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
     tDefineStruct = 336,
     tNameStruct = 337,
     tDefineString = 338,
     tSetNumber = 339,
     tSetString = 340,
     tPoint = 341,
     tCircle = 342,
     tEllipse = 343,
     tLine = 344,
     tSphere = 345,
     tPolarSphere = 346,
     tSurface = 347,
     tSpline = 348,
     tVolume = 349,
     tBlock = 350,
     tCylinder = 351,
     tCone = 352,
     tTorus = 353,
     tEllipsoid = 354,
     tQuadric = 355,
     tShapeFromFile = 356,
     tRectangle = 357,
     tDisk = 358,
     tWire = 359,
     tCharacteristic = 360,
     tLength = 361,
     tParametric = 362,
     tElliptic = 363,
     tRefineMesh = 364,
     tAdaptMesh = 365,
     tRelocateMesh = 366,
     tSetFactory = 367,
     tThruSections = 368,
     tWedge = 369,
     tFillet = 370,
     tChamfer = 371,
     tPlane = 372,
     tRuled = 373,
     tTransfinite = 374,
     tComplex = 375,
     tPhysical = 376,
     tCompound = 377,
     tPeriodic = 378,
     tUsing = 379,
     tPlugin = 380,
     tDegenerated = 381,
     tRecursive = 382,
     tRotate = 383,
     tTranslate = 384,
     tSymmetry = 385,
     tDilate = 386,
     tExtrude = 387,
     tLevelset = 388,
     tAffine = 389,
     tBooleanUnion = 390,
     tBooleanIntersection = 391,
     tBooleanDifference = 392,
     tBooleanSection = 393,
     tBooleanFragments = 394,
     tThickSolid = 395,
     tRecombine = 396,
     tSmoother = 397,
     tSplit = 398,
     tDelete = 399,
     tCoherence = 400,
     tIntersect = 401,
     tMeshAlgorithm = 402,
     tReverse = 403,
     tLayers = 404,
     tScaleLast = 405,
     tHole = 406,
     tAlias = 407,
     tAliasWithOptions = 408,
     tCopyOptions = 409,
     tQuadTriAddVerts = 410,
     tQuadTriNoNewVerts = 411,
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
#define tDefineStruct 336
#define tNameStruct 337
#define tDefineString 338
#define tSetNumber 339
#define tSetString 340
#define tPoint 341
#define tCircle 342
#define tEllipse 343
#define tLine 344
#define tSphere 345
#define tPolarSphere 346
#define tSurface 347
#define tSpline 348
#define tVolume 349
#define tBlock 350
#define tCylinder 351
#define tCone 352
#define tTorus 353
#define tEllipsoid 354
#define tQuadric 355
#define tShapeFromFile 356
#define tRectangle 357
#define tDisk 358
#define tWire 359
#define tCharacteristic 360
#define tLength 361
#define tParametric 362
#define tElliptic 363
#define tRefineMesh 364
#define tAdaptMesh 365
#define tRelocateMesh 366
#define tSetFactory 367
#define tThruSections 368
#define tWedge 369
#define tFillet 370
#define tChamfer 371
#define tPlane 372
#define tRuled 373
#define tTransfinite 374
#define tComplex 375
#define tPhysical 376
#define tCompound 377
#define tPeriodic 378
#define tUsing 379
#define tPlugin 380
#define tDegenerated 381
#define tRecursive 382
#define tRotate 383
#define tTranslate 384
#define tSymmetry 385
#define tDilate 386
#define tExtrude 387
#define tLevelset 388
#define tAffine 389
#define tBooleanUnion 390
#define tBooleanIntersection 391
#define tBooleanDifference 392
#define tBooleanSection 393
#define tBooleanFragments 394
#define tThickSolid 395
#define tRecombine 396
#define tSmoother 397
#define tSplit 398
#define tDelete 399
#define tCoherence 400
#define tIntersect 401
#define tMeshAlgorithm 402
#define tReverse 403
#define tLayers 404
#define tScaleLast 405
#define tHole 406
#define tAlias 407
#define tAliasWithOptions 408
#define tCopyOptions 409
#define tQuadTriAddVerts 410
#define tQuadTriNoNewVerts 411
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
static std::map<std::string, Struct> StructTable_M;
static char *Struct_Name = 0, *Struct_NameSpace = 0;
static int flag_tSTRING_alloc = 0;

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
void ListOfShapes2Vectors(List_T *list, std::vector<int> v[4]);
void Vectors2ListOfShapes(std::vector<int> tags[4], List_T *list);

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
#line 126 "Gmsh.y"
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
#line 673 "Gmsh.tab.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 686 "Gmsh.tab.cpp"

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
#define YYLAST   15195

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  238
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  111
/* YYNRULES -- Number of rules.  */
#define YYNRULES  607
/* YYNRULES -- Number of states.  */
#define YYNSTATES  2284

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
     268,   270,   272,   274,   276,   282,   288,   291,   299,   307,
     312,   316,   323,   330,   338,   346,   353,   360,   370,   380,
     387,   394,   402,   410,   417,   424,   429,   438,   447,   457,
     467,   477,   487,   496,   505,   515,   525,   535,   545,   552,
     562,   569,   579,   585,   594,   603,   615,   622,   632,   638,
     646,   656,   666,   678,   686,   696,   706,   707,   709,   710,
     714,   720,   721,   731,   732,   744,   745,   757,   763,   764,
     774,   775,   779,   783,   789,   795,   796,   799,   803,   809,
     813,   814,   817,   821,   825,   829,   835,   837,   839,   843,
     845,   847,   851,   853,   855,   859,   861,   863,   867,   868,
     874,   875,   878,   886,   894,   902,   911,   920,   928,   936,
     948,   957,   965,   974,   983,   992,  1002,  1006,  1011,  1022,
    1030,  1038,  1046,  1054,  1062,  1070,  1078,  1086,  1094,  1102,
    1111,  1124,  1133,  1141,  1150,  1158,  1167,  1176,  1185,  1194,
    1203,  1212,  1218,  1230,  1236,  1246,  1256,  1261,  1271,  1281,
    1283,  1285,  1286,  1289,  1296,  1303,  1310,  1317,  1326,  1337,
    1352,  1369,  1382,  1397,  1412,  1427,  1442,  1451,  1460,  1467,
    1472,  1479,  1486,  1490,  1495,  1501,  1508,  1514,  1518,  1522,
    1527,  1533,  1538,  1544,  1548,  1554,  1562,  1570,  1574,  1582,
    1586,  1589,  1592,  1595,  1598,  1601,  1617,  1620,  1623,  1626,
    1629,  1632,  1649,  1661,  1668,  1677,  1686,  1697,  1699,  1702,
    1705,  1707,  1711,  1715,  1720,  1725,  1727,  1729,  1735,  1747,
    1761,  1762,  1770,  1771,  1785,  1786,  1802,  1803,  1810,  1820,
    1823,  1827,  1838,  1847,  1856,  1865,  1878,  1891,  1904,  1919,
    1934,  1949,  1950,  1963,  1964,  1977,  1978,  1991,  1992,  2009,
    2010,  2027,  2028,  2045,  2046,  2065,  2066,  2085,  2086,  2105,
    2107,  2110,  2116,  2124,  2134,  2137,  2140,  2144,  2147,  2151,
    2154,  2158,  2168,  2175,  2177,  2179,  2181,  2183,  2185,  2186,
    2189,  2193,  2203,  2208,  2223,  2224,  2228,  2229,  2231,  2232,
    2235,  2236,  2239,  2240,  2243,  2250,  2258,  2265,  2274,  2280,
    2284,  2293,  2299,  2304,  2311,  2323,  2335,  2354,  2373,  2386,
    2399,  2412,  2423,  2434,  2445,  2456,  2467,  2472,  2477,  2482,
    2487,  2492,  2497,  2502,  2507,  2512,  2515,  2519,  2526,  2528,
    2530,  2532,  2535,  2541,  2549,  2560,  2562,  2566,  2569,  2572,
    2575,  2579,  2583,  2587,  2591,  2595,  2599,  2603,  2607,  2611,
    2615,  2619,  2623,  2627,  2631,  2637,  2642,  2647,  2652,  2657,
    2662,  2667,  2672,  2677,  2682,  2687,  2694,  2699,  2704,  2709,
    2714,  2719,  2724,  2729,  2736,  2743,  2750,  2755,  2757,  2759,
    2761,  2763,  2765,  2767,  2769,  2771,  2773,  2775,  2777,  2778,
    2785,  2787,  2792,  2799,  2801,  2806,  2811,  2816,  2821,  2826,
    2831,  2836,  2839,  2845,  2851,  2857,  2863,  2867,  2874,  2879,
    2887,  2894,  2901,  2908,  2913,  2920,  2925,  2926,  2935,  2937,
    2942,  2944,  2945,  2949,  2951,  2954,  2957,  2961,  2965,  2977,
    2987,  2995,  3003,  3005,  3009,  3011,  3013,  3016,  3020,  3025,
    3031,  3033,  3035,  3038,  3042,  3046,  3052,  3057,  3060,  3063,
    3066,  3069,  3073,  3077,  3081,  3085,  3091,  3097,  3103,  3109,
    3126,  3143,  3160,  3177,  3179,  3181,  3183,  3187,  3191,  3196,
    3201,  3206,  3213,  3220,  3227,  3234,  3243,  3252,  3257,  3272,
    3277,  3279,  3281,  3285,  3289,  3299,  3307,  3309,  3315,  3319,
    3326,  3328,  3332,  3334,  3336,  3341,  3346,  3351,  3356,  3360,
    3367,  3369,  3374,  3376,  3378,  3380,  3385,  3392,  3397,  3404,
    3409,  3414,  3419,  3428,  3433,  3438,  3443,  3448,  3457,  3466,
    3473,  3478,  3485,  3490,  3492,  3497,  3502,  3503,  3510,  3515,
    3518,  3524,  3526,  3530,  3536,  3542,  3544,  3546
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     239,     0,    -1,   240,    -1,     1,     6,    -1,    -1,   240,
     241,    -1,   243,    -1,   244,    -1,   264,    -1,   112,   228,
     342,   229,     6,    -1,   283,    -1,   284,    -1,   288,    -1,
     289,    -1,   290,    -1,   291,    -1,   295,    -1,   313,    -1,
     314,    -1,   320,    -1,   321,    -1,   294,    -1,   293,    -1,
     292,    -1,   287,    -1,   323,    -1,   215,    -1,   215,   215,
      -1,    42,   228,   342,   229,     6,    -1,    43,   228,   342,
     229,     6,    -1,    42,   228,   342,   229,   242,   342,     6,
      -1,    42,   228,   342,   234,   338,   229,     6,    -1,    43,
     228,   342,   234,   338,   229,     6,    -1,    42,   228,   342,
     234,   338,   229,   242,   342,     6,    -1,     4,   342,   235,
     245,   236,     6,    -1,   152,     4,   230,   324,   231,     6,
      -1,   153,     4,   230,   324,   231,     6,    -1,   154,     4,
     230,   324,   234,   324,   231,     6,    -1,    -1,   245,   248,
      -1,   245,   252,    -1,   245,   255,    -1,   245,   257,    -1,
     245,   258,    -1,   324,    -1,   246,   234,   324,    -1,   324,
      -1,   247,   234,   324,    -1,    -1,    -1,     4,   249,   228,
     246,   229,   250,   235,   247,   236,     6,    -1,   342,    -1,
     251,   234,   342,    -1,    -1,   159,   228,   324,   234,   324,
     234,   324,   229,   253,   235,   251,   236,     6,    -1,   342,
      -1,   254,   234,   342,    -1,    -1,   160,   228,   324,   234,
     324,   234,   324,   234,   324,   229,   256,   235,   254,   236,
       6,    -1,   161,   235,   334,   236,   235,   334,   236,     6,
      -1,   161,   235,   334,   236,   235,   334,   236,   235,   334,
     236,   235,   334,   236,     6,    -1,    -1,   162,   259,   235,
     247,   236,     6,    -1,     7,    -1,   208,    -1,   207,    -1,
     206,    -1,   205,    -1,   226,    -1,   225,    -1,   228,    -1,
     230,    -1,   229,    -1,   231,    -1,    78,   230,   266,   231,
       6,    -1,    79,   230,   271,   231,     6,    -1,   327,     6,
      -1,    84,   262,   343,   234,   324,   263,     6,    -1,    85,
     262,   348,   234,   343,   263,     6,    -1,   348,   260,   335,
       6,    -1,   348,   261,     6,    -1,     4,   230,   231,   260,
     335,     6,    -1,   347,   230,   231,   260,   335,     6,    -1,
       4,   230,   324,   231,   260,   324,     6,    -1,   347,   230,
     324,   231,   260,   324,     6,    -1,     4,   230,   324,   231,
     261,     6,    -1,   347,   230,   324,   231,   261,     6,    -1,
       4,   262,   235,   338,   236,   263,   260,   335,     6,    -1,
     347,   262,   235,   338,   236,   263,   260,   335,     6,    -1,
       4,   228,   229,   260,   335,     6,    -1,   347,   228,   229,
     260,   335,     6,    -1,     4,   228,   324,   229,   260,   324,
       6,    -1,   347,   228,   324,   229,   260,   324,     6,    -1,
       4,   228,   324,   229,   261,     6,    -1,   347,   228,   324,
     229,   261,     6,    -1,   348,     7,   343,     6,    -1,     4,
     230,   231,     7,    44,   262,   263,     6,    -1,   347,   230,
     231,     7,    44,   262,   263,     6,    -1,     4,   230,   231,
       7,    44,   262,   346,   263,     6,    -1,   347,   230,   231,
       7,    44,   262,   346,   263,     6,    -1,     4,   230,   231,
     208,    44,   262,   346,   263,     6,    -1,   347,   230,   231,
     208,    44,   262,   346,   263,     6,    -1,     4,   228,   229,
       7,    44,   262,   263,     6,    -1,   347,   228,   229,     7,
      44,   262,   263,     6,    -1,     4,   228,   229,     7,    44,
     262,   346,   263,     6,    -1,   347,   228,   229,     7,    44,
     262,   346,   263,     6,    -1,     4,   228,   229,   208,    44,
     262,   346,   263,     6,    -1,   347,   228,   229,   208,    44,
     262,   346,   263,     6,    -1,     4,   232,     4,     7,   343,
       6,    -1,     4,   230,   324,   231,   232,     4,     7,   343,
       6,    -1,     4,   232,     4,   260,   324,     6,    -1,     4,
     230,   324,   231,   232,     4,   260,   324,     6,    -1,     4,
     232,     4,   261,     6,    -1,     4,   230,   324,   231,   232,
       4,   261,     6,    -1,     4,   232,   169,   232,     4,     7,
     339,     6,    -1,     4,   230,   324,   231,   232,   169,   232,
       4,     7,   339,     6,    -1,     4,   232,   170,     7,   340,
       6,    -1,     4,   230,   324,   231,   232,   170,     7,   340,
       6,    -1,     4,   180,     7,   324,     6,    -1,   180,   230,
     324,   231,     7,     4,     6,    -1,   180,   230,   324,   231,
     232,     4,     7,   324,     6,    -1,   180,   230,   324,   231,
     232,     4,     7,   343,     6,    -1,   180,   230,   324,   231,
     232,     4,     7,   235,   338,   236,     6,    -1,   180,   230,
     324,   231,   232,     4,     6,    -1,   125,   228,     4,   229,
     232,     4,     7,   324,     6,    -1,   125,   228,     4,   229,
     232,     4,     7,   343,     6,    -1,    -1,   234,    -1,    -1,
     266,   265,   348,    -1,   266,   265,   348,     7,   324,    -1,
      -1,   266,   265,   348,     7,   235,   335,   267,   273,   236,
      -1,    -1,   266,   265,   348,   230,   231,     7,   235,   335,
     268,   273,   236,    -1,    -1,   266,   265,   348,   228,   229,
       7,   235,   335,   269,   273,   236,    -1,   266,   265,   348,
       7,   343,    -1,    -1,   266,   265,   348,     7,   235,   343,
     270,   275,   236,    -1,    -1,   271,   265,   342,    -1,   324,
       7,   343,    -1,   272,   234,   324,     7,   343,    -1,   337,
       7,   348,   228,   229,    -1,    -1,   273,   274,    -1,   234,
       4,   335,    -1,   234,     4,   235,   272,   236,    -1,   234,
       4,   343,    -1,    -1,   275,   276,    -1,   234,     4,   324,
      -1,   234,     4,   343,    -1,   234,   184,   343,    -1,   234,
       4,   235,   346,   236,    -1,   324,    -1,   343,    -1,   343,
     234,   324,    -1,   324,    -1,   343,    -1,   343,   234,   324,
      -1,   324,    -1,   343,    -1,   343,   234,   324,    -1,   324,
      -1,   343,    -1,   343,   234,   324,    -1,    -1,   172,    90,
     235,   324,   236,    -1,    -1,   117,   332,    -1,    86,   228,
     324,   229,     7,   332,     6,    -1,    89,   228,   324,   229,
       7,   335,     6,    -1,    93,   228,   324,   229,     7,   335,
       6,    -1,    87,   228,   324,   229,     7,   335,   282,     6,
      -1,    88,   228,   324,   229,     7,   335,   282,     6,    -1,
     164,   228,   324,   229,     7,   335,     6,    -1,   165,   228,
     324,   229,     7,   335,     6,    -1,   166,   228,   324,   229,
       7,   335,   168,   335,   167,   324,     6,    -1,   122,    89,
     228,   324,   229,     7,   335,     6,    -1,   104,   228,   324,
     229,     7,   335,     6,    -1,    89,     4,   228,   324,   229,
       7,   335,     6,    -1,   117,    92,   228,   324,   229,     7,
     335,     6,    -1,    92,   228,   324,   229,     7,   335,   281,
       6,    -1,   118,    92,   228,   324,   229,     7,   335,   281,
       6,    -1,    12,    13,     6,    -1,    13,    92,   324,     6,
      -1,   107,    92,   228,   324,   229,     7,     5,     5,     5,
       6,    -1,    90,   228,   324,   229,     7,   335,     6,    -1,
      91,   228,   324,   229,     7,   335,     6,    -1,    95,   228,
     324,   229,     7,   335,     6,    -1,    98,   228,   324,   229,
       7,   335,     6,    -1,   102,   228,   324,   229,     7,   335,
       6,    -1,   103,   228,   324,   229,     7,   335,     6,    -1,
      96,   228,   324,   229,     7,   335,     6,    -1,    97,   228,
     324,   229,     7,   335,     6,    -1,   114,   228,   324,   229,
       7,   335,     6,    -1,   140,   228,   324,   229,     7,   335,
       6,    -1,   122,    92,   228,   324,   229,     7,   335,     6,
      -1,   122,    92,   228,   324,   229,     7,   335,     4,   235,
     334,   236,     6,    -1,    92,     4,   228,   324,   229,     7,
     335,     6,    -1,    94,   228,   324,   229,     7,   335,     6,
      -1,   120,    94,   228,   324,   229,     7,   335,     6,    -1,
     113,   228,   324,   229,     7,   335,     6,    -1,   118,   113,
     228,   324,   229,     7,   335,     6,    -1,   122,    94,   228,
     324,   229,     7,   335,     6,    -1,   121,    86,   228,   277,
     229,   260,   335,     6,    -1,   121,    89,   228,   278,   229,
     260,   335,     6,    -1,   121,    92,   228,   279,   229,   260,
     335,     6,    -1,   121,    94,   228,   280,   229,   260,   335,
       6,    -1,   129,   332,   235,   285,   236,    -1,   128,   235,
     332,   234,   332,   234,   324,   236,   235,   285,   236,    -1,
     130,   332,   235,   285,   236,    -1,   131,   235,   332,   234,
     324,   236,   235,   285,   236,    -1,   131,   235,   332,   234,
     332,   236,   235,   285,   236,    -1,     4,   235,   285,   236,
      -1,   146,    89,   235,   338,   236,    92,   235,   324,   236,
      -1,   143,    89,   228,   324,   229,   235,   338,   236,     6,
      -1,   286,    -1,   284,    -1,    -1,   286,   283,    -1,   286,
      86,   235,   338,   236,     6,    -1,   286,    89,   235,   338,
     236,     6,    -1,   286,    92,   235,   338,   236,     6,    -1,
     286,    94,   235,   338,   236,     6,    -1,   133,   117,   228,
     324,   229,     7,   335,     6,    -1,   133,    86,   228,   324,
     229,     7,   235,   334,   236,     6,    -1,   133,   117,   228,
     324,   229,     7,   235,   332,   234,   332,   234,   338,   236,
       6,    -1,   133,   117,   228,   324,   229,     7,   235,   332,
     234,   332,   234,   332,   234,   338,   236,     6,    -1,   133,
      90,   228,   324,   229,     7,   235,   332,   234,   338,   236,
       6,    -1,   133,    96,   228,   324,   229,     7,   235,   332,
     234,   332,   234,   338,   236,     6,    -1,   133,    97,   228,
     324,   229,     7,   235,   332,   234,   332,   234,   338,   236,
       6,    -1,   133,    99,   228,   324,   229,     7,   235,   332,
     234,   332,   234,   338,   236,     6,    -1,   133,   100,   228,
     324,   229,     7,   235,   332,   234,   332,   234,   338,   236,
       6,    -1,   133,     4,   228,   324,   229,     7,   335,     6,
      -1,   133,     4,   228,   324,   229,     7,     5,     6,    -1,
     133,     4,   235,   324,   236,     6,    -1,   144,   235,   286,
     236,    -1,   144,   180,   230,   324,   231,     6,    -1,   144,
       4,   230,   324,   231,     6,    -1,   144,   348,     6,    -1,
     144,     4,     4,     6,    -1,   169,   339,   235,   286,   236,
      -1,   127,   169,   339,   235,   286,   236,    -1,   202,   324,
     235,   286,   236,    -1,   185,     5,     6,    -1,   186,     5,
       6,    -1,   185,   235,   286,   236,    -1,   127,   185,   235,
     286,   236,    -1,   186,   235,   286,   236,    -1,   127,   186,
     235,   286,   236,    -1,     4,   343,     6,    -1,    71,   228,
     346,   229,     6,    -1,     4,     4,   230,   324,   231,   342,
       6,    -1,     4,     4,     4,   230,   324,   231,     6,    -1,
       4,   324,     6,    -1,   125,   228,     4,   229,   232,     4,
       6,    -1,   163,     4,     6,    -1,   178,     6,    -1,   179,
       6,    -1,    68,     6,    -1,    69,     6,    -1,    62,     6,
      -1,    62,   235,   324,   234,   324,   234,   324,   234,   324,
     234,   324,   234,   324,   236,     6,    -1,    63,     6,    -1,
      64,     6,    -1,    75,     6,    -1,    76,     6,    -1,   109,
       6,    -1,   110,   235,   338,   236,   235,   338,   236,   235,
     334,   236,   235,   324,   234,   324,   236,     6,    -1,   183,
     228,   235,   338,   236,   234,   343,   234,   343,   229,     6,
      -1,   171,   228,   324,     8,   324,   229,    -1,   171,   228,
     324,     8,   324,     8,   324,   229,    -1,   171,     4,   172,
     235,   324,     8,   324,   236,    -1,   171,     4,   172,   235,
     324,     8,   324,     8,   324,   236,    -1,   173,    -1,   184,
       4,    -1,   184,   343,    -1,   181,    -1,   182,   348,     6,
      -1,   182,   343,     6,    -1,   174,   228,   324,   229,    -1,
     175,   228,   324,   229,    -1,   176,    -1,   177,    -1,   132,
     332,   235,   286,   236,    -1,   132,   235,   332,   234,   332,
     234,   324,   236,   235,   286,   236,    -1,   132,   235,   332,
     234,   332,   234,   332,   234,   324,   236,   235,   286,   236,
      -1,    -1,   132,   332,   235,   286,   296,   309,   236,    -1,
      -1,   132,   235,   332,   234,   332,   234,   324,   236,   235,
     286,   297,   309,   236,    -1,    -1,   132,   235,   332,   234,
     332,   234,   332,   234,   324,   236,   235,   286,   298,   309,
     236,    -1,    -1,   132,   235,   286,   299,   309,   236,    -1,
     132,   235,   286,   236,   124,   104,   235,   324,   236,    -1,
     113,   335,    -1,   118,   113,   335,    -1,   115,   235,   338,
     236,   235,   338,   236,   235,   324,   236,    -1,   132,    86,
     235,   324,   234,   332,   236,     6,    -1,   132,    89,   235,
     324,   234,   332,   236,     6,    -1,   132,    92,   235,   324,
     234,   332,   236,     6,    -1,   132,    86,   235,   324,   234,
     332,   234,   332,   234,   324,   236,     6,    -1,   132,    89,
     235,   324,   234,   332,   234,   332,   234,   324,   236,     6,
      -1,   132,    92,   235,   324,   234,   332,   234,   332,   234,
     324,   236,     6,    -1,   132,    86,   235,   324,   234,   332,
     234,   332,   234,   332,   234,   324,   236,     6,    -1,   132,
      89,   235,   324,   234,   332,   234,   332,   234,   332,   234,
     324,   236,     6,    -1,   132,    92,   235,   324,   234,   332,
     234,   332,   234,   332,   234,   324,   236,     6,    -1,    -1,
     132,    86,   235,   324,   234,   332,   236,   300,   235,   309,
     236,     6,    -1,    -1,   132,    89,   235,   324,   234,   332,
     236,   301,   235,   309,   236,     6,    -1,    -1,   132,    92,
     235,   324,   234,   332,   236,   302,   235,   309,   236,     6,
      -1,    -1,   132,    86,   235,   324,   234,   332,   234,   332,
     234,   324,   236,   303,   235,   309,   236,     6,    -1,    -1,
     132,    89,   235,   324,   234,   332,   234,   332,   234,   324,
     236,   304,   235,   309,   236,     6,    -1,    -1,   132,    92,
     235,   324,   234,   332,   234,   332,   234,   324,   236,   305,
     235,   309,   236,     6,    -1,    -1,   132,    86,   235,   324,
     234,   332,   234,   332,   234,   332,   234,   324,   236,   306,
     235,   309,   236,     6,    -1,    -1,   132,    89,   235,   324,
     234,   332,   234,   332,   234,   332,   234,   324,   236,   307,
     235,   309,   236,     6,    -1,    -1,   132,    92,   235,   324,
     234,   332,   234,   332,   234,   332,   234,   324,   236,   308,
     235,   309,   236,     6,    -1,   310,    -1,   309,   310,    -1,
     149,   235,   324,   236,     6,    -1,   149,   235,   335,   234,
     335,   236,     6,    -1,   149,   235,   335,   234,   335,   234,
     335,   236,     6,    -1,   150,     6,    -1,   141,     6,    -1,
     141,   324,     6,    -1,   155,     6,    -1,   155,   157,     6,
      -1,   156,     6,    -1,   156,   157,     6,    -1,   151,   228,
     324,   229,     7,   335,   124,   324,     6,    -1,   124,     4,
     230,   324,   231,     6,    -1,   135,    -1,   136,    -1,   137,
      -1,   138,    -1,   139,    -1,    -1,   144,     6,    -1,   144,
     324,     6,    -1,   311,   235,   286,   312,   236,   235,   286,
     312,   236,    -1,   101,   228,   342,   229,    -1,   311,   228,
     324,   229,     7,   235,   286,   312,   236,   235,   286,   312,
     236,     6,    -1,    -1,   124,     4,   324,    -1,    -1,     4,
      -1,    -1,     7,   335,    -1,    -1,     7,   324,    -1,    -1,
     134,   335,    -1,   105,   106,   335,     7,   324,     6,    -1,
     119,    89,   336,     7,   324,   315,     6,    -1,   119,    92,
     336,   317,   316,     6,    -1,   108,    92,   235,   324,   236,
       7,   335,     6,    -1,   119,    94,   336,   317,     6,    -1,
     158,   336,     6,    -1,   147,    92,   235,   338,   236,     7,
     324,     6,    -1,   141,    92,   336,   318,     6,    -1,   141,
      94,   336,     6,    -1,   142,    92,   336,     7,   324,     6,
      -1,   123,    89,   235,   338,   236,     7,   235,   338,   236,
     319,     6,    -1,   123,    92,   235,   338,   236,     7,   235,
     338,   236,   319,     6,    -1,   123,    89,   235,   338,   236,
       7,   235,   338,   236,   128,   235,   332,   234,   332,   234,
     324,   236,     6,    -1,   123,    92,   235,   338,   236,     7,
     235,   338,   236,   128,   235,   332,   234,   332,   234,   324,
     236,     6,    -1,   123,    89,   235,   338,   236,     7,   235,
     338,   236,   129,   332,     6,    -1,   123,    92,   235,   338,
     236,     7,   235,   338,   236,   129,   332,     6,    -1,   123,
      92,   324,   235,   338,   236,     7,   324,   235,   338,   236,
       6,    -1,    86,   235,   338,   236,   172,    92,   235,   324,
     236,     6,    -1,    89,   235,   338,   236,   172,    92,   235,
     324,   236,     6,    -1,    86,   235,   338,   236,   172,    94,
     235,   324,   236,     6,    -1,    89,   235,   338,   236,   172,
      94,   235,   324,   236,     6,    -1,    92,   235,   338,   236,
     172,    94,   235,   324,   236,     6,    -1,   148,    92,   336,
       6,    -1,   148,    89,   336,     6,    -1,   111,    86,   336,
       6,    -1,   111,    89,   336,     6,    -1,   111,    92,   336,
       6,    -1,   126,    89,   335,     6,    -1,   122,    89,   335,
       6,    -1,   122,    92,   335,     6,    -1,   122,    94,   335,
       6,    -1,   145,     6,    -1,   145,     4,     6,    -1,   145,
      86,   235,   338,   236,     6,    -1,   193,    -1,   194,    -1,
     195,    -1,   322,     6,    -1,   322,   235,   335,   236,     6,
      -1,   322,   235,   335,   234,   335,   236,     6,    -1,   322,
     228,   335,   229,   235,   335,   234,   335,   236,     6,    -1,
     325,    -1,   228,   324,   229,    -1,   219,   324,    -1,   218,
     324,    -1,   223,   324,    -1,   324,   219,   324,    -1,   324,
     218,   324,    -1,   324,   220,   324,    -1,   324,   221,   324,
      -1,   324,   222,   324,    -1,   324,   227,   324,    -1,   324,
     214,   324,    -1,   324,   215,   324,    -1,   324,   217,   324,
      -1,   324,   216,   324,    -1,   324,   213,   324,    -1,   324,
     212,   324,    -1,   324,   211,   324,    -1,   324,   210,   324,
      -1,   324,   209,   324,     8,   324,    -1,    15,   262,   324,
     263,    -1,    16,   262,   324,   263,    -1,    17,   262,   324,
     263,    -1,    18,   262,   324,   263,    -1,    19,   262,   324,
     263,    -1,    20,   262,   324,   263,    -1,    21,   262,   324,
     263,    -1,    22,   262,   324,   263,    -1,    23,   262,   324,
     263,    -1,    25,   262,   324,   263,    -1,    26,   262,   324,
     234,   324,   263,    -1,    27,   262,   324,   263,    -1,    28,
     262,   324,   263,    -1,    29,   262,   324,   263,    -1,    30,
     262,   324,   263,    -1,    31,   262,   324,   263,    -1,    32,
     262,   324,   263,    -1,    33,   262,   324,   263,    -1,    34,
     262,   324,   234,   324,   263,    -1,    35,   262,   324,   234,
     324,   263,    -1,    36,   262,   324,   234,   324,   263,    -1,
      24,   262,   324,   263,    -1,     3,    -1,     9,    -1,    14,
      -1,    10,    -1,    11,    -1,   198,    -1,   199,    -1,   200,
      -1,    72,    -1,    73,    -1,    74,    -1,    -1,    80,   262,
     324,   326,   273,   263,    -1,   327,    -1,   191,   262,   342,
     263,    -1,   191,   262,   342,   234,   324,   263,    -1,   348,
      -1,     4,   230,   324,   231,    -1,     4,   228,   324,   229,
      -1,   347,   230,   324,   231,    -1,   347,   228,   324,   229,
      -1,   196,   228,   348,   229,    -1,   197,   228,   343,   229,
      -1,   233,   348,   262,   263,    -1,   348,   261,    -1,     4,
     230,   324,   231,   261,    -1,     4,   228,   324,   229,   261,
      -1,   347,   230,   324,   231,   261,    -1,   347,   228,   324,
     229,   261,    -1,   348,   232,   330,    -1,     4,   230,   324,
     231,   232,     4,    -1,   348,   232,   330,   261,    -1,     4,
     230,   324,   231,   232,     4,   261,    -1,   187,   228,   342,
     234,   324,   229,    -1,    54,   228,   335,   234,   335,   229,
      -1,    55,   262,   342,   234,   342,   263,    -1,    53,   262,
     342,   263,    -1,    56,   262,   342,   234,   342,   263,    -1,
      61,   228,   346,   229,    -1,    -1,    81,   329,   328,   331,
     230,   324,   273,   231,    -1,   348,    -1,   348,     8,     8,
     348,    -1,     4,    -1,    -1,   235,   348,   236,    -1,   333,
      -1,   219,   332,    -1,   218,   332,    -1,   332,   219,   332,
      -1,   332,   218,   332,    -1,   235,   324,   234,   324,   234,
     324,   234,   324,   234,   324,   236,    -1,   235,   324,   234,
     324,   234,   324,   234,   324,   236,    -1,   235,   324,   234,
     324,   234,   324,   236,    -1,   228,   324,   234,   324,   234,
     324,   229,    -1,   335,    -1,   334,   234,   335,    -1,   324,
      -1,   337,    -1,   235,   236,    -1,   235,   338,   236,    -1,
     219,   235,   338,   236,    -1,   324,   220,   235,   338,   236,
      -1,   335,    -1,     5,    -1,   219,   337,    -1,   324,   220,
     337,    -1,   324,     8,   324,    -1,   324,     8,   324,     8,
     324,    -1,    86,   235,   324,   236,    -1,    86,     5,    -1,
      89,     5,    -1,    92,     5,    -1,    94,     5,    -1,   121,
      86,     5,    -1,   121,    89,     5,    -1,   121,    92,     5,
      -1,   121,    94,     5,    -1,   121,    86,   235,   338,   236,
      -1,   121,    89,   235,   338,   236,    -1,   121,    92,   235,
     338,   236,    -1,   121,    94,   235,   338,   236,    -1,    86,
     172,    62,   235,   324,   234,   324,   234,   324,   234,   324,
     234,   324,   234,   324,   236,    -1,    89,   172,    62,   235,
     324,   234,   324,   234,   324,   234,   324,   234,   324,   234,
     324,   236,    -1,    92,   172,    62,   235,   324,   234,   324,
     234,   324,   234,   324,   234,   324,   234,   324,   236,    -1,
      94,   172,    62,   235,   324,   234,   324,   234,   324,   234,
     324,   234,   324,   234,   324,   236,    -1,   284,    -1,   295,
      -1,   313,    -1,     4,   262,   263,    -1,   347,   262,   263,
      -1,    37,   230,   348,   231,    -1,    37,   230,   337,   231,
      -1,    37,   228,   337,   229,    -1,    37,   230,   235,   338,
     236,   231,    -1,    37,   228,   235,   338,   236,   229,    -1,
       4,   262,   235,   338,   236,   263,    -1,   347,   262,   235,
     338,   236,   263,    -1,    38,   262,   324,   234,   324,   234,
     324,   263,    -1,    39,   262,   324,   234,   324,   234,   324,
     263,    -1,    40,   262,   342,   263,    -1,    41,   262,   324,
     234,   324,   234,   324,   234,   324,   234,   324,   234,   324,
     263,    -1,   192,   262,   337,   263,    -1,   324,    -1,   337,
      -1,   338,   234,   324,    -1,   338,   234,   337,    -1,   235,
     324,   234,   324,   234,   324,   234,   324,   236,    -1,   235,
     324,   234,   324,   234,   324,   236,    -1,   348,    -1,     4,
     232,   169,   232,     4,    -1,   235,   341,   236,    -1,     4,
     230,   324,   231,   232,   170,    -1,   339,    -1,   341,   234,
     339,    -1,   343,    -1,   348,    -1,     4,   230,   324,   231,
      -1,   347,   230,   324,   231,    -1,     4,   228,   324,   229,
      -1,   347,   228,   324,   229,    -1,   348,   232,   330,    -1,
       4,   230,   324,   231,   232,     4,    -1,     5,    -1,   203,
     230,   348,   231,    -1,    65,    -1,   201,    -1,    70,    -1,
     189,   228,   342,   229,    -1,   188,   228,   342,   234,   342,
     229,    -1,   190,   262,   342,   263,    -1,   190,   262,   342,
     234,   342,   263,    -1,    46,   262,   346,   263,    -1,    47,
     228,   342,   229,    -1,    48,   228,   342,   229,    -1,    49,
     228,   342,   234,   342,   234,   342,   229,    -1,    44,   262,
     346,   263,    -1,    58,   262,   342,   263,    -1,    59,   262,
     342,   263,    -1,    60,   262,   342,   263,    -1,    57,   262,
     324,   234,   342,   234,   342,   263,    -1,    52,   262,   342,
     234,   324,   234,   324,   263,    -1,    52,   262,   342,   234,
     324,   263,    -1,    45,   262,   342,   263,    -1,    45,   262,
     342,   234,   338,   263,    -1,    66,   262,   342,   263,    -1,
      67,    -1,    51,   262,   342,   263,    -1,    50,   262,   342,
     263,    -1,    -1,    83,   262,   343,   344,   275,   263,    -1,
      82,   262,   345,   263,    -1,   233,   324,    -1,   348,     8,
       8,   233,   324,    -1,   342,    -1,   346,   234,   342,    -1,
       4,   237,   235,   324,   236,    -1,   347,   237,   235,   324,
     236,    -1,     4,    -1,   347,    -1,   204,   230,   342,   231,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   220,   220,   221,   226,   228,   232,   233,   234,   235,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   263,   267,   274,   279,
     284,   298,   311,   324,   352,   366,   379,   392,   411,   416,
     417,   418,   419,   420,   424,   426,   431,   433,   439,   543,
     438,   561,   568,   579,   578,   596,   603,   614,   613,   630,
     647,   670,   669,   683,   684,   685,   686,   687,   691,   692,
     698,   698,   699,   699,   705,   706,   707,   708,   713,   719,
     781,   798,   827,   856,   861,   866,   871,   876,   883,   893,
     922,   951,   956,   961,   966,   974,   983,   989,   995,  1008,
    1021,  1036,  1053,  1059,  1065,  1078,  1091,  1106,  1123,  1130,
    1139,  1158,  1177,  1187,  1199,  1205,  1213,  1234,  1257,  1268,
    1276,  1298,  1321,  1359,  1380,  1392,  1406,  1406,  1408,  1410,
    1419,  1429,  1428,  1449,  1448,  1467,  1466,  1484,  1494,  1493,
    1507,  1509,  1517,  1523,  1528,  1554,  1555,  1559,  1570,  1585,
    1595,  1596,  1601,  1609,  1618,  1626,  1644,  1648,  1654,  1662,
    1666,  1672,  1680,  1684,  1690,  1698,  1702,  1708,  1717,  1720,
    1727,  1730,  1737,  1758,  1772,  1786,  1821,  1859,  1873,  1887,
    1907,  1916,  1930,  1945,  1959,  1978,  1988,  1994,  2000,  2007,
    2034,  2049,  2069,  2090,  2111,  2132,  2154,  2176,  2197,  2220,
    2229,  2250,  2265,  2279,  2294,  2309,  2324,  2333,  2343,  2353,
    2363,  2378,  2389,  2401,  2411,  2421,  2431,  2466,  2477,  2493,
    2494,  2499,  2502,  2506,  2517,  2528,  2539,  2555,  2577,  2603,
    2625,  2648,  2669,  2725,  2749,  2774,  2800,  2913,  2932,  2975,
    2989,  2995,  3010,  3038,  3055,  3064,  3078,  3092,  3098,  3104,
    3113,  3122,  3131,  3145,  3218,  3236,  3253,  3268,  3301,  3313,
    3337,  3341,  3346,  3353,  3358,  3368,  3373,  3379,  3387,  3391,
    3395,  3404,  3468,  3484,  3501,  3518,  3540,  3562,  3597,  3605,
    3613,  3619,  3626,  3633,  3653,  3679,  3691,  3703,  3719,  3735,
    3744,  3743,  3758,  3757,  3772,  3771,  3786,  3785,  3798,  3811,
    3825,  3839,  3856,  3863,  3870,  3877,  3884,  3891,  3898,  3905,
    3912,  3920,  3919,  3933,  3932,  3946,  3945,  3959,  3958,  3972,
    3971,  3985,  3984,  3998,  3997,  4011,  4010,  4024,  4023,  4040,
    4043,  4049,  4061,  4081,  4104,  4108,  4112,  4116,  4120,  4124,
    4128,  4132,  4141,  4154,  4155,  4156,  4157,  4158,  4162,  4163,
    4164,  4167,  4185,  4202,  4219,  4222,  4238,  4241,  4258,  4261,
    4267,  4270,  4277,  4280,  4287,  4304,  4345,  4389,  4394,  4433,
    4458,  4467,  4497,  4523,  4549,  4581,  4608,  4634,  4660,  4686,
    4712,  4734,  4740,  4746,  4752,  4758,  4764,  4790,  4816,  4833,
    4850,  4867,  4879,  4885,  4891,  4903,  4907,  4917,  4928,  4929,
    4930,  4934,  4940,  4952,  4970,  4998,  4999,  5000,  5001,  5002,
    5003,  5004,  5005,  5006,  5013,  5014,  5015,  5016,  5017,  5018,
    5019,  5020,  5021,  5022,  5023,  5024,  5025,  5026,  5027,  5028,
    5029,  5030,  5031,  5032,  5033,  5034,  5035,  5036,  5037,  5038,
    5039,  5040,  5041,  5042,  5043,  5044,  5045,  5054,  5055,  5056,
    5057,  5058,  5059,  5060,  5061,  5062,  5063,  5064,  5069,  5068,
    5076,  5078,  5083,  5088,  5111,  5129,  5147,  5165,  5183,  5188,
    5194,  5209,  5228,  5248,  5268,  5288,  5318,  5336,  5341,  5351,
    5361,  5366,  5377,  5386,  5391,  5396,  5425,  5424,  5437,  5439,
    5444,  5453,  5455,  5464,  5468,  5472,  5476,  5480,  5487,  5491,
    5495,  5499,  5506,  5511,  5518,  5523,  5527,  5532,  5536,  5544,
    5555,  5559,  5571,  5579,  5587,  5594,  5604,  5627,  5631,  5635,
    5639,  5643,  5647,  5651,  5655,  5659,  5688,  5717,  5746,  5775,
    5792,  5809,  5826,  5843,  5853,  5863,  5873,  5885,  5898,  5910,
    5914,  5918,  5922,  5926,  5944,  5962,  5970,  5978,  6007,  6017,
    6036,  6041,  6045,  6049,  6061,  6065,  6077,  6094,  6104,  6108,
    6123,  6128,  6135,  6139,  6152,  6166,  6180,  6194,  6209,  6231,
    6242,  6246,  6250,  6258,  6264,  6270,  6278,  6286,  6293,  6301,
    6316,  6330,  6344,  6356,  6372,  6381,  6390,  6400,  6411,  6419,
    6427,  6431,  6450,  6457,  6463,  6470,  6478,  6477,  6488,  6502,
    6504,  6510,  6515,  6521,  6530,  6543,  6546,  6550
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
  "tUndefineConstant", "tDefineNumber", "tDefineStruct", "tNameStruct",
  "tDefineString", "tSetNumber", "tSetString", "tPoint", "tCircle",
  "tEllipse", "tLine", "tSphere", "tPolarSphere", "tSurface", "tSpline",
  "tVolume", "tBlock", "tCylinder", "tCone", "tTorus", "tEllipsoid",
  "tQuadric", "tShapeFromFile", "tRectangle", "tDisk", "tWire",
  "tCharacteristic", "tLength", "tParametric", "tElliptic", "tRefineMesh",
  "tAdaptMesh", "tRelocateMesh", "tSetFactory", "tThruSections", "tWedge",
  "tFillet", "tChamfer", "tPlane", "tRuled", "tTransfinite", "tComplex",
  "tPhysical", "tCompound", "tPeriodic", "tUsing", "tPlugin",
  "tDegenerated", "tRecursive", "tRotate", "tTranslate", "tSymmetry",
  "tDilate", "tExtrude", "tLevelset", "tAffine", "tBooleanUnion",
  "tBooleanIntersection", "tBooleanDifference", "tBooleanSection",
  "tBooleanFragments", "tThickSolid", "tRecombine", "tSmoother", "tSplit",
  "tDelete", "tCoherence", "tIntersect", "tMeshAlgorithm", "tReverse",
  "tLayers", "tScaleLast", "tHole", "tAlias", "tAliasWithOptions",
  "tCopyOptions", "tQuadTriAddVerts", "tQuadTriNoNewVerts",
  "tRecombLaterals", "tTransfQuadTri", "tText2D", "tText3D",
  "tInterpolationScheme", "tTime", "tCombine", "tBSpline", "tBezier",
  "tNurbs", "tNurbsOrder", "tNurbsKnots", "tColor", "tColorTable", "tFor",
  "tIn", "tEndFor", "tIf", "tElseIf", "tElse", "tEndIf", "tExit", "tAbort",
  "tField", "tReturn", "tCall", "tSlide", "tMacro", "tShow", "tHide",
  "tGetValue", "tGetStringValue", "tGetEnv", "tGetString", "tGetNumber",
  "tUnique", "tHomology", "tCohomology", "tBetti", "tExists",
  "tFileExists", "tGMSH_MAJOR_VERSION", "tGMSH_MINOR_VERSION",
  "tGMSH_PATCH_VERSION", "tGmshExecutableName", "tSetPartition",
  "tNameToString", "tStringToName", "tAFFECTDIVIDE", "tAFFECTTIMES",
  "tAFFECTMINUS", "tAFFECTPLUS", "'?'", "tOR", "tAND", "tNOTEQUAL",
  "tEQUAL", "'<'", "'>'", "tGREATEROREQUAL", "tLESSOREQUAL", "'+'", "'-'",
  "'*'", "'/'", "'%'", "'!'", "UNARYPREC", "tMINUSMINUS", "tPLUSPLUS",
  "'^'", "'('", "')'", "'['", "']'", "'.'", "'#'", "','", "'{'", "'}'",
  "'~'", "$accept", "All", "GeoFormatItems", "GeoFormatItem", "SendToFile",
  "Printf", "View", "Views", "ElementCoords", "ElementValues", "Element",
  "@1", "@2", "Text2DValues", "Text2D", "@3", "Text3DValues", "Text3D",
  "@4", "InterpolationMatrix", "Time", "@5", "NumericAffectation",
  "NumericIncrement", "LP", "RP", "Affectation", "Comma",
  "DefineConstants", "@6", "@7", "@8", "@9", "UndefineConstants",
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
  "Homology", "FExpr", "FExpr_Single", "@23", "DefineStruct", "@24",
  "Struct_FullName", "tSTRING_Member_Float",
  "Option_SaveStructNameInConstant", "VExpr", "VExpr_Single",
  "RecursiveListOfListOfDouble", "ListOfDouble", "ListOfDoubleOrAll",
  "FExpr_Multi", "RecursiveListOfDouble", "ColorExpr", "ListOfColor",
  "RecursiveListOfColor", "StringExprVar", "StringExpr", "@25",
  "NameStruct_Arg", "RecursiveListOfStringExprVar", "StringIndex",
  "String__Index", 0
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
     264,   264,   264,   264,   264,   264,   265,   265,   266,   266,
     266,   267,   266,   268,   266,   269,   266,   266,   270,   266,
     271,   271,   272,   272,   272,   273,   273,   274,   274,   274,
     275,   275,   276,   276,   276,   276,   277,   277,   277,   278,
     278,   278,   279,   279,   279,   280,   280,   280,   281,   281,
     282,   282,   283,   283,   283,   283,   283,   283,   283,   283,
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
     310,   310,   310,   311,   311,   311,   311,   311,   312,   312,
     312,   313,   313,   314,   315,   315,   316,   316,   317,   317,
     318,   318,   319,   319,   320,   320,   320,   320,   320,   320,
     320,   320,   320,   320,   320,   320,   320,   320,   320,   320,
     320,   320,   320,   320,   320,   320,   320,   320,   320,   320,
     320,   320,   320,   320,   320,   321,   321,   321,   322,   322,
     322,   323,   323,   323,   323,   324,   324,   324,   324,   324,
     324,   324,   324,   324,   324,   324,   324,   324,   324,   324,
     324,   324,   324,   324,   324,   324,   324,   324,   324,   324,
     324,   324,   324,   324,   324,   324,   324,   324,   324,   324,
     324,   324,   324,   324,   324,   324,   324,   325,   325,   325,
     325,   325,   325,   325,   325,   325,   325,   325,   326,   325,
     325,   325,   325,   325,   325,   325,   325,   325,   325,   325,
     325,   325,   325,   325,   325,   325,   325,   325,   325,   325,
     325,   325,   325,   325,   325,   325,   328,   327,   329,   329,
     330,   331,   331,   332,   332,   332,   332,   332,   333,   333,
     333,   333,   334,   334,   335,   335,   335,   335,   335,   335,
     336,   336,   337,   337,   337,   337,   337,   337,   337,   337,
     337,   337,   337,   337,   337,   337,   337,   337,   337,   337,
     337,   337,   337,   337,   337,   337,   337,   337,   337,   337,
     337,   337,   337,   337,   337,   337,   337,   337,   337,   337,
     338,   338,   338,   338,   339,   339,   339,   339,   340,   340,
     341,   341,   342,   342,   342,   342,   342,   342,   342,   342,
     343,   343,   343,   343,   343,   343,   343,   343,   343,   343,
     343,   343,   343,   343,   343,   343,   343,   343,   343,   343,
     343,   343,   343,   343,   343,   343,   344,   343,   343,   345,
     345,   346,   346,   347,   347,   348,   348,   348
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
       1,     1,     1,     1,     5,     5,     2,     7,     7,     4,
       3,     6,     6,     7,     7,     6,     6,     9,     9,     6,
       6,     7,     7,     6,     6,     4,     8,     8,     9,     9,
       9,     9,     8,     8,     9,     9,     9,     9,     6,     9,
       6,     9,     5,     8,     8,    11,     6,     9,     5,     7,
       9,     9,    11,     7,     9,     9,     0,     1,     0,     3,
       5,     0,     9,     0,    11,     0,    11,     5,     0,     9,
       0,     3,     3,     5,     5,     0,     2,     3,     5,     3,
       0,     2,     3,     3,     3,     5,     1,     1,     3,     1,
       1,     3,     1,     1,     3,     1,     1,     3,     0,     5,
       0,     2,     7,     7,     7,     8,     8,     7,     7,    11,
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
       3,     9,     6,     1,     1,     1,     1,     1,     0,     2,
       3,     9,     4,    14,     0,     3,     0,     1,     0,     2,
       0,     2,     0,     2,     6,     7,     6,     8,     5,     3,
       8,     5,     4,     6,    11,    11,    18,    18,    12,    12,
      12,    10,    10,    10,    10,    10,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     2,     3,     6,     1,     1,
       1,     2,     5,     7,    10,     1,     3,     2,     2,     2,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     5,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     6,     4,     4,     4,     4,
       4,     4,     4,     6,     6,     6,     4,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     6,
       1,     4,     6,     1,     4,     4,     4,     4,     4,     4,
       4,     2,     5,     5,     5,     5,     3,     6,     4,     7,
       6,     6,     6,     4,     6,     4,     0,     8,     1,     4,
       1,     0,     3,     1,     2,     2,     3,     3,    11,     9,
       7,     7,     1,     3,     1,     1,     2,     3,     4,     5,
       1,     1,     2,     3,     3,     5,     4,     2,     2,     2,
       2,     3,     3,     3,     3,     5,     5,     5,     5,    16,
      16,    16,    16,     1,     1,     1,     3,     3,     4,     4,
       4,     6,     6,     6,     6,     8,     8,     4,    14,     4,
       1,     1,     3,     3,     9,     7,     1,     5,     3,     6,
       1,     3,     1,     1,     4,     4,     4,     4,     3,     6,
       1,     4,     1,     1,     1,     4,     6,     4,     6,     4,
       4,     4,     8,     4,     4,     4,     4,     8,     8,     6,
       4,     6,     4,     1,     4,     4,     0,     6,     4,     2,
       5,     1,     3,     5,     5,     1,     1,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     2,     3,     1,   605,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   343,   344,   345,
     346,   347,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   277,     0,     0,   285,   286,     0,     0,     0,   280,
       0,     0,     0,     0,     0,   398,   399,   400,     0,     0,
       5,     6,     7,     8,    10,    11,    24,    12,    13,    14,
      15,    23,    22,    21,    16,     0,    17,    18,    19,    20,
       0,    25,     0,   606,     0,   447,   605,   570,   448,   450,
     451,   449,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   572,     0,   593,   574,   455,   456,   457,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     452,   453,   454,   573,     0,     0,     0,     0,    70,    71,
       0,     0,   221,     0,     0,     0,   405,   460,     0,   562,
     606,   463,     0,     0,     0,     0,   264,     0,   266,   267,
     262,   263,     0,   268,   269,   128,   140,   605,   486,   606,
     488,    70,    71,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     270,     0,     0,     0,     0,     0,   605,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   533,   534,     0,   535,   504,   299,   505,
     606,   463,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   493,     0,     0,     0,     0,     0,   221,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   605,     0,   221,     0,     0,   395,     0,     0,
       0,     0,     0,     0,     0,     0,   511,     0,   510,     0,
       0,     0,     0,     0,   605,     0,     0,   556,     0,     0,
       0,     0,   260,   261,     0,     0,     0,     0,   278,   279,
       0,   221,     0,   221,   605,     0,   606,     0,     0,   221,
     401,     0,     0,    76,    70,    71,     0,     0,    63,    67,
      66,    65,    64,    69,    68,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   408,   407,   409,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   220,     0,   219,     0,     0,
     257,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    38,   253,     0,     0,
       0,   471,   186,     0,   605,     0,   562,   606,   563,     0,
       0,   601,     0,   126,   126,   491,     0,     0,     0,     0,
       0,   550,   551,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    70,    71,     0,     0,     0,     0,     0,     0,
       0,   517,     0,     0,   518,     0,   519,     0,   520,     0,
       0,     0,     0,     0,     0,     0,     0,   407,   512,     0,
     506,     0,     0,     0,    70,    71,     0,     0,     0,     0,
       0,     0,     0,   300,     0,   358,   358,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   221,   221,     0,   495,   494,     0,
       0,     0,     0,   221,   221,     0,     0,     0,     0,     0,
       0,     0,   296,     0,   221,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   360,     0,     0,     0,     0,
       0,     0,     0,   242,   396,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   369,   259,     0,     0,     0,     0,
       0,   221,     0,     0,     0,     0,     0,   282,   281,     0,
     247,     0,   248,     0,     0,     0,   221,     0,     0,     0,
       0,   348,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    80,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   458,     0,     0,
       0,   596,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    63,    64,     0,   406,    63,    64,     0,     0,    63,
       0,     0,     0,     0,     0,   216,     0,     0,     0,     0,
       0,     0,     0,   222,     0,     0,     0,   423,   422,   421,
     420,   416,   417,   419,   418,   411,   410,   412,   413,   414,
     415,     0,     0,     0,   490,   476,   187,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     127,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   352,
       0,     0,     0,     0,     0,     0,     0,   388,   389,   390,
       0,     0,     0,    72,    73,     0,   536,     0,     0,     0,
       0,     0,   463,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   521,     0,   522,     0,   523,     0,   524,     0,
       0,     0,   406,   507,   514,     0,   412,   513,     0,     0,
       0,   537,   476,     0,     0,     0,     0,     0,     0,     0,
     356,     0,     0,     0,   156,   157,     0,   159,   160,     0,
     162,   163,     0,   165,   166,     0,   392,     0,   393,     0,
     394,     0,     0,     0,     0,   391,   221,     0,     0,     0,
       0,     0,   497,   496,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   290,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   372,     0,     0,
     243,     0,     0,   239,     0,     0,     0,   387,   386,     0,
       0,     0,   406,     0,     0,     0,     0,     0,     0,     0,
       0,   283,   284,     0,     0,   249,   251,     0,   607,     0,
       0,     0,     0,     0,     0,    63,    64,     0,     0,    63,
      64,     0,     0,     0,     0,    95,    79,     0,   465,   464,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   446,
     434,     0,   436,   437,   438,   439,   440,   441,   442,     0,
       0,     0,   583,     0,   590,   579,   580,   581,     0,   595,
     594,     0,   483,     0,     0,     0,     0,   584,   585,   586,
     485,   592,   145,   599,   598,     0,   150,   118,     0,     0,
     575,     0,   577,     0,   461,   468,   469,   571,     0,     0,
       0,    63,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   112,     0,     0,     0,     0,   470,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   603,     0,     0,
      48,     0,     0,     0,    61,     0,    39,    40,    41,    42,
      43,   467,   466,   478,     0,     0,    28,    26,     0,     0,
       0,     0,   568,    29,     0,     0,   254,   602,    74,   129,
      75,   141,     0,     0,   489,     0,     0,     0,   552,   553,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     9,   465,   464,     0,     0,   540,
       0,   539,   538,     0,     0,   547,     0,     0,   516,     0,
       0,     0,     0,     0,     0,     0,   549,   508,     0,     0,
       0,   467,   466,     0,     0,     0,     0,     0,   406,   354,
     359,   357,     0,   368,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   406,   406,   406,     0,     0,     0,     0,
       0,   250,   252,     0,     0,     0,   211,   213,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   329,     0,   287,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   361,   371,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   244,     0,     0,     0,     0,     0,   246,
       0,   349,     0,     0,     0,     0,   402,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   604,     0,     0,
     473,     0,   472,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    89,     0,    93,     0,     0,    81,
       0,     0,     0,     0,    85,   108,   110,     0,     0,   560,
       0,   116,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   424,     0,     0,     0,     0,     0,    34,   475,
     474,   566,   564,    27,     0,     0,   567,   565,     0,     0,
       0,     0,     0,   492,   145,     0,     0,     0,     0,     0,
     170,   170,     0,     0,     0,     0,     0,     0,     0,   168,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     364,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   525,   526,   527,   528,     0,
     515,   509,     0,     0,     0,     0,     0,     0,     0,     0,
     366,     0,     0,   158,     0,   161,     0,   164,     0,   167,
       0,     0,     0,     0,     0,     0,     0,   245,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   335,     0,
       0,   334,     0,   337,     0,   339,     0,   297,   330,     0,
       0,     0,   238,     0,     0,     0,     0,     0,     0,     0,
       0,   373,     0,   241,   240,   397,     0,     0,    35,    36,
       0,     0,     0,     0,   557,     0,     0,     0,   273,     0,
       0,     0,   221,   350,   221,     0,     0,     0,     0,    90,
       0,    94,     0,     0,    82,     0,    86,     0,   256,   477,
     255,   435,   443,   444,   445,   591,     0,     0,   589,   481,
     482,   484,     0,     0,   459,   146,     0,     0,   597,   151,
     480,   576,   578,   462,     0,     0,     0,    91,     0,     0,
       0,    63,     0,     0,     0,     0,    83,     0,     0,     0,
     558,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   502,     0,     0,    30,    31,
       0,    32,     0,     0,   130,   137,     0,     0,     0,    77,
      78,   172,     0,     0,     0,     0,     0,     0,   173,     0,
       0,   189,   190,     0,     0,     0,     0,   174,   202,   191,
     195,   196,   192,   193,   194,   181,     0,     0,     0,   477,
     543,   542,   541,     0,     0,     0,     0,     0,     0,     0,
     204,   544,   197,     0,     0,   168,     0,     0,   365,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     258,     0,     0,     0,     0,   221,   221,     0,   311,     0,
     313,     0,   315,     0,     0,   336,   504,     0,     0,   338,
     340,     0,     0,   291,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   198,     0,     0,     0,     0,   177,
     178,     0,     0,     0,     0,   119,   123,     0,     0,   348,
     348,     0,   403,     0,     0,     0,    92,     0,     0,     0,
      84,     0,   479,     0,     0,     0,     0,   600,     0,     0,
     102,     0,     0,    96,     0,     0,     0,     0,   113,     0,
       0,   114,     0,   561,   223,   224,   225,   226,     0,     0,
       0,     0,     0,     0,    44,     0,     0,     0,     0,     0,
      46,   569,     0,     0,   131,   138,     0,     0,   487,     0,
       0,   171,   175,   176,   182,     0,     0,   201,     0,   184,
       0,     0,   367,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   183,     0,   205,   355,   203,   207,   208,   209,
     210,   180,     0,   199,   206,     0,     0,     0,     0,     0,
       0,   501,     0,   500,     0,     0,     0,   302,     0,     0,
     303,     0,     0,   304,     0,     0,     0,     0,     0,     0,
       0,     0,   237,   236,     0,     0,     0,     0,     0,     0,
       0,     0,   227,     0,     0,   370,    37,     0,     0,   555,
       0,   275,   274,     0,     0,     0,     0,     0,     0,     0,
     103,     0,     0,    97,     0,     0,     0,   582,   588,   587,
       0,   147,   149,     0,   152,   153,   154,   104,   106,    98,
     100,   109,   111,     0,   117,     0,    87,    49,     0,     0,
       0,   503,     0,     0,     0,    33,     0,   145,   150,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   545,
     546,     0,     0,     0,     0,     0,     0,   185,     0,   362,
     362,     0,   124,   125,   221,     0,   214,   215,     0,     0,
       0,     0,     0,     0,   298,     0,   331,     0,     0,   221,
       0,     0,     0,     0,     0,     0,     0,     0,   218,   217,
       0,     0,     0,     0,   120,   121,     0,     0,   351,     0,
     105,   107,    99,   101,    88,     0,   550,   551,     0,     0,
     559,     0,    45,     0,     0,     0,    47,    62,     0,     0,
       0,   135,   133,   381,   383,   382,   384,     0,   385,   188,
       0,     0,     0,     0,     0,     0,   301,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   499,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   342,     0,
       0,     0,   292,     0,   228,     0,     0,     0,     0,     0,
       0,     0,   554,   276,     0,     0,   221,   404,     0,   148,
       0,     0,   155,   115,     0,     0,     0,     0,     0,   132,
     139,   145,   145,   169,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   363,   374,     0,     0,   375,     0,   212,
       0,   317,     0,     0,   319,     0,     0,   321,     0,     0,
       0,   332,     0,   288,     0,   221,     0,     0,     0,     0,
       0,     0,   179,   122,   272,   348,     0,   142,     0,     0,
      53,     0,    59,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   200,     0,   378,     0,   379,   380,   498,
     305,     0,     0,   312,   306,     0,     0,   314,   307,     0,
       0,   316,     0,     0,     0,   294,   231,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   136,   134,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   323,     0,   325,     0,   327,   333,   341,   293,
     289,     0,     0,     0,     0,     0,     0,     0,     0,   143,
     144,    50,     0,    57,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   308,     0,     0,   309,     0,
       0,   310,     0,     0,   232,   233,   234,   235,     0,   229,
     353,     0,    51,     0,     0,   265,     0,   548,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     295,     0,     0,     0,     0,     0,   271,     0,     0,     0,
       0,     0,     0,   318,     0,   320,     0,   322,     0,   230,
      52,    54,     0,    55,     0,   529,   530,   531,   532,     0,
       0,     0,     0,     0,     0,     0,    60,   376,   377,   324,
     326,   328,    56,    58
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,   110,  1138,   111,   112,   811,  1763,  1769,
    1126,  1373,  1981,  2221,  1127,  2157,  2262,  1128,  2223,  1129,
    1130,  1377,   415,   511,   214,   876,   113,   831,   523,  1907,
    2062,  2061,  1908,   524,  1975,  1335,  1555,  1337,  1559,   923,
     926,   929,   932,  1625,  1615,   793,   293,   486,   487,   116,
     117,   118,   119,   120,   121,   122,   123,   294,  1265,  2094,
    2181,   962,  1828,  1831,  1834,  2131,  2135,  2139,  2206,  2209,
    2212,  1261,  1262,   295,  1011,   296,   127,  1449,  1222,   920,
     976,  2011,   128,   129,   130,   131,   297,   216,  1072,   217,
     525,   238,   815,   835,   628,   331,  1594,   368,   369,   299,
     591,   376,  1106,  1360,   521,   516,  1076,   759,   522,   396,
     301
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1706
static const yytype_int16 yypact[] =
{
   11668,    63,   104, 11815, -1706, -1706,  4703,    16,    57,   -63,
     -41,    42,   121,   221,   230,   303,   -31,   317,   333,  -107,
     -14,    34,   165,   165,  -140,   105,   161,    19,   169,   186,
      22,   194,   204,   207,   240,   249,   290,   298,   323,   339,
     361,   474,   366,   501,   608,   442,   342,   433,  6468,   456,
     455,   601,   -37,   414,   611,   248,   541,   201,   486,   687,
      -5,   503,  -116,  -116,   544,   252,   592, -1706, -1706, -1706,
   -1706, -1706,   554,   545,   702,   726,     5,    43,   734,   717,
     210,   832,   836,   878,  6014,   884,   669,   676,   700,    21,
      53, -1706,   703,   711, -1706, -1706,   821,   885,   685, -1706,
   11978,   729,  6117,    30,    31, -1706, -1706, -1706, 10980,   735,
   -1706, -1706, -1706, -1706, -1706, -1706, -1706, -1706, -1706, -1706,
   -1706, -1706, -1706, -1706, -1706,   -11, -1706, -1706, -1706, -1706,
      47, -1706,   977,  -160,   287, -1706,     9, -1706, -1706, -1706,
   -1706, -1706,   165,   165,   165,   165,   165,   165,   165,   165,
     165,   165,   165,   165,   165,   165,   165,   165,   165,   165,
     165,   165,   165,   165,   165,   165,   165,   759,   768,   777,
     165,   165,   165,   165,   788,   165,   165,   165,   165,   165,
     165,   796, -1706,   165, -1706, -1706, -1706, -1706, -1706,   165,
     165,   165,  1036,   819,   820,   829,   165,   165,   842,   843,
   -1706, -1706, -1706, -1706,   834, 10980, 10980, 10980, 10098, 10319,
      26,    34,   537,   869,   874,   432, -1706, -1706,   890,  1086,
     -69,   198,  1127, 10980, 12007, 12007, -1706, 10980, -1706, -1706,
   -1706, -1706, 12007, -1706, -1706, -1706, -1706,   920, -1706,   941,
    1179, -1706, -1706,  4782,    34, 10980,  9802, 10980, 10980,   980,
   10980,  9802, 10980, 10980,   987, 10980,  9802, 10980, 10980, 10980,
   10980, 10980, 10980, 12007, 10980, 10980, 10980,  6695,   991,   992,
   -1706,  9802,  6014,  6014,  6014, 12007,    80,   558,   165,   165,
     165,   165,    28,    29,    51,    62,  6695,  1110,   618,   165,
    6922, 10980,  5316, -1706, -1706,   997, -1706,   929, -1706, -1706,
     268,   259, 10980,  9802,   998,  1012,  7149,  6014,  6014,  6014,
    1033,  1037,  1041,  1042,  1049,  7376,  7603,  7830,  1043,  3426,
    1285,  6695,    21,  1064,  1065,  -116,  -116,  -116, 10980, 10980,
    -105, -1706,   -36,  -116,  1070,  1078,  1106,  9575,    -7,   129,
    1114,  1122,  1124,  1153,  1156,  1168,  1169, 10980,  6014,  6014,
    6014,  1174,    12,  1125, -1706,  1365,  1397, -1706,  1172,  1176,
    1177,  6014,  6014,  1183,  1184,  1186, -1706, 10980, -1706,  1398,
    1403, 10980, 10980, 10980,   246, 10980,  1182, -1706,  1246, 10980,
   10980, 10980, -1706, -1706, 10980,  1415,  1416,  1189, -1706, -1706,
    1419, -1706,  1421, -1706,   327,  5094,   357, 12007, 10980, -1706,
   -1706,  6695,  6695, -1706, 10392, 10613,  1194,  1195,  4782, -1706,
   -1706, -1706, -1706, -1706, -1706,  6695,  1428,  1206, 10980, 10980,
   10980, 10980, 10980, 10980, 10980, 10980, 10980, 10980, 10980, 10980,
   10980, 10980, 10980, 10980, 10980, 10980, 10980, 10980, 10980, 10980,
   10980, 10980, 12007, 12007, 12007, 12007, 12007, 12007, 12007, 12007,
   12007, 12007,  6695, 12007, 12007, 10980, 12007, 12007, 12007, 12007,
   12007, 10980,    74,  4782, 10980, 12007, 12007, 12007, 12007, 12007,
      34,  4782,    34,  1213,  1213,  1213,    25, 13624,   147, 13233,
     294,  1209,  1438,   165,  1212, -1706,  1214, 12126, 10980,  9802,
   -1706, 10980, 10980, 10980, 10980, 10980, 10980, 10980, 10980, 10980,
   10980, 10980, 10980, 10980, 10980, 10980, -1706, -1706, 10980, 10980,
    1448, -1706, -1706,  1148,   543,   426, -1706,   604,  1222,   445,
   10638, -1706,   465,   182,   273,  1225,  1453,  1228,  1229, 13645,
    9802,  1116, -1706,   531, 13666, 13687, 10980, 13708,   720, 13729,
   13750, 10980, 13771,   741, 13792, 13813, 13834, 13855, 13876, 13897,
    1239, 13918, 13939, 13960,  1462, 10980, 10980,   748,  1466,  1467,
    1468,  1247, 10980, 10980,   512,  8057,  8284, 10980, 10980, 12007,
   10980, -1706,  1413, 10980, -1706,  1417, -1706,  1420, -1706,  1422,
    6695,    32,    38,    39,    41,  9802,  9802,  1213, -1706, 13981,
   -1706,   752, 10980,  8511, 10980, 10980,   528,  1448, 14002,   757,
   10980, 10980, 10980, -1706,  1471,  1476,  1476, 10980, 10023, 10023,
   10023, 10023, 10980,  1479, 10980,  1480, 10980,  1481,  9802,  9802,
   10443,  1260,  1484,  1256, -1706, -1706,   -46, -1706, -1706, 10737,
   10810,  -116,  -116,   537,   537,   -40, 10980, 10980, 10980,  9575,
    9575, 10980,    49,   -28, -1706, 10980, 10980, 10980, 10980, 10980,
   10980, 10980, 10980, 10980, 14023,  1485,  1487,  1488, 10980,  1491,
   10980, 10980,  1541, -1706, -1706,  9802,  9802,  9802,  1494,  1495,
   10980, 10980, 10980, 14044, -1706, -1706, 14065, 14086, 14107,  1325,
   10853, -1706,  1267,  3640, 14128, 14149, 13256, -1706, -1706,  9802,
   -1706,  2116, -1706,  2673, 10980, 10980, -1706, 10980, 10980,  1272,
   14170, 12008,  1275,   761,   177, 14191,   200, 13279, 10980,  9802,
    1503,  1504, -1706, 10980, 14212, 13302, 13210, 13210, 13210, 13210,
   13210, 13210, 13210, 13210, 13210, 13210, 13210, 10934, 13210, 13210,
   13210, 13210, 13210, 13210, 13210, 11110, 11246, 11374,   -74,   574,
     -74,  1286,  1287,  1277,   773,   773,  1280,   773,  1283,  1288,
    1289, 11473,   773,   773,   773,   587,   773, 14968, 10980,   773,
    1513, -1706,  1350,  1292,  1294,  1302,   595,   617,  1303,  1304,
    1305,  1493,  1500,  6695,   309,  1501,  1502,  6695,   124,  4782,
   10980,  1529,  1534,    23,   773, -1706,   315,    24,    27,   376,
    1319,   -33,   750, -1706,  4375,   775,  3659,  1390,   867,   813,
     813,   847,   847,   847,   847,   740,   740,  1213,  1213,  1213,
    1213,    15, 14233, 13325, -1706,  -101, -1706, 10980, 10980,    11,
    9802, 10980, 10980,  1448,  1542,  9802, 10980,  1544, 12007,  1546,
   -1706,    34,  1550, 12007,    34,  1328,    34, 10980,  4782,  1567,
    9802,  9802,  1406,  1568,  1572, 14254,  1575,  1411,  1577,  1578,
   14275,  1579,  1418,  1584,  1585,  1587,  1588,  1589,  1591, -1706,
    1592,  1606,  1608, 10980, 14296,  4467,  1383, -1706, -1706, -1706,
    1613, 14317, 13348, -1706, -1706,  9802, -1706,  9802,  1116,  1391,
    9802,  1392,   305, 11506, 12040,   773, 12066,  1387,  4584,  1389,
    1405,  1407, -1706,  9802, -1706,  9802, -1706,  9802, -1706,  9802,
     773,   781,  1618, -1706,  4122,  9802,  1213, -1706, 14338, 13371,
    9802, -1706,  -184,  1619,  1412, 14359, 14380, 14401, 10980,  6695,
    1637,  1640, 14422,  1423, 14968,  1426,  1427, 14968,  1432,  1439,
   14968,  1433,  1440, 14968,  1436, 14443, -1706, 14464, -1706, 14485,
   -1706,   785,   786,  9802,  1425, -1706, -1706,  4147, 11129,  -116,
   10980, 10980, -1706, -1706,  1435,  1441,  9575, 12092, 12118, 12144,
   10559,  1548,   -34,  -116, 11169, 14506,  4659, 14527, 14548, 14569,
   14590, 14611, 14632, 14653,  1668, 10980,  1670, -1706, 10980, 14674,
   -1706, 13394, 13417, -1706,   789,   802,   805, -1706, -1706, 13440,
   13463, 12170, -1706,  1671,  1672,  1673,  1450, 10980, 11266, 10980,
   10980, -1706, -1706,    13,   810, -1706, -1706, 11305, -1706,  1676,
   10686,  1451,  1455,  6695,  1682,  1647,  1648,  6695,   309,  1650,
    1651,  6695,   309,  4732,   815, -1706, -1706, 13486,   176,   321,
   -1706, -1706, -1706, -1706, -1706, -1706, -1706, -1706, -1706, -1706,
   -1706, 10980, -1706, -1706, -1706, -1706, -1706, -1706, -1706, 10980,
   10980, 10980, -1706,  9802, -1706, -1706, -1706, -1706, 12007, -1706,
   -1706, 10980, -1706,  6695, 12007, 12007, 12007, -1706, -1706, -1706,
   -1706, -1706, -1706, 14968, -1706,  1688, -1706, -1706, 10980, 12007,
   -1706, 12007, -1706, 10980, -1706, -1706, -1706, -1706,   165,   165,
    1691, -1706, 10980,  1694,   165,   165,  1695,    35, 10980,  1696,
    1697,  1582, -1706,  1704,  1482,    21,  1708, -1706,  9802,  9802,
    9802,  9802, 10980,  1489,  1492,  1496,  1506, -1706,   773, 10980,
   -1706,  1508,  1509,  1486, -1706,  1709, -1706, -1706, -1706, -1706,
   -1706,   399,   446, -1706, 14695, 13509, -1706,  1507, 12007,   649,
   14716, 13532, -1706, -1706,   674, 12196, -1706, -1706, -1706,    56,
   -1706, -1706,  1483, 10980, -1706, 13210,   773,  -116,  1116, -1706,
     983,  6695,  6695,  1716,  6695,  1005,  6695,  6695,  1722,  6695,
    1622,  6695,  6695,  6695,  6695,  6695,  6695,  6695,  6695,  6695,
    1741,  1723,  1724,  9802, -1706,  -184,   349,   864,   895, -1706,
     896, -1706, -1706, 10980, 10980, -1706, 10980, 10980, -1706, 10980,
   10980, 10980,   900,   926,   931,   943, -1706, -1706,  6695, 10980,
     948,  -184,  -184,   949,  6695,  9802,  1725,  1733,  1734,  1943,
   -1706, -1706,  1736, -1706,  1737,   212, 10980,   212, 10980,   212,
   10980,   212, 10980,  1738,  1739,  1742,  1744,  1746,   952,  1751,
   11402, -1706, -1706,   109, 12222, 12248, -1706, -1706,  4791,  -154,
    -116,  -116,  -116,  1639,  1754, 10907,  1524,  1755,  1520,    45,
      46,   -50, -1706,   117, -1706,   -34,  1753,  1757,  1758,  1761,
    1762,  1763,  1764,  1765,  1766,  6695, 14968, -1706,  1760,  1532,
    1768,  1769,  1770,  1686,  1772,  1774,  1775, 10980,  6695,  6695,
    6695,  1780, 12274, -1706,  4258,   515,  1781,  1782,  1553, -1706,
    1554, -1706,  1903,  1570,  6695,  1552, -1706,   165,   165,  1800,
   10980,  1801,   165,   165,  1802, 10980,  1804, -1706,   773,  1805,
   -1706,  1808, -1706,  1807, 13210, 13210, 13210, 13210,   621,  1580,
    2109,  1586,   773,   773,  1583,   664,  1593,   683, 14737,  1596,
     773, 13210,  1197, 12007, -1706,  2792, -1706,  1197, 12007, -1706,
     353,  1590,  1809,  2850, -1706, -1706, -1706,    21, 10980, -1706,
     956, -1706,   959,   960,   963,   964, 14758, 10980, 10980, 10980,
   10980,   212, 14968,  1599, 10980, 10980,  6695,  1597, -1706, -1706,
   -1706, -1706,  1602, -1706,  1814,    73, -1706, -1706,  1815, 10980,
    9192,  1607,  1609, -1706, 14968,  1822,  1832,    77,  1604,  1610,
    1726,  1726,  6695,  1835,  1611,  1614,  1836,  1842,  6695,  1678,
    1617,  1848,  1849,  1850,  1851,  1852,  1853,  1855,  1856,  1857,
   -1706,  1859,  6695,   970,  1861,   773,  1638,  1635, 12300, 12326,
   12352, 12378, 12404, 12430, 12456, -1706, -1706, -1706, -1706,  1862,
   14968, -1706,   773,  1863,   973,  6695,  6695,  6695,  1866,  1865,
   -1706,  6695,  6695, 14968,  6695, 14968,  6695, 14968,  6695, 14968,
    6695,  6695,  6695,  1641,  1643,  1867,    86, -1706, 10980, 10980,
   10980,  1644,  1646,  -147,  -108,   -86,  1652,  1642, -1706,  2968,
    6695, -1706, 10980, -1706,  1869, -1706,  1876, -1706, -1706,  9575,
     599,  6241, -1706,  1653,  1654,  1656,  1657,  1658,  1659,  8738,
    1877, -1706,  9802, -1706, -1706, -1706,  1660, 10980, -1706, -1706,
   13555,  1879,  1880,  1728, -1706, 10980, 10980, 10980, -1706,  1891,
     355,  4782, -1706, -1706, -1706,  1664,  1894,  1197, 12007, -1706,
    2989, -1706,  1197, 12007, -1706,  3067, -1706,   212, -1706,   585,
   -1706, -1706, -1706, -1706, -1706, -1706, 12007, 10980, -1706, -1706,
   -1706, -1706, 12007,  1897, -1706, -1706, 10980,    36, -1706, -1706,
   -1706, -1706, -1706, -1706,  1896,   -74,   -74, -1706,  1898,   -74,
     -74,  4782, 10980,  1899,  1904,    23, -1706,  1920, 13578,    21,
   -1706,  1921,  1924,  1925,  1927,  1618, 14779, 14800, 14821, 14842,
    6695, 10980, 12482, 12508,   988, -1706, 10980,  1906, -1706, -1706,
   12007, -1706, 12534,  5560, 14968, -1706,  1928,  1929,   311, -1706,
   -1706, -1706, 10980, 10980,  -116,  1931,  1932,  1933, -1706, 10980,
   10980, -1706, -1706,  1934,  1813,  1935, 10980, -1706, -1706, -1706,
   -1706, -1706, -1706, -1706, -1706, -1706,  1937,  1938,  1699,  -184,
   -1706, -1706, -1706, 10980, 10980, 10980, 10980, 10980, 10980, 10980,
   -1706, -1706, -1706,  1711,  1941,  1678,  1942, 10980, -1706,  1958,
    1959,  1960,  1961,  1977,  1979,  1097,  1980,  9802,  9802, 10980,
   -1706, 10023,  5259, 14863,  3256,   537,   537,  -116,  1982,  -116,
    1984,  -116,  1985, 10980, 10980, -1706,   648,  1759, 14884, -1706,
   -1706,  5498,   156, -1706,  1986,  1988,  6695,  -116,  -116,  -116,
    -116,  -116,  5053,  1989, -1706,  1002, 10980,  3122,  1990, -1706,
   -1706,  6695,  3823,   901, 14905, -1706, -1706,  9273,  1767, 12008,
   12008,  6695, -1706,  1991,   -74,   -74, -1706,  1992,   -74,   -74,
   -1706,  6695, -1706,  1714, 13210,   773,  5787, 14968,  9500,  4782,
   -1706,  1993,  1994, -1706,  1996,  1999,  2000,  3161, -1706,  2003,
    2005, -1706,  1783, -1706, -1706, -1706, -1706, -1706,  1734,  1738,
    1739,  1742,  2006,   742, 14968, 10980, 10980,  6695,  1778,  1003,
   14968, -1706,  2008, 10980, -1706, -1706,  1784,  1785, -1706,  5725,
    6179,   682, -1706, -1706, -1706,  6406,  6633, -1706,  1786, -1706,
    6860,  2011, -1706,  6695, 13210, 13210, 12560, 12586, 12612, 12638,
   12664, 10980, -1706,  2012, -1706, 14968, -1706, -1706, -1706, -1706,
   -1706, -1706,  1788, -1706, -1706,  1016,  1017, 10516,  3355,  2018,
    1790, -1706, 10980, -1706,  1791,  1793,   191, -1706,  1795,   218,
   -1706,  1796,   242, -1706,  1797,  7087, 13601,  2027,  6695,  2010,
    1799, 10980, -1706, -1706,  1024,   254,   256,   310,   314,   320,
    8965,   350, -1706,  2029,  7314, -1706, -1706,  1870, 10980, -1706,
   10980, -1706, -1706,  9802,  3555,  2030,  4782,  1806,  1810,  1811,
   -1706,  2032,  2034, -1706,  2037,  2044,  2045, -1706, -1706, -1706,
    5316, -1706, -1706, 12007, 14968, -1706, -1706, -1706, -1706, -1706,
   -1706, -1706, -1706,    21, -1706,  1882, -1706, -1706, 10980, 12690,
   12716, -1706,  6695, 10980,  2047, -1706, 12742, -1706, -1706,  6695,
    6695,  2048,  2050,  2052,  2054, 10980,  2056,  2058,  1032, -1706,
   -1706, 10980, 10980, 10980, 10980, 10980,  7541, -1706,  6695,    64,
     588,  9802, -1706, -1706,   537,  3958, -1706, -1706,  9575,   -34,
    9575,   -34,  9575,   -34, -1706,  2059, -1706,  1039,  6695, -1706,
    7768,  2060,  9802,  -116,  -116,  -116,  -116,  -116, -1706, -1706,
   10980,  7995,  8222,  1040, -1706, -1706,  1841,  1837, -1706,  2065,
   -1706, -1706, -1706, -1706, -1706,  1047,  1702,  2066,  1048,  2069,
   -1706,  1843, 14968, 10980, 10980,  1058, 14968, -1706, 10980,  1059,
    1072, -1706, -1706, -1706, -1706, -1706, -1706,  8449, -1706, -1706,
    1844, 12768, 12794, 12820, 12846, 12872, -1706,  1080,  1845,  -116,
    6695,  2071,  1846,  -116,  2076,  1083,  1847, 10980, -1706,  8676,
     352,   640,  8903,   354,   651,  9148,   373,   663, -1706,  6695,
    2078,  1962, 11441,  1854, -1706,  1084,   404,   439,   451,   477,
     479,  3574, -1706, -1706,  2079,  2081, -1706, -1706, 10980, -1706,
    4782,    34, -1706, -1706, 10980, 14926, 12898,    44, 12924, -1706,
   -1706, -1706, -1706, -1706, 10980, 10980, 10980, 10980, 10980, 10980,
    2082,  -116,    79, -1706, -1706,  -116,   102, -1706,  2084, -1706,
    9219,  2085, 10980,  2086,  2087, 10980,  2093,  2094, 10980,  2095,
    1868, -1706, 10980, -1706,   -34, -1706,  2096,  9802,  9802,  9802,
    9802,  8965, -1706, -1706, -1706, 12008,  2299, -1706,  1875,  1087,
   -1706, 10980, -1706,  6695, 10980,  1088,  1112, 12950, 12976, 13002,
   13028, 13054, 13080, -1706,   484, -1706,   527, -1706, -1706, -1706,
   -1706,  1871,  9405, -1706, -1706,  1873,  9448, -1706, -1706,  1874,
    9527, -1706,  2099,  3621,   730, 11538, -1706,  1113,  1117,  1138,
    1142,   534,  1143,  1890,  4782,  1902,  2105,  1892, 14947,  1146,
    9740, -1706, -1706, 10980, 10980, 10980, 10980, 10980, 10980,  -116,
    -116,   -34,  2126,   -34,  2127,   -34,  2128, -1706, -1706, -1706,
   -1706,   -34,  2129,  2130,  2131,  2135,  9802,  2136,  2137, -1706,
   -1706, -1706, 12007, -1706,  1909,  2139,  9928, 13210, 13106, 13132,
   13158, 13184,   559,   565,   823, -1706,  1911,   857, -1706,  1912,
    1079, -1706,  1913,  1147, -1706, -1706, -1706, -1706,  1154, -1706,
   -1706,  1155, -1706,  1914,  6695, -1706,  2144, -1706, 10980, 10980,
   10980, 10980, 10980, 10980,  2160,   -34,  2161,   -34,  2162,   -34,
   -1706,  2163, 12007,  2165, 12007,  1158, -1706,  9971, 10048, 10149,
   10222, 10265, 10344, -1706,  1282, -1706,  1315, -1706,  1357, -1706,
   -1706, -1706,  1159, -1706,  2167, -1706, -1706, -1706, -1706,  2168,
    2169,  2170,  2171,  2172, 12007,  2173, -1706, -1706, -1706, -1706,
   -1706, -1706, -1706, -1706
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1706, -1706, -1706, -1706,   795, -1706, -1706, -1706, -1706,   127,
   -1706, -1706, -1706, -1706, -1706, -1706, -1706, -1706, -1706, -1706,
   -1706, -1706,  -382,   -59,  4372,  3698, -1706,  1661, -1706, -1706,
   -1706, -1706, -1706, -1706, -1706, -1386, -1706,   274, -1706, -1706,
   -1706, -1706, -1706,   529,   787,  2183,    -2,  -623,  -333, -1706,
   -1706, -1706, -1706, -1706, -1706, -1706, -1706,  2184, -1706, -1706,
   -1706, -1706, -1706, -1706, -1706, -1706, -1706, -1706, -1706, -1706,
   -1706, -1181, -1255,  2187, -1705,  2188, -1706, -1706, -1706,  1594,
   -1706,   262, -1706, -1706, -1706, -1706,  2043, -1706, -1706,  2190,
   -1706, -1706,  -543, -1706,   888, -1706, -1684,  2908,  1377,  3113,
    1164,  -320,   619, -1706,   152,    18, -1706, -1706,  -437,    -3,
     476
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -570
static const yytype_int16 yytable[] =
{
     133,   115,   623,   220,   642,   738,  1488,   740,  1608,   352,
     954,   955,  1844,   417,  1867,  1868,   659,  1136,   239,  1120,
    1296,   662,   755,   249,   219,   374,   254,  1104,   249,   222,
     480,   254,   771,   571,   574,   390,   392,   892,   237,  1350,
    1738,   413,   414,   894,   896,   300,   898,   356,   226,   357,
    2112,  1483,  1485,   400,   912,   305,   576,   378,   691,   305,
     693,     7,     8,  1390,   631,   632,   701,   578,   404,     4,
     405,   631,   632,   239,  1254,   416,   306,   406,   237,  1599,
    1113,   300,  1472,  1611,  1490,  2125,   239,  1677,   245,  1678,
    1254,  1255,  1670,  1671,   773,   246,   777,   239,   780,  1256,
    1257,  1258,   326,   327,     5,  1259,  1260,  1255,  2127,  1918,
     631,   632,   328,   631,   632,  1256,  1257,  1258,   385,   329,
     389,  1259,  1260,   235,   413,   414,  1679,   228,  1680,   358,
     633,  1091,   631,   632,  -568,   786,    25,    26,   787,    28,
      29,   788,    31,   789,    33,    34,    35,    36,  1681,   223,
    1682,    38,    39,    40,   775,   873,    42,   874,   218,   508,
     828,   509,   790,    49,   322,   224,    51,   791,   406,    54,
      55,   792,   631,   632,  1121,  1122,  1123,  1124,   631,   632,
     323,   324,   631,   632,  1015,   353,  1487,   225,   949,    72,
     631,   632,  2008,  2009,   956,   481,   482,   232,  2010,   634,
     572,   575,  1484,  1486,  1351,  1352,   963,  1019,   239,   109,
     485,   631,   632,    86,    87,    88,   236,   398,  1985,  1091,
    1739,   517,   517,   577,   399,   109,  1137,   229,   644,   517,
     409,   410,   411,   772,   579,  1488,   230,   418,   109,   419,
     354,   239,   660,   300,  2007,  1297,   213,   250,   300,   213,
     255,  1125,   250,   300,   251,   255,   375,   256,  1105,  1109,
     517,   527,  1110,   573,   300,   391,   393,   893,   300,   300,
     300,   300,   517,   895,   897,   401,   899,   227,   109,  2113,
    1142,   379,   402,   300,  1391,   961,  1392,   300,  1137,   300,
     318,   947,   948,   319,   408,   631,   632,   631,   632,   361,
     300,   779,   362,   300,   300,   300,   300,   758,   562,   231,
     563,   964,   300,   300,   300,   212,  1091,   213,   300,   239,
     631,   632,  1017,   233,  1021,   514,   137,   631,   632,   409,
     410,   411,   412,   247,   311,   631,   632,   312,   334,   234,
     313,   335,   314,  1468,   336,   300,   300,   300,   998,   413,
     414,  1489,   409,   410,   411,   776,  1097,   645,   300,   300,
    1571,  1716,  1717,  1007,   646,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   631,   632,   515,   519,   177,   178,
     179,   180,   409,   410,   411,  1016,   182,   183,   184,   248,
    1841,   185,  1092,   241,   517,   242,  1098,   252,   300,   300,
    2153,   413,   414,   190,   191,   409,   410,   411,  1020,   631,
     632,  -566,   300,   829,   253,   550,   830,   409,   410,   411,
     412,   781,   257,   413,   414,  1938,   710,   561,   272,  2159,
     510,   273,   258,  -563,   274,   259,   631,   632,   490,   517,
     517,   517,   517,   517,   517,   517,   517,   517,   517,   300,
     517,   517,  1940,   517,   517,   517,   517,   517,   268,   239,
     631,   632,   517,   517,   517,   517,   517,   239,   260,   239,
     326,   327,   631,   632,   631,   632,  1942,   261,   679,   134,
     328,   761,   221,   213,   413,   414,   300,   337,  1952,   769,
    1953,   597,   409,   410,   411,   412,   594,   240,   595,   409,
     410,   411,   412,   307,   832,   406,   308,   830,   309,   194,
     195,   196,   413,   414,   409,   410,   411,   412,   262,   413,
     414,  1989,   203,  1517,   204,   109,   263,   300,   631,   632,
     413,   414,   631,   632,   413,   414,  1192,   597,   631,   632,
    2245,   484,  1778,   245,  1954,  1553,   413,   414,  1955,   699,
    1108,   264,   355,  1321,  1956,   694,  -564,   695,   409,   410,
     411,   412,   300,   300,   213,   377,   517,   265,   631,   632,
     631,   632,   631,   632,   413,   414,   386,   300,   413,   414,
     267,  1424,   300,   300,  1957,   697,  2082,   698,  2085,   266,
     300,   631,   632,   269,   406,   739,   339,   741,   742,   743,
     744,   745,   746,   747,   258,   749,   750,  2088,   752,   753,
     754,  1111,   756,  1240,   270,   300,   300,   763,   764,   765,
     766,   767,   631,   632,   413,   414,   925,   928,   931,   934,
     315,   485,   485,   316,  -567,   317,  1310,   348,  2097,   349,
    1315,   491,   492,   493,   494,   495,   496,   497,   498,   499,
     500,   501,   502,   503,   504,   819,   592,   631,   632,   505,
     820,   275,   300,   300,   300,    61,    62,    63,    64,   631,
     632,   413,   414,  2098,   824,  2115,  2116,   271,   340,   825,
      75,  -565,   341,    78,   302,  2099,   300,   483,   342,   343,
     303,   344,   345,   304,   827,   631,   632,   631,   632,   828,
     518,   518,   631,   632,   581,   310,   300,   582,   518,   346,
     583,  2100,   584,  2101,   320,  1093,  2012,  2013,  2169,  1099,
     528,   885,  2010,  1254,   491,   492,   493,   494,   495,   496,
     497,   498,   499,   500,   501,   502,   503,   504,   325,   518,
    1255,   873,   505,   874,  1518,   631,   632,   875,  1256,  1257,
    1258,   518,   631,   632,  1259,  1260,  1133,   873,  2021,   874,
    2024,  2170,  2027,   910,  1254,   841,  1488,   842,  2186,  1488,
     300,   817,  1488,   818,   300,  1254,   321,   631,   632,   333,
     213,  1255,   347,   631,   632,  1359,   565,  1254,   566,  1256,
    1257,  1258,  1255,  2232,   350,  1259,  1260,  1100,   377,  2233,
    1256,  1257,  1258,   873,  1255,   874,  1259,  1260,  1053,   360,
     413,   414,  1256,  1257,  1258,   351,  1070,   300,  1259,  1260,
    -569,   828,   300,   359,   873,   517,   874,   382,   239,  1081,
     517,   239,   821,   239,   822,  1693,   363,   300,   300,  1114,
     364,   406,  1115,  1452,  1116,  1454,   873,  1456,   874,  1458,
     873,  1083,   874,  1133,  1254,   841,  1156,   491,   492,   493,
     494,   495,   496,   497,   498,   499,   500,   501,   593,   503,
     504,  1255,   300,   518,   300,   505,  2083,   300,  1385,  1256,
    1257,  1258,   365,   841,  1837,  1259,  1260,  2086,   370,  1488,
     300,   383,   300,   873,   300,   874,   300,   371,  1553,  2089,
     631,   632,   300,  1388,   372,  1565,  1566,   300,   841,  1860,
    1569,  1570,   873,  2144,   874,   384,   300,  1557,   518,   518,
     518,   518,   518,   518,   518,   518,   518,   518,   373,   518,
     518,   380,   518,   518,   518,   518,   518,   592,   760,   381,
     300,   518,   518,   518,   518,   518,   768,  1254,   770,  1488,
     330,   332,  1488,   338,   841,  1488,   847,   387,  1488,  1311,
     502,   503,   504,  1316,  1255,   397,  2179,   505,  1572,  1320,
    1322,  1897,  1256,  1257,  1258,   841,  1898,   852,  1259,  1260,
    1147,  1254,   841,   403,   866,  1151,   841,   445,   903,  1590,
    2204,   841,  2207,   914,  2210,  1013,   446,  1014,  1255,  1488,
    2213,  1488,   873,  1488,   874,   447,  1256,  1257,  1258,   841,
     300,  1118,  1259,  1260,   300,   841,   452,  1207,   300,   841,
     841,  1236,  1237,   841,   459,  1282,   517,   496,   497,   498,
     499,   500,   501,   502,   503,   504,   841,  1577,  1283,   841,
     505,  1284,   882,   464,   841,   518,  1298,   465,   466,   841,
     300,  1318,  1824,  1825,  2254,   517,  2256,   467,  2258,  2234,
     300,   517,   517,   517,   472,   500,   501,   502,   503,   504,
     470,   471,  1379,  1380,   505,  1398,   517,  1399,   517,   494,
     495,   496,   497,   498,   499,   500,   501,   502,   503,   504,
    1724,  1725,   507,  2236,   505,  1728,  1729,  1404,   841,  1405,
    1425,  1812,   239,  1813,   488,   300,   300,   300,   300,   489,
     491,   492,   493,   494,   495,   496,   497,   498,   499,   500,
     501,   502,   503,   504,   592,   506,  1320,  1322,   505,   841,
     841,  1426,  1427,   512,   841,   517,  1435,  1861,   491,   492,
     493,   494,   495,   496,   497,   498,   499,   500,   501,   593,
     503,   504,  1379,  1380,   816,  1731,   505,   213,   300,   300,
     841,   300,  1436,   300,   300,   841,   300,  1437,   300,   300,
     300,   300,   300,   300,   300,   300,   300,   841,   406,  1438,
     300,  1323,   841,   841,  1441,  1442,   841,   526,  1465,  1719,
    1579,  1720,  1580,   841,   841,  1581,  1582,   841,   841,  1583,
    1584,   514,   137,  1254,   841,   300,  1638,   841,   536,  1653,
    1329,   300,   300,   626,   627,   541,  1332,  1333,  1334,   555,
    1255,   635,  1767,   580,  1768,   643,   600,   556,  1256,  1257,
    1258,  1339,   399,  1340,  1259,  1260,   841,  1903,  1853,  1904,
     601,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     841,   841,  1929,  1930,   177,   178,   179,   180,  1767,  1753,
    1951,   607,   182,   183,   184,   608,  1767,   185,  2000,   609,
     610,  1254,   300,  2029,   841,  2030,  2044,   611,   618,   190,
     191,  2048,   828,  2049,  2052,   300,   300,   300,  1255,   621,
    1384,  1573,  1767,  1553,  2057,  2059,  1256,  1257,  1258,   624,
     625,   300,  1259,  1260,   518,   636,  1557,  1149,  2060,   518,
    1152,  2016,  1154,   637,  1767,  2238,  2070,   841,   841,  2078,
    2096,  1903,  1553,  2156,  2161,   491,   492,   493,   494,   495,
     496,   497,   498,   499,   500,   501,   840,   503,   504,   517,
     517,   638,   647,   505,   517,   517,  1553,   841,  2162,  2182,
     648,   841,   649,  2183,   239,   661,  1077,   491,   492,   493,
     494,   495,   496,   497,   498,   499,   500,   501,   502,   503,
     504,   663,   841,   300,  2184,   505,   841,   841,  2185,  2187,
    1767,   650,  2194,  2240,   651,   194,   195,   196,   841,  2242,
    2241,  2243,  1767,  2274,  2264,  2275,   652,   653,   203,   300,
     204,   109,   658,   664,   674,   300,  1254,   665,  1605,   675,
     533,   666,   667,   670,   671,   538,   672,   681,   682,   300,
     543,   687,   688,  1255,   689,   690,   873,   692,   874,   708,
     709,  1256,  1257,  1258,   712,   557,   713,  1259,  1260,  1254,
     505,   782,   300,   300,   300,   783,  1978,   212,   300,   300,
     785,   300,   814,   300,   823,   300,  1255,   300,   300,   300,
     834,   836,   837,   838,  1256,  1257,  1258,   599,   859,   863,
    1259,  1260,   867,   868,   869,   887,   870,   300,   918,   889,
    1732,  1254,   890,   919,   891,   936,   938,   940,   300,   944,
     945,   946,   975,   977,   996,   978,   300,   980,  1255,   300,
     987,   988,   999,  1008,  1012,   518,  1256,  1257,  1258,  1025,
    1026,  1058,  1259,  1260,  1061,  1056,  1057,  1063,  2271,   952,
     953,  1075,  1064,  1065,   517,   517,  1078,   627,  1079,   517,
     517,  1080,  1085,  1086,   518,  1102,  1087,  1088,  1103,  1718,
     518,   518,   518,   517,  1089,  1094,  1095,  1112,  1143,   517,
    1146,  2272,  1148,     7,     8,   518,  1150,   518,  1153,   491,
     492,   493,   494,   495,   496,   497,   498,   499,   500,   501,
     502,   503,   504,  1979,  1157,  1161,   239,   505,  1160,  1162,
    1732,   377,  1164,  1165,  1166,  1167,  1169,   300,  1356,  1746,
    1170,  1171,  1172,  2273,  1173,  1174,  1175,   517,  1176,  1177,
     300,   493,   494,   495,   496,   497,   498,   499,   500,   501,
     502,   503,   504,  1178,   518,  1179,  2032,   505,  1183,  1184,
    1189,  1775,  1197,  1191,  1199,  1208,  1214,   786,    25,    26,
     787,    28,    29,   788,    31,   789,    33,    34,    35,    36,
    1200,  1221,  1201,    38,    39,    40,  1223,  1215,    42,   558,
     559,   560,  1225,   795,   790,    49,  1227,  1239,    51,   791,
    1226,    54,    55,   792,   300,   300,  1228,  1230,  1229,  1231,
    1232,  1246,  1253,   485,   485,  1275,  1277,  1247,  1288,  1289,
    1290,    72,  1291,  1300,   604,   605,   606,  1303,  1306,  1819,
    1304,  1307,  1308,   300,  1312,  1313,  1336,  1344,  1733,   300,
    1346,  1349,  1354,  1355,  1735,    86,    87,    88,   300,  2050,
     592,  1357,  1358,  2105,  1361,  1378,  1410,  1367,   300,  1393,
    1368,  1376,  1383,  1402,  1369,   655,   656,   657,   300,  1408,
    1421,  1422,  1445,   300,  1370,  1865,  1374,  1375,   668,   669,
    1446,  1447,  1450,  1476,  1451,  1460,  1461,  1420,  1482,  1462,
     901,  1463,  1772,  1464,  1882,  1466,  1885,  1886,  1477,  1480,
    1491,  1481,  2145,  1492,   300,  1493,  1501,  1502,  1494,  1495,
    1496,  1497,  1498,  1499,  1503,  1504,  1505,   983,  1506,  1507,
    1508,  1509,   941,   942,  1514,  1519,  1520,  1521,  1526,  1522,
     300,   491,   492,   493,   494,   495,   496,   497,   498,   499,
     500,   501,   502,   503,   504,  1524,  1529,  1531,  1534,   505,
    1536,  1538,  1539,  1540,  1546,  1549,  1575,  1552,   518,   518,
    1598,  1601,  1574,   518,   518,  1561,  1556,  1591,  1609,   984,
     985,   986,  1596,   377,  1597,   300,  1606,  1243,  1610,  1612,
    1607,  1618,  1621,  1614,  1249,  1613,  1619,   300,  1622,  1620,
    1624,  1263,  1626,  1004,  1627,  1628,  1629,  1630,  1631,  1632,
     300,  1633,  1634,  1635,  1636,  1639,  1642,  1641,  1650,  1652,
    1657,  1658,  1684,  1024,  1669,  1689,  1667,   300,  1668,  1675,
     517,  1676,  1690,  1704,  1966,  1709,  1710,  1683,  1696,  1697,
     239,  1698,  1699,  1700,  1701,  1706,  1711,  1715,  1721,   300,
    1722,  1736,  1740,  1788,  1743,  1748,   300,   300,  1749,  1523,
    1771,   491,   492,   493,   494,   495,   496,   497,   498,   499,
     500,   501,   840,   503,   504,   300,  1751,  1754,   300,   505,
    1755,  1756,   485,  1757,  1793,  1776,  1777,  1782,  1783,  1784,
    1787,  1789,  1791,  1877,  1792,   300,  1801,  1802,  1804,   300,
     491,   492,   493,   494,   495,   496,   497,   498,   499,   500,
     501,   502,   503,   504,  1806,  1807,  1808,  1809,   505,   491,
     492,   493,   494,   495,   496,   497,   498,   499,   500,   501,
     502,   503,   504,  1810,  1139,  1811,  1814,   505,  1827,  1144,
    1830,  1833,  1842,  1838,  1843,  1852,  1856,  1870,  1873,  1887,
    1888,  1866,  1889,   518,   518,  1890,  1891,   300,   518,   518,
    1893,  1894,  1896,  1902,  1905,  1895,  1917,  1948,  1927,  1909,
    1910,  1915,   518,  1928,  1933,  1934,   300,  1936,   518,  1937,
    1939,  1941,  1943,  1946,  1949,  1958,  1965,  1960,  1970,  1187,
    1971,  1188,  1967,  1972,  1190,  1397,  1968,  1969,   239,   215,
    1973,  1974,  1980,  1987,  1993,   377,  1994,  1202,  1995,  1203,
    1996,  1204,  1998,  1205,  1999,  2028,  2034,  1448,  2107,  1210,
    2045,  2047,  2046,  2051,  1213,  2053,   518,  2074,  2054,  2064,
    2071,  2075,  2077,  2079,  2091,  2103,  2092,  2104,  2123,  2095,
    2128,  2130,  2133,  2134,   300,   300,   300,   300,   300,  2137,
    2138,  2141,  2146,  2155,  2142,  2177,  2171,  1238,  2173,  2175,
     300,  2191,   491,   492,   493,   494,   495,   496,   497,   498,
     499,   500,   501,   502,   503,   504,  2188,  2192,     7,     8,
     505,  2190,  2205,  2208,  2211,  2214,  2215,  2216,  1473,  1474,
    1475,  2217,  2219,  2220,  2224,  2225,  2235,  2237,  2239,  2244,
    2246,   395,   491,   492,   493,   494,   495,   496,   497,   498,
     499,   500,   501,   502,   503,   504,  2253,  2255,  2257,  2259,
     505,  2261,  2189,  2276,  2277,  2278,  2279,  2280,  2281,  2283,
    1600,  2109,  1990,   300,  1803,   833,   114,   124,  1616,   517,
     125,   126,  2014,   132,  1750,     0,     0,     0,     0,     0,
     921,     0,   786,    25,    26,   787,    28,    29,   788,    31,
     789,    33,    34,    35,    36,     0,     0,  1328,    38,    39,
      40,   300,     0,    42,     0,     0,     0,     0,     0,   790,
      49,     0,     0,    51,   791,     0,    54,    55,   792,   517,
       0,   517,     0,     0,     0,     0,     0,     0,   473,   474,
     475,   477,   479,     0,     0,     0,    72,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   513,     0,     0,     0,
     520,   517,  1362,  1363,  1364,  1365,     0,     0,     0,     0,
      86,    87,    88,     0,     0,     0,     0,     0,   529,   531,
     534,   535,     0,   537,   531,   539,   540,     0,   542,   531,
     544,   545,   546,   547,   548,   549,  2154,   551,   552,   553,
       0,     0,     0,     0,   531,     0,     0,     0,   491,   492,
     493,   494,   495,   496,   497,   498,   499,   500,   501,   502,
     503,   504,     0,   587,   589,   531,   505,     0,   873,     0,
     874,     0,     0,  1547,  2222,   598,   531,  1423,     0,     0,
       0,     0,  1005,     0,     0,     0,     0,     0,     0,   518,
       0,     0,   620,     0,     0,     0,     0,     0,     0,   377,
       0,   629,   630,     0,     0,     0,     0,  1692,     0,  1444,
     630,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     654,     0,     0,     0,  2260,     0,  2263,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     673,     0,     0,     0,   676,   677,   678,     0,   680,     0,
       0,     0,   683,   684,   685,     0,  2282,   686,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   700,     0,     0,     0,     0,     0,   705,   707,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   714,   715,   716,   717,   718,   719,   720,   721,   722,
     723,   724,   725,   726,   727,   728,   729,   730,   731,   732,
     733,   734,   735,   736,   737,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   751,     0,
       0,     0,  1781,     0,   757,     0,     0,   762,   491,   492,
     493,   494,   495,   496,   497,   498,   499,   500,   501,   502,
     503,   504,     0,     0,     0,     0,   505,  2108,     0,     0,
       0,   794,   531,     0,   796,   797,   798,   799,   800,   801,
     802,   803,   804,   805,   806,   807,   808,   809,   810,     0,
       0,   812,   813,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1826,     0,  1829,     0,  1832,
       0,     0,     0,   587,     0,     0,     0,     0,     0,   845,
       0,     0,     0,     0,   850,  1845,  1846,  1847,  1848,  1849,
    1851,     0,     0,     0,     0,     0,     0,     0,   864,   865,
       0,     0,     0,     0,     0,   871,   872,     0,   878,   878,
     883,   884,     0,   886,     0,     0,   888,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   878,   531,
       0,     0,     0,     0,     0,   904,   906,   908,   909,     0,
       0,     0,     0,   915,   916,   917,     0,     0,     0,     0,
     922,   924,   927,   930,   933,   935,     0,   937,     0,   939,
       0,   531,   531,     0,     0,     0,  1705,     0,   518,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   957,
     958,   959,   473,   474,   960,     7,     8,     0,   965,   966,
     967,   968,   969,   970,   971,   972,   973,     0,     0,     0,
       0,   979,     0,   981,   982,     0,     0,     0,   531,   531,
     531,     0,     0,   989,   990,   991,     0,     0,   518,     0,
     518,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   531,     0,     0,     0,     0,   871,   872,     0,
     908,   909,     0,     0,     0,     0,     0,     0,     0,     0,
     518,  1023,   531,     0,     0,     0,  1027,     0,     0,   786,
      25,    26,   787,    28,    29,   788,    31,   789,    33,    34,
      35,    36,     0,     0,     0,    38,    39,    40,     0,     0,
      42,     0,     0,     0,     0,     0,   790,    49,     0,     0,
      51,   791,     0,    54,    55,   792,     0,     0,  1567,     0,
       0,  1073,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    72,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1101,     0,     0,  2020,     0,  2023,     0,
    2026,  1815,  1816,     0,     0,     0,     0,    86,    87,    88,
       0,  2036,  2037,  2038,  2039,  2040,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1576,     0,     0,     0,
    1134,  1135,     0,   531,  1140,  1141,     0,     0,   531,  1145,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1155,     0,     0,   906,  1158,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2072,     0,     0,
       0,  2076,     0,     0,     0,     0,  1180,     0,     0,  1006,
       0,     0,     0,     0,     0,     0,     0,     0,   531,     0,
     531,     0,     0,   531,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   531,     0,   531,     0,
     531,     0,   531,     0,     0,     0,     0,     0,   531,     0,
       0,     0,     0,   531,     0,     0,   298,     0,     0,  2124,
       0,  1219,     0,  2126,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1685,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   531,     0,     0,  2151,
       0,     0,     0,  1244,  1245,  1726,     0,     0,     0,  1248,
       0,   491,   492,   493,   494,   495,   496,   497,   498,   499,
     500,   501,   502,   503,   504,     0,     0,     0,  1276,   505,
       0,  1278,     0,     0,     0,     0,     0,  1963,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1292,     0,  1294,  1295,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1302,     0,     0,     0,  2202,  2203,   491,
     492,   493,   494,   495,   496,   497,   498,   499,   500,   501,
     502,   503,   504,  1730,     0,     0,     0,   505,     0,     0,
       0,     0,     0,     0,  1324,     0,     0,     0,     0,     0,
       0,     0,  1325,  1326,  1327,  2015,   531,     0,     0,     0,
       0,     0,     0,     0,  1330,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2035,     0,     0,     0,
       0,  1338,     0,     0,     0,     0,  1341,     0,  1855,     0,
       0,     0,     0,     0,     0,  1345,     0,     0,     0,     0,
       0,  1353,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   531,   531,   531,   531,  1366,     0,     0,     0,     0,
       0,     0,  1372,     0,     0,     0,     0,  1892,     0,     0,
       0,     0,     0,     0,     0,   554,     0,   491,   492,   493,
     494,   495,   496,   497,   498,   499,   500,   501,   502,   503,
     504,     0,     0,     0,   298,   505,  1394,     0,   491,   492,
     493,   494,   495,   496,   497,   498,   499,   500,   501,   502,
     503,   504,     0,     0,   603,     0,   505,     0,     0,     0,
       0,     0,     0,   613,   615,   617,   531,     0,     0,   622,
       0,     0,     0,     0,     0,     0,  1428,  1429,     0,  1430,
    1431,     0,  1432,  1433,  1434,     0,     0,     0,     0,     0,
       0,     0,  1440,     0,     0,     0,     0,     0,   531,     0,
       0,  2147,  2148,  2149,  2150,  2152,     0,     0,     0,  1453,
       0,  1455,     0,  1457,     0,  1459,   491,   492,   493,   494,
     495,   496,   497,   498,   499,   500,   501,   502,   503,   504,
       0,     0,     0,     0,   505,     0,     0,     0,  1479,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   702,
     703,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   711,     0,     0,     0,     0,     0,     0,
    1510,   491,   492,   493,   494,   495,   496,   497,   498,   499,
     500,   501,   502,   503,   504,     0,     0,     0,     0,   505,
    2218,     0,     0,  1530,     0,     0,     0,     0,  1535,   532,
     748,  1932,     0,     0,   532,     0,     0,     0,     0,   532,
     491,   492,   493,   494,   495,   496,   497,   498,   499,   500,
     501,   502,   503,   504,   532,     0,     0,     0,   505,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1578,     0,   588,     0,   532,     0,     0,     0,     0,
    1586,  1587,  1588,  1589,     0,     0,   532,  1592,  1593,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   135,
     394,     0,  1602,  1604,     0,   138,   139,   140,     0,     0,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,     0,     0,   491,   492,   493,   494,   495,
     496,   497,   498,   499,   500,   501,   502,   503,   504,   173,
     174,   175,   176,   505,     0,     0,     0,   181,   603,     0,
    1822,     0,  1823,     0,     0,     0,     0,     0,   186,   187,
     188,     0,     0,     0,     0,     0,   189,    21,     0,     0,
       0,  1672,  1673,  1674,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1686,     0,  1688,     0,     0,     0,     0,
       0,     0,  1691,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   531,     0,     0,     0,     0,
    1707,     0,     0,     0,     0,     0,     0,     0,  1712,  1713,
    1714,  1964,     0,     0,   491,   492,   493,   494,   495,   496,
     497,   498,   499,   500,   501,   502,   503,   504,     0,     0,
    2102,     0,   505,     0,     0,     0,     0,     0,     0,     0,
    1734,     0,     0,     0,     0,     0,     0,     0,     0,  1737,
       0,     0,   532,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   193,     0,  1747,     0,   197,     0,     0,
       0,     0,   198,   199,   200,   201,   202,  2178,     0,     0,
     109,     0,     0,     0,  1764,     0,     0,     0,     0,  1770,
       0,     0,     0,   588,   205,   206,     0,     0,  1000,   207,
       0,     0,     0,     0,   367,  1779,  1780,     0,     0,   211,
       0,   619,  1785,  1786,     0,     0,     0,  1119,     0,  1790,
       0,     0,     0,     0,     0,     0,     0,     0,   879,   881,
       0,  1090,     0,     0,     0,  1096,  1794,  1795,  1796,  1797,
    1798,  1799,  1800,     0,     0,     0,     0,     0,   900,   532,
    1805,     0,     0,     0,     0,     0,   907,     0,     0,     0,
     531,   531,  1817,     0,  1818,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1835,  1836,     0,     0,
       0,   532,   532,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   531,     0,     0,     0,  1854,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1864,     0,     0,     0,   491,   492,   493,   494,   495,   496,
     497,   498,   499,   500,   501,   502,   503,   504,   532,   532,
     532,  1884,   505,   491,   492,   493,   494,   495,   496,   497,
     498,   499,   500,   501,   502,   503,   504,     0,     0,     0,
       0,   505,   532,     0,     0,     0,     0,     0,  1899,  1900,
       0,     0,     0,     0,     0,     0,  1906,     0,     0,     0,
       0,     0,   532,     0,     0,     0,     0,  1220,     0,     0,
     491,   492,   493,   494,   495,   496,   497,   498,   499,   500,
     501,   502,   503,   504,  1926,     0,     0,     0,   505,   491,
     492,   493,   494,   495,   496,   497,   498,   499,   500,   501,
     502,   503,   504,     0,     0,  1935,     0,   505,   491,   492,
     493,   494,   495,   496,   497,   498,   499,   500,   501,   502,
     503,   504,     0,     0,  1950,     0,   505,     0,     0,     0,
       0,     0,     0,   587,     0,     0,     0,     0,     0,     0,
       0,  1961,     0,  1962,     0,     0,   531,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1305,     0,  1976,     0,  1309,     0,     0,     0,  1314,
       0,     0,     0,   532,     0,     0,     0,     0,   532,     0,
       0,  1982,     0,     0,     0,     0,  1986,     0,     0,     0,
       0,     0,     0,   907,  1159,     0,     0,     0,  1997,     0,
       0,     0,     0,     0,  2001,  2002,  2003,  2004,  2005,     0,
       0,  1331,     0,     0,   531,     0,     0,     0,     0,     0,
       0,  2019,     0,  2022,     0,  2025,     0,     0,   532,     0,
     532,     0,     0,   532,     0,   531,     0,     0,     0,     0,
       0,     0,     0,  2041,     0,     0,   532,     0,   532,     0,
     532,     0,   532,     0,     0,     0,     0,     0,   532,     0,
       0,     0,     0,   532,     0,     0,  2055,  2056,     0,     0,
       0,  2058,   491,   492,   493,   494,   495,   496,   497,   498,
     499,   500,   501,   502,   503,   504,     0,     0,     0,     0,
     505,     0,     0,     0,     0,     0,   532,  1858,     0,  1859,
    2080,     0,     0,     0,     0,     0,     0,     0,     0,  1400,
    1401,     0,  1403,     0,  1406,  1407,     0,  1409,     0,  1411,
    1412,  1413,  1414,  1415,  1416,  1417,  1418,  1419,     0,     0,
       0,  2106,     0,     0,     0,     0,     0,  1770,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2117,  2118,  2119,
    2120,  2121,  2122,     0,     0,     0,  1439,     0,     0,     0,
       0,     0,  1443,     0,     0,  2132,     0,     0,  2136,     0,
    1209,  2140,     0,     0,     0,  2143,     0,     0,     0,     0,
     531,   531,   531,   531,   531,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2158,     0,     0,  2160,     0,     7,
       8,     0,     0,     0,     0,     0,   532,   491,   492,   493,
     494,   495,   496,   497,   498,   499,   500,   501,   502,   503,
     504,     0,     0,  1500,     0,   505,     0,     0,     0,     0,
       0,     0,  2017,     0,  2018,     0,  1511,  1512,  1513,     0,
       0,     0,     0,     0,     0,     0,  2196,  2197,  2198,  2199,
    2200,  2201,  1525,     0,     0,     0,     0,     0,     0,     0,
       0,   532,   532,   532,   532,     0,     0,     0,     0,   531,
       0,     0,     0,   786,    25,    26,   787,    28,    29,   788,
      31,   789,    33,    34,    35,    36,     0,     0,     0,    38,
      39,    40,     0,     0,    42,     0,     0,     0,     0,     0,
     790,    49,     0,     0,    51,   791,  1516,    54,    55,   792,
       0,  2247,  2248,  2249,  2250,  2251,  2252,     0,     0,     0,
       0,     0,     0,     0,  1595,     0,     0,    72,     0,     0,
       0,     0,     0,     0,   911,     0,   532,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1617,    86,    87,    88,     0,     0,  1623,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   532,     0,
    1637,   491,   492,   493,   494,   495,   496,   497,   498,   499,
     500,   501,   502,   503,   504,     0,     0,     0,     0,   505,
       0,     0,     0,  1654,  1655,  1656,     0,     0,     0,  1659,
    1660,     0,  1661,     0,  1662,     0,  1663,     0,  1664,  1665,
    1666,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1241,     0,     0,     0,     0,  1687,     0,
       0,     0,     0,     0,   243,   244,     0,     0,     0,  1695,
       0,     0,     0,     0,     0,     0,     0,  1703,     0,     0,
       0,     0,     0,     0,  1030,  1031,  1032,  1033,  1034,  1035,
    1036,  1037,  1038,  1039,  1040,     0,  1042,  1043,  1044,  1045,
    1046,  1047,  1048,     0,     0,     0,  1052,  1054,  1055,     0,
       0,     0,  1059,  1060,     0,  1062,     0,     0,     0,     0,
    1067,  1068,  1069,     0,  1071,     0,     0,  1074,     0,     0,
       0,     0,     0,     0,  1082,  1084,     0,   491,   492,   493,
     494,   495,   496,   497,   498,   499,   500,   501,   502,   503,
     504,     0,  1107,     0,     0,   505,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1762,     0,
       0,     0,     0,     0,     0,   407,     0,     0,     0,     0,
       0,  1774,     0,     0,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,   439,   440,   441,   442,   443,   444,     0,
       0,     0,   448,   449,   450,   451,     0,   453,   454,   455,
     456,   457,   458,     0,     0,   460,     0,     0,     0,     0,
       0,   461,   462,   463,     0,     0,     0,     0,   468,   469,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1195,   491,   492,   493,   494,   495,   496,
     497,   498,   499,   500,   501,   502,   503,   504,  1206,     0,
       0,     0,   505,     0,  1595,     0,     0,     0,     0,     0,
       0,  1117,     0,     0,     0,   532,     0,     0,     0,  1857,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1869,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1876,
       0,     0,     0,     0,  1881,     0,     0,     0,   564,     0,
     567,   568,   569,   570,     0,     0,     0,     0,     0,     0,
       0,   585,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   596,     0,     0,  1901,   491,   492,   493,   494,
     495,   496,   497,   498,   499,   500,   501,   502,   503,   504,
       0,     0,     0,     0,   505,     0,     0,     0,     0,     0,
       0,  1595,     0,  1182,     0,     0,   135,   136,   137,     0,
       0,     0,   138,   139,   140,     0,     0,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
       0,     0,     0,     0,     0,     0,  1947,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,     0,     0,     0,   182,   183,
     184,     0,     0,   185,     0,   186,   187,   188,     0,     0,
     532,   532,     0,   189,    21,   190,   191,   137,     0,     0,
       0,     0,     0,   491,   492,   493,   494,   495,   496,   497,
     498,   499,   500,   501,   502,   503,   504,     0,     0,     0,
    1595,   505,     0,     0,     0,   532,  1371,  1991,  1992,     0,
    1198,     0,     0,     0,     0,     0,   164,   165,   166,   167,
     168,   169,   170,   171,   172,     0,  1595,     0,     0,   177,
     178,   179,   180,     0,     0,     0,     0,   182,   183,   184,
       0,     0,   185,  1395,  1396,   784,  2031,     0,     0,     0,
       0,     0,     0,     0,   190,   191,     0,     0,   491,   492,
     493,   494,   495,   496,   497,   498,   499,   500,   501,   502,
     503,   504,     0,   192,     0,     0,   505,     0,     0,     0,
     193,   194,   195,   196,   197,  1267,     0,     0,     0,   198,
     199,   200,   201,   202,   203,     0,   204,   109,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2073,     0,
       0,   205,   206,     0,     0,     0,   207,     0,     0,     0,
       0,   208,     0,   209,     0,   210,   211,  2090,   212,     0,
     213,   491,   492,   493,   494,   495,   496,   497,   498,   499,
     500,   501,   502,   503,   504,     0,     0,     0,     0,   505,
       0,     0,     0,   588,     0,     0,     0,     0,  1317,     0,
     194,   195,   196,     0,     0,     0,   532,     0,     0,     0,
       0,     0,     0,   203,     0,   204,     0,     0,     0,     0,
       0,     0,     0,  1977,     0,     0,     0,     0,     0,     0,
     491,   492,   493,   494,   495,   496,   497,   498,   499,   500,
     501,   502,   503,   504,     0,     0,  1537,     0,   505,     0,
       0,  1595,  1541,  1542,  1543,  1544,  1545,  1471,  1548,     0,
    1550,  1551,     0,  1554,     0,  1558,     0,     0,  1562,  1563,
    1564,     0,     0,     0,   532,  1568,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   135,   276,     0,     0,
       0,     0,   138,   139,   140,   532,     0,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     277,   278,   279,   280,   281,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   173,   174,   175,   176,
       0,     0,     0,     0,   181,     0,     0,     0,     0,     0,
       0,     0,     0,  1640,     0,   186,   187,   188,     0,     0,
       0,     0,  1595,   189,    21,     0,     0,     0,     0,   282,
    1651,     0,   283,     0,     0,   284,     0,   285,     0,     0,
       0,     0,     0,     0,    37,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   286,     0,    50,     0,
       0,   287,     0,     0,   288,     0,     0,     0,     0,     0,
       0,    61,    62,    63,    64,    65,     0,     0,    67,    68,
      69,    70,    71,     0,     0,     0,    75,     0,     0,    78,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     532,   532,   532,   532,   532,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1723,     0,     0,     0,     0,
    1727,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     193,     0,     0,     0,   197,   289,     0,     0,     0,   198,
     199,   200,   201,   202,     0,     0,     0,   109,     0,     0,
       0,     0,     0,  1741,  1742,     0,     0,  1744,  1745,     0,
       0,   639,  1850,     0,     0,     0,   207,     0,     0,     0,
       0,   641,     0,     0,     0,     0,   211,     0,   329,   590,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   532,
       0,     0,     0,   491,   492,   493,   494,   495,   496,   497,
     498,   499,   500,   501,   502,   503,   504,     0,     0,   135,
     276,   505,     0,     0,     0,   138,   139,   140,     0,   696,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   277,   278,   279,   280,   281,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   173,
     174,   175,   176,     0,     0,     0,     0,   181,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   186,   187,
     188,     0,     0,     0,     0,     0,   189,    21,     0,     0,
       0,     0,   282,     0,     0,   283,     0,     0,   284,     0,
     285,     0,     0,     0,     0,     0,     0,    37,     0,     0,
       0,     0,  1871,  1872,     0,     0,  1874,  1875,     0,   286,
       0,    50,  1878,  1879,   287,     0,     0,   288,     0,     0,
       0,     0,     0,     0,    61,    62,    63,    64,    65,     0,
       0,    67,    68,    69,    70,    71,     0,     0,     0,    75,
    1342,  1343,    78,     0,     0,     0,  1347,  1348,   491,   492,
     493,   494,   495,   496,   497,   498,   499,   500,   501,   502,
     503,   504,     0,     0,     0,     0,   505,     0,     0,     0,
       0,     0,  1919,  1920,     0,  1820,     0,     0,     0,     0,
       0,     0,     0,   193,     0,     0,     0,   197,   289,     0,
       0,     0,   198,   199,   200,   201,   202,     0,     0,     0,
     109,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   205,   530,     0,     0,     0,   207,
       0,     0,     0,     0,   367,     0,     0,     0,     0,   211,
       0,     0,   590,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   135,   276,   137,     0,     0,     0,   138,
     139,   140,     0,     0,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   277,   278,   279,
     280,   281,     0,     0,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,     0,     0,     0,   182,   183,   184,     0,     0,
     185,     0,   186,   187,   188,     0,     0,     0,     0,     0,
     189,    21,   190,   191,     0,     0,   282,     0,     0,   283,
       0,     0,   284,     0,   285,     0,     0,     0,     0,     0,
       0,    37,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   286,     0,    50,     0,     0,   287,  1527,
    1528,   288,     0,     0,  1532,  1533,     0,     0,    61,    62,
      63,    64,    65,     0,     0,    67,    68,    69,    70,    71,
       0,     0,     0,    75,     0,     0,    78,   491,   492,   493,
     494,   495,   496,   497,   498,   499,   500,   501,   502,   503,
     504,     0,     0,     0,     0,   505,     0,     0,     0,     0,
       0,     0,     0,     0,  1840,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   193,   194,   195,
     196,   197,   289,     0,     0,     0,   198,   199,   200,   201,
     202,   203,     0,   204,   109,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   205,   290,
       0,     0,     0,   207,     0,     0,     0,     0,   367,     0,
     135,   276,   137,   211,     0,   292,   138,   139,   140,     0,
       0,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   277,   278,   279,   280,   281,     0,
       0,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,     0,
       0,     0,   182,   183,   184,     0,     0,   185,     0,   186,
     187,   188,     0,     0,     0,     0,     0,   189,    21,   190,
     191,     0,     0,   282,     0,     0,   283,     0,     0,   284,
       0,   285,     0,     0,     0,     0,     0,     0,    37,     0,
       0,     0,     0,     0,     0,  2227,     0,     0,     0,     0,
     286,     0,    50,     0,     0,   287,     0,     0,   288,     0,
       0,     0,     0,     0,     0,    61,    62,    63,    64,    65,
       0,     0,    67,    68,    69,    70,    71,     0,     0,     0,
      75,     0,     0,    78,   491,   492,   493,   494,   495,   496,
     497,   498,   499,   500,   501,   502,   503,   504,     0,     0,
       0,     0,   505,     0,     0,     0,     0,     0,     0,     0,
       0,  1911,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   193,   194,   195,   196,   197,   289,
       0,     0,     0,   198,   199,   200,   201,   202,   203,     0,
     204,   109,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   205,   290,     0,     0,     0,
     207,     0,     0,     0,     0,   367,     0,   135,   276,   366,
     211,     0,  1880,   138,   139,   140,     0,     0,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   277,   278,   279,   280,   281,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   173,   174,   175,
     176,     0,     0,     0,     0,   181,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   186,   187,   188,     0,
       0,     0,     0,     0,   189,    21,     0,     0,     0,     0,
     282,     0,     0,   283,     0,     0,   284,     0,   285,     0,
       0,     0,     0,     0,     0,    37,     0,     0,     0,     0,
       0,   388,   137,     0,     0,     0,     0,   286,     0,    50,
       0,     0,   287,     0,     0,   288,     0,     0,     0,     0,
       0,     0,    61,    62,    63,    64,    65,     0,     0,    67,
      68,    69,    70,    71,     0,     0,     0,    75,     0,     0,
      78,   164,   165,   166,   167,   168,   169,   170,   171,   172,
       0,     0,     0,     0,   177,   178,   179,   180,     0,     0,
       0,     0,   182,   183,   184,     0,     0,   185,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   190,
     191,   193,     0,     0,     0,   197,   289,     0,     0,     0,
     198,   199,   200,   201,   202,     0,     0,     0,   109,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   205,   290,     0,     0,     0,   207,     0,     0,
       0,     0,   367,     0,   135,   276,  1694,   211,     0,   292,
     138,   139,   140,     0,     0,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   277,   278,
     279,   280,   281,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   173,   174,   175,   176,     0,     0,
       0,     0,   181,     0,     0,   194,   195,   196,     0,     0,
       0,     0,     0,   186,   187,   188,     0,     0,   203,     0,
     204,   189,    21,     0,     0,     0,     0,   282,     0,     0,
     283,     0,     0,   284,     0,   285,     0,     0,     0,     0,
       0,     0,    37,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   286,     0,    50,     0,     0,   287,
       0,     0,   288,     0,     0,     0,     0,     0,     0,    61,
      62,    63,    64,    65,     0,     0,    67,    68,    69,    70,
      71,     0,     0,     0,    75,     0,     0,    78,   491,   492,
     493,   494,   495,   496,   497,   498,   499,   500,   501,   502,
     503,   504,     0,     0,     0,     0,   505,     0,     0,     0,
       0,     0,     0,     0,     0,  1912,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   193,     0,
       0,     0,   197,   289,     0,     0,     0,   198,   199,   200,
     201,   202,     0,     0,     0,   109,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   205,
     290,     0,     0,     0,   207,     0,     0,     0,     0,   367,
       0,   135,   276,     0,   211,     0,   292,   138,   139,   140,
       0,     0,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   277,   278,   279,   280,   281,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   173,   174,   175,   176,     0,     0,     0,     0,   181,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     186,   187,   188,     0,     0,     0,     0,     0,   189,    21,
       0,     0,     0,     0,   282,     0,     0,   283,     0,     0,
     284,     0,   285,     0,     0,     0,     0,     0,     0,    37,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   286,     0,    50,     0,     0,   287,     0,     0,   288,
       0,     0,     0,     0,     0,     0,    61,    62,    63,    64,
      65,     0,     0,    67,    68,    69,    70,    71,     0,     0,
       0,    75,     0,     0,    78,   491,   492,   493,   494,   495,
     496,   497,   498,   499,   500,   501,   502,   503,   504,     0,
       0,     0,     0,   505,     0,     0,     0,     0,     0,     0,
       0,     0,  1913,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   193,     0,     0,     0,   197,
     289,     0,     0,     0,   198,   199,   200,   201,   202,     0,
       0,     0,   109,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   205,   290,     0,     0,
       0,   207,     0,     0,     0,     0,   291,     0,   135,   276,
       0,   211,     0,   292,   138,   139,   140,     0,     0,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   277,   278,   279,   280,   281,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   173,   174,
     175,   176,     0,     0,     0,     0,   181,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   186,   187,   188,
       0,     0,     0,     0,     0,   189,    21,     0,     0,     0,
       0,   282,     0,     0,   283,     0,     0,   284,     0,   285,
       0,     0,     0,     0,     0,     0,    37,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   286,     0,
      50,     0,     0,   287,     0,     0,   288,     0,     0,     0,
       0,     0,     0,    61,    62,    63,    64,    65,     0,     0,
      67,    68,    69,    70,    71,     0,     0,     0,    75,     0,
       0,    78,   491,   492,   493,   494,   495,   496,   497,   498,
     499,   500,   501,   502,   503,   504,     0,     0,     0,     0,
     505,     0,     0,     0,     0,     0,     0,     0,     0,  1914,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   193,     0,     0,     0,   197,   289,     0,     0,
       0,   198,   199,   200,   201,   202,     0,     0,     0,   109,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   205,   290,     0,     0,     0,   207,     0,
       0,     0,     0,   367,     0,   135,   276,     0,   211,     0,
     292,   138,   139,   140,     0,     0,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   277,
     278,   279,   280,   281,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   173,   174,   175,   176,     0,
       0,     0,     0,   181,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   186,   187,   188,     0,     0,     0,
       0,     0,   189,    21,     0,     0,     0,     0,   282,     0,
       0,   283,     0,     0,   284,     0,   285,     0,     0,     0,
       0,     0,     0,    37,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   286,     0,    50,     0,     0,
     287,     0,     0,   288,     0,     0,     0,     0,     0,     0,
      61,    62,    63,    64,    65,     0,     0,    67,    68,    69,
      70,    71,     0,     0,     0,    75,     0,     0,    78,   491,
     492,   493,   494,   495,   496,   497,   498,   499,   500,   501,
     502,   503,   504,     0,     0,     0,     0,   505,     0,     0,
       0,     0,     0,     0,     0,     0,  1916,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   193,
       0,     0,     0,   197,   289,     0,     0,     0,   198,   199,
     200,   201,   202,     0,     0,     0,   109,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     205,   530,     0,     0,     0,   207,     0,     0,     0,     0,
     367,     0,   135,   276,     0,   211,     0,   586,   138,   139,
     140,     0,     0,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   277,   278,   279,   280,
     281,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   173,   174,   175,   176,     0,     0,     0,     0,
     181,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   186,   187,   188,     0,     0,     0,     0,     0,   189,
      21,     0,     0,     0,     0,   282,     0,     0,   283,     0,
       0,   284,     0,   285,     0,     0,     0,     0,     0,     0,
      37,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   286,     0,    50,     0,     0,   287,     0,     0,
     288,     0,     0,     0,     0,     0,     0,    61,    62,    63,
      64,    65,     0,     0,    67,    68,    69,    70,    71,     0,
       0,     0,    75,     0,     0,    78,   491,   492,   493,   494,
     495,   496,   497,   498,   499,   500,   501,   502,   503,   504,
       0,     0,     0,     0,   505,     0,     0,     0,     0,     0,
       0,     0,     0,  1944,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   193,     0,     0,     0,
     197,   289,     0,     0,     0,   198,   199,   200,   201,   202,
       0,     0,     0,   109,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   205,   290,     0,
       0,     0,   207,     0,     0,     0,     0,   602,     0,   135,
     276,     0,   211,     0,   292,   138,   139,   140,     0,     0,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   277,   278,   279,   280,   281,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   173,
     174,   175,   176,     0,     0,     0,     0,   181,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   186,   187,
     188,     0,     0,     0,     0,     0,   189,    21,     0,     0,
       0,     0,   282,     0,     0,   283,     0,     0,   284,     0,
     285,     0,     0,     0,     0,     0,     0,    37,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   286,
       0,    50,     0,     0,   287,     0,     0,   288,     0,     0,
       0,     0,     0,     0,    61,    62,    63,    64,    65,     0,
       0,    67,    68,    69,    70,    71,     0,     0,     0,    75,
       0,     0,    78,   491,   492,   493,   494,   495,   496,   497,
     498,   499,   500,   501,   502,   503,   504,     0,     0,     0,
       0,   505,     0,     0,     0,     0,     0,     0,     0,     0,
    1959,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   193,     0,     0,     0,   197,   289,     0,
       0,     0,   198,   199,   200,   201,   202,     0,     0,     0,
     109,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   205,   290,     0,     0,     0,   207,
       0,     0,     0,     0,   612,     0,   135,   276,     0,   211,
       0,   292,   138,   139,   140,     0,     0,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     277,   278,   279,   280,   281,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   173,   174,   175,   176,
       0,     0,     0,     0,   181,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   186,   187,   188,     0,     0,
       0,     0,     0,   189,    21,     0,     0,     0,     0,   282,
       0,     0,   283,     0,     0,   284,     0,   285,     0,     0,
       0,     0,     0,     0,    37,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   286,     0,    50,     0,
       0,   287,     0,     0,   288,     0,     0,     0,     0,     0,
       0,    61,    62,    63,    64,    65,     0,     0,    67,    68,
      69,    70,    71,     0,     0,     0,    75,     0,     0,    78,
     491,   492,   493,   494,   495,   496,   497,   498,   499,   500,
     501,   502,   503,   504,     0,     0,     0,     0,   505,     0,
       0,     0,     0,     0,     0,     0,     0,  2006,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     193,     0,     0,     0,   197,   289,     0,     0,     0,   198,
     199,   200,   201,   202,     0,     0,     0,   109,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   205,   290,     0,     0,     0,   207,     0,     0,     0,
       0,   614,     0,   135,   276,     0,   211,     0,   292,   138,
     139,   140,     0,     0,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   277,   278,   279,
     280,   281,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   173,   174,   175,   176,     0,     0,     0,
       0,   181,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   186,   187,   188,     0,     0,     0,     0,     0,
     189,    21,     0,     0,     0,     0,   282,     0,     0,   283,
       0,     0,   284,     0,   285,     0,     0,     0,     0,     0,
       0,    37,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   286,     0,    50,     0,     0,   287,     0,
       0,   288,     0,     0,     0,     0,     0,     0,    61,    62,
      63,    64,    65,     0,     0,    67,    68,    69,    70,    71,
       0,     0,     0,    75,     0,     0,    78,   491,   492,   493,
     494,   495,   496,   497,   498,   499,   500,   501,   502,   503,
     504,     0,     0,     0,     0,   505,     0,     0,     0,     0,
       0,     0,     0,     0,  2033,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   193,     0,     0,
       0,   197,   289,     0,     0,     0,   198,   199,   200,   201,
     202,     0,     0,     0,   109,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   205,   290,
       0,     0,     0,   207,     0,     0,     0,     0,   616,     0,
     135,   276,     0,   211,     0,   292,   138,   139,   140,     0,
       0,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   277,   278,   279,   280,   281,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     173,   174,   175,   176,     0,     0,     0,     0,   181,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   186,
     187,   188,     0,     0,     0,     0,     0,   189,    21,     0,
       0,     0,     0,   282,     0,     0,   283,     0,     0,   284,
       0,   285,     0,     0,     0,     0,     0,     0,    37,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     286,     0,    50,     0,     0,   287,     0,     0,   288,     0,
       0,     0,     0,     0,     0,    61,    62,    63,    64,    65,
       0,     0,    67,    68,    69,    70,    71,     0,     0,     0,
      75,     0,     0,    78,   491,   492,   493,   494,   495,   496,
     497,   498,   499,   500,   501,   502,   503,   504,     0,     0,
       0,     0,   505,     0,     0,     0,     0,     0,     0,     0,
       0,  2042,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   193,     0,     0,     0,   197,   289,
       0,     0,     0,   198,   199,   200,   201,   202,     0,     0,
       0,   109,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   205,   530,     0,     0,     0,
     207,     0,     0,     0,     0,   367,     0,   135,   276,     0,
     211,     0,   877,   138,   139,   140,     0,     0,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   277,   278,   279,   280,   281,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   173,   174,   175,
     176,     0,     0,     0,     0,   181,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   186,   187,   188,     0,
       0,     0,     0,     0,   189,    21,     0,     0,     0,     0,
     282,     0,     0,   283,     0,     0,   284,     0,   285,     0,
       0,     0,     0,     0,     0,    37,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   286,     0,    50,
       0,     0,   287,     0,     0,   288,     0,     0,     0,     0,
       0,     0,    61,    62,    63,    64,    65,     0,     0,    67,
      68,    69,    70,    71,     0,     0,     0,    75,     0,     0,
      78,   491,   492,   493,   494,   495,   496,   497,   498,   499,
     500,   501,   502,   503,   504,     0,     0,     0,     0,   505,
       0,     0,     0,     0,     0,     0,     0,     0,  2043,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   193,     0,     0,     0,   197,   289,     0,     0,     0,
     198,   199,   200,   201,   202,     0,     0,     0,   109,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   205,   530,     0,     0,     0,   207,     0,     0,
       0,     0,   367,     0,   135,   276,     0,   211,     0,   880,
     138,   139,   140,     0,     0,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   277,   278,
     279,   280,   281,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   173,   174,   175,   176,     0,     0,
       0,     0,   181,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   186,   187,   188,     0,     0,     0,     0,
       0,   189,    21,     0,     0,     0,     0,   282,     0,     0,
     283,     0,     0,   284,     0,   285,     0,     0,     0,     0,
       0,     0,    37,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   286,     0,    50,     0,     0,   287,
       0,     0,   288,     0,     0,     0,     0,     0,     0,    61,
      62,    63,    64,    65,     0,     0,    67,    68,    69,    70,
      71,     0,     0,     0,    75,     0,     0,    78,   491,   492,
     493,   494,   495,   496,   497,   498,   499,   500,   501,   502,
     503,   504,     0,     0,     0,     0,   505,     0,     0,     0,
       0,     0,     0,     0,     0,  2063,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   193,     0,
       0,     0,   197,   289,     0,     0,     0,   198,   199,   200,
     201,   202,     0,     0,     0,   109,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   205,
     530,     0,     0,     0,   207,     0,     0,     0,     0,   367,
       0,   135,   276,     0,   211,     0,   905,   138,   139,   140,
       0,     0,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   277,   278,   279,   280,   281,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   173,   174,   175,   176,     0,     0,     0,     0,   181,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     186,   187,   188,     0,     0,     0,     0,     0,   189,    21,
       0,     0,     0,     0,   282,     0,     0,   283,     0,     0,
     284,     0,   285,     0,     0,     0,     0,     0,     0,    37,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   286,     0,    50,     0,     0,   287,     0,     0,   288,
       0,     0,     0,     0,     0,     0,    61,    62,    63,    64,
      65,     0,     0,    67,    68,    69,    70,    71,     0,     0,
       0,    75,     0,     0,    78,   491,   492,   493,   494,   495,
     496,   497,   498,   499,   500,   501,   502,   503,   504,     0,
       0,     0,     0,   505,     0,     0,     0,     0,     0,     0,
       0,     0,  2081,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   193,     0,     0,     0,   197,
     289,     0,     0,     0,   198,   199,   200,   201,   202,     0,
       0,     0,   109,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   205,   290,     0,     0,
       0,   207,     0,     0,     0,     0,   367,     0,   135,   276,
       0,   211,     0,  1702,   138,   139,   140,     0,     0,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   277,   278,   279,   280,   281,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   173,   174,
     175,   176,     0,     0,     0,     0,   181,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   186,   187,   188,
       0,     0,     0,     0,     0,   189,    21,     0,     0,     0,
       0,   282,     0,     0,   283,     0,     0,   284,     0,   285,
       0,     0,     0,     0,     0,     0,    37,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   286,     0,
      50,     0,     0,   287,     0,     0,   288,     0,     0,     0,
       0,     0,     0,    61,    62,    63,    64,    65,     0,     0,
      67,    68,    69,    70,    71,     0,     0,     0,    75,     0,
       0,    78,   491,   492,   493,   494,   495,   496,   497,   498,
     499,   500,   501,   502,   503,   504,     0,     0,     0,     0,
     505,     0,     0,     0,     0,     0,     0,     0,     0,  2084,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   193,     0,     0,     0,   197,   289,     0,     0,
       0,   198,   199,   200,   201,   202,     0,     0,     0,   109,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   639,  1850,     0,     0,     0,   207,     0,
       0,     0,     0,   641,     0,   135,   394,   137,   211,     0,
     329,   138,   139,   140,     0,     0,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,     0,
       0,     0,     0,     0,     0,     0,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,     0,     0,     0,   182,   183,   184,
       0,     0,   185,     0,   186,   187,   188,     0,     0,     0,
       0,     0,   189,    21,   190,   191,   135,   394,   137,     0,
       0,     0,   138,   139,   140,     0,     0,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
       0,     0,     0,     0,     0,     0,     0,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,     0,     0,     0,   182,   183,
     184,     0,     0,   185,     0,   186,   187,   188,     0,     0,
       0,     0,     0,   189,    21,   190,   191,   491,   492,   493,
     494,   495,   496,   497,   498,   499,   500,   501,   502,   503,
     504,     0,     0,     0,     0,   505,     0,     0,     0,   193,
     194,   195,   196,   197,  2087,     0,     0,     0,   198,   199,
     200,   201,   202,   203,     0,   204,   109,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     205,   206,     0,     0,     0,   207,     0,     0,     0,     0,
     367,     0,     0,     0,     0,   211,     0,  1603,   491,   492,
     493,   494,   495,   496,   497,   498,   499,   500,   501,   502,
     503,   504,     0,     0,     0,     0,   505,     0,     0,     0,
       0,     0,     0,     0,     0,  2129,     0,     0,     0,     0,
     193,   194,   195,   196,   197,     0,     0,     0,     0,   198,
     199,   200,   201,   202,   203,     0,   204,   109,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   205,   206,     0,     0,     0,   207,     0,     0,     0,
       0,   367,     0,   135,   394,   137,   211,     0,  1863,   138,
     139,   140,     0,     0,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,     0,     0,     0,
       0,     0,     0,     0,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,     0,     0,     0,   182,   183,   184,     0,     0,
     185,     0,   186,   187,   188,     0,     0,     0,   135,   394,
     189,    21,   190,   191,   138,   139,   140,     0,     0,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,     0,     0,   491,   492,   493,   494,   495,   496,
     497,   498,   499,   500,   501,   502,   503,   504,   173,   174,
     175,   176,   505,     0,     0,     0,   181,     0,     0,     0,
       0,  2172,     0,     0,     0,     0,     0,   186,   187,   188,
       0,     0,     0,     0,     0,   189,    21,   491,   492,   493,
     494,   495,   496,   497,   498,   499,   500,   501,   502,   503,
     504,     0,     0,     0,     0,   505,     0,     0,     0,     0,
       0,     0,     0,     0,  2174,     0,     0,   193,   194,   195,
     196,   197,     0,     0,     0,     0,   198,   199,   200,   201,
     202,   203,     0,   204,   109,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   205,   206,
       0,     0,     0,   207,     0,     0,     0,     0,   367,     0,
       0,     0,     0,   211,     0,  1883,   491,   492,   493,   494,
     495,   496,   497,   498,   499,   500,   501,   502,   503,   504,
       0,     0,     0,     0,   505,     0,     0,     0,     0,     0,
       0,     0,   193,  2176,     0,     0,   197,     0,     0,     0,
       0,   198,   199,   200,   201,   202,     0,     0,     0,   109,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   639,   640,     0,     0,     0,   207,     0,
       0,     0,     0,   641,     0,   135,   276,     0,   211,     0,
     329,   138,   139,   140,     0,     0,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   277,
     278,   279,   280,   281,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   173,   174,   175,   176,     0,
       0,     0,     0,   181,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   186,   187,   188,     0,     0,     0,
       0,     0,   189,    21,     0,     0,     0,     0,   282,     0,
       0,   283,     0,     0,   284,     0,   285,     0,     0,     0,
       0,     0,     0,    37,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   286,     0,    50,     0,     0,
     287,     0,     0,   288,     0,     0,     0,     0,     0,     0,
      61,    62,    63,    64,    65,     0,     0,    67,    68,    69,
      70,    71,     0,     0,     0,    75,     0,     0,    78,   491,
     492,   493,   494,   495,   496,   497,   498,   499,   500,   501,
     502,   503,   504,     0,     0,     0,     0,   505,     0,     0,
       0,     0,     0,     0,     0,     0,  2195,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   193,
       0,     0,     0,   197,   289,     0,     0,     0,   198,   199,
     200,   201,   202,     0,     0,     0,   109,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     205,   530,     0,     0,     0,   207,   135,   394,   137,     0,
     367,     0,   138,   139,   140,   211,     0,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
       0,     0,     0,     0,     0,     0,     0,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,     0,     0,     0,   182,   183,
     184,     0,     0,   185,     0,   186,   187,   188,     0,     0,
       0,   135,   394,   189,    21,   190,   191,   138,   139,   140,
       0,     0,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,     0,     0,   491,   492,   493,
     494,   495,   496,   497,   498,   499,   500,   501,   502,   503,
     504,   173,   174,   175,   176,   505,     0,     0,     0,   181,
       0,     0,     0,     0,  2226,     0,     0,     0,     0,     0,
     186,   187,   188,     0,     0,     0,     0,     0,   189,    21,
     491,   492,   493,   494,   495,   496,   497,   498,   499,   500,
     501,   502,   503,   504,     0,     0,     0,     0,   505,     0,
       0,     0,     0,     0,     0,     0,     0,  2265,     0,     0,
     193,   194,   195,   196,   197,     0,     0,     0,     0,   198,
     199,   200,   201,   202,   203,     0,   204,   109,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   205,   206,     0,     0,     0,   207,     0,     0,     0,
       0,   367,     0,     0,     0,     0,   211,   491,   492,   493,
     494,   495,   496,   497,   498,   499,   500,   501,   502,   503,
     504,     0,     0,     0,     0,   505,     0,     0,     0,     0,
       0,     0,     0,     0,  2266,   193,     0,     0,     0,   197,
       0,     0,     0,     0,   198,   199,   200,   201,   202,     0,
       0,     0,   109,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   205,   206,     0,     0,
       0,   207,   135,   394,     0,     0,   367,   476,   138,   139,
     140,   211,     0,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,     0,     0,   491,   492,
     493,   494,   495,   496,   497,   498,   499,   500,   501,   502,
     503,   504,   173,   174,   175,   176,   505,     0,     0,     0,
     181,     0,     0,     0,     0,  2267,     0,     0,     0,     0,
       0,   186,   187,   188,     0,   135,   394,     0,     0,   189,
      21,   138,   139,   140,     0,     0,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,     0,
       0,   491,   492,   493,   494,   495,   496,   497,   498,   499,
     500,   501,   502,   503,   504,   173,   174,   175,   176,   505,
       0,     0,     0,   181,     0,     0,     0,     0,  2268,     0,
       0,     0,     0,     0,   186,   187,   188,     0,     0,     0,
       0,     0,   189,    21,   491,   492,   493,   494,   495,   496,
     497,   498,   499,   500,   501,   502,   503,   504,     0,     0,
       0,     0,   505,     0,     0,     0,     0,     0,     0,     0,
       0,  2269,     0,     0,     0,     0,   193,     0,     0,     0,
     197,     0,     0,     0,     0,   198,   199,   200,   201,   202,
       0,     0,     0,   109,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   205,   206,     0,
       0,     0,   207,     0,     0,     0,     0,   367,     0,     0,
     478,     0,   211,   491,   492,   493,   494,   495,   496,   497,
     498,   499,   500,   501,   502,   503,   504,     0,     0,     0,
       0,   505,     0,     0,     0,     0,     0,     0,     0,   193,
    2270,     0,     0,   197,     0,     0,     0,     0,   198,   199,
     200,   201,   202,     0,     0,     0,   109,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     205,   206,     0,     0,     0,   207,   135,   394,     0,     0,
     367,   704,   138,   139,   140,   211,     0,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
       0,     0,   491,   492,   493,   494,   495,   496,   497,   498,
     499,   500,   501,   502,   503,   504,   173,   174,   175,   176,
     505,     0,     0,     0,   181,     0,     0,     0,   943,     0,
       0,     0,     0,     0,     0,   186,   187,   188,     0,   135,
     394,     0,  1301,   189,    21,   138,   139,   140,     0,     0,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,     0,     0,   491,   492,   493,   494,   495,
     496,   497,   498,   499,   500,   501,   502,   503,   504,   173,
     174,   175,   176,   505,     0,     0,     0,   181,     0,     0,
       0,  1931,     0,     0,     0,     0,     0,     0,   186,   187,
     188,     0,     0,     0,     0,     0,   189,    21,   491,   492,
     493,   494,   495,   496,   497,   498,   499,   500,   501,   502,
     503,   504,     0,     0,     0,     0,   505,     0,   992,     0,
       0,     0,     0,   950,     0,     0,     0,     0,     0,     0,
     193,     0,     0,     0,   197,     0,     0,     0,     0,   198,
     199,   200,   201,   202,     0,     0,     0,   109,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   205,   206,     0,     0,     0,   207,     0,     0,     0,
       0,   367,     0,     0,   706,     0,   211,   491,   492,   493,
     494,   495,   496,   497,   498,   499,   500,   501,   502,   503,
     504,     0,     0,     0,     0,   505,     0,     0,     0,     0,
       0,     0,   826,   193,     0,     0,     0,   197,     0,     0,
       0,     0,   198,   199,   200,   201,   202,     0,     0,     0,
     109,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   205,   206,     0,     0,     0,   207,
     135,   394,     0,  1478,   367,     0,   138,   139,   140,   211,
       0,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,     0,     0,   491,   492,   493,   494,
     495,   496,   497,   498,   499,   500,   501,   502,   503,   504,
     173,   174,   175,   176,   505,     0,     0,     0,   181,     0,
       0,   950,     0,     0,     0,     0,     0,     0,     0,   186,
     187,   188,     0,   135,   394,     0,     0,   189,    21,   138,
     139,   140,     0,     0,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,     0,     0,   491,
     492,   493,   494,   495,   496,   497,   498,   499,   500,   501,
     502,   503,   504,   173,   174,   175,   176,   505,     0,     0,
       0,   181,     0,     0,   951,     0,     0,     0,     0,     0,
       0,     0,   186,   187,   188,     0,     0,     0,     0,     0,
     189,    21,   491,   492,   493,   494,   495,   496,   497,   498,
     499,   500,   501,   502,   503,   504,     0,     0,     0,     0,
     505,     0,     0,     0,     0,     0,     0,   997,     0,     0,
       0,     0,     0,     0,   193,     0,     0,     0,   197,     0,
       0,     0,     0,   198,   199,   200,   201,   202,     0,     0,
       0,   109,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   205,   206,     0,     0,     0,
     207,     0,     0,     0,     0,   367,     0,     0,     0,     0,
     211,     7,     8,   491,   492,   493,   494,   495,   496,   497,
     498,   499,   500,   501,   502,   503,   504,     0,     0,     0,
       0,   505,     0,     0,     0,     0,     0,   193,  1041,     0,
       0,   197,     0,     0,     0,     0,   198,   199,   200,   201,
     202,     7,     8,     0,   109,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   205,   206,
       0,     0,     0,   207,     0,     0,     0,     0,   367,     0,
       0,     0,     0,   211,     0,   786,    25,    26,   787,    28,
      29,   788,    31,   789,    33,    34,    35,    36,     0,     0,
       0,    38,    39,    40,     0,     0,    42,     0,     0,     0,
       0,     0,   790,    49,     0,     0,    51,   791,     0,    54,
      55,   792,     0,     0,     0,   786,    25,    26,   787,    28,
      29,   788,    31,   789,    33,    34,    35,    36,     0,    72,
       0,    38,    39,    40,     0,     0,    42,     0,     7,     8,
       0,     0,   790,    49,     0,     0,    51,   791,     0,    54,
      55,   792,     0,    86,    87,    88,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    72,
       0,     0,     0,     0,     0,     0,     0,     7,     8,   491,
     492,   493,   494,   495,   496,   497,   498,   499,   500,   501,
     502,   503,   504,    86,    87,    88,     0,   505,     0,     0,
       0,     0,     0,     0,  1049,     0,     0,     0,     0,     0,
       0,     0,   786,    25,    26,   787,    28,    29,   788,    31,
     789,    33,    34,    35,    36,  1242,     0,     0,    38,    39,
      40,     0,     0,    42,     0,     0,     0,     0,     0,   790,
      49,     0,     0,    51,   791,     0,    54,    55,   792,     0,
       0,   786,    25,    26,   787,    28,    29,   788,    31,   789,
      33,    34,    35,    36,     0,  1264,    72,    38,    39,    40,
       0,     0,    42,     0,     7,     8,     0,     0,   790,    49,
       0,     0,    51,   791,     0,    54,    55,   792,     0,     0,
      86,    87,    88,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    72,     0,     0,     0,     0,
       0,     0,     0,     7,     8,   491,   492,   493,   494,   495,
     496,   497,   498,   499,   500,   501,   502,   503,   504,    86,
      87,    88,     0,   505,     0,     0,     0,     0,     0,     0,
    1050,     0,     0,     0,     0,     0,     0,     0,   786,    25,
      26,   787,    28,    29,   788,    31,   789,    33,    34,    35,
      36,     0,  1293,     0,    38,    39,    40,     0,     0,    42,
       0,     0,     0,     0,     0,   790,    49,     0,     0,    51,
     791,     0,    54,    55,   792,     0,     0,   786,    25,    26,
     787,    28,    29,   788,    31,   789,    33,    34,    35,    36,
       0,  1299,    72,    38,    39,    40,     0,     0,    42,     0,
       7,     8,     0,     0,   790,    49,     0,     0,    51,   791,
       0,    54,    55,   792,     0,     0,    86,    87,    88,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    72,     0,   491,   492,   493,   494,   495,   496,   497,
     498,   499,   500,   501,   502,   503,   504,     0,     0,     0,
       0,   505,     0,     0,     0,    86,    87,    88,  1051,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   786,    25,    26,   787,    28,    29,
     788,    31,   789,    33,    34,    35,    36,     0,  1467,     0,
      38,    39,    40,     0,     0,    42,     0,     0,     0,     0,
       0,   790,    49,     0,     0,    51,   791,     0,    54,    55,
     792,     0,     0,     0,     0,     0,     0,     0,    -4,     1,
       0,     0,    -4,     0,     0,     0,     0,  2093,    72,     0,
      -4,    -4,   491,   492,   493,   494,   495,   496,   497,   498,
     499,   500,   501,   502,   503,   504,     0,     0,     0,     0,
     505,     0,    86,    87,    88,     0,     0,  1066,     0,     0,
      -4,    -4,     0,     0,     0,   491,   492,   493,   494,   495,
     496,   497,   498,   499,   500,   501,   502,   503,   504,     0,
      -4,    -4,    -4,   505,     0,     0,    -4,    -4,     0,    -4,
    1193,     0,     0,    -4,    -4,     0,    -4,    -4,     0,    -4,
       0,     0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,     0,    -4,
      -4,    -4,    -4,    -4,  2180,    -4,    -4,    -4,    -4,    -4,
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
      17,    18,     0,    19,    20,     0,    21,     0,     0,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,     0,     0,    37,    38,    39,    40,
      41,     0,    42,    43,    44,    45,    46,    47,    48,    49,
      50,     0,    51,    52,    53,    54,    55,    56,    57,     0,
      58,    59,    60,    61,    62,    63,    64,    65,    66,     0,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,     0,     0,     0,    81,    82,    83,
       0,     0,     0,    84,     0,     0,     0,     0,    85,    86,
      87,    88,   237,   137,    89,     0,    90,     0,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,     0,     0,     0,     0,     0,     0,   105,   106,
     107,   514,   137,     0,     0,     0,     0,   108,     0,   109,
       7,     8,   164,   165,   166,   167,   168,   169,   170,   171,
     172,     0,     0,     0,     0,   177,   178,   179,   180,     0,
       0,     0,     0,   182,   183,   184,     0,     0,   185,     0,
       0,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     190,   191,     0,     0,   177,   178,   179,   180,     0,     0,
       0,     0,   182,   183,   184,     0,     0,   185,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   190,
     191,     0,     0,     0,   786,    25,    26,   787,    28,    29,
     788,    31,   789,    33,    34,    35,    36,     0,     0,     0,
      38,    39,    40,     0,     0,    42,     0,     0,     0,     0,
       0,   790,    49,     0,     0,    51,   791,     0,    54,    55,
     792,     0,     0,     0,     0,     0,     0,     0,     7,     8,
       0,     0,     0,     0,     0,     0,     0,     0,    72,     0,
       0,     0,  1010,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   194,   195,   196,     0,
       0,     0,    86,    87,    88,     0,     0,     0,     0,   203,
       0,   204,   109,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   194,   195,   196,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   203,     0,
     204,   109,   786,    25,    26,   787,    28,    29,   788,    31,
     789,    33,    34,    35,    36,     0,     0,     0,    38,    39,
      40,     0,     0,    42,     0,     0,     0,     0,     0,   790,
      49,     0,     0,    51,   791,     0,    54,    55,   792,   491,
     492,   493,   494,   495,   496,   497,   498,   499,   500,   501,
     502,   503,   504,     0,     0,     0,    72,   505,     0,     0,
       0,     0,     0,     0,  1194,   491,   492,   493,   494,   495,
     496,   497,   498,   499,   500,   501,   502,   503,   504,     0,
      86,    87,    88,   505,     0,     0,     0,     0,     0,     0,
    1196,   491,   492,   493,   494,   495,   496,   497,   498,   499,
     500,   501,   502,   503,   504,     0,     0,     0,     0,   505,
       0,     0,     0,     0,     0,     0,  1250,   491,   492,   493,
     494,   495,   496,   497,   498,   499,   500,   501,   502,   503,
     504,     0,     0,     0,     0,   505,     0,     0,     0,     0,
       0,     0,  1251,   491,   492,   493,   494,   495,   496,   497,
     498,   499,   500,   501,   502,   503,   504,     0,     0,     0,
       0,   505,     0,     0,     0,     0,     0,     0,  1252,   491,
     492,   493,   494,   495,   496,   497,   498,   499,   500,   501,
     502,   503,   504,     0,     0,     0,     0,   505,     0,     0,
       0,     0,     0,     0,  1287,   491,   492,   493,   494,   495,
     496,   497,   498,   499,   500,   501,   502,   503,   504,     0,
       0,     0,     0,   505,     0,     0,     0,     0,     0,     0,
    1389,   491,   492,   493,   494,   495,   496,   497,   498,   499,
     500,   501,   502,   503,   504,     0,     0,     0,     0,   505,
       0,     0,     0,     0,     0,     0,  1469,   491,   492,   493,
     494,   495,   496,   497,   498,   499,   500,   501,   502,   503,
     504,     0,     0,     0,     0,   505,     0,     0,     0,     0,
       0,     0,  1470,   491,   492,   493,   494,   495,   496,   497,
     498,   499,   500,   501,   502,   503,   504,     0,     0,     0,
       0,   505,     0,     0,     0,     0,     0,     0,  1515,   491,
     492,   493,   494,   495,   496,   497,   498,   499,   500,   501,
     502,   503,   504,     0,     0,     0,     0,   505,     0,     0,
       0,     0,     0,     0,  1643,   491,   492,   493,   494,   495,
     496,   497,   498,   499,   500,   501,   502,   503,   504,     0,
       0,     0,     0,   505,     0,     0,     0,     0,     0,     0,
    1644,   491,   492,   493,   494,   495,   496,   497,   498,   499,
     500,   501,   502,   503,   504,     0,     0,     0,     0,   505,
       0,     0,     0,     0,     0,     0,  1645,   491,   492,   493,
     494,   495,   496,   497,   498,   499,   500,   501,   502,   503,
     504,     0,     0,     0,     0,   505,     0,     0,     0,     0,
       0,     0,  1646,   491,   492,   493,   494,   495,   496,   497,
     498,   499,   500,   501,   502,   503,   504,     0,     0,     0,
       0,   505,     0,     0,     0,     0,     0,     0,  1647,   491,
     492,   493,   494,   495,   496,   497,   498,   499,   500,   501,
     502,   503,   504,     0,     0,     0,     0,   505,     0,     0,
       0,     0,     0,     0,  1648,   491,   492,   493,   494,   495,
     496,   497,   498,   499,   500,   501,   502,   503,   504,     0,
       0,     0,     0,   505,     0,     0,     0,     0,     0,     0,
    1649,   491,   492,   493,   494,   495,   496,   497,   498,   499,
     500,   501,   502,   503,   504,     0,     0,     0,     0,   505,
       0,     0,     0,     0,     0,     0,  1765,   491,   492,   493,
     494,   495,   496,   497,   498,   499,   500,   501,   502,   503,
     504,     0,     0,     0,     0,   505,     0,     0,     0,     0,
       0,     0,  1766,   491,   492,   493,   494,   495,   496,   497,
     498,   499,   500,   501,   502,   503,   504,     0,     0,     0,
       0,   505,     0,     0,     0,     0,     0,     0,  1773,   491,
     492,   493,   494,   495,   496,   497,   498,   499,   500,   501,
     502,   503,   504,     0,     0,     0,     0,   505,     0,     0,
       0,     0,     0,     0,  1921,   491,   492,   493,   494,   495,
     496,   497,   498,   499,   500,   501,   502,   503,   504,     0,
       0,     0,     0,   505,     0,     0,     0,     0,     0,     0,
    1922,   491,   492,   493,   494,   495,   496,   497,   498,   499,
     500,   501,   502,   503,   504,     0,     0,     0,     0,   505,
       0,     0,     0,     0,     0,     0,  1923,   491,   492,   493,
     494,   495,   496,   497,   498,   499,   500,   501,   502,   503,
     504,     0,     0,     0,     0,   505,     0,     0,     0,     0,
       0,     0,  1924,   491,   492,   493,   494,   495,   496,   497,
     498,   499,   500,   501,   502,   503,   504,     0,     0,     0,
       0,   505,     0,     0,     0,     0,     0,     0,  1925,   491,
     492,   493,   494,   495,   496,   497,   498,   499,   500,   501,
     502,   503,   504,     0,     0,     0,     0,   505,     0,     0,
       0,     0,     0,     0,  1983,   491,   492,   493,   494,   495,
     496,   497,   498,   499,   500,   501,   502,   503,   504,     0,
       0,     0,     0,   505,     0,     0,     0,     0,     0,     0,
    1984,   491,   492,   493,   494,   495,   496,   497,   498,   499,
     500,   501,   502,   503,   504,     0,     0,     0,     0,   505,
       0,     0,     0,     0,     0,     0,  1988,   491,   492,   493,
     494,   495,   496,   497,   498,   499,   500,   501,   502,   503,
     504,     0,     0,     0,     0,   505,     0,     0,     0,     0,
       0,     0,  2065,   491,   492,   493,   494,   495,   496,   497,
     498,   499,   500,   501,   502,   503,   504,     0,     0,     0,
       0,   505,     0,     0,     0,     0,     0,     0,  2066,   491,
     492,   493,   494,   495,   496,   497,   498,   499,   500,   501,
     502,   503,   504,     0,     0,     0,     0,   505,     0,     0,
       0,     0,     0,     0,  2067,   491,   492,   493,   494,   495,
     496,   497,   498,   499,   500,   501,   502,   503,   504,     0,
       0,     0,     0,   505,     0,     0,     0,     0,     0,     0,
    2068,   491,   492,   493,   494,   495,   496,   497,   498,   499,
     500,   501,   502,   503,   504,     0,     0,     0,     0,   505,
       0,     0,     0,     0,     0,     0,  2069,   491,   492,   493,
     494,   495,   496,   497,   498,   499,   500,   501,   502,   503,
     504,     0,     0,     0,     0,   505,     0,     0,     0,     0,
       0,     0,  2111,   491,   492,   493,   494,   495,   496,   497,
     498,   499,   500,   501,   502,   503,   504,     0,     0,     0,
       0,   505,     0,     0,     0,     0,     0,     0,  2114,   491,
     492,   493,   494,   495,   496,   497,   498,   499,   500,   501,
     502,   503,   504,     0,     0,     0,     0,   505,     0,     0,
       0,     0,     0,     0,  2163,   491,   492,   493,   494,   495,
     496,   497,   498,   499,   500,   501,   502,   503,   504,     0,
       0,     0,     0,   505,     0,     0,     0,     0,     0,     0,
    2164,   491,   492,   493,   494,   495,   496,   497,   498,   499,
     500,   501,   502,   503,   504,     0,     0,     0,     0,   505,
       0,     0,     0,     0,     0,     0,  2165,   491,   492,   493,
     494,   495,   496,   497,   498,   499,   500,   501,   502,   503,
     504,     0,     0,     0,     0,   505,     0,     0,     0,     0,
       0,     0,  2166,   491,   492,   493,   494,   495,   496,   497,
     498,   499,   500,   501,   502,   503,   504,     0,     0,     0,
       0,   505,     0,     0,     0,     0,     0,     0,  2167,   491,
     492,   493,   494,   495,   496,   497,   498,   499,   500,   501,
     502,   503,   504,     0,     0,     0,     0,   505,     0,     0,
       0,     0,     0,     0,  2168,   491,   492,   493,   494,   495,
     496,   497,   498,   499,   500,   501,   502,   503,   504,     0,
       0,     0,     0,   505,     0,     0,     0,     0,     0,     0,
    2228,   491,   492,   493,   494,   495,   496,   497,   498,   499,
     500,   501,   502,   503,   504,     0,     0,     0,     0,   505,
       0,     0,     0,     0,     0,     0,  2229,   491,   492,   493,
     494,   495,   496,   497,   498,   499,   500,   501,   502,   503,
     504,     0,     0,     0,     0,   505,     0,     0,     0,     0,
       0,     0,  2230,   491,   492,   493,   494,   495,   496,   497,
     498,   499,   500,   501,   502,   503,   504,     0,     0,     0,
       0,   505,     0,     0,     0,     0,     0,     0,  2231,   491,
     492,   493,   494,   495,   496,   497,   498,   499,   500,   501,
     502,   503,   504,     0,     0,     0,     0,   505,     0,   873,
       0,   874,   491,   492,   493,   494,   495,   496,   497,   498,
     499,   500,   501,   502,   503,   504,     0,     0,     0,     0,
     505,     0,     0,     0,   778,   491,   492,   493,   494,   495,
     496,   497,   498,   499,   500,   501,   502,   503,   504,     0,
       0,     0,     0,   505,     0,     0,     0,  1003,   491,   492,
     493,   494,   495,   496,   497,   498,   499,   500,   501,   502,
     503,   504,     0,     0,     0,     0,   505,     0,     0,     0,
    1022,   491,   492,   493,   494,   495,   496,   497,   498,   499,
     500,   501,   502,   503,   504,     0,     0,     0,     0,   505,
       0,     0,     0,  1029,   491,   492,   493,   494,   495,   496,
     497,   498,   499,   500,   501,   502,   503,   504,     0,     0,
       0,     0,   505,     0,     0,     0,  1132,   491,   492,   493,
     494,   495,   496,   497,   498,   499,   500,   501,   502,   503,
     504,     0,     0,     0,     0,   505,     0,     0,     0,  1186,
     491,   492,   493,   494,   495,   496,   497,   498,   499,   500,
     501,   502,   503,   504,     0,     0,     0,     0,   505,     0,
       0,     0,  1212,   491,   492,   493,   494,   495,   496,   497,
     498,   499,   500,   501,   502,   503,   504,     0,     0,     0,
       0,   505,     0,     0,     0,  1280,   491,   492,   493,   494,
     495,   496,   497,   498,   499,   500,   501,   502,   503,   504,
       0,     0,     0,     0,   505,     0,     0,     0,  1281,   491,
     492,   493,   494,   495,   496,   497,   498,   499,   500,   501,
     502,   503,   504,     0,     0,     0,     0,   505,     0,     0,
       0,  1285,   491,   492,   493,   494,   495,   496,   497,   498,
     499,   500,   501,   502,   503,   504,     0,     0,     0,     0,
     505,     0,     0,     0,  1286,   491,   492,   493,   494,   495,
     496,   497,   498,   499,   500,   501,   502,   503,   504,     0,
       0,     0,     0,   505,     0,     0,     0,  1319,   491,   492,
     493,   494,   495,   496,   497,   498,   499,   500,   501,   502,
     503,   504,     0,     0,     0,     0,   505,     0,     0,     0,
    1382,   491,   492,   493,   494,   495,   496,   497,   498,   499,
     500,   501,   502,   503,   504,     0,     0,     0,     0,   505,
       0,     0,     0,  1387,   491,   492,   493,   494,   495,   496,
     497,   498,   499,   500,   501,   502,   503,   504,     0,     0,
       0,     0,   505,     0,     0,     0,  1708,   491,   492,   493,
     494,   495,   496,   497,   498,   499,   500,   501,   502,   503,
     504,     0,     0,     0,     0,   505,     0,     0,     0,  1752,
     491,   492,   493,   494,   495,   496,   497,   498,   499,   500,
     501,   502,   503,   504,     0,     0,     0,     0,   505,     0,
       0,     0,  1945,   491,   492,   493,   494,   495,   496,   497,
     498,   499,   500,   501,   502,   503,   504,     0,     0,     0,
       0,   505,     0,   774,   491,   492,   493,   494,   495,   496,
     497,   498,   499,   500,   501,   502,   503,   504,     0,     0,
       0,     0,   505,     0,   839,   491,   492,   493,   494,   495,
     496,   497,   498,   499,   500,   501,   502,   503,   504,     0,
       0,     0,     0,   505,     0,   843,   491,   492,   493,   494,
     495,   496,   497,   498,   499,   500,   501,   502,   503,   504,
       0,     0,     0,     0,   505,     0,   844,   491,   492,   493,
     494,   495,   496,   497,   498,   499,   500,   501,   502,   503,
     504,     0,     0,     0,     0,   505,     0,   846,   491,   492,
     493,   494,   495,   496,   497,   498,   499,   500,   501,   502,
     503,   504,     0,     0,     0,     0,   505,     0,   848,   491,
     492,   493,   494,   495,   496,   497,   498,   499,   500,   501,
     502,   503,   504,     0,     0,     0,     0,   505,     0,   849,
     491,   492,   493,   494,   495,   496,   497,   498,   499,   500,
     501,   502,   503,   504,     0,     0,     0,     0,   505,     0,
     851,   491,   492,   493,   494,   495,   496,   497,   498,   499,
     500,   501,   502,   503,   504,     0,     0,     0,     0,   505,
       0,   853,   491,   492,   493,   494,   495,   496,   497,   498,
     499,   500,   501,   502,   503,   504,     0,     0,     0,     0,
     505,     0,   854,   491,   492,   493,   494,   495,   496,   497,
     498,   499,   500,   501,   502,   503,   504,     0,     0,     0,
       0,   505,     0,   855,   491,   492,   493,   494,   495,   496,
     497,   498,   499,   500,   501,   502,   503,   504,     0,     0,
       0,     0,   505,     0,   856,   491,   492,   493,   494,   495,
     496,   497,   498,   499,   500,   501,   502,   503,   504,     0,
       0,     0,     0,   505,     0,   857,   491,   492,   493,   494,
     495,   496,   497,   498,   499,   500,   501,   502,   503,   504,
       0,     0,     0,     0,   505,     0,   858,   491,   492,   493,
     494,   495,   496,   497,   498,   499,   500,   501,   502,   503,
     504,     0,     0,     0,     0,   505,     0,   860,   491,   492,
     493,   494,   495,   496,   497,   498,   499,   500,   501,   502,
     503,   504,     0,     0,     0,     0,   505,     0,   861,   491,
     492,   493,   494,   495,   496,   497,   498,   499,   500,   501,
     502,   503,   504,     0,     0,     0,     0,   505,     0,   862,
     491,   492,   493,   494,   495,   496,   497,   498,   499,   500,
     501,   502,   503,   504,     0,     0,     0,     0,   505,     0,
     902,   491,   492,   493,   494,   495,   496,   497,   498,   499,
     500,   501,   502,   503,   504,     0,     0,     0,     0,   505,
       0,   913,   491,   492,   493,   494,   495,   496,   497,   498,
     499,   500,   501,   502,   503,   504,     0,     0,     0,     0,
     505,     0,   974,   491,   492,   493,   494,   495,   496,   497,
     498,   499,   500,   501,   502,   503,   504,     0,     0,     0,
       0,   505,     0,   992,   491,   492,   493,   494,   495,   496,
     497,   498,   499,   500,   501,   502,   503,   504,     0,     0,
       0,     0,   505,     0,   993,   491,   492,   493,   494,   495,
     496,   497,   498,   499,   500,   501,   502,   503,   504,     0,
       0,     0,     0,   505,     0,   994,   491,   492,   493,   494,
     495,   496,   497,   498,   499,   500,   501,   502,   503,   504,
       0,     0,     0,     0,   505,     0,   995,   491,   492,   493,
     494,   495,   496,   497,   498,   499,   500,   501,   502,   503,
     504,     0,     0,     0,     0,   505,     0,  1001,   491,   492,
     493,   494,   495,   496,   497,   498,   499,   500,   501,   502,
     503,   504,     0,     0,     0,     0,   505,     0,  1002,   491,
     492,   493,   494,   495,   496,   497,   498,   499,   500,   501,
     502,   503,   504,     0,     0,     0,     0,   505,     0,  1009,
     491,   492,   493,   494,   495,   496,   497,   498,   499,   500,
     501,   502,   503,   504,     0,     0,     0,     0,   505,     0,
    1018,   491,   492,   493,   494,   495,   496,   497,   498,   499,
     500,   501,   502,   503,   504,     0,     0,     0,     0,   505,
       0,  1028,   491,   492,   493,   494,   495,   496,   497,   498,
     499,   500,   501,   502,   503,   504,     0,     0,     0,     0,
     505,     0,  1131,   491,   492,   493,   494,   495,   496,   497,
     498,   499,   500,   501,   502,   503,   504,     0,     0,     0,
       0,   505,     0,  1163,   491,   492,   493,   494,   495,   496,
     497,   498,   499,   500,   501,   502,   503,   504,     0,     0,
       0,     0,   505,     0,  1168,   491,   492,   493,   494,   495,
     496,   497,   498,   499,   500,   501,   502,   503,   504,     0,
       0,     0,     0,   505,     0,  1181,   491,   492,   493,   494,
     495,   496,   497,   498,   499,   500,   501,   502,   503,   504,
       0,     0,     0,     0,   505,     0,  1185,   491,   492,   493,
     494,   495,   496,   497,   498,   499,   500,   501,   502,   503,
     504,     0,     0,     0,     0,   505,     0,  1211,   491,   492,
     493,   494,   495,   496,   497,   498,   499,   500,   501,   502,
     503,   504,     0,     0,     0,     0,   505,     0,  1216,   491,
     492,   493,   494,   495,   496,   497,   498,   499,   500,   501,
     502,   503,   504,     0,     0,     0,     0,   505,     0,  1217,
     491,   492,   493,   494,   495,   496,   497,   498,   499,   500,
     501,   502,   503,   504,     0,     0,     0,     0,   505,     0,
    1218,   491,   492,   493,   494,   495,   496,   497,   498,   499,
     500,   501,   502,   503,   504,     0,     0,     0,     0,   505,
       0,  1224,   491,   492,   493,   494,   495,   496,   497,   498,
     499,   500,   501,   502,   503,   504,     0,     0,     0,     0,
     505,     0,  1233,   491,   492,   493,   494,   495,   496,   497,
     498,   499,   500,   501,   502,   503,   504,     0,     0,     0,
       0,   505,     0,  1234,   491,   492,   493,   494,   495,   496,
     497,   498,   499,   500,   501,   502,   503,   504,     0,     0,
       0,     0,   505,     0,  1235,   491,   492,   493,   494,   495,
     496,   497,   498,   499,   500,   501,   502,   503,   504,     0,
       0,     0,     0,   505,     0,  1266,   491,   492,   493,   494,
     495,   496,   497,   498,   499,   500,   501,   502,   503,   504,
       0,     0,     0,     0,   505,     0,  1268,   491,   492,   493,
     494,   495,   496,   497,   498,   499,   500,   501,   502,   503,
     504,     0,     0,     0,     0,   505,     0,  1269,   491,   492,
     493,   494,   495,   496,   497,   498,   499,   500,   501,   502,
     503,   504,     0,     0,     0,     0,   505,     0,  1270,   491,
     492,   493,   494,   495,   496,   497,   498,   499,   500,   501,
     502,   503,   504,     0,     0,     0,     0,   505,     0,  1271,
     491,   492,   493,   494,   495,   496,   497,   498,   499,   500,
     501,   502,   503,   504,     0,     0,     0,     0,   505,     0,
    1272,   491,   492,   493,   494,   495,   496,   497,   498,   499,
     500,   501,   502,   503,   504,     0,     0,     0,     0,   505,
       0,  1273,   491,   492,   493,   494,   495,   496,   497,   498,
     499,   500,   501,   502,   503,   504,     0,     0,     0,     0,
     505,     0,  1274,   491,   492,   493,   494,   495,   496,   497,
     498,   499,   500,   501,   502,   503,   504,     0,     0,     0,
       0,   505,     0,  1279,   491,   492,   493,   494,   495,   496,
     497,   498,   499,   500,   501,   502,   503,   504,     0,     0,
       0,     0,   505,     0,  1381,   491,   492,   493,   494,   495,
     496,   497,   498,   499,   500,   501,   502,   503,   504,     0,
       0,     0,     0,   505,     0,  1386,   491,   492,   493,   494,
     495,   496,   497,   498,   499,   500,   501,   502,   503,   504,
       0,     0,     0,     0,   505,     0,  1560,   491,   492,   493,
     494,   495,   496,   497,   498,   499,   500,   501,   502,   503,
     504,     0,     0,     0,     0,   505,     0,  1585,   491,   492,
     493,   494,   495,   496,   497,   498,   499,   500,   501,   502,
     503,   504,     0,     0,     0,     0,   505,     0,  1758,   491,
     492,   493,   494,   495,   496,   497,   498,   499,   500,   501,
     502,   503,   504,     0,     0,     0,     0,   505,     0,  1759,
     491,   492,   493,   494,   495,   496,   497,   498,   499,   500,
     501,   502,   503,   504,     0,     0,     0,     0,   505,     0,
    1760,   491,   492,   493,   494,   495,   496,   497,   498,   499,
     500,   501,   502,   503,   504,     0,     0,     0,     0,   505,
       0,  1761,   491,   492,   493,   494,   495,   496,   497,   498,
     499,   500,   501,   502,   503,   504,     0,     0,     0,     0,
     505,     0,  1821,   491,   492,   493,   494,   495,   496,   497,
     498,   499,   500,   501,   502,   503,   504,     0,     0,     0,
       0,   505,     0,  1839,   491,   492,   493,   494,   495,   496,
     497,   498,   499,   500,   501,   502,   503,   504,     0,     0,
       0,     0,   505,     0,  1862,   491,   492,   493,   494,   495,
     496,   497,   498,   499,   500,   501,   502,   503,   504,     0,
       0,     0,     0,   505,     0,  2110,   491,   492,   493,   494,
     495,   496,   497,   498,   499,   500,   501,   502,   503,   504,
       0,     0,     0,     0,   505,     0,  2193,   491,   492,   493,
     494,   495,   496,   497,   498,   499,   500,   501,   502,   503,
     504,     0,     0,     0,     0,   505
};

static const yytype_int16 yycheck[] =
{
       3,     3,   322,     6,   337,   442,  1261,   444,  1394,     4,
     633,   634,  1696,     4,  1719,  1720,     4,     6,    21,     4,
       7,   354,   459,     4,     6,     4,     4,     4,     4,    13,
       4,     4,     7,     5,     5,     5,     5,     5,     4,     4,
       4,   225,   226,     5,     5,    48,     5,     4,     6,     6,
       6,     6,     6,     6,   597,    92,     5,     4,   391,    92,
     393,    12,    13,     7,   218,   219,   399,     5,   228,     6,
     230,   218,   219,    76,   124,   134,   113,   237,     4,     6,
     113,    84,   236,     6,  1265,     6,    89,   234,   228,   236,
     124,   141,     6,     7,   476,   235,   478,   100,   480,   149,
     150,   151,   218,   219,     0,   155,   156,   141,     6,  1793,
     218,   219,   228,   218,   219,   149,   150,   151,   100,   235,
     102,   155,   156,   230,   225,   226,   234,     6,   236,    86,
     235,     7,   218,   219,   235,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,   234,    92,
     236,   102,   103,   104,     7,   229,   107,   231,     6,   228,
     234,   230,   113,   114,   169,   228,   117,   118,   237,   120,
     121,   122,   218,   219,   159,   160,   161,   162,   218,   219,
     185,   186,   218,   219,     7,   180,   236,   228,   234,   140,
     218,   219,   128,   129,   234,   169,   170,   228,   134,   235,
     172,   172,   157,   157,   169,   170,   234,     7,   211,   204,
     212,   218,   219,   164,   165,   166,   230,   228,  1902,     7,
     184,   224,   225,   172,   235,   204,   215,     6,   235,   232,
     205,   206,   207,   208,   172,  1490,     6,   228,   204,   230,
     235,   244,   230,   246,  1928,   232,   237,   228,   251,   237,
     228,   236,   228,   256,   235,   228,   235,   235,   235,   235,
     263,   243,   235,   235,   267,   235,   235,   235,   271,   272,
     273,   274,   275,   235,   235,   228,   235,   235,   204,   235,
     823,   228,   235,   286,   228,   236,   230,   290,   215,   292,
      89,   624,   625,    92,     7,   218,   219,   218,   219,    89,
     303,     7,    92,   306,   307,   308,   309,   233,   228,     6,
     230,   644,   315,   316,   317,   235,     7,   237,   321,   322,
     218,   219,   704,     6,   706,     4,     5,   218,   219,   205,
     206,   207,   208,   228,    86,   218,   219,    89,    86,     6,
      92,    89,    94,   234,    92,   348,   349,   350,   681,   225,
     226,   234,   205,   206,   207,   208,   232,   228,   361,   362,
       7,     6,     7,   696,   235,    44,    45,    46,    47,    48,
      49,    50,    51,    52,   218,   219,   224,   225,    57,    58,
      59,    60,   205,   206,   207,   208,    65,    66,    67,   228,
     234,    70,   774,   228,   397,   230,   778,   228,   401,   402,
    2105,   225,   226,    82,    83,   205,   206,   207,   208,   218,
     219,   235,   415,   231,   228,   263,   234,   205,   206,   207,
     208,   480,   228,   225,   226,   234,   408,   275,    86,  2113,
     232,    89,   228,   235,    92,   228,   218,   219,     6,   442,
     443,   444,   445,   446,   447,   448,   449,   450,   451,   452,
     453,   454,   234,   456,   457,   458,   459,   460,    92,   462,
     218,   219,   465,   466,   467,   468,   469,   470,   228,   472,
     218,   219,   218,   219,   218,   219,   234,   228,   232,     3,
     228,   463,     6,   237,   225,   226,   489,   235,   234,   471,
     234,   232,   205,   206,   207,   208,   228,    21,   230,   205,
     206,   207,   208,    89,   231,   237,    92,   234,    94,   188,
     189,   190,   225,   226,   205,   206,   207,   208,   228,   225,
     226,  1907,   201,     8,   203,   204,   228,   530,   218,   219,
     225,   226,   218,   219,   225,   226,   231,   232,   218,   219,
    2224,     4,   231,   228,   234,   234,   225,   226,   234,   397,
     235,   228,    76,   232,   234,   228,   235,   230,   205,   206,
     207,   208,   565,   566,   237,    89,   569,   228,   218,   219,
     218,   219,   218,   219,   225,   226,   100,   580,   225,   226,
     106,   232,   585,   586,   234,   228,   234,   230,   234,   228,
     593,   218,   219,    92,   237,   443,     4,   445,   446,   447,
     448,   449,   450,   451,   228,   453,   454,   234,   456,   457,
     458,   235,   460,   946,     6,   618,   619,   465,   466,   467,
     468,   469,   218,   219,   225,   226,   608,   609,   610,   611,
      89,   633,   634,    92,   235,    94,  1018,    92,   234,    94,
    1022,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   229,     8,   218,   219,   227,
     234,   228,   665,   666,   667,   128,   129,   130,   131,   218,
     219,   225,   226,   234,   229,  2061,  2062,   235,    86,   234,
     143,   235,    90,   146,   228,   234,   689,   211,    96,    97,
     235,    99,   100,    92,   229,   218,   219,   218,   219,   234,
     224,   225,   218,   219,    86,    94,   709,    89,   232,   117,
      92,   234,    94,   234,   228,   774,   128,   129,   234,   778,
     244,   569,   134,   124,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   235,   263,
     141,   229,   227,   231,   229,   218,   219,   235,   149,   150,
     151,   275,   218,   219,   155,   156,   815,   229,  1939,   231,
    1941,   234,  1943,   235,   124,   234,  2021,   236,   234,  2024,
     773,   228,  2027,   230,   777,   124,    89,   218,   219,   235,
     237,   141,   228,   218,   219,  1105,   228,   124,   230,   149,
     150,   151,   141,   234,    92,   155,   156,   779,   322,   234,
     149,   150,   151,   229,   141,   231,   155,   156,   234,    92,
     225,   226,   149,   150,   151,    89,   229,   820,   155,   156,
     235,   234,   825,    89,   229,   828,   231,     6,   831,   234,
     833,   834,   228,   836,   230,   236,     4,   840,   841,    89,
       4,   237,    92,  1225,    94,  1227,   229,  1229,   231,  1231,
     229,   234,   231,   912,   124,   234,   838,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   141,   875,   397,   877,   227,   236,   880,   229,   149,
     150,   151,     4,   234,   236,   155,   156,   236,     4,  2144,
     893,     6,   895,   229,   897,   231,   899,   228,   234,   236,
     218,   219,   905,   229,   228,  1342,  1343,   910,   234,     8,
    1347,  1348,   229,  2094,   231,   230,   919,   234,   442,   443,
     444,   445,   446,   447,   448,   449,   450,   451,   228,   453,
     454,   228,   456,   457,   458,   459,   460,     8,   462,   228,
     943,   465,   466,   467,   468,   469,   470,   124,   472,  2204,
      62,    63,  2207,    65,   234,  2210,   236,   228,  2213,  1018,
     220,   221,   222,  1022,   141,   230,   236,   227,  1350,  1028,
    1029,   229,   149,   150,   151,   234,   234,   236,   155,   156,
     828,   124,   234,     6,   236,   833,   234,   228,   236,  1371,
    2171,   234,  2173,   236,  2175,   234,   228,   236,   141,  2254,
    2181,  2256,   229,  2258,   231,   228,   149,   150,   151,   234,
    1013,   236,   155,   156,  1017,   234,   228,   236,  1021,   234,
     234,   236,   236,   234,   228,   236,  1029,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   234,  1357,   236,   234,
     227,   236,   566,     7,   234,   569,   236,   228,   228,   234,
    1053,   236,  1675,  1676,  2235,  1058,  2237,   228,  2239,   236,
    1063,  1064,  1065,  1066,   230,   218,   219,   220,   221,   222,
     228,   228,  1131,  1132,   227,    92,  1079,    94,  1081,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
    1527,  1528,     6,   236,   227,  1532,  1533,    92,   234,    94,
     236,     4,  1105,     6,   235,  1108,  1109,  1110,  1111,   235,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,     8,   235,  1185,  1186,   227,   234,
     234,   236,   236,     6,   234,  1138,   236,   236,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,  1211,  1212,     6,  1537,   227,   237,  1161,  1162,
     234,  1164,   236,  1166,  1167,   234,  1169,   236,  1171,  1172,
    1173,  1174,  1175,  1176,  1177,  1178,  1179,   234,   237,   236,
    1183,  1029,   234,   234,   236,   236,   234,     8,   236,  1522,
     234,  1524,   236,   234,   234,   236,   236,   234,   234,   236,
     236,     4,     5,   124,   234,  1208,   236,   234,   228,   236,
    1058,  1214,  1215,   325,   326,   228,  1064,  1065,  1066,   228,
     141,   333,   234,   113,   236,   337,   228,   235,   149,   150,
     151,  1079,   235,  1081,   155,   156,   234,   234,   236,   236,
     228,    44,    45,    46,    47,    48,    49,    50,    51,    52,
     234,   234,   236,   236,    57,    58,    59,    60,   234,  1579,
     236,   228,    65,    66,    67,   228,   234,    70,   236,   228,
     228,   124,  1275,   234,   234,   236,   236,   228,   235,    82,
      83,   234,   234,   236,   236,  1288,  1289,  1290,   141,     4,
    1138,  1350,   234,   234,   236,   236,   149,   150,   151,   235,
     235,  1304,   155,   156,   828,   235,   234,   831,   236,   833,
     834,  1934,   836,   235,   234,   236,   236,   234,   234,   236,
     236,   234,   234,   236,   236,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,  1342,
    1343,   235,   228,   227,  1347,  1348,   234,   234,   236,   236,
     228,   234,   228,   236,  1357,   230,     6,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,     6,   234,  1376,   236,   227,   234,   234,   236,   236,
     234,   228,   236,   236,   228,   188,   189,   190,   234,   234,
     236,   236,   234,   234,   236,   236,   228,   228,   201,  1402,
     203,   204,   228,     6,     6,  1408,   124,   235,  1390,     6,
     246,   235,   235,   230,   230,   251,   230,   235,   172,  1422,
     256,     6,     6,   141,   235,     6,   229,     6,   231,   235,
     235,   149,   150,   151,     6,   271,   230,   155,   156,   124,
     227,   232,  1445,  1446,  1447,     7,  1883,   235,  1451,  1452,
     236,  1454,     4,  1456,   232,  1458,   141,  1460,  1461,  1462,
     235,     8,   234,   234,   149,   150,   151,   303,   229,     7,
     155,   156,     6,     6,     6,    62,   229,  1480,     7,    62,
    1539,   124,    62,     7,    62,     6,     6,     6,  1491,   229,
       6,   235,     7,     6,   169,     7,  1499,     6,   141,  1502,
       6,     6,   235,   231,   229,  1029,   149,   150,   151,     6,
       6,   234,   155,   156,   234,   229,   229,   234,   236,   631,
     632,     8,   234,   234,  1527,  1528,   234,   639,   234,  1532,
    1533,   229,   229,   229,  1058,     6,   231,    44,     4,  1521,
    1064,  1065,  1066,  1546,    44,    44,    44,   228,     6,  1552,
       6,   236,     6,    12,    13,  1079,     6,  1081,   230,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,  1893,     7,     7,  1579,   227,   172,     7,
    1639,  1105,     7,   172,     7,     7,     7,  1590,     6,  1571,
     172,     7,     7,   236,     7,     7,     7,  1600,     7,     7,
    1603,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,     7,  1138,     7,  1949,   227,   235,     6,
     229,  1603,   235,   231,   235,     7,     7,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
     235,     4,   235,   102,   103,   104,     6,   235,   107,   272,
     273,   274,   229,   489,   113,   114,   229,   232,   117,   118,
     234,   120,   121,   122,  1667,  1668,   234,   234,   229,   229,
     234,   236,   124,  1675,  1676,     7,     6,   236,     7,     7,
       7,   140,   232,     7,   307,   308,   309,   236,     6,  1671,
     235,    44,    44,  1696,    44,    44,     8,     6,  1546,  1702,
       6,     6,     6,     6,  1552,   164,   165,   166,  1711,     7,
       8,     7,   230,  2046,     6,     6,    94,   228,  1721,   236,
     228,   235,   215,     7,   228,   348,   349,   350,  1731,     7,
       7,     7,     7,  1736,   228,  1717,   228,   228,   361,   362,
       7,     7,     6,   104,     7,     7,     7,     6,   228,     7,
     586,     7,  1600,     7,  1736,     4,  1738,  1739,     4,   235,
       7,     6,  2095,     6,  1767,     7,     6,   235,     7,     7,
       7,     7,     7,     7,     6,     6,     6,   236,    92,     7,
       6,     6,   618,   619,     4,     4,     4,   234,   236,   235,
    1793,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   235,     6,     6,     6,   227,
       6,     6,     4,     6,   234,   229,     7,   234,  1342,  1343,
       6,     6,   232,  1347,  1348,   229,   233,   228,     6,   665,
     666,   667,   235,  1357,   232,  1838,   229,   949,     6,   235,
     231,     6,     6,   117,   956,   235,   235,  1850,     6,   235,
     172,   963,   235,   689,     6,     6,     6,     6,     6,     6,
    1863,     6,     6,     6,     5,     4,   231,   229,     6,     6,
       4,     6,   230,   709,     7,     6,   235,  1880,   235,   235,
    1883,   235,     6,     6,  1866,     6,     6,   235,   235,   235,
    1893,   235,   235,   235,   235,   235,   168,     6,   234,  1902,
       6,     4,     6,    90,     6,     6,  1909,  1910,     4,     6,
       4,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,  1928,     6,     6,  1931,   227,
       6,     6,  1934,     6,   235,     7,     7,     6,     6,     6,
       6,     6,     5,   229,     6,  1948,   235,     6,     6,  1952,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,     6,     6,     6,     6,   227,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,     6,   820,     6,     6,   227,     6,   825,
       6,     6,     6,   234,     6,     6,     6,     6,     6,     6,
       6,   234,     6,  1527,  1528,     6,     6,  2010,  1532,  1533,
       7,     6,     6,   235,     6,   232,     5,     7,     6,   235,
     235,   235,  1546,   235,     6,   235,  2029,   236,  1552,   236,
     235,   235,   235,     6,   235,     6,     6,   167,     6,   875,
       6,   877,   236,     6,   880,  1157,   236,   236,  2051,     6,
       6,     6,   170,     6,     6,  1579,     6,   893,     6,   895,
       6,   897,     6,   899,     6,     6,     6,   124,  2050,   905,
     229,     6,   235,     7,   910,     6,  1600,     6,   235,   235,
     235,   235,     6,   236,     6,     6,   124,     6,     6,   235,
       6,     6,     6,     6,  2097,  2098,  2099,  2100,  2101,     6,
       6,     6,     6,   228,   236,     6,   235,   943,   235,   235,
    2113,     6,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   236,   235,    12,    13,
     227,   229,     6,     6,     6,     6,     6,     6,  1250,  1251,
    1252,     6,     6,     6,   235,     6,   235,   235,   235,   235,
       6,   108,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,     6,     6,     6,     6,
     227,     6,  2154,     6,     6,     6,     6,     6,     6,     6,
    1385,  2054,  1908,  2186,  1655,   524,     3,     3,  1401,  2192,
       3,     3,  1930,     3,  1575,    -1,    -1,    -1,    -1,    -1,
     606,    -1,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    -1,    -1,  1053,   102,   103,
     104,  2224,    -1,   107,    -1,    -1,    -1,    -1,    -1,   113,
     114,    -1,    -1,   117,   118,    -1,   120,   121,   122,  2242,
      -1,  2244,    -1,    -1,    -1,    -1,    -1,    -1,   205,   206,
     207,   208,   209,    -1,    -1,    -1,   140,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   223,    -1,    -1,    -1,
     227,  2274,  1108,  1109,  1110,  1111,    -1,    -1,    -1,    -1,
     164,   165,   166,    -1,    -1,    -1,    -1,    -1,   245,   246,
     247,   248,    -1,   250,   251,   252,   253,    -1,   255,   256,
     257,   258,   259,   260,   261,   262,     7,   264,   265,   266,
      -1,    -1,    -1,    -1,   271,    -1,    -1,    -1,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,    -1,   290,   291,   292,   227,    -1,   229,    -1,
     231,    -1,    -1,   234,  2192,   302,   303,  1183,    -1,    -1,
      -1,    -1,   236,    -1,    -1,    -1,    -1,    -1,    -1,  1883,
      -1,    -1,   319,    -1,    -1,    -1,    -1,    -1,    -1,  1893,
      -1,   328,   329,    -1,    -1,    -1,    -1,  1489,    -1,  1215,
     337,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     347,    -1,    -1,    -1,  2242,    -1,  2244,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     367,    -1,    -1,    -1,   371,   372,   373,    -1,   375,    -1,
      -1,    -1,   379,   380,   381,    -1,  2274,   384,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   398,    -1,    -1,    -1,    -1,    -1,   404,   405,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   418,   419,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,   439,   440,   441,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   455,    -1,
      -1,    -1,  1614,    -1,   461,    -1,    -1,   464,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,    -1,    -1,    -1,    -1,   227,  2051,    -1,    -1,
      -1,   488,   489,    -1,   491,   492,   493,   494,   495,   496,
     497,   498,   499,   500,   501,   502,   503,   504,   505,    -1,
      -1,   508,   509,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1677,    -1,  1679,    -1,  1681,
      -1,    -1,    -1,   530,    -1,    -1,    -1,    -1,    -1,   536,
      -1,    -1,    -1,    -1,   541,  1697,  1698,  1699,  1700,  1701,
    1702,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   555,   556,
      -1,    -1,    -1,    -1,    -1,   562,   563,    -1,   565,   566,
     567,   568,    -1,   570,    -1,    -1,   573,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   585,   586,
      -1,    -1,    -1,    -1,    -1,   592,   593,   594,   595,    -1,
      -1,    -1,    -1,   600,   601,   602,    -1,    -1,    -1,    -1,
     607,   608,   609,   610,   611,   612,    -1,   614,    -1,   616,
      -1,   618,   619,    -1,    -1,    -1,  1502,    -1,  2192,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   636,
     637,   638,   639,   640,   641,    12,    13,    -1,   645,   646,
     647,   648,   649,   650,   651,   652,   653,    -1,    -1,    -1,
      -1,   658,    -1,   660,   661,    -1,    -1,    -1,   665,   666,
     667,    -1,    -1,   670,   671,   672,    -1,    -1,  2242,    -1,
    2244,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   689,    -1,    -1,    -1,    -1,   694,   695,    -1,
     697,   698,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2274,   708,   709,    -1,    -1,    -1,   713,    -1,    -1,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    -1,    -1,    -1,   102,   103,   104,    -1,    -1,
     107,    -1,    -1,    -1,    -1,    -1,   113,   114,    -1,    -1,
     117,   118,    -1,   120,   121,   122,    -1,    -1,     6,    -1,
      -1,   758,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   140,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   780,    -1,    -1,  1938,    -1,  1940,    -1,
    1942,  1667,  1668,    -1,    -1,    -1,    -1,   164,   165,   166,
      -1,  1953,  1954,  1955,  1956,  1957,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     6,    -1,    -1,    -1,
     817,   818,    -1,   820,   821,   822,    -1,    -1,   825,   826,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     837,    -1,    -1,   840,   841,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2009,    -1,    -1,
      -1,  2013,    -1,    -1,    -1,    -1,   863,    -1,    -1,   236,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   875,    -1,
     877,    -1,    -1,   880,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   893,    -1,   895,    -1,
     897,    -1,   899,    -1,    -1,    -1,    -1,    -1,   905,    -1,
      -1,    -1,    -1,   910,    -1,    -1,    48,    -1,    -1,  2071,
      -1,   918,    -1,  2075,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     6,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   943,    -1,    -1,  2101,
      -1,    -1,    -1,   950,   951,     6,    -1,    -1,    -1,   956,
      -1,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,    -1,    -1,    -1,   975,   227,
      -1,   978,    -1,    -1,    -1,    -1,    -1,  1863,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     997,    -1,   999,  1000,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1010,    -1,    -1,    -1,  2169,  2170,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,     6,    -1,    -1,    -1,   227,    -1,    -1,
      -1,    -1,    -1,    -1,  1041,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1049,  1050,  1051,  1931,  1053,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1061,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1952,    -1,    -1,    -1,
      -1,  1078,    -1,    -1,    -1,    -1,  1083,    -1,     6,    -1,
      -1,    -1,    -1,    -1,    -1,  1092,    -1,    -1,    -1,    -1,
      -1,  1098,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1108,  1109,  1110,  1111,  1112,    -1,    -1,    -1,    -1,
      -1,    -1,  1119,    -1,    -1,    -1,    -1,     6,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   267,    -1,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,    -1,    -1,    -1,   286,   227,  1153,    -1,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,    -1,    -1,   306,    -1,   227,    -1,    -1,    -1,
      -1,    -1,    -1,   315,   316,   317,  1183,    -1,    -1,   321,
      -1,    -1,    -1,    -1,    -1,    -1,  1193,  1194,    -1,  1196,
    1197,    -1,  1199,  1200,  1201,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1209,    -1,    -1,    -1,    -1,    -1,  1215,    -1,
      -1,  2097,  2098,  2099,  2100,  2101,    -1,    -1,    -1,  1226,
      -1,  1228,    -1,  1230,    -1,  1232,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
      -1,    -1,    -1,    -1,   227,    -1,    -1,    -1,  1255,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   401,
     402,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   415,    -1,    -1,    -1,    -1,    -1,    -1,
    1287,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,    -1,    -1,    -1,    -1,   227,
    2186,    -1,    -1,  1310,    -1,    -1,    -1,    -1,  1315,   246,
     452,     6,    -1,    -1,   251,    -1,    -1,    -1,    -1,   256,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   271,    -1,    -1,    -1,   227,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1358,    -1,   290,    -1,   292,    -1,    -1,    -1,    -1,
    1367,  1368,  1369,  1370,    -1,    -1,   303,  1374,  1375,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,    -1,  1389,  1390,    -1,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    -1,    -1,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,    53,
      54,    55,    56,   227,    -1,    -1,    -1,    61,   580,    -1,
     234,    -1,   236,    -1,    -1,    -1,    -1,    -1,    72,    73,
      74,    -1,    -1,    -1,    -1,    -1,    80,    81,    -1,    -1,
      -1,  1468,  1469,  1470,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1480,    -1,  1482,    -1,    -1,    -1,    -1,
      -1,    -1,  1489,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1502,    -1,    -1,    -1,    -1,
    1507,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1515,  1516,
    1517,     6,    -1,    -1,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,    -1,    -1,
       6,    -1,   227,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1547,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1556,
      -1,    -1,   489,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   187,    -1,  1572,    -1,   191,    -1,    -1,
      -1,    -1,   196,   197,   198,   199,   200,     6,    -1,    -1,
     204,    -1,    -1,    -1,  1591,    -1,    -1,    -1,    -1,  1596,
      -1,    -1,    -1,   530,   218,   219,    -1,    -1,     8,   223,
      -1,    -1,    -1,    -1,   228,  1612,  1613,    -1,    -1,   233,
      -1,   235,  1619,  1620,    -1,    -1,    -1,     8,    -1,  1626,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   565,   566,
      -1,   773,    -1,    -1,    -1,   777,  1643,  1644,  1645,  1646,
    1647,  1648,  1649,    -1,    -1,    -1,    -1,    -1,   585,   586,
    1657,    -1,    -1,    -1,    -1,    -1,   593,    -1,    -1,    -1,
    1667,  1668,  1669,    -1,  1671,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1683,  1684,    -1,    -1,
      -1,   618,   619,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1702,    -1,    -1,    -1,  1706,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1717,    -1,    -1,    -1,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   665,   666,
     667,  1738,   227,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,    -1,    -1,    -1,
      -1,   227,   689,    -1,    -1,    -1,    -1,    -1,  1765,  1766,
      -1,    -1,    -1,    -1,    -1,    -1,  1773,    -1,    -1,    -1,
      -1,    -1,   709,    -1,    -1,    -1,    -1,   919,    -1,    -1,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,  1801,    -1,    -1,    -1,   227,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,    -1,    -1,  1822,    -1,   227,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,    -1,    -1,  1841,    -1,   227,    -1,    -1,    -1,
      -1,    -1,    -1,  1850,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1858,    -1,  1860,    -1,    -1,  1863,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1013,    -1,  1880,    -1,  1017,    -1,    -1,    -1,  1021,
      -1,    -1,    -1,   820,    -1,    -1,    -1,    -1,   825,    -1,
      -1,  1898,    -1,    -1,    -1,    -1,  1903,    -1,    -1,    -1,
      -1,    -1,    -1,   840,   841,    -1,    -1,    -1,  1915,    -1,
      -1,    -1,    -1,    -1,  1921,  1922,  1923,  1924,  1925,    -1,
      -1,  1063,    -1,    -1,  1931,    -1,    -1,    -1,    -1,    -1,
      -1,  1938,    -1,  1940,    -1,  1942,    -1,    -1,   875,    -1,
     877,    -1,    -1,   880,    -1,  1952,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1960,    -1,    -1,   893,    -1,   895,    -1,
     897,    -1,   899,    -1,    -1,    -1,    -1,    -1,   905,    -1,
      -1,    -1,    -1,   910,    -1,    -1,  1983,  1984,    -1,    -1,
      -1,  1988,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,    -1,    -1,    -1,    -1,
     227,    -1,    -1,    -1,    -1,    -1,   943,   234,    -1,   236,
    2017,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1161,
    1162,    -1,  1164,    -1,  1166,  1167,    -1,  1169,    -1,  1171,
    1172,  1173,  1174,  1175,  1176,  1177,  1178,  1179,    -1,    -1,
      -1,  2048,    -1,    -1,    -1,    -1,    -1,  2054,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2064,  2065,  2066,
    2067,  2068,  2069,    -1,    -1,    -1,  1208,    -1,    -1,    -1,
      -1,    -1,  1214,    -1,    -1,  2082,    -1,    -1,  2085,    -1,
       8,  2088,    -1,    -1,    -1,  2092,    -1,    -1,    -1,    -1,
    2097,  2098,  2099,  2100,  2101,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2111,    -1,    -1,  2114,    -1,    12,
      13,    -1,    -1,    -1,    -1,    -1,  1053,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,    -1,    -1,  1275,    -1,   227,    -1,    -1,    -1,    -1,
      -1,    -1,   234,    -1,   236,    -1,  1288,  1289,  1290,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2163,  2164,  2165,  2166,
    2167,  2168,  1304,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1108,  1109,  1110,  1111,    -1,    -1,    -1,    -1,  2186,
      -1,    -1,    -1,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    -1,    -1,    -1,   102,
     103,   104,    -1,    -1,   107,    -1,    -1,    -1,    -1,    -1,
     113,   114,    -1,    -1,   117,   118,     8,   120,   121,   122,
      -1,  2228,  2229,  2230,  2231,  2232,  2233,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1376,    -1,    -1,   140,    -1,    -1,
      -1,    -1,    -1,    -1,   596,    -1,  1183,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1402,   164,   165,   166,    -1,    -1,  1408,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1215,    -1,
    1422,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,    -1,    -1,    -1,    -1,   227,
      -1,    -1,    -1,  1445,  1446,  1447,    -1,    -1,    -1,  1451,
    1452,    -1,  1454,    -1,  1456,    -1,  1458,    -1,  1460,  1461,
    1462,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   236,    -1,    -1,    -1,    -1,  1480,    -1,
      -1,    -1,    -1,    -1,    22,    23,    -1,    -1,    -1,  1491,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1499,    -1,    -1,
      -1,    -1,    -1,    -1,   716,   717,   718,   719,   720,   721,
     722,   723,   724,   725,   726,    -1,   728,   729,   730,   731,
     732,   733,   734,    -1,    -1,    -1,   738,   739,   740,    -1,
      -1,    -1,   744,   745,    -1,   747,    -1,    -1,    -1,    -1,
     752,   753,   754,    -1,   756,    -1,    -1,   759,    -1,    -1,
      -1,    -1,    -1,    -1,   766,   767,    -1,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,    -1,   784,    -1,    -1,   227,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1590,    -1,
      -1,    -1,    -1,    -1,    -1,   133,    -1,    -1,    -1,    -1,
      -1,  1603,    -1,    -1,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,    -1,
      -1,    -1,   170,   171,   172,   173,    -1,   175,   176,   177,
     178,   179,   180,    -1,    -1,   183,    -1,    -1,    -1,    -1,
      -1,   189,   190,   191,    -1,    -1,    -1,    -1,   196,   197,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   885,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   900,    -1,
      -1,    -1,   227,    -1,  1696,    -1,    -1,    -1,    -1,    -1,
      -1,   236,    -1,    -1,    -1,  1502,    -1,    -1,    -1,  1711,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1721,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1731,
      -1,    -1,    -1,    -1,  1736,    -1,    -1,    -1,   276,    -1,
     278,   279,   280,   281,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   289,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   300,    -1,    -1,  1767,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
      -1,    -1,    -1,    -1,   227,    -1,    -1,    -1,    -1,    -1,
      -1,  1793,    -1,   236,    -1,    -1,     3,     4,     5,    -1,
      -1,    -1,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      -1,    -1,    -1,    -1,    -1,    -1,  1838,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    -1,    -1,    -1,    65,    66,
      67,    -1,    -1,    70,    -1,    72,    73,    74,    -1,    -1,
    1667,  1668,    -1,    80,    81,    82,    83,     5,    -1,    -1,
      -1,    -1,    -1,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,    -1,    -1,    -1,
    1902,   227,    -1,    -1,    -1,  1702,  1118,  1909,  1910,    -1,
     236,    -1,    -1,    -1,    -1,    -1,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    -1,  1928,    -1,    -1,    57,
      58,    59,    60,    -1,    -1,    -1,    -1,    65,    66,    67,
      -1,    -1,    70,  1155,  1156,   483,  1948,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    82,    83,    -1,    -1,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,    -1,   180,    -1,    -1,   227,    -1,    -1,    -1,
     187,   188,   189,   190,   191,   236,    -1,    -1,    -1,   196,
     197,   198,   199,   200,   201,    -1,   203,   204,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2010,    -1,
      -1,   218,   219,    -1,    -1,    -1,   223,    -1,    -1,    -1,
      -1,   228,    -1,   230,    -1,   232,   233,  2029,   235,    -1,
     237,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,    -1,    -1,    -1,    -1,   227,
      -1,    -1,    -1,  1850,    -1,    -1,    -1,    -1,   236,    -1,
     188,   189,   190,    -1,    -1,    -1,  1863,    -1,    -1,    -1,
      -1,    -1,    -1,   201,    -1,   203,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1880,    -1,    -1,    -1,    -1,    -1,    -1,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,    -1,    -1,  1318,    -1,   227,    -1,
      -1,  2113,  1324,  1325,  1326,  1327,  1328,   236,  1330,    -1,
    1332,  1333,    -1,  1335,    -1,  1337,    -1,    -1,  1340,  1341,
    1342,    -1,    -1,    -1,  1931,  1347,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,    -1,    -1,
      -1,    -1,     9,    10,    11,  1952,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    53,    54,    55,    56,
      -1,    -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1425,    -1,    72,    73,    74,    -1,    -1,
      -1,    -1,  2224,    80,    81,    -1,    -1,    -1,    -1,    86,
    1442,    -1,    89,    -1,    -1,    92,    -1,    94,    -1,    -1,
      -1,    -1,    -1,    -1,   101,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   113,    -1,   115,    -1,
      -1,   118,    -1,    -1,   121,    -1,    -1,    -1,    -1,    -1,
      -1,   128,   129,   130,   131,   132,    -1,    -1,   135,   136,
     137,   138,   139,    -1,    -1,    -1,   143,    -1,    -1,   146,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2097,  2098,  2099,  2100,  2101,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1527,    -1,    -1,    -1,    -1,
    1532,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     187,    -1,    -1,    -1,   191,   192,    -1,    -1,    -1,   196,
     197,   198,   199,   200,    -1,    -1,    -1,   204,    -1,    -1,
      -1,    -1,    -1,  1565,  1566,    -1,    -1,  1569,  1570,    -1,
      -1,   218,   219,    -1,    -1,    -1,   223,    -1,    -1,    -1,
      -1,   228,    -1,    -1,    -1,    -1,   233,    -1,   235,   236,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2186,
      -1,    -1,    -1,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,    -1,    -1,     3,
       4,   227,    -1,    -1,    -1,     9,    10,    11,    -1,   235,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,
      54,    55,    56,    -1,    -1,    -1,    -1,    61,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,    73,
      74,    -1,    -1,    -1,    -1,    -1,    80,    81,    -1,    -1,
      -1,    -1,    86,    -1,    -1,    89,    -1,    -1,    92,    -1,
      94,    -1,    -1,    -1,    -1,    -1,    -1,   101,    -1,    -1,
      -1,    -1,  1724,  1725,    -1,    -1,  1728,  1729,    -1,   113,
      -1,   115,  1734,  1735,   118,    -1,    -1,   121,    -1,    -1,
      -1,    -1,    -1,    -1,   128,   129,   130,   131,   132,    -1,
      -1,   135,   136,   137,   138,   139,    -1,    -1,    -1,   143,
    1088,  1089,   146,    -1,    -1,    -1,  1094,  1095,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,    -1,    -1,    -1,    -1,   227,    -1,    -1,    -1,
      -1,    -1,  1794,  1795,    -1,   236,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   187,    -1,    -1,    -1,   191,   192,    -1,
      -1,    -1,   196,   197,   198,   199,   200,    -1,    -1,    -1,
     204,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   218,   219,    -1,    -1,    -1,   223,
      -1,    -1,    -1,    -1,   228,    -1,    -1,    -1,    -1,   233,
      -1,    -1,   236,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     3,     4,     5,    -1,    -1,    -1,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    -1,    -1,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    -1,    -1,    -1,    65,    66,    67,    -1,    -1,
      70,    -1,    72,    73,    74,    -1,    -1,    -1,    -1,    -1,
      80,    81,    82,    83,    -1,    -1,    86,    -1,    -1,    89,
      -1,    -1,    92,    -1,    94,    -1,    -1,    -1,    -1,    -1,
      -1,   101,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   113,    -1,   115,    -1,    -1,   118,  1307,
    1308,   121,    -1,    -1,  1312,  1313,    -1,    -1,   128,   129,
     130,   131,   132,    -1,    -1,   135,   136,   137,   138,   139,
      -1,    -1,    -1,   143,    -1,    -1,   146,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,    -1,    -1,    -1,    -1,   227,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   236,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   187,   188,   189,
     190,   191,   192,    -1,    -1,    -1,   196,   197,   198,   199,
     200,   201,    -1,   203,   204,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   218,   219,
      -1,    -1,    -1,   223,    -1,    -1,    -1,    -1,   228,    -1,
       3,     4,     5,   233,    -1,   235,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    -1,
      -1,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    -1,
      -1,    -1,    65,    66,    67,    -1,    -1,    70,    -1,    72,
      73,    74,    -1,    -1,    -1,    -1,    -1,    80,    81,    82,
      83,    -1,    -1,    86,    -1,    -1,    89,    -1,    -1,    92,
      -1,    94,    -1,    -1,    -1,    -1,    -1,    -1,   101,    -1,
      -1,    -1,    -1,    -1,    -1,  2197,    -1,    -1,    -1,    -1,
     113,    -1,   115,    -1,    -1,   118,    -1,    -1,   121,    -1,
      -1,    -1,    -1,    -1,    -1,   128,   129,   130,   131,   132,
      -1,    -1,   135,   136,   137,   138,   139,    -1,    -1,    -1,
     143,    -1,    -1,   146,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,    -1,    -1,
      -1,    -1,   227,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   236,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   187,   188,   189,   190,   191,   192,
      -1,    -1,    -1,   196,   197,   198,   199,   200,   201,    -1,
     203,   204,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   218,   219,    -1,    -1,    -1,
     223,    -1,    -1,    -1,    -1,   228,    -1,     3,     4,     5,
     233,    -1,   235,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,    54,    55,
      56,    -1,    -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    72,    73,    74,    -1,
      -1,    -1,    -1,    -1,    80,    81,    -1,    -1,    -1,    -1,
      86,    -1,    -1,    89,    -1,    -1,    92,    -1,    94,    -1,
      -1,    -1,    -1,    -1,    -1,   101,    -1,    -1,    -1,    -1,
      -1,     4,     5,    -1,    -1,    -1,    -1,   113,    -1,   115,
      -1,    -1,   118,    -1,    -1,   121,    -1,    -1,    -1,    -1,
      -1,    -1,   128,   129,   130,   131,   132,    -1,    -1,   135,
     136,   137,   138,   139,    -1,    -1,    -1,   143,    -1,    -1,
     146,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      -1,    -1,    -1,    -1,    57,    58,    59,    60,    -1,    -1,
      -1,    -1,    65,    66,    67,    -1,    -1,    70,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    82,
      83,   187,    -1,    -1,    -1,   191,   192,    -1,    -1,    -1,
     196,   197,   198,   199,   200,    -1,    -1,    -1,   204,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   218,   219,    -1,    -1,    -1,   223,    -1,    -1,
      -1,    -1,   228,    -1,     3,     4,     5,   233,    -1,   235,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    53,    54,    55,    56,    -1,    -1,
      -1,    -1,    61,    -1,    -1,   188,   189,   190,    -1,    -1,
      -1,    -1,    -1,    72,    73,    74,    -1,    -1,   201,    -1,
     203,    80,    81,    -1,    -1,    -1,    -1,    86,    -1,    -1,
      89,    -1,    -1,    92,    -1,    94,    -1,    -1,    -1,    -1,
      -1,    -1,   101,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   113,    -1,   115,    -1,    -1,   118,
      -1,    -1,   121,    -1,    -1,    -1,    -1,    -1,    -1,   128,
     129,   130,   131,   132,    -1,    -1,   135,   136,   137,   138,
     139,    -1,    -1,    -1,   143,    -1,    -1,   146,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,    -1,    -1,    -1,    -1,   227,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   236,    -1,    -1,    -1,    -1,
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
      72,    73,    74,    -1,    -1,    -1,    -1,    -1,    80,    81,
      -1,    -1,    -1,    -1,    86,    -1,    -1,    89,    -1,    -1,
      92,    -1,    94,    -1,    -1,    -1,    -1,    -1,    -1,   101,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   113,    -1,   115,    -1,    -1,   118,    -1,    -1,   121,
      -1,    -1,    -1,    -1,    -1,    -1,   128,   129,   130,   131,
     132,    -1,    -1,   135,   136,   137,   138,   139,    -1,    -1,
      -1,   143,    -1,    -1,   146,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,    -1,
      -1,    -1,    -1,   227,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   236,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
      -1,    -1,    -1,    -1,    -1,    80,    81,    -1,    -1,    -1,
      -1,    86,    -1,    -1,    89,    -1,    -1,    92,    -1,    94,
      -1,    -1,    -1,    -1,    -1,    -1,   101,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,    -1,
     115,    -1,    -1,   118,    -1,    -1,   121,    -1,    -1,    -1,
      -1,    -1,    -1,   128,   129,   130,   131,   132,    -1,    -1,
     135,   136,   137,   138,   139,    -1,    -1,    -1,   143,    -1,
      -1,   146,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,    -1,    -1,    -1,    -1,
     227,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   236,
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
      -1,    -1,    80,    81,    -1,    -1,    -1,    -1,    86,    -1,
      -1,    89,    -1,    -1,    92,    -1,    94,    -1,    -1,    -1,
      -1,    -1,    -1,   101,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   113,    -1,   115,    -1,    -1,
     118,    -1,    -1,   121,    -1,    -1,    -1,    -1,    -1,    -1,
     128,   129,   130,   131,   132,    -1,    -1,   135,   136,   137,
     138,   139,    -1,    -1,    -1,   143,    -1,    -1,   146,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,    -1,    -1,    -1,    -1,   227,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   236,    -1,    -1,    -1,
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
      81,    -1,    -1,    -1,    -1,    86,    -1,    -1,    89,    -1,
      -1,    92,    -1,    94,    -1,    -1,    -1,    -1,    -1,    -1,
     101,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   113,    -1,   115,    -1,    -1,   118,    -1,    -1,
     121,    -1,    -1,    -1,    -1,    -1,    -1,   128,   129,   130,
     131,   132,    -1,    -1,   135,   136,   137,   138,   139,    -1,
      -1,    -1,   143,    -1,    -1,   146,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
      -1,    -1,    -1,    -1,   227,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   236,    -1,    -1,    -1,    -1,    -1,    -1,
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
      74,    -1,    -1,    -1,    -1,    -1,    80,    81,    -1,    -1,
      -1,    -1,    86,    -1,    -1,    89,    -1,    -1,    92,    -1,
      94,    -1,    -1,    -1,    -1,    -1,    -1,   101,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,
      -1,   115,    -1,    -1,   118,    -1,    -1,   121,    -1,    -1,
      -1,    -1,    -1,    -1,   128,   129,   130,   131,   132,    -1,
      -1,   135,   136,   137,   138,   139,    -1,    -1,    -1,   143,
      -1,    -1,   146,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,    -1,    -1,    -1,
      -1,   227,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     236,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
      -1,    -1,    -1,    80,    81,    -1,    -1,    -1,    -1,    86,
      -1,    -1,    89,    -1,    -1,    92,    -1,    94,    -1,    -1,
      -1,    -1,    -1,    -1,   101,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   113,    -1,   115,    -1,
      -1,   118,    -1,    -1,   121,    -1,    -1,    -1,    -1,    -1,
      -1,   128,   129,   130,   131,   132,    -1,    -1,   135,   136,
     137,   138,   139,    -1,    -1,    -1,   143,    -1,    -1,   146,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,    -1,    -1,    -1,    -1,   227,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   236,    -1,    -1,
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
      80,    81,    -1,    -1,    -1,    -1,    86,    -1,    -1,    89,
      -1,    -1,    92,    -1,    94,    -1,    -1,    -1,    -1,    -1,
      -1,   101,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   113,    -1,   115,    -1,    -1,   118,    -1,
      -1,   121,    -1,    -1,    -1,    -1,    -1,    -1,   128,   129,
     130,   131,   132,    -1,    -1,   135,   136,   137,   138,   139,
      -1,    -1,    -1,   143,    -1,    -1,   146,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,    -1,    -1,    -1,    -1,   227,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   236,    -1,    -1,    -1,    -1,    -1,
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
      73,    74,    -1,    -1,    -1,    -1,    -1,    80,    81,    -1,
      -1,    -1,    -1,    86,    -1,    -1,    89,    -1,    -1,    92,
      -1,    94,    -1,    -1,    -1,    -1,    -1,    -1,   101,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     113,    -1,   115,    -1,    -1,   118,    -1,    -1,   121,    -1,
      -1,    -1,    -1,    -1,    -1,   128,   129,   130,   131,   132,
      -1,    -1,   135,   136,   137,   138,   139,    -1,    -1,    -1,
     143,    -1,    -1,   146,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,    -1,    -1,
      -1,    -1,   227,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   236,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
      -1,    -1,    -1,    -1,    80,    81,    -1,    -1,    -1,    -1,
      86,    -1,    -1,    89,    -1,    -1,    92,    -1,    94,    -1,
      -1,    -1,    -1,    -1,    -1,   101,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,    -1,   115,
      -1,    -1,   118,    -1,    -1,   121,    -1,    -1,    -1,    -1,
      -1,    -1,   128,   129,   130,   131,   132,    -1,    -1,   135,
     136,   137,   138,   139,    -1,    -1,    -1,   143,    -1,    -1,
     146,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,    -1,    -1,    -1,    -1,   227,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   236,    -1,
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
      -1,    80,    81,    -1,    -1,    -1,    -1,    86,    -1,    -1,
      89,    -1,    -1,    92,    -1,    94,    -1,    -1,    -1,    -1,
      -1,    -1,   101,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   113,    -1,   115,    -1,    -1,   118,
      -1,    -1,   121,    -1,    -1,    -1,    -1,    -1,    -1,   128,
     129,   130,   131,   132,    -1,    -1,   135,   136,   137,   138,
     139,    -1,    -1,    -1,   143,    -1,    -1,   146,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,    -1,    -1,    -1,    -1,   227,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   236,    -1,    -1,    -1,    -1,
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
      72,    73,    74,    -1,    -1,    -1,    -1,    -1,    80,    81,
      -1,    -1,    -1,    -1,    86,    -1,    -1,    89,    -1,    -1,
      92,    -1,    94,    -1,    -1,    -1,    -1,    -1,    -1,   101,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   113,    -1,   115,    -1,    -1,   118,    -1,    -1,   121,
      -1,    -1,    -1,    -1,    -1,    -1,   128,   129,   130,   131,
     132,    -1,    -1,   135,   136,   137,   138,   139,    -1,    -1,
      -1,   143,    -1,    -1,   146,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,    -1,
      -1,    -1,    -1,   227,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   236,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
      -1,    -1,    -1,    -1,    -1,    80,    81,    -1,    -1,    -1,
      -1,    86,    -1,    -1,    89,    -1,    -1,    92,    -1,    94,
      -1,    -1,    -1,    -1,    -1,    -1,   101,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,    -1,
     115,    -1,    -1,   118,    -1,    -1,   121,    -1,    -1,    -1,
      -1,    -1,    -1,   128,   129,   130,   131,   132,    -1,    -1,
     135,   136,   137,   138,   139,    -1,    -1,    -1,   143,    -1,
      -1,   146,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,    -1,    -1,    -1,    -1,
     227,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   236,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   187,    -1,    -1,    -1,   191,   192,    -1,    -1,
      -1,   196,   197,   198,   199,   200,    -1,    -1,    -1,   204,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   218,   219,    -1,    -1,    -1,   223,    -1,
      -1,    -1,    -1,   228,    -1,     3,     4,     5,   233,    -1,
     235,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    -1,    -1,    -1,    65,    66,    67,
      -1,    -1,    70,    -1,    72,    73,    74,    -1,    -1,    -1,
      -1,    -1,    80,    81,    82,    83,     3,     4,     5,    -1,
      -1,    -1,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    -1,    -1,    -1,    65,    66,
      67,    -1,    -1,    70,    -1,    72,    73,    74,    -1,    -1,
      -1,    -1,    -1,    80,    81,    82,    83,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,    -1,    -1,    -1,    -1,   227,    -1,    -1,    -1,   187,
     188,   189,   190,   191,   236,    -1,    -1,    -1,   196,   197,
     198,   199,   200,   201,    -1,   203,   204,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     218,   219,    -1,    -1,    -1,   223,    -1,    -1,    -1,    -1,
     228,    -1,    -1,    -1,    -1,   233,    -1,   235,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,    -1,    -1,    -1,    -1,   227,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   236,    -1,    -1,    -1,    -1,
     187,   188,   189,   190,   191,    -1,    -1,    -1,    -1,   196,
     197,   198,   199,   200,   201,    -1,   203,   204,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   218,   219,    -1,    -1,    -1,   223,    -1,    -1,    -1,
      -1,   228,    -1,     3,     4,     5,   233,    -1,   235,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    -1,    -1,    -1,    65,    66,    67,    -1,    -1,
      70,    -1,    72,    73,    74,    -1,    -1,    -1,     3,     4,
      80,    81,    82,    83,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    -1,    -1,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,    53,    54,
      55,    56,   227,    -1,    -1,    -1,    61,    -1,    -1,    -1,
      -1,   236,    -1,    -1,    -1,    -1,    -1,    72,    73,    74,
      -1,    -1,    -1,    -1,    -1,    80,    81,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,    -1,    -1,    -1,    -1,   227,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   236,    -1,    -1,   187,   188,   189,
     190,   191,    -1,    -1,    -1,    -1,   196,   197,   198,   199,
     200,   201,    -1,   203,   204,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   218,   219,
      -1,    -1,    -1,   223,    -1,    -1,    -1,    -1,   228,    -1,
      -1,    -1,    -1,   233,    -1,   235,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
      -1,    -1,    -1,    -1,   227,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   187,   236,    -1,    -1,   191,    -1,    -1,    -1,
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
      -1,    -1,    80,    81,    -1,    -1,    -1,    -1,    86,    -1,
      -1,    89,    -1,    -1,    92,    -1,    94,    -1,    -1,    -1,
      -1,    -1,    -1,   101,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   113,    -1,   115,    -1,    -1,
     118,    -1,    -1,   121,    -1,    -1,    -1,    -1,    -1,    -1,
     128,   129,   130,   131,   132,    -1,    -1,   135,   136,   137,
     138,   139,    -1,    -1,    -1,   143,    -1,    -1,   146,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,    -1,    -1,    -1,    -1,   227,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   236,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   187,
      -1,    -1,    -1,   191,   192,    -1,    -1,    -1,   196,   197,
     198,   199,   200,    -1,    -1,    -1,   204,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     218,   219,    -1,    -1,    -1,   223,     3,     4,     5,    -1,
     228,    -1,     9,    10,    11,   233,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    -1,    -1,    -1,    65,    66,
      67,    -1,    -1,    70,    -1,    72,    73,    74,    -1,    -1,
      -1,     3,     4,    80,    81,    82,    83,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    -1,    -1,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,    53,    54,    55,    56,   227,    -1,    -1,    -1,    61,
      -1,    -1,    -1,    -1,   236,    -1,    -1,    -1,    -1,    -1,
      72,    73,    74,    -1,    -1,    -1,    -1,    -1,    80,    81,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,    -1,    -1,    -1,    -1,   227,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   236,    -1,    -1,
     187,   188,   189,   190,   191,    -1,    -1,    -1,    -1,   196,
     197,   198,   199,   200,   201,    -1,   203,   204,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   218,   219,    -1,    -1,    -1,   223,    -1,    -1,    -1,
      -1,   228,    -1,    -1,    -1,    -1,   233,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,    -1,    -1,    -1,    -1,   227,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   236,   187,    -1,    -1,    -1,   191,
      -1,    -1,    -1,    -1,   196,   197,   198,   199,   200,    -1,
      -1,    -1,   204,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   218,   219,    -1,    -1,
      -1,   223,     3,     4,    -1,    -1,   228,   229,     9,    10,
      11,   233,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    -1,    -1,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,    53,    54,    55,    56,   227,    -1,    -1,    -1,
      61,    -1,    -1,    -1,    -1,   236,    -1,    -1,    -1,    -1,
      -1,    72,    73,    74,    -1,     3,     4,    -1,    -1,    80,
      81,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    -1,
      -1,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,    53,    54,    55,    56,   227,
      -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,   236,    -1,
      -1,    -1,    -1,    -1,    72,    73,    74,    -1,    -1,    -1,
      -1,    -1,    80,    81,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,    -1,    -1,
      -1,    -1,   227,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   236,    -1,    -1,    -1,    -1,   187,    -1,    -1,    -1,
     191,    -1,    -1,    -1,    -1,   196,   197,   198,   199,   200,
      -1,    -1,    -1,   204,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   218,   219,    -1,
      -1,    -1,   223,    -1,    -1,    -1,    -1,   228,    -1,    -1,
     231,    -1,   233,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,    -1,    -1,    -1,
      -1,   227,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   187,
     236,    -1,    -1,   191,    -1,    -1,    -1,    -1,   196,   197,
     198,   199,   200,    -1,    -1,    -1,   204,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     218,   219,    -1,    -1,    -1,   223,     3,     4,    -1,    -1,
     228,   229,     9,    10,    11,   233,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      -1,    -1,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,    53,    54,    55,    56,
     227,    -1,    -1,    -1,    61,    -1,    -1,    -1,   235,    -1,
      -1,    -1,    -1,    -1,    -1,    72,    73,    74,    -1,     3,
       4,    -1,     6,    80,    81,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    -1,    -1,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,    53,
      54,    55,    56,   227,    -1,    -1,    -1,    61,    -1,    -1,
      -1,   235,    -1,    -1,    -1,    -1,    -1,    -1,    72,    73,
      74,    -1,    -1,    -1,    -1,    -1,    80,    81,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,    -1,    -1,    -1,    -1,   227,    -1,   229,    -1,
      -1,    -1,    -1,   234,    -1,    -1,    -1,    -1,    -1,    -1,
     187,    -1,    -1,    -1,   191,    -1,    -1,    -1,    -1,   196,
     197,   198,   199,   200,    -1,    -1,    -1,   204,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   218,   219,    -1,    -1,    -1,   223,    -1,    -1,    -1,
      -1,   228,    -1,    -1,   231,    -1,   233,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,    -1,    -1,    -1,    -1,   227,    -1,    -1,    -1,    -1,
      -1,    -1,   234,   187,    -1,    -1,    -1,   191,    -1,    -1,
      -1,    -1,   196,   197,   198,   199,   200,    -1,    -1,    -1,
     204,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   218,   219,    -1,    -1,    -1,   223,
       3,     4,    -1,     6,   228,    -1,     9,    10,    11,   233,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
      53,    54,    55,    56,   227,    -1,    -1,    -1,    61,    -1,
      -1,   234,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,
      73,    74,    -1,     3,     4,    -1,    -1,    80,    81,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    -1,    -1,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,    53,    54,    55,    56,   227,    -1,    -1,
      -1,    61,    -1,    -1,   234,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    72,    73,    74,    -1,    -1,    -1,    -1,    -1,
      80,    81,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,    -1,    -1,    -1,    -1,
     227,    -1,    -1,    -1,    -1,    -1,    -1,   234,    -1,    -1,
      -1,    -1,    -1,    -1,   187,    -1,    -1,    -1,   191,    -1,
      -1,    -1,    -1,   196,   197,   198,   199,   200,    -1,    -1,
      -1,   204,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   218,   219,    -1,    -1,    -1,
     223,    -1,    -1,    -1,    -1,   228,    -1,    -1,    -1,    -1,
     233,    12,    13,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,    -1,    -1,    -1,
      -1,   227,    -1,    -1,    -1,    -1,    -1,   187,   234,    -1,
      -1,   191,    -1,    -1,    -1,    -1,   196,   197,   198,   199,
     200,    12,    13,    -1,   204,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   218,   219,
      -1,    -1,    -1,   223,    -1,    -1,    -1,    -1,   228,    -1,
      -1,    -1,    -1,   233,    -1,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    -1,    -1,
      -1,   102,   103,   104,    -1,    -1,   107,    -1,    -1,    -1,
      -1,    -1,   113,   114,    -1,    -1,   117,   118,    -1,   120,
     121,   122,    -1,    -1,    -1,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    -1,   140,
      -1,   102,   103,   104,    -1,    -1,   107,    -1,    12,    13,
      -1,    -1,   113,   114,    -1,    -1,   117,   118,    -1,   120,
     121,   122,    -1,   164,   165,   166,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   140,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    12,    13,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   164,   165,   166,    -1,   227,    -1,    -1,
      -1,    -1,    -1,    -1,   234,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,   236,    -1,    -1,   102,   103,
     104,    -1,    -1,   107,    -1,    -1,    -1,    -1,    -1,   113,
     114,    -1,    -1,   117,   118,    -1,   120,   121,   122,    -1,
      -1,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    -1,   236,   140,   102,   103,   104,
      -1,    -1,   107,    -1,    12,    13,    -1,    -1,   113,   114,
      -1,    -1,   117,   118,    -1,   120,   121,   122,    -1,    -1,
     164,   165,   166,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   140,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    12,    13,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   164,
     165,   166,    -1,   227,    -1,    -1,    -1,    -1,    -1,    -1,
     234,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    -1,   236,    -1,   102,   103,   104,    -1,    -1,   107,
      -1,    -1,    -1,    -1,    -1,   113,   114,    -1,    -1,   117,
     118,    -1,   120,   121,   122,    -1,    -1,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      -1,   236,   140,   102,   103,   104,    -1,    -1,   107,    -1,
      12,    13,    -1,    -1,   113,   114,    -1,    -1,   117,   118,
      -1,   120,   121,   122,    -1,    -1,   164,   165,   166,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   140,    -1,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,    -1,    -1,    -1,
      -1,   227,    -1,    -1,    -1,   164,   165,   166,   234,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    -1,   236,    -1,
     102,   103,   104,    -1,    -1,   107,    -1,    -1,    -1,    -1,
      -1,   113,   114,    -1,    -1,   117,   118,    -1,   120,   121,
     122,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     0,     1,
      -1,    -1,     4,    -1,    -1,    -1,    -1,   236,   140,    -1,
      12,    13,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,    -1,    -1,    -1,    -1,
     227,    -1,   164,   165,   166,    -1,    -1,   234,    -1,    -1,
      42,    43,    -1,    -1,    -1,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,    -1,
      62,    63,    64,   227,    -1,    -1,    68,    69,    -1,    71,
     234,    -1,    -1,    75,    76,    -1,    78,    79,    -1,    81,
      -1,    -1,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    -1,    -1,   101,
     102,   103,   104,   105,   236,   107,   108,   109,   110,   111,
     112,   113,   114,   115,    -1,   117,   118,   119,   120,   121,
     122,   123,    -1,   125,   126,   127,   128,   129,   130,   131,
     132,   133,    -1,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,    -1,    -1,     4,
     152,   153,   154,    -1,    -1,    -1,   158,    12,    13,    -1,
      -1,   163,   164,   165,   166,    -1,    -1,   169,    -1,   171,
      -1,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,    -1,    -1,    42,    43,    -1,
      -1,   193,   194,   195,    -1,    -1,    -1,    -1,    -1,    -1,
     202,    -1,   204,    -1,    -1,    -1,    -1,    62,    63,    64,
      -1,    -1,    -1,    68,    69,    -1,    71,    -1,    -1,    -1,
      75,    76,    -1,    78,    79,    -1,    81,    -1,    -1,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    -1,    -1,   101,   102,   103,   104,
     105,    -1,   107,   108,   109,   110,   111,   112,   113,   114,
     115,    -1,   117,   118,   119,   120,   121,   122,   123,    -1,
     125,   126,   127,   128,   129,   130,   131,   132,   133,    -1,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,    -1,    -1,    -1,   152,   153,   154,
      -1,    -1,    -1,   158,    -1,    -1,    -1,    -1,   163,   164,
     165,   166,     4,     5,   169,    -1,   171,    -1,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,    -1,    -1,    -1,    -1,    -1,    -1,   193,   194,
     195,     4,     5,    -1,    -1,    -1,    -1,   202,    -1,   204,
      12,    13,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    -1,    -1,    -1,    -1,    57,    58,    59,    60,    -1,
      -1,    -1,    -1,    65,    66,    67,    -1,    -1,    70,    -1,
      -1,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      82,    83,    -1,    -1,    57,    58,    59,    60,    -1,    -1,
      -1,    -1,    65,    66,    67,    -1,    -1,    70,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    82,
      83,    -1,    -1,    -1,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    -1,    -1,    -1,
     102,   103,   104,    -1,    -1,   107,    -1,    -1,    -1,    -1,
      -1,   113,   114,    -1,    -1,   117,   118,    -1,   120,   121,
     122,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    12,    13,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   140,    -1,
      -1,    -1,   144,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   188,   189,   190,    -1,
      -1,    -1,   164,   165,   166,    -1,    -1,    -1,    -1,   201,
      -1,   203,   204,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   188,   189,   190,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   201,    -1,
     203,   204,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    -1,    -1,    -1,   102,   103,
     104,    -1,    -1,   107,    -1,    -1,    -1,    -1,    -1,   113,
     114,    -1,    -1,   117,   118,    -1,   120,   121,   122,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,    -1,    -1,    -1,   140,   227,    -1,    -1,
      -1,    -1,    -1,    -1,   234,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,    -1,
     164,   165,   166,   227,    -1,    -1,    -1,    -1,    -1,    -1,
     234,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,    -1,    -1,    -1,    -1,   227,
      -1,    -1,    -1,    -1,    -1,    -1,   234,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,    -1,    -1,    -1,    -1,   227,    -1,    -1,    -1,    -1,
      -1,    -1,   234,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,    -1,    -1,    -1,
      -1,   227,    -1,    -1,    -1,    -1,    -1,    -1,   234,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,    -1,    -1,    -1,    -1,   227,    -1,    -1,
      -1,    -1,    -1,    -1,   234,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,    -1,
      -1,    -1,    -1,   227,    -1,    -1,    -1,    -1,    -1,    -1,
     234,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,    -1,    -1,    -1,    -1,   227,
      -1,    -1,    -1,    -1,    -1,    -1,   234,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,    -1,    -1,    -1,    -1,   227,    -1,    -1,    -1,    -1,
      -1,    -1,   234,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,    -1,    -1,    -1,
      -1,   227,    -1,    -1,    -1,    -1,    -1,    -1,   234,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,    -1,    -1,    -1,    -1,   227,    -1,    -1,
      -1,    -1,    -1,    -1,   234,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,    -1,
      -1,    -1,    -1,   227,    -1,    -1,    -1,    -1,    -1,    -1,
     234,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,    -1,    -1,    -1,    -1,   227,
      -1,    -1,    -1,    -1,    -1,    -1,   234,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,    -1,    -1,    -1,    -1,   227,    -1,    -1,    -1,    -1,
      -1,    -1,   234,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,    -1,    -1,    -1,
      -1,   227,    -1,    -1,    -1,    -1,    -1,    -1,   234,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,    -1,    -1,    -1,    -1,   227,    -1,    -1,
      -1,    -1,    -1,    -1,   234,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,    -1,
      -1,    -1,    -1,   227,    -1,    -1,    -1,    -1,    -1,    -1,
     234,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,    -1,    -1,    -1,    -1,   227,
      -1,    -1,    -1,    -1,    -1,    -1,   234,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,    -1,    -1,    -1,    -1,   227,    -1,    -1,    -1,    -1,
      -1,    -1,   234,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,    -1,    -1,    -1,
      -1,   227,    -1,    -1,    -1,    -1,    -1,    -1,   234,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,    -1,    -1,    -1,    -1,   227,    -1,    -1,
      -1,    -1,    -1,    -1,   234,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,    -1,
      -1,    -1,    -1,   227,    -1,    -1,    -1,    -1,    -1,    -1,
     234,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,    -1,    -1,    -1,    -1,   227,
      -1,    -1,    -1,    -1,    -1,    -1,   234,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,    -1,    -1,    -1,    -1,   227,    -1,    -1,    -1,    -1,
      -1,    -1,   234,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,    -1,    -1,    -1,
      -1,   227,    -1,    -1,    -1,    -1,    -1,    -1,   234,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,    -1,    -1,    -1,    -1,   227,    -1,    -1,
      -1,    -1,    -1,    -1,   234,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,    -1,
      -1,    -1,    -1,   227,    -1,    -1,    -1,    -1,    -1,    -1,
     234,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,    -1,    -1,    -1,    -1,   227,
      -1,    -1,    -1,    -1,    -1,    -1,   234,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,    -1,    -1,    -1,    -1,   227,    -1,    -1,    -1,    -1,
      -1,    -1,   234,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,    -1,    -1,    -1,
      -1,   227,    -1,    -1,    -1,    -1,    -1,    -1,   234,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,    -1,    -1,    -1,    -1,   227,    -1,    -1,
      -1,    -1,    -1,    -1,   234,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,    -1,
      -1,    -1,    -1,   227,    -1,    -1,    -1,    -1,    -1,    -1,
     234,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,    -1,    -1,    -1,    -1,   227,
      -1,    -1,    -1,    -1,    -1,    -1,   234,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,    -1,    -1,    -1,    -1,   227,    -1,    -1,    -1,    -1,
      -1,    -1,   234,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,    -1,    -1,    -1,
      -1,   227,    -1,    -1,    -1,    -1,    -1,    -1,   234,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,    -1,    -1,    -1,    -1,   227,    -1,    -1,
      -1,    -1,    -1,    -1,   234,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,    -1,
      -1,    -1,    -1,   227,    -1,    -1,    -1,    -1,    -1,    -1,
     234,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,    -1,    -1,    -1,    -1,   227,
      -1,    -1,    -1,    -1,    -1,    -1,   234,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,    -1,    -1,    -1,    -1,   227,    -1,    -1,    -1,    -1,
      -1,    -1,   234,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,    -1,    -1,    -1,
      -1,   227,    -1,    -1,    -1,    -1,    -1,    -1,   234,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,    -1,    -1,    -1,    -1,   227,    -1,    -1,
      -1,    -1,    -1,    -1,   234,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,    -1,
      -1,    -1,    -1,   227,    -1,    -1,    -1,    -1,    -1,    -1,
     234,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,    -1,    -1,    -1,    -1,   227,
      -1,    -1,    -1,    -1,    -1,    -1,   234,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,    -1,    -1,    -1,    -1,   227,    -1,    -1,    -1,    -1,
      -1,    -1,   234,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,    -1,    -1,    -1,
      -1,   227,    -1,    -1,    -1,    -1,    -1,    -1,   234,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,    -1,    -1,    -1,    -1,   227,    -1,   229,
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
      -1,    -1,    -1,    -1,   227,    -1,   229,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,    -1,    -1,    -1,    -1,   227
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,   239,   240,     6,     0,     4,    12,    13,    42,
      43,    62,    63,    64,    68,    69,    71,    75,    76,    78,
      79,    81,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,   101,   102,   103,
     104,   105,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   117,   118,   119,   120,   121,   122,   123,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   152,   153,   154,   158,   163,   164,   165,   166,   169,
     171,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   193,   194,   195,   202,   204,
     241,   243,   244,   264,   283,   284,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   311,   313,   314,   320,   321,
     322,   323,   327,   347,   348,     3,     4,     5,     9,    10,
      11,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    65,    66,    67,    70,    72,    73,    74,    80,
      82,    83,   180,   187,   188,   189,   190,   191,   196,   197,
     198,   199,   200,   201,   203,   218,   219,   223,   228,   230,
     232,   233,   235,   237,   262,   324,   325,   327,   342,   343,
     347,   348,    13,    92,   228,   228,     6,   235,     6,     6,
       6,     6,   228,     6,     6,   230,   230,     4,   329,   347,
     348,   228,   230,   262,   262,   228,   235,   228,   228,     4,
     228,   235,   228,   228,     4,   228,   235,   228,   228,   228,
     228,   228,   228,   228,   228,   228,   228,   106,    92,    92,
       6,   235,    86,    89,    92,   228,     4,    37,    38,    39,
      40,    41,    86,    89,    92,    94,   113,   118,   121,   192,
     219,   228,   235,   284,   295,   311,   313,   324,   335,   337,
     347,   348,   228,   235,    92,    92,   113,    89,    92,    94,
      94,    86,    89,    92,    94,    89,    92,    94,    89,    92,
     228,    89,   169,   185,   186,   235,   218,   219,   228,   235,
     332,   333,   332,   235,    86,    89,    92,   235,   332,     4,
      86,    90,    96,    97,    99,   100,   117,   228,    92,    94,
      92,    89,     4,   180,   235,   348,     4,     6,    86,    89,
      92,    89,    92,     4,     4,     4,     5,   228,   335,   336,
       4,   228,   228,   228,     4,   235,   339,   348,     4,   228,
     228,   228,     6,     6,   230,   343,   348,   228,     4,   343,
       5,   235,     5,   235,     4,   324,   347,   230,   228,   235,
       6,   228,   235,     6,   228,   230,   237,   262,     7,   205,
     206,   207,   208,   225,   226,   260,   261,     4,   228,   230,
     262,   262,   262,   262,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   228,   228,   228,   262,   262,
     262,   262,   228,   262,   262,   262,   262,   262,   262,   228,
     262,   262,   262,   262,     7,   228,   228,   228,   262,   262,
     228,   228,   230,   324,   324,   324,   229,   324,   231,   324,
       4,   169,   170,   348,     4,   284,   285,   286,   235,   235,
       6,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   227,   235,     6,   228,   230,
     232,   261,     6,   324,     4,   342,   343,   347,   348,   342,
     324,   342,   346,   266,   271,   328,     8,   343,   348,   324,
     219,   324,   337,   338,   324,   324,   228,   324,   338,   324,
     324,   228,   324,   338,   324,   324,   324,   324,   324,   324,
     342,   324,   324,   324,   335,   228,   235,   338,   336,   336,
     336,   342,   228,   230,   262,   228,   230,   262,   262,   262,
     262,     5,   172,   235,     5,   172,     5,   172,     5,   172,
     113,    86,    89,    92,    94,   262,   235,   324,   337,   324,
     236,   338,     8,   220,   228,   230,   262,   232,   324,   338,
     228,   228,   228,   335,   336,   336,   336,   228,   228,   228,
     228,   228,   228,   335,   228,   335,   228,   335,   235,   235,
     324,     4,   335,   339,   235,   235,   332,   332,   332,   324,
     324,   218,   219,   235,   235,   332,   235,   235,   235,   218,
     219,   228,   286,   332,   235,   228,   235,   228,   228,   228,
     228,   228,   228,   228,   324,   336,   336,   336,   228,     4,
     230,   230,   286,     6,     6,   235,   235,   235,   336,   336,
     230,   230,   230,   324,     6,     6,   324,   324,   324,   232,
     324,   235,   172,   324,   324,   324,   324,     6,     6,   235,
       6,   286,     6,   286,   228,   230,   235,   228,   230,   342,
     324,   286,   335,   335,   229,   324,   231,   324,   235,   235,
     343,   335,     6,   230,   324,   324,   324,   324,   324,   324,
     324,   324,   324,   324,   324,   324,   324,   324,   324,   324,
     324,   324,   324,   324,   324,   324,   324,   324,   346,   342,
     346,   342,   342,   342,   342,   342,   342,   342,   335,   342,
     342,   324,   342,   342,   342,   346,   342,   324,   233,   345,
     348,   343,   324,   342,   342,   342,   342,   342,   348,   343,
     348,     7,   208,   260,   229,     7,   208,   260,   231,     7,
     260,   261,   232,     7,   262,   236,    86,    89,    92,    94,
     113,   118,   122,   283,   324,   338,   324,   324,   324,   324,
     324,   324,   324,   324,   324,   324,   324,   324,   324,   324,
     324,   245,   324,   324,     4,   330,     6,   228,   230,   229,
     234,   228,   230,   232,   229,   234,   234,   229,   234,   231,
     234,   265,   231,   265,   235,   331,     8,   234,   234,   229,
     220,   234,   236,   229,   229,   324,   229,   236,   229,   229,
     324,   229,   236,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,     7,   324,   324,   236,     6,     6,     6,
     229,   324,   324,   229,   231,   235,   263,   235,   324,   337,
     235,   337,   348,   324,   324,   342,   324,    62,   324,    62,
      62,    62,     5,   235,     5,   235,     5,   235,     5,   235,
     337,   338,   229,   236,   324,   235,   324,   337,   324,   324,
     235,   263,   330,   229,   236,   324,   324,   324,     7,     7,
     317,   317,   324,   277,   324,   343,   278,   324,   343,   279,
     324,   343,   280,   324,   343,   324,     6,   324,     6,   324,
       6,   338,   338,   235,   229,     6,   235,   286,   286,   234,
     234,   234,   332,   332,   285,   285,   234,   324,   324,   324,
     324,   236,   299,   234,   286,   324,   324,   324,   324,   324,
     324,   324,   324,   324,   229,     7,   318,     6,     7,   324,
       6,   324,   324,   236,   338,   338,   338,     6,     6,   324,
     324,   324,   229,   229,   229,   229,   169,   234,   286,   235,
       8,   229,   229,   231,   338,   236,   236,   286,   231,   229,
     144,   312,   229,   234,   236,     7,   208,   260,   229,     7,
     208,   260,   231,   324,   338,     6,     6,   324,   229,   231,
     263,   263,   263,   263,   263,   263,   263,   263,   263,   263,
     263,   234,   263,   263,   263,   263,   263,   263,   263,   234,
     234,   234,   263,   234,   263,   263,   229,   229,   234,   263,
     263,   234,   263,   234,   234,   234,   234,   263,   263,   263,
     229,   263,   326,   324,   263,     8,   344,     6,   234,   234,
     229,   234,   263,   234,   263,   229,   229,   231,    44,    44,
     335,     7,   260,   261,    44,    44,   335,   232,   260,   261,
     343,   324,     6,     4,     4,   235,   340,   263,   235,   235,
     235,   235,   228,   113,    89,    92,    94,   236,   236,     8,
       4,   159,   160,   161,   162,   236,   248,   252,   255,   257,
     258,   229,   231,   261,   324,   324,     6,   215,   242,   338,
     324,   324,   330,     6,   338,   324,     6,   342,     6,   348,
       6,   342,   348,   230,   348,   324,   343,     7,   324,   337,
     172,     7,     7,   229,     7,   172,     7,     7,   229,     7,
     172,     7,     7,     7,     7,     7,     7,     7,     7,     7,
     324,   229,   236,   235,     6,   229,   231,   338,   338,   229,
     338,   231,   231,   234,   234,   263,   234,   235,   236,   235,
     235,   235,   338,   338,   338,   338,   263,   236,     7,     8,
     338,   229,   231,   338,     7,   235,   229,   229,   229,   324,
     335,     4,   316,     6,   229,   229,   234,   229,   234,   229,
     234,   229,   234,   229,   229,   229,   236,   236,   338,   232,
     286,   236,   236,   332,   324,   324,   236,   236,   324,   332,
     234,   234,   234,   124,   124,   141,   149,   150,   151,   155,
     156,   309,   310,   332,   236,   296,   229,   236,   229,   229,
     229,   229,   229,   229,   229,     7,   324,     6,   324,   229,
     231,   231,   236,   236,   236,   231,   231,   234,     7,     7,
       7,   232,   324,   236,   324,   324,     7,   232,   236,   236,
       7,     6,   324,   236,   235,   335,     6,    44,    44,   335,
     260,   261,    44,    44,   335,   260,   261,   236,   236,   231,
     261,   232,   261,   342,   324,   324,   324,   324,   338,   342,
     324,   335,   342,   342,   342,   273,     8,   275,   324,   342,
     342,   324,   262,   262,     6,   324,     6,   262,   262,     6,
       4,   169,   170,   324,     6,     6,     6,     7,   230,   339,
     341,     6,   338,   338,   338,   338,   324,   228,   228,   228,
     228,   263,   324,   249,   228,   228,   235,   259,     6,   261,
     261,   229,   231,   215,   342,   229,   229,   231,   229,   234,
       7,   228,   230,   236,   324,   263,   263,   332,    92,    94,
     335,   335,     7,   335,    92,    94,   335,   335,     7,   335,
      94,   335,   335,   335,   335,   335,   335,   335,   335,   335,
       6,     7,     7,   338,   232,   236,   236,   236,   324,   324,
     324,   324,   324,   324,   324,   236,   236,   236,   236,   335,
     324,   236,   236,   335,   338,     7,     7,     7,   124,   315,
       6,     7,   260,   324,   260,   324,   260,   324,   260,   324,
       7,     7,     7,     7,     7,   236,     4,   236,   234,   234,
     234,   236,   236,   332,   332,   332,   104,     4,     6,   324,
     235,     6,   228,     6,   157,     6,   157,   236,   310,   234,
     309,     7,     6,     7,     7,     7,     7,     7,     7,     7,
     335,     6,   235,     6,     6,     6,    92,     7,     6,     6,
     324,   335,   335,   335,     4,   234,     8,     8,   229,     4,
       4,   234,   235,     6,   235,   335,   236,   262,   262,     6,
     324,     6,   262,   262,     6,   324,     6,   263,     6,     4,
       6,   263,   263,   263,   263,   263,   234,   234,   263,   229,
     263,   263,   234,   234,   263,   274,   233,   234,   263,   276,
     229,   229,   263,   263,   263,   346,   346,     6,   263,   346,
     346,     7,   260,   261,   232,     7,     6,   339,   324,   234,
     236,   236,   236,   236,   236,   229,   324,   324,   324,   324,
     260,   228,   324,   324,   334,   335,   235,   232,     6,     6,
     242,     6,   324,   235,   324,   343,   229,   231,   273,     6,
       6,     6,   235,   235,   117,   282,   282,   335,     6,   235,
     235,     6,     6,   335,   172,   281,   235,     6,     6,     6,
       6,     6,     6,     6,     6,     6,     5,   335,   236,     4,
     263,   229,   231,   234,   234,   234,   234,   234,   234,   234,
       6,   263,     6,   236,   335,   335,   335,     4,     6,   335,
     335,   335,   335,   335,   335,   335,   335,   235,   235,     7,
       6,     7,   324,   324,   324,   235,   235,   234,   236,   234,
     236,   234,   236,   235,   230,     6,   324,   335,   324,     6,
       6,   324,   332,   236,     5,   335,   235,   235,   235,   235,
     235,   235,   235,   335,     6,   338,   235,   324,   231,     6,
       6,   168,   324,   324,   324,     6,     6,     7,   343,   286,
     286,   234,     6,   263,   346,   346,     6,   263,   346,   346,
       6,   260,   261,   342,   324,   342,     4,   324,     4,   184,
       6,   263,   263,     6,   263,   263,   343,   324,     6,     4,
     340,     6,   231,   339,     6,     6,     6,     6,   229,   229,
     229,   229,   335,   246,   324,   234,   234,   234,   236,   247,
     324,     4,   342,   234,   335,   343,     7,     7,   231,   324,
     324,   332,     6,     6,     6,   324,   324,     6,    90,     6,
     324,     5,     6,   235,   324,   324,   324,   324,   324,   324,
     324,   235,     6,   281,     6,   324,     6,     6,     6,     6,
       6,     6,     4,     6,     6,   338,   338,   324,   324,   343,
     236,   229,   234,   236,   285,   285,   332,     6,   300,   332,
       6,   301,   332,     6,   302,   324,   324,   236,   234,   229,
     236,   234,     6,     6,   334,   332,   332,   332,   332,   332,
     219,   332,     6,   236,   324,     6,     6,   335,   234,   236,
       8,   236,   229,   235,   324,   343,   234,   312,   312,   335,
       6,   263,   263,     6,   263,   263,   335,   229,   263,   263,
     235,   335,   343,   235,   324,   343,   343,     6,     6,     6,
       6,     6,     6,     7,     6,   232,     6,   229,   234,   324,
     324,   335,   235,   234,   236,     6,   324,   267,   270,   235,
     235,   236,   236,   236,   236,   235,   236,     5,   334,   263,
     263,   234,   234,   234,   234,   234,   324,     6,   235,   236,
     236,   235,     6,     6,   235,   324,   236,   236,   234,   235,
     234,   235,   234,   235,   236,   231,     6,   335,     7,   235,
     324,   236,   234,   234,   234,   234,   234,   234,     6,   236,
     167,   324,   324,   338,     6,     6,   343,   236,   236,   236,
       6,     6,     6,     6,     6,   272,   324,   337,   346,   339,
     170,   250,   324,   234,   234,   334,   324,     6,   234,   273,
     275,   335,   335,     6,     6,     6,     6,   324,     6,     6,
     236,   324,   324,   324,   324,   324,   236,   334,   128,   129,
     134,   319,   128,   129,   319,   338,   285,   234,   236,   324,
     332,   309,   324,   332,   309,   324,   332,   309,     6,   234,
     236,   335,   286,   236,     6,   338,   332,   332,   332,   332,
     332,   324,   236,   236,   236,   229,   235,     6,   234,   236,
       7,     7,   236,     6,   235,   324,   324,   236,   324,   236,
     236,   269,   268,   236,   235,   234,   234,   234,   234,   234,
     236,   235,   332,   335,     6,   235,   332,     6,   236,   236,
     324,   236,   234,   236,   236,   234,   236,   236,   234,   236,
     335,     6,   124,   236,   297,   235,   236,   234,   234,   234,
     234,   234,     6,     6,     6,   286,   324,   343,   348,   247,
     229,   234,     6,   235,   234,   273,   273,   324,   324,   324,
     324,   324,   324,     6,   332,     6,   332,     6,     6,   236,
       6,   303,   324,     6,     6,   304,   324,     6,     6,   305,
     324,     6,   236,   324,   309,   286,     6,   338,   338,   338,
     338,   332,   338,   312,     7,   228,   236,   253,   324,   334,
     324,   236,   236,   234,   234,   234,   234,   234,   234,   234,
     234,   235,   236,   235,   236,   235,   236,     6,     6,   236,
     236,   298,   236,   236,   236,   236,   234,   236,   236,   343,
     229,     6,   235,   229,   236,   236,   324,   324,   324,   324,
     324,   324,   332,   332,   309,     6,   306,   309,     6,   307,
     309,     6,   308,   309,     6,     6,     6,     6,   338,     6,
       6,   251,   342,   256,   235,     6,   236,   263,   234,   234,
     234,   234,   234,   234,   236,   235,   236,   235,   236,   235,
     236,   236,   234,   236,   235,   334,     6,   324,   324,   324,
     324,   324,   324,     6,   309,     6,   309,     6,   309,     6,
     342,     6,   254,   342,   236,   236,   236,   236,   236,   236,
     236,   236,   236,   236,   234,   236,     6,     6,     6,     6,
       6,     6,   342,     6
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
#line 221 "Gmsh.y"
    { yyerrok; return 1; ;}
    break;

  case 6:
#line 232 "Gmsh.y"
    { return 1; ;}
    break;

  case 7:
#line 233 "Gmsh.y"
    { return 1; ;}
    break;

  case 8:
#line 234 "Gmsh.y"
    { return 1; ;}
    break;

  case 9:
#line 236 "Gmsh.y"
    {
      // FIXME: when changing to OpenCASCADE, get maxTags from GEO_Internals and
      // add that info in OCC_Internals - same in the other direction
      factory = (yyvsp[(3) - (5)].c);
      if(factory == "OpenCASCADE" && !GModel::current()->getOCCInternals())
        GModel::current()->createOCCInternals();
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 10:
#line 244 "Gmsh.y"
    { return 1; ;}
    break;

  case 11:
#line 245 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 12:
#line 246 "Gmsh.y"
    { return 1; ;}
    break;

  case 13:
#line 247 "Gmsh.y"
    { return 1; ;}
    break;

  case 14:
#line 248 "Gmsh.y"
    { return 1; ;}
    break;

  case 15:
#line 249 "Gmsh.y"
    { return 1; ;}
    break;

  case 16:
#line 250 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 17:
#line 251 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 18:
#line 252 "Gmsh.y"
    { return 1; ;}
    break;

  case 19:
#line 253 "Gmsh.y"
    { return 1; ;}
    break;

  case 20:
#line 254 "Gmsh.y"
    { return 1; ;}
    break;

  case 21:
#line 255 "Gmsh.y"
    { return 1; ;}
    break;

  case 22:
#line 256 "Gmsh.y"
    { return 1; ;}
    break;

  case 23:
#line 257 "Gmsh.y"
    { return 1; ;}
    break;

  case 24:
#line 258 "Gmsh.y"
    { return 1; ;}
    break;

  case 25:
#line 259 "Gmsh.y"
    { return 1; ;}
    break;

  case 26:
#line 264 "Gmsh.y"
    {
      (yyval.c) = (char*)"w";
    ;}
    break;

  case 27:
#line 268 "Gmsh.y"
    {
      (yyval.c) = (char*)"a";
    ;}
    break;

  case 28:
#line 275 "Gmsh.y"
    {
      Msg::Direct((yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 29:
#line 280 "Gmsh.y"
    {
      Msg::Error((yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 30:
#line 285 "Gmsh.y"
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
#line 299 "Gmsh.y"
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
#line 312 "Gmsh.y"
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
#line 325 "Gmsh.y"
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
#line 353 "Gmsh.y"
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
#line 367 "Gmsh.y"
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
#line 380 "Gmsh.y"
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
#line 393 "Gmsh.y"
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
#line 411 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData = new PViewDataList();
#endif
    ;}
    break;

  case 44:
#line 425 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(1) - (1)].d)); ;}
    break;

  case 45:
#line 427 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(3) - (3)].d)); ;}
    break;

  case 46:
#line 432 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(1) - (1)].d)); ;}
    break;

  case 47:
#line 434 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(3) - (3)].d)); ;}
    break;

  case 48:
#line 439 "Gmsh.y"
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
#line 543 "Gmsh.y"
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
#line 553 "Gmsh.y"
    {
#if defined(HAVE_POST)
      if(ViewValueList) (*ViewNumList)++;
#endif
    ;}
    break;

  case 51:
#line 562 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[(1) - (1)].c)[i]);
#endif
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 52:
#line 569 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[(3) - (3)].c)[i]);
#endif
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 53:
#line 579 "Gmsh.y"
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
#line 588 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->NbT2++;
#endif
    ;}
    break;

  case 55:
#line 597 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[(1) - (1)].c)[i]);
#endif
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 56:
#line 604 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[(3) - (3)].c)[i]);
#endif
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 57:
#line 614 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->T3D.push_back((yyvsp[(3) - (10)].d)); ViewData->T3D.push_back((yyvsp[(5) - (10)].d));
      ViewData->T3D.push_back((yyvsp[(7) - (10)].d)); ViewData->T3D.push_back((yyvsp[(9) - (10)].d));
      ViewData->T3D.push_back(ViewData->T3C.size());
#endif
    ;}
    break;

  case 58:
#line 622 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->NbT3++;
#endif
    ;}
    break;

  case 59:
#line 632 "Gmsh.y"
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
#line 651 "Gmsh.y"
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
#line 670 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewValueList = &ViewData->Time;
#endif
    ;}
    break;

  case 62:
#line 676 "Gmsh.y"
    {
    ;}
    break;

  case 63:
#line 683 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 64:
#line 684 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 65:
#line 685 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 66:
#line 686 "Gmsh.y"
    { (yyval.i) = 3; ;}
    break;

  case 67:
#line 687 "Gmsh.y"
    { (yyval.i) = 4; ;}
    break;

  case 68:
#line 691 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 69:
#line 692 "Gmsh.y"
    { (yyval.i) = -1; ;}
    break;

  case 70:
#line 698 "Gmsh.y"
    { (yyval.c) = (char*)"("; ;}
    break;

  case 71:
#line 698 "Gmsh.y"
    { (yyval.c) = (char*)"["; ;}
    break;

  case 72:
#line 699 "Gmsh.y"
    { (yyval.c) = (char*)")"; ;}
    break;

  case 73:
#line 699 "Gmsh.y"
    { (yyval.c) = (char*)"]"; ;}
    break;

  case 77:
#line 709 "Gmsh.y"
    {
      Msg::SetOnelabNumber((yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].d));
      Free((yyvsp[(3) - (7)].c));
    ;}
    break;

  case 78:
#line 714 "Gmsh.y"
    {
      Msg::SetOnelabString((yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].c));
      Free((yyvsp[(3) - (7)].c));
      Free((yyvsp[(5) - (7)].c));
    ;}
    break;

  case 79:
#line 720 "Gmsh.y"
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

  case 80:
#line 782 "Gmsh.y"
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

  case 81:
#line 799 "Gmsh.y"
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
#line 828 "Gmsh.y"
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

  case 83:
#line 857 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    ;}
    break;

  case 84:
#line 862 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    ;}
    break;

  case 85:
#line 867 "Gmsh.y"
    {
      incrementVariable((yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].i));
      Free((yyvsp[(1) - (6)].c));
    ;}
    break;

  case 86:
#line 872 "Gmsh.y"
    {
      incrementVariable((yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].i));
      Free((yyvsp[(1) - (6)].c));
    ;}
    break;

  case 87:
#line 877 "Gmsh.y"
    {
      assignVariables((yyvsp[(1) - (9)].c), (yyvsp[(4) - (9)].l), (yyvsp[(7) - (9)].i), (yyvsp[(8) - (9)].l));
      Free((yyvsp[(1) - (9)].c));
      List_Delete((yyvsp[(4) - (9)].l));
      List_Delete((yyvsp[(8) - (9)].l));
    ;}
    break;

  case 88:
#line 884 "Gmsh.y"
    {
      assignVariables((yyvsp[(1) - (9)].c), (yyvsp[(4) - (9)].l), (yyvsp[(7) - (9)].i), (yyvsp[(8) - (9)].l));
      Free((yyvsp[(1) - (9)].c));
      List_Delete((yyvsp[(4) - (9)].l));
      List_Delete((yyvsp[(8) - (9)].l));
    ;}
    break;

  case 89:
#line 894 "Gmsh.y"
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
#line 923 "Gmsh.y"
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

  case 91:
#line 952 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    ;}
    break;

  case 92:
#line 957 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    ;}
    break;

  case 93:
#line 962 "Gmsh.y"
    {
      incrementVariable((yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].i));
      Free((yyvsp[(1) - (6)].c));
    ;}
    break;

  case 94:
#line 967 "Gmsh.y"
    {
      incrementVariable((yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].i));
      Free((yyvsp[(1) - (6)].c));
    ;}
    break;

  case 95:
#line 975 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[(1) - (4)].c)] = std::vector<std::string>(1, (yyvsp[(3) - (4)].c));
      Free((yyvsp[(1) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 96:
#line 984 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[(1) - (8)].c)] = std::vector<std::string>();
      Free((yyvsp[(1) - (8)].c));
    ;}
    break;

  case 97:
#line 990 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[(1) - (8)].c)] = std::vector<std::string>();
      Free((yyvsp[(1) - (8)].c));
    ;}
    break;

  case 98:
#line 996 "Gmsh.y"
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
#line 1009 "Gmsh.y"
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

  case 100:
#line 1022 "Gmsh.y"
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
#line 1037 "Gmsh.y"
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

  case 102:
#line 1054 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[(1) - (8)].c)] = std::vector<std::string>();
      Free((yyvsp[(1) - (8)].c));
    ;}
    break;

  case 103:
#line 1060 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[(1) - (8)].c)] = std::vector<std::string>();
      Free((yyvsp[(1) - (8)].c));
    ;}
    break;

  case 104:
#line 1066 "Gmsh.y"
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
#line 1079 "Gmsh.y"
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

  case 106:
#line 1092 "Gmsh.y"
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
#line 1107 "Gmsh.y"
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

  case 108:
#line 1124 "Gmsh.y"
    {
      std::string tmp((yyvsp[(5) - (6)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (6)].c), 0, (yyvsp[(3) - (6)].c), tmp);
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 109:
#line 1131 "Gmsh.y"
    {
      std::string tmp((yyvsp[(8) - (9)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (9)].c), (int)(yyvsp[(3) - (9)].d), (yyvsp[(6) - (9)].c), tmp);
      Free((yyvsp[(1) - (9)].c)); Free((yyvsp[(6) - (9)].c)); Free((yyvsp[(8) - (9)].c));
    ;}
    break;

  case 110:
#line 1140 "Gmsh.y"
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

  case 111:
#line 1159 "Gmsh.y"
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

  case 112:
#line 1178 "Gmsh.y"
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(3) - (5)].c), d)){
	d += (yyvsp[(4) - (5)].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (5)].c), 0, (yyvsp[(3) - (5)].c), d);
      }
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 113:
#line 1188 "Gmsh.y"
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[(1) - (8)].c), (int)(yyvsp[(3) - (8)].d), (yyvsp[(6) - (8)].c), d)){
	d += (yyvsp[(7) - (8)].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (8)].c), (int)(yyvsp[(3) - (8)].d), (yyvsp[(6) - (8)].c), d);
      }
      Free((yyvsp[(1) - (8)].c)); Free((yyvsp[(6) - (8)].c));
    ;}
    break;

  case 114:
#line 1200 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (8)].c), 0, (yyvsp[(5) - (8)].c), (yyvsp[(7) - (8)].u));
      Free((yyvsp[(1) - (8)].c)); Free((yyvsp[(5) - (8)].c));
    ;}
    break;

  case 115:
#line 1206 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (11)].c), (int)(yyvsp[(3) - (11)].d), (yyvsp[(8) - (11)].c), (yyvsp[(10) - (11)].u));
      Free((yyvsp[(1) - (11)].c)); Free((yyvsp[(8) - (11)].c));
    ;}
    break;

  case 116:
#line 1214 "Gmsh.y"
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

  case 117:
#line 1235 "Gmsh.y"
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

  case 118:
#line 1258 "Gmsh.y"
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

  case 119:
#line 1269 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      if(!GModel::current()->getFields()->newField((int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c)))
	yymsg(0, "Cannot create field %i of type '%s'", (int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c));
#endif
      Free((yyvsp[(6) - (7)].c));
    ;}
    break;

  case 120:
#line 1277 "Gmsh.y"
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

  case 121:
#line 1299 "Gmsh.y"
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

  case 122:
#line 1322 "Gmsh.y"
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

  case 123:
#line 1360 "Gmsh.y"
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

  case 124:
#line 1381 "Gmsh.y"
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

  case 125:
#line 1393 "Gmsh.y"
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

  case 129:
#line 1411 "Gmsh.y"
    {
      std::string key((yyvsp[(3) - (3)].c));
      std::vector<double> val(1, 0.);
      if(!gmsh_yysymbols.count(key)){
        gmsh_yysymbols[key].value = val;
      }
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 130:
#line 1420 "Gmsh.y"
    {
      std::string key((yyvsp[(3) - (5)].c));
      std::vector<double> val(1, (yyvsp[(5) - (5)].d));
      if(!gmsh_yysymbols.count(key)){
        gmsh_yysymbols[key].value = val;
      }
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 131:
#line 1429 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 132:
#line 1431 "Gmsh.y"
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

  case 133:
#line 1449 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 134:
#line 1451 "Gmsh.y"
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
#line 1467 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 136:
#line 1469 "Gmsh.y"
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

  case 137:
#line 1485 "Gmsh.y"
    {
      std::string key((yyvsp[(3) - (5)].c)), val((yyvsp[(5) - (5)].c));
      if(!gmsh_yystringsymbols.count(key)){
        gmsh_yystringsymbols[key] = std::vector<std::string>(1, val);
      }
      Free((yyvsp[(3) - (5)].c));
      Free((yyvsp[(5) - (5)].c));
    ;}
    break;

  case 138:
#line 1494 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 139:
#line 1496 "Gmsh.y"
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

  case 141:
#line 1510 "Gmsh.y"
    {
      std::string name((yyvsp[(3) - (3)].c));
      Msg::UndefineOnelabParameter(name);
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 142:
#line 1518 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(doubleXstring));
      doubleXstring v = {(yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].c)};
      List_Add((yyval.l), &v);
    ;}
    break;

  case 143:
#line 1524 "Gmsh.y"
    {
      doubleXstring v = {(yyvsp[(3) - (5)].d), (yyvsp[(5) - (5)].c)};
      List_Add((yyval.l), &v);
    ;}
    break;

  case 144:
#line 1529 "Gmsh.y"
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

  case 147:
#line 1560 "Gmsh.y"
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

  case 148:
#line 1571 "Gmsh.y"
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

  case 149:
#line 1586 "Gmsh.y"
    {
      std::string key((yyvsp[(2) - (3)].c));
      std::string val((yyvsp[(3) - (3)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(2) - (3)].c));
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 152:
#line 1602 "Gmsh.y"
    {
      std::string key((yyvsp[(2) - (3)].c));
      double val = (yyvsp[(3) - (3)].d);
      floatOptions[key].push_back(val);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 153:
#line 1610 "Gmsh.y"
    {
      std::string key((yyvsp[(2) - (3)].c));
      std::string val((yyvsp[(3) - (3)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(2) - (3)].c));
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 154:
#line 1619 "Gmsh.y"
    {
      std::string key("Macro");
      std::string val((yyvsp[(3) - (3)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 155:
#line 1627 "Gmsh.y"
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

  case 156:
#line 1645 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    ;}
    break;

  case 157:
#line 1649 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[(1) - (1)].c)), 0, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 158:
#line 1655 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (3)].c)), 0, (yyvsp[(3) - (3)].d));
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 159:
#line 1663 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    ;}
    break;

  case 160:
#line 1667 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[(1) - (1)].c)), 1, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 161:
#line 1673 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (3)].c)), 1, (yyvsp[(3) - (3)].d));
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 162:
#line 1681 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    ;}
    break;

  case 163:
#line 1685 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[(1) - (1)].c)), 2, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 164:
#line 1691 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (3)].c)), 2, (yyvsp[(3) - (3)].d));
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 165:
#line 1699 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    ;}
    break;

  case 166:
#line 1703 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[(1) - (1)].c)), 3, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 167:
#line 1709 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (3)].c)), 3, (yyvsp[(3) - (3)].d));
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 168:
#line 1717 "Gmsh.y"
    {
      (yyval.i) = -1;
    ;}
    break;

  case 169:
#line 1721 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(4) - (5)].d);
    ;}
    break;

  case 170:
#line 1727 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = 0.;
    ;}
    break;

  case 171:
#line 1731 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 172:
#line 1738 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      double x = CTX::instance()->geom.scalingFactor * (yyvsp[(6) - (7)].v)[0];
      double y = CTX::instance()->geom.scalingFactor * (yyvsp[(6) - (7)].v)[1];
      double z = CTX::instance()->geom.scalingFactor * (yyvsp[(6) - (7)].v)[2];
      double lc = CTX::instance()->geom.scalingFactor * (yyvsp[(6) - (7)].v)[3];
      if(lc == 0.) lc = MAX_LC; // no mesh size given at the point
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
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

  case 173:
#line 1759 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(6) - (7)].l), tags);
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
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

  case 174:
#line 1773 "Gmsh.y"
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
#line 1787 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (8)].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(6) - (8)].l), tags);
      std::vector<double> param; ListOfDouble2Vector((yyvsp[(6) - (8)].l), param);
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
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

  case 176:
#line 1822 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (8)].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(6) - (8)].l), tags);
      std::vector<double> param; ListOfDouble2Vector((yyvsp[(6) - (8)].l), param);
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
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

  case 177:
#line 1860 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(6) - (7)].l), tags);
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
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
#line 1874 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(6) - (7)].l), tags);
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
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
#line 1889 "Gmsh.y"
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
#line 1908 "Gmsh.y"
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
#line 1917 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(6) - (7)].l), tags);
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
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
#line 1931 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(7) - (8)].l), tags);
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
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
#line 1946 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(7) - (8)].l), tags);
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
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
#line 1960 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (8)].d);
      std::vector<int> wires; ListOfDouble2Vector((yyvsp[(6) - (8)].l), wires);
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
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
#line 1979 "Gmsh.y"
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
#line 1989 "Gmsh.y"
    {
      myGmshSurface = 0;
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 187:
#line 1995 "Gmsh.y"
    {
      myGmshSurface = gmshSurface::getSurface((int)(yyvsp[(3) - (4)].d));
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 188:
#line 2001 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (10)].d);
      myGmshSurface = gmshParametricSurface::NewParametricSurface(num, (yyvsp[(7) - (10)].c), (yyvsp[(8) - (10)].c), (yyvsp[(9) - (10)].c));
      (yyval.s).Type = 0;
      (yyval.s).Num = num;
    ;}
    break;

  case 189:
#line 2008 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(6) - (7)].l), tags);
      std::vector<double> param; ListOfDouble2Vector((yyvsp[(6) - (7)].l), param);
      (yyval.s).Type = 0;
      if(param.size() == 4 || param.size() == 5){
        if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
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
#line 2035 "Gmsh.y"
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
#line 2050 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      std::vector<double> param; ListOfDouble2Vector((yyvsp[(6) - (7)].l), param);
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
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
#line 2070 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      std::vector<double> param; ListOfDouble2Vector((yyvsp[(6) - (7)].l), param);
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
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
#line 2091 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      std::vector<double> param; ListOfDouble2Vector((yyvsp[(6) - (7)].l), param);
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
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
#line 2112 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      std::vector<double> param; ListOfDouble2Vector((yyvsp[(6) - (7)].l), param);
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
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
#line 2133 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      std::vector<double> param; ListOfDouble2Vector((yyvsp[(6) - (7)].l), param);
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
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
#line 2155 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      std::vector<double> param; ListOfDouble2Vector((yyvsp[(6) - (7)].l), param);
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
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
#line 2177 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      std::vector<double> param; ListOfDouble2Vector((yyvsp[(6) - (7)].l), param);
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
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
#line 2198 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      std::vector<double> param; ListOfDouble2Vector((yyvsp[(6) - (7)].l), param);
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
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
#line 2221 "Gmsh.y"
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
#line 2231 "Gmsh.y"
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
#line 2251 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(7) - (8)].l), tags);
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
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
#line 2266 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(6) - (7)].l), tags);
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
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
#line 2280 "Gmsh.y"
    {
      yymsg(1, "'Complex Volume' command is deprecated: use 'Volume' instead");
      int num = (int)(yyvsp[(4) - (8)].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(7) - (8)].l), tags);
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
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
#line 2295 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      std::vector<int> wires, out[4]; ListOfDouble2Vector((yyvsp[(6) - (7)].l), wires);
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
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
#line 2310 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].d);
      std::vector<int> wires, out[4]; ListOfDouble2Vector((yyvsp[(7) - (8)].l), wires);
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
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
#line 2325 "Gmsh.y"
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
#line 2334 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].i);
      int op = (yyvsp[(6) - (8)].i);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(7) - (8)].l), tags);
      GModel::current()->getGEOInternals()->modifyPhysicalGroup(0, num, op, tags);
      List_Delete((yyvsp[(7) - (8)].l));
      (yyval.s).Type = MSH_PHYSICAL_POINT;
      (yyval.s).Num = num;
    ;}
    break;

  case 208:
#line 2344 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].i);
      int op = (yyvsp[(6) - (8)].i);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(7) - (8)].l), tags);
      GModel::current()->getGEOInternals()->modifyPhysicalGroup(1, num, op, tags);
      List_Delete((yyvsp[(7) - (8)].l));
      (yyval.s).Type = MSH_PHYSICAL_LINE;
      (yyval.s).Num = num;
    ;}
    break;

  case 209:
#line 2354 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].i);
      int op = (yyvsp[(6) - (8)].i);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(7) - (8)].l), tags);
      GModel::current()->getGEOInternals()->modifyPhysicalGroup(2, num, op, tags);
      List_Delete((yyvsp[(7) - (8)].l));
      (yyval.s).Type = MSH_PHYSICAL_SURFACE;
      (yyval.s).Num = num;
    ;}
    break;

  case 210:
#line 2364 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].i);
      int op = (yyvsp[(6) - (8)].i);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(7) - (8)].l), tags);
      GModel::current()->getGEOInternals()->modifyPhysicalGroup(3, num, op, tags);
      List_Delete((yyvsp[(7) - (8)].l));
      (yyval.s).Type = MSH_PHYSICAL_VOLUME;
      (yyval.s).Num = num;
    ;}
    break;

  case 211:
#line 2379 "Gmsh.y"
    {
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        std::vector<int> tags[4]; ListOfShapes2Vectors((yyvsp[(4) - (5)].l), tags);
        GModel::current()->getOCCInternals()->translate(tags, (yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2]);
      }
      else{
        TranslateShapes((yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], (yyvsp[(4) - (5)].l));
      }
      (yyval.l) = (yyvsp[(4) - (5)].l);
    ;}
    break;

  case 212:
#line 2390 "Gmsh.y"
    {
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        std::vector<int> tags[4]; ListOfShapes2Vectors((yyvsp[(10) - (11)].l), tags);
        GModel::current()->getOCCInternals()->rotate(tags, (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2],
                                                     (yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(7) - (11)].d));
      }
      else{
        RotateShapes((yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(7) - (11)].d), (yyvsp[(10) - (11)].l));
      }
      (yyval.l) = (yyvsp[(10) - (11)].l);
    ;}
    break;

  case 213:
#line 2402 "Gmsh.y"
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

  case 214:
#line 2412 "Gmsh.y"
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

  case 215:
#line 2422 "Gmsh.y"
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

  case 216:
#line 2432 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
      if(!strcmp((yyvsp[(1) - (4)].c), "Duplicata")){
        if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
          std::vector<int> in[4], out[4]; ListOfShapes2Vectors((yyvsp[(3) - (4)].l), in);
          GModel::current()->getOCCInternals()->copy(in, out);
          Vectors2ListOfShapes(out, (yyval.l));
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
        if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
          std::vector<int> in[4], out[4]; ListOfShapes2Vectors((yyvsp[(3) - (4)].l), in);
          GModel::current()->getOCCInternals()->getBoundary
            (in, out, !strcmp((yyvsp[(1) - (4)].c), "CombinedBoundary") ? true : false);
          Vectors2ListOfShapes(out, (yyval.l));
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
#line 2467 "Gmsh.y"
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
#line 2478 "Gmsh.y"
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
#line 2493 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 220:
#line 2494 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 221:
#line 2499 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    ;}
    break;

  case 222:
#line 2503 "Gmsh.y"
    {
      List_Add((yyval.l), &(yyvsp[(2) - (2)].s));
    ;}
    break;

  case 223:
#line 2507 "Gmsh.y"
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

  case 224:
#line 2518 "Gmsh.y"
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

  case 225:
#line 2529 "Gmsh.y"
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

  case 226:
#line 2540 "Gmsh.y"
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

  case 227:
#line 2556 "Gmsh.y"
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
#line 2578 "Gmsh.y"
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
#line 2605 "Gmsh.y"
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
#line 2627 "Gmsh.y"
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
#line 2649 "Gmsh.y"
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
#line 2671 "Gmsh.y"
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
#line 2727 "Gmsh.y"
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
#line 2751 "Gmsh.y"
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
#line 2776 "Gmsh.y"
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
#line 2801 "Gmsh.y"
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
#line 2914 "Gmsh.y"
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
#line 2933 "Gmsh.y"
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
#line 2976 "Gmsh.y"
    {
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        std::vector<int> tags[4]; ListOfShapes2Vectors((yyvsp[(3) - (4)].l), tags);
        GModel::current()->getOCCInternals()->remove(tags);
      }
      // FIXME use GEOInternals + int api
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
        Shape TheShape;
        List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
        DeleteShape(TheShape.Type, TheShape.Num);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 240:
#line 2990 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      GModel::current()->getFields()->deleteField((int)(yyvsp[(4) - (6)].d));
#endif
    ;}
    break;

  case 241:
#line 2996 "Gmsh.y"
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
#line 3011 "Gmsh.y"
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
#line 3039 "Gmsh.y"
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
#line 3056 "Gmsh.y"
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
#line 3065 "Gmsh.y"
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
#line 3079 "Gmsh.y"
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
#line 3093 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 1, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 248:
#line 3099 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 0, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 249:
#line 3105 "Gmsh.y"
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
#line 3114 "Gmsh.y"
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
#line 3123 "Gmsh.y"
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
#line 3132 "Gmsh.y"
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
#line 3146 "Gmsh.y"
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
        if(GModel::current()->getOCCInternals() &&
           GModel::current()->getOCCInternals()->getChanged())
          GModel::current()->getOCCInternals()->synchronize(GModel::current());
        if(GModel::current()->getGEOInternals()->getChanged())
          GModel::current()->getGEOInternals()->synchronize(GModel::current());
        std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(2) - (3)].c));
	CreateOutputFile(tmp, CTX::instance()->print.fileFormat);
      }
      else if(!strcmp((yyvsp[(1) - (3)].c), "Save")){
        if(GModel::current()->getOCCInternals() &&
           GModel::current()->getOCCInternals()->getChanged())
          GModel::current()->getOCCInternals()->synchronize(GModel::current());
        if(GModel::current()->getGEOInternals()->getChanged())
          GModel::current()->getGEOInternals()->synchronize(GModel::current());
        std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(2) - (3)].c));
	CreateOutputFile(tmp, CTX::instance()->mesh.fileFormat);
      }
      else if(!strcmp((yyvsp[(1) - (3)].c), "Merge") || !strcmp((yyvsp[(1) - (3)].c), "MergeWithBoundingBox")){
	// sync CAD internals here, so that if we e.g. import a STEP file, we
        // have the correct entity tags and the numberings don't clash
        if(GModel::current()->getOCCInternals() &&
           GModel::current()->getOCCInternals()->getChanged())
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

  case 254:
#line 3219 "Gmsh.y"
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
#line 3237 "Gmsh.y"
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
#line 3254 "Gmsh.y"
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
#line 3269 "Gmsh.y"
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
        if(GModel::current()->getOCCInternals() &&
           GModel::current()->getOCCInternals()->getChanged())
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

  case 258:
#line 3302 "Gmsh.y"
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
#line 3314 "Gmsh.y"
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
#line 3338 "Gmsh.y"
    {
      Msg::Exit(0);
    ;}
    break;

  case 261:
#line 3342 "Gmsh.y"
    {
      gmsh_yyerrorstate = 999; // this will be checked when yyparse returns
      YYABORT;
    ;}
    break;

  case 262:
#line 3347 "Gmsh.y"
    {
      // force sync
      if(GModel::current()->getOCCInternals())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      GModel::current()->getGEOInternals()->synchronize(GModel::current());
    ;}
    break;

  case 263:
#line 3354 "Gmsh.y"
    {
      new GModel();
      GModel::current(GModel::list.size() - 1);
    ;}
    break;

  case 264:
#line 3359 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 0;
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      if(GModel::current()->getGEOInternals()->getChanged())
        GModel::current()->getGEOInternals()->synchronize(GModel::current());
      SetBoundingBox();
    ;}
    break;

  case 265:
#line 3369 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 1;
      SetBoundingBox((yyvsp[(3) - (15)].d), (yyvsp[(5) - (15)].d), (yyvsp[(7) - (15)].d), (yyvsp[(9) - (15)].d), (yyvsp[(11) - (15)].d), (yyvsp[(13) - (15)].d));
    ;}
    break;

  case 266:
#line 3374 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
      drawContext::global()->draw();
#endif
    ;}
    break;

  case 267:
#line 3380 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
     CTX::instance()->mesh.changed = ENT_ALL;
     for(unsigned int index = 0; index < PView::list.size(); index++)
       PView::list[index]->setChanged(true);
#endif
    ;}
    break;

  case 268:
#line 3388 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh();
    ;}
    break;

  case 269:
#line 3392 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh(1);
    ;}
    break;

  case 270:
#line 3396 "Gmsh.y"
    {
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      if(GModel::current()->getGEOInternals()->getChanged())
        GModel::current()->getGEOInternals()->synchronize(GModel::current());
      GModel::current()->refineMesh(CTX::instance()->mesh.secondOrderLinear);
    ;}
    break;

  case 271:
#line 3406 "Gmsh.y"
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
            if(GModel::current()->getOCCInternals() &&
               GModel::current()->getOCCInternals()->getChanged())
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

  case 272:
#line 3469 "Gmsh.y"
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
#line 3485 "Gmsh.y"
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
#line 3502 "Gmsh.y"
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
#line 3519 "Gmsh.y"
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
#line 3541 "Gmsh.y"
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
#line 3563 "Gmsh.y"
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
#line 3598 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip_until(NULL, "Return");
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 279:
#line 3606 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip_until(NULL, "Return");
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 280:
#line 3614 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    ;}
    break;

  case 281:
#line 3620 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 282:
#line 3627 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 283:
#line 3634 "Gmsh.y"
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
#line 3654 "Gmsh.y"
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
#line 3680 "Gmsh.y"
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
#line 3692 "Gmsh.y"
    {
      ImbricatedTest--;
      if(ImbricatedTest < 0)
        yymsg(1, "Orphan EndIf");
    ;}
    break;

  case 287:
#line 3704 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        std::vector<int> in[4], out[4]; ListOfShapes2Vectors((yyvsp[(4) - (5)].l), in);
        GModel::current()->getOCCInternals()->extrude(-1, in, (yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], out);
        Vectors2ListOfShapes(out, (yyval.l));
      }
      else{
        // FIXME use GEOInternals + int api -- SAME FOR ALL BELOW!
        ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (5)].l),
                      (yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
                      NULL, (yyval.l));
      }
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 288:
#line 3720 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        std::vector<int> in[4], out[4]; ListOfShapes2Vectors((yyvsp[(10) - (11)].l), in);
        GModel::current()->getOCCInternals()->revolve(-1, in, (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2],
                                                      (yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(7) - (11)].d), out);
        Vectors2ListOfShapes(out, (yyval.l));
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
#line 3736 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (13)].l),
		    (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].v)[0], (yyvsp[(7) - (13)].v)[1], (yyvsp[(7) - (13)].v)[2], (yyvsp[(9) - (13)].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[(12) - (13)].l));
    ;}
    break;

  case 290:
#line 3744 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 291:
#line 3750 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (7)].l),
		    (yyvsp[(2) - (7)].v)[0], (yyvsp[(2) - (7)].v)[1], (yyvsp[(2) - (7)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(4) - (7)].l));
    ;}
    break;

  case 292:
#line 3758 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 293:
#line 3764 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[(10) - (13)].l),
		    0., 0., 0., (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(10) - (13)].l));
    ;}
    break;

  case 294:
#line 3772 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 295:
#line 3778 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (15)].l),
		    (yyvsp[(3) - (15)].v)[0], (yyvsp[(3) - (15)].v)[1], (yyvsp[(3) - (15)].v)[2], (yyvsp[(5) - (15)].v)[0], (yyvsp[(5) - (15)].v)[1], (yyvsp[(5) - (15)].v)[2], (yyvsp[(7) - (15)].v)[0], (yyvsp[(7) - (15)].v)[1], (yyvsp[(7) - (15)].v)[2], (yyvsp[(9) - (15)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(12) - (15)].l));
    ;}
    break;

  case 296:
#line 3786 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 297:
#line 3792 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(BOUNDARY_LAYER, (yyvsp[(3) - (6)].l), 0., 0., 0., 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(3) - (6)].l));
    ;}
    break;

  case 298:
#line 3799 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        std::vector<int> in[4], out[4]; ListOfShapes2Vectors((yyvsp[(3) - (9)].l), in);
        GModel::current()->getOCCInternals()->addPipe(-1, in, (int)(yyvsp[(8) - (9)].d), out);
        Vectors2ListOfShapes(out, (yyval.l));
      }
      else{
        yymsg(0, "Pipe only available with OpenCASCADE factory");
      }
      List_Delete((yyvsp[(3) - (9)].l));
    ;}
    break;

  case 299:
#line 3812 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        std::vector<int> wires, out[4]; ListOfDouble2Vector((yyvsp[(2) - (2)].l), wires);
        GModel::current()->getOCCInternals()->addThruSections(-1, wires, out,
                                                              false, false);
        Vectors2ListOfShapes(out, (yyval.l));
      }
      else{
        yymsg(0, "ThruSections only available with OpenCASCADE factory");
      }
      List_Delete((yyvsp[(2) - (2)].l));
    ;}
    break;

  case 300:
#line 3826 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        std::vector<int> wires, out[4]; ListOfDouble2Vector((yyvsp[(3) - (3)].l), wires);
        GModel::current()->getOCCInternals()->addThruSections(-1, wires, out,
                                                              false, true);
        Vectors2ListOfShapes(out, (yyval.l));
      }
      else{
        yymsg(0, "ThruSections only available with OpenCASCADE factory");
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 301:
#line 3840 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        double radius = (yyvsp[(9) - (10)].d);
        std::vector<int> regions, edges, out[4];
        ListOfDouble2Vector((yyvsp[(3) - (10)].l), regions); ListOfDouble2Vector((yyvsp[(6) - (10)].l), edges);
        GModel::current()->getOCCInternals()->fillet(regions, edges, radius, out);
        Vectors2ListOfShapes(out, (yyval.l));
      }
      else{
        yymsg(0, "Fillet only available with OpenCASCADE factory");
      }
      List_Delete((yyvsp[(3) - (10)].l));
      List_Delete((yyvsp[(6) - (10)].l));
    ;}
    break;

  case 302:
#line 3857 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 303:
#line 3864 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 304:
#line 3871 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 305:
#line 3878 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 306:
#line 3885 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 307:
#line 3892 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 308:
#line 3899 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 309:
#line 3906 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 310:
#line 3913 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 311:
#line 3920 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 312:
#line 3926 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 313:
#line 3933 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 314:
#line 3939 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 315:
#line 3946 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 316:
#line 3952 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 317:
#line 3959 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 318:
#line 3965 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 319:
#line 3972 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 320:
#line 3978 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 321:
#line 3985 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 322:
#line 3991 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 323:
#line 3998 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 324:
#line 4004 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 325:
#line 4011 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 326:
#line 4017 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 327:
#line 4024 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 328:
#line 4030 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 329:
#line 4041 "Gmsh.y"
    {
    ;}
    break;

  case 330:
#line 4044 "Gmsh.y"
    {
    ;}
    break;

  case 331:
#line 4050 "Gmsh.y"
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
#line 4062 "Gmsh.y"
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
#line 4082 "Gmsh.y"
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
#line 4105 "Gmsh.y"
    {
      extr.mesh.ScaleLast = true;
    ;}
    break;

  case 335:
#line 4109 "Gmsh.y"
    {
      extr.mesh.Recombine = true;
    ;}
    break;

  case 336:
#line 4113 "Gmsh.y"
    {
      extr.mesh.Recombine = (yyvsp[(2) - (3)].d) ? true : false;
    ;}
    break;

  case 337:
#line 4117 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1;
    ;}
    break;

  case 338:
#line 4121 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1_RECOMB;
    ;}
    break;

  case 339:
#line 4125 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1;
    ;}
    break;

  case 340:
#line 4129 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1_RECOMB;
    ;}
    break;

  case 341:
#line 4133 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(6) - (9)].l), tags);
      int num = (int)(yyvsp[(3) - (9)].d);
      GModel::current()->getGEOInternals()->addDiscreteSurface(num);
      extr.mesh.Holes[num].first = (yyvsp[(8) - (9)].d);
      extr.mesh.Holes[num].second = tags;
      List_Delete((yyvsp[(6) - (9)].l));
    ;}
    break;

  case 342:
#line 4142 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (6)].c), "Index"))
        extr.mesh.BoundaryLayerIndex = (yyvsp[(4) - (6)].d);
      else if(!strcmp((yyvsp[(2) - (6)].c), "View"))
        extr.mesh.ViewIndex = (yyvsp[(4) - (6)].d);
      Free((yyvsp[(2) - (6)].c));
    ;}
    break;

  case 343:
#line 4154 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Union; ;}
    break;

  case 344:
#line 4155 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Intersection; ;}
    break;

  case 345:
#line 4156 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Difference; ;}
    break;

  case 346:
#line 4157 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Section; ;}
    break;

  case 347:
#line 4158 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Fragments; ;}
    break;

  case 348:
#line 4162 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 349:
#line 4163 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 350:
#line 4164 "Gmsh.y"
    { (yyval.i) = (yyvsp[(2) - (3)].d); ;}
    break;

  case 351:
#line 4169 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        std::vector<int> shape[4], tool[4], out[4];
        ListOfShapes2Vectors((yyvsp[(3) - (9)].l), shape);
        ListOfShapes2Vectors((yyvsp[(7) - (9)].l), tool);
        GModel::current()->getOCCInternals()->applyBooleanOperator
          (-1, (OCC_Internals::BooleanOperator)(yyvsp[(1) - (9)].i), shape, tool, out, (yyvsp[(4) - (9)].i), (yyvsp[(8) - (9)].i));
        Vectors2ListOfShapes(out, (yyval.l));
      }
      else{
        yymsg(0, "Boolean operators only available with OpenCASCADE factory");
      }
      List_Delete((yyvsp[(3) - (9)].l));
      List_Delete((yyvsp[(7) - (9)].l));
    ;}
    break;

  case 352:
#line 4186 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        std::vector<int> out[4];
        std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
        GModel::current()->getOCCInternals()->importShapes(tmp, true, out);
        Vectors2ListOfShapes(out, (yyval.l));
      }
      else{
        yymsg(0, "ShapeFromFile only available with OpenCASCADE factory");
      }
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 353:
#line 4204 "Gmsh.y"
    {
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        std::vector<int> shape[4], tool[4], out[4];
        ListOfShapes2Vectors((yyvsp[(7) - (14)].l), shape);
        ListOfShapes2Vectors((yyvsp[(11) - (14)].l), tool);
        GModel::current()->getOCCInternals()->applyBooleanOperator
          ((int)(yyvsp[(3) - (14)].d), (OCC_Internals::BooleanOperator)(yyvsp[(1) - (14)].i), shape, tool, out, (yyvsp[(8) - (14)].i), (yyvsp[(12) - (14)].i));
      }
      List_Delete((yyvsp[(7) - (14)].l));
      List_Delete((yyvsp[(11) - (14)].l));
    ;}
    break;

  case 354:
#line 4219 "Gmsh.y"
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    ;}
    break;

  case 355:
#line 4223 "Gmsh.y"
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

  case 356:
#line 4238 "Gmsh.y"
    {
      (yyval.i) = -1; // left
    ;}
    break;

  case 357:
#line 4242 "Gmsh.y"
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

  case 358:
#line 4258 "Gmsh.y"
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   ;}
    break;

  case 359:
#line 4262 "Gmsh.y"
    {
     (yyval.l) = (yyvsp[(2) - (2)].l);
   ;}
    break;

  case 360:
#line 4267 "Gmsh.y"
    {
      (yyval.i) = 45;
    ;}
    break;

  case 361:
#line 4271 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(2) - (2)].d);
    ;}
    break;

  case 362:
#line 4277 "Gmsh.y"
    {
      (yyval.l) = List_Create(1, 1, sizeof(double));
    ;}
    break;

  case 363:
#line 4281 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
    ;}
    break;

  case 364:
#line 4288 "Gmsh.y"
    {
      // mesh sizes at vertices are stored in internal CAD data, as they can be
      // specified during vertex creation and copied around during CAD
      // operations
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (6)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (6)].l), i, &d);
        int tag = (int)d;
        if(GModel::current()->getOCCInternals())
          GModel::current()->getOCCInternals()->setMeshSize(0, tag, (yyvsp[(5) - (6)].d));
        GModel::current()->getGEOInternals()->setMeshSize(0, tag, (yyvsp[(5) - (6)].d));
        GVertex *gv = GModel::current()->getVertexByTag(tag);
        if(gv) gv->setPrescribedMeshSizeAtVertex((yyvsp[(5) - (6)].d));
      }
      List_Delete((yyvsp[(3) - (6)].l));
    ;}
    break;

  case 365:
#line 4305 "Gmsh.y"
    {
      // transfinite constraints are also stored in GEO internals, as they can
      // be copied around during GEO operations
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
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

  case 366:
#line 4346 "Gmsh.y"
    {
      // transfinite constraints are also stored in GEO internals, as they can
      // be copied around during GEO operations
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
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

  case 367:
#line 4390 "Gmsh.y"
    {
      yymsg(1, "Elliptic Surface is deprecated: use Transfinite instead (with smoothing)");
      List_Delete((yyvsp[(7) - (8)].l));
    ;}
    break;

  case 368:
#line 4395 "Gmsh.y"
    {
      // transfinite constraints are also stored in GEO internals, as they can
      // be copied around during GEO operations
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
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

  case 369:
#line 4434 "Gmsh.y"
    {
      // transfinite constraints are also stored in GEO internals, as they can
      // be copied around during GEO operations
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
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

  case 370:
#line 4459 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (8)].l)); i++){
	double d;
	List_Read((yyvsp[(4) - (8)].l), i, &d);
	CTX::instance()->mesh.algo2d_per_face[(int)d] = (int)(yyvsp[(7) - (8)].d);
      }
      List_Delete((yyvsp[(4) - (8)].l));
    ;}
    break;

  case 371:
#line 4468 "Gmsh.y"
    {
      // recombine constraints are also stored in GEO internals, as they can be
      // copied around during GEO operations
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
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

  case 372:
#line 4498 "Gmsh.y"
    {
      // recombine constraints are also stored in GEO internals, as they can be
      // copied around during GEO operations
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
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

  case 373:
#line 4524 "Gmsh.y"
    {
      // smoothing constraints are also stored in GEO internals, as they can be
      // copied around during GEO operations
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
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

  case 374:
#line 4551 "Gmsh.y"
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

  case 375:
#line 4583 "Gmsh.y"
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

  case 376:
#line 4610 "Gmsh.y"
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

  case 377:
#line 4636 "Gmsh.y"
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

  case 378:
#line 4662 "Gmsh.y"
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

  case 379:
#line 4688 "Gmsh.y"
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

  case 380:
#line 4714 "Gmsh.y"
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

  case 381:
#line 4735 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (10)].l), tags);
      addEmbedded(0, tags, 2, (int)(yyvsp[(8) - (10)].d));
      List_Delete((yyvsp[(3) - (10)].l));
    ;}
    break;

  case 382:
#line 4741 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (10)].l), tags);
      addEmbedded(1, tags, 2, (int)(yyvsp[(8) - (10)].d));
      List_Delete((yyvsp[(3) - (10)].l));
    ;}
    break;

  case 383:
#line 4747 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (10)].l), tags);
      addEmbedded(0, tags, 3, (int)(yyvsp[(8) - (10)].d));
      List_Delete((yyvsp[(3) - (10)].l));
    ;}
    break;

  case 384:
#line 4753 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (10)].l), tags);
      addEmbedded(1, tags, 3, (int)(yyvsp[(8) - (10)].d));
      List_Delete((yyvsp[(3) - (10)].l));
    ;}
    break;

  case 385:
#line 4759 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (10)].l), tags);
      addEmbedded(2, tags, 3, (int)(yyvsp[(8) - (10)].d));
      List_Delete((yyvsp[(3) - (10)].l));
    ;}
    break;

  case 386:
#line 4765 "Gmsh.y"
    {
      // reverse mesh constraints are also stored in GEO internals, as they can
      // be copied around during GEO operations
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
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

  case 387:
#line 4791 "Gmsh.y"
    {
      // reverse mesh constraints are also stored in GEO internals, as they can
      // be copied around during GEO operations
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
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

  case 388:
#line 4817 "Gmsh.y"
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

  case 389:
#line 4834 "Gmsh.y"
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

  case 390:
#line 4851 "Gmsh.y"
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

  case 391:
#line 4868 "Gmsh.y"
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

  case 392:
#line 4880 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (4)].l), tags);
      GModel::current()->getGEOInternals()->setCompoundMesh(1, tags);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 393:
#line 4886 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (4)].l), tags);
      GModel::current()->getGEOInternals()->setCompoundMesh(2, tags);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 394:
#line 4892 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (4)].l), tags);
      GModel::current()->getGEOInternals()->setCompoundMesh(3, tags);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 395:
#line 4904 "Gmsh.y"
    {
      GModel::current()->getGEOInternals()->removeAllDuplicates();
    ;}
    break;

  case 396:
#line 4908 "Gmsh.y"
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

  case 397:
#line 4918 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(4) - (6)].l), tags);
      GModel::current()->getGEOInternals()->mergeVertices(tags);
      List_Delete((yyvsp[(4) - (6)].l));
    ;}
    break;

  case 398:
#line 4928 "Gmsh.y"
    { (yyval.c) = (char*)"Homology"; ;}
    break;

  case 399:
#line 4929 "Gmsh.y"
    { (yyval.c) = (char*)"Cohomology"; ;}
    break;

  case 400:
#line 4930 "Gmsh.y"
    { (yyval.c) = (char*)"Betti"; ;}
    break;

  case 401:
#line 4935 "Gmsh.y"
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest((yyvsp[(1) - (2)].c), domain, subdomain, dim);
    ;}
    break;

  case 402:
#line 4941 "Gmsh.y"
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

  case 403:
#line 4953 "Gmsh.y"
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

  case 404:
#line 4971 "Gmsh.y"
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

  case 405:
#line 4998 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d);           ;}
    break;

  case 406:
#line 4999 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (3)].d);           ;}
    break;

  case 407:
#line 5000 "Gmsh.y"
    { (yyval.d) = -(yyvsp[(2) - (2)].d);          ;}
    break;

  case 408:
#line 5001 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);           ;}
    break;

  case 409:
#line 5002 "Gmsh.y"
    { (yyval.d) = !(yyvsp[(2) - (2)].d);          ;}
    break;

  case 410:
#line 5003 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) - (yyvsp[(3) - (3)].d);      ;}
    break;

  case 411:
#line 5004 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) + (yyvsp[(3) - (3)].d);      ;}
    break;

  case 412:
#line 5005 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) * (yyvsp[(3) - (3)].d);      ;}
    break;

  case 413:
#line 5007 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (3)].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));
      else
	(yyval.d) = (yyvsp[(1) - (3)].d) / (yyvsp[(3) - (3)].d);
    ;}
    break;

  case 414:
#line 5013 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) % (int)(yyvsp[(3) - (3)].d);  ;}
    break;

  case 415:
#line 5014 "Gmsh.y"
    { (yyval.d) = pow((yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));  ;}
    break;

  case 416:
#line 5015 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d);      ;}
    break;

  case 417:
#line 5016 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) > (yyvsp[(3) - (3)].d);      ;}
    break;

  case 418:
#line 5017 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) <= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 419:
#line 5018 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) >= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 420:
#line 5019 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) == (yyvsp[(3) - (3)].d);     ;}
    break;

  case 421:
#line 5020 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) != (yyvsp[(3) - (3)].d);     ;}
    break;

  case 422:
#line 5021 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) && (yyvsp[(3) - (3)].d);     ;}
    break;

  case 423:
#line 5022 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) || (yyvsp[(3) - (3)].d);     ;}
    break;

  case 424:
#line 5023 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (5)].d) ? (yyvsp[(3) - (5)].d) : (yyvsp[(5) - (5)].d); ;}
    break;

  case 425:
#line 5024 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 426:
#line 5025 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 427:
#line 5026 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 428:
#line 5027 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 429:
#line 5028 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 430:
#line 5029 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 431:
#line 5030 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 432:
#line 5031 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 433:
#line 5032 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 434:
#line 5033 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 435:
#line 5034 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 436:
#line 5035 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 437:
#line 5036 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 438:
#line 5037 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 439:
#line 5038 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 440:
#line 5039 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 441:
#line 5040 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 442:
#line 5041 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d) + 0.5); ;}
    break;

  case 443:
#line 5042 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 444:
#line 5043 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 445:
#line 5044 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 446:
#line 5045 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 447:
#line 5054 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 448:
#line 5055 "Gmsh.y"
    { (yyval.d) = 3.141592653589793; ;}
    break;

  case 449:
#line 5056 "Gmsh.y"
    { (yyval.d) = (double)ImbricatedTest; ;}
    break;

  case 450:
#line 5057 "Gmsh.y"
    { (yyval.d) = Msg::GetCommRank(); ;}
    break;

  case 451:
#line 5058 "Gmsh.y"
    { (yyval.d) = Msg::GetCommSize(); ;}
    break;

  case 452:
#line 5059 "Gmsh.y"
    { (yyval.d) = GetGmshMajorVersion(); ;}
    break;

  case 453:
#line 5060 "Gmsh.y"
    { (yyval.d) = GetGmshMinorVersion(); ;}
    break;

  case 454:
#line 5061 "Gmsh.y"
    { (yyval.d) = GetGmshPatchVersion(); ;}
    break;

  case 455:
#line 5062 "Gmsh.y"
    { (yyval.d) = Cpu(); ;}
    break;

  case 456:
#line 5063 "Gmsh.y"
    { (yyval.d) = GetMemoryUsage()/1024./1024.; ;}
    break;

  case 457:
#line 5064 "Gmsh.y"
    { (yyval.d) = TotalRam(); ;}
    break;

  case 458:
#line 5069 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 459:
#line 5071 "Gmsh.y"
    {
      std::vector<double> val(1, (yyvsp[(3) - (6)].d));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.d) = val[0];
    ;}
    break;

  case 460:
#line 5077 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 461:
#line 5079 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 462:
#line 5084 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 463:
#line 5089 "Gmsh.y"
    {
      if(gmsh_yysymbols.count((yyvsp[(1) - (1)].c))){
        gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[(1) - (1)].c)]);
        if(s.value.empty()){
          yymsg(0, "Uninitialized variable '%s'", (yyvsp[(1) - (1)].c));
          (yyval.d) = 0.;
        }
        else
          (yyval.d) = s.value[0];
      }
      else{
        std::string key((yyvsp[(1) - (1)].c));
        if(StructTable_M.count(key)) {
          (yyval.d) = (double)StructTable_M[key]._value;
        }
        else {
          yymsg(0, "Unknown variable '%s'", (yyvsp[(1) - (1)].c));
          (yyval.d) = 0.;
        }
      }
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 464:
#line 5112 "Gmsh.y"
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
#line 5130 "Gmsh.y"
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
#line 5148 "Gmsh.y"
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
#line 5166 "Gmsh.y"
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
#line 5184 "Gmsh.y"
    {
      (yyval.d) = gmsh_yysymbols.count((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 469:
#line 5189 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.d) = !StatFile(tmp);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 470:
#line 5195 "Gmsh.y"
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

  case 471:
#line 5210 "Gmsh.y"
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

  case 472:
#line 5229 "Gmsh.y"
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
#line 5249 "Gmsh.y"
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
#line 5269 "Gmsh.y"
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
#line 5289 "Gmsh.y"
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
#line 5319 "Gmsh.y"
    {
      std::string key((yyvsp[(1) - (3)].c));
      if(StructTable_M.count(key)) {
        std::string key2((yyvsp[(3) - (3)].c));
        if(StructTable_M[key]._fopt.count(key2)) {
	  (yyval.d) = StructTable_M[key]._fopt[key2][0];
        }
        else {
	  yymsg(0, "Unknown member '%s' of Struct %s", (yyvsp[(3) - (3)].c), (yyvsp[(1) - (3)].c));  (yyval.d) = 0.;
	}
      }
      else  {
        NumberOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), (yyval.d));
      }
      Free((yyvsp[(1) - (3)].c));
      if (flag_tSTRING_alloc) Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 477:
#line 5337 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), (yyval.d));
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 478:
#line 5342 "Gmsh.y"
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

  case 479:
#line 5352 "Gmsh.y"
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

  case 480:
#line 5362 "Gmsh.y"
    {
      (yyval.d) = Msg::GetValue((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 481:
#line 5367 "Gmsh.y"
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

  case 482:
#line 5378 "Gmsh.y"
    {
      std::string s((yyvsp[(3) - (6)].c)), substr((yyvsp[(5) - (6)].c));
      if(s.find(substr) != std::string::npos)
        (yyval.d) = 1.;
      else
        (yyval.d) = 0.;
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 483:
#line 5387 "Gmsh.y"
    {
      (yyval.d) = strlen((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 484:
#line 5392 "Gmsh.y"
    {
      (yyval.d) = strcmp((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 485:
#line 5397 "Gmsh.y"
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

  case 486:
#line 5425 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 487:
#line 5428 "Gmsh.y"
    {
      std::string key(Struct_Name);
      StructTable_M[key] = Struct((int)(yyvsp[(6) - (8)].d), 1, floatOptions, charOptions);
      (yyval.d) = (yyvsp[(6) - (8)].d);
      Free(Struct_Name);
    ;}
    break;

  case 488:
#line 5438 "Gmsh.y"
    { Struct_NameSpace = NULL; Struct_Name = (yyvsp[(1) - (1)].c); ;}
    break;

  case 489:
#line 5440 "Gmsh.y"
    { Struct_NameSpace = (yyvsp[(1) - (4)].c); Struct_Name = (yyvsp[(4) - (4)].c); ;}
    break;

  case 490:
#line 5445 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); flag_tSTRING_alloc = 1; ;}
    break;

  case 492:
#line 5456 "Gmsh.y"
    {
      std::string key((yyvsp[(2) - (3)].c)), val(Struct_Name);
      gmsh_yystringsymbols[key] = std::vector<std::string>(1, val);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 493:
#line 5465 "Gmsh.y"
    {
      memcpy((yyval.v), (yyvsp[(1) - (1)].v), 5*sizeof(double));
    ;}
    break;

  case 494:
#line 5469 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 495:
#line 5473 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 496:
#line 5477 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] - (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 497:
#line 5481 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] + (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 498:
#line 5488 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (11)].d);  (yyval.v)[1] = (yyvsp[(4) - (11)].d);  (yyval.v)[2] = (yyvsp[(6) - (11)].d);  (yyval.v)[3] = (yyvsp[(8) - (11)].d); (yyval.v)[4] = (yyvsp[(10) - (11)].d);
    ;}
    break;

  case 499:
#line 5492 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (9)].d);  (yyval.v)[1] = (yyvsp[(4) - (9)].d);  (yyval.v)[2] = (yyvsp[(6) - (9)].d);  (yyval.v)[3] = (yyvsp[(8) - (9)].d); (yyval.v)[4] = 1.0;
    ;}
    break;

  case 500:
#line 5496 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 501:
#line 5500 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 502:
#line 5507 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].l)));
    ;}
    break;

  case 503:
#line 5512 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].l)));
    ;}
    break;

  case 504:
#line 5519 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 505:
#line 5524 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 506:
#line 5528 "Gmsh.y"
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    ;}
    break;

  case 507:
#line 5533 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 508:
#line 5537 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 509:
#line 5545 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (5)].d);
      }
    ;}
    break;

  case 510:
#line 5556 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 511:
#line 5560 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(1) - (1)].c), "*") || !strcmp((yyvsp[(1) - (1)].c), "all"))
        (yyval.l) = 0;
      else{
        yyerror("Unknown special string for list replacement");
        (yyval.l) = List_Create(2, 1, sizeof(double));
      }
    ;}
    break;

  case 512:
#line 5572 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 513:
#line 5580 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (3)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (3)].d);
      }
    ;}
    break;

  case 514:
#line 5588 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      for(double d = (yyvsp[(1) - (3)].d); ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d <= (yyvsp[(3) - (3)].d)) : (d >= (yyvsp[(3) - (3)].d));
          ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d += 1.) : (d -= 1.))
	List_Add((yyval.l), &d);
    ;}
    break;

  case 515:
#line 5595 "Gmsh.y"
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

  case 516:
#line 5605 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 1, sizeof(double));
      int tag = (int)(yyvsp[(3) - (4)].d);
      double x = 0., y = 0., z = 0.;
      bool found = GModel::current()->getGEOInternals()->getVertex(tag, x, y, z);
      if(!found && GModel::current()->getOCCInternals())
        found = GModel::current()->getOCCInternals()->getVertex(tag, x, y, z);
      if(!found){
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
      List_Add((yyval.l), &x);
      List_Add((yyval.l), &y);
      List_Add((yyval.l), &z);
    ;}
    break;

  case 517:
#line 5628 "Gmsh.y"
    {
      (yyval.l) = GetAllElementaryEntityNumbers(0);
    ;}
    break;

  case 518:
#line 5632 "Gmsh.y"
    {
      (yyval.l) = GetAllElementaryEntityNumbers(1);
    ;}
    break;

  case 519:
#line 5636 "Gmsh.y"
    {
      (yyval.l) = GetAllElementaryEntityNumbers(2);
    ;}
    break;

  case 520:
#line 5640 "Gmsh.y"
    {
      (yyval.l) = GetAllElementaryEntityNumbers(3);
    ;}
    break;

  case 521:
#line 5644 "Gmsh.y"
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(0);
    ;}
    break;

  case 522:
#line 5648 "Gmsh.y"
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(1);
    ;}
    break;

  case 523:
#line 5652 "Gmsh.y"
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(2);
    ;}
    break;

  case 524:
#line 5656 "Gmsh.y"
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(3);
    ;}
    break;

  case 525:
#line 5660 "Gmsh.y"
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

  case 526:
#line 5689 "Gmsh.y"
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

  case 527:
#line 5718 "Gmsh.y"
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

  case 528:
#line 5747 "Gmsh.y"
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

  case 529:
#line 5777 "Gmsh.y"
    {
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
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

  case 530:
#line 5794 "Gmsh.y"
    {
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
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

  case 531:
#line 5811 "Gmsh.y"
    {
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
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

  case 532:
#line 5828 "Gmsh.y"
    {
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
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

  case 533:
#line 5844 "Gmsh.y"
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

  case 534:
#line 5854 "Gmsh.y"
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

  case 535:
#line 5864 "Gmsh.y"
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

  case 536:
#line 5874 "Gmsh.y"
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

  case 537:
#line 5886 "Gmsh.y"
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

  case 538:
#line 5899 "Gmsh.y"
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

  case 539:
#line 5911 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 540:
#line 5915 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 541:
#line 5919 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (6)].l);
    ;}
    break;

  case 542:
#line 5923 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (6)].l);
    ;}
    break;

  case 543:
#line 5927 "Gmsh.y"
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

  case 544:
#line 5945 "Gmsh.y"
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

  case 545:
#line 5963 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = (yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1);
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 546:
#line 5971 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = pow(10,(yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1));
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 547:
#line 5979 "Gmsh.y"
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

  case 548:
#line 6008 "Gmsh.y"
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

  case 549:
#line 6018 "Gmsh.y"
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

  case 550:
#line 6037 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 551:
#line 6042 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 552:
#line 6046 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].d)));
    ;}
    break;

  case 553:
#line 6050 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (3)].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 554:
#line 6062 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (9)].d), (int)(yyvsp[(4) - (9)].d), (int)(yyvsp[(6) - (9)].d), (int)(yyvsp[(8) - (9)].d));
    ;}
    break;

  case 555:
#line 6066 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (7)].d), (int)(yyvsp[(4) - (7)].d), (int)(yyvsp[(6) - (7)].d), 255);
    ;}
    break;

  case 556:
#line 6078 "Gmsh.y"
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

  case 557:
#line 6095 "Gmsh.y"
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(5) - (5)].c), val);
      (yyval.u) = val;
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(5) - (5)].c));
    ;}
    break;

  case 558:
#line 6105 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 559:
#line 6109 "Gmsh.y"
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

  case 560:
#line 6124 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].u)));
    ;}
    break;

  case 561:
#line 6129 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].u)));
    ;}
    break;

  case 562:
#line 6136 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 563:
#line 6140 "Gmsh.y"
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

  case 564:
#line 6153 "Gmsh.y"
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

  case 565:
#line 6167 "Gmsh.y"
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

  case 566:
#line 6181 "Gmsh.y"
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

  case 567:
#line 6195 "Gmsh.y"
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

  case 568:
#line 6210 "Gmsh.y"
    {
      std::string out;
      std::string key((yyvsp[(1) - (3)].c));
      if(StructTable_M.count(key)) {
        std::string key2((yyvsp[(3) - (3)].c));
        if(StructTable_M[key]._copt.count(key2)) {
          out = StructTable_M[key]._copt[key2][0];
        }
        else {
	  yymsg(0, "Unknown member '%s' of Struct %s", (yyvsp[(3) - (3)].c), (yyvsp[(1) - (3)].c));
	}
      }
      else  {
        StringOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), out);
      }
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (3)].c));
      if (flag_tSTRING_alloc) Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 569:
#line 6232 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 570:
#line 6243 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 571:
#line 6247 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 572:
#line 6251 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    ;}
    break;

  case 573:
#line 6259 "Gmsh.y"
    {
      std::string exe = Msg::GetExecutableName();
      (yyval.c) = (char *)Malloc(exe.size() + 1);
      strcpy((yyval.c), exe.c_str());
    ;}
    break;

  case 574:
#line 6265 "Gmsh.y"
    {
      std::string action = Msg::GetOnelabAction();
      (yyval.c) = (char *)Malloc(action.size() + 1);
      strcpy((yyval.c), action.c_str());
    ;}
    break;

  case 575:
#line 6271 "Gmsh.y"
    {
      const char *env = GetEnvironmentVar((yyvsp[(3) - (4)].c));
      if(!env) env = "";
      (yyval.c) = (char *)Malloc((sizeof(env) + 1) * sizeof(char));
      strcpy((yyval.c), env);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 576:
#line 6279 "Gmsh.y"
    {
      std::string s = Msg::GetString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 577:
#line 6287 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (4)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 578:
#line 6294 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 579:
#line 6302 "Gmsh.y"
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

  case 580:
#line 6317 "Gmsh.y"
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

  case 581:
#line 6331 "Gmsh.y"
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

  case 582:
#line 6345 "Gmsh.y"
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

  case 583:
#line 6357 "Gmsh.y"
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

  case 584:
#line 6373 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = toupper((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 585:
#line 6382 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = tolower((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 586:
#line 6391 "Gmsh.y"
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

  case 587:
#line 6401 "Gmsh.y"
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

  case 588:
#line 6412 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (8)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (8)].d), (int)(yyvsp[(7) - (8)].d));
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (8)].c));
    ;}
    break;

  case 589:
#line 6420 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (6)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (6)].d), std::string::npos);
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 590:
#line 6428 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 591:
#line 6432 "Gmsh.y"
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

  case 592:
#line 6451 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 593:
#line 6458 "Gmsh.y"
    {
      std::string tmp = SplitFileName(GetAbsolutePath(gmsh_yyname))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
    ;}
    break;

  case 594:
#line 6464 "Gmsh.y"
    {
      std::string tmp = SplitFileName((yyvsp[(3) - (4)].c))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 595:
#line 6471 "Gmsh.y"
    {
      std::string tmp = GetAbsolutePath((yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 596:
#line 6478 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 597:
#line 6480 "Gmsh.y"
    {
      std::string val((yyvsp[(3) - (6)].c));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.c) = (char*)Malloc((val.size() + 1) * sizeof(char));
      strcpy((yyval.c), val.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 598:
#line 6489 "Gmsh.y"
    {
      std::string out;
      int val = (int)(yyvsp[(3) - (4)].d);
      std::map<std::string, Struct>::iterator it;
      for (it = StructTable_M.begin(); it != StructTable_M.end(); ++it )
        if (it->second._value == val) out = it->first;
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
    ;}
    break;

  case 599:
#line 6503 "Gmsh.y"
    { Struct_NameSpace = NULL; (yyval.d) = (yyvsp[(2) - (2)].d); ;}
    break;

  case 600:
#line 6505 "Gmsh.y"
    { Struct_NameSpace = (yyvsp[(1) - (5)].c); (yyval.d) = (yyvsp[(5) - (5)].d); ;}
    break;

  case 601:
#line 6511 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].c)));
    ;}
    break;

  case 602:
#line 6516 "Gmsh.y"
    { List_Add((yyval.l), &((yyvsp[(3) - (3)].c))); ;}
    break;

  case 603:
#line 6522 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 604:
#line 6531 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char)) ;
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)) ; strcat((yyval.c), tmpstr) ;
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 605:
#line 6544 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 606:
#line 6547 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 607:
#line 6551 "Gmsh.y"
    { (yyval.c) = (yyvsp[(3) - (4)].c); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 14080 "Gmsh.tab.cpp"
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


#line 6554 "Gmsh.y"


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

void ListOfShapes2Vectors(List_T *list, std::vector<int> v[4])
{
  Shape s;
  for(int i = 0; i < List_Nbr(list); i++){
    List_Read(list, i, &s);
    int dim = s.Type / 100 - 1;
    if(dim >= 0 && dim <= 3) v[dim].push_back(s.Num);
  }
}

void Vectors2ListOfShapes(std::vector<int> tags[4], List_T *list)
{
  for(int dim = 0; dim < 4; dim++){
    Shape s;
    s.Type =
      (dim == 3) ? MSH_VOLUME_FROM_GMODEL :
      (dim == 2) ? MSH_SURF_FROM_GMODEL :
      (dim == 1) ? MSH_SEGM_FROM_GMODEL :
      MSH_POINT_FROM_GMODEL;
    for(unsigned int i = 0; i < tags[dim].size(); i++){
      s.Num = tags[dim][i];
      List_Add(list, &s);
    }
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
  if(GModel::current()->getOCCInternals() &&
     GModel::current()->getOCCInternals()->getChanged())
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
  if(GModel::current()->getOCCInternals() &&
     GModel::current()->getOCCInternals()->getChanged())
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
  if(GModel::current()->getOCCInternals() &&
     GModel::current()->getOCCInternals()->getChanged())
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
  if(GModel::current()->getOCCInternals() &&
     GModel::current()->getOCCInternals()->getChanged())
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
  if(GModel::current()->getOCCInternals())
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
  if(GModel::current()->getOCCInternals())
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
  if(GModel::current()->getOCCInternals())
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
  if(GModel::current()->getOCCInternals())
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
  if(GModel::current()->getOCCInternals())
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
  if(GModel::current()->getOCCInternals())
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
  if(GModel::current()->getOCCInternals()){
    for(int i = -2; i < 4; i++)
      tag = std::max(tag, GModel::current()->getOCCInternals()->getMaxTag(i) + 1);
  }
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

