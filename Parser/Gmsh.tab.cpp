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
#define YYLAST   14885

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  237
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  105
/* YYNRULES -- Number of rules.  */
#define YYNRULES  597
/* YYNRULES -- Number of states.  */
#define YYNSTATES  2235

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
     946,   954,   966,   975,   980,   989,   998,  1007,  1017,  1021,
    1026,  1037,  1045,  1053,  1061,  1069,  1077,  1085,  1093,  1101,
    1109,  1117,  1126,  1131,  1140,  1153,  1162,  1171,  1179,  1187,
    1196,  1201,  1210,  1219,  1225,  1237,  1243,  1253,  1263,  1268,
    1278,  1288,  1290,  1292,  1293,  1296,  1303,  1310,  1317,  1324,
    1333,  1344,  1359,  1376,  1389,  1404,  1419,  1434,  1449,  1458,
    1467,  1474,  1479,  1486,  1493,  1497,  1502,  1508,  1515,  1521,
    1525,  1529,  1534,  1540,  1545,  1551,  1555,  1561,  1569,  1577,
    1581,  1589,  1593,  1596,  1599,  1602,  1605,  1608,  1624,  1627,
    1630,  1633,  1636,  1639,  1656,  1668,  1675,  1684,  1693,  1704,
    1706,  1709,  1712,  1714,  1718,  1722,  1727,  1732,  1734,  1736,
    1742,  1754,  1768,  1769,  1777,  1778,  1792,  1793,  1809,  1810,
    1817,  1827,  1830,  1834,  1845,  1854,  1863,  1872,  1885,  1898,
    1911,  1926,  1941,  1956,  1957,  1970,  1971,  1984,  1985,  1998,
    1999,  2016,  2017,  2034,  2035,  2052,  2053,  2072,  2073,  2092,
    2093,  2112,  2114,  2117,  2123,  2131,  2141,  2144,  2147,  2151,
    2154,  2158,  2161,  2165,  2168,  2172,  2175,  2179,  2189,  2196,
    2198,  2200,  2202,  2204,  2206,  2207,  2210,  2214,  2224,  2229,
    2244,  2245,  2249,  2250,  2252,  2253,  2256,  2257,  2260,  2261,
    2264,  2272,  2279,  2288,  2294,  2298,  2307,  2313,  2318,  2325,
    2337,  2349,  2368,  2387,  2400,  2413,  2426,  2437,  2448,  2459,
    2470,  2481,  2486,  2491,  2496,  2501,  2506,  2509,  2513,  2520,
    2522,  2524,  2526,  2529,  2535,  2543,  2554,  2556,  2560,  2563,
    2566,  2569,  2573,  2577,  2581,  2585,  2589,  2593,  2597,  2601,
    2605,  2609,  2613,  2617,  2621,  2625,  2631,  2636,  2641,  2646,
    2651,  2656,  2661,  2666,  2671,  2676,  2681,  2688,  2693,  2698,
    2703,  2708,  2713,  2718,  2723,  2730,  2737,  2744,  2749,  2751,
    2753,  2755,  2757,  2759,  2761,  2763,  2765,  2767,  2769,  2771,
    2772,  2779,  2784,  2791,  2793,  2798,  2803,  2808,  2813,  2818,
    2823,  2828,  2831,  2837,  2843,  2849,  2855,  2859,  2866,  2871,
    2879,  2886,  2893,  2900,  2905,  2912,  2917,  2919,  2922,  2925,
    2929,  2933,  2945,  2955,  2963,  2971,  2973,  2977,  2979,  2981,
    2984,  2988,  2993,  2999,  3001,  3003,  3006,  3010,  3014,  3020,
    3025,  3028,  3031,  3034,  3037,  3041,  3045,  3049,  3053,  3059,
    3065,  3071,  3077,  3094,  3111,  3128,  3145,  3147,  3149,  3151,
    3155,  3159,  3164,  3169,  3174,  3181,  3188,  3195,  3202,  3211,
    3220,  3225,  3240,  3245,  3247,  3249,  3253,  3257,  3267,  3275,
    3277,  3283,  3287,  3294,  3296,  3300,  3302,  3304,  3309,  3314,
    3319,  3324,  3328,  3335,  3337,  3342,  3344,  3346,  3348,  3353,
    3360,  3365,  3372,  3377,  3382,  3387,  3396,  3401,  3406,  3411,
    3416,  3425,  3434,  3441,  3446,  3453,  3458,  3460,  3465,  3470,
    3471,  3478,  3480,  3484,  3490,  3496,  3498,  3500
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
     227,   323,   228,     7,   329,     6,    -1,   115,    90,   227,
     323,   228,     7,   329,   280,     6,    -1,    12,    13,     6,
      -1,    13,    90,   323,     6,    -1,   104,    90,   227,   323,
     228,     7,     5,     5,     5,     6,    -1,    88,   227,   323,
     228,     7,   329,     6,    -1,    89,   227,   323,   228,     7,
     329,     6,    -1,    93,   227,   323,   228,     7,   329,     6,
      -1,    96,   227,   323,   228,     7,   329,     6,    -1,   100,
     227,   323,   228,     7,   329,     6,    -1,   101,   227,   323,
     228,     7,   329,     6,    -1,    94,   227,   323,   228,     7,
     329,     6,    -1,    95,   227,   323,   228,     7,   329,     6,
      -1,   111,   227,   323,   228,     7,   329,     6,    -1,   137,
     227,   323,   228,     7,   329,     6,    -1,    90,     4,   227,
     323,   228,     7,   329,     6,    -1,   119,    90,   329,     6,
      -1,   119,    90,   227,   323,   228,     7,   329,     6,    -1,
     119,    90,   227,   323,   228,     7,   329,     4,   234,   328,
     235,     6,    -1,   118,    90,   227,   278,   228,   259,   329,
       6,    -1,   117,    92,   227,   323,   228,     7,   329,     6,
      -1,    92,   227,   323,   228,     7,   329,     6,    -1,   110,
     227,   323,   228,     7,   329,     6,    -1,   115,   110,   227,
     323,   228,     7,   329,     6,    -1,   119,    92,   329,     6,
      -1,   119,    92,   227,   323,   228,     7,   329,     6,    -1,
     118,    92,   227,   279,   228,   259,   329,     6,    -1,   126,
     326,   234,   284,   235,    -1,   125,   234,   326,   233,   326,
     233,   323,   235,   234,   284,   235,    -1,   127,   326,   234,
     284,   235,    -1,   128,   234,   326,   233,   323,   235,   234,
     284,   235,    -1,   128,   234,   326,   233,   326,   235,   234,
     284,   235,    -1,     4,   234,   284,   235,    -1,   143,    87,
     234,   332,   235,    90,   234,   323,   235,    -1,   140,    87,
     227,   323,   228,   234,   332,   235,     6,    -1,   285,    -1,
     283,    -1,    -1,   285,   282,    -1,   285,    84,   234,   332,
     235,     6,    -1,   285,    87,   234,   332,   235,     6,    -1,
     285,    90,   234,   332,   235,     6,    -1,   285,    92,   234,
     332,   235,     6,    -1,   130,   114,   227,   323,   228,     7,
     329,     6,    -1,   130,    84,   227,   323,   228,     7,   234,
     328,   235,     6,    -1,   130,   114,   227,   323,   228,     7,
     234,   326,   233,   326,   233,   332,   235,     6,    -1,   130,
     114,   227,   323,   228,     7,   234,   326,   233,   326,   233,
     326,   233,   332,   235,     6,    -1,   130,    88,   227,   323,
     228,     7,   234,   326,   233,   332,   235,     6,    -1,   130,
      94,   227,   323,   228,     7,   234,   326,   233,   326,   233,
     332,   235,     6,    -1,   130,    95,   227,   323,   228,     7,
     234,   326,   233,   326,   233,   332,   235,     6,    -1,   130,
      97,   227,   323,   228,     7,   234,   326,   233,   326,   233,
     332,   235,     6,    -1,   130,    98,   227,   323,   228,     7,
     234,   326,   233,   326,   233,   332,   235,     6,    -1,   130,
       4,   227,   323,   228,     7,   329,     6,    -1,   130,     4,
     227,   323,   228,     7,     5,     6,    -1,   130,     4,   234,
     323,   235,     6,    -1,   141,   234,   285,   235,    -1,   141,
     179,   229,   323,   230,     6,    -1,   141,     4,   229,   323,
     230,     6,    -1,   141,   341,     6,    -1,   141,     4,     4,
       6,    -1,   168,   333,   234,   285,   235,    -1,   124,   168,
     333,   234,   285,   235,    -1,   201,   323,   234,   285,   235,
      -1,   184,     5,     6,    -1,   185,     5,     6,    -1,   184,
     234,   285,   235,    -1,   124,   184,   234,   285,   235,    -1,
     185,   234,   285,   235,    -1,   124,   185,   234,   285,   235,
      -1,     4,   337,     6,    -1,    71,   227,   339,   228,     6,
      -1,     4,     4,   229,   323,   230,   336,     6,    -1,     4,
       4,     4,   229,   323,   230,     6,    -1,     4,   323,     6,
      -1,   122,   227,     4,   228,   231,     4,     6,    -1,   162,
       4,     6,    -1,   177,     6,    -1,   178,     6,    -1,    68,
       6,    -1,    69,     6,    -1,    62,     6,    -1,    62,   234,
     323,   233,   323,   233,   323,   233,   323,   233,   323,   233,
     323,   235,     6,    -1,    63,     6,    -1,    64,     6,    -1,
      75,     6,    -1,    76,     6,    -1,   106,     6,    -1,   107,
     234,   332,   235,   234,   332,   235,   234,   328,   235,   234,
     323,   233,   323,   235,     6,    -1,   182,   227,   234,   332,
     235,   233,   337,   233,   337,   228,     6,    -1,   170,   227,
     323,     8,   323,   228,    -1,   170,   227,   323,     8,   323,
       8,   323,   228,    -1,   170,     4,   171,   234,   323,     8,
     323,   235,    -1,   170,     4,   171,   234,   323,     8,   323,
       8,   323,   235,    -1,   172,    -1,   183,     4,    -1,   183,
     337,    -1,   180,    -1,   181,   341,     6,    -1,   181,   337,
       6,    -1,   173,   227,   323,   228,    -1,   174,   227,   323,
     228,    -1,   175,    -1,   176,    -1,   129,   326,   234,   285,
     235,    -1,   129,   234,   326,   233,   326,   233,   323,   235,
     234,   285,   235,    -1,   129,   234,   326,   233,   326,   233,
     326,   233,   323,   235,   234,   285,   235,    -1,    -1,   129,
     326,   234,   285,   295,   308,   235,    -1,    -1,   129,   234,
     326,   233,   326,   233,   323,   235,   234,   285,   296,   308,
     235,    -1,    -1,   129,   234,   326,   233,   326,   233,   326,
     233,   323,   235,   234,   285,   297,   308,   235,    -1,    -1,
     129,   234,   285,   298,   308,   235,    -1,   129,   234,   285,
     235,   121,    87,   234,   329,   235,    -1,   110,   329,    -1,
     115,   110,   329,    -1,   112,   234,   332,   235,   234,   332,
     235,   234,   323,   235,    -1,   129,    84,   234,   323,   233,
     326,   235,     6,    -1,   129,    87,   234,   323,   233,   326,
     235,     6,    -1,   129,    90,   234,   323,   233,   326,   235,
       6,    -1,   129,    84,   234,   323,   233,   326,   233,   326,
     233,   323,   235,     6,    -1,   129,    87,   234,   323,   233,
     326,   233,   326,   233,   323,   235,     6,    -1,   129,    90,
     234,   323,   233,   326,   233,   326,   233,   323,   235,     6,
      -1,   129,    84,   234,   323,   233,   326,   233,   326,   233,
     326,   233,   323,   235,     6,    -1,   129,    87,   234,   323,
     233,   326,   233,   326,   233,   326,   233,   323,   235,     6,
      -1,   129,    90,   234,   323,   233,   326,   233,   326,   233,
     326,   233,   323,   235,     6,    -1,    -1,   129,    84,   234,
     323,   233,   326,   235,   299,   234,   308,   235,     6,    -1,
      -1,   129,    87,   234,   323,   233,   326,   235,   300,   234,
     308,   235,     6,    -1,    -1,   129,    90,   234,   323,   233,
     326,   235,   301,   234,   308,   235,     6,    -1,    -1,   129,
      84,   234,   323,   233,   326,   233,   326,   233,   323,   235,
     302,   234,   308,   235,     6,    -1,    -1,   129,    87,   234,
     323,   233,   326,   233,   326,   233,   323,   235,   303,   234,
     308,   235,     6,    -1,    -1,   129,    90,   234,   323,   233,
     326,   233,   326,   233,   323,   235,   304,   234,   308,   235,
       6,    -1,    -1,   129,    84,   234,   323,   233,   326,   233,
     326,   233,   326,   233,   323,   235,   305,   234,   308,   235,
       6,    -1,    -1,   129,    87,   234,   323,   233,   326,   233,
     326,   233,   326,   233,   323,   235,   306,   234,   308,   235,
       6,    -1,    -1,   129,    90,   234,   323,   233,   326,   233,
     326,   233,   326,   233,   323,   235,   307,   234,   308,   235,
       6,    -1,   309,    -1,   308,   309,    -1,   146,   234,   323,
     235,     6,    -1,   146,   234,   329,   233,   329,   235,     6,
      -1,   146,   234,   329,   233,   329,   233,   329,   235,     6,
      -1,   147,     6,    -1,   138,     6,    -1,   138,   323,     6,
      -1,   154,     6,    -1,   154,   156,     6,    -1,   155,     6,
      -1,   155,   156,     6,    -1,   152,     6,    -1,   152,   156,
       6,    -1,   153,     6,    -1,   153,   156,     6,    -1,   148,
     227,   323,   228,     7,   329,   121,   323,     6,    -1,   121,
       4,   229,   323,   230,     6,    -1,   132,    -1,   133,    -1,
     134,    -1,   135,    -1,   136,    -1,    -1,   141,     6,    -1,
     141,   323,     6,    -1,   310,   234,   285,   311,   235,   234,
     285,   311,   235,    -1,    99,   227,   336,   228,    -1,   310,
     227,   323,   228,     7,   234,   285,   311,   235,   234,   285,
     311,   235,     6,    -1,    -1,   121,     4,   323,    -1,    -1,
       4,    -1,    -1,     7,   329,    -1,    -1,     7,   323,    -1,
      -1,   131,   329,    -1,   116,    87,   330,     7,   323,   314,
       6,    -1,   116,    90,   330,   316,   315,     6,    -1,   105,
      90,   234,   323,   235,     7,   329,     6,    -1,   116,    92,
     330,   316,     6,    -1,   157,   330,     6,    -1,   144,    90,
     234,   332,   235,     7,   323,     6,    -1,   138,    90,   330,
     317,     6,    -1,   138,    92,   330,     6,    -1,   139,    90,
     329,     7,   323,     6,    -1,   120,    87,   234,   332,   235,
       7,   234,   332,   235,   318,     6,    -1,   120,    90,   234,
     332,   235,     7,   234,   332,   235,   318,     6,    -1,   120,
      87,   234,   332,   235,     7,   234,   332,   235,   125,   234,
     326,   233,   326,   233,   323,   235,     6,    -1,   120,    90,
     234,   332,   235,     7,   234,   332,   235,   125,   234,   326,
     233,   326,   233,   323,   235,     6,    -1,   120,    87,   234,
     332,   235,     7,   234,   332,   235,   126,   326,     6,    -1,
     120,    90,   234,   332,   235,     7,   234,   332,   235,   126,
     326,     6,    -1,   120,    90,   323,   234,   332,   235,     7,
     323,   234,   332,   235,     6,    -1,    84,   234,   332,   235,
     171,    90,   234,   323,   235,     6,    -1,    87,   234,   332,
     235,   171,    90,   234,   323,   235,     6,    -1,    84,   234,
     332,   235,   171,    92,   234,   323,   235,     6,    -1,    87,
     234,   332,   235,   171,    92,   234,   323,   235,     6,    -1,
      90,   234,   332,   235,   171,    92,   234,   323,   235,     6,
      -1,   145,    90,   330,     6,    -1,   145,    87,   330,     6,
      -1,   108,    84,   330,     6,    -1,   108,    87,   330,     6,
      -1,   108,    90,   330,     6,    -1,   142,     6,    -1,   142,
       4,     6,    -1,   142,    84,   234,   332,   235,     6,    -1,
     192,    -1,   193,    -1,   194,    -1,   321,     6,    -1,   321,
     234,   329,   235,     6,    -1,   321,   234,   329,   233,   329,
     235,     6,    -1,   321,   227,   329,   228,   234,   329,   233,
     329,   235,     6,    -1,   324,    -1,   227,   323,   228,    -1,
     218,   323,    -1,   217,   323,    -1,   222,   323,    -1,   323,
     218,   323,    -1,   323,   217,   323,    -1,   323,   219,   323,
      -1,   323,   220,   323,    -1,   323,   221,   323,    -1,   323,
     226,   323,    -1,   323,   213,   323,    -1,   323,   214,   323,
      -1,   323,   216,   323,    -1,   323,   215,   323,    -1,   323,
     212,   323,    -1,   323,   211,   323,    -1,   323,   210,   323,
      -1,   323,   209,   323,    -1,   323,   208,   323,     8,   323,
      -1,    15,   261,   323,   262,    -1,    16,   261,   323,   262,
      -1,    17,   261,   323,   262,    -1,    18,   261,   323,   262,
      -1,    19,   261,   323,   262,    -1,    20,   261,   323,   262,
      -1,    21,   261,   323,   262,    -1,    22,   261,   323,   262,
      -1,    23,   261,   323,   262,    -1,    25,   261,   323,   262,
      -1,    26,   261,   323,   233,   323,   262,    -1,    27,   261,
     323,   262,    -1,    28,   261,   323,   262,    -1,    29,   261,
     323,   262,    -1,    30,   261,   323,   262,    -1,    31,   261,
     323,   262,    -1,    32,   261,   323,   262,    -1,    33,   261,
     323,   262,    -1,    34,   261,   323,   233,   323,   262,    -1,
      35,   261,   323,   233,   323,   262,    -1,    36,   261,   323,
     233,   323,   262,    -1,    24,   261,   323,   262,    -1,     3,
      -1,     9,    -1,    14,    -1,    10,    -1,    11,    -1,   197,
      -1,   198,    -1,   199,    -1,    72,    -1,    73,    -1,    74,
      -1,    -1,    80,   261,   323,   325,   272,   262,    -1,   190,
     261,   336,   262,    -1,   190,   261,   336,   233,   323,   262,
      -1,   341,    -1,     4,   229,   323,   230,    -1,     4,   227,
     323,   228,    -1,   340,   229,   323,   230,    -1,   340,   227,
     323,   228,    -1,   195,   227,   341,   228,    -1,   196,   227,
     337,   228,    -1,   232,   341,   261,   262,    -1,   341,   260,
      -1,     4,   229,   323,   230,   260,    -1,     4,   227,   323,
     228,   260,    -1,   340,   229,   323,   230,   260,    -1,   340,
     227,   323,   228,   260,    -1,     4,   231,     4,    -1,     4,
     229,   323,   230,   231,     4,    -1,     4,   231,     4,   260,
      -1,     4,   229,   323,   230,   231,     4,   260,    -1,   186,
     227,   336,   233,   323,   228,    -1,    54,   227,   329,   233,
     329,   228,    -1,    55,   261,   336,   233,   336,   262,    -1,
      53,   261,   336,   262,    -1,    56,   261,   336,   233,   336,
     262,    -1,    61,   227,   339,   228,    -1,   327,    -1,   218,
     326,    -1,   217,   326,    -1,   326,   218,   326,    -1,   326,
     217,   326,    -1,   234,   323,   233,   323,   233,   323,   233,
     323,   233,   323,   235,    -1,   234,   323,   233,   323,   233,
     323,   233,   323,   235,    -1,   234,   323,   233,   323,   233,
     323,   235,    -1,   227,   323,   233,   323,   233,   323,   228,
      -1,   329,    -1,   328,   233,   329,    -1,   323,    -1,   331,
      -1,   234,   235,    -1,   234,   332,   235,    -1,   218,   234,
     332,   235,    -1,   323,   219,   234,   332,   235,    -1,   329,
      -1,     5,    -1,   218,   331,    -1,   323,   219,   331,    -1,
     323,     8,   323,    -1,   323,     8,   323,     8,   323,    -1,
      84,   234,   323,   235,    -1,    84,     5,    -1,    87,     5,
      -1,    90,     5,    -1,    92,     5,    -1,   118,    84,     5,
      -1,   118,    87,     5,    -1,   118,    90,     5,    -1,   118,
      92,     5,    -1,   118,    84,   234,   332,   235,    -1,   118,
      87,   234,   332,   235,    -1,   118,    90,   234,   332,   235,
      -1,   118,    92,   234,   332,   235,    -1,    84,   171,    62,
     234,   323,   233,   323,   233,   323,   233,   323,   233,   323,
     233,   323,   235,    -1,    87,   171,    62,   234,   323,   233,
     323,   233,   323,   233,   323,   233,   323,   233,   323,   235,
      -1,    90,   171,    62,   234,   323,   233,   323,   233,   323,
     233,   323,   233,   323,   233,   323,   235,    -1,    92,   171,
      62,   234,   323,   233,   323,   233,   323,   233,   323,   233,
     323,   233,   323,   235,    -1,   283,    -1,   294,    -1,   312,
      -1,     4,   261,   262,    -1,   340,   261,   262,    -1,    37,
     229,   341,   230,    -1,    37,   229,   331,   230,    -1,    37,
     227,   331,   228,    -1,    37,   229,   234,   332,   235,   230,
      -1,    37,   227,   234,   332,   235,   228,    -1,     4,   261,
     234,   332,   235,   262,    -1,   340,   261,   234,   332,   235,
     262,    -1,    38,   261,   323,   233,   323,   233,   323,   262,
      -1,    39,   261,   323,   233,   323,   233,   323,   262,    -1,
      40,   261,   336,   262,    -1,    41,   261,   323,   233,   323,
     233,   323,   233,   323,   233,   323,   233,   323,   262,    -1,
     191,   261,   331,   262,    -1,   323,    -1,   331,    -1,   332,
     233,   323,    -1,   332,   233,   331,    -1,   234,   323,   233,
     323,   233,   323,   233,   323,   235,    -1,   234,   323,   233,
     323,   233,   323,   235,    -1,   341,    -1,     4,   231,   168,
     231,     4,    -1,   234,   335,   235,    -1,     4,   229,   323,
     230,   231,   169,    -1,   333,    -1,   335,   233,   333,    -1,
     337,    -1,   341,    -1,     4,   229,   323,   230,    -1,   340,
     229,   323,   230,    -1,     4,   227,   323,   228,    -1,   340,
     227,   323,   228,    -1,     4,   231,     4,    -1,     4,   229,
     323,   230,   231,     4,    -1,     5,    -1,   202,   229,   341,
     230,    -1,    65,    -1,   200,    -1,    70,    -1,   188,   227,
     336,   228,    -1,   187,   227,   336,   233,   336,   228,    -1,
     189,   261,   336,   262,    -1,   189,   261,   336,   233,   336,
     262,    -1,    46,   261,   339,   262,    -1,    47,   227,   336,
     228,    -1,    48,   227,   336,   228,    -1,    49,   227,   336,
     233,   336,   233,   336,   228,    -1,    44,   261,   339,   262,
      -1,    58,   261,   336,   262,    -1,    59,   261,   336,   262,
      -1,    60,   261,   336,   262,    -1,    57,   261,   323,   233,
     336,   233,   336,   262,    -1,    52,   261,   336,   233,   323,
     233,   323,   262,    -1,    52,   261,   336,   233,   323,   262,
      -1,    45,   261,   336,   262,    -1,    45,   261,   336,   233,
     332,   262,    -1,    66,   261,   336,   262,    -1,    67,    -1,
      51,   261,   336,   262,    -1,    50,   261,   336,   262,    -1,
      -1,    81,   261,   337,   338,   274,   262,    -1,   336,    -1,
     339,   233,   336,    -1,     4,   236,   234,   323,   235,    -1,
     340,   236,   234,   323,   235,    -1,     4,    -1,   340,    -1,
     203,   229,   336,   230,    -1
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
    2039,  2066,  2093,  2122,  2127,  2145,  2191,  2219,  2269,  2275,
    2281,  2288,  2330,  2356,  2380,  2404,  2429,  2452,  2479,  2507,
    2532,  2555,  2582,  2586,  2605,  2639,  2686,  2704,  2731,  2750,
    2769,  2773,  2789,  2837,  2854,  2872,  2882,  2892,  2902,  2965,
    2976,  2992,  2993,  2998,  3001,  3005,  3034,  3063,  3092,  3126,
    3148,  3174,  3196,  3219,  3240,  3296,  3320,  3345,  3371,  3484,
    3503,  3546,  3567,  3573,  3588,  3616,  3633,  3642,  3656,  3670,
    3676,  3682,  3691,  3700,  3709,  3723,  3785,  3803,  3820,  3835,
    3864,  3876,  3900,  3904,  3909,  3917,  3922,  3928,  3933,  3939,
    3947,  3951,  3955,  3960,  4020,  4036,  4053,  4070,  4092,  4114,
    4149,  4157,  4165,  4171,  4178,  4185,  4205,  4231,  4243,  4255,
    4285,  4316,  4325,  4324,  4339,  4338,  4353,  4352,  4367,  4366,
    4379,  4412,  4435,  4458,  4489,  4496,  4503,  4510,  4517,  4524,
    4531,  4538,  4545,  4553,  4552,  4566,  4565,  4579,  4578,  4592,
    4591,  4605,  4604,  4618,  4617,  4631,  4630,  4644,  4643,  4657,
    4656,  4673,  4676,  4682,  4694,  4714,  4738,  4742,  4746,  4750,
    4754,  4758,  4764,  4770,  4774,  4778,  4782,  4786,  4805,  4818,
    4819,  4820,  4821,  4822,  4826,  4827,  4828,  4831,  4865,  4891,
    4915,  4918,  4934,  4937,  4954,  4957,  4963,  4966,  4973,  4976,
    4983,  5039,  5109,  5114,  5181,  5217,  5225,  5268,  5307,  5327,
    5359,  5386,  5412,  5438,  5464,  5490,  5512,  5540,  5568,  5596,
    5624,  5652,  5691,  5730,  5751,  5772,  5799,  5803,  5813,  5848,
    5849,  5850,  5854,  5860,  5872,  5890,  5918,  5919,  5920,  5921,
    5922,  5923,  5924,  5925,  5926,  5933,  5934,  5935,  5936,  5937,
    5938,  5939,  5940,  5941,  5942,  5943,  5944,  5945,  5946,  5947,
    5948,  5949,  5950,  5951,  5952,  5953,  5954,  5955,  5956,  5957,
    5958,  5959,  5960,  5961,  5962,  5963,  5964,  5965,  5974,  5975,
    5976,  5977,  5978,  5979,  5980,  5981,  5982,  5983,  5984,  5989,
    5988,  5996,  6001,  6006,  6023,  6041,  6059,  6077,  6095,  6100,
    6106,  6121,  6140,  6160,  6180,  6200,  6223,  6228,  6233,  6243,
    6253,  6258,  6269,  6278,  6283,  6288,  6315,  6319,  6323,  6327,
    6331,  6338,  6342,  6346,  6350,  6357,  6362,  6369,  6374,  6378,
    6383,  6387,  6395,  6406,  6410,  6422,  6430,  6438,  6445,  6455,
    6484,  6488,  6492,  6496,  6500,  6504,  6508,  6512,  6516,  6545,
    6574,  6603,  6632,  6645,  6658,  6671,  6684,  6694,  6704,  6714,
    6726,  6739,  6751,  6755,  6759,  6763,  6767,  6785,  6803,  6811,
    6819,  6848,  6858,  6877,  6882,  6886,  6890,  6902,  6906,  6918,
    6935,  6945,  6949,  6964,  6969,  6976,  6980,  6993,  7007,  7021,
    7035,  7049,  7057,  7068,  7072,  7076,  7084,  7090,  7096,  7104,
    7112,  7119,  7127,  7142,  7156,  7170,  7182,  7198,  7207,  7216,
    7226,  7237,  7245,  7253,  7257,  7276,  7283,  7289,  7296,  7304,
    7303,  7316,  7321,  7327,  7336,  7349,  7352,  7356
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
     282,   282,   282,   283,   283,   283,   283,   283,   283,   283,
     283,   284,   284,   285,   285,   285,   285,   285,   285,   286,
     286,   286,   286,   286,   286,   286,   286,   286,   286,   286,
     286,   287,   287,   287,   287,   287,   288,   288,   289,   290,
     290,   290,   290,   290,   290,   291,   291,   291,   291,   291,
     291,   291,   291,   291,   291,   291,   291,   291,   291,   291,
     291,   291,   291,   291,   292,   293,   293,   293,   293,   293,
     293,   293,   293,   293,   293,   293,   293,   293,   293,   294,
     294,   294,   295,   294,   296,   294,   297,   294,   298,   294,
     294,   294,   294,   294,   294,   294,   294,   294,   294,   294,
     294,   294,   294,   299,   294,   300,   294,   301,   294,   302,
     294,   303,   294,   304,   294,   305,   294,   306,   294,   307,
     294,   308,   308,   309,   309,   309,   309,   309,   309,   309,
     309,   309,   309,   309,   309,   309,   309,   309,   309,   310,
     310,   310,   310,   310,   311,   311,   311,   312,   312,   313,
     314,   314,   315,   315,   316,   316,   317,   317,   318,   318,
     319,   319,   319,   319,   319,   319,   319,   319,   319,   319,
     319,   319,   319,   319,   319,   319,   319,   319,   319,   319,
     319,   319,   319,   319,   319,   319,   320,   320,   320,   321,
     321,   321,   322,   322,   322,   322,   323,   323,   323,   323,
     323,   323,   323,   323,   323,   323,   323,   323,   323,   323,
     323,   323,   323,   323,   323,   323,   323,   323,   323,   323,
     323,   323,   323,   323,   323,   323,   323,   323,   323,   323,
     323,   323,   323,   323,   323,   323,   323,   323,   324,   324,
     324,   324,   324,   324,   324,   324,   324,   324,   324,   325,
     324,   324,   324,   324,   324,   324,   324,   324,   324,   324,
     324,   324,   324,   324,   324,   324,   324,   324,   324,   324,
     324,   324,   324,   324,   324,   324,   326,   326,   326,   326,
     326,   327,   327,   327,   327,   328,   328,   329,   329,   329,
     329,   329,   329,   330,   330,   331,   331,   331,   331,   331,
     331,   331,   331,   331,   331,   331,   331,   331,   331,   331,
     331,   331,   331,   331,   331,   331,   331,   331,   331,   331,
     331,   331,   331,   331,   331,   331,   331,   331,   331,   331,
     331,   331,   331,   332,   332,   332,   332,   333,   333,   333,
     333,   334,   334,   335,   335,   336,   336,   336,   336,   336,
     336,   336,   336,   337,   337,   337,   337,   337,   337,   337,
     337,   337,   337,   337,   337,   337,   337,   337,   337,   337,
     337,   337,   337,   337,   337,   337,   337,   337,   337,   338,
     337,   339,   339,   340,   340,   341,   341,   341
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
      10,     7,     7,     7,     7,     7,     7,     7,     7,     7,
       7,     8,     4,     8,    12,     8,     8,     7,     7,     8,
       4,     8,     8,     5,    11,     5,     9,     9,     4,     9,
       9,     1,     1,     0,     2,     6,     6,     6,     6,     8,
      10,    14,    16,    12,    14,    14,    14,    14,     8,     8,
       6,     4,     6,     6,     3,     4,     5,     6,     5,     3,
       3,     4,     5,     4,     5,     3,     5,     7,     7,     3,
       7,     3,     2,     2,     2,     2,     2,    15,     2,     2,
       2,     2,     2,    16,    11,     6,     8,     8,    10,     1,
       2,     2,     1,     3,     3,     4,     4,     1,     1,     5,
      11,    13,     0,     7,     0,    13,     0,    15,     0,     6,
       9,     2,     3,    10,     8,     8,     8,    12,    12,    12,
      14,    14,    14,     0,    12,     0,    12,     0,    12,     0,
      16,     0,    16,     0,    16,     0,    18,     0,    18,     0,
      18,     1,     2,     5,     7,     9,     2,     2,     3,     2,
       3,     2,     3,     2,     3,     2,     3,     9,     6,     1,
       1,     1,     1,     1,     0,     2,     3,     9,     4,    14,
       0,     3,     0,     1,     0,     2,     0,     2,     0,     2,
       7,     6,     8,     5,     3,     8,     5,     4,     6,    11,
      11,    18,    18,    12,    12,    12,    10,    10,    10,    10,
      10,     4,     4,     4,     4,     4,     2,     3,     6,     1,
       1,     1,     2,     5,     7,    10,     1,     3,     2,     2,
       2,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     5,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     6,     4,     4,     4,
       4,     4,     4,     4,     6,     6,     6,     4,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       6,     4,     6,     1,     4,     4,     4,     4,     4,     4,
       4,     2,     5,     5,     5,     5,     3,     6,     4,     7,
       6,     6,     6,     4,     6,     4,     1,     2,     2,     3,
       3,    11,     9,     7,     7,     1,     3,     1,     1,     2,
       3,     4,     5,     1,     1,     2,     3,     3,     5,     4,
       2,     2,     2,     2,     3,     3,     3,     3,     5,     5,
       5,     5,    16,    16,    16,    16,     1,     1,     1,     3,
       3,     4,     4,     4,     6,     6,     6,     6,     8,     8,
       4,    14,     4,     1,     1,     3,     3,     9,     7,     1,
       5,     3,     6,     1,     3,     1,     1,     4,     4,     4,
       4,     3,     6,     1,     4,     1,     1,     1,     4,     6,
       4,     6,     4,     4,     4,     8,     4,     4,     4,     4,
       8,     8,     6,     4,     6,     4,     1,     4,     4,     0,
       6,     1,     3,     5,     5,     1,     1,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     2,     3,     1,   595,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   349,   350,   351,   352,   353,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   279,
       0,     0,   287,   288,     0,     0,     0,   282,     0,     0,
       0,     0,     0,   399,   400,   401,     0,     0,     5,     7,
       6,     8,     9,    10,    23,    11,    12,    13,    14,    22,
      21,    20,    15,     0,    16,    17,    18,    19,     0,    24,
     596,     0,   448,   595,   563,   449,   451,   452,   450,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   565,
       0,   586,   567,   456,   457,   458,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   453,   454,   455,   566,
       0,     0,     0,     0,    69,    70,     0,     0,   223,     0,
       0,     0,   406,     0,   555,   596,   463,     0,     0,     0,
       0,   266,     0,   268,   269,   264,   265,     0,   270,   271,
     126,   138,    69,    70,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   272,
       0,     0,     0,     0,     0,   595,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   526,   527,     0,   528,   497,   301,   498,   596,
     463,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     486,     0,     0,     0,     0,     0,   223,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   595,     0,   223,   596,     0,     0,   396,     0,     0,
       0,     0,     0,     0,     0,     0,   504,     0,   503,     0,
       0,     0,     0,     0,   595,     0,     0,   549,     0,     0,
       0,     0,   262,   263,     0,   595,     0,     0,     0,   280,
     281,     0,   223,     0,   223,   595,     0,   596,     0,     0,
     223,   402,     0,     0,    69,    70,     0,     0,    62,    66,
      65,    64,    63,    68,    67,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   409,   408,   410,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   222,     0,   221,     0,     0,
     259,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    37,   255,     0,     0,
     471,   188,     0,   595,     0,   555,   596,   556,     0,     0,
     591,     0,   124,   124,     0,     0,     0,     0,   543,   544,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    69,    70,     0,
       0,     0,     0,     0,     0,     0,     0,   510,     0,     0,
     511,     0,   512,     0,   513,     0,     0,     0,     0,     0,
       0,     0,     0,   408,   505,     0,   499,     0,     0,     0,
      69,    70,     0,     0,     0,     0,     0,     0,   302,     0,
     364,   364,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   223,
     223,     0,   488,   487,     0,     0,     0,     0,   223,   223,
       0,     0,     0,     0,     0,     0,     0,   298,     0,   223,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     366,     0,     0,     0,     0,     0,     0,     0,   244,   397,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   374,
     261,     0,     0,     0,     0,     0,   223,     0,     0,     0,
       0,     0,   284,   283,     0,   249,     0,   250,     0,     0,
       0,   223,     0,     0,     0,     0,   354,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    78,     0,     0,
       0,   476,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   459,   589,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    62,    63,     0,   407,    62,    63,
       0,     0,    62,     0,     0,     0,     0,     0,   218,     0,
       0,     0,     0,     0,     0,   224,     0,     0,     0,   424,
     423,   422,   421,   417,   418,   420,   419,   412,   411,   413,
     414,   415,   416,     0,     0,     0,   189,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     125,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   358,     0,     0,     0,     0,
       0,     0,   393,   394,   395,     0,     0,     0,   476,    71,
      72,     0,   529,     0,     0,     0,     0,     0,   463,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   514,     0,
     515,     0,   516,     0,   517,     0,     0,     0,   407,   500,
     507,     0,   413,   506,     0,     0,     0,   530,     0,     0,
       0,     0,     0,     0,     0,   362,     0,     0,     0,   154,
     155,     0,   157,   158,     0,   160,   161,     0,   163,   164,
       0,   183,     0,   202,     0,   210,     0,     0,     0,     0,
     175,   223,     0,     0,     0,     0,     0,   490,   489,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   292,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   377,     0,     0,   245,     0,     0,   241,     0,
       0,     0,   392,   391,     0,     0,     0,   407,     0,     0,
       0,     0,     0,     0,     0,     0,   285,   286,     0,     0,
     251,   253,     0,   597,     0,     0,     0,     0,     0,     0,
      62,    63,     0,     0,    62,    63,     0,     0,     0,     0,
      93,    77,     0,   465,   464,   478,   426,   427,   428,   429,
     430,   431,   432,   433,   434,   447,   435,     0,   437,   438,
     439,   440,   441,   442,   443,     0,     0,     0,   576,     0,
     583,   572,   573,   574,     0,   588,   587,     0,   483,     0,
       0,     0,     0,   577,   578,   579,   485,   585,   143,   148,
     116,     0,     0,   568,     0,   570,     0,   461,   468,   469,
     564,     0,     0,     0,    62,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   110,     0,     0,     0,     0,
     470,     0,     0,     0,     0,     0,     0,   593,     0,     0,
      47,     0,     0,     0,    60,     0,    38,    39,    40,    41,
      42,   467,   466,     0,     0,   561,    27,    25,     0,     0,
       0,     0,    28,     0,     0,   256,   592,    73,   127,    74,
     139,     0,     0,     0,   545,   546,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   170,   465,
     464,     0,     0,   533,     0,   532,   531,     0,     0,   540,
       0,     0,   509,     0,     0,     0,     0,     0,     0,     0,
     542,   501,     0,     0,     0,   467,   466,     0,     0,     0,
       0,     0,   407,   360,   365,   363,     0,   373,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   407,   407,   407,
       0,     0,     0,     0,     0,   252,   254,     0,     0,     0,
     213,   215,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   331,     0,
     289,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   367,   376,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   246,
       0,     0,     0,     0,     0,   248,     0,   355,     0,     0,
       0,     0,   403,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   594,     0,     0,   473,     0,   472,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    87,
       0,    91,     0,     0,    79,     0,     0,     0,     0,    83,
     106,   108,     0,     0,   553,     0,   114,     0,     0,     0,
       0,     0,     0,     0,   425,     0,     0,     0,     0,     0,
      33,   475,   474,   559,   557,    26,     0,     0,   560,   558,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     168,   168,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   173,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   518,   519,   520,   521,     0,   508,   502,
       0,     0,     0,     0,     0,     0,     0,     0,   371,     0,
       0,   156,     0,   159,     0,   162,     0,   165,     0,     0,
       0,     0,     0,     0,     0,   247,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   337,     0,     0,   336,
       0,   343,     0,   345,     0,   339,     0,   341,     0,   299,
     332,     0,     0,     0,   240,     0,     0,     0,     0,     0,
       0,     0,     0,   378,     0,   243,   242,   398,     0,     0,
      34,    35,     0,     0,     0,     0,   550,     0,     0,     0,
     275,     0,     0,     0,   223,   356,   223,     0,     0,     0,
       0,    88,     0,    92,     0,     0,    80,     0,    84,     0,
     258,   477,   257,   436,   444,   445,   446,   584,     0,     0,
     582,   481,   482,   484,     0,     0,   460,   144,     0,   590,
     149,   480,   569,   571,   462,     0,     0,     0,    89,     0,
       0,     0,    62,     0,     0,     0,     0,    81,     0,     0,
       0,   551,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   495,     0,     0,    29,    30,     0,    31,
       0,     0,   128,   135,     0,     0,    75,    76,   171,     0,
       0,     0,     0,     0,     0,   174,     0,     0,   191,   192,
       0,     0,   176,   207,   193,   197,   198,   194,   195,   196,
       0,     0,     0,   477,   536,   535,   534,     0,     0,     0,
       0,     0,     0,     0,   208,   537,   199,     0,     0,   166,
       0,     0,   370,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   260,     0,     0,     0,     0,   223,
     223,     0,   313,     0,   315,     0,   317,     0,     0,   338,
     497,     0,     0,   344,   346,   340,   342,     0,     0,   293,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     200,     0,     0,     0,     0,   179,   180,     0,     0,     0,
       0,   117,   121,     0,     0,   354,   354,     0,   404,     0,
       0,     0,    90,     0,     0,     0,    82,     0,   479,     0,
       0,     0,     0,     0,     0,   100,     0,     0,    94,     0,
       0,     0,     0,   111,     0,     0,   112,     0,   554,   225,
     226,   227,   228,     0,     0,     0,    43,     0,     0,     0,
       0,     0,    45,   562,     0,     0,   129,   136,     0,     0,
       0,     0,   169,   177,   178,   182,     0,     0,   201,     0,
       0,   372,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   186,     0,     0,   209,   361,   206,   172,   185,   205,
     212,   184,     0,   203,   211,     0,     0,     0,     0,     0,
       0,   494,     0,   493,     0,     0,     0,   304,     0,     0,
     305,     0,     0,   306,     0,     0,     0,     0,     0,     0,
       0,     0,   239,   238,     0,     0,     0,     0,     0,     0,
       0,     0,   229,     0,     0,   375,    36,     0,     0,   548,
       0,   277,   276,     0,     0,     0,     0,     0,     0,     0,
     101,     0,     0,    95,     0,     0,     0,   575,   581,   580,
       0,   145,   147,     0,   150,   151,   152,   102,   104,    96,
      98,   107,   109,     0,   115,     0,    85,    48,     0,     0,
       0,   496,     0,     0,     0,    32,     0,   143,   148,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   538,   539,
       0,     0,     0,     0,     0,     0,     0,   187,     0,   368,
     368,     0,   122,   123,   223,     0,   216,   217,     0,     0,
       0,     0,     0,     0,   300,     0,   333,     0,     0,   223,
       0,     0,     0,     0,     0,     0,     0,     0,   220,   219,
       0,     0,     0,     0,   118,   119,     0,     0,   357,     0,
     103,   105,    97,    99,    86,     0,   543,   544,     0,     0,
     552,     0,    44,     0,     0,     0,    46,    61,     0,     0,
       0,   133,   131,   386,   388,   387,   389,   390,   190,     0,
       0,     0,     0,     0,     0,   303,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   492,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   348,     0,
       0,     0,   294,     0,   230,     0,     0,     0,     0,     0,
       0,     0,   547,   278,     0,     0,   223,   405,     0,   146,
       0,     0,   153,   113,     0,     0,     0,     0,     0,   130,
     137,   143,   143,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   369,   379,     0,     0,   380,     0,   214,
       0,   319,     0,     0,   321,     0,     0,   323,     0,     0,
       0,   334,     0,   290,     0,   223,     0,     0,     0,     0,
       0,     0,   181,   120,   274,   354,     0,   140,     0,     0,
      52,     0,    58,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   167,   204,     0,   383,     0,   384,   385,
     491,   307,     0,     0,   314,   308,     0,     0,   316,   309,
       0,     0,   318,     0,     0,     0,   296,   233,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   134,   132,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   325,     0,   327,     0,   329,   335,   347,
     295,   291,     0,     0,     0,     0,     0,     0,     0,     0,
     141,   142,    49,     0,    56,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   310,     0,     0,   311,
       0,     0,   312,     0,     0,   234,   235,   236,   237,     0,
     231,   359,     0,    50,     0,     0,   267,     0,   541,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   297,     0,     0,     0,     0,     0,   273,     0,     0,
       0,     0,     0,     0,   320,     0,   322,     0,   324,     0,
     232,    51,    53,     0,    54,     0,   522,   523,   524,   525,
       0,     0,     0,     0,     0,     0,     0,    59,   381,   382,
     326,   328,   330,    55,    57
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,   108,  1108,   109,   110,   793,  1715,  1721,
    1096,  1335,  1931,  2172,  1097,  2108,  2213,  1098,  2174,  1099,
    1100,  1339,   405,   500,   210,   852,   111,   811,   512,  1857,
    2012,  2011,  1858,   513,  1925,  1301,  1517,  1302,  1520,   898,
     901,   904,   907,  1753,  1572,   775,   282,   476,   477,   114,
     115,   116,   117,   118,   119,   120,   121,   283,  1231,  2044,
    2132,   937,  1778,  1781,  1784,  2082,  2086,  2090,  2157,  2160,
    2163,  1227,  1228,   284,   986,   285,   125,  1407,  1186,   895,
     951,  1961,   126,   127,   128,   129,   286,   212,  1048,   613,
     320,  1552,   358,   359,   288,   577,   366,  1079,  1325,   510,
     505,  1049,   511,   387,   290
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1664
static const yytype_int16 yypact[] =
{
   11540,    51,    69, 11688, -1664, -1664,  4966,     7,   -56,  -121,
     -92,    40,   135,   162,   186,   227,   153,   300,   338,   157,
     168,  -113,  -113,  -206,   222,   246,    13,   259,   270,    21,
     279,   302,   319,   323,   331,   340,   351,   358,   372,   499,
     531,   538,   645,   454,   622,   484,  6746,   517,   518,   580,
     -46,   329,   664,   684,   709,   -10,   546,   717,   -59,   582,
    -100,  -100,   596,   339,   500, -1664, -1664, -1664, -1664, -1664,
     617,   198,   768,   720,    20,    81,   803,   797,    79,   892,
     914,   917,  6294,   934,   677,   685,   750,    15,    38, -1664,
     757,   760, -1664, -1664,   985,   992,   777, -1664,  4112,   772,
    4671,    18,    22, -1664, -1664, -1664, 10859,   782, -1664, -1664,
   -1664, -1664, -1664, -1664, -1664, -1664, -1664, -1664, -1664, -1664,
   -1664, -1664, -1664,  -123, -1664, -1664, -1664, -1664,    53, -1664,
    -108,   200, -1664,     0, -1664, -1664, -1664, -1664, -1664,  -113,
    -113,  -113,  -113,  -113,  -113,  -113,  -113,  -113,  -113,  -113,
    -113,  -113,  -113,  -113,  -113,  -113,  -113,  -113,  -113,  -113,
    -113,  -113,  -113,  -113,   785,   791,   794,  -113,  -113,  -113,
    -113,   802,  -113,  -113,  -113,  -113,  -113,  -113,   808, -1664,
    -113, -1664, -1664, -1664, -1664, -1664,  -113,  -113,  1041,   820,
     833,   837,  -113,  -113,   841,   842, -1664, -1664, -1664, -1664,
     828, 10859, 10859, 10859,  5039, 10050,    77,    25,   397,   843,
     852,   969, -1664,   872,  1067,   145,   108,  1070, 10859,  4140,
    4140, -1664, 10859, -1664, -1664, -1664, -1664,  4140, -1664, -1664,
   -1664, -1664, -1664, -1664,  5236,    25, 10859,  9757, 10859, 10859,
     868, 10859,  9757, 10859, 10859,   876,  9757, 10859, 10859, 10859,
   10859, 10859, 10859,  4140, 10859, 10859,  6972,   880,   888, -1664,
    9757,  6294,  6294,  6294,  4140,   713,   382,  -113,  -113,  -113,
    -113,    32,    42,    43,    44,  6972,   973,   830,  -113,  7198,
   10859,  5596, -1664, -1664,   889, -1664,  3338, -1664, -1664,   231,
     193, 10859,  9757,   901,   904,  7424,  6294,  6294,  6294,   905,
     915,   940,   946,   965,  7650,  7876,  8102,   959,  1899,  1193,
    6972,    15,   964,   968,  -100,  -100,  -100, 10859, 10859,  -135,
   -1664,   139,  -100,   970,   975,  1001,  1998,   141,    95,   976,
    1002,  1009,  1020,  1023,  1031,  1050, 10859,  6294,  6294,  6972,
    1075,     6,  1078, -1664,  1076,  1311,  1327, -1664,  1109,  1123,
    1126,  6294,  6294,  1139,  1142,  1143, -1664, 10859, -1664,  1367,
    1368, 10859, 10859, 10859,   130, 10859,  1141, -1664,  1205, 10859,
   10859, 10859, -1664, -1664, 10859,  1144,  1375,  1376,  1149, -1664,
   -1664,  1378, -1664,  1379, -1664,   666,  2732,   386,  4140, 10859,
   -1664, -1664,  6972,  6972, 10275, 10342,  1152,  1153,  5236, -1664,
   -1664, -1664, -1664, -1664, -1664,  6972,  1383,  1161, 10859, 10859,
    1387, 10859, 10859, 10859, 10859, 10859, 10859, 10859, 10859, 10859,
   10859, 10859, 10859, 10859, 10859, 10859, 10859, 10859, 10859, 10859,
   10859, 10859, 10859,  4140,  4140,  4140,  4140,  4140,  4140,  4140,
    4140,  4140,  4140,  6972,  4140,  4140, 10859,  4140,  4140,  4140,
    4140,  4140, 10859,  5236, 10859,  4140,  4140,  4140,  4140,  4140,
      25,  5236,    25,  1166,  1166,  1166,   105, 13420,   164, 13029,
     278,  1162,  1391,  -113,  1160, -1664,  1164, 11822, 10859,  9757,
   -1664, 10859, 10859, 10859, 10859, 10859, 10859, 10859, 10859, 10859,
   10859, 10859, 10859, 10859, 10859, 10859, -1664, -1664, 10859, 10859,
   -1664, -1664,  1254,   759,   344, -1664,   505, -1664,   477, 10470,
   -1664,   552,   -63,   359,  1170,  1171, 13441,  9757,  3362, -1664,
    -111, 13462, 13483, 10859, 13504,   239, 13525, 13546, 10859,   422,
   13567, 13588, 13609, 13630, 13651, 13672,  1180, 13693, 13714,  1403,
   10859, 10859,   462,  1406,  1408,  1421,  1200, 10859, 10859,  1425,
     313,  8328,  8554, 10859, 10859,  4140, 10859, -1664,  1380, 10859,
   -1664,  1381, -1664,  1384, -1664,  1385,  6972,    30,    33,    34,
      35,  9757,  9757,  1166, -1664, 13735, -1664,   610, 10859,  8780,
   10859, 10859,   402, 13756,   632, 10859, 10859, 10859, -1664,  1423,
    1429,  1429, 10859,  9977,  9977,  9977,  9977, 10859,  1431, 10859,
    1432, 10859,  1439,  9757,  9757,  4870,  1220,  1443,  1217, -1664,
   -1664,   120, -1664, -1664, 10593, 10732,  -100,  -100,   397,   397,
     146, 10859, 10859, 10859,  1998,  1998, 10859,  2651,   165, -1664,
   10859, 10859, 10859, 10859, 10859, 10859, 10859, 10859, 10859, 13777,
    1445,  1447,  1449, 10859,  1448, 10859, 10859,  3678, -1664, -1664,
    9757,  9757,  9757,  1451,  1453, 10859, 10859, 10859, 13798, -1664,
   -1664, 13819, 13840, 13861,  1292, 10820, -1664,  1242,  3383, 13882,
   13903, 13052, -1664, -1664,  9757, -1664,  4357, -1664, 10887, 10859,
   10859, -1664, 10859, 10859,  1247, 13924,  5661,  1250,   636,   205,
   13945,   274, 13075, 10859,  9757,  1473,  1475, -1664, 10859, 13966,
   13098,   271,  3313,  3313,  3313,  3313,  3313,  3313,  3313,  3313,
    3313,  3313,  3313, 11348,  3313,  3313,  3313,  3313,  3313,  3313,
    3313, 11379, 11755, 11781,  -137,   738,  -137,  1255,  1256,  1249,
     675,   675,  1252,   675,  1257,  1273,  1274, 11807,   675,   675,
     675,   608,   675, 14659, -1664,  1305,  1275,  1277,  1261,   774,
     800,  1284,  1299,  1298,  1486,  1488,  6972,   306,  1489,  1491,
    6972,   189,  5236, 10859,  1530,  1525,    28,   675, -1664,   150,
      14,    29,   267,  1312,   -40, -1664,  4147,   676,  3643,  1531,
    1283,  1110,  1110,   656,   656,   656,   656,   249,   249,  1166,
    1166,  1166,  1166,    61, 13987, 13121, -1664, 10859, 10859,  1534,
      24,  9757, 10859, 10859,  1535,  9757, 10859,  1537,  4140,  1538,
   -1664,    25,  1540,  4140, 10859,  5236,  1533,  9757,  9757,  1377,
    1542,  1543, 14008,  1544,  1382,  1545,  1547, 14029,  1386,  1549,
    1552,  1553,  1557,  1558,  1559, -1664,  1560,  1561, 10859, 14050,
    4184,  1313, -1664, -1664, -1664,  1563, 14071, 13144,   193, -1664,
   -1664,  9757, -1664,  9757,  3362,  1342,  9757,  1343,   442, 11833,
   11859,   675, 11885,  1338,  4288,  1341,  1344,  1345, -1664,  9757,
   -1664,  9757, -1664,  9757, -1664,  9757,   675,   704,  1573, -1664,
    3662,  9757,  1166, -1664, 14092, 13167,  9757, -1664,  1574,  1348,
   14113, 14134, 14155, 10859,  6972,  1579,  1578, 14176,  1357, 14659,
    1353,  1361, 14659,  1358,  1362, 14659,  1364,  1366, 14659,  1371,
   14197, -1664, 14218, -1664, 14239, -1664,   732,   770,  9757,  1369,
   -1664, -1664, 11009, 11066,  -100, 10859, 10859, -1664, -1664,  1389,
    1390,  1998, 11911, 11937, 11963, 10398,  1480,   -80,  -100, 11123,
   14260,  4401, 14281, 14302, 14323, 14344, 14365, 14386, 14407,  1603,
   10859,  1605, -1664, 10859, 14428, -1664, 13190, 13213, -1664,   789,
     799,   807, -1664, -1664, 13236, 13259, 11989, -1664,  1606,  1607,
    1608,  1398, 10859, 11180, 10859, 10859, -1664, -1664,    -1,   839,
   -1664, -1664, 11237, -1664,  1609, 10567,  1395,  1388,  6972,  1611,
    1568,  1576,  6972,   306,  1577,  1592,  6972,   306,  4626,   849,
   -1664, -1664, 13282,   474,  1374, -1664, -1664, -1664, -1664, -1664,
   -1664, -1664, -1664, -1664, -1664, -1664, -1664, 10859, -1664, -1664,
   -1664, -1664, -1664, -1664, -1664, 10859, 10859, 10859, -1664,  9757,
   -1664, -1664, -1664, -1664,  4140, -1664, -1664, 10859, -1664,  6972,
    4140,  4140,  4140, -1664, -1664, -1664, -1664, -1664, -1664, -1664,
   -1664, 10859,  4140, -1664,  4140, -1664, 10859, -1664, -1664, -1664,
   -1664,  -113,  -113,  1635, -1664, 10859,  1636,  -113,  -113,  1639,
     136, 10859,  1640,  1641,  1650, -1664,  1643,  1419,    15,  1648,
   -1664,  9757,  9757,  9757,  9757, 10859,  1435, -1664,   675, 10859,
   -1664,  1436,  1438,  1433, -1664,  1660, -1664, -1664, -1664, -1664,
   -1664,   563,   597, 14449, 13305, -1664, -1664,  1454,  4140,   631,
   14470, 13328, -1664,   653, 12015, -1664, -1664, -1664,    55, -1664,
   -1664,  3313,   675,  -100,  3362, -1664,   856,  6972,  6972,  1665,
    6972,   902,  6972,  6972,  1666,  1587,  6972,  6972,  6972,  6972,
    6972,  6972,  6972,  6972,  1730,  1673,  1674,  9757, -1664,   193,
     -95,   854,   857, -1664,   861, -1664, -1664, 10859, 10859, -1664,
   10859, 10859, -1664, 10859, 10859, 10859,   865,   866,   869,   908,
   -1664, -1664,  6972, 10859,   926,   193,   193,   927,  6972,  9757,
    1675,  1678,  1679,  1935, -1664, -1664,  1681, -1664,  1683,   284,
   10859,   284, 10859,   284, 10859,   284, 10859,  1684,  1686,  1687,
    1688,  1689,   931,  1693, 11294, -1664, -1664,   170, 12041, 12067,
   -1664, -1664,  4668,  -115,  -100,  -100,  -100,  1601,  1694, 10639,
    1465,  1695,  1478,    49,   117,   184,   185,   407, -1664,   182,
   -1664,   -80,  1700,  1702,  1703,  1704,  1705,  1706,  1707,  1708,
    1714,  6972, 14659, -1664,  1773,  1466,  1716,  1721,  1722,  1642,
    1723,  1725,  1727, 10859,  6972,  6972,  6972,  1731, 12093, -1664,
    3806,   937,  1733,  1734,  1496, -1664,  1500, -1664,  2093,  1520,
    6972,  1521, -1664,  -113,  -113,  1754, 10859,  1755,  -113,  -113,
    1756, 10859,  1757, -1664,   675,  1758, -1664,  1761, -1664,  1760,
    3313,  3313,  3313,  3313,   813,  1539, 10512,  1548,   675,   675,
    1550,   822,   826, 14491,  1556,   675,  3313,  1167,  4140, -1664,
    2121, -1664,  1167,  4140, -1664,   314,  1536,  1764,  2165, -1664,
   -1664, -1664,    15, 10859, -1664,   935, -1664,   987,   988,   995,
    1006, 14512, 10859,   284, 14659,  1541, 10859, 10859,  6972,  1546,
   -1664, -1664, -1664, -1664,  1555, -1664,  1767,    57, -1664, -1664,
    1771, 10859,   128,  1562,  1551,  1772,  1781,     8,  1564,  1566,
    1677,  1677,  6972,  1783,  1567,  1570,  1786,  1787,  6972,  1583,
    1789,  1790,  1796,  1799,  1805,  1806,  1812,  1813, -1664,  1816,
    6972,  1007,  1818,   675,  1595,  1594, 12119, 12145, 12171, 12197,
   12223, 12249, 12275, -1664, -1664, -1664, -1664,  1819, 14659, -1664,
     675,  1822,  1010,  6972,  6972,  6972,  1825,  1826, -1664,  6972,
    6972, 14659,  6972, 14659,  6972, 14659,  6972, 14659,  6972,  6972,
    6972,  1597,  1599,  1827,   634, -1664, 10859, 10859, 10859,  1602,
    1610,  -157,  -128,  -120,  1612,  1613, -1664,  2486,  6972, -1664,
   10859, -1664,  1829, -1664,  1831, -1664,  1833, -1664,  1835, -1664,
   -1664,  1998,   472,  6520, -1664,  1614,  1616,  1617,  1618,  1619,
    1620,  9006,  1837, -1664,  9757, -1664, -1664, -1664,  1621, 10859,
   -1664, -1664, 13351,  1839,  1841,  1710, -1664, 10859, 10859, 10859,
   -1664,  1866,   827,  5236, -1664, -1664, -1664,  1646,  1867,  1167,
    4140, -1664,  2592, -1664,  1167,  4140, -1664,  2647, -1664,   284,
   -1664,   615, -1664, -1664, -1664, -1664, -1664, -1664,  4140, 10859,
   -1664, -1664, -1664, -1664,  4140,  1870, -1664, -1664,    27, -1664,
   -1664, -1664, -1664, -1664, -1664,  1874,  -137,  -137, -1664,  1875,
    -137,  -137,  5236, 10859,  1877,  1880,    28, -1664,  1879, 13374,
      15, -1664,  1881,  1882,  1883,  1884,  1573, 14533,  6972, 10859,
   12301, 12327,  1011, -1664, 10859,  1887, -1664, -1664,  4140, -1664,
   12353,  5842, 14659, -1664,  1885,  1886, -1664, -1664, -1664, 10859,
   10859,  -100,  1888,  1894,  1895, -1664, 10859, 10859, -1664, -1664,
    1898, 10859, -1664, -1664, -1664, -1664, -1664, -1664, -1664, -1664,
    1901,  1905,  1652,   193, -1664, -1664, -1664, 10859, 10859, 10859,
   10859, 10859, 10859, 10859, -1664, -1664, -1664,  1724,  1906,  1736,
    1930, 10859, -1664,  1931,  1953,  1955,  1956,  1957,  1958,  1059,
    1959,  9757,  9757, 10859, -1664,  9977,  4725, 14554,  2328,   397,
     397,  -100,  1960,  -100,  1961,  -100,  1962,  6972, 10859, -1664,
     715,  1737, 14575, -1664, -1664, -1664, -1664,  5119,   210, -1664,
    1963,  1968,  6972,  -100,  -100,  -100,  -100,  -100,  5361,  1969,
   -1664,  1021, 10859,  2761,  1971, -1664, -1664,  6972,  3913,   743,
   14596, -1664, -1664,  9458,  1745,  5661,  5661,  6972, -1664,  1974,
    -137,  -137, -1664,  1989,  -137,  -137, -1664,  6972, -1664,  1768,
    3313,   675,  6068,  9531,  5236, -1664,  1991,  1994, -1664,  1997,
    1999,  2000,  2783, -1664,  2004,  2029, -1664,  1807, -1664, -1664,
   -1664, -1664, -1664,  1679,  2030,   661, 14659, 10859, 10859,  6972,
    1770,  1022, 14659, -1664,  2031, 10859, -1664, -1664,  1809,  1815,
    5318,  5778,   763, -1664, -1664, -1664,  6004,  6230, -1664,  6456,
    2034, -1664,  6972,  3313,  3313, 12379, 12405, 12431, 12457, 12483,
   10859, -1664,  1952,  2035, -1664, 14659, -1664, -1664, -1664, -1664,
   -1664, -1664,  1821, -1664, -1664,  1026,  1029, 10300,  2814,  2044,
    1823, -1664, 10859, -1664,  1828,  1830,   233, -1664,  1824,   244,
   -1664,  1832,   275, -1664,  1834,  1838, 13397,  2055,  6972,  2057,
    1840, 10859, -1664, -1664,  1030,   299,   309,   318,   347,   353,
    9232,   357, -1664,  2056,  6682, -1664, -1664,  1903, 10859, -1664,
   10859, -1664, -1664,  9757,  2920,  2061,  5236,  1842,  1844,  1845,
   -1664,  2069,  2070, -1664,  2075,  2076,  2077, -1664, -1664, -1664,
    5596, -1664, -1664,  4140, 14659, -1664, -1664, -1664, -1664, -1664,
   -1664, -1664, -1664,    15, -1664,  1915, -1664, -1664, 10859, 12509,
   12535, -1664,  6972, 10859,  2080, -1664, 12561, -1664, -1664,  6972,
    6972,  2081,  2082,  2084,  2085,  2086,  2087,  1033, -1664, -1664,
   10859, 10859, 10859, 10859, 10859,  6908,  1869, -1664,  6972,   456,
     726,  9757, -1664, -1664,   397,  4034, -1664, -1664,  1998,   -80,
    1998,   -80,  1998,   -80, -1664,  2094, -1664,  1036,  6972, -1664,
    7134,  2095,  9757,  -100,  -100,  -100,  -100,  -100, -1664, -1664,
   10859,  7360,  7586,  1037, -1664, -1664,  1876,  1871, -1664,  2100,
   -1664, -1664, -1664, -1664, -1664,  1040,  3240,  2101,  1043,  2103,
   -1664,  1873, 14659, 10859, 10859,  1047, 14659, -1664, 10859,  1048,
    1056, -1664, -1664, -1664, -1664, -1664, -1664, -1664, -1664,  1878,
   12587, 12613, 12639, 12665, 12691, -1664, 10859,  1057,  1890,  -100,
    6972,  2104,  1891,  -100,  2105,  1060,  1893, 10859, -1664,  7812,
     390,   491,  8038,   417,   612,  8264,   436,   665, -1664,  6972,
    2108,  2001, 11351,  1896, -1664,  1061,   441,   443,   445,   447,
     528,  3110, -1664, -1664,  2112,  2113, -1664, -1664, 10859, -1664,
    5236,    25, -1664, -1664, 10859, 14617, 12717,    45, 12743, -1664,
   -1664, -1664, -1664, 10859, 10859, 10859, 10859, 10859, 10859,  8490,
    2114,  -100,    80, -1664, -1664,  -100,    82, -1664,  2123, -1664,
    8716,  2126, 10859,  2129,  2130, 10859,  2131,  2132, 10859,  2133,
    1922, -1664, 10859, -1664,   -80, -1664,  2135,  9757,  9757,  9757,
    9757,  9232, -1664, -1664, -1664,  5661,   900, -1664,  1932,  1065,
   -1664, 10859, -1664,  6972, 10859,  1068,  1073, 12769, 12795, 12821,
   12847, 12873, 12899, -1664, -1664,   537, -1664,   545, -1664, -1664,
   -1664, -1664,  1924,  8942, -1664, -1664,  1926,  9168, -1664, -1664,
    1928,  9405, -1664,  2157,  3213,   708, 11408, -1664,  1080,  1083,
    1104,  1105,   573,  1112,  1929,  5236,  1937,  2160,  1933, 14638,
    1113,  9487, -1664, -1664, 10859, 10859, 10859, 10859, 10859, 10859,
    -100,  -100,   -80,  2162,   -80,  2163,   -80,  2164, -1664, -1664,
   -1664, -1664,   -80,  2167,  2168,  2169,  2170,  9757,  2171,  2172,
   -1664, -1664, -1664,  4140, -1664,  1945,  2174,  9693,  3313, 12925,
   12951, 12977, 13003,   576,   609,   862, -1664,  1947,  1053, -1664,
    1948,  1485, -1664,  1949,  1505, -1664, -1664, -1664, -1664,  1116,
   -1664, -1664,  1117, -1664,  1951,  6972, -1664,  2180, -1664, 10859,
   10859, 10859, 10859, 10859, 10859,  2181,   -80,  2183,   -80,  2185,
     -80, -1664,  2192,  4140,  2193,  4140,  1128, -1664,  9881,  9923,
   10002, 10106, 10173, 10215, -1664,  1523, -1664,  1571, -1664,  1661,
   -1664, -1664, -1664,  1131, -1664,  2194, -1664, -1664, -1664, -1664,
    2196,  2197,  2198,  2200,  2201,  4140,  2202, -1664, -1664, -1664,
   -1664, -1664, -1664, -1664, -1664
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1664, -1664, -1664, -1664,   863, -1664, -1664, -1664, -1664,   207,
   -1664, -1664, -1664, -1664, -1664, -1664, -1664, -1664, -1664, -1664,
   -1664, -1664,  -414,  -105,  4632,  3832, -1664,  1696, -1664, -1664,
   -1664, -1664, -1664, -1664, -1664, -1660, -1664,   355, -1664, -1664,
   -1664, -1664, -1664, -1664,   853,  2214,    -2,  -610,  -290, -1664,
   -1664, -1664, -1664, -1664, -1664, -1664, -1664,  2215, -1664, -1664,
   -1664, -1664, -1664, -1664, -1664, -1664, -1664, -1664, -1664, -1664,
   -1664, -1216, -1182,  2218, -1663,  2220, -1664, -1664, -1664,  1633,
   -1664,   346, -1664, -1664, -1664, -1664,  2036, -1664, -1664,  1281,
   -1664, -1641,  2971,   486,  2866,  3408,  -309,   691, -1664,   245,
      10, -1664,  -428,    -3,   280
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -563
static const yytype_int16 yytable[] =
{
     130,   113,   608,   215,   407,   724,  1262,   726,   929,   930,
     644,  1794,  1817,  1818,  1568,  1452,   214,   240,   240,   364,
     217,   236,   741,   381,   341,   245,   406,   383,   237,   375,
    1106,  1693,  1077,   245,   218,   868,   627,   557,   870,   872,
     874,  1218,   368,   289,   294,  1450,   221,   560,   562,   564,
     294,  2062,   756,   647,   760,  1441,   763,     4,  1219,   391,
     616,   617,  1352,  1557,   295,  1090,  1220,  1221,  1222,     5,
    1086,   344,  1223,  1224,  1225,  1226,  1631,   307,  1632,   289,
     308,   470,   616,   617,   344,   346,  2076,   347,  2078,   616,
     617,   849,   676,   850,   678,   344,   808,   616,   617,   618,
     686,  1867,   616,   617,   389,  1633,   219,  1634,   376,   311,
     380,   390,   754,  1635,   232,  1636,   233,   315,   316,   394,
    1430,   395,   818,  1443,   819,   312,   313,   317,   396,   403,
     404,   132,   385,   134,   318,   220,  1382,   135,   136,   137,
    1315,   223,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   348,   351,   809,   224,   352,
     810,   758,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
    1445,  1447,   225,   179,   180,   181,  1064,  1939,   182,   342,
     183,   184,   185,   558,   344,  1442,   475,   398,   186,   187,
    1694,  1935,   990,   561,   563,   565,   506,   506,   107,  1091,
    1092,  1093,  1094,   107,   506,   616,   617,   408,   107,   409,
    1263,   410,   344,   226,   289,   645,   209,  1957,  1107,   289,
     241,   241,   209,   289,   514,   471,   472,   242,  1082,   365,
     506,   213,   382,   289,   343,   246,   384,   289,   289,   289,
     289,   506,  1078,  1083,   869,   369,   559,   871,   873,   875,
    1450,  1107,   289,  1444,   222,   992,   289,   996,   289,  2063,
     392,   994,  1353,   131,  1354,   762,   216,   393,   337,   289,
     338,  1064,   289,   289,   289,   289,  1095,   616,   617,   616,
     617,   289,   289,   289,  1316,  1317,   228,   289,   344,   399,
     400,   401,   755,  1064,   189,   190,   191,   192,   193,   922,
     923,  1532,   630,   194,   195,   196,   197,   198,   199,   631,
     200,   107,   403,   404,   289,   289,   289,   616,   617,   939,
    1446,  1448,  -556,  1065,   229,   201,   202,  1071,   289,   289,
     203,  2065,  2066,   924,   345,   357,   616,   617,   616,   617,
     207,   664,  1561,   616,   617,   764,   209,   367,   399,   400,
     401,   759,   498,   619,   499,   629,   973,   236,   377,   931,
     227,   396,   616,   617,  1081,   506,   230,   616,   617,   289,
     289,   982,  2104,   399,   400,   401,   402,   231,   938,   616,
     617,   474,   289,  1426,   399,   400,   401,   402,   695,   399,
     400,   401,   991,   403,   404,  1451,   296,   403,   404,   297,
    1070,   298,  2110,   323,   403,   404,   324,   616,   617,   325,
     506,   506,   506,   506,   506,   506,   506,   506,   506,   506,
     289,   506,   506,  1791,   506,   506,   506,   506,   506,   238,
     616,   617,   506,   506,   506,   506,   506,   344,   580,   344,
     581,   616,   617,   744,   504,   508,  1888,   396,   492,   493,
     494,   752,   818,   239,   824,   495,   289,  1890,   399,   400,
     401,   995,   399,   400,   401,   402,   243,   473,   399,   400,
     401,   402,   616,   617,   248,   403,   404,   244,   536,   507,
     507,  1084,   403,   404,   328,  -561,   247,   507,  1892,   546,
     399,   400,   401,   402,   289,   515,   616,   617,   399,   400,
     401,   402,    59,    60,    61,    62,   616,   617,  1218,   248,
     403,   404,  1902,   507,  2196,   616,   617,    73,   403,   404,
      76,   849,  1903,   850,   507,  1219,   249,   851,   289,   289,
     250,  1904,   506,  1220,  1221,  1222,   315,   316,   251,  1223,
    1224,  1225,  1226,   289,   616,   617,   317,   252,   289,   289,
     616,   617,   800,   326,   616,   617,   289,   801,   253,  1276,
    1905,  1958,  1959,  1281,   329,   254,  1906,  1960,   330,   812,
    1907,   367,   810,  1218,   331,   332,  1005,   333,   334,   255,
     289,   289,   256,   900,   903,   906,   909,   616,   617,   551,
    1219,   552,  1218,   682,   335,   683,   475,   475,  1220,  1221,
    1222,   257,   396,  2032,  1223,  1224,  1225,  1226,   258,  1219,
     849,  1204,   850,   684,   616,   617,   886,  1220,  1221,  1222,
    1624,  1625,  1449,  1223,  1224,  1225,  1226,   289,   289,   289,
    2035,   259,  1066,   616,   617,   818,  1072,   828,   616,   617,
     616,   617,   616,   617,   616,   617,   403,   404,   507,  2038,
     293,   289,  1156,  1971,  2047,  1974,  2048,  1977,  2049,   725,
    2050,   727,   728,   729,   730,   731,   732,   733,   260,   735,
     736,   289,   738,   739,   740,   818,   742,   841,   403,   404,
     746,   747,   748,   749,   750,   804,   261,  1649,  -559,   262,
     805,   264,   263,   507,   507,   507,   507,   507,   507,   507,
     507,   507,   507,   578,   507,   507,  2033,   507,   507,   507,
     507,   507,   802,  1218,   803,   507,   507,   507,   507,   507,
     751,   396,   753,  1005,   291,   616,   617,   543,   544,   545,
    1219,  1810,   292,   289,   616,   617,   299,   289,  1220,  1221,
    1222,  2051,   616,   617,  1223,  1224,  1225,  1226,   300,  1324,
    2120,   301,  1073,   309,   302,  1410,   303,  1412,  2121,  1414,
     807,  1416,   589,   590,   591,   808,  1218,   403,   404,  1450,
     616,   617,  1450,   616,   617,  1450,   304,  -560,   289,   305,
     861,   306,   289,  1219,   310,   506,  2137,   340,   344,  2183,
     506,  1220,  1221,  1222,   289,   289,   314,  1223,  1224,  1225,
    1226,   403,   404,   640,   641,  1122,   616,   617,  2095,  1218,
     322,  -558,   858,  1672,  1673,   507,  1046,   653,   654,   403,
     404,   808,  2184,   818,   336,   879,  1219,  2036,   289,  -562,
     289,  1962,  1963,   289,  1220,  1221,  1222,  1960,   339,  1347,
    1223,  1224,  1225,  1226,   818,   818,   289,   889,   289,   988,
     289,   989,   289,   490,   491,   492,   493,   494,   289,  1526,
    1527,  1350,   495,   289,  1530,  1531,   818,   350,  1277,  1847,
     349,   289,  1282,   679,  1848,   680,   353,   549,  1286,  1288,
    2039,  1533,   209,   849,   361,   850,  2155,  2105,  2158,   818,
    2161,  1088,   362,  1450,   567,   289,  2164,   568,   354,  1548,
     569,   355,   570,   481,   482,   483,   484,   485,   486,   487,
     488,   489,   490,   491,   579,   493,   494,   818,   360,  1171,
     547,   495,   548,  2130,   549,  1479,  1358,   208,  1359,   209,
    1787,   481,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,   818,   849,  1200,   850,   495,
    2205,  1029,  2207,  1450,  2209,   480,  1450,   363,  1811,  1450,
     616,   617,  1450,  1218,   370,   289,   797,   371,   798,   289,
     799,   372,  1364,   289,  1365,   209,  1341,  1342,   373,   378,
    1219,   506,   849,   818,   850,  1201,   374,  1054,  1220,  1221,
    1222,   388,   436,  1538,  1223,  1224,  1225,  1226,   437,  1774,
    1775,   438,   818,  1450,  1248,  1450,   289,  1450,   849,   443,
     850,   506,   818,  1056,  1249,   450,   289,   506,   506,   506,
     818,   849,  1250,   850,  1286,  1288,   818,   455,   454,   506,
     849,   506,   850,  1116,   849,  1515,   850,   462,  1120,  1518,
     456,  1680,  1681,  1762,   457,  1763,  1684,  1685,   460,   461,
    1341,  1342,   818,   497,  1264,   344,   501,   478,   289,   289,
     289,   289,   818,   566,  1284,  1687,   479,   818,   507,  1383,
     818,  1118,  1384,   507,   818,   523,  1385,  2185,   818,   818,
    1393,  1394,   818,   528,  1395,   506,   496,   540,   481,   482,
     483,   484,   485,   486,   487,   488,   489,   490,   491,   492,
     493,   494,   541,   390,   289,   289,   495,   289,   585,   289,
     289,   586,   592,   289,   289,   289,   289,   289,   289,   289,
     289,   818,   593,  1396,   289,   481,   482,   483,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,   818,
     818,  1399,  1400,   495,   818,  1480,  1423,   594,  1540,   289,
    1541,   503,   134,   595,  1218,   289,   289,   481,   482,   483,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
     494,  1219,   596,   603,  1675,   495,  1676,   606,   609,  1220,
    1221,  1222,   610,   632,   621,  1223,  1224,  1225,  1226,   622,
    1534,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     818,   818,  1542,  1543,   174,   175,   176,   177,   818,   633,
    1544,  1708,   179,   180,   181,   623,   634,   182,   289,   818,
     818,  1545,  1592,   818,  1719,  1607,  1720,   635,   187,  1289,
     636,   289,   289,   289,   818,  1853,  1803,  1854,   637,   818,
     796,  1879,   818,  1719,  1880,  1901,  1719,   289,  1949,  1979,
     818,  1980,  1994,  1998,  1966,  1999,   808,   638,  2002,  1295,
    1719,  1515,  2007,  2009,   507,  1298,  1299,  1300,  2187,  1518,
    1719,  2010,  2020,   818,   818,  2028,  2046,  1304,  1853,  1305,
    2107,  1515,   643,  2112,   506,   506,  1515,   646,  2113,   506,
     506,  1050,   396,   818,   507,  2133,   818,   648,  2134,   344,
     507,   507,   507,   486,   487,   488,   489,   490,   491,   492,
     493,   494,   507,   649,   507,   289,   495,   818,   818,  2135,
    2136,   319,   321,   650,   327,   818,  1719,  2138,  2145,   818,
    2193,  2192,  2194,  1346,   190,   191,   192,   651,   367,   289,
     652,  1719,  1563,  2215,  2225,   289,  2226,   199,   655,   200,
     107,   656,   657,   659,   660,   666,   667,   289,   503,   134,
     209,   672,   673,   674,   675,   677,   693,   694,   507,   697,
     698,   701,   495,   765,   208,   849,  1688,   850,   766,   768,
     289,   289,   289,   814,   815,  1928,   289,   289,   835,   289,
     838,   289,   842,   289,   843,   289,   289,   289,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   844,   845,   848,
     893,   174,   175,   176,   177,   289,   894,   911,   913,   179,
     180,   181,   863,   865,   182,   915,   866,   867,   919,   920,
     289,   921,   950,   952,   955,   187,   953,   962,   289,   963,
     971,   289,   481,   482,   483,   484,   485,   486,   487,   488,
     489,   490,   491,   492,   493,   494,   974,   983,   987,  1000,
     495,  1001,  1034,  1032,  1033,  1037,   506,   506,  1688,  1053,
    1039,   506,   506,  1674,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,   506,  1040,  1041,  1051,   495,
    1052,   506,  1058,   481,   482,   483,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,  1059,  1060,  1076,
    1061,   495,  1062,  1067,  1929,  1068,  1075,   344,  1105,  1085,
    1123,  1112,  1701,  1115,  1117,   289,  1119,  1147,  1126,  1127,
    1128,  1130,  1132,  1131,  1133,   506,  1136,  1135,   289,  1137,
    1138,   190,   191,   192,  1139,  1140,  1141,  1142,  1143,  1148,
    1153,  1727,  1161,  1155,   199,  1163,   200,   107,  1164,  1165,
    1172,  1178,  1179,  1185,  1187,  1189,  1190,   507,   507,  1191,
    1193,  1192,   507,   507,  1195,   611,   612,  1194,   403,   404,
    1203,  1217,   367,   620,  1196,  1287,  1218,   628,  -557,  1982,
    1241,  1243,  1273,  1254,  1255,  1256,  1266,  1272,   289,   289,
    1274,  1278,  1270,  1219,  1210,  1211,  1218,   475,   475,  1257,
    1269,  1220,  1221,  1222,   289,  1769,  1279,  1223,  1224,  1225,
    1226,  1309,  1311,  1219,  1218,  1314,  1319,  1320,  1323,   289,
    1322,  1220,  1221,  1222,  1326,   289,  1321,  1223,  1224,  1225,
    1226,  1219,  1332,  1336,   289,  1337,  1340,  1338,  1345,  1220,
    1221,  1222,  1362,  1368,   289,  1223,  1224,  1225,  1226,  1369,
    1379,  1380,  1403,  1815,   289,  1404,  1405,  1408,  1434,   289,
    1409,  1418,  1218,  1419,  1420,  1421,  1422,  1424,  1435,  1438,
    1464,  1439,  1832,  1835,  1836,  1440,  2055,  1453,  1454,  1219,
    1455,  1456,  1457,  1458,  1459,  1460,   289,  1220,  1221,  1222,
    2189,  1461,  1465,  1223,  1224,  1225,  1226,  1466,  1467,  1483,
    1469,  1470,  1468,  1471,  1484,  1476,  1378,  1481,  1482,   289,
    2191,   483,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   493,   494,  1689,  1486,  2096,  1488,   495,  2222,  1691,
    1491,  1493,  1496,  1498,  1500,  1501,  1502,  1535,  1549,   507,
     507,  1536,  1508,  1556,   507,   507,  1511,  1559,  1566,  1463,
    1554,  1565,  1218,  1514,  1522,   289,  1555,  1567,   507,  1575,
    1564,  1571,  1578,  1579,   507,  1582,  1583,   289,  1569,  1219,
    1570,  1576,  1584,  1724,  1577,  1585,  2223,  1220,  1221,  1222,
     289,  1586,  1587,  1223,  1224,  1225,  1226,  1581,  1588,  1589,
     367,  1590,  1593,  1595,  1596,  1604,  1916,   289,  1606,  1611,
     506,  1621,  1612,  1622,  1623,  1643,  1629,  1644,   507,  1645,
     344,  1646,  1638,  1660,  1630,  1665,  1637,  1666,  1652,   289,
    1653,  1654,  1655,  1656,  1657,  1662,   289,   289,   481,   482,
     483,   484,   485,   486,   487,   488,   489,   490,   491,   492,
     493,   494,  1671,  1678,  1692,   289,   495,  1667,   289,  1677,
    1695,  1698,   475,  1703,  1704,  1706,  1742,  1709,  1710,  1711,
    1712,  1723,  1728,  1729,  1733,   289,  2224,   927,   928,   289,
    1734,  1735,   132,   385,  1738,   612,  1740,  1752,   135,   136,
     137,  1741,  1751,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,  1754,  1756,   481,   482,
     483,   484,   485,   486,   487,   488,   489,   490,   491,   492,
     493,   494,   170,   171,   172,   173,   495,   289,  1750,  1757,
     178,  1758,  1759,  1760,  1761,  1764,  1777,  1780,  1783,  1792,
    1788,   183,   184,   185,  1793,  1802,   289,  1806,  1816,   186,
    1820,   481,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,  1823,  1827,  1837,   344,   495,
    1838,   132,   385,  1839,  1852,  1840,  1841,   135,   136,   137,
    2057,  1843,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,  1844,  1846,  1855,  1845,  1866,
    1876,  1877,   211,  1859,   289,   289,   289,   289,   289,  1860,
    1883,   170,   171,   172,   173,  1878,  1406,  1884,  1889,   178,
     289,  1896,  1908,  1886,  1898,  1887,  1891,  1915,  1893,  1910,
     183,   184,   185,  1894,  1899,  1920,  1921,  1917,   186,  1918,
    1919,  1922,  1923,  1924,  1930,   189,  1937,  1943,  1944,   193,
    1945,  1946,  1947,  1948,   194,   195,   196,   197,   198,  1485,
    1978,  1984,   107,  1956,  1995,  1996,  1997,  2004,  2001,  2003,
    2024,  2027,  2013,   507,  2041,  2140,   201,   202,  2053,  2054,
    2074,   203,  2042,   367,  2021,  2025,   357,  1528,  2029,  2079,
    2045,   207,  2081,   604,   289,  2084,  2085,  2088,  2089,  2092,
     506,  2097,   386,   481,   482,   483,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,  2093,  2122,  2106,
    2124,   495,  2126,  2128,  2139,  2141,  2142,  2143,  2156,  2159,
    2162,  1537,   289,  2165,  2166,  2167,  2168,  2170,  2171,  2175,
    2176,  2186,  2188,  2190,   189,  2195,  2197,  2204,   193,  2206,
     506,  2208,   506,   194,   195,   196,   197,   198,  2210,  2212,
    2227,   107,  2228,  2229,  2230,  1207,  2231,  2232,  2234,   813,
    1558,  2059,  1213,  1940,  1573,   624,   625,   112,   122,  1229,
     203,   123,   506,   124,   896,   626,  1964,  1705,     0,     0,
     207,     0,   318,     0,     0,     0,     0,   463,   464,   465,
     467,   469,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   502,     0,     0,     0,   509,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   516,   518,   521,   522,     0,   524,   518,   526,
     527,  2058,   518,   530,   531,   532,   533,   534,   535,     0,
     537,   538,     0,     0,     0,     0,   518,     0,     0,     0,
       0,   481,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,   573,   575,   518,     0,   495,
       0,     0,     0,     0,     0,     0,     0,   583,   518,   481,
     482,   483,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   493,   494,     0,   605,     0,     0,   495,     0,     0,
       0,     0,     0,   614,   615,     0,     0,     0,     0,     0,
       0,     0,   615,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   639,   481,   482,   483,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,     0,  2173,     0,
       0,   495,     0,   658,     0,     0,     0,   661,   662,   663,
       0,   665,     0,     0,  1357,   668,   669,   670,     0,     0,
     671,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   507,     0,   685,     0,     0,     0,     0,
     690,   692,     0,     0,     0,     0,     0,     0,  2211,     0,
    2214,     0,     0,     0,   699,   700,     0,   702,   703,   704,
     705,   706,   707,   708,   709,   710,   711,   712,   713,   714,
     715,   716,   717,   718,   719,   720,   721,   722,   723,     0,
    2233,     0,     0,   507,     0,   507,     0,     0,     0,     0,
       0,     0,   737,     0,     0,     0,     0,     0,   743,     0,
     745,     0,  1639,     0,     0,  1431,  1432,  1433,     0,     0,
       0,     0,     0,     0,     0,   507,     0,     0,     0,     0,
       0,     0,     0,     0,   776,   518,     0,   778,   779,   780,
     781,   782,   783,   784,   785,   786,   787,   788,   789,   790,
     791,   792,     0,     0,   794,   795,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
       0,     0,     0,   573,   495,     0,     0,     0,     0,   822,
       0,  1772,     0,  1773,   827,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   839,   840,     0,     0,
       0,     0,     0,   846,   847,     0,     0,   854,   854,   859,
     860,     0,   862,     0,     0,   864,     0,     0,  1682,     0,
       0,     0,     0,     0,     0,     0,     0,   854,   518,     0,
       0,     0,     0,     0,   880,   882,   884,   885,     0,     0,
       0,   890,   891,   892,     0,     0,     0,     0,   897,   899,
     902,   905,   908,   910,     0,   912,     0,   914,     0,   518,
     518,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1686,     0,     0,     0,   932,   933,   934,
     463,   464,   935,     7,     8,     0,   940,   941,   942,   943,
     944,   945,   946,   947,   948,     0,     0,     0,     0,   954,
       0,   956,   957,     0,     0,     0,   518,   518,   518,     0,
       0,   964,   965,   966,   481,   482,   483,   484,   485,   486,
     487,   488,   489,   490,   491,   492,   493,   494,     0,     0,
     518,     0,   495,     0,     0,   846,   847,     0,   884,   885,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   998,
     518,     0,  1648,     0,  1002,   769,    24,    25,   770,    27,
      28,   771,    30,   772,    32,    33,    34,    35,     0,     0,
       0,    37,    38,    39,     0,    40,     0,     0,     0,     0,
      45,   773,    47,     0,     0,    49,   774,  1805,    52,    53,
      54,     0,     0,     0,    57,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    70,  1842,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1074,
     481,   482,   483,   484,   485,   486,   487,   488,   489,   490,
     491,   492,   493,   494,    84,    85,    86,     0,   495,     0,
    1882,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1103,  1104,     0,     0,   518,  1110,  1111,
       0,   518,  1114,     0,     0,     0,     0,     0,     0,     0,
    1121,     0,  1732,   882,  1124,   481,   482,   483,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,     0,
       0,     0,     0,   495,  1144,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   936,   518,     0,   518,
       0,     0,   518,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   518,     0,   518,     0,   518,
       0,   518,  1776,     0,  1779,     0,  1782,   518,     0,     0,
       0,     0,   518,     0,     0,     0,  1914,     0,     0,  1183,
       0,     0,     0,     0,  1795,  1796,  1797,  1798,  1799,  1801,
     481,   482,   483,   484,   485,   486,   487,   488,   489,   490,
     491,   492,   493,   494,   518,     0,     0,     0,   495,     0,
       0,  1208,  1209,     0,     0,     0,   681,  1212,     0,   481,
     482,   483,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   493,   494,     0,     0,     0,  1242,   495,     0,  1244,
       0,   481,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,     0,     0,     0,  1258,   495,
    1260,  1261,     0,     0,     0,     0,     0,   287,     0,     0,
       0,  1268,   481,   482,   483,   484,   485,   486,   487,   488,
     489,   490,   491,   492,   493,   494,     0,     0,     0,     0,
     495,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1290,     0,     0,     0,     0,     0,     0,
       0,  1291,  1292,  1293,     0,   518,     0,     0,     0,     0,
       0,     0,     0,  1296,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1303,     0,     0,
       0,     0,  1306,     0,     0,     0,     0,     0,     0,     0,
       0,  1310,     0,   519,     0,     0,     0,  1318,   519,     0,
       0,     0,   519,     0,     0,     0,  2052,   518,   518,   518,
     518,  1331,     0,     0,     0,  1334,   519,     0,   481,   482,
     483,   484,   485,   486,   487,   488,   489,   490,   491,   492,
     493,   494,     0,     0,     0,   574,   495,   519,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   519,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1970,
       0,  1973,     0,  1976,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   518,  1986,  1987,  1988,  1989,  1990,     0,
       0,     0,     0,  1386,  1387,     0,  1388,  1389,     0,  1390,
    1391,  1392,     0,     0,     0,     0,     0,     0,     0,  1398,
       0,     0,     0,     0,     0,   518,     0,     0,     0,  2129,
       0,     0,     0,     0,     0,     0,  1411,   539,  1413,     0,
    1415,     0,  1417,     0,     0,     0,     0,     0,     0,     0,
    2022,     0,     0,     0,  2026,     0,   287,  2000,   578,     0,
       0,     0,     0,     0,     0,  1437,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   588,     0,     0,     0,
       0,     0,     0,     0,     0,   598,   600,   602,     0,     0,
       0,   607,     0,     0,     0,     0,     0,     0,     0,  1472,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2075,     0,     0,     0,  2077,     0,     0,     0,
     642,     0,  1492,     0,     0,     0,     0,  1497,   481,   482,
     483,   484,   485,   486,   487,   488,   489,   490,   491,   492,
     493,   494,  2102,     0,     0,     0,   495,     0,     0,     0,
       0,     0,     0,     0,     0,   519,   578,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1539,
       0,     0,     0,   687,   688,     0,     0,     0,  1547,     0,
     578,     0,  1550,  1551,     0,     0,   696,     0,     0,     0,
       0,     0,     0,   574,     0,     0,     0,  1560,  1562,     0,
       0,   975,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2153,  2154,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   734,     0,     0,   855,   857,     0,
       0,   481,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,     0,     0,   876,   519,   495,
       0,     0,     0,     0,     0,   883,     0,     0,   481,   482,
     483,   484,   485,   486,   487,   488,   489,   490,   491,   817,
     493,   494,  1626,  1627,  1628,     0,   495,     0,     0,   519,
     519,     0,     0,     0,  1640,     0,  1642,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1647,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     518,     0,     0,     0,     0,  1663,     0,     0,     0,     0,
       0,     0,     0,  1668,  1669,  1670,   519,   519,   519,     0,
       0,   481,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,     0,     0,   588,     0,   495,
     519,   849,     0,   850,     0,  1690,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   579,   493,   494,
     519,     0,     0,     0,   495,     0,     0,     0,     0,  1702,
     481,   482,   483,   484,   485,   486,   487,   488,   489,   490,
     491,   817,   493,   494,     0,  1716,     0,     0,   495,     0,
    1722,   481,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,  1730,  1731,     0,     0,   495,
       0,     0,  1736,  1737,     0,     0,     0,  1739,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1743,  1744,  1745,  1746,  1747,  1748,  1749,
       0,     0,     0,     0,     0,   520,     0,  1755,     0,     0,
     525,  1089,     0,     0,   529,     0,     0,   518,   518,  1767,
       0,  1768,     0,     0,     0,     0,     0,   519,   542,     0,
    1173,   519,     0,     0,  1786,     0,     0,     0,     0,     0,
       0,     0,     0,   883,  1125,     0,     0,     0,     0,     0,
       7,     8,     0,     0,   518,     0,     0,     0,  1804,     0,
     584,     0,     0,     0,     0,     0,     0,     0,     0,  1814,
       0,     0,     0,     0,     0,     0,     0,   519,     0,   519,
       0,     0,   519,     0,     0,     0,     0,  1063,     0,  1834,
       0,  1069,     0,     0,     0,   519,     0,   519,     0,   519,
       0,   519,     0,     0,     0,     0,     0,   519,     0,     0,
       0,     0,   519,  1849,  1850,     0,     0,     0,     0,     0,
       0,  1856,   769,    24,    25,   770,    27,    28,   771,    30,
     772,    32,    33,    34,    35,     0,     0,     0,    37,    38,
      39,     0,    40,     0,   519,     0,  1875,    45,   773,    47,
       0,     0,    49,   774,     0,    52,    53,    54,     0,     0,
       0,    57,     0,     0,     0,     0,     0,     0,  1885,     0,
       0,     0,     0,     0,  1478,    70,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1900,     0,     0,
       0,     0,     0,     0,     0,     0,   573,     0,     0,     0,
       0,    84,    85,    86,  1911,     0,  1912,     0,     0,   518,
       0,   481,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,  1184,  1926,     0,     0,   495,
     481,   482,   483,   484,   485,   486,   487,   488,   489,   490,
     491,   492,   493,   494,  1932,     0,     0,   777,   495,  1936,
       0,     0,     0,     0,     0,   519,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1950,  1951,  1952,  1953,
    1954,     0,     0,   958,     0,     0,     0,   518,     0,     0,
       0,     0,     0,     0,  1969,     0,  1972,     0,  1975,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   518,     0,
       0,     0,     0,     0,     0,     0,  1991,   519,   519,   519,
     519,     0,     0,     0,     0,     0,     0,     0,     0,  1271,
       0,     0,     0,  1275,     0,     0,     0,  1280,     0,  2005,
    2006,     0,     0,     0,  2008,     0,     0,     0,     0,     0,
     877,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2019,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2030,     0,     0,     0,     0,     0,     0,
    1297,   916,   917,   519,   481,   482,   483,   484,   485,   486,
     487,   488,   489,   490,   491,   492,   493,   494,     0,     0,
       0,     0,   495,     0,  2056,     0,     0,     0,     0,     0,
    1722,     0,     0,     0,     0,   519,     0,     0,     0,  2067,
    2068,  2069,  2070,  2071,  2072,     0,     0,     0,   959,   960,
     961,     0,     0,     0,     0,     0,     0,     0,  2083,     0,
       0,  2087,     0,     0,  2091,     0,     0,     0,  2094,     0,
       0,     0,   979,   518,   518,   518,   518,   518,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2109,  1360,  1361,
    2111,  1363,   999,  1366,  1367,     0,     0,  1370,  1371,  1372,
    1373,  1374,  1375,  1376,  1377,     0,   375,   134,     0,     0,
       0,   481,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,     0,     0,     0,     0,   495,
       0,     0,     0,  1397,   503,   134,  1808,     0,  1809,  1401,
    2147,  2148,  2149,  2150,  2151,  2152,   161,   162,   163,   164,
     165,   166,   167,   168,   169,     0,     0,     0,     0,   174,
     175,   176,   177,   518,     0,     0,     0,   179,   180,   181,
       0,     0,   182,     0,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   187,     0,     0,     0,   174,   175,   176,
     177,     0,     0,     0,     0,   179,   180,   181,     0,  1109,
     182,     0,  1462,  1113,     0,  2198,  2199,  2200,  2201,  2202,
    2203,   187,     0,     0,     0,  1473,  1474,  1475,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1487,   481,   482,   483,   484,   485,   486,   487,   488,
     489,   490,   491,   492,   493,   494,     0,     0,     0,  1151,
     495,  1152,     0,     0,  1154,     0,     0,  1967,     0,  1968,
       0,     0,     0,     0,     0,     0,     0,  1166,     0,  1167,
       0,  1168,     0,  1169,     0,     0,     0,     0,     0,  1174,
       0,     0,     0,     0,  1177,     0,     0,     0,     0,   190,
     191,   192,     0,     0,     0,     0,     0,     0,     0,  1553,
       0,     0,   199,     0,   200,   107,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1202,   190,   191,   192,
     519,     0,     0,  1574,     0,     0,     0,     0,     0,  1580,
     199,     0,   200,   107,     0,     0,     0,     0,     0,     0,
       0,  1591,     0,     0,     0,   481,   482,   483,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,     7,
       8,     0,     0,   495,  1608,  1609,  1610,     0,     0,     0,
    1613,  1614,  1087,  1615,     0,  1616,     0,  1617,     0,  1618,
    1619,  1620,   481,   482,   483,   484,   485,   486,   487,   488,
     489,   490,   491,   492,   493,   494,     0,     0,     0,  1641,
     495,     0,     0,     0,   887,     0,     0,     0,     0,  1146,
       0,     0,     0,     0,  1651,     0,     0,     0,     0,     0,
       0,     0,  1659,     0,     0,     0,     0,  1294,     0,     0,
       0,   769,    24,    25,   770,    27,    28,   771,    30,   772,
      32,    33,    34,    35,     0,     0,     0,    37,    38,    39,
       0,    40,     0,     0,     0,     0,    45,   773,    47,     0,
       0,    49,   774,     0,    52,    53,    54,     0,     0,     0,
      57,     0,     0,     0,     0,     0,     0,   519,   519,  1327,
    1328,  1329,  1330,     0,    70,     0,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
       0,     0,     0,     0,   495,     0,     0,     0,     0,  1714,
      84,    85,    86,  1162,   519,     0,     0,     0,     0,     0,
       0,     0,  1726,     0,  1006,  1007,  1008,  1009,  1010,  1011,
    1012,  1013,  1014,  1015,  1016,     0,  1018,  1019,  1020,  1021,
    1022,  1023,  1024,     0,     0,  1381,  1028,  1030,  1031,     0,
       0,     0,  1035,  1036,     0,  1038,     0,     0,     0,     0,
    1043,  1044,  1045,     0,  1047,     0,     0,     0,     0,     0,
       0,  1055,  1057,     0,     0,     0,     0,  1402,     0,     0,
       0,     0,   980,     0,     0,     0,     0,     0,     0,  1080,
       0,     0,     0,     0,     0,     0,     0,     0,  1785,   481,
     482,   483,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   493,   494,  1553,     0,     0,     0,   495,     0,     0,
       0,     0,     0,     0,     0,     0,  1233,     0,  1807,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1819,     0,
       0,     0,     0,   234,   235,     0,     0,     0,  1826,     0,
       0,     0,     0,  1831,     0,     0,   574,     0,     0,     0,
       0,     0,     0,     0,     0,   379,   134,     0,     0,   519,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1851,     0,     0,  1159,     0,     0,  1927,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1170,     0,
       0,     0,     0,  1553,     0,   161,   162,   163,   164,   165,
     166,   167,   168,   169,     0,     0,     0,     0,   174,   175,
     176,   177,     0,     0,     0,     0,   179,   180,   181,     0,
       0,   182,     0,     0,     0,     0,     0,   519,     0,     0,
       0,     0,   187,     0,     0,     0,     0,     0,     0,  1897,
       0,     0,   397,     0,     0,     0,     0,     0,   519,     0,
       0,   411,   412,   413,   414,   415,   416,   417,   418,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,   435,     0,     0,     0,   439,
     440,   441,   442,     0,   444,   445,   446,   447,   448,   449,
       0,     0,   451,     0,     0,     0,     0,     0,   452,   453,
       0,     0,     0,  1553,   458,   459,     0,     0,     0,     0,
    1941,  1942,     0,     0,   481,   482,   483,   484,   485,   486,
     487,   488,   489,   490,   491,   492,   493,   494,     0,  1553,
       0,     0,   495,     0,     0,     0,     0,     0,   190,   191,
     192,  1283,     0,     0,     0,     0,     0,     0,     0,  1981,
       0,   199,  1661,   200,     0,     0,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
       0,     0,     0,     0,   495,     0,     0,   550,     0,   553,
     554,   555,   556,  1429,     0,     0,     0,     0,     0,     0,
     571,     0,     0,   519,   519,   519,   519,   519,     0,     0,
    1333,   582,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2023,     0,   481,   482,   483,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,     0,     0,     0,
    2040,   495,     0,  1355,  1356,     0,     0,     0,     0,     0,
    1770,     0,     0,     0,     0,     0,     0,     0,     0,   132,
     133,   134,     0,     0,     0,   135,   136,   137,     0,     0,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   519,     0,     0,     0,     0,     0,     0,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,     0,  1765,
    1766,   179,   180,   181,  1553,     0,   182,     0,   183,   184,
     185,     0,   132,   385,     0,     0,   186,   187,   135,   136,
     137,     0,     0,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,     0,     0,   481,   482,
     483,   484,   485,   486,   487,   488,   489,   490,   491,   492,
     493,   494,   170,   171,   172,   173,   495,     0,     0,     0,
     178,     0,     0,     0,   918,   767,     0,     0,     0,     0,
       0,   183,   184,   185,     0,     0,  1499,     0,     0,   186,
       0,     0,  1503,  1504,  1505,  1506,  1507,     0,  1510,     0,
    1512,  1513,     0,  1516,  1519,     0,     0,  1523,  1524,  1525,
       0,     0,     0,     0,  1529,   188,  1553,     0,     0,     0,
       0,     0,   189,   190,   191,   192,   193,     0,     0,     0,
       0,   194,   195,   196,   197,   198,   199,     0,   200,   107,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   201,   202,     0,     0,     0,   203,     0,
       0,     0,     0,   204,     0,   205,     0,   206,   207,     0,
     208,     0,   209,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1594,     0,     0,     0,     0,
       0,  1913,     0,     0,     0,   189,     0,     0,     0,   193,
       0,     0,  1605,     0,   194,   195,   196,   197,   198,     0,
       0,   134,   107,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   201,   202,     0,     0,
       0,   203,     0,     0,     0,     0,   357,   466,     0,     0,
       0,   207,     0,     0,     0,     0,     0,     0,     0,     0,
     161,   162,   163,   164,   165,   166,   167,   168,   169,  1965,
       0,     0,     0,   174,   175,   176,   177,     0,     0,     0,
       0,   179,   180,   181,     0,     0,   182,     0,     0,     0,
    1985,     0,     0,     0,     0,     0,     0,   187,     0,     0,
       0,  1679,     0,     0,     0,     0,  1683,   481,   482,   483,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
     494,     0,     0,     0,     0,   495,     0,     0,     0,     0,
       0,     0,     0,     0,  1790,     0,     0,     0,  1696,  1697,
       0,     0,  1699,  1700,   132,   265,     0,     0,     0,     0,
     135,   136,   137,     0,     0,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   266,   267,
     268,   269,   270,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   170,   171,   172,   173,     0,     0,
       0,     0,   178,   190,   191,   192,     0,     0,     0,     0,
       0,     0,     0,   183,   184,   185,   199,     0,   200,     0,
       0,   186,     0,     0,     0,   271,     0,     0,   272,     0,
       0,   273,     0,   274,     0,  2098,  2099,  2100,  2101,  2103,
      36,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   275,     0,    48,     0,     0,   276,     0,     0,   277,
       0,     0,     0,     0,     0,     0,    59,    60,    61,    62,
      63,     0,     0,    65,    66,    67,    68,    69,     0,     0,
       0,    73,     0,     0,    76,     0,     0,     0,     0,     0,
       0,     0,  1821,  1822,     0,     0,  1824,  1825,     0,     0,
       0,     0,  1828,  1829,     0,     0,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
       0,     0,     0,     0,   495,  2169,     0,   189,     0,     0,
       0,   193,   278,  1861,     0,     0,   194,   195,   196,   197,
     198,     0,     0,     0,   107,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1868,  1869,     0,   624,  1800,
       0,     0,     0,   203,     0,     0,     0,     0,   626,     0,
       0,     0,     0,   207,     0,   318,   576,     0,     0,   132,
     265,     0,     0,     0,     0,   135,   136,   137,     0,     0,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   266,   267,   268,   269,   270,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   170,
     171,   172,   173,     0,     0,     0,     0,   178,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   183,   184,
     185,     0,     0,     7,     8,     0,   186,     0,     0,     0,
     271,     0,     0,   272,     0,     0,   273,     0,   274,     0,
       0,     0,     0,  1307,  1308,    36,     0,     0,     0,  1312,
    1313,     0,     0,     0,     0,     0,   275,     0,    48,     0,
       0,   276,     0,     0,   277,     0,     0,     0,     0,     0,
       0,    59,    60,    61,    62,    63,     0,     0,    65,    66,
      67,    68,    69,     0,     0,     0,    73,     0,     0,    76,
       0,     0,     0,     0,     0,   769,    24,    25,   770,    27,
      28,   771,    30,   772,    32,    33,    34,    35,     0,     0,
       0,    37,    38,    39,     0,    40,     0,     0,     0,     0,
      45,   773,    47,     0,     0,    49,   774,     0,    52,    53,
      54,     0,   189,     0,    57,     0,   193,   278,     0,     0,
       0,   194,   195,   196,   197,   198,     0,     0,    70,   107,
       0,     0,   985,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   201,   517,     0,     0,     0,   203,     0,
       0,     0,     0,   357,    84,    85,    86,     0,   207,     0,
       0,   576,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   132,   265,   134,     0,     0,
       0,   135,   136,   137,     0,     0,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   266,
     267,   268,   269,   270,     0,     0,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,     0,  1489,  1490,   179,   180,   181,
    1494,  1495,   182,     0,   183,   184,   185,     0,     0,     0,
       0,     0,   186,   187,     0,     0,   271,     0,     0,   272,
       0,     0,   273,     0,   274,     0,     0,     0,     0,     0,
       0,    36,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   275,     0,    48,     0,     0,   276,     0,     0,
     277,     0,     0,     0,     0,     0,     0,    59,    60,    61,
      62,    63,     0,     0,    65,    66,    67,    68,    69,     0,
    2178,     0,    73,     0,     0,    76,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
       0,     0,     0,     0,   495,     0,     0,     0,     0,     0,
       0,     0,     0,  1862,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   189,   190,
     191,   192,   193,   278,     0,     0,     0,   194,   195,   196,
     197,   198,   199,     0,   200,   107,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   201,
     279,     0,     0,     0,   203,     0,     0,     0,     0,   357,
       0,   132,   265,   134,   207,     0,   281,   135,   136,   137,
       0,     0,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   266,   267,   268,   269,   270,
       0,     0,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
       0,     0,     0,   179,   180,   181,     0,     0,   182,     0,
     183,   184,   185,     0,     0,     0,     0,     0,   186,   187,
       0,     0,   271,     0,     0,   272,     0,     0,   273,     0,
     274,     0,     0,     0,     0,     0,     0,    36,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   275,     0,
      48,     0,     0,   276,     0,     0,   277,     0,     0,     0,
       0,     0,     0,    59,    60,    61,    62,    63,     0,     0,
      65,    66,    67,    68,    69,     0,     0,     0,    73,     0,
       0,    76,   481,   482,   483,   484,   485,   486,   487,   488,
     489,   490,   491,   492,   493,   494,     0,     0,     0,     0,
     495,     0,     0,     0,     0,     0,     0,     0,     0,  1863,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   189,   190,   191,   192,   193,   278,
       0,     0,     0,   194,   195,   196,   197,   198,   199,     0,
     200,   107,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   201,   279,     0,     0,     0,
     203,     0,     0,     0,     0,   357,     0,   132,   265,   356,
     207,     0,  1830,   135,   136,   137,     0,     0,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   266,   267,   268,   269,   270,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   170,   171,   172,
     173,     0,     0,     0,     0,   178,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   183,   184,   185,     0,
       0,     0,     0,     0,   186,     0,     0,     0,   271,     0,
       0,   272,     0,     0,   273,     0,   274,     0,     0,     0,
       0,     0,     0,    36,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   275,     0,    48,     0,     0,   276,
       0,     0,   277,     0,     0,     0,     0,     0,     0,    59,
      60,    61,    62,    63,     0,     0,    65,    66,    67,    68,
      69,     0,     0,     0,    73,     0,     0,    76,   481,   482,
     483,   484,   485,   486,   487,   488,   489,   490,   491,   492,
     493,   494,     0,     0,     0,     0,   495,     0,     0,     0,
       0,     0,     0,     0,     0,  1864,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     189,     0,     0,     0,   193,   278,     0,     0,     0,   194,
     195,   196,   197,   198,     0,     0,     0,   107,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   201,   279,     0,     0,     0,   203,     0,     0,     0,
       0,   357,     0,   132,   265,  1650,   207,     0,   281,   135,
     136,   137,     0,     0,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   266,   267,   268,
     269,   270,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   170,   171,   172,   173,     0,     0,     0,
       0,   178,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   183,   184,   185,     0,     0,     0,     0,     0,
     186,     0,     0,     0,   271,     0,     0,   272,     0,     0,
     273,     0,   274,     0,     0,     0,     0,     0,     0,    36,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     275,     0,    48,     0,     0,   276,     0,     0,   277,     0,
       0,     0,     0,     0,     0,    59,    60,    61,    62,    63,
       0,     0,    65,    66,    67,    68,    69,     0,     0,     0,
      73,     0,     0,    76,   481,   482,   483,   484,   485,   486,
     487,   488,   489,   490,   491,   492,   493,   494,     0,     0,
       0,     0,   495,     0,     0,     0,     0,     0,     0,     0,
       0,  1865,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   189,     0,     0,     0,
     193,   278,     0,     0,     0,   194,   195,   196,   197,   198,
       0,     0,     0,   107,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   201,   279,     0,
       0,     0,   203,     0,     0,     0,     0,   357,     0,   132,
     265,     0,   207,     0,   281,   135,   136,   137,     0,     0,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   266,   267,   268,   269,   270,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   170,
     171,   172,   173,     0,     0,     0,     0,   178,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   183,   184,
     185,     0,     0,     0,     0,     0,   186,     0,     0,     0,
     271,     0,     0,   272,     0,     0,   273,     0,   274,     0,
       0,     0,     0,     0,     0,    36,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   275,     0,    48,     0,
       0,   276,     0,     0,   277,     0,     0,     0,     0,     0,
       0,    59,    60,    61,    62,    63,     0,     0,    65,    66,
      67,    68,    69,     0,     0,     0,    73,     0,     0,    76,
     481,   482,   483,   484,   485,   486,   487,   488,   489,   490,
     491,   492,   493,   494,     0,     0,     0,     0,   495,     0,
       0,     0,     0,     0,     0,     0,     0,  1909,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   189,     0,     0,     0,   193,   278,     0,     0,
       0,   194,   195,   196,   197,   198,     0,     0,     0,   107,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   201,   279,     0,     0,     0,   203,     0,
       0,     0,     0,   280,     0,   132,   265,     0,   207,     0,
     281,   135,   136,   137,     0,     0,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   266,
     267,   268,   269,   270,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   170,   171,   172,   173,     0,
       0,     0,     0,   178,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   183,   184,   185,     0,     0,     0,
       0,     0,   186,     0,     0,     0,   271,     0,     0,   272,
       0,     0,   273,     0,   274,     0,     0,     0,     0,     0,
       0,    36,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   275,     0,    48,     0,     0,   276,     0,     0,
     277,     0,     0,     0,     0,     0,     0,    59,    60,    61,
      62,    63,     0,     0,    65,    66,    67,    68,    69,     0,
       0,     0,    73,     0,     0,    76,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
       0,     0,     0,     0,   495,     0,     0,     0,     0,     0,
       0,     0,     0,  1955,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   189,     0,
       0,     0,   193,   278,     0,     0,     0,   194,   195,   196,
     197,   198,     0,     0,     0,   107,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   201,
     279,     0,     0,     0,   203,     0,     0,     0,     0,   357,
       0,   132,   265,     0,   207,     0,   281,   135,   136,   137,
       0,     0,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   266,   267,   268,   269,   270,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   170,   171,   172,   173,     0,     0,     0,     0,   178,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     183,   184,   185,     0,     0,     0,     0,     0,   186,     0,
       0,     0,   271,     0,     0,   272,     0,     0,   273,     0,
     274,     0,     0,     0,     0,     0,     0,    36,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   275,     0,
      48,     0,     0,   276,     0,     0,   277,     0,     0,     0,
       0,     0,     0,    59,    60,    61,    62,    63,     0,     0,
      65,    66,    67,    68,    69,     0,     0,     0,    73,     0,
       0,    76,   481,   482,   483,   484,   485,   486,   487,   488,
     489,   490,   491,   492,   493,   494,     0,     0,     0,     0,
     495,     0,     0,     0,     0,     0,     0,     0,     0,  1983,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   189,     0,     0,     0,   193,   278,
       0,     0,     0,   194,   195,   196,   197,   198,     0,     0,
       0,   107,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   201,   517,     0,     0,     0,
     203,     0,     0,     0,     0,   357,     0,   132,   265,     0,
     207,     0,   572,   135,   136,   137,     0,     0,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   266,   267,   268,   269,   270,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   170,   171,   172,
     173,     0,     0,     0,     0,   178,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   183,   184,   185,     0,
       0,     0,     0,     0,   186,     0,     0,     0,   271,     0,
       0,   272,     0,     0,   273,     0,   274,     0,     0,     0,
       0,     0,     0,    36,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   275,     0,    48,     0,     0,   276,
       0,     0,   277,     0,     0,     0,     0,     0,     0,    59,
      60,    61,    62,    63,     0,     0,    65,    66,    67,    68,
      69,     0,     0,     0,    73,     0,     0,    76,   481,   482,
     483,   484,   485,   486,   487,   488,   489,   490,   491,   492,
     493,   494,     0,     0,     0,     0,   495,     0,     0,     0,
       0,     0,     0,     0,     0,  1992,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     189,     0,     0,     0,   193,   278,     0,     0,     0,   194,
     195,   196,   197,   198,     0,     0,     0,   107,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   201,   279,     0,     0,     0,   203,     0,     0,     0,
       0,   587,     0,   132,   265,     0,   207,     0,   281,   135,
     136,   137,     0,     0,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   266,   267,   268,
     269,   270,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   170,   171,   172,   173,     0,     0,     0,
       0,   178,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   183,   184,   185,     0,     0,     0,     0,     0,
     186,     0,     0,     0,   271,     0,     0,   272,     0,     0,
     273,     0,   274,     0,     0,     0,     0,     0,     0,    36,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     275,     0,    48,     0,     0,   276,     0,     0,   277,     0,
       0,     0,     0,     0,     0,    59,    60,    61,    62,    63,
       0,     0,    65,    66,    67,    68,    69,     0,     0,     0,
      73,     0,     0,    76,   481,   482,   483,   484,   485,   486,
     487,   488,   489,   490,   491,   492,   493,   494,     0,     0,
       0,     0,   495,     0,     0,     0,     0,     0,     0,     0,
       0,  1993,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   189,     0,     0,     0,
     193,   278,     0,     0,     0,   194,   195,   196,   197,   198,
       0,     0,     0,   107,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   201,   279,     0,
       0,     0,   203,     0,     0,     0,     0,   597,     0,   132,
     265,     0,   207,     0,   281,   135,   136,   137,     0,     0,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   266,   267,   268,   269,   270,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   170,
     171,   172,   173,     0,     0,     0,     0,   178,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   183,   184,
     185,     0,     0,     0,     0,     0,   186,     0,     0,     0,
     271,     0,     0,   272,     0,     0,   273,     0,   274,     0,
       0,     0,     0,     0,     0,    36,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   275,     0,    48,     0,
       0,   276,     0,     0,   277,     0,     0,     0,     0,     0,
       0,    59,    60,    61,    62,    63,     0,     0,    65,    66,
      67,    68,    69,     0,     0,     0,    73,     0,     0,    76,
     481,   482,   483,   484,   485,   486,   487,   488,   489,   490,
     491,   492,   493,   494,     0,     0,     0,     0,   495,     0,
       0,     0,     0,     0,     0,     0,     0,  2031,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   189,     0,     0,     0,   193,   278,     0,     0,
       0,   194,   195,   196,   197,   198,     0,     0,     0,   107,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   201,   279,     0,     0,     0,   203,     0,
       0,     0,     0,   599,     0,   132,   265,     0,   207,     0,
     281,   135,   136,   137,     0,     0,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   266,
     267,   268,   269,   270,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   170,   171,   172,   173,     0,
       0,     0,     0,   178,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   183,   184,   185,     0,     0,     0,
       0,     0,   186,     0,     0,     0,   271,     0,     0,   272,
       0,     0,   273,     0,   274,     0,     0,     0,     0,     0,
       0,    36,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   275,     0,    48,     0,     0,   276,     0,     0,
     277,     0,     0,     0,     0,     0,     0,    59,    60,    61,
      62,    63,     0,     0,    65,    66,    67,    68,    69,     0,
       0,     0,    73,     0,     0,    76,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
       0,     0,     0,     0,   495,     0,     0,     0,     0,     0,
       0,     0,     0,  2034,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   189,     0,
       0,     0,   193,   278,     0,     0,     0,   194,   195,   196,
     197,   198,     0,     0,     0,   107,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   201,
     279,     0,     0,     0,   203,     0,     0,     0,     0,   601,
       0,   132,   265,     0,   207,     0,   281,   135,   136,   137,
       0,     0,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   266,   267,   268,   269,   270,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   170,   171,   172,   173,     0,     0,     0,     0,   178,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     183,   184,   185,     0,     0,     0,     0,     0,   186,     0,
       0,     0,   271,     0,     0,   272,     0,     0,   273,     0,
     274,     0,     0,     0,     0,     0,     0,    36,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   275,     0,
      48,     0,     0,   276,     0,     0,   277,     0,     0,     0,
       0,     0,     0,    59,    60,    61,    62,    63,     0,     0,
      65,    66,    67,    68,    69,     0,     0,     0,    73,     0,
       0,    76,   481,   482,   483,   484,   485,   486,   487,   488,
     489,   490,   491,   492,   493,   494,     0,     0,     0,     0,
     495,     0,     0,     0,     0,     0,     0,     0,     0,  2037,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   189,     0,     0,     0,   193,   278,
       0,     0,     0,   194,   195,   196,   197,   198,     0,     0,
       0,   107,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   201,   517,     0,     0,     0,
     203,     0,     0,     0,     0,   357,     0,   132,   265,     0,
     207,     0,   853,   135,   136,   137,     0,     0,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   266,   267,   268,   269,   270,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   170,   171,   172,
     173,     0,     0,     0,     0,   178,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   183,   184,   185,     0,
       0,     0,     0,     0,   186,     0,     0,     0,   271,     0,
       0,   272,     0,     0,   273,     0,   274,     0,     0,     0,
       0,     0,     0,    36,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   275,     0,    48,     0,     0,   276,
       0,     0,   277,     0,     0,     0,     0,     0,     0,    59,
      60,    61,    62,    63,     0,     0,    65,    66,    67,    68,
      69,     0,     0,     0,    73,     0,     0,    76,   481,   482,
     483,   484,   485,   486,   487,   488,   489,   490,   491,   492,
     493,   494,     0,     0,     0,     0,   495,     0,     0,     0,
       0,     0,     0,     0,     0,  2073,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     189,     0,     0,     0,   193,   278,     0,     0,     0,   194,
     195,   196,   197,   198,     0,     0,     0,   107,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   201,   517,     0,     0,     0,   203,     0,     0,     0,
       0,   357,     0,   132,   265,     0,   207,     0,   856,   135,
     136,   137,     0,     0,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   266,   267,   268,
     269,   270,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   170,   171,   172,   173,     0,     0,     0,
       0,   178,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   183,   184,   185,     0,     0,     0,     0,     0,
     186,     0,     0,     0,   271,     0,     0,   272,     0,     0,
     273,     0,   274,     0,     0,     0,     0,     0,     0,    36,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     275,     0,    48,     0,     0,   276,     0,     0,   277,     0,
       0,     0,     0,     0,     0,    59,    60,    61,    62,    63,
       0,     0,    65,    66,    67,    68,    69,     0,     0,     0,
      73,     0,     0,    76,   481,   482,   483,   484,   485,   486,
     487,   488,   489,   490,   491,   492,   493,   494,     0,     0,
       0,     0,   495,     0,     0,     0,     0,     0,     0,     0,
       0,  2080,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   189,     0,     0,     0,
     193,   278,     0,     0,     0,   194,   195,   196,   197,   198,
       0,     0,     0,   107,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   201,   517,     0,
       0,     0,   203,     0,     0,     0,     0,   357,     0,   132,
     265,     0,   207,     0,   881,   135,   136,   137,     0,     0,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   266,   267,   268,   269,   270,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   170,
     171,   172,   173,     0,     0,     0,     0,   178,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   183,   184,
     185,     0,     0,     0,     0,     0,   186,     0,     0,     0,
     271,     0,     0,   272,     0,     0,   273,     0,   274,     0,
       0,     0,     0,     0,     0,    36,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   275,     0,    48,     0,
       0,   276,     0,     0,   277,     0,     0,     0,     0,     0,
       0,    59,    60,    61,    62,    63,     0,     0,    65,    66,
      67,    68,    69,     0,     0,     0,    73,     0,     0,    76,
     481,   482,   483,   484,   485,   486,   487,   488,   489,   490,
     491,   492,   493,   494,     0,     0,     0,     0,   495,     0,
       0,     0,     0,     0,     0,     0,     0,  2123,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   189,     0,     0,     0,   193,   278,     0,     0,
       0,   194,   195,   196,   197,   198,     0,     0,     0,   107,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   201,   279,     0,     0,     0,   203,     0,
       0,     0,     0,   357,     0,   132,   265,     0,   207,     0,
    1658,   135,   136,   137,     0,     0,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   266,
     267,   268,   269,   270,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   170,   171,   172,   173,     0,
       0,     0,     0,   178,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   183,   184,   185,     0,     0,     0,
       0,     0,   186,     0,     0,     0,   271,     0,     0,   272,
       0,     0,   273,     0,   274,     0,     0,     0,     0,     0,
       0,    36,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   275,     0,    48,     0,     0,   276,     0,     0,
     277,     0,     0,     0,     0,     0,     0,    59,    60,    61,
      62,    63,     0,     0,    65,    66,    67,    68,    69,     0,
       0,     0,    73,     0,     0,    76,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
       0,     0,     0,     0,   495,     0,     0,     0,     0,     0,
       0,     0,     0,  2125,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   189,     0,
       0,     0,   193,   278,     0,     0,     0,   194,   195,   196,
     197,   198,     0,     0,     0,   107,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   624,
    1800,     0,     0,     0,   203,     0,     0,     0,     0,   626,
       0,   132,   385,   134,   207,     0,   318,   135,   136,   137,
       0,     0,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,     0,     0,     0,     0,     0,
       0,     0,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
       0,     0,     0,   179,   180,   181,     0,     0,   182,     0,
     183,   184,   185,     0,   132,   385,   134,     0,   186,   187,
     135,   136,   137,     0,     0,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,     0,     0,
       0,     0,     0,     0,     0,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,     0,     0,     0,   179,   180,   181,     0,
       0,   182,     0,   183,   184,   185,     0,     0,     0,     0,
       0,   186,   187,   481,   482,   483,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,     0,     0,     0,
       0,   495,     0,     0,     0,     0,     0,     0,     0,     0,
    2127,     0,     0,     0,   189,   190,   191,   192,   193,     0,
       0,     0,     0,   194,   195,   196,   197,   198,   199,     0,
     200,   107,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   201,   202,     0,     0,     0,
     203,     0,     0,     0,     0,   357,     0,     0,     0,     0,
     207,     0,  1813,     0,     0,   481,   482,   483,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,     0,
       0,     0,     0,   495,     0,     0,     0,   189,   190,   191,
     192,   193,  2146,     0,     0,     0,   194,   195,   196,   197,
     198,   199,     0,   200,   107,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   201,   202,
       0,     0,     0,   203,     0,     0,     0,     0,   357,     0,
     132,   265,     0,   207,     0,  1833,   135,   136,   137,     0,
       0,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   266,   267,   268,   269,   270,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     170,   171,   172,   173,     0,     0,     0,     0,   178,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   183,
     184,   185,     0,     0,     0,     0,     0,   186,     0,     0,
       0,   271,     0,     0,   272,     0,     0,   273,     0,   274,
       0,     0,     0,     0,     0,     0,    36,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   275,     0,    48,
       0,     0,   276,     0,     0,   277,     0,     0,     0,     0,
       0,     0,    59,    60,    61,    62,    63,     0,     0,    65,
      66,    67,    68,    69,     0,     0,     0,    73,     0,     0,
      76,   481,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,     0,     0,     0,     0,   495,
       0,     0,     0,     0,     0,     0,     0,     0,  2177,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   189,     0,     0,     0,   193,   278,     0,
       0,     0,   194,   195,   196,   197,   198,     0,     0,     0,
     107,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   201,   517,     0,     0,     0,   203,
     132,   385,   134,     0,   357,     0,   135,   136,   137,   207,
       0,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,     0,     0,     0,     0,     0,     0,
       0,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,     0,
       0,     0,   179,   180,   181,     0,     0,   182,     0,   183,
     184,   185,     0,   132,   385,     0,     0,   186,   187,   135,
     136,   137,     0,     0,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,     0,     0,   481,
     482,   483,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   493,   494,   170,   171,   172,   173,   495,     0,     0,
       0,   178,     0,     0,     0,     0,  2216,     0,     0,     0,
       0,     0,   183,   184,   185,     0,     0,     0,     0,     0,
     186,   481,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,     0,     0,     0,     0,   495,
       0,     0,     0,     0,     0,     0,     0,     0,  2217,     0,
       0,     0,     0,   189,   190,   191,   192,   193,     0,     0,
       0,     0,   194,   195,   196,   197,   198,   199,     0,   200,
     107,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   201,   202,     0,     0,     0,   203,
       0,     0,     0,     0,   357,     0,     0,     0,     0,   207,
     481,   482,   483,   484,   485,   486,   487,   488,   489,   490,
     491,   492,   493,   494,     0,     0,     0,     0,   495,     0,
       0,     0,     0,     0,     0,     0,   189,  2218,     0,     0,
     193,     0,     0,     0,     0,   194,   195,   196,   197,   198,
       0,     0,     0,   107,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   201,   202,     0,
       0,     0,   203,     0,     0,     0,     0,   357,   132,   385,
     468,     0,   207,     0,   135,   136,   137,     0,     0,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,     0,     0,   481,   482,   483,   484,   485,   486,
     487,   488,   489,   490,   491,   492,   493,   494,   170,   171,
     172,   173,   495,     0,     0,     0,   178,     0,     0,     0,
       0,  2219,     0,     0,     0,   132,   385,   183,   184,   185,
       0,   135,   136,   137,     0,   186,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,     0,
       0,   481,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,   170,   171,   172,   173,   495,
       0,     0,     0,   178,     0,     0,     0,     0,  2220,     0,
       0,     0,     0,     0,   183,   184,   185,     0,     0,     0,
       0,     0,   186,   481,   482,   483,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,     0,     0,     0,
       0,   495,     0,     0,     0,     0,     0,     0,     0,     0,
    2221,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   189,     0,     0,     0,   193,     0,     0,     0,     0,
     194,   195,   196,   197,   198,     0,     0,     0,   107,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   201,   202,     0,     0,     0,   203,     0,     0,
       0,     0,   357,   689,     0,     0,     0,   207,   481,   482,
     483,   484,   485,   486,   487,   488,   489,   490,   491,   492,
     493,   494,     0,     0,     0,     0,   495,     0,   189,     0,
       0,     0,   193,     0,  1881,     0,     0,   194,   195,   196,
     197,   198,     0,     0,     0,   107,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   201,
     202,     0,     0,     0,   203,     0,     0,     0,     0,   357,
     132,   385,   691,  1267,   207,     0,   135,   136,   137,     0,
       0,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,     0,     0,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     170,   171,   172,   173,   495,     0,   967,     0,   178,     0,
       0,   925,     0,     0,     0,     0,     0,     0,     0,   183,
     184,   185,   132,   385,     0,  1436,     0,   186,   135,   136,
     137,     0,     0,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,     0,     0,   481,   482,
     483,   484,   485,   486,   487,   488,   489,   490,   491,   492,
     493,   494,   170,   171,   172,   173,   495,     0,     0,     0,
     178,     0,     0,   806,     0,     0,     0,     0,     0,     0,
       0,   183,   184,   185,     0,     0,     0,     0,     0,   186,
     481,   482,   483,   484,   485,   486,   487,   488,   489,   490,
     491,   492,   493,   494,     0,     0,     0,     0,   495,     0,
     849,     0,   850,     0,     0,  1509,     0,     0,     0,     0,
       0,     0,     0,   189,     0,     0,     0,   193,     0,     0,
       0,     0,   194,   195,   196,   197,   198,     0,     0,     0,
     107,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   201,   202,     0,     0,     0,   203,
       0,     0,     0,     0,   357,     0,     0,     0,     0,   207,
       0,   481,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,     0,     0,     0,     0,   495,
       0,     0,     0,     0,     0,   189,   925,     0,     0,   193,
       0,     0,     0,     0,   194,   195,   196,   197,   198,     0,
       0,     0,   107,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   201,   202,     0,     0,
       0,   203,   132,   385,     0,     0,   357,     0,   135,   136,
     137,   207,     0,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,     0,     0,     0,     7,
       8,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   170,   171,   172,   173,     0,     0,     0,     0,
     178,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   183,   184,   185,     0,     0,     0,     0,     0,   186,
     481,   482,   483,   484,   485,   486,   487,   488,   489,   490,
     491,   492,   493,   494,     0,     0,     0,     0,   495,     0,
       0,     0,     0,     0,     0,   926,     0,     0,     0,     0,
       0,   769,    24,    25,   770,    27,    28,   771,    30,   772,
      32,    33,    34,    35,     0,     0,     0,    37,    38,    39,
       0,    40,     0,     0,     0,     0,    45,   773,    47,     0,
       0,    49,   774,     0,    52,    53,    54,     0,     0,     0,
      57,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     7,     8,     0,    70,     0,     0,     0,   481,   482,
     483,   484,   485,   486,   487,   488,   489,   490,   491,   492,
     493,   494,     0,     0,     0,   189,   495,     0,     0,   193,
      84,    85,    86,   972,   194,   195,   196,   197,   198,     0,
       0,     0,   107,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   201,   202,     7,     8,
       0,   203,     0,     0,     0,     0,   357,     0,     0,     0,
       0,   207,     0,   769,    24,    25,   770,    27,    28,   771,
      30,   772,    32,    33,    34,    35,     0,     0,     0,    37,
      38,    39,     0,    40,     0,     0,     0,     0,    45,   773,
      47,     0,   981,    49,   774,     0,    52,    53,    54,     0,
       0,     0,    57,     0,     0,     7,     8,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    70,     0,     0,     0,
     769,    24,    25,   770,    27,    28,   771,    30,   772,    32,
      33,    34,    35,     0,     0,     0,    37,    38,    39,     0,
      40,     0,    84,    85,    86,    45,   773,    47,     0,     0,
      49,   774,     0,    52,    53,    54,     0,     0,     0,    57,
       0,     0,     7,     8,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    70,     0,     0,     0,   769,    24,    25,
     770,    27,    28,   771,    30,   772,    32,    33,    34,    35,
       0,     0,     0,    37,    38,    39,     0,    40,     0,    84,
      85,    86,    45,   773,    47,     0,     0,    49,   774,     0,
      52,    53,    54,     0,  1205,     0,    57,     0,     0,     7,
       8,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      70,     0,     0,     0,   769,    24,    25,   770,    27,    28,
     771,    30,   772,    32,    33,    34,    35,     0,     0,     0,
      37,    38,    39,     0,    40,     0,    84,    85,    86,    45,
     773,    47,     0,     0,    49,   774,     0,    52,    53,    54,
       0,  1206,     0,    57,     0,     0,     7,     8,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    70,     0,     0,
       0,   769,    24,    25,   770,    27,    28,   771,    30,   772,
      32,    33,    34,    35,     0,     0,     0,    37,    38,    39,
       0,    40,     0,    84,    85,    86,    45,   773,    47,     0,
       0,    49,   774,     0,    52,    53,    54,     0,  1230,     0,
      57,     0,     0,     7,     8,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    70,     0,     0,     0,   769,    24,
      25,   770,    27,    28,   771,    30,   772,    32,    33,    34,
      35,     0,     0,     0,    37,    38,    39,     0,    40,     0,
      84,    85,    86,    45,   773,    47,     0,     0,    49,   774,
       0,    52,    53,    54,     0,  1259,     0,    57,     0,     0,
       7,     8,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    70,     0,     0,     0,   769,    24,    25,   770,    27,
      28,   771,    30,   772,    32,    33,    34,    35,     0,     0,
       0,    37,    38,    39,     0,    40,     0,    84,    85,    86,
      45,   773,    47,     0,     0,    49,   774,     0,    52,    53,
      54,     0,  1265,     0,    57,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    70,     0,
       0,     0,   769,    24,    25,   770,    27,    28,   771,    30,
     772,    32,    33,    34,    35,     0,     0,     0,    37,    38,
      39,     0,    40,     0,    84,    85,    86,    45,   773,    47,
       0,     0,    49,   774,     0,    52,    53,    54,     0,  1425,
       0,    57,     0,     0,     0,     0,     0,     0,     0,     0,
      -4,     1,     0,     0,    -4,    70,     0,     0,     0,     0,
       0,     0,    -4,    -4,     0,     0,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
       0,    84,    85,    86,   495,     0,     0,     0,     0,     0,
       0,  1017,    -4,    -4,     0,     0,  2043,   481,   482,   483,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
     494,     0,    -4,    -4,    -4,   495,     0,     0,    -4,    -4,
       0,    -4,  1025,     0,     0,    -4,    -4,     0,    -4,    -4,
       0,     0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,     0,    -4,
      -4,    -4,    -4,  2131,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,     0,     0,     0,    -4,
      -4,    -4,     6,     0,     0,     0,     0,    -4,     0,     0,
       7,     8,    -4,    -4,    -4,    -4,     0,     0,    -4,     0,
      -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,     0,     0,     0,     0,
       9,    10,    -4,    -4,    -4,     0,     0,     0,     0,     0,
       0,    -4,     0,    -4,     0,     0,     0,     0,     0,     0,
      11,    12,    13,     0,     0,     0,    14,    15,     0,    16,
       0,     0,     0,    17,    18,     0,    19,    20,     0,     0,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,     0,     0,    36,    37,    38,
      39,     0,    40,    41,    42,    43,    44,    45,    46,    47,
      48,     0,    49,    50,    51,    52,    53,    54,    55,     0,
      56,    57,    58,    59,    60,    61,    62,    63,    64,     0,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,     7,     8,     0,    79,    80,    81,
       0,     0,     0,     0,     0,    82,     0,     0,     0,     0,
      83,    84,    85,    86,     0,     0,    87,     0,    88,     0,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,     0,     0,     0,     0,     0,     0,
     103,   104,   105,     0,     0,     0,     0,     0,     0,   106,
       0,   107,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   769,    24,    25,   770,
      27,    28,   771,    30,   772,    32,    33,    34,    35,     0,
       0,     0,    37,    38,    39,     0,    40,     0,     0,     0,
       0,    45,   773,    47,     0,     0,    49,   774,     0,    52,
      53,    54,     0,     0,     0,    57,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    70,
       0,     0,     0,   481,   482,   483,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,     0,     0,     0,
       0,   495,     0,     0,     0,    84,    85,    86,  1026,   481,
     482,   483,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   493,   494,     0,     0,     0,     0,   495,     0,     0,
       0,     0,     0,     0,  1027,   481,   482,   483,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,     0,
       0,     0,     0,   495,     0,     0,     0,     0,     0,     0,
    1042,   481,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,     0,     0,     0,     0,   495,
       0,     0,     0,     0,     0,     0,  1157,   481,   482,   483,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
     494,     0,     0,     0,     0,   495,     0,     0,     0,     0,
       0,     0,  1158,   481,   482,   483,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,     0,     0,     0,
       0,   495,     0,     0,     0,     0,     0,     0,  1160,   481,
     482,   483,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   493,   494,     0,     0,     0,     0,   495,     0,     0,
       0,     0,     0,     0,  1214,   481,   482,   483,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,     0,
       0,     0,     0,   495,     0,     0,     0,     0,     0,     0,
    1215,   481,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,     0,     0,     0,     0,   495,
       0,     0,     0,     0,     0,     0,  1216,   481,   482,   483,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
     494,     0,     0,     0,     0,   495,     0,     0,     0,     0,
       0,     0,  1253,   481,   482,   483,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,     0,     0,     0,
       0,   495,     0,     0,     0,     0,     0,     0,  1351,   481,
     482,   483,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   493,   494,     0,     0,     0,     0,   495,     0,     0,
       0,     0,     0,     0,  1427,   481,   482,   483,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,     0,
       0,     0,     0,   495,     0,     0,     0,     0,     0,     0,
    1428,   481,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,     0,     0,     0,     0,   495,
       0,     0,     0,     0,     0,     0,  1477,   481,   482,   483,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
     494,     0,     0,     0,     0,   495,     0,     0,     0,     0,
       0,     0,  1597,   481,   482,   483,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,     0,     0,     0,
       0,   495,     0,     0,     0,     0,     0,     0,  1598,   481,
     482,   483,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   493,   494,     0,     0,     0,     0,   495,     0,     0,
       0,     0,     0,     0,  1599,   481,   482,   483,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,     0,
       0,     0,     0,   495,     0,     0,     0,     0,     0,     0,
    1600,   481,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,     0,     0,     0,     0,   495,
       0,     0,     0,     0,     0,     0,  1601,   481,   482,   483,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
     494,     0,     0,     0,     0,   495,     0,     0,     0,     0,
       0,     0,  1602,   481,   482,   483,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,     0,     0,     0,
       0,   495,     0,     0,     0,     0,     0,     0,  1603,   481,
     482,   483,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   493,   494,     0,     0,     0,     0,   495,     0,     0,
       0,     0,     0,     0,  1717,   481,   482,   483,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,     0,
       0,     0,     0,   495,     0,     0,     0,     0,     0,     0,
    1718,   481,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,     0,     0,     0,     0,   495,
       0,     0,     0,     0,     0,     0,  1725,   481,   482,   483,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
     494,     0,     0,     0,     0,   495,     0,     0,     0,     0,
       0,     0,  1870,   481,   482,   483,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,     0,     0,     0,
       0,   495,     0,     0,     0,     0,     0,     0,  1871,   481,
     482,   483,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   493,   494,     0,     0,     0,     0,   495,     0,     0,
       0,     0,     0,     0,  1872,   481,   482,   483,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,     0,
       0,     0,     0,   495,     0,     0,     0,     0,     0,     0,
    1873,   481,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,     0,     0,     0,     0,   495,
       0,     0,     0,     0,     0,     0,  1874,   481,   482,   483,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
     494,     0,     0,     0,     0,   495,     0,     0,     0,     0,
       0,     0,  1933,   481,   482,   483,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,     0,     0,     0,
       0,   495,     0,     0,     0,     0,     0,     0,  1934,   481,
     482,   483,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   493,   494,     0,     0,     0,     0,   495,     0,     0,
       0,     0,     0,     0,  1938,   481,   482,   483,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,     0,
       0,     0,     0,   495,     0,     0,     0,     0,     0,     0,
    2014,   481,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,     0,     0,     0,     0,   495,
       0,     0,     0,     0,     0,     0,  2015,   481,   482,   483,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
     494,     0,     0,     0,     0,   495,     0,     0,     0,     0,
       0,     0,  2016,   481,   482,   483,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,     0,     0,     0,
       0,   495,     0,     0,     0,     0,     0,     0,  2017,   481,
     482,   483,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   493,   494,     0,     0,     0,     0,   495,     0,     0,
       0,     0,     0,     0,  2018,   481,   482,   483,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,     0,
       0,     0,     0,   495,     0,     0,     0,     0,     0,     0,
    2061,   481,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,     0,     0,     0,     0,   495,
       0,     0,     0,     0,     0,     0,  2064,   481,   482,   483,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
     494,     0,     0,     0,     0,   495,     0,     0,     0,     0,
       0,     0,  2114,   481,   482,   483,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,     0,     0,     0,
       0,   495,     0,     0,     0,     0,     0,     0,  2115,   481,
     482,   483,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   493,   494,     0,     0,     0,     0,   495,     0,     0,
       0,     0,     0,     0,  2116,   481,   482,   483,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,     0,
       0,     0,     0,   495,     0,     0,     0,     0,     0,     0,
    2117,   481,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,     0,     0,     0,     0,   495,
       0,     0,     0,     0,     0,     0,  2118,   481,   482,   483,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
     494,     0,     0,     0,     0,   495,     0,     0,     0,     0,
       0,     0,  2119,   481,   482,   483,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,     0,     0,     0,
       0,   495,     0,     0,     0,     0,     0,     0,  2179,   481,
     482,   483,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   493,   494,     0,     0,     0,     0,   495,     0,     0,
       0,     0,     0,     0,  2180,   481,   482,   483,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,     0,
       0,     0,     0,   495,     0,     0,     0,     0,     0,     0,
    2181,   481,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,     0,     0,     0,     0,   495,
       0,     0,     0,     0,     0,     0,  2182,   481,   482,   483,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
     494,     0,     0,     0,     0,   495,     0,     0,     0,   761,
     481,   482,   483,   484,   485,   486,   487,   488,   489,   490,
     491,   492,   493,   494,     0,     0,     0,     0,   495,     0,
       0,     0,   978,   481,   482,   483,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,     0,     0,     0,
       0,   495,     0,     0,     0,   997,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
       0,     0,     0,     0,   495,     0,     0,     0,  1004,   481,
     482,   483,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   493,   494,     0,     0,     0,     0,   495,     0,     0,
       0,  1102,   481,   482,   483,   484,   485,   486,   487,   488,
     489,   490,   491,   492,   493,   494,     0,     0,     0,     0,
     495,     0,     0,     0,  1150,   481,   482,   483,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,     0,
       0,     0,     0,   495,     0,     0,     0,  1176,   481,   482,
     483,   484,   485,   486,   487,   488,   489,   490,   491,   492,
     493,   494,     0,     0,     0,     0,   495,     0,     0,     0,
    1246,   481,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,     0,     0,     0,     0,   495,
       0,     0,     0,  1247,   481,   482,   483,   484,   485,   486,
     487,   488,   489,   490,   491,   492,   493,   494,     0,     0,
       0,     0,   495,     0,     0,     0,  1251,   481,   482,   483,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
     494,     0,     0,     0,     0,   495,     0,     0,     0,  1252,
     481,   482,   483,   484,   485,   486,   487,   488,   489,   490,
     491,   492,   493,   494,     0,     0,     0,     0,   495,     0,
       0,     0,  1285,   481,   482,   483,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,     0,     0,     0,
       0,   495,     0,     0,     0,  1344,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
       0,     0,     0,     0,   495,     0,     0,     0,  1349,   481,
     482,   483,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   493,   494,     0,     0,     0,     0,   495,     0,     0,
       0,  1664,   481,   482,   483,   484,   485,   486,   487,   488,
     489,   490,   491,   492,   493,   494,     0,     0,     0,     0,
     495,     0,     0,     0,  1707,   481,   482,   483,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,     0,
       0,     0,     0,   495,     0,     0,     0,  1895,   481,   482,
     483,   484,   485,   486,   487,   488,   489,   490,   491,   492,
     493,   494,     0,     0,     0,     0,   495,     0,   757,   481,
     482,   483,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   493,   494,     0,     0,     0,     0,   495,     0,   816,
     481,   482,   483,   484,   485,   486,   487,   488,   489,   490,
     491,   492,   493,   494,     0,     0,     0,     0,   495,     0,
     820,   481,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,     0,     0,     0,     0,   495,
       0,   821,   481,   482,   483,   484,   485,   486,   487,   488,
     489,   490,   491,   492,   493,   494,     0,     0,     0,     0,
     495,     0,   823,   481,   482,   483,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,     0,     0,     0,
       0,   495,     0,   825,   481,   482,   483,   484,   485,   486,
     487,   488,   489,   490,   491,   492,   493,   494,     0,     0,
       0,     0,   495,     0,   826,   481,   482,   483,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,     0,
       0,     0,     0,   495,     0,   829,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
       0,     0,     0,     0,   495,     0,   830,   481,   482,   483,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
     494,     0,     0,     0,     0,   495,     0,   831,   481,   482,
     483,   484,   485,   486,   487,   488,   489,   490,   491,   492,
     493,   494,     0,     0,     0,     0,   495,     0,   832,   481,
     482,   483,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   493,   494,     0,     0,     0,     0,   495,     0,   833,
     481,   482,   483,   484,   485,   486,   487,   488,   489,   490,
     491,   492,   493,   494,     0,     0,     0,     0,   495,     0,
     834,   481,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,     0,     0,     0,     0,   495,
       0,   836,   481,   482,   483,   484,   485,   486,   487,   488,
     489,   490,   491,   492,   493,   494,     0,     0,     0,     0,
     495,     0,   837,   481,   482,   483,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,     0,     0,     0,
       0,   495,     0,   878,   481,   482,   483,   484,   485,   486,
     487,   488,   489,   490,   491,   492,   493,   494,     0,     0,
       0,     0,   495,     0,   888,   481,   482,   483,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,     0,
       0,     0,     0,   495,     0,   949,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
       0,     0,     0,     0,   495,     0,   967,   481,   482,   483,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
     494,     0,     0,     0,     0,   495,     0,   968,   481,   482,
     483,   484,   485,   486,   487,   488,   489,   490,   491,   492,
     493,   494,     0,     0,     0,     0,   495,     0,   969,   481,
     482,   483,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   493,   494,     0,     0,     0,     0,   495,     0,   970,
     481,   482,   483,   484,   485,   486,   487,   488,   489,   490,
     491,   492,   493,   494,     0,     0,     0,     0,   495,     0,
     976,   481,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,     0,     0,     0,     0,   495,
       0,   977,   481,   482,   483,   484,   485,   486,   487,   488,
     489,   490,   491,   492,   493,   494,     0,     0,     0,     0,
     495,     0,   984,   481,   482,   483,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,     0,     0,     0,
       0,   495,     0,   993,   481,   482,   483,   484,   485,   486,
     487,   488,   489,   490,   491,   492,   493,   494,     0,     0,
       0,     0,   495,     0,  1003,   481,   482,   483,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,     0,
       0,     0,     0,   495,     0,  1101,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
       0,     0,     0,     0,   495,     0,  1129,   481,   482,   483,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
     494,     0,     0,     0,     0,   495,     0,  1134,   481,   482,
     483,   484,   485,   486,   487,   488,   489,   490,   491,   492,
     493,   494,     0,     0,     0,     0,   495,     0,  1145,   481,
     482,   483,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   493,   494,     0,     0,     0,     0,   495,     0,  1149,
     481,   482,   483,   484,   485,   486,   487,   488,   489,   490,
     491,   492,   493,   494,     0,     0,     0,     0,   495,     0,
    1175,   481,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,     0,     0,     0,     0,   495,
       0,  1180,   481,   482,   483,   484,   485,   486,   487,   488,
     489,   490,   491,   492,   493,   494,     0,     0,     0,     0,
     495,     0,  1181,   481,   482,   483,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,     0,     0,     0,
       0,   495,     0,  1182,   481,   482,   483,   484,   485,   486,
     487,   488,   489,   490,   491,   492,   493,   494,     0,     0,
       0,     0,   495,     0,  1188,   481,   482,   483,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,     0,
       0,     0,     0,   495,     0,  1197,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
       0,     0,     0,     0,   495,     0,  1198,   481,   482,   483,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
     494,     0,     0,     0,     0,   495,     0,  1199,   481,   482,
     483,   484,   485,   486,   487,   488,   489,   490,   491,   492,
     493,   494,     0,     0,     0,     0,   495,     0,  1232,   481,
     482,   483,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   493,   494,     0,     0,     0,     0,   495,     0,  1234,
     481,   482,   483,   484,   485,   486,   487,   488,   489,   490,
     491,   492,   493,   494,     0,     0,     0,     0,   495,     0,
    1235,   481,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,     0,     0,     0,     0,   495,
       0,  1236,   481,   482,   483,   484,   485,   486,   487,   488,
     489,   490,   491,   492,   493,   494,     0,     0,     0,     0,
     495,     0,  1237,   481,   482,   483,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,     0,     0,     0,
       0,   495,     0,  1238,   481,   482,   483,   484,   485,   486,
     487,   488,   489,   490,   491,   492,   493,   494,     0,     0,
       0,     0,   495,     0,  1239,   481,   482,   483,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,     0,
       0,     0,     0,   495,     0,  1240,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
       0,     0,     0,     0,   495,     0,  1245,   481,   482,   483,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
     494,     0,     0,     0,     0,   495,     0,  1343,   481,   482,
     483,   484,   485,   486,   487,   488,   489,   490,   491,   492,
     493,   494,     0,     0,     0,     0,   495,     0,  1348,   481,
     482,   483,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   493,   494,     0,     0,     0,     0,   495,     0,  1521,
     481,   482,   483,   484,   485,   486,   487,   488,   489,   490,
     491,   492,   493,   494,     0,     0,     0,     0,   495,     0,
    1546,   481,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,     0,     0,     0,     0,   495,
       0,  1713,   481,   482,   483,   484,   485,   486,   487,   488,
     489,   490,   491,   492,   493,   494,     0,     0,     0,     0,
     495,     0,  1771,   481,   482,   483,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,     0,     0,     0,
       0,   495,     0,  1789,   481,   482,   483,   484,   485,   486,
     487,   488,   489,   490,   491,   492,   493,   494,     0,     0,
       0,     0,   495,     0,  1812,   481,   482,   483,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,     0,
       0,     0,     0,   495,     0,  2060,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
       0,     0,     0,     0,   495,     0,  2144,   481,   482,   483,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
     494,     0,     0,     0,     0,   495
};

static const yytype_int16 yycheck[] =
{
       3,     3,   311,     6,     4,   433,     7,   435,   618,   619,
       4,  1652,  1675,  1676,     6,  1231,     6,     4,     4,     4,
      13,   227,   450,     5,     4,     4,   131,     5,   234,     4,
       6,     4,     4,     4,    90,     5,   326,     5,     5,     5,
       5,   121,     4,    46,    90,  1227,     6,     5,     5,     5,
      90,     6,   466,   343,   468,     6,   470,     6,   138,     6,
     217,   218,     7,     6,   110,     4,   146,   147,   148,     0,
     110,    74,   152,   153,   154,   155,   233,    87,   235,    82,
      90,     4,   217,   218,    87,     4,     6,     6,     6,   217,
     218,   228,   382,   230,   384,    98,   233,   217,   218,   234,
     390,  1742,   217,   218,   227,   233,   227,   235,    98,   168,
     100,   234,     7,   233,   227,   235,   229,   217,   218,   227,
     235,   229,   233,     6,   235,   184,   185,   227,   236,   224,
     225,     3,     4,     5,   234,   227,   231,     9,    10,    11,
       4,     6,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    84,    87,   230,     6,    90,
     233,     7,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
       6,     6,     6,    65,    66,    67,     7,  1857,    70,   179,
      72,    73,    74,   171,   207,   156,   208,     7,    80,    81,
     183,  1852,     7,   171,   171,   171,   219,   220,   203,   158,
     159,   160,   161,   203,   227,   217,   218,   227,   203,   229,
     231,   231,   235,     6,   237,   229,   236,  1878,   214,   242,
     227,   227,   236,   246,   234,   168,   169,   234,   234,   234,
     253,     6,   234,   256,   234,   234,   234,   260,   261,   262,
     263,   264,   234,   234,   234,   227,   234,   234,   234,   234,
    1452,   214,   275,   156,   234,   689,   279,   691,   281,   234,
     227,     7,   227,     3,   229,     7,     6,   234,    90,   292,
      92,     7,   295,   296,   297,   298,   235,   217,   218,   217,
     218,   304,   305,   306,   168,   169,     6,   310,   311,   204,
     205,   206,   207,     7,   186,   187,   188,   189,   190,   609,
     610,     7,   227,   195,   196,   197,   198,   199,   200,   234,
     202,   203,   224,   225,   337,   338,   339,   217,   218,   629,
     156,   156,   234,   757,     6,   217,   218,   761,   351,   352,
     222,  2011,  2012,   233,    74,   227,   217,   218,   217,   218,
     232,   231,   234,   217,   218,   470,   236,    87,   204,   205,
     206,   207,   227,   234,   229,   234,   666,   227,    98,   233,
     227,   236,   217,   218,   234,   388,   229,   217,   218,   392,
     393,   681,  2055,   204,   205,   206,   207,   229,   233,   217,
     218,     4,   405,   233,   204,   205,   206,   207,   398,   204,
     205,   206,   207,   224,   225,   233,    87,   224,   225,    90,
     231,    92,  2063,    84,   224,   225,    87,   217,   218,    90,
     433,   434,   435,   436,   437,   438,   439,   440,   441,   442,
     443,   444,   445,   233,   447,   448,   449,   450,   451,   227,
     217,   218,   455,   456,   457,   458,   459,   460,   227,   462,
     229,   217,   218,   453,   219,   220,   233,   236,   219,   220,
     221,   461,   233,   227,   235,   226,   479,   233,   204,   205,
     206,   207,   204,   205,   206,   207,   227,   207,   204,   205,
     206,   207,   217,   218,   227,   224,   225,   227,   253,   219,
     220,   234,   224,   225,     4,   234,   227,   227,   233,   264,
     204,   205,   206,   207,   517,   235,   217,   218,   204,   205,
     206,   207,   125,   126,   127,   128,   217,   218,   121,   227,
     224,   225,   233,   253,  2175,   217,   218,   140,   224,   225,
     143,   228,   233,   230,   264,   138,   227,   234,   551,   552,
     227,   233,   555,   146,   147,   148,   217,   218,   227,   152,
     153,   154,   155,   566,   217,   218,   227,   227,   571,   572,
     217,   218,   228,   234,   217,   218,   579,   233,   227,   993,
     233,   125,   126,   997,    84,   227,   233,   131,    88,   230,
     233,   311,   233,   121,    94,    95,   701,    97,    98,   227,
     603,   604,   103,   593,   594,   595,   596,   217,   218,   227,
     138,   229,   121,   227,   114,   229,   618,   619,   146,   147,
     148,    90,   236,   233,   152,   153,   154,   155,    90,   138,
     228,   921,   230,   388,   217,   218,   234,   146,   147,   148,
       6,     7,   235,   152,   153,   154,   155,   650,   651,   652,
     233,     6,   757,   217,   218,   233,   761,   235,   217,   218,
     217,   218,   217,   218,   217,   218,   224,   225,   388,   233,
      90,   674,   230,  1889,   233,  1891,   233,  1893,   233,   434,
     233,   436,   437,   438,   439,   440,   441,   442,   234,   444,
     445,   694,   447,   448,   449,   233,   451,   235,   224,   225,
     455,   456,   457,   458,   459,   228,    84,   235,   234,    87,
     233,   227,    90,   433,   434,   435,   436,   437,   438,   439,
     440,   441,   442,     8,   444,   445,   235,   447,   448,   449,
     450,   451,   227,   121,   229,   455,   456,   457,   458,   459,
     460,   236,   462,   848,   227,   217,   218,   261,   262,   263,
     138,     8,   234,   756,   217,   218,    92,   760,   146,   147,
     148,   233,   217,   218,   152,   153,   154,   155,    84,  1078,
     233,    87,   762,   227,    90,  1189,    92,  1191,   233,  1193,
     228,  1195,   296,   297,   298,   233,   121,   224,   225,  1971,
     217,   218,  1974,   217,   218,  1977,    87,   234,   801,    90,
     555,    92,   805,   138,    87,   808,   233,    87,   811,   233,
     813,   146,   147,   148,   817,   818,   234,   152,   153,   154,
     155,   224,   225,   337,   338,   815,   217,   218,  2044,   121,
     234,   234,   552,     6,     7,   555,   228,   351,   352,   224,
     225,   233,   233,   233,   227,   235,   138,   235,   851,   234,
     853,   125,   126,   856,   146,   147,   148,   131,    90,   228,
     152,   153,   154,   155,   233,   233,   869,   235,   871,   233,
     873,   235,   875,   217,   218,   219,   220,   221,   881,  1307,
    1308,   228,   226,   886,  1312,  1313,   233,    90,   993,   228,
      87,   894,   997,   227,   233,   229,     4,   231,  1003,  1004,
     235,  1315,   236,   228,   227,   230,  2122,     7,  2124,   233,
    2126,   235,   227,  2095,    84,   918,  2132,    87,     4,  1333,
      90,     4,    92,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   233,     4,   235,
     227,   226,   229,   235,   231,     8,    90,   234,    92,   236,
     235,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   233,   228,   235,   230,   226,
    2186,   233,  2188,  2155,  2190,     6,  2158,   227,   235,  2161,
     217,   218,  2164,   121,   227,   988,   227,   227,   229,   992,
     231,     6,    90,   996,    92,   236,  1101,  1102,     6,   227,
     138,  1004,   228,   233,   230,   235,   229,   233,   146,   147,
     148,   229,   227,  1322,   152,   153,   154,   155,   227,  1629,
    1630,   227,   233,  2205,   235,  2207,  1029,  2209,   228,   227,
     230,  1034,   233,   233,   235,   227,  1039,  1040,  1041,  1042,
     233,   228,   235,   230,  1149,  1150,   233,   227,     7,  1052,
     228,  1054,   230,   808,   228,   233,   230,   229,   813,   233,
     227,  1489,  1490,     4,   227,     6,  1494,  1495,   227,   227,
    1175,  1176,   233,     6,   235,  1078,     6,   234,  1081,  1082,
    1083,  1084,   233,   110,   235,  1499,   234,   233,   808,   235,
     233,   811,   235,   813,   233,   227,   235,   235,   233,   233,
     235,   235,   233,   227,   235,  1108,   234,   227,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   234,   234,  1127,  1128,   226,  1130,   227,  1132,
    1133,   227,   227,  1136,  1137,  1138,  1139,  1140,  1141,  1142,
    1143,   233,   227,   235,  1147,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   233,
     233,   235,   235,   226,   233,   228,   235,   227,   233,  1172,
     235,     4,     5,   227,   121,  1178,  1179,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   138,   227,   234,  1484,   226,  1486,     4,   234,   146,
     147,   148,   234,   227,   234,   152,   153,   154,   155,   234,
    1315,    44,    45,    46,    47,    48,    49,    50,    51,    52,
     233,   233,   235,   235,    57,    58,    59,    60,   233,   227,
     235,  1540,    65,    66,    67,   234,   227,    70,  1241,   233,
     233,   235,   235,   233,   233,   235,   235,   227,    81,  1004,
     227,  1254,  1255,  1256,   233,   233,   235,   235,   227,   233,
       6,   235,   233,   233,   235,   235,   233,  1270,   235,   233,
     233,   235,   235,   233,  1884,   235,   233,   227,   235,  1034,
     233,   233,   235,   235,  1004,  1040,  1041,  1042,   235,   233,
     233,   235,   235,   233,   233,   235,   235,  1052,   233,  1054,
     235,   233,   227,   235,  1307,  1308,   233,   229,   235,  1312,
    1313,     6,   236,   233,  1034,   235,   233,     6,   235,  1322,
    1040,  1041,  1042,   213,   214,   215,   216,   217,   218,   219,
     220,   221,  1052,     6,  1054,  1338,   226,   233,   233,   235,
     235,    60,    61,   234,    63,   233,   233,   235,   235,   233,
     233,   235,   235,  1108,   187,   188,   189,   234,  1078,  1362,
     234,   233,  1352,   235,   233,  1368,   235,   200,   229,   202,
     203,   229,   229,     6,     6,   234,   171,  1380,     4,     5,
     236,     6,     6,   234,     6,     6,   234,   234,  1108,     6,
     229,     4,   226,   231,   234,   228,  1501,   230,     7,   235,
    1403,  1404,  1405,   233,   233,  1833,  1409,  1410,   228,  1412,
       7,  1414,     6,  1416,     6,  1418,  1419,  1420,    44,    45,
      46,    47,    48,    49,    50,    51,    52,     6,   228,     4,
       7,    57,    58,    59,    60,  1438,     7,     6,     6,    65,
      66,    67,    62,    62,    70,     6,    62,    62,   228,     6,
    1453,   234,     7,     6,     6,    81,     7,     6,  1461,     6,
     168,  1464,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   234,   230,   228,     6,
     226,     6,   233,   228,   228,   233,  1489,  1490,  1593,   228,
     233,  1494,  1495,  1483,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,  1508,   233,   233,   233,   226,
     233,  1514,   228,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   228,   230,     4,
      44,   226,    44,    44,  1843,    44,     6,  1540,     4,   227,
       7,     6,  1532,     6,     6,  1548,     6,   234,   171,     7,
       7,     7,     7,   171,     7,  1558,     7,   171,  1561,     7,
       7,   187,   188,   189,     7,     7,     7,     7,     7,     6,
     228,  1561,   234,   230,   200,   234,   202,   203,   234,   234,
       7,     7,   234,     4,     6,   228,   233,  1307,  1308,   228,
     228,   233,  1312,  1313,   228,   314,   315,   233,   224,   225,
     231,   121,  1322,   322,   233,   231,   121,   326,   234,  1899,
       7,     6,    44,     7,     7,     7,     7,     6,  1621,  1622,
      44,    44,   234,   138,   235,   235,   121,  1629,  1630,   231,
     235,   146,   147,   148,  1637,  1625,    44,   152,   153,   154,
     155,     6,     6,   138,   121,     6,     6,     6,   229,  1652,
       7,   146,   147,   148,     6,  1658,     6,   152,   153,   154,
     155,   138,   227,   227,  1667,   227,     6,   234,   214,   146,
     147,   148,     7,     7,  1677,   152,   153,   154,   155,    92,
       7,     7,     7,  1673,  1687,     7,     7,     6,    87,  1692,
       7,     7,   121,     7,     7,     7,     7,     4,     4,   234,
     234,     6,  1692,  1693,  1694,   227,  1996,     7,     6,   138,
       7,     7,     7,     7,     7,     7,  1719,   146,   147,   148,
     235,     7,     6,   152,   153,   154,   155,     6,     6,   233,
       7,     6,    90,     6,   234,     4,     6,     4,     4,  1742,
     235,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,  1508,   234,  2045,   235,   226,   235,  1514,
       6,     6,     6,     6,     6,     4,     6,   231,   227,  1489,
    1490,     7,   233,     6,  1494,  1495,   228,     6,     6,     6,
     234,   230,   121,   233,   228,  1788,   231,     6,  1508,     6,
     228,   114,     6,     6,  1514,     6,     6,  1800,   234,   138,
     234,   234,     6,  1558,   234,     6,   235,   146,   147,   148,
    1813,     6,     6,   152,   153,   154,   155,   234,     6,     6,
    1540,     5,     4,   228,   230,     6,  1816,  1830,     6,     4,
    1833,   234,     6,   234,     7,     6,   234,     6,  1558,     6,
    1843,     6,   229,     6,   234,     6,   234,     6,   234,  1852,
     234,   234,   234,   234,   234,   234,  1859,  1860,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,     6,     6,     4,  1878,   226,   167,  1881,   233,
       6,     6,  1884,     6,     4,     6,   234,     6,     6,     6,
       6,     4,     7,     7,     6,  1898,   235,   616,   617,  1902,
       6,     6,     3,     4,     6,   624,     5,   171,     9,    10,
      11,     6,     6,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,     6,     6,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,    53,    54,    55,    56,   226,  1960,   234,     6,
      61,     6,     6,     6,     6,     6,     6,     6,     6,     6,
     233,    72,    73,    74,     6,     6,  1979,     6,   233,    80,
       6,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,     6,   228,     6,  2001,   226,
       6,     3,     4,     6,   234,     6,     6,     9,    10,    11,
    2000,     7,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,     6,     6,     6,   231,     5,
      88,     6,     6,   234,  2047,  2048,  2049,  2050,  2051,   234,
       6,    53,    54,    55,    56,   234,   121,   234,   234,    61,
    2063,     6,     6,   235,     7,   235,   234,     6,   234,   166,
      72,    73,    74,   235,   234,     6,     6,   235,    80,   235,
     235,     6,     6,     6,   169,   186,     6,     6,     6,   190,
       6,     6,     6,     6,   195,   196,   197,   198,   199,     6,
       6,     6,   203,   234,   228,   234,     6,   234,     7,     6,
       6,     6,   234,  1833,     6,  2105,   217,   218,     6,     6,
       6,   222,   121,  1843,   234,   234,   227,     6,   235,     6,
     234,   232,     6,   234,  2137,     6,     6,     6,     6,     6,
    2143,     6,   106,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   235,   234,   227,
     234,   226,   234,     6,   235,   228,     6,   234,     6,     6,
       6,     6,  2175,     6,     6,     6,     6,     6,     6,   234,
       6,   234,   234,   234,   186,   234,     6,     6,   190,     6,
    2193,     6,  2195,   195,   196,   197,   198,   199,     6,     6,
       6,   203,     6,     6,     6,   924,     6,     6,     6,   513,
    1347,  2004,   931,  1858,  1361,   217,   218,     3,     3,   938,
     222,     3,  2225,     3,   591,   227,  1880,  1536,    -1,    -1,
     232,    -1,   234,    -1,    -1,    -1,    -1,   201,   202,   203,
     204,   205,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   218,    -1,    -1,    -1,   222,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   236,   237,   238,   239,    -1,   241,   242,   243,
     244,  2001,   246,   247,   248,   249,   250,   251,   252,    -1,
     254,   255,    -1,    -1,    -1,    -1,   260,    -1,    -1,    -1,
      -1,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   279,   280,   281,    -1,   226,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   291,   292,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,    -1,   308,    -1,    -1,   226,    -1,    -1,
      -1,    -1,    -1,   317,   318,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   326,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   336,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,    -1,  2143,    -1,
      -1,   226,    -1,   357,    -1,    -1,    -1,   361,   362,   363,
      -1,   365,    -1,    -1,  1123,   369,   370,   371,    -1,    -1,
     374,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2143,    -1,   389,    -1,    -1,    -1,    -1,
     394,   395,    -1,    -1,    -1,    -1,    -1,    -1,  2193,    -1,
    2195,    -1,    -1,    -1,   408,   409,    -1,   411,   412,   413,
     414,   415,   416,   417,   418,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,    -1,
    2225,    -1,    -1,  2193,    -1,  2195,    -1,    -1,    -1,    -1,
      -1,    -1,   446,    -1,    -1,    -1,    -1,    -1,   452,    -1,
     454,    -1,     6,    -1,    -1,  1214,  1215,  1216,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2225,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   478,   479,    -1,   481,   482,   483,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
     494,   495,    -1,    -1,   498,   499,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
      -1,    -1,    -1,   517,   226,    -1,    -1,    -1,    -1,   523,
      -1,   233,    -1,   235,   528,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   540,   541,    -1,    -1,
      -1,    -1,    -1,   547,   548,    -1,    -1,   551,   552,   553,
     554,    -1,   556,    -1,    -1,   559,    -1,    -1,     6,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   571,   572,    -1,
      -1,    -1,    -1,    -1,   578,   579,   580,   581,    -1,    -1,
      -1,   585,   586,   587,    -1,    -1,    -1,    -1,   592,   593,
     594,   595,   596,   597,    -1,   599,    -1,   601,    -1,   603,
     604,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     6,    -1,    -1,    -1,   621,   622,   623,
     624,   625,   626,    12,    13,    -1,   630,   631,   632,   633,
     634,   635,   636,   637,   638,    -1,    -1,    -1,    -1,   643,
      -1,   645,   646,    -1,    -1,    -1,   650,   651,   652,    -1,
      -1,   655,   656,   657,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,    -1,    -1,
     674,    -1,   226,    -1,    -1,   679,   680,    -1,   682,   683,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   693,
     694,    -1,  1451,    -1,   698,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    -1,    -1,
      -1,   100,   101,   102,    -1,   104,    -1,    -1,    -1,    -1,
     109,   110,   111,    -1,    -1,   114,   115,     6,   117,   118,
     119,    -1,    -1,    -1,   123,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   137,     6,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   763,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   163,   164,   165,    -1,   226,    -1,
       6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   797,   798,    -1,    -1,   801,   802,   803,
      -1,   805,   806,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     814,    -1,  1571,   817,   818,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,    -1,
      -1,    -1,    -1,   226,   838,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   235,   851,    -1,   853,
      -1,    -1,   856,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   869,    -1,   871,    -1,   873,
      -1,   875,  1631,    -1,  1633,    -1,  1635,   881,    -1,    -1,
      -1,    -1,   886,    -1,    -1,    -1,     6,    -1,    -1,   893,
      -1,    -1,    -1,    -1,  1653,  1654,  1655,  1656,  1657,  1658,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   918,    -1,    -1,    -1,   226,    -1,
      -1,   925,   926,    -1,    -1,    -1,   234,   931,    -1,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,    -1,    -1,    -1,   950,   226,    -1,   953,
      -1,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,    -1,    -1,    -1,   972,   226,
     974,   975,    -1,    -1,    -1,    -1,    -1,    46,    -1,    -1,
      -1,   985,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,    -1,    -1,    -1,    -1,
     226,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1017,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1025,  1026,  1027,    -1,  1029,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1037,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1051,    -1,    -1,
      -1,    -1,  1056,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1065,    -1,   237,    -1,    -1,    -1,  1071,   242,    -1,
      -1,    -1,   246,    -1,    -1,    -1,     6,  1081,  1082,  1083,
    1084,  1085,    -1,    -1,    -1,  1089,   260,    -1,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,    -1,    -1,    -1,   279,   226,   281,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   292,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1888,
      -1,  1890,    -1,  1892,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1147,  1903,  1904,  1905,  1906,  1907,    -1,
      -1,    -1,    -1,  1157,  1158,    -1,  1160,  1161,    -1,  1163,
    1164,  1165,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1173,
      -1,    -1,    -1,    -1,    -1,  1179,    -1,    -1,    -1,     6,
      -1,    -1,    -1,    -1,    -1,    -1,  1190,   256,  1192,    -1,
    1194,    -1,  1196,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1959,    -1,    -1,    -1,  1963,    -1,   275,     7,     8,    -1,
      -1,    -1,    -1,    -1,    -1,  1219,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   295,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   304,   305,   306,    -1,    -1,
      -1,   310,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1253,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2021,    -1,    -1,    -1,  2025,    -1,    -1,    -1,
     339,    -1,  1276,    -1,    -1,    -1,    -1,  1281,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,  2051,    -1,    -1,    -1,   226,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   479,     8,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1323,
      -1,    -1,    -1,   392,   393,    -1,    -1,    -1,  1332,    -1,
       8,    -1,  1336,  1337,    -1,    -1,   405,    -1,    -1,    -1,
      -1,    -1,    -1,   517,    -1,    -1,    -1,  1351,  1352,    -1,
      -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2120,  2121,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   443,    -1,    -1,   551,   552,    -1,
      -1,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,    -1,    -1,   571,   572,   226,
      -1,    -1,    -1,    -1,    -1,   579,    -1,    -1,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,  1426,  1427,  1428,    -1,   226,    -1,    -1,   603,
     604,    -1,    -1,    -1,  1438,    -1,  1440,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1451,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1464,    -1,    -1,    -1,    -1,  1469,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1477,  1478,  1479,   650,   651,   652,    -1,
      -1,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,    -1,    -1,   566,    -1,   226,
     674,   228,    -1,   230,    -1,  1509,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     694,    -1,    -1,    -1,   226,    -1,    -1,    -1,    -1,  1533,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,    -1,  1549,    -1,    -1,   226,    -1,
    1554,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,  1569,  1570,    -1,    -1,   226,
      -1,    -1,  1576,  1577,    -1,    -1,    -1,  1581,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1597,  1598,  1599,  1600,  1601,  1602,  1603,
      -1,    -1,    -1,    -1,    -1,   237,    -1,  1611,    -1,    -1,
     242,     8,    -1,    -1,   246,    -1,    -1,  1621,  1622,  1623,
      -1,  1625,    -1,    -1,    -1,    -1,    -1,   801,   260,    -1,
       8,   805,    -1,    -1,  1638,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   817,   818,    -1,    -1,    -1,    -1,    -1,
      12,    13,    -1,    -1,  1658,    -1,    -1,    -1,  1662,    -1,
     292,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1673,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   851,    -1,   853,
      -1,    -1,   856,    -1,    -1,    -1,    -1,   756,    -1,  1693,
      -1,   760,    -1,    -1,    -1,   869,    -1,   871,    -1,   873,
      -1,   875,    -1,    -1,    -1,    -1,    -1,   881,    -1,    -1,
      -1,    -1,   886,  1717,  1718,    -1,    -1,    -1,    -1,    -1,
      -1,  1725,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    -1,    -1,    -1,   100,   101,
     102,    -1,   104,    -1,   918,    -1,  1750,   109,   110,   111,
      -1,    -1,   114,   115,    -1,   117,   118,   119,    -1,    -1,
      -1,   123,    -1,    -1,    -1,    -1,    -1,    -1,  1772,    -1,
      -1,    -1,    -1,    -1,     8,   137,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1791,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1800,    -1,    -1,    -1,
      -1,   163,   164,   165,  1808,    -1,  1810,    -1,    -1,  1813,
      -1,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   894,  1830,    -1,    -1,   226,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,  1848,    -1,    -1,   479,   226,  1853,
      -1,    -1,    -1,    -1,    -1,  1029,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1870,  1871,  1872,  1873,
    1874,    -1,    -1,   235,    -1,    -1,    -1,  1881,    -1,    -1,
      -1,    -1,    -1,    -1,  1888,    -1,  1890,    -1,  1892,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1902,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1910,  1081,  1082,  1083,
    1084,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   988,
      -1,    -1,    -1,   992,    -1,    -1,    -1,   996,    -1,  1933,
    1934,    -1,    -1,    -1,  1938,    -1,    -1,    -1,    -1,    -1,
     572,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1956,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1967,    -1,    -1,    -1,    -1,    -1,    -1,
    1039,   603,   604,  1147,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,    -1,    -1,
      -1,    -1,   226,    -1,  1998,    -1,    -1,    -1,    -1,    -1,
    2004,    -1,    -1,    -1,    -1,  1179,    -1,    -1,    -1,  2013,
    2014,  2015,  2016,  2017,  2018,    -1,    -1,    -1,   650,   651,
     652,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2032,    -1,
      -1,  2035,    -1,    -1,  2038,    -1,    -1,    -1,  2042,    -1,
      -1,    -1,   674,  2047,  2048,  2049,  2050,  2051,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2061,  1127,  1128,
    2064,  1130,   694,  1132,  1133,    -1,    -1,  1136,  1137,  1138,
    1139,  1140,  1141,  1142,  1143,    -1,     4,     5,    -1,    -1,
      -1,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,    -1,    -1,    -1,    -1,   226,
      -1,    -1,    -1,  1172,     4,     5,   233,    -1,   235,  1178,
    2114,  2115,  2116,  2117,  2118,  2119,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    -1,    -1,    -1,    -1,    57,
      58,    59,    60,  2137,    -1,    -1,    -1,    65,    66,    67,
      -1,    -1,    70,    -1,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    81,    -1,    -1,    -1,    57,    58,    59,
      60,    -1,    -1,    -1,    -1,    65,    66,    67,    -1,   801,
      70,    -1,  1241,   805,    -1,  2179,  2180,  2181,  2182,  2183,
    2184,    81,    -1,    -1,    -1,  1254,  1255,  1256,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1270,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,    -1,    -1,    -1,   851,
     226,   853,    -1,    -1,   856,    -1,    -1,   233,    -1,   235,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   869,    -1,   871,
      -1,   873,    -1,   875,    -1,    -1,    -1,    -1,    -1,   881,
      -1,    -1,    -1,    -1,   886,    -1,    -1,    -1,    -1,   187,
     188,   189,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1338,
      -1,    -1,   200,    -1,   202,   203,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   918,   187,   188,   189,
    1464,    -1,    -1,  1362,    -1,    -1,    -1,    -1,    -1,  1368,
     200,    -1,   202,   203,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1380,    -1,    -1,    -1,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,    12,
      13,    -1,    -1,   226,  1403,  1404,  1405,    -1,    -1,    -1,
    1409,  1410,   235,  1412,    -1,  1414,    -1,  1416,    -1,  1418,
    1419,  1420,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,    -1,    -1,    -1,  1438,
     226,    -1,    -1,    -1,   582,    -1,    -1,    -1,    -1,   235,
      -1,    -1,    -1,    -1,  1453,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1461,    -1,    -1,    -1,    -1,  1029,    -1,    -1,
      -1,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    -1,    -1,    -1,   100,   101,   102,
      -1,   104,    -1,    -1,    -1,    -1,   109,   110,   111,    -1,
      -1,   114,   115,    -1,   117,   118,   119,    -1,    -1,    -1,
     123,    -1,    -1,    -1,    -1,    -1,    -1,  1621,  1622,  1081,
    1082,  1083,  1084,    -1,   137,    -1,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
      -1,    -1,    -1,    -1,   226,    -1,    -1,    -1,    -1,  1548,
     163,   164,   165,   235,  1658,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1561,    -1,   702,   703,   704,   705,   706,   707,
     708,   709,   710,   711,   712,    -1,   714,   715,   716,   717,
     718,   719,   720,    -1,    -1,  1147,   724,   725,   726,    -1,
      -1,    -1,   730,   731,    -1,   733,    -1,    -1,    -1,    -1,
     738,   739,   740,    -1,   742,    -1,    -1,    -1,    -1,    -1,
      -1,   749,   750,    -1,    -1,    -1,    -1,  1179,    -1,    -1,
      -1,    -1,   235,    -1,    -1,    -1,    -1,    -1,    -1,   767,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1637,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,  1652,    -1,    -1,    -1,   226,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   235,    -1,  1667,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1677,    -1,
      -1,    -1,    -1,    21,    22,    -1,    -1,    -1,  1687,    -1,
      -1,    -1,    -1,  1692,    -1,    -1,  1800,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     4,     5,    -1,    -1,  1813,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1719,    -1,    -1,   861,    -1,    -1,  1830,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   876,    -1,
      -1,    -1,    -1,  1742,    -1,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    -1,    -1,    -1,    -1,    57,    58,
      59,    60,    -1,    -1,    -1,    -1,    65,    66,    67,    -1,
      -1,    70,    -1,    -1,    -1,    -1,    -1,  1881,    -1,    -1,
      -1,    -1,    81,    -1,    -1,    -1,    -1,    -1,    -1,  1788,
      -1,    -1,   130,    -1,    -1,    -1,    -1,    -1,  1902,    -1,
      -1,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,    -1,    -1,    -1,   167,
     168,   169,   170,    -1,   172,   173,   174,   175,   176,   177,
      -1,    -1,   180,    -1,    -1,    -1,    -1,    -1,   186,   187,
      -1,    -1,    -1,  1852,   192,   193,    -1,    -1,    -1,    -1,
    1859,  1860,    -1,    -1,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,    -1,  1878,
      -1,    -1,   226,    -1,    -1,    -1,    -1,    -1,   187,   188,
     189,   235,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1898,
      -1,   200,  1464,   202,    -1,    -1,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
      -1,    -1,    -1,    -1,   226,    -1,    -1,   265,    -1,   267,
     268,   269,   270,   235,    -1,    -1,    -1,    -1,    -1,    -1,
     278,    -1,    -1,  2047,  2048,  2049,  2050,  2051,    -1,    -1,
    1088,   289,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1960,    -1,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,    -1,    -1,    -1,
    1979,   226,    -1,  1121,  1122,    -1,    -1,    -1,    -1,    -1,
     235,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,    -1,    -1,    -1,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,  2137,    -1,    -1,    -1,    -1,    -1,    -1,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    -1,  1621,
    1622,    65,    66,    67,  2063,    -1,    70,    -1,    72,    73,
      74,    -1,     3,     4,    -1,    -1,    80,    81,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    -1,    -1,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,    53,    54,    55,    56,   226,    -1,    -1,    -1,
      61,    -1,    -1,    -1,   234,   473,    -1,    -1,    -1,    -1,
      -1,    72,    73,    74,    -1,    -1,  1284,    -1,    -1,    80,
      -1,    -1,  1290,  1291,  1292,  1293,  1294,    -1,  1296,    -1,
    1298,  1299,    -1,  1301,  1302,    -1,    -1,  1305,  1306,  1307,
      -1,    -1,    -1,    -1,  1312,   179,  2175,    -1,    -1,    -1,
      -1,    -1,   186,   187,   188,   189,   190,    -1,    -1,    -1,
      -1,   195,   196,   197,   198,   199,   200,    -1,   202,   203,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   217,   218,    -1,    -1,    -1,   222,    -1,
      -1,    -1,    -1,   227,    -1,   229,    -1,   231,   232,    -1,
     234,    -1,   236,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1383,    -1,    -1,    -1,    -1,
      -1,  1813,    -1,    -1,    -1,   186,    -1,    -1,    -1,   190,
      -1,    -1,  1400,    -1,   195,   196,   197,   198,   199,    -1,
      -1,     5,   203,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   217,   218,    -1,    -1,
      -1,   222,    -1,    -1,    -1,    -1,   227,   228,    -1,    -1,
      -1,   232,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      44,    45,    46,    47,    48,    49,    50,    51,    52,  1881,
      -1,    -1,    -1,    57,    58,    59,    60,    -1,    -1,    -1,
      -1,    65,    66,    67,    -1,    -1,    70,    -1,    -1,    -1,
    1902,    -1,    -1,    -1,    -1,    -1,    -1,    81,    -1,    -1,
      -1,  1489,    -1,    -1,    -1,    -1,  1494,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,    -1,    -1,    -1,    -1,   226,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   235,    -1,    -1,    -1,  1526,  1527,
      -1,    -1,  1530,  1531,     3,     4,    -1,    -1,    -1,    -1,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    53,    54,    55,    56,    -1,    -1,
      -1,    -1,    61,   187,   188,   189,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    72,    73,    74,   200,    -1,   202,    -1,
      -1,    80,    -1,    -1,    -1,    84,    -1,    -1,    87,    -1,
      -1,    90,    -1,    92,    -1,  2047,  2048,  2049,  2050,  2051,
      99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   110,    -1,   112,    -1,    -1,   115,    -1,    -1,   118,
      -1,    -1,    -1,    -1,    -1,    -1,   125,   126,   127,   128,
     129,    -1,    -1,   132,   133,   134,   135,   136,    -1,    -1,
      -1,   140,    -1,    -1,   143,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1680,  1681,    -1,    -1,  1684,  1685,    -1,    -1,
      -1,    -1,  1690,  1691,    -1,    -1,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
      -1,    -1,    -1,    -1,   226,  2137,    -1,   186,    -1,    -1,
      -1,   190,   191,   235,    -1,    -1,   195,   196,   197,   198,
     199,    -1,    -1,    -1,   203,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1743,  1744,    -1,   217,   218,
      -1,    -1,    -1,   222,    -1,    -1,    -1,    -1,   227,    -1,
      -1,    -1,    -1,   232,    -1,   234,   235,    -1,    -1,     3,
       4,    -1,    -1,    -1,    -1,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,
      54,    55,    56,    -1,    -1,    -1,    -1,    61,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,    73,
      74,    -1,    -1,    12,    13,    -1,    80,    -1,    -1,    -1,
      84,    -1,    -1,    87,    -1,    -1,    90,    -1,    92,    -1,
      -1,    -1,    -1,  1061,  1062,    99,    -1,    -1,    -1,  1067,
    1068,    -1,    -1,    -1,    -1,    -1,   110,    -1,   112,    -1,
      -1,   115,    -1,    -1,   118,    -1,    -1,    -1,    -1,    -1,
      -1,   125,   126,   127,   128,   129,    -1,    -1,   132,   133,
     134,   135,   136,    -1,    -1,    -1,   140,    -1,    -1,   143,
      -1,    -1,    -1,    -1,    -1,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    -1,    -1,
      -1,   100,   101,   102,    -1,   104,    -1,    -1,    -1,    -1,
     109,   110,   111,    -1,    -1,   114,   115,    -1,   117,   118,
     119,    -1,   186,    -1,   123,    -1,   190,   191,    -1,    -1,
      -1,   195,   196,   197,   198,   199,    -1,    -1,   137,   203,
      -1,    -1,   141,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   217,   218,    -1,    -1,    -1,   222,    -1,
      -1,    -1,    -1,   227,   163,   164,   165,    -1,   232,    -1,
      -1,   235,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,    -1,    -1,
      -1,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    -1,    -1,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    -1,  1273,  1274,    65,    66,    67,
    1278,  1279,    70,    -1,    72,    73,    74,    -1,    -1,    -1,
      -1,    -1,    80,    81,    -1,    -1,    84,    -1,    -1,    87,
      -1,    -1,    90,    -1,    92,    -1,    -1,    -1,    -1,    -1,
      -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   110,    -1,   112,    -1,    -1,   115,    -1,    -1,
     118,    -1,    -1,    -1,    -1,    -1,    -1,   125,   126,   127,
     128,   129,    -1,    -1,   132,   133,   134,   135,   136,    -1,
    2148,    -1,   140,    -1,    -1,   143,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
      -1,    -1,    -1,    -1,   226,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   235,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   186,   187,
     188,   189,   190,   191,    -1,    -1,    -1,   195,   196,   197,
     198,   199,   200,    -1,   202,   203,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   217,
     218,    -1,    -1,    -1,   222,    -1,    -1,    -1,    -1,   227,
      -1,     3,     4,     5,   232,    -1,   234,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      -1,    -1,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      -1,    -1,    -1,    65,    66,    67,    -1,    -1,    70,    -1,
      72,    73,    74,    -1,    -1,    -1,    -1,    -1,    80,    81,
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
      -1,    -1,    -1,    -1,   186,   187,   188,   189,   190,   191,
      -1,    -1,    -1,   195,   196,   197,   198,   199,   200,    -1,
     202,   203,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   217,   218,    -1,    -1,    -1,
     222,    -1,    -1,    -1,    -1,   227,    -1,     3,     4,     5,
     232,    -1,   234,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,    54,    55,
      56,    -1,    -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    72,    73,    74,    -1,
      -1,    -1,    -1,    -1,    80,    -1,    -1,    -1,    84,    -1,
      -1,    87,    -1,    -1,    90,    -1,    92,    -1,    -1,    -1,
      -1,    -1,    -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   110,    -1,   112,    -1,    -1,   115,
      -1,    -1,   118,    -1,    -1,    -1,    -1,    -1,    -1,   125,
     126,   127,   128,   129,    -1,    -1,   132,   133,   134,   135,
     136,    -1,    -1,    -1,   140,    -1,    -1,   143,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,    -1,    -1,    -1,    -1,   226,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   235,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     186,    -1,    -1,    -1,   190,   191,    -1,    -1,    -1,   195,
     196,   197,   198,   199,    -1,    -1,    -1,   203,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   217,   218,    -1,    -1,    -1,   222,    -1,    -1,    -1,
      -1,   227,    -1,     3,     4,     5,   232,    -1,   234,     9,
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
     110,    -1,   112,    -1,    -1,   115,    -1,    -1,   118,    -1,
      -1,    -1,    -1,    -1,    -1,   125,   126,   127,   128,   129,
      -1,    -1,   132,   133,   134,   135,   136,    -1,    -1,    -1,
     140,    -1,    -1,   143,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,    -1,    -1,
      -1,    -1,   226,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   235,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   186,    -1,    -1,    -1,
     190,   191,    -1,    -1,    -1,   195,   196,   197,   198,   199,
      -1,    -1,    -1,   203,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   217,   218,    -1,
      -1,    -1,   222,    -1,    -1,    -1,    -1,   227,    -1,     3,
       4,    -1,   232,    -1,   234,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,
      54,    55,    56,    -1,    -1,    -1,    -1,    61,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,    73,
      74,    -1,    -1,    -1,    -1,    -1,    80,    -1,    -1,    -1,
      84,    -1,    -1,    87,    -1,    -1,    90,    -1,    92,    -1,
      -1,    -1,    -1,    -1,    -1,    99,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   110,    -1,   112,    -1,
      -1,   115,    -1,    -1,   118,    -1,    -1,    -1,    -1,    -1,
      -1,   125,   126,   127,   128,   129,    -1,    -1,   132,   133,
     134,   135,   136,    -1,    -1,    -1,   140,    -1,    -1,   143,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,    -1,    -1,    -1,    -1,   226,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   235,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   186,    -1,    -1,    -1,   190,   191,    -1,    -1,
      -1,   195,   196,   197,   198,   199,    -1,    -1,    -1,   203,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   217,   218,    -1,    -1,    -1,   222,    -1,
      -1,    -1,    -1,   227,    -1,     3,     4,    -1,   232,    -1,
     234,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    53,    54,    55,    56,    -1,
      -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    72,    73,    74,    -1,    -1,    -1,
      -1,    -1,    80,    -1,    -1,    -1,    84,    -1,    -1,    87,
      -1,    -1,    90,    -1,    92,    -1,    -1,    -1,    -1,    -1,
      -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   110,    -1,   112,    -1,    -1,   115,    -1,    -1,
     118,    -1,    -1,    -1,    -1,    -1,    -1,   125,   126,   127,
     128,   129,    -1,    -1,   132,   133,   134,   135,   136,    -1,
      -1,    -1,   140,    -1,    -1,   143,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
      -1,    -1,    -1,    -1,   226,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   235,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   186,    -1,
      -1,    -1,   190,   191,    -1,    -1,    -1,   195,   196,   197,
     198,   199,    -1,    -1,    -1,   203,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   217,
     218,    -1,    -1,    -1,   222,    -1,    -1,    -1,    -1,   227,
      -1,     3,     4,    -1,   232,    -1,   234,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    53,    54,    55,    56,    -1,    -1,    -1,    -1,    61,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
     222,    -1,    -1,    -1,    -1,   227,    -1,     3,     4,    -1,
     232,    -1,   234,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,    54,    55,
      56,    -1,    -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    72,    73,    74,    -1,
      -1,    -1,    -1,    -1,    80,    -1,    -1,    -1,    84,    -1,
      -1,    87,    -1,    -1,    90,    -1,    92,    -1,    -1,    -1,
      -1,    -1,    -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   110,    -1,   112,    -1,    -1,   115,
      -1,    -1,   118,    -1,    -1,    -1,    -1,    -1,    -1,   125,
     126,   127,   128,   129,    -1,    -1,   132,   133,   134,   135,
     136,    -1,    -1,    -1,   140,    -1,    -1,   143,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,    -1,    -1,    -1,    -1,   226,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   235,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     186,    -1,    -1,    -1,   190,   191,    -1,    -1,    -1,   195,
     196,   197,   198,   199,    -1,    -1,    -1,   203,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   217,   218,    -1,    -1,    -1,   222,    -1,    -1,    -1,
      -1,   227,    -1,     3,     4,    -1,   232,    -1,   234,     9,
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
     110,    -1,   112,    -1,    -1,   115,    -1,    -1,   118,    -1,
      -1,    -1,    -1,    -1,    -1,   125,   126,   127,   128,   129,
      -1,    -1,   132,   133,   134,   135,   136,    -1,    -1,    -1,
     140,    -1,    -1,   143,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,    -1,    -1,
      -1,    -1,   226,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   235,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   186,    -1,    -1,    -1,
     190,   191,    -1,    -1,    -1,   195,   196,   197,   198,   199,
      -1,    -1,    -1,   203,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   217,   218,    -1,
      -1,    -1,   222,    -1,    -1,    -1,    -1,   227,    -1,     3,
       4,    -1,   232,    -1,   234,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,
      54,    55,    56,    -1,    -1,    -1,    -1,    61,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,    73,
      74,    -1,    -1,    -1,    -1,    -1,    80,    -1,    -1,    -1,
      84,    -1,    -1,    87,    -1,    -1,    90,    -1,    92,    -1,
      -1,    -1,    -1,    -1,    -1,    99,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   110,    -1,   112,    -1,
      -1,   115,    -1,    -1,   118,    -1,    -1,    -1,    -1,    -1,
      -1,   125,   126,   127,   128,   129,    -1,    -1,   132,   133,
     134,   135,   136,    -1,    -1,    -1,   140,    -1,    -1,   143,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,    -1,    -1,    -1,    -1,   226,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   235,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   186,    -1,    -1,    -1,   190,   191,    -1,    -1,
      -1,   195,   196,   197,   198,   199,    -1,    -1,    -1,   203,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   217,   218,    -1,    -1,    -1,   222,    -1,
      -1,    -1,    -1,   227,    -1,     3,     4,    -1,   232,    -1,
     234,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    53,    54,    55,    56,    -1,
      -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    72,    73,    74,    -1,    -1,    -1,
      -1,    -1,    80,    -1,    -1,    -1,    84,    -1,    -1,    87,
      -1,    -1,    90,    -1,    92,    -1,    -1,    -1,    -1,    -1,
      -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   110,    -1,   112,    -1,    -1,   115,    -1,    -1,
     118,    -1,    -1,    -1,    -1,    -1,    -1,   125,   126,   127,
     128,   129,    -1,    -1,   132,   133,   134,   135,   136,    -1,
      -1,    -1,   140,    -1,    -1,   143,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
      -1,    -1,    -1,    -1,   226,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   235,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   186,    -1,
      -1,    -1,   190,   191,    -1,    -1,    -1,   195,   196,   197,
     198,   199,    -1,    -1,    -1,   203,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   217,
     218,    -1,    -1,    -1,   222,    -1,    -1,    -1,    -1,   227,
      -1,     3,     4,    -1,   232,    -1,   234,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    53,    54,    55,    56,    -1,    -1,    -1,    -1,    61,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
     222,    -1,    -1,    -1,    -1,   227,    -1,     3,     4,    -1,
     232,    -1,   234,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,    54,    55,
      56,    -1,    -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    72,    73,    74,    -1,
      -1,    -1,    -1,    -1,    80,    -1,    -1,    -1,    84,    -1,
      -1,    87,    -1,    -1,    90,    -1,    92,    -1,    -1,    -1,
      -1,    -1,    -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   110,    -1,   112,    -1,    -1,   115,
      -1,    -1,   118,    -1,    -1,    -1,    -1,    -1,    -1,   125,
     126,   127,   128,   129,    -1,    -1,   132,   133,   134,   135,
     136,    -1,    -1,    -1,   140,    -1,    -1,   143,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,    -1,    -1,    -1,    -1,   226,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   235,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     186,    -1,    -1,    -1,   190,   191,    -1,    -1,    -1,   195,
     196,   197,   198,   199,    -1,    -1,    -1,   203,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   217,   218,    -1,    -1,    -1,   222,    -1,    -1,    -1,
      -1,   227,    -1,     3,     4,    -1,   232,    -1,   234,     9,
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
     110,    -1,   112,    -1,    -1,   115,    -1,    -1,   118,    -1,
      -1,    -1,    -1,    -1,    -1,   125,   126,   127,   128,   129,
      -1,    -1,   132,   133,   134,   135,   136,    -1,    -1,    -1,
     140,    -1,    -1,   143,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,    -1,    -1,
      -1,    -1,   226,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   235,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   186,    -1,    -1,    -1,
     190,   191,    -1,    -1,    -1,   195,   196,   197,   198,   199,
      -1,    -1,    -1,   203,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   217,   218,    -1,
      -1,    -1,   222,    -1,    -1,    -1,    -1,   227,    -1,     3,
       4,    -1,   232,    -1,   234,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,
      54,    55,    56,    -1,    -1,    -1,    -1,    61,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,    73,
      74,    -1,    -1,    -1,    -1,    -1,    80,    -1,    -1,    -1,
      84,    -1,    -1,    87,    -1,    -1,    90,    -1,    92,    -1,
      -1,    -1,    -1,    -1,    -1,    99,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   110,    -1,   112,    -1,
      -1,   115,    -1,    -1,   118,    -1,    -1,    -1,    -1,    -1,
      -1,   125,   126,   127,   128,   129,    -1,    -1,   132,   133,
     134,   135,   136,    -1,    -1,    -1,   140,    -1,    -1,   143,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,    -1,    -1,    -1,    -1,   226,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   235,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   186,    -1,    -1,    -1,   190,   191,    -1,    -1,
      -1,   195,   196,   197,   198,   199,    -1,    -1,    -1,   203,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   217,   218,    -1,    -1,    -1,   222,    -1,
      -1,    -1,    -1,   227,    -1,     3,     4,    -1,   232,    -1,
     234,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    53,    54,    55,    56,    -1,
      -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    72,    73,    74,    -1,    -1,    -1,
      -1,    -1,    80,    -1,    -1,    -1,    84,    -1,    -1,    87,
      -1,    -1,    90,    -1,    92,    -1,    -1,    -1,    -1,    -1,
      -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   110,    -1,   112,    -1,    -1,   115,    -1,    -1,
     118,    -1,    -1,    -1,    -1,    -1,    -1,   125,   126,   127,
     128,   129,    -1,    -1,   132,   133,   134,   135,   136,    -1,
      -1,    -1,   140,    -1,    -1,   143,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
      -1,    -1,    -1,    -1,   226,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   235,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   186,    -1,
      -1,    -1,   190,   191,    -1,    -1,    -1,   195,   196,   197,
     198,   199,    -1,    -1,    -1,   203,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   217,
     218,    -1,    -1,    -1,   222,    -1,    -1,    -1,    -1,   227,
      -1,     3,     4,     5,   232,    -1,   234,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      -1,    -1,    -1,    65,    66,    67,    -1,    -1,    70,    -1,
      72,    73,    74,    -1,     3,     4,     5,    -1,    80,    81,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    -1,    -1,    -1,    65,    66,    67,    -1,
      -1,    70,    -1,    72,    73,    74,    -1,    -1,    -1,    -1,
      -1,    80,    81,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,    -1,    -1,    -1,
      -1,   226,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     235,    -1,    -1,    -1,   186,   187,   188,   189,   190,    -1,
      -1,    -1,    -1,   195,   196,   197,   198,   199,   200,    -1,
     202,   203,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   217,   218,    -1,    -1,    -1,
     222,    -1,    -1,    -1,    -1,   227,    -1,    -1,    -1,    -1,
     232,    -1,   234,    -1,    -1,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,    -1,
      -1,    -1,    -1,   226,    -1,    -1,    -1,   186,   187,   188,
     189,   190,   235,    -1,    -1,    -1,   195,   196,   197,   198,
     199,   200,    -1,   202,   203,    -1,    -1,    -1,    -1,    -1,
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
       3,     4,     5,    -1,   227,    -1,     9,    10,    11,   232,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    -1,
      -1,    -1,    65,    66,    67,    -1,    -1,    70,    -1,    72,
      73,    74,    -1,     3,     4,    -1,    -1,    80,    81,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    -1,    -1,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,    53,    54,    55,    56,   226,    -1,    -1,
      -1,    61,    -1,    -1,    -1,    -1,   235,    -1,    -1,    -1,
      -1,    -1,    72,    73,    74,    -1,    -1,    -1,    -1,    -1,
      80,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,    -1,    -1,    -1,    -1,   226,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   235,    -1,
      -1,    -1,    -1,   186,   187,   188,   189,   190,    -1,    -1,
      -1,    -1,   195,   196,   197,   198,   199,   200,    -1,   202,
     203,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   217,   218,    -1,    -1,    -1,   222,
      -1,    -1,    -1,    -1,   227,    -1,    -1,    -1,    -1,   232,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,    -1,    -1,    -1,    -1,   226,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   186,   235,    -1,    -1,
     190,    -1,    -1,    -1,    -1,   195,   196,   197,   198,   199,
      -1,    -1,    -1,   203,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   217,   218,    -1,
      -1,    -1,   222,    -1,    -1,    -1,    -1,   227,     3,     4,
     230,    -1,   232,    -1,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    -1,    -1,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,    53,    54,
      55,    56,   226,    -1,    -1,    -1,    61,    -1,    -1,    -1,
      -1,   235,    -1,    -1,    -1,     3,     4,    72,    73,    74,
      -1,     9,    10,    11,    -1,    80,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    -1,
      -1,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,    53,    54,    55,    56,   226,
      -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,   235,    -1,
      -1,    -1,    -1,    -1,    72,    73,    74,    -1,    -1,    -1,
      -1,    -1,    80,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,    -1,    -1,    -1,
      -1,   226,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     235,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   186,    -1,    -1,    -1,   190,    -1,    -1,    -1,    -1,
     195,   196,   197,   198,   199,    -1,    -1,    -1,   203,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   217,   218,    -1,    -1,    -1,   222,    -1,    -1,
      -1,    -1,   227,   228,    -1,    -1,    -1,   232,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,    -1,    -1,    -1,    -1,   226,    -1,   186,    -1,
      -1,    -1,   190,    -1,   234,    -1,    -1,   195,   196,   197,
     198,   199,    -1,    -1,    -1,   203,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   217,
     218,    -1,    -1,    -1,   222,    -1,    -1,    -1,    -1,   227,
       3,     4,   230,     6,   232,    -1,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
      53,    54,    55,    56,   226,    -1,   228,    -1,    61,    -1,
      -1,   233,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,
      73,    74,     3,     4,    -1,     6,    -1,    80,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    -1,    -1,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,    53,    54,    55,    56,   226,    -1,    -1,    -1,
      61,    -1,    -1,   233,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    72,    73,    74,    -1,    -1,    -1,    -1,    -1,    80,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,    -1,    -1,    -1,    -1,   226,    -1,
     228,    -1,   230,    -1,    -1,   233,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   186,    -1,    -1,    -1,   190,    -1,    -1,
      -1,    -1,   195,   196,   197,   198,   199,    -1,    -1,    -1,
     203,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   217,   218,    -1,    -1,    -1,   222,
      -1,    -1,    -1,    -1,   227,    -1,    -1,    -1,    -1,   232,
      -1,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,    -1,    -1,    -1,    -1,   226,
      -1,    -1,    -1,    -1,    -1,   186,   233,    -1,    -1,   190,
      -1,    -1,    -1,    -1,   195,   196,   197,   198,   199,    -1,
      -1,    -1,   203,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   217,   218,    -1,    -1,
      -1,   222,     3,     4,    -1,    -1,   227,    -1,     9,    10,
      11,   232,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    -1,    -1,    -1,    12,
      13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    53,    54,    55,    56,    -1,    -1,    -1,    -1,
      61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    72,    73,    74,    -1,    -1,    -1,    -1,    -1,    80,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,    -1,    -1,    -1,    -1,   226,    -1,
      -1,    -1,    -1,    -1,    -1,   233,    -1,    -1,    -1,    -1,
      -1,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    -1,    -1,    -1,   100,   101,   102,
      -1,   104,    -1,    -1,    -1,    -1,   109,   110,   111,    -1,
      -1,   114,   115,    -1,   117,   118,   119,    -1,    -1,    -1,
     123,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    12,    13,    -1,   137,    -1,    -1,    -1,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,    -1,    -1,    -1,   186,   226,    -1,    -1,   190,
     163,   164,   165,   233,   195,   196,   197,   198,   199,    -1,
      -1,    -1,   203,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   217,   218,    12,    13,
      -1,   222,    -1,    -1,    -1,    -1,   227,    -1,    -1,    -1,
      -1,   232,    -1,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    -1,    -1,    -1,   100,
     101,   102,    -1,   104,    -1,    -1,    -1,    -1,   109,   110,
     111,    -1,   235,   114,   115,    -1,   117,   118,   119,    -1,
      -1,    -1,   123,    -1,    -1,    12,    13,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   137,    -1,    -1,    -1,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    -1,    -1,    -1,   100,   101,   102,    -1,
     104,    -1,   163,   164,   165,   109,   110,   111,    -1,    -1,
     114,   115,    -1,   117,   118,   119,    -1,    -1,    -1,   123,
      -1,    -1,    12,    13,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   137,    -1,    -1,    -1,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      -1,    -1,    -1,   100,   101,   102,    -1,   104,    -1,   163,
     164,   165,   109,   110,   111,    -1,    -1,   114,   115,    -1,
     117,   118,   119,    -1,   235,    -1,   123,    -1,    -1,    12,
      13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     137,    -1,    -1,    -1,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    -1,    -1,    -1,
     100,   101,   102,    -1,   104,    -1,   163,   164,   165,   109,
     110,   111,    -1,    -1,   114,   115,    -1,   117,   118,   119,
      -1,   235,    -1,   123,    -1,    -1,    12,    13,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   137,    -1,    -1,
      -1,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    -1,    -1,    -1,   100,   101,   102,
      -1,   104,    -1,   163,   164,   165,   109,   110,   111,    -1,
      -1,   114,   115,    -1,   117,   118,   119,    -1,   235,    -1,
     123,    -1,    -1,    12,    13,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   137,    -1,    -1,    -1,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    -1,    -1,    -1,   100,   101,   102,    -1,   104,    -1,
     163,   164,   165,   109,   110,   111,    -1,    -1,   114,   115,
      -1,   117,   118,   119,    -1,   235,    -1,   123,    -1,    -1,
      12,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   137,    -1,    -1,    -1,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    -1,    -1,
      -1,   100,   101,   102,    -1,   104,    -1,   163,   164,   165,
     109,   110,   111,    -1,    -1,   114,   115,    -1,   117,   118,
     119,    -1,   235,    -1,   123,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   137,    -1,
      -1,    -1,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    -1,    -1,    -1,   100,   101,
     102,    -1,   104,    -1,   163,   164,   165,   109,   110,   111,
      -1,    -1,   114,   115,    -1,   117,   118,   119,    -1,   235,
      -1,   123,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       0,     1,    -1,    -1,     4,   137,    -1,    -1,    -1,    -1,
      -1,    -1,    12,    13,    -1,    -1,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
      -1,   163,   164,   165,   226,    -1,    -1,    -1,    -1,    -1,
      -1,   233,    42,    43,    -1,    -1,   235,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,    -1,    62,    63,    64,   226,    -1,    -1,    68,    69,
      -1,    71,   233,    -1,    -1,    75,    76,    -1,    78,    79,
      -1,    -1,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    -1,    -1,    99,
     100,   101,   102,   235,   104,   105,   106,   107,   108,   109,
     110,   111,   112,    -1,   114,   115,   116,   117,   118,   119,
     120,    -1,   122,   123,   124,   125,   126,   127,   128,   129,
     130,    -1,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,    -1,    -1,    -1,   149,
     150,   151,     4,    -1,    -1,    -1,    -1,   157,    -1,    -1,
      12,    13,   162,   163,   164,   165,    -1,    -1,   168,    -1,
     170,    -1,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,    -1,    -1,    -1,    -1,
      42,    43,   192,   193,   194,    -1,    -1,    -1,    -1,    -1,
      -1,   201,    -1,   203,    -1,    -1,    -1,    -1,    -1,    -1,
      62,    63,    64,    -1,    -1,    -1,    68,    69,    -1,    71,
      -1,    -1,    -1,    75,    76,    -1,    78,    79,    -1,    -1,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    -1,    -1,    99,   100,   101,
     102,    -1,   104,   105,   106,   107,   108,   109,   110,   111,
     112,    -1,   114,   115,   116,   117,   118,   119,   120,    -1,
     122,   123,   124,   125,   126,   127,   128,   129,   130,    -1,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,    12,    13,    -1,   149,   150,   151,
      -1,    -1,    -1,    -1,    -1,   157,    -1,    -1,    -1,    -1,
     162,   163,   164,   165,    -1,    -1,   168,    -1,   170,    -1,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,    -1,    -1,    -1,    -1,    -1,    -1,
     192,   193,   194,    -1,    -1,    -1,    -1,    -1,    -1,   201,
      -1,   203,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    -1,
      -1,    -1,   100,   101,   102,    -1,   104,    -1,    -1,    -1,
      -1,   109,   110,   111,    -1,    -1,   114,   115,    -1,   117,
     118,   119,    -1,    -1,    -1,   123,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   137,
      -1,    -1,    -1,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,    -1,    -1,    -1,
      -1,   226,    -1,    -1,    -1,   163,   164,   165,   233,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,    -1,    -1,    -1,    -1,   226,    -1,    -1,
      -1,    -1,    -1,    -1,   233,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,    -1,
      -1,    -1,    -1,   226,    -1,    -1,    -1,    -1,    -1,    -1,
     233,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,    -1,    -1,    -1,    -1,   226,
      -1,    -1,    -1,    -1,    -1,    -1,   233,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,    -1,    -1,    -1,    -1,   226,    -1,    -1,    -1,    -1,
      -1,    -1,   233,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,    -1,    -1,    -1,
      -1,   226,    -1,    -1,    -1,    -1,    -1,    -1,   233,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,    -1,    -1,    -1,    -1,   226,    -1,    -1,
      -1,    -1,    -1,    -1,   233,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,    -1,
      -1,    -1,    -1,   226,    -1,    -1,    -1,    -1,    -1,    -1,
     233,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,    -1,    -1,    -1,    -1,   226,
      -1,    -1,    -1,    -1,    -1,    -1,   233,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,    -1,    -1,    -1,    -1,   226,    -1,    -1,    -1,    -1,
      -1,    -1,   233,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,    -1,    -1,    -1,
      -1,   226,    -1,    -1,    -1,    -1,    -1,    -1,   233,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,    -1,    -1,    -1,    -1,   226,    -1,    -1,
      -1,    -1,    -1,    -1,   233,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,    -1,
      -1,    -1,    -1,   226,    -1,    -1,    -1,    -1,    -1,    -1,
     233,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,    -1,    -1,    -1,    -1,   226,
      -1,    -1,    -1,    -1,    -1,    -1,   233,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,    -1,    -1,    -1,    -1,   226,    -1,    -1,    -1,    -1,
      -1,    -1,   233,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,    -1,    -1,    -1,
      -1,   226,    -1,    -1,    -1,    -1,    -1,    -1,   233,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,    -1,    -1,    -1,    -1,   226,    -1,    -1,
      -1,    -1,    -1,    -1,   233,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,    -1,
      -1,    -1,    -1,   226,    -1,    -1,    -1,    -1,    -1,    -1,
     233,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,    -1,    -1,    -1,    -1,   226,
      -1,    -1,    -1,    -1,    -1,    -1,   233,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,    -1,    -1,    -1,    -1,   226,    -1,    -1,    -1,    -1,
      -1,    -1,   233,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,    -1,    -1,    -1,
      -1,   226,    -1,    -1,    -1,    -1,    -1,    -1,   233,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,    -1,    -1,    -1,    -1,   226,    -1,    -1,
      -1,    -1,    -1,    -1,   233,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,    -1,
      -1,    -1,    -1,   226,    -1,    -1,    -1,    -1,    -1,    -1,
     233,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,    -1,    -1,    -1,    -1,   226,
      -1,    -1,    -1,    -1,    -1,    -1,   233,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,    -1,    -1,    -1,    -1,   226,    -1,    -1,    -1,    -1,
      -1,    -1,   233,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,    -1,    -1,    -1,
      -1,   226,    -1,    -1,    -1,    -1,    -1,    -1,   233,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,    -1,    -1,    -1,    -1,   226,    -1,    -1,
      -1,    -1,    -1,    -1,   233,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,    -1,
      -1,    -1,    -1,   226,    -1,    -1,    -1,    -1,    -1,    -1,
     233,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,    -1,    -1,    -1,    -1,   226,
      -1,    -1,    -1,    -1,    -1,    -1,   233,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,    -1,    -1,    -1,    -1,   226,    -1,    -1,    -1,    -1,
      -1,    -1,   233,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,    -1,    -1,    -1,
      -1,   226,    -1,    -1,    -1,    -1,    -1,    -1,   233,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,    -1,    -1,    -1,    -1,   226,    -1,    -1,
      -1,    -1,    -1,    -1,   233,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,    -1,
      -1,    -1,    -1,   226,    -1,    -1,    -1,    -1,    -1,    -1,
     233,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,    -1,    -1,    -1,    -1,   226,
      -1,    -1,    -1,    -1,    -1,    -1,   233,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,    -1,    -1,    -1,    -1,   226,    -1,    -1,    -1,    -1,
      -1,    -1,   233,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,    -1,    -1,    -1,
      -1,   226,    -1,    -1,    -1,    -1,    -1,    -1,   233,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,    -1,    -1,    -1,    -1,   226,    -1,    -1,
      -1,    -1,    -1,    -1,   233,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,    -1,
      -1,    -1,    -1,   226,    -1,    -1,    -1,    -1,    -1,    -1,
     233,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,    -1,    -1,    -1,    -1,   226,
      -1,    -1,    -1,    -1,    -1,    -1,   233,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,    -1,    -1,    -1,    -1,   226,    -1,    -1,    -1,    -1,
      -1,    -1,   233,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,    -1,    -1,    -1,
      -1,   226,    -1,    -1,    -1,    -1,    -1,    -1,   233,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,    -1,    -1,    -1,    -1,   226,    -1,    -1,
      -1,    -1,    -1,    -1,   233,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,    -1,
      -1,    -1,    -1,   226,    -1,    -1,    -1,    -1,    -1,    -1,
     233,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,    -1,    -1,    -1,    -1,   226,
      -1,    -1,    -1,    -1,    -1,    -1,   233,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,    -1,    -1,    -1,    -1,   226,    -1,    -1,    -1,    -1,
      -1,    -1,   233,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,    -1,    -1,    -1,
      -1,   226,    -1,    -1,    -1,    -1,    -1,    -1,   233,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,    -1,    -1,    -1,    -1,   226,    -1,    -1,
      -1,    -1,    -1,    -1,   233,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,    -1,
      -1,    -1,    -1,   226,    -1,    -1,    -1,    -1,    -1,    -1,
     233,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,    -1,    -1,    -1,    -1,   226,
      -1,    -1,    -1,    -1,    -1,    -1,   233,   208,   209,   210,
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
     221,    -1,    -1,    -1,    -1,   226
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
       4,   227,   234,   227,   227,     4,   234,   227,   227,   227,
     227,   227,   227,   227,   227,   227,   103,    90,    90,     6,
     234,    84,    87,    90,   227,     4,    37,    38,    39,    40,
      41,    84,    87,    90,    92,   110,   115,   118,   191,   218,
     227,   234,   283,   294,   310,   312,   323,   329,   331,   340,
     341,   227,   234,    90,    90,   110,    87,    90,    92,    92,
      84,    87,    90,    92,    87,    90,    92,    87,    90,   227,
      87,   168,   184,   185,   234,   217,   218,   227,   234,   326,
     327,   326,   234,    84,    87,    90,   234,   326,     4,    84,
      88,    94,    95,    97,    98,   114,   227,    90,    92,    90,
      87,     4,   179,   234,   340,   341,     4,     6,    84,    87,
      90,    87,    90,     4,     4,     4,     5,   227,   329,   330,
       4,   227,   227,   227,     4,   234,   333,   341,     4,   227,
     227,   227,     6,     6,   229,     4,   337,   341,   227,     4,
     337,     5,   234,     5,   234,     4,   323,   340,   229,   227,
     234,     6,   227,   234,   227,   229,   236,   261,     7,   204,
     205,   206,   207,   224,   225,   259,   260,     4,   227,   229,
     231,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   227,   227,   227,   261,
     261,   261,   261,   227,   261,   261,   261,   261,   261,   261,
     227,   261,   261,   261,     7,   227,   227,   227,   261,   261,
     227,   227,   229,   323,   323,   323,   228,   323,   230,   323,
       4,   168,   169,   341,     4,   283,   284,   285,   234,   234,
       6,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   226,   234,     6,   227,   229,
     260,     6,   323,     4,   336,   337,   340,   341,   336,   323,
     336,   339,   265,   270,   337,   341,   323,   218,   323,   331,
     332,   323,   323,   227,   323,   332,   323,   323,   227,   332,
     323,   323,   323,   323,   323,   323,   336,   323,   323,   329,
     227,   234,   332,   330,   330,   330,   336,   227,   229,   231,
     261,   227,   229,   261,   261,   261,   261,     5,   171,   234,
       5,   171,     5,   171,     5,   171,   110,    84,    87,    90,
      92,   261,   234,   323,   331,   323,   235,   332,     8,   219,
     227,   229,   261,   323,   332,   227,   227,   227,   329,   330,
     330,   330,   227,   227,   227,   227,   227,   227,   329,   227,
     329,   227,   329,   234,   234,   323,     4,   329,   333,   234,
     234,   326,   326,   326,   323,   323,   217,   218,   234,   234,
     326,   234,   234,   234,   217,   218,   227,   285,   326,   234,
     227,   234,   227,   227,   227,   227,   227,   227,   227,   323,
     330,   330,   329,   227,     4,   229,   229,   285,     6,     6,
     234,   234,   234,   330,   330,   229,   229,   229,   323,     6,
       6,   323,   323,   323,   231,   323,   234,   171,   323,   323,
     323,   323,     6,     6,   234,     6,   285,     6,   285,   227,
     229,   234,   227,   229,   336,   323,   285,   329,   329,   228,
     323,   230,   323,   234,   234,   337,   329,     6,   229,   323,
     323,     4,   323,   323,   323,   323,   323,   323,   323,   323,
     323,   323,   323,   323,   323,   323,   323,   323,   323,   323,
     323,   323,   323,   323,   339,   336,   339,   336,   336,   336,
     336,   336,   336,   336,   329,   336,   336,   323,   336,   336,
     336,   339,   336,   323,   337,   323,   336,   336,   336,   336,
     336,   341,   337,   341,     7,   207,   259,   228,     7,   207,
     259,   230,     7,   259,   260,   231,     7,   261,   235,    84,
      87,    90,    92,   110,   115,   282,   323,   332,   323,   323,
     323,   323,   323,   323,   323,   323,   323,   323,   323,   323,
     323,   323,   323,   244,   323,   323,     6,   227,   229,   231,
     228,   233,   227,   229,   228,   233,   233,   228,   233,   230,
     233,   264,   230,   264,   233,   233,   228,   219,   233,   235,
     228,   228,   323,   228,   235,   228,   228,   323,   235,   228,
     228,   228,   228,   228,   228,   228,   228,   228,     7,   323,
     323,   235,     6,     6,     6,   228,   323,   323,     4,   228,
     230,   234,   262,   234,   323,   331,   234,   331,   341,   323,
     323,   336,   323,    62,   323,    62,    62,    62,     5,   234,
       5,   234,     5,   234,     5,   234,   331,   332,   228,   235,
     323,   234,   323,   331,   323,   323,   234,   262,   228,   235,
     323,   323,   323,     7,     7,   316,   316,   323,   276,   323,
     337,   277,   323,   337,   278,   323,   337,   279,   323,   337,
     323,     6,   323,     6,   323,     6,   332,   332,   234,   228,
       6,   234,   285,   285,   233,   233,   233,   326,   326,   284,
     284,   233,   323,   323,   323,   323,   235,   298,   233,   285,
     323,   323,   323,   323,   323,   323,   323,   323,   323,   228,
       7,   317,     6,     7,   323,     6,   323,   323,   235,   332,
     332,   332,     6,     6,   323,   323,   323,   228,   228,   228,
     228,   168,   233,   285,   234,     8,   228,   228,   230,   332,
     235,   235,   285,   230,   228,   141,   311,   228,   233,   235,
       7,   207,   259,   228,     7,   207,   259,   230,   323,   332,
       6,     6,   323,   228,   230,   260,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   262,   262,   233,   262,   262,
     262,   262,   262,   262,   262,   233,   233,   233,   262,   233,
     262,   262,   228,   228,   233,   262,   262,   233,   262,   233,
     233,   233,   233,   262,   262,   262,   228,   262,   325,   338,
       6,   233,   233,   228,   233,   262,   233,   262,   228,   228,
     230,    44,    44,   329,     7,   259,   260,    44,    44,   329,
     231,   259,   260,   337,   323,     6,     4,     4,   234,   334,
     262,   234,   234,   234,   234,   227,   110,   235,   235,     8,
       4,   158,   159,   160,   161,   235,   247,   251,   254,   256,
     257,   228,   230,   323,   323,     4,     6,   214,   241,   332,
     323,   323,     6,   332,   323,     6,   336,     6,   341,     6,
     336,   323,   337,     7,   323,   331,   171,     7,     7,   228,
       7,   171,     7,     7,   228,   171,     7,     7,     7,     7,
       7,     7,     7,     7,   323,   228,   235,   234,     6,   228,
     230,   332,   332,   228,   332,   230,   230,   233,   233,   262,
     233,   234,   235,   234,   234,   234,   332,   332,   332,   332,
     262,   235,     7,     8,   332,   228,   230,   332,     7,   234,
     228,   228,   228,   323,   329,     4,   315,     6,   228,   228,
     233,   228,   233,   228,   233,   228,   233,   228,   228,   228,
     235,   235,   332,   231,   285,   235,   235,   326,   323,   323,
     235,   235,   323,   326,   233,   233,   233,   121,   121,   138,
     146,   147,   148,   152,   153,   154,   155,   308,   309,   326,
     235,   295,   228,   235,   228,   228,   228,   228,   228,   228,
     228,     7,   323,     6,   323,   228,   230,   230,   235,   235,
     235,   230,   230,   233,     7,     7,     7,   231,   323,   235,
     323,   323,     7,   231,   235,   235,     7,     6,   323,   235,
     234,   329,     6,    44,    44,   329,   259,   260,    44,    44,
     329,   259,   260,   235,   235,   230,   260,   231,   260,   336,
     323,   323,   323,   323,   332,   336,   323,   329,   336,   336,
     336,   272,   274,   323,   336,   336,   323,   261,   261,     6,
     323,     6,   261,   261,     6,     4,   168,   169,   323,     6,
       6,     6,     7,   229,   333,   335,     6,   332,   332,   332,
     332,   323,   227,   262,   323,   248,   227,   227,   234,   258,
       6,   260,   260,   228,   230,   214,   336,   228,   228,   230,
     228,   233,     7,   227,   229,   262,   262,   326,    90,    92,
     329,   329,     7,   329,    90,    92,   329,   329,     7,    92,
     329,   329,   329,   329,   329,   329,   329,   329,     6,     7,
       7,   332,   231,   235,   235,   235,   323,   323,   323,   323,
     323,   323,   323,   235,   235,   235,   235,   329,   323,   235,
     235,   329,   332,     7,     7,     7,   121,   314,     6,     7,
     259,   323,   259,   323,   259,   323,   259,   323,     7,     7,
       7,     7,     7,   235,     4,   235,   233,   233,   233,   235,
     235,   326,   326,   326,    87,     4,     6,   323,   234,     6,
     227,     6,   156,     6,   156,     6,   156,     6,   156,   235,
     309,   233,   308,     7,     6,     7,     7,     7,     7,     7,
       7,     7,   329,     6,   234,     6,     6,     6,    90,     7,
       6,     6,   323,   329,   329,   329,     4,   233,     8,     8,
     228,     4,     4,   233,   234,     6,   234,   329,   235,   261,
     261,     6,   323,     6,   261,   261,     6,   323,     6,   262,
       6,     4,     6,   262,   262,   262,   262,   262,   233,   233,
     262,   228,   262,   262,   233,   233,   262,   273,   233,   262,
     275,   228,   228,   262,   262,   262,   339,   339,     6,   262,
     339,   339,     7,   259,   260,   231,     7,     6,   333,   323,
     233,   235,   235,   235,   235,   235,   228,   323,   259,   227,
     323,   323,   328,   329,   234,   231,     6,     6,   241,     6,
     323,   234,   323,   337,   228,   230,     6,     6,     6,   234,
     234,   114,   281,   281,   329,     6,   234,   234,     6,     6,
     329,   234,     6,     6,     6,     6,     6,     6,     6,     6,
       5,   329,   235,     4,   262,   228,   230,   233,   233,   233,
     233,   233,   233,   233,     6,   262,     6,   235,   329,   329,
     329,     4,     6,   329,   329,   329,   329,   329,   329,   329,
     329,   234,   234,     7,     6,     7,   323,   323,   323,   234,
     234,   233,   235,   233,   235,   233,   235,   234,   229,     6,
     323,   329,   323,     6,     6,     6,     6,   323,   326,   235,
       5,   329,   234,   234,   234,   234,   234,   234,   234,   329,
       6,   332,   234,   323,   230,     6,     6,   167,   323,   323,
     323,     6,     6,     7,   337,   285,   285,   233,     6,   262,
     339,   339,     6,   262,   339,   339,     6,   259,   260,   336,
     323,   336,     4,     4,   183,     6,   262,   262,     6,   262,
     262,   337,   323,     6,     4,   334,     6,   230,   333,     6,
       6,     6,     6,   228,   329,   245,   323,   233,   233,   233,
     235,   246,   323,     4,   336,   233,   329,   337,     7,     7,
     323,   323,   326,     6,     6,     6,   323,   323,     6,   323,
       5,     6,   234,   323,   323,   323,   323,   323,   323,   323,
     234,     6,   171,   280,     6,   323,     6,     6,     6,     6,
       6,     6,     4,     6,     6,   332,   332,   323,   323,   337,
     235,   228,   233,   235,   284,   284,   326,     6,   299,   326,
       6,   300,   326,     6,   301,   329,   323,   235,   233,   228,
     235,   233,     6,     6,   328,   326,   326,   326,   326,   326,
     218,   326,     6,   235,   323,     6,     6,   329,   233,   235,
       8,   235,   228,   234,   323,   337,   233,   311,   311,   329,
       6,   262,   262,     6,   262,   262,   329,   228,   262,   262,
     234,   329,   337,   234,   323,   337,   337,     6,     6,     6,
       6,     6,     6,     7,     6,   231,     6,   228,   233,   323,
     323,   329,   234,   233,   235,     6,   323,   266,   269,   234,
     234,   235,   235,   235,   235,   235,     5,   328,   262,   262,
     233,   233,   233,   233,   233,   323,    88,     6,   234,   235,
     235,   234,     6,     6,   234,   323,   235,   235,   233,   234,
     233,   234,   233,   234,   235,   230,     6,   329,     7,   234,
     323,   235,   233,   233,   233,   233,   233,   233,     6,   235,
     166,   323,   323,   332,     6,     6,   337,   235,   235,   235,
       6,     6,     6,     6,     6,   271,   323,   331,   339,   333,
     169,   249,   323,   233,   233,   328,   323,     6,   233,   272,
     274,   329,   329,     6,     6,     6,     6,     6,     6,   235,
     323,   323,   323,   323,   323,   235,   234,   328,   125,   126,
     131,   318,   125,   126,   318,   332,   284,   233,   235,   323,
     326,   308,   323,   326,   308,   323,   326,   308,     6,   233,
     235,   329,   285,   235,     6,   332,   326,   326,   326,   326,
     326,   323,   235,   235,   235,   228,   234,     6,   233,   235,
       7,     7,   235,     6,   234,   323,   323,   235,   323,   235,
     235,   268,   267,   234,   233,   233,   233,   233,   233,   323,
     235,   234,   326,   329,     6,   234,   326,     6,   235,   235,
     323,   235,   233,   235,   235,   233,   235,   235,   233,   235,
     329,     6,   121,   235,   296,   234,   235,   233,   233,   233,
     233,   233,     6,     6,     6,   285,   323,   337,   341,   246,
     228,   233,     6,   234,   233,   272,   272,   323,   323,   323,
     323,   323,   323,   235,     6,   326,     6,   326,     6,     6,
     235,     6,   302,   323,     6,     6,   303,   323,     6,     6,
     304,   323,     6,   235,   323,   308,   285,     6,   332,   332,
     332,   332,   326,   332,   311,     7,   227,   235,   252,   323,
     328,   323,   235,   235,   233,   233,   233,   233,   233,   233,
     233,   233,   234,   235,   234,   235,   234,   235,     6,     6,
     235,   235,   297,   235,   235,   235,   235,   233,   235,   235,
     337,   228,     6,   234,   228,   235,   235,   323,   323,   323,
     323,   323,   323,   326,   326,   308,     6,   305,   308,     6,
     306,   308,     6,   307,   308,     6,     6,     6,     6,   332,
       6,     6,   250,   336,   255,   234,     6,   235,   262,   233,
     233,   233,   233,   233,   233,   235,   234,   235,   234,   235,
     234,   235,   235,   233,   235,   234,   328,     6,   323,   323,
     323,   323,   323,   323,     6,   308,     6,   308,     6,   308,
       6,   336,     6,   253,   336,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   233,   235,     6,     6,     6,
       6,     6,     6,   336,     6
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
      // FIXME: when changing to OpenCASCADE, get maxTag for all dimensions
      // and add that info in OCC_Internals - same in the other direction
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
      }
      List_Delete((yyvsp[(7) - (9)].l));
      (yyval.s).Type = type;
      (yyval.s).Num = num;
    ;}
    break;

  case 188:
#line 2270 "Gmsh.y"
    {
      myGmshSurface = 0;
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 189:
#line 2276 "Gmsh.y"
    {
      myGmshSurface = gmshSurface::getSurface((int)(yyvsp[(3) - (4)].d));
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 190:
#line 2282 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (10)].d);
      myGmshSurface = gmshParametricSurface::NewParametricSurface(num, (yyvsp[(7) - (10)].c), (yyvsp[(8) - (10)].c), (yyvsp[(9) - (10)].c));
      (yyval.s).Type = 0;
      (yyval.s).Num = num;
    ;}
    break;

  case 191:
#line 2289 "Gmsh.y"
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

  case 192:
#line 2331 "Gmsh.y"
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
#line 2357 "Gmsh.y"
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
#line 2381 "Gmsh.y"
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

  case 195:
#line 2405 "Gmsh.y"
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

  case 196:
#line 2430 "Gmsh.y"
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

  case 197:
#line 2453 "Gmsh.y"
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

  case 198:
#line 2480 "Gmsh.y"
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

  case 199:
#line 2508 "Gmsh.y"
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

  case 200:
#line 2533 "Gmsh.y"
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

  case 201:
#line 2556 "Gmsh.y"
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

  case 202:
#line 2583 "Gmsh.y"
    {
      GModel::current()->getGEOInternals()->addCompoundMesh ( 2 , (yyvsp[(3) - (4)].l) );
    ;}
    break;

  case 203:
#line 2587 "Gmsh.y"
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

  case 204:
#line 2607 "Gmsh.y"
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

  case 205:
#line 2640 "Gmsh.y"
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

  case 206:
#line 2687 "Gmsh.y"
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

  case 207:
#line 2705 "Gmsh.y"
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

  case 208:
#line 2732 "Gmsh.y"
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

  case 209:
#line 2751 "Gmsh.y"
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

  case 210:
#line 2770 "Gmsh.y"
    {
      GModel::current()->getGEOInternals()->addCompoundMesh(3, (yyvsp[(3) - (4)].l));
    ;}
    break;

  case 211:
#line 2774 "Gmsh.y"
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

  case 212:
#line 2790 "Gmsh.y"
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

  case 213:
#line 2838 "Gmsh.y"
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

  case 214:
#line 2855 "Gmsh.y"
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

  case 215:
#line 2873 "Gmsh.y"
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

  case 216:
#line 2883 "Gmsh.y"
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

  case 217:
#line 2893 "Gmsh.y"
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

  case 218:
#line 2903 "Gmsh.y"
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

  case 219:
#line 2966 "Gmsh.y"
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

  case 220:
#line 2977 "Gmsh.y"
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

  case 221:
#line 2992 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 222:
#line 2993 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 223:
#line 2998 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    ;}
    break;

  case 224:
#line 3002 "Gmsh.y"
    {
      List_Add((yyval.l), &(yyvsp[(2) - (2)].s));
    ;}
    break;

  case 225:
#line 3006 "Gmsh.y"
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

  case 226:
#line 3035 "Gmsh.y"
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

  case 227:
#line 3064 "Gmsh.y"
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

  case 228:
#line 3093 "Gmsh.y"
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

  case 229:
#line 3127 "Gmsh.y"
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

  case 230:
#line 3149 "Gmsh.y"
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

  case 231:
#line 3176 "Gmsh.y"
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

  case 232:
#line 3198 "Gmsh.y"
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

  case 233:
#line 3220 "Gmsh.y"
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

  case 234:
#line 3242 "Gmsh.y"
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

  case 235:
#line 3298 "Gmsh.y"
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

  case 236:
#line 3322 "Gmsh.y"
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

  case 237:
#line 3347 "Gmsh.y"
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

  case 238:
#line 3372 "Gmsh.y"
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

  case 239:
#line 3485 "Gmsh.y"
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

  case 240:
#line 3504 "Gmsh.y"
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

  case 241:
#line 3547 "Gmsh.y"
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

  case 242:
#line 3568 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      GModel::current()->getFields()->deleteField((int)(yyvsp[(4) - (6)].d));
#endif
    ;}
    break;

  case 243:
#line 3574 "Gmsh.y"
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

  case 244:
#line 3589 "Gmsh.y"
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

  case 245:
#line 3617 "Gmsh.y"
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

  case 246:
#line 3634 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(4) - (5)].l), i, &TheShape);
	ColorShape(TheShape.Type, TheShape.Num, (yyvsp[(2) - (5)].u), false);
      }
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 247:
#line 3643 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(5) - (6)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(5) - (6)].l), i, &TheShape);
	ColorShape(TheShape.Type, TheShape.Num, (yyvsp[(3) - (6)].u), true);
      }
      List_Delete((yyvsp[(5) - (6)].l));
    ;}
    break;

  case 248:
#line 3657 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(4) - (5)].l), i, &TheShape);
	SetPartition(TheShape.Type, TheShape.Num, (yyvsp[(2) - (5)].d));
      }
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 249:
#line 3671 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 1, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 250:
#line 3677 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 0, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 251:
#line 3683 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 1, false);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 252:
#line 3692 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(4) - (5)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 1, true);
      }
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 253:
#line 3701 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 0, false);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 254:
#line 3710 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(4) - (5)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 0, true);
      }
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 255:
#line 3724 "Gmsh.y"
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

  case 256:
#line 3786 "Gmsh.y"
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

  case 257:
#line 3804 "Gmsh.y"
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

  case 258:
#line 3821 "Gmsh.y"
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

  case 259:
#line 3836 "Gmsh.y"
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

  case 260:
#line 3865 "Gmsh.y"
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

  case 261:
#line 3877 "Gmsh.y"
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

  case 262:
#line 3901 "Gmsh.y"
    {
      Msg::Exit(0);
    ;}
    break;

  case 263:
#line 3905 "Gmsh.y"
    {
      gmsh_yyerrorstate = 999; // this will be checked when yyparse returns
      YYABORT;
    ;}
    break;

  case 264:
#line 3910 "Gmsh.y"
    {
      // FIXME: this is a hack to force a transfer from the old DB to
      // the new DB. This will become unnecessary if/when we fill the
      // GModel directly during parsing.
      GModel::current()->importGEOInternals();
      GModel::current()->importOCCInternals();
    ;}
    break;

  case 265:
#line 3918 "Gmsh.y"
    {
      new GModel();
      GModel::current(GModel::list.size() - 1);
    ;}
    break;

  case 266:
#line 3923 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 0;
      GModel::current()->importGEOInternals();
      SetBoundingBox();
    ;}
    break;

  case 267:
#line 3929 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 1;
      SetBoundingBox((yyvsp[(3) - (15)].d), (yyvsp[(5) - (15)].d), (yyvsp[(7) - (15)].d), (yyvsp[(9) - (15)].d), (yyvsp[(11) - (15)].d), (yyvsp[(13) - (15)].d));
    ;}
    break;

  case 268:
#line 3934 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
      drawContext::global()->draw();
#endif
    ;}
    break;

  case 269:
#line 3940 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
     CTX::instance()->mesh.changed = ENT_ALL;
     for(unsigned int index = 0; index < PView::list.size(); index++)
       PView::list[index]->setChanged(true);
#endif
    ;}
    break;

  case 270:
#line 3948 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh();
    ;}
    break;

  case 271:
#line 3952 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh(1);
    ;}
    break;

  case 272:
#line 3956 "Gmsh.y"
    {
      GModel::current()->importGEOInternals();
      GModel::current()->refineMesh(CTX::instance()->mesh.secondOrderLinear);
    ;}
    break;

  case 273:
#line 3962 "Gmsh.y"
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

  case 274:
#line 4021 "Gmsh.y"
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

  case 275:
#line 4037 "Gmsh.y"
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

  case 276:
#line 4054 "Gmsh.y"
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

  case 277:
#line 4071 "Gmsh.y"
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

  case 278:
#line 4093 "Gmsh.y"
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

  case 279:
#line 4115 "Gmsh.y"
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

  case 280:
#line 4150 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip_until(NULL, "Return");
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 281:
#line 4158 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip_until(NULL, "Return");
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 282:
#line 4166 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    ;}
    break;

  case 283:
#line 4172 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 284:
#line 4179 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 285:
#line 4186 "Gmsh.y"
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

  case 286:
#line 4206 "Gmsh.y"
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

  case 287:
#line 4232 "Gmsh.y"
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

  case 288:
#line 4244 "Gmsh.y"
    {
      ImbricatedTest--;
      if(ImbricatedTest < 0)
        yymsg(1, "Orphan EndIf");
    ;}
    break;

  case 289:
#line 4256 "Gmsh.y"
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

  case 290:
#line 4286 "Gmsh.y"
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

  case 291:
#line 4317 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (13)].l),
		    (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].v)[0], (yyvsp[(7) - (13)].v)[1], (yyvsp[(7) - (13)].v)[2], (yyvsp[(9) - (13)].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[(12) - (13)].l));
    ;}
    break;

  case 292:
#line 4325 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 293:
#line 4331 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (7)].l),
		    (yyvsp[(2) - (7)].v)[0], (yyvsp[(2) - (7)].v)[1], (yyvsp[(2) - (7)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(4) - (7)].l));
    ;}
    break;

  case 294:
#line 4339 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 295:
#line 4345 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[(10) - (13)].l),
		    0., 0., 0., (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(10) - (13)].l));
    ;}
    break;

  case 296:
#line 4353 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 297:
#line 4359 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (15)].l),
		    (yyvsp[(3) - (15)].v)[0], (yyvsp[(3) - (15)].v)[1], (yyvsp[(3) - (15)].v)[2], (yyvsp[(5) - (15)].v)[0], (yyvsp[(5) - (15)].v)[1], (yyvsp[(5) - (15)].v)[2], (yyvsp[(7) - (15)].v)[0], (yyvsp[(7) - (15)].v)[1], (yyvsp[(7) - (15)].v)[2], (yyvsp[(9) - (15)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(12) - (15)].l));
    ;}
    break;

  case 298:
#line 4367 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 299:
#line 4373 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(BOUNDARY_LAYER, (yyvsp[(3) - (6)].l), 0., 0., 0., 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(3) - (6)].l));
    ;}
    break;

  case 300:
#line 4380 "Gmsh.y"
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

  case 301:
#line 4413 "Gmsh.y"
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

  case 302:
#line 4436 "Gmsh.y"
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

  case 303:
#line 4459 "Gmsh.y"
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

  case 304:
#line 4490 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 305:
#line 4497 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 306:
#line 4504 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 307:
#line 4511 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 308:
#line 4518 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 309:
#line 4525 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 310:
#line 4532 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 311:
#line 4539 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 312:
#line 4546 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 313:
#line 4553 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 314:
#line 4559 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 315:
#line 4566 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 316:
#line 4572 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 317:
#line 4579 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 318:
#line 4585 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 319:
#line 4592 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 320:
#line 4598 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 321:
#line 4605 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 322:
#line 4611 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 323:
#line 4618 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 324:
#line 4624 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 325:
#line 4631 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 326:
#line 4637 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 327:
#line 4644 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 328:
#line 4650 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 329:
#line 4657 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 330:
#line 4663 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 331:
#line 4674 "Gmsh.y"
    {
    ;}
    break;

  case 332:
#line 4677 "Gmsh.y"
    {
    ;}
    break;

  case 333:
#line 4683 "Gmsh.y"
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

  case 334:
#line 4695 "Gmsh.y"
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

  case 335:
#line 4715 "Gmsh.y"
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

  case 336:
#line 4739 "Gmsh.y"
    {
      extr.mesh.ScaleLast = true;
    ;}
    break;

  case 337:
#line 4743 "Gmsh.y"
    {
      extr.mesh.Recombine = true;
    ;}
    break;

  case 338:
#line 4747 "Gmsh.y"
    {
      extr.mesh.Recombine = (yyvsp[(2) - (3)].d) ? true : false;
    ;}
    break;

  case 339:
#line 4751 "Gmsh.y"
    {
      yymsg(0, "Keyword 'QuadTriSngl' deprecated. Use 'QuadTriNoNewVerts' instead.");
    ;}
    break;

  case 340:
#line 4755 "Gmsh.y"
    {
      yymsg(0, "Keyword 'QuadTriSngl' deprecated. Use 'QuadTriNoNewVerts' instead.");
    ;}
    break;

  case 341:
#line 4759 "Gmsh.y"
    {
      yymsg(0, "Method 'QuadTriDbl' deprecated. Use 'QuadTriAddVerts' instead, "
            "which has no requirement for the number of extrusion layers and meshes "
            "with body-centered vertices.");
    ;}
    break;

  case 342:
#line 4765 "Gmsh.y"
    {
      yymsg(0, "Method 'QuadTriDbl' deprecated. Use 'QuadTriAddVerts' instead, "
            "which has no requirement for the number of extrusion layers and meshes "
            "with body-centered vertices.");
    ;}
    break;

  case 343:
#line 4771 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1;
    ;}
    break;

  case 344:
#line 4775 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1_RECOMB;
    ;}
    break;

  case 345:
#line 4779 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1;
    ;}
    break;

  case 346:
#line 4783 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1_RECOMB;
    ;}
    break;

  case 347:
#line 4787 "Gmsh.y"
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

  case 348:
#line 4806 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (6)].c), "Index"))
        extr.mesh.BoundaryLayerIndex = (yyvsp[(4) - (6)].d);
      else if(!strcmp((yyvsp[(2) - (6)].c), "View"))
        extr.mesh.ViewIndex = (yyvsp[(4) - (6)].d);
      Free((yyvsp[(2) - (6)].c));
    ;}
    break;

  case 349:
#line 4818 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Union; ;}
    break;

  case 350:
#line 4819 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Intersection; ;}
    break;

  case 351:
#line 4820 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Difference; ;}
    break;

  case 352:
#line 4821 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Section; ;}
    break;

  case 353:
#line 4822 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Fragments; ;}
    break;

  case 354:
#line 4826 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 355:
#line 4827 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 356:
#line 4828 "Gmsh.y"
    { (yyval.i) = (yyvsp[(2) - (3)].d); ;}
    break;

  case 357:
#line 4833 "Gmsh.y"
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

  case 358:
#line 4866 "Gmsh.y"
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

  case 359:
#line 4893 "Gmsh.y"
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

  case 360:
#line 4915 "Gmsh.y"
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    ;}
    break;

  case 361:
#line 4919 "Gmsh.y"
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

  case 362:
#line 4934 "Gmsh.y"
    {
      (yyval.i) = -1; // left
    ;}
    break;

  case 363:
#line 4938 "Gmsh.y"
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

  case 364:
#line 4954 "Gmsh.y"
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   ;}
    break;

  case 365:
#line 4958 "Gmsh.y"
    {
     (yyval.l) = (yyvsp[(2) - (2)].l);
   ;}
    break;

  case 366:
#line 4963 "Gmsh.y"
    {
      (yyval.i) = 45;
    ;}
    break;

  case 367:
#line 4967 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(2) - (2)].d);
    ;}
    break;

  case 368:
#line 4973 "Gmsh.y"
    {
      (yyval.l) = List_Create(1, 1, sizeof(double));
    ;}
    break;

  case 369:
#line 4977 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
    ;}
    break;

  case 370:
#line 4984 "Gmsh.y"
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

  case 371:
#line 5040 "Gmsh.y"
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

  case 372:
#line 5110 "Gmsh.y"
    {
      yymsg(1, "Elliptic Surface is deprecated: use Transfinite instead (with smoothing)");
      List_Delete((yyvsp[(7) - (8)].l));
    ;}
    break;

  case 373:
#line 5115 "Gmsh.y"
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

  case 374:
#line 5182 "Gmsh.y"
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

  case 375:
#line 5218 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (8)].l)); i++){
	double d;
	List_Read((yyvsp[(4) - (8)].l), i, &d);
	CTX::instance()->mesh.algo2d_per_face[(int)d] = (int)(yyvsp[(7) - (8)].d);
      }
    ;}
    break;

  case 376:
#line 5226 "Gmsh.y"
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

  case 377:
#line 5269 "Gmsh.y"
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

  case 378:
#line 5308 "Gmsh.y"
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

  case 379:
#line 5329 "Gmsh.y"
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

  case 380:
#line 5361 "Gmsh.y"
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

  case 381:
#line 5388 "Gmsh.y"
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

  case 382:
#line 5414 "Gmsh.y"
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

  case 383:
#line 5440 "Gmsh.y"
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

  case 384:
#line 5466 "Gmsh.y"
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

  case 385:
#line 5492 "Gmsh.y"
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

  case 386:
#line 5513 "Gmsh.y"
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

  case 387:
#line 5541 "Gmsh.y"
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

  case 388:
#line 5569 "Gmsh.y"
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

  case 389:
#line 5597 "Gmsh.y"
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

  case 390:
#line 5625 "Gmsh.y"
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

  case 391:
#line 5653 "Gmsh.y"
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

  case 392:
#line 5692 "Gmsh.y"
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

  case 393:
#line 5731 "Gmsh.y"
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

  case 394:
#line 5752 "Gmsh.y"
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

  case 395:
#line 5773 "Gmsh.y"
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

  case 396:
#line 5800 "Gmsh.y"
    {
      ReplaceAllDuplicates();
    ;}
    break;

  case 397:
#line 5804 "Gmsh.y"
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

  case 398:
#line 5814 "Gmsh.y"
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

  case 399:
#line 5848 "Gmsh.y"
    { (yyval.c) = (char*)"Homology"; ;}
    break;

  case 400:
#line 5849 "Gmsh.y"
    { (yyval.c) = (char*)"Cohomology"; ;}
    break;

  case 401:
#line 5850 "Gmsh.y"
    { (yyval.c) = (char*)"Betti"; ;}
    break;

  case 402:
#line 5855 "Gmsh.y"
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest((yyvsp[(1) - (2)].c), domain, subdomain, dim);
    ;}
    break;

  case 403:
#line 5861 "Gmsh.y"
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

  case 404:
#line 5873 "Gmsh.y"
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

  case 405:
#line 5891 "Gmsh.y"
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

  case 406:
#line 5918 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d);           ;}
    break;

  case 407:
#line 5919 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (3)].d);           ;}
    break;

  case 408:
#line 5920 "Gmsh.y"
    { (yyval.d) = -(yyvsp[(2) - (2)].d);          ;}
    break;

  case 409:
#line 5921 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);           ;}
    break;

  case 410:
#line 5922 "Gmsh.y"
    { (yyval.d) = !(yyvsp[(2) - (2)].d);          ;}
    break;

  case 411:
#line 5923 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) - (yyvsp[(3) - (3)].d);      ;}
    break;

  case 412:
#line 5924 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) + (yyvsp[(3) - (3)].d);      ;}
    break;

  case 413:
#line 5925 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) * (yyvsp[(3) - (3)].d);      ;}
    break;

  case 414:
#line 5927 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (3)].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));
      else
	(yyval.d) = (yyvsp[(1) - (3)].d) / (yyvsp[(3) - (3)].d);
    ;}
    break;

  case 415:
#line 5933 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) % (int)(yyvsp[(3) - (3)].d);  ;}
    break;

  case 416:
#line 5934 "Gmsh.y"
    { (yyval.d) = pow((yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));  ;}
    break;

  case 417:
#line 5935 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d);      ;}
    break;

  case 418:
#line 5936 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) > (yyvsp[(3) - (3)].d);      ;}
    break;

  case 419:
#line 5937 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) <= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 420:
#line 5938 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) >= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 421:
#line 5939 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) == (yyvsp[(3) - (3)].d);     ;}
    break;

  case 422:
#line 5940 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) != (yyvsp[(3) - (3)].d);     ;}
    break;

  case 423:
#line 5941 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) && (yyvsp[(3) - (3)].d);     ;}
    break;

  case 424:
#line 5942 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) || (yyvsp[(3) - (3)].d);     ;}
    break;

  case 425:
#line 5943 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (5)].d) ? (yyvsp[(3) - (5)].d) : (yyvsp[(5) - (5)].d); ;}
    break;

  case 426:
#line 5944 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 427:
#line 5945 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 428:
#line 5946 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 429:
#line 5947 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 430:
#line 5948 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 431:
#line 5949 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 432:
#line 5950 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 433:
#line 5951 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 434:
#line 5952 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 435:
#line 5953 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 436:
#line 5954 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 437:
#line 5955 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 438:
#line 5956 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 439:
#line 5957 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 440:
#line 5958 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 441:
#line 5959 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 442:
#line 5960 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 443:
#line 5961 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d) + 0.5); ;}
    break;

  case 444:
#line 5962 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 445:
#line 5963 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 446:
#line 5964 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 447:
#line 5965 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 448:
#line 5974 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 449:
#line 5975 "Gmsh.y"
    { (yyval.d) = 3.141592653589793; ;}
    break;

  case 450:
#line 5976 "Gmsh.y"
    { (yyval.d) = (double)ImbricatedTest; ;}
    break;

  case 451:
#line 5977 "Gmsh.y"
    { (yyval.d) = Msg::GetCommRank(); ;}
    break;

  case 452:
#line 5978 "Gmsh.y"
    { (yyval.d) = Msg::GetCommSize(); ;}
    break;

  case 453:
#line 5979 "Gmsh.y"
    { (yyval.d) = GetGmshMajorVersion(); ;}
    break;

  case 454:
#line 5980 "Gmsh.y"
    { (yyval.d) = GetGmshMinorVersion(); ;}
    break;

  case 455:
#line 5981 "Gmsh.y"
    { (yyval.d) = GetGmshPatchVersion(); ;}
    break;

  case 456:
#line 5982 "Gmsh.y"
    { (yyval.d) = Cpu(); ;}
    break;

  case 457:
#line 5983 "Gmsh.y"
    { (yyval.d) = GetMemoryUsage()/1024./1024.; ;}
    break;

  case 458:
#line 5984 "Gmsh.y"
    { (yyval.d) = TotalRam(); ;}
    break;

  case 459:
#line 5989 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 460:
#line 5991 "Gmsh.y"
    {
      std::vector<double> val(1, (yyvsp[(3) - (6)].d));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.d) = val[0];
    ;}
    break;

  case 461:
#line 5997 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 462:
#line 6002 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 463:
#line 6007 "Gmsh.y"
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

  case 464:
#line 6024 "Gmsh.y"
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
#line 6042 "Gmsh.y"
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
#line 6060 "Gmsh.y"
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
#line 6078 "Gmsh.y"
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
#line 6096 "Gmsh.y"
    {
      (yyval.d) = gmsh_yysymbols.count((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 469:
#line 6101 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.d) = !StatFile(tmp);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 470:
#line 6107 "Gmsh.y"
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
#line 6122 "Gmsh.y"
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
#line 6141 "Gmsh.y"
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
#line 6161 "Gmsh.y"
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
#line 6181 "Gmsh.y"
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
#line 6201 "Gmsh.y"
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
#line 6224 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), (yyval.d));
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 477:
#line 6229 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), (yyval.d));
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 478:
#line 6234 "Gmsh.y"
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
#line 6244 "Gmsh.y"
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
#line 6254 "Gmsh.y"
    {
      (yyval.d) = Msg::GetValue((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 481:
#line 6259 "Gmsh.y"
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
#line 6270 "Gmsh.y"
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
#line 6279 "Gmsh.y"
    {
      (yyval.d) = strlen((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 484:
#line 6284 "Gmsh.y"
    {
      (yyval.d) = strcmp((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 485:
#line 6289 "Gmsh.y"
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
#line 6316 "Gmsh.y"
    {
      memcpy((yyval.v), (yyvsp[(1) - (1)].v), 5*sizeof(double));
    ;}
    break;

  case 487:
#line 6320 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 488:
#line 6324 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 489:
#line 6328 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] - (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 490:
#line 6332 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] + (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 491:
#line 6339 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (11)].d);  (yyval.v)[1] = (yyvsp[(4) - (11)].d);  (yyval.v)[2] = (yyvsp[(6) - (11)].d);  (yyval.v)[3] = (yyvsp[(8) - (11)].d); (yyval.v)[4] = (yyvsp[(10) - (11)].d);
    ;}
    break;

  case 492:
#line 6343 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (9)].d);  (yyval.v)[1] = (yyvsp[(4) - (9)].d);  (yyval.v)[2] = (yyvsp[(6) - (9)].d);  (yyval.v)[3] = (yyvsp[(8) - (9)].d); (yyval.v)[4] = 1.0;
    ;}
    break;

  case 493:
#line 6347 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 494:
#line 6351 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 495:
#line 6358 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].l)));
    ;}
    break;

  case 496:
#line 6363 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].l)));
    ;}
    break;

  case 497:
#line 6370 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 498:
#line 6375 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 499:
#line 6379 "Gmsh.y"
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    ;}
    break;

  case 500:
#line 6384 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 501:
#line 6388 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 502:
#line 6396 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (5)].d);
      }
    ;}
    break;

  case 503:
#line 6407 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 504:
#line 6411 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(1) - (1)].c), "*") || !strcmp((yyvsp[(1) - (1)].c), "all"))
        (yyval.l) = 0;
      else{
        yyerror("Unknown special string for list replacement");
        (yyval.l) = List_Create(2, 1, sizeof(double));
      }
    ;}
    break;

  case 505:
#line 6423 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 506:
#line 6431 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (3)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (3)].d);
      }
    ;}
    break;

  case 507:
#line 6439 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      for(double d = (yyvsp[(1) - (3)].d); ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d <= (yyvsp[(3) - (3)].d)) : (d >= (yyvsp[(3) - (3)].d));
          ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d += 1.) : (d -= 1.))
	List_Add((yyval.l), &d);
    ;}
    break;

  case 508:
#line 6446 "Gmsh.y"
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

  case 509:
#line 6456 "Gmsh.y"
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

  case 510:
#line 6485 "Gmsh.y"
    {
      (yyval.l) = GetAllElementaryEntityNumbers(0);
    ;}
    break;

  case 511:
#line 6489 "Gmsh.y"
    {
      (yyval.l) = GetAllElementaryEntityNumbers(1);
    ;}
    break;

  case 512:
#line 6493 "Gmsh.y"
    {
      (yyval.l) = GetAllElementaryEntityNumbers(2);
    ;}
    break;

  case 513:
#line 6497 "Gmsh.y"
    {
      (yyval.l) = GetAllElementaryEntityNumbers(3);
    ;}
    break;

  case 514:
#line 6501 "Gmsh.y"
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(0);
    ;}
    break;

  case 515:
#line 6505 "Gmsh.y"
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(1);
    ;}
    break;

  case 516:
#line 6509 "Gmsh.y"
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(2);
    ;}
    break;

  case 517:
#line 6513 "Gmsh.y"
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(3);
    ;}
    break;

  case 518:
#line 6517 "Gmsh.y"
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

  case 519:
#line 6546 "Gmsh.y"
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

  case 520:
#line 6575 "Gmsh.y"
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

  case 521:
#line 6604 "Gmsh.y"
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

  case 522:
#line 6634 "Gmsh.y"
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

  case 523:
#line 6647 "Gmsh.y"
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

  case 524:
#line 6660 "Gmsh.y"
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

  case 525:
#line 6673 "Gmsh.y"
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

  case 526:
#line 6685 "Gmsh.y"
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
#line 6695 "Gmsh.y"
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
#line 6705 "Gmsh.y"
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
#line 6715 "Gmsh.y"
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

  case 530:
#line 6727 "Gmsh.y"
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
#line 6740 "Gmsh.y"
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

  case 532:
#line 6752 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 533:
#line 6756 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 534:
#line 6760 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (6)].l);
    ;}
    break;

  case 535:
#line 6764 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (6)].l);
    ;}
    break;

  case 536:
#line 6768 "Gmsh.y"
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

  case 537:
#line 6786 "Gmsh.y"
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
#line 6804 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = (yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1);
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 539:
#line 6812 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = pow(10,(yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1));
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 540:
#line 6820 "Gmsh.y"
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

  case 541:
#line 6849 "Gmsh.y"
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

  case 542:
#line 6859 "Gmsh.y"
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

  case 543:
#line 6878 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 544:
#line 6883 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 545:
#line 6887 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].d)));
    ;}
    break;

  case 546:
#line 6891 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (3)].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 547:
#line 6903 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (9)].d), (int)(yyvsp[(4) - (9)].d), (int)(yyvsp[(6) - (9)].d), (int)(yyvsp[(8) - (9)].d));
    ;}
    break;

  case 548:
#line 6907 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (7)].d), (int)(yyvsp[(4) - (7)].d), (int)(yyvsp[(6) - (7)].d), 255);
    ;}
    break;

  case 549:
#line 6919 "Gmsh.y"
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

  case 550:
#line 6936 "Gmsh.y"
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(5) - (5)].c), val);
      (yyval.u) = val;
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(5) - (5)].c));
    ;}
    break;

  case 551:
#line 6946 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 552:
#line 6950 "Gmsh.y"
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

  case 553:
#line 6965 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].u)));
    ;}
    break;

  case 554:
#line 6970 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].u)));
    ;}
    break;

  case 555:
#line 6977 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 556:
#line 6981 "Gmsh.y"
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

  case 557:
#line 6994 "Gmsh.y"
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
#line 7008 "Gmsh.y"
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
#line 7022 "Gmsh.y"
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
#line 7036 "Gmsh.y"
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
#line 7050 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 562:
#line 7058 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 563:
#line 7069 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 564:
#line 7073 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 565:
#line 7077 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    ;}
    break;

  case 566:
#line 7085 "Gmsh.y"
    {
      std::string exe = Msg::GetExecutableName();
      (yyval.c) = (char *)Malloc(exe.size() + 1);
      strcpy((yyval.c), exe.c_str());
    ;}
    break;

  case 567:
#line 7091 "Gmsh.y"
    {
      std::string action = Msg::GetOnelabAction();
      (yyval.c) = (char *)Malloc(action.size() + 1);
      strcpy((yyval.c), action.c_str());
    ;}
    break;

  case 568:
#line 7097 "Gmsh.y"
    {
      const char *env = GetEnvironmentVar((yyvsp[(3) - (4)].c));
      if(!env) env = "";
      (yyval.c) = (char *)Malloc((sizeof(env) + 1) * sizeof(char));
      strcpy((yyval.c), env);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 569:
#line 7105 "Gmsh.y"
    {
      std::string s = Msg::GetString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 570:
#line 7113 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (4)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 571:
#line 7120 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 572:
#line 7128 "Gmsh.y"
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

  case 573:
#line 7143 "Gmsh.y"
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

  case 574:
#line 7157 "Gmsh.y"
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

  case 575:
#line 7171 "Gmsh.y"
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

  case 576:
#line 7183 "Gmsh.y"
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

  case 577:
#line 7199 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = toupper((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 578:
#line 7208 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = tolower((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 579:
#line 7217 "Gmsh.y"
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

  case 580:
#line 7227 "Gmsh.y"
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

  case 581:
#line 7238 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (8)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (8)].d), (int)(yyvsp[(7) - (8)].d));
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (8)].c));
    ;}
    break;

  case 582:
#line 7246 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (6)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (6)].d), std::string::npos);
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 583:
#line 7254 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 584:
#line 7258 "Gmsh.y"
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

  case 585:
#line 7277 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 586:
#line 7284 "Gmsh.y"
    {
      std::string tmp = SplitFileName(GetAbsolutePath(gmsh_yyname))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
    ;}
    break;

  case 587:
#line 7290 "Gmsh.y"
    {
      std::string tmp = SplitFileName((yyvsp[(3) - (4)].c))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 588:
#line 7297 "Gmsh.y"
    {
      std::string tmp = GetAbsolutePath((yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 589:
#line 7304 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 590:
#line 7306 "Gmsh.y"
    {
      std::string val((yyvsp[(3) - (6)].c));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.c) = (char*)Malloc((val.size() + 1) * sizeof(char));
      strcpy((yyval.c), val.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 591:
#line 7317 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].c)));
    ;}
    break;

  case 592:
#line 7322 "Gmsh.y"
    { List_Add((yyval.l), &((yyvsp[(3) - (3)].c))); ;}
    break;

  case 593:
#line 7328 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 594:
#line 7337 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char)) ;
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)) ; strcat((yyval.c), tmpstr) ;
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 595:
#line 7350 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 596:
#line 7353 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 597:
#line 7357 "Gmsh.y"
    { (yyval.c) = (yyvsp[(3) - (4)].c); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 14794 "Gmsh.tab.cpp"
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


#line 7360 "Gmsh.y"


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

