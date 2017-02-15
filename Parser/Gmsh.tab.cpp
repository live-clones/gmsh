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
     tCharacteristic = 357,
     tLength = 358,
     tParametric = 359,
     tElliptic = 360,
     tRefineMesh = 361,
     tAdaptMesh = 362,
     tRelocateMesh = 363,
     tSetFactory = 364,
     tThruSections = 365,
     tWedge = 366,
     tFillet = 367,
     tChamfer = 368,
     tPlane = 369,
     tRuled = 370,
     tTransfinite = 371,
     tComplex = 372,
     tPhysical = 373,
     tCompound = 374,
     tPeriodic = 375,
     tUsing = 376,
     tPlugin = 377,
     tDegenerated = 378,
     tRecursive = 379,
     tRotate = 380,
     tTranslate = 381,
     tSymmetry = 382,
     tDilate = 383,
     tExtrude = 384,
     tLevelset = 385,
     tAffine = 386,
     tBooleanUnion = 387,
     tBooleanIntersection = 388,
     tBooleanDifference = 389,
     tBooleanSection = 390,
     tBooleanFragments = 391,
     tThickSolid = 392,
     tRecombine = 393,
     tSmoother = 394,
     tSplit = 395,
     tDelete = 396,
     tCoherence = 397,
     tIntersect = 398,
     tMeshAlgorithm = 399,
     tReverse = 400,
     tLayers = 401,
     tScaleLast = 402,
     tHole = 403,
     tAlias = 404,
     tAliasWithOptions = 405,
     tCopyOptions = 406,
     tQuadTriAddVerts = 407,
     tQuadTriNoNewVerts = 408,
     tQuadTriSngl = 409,
     tQuadTriDbl = 410,
     tRecombLaterals = 411,
     tTransfQuadTri = 412,
     tText2D = 413,
     tText3D = 414,
     tInterpolationScheme = 415,
     tTime = 416,
     tCombine = 417,
     tBSpline = 418,
     tBezier = 419,
     tNurbs = 420,
     tNurbsOrder = 421,
     tNurbsKnots = 422,
     tColor = 423,
     tColorTable = 424,
     tFor = 425,
     tIn = 426,
     tEndFor = 427,
     tIf = 428,
     tElseIf = 429,
     tElse = 430,
     tEndIf = 431,
     tExit = 432,
     tAbort = 433,
     tField = 434,
     tReturn = 435,
     tCall = 436,
     tSlide = 437,
     tMacro = 438,
     tShow = 439,
     tHide = 440,
     tGetValue = 441,
     tGetStringValue = 442,
     tGetEnv = 443,
     tGetString = 444,
     tGetNumber = 445,
     tUnique = 446,
     tHomology = 447,
     tCohomology = 448,
     tBetti = 449,
     tExists = 450,
     tFileExists = 451,
     tGMSH_MAJOR_VERSION = 452,
     tGMSH_MINOR_VERSION = 453,
     tGMSH_PATCH_VERSION = 454,
     tGmshExecutableName = 455,
     tSetPartition = 456,
     tNameToString = 457,
     tStringToName = 458,
     tAFFECTDIVIDE = 459,
     tAFFECTTIMES = 460,
     tAFFECTMINUS = 461,
     tAFFECTPLUS = 462,
     tOR = 463,
     tAND = 464,
     tNOTEQUAL = 465,
     tEQUAL = 466,
     tGREATEROREQUAL = 467,
     tLESSOREQUAL = 468,
     UNARYPREC = 469,
     tMINUSMINUS = 470,
     tPLUSPLUS = 471
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
#define tCharacteristic 357
#define tLength 358
#define tParametric 359
#define tElliptic 360
#define tRefineMesh 361
#define tAdaptMesh 362
#define tRelocateMesh 363
#define tSetFactory 364
#define tThruSections 365
#define tWedge 366
#define tFillet 367
#define tChamfer 368
#define tPlane 369
#define tRuled 370
#define tTransfinite 371
#define tComplex 372
#define tPhysical 373
#define tCompound 374
#define tPeriodic 375
#define tUsing 376
#define tPlugin 377
#define tDegenerated 378
#define tRecursive 379
#define tRotate 380
#define tTranslate 381
#define tSymmetry 382
#define tDilate 383
#define tExtrude 384
#define tLevelset 385
#define tAffine 386
#define tBooleanUnion 387
#define tBooleanIntersection 388
#define tBooleanDifference 389
#define tBooleanSection 390
#define tBooleanFragments 391
#define tThickSolid 392
#define tRecombine 393
#define tSmoother 394
#define tSplit 395
#define tDelete 396
#define tCoherence 397
#define tIntersect 398
#define tMeshAlgorithm 399
#define tReverse 400
#define tLayers 401
#define tScaleLast 402
#define tHole 403
#define tAlias 404
#define tAliasWithOptions 405
#define tCopyOptions 406
#define tQuadTriAddVerts 407
#define tQuadTriNoNewVerts 408
#define tQuadTriSngl 409
#define tQuadTriDbl 410
#define tRecombLaterals 411
#define tTransfQuadTri 412
#define tText2D 413
#define tText3D 414
#define tInterpolationScheme 415
#define tTime 416
#define tCombine 417
#define tBSpline 418
#define tBezier 419
#define tNurbs 420
#define tNurbsOrder 421
#define tNurbsKnots 422
#define tColor 423
#define tColorTable 424
#define tFor 425
#define tIn 426
#define tEndFor 427
#define tIf 428
#define tElseIf 429
#define tElse 430
#define tEndIf 431
#define tExit 432
#define tAbort 433
#define tField 434
#define tReturn 435
#define tCall 436
#define tSlide 437
#define tMacro 438
#define tShow 439
#define tHide 440
#define tGetValue 441
#define tGetStringValue 442
#define tGetEnv 443
#define tGetString 444
#define tGetNumber 445
#define tUnique 446
#define tHomology 447
#define tCohomology 448
#define tBetti 449
#define tExists 450
#define tFileExists 451
#define tGMSH_MAJOR_VERSION 452
#define tGMSH_MINOR_VERSION 453
#define tGMSH_PATCH_VERSION 454
#define tGmshExecutableName 455
#define tSetPartition 456
#define tNameToString 457
#define tStringToName 458
#define tAFFECTDIVIDE 459
#define tAFFECTTIMES 460
#define tAFFECTMINUS 461
#define tAFFECTPLUS 462
#define tOR 463
#define tAND 464
#define tNOTEQUAL 465
#define tEQUAL 466
#define tGREATEROREQUAL 467
#define tLESSOREQUAL 468
#define UNARYPREC 469
#define tMINUSMINUS 470
#define tPLUSPLUS 471




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
#line 662 "Gmsh.tab.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 675 "Gmsh.tab.cpp"

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
#define YYLAST   15116

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  237
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  105
/* YYNRULES -- Number of rules.  */
#define YYNRULES  598
/* YYNRULES -- Number of states.  */
#define YYNSTATES  2242

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   471

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   222,     2,   232,     2,   221,     2,     2,
     227,   228,   219,   217,   233,   218,   231,   220,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     213,     2,   214,   208,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   229,     2,   230,   226,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   234,     2,   235,   236,     2,     2,     2,
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
     205,   206,   207,   209,   210,   211,   212,   215,   216,   223,
     224,   225
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
     946,   954,   966,   975,   980,   989,   998,  1007,  1016,  1026,
    1030,  1035,  1046,  1054,  1062,  1070,  1078,  1086,  1094,  1102,
    1110,  1118,  1126,  1135,  1140,  1149,  1162,  1171,  1180,  1188,
    1196,  1205,  1210,  1219,  1228,  1234,  1246,  1252,  1262,  1272,
    1277,  1287,  1297,  1299,  1301,  1302,  1305,  1312,  1319,  1326,
    1333,  1342,  1353,  1368,  1385,  1398,  1413,  1428,  1443,  1458,
    1467,  1476,  1483,  1488,  1495,  1502,  1506,  1511,  1517,  1524,
    1530,  1534,  1538,  1543,  1549,  1554,  1560,  1564,  1570,  1578,
    1586,  1590,  1598,  1602,  1605,  1608,  1611,  1614,  1617,  1633,
    1636,  1639,  1642,  1645,  1648,  1665,  1677,  1684,  1693,  1702,
    1713,  1715,  1718,  1721,  1723,  1727,  1731,  1736,  1741,  1743,
    1745,  1751,  1763,  1777,  1778,  1786,  1787,  1801,  1802,  1818,
    1819,  1826,  1836,  1839,  1843,  1854,  1863,  1872,  1881,  1894,
    1907,  1920,  1935,  1950,  1965,  1966,  1979,  1980,  1993,  1994,
    2007,  2008,  2025,  2026,  2043,  2044,  2061,  2062,  2081,  2082,
    2101,  2102,  2121,  2123,  2126,  2132,  2140,  2150,  2153,  2156,
    2160,  2163,  2167,  2170,  2174,  2177,  2181,  2184,  2188,  2198,
    2205,  2207,  2209,  2211,  2213,  2215,  2216,  2219,  2223,  2233,
    2238,  2253,  2254,  2258,  2259,  2261,  2262,  2265,  2266,  2269,
    2270,  2273,  2281,  2288,  2297,  2303,  2307,  2316,  2322,  2327,
    2334,  2346,  2358,  2377,  2396,  2409,  2422,  2435,  2446,  2457,
    2468,  2479,  2490,  2495,  2500,  2505,  2510,  2515,  2518,  2522,
    2529,  2531,  2533,  2535,  2538,  2544,  2552,  2563,  2565,  2569,
    2572,  2575,  2578,  2582,  2586,  2590,  2594,  2598,  2602,  2606,
    2610,  2614,  2618,  2622,  2626,  2630,  2634,  2640,  2645,  2650,
    2655,  2660,  2665,  2670,  2675,  2680,  2685,  2690,  2697,  2702,
    2707,  2712,  2717,  2722,  2727,  2732,  2739,  2746,  2753,  2758,
    2760,  2762,  2764,  2766,  2768,  2770,  2772,  2774,  2776,  2778,
    2780,  2781,  2788,  2793,  2800,  2802,  2807,  2812,  2817,  2822,
    2827,  2832,  2837,  2840,  2846,  2852,  2858,  2864,  2868,  2875,
    2880,  2888,  2895,  2902,  2909,  2914,  2921,  2926,  2928,  2931,
    2934,  2938,  2942,  2954,  2964,  2972,  2980,  2982,  2986,  2988,
    2990,  2993,  2997,  3002,  3008,  3010,  3012,  3015,  3019,  3023,
    3029,  3034,  3037,  3040,  3043,  3046,  3050,  3054,  3058,  3062,
    3068,  3074,  3080,  3086,  3103,  3120,  3137,  3154,  3156,  3158,
    3160,  3164,  3168,  3173,  3178,  3183,  3190,  3197,  3204,  3211,
    3220,  3229,  3234,  3249,  3254,  3256,  3258,  3262,  3266,  3276,
    3284,  3286,  3292,  3296,  3303,  3305,  3309,  3311,  3313,  3318,
    3323,  3328,  3333,  3337,  3344,  3346,  3351,  3353,  3355,  3357,
    3362,  3369,  3374,  3381,  3386,  3391,  3396,  3405,  3410,  3415,
    3420,  3425,  3434,  3443,  3450,  3455,  3462,  3467,  3469,  3474,
    3479,  3480,  3487,  3489,  3493,  3499,  3505,  3507,  3509
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     238,     0,    -1,   239,    -1,     1,     6,    -1,    -1,   239,
     240,    -1,   243,    -1,   242,    -1,   263,    -1,   282,    -1,
     283,    -1,   287,    -1,   288,    -1,   289,    -1,   290,    -1,
     294,    -1,   312,    -1,   313,    -1,   319,    -1,   320,    -1,
     293,    -1,   292,    -1,   291,    -1,   286,    -1,   322,    -1,
     214,    -1,   214,   214,    -1,    42,   227,   336,   228,     6,
      -1,    43,   227,   336,   228,     6,    -1,    42,   227,   336,
     228,   241,   336,     6,    -1,    42,   227,   336,   233,   332,
     228,     6,    -1,    43,   227,   336,   233,   332,   228,     6,
      -1,    42,   227,   336,   233,   332,   228,   241,   336,     6,
      -1,     4,   336,   234,   244,   235,     6,    -1,   149,     4,
     229,   323,   230,     6,    -1,   150,     4,   229,   323,   230,
       6,    -1,   151,     4,   229,   323,   233,   323,   230,     6,
      -1,    -1,   244,   247,    -1,   244,   251,    -1,   244,   254,
      -1,   244,   256,    -1,   244,   257,    -1,   323,    -1,   245,
     233,   323,    -1,   323,    -1,   246,   233,   323,    -1,    -1,
      -1,     4,   248,   227,   245,   228,   249,   234,   246,   235,
       6,    -1,   336,    -1,   250,   233,   336,    -1,    -1,   158,
     227,   323,   233,   323,   233,   323,   228,   252,   234,   250,
     235,     6,    -1,   336,    -1,   253,   233,   336,    -1,    -1,
     159,   227,   323,   233,   323,   233,   323,   233,   323,   228,
     255,   234,   253,   235,     6,    -1,   160,   234,   328,   235,
     234,   328,   235,     6,    -1,   160,   234,   328,   235,   234,
     328,   235,   234,   328,   235,   234,   328,   235,     6,    -1,
      -1,   161,   258,   234,   246,   235,     6,    -1,     7,    -1,
     207,    -1,   206,    -1,   205,    -1,   204,    -1,   225,    -1,
     224,    -1,   227,    -1,   229,    -1,   228,    -1,   230,    -1,
      78,   229,   265,   230,     6,    -1,    79,   229,   270,   230,
       6,    -1,    82,   261,   337,   233,   323,   262,     6,    -1,
      83,   261,   341,   233,   337,   262,     6,    -1,   341,   259,
     329,     6,    -1,   341,   260,     6,    -1,     4,   229,   230,
     259,   329,     6,    -1,   340,   229,   230,   259,   329,     6,
      -1,     4,   229,   323,   230,   259,   323,     6,    -1,   340,
     229,   323,   230,   259,   323,     6,    -1,     4,   229,   323,
     230,   260,     6,    -1,   340,   229,   323,   230,   260,     6,
      -1,     4,   261,   234,   332,   235,   262,   259,   329,     6,
      -1,   340,   261,   234,   332,   235,   262,   259,   329,     6,
      -1,     4,   227,   228,   259,   329,     6,    -1,   340,   227,
     228,   259,   329,     6,    -1,     4,   227,   323,   228,   259,
     323,     6,    -1,   340,   227,   323,   228,   259,   323,     6,
      -1,     4,   227,   323,   228,   260,     6,    -1,   340,   227,
     323,   228,   260,     6,    -1,   341,     7,   337,     6,    -1,
       4,   229,   230,     7,    44,   261,   262,     6,    -1,   340,
     229,   230,     7,    44,   261,   262,     6,    -1,     4,   229,
     230,     7,    44,   261,   339,   262,     6,    -1,   340,   229,
     230,     7,    44,   261,   339,   262,     6,    -1,     4,   229,
     230,   207,    44,   261,   339,   262,     6,    -1,   340,   229,
     230,   207,    44,   261,   339,   262,     6,    -1,     4,   227,
     228,     7,    44,   261,   262,     6,    -1,   340,   227,   228,
       7,    44,   261,   262,     6,    -1,     4,   227,   228,     7,
      44,   261,   339,   262,     6,    -1,   340,   227,   228,     7,
      44,   261,   339,   262,     6,    -1,     4,   227,   228,   207,
      44,   261,   339,   262,     6,    -1,   340,   227,   228,   207,
      44,   261,   339,   262,     6,    -1,     4,   231,     4,     7,
     337,     6,    -1,     4,   229,   323,   230,   231,     4,     7,
     337,     6,    -1,     4,   231,     4,   259,   323,     6,    -1,
       4,   229,   323,   230,   231,     4,   259,   323,     6,    -1,
       4,   231,     4,   260,     6,    -1,     4,   229,   323,   230,
     231,     4,   260,     6,    -1,     4,   231,   168,   231,     4,
       7,   333,     6,    -1,     4,   229,   323,   230,   231,   168,
     231,     4,     7,   333,     6,    -1,     4,   231,   169,     7,
     334,     6,    -1,     4,   229,   323,   230,   231,   169,     7,
     334,     6,    -1,     4,   179,     7,   323,     6,    -1,   179,
     229,   323,   230,     7,     4,     6,    -1,   179,   229,   323,
     230,   231,     4,     7,   323,     6,    -1,   179,   229,   323,
     230,   231,     4,     7,   337,     6,    -1,   179,   229,   323,
     230,   231,     4,     7,   234,   332,   235,     6,    -1,   179,
     229,   323,   230,   231,     4,     6,    -1,   122,   227,     4,
     228,   231,     4,     7,   323,     6,    -1,   122,   227,     4,
     228,   231,     4,     7,   337,     6,    -1,    -1,   233,    -1,
      -1,   265,   264,   341,    -1,   265,   264,   341,     7,   323,
      -1,    -1,   265,   264,   341,     7,   234,   329,   266,   272,
     235,    -1,    -1,   265,   264,   341,   229,   230,     7,   234,
     329,   267,   272,   235,    -1,    -1,   265,   264,   341,   227,
     228,     7,   234,   329,   268,   272,   235,    -1,   265,   264,
     341,     7,   337,    -1,    -1,   265,   264,   341,     7,   234,
     337,   269,   274,   235,    -1,    -1,   270,   264,   336,    -1,
     323,     7,   337,    -1,   271,   233,   323,     7,   337,    -1,
     331,     7,   341,   227,   228,    -1,    -1,   272,   273,    -1,
     233,     4,   329,    -1,   233,     4,   234,   271,   235,    -1,
     233,     4,   337,    -1,    -1,   274,   275,    -1,   233,     4,
     323,    -1,   233,     4,   337,    -1,   233,   183,   337,    -1,
     233,     4,   234,   339,   235,    -1,   323,    -1,   337,    -1,
     337,   233,   323,    -1,   323,    -1,   337,    -1,   337,   233,
     323,    -1,   323,    -1,   337,    -1,   337,   233,   323,    -1,
     323,    -1,   337,    -1,   337,   233,   323,    -1,    -1,   171,
      88,   234,   323,   235,    -1,    -1,   114,   326,    -1,   109,
     227,   336,   228,     6,    -1,    84,   227,   323,   228,     7,
     326,     6,    -1,   118,    84,   227,   276,   228,   259,   329,
       6,    -1,   102,   103,   329,     7,   323,     6,    -1,    87,
     227,   323,   228,     7,   329,     6,    -1,   123,    87,   329,
       6,    -1,    91,   227,   323,   228,     7,   329,     6,    -1,
      85,   227,   323,   228,     7,   329,   281,     6,    -1,    86,
     227,   323,   228,     7,   329,   281,     6,    -1,   163,   227,
     323,   228,     7,   329,     6,    -1,   164,   227,   323,   228,
       7,   329,     6,    -1,   165,   227,   323,   228,     7,   329,
     167,   329,   166,   323,     6,    -1,    87,     4,   227,   323,
     228,     7,   329,     6,    -1,   119,    87,   329,     6,    -1,
     119,    87,   227,   323,   228,     7,   329,     6,    -1,   118,
      87,   227,   277,   228,   259,   329,     6,    -1,   114,    90,
     227,   323,   228,     7,   329,     6,    -1,    90,   227,   323,
     228,     7,   329,   280,     6,    -1,   115,    90,   227,   323,
     228,     7,   329,   280,     6,    -1,    12,    13,     6,    -1,
      13,    90,   323,     6,    -1,   104,    90,   227,   323,   228,
       7,     5,     5,     5,     6,    -1,    88,   227,   323,   228,
       7,   329,     6,    -1,    89,   227,   323,   228,     7,   329,
       6,    -1,    93,   227,   323,   228,     7,   329,     6,    -1,
      96,   227,   323,   228,     7,   329,     6,    -1,   100,   227,
     323,   228,     7,   329,     6,    -1,   101,   227,   323,   228,
       7,   329,     6,    -1,    94,   227,   323,   228,     7,   329,
       6,    -1,    95,   227,   323,   228,     7,   329,     6,    -1,
     111,   227,   323,   228,     7,   329,     6,    -1,   137,   227,
     323,   228,     7,   329,     6,    -1,    90,     4,   227,   323,
     228,     7,   329,     6,    -1,   119,    90,   329,     6,    -1,
     119,    90,   227,   323,   228,     7,   329,     6,    -1,   119,
      90,   227,   323,   228,     7,   329,     4,   234,   328,   235,
       6,    -1,   118,    90,   227,   278,   228,   259,   329,     6,
      -1,   117,    92,   227,   323,   228,     7,   329,     6,    -1,
      92,   227,   323,   228,     7,   329,     6,    -1,   110,   227,
     323,   228,     7,   329,     6,    -1,   115,   110,   227,   323,
     228,     7,   329,     6,    -1,   119,    92,   329,     6,    -1,
     119,    92,   227,   323,   228,     7,   329,     6,    -1,   118,
      92,   227,   279,   228,   259,   329,     6,    -1,   126,   326,
     234,   284,   235,    -1,   125,   234,   326,   233,   326,   233,
     323,   235,   234,   284,   235,    -1,   127,   326,   234,   284,
     235,    -1,   128,   234,   326,   233,   323,   235,   234,   284,
     235,    -1,   128,   234,   326,   233,   326,   235,   234,   284,
     235,    -1,     4,   234,   284,   235,    -1,   143,    87,   234,
     332,   235,    90,   234,   323,   235,    -1,   140,    87,   227,
     323,   228,   234,   332,   235,     6,    -1,   285,    -1,   283,
      -1,    -1,   285,   282,    -1,   285,    84,   234,   332,   235,
       6,    -1,   285,    87,   234,   332,   235,     6,    -1,   285,
      90,   234,   332,   235,     6,    -1,   285,    92,   234,   332,
     235,     6,    -1,   130,   114,   227,   323,   228,     7,   329,
       6,    -1,   130,    84,   227,   323,   228,     7,   234,   328,
     235,     6,    -1,   130,   114,   227,   323,   228,     7,   234,
     326,   233,   326,   233,   332,   235,     6,    -1,   130,   114,
     227,   323,   228,     7,   234,   326,   233,   326,   233,   326,
     233,   332,   235,     6,    -1,   130,    88,   227,   323,   228,
       7,   234,   326,   233,   332,   235,     6,    -1,   130,    94,
     227,   323,   228,     7,   234,   326,   233,   326,   233,   332,
     235,     6,    -1,   130,    95,   227,   323,   228,     7,   234,
     326,   233,   326,   233,   332,   235,     6,    -1,   130,    97,
     227,   323,   228,     7,   234,   326,   233,   326,   233,   332,
     235,     6,    -1,   130,    98,   227,   323,   228,     7,   234,
     326,   233,   326,   233,   332,   235,     6,    -1,   130,     4,
     227,   323,   228,     7,   329,     6,    -1,   130,     4,   227,
     323,   228,     7,     5,     6,    -1,   130,     4,   234,   323,
     235,     6,    -1,   141,   234,   285,   235,    -1,   141,   179,
     229,   323,   230,     6,    -1,   141,     4,   229,   323,   230,
       6,    -1,   141,   341,     6,    -1,   141,     4,     4,     6,
      -1,   168,   333,   234,   285,   235,    -1,   124,   168,   333,
     234,   285,   235,    -1,   201,   323,   234,   285,   235,    -1,
     184,     5,     6,    -1,   185,     5,     6,    -1,   184,   234,
     285,   235,    -1,   124,   184,   234,   285,   235,    -1,   185,
     234,   285,   235,    -1,   124,   185,   234,   285,   235,    -1,
       4,   337,     6,    -1,    71,   227,   339,   228,     6,    -1,
       4,     4,   229,   323,   230,   336,     6,    -1,     4,     4,
       4,   229,   323,   230,     6,    -1,     4,   323,     6,    -1,
     122,   227,     4,   228,   231,     4,     6,    -1,   162,     4,
       6,    -1,   177,     6,    -1,   178,     6,    -1,    68,     6,
      -1,    69,     6,    -1,    62,     6,    -1,    62,   234,   323,
     233,   323,   233,   323,   233,   323,   233,   323,   233,   323,
     235,     6,    -1,    63,     6,    -1,    64,     6,    -1,    75,
       6,    -1,    76,     6,    -1,   106,     6,    -1,   107,   234,
     332,   235,   234,   332,   235,   234,   328,   235,   234,   323,
     233,   323,   235,     6,    -1,   182,   227,   234,   332,   235,
     233,   337,   233,   337,   228,     6,    -1,   170,   227,   323,
       8,   323,   228,    -1,   170,   227,   323,     8,   323,     8,
     323,   228,    -1,   170,     4,   171,   234,   323,     8,   323,
     235,    -1,   170,     4,   171,   234,   323,     8,   323,     8,
     323,   235,    -1,   172,    -1,   183,     4,    -1,   183,   337,
      -1,   180,    -1,   181,   341,     6,    -1,   181,   337,     6,
      -1,   173,   227,   323,   228,    -1,   174,   227,   323,   228,
      -1,   175,    -1,   176,    -1,   129,   326,   234,   285,   235,
      -1,   129,   234,   326,   233,   326,   233,   323,   235,   234,
     285,   235,    -1,   129,   234,   326,   233,   326,   233,   326,
     233,   323,   235,   234,   285,   235,    -1,    -1,   129,   326,
     234,   285,   295,   308,   235,    -1,    -1,   129,   234,   326,
     233,   326,   233,   323,   235,   234,   285,   296,   308,   235,
      -1,    -1,   129,   234,   326,   233,   326,   233,   326,   233,
     323,   235,   234,   285,   297,   308,   235,    -1,    -1,   129,
     234,   285,   298,   308,   235,    -1,   129,   234,   285,   235,
     121,    87,   234,   329,   235,    -1,   110,   329,    -1,   115,
     110,   329,    -1,   112,   234,   332,   235,   234,   332,   235,
     234,   323,   235,    -1,   129,    84,   234,   323,   233,   326,
     235,     6,    -1,   129,    87,   234,   323,   233,   326,   235,
       6,    -1,   129,    90,   234,   323,   233,   326,   235,     6,
      -1,   129,    84,   234,   323,   233,   326,   233,   326,   233,
     323,   235,     6,    -1,   129,    87,   234,   323,   233,   326,
     233,   326,   233,   323,   235,     6,    -1,   129,    90,   234,
     323,   233,   326,   233,   326,   233,   323,   235,     6,    -1,
     129,    84,   234,   323,   233,   326,   233,   326,   233,   326,
     233,   323,   235,     6,    -1,   129,    87,   234,   323,   233,
     326,   233,   326,   233,   326,   233,   323,   235,     6,    -1,
     129,    90,   234,   323,   233,   326,   233,   326,   233,   326,
     233,   323,   235,     6,    -1,    -1,   129,    84,   234,   323,
     233,   326,   235,   299,   234,   308,   235,     6,    -1,    -1,
     129,    87,   234,   323,   233,   326,   235,   300,   234,   308,
     235,     6,    -1,    -1,   129,    90,   234,   323,   233,   326,
     235,   301,   234,   308,   235,     6,    -1,    -1,   129,    84,
     234,   323,   233,   326,   233,   326,   233,   323,   235,   302,
     234,   308,   235,     6,    -1,    -1,   129,    87,   234,   323,
     233,   326,   233,   326,   233,   323,   235,   303,   234,   308,
     235,     6,    -1,    -1,   129,    90,   234,   323,   233,   326,
     233,   326,   233,   323,   235,   304,   234,   308,   235,     6,
      -1,    -1,   129,    84,   234,   323,   233,   326,   233,   326,
     233,   326,   233,   323,   235,   305,   234,   308,   235,     6,
      -1,    -1,   129,    87,   234,   323,   233,   326,   233,   326,
     233,   326,   233,   323,   235,   306,   234,   308,   235,     6,
      -1,    -1,   129,    90,   234,   323,   233,   326,   233,   326,
     233,   326,   233,   323,   235,   307,   234,   308,   235,     6,
      -1,   309,    -1,   308,   309,    -1,   146,   234,   323,   235,
       6,    -1,   146,   234,   329,   233,   329,   235,     6,    -1,
     146,   234,   329,   233,   329,   233,   329,   235,     6,    -1,
     147,     6,    -1,   138,     6,    -1,   138,   323,     6,    -1,
     154,     6,    -1,   154,   156,     6,    -1,   155,     6,    -1,
     155,   156,     6,    -1,   152,     6,    -1,   152,   156,     6,
      -1,   153,     6,    -1,   153,   156,     6,    -1,   148,   227,
     323,   228,     7,   329,   121,   323,     6,    -1,   121,     4,
     229,   323,   230,     6,    -1,   132,    -1,   133,    -1,   134,
      -1,   135,    -1,   136,    -1,    -1,   141,     6,    -1,   141,
     323,     6,    -1,   310,   234,   285,   311,   235,   234,   285,
     311,   235,    -1,    99,   227,   336,   228,    -1,   310,   227,
     323,   228,     7,   234,   285,   311,   235,   234,   285,   311,
     235,     6,    -1,    -1,   121,     4,   323,    -1,    -1,     4,
      -1,    -1,     7,   329,    -1,    -1,     7,   323,    -1,    -1,
     131,   329,    -1,   116,    87,   330,     7,   323,   314,     6,
      -1,   116,    90,   330,   316,   315,     6,    -1,   105,    90,
     234,   323,   235,     7,   329,     6,    -1,   116,    92,   330,
     316,     6,    -1,   157,   330,     6,    -1,   144,    90,   234,
     332,   235,     7,   323,     6,    -1,   138,    90,   330,   317,
       6,    -1,   138,    92,   330,     6,    -1,   139,    90,   329,
       7,   323,     6,    -1,   120,    87,   234,   332,   235,     7,
     234,   332,   235,   318,     6,    -1,   120,    90,   234,   332,
     235,     7,   234,   332,   235,   318,     6,    -1,   120,    87,
     234,   332,   235,     7,   234,   332,   235,   125,   234,   326,
     233,   326,   233,   323,   235,     6,    -1,   120,    90,   234,
     332,   235,     7,   234,   332,   235,   125,   234,   326,   233,
     326,   233,   323,   235,     6,    -1,   120,    87,   234,   332,
     235,     7,   234,   332,   235,   126,   326,     6,    -1,   120,
      90,   234,   332,   235,     7,   234,   332,   235,   126,   326,
       6,    -1,   120,    90,   323,   234,   332,   235,     7,   323,
     234,   332,   235,     6,    -1,    84,   234,   332,   235,   171,
      90,   234,   323,   235,     6,    -1,    87,   234,   332,   235,
     171,    90,   234,   323,   235,     6,    -1,    84,   234,   332,
     235,   171,    92,   234,   323,   235,     6,    -1,    87,   234,
     332,   235,   171,    92,   234,   323,   235,     6,    -1,    90,
     234,   332,   235,   171,    92,   234,   323,   235,     6,    -1,
     145,    90,   330,     6,    -1,   145,    87,   330,     6,    -1,
     108,    84,   330,     6,    -1,   108,    87,   330,     6,    -1,
     108,    90,   330,     6,    -1,   142,     6,    -1,   142,     4,
       6,    -1,   142,    84,   234,   332,   235,     6,    -1,   192,
      -1,   193,    -1,   194,    -1,   321,     6,    -1,   321,   234,
     329,   235,     6,    -1,   321,   234,   329,   233,   329,   235,
       6,    -1,   321,   227,   329,   228,   234,   329,   233,   329,
     235,     6,    -1,   324,    -1,   227,   323,   228,    -1,   218,
     323,    -1,   217,   323,    -1,   222,   323,    -1,   323,   218,
     323,    -1,   323,   217,   323,    -1,   323,   219,   323,    -1,
     323,   220,   323,    -1,   323,   221,   323,    -1,   323,   226,
     323,    -1,   323,   213,   323,    -1,   323,   214,   323,    -1,
     323,   216,   323,    -1,   323,   215,   323,    -1,   323,   212,
     323,    -1,   323,   211,   323,    -1,   323,   210,   323,    -1,
     323,   209,   323,    -1,   323,   208,   323,     8,   323,    -1,
      15,   261,   323,   262,    -1,    16,   261,   323,   262,    -1,
      17,   261,   323,   262,    -1,    18,   261,   323,   262,    -1,
      19,   261,   323,   262,    -1,    20,   261,   323,   262,    -1,
      21,   261,   323,   262,    -1,    22,   261,   323,   262,    -1,
      23,   261,   323,   262,    -1,    25,   261,   323,   262,    -1,
      26,   261,   323,   233,   323,   262,    -1,    27,   261,   323,
     262,    -1,    28,   261,   323,   262,    -1,    29,   261,   323,
     262,    -1,    30,   261,   323,   262,    -1,    31,   261,   323,
     262,    -1,    32,   261,   323,   262,    -1,    33,   261,   323,
     262,    -1,    34,   261,   323,   233,   323,   262,    -1,    35,
     261,   323,   233,   323,   262,    -1,    36,   261,   323,   233,
     323,   262,    -1,    24,   261,   323,   262,    -1,     3,    -1,
       9,    -1,    14,    -1,    10,    -1,    11,    -1,   197,    -1,
     198,    -1,   199,    -1,    72,    -1,    73,    -1,    74,    -1,
      -1,    80,   261,   323,   325,   272,   262,    -1,   190,   261,
     336,   262,    -1,   190,   261,   336,   233,   323,   262,    -1,
     341,    -1,     4,   229,   323,   230,    -1,     4,   227,   323,
     228,    -1,   340,   229,   323,   230,    -1,   340,   227,   323,
     228,    -1,   195,   227,   341,   228,    -1,   196,   227,   337,
     228,    -1,   232,   341,   261,   262,    -1,   341,   260,    -1,
       4,   229,   323,   230,   260,    -1,     4,   227,   323,   228,
     260,    -1,   340,   229,   323,   230,   260,    -1,   340,   227,
     323,   228,   260,    -1,     4,   231,     4,    -1,     4,   229,
     323,   230,   231,     4,    -1,     4,   231,     4,   260,    -1,
       4,   229,   323,   230,   231,     4,   260,    -1,   186,   227,
     336,   233,   323,   228,    -1,    54,   227,   329,   233,   329,
     228,    -1,    55,   261,   336,   233,   336,   262,    -1,    53,
     261,   336,   262,    -1,    56,   261,   336,   233,   336,   262,
      -1,    61,   227,   339,   228,    -1,   327,    -1,   218,   326,
      -1,   217,   326,    -1,   326,   218,   326,    -1,   326,   217,
     326,    -1,   234,   323,   233,   323,   233,   323,   233,   323,
     233,   323,   235,    -1,   234,   323,   233,   323,   233,   323,
     233,   323,   235,    -1,   234,   323,   233,   323,   233,   323,
     235,    -1,   227,   323,   233,   323,   233,   323,   228,    -1,
     329,    -1,   328,   233,   329,    -1,   323,    -1,   331,    -1,
     234,   235,    -1,   234,   332,   235,    -1,   218,   234,   332,
     235,    -1,   323,   219,   234,   332,   235,    -1,   329,    -1,
       5,    -1,   218,   331,    -1,   323,   219,   331,    -1,   323,
       8,   323,    -1,   323,     8,   323,     8,   323,    -1,    84,
     234,   323,   235,    -1,    84,     5,    -1,    87,     5,    -1,
      90,     5,    -1,    92,     5,    -1,   118,    84,     5,    -1,
     118,    87,     5,    -1,   118,    90,     5,    -1,   118,    92,
       5,    -1,   118,    84,   234,   332,   235,    -1,   118,    87,
     234,   332,   235,    -1,   118,    90,   234,   332,   235,    -1,
     118,    92,   234,   332,   235,    -1,    84,   171,    62,   234,
     323,   233,   323,   233,   323,   233,   323,   233,   323,   233,
     323,   235,    -1,    87,   171,    62,   234,   323,   233,   323,
     233,   323,   233,   323,   233,   323,   233,   323,   235,    -1,
      90,   171,    62,   234,   323,   233,   323,   233,   323,   233,
     323,   233,   323,   233,   323,   235,    -1,    92,   171,    62,
     234,   323,   233,   323,   233,   323,   233,   323,   233,   323,
     233,   323,   235,    -1,   283,    -1,   294,    -1,   312,    -1,
       4,   261,   262,    -1,   340,   261,   262,    -1,    37,   229,
     341,   230,    -1,    37,   229,   331,   230,    -1,    37,   227,
     331,   228,    -1,    37,   229,   234,   332,   235,   230,    -1,
      37,   227,   234,   332,   235,   228,    -1,     4,   261,   234,
     332,   235,   262,    -1,   340,   261,   234,   332,   235,   262,
      -1,    38,   261,   323,   233,   323,   233,   323,   262,    -1,
      39,   261,   323,   233,   323,   233,   323,   262,    -1,    40,
     261,   336,   262,    -1,    41,   261,   323,   233,   323,   233,
     323,   233,   323,   233,   323,   233,   323,   262,    -1,   191,
     261,   331,   262,    -1,   323,    -1,   331,    -1,   332,   233,
     323,    -1,   332,   233,   331,    -1,   234,   323,   233,   323,
     233,   323,   233,   323,   235,    -1,   234,   323,   233,   323,
     233,   323,   235,    -1,   341,    -1,     4,   231,   168,   231,
       4,    -1,   234,   335,   235,    -1,     4,   229,   323,   230,
     231,   169,    -1,   333,    -1,   335,   233,   333,    -1,   337,
      -1,   341,    -1,     4,   229,   323,   230,    -1,   340,   229,
     323,   230,    -1,     4,   227,   323,   228,    -1,   340,   227,
     323,   228,    -1,     4,   231,     4,    -1,     4,   229,   323,
     230,   231,     4,    -1,     5,    -1,   202,   229,   341,   230,
      -1,    65,    -1,   200,    -1,    70,    -1,   188,   227,   336,
     228,    -1,   187,   227,   336,   233,   336,   228,    -1,   189,
     261,   336,   262,    -1,   189,   261,   336,   233,   336,   262,
      -1,    46,   261,   339,   262,    -1,    47,   227,   336,   228,
      -1,    48,   227,   336,   228,    -1,    49,   227,   336,   233,
     336,   233,   336,   228,    -1,    44,   261,   339,   262,    -1,
      58,   261,   336,   262,    -1,    59,   261,   336,   262,    -1,
      60,   261,   336,   262,    -1,    57,   261,   323,   233,   336,
     233,   336,   262,    -1,    52,   261,   336,   233,   323,   233,
     323,   262,    -1,    52,   261,   336,   233,   323,   262,    -1,
      45,   261,   336,   262,    -1,    45,   261,   336,   233,   332,
     262,    -1,    66,   261,   336,   262,    -1,    67,    -1,    51,
     261,   336,   262,    -1,    50,   261,   336,   262,    -1,    -1,
      81,   261,   337,   338,   274,   262,    -1,   336,    -1,   339,
     233,   336,    -1,     4,   236,   234,   323,   235,    -1,   340,
     236,   234,   323,   235,    -1,     4,    -1,   340,    -1,   203,
     229,   336,   230,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   210,   210,   211,   216,   218,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   244,   248,   255,   260,   265,
     279,   292,   305,   333,   347,   360,   373,   392,   397,   398,
     399,   400,   401,   405,   407,   412,   414,   420,   524,   419,
     542,   549,   560,   559,   577,   584,   595,   594,   611,   628,
     651,   650,   664,   665,   666,   667,   668,   672,   673,   679,
     679,   680,   680,   686,   687,   688,   693,   699,   761,   778,
     807,   836,   841,   846,   851,   856,   863,   873,   902,   931,
     936,   941,   946,   954,   963,   969,   975,   988,  1001,  1016,
    1033,  1039,  1045,  1058,  1071,  1086,  1103,  1109,  1118,  1136,
    1154,  1163,  1175,  1180,  1188,  1208,  1231,  1242,  1250,  1272,
    1295,  1333,  1354,  1366,  1380,  1380,  1382,  1384,  1393,  1403,
    1402,  1423,  1422,  1441,  1440,  1458,  1468,  1467,  1481,  1483,
    1491,  1497,  1502,  1528,  1529,  1533,  1544,  1559,  1569,  1570,
    1575,  1583,  1592,  1600,  1618,  1622,  1628,  1636,  1640,  1646,
    1654,  1658,  1664,  1672,  1676,  1682,  1691,  1694,  1707,  1710,
    1718,  1728,  1756,  1799,  1822,  1851,  1872,  1890,  1947,  2012,
    2039,  2066,  2093,  2122,  2127,  2145,  2191,  2219,  2270,  2321,
    2327,  2333,  2340,  2382,  2408,  2432,  2456,  2481,  2504,  2531,
    2559,  2584,  2607,  2634,  2638,  2657,  2691,  2738,  2756,  2783,
    2802,  2821,  2825,  2841,  2889,  2906,  2924,  2934,  2944,  2954,
    3017,  3028,  3044,  3045,  3050,  3053,  3057,  3086,  3115,  3144,
    3178,  3200,  3226,  3248,  3271,  3292,  3348,  3372,  3397,  3423,
    3536,  3555,  3598,  3619,  3625,  3640,  3668,  3685,  3694,  3708,
    3722,  3728,  3734,  3743,  3752,  3761,  3775,  3837,  3855,  3872,
    3887,  3916,  3928,  3952,  3956,  3961,  3969,  3974,  3980,  3985,
    3991,  3999,  4003,  4007,  4012,  4072,  4088,  4105,  4122,  4144,
    4166,  4201,  4209,  4217,  4223,  4230,  4237,  4257,  4283,  4295,
    4307,  4337,  4368,  4377,  4376,  4391,  4390,  4405,  4404,  4419,
    4418,  4431,  4464,  4487,  4510,  4541,  4548,  4555,  4562,  4569,
    4576,  4583,  4590,  4597,  4605,  4604,  4618,  4617,  4631,  4630,
    4644,  4643,  4657,  4656,  4670,  4669,  4683,  4682,  4696,  4695,
    4709,  4708,  4725,  4728,  4734,  4746,  4766,  4790,  4794,  4798,
    4802,  4806,  4810,  4816,  4822,  4826,  4830,  4834,  4838,  4857,
    4870,  4871,  4872,  4873,  4874,  4878,  4879,  4880,  4883,  4917,
    4943,  4967,  4970,  4986,  4989,  5006,  5009,  5015,  5018,  5025,
    5028,  5035,  5091,  5161,  5166,  5233,  5269,  5277,  5320,  5359,
    5379,  5411,  5438,  5464,  5490,  5516,  5542,  5564,  5592,  5620,
    5648,  5676,  5704,  5743,  5782,  5803,  5824,  5851,  5855,  5865,
    5900,  5901,  5902,  5906,  5912,  5924,  5942,  5970,  5971,  5972,
    5973,  5974,  5975,  5976,  5977,  5978,  5985,  5986,  5987,  5988,
    5989,  5990,  5991,  5992,  5993,  5994,  5995,  5996,  5997,  5998,
    5999,  6000,  6001,  6002,  6003,  6004,  6005,  6006,  6007,  6008,
    6009,  6010,  6011,  6012,  6013,  6014,  6015,  6016,  6017,  6026,
    6027,  6028,  6029,  6030,  6031,  6032,  6033,  6034,  6035,  6036,
    6041,  6040,  6048,  6053,  6058,  6075,  6093,  6111,  6129,  6147,
    6152,  6158,  6173,  6192,  6212,  6232,  6252,  6275,  6280,  6285,
    6295,  6305,  6310,  6321,  6330,  6335,  6340,  6367,  6371,  6375,
    6379,  6383,  6390,  6394,  6398,  6402,  6409,  6414,  6421,  6426,
    6430,  6435,  6439,  6447,  6458,  6462,  6474,  6482,  6490,  6497,
    6507,  6536,  6540,  6544,  6548,  6552,  6556,  6560,  6564,  6568,
    6597,  6626,  6655,  6684,  6697,  6710,  6723,  6736,  6746,  6756,
    6766,  6778,  6791,  6803,  6807,  6811,  6815,  6819,  6837,  6855,
    6863,  6871,  6900,  6910,  6929,  6934,  6938,  6942,  6954,  6958,
    6970,  6987,  6997,  7001,  7016,  7021,  7028,  7032,  7045,  7059,
    7073,  7087,  7101,  7109,  7120,  7124,  7128,  7136,  7142,  7148,
    7156,  7164,  7171,  7179,  7194,  7208,  7222,  7234,  7250,  7259,
    7268,  7278,  7289,  7297,  7305,  7309,  7328,  7335,  7341,  7348,
    7356,  7355,  7368,  7373,  7379,  7388,  7401,  7404,  7408
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
  "tRectangle", "tDisk", "tCharacteristic", "tLength", "tParametric",
  "tElliptic", "tRefineMesh", "tAdaptMesh", "tRelocateMesh", "tSetFactory",
  "tThruSections", "tWedge", "tFillet", "tChamfer", "tPlane", "tRuled",
  "tTransfinite", "tComplex", "tPhysical", "tCompound", "tPeriodic",
  "tUsing", "tPlugin", "tDegenerated", "tRecursive", "tRotate",
  "tTranslate", "tSymmetry", "tDilate", "tExtrude", "tLevelset", "tAffine",
  "tBooleanUnion", "tBooleanIntersection", "tBooleanDifference",
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
     455,   456,   457,   458,   459,   460,   461,   462,    63,   463,
     464,   465,   466,    60,    62,   467,   468,    43,    45,    42,
      47,    37,    33,   469,   470,   471,    94,    40,    41,    91,
      93,    46,    35,    44,   123,   125,   126
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   237,   238,   238,   239,   239,   240,   240,   240,   240,
     240,   240,   240,   240,   240,   240,   240,   240,   240,   240,
     240,   240,   240,   240,   240,   241,   241,   242,   242,   242,
     242,   242,   242,   243,   243,   243,   243,   244,   244,   244,
     244,   244,   244,   245,   245,   246,   246,   248,   249,   247,
     250,   250,   252,   251,   253,   253,   255,   254,   256,   256,
     258,   257,   259,   259,   259,   259,   259,   260,   260,   261,
     261,   262,   262,   263,   263,   263,   263,   263,   263,   263,
     263,   263,   263,   263,   263,   263,   263,   263,   263,   263,
     263,   263,   263,   263,   263,   263,   263,   263,   263,   263,
     263,   263,   263,   263,   263,   263,   263,   263,   263,   263,
     263,   263,   263,   263,   263,   263,   263,   263,   263,   263,
     263,   263,   263,   263,   264,   264,   265,   265,   265,   266,
     265,   267,   265,   268,   265,   265,   269,   265,   270,   270,
     271,   271,   271,   272,   272,   273,   273,   273,   274,   274,
     275,   275,   275,   275,   276,   276,   276,   277,   277,   277,
     278,   278,   278,   279,   279,   279,   280,   280,   281,   281,
     282,   282,   282,   282,   282,   282,   282,   282,   282,   282,
     282,   282,   282,   282,   282,   282,   282,   282,   282,   282,
     282,   282,   282,   282,   282,   282,   282,   282,   282,   282,
     282,   282,   282,   282,   282,   282,   282,   282,   282,   282,
     282,   282,   282,   282,   283,   283,   283,   283,   283,   283,
     283,   283,   284,   284,   285,   285,   285,   285,   285,   285,
     286,   286,   286,   286,   286,   286,   286,   286,   286,   286,
     286,   286,   287,   287,   287,   287,   287,   288,   288,   289,
     290,   290,   290,   290,   290,   290,   291,   291,   291,   291,
     291,   291,   291,   291,   291,   291,   291,   291,   291,   291,
     291,   291,   291,   291,   291,   292,   293,   293,   293,   293,
     293,   293,   293,   293,   293,   293,   293,   293,   293,   293,
     294,   294,   294,   295,   294,   296,   294,   297,   294,   298,
     294,   294,   294,   294,   294,   294,   294,   294,   294,   294,
     294,   294,   294,   294,   299,   294,   300,   294,   301,   294,
     302,   294,   303,   294,   304,   294,   305,   294,   306,   294,
     307,   294,   308,   308,   309,   309,   309,   309,   309,   309,
     309,   309,   309,   309,   309,   309,   309,   309,   309,   309,
     310,   310,   310,   310,   310,   311,   311,   311,   312,   312,
     313,   314,   314,   315,   315,   316,   316,   317,   317,   318,
     318,   319,   319,   319,   319,   319,   319,   319,   319,   319,
     319,   319,   319,   319,   319,   319,   319,   319,   319,   319,
     319,   319,   319,   319,   319,   319,   319,   320,   320,   320,
     321,   321,   321,   322,   322,   322,   322,   323,   323,   323,
     323,   323,   323,   323,   323,   323,   323,   323,   323,   323,
     323,   323,   323,   323,   323,   323,   323,   323,   323,   323,
     323,   323,   323,   323,   323,   323,   323,   323,   323,   323,
     323,   323,   323,   323,   323,   323,   323,   323,   323,   324,
     324,   324,   324,   324,   324,   324,   324,   324,   324,   324,
     325,   324,   324,   324,   324,   324,   324,   324,   324,   324,
     324,   324,   324,   324,   324,   324,   324,   324,   324,   324,
     324,   324,   324,   324,   324,   324,   324,   326,   326,   326,
     326,   326,   327,   327,   327,   327,   328,   328,   329,   329,
     329,   329,   329,   329,   330,   330,   331,   331,   331,   331,
     331,   331,   331,   331,   331,   331,   331,   331,   331,   331,
     331,   331,   331,   331,   331,   331,   331,   331,   331,   331,
     331,   331,   331,   331,   331,   331,   331,   331,   331,   331,
     331,   331,   331,   331,   332,   332,   332,   332,   333,   333,
     333,   333,   334,   334,   335,   335,   336,   336,   336,   336,
     336,   336,   336,   336,   337,   337,   337,   337,   337,   337,
     337,   337,   337,   337,   337,   337,   337,   337,   337,   337,
     337,   337,   337,   337,   337,   337,   337,   337,   337,   337,
     338,   337,   339,   339,   340,   340,   341,   341,   341
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
       7,    11,     8,     4,     8,     8,     8,     8,     9,     3,
       4,    10,     7,     7,     7,     7,     7,     7,     7,     7,
       7,     7,     8,     4,     8,    12,     8,     8,     7,     7,
       8,     4,     8,     8,     5,    11,     5,     9,     9,     4,
       9,     9,     1,     1,     0,     2,     6,     6,     6,     6,
       8,    10,    14,    16,    12,    14,    14,    14,    14,     8,
       8,     6,     4,     6,     6,     3,     4,     5,     6,     5,
       3,     3,     4,     5,     4,     5,     3,     5,     7,     7,
       3,     7,     3,     2,     2,     2,     2,     2,    15,     2,
       2,     2,     2,     2,    16,    11,     6,     8,     8,    10,
       1,     2,     2,     1,     3,     3,     4,     4,     1,     1,
       5,    11,    13,     0,     7,     0,    13,     0,    15,     0,
       6,     9,     2,     3,    10,     8,     8,     8,    12,    12,
      12,    14,    14,    14,     0,    12,     0,    12,     0,    12,
       0,    16,     0,    16,     0,    16,     0,    18,     0,    18,
       0,    18,     1,     2,     5,     7,     9,     2,     2,     3,
       2,     3,     2,     3,     2,     3,     2,     3,     9,     6,
       1,     1,     1,     1,     1,     0,     2,     3,     9,     4,
      14,     0,     3,     0,     1,     0,     2,     0,     2,     0,
       2,     7,     6,     8,     5,     3,     8,     5,     4,     6,
      11,    11,    18,    18,    12,    12,    12,    10,    10,    10,
      10,    10,     4,     4,     4,     4,     4,     2,     3,     6,
       1,     1,     1,     2,     5,     7,    10,     1,     3,     2,
       2,     2,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     5,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     6,     4,     4,
       4,     4,     4,     4,     4,     6,     6,     6,     4,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     6,     4,     6,     1,     4,     4,     4,     4,     4,
       4,     4,     2,     5,     5,     5,     5,     3,     6,     4,
       7,     6,     6,     6,     4,     6,     4,     1,     2,     2,
       3,     3,    11,     9,     7,     7,     1,     3,     1,     1,
       2,     3,     4,     5,     1,     1,     2,     3,     3,     5,
       4,     2,     2,     2,     2,     3,     3,     3,     3,     5,
       5,     5,     5,    16,    16,    16,    16,     1,     1,     1,
       3,     3,     4,     4,     4,     6,     6,     6,     6,     8,
       8,     4,    14,     4,     1,     1,     3,     3,     9,     7,
       1,     5,     3,     6,     1,     3,     1,     1,     4,     4,
       4,     4,     3,     6,     1,     4,     1,     1,     1,     4,
       6,     4,     6,     4,     4,     4,     8,     4,     4,     4,
       4,     8,     8,     6,     4,     6,     4,     1,     4,     4,
       0,     6,     1,     3,     5,     5,     1,     1,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     2,     3,     1,   596,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   350,   351,   352,   353,   354,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   280,
       0,     0,   288,   289,     0,     0,     0,   283,     0,     0,
       0,     0,     0,   400,   401,   402,     0,     0,     5,     7,
       6,     8,     9,    10,    23,    11,    12,    13,    14,    22,
      21,    20,    15,     0,    16,    17,    18,    19,     0,    24,
     597,     0,   449,   596,   564,   450,   452,   453,   451,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   566,
       0,   587,   568,   457,   458,   459,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   454,   455,   456,   567,
       0,     0,     0,     0,    69,    70,     0,     0,   224,     0,
       0,     0,   407,     0,   556,   597,   464,     0,     0,     0,
       0,   267,     0,   269,   270,   265,   266,     0,   271,   272,
     126,   138,    69,    70,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     273,     0,     0,     0,     0,     0,   596,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   527,   528,     0,   529,   498,   302,   499,
     597,   464,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   487,     0,     0,     0,     0,     0,   224,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   596,     0,   224,   597,     0,     0,   397,     0,
       0,     0,     0,     0,     0,     0,     0,   505,     0,   504,
       0,     0,     0,     0,     0,   596,     0,     0,   550,     0,
       0,     0,     0,   263,   264,     0,   596,     0,     0,     0,
     281,   282,     0,   224,     0,   224,   596,     0,   597,     0,
       0,   224,   403,     0,     0,    69,    70,     0,     0,    62,
      66,    65,    64,    63,    68,    67,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   410,   409,   411,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   223,     0,   222,     0,
       0,   260,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    37,   256,     0,
       0,   472,   189,     0,   596,     0,   556,   597,   557,     0,
       0,   592,     0,   124,   124,     0,     0,     0,     0,   544,
     545,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    69,
      70,     0,     0,     0,     0,     0,     0,     0,     0,   511,
       0,     0,   512,     0,   513,     0,   514,     0,     0,     0,
       0,     0,     0,     0,     0,   409,   506,     0,   500,     0,
       0,     0,    69,    70,     0,     0,     0,     0,     0,     0,
     303,     0,   365,   365,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   224,   224,     0,   489,   488,     0,     0,     0,     0,
     224,   224,     0,     0,     0,     0,     0,     0,     0,   299,
       0,   224,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   367,     0,     0,     0,     0,     0,     0,     0,
     245,   398,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   375,   262,     0,     0,     0,     0,     0,   224,     0,
       0,     0,     0,     0,   285,   284,     0,   250,     0,   251,
       0,     0,     0,   224,     0,     0,     0,     0,   355,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    78,
       0,     0,     0,   477,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   460,   590,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    62,    63,     0,   408,
      62,    63,     0,     0,    62,     0,     0,     0,     0,     0,
     219,     0,     0,     0,     0,     0,     0,   225,     0,     0,
       0,   425,   424,   423,   422,   418,   419,   421,   420,   413,
     412,   414,   415,   416,   417,     0,     0,     0,   190,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   125,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   359,     0,
       0,     0,     0,     0,     0,   394,   395,   396,     0,     0,
       0,   477,    71,    72,     0,   530,     0,     0,     0,     0,
       0,   464,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   515,     0,   516,     0,   517,     0,   518,     0,     0,
       0,   408,   501,   508,     0,   414,   507,     0,     0,     0,
     531,     0,     0,     0,     0,     0,     0,     0,   363,     0,
       0,     0,   154,   155,     0,   157,   158,     0,   160,   161,
       0,   163,   164,     0,   183,     0,   203,     0,   211,     0,
       0,     0,     0,   175,   224,     0,     0,     0,     0,     0,
     491,   490,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   293,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   378,     0,     0,   246,     0,
       0,   242,     0,     0,     0,   393,   392,     0,     0,     0,
     408,     0,     0,     0,     0,     0,     0,     0,     0,   286,
     287,     0,     0,   252,   254,     0,   598,     0,     0,     0,
       0,     0,     0,    62,    63,     0,     0,    62,    63,     0,
       0,     0,     0,    93,    77,     0,   466,   465,   479,   427,
     428,   429,   430,   431,   432,   433,   434,   435,   448,   436,
       0,   438,   439,   440,   441,   442,   443,   444,     0,     0,
       0,   577,     0,   584,   573,   574,   575,     0,   589,   588,
       0,   484,     0,     0,     0,     0,   578,   579,   580,   486,
     586,   143,   148,   116,     0,     0,   569,     0,   571,     0,
     462,   469,   470,   565,     0,     0,     0,    62,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   110,     0,
       0,     0,     0,   471,     0,     0,     0,     0,     0,     0,
     594,     0,     0,    47,     0,     0,     0,    60,     0,    38,
      39,    40,    41,    42,   468,   467,     0,     0,   562,    27,
      25,     0,     0,     0,     0,    28,     0,     0,   257,   593,
      73,   127,    74,   139,     0,     0,     0,   546,   547,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   170,   466,   465,     0,     0,   534,     0,   533,
     532,     0,     0,   541,     0,     0,   510,     0,     0,     0,
       0,     0,     0,     0,   543,   502,     0,     0,     0,   468,
     467,     0,     0,     0,     0,     0,   408,   361,   366,   364,
       0,   374,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   408,   408,   408,     0,     0,     0,     0,     0,   253,
     255,     0,     0,     0,   214,   216,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   332,     0,   290,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   368,   377,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   247,     0,     0,     0,     0,     0,   249,
       0,   356,     0,     0,     0,     0,   404,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   595,     0,     0,
     474,     0,   473,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    87,     0,    91,     0,     0,    79,     0,
       0,     0,     0,    83,   106,   108,     0,     0,   554,     0,
     114,     0,     0,     0,     0,     0,     0,     0,   426,     0,
       0,     0,     0,     0,    33,   476,   475,   560,   558,    26,
       0,     0,   561,   559,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   168,   168,     0,     0,     0,     0,
       0,     0,     0,   166,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   173,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   519,   520,
     521,   522,     0,   509,   503,     0,     0,     0,     0,     0,
       0,     0,     0,   372,     0,     0,   156,     0,   159,     0,
     162,     0,   165,     0,     0,     0,     0,     0,     0,     0,
     248,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   338,     0,     0,   337,     0,   344,     0,   346,     0,
     340,     0,   342,     0,   300,   333,     0,     0,     0,   241,
       0,     0,     0,     0,     0,     0,     0,     0,   379,     0,
     244,   243,   399,     0,     0,    34,    35,     0,     0,     0,
       0,   551,     0,     0,     0,   276,     0,     0,     0,   224,
     357,   224,     0,     0,     0,     0,    88,     0,    92,     0,
       0,    80,     0,    84,     0,   259,   478,   258,   437,   445,
     446,   447,   585,     0,     0,   583,   482,   483,   485,     0,
       0,   461,   144,     0,   591,   149,   481,   570,   572,   463,
       0,     0,     0,    89,     0,     0,     0,    62,     0,     0,
       0,     0,    81,     0,     0,     0,   552,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   496,     0,
       0,    29,    30,     0,    31,     0,     0,   128,   135,     0,
       0,    75,    76,   171,     0,     0,     0,     0,     0,     0,
     174,     0,     0,   192,   193,     0,     0,     0,     0,   176,
     208,   194,   198,   199,   195,   196,   197,     0,     0,     0,
     478,   537,   536,   535,     0,     0,     0,     0,     0,     0,
       0,   209,   538,   200,     0,     0,   166,     0,     0,   371,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   261,     0,     0,     0,     0,   224,   224,     0,   314,
       0,   316,     0,   318,     0,     0,   339,   498,     0,     0,
     345,   347,   341,   343,     0,     0,   294,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   201,     0,     0,
       0,     0,   179,   180,     0,     0,     0,     0,   117,   121,
       0,     0,   355,   355,     0,   405,     0,     0,     0,    90,
       0,     0,     0,    82,     0,   480,     0,     0,     0,     0,
       0,     0,   100,     0,     0,    94,     0,     0,     0,     0,
     111,     0,     0,   112,     0,   555,   226,   227,   228,   229,
       0,     0,     0,    43,     0,     0,     0,     0,     0,    45,
     563,     0,     0,   129,   136,     0,     0,     0,     0,   169,
     177,   178,   182,     0,     0,   202,     0,   187,     0,     0,
     373,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     186,     0,   210,   362,   207,   172,   185,   206,   213,   184,
       0,   204,   212,     0,     0,     0,     0,     0,     0,   495,
       0,   494,     0,     0,     0,   305,     0,     0,   306,     0,
       0,   307,     0,     0,     0,     0,     0,     0,     0,     0,
     240,   239,     0,     0,     0,     0,     0,     0,     0,     0,
     230,     0,     0,   376,    36,     0,     0,   549,     0,   278,
     277,     0,     0,     0,     0,     0,     0,     0,   101,     0,
       0,    95,     0,     0,     0,   576,   582,   581,     0,   145,
     147,     0,   150,   151,   152,   102,   104,    96,    98,   107,
     109,     0,   115,     0,    85,    48,     0,     0,     0,   497,
       0,     0,     0,    32,     0,   143,   148,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   539,   540,     0,
       0,     0,     0,     0,     0,   188,     0,   369,   369,     0,
     122,   123,   224,     0,   217,   218,     0,     0,     0,     0,
       0,     0,   301,     0,   334,     0,     0,   224,     0,     0,
       0,     0,     0,     0,     0,     0,   221,   220,     0,     0,
       0,     0,   118,   119,     0,     0,   358,     0,   103,   105,
      97,    99,    86,     0,   544,   545,     0,     0,   553,     0,
      44,     0,     0,     0,    46,    61,     0,     0,     0,   133,
     131,   387,   389,   388,   390,     0,   391,   191,     0,     0,
       0,     0,     0,     0,   304,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   493,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   349,     0,     0,     0,
     295,     0,   231,     0,     0,     0,     0,     0,     0,     0,
     548,   279,     0,     0,   224,   406,     0,   146,     0,     0,
     153,   113,     0,     0,     0,     0,     0,   130,   137,   143,
     143,   167,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   370,   380,     0,     0,   381,     0,   215,     0,   320,
       0,     0,   322,     0,     0,   324,     0,     0,     0,   335,
       0,   291,     0,   224,     0,     0,     0,     0,     0,     0,
     181,   120,   275,   355,     0,   140,     0,     0,    52,     0,
      58,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   205,     0,   384,     0,   385,   386,   492,   308,     0,
       0,   315,   309,     0,     0,   317,   310,     0,     0,   319,
       0,     0,     0,   297,   234,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   134,
     132,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     326,     0,   328,     0,   330,   336,   348,   296,   292,     0,
       0,     0,     0,     0,     0,     0,     0,   141,   142,    49,
       0,    56,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   311,     0,     0,   312,     0,     0,   313,
       0,     0,   235,   236,   237,   238,     0,   232,   360,     0,
      50,     0,     0,   268,     0,   542,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   298,     0,
       0,     0,     0,     0,   274,     0,     0,     0,     0,     0,
       0,   321,     0,   323,     0,   325,     0,   233,    51,    53,
       0,    54,     0,   523,   524,   525,   526,     0,     0,     0,
       0,     0,     0,     0,    59,   382,   383,   327,   329,   331,
      55,    57
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,   108,  1111,   109,   110,   795,  1722,  1728,
    1099,  1339,  1939,  2179,  1100,  2115,  2220,  1101,  2181,  1102,
    1103,  1343,   406,   501,   210,   855,   111,   813,   513,  1865,
    2020,  2019,  1866,   514,  1933,  1305,  1522,  1306,  1525,   901,
     904,   907,   910,  1587,  1577,   777,   283,   477,   478,   114,
     115,   116,   117,   118,   119,   120,   121,   284,  1235,  2052,
    2139,   940,  1786,  1789,  1792,  2089,  2093,  2097,  2164,  2167,
    2170,  1231,  1232,   285,   989,   286,   125,  1412,  1190,   898,
     954,  1969,   126,   127,   128,   129,   287,   212,  1051,   615,
     321,  1557,   359,   360,   289,   579,   367,  1082,  1329,   511,
     506,  1052,   512,   388,   291
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1841
static const yytype_int16 yypact[] =
{
   11487,    87,   124, 11635, -1841, -1841,  5183,   130,   -70,   -72,
     -61,    52,   164,   172,   213,   231,   -45,   270,   291,   -43,
      88,  -147,  -147,   143,    62,    94,    29,   120,   129,    30,
     139,   175,   179,   187,   232,   259,   295,   337,   345,   370,
     409,   493,   600,   377,   131,   388,  6811,   405,   413,   567,
     -40,    24,   575,   691,   622,   -52,   465,   613,   -93,   473,
    -140,  -140,   502,   378,   503, -1841, -1841, -1841, -1841, -1841,
     484,   573,   653,   670,    11,    51,   682,   690,    35,   786,
     795,   801,  6359,   814,   557,   579,   609,    19,    45, -1841,
     628,   634, -1841, -1841,   864,   877,   647, -1841,  4888,   657,
    4203,     8,    36, -1841, -1841, -1841, 10920,   651, -1841, -1841,
   -1841, -1841, -1841, -1841, -1841, -1841, -1841, -1841, -1841, -1841,
   -1841, -1841, -1841,   151, -1841, -1841, -1841, -1841,    58, -1841,
    -139,   106, -1841,    38, -1841, -1841, -1841, -1841, -1841,  -147,
    -147,  -147,  -147,  -147,  -147,  -147,  -147,  -147,  -147,  -147,
    -147,  -147,  -147,  -147,  -147,  -147,  -147,  -147,  -147,  -147,
    -147,  -147,  -147,  -147,   664,   674,   702,  -147,  -147,  -147,
    -147,   705,  -147,  -147,  -147,  -147,  -147,  -147,   715, -1841,
    -147, -1841, -1841, -1841, -1841, -1841,  -147,  -147,   895,   716,
     725,   729,  -147,  -147,   730,   734, -1841, -1841, -1841, -1841,
     733, 10920, 10920, 10920,  4796,  5101,    25,    28,   344,   741,
     747,  1084, -1841,   756,   968,   190,  -104,   979, 10920,  6008,
    6008, -1841, 10920, -1841, -1841, -1841, -1841,  6008, -1841, -1841,
   -1841, -1841, -1841, -1841,  5782,    28, 10920, 10048, 10920, 10920,
     766, 10920, 10048, 10920, 10920,   787, 10920, 10048, 10920, 10920,
   10920, 10920, 10920, 10920,  6008, 10920, 10920,  7037,   792,   767,
   -1841, 10048,  6359,  6359,  6359,  6008,   435,   448,  -147,  -147,
    -147,  -147,     4,    14,    26,    34,  7037,   917,   711,  -147,
    7263, 10920,  5674, -1841, -1841,   827, -1841,  1356, -1841, -1841,
     350,  -163, 10920, 10048,   838,   841,  7489,  6359,  6359,  6359,
     842,   846,   879,   883,   898,  7715,  7941,  8167,   855,  2008,
    1076,  7037,    19,   892,   911,  -140,  -140,  -140, 10920, 10920,
     -89, -1841,   -67,  -140,   940,   944,   951,  2750,   -53,   275,
     983,  1003,  1022,  1031,  1032,  1036,  1043, 10920,  6359,  6359,
    7037,  1059,     7,   976, -1841,  1002,  1213,  1284, -1841,  1057,
    1072,  1077,  6359,  6359,  1008,  1083,  1087, -1841, 10920, -1841,
    1311,  1314, 10920, 10920, 10920,  -135, 10920,  1088, -1841,  1156,
   10920, 10920, 10920, -1841, -1841, 10920,  1092,  1326,  1327,  1100,
   -1841, -1841,  1329, -1841,  1331, -1841,   363, 10793,   394,  6008,
   10920, -1841, -1841,  7037,  7037, 10341, 10561,  1106,  1107,  5782,
   -1841, -1841, -1841, -1841, -1841, -1841,  7037,  1337,  1117, 10920,
   10920,  1343, 10920, 10920, 10920, 10920, 10920, 10920, 10920, 10920,
   10920, 10920, 10920, 10920, 10920, 10920, 10920, 10920, 10920, 10920,
   10920, 10920, 10920, 10920,  6008,  6008,  6008,  6008,  6008,  6008,
    6008,  6008,  6008,  6008,  7037,  6008,  6008, 10920,  6008,  6008,
    6008,  6008,  6008, 10920,  5782, 10920,  6008,  6008,  6008,  6008,
    6008,    28,  5782,    28,  1122,  1122,  1122,   119, 13630,   192,
   13239,   188,  1118,  1344,  -147,  1116, -1841,  1119, 11827, 10920,
   10048, -1841, 10920, 10920, 10920, 10920, 10920, 10920, 10920, 10920,
   10920, 10920, 10920, 10920, 10920, 10920, 10920, -1841, -1841, 10920,
   10920, -1841, -1841,  1215,   472,   134, -1841,   543, -1841,   252,
   11786, -1841,   311,   495,   604,  1123,  1124, 13651, 10048,  3376,
   -1841,   516, 13672, 13693, 10920, 13714,   595, 13735, 13756, 10920,
   13777,   619, 13798, 13819, 13840, 13861, 13882, 13903,  1130, 13924,
   13945,  1345, 10920, 10920,   675,  1353,  1354,  1359,  1138, 10920,
   10920,  1363,   392,  8393,  8619, 10920, 10920,  6008, 10920, -1841,
    1312, 10920, -1841,  1313, -1841,  1315, -1841,  1316,  7037,    46,
      47,    48,    49, 10048, 10048,  1122, -1841, 13966, -1841,   679,
   10920,  8845, 10920, 10920,   581, 13987,   706, 10920, 10920, 10920,
   -1841,  1364,  1366,  1366, 10920, 10268, 10268, 10268, 10268, 10920,
    1370, 10920,  1373, 10920,  1374, 10048, 10048, 10878,  1153,  1377,
    1150, -1841, -1841,   -76, -1841, -1841, 11812, 11838,  -140,  -140,
     344,   344,   -49, 10920, 10920, 10920,  2750,  2750, 10920,  3066,
     -41, -1841, 10920, 10920, 10920, 10920, 10920, 10920, 10920, 10920,
   10920, 14008,  1378,  1380,  1381, 10920,  1383, 10920, 10920,  3259,
   -1841, -1841, 10048, 10048, 10048,  1384,  1385, 10920, 10920, 10920,
   14029, -1841, -1841, 14050, 14071, 14092,  1219, 11864, -1841,  1174,
    3397, 14113, 14134, 13262, -1841, -1841, 10048, -1841,  3722, -1841,
    4415, 10920, 10920, -1841, 10920, 10920,  1180, 14155, 11769,  1185,
     720,   216, 14176,   307, 13285, 10920, 10048,  1409,  1431, -1841,
   10920, 14197, 13308,   -78, 13216, 13216, 13216, 13216, 13216, 13216,
   13216, 13216, 13216, 13216, 13216, 11890, 13216, 13216, 13216, 13216,
   13216, 13216, 13216, 11916, 11942, 11968,   197,   649,   197,  1210,
    1211,  1220,   740,   740,  1221,   740,  1223,  1225,  1226, 11994,
     740,   740,   740,   315,   740, 14890, -1841,  1259,  1227,  1228,
    1234,   697,   707,  1236,  1237,  1251,  1438,  1439,  7037,   299,
    1440,  1442,  7037,   176,  5782, 10920,  1481,  1484,    32,   740,
   -1841,   283,    41,    44,   318,  1262,   -34, -1841,  4627,   774,
    3483,  1183,  1231,   606,   606,   272,   272,   272,   272,   623,
     623,  1122,  1122,  1122,  1122,    13, 14218, 13331, -1841, 10920,
   10920,  1486,    15, 10048, 10920, 10920,  1487, 10048, 10920,  1488,
    6008,  1489, -1841,    28,  1493,  6008, 10920,  5782,  1494, 10048,
   10048,  1332,  1495,  1497, 14239,  1498,  1335,  1500,  1501, 14260,
    1502,  1340,  1505,  1507,  1508,  1526,  1527,  1529, -1841,  1530,
    1531, 10920, 14281,  4821,  1298, -1841, -1841, -1841,  1533, 14302,
   13354,  -163, -1841, -1841, 10048, -1841, 10048,  3376,  1317, 10048,
    1310,   180, 12020, 12046,   740, 12072,  1318,  5057,  1319,  1320,
    1321, -1841, 10048, -1841, 10048, -1841, 10048, -1841, 10048,   740,
     777,  1536, -1841,  3756, 10048,  1122, -1841, 14323, 13377, 10048,
   -1841,  1537,  1322, 14344, 14365, 14386, 10920,  7037,  1542,  1541,
   14407,  1323, 14890,  1324,  1330, 14890,  1328,  1334, 14890,  1347,
    1355, 14890,  1348, 14428, -1841, 14449, -1841, 14470, -1841,   780,
     789, 10048,  1357, -1841, -1841,  4500,  9878,  -140, 10920, 10920,
   -1841, -1841,  1349,  1350,  2750, 12098, 12124, 12150, 11760,  1427,
     769,  -140, 11069, 14491,  5126, 14512, 14533, 14554, 14575, 14596,
   14617, 14638,  1552, 10920,  1580, -1841, 10920, 14659, -1841, 13400,
   13423, -1841,   790,   793,   797, -1841, -1841, 13446, 13469, 12176,
   -1841,  1582,  1583,  1584,  1368, 10920, 11127, 10920, 10920, -1841,
   -1841,    60,   798, -1841, -1841, 11184, -1841,  1587, 10633,  1352,
    1361,  7037,  1594,  1557,  1558,  7037,   299,  1559,  1564,  7037,
     299,  5396,   802, -1841, -1841, 13492,   -36,   294, -1841, -1841,
   -1841, -1841, -1841, -1841, -1841, -1841, -1841, -1841, -1841, -1841,
   10920, -1841, -1841, -1841, -1841, -1841, -1841, -1841, 10920, 10920,
   10920, -1841, 10048, -1841, -1841, -1841, -1841,  6008, -1841, -1841,
   10920, -1841,  7037,  6008,  6008,  6008, -1841, -1841, -1841, -1841,
   -1841, -1841, -1841, -1841, 10920,  6008, -1841,  6008, -1841, 10920,
   -1841, -1841, -1841, -1841,  -147,  -147,  1603, -1841, 10920,  1608,
    -147,  -147,  1609,    43, 10920,  1610,  1611,  1309, -1841,  1612,
    1391,    19,  1615, -1841, 10048, 10048, 10048, 10048, 10920,  1395,
   -1841,   740, 10920, -1841,  1396,  1397,  1393, -1841,  1622, -1841,
   -1841, -1841, -1841, -1841,   -24,     1, 14680, 13515, -1841, -1841,
    1415,  6008,   580, 14701, 13538, -1841,   667, 12202, -1841, -1841,
   -1841,    78, -1841, -1841, 13216,   740,  -140,  3376, -1841,   946,
    7037,  7037,  1623,  7037,   953,  7037,  7037,  1624,  7037,  1540,
    7037,  7037,  7037,  7037,  7037,  7037,  7037,  7037,  1525,  1626,
    1629, 10048, -1841,  -163,   103,   811,   815, -1841,   816, -1841,
   -1841, 10920, 10920, -1841, 10920, 10920, -1841, 10920, 10920, 10920,
     820,   823,   824,   829, -1841, -1841,  7037, 10920,   839,  -163,
    -163,   844,  7037, 10048,  1630,  1631,  1632,  2102, -1841, -1841,
    1634, -1841,  1635,   369, 10920,   369, 10920,   369, 10920,   369,
   10920,  1638,  1639,  1640,  1641,  1642,   852,  1646, 11241, -1841,
   -1841,   154, 12228, 12254, -1841, -1841,  6069,  -149,  -140,  -140,
    -140,  1565,  1647, 10853,  1419,  1648,  1428,    31,    40,    53,
      57,   -15, -1841,   156, -1841,   769,  1650,  1652,  1654,  1656,
    1657,  1658,  1659,  1665,  1666,  7037, 14890, -1841,  1661,  1425,
    1672,  1673,  1677,  1595,  1679,  1681,  1682, 10920,  7037,  7037,
    7037,  1685, 12280, -1841,  3790,   903,  1686,  1690,  1462, -1841,
    1463, -1841,  1710,  1464,  7037,  1465, -1841,  -147,  -147,  1693,
   10920,  1695,  -147,  -147,  1702, 10920,  1704, -1841,   740,  1708,
   -1841,  1713, -1841,  1712, 13216, 13216, 13216, 13216,   754,  1491,
   11295,  1492,   740,   740,  1496,   761,   775, 14722,  1499,   740,
   13216,  1142,  6008, -1841,  1759, -1841,  1142,  6008, -1841,   356,
    1490,  1715,  1778, -1841, -1841, -1841,    19, 10920, -1841,   853,
   -1841,   862,   865,   866,   869, 14743, 10920,   369, 14890,  1503,
   10920, 10920,  7037,  1485, -1841, -1841, -1841, -1841,  1516, -1841,
    1719,    16, -1841, -1841,  1720, 10920,  9523,  1504,  1519,  1722,
    1725,    10,  1518,  1520,  1636,  1636,  7037,  1747,  1521,  1524,
    1750,  1754,  7037,  1590,  1528,  1757,  1758,  1760,  1761,  1762,
    1763,  1766,  1767, -1841,  1769,  7037,   870,  1773,   740,  1550,
    1549, 12306, 12332, 12358, 12384, 12410, 12436, 12462, -1841, -1841,
   -1841, -1841,  1776, 14890, -1841,   740,  1777,   874,  7037,  7037,
    7037,  1781,  1780, -1841,  7037,  7037, 14890,  7037, 14890,  7037,
   14890,  7037, 14890,  7037,  7037,  7037,  1554,  1555,  1784,   326,
   -1841, 10920, 10920, 10920,  1572,  1574,  -152,  -118,   -99,  1575,
    1563, -1841,  1894,  7037, -1841, 10920, -1841,  1792, -1841,  1793,
   -1841,  1804, -1841,  1805, -1841, -1841,  2750,     6,  6585, -1841,
    1578,  1579,  1585,  1586,  1591,  1593,  9071,  1808, -1841, 10048,
   -1841, -1841, -1841,  1596, 10920, -1841, -1841, 13561,  1822,  1823,
    1664, -1841, 10920, 10920, 10920, -1841,  1826,   524,  5782, -1841,
   -1841, -1841,  1600,  1828,  1142,  6008, -1841,  1945, -1841,  1142,
    6008, -1841,  2338, -1841,   369, -1841,    95, -1841, -1841, -1841,
   -1841, -1841, -1841,  6008, 10920, -1841, -1841, -1841, -1841,  6008,
    1833, -1841, -1841,    20, -1841, -1841, -1841, -1841, -1841, -1841,
    1834,   197,   197, -1841,  1835,   197,   197,  5782, 10920,  1836,
    1839,    32, -1841,  1840, 13584,    19, -1841,  1841,  1843,  1844,
    1845,  1536, 14764,  7037, 10920, 12488, 12514,   901, -1841, 10920,
    1848, -1841, -1841,  6008, -1841, 12540,  5907, 14890, -1841,  1832,
    1838, -1841, -1841, -1841, 10920, 10920,  -140,  1847,  1849,  1850,
   -1841, 10920, 10920, -1841, -1841,  1852,  1771,  1854, 10920, -1841,
   -1841, -1841, -1841, -1841, -1841, -1841, -1841,  1856,  1857,  1620,
    -163, -1841, -1841, -1841, 10920, 10920, 10920, 10920, 10920, 10920,
   10920, -1841, -1841, -1841,  1628,  1860,  1590,  1861, 10920, -1841,
    1879,  1882,  1883,  1885,  1886,  1887,  1159,  1888, 10048, 10048,
   10920, -1841, 10268,  6295, 14785,  3815,   344,   344,  -140,  1889,
    -140,  1890,  -140,  1891,  7037, 10920, -1841,   470,  1668, 14806,
   -1841, -1841, -1841, -1841,  6521,   191, -1841,  1892,  1893,  7037,
    -140,  -140,  -140,  -140,  -140,  5439,  1896, -1841,   931, 10920,
    2497,  1899, -1841, -1841,  7037,  4077,   941, 14827, -1841, -1841,
    9596,  1675, 11769, 11769,  7037, -1841,  1900,   197,   197, -1841,
    1903,   197,   197, -1841,  7037, -1841,  1683, 13216,   740,  6133,
    9822,  5782, -1841,  1904,  1906, -1841,  1907,  1908,  1909,  2658,
   -1841,  1925,  1910, -1841,  1703, -1841, -1841, -1841, -1841, -1841,
    1632,  1927,   698, 14890, 10920, 10920,  7037,  1701,   936, 14890,
   -1841,  1931, 10920, -1841, -1841,  1705,  1707,  6747,  6973,   340,
   -1841, -1841, -1841,  7199,  7425, -1841,  1709, -1841,  7651,  1939,
   -1841,  7037, 13216, 13216, 12566, 12592, 12618, 12644, 12670, 10920,
   -1841,  1940, -1841, 14890, -1841, -1841, -1841, -1841, -1841, -1841,
    1711, -1841, -1841,   937,   942, 11326,  2795,  1941,  1714, -1841,
   10920, -1841,  1717,  1723,   211, -1841,  1716,   234, -1841,  1726,
     246, -1841,  1727,  1724, 13607,  1943,  7037,  1955,  1729, 10920,
   -1841, -1841,   948,   303,   309,   316,   320,   323,  9297,   349,
   -1841,  1958,  7877, -1841, -1841,  1800, 10920, -1841, 10920, -1841,
   -1841, 10048,  2837,  1975,  5782,  1748,  1765,  1768, -1841,  1976,
    1995, -1841,  1996,  1999,  2001, -1841, -1841, -1841,  5674, -1841,
   -1841,  6008, 14890, -1841, -1841, -1841, -1841, -1841, -1841, -1841,
   -1841,    19, -1841,  1846, -1841, -1841, 10920, 12696, 12722, -1841,
    7037, 10920,  2002, -1841, 12748, -1841, -1841,  7037,  7037,  2004,
    2010,  2015,  2039, 10920,  2040,  2041,   949, -1841, -1841, 10920,
   10920, 10920, 10920, 10920,  8103, -1841,  7037,   671,   737, 10048,
   -1841, -1841,   344,  4501, -1841, -1841,  2750,   769,  2750,   769,
    2750,   769, -1841,  2042, -1841,   962,  7037, -1841,  8329,  2043,
   10048,  -140,  -140,  -140,  -140,  -140, -1841, -1841, 10920,  8555,
    8781,   963, -1841, -1841,  1786,  1816, -1841,  2051, -1841, -1841,
   -1841, -1841, -1841,   971,  3218,  2052,   978,  2054, -1841,  1824,
   14890, 10920, 10920,   981, 14890, -1841, 10920,   982,   985, -1841,
   -1841, -1841, -1841, -1841, -1841,  9007, -1841, -1841,  1831, 12774,
   12800, 12826, 12852, 12878, -1841,   989,  1842,  -140,  7037,  2060,
    1851,  -140,  2061,   992,  1837, 10920, -1841,  9233,   351,   639,
    9470,   371,   693,  9552,   396,   712, -1841,  7037,  2064,  1952,
   11298,  1853, -1841,   993,   407,   410,   441,   477,   480,  3070,
   -1841, -1841,  2068,  2071, -1841, -1841, 10920, -1841,  5782,    28,
   -1841, -1841, 10920, 14848, 12904,    54, 12930, -1841, -1841, -1841,
   -1841, -1841, 10920, 10920, 10920, 10920, 10920, 10920,  2072,  -140,
      83, -1841, -1841,  -140,    98, -1841,  2073, -1841,  9696,  2077,
   10920,  2078,  2080, 10920,  2083,  2084, 10920,  2085,  1858, -1841,
   10920, -1841,   769, -1841,  2086, 10048, 10048, 10048, 10048,  9297,
   -1841, -1841, -1841, 11769,  3328, -1841,  1867,   996, -1841, 10920,
   -1841,  7037, 10920,  1001,  1010, 12956, 12982, 13008, 13034, 13060,
   13086, -1841,   517, -1841,   528, -1841, -1841, -1841, -1841,  1862,
    9724, -1841, -1841,  1863,  9984, -1841, -1841,  1864, 10172, -1841,
    2089,  3199,   751, 11355, -1841,  1011,  1015,  1019,  1033,   530,
    1034,  1865,  5782,  1871,  2110,  1884, 14869,  1042, 10214, -1841,
   -1841, 10920, 10920, 10920, 10920, 10920, 10920,  -140,  -140,   769,
    2111,   769,  2113,   769,  2115, -1841, -1841, -1841, -1841,   769,
    2117,  2119,  2120,  2121, 10048,  2122,  2123, -1841, -1841, -1841,
    6008, -1841,  1897,  2124, 10293, 13216, 13112, 13138, 13164, 13190,
     549,   556,   812, -1841,  1901,   825, -1841,  1902,  1126, -1841,
    1905,  1458, -1841, -1841, -1841, -1841,  1049, -1841, -1841,  1050,
   -1841,  1911,  7037, -1841,  2127, -1841, 10920, 10920, 10920, 10920,
   10920, 10920,  2128,   769,  2131,   769,  2132,   769, -1841,  2134,
    6008,  2136,  6008,  1054, -1841, 10392, 10464, 10506, 10586, 10684,
   10751, -1841,  1522, -1841,  1649, -1841,  1669, -1841, -1841, -1841,
    1086, -1841,  2137, -1841, -1841, -1841, -1841,  2138,  2140,  2142,
    2143,  2144,  6008,  2146, -1841, -1841, -1841, -1841, -1841, -1841,
   -1841, -1841
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1841, -1841, -1841, -1841,   817, -1841, -1841, -1841, -1841,   155,
   -1841, -1841, -1841, -1841, -1841, -1841, -1841, -1841, -1841, -1841,
   -1841, -1841,  -441,   -87,  4611,  3615, -1841,  1660, -1841, -1841,
   -1841, -1841, -1841, -1841, -1841, -1840, -1841,   306, -1841, -1841,
   -1841, -1841, -1841,   559,   808,  2173,    -2,  -616,  -136, -1841,
   -1841, -1841, -1841, -1841, -1841, -1841, -1841,  2174, -1841, -1841,
   -1841, -1841, -1841, -1841, -1841, -1841, -1841, -1841, -1841, -1841,
   -1841, -1195, -1217,  2175, -1675,  2177, -1841, -1841, -1841,  1588,
   -1841,   296, -1841, -1841, -1841, -1841,  2045, -1841, -1841,    42,
   -1841, -1653,  2998,  -190,  2646,  3542,  -310,   641, -1841,   196,
      12, -1841,  -424,    -3,   281
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -564
static const yytype_int16 yytable[] =
{
     130,   113,   610,   215,   932,   933,  1802,  1825,  1826,   559,
     726,   646,   728,   382,  1455,   342,  1573,  1093,   214,   562,
     218,  1109,  1562,   365,  1700,  1947,   758,   743,   762,   471,
     765,   564,   376,   240,   245,   308,  1080,  1446,   309,   566,
    1457,   384,   408,   290,   407,   240,  1448,  1319,   245,   369,
     295,   871,   873,   875,   877,   347,   295,   348,   221,  1450,
    2070,   404,   405,  1452,   392,   618,   619,  1266,   618,   619,
     296,   345,   545,   546,   547,   312,  1089,   316,   317,   290,
     232,  1638,   233,  1639,   345,  1356,  1435,   318,   395,  2083,
     396,   313,   314,     4,   319,   345,   666,   397,  1876,   618,
     619,   209,   320,   322,  2085,   328,  1222,   591,   592,   593,
     377,   297,   381,   399,   298,  1640,   299,  1641,   618,   619,
     404,   405,   352,  1223,     5,   353,   756,  1222,   618,   619,
    -557,  1224,  1225,  1226,  1642,   349,  1643,  1227,  1228,  1229,
    1230,   618,   619,   217,  1223,   620,   404,   405,   642,   643,
     618,   619,  1224,  1225,  1226,   219,  -562,   927,  1227,  1228,
    1229,  1230,   655,   656,   618,   619,   220,   621,   618,   619,
     223,  1094,  1095,  1096,  1097,   560,   618,   619,   224,  2073,
    2074,   631,   227,  1067,   934,   563,   230,  1447,   404,   405,
     343,   629,   941,   472,   473,   764,  1449,   565,  -560,   760,
     404,   405,   213,  1701,   345,   567,   476,  1943,   649,  1451,
    -561,  1320,  1321,  1453,   107,   262,   507,   507,   263,   225,
    1454,   264,   107,   993,   507,   404,   405,   618,   619,  1110,
    1110,   107,   345,  1965,   290,  -559,   647,   226,   561,   290,
    1455,  1656,   383,   209,   290,   344,   515,   678,  1098,   680,
     995,   507,   999,   366,   290,   688,   241,   246,   290,   290,
     290,   290,   507,   242,   247,   409,  1081,   410,   241,   411,
     385,   246,   370,   290,   209,  1085,   228,   290,  1086,   290,
     872,   874,   876,   878,   131,   393,   222,   216,  2071,   238,
     290,  1267,   394,   290,   290,   290,   290,   229,   504,   134,
     618,   619,   290,   290,   290,  1357,  1067,  1358,   290,   345,
     400,   401,   402,   403,   997,   618,   619,   231,  1068,   404,
     405,   239,  1074,   400,   401,   402,   757,   404,   405,  -563,
     404,   405,  1631,  1632,  1387,   290,   290,   290,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   243,   475,   290,
     290,   174,   175,   176,   177,   346,   244,   613,   614,   179,
     180,   181,   802,  1537,   182,   622,   248,   803,   368,   630,
     236,   618,   619,   618,   619,   187,  1067,   237,   390,   378,
     400,   401,   402,   403,   766,   391,   507,  1431,  2111,  1456,
     290,   290,   400,   401,   402,   403,   400,   401,   402,   761,
     404,   405,   249,   290,   404,   405,   250,  1073,   618,   619,
    1160,   697,   404,   405,   251,   505,   509,   499,  2117,   500,
     400,   401,   402,   994,  1799,   852,   397,   853,   618,   619,
     810,   507,   507,   507,   507,   507,   507,   507,   507,   507,
     507,   290,   507,   507,  1896,   507,   507,   507,   507,   507,
     538,   618,   619,   507,   507,   507,   507,   507,   345,   252,
     345,   548,   324,   618,   619,   325,   746,  1898,   326,    59,
      60,    61,    62,   257,   754,   925,   926,   290,   580,  1900,
     806,   190,   191,   192,    73,   807,   253,    76,   474,   491,
     492,   493,   494,   495,   199,   942,   200,   107,   496,   258,
     508,   508,   632,   400,   401,   402,   403,   329,   508,   633,
     236,   400,   401,   402,   998,   290,   516,  1084,   404,   405,
     618,   619,   254,   404,   405,  1291,   618,   619,  -558,  2203,
    1679,  1680,   976,   618,   619,   508,  1910,   618,   619,   809,
     618,   619,  1911,  1049,   810,   249,   508,   985,   810,  1912,
     290,   290,  1087,  1913,   507,  1280,  1914,   618,   619,  1285,
     400,   401,   402,   403,   255,   290,   618,   619,   618,   619,
     290,   290,   256,   400,   401,   402,   403,   582,   290,   583,
     404,   405,  1915,   259,  2040,   686,   397,   330,   618,   619,
     681,   331,   682,   368,   551,   316,   317,   332,   333,   209,
     334,   335,   290,   290,  2043,   318,   260,   903,   906,   909,
     912,   261,   327,   618,   619,   265,  1008,   336,   476,   476,
     852,   684,   853,   685,   618,   619,   854,   618,   619,  2046,
     397,   727,   292,   729,   730,   731,   732,   733,   734,   735,
    2055,   737,   738,  2056,   740,   741,   742,   293,   744,   290,
     290,   290,   748,   749,   750,   751,   752,   294,   618,   619,
     930,   931,   549,   338,   550,   339,   551,   300,   614,   208,
     508,   209,  1069,   290,  2057,   553,  1075,   554,   482,   483,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   581,
     494,   495,   310,   290,   618,   619,   496,   618,   619,   799,
     311,   800,  1979,   801,  1982,  1795,  1985,   315,   209,   305,
    2058,   337,   306,  2059,   307,   508,   508,   508,   508,   508,
     508,   508,   508,   508,   508,   811,   508,   508,   812,   508,
     508,   508,   508,   508,   618,   619,   323,   508,   508,   508,
     508,   508,   753,   340,   755,   618,   619,   618,   619,   820,
    2127,   821,  1415,   864,  1417,   290,  1419,   341,  1421,   290,
    1222,  2128,  1455,  2144,  1008,  1455,   618,   619,  1455,   350,
     804,  1328,   805,   618,   619,   301,  1076,  1223,   302,   397,
     351,   303,  2190,   304,   362,  1224,  1225,  1226,  1208,  2191,
     354,  1227,  1228,  1229,  1230,   569,  1966,  1967,   570,   355,
     290,   571,  1968,   572,   290,   356,   363,   507,  1351,   852,
     345,   853,   507,   820,  1222,   889,   290,   290,   361,   487,
     488,   489,   490,   491,   492,   493,   494,   495,   820,  1125,
     826,  1223,   496,  1222,   814,   861,   364,   812,   508,  1224,
    1225,  1226,   493,   494,   495,  1227,  1228,  1229,  1230,   496,
    1223,   290,   820,   290,   831,   371,   290,  2102,  1224,  1225,
    1226,   372,  1970,  1971,  1227,  1228,  1229,  1230,  1968,   290,
     373,   290,  1222,   290,  2041,   290,   375,   852,  1538,   853,
     389,   290,  1032,   374,   379,  1455,   290,  1531,  1532,  1223,
    1222,   437,  1535,  1536,   290,  1354,  1553,  1224,  1225,  1226,
     820,   438,   455,  1227,  1228,  1229,  1230,  1223,   820,  1281,
     844,  1484,   820,  1286,   882,  1224,  1225,  1226,   290,  1290,
    1292,  1227,  1228,  1229,  1230,   852,  1855,   853,  2044,   439,
    1057,  1856,   444,  1222,  2162,   852,  2165,   853,  2168,   820,
    1059,   892,   451,   456,  2171,  1455,  1222,  2047,  1455,  1818,
    1223,  1455,   457,   991,  1455,   992,   458,   461,  1224,  1225,
    1226,   462,   463,  1223,  1227,  1228,  1229,  1230,   852,  1211,
     853,  1224,  1225,  1226,   498,   479,  1217,  1227,  1228,  1229,
    1230,   480,   852,  1233,   853,   502,  2137,   820,   290,   852,
     497,   853,   290,   524,  1520,  1455,   290,  1455,  2212,  1455,
    2214,   543,  2216,   852,   507,   853,  1119,   820,  1523,  1091,
     820,  1123,  1175,   820,   529,  1204,  1543,  1345,  1346,   542,
    1782,  1783,   820,   820,  1205,  1252,   820,   568,  1253,   290,
     820,   820,  1254,  1268,   507,   820,  1362,  1288,  1363,   290,
     507,   507,   507,  1368,   820,  1369,  1388,  2192,   820,   820,
    1389,  1390,   507,   820,   507,  1398,   820,   820,  1399,  1400,
    2194,   391,   820,  1694,  1401,   587,  1290,  1292,   588,   594,
    1687,  1688,   820,   595,  1404,  1691,  1692,   820,   345,  1405,
     608,   290,   290,   290,   290,   820,  1545,  1428,  1546,   605,
     481,   508,  1345,  1346,  1121,   820,   508,  1547,   820,   820,
    1548,  1549,   820,   820,  1550,  1599,   596,   820,   507,  1614,
     597,   482,   483,   484,   485,   486,   487,   488,   489,   490,
     491,   492,   493,   494,   495,   598,   611,   290,   290,   496,
     290,  1485,   290,   290,  1726,   290,  1727,   290,   290,   290,
     290,   290,   290,   290,   290,   612,   504,   134,   290,   482,
     483,   484,   485,   486,   487,   488,   489,   490,   491,   492,
     493,   494,   495,  1770,   820,  1771,  1811,   496,  1361,  1861,
     820,  1862,  1887,   290,   623,   820,  1819,  1888,   624,   290,
     290,  1726,  1726,  1909,  1958,   625,   161,   162,   163,   164,
     165,   166,   167,   168,   169,  1987,   820,  1988,  2002,   174,
     175,   176,   177,  1293,  2006,   648,  2007,   179,   180,   181,
     634,   810,   182,  2010,  1726,  1520,  2015,  2017,  1523,   650,
    2018,   798,  1726,   187,  2028,   820,   820,  2036,  2054,  1861,
     635,  2114,  1539,  1299,  1520,  1715,  2119,   657,   397,  1302,
    1303,  1304,   290,  1520,   820,  2120,  2140,  1222,   820,   636,
    2141,  1308,   820,  1309,  2142,   290,   290,   290,   637,   638,
    1436,  1437,  1438,   639,  1223,  1053,   820,   820,  2143,  2145,
     640,   290,  1224,  1225,  1226,  1726,  1974,  2152,  1227,  1228,
    1229,  1230,   820,  2200,  2199,  2201,   645,  1726,   508,  2222,
     651,   652,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,   495,   653,  1350,   507,   507,
     496,   654,   658,   507,   507,  1325,   659,   661,   508,  2232,
     662,  2233,   668,   345,   508,   508,   508,   669,   209,   190,
     191,   192,   674,   675,   676,   677,   508,   679,   508,   290,
     695,   696,   199,   699,   200,   107,   700,   703,   496,   767,
     208,   768,   841,  1682,   770,  1683,   816,   817,   838,   845,
     846,  2196,   368,   290,   580,   847,   848,   851,  1568,   290,
     852,   896,   853,   897,   866,   868,   914,   869,   870,   916,
     918,   922,   290,   923,   924,   953,   955,   974,   956,   958,
     965,   966,   508,   484,   485,   486,   487,   488,   489,   490,
     491,   492,   493,   494,   495,   290,   290,   290,   977,   496,
     986,   290,   290,   990,   290,  1003,   290,  1936,   290,  1695,
     290,   290,   290,   482,   483,   484,   485,   486,   487,   488,
     489,   490,   491,   492,   493,   494,   495,  1004,  1035,  1036,
     290,   496,   485,   486,   487,   488,   489,   490,   491,   492,
     493,   494,   495,  1037,  1040,   290,  1042,   496,  1043,  1044,
    1054,  1055,  1056,   290,  1061,  1062,   290,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     495,  1063,  1064,  1065,  1070,   496,  1071,  1078,  1079,  1088,
    1108,   507,   507,  1115,  1118,  1120,   507,   507,  1655,  1122,
    1681,  1126,  1130,  1129,  1131,  1133,  1134,  1135,  1136,  1138,
     507,  1139,  1140,  1695,  1141,  1142,   507,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     495,  1383,  1151,  1143,  1144,   496,  1145,  1146,  1147,  1152,
    1159,  1937,   345,  1176,  1182,  1157,  1189,  1191,  1221,  1708,
     290,  1193,  1165,  1167,  1168,  1169,  1183,  1194,  1195,  1245,
     507,  1196,  1197,   290,   482,   483,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   581,   494,   495,  1734,  1222,
    1198,  1200,   496,  1199,  1214,  1215,  1247,  1273,  1207,  1258,
    1259,  1260,   508,   508,  1270,  1274,  1223,   508,   508,  1261,
    1276,  1277,  1278,  1282,  1224,  1225,  1226,   368,  1283,  1313,
    1227,  1228,  1229,  1230,  1315,  1318,  1323,  1324,  1739,  1326,
    1327,  1330,  1336,  1340,  1341,   290,   290,  1342,  1344,  1349,
    1366,  1372,  1374,  1384,   476,   476,  1385,  1408,  1409,  1410,
    1413,   290,  1414,  1222,  1777,  1423,  1424,  1425,  1426,  1427,
    1429,  1440,  1439,  1443,  1444,  1445,   290,  1458,  1459,  1469,
    1223,  1460,   290,  1461,  1462,  1463,  1464,  1468,  1224,  1225,
    1226,   290,  1465,  1466,  1227,  1228,  1229,  1230,  1470,  1471,
    1784,   290,  1787,  1472,  1790,  1473,  1474,  1475,  1476,  1481,
    1486,   290,  1823,  2198,  1487,  1488,   290,  1489,  1491,  1496,
    1493,  1498,  1803,  1804,  1805,  1806,  1807,  1809,  1501,  1696,
    1503,  1840,  1843,  1844,  1505,  1698,  1490,  1506,  1507,  1559,
    1516,  1540,  1541,   290,  1513,  1561,  1564,  1527,  1571,  1519,
    1554,  1572,  1569,   482,   483,   484,   485,   486,   487,   488,
     489,   490,   491,   492,   493,   494,   495,  1560,   290,  1570,
    1576,   496,  1574,  1580,  1575,  1581,  1583,  2229,  1582,  1731,
    1584,  1586,  1588,  1589,  1590,  1533,  1591,  1592,  1593,  1594,
    1222,  1990,  1595,  1596,  1597,   508,   508,  1600,  1602,  1603,
     508,   508,  1611,  1613,  1542,  1618,  1619,  1223,  1628,  1629,
    1222,  1630,  1645,   290,   508,  1224,  1225,  1226,  1650,  1651,
     508,  1227,  1228,  1229,  1230,   290,  1636,  1223,  1637,  1644,
    1652,  1653,  1659,  1660,  1667,  1224,  1225,  1226,   290,  1661,
    1662,  1227,  1228,  1229,  1230,  1663,   368,  1664,  1672,  1673,
    1669,  1674,  1678,  1684,  1685,   290,  1924,  1699,   507,  1735,
    1702,  1705,  1710,  1711,   508,  1736,  1713,  1716,   345,  1717,
    1718,  1719,  1730,  1740,  1751,  1741,  1742,   290,  1745,  1746,
    1747,  1749,  1759,  1750,   290,   290,  1760,  1762,  2063,   482,
     483,   484,   485,   486,   487,   488,   489,   490,   491,   492,
     493,   494,   495,   290,  2230,  1764,   290,   496,  1765,  1766,
     476,  1767,  1768,  1769,  1772,  1785,  1788,  1791,  1800,  1801,
    1646,  1796,  1810,   290,  2231,  1814,  1828,   290,  1824,  1831,
    1845,  1835,  1846,  1847,  1848,  1849,  1852,  2103,   482,   483,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
     494,   495,  1851,  1854,  1853,  1860,   496,  1863,  1978,  1867,
    1981,  1868,  1984,  1873,  1875,  1886,  1885,  1891,  1892,  1904,
    1897,  1689,  1894,  1994,  1995,  1996,  1997,  1998,  1895,  1902,
    1899,  1901,  1906,  1907,  1916,   290,  1918,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     495,  1923,  1928,  1925,   290,   496,   482,   483,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,   495,
    1926,  1929,  1930,  1927,   496,  1931,   345,  1932,  1945,  2030,
    1951,   132,   386,  2034,  2003,  1938,  1952,   135,   136,   137,
    2065,  1953,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,  1954,  1956,  1957,  1986,  1992,
    2004,   211,   290,   290,   290,   290,   290,  2005,  2012,  2009,
    2011,   170,   171,   172,   173,  2022,  2032,  2035,   290,   178,
    2049,  2082,  2037,  2050,  2061,  2084,  2029,  2062,  2081,  2086,
     183,   184,   185,  2088,  2091,  2033,  2092,  2053,   186,  2095,
    2096,  2099,  2104,  2100,  2113,  2135,  2129,  2131,  2133,  2148,
    2146,  2109,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,   495,  2149,  2163,  2150,  2166,
     496,  2169,   508,  2172,  2147,  2173,  2174,  2175,  2177,  2178,
    2183,  2182,   368,  2204,  2211,  2193,  2195,  2213,  2215,  2197,
    2217,   290,  2219,  2234,  2235,  2202,  2236,   507,  2237,  2238,
    2239,   387,  2241,   482,   483,   484,   485,   486,   487,   488,
     489,   490,   491,   492,   493,   494,   495,  2067,  1563,  2160,
    2161,   496,  1948,  1578,   815,  1761,   112,   122,   123,   290,
     124,   899,  1712,     0,  1972,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   189,     0,     0,   507,   193,   507,
       0,     0,     0,   194,   195,   196,   197,   198,     0,     0,
       0,   107,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1411,     0,   201,   202,     0,     0,   507,
     203,     0,     0,     0,     0,   358,     0,     0,     0,     0,
     207,     0,   606,     0,     0,     0,   464,   465,   466,   468,
     470,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   503,     0,     0,     0,   510,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   517,   519,   522,   523,     0,   525,   519,   527,   528,
    2066,   530,   519,   532,   533,   534,   535,   536,   537,     0,
     539,   540,     0,     0,     0,     0,   519,     0,     0,     0,
     482,   483,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   493,   494,   495,     0,   575,   577,   519,   496,     0,
       0,     0,     0,     0,     0,     0,     0,   585,   519,     0,
       0,     0,     0,     0,  1693,     0,  2180,     0,     0,     0,
       0,     0,     0,     0,   607,     0,     0,     0,     0,     0,
       0,     0,     0,   616,   617,     0,     0,     0,     0,     0,
       0,     0,   617,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   641,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2218,     0,  2221,     0,
       0,     0,     0,   660,     0,     0,     0,   663,   664,   665,
       0,   667,     0,     0,     0,   670,   671,   672,     0,     0,
     673,     0,     0,     0,     0,     0,     0,     0,  2240,     0,
       0,   508,     0,     0,     0,   687,     0,     0,     0,     0,
     692,   694,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   701,   702,     0,   704,   705,   706,
     707,   708,   709,   710,   711,   712,   713,   714,   715,   716,
     717,   718,   719,   720,   721,   722,   723,   724,   725,     0,
       0,   508,     0,   508,     0,     0,     0,     0,     0,     0,
       0,     0,   739,     0,     0,     0,     0,     0,   745,     0,
     747,     0,     0,  1813,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   508,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   778,   519,     0,   780,   781,   782,
     783,   784,   785,   786,   787,   788,   789,   790,   791,   792,
     793,   794,     0,     0,   796,   797,   482,   483,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,   495,
       0,     0,     0,   575,   496,     0,     0,     0,     0,   824,
       0,     0,     0,     0,   829,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   842,   843,     0,
       0,     0,     0,     0,   849,   850,     0,     0,   857,   857,
     862,   863,     0,   865,     0,     0,   867,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   857,   519,
       0,     0,     0,     0,     0,   883,   885,   887,   888,     0,
       0,     0,   893,   894,   895,     0,     0,     0,     0,   900,
     902,   905,   908,   911,   913,     0,   915,     0,   917,     0,
     519,   519,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1850,     0,     0,     0,   935,   936,
     937,   464,   465,   938,     0,     0,     0,   943,   944,   945,
     946,   947,   948,   949,   950,   951,     0,     0,     0,     0,
     957,     0,   959,   960,     0,     0,     0,   519,   519,   519,
       0,     0,   967,   968,   969,   482,   483,   484,   485,   486,
     487,   488,   489,   490,   491,   492,   493,   494,   495,     0,
       0,   519,     0,   496,     0,     0,   849,   850,     0,   887,
     888,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1001,   519,     0,     0,     0,  1005,     0,     0,     0,     0,
       0,     0,     0,   132,   386,     0,     0,     0,     0,   135,
     136,   137,     0,     0,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1890,     0,   170,   171,   172,   173,     0,     0,     0,
    1077,   178,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   183,   184,   185,     0,     0,     0,     0,     0,
     186,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1922,  1106,  1107,     0,     0,   519,  1113,
    1114,     0,   519,  1117,     0,     0,     0,     0,     0,     0,
       0,  1124,     0,     0,   885,  1127,   482,   483,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,   495,
       0,     0,     0,   520,   496,     0,  1148,     0,   520,     0,
       0,     0,     0,   520,     0,     0,     0,     0,     0,   519,
       0,   519,     0,     0,   519,     0,     0,   520,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   519,     0,   519,
       0,   519,     0,   519,     0,     0,   576,     0,   520,   519,
       0,     0,     0,     0,   519,     0,   189,     0,     0,   520,
     193,  1187,     0,     0,     0,   194,   195,   196,   197,   198,
       0,     0,     0,   107,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   519,   626,   627,     0,
       0,     0,   203,  1212,  1213,     0,     0,   628,     0,  1216,
       0,     0,   207,     0,   319,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1246,     0,
       0,  1248,     0,   482,   483,   484,   485,   486,   487,   488,
     489,   490,   491,   492,   493,   494,   495,     0,     0,     0,
    1262,   496,  1264,  1265,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1272,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   288,   482,   483,   484,   485,   486,
     487,   488,   489,   490,   491,   492,   493,   494,   495,     0,
       0,     0,     0,   496,     0,  1294,     0,     0,     0,     0,
       0,     0,     0,  1295,  1296,  1297,  2060,   519,     7,     8,
       0,     0,     0,     0,     0,  1300,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1307,
       0,     0,     0,     0,  1310,     0,     0,     0,     0,     0,
       0,     0,     0,  1314,     0,     0,     0,     0,     0,  1322,
       0,     0,     0,     0,     0,     0,   520,     0,     0,   519,
     519,   519,   519,  1335,     0,     0,     0,  1338,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     771,    24,    25,   772,    27,    28,   773,    30,   774,    32,
      33,    34,    35,     0,   576,     0,    37,    38,    39,     0,
      40,     0,     0,     0,     0,    45,   775,    47,     0,     0,
      49,   776,     0,    52,    53,    54,     0,     0,     0,    57,
       0,     0,     0,     0,     0,     0,   519,     0,     0,   858,
     860,     0,     0,    70,     0,  2136,  1391,  1392,     0,  1393,
    1394,     0,  1395,  1396,  1397,     0,     0,     0,     0,   879,
     520,     0,  1403,     0,     0,  2008,   580,   886,   519,    84,
      85,    86,     0,     0,     0,     0,     0,     0,     0,  1416,
       0,  1418,     0,  1420,     0,  1422,     0,     0,     0,     0,
       0,   520,   520,     0,     0,   541,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1442,     0,
       0,     7,     8,     0,   288,     0,     0,     0,   482,   483,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
     494,   495,     0,     0,   590,     0,   496,     0,   520,   520,
     520,   939,  1477,   600,   602,   604,     0,     0,     0,   609,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   520,     0,     0,  1497,     0,     0,     0,     0,
    1502,     0,     0,     0,     0,  2112,     0,     0,   644,     0,
       0,     0,   520,   771,    24,    25,   772,    27,    28,   773,
      30,   774,    32,    33,    34,    35,     0,     0,     0,    37,
      38,    39,     0,    40,     0,     0,     0,     0,    45,   775,
      47,     0,  1544,    49,   776,     0,    52,    53,    54,     0,
       0,  1552,    57,     0,   580,  1555,  1556,     0,     0,     0,
       0,   689,   690,     0,     0,     0,    70,     0,     0,     0,
    1565,  1567,     0,     0,   698,   978,     0,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     495,     0,    84,    85,    86,   496,   482,   483,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   819,   494,   495,
       0,     0,   736,     0,   496,     0,     0,     0,     0,   520,
       0,     0,     0,   520,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   886,  1128,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1633,  1634,  1635,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1647,     0,
    1649,  1092,     0,     0,   961,     0,     0,     0,     0,     0,
     520,  1654,   520,     0,     0,   520,     0,     0,     0,     0,
       0,     0,     0,     0,   519,     0,     0,     0,   520,  1670,
     520,     0,   520,     0,   520,     0,     0,  1675,  1676,  1677,
     520,     0,     0,     0,     0,   520,   482,   483,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,   495,
       0,     0,     0,     0,   496,     0,     0,     0,     0,  1697,
       0,     0,     0,     0,     0,     0,   590,   520,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1709,   482,   483,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   819,   494,   495,     0,  1723,
       0,     0,   496,     0,  1729,   482,   483,   484,   485,   486,
     487,   488,   489,   490,   491,   492,   493,   494,   495,  1737,
    1738,     0,     0,   496,     0,     0,  1743,  1744,     0,     0,
       0,     0,     0,  1748,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1752,
    1753,  1754,  1755,  1756,  1757,  1758,     0,     0,     0,     0,
       0,     0,     0,  1763,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   519,   519,  1775,     0,  1776,   520,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1794,   482,   483,   484,   485,   486,   487,   488,   489,   490,
     491,   492,   493,   494,   495,     0,     0,     0,     0,   496,
     519,     0,     0,     0,  1812,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1822,     0,     0,     0,     0,
     520,   520,   520,   520,     7,     8,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1842,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1066,     0,     0,     0,
    1072,     0,     0,     0,  1177,     0,     0,     0,     0,  1857,
    1858,     0,     0,     0,     0,     0,     0,  1864,     0,   521,
       0,     0,     0,     0,   526,     0,     0,     0,     0,   531,
       0,     0,     0,     0,     0,     0,     0,   520,  1483,     0,
       0,     0,     0,   544,  1884,     0,   771,    24,    25,   772,
      27,    28,   773,    30,   774,    32,    33,    34,    35,     0,
       0,     0,    37,    38,    39,  1893,    40,     0,     0,   520,
       0,    45,   775,    47,     0,   586,    49,   776,     0,    52,
      53,    54,     0,     0,  1908,    57,     0,     0,     0,     0,
       0,     0,     0,   575,     0,     0,     0,     0,     0,    70,
       0,  1919,     0,  1920,     0,     0,   519,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1934,     0,    84,    85,    86,     0,     0,
       0,     0,     0,     0,     0,  1188,     0,     0,     0,     0,
       0,  1940,     0,     0,     0,     0,  1944,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1955,     0,
       0,     0,     0,     0,  1959,  1960,  1961,  1962,  1963,     0,
       0,     0,     0,     0,   519,     0,     0,     0,     0,     0,
       0,  1977,     0,  1980,     0,  1983,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   519,     0,   983,     0,     0,
       0,     0,     0,  1999,   482,   483,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,   495,     0,     0,
       0,     0,   496,     0,     0,     0,  2013,  2014,     0,  1275,
       0,  2016,     0,  1279,     0,     0,     0,  1284,   482,   483,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
     494,   495,     0,     0,     0,     0,   496,     0,     0,     0,
    2038,     0,   779,   482,   483,   484,   485,   486,   487,   488,
     489,   490,   491,   492,   493,   494,   495,     0,     0,     0,
    1301,   496,     0,     0,     0,     0,     0,     0,  1780,     0,
    1781,  2064,     0,     0,     0,     0,     0,  1729,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2075,  2076,  2077,
    2078,  2079,  2080,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2090,     0,     0,  2094,     0,
       0,  2098,     0,     0,     0,  2101,     0,     0,     0,     0,
     519,   519,   519,   519,   519,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2116,   520,   880,  2118,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1364,  1365,
       0,  1367,     0,  1370,  1371,     0,  1373,     0,  1375,  1376,
    1377,  1378,  1379,  1380,  1381,  1382,     0,   919,   920,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2154,  2155,  2156,  2157,
    2158,  2159,     0,     0,  1402,     0,     0,     0,     0,     0,
    1406,     0,     0,     0,     0,     0,     0,     0,     0,   519,
       0,     0,     0,     0,   962,   963,   964,     0,     0,   890,
       0,     0,     0,     0,     0,     0,     0,   380,   134,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   982,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2205,  2206,  2207,  2208,  2209,  2210,     0,  1002,     0,
       0,     0,     0,  1467,     0,     0,     0,   161,   162,   163,
     164,   165,   166,   167,   168,   169,  1478,  1479,  1480,     0,
     174,   175,   176,   177,     0,     0,     0,     0,   179,   180,
     181,     0,  1492,   182,   520,   520,     0,     0,     0,     0,
       0,     0,     0,     0,   187,   482,   483,   484,   485,   486,
     487,   488,   489,   490,   491,   492,   493,   494,   495,     0,
       0,     0,     0,   496,     0,     0,     0,     0,     0,     0,
    1816,   520,  1817,     0,     0,     0,     0,     0,     0,  1009,
    1010,  1011,  1012,  1013,  1014,  1015,  1016,  1017,  1018,  1019,
       0,  1021,  1022,  1023,  1024,  1025,  1026,  1027,     0,     0,
    1558,  1031,  1033,  1034,     0,  1112,     0,  1038,  1039,  1116,
    1041,     0,     0,     0,     0,  1046,  1047,  1048,     0,  1050,
       0,     0,     0,     0,  1579,     0,  1058,  1060,     0,     0,
    1585,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1598,  1083,     0,     0,     0,     0,     0,
     190,   191,   192,     0,     0,     0,  1155,     0,  1156,     0,
       0,  1158,     0,   199,     0,   200,  1615,  1616,  1617,     0,
       0,     0,  1620,  1621,  1170,  1622,  1171,  1623,  1172,  1624,
    1173,  1625,  1626,  1627,     0,     0,  1178,     7,     8,     0,
       0,  1181,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1648,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   576,     0,  1658,     0,     0,     0,
       0,     0,     0,  1206,  1666,     0,     0,   520,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1163,
       0,     0,     0,     0,  1935,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1174,     0,     0,     0,     0,   771,
      24,    25,   772,    27,    28,   773,    30,   774,    32,    33,
      34,    35,     7,     8,     0,    37,    38,    39,     0,    40,
       0,     0,     0,     0,    45,   775,    47,     0,     0,    49,
     776,     0,    52,    53,    54,   520,     0,     0,    57,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1721,    70,     0,     0,     0,   520,     0,     0,     0,
       0,     0,     0,     0,  1733,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1298,     0,     0,     0,    84,    85,
      86,     0,     0,     0,   771,    24,    25,   772,    27,    28,
     773,    30,   774,    32,    33,    34,    35,     0,     0,     0,
      37,    38,    39,     0,    40,     0,     0,     0,     0,    45,
     775,    47,     0,     0,    49,   776,     0,    52,    53,    54,
       0,     0,     0,    57,     0,     0,  1331,  1332,  1333,  1334,
       0,     0,   234,   235,     0,     0,     0,    70,     0,     0,
       0,     0,  1793,     0,     0,     0,     0,     0,     0,     0,
     984,     0,     0,     0,     0,     0,     0,  1558,     0,     0,
       0,     0,     0,    84,    85,    86,     0,     0,     0,     0,
       0,     0,  1815,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1827,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1834,  1386,     0,     0,     0,  1839,     0,     0,
       0,   520,   520,   520,   520,   520,  1337,     0,     0,   482,
     483,   484,   485,   486,   487,   488,   489,   490,   491,   492,
     493,   494,   495,     0,  1859,  1407,     0,   496,     0,     0,
       0,     0,     0,     0,  1975,  1209,  1976,     0,     0,  1359,
    1360,   398,     0,     0,     0,     0,     0,     0,     0,  1558,
     412,   413,   414,   415,   416,   417,   418,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,   435,   436,     0,     0,     0,   440,   441,
     442,   443,     0,   445,   446,   447,   448,   449,   450,     0,
     520,   452,     0,     0,  1905,     0,     0,   453,   454,   132,
     386,     0,     0,   459,   460,   135,   136,   137,     0,     0,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,     0,     0,   482,   483,   484,   485,   486,
     487,   488,   489,   490,   491,   492,   493,   494,   495,   170,
     171,   172,   173,   496,     0,     0,     0,   178,  1558,     0,
       0,     0,  1090,     0,     0,  1949,  1950,     0,   183,   184,
     185,     0,     0,     0,     0,     0,   186,   552,     0,   555,
     556,   557,   558,     0,  1558,     0,     0,     0,     0,     0,
     573,     0,   376,   134,     0,     0,     0,     0,     0,     0,
       0,   584,     0,  1504,  1989,     0,     0,     0,     0,  1508,
    1509,  1510,  1511,  1512,     0,  1515,     0,  1517,  1518,     0,
    1521,  1524,     0,     0,  1528,  1529,  1530,     0,     0,     0,
       0,  1534,   161,   162,   163,   164,   165,   166,   167,   168,
     169,     0,     0,     0,     0,   174,   175,   176,   177,     0,
       0,     0,     0,   179,   180,   181,     0,     0,   182,     0,
       0,     0,     0,     0,     0,     0,  2031,     0,     0,   187,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   189,     0,     0,  2048,   193,     0,     0,     0,
       0,   194,   195,   196,   197,   198,     0,     0,     0,   107,
       0,     0,     0,  1601,     0,     0,     0,     0,     0,     0,
       0,  1668,     0,   201,   202,     0,     0,     0,   203,     0,
    1612,     0,     0,   358,   467,     0,     0,     0,   207,   482,
     483,   484,   485,   486,   487,   488,   489,   490,   491,   492,
     493,   494,   495,     0,     0,     0,     0,   496,     0,     0,
       0,     0,     0,     0,     0,     0,  1150,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1558,
       0,     0,     0,     0,     0,   190,   191,   192,     0,     0,
       0,     0,     0,     0,     0,   769,     0,     0,   199,     0,
     200,   107,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   132,   386,     0,     0,     0,  1686,
     135,   136,   137,     0,  1690,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,     0,     0,
       0,     0,     0,     0,     0,     0,  1703,  1704,     0,     0,
    1706,  1707,     0,     0,   170,   171,   172,   173,     0,     0,
       0,     0,   178,     0,     0,     0,     0,     0,     0,     0,
    1773,  1774,     0,   183,   184,   185,     0,     0,     0,     0,
    1558,   186,     0,     0,     0,     0,   132,   133,   134,     0,
       0,     0,   135,   136,   137,     0,     0,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
       0,     0,     0,     0,     0,     0,     0,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,     0,     0,     0,   179,   180,
     181,     0,     0,   182,     0,   183,   184,   185,     0,     0,
       0,     0,     0,   186,   187,   482,   483,   484,   485,   486,
     487,   488,   489,   490,   491,   492,   493,   494,   495,     0,
       0,     0,     0,   496,     0,     0,     0,   189,     0,     0,
       0,   193,  1166,     0,     0,     0,   194,   195,   196,   197,
     198,     0,  1829,  1830,   107,     0,  1832,  1833,     0,     0,
       0,     0,  1836,  1837,     0,     0,     0,     0,   201,   202,
       0,     0,     0,   203,     0,     0,     0,     0,   358,     0,
       0,   469,     0,   207,   482,   483,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,   495,     0,     0,
       0,     0,   496,     0,     0,     0,     0,     0,     0,     0,
       0,  1237,   188,  1921,     0,     0,     0,  1877,  1878,   189,
     190,   191,   192,   193,     0,     0,     0,     0,   194,   195,
     196,   197,   198,   199,     0,   200,   107,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     201,   202,     0,     0,     0,   203,     0,     0,     0,     0,
     204,     0,   205,     0,   206,   207,     0,   208,     0,   209,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1973,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   132,   266,     0,     0,     0,     0,   135,   136,
     137,     0,  1993,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   267,   268,   269,   270,
     271,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   170,   171,   172,   173,     0,     0,     0,     0,
     178,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   183,   184,   185,     0,     0,     0,     0,     0,   186,
       0,     0,     0,   272,     0,     0,   273,     0,     0,   274,
       0,   275,     0,     0,     0,     0,     0,     0,    36,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   276,
       0,    48,     0,     0,   277,     0,     0,   278,     0,     0,
       0,     0,     0,     0,    59,    60,    61,    62,    63,     0,
       0,    65,    66,    67,    68,    69,     0,     0,     0,    73,
       0,     0,    76,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2105,  2106,  2107,
    2108,  2110,     0,     0,   482,   483,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,   495,     0,     0,
       0,     0,   496,     0,     0,   189,     0,     0,     0,   193,
     279,  1287,     0,     0,   194,   195,   196,   197,   198,     0,
       0,     0,   107,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   626,  1808,     0,     0,
       0,   203,     0,     0,     0,     0,   628,     0,     0,     0,
       0,   207,     0,   319,   578,  1311,  1312,   132,   266,     0,
       0,  1316,  1317,   135,   136,   137,  2176,     0,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   267,   268,   269,   270,   271,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   170,   171,   172,
     173,     0,     0,     0,     0,   178,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   183,   184,   185,     0,
       0,     0,     0,     0,   186,     0,     0,     0,   272,     0,
       0,   273,     0,     0,   274,     0,   275,     0,     0,     0,
    2185,     0,     0,    36,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   276,     0,    48,   134,     0,   277,
       0,     0,   278,     0,     0,     0,     0,     0,     0,    59,
      60,    61,    62,    63,     0,     0,    65,    66,    67,    68,
      69,     0,     0,     0,    73,     0,     0,    76,     0,     0,
       0,     0,     0,     0,     0,     0,   161,   162,   163,   164,
     165,   166,   167,   168,   169,     0,     0,     0,     0,   174,
     175,   176,   177,     0,     0,     0,     0,   179,   180,   181,
       0,     0,   182,     0,     0,     0,     0,     0,     0,     0,
     189,     0,     0,   187,   193,   279,     0,     0,     0,   194,
     195,   196,   197,   198,     0,     0,     0,   107,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1494,  1495,
       0,   201,   518,  1499,  1500,     0,   203,     0,     0,     0,
       0,   358,     0,     0,     0,     0,   207,     0,     0,   578,
     132,   266,   134,     0,     0,     0,   135,   136,   137,     0,
       0,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   267,   268,   269,   270,   271,     0,
       0,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   190,
     191,   192,   179,   180,   181,     0,     0,   182,     0,   183,
     184,   185,   199,     0,   200,     0,     0,   186,   187,     0,
       0,   272,     0,     0,   273,     0,     0,   274,     0,   275,
       0,     0,     0,     0,     0,     0,    36,     0,     0,     0,
       0,     0,   504,   134,     0,     0,     0,   276,     0,    48,
       0,     0,   277,     0,     0,   278,     0,     0,     0,     0,
       0,     0,    59,    60,    61,    62,    63,     0,     0,    65,
      66,    67,    68,    69,     0,     0,     0,    73,     0,     0,
      76,     0,   161,   162,   163,   164,   165,   166,   167,   168,
     169,     0,     0,     0,     0,   174,   175,   176,   177,     0,
       0,     0,     0,   179,   180,   181,     0,     0,   182,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   187,
       0,     0,     0,   189,   190,   191,   192,   193,   279,     0,
       0,     0,   194,   195,   196,   197,   198,   199,     0,   200,
     107,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   201,   280,     0,     0,     0,   203,
       0,     0,     0,     0,   358,     0,   132,   266,   134,   207,
       0,   282,   135,   136,   137,     0,     0,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     267,   268,   269,   270,   271,     0,     0,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   190,   191,   192,   179,   180,
     181,     0,     0,   182,     0,   183,   184,   185,   199,     0,
     200,   107,     0,   186,   187,     0,     0,   272,     0,     0,
     273,     0,     0,   274,     0,   275,     0,     0,     0,     0,
       0,     0,    36,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   276,     0,    48,     0,     0,   277,     0,
       0,   278,     0,     0,     0,     0,     0,     0,    59,    60,
      61,    62,    63,     0,     0,    65,    66,    67,    68,    69,
       0,     0,     0,    73,     0,     0,    76,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     495,     0,     0,     0,     0,   496,     0,     0,     0,     0,
       0,     0,     0,     0,  1434,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   189,
     190,   191,   192,   193,   279,     0,     0,     0,   194,   195,
     196,   197,   198,   199,     0,   200,   107,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     201,   280,     0,     0,     0,   203,     0,     0,     0,     0,
     358,     0,   132,   266,   357,   207,     0,  1838,   135,   136,
     137,     0,     0,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   267,   268,   269,   270,
     271,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   170,   171,   172,   173,     0,     0,     0,     0,
     178,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   183,   184,   185,     0,     0,     0,     0,     0,   186,
       0,     0,     0,   272,     0,     0,   273,     0,     0,   274,
       0,   275,     0,     0,     0,     0,     0,     0,    36,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   276,
       0,    48,     0,     0,   277,     0,     0,   278,     0,     0,
       0,     0,     0,     0,    59,    60,    61,    62,    63,     0,
       0,    65,    66,    67,    68,    69,     0,     0,     0,    73,
       0,     0,    76,   482,   483,   484,   485,   486,   487,   488,
     489,   490,   491,   492,   493,   494,   495,     0,     0,     0,
       0,   496,     0,     0,     0,     0,     0,     0,     0,     0,
    1778,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   189,     0,     0,     0,   193,
     279,     0,     0,     0,   194,   195,   196,   197,   198,     0,
       0,     0,   107,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   201,   280,     0,     0,
       0,   203,     0,     0,     0,     0,   358,     0,   132,   266,
    1657,   207,     0,   282,   135,   136,   137,     0,     0,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   267,   268,   269,   270,   271,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   170,   171,
     172,   173,     0,     0,     0,     0,   178,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   183,   184,   185,
       0,     0,     0,     0,     0,   186,     0,     0,     0,   272,
       0,     0,   273,     0,     0,   274,     0,   275,     0,     0,
       0,     0,     0,     0,    36,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   276,     0,    48,     0,     0,
     277,     0,     0,   278,     0,     0,     0,     0,     0,     0,
      59,    60,    61,    62,    63,     0,     0,    65,    66,    67,
      68,    69,     0,     0,     0,    73,     0,     0,    76,   482,
     483,   484,   485,   486,   487,   488,   489,   490,   491,   492,
     493,   494,   495,     0,     0,     0,     0,   496,     0,     0,
       0,     0,     0,     0,     0,     0,  1798,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   189,     0,     0,     0,   193,   279,     0,     0,     0,
     194,   195,   196,   197,   198,     0,     0,     0,   107,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   201,   280,     0,     0,     0,   203,     0,     0,
       0,     0,   358,     0,   132,   266,     0,   207,     0,   282,
     135,   136,   137,     0,     0,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   267,   268,
     269,   270,   271,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   170,   171,   172,   173,     0,     0,
       0,     0,   178,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   183,   184,   185,     0,     0,     0,     0,
       0,   186,     0,     0,     0,   272,     0,     0,   273,     0,
       0,   274,     0,   275,     0,     0,     0,     0,     0,     0,
      36,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   276,     0,    48,     0,     0,   277,     0,     0,   278,
       0,     0,     0,     0,     0,     0,    59,    60,    61,    62,
      63,     0,     0,    65,    66,    67,    68,    69,     0,     0,
       0,    73,     0,     0,    76,   482,   483,   484,   485,   486,
     487,   488,   489,   490,   491,   492,   493,   494,   495,     0,
       0,     0,     0,   496,     0,     0,     0,     0,     0,     0,
       0,     0,  1869,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   189,     0,     0,
       0,   193,   279,     0,     0,     0,   194,   195,   196,   197,
     198,     0,     0,     0,   107,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   201,   280,
       0,     0,     0,   203,     0,     0,     0,     0,   281,     0,
     132,   266,     0,   207,     0,   282,   135,   136,   137,     0,
       0,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   267,   268,   269,   270,   271,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     170,   171,   172,   173,     0,     0,     0,     0,   178,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   183,
     184,   185,     0,     0,     0,     0,     0,   186,     0,     0,
       0,   272,     0,     0,   273,     0,     0,   274,     0,   275,
       0,     0,     0,     0,     0,     0,    36,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   276,     0,    48,
       0,     0,   277,     0,     0,   278,     0,     0,     0,     0,
       0,     0,    59,    60,    61,    62,    63,     0,     0,    65,
      66,    67,    68,    69,     0,     0,     0,    73,     0,     0,
      76,   482,   483,   484,   485,   486,   487,   488,   489,   490,
     491,   492,   493,   494,   495,     0,     0,     0,     0,   496,
       0,     0,     0,     0,     0,     0,     0,     0,  1870,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   189,     0,     0,     0,   193,   279,     0,
       0,     0,   194,   195,   196,   197,   198,     0,     0,     0,
     107,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   201,   280,     0,     0,     0,   203,
       0,     0,     0,     0,   358,     0,   132,   266,     0,   207,
       0,   282,   135,   136,   137,     0,     0,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     267,   268,   269,   270,   271,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   170,   171,   172,   173,
       0,     0,     0,     0,   178,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   183,   184,   185,     0,     0,
       0,     0,     0,   186,     0,     0,     0,   272,     0,     0,
     273,     0,     0,   274,     0,   275,     0,     0,     0,     0,
       0,     0,    36,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   276,     0,    48,     0,     0,   277,     0,
       0,   278,     0,     0,     0,     0,     0,     0,    59,    60,
      61,    62,    63,     0,     0,    65,    66,    67,    68,    69,
       0,     0,     0,    73,     0,     0,    76,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     495,     0,     0,     0,     0,   496,     0,     0,     0,     0,
       0,     0,     0,     0,  1871,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   189,
       0,     0,     0,   193,   279,     0,     0,     0,   194,   195,
     196,   197,   198,     0,     0,     0,   107,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     201,   518,     0,     0,     0,   203,     0,     0,     0,     0,
     358,     0,   132,   266,     0,   207,     0,   574,   135,   136,
     137,     0,     0,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   267,   268,   269,   270,
     271,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   170,   171,   172,   173,     0,     0,     0,     0,
     178,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   183,   184,   185,     0,     0,     0,     0,     0,   186,
       0,     0,     0,   272,     0,     0,   273,     0,     0,   274,
       0,   275,     0,     0,     0,     0,     0,     0,    36,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   276,
       0,    48,     0,     0,   277,     0,     0,   278,     0,     0,
       0,     0,     0,     0,    59,    60,    61,    62,    63,     0,
       0,    65,    66,    67,    68,    69,     0,     0,     0,    73,
       0,     0,    76,   482,   483,   484,   485,   486,   487,   488,
     489,   490,   491,   492,   493,   494,   495,     0,     0,     0,
       0,   496,     0,     0,     0,     0,     0,     0,     0,     0,
    1872,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   189,     0,     0,     0,   193,
     279,     0,     0,     0,   194,   195,   196,   197,   198,     0,
       0,     0,   107,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   201,   280,     0,     0,
       0,   203,     0,     0,     0,     0,   589,     0,   132,   266,
       0,   207,     0,   282,   135,   136,   137,     0,     0,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   267,   268,   269,   270,   271,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   170,   171,
     172,   173,     0,     0,     0,     0,   178,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   183,   184,   185,
       0,     0,     0,     0,     0,   186,     0,     0,     0,   272,
       0,     0,   273,     0,     0,   274,     0,   275,     0,     0,
       0,     0,     0,     0,    36,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   276,     0,    48,     0,     0,
     277,     0,     0,   278,     0,     0,     0,     0,     0,     0,
      59,    60,    61,    62,    63,     0,     0,    65,    66,    67,
      68,    69,     0,     0,     0,    73,     0,     0,    76,   482,
     483,   484,   485,   486,   487,   488,   489,   490,   491,   492,
     493,   494,   495,     0,     0,     0,     0,   496,     0,     0,
       0,     0,     0,     0,     0,     0,  1874,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   189,     0,     0,     0,   193,   279,     0,     0,     0,
     194,   195,   196,   197,   198,     0,     0,     0,   107,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   201,   280,     0,     0,     0,   203,     0,     0,
       0,     0,   599,     0,   132,   266,     0,   207,     0,   282,
     135,   136,   137,     0,     0,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   267,   268,
     269,   270,   271,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   170,   171,   172,   173,     0,     0,
       0,     0,   178,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   183,   184,   185,     0,     0,     0,     0,
       0,   186,     0,     0,     0,   272,     0,     0,   273,     0,
       0,   274,     0,   275,     0,     0,     0,     0,     0,     0,
      36,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   276,     0,    48,     0,     0,   277,     0,     0,   278,
       0,     0,     0,     0,     0,     0,    59,    60,    61,    62,
      63,     0,     0,    65,    66,    67,    68,    69,     0,     0,
       0,    73,     0,     0,    76,   482,   483,   484,   485,   486,
     487,   488,   489,   490,   491,   492,   493,   494,   495,     0,
       0,     0,     0,   496,     0,     0,     0,     0,     0,     0,
       0,     0,  1917,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   189,     0,     0,
       0,   193,   279,     0,     0,     0,   194,   195,   196,   197,
     198,     0,     0,     0,   107,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   201,   280,
       0,     0,     0,   203,     0,     0,     0,     0,   601,     0,
     132,   266,     0,   207,     0,   282,   135,   136,   137,     0,
       0,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   267,   268,   269,   270,   271,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     170,   171,   172,   173,     0,     0,     0,     0,   178,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   183,
     184,   185,     0,     0,     0,     0,     0,   186,     0,     0,
       0,   272,     0,     0,   273,     0,     0,   274,     0,   275,
       0,     0,     0,     0,     0,     0,    36,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   276,     0,    48,
       0,     0,   277,     0,     0,   278,     0,     0,     0,     0,
       0,     0,    59,    60,    61,    62,    63,     0,     0,    65,
      66,    67,    68,    69,     0,     0,     0,    73,     0,     0,
      76,   482,   483,   484,   485,   486,   487,   488,   489,   490,
     491,   492,   493,   494,   495,     0,     0,     0,     0,   496,
       0,     0,     0,     0,     0,     0,     0,     0,  1964,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   189,     0,     0,     0,   193,   279,     0,
       0,     0,   194,   195,   196,   197,   198,     0,     0,     0,
     107,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   201,   280,     0,     0,     0,   203,
       0,     0,     0,     0,   603,     0,   132,   266,     0,   207,
       0,   282,   135,   136,   137,     0,     0,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     267,   268,   269,   270,   271,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   170,   171,   172,   173,
       0,     0,     0,     0,   178,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   183,   184,   185,     0,     0,
       0,     0,     0,   186,     0,     0,     0,   272,     0,     0,
     273,     0,     0,   274,     0,   275,     0,     0,     0,     0,
       0,     0,    36,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   276,     0,    48,     0,     0,   277,     0,
       0,   278,     0,     0,     0,     0,     0,     0,    59,    60,
      61,    62,    63,     0,     0,    65,    66,    67,    68,    69,
       0,     0,     0,    73,     0,     0,    76,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     495,     0,     0,     0,     0,   496,     0,     0,     0,     0,
       0,     0,     0,     0,  1991,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   189,
       0,     0,     0,   193,   279,     0,     0,     0,   194,   195,
     196,   197,   198,     0,     0,     0,   107,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     201,   518,     0,     0,     0,   203,     0,     0,     0,     0,
     358,     0,   132,   266,     0,   207,     0,   856,   135,   136,
     137,     0,     0,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   267,   268,   269,   270,
     271,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   170,   171,   172,   173,     0,     0,     0,     0,
     178,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   183,   184,   185,     0,     0,     0,     0,     0,   186,
       0,     0,     0,   272,     0,     0,   273,     0,     0,   274,
       0,   275,     0,     0,     0,     0,     0,     0,    36,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   276,
       0,    48,     0,     0,   277,     0,     0,   278,     0,     0,
       0,     0,     0,     0,    59,    60,    61,    62,    63,     0,
       0,    65,    66,    67,    68,    69,     0,     0,     0,    73,
       0,     0,    76,   482,   483,   484,   485,   486,   487,   488,
     489,   490,   491,   492,   493,   494,   495,     0,     0,     0,
       0,   496,     0,     0,     0,     0,     0,     0,     0,     0,
    2000,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   189,     0,     0,     0,   193,
     279,     0,     0,     0,   194,   195,   196,   197,   198,     0,
       0,     0,   107,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   201,   518,     0,     0,
       0,   203,     0,     0,     0,     0,   358,     0,   132,   266,
       0,   207,     0,   859,   135,   136,   137,     0,     0,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   267,   268,   269,   270,   271,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   170,   171,
     172,   173,     0,     0,     0,     0,   178,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   183,   184,   185,
       0,     0,     0,     0,     0,   186,     0,     0,     0,   272,
       0,     0,   273,     0,     0,   274,     0,   275,     0,     0,
       0,     0,     0,     0,    36,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   276,     0,    48,     0,     0,
     277,     0,     0,   278,     0,     0,     0,     0,     0,     0,
      59,    60,    61,    62,    63,     0,     0,    65,    66,    67,
      68,    69,     0,     0,     0,    73,     0,     0,    76,   482,
     483,   484,   485,   486,   487,   488,   489,   490,   491,   492,
     493,   494,   495,     0,     0,     0,     0,   496,     0,     0,
       0,     0,     0,     0,     0,     0,  2001,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   189,     0,     0,     0,   193,   279,     0,     0,     0,
     194,   195,   196,   197,   198,     0,     0,     0,   107,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   201,   518,     0,     0,     0,   203,     0,     0,
       0,     0,   358,     0,   132,   266,     0,   207,     0,   884,
     135,   136,   137,     0,     0,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   267,   268,
     269,   270,   271,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   170,   171,   172,   173,     0,     0,
       0,     0,   178,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   183,   184,   185,     0,     0,     0,     0,
       0,   186,     0,     0,     0,   272,     0,     0,   273,     0,
       0,   274,     0,   275,     0,     0,     0,     0,     0,     0,
      36,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   276,     0,    48,     0,     0,   277,     0,     0,   278,
       0,     0,     0,     0,     0,     0,    59,    60,    61,    62,
      63,     0,     0,    65,    66,    67,    68,    69,     0,     0,
       0,    73,     0,     0,    76,   482,   483,   484,   485,   486,
     487,   488,   489,   490,   491,   492,   493,   494,   495,     0,
       0,     0,     0,   496,     0,     0,     0,     0,     0,     0,
       0,     0,  2021,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   189,     0,     0,
       0,   193,   279,     0,     0,     0,   194,   195,   196,   197,
     198,     0,     0,     0,   107,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   201,   280,
       0,     0,     0,   203,     0,     0,     0,     0,   358,     0,
     132,   266,     0,   207,     0,  1665,   135,   136,   137,     0,
       0,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   267,   268,   269,   270,   271,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     170,   171,   172,   173,     0,     0,     0,     0,   178,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   183,
     184,   185,     0,     0,     0,     0,     0,   186,     0,     0,
       0,   272,     0,     0,   273,     0,     0,   274,     0,   275,
       0,     0,     0,     0,     0,     0,    36,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   276,     0,    48,
       0,     0,   277,     0,     0,   278,     0,     0,     0,     0,
       0,     0,    59,    60,    61,    62,    63,     0,     0,    65,
      66,    67,    68,    69,     0,     0,     0,    73,     0,     0,
      76,   482,   483,   484,   485,   486,   487,   488,   489,   490,
     491,   492,   493,   494,   495,     0,     0,     0,     0,   496,
       0,     0,     0,     0,     0,     0,     0,     0,  2039,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   189,     0,     0,     0,   193,   279,     0,
       0,     0,   194,   195,   196,   197,   198,     0,     0,     0,
     107,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   626,  1808,     0,     0,     0,   203,
       0,     0,     0,     0,   628,     0,   132,   386,   134,   207,
       0,   319,   135,   136,   137,     0,     0,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
       0,     0,     0,     0,     0,     0,     0,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,     0,     0,     0,   179,   180,
     181,     0,     0,   182,     0,   183,   184,   185,     0,   132,
     386,   134,     0,   186,   187,   135,   136,   137,     0,     0,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,     0,     0,     0,     0,     0,     0,     0,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,     0,     0,
       0,   179,   180,   181,     0,     0,   182,     0,   183,   184,
     185,     0,     0,     0,     0,     0,   186,   187,   482,   483,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
     494,   495,     0,     0,     0,     0,   496,     0,     0,     0,
       0,     0,     0,     0,     0,  2042,     0,     0,     0,   189,
     190,   191,   192,   193,     0,     0,     0,     0,   194,   195,
     196,   197,   198,   199,     0,   200,   107,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     201,   202,     0,     0,     0,   203,     0,     0,     0,     0,
     358,     0,     0,     0,     0,   207,     0,  1566,     0,     0,
     482,   483,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   493,   494,   495,     0,     0,     0,     0,   496,     0,
       0,     0,   189,   190,   191,   192,   193,  2045,     0,     0,
       0,   194,   195,   196,   197,   198,   199,     0,   200,   107,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   201,   202,     0,     0,     0,   203,     0,
       0,     0,     0,   358,     0,   132,   386,   134,   207,     0,
    1821,   135,   136,   137,     0,     0,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,     0,
       0,     0,     0,     0,     0,     0,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,     0,     0,     0,   179,   180,   181,
       7,     8,   182,     0,   183,   184,   185,     0,     0,     0,
       0,     0,   186,   187,   482,   483,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,   495,     0,     0,
       0,     0,   496,     0,     0,     0,     0,     0,     0,     0,
       0,  2087,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,   495,     0,     0,     0,     0,
     496,     0,     0,     0,     0,     0,     0,     0,     0,  2130,
       0,     0,   771,    24,    25,   772,    27,    28,   773,    30,
     774,    32,    33,    34,    35,     0,     0,     0,    37,    38,
      39,     0,    40,     0,     0,     0,     0,    45,   775,    47,
       0,     0,    49,   776,     0,    52,    53,    54,     0,     0,
       0,    57,     0,     0,     0,     0,     0,     0,   189,   190,
     191,   192,   193,     0,     0,    70,     0,   194,   195,   196,
     197,   198,   199,     0,   200,   107,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   201,
     202,    84,    85,    86,   203,     0,     0,     0,     0,   358,
       0,   132,   266,     0,   207,     0,  1841,   135,   136,   137,
       0,     0,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   267,   268,   269,   270,   271,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   170,   171,   172,   173,     0,     0,     0,     0,   178,
       0,     0,     0,  1210,     0,     0,     0,     0,     0,     0,
     183,   184,   185,     0,     0,     0,     0,     0,   186,     0,
       0,     0,   272,     0,     0,   273,     0,     0,   274,     0,
     275,     0,     0,     0,     0,     0,     0,    36,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   276,     0,
      48,     0,     0,   277,     0,     0,   278,     0,     0,     0,
       0,     0,     0,    59,    60,    61,    62,    63,     0,     0,
      65,    66,    67,    68,    69,     0,     0,     0,    73,     0,
       0,    76,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,   495,     0,     0,     0,     0,
     496,     0,     0,     0,     0,     0,     0,     0,     0,  2132,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   189,     0,     0,     0,   193,   279,
       0,     0,     0,   194,   195,   196,   197,   198,     0,     0,
       0,   107,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   201,   518,     0,     0,     0,
     203,   132,   386,   134,     0,   358,     0,   135,   136,   137,
     207,     0,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,     0,     0,     0,     0,     0,
       0,     0,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
       0,     0,     0,   179,   180,   181,     0,     0,   182,     0,
     183,   184,   185,     0,   132,   386,     0,     0,   186,   187,
     135,   136,   137,     0,     0,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,     0,     0,
     482,   483,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   493,   494,   495,   170,   171,   172,   173,   496,     0,
       0,     0,   178,     0,     0,     0,     0,  2134,     0,     0,
       0,     0,     0,   183,   184,   185,     0,     0,     0,     0,
       0,   186,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,   495,     0,     0,     0,     0,
     496,     0,     0,     0,     0,     0,     0,     0,     0,  2153,
       0,     0,     0,     0,   189,   190,   191,   192,   193,     0,
       0,     0,     0,   194,   195,   196,   197,   198,   199,     0,
     200,   107,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   201,   202,     0,     0,     0,
     203,     0,     0,     0,     0,   358,     0,     0,     0,     0,
     207,   482,   483,   484,   485,   486,   487,   488,   489,   490,
     491,   492,   493,   494,   495,     0,     0,     0,     0,   496,
       0,     0,     0,     0,     0,     0,     0,   189,  2184,     0,
       0,   193,     0,     0,     0,     0,   194,   195,   196,   197,
     198,     0,     0,     0,   107,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   201,   202,
       0,     0,     0,   203,   132,   386,     0,     0,   358,   691,
     135,   136,   137,   207,     0,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,     0,     0,
     482,   483,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   493,   494,   495,   170,   171,   172,   173,   496,     0,
       0,     0,   178,     0,     0,     0,     0,  2223,     0,     0,
       0,     0,     0,   183,   184,   185,   132,   386,     0,  1271,
       0,   186,   135,   136,   137,     0,     0,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
       0,     0,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,   495,   170,   171,   172,   173,
     496,     0,     0,     0,   178,     0,     0,     0,     0,  2224,
       0,     0,     0,     0,     0,   183,   184,   185,     0,     0,
       0,     0,     0,   186,   482,   483,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,   495,     0,     0,
       0,     0,   496,     0,     0,     0,     0,     0,     0,     0,
       0,  2225,     0,     0,     0,     0,     0,   189,     0,     0,
       0,   193,     0,     0,     0,     0,   194,   195,   196,   197,
     198,     0,     0,     0,   107,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   201,   202,
       0,     0,     0,   203,     0,     0,     0,     0,   358,     0,
       0,   693,     0,   207,   482,   483,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,   495,     0,     0,
       0,     0,   496,     0,     0,     0,     0,     0,     0,   189,
       0,  2226,     0,   193,     0,     0,     0,     0,   194,   195,
     196,   197,   198,     0,     0,     0,   107,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     201,   202,     0,     0,     0,   203,   132,   386,     0,  1441,
     358,     0,   135,   136,   137,   207,     0,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
       0,     0,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,   495,   170,   171,   172,   173,
     496,     0,     0,     0,   178,     0,     0,     0,     0,  2227,
       0,     0,     0,   132,   386,   183,   184,   185,     0,   135,
     136,   137,     0,   186,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,     0,     0,   482,
     483,   484,   485,   486,   487,   488,   489,   490,   491,   492,
     493,   494,   495,   170,   171,   172,   173,   496,     0,     0,
       0,   178,     0,     0,     0,     0,  2228,     0,     0,     0,
       0,     0,   183,   184,   185,     0,     0,     0,     0,     0,
     186,   482,   483,   484,   485,   486,   487,   488,   489,   490,
     491,   492,   493,   494,   495,     0,     0,     0,     0,   496,
       0,     0,     0,     0,     0,     0,     0,   683,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   189,
       0,     0,     0,   193,     0,     0,     0,     0,   194,   195,
     196,   197,   198,     0,     0,     0,   107,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     201,   202,     0,     0,     0,   203,     0,     0,     0,     0,
     358,     7,     8,     0,     0,   207,   482,   483,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,   495,
       0,     0,     0,     0,   496,     0,   189,     0,     0,     0,
     193,     0,   921,     0,     0,   194,   195,   196,   197,   198,
       0,     0,     0,   107,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   201,   202,     7,
       8,     0,   203,     0,     0,     0,     0,   358,     0,     0,
       0,     0,   207,   771,    24,    25,   772,    27,    28,   773,
      30,   774,    32,    33,    34,    35,     0,     0,     0,    37,
      38,    39,     0,    40,     0,     0,     0,     0,    45,   775,
      47,     0,     0,    49,   776,     0,    52,    53,    54,     0,
       0,     0,    57,     0,     0,     0,     7,     8,     0,     0,
       0,     0,     0,     0,     0,     0,    70,     0,     0,     0,
       0,   771,    24,    25,   772,    27,    28,   773,    30,   774,
      32,    33,    34,    35,     0,     0,     0,    37,    38,    39,
       0,    40,    84,    85,    86,     0,    45,   775,    47,     0,
       0,    49,   776,     0,    52,    53,    54,     0,     0,     0,
      57,     0,     0,     7,     8,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    70,     0,     0,     0,   771,    24,
      25,   772,    27,    28,   773,    30,   774,    32,    33,    34,
      35,     0,     0,     0,    37,    38,    39,     0,    40,     0,
      84,    85,    86,    45,   775,    47,     0,     0,    49,   776,
       0,    52,    53,    54,  1234,     0,     0,    57,     0,     0,
       7,     8,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    70,     0,     0,     0,   771,    24,    25,   772,    27,
      28,   773,    30,   774,    32,    33,    34,    35,     0,     0,
       0,    37,    38,    39,     0,    40,     0,    84,    85,    86,
      45,   775,    47,     0,     0,    49,   776,     0,    52,    53,
      54,     0,  1263,     0,    57,     0,     0,     7,     8,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    70,     0,
       0,     0,   771,    24,    25,   772,    27,    28,   773,    30,
     774,    32,    33,    34,    35,     0,     0,     0,    37,    38,
      39,     0,    40,     0,    84,    85,    86,    45,   775,    47,
       0,     0,    49,   776,     0,    52,    53,    54,     0,  1269,
       0,    57,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    70,     0,     0,     0,   771,
      24,    25,   772,    27,    28,   773,    30,   774,    32,    33,
      34,    35,     0,     0,     0,    37,    38,    39,     0,    40,
       0,    84,    85,    86,    45,   775,    47,     0,     0,    49,
     776,     0,    52,    53,    54,     0,  1430,     0,    57,     0,
       0,     0,     0,     0,     0,     0,     0,    -4,     1,     0,
       0,    -4,    70,     0,     0,     0,     0,     0,     0,    -4,
      -4,     0,     0,   482,   483,   484,   485,   486,   487,   488,
     489,   490,   491,   492,   493,   494,   495,     0,    84,    85,
      86,   496,     0,   852,     0,   853,     0,     0,  1514,    -4,
      -4,     0,     0,  2051,   482,   483,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,   495,     0,    -4,
      -4,    -4,   496,     0,     0,    -4,    -4,     0,    -4,     0,
    1889,     0,    -4,    -4,     0,    -4,    -4,     0,     0,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,     0,     0,    -4,    -4,    -4,    -4,
    2138,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
       0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,     0,     0,     0,    -4,    -4,    -4,     6,
       0,     0,     0,     0,    -4,     0,     0,     7,     8,    -4,
      -4,    -4,    -4,     0,     0,    -4,     0,    -4,     0,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,     0,     0,     0,     0,     9,    10,    -4,
      -4,    -4,     0,     0,     0,     0,     0,     0,    -4,     0,
      -4,     0,     0,     0,     0,     0,     0,    11,    12,    13,
       0,     0,     0,    14,    15,     0,    16,     0,     0,     0,
      17,    18,     0,    19,    20,     0,     0,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,     0,     0,    36,    37,    38,    39,     0,    40,
      41,    42,    43,    44,    45,    46,    47,    48,     0,    49,
      50,    51,    52,    53,    54,    55,     0,    56,    57,    58,
      59,    60,    61,    62,    63,    64,     0,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,     7,     8,     0,    79,    80,    81,     0,     0,     0,
       0,     0,    82,     0,     0,     0,     0,    83,    84,    85,
      86,     0,     0,    87,     0,    88,     0,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,     0,     0,     0,     0,     0,     0,   103,   104,   105,
       0,     0,     0,     0,     0,     0,   106,     0,   107,     7,
       8,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   771,    24,    25,   772,    27,    28,   773,
      30,   774,    32,    33,    34,    35,     0,     0,     0,    37,
      38,    39,     0,    40,     0,     0,     0,     0,    45,   775,
      47,     0,     0,    49,   776,     0,    52,    53,    54,     0,
       0,     0,    57,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    70,     0,     0,     0,
     988,   771,    24,    25,   772,    27,    28,   773,    30,   774,
      32,    33,    34,    35,     0,     0,     0,    37,    38,    39,
       0,    40,    84,    85,    86,     0,    45,   775,    47,     0,
       0,    49,   776,     0,    52,    53,    54,     0,     0,     0,
      57,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    70,     0,     0,     0,   482,   483,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
     494,   495,     0,     0,     0,     0,   496,     0,   970,     0,
      84,    85,    86,   928,   482,   483,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,   495,     0,     0,
       0,     0,   496,     0,     0,     0,     0,     0,     0,   808,
     482,   483,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   493,   494,   495,     0,     0,     0,     0,   496,     0,
       0,     0,     0,     0,     0,   928,   482,   483,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,   495,
       0,     0,     0,     0,   496,     0,     0,     0,     0,     0,
       0,   929,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,   495,     0,     0,     0,     0,
     496,     0,     0,     0,     0,     0,     0,   975,   482,   483,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
     494,   495,     0,     0,     0,     0,   496,     0,     0,     0,
       0,     0,     0,  1020,   482,   483,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,   495,     0,     0,
       0,     0,   496,     0,     0,     0,     0,     0,     0,  1028,
     482,   483,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   493,   494,   495,     0,     0,     0,     0,   496,     0,
       0,     0,     0,     0,     0,  1029,   482,   483,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,   495,
       0,     0,     0,     0,   496,     0,     0,     0,     0,     0,
       0,  1030,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,   495,     0,     0,     0,     0,
     496,     0,     0,     0,     0,     0,     0,  1045,   482,   483,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
     494,   495,     0,     0,     0,     0,   496,     0,     0,     0,
       0,     0,     0,  1161,   482,   483,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,   495,     0,     0,
       0,     0,   496,     0,     0,     0,     0,     0,     0,  1162,
     482,   483,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   493,   494,   495,     0,     0,     0,     0,   496,     0,
       0,     0,     0,     0,     0,  1164,   482,   483,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,   495,
       0,     0,     0,     0,   496,     0,     0,     0,     0,     0,
       0,  1218,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,   495,     0,     0,     0,     0,
     496,     0,     0,     0,     0,     0,     0,  1219,   482,   483,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
     494,   495,     0,     0,     0,     0,   496,     0,     0,     0,
       0,     0,     0,  1220,   482,   483,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,   495,     0,     0,
       0,     0,   496,     0,     0,     0,     0,     0,     0,  1257,
     482,   483,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   493,   494,   495,     0,     0,     0,     0,   496,     0,
       0,     0,     0,     0,     0,  1355,   482,   483,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,   495,
       0,     0,     0,     0,   496,     0,     0,     0,     0,     0,
       0,  1432,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,   495,     0,     0,     0,     0,
     496,     0,     0,     0,     0,     0,     0,  1433,   482,   483,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
     494,   495,     0,     0,     0,     0,   496,     0,     0,     0,
       0,     0,     0,  1482,   482,   483,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,   495,     0,     0,
       0,     0,   496,     0,     0,     0,     0,     0,     0,  1604,
     482,   483,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   493,   494,   495,     0,     0,     0,     0,   496,     0,
       0,     0,     0,     0,     0,  1605,   482,   483,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,   495,
       0,     0,     0,     0,   496,     0,     0,     0,     0,     0,
       0,  1606,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,   495,     0,     0,     0,     0,
     496,     0,     0,     0,     0,     0,     0,  1607,   482,   483,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
     494,   495,     0,     0,     0,     0,   496,     0,     0,     0,
       0,     0,     0,  1608,   482,   483,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,   495,     0,     0,
       0,     0,   496,     0,     0,     0,     0,     0,     0,  1609,
     482,   483,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   493,   494,   495,     0,     0,     0,     0,   496,     0,
       0,     0,     0,     0,     0,  1610,   482,   483,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,   495,
       0,     0,     0,     0,   496,     0,     0,     0,     0,     0,
       0,  1724,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,   495,     0,     0,     0,     0,
     496,     0,     0,     0,     0,     0,     0,  1725,   482,   483,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
     494,   495,     0,     0,     0,     0,   496,     0,     0,     0,
       0,     0,     0,  1732,   482,   483,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,   495,     0,     0,
       0,     0,   496,     0,     0,     0,     0,     0,     0,  1879,
     482,   483,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   493,   494,   495,     0,     0,     0,     0,   496,     0,
       0,     0,     0,     0,     0,  1880,   482,   483,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,   495,
       0,     0,     0,     0,   496,     0,     0,     0,     0,     0,
       0,  1881,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,   495,     0,     0,     0,     0,
     496,     0,     0,     0,     0,     0,     0,  1882,   482,   483,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
     494,   495,     0,     0,     0,     0,   496,     0,     0,     0,
       0,     0,     0,  1883,   482,   483,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,   495,     0,     0,
       0,     0,   496,     0,     0,     0,     0,     0,     0,  1941,
     482,   483,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   493,   494,   495,     0,     0,     0,     0,   496,     0,
       0,     0,     0,     0,     0,  1942,   482,   483,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,   495,
       0,     0,     0,     0,   496,     0,     0,     0,     0,     0,
       0,  1946,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,   495,     0,     0,     0,     0,
     496,     0,     0,     0,     0,     0,     0,  2023,   482,   483,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
     494,   495,     0,     0,     0,     0,   496,     0,     0,     0,
       0,     0,     0,  2024,   482,   483,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,   495,     0,     0,
       0,     0,   496,     0,     0,     0,     0,     0,     0,  2025,
     482,   483,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   493,   494,   495,     0,     0,     0,     0,   496,     0,
       0,     0,     0,     0,     0,  2026,   482,   483,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,   495,
       0,     0,     0,     0,   496,     0,     0,     0,     0,     0,
       0,  2027,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,   495,     0,     0,     0,     0,
     496,     0,     0,     0,     0,     0,     0,  2069,   482,   483,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
     494,   495,     0,     0,     0,     0,   496,     0,     0,     0,
       0,     0,     0,  2072,   482,   483,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,   495,     0,     0,
       0,     0,   496,     0,     0,     0,     0,     0,     0,  2121,
     482,   483,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   493,   494,   495,     0,     0,     0,     0,   496,     0,
       0,     0,     0,     0,     0,  2122,   482,   483,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,   495,
       0,     0,     0,     0,   496,     0,     0,     0,     0,     0,
       0,  2123,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,   495,     0,     0,     0,     0,
     496,     0,     0,     0,     0,     0,     0,  2124,   482,   483,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
     494,   495,     0,     0,     0,     0,   496,     0,     0,     0,
       0,     0,     0,  2125,   482,   483,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,   495,     0,     0,
       0,     0,   496,     0,     0,     0,     0,     0,     0,  2126,
     482,   483,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   493,   494,   495,     0,     0,     0,     0,   496,     0,
       0,     0,     0,     0,     0,  2186,   482,   483,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,   495,
       0,     0,     0,     0,   496,     0,     0,     0,     0,     0,
       0,  2187,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,   495,     0,     0,     0,     0,
     496,     0,     0,     0,     0,     0,     0,  2188,   482,   483,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
     494,   495,     0,     0,     0,     0,   496,     0,     0,     0,
       0,     0,     0,  2189,   482,   483,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,   495,     0,     0,
       0,     0,   496,     0,   852,     0,   853,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     495,     0,     0,     0,     0,   496,     0,     0,     0,   763,
     482,   483,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   493,   494,   495,     0,     0,     0,     0,   496,     0,
       0,     0,   981,   482,   483,   484,   485,   486,   487,   488,
     489,   490,   491,   492,   493,   494,   495,     0,     0,     0,
       0,   496,     0,     0,     0,  1000,   482,   483,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,   495,
       0,     0,     0,     0,   496,     0,     0,     0,  1007,   482,
     483,   484,   485,   486,   487,   488,   489,   490,   491,   492,
     493,   494,   495,     0,     0,     0,     0,   496,     0,     0,
       0,  1105,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,   495,     0,     0,     0,     0,
     496,     0,     0,     0,  1154,   482,   483,   484,   485,   486,
     487,   488,   489,   490,   491,   492,   493,   494,   495,     0,
       0,     0,     0,   496,     0,     0,     0,  1180,   482,   483,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
     494,   495,     0,     0,     0,     0,   496,     0,     0,     0,
    1250,   482,   483,   484,   485,   486,   487,   488,   489,   490,
     491,   492,   493,   494,   495,     0,     0,     0,     0,   496,
       0,     0,     0,  1251,   482,   483,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,   495,     0,     0,
       0,     0,   496,     0,     0,     0,  1255,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     495,     0,     0,     0,     0,   496,     0,     0,     0,  1256,
     482,   483,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   493,   494,   495,     0,     0,     0,     0,   496,     0,
       0,     0,  1289,   482,   483,   484,   485,   486,   487,   488,
     489,   490,   491,   492,   493,   494,   495,     0,     0,     0,
       0,   496,     0,     0,     0,  1348,   482,   483,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,   495,
       0,     0,     0,     0,   496,     0,     0,     0,  1353,   482,
     483,   484,   485,   486,   487,   488,   489,   490,   491,   492,
     493,   494,   495,     0,     0,     0,     0,   496,     0,     0,
       0,  1671,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,   495,     0,     0,     0,     0,
     496,     0,     0,     0,  1714,   482,   483,   484,   485,   486,
     487,   488,   489,   490,   491,   492,   493,   494,   495,     0,
       0,     0,     0,   496,     0,     0,     0,  1903,   482,   483,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
     494,   495,     0,     0,     0,     0,   496,     0,   759,   482,
     483,   484,   485,   486,   487,   488,   489,   490,   491,   492,
     493,   494,   495,     0,     0,     0,     0,   496,     0,   818,
     482,   483,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   493,   494,   495,     0,     0,     0,     0,   496,     0,
     822,   482,   483,   484,   485,   486,   487,   488,   489,   490,
     491,   492,   493,   494,   495,     0,     0,     0,     0,   496,
       0,   823,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,   495,     0,     0,     0,     0,
     496,     0,   825,   482,   483,   484,   485,   486,   487,   488,
     489,   490,   491,   492,   493,   494,   495,     0,     0,     0,
       0,   496,     0,   827,   482,   483,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,   495,     0,     0,
       0,     0,   496,     0,   828,   482,   483,   484,   485,   486,
     487,   488,   489,   490,   491,   492,   493,   494,   495,     0,
       0,     0,     0,   496,     0,   830,   482,   483,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,   495,
       0,     0,     0,     0,   496,     0,   832,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     495,     0,     0,     0,     0,   496,     0,   833,   482,   483,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
     494,   495,     0,     0,     0,     0,   496,     0,   834,   482,
     483,   484,   485,   486,   487,   488,   489,   490,   491,   492,
     493,   494,   495,     0,     0,     0,     0,   496,     0,   835,
     482,   483,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   493,   494,   495,     0,     0,     0,     0,   496,     0,
     836,   482,   483,   484,   485,   486,   487,   488,   489,   490,
     491,   492,   493,   494,   495,     0,     0,     0,     0,   496,
       0,   837,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,   495,     0,     0,     0,     0,
     496,     0,   839,   482,   483,   484,   485,   486,   487,   488,
     489,   490,   491,   492,   493,   494,   495,     0,     0,     0,
       0,   496,     0,   840,   482,   483,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,   495,     0,     0,
       0,     0,   496,     0,   881,   482,   483,   484,   485,   486,
     487,   488,   489,   490,   491,   492,   493,   494,   495,     0,
       0,     0,     0,   496,     0,   891,   482,   483,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,   495,
       0,     0,     0,     0,   496,     0,   952,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     495,     0,     0,     0,     0,   496,     0,   970,   482,   483,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
     494,   495,     0,     0,     0,     0,   496,     0,   971,   482,
     483,   484,   485,   486,   487,   488,   489,   490,   491,   492,
     493,   494,   495,     0,     0,     0,     0,   496,     0,   972,
     482,   483,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   493,   494,   495,     0,     0,     0,     0,   496,     0,
     973,   482,   483,   484,   485,   486,   487,   488,   489,   490,
     491,   492,   493,   494,   495,     0,     0,     0,     0,   496,
       0,   979,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,   495,     0,     0,     0,     0,
     496,     0,   980,   482,   483,   484,   485,   486,   487,   488,
     489,   490,   491,   492,   493,   494,   495,     0,     0,     0,
       0,   496,     0,   987,   482,   483,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,   495,     0,     0,
       0,     0,   496,     0,   996,   482,   483,   484,   485,   486,
     487,   488,   489,   490,   491,   492,   493,   494,   495,     0,
       0,     0,     0,   496,     0,  1006,   482,   483,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,   495,
       0,     0,     0,     0,   496,     0,  1104,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     495,     0,     0,     0,     0,   496,     0,  1132,   482,   483,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
     494,   495,     0,     0,     0,     0,   496,     0,  1137,   482,
     483,   484,   485,   486,   487,   488,   489,   490,   491,   492,
     493,   494,   495,     0,     0,     0,     0,   496,     0,  1149,
     482,   483,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   493,   494,   495,     0,     0,     0,     0,   496,     0,
    1153,   482,   483,   484,   485,   486,   487,   488,   489,   490,
     491,   492,   493,   494,   495,     0,     0,     0,     0,   496,
       0,  1179,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,   495,     0,     0,     0,     0,
     496,     0,  1184,   482,   483,   484,   485,   486,   487,   488,
     489,   490,   491,   492,   493,   494,   495,     0,     0,     0,
       0,   496,     0,  1185,   482,   483,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,   495,     0,     0,
       0,     0,   496,     0,  1186,   482,   483,   484,   485,   486,
     487,   488,   489,   490,   491,   492,   493,   494,   495,     0,
       0,     0,     0,   496,     0,  1192,   482,   483,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,   495,
       0,     0,     0,     0,   496,     0,  1201,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     495,     0,     0,     0,     0,   496,     0,  1202,   482,   483,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
     494,   495,     0,     0,     0,     0,   496,     0,  1203,   482,
     483,   484,   485,   486,   487,   488,   489,   490,   491,   492,
     493,   494,   495,     0,     0,     0,     0,   496,     0,  1236,
     482,   483,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   493,   494,   495,     0,     0,     0,     0,   496,     0,
    1238,   482,   483,   484,   485,   486,   487,   488,   489,   490,
     491,   492,   493,   494,   495,     0,     0,     0,     0,   496,
       0,  1239,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,   495,     0,     0,     0,     0,
     496,     0,  1240,   482,   483,   484,   485,   486,   487,   488,
     489,   490,   491,   492,   493,   494,   495,     0,     0,     0,
       0,   496,     0,  1241,   482,   483,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,   495,     0,     0,
       0,     0,   496,     0,  1242,   482,   483,   484,   485,   486,
     487,   488,   489,   490,   491,   492,   493,   494,   495,     0,
       0,     0,     0,   496,     0,  1243,   482,   483,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,   495,
       0,     0,     0,     0,   496,     0,  1244,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     495,     0,     0,     0,     0,   496,     0,  1249,   482,   483,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
     494,   495,     0,     0,     0,     0,   496,     0,  1347,   482,
     483,   484,   485,   486,   487,   488,   489,   490,   491,   492,
     493,   494,   495,     0,     0,     0,     0,   496,     0,  1352,
     482,   483,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   493,   494,   495,     0,     0,     0,     0,   496,     0,
    1526,   482,   483,   484,   485,   486,   487,   488,   489,   490,
     491,   492,   493,   494,   495,     0,     0,     0,     0,   496,
       0,  1551,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,   495,     0,     0,     0,     0,
     496,     0,  1720,   482,   483,   484,   485,   486,   487,   488,
     489,   490,   491,   492,   493,   494,   495,     0,     0,     0,
       0,   496,     0,  1779,   482,   483,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,   495,     0,     0,
       0,     0,   496,     0,  1797,   482,   483,   484,   485,   486,
     487,   488,   489,   490,   491,   492,   493,   494,   495,     0,
       0,     0,     0,   496,     0,  1820,   482,   483,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,   495,
       0,     0,     0,     0,   496,     0,  2068,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     495,     0,     0,     0,     0,   496,     0,  2151,   482,   483,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
     494,   495,     0,     0,     0,     0,   496
};

static const yytype_int16 yycheck[] =
{
       3,     3,   312,     6,   620,   621,  1659,  1682,  1683,     5,
     434,     4,   436,     5,  1231,     4,     6,     4,     6,     5,
      90,     6,     6,     4,     4,  1865,   467,   451,   469,     4,
     471,     5,     4,     4,     4,    87,     4,     6,    90,     5,
    1235,     5,     4,    46,   131,     4,     6,     4,     4,     4,
      90,     5,     5,     5,     5,     4,    90,     6,     6,     6,
       6,   224,   225,     6,     6,   217,   218,     7,   217,   218,
     110,    74,   262,   263,   264,   168,   110,   217,   218,    82,
     227,   233,   229,   235,    87,     7,   235,   227,   227,     6,
     229,   184,   185,     6,   234,    98,   231,   236,  1751,   217,
     218,   236,    60,    61,     6,    63,   121,   297,   298,   299,
      98,    87,   100,     7,    90,   233,    92,   235,   217,   218,
     224,   225,    87,   138,     0,    90,     7,   121,   217,   218,
     234,   146,   147,   148,   233,    84,   235,   152,   153,   154,
     155,   217,   218,    13,   138,   234,   224,   225,   338,   339,
     217,   218,   146,   147,   148,   227,   234,   233,   152,   153,
     154,   155,   352,   353,   217,   218,   227,   234,   217,   218,
       6,   158,   159,   160,   161,   171,   217,   218,     6,  2019,
    2020,   234,   227,     7,   233,   171,   229,   156,   224,   225,
     179,   327,   233,   168,   169,     7,   156,   171,   234,     7,
     224,   225,     6,   183,   207,   171,   208,  1860,   344,   156,
     234,   168,   169,   156,   203,    84,   219,   220,    87,     6,
     235,    90,   203,     7,   227,   224,   225,   217,   218,   214,
     214,   203,   235,  1886,   237,   234,   229,     6,   234,   242,
    1457,   235,   234,   236,   247,   234,   234,   383,   235,   385,
     691,   254,   693,   234,   257,   391,   227,   227,   261,   262,
     263,   264,   265,   234,   234,   227,   234,   229,   227,   231,
     234,   227,   227,   276,   236,   234,     6,   280,   234,   282,
     234,   234,   234,   234,     3,   227,   234,     6,   234,   227,
     293,   231,   234,   296,   297,   298,   299,     6,     4,     5,
     217,   218,   305,   306,   307,   227,     7,   229,   311,   312,
     204,   205,   206,   207,     7,   217,   218,   229,   759,   224,
     225,   227,   763,   204,   205,   206,   207,   224,   225,   234,
     224,   225,     6,     7,   231,   338,   339,   340,    44,    45,
      46,    47,    48,    49,    50,    51,    52,   227,     4,   352,
     353,    57,    58,    59,    60,    74,   227,   315,   316,    65,
      66,    67,   228,     7,    70,   323,   227,   233,    87,   327,
     227,   217,   218,   217,   218,    81,     7,   234,   227,    98,
     204,   205,   206,   207,   471,   234,   389,   233,  2063,   233,
     393,   394,   204,   205,   206,   207,   204,   205,   206,   207,
     224,   225,   227,   406,   224,   225,   227,   231,   217,   218,
     230,   399,   224,   225,   227,   219,   220,   227,  2071,   229,
     204,   205,   206,   207,   233,   228,   236,   230,   217,   218,
     233,   434,   435,   436,   437,   438,   439,   440,   441,   442,
     443,   444,   445,   446,   233,   448,   449,   450,   451,   452,
     254,   217,   218,   456,   457,   458,   459,   460,   461,   227,
     463,   265,    84,   217,   218,    87,   454,   233,    90,   125,
     126,   127,   128,   103,   462,   611,   612,   480,     8,   233,
     228,   187,   188,   189,   140,   233,   227,   143,   207,   217,
     218,   219,   220,   221,   200,   631,   202,   203,   226,    90,
     219,   220,   227,   204,   205,   206,   207,     4,   227,   234,
     227,   204,   205,   206,   207,   518,   235,   234,   224,   225,
     217,   218,   227,   224,   225,   231,   217,   218,   234,  2182,
       6,     7,   668,   217,   218,   254,   233,   217,   218,   228,
     217,   218,   233,   228,   233,   227,   265,   683,   233,   233,
     553,   554,   234,   233,   557,   996,   233,   217,   218,  1000,
     204,   205,   206,   207,   227,   568,   217,   218,   217,   218,
     573,   574,   227,   204,   205,   206,   207,   227,   581,   229,
     224,   225,   233,    90,   233,   389,   236,    84,   217,   218,
     227,    88,   229,   312,   231,   217,   218,    94,    95,   236,
      97,    98,   605,   606,   233,   227,     6,   595,   596,   597,
     598,   234,   234,   217,   218,   227,   703,   114,   620,   621,
     228,   227,   230,   229,   217,   218,   234,   217,   218,   233,
     236,   435,   227,   437,   438,   439,   440,   441,   442,   443,
     233,   445,   446,   233,   448,   449,   450,   234,   452,   652,
     653,   654,   456,   457,   458,   459,   460,    90,   217,   218,
     618,   619,   227,    90,   229,    92,   231,    92,   626,   234,
     389,   236,   759,   676,   233,   227,   763,   229,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   227,   696,   217,   218,   226,   217,   218,   227,
      87,   229,  1897,   231,  1899,   235,  1901,   234,   236,    87,
     233,   227,    90,   233,    92,   434,   435,   436,   437,   438,
     439,   440,   441,   442,   443,   230,   445,   446,   233,   448,
     449,   450,   451,   452,   217,   218,   234,   456,   457,   458,
     459,   460,   461,    90,   463,   217,   218,   217,   218,   233,
     233,   235,  1193,   557,  1195,   758,  1197,    87,  1199,   762,
     121,   233,  1979,   233,   851,  1982,   217,   218,  1985,    87,
     227,  1081,   229,   217,   218,    84,   764,   138,    87,   236,
      90,    90,   233,    92,   227,   146,   147,   148,   924,   233,
       4,   152,   153,   154,   155,    84,   125,   126,    87,     4,
     803,    90,   131,    92,   807,     4,   227,   810,   228,   228,
     813,   230,   815,   233,   121,   234,   819,   820,     4,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   233,   817,
     235,   138,   226,   121,   230,   554,   227,   233,   557,   146,
     147,   148,   219,   220,   221,   152,   153,   154,   155,   226,
     138,   854,   233,   856,   235,   227,   859,  2052,   146,   147,
     148,   227,   125,   126,   152,   153,   154,   155,   131,   872,
       6,   874,   121,   876,   235,   878,   229,   228,  1319,   230,
     229,   884,   233,     6,   227,  2102,   889,  1311,  1312,   138,
     121,   227,  1316,  1317,   897,   228,  1337,   146,   147,   148,
     233,   227,     7,   152,   153,   154,   155,   138,   233,   996,
     235,     8,   233,  1000,   235,   146,   147,   148,   921,  1006,
    1007,   152,   153,   154,   155,   228,   228,   230,   235,   227,
     233,   233,   227,   121,  2129,   228,  2131,   230,  2133,   233,
     233,   235,   227,   227,  2139,  2162,   121,   235,  2165,     8,
     138,  2168,   227,   233,  2171,   235,   227,   227,   146,   147,
     148,   227,   229,   138,   152,   153,   154,   155,   228,   927,
     230,   146,   147,   148,     6,   234,   934,   152,   153,   154,
     155,   234,   228,   941,   230,     6,   235,   233,   991,   228,
     234,   230,   995,   227,   233,  2212,   999,  2214,  2193,  2216,
    2195,   234,  2197,   228,  1007,   230,   810,   233,   233,   235,
     233,   815,   235,   233,   227,   235,  1326,  1104,  1105,   227,
    1636,  1637,   233,   233,   235,   235,   233,   110,   235,  1032,
     233,   233,   235,   235,  1037,   233,    90,   235,    92,  1042,
    1043,  1044,  1045,    90,   233,    92,   235,   235,   233,   233,
     235,   235,  1055,   233,  1057,   235,   233,   233,   235,   235,
     235,   234,   233,  1504,   235,   227,  1153,  1154,   227,   227,
    1494,  1495,   233,   227,   235,  1499,  1500,   233,  1081,   235,
       4,  1084,  1085,  1086,  1087,   233,   233,   235,   235,   234,
       6,   810,  1179,  1180,   813,   233,   815,   235,   233,   233,
     235,   235,   233,   233,   235,   235,   227,   233,  1111,   235,
     227,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   227,   234,  1130,  1131,   226,
    1133,   228,  1135,  1136,   233,  1138,   235,  1140,  1141,  1142,
    1143,  1144,  1145,  1146,  1147,   234,     4,     5,  1151,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,     4,   233,     6,   235,   226,  1126,   233,
     233,   235,   235,  1176,   234,   233,   235,   235,   234,  1182,
    1183,   233,   233,   235,   235,   234,    44,    45,    46,    47,
      48,    49,    50,    51,    52,   233,   233,   235,   235,    57,
      58,    59,    60,  1007,   233,   229,   235,    65,    66,    67,
     227,   233,    70,   235,   233,   233,   235,   235,   233,     6,
     235,     6,   233,    81,   235,   233,   233,   235,   235,   233,
     227,   235,  1319,  1037,   233,  1545,   235,   229,   236,  1043,
    1044,  1045,  1245,   233,   233,   235,   235,   121,   233,   227,
     235,  1055,   233,  1057,   235,  1258,  1259,  1260,   227,   227,
    1218,  1219,  1220,   227,   138,     6,   233,   233,   235,   235,
     227,  1274,   146,   147,   148,   233,  1892,   235,   152,   153,
     154,   155,   233,   233,   235,   235,   227,   233,  1007,   235,
       6,   234,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   234,  1111,  1311,  1312,
     226,   234,   229,  1316,  1317,     6,   229,     6,  1037,   233,
       6,   235,   234,  1326,  1043,  1044,  1045,   171,   236,   187,
     188,   189,     6,     6,   234,     6,  1055,     6,  1057,  1342,
     234,   234,   200,     6,   202,   203,   229,     4,   226,   231,
     234,     7,     7,  1489,   235,  1491,   233,   233,   228,     6,
       6,   235,  1081,  1366,     8,     6,   228,     4,  1356,  1372,
     228,     7,   230,     7,    62,    62,     6,    62,    62,     6,
       6,   228,  1385,     6,   234,     7,     6,   168,     7,     6,
       6,     6,  1111,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,  1408,  1409,  1410,   234,   226,
     230,  1414,  1415,   228,  1417,     6,  1419,  1841,  1421,  1506,
    1423,  1424,  1425,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,     6,   228,   228,
    1443,   226,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   233,   233,  1458,   233,   226,   233,   233,
     233,   233,   228,  1466,   228,   228,  1469,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   230,    44,    44,    44,   226,    44,     6,     4,   227,
       4,  1494,  1495,     6,     6,     6,  1499,  1500,  1456,     6,
    1488,     7,     7,   171,     7,     7,   171,     7,     7,     7,
    1513,   171,     7,  1600,     7,     7,  1519,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,     6,   234,     7,     7,   226,     7,     7,     7,     6,
     230,  1851,  1545,     7,     7,   228,     4,     6,   121,  1537,
    1553,   228,   234,   234,   234,   234,   234,   233,   228,     7,
    1563,   233,   228,  1566,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,  1566,   121,
     233,   233,   226,   228,   235,   235,     6,   235,   231,     7,
       7,     7,  1311,  1312,     7,   234,   138,  1316,  1317,   231,
       6,    44,    44,    44,   146,   147,   148,  1326,    44,     6,
     152,   153,   154,   155,     6,     6,     6,     6,  1576,     7,
     229,     6,   227,   227,   227,  1628,  1629,   234,     6,   214,
       7,     7,    92,     7,  1636,  1637,     7,     7,     7,     7,
       6,  1644,     7,   121,  1632,     7,     7,     7,     7,     7,
       4,     4,    87,   234,     6,   227,  1659,     7,     6,   234,
     138,     7,  1665,     7,     7,     7,     7,     6,   146,   147,
     148,  1674,     7,     7,   152,   153,   154,   155,     6,     6,
    1638,  1684,  1640,     6,  1642,    90,     7,     6,     6,     4,
       4,  1694,  1680,   235,     4,   233,  1699,   234,   234,     6,
     235,     6,  1660,  1661,  1662,  1663,  1664,  1665,     6,  1513,
       6,  1699,  1700,  1701,     6,  1519,     6,     4,     6,   234,
     228,   231,     7,  1726,   233,     6,     6,   228,     6,   233,
     227,     6,   228,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   231,  1751,   230,
     114,   226,   234,     6,   234,   234,     6,   235,   234,  1563,
       6,   171,   234,     6,     6,     6,     6,     6,     6,     6,
     121,  1907,     6,     6,     5,  1494,  1495,     4,   228,   230,
    1499,  1500,     6,     6,     6,     4,     6,   138,   234,   234,
     121,     7,   229,  1796,  1513,   146,   147,   148,     6,     6,
    1519,   152,   153,   154,   155,  1808,   234,   138,   234,   234,
       6,     6,   234,   234,     6,   146,   147,   148,  1821,   234,
     234,   152,   153,   154,   155,   234,  1545,   234,     6,     6,
     234,   167,     6,   233,     6,  1838,  1824,     4,  1841,     7,
       6,     6,     6,     4,  1563,     7,     6,     6,  1851,     6,
       6,     6,     4,     6,   234,     6,     6,  1860,     6,    88,
       6,     5,   234,     6,  1867,  1868,     6,     6,  2004,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,  1886,   235,     6,  1889,   226,     6,     6,
    1892,     6,     6,     6,     6,     6,     6,     6,     6,     6,
       6,   233,     6,  1906,   235,     6,     6,  1910,   233,     6,
       6,   228,     6,     6,     6,     6,     6,  2053,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,     7,     6,   231,   234,   226,     6,  1896,   234,
    1898,   234,  1900,   234,     5,   234,     6,     6,   234,     6,
     234,     6,   235,  1911,  1912,  1913,  1914,  1915,   235,   235,
     234,   234,     7,   234,     6,  1968,   166,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,     6,     6,   235,  1987,   226,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     235,     6,     6,   235,   226,     6,  2009,     6,     6,  1967,
       6,     3,     4,  1971,   228,   169,     6,     9,    10,    11,
    2008,     6,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,     6,     6,     6,     6,     6,
     234,     6,  2055,  2056,  2057,  2058,  2059,     6,   234,     7,
       6,    53,    54,    55,    56,   234,     6,     6,  2071,    61,
       6,  2029,   235,   121,     6,  2033,   234,     6,     6,     6,
      72,    73,    74,     6,     6,   234,     6,   234,    80,     6,
       6,     6,     6,   235,   227,     6,   234,   234,   234,   228,
     235,  2059,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,     6,     6,   234,     6,
     226,     6,  1841,     6,  2112,     6,     6,     6,     6,     6,
       6,   234,  1851,     6,     6,   234,   234,     6,     6,   234,
       6,  2144,     6,     6,     6,   234,     6,  2150,     6,     6,
       6,   106,     6,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,  2012,  1351,  2127,
    2128,   226,  1866,  1365,   514,  1616,     3,     3,     3,  2182,
       3,   593,  1541,    -1,  1888,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   186,    -1,    -1,  2200,   190,  2202,
      -1,    -1,    -1,   195,   196,   197,   198,   199,    -1,    -1,
      -1,   203,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   121,    -1,   217,   218,    -1,    -1,  2232,
     222,    -1,    -1,    -1,    -1,   227,    -1,    -1,    -1,    -1,
     232,    -1,   234,    -1,    -1,    -1,   201,   202,   203,   204,
     205,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   218,    -1,    -1,    -1,   222,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   236,   237,   238,   239,    -1,   241,   242,   243,   244,
    2009,   246,   247,   248,   249,   250,   251,   252,   253,    -1,
     255,   256,    -1,    -1,    -1,    -1,   261,    -1,    -1,    -1,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,    -1,   280,   281,   282,   226,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   292,   293,    -1,
      -1,    -1,    -1,    -1,     6,    -1,  2150,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   309,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   318,   319,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   327,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   337,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2200,    -1,  2202,    -1,
      -1,    -1,    -1,   358,    -1,    -1,    -1,   362,   363,   364,
      -1,   366,    -1,    -1,    -1,   370,   371,   372,    -1,    -1,
     375,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2232,    -1,
      -1,  2150,    -1,    -1,    -1,   390,    -1,    -1,    -1,    -1,
     395,   396,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   409,   410,    -1,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,    -1,
      -1,  2200,    -1,  2202,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   447,    -1,    -1,    -1,    -1,    -1,   453,    -1,
     455,    -1,    -1,     6,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2232,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   479,   480,    -1,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     495,   496,    -1,    -1,   499,   500,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
      -1,    -1,    -1,   518,   226,    -1,    -1,    -1,    -1,   524,
      -1,    -1,    -1,    -1,   529,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   542,   543,    -1,
      -1,    -1,    -1,    -1,   549,   550,    -1,    -1,   553,   554,
     555,   556,    -1,   558,    -1,    -1,   561,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   573,   574,
      -1,    -1,    -1,    -1,    -1,   580,   581,   582,   583,    -1,
      -1,    -1,   587,   588,   589,    -1,    -1,    -1,    -1,   594,
     595,   596,   597,   598,   599,    -1,   601,    -1,   603,    -1,
     605,   606,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     6,    -1,    -1,    -1,   623,   624,
     625,   626,   627,   628,    -1,    -1,    -1,   632,   633,   634,
     635,   636,   637,   638,   639,   640,    -1,    -1,    -1,    -1,
     645,    -1,   647,   648,    -1,    -1,    -1,   652,   653,   654,
      -1,    -1,   657,   658,   659,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,    -1,
      -1,   676,    -1,   226,    -1,    -1,   681,   682,    -1,   684,
     685,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     695,   696,    -1,    -1,    -1,   700,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     3,     4,    -1,    -1,    -1,    -1,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     6,    -1,    53,    54,    55,    56,    -1,    -1,    -1,
     765,    61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    72,    73,    74,    -1,    -1,    -1,    -1,    -1,
      80,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     6,   799,   800,    -1,    -1,   803,   804,
     805,    -1,   807,   808,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   816,    -1,    -1,   819,   820,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
      -1,    -1,    -1,   237,   226,    -1,   841,    -1,   242,    -1,
      -1,    -1,    -1,   247,    -1,    -1,    -1,    -1,    -1,   854,
      -1,   856,    -1,    -1,   859,    -1,    -1,   261,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   872,    -1,   874,
      -1,   876,    -1,   878,    -1,    -1,   280,    -1,   282,   884,
      -1,    -1,    -1,    -1,   889,    -1,   186,    -1,    -1,   293,
     190,   896,    -1,    -1,    -1,   195,   196,   197,   198,   199,
      -1,    -1,    -1,   203,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   921,   217,   218,    -1,
      -1,    -1,   222,   928,   929,    -1,    -1,   227,    -1,   934,
      -1,    -1,   232,    -1,   234,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   953,    -1,
      -1,   956,    -1,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,    -1,    -1,    -1,
     975,   226,   977,   978,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   988,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    46,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,    -1,
      -1,    -1,    -1,   226,    -1,  1020,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1028,  1029,  1030,     6,  1032,    12,    13,
      -1,    -1,    -1,    -1,    -1,  1040,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1054,
      -1,    -1,    -1,    -1,  1059,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1068,    -1,    -1,    -1,    -1,    -1,  1074,
      -1,    -1,    -1,    -1,    -1,    -1,   480,    -1,    -1,  1084,
    1085,  1086,  1087,  1088,    -1,    -1,    -1,  1092,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    -1,   518,    -1,   100,   101,   102,    -1,
     104,    -1,    -1,    -1,    -1,   109,   110,   111,    -1,    -1,
     114,   115,    -1,   117,   118,   119,    -1,    -1,    -1,   123,
      -1,    -1,    -1,    -1,    -1,    -1,  1151,    -1,    -1,   553,
     554,    -1,    -1,   137,    -1,     6,  1161,  1162,    -1,  1164,
    1165,    -1,  1167,  1168,  1169,    -1,    -1,    -1,    -1,   573,
     574,    -1,  1177,    -1,    -1,     7,     8,   581,  1183,   163,
     164,   165,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1194,
      -1,  1196,    -1,  1198,    -1,  1200,    -1,    -1,    -1,    -1,
      -1,   605,   606,    -1,    -1,   257,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1223,    -1,
      -1,    12,    13,    -1,   276,    -1,    -1,    -1,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,    -1,    -1,   296,    -1,   226,    -1,   652,   653,
     654,   235,  1257,   305,   306,   307,    -1,    -1,    -1,   311,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   676,    -1,    -1,  1280,    -1,    -1,    -1,    -1,
    1285,    -1,    -1,    -1,    -1,     7,    -1,    -1,   340,    -1,
      -1,    -1,   696,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    -1,    -1,    -1,   100,
     101,   102,    -1,   104,    -1,    -1,    -1,    -1,   109,   110,
     111,    -1,  1327,   114,   115,    -1,   117,   118,   119,    -1,
      -1,  1336,   123,    -1,     8,  1340,  1341,    -1,    -1,    -1,
      -1,   393,   394,    -1,    -1,    -1,   137,    -1,    -1,    -1,
    1355,  1356,    -1,    -1,   406,     8,    -1,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,    -1,   163,   164,   165,   226,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
      -1,    -1,   444,    -1,   226,    -1,    -1,    -1,    -1,   803,
      -1,    -1,    -1,   807,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   819,   820,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1431,  1432,  1433,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1443,    -1,
    1445,     8,    -1,    -1,   235,    -1,    -1,    -1,    -1,    -1,
     854,  1456,   856,    -1,    -1,   859,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1469,    -1,    -1,    -1,   872,  1474,
     874,    -1,   876,    -1,   878,    -1,    -1,  1482,  1483,  1484,
     884,    -1,    -1,    -1,    -1,   889,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
      -1,    -1,    -1,    -1,   226,    -1,    -1,    -1,    -1,  1514,
      -1,    -1,    -1,    -1,    -1,    -1,   568,   921,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1538,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,    -1,  1554,
      -1,    -1,   226,    -1,  1559,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,  1574,
    1575,    -1,    -1,   226,    -1,    -1,  1581,  1582,    -1,    -1,
      -1,    -1,    -1,  1588,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1604,
    1605,  1606,  1607,  1608,  1609,  1610,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1618,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1628,  1629,  1630,    -1,  1632,  1032,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1645,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,    -1,    -1,    -1,    -1,   226,
    1665,    -1,    -1,    -1,  1669,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1680,    -1,    -1,    -1,    -1,
    1084,  1085,  1086,  1087,    12,    13,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1700,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   758,    -1,    -1,    -1,
     762,    -1,    -1,    -1,     8,    -1,    -1,    -1,    -1,  1724,
    1725,    -1,    -1,    -1,    -1,    -1,    -1,  1732,    -1,   237,
      -1,    -1,    -1,    -1,   242,    -1,    -1,    -1,    -1,   247,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1151,     8,    -1,
      -1,    -1,    -1,   261,  1759,    -1,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    -1,
      -1,    -1,   100,   101,   102,  1780,   104,    -1,    -1,  1183,
      -1,   109,   110,   111,    -1,   293,   114,   115,    -1,   117,
     118,   119,    -1,    -1,  1799,   123,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1808,    -1,    -1,    -1,    -1,    -1,   137,
      -1,  1816,    -1,  1818,    -1,    -1,  1821,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1838,    -1,   163,   164,   165,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   897,    -1,    -1,    -1,    -1,
      -1,  1856,    -1,    -1,    -1,    -1,  1861,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1873,    -1,
      -1,    -1,    -1,    -1,  1879,  1880,  1881,  1882,  1883,    -1,
      -1,    -1,    -1,    -1,  1889,    -1,    -1,    -1,    -1,    -1,
      -1,  1896,    -1,  1898,    -1,  1900,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1910,    -1,   235,    -1,    -1,
      -1,    -1,    -1,  1918,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,    -1,    -1,
      -1,    -1,   226,    -1,    -1,    -1,  1941,  1942,    -1,   991,
      -1,  1946,    -1,   995,    -1,    -1,    -1,   999,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,    -1,    -1,    -1,    -1,   226,    -1,    -1,    -1,
    1975,    -1,   480,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,    -1,    -1,    -1,
    1042,   226,    -1,    -1,    -1,    -1,    -1,    -1,   233,    -1,
     235,  2006,    -1,    -1,    -1,    -1,    -1,  2012,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2022,  2023,  2024,
    2025,  2026,  2027,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2040,    -1,    -1,  2043,    -1,
      -1,  2046,    -1,    -1,    -1,  2050,    -1,    -1,    -1,    -1,
    2055,  2056,  2057,  2058,  2059,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2069,  1469,   574,  2072,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1130,  1131,
      -1,  1133,    -1,  1135,  1136,    -1,  1138,    -1,  1140,  1141,
    1142,  1143,  1144,  1145,  1146,  1147,    -1,   605,   606,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2121,  2122,  2123,  2124,
    2125,  2126,    -1,    -1,  1176,    -1,    -1,    -1,    -1,    -1,
    1182,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2144,
      -1,    -1,    -1,    -1,   652,   653,   654,    -1,    -1,   584,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     4,     5,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   676,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2186,  2187,  2188,  2189,  2190,  2191,    -1,   696,    -1,
      -1,    -1,    -1,  1245,    -1,    -1,    -1,    44,    45,    46,
      47,    48,    49,    50,    51,    52,  1258,  1259,  1260,    -1,
      57,    58,    59,    60,    -1,    -1,    -1,    -1,    65,    66,
      67,    -1,  1274,    70,  1628,  1629,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    81,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,    -1,
      -1,    -1,    -1,   226,    -1,    -1,    -1,    -1,    -1,    -1,
     233,  1665,   235,    -1,    -1,    -1,    -1,    -1,    -1,   704,
     705,   706,   707,   708,   709,   710,   711,   712,   713,   714,
      -1,   716,   717,   718,   719,   720,   721,   722,    -1,    -1,
    1342,   726,   727,   728,    -1,   803,    -1,   732,   733,   807,
     735,    -1,    -1,    -1,    -1,   740,   741,   742,    -1,   744,
      -1,    -1,    -1,    -1,  1366,    -1,   751,   752,    -1,    -1,
    1372,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1385,   769,    -1,    -1,    -1,    -1,    -1,
     187,   188,   189,    -1,    -1,    -1,   854,    -1,   856,    -1,
      -1,   859,    -1,   200,    -1,   202,  1408,  1409,  1410,    -1,
      -1,    -1,  1414,  1415,   872,  1417,   874,  1419,   876,  1421,
     878,  1423,  1424,  1425,    -1,    -1,   884,    12,    13,    -1,
      -1,   889,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1443,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1808,    -1,  1458,    -1,    -1,    -1,
      -1,    -1,    -1,   921,  1466,    -1,    -1,  1821,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   864,
      -1,    -1,    -1,    -1,  1838,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   879,    -1,    -1,    -1,    -1,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    12,    13,    -1,   100,   101,   102,    -1,   104,
      -1,    -1,    -1,    -1,   109,   110,   111,    -1,    -1,   114,
     115,    -1,   117,   118,   119,  1889,    -1,    -1,   123,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1553,   137,    -1,    -1,    -1,  1910,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1566,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1032,    -1,    -1,    -1,   163,   164,
     165,    -1,    -1,    -1,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    -1,    -1,    -1,
     100,   101,   102,    -1,   104,    -1,    -1,    -1,    -1,   109,
     110,   111,    -1,    -1,   114,   115,    -1,   117,   118,   119,
      -1,    -1,    -1,   123,    -1,    -1,  1084,  1085,  1086,  1087,
      -1,    -1,    21,    22,    -1,    -1,    -1,   137,    -1,    -1,
      -1,    -1,  1644,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     235,    -1,    -1,    -1,    -1,    -1,    -1,  1659,    -1,    -1,
      -1,    -1,    -1,   163,   164,   165,    -1,    -1,    -1,    -1,
      -1,    -1,  1674,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1684,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1694,  1151,    -1,    -1,    -1,  1699,    -1,    -1,
      -1,  2055,  2056,  2057,  2058,  2059,  1091,    -1,    -1,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,    -1,  1726,  1183,    -1,   226,    -1,    -1,
      -1,    -1,    -1,    -1,   233,   235,   235,    -1,    -1,  1124,
    1125,   130,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1751,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,    -1,    -1,    -1,   167,   168,
     169,   170,    -1,   172,   173,   174,   175,   176,   177,    -1,
    2144,   180,    -1,    -1,  1796,    -1,    -1,   186,   187,     3,
       4,    -1,    -1,   192,   193,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    -1,    -1,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,    53,
      54,    55,    56,   226,    -1,    -1,    -1,    61,  1860,    -1,
      -1,    -1,   235,    -1,    -1,  1867,  1868,    -1,    72,    73,
      74,    -1,    -1,    -1,    -1,    -1,    80,   266,    -1,   268,
     269,   270,   271,    -1,  1886,    -1,    -1,    -1,    -1,    -1,
     279,    -1,     4,     5,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   290,    -1,  1288,  1906,    -1,    -1,    -1,    -1,  1294,
    1295,  1296,  1297,  1298,    -1,  1300,    -1,  1302,  1303,    -1,
    1305,  1306,    -1,    -1,  1309,  1310,  1311,    -1,    -1,    -1,
      -1,  1316,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    -1,    -1,    -1,    -1,    57,    58,    59,    60,    -1,
      -1,    -1,    -1,    65,    66,    67,    -1,    -1,    70,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1968,    -1,    -1,    81,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   186,    -1,    -1,  1987,   190,    -1,    -1,    -1,
      -1,   195,   196,   197,   198,   199,    -1,    -1,    -1,   203,
      -1,    -1,    -1,  1388,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1469,    -1,   217,   218,    -1,    -1,    -1,   222,    -1,
    1405,    -1,    -1,   227,   228,    -1,    -1,    -1,   232,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,    -1,    -1,    -1,    -1,   226,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   235,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2071,
      -1,    -1,    -1,    -1,    -1,   187,   188,   189,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   474,    -1,    -1,   200,    -1,
     202,   203,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,    -1,    -1,    -1,  1494,
       9,    10,    11,    -1,  1499,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1531,  1532,    -1,    -1,
    1535,  1536,    -1,    -1,    53,    54,    55,    56,    -1,    -1,
      -1,    -1,    61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1628,  1629,    -1,    72,    73,    74,    -1,    -1,    -1,    -1,
    2182,    80,    -1,    -1,    -1,    -1,     3,     4,     5,    -1,
      -1,    -1,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    -1,    -1,    -1,    65,    66,
      67,    -1,    -1,    70,    -1,    72,    73,    74,    -1,    -1,
      -1,    -1,    -1,    80,    81,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,    -1,
      -1,    -1,    -1,   226,    -1,    -1,    -1,   186,    -1,    -1,
      -1,   190,   235,    -1,    -1,    -1,   195,   196,   197,   198,
     199,    -1,  1687,  1688,   203,    -1,  1691,  1692,    -1,    -1,
      -1,    -1,  1697,  1698,    -1,    -1,    -1,    -1,   217,   218,
      -1,    -1,    -1,   222,    -1,    -1,    -1,    -1,   227,    -1,
      -1,   230,    -1,   232,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,    -1,    -1,
      -1,    -1,   226,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   235,   179,  1821,    -1,    -1,    -1,  1752,  1753,   186,
     187,   188,   189,   190,    -1,    -1,    -1,    -1,   195,   196,
     197,   198,   199,   200,    -1,   202,   203,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     217,   218,    -1,    -1,    -1,   222,    -1,    -1,    -1,    -1,
     227,    -1,   229,    -1,   231,   232,    -1,   234,    -1,   236,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1889,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,    -1,    -1,    -1,    -1,     9,    10,
      11,    -1,  1910,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    53,    54,    55,    56,    -1,    -1,    -1,    -1,
      61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    72,    73,    74,    -1,    -1,    -1,    -1,    -1,    80,
      -1,    -1,    -1,    84,    -1,    -1,    87,    -1,    -1,    90,
      -1,    92,    -1,    -1,    -1,    -1,    -1,    -1,    99,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   110,
      -1,   112,    -1,    -1,   115,    -1,    -1,   118,    -1,    -1,
      -1,    -1,    -1,    -1,   125,   126,   127,   128,   129,    -1,
      -1,   132,   133,   134,   135,   136,    -1,    -1,    -1,   140,
      -1,    -1,   143,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2055,  2056,  2057,
    2058,  2059,    -1,    -1,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,    -1,    -1,
      -1,    -1,   226,    -1,    -1,   186,    -1,    -1,    -1,   190,
     191,   235,    -1,    -1,   195,   196,   197,   198,   199,    -1,
      -1,    -1,   203,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   217,   218,    -1,    -1,
      -1,   222,    -1,    -1,    -1,    -1,   227,    -1,    -1,    -1,
      -1,   232,    -1,   234,   235,  1064,  1065,     3,     4,    -1,
      -1,  1070,  1071,     9,    10,    11,  2144,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,    54,    55,
      56,    -1,    -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    72,    73,    74,    -1,
      -1,    -1,    -1,    -1,    80,    -1,    -1,    -1,    84,    -1,
      -1,    87,    -1,    -1,    90,    -1,    92,    -1,    -1,    -1,
    2155,    -1,    -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   110,    -1,   112,     5,    -1,   115,
      -1,    -1,   118,    -1,    -1,    -1,    -1,    -1,    -1,   125,
     126,   127,   128,   129,    -1,    -1,   132,   133,   134,   135,
     136,    -1,    -1,    -1,   140,    -1,    -1,   143,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    -1,    -1,    -1,    -1,    57,
      58,    59,    60,    -1,    -1,    -1,    -1,    65,    66,    67,
      -1,    -1,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     186,    -1,    -1,    81,   190,   191,    -1,    -1,    -1,   195,
     196,   197,   198,   199,    -1,    -1,    -1,   203,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1277,  1278,
      -1,   217,   218,  1282,  1283,    -1,   222,    -1,    -1,    -1,
      -1,   227,    -1,    -1,    -1,    -1,   232,    -1,    -1,   235,
       3,     4,     5,    -1,    -1,    -1,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    -1,
      -1,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,   187,
     188,   189,    65,    66,    67,    -1,    -1,    70,    -1,    72,
      73,    74,   200,    -1,   202,    -1,    -1,    80,    81,    -1,
      -1,    84,    -1,    -1,    87,    -1,    -1,    90,    -1,    92,
      -1,    -1,    -1,    -1,    -1,    -1,    99,    -1,    -1,    -1,
      -1,    -1,     4,     5,    -1,    -1,    -1,   110,    -1,   112,
      -1,    -1,   115,    -1,    -1,   118,    -1,    -1,    -1,    -1,
      -1,    -1,   125,   126,   127,   128,   129,    -1,    -1,   132,
     133,   134,   135,   136,    -1,    -1,    -1,   140,    -1,    -1,
     143,    -1,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    -1,    -1,    -1,    -1,    57,    58,    59,    60,    -1,
      -1,    -1,    -1,    65,    66,    67,    -1,    -1,    70,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,
      -1,    -1,    -1,   186,   187,   188,   189,   190,   191,    -1,
      -1,    -1,   195,   196,   197,   198,   199,   200,    -1,   202,
     203,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   217,   218,    -1,    -1,    -1,   222,
      -1,    -1,    -1,    -1,   227,    -1,     3,     4,     5,   232,
      -1,   234,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    -1,    -1,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,   187,   188,   189,    65,    66,
      67,    -1,    -1,    70,    -1,    72,    73,    74,   200,    -1,
     202,   203,    -1,    80,    81,    -1,    -1,    84,    -1,    -1,
      87,    -1,    -1,    90,    -1,    92,    -1,    -1,    -1,    -1,
      -1,    -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   110,    -1,   112,    -1,    -1,   115,    -1,
      -1,   118,    -1,    -1,    -1,    -1,    -1,    -1,   125,   126,
     127,   128,   129,    -1,    -1,   132,   133,   134,   135,   136,
      -1,    -1,    -1,   140,    -1,    -1,   143,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,    -1,    -1,    -1,    -1,   226,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   235,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   186,
     187,   188,   189,   190,   191,    -1,    -1,    -1,   195,   196,
     197,   198,   199,   200,    -1,   202,   203,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     217,   218,    -1,    -1,    -1,   222,    -1,    -1,    -1,    -1,
     227,    -1,     3,     4,     5,   232,    -1,   234,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    53,    54,    55,    56,    -1,    -1,    -1,    -1,
      61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    72,    73,    74,    -1,    -1,    -1,    -1,    -1,    80,
      -1,    -1,    -1,    84,    -1,    -1,    87,    -1,    -1,    90,
      -1,    92,    -1,    -1,    -1,    -1,    -1,    -1,    99,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   110,
      -1,   112,    -1,    -1,   115,    -1,    -1,   118,    -1,    -1,
      -1,    -1,    -1,    -1,   125,   126,   127,   128,   129,    -1,
      -1,   132,   133,   134,   135,   136,    -1,    -1,    -1,   140,
      -1,    -1,   143,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,    -1,    -1,    -1,
      -1,   226,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     235,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   186,    -1,    -1,    -1,   190,
     191,    -1,    -1,    -1,   195,   196,   197,   198,   199,    -1,
      -1,    -1,   203,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   217,   218,    -1,    -1,
      -1,   222,    -1,    -1,    -1,    -1,   227,    -1,     3,     4,
       5,   232,    -1,   234,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,    54,
      55,    56,    -1,    -1,    -1,    -1,    61,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,    73,    74,
      -1,    -1,    -1,    -1,    -1,    80,    -1,    -1,    -1,    84,
      -1,    -1,    87,    -1,    -1,    90,    -1,    92,    -1,    -1,
      -1,    -1,    -1,    -1,    99,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   110,    -1,   112,    -1,    -1,
     115,    -1,    -1,   118,    -1,    -1,    -1,    -1,    -1,    -1,
     125,   126,   127,   128,   129,    -1,    -1,   132,   133,   134,
     135,   136,    -1,    -1,    -1,   140,    -1,    -1,   143,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,    -1,    -1,    -1,    -1,   226,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   235,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   186,    -1,    -1,    -1,   190,   191,    -1,    -1,    -1,
     195,   196,   197,   198,   199,    -1,    -1,    -1,   203,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   217,   218,    -1,    -1,    -1,   222,    -1,    -1,
      -1,    -1,   227,    -1,     3,     4,    -1,   232,    -1,   234,
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
      -1,   110,    -1,   112,    -1,    -1,   115,    -1,    -1,   118,
      -1,    -1,    -1,    -1,    -1,    -1,   125,   126,   127,   128,
     129,    -1,    -1,   132,   133,   134,   135,   136,    -1,    -1,
      -1,   140,    -1,    -1,   143,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,    -1,
      -1,    -1,    -1,   226,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   235,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   186,    -1,    -1,
      -1,   190,   191,    -1,    -1,    -1,   195,   196,   197,   198,
     199,    -1,    -1,    -1,   203,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   217,   218,
      -1,    -1,    -1,   222,    -1,    -1,    -1,    -1,   227,    -1,
       3,     4,    -1,   232,    -1,   234,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      53,    54,    55,    56,    -1,    -1,    -1,    -1,    61,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,
      73,    74,    -1,    -1,    -1,    -1,    -1,    80,    -1,    -1,
      -1,    84,    -1,    -1,    87,    -1,    -1,    90,    -1,    92,
      -1,    -1,    -1,    -1,    -1,    -1,    99,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   110,    -1,   112,
      -1,    -1,   115,    -1,    -1,   118,    -1,    -1,    -1,    -1,
      -1,    -1,   125,   126,   127,   128,   129,    -1,    -1,   132,
     133,   134,   135,   136,    -1,    -1,    -1,   140,    -1,    -1,
     143,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,    -1,    -1,    -1,    -1,   226,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   235,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   186,    -1,    -1,    -1,   190,   191,    -1,
      -1,    -1,   195,   196,   197,   198,   199,    -1,    -1,    -1,
     203,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   217,   218,    -1,    -1,    -1,   222,
      -1,    -1,    -1,    -1,   227,    -1,     3,     4,    -1,   232,
      -1,   234,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    53,    54,    55,    56,
      -1,    -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    72,    73,    74,    -1,    -1,
      -1,    -1,    -1,    80,    -1,    -1,    -1,    84,    -1,    -1,
      87,    -1,    -1,    90,    -1,    92,    -1,    -1,    -1,    -1,
      -1,    -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   110,    -1,   112,    -1,    -1,   115,    -1,
      -1,   118,    -1,    -1,    -1,    -1,    -1,    -1,   125,   126,
     127,   128,   129,    -1,    -1,   132,   133,   134,   135,   136,
      -1,    -1,    -1,   140,    -1,    -1,   143,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,    -1,    -1,    -1,    -1,   226,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   235,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   186,
      -1,    -1,    -1,   190,   191,    -1,    -1,    -1,   195,   196,
     197,   198,   199,    -1,    -1,    -1,   203,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     217,   218,    -1,    -1,    -1,   222,    -1,    -1,    -1,    -1,
     227,    -1,     3,     4,    -1,   232,    -1,   234,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    53,    54,    55,    56,    -1,    -1,    -1,    -1,
      61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    72,    73,    74,    -1,    -1,    -1,    -1,    -1,    80,
      -1,    -1,    -1,    84,    -1,    -1,    87,    -1,    -1,    90,
      -1,    92,    -1,    -1,    -1,    -1,    -1,    -1,    99,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   110,
      -1,   112,    -1,    -1,   115,    -1,    -1,   118,    -1,    -1,
      -1,    -1,    -1,    -1,   125,   126,   127,   128,   129,    -1,
      -1,   132,   133,   134,   135,   136,    -1,    -1,    -1,   140,
      -1,    -1,   143,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,    -1,    -1,    -1,
      -1,   226,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     235,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   186,    -1,    -1,    -1,   190,
     191,    -1,    -1,    -1,   195,   196,   197,   198,   199,    -1,
      -1,    -1,   203,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   217,   218,    -1,    -1,
      -1,   222,    -1,    -1,    -1,    -1,   227,    -1,     3,     4,
      -1,   232,    -1,   234,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,    54,
      55,    56,    -1,    -1,    -1,    -1,    61,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,    73,    74,
      -1,    -1,    -1,    -1,    -1,    80,    -1,    -1,    -1,    84,
      -1,    -1,    87,    -1,    -1,    90,    -1,    92,    -1,    -1,
      -1,    -1,    -1,    -1,    99,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   110,    -1,   112,    -1,    -1,
     115,    -1,    -1,   118,    -1,    -1,    -1,    -1,    -1,    -1,
     125,   126,   127,   128,   129,    -1,    -1,   132,   133,   134,
     135,   136,    -1,    -1,    -1,   140,    -1,    -1,   143,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,    -1,    -1,    -1,    -1,   226,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   235,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   186,    -1,    -1,    -1,   190,   191,    -1,    -1,    -1,
     195,   196,   197,   198,   199,    -1,    -1,    -1,   203,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   217,   218,    -1,    -1,    -1,   222,    -1,    -1,
      -1,    -1,   227,    -1,     3,     4,    -1,   232,    -1,   234,
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
      -1,   110,    -1,   112,    -1,    -1,   115,    -1,    -1,   118,
      -1,    -1,    -1,    -1,    -1,    -1,   125,   126,   127,   128,
     129,    -1,    -1,   132,   133,   134,   135,   136,    -1,    -1,
      -1,   140,    -1,    -1,   143,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,    -1,
      -1,    -1,    -1,   226,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   235,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   186,    -1,    -1,
      -1,   190,   191,    -1,    -1,    -1,   195,   196,   197,   198,
     199,    -1,    -1,    -1,   203,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   217,   218,
      -1,    -1,    -1,   222,    -1,    -1,    -1,    -1,   227,    -1,
       3,     4,    -1,   232,    -1,   234,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      53,    54,    55,    56,    -1,    -1,    -1,    -1,    61,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,
      73,    74,    -1,    -1,    -1,    -1,    -1,    80,    -1,    -1,
      -1,    84,    -1,    -1,    87,    -1,    -1,    90,    -1,    92,
      -1,    -1,    -1,    -1,    -1,    -1,    99,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   110,    -1,   112,
      -1,    -1,   115,    -1,    -1,   118,    -1,    -1,    -1,    -1,
      -1,    -1,   125,   126,   127,   128,   129,    -1,    -1,   132,
     133,   134,   135,   136,    -1,    -1,    -1,   140,    -1,    -1,
     143,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,    -1,    -1,    -1,    -1,   226,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   235,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   186,    -1,    -1,    -1,   190,   191,    -1,
      -1,    -1,   195,   196,   197,   198,   199,    -1,    -1,    -1,
     203,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   217,   218,    -1,    -1,    -1,   222,
      -1,    -1,    -1,    -1,   227,    -1,     3,     4,    -1,   232,
      -1,   234,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    53,    54,    55,    56,
      -1,    -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    72,    73,    74,    -1,    -1,
      -1,    -1,    -1,    80,    -1,    -1,    -1,    84,    -1,    -1,
      87,    -1,    -1,    90,    -1,    92,    -1,    -1,    -1,    -1,
      -1,    -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   110,    -1,   112,    -1,    -1,   115,    -1,
      -1,   118,    -1,    -1,    -1,    -1,    -1,    -1,   125,   126,
     127,   128,   129,    -1,    -1,   132,   133,   134,   135,   136,
      -1,    -1,    -1,   140,    -1,    -1,   143,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,    -1,    -1,    -1,    -1,   226,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   235,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   186,
      -1,    -1,    -1,   190,   191,    -1,    -1,    -1,   195,   196,
     197,   198,   199,    -1,    -1,    -1,   203,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     217,   218,    -1,    -1,    -1,   222,    -1,    -1,    -1,    -1,
     227,    -1,     3,     4,    -1,   232,    -1,   234,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    53,    54,    55,    56,    -1,    -1,    -1,    -1,
      61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    72,    73,    74,    -1,    -1,    -1,    -1,    -1,    80,
      -1,    -1,    -1,    84,    -1,    -1,    87,    -1,    -1,    90,
      -1,    92,    -1,    -1,    -1,    -1,    -1,    -1,    99,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   110,
      -1,   112,    -1,    -1,   115,    -1,    -1,   118,    -1,    -1,
      -1,    -1,    -1,    -1,   125,   126,   127,   128,   129,    -1,
      -1,   132,   133,   134,   135,   136,    -1,    -1,    -1,   140,
      -1,    -1,   143,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,    -1,    -1,    -1,
      -1,   226,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     235,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   186,    -1,    -1,    -1,   190,
     191,    -1,    -1,    -1,   195,   196,   197,   198,   199,    -1,
      -1,    -1,   203,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   217,   218,    -1,    -1,
      -1,   222,    -1,    -1,    -1,    -1,   227,    -1,     3,     4,
      -1,   232,    -1,   234,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,    54,
      55,    56,    -1,    -1,    -1,    -1,    61,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,    73,    74,
      -1,    -1,    -1,    -1,    -1,    80,    -1,    -1,    -1,    84,
      -1,    -1,    87,    -1,    -1,    90,    -1,    92,    -1,    -1,
      -1,    -1,    -1,    -1,    99,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   110,    -1,   112,    -1,    -1,
     115,    -1,    -1,   118,    -1,    -1,    -1,    -1,    -1,    -1,
     125,   126,   127,   128,   129,    -1,    -1,   132,   133,   134,
     135,   136,    -1,    -1,    -1,   140,    -1,    -1,   143,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,    -1,    -1,    -1,    -1,   226,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   235,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   186,    -1,    -1,    -1,   190,   191,    -1,    -1,    -1,
     195,   196,   197,   198,   199,    -1,    -1,    -1,   203,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   217,   218,    -1,    -1,    -1,   222,    -1,    -1,
      -1,    -1,   227,    -1,     3,     4,    -1,   232,    -1,   234,
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
      -1,   110,    -1,   112,    -1,    -1,   115,    -1,    -1,   118,
      -1,    -1,    -1,    -1,    -1,    -1,   125,   126,   127,   128,
     129,    -1,    -1,   132,   133,   134,   135,   136,    -1,    -1,
      -1,   140,    -1,    -1,   143,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,    -1,
      -1,    -1,    -1,   226,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   235,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   186,    -1,    -1,
      -1,   190,   191,    -1,    -1,    -1,   195,   196,   197,   198,
     199,    -1,    -1,    -1,   203,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   217,   218,
      -1,    -1,    -1,   222,    -1,    -1,    -1,    -1,   227,    -1,
       3,     4,    -1,   232,    -1,   234,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      53,    54,    55,    56,    -1,    -1,    -1,    -1,    61,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,
      73,    74,    -1,    -1,    -1,    -1,    -1,    80,    -1,    -1,
      -1,    84,    -1,    -1,    87,    -1,    -1,    90,    -1,    92,
      -1,    -1,    -1,    -1,    -1,    -1,    99,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   110,    -1,   112,
      -1,    -1,   115,    -1,    -1,   118,    -1,    -1,    -1,    -1,
      -1,    -1,   125,   126,   127,   128,   129,    -1,    -1,   132,
     133,   134,   135,   136,    -1,    -1,    -1,   140,    -1,    -1,
     143,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,    -1,    -1,    -1,    -1,   226,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   235,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   186,    -1,    -1,    -1,   190,   191,    -1,
      -1,    -1,   195,   196,   197,   198,   199,    -1,    -1,    -1,
     203,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   217,   218,    -1,    -1,    -1,   222,
      -1,    -1,    -1,    -1,   227,    -1,     3,     4,     5,   232,
      -1,   234,     9,    10,    11,    -1,    -1,    14,    15,    16,
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
      74,    -1,    -1,    -1,    -1,    -1,    80,    81,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,    -1,    -1,    -1,    -1,   226,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   235,    -1,    -1,    -1,   186,
     187,   188,   189,   190,    -1,    -1,    -1,    -1,   195,   196,
     197,   198,   199,   200,    -1,   202,   203,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     217,   218,    -1,    -1,    -1,   222,    -1,    -1,    -1,    -1,
     227,    -1,    -1,    -1,    -1,   232,    -1,   234,    -1,    -1,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,    -1,    -1,    -1,    -1,   226,    -1,
      -1,    -1,   186,   187,   188,   189,   190,   235,    -1,    -1,
      -1,   195,   196,   197,   198,   199,   200,    -1,   202,   203,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   217,   218,    -1,    -1,    -1,   222,    -1,
      -1,    -1,    -1,   227,    -1,     3,     4,     5,   232,    -1,
     234,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    -1,    -1,    -1,    65,    66,    67,
      12,    13,    70,    -1,    72,    73,    74,    -1,    -1,    -1,
      -1,    -1,    80,    81,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,    -1,    -1,
      -1,    -1,   226,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   235,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,    -1,    -1,    -1,    -1,
     226,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   235,
      -1,    -1,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    -1,    -1,    -1,   100,   101,
     102,    -1,   104,    -1,    -1,    -1,    -1,   109,   110,   111,
      -1,    -1,   114,   115,    -1,   117,   118,   119,    -1,    -1,
      -1,   123,    -1,    -1,    -1,    -1,    -1,    -1,   186,   187,
     188,   189,   190,    -1,    -1,   137,    -1,   195,   196,   197,
     198,   199,   200,    -1,   202,   203,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   217,
     218,   163,   164,   165,   222,    -1,    -1,    -1,    -1,   227,
      -1,     3,     4,    -1,   232,    -1,   234,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    53,    54,    55,    56,    -1,    -1,    -1,    -1,    61,
      -1,    -1,    -1,   235,    -1,    -1,    -1,    -1,    -1,    -1,
      72,    73,    74,    -1,    -1,    -1,    -1,    -1,    80,    -1,
      -1,    -1,    84,    -1,    -1,    87,    -1,    -1,    90,    -1,
      92,    -1,    -1,    -1,    -1,    -1,    -1,    99,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   110,    -1,
     112,    -1,    -1,   115,    -1,    -1,   118,    -1,    -1,    -1,
      -1,    -1,    -1,   125,   126,   127,   128,   129,    -1,    -1,
     132,   133,   134,   135,   136,    -1,    -1,    -1,   140,    -1,
      -1,   143,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,    -1,    -1,    -1,    -1,
     226,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   235,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   186,    -1,    -1,    -1,   190,   191,
      -1,    -1,    -1,   195,   196,   197,   198,   199,    -1,    -1,
      -1,   203,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   217,   218,    -1,    -1,    -1,
     222,     3,     4,     5,    -1,   227,    -1,     9,    10,    11,
     232,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      -1,    -1,    -1,    65,    66,    67,    -1,    -1,    70,    -1,
      72,    73,    74,    -1,     3,     4,    -1,    -1,    80,    81,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    -1,    -1,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,    53,    54,    55,    56,   226,    -1,
      -1,    -1,    61,    -1,    -1,    -1,    -1,   235,    -1,    -1,
      -1,    -1,    -1,    72,    73,    74,    -1,    -1,    -1,    -1,
      -1,    80,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,    -1,    -1,    -1,    -1,
     226,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   235,
      -1,    -1,    -1,    -1,   186,   187,   188,   189,   190,    -1,
      -1,    -1,    -1,   195,   196,   197,   198,   199,   200,    -1,
     202,   203,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   217,   218,    -1,    -1,    -1,
     222,    -1,    -1,    -1,    -1,   227,    -1,    -1,    -1,    -1,
     232,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,    -1,    -1,    -1,    -1,   226,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   186,   235,    -1,
      -1,   190,    -1,    -1,    -1,    -1,   195,   196,   197,   198,
     199,    -1,    -1,    -1,   203,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   217,   218,
      -1,    -1,    -1,   222,     3,     4,    -1,    -1,   227,   228,
       9,    10,    11,   232,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    -1,    -1,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,    53,    54,    55,    56,   226,    -1,
      -1,    -1,    61,    -1,    -1,    -1,    -1,   235,    -1,    -1,
      -1,    -1,    -1,    72,    73,    74,     3,     4,    -1,     6,
      -1,    80,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      -1,    -1,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,    53,    54,    55,    56,
     226,    -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,   235,
      -1,    -1,    -1,    -1,    -1,    72,    73,    74,    -1,    -1,
      -1,    -1,    -1,    80,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,    -1,    -1,
      -1,    -1,   226,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   235,    -1,    -1,    -1,    -1,    -1,   186,    -1,    -1,
      -1,   190,    -1,    -1,    -1,    -1,   195,   196,   197,   198,
     199,    -1,    -1,    -1,   203,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   217,   218,
      -1,    -1,    -1,   222,    -1,    -1,    -1,    -1,   227,    -1,
      -1,   230,    -1,   232,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,    -1,    -1,
      -1,    -1,   226,    -1,    -1,    -1,    -1,    -1,    -1,   186,
      -1,   235,    -1,   190,    -1,    -1,    -1,    -1,   195,   196,
     197,   198,   199,    -1,    -1,    -1,   203,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     217,   218,    -1,    -1,    -1,   222,     3,     4,    -1,     6,
     227,    -1,     9,    10,    11,   232,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      -1,    -1,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,    53,    54,    55,    56,
     226,    -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,   235,
      -1,    -1,    -1,     3,     4,    72,    73,    74,    -1,     9,
      10,    11,    -1,    80,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    -1,    -1,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,    53,    54,    55,    56,   226,    -1,    -1,
      -1,    61,    -1,    -1,    -1,    -1,   235,    -1,    -1,    -1,
      -1,    -1,    72,    73,    74,    -1,    -1,    -1,    -1,    -1,
      80,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,    -1,    -1,    -1,    -1,   226,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   234,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   186,
      -1,    -1,    -1,   190,    -1,    -1,    -1,    -1,   195,   196,
     197,   198,   199,    -1,    -1,    -1,   203,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     217,   218,    -1,    -1,    -1,   222,    -1,    -1,    -1,    -1,
     227,    12,    13,    -1,    -1,   232,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
      -1,    -1,    -1,    -1,   226,    -1,   186,    -1,    -1,    -1,
     190,    -1,   234,    -1,    -1,   195,   196,   197,   198,   199,
      -1,    -1,    -1,   203,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   217,   218,    12,
      13,    -1,   222,    -1,    -1,    -1,    -1,   227,    -1,    -1,
      -1,    -1,   232,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    -1,    -1,    -1,   100,
     101,   102,    -1,   104,    -1,    -1,    -1,    -1,   109,   110,
     111,    -1,    -1,   114,   115,    -1,   117,   118,   119,    -1,
      -1,    -1,   123,    -1,    -1,    -1,    12,    13,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   137,    -1,    -1,    -1,
      -1,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    -1,    -1,    -1,   100,   101,   102,
      -1,   104,   163,   164,   165,    -1,   109,   110,   111,    -1,
      -1,   114,   115,    -1,   117,   118,   119,    -1,    -1,    -1,
     123,    -1,    -1,    12,    13,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   137,    -1,    -1,    -1,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    -1,    -1,    -1,   100,   101,   102,    -1,   104,    -1,
     163,   164,   165,   109,   110,   111,    -1,    -1,   114,   115,
      -1,   117,   118,   119,   235,    -1,    -1,   123,    -1,    -1,
      12,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   137,    -1,    -1,    -1,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    -1,    -1,
      -1,   100,   101,   102,    -1,   104,    -1,   163,   164,   165,
     109,   110,   111,    -1,    -1,   114,   115,    -1,   117,   118,
     119,    -1,   235,    -1,   123,    -1,    -1,    12,    13,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   137,    -1,
      -1,    -1,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    -1,    -1,    -1,   100,   101,
     102,    -1,   104,    -1,   163,   164,   165,   109,   110,   111,
      -1,    -1,   114,   115,    -1,   117,   118,   119,    -1,   235,
      -1,   123,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   137,    -1,    -1,    -1,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    -1,    -1,    -1,   100,   101,   102,    -1,   104,
      -1,   163,   164,   165,   109,   110,   111,    -1,    -1,   114,
     115,    -1,   117,   118,   119,    -1,   235,    -1,   123,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     0,     1,    -1,
      -1,     4,   137,    -1,    -1,    -1,    -1,    -1,    -1,    12,
      13,    -1,    -1,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,    -1,   163,   164,
     165,   226,    -1,   228,    -1,   230,    -1,    -1,   233,    42,
      43,    -1,    -1,   235,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,    -1,    62,
      63,    64,   226,    -1,    -1,    68,    69,    -1,    71,    -1,
     234,    -1,    75,    76,    -1,    78,    79,    -1,    -1,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    -1,    -1,    99,   100,   101,   102,
     235,   104,   105,   106,   107,   108,   109,   110,   111,   112,
      -1,   114,   115,   116,   117,   118,   119,   120,    -1,   122,
     123,   124,   125,   126,   127,   128,   129,   130,    -1,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,    -1,    -1,    -1,   149,   150,   151,     4,
      -1,    -1,    -1,    -1,   157,    -1,    -1,    12,    13,   162,
     163,   164,   165,    -1,    -1,   168,    -1,   170,    -1,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,    -1,    -1,    -1,    -1,    42,    43,   192,
     193,   194,    -1,    -1,    -1,    -1,    -1,    -1,   201,    -1,
     203,    -1,    -1,    -1,    -1,    -1,    -1,    62,    63,    64,
      -1,    -1,    -1,    68,    69,    -1,    71,    -1,    -1,    -1,
      75,    76,    -1,    78,    79,    -1,    -1,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    -1,    -1,    99,   100,   101,   102,    -1,   104,
     105,   106,   107,   108,   109,   110,   111,   112,    -1,   114,
     115,   116,   117,   118,   119,   120,    -1,   122,   123,   124,
     125,   126,   127,   128,   129,   130,    -1,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,    12,    13,    -1,   149,   150,   151,    -1,    -1,    -1,
      -1,    -1,   157,    -1,    -1,    -1,    -1,   162,   163,   164,
     165,    -1,    -1,   168,    -1,   170,    -1,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,    -1,    -1,    -1,    -1,    -1,    -1,   192,   193,   194,
      -1,    -1,    -1,    -1,    -1,    -1,   201,    -1,   203,    12,
      13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    -1,    -1,    -1,   100,
     101,   102,    -1,   104,    -1,    -1,    -1,    -1,   109,   110,
     111,    -1,    -1,   114,   115,    -1,   117,   118,   119,    -1,
      -1,    -1,   123,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   137,    -1,    -1,    -1,
     141,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    -1,    -1,    -1,   100,   101,   102,
      -1,   104,   163,   164,   165,    -1,   109,   110,   111,    -1,
      -1,   114,   115,    -1,   117,   118,   119,    -1,    -1,    -1,
     123,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   137,    -1,    -1,    -1,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,    -1,    -1,    -1,    -1,   226,    -1,   228,    -1,
     163,   164,   165,   233,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,    -1,    -1,
      -1,    -1,   226,    -1,    -1,    -1,    -1,    -1,    -1,   233,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,    -1,    -1,    -1,    -1,   226,    -1,
      -1,    -1,    -1,    -1,    -1,   233,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
      -1,    -1,    -1,    -1,   226,    -1,    -1,    -1,    -1,    -1,
      -1,   233,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,    -1,    -1,    -1,    -1,
     226,    -1,    -1,    -1,    -1,    -1,    -1,   233,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,    -1,    -1,    -1,    -1,   226,    -1,    -1,    -1,
      -1,    -1,    -1,   233,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,    -1,    -1,
      -1,    -1,   226,    -1,    -1,    -1,    -1,    -1,    -1,   233,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,    -1,    -1,    -1,    -1,   226,    -1,
      -1,    -1,    -1,    -1,    -1,   233,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
      -1,    -1,    -1,    -1,   226,    -1,    -1,    -1,    -1,    -1,
      -1,   233,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,    -1,    -1,    -1,    -1,
     226,    -1,    -1,    -1,    -1,    -1,    -1,   233,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,    -1,    -1,    -1,    -1,   226,    -1,    -1,    -1,
      -1,    -1,    -1,   233,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,    -1,    -1,
      -1,    -1,   226,    -1,    -1,    -1,    -1,    -1,    -1,   233,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,    -1,    -1,    -1,    -1,   226,    -1,
      -1,    -1,    -1,    -1,    -1,   233,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
      -1,    -1,    -1,    -1,   226,    -1,    -1,    -1,    -1,    -1,
      -1,   233,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,    -1,    -1,    -1,    -1,
     226,    -1,    -1,    -1,    -1,    -1,    -1,   233,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,    -1,    -1,    -1,    -1,   226,    -1,    -1,    -1,
      -1,    -1,    -1,   233,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,    -1,    -1,
      -1,    -1,   226,    -1,    -1,    -1,    -1,    -1,    -1,   233,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,    -1,    -1,    -1,    -1,   226,    -1,
      -1,    -1,    -1,    -1,    -1,   233,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
      -1,    -1,    -1,    -1,   226,    -1,    -1,    -1,    -1,    -1,
      -1,   233,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,    -1,    -1,    -1,    -1,
     226,    -1,    -1,    -1,    -1,    -1,    -1,   233,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,    -1,    -1,    -1,    -1,   226,    -1,    -1,    -1,
      -1,    -1,    -1,   233,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,    -1,    -1,
      -1,    -1,   226,    -1,    -1,    -1,    -1,    -1,    -1,   233,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,    -1,    -1,    -1,    -1,   226,    -1,
      -1,    -1,    -1,    -1,    -1,   233,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
      -1,    -1,    -1,    -1,   226,    -1,    -1,    -1,    -1,    -1,
      -1,   233,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,    -1,    -1,    -1,    -1,
     226,    -1,    -1,    -1,    -1,    -1,    -1,   233,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,    -1,    -1,    -1,    -1,   226,    -1,    -1,    -1,
      -1,    -1,    -1,   233,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,    -1,    -1,
      -1,    -1,   226,    -1,    -1,    -1,    -1,    -1,    -1,   233,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,    -1,    -1,    -1,    -1,   226,    -1,
      -1,    -1,    -1,    -1,    -1,   233,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
      -1,    -1,    -1,    -1,   226,    -1,    -1,    -1,    -1,    -1,
      -1,   233,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,    -1,    -1,    -1,    -1,
     226,    -1,    -1,    -1,    -1,    -1,    -1,   233,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,    -1,    -1,    -1,    -1,   226,    -1,    -1,    -1,
      -1,    -1,    -1,   233,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,    -1,    -1,
      -1,    -1,   226,    -1,    -1,    -1,    -1,    -1,    -1,   233,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,    -1,    -1,    -1,    -1,   226,    -1,
      -1,    -1,    -1,    -1,    -1,   233,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
      -1,    -1,    -1,    -1,   226,    -1,    -1,    -1,    -1,    -1,
      -1,   233,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,    -1,    -1,    -1,    -1,
     226,    -1,    -1,    -1,    -1,    -1,    -1,   233,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,    -1,    -1,    -1,    -1,   226,    -1,    -1,    -1,
      -1,    -1,    -1,   233,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,    -1,    -1,
      -1,    -1,   226,    -1,    -1,    -1,    -1,    -1,    -1,   233,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,    -1,    -1,    -1,    -1,   226,    -1,
      -1,    -1,    -1,    -1,    -1,   233,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
      -1,    -1,    -1,    -1,   226,    -1,    -1,    -1,    -1,    -1,
      -1,   233,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,    -1,    -1,    -1,    -1,
     226,    -1,    -1,    -1,    -1,    -1,    -1,   233,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,    -1,    -1,    -1,    -1,   226,    -1,    -1,    -1,
      -1,    -1,    -1,   233,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,    -1,    -1,
      -1,    -1,   226,    -1,    -1,    -1,    -1,    -1,    -1,   233,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,    -1,    -1,    -1,    -1,   226,    -1,
      -1,    -1,    -1,    -1,    -1,   233,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
      -1,    -1,    -1,    -1,   226,    -1,    -1,    -1,    -1,    -1,
      -1,   233,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,    -1,    -1,    -1,    -1,
     226,    -1,    -1,    -1,    -1,    -1,    -1,   233,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,    -1,    -1,    -1,    -1,   226,    -1,    -1,    -1,
      -1,    -1,    -1,   233,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,    -1,    -1,
      -1,    -1,   226,    -1,    -1,    -1,    -1,    -1,    -1,   233,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,    -1,    -1,    -1,    -1,   226,    -1,
      -1,    -1,    -1,    -1,    -1,   233,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
      -1,    -1,    -1,    -1,   226,    -1,    -1,    -1,    -1,    -1,
      -1,   233,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,    -1,    -1,    -1,    -1,
     226,    -1,    -1,    -1,    -1,    -1,    -1,   233,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,    -1,    -1,    -1,    -1,   226,    -1,    -1,    -1,
      -1,    -1,    -1,   233,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,    -1,    -1,
      -1,    -1,   226,    -1,    -1,    -1,    -1,    -1,    -1,   233,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,    -1,    -1,    -1,    -1,   226,    -1,
      -1,    -1,    -1,    -1,    -1,   233,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
      -1,    -1,    -1,    -1,   226,    -1,    -1,    -1,    -1,    -1,
      -1,   233,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,    -1,    -1,    -1,    -1,
     226,    -1,    -1,    -1,    -1,    -1,    -1,   233,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,    -1,    -1,    -1,    -1,   226,    -1,    -1,    -1,
      -1,    -1,    -1,   233,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,    -1,    -1,
      -1,    -1,   226,    -1,   228,    -1,   230,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,    -1,    -1,    -1,    -1,   226,    -1,    -1,    -1,   230,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,    -1,    -1,    -1,    -1,   226,    -1,
      -1,    -1,   230,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,    -1,    -1,    -1,
      -1,   226,    -1,    -1,    -1,   230,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
      -1,    -1,    -1,    -1,   226,    -1,    -1,    -1,   230,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,    -1,    -1,    -1,    -1,   226,    -1,    -1,
      -1,   230,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,    -1,    -1,    -1,    -1,
     226,    -1,    -1,    -1,   230,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,    -1,
      -1,    -1,    -1,   226,    -1,    -1,    -1,   230,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,    -1,    -1,    -1,    -1,   226,    -1,    -1,    -1,
     230,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,    -1,    -1,    -1,    -1,   226,
      -1,    -1,    -1,   230,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,    -1,    -1,
      -1,    -1,   226,    -1,    -1,    -1,   230,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,    -1,    -1,    -1,    -1,   226,    -1,    -1,    -1,   230,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,    -1,    -1,    -1,    -1,   226,    -1,
      -1,    -1,   230,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,    -1,    -1,    -1,
      -1,   226,    -1,    -1,    -1,   230,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
      -1,    -1,    -1,    -1,   226,    -1,    -1,    -1,   230,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,    -1,    -1,    -1,    -1,   226,    -1,    -1,
      -1,   230,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,    -1,    -1,    -1,    -1,
     226,    -1,    -1,    -1,   230,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,    -1,
      -1,    -1,    -1,   226,    -1,    -1,    -1,   230,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,    -1,    -1,    -1,    -1,   226,    -1,   228,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,    -1,    -1,    -1,    -1,   226,    -1,   228,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,    -1,    -1,    -1,    -1,   226,    -1,
     228,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,    -1,    -1,    -1,    -1,   226,
      -1,   228,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,    -1,    -1,    -1,    -1,
     226,    -1,   228,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,    -1,    -1,    -1,
      -1,   226,    -1,   228,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,    -1,    -1,
      -1,    -1,   226,    -1,   228,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,    -1,
      -1,    -1,    -1,   226,    -1,   228,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
      -1,    -1,    -1,    -1,   226,    -1,   228,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,    -1,    -1,    -1,    -1,   226,    -1,   228,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,    -1,    -1,    -1,    -1,   226,    -1,   228,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,    -1,    -1,    -1,    -1,   226,    -1,   228,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,    -1,    -1,    -1,    -1,   226,    -1,
     228,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,    -1,    -1,    -1,    -1,   226,
      -1,   228,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,    -1,    -1,    -1,    -1,
     226,    -1,   228,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,    -1,    -1,    -1,
      -1,   226,    -1,   228,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,    -1,    -1,
      -1,    -1,   226,    -1,   228,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,    -1,
      -1,    -1,    -1,   226,    -1,   228,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
      -1,    -1,    -1,    -1,   226,    -1,   228,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,    -1,    -1,    -1,    -1,   226,    -1,   228,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,    -1,    -1,    -1,    -1,   226,    -1,   228,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,    -1,    -1,    -1,    -1,   226,    -1,   228,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,    -1,    -1,    -1,    -1,   226,    -1,
     228,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,    -1,    -1,    -1,    -1,   226,
      -1,   228,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,    -1,    -1,    -1,    -1,
     226,    -1,   228,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,    -1,    -1,    -1,
      -1,   226,    -1,   228,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,    -1,    -1,
      -1,    -1,   226,    -1,   228,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,    -1,
      -1,    -1,    -1,   226,    -1,   228,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
      -1,    -1,    -1,    -1,   226,    -1,   228,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,    -1,    -1,    -1,    -1,   226,    -1,   228,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,    -1,    -1,    -1,    -1,   226,    -1,   228,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,    -1,    -1,    -1,    -1,   226,    -1,   228,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,    -1,    -1,    -1,    -1,   226,    -1,
     228,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,    -1,    -1,    -1,    -1,   226,
      -1,   228,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,    -1,    -1,    -1,    -1,
     226,    -1,   228,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,    -1,    -1,    -1,
      -1,   226,    -1,   228,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,    -1,    -1,
      -1,    -1,   226,    -1,   228,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,    -1,
      -1,    -1,    -1,   226,    -1,   228,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
      -1,    -1,    -1,    -1,   226,    -1,   228,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,    -1,    -1,    -1,    -1,   226,    -1,   228,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,    -1,    -1,    -1,    -1,   226,    -1,   228,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,    -1,    -1,    -1,    -1,   226,    -1,   228,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,    -1,    -1,    -1,    -1,   226,    -1,
     228,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,    -1,    -1,    -1,    -1,   226,
      -1,   228,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,    -1,    -1,    -1,    -1,
     226,    -1,   228,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,    -1,    -1,    -1,
      -1,   226,    -1,   228,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,    -1,    -1,
      -1,    -1,   226,    -1,   228,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,    -1,
      -1,    -1,    -1,   226,    -1,   228,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
      -1,    -1,    -1,    -1,   226,    -1,   228,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,    -1,    -1,    -1,    -1,   226,    -1,   228,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,    -1,    -1,    -1,    -1,   226,    -1,   228,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,    -1,    -1,    -1,    -1,   226,    -1,   228,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,    -1,    -1,    -1,    -1,   226,    -1,
     228,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,    -1,    -1,    -1,    -1,   226,
      -1,   228,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,    -1,    -1,    -1,    -1,
     226,    -1,   228,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,    -1,    -1,    -1,
      -1,   226,    -1,   228,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,    -1,    -1,
      -1,    -1,   226,    -1,   228,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,    -1,
      -1,    -1,    -1,   226,    -1,   228,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
      -1,    -1,    -1,    -1,   226,    -1,   228,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,    -1,    -1,    -1,    -1,   226,    -1,   228,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,    -1,    -1,    -1,    -1,   226
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,   238,   239,     6,     0,     4,    12,    13,    42,
      43,    62,    63,    64,    68,    69,    71,    75,    76,    78,
      79,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    99,   100,   101,   102,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   114,
     115,   116,   117,   118,   119,   120,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   149,
     150,   151,   157,   162,   163,   164,   165,   168,   170,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   192,   193,   194,   201,   203,   240,   242,
     243,   263,   282,   283,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   310,   312,   313,   319,   320,   321,   322,
     340,   341,     3,     4,     5,     9,    10,    11,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    65,
      66,    67,    70,    72,    73,    74,    80,    81,   179,   186,
     187,   188,   189,   190,   195,   196,   197,   198,   199,   200,
     202,   217,   218,   222,   227,   229,   231,   232,   234,   236,
     261,   323,   324,   336,   337,   340,   341,    13,    90,   227,
     227,     6,   234,     6,     6,     6,     6,   227,     6,     6,
     229,   229,   227,   229,   261,   261,   227,   234,   227,   227,
       4,   227,   234,   227,   227,     4,   227,   234,   227,   227,
     227,   227,   227,   227,   227,   227,   227,   103,    90,    90,
       6,   234,    84,    87,    90,   227,     4,    37,    38,    39,
      40,    41,    84,    87,    90,    92,   110,   115,   118,   191,
     218,   227,   234,   283,   294,   310,   312,   323,   329,   331,
     340,   341,   227,   234,    90,    90,   110,    87,    90,    92,
      92,    84,    87,    90,    92,    87,    90,    92,    87,    90,
     227,    87,   168,   184,   185,   234,   217,   218,   227,   234,
     326,   327,   326,   234,    84,    87,    90,   234,   326,     4,
      84,    88,    94,    95,    97,    98,   114,   227,    90,    92,
      90,    87,     4,   179,   234,   340,   341,     4,     6,    84,
      87,    90,    87,    90,     4,     4,     4,     5,   227,   329,
     330,     4,   227,   227,   227,     4,   234,   333,   341,     4,
     227,   227,   227,     6,     6,   229,     4,   337,   341,   227,
       4,   337,     5,   234,     5,   234,     4,   323,   340,   229,
     227,   234,     6,   227,   234,   227,   229,   236,   261,     7,
     204,   205,   206,   207,   224,   225,   259,   260,     4,   227,
     229,   231,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   227,   227,   227,
     261,   261,   261,   261,   227,   261,   261,   261,   261,   261,
     261,   227,   261,   261,   261,     7,   227,   227,   227,   261,
     261,   227,   227,   229,   323,   323,   323,   228,   323,   230,
     323,     4,   168,   169,   341,     4,   283,   284,   285,   234,
     234,     6,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   226,   234,     6,   227,
     229,   260,     6,   323,     4,   336,   337,   340,   341,   336,
     323,   336,   339,   265,   270,   337,   341,   323,   218,   323,
     331,   332,   323,   323,   227,   323,   332,   323,   323,   227,
     323,   332,   323,   323,   323,   323,   323,   323,   336,   323,
     323,   329,   227,   234,   332,   330,   330,   330,   336,   227,
     229,   231,   261,   227,   229,   261,   261,   261,   261,     5,
     171,   234,     5,   171,     5,   171,     5,   171,   110,    84,
      87,    90,    92,   261,   234,   323,   331,   323,   235,   332,
       8,   219,   227,   229,   261,   323,   332,   227,   227,   227,
     329,   330,   330,   330,   227,   227,   227,   227,   227,   227,
     329,   227,   329,   227,   329,   234,   234,   323,     4,   329,
     333,   234,   234,   326,   326,   326,   323,   323,   217,   218,
     234,   234,   326,   234,   234,   234,   217,   218,   227,   285,
     326,   234,   227,   234,   227,   227,   227,   227,   227,   227,
     227,   323,   330,   330,   329,   227,     4,   229,   229,   285,
       6,     6,   234,   234,   234,   330,   330,   229,   229,   229,
     323,     6,     6,   323,   323,   323,   231,   323,   234,   171,
     323,   323,   323,   323,     6,     6,   234,     6,   285,     6,
     285,   227,   229,   234,   227,   229,   336,   323,   285,   329,
     329,   228,   323,   230,   323,   234,   234,   337,   329,     6,
     229,   323,   323,     4,   323,   323,   323,   323,   323,   323,
     323,   323,   323,   323,   323,   323,   323,   323,   323,   323,
     323,   323,   323,   323,   323,   323,   339,   336,   339,   336,
     336,   336,   336,   336,   336,   336,   329,   336,   336,   323,
     336,   336,   336,   339,   336,   323,   337,   323,   336,   336,
     336,   336,   336,   341,   337,   341,     7,   207,   259,   228,
       7,   207,   259,   230,     7,   259,   260,   231,     7,   261,
     235,    84,    87,    90,    92,   110,   115,   282,   323,   332,
     323,   323,   323,   323,   323,   323,   323,   323,   323,   323,
     323,   323,   323,   323,   323,   244,   323,   323,     6,   227,
     229,   231,   228,   233,   227,   229,   228,   233,   233,   228,
     233,   230,   233,   264,   230,   264,   233,   233,   228,   219,
     233,   235,   228,   228,   323,   228,   235,   228,   228,   323,
     228,   235,   228,   228,   228,   228,   228,   228,   228,   228,
     228,     7,   323,   323,   235,     6,     6,     6,   228,   323,
     323,     4,   228,   230,   234,   262,   234,   323,   331,   234,
     331,   341,   323,   323,   336,   323,    62,   323,    62,    62,
      62,     5,   234,     5,   234,     5,   234,     5,   234,   331,
     332,   228,   235,   323,   234,   323,   331,   323,   323,   234,
     262,   228,   235,   323,   323,   323,     7,     7,   316,   316,
     323,   276,   323,   337,   277,   323,   337,   278,   323,   337,
     279,   323,   337,   323,     6,   323,     6,   323,     6,   332,
     332,   234,   228,     6,   234,   285,   285,   233,   233,   233,
     326,   326,   284,   284,   233,   323,   323,   323,   323,   235,
     298,   233,   285,   323,   323,   323,   323,   323,   323,   323,
     323,   323,   228,     7,   317,     6,     7,   323,     6,   323,
     323,   235,   332,   332,   332,     6,     6,   323,   323,   323,
     228,   228,   228,   228,   168,   233,   285,   234,     8,   228,
     228,   230,   332,   235,   235,   285,   230,   228,   141,   311,
     228,   233,   235,     7,   207,   259,   228,     7,   207,   259,
     230,   323,   332,     6,     6,   323,   228,   230,   260,   262,
     262,   262,   262,   262,   262,   262,   262,   262,   262,   262,
     233,   262,   262,   262,   262,   262,   262,   262,   233,   233,
     233,   262,   233,   262,   262,   228,   228,   233,   262,   262,
     233,   262,   233,   233,   233,   233,   262,   262,   262,   228,
     262,   325,   338,     6,   233,   233,   228,   233,   262,   233,
     262,   228,   228,   230,    44,    44,   329,     7,   259,   260,
      44,    44,   329,   231,   259,   260,   337,   323,     6,     4,
       4,   234,   334,   262,   234,   234,   234,   234,   227,   110,
     235,   235,     8,     4,   158,   159,   160,   161,   235,   247,
     251,   254,   256,   257,   228,   230,   323,   323,     4,     6,
     214,   241,   332,   323,   323,     6,   332,   323,     6,   336,
       6,   341,     6,   336,   323,   337,     7,   323,   331,   171,
       7,     7,   228,     7,   171,     7,     7,   228,     7,   171,
       7,     7,     7,     7,     7,     7,     7,     7,   323,   228,
     235,   234,     6,   228,   230,   332,   332,   228,   332,   230,
     230,   233,   233,   262,   233,   234,   235,   234,   234,   234,
     332,   332,   332,   332,   262,   235,     7,     8,   332,   228,
     230,   332,     7,   234,   228,   228,   228,   323,   329,     4,
     315,     6,   228,   228,   233,   228,   233,   228,   233,   228,
     233,   228,   228,   228,   235,   235,   332,   231,   285,   235,
     235,   326,   323,   323,   235,   235,   323,   326,   233,   233,
     233,   121,   121,   138,   146,   147,   148,   152,   153,   154,
     155,   308,   309,   326,   235,   295,   228,   235,   228,   228,
     228,   228,   228,   228,   228,     7,   323,     6,   323,   228,
     230,   230,   235,   235,   235,   230,   230,   233,     7,     7,
       7,   231,   323,   235,   323,   323,     7,   231,   235,   235,
       7,     6,   323,   235,   234,   329,     6,    44,    44,   329,
     259,   260,    44,    44,   329,   259,   260,   235,   235,   230,
     260,   231,   260,   336,   323,   323,   323,   323,   332,   336,
     323,   329,   336,   336,   336,   272,   274,   323,   336,   336,
     323,   261,   261,     6,   323,     6,   261,   261,     6,     4,
     168,   169,   323,     6,     6,     6,     7,   229,   333,   335,
       6,   332,   332,   332,   332,   323,   227,   262,   323,   248,
     227,   227,   234,   258,     6,   260,   260,   228,   230,   214,
     336,   228,   228,   230,   228,   233,     7,   227,   229,   262,
     262,   326,    90,    92,   329,   329,     7,   329,    90,    92,
     329,   329,     7,   329,    92,   329,   329,   329,   329,   329,
     329,   329,   329,     6,     7,     7,   332,   231,   235,   235,
     235,   323,   323,   323,   323,   323,   323,   323,   235,   235,
     235,   235,   329,   323,   235,   235,   329,   332,     7,     7,
       7,   121,   314,     6,     7,   259,   323,   259,   323,   259,
     323,   259,   323,     7,     7,     7,     7,     7,   235,     4,
     235,   233,   233,   233,   235,   235,   326,   326,   326,    87,
       4,     6,   323,   234,     6,   227,     6,   156,     6,   156,
       6,   156,     6,   156,   235,   309,   233,   308,     7,     6,
       7,     7,     7,     7,     7,     7,     7,   329,     6,   234,
       6,     6,     6,    90,     7,     6,     6,   323,   329,   329,
     329,     4,   233,     8,     8,   228,     4,     4,   233,   234,
       6,   234,   329,   235,   261,   261,     6,   323,     6,   261,
     261,     6,   323,     6,   262,     6,     4,     6,   262,   262,
     262,   262,   262,   233,   233,   262,   228,   262,   262,   233,
     233,   262,   273,   233,   262,   275,   228,   228,   262,   262,
     262,   339,   339,     6,   262,   339,   339,     7,   259,   260,
     231,     7,     6,   333,   323,   233,   235,   235,   235,   235,
     235,   228,   323,   259,   227,   323,   323,   328,   329,   234,
     231,     6,     6,   241,     6,   323,   234,   323,   337,   228,
     230,     6,     6,     6,   234,   234,   114,   281,   281,   329,
       6,   234,   234,     6,     6,   329,   171,   280,   234,     6,
       6,     6,     6,     6,     6,     6,     6,     5,   329,   235,
       4,   262,   228,   230,   233,   233,   233,   233,   233,   233,
     233,     6,   262,     6,   235,   329,   329,   329,     4,     6,
     329,   329,   329,   329,   329,   329,   329,   329,   234,   234,
       7,     6,     7,   323,   323,   323,   234,   234,   233,   235,
     233,   235,   233,   235,   234,   229,     6,   323,   329,   323,
       6,     6,     6,     6,   323,   326,   235,     5,   329,   234,
     234,   234,   234,   234,   234,   234,   329,     6,   332,   234,
     323,   230,     6,     6,   167,   323,   323,   323,     6,     6,
       7,   337,   285,   285,   233,     6,   262,   339,   339,     6,
     262,   339,   339,     6,   259,   260,   336,   323,   336,     4,
       4,   183,     6,   262,   262,     6,   262,   262,   337,   323,
       6,     4,   334,     6,   230,   333,     6,     6,     6,     6,
     228,   329,   245,   323,   233,   233,   233,   235,   246,   323,
       4,   336,   233,   329,   337,     7,     7,   323,   323,   326,
       6,     6,     6,   323,   323,     6,    88,     6,   323,     5,
       6,   234,   323,   323,   323,   323,   323,   323,   323,   234,
       6,   280,     6,   323,     6,     6,     6,     6,     6,     6,
       4,     6,     6,   332,   332,   323,   323,   337,   235,   228,
     233,   235,   284,   284,   326,     6,   299,   326,     6,   300,
     326,     6,   301,   329,   323,   235,   233,   228,   235,   233,
       6,     6,   328,   326,   326,   326,   326,   326,   218,   326,
       6,   235,   323,     6,     6,   329,   233,   235,     8,   235,
     228,   234,   323,   337,   233,   311,   311,   329,     6,   262,
     262,     6,   262,   262,   329,   228,   262,   262,   234,   329,
     337,   234,   323,   337,   337,     6,     6,     6,     6,     6,
       6,     7,     6,   231,     6,   228,   233,   323,   323,   329,
     234,   233,   235,     6,   323,   266,   269,   234,   234,   235,
     235,   235,   235,   234,   235,     5,   328,   262,   262,   233,
     233,   233,   233,   233,   323,     6,   234,   235,   235,   234,
       6,     6,   234,   323,   235,   235,   233,   234,   233,   234,
     233,   234,   235,   230,     6,   329,     7,   234,   323,   235,
     233,   233,   233,   233,   233,   233,     6,   235,   166,   323,
     323,   332,     6,     6,   337,   235,   235,   235,     6,     6,
       6,     6,     6,   271,   323,   331,   339,   333,   169,   249,
     323,   233,   233,   328,   323,     6,   233,   272,   274,   329,
     329,     6,     6,     6,     6,   323,     6,     6,   235,   323,
     323,   323,   323,   323,   235,   328,   125,   126,   131,   318,
     125,   126,   318,   332,   284,   233,   235,   323,   326,   308,
     323,   326,   308,   323,   326,   308,     6,   233,   235,   329,
     285,   235,     6,   332,   326,   326,   326,   326,   326,   323,
     235,   235,   235,   228,   234,     6,   233,   235,     7,     7,
     235,     6,   234,   323,   323,   235,   323,   235,   235,   268,
     267,   235,   234,   233,   233,   233,   233,   233,   235,   234,
     326,   329,     6,   234,   326,     6,   235,   235,   323,   235,
     233,   235,   235,   233,   235,   235,   233,   235,   329,     6,
     121,   235,   296,   234,   235,   233,   233,   233,   233,   233,
       6,     6,     6,   285,   323,   337,   341,   246,   228,   233,
       6,   234,   233,   272,   272,   323,   323,   323,   323,   323,
     323,     6,   326,     6,   326,     6,     6,   235,     6,   302,
     323,     6,     6,   303,   323,     6,     6,   304,   323,     6,
     235,   323,   308,   285,     6,   332,   332,   332,   332,   326,
     332,   311,     7,   227,   235,   252,   323,   328,   323,   235,
     235,   233,   233,   233,   233,   233,   233,   233,   233,   234,
     235,   234,   235,   234,   235,     6,     6,   235,   235,   297,
     235,   235,   235,   235,   233,   235,   235,   337,   228,     6,
     234,   228,   235,   235,   323,   323,   323,   323,   323,   323,
     326,   326,   308,     6,   305,   308,     6,   306,   308,     6,
     307,   308,     6,     6,     6,     6,   332,     6,     6,   250,
     336,   255,   234,     6,   235,   262,   233,   233,   233,   233,
     233,   233,   235,   234,   235,   234,   235,   234,   235,   235,
     233,   235,   234,   328,     6,   323,   323,   323,   323,   323,
     323,     6,   308,     6,   308,     6,   308,     6,   336,     6,
     253,   336,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   233,   235,     6,     6,     6,     6,     6,     6,
     336,     6
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
#line 211 "Gmsh.y"
    { yyerrok; return 1; ;}
    break;

  case 6:
#line 222 "Gmsh.y"
    { return 1; ;}
    break;

  case 7:
#line 223 "Gmsh.y"
    { return 1; ;}
    break;

  case 8:
#line 224 "Gmsh.y"
    { return 1; ;}
    break;

  case 9:
#line 225 "Gmsh.y"
    { return 1; ;}
    break;

  case 10:
#line 226 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 11:
#line 227 "Gmsh.y"
    { return 1; ;}
    break;

  case 12:
#line 228 "Gmsh.y"
    { return 1; ;}
    break;

  case 13:
#line 229 "Gmsh.y"
    { return 1; ;}
    break;

  case 14:
#line 230 "Gmsh.y"
    { return 1; ;}
    break;

  case 15:
#line 231 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 16:
#line 232 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 17:
#line 233 "Gmsh.y"
    { return 1; ;}
    break;

  case 18:
#line 234 "Gmsh.y"
    { return 1; ;}
    break;

  case 19:
#line 235 "Gmsh.y"
    { return 1; ;}
    break;

  case 20:
#line 236 "Gmsh.y"
    { return 1; ;}
    break;

  case 21:
#line 237 "Gmsh.y"
    { return 1; ;}
    break;

  case 22:
#line 238 "Gmsh.y"
    { return 1; ;}
    break;

  case 23:
#line 239 "Gmsh.y"
    { return 1; ;}
    break;

  case 24:
#line 240 "Gmsh.y"
    { return 1; ;}
    break;

  case 25:
#line 245 "Gmsh.y"
    {
      (yyval.c) = (char*)"w";
    ;}
    break;

  case 26:
#line 249 "Gmsh.y"
    {
      (yyval.c) = (char*)"a";
    ;}
    break;

  case 27:
#line 256 "Gmsh.y"
    {
      Msg::Direct((yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 28:
#line 261 "Gmsh.y"
    {
      Msg::Error((yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 29:
#line 266 "Gmsh.y"
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
#line 280 "Gmsh.y"
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
#line 293 "Gmsh.y"
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
#line 306 "Gmsh.y"
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
#line 334 "Gmsh.y"
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
#line 348 "Gmsh.y"
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
#line 361 "Gmsh.y"
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
#line 374 "Gmsh.y"
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
#line 392 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData = new PViewDataList();
#endif
    ;}
    break;

  case 43:
#line 406 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(1) - (1)].d)); ;}
    break;

  case 44:
#line 408 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(3) - (3)].d)); ;}
    break;

  case 45:
#line 413 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(1) - (1)].d)); ;}
    break;

  case 46:
#line 415 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(3) - (3)].d)); ;}
    break;

  case 47:
#line 420 "Gmsh.y"
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
#line 524 "Gmsh.y"
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
#line 534 "Gmsh.y"
    {
#if defined(HAVE_POST)
      if(ViewValueList) (*ViewNumList)++;
#endif
    ;}
    break;

  case 50:
#line 543 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[(1) - (1)].c)[i]);
#endif
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 51:
#line 550 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[(3) - (3)].c)[i]);
#endif
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 52:
#line 560 "Gmsh.y"
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
#line 569 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->NbT2++;
#endif
    ;}
    break;

  case 54:
#line 578 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[(1) - (1)].c)[i]);
#endif
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 55:
#line 585 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[(3) - (3)].c)[i]);
#endif
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 56:
#line 595 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->T3D.push_back((yyvsp[(3) - (10)].d)); ViewData->T3D.push_back((yyvsp[(5) - (10)].d));
      ViewData->T3D.push_back((yyvsp[(7) - (10)].d)); ViewData->T3D.push_back((yyvsp[(9) - (10)].d));
      ViewData->T3D.push_back(ViewData->T3C.size());
#endif
    ;}
    break;

  case 57:
#line 603 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->NbT3++;
#endif
    ;}
    break;

  case 58:
#line 613 "Gmsh.y"
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
#line 632 "Gmsh.y"
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
#line 651 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewValueList = &ViewData->Time;
#endif
    ;}
    break;

  case 61:
#line 657 "Gmsh.y"
    {
    ;}
    break;

  case 62:
#line 664 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 63:
#line 665 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 64:
#line 666 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 65:
#line 667 "Gmsh.y"
    { (yyval.i) = 3; ;}
    break;

  case 66:
#line 668 "Gmsh.y"
    { (yyval.i) = 4; ;}
    break;

  case 67:
#line 672 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 68:
#line 673 "Gmsh.y"
    { (yyval.i) = -1; ;}
    break;

  case 69:
#line 679 "Gmsh.y"
    { (yyval.c) = (char*)"("; ;}
    break;

  case 70:
#line 679 "Gmsh.y"
    { (yyval.c) = (char*)"["; ;}
    break;

  case 71:
#line 680 "Gmsh.y"
    { (yyval.c) = (char*)")"; ;}
    break;

  case 72:
#line 680 "Gmsh.y"
    { (yyval.c) = (char*)"]"; ;}
    break;

  case 75:
#line 689 "Gmsh.y"
    {
      Msg::SetOnelabNumber((yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].d));
      Free((yyvsp[(3) - (7)].c));
    ;}
    break;

  case 76:
#line 694 "Gmsh.y"
    {
      Msg::SetOnelabString((yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].c));
      Free((yyvsp[(3) - (7)].c));
      Free((yyvsp[(5) - (7)].c));
    ;}
    break;

  case 77:
#line 700 "Gmsh.y"
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
#line 762 "Gmsh.y"
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
#line 779 "Gmsh.y"
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
#line 808 "Gmsh.y"
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
#line 837 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    ;}
    break;

  case 82:
#line 842 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    ;}
    break;

  case 83:
#line 847 "Gmsh.y"
    {
      incrementVariable((yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].i));
      Free((yyvsp[(1) - (6)].c));
    ;}
    break;

  case 84:
#line 852 "Gmsh.y"
    {
      incrementVariable((yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].i));
      Free((yyvsp[(1) - (6)].c));
    ;}
    break;

  case 85:
#line 857 "Gmsh.y"
    {
      assignVariables((yyvsp[(1) - (9)].c), (yyvsp[(4) - (9)].l), (yyvsp[(7) - (9)].i), (yyvsp[(8) - (9)].l));
      Free((yyvsp[(1) - (9)].c));
      List_Delete((yyvsp[(4) - (9)].l));
      List_Delete((yyvsp[(8) - (9)].l));
    ;}
    break;

  case 86:
#line 864 "Gmsh.y"
    {
      assignVariables((yyvsp[(1) - (9)].c), (yyvsp[(4) - (9)].l), (yyvsp[(7) - (9)].i), (yyvsp[(8) - (9)].l));
      Free((yyvsp[(1) - (9)].c));
      List_Delete((yyvsp[(4) - (9)].l));
      List_Delete((yyvsp[(8) - (9)].l));
    ;}
    break;

  case 87:
#line 874 "Gmsh.y"
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
#line 903 "Gmsh.y"
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
#line 932 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    ;}
    break;

  case 90:
#line 937 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    ;}
    break;

  case 91:
#line 942 "Gmsh.y"
    {
      incrementVariable((yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].i));
      Free((yyvsp[(1) - (6)].c));
    ;}
    break;

  case 92:
#line 947 "Gmsh.y"
    {
      incrementVariable((yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].i));
      Free((yyvsp[(1) - (6)].c));
    ;}
    break;

  case 93:
#line 955 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[(1) - (4)].c)] = std::vector<std::string>(1, (yyvsp[(3) - (4)].c));
      Free((yyvsp[(1) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 94:
#line 964 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[(1) - (8)].c)] = std::vector<std::string>();
      Free((yyvsp[(1) - (8)].c));
    ;}
    break;

  case 95:
#line 970 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[(1) - (8)].c)] = std::vector<std::string>();
      Free((yyvsp[(1) - (8)].c));
    ;}
    break;

  case 96:
#line 976 "Gmsh.y"
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
#line 989 "Gmsh.y"
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
#line 1002 "Gmsh.y"
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
#line 1017 "Gmsh.y"
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
#line 1034 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[(1) - (8)].c)] = std::vector<std::string>();
      Free((yyvsp[(1) - (8)].c));
    ;}
    break;

  case 101:
#line 1040 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[(1) - (8)].c)] = std::vector<std::string>();
      Free((yyvsp[(1) - (8)].c));
    ;}
    break;

  case 102:
#line 1046 "Gmsh.y"
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
#line 1059 "Gmsh.y"
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
#line 1072 "Gmsh.y"
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
#line 1087 "Gmsh.y"
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
#line 1104 "Gmsh.y"
    {
      std::string tmp((yyvsp[(5) - (6)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (6)].c), 0, (yyvsp[(3) - (6)].c), tmp);
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 107:
#line 1110 "Gmsh.y"
    {
      std::string tmp((yyvsp[(8) - (9)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (9)].c), (int)(yyvsp[(3) - (9)].d), (yyvsp[(6) - (9)].c), tmp);
      Free((yyvsp[(1) - (9)].c)); Free((yyvsp[(6) - (9)].c)); Free((yyvsp[(8) - (9)].c));
    ;}
    break;

  case 108:
#line 1119 "Gmsh.y"
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
#line 1137 "Gmsh.y"
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
#line 1155 "Gmsh.y"
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
#line 1164 "Gmsh.y"
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
#line 1176 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (8)].c), 0, (yyvsp[(5) - (8)].c), (yyvsp[(7) - (8)].u));
      Free((yyvsp[(1) - (8)].c)); Free((yyvsp[(5) - (8)].c));
    ;}
    break;

  case 113:
#line 1181 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (11)].c), (int)(yyvsp[(3) - (11)].d), (yyvsp[(8) - (11)].c), (yyvsp[(10) - (11)].u));
      Free((yyvsp[(1) - (11)].c)); Free((yyvsp[(8) - (11)].c));
    ;}
    break;

  case 114:
#line 1189 "Gmsh.y"
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
#line 1209 "Gmsh.y"
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
#line 1232 "Gmsh.y"
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
#line 1243 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      if(!GModel::current()->getFields()->newField((int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c)))
	yymsg(0, "Cannot create field %i of type '%s'", (int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c));
#endif
      Free((yyvsp[(6) - (7)].c));
    ;}
    break;

  case 118:
#line 1251 "Gmsh.y"
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
#line 1273 "Gmsh.y"
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
#line 1296 "Gmsh.y"
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
#line 1334 "Gmsh.y"
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
#line 1355 "Gmsh.y"
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
#line 1367 "Gmsh.y"
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
#line 1385 "Gmsh.y"
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
#line 1394 "Gmsh.y"
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
#line 1403 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 130:
#line 1405 "Gmsh.y"
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
#line 1423 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 132:
#line 1425 "Gmsh.y"
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
#line 1441 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 134:
#line 1443 "Gmsh.y"
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
#line 1459 "Gmsh.y"
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
#line 1468 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 137:
#line 1470 "Gmsh.y"
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
#line 1484 "Gmsh.y"
    {
      std::string name((yyvsp[(3) - (3)].c));
      Msg::UndefineOnelabParameter(name);
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 140:
#line 1492 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(doubleXstring));
      doubleXstring v = {(yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].c)};
      List_Add((yyval.l), &v);
    ;}
    break;

  case 141:
#line 1498 "Gmsh.y"
    {
      doubleXstring v = {(yyvsp[(3) - (5)].d), (yyvsp[(5) - (5)].c)};
      List_Add((yyval.l), &v);
    ;}
    break;

  case 142:
#line 1503 "Gmsh.y"
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
#line 1534 "Gmsh.y"
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
#line 1545 "Gmsh.y"
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
#line 1560 "Gmsh.y"
    {
      std::string key((yyvsp[(2) - (3)].c));
      std::string val((yyvsp[(3) - (3)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(2) - (3)].c));
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 150:
#line 1576 "Gmsh.y"
    {
      std::string key((yyvsp[(2) - (3)].c));
      double val = (yyvsp[(3) - (3)].d);
      floatOptions[key].push_back(val);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 151:
#line 1584 "Gmsh.y"
    {
      std::string key((yyvsp[(2) - (3)].c));
      std::string val((yyvsp[(3) - (3)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(2) - (3)].c));
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 152:
#line 1593 "Gmsh.y"
    {
      std::string key("Macro");
      std::string val((yyvsp[(3) - (3)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 153:
#line 1601 "Gmsh.y"
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
#line 1619 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    ;}
    break;

  case 155:
#line 1623 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[(1) - (1)].c)), 0, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 156:
#line 1629 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (3)].c)), 0, (yyvsp[(3) - (3)].d));
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 157:
#line 1637 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    ;}
    break;

  case 158:
#line 1641 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[(1) - (1)].c)), 1, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 159:
#line 1647 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (3)].c)), 1, (yyvsp[(3) - (3)].d));
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 160:
#line 1655 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    ;}
    break;

  case 161:
#line 1659 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[(1) - (1)].c)), 2, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 162:
#line 1665 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (3)].c)), 2, (yyvsp[(3) - (3)].d));
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 163:
#line 1673 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    ;}
    break;

  case 164:
#line 1677 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[(1) - (1)].c)), 3, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 165:
#line 1683 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (3)].c)), 3, (yyvsp[(3) - (3)].d));
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 166:
#line 1691 "Gmsh.y"
    {
      (yyval.l) = 0;
    ;}
    break;

  case 167:
#line 1695 "Gmsh.y"
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
#line 1707 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = 0.;
    ;}
    break;

  case 169:
#line 1711 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 170:
#line 1719 "Gmsh.y"
    {
      // FIXME: when changing to OpenCASCADE, get maxTags from GEO_Internals and
      // add that info in OCC_Internals - same in the other direction
      factory = (yyvsp[(3) - (5)].c);
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 171:
#line 1729 "Gmsh.y"
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
#line 1757 "Gmsh.y"
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
#line 1800 "Gmsh.y"
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
#line 1823 "Gmsh.y"
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
#line 1852 "Gmsh.y"
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
#line 1873 "Gmsh.y"
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
#line 1891 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (8)].d);
      if(FindCurve(num)){
	yymsg(0, "Curve %d already exists", num);
      }
      else{
        if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
          if(List_Nbr((yyvsp[(6) - (8)].l)) >= 3 && List_Nbr((yyvsp[(6) - (8)].l)) <= 6){
            double d[3];
            List_Read((yyvsp[(6) - (8)].l), 0, &d[0]); List_Read((yyvsp[(6) - (8)].l), 1, &d[1]); List_Read((yyvsp[(6) - (8)].l), 2, &d[2]);
            if(List_Nbr((yyvsp[(6) - (8)].l)) == 3){
              GModel::current()->getOCCInternals()->addCircleArc
                (num, (int)d[0], (int)d[1], (int)d[2]);
            }
            else{
              double r; List_Read((yyvsp[(6) - (8)].l), 3, &r);
              double a1 = 0., a2 = 2.*M_PI;
              if(List_Nbr((yyvsp[(6) - (8)].l)) == 5){
                List_Read((yyvsp[(6) - (8)].l), 4, &a2);
              }
              else if(List_Nbr((yyvsp[(6) - (8)].l)) == 6){
                List_Read((yyvsp[(6) - (8)].l), 4, &a1); List_Read((yyvsp[(6) - (8)].l), 5, &a2);
              }
              GModel::current()->getOCCInternals()->addCircle(num, d[0], d[1], d[2],
                                                              r, a1, a2);
            }
          }
          else{
            yymsg(0, "Circle definition requires 3 to 5 parameters");
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
#line 1948 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (8)].d);
      if(FindCurve(num)){
	yymsg(0, "Curve %d already exists", num);
      }
      else{
        if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
          if(List_Nbr((yyvsp[(6) - (8)].l)) >= 3 || List_Nbr((yyvsp[(6) - (8)].l)) <= 7){
            if(List_Nbr((yyvsp[(6) - (8)].l)) == 3 || List_Nbr((yyvsp[(6) - (8)].l)) == 4){
              double start, center, end;
              List_Read((yyvsp[(6) - (8)].l), 0, &start); List_Read((yyvsp[(6) - (8)].l), 1, &center);
              if(List_Nbr((yyvsp[(6) - (8)].l)) == 3)
                List_Read((yyvsp[(6) - (8)].l), 2, &end);
              else
                List_Read((yyvsp[(6) - (8)].l), 3, &end);
              GModel::current()->getOCCInternals()->addEllipseArc
                (num, (int)start, (int)center, (int)end);
            }
            else{
              double x; List_Read((yyvsp[(6) - (8)].l), 0, &x);
              double y; List_Read((yyvsp[(6) - (8)].l), 1, &y);
              double z; List_Read((yyvsp[(6) - (8)].l), 2, &z);
              double r1; List_Read((yyvsp[(6) - (8)].l), 3, &r1);
              double r2; List_Read((yyvsp[(6) - (8)].l), 4, &r2);
              double a1 = 0., a2 = 2.*M_PI;
              if(List_Nbr((yyvsp[(6) - (8)].l)) == 6){
                List_Read((yyvsp[(6) - (8)].l), 5, &a2);
              }
              else if(List_Nbr((yyvsp[(6) - (8)].l)) == 7){
                List_Read((yyvsp[(6) - (8)].l), 5, &a1); List_Read((yyvsp[(6) - (8)].l), 6, &a2);
              }
              GModel::current()->getOCCInternals()->addEllipse(num, x, y, z,
                                                               r1, r2, a1, a2);
            }
          }
          else{
            yymsg(0, "Ellipse definition requires 3 to 7 parameters");
          }
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
      }
      List_Delete((yyvsp[(6) - (8)].l));
      (yyval.s).Type = MSH_SEGM_ELLI;
      (yyval.s).Num = num;
    ;}
    break;

  case 179:
#line 2013 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      if(FindCurve(num)){
	yymsg(0, "Curve %d already exists", num);
      }
      else{
        if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
          std::vector<int> tags;
          for(int i = 0; i < List_Nbr((yyvsp[(6) - (7)].l)); i++){
            double d; List_Read((yyvsp[(6) - (7)].l), i, &d); tags.push_back((int)d);
          }
          GModel::current()->getOCCInternals()->addBSpline(num, tags);
        }
        else{
          List_T *temp = ListOfDouble2ListOfInt((yyvsp[(6) - (7)].l));
          Curve *c = Create_Curve(num, MSH_SEGM_BSPLN, 2, temp, NULL,
                                  -1, -1, 0., 1.);
          Tree_Add(GModel::current()->getGEOInternals()->Curves, &c);
          CreateReversedCurve(c);
          List_Delete(temp);
        }
      }
      List_Delete((yyvsp[(6) - (7)].l));
      (yyval.s).Type = MSH_SEGM_BSPLN;
      (yyval.s).Num = num;
    ;}
    break;

  case 180:
#line 2040 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      if(FindCurve(num)){
	yymsg(0, "Curve %d already exists", num);
      }
      else{
        if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
          std::vector<int> tags;
          for(int i = 0; i < List_Nbr((yyvsp[(6) - (7)].l)); i++){
            double d; List_Read((yyvsp[(6) - (7)].l), i, &d); tags.push_back((int)d);
          }
          GModel::current()->getOCCInternals()->addBezier(num, tags);
        }
        else{
          List_T *temp = ListOfDouble2ListOfInt((yyvsp[(6) - (7)].l));
          Curve *c = Create_Curve(num, MSH_SEGM_BEZIER, 2, temp, NULL,
                                  -1, -1, 0., 1.);
          Tree_Add(GModel::current()->getGEOInternals()->Curves, &c);
          CreateReversedCurve(c);
          List_Delete(temp);
        }
      }
      List_Delete((yyvsp[(6) - (7)].l));
      (yyval.s).Type = MSH_SEGM_BEZIER;
      (yyval.s).Num = num;
    ;}
    break;

  case 181:
#line 2068 "Gmsh.y"
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
#line 2094 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].d);
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        std::vector<int> edges;
        for(int i = 0; i < List_Nbr((yyvsp[(7) - (8)].l)); i++){
          double d; List_Read((yyvsp[(7) - (8)].l), i, &d);
          edges.push_back((int)std::abs(d));
        }
        GModel::current()->getOCCInternals()->addLineLoop(num, edges);
      }
      else{
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
      }
      List_Delete((yyvsp[(7) - (8)].l));
      Free((yyvsp[(2) - (8)].c));
      (yyval.s).Type = MSH_SEGM_LOOP;
      (yyval.s).Num = num;
    ;}
    break;

  case 183:
#line 2123 "Gmsh.y"
    {
     GModel::current()->getGEOInternals()->addCompoundMesh ( 1 , (yyvsp[(3) - (4)].l) );
   ;}
    break;

  case 184:
#line 2128 "Gmsh.y"
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
#line 2146 "Gmsh.y"
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
#line 2192 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].d);
      if(FindSurface(num)){
        yymsg(0, "Surface %d already exists", num);
      }
      else{
        if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
          std::vector<int> wires;
          for(int i = 0; i < List_Nbr((yyvsp[(7) - (8)].l)); i++){
            double d; List_Read((yyvsp[(7) - (8)].l), i, &d);
            wires.push_back((int)std::abs(d));
          }
          GModel::current()->getOCCInternals()->addPlanarFace(num, wires);
        }
        else{
          Surface *s = Create_Surface(num, MSH_SURF_PLAN);
          List_T *temp = ListOfDouble2ListOfInt((yyvsp[(7) - (8)].l));
          setSurfaceGeneratrices(s, temp);
          List_Delete(temp);
          End_Surface(s);
          Tree_Add(GModel::current()->getGEOInternals()->Surfaces, &s);
        }
      }
      List_Delete((yyvsp[(7) - (8)].l));
      (yyval.s).Type = MSH_SURF_PLAN;
      (yyval.s).Num = num;
    ;}
    break;

  case 187:
#line 2220 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (8)].d), type = 0;
      if(FindSurface(num)){
        yymsg(0, "Surface %d already exists", num);
      }
      else{
        if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
          std::vector<int> wires;
          for(int i = 0; i < List_Nbr((yyvsp[(6) - (8)].l)); i++){
            double d; List_Read((yyvsp[(6) - (8)].l), i, &d);
            wires.push_back((int)std::abs(d));
          }
          std::vector<std::vector<double> > points;
          GModel::current()->getOCCInternals()->addFaceFilling(num, wires, points);
        }
        else{
          double d;
          List_Read((yyvsp[(6) - (8)].l), 0, &d);
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
              yymsg(0, "Wrong definition of Surface %d: "
                    "%d borders instead of 3 or 4", num, j);
              type = MSH_SURF_PLAN;
            }
            Surface *s = Create_Surface(num, type);
            List_T *temp = ListOfDouble2ListOfInt((yyvsp[(6) - (8)].l));
            setSurfaceGeneratrices(s, temp);
            List_Delete(temp);
            End_Surface(s);
            s->InSphereCenter = (yyvsp[(7) - (8)].l);
            Tree_Add(GModel::current()->getGEOInternals()->Surfaces, &s);
          }
        }
      }
      List_Delete((yyvsp[(6) - (8)].l));
      (yyval.s).Type = type;
      (yyval.s).Num = num;
    ;}
    break;

  case 188:
#line 2271 "Gmsh.y"
    {
      yymsg(1, "'Ruled Surface' command is deprecated: use 'Surface' instead");
      int num = (int)(yyvsp[(4) - (9)].d), type = 0;
      if(FindSurface(num)){
        yymsg(0, "Surface %d already exists", num);
      }
      else{
        if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
          std::vector<int> wires;
          for(int i = 0; i < List_Nbr((yyvsp[(7) - (9)].l)); i++){
            double d; List_Read((yyvsp[(7) - (9)].l), i, &d);
            wires.push_back((int)std::abs(d));
          }
          std::vector<std::vector<double> > points;
          GModel::current()->getOCCInternals()->addFaceFilling(num, wires, points);
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
              yymsg(0, "Wrong definition of Surface %d: "
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
      }
      List_Delete((yyvsp[(7) - (9)].l));
      (yyval.s).Type = type;
      (yyval.s).Num = num;
    ;}
    break;

  case 189:
#line 2322 "Gmsh.y"
    {
      myGmshSurface = 0;
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 190:
#line 2328 "Gmsh.y"
    {
      myGmshSurface = gmshSurface::getSurface((int)(yyvsp[(3) - (4)].d));
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 191:
#line 2334 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (10)].d);
      myGmshSurface = gmshParametricSurface::NewParametricSurface(num, (yyvsp[(7) - (10)].c), (yyvsp[(8) - (10)].c), (yyvsp[(9) - (10)].c));
      (yyval.s).Type = 0;
      (yyval.s).Num = num;
    ;}
    break;

  case 192:
#line 2341 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      if(List_Nbr((yyvsp[(6) - (7)].l)) == 4 || List_Nbr((yyvsp[(6) - (7)].l)) == 5){
        if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
          double x; List_Read((yyvsp[(6) - (7)].l), 0, &x);
          double y; List_Read((yyvsp[(6) - (7)].l), 1, &y);
          double z; List_Read((yyvsp[(6) - (7)].l), 2, &z);
          double r; List_Read((yyvsp[(6) - (7)].l), 3, &r);
          double alpha = 2.*M_PI; if(List_Nbr((yyvsp[(6) - (7)].l)) == 5) List_Read((yyvsp[(6) - (7)].l), 4, &alpha);
          GModel::current()->getOCCInternals()->addSphere(num, x, y, z, r, alpha);
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

  case 193:
#line 2383 "Gmsh.y"
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

  case 194:
#line 2409 "Gmsh.y"
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

  case 195:
#line 2433 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      if(List_Nbr((yyvsp[(6) - (7)].l)) == 5 || List_Nbr((yyvsp[(6) - (7)].l)) == 6){
        if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
          double x; List_Read((yyvsp[(6) - (7)].l), 0, &x);
          double y; List_Read((yyvsp[(6) - (7)].l), 1, &y);
          double z; List_Read((yyvsp[(6) - (7)].l), 2, &z);
          double r1; List_Read((yyvsp[(6) - (7)].l), 3, &r1);
          double r2; List_Read((yyvsp[(6) - (7)].l), 4, &r2);
          double alpha = 2*M_PI; if(List_Nbr((yyvsp[(6) - (7)].l)) == 6) List_Read((yyvsp[(6) - (7)].l), 5, &alpha);
          GModel::current()->getOCCInternals()->addTorus(num, x, y, z, r1, r2, alpha);
        }
        else{
          yymsg(0, "Torus only available with OpenCASCADE factory");
        }
      }
      else{
        yymsg(0, "Torus has to be defined using {x,y,z,r1,r2} or {x,y,z,r1,r2,alpha}");
      }
      List_Delete((yyvsp[(6) - (7)].l));
      (yyval.s).Type = MSH_VOLUME;
      (yyval.s).Num = num;
    ;}
    break;

  case 196:
#line 2457 "Gmsh.y"
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
          GModel::current()->getOCCInternals()->addRectangle(num, x1, y1, z1,
                                                             x2, y2, z2);
        }
        else{
          yymsg(0, "Rectangle only available with OpenCASCADE factory");
        }
      }
      else{
        yymsg(0, "Rectangle has to be defined using {x1,y1,z1,x2,y2,z2}");
      }
      List_Delete((yyvsp[(6) - (7)].l));
      (yyval.s).Type = MSH_SURF_PLAN;
      (yyval.s).Num = num;
    ;}
    break;

  case 197:
#line 2482 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      if(List_Nbr((yyvsp[(6) - (7)].l)) == 4 || List_Nbr((yyvsp[(6) - (7)].l)) == 5){
        if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
          double xc; List_Read((yyvsp[(6) - (7)].l), 0, &xc);
          double yc; List_Read((yyvsp[(6) - (7)].l), 1, &yc);
          double zc; List_Read((yyvsp[(6) - (7)].l), 2, &zc);
          double rx; List_Read((yyvsp[(6) - (7)].l), 3, &rx);
          double ry = rx; if(List_Nbr((yyvsp[(6) - (7)].l)) == 5) List_Read((yyvsp[(6) - (7)].l), 4, &ry);
          GModel::current()->getOCCInternals()->addDisk(num, xc, yc, zc, rx, ry);
        }
        else{
          yymsg(0, "Disk only available with OpenCASCADE factory");
        }
      }
      else{
        yymsg(0, "Disk has to be defined using {x,y,z,r} or {x,y,z,rx,ry}");
      }
      List_Delete((yyvsp[(6) - (7)].l));
      (yyval.s).Type = MSH_SURF_PLAN;
      (yyval.s).Num = num;
    ;}
    break;

  case 198:
#line 2505 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      if(List_Nbr((yyvsp[(6) - (7)].l)) == 7 || List_Nbr((yyvsp[(6) - (7)].l)) == 8){
        if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
          double x1; List_Read((yyvsp[(6) - (7)].l), 0, &x1);
          double y1; List_Read((yyvsp[(6) - (7)].l), 1, &y1);
          double z1; List_Read((yyvsp[(6) - (7)].l), 2, &z1);
          double x2; List_Read((yyvsp[(6) - (7)].l), 3, &x2);
          double y2; List_Read((yyvsp[(6) - (7)].l), 4, &y2);
          double z2; List_Read((yyvsp[(6) - (7)].l), 5, &z2);
          double r; List_Read((yyvsp[(6) - (7)].l), 6, &r);
          double angle = 2*M_PI; if(List_Nbr((yyvsp[(6) - (7)].l)) == 8) List_Read((yyvsp[(6) - (7)].l), 7, &angle);
          GModel::current()->getOCCInternals()->addCylinder(num, x1, y1, z1,
                                                            x2, y2, z2, r, angle);
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

  case 199:
#line 2532 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      if(List_Nbr((yyvsp[(6) - (7)].l)) == 8 || List_Nbr((yyvsp[(6) - (7)].l)) == 9){
        if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
          double x1; List_Read((yyvsp[(6) - (7)].l), 0, &x1);
          double y1; List_Read((yyvsp[(6) - (7)].l), 1, &y1);
          double z1; List_Read((yyvsp[(6) - (7)].l), 2, &z1);
          double x2; List_Read((yyvsp[(6) - (7)].l), 3, &x2);
          double y2; List_Read((yyvsp[(6) - (7)].l), 4, &y2);
          double z2; List_Read((yyvsp[(6) - (7)].l), 5, &z2);
          double r1; List_Read((yyvsp[(6) - (7)].l), 6, &r1);
          double r2; List_Read((yyvsp[(6) - (7)].l), 7, &r2);
          double alpha=2*M_PI; if(List_Nbr((yyvsp[(6) - (7)].l)) == 9) List_Read((yyvsp[(6) - (7)].l), 8, &alpha);
          GModel::current()->getOCCInternals()->addCone(num, x1, y1, z1, x2, y2, z2,
                                                        r1, r2, alpha);
        }
        else{
          yymsg(0, "Cone only available with OpenCASCADE factory");
        }
      }
      else{
        yymsg(0, "Cone has to be defined using 2 points and 2 radii");
      }
      List_Delete((yyvsp[(6) - (7)].l));
      (yyval.s).Type = MSH_VOLUME;
      (yyval.s).Num = num;
    ;}
    break;

  case 200:
#line 2560 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      if(List_Nbr((yyvsp[(6) - (7)].l)) == 7){
        if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
          double x; List_Read((yyvsp[(6) - (7)].l), 0, &x);
          double y; List_Read((yyvsp[(6) - (7)].l), 1, &y);
          double z; List_Read((yyvsp[(6) - (7)].l), 2, &z);
          double dx; List_Read((yyvsp[(6) - (7)].l), 3, &dx);
          double dy; List_Read((yyvsp[(6) - (7)].l), 4, &dy);
          double dz; List_Read((yyvsp[(6) - (7)].l), 5, &dz);
          double ltx; List_Read((yyvsp[(6) - (7)].l), 6, &ltx);
          GModel::current()->getOCCInternals()->addWedge(num, x, y, z, dx, dy, dz, ltx);
        }
        else{
          yymsg(0, "Wedge only available with OpenCASCADE factory");
        }
      }
      else{
        yymsg(0, "Wedge requires 7 arguments");
      }
      List_Delete((yyvsp[(6) - (7)].l));
      (yyval.s).Type = MSH_VOLUME;
      (yyval.s).Num = num;
    ;}
    break;

  case 201:
#line 2585 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        if(List_Nbr((yyvsp[(6) - (7)].l)) >= 2){
          double in; List_Read((yyvsp[(6) - (7)].l), 0, &in);
          double offset; List_Read((yyvsp[(6) - (7)].l), 1, &offset);
          std::vector<int> exclude;
          for(int i = 2; i < List_Nbr((yyvsp[(6) - (7)].l)); i++){
            double d; List_Read((yyvsp[(6) - (7)].l), i, &d); exclude.push_back((int)d);
          }
          GModel::current()->getOCCInternals()->addThickSolid(num, (int)in, exclude,
                                                              offset);
        }
        else{
          yymsg(0, "ThickSolid requires at least 2 arguments");
        }
      }
      else{
        yymsg(0, "ThickSolid only available with OpenCASCADE factory");
      }
      List_Delete((yyvsp[(6) - (7)].l));
    ;}
    break;

  case 202:
#line 2608 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].d);
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        std::vector<int> faces;
        for(int i = 0; i < List_Nbr((yyvsp[(7) - (8)].l)); i++){
          double d; List_Read((yyvsp[(7) - (8)].l), i, &d);
          faces.push_back((int)std::abs(d));
        }
        GModel::current()->getOCCInternals()->addSurfaceLoop(num, faces);
      }
      else{
        if(FindSurfaceLoop(num)){
          yymsg(0, "Surface loop %d already exists", num);
        }
        else{
          List_T *temp = ListOfDouble2ListOfInt((yyvsp[(7) - (8)].l));
          SurfaceLoop *l = Create_SurfaceLoop(num, temp);
          Tree_Add(GModel::current()->getGEOInternals()->SurfaceLoops, &l);
          List_Delete(temp);
        }
      }
      List_Delete((yyvsp[(7) - (8)].l));
      Free((yyvsp[(2) - (8)].c));
      (yyval.s).Type = MSH_SURF_LOOP;
      (yyval.s).Num = num;
    ;}
    break;

  case 203:
#line 2635 "Gmsh.y"
    {
      GModel::current()->getGEOInternals()->addCompoundMesh ( 2 , (yyvsp[(3) - (4)].l) );
    ;}
    break;

  case 204:
#line 2639 "Gmsh.y"
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

  case 205:
#line 2659 "Gmsh.y"
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

  case 206:
#line 2692 "Gmsh.y"
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

  case 207:
#line 2739 "Gmsh.y"
    {
      yymsg(1, "'Complex Volume' command is deprecated: use 'Volume' instead");
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

  case 208:
#line 2757 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      if(FindVolume(num)){
        yymsg(0, "Volume %d already exists", num);
      }
      else{
        if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
          std::vector<int> shells;
          for(int i = 0; i < List_Nbr((yyvsp[(6) - (7)].l)); i++){
            double d; List_Read((yyvsp[(6) - (7)].l), i, &d);
            shells.push_back((int)std::abs(d));
          }
          GModel::current()->getOCCInternals()->addVolume(num, shells);
        }
        else{
          Volume *v = Create_Volume(num, MSH_VOLUME);
          List_T *temp = ListOfDouble2ListOfInt((yyvsp[(6) - (7)].l));
          setVolumeSurfaces(v, temp);
          List_Delete(temp);
          Tree_Add(GModel::current()->getGEOInternals()->Volumes, &v);
        }
      }
      List_Delete((yyvsp[(6) - (7)].l));
      (yyval.s).Type = MSH_VOLUME;
      (yyval.s).Num = num;
    ;}
    break;

  case 209:
#line 2784 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        std::vector<int> wires, out[4];
        for(int i = 0; i < List_Nbr((yyvsp[(6) - (7)].l)); i++){
          double d; List_Read((yyvsp[(6) - (7)].l), i, &d);
          wires.push_back((int)std::abs(d));
        }
        GModel::current()->getOCCInternals()->addThruSections(num, wires,
                                                              out, true, false);
      }
      else{
        yymsg(0, "ThruSections only available with OpenCASCADE factory");
      }
      List_Delete((yyvsp[(6) - (7)].l));
      (yyval.s).Type = MSH_VOLUME;
      (yyval.s).Num = num;
    ;}
    break;

  case 210:
#line 2803 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].d);
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        std::vector<int> wires, out[4];
        for(int i = 0; i < List_Nbr((yyvsp[(7) - (8)].l)); i++){
          double d; List_Read((yyvsp[(7) - (8)].l), i, &d);
          wires.push_back((int)std::abs(d));
        }
        GModel::current()->getOCCInternals()->addThruSections(num, wires,
                                                              out, true, true);
      }
      else{
        yymsg(0, "ThruSections only available with OpenCASCADE factory");
      }
      List_Delete((yyvsp[(7) - (8)].l));
      (yyval.s).Type = MSH_VOLUME;
      (yyval.s).Num = num;
    ;}
    break;

  case 211:
#line 2822 "Gmsh.y"
    {
      GModel::current()->getGEOInternals()->addCompoundMesh(3, (yyvsp[(3) - (4)].l));
    ;}
    break;

  case 212:
#line 2826 "Gmsh.y"
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

  case 213:
#line 2842 "Gmsh.y"
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

  case 214:
#line 2890 "Gmsh.y"
    {
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
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

  case 215:
#line 2907 "Gmsh.y"
    {
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
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

  case 216:
#line 2925 "Gmsh.y"
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

  case 217:
#line 2935 "Gmsh.y"
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

  case 218:
#line 2945 "Gmsh.y"
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

  case 219:
#line 2955 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
      if(!strcmp((yyvsp[(1) - (4)].c), "Duplicata")){
        if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
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

  case 220:
#line 3018 "Gmsh.y"
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

  case 221:
#line 3029 "Gmsh.y"
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

  case 222:
#line 3044 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 223:
#line 3045 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 224:
#line 3050 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    ;}
    break;

  case 225:
#line 3054 "Gmsh.y"
    {
      List_Add((yyval.l), &(yyvsp[(2) - (2)].s));
    ;}
    break;

  case 226:
#line 3058 "Gmsh.y"
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

  case 227:
#line 3087 "Gmsh.y"
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

  case 228:
#line 3116 "Gmsh.y"
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

  case 229:
#line 3145 "Gmsh.y"
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

  case 230:
#line 3179 "Gmsh.y"
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

  case 231:
#line 3201 "Gmsh.y"
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

  case 232:
#line 3228 "Gmsh.y"
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

  case 233:
#line 3250 "Gmsh.y"
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

  case 234:
#line 3272 "Gmsh.y"
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

  case 235:
#line 3294 "Gmsh.y"
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

  case 236:
#line 3350 "Gmsh.y"
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

  case 237:
#line 3374 "Gmsh.y"
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

  case 238:
#line 3399 "Gmsh.y"
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

  case 239:
#line 3424 "Gmsh.y"
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

  case 240:
#line 3537 "Gmsh.y"
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

  case 241:
#line 3556 "Gmsh.y"
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

  case 242:
#line 3599 "Gmsh.y"
    {
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
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

  case 243:
#line 3620 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      GModel::current()->getFields()->deleteField((int)(yyvsp[(4) - (6)].d));
#endif
    ;}
    break;

  case 244:
#line 3626 "Gmsh.y"
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

  case 245:
#line 3641 "Gmsh.y"
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

  case 246:
#line 3669 "Gmsh.y"
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

  case 247:
#line 3686 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(4) - (5)].l), i, &TheShape);
	ColorShape(TheShape.Type, TheShape.Num, (yyvsp[(2) - (5)].u), false);
      }
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 248:
#line 3695 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(5) - (6)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(5) - (6)].l), i, &TheShape);
	ColorShape(TheShape.Type, TheShape.Num, (yyvsp[(3) - (6)].u), true);
      }
      List_Delete((yyvsp[(5) - (6)].l));
    ;}
    break;

  case 249:
#line 3709 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(4) - (5)].l), i, &TheShape);
	SetPartition(TheShape.Type, TheShape.Num, (yyvsp[(2) - (5)].d));
      }
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 250:
#line 3723 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 1, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 251:
#line 3729 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 0, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 252:
#line 3735 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 1, false);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 253:
#line 3744 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(4) - (5)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 1, true);
      }
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 254:
#line 3753 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 0, false);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 255:
#line 3762 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(4) - (5)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 0, true);
      }
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 256:
#line 3776 "Gmsh.y"
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

  case 257:
#line 3838 "Gmsh.y"
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

  case 258:
#line 3856 "Gmsh.y"
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

  case 259:
#line 3873 "Gmsh.y"
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

  case 260:
#line 3888 "Gmsh.y"
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

  case 261:
#line 3917 "Gmsh.y"
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

  case 262:
#line 3929 "Gmsh.y"
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

  case 263:
#line 3953 "Gmsh.y"
    {
      Msg::Exit(0);
    ;}
    break;

  case 264:
#line 3957 "Gmsh.y"
    {
      gmsh_yyerrorstate = 999; // this will be checked when yyparse returns
      YYABORT;
    ;}
    break;

  case 265:
#line 3962 "Gmsh.y"
    {
      // FIXME: this is a hack to force a transfer from the old DB to
      // the new DB. This will become unnecessary if/when we fill the
      // GModel directly during parsing.
      GModel::current()->importGEOInternals();
      GModel::current()->importOCCInternals();
    ;}
    break;

  case 266:
#line 3970 "Gmsh.y"
    {
      new GModel();
      GModel::current(GModel::list.size() - 1);
    ;}
    break;

  case 267:
#line 3975 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 0;
      GModel::current()->importGEOInternals();
      SetBoundingBox();
    ;}
    break;

  case 268:
#line 3981 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 1;
      SetBoundingBox((yyvsp[(3) - (15)].d), (yyvsp[(5) - (15)].d), (yyvsp[(7) - (15)].d), (yyvsp[(9) - (15)].d), (yyvsp[(11) - (15)].d), (yyvsp[(13) - (15)].d));
    ;}
    break;

  case 269:
#line 3986 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
      drawContext::global()->draw();
#endif
    ;}
    break;

  case 270:
#line 3992 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
     CTX::instance()->mesh.changed = ENT_ALL;
     for(unsigned int index = 0; index < PView::list.size(); index++)
       PView::list[index]->setChanged(true);
#endif
    ;}
    break;

  case 271:
#line 4000 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh();
    ;}
    break;

  case 272:
#line 4004 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh(1);
    ;}
    break;

  case 273:
#line 4008 "Gmsh.y"
    {
      GModel::current()->importGEOInternals();
      GModel::current()->refineMesh(CTX::instance()->mesh.secondOrderLinear);
    ;}
    break;

  case 274:
#line 4014 "Gmsh.y"
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

  case 275:
#line 4073 "Gmsh.y"
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

  case 276:
#line 4089 "Gmsh.y"
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

  case 277:
#line 4106 "Gmsh.y"
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

  case 278:
#line 4123 "Gmsh.y"
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

  case 279:
#line 4145 "Gmsh.y"
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

  case 280:
#line 4167 "Gmsh.y"
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

  case 281:
#line 4202 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip_until(NULL, "Return");
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 282:
#line 4210 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip_until(NULL, "Return");
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 283:
#line 4218 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    ;}
    break;

  case 284:
#line 4224 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 285:
#line 4231 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 286:
#line 4238 "Gmsh.y"
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

  case 287:
#line 4258 "Gmsh.y"
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

  case 288:
#line 4284 "Gmsh.y"
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

  case 289:
#line 4296 "Gmsh.y"
    {
      ImbricatedTest--;
      if(ImbricatedTest < 0)
        yymsg(1, "Orphan EndIf");
    ;}
    break;

  case 290:
#line 4308 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
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

  case 291:
#line 4338 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
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

  case 292:
#line 4369 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (13)].l),
		    (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].v)[0], (yyvsp[(7) - (13)].v)[1], (yyvsp[(7) - (13)].v)[2], (yyvsp[(9) - (13)].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[(12) - (13)].l));
    ;}
    break;

  case 293:
#line 4377 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 294:
#line 4383 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (7)].l),
		    (yyvsp[(2) - (7)].v)[0], (yyvsp[(2) - (7)].v)[1], (yyvsp[(2) - (7)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(4) - (7)].l));
    ;}
    break;

  case 295:
#line 4391 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 296:
#line 4397 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[(10) - (13)].l),
		    0., 0., 0., (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(10) - (13)].l));
    ;}
    break;

  case 297:
#line 4405 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 298:
#line 4411 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (15)].l),
		    (yyvsp[(3) - (15)].v)[0], (yyvsp[(3) - (15)].v)[1], (yyvsp[(3) - (15)].v)[2], (yyvsp[(5) - (15)].v)[0], (yyvsp[(5) - (15)].v)[1], (yyvsp[(5) - (15)].v)[2], (yyvsp[(7) - (15)].v)[0], (yyvsp[(7) - (15)].v)[1], (yyvsp[(7) - (15)].v)[2], (yyvsp[(9) - (15)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(12) - (15)].l));
    ;}
    break;

  case 299:
#line 4419 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 300:
#line 4425 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(BOUNDARY_LAYER, (yyvsp[(3) - (6)].l), 0., 0., 0., 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(3) - (6)].l));
    ;}
    break;

  case 301:
#line 4432 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        std::vector<int> edges;
        std::vector<int> in[4], out[4];
        for(int i = 0; i < List_Nbr((yyvsp[(8) - (9)].l)); i++){
          double d; List_Read((yyvsp[(8) - (9)].l), i, &d);
          edges.push_back((int)d);
        }
        Shape TheShape;
        for(int i = 0; i < List_Nbr((yyvsp[(3) - (9)].l)); i++){
          List_Read((yyvsp[(3) - (9)].l), i, &TheShape);
          int dim = TheShape.Type / 100 - 1;
          if(dim >= 0 && dim <= 3) in[dim].push_back(TheShape.Num);
        }
        GModel::current()->getOCCInternals()->addPipe(-1, in, edges, out);
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
      List_Delete((yyvsp[(8) - (9)].l));
    ;}
    break;

  case 302:
#line 4465 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        std::vector<int> wires, out[4];
        for(int i = 0; i < List_Nbr((yyvsp[(2) - (2)].l)); i++){
          double d; List_Read((yyvsp[(2) - (2)].l), i, &d);
          wires.push_back((int)std::abs(d));
        }
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

  case 303:
#line 4488 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        std::vector<int> wires, out[4];
        for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
          double d; List_Read((yyvsp[(3) - (3)].l), i, &d);
          wires.push_back((int)std::abs(d));
        }
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

  case 304:
#line 4511 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        double radius = (yyvsp[(9) - (10)].d);
        std::vector<int> regions, edges, out[4];
        for(int i = 0; i < List_Nbr((yyvsp[(3) - (10)].l)); i++){
          double d; List_Read((yyvsp[(3) - (10)].l), i, &d); regions.push_back((int)d);
        }
        for(int i = 0; i < List_Nbr((yyvsp[(6) - (10)].l)); i++){
          double d; List_Read((yyvsp[(6) - (10)].l), i, &d); edges.push_back((int)d);
        }
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

  case 305:
#line 4542 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 306:
#line 4549 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 307:
#line 4556 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 308:
#line 4563 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 309:
#line 4570 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 310:
#line 4577 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 311:
#line 4584 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 312:
#line 4591 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 313:
#line 4598 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 314:
#line 4605 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 315:
#line 4611 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 316:
#line 4618 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 317:
#line 4624 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 318:
#line 4631 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 319:
#line 4637 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 320:
#line 4644 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 321:
#line 4650 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 322:
#line 4657 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 323:
#line 4663 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 324:
#line 4670 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 325:
#line 4676 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 326:
#line 4683 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 327:
#line 4689 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 328:
#line 4696 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 329:
#line 4702 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 330:
#line 4709 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 331:
#line 4715 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 332:
#line 4726 "Gmsh.y"
    {
    ;}
    break;

  case 333:
#line 4729 "Gmsh.y"
    {
    ;}
    break;

  case 334:
#line 4735 "Gmsh.y"
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

  case 335:
#line 4747 "Gmsh.y"
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

  case 336:
#line 4767 "Gmsh.y"
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

  case 337:
#line 4791 "Gmsh.y"
    {
      extr.mesh.ScaleLast = true;
    ;}
    break;

  case 338:
#line 4795 "Gmsh.y"
    {
      extr.mesh.Recombine = true;
    ;}
    break;

  case 339:
#line 4799 "Gmsh.y"
    {
      extr.mesh.Recombine = (yyvsp[(2) - (3)].d) ? true : false;
    ;}
    break;

  case 340:
#line 4803 "Gmsh.y"
    {
      yymsg(0, "Keyword 'QuadTriSngl' deprecated. Use 'QuadTriNoNewVerts' instead.");
    ;}
    break;

  case 341:
#line 4807 "Gmsh.y"
    {
      yymsg(0, "Keyword 'QuadTriSngl' deprecated. Use 'QuadTriNoNewVerts' instead.");
    ;}
    break;

  case 342:
#line 4811 "Gmsh.y"
    {
      yymsg(0, "Method 'QuadTriDbl' deprecated. Use 'QuadTriAddVerts' instead, "
            "which has no requirement for the number of extrusion layers and meshes "
            "with body-centered vertices.");
    ;}
    break;

  case 343:
#line 4817 "Gmsh.y"
    {
      yymsg(0, "Method 'QuadTriDbl' deprecated. Use 'QuadTriAddVerts' instead, "
            "which has no requirement for the number of extrusion layers and meshes "
            "with body-centered vertices.");
    ;}
    break;

  case 344:
#line 4823 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1;
    ;}
    break;

  case 345:
#line 4827 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1_RECOMB;
    ;}
    break;

  case 346:
#line 4831 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1;
    ;}
    break;

  case 347:
#line 4835 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1_RECOMB;
    ;}
    break;

  case 348:
#line 4839 "Gmsh.y"
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

  case 349:
#line 4858 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (6)].c), "Index"))
        extr.mesh.BoundaryLayerIndex = (yyvsp[(4) - (6)].d);
      else if(!strcmp((yyvsp[(2) - (6)].c), "View"))
        extr.mesh.ViewIndex = (yyvsp[(4) - (6)].d);
      Free((yyvsp[(2) - (6)].c));
    ;}
    break;

  case 350:
#line 4870 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Union; ;}
    break;

  case 351:
#line 4871 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Intersection; ;}
    break;

  case 352:
#line 4872 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Difference; ;}
    break;

  case 353:
#line 4873 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Section; ;}
    break;

  case 354:
#line 4874 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Fragments; ;}
    break;

  case 355:
#line 4878 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 356:
#line 4879 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 357:
#line 4880 "Gmsh.y"
    { (yyval.i) = (yyvsp[(2) - (3)].d); ;}
    break;

  case 358:
#line 4885 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
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

  case 359:
#line 4918 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
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

  case 360:
#line 4945 "Gmsh.y"
    {
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
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

  case 361:
#line 4967 "Gmsh.y"
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    ;}
    break;

  case 362:
#line 4971 "Gmsh.y"
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

  case 363:
#line 4986 "Gmsh.y"
    {
      (yyval.i) = -1; // left
    ;}
    break;

  case 364:
#line 4990 "Gmsh.y"
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

  case 365:
#line 5006 "Gmsh.y"
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   ;}
    break;

  case 366:
#line 5010 "Gmsh.y"
    {
     (yyval.l) = (yyvsp[(2) - (2)].l);
   ;}
    break;

  case 367:
#line 5015 "Gmsh.y"
    {
      (yyval.i) = 45;
    ;}
    break;

  case 368:
#line 5019 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(2) - (2)].d);
    ;}
    break;

  case 369:
#line 5025 "Gmsh.y"
    {
      (yyval.l) = List_Create(1, 1, sizeof(double));
    ;}
    break;

  case 370:
#line 5029 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
    ;}
    break;

  case 371:
#line 5036 "Gmsh.y"
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

  case 372:
#line 5092 "Gmsh.y"
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

  case 373:
#line 5162 "Gmsh.y"
    {
      yymsg(1, "Elliptic Surface is deprecated: use Transfinite instead (with smoothing)");
      List_Delete((yyvsp[(7) - (8)].l));
    ;}
    break;

  case 374:
#line 5167 "Gmsh.y"
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

  case 375:
#line 5234 "Gmsh.y"
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

  case 376:
#line 5270 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (8)].l)); i++){
	double d;
	List_Read((yyvsp[(4) - (8)].l), i, &d);
	CTX::instance()->mesh.algo2d_per_face[(int)d] = (int)(yyvsp[(7) - (8)].d);
      }
    ;}
    break;

  case 377:
#line 5278 "Gmsh.y"
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

  case 378:
#line 5321 "Gmsh.y"
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

  case 379:
#line 5360 "Gmsh.y"
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

  case 380:
#line 5381 "Gmsh.y"
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

  case 381:
#line 5413 "Gmsh.y"
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

  case 382:
#line 5440 "Gmsh.y"
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

  case 383:
#line 5466 "Gmsh.y"
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

  case 384:
#line 5492 "Gmsh.y"
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

  case 385:
#line 5518 "Gmsh.y"
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

  case 386:
#line 5544 "Gmsh.y"
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

  case 387:
#line 5565 "Gmsh.y"
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

  case 388:
#line 5593 "Gmsh.y"
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

  case 389:
#line 5621 "Gmsh.y"
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

  case 390:
#line 5649 "Gmsh.y"
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

  case 391:
#line 5677 "Gmsh.y"
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

  case 392:
#line 5705 "Gmsh.y"
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

  case 393:
#line 5744 "Gmsh.y"
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

  case 394:
#line 5783 "Gmsh.y"
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

  case 395:
#line 5804 "Gmsh.y"
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

  case 396:
#line 5825 "Gmsh.y"
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

  case 397:
#line 5852 "Gmsh.y"
    {
      ReplaceAllDuplicates();
    ;}
    break;

  case 398:
#line 5856 "Gmsh.y"
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

  case 399:
#line 5866 "Gmsh.y"
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

  case 400:
#line 5900 "Gmsh.y"
    { (yyval.c) = (char*)"Homology"; ;}
    break;

  case 401:
#line 5901 "Gmsh.y"
    { (yyval.c) = (char*)"Cohomology"; ;}
    break;

  case 402:
#line 5902 "Gmsh.y"
    { (yyval.c) = (char*)"Betti"; ;}
    break;

  case 403:
#line 5907 "Gmsh.y"
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest((yyvsp[(1) - (2)].c), domain, subdomain, dim);
    ;}
    break;

  case 404:
#line 5913 "Gmsh.y"
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

  case 405:
#line 5925 "Gmsh.y"
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

  case 406:
#line 5943 "Gmsh.y"
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

  case 407:
#line 5970 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d);           ;}
    break;

  case 408:
#line 5971 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (3)].d);           ;}
    break;

  case 409:
#line 5972 "Gmsh.y"
    { (yyval.d) = -(yyvsp[(2) - (2)].d);          ;}
    break;

  case 410:
#line 5973 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);           ;}
    break;

  case 411:
#line 5974 "Gmsh.y"
    { (yyval.d) = !(yyvsp[(2) - (2)].d);          ;}
    break;

  case 412:
#line 5975 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) - (yyvsp[(3) - (3)].d);      ;}
    break;

  case 413:
#line 5976 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) + (yyvsp[(3) - (3)].d);      ;}
    break;

  case 414:
#line 5977 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) * (yyvsp[(3) - (3)].d);      ;}
    break;

  case 415:
#line 5979 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (3)].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));
      else
	(yyval.d) = (yyvsp[(1) - (3)].d) / (yyvsp[(3) - (3)].d);
    ;}
    break;

  case 416:
#line 5985 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) % (int)(yyvsp[(3) - (3)].d);  ;}
    break;

  case 417:
#line 5986 "Gmsh.y"
    { (yyval.d) = pow((yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));  ;}
    break;

  case 418:
#line 5987 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d);      ;}
    break;

  case 419:
#line 5988 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) > (yyvsp[(3) - (3)].d);      ;}
    break;

  case 420:
#line 5989 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) <= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 421:
#line 5990 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) >= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 422:
#line 5991 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) == (yyvsp[(3) - (3)].d);     ;}
    break;

  case 423:
#line 5992 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) != (yyvsp[(3) - (3)].d);     ;}
    break;

  case 424:
#line 5993 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) && (yyvsp[(3) - (3)].d);     ;}
    break;

  case 425:
#line 5994 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) || (yyvsp[(3) - (3)].d);     ;}
    break;

  case 426:
#line 5995 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (5)].d) ? (yyvsp[(3) - (5)].d) : (yyvsp[(5) - (5)].d); ;}
    break;

  case 427:
#line 5996 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 428:
#line 5997 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 429:
#line 5998 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 430:
#line 5999 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 431:
#line 6000 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 432:
#line 6001 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 433:
#line 6002 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 434:
#line 6003 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 435:
#line 6004 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 436:
#line 6005 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 437:
#line 6006 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 438:
#line 6007 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 439:
#line 6008 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 440:
#line 6009 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 441:
#line 6010 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 442:
#line 6011 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 443:
#line 6012 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 444:
#line 6013 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d) + 0.5); ;}
    break;

  case 445:
#line 6014 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 446:
#line 6015 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 447:
#line 6016 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 448:
#line 6017 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 449:
#line 6026 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 450:
#line 6027 "Gmsh.y"
    { (yyval.d) = 3.141592653589793; ;}
    break;

  case 451:
#line 6028 "Gmsh.y"
    { (yyval.d) = (double)ImbricatedTest; ;}
    break;

  case 452:
#line 6029 "Gmsh.y"
    { (yyval.d) = Msg::GetCommRank(); ;}
    break;

  case 453:
#line 6030 "Gmsh.y"
    { (yyval.d) = Msg::GetCommSize(); ;}
    break;

  case 454:
#line 6031 "Gmsh.y"
    { (yyval.d) = GetGmshMajorVersion(); ;}
    break;

  case 455:
#line 6032 "Gmsh.y"
    { (yyval.d) = GetGmshMinorVersion(); ;}
    break;

  case 456:
#line 6033 "Gmsh.y"
    { (yyval.d) = GetGmshPatchVersion(); ;}
    break;

  case 457:
#line 6034 "Gmsh.y"
    { (yyval.d) = Cpu(); ;}
    break;

  case 458:
#line 6035 "Gmsh.y"
    { (yyval.d) = GetMemoryUsage()/1024./1024.; ;}
    break;

  case 459:
#line 6036 "Gmsh.y"
    { (yyval.d) = TotalRam(); ;}
    break;

  case 460:
#line 6041 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 461:
#line 6043 "Gmsh.y"
    {
      std::vector<double> val(1, (yyvsp[(3) - (6)].d));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.d) = val[0];
    ;}
    break;

  case 462:
#line 6049 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 463:
#line 6054 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 464:
#line 6059 "Gmsh.y"
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

  case 465:
#line 6076 "Gmsh.y"
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
#line 6094 "Gmsh.y"
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
#line 6112 "Gmsh.y"
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
#line 6130 "Gmsh.y"
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
#line 6148 "Gmsh.y"
    {
      (yyval.d) = gmsh_yysymbols.count((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 470:
#line 6153 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.d) = !StatFile(tmp);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 471:
#line 6159 "Gmsh.y"
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

  case 472:
#line 6174 "Gmsh.y"
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

  case 473:
#line 6193 "Gmsh.y"
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
#line 6213 "Gmsh.y"
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
#line 6233 "Gmsh.y"
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
#line 6253 "Gmsh.y"
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
#line 6276 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), (yyval.d));
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 478:
#line 6281 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), (yyval.d));
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 479:
#line 6286 "Gmsh.y"
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

  case 480:
#line 6296 "Gmsh.y"
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

  case 481:
#line 6306 "Gmsh.y"
    {
      (yyval.d) = Msg::GetValue((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 482:
#line 6311 "Gmsh.y"
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

  case 483:
#line 6322 "Gmsh.y"
    {
      std::string s((yyvsp[(3) - (6)].c)), substr((yyvsp[(5) - (6)].c));
      if(s.find(substr) != std::string::npos)
        (yyval.d) = 1.;
      else
        (yyval.d) = 0.;
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 484:
#line 6331 "Gmsh.y"
    {
      (yyval.d) = strlen((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 485:
#line 6336 "Gmsh.y"
    {
      (yyval.d) = strcmp((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 486:
#line 6341 "Gmsh.y"
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

  case 487:
#line 6368 "Gmsh.y"
    {
      memcpy((yyval.v), (yyvsp[(1) - (1)].v), 5*sizeof(double));
    ;}
    break;

  case 488:
#line 6372 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 489:
#line 6376 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 490:
#line 6380 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] - (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 491:
#line 6384 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] + (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 492:
#line 6391 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (11)].d);  (yyval.v)[1] = (yyvsp[(4) - (11)].d);  (yyval.v)[2] = (yyvsp[(6) - (11)].d);  (yyval.v)[3] = (yyvsp[(8) - (11)].d); (yyval.v)[4] = (yyvsp[(10) - (11)].d);
    ;}
    break;

  case 493:
#line 6395 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (9)].d);  (yyval.v)[1] = (yyvsp[(4) - (9)].d);  (yyval.v)[2] = (yyvsp[(6) - (9)].d);  (yyval.v)[3] = (yyvsp[(8) - (9)].d); (yyval.v)[4] = 1.0;
    ;}
    break;

  case 494:
#line 6399 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 495:
#line 6403 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 496:
#line 6410 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].l)));
    ;}
    break;

  case 497:
#line 6415 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].l)));
    ;}
    break;

  case 498:
#line 6422 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 499:
#line 6427 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 500:
#line 6431 "Gmsh.y"
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    ;}
    break;

  case 501:
#line 6436 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 502:
#line 6440 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 503:
#line 6448 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (5)].d);
      }
    ;}
    break;

  case 504:
#line 6459 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 505:
#line 6463 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(1) - (1)].c), "*") || !strcmp((yyvsp[(1) - (1)].c), "all"))
        (yyval.l) = 0;
      else{
        yyerror("Unknown special string for list replacement");
        (yyval.l) = List_Create(2, 1, sizeof(double));
      }
    ;}
    break;

  case 506:
#line 6475 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 507:
#line 6483 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (3)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (3)].d);
      }
    ;}
    break;

  case 508:
#line 6491 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      for(double d = (yyvsp[(1) - (3)].d); ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d <= (yyvsp[(3) - (3)].d)) : (d >= (yyvsp[(3) - (3)].d));
          ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d += 1.) : (d -= 1.))
	List_Add((yyval.l), &d);
    ;}
    break;

  case 509:
#line 6498 "Gmsh.y"
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

  case 510:
#line 6508 "Gmsh.y"
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

  case 511:
#line 6537 "Gmsh.y"
    {
      (yyval.l) = GetAllElementaryEntityNumbers(0);
    ;}
    break;

  case 512:
#line 6541 "Gmsh.y"
    {
      (yyval.l) = GetAllElementaryEntityNumbers(1);
    ;}
    break;

  case 513:
#line 6545 "Gmsh.y"
    {
      (yyval.l) = GetAllElementaryEntityNumbers(2);
    ;}
    break;

  case 514:
#line 6549 "Gmsh.y"
    {
      (yyval.l) = GetAllElementaryEntityNumbers(3);
    ;}
    break;

  case 515:
#line 6553 "Gmsh.y"
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(0);
    ;}
    break;

  case 516:
#line 6557 "Gmsh.y"
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(1);
    ;}
    break;

  case 517:
#line 6561 "Gmsh.y"
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(2);
    ;}
    break;

  case 518:
#line 6565 "Gmsh.y"
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(3);
    ;}
    break;

  case 519:
#line 6569 "Gmsh.y"
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

  case 520:
#line 6598 "Gmsh.y"
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

  case 521:
#line 6627 "Gmsh.y"
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

  case 522:
#line 6656 "Gmsh.y"
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

  case 523:
#line 6686 "Gmsh.y"
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

  case 524:
#line 6699 "Gmsh.y"
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

  case 525:
#line 6712 "Gmsh.y"
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

  case 526:
#line 6725 "Gmsh.y"
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

  case 527:
#line 6737 "Gmsh.y"
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

  case 528:
#line 6747 "Gmsh.y"
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
#line 6757 "Gmsh.y"
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
#line 6767 "Gmsh.y"
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

  case 531:
#line 6779 "Gmsh.y"
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
#line 6792 "Gmsh.y"
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

  case 533:
#line 6804 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 534:
#line 6808 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 535:
#line 6812 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (6)].l);
    ;}
    break;

  case 536:
#line 6816 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (6)].l);
    ;}
    break;

  case 537:
#line 6820 "Gmsh.y"
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

  case 538:
#line 6838 "Gmsh.y"
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
#line 6856 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = (yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1);
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 540:
#line 6864 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = pow(10,(yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1));
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 541:
#line 6872 "Gmsh.y"
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

  case 542:
#line 6901 "Gmsh.y"
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

  case 543:
#line 6911 "Gmsh.y"
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

  case 544:
#line 6930 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 545:
#line 6935 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 546:
#line 6939 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].d)));
    ;}
    break;

  case 547:
#line 6943 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (3)].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 548:
#line 6955 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (9)].d), (int)(yyvsp[(4) - (9)].d), (int)(yyvsp[(6) - (9)].d), (int)(yyvsp[(8) - (9)].d));
    ;}
    break;

  case 549:
#line 6959 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (7)].d), (int)(yyvsp[(4) - (7)].d), (int)(yyvsp[(6) - (7)].d), 255);
    ;}
    break;

  case 550:
#line 6971 "Gmsh.y"
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

  case 551:
#line 6988 "Gmsh.y"
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(5) - (5)].c), val);
      (yyval.u) = val;
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(5) - (5)].c));
    ;}
    break;

  case 552:
#line 6998 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 553:
#line 7002 "Gmsh.y"
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

  case 554:
#line 7017 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].u)));
    ;}
    break;

  case 555:
#line 7022 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].u)));
    ;}
    break;

  case 556:
#line 7029 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 557:
#line 7033 "Gmsh.y"
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

  case 558:
#line 7046 "Gmsh.y"
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
#line 7060 "Gmsh.y"
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
#line 7074 "Gmsh.y"
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
#line 7088 "Gmsh.y"
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
#line 7102 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 563:
#line 7110 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 564:
#line 7121 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 565:
#line 7125 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 566:
#line 7129 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    ;}
    break;

  case 567:
#line 7137 "Gmsh.y"
    {
      std::string exe = Msg::GetExecutableName();
      (yyval.c) = (char *)Malloc(exe.size() + 1);
      strcpy((yyval.c), exe.c_str());
    ;}
    break;

  case 568:
#line 7143 "Gmsh.y"
    {
      std::string action = Msg::GetOnelabAction();
      (yyval.c) = (char *)Malloc(action.size() + 1);
      strcpy((yyval.c), action.c_str());
    ;}
    break;

  case 569:
#line 7149 "Gmsh.y"
    {
      const char *env = GetEnvironmentVar((yyvsp[(3) - (4)].c));
      if(!env) env = "";
      (yyval.c) = (char *)Malloc((sizeof(env) + 1) * sizeof(char));
      strcpy((yyval.c), env);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 570:
#line 7157 "Gmsh.y"
    {
      std::string s = Msg::GetString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 571:
#line 7165 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (4)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 572:
#line 7172 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 573:
#line 7180 "Gmsh.y"
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

  case 574:
#line 7195 "Gmsh.y"
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

  case 575:
#line 7209 "Gmsh.y"
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

  case 576:
#line 7223 "Gmsh.y"
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

  case 577:
#line 7235 "Gmsh.y"
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

  case 578:
#line 7251 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = toupper((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 579:
#line 7260 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = tolower((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 580:
#line 7269 "Gmsh.y"
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

  case 581:
#line 7279 "Gmsh.y"
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

  case 582:
#line 7290 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (8)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (8)].d), (int)(yyvsp[(7) - (8)].d));
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (8)].c));
    ;}
    break;

  case 583:
#line 7298 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (6)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (6)].d), std::string::npos);
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 584:
#line 7306 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 585:
#line 7310 "Gmsh.y"
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

  case 586:
#line 7329 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 587:
#line 7336 "Gmsh.y"
    {
      std::string tmp = SplitFileName(GetAbsolutePath(gmsh_yyname))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
    ;}
    break;

  case 588:
#line 7342 "Gmsh.y"
    {
      std::string tmp = SplitFileName((yyvsp[(3) - (4)].c))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 589:
#line 7349 "Gmsh.y"
    {
      std::string tmp = GetAbsolutePath((yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 590:
#line 7356 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 591:
#line 7358 "Gmsh.y"
    {
      std::string val((yyvsp[(3) - (6)].c));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.c) = (char*)Malloc((val.size() + 1) * sizeof(char));
      strcpy((yyval.c), val.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 592:
#line 7369 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].c)));
    ;}
    break;

  case 593:
#line 7374 "Gmsh.y"
    { List_Add((yyval.l), &((yyvsp[(3) - (3)].c))); ;}
    break;

  case 594:
#line 7380 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 595:
#line 7389 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char)) ;
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)) ; strcat((yyval.c), tmpstr) ;
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 596:
#line 7402 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 597:
#line 7405 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 598:
#line 7409 "Gmsh.y"
    { (yyval.c) = (yyvsp[(3) - (4)].c); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 14898 "Gmsh.tab.cpp"
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


#line 7412 "Gmsh.y"


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

