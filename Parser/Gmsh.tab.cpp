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
     tPlane = 367,
     tRuled = 368,
     tTransfinite = 369,
     tComplex = 370,
     tPhysical = 371,
     tCompound = 372,
     tPeriodic = 373,
     tUsing = 374,
     tNotUsing = 375,
     tPlugin = 376,
     tDegenerated = 377,
     tRecursive = 378,
     tRotate = 379,
     tTranslate = 380,
     tSymmetry = 381,
     tDilate = 382,
     tExtrude = 383,
     tLevelset = 384,
     tAffine = 385,
     tBooleanUnion = 386,
     tBooleanIntersection = 387,
     tBooleanDifference = 388,
     tBooleanSection = 389,
     tBooleanFragments = 390,
     tThickSolid = 391,
     tRecombine = 392,
     tSmoother = 393,
     tSplit = 394,
     tDelete = 395,
     tCoherence = 396,
     tIntersect = 397,
     tMeshAlgorithm = 398,
     tReverse = 399,
     tLayers = 400,
     tScaleLast = 401,
     tHole = 402,
     tAlias = 403,
     tAliasWithOptions = 404,
     tCopyOptions = 405,
     tQuadTriAddVerts = 406,
     tQuadTriNoNewVerts = 407,
     tQuadTriSngl = 408,
     tQuadTriDbl = 409,
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
     tHomology = 445,
     tCohomology = 446,
     tBetti = 447,
     tExists = 448,
     tFileExists = 449,
     tGMSH_MAJOR_VERSION = 450,
     tGMSH_MINOR_VERSION = 451,
     tGMSH_PATCH_VERSION = 452,
     tGmshExecutableName = 453,
     tSetPartition = 454,
     tNameToString = 455,
     tStringToName = 456,
     tAFFECTDIVIDE = 457,
     tAFFECTTIMES = 458,
     tAFFECTMINUS = 459,
     tAFFECTPLUS = 460,
     tOR = 461,
     tAND = 462,
     tNOTEQUAL = 463,
     tEQUAL = 464,
     tGREATEROREQUAL = 465,
     tLESSOREQUAL = 466,
     UNARYPREC = 467,
     tMINUSMINUS = 468,
     tPLUSPLUS = 469
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
#define tPlane 367
#define tRuled 368
#define tTransfinite 369
#define tComplex 370
#define tPhysical 371
#define tCompound 372
#define tPeriodic 373
#define tUsing 374
#define tNotUsing 375
#define tPlugin 376
#define tDegenerated 377
#define tRecursive 378
#define tRotate 379
#define tTranslate 380
#define tSymmetry 381
#define tDilate 382
#define tExtrude 383
#define tLevelset 384
#define tAffine 385
#define tBooleanUnion 386
#define tBooleanIntersection 387
#define tBooleanDifference 388
#define tBooleanSection 389
#define tBooleanFragments 390
#define tThickSolid 391
#define tRecombine 392
#define tSmoother 393
#define tSplit 394
#define tDelete 395
#define tCoherence 396
#define tIntersect 397
#define tMeshAlgorithm 398
#define tReverse 399
#define tLayers 400
#define tScaleLast 401
#define tHole 402
#define tAlias 403
#define tAliasWithOptions 404
#define tCopyOptions 405
#define tQuadTriAddVerts 406
#define tQuadTriNoNewVerts 407
#define tQuadTriSngl 408
#define tQuadTriDbl 409
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
#define tHomology 445
#define tCohomology 446
#define tBetti 447
#define tExists 448
#define tFileExists 449
#define tGMSH_MAJOR_VERSION 450
#define tGMSH_MINOR_VERSION 451
#define tGMSH_PATCH_VERSION 452
#define tGmshExecutableName 453
#define tSetPartition 454
#define tNameToString 455
#define tStringToName 456
#define tAFFECTDIVIDE 457
#define tAFFECTTIMES 458
#define tAFFECTMINUS 459
#define tAFFECTPLUS 460
#define tOR 461
#define tAND 462
#define tNOTEQUAL 463
#define tEQUAL 464
#define tGREATEROREQUAL 465
#define tLESSOREQUAL 466
#define UNARYPREC 467
#define tMINUSMINUS 468
#define tPLUSPLUS 469




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
#line 658 "Gmsh.tab.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 671 "Gmsh.tab.cpp"

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
#define YYLAST   14903

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  235
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  105
/* YYNRULES -- Number of rules.  */
#define YYNRULES  596
/* YYNRULES -- Number of states.  */
#define YYNSTATES  2231

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   469

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   220,     2,   230,     2,   219,     2,     2,
     225,   226,   217,   215,   231,   216,   229,   218,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     211,     2,   212,   206,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   227,     2,   228,   224,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   232,     2,   233,   234,     2,     2,     2,
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
     205,   207,   208,   209,   210,   213,   214,   221,   222,   223
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
    1817,  1827,  1840,  1843,  1847,  1856,  1865,  1874,  1887,  1900,
    1913,  1928,  1943,  1958,  1959,  1972,  1973,  1986,  1987,  2000,
    2001,  2018,  2019,  2036,  2037,  2054,  2055,  2074,  2075,  2094,
    2095,  2114,  2116,  2119,  2125,  2133,  2143,  2146,  2149,  2153,
    2156,  2160,  2163,  2167,  2170,  2174,  2177,  2181,  2191,  2198,
    2200,  2202,  2204,  2206,  2208,  2209,  2212,  2216,  2226,  2231,
    2246,  2247,  2251,  2252,  2254,  2255,  2258,  2259,  2262,  2263,
    2266,  2274,  2281,  2290,  2296,  2300,  2309,  2315,  2320,  2327,
    2339,  2351,  2370,  2389,  2402,  2415,  2428,  2439,  2450,  2461,
    2472,  2483,  2488,  2493,  2498,  2503,  2508,  2511,  2515,  2522,
    2524,  2526,  2528,  2531,  2537,  2545,  2556,  2558,  2562,  2565,
    2568,  2571,  2575,  2579,  2583,  2587,  2591,  2595,  2599,  2603,
    2607,  2611,  2615,  2619,  2623,  2627,  2633,  2638,  2643,  2648,
    2653,  2658,  2663,  2668,  2673,  2678,  2683,  2690,  2695,  2700,
    2705,  2710,  2715,  2720,  2725,  2732,  2739,  2746,  2751,  2753,
    2755,  2757,  2759,  2761,  2763,  2765,  2767,  2769,  2771,  2773,
    2774,  2781,  2786,  2793,  2795,  2800,  2805,  2810,  2815,  2820,
    2825,  2830,  2833,  2839,  2845,  2851,  2857,  2861,  2868,  2873,
    2881,  2888,  2895,  2902,  2907,  2914,  2919,  2921,  2924,  2927,
    2931,  2935,  2947,  2957,  2965,  2973,  2975,  2979,  2981,  2983,
    2986,  2990,  2995,  3001,  3003,  3005,  3008,  3012,  3016,  3022,
    3027,  3030,  3033,  3036,  3039,  3043,  3047,  3051,  3055,  3061,
    3067,  3073,  3079,  3096,  3113,  3130,  3147,  3149,  3151,  3153,
    3157,  3161,  3166,  3171,  3176,  3183,  3190,  3197,  3204,  3213,
    3222,  3227,  3242,  3244,  3246,  3250,  3254,  3264,  3272,  3274,
    3280,  3284,  3291,  3293,  3297,  3299,  3301,  3306,  3311,  3316,
    3321,  3325,  3332,  3334,  3339,  3341,  3343,  3345,  3350,  3357,
    3362,  3369,  3374,  3379,  3384,  3393,  3398,  3403,  3408,  3413,
    3422,  3431,  3438,  3443,  3450,  3455,  3457,  3462,  3467,  3468,
    3475,  3477,  3481,  3487,  3493,  3495,  3497
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     236,     0,    -1,   237,    -1,     1,     6,    -1,    -1,   237,
     238,    -1,   241,    -1,   240,    -1,   261,    -1,   280,    -1,
     281,    -1,   285,    -1,   286,    -1,   287,    -1,   288,    -1,
     292,    -1,   310,    -1,   311,    -1,   317,    -1,   318,    -1,
     291,    -1,   290,    -1,   289,    -1,   284,    -1,   320,    -1,
     212,    -1,   212,   212,    -1,    42,   225,   334,   226,     6,
      -1,    43,   225,   334,   226,     6,    -1,    42,   225,   334,
     226,   239,   334,     6,    -1,    42,   225,   334,   231,   330,
     226,     6,    -1,    43,   225,   334,   231,   330,   226,     6,
      -1,    42,   225,   334,   231,   330,   226,   239,   334,     6,
      -1,     4,   334,   232,   242,   233,     6,    -1,   148,     4,
     227,   321,   228,     6,    -1,   149,     4,   227,   321,   228,
       6,    -1,   150,     4,   227,   321,   231,   321,   228,     6,
      -1,    -1,   242,   245,    -1,   242,   249,    -1,   242,   252,
      -1,   242,   254,    -1,   242,   255,    -1,   321,    -1,   243,
     231,   321,    -1,   321,    -1,   244,   231,   321,    -1,    -1,
      -1,     4,   246,   225,   243,   226,   247,   232,   244,   233,
       6,    -1,   334,    -1,   248,   231,   334,    -1,    -1,   157,
     225,   321,   231,   321,   231,   321,   226,   250,   232,   248,
     233,     6,    -1,   334,    -1,   251,   231,   334,    -1,    -1,
     158,   225,   321,   231,   321,   231,   321,   231,   321,   226,
     253,   232,   251,   233,     6,    -1,   159,   232,   326,   233,
     232,   326,   233,     6,    -1,   159,   232,   326,   233,   232,
     326,   233,   232,   326,   233,   232,   326,   233,     6,    -1,
      -1,   160,   256,   232,   244,   233,     6,    -1,     7,    -1,
     205,    -1,   204,    -1,   203,    -1,   202,    -1,   223,    -1,
     222,    -1,   225,    -1,   227,    -1,   226,    -1,   228,    -1,
      78,   227,   263,   228,     6,    -1,    79,   227,   268,   228,
       6,    -1,    82,   259,   335,   231,   321,   260,     6,    -1,
      83,   259,   339,   231,   335,   260,     6,    -1,   339,   257,
     327,     6,    -1,   339,   258,     6,    -1,     4,   227,   228,
     257,   327,     6,    -1,   338,   227,   228,   257,   327,     6,
      -1,     4,   227,   321,   228,   257,   321,     6,    -1,   338,
     227,   321,   228,   257,   321,     6,    -1,     4,   227,   321,
     228,   258,     6,    -1,   338,   227,   321,   228,   258,     6,
      -1,     4,   259,   232,   330,   233,   260,   257,   327,     6,
      -1,   338,   259,   232,   330,   233,   260,   257,   327,     6,
      -1,     4,   225,   226,   257,   327,     6,    -1,   338,   225,
     226,   257,   327,     6,    -1,     4,   225,   321,   226,   257,
     321,     6,    -1,   338,   225,   321,   226,   257,   321,     6,
      -1,     4,   225,   321,   226,   258,     6,    -1,   338,   225,
     321,   226,   258,     6,    -1,   339,     7,   335,     6,    -1,
       4,   227,   228,     7,    44,   259,   260,     6,    -1,   338,
     227,   228,     7,    44,   259,   260,     6,    -1,     4,   227,
     228,     7,    44,   259,   337,   260,     6,    -1,   338,   227,
     228,     7,    44,   259,   337,   260,     6,    -1,     4,   227,
     228,   205,    44,   259,   337,   260,     6,    -1,   338,   227,
     228,   205,    44,   259,   337,   260,     6,    -1,     4,   225,
     226,     7,    44,   259,   260,     6,    -1,   338,   225,   226,
       7,    44,   259,   260,     6,    -1,     4,   225,   226,     7,
      44,   259,   337,   260,     6,    -1,   338,   225,   226,     7,
      44,   259,   337,   260,     6,    -1,     4,   225,   226,   205,
      44,   259,   337,   260,     6,    -1,   338,   225,   226,   205,
      44,   259,   337,   260,     6,    -1,     4,   229,     4,     7,
     335,     6,    -1,     4,   227,   321,   228,   229,     4,     7,
     335,     6,    -1,     4,   229,     4,   257,   321,     6,    -1,
       4,   227,   321,   228,   229,     4,   257,   321,     6,    -1,
       4,   229,     4,   258,     6,    -1,     4,   227,   321,   228,
     229,     4,   258,     6,    -1,     4,   229,   167,   229,     4,
       7,   331,     6,    -1,     4,   227,   321,   228,   229,   167,
     229,     4,     7,   331,     6,    -1,     4,   229,   168,     7,
     332,     6,    -1,     4,   227,   321,   228,   229,   168,     7,
     332,     6,    -1,     4,   178,     7,   321,     6,    -1,   178,
     227,   321,   228,     7,     4,     6,    -1,   178,   227,   321,
     228,   229,     4,     7,   321,     6,    -1,   178,   227,   321,
     228,   229,     4,     7,   335,     6,    -1,   178,   227,   321,
     228,   229,     4,     7,   232,   330,   233,     6,    -1,   178,
     227,   321,   228,   229,     4,     6,    -1,   121,   225,     4,
     226,   229,     4,     7,   321,     6,    -1,   121,   225,     4,
     226,   229,     4,     7,   335,     6,    -1,    -1,   231,    -1,
      -1,   263,   262,   339,    -1,   263,   262,   339,     7,   321,
      -1,    -1,   263,   262,   339,     7,   232,   327,   264,   270,
     233,    -1,    -1,   263,   262,   339,   227,   228,     7,   232,
     327,   265,   270,   233,    -1,    -1,   263,   262,   339,   225,
     226,     7,   232,   327,   266,   270,   233,    -1,   263,   262,
     339,     7,   335,    -1,    -1,   263,   262,   339,     7,   232,
     335,   267,   272,   233,    -1,    -1,   268,   262,   334,    -1,
     321,     7,   335,    -1,   269,   231,   321,     7,   335,    -1,
     329,     7,   339,   225,   226,    -1,    -1,   270,   271,    -1,
     231,     4,   327,    -1,   231,     4,   232,   269,   233,    -1,
     231,     4,   335,    -1,    -1,   272,   273,    -1,   231,     4,
     321,    -1,   231,     4,   335,    -1,   231,   182,   335,    -1,
     231,     4,   232,   337,   233,    -1,   321,    -1,   335,    -1,
     335,   231,   321,    -1,   321,    -1,   335,    -1,   335,   231,
     321,    -1,   321,    -1,   335,    -1,   335,   231,   321,    -1,
     321,    -1,   335,    -1,   335,   231,   321,    -1,    -1,   170,
      88,   232,   321,   233,    -1,    -1,   112,   324,    -1,   109,
     225,   334,   226,     6,    -1,    84,   225,   321,   226,     7,
     324,     6,    -1,   116,    84,   225,   274,   226,   257,   327,
       6,    -1,   102,   103,   327,     7,   321,     6,    -1,    87,
     225,   321,   226,     7,   327,     6,    -1,   122,    87,   327,
       6,    -1,    91,   225,   321,   226,     7,   327,     6,    -1,
      85,   225,   321,   226,     7,   327,   279,     6,    -1,    86,
     225,   321,   226,     7,   327,   279,     6,    -1,   162,   225,
     321,   226,     7,   327,     6,    -1,   163,   225,   321,   226,
       7,   327,     6,    -1,   164,   225,   321,   226,     7,   327,
     166,   327,   165,   321,     6,    -1,    87,     4,   225,   321,
     226,     7,   327,     6,    -1,   117,    87,   327,     6,    -1,
     117,    87,   225,   321,   226,     7,   327,     6,    -1,   116,
      87,   225,   275,   226,   257,   327,     6,    -1,   112,    90,
     225,   321,   226,     7,   327,     6,    -1,   113,    90,   225,
     321,   226,     7,   327,   278,     6,    -1,    12,    13,     6,
      -1,    13,    90,   321,     6,    -1,   104,    90,   225,   321,
     226,     7,     5,     5,     5,     6,    -1,    88,   225,   321,
     226,     7,   327,     6,    -1,    89,   225,   321,   226,     7,
     327,     6,    -1,    93,   225,   321,   226,     7,   327,     6,
      -1,    96,   225,   321,   226,     7,   327,     6,    -1,   100,
     225,   321,   226,     7,   327,     6,    -1,   101,   225,   321,
     226,     7,   327,     6,    -1,    94,   225,   321,   226,     7,
     327,     6,    -1,    95,   225,   321,   226,     7,   327,     6,
      -1,   111,   225,   321,   226,     7,   327,     6,    -1,   136,
     225,   321,   226,     7,   327,     6,    -1,    90,     4,   225,
     321,   226,     7,   327,     6,    -1,   117,    90,   327,     6,
      -1,   117,    90,   225,   321,   226,     7,   327,     6,    -1,
     117,    90,   225,   321,   226,     7,   327,     4,   232,   326,
     233,     6,    -1,   116,    90,   225,   276,   226,   257,   327,
       6,    -1,   115,    92,   225,   321,   226,     7,   327,     6,
      -1,    92,   225,   321,   226,     7,   327,     6,    -1,   110,
     225,   321,   226,     7,   327,     6,    -1,   113,   110,   225,
     321,   226,     7,   327,     6,    -1,   117,    92,   327,     6,
      -1,   117,    92,   225,   321,   226,     7,   327,     6,    -1,
     116,    92,   225,   277,   226,   257,   327,     6,    -1,   125,
     324,   232,   282,   233,    -1,   124,   232,   324,   231,   324,
     231,   321,   233,   232,   282,   233,    -1,   126,   324,   232,
     282,   233,    -1,   127,   232,   324,   231,   321,   233,   232,
     282,   233,    -1,   127,   232,   324,   231,   324,   233,   232,
     282,   233,    -1,     4,   232,   282,   233,    -1,   142,    87,
     232,   330,   233,    90,   232,   321,   233,    -1,   139,    87,
     225,   321,   226,   232,   330,   233,     6,    -1,   283,    -1,
     281,    -1,    -1,   283,   280,    -1,   283,    84,   232,   330,
     233,     6,    -1,   283,    87,   232,   330,   233,     6,    -1,
     283,    90,   232,   330,   233,     6,    -1,   283,    92,   232,
     330,   233,     6,    -1,   129,   112,   225,   321,   226,     7,
     327,     6,    -1,   129,    84,   225,   321,   226,     7,   232,
     326,   233,     6,    -1,   129,   112,   225,   321,   226,     7,
     232,   324,   231,   324,   231,   330,   233,     6,    -1,   129,
     112,   225,   321,   226,     7,   232,   324,   231,   324,   231,
     324,   231,   330,   233,     6,    -1,   129,    88,   225,   321,
     226,     7,   232,   324,   231,   330,   233,     6,    -1,   129,
      94,   225,   321,   226,     7,   232,   324,   231,   324,   231,
     330,   233,     6,    -1,   129,    95,   225,   321,   226,     7,
     232,   324,   231,   324,   231,   330,   233,     6,    -1,   129,
      97,   225,   321,   226,     7,   232,   324,   231,   324,   231,
     330,   233,     6,    -1,   129,    98,   225,   321,   226,     7,
     232,   324,   231,   324,   231,   330,   233,     6,    -1,   129,
       4,   225,   321,   226,     7,   327,     6,    -1,   129,     4,
     225,   321,   226,     7,     5,     6,    -1,   129,     4,   232,
     321,   233,     6,    -1,   140,   232,   283,   233,    -1,   140,
     178,   227,   321,   228,     6,    -1,   140,     4,   227,   321,
     228,     6,    -1,   140,   339,     6,    -1,   140,     4,     4,
       6,    -1,   167,   331,   232,   283,   233,    -1,   123,   167,
     331,   232,   283,   233,    -1,   199,   321,   232,   283,   233,
      -1,   183,     5,     6,    -1,   184,     5,     6,    -1,   183,
     232,   283,   233,    -1,   123,   183,   232,   283,   233,    -1,
     184,   232,   283,   233,    -1,   123,   184,   232,   283,   233,
      -1,     4,   335,     6,    -1,    71,   225,   337,   226,     6,
      -1,     4,     4,   227,   321,   228,   334,     6,    -1,     4,
       4,     4,   227,   321,   228,     6,    -1,     4,   321,     6,
      -1,   121,   225,     4,   226,   229,     4,     6,    -1,   161,
       4,     6,    -1,   176,     6,    -1,   177,     6,    -1,    68,
       6,    -1,    69,     6,    -1,    62,     6,    -1,    62,   232,
     321,   231,   321,   231,   321,   231,   321,   231,   321,   231,
     321,   233,     6,    -1,    63,     6,    -1,    64,     6,    -1,
      75,     6,    -1,    76,     6,    -1,   106,     6,    -1,   107,
     232,   330,   233,   232,   330,   233,   232,   326,   233,   232,
     321,   231,   321,   233,     6,    -1,   181,   225,   232,   330,
     233,   231,   335,   231,   335,   226,     6,    -1,   169,   225,
     321,     8,   321,   226,    -1,   169,   225,   321,     8,   321,
       8,   321,   226,    -1,   169,     4,   170,   232,   321,     8,
     321,   233,    -1,   169,     4,   170,   232,   321,     8,   321,
       8,   321,   233,    -1,   171,    -1,   182,     4,    -1,   182,
     335,    -1,   179,    -1,   180,   339,     6,    -1,   180,   335,
       6,    -1,   172,   225,   321,   226,    -1,   173,   225,   321,
     226,    -1,   174,    -1,   175,    -1,   128,   324,   232,   283,
     233,    -1,   128,   232,   324,   231,   324,   231,   321,   233,
     232,   283,   233,    -1,   128,   232,   324,   231,   324,   231,
     324,   231,   321,   233,   232,   283,   233,    -1,    -1,   128,
     324,   232,   283,   293,   306,   233,    -1,    -1,   128,   232,
     324,   231,   324,   231,   321,   233,   232,   283,   294,   306,
     233,    -1,    -1,   128,   232,   324,   231,   324,   231,   324,
     231,   321,   233,   232,   283,   295,   306,   233,    -1,    -1,
     128,   232,   283,   296,   306,   233,    -1,   128,   232,   283,
     233,   119,    87,   232,   327,   233,    -1,   128,   232,   321,
     233,   232,   283,   233,   120,    90,   232,   327,   233,    -1,
     110,   327,    -1,   113,   110,   327,    -1,   128,    84,   232,
     321,   231,   324,   233,     6,    -1,   128,    87,   232,   321,
     231,   324,   233,     6,    -1,   128,    90,   232,   321,   231,
     324,   233,     6,    -1,   128,    84,   232,   321,   231,   324,
     231,   324,   231,   321,   233,     6,    -1,   128,    87,   232,
     321,   231,   324,   231,   324,   231,   321,   233,     6,    -1,
     128,    90,   232,   321,   231,   324,   231,   324,   231,   321,
     233,     6,    -1,   128,    84,   232,   321,   231,   324,   231,
     324,   231,   324,   231,   321,   233,     6,    -1,   128,    87,
     232,   321,   231,   324,   231,   324,   231,   324,   231,   321,
     233,     6,    -1,   128,    90,   232,   321,   231,   324,   231,
     324,   231,   324,   231,   321,   233,     6,    -1,    -1,   128,
      84,   232,   321,   231,   324,   233,   297,   232,   306,   233,
       6,    -1,    -1,   128,    87,   232,   321,   231,   324,   233,
     298,   232,   306,   233,     6,    -1,    -1,   128,    90,   232,
     321,   231,   324,   233,   299,   232,   306,   233,     6,    -1,
      -1,   128,    84,   232,   321,   231,   324,   231,   324,   231,
     321,   233,   300,   232,   306,   233,     6,    -1,    -1,   128,
      87,   232,   321,   231,   324,   231,   324,   231,   321,   233,
     301,   232,   306,   233,     6,    -1,    -1,   128,    90,   232,
     321,   231,   324,   231,   324,   231,   321,   233,   302,   232,
     306,   233,     6,    -1,    -1,   128,    84,   232,   321,   231,
     324,   231,   324,   231,   324,   231,   321,   233,   303,   232,
     306,   233,     6,    -1,    -1,   128,    87,   232,   321,   231,
     324,   231,   324,   231,   324,   231,   321,   233,   304,   232,
     306,   233,     6,    -1,    -1,   128,    90,   232,   321,   231,
     324,   231,   324,   231,   324,   231,   321,   233,   305,   232,
     306,   233,     6,    -1,   307,    -1,   306,   307,    -1,   145,
     232,   321,   233,     6,    -1,   145,   232,   327,   231,   327,
     233,     6,    -1,   145,   232,   327,   231,   327,   231,   327,
     233,     6,    -1,   146,     6,    -1,   137,     6,    -1,   137,
     321,     6,    -1,   153,     6,    -1,   153,   155,     6,    -1,
     154,     6,    -1,   154,   155,     6,    -1,   151,     6,    -1,
     151,   155,     6,    -1,   152,     6,    -1,   152,   155,     6,
      -1,   147,   225,   321,   226,     7,   327,   119,   321,     6,
      -1,   119,     4,   227,   321,   228,     6,    -1,   131,    -1,
     132,    -1,   133,    -1,   134,    -1,   135,    -1,    -1,   140,
       6,    -1,   140,   321,     6,    -1,   308,   232,   283,   309,
     233,   232,   283,   309,   233,    -1,    99,   225,   334,   226,
      -1,   308,   225,   321,   226,     7,   232,   283,   309,   233,
     232,   283,   309,   233,     6,    -1,    -1,   119,     4,   321,
      -1,    -1,     4,    -1,    -1,     7,   327,    -1,    -1,     7,
     321,    -1,    -1,   130,   327,    -1,   114,    87,   328,     7,
     321,   312,     6,    -1,   114,    90,   328,   314,   313,     6,
      -1,   105,    90,   232,   321,   233,     7,   327,     6,    -1,
     114,    92,   328,   314,     6,    -1,   156,   328,     6,    -1,
     143,    90,   232,   330,   233,     7,   321,     6,    -1,   137,
      90,   328,   315,     6,    -1,   137,    92,   328,     6,    -1,
     138,    90,   327,     7,   321,     6,    -1,   118,    87,   232,
     330,   233,     7,   232,   330,   233,   316,     6,    -1,   118,
      90,   232,   330,   233,     7,   232,   330,   233,   316,     6,
      -1,   118,    87,   232,   330,   233,     7,   232,   330,   233,
     124,   232,   324,   231,   324,   231,   321,   233,     6,    -1,
     118,    90,   232,   330,   233,     7,   232,   330,   233,   124,
     232,   324,   231,   324,   231,   321,   233,     6,    -1,   118,
      87,   232,   330,   233,     7,   232,   330,   233,   125,   324,
       6,    -1,   118,    90,   232,   330,   233,     7,   232,   330,
     233,   125,   324,     6,    -1,   118,    90,   321,   232,   330,
     233,     7,   321,   232,   330,   233,     6,    -1,    84,   232,
     330,   233,   170,    90,   232,   321,   233,     6,    -1,    87,
     232,   330,   233,   170,    90,   232,   321,   233,     6,    -1,
      84,   232,   330,   233,   170,    92,   232,   321,   233,     6,
      -1,    87,   232,   330,   233,   170,    92,   232,   321,   233,
       6,    -1,    90,   232,   330,   233,   170,    92,   232,   321,
     233,     6,    -1,   144,    90,   328,     6,    -1,   144,    87,
     328,     6,    -1,   108,    84,   328,     6,    -1,   108,    87,
     328,     6,    -1,   108,    90,   328,     6,    -1,   141,     6,
      -1,   141,     4,     6,    -1,   141,    84,   232,   330,   233,
       6,    -1,   190,    -1,   191,    -1,   192,    -1,   319,     6,
      -1,   319,   232,   327,   233,     6,    -1,   319,   232,   327,
     231,   327,   233,     6,    -1,   319,   225,   327,   226,   232,
     327,   231,   327,   233,     6,    -1,   322,    -1,   225,   321,
     226,    -1,   216,   321,    -1,   215,   321,    -1,   220,   321,
      -1,   321,   216,   321,    -1,   321,   215,   321,    -1,   321,
     217,   321,    -1,   321,   218,   321,    -1,   321,   219,   321,
      -1,   321,   224,   321,    -1,   321,   211,   321,    -1,   321,
     212,   321,    -1,   321,   214,   321,    -1,   321,   213,   321,
      -1,   321,   210,   321,    -1,   321,   209,   321,    -1,   321,
     208,   321,    -1,   321,   207,   321,    -1,   321,   206,   321,
       8,   321,    -1,    15,   259,   321,   260,    -1,    16,   259,
     321,   260,    -1,    17,   259,   321,   260,    -1,    18,   259,
     321,   260,    -1,    19,   259,   321,   260,    -1,    20,   259,
     321,   260,    -1,    21,   259,   321,   260,    -1,    22,   259,
     321,   260,    -1,    23,   259,   321,   260,    -1,    25,   259,
     321,   260,    -1,    26,   259,   321,   231,   321,   260,    -1,
      27,   259,   321,   260,    -1,    28,   259,   321,   260,    -1,
      29,   259,   321,   260,    -1,    30,   259,   321,   260,    -1,
      31,   259,   321,   260,    -1,    32,   259,   321,   260,    -1,
      33,   259,   321,   260,    -1,    34,   259,   321,   231,   321,
     260,    -1,    35,   259,   321,   231,   321,   260,    -1,    36,
     259,   321,   231,   321,   260,    -1,    24,   259,   321,   260,
      -1,     3,    -1,     9,    -1,    14,    -1,    10,    -1,    11,
      -1,   195,    -1,   196,    -1,   197,    -1,    72,    -1,    73,
      -1,    74,    -1,    -1,    80,   259,   321,   323,   270,   260,
      -1,   189,   259,   334,   260,    -1,   189,   259,   334,   231,
     321,   260,    -1,   339,    -1,     4,   227,   321,   228,    -1,
       4,   225,   321,   226,    -1,   338,   227,   321,   228,    -1,
     338,   225,   321,   226,    -1,   193,   225,   339,   226,    -1,
     194,   225,   335,   226,    -1,   230,   339,   259,   260,    -1,
     339,   258,    -1,     4,   227,   321,   228,   258,    -1,     4,
     225,   321,   226,   258,    -1,   338,   227,   321,   228,   258,
      -1,   338,   225,   321,   226,   258,    -1,     4,   229,     4,
      -1,     4,   227,   321,   228,   229,     4,    -1,     4,   229,
       4,   258,    -1,     4,   227,   321,   228,   229,     4,   258,
      -1,   185,   225,   334,   231,   321,   226,    -1,    54,   225,
     327,   231,   327,   226,    -1,    55,   259,   334,   231,   334,
     260,    -1,    53,   259,   334,   260,    -1,    56,   259,   334,
     231,   334,   260,    -1,    61,   225,   337,   226,    -1,   325,
      -1,   216,   324,    -1,   215,   324,    -1,   324,   216,   324,
      -1,   324,   215,   324,    -1,   232,   321,   231,   321,   231,
     321,   231,   321,   231,   321,   233,    -1,   232,   321,   231,
     321,   231,   321,   231,   321,   233,    -1,   232,   321,   231,
     321,   231,   321,   233,    -1,   225,   321,   231,   321,   231,
     321,   226,    -1,   327,    -1,   326,   231,   327,    -1,   321,
      -1,   329,    -1,   232,   233,    -1,   232,   330,   233,    -1,
     216,   232,   330,   233,    -1,   321,   217,   232,   330,   233,
      -1,   327,    -1,     5,    -1,   216,   329,    -1,   321,   217,
     329,    -1,   321,     8,   321,    -1,   321,     8,   321,     8,
     321,    -1,    84,   232,   321,   233,    -1,    84,     5,    -1,
      87,     5,    -1,    90,     5,    -1,    92,     5,    -1,   116,
      84,     5,    -1,   116,    87,     5,    -1,   116,    90,     5,
      -1,   116,    92,     5,    -1,   116,    84,   232,   330,   233,
      -1,   116,    87,   232,   330,   233,    -1,   116,    90,   232,
     330,   233,    -1,   116,    92,   232,   330,   233,    -1,    84,
     170,    62,   232,   321,   231,   321,   231,   321,   231,   321,
     231,   321,   231,   321,   233,    -1,    87,   170,    62,   232,
     321,   231,   321,   231,   321,   231,   321,   231,   321,   231,
     321,   233,    -1,    90,   170,    62,   232,   321,   231,   321,
     231,   321,   231,   321,   231,   321,   231,   321,   233,    -1,
      92,   170,    62,   232,   321,   231,   321,   231,   321,   231,
     321,   231,   321,   231,   321,   233,    -1,   281,    -1,   292,
      -1,   310,    -1,     4,   259,   260,    -1,   338,   259,   260,
      -1,    37,   227,   339,   228,    -1,    37,   227,   329,   228,
      -1,    37,   225,   329,   226,    -1,    37,   227,   232,   330,
     233,   228,    -1,    37,   225,   232,   330,   233,   226,    -1,
       4,   259,   232,   330,   233,   260,    -1,   338,   259,   232,
     330,   233,   260,    -1,    38,   259,   321,   231,   321,   231,
     321,   260,    -1,    39,   259,   321,   231,   321,   231,   321,
     260,    -1,    40,   259,   334,   260,    -1,    41,   259,   321,
     231,   321,   231,   321,   231,   321,   231,   321,   231,   321,
     260,    -1,   321,    -1,   329,    -1,   330,   231,   321,    -1,
     330,   231,   329,    -1,   232,   321,   231,   321,   231,   321,
     231,   321,   233,    -1,   232,   321,   231,   321,   231,   321,
     233,    -1,   339,    -1,     4,   229,   167,   229,     4,    -1,
     232,   333,   233,    -1,     4,   227,   321,   228,   229,   168,
      -1,   331,    -1,   333,   231,   331,    -1,   335,    -1,   339,
      -1,     4,   227,   321,   228,    -1,   338,   227,   321,   228,
      -1,     4,   225,   321,   226,    -1,   338,   225,   321,   226,
      -1,     4,   229,     4,    -1,     4,   227,   321,   228,   229,
       4,    -1,     5,    -1,   200,   227,   339,   228,    -1,    65,
      -1,   198,    -1,    70,    -1,   187,   225,   334,   226,    -1,
     186,   225,   334,   231,   334,   226,    -1,   188,   259,   334,
     260,    -1,   188,   259,   334,   231,   334,   260,    -1,    46,
     259,   337,   260,    -1,    47,   225,   334,   226,    -1,    48,
     225,   334,   226,    -1,    49,   225,   334,   231,   334,   231,
     334,   226,    -1,    44,   259,   337,   260,    -1,    58,   259,
     334,   260,    -1,    59,   259,   334,   260,    -1,    60,   259,
     334,   260,    -1,    57,   259,   321,   231,   334,   231,   334,
     260,    -1,    52,   259,   334,   231,   321,   231,   321,   260,
      -1,    52,   259,   334,   231,   321,   260,    -1,    45,   259,
     334,   260,    -1,    45,   259,   334,   231,   330,   260,    -1,
      66,   259,   334,   260,    -1,    67,    -1,    51,   259,   334,
     260,    -1,    50,   259,   334,   260,    -1,    -1,    81,   259,
     335,   336,   272,   260,    -1,   334,    -1,   337,   231,   334,
      -1,     4,   234,   232,   321,   233,    -1,   338,   234,   232,
     321,   233,    -1,     4,    -1,   338,    -1,   201,   227,   334,
     228,    -1
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
    1718,  1728,  1756,  1799,  1822,  1851,  1872,  1890,  1930,  1974,
    2001,  2028,  2055,  2084,  2089,  2107,  2153,  2181,  2231,  2237,
    2243,  2250,  2292,  2318,  2342,  2366,  2391,  2414,  2441,  2469,
    2494,  2517,  2544,  2548,  2567,  2601,  2648,  2666,  2693,  2712,
    2731,  2735,  2751,  2799,  2816,  2834,  2844,  2854,  2864,  2927,
    2938,  2954,  2955,  2960,  2963,  2967,  2996,  3025,  3054,  3088,
    3110,  3136,  3158,  3181,  3202,  3258,  3282,  3307,  3333,  3446,
    3465,  3508,  3529,  3535,  3550,  3578,  3595,  3604,  3618,  3632,
    3638,  3644,  3653,  3662,  3671,  3685,  3747,  3765,  3782,  3797,
    3826,  3838,  3862,  3866,  3871,  3879,  3884,  3890,  3895,  3901,
    3909,  3913,  3917,  3922,  3982,  3998,  4015,  4032,  4054,  4076,
    4111,  4119,  4127,  4133,  4140,  4147,  4167,  4193,  4205,  4217,
    4247,  4278,  4287,  4286,  4301,  4300,  4315,  4314,  4329,  4328,
    4341,  4374,  4380,  4403,  4427,  4434,  4441,  4448,  4455,  4462,
    4469,  4476,  4483,  4491,  4490,  4504,  4503,  4517,  4516,  4530,
    4529,  4543,  4542,  4556,  4555,  4569,  4568,  4582,  4581,  4595,
    4594,  4611,  4614,  4620,  4632,  4652,  4676,  4680,  4684,  4688,
    4692,  4696,  4702,  4708,  4712,  4716,  4720,  4724,  4743,  4756,
    4757,  4758,  4759,  4760,  4764,  4765,  4766,  4769,  4803,  4829,
    4853,  4856,  4872,  4875,  4892,  4895,  4901,  4904,  4911,  4914,
    4921,  4977,  5047,  5052,  5119,  5155,  5163,  5206,  5245,  5265,
    5297,  5324,  5350,  5376,  5402,  5428,  5450,  5478,  5506,  5534,
    5562,  5590,  5629,  5668,  5689,  5710,  5737,  5741,  5751,  5786,
    5787,  5788,  5792,  5798,  5810,  5828,  5856,  5857,  5858,  5859,
    5860,  5861,  5862,  5863,  5864,  5871,  5872,  5873,  5874,  5875,
    5876,  5877,  5878,  5879,  5880,  5881,  5882,  5883,  5884,  5885,
    5886,  5887,  5888,  5889,  5890,  5891,  5892,  5893,  5894,  5895,
    5896,  5897,  5898,  5899,  5900,  5901,  5902,  5903,  5912,  5913,
    5914,  5915,  5916,  5917,  5918,  5919,  5920,  5921,  5922,  5927,
    5926,  5934,  5939,  5944,  5961,  5979,  5997,  6015,  6033,  6038,
    6044,  6059,  6078,  6098,  6118,  6138,  6161,  6166,  6171,  6181,
    6191,  6196,  6207,  6216,  6221,  6226,  6253,  6257,  6261,  6265,
    6269,  6276,  6280,  6284,  6288,  6295,  6300,  6307,  6312,  6316,
    6321,  6325,  6333,  6344,  6348,  6360,  6368,  6376,  6383,  6393,
    6422,  6426,  6430,  6434,  6438,  6442,  6446,  6450,  6454,  6483,
    6512,  6541,  6570,  6583,  6596,  6609,  6622,  6632,  6642,  6652,
    6664,  6677,  6689,  6693,  6697,  6701,  6705,  6723,  6741,  6749,
    6757,  6786,  6799,  6804,  6808,  6812,  6824,  6828,  6840,  6857,
    6867,  6871,  6886,  6891,  6898,  6902,  6915,  6929,  6943,  6957,
    6971,  6979,  6990,  6994,  6998,  7006,  7012,  7018,  7026,  7034,
    7041,  7049,  7064,  7078,  7092,  7104,  7120,  7129,  7138,  7148,
    7159,  7167,  7175,  7179,  7198,  7205,  7211,  7218,  7226,  7225,
    7238,  7243,  7249,  7258,  7271,  7274,  7278
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
  "tThruSections", "tWedge", "tPlane", "tRuled", "tTransfinite",
  "tComplex", "tPhysical", "tCompound", "tPeriodic", "tUsing", "tNotUsing",
  "tPlugin", "tDegenerated", "tRecursive", "tRotate", "tTranslate",
  "tSymmetry", "tDilate", "tExtrude", "tLevelset", "tAffine",
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
  "tGetStringValue", "tGetEnv", "tGetString", "tGetNumber", "tHomology",
  "tCohomology", "tBetti", "tExists", "tFileExists", "tGMSH_MAJOR_VERSION",
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
     455,   456,   457,   458,   459,   460,    63,   461,   462,   463,
     464,    60,    62,   465,   466,    43,    45,    42,    47,    37,
      33,   467,   468,   469,    94,    40,    41,    91,    93,    46,
      35,    44,   123,   125,   126
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   235,   236,   236,   237,   237,   238,   238,   238,   238,
     238,   238,   238,   238,   238,   238,   238,   238,   238,   238,
     238,   238,   238,   238,   238,   239,   239,   240,   240,   240,
     240,   240,   240,   241,   241,   241,   241,   242,   242,   242,
     242,   242,   242,   243,   243,   244,   244,   246,   247,   245,
     248,   248,   250,   249,   251,   251,   253,   252,   254,   254,
     256,   255,   257,   257,   257,   257,   257,   258,   258,   259,
     259,   260,   260,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   262,   262,   263,   263,   263,   264,
     263,   265,   263,   266,   263,   263,   267,   263,   268,   268,
     269,   269,   269,   270,   270,   271,   271,   271,   272,   272,
     273,   273,   273,   273,   274,   274,   274,   275,   275,   275,
     276,   276,   276,   277,   277,   277,   278,   278,   279,   279,
     280,   280,   280,   280,   280,   280,   280,   280,   280,   280,
     280,   280,   280,   280,   280,   280,   280,   280,   280,   280,
     280,   280,   280,   280,   280,   280,   280,   280,   280,   280,
     280,   280,   280,   280,   280,   280,   280,   280,   280,   280,
     280,   280,   280,   281,   281,   281,   281,   281,   281,   281,
     281,   282,   282,   283,   283,   283,   283,   283,   283,   284,
     284,   284,   284,   284,   284,   284,   284,   284,   284,   284,
     284,   285,   285,   285,   285,   285,   286,   286,   287,   288,
     288,   288,   288,   288,   288,   289,   289,   289,   289,   289,
     289,   289,   289,   289,   289,   289,   289,   289,   289,   289,
     289,   289,   289,   289,   290,   291,   291,   291,   291,   291,
     291,   291,   291,   291,   291,   291,   291,   291,   291,   292,
     292,   292,   293,   292,   294,   292,   295,   292,   296,   292,
     292,   292,   292,   292,   292,   292,   292,   292,   292,   292,
     292,   292,   292,   297,   292,   298,   292,   299,   292,   300,
     292,   301,   292,   302,   292,   303,   292,   304,   292,   305,
     292,   306,   306,   307,   307,   307,   307,   307,   307,   307,
     307,   307,   307,   307,   307,   307,   307,   307,   307,   308,
     308,   308,   308,   308,   309,   309,   309,   310,   310,   311,
     312,   312,   313,   313,   314,   314,   315,   315,   316,   316,
     317,   317,   317,   317,   317,   317,   317,   317,   317,   317,
     317,   317,   317,   317,   317,   317,   317,   317,   317,   317,
     317,   317,   317,   317,   317,   317,   318,   318,   318,   319,
     319,   319,   320,   320,   320,   320,   321,   321,   321,   321,
     321,   321,   321,   321,   321,   321,   321,   321,   321,   321,
     321,   321,   321,   321,   321,   321,   321,   321,   321,   321,
     321,   321,   321,   321,   321,   321,   321,   321,   321,   321,
     321,   321,   321,   321,   321,   321,   321,   321,   322,   322,
     322,   322,   322,   322,   322,   322,   322,   322,   322,   323,
     322,   322,   322,   322,   322,   322,   322,   322,   322,   322,
     322,   322,   322,   322,   322,   322,   322,   322,   322,   322,
     322,   322,   322,   322,   322,   322,   324,   324,   324,   324,
     324,   325,   325,   325,   325,   326,   326,   327,   327,   327,
     327,   327,   327,   328,   328,   329,   329,   329,   329,   329,
     329,   329,   329,   329,   329,   329,   329,   329,   329,   329,
     329,   329,   329,   329,   329,   329,   329,   329,   329,   329,
     329,   329,   329,   329,   329,   329,   329,   329,   329,   329,
     329,   329,   330,   330,   330,   330,   331,   331,   331,   331,
     332,   332,   333,   333,   334,   334,   334,   334,   334,   334,
     334,   334,   335,   335,   335,   335,   335,   335,   335,   335,
     335,   335,   335,   335,   335,   335,   335,   335,   335,   335,
     335,   335,   335,   335,   335,   335,   335,   335,   336,   335,
     337,   337,   338,   338,   339,   339,   339
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
       9,    12,     2,     3,     8,     8,     8,    12,    12,    12,
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
       4,    14,     1,     1,     3,     3,     9,     7,     1,     5,
       3,     6,     1,     3,     1,     1,     4,     4,     4,     4,
       3,     6,     1,     4,     1,     1,     1,     4,     6,     4,
       6,     4,     4,     4,     8,     4,     4,     4,     4,     8,
       8,     6,     4,     6,     4,     1,     4,     4,     0,     6,
       1,     3,     5,     5,     1,     1,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     2,     3,     1,   594,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   349,   350,   351,   352,   353,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   279,     0,
       0,   287,   288,     0,     0,     0,   282,     0,     0,     0,
       0,     0,   399,   400,   401,     0,     0,     5,     7,     6,
       8,     9,    10,    23,    11,    12,    13,    14,    22,    21,
      20,    15,     0,    16,    17,    18,    19,     0,    24,   595,
       0,   448,   594,   562,   449,   451,   452,   450,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   564,     0,
     585,   566,   456,   457,   458,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   453,   454,   455,   565,     0,
       0,     0,     0,    69,    70,     0,     0,   223,     0,     0,
       0,   406,     0,   554,   595,   463,     0,     0,     0,     0,
     266,     0,   268,   269,   264,   265,     0,   270,   271,   126,
     138,    69,    70,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   272,     0,
       0,     0,     0,     0,   594,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     526,   527,     0,   528,   497,   302,   498,   595,   463,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   486,     0,     0,
       0,     0,     0,   223,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   594,     0,
     223,   595,     0,     0,   396,     0,     0,     0,     0,     0,
       0,     0,     0,   504,     0,   503,     0,     0,     0,     0,
       0,   594,     0,     0,   548,     0,     0,     0,     0,   262,
     263,     0,   594,     0,     0,     0,   280,   281,     0,   223,
       0,   223,   594,     0,   595,     0,     0,   223,   402,     0,
       0,    69,    70,     0,     0,    62,    66,    65,    64,    63,
      68,    67,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     409,   408,   410,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   222,     0,   221,     0,     0,   259,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    37,   255,     0,     0,   471,   188,     0,
     594,     0,   554,   595,   555,     0,     0,   590,     0,   124,
     124,     0,     0,     0,     0,   542,   543,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    69,    70,     0,     0,     0,     0,
       0,     0,     0,     0,   510,     0,     0,   511,     0,   512,
       0,   513,     0,     0,     0,     0,     0,     0,     0,   408,
     505,     0,   499,     0,     0,     0,    69,    70,     0,     0,
       0,     0,     0,   303,     0,   364,   364,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   223,   223,     0,   488,   487,     0,
       0,     0,     0,   223,   223,     0,     0,     0,     0,     0,
       0,     0,   298,     0,     0,   223,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   366,     0,     0,     0,
       0,     0,     0,     0,   244,   397,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   374,   261,     0,     0,     0,
       0,     0,   223,     0,     0,     0,     0,     0,   284,   283,
       0,   249,     0,   250,     0,     0,     0,   223,     0,     0,
       0,     0,   354,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    78,     0,     0,     0,   476,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   459,
     588,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      62,    63,     0,   407,    62,    63,     0,     0,    62,     0,
       0,     0,     0,     0,   218,     0,     0,     0,     0,     0,
       0,   224,     0,     0,     0,   424,   423,   422,   421,   417,
     418,   420,   419,   412,   411,   413,   414,   415,   416,     0,
       0,     0,   189,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   125,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   358,     0,     0,     0,     0,     0,     0,   393,   394,
     395,     0,     0,     0,   476,    71,    72,     0,   529,     0,
       0,     0,     0,     0,   463,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   514,     0,   515,     0,   516,     0,
     517,     0,     0,   407,   500,   507,     0,   413,   506,     0,
       0,     0,   530,     0,     0,     0,     0,     0,     0,   362,
       0,     0,     0,   154,   155,     0,   157,   158,     0,   160,
     161,     0,   163,   164,     0,   183,     0,   202,     0,   210,
       0,     0,     0,     0,   175,   223,     0,     0,     0,     0,
       0,   490,   489,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   292,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   377,     0,     0,
     245,     0,     0,   241,     0,     0,     0,   392,   391,     0,
       0,     0,   407,     0,     0,     0,     0,     0,     0,     0,
       0,   285,   286,     0,     0,   251,   253,     0,   596,     0,
       0,     0,     0,     0,     0,    62,    63,     0,     0,    62,
      63,     0,     0,     0,     0,    93,    77,     0,   465,   464,
     478,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     447,   435,     0,   437,   438,   439,   440,   441,   442,   443,
       0,     0,     0,   575,     0,   582,   571,   572,   573,     0,
     587,   586,     0,   483,     0,     0,     0,     0,   576,   577,
     578,   485,   584,   143,   148,   116,     0,     0,   567,     0,
     569,     0,   461,   468,   469,   563,     0,     0,     0,    62,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     110,     0,     0,     0,     0,   470,     0,     0,     0,     0,
       0,     0,   592,     0,     0,    47,     0,     0,     0,    60,
       0,    38,    39,    40,    41,    42,   467,   466,     0,     0,
     560,    27,    25,     0,     0,     0,     0,    28,     0,     0,
     256,   591,    73,   127,    74,   139,     0,     0,     0,   544,
     545,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   170,   465,   464,     0,     0,   533,     0,
     532,   531,     0,     0,   540,     0,     0,   509,     0,     0,
       0,     0,     0,     0,     0,   501,     0,     0,     0,   467,
     466,     0,     0,     0,     0,   407,   360,   365,   363,     0,
     373,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     407,   407,   407,     0,     0,     0,     0,     0,   252,   254,
       0,     0,     0,   213,   215,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   331,   223,     0,   289,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   367,   376,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   246,     0,     0,     0,     0,     0,   248,
       0,   355,     0,     0,     0,     0,   403,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   593,     0,     0,
     473,     0,   472,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    87,     0,    91,     0,     0,    79,     0,
       0,     0,     0,    83,   106,   108,     0,     0,   552,     0,
     114,     0,     0,     0,     0,     0,     0,     0,   425,     0,
       0,     0,     0,     0,    33,   475,   474,   558,   556,    26,
       0,     0,   559,   557,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   168,   168,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   173,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   518,   519,   520,
     521,     0,   508,   502,     0,     0,     0,     0,     0,     0,
       0,   371,     0,     0,   156,     0,   159,     0,   162,     0,
     165,     0,     0,     0,     0,     0,     0,     0,   247,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   337,
       0,     0,   336,     0,   343,     0,   345,     0,   339,     0,
     341,     0,   299,   332,     0,     0,     0,     0,   240,     0,
       0,     0,     0,     0,     0,     0,     0,   378,     0,   243,
     242,   398,     0,     0,    34,    35,     0,     0,     0,     0,
     549,     0,     0,     0,   275,     0,     0,     0,   223,   356,
     223,     0,     0,     0,     0,    88,     0,    92,     0,     0,
      80,     0,    84,     0,   258,   477,   257,   436,   444,   445,
     446,   583,     0,     0,   581,   481,   482,   484,     0,     0,
     460,   144,     0,   589,   149,   480,   568,   570,   462,     0,
       0,     0,    89,     0,     0,     0,    62,     0,     0,     0,
       0,    81,     0,     0,     0,   550,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   495,     0,     0,
      29,    30,     0,    31,     0,     0,   128,   135,     0,     0,
      75,    76,   171,     0,     0,     0,     0,     0,     0,   174,
       0,     0,   191,   192,     0,     0,   176,   207,   193,   197,
     198,   194,   195,   196,     0,     0,     0,   477,   536,   535,
     534,     0,     0,     0,     0,     0,     0,     0,   208,   537,
     199,     0,   166,     0,     0,   370,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   260,     0,     0,
       0,     0,   223,   223,     0,   313,     0,   315,     0,   317,
       0,     0,   338,   497,     0,     0,   344,   346,   340,   342,
       0,     0,     0,   293,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   200,     0,     0,     0,     0,   179,
     180,     0,     0,     0,     0,   117,   121,     0,     0,   354,
     354,     0,   404,     0,     0,     0,    90,     0,     0,     0,
      82,     0,   479,     0,     0,     0,     0,     0,     0,   100,
       0,     0,    94,     0,     0,     0,     0,   111,     0,     0,
     112,     0,   553,   225,   226,   227,   228,     0,     0,     0,
      43,     0,     0,     0,     0,     0,    45,   561,     0,     0,
     129,   136,     0,     0,     0,     0,   169,   177,   178,   182,
       0,     0,   201,     0,     0,   372,     0,     0,     0,     0,
       0,     0,     0,     0,   186,     0,     0,   209,   361,   206,
     172,   185,   205,   212,   184,     0,   203,   211,     0,     0,
       0,     0,     0,     0,   494,     0,   493,     0,     0,     0,
     304,     0,     0,   305,     0,     0,   306,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   239,   238,     0,     0,
       0,     0,     0,     0,     0,     0,   229,     0,     0,   375,
      36,     0,     0,   547,     0,   277,   276,     0,     0,     0,
       0,     0,     0,     0,   101,     0,     0,    95,     0,     0,
       0,   574,   580,   579,     0,   145,   147,     0,   150,   151,
     152,   102,   104,    96,    98,   107,   109,     0,   115,     0,
      85,    48,     0,     0,     0,   496,     0,     0,     0,    32,
       0,   143,   148,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   538,   539,     0,     0,     0,     0,     0,     0,
     187,     0,   368,   368,     0,   122,   123,   223,     0,   216,
     217,     0,     0,     0,     0,     0,     0,   300,     0,   333,
       0,     0,     0,   223,     0,     0,     0,     0,     0,     0,
       0,     0,   220,   219,     0,     0,     0,     0,   118,   119,
       0,     0,   357,     0,   103,   105,    97,    99,    86,     0,
     542,   543,     0,     0,   551,     0,    44,     0,     0,     0,
      46,    61,     0,     0,     0,   133,   131,   386,   388,   387,
     389,   390,   190,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   492,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   348,     0,     0,     0,     0,   294,     0,   230,     0,
       0,     0,     0,     0,     0,     0,   546,   278,     0,     0,
     223,   405,     0,   146,     0,     0,   153,   113,     0,     0,
       0,     0,     0,   130,   137,   143,   143,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   369,   379,     0,
       0,   380,     0,   214,     0,   319,     0,     0,   321,     0,
       0,   323,     0,     0,     0,   334,     0,     0,   290,     0,
     223,     0,     0,     0,     0,     0,     0,   181,   120,   274,
     354,     0,   140,     0,     0,    52,     0,    58,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   167,   204,
       0,   383,     0,   384,   385,   491,   307,     0,     0,   314,
     308,     0,     0,   316,   309,     0,     0,   318,     0,     0,
     301,     0,   296,   233,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   134,   132,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   325,
       0,   327,     0,   329,   335,   347,   295,   291,     0,     0,
       0,     0,     0,     0,     0,     0,   141,   142,    49,     0,
      56,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   310,     0,     0,   311,     0,     0,   312,     0,
       0,   234,   235,   236,   237,     0,   231,   359,     0,    50,
       0,     0,   267,     0,   541,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   297,     0,     0,
       0,     0,     0,   273,     0,     0,     0,     0,     0,     0,
     320,     0,   322,     0,   324,     0,   232,    51,    53,     0,
      54,     0,   522,   523,   524,   525,     0,     0,     0,     0,
       0,     0,     0,    59,   381,   382,   326,   328,   330,    55,
      57
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,   107,  1103,   108,   109,   789,  1709,  1715,
    1091,  1329,  1925,  2168,  1092,  2104,  2209,  1093,  2170,  1094,
    1095,  1333,   402,   497,   209,   848,   110,   807,   509,  1851,
    2006,  2005,  1852,   510,  1919,  1295,  1511,  1296,  1514,   892,
     895,   898,   901,  1746,  1566,   771,   280,   473,   474,   113,
     114,   115,   116,   117,   118,   119,   120,   281,  1225,  2039,
    2128,   931,  1771,  1774,  1777,  2077,  2081,  2085,  2153,  2156,
    2159,  1220,  1221,   282,   981,   283,   124,  1400,  1179,   889,
     946,  1954,   125,   126,   127,   128,   284,   211,  1043,   608,
     317,  1546,   355,   356,   286,   573,   363,  1074,  1319,   507,
     502,  1044,   508,   384,   288
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1836
static const yytype_int16 yypact[] =
{
   11394,    42,    73, 11547, -1836, -1836,  4533,    17,    61,  -125,
    -102,    18,   157,   216,   287,   316,     5,   341,   375,    70,
     163,  -106,  -106,   -73,   159,   181,    15,   184,   195,    22,
     215,   222,   230,   233,   240,   246,   259,   322,   331,   393,
     453,   476,   553,   372,   310,   373,  6226,   385,   523,   -61,
     -30,   524,   764,   471,    90,   395,   536,   -77,   394,  -139,
    -139,   409,   293,   610, -1836, -1836, -1836, -1836, -1836,   438,
      89,   579,   599,    16,    50,   602,   611,   117,   715,   726,
     736,  5778,   743,   529,   563,   574,    19,    54, -1836,   578,
     584, -1836, -1836,   806,   812,   600, -1836,  3480,   618,  5655,
      30,    32, -1836, -1836, -1836, 10659,   609, -1836, -1836, -1836,
   -1836, -1836, -1836, -1836, -1836, -1836, -1836, -1836, -1836, -1836,
   -1836, -1836,   -70, -1836, -1836, -1836, -1836,    69, -1836,    96,
     199, -1836,    10, -1836, -1836, -1836, -1836, -1836,  -106,  -106,
    -106,  -106,  -106,  -106,  -106,  -106,  -106,  -106,  -106,  -106,
    -106,  -106,  -106,  -106,  -106,  -106,  -106,  -106,  -106,  -106,
    -106,  -106,  -106,   625,   635,   708,  -106,  -106,  -106,  -106,
     718,  -106,  -106,  -106,  -106,  -106,  -106,   746, -1836,  -106,
   -1836, -1836, -1836, -1836, -1836,  -106,  -106,   840,   749,   757,
     761,  -106,  -106,   805,   811, -1836, -1836, -1836, -1836,   644,
   10659, 10659, 10659,  9799, 10017,    24,    11,   411,   770,   784,
     971, -1836,   808,  1023,   276,  -110,  1044, 10659,  5231,  5231,
   -1836, 10659, -1836, -1836, -1836, -1836,  5231, -1836, -1836, -1836,
   -1836, -1836, -1836,  5879,    11, 10659,  9508, 10659, 10659,   826,
   10659,  9508, 10659, 10659,   830,  9508, 10659, 10659, 10659, 10659,
   10659, 10659,  5231, 10659, 10659,  6450,   835,   836, -1836,  9508,
    5778,  5778,  5778,  5231,   516,    99,  -106,  -106,  -106,  -106,
      31,    26,    27,    39,  6450,   962,   865,  6674, 10659,  5036,
   -1836, -1836,   847, -1836,  2087, -1836, -1836,   365,   105, 10659,
     855,   873,  6898,  5778,  5778,  5778,   893,   901,   902,   912,
     919,  7122,  7346,  7570,   852,  4453,  1141,  6450,    19,   936,
     939,  -139,  -139,  -139, 10659, 10659,  -164, -1836,   -74,  -139,
     944,   959,   977,  9284,   -72,   -50,   991,   996,   997,  1003,
    1009,  1014,  1024, 10659,  5778,  5778,  6450,  1041,     9,  1021,
   -1836,   968,  1274,  1275, -1836,  1064,  1069,  1070,  5778,  5778,
    1107,  1108,  1109, -1836, 10659, -1836,  1299,  1331, 10659, 10659,
   10659,  -138, 10659,  1106, -1836,  1169, 10659, 10659, 10659, -1836,
   -1836, 10659,  1110,  1336,  1337,  1113, -1836, -1836,  1340, -1836,
    1341, -1836,   738, 10492,   390,  5231, 10659, -1836, -1836,  6450,
    6450, 10084, 10302,  1116,  1119,  5879, -1836, -1836, -1836, -1836,
   -1836, -1836,  6450,  1343,  1129, 10659, 10659,  1356, 10659, 10659,
   10659, 10659, 10659, 10659, 10659, 10659, 10659, 10659, 10659, 10659,
   10659, 10659, 10659, 10659, 10659, 10659, 10659, 10659, 10659, 10659,
    5231,  5231,  5231,  5231,  5231,  5231,  5231,  5231,  5231,  5231,
    6450,  5231,  5231, 10659,  5231,  5231,  5231,  5231,  5231, 10659,
    5879, 10659,  5231,  5231,  5231,  5231,  5231,    11,  5879,    11,
    1138,  1138,  1138,   113, 13440,   214, 13049,   318,  1132,  1357,
    -106,  1131, -1836,  1133, 11737, 10659,  9508, -1836, 10659, 10659,
   10659, 10659, 10659, 10659, 10659, 10659, 10659, 10659, 10659, 10659,
   10659, 10659, 10659, -1836, -1836, 10659, 10659, -1836, -1836,  1076,
     756,  -116, -1836,   432, -1836,   179, 11103, -1836,   308,   -95,
       1,  1134,  1136, 13461,  9508,  3373, -1836,   283, 13482, 13503,
   10659, 13524,   427, 13545, 13566, 10659,   558, 13587, 13608, 13629,
   13650, 13671, 13692,  1142, 13713, 13734,  1362, 10659, 10659,   593,
    1364,  1366,  1367,  1148, 10659, 10659,  1372,   235,  7794,  8018,
   10659, 10659,  5231, 10659, -1836,  1315, 10659, -1836,  1316, -1836,
    1317, -1836,  1318,  6450,    37,    40,    41,    45,  9508,  1138,
   -1836, 13755, -1836,   626, 10659,  8242, 10659, 10659,   298, 13776,
   10659, 10659, 10659, -1836,  1374,  1379,  1379, 10659,  9726,  9726,
    9726,  9726, 10659,  1382, 10659,  1390, 10659,  1391,  9508,  9508,
   10534,  1161,  1392,  1173, -1836, -1836,  -150, -1836, -1836, 11235,
   11671,  -139,  -139,   411,   411,   -67, 10659, 10659, 10659,  9284,
    9284, 10659,  1981,  3014,   -62, -1836, 10659, 10659, 10659, 10659,
   10659, 10659, 10659, 10659, 10659, 13797,  1419,  1421,  1423, 10659,
    1425, 10659, 10659,  3031, -1836, -1836,  9508,  9508,  9508,  1426,
    1430, 10659, 10659, 10659, 13818, -1836, -1836, 13839, 13860, 13881,
    1270, 11697, -1836,  1206,  3958, 13902, 13923, 13072, -1836, -1836,
    9508, -1836,  3302, -1836,  3676, 10659, 10659, -1836, 10659, 10659,
    1215, 13944, 11680,  1219,   630,   221, 13965,   378, 13095, 10659,
    9508,  1440,  1441, -1836, 10659, 13986, 13118,     2, 11205, 11205,
   11205, 11205, 11205, 11205, 11205, 11205, 11205, 11205, 11205, 11723,
   11205, 11205, 11205, 11205, 11205, 11205, 11205, 11749, 11775, 11801,
     262,   511,   262,  1222,  1223,  1220,   641,   641,  1239,   641,
    1241,  1242,  1244, 11827,   641,   641,   641,   425,   641, 14679,
   -1836,  1205,  1245,  1246,  1224,   569,   747,  1227,  1228,  1251,
    1434,  1438,  6450,   366,  1439,  1443,  6450,   166,  5879, 10659,
    1478,  1486,    23,   641, -1836,   128,    21,    29,   142,  1266,
     -43, -1836,  4490,   646,  3978,  1668,  1701,   795,   795,   -31,
     -31,   -31,   -31,   367,   367,  1138,  1138,  1138,  1138,     8,
   14007, 13141, -1836, 10659, 10659,  1488,    58,  9508, 10659, 10659,
    1490,  9508, 10659,  1491,  5231,  1492, -1836,    11,  1495,  5231,
   10659,  5879,  1496,  9508,  9508,  1323,  1497,  1499, 14028,  1500,
    1324,  1506,  1508, 14049,  1352,  1522,  1530,  1533,  1534,  1535,
    1536, -1836,  1537,  1538, 10659, 14070,  5275,  1314, -1836, -1836,
   -1836,  1541, 14091, 13164,   105, -1836, -1836,  9508, -1836,  9508,
    3373,  1322,  9508,  1344,   692, 11853, 11879,   641, 11905,  1319,
    5939,  1342,  1345,  1346, -1836,  9508, -1836,  9508, -1836,  9508,
   -1836,  9508,   661,  1543, -1836,  4043,  9508,  1138, -1836, 14112,
   13187,  9508, -1836,  1561, 14133, 14154, 14175, 10659,  6450,  1565,
    1567, 14196,  1350, 14679,  1348,  1358, 14679,  1351,  1361, 14679,
    1359,  1363, 14679,  1360, 14217, -1836, 14238, -1836, 14259, -1836,
     723,   733,  9508,  1354, -1836, -1836, 10806, 10845,  -139, 10659,
   10659, -1836, -1836,  1376,  1377,  9284, 11931, 11957, 11983,  4235,
    1473,   765,  1368,  -139, 10901, 14280,  6163, 14301, 14322, 14343,
   14364, 14385, 14406, 14427,  1586, 10659,  1588, -1836, 10659, 14448,
   -1836, 13210, 13233, -1836,   768,   791,   804, -1836, -1836, 13256,
   13279, 12009, -1836,  1592,  1600,  1606,  1386, 10659, 10940, 10659,
   10659, -1836, -1836,    46,   810, -1836, -1836, 11035, -1836,  1609,
   10374,  1384,  1387,  6450,  1616,  1579,  1581,  6450,   366,  1582,
    1585,  6450,   366,  6387,   816, -1836, -1836, 13302,    97,    80,
   -1836, -1836, -1836, -1836, -1836, -1836, -1836, -1836, -1836, -1836,
   -1836, -1836, 10659, -1836, -1836, -1836, -1836, -1836, -1836, -1836,
   10659, 10659, 10659, -1836,  9508, -1836, -1836, -1836, -1836,  5231,
   -1836, -1836, 10659, -1836,  6450,  5231,  5231,  5231, -1836, -1836,
   -1836, -1836, -1836, -1836, -1836, -1836, 10659,  5231, -1836,  5231,
   -1836, 10659, -1836, -1836, -1836, -1836,  -106,  -106,  1625, -1836,
   10659,  1629,  -106,  -106,  1630,    51, 10659,  1631,  1636,  1250,
   -1836,  1637,  1418,    19,  1641, -1836,  9508,  9508,  9508,  9508,
   10659,  1428, -1836,   641, 10659, -1836,  1432,  1445,  1416, -1836,
    1644, -1836, -1836, -1836, -1836, -1836,   237,   272, 14469, 13325,
   -1836, -1836,  1447,  5231,   545, 14490, 13348, -1836,   660, 12035,
   -1836, -1836, -1836,    81, -1836, -1836, 11205,   641,  -139,  3373,
   -1836,   964,  6450,  6450,  1657,  6450,   969,  6450,  6450,  1658,
    1559,  6450,  6450,  6450,  6450,  6450,  6450,  6450,  6450,  1646,
    1659,  1666,  9508, -1836,   105,   473,   833,   834, -1836,   838,
   -1836, -1836, 10659, 10659, -1836, 10659, 10659, -1836, 10659, 10659,
   10659,   854,   859,   863,   864, -1836,  6450, 10659,   868,   105,
     105,   871,  6450,  1667,  1669,  1670,  4188, -1836, -1836,  1674,
   -1836,  1675,   404, 10659,   404, 10659,   404, 10659,   404, 10659,
    1678,  1679,  1680,  1681,  1682,   872,  1671, 11074, -1836, -1836,
     -59, 12061, 12087, -1836, -1836,  6611,   -98,  -139,  -139,  -139,
    1594,  1697, 10592,  1471,  1698,  1480,    28,    34,    35,    53,
     329, -1836, -1836,   -17, -1836,   765,  1699,  1702,  1704,  1706,
    1707,  1709,  1710,  1711,  1712,  6450, 14679, -1836,  1767,  1477,
    1715,  1728,  1729,  1647,  1731,  1730,  1733, 10659,  6450,  6450,
    6450,  1736, 12113, -1836,  4149,   940,  1737,  1739,  1516, -1836,
    1518, -1836,  1801,  1519,  6450,  1520, -1836,  -106,  -106,  1746,
   10659,  1748,  -106,  -106,  1749, 10659,  1750, -1836,   641,  1751,
   -1836,  1754, -1836,  1758, 11205, 11205, 11205, 11205,   763,  1539,
   10882,  1540,   641,   641,  1544,   769,   797, 14511,  1545,   641,
   11205,   291,  5231, -1836,  1965, -1836,   291,  5231, -1836,   371,
    1547,  1762,  1984, -1836, -1836, -1836,    19, 10659, -1836,   876,
   -1836,   880,   881,   884,   890, 14532, 10659,   404, 14679,  1549,
   10659, 10659,  6450,  1548, -1836, -1836, -1836, -1836,  1550, -1836,
    1759,    76, -1836, -1836,  1766, 10659,  8914,  1551,  1554,  1777,
    1778,    68,  1553,  1556,  1677,  1677,  6450,  1780,  1558,  1560,
    1787,  1788,  6450,  1563,  1790,  1791,  1792,  1793,  1796,  1797,
    1799,  1800, -1836,  1803,  6450,   905,  1805,   641,  1584,  1589,
   12139, 12165, 12191, 12217, 12243, 12269, 12295, -1836, -1836, -1836,
   -1836,  1806, 14679, -1836,   641,  1810,  6450,  6450,  6450,  1814,
    1813, -1836,  6450,  6450, 14679,  6450, 14679,  6450, 14679,  6450,
   14679,  6450,  6450,  6450,  1591,  1593,  1819,   571, -1836, 10659,
   10659, 10659,  1595,  1596,  -144,  -136,  -117,  1597,  1603, -1836,
    2163,  6450, -1836, 10659, -1836,  1826, -1836,  1827, -1836,  1829,
   -1836,  1830, -1836, -1836, 11130,  9284,   632,  6002, -1836,  1605,
    1607,  1608,  1610,  1612,  1613,  8466,  1832, -1836,  9508, -1836,
   -1836, -1836,  1614, 10659, -1836, -1836, 13371,  1835,  1841,  1654,
   -1836, 10659, 10659, 10659, -1836,  1842,   686,  5879, -1836, -1836,
   -1836,  1618,  1860,   291,  5231, -1836,  2279, -1836,   291,  5231,
   -1836,  2478, -1836,   404, -1836,   332, -1836, -1836, -1836, -1836,
   -1836, -1836,  5231, 10659, -1836, -1836, -1836, -1836,  5231,  1863,
   -1836, -1836,    13, -1836, -1836, -1836, -1836, -1836, -1836,  1866,
     262,   262, -1836,  1867,   262,   262,  5879, 10659,  1868,  1865,
      23, -1836,  1883, 13394,    19, -1836,  1884,  1885,  1888,  1889,
    1543, 14553,  6450, 10659, 12321, 12347,   909, -1836, 10659,  1892,
   -1836, -1836,  5231, -1836, 12373,  5317, 14679, -1836,  1890,  1893,
   -1836, -1836, -1836, 10659, 10659,  -139,  1895,  1898,  1899, -1836,
   10659, 10659, -1836, -1836,  1900, 10659, -1836, -1836, -1836, -1836,
   -1836, -1836, -1836, -1836,  1902,  1915,  1690,   105, -1836, -1836,
   -1836, 10659, 10659, 10659, 10659, 10659, 10659, 10659, -1836, -1836,
   -1836,  1917,  1757,  1923, 10659, -1836,  1924,  1925,  1926,  1927,
    1928,  1929,  1137,  1930,  9508,  9508, 10659, -1836,  9726,  6835,
   14574,  4706,   411,   411,  -139,  1931,  -139,  1932,  -139,  1933,
    6450, 10659, -1836,   464,  1714, 14595, -1836, -1836, -1836, -1836,
    1828,  7059,    -5, -1836,  1940,  1941,  6450,  -139,  -139,  -139,
    -139,  -139,  4769,  1943, -1836,   934, 10659,  2584,  1945, -1836,
   -1836,  6450,  4797,   549, 14616, -1836, -1836,  8987,  1721, 11680,
   11680,  6450, -1836,  1947,   262,   262, -1836,  1948,   262,   262,
   -1836,  6450, -1836,  1732, 11205,   641,  5554,  9211,  5879, -1836,
    1949,  1950, -1836,  1951,  1953,  1954,  2712, -1836,  1956,  1958,
   -1836,  1738, -1836, -1836, -1836, -1836, -1836,  1670,  1959,   682,
   14679, 10659, 10659,  6450,  1734,   942, 14679, -1836,  1962, 10659,
   -1836, -1836,  1755,  1756,  7283,  7507,   777, -1836, -1836, -1836,
    7731,  7955, -1836,  8179,  1991, -1836,  6450, 11205, 11205, 12399,
   12425, 12451, 12477, 12503, -1836,  1882,  1983, -1836, 14679, -1836,
   -1836, -1836, -1836, -1836, -1836,  1765, -1836, -1836,   963,   966,
   10617,  2752,  1992,  1768, -1836, 10659, -1836,  1769,  1770,   148,
   -1836,  1772,   177, -1836,  1773,   271, -1836,  1789,  1794, 13417,
    1995,  6450,  2015,  1934,  1798, 10659, -1836, -1836,   967,   284,
     313,   317,   336,   403,  8690,   406, -1836,  2017,  8403, -1836,
   -1836,  1861, 10659, -1836, 10659, -1836, -1836,  9508,  2774,  2022,
    5879,  1802,  1804,  1811, -1836,  2023,  2025, -1836,  2026,  2027,
    2028, -1836, -1836, -1836,  5036, -1836, -1836,  5231, 14679, -1836,
   -1836, -1836, -1836, -1836, -1836, -1836, -1836,    19, -1836,  1870,
   -1836, -1836, 10659, 12529, 12555, -1836,  6450, 10659,  2039, -1836,
   12581, -1836, -1836,  6450,  6450,  2040,  2041,  2042,  2043,  2044,
    2045,   970, -1836, -1836, 10659, 10659, 10659, 10659, 10659,  1820,
   -1836,  6450,   382,   817,  9508, -1836, -1836,   411,  4973, -1836,
   -1836,  9284,   765,  9284,   765,  9284,   765, -1836,  2047, -1836,
     974,  6450,  1822, -1836,  8627,  2050,  9508,  -139,  -139,  -139,
    -139,  -139, -1836, -1836, 10659,  8863,  8944,   975, -1836, -1836,
    1831,  1846, -1836,  2053, -1836, -1836, -1836, -1836, -1836,   981,
    1347,  2054,   982,  2057, -1836,  1847, 14679, 10659, 10659,  1004,
   14679, -1836, 10659,  1007,  1011, -1836, -1836, -1836, -1836, -1836,
   -1836, -1836, -1836,  1848, 12607, 12633, 12659, 12685, 12711, 10659,
    1022,  1852,  -139,  6450,  2058,  1854,  -139,  2081,  1026,  1855,
   10659, -1836,  9117,   437,   668,  9159,   469,   688,  9238,   475,
    1073, -1836,  6450,  2093,  1982,  6450, 11169,  1872, -1836,  1027,
     513,   559,   565,   577,   601,  2805, -1836, -1836,  2094,  2096,
   -1836, -1836, 10659, -1836,  5879,    11, -1836, -1836, 10659, 14637,
   12737,    33, 12763, -1836, -1836, -1836, -1836, 10659, 10659, 10659,
   10659, 10659, 10659,  9445,  2099,  -139,    95, -1836, -1836,  -139,
      98, -1836,  2101, -1836,  9632,  2102, 10659,  2103,  2104, 10659,
    2105,  2106, 10659,  2108,  1886, -1836, 10659,  1887, -1836,   765,
   -1836,  2109,  9508,  9508,  9508,  9508,  8690, -1836, -1836, -1836,
   11680,  3299, -1836,  1896,  1034, -1836, 10659, -1836,  6450, 10659,
    1042,  1043, 12789, 12815, 12841, 12867, 12893, 12919, -1836, -1836,
     614, -1836,   622, -1836, -1836, -1836, -1836,  1891,  9674, -1836,
   -1836,  1894,  9752, -1836, -1836,  1897,  9850, -1836,  2112,  3122,
   -1836,  1117, 11264, -1836,  1046,  1078,  1079,  1086,   667,  1087,
    1901,  5879,  1834,  2116,  1905, 14658,  1090,  9917, -1836, -1836,
   10659, 10659, 10659, 10659, 10659, 10659,  -139,  -139,   765,  2118,
     765,  2119,   765,  2121, -1836, -1836, -1836, -1836,   765,  2122,
    2125,  2126,  2127,  9508,  2132,  2133, -1836, -1836, -1836,  5231,
   -1836,  1908,  2135,  9959, 11205, 12945, 12971, 12997, 13023,   672,
     674,  1238, -1836,  1910,  1288, -1836,  1914,  1381, -1836,  1916,
    1451, -1836, -1836, -1836, -1836,  1091, -1836, -1836,  1094, -1836,
    1918,  6450, -1836,  2141, -1836, 10659, 10659, 10659, 10659, 10659,
   10659,  2143,   765,  2145,   765,  2146,   765, -1836,  2147,  5231,
    2148,  5231,  1099, -1836, 10042, 10135, 10207, 10249, 10327, 10425,
   -1836,  1487, -1836,  1509, -1836,  1578, -1836, -1836, -1836,  1100,
   -1836,  2149, -1836, -1836, -1836, -1836,  2150,  2151,  2152,  2155,
    2156,  5231,  2157, -1836, -1836, -1836, -1836, -1836, -1836, -1836,
   -1836
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1836, -1836, -1836, -1836,   823, -1836, -1836, -1836, -1836,   167,
   -1836, -1836, -1836, -1836, -1836, -1836, -1836, -1836, -1836, -1836,
   -1836, -1836,  -289,   -92,  2593,   224, -1836,  1656, -1836, -1836,
   -1836, -1836, -1836, -1836, -1836, -1835, -1836,   315, -1836, -1836,
   -1836, -1836, -1836, -1836,   815,  2182,    -2,  -605,  -318, -1836,
   -1836, -1836, -1836, -1836, -1836, -1836, -1836,  2184, -1836, -1836,
   -1836, -1836, -1836, -1836, -1836, -1836, -1836, -1836, -1836, -1836,
   -1836, -1012, -1112,  2201, -1659,  2202, -1836, -1836, -1836,  1620,
   -1836,   334, -1836, -1836, -1836, -1836,  2030, -1836, -1836,    43,
   -1836, -1644,  2980,  1466,  3434,  2287,  -301,   679, -1836,   194,
      12, -1836,  -426,    -3,   279
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -562
static const yytype_int16 yytable[] =
{
     129,   112,  1788,   214,   720,   622,   722,   603,   923,   924,
    1811,  1812,  1085,   640,   404,   372,  1933,  1687,   213,   239,
     338,   737,   643,   361,   220,   239,   244,  1072,   467,   291,
     216,   557,   559,   244,  1434,   378,   554,   380,   403,  2057,
    1436,  1438,   864,   287,   561,   866,   868,   291,     4,   292,
     870,   611,   612,  1256,   343,  1309,   344,   293,   365,  1440,
     294,   672,   295,   674,  1101,   611,   612,  1081,   613,   682,
     341,   611,   612,     5,  1562,   388,   312,   313,   287,   611,
     612,   918,  1551,   341,   500,   133,   314,  1624,  1346,  1625,
     308,   660,  1861,   315,   341,  1626,   208,  1627,   611,   612,
     218,  2071,   316,   318,  2073,   324,   309,   310,  1443,   373,
     796,   377,   400,   401,  1628,   797,  1629,   611,   612,   231,
     750,   232,  -555,   219,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   805,   345,  1423,   806,   173,   174,   175,
     176,   611,   612,   611,   612,   178,   179,   180,   611,   612,
     181,   217,   235,   611,   612,   386,   611,   612,   614,   236,
     625,   186,   387,   222,   925,  1086,  1087,  1088,  1089,   933,
    2060,  2061,  1419,  1059,   752,   626,   756,   304,   759,   334,
     305,   335,   627,  1435,   487,   488,   489,   490,   491,  1437,
    1439,   468,   469,   492,   339,  1688,   558,   560,   611,   612,
     212,   555,  1929,   341,   348,   472,   395,   349,  1441,   562,
     611,   612,   106,  1446,  1445,   503,   503,   106,  1310,  1311,
     106,   754,   223,   503,   400,   401,  1785,  1950,   985,   808,
     226,   341,   806,   287,  -560,   405,   641,   406,   287,   407,
     240,  1090,   287,   208,   208,   511,   240,   241,   340,   503,
     221,   362,   287,  1077,   245,  1073,   287,   287,   287,   287,
     503,  1078,   379,   556,   381,  2058,   189,   190,   191,   865,
    1102,   287,   867,   869,   287,  1257,   287,   871,   198,   366,
     199,   106,   130,   611,   612,   215,   916,   917,  1102,   287,
     287,   287,   287,   224,   389,   500,   133,   229,   287,   287,
     287,   390,   400,   401,   287,   341,  1347,   934,  1348,  1281,
     611,   612,  -556,   611,   612,   396,   397,   398,   751,   400,
     401,   391,   225,   392,   548,   758,   549,   400,   401,  -558,
     393,   287,   287,   287,  1443,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   968,   287,   287,   227,   173,   174,
     175,   176,   342,   235,   606,   607,   178,   179,   180,   977,
    1076,   181,   615,   611,   612,   364,   624,   247,   396,   397,
     398,   399,   186,  1059,  1079,   760,   374,   320,  1526,  1881,
     321,   228,   503,   322,   237,   989,   287,   287,   400,   401,
     230,  2100,   611,   612,   260,  1065,   987,   261,   991,   287,
     262,   396,   397,   398,   399,   800,   238,   691,  1883,   242,
     801,  1059,   501,   505,  2106,   471,   396,   397,   398,   755,
     243,   400,   401,   396,   397,   398,   986,   503,   503,   503,
     503,   503,   503,   503,   503,   503,   503,   287,   503,   503,
     246,   503,   503,   503,   503,   503,   533,   247,  1211,   503,
     503,   503,   503,   503,   341,   248,   341,   543,   249,   400,
     401,   845,   740,   846,  1060,   250,  1212,   847,  1066,  -559,
     748,   251,   574,   287,  1213,  1214,  1215,   189,   190,   191,
    1216,  1217,  1218,  1219,   252,   470,   611,   612,   845,   198,
     846,   199,   106,   804,   400,   401,   255,   504,   504,   611,
     612,   495,  1885,   496,  -557,   504,  1951,  1952,   312,   313,
     393,   287,  1953,   512,   814,  1896,   815,   845,   314,   846,
     396,   397,   398,   399,   845,   323,   846,  2192,   611,   612,
     881,   504,   611,   612,   803,    58,    59,    60,    61,   804,
     400,   401,   504,   256,  1897,   287,   287,   253,  1898,   503,
      72,   611,   612,    75,   400,   401,   254,  1804,   301,   258,
     287,   302,  1442,   303,  -561,   287,   257,  1899,   396,   397,
     398,   399,   287,   396,   397,   398,   399,  1617,  1618,   680,
     396,   397,   398,   990,   489,   490,   491,   364,   400,   401,
     576,   492,   577,   400,   401,   287,   287,  1197,   263,   393,
     894,   897,   900,   903,   259,  1000,   396,   397,   398,   399,
     289,   472,   472,   290,   325,   678,   296,   679,   611,   612,
     306,   611,   612,   307,   393,   721,   311,   723,   724,   725,
     726,   727,   728,   729,  1900,   731,   732,  1901,   734,   735,
     736,   319,   738,   287,   287,   287,   742,   743,   744,   745,
     746,  1041,   611,   612,   921,   922,   804,   798,   814,   799,
     820,  1061,   607,   333,   504,  1067,   393,   287,  2026,   336,
     478,   479,   480,   481,   482,   483,   484,   485,   486,   487,
     488,   575,   490,   491,   611,   612,   337,   287,   492,   346,
     611,   612,  1666,  1667,   326,   400,   401,  1780,   327,  1270,
    2029,   347,  1376,  1275,   328,   329,  2032,   330,   331,   504,
     504,   504,   504,   504,   504,   504,   504,   504,   504,   350,
     504,   504,   332,   504,   504,   504,   504,   504,   611,   612,
     351,   504,   504,   504,   504,   504,   747,   845,   749,   846,
     352,   544,  1024,   545,  2042,   546,   857,   357,   207,   287,
     208,  1211,  1000,   287,   358,   478,   479,   480,   481,   482,
     483,   484,   485,   486,   487,   488,   489,   490,   491,  1212,
    1068,  1341,  1318,   492,   611,   612,   814,  1213,  1214,  1215,
     611,   612,  1805,  1216,  1217,  1218,  1219,  1211,   359,   814,
    2043,   824,   611,   612,   287,   845,  2044,   846,   287,   360,
    1049,   503,   882,   367,   341,  1212,   503,  1211,  2045,   368,
     287,   287,   369,  1213,  1214,  1215,   611,   612,   370,  1216,
    1217,  1218,  1219,  1117,   814,  1212,   837,   371,   854,   611,
     612,   504,  2046,  1213,  1214,  1215,   385,   611,   612,  1216,
    1217,  1218,  1219,   375,   287,  2116,   287,   451,   297,   287,
     433,   298,  1443,  2117,   299,  1443,   300,   814,  1443,   874,
     434,   983,   287,   984,   287,  1643,   287,   845,   287,   846,
    1964,   459,  1967,   287,  1970,  1520,  1521,   814,   287,  1083,
    1524,  1525,   611,   612,  1211,   287,  1344,   611,   612,   611,
     612,   814,   814,  1403,  1165,  1405,  1271,  1407,  2133,  1409,
    1276,  2027,  1212,  2179,  1444,  2180,  1280,  1282,  1841,   287,
    1213,  1214,  1215,  1842,   400,   401,  1216,  1217,  1218,  1219,
    1151,  2030,  1001,  1002,  1003,  1004,  1005,  1006,  1007,  1008,
    1009,  1010,  1011,   435,  1013,  1014,  1015,  1016,  1017,  1018,
    1019,  1955,  1956,   440,  1023,  1025,  1026,  1953,  1473,   564,
    1030,  1031,   565,  1033,   814,   566,  1193,   567,  1038,  1039,
    1040,  1200,  1042,   675,   814,   676,  1194,   546,  1206,  1050,
    1052,   447,   208,   845,   452,   846,  1223,   477,  1051,  1443,
     287,   793,   453,   794,   287,   795,   454,  1075,   287,   845,
     208,   846,   611,   612,   814,   845,   503,   846,  1111,   814,
    1509,  1242,   475,  1115,  1335,  1336,   483,   484,   485,   486,
     487,   488,   489,   490,   491,  1532,   476,  1767,  1768,   492,
    1527,   287,   814,   845,  1243,   846,   503,  2091,  1512,   494,
     457,   287,   503,   503,   503,   814,   458,  1244,  1542,  1443,
     493,   814,  1443,  1258,   503,  1443,   503,   814,  1443,  1278,
     498,   520,  1280,  1282,  1352,   525,  1353,  1674,  1675,  1358,
     537,  1359,  1678,  1679,   814,   814,  1377,  1378,   538,   814,
     341,  1379,   563,   287,   287,   287,   287,  1335,  1336,   387,
     580,  1154,   792,   504,   598,   814,  1113,  1387,   504,  1443,
     814,  1443,  1388,  1443,   814,   814,  1389,  1390,   581,   814,
     503,  1393,   814,   814,  1394,  1416,  2151,  1534,  2154,  1535,
    2157,   814,   814,  1536,  1537,   814,  2160,  1538,   587,   287,
     287,   814,   287,  1539,   287,   287,   588,   589,   287,   287,
     287,   287,   287,   287,   287,   287,   814,   590,  1586,   287,
    1713,  1755,  1714,  1756,   591,   601,   478,   479,   480,   481,
     482,   483,   484,   485,   486,   487,   488,   489,   490,   491,
    1669,  1351,  1670,   287,   492,   814,  1474,  1797,   604,   287,
    2201,   605,  2203,  1847,  2205,  1848,   616,   478,   479,   480,
     481,   482,   483,   484,   485,   486,   487,   488,   489,   490,
     491,   617,  1211,  1283,   814,   492,  1872,   814,  1713,  1873,
    1895,  1713,   393,  1943,  1681,  1972,   814,  1973,  1988,   618,
    1212,  1045,  1992,   804,  1993,  1996,   628,  1528,  1213,  1214,
    1215,   629,   630,  1289,  1216,  1217,  1218,  1219,   631,  1292,
    1293,  1294,   287,  1702,   632,  1713,  1211,  2001,  1509,   633,
    2003,  1298,  1512,  1299,  2004,   287,   287,   287,   642,   634,
    1424,  1425,  1426,  1713,  1212,  2014,  1315,   814,   814,  2022,
    2041,   287,  1213,  1214,  1215,  1847,   639,  2103,  1216,  1217,
    1218,  1219,  1959,  1509,  1509,  2108,  2109,   814,   504,  2129,
     644,   645,   478,   479,   480,   481,   482,   483,   484,   485,
     486,   487,   488,   489,   490,   491,   646,  1340,   503,   503,
     492,   647,   648,   503,   503,   655,  2033,  1327,   504,   814,
     814,  2130,  2131,   341,   504,   504,   504,   814,   814,  2132,
    2134,  1713,   814,  2141,  2188,  2189,   504,  2190,   504,   287,
    1713,  2221,  2211,  2222,   651,   652,   653,   656,   662,   663,
    1349,  1350,   668,   669,   208,   670,   671,   673,   689,   693,
    2126,   690,   364,   287,  1994,   574,   694,  1211,  1557,   287,
     697,   761,   492,   207,   762,   810,   764,   811,   831,   834,
     838,   287,   839,   840,   841,  1212,   844,   859,   861,   862,
     863,   887,   504,  1213,  1214,  1215,   888,   913,   905,  1216,
    1217,  1218,  1219,   287,   287,   287,   907,   909,   914,   287,
     287,  1922,   287,  1682,   287,   915,   287,  1211,   287,   287,
     287,   478,   479,   480,   481,   482,   483,   484,   485,   486,
     487,   488,   489,   490,   491,  1212,   945,   947,   287,   492,
     948,   950,   957,  1213,  1214,  1215,   958,   966,   969,  1216,
    1217,  1218,  1219,   978,   287,   982,   995,   996,  1027,  1028,
    1048,  1029,   287,  1053,  1054,   287,   478,   479,   480,   481,
     482,   483,   484,   485,   486,   487,   488,   489,   490,   491,
    1032,  2181,  1034,  1035,   492,  1036,  1046,  1047,  1056,  1055,
     503,   503,  1057,  1062,  1070,   503,   503,  1063,  1642,  1668,
    1071,  1080,  1100,  1121,  1126,  1682,  1107,  1110,  1112,   503,
    1211,  1114,  1493,  1118,  1122,   503,  1123,  1125,  1497,  1498,
    1499,  1500,  1501,  1127,  1504,  1128,  1506,  1507,  1212,  1510,
    1513,  2183,  1130,  1517,  1518,  1519,  1213,  1214,  1215,  1131,
    1523,   341,  1216,  1217,  1218,  1219,  1923,  1132,  1695,   287,
    1133,  1134,  1135,  1136,  1137,  1138,  1142,  1143,  1148,   503,
    1166,  1156,   287,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   813,   490,   491,  1721,  1172,  1178,
    1211,   492,  1150,  1180,  1158,  1976,  1182,  1159,  1160,  1183,
     504,   504,  1185,  1196,  1184,   504,   504,  1186,  1212,  1188,
    1187,  1189,  1210,  1235,  1237,   364,  1213,  1214,  1215,  1248,
    1222,  1588,  1216,  1217,  1218,  1219,  1211,  1249,  1726,  1203,
    1204,   287,   287,  1250,  2185,  1251,  1260,  1263,  1599,  1264,
     472,   472,  1266,  1267,  1212,  1268,  1272,   287,  1211,  1273,
    1762,  1303,  1213,  1214,  1215,  1305,  1308,  1313,  1216,  1217,
    1218,  1219,  1314,   287,  1316,  1317,  1212,  1320,  1332,   287,
    1334,  1363,  1372,  1326,  1213,  1214,  1215,  1330,   287,  1339,
    1216,  1217,  1218,  1219,  1356,  1362,  1373,  1769,   287,  1772,
    1331,  1775,  2050,  1374,  1396,  1417,  1397,  1398,   287,  1809,
    1401,  1427,  1402,   287,  2187,  1411,  1412,  1413,  1414,  1415,
    1789,  1790,  1791,  1792,  1793,  1795,  1683,  1211,  1826,  1829,
    1830,  1428,  1685,  1431,  1432,  1433,  1447,  1673,  1448,  1458,
     287,  1449,  1677,  1450,  1451,  1212,  1452,  1453,  1454,  1455,
    2218,  1459,  2092,  1213,  1214,  1215,   540,   541,   542,  1216,
    1217,  1218,  1219,   287,  1460,  1461,  1464,  1462,  1463,  1465,
    1470,  1475,  2219,  1476,  1690,  1691,  1718,  1477,  1693,  1694,
    1478,  1480,  1485,  1482,  1487,  1490,  1492,  1494,  1495,   584,
     585,   586,   504,   504,  1496,  1550,  1505,   504,   504,  1530,
    1502,  1516,  1553,  1457,  1543,  1508,  1529,  1558,   287,  1549,
    1548,   504,  1559,  1560,  1561,  1563,  1569,   504,  1564,  1565,
    1570,   287,  1571,  1572,  1573,  1575,  1576,  1577,  1578,  1579,
     636,   637,  1580,  1581,   287,  1582,  1583,  1479,  1584,  1587,
    1589,  2220,  1598,   364,   649,   650,  1600,  1590,  1604,  1605,
    1661,   287,  1910,  1614,   503,  1615,  1616,  1622,  1623,  1630,
    1631,   504,  1636,  1637,   341,  1638,  1639,  1646,  1654,  1647,
    1648,  1659,  1649,   287,  1650,  1651,  1656,  1660,  1665,  1671,
     287,   287,   478,   479,   480,   481,   482,   483,   484,   485,
     486,   487,   488,   489,   490,   491,  1672,  1686,   287,  1698,
     492,   287,  1689,  1692,  1697,   472,   480,   481,   482,   483,
     484,   485,   486,   487,   488,   489,   490,   491,   287,  1700,
    1703,  1704,   492,   287,  1705,  1706,  1717,  1722,  1815,  1816,
    1723,  1727,  1818,  1819,  1728,  1729,  1732,  1734,  1822,  1823,
     481,   482,   483,   484,   485,   486,   487,   488,   489,   490,
     491,  1735,  1736,  1744,  1963,   492,  1966,  1745,  1969,  1747,
    1749,  1750,  1751,  1752,  1753,  1754,  1757,  1770,  1773,  1776,
    1980,  1981,  1982,  1983,  1984,  1781,  1786,  1787,  1783,  1796,
     287,  1800,  1810,  1814,  1817,  1831,  1832,  1833,  1821,  1834,
    1835,  1862,  1863,  1837,  1838,  1840,  1846,  1839,  1849,   287,
    1869,  1522,   287,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,  1853,  1854,  1870,
    1531,   492,   341,     7,     8,  2016,  1860,  1871,  1876,  2020,
    1877,  1889,  1879,  1880,  1882,  1884,  2052,   478,   479,   480,
     481,   482,   483,   484,   485,   486,   487,   488,   489,   490,
     491,  1886,  1891,  1902,  1892,   492,  1904,  1887,  1909,  1914,
    1893,  1915,  1916,  1917,  1918,  1911,   210,  1912,  1924,   287,
     287,   287,   287,   287,  1913,  1931,  1937,  1938,  1939,  1940,
    1941,  1942,  1949,  1971,  1975,   287,  1978,  1989,  2070,  1991,
    2137,  1995,  2072,  1997,  2018,   765,    24,    25,   766,    27,
      28,   767,    30,   768,    32,    33,    34,    35,  1990,  1998,
    2007,    37,    38,    39,  2015,    40,  2019,  2021,  2023,  2098,
      45,   769,    47,    48,   770,   574,    51,    52,    53,  2035,
    2048,  2036,  2049,    56,  2040,  2069,   504,  2074,  2076,  2079,
    2080,  2083,  2084,  2136,  2087,  2093,   364,    69,  2124,  2088,
    2090,  2102,  2138,  2118,  2152,  2155,  2120,  2158,  2161,  2122,
     287,  2162,  2163,  2164,  2135,   383,   503,  2139,  2166,  2167,
    2171,  2172,  2182,    83,    84,    85,  2184,  2193,  2186,  2200,
    2191,  2202,  2204,  2206,  2208,  2223,  2224,  2225,  2226,  2149,
    2150,  2227,  2228,  2230,  1552,  2054,   809,  1934,   287,  1632,
    1567,   478,   479,   480,   481,   482,   483,   484,   485,   486,
     487,   488,   489,   490,   491,   111,   503,   121,   503,   492,
     478,   479,   480,   481,   482,   483,   484,   485,   486,   487,
     488,   489,   490,   491,   122,   123,   890,  1957,   492,  1699,
       0,     0,     0,     0,   930,     0,     0,     0,   503,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     460,   461,   462,   464,   466,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   499,     0,     0,
       0,   506,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   513,   515,   518,   519,     0,
     521,   515,   523,   524,  2053,   515,   527,   528,   529,   530,
     531,   532,     0,   534,   535,  1676,     0,     0,     0,   515,
       0,     0,     0,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   575,   490,   491,   569,   571,   515,
       0,   492,     0,     0,     0,     0,     0,     0,     0,   579,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2169,     0,   600,     0,     0,     0,     0,
       0,     0,     0,     0,   609,   610,     0,     0,     0,     0,
       0,     0,     0,   623,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   635,     0,     0,     0,     0,  2174,   478,
     479,   480,   481,   482,   483,   484,   485,   486,   487,   488,
     489,   490,   491,  2207,   654,  2210,     0,   492,   657,   658,
     659,     0,   661,     0,     0,     0,   664,   665,   666,     0,
       0,   667,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2229,   681,     0,   504,     0,
       0,   686,   688,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   695,   696,     0,   698,   699,
     700,   701,   702,   703,   704,   705,   706,   707,   708,   709,
     710,   711,   712,   713,   714,   715,   716,   717,   718,   719,
       0,     0,     0,     0,     0,     0,     0,     0,   504,     0,
     504,     0,     0,   733,     0,     0,     0,     0,     0,   739,
       0,   741,     0,     0,  1680,   478,   479,   480,   481,   482,
     483,   484,   485,   486,   487,   488,   489,   490,   491,     0,
     504,     0,     0,   492,     0,   772,   515,     0,   774,   775,
     776,   777,   778,   779,   780,   781,   782,   783,   784,   785,
     786,   787,   788,   517,     0,   790,   791,     0,   522,     0,
       0,     0,   526,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   569,     0,   539,     0,     0,     0,
     818,     0,     0,     0,     0,   823,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   835,   836,     0,
       0,     0,     0,     0,   842,   843,     0,     0,   850,   850,
     855,   856,     0,   858,     0,     0,   860,     0,     0,     0,
    1799,     0,     0,     0,     0,     0,     0,     0,   515,     0,
       0,     0,     0,     0,   875,   877,   879,   880,     0,     0,
     884,   885,   886,     0,   233,   234,     0,   891,   893,   896,
     899,   902,   904,     0,   906,     0,   908,     0,   515,   515,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   926,   927,   928,   460,
     461,   929,     0,     0,     0,     0,   935,   936,   937,   938,
     939,   940,   941,   942,   943,     0,     0,     0,     0,   949,
       0,   951,   952,     0,     0,     0,   515,   515,   515,     0,
       0,   959,   960,   961,   478,   479,   480,   481,   482,   483,
     484,   485,   486,   487,   488,   489,   490,   491,     0,     0,
     515,     0,   492,     0,     0,   842,   843,     0,   879,   880,
       0,     0,     0,     0,     0,     0,     0,     0,  1836,   993,
     515,     0,   394,     0,   997,     0,     0,     0,     0,     0,
       0,   408,   409,   410,   411,   412,   413,   414,   415,   416,
     417,   418,   419,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,     0,     0,  1875,   436,
     437,   438,   439,   773,   441,   442,   443,   444,   445,   446,
       0,     0,   448,     0,     0,     0,     0,     0,   449,   450,
    1908,     0,     0,     0,   455,   456,     0,     0,     0,  1069,
     478,   479,   480,   481,   482,   483,   484,   485,   486,   487,
     488,   489,   490,   491,     0,     0,     0,     0,   492,     0,
       0,  2047,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1098,  1099,     0,     0,   515,  1105,  1106,
       0,   515,  1109,     0,     0,     0,     0,     0,     0,     0,
    1116,     0,     0,   877,  1119,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   872,     0,   547,     0,   550,
     551,   552,   553,     0,  1139,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   515,     0,   515,
     578,     0,   515,     0,     0,   910,   911,     0,     0,     0,
       0,     0,     0,     0,     0,   515,     0,   515,     0,   515,
       0,   515,     0,     0,     0,     0,   515,     0,     0,     0,
       0,   515,     0,     0,     0,     0,     0,  1176,   478,   479,
     480,   481,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   491,     0,   954,   955,   956,   492,     0,     0,     0,
       0,     0,   515,     0,     0,     0,     0,     0,     0,  1201,
    1202,     0,     0,     0,     0,  1205,     0,   974,   478,   479,
     480,   481,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   491,     0,     0,     0,  1236,   492,   994,  1238,     0,
     478,   479,   480,   481,   482,   483,   484,   485,   486,   487,
     488,   489,   490,   491,     0,     0,     0,  1252,   492,  1254,
    1255,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1262,   478,   479,   480,   481,   482,   483,   484,   485,   486,
     487,   488,   489,   490,   491,     0,   285,     0,     0,   492,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1284,     7,     8,     0,     0,     0,     0,     0,
    1285,  1286,  1287,     0,   515,     0,     0,     0,     0,     0,
       0,     0,  1290,   763,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1297,     0,     0,     0,
       0,  1300,     0,     0,  1104,     0,     0,     0,  1108,     0,
    1304,     0,     0,     0,     0,     0,  1312,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   515,   515,   515,   515,
    1325,     0,     0,     0,  1328,   765,    24,    25,   766,    27,
      28,   767,    30,   768,    32,    33,    34,    35,  2125,     0,
       0,    37,    38,    39,  1146,    40,  1147,     0,     0,  1149,
      45,   769,    47,    48,   770,     0,    51,    52,    53,     0,
       0,     0,  1161,    56,  1162,     0,  1163,     0,  1164,     0,
       0,     0,     0,  1168,     0,     0,     0,    69,  1171,     0,
       0,     0,   515,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1380,  1381,     0,  1382,  1383,     0,  1384,  1385,
    1386,     0,     0,    83,    84,    85,     0,  1392,     0,  1195,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1404,     0,  1406,     0,  1408,     0,  1410,
     478,   479,   480,   481,   482,   483,   484,   485,   486,   487,
     488,   489,   490,   491,     0,   536,     0,     0,   492,     0,
       0,     0,  1430,     0,     0,   920,     0,   932,     0,     0,
       0,     0,     0,     0,   285,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   953,     0,     0,     0,     0,     0,
       0,     0,   583,     0,     0,     0,     0,  1466,     0,     0,
       0,   593,   595,   597,     0,     0,     0,   602,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1486,     0,     0,     0,     0,  1491,  2101,     0,     0,     0,
       0,  1288,     0,     0,     7,     8,   638,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   478,   479,
     480,   481,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   491,     0,     0,     0,     0,   492,  1533,     0,     0,
       0,     0,     0,     0,     0,     0,  1541,     0,     0,     0,
    1544,  1545,     0,  1321,  1322,  1323,  1324,     0,     0,   683,
     684,     0,     0,     0,     0,  1554,  1556,     0,     0,     0,
       0,   574,   692,     0,     0,     0,   765,    24,    25,   766,
      27,    28,   767,    30,   768,    32,    33,    34,    35,     0,
       0,     0,    37,    38,    39,     0,    40,     0,     0,     0,
       0,    45,   769,    47,    48,   770,     0,    51,    52,    53,
     730,     0,     0,     0,    56,     0,     0,     0,     0,  1375,
       0,     0,     0,     0,     0,     0,     0,     0,    69,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1619,
    1620,  1621,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1633,     0,  1635,    83,    84,    85,     0,     0,     0,
       0,     0,     0,     0,     0,  1641,     0,     0,     0,     0,
       0,     0,     0,     0,   372,   133,     0,     0,   515,     0,
       0,     0,     0,  1657,     0,     0,     0,     0,     0,     0,
       0,  1662,  1663,  1664,     0,   478,   479,   480,   481,   482,
     483,   484,   485,   486,   487,   488,   489,   490,   491,     0,
       0,     0,     0,   492,   160,   161,   162,   163,   164,   165,
     166,   167,   168,  1684,     0,   975,     0,   173,   174,   175,
     176,     0,     0,   583,     0,   178,   179,   180,     0,     0,
     181,     0,     0,     0,     0,     0,     0,  1696,     0,     0,
       0,   186,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1710,     0,     0,     0,     0,  1716,   478,
     479,   480,   481,   482,   483,   484,   485,   486,   487,   488,
     813,   490,   491,  1724,  1725,     0,     0,   492,     0,     0,
    1730,  1731,     0,     0,     0,  1733,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1737,  1738,  1739,  1740,  1741,  1742,  1743,     0,     0,
       0,     0,     0,     0,  1748,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   515,   515,  1760,     0,  1761,  1301,
    1302,     0,     0,     0,     0,  1306,  1307,     0,     0,     0,
       0,  1779,     0,     0,     0,     0,   189,   190,   191,     0,
     516,     0,     0,     0,     0,   516,     0,     0,   198,   516,
     199,   106,   515,     0,     0,     0,  1798,     0,     7,     8,
       0,     0,     0,   516,     0,     0,     0,  1808,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   570,     0,   516,     0,     0,     0,  1828,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1058,     0,     0,     0,  1064,     0,     0,     0,
       0,  1843,  1844,     0,     0,  1655,     0,     0,     0,  1850,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     765,    24,    25,   766,    27,    28,   767,    30,   768,    32,
      33,    34,    35,     0,     0,     0,    37,    38,    39,     0,
      40,     0,     0,     0,     0,    45,   769,    47,    48,   770,
       0,    51,    52,    53,     0,  1878,     0,     0,    56,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    69,     0,     0,  1894,     0,     0,     0,     0,
       0,     0,     0,     0,   569,     0,     0,     0,     0,     0,
       0,     0,  1905,     0,  1906,     0,     0,   515,    83,    84,
      85,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1920,     0,     0,     0,     0,     0,
    1483,  1484,     0,     0,     0,  1488,  1489,     0,  1177,     0,
       0,     0,  1926,     0,     0,     0,     0,  1930,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1944,  1945,  1946,  1947,  1948,     0,
       0,  1758,  1759,     0,   515,     0,     0,     0,     0,   976,
     516,  1962,     0,  1965,     0,  1968,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   515,     0,     0,     0,
       0,     0,     0,     0,  1985,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   570,     0,
       0,     0,     0,     0,     0,     0,     0,  1999,  2000,     0,
       0,     0,  2002,  1265,     0,     0,   970,  1269,     0,     0,
       0,  1274,     0,     0,     0,     0,     0,     0,     0,  2013,
       0,     0,   851,   853,     0,     0,  1084,     0,     0,     0,
    2024,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   516,     0,     0,     0,     0,     0,     0,   878,
       0,     0,     0,     0,  1291,     0,     0,     0,     0,     0,
       0,     0,  2051,     0,     0,     0,     0,     0,  1716,     0,
       0,     0,   516,   516,     0,     0,     0,  2062,  2063,  2064,
    2065,  2066,  2067,     0,     0,     0,     0,     0,     0,     0,
       0,  1167,     0,     0,     0,     0,  2078,     0,     0,  2082,
       0,     0,  2086,     0,     0,     0,  2089,     0,     0,     0,
       0,     0,   515,   515,   515,   515,   515,     0,     0,     0,
     516,   516,   516,     0,     0,     0,  2105,     0,     0,  2107,
       0,     0,     0,     0,  1907,     0,     0,     0,     0,     0,
       0,     0,  1354,  1355,   516,  1357,     0,  1360,  1361,     0,
       0,  1364,  1365,  1366,  1367,  1368,  1369,  1370,  1371,     0,
       0,     0,     0,     0,   516,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2143,  2144,  2145,  2146,  2147,  2148,  1391,     0,     0,     0,
       0,     0,  1395,     0,     0,     0,     0,  1472,     0,     0,
       0,  1958,     0,   515,   478,   479,   480,   481,   482,   483,
     484,   485,   486,   487,   488,   489,   490,   491,     0,     0,
       0,     0,   492,  1979,   478,   479,   480,   481,   482,   483,
     484,   485,   486,   487,   488,   489,   490,   491,     0,     0,
       0,     0,   492,     0,     0,  2194,  2195,  2196,  2197,  2198,
    2199,     0,     0,     0,     0,  1456,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1467,  1468,
    1469,   516,     0,     0,     0,   516,     0,     0,     0,     0,
       0,     0,     0,     0,  1481,     0,     0,   878,  1120,   478,
     479,   480,   481,   482,   483,   484,   485,   486,   487,   488,
     489,   490,   491,     0,     0,     0,     0,   492,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   516,     0,   516,     0,     0,   516,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   516,
       0,   516,     0,   516,     0,   516,     0,  1399,     0,     0,
     516,     0,  1547,     0,     0,   516,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2094,
    2095,  2096,  2097,  2099,     0,     0,  1568,     0,     0,     0,
       0,     0,  1574,     0,     0,     0,   516,     0,     0,     0,
       0,     0,     0,     0,  1585,   478,   479,   480,   481,   482,
     483,   484,   485,   486,   487,   488,   489,   490,   491,     0,
       0,     0,     0,   492,     0,     0,  1601,  1602,  1603,     0,
       0,     0,  1606,  1607,     0,  1608,     0,  1609,     0,  1610,
       0,  1611,  1612,  1613,   478,   479,   480,   481,   482,   483,
     484,   485,   486,   487,   488,   489,   490,   491,     0,     0,
       0,  1634,   492,     0,     0,     0,     0,     0,     0,     0,
    2165,     0,     0,     0,     0,     0,     0,  1645,     0,     0,
       0,     0,     0,     0,     0,  1653,     0,     0,     0,     0,
       0,   478,   479,   480,   481,   482,   483,   484,   485,   486,
     487,   488,   489,   490,   491,     0,   131,   382,   516,   492,
       0,   962,   134,   135,   136,     0,   919,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   169,   170,   171,   172,
     516,   516,   516,   516,   177,     0,     0,     0,     0,     0,
       0,     0,  1708,     0,     0,   182,   183,   184,     0,     0,
       0,     0,     0,   185,     0,  1720,   131,   132,   133,     0,
       0,     0,   134,   135,   136,     0,     0,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
       0,     0,     0,     0,     0,     0,   516,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,     0,     0,     0,   178,   179,
     180,     0,     0,   181,     0,   182,   183,   184,     0,     0,
    1778,     0,     0,   185,   186,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1547,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   188,     0,
       0,  1801,   192,     0,     0,     0,   193,   194,   195,   196,
     197,  1813,     0,     0,   106,     0,     0,     0,     0,     0,
       0,  1820,     0,     0,     0,     0,  1825,     0,   200,   201,
       0,     0,     0,   202,     0,     0,     0,     0,   354,     0,
       0,     0,     0,   206,     0,   599,     0,     0,     0,     0,
       0,     0,     0,  1845,     0,     0,   478,   479,   480,   481,
     482,   483,   484,   485,   486,   487,   488,   489,   490,   491,
       0,   187,     0,     0,   492,     0,  1547,     0,   188,   189,
     190,   191,   192,  1082,     0,     0,   193,   194,   195,   196,
     197,   198,     0,   199,   106,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   200,   201,
       0,     0,     0,   202,     0,     0,     0,     0,   203,     0,
     204,  1890,   205,   206,     0,   207,     0,   208,     0,     0,
       0,     0,   131,   264,     0,     0,     0,     0,   134,   135,
     136,     0,     0,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   265,   266,   267,   268,
     269,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   169,   170,   171,   172,  1547,     0,     0,     0,
     177,     0,     0,  1935,  1936,     0,     0,     0,     0,     0,
       0,   182,   183,   184,     0,     0,     0,     0,     0,   185,
       0,  1547,     0,   270,     0,     0,   271,     0,     0,   272,
       0,   273,     0,     0,     0,     0,     0,     0,    36,     0,
       0,  1974,     0,     0,     0,     0,     0,     0,     0,   274,
       0,     0,   275,     0,     0,   276,     0,     0,     0,     0,
       0,     0,   516,    58,    59,    60,    61,    62,     0,     0,
      64,    65,    66,    67,    68,     0,     0,     0,    72,     0,
       0,    75,   478,   479,   480,   481,   482,   483,   484,   485,
     486,   487,   488,   489,   490,   491,     0,     0,     0,     0,
     492,     0,     0,  2017,     0,     0,     0,  1765,     0,  1766,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2034,     0,   188,  2037,     0,     0,   192,     0,
       0,     0,   193,   194,   195,   196,   197,     0,     0,     0,
     106,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   619,  1794,     0,     0,     0,   202,
       0,     0,     0,     0,   621,     0,     0,     0,     0,   206,
       0,   315,   572,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,     0,     0,     0,
       0,   492,     0,     0,     0,     0,     0,     0,  1802,     0,
    1803,     0,     0,     0,     0,     0,     0,     0,  1547,   131,
     264,     0,     0,     0,     0,   134,   135,   136,   516,   516,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   265,   266,   267,   268,   269,     0,     0,
       0,     0,     0,     0,     0,     0,   516,     0,     0,   169,
     170,   171,   172,     0,     0,     0,     0,   177,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   182,   183,
     184,     0,     0,     0,     0,     0,   185,     0,     0,     0,
     270,     0,     0,   271,     0,     0,   272,     0,   273,     0,
       0,     0,     0,     0,     0,    36,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   274,     0,     0,   275,
       0,  1547,   276,     0,     0,     0,     0,     0,     0,     0,
      58,    59,    60,    61,    62,     0,     0,    64,    65,    66,
      67,    68,     0,     0,     0,    72,     0,     0,    75,   478,
     479,   480,   481,   482,   483,   484,   485,   486,   487,   488,
     489,   490,   491,     0,     0,     0,     0,   492,     0,     0,
       0,     0,     0,     0,  1960,     0,  1961,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   188,     0,     0,     0,   192,     0,     0,   570,   193,
     194,   195,   196,   197,     0,   500,   133,   106,     0,     0,
       0,   516,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   200,   514,     0,     0,     0,   202,     0,  1921,     0,
       0,   354,     0,     0,     0,     0,   206,     0,     0,   572,
       0,     0,     0,     0,     0,   160,   161,   162,   163,   164,
     165,   166,   167,   168,     0,     0,     0,     0,   173,   174,
     175,   176,     0,     0,     0,     0,   178,   179,   180,     0,
       0,   181,     0,     0,     0,     0,     0,     0,   516,     0,
       0,     0,   186,     0,     0,     0,     0,     0,     0,     0,
     131,   264,   133,     0,     0,     0,   134,   135,   136,     0,
     516,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   265,   266,   267,   268,   269,     0,
       0,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,     0,
       0,     0,   178,   179,   180,     0,     0,   181,     0,   182,
     183,   184,     0,     0,     0,     0,     0,   185,   186,     0,
       0,   270,     0,     0,   271,     0,     0,   272,     0,   273,
       0,     0,     0,     0,     0,     0,    36,   189,   190,   191,
       0,     0,     0,     0,     0,     0,     0,   274,     0,   198,
     275,   199,   106,   276,     0,     0,     0,     0,     0,     0,
       0,    58,    59,    60,    61,    62,     0,     0,    64,    65,
      66,    67,    68,     0,     0,     0,    72,     0,     0,    75,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   516,   516,   516,   516,
     516,   478,   479,   480,   481,   482,   483,   484,   485,   486,
     487,   488,   489,   490,   491,     0,     0,     0,     0,   492,
       0,     0,   188,   189,   190,   191,   192,     0,  1141,     0,
     193,   194,   195,   196,   197,   198,     0,   199,   106,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   200,   277,     0,     0,     0,   202,     0,     0,
       0,     0,   354,     0,     0,     0,     0,   206,     0,   279,
       0,     0,     0,     0,     0,     0,     0,   131,   264,   133,
       0,     0,     0,   134,   135,   136,     0,   516,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   265,   266,   267,   268,   269,     0,     0,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,     0,     0,     0,   178,
     179,   180,     0,     0,   181,     0,   182,   183,   184,     0,
       0,     0,     0,     0,   185,   186,     0,     0,   270,     0,
       0,   271,     0,     0,   272,     0,   273,     0,     0,     0,
       0,     0,     0,    36,     0,     0,     0,     0,     0,   376,
     133,     0,     0,     0,   274,     0,     0,   275,     0,     0,
     276,     0,     0,     0,     0,     0,     0,     0,    58,    59,
      60,    61,    62,     0,     0,    64,    65,    66,    67,    68,
       0,     0,     0,    72,     0,     0,    75,     0,     0,   160,
     161,   162,   163,   164,   165,   166,   167,   168,     0,     0,
       0,     0,   173,   174,   175,   176,     0,     0,     0,     0,
     178,   179,   180,     0,     0,   181,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   186,     0,     0,   188,
     189,   190,   191,   192,     0,     0,     0,   193,   194,   195,
     196,   197,   198,     0,   199,   106,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   200,
     277,     0,     0,     0,   202,     0,     0,     0,     0,   354,
       0,   131,   264,   353,   206,     0,  1824,   134,   135,   136,
       0,     0,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   265,   266,   267,   268,   269,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   169,   170,   171,   172,     0,     0,     0,     0,   177,
       0,   189,   190,   191,     0,     0,     0,     0,     0,     0,
     182,   183,   184,   198,     0,   199,     0,     0,   185,     0,
       0,     0,   270,     0,     0,   271,     0,     0,   272,     0,
     273,     0,     0,     0,     0,     0,     0,    36,     0,     0,
       0,     0,     0,     0,   133,     0,     0,     0,   274,     0,
       0,   275,     0,     0,   276,     0,     0,     0,     0,     0,
       0,     0,    58,    59,    60,    61,    62,     0,     0,    64,
      65,    66,    67,    68,     0,     0,     0,    72,     0,     0,
      75,     0,     0,   160,   161,   162,   163,   164,   165,   166,
     167,   168,     0,     0,     0,     0,   173,   174,   175,   176,
       0,     0,     0,     0,   178,   179,   180,     0,     0,   181,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     186,     0,     0,   188,     0,     0,     0,   192,     0,     0,
       0,   193,   194,   195,   196,   197,     0,     0,     0,   106,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   200,   277,     0,     0,     0,   202,     0,
       0,     0,     0,   354,     0,   131,   264,  1644,   206,     0,
     279,   134,   135,   136,     0,     0,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   265,
     266,   267,   268,   269,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   169,   170,   171,   172,     0,
       0,     0,     0,   177,     0,   189,   190,   191,     0,     0,
       0,     0,     0,     0,   182,   183,   184,   198,     0,   199,
       0,     0,   185,     0,     0,     0,   270,     0,     0,   271,
       0,     0,   272,     0,   273,     0,     0,     0,     0,     0,
       0,    36,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   274,     0,     0,   275,     0,     0,   276,     0,
       0,     0,     0,     0,     0,     0,    58,    59,    60,    61,
      62,     0,     0,    64,    65,    66,    67,    68,     0,     0,
       0,    72,     0,     0,    75,   478,   479,   480,   481,   482,
     483,   484,   485,   486,   487,   488,   489,   490,   491,     0,
       0,     0,     0,   492,     0,     0,     0,     0,     0,     0,
       0,     0,  1157,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   188,     0,     0,
       0,   192,     0,     0,     0,   193,   194,   195,   196,   197,
       0,     0,     0,   106,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   200,   277,     0,
       0,     0,   202,     0,     0,     0,     0,   354,     0,   131,
     264,     0,   206,     0,   279,   134,   135,   136,     0,     0,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   265,   266,   267,   268,   269,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   169,
     170,   171,   172,     0,     0,     0,     0,   177,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   182,   183,
     184,     0,     0,     0,     0,     0,   185,     0,     0,     0,
     270,     0,     0,   271,     0,     0,   272,     0,   273,     0,
       0,     0,     0,     0,     0,    36,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   274,     0,     0,   275,
       0,     0,   276,     0,     0,     0,     0,     0,     0,     0,
      58,    59,    60,    61,    62,     0,     0,    64,    65,    66,
      67,    68,     0,     0,     0,    72,     0,     0,    75,   478,
     479,   480,   481,   482,   483,   484,   485,   486,   487,   488,
     489,   490,   491,     0,     0,     0,     0,   492,     0,     0,
       0,     0,     0,     0,     0,     0,  1227,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   188,     0,     0,     0,   192,     0,     0,     0,   193,
     194,   195,   196,   197,     0,     0,     0,   106,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   200,   277,     0,     0,     0,   202,     0,     0,     0,
       0,   278,     0,   131,   264,     0,   206,     0,   279,   134,
     135,   136,     0,     0,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   265,   266,   267,
     268,   269,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   169,   170,   171,   172,     0,     0,     0,
       0,   177,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   182,   183,   184,     0,     0,     0,     0,     0,
     185,     0,     0,     0,   270,     0,     0,   271,     0,     0,
     272,     0,   273,     0,     0,     0,     0,     0,     0,    36,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     274,     0,     0,   275,     0,     0,   276,     0,     0,     0,
       0,     0,     0,     0,    58,    59,    60,    61,    62,     0,
       0,    64,    65,    66,    67,    68,     0,     0,     0,    72,
       0,     0,    75,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,     0,     0,     0,
       0,   492,     0,     0,     0,     0,     0,     0,     0,     0,
    1277,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   188,     0,     0,     0,   192,
       0,     0,     0,   193,   194,   195,   196,   197,     0,     0,
       0,   106,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   200,   277,     0,     0,     0,
     202,     0,     0,     0,     0,   354,     0,   131,   264,     0,
     206,     0,   279,   134,   135,   136,     0,     0,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   265,   266,   267,   268,   269,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   169,   170,   171,
     172,     0,     0,     0,     0,   177,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   182,   183,   184,     0,
       0,     0,     0,     0,   185,     0,     0,     0,   270,     0,
       0,   271,     0,     0,   272,     0,   273,     0,     0,     0,
       0,     0,     0,    36,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   274,     0,     0,   275,     0,     0,
     276,     0,     0,     0,     0,     0,     0,     0,    58,    59,
      60,    61,    62,     0,     0,    64,    65,    66,    67,    68,
       0,     0,     0,    72,     0,     0,    75,   478,   479,   480,
     481,   482,   483,   484,   485,   486,   487,   488,   489,   490,
     491,     0,     0,     0,     0,   492,     0,     0,     0,     0,
       0,     0,     0,     0,  1422,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   188,
       0,     0,     0,   192,     0,     0,     0,   193,   194,   195,
     196,   197,     0,     0,     0,   106,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   200,
     514,     0,     0,     0,   202,     0,     0,     0,     0,   354,
       0,   131,   264,     0,   206,     0,   568,   134,   135,   136,
       0,     0,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   265,   266,   267,   268,   269,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   169,   170,   171,   172,     0,     0,     0,     0,   177,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     182,   183,   184,     0,     0,     0,     0,     0,   185,     0,
       0,     0,   270,     0,     0,   271,     0,     0,   272,     0,
     273,     0,     0,     0,     0,     0,     0,    36,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   274,     0,
       0,   275,     0,     0,   276,     0,     0,     0,     0,     0,
       0,     0,    58,    59,    60,    61,    62,     0,     0,    64,
      65,    66,    67,    68,     0,     0,     0,    72,     0,     0,
      75,   478,   479,   480,   481,   482,   483,   484,   485,   486,
     487,   488,   489,   490,   491,     0,     0,     0,     0,   492,
       0,     0,     0,     0,     0,     0,     0,     0,  1763,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   188,     0,     0,     0,   192,     0,     0,
       0,   193,   194,   195,   196,   197,     0,     0,     0,   106,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   200,   277,     0,     0,     0,   202,     0,
       0,     0,     0,   582,     0,   131,   264,     0,   206,     0,
     279,   134,   135,   136,     0,     0,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   265,
     266,   267,   268,   269,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   169,   170,   171,   172,     0,
       0,     0,     0,   177,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   182,   183,   184,     0,     0,     0,
       0,     0,   185,     0,     0,     0,   270,     0,     0,   271,
       0,     0,   272,     0,   273,     0,     0,     0,     0,     0,
       0,    36,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   274,     0,     0,   275,     0,     0,   276,     0,
       0,     0,     0,     0,     0,     0,    58,    59,    60,    61,
      62,     0,     0,    64,    65,    66,    67,    68,     0,     0,
       0,    72,     0,     0,    75,   478,   479,   480,   481,   482,
     483,   484,   485,   486,   487,   488,   489,   490,   491,     0,
       0,     0,     0,   492,     0,     0,     0,     0,     0,     0,
       0,     0,  1784,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   188,     0,     0,
       0,   192,     0,     0,     0,   193,   194,   195,   196,   197,
       0,     0,     0,   106,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   200,   277,     0,
       0,     0,   202,     0,     0,     0,     0,   592,     0,   131,
     264,     0,   206,     0,   279,   134,   135,   136,     0,     0,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   265,   266,   267,   268,   269,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   169,
     170,   171,   172,     0,     0,     0,     0,   177,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   182,   183,
     184,     0,     0,     0,     0,     0,   185,     0,     0,     0,
     270,     0,     0,   271,     0,     0,   272,     0,   273,     0,
       0,     0,     0,     0,     0,    36,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   274,     0,     0,   275,
       0,     0,   276,     0,     0,     0,     0,     0,     0,     0,
      58,    59,    60,    61,    62,     0,     0,    64,    65,    66,
      67,    68,     0,     0,     0,    72,     0,     0,    75,   478,
     479,   480,   481,   482,   483,   484,   485,   486,   487,   488,
     489,   490,   491,     0,     0,     0,     0,   492,     0,     0,
       0,     0,     0,     0,     0,     0,  1855,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   188,     0,     0,     0,   192,     0,     0,     0,   193,
     194,   195,   196,   197,     0,     0,     0,   106,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   200,   277,     0,     0,     0,   202,     0,     0,     0,
       0,   594,     0,   131,   264,     0,   206,     0,   279,   134,
     135,   136,     0,     0,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   265,   266,   267,
     268,   269,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   169,   170,   171,   172,     0,     0,     0,
       0,   177,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   182,   183,   184,     0,     0,     0,     0,     0,
     185,     0,     0,     0,   270,     0,     0,   271,     0,     0,
     272,     0,   273,     0,     0,     0,     0,     0,     0,    36,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     274,     0,     0,   275,     0,     0,   276,     0,     0,     0,
       0,     0,     0,     0,    58,    59,    60,    61,    62,     0,
       0,    64,    65,    66,    67,    68,     0,     0,     0,    72,
       0,     0,    75,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,     0,     0,     0,
       0,   492,     0,     0,     0,     0,     0,     0,     0,     0,
    1856,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   188,     0,     0,     0,   192,
       0,     0,     0,   193,   194,   195,   196,   197,     0,     0,
       0,   106,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   200,   277,     0,     0,     0,
     202,     0,     0,     0,     0,   596,     0,   131,   264,     0,
     206,     0,   279,   134,   135,   136,     0,     0,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   265,   266,   267,   268,   269,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   169,   170,   171,
     172,     0,     0,     0,     0,   177,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   182,   183,   184,     0,
       0,     0,     0,     0,   185,     0,     0,     0,   270,     0,
       0,   271,     0,     0,   272,     0,   273,     0,     0,     0,
       0,     0,     0,    36,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   274,     0,     0,   275,     0,     0,
     276,     0,     0,     0,     0,     0,     0,     0,    58,    59,
      60,    61,    62,     0,     0,    64,    65,    66,    67,    68,
       0,     0,     0,    72,     0,     0,    75,   478,   479,   480,
     481,   482,   483,   484,   485,   486,   487,   488,   489,   490,
     491,     0,     0,     0,     0,   492,     0,     0,     0,     0,
       0,     0,     0,     0,  1857,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   188,
       0,     0,     0,   192,     0,     0,     0,   193,   194,   195,
     196,   197,     0,     0,     0,   106,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   200,
     514,     0,     0,     0,   202,     0,     0,     0,     0,   354,
       0,   131,   264,     0,   206,     0,   849,   134,   135,   136,
       0,     0,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   265,   266,   267,   268,   269,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   169,   170,   171,   172,     0,     0,     0,     0,   177,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     182,   183,   184,     0,     0,     0,     0,     0,   185,     0,
       0,     0,   270,     0,     0,   271,     0,     0,   272,     0,
     273,     0,     0,     0,     0,     0,     0,    36,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   274,     0,
       0,   275,     0,     0,   276,     0,     0,     0,     0,     0,
       0,     0,    58,    59,    60,    61,    62,     0,     0,    64,
      65,    66,    67,    68,     0,     0,     0,    72,     0,     0,
      75,   478,   479,   480,   481,   482,   483,   484,   485,   486,
     487,   488,   489,   490,   491,     0,     0,     0,     0,   492,
       0,     0,     0,     0,     0,     0,     0,     0,  1858,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   188,     0,     0,     0,   192,     0,     0,
       0,   193,   194,   195,   196,   197,     0,     0,     0,   106,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   200,   514,     0,     0,     0,   202,     0,
       0,     0,     0,   354,     0,   131,   264,     0,   206,     0,
     852,   134,   135,   136,     0,     0,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   265,
     266,   267,   268,   269,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   169,   170,   171,   172,     0,
       0,     0,     0,   177,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   182,   183,   184,     0,     0,     0,
       0,     0,   185,     0,     0,     0,   270,     0,     0,   271,
       0,     0,   272,     0,   273,     0,     0,     0,     0,     0,
       0,    36,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   274,     0,     0,   275,     0,     0,   276,     0,
       0,     0,     0,     0,     0,     0,    58,    59,    60,    61,
      62,     0,     0,    64,    65,    66,    67,    68,     0,     0,
       0,    72,     0,     0,    75,   478,   479,   480,   481,   482,
     483,   484,   485,   486,   487,   488,   489,   490,   491,     0,
       0,     0,     0,   492,     0,     0,     0,     0,     0,     0,
       0,     0,  1859,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   188,     0,     0,
       0,   192,     0,     0,     0,   193,   194,   195,   196,   197,
       0,     0,     0,   106,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   200,   514,     0,
       0,     0,   202,     0,     0,     0,     0,   354,     0,   131,
     264,     0,   206,     0,   876,   134,   135,   136,     0,     0,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   265,   266,   267,   268,   269,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   169,
     170,   171,   172,     0,     0,     0,     0,   177,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   182,   183,
     184,     0,     0,     0,     0,     0,   185,     0,     0,     0,
     270,     0,     0,   271,     0,     0,   272,     0,   273,     0,
       0,     0,     0,     0,     0,    36,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   274,     0,     0,   275,
       0,     0,   276,     0,     0,     0,     0,     0,     0,     0,
      58,    59,    60,    61,    62,     0,     0,    64,    65,    66,
      67,    68,     0,     0,     0,    72,     0,     0,    75,   478,
     479,   480,   481,   482,   483,   484,   485,   486,   487,   488,
     489,   490,   491,     0,     0,     0,     0,   492,     0,     0,
       0,     0,     0,     0,     0,     0,  1903,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   188,     0,     0,     0,   192,     0,     0,     0,   193,
     194,   195,   196,   197,     0,     0,     0,   106,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   200,   277,     0,     0,     0,   202,     0,     0,     0,
       0,   354,     0,   131,   264,     0,   206,     0,  1652,   134,
     135,   136,     0,     0,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   265,   266,   267,
     268,   269,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   169,   170,   171,   172,     0,     0,     0,
       0,   177,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   182,   183,   184,     0,     0,     0,     0,     0,
     185,     0,     0,     0,   270,     0,     0,   271,     0,     0,
     272,     0,   273,     0,     0,     0,     0,     0,     0,    36,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     274,     0,     0,   275,     0,     0,   276,     0,     0,     0,
       0,     0,     0,     0,    58,    59,    60,    61,    62,     0,
       0,    64,    65,    66,    67,    68,     0,     0,     0,    72,
       0,     0,    75,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,     0,     0,     0,
       0,   492,     0,     0,     0,     0,     0,     0,     0,     0,
    1977,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   188,     0,     0,     0,   192,
       0,     0,     0,   193,   194,   195,   196,   197,     0,     0,
       0,   106,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   619,  1794,     0,     0,     0,
     202,     0,     0,     0,     0,   621,     0,   131,   382,   133,
     206,     0,   315,   134,   135,   136,     0,     0,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,     0,     0,     0,     0,     0,     0,     0,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,     0,     0,     0,   178,
     179,   180,     0,     0,   181,     0,   182,   183,   184,     0,
     131,   382,   133,     0,   185,   186,   134,   135,   136,     0,
       0,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,     0,     0,     0,     0,     0,     0,
       0,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,     0,
       0,     0,   178,   179,   180,     0,     0,   181,     0,   182,
     183,   184,     0,     0,     0,     0,     0,   185,   186,   478,
     479,   480,   481,   482,   483,   484,   485,   486,   487,   488,
     489,   490,   491,     0,     0,     0,     0,   492,     0,     0,
       0,     0,     0,     0,     0,     0,  1986,     0,     0,   188,
     189,   190,   191,   192,     0,     0,     0,   193,   194,   195,
     196,   197,   198,     0,   199,   106,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   200,
     201,     0,     0,     0,   202,     0,     0,     0,     0,   354,
       0,     0,     0,     0,   206,     0,  1555,     0,     0,     0,
     478,   479,   480,   481,   482,   483,   484,   485,   486,   487,
     488,   489,   490,   491,     0,     0,     0,     0,   492,     0,
       0,     0,   188,   189,   190,   191,   192,  1987,     0,     0,
     193,   194,   195,   196,   197,   198,     0,   199,   106,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   200,   201,     0,     0,     0,   202,     0,     0,
       0,     0,   354,     0,   131,   382,   133,   206,     0,  1807,
     134,   135,   136,     0,     0,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,     0,     0,
       0,     0,     0,     0,     0,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,     0,     0,     0,   178,   179,   180,     0,
       0,   181,     0,   182,   183,   184,     0,   131,   382,     0,
       0,   185,   186,   134,   135,   136,     0,     0,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,     0,     0,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   169,   170,   171,
     172,   492,     0,     0,     0,   177,     0,     0,     0,     0,
    2025,     0,     0,     0,     0,     0,   182,   183,   184,     0,
       0,     0,     0,     0,   185,   478,   479,   480,   481,   482,
     483,   484,   485,   486,   487,   488,   489,   490,   491,     0,
       0,     0,     0,   492,     0,     0,     0,     0,     0,     0,
       0,     0,  2028,     0,     0,     0,   188,   189,   190,   191,
     192,     0,     0,     0,   193,   194,   195,   196,   197,   198,
       0,   199,   106,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   200,   201,     0,     0,
       0,   202,     0,     0,     0,     0,   354,     0,     0,     0,
       0,   206,     0,  1827,   478,   479,   480,   481,   482,   483,
     484,   485,   486,   487,   488,   489,   490,   491,     0,     0,
       0,     0,   492,     0,     0,     0,     0,     0,     0,   188,
       0,  2031,     0,   192,     0,     0,     0,   193,   194,   195,
     196,   197,     0,     0,     0,   106,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   619,
     620,     0,     0,     0,   202,     0,     0,     0,     0,   621,
       0,   131,   264,     0,   206,     0,   315,   134,   135,   136,
       0,     0,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   265,   266,   267,   268,   269,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   169,   170,   171,   172,     0,     0,     0,     0,   177,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     182,   183,   184,     0,     0,     0,     0,     0,   185,     0,
       0,     0,   270,     0,     0,   271,     0,     0,   272,     0,
     273,     0,     0,     0,     0,     0,     0,    36,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   274,     0,
       0,   275,     0,     0,   276,     0,     0,     0,     0,     0,
       0,     0,    58,    59,    60,    61,    62,     0,     0,    64,
      65,    66,    67,    68,     0,     0,     0,    72,     0,     0,
      75,   478,   479,   480,   481,   482,   483,   484,   485,   486,
     487,   488,   489,   490,   491,     0,     0,     0,     0,   492,
       0,     0,     0,     0,     0,     0,     0,     0,  2068,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   188,     0,     0,     0,   192,     0,     0,
       0,   193,   194,   195,   196,   197,     0,     0,     0,   106,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   200,   514,     0,     0,     0,   202,   131,
     382,   133,     0,   354,     0,   134,   135,   136,   206,     0,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,     0,     0,     0,     0,     0,     0,     0,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,     0,     0,
       0,   178,   179,   180,     0,     0,   181,     0,   182,   183,
     184,     0,   131,   382,     0,     0,   185,   186,   134,   135,
     136,     0,     0,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,     0,     0,   478,   479,
     480,   481,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   491,   169,   170,   171,   172,   492,     0,     0,     0,
     177,     0,     0,     0,     0,  2075,     0,     0,     0,     0,
       0,   182,   183,   184,     0,     0,     0,     0,     0,   185,
     478,   479,   480,   481,   482,   483,   484,   485,   486,   487,
     488,   489,   490,   491,     0,     0,     0,     0,   492,     0,
       0,     0,     0,     0,     0,     0,     0,  2119,     0,     0,
       0,   188,   189,   190,   191,   192,     0,     0,     0,   193,
     194,   195,   196,   197,   198,     0,   199,   106,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   200,   201,     0,     0,     0,   202,     0,     0,     0,
       0,   354,     0,     0,     0,     0,   206,     0,   478,   479,
     480,   481,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   491,     0,     0,     0,     0,   492,     0,     0,     0,
       0,     0,     0,     0,   188,  2121,     0,     0,   192,     0,
       0,     0,   193,   194,   195,   196,   197,     0,     0,     0,
     106,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   200,   201,     0,     0,     0,   202,
     131,   382,     0,     0,   354,   463,   134,   135,   136,   206,
       0,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,     0,     0,   478,   479,   480,   481,
     482,   483,   484,   485,   486,   487,   488,   489,   490,   491,
     169,   170,   171,   172,   492,     0,     0,     0,   177,     0,
       0,     0,     0,  2123,     0,     0,     0,   131,   382,   182,
     183,   184,     0,   134,   135,   136,     0,   185,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,     0,     0,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   169,   170,   171,
     172,   492,     0,     0,     0,   177,     0,     0,     0,     0,
    2142,     0,     0,     0,     0,     0,   182,   183,   184,     0,
       0,     0,     0,     0,   185,   478,   479,   480,   481,   482,
     483,   484,   485,   486,   487,   488,   489,   490,   491,     0,
       0,     0,     0,   492,     0,     0,     0,     0,     0,     0,
       0,     0,  2173,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   188,     0,     0,     0,   192,     0,     0,     0,
     193,   194,   195,   196,   197,     0,     0,     0,   106,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   200,   201,     0,     0,     0,   202,     0,     0,
       0,     0,   354,     0,     0,   465,     0,   206,   478,   479,
     480,   481,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   491,     0,     0,     0,     0,   492,     0,     0,   188,
       0,     0,     0,   192,     0,  2212,     0,   193,   194,   195,
     196,   197,     0,     0,     0,   106,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   200,
     201,     0,     0,     0,   202,   131,   382,     0,     0,   354,
     685,   134,   135,   136,   206,     0,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,     0,
       0,   478,   479,   480,   481,   482,   483,   484,   485,   486,
     487,   488,   489,   490,   491,   169,   170,   171,   172,   492,
       0,     0,     0,   177,     0,     0,     0,     0,  2213,     0,
       0,     0,     0,     0,   182,   183,   184,   131,   382,     0,
    1261,     0,   185,   134,   135,   136,     0,     0,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,     0,     0,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   169,   170,   171,
     172,   492,     0,     0,     0,   177,     0,     0,     0,     0,
    2214,     0,     0,     0,     0,     0,   182,   183,   184,     0,
       0,     0,     0,     0,   185,   478,   479,   480,   481,   482,
     483,   484,   485,   486,   487,   488,   489,   490,   491,     0,
       0,     0,     0,   492,     0,     0,     0,     0,     0,     0,
       0,     0,  2215,     0,     0,     0,     0,   188,     0,     0,
       0,   192,     0,     0,     0,   193,   194,   195,   196,   197,
       0,     0,     0,   106,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   200,   201,     0,
       0,     0,   202,     0,     0,     0,     0,   354,     0,     0,
     687,     0,   206,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,     0,     0,     0,
       0,   492,     0,     0,     0,     0,     0,     0,     0,   188,
    2216,     0,     0,   192,     0,     0,     0,   193,   194,   195,
     196,   197,     0,     0,     0,   106,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   200,
     201,     0,     0,     0,   202,   131,   382,     0,  1429,   354,
       0,   134,   135,   136,   206,     0,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,     0,
       0,   478,   479,   480,   481,   482,   483,   484,   485,   486,
     487,   488,   489,   490,   491,   169,   170,   171,   172,   492,
       0,     0,     0,   177,     0,     0,     0,     0,  2217,     0,
       0,     0,   131,   382,   182,   183,   184,     0,   134,   135,
     136,     0,   185,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,     0,     0,   478,   479,
     480,   481,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   491,   169,   170,   171,   172,   492,     0,     0,     0,
     177,     0,     0,     0,   677,     0,     0,     0,     0,     0,
       0,   182,   183,   184,     0,     0,     0,     0,     0,   185,
     478,   479,   480,   481,   482,   483,   484,   485,   486,   487,
     488,   489,   490,   491,     0,     0,     0,     0,   492,     0,
       0,     0,     0,     0,     0,     0,   912,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   188,     0,     0,
       0,   192,     0,     0,     0,   193,   194,   195,   196,   197,
       0,     0,     0,   106,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   200,   201,     0,
       0,     0,   202,     0,     0,     0,     0,   354,     7,     8,
       0,     0,   206,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,     0,     0,     0,
       0,   492,     0,     0,   188,     0,     0,     0,   192,  1874,
       0,     0,   193,   194,   195,   196,   197,     7,     8,     0,
     106,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   200,   201,     0,     0,     0,   202,
       0,     0,     0,     0,   354,     0,     0,     0,     0,   206,
     765,    24,    25,   766,    27,    28,   767,    30,   768,    32,
      33,    34,    35,     0,     0,     0,    37,    38,    39,     0,
      40,     0,     0,     7,     8,    45,   769,    47,    48,   770,
       0,    51,    52,    53,     0,     0,     0,     0,    56,   765,
      24,    25,   766,    27,    28,   767,    30,   768,    32,    33,
      34,    35,    69,     0,     0,    37,    38,    39,     0,    40,
       0,     0,     7,     8,    45,   769,    47,    48,   770,     0,
      51,    52,    53,     0,     0,     0,     0,    56,    83,    84,
      85,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    69,     0,     0,     0,   765,    24,    25,   766,    27,
      28,   767,    30,   768,    32,    33,    34,    35,     0,     0,
       0,    37,    38,    39,     0,    40,     0,    83,    84,    85,
      45,   769,    47,    48,   770,     0,    51,    52,    53,     0,
       0,     0,     0,    56,   765,    24,    25,   766,    27,    28,
     767,    30,   768,    32,    33,    34,    35,    69,     0,  1198,
      37,    38,    39,     0,    40,     0,     0,     7,     8,    45,
     769,    47,    48,   770,     0,    51,    52,    53,     0,     0,
       0,     0,    56,    83,    84,    85,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    69,     0,  1199,     0,
       0,     0,     0,     0,     0,     0,     7,     8,   478,   479,
     480,   481,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   491,    83,    84,    85,     0,   492,     0,   845,     0,
     846,     0,     0,  1503,     0,     0,     0,     0,     0,   765,
      24,    25,   766,    27,    28,   767,    30,   768,    32,    33,
      34,    35,     0,     0,  1224,    37,    38,    39,     0,    40,
       0,     0,     7,     8,    45,   769,    47,    48,   770,     0,
      51,    52,    53,     0,     0,     0,     0,    56,   765,    24,
      25,   766,    27,    28,   767,    30,   768,    32,    33,    34,
      35,    69,     0,  1253,    37,    38,    39,     0,    40,     0,
       0,     7,     8,    45,   769,    47,    48,   770,     0,    51,
      52,    53,     0,     0,     0,     0,    56,    83,    84,    85,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      69,     0,     0,     0,   765,    24,    25,   766,    27,    28,
     767,    30,   768,    32,    33,    34,    35,     0,     0,     0,
      37,    38,    39,     0,    40,     0,    83,    84,    85,    45,
     769,    47,    48,   770,     0,    51,    52,    53,     0,     0,
       0,     0,    56,   765,    24,    25,   766,    27,    28,   767,
      30,   768,    32,    33,    34,    35,    69,     0,  1259,    37,
      38,    39,     0,    40,     0,     0,     7,     8,    45,   769,
      47,    48,   770,     0,    51,    52,    53,     0,     0,     0,
       0,    56,    83,    84,    85,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    69,     0,  1418,     0,   478,
     479,   480,   481,   482,   483,   484,   485,   486,   487,   488,
     489,   490,   491,     0,     0,     0,     0,   492,     0,     0,
       0,    83,    84,    85,   802,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   765,    24,
      25,   766,    27,    28,   767,    30,   768,    32,    33,    34,
      35,     0,     0,  1640,    37,    38,    39,     0,    40,     0,
       0,     0,     0,    45,   769,    47,    48,   770,     0,    51,
      52,    53,     0,     0,     0,     0,    56,     0,     0,     0,
       0,     0,     0,     0,    -4,     1,     0,     0,    -4,     0,
      69,     0,  2038,     0,     0,     0,    -4,    -4,     0,     0,
       0,   478,   479,   480,   481,   482,   483,   484,   485,   486,
     487,   488,   489,   490,   491,     0,    83,    84,    85,   492,
       0,   845,     0,   846,     0,     0,    -4,    -4,     0,     0,
       0,   478,   479,   480,   481,   482,   483,   484,   485,   486,
     487,   488,   489,   490,   491,     0,    -4,    -4,    -4,   492,
       0,     0,    -4,    -4,     0,    -4,   919,     0,     0,    -4,
      -4,     0,    -4,    -4,     0,     0,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,     0,     0,    -4,    -4,    -4,    -4,  2127,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,     0,     0,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,     0,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,
       0,     0,    -4,    -4,    -4,     0,     0,     0,     0,     0,
      -4,     6,     0,     0,     0,    -4,    -4,    -4,    -4,     7,
       8,    -4,     0,    -4,     0,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,
       0,     0,     0,     0,    -4,    -4,    -4,     0,     0,     9,
      10,     0,     0,    -4,     0,    -4,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    11,
      12,    13,     0,     0,     0,    14,    15,     0,    16,     0,
       0,     0,    17,    18,     0,    19,    20,     0,     0,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,     0,     0,    36,    37,    38,    39,
       0,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,     0,     0,    55,    56,
      57,    58,    59,    60,    61,    62,    63,     0,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,     7,     8,     0,    78,    79,    80,     0,     0,
       0,     0,     0,    81,     0,     0,     0,     0,    82,    83,
      84,    85,     0,     0,    86,     0,    87,     0,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,     0,     0,     0,     0,     0,   102,   103,   104,
       0,     0,     0,     0,     0,     0,   105,     0,   106,     7,
       8,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   765,    24,    25,   766,    27,    28,
     767,    30,   768,    32,    33,    34,    35,     0,     0,     0,
      37,    38,    39,     0,    40,     0,     0,     0,     0,    45,
     769,    47,    48,   770,     0,    51,    52,    53,     0,     0,
       0,     0,    56,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    69,     0,     0,     0,
     980,   765,    24,    25,   766,    27,    28,   767,    30,   768,
      32,    33,    34,    35,     0,     0,     0,    37,    38,    39,
       0,    40,    83,    84,    85,     0,    45,   769,    47,    48,
     770,     0,    51,    52,    53,     0,     0,     0,     0,    56,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    69,     0,     0,     0,   478,   479,   480,
     481,   482,   483,   484,   485,   486,   487,   488,   489,   490,
     491,     0,     0,     0,     0,   492,     0,     0,     0,    83,
      84,    85,   920,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,     0,     0,     0,
       0,   492,     0,     0,     0,     0,     0,     0,   967,   478,
     479,   480,   481,   482,   483,   484,   485,   486,   487,   488,
     489,   490,   491,     0,     0,     0,     0,   492,     0,     0,
       0,     0,     0,     0,  1012,   478,   479,   480,   481,   482,
     483,   484,   485,   486,   487,   488,   489,   490,   491,     0,
       0,     0,     0,   492,     0,     0,     0,     0,     0,     0,
    1020,   478,   479,   480,   481,   482,   483,   484,   485,   486,
     487,   488,   489,   490,   491,     0,     0,     0,     0,   492,
       0,     0,     0,     0,     0,     0,  1021,   478,   479,   480,
     481,   482,   483,   484,   485,   486,   487,   488,   489,   490,
     491,     0,     0,     0,     0,   492,     0,     0,     0,     0,
       0,     0,  1022,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,     0,     0,     0,
       0,   492,     0,     0,     0,     0,     0,     0,  1037,   478,
     479,   480,   481,   482,   483,   484,   485,   486,   487,   488,
     489,   490,   491,     0,     0,     0,     0,   492,     0,     0,
       0,     0,     0,     0,  1152,   478,   479,   480,   481,   482,
     483,   484,   485,   486,   487,   488,   489,   490,   491,     0,
       0,     0,     0,   492,     0,     0,     0,     0,     0,     0,
    1153,   478,   479,   480,   481,   482,   483,   484,   485,   486,
     487,   488,   489,   490,   491,     0,     0,     0,     0,   492,
       0,     0,     0,     0,     0,     0,  1155,   478,   479,   480,
     481,   482,   483,   484,   485,   486,   487,   488,   489,   490,
     491,     0,     0,     0,     0,   492,     0,     0,     0,     0,
       0,     0,  1207,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,     0,     0,     0,
       0,   492,     0,     0,     0,     0,     0,     0,  1208,   478,
     479,   480,   481,   482,   483,   484,   485,   486,   487,   488,
     489,   490,   491,     0,     0,     0,     0,   492,     0,     0,
       0,     0,     0,     0,  1209,   478,   479,   480,   481,   482,
     483,   484,   485,   486,   487,   488,   489,   490,   491,     0,
       0,     0,     0,   492,     0,     0,     0,     0,     0,     0,
    1247,   478,   479,   480,   481,   482,   483,   484,   485,   486,
     487,   488,   489,   490,   491,     0,     0,     0,     0,   492,
       0,     0,     0,     0,     0,     0,  1345,   478,   479,   480,
     481,   482,   483,   484,   485,   486,   487,   488,   489,   490,
     491,     0,     0,     0,     0,   492,     0,     0,     0,     0,
       0,     0,  1420,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,     0,     0,     0,
       0,   492,     0,     0,     0,     0,     0,     0,  1421,   478,
     479,   480,   481,   482,   483,   484,   485,   486,   487,   488,
     489,   490,   491,     0,     0,     0,     0,   492,     0,     0,
       0,     0,     0,     0,  1471,   478,   479,   480,   481,   482,
     483,   484,   485,   486,   487,   488,   489,   490,   491,     0,
       0,     0,     0,   492,     0,     0,     0,     0,     0,     0,
    1591,   478,   479,   480,   481,   482,   483,   484,   485,   486,
     487,   488,   489,   490,   491,     0,     0,     0,     0,   492,
       0,     0,     0,     0,     0,     0,  1592,   478,   479,   480,
     481,   482,   483,   484,   485,   486,   487,   488,   489,   490,
     491,     0,     0,     0,     0,   492,     0,     0,     0,     0,
       0,     0,  1593,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,     0,     0,     0,
       0,   492,     0,     0,     0,     0,     0,     0,  1594,   478,
     479,   480,   481,   482,   483,   484,   485,   486,   487,   488,
     489,   490,   491,     0,     0,     0,     0,   492,     0,     0,
       0,     0,     0,     0,  1595,   478,   479,   480,   481,   482,
     483,   484,   485,   486,   487,   488,   489,   490,   491,     0,
       0,     0,     0,   492,     0,     0,     0,     0,     0,     0,
    1596,   478,   479,   480,   481,   482,   483,   484,   485,   486,
     487,   488,   489,   490,   491,     0,     0,     0,     0,   492,
       0,     0,     0,     0,     0,     0,  1597,   478,   479,   480,
     481,   482,   483,   484,   485,   486,   487,   488,   489,   490,
     491,     0,     0,     0,     0,   492,     0,     0,     0,     0,
       0,     0,  1711,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,     0,     0,     0,
       0,   492,     0,     0,     0,     0,     0,     0,  1712,   478,
     479,   480,   481,   482,   483,   484,   485,   486,   487,   488,
     489,   490,   491,     0,     0,     0,     0,   492,     0,     0,
       0,     0,     0,     0,  1719,   478,   479,   480,   481,   482,
     483,   484,   485,   486,   487,   488,   489,   490,   491,     0,
       0,     0,     0,   492,     0,     0,     0,     0,     0,     0,
    1864,   478,   479,   480,   481,   482,   483,   484,   485,   486,
     487,   488,   489,   490,   491,     0,     0,     0,     0,   492,
       0,     0,     0,     0,     0,     0,  1865,   478,   479,   480,
     481,   482,   483,   484,   485,   486,   487,   488,   489,   490,
     491,     0,     0,     0,     0,   492,     0,     0,     0,     0,
       0,     0,  1866,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,     0,     0,     0,
       0,   492,     0,     0,     0,     0,     0,     0,  1867,   478,
     479,   480,   481,   482,   483,   484,   485,   486,   487,   488,
     489,   490,   491,     0,     0,     0,     0,   492,     0,     0,
       0,     0,     0,     0,  1868,   478,   479,   480,   481,   482,
     483,   484,   485,   486,   487,   488,   489,   490,   491,     0,
       0,     0,     0,   492,     0,     0,     0,     0,     0,     0,
    1927,   478,   479,   480,   481,   482,   483,   484,   485,   486,
     487,   488,   489,   490,   491,     0,     0,     0,     0,   492,
       0,     0,     0,     0,     0,     0,  1928,   478,   479,   480,
     481,   482,   483,   484,   485,   486,   487,   488,   489,   490,
     491,     0,     0,     0,     0,   492,     0,     0,     0,     0,
       0,     0,  1932,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,     0,     0,     0,
       0,   492,     0,     0,     0,     0,     0,     0,  2008,   478,
     479,   480,   481,   482,   483,   484,   485,   486,   487,   488,
     489,   490,   491,     0,     0,     0,     0,   492,     0,     0,
       0,     0,     0,     0,  2009,   478,   479,   480,   481,   482,
     483,   484,   485,   486,   487,   488,   489,   490,   491,     0,
       0,     0,     0,   492,     0,     0,     0,     0,     0,     0,
    2010,   478,   479,   480,   481,   482,   483,   484,   485,   486,
     487,   488,   489,   490,   491,     0,     0,     0,     0,   492,
       0,     0,     0,     0,     0,     0,  2011,   478,   479,   480,
     481,   482,   483,   484,   485,   486,   487,   488,   489,   490,
     491,     0,     0,     0,     0,   492,     0,     0,     0,     0,
       0,     0,  2012,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,     0,     0,     0,
       0,   492,     0,     0,     0,     0,     0,     0,  2056,   478,
     479,   480,   481,   482,   483,   484,   485,   486,   487,   488,
     489,   490,   491,     0,     0,     0,     0,   492,     0,     0,
       0,     0,     0,     0,  2059,   478,   479,   480,   481,   482,
     483,   484,   485,   486,   487,   488,   489,   490,   491,     0,
       0,     0,     0,   492,     0,     0,     0,     0,     0,     0,
    2110,   478,   479,   480,   481,   482,   483,   484,   485,   486,
     487,   488,   489,   490,   491,     0,     0,     0,     0,   492,
       0,     0,     0,     0,     0,     0,  2111,   478,   479,   480,
     481,   482,   483,   484,   485,   486,   487,   488,   489,   490,
     491,     0,     0,     0,     0,   492,     0,     0,     0,     0,
       0,     0,  2112,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,     0,     0,     0,
       0,   492,     0,     0,     0,     0,     0,     0,  2113,   478,
     479,   480,   481,   482,   483,   484,   485,   486,   487,   488,
     489,   490,   491,     0,     0,     0,     0,   492,     0,     0,
       0,     0,     0,     0,  2114,   478,   479,   480,   481,   482,
     483,   484,   485,   486,   487,   488,   489,   490,   491,     0,
       0,     0,     0,   492,     0,     0,     0,     0,     0,     0,
    2115,   478,   479,   480,   481,   482,   483,   484,   485,   486,
     487,   488,   489,   490,   491,     0,     0,     0,     0,   492,
       0,     0,     0,     0,     0,     0,  2175,   478,   479,   480,
     481,   482,   483,   484,   485,   486,   487,   488,   489,   490,
     491,     0,     0,     0,     0,   492,     0,     0,     0,     0,
       0,     0,  2176,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,     0,     0,     0,
       0,   492,     0,     0,     0,     0,     0,     0,  2177,   478,
     479,   480,   481,   482,   483,   484,   485,   486,   487,   488,
     489,   490,   491,     0,     0,     0,     0,   492,     0,     0,
       0,     0,     0,     0,  2178,   478,   479,   480,   481,   482,
     483,   484,   485,   486,   487,   488,   489,   490,   491,     0,
       0,     0,     0,   492,     0,     0,     0,   757,   478,   479,
     480,   481,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   491,     0,     0,     0,     0,   492,     0,     0,     0,
     973,   478,   479,   480,   481,   482,   483,   484,   485,   486,
     487,   488,   489,   490,   491,     0,     0,     0,     0,   492,
       0,     0,     0,   992,   478,   479,   480,   481,   482,   483,
     484,   485,   486,   487,   488,   489,   490,   491,     0,     0,
       0,     0,   492,     0,     0,     0,   999,   478,   479,   480,
     481,   482,   483,   484,   485,   486,   487,   488,   489,   490,
     491,     0,     0,     0,     0,   492,     0,     0,     0,  1097,
     478,   479,   480,   481,   482,   483,   484,   485,   486,   487,
     488,   489,   490,   491,     0,     0,     0,     0,   492,     0,
       0,     0,  1145,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,     0,     0,     0,
       0,   492,     0,     0,     0,  1170,   478,   479,   480,   481,
     482,   483,   484,   485,   486,   487,   488,   489,   490,   491,
       0,     0,     0,     0,   492,     0,     0,     0,  1240,   478,
     479,   480,   481,   482,   483,   484,   485,   486,   487,   488,
     489,   490,   491,     0,     0,     0,     0,   492,     0,     0,
       0,  1241,   478,   479,   480,   481,   482,   483,   484,   485,
     486,   487,   488,   489,   490,   491,     0,     0,     0,     0,
     492,     0,     0,     0,  1245,   478,   479,   480,   481,   482,
     483,   484,   485,   486,   487,   488,   489,   490,   491,     0,
       0,     0,     0,   492,     0,     0,     0,  1246,   478,   479,
     480,   481,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   491,     0,     0,     0,     0,   492,     0,     0,     0,
    1279,   478,   479,   480,   481,   482,   483,   484,   485,   486,
     487,   488,   489,   490,   491,     0,     0,     0,     0,   492,
       0,     0,     0,  1338,   478,   479,   480,   481,   482,   483,
     484,   485,   486,   487,   488,   489,   490,   491,     0,     0,
       0,     0,   492,     0,     0,     0,  1343,   478,   479,   480,
     481,   482,   483,   484,   485,   486,   487,   488,   489,   490,
     491,     0,     0,     0,     0,   492,     0,     0,     0,  1658,
     478,   479,   480,   481,   482,   483,   484,   485,   486,   487,
     488,   489,   490,   491,     0,     0,     0,     0,   492,     0,
       0,     0,  1701,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,     0,     0,     0,
       0,   492,     0,     0,     0,  1888,   478,   479,   480,   481,
     482,   483,   484,   485,   486,   487,   488,   489,   490,   491,
       0,     0,     0,     0,   492,     0,   753,   478,   479,   480,
     481,   482,   483,   484,   485,   486,   487,   488,   489,   490,
     491,     0,     0,     0,     0,   492,     0,   812,   478,   479,
     480,   481,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   491,     0,     0,     0,     0,   492,     0,   816,   478,
     479,   480,   481,   482,   483,   484,   485,   486,   487,   488,
     489,   490,   491,     0,     0,     0,     0,   492,     0,   817,
     478,   479,   480,   481,   482,   483,   484,   485,   486,   487,
     488,   489,   490,   491,     0,     0,     0,     0,   492,     0,
     819,   478,   479,   480,   481,   482,   483,   484,   485,   486,
     487,   488,   489,   490,   491,     0,     0,     0,     0,   492,
       0,   821,   478,   479,   480,   481,   482,   483,   484,   485,
     486,   487,   488,   489,   490,   491,     0,     0,     0,     0,
     492,     0,   822,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,     0,     0,     0,
       0,   492,     0,   825,   478,   479,   480,   481,   482,   483,
     484,   485,   486,   487,   488,   489,   490,   491,     0,     0,
       0,     0,   492,     0,   826,   478,   479,   480,   481,   482,
     483,   484,   485,   486,   487,   488,   489,   490,   491,     0,
       0,     0,     0,   492,     0,   827,   478,   479,   480,   481,
     482,   483,   484,   485,   486,   487,   488,   489,   490,   491,
       0,     0,     0,     0,   492,     0,   828,   478,   479,   480,
     481,   482,   483,   484,   485,   486,   487,   488,   489,   490,
     491,     0,     0,     0,     0,   492,     0,   829,   478,   479,
     480,   481,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   491,     0,     0,     0,     0,   492,     0,   830,   478,
     479,   480,   481,   482,   483,   484,   485,   486,   487,   488,
     489,   490,   491,     0,     0,     0,     0,   492,     0,   832,
     478,   479,   480,   481,   482,   483,   484,   485,   486,   487,
     488,   489,   490,   491,     0,     0,     0,     0,   492,     0,
     833,   478,   479,   480,   481,   482,   483,   484,   485,   486,
     487,   488,   489,   490,   491,     0,     0,     0,     0,   492,
       0,   873,   478,   479,   480,   481,   482,   483,   484,   485,
     486,   487,   488,   489,   490,   491,     0,     0,     0,     0,
     492,     0,   883,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,     0,     0,     0,
       0,   492,     0,   944,   478,   479,   480,   481,   482,   483,
     484,   485,   486,   487,   488,   489,   490,   491,     0,     0,
       0,     0,   492,     0,   962,   478,   479,   480,   481,   482,
     483,   484,   485,   486,   487,   488,   489,   490,   491,     0,
       0,     0,     0,   492,     0,   963,   478,   479,   480,   481,
     482,   483,   484,   485,   486,   487,   488,   489,   490,   491,
       0,     0,     0,     0,   492,     0,   964,   478,   479,   480,
     481,   482,   483,   484,   485,   486,   487,   488,   489,   490,
     491,     0,     0,     0,     0,   492,     0,   965,   478,   479,
     480,   481,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   491,     0,     0,     0,     0,   492,     0,   971,   478,
     479,   480,   481,   482,   483,   484,   485,   486,   487,   488,
     489,   490,   491,     0,     0,     0,     0,   492,     0,   972,
     478,   479,   480,   481,   482,   483,   484,   485,   486,   487,
     488,   489,   490,   491,     0,     0,     0,     0,   492,     0,
     979,   478,   479,   480,   481,   482,   483,   484,   485,   486,
     487,   488,   489,   490,   491,     0,     0,     0,     0,   492,
       0,   988,   478,   479,   480,   481,   482,   483,   484,   485,
     486,   487,   488,   489,   490,   491,     0,     0,     0,     0,
     492,     0,   998,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,     0,     0,     0,
       0,   492,     0,  1096,   478,   479,   480,   481,   482,   483,
     484,   485,   486,   487,   488,   489,   490,   491,     0,     0,
       0,     0,   492,     0,  1124,   478,   479,   480,   481,   482,
     483,   484,   485,   486,   487,   488,   489,   490,   491,     0,
       0,     0,     0,   492,     0,  1129,   478,   479,   480,   481,
     482,   483,   484,   485,   486,   487,   488,   489,   490,   491,
       0,     0,     0,     0,   492,     0,  1140,   478,   479,   480,
     481,   482,   483,   484,   485,   486,   487,   488,   489,   490,
     491,     0,     0,     0,     0,   492,     0,  1144,   478,   479,
     480,   481,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   491,     0,     0,     0,     0,   492,     0,  1169,   478,
     479,   480,   481,   482,   483,   484,   485,   486,   487,   488,
     489,   490,   491,     0,     0,     0,     0,   492,     0,  1173,
     478,   479,   480,   481,   482,   483,   484,   485,   486,   487,
     488,   489,   490,   491,     0,     0,     0,     0,   492,     0,
    1174,   478,   479,   480,   481,   482,   483,   484,   485,   486,
     487,   488,   489,   490,   491,     0,     0,     0,     0,   492,
       0,  1175,   478,   479,   480,   481,   482,   483,   484,   485,
     486,   487,   488,   489,   490,   491,     0,     0,     0,     0,
     492,     0,  1181,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,     0,     0,     0,
       0,   492,     0,  1190,   478,   479,   480,   481,   482,   483,
     484,   485,   486,   487,   488,   489,   490,   491,     0,     0,
       0,     0,   492,     0,  1191,   478,   479,   480,   481,   482,
     483,   484,   485,   486,   487,   488,   489,   490,   491,     0,
       0,     0,     0,   492,     0,  1192,   478,   479,   480,   481,
     482,   483,   484,   485,   486,   487,   488,   489,   490,   491,
       0,     0,     0,     0,   492,     0,  1226,   478,   479,   480,
     481,   482,   483,   484,   485,   486,   487,   488,   489,   490,
     491,     0,     0,     0,     0,   492,     0,  1228,   478,   479,
     480,   481,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   491,     0,     0,     0,     0,   492,     0,  1229,   478,
     479,   480,   481,   482,   483,   484,   485,   486,   487,   488,
     489,   490,   491,     0,     0,     0,     0,   492,     0,  1230,
     478,   479,   480,   481,   482,   483,   484,   485,   486,   487,
     488,   489,   490,   491,     0,     0,     0,     0,   492,     0,
    1231,   478,   479,   480,   481,   482,   483,   484,   485,   486,
     487,   488,   489,   490,   491,     0,     0,     0,     0,   492,
       0,  1232,   478,   479,   480,   481,   482,   483,   484,   485,
     486,   487,   488,   489,   490,   491,     0,     0,     0,     0,
     492,     0,  1233,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,     0,     0,     0,
       0,   492,     0,  1234,   478,   479,   480,   481,   482,   483,
     484,   485,   486,   487,   488,   489,   490,   491,     0,     0,
       0,     0,   492,     0,  1239,   478,   479,   480,   481,   482,
     483,   484,   485,   486,   487,   488,   489,   490,   491,     0,
       0,     0,     0,   492,     0,  1337,   478,   479,   480,   481,
     482,   483,   484,   485,   486,   487,   488,   489,   490,   491,
       0,     0,     0,     0,   492,     0,  1342,   478,   479,   480,
     481,   482,   483,   484,   485,   486,   487,   488,   489,   490,
     491,     0,     0,     0,     0,   492,     0,  1515,   478,   479,
     480,   481,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   491,     0,     0,     0,     0,   492,     0,  1540,   478,
     479,   480,   481,   482,   483,   484,   485,   486,   487,   488,
     489,   490,   491,     0,     0,     0,     0,   492,     0,  1707,
     478,   479,   480,   481,   482,   483,   484,   485,   486,   487,
     488,   489,   490,   491,     0,     0,     0,     0,   492,     0,
    1764,   478,   479,   480,   481,   482,   483,   484,   485,   486,
     487,   488,   489,   490,   491,     0,     0,     0,     0,   492,
       0,  1782,   478,   479,   480,   481,   482,   483,   484,   485,
     486,   487,   488,   489,   490,   491,     0,     0,     0,     0,
     492,     0,  1806,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,     0,     0,     0,
       0,   492,     0,  2055,   478,   479,   480,   481,   482,   483,
     484,   485,   486,   487,   488,   489,   490,   491,     0,     0,
       0,     0,   492,     0,  2140,   478,   479,   480,   481,   482,
     483,   484,   485,   486,   487,   488,   489,   490,   491,     0,
       0,     0,     0,   492
};

static const yytype_int16 yycheck[] =
{
       3,     3,  1646,     6,   430,   323,   432,   308,   613,   614,
    1669,  1670,     4,     4,     4,     4,  1851,     4,     6,     4,
       4,   447,   340,     4,     6,     4,     4,     4,     4,    90,
      13,     5,     5,     4,     6,     5,     5,     5,   130,     6,
       6,     6,     5,    46,     5,     5,     5,    90,     6,   110,
       5,   215,   216,     7,     4,     4,     6,    87,     4,     6,
      90,   379,    92,   381,     6,   215,   216,   110,   232,   387,
      73,   215,   216,     0,     6,     6,   215,   216,    81,   215,
     216,   231,     6,    86,     4,     5,   225,   231,     7,   233,
     167,   229,  1736,   232,    97,   231,   234,   233,   215,   216,
     225,     6,    59,    60,     6,    62,   183,   184,  1220,    97,
     226,    99,   222,   223,   231,   231,   233,   215,   216,   225,
       7,   227,   232,   225,    44,    45,    46,    47,    48,    49,
      50,    51,    52,   228,    84,   233,   231,    57,    58,    59,
      60,   215,   216,   215,   216,    65,    66,    67,   215,   216,
      70,    90,   225,   215,   216,   225,   215,   216,   232,   232,
     232,    81,   232,     6,   231,   157,   158,   159,   160,   231,
    2005,  2006,   231,     7,   463,   225,   465,    87,   467,    90,
      90,    92,   232,   155,   215,   216,   217,   218,   219,   155,
     155,   167,   168,   224,   178,   182,   170,   170,   215,   216,
       6,   170,  1846,   206,    87,   207,     7,    90,   155,   170,
     215,   216,   201,  1225,   231,   218,   219,   201,   167,   168,
     201,     7,     6,   226,   222,   223,   231,  1871,     7,   228,
     225,   234,   231,   236,   232,   225,   227,   227,   241,   229,
     225,   233,   245,   234,   234,   233,   225,   232,   232,   252,
     232,   232,   255,   232,   232,   232,   259,   260,   261,   262,
     263,   232,   232,   232,   232,   232,   186,   187,   188,   232,
     212,   274,   232,   232,   277,   229,   279,   232,   198,   225,
     200,   201,     3,   215,   216,     6,   604,   605,   212,   292,
     293,   294,   295,     6,   225,     4,     5,   227,   301,   302,
     303,   232,   222,   223,   307,   308,   225,   625,   227,   229,
     215,   216,   232,   215,   216,   202,   203,   204,   205,   222,
     223,   225,     6,   227,   225,     7,   227,   222,   223,   232,
     234,   334,   335,   336,  1446,    44,    45,    46,    47,    48,
      49,    50,    51,    52,   662,   348,   349,     6,    57,    58,
      59,    60,    73,   225,   311,   312,    65,    66,    67,   677,
     232,    70,   319,   215,   216,    86,   323,   225,   202,   203,
     204,   205,    81,     7,   232,   467,    97,    84,     7,   231,
      87,     6,   385,    90,   225,     7,   389,   390,   222,   223,
     227,  2050,   215,   216,    84,   229,   685,    87,   687,   402,
      90,   202,   203,   204,   205,   226,   225,   395,   231,   225,
     231,     7,   218,   219,  2058,     4,   202,   203,   204,   205,
     225,   222,   223,   202,   203,   204,   205,   430,   431,   432,
     433,   434,   435,   436,   437,   438,   439,   440,   441,   442,
     225,   444,   445,   446,   447,   448,   252,   225,   119,   452,
     453,   454,   455,   456,   457,   225,   459,   263,   225,   222,
     223,   226,   450,   228,   753,   225,   137,   232,   757,   232,
     458,   225,     8,   476,   145,   146,   147,   186,   187,   188,
     151,   152,   153,   154,   225,   206,   215,   216,   226,   198,
     228,   200,   201,   231,   222,   223,   103,   218,   219,   215,
     216,   225,   231,   227,   232,   226,   124,   125,   215,   216,
     234,   514,   130,   234,   231,   231,   233,   226,   225,   228,
     202,   203,   204,   205,   226,   232,   228,  2171,   215,   216,
     232,   252,   215,   216,   226,   124,   125,   126,   127,   231,
     222,   223,   263,    90,   231,   548,   549,   225,   231,   552,
     139,   215,   216,   142,   222,   223,   225,     8,    87,     6,
     563,    90,   233,    92,   232,   568,    90,   231,   202,   203,
     204,   205,   575,   202,   203,   204,   205,     6,     7,   385,
     202,   203,   204,   205,   217,   218,   219,   308,   222,   223,
     225,   224,   227,   222,   223,   598,   599,   915,   225,   234,
     588,   589,   590,   591,   232,   697,   202,   203,   204,   205,
     225,   613,   614,    90,     4,   225,    92,   227,   215,   216,
     225,   215,   216,    87,   234,   431,   232,   433,   434,   435,
     436,   437,   438,   439,   231,   441,   442,   231,   444,   445,
     446,   232,   448,   646,   647,   648,   452,   453,   454,   455,
     456,   226,   215,   216,   611,   612,   231,   225,   231,   227,
     233,   753,   619,   225,   385,   757,   234,   670,   231,    90,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   215,   216,    87,   690,   224,    87,
     215,   216,     6,     7,    84,   222,   223,   233,    88,   988,
     231,    90,   229,   992,    94,    95,   231,    97,    98,   430,
     431,   432,   433,   434,   435,   436,   437,   438,   439,     4,
     441,   442,   112,   444,   445,   446,   447,   448,   215,   216,
       4,   452,   453,   454,   455,   456,   457,   226,   459,   228,
       4,   225,   231,   227,   231,   229,   552,     4,   232,   752,
     234,   119,   844,   756,   225,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   137,
     758,   226,  1073,   224,   215,   216,   231,   145,   146,   147,
     215,   216,   233,   151,   152,   153,   154,   119,   225,   231,
     231,   233,   215,   216,   797,   226,   231,   228,   801,   225,
     231,   804,   578,   225,   807,   137,   809,   119,   231,   225,
     813,   814,     6,   145,   146,   147,   215,   216,     6,   151,
     152,   153,   154,   811,   231,   137,   233,   227,   549,   215,
     216,   552,   231,   145,   146,   147,   227,   215,   216,   151,
     152,   153,   154,   225,   847,   231,   849,     7,    84,   852,
     225,    87,  1964,   231,    90,  1967,    92,   231,  1970,   233,
     225,   231,   865,   233,   867,   233,   869,   226,   871,   228,
    1882,   227,  1884,   876,  1886,  1301,  1302,   231,   881,   233,
    1306,  1307,   215,   216,   119,   888,   226,   215,   216,   215,
     216,   231,   231,  1182,   233,  1184,   988,  1186,   231,  1188,
     992,   233,   137,   231,  1222,   231,   998,   999,   226,   912,
     145,   146,   147,   231,   222,   223,   151,   152,   153,   154,
     228,   233,   698,   699,   700,   701,   702,   703,   704,   705,
     706,   707,   708,   225,   710,   711,   712,   713,   714,   715,
     716,   124,   125,   225,   720,   721,   722,   130,     8,    84,
     726,   727,    87,   729,   231,    90,   233,    92,   734,   735,
     736,   918,   738,   225,   231,   227,   233,   229,   925,   745,
     746,   225,   234,   226,   225,   228,   933,     6,   231,  2091,
     983,   225,   225,   227,   987,   229,   225,   763,   991,   226,
     234,   228,   215,   216,   231,   226,   999,   228,   804,   231,
     231,   233,   232,   809,  1096,  1097,   211,   212,   213,   214,
     215,   216,   217,   218,   219,  1316,   232,  1622,  1623,   224,
    1309,  1024,   231,   226,   233,   228,  1029,  2039,   231,     6,
     225,  1034,  1035,  1036,  1037,   231,   225,   233,  1327,  2151,
     232,   231,  2154,   233,  1047,  2157,  1049,   231,  2160,   233,
       6,   225,  1144,  1145,    90,   225,    92,  1483,  1484,    90,
     225,    92,  1488,  1489,   231,   231,   233,   233,   232,   231,
    1073,   233,   110,  1076,  1077,  1078,  1079,  1169,  1170,   232,
     225,   857,     6,   804,   232,   231,   807,   233,   809,  2201,
     231,  2203,   233,  2205,   231,   231,   233,   233,   225,   231,
    1103,   233,   231,   231,   233,   233,  2118,   231,  2120,   233,
    2122,   231,   231,   233,   233,   231,  2128,   233,   225,  1122,
    1123,   231,  1125,   233,  1127,  1128,   225,   225,  1131,  1132,
    1133,  1134,  1135,  1136,  1137,  1138,   231,   225,   233,  1142,
     231,     4,   233,     6,   225,     4,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
    1478,  1118,  1480,  1166,   224,   231,   226,   233,   232,  1172,
    2182,   232,  2184,   231,  2186,   233,   232,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   232,   119,   999,   231,   224,   233,   231,   231,   233,
     233,   231,   234,   233,  1493,   231,   231,   233,   233,   232,
     137,     6,   231,   231,   233,   233,   225,  1309,   145,   146,
     147,   225,   225,  1029,   151,   152,   153,   154,   225,  1035,
    1036,  1037,  1235,  1534,   225,   231,   119,   233,   231,   225,
     233,  1047,   231,  1049,   233,  1248,  1249,  1250,   227,   225,
    1207,  1208,  1209,   231,   137,   233,     6,   231,   231,   233,
     233,  1264,   145,   146,   147,   231,   225,   233,   151,   152,
     153,   154,  1877,   231,   231,   233,   233,   231,   999,   233,
       6,     6,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   232,  1103,  1301,  1302,
     224,   232,   232,  1306,  1307,     6,   233,  1083,  1029,   231,
     231,   233,   233,  1316,  1035,  1036,  1037,   231,   231,   233,
     233,   231,   231,   233,   233,   231,  1047,   233,  1049,  1332,
     231,   231,   233,   233,   227,   227,   227,     6,   232,   170,
    1116,  1117,     6,     6,   234,   232,     6,     6,   232,     6,
     233,   232,  1073,  1356,     7,     8,   227,   119,  1346,  1362,
       4,   229,   224,   232,     7,   231,   233,   231,   226,     7,
       6,  1374,     6,     6,   226,   137,     4,    62,    62,    62,
      62,     7,  1103,   145,   146,   147,     7,   226,     6,   151,
     152,   153,   154,  1396,  1397,  1398,     6,     6,     6,  1402,
    1403,  1827,  1405,  1495,  1407,   232,  1409,   119,  1411,  1412,
    1413,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   137,     7,     6,  1431,   224,
       7,     6,     6,   145,   146,   147,     6,   167,   232,   151,
     152,   153,   154,   228,  1447,   226,     6,     6,   226,   226,
     226,   231,  1455,   226,   226,  1458,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     231,   233,   231,   231,   224,   231,   231,   231,    44,   228,
    1483,  1484,    44,    44,     6,  1488,  1489,    44,  1445,  1477,
       4,   225,     4,   170,   170,  1587,     6,     6,     6,  1502,
     119,     6,  1278,     7,     7,  1508,     7,     7,  1284,  1285,
    1286,  1287,  1288,     7,  1290,     7,  1292,  1293,   137,  1295,
    1296,   233,   170,  1299,  1300,  1301,   145,   146,   147,     7,
    1306,  1534,   151,   152,   153,   154,  1837,     7,  1526,  1542,
       7,     7,     7,     7,     7,     7,   232,     6,   226,  1552,
       7,   232,  1555,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,  1555,     7,     4,
     119,   224,   228,     6,   232,  1893,   226,   232,   232,   231,
    1301,  1302,   231,   229,   226,  1306,  1307,   226,   137,   226,
     231,   231,   119,     7,     6,  1316,   145,   146,   147,     7,
     232,  1377,   151,   152,   153,   154,   119,     7,  1565,   233,
     233,  1614,  1615,     7,   233,   229,     7,   233,  1394,   232,
    1622,  1623,     6,    44,   137,    44,    44,  1630,   119,    44,
    1618,     6,   145,   146,   147,     6,     6,     6,   151,   152,
     153,   154,     6,  1646,     7,   227,   137,     6,   232,  1652,
       6,    92,     6,   225,   145,   146,   147,   225,  1661,   212,
     151,   152,   153,   154,     7,     7,     7,  1624,  1671,  1626,
     225,  1628,  1990,     7,     7,     4,     7,     7,  1681,  1667,
       6,    87,     7,  1686,   233,     7,     7,     7,     7,     7,
    1647,  1648,  1649,  1650,  1651,  1652,  1502,   119,  1686,  1687,
    1688,     4,  1508,   232,     6,   225,     7,  1483,     6,   232,
    1713,     7,  1488,     7,     7,   137,     7,     7,     7,     7,
     233,     6,  2040,   145,   146,   147,   260,   261,   262,   151,
     152,   153,   154,  1736,     6,     6,     6,    90,     7,     6,
       4,     4,   233,     4,  1520,  1521,  1552,   231,  1524,  1525,
     232,   232,     6,   233,     6,     6,     6,     6,     4,   293,
     294,   295,  1483,  1484,     6,     6,   226,  1488,  1489,     7,
     231,   226,     6,     6,   225,   231,   229,   226,  1781,   229,
     232,  1502,   228,     6,     6,   232,     6,  1508,   232,   112,
     232,  1794,   232,     6,     6,   232,     6,     6,     6,     6,
     334,   335,     6,     6,  1807,     6,     6,     6,     5,     4,
     226,   233,     6,  1534,   348,   349,     6,   228,     4,     6,
     166,  1824,  1810,   232,  1827,   232,     7,   232,   232,   232,
     227,  1552,     6,     6,  1837,     6,     6,   232,     6,   232,
     232,     6,   232,  1846,   232,   232,   232,     6,     6,   231,
    1853,  1854,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,     6,     4,  1871,     4,
     224,  1874,     6,     6,     6,  1877,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,  1891,     6,
       6,     6,   224,  1896,     6,     6,     4,     7,  1674,  1675,
       7,     6,  1678,  1679,     6,     6,     6,     5,  1684,  1685,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,     6,   232,     6,  1881,   224,  1883,   170,  1885,     6,
       6,     6,     6,     6,     6,     6,     6,     6,     6,     6,
    1897,  1898,  1899,  1900,  1901,   231,     6,     6,   120,     6,
    1953,     6,   231,     6,     6,     6,     6,     6,   226,     6,
       6,  1737,  1738,     7,     6,     6,   232,   229,     6,  1972,
      88,     6,  1975,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   232,   232,     6,
       6,   224,  1995,    12,    13,  1952,     5,   232,     6,  1956,
     232,     6,   233,   233,   232,   232,  1994,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   232,     7,     6,    90,   224,   165,   233,     6,     6,
     232,     6,     6,     6,     6,   233,     6,   233,   168,  2042,
    2043,  2044,  2045,  2046,   233,     6,     6,     6,     6,     6,
       6,     6,   232,     6,   232,  2058,     6,   226,  2015,     6,
     226,     7,  2019,     6,     6,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,   232,   232,
     232,   100,   101,   102,   232,   104,   232,     6,   233,  2046,
     109,   110,   111,   112,   113,     8,   115,   116,   117,     6,
       6,   119,     6,   122,   232,     6,  1827,     6,     6,     6,
       6,     6,     6,  2101,     6,     6,  1837,   136,     6,   233,
     233,   225,     6,   232,     6,     6,   232,     6,     6,   232,
    2133,     6,     6,     6,   233,   105,  2139,   232,     6,     6,
     232,     6,   232,   162,   163,   164,   232,     6,   232,     6,
     232,     6,     6,     6,     6,     6,     6,     6,     6,  2116,
    2117,     6,     6,     6,  1341,  1998,   510,  1852,  2171,     6,
    1355,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,     3,  2189,     3,  2191,   224,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,     3,     3,   586,  1873,   224,  1530,
      -1,    -1,    -1,    -1,   233,    -1,    -1,    -1,  2221,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     200,   201,   202,   203,   204,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   217,    -1,    -1,
      -1,   221,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   235,   236,   237,   238,    -1,
     240,   241,   242,   243,  1995,   245,   246,   247,   248,   249,
     250,   251,    -1,   253,   254,     6,    -1,    -1,    -1,   259,
      -1,    -1,    -1,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   277,   278,   279,
      -1,   224,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   289,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2139,    -1,   305,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   314,   315,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   323,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   333,    -1,    -1,    -1,    -1,  2144,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,  2189,   354,  2191,    -1,   224,   358,   359,
     360,    -1,   362,    -1,    -1,    -1,   366,   367,   368,    -1,
      -1,   371,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2221,   386,    -1,  2139,    -1,
      -1,   391,   392,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   405,   406,    -1,   408,   409,
     410,   411,   412,   413,   414,   415,   416,   417,   418,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2189,    -1,
    2191,    -1,    -1,   443,    -1,    -1,    -1,    -1,    -1,   449,
      -1,   451,    -1,    -1,     6,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,    -1,
    2221,    -1,    -1,   224,    -1,   475,   476,    -1,   478,   479,
     480,   481,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   236,    -1,   495,   496,    -1,   241,    -1,
      -1,    -1,   245,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   514,    -1,   259,    -1,    -1,    -1,
     520,    -1,    -1,    -1,    -1,   525,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   537,   538,    -1,
      -1,    -1,    -1,    -1,   544,   545,    -1,    -1,   548,   549,
     550,   551,    -1,   553,    -1,    -1,   556,    -1,    -1,    -1,
       6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   568,    -1,
      -1,    -1,    -1,    -1,   574,   575,   576,   577,    -1,    -1,
     580,   581,   582,    -1,    21,    22,    -1,   587,   588,   589,
     590,   591,   592,    -1,   594,    -1,   596,    -1,   598,   599,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   616,   617,   618,   619,
     620,   621,    -1,    -1,    -1,    -1,   626,   627,   628,   629,
     630,   631,   632,   633,   634,    -1,    -1,    -1,    -1,   639,
      -1,   641,   642,    -1,    -1,    -1,   646,   647,   648,    -1,
      -1,   651,   652,   653,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,    -1,    -1,
     670,    -1,   224,    -1,    -1,   675,   676,    -1,   678,   679,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     6,   689,
     690,    -1,   129,    -1,   694,    -1,    -1,    -1,    -1,    -1,
      -1,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,    -1,    -1,     6,   166,
     167,   168,   169,   476,   171,   172,   173,   174,   175,   176,
      -1,    -1,   179,    -1,    -1,    -1,    -1,    -1,   185,   186,
       6,    -1,    -1,    -1,   191,   192,    -1,    -1,    -1,   759,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,    -1,    -1,    -1,    -1,   224,    -1,
      -1,     6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   793,   794,    -1,    -1,   797,   798,   799,
      -1,   801,   802,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     810,    -1,    -1,   813,   814,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   568,    -1,   264,    -1,   266,
     267,   268,   269,    -1,   834,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   847,    -1,   849,
     287,    -1,   852,    -1,    -1,   598,   599,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   865,    -1,   867,    -1,   869,
      -1,   871,    -1,    -1,    -1,    -1,   876,    -1,    -1,    -1,
      -1,   881,    -1,    -1,    -1,    -1,    -1,   887,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,    -1,   646,   647,   648,   224,    -1,    -1,    -1,
      -1,    -1,   912,    -1,    -1,    -1,    -1,    -1,    -1,   919,
     920,    -1,    -1,    -1,    -1,   925,    -1,   670,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,    -1,    -1,    -1,   945,   224,   690,   948,    -1,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,    -1,    -1,    -1,   967,   224,   969,
     970,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     980,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,    -1,    46,    -1,    -1,   224,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1012,    12,    13,    -1,    -1,    -1,    -1,    -1,
    1020,  1021,  1022,    -1,  1024,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1032,   470,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1046,    -1,    -1,    -1,
      -1,  1051,    -1,    -1,   797,    -1,    -1,    -1,   801,    -1,
    1060,    -1,    -1,    -1,    -1,    -1,  1066,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1076,  1077,  1078,  1079,
    1080,    -1,    -1,    -1,  1084,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,     6,    -1,
      -1,   100,   101,   102,   847,   104,   849,    -1,    -1,   852,
     109,   110,   111,   112,   113,    -1,   115,   116,   117,    -1,
      -1,    -1,   865,   122,   867,    -1,   869,    -1,   871,    -1,
      -1,    -1,    -1,   876,    -1,    -1,    -1,   136,   881,    -1,
      -1,    -1,  1142,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1152,  1153,    -1,  1155,  1156,    -1,  1158,  1159,
    1160,    -1,    -1,   162,   163,   164,    -1,  1167,    -1,   912,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1183,    -1,  1185,    -1,  1187,    -1,  1189,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,    -1,   255,    -1,    -1,   224,    -1,
      -1,    -1,  1212,    -1,    -1,   231,    -1,   233,    -1,    -1,
      -1,    -1,    -1,    -1,   274,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   233,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   292,    -1,    -1,    -1,    -1,  1247,    -1,    -1,
      -1,   301,   302,   303,    -1,    -1,    -1,   307,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1270,    -1,    -1,    -1,    -1,  1275,     7,    -1,    -1,    -1,
      -1,  1024,    -1,    -1,    12,    13,   336,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,    -1,    -1,    -1,    -1,   224,  1317,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1326,    -1,    -1,    -1,
    1330,  1331,    -1,  1076,  1077,  1078,  1079,    -1,    -1,   389,
     390,    -1,    -1,    -1,    -1,  1345,  1346,    -1,    -1,    -1,
      -1,     8,   402,    -1,    -1,    -1,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    -1,
      -1,    -1,   100,   101,   102,    -1,   104,    -1,    -1,    -1,
      -1,   109,   110,   111,   112,   113,    -1,   115,   116,   117,
     440,    -1,    -1,    -1,   122,    -1,    -1,    -1,    -1,  1142,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   136,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1419,
    1420,  1421,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1431,    -1,  1433,   162,   163,   164,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1445,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     4,     5,    -1,    -1,  1458,    -1,
      -1,    -1,    -1,  1463,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1471,  1472,  1473,    -1,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,    -1,
      -1,    -1,    -1,   224,    44,    45,    46,    47,    48,    49,
      50,    51,    52,  1503,    -1,   233,    -1,    57,    58,    59,
      60,    -1,    -1,   563,    -1,    65,    66,    67,    -1,    -1,
      70,    -1,    -1,    -1,    -1,    -1,    -1,  1527,    -1,    -1,
      -1,    81,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1543,    -1,    -1,    -1,    -1,  1548,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,  1563,  1564,    -1,    -1,   224,    -1,    -1,
    1570,  1571,    -1,    -1,    -1,  1575,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1591,  1592,  1593,  1594,  1595,  1596,  1597,    -1,    -1,
      -1,    -1,    -1,    -1,  1604,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1614,  1615,  1616,    -1,  1618,  1056,
    1057,    -1,    -1,    -1,    -1,  1062,  1063,    -1,    -1,    -1,
      -1,  1631,    -1,    -1,    -1,    -1,   186,   187,   188,    -1,
     236,    -1,    -1,    -1,    -1,   241,    -1,    -1,   198,   245,
     200,   201,  1652,    -1,    -1,    -1,  1656,    -1,    12,    13,
      -1,    -1,    -1,   259,    -1,    -1,    -1,  1667,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   277,    -1,   279,    -1,    -1,    -1,  1687,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   752,    -1,    -1,    -1,   756,    -1,    -1,    -1,
      -1,  1711,  1712,    -1,    -1,  1458,    -1,    -1,    -1,  1719,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    -1,    -1,    -1,   100,   101,   102,    -1,
     104,    -1,    -1,    -1,    -1,   109,   110,   111,   112,   113,
      -1,   115,   116,   117,    -1,  1765,    -1,    -1,   122,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   136,    -1,    -1,  1785,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1794,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1802,    -1,  1804,    -1,    -1,  1807,   162,   163,
     164,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1824,    -1,    -1,    -1,    -1,    -1,
    1267,  1268,    -1,    -1,    -1,  1272,  1273,    -1,   888,    -1,
      -1,    -1,  1842,    -1,    -1,    -1,    -1,  1847,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1864,  1865,  1866,  1867,  1868,    -1,
      -1,  1614,  1615,    -1,  1874,    -1,    -1,    -1,    -1,   233,
     476,  1881,    -1,  1883,    -1,  1885,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1896,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1904,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   514,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1927,  1928,    -1,
      -1,    -1,  1932,   983,    -1,    -1,     8,   987,    -1,    -1,
      -1,   991,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1949,
      -1,    -1,   548,   549,    -1,    -1,     8,    -1,    -1,    -1,
    1960,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   568,    -1,    -1,    -1,    -1,    -1,    -1,   575,
      -1,    -1,    -1,    -1,  1034,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1992,    -1,    -1,    -1,    -1,    -1,  1998,    -1,
      -1,    -1,   598,   599,    -1,    -1,    -1,  2007,  2008,  2009,
    2010,  2011,  2012,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     8,    -1,    -1,    -1,    -1,  2026,    -1,    -1,  2029,
      -1,    -1,  2032,    -1,    -1,    -1,  2036,    -1,    -1,    -1,
      -1,    -1,  2042,  2043,  2044,  2045,  2046,    -1,    -1,    -1,
     646,   647,   648,    -1,    -1,    -1,  2056,    -1,    -1,  2059,
      -1,    -1,    -1,    -1,  1807,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1122,  1123,   670,  1125,    -1,  1127,  1128,    -1,
      -1,  1131,  1132,  1133,  1134,  1135,  1136,  1137,  1138,    -1,
      -1,    -1,    -1,    -1,   690,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2110,  2111,  2112,  2113,  2114,  2115,  1166,    -1,    -1,    -1,
      -1,    -1,  1172,    -1,    -1,    -1,    -1,     8,    -1,    -1,
      -1,  1874,    -1,  2133,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,    -1,    -1,
      -1,    -1,   224,  1896,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,    -1,    -1,
      -1,    -1,   224,    -1,    -1,  2175,  2176,  2177,  2178,  2179,
    2180,    -1,    -1,    -1,    -1,  1235,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1248,  1249,
    1250,   797,    -1,    -1,    -1,   801,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1264,    -1,    -1,   813,   814,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,    -1,    -1,    -1,    -1,   224,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   847,    -1,   849,    -1,    -1,   852,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   865,
      -1,   867,    -1,   869,    -1,   871,    -1,   119,    -1,    -1,
     876,    -1,  1332,    -1,    -1,   881,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2042,
    2043,  2044,  2045,  2046,    -1,    -1,  1356,    -1,    -1,    -1,
      -1,    -1,  1362,    -1,    -1,    -1,   912,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1374,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,    -1,
      -1,    -1,    -1,   224,    -1,    -1,  1396,  1397,  1398,    -1,
      -1,    -1,  1402,  1403,    -1,  1405,    -1,  1407,    -1,  1409,
      -1,  1411,  1412,  1413,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,    -1,    -1,
      -1,  1431,   224,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2133,    -1,    -1,    -1,    -1,    -1,    -1,  1447,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1455,    -1,    -1,    -1,    -1,
      -1,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,    -1,     3,     4,  1024,   224,
      -1,   226,     9,    10,    11,    -1,   231,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    53,    54,    55,    56,
    1076,  1077,  1078,  1079,    61,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1542,    -1,    -1,    72,    73,    74,    -1,    -1,
      -1,    -1,    -1,    80,    -1,  1555,     3,     4,     5,    -1,
      -1,    -1,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      -1,    -1,    -1,    -1,    -1,    -1,  1142,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    -1,    -1,    -1,    65,    66,
      67,    -1,    -1,    70,    -1,    72,    73,    74,    -1,    -1,
    1630,    -1,    -1,    80,    81,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1646,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   185,    -1,
      -1,  1661,   189,    -1,    -1,    -1,   193,   194,   195,   196,
     197,  1671,    -1,    -1,   201,    -1,    -1,    -1,    -1,    -1,
      -1,  1681,    -1,    -1,    -1,    -1,  1686,    -1,   215,   216,
      -1,    -1,    -1,   220,    -1,    -1,    -1,    -1,   225,    -1,
      -1,    -1,    -1,   230,    -1,   232,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1713,    -1,    -1,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
      -1,   178,    -1,    -1,   224,    -1,  1736,    -1,   185,   186,
     187,   188,   189,   233,    -1,    -1,   193,   194,   195,   196,
     197,   198,    -1,   200,   201,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   215,   216,
      -1,    -1,    -1,   220,    -1,    -1,    -1,    -1,   225,    -1,
     227,  1781,   229,   230,    -1,   232,    -1,   234,    -1,    -1,
      -1,    -1,     3,     4,    -1,    -1,    -1,    -1,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    53,    54,    55,    56,  1846,    -1,    -1,    -1,
      61,    -1,    -1,  1853,  1854,    -1,    -1,    -1,    -1,    -1,
      -1,    72,    73,    74,    -1,    -1,    -1,    -1,    -1,    80,
      -1,  1871,    -1,    84,    -1,    -1,    87,    -1,    -1,    90,
      -1,    92,    -1,    -1,    -1,    -1,    -1,    -1,    99,    -1,
      -1,  1891,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   110,
      -1,    -1,   113,    -1,    -1,   116,    -1,    -1,    -1,    -1,
      -1,    -1,  1458,   124,   125,   126,   127,   128,    -1,    -1,
     131,   132,   133,   134,   135,    -1,    -1,    -1,   139,    -1,
      -1,   142,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,    -1,    -1,    -1,    -1,
     224,    -1,    -1,  1953,    -1,    -1,    -1,   231,    -1,   233,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1972,    -1,   185,  1975,    -1,    -1,   189,    -1,
      -1,    -1,   193,   194,   195,   196,   197,    -1,    -1,    -1,
     201,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   215,   216,    -1,    -1,    -1,   220,
      -1,    -1,    -1,    -1,   225,    -1,    -1,    -1,    -1,   230,
      -1,   232,   233,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,    -1,    -1,    -1,
      -1,   224,    -1,    -1,    -1,    -1,    -1,    -1,   231,    -1,
     233,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2058,     3,
       4,    -1,    -1,    -1,    -1,     9,    10,    11,  1614,  1615,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1652,    -1,    -1,    53,
      54,    55,    56,    -1,    -1,    -1,    -1,    61,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,    73,
      74,    -1,    -1,    -1,    -1,    -1,    80,    -1,    -1,    -1,
      84,    -1,    -1,    87,    -1,    -1,    90,    -1,    92,    -1,
      -1,    -1,    -1,    -1,    -1,    99,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   110,    -1,    -1,   113,
      -1,  2171,   116,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     124,   125,   126,   127,   128,    -1,    -1,   131,   132,   133,
     134,   135,    -1,    -1,    -1,   139,    -1,    -1,   142,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,    -1,    -1,    -1,    -1,   224,    -1,    -1,
      -1,    -1,    -1,    -1,   231,    -1,   233,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   185,    -1,    -1,    -1,   189,    -1,    -1,  1794,   193,
     194,   195,   196,   197,    -1,     4,     5,   201,    -1,    -1,
      -1,  1807,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   215,   216,    -1,    -1,    -1,   220,    -1,  1824,    -1,
      -1,   225,    -1,    -1,    -1,    -1,   230,    -1,    -1,   233,
      -1,    -1,    -1,    -1,    -1,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    -1,    -1,    -1,    -1,    57,    58,
      59,    60,    -1,    -1,    -1,    -1,    65,    66,    67,    -1,
      -1,    70,    -1,    -1,    -1,    -1,    -1,    -1,  1874,    -1,
      -1,    -1,    81,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,    -1,    -1,    -1,     9,    10,    11,    -1,
    1896,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    -1,
      -1,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    -1,
      -1,    -1,    65,    66,    67,    -1,    -1,    70,    -1,    72,
      73,    74,    -1,    -1,    -1,    -1,    -1,    80,    81,    -1,
      -1,    84,    -1,    -1,    87,    -1,    -1,    90,    -1,    92,
      -1,    -1,    -1,    -1,    -1,    -1,    99,   186,   187,   188,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   110,    -1,   198,
     113,   200,   201,   116,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   124,   125,   126,   127,   128,    -1,    -1,   131,   132,
     133,   134,   135,    -1,    -1,    -1,   139,    -1,    -1,   142,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2042,  2043,  2044,  2045,
    2046,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,    -1,    -1,    -1,    -1,   224,
      -1,    -1,   185,   186,   187,   188,   189,    -1,   233,    -1,
     193,   194,   195,   196,   197,   198,    -1,   200,   201,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   215,   216,    -1,    -1,    -1,   220,    -1,    -1,
      -1,    -1,   225,    -1,    -1,    -1,    -1,   230,    -1,   232,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
      -1,    -1,    -1,     9,    10,    11,    -1,  2133,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    -1,    -1,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    -1,    -1,    -1,    65,
      66,    67,    -1,    -1,    70,    -1,    72,    73,    74,    -1,
      -1,    -1,    -1,    -1,    80,    81,    -1,    -1,    84,    -1,
      -1,    87,    -1,    -1,    90,    -1,    92,    -1,    -1,    -1,
      -1,    -1,    -1,    99,    -1,    -1,    -1,    -1,    -1,     4,
       5,    -1,    -1,    -1,   110,    -1,    -1,   113,    -1,    -1,
     116,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   124,   125,
     126,   127,   128,    -1,    -1,   131,   132,   133,   134,   135,
      -1,    -1,    -1,   139,    -1,    -1,   142,    -1,    -1,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    -1,    -1,
      -1,    -1,    57,    58,    59,    60,    -1,    -1,    -1,    -1,
      65,    66,    67,    -1,    -1,    70,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    81,    -1,    -1,   185,
     186,   187,   188,   189,    -1,    -1,    -1,   193,   194,   195,
     196,   197,   198,    -1,   200,   201,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   215,
     216,    -1,    -1,    -1,   220,    -1,    -1,    -1,    -1,   225,
      -1,     3,     4,     5,   230,    -1,   232,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    53,    54,    55,    56,    -1,    -1,    -1,    -1,    61,
      -1,   186,   187,   188,    -1,    -1,    -1,    -1,    -1,    -1,
      72,    73,    74,   198,    -1,   200,    -1,    -1,    80,    -1,
      -1,    -1,    84,    -1,    -1,    87,    -1,    -1,    90,    -1,
      92,    -1,    -1,    -1,    -1,    -1,    -1,    99,    -1,    -1,
      -1,    -1,    -1,    -1,     5,    -1,    -1,    -1,   110,    -1,
      -1,   113,    -1,    -1,   116,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   124,   125,   126,   127,   128,    -1,    -1,   131,
     132,   133,   134,   135,    -1,    -1,    -1,   139,    -1,    -1,
     142,    -1,    -1,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    -1,    -1,    -1,    -1,    57,    58,    59,    60,
      -1,    -1,    -1,    -1,    65,    66,    67,    -1,    -1,    70,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      81,    -1,    -1,   185,    -1,    -1,    -1,   189,    -1,    -1,
      -1,   193,   194,   195,   196,   197,    -1,    -1,    -1,   201,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   215,   216,    -1,    -1,    -1,   220,    -1,
      -1,    -1,    -1,   225,    -1,     3,     4,     5,   230,    -1,
     232,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    53,    54,    55,    56,    -1,
      -1,    -1,    -1,    61,    -1,   186,   187,   188,    -1,    -1,
      -1,    -1,    -1,    -1,    72,    73,    74,   198,    -1,   200,
      -1,    -1,    80,    -1,    -1,    -1,    84,    -1,    -1,    87,
      -1,    -1,    90,    -1,    92,    -1,    -1,    -1,    -1,    -1,
      -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   110,    -1,    -1,   113,    -1,    -1,   116,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   124,   125,   126,   127,
     128,    -1,    -1,   131,   132,   133,   134,   135,    -1,    -1,
      -1,   139,    -1,    -1,   142,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,    -1,
      -1,    -1,    -1,   224,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   233,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   185,    -1,    -1,
      -1,   189,    -1,    -1,    -1,   193,   194,   195,   196,   197,
      -1,    -1,    -1,   201,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   215,   216,    -1,
      -1,    -1,   220,    -1,    -1,    -1,    -1,   225,    -1,     3,
       4,    -1,   230,    -1,   232,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,
      54,    55,    56,    -1,    -1,    -1,    -1,    61,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,    73,
      74,    -1,    -1,    -1,    -1,    -1,    80,    -1,    -1,    -1,
      84,    -1,    -1,    87,    -1,    -1,    90,    -1,    92,    -1,
      -1,    -1,    -1,    -1,    -1,    99,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   110,    -1,    -1,   113,
      -1,    -1,   116,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     124,   125,   126,   127,   128,    -1,    -1,   131,   132,   133,
     134,   135,    -1,    -1,    -1,   139,    -1,    -1,   142,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,    -1,    -1,    -1,    -1,   224,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   233,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   185,    -1,    -1,    -1,   189,    -1,    -1,    -1,   193,
     194,   195,   196,   197,    -1,    -1,    -1,   201,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   215,   216,    -1,    -1,    -1,   220,    -1,    -1,    -1,
      -1,   225,    -1,     3,     4,    -1,   230,    -1,   232,     9,
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
     110,    -1,    -1,   113,    -1,    -1,   116,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   124,   125,   126,   127,   128,    -1,
      -1,   131,   132,   133,   134,   135,    -1,    -1,    -1,   139,
      -1,    -1,   142,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,    -1,    -1,    -1,
      -1,   224,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     233,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   185,    -1,    -1,    -1,   189,
      -1,    -1,    -1,   193,   194,   195,   196,   197,    -1,    -1,
      -1,   201,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   215,   216,    -1,    -1,    -1,
     220,    -1,    -1,    -1,    -1,   225,    -1,     3,     4,    -1,
     230,    -1,   232,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,    54,    55,
      56,    -1,    -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    72,    73,    74,    -1,
      -1,    -1,    -1,    -1,    80,    -1,    -1,    -1,    84,    -1,
      -1,    87,    -1,    -1,    90,    -1,    92,    -1,    -1,    -1,
      -1,    -1,    -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   110,    -1,    -1,   113,    -1,    -1,
     116,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   124,   125,
     126,   127,   128,    -1,    -1,   131,   132,   133,   134,   135,
      -1,    -1,    -1,   139,    -1,    -1,   142,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,    -1,    -1,    -1,    -1,   224,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   233,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   185,
      -1,    -1,    -1,   189,    -1,    -1,    -1,   193,   194,   195,
     196,   197,    -1,    -1,    -1,   201,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   215,
     216,    -1,    -1,    -1,   220,    -1,    -1,    -1,    -1,   225,
      -1,     3,     4,    -1,   230,    -1,   232,     9,    10,    11,
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
      -1,   113,    -1,    -1,   116,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   124,   125,   126,   127,   128,    -1,    -1,   131,
     132,   133,   134,   135,    -1,    -1,    -1,   139,    -1,    -1,
     142,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,    -1,    -1,    -1,    -1,   224,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   233,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   185,    -1,    -1,    -1,   189,    -1,    -1,
      -1,   193,   194,   195,   196,   197,    -1,    -1,    -1,   201,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   215,   216,    -1,    -1,    -1,   220,    -1,
      -1,    -1,    -1,   225,    -1,     3,     4,    -1,   230,    -1,
     232,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    53,    54,    55,    56,    -1,
      -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    72,    73,    74,    -1,    -1,    -1,
      -1,    -1,    80,    -1,    -1,    -1,    84,    -1,    -1,    87,
      -1,    -1,    90,    -1,    92,    -1,    -1,    -1,    -1,    -1,
      -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   110,    -1,    -1,   113,    -1,    -1,   116,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   124,   125,   126,   127,
     128,    -1,    -1,   131,   132,   133,   134,   135,    -1,    -1,
      -1,   139,    -1,    -1,   142,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,    -1,
      -1,    -1,    -1,   224,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   233,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   185,    -1,    -1,
      -1,   189,    -1,    -1,    -1,   193,   194,   195,   196,   197,
      -1,    -1,    -1,   201,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   215,   216,    -1,
      -1,    -1,   220,    -1,    -1,    -1,    -1,   225,    -1,     3,
       4,    -1,   230,    -1,   232,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,
      54,    55,    56,    -1,    -1,    -1,    -1,    61,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,    73,
      74,    -1,    -1,    -1,    -1,    -1,    80,    -1,    -1,    -1,
      84,    -1,    -1,    87,    -1,    -1,    90,    -1,    92,    -1,
      -1,    -1,    -1,    -1,    -1,    99,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   110,    -1,    -1,   113,
      -1,    -1,   116,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     124,   125,   126,   127,   128,    -1,    -1,   131,   132,   133,
     134,   135,    -1,    -1,    -1,   139,    -1,    -1,   142,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,    -1,    -1,    -1,    -1,   224,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   233,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   185,    -1,    -1,    -1,   189,    -1,    -1,    -1,   193,
     194,   195,   196,   197,    -1,    -1,    -1,   201,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   215,   216,    -1,    -1,    -1,   220,    -1,    -1,    -1,
      -1,   225,    -1,     3,     4,    -1,   230,    -1,   232,     9,
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
     110,    -1,    -1,   113,    -1,    -1,   116,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   124,   125,   126,   127,   128,    -1,
      -1,   131,   132,   133,   134,   135,    -1,    -1,    -1,   139,
      -1,    -1,   142,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,    -1,    -1,    -1,
      -1,   224,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     233,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   185,    -1,    -1,    -1,   189,
      -1,    -1,    -1,   193,   194,   195,   196,   197,    -1,    -1,
      -1,   201,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   215,   216,    -1,    -1,    -1,
     220,    -1,    -1,    -1,    -1,   225,    -1,     3,     4,    -1,
     230,    -1,   232,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,    54,    55,
      56,    -1,    -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    72,    73,    74,    -1,
      -1,    -1,    -1,    -1,    80,    -1,    -1,    -1,    84,    -1,
      -1,    87,    -1,    -1,    90,    -1,    92,    -1,    -1,    -1,
      -1,    -1,    -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   110,    -1,    -1,   113,    -1,    -1,
     116,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   124,   125,
     126,   127,   128,    -1,    -1,   131,   132,   133,   134,   135,
      -1,    -1,    -1,   139,    -1,    -1,   142,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,    -1,    -1,    -1,    -1,   224,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   233,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   185,
      -1,    -1,    -1,   189,    -1,    -1,    -1,   193,   194,   195,
     196,   197,    -1,    -1,    -1,   201,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   215,
     216,    -1,    -1,    -1,   220,    -1,    -1,    -1,    -1,   225,
      -1,     3,     4,    -1,   230,    -1,   232,     9,    10,    11,
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
      -1,   113,    -1,    -1,   116,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   124,   125,   126,   127,   128,    -1,    -1,   131,
     132,   133,   134,   135,    -1,    -1,    -1,   139,    -1,    -1,
     142,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,    -1,    -1,    -1,    -1,   224,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   233,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   185,    -1,    -1,    -1,   189,    -1,    -1,
      -1,   193,   194,   195,   196,   197,    -1,    -1,    -1,   201,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   215,   216,    -1,    -1,    -1,   220,    -1,
      -1,    -1,    -1,   225,    -1,     3,     4,    -1,   230,    -1,
     232,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    53,    54,    55,    56,    -1,
      -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    72,    73,    74,    -1,    -1,    -1,
      -1,    -1,    80,    -1,    -1,    -1,    84,    -1,    -1,    87,
      -1,    -1,    90,    -1,    92,    -1,    -1,    -1,    -1,    -1,
      -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   110,    -1,    -1,   113,    -1,    -1,   116,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   124,   125,   126,   127,
     128,    -1,    -1,   131,   132,   133,   134,   135,    -1,    -1,
      -1,   139,    -1,    -1,   142,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,    -1,
      -1,    -1,    -1,   224,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   233,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   185,    -1,    -1,
      -1,   189,    -1,    -1,    -1,   193,   194,   195,   196,   197,
      -1,    -1,    -1,   201,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   215,   216,    -1,
      -1,    -1,   220,    -1,    -1,    -1,    -1,   225,    -1,     3,
       4,    -1,   230,    -1,   232,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,
      54,    55,    56,    -1,    -1,    -1,    -1,    61,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,    73,
      74,    -1,    -1,    -1,    -1,    -1,    80,    -1,    -1,    -1,
      84,    -1,    -1,    87,    -1,    -1,    90,    -1,    92,    -1,
      -1,    -1,    -1,    -1,    -1,    99,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   110,    -1,    -1,   113,
      -1,    -1,   116,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     124,   125,   126,   127,   128,    -1,    -1,   131,   132,   133,
     134,   135,    -1,    -1,    -1,   139,    -1,    -1,   142,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,    -1,    -1,    -1,    -1,   224,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   233,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   185,    -1,    -1,    -1,   189,    -1,    -1,    -1,   193,
     194,   195,   196,   197,    -1,    -1,    -1,   201,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   215,   216,    -1,    -1,    -1,   220,    -1,    -1,    -1,
      -1,   225,    -1,     3,     4,    -1,   230,    -1,   232,     9,
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
     110,    -1,    -1,   113,    -1,    -1,   116,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   124,   125,   126,   127,   128,    -1,
      -1,   131,   132,   133,   134,   135,    -1,    -1,    -1,   139,
      -1,    -1,   142,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,    -1,    -1,    -1,
      -1,   224,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     233,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   185,    -1,    -1,    -1,   189,
      -1,    -1,    -1,   193,   194,   195,   196,   197,    -1,    -1,
      -1,   201,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   215,   216,    -1,    -1,    -1,
     220,    -1,    -1,    -1,    -1,   225,    -1,     3,     4,     5,
     230,    -1,   232,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    -1,    -1,    -1,    65,
      66,    67,    -1,    -1,    70,    -1,    72,    73,    74,    -1,
       3,     4,     5,    -1,    80,    81,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    -1,
      -1,    -1,    65,    66,    67,    -1,    -1,    70,    -1,    72,
      73,    74,    -1,    -1,    -1,    -1,    -1,    80,    81,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,    -1,    -1,    -1,    -1,   224,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   233,    -1,    -1,   185,
     186,   187,   188,   189,    -1,    -1,    -1,   193,   194,   195,
     196,   197,   198,    -1,   200,   201,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   215,
     216,    -1,    -1,    -1,   220,    -1,    -1,    -1,    -1,   225,
      -1,    -1,    -1,    -1,   230,    -1,   232,    -1,    -1,    -1,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,    -1,    -1,    -1,    -1,   224,    -1,
      -1,    -1,   185,   186,   187,   188,   189,   233,    -1,    -1,
     193,   194,   195,   196,   197,   198,    -1,   200,   201,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   215,   216,    -1,    -1,    -1,   220,    -1,    -1,
      -1,    -1,   225,    -1,     3,     4,     5,   230,    -1,   232,
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
      36,    -1,    -1,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,    53,    54,    55,
      56,   224,    -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,
     233,    -1,    -1,    -1,    -1,    -1,    72,    73,    74,    -1,
      -1,    -1,    -1,    -1,    80,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,    -1,
      -1,    -1,    -1,   224,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   233,    -1,    -1,    -1,   185,   186,   187,   188,
     189,    -1,    -1,    -1,   193,   194,   195,   196,   197,   198,
      -1,   200,   201,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   215,   216,    -1,    -1,
      -1,   220,    -1,    -1,    -1,    -1,   225,    -1,    -1,    -1,
      -1,   230,    -1,   232,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,    -1,    -1,
      -1,    -1,   224,    -1,    -1,    -1,    -1,    -1,    -1,   185,
      -1,   233,    -1,   189,    -1,    -1,    -1,   193,   194,   195,
     196,   197,    -1,    -1,    -1,   201,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   215,
     216,    -1,    -1,    -1,   220,    -1,    -1,    -1,    -1,   225,
      -1,     3,     4,    -1,   230,    -1,   232,     9,    10,    11,
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
      -1,   113,    -1,    -1,   116,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   124,   125,   126,   127,   128,    -1,    -1,   131,
     132,   133,   134,   135,    -1,    -1,    -1,   139,    -1,    -1,
     142,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,    -1,    -1,    -1,    -1,   224,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   233,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   185,    -1,    -1,    -1,   189,    -1,    -1,
      -1,   193,   194,   195,   196,   197,    -1,    -1,    -1,   201,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   215,   216,    -1,    -1,    -1,   220,     3,
       4,     5,    -1,   225,    -1,     9,    10,    11,   230,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    -1,    -1,
      -1,    65,    66,    67,    -1,    -1,    70,    -1,    72,    73,
      74,    -1,     3,     4,    -1,    -1,    80,    81,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    -1,    -1,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,    53,    54,    55,    56,   224,    -1,    -1,    -1,
      61,    -1,    -1,    -1,    -1,   233,    -1,    -1,    -1,    -1,
      -1,    72,    73,    74,    -1,    -1,    -1,    -1,    -1,    80,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,    -1,    -1,    -1,    -1,   224,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   233,    -1,    -1,
      -1,   185,   186,   187,   188,   189,    -1,    -1,    -1,   193,
     194,   195,   196,   197,   198,    -1,   200,   201,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   215,   216,    -1,    -1,    -1,   220,    -1,    -1,    -1,
      -1,   225,    -1,    -1,    -1,    -1,   230,    -1,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,    -1,    -1,    -1,    -1,   224,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   185,   233,    -1,    -1,   189,    -1,
      -1,    -1,   193,   194,   195,   196,   197,    -1,    -1,    -1,
     201,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   215,   216,    -1,    -1,    -1,   220,
       3,     4,    -1,    -1,   225,   226,     9,    10,    11,   230,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
      53,    54,    55,    56,   224,    -1,    -1,    -1,    61,    -1,
      -1,    -1,    -1,   233,    -1,    -1,    -1,     3,     4,    72,
      73,    74,    -1,     9,    10,    11,    -1,    80,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    -1,    -1,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,    53,    54,    55,
      56,   224,    -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,
     233,    -1,    -1,    -1,    -1,    -1,    72,    73,    74,    -1,
      -1,    -1,    -1,    -1,    80,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,    -1,
      -1,    -1,    -1,   224,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   233,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   185,    -1,    -1,    -1,   189,    -1,    -1,    -1,
     193,   194,   195,   196,   197,    -1,    -1,    -1,   201,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   215,   216,    -1,    -1,    -1,   220,    -1,    -1,
      -1,    -1,   225,    -1,    -1,   228,    -1,   230,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,    -1,    -1,    -1,    -1,   224,    -1,    -1,   185,
      -1,    -1,    -1,   189,    -1,   233,    -1,   193,   194,   195,
     196,   197,    -1,    -1,    -1,   201,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   215,
     216,    -1,    -1,    -1,   220,     3,     4,    -1,    -1,   225,
     226,     9,    10,    11,   230,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    -1,
      -1,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,    53,    54,    55,    56,   224,
      -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,   233,    -1,
      -1,    -1,    -1,    -1,    72,    73,    74,     3,     4,    -1,
       6,    -1,    80,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    -1,    -1,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,    53,    54,    55,
      56,   224,    -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,
     233,    -1,    -1,    -1,    -1,    -1,    72,    73,    74,    -1,
      -1,    -1,    -1,    -1,    80,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,    -1,
      -1,    -1,    -1,   224,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   233,    -1,    -1,    -1,    -1,   185,    -1,    -1,
      -1,   189,    -1,    -1,    -1,   193,   194,   195,   196,   197,
      -1,    -1,    -1,   201,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   215,   216,    -1,
      -1,    -1,   220,    -1,    -1,    -1,    -1,   225,    -1,    -1,
     228,    -1,   230,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,    -1,    -1,    -1,
      -1,   224,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   185,
     233,    -1,    -1,   189,    -1,    -1,    -1,   193,   194,   195,
     196,   197,    -1,    -1,    -1,   201,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   215,
     216,    -1,    -1,    -1,   220,     3,     4,    -1,     6,   225,
      -1,     9,    10,    11,   230,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    -1,
      -1,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,    53,    54,    55,    56,   224,
      -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,   233,    -1,
      -1,    -1,     3,     4,    72,    73,    74,    -1,     9,    10,
      11,    -1,    80,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    -1,    -1,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,    53,    54,    55,    56,   224,    -1,    -1,    -1,
      61,    -1,    -1,    -1,   232,    -1,    -1,    -1,    -1,    -1,
      -1,    72,    73,    74,    -1,    -1,    -1,    -1,    -1,    80,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,    -1,    -1,    -1,    -1,   224,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   232,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   185,    -1,    -1,
      -1,   189,    -1,    -1,    -1,   193,   194,   195,   196,   197,
      -1,    -1,    -1,   201,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   215,   216,    -1,
      -1,    -1,   220,    -1,    -1,    -1,    -1,   225,    12,    13,
      -1,    -1,   230,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,    -1,    -1,    -1,
      -1,   224,    -1,    -1,   185,    -1,    -1,    -1,   189,   232,
      -1,    -1,   193,   194,   195,   196,   197,    12,    13,    -1,
     201,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   215,   216,    -1,    -1,    -1,   220,
      -1,    -1,    -1,    -1,   225,    -1,    -1,    -1,    -1,   230,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    -1,    -1,    -1,   100,   101,   102,    -1,
     104,    -1,    -1,    12,    13,   109,   110,   111,   112,   113,
      -1,   115,   116,   117,    -1,    -1,    -1,    -1,   122,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,   136,    -1,    -1,   100,   101,   102,    -1,   104,
      -1,    -1,    12,    13,   109,   110,   111,   112,   113,    -1,
     115,   116,   117,    -1,    -1,    -1,    -1,   122,   162,   163,
     164,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   136,    -1,    -1,    -1,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    -1,    -1,
      -1,   100,   101,   102,    -1,   104,    -1,   162,   163,   164,
     109,   110,   111,   112,   113,    -1,   115,   116,   117,    -1,
      -1,    -1,    -1,   122,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,   136,    -1,   233,
     100,   101,   102,    -1,   104,    -1,    -1,    12,    13,   109,
     110,   111,   112,   113,    -1,   115,   116,   117,    -1,    -1,
      -1,    -1,   122,   162,   163,   164,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   136,    -1,   233,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    12,    13,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   162,   163,   164,    -1,   224,    -1,   226,    -1,
     228,    -1,    -1,   231,    -1,    -1,    -1,    -1,    -1,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    -1,    -1,   233,   100,   101,   102,    -1,   104,
      -1,    -1,    12,    13,   109,   110,   111,   112,   113,    -1,
     115,   116,   117,    -1,    -1,    -1,    -1,   122,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,   136,    -1,   233,   100,   101,   102,    -1,   104,    -1,
      -1,    12,    13,   109,   110,   111,   112,   113,    -1,   115,
     116,   117,    -1,    -1,    -1,    -1,   122,   162,   163,   164,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     136,    -1,    -1,    -1,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    -1,    -1,    -1,
     100,   101,   102,    -1,   104,    -1,   162,   163,   164,   109,
     110,   111,   112,   113,    -1,   115,   116,   117,    -1,    -1,
      -1,    -1,   122,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,   136,    -1,   233,   100,
     101,   102,    -1,   104,    -1,    -1,    12,    13,   109,   110,
     111,   112,   113,    -1,   115,   116,   117,    -1,    -1,    -1,
      -1,   122,   162,   163,   164,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   136,    -1,   233,    -1,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,    -1,    -1,    -1,    -1,   224,    -1,    -1,
      -1,   162,   163,   164,   231,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    -1,    -1,   233,   100,   101,   102,    -1,   104,    -1,
      -1,    -1,    -1,   109,   110,   111,   112,   113,    -1,   115,
     116,   117,    -1,    -1,    -1,    -1,   122,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     0,     1,    -1,    -1,     4,    -1,
     136,    -1,   233,    -1,    -1,    -1,    12,    13,    -1,    -1,
      -1,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,    -1,   162,   163,   164,   224,
      -1,   226,    -1,   228,    -1,    -1,    42,    43,    -1,    -1,
      -1,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,    -1,    62,    63,    64,   224,
      -1,    -1,    68,    69,    -1,    71,   231,    -1,    -1,    75,
      76,    -1,    78,    79,    -1,    -1,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    -1,    -1,    99,   100,   101,   102,   233,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,    -1,    -1,   121,   122,   123,   124,   125,
     126,   127,   128,   129,    -1,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,    -1,
      -1,    -1,   148,   149,   150,    -1,    -1,    -1,    -1,    -1,
     156,     4,    -1,    -1,    -1,   161,   162,   163,   164,    12,
      13,   167,    -1,   169,    -1,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,    -1,
      -1,    -1,    -1,    -1,   190,   191,   192,    -1,    -1,    42,
      43,    -1,    -1,   199,    -1,   201,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,
      63,    64,    -1,    -1,    -1,    68,    69,    -1,    71,    -1,
      -1,    -1,    75,    76,    -1,    78,    79,    -1,    -1,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    -1,    -1,    99,   100,   101,   102,
      -1,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,    -1,    -1,   121,   122,
     123,   124,   125,   126,   127,   128,   129,    -1,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,    12,    13,    -1,   148,   149,   150,    -1,    -1,
      -1,    -1,    -1,   156,    -1,    -1,    -1,    -1,   161,   162,
     163,   164,    -1,    -1,   167,    -1,   169,    -1,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,    -1,    -1,    -1,    -1,    -1,   190,   191,   192,
      -1,    -1,    -1,    -1,    -1,    -1,   199,    -1,   201,    12,
      13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    -1,    -1,    -1,
     100,   101,   102,    -1,   104,    -1,    -1,    -1,    -1,   109,
     110,   111,   112,   113,    -1,   115,   116,   117,    -1,    -1,
      -1,    -1,   122,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   136,    -1,    -1,    -1,
     140,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    -1,    -1,    -1,   100,   101,   102,
      -1,   104,   162,   163,   164,    -1,   109,   110,   111,   112,
     113,    -1,   115,   116,   117,    -1,    -1,    -1,    -1,   122,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   136,    -1,    -1,    -1,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,    -1,    -1,    -1,    -1,   224,    -1,    -1,    -1,   162,
     163,   164,   231,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,    -1,    -1,    -1,
      -1,   224,    -1,    -1,    -1,    -1,    -1,    -1,   231,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,    -1,    -1,    -1,    -1,   224,    -1,    -1,
      -1,    -1,    -1,    -1,   231,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,    -1,
      -1,    -1,    -1,   224,    -1,    -1,    -1,    -1,    -1,    -1,
     231,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,    -1,    -1,    -1,    -1,   224,
      -1,    -1,    -1,    -1,    -1,    -1,   231,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,    -1,    -1,    -1,    -1,   224,    -1,    -1,    -1,    -1,
      -1,    -1,   231,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,    -1,    -1,    -1,
      -1,   224,    -1,    -1,    -1,    -1,    -1,    -1,   231,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,    -1,    -1,    -1,    -1,   224,    -1,    -1,
      -1,    -1,    -1,    -1,   231,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,    -1,
      -1,    -1,    -1,   224,    -1,    -1,    -1,    -1,    -1,    -1,
     231,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,    -1,    -1,    -1,    -1,   224,
      -1,    -1,    -1,    -1,    -1,    -1,   231,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,    -1,    -1,    -1,    -1,   224,    -1,    -1,    -1,    -1,
      -1,    -1,   231,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,    -1,    -1,    -1,
      -1,   224,    -1,    -1,    -1,    -1,    -1,    -1,   231,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,    -1,    -1,    -1,    -1,   224,    -1,    -1,
      -1,    -1,    -1,    -1,   231,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,    -1,
      -1,    -1,    -1,   224,    -1,    -1,    -1,    -1,    -1,    -1,
     231,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,    -1,    -1,    -1,    -1,   224,
      -1,    -1,    -1,    -1,    -1,    -1,   231,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,    -1,    -1,    -1,    -1,   224,    -1,    -1,    -1,    -1,
      -1,    -1,   231,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,    -1,    -1,    -1,
      -1,   224,    -1,    -1,    -1,    -1,    -1,    -1,   231,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,    -1,    -1,    -1,    -1,   224,    -1,    -1,
      -1,    -1,    -1,    -1,   231,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,    -1,
      -1,    -1,    -1,   224,    -1,    -1,    -1,    -1,    -1,    -1,
     231,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,    -1,    -1,    -1,    -1,   224,
      -1,    -1,    -1,    -1,    -1,    -1,   231,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,    -1,    -1,    -1,    -1,   224,    -1,    -1,    -1,    -1,
      -1,    -1,   231,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,    -1,    -1,    -1,
      -1,   224,    -1,    -1,    -1,    -1,    -1,    -1,   231,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,    -1,    -1,    -1,    -1,   224,    -1,    -1,
      -1,    -1,    -1,    -1,   231,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,    -1,
      -1,    -1,    -1,   224,    -1,    -1,    -1,    -1,    -1,    -1,
     231,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,    -1,    -1,    -1,    -1,   224,
      -1,    -1,    -1,    -1,    -1,    -1,   231,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,    -1,    -1,    -1,    -1,   224,    -1,    -1,    -1,    -1,
      -1,    -1,   231,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,    -1,    -1,    -1,
      -1,   224,    -1,    -1,    -1,    -1,    -1,    -1,   231,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,    -1,    -1,    -1,    -1,   224,    -1,    -1,
      -1,    -1,    -1,    -1,   231,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,    -1,
      -1,    -1,    -1,   224,    -1,    -1,    -1,    -1,    -1,    -1,
     231,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,    -1,    -1,    -1,    -1,   224,
      -1,    -1,    -1,    -1,    -1,    -1,   231,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,    -1,    -1,    -1,    -1,   224,    -1,    -1,    -1,    -1,
      -1,    -1,   231,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,    -1,    -1,    -1,
      -1,   224,    -1,    -1,    -1,    -1,    -1,    -1,   231,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,    -1,    -1,    -1,    -1,   224,    -1,    -1,
      -1,    -1,    -1,    -1,   231,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,    -1,
      -1,    -1,    -1,   224,    -1,    -1,    -1,    -1,    -1,    -1,
     231,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,    -1,    -1,    -1,    -1,   224,
      -1,    -1,    -1,    -1,    -1,    -1,   231,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,    -1,    -1,    -1,    -1,   224,    -1,    -1,    -1,    -1,
      -1,    -1,   231,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,    -1,    -1,    -1,
      -1,   224,    -1,    -1,    -1,    -1,    -1,    -1,   231,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,    -1,    -1,    -1,    -1,   224,    -1,    -1,
      -1,    -1,    -1,    -1,   231,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,    -1,
      -1,    -1,    -1,   224,    -1,    -1,    -1,    -1,    -1,    -1,
     231,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,    -1,    -1,    -1,    -1,   224,
      -1,    -1,    -1,    -1,    -1,    -1,   231,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,    -1,    -1,    -1,    -1,   224,    -1,    -1,    -1,    -1,
      -1,    -1,   231,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,    -1,    -1,    -1,
      -1,   224,    -1,    -1,    -1,    -1,    -1,    -1,   231,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,    -1,    -1,    -1,    -1,   224,    -1,    -1,
      -1,    -1,    -1,    -1,   231,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,    -1,
      -1,    -1,    -1,   224,    -1,    -1,    -1,    -1,    -1,    -1,
     231,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,    -1,    -1,    -1,    -1,   224,
      -1,    -1,    -1,    -1,    -1,    -1,   231,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,    -1,    -1,    -1,    -1,   224,    -1,    -1,    -1,    -1,
      -1,    -1,   231,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,    -1,    -1,    -1,
      -1,   224,    -1,    -1,    -1,    -1,    -1,    -1,   231,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,    -1,    -1,    -1,    -1,   224,    -1,    -1,
      -1,    -1,    -1,    -1,   231,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,    -1,
      -1,    -1,    -1,   224,    -1,    -1,    -1,    -1,    -1,    -1,
     231,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,    -1,    -1,    -1,    -1,   224,
      -1,    -1,    -1,    -1,    -1,    -1,   231,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,    -1,    -1,    -1,    -1,   224,    -1,    -1,    -1,    -1,
      -1,    -1,   231,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,    -1,    -1,    -1,
      -1,   224,    -1,    -1,    -1,    -1,    -1,    -1,   231,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,    -1,    -1,    -1,    -1,   224,    -1,    -1,
      -1,    -1,    -1,    -1,   231,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,    -1,
      -1,    -1,    -1,   224,    -1,    -1,    -1,   228,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,    -1,    -1,    -1,    -1,   224,    -1,    -1,    -1,
     228,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,    -1,    -1,    -1,    -1,   224,
      -1,    -1,    -1,   228,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,    -1,    -1,
      -1,    -1,   224,    -1,    -1,    -1,   228,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,    -1,    -1,    -1,    -1,   224,    -1,    -1,    -1,   228,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,    -1,    -1,    -1,    -1,   224,    -1,
      -1,    -1,   228,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,    -1,    -1,    -1,
      -1,   224,    -1,    -1,    -1,   228,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
      -1,    -1,    -1,    -1,   224,    -1,    -1,    -1,   228,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,    -1,    -1,    -1,    -1,   224,    -1,    -1,
      -1,   228,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,    -1,    -1,    -1,    -1,
     224,    -1,    -1,    -1,   228,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,    -1,
      -1,    -1,    -1,   224,    -1,    -1,    -1,   228,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,    -1,    -1,    -1,    -1,   224,    -1,    -1,    -1,
     228,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,    -1,    -1,    -1,    -1,   224,
      -1,    -1,    -1,   228,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,    -1,    -1,
      -1,    -1,   224,    -1,    -1,    -1,   228,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,    -1,    -1,    -1,    -1,   224,    -1,    -1,    -1,   228,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,    -1,    -1,    -1,    -1,   224,    -1,
      -1,    -1,   228,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,    -1,    -1,    -1,
      -1,   224,    -1,    -1,    -1,   228,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
      -1,    -1,    -1,    -1,   224,    -1,   226,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,    -1,    -1,    -1,    -1,   224,    -1,   226,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,    -1,    -1,    -1,    -1,   224,    -1,   226,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,    -1,    -1,    -1,    -1,   224,    -1,   226,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,    -1,    -1,    -1,    -1,   224,    -1,
     226,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,    -1,    -1,    -1,    -1,   224,
      -1,   226,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,    -1,    -1,    -1,    -1,
     224,    -1,   226,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,    -1,    -1,    -1,
      -1,   224,    -1,   226,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,    -1,    -1,
      -1,    -1,   224,    -1,   226,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,    -1,
      -1,    -1,    -1,   224,    -1,   226,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
      -1,    -1,    -1,    -1,   224,    -1,   226,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,    -1,    -1,    -1,    -1,   224,    -1,   226,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,    -1,    -1,    -1,    -1,   224,    -1,   226,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,    -1,    -1,    -1,    -1,   224,    -1,   226,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,    -1,    -1,    -1,    -1,   224,    -1,
     226,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,    -1,    -1,    -1,    -1,   224,
      -1,   226,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,    -1,    -1,    -1,    -1,
     224,    -1,   226,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,    -1,    -1,    -1,
      -1,   224,    -1,   226,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,    -1,    -1,
      -1,    -1,   224,    -1,   226,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,    -1,
      -1,    -1,    -1,   224,    -1,   226,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
      -1,    -1,    -1,    -1,   224,    -1,   226,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,    -1,    -1,    -1,    -1,   224,    -1,   226,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,    -1,    -1,    -1,    -1,   224,    -1,   226,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,    -1,    -1,    -1,    -1,   224,    -1,   226,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,    -1,    -1,    -1,    -1,   224,    -1,
     226,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,    -1,    -1,    -1,    -1,   224,
      -1,   226,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,    -1,    -1,    -1,    -1,
     224,    -1,   226,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,    -1,    -1,    -1,
      -1,   224,    -1,   226,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,    -1,    -1,
      -1,    -1,   224,    -1,   226,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,    -1,
      -1,    -1,    -1,   224,    -1,   226,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
      -1,    -1,    -1,    -1,   224,    -1,   226,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,    -1,    -1,    -1,    -1,   224,    -1,   226,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,    -1,    -1,    -1,    -1,   224,    -1,   226,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,    -1,    -1,    -1,    -1,   224,    -1,   226,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,    -1,    -1,    -1,    -1,   224,    -1,
     226,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,    -1,    -1,    -1,    -1,   224,
      -1,   226,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,    -1,    -1,    -1,    -1,
     224,    -1,   226,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,    -1,    -1,    -1,
      -1,   224,    -1,   226,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,    -1,    -1,
      -1,    -1,   224,    -1,   226,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,    -1,
      -1,    -1,    -1,   224,    -1,   226,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
      -1,    -1,    -1,    -1,   224,    -1,   226,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,    -1,    -1,    -1,    -1,   224,    -1,   226,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,    -1,    -1,    -1,    -1,   224,    -1,   226,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,    -1,    -1,    -1,    -1,   224,    -1,   226,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,    -1,    -1,    -1,    -1,   224,    -1,
     226,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,    -1,    -1,    -1,    -1,   224,
      -1,   226,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,    -1,    -1,    -1,    -1,
     224,    -1,   226,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,    -1,    -1,    -1,
      -1,   224,    -1,   226,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,    -1,    -1,
      -1,    -1,   224,    -1,   226,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,    -1,
      -1,    -1,    -1,   224,    -1,   226,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
      -1,    -1,    -1,    -1,   224,    -1,   226,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,    -1,    -1,    -1,    -1,   224,    -1,   226,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,    -1,    -1,    -1,    -1,   224,    -1,   226,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,    -1,    -1,    -1,    -1,   224,    -1,   226,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,    -1,    -1,    -1,    -1,   224,    -1,
     226,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,    -1,    -1,    -1,    -1,   224,
      -1,   226,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,    -1,    -1,    -1,    -1,
     224,    -1,   226,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,    -1,    -1,    -1,
      -1,   224,    -1,   226,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,    -1,    -1,
      -1,    -1,   224,    -1,   226,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,    -1,
      -1,    -1,    -1,   224
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,   236,   237,     6,     0,     4,    12,    13,    42,
      43,    62,    63,    64,    68,    69,    71,    75,    76,    78,
      79,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    99,   100,   101,   102,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   148,   149,
     150,   156,   161,   162,   163,   164,   167,   169,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   190,   191,   192,   199,   201,   238,   240,   241,
     261,   280,   281,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   308,   310,   311,   317,   318,   319,   320,   338,
     339,     3,     4,     5,     9,    10,    11,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    65,    66,
      67,    70,    72,    73,    74,    80,    81,   178,   185,   186,
     187,   188,   189,   193,   194,   195,   196,   197,   198,   200,
     215,   216,   220,   225,   227,   229,   230,   232,   234,   259,
     321,   322,   334,   335,   338,   339,    13,    90,   225,   225,
       6,   232,     6,     6,     6,     6,   225,     6,     6,   227,
     227,   225,   227,   259,   259,   225,   232,   225,   225,     4,
     225,   232,   225,   225,     4,   232,   225,   225,   225,   225,
     225,   225,   225,   225,   225,   103,    90,    90,     6,   232,
      84,    87,    90,   225,     4,    37,    38,    39,    40,    41,
      84,    87,    90,    92,   110,   113,   116,   216,   225,   232,
     281,   292,   308,   310,   321,   327,   329,   338,   339,   225,
      90,    90,   110,    87,    90,    92,    92,    84,    87,    90,
      92,    87,    90,    92,    87,    90,   225,    87,   167,   183,
     184,   232,   215,   216,   225,   232,   324,   325,   324,   232,
      84,    87,    90,   232,   324,     4,    84,    88,    94,    95,
      97,    98,   112,   225,    90,    92,    90,    87,     4,   178,
     232,   338,   339,     4,     6,    84,    87,    90,    87,    90,
       4,     4,     4,     5,   225,   327,   328,     4,   225,   225,
     225,     4,   232,   331,   339,     4,   225,   225,   225,     6,
       6,   227,     4,   335,   339,   225,     4,   335,     5,   232,
       5,   232,     4,   321,   338,   227,   225,   232,     6,   225,
     232,   225,   227,   234,   259,     7,   202,   203,   204,   205,
     222,   223,   257,   258,     4,   225,   227,   229,   259,   259,
     259,   259,   259,   259,   259,   259,   259,   259,   259,   259,
     259,   259,   259,   259,   259,   259,   259,   259,   259,   259,
     259,   259,   259,   225,   225,   225,   259,   259,   259,   259,
     225,   259,   259,   259,   259,   259,   259,   225,   259,   259,
     259,     7,   225,   225,   225,   259,   259,   225,   225,   227,
     321,   321,   321,   226,   321,   228,   321,     4,   167,   168,
     339,     4,   281,   282,   283,   232,   232,     6,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   224,   232,     6,   225,   227,   258,     6,   321,
       4,   334,   335,   338,   339,   334,   321,   334,   337,   263,
     268,   335,   339,   321,   216,   321,   329,   330,   321,   321,
     225,   321,   330,   321,   321,   225,   330,   321,   321,   321,
     321,   321,   321,   334,   321,   321,   327,   225,   232,   330,
     328,   328,   328,   334,   225,   227,   229,   259,   225,   227,
     259,   259,   259,   259,     5,   170,   232,     5,   170,     5,
     170,     5,   170,   110,    84,    87,    90,    92,   232,   321,
     329,   321,   233,   330,     8,   217,   225,   227,   259,   321,
     225,   225,   225,   327,   328,   328,   328,   225,   225,   225,
     225,   225,   225,   327,   225,   327,   225,   327,   232,   232,
     321,     4,   327,   331,   232,   232,   324,   324,   324,   321,
     321,   215,   216,   232,   232,   324,   232,   232,   232,   215,
     216,   225,   283,   321,   324,   232,   225,   232,   225,   225,
     225,   225,   225,   225,   225,   321,   328,   328,   327,   225,
       4,   227,   227,   283,     6,     6,   232,   232,   232,   328,
     328,   227,   227,   227,   321,     6,     6,   321,   321,   321,
     229,   321,   232,   170,   321,   321,   321,   321,     6,     6,
     232,     6,   283,     6,   283,   225,   227,   232,   225,   227,
     334,   321,   283,   327,   327,   226,   321,   228,   321,   232,
     232,   335,   327,     6,   227,   321,   321,     4,   321,   321,
     321,   321,   321,   321,   321,   321,   321,   321,   321,   321,
     321,   321,   321,   321,   321,   321,   321,   321,   321,   321,
     337,   334,   337,   334,   334,   334,   334,   334,   334,   334,
     327,   334,   334,   321,   334,   334,   334,   337,   334,   321,
     335,   321,   334,   334,   334,   334,   334,   339,   335,   339,
       7,   205,   257,   226,     7,   205,   257,   228,     7,   257,
     258,   229,     7,   259,   233,    84,    87,    90,    92,   110,
     113,   280,   321,   330,   321,   321,   321,   321,   321,   321,
     321,   321,   321,   321,   321,   321,   321,   321,   321,   242,
     321,   321,     6,   225,   227,   229,   226,   231,   225,   227,
     226,   231,   231,   226,   231,   228,   231,   262,   228,   262,
     231,   231,   226,   217,   231,   233,   226,   226,   321,   226,
     233,   226,   226,   321,   233,   226,   226,   226,   226,   226,
     226,   226,   226,   226,     7,   321,   321,   233,     6,     6,
       6,   226,   321,   321,     4,   226,   228,   232,   260,   232,
     321,   329,   232,   329,   339,   321,   321,   334,   321,    62,
     321,    62,    62,    62,     5,   232,     5,   232,     5,   232,
       5,   232,   330,   226,   233,   321,   232,   321,   329,   321,
     321,   232,   260,   226,   321,   321,   321,     7,     7,   314,
     314,   321,   274,   321,   335,   275,   321,   335,   276,   321,
     335,   277,   321,   335,   321,     6,   321,     6,   321,     6,
     330,   330,   232,   226,     6,   232,   283,   283,   231,   231,
     231,   324,   324,   282,   282,   231,   321,   321,   321,   321,
     233,   296,   233,   231,   283,   321,   321,   321,   321,   321,
     321,   321,   321,   321,   226,     7,   315,     6,     7,   321,
       6,   321,   321,   233,   330,   330,   330,     6,     6,   321,
     321,   321,   226,   226,   226,   226,   167,   231,   283,   232,
       8,   226,   226,   228,   330,   233,   233,   283,   228,   226,
     140,   309,   226,   231,   233,     7,   205,   257,   226,     7,
     205,   257,   228,   321,   330,     6,     6,   321,   226,   228,
     258,   260,   260,   260,   260,   260,   260,   260,   260,   260,
     260,   260,   231,   260,   260,   260,   260,   260,   260,   260,
     231,   231,   231,   260,   231,   260,   260,   226,   226,   231,
     260,   260,   231,   260,   231,   231,   231,   231,   260,   260,
     260,   226,   260,   323,   336,     6,   231,   231,   226,   231,
     260,   231,   260,   226,   226,   228,    44,    44,   327,     7,
     257,   258,    44,    44,   327,   229,   257,   258,   335,   321,
       6,     4,     4,   232,   332,   260,   232,   232,   232,   232,
     225,   110,   233,   233,     8,     4,   157,   158,   159,   160,
     233,   245,   249,   252,   254,   255,   226,   228,   321,   321,
       4,     6,   212,   239,   330,   321,   321,     6,   330,   321,
       6,   334,     6,   339,     6,   334,   321,   335,     7,   321,
     329,   170,     7,     7,   226,     7,   170,     7,     7,   226,
     170,     7,     7,     7,     7,     7,     7,     7,     7,   321,
     226,   233,   232,     6,   226,   228,   330,   330,   226,   330,
     228,   228,   231,   231,   260,   231,   232,   233,   232,   232,
     232,   330,   330,   330,   330,   233,     7,     8,   330,   226,
     228,   330,     7,   226,   226,   226,   321,   327,     4,   313,
       6,   226,   226,   231,   226,   231,   226,   231,   226,   231,
     226,   226,   226,   233,   233,   330,   229,   283,   233,   233,
     324,   321,   321,   233,   233,   321,   324,   231,   231,   231,
     119,   119,   137,   145,   146,   147,   151,   152,   153,   154,
     306,   307,   232,   324,   233,   293,   226,   233,   226,   226,
     226,   226,   226,   226,   226,     7,   321,     6,   321,   226,
     228,   228,   233,   233,   233,   228,   228,   231,     7,     7,
       7,   229,   321,   233,   321,   321,     7,   229,   233,   233,
       7,     6,   321,   233,   232,   327,     6,    44,    44,   327,
     257,   258,    44,    44,   327,   257,   258,   233,   233,   228,
     258,   229,   258,   334,   321,   321,   321,   321,   330,   334,
     321,   327,   334,   334,   334,   270,   272,   321,   334,   334,
     321,   259,   259,     6,   321,     6,   259,   259,     6,     4,
     167,   168,   321,     6,     6,     6,     7,   227,   331,   333,
       6,   330,   330,   330,   330,   321,   225,   260,   321,   246,
     225,   225,   232,   256,     6,   258,   258,   226,   228,   212,
     334,   226,   226,   228,   226,   231,     7,   225,   227,   260,
     260,   324,    90,    92,   327,   327,     7,   327,    90,    92,
     327,   327,     7,    92,   327,   327,   327,   327,   327,   327,
     327,   327,     6,     7,     7,   330,   229,   233,   233,   233,
     321,   321,   321,   321,   321,   321,   321,   233,   233,   233,
     233,   327,   321,   233,   233,   327,     7,     7,     7,   119,
     312,     6,     7,   257,   321,   257,   321,   257,   321,   257,
     321,     7,     7,     7,     7,     7,   233,     4,   233,   231,
     231,   231,   233,   233,   324,   324,   324,    87,     4,     6,
     321,   232,     6,   225,     6,   155,     6,   155,     6,   155,
       6,   155,   233,   307,   283,   231,   306,     7,     6,     7,
       7,     7,     7,     7,     7,     7,   327,     6,   232,     6,
       6,     6,    90,     7,     6,     6,   321,   327,   327,   327,
       4,   231,     8,     8,   226,     4,     4,   231,   232,     6,
     232,   327,   233,   259,   259,     6,   321,     6,   259,   259,
       6,   321,     6,   260,     6,     4,     6,   260,   260,   260,
     260,   260,   231,   231,   260,   226,   260,   260,   231,   231,
     260,   271,   231,   260,   273,   226,   226,   260,   260,   260,
     337,   337,     6,   260,   337,   337,     7,   257,   258,   229,
       7,     6,   331,   321,   231,   233,   233,   233,   233,   233,
     226,   321,   257,   225,   321,   321,   326,   327,   232,   229,
       6,     6,   239,     6,   321,   232,   321,   335,   226,   228,
       6,     6,     6,   232,   232,   112,   279,   279,   327,     6,
     232,   232,     6,     6,   327,   232,     6,     6,     6,     6,
       6,     6,     6,     6,     5,   327,   233,     4,   260,   226,
     228,   231,   231,   231,   231,   231,   231,   231,     6,   260,
       6,   327,   327,   327,     4,     6,   327,   327,   327,   327,
     327,   327,   327,   327,   232,   232,     7,     6,     7,   321,
     321,   321,   232,   232,   231,   233,   231,   233,   231,   233,
     232,   227,     6,   321,   327,   321,     6,     6,     6,     6,
     233,   321,   324,   233,     5,   327,   232,   232,   232,   232,
     232,   232,   232,   327,     6,   330,   232,   321,   228,     6,
       6,   166,   321,   321,   321,     6,     6,     7,   335,   283,
     283,   231,     6,   260,   337,   337,     6,   260,   337,   337,
       6,   257,   258,   334,   321,   334,     4,     4,   182,     6,
     260,   260,     6,   260,   260,   335,   321,     6,     4,   332,
       6,   228,   331,     6,     6,     6,     6,   226,   327,   243,
     321,   231,   231,   231,   233,   244,   321,     4,   334,   231,
     327,   335,     7,     7,   321,   321,   324,     6,     6,     6,
     321,   321,     6,   321,     5,     6,   232,   321,   321,   321,
     321,   321,   321,   321,     6,   170,   278,     6,   321,     6,
       6,     6,     6,     6,     6,     4,     6,     6,   330,   330,
     321,   321,   335,   233,   226,   231,   233,   282,   282,   324,
       6,   297,   324,     6,   298,   324,     6,   299,   327,   321,
     233,   231,   226,   120,   233,   231,     6,     6,   326,   324,
     324,   324,   324,   324,   216,   324,     6,   233,   321,     6,
       6,   327,   231,   233,     8,   233,   226,   232,   321,   335,
     231,   309,   309,   327,     6,   260,   260,     6,   260,   260,
     327,   226,   260,   260,   232,   327,   335,   232,   321,   335,
     335,     6,     6,     6,     6,     6,     6,     7,     6,   229,
       6,   226,   231,   321,   321,   327,   232,   231,   233,     6,
     321,   264,   267,   232,   232,   233,   233,   233,   233,   233,
       5,   326,   260,   260,   231,   231,   231,   231,   231,    88,
       6,   232,   233,   233,   232,     6,     6,   232,   321,   233,
     233,   231,   232,   231,   232,   231,   232,   233,   228,     6,
     327,     7,    90,   232,   321,   233,   231,   231,   231,   231,
     231,   231,     6,   233,   165,   321,   321,   330,     6,     6,
     335,   233,   233,   233,     6,     6,     6,     6,     6,   269,
     321,   329,   337,   331,   168,   247,   321,   231,   231,   326,
     321,     6,   231,   270,   272,   327,   327,     6,     6,     6,
       6,     6,     6,   233,   321,   321,   321,   321,   321,   232,
     326,   124,   125,   130,   316,   124,   125,   316,   330,   282,
     231,   233,   321,   324,   306,   321,   324,   306,   321,   324,
     306,     6,   231,   233,   327,   232,   283,   233,     6,   330,
     324,   324,   324,   324,   324,   321,   233,   233,   233,   226,
     232,     6,   231,   233,     7,     7,   233,     6,   232,   321,
     321,   233,   321,   233,   233,   266,   265,   232,   231,   231,
     231,   231,   231,   321,   233,   232,   324,   327,     6,   232,
     324,     6,   233,   233,   321,   233,   231,   233,   233,   231,
     233,   233,   231,   233,   327,     6,   119,   327,   233,   294,
     232,   233,   231,   231,   231,   231,   231,     6,     6,     6,
     283,   321,   335,   339,   244,   226,   231,     6,   232,   231,
     270,   270,   321,   321,   321,   321,   321,   321,   233,     6,
     324,     6,   324,     6,     6,   233,     6,   300,   321,     6,
       6,   301,   321,     6,     6,   302,   321,     6,   233,   321,
     233,   306,   283,     6,   330,   330,   330,   330,   324,   330,
     309,     7,   225,   233,   250,   321,   326,   321,   233,   233,
     231,   231,   231,   231,   231,   231,   231,   231,   232,   233,
     232,   233,   232,   233,     6,     6,   233,   233,   295,   233,
     233,   233,   233,   231,   233,   233,   335,   226,     6,   232,
     226,   233,   233,   321,   321,   321,   321,   321,   321,   324,
     324,   306,     6,   303,   306,     6,   304,   306,     6,   305,
     306,     6,     6,     6,     6,   330,     6,     6,   248,   334,
     253,   232,     6,   233,   260,   231,   231,   231,   231,   231,
     231,   233,   232,   233,   232,   233,   232,   233,   233,   231,
     233,   232,   326,     6,   321,   321,   321,   321,   321,   321,
       6,   306,     6,   306,     6,   306,     6,   334,     6,   251,
     334,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   231,   233,     6,     6,     6,     6,     6,     6,   334,
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
#line 1931 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (8)].d);
      if(FindCurve(num)){
	yymsg(0, "Curve %d already exists", num);
      }
      else{
        if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
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
#line 1975 "Gmsh.y"
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
#line 2002 "Gmsh.y"
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
#line 2030 "Gmsh.y"
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
#line 2056 "Gmsh.y"
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
#line 2085 "Gmsh.y"
    {
     GModel::current()->getGEOInternals()->addCompoundMesh ( 1 , (yyvsp[(3) - (4)].l) );
   ;}
    break;

  case 184:
#line 2090 "Gmsh.y"
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
#line 2108 "Gmsh.y"
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
#line 2154 "Gmsh.y"
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
#line 2182 "Gmsh.y"
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
#line 2232 "Gmsh.y"
    {
      myGmshSurface = 0;
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 189:
#line 2238 "Gmsh.y"
    {
      myGmshSurface = gmshSurface::getSurface((int)(yyvsp[(3) - (4)].d));
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 190:
#line 2244 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (10)].d);
      myGmshSurface = gmshParametricSurface::NewParametricSurface(num, (yyvsp[(7) - (10)].c), (yyvsp[(8) - (10)].c), (yyvsp[(9) - (10)].c));
      (yyval.s).Type = 0;
      (yyval.s).Num = num;
    ;}
    break;

  case 191:
#line 2251 "Gmsh.y"
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
#line 2293 "Gmsh.y"
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
#line 2319 "Gmsh.y"
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
#line 2343 "Gmsh.y"
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
#line 2367 "Gmsh.y"
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
#line 2392 "Gmsh.y"
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
#line 2415 "Gmsh.y"
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
#line 2442 "Gmsh.y"
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
#line 2470 "Gmsh.y"
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
#line 2495 "Gmsh.y"
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
#line 2518 "Gmsh.y"
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
#line 2545 "Gmsh.y"
    {
      GModel::current()->getGEOInternals()->addCompoundMesh ( 2 , (yyvsp[(3) - (4)].l) );
    ;}
    break;

  case 203:
#line 2549 "Gmsh.y"
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
#line 2569 "Gmsh.y"
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
#line 2602 "Gmsh.y"
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
#line 2649 "Gmsh.y"
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
#line 2667 "Gmsh.y"
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
#line 2694 "Gmsh.y"
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
#line 2713 "Gmsh.y"
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
#line 2732 "Gmsh.y"
    {
      GModel::current()->getGEOInternals()->addCompoundMesh(3, (yyvsp[(3) - (4)].l));
    ;}
    break;

  case 211:
#line 2736 "Gmsh.y"
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
#line 2752 "Gmsh.y"
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
#line 2800 "Gmsh.y"
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
#line 2817 "Gmsh.y"
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
#line 2835 "Gmsh.y"
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
#line 2845 "Gmsh.y"
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
#line 2855 "Gmsh.y"
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
#line 2865 "Gmsh.y"
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
#line 2928 "Gmsh.y"
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
#line 2939 "Gmsh.y"
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
#line 2954 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 222:
#line 2955 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 223:
#line 2960 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    ;}
    break;

  case 224:
#line 2964 "Gmsh.y"
    {
      List_Add((yyval.l), &(yyvsp[(2) - (2)].s));
    ;}
    break;

  case 225:
#line 2968 "Gmsh.y"
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
#line 2997 "Gmsh.y"
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
#line 3026 "Gmsh.y"
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
#line 3055 "Gmsh.y"
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
#line 3089 "Gmsh.y"
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
#line 3111 "Gmsh.y"
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
#line 3138 "Gmsh.y"
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
#line 3160 "Gmsh.y"
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
#line 3182 "Gmsh.y"
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
#line 3204 "Gmsh.y"
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
#line 3260 "Gmsh.y"
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
#line 3284 "Gmsh.y"
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
#line 3309 "Gmsh.y"
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
#line 3334 "Gmsh.y"
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
#line 3447 "Gmsh.y"
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
#line 3466 "Gmsh.y"
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
#line 3509 "Gmsh.y"
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
#line 3530 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      GModel::current()->getFields()->deleteField((int)(yyvsp[(4) - (6)].d));
#endif
    ;}
    break;

  case 243:
#line 3536 "Gmsh.y"
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
#line 3551 "Gmsh.y"
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
#line 3579 "Gmsh.y"
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
#line 3596 "Gmsh.y"
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
#line 3605 "Gmsh.y"
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
#line 3619 "Gmsh.y"
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
#line 3633 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 1, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 250:
#line 3639 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 0, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 251:
#line 3645 "Gmsh.y"
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
#line 3654 "Gmsh.y"
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
#line 3663 "Gmsh.y"
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
#line 3672 "Gmsh.y"
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
#line 3686 "Gmsh.y"
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
#line 3748 "Gmsh.y"
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
#line 3766 "Gmsh.y"
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
#line 3783 "Gmsh.y"
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
#line 3798 "Gmsh.y"
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
#line 3827 "Gmsh.y"
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
#line 3839 "Gmsh.y"
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
#line 3863 "Gmsh.y"
    {
      Msg::Exit(0);
    ;}
    break;

  case 263:
#line 3867 "Gmsh.y"
    {
      gmsh_yyerrorstate = 999; // this will be checked when yyparse returns
      YYABORT;
    ;}
    break;

  case 264:
#line 3872 "Gmsh.y"
    {
      // FIXME: this is a hack to force a transfer from the old DB to
      // the new DB. This will become unnecessary if/when we fill the
      // GModel directly during parsing.
      GModel::current()->importGEOInternals();
      GModel::current()->importOCCInternals();
    ;}
    break;

  case 265:
#line 3880 "Gmsh.y"
    {
      new GModel();
      GModel::current(GModel::list.size() - 1);
    ;}
    break;

  case 266:
#line 3885 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 0;
      GModel::current()->importGEOInternals();
      SetBoundingBox();
    ;}
    break;

  case 267:
#line 3891 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 1;
      SetBoundingBox((yyvsp[(3) - (15)].d), (yyvsp[(5) - (15)].d), (yyvsp[(7) - (15)].d), (yyvsp[(9) - (15)].d), (yyvsp[(11) - (15)].d), (yyvsp[(13) - (15)].d));
    ;}
    break;

  case 268:
#line 3896 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
      drawContext::global()->draw();
#endif
    ;}
    break;

  case 269:
#line 3902 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
     CTX::instance()->mesh.changed = ENT_ALL;
     for(unsigned int index = 0; index < PView::list.size(); index++)
       PView::list[index]->setChanged(true);
#endif
    ;}
    break;

  case 270:
#line 3910 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh();
    ;}
    break;

  case 271:
#line 3914 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh(1);
    ;}
    break;

  case 272:
#line 3918 "Gmsh.y"
    {
      GModel::current()->importGEOInternals();
      GModel::current()->refineMesh(CTX::instance()->mesh.secondOrderLinear);
    ;}
    break;

  case 273:
#line 3924 "Gmsh.y"
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
#line 3983 "Gmsh.y"
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
#line 3999 "Gmsh.y"
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
#line 4016 "Gmsh.y"
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
#line 4033 "Gmsh.y"
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
#line 4055 "Gmsh.y"
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
#line 4077 "Gmsh.y"
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
#line 4112 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip_until(NULL, "Return");
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 281:
#line 4120 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip_until(NULL, "Return");
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 282:
#line 4128 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    ;}
    break;

  case 283:
#line 4134 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 284:
#line 4141 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 285:
#line 4148 "Gmsh.y"
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
#line 4168 "Gmsh.y"
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
#line 4194 "Gmsh.y"
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
#line 4206 "Gmsh.y"
    {
      ImbricatedTest--;
      if(ImbricatedTest < 0)
        yymsg(1, "Orphan EndIf");
    ;}
    break;

  case 289:
#line 4218 "Gmsh.y"
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
#line 4248 "Gmsh.y"
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
#line 4279 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (13)].l),
		    (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].v)[0], (yyvsp[(7) - (13)].v)[1], (yyvsp[(7) - (13)].v)[2], (yyvsp[(9) - (13)].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[(12) - (13)].l));
    ;}
    break;

  case 292:
#line 4287 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 293:
#line 4293 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (7)].l),
		    (yyvsp[(2) - (7)].v)[0], (yyvsp[(2) - (7)].v)[1], (yyvsp[(2) - (7)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(4) - (7)].l));
    ;}
    break;

  case 294:
#line 4301 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 295:
#line 4307 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[(10) - (13)].l),
		    0., 0., 0., (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(10) - (13)].l));
    ;}
    break;

  case 296:
#line 4315 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 297:
#line 4321 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (15)].l),
		    (yyvsp[(3) - (15)].v)[0], (yyvsp[(3) - (15)].v)[1], (yyvsp[(3) - (15)].v)[2], (yyvsp[(5) - (15)].v)[0], (yyvsp[(5) - (15)].v)[1], (yyvsp[(5) - (15)].v)[2], (yyvsp[(7) - (15)].v)[0], (yyvsp[(7) - (15)].v)[1], (yyvsp[(7) - (15)].v)[2], (yyvsp[(9) - (15)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(12) - (15)].l));
    ;}
    break;

  case 298:
#line 4329 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 299:
#line 4335 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(BOUNDARY_LAYER, (yyvsp[(3) - (6)].l), 0., 0., 0., 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(3) - (6)].l));
    ;}
    break;

  case 300:
#line 4342 "Gmsh.y"
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
#line 4375 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      List_Delete((yyvsp[(6) - (12)].l));
      List_Delete((yyvsp[(11) - (12)].l));
    ;}
    break;

  case 302:
#line 4381 "Gmsh.y"
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
#line 4404 "Gmsh.y"
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
#line 4428 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 305:
#line 4435 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 306:
#line 4442 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 307:
#line 4449 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 308:
#line 4456 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 309:
#line 4463 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 310:
#line 4470 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 311:
#line 4477 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 312:
#line 4484 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 313:
#line 4491 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 314:
#line 4497 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 315:
#line 4504 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 316:
#line 4510 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 317:
#line 4517 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 318:
#line 4523 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 319:
#line 4530 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 320:
#line 4536 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 321:
#line 4543 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 322:
#line 4549 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 323:
#line 4556 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 324:
#line 4562 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 325:
#line 4569 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 326:
#line 4575 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 327:
#line 4582 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 328:
#line 4588 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 329:
#line 4595 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 330:
#line 4601 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 331:
#line 4612 "Gmsh.y"
    {
    ;}
    break;

  case 332:
#line 4615 "Gmsh.y"
    {
    ;}
    break;

  case 333:
#line 4621 "Gmsh.y"
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
#line 4633 "Gmsh.y"
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
#line 4653 "Gmsh.y"
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
#line 4677 "Gmsh.y"
    {
      extr.mesh.ScaleLast = true;
    ;}
    break;

  case 337:
#line 4681 "Gmsh.y"
    {
      extr.mesh.Recombine = true;
    ;}
    break;

  case 338:
#line 4685 "Gmsh.y"
    {
      extr.mesh.Recombine = (yyvsp[(2) - (3)].d) ? true : false;
    ;}
    break;

  case 339:
#line 4689 "Gmsh.y"
    {
      yymsg(0, "Keyword 'QuadTriSngl' deprecated. Use 'QuadTriNoNewVerts' instead.");
    ;}
    break;

  case 340:
#line 4693 "Gmsh.y"
    {
      yymsg(0, "Keyword 'QuadTriSngl' deprecated. Use 'QuadTriNoNewVerts' instead.");
    ;}
    break;

  case 341:
#line 4697 "Gmsh.y"
    {
      yymsg(0, "Method 'QuadTriDbl' deprecated. Use 'QuadTriAddVerts' instead, "
            "which has no requirement for the number of extrusion layers and meshes "
            "with body-centered vertices.");
    ;}
    break;

  case 342:
#line 4703 "Gmsh.y"
    {
      yymsg(0, "Method 'QuadTriDbl' deprecated. Use 'QuadTriAddVerts' instead, "
            "which has no requirement for the number of extrusion layers and meshes "
            "with body-centered vertices.");
    ;}
    break;

  case 343:
#line 4709 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1;
    ;}
    break;

  case 344:
#line 4713 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1_RECOMB;
    ;}
    break;

  case 345:
#line 4717 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1;
    ;}
    break;

  case 346:
#line 4721 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1_RECOMB;
    ;}
    break;

  case 347:
#line 4725 "Gmsh.y"
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
#line 4744 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (6)].c), "Index"))
        extr.mesh.BoundaryLayerIndex = (yyvsp[(4) - (6)].d);
      else if(!strcmp((yyvsp[(2) - (6)].c), "View"))
        extr.mesh.ViewIndex = (yyvsp[(4) - (6)].d);
      Free((yyvsp[(2) - (6)].c));
    ;}
    break;

  case 349:
#line 4756 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Union; ;}
    break;

  case 350:
#line 4757 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Intersection; ;}
    break;

  case 351:
#line 4758 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Difference; ;}
    break;

  case 352:
#line 4759 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Section; ;}
    break;

  case 353:
#line 4760 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Fragments; ;}
    break;

  case 354:
#line 4764 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 355:
#line 4765 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 356:
#line 4766 "Gmsh.y"
    { (yyval.i) = (yyvsp[(2) - (3)].d); ;}
    break;

  case 357:
#line 4771 "Gmsh.y"
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
#line 4804 "Gmsh.y"
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
#line 4831 "Gmsh.y"
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
#line 4853 "Gmsh.y"
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    ;}
    break;

  case 361:
#line 4857 "Gmsh.y"
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
#line 4872 "Gmsh.y"
    {
      (yyval.i) = -1; // left
    ;}
    break;

  case 363:
#line 4876 "Gmsh.y"
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
#line 4892 "Gmsh.y"
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   ;}
    break;

  case 365:
#line 4896 "Gmsh.y"
    {
     (yyval.l) = (yyvsp[(2) - (2)].l);
   ;}
    break;

  case 366:
#line 4901 "Gmsh.y"
    {
      (yyval.i) = 45;
    ;}
    break;

  case 367:
#line 4905 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(2) - (2)].d);
    ;}
    break;

  case 368:
#line 4911 "Gmsh.y"
    {
      (yyval.l) = List_Create(1, 1, sizeof(double));
    ;}
    break;

  case 369:
#line 4915 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
    ;}
    break;

  case 370:
#line 4922 "Gmsh.y"
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
#line 4978 "Gmsh.y"
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
#line 5048 "Gmsh.y"
    {
      yymsg(1, "Elliptic Surface is deprecated: use Transfinite instead (with smoothing)");
      List_Delete((yyvsp[(7) - (8)].l));
    ;}
    break;

  case 373:
#line 5053 "Gmsh.y"
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
#line 5120 "Gmsh.y"
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
#line 5156 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (8)].l)); i++){
	double d;
	List_Read((yyvsp[(4) - (8)].l), i, &d);
	CTX::instance()->mesh.algo2d_per_face[(int)d] = (int)(yyvsp[(7) - (8)].d);
      }
    ;}
    break;

  case 376:
#line 5164 "Gmsh.y"
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
#line 5207 "Gmsh.y"
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
#line 5246 "Gmsh.y"
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
#line 5267 "Gmsh.y"
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
#line 5299 "Gmsh.y"
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
#line 5326 "Gmsh.y"
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
#line 5352 "Gmsh.y"
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
#line 5378 "Gmsh.y"
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
#line 5404 "Gmsh.y"
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
#line 5430 "Gmsh.y"
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
#line 5451 "Gmsh.y"
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
#line 5479 "Gmsh.y"
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
#line 5507 "Gmsh.y"
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
#line 5535 "Gmsh.y"
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
#line 5563 "Gmsh.y"
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
#line 5591 "Gmsh.y"
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
#line 5630 "Gmsh.y"
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
#line 5669 "Gmsh.y"
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
#line 5690 "Gmsh.y"
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
#line 5711 "Gmsh.y"
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
#line 5738 "Gmsh.y"
    {
      ReplaceAllDuplicates();
    ;}
    break;

  case 397:
#line 5742 "Gmsh.y"
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
#line 5752 "Gmsh.y"
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
#line 5786 "Gmsh.y"
    { (yyval.c) = (char*)"Homology"; ;}
    break;

  case 400:
#line 5787 "Gmsh.y"
    { (yyval.c) = (char*)"Cohomology"; ;}
    break;

  case 401:
#line 5788 "Gmsh.y"
    { (yyval.c) = (char*)"Betti"; ;}
    break;

  case 402:
#line 5793 "Gmsh.y"
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest((yyvsp[(1) - (2)].c), domain, subdomain, dim);
    ;}
    break;

  case 403:
#line 5799 "Gmsh.y"
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
#line 5811 "Gmsh.y"
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
#line 5829 "Gmsh.y"
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
#line 5856 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d);           ;}
    break;

  case 407:
#line 5857 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (3)].d);           ;}
    break;

  case 408:
#line 5858 "Gmsh.y"
    { (yyval.d) = -(yyvsp[(2) - (2)].d);          ;}
    break;

  case 409:
#line 5859 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);           ;}
    break;

  case 410:
#line 5860 "Gmsh.y"
    { (yyval.d) = !(yyvsp[(2) - (2)].d);          ;}
    break;

  case 411:
#line 5861 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) - (yyvsp[(3) - (3)].d);      ;}
    break;

  case 412:
#line 5862 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) + (yyvsp[(3) - (3)].d);      ;}
    break;

  case 413:
#line 5863 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) * (yyvsp[(3) - (3)].d);      ;}
    break;

  case 414:
#line 5865 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (3)].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));
      else
	(yyval.d) = (yyvsp[(1) - (3)].d) / (yyvsp[(3) - (3)].d);
    ;}
    break;

  case 415:
#line 5871 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) % (int)(yyvsp[(3) - (3)].d);  ;}
    break;

  case 416:
#line 5872 "Gmsh.y"
    { (yyval.d) = pow((yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));  ;}
    break;

  case 417:
#line 5873 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d);      ;}
    break;

  case 418:
#line 5874 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) > (yyvsp[(3) - (3)].d);      ;}
    break;

  case 419:
#line 5875 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) <= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 420:
#line 5876 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) >= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 421:
#line 5877 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) == (yyvsp[(3) - (3)].d);     ;}
    break;

  case 422:
#line 5878 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) != (yyvsp[(3) - (3)].d);     ;}
    break;

  case 423:
#line 5879 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) && (yyvsp[(3) - (3)].d);     ;}
    break;

  case 424:
#line 5880 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) || (yyvsp[(3) - (3)].d);     ;}
    break;

  case 425:
#line 5881 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (5)].d) ? (yyvsp[(3) - (5)].d) : (yyvsp[(5) - (5)].d); ;}
    break;

  case 426:
#line 5882 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 427:
#line 5883 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 428:
#line 5884 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 429:
#line 5885 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 430:
#line 5886 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 431:
#line 5887 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 432:
#line 5888 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 433:
#line 5889 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 434:
#line 5890 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 435:
#line 5891 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 436:
#line 5892 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 437:
#line 5893 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 438:
#line 5894 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 439:
#line 5895 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 440:
#line 5896 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 441:
#line 5897 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 442:
#line 5898 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 443:
#line 5899 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d) + 0.5); ;}
    break;

  case 444:
#line 5900 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 445:
#line 5901 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 446:
#line 5902 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 447:
#line 5903 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 448:
#line 5912 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 449:
#line 5913 "Gmsh.y"
    { (yyval.d) = 3.141592653589793; ;}
    break;

  case 450:
#line 5914 "Gmsh.y"
    { (yyval.d) = (double)ImbricatedTest; ;}
    break;

  case 451:
#line 5915 "Gmsh.y"
    { (yyval.d) = Msg::GetCommRank(); ;}
    break;

  case 452:
#line 5916 "Gmsh.y"
    { (yyval.d) = Msg::GetCommSize(); ;}
    break;

  case 453:
#line 5917 "Gmsh.y"
    { (yyval.d) = GetGmshMajorVersion(); ;}
    break;

  case 454:
#line 5918 "Gmsh.y"
    { (yyval.d) = GetGmshMinorVersion(); ;}
    break;

  case 455:
#line 5919 "Gmsh.y"
    { (yyval.d) = GetGmshPatchVersion(); ;}
    break;

  case 456:
#line 5920 "Gmsh.y"
    { (yyval.d) = Cpu(); ;}
    break;

  case 457:
#line 5921 "Gmsh.y"
    { (yyval.d) = GetMemoryUsage()/1024./1024.; ;}
    break;

  case 458:
#line 5922 "Gmsh.y"
    { (yyval.d) = TotalRam(); ;}
    break;

  case 459:
#line 5927 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 460:
#line 5929 "Gmsh.y"
    {
      std::vector<double> val(1, (yyvsp[(3) - (6)].d));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.d) = val[0];
    ;}
    break;

  case 461:
#line 5935 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 462:
#line 5940 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 463:
#line 5945 "Gmsh.y"
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
#line 5962 "Gmsh.y"
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
#line 5980 "Gmsh.y"
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
#line 5998 "Gmsh.y"
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
#line 6016 "Gmsh.y"
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
#line 6034 "Gmsh.y"
    {
      (yyval.d) = gmsh_yysymbols.count((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 469:
#line 6039 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.d) = !StatFile(tmp);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 470:
#line 6045 "Gmsh.y"
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
#line 6060 "Gmsh.y"
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
#line 6079 "Gmsh.y"
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
#line 6099 "Gmsh.y"
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
#line 6119 "Gmsh.y"
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
#line 6139 "Gmsh.y"
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
#line 6162 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), (yyval.d));
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 477:
#line 6167 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), (yyval.d));
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 478:
#line 6172 "Gmsh.y"
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
#line 6182 "Gmsh.y"
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
#line 6192 "Gmsh.y"
    {
      (yyval.d) = Msg::GetValue((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 481:
#line 6197 "Gmsh.y"
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
#line 6208 "Gmsh.y"
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
#line 6217 "Gmsh.y"
    {
      (yyval.d) = strlen((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 484:
#line 6222 "Gmsh.y"
    {
      (yyval.d) = strcmp((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 485:
#line 6227 "Gmsh.y"
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
#line 6254 "Gmsh.y"
    {
      memcpy((yyval.v), (yyvsp[(1) - (1)].v), 5*sizeof(double));
    ;}
    break;

  case 487:
#line 6258 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 488:
#line 6262 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 489:
#line 6266 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] - (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 490:
#line 6270 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] + (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 491:
#line 6277 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (11)].d);  (yyval.v)[1] = (yyvsp[(4) - (11)].d);  (yyval.v)[2] = (yyvsp[(6) - (11)].d);  (yyval.v)[3] = (yyvsp[(8) - (11)].d); (yyval.v)[4] = (yyvsp[(10) - (11)].d);
    ;}
    break;

  case 492:
#line 6281 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (9)].d);  (yyval.v)[1] = (yyvsp[(4) - (9)].d);  (yyval.v)[2] = (yyvsp[(6) - (9)].d);  (yyval.v)[3] = (yyvsp[(8) - (9)].d); (yyval.v)[4] = 1.0;
    ;}
    break;

  case 493:
#line 6285 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 494:
#line 6289 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 495:
#line 6296 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].l)));
    ;}
    break;

  case 496:
#line 6301 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].l)));
    ;}
    break;

  case 497:
#line 6308 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 498:
#line 6313 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 499:
#line 6317 "Gmsh.y"
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    ;}
    break;

  case 500:
#line 6322 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 501:
#line 6326 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 502:
#line 6334 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (5)].d);
      }
    ;}
    break;

  case 503:
#line 6345 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 504:
#line 6349 "Gmsh.y"
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
#line 6361 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 506:
#line 6369 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (3)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (3)].d);
      }
    ;}
    break;

  case 507:
#line 6377 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      for(double d = (yyvsp[(1) - (3)].d); ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d <= (yyvsp[(3) - (3)].d)) : (d >= (yyvsp[(3) - (3)].d));
          ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d += 1.) : (d -= 1.))
	List_Add((yyval.l), &d);
    ;}
    break;

  case 508:
#line 6384 "Gmsh.y"
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
#line 6394 "Gmsh.y"
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
#line 6423 "Gmsh.y"
    {
      (yyval.l) = GetAllElementaryEntityNumbers(0);
    ;}
    break;

  case 511:
#line 6427 "Gmsh.y"
    {
      (yyval.l) = GetAllElementaryEntityNumbers(1);
    ;}
    break;

  case 512:
#line 6431 "Gmsh.y"
    {
      (yyval.l) = GetAllElementaryEntityNumbers(2);
    ;}
    break;

  case 513:
#line 6435 "Gmsh.y"
    {
      (yyval.l) = GetAllElementaryEntityNumbers(3);
    ;}
    break;

  case 514:
#line 6439 "Gmsh.y"
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(0);
    ;}
    break;

  case 515:
#line 6443 "Gmsh.y"
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(1);
    ;}
    break;

  case 516:
#line 6447 "Gmsh.y"
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(2);
    ;}
    break;

  case 517:
#line 6451 "Gmsh.y"
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(3);
    ;}
    break;

  case 518:
#line 6455 "Gmsh.y"
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
#line 6484 "Gmsh.y"
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
#line 6513 "Gmsh.y"
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
#line 6542 "Gmsh.y"
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
#line 6572 "Gmsh.y"
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
#line 6585 "Gmsh.y"
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
#line 6598 "Gmsh.y"
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
#line 6611 "Gmsh.y"
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
#line 6623 "Gmsh.y"
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
#line 6633 "Gmsh.y"
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
#line 6643 "Gmsh.y"
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
#line 6653 "Gmsh.y"
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
#line 6665 "Gmsh.y"
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
#line 6678 "Gmsh.y"
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
#line 6690 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 533:
#line 6694 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 534:
#line 6698 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (6)].l);
    ;}
    break;

  case 535:
#line 6702 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (6)].l);
    ;}
    break;

  case 536:
#line 6706 "Gmsh.y"
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
#line 6724 "Gmsh.y"
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
#line 6742 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = (yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1);
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 539:
#line 6750 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = pow(10,(yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1));
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 540:
#line 6758 "Gmsh.y"
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
#line 6787 "Gmsh.y"
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
#line 6800 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 543:
#line 6805 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 544:
#line 6809 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].d)));
    ;}
    break;

  case 545:
#line 6813 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (3)].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 546:
#line 6825 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (9)].d), (int)(yyvsp[(4) - (9)].d), (int)(yyvsp[(6) - (9)].d), (int)(yyvsp[(8) - (9)].d));
    ;}
    break;

  case 547:
#line 6829 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (7)].d), (int)(yyvsp[(4) - (7)].d), (int)(yyvsp[(6) - (7)].d), 255);
    ;}
    break;

  case 548:
#line 6841 "Gmsh.y"
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

  case 549:
#line 6858 "Gmsh.y"
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(5) - (5)].c), val);
      (yyval.u) = val;
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(5) - (5)].c));
    ;}
    break;

  case 550:
#line 6868 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 551:
#line 6872 "Gmsh.y"
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

  case 552:
#line 6887 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].u)));
    ;}
    break;

  case 553:
#line 6892 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].u)));
    ;}
    break;

  case 554:
#line 6899 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 555:
#line 6903 "Gmsh.y"
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

  case 556:
#line 6916 "Gmsh.y"
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
#line 6930 "Gmsh.y"
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
#line 6944 "Gmsh.y"
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
#line 6958 "Gmsh.y"
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
#line 6972 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 561:
#line 6980 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 562:
#line 6991 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 563:
#line 6995 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 564:
#line 6999 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    ;}
    break;

  case 565:
#line 7007 "Gmsh.y"
    {
      std::string exe = Msg::GetExecutableName();
      (yyval.c) = (char *)Malloc(exe.size() + 1);
      strcpy((yyval.c), exe.c_str());
    ;}
    break;

  case 566:
#line 7013 "Gmsh.y"
    {
      std::string action = Msg::GetOnelabAction();
      (yyval.c) = (char *)Malloc(action.size() + 1);
      strcpy((yyval.c), action.c_str());
    ;}
    break;

  case 567:
#line 7019 "Gmsh.y"
    {
      const char *env = GetEnvironmentVar((yyvsp[(3) - (4)].c));
      if(!env) env = "";
      (yyval.c) = (char *)Malloc((sizeof(env) + 1) * sizeof(char));
      strcpy((yyval.c), env);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 568:
#line 7027 "Gmsh.y"
    {
      std::string s = Msg::GetString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 569:
#line 7035 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (4)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 570:
#line 7042 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 571:
#line 7050 "Gmsh.y"
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

  case 572:
#line 7065 "Gmsh.y"
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

  case 573:
#line 7079 "Gmsh.y"
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

  case 574:
#line 7093 "Gmsh.y"
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

  case 575:
#line 7105 "Gmsh.y"
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

  case 576:
#line 7121 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = toupper((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 577:
#line 7130 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = tolower((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 578:
#line 7139 "Gmsh.y"
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

  case 579:
#line 7149 "Gmsh.y"
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

  case 580:
#line 7160 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (8)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (8)].d), (int)(yyvsp[(7) - (8)].d));
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (8)].c));
    ;}
    break;

  case 581:
#line 7168 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (6)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (6)].d), std::string::npos);
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 582:
#line 7176 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 583:
#line 7180 "Gmsh.y"
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

  case 584:
#line 7199 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 585:
#line 7206 "Gmsh.y"
    {
      std::string tmp = SplitFileName(GetAbsolutePath(gmsh_yyname))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
    ;}
    break;

  case 586:
#line 7212 "Gmsh.y"
    {
      std::string tmp = SplitFileName((yyvsp[(3) - (4)].c))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 587:
#line 7219 "Gmsh.y"
    {
      std::string tmp = GetAbsolutePath((yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 588:
#line 7226 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 589:
#line 7228 "Gmsh.y"
    {
      std::string val((yyvsp[(3) - (6)].c));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.c) = (char*)Malloc((val.size() + 1) * sizeof(char));
      strcpy((yyval.c), val.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 590:
#line 7239 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].c)));
    ;}
    break;

  case 591:
#line 7244 "Gmsh.y"
    { List_Add((yyval.l), &((yyvsp[(3) - (3)].c))); ;}
    break;

  case 592:
#line 7250 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 593:
#line 7259 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char)) ;
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)) ; strcat((yyval.c), tmpstr) ;
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 594:
#line 7272 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 595:
#line 7275 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 596:
#line 7279 "Gmsh.y"
    { (yyval.c) = (yyvsp[(3) - (4)].c); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 14712 "Gmsh.tab.cpp"
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


#line 7282 "Gmsh.y"


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

