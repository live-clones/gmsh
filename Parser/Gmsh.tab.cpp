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
     tRecombine = 391,
     tSmoother = 392,
     tSplit = 393,
     tDelete = 394,
     tCoherence = 395,
     tIntersect = 396,
     tMeshAlgorithm = 397,
     tReverse = 398,
     tLayers = 399,
     tScaleLast = 400,
     tHole = 401,
     tAlias = 402,
     tAliasWithOptions = 403,
     tCopyOptions = 404,
     tQuadTriAddVerts = 405,
     tQuadTriNoNewVerts = 406,
     tQuadTriSngl = 407,
     tQuadTriDbl = 408,
     tRecombLaterals = 409,
     tTransfQuadTri = 410,
     tText2D = 411,
     tText3D = 412,
     tInterpolationScheme = 413,
     tTime = 414,
     tCombine = 415,
     tBSpline = 416,
     tBezier = 417,
     tNurbs = 418,
     tNurbsOrder = 419,
     tNurbsKnots = 420,
     tColor = 421,
     tColorTable = 422,
     tFor = 423,
     tIn = 424,
     tEndFor = 425,
     tIf = 426,
     tElseIf = 427,
     tElse = 428,
     tEndIf = 429,
     tExit = 430,
     tAbort = 431,
     tField = 432,
     tReturn = 433,
     tCall = 434,
     tSlide = 435,
     tMacro = 436,
     tShow = 437,
     tHide = 438,
     tGetValue = 439,
     tGetStringValue = 440,
     tGetEnv = 441,
     tGetString = 442,
     tGetNumber = 443,
     tHomology = 444,
     tCohomology = 445,
     tBetti = 446,
     tExists = 447,
     tFileExists = 448,
     tGMSH_MAJOR_VERSION = 449,
     tGMSH_MINOR_VERSION = 450,
     tGMSH_PATCH_VERSION = 451,
     tGmshExecutableName = 452,
     tSetPartition = 453,
     tNameToString = 454,
     tStringToName = 455,
     tAFFECTDIVIDE = 456,
     tAFFECTTIMES = 457,
     tAFFECTMINUS = 458,
     tAFFECTPLUS = 459,
     tOR = 460,
     tAND = 461,
     tNOTEQUAL = 462,
     tEQUAL = 463,
     tGREATEROREQUAL = 464,
     tLESSOREQUAL = 465,
     UNARYPREC = 466,
     tMINUSMINUS = 467,
     tPLUSPLUS = 468
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
#define tRecombine 391
#define tSmoother 392
#define tSplit 393
#define tDelete 394
#define tCoherence 395
#define tIntersect 396
#define tMeshAlgorithm 397
#define tReverse 398
#define tLayers 399
#define tScaleLast 400
#define tHole 401
#define tAlias 402
#define tAliasWithOptions 403
#define tCopyOptions 404
#define tQuadTriAddVerts 405
#define tQuadTriNoNewVerts 406
#define tQuadTriSngl 407
#define tQuadTriDbl 408
#define tRecombLaterals 409
#define tTransfQuadTri 410
#define tText2D 411
#define tText3D 412
#define tInterpolationScheme 413
#define tTime 414
#define tCombine 415
#define tBSpline 416
#define tBezier 417
#define tNurbs 418
#define tNurbsOrder 419
#define tNurbsKnots 420
#define tColor 421
#define tColorTable 422
#define tFor 423
#define tIn 424
#define tEndFor 425
#define tIf 426
#define tElseIf 427
#define tElse 428
#define tEndIf 429
#define tExit 430
#define tAbort 431
#define tField 432
#define tReturn 433
#define tCall 434
#define tSlide 435
#define tMacro 436
#define tShow 437
#define tHide 438
#define tGetValue 439
#define tGetStringValue 440
#define tGetEnv 441
#define tGetString 442
#define tGetNumber 443
#define tHomology 444
#define tCohomology 445
#define tBetti 446
#define tExists 447
#define tFileExists 448
#define tGMSH_MAJOR_VERSION 449
#define tGMSH_MINOR_VERSION 450
#define tGMSH_PATCH_VERSION 451
#define tGmshExecutableName 452
#define tSetPartition 453
#define tNameToString 454
#define tStringToName 455
#define tAFFECTDIVIDE 456
#define tAFFECTTIMES 457
#define tAFFECTMINUS 458
#define tAFFECTPLUS 459
#define tOR 460
#define tAND 461
#define tNOTEQUAL 462
#define tEQUAL 463
#define tGREATEROREQUAL 464
#define tLESSOREQUAL 465
#define UNARYPREC 466
#define tMINUSMINUS 467
#define tPLUSPLUS 468




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
#line 656 "Gmsh.tab.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 669 "Gmsh.tab.cpp"

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
#define YYLAST   14469

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  234
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  105
/* YYNRULES -- Number of rules.  */
#define YYNRULES  596
/* YYNRULES -- Number of states.  */
#define YYNSTATES  2224

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   468

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   219,     2,   229,     2,   218,     2,     2,
     224,   225,   216,   214,   230,   215,   228,   217,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     210,     2,   211,   205,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   226,     2,   227,   223,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   231,     2,   232,   233,     2,     2,     2,
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
     206,   207,   208,   209,   212,   213,   220,   221,   222
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
    1109,  1118,  1123,  1132,  1145,  1154,  1163,  1171,  1179,  1188,
    1193,  1202,  1211,  1217,  1229,  1235,  1245,  1255,  1260,  1270,
    1280,  1282,  1284,  1285,  1288,  1295,  1302,  1309,  1316,  1325,
    1336,  1351,  1368,  1381,  1396,  1411,  1426,  1441,  1450,  1459,
    1466,  1471,  1478,  1485,  1489,  1494,  1500,  1507,  1513,  1517,
    1521,  1526,  1532,  1537,  1543,  1547,  1553,  1561,  1569,  1573,
    1581,  1585,  1588,  1591,  1594,  1597,  1600,  1616,  1619,  1622,
    1625,  1628,  1631,  1648,  1660,  1667,  1676,  1685,  1696,  1698,
    1701,  1704,  1706,  1710,  1714,  1719,  1724,  1726,  1728,  1734,
    1746,  1760,  1761,  1769,  1770,  1784,  1785,  1801,  1802,  1809,
    1819,  1827,  1840,  1843,  1847,  1856,  1865,  1874,  1887,  1900,
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
     235,     0,    -1,   236,    -1,     1,     6,    -1,    -1,   236,
     237,    -1,   240,    -1,   239,    -1,   260,    -1,   279,    -1,
     280,    -1,   284,    -1,   285,    -1,   286,    -1,   287,    -1,
     291,    -1,   309,    -1,   310,    -1,   316,    -1,   317,    -1,
     290,    -1,   289,    -1,   288,    -1,   283,    -1,   319,    -1,
     211,    -1,   211,   211,    -1,    42,   224,   333,   225,     6,
      -1,    43,   224,   333,   225,     6,    -1,    42,   224,   333,
     225,   238,   333,     6,    -1,    42,   224,   333,   230,   329,
     225,     6,    -1,    43,   224,   333,   230,   329,   225,     6,
      -1,    42,   224,   333,   230,   329,   225,   238,   333,     6,
      -1,     4,   333,   231,   241,   232,     6,    -1,   147,     4,
     226,   320,   227,     6,    -1,   148,     4,   226,   320,   227,
       6,    -1,   149,     4,   226,   320,   230,   320,   227,     6,
      -1,    -1,   241,   244,    -1,   241,   248,    -1,   241,   251,
      -1,   241,   253,    -1,   241,   254,    -1,   320,    -1,   242,
     230,   320,    -1,   320,    -1,   243,   230,   320,    -1,    -1,
      -1,     4,   245,   224,   242,   225,   246,   231,   243,   232,
       6,    -1,   333,    -1,   247,   230,   333,    -1,    -1,   156,
     224,   320,   230,   320,   230,   320,   225,   249,   231,   247,
     232,     6,    -1,   333,    -1,   250,   230,   333,    -1,    -1,
     157,   224,   320,   230,   320,   230,   320,   230,   320,   225,
     252,   231,   250,   232,     6,    -1,   158,   231,   325,   232,
     231,   325,   232,     6,    -1,   158,   231,   325,   232,   231,
     325,   232,   231,   325,   232,   231,   325,   232,     6,    -1,
      -1,   159,   255,   231,   243,   232,     6,    -1,     7,    -1,
     204,    -1,   203,    -1,   202,    -1,   201,    -1,   222,    -1,
     221,    -1,   224,    -1,   226,    -1,   225,    -1,   227,    -1,
      78,   226,   262,   227,     6,    -1,    79,   226,   267,   227,
       6,    -1,    82,   258,   334,   230,   320,   259,     6,    -1,
      83,   258,   338,   230,   334,   259,     6,    -1,   338,   256,
     326,     6,    -1,   338,   257,     6,    -1,     4,   226,   227,
     256,   326,     6,    -1,   337,   226,   227,   256,   326,     6,
      -1,     4,   226,   320,   227,   256,   320,     6,    -1,   337,
     226,   320,   227,   256,   320,     6,    -1,     4,   226,   320,
     227,   257,     6,    -1,   337,   226,   320,   227,   257,     6,
      -1,     4,   258,   231,   329,   232,   259,   256,   326,     6,
      -1,   337,   258,   231,   329,   232,   259,   256,   326,     6,
      -1,     4,   224,   225,   256,   326,     6,    -1,   337,   224,
     225,   256,   326,     6,    -1,     4,   224,   320,   225,   256,
     320,     6,    -1,   337,   224,   320,   225,   256,   320,     6,
      -1,     4,   224,   320,   225,   257,     6,    -1,   337,   224,
     320,   225,   257,     6,    -1,   338,     7,   334,     6,    -1,
       4,   226,   227,     7,    44,   258,   259,     6,    -1,   337,
     226,   227,     7,    44,   258,   259,     6,    -1,     4,   226,
     227,     7,    44,   258,   336,   259,     6,    -1,   337,   226,
     227,     7,    44,   258,   336,   259,     6,    -1,     4,   226,
     227,   204,    44,   258,   336,   259,     6,    -1,   337,   226,
     227,   204,    44,   258,   336,   259,     6,    -1,     4,   224,
     225,     7,    44,   258,   259,     6,    -1,   337,   224,   225,
       7,    44,   258,   259,     6,    -1,     4,   224,   225,     7,
      44,   258,   336,   259,     6,    -1,   337,   224,   225,     7,
      44,   258,   336,   259,     6,    -1,     4,   224,   225,   204,
      44,   258,   336,   259,     6,    -1,   337,   224,   225,   204,
      44,   258,   336,   259,     6,    -1,     4,   228,     4,     7,
     334,     6,    -1,     4,   226,   320,   227,   228,     4,     7,
     334,     6,    -1,     4,   228,     4,   256,   320,     6,    -1,
       4,   226,   320,   227,   228,     4,   256,   320,     6,    -1,
       4,   228,     4,   257,     6,    -1,     4,   226,   320,   227,
     228,     4,   257,     6,    -1,     4,   228,   166,   228,     4,
       7,   330,     6,    -1,     4,   226,   320,   227,   228,   166,
     228,     4,     7,   330,     6,    -1,     4,   228,   167,     7,
     331,     6,    -1,     4,   226,   320,   227,   228,   167,     7,
     331,     6,    -1,     4,   177,     7,   320,     6,    -1,   177,
     226,   320,   227,     7,     4,     6,    -1,   177,   226,   320,
     227,   228,     4,     7,   320,     6,    -1,   177,   226,   320,
     227,   228,     4,     7,   334,     6,    -1,   177,   226,   320,
     227,   228,     4,     7,   231,   329,   232,     6,    -1,   177,
     226,   320,   227,   228,     4,     6,    -1,   121,   224,     4,
     225,   228,     4,     7,   320,     6,    -1,   121,   224,     4,
     225,   228,     4,     7,   334,     6,    -1,    -1,   230,    -1,
      -1,   262,   261,   338,    -1,   262,   261,   338,     7,   320,
      -1,    -1,   262,   261,   338,     7,   231,   326,   263,   269,
     232,    -1,    -1,   262,   261,   338,   226,   227,     7,   231,
     326,   264,   269,   232,    -1,    -1,   262,   261,   338,   224,
     225,     7,   231,   326,   265,   269,   232,    -1,   262,   261,
     338,     7,   334,    -1,    -1,   262,   261,   338,     7,   231,
     334,   266,   271,   232,    -1,    -1,   267,   261,   333,    -1,
     320,     7,   334,    -1,   268,   230,   320,     7,   334,    -1,
     328,     7,   338,   224,   225,    -1,    -1,   269,   270,    -1,
     230,     4,   326,    -1,   230,     4,   231,   268,   232,    -1,
     230,     4,   334,    -1,    -1,   271,   272,    -1,   230,     4,
     320,    -1,   230,     4,   334,    -1,   230,   181,   334,    -1,
     230,     4,   231,   336,   232,    -1,   320,    -1,   334,    -1,
     334,   230,   320,    -1,   320,    -1,   334,    -1,   334,   230,
     320,    -1,   320,    -1,   334,    -1,   334,   230,   320,    -1,
     320,    -1,   334,    -1,   334,   230,   320,    -1,    -1,   169,
      88,   231,   320,   232,    -1,    -1,   112,   323,    -1,   109,
     224,   333,   225,     6,    -1,    84,   224,   320,   225,     7,
     323,     6,    -1,   116,    84,   224,   273,   225,   256,   326,
       6,    -1,   102,   103,   326,     7,   320,     6,    -1,    87,
     224,   320,   225,     7,   326,     6,    -1,   122,    87,   326,
       6,    -1,    91,   224,   320,   225,     7,   326,     6,    -1,
      85,   224,   320,   225,     7,   326,   278,     6,    -1,    86,
     224,   320,   225,     7,   326,   278,     6,    -1,   161,   224,
     320,   225,     7,   326,     6,    -1,   162,   224,   320,   225,
       7,   326,     6,    -1,   163,   224,   320,   225,     7,   326,
     165,   326,   164,   320,     6,    -1,    87,     4,   224,   320,
     225,     7,   326,     6,    -1,   117,    87,   326,     6,    -1,
     117,    87,   224,   320,   225,     7,   326,     6,    -1,   116,
      87,   224,   274,   225,   256,   326,     6,    -1,   112,    90,
     224,   320,   225,     7,   326,     6,    -1,   113,    90,   224,
     320,   225,     7,   326,   277,     6,    -1,    12,    13,     6,
      -1,    13,    90,   320,     6,    -1,   104,    90,   224,   320,
     225,     7,     5,     5,     5,     6,    -1,    88,   224,   320,
     225,     7,   326,     6,    -1,    89,   224,   320,   225,     7,
     326,     6,    -1,    93,   224,   320,   225,     7,   326,     6,
      -1,    96,   224,   320,   225,     7,   326,     6,    -1,   100,
     224,   320,   225,     7,   326,     6,    -1,   101,   224,   320,
     225,     7,   326,     6,    -1,    94,   224,   320,   225,     7,
     326,     6,    -1,    95,   224,   320,   225,     7,   326,     6,
      -1,   111,   224,   320,   225,     7,   326,     6,    -1,    90,
       4,   224,   320,   225,     7,   326,     6,    -1,   117,    90,
     326,     6,    -1,   117,    90,   224,   320,   225,     7,   326,
       6,    -1,   117,    90,   224,   320,   225,     7,   326,     4,
     231,   325,   232,     6,    -1,   116,    90,   224,   275,   225,
     256,   326,     6,    -1,   115,    92,   224,   320,   225,     7,
     326,     6,    -1,    92,   224,   320,   225,     7,   326,     6,
      -1,   110,   224,   320,   225,     7,   326,     6,    -1,   113,
     110,   224,   320,   225,     7,   326,     6,    -1,   117,    92,
     326,     6,    -1,   117,    92,   224,   320,   225,     7,   326,
       6,    -1,   116,    92,   224,   276,   225,   256,   326,     6,
      -1,   125,   323,   231,   281,   232,    -1,   124,   231,   323,
     230,   323,   230,   320,   232,   231,   281,   232,    -1,   126,
     323,   231,   281,   232,    -1,   127,   231,   323,   230,   320,
     232,   231,   281,   232,    -1,   127,   231,   323,   230,   323,
     232,   231,   281,   232,    -1,     4,   231,   281,   232,    -1,
     141,    87,   231,   329,   232,    90,   231,   320,   232,    -1,
     138,    87,   224,   320,   225,   231,   329,   232,     6,    -1,
     282,    -1,   280,    -1,    -1,   282,   279,    -1,   282,    84,
     231,   329,   232,     6,    -1,   282,    87,   231,   329,   232,
       6,    -1,   282,    90,   231,   329,   232,     6,    -1,   282,
      92,   231,   329,   232,     6,    -1,   129,   112,   224,   320,
     225,     7,   326,     6,    -1,   129,    84,   224,   320,   225,
       7,   231,   325,   232,     6,    -1,   129,   112,   224,   320,
     225,     7,   231,   323,   230,   323,   230,   329,   232,     6,
      -1,   129,   112,   224,   320,   225,     7,   231,   323,   230,
     323,   230,   323,   230,   329,   232,     6,    -1,   129,    88,
     224,   320,   225,     7,   231,   323,   230,   329,   232,     6,
      -1,   129,    94,   224,   320,   225,     7,   231,   323,   230,
     323,   230,   329,   232,     6,    -1,   129,    95,   224,   320,
     225,     7,   231,   323,   230,   323,   230,   329,   232,     6,
      -1,   129,    97,   224,   320,   225,     7,   231,   323,   230,
     323,   230,   329,   232,     6,    -1,   129,    98,   224,   320,
     225,     7,   231,   323,   230,   323,   230,   329,   232,     6,
      -1,   129,     4,   224,   320,   225,     7,   326,     6,    -1,
     129,     4,   224,   320,   225,     7,     5,     6,    -1,   129,
       4,   231,   320,   232,     6,    -1,   139,   231,   282,   232,
      -1,   139,   177,   226,   320,   227,     6,    -1,   139,     4,
     226,   320,   227,     6,    -1,   139,   338,     6,    -1,   139,
       4,     4,     6,    -1,   166,   330,   231,   282,   232,    -1,
     123,   166,   330,   231,   282,   232,    -1,   198,   320,   231,
     282,   232,    -1,   182,     5,     6,    -1,   183,     5,     6,
      -1,   182,   231,   282,   232,    -1,   123,   182,   231,   282,
     232,    -1,   183,   231,   282,   232,    -1,   123,   183,   231,
     282,   232,    -1,     4,   334,     6,    -1,    71,   224,   336,
     225,     6,    -1,     4,     4,   226,   320,   227,   333,     6,
      -1,     4,     4,     4,   226,   320,   227,     6,    -1,     4,
     320,     6,    -1,   121,   224,     4,   225,   228,     4,     6,
      -1,   160,     4,     6,    -1,   175,     6,    -1,   176,     6,
      -1,    68,     6,    -1,    69,     6,    -1,    62,     6,    -1,
      62,   231,   320,   230,   320,   230,   320,   230,   320,   230,
     320,   230,   320,   232,     6,    -1,    63,     6,    -1,    64,
       6,    -1,    75,     6,    -1,    76,     6,    -1,   106,     6,
      -1,   107,   231,   329,   232,   231,   329,   232,   231,   325,
     232,   231,   320,   230,   320,   232,     6,    -1,   180,   224,
     231,   329,   232,   230,   334,   230,   334,   225,     6,    -1,
     168,   224,   320,     8,   320,   225,    -1,   168,   224,   320,
       8,   320,     8,   320,   225,    -1,   168,     4,   169,   231,
     320,     8,   320,   232,    -1,   168,     4,   169,   231,   320,
       8,   320,     8,   320,   232,    -1,   170,    -1,   181,     4,
      -1,   181,   334,    -1,   178,    -1,   179,   338,     6,    -1,
     179,   334,     6,    -1,   171,   224,   320,   225,    -1,   172,
     224,   320,   225,    -1,   173,    -1,   174,    -1,   128,   323,
     231,   282,   232,    -1,   128,   231,   323,   230,   323,   230,
     320,   232,   231,   282,   232,    -1,   128,   231,   323,   230,
     323,   230,   323,   230,   320,   232,   231,   282,   232,    -1,
      -1,   128,   323,   231,   282,   292,   305,   232,    -1,    -1,
     128,   231,   323,   230,   323,   230,   320,   232,   231,   282,
     293,   305,   232,    -1,    -1,   128,   231,   323,   230,   323,
     230,   323,   230,   320,   232,   231,   282,   294,   305,   232,
      -1,    -1,   128,   231,   282,   295,   305,   232,    -1,   128,
     231,   282,   232,   119,    87,   231,   326,   232,    -1,   128,
     231,   320,   232,   231,   282,   232,    -1,   128,   231,   320,
     232,   231,   282,   232,   120,    90,   231,   326,   232,    -1,
     110,   326,    -1,   113,   110,   326,    -1,   128,    84,   231,
     320,   230,   323,   232,     6,    -1,   128,    87,   231,   320,
     230,   323,   232,     6,    -1,   128,    90,   231,   320,   230,
     323,   232,     6,    -1,   128,    84,   231,   320,   230,   323,
     230,   323,   230,   320,   232,     6,    -1,   128,    87,   231,
     320,   230,   323,   230,   323,   230,   320,   232,     6,    -1,
     128,    90,   231,   320,   230,   323,   230,   323,   230,   320,
     232,     6,    -1,   128,    84,   231,   320,   230,   323,   230,
     323,   230,   323,   230,   320,   232,     6,    -1,   128,    87,
     231,   320,   230,   323,   230,   323,   230,   323,   230,   320,
     232,     6,    -1,   128,    90,   231,   320,   230,   323,   230,
     323,   230,   323,   230,   320,   232,     6,    -1,    -1,   128,
      84,   231,   320,   230,   323,   232,   296,   231,   305,   232,
       6,    -1,    -1,   128,    87,   231,   320,   230,   323,   232,
     297,   231,   305,   232,     6,    -1,    -1,   128,    90,   231,
     320,   230,   323,   232,   298,   231,   305,   232,     6,    -1,
      -1,   128,    84,   231,   320,   230,   323,   230,   323,   230,
     320,   232,   299,   231,   305,   232,     6,    -1,    -1,   128,
      87,   231,   320,   230,   323,   230,   323,   230,   320,   232,
     300,   231,   305,   232,     6,    -1,    -1,   128,    90,   231,
     320,   230,   323,   230,   323,   230,   320,   232,   301,   231,
     305,   232,     6,    -1,    -1,   128,    84,   231,   320,   230,
     323,   230,   323,   230,   323,   230,   320,   232,   302,   231,
     305,   232,     6,    -1,    -1,   128,    87,   231,   320,   230,
     323,   230,   323,   230,   323,   230,   320,   232,   303,   231,
     305,   232,     6,    -1,    -1,   128,    90,   231,   320,   230,
     323,   230,   323,   230,   323,   230,   320,   232,   304,   231,
     305,   232,     6,    -1,   306,    -1,   305,   306,    -1,   144,
     231,   320,   232,     6,    -1,   144,   231,   326,   230,   326,
     232,     6,    -1,   144,   231,   326,   230,   326,   230,   326,
     232,     6,    -1,   145,     6,    -1,   136,     6,    -1,   136,
     320,     6,    -1,   152,     6,    -1,   152,   154,     6,    -1,
     153,     6,    -1,   153,   154,     6,    -1,   150,     6,    -1,
     150,   154,     6,    -1,   151,     6,    -1,   151,   154,     6,
      -1,   146,   224,   320,   225,     7,   326,   119,   320,     6,
      -1,   119,     4,   226,   320,   227,     6,    -1,   131,    -1,
     132,    -1,   133,    -1,   134,    -1,   135,    -1,    -1,   139,
       6,    -1,   139,   320,     6,    -1,   307,   231,   282,   308,
     232,   231,   282,   308,   232,    -1,    99,   224,   333,   225,
      -1,   307,   224,   320,   225,     7,   231,   282,   308,   232,
     231,   282,   308,   232,     6,    -1,    -1,   119,     4,   320,
      -1,    -1,     4,    -1,    -1,     7,   326,    -1,    -1,     7,
     320,    -1,    -1,   130,   326,    -1,   114,    87,   327,     7,
     320,   311,     6,    -1,   114,    90,   327,   313,   312,     6,
      -1,   105,    90,   231,   320,   232,     7,   326,     6,    -1,
     114,    92,   327,   313,     6,    -1,   155,   327,     6,    -1,
     142,    90,   231,   329,   232,     7,   320,     6,    -1,   136,
      90,   327,   314,     6,    -1,   136,    92,   327,     6,    -1,
     137,    90,   326,     7,   320,     6,    -1,   118,    87,   231,
     329,   232,     7,   231,   329,   232,   315,     6,    -1,   118,
      90,   231,   329,   232,     7,   231,   329,   232,   315,     6,
      -1,   118,    87,   231,   329,   232,     7,   231,   329,   232,
     124,   231,   323,   230,   323,   230,   320,   232,     6,    -1,
     118,    90,   231,   329,   232,     7,   231,   329,   232,   124,
     231,   323,   230,   323,   230,   320,   232,     6,    -1,   118,
      87,   231,   329,   232,     7,   231,   329,   232,   125,   323,
       6,    -1,   118,    90,   231,   329,   232,     7,   231,   329,
     232,   125,   323,     6,    -1,   118,    90,   320,   231,   329,
     232,     7,   320,   231,   329,   232,     6,    -1,    84,   231,
     329,   232,   169,    90,   231,   320,   232,     6,    -1,    87,
     231,   329,   232,   169,    90,   231,   320,   232,     6,    -1,
      84,   231,   329,   232,   169,    92,   231,   320,   232,     6,
      -1,    87,   231,   329,   232,   169,    92,   231,   320,   232,
       6,    -1,    90,   231,   329,   232,   169,    92,   231,   320,
     232,     6,    -1,   143,    90,   327,     6,    -1,   143,    87,
     327,     6,    -1,   108,    84,   327,     6,    -1,   108,    87,
     327,     6,    -1,   108,    90,   327,     6,    -1,   140,     6,
      -1,   140,     4,     6,    -1,   140,    84,   231,   329,   232,
       6,    -1,   189,    -1,   190,    -1,   191,    -1,   318,     6,
      -1,   318,   231,   326,   232,     6,    -1,   318,   231,   326,
     230,   326,   232,     6,    -1,   318,   224,   326,   225,   231,
     326,   230,   326,   232,     6,    -1,   321,    -1,   224,   320,
     225,    -1,   215,   320,    -1,   214,   320,    -1,   219,   320,
      -1,   320,   215,   320,    -1,   320,   214,   320,    -1,   320,
     216,   320,    -1,   320,   217,   320,    -1,   320,   218,   320,
      -1,   320,   223,   320,    -1,   320,   210,   320,    -1,   320,
     211,   320,    -1,   320,   213,   320,    -1,   320,   212,   320,
      -1,   320,   209,   320,    -1,   320,   208,   320,    -1,   320,
     207,   320,    -1,   320,   206,   320,    -1,   320,   205,   320,
       8,   320,    -1,    15,   258,   320,   259,    -1,    16,   258,
     320,   259,    -1,    17,   258,   320,   259,    -1,    18,   258,
     320,   259,    -1,    19,   258,   320,   259,    -1,    20,   258,
     320,   259,    -1,    21,   258,   320,   259,    -1,    22,   258,
     320,   259,    -1,    23,   258,   320,   259,    -1,    25,   258,
     320,   259,    -1,    26,   258,   320,   230,   320,   259,    -1,
      27,   258,   320,   259,    -1,    28,   258,   320,   259,    -1,
      29,   258,   320,   259,    -1,    30,   258,   320,   259,    -1,
      31,   258,   320,   259,    -1,    32,   258,   320,   259,    -1,
      33,   258,   320,   259,    -1,    34,   258,   320,   230,   320,
     259,    -1,    35,   258,   320,   230,   320,   259,    -1,    36,
     258,   320,   230,   320,   259,    -1,    24,   258,   320,   259,
      -1,     3,    -1,     9,    -1,    14,    -1,    10,    -1,    11,
      -1,   194,    -1,   195,    -1,   196,    -1,    72,    -1,    73,
      -1,    74,    -1,    -1,    80,   258,   320,   322,   269,   259,
      -1,   188,   258,   333,   259,    -1,   188,   258,   333,   230,
     320,   259,    -1,   338,    -1,     4,   226,   320,   227,    -1,
       4,   224,   320,   225,    -1,   337,   226,   320,   227,    -1,
     337,   224,   320,   225,    -1,   192,   224,   338,   225,    -1,
     193,   224,   334,   225,    -1,   229,   338,   258,   259,    -1,
     338,   257,    -1,     4,   226,   320,   227,   257,    -1,     4,
     224,   320,   225,   257,    -1,   337,   226,   320,   227,   257,
      -1,   337,   224,   320,   225,   257,    -1,     4,   228,     4,
      -1,     4,   226,   320,   227,   228,     4,    -1,     4,   228,
       4,   257,    -1,     4,   226,   320,   227,   228,     4,   257,
      -1,   184,   224,   333,   230,   320,   225,    -1,    54,   224,
     326,   230,   326,   225,    -1,    55,   258,   333,   230,   333,
     259,    -1,    53,   258,   333,   259,    -1,    56,   258,   333,
     230,   333,   259,    -1,    61,   224,   336,   225,    -1,   324,
      -1,   215,   323,    -1,   214,   323,    -1,   323,   215,   323,
      -1,   323,   214,   323,    -1,   231,   320,   230,   320,   230,
     320,   230,   320,   230,   320,   232,    -1,   231,   320,   230,
     320,   230,   320,   230,   320,   232,    -1,   231,   320,   230,
     320,   230,   320,   232,    -1,   224,   320,   230,   320,   230,
     320,   225,    -1,   326,    -1,   325,   230,   326,    -1,   320,
      -1,   328,    -1,   231,   232,    -1,   231,   329,   232,    -1,
     215,   231,   329,   232,    -1,   320,   216,   231,   329,   232,
      -1,   326,    -1,     5,    -1,   215,   328,    -1,   320,   216,
     328,    -1,   320,     8,   320,    -1,   320,     8,   320,     8,
     320,    -1,    84,   231,   320,   232,    -1,    84,     5,    -1,
      87,     5,    -1,    90,     5,    -1,    92,     5,    -1,   116,
      84,     5,    -1,   116,    87,     5,    -1,   116,    90,     5,
      -1,   116,    92,     5,    -1,   116,    84,   231,   329,   232,
      -1,   116,    87,   231,   329,   232,    -1,   116,    90,   231,
     329,   232,    -1,   116,    92,   231,   329,   232,    -1,    84,
     169,    62,   231,   320,   230,   320,   230,   320,   230,   320,
     230,   320,   230,   320,   232,    -1,    87,   169,    62,   231,
     320,   230,   320,   230,   320,   230,   320,   230,   320,   230,
     320,   232,    -1,    90,   169,    62,   231,   320,   230,   320,
     230,   320,   230,   320,   230,   320,   230,   320,   232,    -1,
      92,   169,    62,   231,   320,   230,   320,   230,   320,   230,
     320,   230,   320,   230,   320,   232,    -1,   280,    -1,   291,
      -1,   309,    -1,     4,   258,   259,    -1,   337,   258,   259,
      -1,    37,   226,   338,   227,    -1,    37,   226,   328,   227,
      -1,    37,   224,   328,   225,    -1,    37,   226,   231,   329,
     232,   227,    -1,    37,   224,   231,   329,   232,   225,    -1,
       4,   258,   231,   329,   232,   259,    -1,   337,   258,   231,
     329,   232,   259,    -1,    38,   258,   320,   230,   320,   230,
     320,   259,    -1,    39,   258,   320,   230,   320,   230,   320,
     259,    -1,    40,   258,   333,   259,    -1,    41,   258,   320,
     230,   320,   230,   320,   230,   320,   230,   320,   230,   320,
     259,    -1,   320,    -1,   328,    -1,   329,   230,   320,    -1,
     329,   230,   328,    -1,   231,   320,   230,   320,   230,   320,
     230,   320,   232,    -1,   231,   320,   230,   320,   230,   320,
     232,    -1,   338,    -1,     4,   228,   166,   228,     4,    -1,
     231,   332,   232,    -1,     4,   226,   320,   227,   228,   167,
      -1,   330,    -1,   332,   230,   330,    -1,   334,    -1,   338,
      -1,     4,   226,   320,   227,    -1,   337,   226,   320,   227,
      -1,     4,   224,   320,   225,    -1,   337,   224,   320,   225,
      -1,     4,   228,     4,    -1,     4,   226,   320,   227,   228,
       4,    -1,     5,    -1,   199,   226,   338,   227,    -1,    65,
      -1,   197,    -1,    70,    -1,   186,   224,   333,   225,    -1,
     185,   224,   333,   230,   333,   225,    -1,   187,   258,   333,
     259,    -1,   187,   258,   333,   230,   333,   259,    -1,    46,
     258,   336,   259,    -1,    47,   224,   333,   225,    -1,    48,
     224,   333,   225,    -1,    49,   224,   333,   230,   333,   230,
     333,   225,    -1,    44,   258,   336,   259,    -1,    58,   258,
     333,   259,    -1,    59,   258,   333,   259,    -1,    60,   258,
     333,   259,    -1,    57,   258,   320,   230,   333,   230,   333,
     259,    -1,    52,   258,   333,   230,   320,   230,   320,   259,
      -1,    52,   258,   333,   230,   320,   259,    -1,    45,   258,
     333,   259,    -1,    45,   258,   333,   230,   329,   259,    -1,
      66,   258,   333,   259,    -1,    67,    -1,    51,   258,   333,
     259,    -1,    50,   258,   333,   259,    -1,    -1,    81,   258,
     334,   335,   271,   259,    -1,   333,    -1,   336,   230,   333,
      -1,     4,   233,   231,   320,   232,    -1,   337,   233,   231,
     320,   232,    -1,     4,    -1,   337,    -1,   200,   226,   333,
     227,    -1
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
    1718,  1728,  1756,  1799,  1822,  1851,  1872,  1890,  1930,  1960,
    1987,  2014,  2041,  2070,  2075,  2093,  2139,  2167,  2217,  2223,
    2229,  2236,  2278,  2304,  2328,  2352,  2377,  2400,  2427,  2455,
    2480,  2507,  2511,  2530,  2564,  2611,  2629,  2656,  2675,  2694,
    2698,  2714,  2762,  2779,  2797,  2807,  2817,  2827,  2890,  2901,
    2917,  2918,  2923,  2926,  2930,  2959,  2988,  3017,  3051,  3073,
    3099,  3121,  3144,  3165,  3221,  3245,  3270,  3296,  3409,  3428,
    3471,  3492,  3498,  3513,  3541,  3558,  3567,  3581,  3595,  3601,
    3607,  3616,  3625,  3634,  3648,  3710,  3728,  3745,  3760,  3789,
    3801,  3825,  3829,  3834,  3842,  3847,  3853,  3858,  3864,  3872,
    3876,  3880,  3885,  3945,  3961,  3978,  3995,  4017,  4039,  4074,
    4082,  4090,  4096,  4103,  4110,  4130,  4156,  4168,  4180,  4210,
    4241,  4250,  4249,  4264,  4263,  4278,  4277,  4292,  4291,  4304,
    4337,  4342,  4348,  4371,  4395,  4402,  4409,  4416,  4423,  4430,
    4437,  4444,  4451,  4459,  4458,  4472,  4471,  4485,  4484,  4498,
    4497,  4511,  4510,  4524,  4523,  4537,  4536,  4550,  4549,  4563,
    4562,  4579,  4582,  4588,  4600,  4620,  4644,  4648,  4652,  4656,
    4660,  4664,  4670,  4676,  4680,  4684,  4688,  4692,  4711,  4724,
    4725,  4726,  4727,  4728,  4732,  4733,  4734,  4737,  4771,  4797,
    4821,  4824,  4840,  4843,  4860,  4863,  4869,  4872,  4879,  4882,
    4889,  4945,  5015,  5020,  5087,  5123,  5131,  5174,  5213,  5233,
    5265,  5292,  5318,  5344,  5370,  5396,  5418,  5446,  5474,  5502,
    5530,  5558,  5597,  5636,  5657,  5678,  5705,  5709,  5719,  5754,
    5755,  5756,  5760,  5766,  5778,  5796,  5824,  5825,  5826,  5827,
    5828,  5829,  5830,  5831,  5832,  5839,  5840,  5841,  5842,  5843,
    5844,  5845,  5846,  5847,  5848,  5849,  5850,  5851,  5852,  5853,
    5854,  5855,  5856,  5857,  5858,  5859,  5860,  5861,  5862,  5863,
    5864,  5865,  5866,  5867,  5868,  5869,  5870,  5871,  5880,  5881,
    5882,  5883,  5884,  5885,  5886,  5887,  5888,  5889,  5890,  5895,
    5894,  5902,  5907,  5912,  5929,  5947,  5965,  5983,  6001,  6006,
    6012,  6027,  6046,  6066,  6086,  6106,  6129,  6134,  6139,  6149,
    6159,  6164,  6175,  6184,  6189,  6194,  6221,  6225,  6229,  6233,
    6237,  6244,  6248,  6252,  6256,  6263,  6268,  6275,  6280,  6284,
    6289,  6293,  6301,  6312,  6316,  6328,  6336,  6344,  6351,  6361,
    6390,  6394,  6398,  6402,  6406,  6410,  6414,  6418,  6422,  6451,
    6480,  6509,  6538,  6551,  6564,  6577,  6590,  6600,  6610,  6620,
    6632,  6645,  6657,  6661,  6665,  6669,  6673,  6691,  6709,  6717,
    6725,  6754,  6767,  6772,  6776,  6780,  6792,  6796,  6808,  6825,
    6835,  6839,  6854,  6859,  6866,  6870,  6883,  6897,  6911,  6925,
    6939,  6947,  6958,  6962,  6966,  6974,  6980,  6986,  6994,  7002,
    7009,  7017,  7032,  7046,  7060,  7072,  7088,  7097,  7106,  7116,
    7127,  7135,  7143,  7147,  7166,  7173,  7179,  7186,  7194,  7193,
    7206,  7211,  7217,  7226,  7239,  7242,  7246
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
  "tBooleanSection", "tBooleanFragments", "tRecombine", "tSmoother",
  "tSplit", "tDelete", "tCoherence", "tIntersect", "tMeshAlgorithm",
  "tReverse", "tLayers", "tScaleLast", "tHole", "tAlias",
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
     455,   456,   457,   458,   459,    63,   460,   461,   462,   463,
      60,    62,   464,   465,    43,    45,    42,    47,    37,    33,
     466,   467,   468,    94,    40,    41,    91,    93,    46,    35,
      44,   123,   125,   126
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   234,   235,   235,   236,   236,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   238,   238,   239,   239,   239,
     239,   239,   239,   240,   240,   240,   240,   241,   241,   241,
     241,   241,   241,   242,   242,   243,   243,   245,   246,   244,
     247,   247,   249,   248,   250,   250,   252,   251,   253,   253,
     255,   254,   256,   256,   256,   256,   256,   257,   257,   258,
     258,   259,   259,   260,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   260,   261,   261,   262,   262,   262,   263,
     262,   264,   262,   265,   262,   262,   266,   262,   267,   267,
     268,   268,   268,   269,   269,   270,   270,   270,   271,   271,
     272,   272,   272,   272,   273,   273,   273,   274,   274,   274,
     275,   275,   275,   276,   276,   276,   277,   277,   278,   278,
     279,   279,   279,   279,   279,   279,   279,   279,   279,   279,
     279,   279,   279,   279,   279,   279,   279,   279,   279,   279,
     279,   279,   279,   279,   279,   279,   279,   279,   279,   279,
     279,   279,   279,   279,   279,   279,   279,   279,   279,   279,
     279,   279,   280,   280,   280,   280,   280,   280,   280,   280,
     281,   281,   282,   282,   282,   282,   282,   282,   283,   283,
     283,   283,   283,   283,   283,   283,   283,   283,   283,   283,
     284,   284,   284,   284,   284,   285,   285,   286,   287,   287,
     287,   287,   287,   287,   288,   288,   288,   288,   288,   288,
     288,   288,   288,   288,   288,   288,   288,   288,   288,   288,
     288,   288,   288,   289,   290,   290,   290,   290,   290,   290,
     290,   290,   290,   290,   290,   290,   290,   290,   291,   291,
     291,   292,   291,   293,   291,   294,   291,   295,   291,   291,
     291,   291,   291,   291,   291,   291,   291,   291,   291,   291,
     291,   291,   291,   296,   291,   297,   291,   298,   291,   299,
     291,   300,   291,   301,   291,   302,   291,   303,   291,   304,
     291,   305,   305,   306,   306,   306,   306,   306,   306,   306,
     306,   306,   306,   306,   306,   306,   306,   306,   306,   307,
     307,   307,   307,   307,   308,   308,   308,   309,   309,   310,
     311,   311,   312,   312,   313,   313,   314,   314,   315,   315,
     316,   316,   316,   316,   316,   316,   316,   316,   316,   316,
     316,   316,   316,   316,   316,   316,   316,   316,   316,   316,
     316,   316,   316,   316,   316,   316,   317,   317,   317,   318,
     318,   318,   319,   319,   319,   319,   320,   320,   320,   320,
     320,   320,   320,   320,   320,   320,   320,   320,   320,   320,
     320,   320,   320,   320,   320,   320,   320,   320,   320,   320,
     320,   320,   320,   320,   320,   320,   320,   320,   320,   320,
     320,   320,   320,   320,   320,   320,   320,   320,   321,   321,
     321,   321,   321,   321,   321,   321,   321,   321,   321,   322,
     321,   321,   321,   321,   321,   321,   321,   321,   321,   321,
     321,   321,   321,   321,   321,   321,   321,   321,   321,   321,
     321,   321,   321,   321,   321,   321,   323,   323,   323,   323,
     323,   324,   324,   324,   324,   325,   325,   326,   326,   326,
     326,   326,   326,   327,   327,   328,   328,   328,   328,   328,
     328,   328,   328,   328,   328,   328,   328,   328,   328,   328,
     328,   328,   328,   328,   328,   328,   328,   328,   328,   328,
     328,   328,   328,   328,   328,   328,   328,   328,   328,   328,
     328,   328,   329,   329,   329,   329,   330,   330,   330,   330,
     331,   331,   332,   332,   333,   333,   333,   333,   333,   333,
     333,   333,   334,   334,   334,   334,   334,   334,   334,   334,
     334,   334,   334,   334,   334,   334,   334,   334,   334,   334,
     334,   334,   334,   334,   334,   334,   334,   334,   335,   334,
     336,   336,   337,   337,   338,   338,   338
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
       8,     4,     8,    12,     8,     8,     7,     7,     8,     4,
       8,     8,     5,    11,     5,     9,     9,     4,     9,     9,
       1,     1,     0,     2,     6,     6,     6,     6,     8,    10,
      14,    16,    12,    14,    14,    14,    14,     8,     8,     6,
       4,     6,     6,     3,     4,     5,     6,     5,     3,     3,
       4,     5,     4,     5,     3,     5,     7,     7,     3,     7,
       3,     2,     2,     2,     2,     2,    15,     2,     2,     2,
       2,     2,    16,    11,     6,     8,     8,    10,     1,     2,
       2,     1,     3,     3,     4,     4,     1,     1,     5,    11,
      13,     0,     7,     0,    13,     0,    15,     0,     6,     9,
       7,    12,     2,     3,     8,     8,     8,    12,    12,    12,
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
       0,     0,     0,     0,     0,     0,     0,   278,     0,     0,
     286,   287,     0,     0,     0,   281,     0,     0,     0,     0,
       0,   399,   400,   401,     0,     0,     5,     7,     6,     8,
       9,    10,    23,    11,    12,    13,    14,    22,    21,    20,
      15,     0,    16,    17,    18,    19,     0,    24,   595,     0,
     448,   594,   562,   449,   451,   452,   450,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   564,     0,   585,
     566,   456,   457,   458,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   453,   454,   455,   565,     0,     0,
       0,     0,    69,    70,     0,     0,   222,     0,     0,     0,
     406,     0,   554,   595,   463,     0,     0,     0,     0,   265,
       0,   267,   268,   263,   264,     0,   269,   270,   126,   138,
      69,    70,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   271,     0,     0,
       0,     0,     0,   594,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   526,
     527,     0,   528,   497,   302,   498,   595,   463,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   486,     0,     0,     0,
       0,     0,   222,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   594,     0,   222,   595,
       0,     0,   396,     0,     0,     0,     0,     0,     0,     0,
       0,   504,     0,   503,     0,     0,     0,     0,     0,   594,
       0,     0,   548,     0,     0,     0,     0,   261,   262,     0,
     594,     0,     0,     0,   279,   280,     0,   222,     0,   222,
     594,     0,   595,     0,     0,   222,   402,     0,     0,    69,
      70,     0,     0,    62,    66,    65,    64,    63,    68,    67,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   409,   408,
     410,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     221,     0,   220,     0,     0,   258,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    37,   254,     0,     0,   471,   188,     0,   594,     0,
     554,   595,   555,     0,     0,   590,     0,   124,   124,     0,
       0,     0,     0,   542,   543,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    69,    70,     0,     0,     0,     0,     0,     0,
       0,     0,   510,     0,     0,   511,     0,   512,     0,   513,
       0,     0,     0,     0,     0,     0,     0,   408,   505,     0,
     499,     0,     0,     0,    69,    70,     0,     0,     0,     0,
       0,   303,     0,   364,   364,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   222,   222,     0,   488,   487,     0,     0,     0,
       0,   222,   222,     0,     0,     0,     0,     0,     0,     0,
     297,     0,     0,   222,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   366,     0,     0,     0,     0,     0,     0,
       0,   243,   397,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   374,   260,     0,     0,     0,     0,     0,   222,
       0,     0,     0,     0,     0,   283,   282,     0,   248,     0,
     249,     0,     0,     0,   222,     0,     0,     0,     0,   354,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      78,     0,     0,     0,   476,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   459,   588,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    62,    63,     0,
     407,    62,    63,     0,     0,    62,     0,     0,     0,     0,
       0,   217,     0,     0,     0,     0,     0,     0,   223,     0,
       0,     0,   424,   423,   422,   421,   417,   418,   420,   419,
     412,   411,   413,   414,   415,   416,     0,     0,     0,   189,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   125,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   358,     0,
       0,     0,     0,     0,     0,   393,   394,   395,     0,     0,
       0,   476,    71,    72,     0,   529,     0,     0,     0,     0,
       0,   463,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   514,     0,   515,     0,   516,     0,   517,     0,     0,
     407,   500,   507,     0,   413,   506,     0,     0,     0,   530,
       0,     0,     0,     0,     0,     0,   362,     0,     0,     0,
     154,   155,     0,   157,   158,     0,   160,   161,     0,   163,
     164,     0,   183,     0,   201,     0,   209,     0,     0,     0,
       0,   175,   222,     0,     0,     0,     0,     0,   490,   489,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   291,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   377,     0,     0,   244,     0,     0,   240,
       0,     0,     0,   392,   391,     0,     0,     0,   407,     0,
       0,     0,     0,     0,     0,     0,     0,   284,   285,     0,
       0,   250,   252,     0,   596,     0,     0,     0,     0,     0,
       0,    62,    63,     0,     0,    62,    63,     0,     0,     0,
       0,    93,    77,     0,   465,   464,   478,   426,   427,   428,
     429,   430,   431,   432,   433,   434,   447,   435,     0,   437,
     438,   439,   440,   441,   442,   443,     0,     0,     0,   575,
       0,   582,   571,   572,   573,     0,   587,   586,     0,   483,
       0,     0,     0,     0,   576,   577,   578,   485,   584,   143,
     148,   116,     0,     0,   567,     0,   569,     0,   461,   468,
     469,   563,     0,     0,     0,    62,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   110,     0,     0,     0,
       0,   470,     0,     0,     0,     0,     0,     0,   592,     0,
       0,    47,     0,     0,     0,    60,     0,    38,    39,    40,
      41,    42,   467,   466,     0,     0,   560,    27,    25,     0,
       0,     0,     0,    28,     0,     0,   255,   591,    73,   127,
      74,   139,     0,     0,     0,   544,   545,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   170,
     465,   464,     0,     0,   533,     0,   532,   531,     0,     0,
     540,     0,     0,   509,     0,     0,     0,     0,     0,     0,
       0,   501,     0,     0,     0,   467,   466,     0,     0,     0,
       0,   407,   360,   365,   363,     0,   373,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   407,   407,   407,     0,
       0,     0,     0,     0,   251,   253,     0,     0,     0,   212,
     214,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   331,   222,     0,
     288,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   367,   376,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   245,     0,
       0,     0,     0,     0,   247,     0,   355,     0,     0,     0,
       0,   403,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   593,     0,     0,   473,     0,   472,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    87,     0,
      91,     0,     0,    79,     0,     0,     0,     0,    83,   106,
     108,     0,     0,   552,     0,   114,     0,     0,     0,     0,
       0,     0,     0,   425,     0,     0,     0,     0,     0,    33,
     475,   474,   558,   556,    26,     0,     0,   559,   557,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   168,
     168,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   173,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   518,   519,   520,   521,     0,   508,   502,     0,
       0,     0,     0,     0,     0,     0,   371,     0,     0,   156,
       0,   159,     0,   162,     0,   165,     0,     0,     0,     0,
       0,     0,     0,   246,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   337,     0,     0,   336,     0,   343,
       0,   345,     0,   339,     0,   341,     0,   298,   332,     0,
       0,     0,     0,   239,     0,     0,     0,     0,     0,     0,
       0,   378,     0,   242,   241,   398,     0,     0,    34,    35,
       0,     0,     0,     0,   549,     0,     0,     0,   274,     0,
       0,     0,   222,   356,   222,     0,     0,     0,     0,    88,
       0,    92,     0,     0,    80,     0,    84,     0,   257,   477,
     256,   436,   444,   445,   446,   583,     0,     0,   581,   481,
     482,   484,     0,     0,   460,   144,     0,   589,   149,   480,
     568,   570,   462,     0,     0,     0,    89,     0,     0,     0,
      62,     0,     0,     0,     0,    81,     0,     0,     0,   550,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   495,     0,     0,    29,    30,     0,    31,     0,     0,
     128,   135,     0,     0,    75,    76,   171,     0,     0,     0,
       0,     0,     0,   174,     0,     0,   191,   192,     0,     0,
     176,   206,   193,   197,   198,   194,   195,   196,     0,     0,
       0,   477,   536,   535,   534,     0,     0,     0,     0,     0,
       0,     0,   207,   537,   199,     0,   166,     0,     0,   370,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   259,     0,     0,     0,     0,   222,   222,     0,   313,
       0,   315,     0,   317,     0,     0,   338,   497,     0,     0,
     344,   346,   340,   342,   300,     0,     0,   292,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   179,   180,     0,     0,     0,     0,   117,   121,
       0,     0,   354,   354,     0,   404,     0,     0,     0,    90,
       0,     0,     0,    82,     0,   479,     0,     0,     0,     0,
       0,     0,   100,     0,     0,    94,     0,     0,     0,     0,
     111,     0,     0,   112,     0,   553,   224,   225,   226,   227,
       0,     0,     0,    43,     0,     0,     0,     0,     0,    45,
     561,     0,     0,   129,   136,     0,     0,     0,     0,   169,
     177,   178,   182,     0,     0,   200,     0,     0,   372,     0,
       0,     0,     0,     0,     0,     0,     0,   186,     0,     0,
     208,   361,   205,   172,   185,   204,   211,   184,     0,   202,
     210,     0,     0,     0,     0,     0,     0,   494,     0,   493,
       0,     0,     0,   304,     0,     0,   305,     0,     0,   306,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   238,
     237,     0,     0,     0,     0,     0,     0,     0,     0,   228,
       0,     0,   375,    36,     0,     0,   547,     0,   276,   275,
       0,     0,     0,     0,     0,     0,     0,   101,     0,     0,
      95,     0,     0,     0,   574,   580,   579,     0,   145,   147,
       0,   150,   151,   152,   102,   104,    96,    98,   107,   109,
       0,   115,     0,    85,    48,     0,     0,     0,   496,     0,
       0,     0,    32,     0,   143,   148,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   538,   539,     0,     0,     0,
       0,     0,     0,   187,     0,   368,   368,     0,   122,   123,
     222,     0,   215,   216,     0,     0,     0,     0,     0,     0,
     299,     0,   333,     0,     0,     0,   222,     0,     0,     0,
       0,     0,     0,     0,     0,   219,   218,     0,     0,     0,
       0,   118,   119,     0,     0,   357,     0,   103,   105,    97,
      99,    86,     0,   542,   543,     0,     0,   551,     0,    44,
       0,     0,     0,    46,    61,     0,     0,     0,   133,   131,
     386,   388,   387,   389,   390,   190,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   492,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   348,     0,     0,     0,     0,   293,
       0,   229,     0,     0,     0,     0,     0,     0,     0,   546,
     277,     0,     0,   222,   405,     0,   146,     0,     0,   153,
     113,     0,     0,     0,     0,     0,   130,   137,   143,   143,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     369,   379,     0,     0,   380,     0,   213,     0,   319,     0,
       0,   321,     0,     0,   323,     0,     0,     0,   334,     0,
       0,   289,     0,   222,     0,     0,     0,     0,     0,     0,
     181,   120,   273,   354,     0,   140,     0,     0,    52,     0,
      58,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   167,   203,     0,   383,     0,   384,   385,   491,   307,
       0,     0,   314,   308,     0,     0,   316,   309,     0,     0,
     318,     0,     0,   301,     0,   295,   232,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   134,   132,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   325,     0,   327,     0,   329,   335,   347,   294,
     290,     0,     0,     0,     0,     0,     0,     0,     0,   141,
     142,    49,     0,    56,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   310,     0,     0,   311,     0,
       0,   312,     0,     0,   233,   234,   235,   236,     0,   230,
     359,     0,    50,     0,     0,   266,     0,   541,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     296,     0,     0,     0,     0,     0,   272,     0,     0,     0,
       0,     0,     0,   320,     0,   322,     0,   324,     0,   231,
      51,    53,     0,    54,     0,   522,   523,   524,   525,     0,
       0,     0,     0,     0,     0,     0,    59,   381,   382,   326,
     328,   330,    55,    57
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,   106,  1099,   107,   108,   786,  1702,  1708,
    1087,  1324,  1918,  2161,  1088,  2097,  2202,  1089,  2163,  1090,
    1091,  1328,   400,   495,   208,   845,   109,   804,   507,  1844,
    1999,  1998,  1845,   508,  1912,  1290,  1505,  1291,  1508,   889,
     892,   895,   898,  1739,  1560,   768,   279,   471,   472,   112,
     113,   114,   115,   116,   117,   118,   119,   280,  1221,  2032,
    2121,   928,  1764,  1767,  1770,  2070,  2074,  2078,  2146,  2149,
    2152,  1216,  1217,   281,   977,   282,   123,  1395,  1175,   886,
     942,  1947,   124,   125,   126,   127,   283,   210,  1039,   606,
     316,  1540,   353,   354,   285,   571,   361,  1070,  1314,   505,
     500,  1040,   506,   382,   287
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1790
static const yytype_int16 yypact[] =
{
   11264,    38,    67, 11416, -1790, -1790,  4449,    58,   -42,  -141,
    -133,    43,   100,   130,   223,   244,    63,   290,   367,    56,
     153,  -129,  -129,  -128,   176,   188,    22,   199,   214,    29,
     229,   268,   300,   312,   315,   354,   429,   458,   467,   413,
     548,   614,   710,   488,   309,   502,  6371,   513,   659,   -53,
     134,   694,    99,   215,   414,   566,   719,  -107,   598,  -115,
    -115,   638,   299,   454, -1790, -1790, -1790, -1790, -1790,   246,
     726,   748,     0,    50,   790,   795,   415,   885,   900,   904,
    5925,   911,   656,   688,   692,    18,    16, -1790,   696,   712,
   -1790, -1790,   938,   942,   736, -1790,  3959,   728,  5803,    33,
      35, -1790, -1790, -1790, 10607,   747, -1790, -1790, -1790, -1790,
   -1790, -1790, -1790, -1790, -1790, -1790, -1790, -1790, -1790, -1790,
   -1790,   -49, -1790, -1790, -1790, -1790,    45, -1790,  -139,   166,
   -1790,    19, -1790, -1790, -1790, -1790, -1790,  -129,  -129,  -129,
    -129,  -129,  -129,  -129,  -129,  -129,  -129,  -129,  -129,  -129,
    -129,  -129,  -129,  -129,  -129,  -129,  -129,  -129,  -129,  -129,
    -129,  -129,   750,   754,   763,  -129,  -129,  -129,  -129,   766,
    -129,  -129,  -129,  -129,  -129,  -129,   784, -1790,  -129, -1790,
   -1790, -1790, -1790, -1790,  -129,  -129,  1008,   822,   833,   834,
    -129,  -129,   853,   890, -1790, -1790, -1790, -1790,   771, 10607,
   10607, 10607,  9750,  9967,    21,    20,   394,   836,   837,  1072,
   -1790,   849,  1056,   512,   -60,  1113, 10607,  4143,  4143, -1790,
   10607, -1790, -1790, -1790, -1790,  4143, -1790, -1790, -1790, -1790,
   -1790, -1790,  6026,    20, 10607,  9460, 10607, 10607,   898, 10607,
    9460, 10607, 10607,   899,  9460, 10607, 10607, 10607, 10607, 10607,
   10607,  4143, 10607, 10607,  6594,   909,   901, -1790,  9460,  5925,
    5925,  5925,  4143,   640,   360,  -129,  -129,  -129,  -129,    34,
      11,    27,    48,  6594,  1029,   375,  6817, 10607,  5249, -1790,
   -1790,   937, -1790,  1220, -1790, -1790,   559,   106, 10607,   950,
     962,  7040,  5925,  5925,  5925,   976,   992,   999,  1005,  1006,
    7263,  7486,  7709,  1000,  3519,  1228,  6594,    18,  1003,  1012,
    -115,  -115,  -115, 10607, 10607,   -90, -1790,   -36,  -115,  1013,
    1017,  1018,  9343,   125,   -34,  1015,  1026,  1031,  1033,  1034,
    1035,  1036,  5925,  5925,  6594,  1037,     9,  1027, -1790,  1032,
    1261,  1266, -1790,  1043,  1044,  1045,  5925,  5925,  1065,  1070,
    1071, -1790, 10607, -1790,  1294,  1296, 10607, 10607, 10607,   126,
   10607,  1073, -1790,  1137, 10607, 10607, 10607, -1790, -1790, 10607,
    1074,  1306,  1307,  1083, -1790, -1790,  1309, -1790,  1310, -1790,
     284,  4771,   600,  4143, 10607, -1790, -1790,  6594,  6594, 10034,
   10251,  1089,  1094,  6026, -1790, -1790, -1790, -1790, -1790, -1790,
    6594,  1316,  1100, 10607, 10607,  1323, 10607, 10607, 10607, 10607,
   10607, 10607, 10607, 10607, 10607, 10607, 10607, 10607, 10607, 10607,
   10607, 10607, 10607, 10607, 10607, 10607, 10607, 10607,  4143,  4143,
    4143,  4143,  4143,  4143,  4143,  4143,  4143,  4143,  6594,  4143,
    4143, 10607,  4143,  4143,  4143,  4143,  4143, 10607,  6026, 10607,
    4143,  4143,  4143,  4143,  4143,    20,  6026,    20,  1105,  1105,
    1105,   121, 13028,   174,  1904,   200,  1102,  1342,  -129,  1121,
   -1790,  1123,  5313, 10607,  9460, -1790, 10607, 10607, 10607, 10607,
   10607, 10607, 10607, 10607, 10607, 10607, 10607, 10607, 10607, 10607,
   10607, -1790, -1790, 10607, 10607, -1790, -1790,  1128,   648,   325,
   -1790,   634, -1790,   332, 10374, -1790,   349,   304,   404,  1126,
    1130, 13049,  9460,  2145, -1790,   254, 13070, 13091, 10607, 13112,
     376, 13133, 13154, 10607,   391, 13175, 13196, 13217, 13238, 13259,
   13280,  1133, 13301, 13322,  1354, 10607, 10607,   448,  1356,  1357,
    1358,  1140, 10607, 10607,  1363,   596,  7932,  8155, 10607, 10607,
    4143, 10607, -1790,  1308, 10607, -1790,  1311, -1790,  1312, -1790,
    1313,  6594,    36,    37,    40,    41,  9460,  1105, -1790, 13343,
   -1790,   580, 10607,  8378, 10607, 10607,   672, 13364, 10607, 10607,
   10607, -1790,  1361,  1362,  1362, 10607,  9677,  9677,  9677,  9677,
   10607,  1365, 10607,  1366, 10607,  1370,  9460,  9460, 10085,  1153,
    1373,  1149, -1790, -1790,   -88, -1790, -1790, 10441, 10483,  -115,
    -115,   394,   394,   -83, 10607, 10607, 10607,  9343,  9343, 10607,
    2082,  2225,   119, -1790, 10607, 10607, 10607, 10607, 10607, 10607,
   10607, 10607, 10607,  1375,  1377,  1378, 10607,  1380, 10607, 10607,
    2669, -1790, -1790,  9460,  9460,  9460,  1381,  1385, 10607, 10607,
   10607, 13385, -1790, -1790, 13406, 13427, 13448,  1218, 10566, -1790,
    1161,  2740, 13469, 13490,  3481, -1790, -1790,  9460, -1790,  3057,
   -1790,  3258, 10607, 10607, -1790, 10607, 10607,  1166, 13511,  5053,
    1171,   658,   205, 13532,   212, 12683, 10607,  9460,  1394,  1403,
   -1790, 10607, 13553, 12706,   -37, 12660, 12660, 12660, 12660, 12660,
   12660, 12660, 12660, 12660, 12660, 12660, 10756, 12660, 12660, 12660,
   12660, 12660, 12660, 12660, 10968, 11106, 11412,   -58,   680,   -58,
    1185,  1186,  1187,   673,   673,  1188,   673,  1189,  1190,  1191,
   11438,   673,   673,   673,   389,   673, 14246, -1790,  1246,  1192,
    1194,  1215,   684,   720,  1216,  1217,  1219,  1400,  1401,  6594,
     272,  1404,  1406,  6594,   144,  6026, 10607,  1459,  1462,    31,
     673, -1790,    -8,    30,    32,   127,  1243,   -24, -1790,  4030,
     689,  2849,  2075,   639,   821,   821,   482,   482,   482,   482,
     201,   201,  1105,  1105,  1105,  1105,     7, 13574, 12729, -1790,
   10607, 10607,  1464,    23,  9460, 10607, 10607,  1465,  9460, 10607,
    1466,  4143,  1467, -1790,    20,  1470,  4143, 10607,  6026,  1463,
    9460,  9460,  1315,  1471,  1474, 13595,  1478,  1317,  1480,  1481,
   13616,  1320,  1484,  1485,  1488,  1489,  1490,  1491, -1790,  1507,
    1508, 10607, 13637,  4174,  1285, -1790, -1790, -1790,  1511, 13658,
   12752,   106, -1790, -1790,  9460, -1790,  9460,  2145,  1252,  9460,
    1292,   260, 11464, 11490,   673, 11516,  1289,  4211,  1290,  1291,
    1293, -1790,  9460, -1790,  9460, -1790,  9460, -1790,  9460,   707,
    1516, -1790,  3254,  9460,  1105, -1790, 13679, 12775,  9460, -1790,
    1519, 13700, 13721, 13742, 10607,  6594,  1523,  1522, 13763,  1305,
   14246,  1304,  1314, 14246,  1321,  1319, 14246,  1322,  1325, 14246,
    1324, 13784, -1790, 13805, -1790, 13826, -1790,   723,   737,  9460,
    1327, -1790, -1790,  4477, 10753,  -115, 10607, 10607, -1790, -1790,
    1303,  1328,  9343, 11542, 11568, 11594, 10276,  1417,     4,  1336,
    -115, 10796, 13847,  4395, 13868, 13889, 13910, 13931, 13952, 13973,
   13994, 10607,  1531, -1790, 10607, 14015, -1790, 12798, 12821, -1790,
     751,   756,   761, -1790, -1790, 12844, 12867, 11620, -1790,  1533,
    1538,  1540,  1331, 10607, 10838, 10607, 10607, -1790, -1790,    10,
     770, -1790, -1790, 10923, -1790,  1546, 10323,  1338,  1337,  6594,
    1532,  1498,  1527,  6594,   272,  1528,  1529,  6594,   272,  4509,
     773, -1790, -1790, 12890,   140,  1582, -1790, -1790, -1790, -1790,
   -1790, -1790, -1790, -1790, -1790, -1790, -1790, -1790, 10607, -1790,
   -1790, -1790, -1790, -1790, -1790, -1790, 10607, 10607, 10607, -1790,
    9460, -1790, -1790, -1790, -1790,  4143, -1790, -1790, 10607, -1790,
    6594,  4143,  4143,  4143, -1790, -1790, -1790, -1790, -1790, -1790,
   -1790, -1790, 10607,  4143, -1790,  4143, -1790, 10607, -1790, -1790,
   -1790, -1790,  -129,  -129,  1570, -1790, 10607,  1572,  -129,  -129,
    1575,    26, 10607,  1578,  1579,  1295, -1790,  1581,  1364,    18,
    1589, -1790,  9460,  9460,  9460,  9460, 10607,  1372, -1790,   673,
   10607, -1790,  1383,  1388,  1382, -1790,  1610, -1790, -1790, -1790,
   -1790, -1790,   160,   306, 14036, 12913, -1790, -1790,  1407,  4143,
     432, 14057, 12936, -1790,   509, 11646, -1790, -1790, -1790,    54,
   -1790, -1790, 12660,   673,  -115,  2145, -1790,   919,  6594,  6594,
    1612,  6594,   924,  6594,  6594,  1613,  1525,  6594,  6594,  6594,
    6594,  6594,  6594,  6594,  6594,  1535,  1615,  1616,  9460, -1790,
     106,   665,   788,   789, -1790,   793, -1790, -1790, 10607, 10607,
   -1790, 10607, 10607, -1790, 10607, 10607, 10607,   794,   811,   815,
     819, -1790,  6594, 10607,   823,   106,   106,   824,  6594,  1618,
    1628,  1629,  1740, -1790, -1790,  1632, -1790,  1638,   287, 10607,
     287, 10607,   287, 10607,   287, 10607,  1643,  1646,  1647,  1648,
    1649,   831,  1653, 10965, -1790, -1790,   231, 11672, 11698, -1790,
   -1790,  4617,  -125,  -115,  -115,  -115,  1571,  1655, 10540,  1434,
    1661,  1444,    44,    52,    57,    59,   -72, -1790, -1790,   242,
   -1790,     4,  1662,  1664,  1666,  1667,  1668,  1670,  1671,  1673,
    1674, 14246, -1790,  1640,  1451,  1688,  1691,  1692,  1609,  1695,
    1698,  1701, 10607,  6594,  6594,  6594,  1697, 11724, -1790,  3398,
     717,  1704,  1705,  1482, -1790,  1479, -1790,  1694,  1483,  6594,
    1486, -1790,  -129,  -129,  1709, 10607,  1711,  -129,  -129,  1713,
   10607,  1714, -1790,   673,  1718, -1790,  1707, -1790,  1719, 12660,
   12660, 12660, 12660,   724,  1501, 10199,  1509,   673,   673,  1502,
     741,   752, 14078,  1510,   673, 12660,  1132,  4143, -1790,  1766,
   -1790,  1132,  4143, -1790,   276,  1505,  1729,  1795, -1790, -1790,
   -1790,    18, 10607, -1790,   843, -1790,   844,   851,   855,   856,
   14099, 10607,   287, 14246,  1513, 10607, 10607,  6594,  1526, -1790,
   -1790, -1790, -1790,  1534, -1790,  1732,    25, -1790, -1790,  1748,
   10607,  4740,  1539,  1536,  1753,  1759,    13,  1542,  1544,  1654,
    1654,  6594,  1764,  1545,  1547,  1771,  1777,  6594,  1554,  1780,
    1781,  1782,  1783,  1784,  1785,  1786,  1787, -1790,  1789,  6594,
     859,  1791,   673,  1573,  1569, 11750, 11776, 11802, 11828, 11854,
   11880, 11906, -1790, -1790, -1790, -1790,  1793, 14246, -1790,   673,
    1794,  6594,  6594,  6594,  1798,  1799, -1790,  6594,  6594, 14246,
    6594, 14246,  6594, 14246,  6594, 14246,  6594,  6594,  6594,  1576,
    1580,  1805,   759, -1790, 10607, 10607, 10607,  1585,  1587,   -97,
     -62,   -56,  1588,  1594, -1790,  1932,  6594, -1790, 10607, -1790,
    1815, -1790,  1816, -1790,  1817, -1790,  1820, -1790, -1790, 11008,
    9343,   -31,  6148, -1790,  1597,  1598,  1599,  1600,  1601,  1606,
    8601, -1790,  9460, -1790, -1790, -1790,  1607, 10607, -1790, -1790,
   12959,  1854,  1856,  1700, -1790, 10607, 10607, 10607, -1790,  1860,
     838,  6026, -1790, -1790, -1790,  1637,  1865,  1132,  4143, -1790,
    2019, -1790,  1132,  4143, -1790,  2179, -1790,   287, -1790,   346,
   -1790, -1790, -1790, -1790, -1790, -1790,  4143, 10607, -1790, -1790,
   -1790, -1790,  4143,  1868, -1790, -1790,    24, -1790, -1790, -1790,
   -1790, -1790, -1790,  1867,   -58,   -58, -1790,  1869,   -58,   -58,
    6026, 10607,  1870,  1873,    31, -1790,  1872, 12982,    18, -1790,
    1874,  1876,  1877,  1878,  1516, 14120,  6594, 10607, 11932, 11958,
     860, -1790, 10607,  1875, -1790, -1790,  4143, -1790, 11984,  5479,
   14246, -1790,  1880,  1881, -1790, -1790, -1790, 10607, 10607,  -115,
    1879,  1883,  1884, -1790, 10607, 10607, -1790, -1790,  1885, 10607,
   -1790, -1790, -1790, -1790, -1790, -1790, -1790, -1790,  1887,  1888,
    1665,   106, -1790, -1790, -1790, 10607, 10607, 10607, 10607, 10607,
   10607, 10607, -1790, -1790, -1790,  1889,  1724,  1892, 10607, -1790,
    1907,  1908,  1909,  1913,  1916,  1917,  1091,  1918,  9460,  9460,
   10607, -1790,  9677,  5019, 14141,  2507,   394,   394,  -115,  1919,
    -115,  1920,  -115,  1921,  6594, 10607, -1790,   103,  1644, 14162,
   -1790, -1790, -1790, -1790,  1808,  5416,   255, -1790,  1923,  1924,
    6594,  -115,  -115,  -115,  -115,  -115,  4989,  1925,   868, 10607,
    2305,  1931, -1790, -1790,  6594,  3656,   564, 14183, -1790, -1790,
    9047,  1710,  5053,  5053,  6594, -1790,  1933,   -58,   -58, -1790,
    1935,   -58,   -58, -1790,  6594, -1790,  1717, 12660,   673,  5702,
    9120,  6026, -1790,  1938,  1953, -1790,  1954,  1955,  1960,  2587,
   -1790,  1961,  1963, -1790,  1739, -1790, -1790, -1790, -1790, -1790,
    1629,  1964,   572, 14246, 10607, 10607,  6594,  1757,   869, 14246,
   -1790,  1984, 10607, -1790, -1790,  1761,  1762,  6085,  6308,   249,
   -1790, -1790, -1790,  6531,  6754, -1790,  6977,  1989, -1790,  6594,
   12660, 12660, 12010, 12036, 12062, 12088, 12114, -1790,  1910,  1990,
   -1790, 14246, -1790, -1790, -1790, -1790, -1790, -1790,  1788, -1790,
   -1790,   872,   873, 10157,  2630,  1991,  1790, -1790, 10607, -1790,
    1763,  1792,   285, -1790,  1796,   292, -1790,  1797,   311, -1790,
    1800,  1806, 13005,  2008,  6594,  2009,  1927,  1809, 10607, -1790,
   -1790,   876,   331,   339,   345,   350,   377,  8824,   382, -1790,
    2014,  7200, -1790, -1790,  1851, 10607, -1790, 10607, -1790, -1790,
    9460,  2782,  2016,  6026,  1807,  1810,  1811, -1790,  2017,  2020,
   -1790,  2023,  2024,  2031, -1790, -1790, -1790,  5249, -1790, -1790,
    4143, 14246, -1790, -1790, -1790, -1790, -1790, -1790, -1790, -1790,
      18, -1790,  1882, -1790, -1790, 10607, 12140, 12166, -1790,  6594,
   10607,  2035, -1790, 12192, -1790, -1790,  6594,  6594,  2038,  2039,
    2040,  2041,  2045,  2046,   880, -1790, -1790, 10607, 10607, 10607,
   10607, 10607,  1822, -1790,  6594,   543,   632,  9460, -1790, -1790,
     394,  3761, -1790, -1790,  9343,     4,  9343,     4,  9343,     4,
   -1790,  2049, -1790,   908,  6594,  1825, -1790,  7423,  2051,  9460,
    -115,  -115,  -115,  -115,  -115, -1790, -1790, 10607,  7646,  7869,
     913, -1790, -1790,  1833,  1828, -1790,  2054, -1790, -1790, -1790,
   -1790, -1790,   914,  1862,  2055,   917,  2057, -1790,  1830, 14246,
   10607, 10607,   918, 14246, -1790, 10607,   921,   922, -1790, -1790,
   -1790, -1790, -1790, -1790, -1790, -1790,  1834, 12218, 12244, 12270,
   12296, 12322, 10607,   928,  1852,  -115,  6594,  2058,  1853,  -115,
    2076,   931,  1855, 10607, -1790,  8092,   388,    -7,  8315,   390,
     437,  8538,   440,   608, -1790,  6594,  2080,  1969,  6594, 11050,
    1858, -1790,   932,   451,   457,   460,   462,   471,  2801, -1790,
   -1790,  2084,  2085, -1790, -1790, 10607, -1790,  6026,    20, -1790,
   -1790, 10607, 14204, 12348,    46, 12374, -1790, -1790, -1790, -1790,
   10607, 10607, 10607, 10607, 10607, 10607,  8761,  2086,  -115,    78,
   -1790, -1790,  -115,    86, -1790,  2087, -1790,  8997,  2090, 10607,
    2091,  2093, 10607,  2094,  2095, 10607,  2096,  1871, -1790, 10607,
    1893, -1790,     4, -1790,  2098,  9460,  9460,  9460,  9460,  8824,
   -1790, -1790, -1790,  5053,  3217, -1790,  1900,   943, -1790, 10607,
   -1790,  6594, 10607,   955,   963, 12400, 12426, 12452, 12478, 12504,
   12530, -1790, -1790,   533, -1790,   574, -1790, -1790, -1790, -1790,
    1895,  9077, -1790, -1790,  1897,  9177, -1790, -1790,  1899,  9219,
   -1790,  2099,  3041, -1790,   686, 11135, -1790,   964,   971,   974,
     975,   579,   978,  1922,  6026,  1934,  2101,  1926, 14225,   979,
    9397, -1790, -1790, 10607, 10607, 10607, 10607, 10607, 10607,  -115,
    -115,     4,  2150,     4,  2152,     4,  2154, -1790, -1790, -1790,
   -1790,     4,  2156,  2157,  2159,  2174,  9460,  2181,  2182, -1790,
   -1790, -1790,  4143, -1790,  1958,  2184,  9584, 12660, 12556, 12582,
   12608, 12634,   585,   604,  1118, -1790,  1965,  1262, -1790,  1970,
    1412, -1790,  1971,  1447, -1790, -1790, -1790, -1790,   982, -1790,
   -1790,   985, -1790,  1972,  6594, -1790,  2194, -1790, 10607, 10607,
   10607, 10607, 10607, 10607,  2199,     4,  2200,     4,  2201,     4,
   -1790,  2202,  4143,  2203,  4143,   989, -1790,  9626,  9703,  9801,
    9868,  9910,  9992, -1790,  1458, -1790,  1577, -1790,  1689, -1790,
   -1790, -1790,   990, -1790,  2204, -1790, -1790, -1790, -1790,  2206,
    2207,  2208,  2209,  2210,  4143,  2211, -1790, -1790, -1790, -1790,
   -1790, -1790, -1790, -1790
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1790, -1790, -1790, -1790,   882, -1790, -1790, -1790, -1790,   228,
   -1790, -1790, -1790, -1790, -1790, -1790, -1790, -1790, -1790, -1790,
   -1790, -1790,   -71,     1,  3642,  3578, -1790,  1712, -1790, -1790,
   -1790, -1790, -1790, -1790, -1790, -1789, -1790,   393, -1790, -1790,
   -1790, -1790, -1790, -1790,   871,  2219,    -2,  -604,  -317, -1790,
   -1790, -1790, -1790, -1790, -1790, -1790, -1790,  2236, -1790, -1790,
   -1790, -1790, -1790, -1790, -1790, -1790, -1790, -1790, -1790, -1790,
   -1790, -1219, -1146,  2237, -1648,  2238, -1790, -1790, -1790,  1663,
   -1790,   380, -1790, -1790, -1790, -1790,  2060, -1790, -1790,    42,
   -1790, -1631,  3007,   356,  2316,    97,  -301,   725, -1790,   193,
      12, -1790,  -418,    -3,   278
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -562
static const yytype_int16 yytable[] =
{
     128,   111,  1441,   213,   336,   620,   601,   920,   921,  1781,
     717,  1081,   719,   637,  1804,  1805,   555,  1251,   212,  1556,
     363,   640,   359,   402,   370,   465,   238,   734,  1680,  1097,
    1304,  1545,   557,   243,   238,  1068,   243,   290,   376,   552,
     378,   861,   863,   286,     4,   865,   867,  1207,   216,   219,
    1429,   386,  2050,   559,   341,  1926,   342,   291,  1431,   307,
     669,  1341,   671,  1433,  1208,  1435,   290,     5,   679,   339,
    1438,   215,  1209,  1210,  1211,   308,   309,   286,  1212,  1213,
    1214,  1215,   339,   217,  2064,   389,  1077,   390,  1207,   609,
     610,   218,  2066,   339,   391,   230,   234,   231,  1854,   311,
     312,   315,   317,   235,   323,  1208,   221,  1418,   371,   313,
     375,   572,  1207,  1209,  1210,  1211,   314,   609,   610,  1212,
    1213,  1214,  1215,  1207,   609,   610,   609,   610,   747,  1208,
     401,   609,   610,  1618,   343,  1619,   222,  1209,  1210,  1211,
    1208,   611,   915,  1212,  1213,  1214,  1215,   922,  1209,  1210,
    1211,  1055,   609,   610,  1212,  1213,  1214,  1215,   609,   610,
    1437,   398,   399,  1082,  1083,  1084,  1085,   842,  1620,   843,
    1621,  -555,   801,   393,  1622,   384,  1623,   337,   609,   610,
     556,   751,   385,   296,   398,   399,   297,   466,   467,   298,
     624,   299,  1305,  1306,  -560,   612,   558,   625,  1430,   211,
     105,  1637,   339,   553,   470,  1681,  1432,   755,  1922,  2053,
    2054,  1434,   981,  1436,   501,   501,   234,   560,   105,   985,
     105,   292,   501,  1072,   293,  2020,   294,   609,   610,   223,
     339,   338,   286,  1943,  1098,   638,  1098,   286,  1252,  1086,
     364,   286,   207,   403,   509,   404,   239,   405,   501,   360,
     224,   286,   207,   240,   239,   286,   286,   286,   286,   501,
     244,  1073,  1069,  1074,   377,   554,   379,   862,   864,   387,
     286,   866,   868,   286,   220,   286,   388,  2051,  1342,  1055,
    1343,   129,   228,  1520,   214,   913,   914,   225,   286,   286,
     286,   286,   609,   610,  1055,  1438,   226,   286,   286,   286,
     609,   610,   300,   286,   339,   301,   931,   302,   476,   477,
     478,   479,   480,   481,   482,   483,   484,   485,   486,   573,
     488,   489,   394,   395,   396,   748,   490,   398,   399,   286,
     286,   286,   515,   609,   610,  1773,   332,   520,   333,   609,
     610,   524,   964,   286,   286,   394,   395,   396,   397,   930,
     340,   246,   604,   605,   657,   537,   623,   973,  1075,   207,
     613,   398,   399,   362,   622,   398,   399,   394,   395,   396,
     397,  -558,  1061,   227,   372,   394,   395,   396,   752,   229,
     501,   398,   399,   319,   286,   286,   320,   398,   399,   321,
     749,  -559,   753,   259,   756,  2093,   260,   286,   469,   261,
     236,   394,   395,   396,   397,   688,   394,   395,   396,   982,
     499,   503,   237,   394,   395,   396,   986,   487,   488,   489,
    2099,   398,   399,   241,   490,   501,   501,   501,   501,   501,
     501,   501,   501,   501,   501,   286,   501,   501,   242,   501,
     501,   501,   501,   501,   531,   609,   610,   501,   501,   501,
     501,   501,   339,   245,   339,   541,   609,   610,   324,   562,
     737,  1414,   563,   609,   610,   564,   757,   565,   745,   609,
     610,   286,  1440,   394,   395,   396,   397,   394,   395,   396,
     397,   398,   399,   468,   811,  1778,   812,  1147,   394,   395,
     396,   397,   246,   398,   399,   502,   502,   398,   399,   609,
     610,   303,   346,   502,   304,   347,   609,   610,   672,   286,
     673,   510,   544,   311,   312,  1874,   254,   207,    58,    59,
      60,    61,  1876,   313,   247,   609,   610,   398,   399,   502,
     322,   802,    71,  2185,   803,    74,   248,  -557,   325,   249,
     502,  1878,   326,   286,   286,   609,   610,   501,   327,   328,
     793,   329,   330,   609,   610,   794,  1207,   797,   286,   609,
     610,  1889,   798,   286,   609,   610,   331,   398,   399,  1890,
     286,   770,  1797,  1208,   800,  1891,   677,  -561,   250,   801,
    1892,  1209,  1210,  1211,   546,   362,   547,  1212,  1213,  1214,
    1215,   609,   610,   286,   286,  1193,   609,   610,   891,   894,
     897,   900,   609,   610,   609,   610,   811,  1893,   817,   470,
     470,   983,  1894,   987,  1037,   538,   539,   540,  2019,   801,
    2022,   811,   718,   821,   720,   721,   722,   723,   724,   725,
     726,   805,   728,   729,   803,   731,   732,   733,   255,   735,
     286,   286,   286,   739,   740,   741,   742,   743,   582,   583,
     584,   918,   919,   251,   609,   610,  1957,  1336,  1960,   605,
    1963,   502,   811,   869,   286,   609,   610,  1944,  1945,  2023,
    2025,   609,   610,  1946,   609,   610,   609,   610,   811,  1056,
     834,  2035,   252,  1062,   286,   609,   610,  2036,   633,   634,
    2037,   253,  2038,   907,   908,   996,   485,   486,   487,   488,
     489,  2039,   646,   647,   256,   490,   502,   502,   502,   502,
     502,   502,   502,   502,   502,   502,   257,   502,   502,   258,
     502,   502,   502,   502,   502,  1467,   262,  1207,   502,   502,
     502,   502,   502,   744,  1339,   746,   493,   288,   494,   811,
     950,   951,   952,   854,  1208,   391,   286,   609,   610,   289,
     286,  1057,  1209,  1210,  1211,  1063,  1948,  1949,  1212,  1213,
    1214,  1215,  1946,  2109,   970,  1611,  1612,  1064,  1313,   476,
     477,   478,   479,   480,   481,   482,   483,   484,   485,   486,
     487,   488,   489,   574,   990,   575,   295,   490,   609,   610,
     305,   286,   391,   609,   610,   286,  1798,  1834,   501,   609,
     610,   339,  1835,   501,  2110,  1207,   306,   286,   286,  2126,
     811,  1438,   871,  2084,  1438,  2172,   334,  1438,   609,   610,
    1113,   842,  1208,   843,   675,   851,   676,   844,   502,   310,
    1209,  1210,  1211,   391,  2173,   335,  1212,  1213,  1214,  1215,
    2026,   286,   996,   286,  1659,  1660,   286,   479,   480,   481,
     482,   483,   484,   485,   486,   487,   488,   489,   795,   286,
     796,   286,   490,   286,   542,   286,   543,   391,   544,   318,
     286,   206,   790,   207,   791,   286,   792,   344,  1514,  1515,
     356,   207,   286,  1518,  1519,   345,   398,   399,   979,   348,
     980,  1100,  2144,  1371,  2147,  1104,  2150,   842,   842,   843,
     843,  1439,  2153,   878,   349,   842,   286,   843,   350,   842,
    1020,   843,   357,  1265,  1045,   355,   358,  1270,  2119,   811,
     365,  1079,   476,   477,   478,   479,   480,   481,   482,   483,
     484,   485,   486,   487,   488,   489,   366,   811,  1438,  1161,
     490,  1142,  1468,  1143,   367,   842,  1145,   843,   368,   842,
    1047,   843,   373,   811,   811,  1189,  2194,  1196,  2196,  1157,
    2198,  1158,   369,  1159,  1202,  1160,   842,   811,   843,  1190,
    1164,  1503,  1219,   383,   431,  1167,   286,   842,   432,   843,
     286,   811,  1506,  1237,   286,  1266,   811,   433,  1238,  1271,
     438,   811,   501,  1239,  1107,  1275,  1277,   457,  1438,  1111,
     811,  1438,  1253,   811,  1438,  1273,  1191,  1438,   445,  1347,
    1526,  1348,  1760,  1761,  1353,   449,  1354,   286,   811,   811,
    1372,  1373,   501,   811,   811,  1374,  1382,   286,   501,   501,
     501,   481,   482,   483,   484,   485,   486,   487,   488,   489,
     501,   811,   501,  1383,   490,   811,   450,  1384,  1438,   811,
    1438,  1385,  1438,   811,   811,  1388,  1389,   451,   452,  1667,
    1668,   811,   492,  1411,  1671,  1672,   339,   473,   474,   286,
     286,   286,   286,  1528,   811,  1529,  1530,   455,   475,   502,
     491,   811,  1109,  1531,   502,   811,   811,  1532,  1533,   811,
    1706,  1580,  1707,  1330,  1331,  1748,   501,  1749,   811,  1840,
    1790,  1841,   811,   811,  1865,  1866,  1706,  1398,  1888,  1400,
    1706,  1402,  1936,  1404,   456,   286,   286,  1283,   286,   496,
     286,   286,   518,   523,   286,   286,   286,   286,   286,   286,
     286,   286,   536,   535,   789,   286,   498,   132,  1965,   561,
    1966,  1275,  1277,   811,  1985,  1981,  1986,   801,  1706,  1989,
    1994,  1503,  1506,  1996,  1997,  1662,  1346,  1663,  1706,   286,
    2007,   811,   811,  2015,  2034,   286,  1330,  1331,   385,  1316,
    1317,  1318,  1319,  1840,   578,  2096,   159,   160,   161,   162,
     163,   164,   165,   166,   167,  1503,   579,  2101,  1278,   172,
     173,   174,   175,  1503,   811,  2102,  2122,   177,   178,   179,
     585,   811,   180,  2123,   811,   811,  2124,  2125,   811,  1706,
    2127,  2134,   811,   185,  2181,  2182,   586,  2183,  1284,  1706,
    2214,  2204,  2215,   587,  1287,  1288,  1289,  1695,   572,   588,
     589,   596,   599,  1521,   602,  1370,  1293,  1207,  1294,   626,
     286,   286,   286,   603,   614,  1419,  1420,  1421,   615,   616,
     627,  1536,  1041,   639,  1208,   628,   286,   629,   630,   631,
     632,   636,  1209,  1210,  1211,   391,  1952,   641,  1212,  1213,
    1214,  1215,   642,   502,   643,   644,   645,   476,   477,   478,
     479,   480,   481,   482,   483,   484,   485,   486,   487,   488,
     489,   648,  1335,   501,   501,   490,   649,   650,   501,   501,
     652,  1310,   653,   502,   659,  1522,   660,   207,   339,   502,
     502,   502,   665,   666,   667,   668,   670,   188,   189,   190,
     686,   502,   690,   502,   286,   687,   691,   694,   490,   197,
     758,   198,   105,   476,   477,   478,   479,   480,   481,   482,
     483,   484,   485,   486,   487,   488,   489,   362,   286,   759,
    2174,   490,   206,  1551,   286,   761,   807,   842,   828,   843,
     808,   831,   835,   836,   837,   838,   286,   841,   884,   885,
     856,   902,   904,   858,   859,   860,   906,   502,   910,   911,
     912,  1207,   941,   943,   962,   944,   946,   953,   286,   286,
     286,   954,   965,   974,   286,   286,   978,   286,  1208,   286,
     991,   286,  1915,   286,   286,   286,  1209,  1210,  1211,   992,
    1023,  1024,  1212,  1213,  1214,  1215,  1674,  1025,  1028,  1030,
    1031,  1032,  1042,   286,  1043,   476,   477,   478,   479,   480,
     481,   482,   483,   484,   485,   486,   573,   488,   489,   286,
    1044,  1049,  1050,   490,  1052,  1053,  1051,   286,  1058,   286,
    1059,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,  1066,  1067,  1076,  1096,   490,
    1114,  1103,  1106,  1108,   501,   501,  1110,  1144,  1118,   501,
     501,  1119,  1636,  1661,  1117,  1121,  1122,  1123,  1124,  1126,
    1675,  1127,  1128,   501,  2176,  1129,  1130,  1131,  1132,   501,
     476,   477,   478,   479,   480,   481,   482,   483,   484,   485,
     486,   487,   488,   489,  1133,  1134,  1138,  1139,   490,  1146,
    1152,  1154,  1155,  1162,  1156,   339,  1168,  1174,  1176,  1916,
    1178,  1207,  1688,   286,  1179,  1199,  1206,  1232,  1261,  1180,
    1243,  1367,  1262,   501,  1182,  1244,   286,  1245,  1208,  1648,
    1184,  1181,  1183,  1255,  1185,  1192,  1209,  1210,  1211,  1246,
    1200,  1714,  1212,  1213,  1214,  1215,  1207,  1218,  1259,  1969,
    1258,  1263,  1267,  1268,   502,   502,  1298,  1207,  1300,   502,
     502,  1303,  1675,  1208,  1308,  1309,   498,   132,  1311,   362,
    1312,  1209,  1210,  1211,  1208,  1315,  1321,  1212,  1213,  1214,
    1215,  1719,  1209,  1210,  1211,   286,   286,  1325,  1212,  1213,
    1214,  1215,  1326,  1327,   470,   470,  1329,  1358,  1334,  1351,
    1357,   286,  1368,  1369,  1755,  1391,   159,   160,   161,   162,
     163,   164,   165,   166,   167,  1392,  1393,   286,  1396,   172,
     173,   174,   175,   286,  2178,  1397,  1451,   177,   178,   179,
    1406,   286,   180,  1407,  1408,  1409,  1410,  1412,  1422,  1423,
    1762,   286,  1765,   185,  1768,  1426,  2043,  1427,  1428,  1442,
    1443,   286,  1802,  1444,  1445,  1446,   286,  1447,  1448,  2180,
    1449,  1450,  1452,  1782,  1783,  1784,  1785,  1786,  1788,  1676,
    2211,  1819,  1822,  1823,  1453,  1678,  1207,  1454,  1455,  1456,
    1473,  1464,  1457,   286,  1458,  1751,  1752,  1459,  1469,  1470,
    1472,  1489,  1471,  1208,  1474,  1479,  2085,  1481,  1476,  1484,
    1486,  1209,  1210,  1211,  1488,  1490,   286,  1212,  1213,  1214,
    1215,  1496,  1502,  1523,  1499,  1510,  1524,  1537,  1544,  1711,
     476,   477,   478,   479,   480,   481,   482,   483,   484,   485,
     486,   487,   488,   489,  1547,   502,   502,  1542,   490,  1554,
     502,   502,  1543,  1553,  1552,  1555,  1559,   188,   189,   190,
    1563,   286,  1516,  1557,   502,  1558,  1564,  1566,  1565,   197,
     502,   198,   105,  1567,   286,  1569,  1570,  1571,  1572,  1573,
    1574,  1575,  1576,  1577,  1578,  1581,  1584,   286,  1583,  1592,
    1594,  1525,  1598,   398,   399,  1599,   362,  1608,  1207,  2212,
    1276,  1609,  1610,  -556,   286,  1903,  1616,   501,  1617,  1624,
    1625,  1630,  1631,  1632,   502,  1208,  1633,   339,  1640,  1641,
    1642,  1643,  1644,  1209,  1210,  1211,   286,  1645,  1649,  1212,
    1213,  1214,  1215,   286,   286,   476,   477,   478,   479,   480,
     481,   482,   483,   484,   485,   486,   487,   488,   489,  1394,
    1652,   286,  1653,   490,   286,  1654,  1658,  1664,   470,  1987,
     572,  1665,  1679,  1682,  1774,  1685,  1690,  1691,  1693,  1710,
    1696,   286,  1697,  1698,  1699,  1720,   286,  1715,  1716,  1721,
    1722,  1725,  1727,  1738,  1728,  1737,  1729,  1900,  1740,   476,
     477,   478,   479,   480,   481,   482,   483,   484,   485,   486,
     487,   488,   489,  1742,  1743,  1744,  1956,   490,  1959,  1745,
    1962,  2213,  1746,  1747,  1750,  1763,  1766,  1769,  1776,  1779,
    1780,  1789,  1973,  1974,  1975,  1976,  1977,  1793,  1626,  1807,
    1803,  1810,  1814,   286,  1824,   476,   477,   478,   479,   480,
     481,   482,   483,   484,   485,   486,   487,   488,   489,  1825,
    1826,  1827,   286,   490,  1951,   286,  1828,  1832,  1830,  1831,
    1833,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   339,  1972,  2009,  1839,   490,
    1842,  2013,  1846,  1847,  1853,  1872,  1863,  1869,  1862,  2045,
     476,   477,   478,   479,   480,   481,   482,   483,   484,   485,
     486,   487,   488,   489,  1882,  1897,  1884,  1885,   490,  1864,
    1895,  1870,  1902,  1907,  1873,  1669,  1908,  1875,  1877,  1909,
    1910,  1879,   286,   286,   286,   286,   286,  1911,  1880,  1904,
    1886,  1924,  1905,  1906,  1930,  1931,  1932,  1933,   286,  1917,
    2063,  1934,  1935,  1942,  2065,  1964,  1968,  1971,  1982,  1983,
    1984,  1991,  1988,  1990,  2011,  2000,   209,   476,   477,   478,
     479,   480,   481,   482,   483,   484,   485,   486,   810,   488,
     489,  2091,  2014,  2008,  2012,   490,  2028,  2016,  2029,  2033,
    2041,  2042,  2062,  2067,     7,     8,  2069,  2072,   502,  2073,
    2076,  2077,  2080,  2081,  2086,  2117,  2129,  2131,   362,   476,
     477,   478,   479,   480,   481,   482,   483,   484,   485,   486,
     487,   488,   489,   286,  2095,  2083,  2111,   490,  2113,   501,
    2115,   754,  2087,  2088,  2089,  2090,  2092,   476,   477,   478,
     479,   480,   481,   482,   483,   484,   485,   486,   487,   488,
     489,  2142,  2143,   572,  2128,   490,  2145,  2132,  2148,  2130,
    2151,   286,  2154,  2155,   381,  2156,   762,    24,    25,   763,
      27,    28,   764,    30,   765,    32,    33,    34,    35,   501,
    2157,   501,    37,    38,    39,  1673,    40,  2159,  2160,  2164,
    2165,    45,   766,    47,    48,   767,  2175,    51,    52,    53,
    2186,  2177,  2179,  2184,    56,  2193,  2195,  2197,  2199,  2201,
    2216,   501,  2217,  2218,  2219,  2220,  2221,  2223,  1546,  2047,
     806,  1561,   110,  2158,   476,   477,   478,   479,   480,   481,
     482,   483,   484,   485,   486,   487,   488,   489,  1927,   120,
     121,   122,   490,    82,    83,    84,  1950,   887,     0,  1692,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   458,
     459,   460,   462,   464,     0,     0,  2046,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   497,     0,     0,     0,
     504,     0,   478,   479,   480,   481,   482,   483,   484,   485,
     486,   487,   488,   489,   511,   513,   516,   517,   490,   519,
     513,   521,   522,     0,   513,   525,   526,   527,   528,   529,
     530,  1792,   532,   533,   927,     0,     0,     0,   513,     0,
       0,     0,     0,     0,     0,  2162,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   567,   569,   513,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   577,     0,
     476,   477,   478,   479,   480,   481,   482,   483,   484,   485,
     486,   810,   488,   489,   598,     0,     0,     0,   490,     0,
       0,     0,     0,   607,   608,  2200,     0,  2203,     0,     0,
       0,     0,   621,     0,   476,   477,   478,   479,   480,   481,
     482,   483,   484,   485,   486,   487,   488,   489,     0,     0,
       0,     0,   490,     0,     0,     0,     0,  2222,     0,     0,
     502,     0,   651,     0,     0,     0,   654,   655,   656,     0,
     658,     0,     0,     0,   661,   662,   663,     0,     0,   664,
     476,   477,   478,   479,   480,   481,   482,   483,   484,   485,
     486,   487,   488,   489,   678,     0,     0,     0,   490,   683,
     685,     0,     0,     0,     0,   917,     0,   929,     0,     0,
     502,     0,   502,   692,   693,     0,   695,   696,   697,   698,
     699,   700,   701,   702,   703,   704,   705,   706,   707,   708,
     709,   710,   711,   712,   713,   714,   715,   716,     0,     0,
       0,     0,   502,     0,     0,     0,     0,     0,     0,     0,
       0,   730,     0,     0,     0,     0,     0,   736,     0,   738,
     476,   477,   478,   479,   480,   481,   482,   483,   484,   485,
     486,   487,   488,   489,     0,     0,     0,     0,   490,     0,
       0,     0,     0,   769,   513,     0,   771,   772,   773,   774,
     775,   776,   777,   778,   779,   780,   781,   782,   783,   784,
     785,   514,     0,   787,   788,     0,   514,     0,     0,     0,
     514,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   567,     0,   514,     0,     0,     0,   815,     0,
       0,     0,     0,   820,     0,     0,     0,     0,     0,     0,
       0,     0,   568,  1829,   514,   832,   833,     0,     0,     0,
       0,     0,   839,   840,     0,     0,   847,   847,   852,   853,
       0,   855,     0,     0,   857,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   513,     0,     0,     0,
       0,     0,   872,   874,   876,   877,  1868,     0,   881,   882,
     883,     0,     0,     0,     0,   888,   890,   893,   896,   899,
     901,     0,   903,     0,   905,     0,   513,   513,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   923,   924,   925,   458,   459,   926,
       0,     7,     8,     0,   932,   933,   934,   935,   936,   937,
     938,   939,   940,     0,     0,     0,   945,     0,   947,   948,
       0,     0,     0,   513,   513,   513,     0,     0,   955,   956,
     957,     0,   476,   477,   478,   479,   480,   481,   482,   483,
     484,   485,   486,   487,   488,   489,     0,   513,     0,     0,
     490,     0,   839,   840,     0,   876,   877,  1758,     0,  1759,
       0,     0,     0,     0,     0,     0,   989,   513,   966,     0,
       0,   993,     0,   762,    24,    25,   763,    27,    28,   764,
      30,   765,    32,    33,    34,    35,     0,     0,     0,    37,
      38,    39,     0,    40,     0,     0,     0,     0,    45,   766,
      47,    48,   767,     0,    51,    52,    53,     0,  1901,     0,
     514,    56,   476,   477,   478,   479,   480,   481,   482,   483,
     484,   485,   486,   487,   488,   489,     0,  2040,     0,     0,
     490,     0,     0,     0,     0,     0,  1065,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   568,     0,
      82,    83,    84,     0,     0,   476,   477,   478,   479,   480,
     481,   482,   483,   484,   485,   486,   487,   488,   489,     0,
    1094,  1095,     0,   490,   513,  1101,  1102,  1080,   513,  1105,
       0,     0,   848,   850,     0,     0,     0,  1112,     0,     0,
     874,  1115,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   514,     0,     0,     0,     0,     0,     0,   875,
       0,  1135,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   949,     0,     0,   513,     0,   513,     0,     0,   513,
       0,     0,   514,   514,     0,     0,     0,     0,     0,     0,
       0,     0,   513,     0,   513,     0,   513,     0,   513,     0,
       0,     0,     0,   513,     0,     0,     0,     0,   513,     0,
       0,     0,     0,     0,  1172,   476,   477,   478,   479,   480,
     481,   482,   483,   484,   485,   486,   487,   488,   489,   514,
     514,   514,     0,   490,     0,     0,     0,     0,     0,   513,
       0,     0,     0,     0,     0,     0,  1197,  1198,     0,     0,
       0,     0,  1201,   514,     0,     0,     0,   476,   477,   478,
     479,   480,   481,   482,   483,   484,   485,   486,   487,   488,
     489,  1231,     0,   514,  1233,   490,   476,   477,   478,   479,
     480,   481,   482,   483,   484,   485,   486,   487,   488,   489,
       0,     0,     0,  1247,   490,  1249,  1250,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1257,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2118,     0,     0,
       0,     0,     0,   284,   476,   477,   478,   479,   480,   481,
     482,   483,   484,   485,   486,   487,   488,   489,  1279,     7,
       8,     0,   490,     0,     0,     0,  1280,  1281,  1282,     0,
     513,     0,     0,     0,     0,     0,     0,     0,  1285,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1292,     0,     0,     0,     0,  1295,     0,     0,
     514,     0,     0,     0,   514,     0,  1299,     0,     0,     0,
       0,     0,  1307,     0,     0,     0,   875,  1116,     0,     0,
       0,     0,   513,   513,   513,   513,  1320,     0,     0,     0,
    1323,   762,    24,    25,   763,    27,    28,   764,    30,   765,
      32,    33,    34,    35,     0,     0,     0,    37,    38,    39,
     514,    40,   514,     0,     0,   514,    45,   766,    47,    48,
     767,     0,    51,    52,    53,     0,     0,     0,   514,    56,
     514,     0,   514,     0,   514,     0,     0,     0,     0,   514,
       0,     0,     0,     0,   514,     0,     0,     0,   513,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1375,  1376,
       0,  1377,  1378,     0,  1379,  1380,  1381,     0,    82,    83,
      84,     0,     0,  1387,  2094,   514,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1399,
       0,  1401,     0,  1403,     0,  1405,   476,   477,   478,   479,
     480,   481,   482,   483,   484,   485,   486,   487,   488,   489,
       0,   534,  1163,     0,   490,     0,     0,     0,  1425,     0,
       7,     8,     0,     0,     0,     0,     0,     0,     0,     0,
     284,     0,     0,     0,     0,     0,     0,     0,     0,   971,
       0,     0,     0,     0,     0,     0,     0,     0,   581,     0,
       0,     0,  1460,     0,     0,     0,     0,   591,   593,   595,
       0,     0,     0,   600,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1480,     0,     0,     0,     0,
    1485,     0,     0,     0,     0,     0,   514,     0,     0,     0,
       0,   635,   762,    24,    25,   763,    27,    28,   764,    30,
     765,    32,    33,    34,    35,     0,     0,     0,    37,    38,
      39,     0,    40,     0,     0,     0,     0,    45,   766,    47,
      48,   767,  1527,    51,    52,    53,     0,     0,     0,     0,
      56,  1535,     0,     0,     0,  1538,  1539,     0,   514,   514,
     514,   514,     0,     0,   680,   681,     0,     0,     0,     0,
    1548,  1550,     0,     0,     0,     0,  1466,   689,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    82,
      83,    84,   476,   477,   478,   479,   480,   481,   482,   483,
     484,   485,   486,   487,   488,   489,     0,     0,     0,     0,
     490,     0,     0,     0,     0,   727,     0,     0,     0,     0,
       0,     0,     0,     0,   514,     0,     0,     0,     0,   476,
     477,   478,   479,   480,   481,   482,   483,   484,   485,   486,
     487,   488,   489,     0,  1613,  1614,  1615,   490,     0,     0,
       0,     0,     0,     0,     0,     0,  1627,     0,  1629,     0,
     972,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1635,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   513,     0,     0,     0,     0,  1650,     0,     0,
       0,     0,   130,   380,     0,  1655,  1656,  1657,   133,   134,
     135,     0,     0,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,     0,  1677,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   581,     0,
       0,     0,   168,   169,   170,   171,     0,     0,     0,     0,
     176,  1689,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   181,   182,   183,     0,     0,     0,  1703,     0,   184,
       0,     0,  1709,   476,   477,   478,   479,   480,   481,   482,
     483,   484,   485,   486,   487,   488,   489,  1717,  1718,     0,
       0,   490,     0,     0,  1723,  1724,     0,     0,     0,  1726,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1730,  1731,  1732,  1733,  1734,
    1735,  1736,     0,     0,     0,     0,     0,     0,  1741,     0,
       0,     0,     0,   232,   233,     0,     0,     0,   513,   513,
    1753,     0,  1754,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1772,   476,   477,   478,   479,
     480,   481,   482,   483,   484,   485,   486,   487,   488,   489,
       0,     0,     0,   187,   490,     0,   513,   191,   969,  1791,
       0,   192,   193,   194,   195,   196,     0,     0,     0,   105,
    1801,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   199,   200,     0,     0,     0,   201,     0,
    1821,     0,     0,   352,     0,     0,     0,     0,   205,     0,
     597,     0,     0,     0,     0,     0,  1054,     0,     0,     0,
    1060,     0,     0,     0,  1836,  1837,     0,     0,   514,     0,
     392,     0,  1843,     0,     0,     0,     0,     0,     0,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,   416,
     417,   418,   419,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,     0,     0,     0,   434,   435,   436,
     437,     0,   439,   440,   441,   442,   443,   444,  1871,     0,
     446,     0,     0,     0,     0,     0,   447,   448,     0,     0,
       0,     0,   453,   454,     0,     0,     0,     0,  1887,     0,
       0,     0,     0,     0,     0,     0,     0,   567,     0,     0,
       0,     0,     0,     0,     0,  1898,     0,  1899,     0,     0,
     513,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,     0,     0,  1913,     0,   490,
       0,     0,     0,     0,     0,     0,  1795,     0,  1796,     0,
       0,     0,  1173,     0,     0,  1919,     0,     0,     0,     0,
    1923,     0,     0,     0,     0,   545,     0,   548,   549,   550,
     551,     0,     0,     0,     0,     0,     0,  1937,  1938,  1939,
    1940,  1941,     0,     0,   514,   514,     0,   513,   576,     0,
       0,     0,     0,     0,  1955,     0,  1958,     0,  1961,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   513,
       0,     0,     0,     0,     0,     0,     0,  1978,     0,     0,
       0,     0,   514,   370,   132,     0,   476,   477,   478,   479,
     480,   481,   482,   483,   484,   485,   486,   487,   488,   489,
    1992,  1993,     0,     0,   490,  1995,  1260,     0,     0,     0,
    1264,  1953,     0,  1954,  1269,     0,     0,     0,     0,     0,
       0,     0,  2006,   159,   160,   161,   162,   163,   164,   165,
     166,   167,     0,  2017,     0,     0,   172,   173,   174,   175,
       0,     0,     0,     0,   177,   178,   179,     0,     0,   180,
       0,     0,     0,     0,     0,     0,     0,  1286,     0,     0,
     185,     0,     0,     0,     0,  2044,     0,     0,     0,     0,
       0,  1709,     0,     0,     0,     0,     0,     0,     0,     0,
    2055,  2056,  2057,  2058,  2059,  2060,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2071,
       0,     0,  2075,     0,     0,  2079,     0,     0,     0,  2082,
       0,     0,     0,     0,     0,   513,   513,   513,   513,   513,
       0,     0,     0,   568,     0,     0,     0,     0,     0,  2098,
     760,     0,  2100,     0,     0,     0,   514,     0,     0,     0,
       0,     0,     0,     0,     0,  1349,  1350,     0,  1352,     0,
    1355,  1356,     0,  1914,  1359,  1360,  1361,  1362,  1363,  1364,
    1365,  1366,     0,     0,   188,   189,   190,   498,   132,     0,
       0,     0,     0,     0,   879,     0,   197,     0,   198,   105,
       0,     0,     0,  2136,  2137,  2138,  2139,  2140,  2141,  1386,
       0,     0,     0,     0,     0,  1390,     0,     0,     0,     0,
       0,     0,     0,   514,     0,     0,   513,   159,   160,   161,
     162,   163,   164,   165,   166,   167,     0,     0,     0,     0,
     172,   173,   174,   175,     0,   514,     0,     0,   177,   178,
     179,     0,     0,   180,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   185,     0,     0,     0,  2187,  2188,
    2189,  2190,  2191,  2192,     0,   476,   477,   478,   479,   480,
     481,   482,   483,   484,   485,   486,   487,   488,   489,     0,
    1461,  1462,  1463,   490,     0,     0,     0,     0,     0,     0,
       0,     0,  1078,     0,     0,     0,  1475,     0,     0,     0,
       0,     0,     0,   997,   998,   999,  1000,  1001,  1002,  1003,
    1004,  1005,  1006,  1007,     0,  1009,  1010,  1011,  1012,  1013,
    1014,  1015,     0,     0,     0,  1019,  1021,  1022,     0,     0,
       0,  1026,  1027,     0,  1029,     0,     0,     0,     0,  1034,
    1035,  1036,     0,  1038,     0,     0,     0,     0,     0,     0,
    1046,  1048,     0,     0,     0,     0,     0,     0,   188,   189,
     190,     0,     0,     0,  1541,     0,     0,     0,  1071,     0,
     197,     0,   198,   105,     0,     0,     0,     0,     0,     0,
       0,   514,   514,   514,   514,   514,     0,     0,  1562,     0,
       0,     0,     0,     0,  1568,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1579,     0,     0,   476,
     477,   478,   479,   480,   481,   482,   483,   484,   485,   486,
     487,   488,   489,     0,     0,     0,     0,   490,  1595,  1596,
    1597,     0,     0,     0,  1600,  1601,  1137,  1602,     0,  1603,
       0,  1604,     0,  1605,  1606,  1607,   476,   477,   478,   479,
     480,   481,   482,   483,   484,   485,   486,   487,   488,   489,
       0,     0,  1150,  1628,   490,     0,     0,     0,     0,     0,
       0,     0,   514,  1153,     0,     0,     0,     0,     0,  1639,
       0,     0,   130,   131,   132,     0,     0,  1647,   133,   134,
     135,     0,     0,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,     0,     0,     0,     7,
       8,     0,     0,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,     0,     0,     0,   177,   178,   179,     0,     0,   180,
       0,   181,   182,   183,     0,     0,     0,     0,     0,   184,
     185,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1701,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1713,     0,     0,     0,
       0,   762,    24,    25,   763,    27,    28,   764,    30,   765,
      32,    33,    34,    35,     0,     0,     0,    37,    38,    39,
       0,    40,     0,     0,     0,     0,    45,   766,    47,    48,
     767,     0,    51,    52,    53,     0,     0,     0,     0,    56,
     476,   477,   478,   479,   480,   481,   482,   483,   484,   485,
     486,   487,   488,   489,     0,     0,     0,     0,   490,     0,
       0,     0,     0,     0,     0,     0,   186,  1223,     0,     0,
       0,  1771,     0,   187,   188,   189,   190,   191,    82,    83,
      84,   192,   193,   194,   195,   196,   197,  1541,   198,   105,
       0,     0,     0,     0,     0,     0,     0,  1322,     0,     0,
       0,  1794,     0,   199,   200,     0,     0,     0,   201,     0,
       0,  1806,     0,   202,     0,   203,     0,   204,   205,     0,
     206,  1813,   207,     0,     0,     0,  1818,     0,     0,     0,
    1344,  1345,     0,     0,  1296,  1297,     0,     0,     0,     0,
    1301,  1302,     0,     0,     0,     0,     0,     0,     0,  1194,
       0,     0,     0,  1838,   476,   477,   478,   479,   480,   481,
     482,   483,   484,   485,   486,   487,   488,   489,     0,     0,
       0,     0,   490,     0,     0,     0,  1541,     0,     0,     0,
       0,  1272,     0,   130,   380,   132,     0,     0,     0,   133,
     134,   135,     0,     0,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,     0,     0,     0,
       0,  1883,     0,     0,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,     0,     0,     0,   177,   178,   179,     0,     0,
     180,     0,   181,   182,   183,     0,     0,     0,     0,     0,
     184,   185,   476,   477,   478,   479,   480,   481,   482,   483,
     484,   485,   486,   487,   488,   489,     0,     0,     0,     0,
     490,     0,     0,     0,     0,     0,  1541,     0,     0,  1417,
       0,  1487,     0,  1928,  1929,     0,     0,  1491,  1492,  1493,
    1494,  1495,     0,  1498,     0,  1500,  1501,     0,  1504,  1507,
       0,  1541,  1511,  1512,  1513,     0,     0,     0,     0,  1517,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1967,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1477,  1478,     0,     0,     0,  1482,
    1483,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   187,   188,   189,   190,   191,     0,
       0,     0,   192,   193,   194,   195,   196,   197,     0,   198,
     105,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1582,     0,     0,  2010,   199,   200,     0,     0,     0,   201,
       0,     0,     0,     0,   352,     0,     0,  1593,     0,   205,
       0,  1549,  2027,     0,     0,  2030,   476,   477,   478,   479,
     480,   481,   482,   483,   484,   485,   486,   487,   488,   489,
       0,     0,   130,   263,   490,     0,     0,     0,   133,   134,
     135,     0,   674,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   264,   265,   266,   267,
     268,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   168,   169,   170,   171,     0,     0,     0,     0,
     176,     0,     0,     0,     0,  1666,     0,     0,  1541,     0,
    1670,   181,   182,   183,     0,     7,     8,     0,     0,   184,
       0,     0,     0,   269,     0,     0,   270,     0,     0,   271,
       0,   272,     0,     0,     0,     0,     0,     0,    36,     0,
       0,     0,  1683,  1684,     0,     0,  1686,  1687,     0,   273,
       0,     0,   274,     0,     0,   275,     0,     0,     0,     0,
       0,     0,     0,    58,    59,    60,    61,    62,     0,     0,
      64,    65,    66,    67,    68,     0,     0,    71,     0,     0,
      74,     0,     0,     0,     0,     0,     0,   762,    24,    25,
     763,    27,    28,   764,    30,   765,    32,    33,    34,    35,
       0,     0,     0,    37,    38,    39,     0,    40,     0,     0,
       0,     0,    45,   766,    47,    48,   767,     0,    51,    52,
      53,  1541,     0,   187,     0,    56,     0,   191,     0,     0,
       0,   192,   193,   194,   195,   196,     0,     0,     0,   105,
       0,     0,   976,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   617,  1787,     0,     0,     0,   201,     0,
       0,     0,     0,   619,    82,    83,    84,     0,   205,     0,
     314,   570,     0,     0,   476,   477,   478,   479,   480,   481,
     482,   483,   484,   485,   486,   487,   488,   489,     0,     0,
       0,     0,   490,     0,     0,  1808,  1809,     0,     0,  1811,
    1812,  1756,   130,   263,     0,  1815,  1816,     0,   133,   134,
     135,     0,     0,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   264,   265,   266,   267,
     268,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   168,   169,   170,   171,     0,     0,  1855,  1856,
     176,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   181,   182,   183,     0,     7,     8,     0,     0,   184,
       0,     0,     0,   269,     0,     0,   270,     0,     0,   271,
       0,   272,     0,     0,     0,     0,     0,     0,    36,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   273,
       0,     0,   274,     0,     0,   275,     0,     0,     0,     0,
       0,     0,     0,    58,    59,    60,    61,    62,     0,     0,
      64,    65,    66,    67,    68,     0,     0,    71,     0,     0,
      74,     0,     0,     0,     0,     0,     0,   762,    24,    25,
     763,    27,    28,   764,    30,   765,    32,    33,    34,    35,
       0,     0,     0,    37,    38,    39,     0,    40,     0,     0,
       0,     0,    45,   766,    47,    48,   767,     0,    51,    52,
      53,     0,     0,   187,     0,    56,     0,   191,     0,     0,
       0,   192,   193,   194,   195,   196,     0,     0,     0,   105,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   199,   512,     0,     0,     0,   201,     0,
       0,     0,     0,   352,    82,    83,    84,     0,   205,     0,
       0,   570,   130,   263,   132,     0,     0,     0,   133,   134,
     135,     0,     0,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   264,   265,   266,   267,
     268,     0,     0,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,     0,     0,     0,   177,   178,   179,     0,     0,   180,
       0,   181,   182,   183,     0,     0,     0,     0,     0,   184,
     185,     0,     0,   269,     0,     0,   270,     0,     0,   271,
       0,   272,     0,     0,     0,     0,     0,     0,    36,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   273,
       0,     0,   274,     0,     0,   275,     0,     0,     0,     0,
       0,     0,     0,    58,    59,    60,    61,    62,     0,     0,
      64,    65,    66,    67,    68,     0,     0,    71,     0,     0,
      74,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,     0,     0,     0,     0,   490,
       0,     0,     0,     0,     0,     0,     0,     0,  1777,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   187,   188,   189,   190,   191,     0,     0,
       0,   192,   193,   194,   195,   196,   197,     0,   198,   105,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   199,   276,     0,     0,     0,   201,     0,
       0,     0,     0,   352,     0,   130,   263,   132,   205,     0,
     278,   133,   134,   135,     0,  2167,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   264,
     265,   266,   267,   268,     0,     0,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,     0,     0,     0,   177,   178,   179,
       0,     0,   180,     0,   181,   182,   183,     0,     0,     0,
       0,     0,   184,   185,     0,     0,   269,     0,     0,   270,
       0,     0,   271,     0,   272,     0,     0,     0,     0,     0,
       0,    36,     0,     0,     0,     0,     0,   374,   132,     0,
       0,     0,   273,     0,     0,   274,     0,     0,   275,     0,
       0,     0,     0,     0,     0,     0,    58,    59,    60,    61,
      62,     0,     0,    64,    65,    66,    67,    68,     0,     0,
      71,     0,     0,    74,     0,     0,     0,   159,   160,   161,
     162,   163,   164,   165,   166,   167,     0,     0,     0,     0,
     172,   173,   174,   175,     0,     0,     0,     0,   177,   178,
     179,     0,     0,   180,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   185,     0,   187,   188,   189,   190,
     191,     0,     0,     0,   192,   193,   194,   195,   196,   197,
       0,   198,   105,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   199,   276,     0,     0,
       0,   201,     0,     0,     0,     0,   352,     0,   130,   263,
     351,   205,     0,  1817,   133,   134,   135,     0,     0,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   264,   265,   266,   267,   268,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   168,   169,
     170,   171,     0,     0,     0,     0,   176,     0,   188,   189,
     190,     0,     0,     0,     0,     0,     0,   181,   182,   183,
     197,     0,   198,     0,     0,   184,     0,     0,     0,   269,
       0,     0,   270,     0,     0,   271,     0,   272,     0,     0,
       0,     0,     0,     0,    36,     0,     0,     0,     0,     0,
       0,   132,     0,     0,     0,   273,     0,     0,   274,     0,
       0,   275,     0,     0,     0,     0,     0,     0,     0,    58,
      59,    60,    61,    62,     0,     0,    64,    65,    66,    67,
      68,     0,     0,    71,     0,     0,    74,     0,     0,     0,
     159,   160,   161,   162,   163,   164,   165,   166,   167,     0,
       0,     0,     0,   172,   173,   174,   175,     0,     0,     0,
       0,   177,   178,   179,     0,     0,   180,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   185,     0,   187,
       0,     0,     0,   191,     0,     0,     0,   192,   193,   194,
     195,   196,     0,     0,     0,   105,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   199,
     276,     0,     0,     0,   201,     0,     0,     0,     0,   352,
       0,   130,   263,  1638,   205,     0,   278,   133,   134,   135,
       0,     0,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   264,   265,   266,   267,   268,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   168,   169,   170,   171,     0,     0,     0,     0,   176,
       0,   188,   189,   190,     0,     0,     0,     0,     0,     0,
     181,   182,   183,   197,     0,   198,     0,     0,   184,     0,
       0,     0,   269,     0,     0,   270,     0,     0,   271,     0,
     272,     0,     0,     0,     0,     0,     0,    36,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   273,     0,
       0,   274,     0,     0,   275,     0,     0,     0,     0,     0,
       0,     0,    58,    59,    60,    61,    62,     0,     0,    64,
      65,    66,    67,    68,     0,     0,    71,     0,     0,    74,
     476,   477,   478,   479,   480,   481,   482,   483,   484,   485,
     486,   487,   488,   489,     0,     0,     0,     0,   490,     0,
       0,     0,     0,     0,     0,     0,     0,  1848,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   187,     0,     0,     0,   191,     0,     0,     0,
     192,   193,   194,   195,   196,     0,     0,     0,   105,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   199,   276,     0,     0,     0,   201,     0,     0,
       0,     0,   352,     0,   130,   263,     0,   205,     0,   278,
     133,   134,   135,     0,     0,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   264,   265,
     266,   267,   268,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   168,   169,   170,   171,     0,     0,
       0,     0,   176,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   181,   182,   183,     0,     0,     0,     0,
       0,   184,     0,     0,     0,   269,     0,     0,   270,     0,
       0,   271,     0,   272,     0,     0,     0,     0,     0,     0,
      36,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   273,     0,     0,   274,     0,     0,   275,     0,     0,
       0,     0,     0,     0,     0,    58,    59,    60,    61,    62,
       0,     0,    64,    65,    66,    67,    68,     0,     0,    71,
       0,     0,    74,   476,   477,   478,   479,   480,   481,   482,
     483,   484,   485,   486,   487,   488,   489,     0,     0,     0,
       0,   490,     0,     0,     0,     0,     0,     0,     0,     0,
    1849,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   187,     0,     0,     0,   191,
       0,     0,     0,   192,   193,   194,   195,   196,     0,     0,
       0,   105,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   199,   276,     0,     0,     0,
     201,     0,     0,     0,     0,   277,     0,   130,   263,     0,
     205,     0,   278,   133,   134,   135,     0,     0,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   264,   265,   266,   267,   268,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   168,   169,   170,
     171,     0,     0,     0,     0,   176,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   181,   182,   183,     0,
       0,     0,     0,     0,   184,     0,     0,     0,   269,     0,
       0,   270,     0,     0,   271,     0,   272,     0,     0,     0,
       0,     0,     0,    36,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   273,     0,     0,   274,     0,     0,
     275,     0,     0,     0,     0,     0,     0,     0,    58,    59,
      60,    61,    62,     0,     0,    64,    65,    66,    67,    68,
       0,     0,    71,     0,     0,    74,   476,   477,   478,   479,
     480,   481,   482,   483,   484,   485,   486,   487,   488,   489,
       0,     0,     0,     0,   490,     0,     0,     0,     0,     0,
       0,     0,     0,  1850,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   187,     0,
       0,     0,   191,     0,     0,     0,   192,   193,   194,   195,
     196,     0,     0,     0,   105,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   199,   276,
       0,     0,     0,   201,     0,     0,     0,     0,   352,     0,
     130,   263,     0,   205,     0,   278,   133,   134,   135,     0,
       0,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   264,   265,   266,   267,   268,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     168,   169,   170,   171,     0,     0,     0,     0,   176,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   181,
     182,   183,     0,     0,     0,     0,     0,   184,     0,     0,
       0,   269,     0,     0,   270,     0,     0,   271,     0,   272,
       0,     0,     0,     0,     0,     0,    36,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   273,     0,     0,
     274,     0,     0,   275,     0,     0,     0,     0,     0,     0,
       0,    58,    59,    60,    61,    62,     0,     0,    64,    65,
      66,    67,    68,     0,     0,    71,     0,     0,    74,   476,
     477,   478,   479,   480,   481,   482,   483,   484,   485,   486,
     487,   488,   489,     0,     0,     0,     0,   490,     0,     0,
       0,     0,     0,     0,     0,     0,  1851,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   187,     0,     0,     0,   191,     0,     0,     0,   192,
     193,   194,   195,   196,     0,     0,     0,   105,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   199,   512,     0,     0,     0,   201,     0,     0,     0,
       0,   352,     0,   130,   263,     0,   205,     0,   566,   133,
     134,   135,     0,     0,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   264,   265,   266,
     267,   268,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   168,   169,   170,   171,     0,     0,     0,
       0,   176,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   181,   182,   183,     0,     0,     0,     0,     0,
     184,     0,     0,     0,   269,     0,     0,   270,     0,     0,
     271,     0,   272,     0,     0,     0,     0,     0,     0,    36,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     273,     0,     0,   274,     0,     0,   275,     0,     0,     0,
       0,     0,     0,     0,    58,    59,    60,    61,    62,     0,
       0,    64,    65,    66,    67,    68,     0,     0,    71,     0,
       0,    74,   476,   477,   478,   479,   480,   481,   482,   483,
     484,   485,   486,   487,   488,   489,     0,     0,     0,     0,
     490,     0,     0,     0,     0,     0,     0,     0,     0,  1852,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   187,     0,     0,     0,   191,     0,
       0,     0,   192,   193,   194,   195,   196,     0,     0,     0,
     105,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   199,   276,     0,     0,     0,   201,
       0,     0,     0,     0,   580,     0,   130,   263,     0,   205,
       0,   278,   133,   134,   135,     0,     0,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     264,   265,   266,   267,   268,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   168,   169,   170,   171,
       0,     0,     0,     0,   176,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   181,   182,   183,     0,     0,
       0,     0,     0,   184,     0,     0,     0,   269,     0,     0,
     270,     0,     0,   271,     0,   272,     0,     0,     0,     0,
       0,     0,    36,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   273,     0,     0,   274,     0,     0,   275,
       0,     0,     0,     0,     0,     0,     0,    58,    59,    60,
      61,    62,     0,     0,    64,    65,    66,    67,    68,     0,
       0,    71,     0,     0,    74,   476,   477,   478,   479,   480,
     481,   482,   483,   484,   485,   486,   487,   488,   489,     0,
       0,     0,     0,   490,     0,     0,     0,     0,     0,     0,
       0,     0,  1896,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   187,     0,     0,
       0,   191,     0,     0,     0,   192,   193,   194,   195,   196,
       0,     0,     0,   105,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   199,   276,     0,
       0,     0,   201,     0,     0,     0,     0,   590,     0,   130,
     263,     0,   205,     0,   278,   133,   134,   135,     0,     0,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   264,   265,   266,   267,   268,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   168,
     169,   170,   171,     0,     0,     0,     0,   176,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   181,   182,
     183,     0,     0,     0,     0,     0,   184,     0,     0,     0,
     269,     0,     0,   270,     0,     0,   271,     0,   272,     0,
       0,     0,     0,     0,     0,    36,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   273,     0,     0,   274,
       0,     0,   275,     0,     0,     0,     0,     0,     0,     0,
      58,    59,    60,    61,    62,     0,     0,    64,    65,    66,
      67,    68,     0,     0,    71,     0,     0,    74,   476,   477,
     478,   479,   480,   481,   482,   483,   484,   485,   486,   487,
     488,   489,     0,     0,     0,     0,   490,     0,     0,     0,
       0,     0,     0,     0,     0,  1970,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     187,     0,     0,     0,   191,     0,     0,     0,   192,   193,
     194,   195,   196,     0,     0,     0,   105,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     199,   276,     0,     0,     0,   201,     0,     0,     0,     0,
     592,     0,   130,   263,     0,   205,     0,   278,   133,   134,
     135,     0,     0,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   264,   265,   266,   267,
     268,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   168,   169,   170,   171,     0,     0,     0,     0,
     176,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   181,   182,   183,     0,     0,     0,     0,     0,   184,
       0,     0,     0,   269,     0,     0,   270,     0,     0,   271,
       0,   272,     0,     0,     0,     0,     0,     0,    36,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   273,
       0,     0,   274,     0,     0,   275,     0,     0,     0,     0,
       0,     0,     0,    58,    59,    60,    61,    62,     0,     0,
      64,    65,    66,    67,    68,     0,     0,    71,     0,     0,
      74,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,     0,     0,     0,     0,   490,
       0,     0,     0,     0,     0,     0,     0,     0,  1979,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   187,     0,     0,     0,   191,     0,     0,
       0,   192,   193,   194,   195,   196,     0,     0,     0,   105,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   199,   276,     0,     0,     0,   201,     0,
       0,     0,     0,   594,     0,   130,   263,     0,   205,     0,
     278,   133,   134,   135,     0,     0,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   264,
     265,   266,   267,   268,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   168,   169,   170,   171,     0,
       0,     0,     0,   176,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   181,   182,   183,     0,     0,     0,
       0,     0,   184,     0,     0,     0,   269,     0,     0,   270,
       0,     0,   271,     0,   272,     0,     0,     0,     0,     0,
       0,    36,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   273,     0,     0,   274,     0,     0,   275,     0,
       0,     0,     0,     0,     0,     0,    58,    59,    60,    61,
      62,     0,     0,    64,    65,    66,    67,    68,     0,     0,
      71,     0,     0,    74,   476,   477,   478,   479,   480,   481,
     482,   483,   484,   485,   486,   487,   488,   489,     0,     0,
       0,     0,   490,     0,     0,     0,     0,     0,     0,     0,
       0,  1980,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   187,     0,     0,     0,
     191,     0,     0,     0,   192,   193,   194,   195,   196,     0,
       0,     0,   105,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   199,   512,     0,     0,
       0,   201,     0,     0,     0,     0,   352,     0,   130,   263,
       0,   205,     0,   846,   133,   134,   135,     0,     0,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   264,   265,   266,   267,   268,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   168,   169,
     170,   171,     0,     0,     0,     0,   176,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   181,   182,   183,
       0,     0,     0,     0,     0,   184,     0,     0,     0,   269,
       0,     0,   270,     0,     0,   271,     0,   272,     0,     0,
       0,     0,     0,     0,    36,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   273,     0,     0,   274,     0,
       0,   275,     0,     0,     0,     0,     0,     0,     0,    58,
      59,    60,    61,    62,     0,     0,    64,    65,    66,    67,
      68,     0,     0,    71,     0,     0,    74,   476,   477,   478,
     479,   480,   481,   482,   483,   484,   485,   486,   487,   488,
     489,     0,     0,     0,     0,   490,     0,     0,     0,     0,
       0,     0,     0,     0,  2018,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   187,
       0,     0,     0,   191,     0,     0,     0,   192,   193,   194,
     195,   196,     0,     0,     0,   105,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   199,
     512,     0,     0,     0,   201,     0,     0,     0,     0,   352,
       0,   130,   263,     0,   205,     0,   849,   133,   134,   135,
       0,     0,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   264,   265,   266,   267,   268,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   168,   169,   170,   171,     0,     0,     0,     0,   176,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     181,   182,   183,     0,     0,     0,     0,     0,   184,     0,
       0,     0,   269,     0,     0,   270,     0,     0,   271,     0,
     272,     0,     0,     0,     0,     0,     0,    36,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   273,     0,
       0,   274,     0,     0,   275,     0,     0,     0,     0,     0,
       0,     0,    58,    59,    60,    61,    62,     0,     0,    64,
      65,    66,    67,    68,     0,     0,    71,     0,     0,    74,
     476,   477,   478,   479,   480,   481,   482,   483,   484,   485,
     486,   487,   488,   489,     0,     0,     0,     0,   490,     0,
       0,     0,     0,     0,     0,     0,     0,  2021,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   187,     0,     0,     0,   191,     0,     0,     0,
     192,   193,   194,   195,   196,     0,     0,     0,   105,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   199,   512,     0,     0,     0,   201,     0,     0,
       0,     0,   352,     0,   130,   263,     0,   205,     0,   873,
     133,   134,   135,     0,     0,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   264,   265,
     266,   267,   268,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   168,   169,   170,   171,     0,     0,
       0,     0,   176,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   181,   182,   183,     0,     0,     0,     0,
       0,   184,     0,     0,     0,   269,     0,     0,   270,     0,
       0,   271,     0,   272,     0,     0,     0,     0,     0,     0,
      36,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   273,     0,     0,   274,     0,     0,   275,     0,     0,
       0,     0,     0,     0,     0,    58,    59,    60,    61,    62,
       0,     0,    64,    65,    66,    67,    68,     0,     0,    71,
       0,     0,    74,   476,   477,   478,   479,   480,   481,   482,
     483,   484,   485,   486,   487,   488,   489,     0,     0,     0,
       0,   490,     0,     0,     0,     0,     0,     0,     0,     0,
    2024,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   187,     0,     0,     0,   191,
       0,     0,     0,   192,   193,   194,   195,   196,     0,     0,
       0,   105,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   199,   276,     0,     0,     0,
     201,     0,     0,     0,     0,   352,     0,   130,   263,     0,
     205,     0,  1646,   133,   134,   135,     0,     0,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   264,   265,   266,   267,   268,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   168,   169,   170,
     171,     0,     0,     0,     0,   176,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   181,   182,   183,     0,
       0,     0,     0,     0,   184,     0,     0,     0,   269,     0,
       0,   270,     0,     0,   271,     0,   272,     0,     0,     0,
       0,     0,     0,    36,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   273,     0,     0,   274,     0,     0,
     275,     0,     0,     0,     0,     0,     0,     0,    58,    59,
      60,    61,    62,     0,     0,    64,    65,    66,    67,    68,
       0,     0,    71,     0,     0,    74,   476,   477,   478,   479,
     480,   481,   482,   483,   484,   485,   486,   487,   488,   489,
       0,     0,     0,     0,   490,     0,     0,     0,     0,     0,
       0,     0,     0,  2061,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   187,     0,
       0,     0,   191,     0,     0,     0,   192,   193,   194,   195,
     196,     0,     0,     0,   105,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   617,  1787,
       0,     0,     0,   201,     0,     0,     0,     0,   619,     0,
     130,   380,   132,   205,     0,   314,   133,   134,   135,     0,
       0,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,     0,     0,     0,     0,     0,     0,
       0,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,     0,
       0,     0,   177,   178,   179,     0,     0,   180,     0,   181,
     182,   183,     0,   130,   380,   132,     0,   184,   185,   133,
     134,   135,     0,     0,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,     0,     0,     0,
       0,     0,     0,     0,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,     0,     0,     0,   177,   178,   179,     0,     0,
     180,     0,   181,   182,   183,     0,     0,     0,     0,     0,
     184,   185,   476,   477,   478,   479,   480,   481,   482,   483,
     484,   485,   486,   487,   488,   489,     0,     0,     0,     0,
     490,     0,     0,     0,     0,     0,     0,     0,     0,  2068,
       0,   187,   188,   189,   190,   191,     0,     0,     0,   192,
     193,   194,   195,   196,   197,     0,   198,   105,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   199,   200,     0,     0,     0,   201,     0,     0,     0,
       0,   352,     0,     0,     0,     0,   205,     0,  1800,     0,
       0,     0,   476,   477,   478,   479,   480,   481,   482,   483,
     484,   485,   486,   487,   488,   489,     0,     0,     0,     0,
     490,     0,     0,     0,   187,   188,   189,   190,   191,  2112,
       0,     0,   192,   193,   194,   195,   196,   197,     0,   198,
     105,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   199,   200,     0,     0,     0,   201,
       0,     0,     0,     0,   352,     0,   130,   380,     0,   205,
       0,  1820,   133,   134,   135,     0,     0,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
       0,     0,   476,   477,   478,   479,   480,   481,   482,   483,
     484,   485,   486,   487,   488,   489,   168,   169,   170,   171,
     490,     0,     0,     0,   176,     0,     0,     0,     0,  2114,
       0,     0,     0,     0,     0,   181,   182,   183,     0,     0,
       0,     0,     0,   184,   476,   477,   478,   479,   480,   481,
     482,   483,   484,   485,   486,   487,   488,   489,     0,     0,
       0,     0,   490,     0,     0,     0,     0,     0,     0,     0,
       0,  2116,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   130,   263,     0,     0,     0,     0,   133,
     134,   135,     0,     0,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   264,   265,   266,
     267,   268,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   168,   169,   170,   171,     0,     0,     0,
       0,   176,     0,     0,     0,     0,     0,   187,     0,     0,
       0,   191,   181,   182,   183,   192,   193,   194,   195,   196,
     184,     0,     0,   105,   269,     0,     0,   270,     0,     0,
     271,     0,   272,     0,     0,     0,     0,   617,   618,    36,
       0,     0,   201,     0,     0,     0,     0,   619,     0,     0,
     273,     0,   205,   274,   314,     0,   275,     0,     0,     0,
       0,     0,     0,     0,    58,    59,    60,    61,    62,     0,
       0,    64,    65,    66,    67,    68,     0,     0,    71,     0,
       0,    74,   476,   477,   478,   479,   480,   481,   482,   483,
     484,   485,   486,   487,   488,   489,     0,     0,     0,     0,
     490,     0,     0,     0,     0,     0,     0,     0,     0,  2135,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   187,     0,     0,     0,   191,     0,
       0,     0,   192,   193,   194,   195,   196,     0,     0,     0,
     105,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   199,   512,     0,     0,     0,   201,
     130,   380,   132,     0,   352,     0,   133,   134,   135,   205,
       0,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,     0,     0,     0,     0,     0,     0,
       0,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,     0,
       0,     0,   177,   178,   179,     0,     0,   180,     0,   181,
     182,   183,     0,   130,   380,     0,     0,   184,   185,   133,
     134,   135,     0,     0,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,     0,     0,   476,
     477,   478,   479,   480,   481,   482,   483,   484,   485,   486,
     487,   488,   489,   168,   169,   170,   171,   490,     0,     0,
       0,   176,     0,     0,     0,     0,  2166,     0,     0,     0,
       0,     0,   181,   182,   183,     0,     0,     0,     0,     0,
     184,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,     0,     0,     0,     0,   490,
       0,     0,     0,     0,     0,     0,     0,     0,  2205,     0,
       0,   187,   188,   189,   190,   191,     0,     0,     0,   192,
     193,   194,   195,   196,   197,     0,   198,   105,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   199,   200,     0,     0,     0,   201,     0,     0,     0,
       0,   352,     0,     0,     0,     0,   205,     0,   476,   477,
     478,   479,   480,   481,   482,   483,   484,   485,   486,   487,
     488,   489,     0,     0,     0,     0,   490,     0,     0,     0,
       0,     0,     0,     0,   187,  2206,     0,     0,   191,     0,
       0,     0,   192,   193,   194,   195,   196,     0,     0,     0,
     105,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   199,   200,     0,     0,     0,   201,
     130,   380,     0,     0,   352,   461,   133,   134,   135,   205,
       0,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,     0,     0,   476,   477,   478,   479,
     480,   481,   482,   483,   484,   485,   486,   487,   488,   489,
     168,   169,   170,   171,   490,     0,     0,     0,   176,     0,
       0,     0,     0,  2207,     0,     0,     0,   130,   380,   181,
     182,   183,     0,   133,   134,   135,     0,   184,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,     0,     0,   476,   477,   478,   479,   480,   481,   482,
     483,   484,   485,   486,   487,   488,   489,   168,   169,   170,
     171,   490,     0,     0,     0,   176,     0,     0,     0,     0,
    2208,     0,     0,     0,     0,     0,   181,   182,   183,     0,
       0,     0,     0,     0,   184,   476,   477,   478,   479,   480,
     481,   482,   483,   484,   485,   486,   487,   488,   489,     0,
       0,     0,     0,   490,     0,     0,     0,     0,     0,     0,
       0,     0,  2209,     0,     0,     0,     0,     0,     0,     0,
       0,   187,     0,     0,     0,   191,     0,     0,     0,   192,
     193,   194,   195,   196,     0,     0,     0,   105,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   199,   200,     0,     0,     0,   201,     0,     0,     0,
       0,   352,     0,     0,   463,     0,   205,   476,   477,   478,
     479,   480,   481,   482,   483,   484,   485,   486,   487,   488,
     489,     0,     0,     0,     0,   490,     0,     0,   187,     0,
       0,     0,   191,     0,  2210,     0,   192,   193,   194,   195,
     196,     0,     0,     0,   105,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   199,   200,
       0,     0,     0,   201,   130,   380,     0,     0,   352,   682,
     133,   134,   135,   205,     0,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,     0,     0,
     476,   477,   478,   479,   480,   481,   482,   483,   484,   485,
     486,   487,   488,   489,   168,   169,   170,   171,   490,     0,
       0,     0,   176,     0,     0,     0,   909,     0,     0,     0,
       0,     0,     0,   181,   182,   183,   130,   380,     0,  1256,
       0,   184,   133,   134,   135,     0,     0,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
       0,     0,   476,   477,   478,   479,   480,   481,   482,   483,
     484,   485,   486,   487,   488,   489,   168,   169,   170,   171,
     490,     0,     0,     0,   176,     0,     0,     0,  1867,     0,
       0,     0,     0,     0,     0,   181,   182,   183,     0,     0,
       0,     0,     0,   184,   476,   477,   478,   479,   480,   481,
     482,   483,   484,   485,   486,   487,   488,   489,     0,     0,
       0,     0,   490,     0,   842,     0,   843,     0,     0,  1497,
       0,     0,     0,     0,     0,   187,     0,     0,     0,   191,
       0,     0,     0,   192,   193,   194,   195,   196,     0,     0,
       0,   105,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   199,   200,     0,     0,     0,
     201,     0,     0,     0,     0,   352,     0,     0,   684,     0,
     205,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,     0,     0,     0,     0,   490,
       0,   958,     0,     0,     0,     0,   916,   187,     0,     0,
       0,   191,     0,     0,     0,   192,   193,   194,   195,   196,
       0,     0,     0,   105,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   199,   200,     0,
       0,     0,   201,   130,   380,     0,  1424,   352,     0,   133,
     134,   135,   205,     0,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,     0,     0,   476,
     477,   478,   479,   480,   481,   482,   483,   484,   485,   486,
     487,   488,   489,   168,   169,   170,   171,   490,     0,     0,
       0,   176,     0,     0,   799,     0,     0,     0,     0,     0,
     130,   380,   181,   182,   183,     0,   133,   134,   135,     0,
     184,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,     0,     0,   476,   477,   478,   479,
     480,   481,   482,   483,   484,   485,   486,   487,   488,   489,
     168,   169,   170,   171,   490,     0,     0,     0,   176,     0,
       0,   916,     0,     0,     0,     0,     0,     0,     0,   181,
     182,   183,     0,     0,     0,     0,     0,   184,   476,   477,
     478,   479,   480,   481,   482,   483,   484,   485,   486,   487,
     488,   489,     0,     0,     0,     0,   490,     0,     0,     0,
       0,     0,     0,   917,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   187,     0,     0,     0,   191,     0,
       0,     0,   192,   193,   194,   195,   196,     0,     0,     0,
     105,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   199,   200,     0,     0,     0,   201,
       0,     0,     0,     0,   352,     7,     8,     0,     0,   205,
       0,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,     0,     0,     0,     0,   490,
       0,   187,     0,     0,     0,   191,   963,     0,     0,   192,
     193,   194,   195,   196,     0,     0,     0,   105,     7,     8,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   199,   200,     0,     0,     0,   201,     0,     0,     0,
       0,   352,     0,     0,     0,     0,   205,   762,    24,    25,
     763,    27,    28,   764,    30,   765,    32,    33,    34,    35,
       7,     8,     0,    37,    38,    39,     0,    40,     0,     0,
       0,     0,    45,   766,    47,    48,   767,     0,    51,    52,
      53,     0,     0,     0,     0,    56,     0,     0,     0,     0,
     762,    24,    25,   763,    27,    28,   764,    30,   765,    32,
      33,    34,    35,     0,     0,     0,    37,    38,    39,     0,
      40,     0,     0,     0,     0,    45,   766,    47,    48,   767,
       0,    51,    52,    53,    82,    83,    84,     0,    56,     0,
       0,     0,   762,    24,    25,   763,    27,    28,   764,    30,
     765,    32,    33,    34,    35,     7,     8,     0,    37,    38,
      39,     0,    40,     0,     0,     0,     0,    45,   766,    47,
      48,   767,     0,    51,    52,    53,     0,    82,    83,    84,
      56,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,     0,     0,     7,     8,   490,
       0,     0,     0,     0,     0,  1195,  1008,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    82,
      83,    84,     0,     0,     0,     0,     0,   762,    24,    25,
     763,    27,    28,   764,    30,   765,    32,    33,    34,    35,
       7,     8,     0,    37,    38,    39,     0,    40,  1220,     0,
       0,     0,    45,   766,    47,    48,   767,     0,    51,    52,
      53,     0,     0,     0,     0,    56,     0,     0,     0,   762,
      24,    25,   763,    27,    28,   764,    30,   765,    32,    33,
      34,    35,     7,     8,     0,    37,    38,    39,     0,    40,
    1248,     0,     0,     0,    45,   766,    47,    48,   767,     0,
      51,    52,    53,     0,    82,    83,    84,    56,     0,     0,
       0,     0,   762,    24,    25,   763,    27,    28,   764,    30,
     765,    32,    33,    34,    35,     0,     0,     0,    37,    38,
      39,     0,    40,     0,     0,     0,     0,    45,   766,    47,
      48,   767,     0,    51,    52,    53,    82,    83,    84,     0,
      56,     0,     0,     0,   762,    24,    25,   763,    27,    28,
     764,    30,   765,    32,    33,    34,    35,     7,     8,     0,
      37,    38,    39,     0,    40,  1254,     0,     0,     0,    45,
     766,    47,    48,   767,     0,    51,    52,    53,     0,    82,
      83,    84,    56,   476,   477,   478,   479,   480,   481,   482,
     483,   484,   485,   486,   487,   488,   489,     0,     0,     0,
       0,   490,     0,     0,     0,     0,     0,  1413,  1016,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    82,    83,    84,     0,     0,     0,     0,     0,   762,
      24,    25,   763,    27,    28,   764,    30,   765,    32,    33,
      34,    35,     0,     0,     0,    37,    38,    39,     0,    40,
    1634,     0,     0,     0,    45,   766,    47,    48,   767,     0,
      51,    52,    53,     0,     0,     0,     0,    56,     0,     0,
       0,     0,     0,     0,    -4,     1,     0,     0,    -4,     0,
       0,     0,     0,     0,     0,     0,    -4,    -4,     0,     0,
       0,     0,  2031,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    82,    83,    84,     0,
       0,     0,     0,     0,     0,     0,    -4,    -4,     0,     0,
       0,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,     0,    -4,    -4,    -4,   490,
       0,     0,    -4,    -4,     0,    -4,  1017,     0,     0,    -4,
      -4,     0,    -4,    -4,     0,     0,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,     0,     0,    -4,    -4,    -4,    -4,  2120,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,     0,     0,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,     0,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,     0,
       0,    -4,    -4,    -4,     0,     0,     0,     0,     0,    -4,
       6,     0,     0,     0,    -4,    -4,    -4,    -4,     7,     8,
      -4,     0,    -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,     0,
       0,     0,     0,    -4,    -4,    -4,     0,     0,     9,    10,
       0,     0,    -4,     0,    -4,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    11,    12,
      13,     0,     0,     0,    14,    15,     0,    16,     0,     0,
       0,    17,    18,     0,    19,    20,     0,     0,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,     0,     0,    36,    37,    38,    39,     0,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,     0,     0,    55,    56,    57,
      58,    59,    60,    61,    62,    63,     0,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
       0,     0,     0,    77,    78,    79,     0,     0,     0,     0,
       0,    80,     0,     0,     0,     0,    81,    82,    83,    84,
       0,     0,    85,     0,    86,     0,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
       0,     0,     0,     0,     0,   101,   102,   103,     0,     0,
       0,     0,     0,     0,   104,     0,   105,   476,   477,   478,
     479,   480,   481,   482,   483,   484,   485,   486,   487,   488,
     489,     0,     0,     0,     0,   490,     0,     0,     0,     0,
       0,     0,  1018,   476,   477,   478,   479,   480,   481,   482,
     483,   484,   485,   486,   487,   488,   489,     0,     0,     0,
       0,   490,     0,     0,     0,     0,     0,     0,  1033,   476,
     477,   478,   479,   480,   481,   482,   483,   484,   485,   486,
     487,   488,   489,     0,     0,     0,     0,   490,     0,     0,
       0,     0,     0,     0,  1148,   476,   477,   478,   479,   480,
     481,   482,   483,   484,   485,   486,   487,   488,   489,     0,
       0,     0,     0,   490,     0,     0,     0,     0,     0,     0,
    1149,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,     0,     0,     0,     0,   490,
       0,     0,     0,     0,     0,     0,  1151,   476,   477,   478,
     479,   480,   481,   482,   483,   484,   485,   486,   487,   488,
     489,     0,     0,     0,     0,   490,     0,     0,     0,     0,
       0,     0,  1203,   476,   477,   478,   479,   480,   481,   482,
     483,   484,   485,   486,   487,   488,   489,     0,     0,     0,
       0,   490,     0,     0,     0,     0,     0,     0,  1204,   476,
     477,   478,   479,   480,   481,   482,   483,   484,   485,   486,
     487,   488,   489,     0,     0,     0,     0,   490,     0,     0,
       0,     0,     0,     0,  1205,   476,   477,   478,   479,   480,
     481,   482,   483,   484,   485,   486,   487,   488,   489,     0,
       0,     0,     0,   490,     0,     0,     0,     0,     0,     0,
    1242,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,     0,     0,     0,     0,   490,
       0,     0,     0,     0,     0,     0,  1340,   476,   477,   478,
     479,   480,   481,   482,   483,   484,   485,   486,   487,   488,
     489,     0,     0,     0,     0,   490,     0,     0,     0,     0,
       0,     0,  1415,   476,   477,   478,   479,   480,   481,   482,
     483,   484,   485,   486,   487,   488,   489,     0,     0,     0,
       0,   490,     0,     0,     0,     0,     0,     0,  1416,   476,
     477,   478,   479,   480,   481,   482,   483,   484,   485,   486,
     487,   488,   489,     0,     0,     0,     0,   490,     0,     0,
       0,     0,     0,     0,  1465,   476,   477,   478,   479,   480,
     481,   482,   483,   484,   485,   486,   487,   488,   489,     0,
       0,     0,     0,   490,     0,     0,     0,     0,     0,     0,
    1585,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,     0,     0,     0,     0,   490,
       0,     0,     0,     0,     0,     0,  1586,   476,   477,   478,
     479,   480,   481,   482,   483,   484,   485,   486,   487,   488,
     489,     0,     0,     0,     0,   490,     0,     0,     0,     0,
       0,     0,  1587,   476,   477,   478,   479,   480,   481,   482,
     483,   484,   485,   486,   487,   488,   489,     0,     0,     0,
       0,   490,     0,     0,     0,     0,     0,     0,  1588,   476,
     477,   478,   479,   480,   481,   482,   483,   484,   485,   486,
     487,   488,   489,     0,     0,     0,     0,   490,     0,     0,
       0,     0,     0,     0,  1589,   476,   477,   478,   479,   480,
     481,   482,   483,   484,   485,   486,   487,   488,   489,     0,
       0,     0,     0,   490,     0,     0,     0,     0,     0,     0,
    1590,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,     0,     0,     0,     0,   490,
       0,     0,     0,     0,     0,     0,  1591,   476,   477,   478,
     479,   480,   481,   482,   483,   484,   485,   486,   487,   488,
     489,     0,     0,     0,     0,   490,     0,     0,     0,     0,
       0,     0,  1704,   476,   477,   478,   479,   480,   481,   482,
     483,   484,   485,   486,   487,   488,   489,     0,     0,     0,
       0,   490,     0,     0,     0,     0,     0,     0,  1705,   476,
     477,   478,   479,   480,   481,   482,   483,   484,   485,   486,
     487,   488,   489,     0,     0,     0,     0,   490,     0,     0,
       0,     0,     0,     0,  1712,   476,   477,   478,   479,   480,
     481,   482,   483,   484,   485,   486,   487,   488,   489,     0,
       0,     0,     0,   490,     0,     0,     0,     0,     0,     0,
    1857,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,     0,     0,     0,     0,   490,
       0,     0,     0,     0,     0,     0,  1858,   476,   477,   478,
     479,   480,   481,   482,   483,   484,   485,   486,   487,   488,
     489,     0,     0,     0,     0,   490,     0,     0,     0,     0,
       0,     0,  1859,   476,   477,   478,   479,   480,   481,   482,
     483,   484,   485,   486,   487,   488,   489,     0,     0,     0,
       0,   490,     0,     0,     0,     0,     0,     0,  1860,   476,
     477,   478,   479,   480,   481,   482,   483,   484,   485,   486,
     487,   488,   489,     0,     0,     0,     0,   490,     0,     0,
       0,     0,     0,     0,  1861,   476,   477,   478,   479,   480,
     481,   482,   483,   484,   485,   486,   487,   488,   489,     0,
       0,     0,     0,   490,     0,     0,     0,     0,     0,     0,
    1920,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,     0,     0,     0,     0,   490,
       0,     0,     0,     0,     0,     0,  1921,   476,   477,   478,
     479,   480,   481,   482,   483,   484,   485,   486,   487,   488,
     489,     0,     0,     0,     0,   490,     0,     0,     0,     0,
       0,     0,  1925,   476,   477,   478,   479,   480,   481,   482,
     483,   484,   485,   486,   487,   488,   489,     0,     0,     0,
       0,   490,     0,     0,     0,     0,     0,     0,  2001,   476,
     477,   478,   479,   480,   481,   482,   483,   484,   485,   486,
     487,   488,   489,     0,     0,     0,     0,   490,     0,     0,
       0,     0,     0,     0,  2002,   476,   477,   478,   479,   480,
     481,   482,   483,   484,   485,   486,   487,   488,   489,     0,
       0,     0,     0,   490,     0,     0,     0,     0,     0,     0,
    2003,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,     0,     0,     0,     0,   490,
       0,     0,     0,     0,     0,     0,  2004,   476,   477,   478,
     479,   480,   481,   482,   483,   484,   485,   486,   487,   488,
     489,     0,     0,     0,     0,   490,     0,     0,     0,     0,
       0,     0,  2005,   476,   477,   478,   479,   480,   481,   482,
     483,   484,   485,   486,   487,   488,   489,     0,     0,     0,
       0,   490,     0,     0,     0,     0,     0,     0,  2049,   476,
     477,   478,   479,   480,   481,   482,   483,   484,   485,   486,
     487,   488,   489,     0,     0,     0,     0,   490,     0,     0,
       0,     0,     0,     0,  2052,   476,   477,   478,   479,   480,
     481,   482,   483,   484,   485,   486,   487,   488,   489,     0,
       0,     0,     0,   490,     0,     0,     0,     0,     0,     0,
    2103,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,     0,     0,     0,     0,   490,
       0,     0,     0,     0,     0,     0,  2104,   476,   477,   478,
     479,   480,   481,   482,   483,   484,   485,   486,   487,   488,
     489,     0,     0,     0,     0,   490,     0,     0,     0,     0,
       0,     0,  2105,   476,   477,   478,   479,   480,   481,   482,
     483,   484,   485,   486,   487,   488,   489,     0,     0,     0,
       0,   490,     0,     0,     0,     0,     0,     0,  2106,   476,
     477,   478,   479,   480,   481,   482,   483,   484,   485,   486,
     487,   488,   489,     0,     0,     0,     0,   490,     0,     0,
       0,     0,     0,     0,  2107,   476,   477,   478,   479,   480,
     481,   482,   483,   484,   485,   486,   487,   488,   489,     0,
       0,     0,     0,   490,     0,     0,     0,     0,     0,     0,
    2108,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,     0,     0,     0,     0,   490,
       0,     0,     0,     0,     0,     0,  2168,   476,   477,   478,
     479,   480,   481,   482,   483,   484,   485,   486,   487,   488,
     489,     0,     0,     0,     0,   490,     0,     0,     0,     0,
       0,     0,  2169,   476,   477,   478,   479,   480,   481,   482,
     483,   484,   485,   486,   487,   488,   489,     0,     0,     0,
       0,   490,     0,     0,     0,     0,     0,     0,  2170,   476,
     477,   478,   479,   480,   481,   482,   483,   484,   485,   486,
     487,   488,   489,     0,     0,     0,     0,   490,     0,     0,
       0,     0,     0,     0,  2171,   476,   477,   478,   479,   480,
     481,   482,   483,   484,   485,   486,   487,   488,   489,     0,
       0,     0,     0,   490,     0,   842,     0,   843,   476,   477,
     478,   479,   480,   481,   482,   483,   484,   485,   486,   487,
     488,   489,     0,     0,     0,     0,   490,     0,     0,     0,
     988,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,     0,     0,     0,     0,   490,
       0,     0,     0,   995,   476,   477,   478,   479,   480,   481,
     482,   483,   484,   485,   486,   487,   488,   489,     0,     0,
       0,     0,   490,     0,     0,     0,  1093,   476,   477,   478,
     479,   480,   481,   482,   483,   484,   485,   486,   487,   488,
     489,     0,     0,     0,     0,   490,     0,     0,     0,  1141,
     476,   477,   478,   479,   480,   481,   482,   483,   484,   485,
     486,   487,   488,   489,     0,     0,     0,     0,   490,     0,
       0,     0,  1166,   476,   477,   478,   479,   480,   481,   482,
     483,   484,   485,   486,   487,   488,   489,     0,     0,     0,
       0,   490,     0,     0,     0,  1235,   476,   477,   478,   479,
     480,   481,   482,   483,   484,   485,   486,   487,   488,   489,
       0,     0,     0,     0,   490,     0,     0,     0,  1236,   476,
     477,   478,   479,   480,   481,   482,   483,   484,   485,   486,
     487,   488,   489,     0,     0,     0,     0,   490,     0,     0,
       0,  1240,   476,   477,   478,   479,   480,   481,   482,   483,
     484,   485,   486,   487,   488,   489,     0,     0,     0,     0,
     490,     0,     0,     0,  1241,   476,   477,   478,   479,   480,
     481,   482,   483,   484,   485,   486,   487,   488,   489,     0,
       0,     0,     0,   490,     0,     0,     0,  1274,   476,   477,
     478,   479,   480,   481,   482,   483,   484,   485,   486,   487,
     488,   489,     0,     0,     0,     0,   490,     0,     0,     0,
    1333,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,     0,     0,     0,     0,   490,
       0,     0,     0,  1338,   476,   477,   478,   479,   480,   481,
     482,   483,   484,   485,   486,   487,   488,   489,     0,     0,
       0,     0,   490,     0,     0,     0,  1651,   476,   477,   478,
     479,   480,   481,   482,   483,   484,   485,   486,   487,   488,
     489,     0,     0,     0,     0,   490,     0,     0,     0,  1694,
     476,   477,   478,   479,   480,   481,   482,   483,   484,   485,
     486,   487,   488,   489,     0,     0,     0,     0,   490,     0,
       0,     0,  1881,   476,   477,   478,   479,   480,   481,   482,
     483,   484,   485,   486,   487,   488,   489,     0,     0,     0,
       0,   490,     0,   750,   476,   477,   478,   479,   480,   481,
     482,   483,   484,   485,   486,   487,   488,   489,     0,     0,
       0,     0,   490,     0,   809,   476,   477,   478,   479,   480,
     481,   482,   483,   484,   485,   486,   487,   488,   489,     0,
       0,     0,     0,   490,     0,   813,   476,   477,   478,   479,
     480,   481,   482,   483,   484,   485,   486,   487,   488,   489,
       0,     0,     0,     0,   490,     0,   814,   476,   477,   478,
     479,   480,   481,   482,   483,   484,   485,   486,   487,   488,
     489,     0,     0,     0,     0,   490,     0,   816,   476,   477,
     478,   479,   480,   481,   482,   483,   484,   485,   486,   487,
     488,   489,     0,     0,     0,     0,   490,     0,   818,   476,
     477,   478,   479,   480,   481,   482,   483,   484,   485,   486,
     487,   488,   489,     0,     0,     0,     0,   490,     0,   819,
     476,   477,   478,   479,   480,   481,   482,   483,   484,   485,
     486,   487,   488,   489,     0,     0,     0,     0,   490,     0,
     822,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,     0,     0,     0,     0,   490,
       0,   823,   476,   477,   478,   479,   480,   481,   482,   483,
     484,   485,   486,   487,   488,   489,     0,     0,     0,     0,
     490,     0,   824,   476,   477,   478,   479,   480,   481,   482,
     483,   484,   485,   486,   487,   488,   489,     0,     0,     0,
       0,   490,     0,   825,   476,   477,   478,   479,   480,   481,
     482,   483,   484,   485,   486,   487,   488,   489,     0,     0,
       0,     0,   490,     0,   826,   476,   477,   478,   479,   480,
     481,   482,   483,   484,   485,   486,   487,   488,   489,     0,
       0,     0,     0,   490,     0,   827,   476,   477,   478,   479,
     480,   481,   482,   483,   484,   485,   486,   487,   488,   489,
       0,     0,     0,     0,   490,     0,   829,   476,   477,   478,
     479,   480,   481,   482,   483,   484,   485,   486,   487,   488,
     489,     0,     0,     0,     0,   490,     0,   830,   476,   477,
     478,   479,   480,   481,   482,   483,   484,   485,   486,   487,
     488,   489,     0,     0,     0,     0,   490,     0,   870,   476,
     477,   478,   479,   480,   481,   482,   483,   484,   485,   486,
     487,   488,   489,     0,     0,     0,     0,   490,     0,   880,
     476,   477,   478,   479,   480,   481,   482,   483,   484,   485,
     486,   487,   488,   489,     0,     0,     0,     0,   490,     0,
     958,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,     0,     0,     0,     0,   490,
       0,   959,   476,   477,   478,   479,   480,   481,   482,   483,
     484,   485,   486,   487,   488,   489,     0,     0,     0,     0,
     490,     0,   960,   476,   477,   478,   479,   480,   481,   482,
     483,   484,   485,   486,   487,   488,   489,     0,     0,     0,
       0,   490,     0,   961,   476,   477,   478,   479,   480,   481,
     482,   483,   484,   485,   486,   487,   488,   489,     0,     0,
       0,     0,   490,     0,   967,   476,   477,   478,   479,   480,
     481,   482,   483,   484,   485,   486,   487,   488,   489,     0,
       0,     0,     0,   490,     0,   968,   476,   477,   478,   479,
     480,   481,   482,   483,   484,   485,   486,   487,   488,   489,
       0,     0,     0,     0,   490,     0,   975,   476,   477,   478,
     479,   480,   481,   482,   483,   484,   485,   486,   487,   488,
     489,     0,     0,     0,     0,   490,     0,   984,   476,   477,
     478,   479,   480,   481,   482,   483,   484,   485,   486,   487,
     488,   489,     0,     0,     0,     0,   490,     0,   994,   476,
     477,   478,   479,   480,   481,   482,   483,   484,   485,   486,
     487,   488,   489,     0,     0,     0,     0,   490,     0,  1092,
     476,   477,   478,   479,   480,   481,   482,   483,   484,   485,
     486,   487,   488,   489,     0,     0,     0,     0,   490,     0,
    1120,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,     0,     0,     0,     0,   490,
       0,  1125,   476,   477,   478,   479,   480,   481,   482,   483,
     484,   485,   486,   487,   488,   489,     0,     0,     0,     0,
     490,     0,  1136,   476,   477,   478,   479,   480,   481,   482,
     483,   484,   485,   486,   487,   488,   489,     0,     0,     0,
       0,   490,     0,  1140,   476,   477,   478,   479,   480,   481,
     482,   483,   484,   485,   486,   487,   488,   489,     0,     0,
       0,     0,   490,     0,  1165,   476,   477,   478,   479,   480,
     481,   482,   483,   484,   485,   486,   487,   488,   489,     0,
       0,     0,     0,   490,     0,  1169,   476,   477,   478,   479,
     480,   481,   482,   483,   484,   485,   486,   487,   488,   489,
       0,     0,     0,     0,   490,     0,  1170,   476,   477,   478,
     479,   480,   481,   482,   483,   484,   485,   486,   487,   488,
     489,     0,     0,     0,     0,   490,     0,  1171,   476,   477,
     478,   479,   480,   481,   482,   483,   484,   485,   486,   487,
     488,   489,     0,     0,     0,     0,   490,     0,  1177,   476,
     477,   478,   479,   480,   481,   482,   483,   484,   485,   486,
     487,   488,   489,     0,     0,     0,     0,   490,     0,  1186,
     476,   477,   478,   479,   480,   481,   482,   483,   484,   485,
     486,   487,   488,   489,     0,     0,     0,     0,   490,     0,
    1187,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,     0,     0,     0,     0,   490,
       0,  1188,   476,   477,   478,   479,   480,   481,   482,   483,
     484,   485,   486,   487,   488,   489,     0,     0,     0,     0,
     490,     0,  1222,   476,   477,   478,   479,   480,   481,   482,
     483,   484,   485,   486,   487,   488,   489,     0,     0,     0,
       0,   490,     0,  1224,   476,   477,   478,   479,   480,   481,
     482,   483,   484,   485,   486,   487,   488,   489,     0,     0,
       0,     0,   490,     0,  1225,   476,   477,   478,   479,   480,
     481,   482,   483,   484,   485,   486,   487,   488,   489,     0,
       0,     0,     0,   490,     0,  1226,   476,   477,   478,   479,
     480,   481,   482,   483,   484,   485,   486,   487,   488,   489,
       0,     0,     0,     0,   490,     0,  1227,   476,   477,   478,
     479,   480,   481,   482,   483,   484,   485,   486,   487,   488,
     489,     0,     0,     0,     0,   490,     0,  1228,   476,   477,
     478,   479,   480,   481,   482,   483,   484,   485,   486,   487,
     488,   489,     0,     0,     0,     0,   490,     0,  1229,   476,
     477,   478,   479,   480,   481,   482,   483,   484,   485,   486,
     487,   488,   489,     0,     0,     0,     0,   490,     0,  1230,
     476,   477,   478,   479,   480,   481,   482,   483,   484,   485,
     486,   487,   488,   489,     0,     0,     0,     0,   490,     0,
    1234,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,     0,     0,     0,     0,   490,
       0,  1332,   476,   477,   478,   479,   480,   481,   482,   483,
     484,   485,   486,   487,   488,   489,     0,     0,     0,     0,
     490,     0,  1337,   476,   477,   478,   479,   480,   481,   482,
     483,   484,   485,   486,   487,   488,   489,     0,     0,     0,
       0,   490,     0,  1509,   476,   477,   478,   479,   480,   481,
     482,   483,   484,   485,   486,   487,   488,   489,     0,     0,
       0,     0,   490,     0,  1534,   476,   477,   478,   479,   480,
     481,   482,   483,   484,   485,   486,   487,   488,   489,     0,
       0,     0,     0,   490,     0,  1700,   476,   477,   478,   479,
     480,   481,   482,   483,   484,   485,   486,   487,   488,   489,
       0,     0,     0,     0,   490,     0,  1757,   476,   477,   478,
     479,   480,   481,   482,   483,   484,   485,   486,   487,   488,
     489,     0,     0,     0,     0,   490,     0,  1775,   476,   477,
     478,   479,   480,   481,   482,   483,   484,   485,   486,   487,
     488,   489,     0,     0,     0,     0,   490,     0,  1799,   476,
     477,   478,   479,   480,   481,   482,   483,   484,   485,   486,
     487,   488,   489,     0,     0,     0,     0,   490,     0,  2048,
     476,   477,   478,   479,   480,   481,   482,   483,   484,   485,
     486,   487,   488,   489,     0,     0,     0,     0,   490,     0,
    2133,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,     0,     0,     0,     0,   490
};

static const yytype_int16 yycheck[] =
{
       3,     3,  1221,     6,     4,   322,   307,   611,   612,  1640,
     428,     4,   430,     4,  1662,  1663,     5,     7,     6,     6,
       4,   338,     4,     4,     4,     4,     4,   445,     4,     6,
       4,     6,     5,     4,     4,     4,     4,    90,     5,     5,
       5,     5,     5,    46,     6,     5,     5,   119,    90,     6,
       6,     6,     6,     5,     4,  1844,     6,   110,     6,   166,
     377,     7,   379,     6,   136,     6,    90,     0,   385,    72,
    1216,    13,   144,   145,   146,   182,   183,    80,   150,   151,
     152,   153,    85,   224,     6,   224,   110,   226,   119,   214,
     215,   224,     6,    96,   233,   224,   224,   226,  1729,   214,
     215,    59,    60,   231,    62,   136,     6,   232,    96,   224,
      98,     8,   119,   144,   145,   146,   231,   214,   215,   150,
     151,   152,   153,   119,   214,   215,   214,   215,     7,   136,
     129,   214,   215,   230,    84,   232,     6,   144,   145,   146,
     136,   231,   230,   150,   151,   152,   153,   230,   144,   145,
     146,     7,   214,   215,   150,   151,   152,   153,   214,   215,
     232,   221,   222,   156,   157,   158,   159,   225,   230,   227,
     232,   231,   230,     7,   230,   224,   232,   177,   214,   215,
     169,     7,   231,    84,   221,   222,    87,   166,   167,    90,
     224,    92,   166,   167,   231,   231,   169,   231,   154,     6,
     200,   232,   205,   169,   206,   181,   154,     7,  1839,  1998,
    1999,   154,     7,   154,   217,   218,   224,   169,   200,     7,
     200,    87,   225,   231,    90,   232,    92,   214,   215,     6,
     233,   231,   235,  1864,   211,   226,   211,   240,   228,   232,
     224,   244,   233,   224,   232,   226,   224,   228,   251,   231,
       6,   254,   233,   231,   224,   258,   259,   260,   261,   262,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   224,
     273,   231,   231,   276,   231,   278,   231,   231,   224,     7,
     226,     3,   226,     7,     6,   602,   603,   224,   291,   292,
     293,   294,   214,   215,     7,  1441,     6,   300,   301,   302,
     214,   215,    87,   306,   307,    90,   623,    92,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   201,   202,   203,   204,   223,   221,   222,   332,
     333,   334,   235,   214,   215,   232,    90,   240,    92,   214,
     215,   244,   659,   346,   347,   201,   202,   203,   204,   230,
      72,   224,   310,   311,   228,   258,   231,   674,   231,   233,
     318,   221,   222,    85,   322,   221,   222,   201,   202,   203,
     204,   231,   228,     6,    96,   201,   202,   203,   204,   226,
     383,   221,   222,    84,   387,   388,    87,   221,   222,    90,
     461,   231,   463,    84,   465,  2043,    87,   400,     4,    90,
     224,   201,   202,   203,   204,   393,   201,   202,   203,   204,
     217,   218,   224,   201,   202,   203,   204,   216,   217,   218,
    2051,   221,   222,   224,   223,   428,   429,   430,   431,   432,
     433,   434,   435,   436,   437,   438,   439,   440,   224,   442,
     443,   444,   445,   446,   251,   214,   215,   450,   451,   452,
     453,   454,   455,   224,   457,   262,   214,   215,     4,    84,
     448,   230,    87,   214,   215,    90,   465,    92,   456,   214,
     215,   474,   230,   201,   202,   203,   204,   201,   202,   203,
     204,   221,   222,   205,   230,   230,   232,   227,   201,   202,
     203,   204,   224,   221,   222,   217,   218,   221,   222,   214,
     215,    87,    87,   225,    90,    90,   214,   215,   224,   512,
     226,   233,   228,   214,   215,   230,   103,   233,   124,   125,
     126,   127,   230,   224,   224,   214,   215,   221,   222,   251,
     231,   227,   138,  2164,   230,   141,   224,   231,    84,   224,
     262,   230,    88,   546,   547,   214,   215,   550,    94,    95,
     225,    97,    98,   214,   215,   230,   119,   225,   561,   214,
     215,   230,   230,   566,   214,   215,   112,   221,   222,   230,
     573,   474,     8,   136,   225,   230,   383,   231,   224,   230,
     230,   144,   145,   146,   224,   307,   226,   150,   151,   152,
     153,   214,   215,   596,   597,   912,   214,   215,   586,   587,
     588,   589,   214,   215,   214,   215,   230,   230,   232,   611,
     612,   682,   230,   684,   225,   259,   260,   261,   230,   230,
     230,   230,   429,   232,   431,   432,   433,   434,   435,   436,
     437,   227,   439,   440,   230,   442,   443,   444,    90,   446,
     643,   644,   645,   450,   451,   452,   453,   454,   292,   293,
     294,   609,   610,   224,   214,   215,  1875,   225,  1877,   617,
    1879,   383,   230,   566,   667,   214,   215,   124,   125,   232,
     230,   214,   215,   130,   214,   215,   214,   215,   230,   750,
     232,   230,   224,   754,   687,   214,   215,   230,   332,   333,
     230,   224,   230,   596,   597,   694,   214,   215,   216,   217,
     218,   230,   346,   347,    90,   223,   428,   429,   430,   431,
     432,   433,   434,   435,   436,   437,     6,   439,   440,   231,
     442,   443,   444,   445,   446,     8,   224,   119,   450,   451,
     452,   453,   454,   455,   225,   457,   224,   224,   226,   230,
     643,   644,   645,   550,   136,   233,   749,   214,   215,    90,
     753,   750,   144,   145,   146,   754,   124,   125,   150,   151,
     152,   153,   130,   230,   667,     6,     7,   755,  1069,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   224,   687,   226,    92,   223,   214,   215,
     224,   794,   233,   214,   215,   798,   232,   225,   801,   214,
     215,   804,   230,   806,   230,   119,    87,   810,   811,   230,
     230,  1957,   232,  2032,  1960,   230,    90,  1963,   214,   215,
     808,   225,   136,   227,   224,   547,   226,   231,   550,   231,
     144,   145,   146,   233,   230,    87,   150,   151,   152,   153,
     232,   844,   841,   846,     6,     7,   849,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   224,   862,
     226,   864,   223,   866,   224,   868,   226,   233,   228,   231,
     873,   231,   224,   233,   226,   878,   228,    87,  1296,  1297,
     224,   233,   885,  1301,  1302,    90,   221,   222,   230,     4,
     232,   794,  2111,   228,  2113,   798,  2115,   225,   225,   227,
     227,  1218,  2121,   231,     4,   225,   909,   227,     4,   225,
     230,   227,   224,   984,   230,     4,   224,   988,   232,   230,
     224,   232,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   224,   230,  2084,   232,
     223,   844,   225,   846,     6,   225,   849,   227,     6,   225,
     230,   227,   224,   230,   230,   232,  2175,   915,  2177,   862,
    2179,   864,   226,   866,   922,   868,   225,   230,   227,   232,
     873,   230,   930,   226,   224,   878,   979,   225,   224,   227,
     983,   230,   230,   232,   987,   984,   230,   224,   232,   988,
     224,   230,   995,   232,   801,   994,   995,   226,  2144,   806,
     230,  2147,   232,   230,  2150,   232,   909,  2153,   224,    90,
    1311,    92,  1616,  1617,    90,     7,    92,  1020,   230,   230,
     232,   232,  1025,   230,   230,   232,   232,  1030,  1031,  1032,
    1033,   210,   211,   212,   213,   214,   215,   216,   217,   218,
    1043,   230,  1045,   232,   223,   230,   224,   232,  2194,   230,
    2196,   232,  2198,   230,   230,   232,   232,   224,   224,  1477,
    1478,   230,     6,   232,  1482,  1483,  1069,   231,   231,  1072,
    1073,  1074,  1075,   230,   230,   232,   232,   224,     6,   801,
     231,   230,   804,   232,   806,   230,   230,   232,   232,   230,
     230,   232,   232,  1092,  1093,     4,  1099,     6,   230,   230,
     232,   232,   230,   230,   232,   232,   230,  1178,   232,  1180,
     230,  1182,   232,  1184,   224,  1118,  1119,  1020,  1121,     6,
    1123,  1124,   224,   224,  1127,  1128,  1129,  1130,  1131,  1132,
    1133,  1134,   231,   224,     6,  1138,     4,     5,   230,   110,
     232,  1140,  1141,   230,   230,   232,   232,   230,   230,   232,
     232,   230,   230,   232,   232,  1472,  1114,  1474,   230,  1162,
     232,   230,   230,   232,   232,  1168,  1165,  1166,   231,  1072,
    1073,  1074,  1075,   230,   224,   232,    44,    45,    46,    47,
      48,    49,    50,    51,    52,   230,   224,   232,   995,    57,
      58,    59,    60,   230,   230,   232,   232,    65,    66,    67,
     224,   230,    70,   232,   230,   230,   232,   232,   230,   230,
     232,   232,   230,    81,   232,   230,   224,   232,  1025,   230,
     230,   232,   232,   224,  1031,  1032,  1033,  1528,     8,   224,
     224,   231,     4,  1304,   231,  1138,  1043,   119,  1045,   224,
    1243,  1244,  1245,   231,   231,  1203,  1204,  1205,   231,   231,
     224,  1322,     6,   226,   136,   224,  1259,   224,   224,   224,
     224,   224,   144,   145,   146,   233,  1870,     6,   150,   151,
     152,   153,     6,   995,   231,   231,   231,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   226,  1099,  1296,  1297,   223,   226,   226,  1301,  1302,
       6,     6,     6,  1025,   231,  1304,   169,   233,  1311,  1031,
    1032,  1033,     6,     6,   231,     6,     6,   185,   186,   187,
     231,  1043,     6,  1045,  1327,   231,   226,     4,   223,   197,
     228,   199,   200,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,  1069,  1351,     7,
     232,   223,   231,  1341,  1357,   232,   230,   225,   225,   227,
     230,     7,     6,     6,     6,   225,  1369,     4,     7,     7,
      62,     6,     6,    62,    62,    62,     6,  1099,   225,     6,
     231,   119,     7,     6,   166,     7,     6,     6,  1391,  1392,
    1393,     6,   231,   227,  1397,  1398,   225,  1400,   136,  1402,
       6,  1404,  1820,  1406,  1407,  1408,   144,   145,   146,     6,
     225,   225,   150,   151,   152,   153,  1487,   230,   230,   230,
     230,   230,   230,  1426,   230,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,  1442,
     225,   225,   225,   223,    44,    44,   227,  1450,    44,  1452,
      44,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,     6,     4,   224,     4,   223,
       7,     6,     6,     6,  1477,  1478,     6,   225,     7,  1482,
    1483,     7,  1440,  1471,   169,     7,   169,     7,     7,   169,
    1489,     7,     7,  1496,   232,     7,     7,     7,     7,  1502,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,     7,     7,   231,     6,   223,   227,
     231,   231,   231,     7,   231,  1528,     7,     4,     6,  1830,
     225,   119,  1520,  1536,   230,   232,   119,     6,     6,   225,
       7,     6,    44,  1546,   225,     7,  1549,     7,   136,  1452,
     225,   230,   230,     7,   230,   228,   144,   145,   146,   228,
     232,  1549,   150,   151,   152,   153,   119,   231,   231,  1886,
     232,    44,    44,    44,  1296,  1297,     6,   119,     6,  1301,
    1302,     6,  1581,   136,     6,     6,     4,     5,     7,  1311,
     226,   144,   145,   146,   136,     6,   224,   150,   151,   152,
     153,  1559,   144,   145,   146,  1608,  1609,   224,   150,   151,
     152,   153,   224,   231,  1616,  1617,     6,    92,   211,     7,
       7,  1624,     7,     7,  1612,     7,    44,    45,    46,    47,
      48,    49,    50,    51,    52,     7,     7,  1640,     6,    57,
      58,    59,    60,  1646,   232,     7,     6,    65,    66,    67,
       7,  1654,    70,     7,     7,     7,     7,     4,    87,     4,
    1618,  1664,  1620,    81,  1622,   231,  1983,     6,   224,     7,
       6,  1674,  1660,     7,     7,     7,  1679,     7,     7,   232,
       7,     7,   231,  1641,  1642,  1643,  1644,  1645,  1646,  1496,
     232,  1679,  1680,  1681,     6,  1502,   119,     6,     6,    90,
       6,     4,     7,  1706,     6,  1608,  1609,     6,     4,     4,
     231,     4,   230,   136,   231,     6,  2033,     6,   232,     6,
       6,   144,   145,   146,     6,     6,  1729,   150,   151,   152,
     153,   230,   230,   228,   225,   225,     7,   224,     6,  1546,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,     6,  1477,  1478,   231,   223,     6,
    1482,  1483,   228,   227,   225,     6,   112,   185,   186,   187,
       6,  1774,     6,   231,  1496,   231,   231,     6,   231,   197,
    1502,   199,   200,     6,  1787,   231,     6,     6,     6,     6,
       6,     6,     6,     6,     5,     4,   227,  1800,   225,     6,
       6,     6,     4,   221,   222,     6,  1528,   231,   119,   232,
     228,   231,     7,   231,  1817,  1803,   231,  1820,   231,   231,
     226,     6,     6,     6,  1546,   136,     6,  1830,   231,   231,
     231,   231,   231,   144,   145,   146,  1839,   231,   231,   150,
     151,   152,   153,  1846,  1847,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   119,
       6,  1864,     6,   223,  1867,   165,     6,   230,  1870,     7,
       8,     6,     4,     6,   230,     6,     6,     4,     6,     4,
       6,  1884,     6,     6,     6,     6,  1889,     7,     7,     6,
       6,     6,     5,   169,     6,     6,   231,  1800,     6,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,     6,     6,     6,  1874,   223,  1876,     6,
    1878,   232,     6,     6,     6,     6,     6,     6,   120,     6,
       6,     6,  1890,  1891,  1892,  1893,  1894,     6,     6,     6,
     230,     6,   225,  1946,     6,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,     6,
       6,     6,  1965,   223,  1867,  1968,     6,   228,     7,     6,
       6,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,  1988,  1889,  1945,   231,   223,
       6,  1949,   231,   231,     5,   232,     6,     6,    88,  1987,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,     6,   164,     7,    90,   223,   231,
       6,   231,     6,     6,   232,     6,     6,   231,   231,     6,
       6,   231,  2035,  2036,  2037,  2038,  2039,     6,   232,   232,
     231,     6,   232,   232,     6,     6,     6,     6,  2051,   167,
    2008,     6,     6,   231,  2012,     6,   231,     6,   225,   231,
       6,   231,     7,     6,     6,   231,     6,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,  2039,     6,   231,   231,   223,     6,   232,   119,   231,
       6,     6,     6,     6,    12,    13,     6,     6,  1820,     6,
       6,     6,     6,   232,     6,     6,  2094,     6,  1830,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,  2126,   224,   232,   231,   223,   231,  2132,
     231,   227,  2035,  2036,  2037,  2038,  2039,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,  2109,  2110,     8,   232,   223,     6,   231,     6,   225,
       6,  2164,     6,     6,   104,     6,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,  2182,
       6,  2184,   100,   101,   102,     6,   104,     6,     6,   231,
       6,   109,   110,   111,   112,   113,   231,   115,   116,   117,
       6,   231,   231,   231,   122,     6,     6,     6,     6,     6,
       6,  2214,     6,     6,     6,     6,     6,     6,  1336,  1991,
     508,  1350,     3,  2126,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,  1845,     3,
       3,     3,   223,   161,   162,   163,  1866,   584,    -1,  1524,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   199,
     200,   201,   202,   203,    -1,    -1,  1988,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   216,    -1,    -1,    -1,
     220,    -1,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   234,   235,   236,   237,   223,   239,
     240,   241,   242,    -1,   244,   245,   246,   247,   248,   249,
     250,     6,   252,   253,   232,    -1,    -1,    -1,   258,    -1,
      -1,    -1,    -1,    -1,    -1,  2132,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   276,   277,   278,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   288,    -1,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   304,    -1,    -1,    -1,   223,    -1,
      -1,    -1,    -1,   313,   314,  2182,    -1,  2184,    -1,    -1,
      -1,    -1,   322,    -1,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,    -1,    -1,
      -1,    -1,   223,    -1,    -1,    -1,    -1,  2214,    -1,    -1,
    2132,    -1,   352,    -1,    -1,    -1,   356,   357,   358,    -1,
     360,    -1,    -1,    -1,   364,   365,   366,    -1,    -1,   369,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   384,    -1,    -1,    -1,   223,   389,
     390,    -1,    -1,    -1,    -1,   230,    -1,   232,    -1,    -1,
    2182,    -1,  2184,   403,   404,    -1,   406,   407,   408,   409,
     410,   411,   412,   413,   414,   415,   416,   417,   418,   419,
     420,   421,   422,   423,   424,   425,   426,   427,    -1,    -1,
      -1,    -1,  2214,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   441,    -1,    -1,    -1,    -1,    -1,   447,    -1,   449,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,    -1,    -1,    -1,    -1,   223,    -1,
      -1,    -1,    -1,   473,   474,    -1,   476,   477,   478,   479,
     480,   481,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   235,    -1,   493,   494,    -1,   240,    -1,    -1,    -1,
     244,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   512,    -1,   258,    -1,    -1,    -1,   518,    -1,
      -1,    -1,    -1,   523,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   276,     6,   278,   535,   536,    -1,    -1,    -1,
      -1,    -1,   542,   543,    -1,    -1,   546,   547,   548,   549,
      -1,   551,    -1,    -1,   554,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   566,    -1,    -1,    -1,
      -1,    -1,   572,   573,   574,   575,     6,    -1,   578,   579,
     580,    -1,    -1,    -1,    -1,   585,   586,   587,   588,   589,
     590,    -1,   592,    -1,   594,    -1,   596,   597,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   614,   615,   616,   617,   618,   619,
      -1,    12,    13,    -1,   624,   625,   626,   627,   628,   629,
     630,   631,   632,    -1,    -1,    -1,   636,    -1,   638,   639,
      -1,    -1,    -1,   643,   644,   645,    -1,    -1,   648,   649,
     650,    -1,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,    -1,   667,    -1,    -1,
     223,    -1,   672,   673,    -1,   675,   676,   230,    -1,   232,
      -1,    -1,    -1,    -1,    -1,    -1,   686,   687,     8,    -1,
      -1,   691,    -1,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    -1,    -1,    -1,   100,
     101,   102,    -1,   104,    -1,    -1,    -1,    -1,   109,   110,
     111,   112,   113,    -1,   115,   116,   117,    -1,     6,    -1,
     474,   122,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,    -1,     6,    -1,    -1,
     223,    -1,    -1,    -1,    -1,    -1,   756,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   512,    -1,
     161,   162,   163,    -1,    -1,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,    -1,
     790,   791,    -1,   223,   794,   795,   796,     8,   798,   799,
      -1,    -1,   546,   547,    -1,    -1,    -1,   807,    -1,    -1,
     810,   811,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   566,    -1,    -1,    -1,    -1,    -1,    -1,   573,
      -1,   831,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   232,    -1,    -1,   844,    -1,   846,    -1,    -1,   849,
      -1,    -1,   596,   597,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   862,    -1,   864,    -1,   866,    -1,   868,    -1,
      -1,    -1,    -1,   873,    -1,    -1,    -1,    -1,   878,    -1,
      -1,    -1,    -1,    -1,   884,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   643,
     644,   645,    -1,   223,    -1,    -1,    -1,    -1,    -1,   909,
      -1,    -1,    -1,    -1,    -1,    -1,   916,   917,    -1,    -1,
      -1,    -1,   922,   667,    -1,    -1,    -1,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   941,    -1,   687,   944,   223,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
      -1,    -1,    -1,   963,   223,   965,   966,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   976,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     6,    -1,    -1,
      -1,    -1,    -1,    46,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,  1008,    12,
      13,    -1,   223,    -1,    -1,    -1,  1016,  1017,  1018,    -1,
    1020,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1028,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1042,    -1,    -1,    -1,    -1,  1047,    -1,    -1,
     794,    -1,    -1,    -1,   798,    -1,  1056,    -1,    -1,    -1,
      -1,    -1,  1062,    -1,    -1,    -1,   810,   811,    -1,    -1,
      -1,    -1,  1072,  1073,  1074,  1075,  1076,    -1,    -1,    -1,
    1080,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    -1,    -1,    -1,   100,   101,   102,
     844,   104,   846,    -1,    -1,   849,   109,   110,   111,   112,
     113,    -1,   115,   116,   117,    -1,    -1,    -1,   862,   122,
     864,    -1,   866,    -1,   868,    -1,    -1,    -1,    -1,   873,
      -1,    -1,    -1,    -1,   878,    -1,    -1,    -1,  1138,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1148,  1149,
      -1,  1151,  1152,    -1,  1154,  1155,  1156,    -1,   161,   162,
     163,    -1,    -1,  1163,     7,   909,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1179,
      -1,  1181,    -1,  1183,    -1,  1185,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
      -1,   254,     8,    -1,   223,    -1,    -1,    -1,  1208,    -1,
      12,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     273,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   232,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   291,    -1,
      -1,    -1,  1242,    -1,    -1,    -1,    -1,   300,   301,   302,
      -1,    -1,    -1,   306,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1265,    -1,    -1,    -1,    -1,
    1270,    -1,    -1,    -1,    -1,    -1,  1020,    -1,    -1,    -1,
      -1,   334,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    -1,    -1,    -1,   100,   101,
     102,    -1,   104,    -1,    -1,    -1,    -1,   109,   110,   111,
     112,   113,  1312,   115,   116,   117,    -1,    -1,    -1,    -1,
     122,  1321,    -1,    -1,    -1,  1325,  1326,    -1,  1072,  1073,
    1074,  1075,    -1,    -1,   387,   388,    -1,    -1,    -1,    -1,
    1340,  1341,    -1,    -1,    -1,    -1,     8,   400,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   161,
     162,   163,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,    -1,    -1,    -1,    -1,
     223,    -1,    -1,    -1,    -1,   438,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1138,    -1,    -1,    -1,    -1,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,    -1,  1414,  1415,  1416,   223,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1426,    -1,  1428,    -1,
     232,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1440,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1452,    -1,    -1,    -1,    -1,  1457,    -1,    -1,
      -1,    -1,     3,     4,    -1,  1465,  1466,  1467,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    -1,  1497,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   561,    -1,
      -1,    -1,    53,    54,    55,    56,    -1,    -1,    -1,    -1,
      61,  1521,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    72,    73,    74,    -1,    -1,    -1,  1537,    -1,    80,
      -1,    -1,  1542,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,  1557,  1558,    -1,
      -1,   223,    -1,    -1,  1564,  1565,    -1,    -1,    -1,  1569,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1585,  1586,  1587,  1588,  1589,
    1590,  1591,    -1,    -1,    -1,    -1,    -1,    -1,  1598,    -1,
      -1,    -1,    -1,    21,    22,    -1,    -1,    -1,  1608,  1609,
    1610,    -1,  1612,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1625,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
      -1,    -1,    -1,   184,   223,    -1,  1646,   188,   227,  1649,
      -1,   192,   193,   194,   195,   196,    -1,    -1,    -1,   200,
    1660,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   214,   215,    -1,    -1,    -1,   219,    -1,
    1680,    -1,    -1,   224,    -1,    -1,    -1,    -1,   229,    -1,
     231,    -1,    -1,    -1,    -1,    -1,   749,    -1,    -1,    -1,
     753,    -1,    -1,    -1,  1704,  1705,    -1,    -1,  1452,    -1,
     128,    -1,  1712,    -1,    -1,    -1,    -1,    -1,    -1,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,    -1,    -1,    -1,   165,   166,   167,
     168,    -1,   170,   171,   172,   173,   174,   175,  1758,    -1,
     178,    -1,    -1,    -1,    -1,    -1,   184,   185,    -1,    -1,
      -1,    -1,   190,   191,    -1,    -1,    -1,    -1,  1778,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1787,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1795,    -1,  1797,    -1,    -1,
    1800,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,    -1,    -1,  1817,    -1,   223,
      -1,    -1,    -1,    -1,    -1,    -1,   230,    -1,   232,    -1,
      -1,    -1,   885,    -1,    -1,  1835,    -1,    -1,    -1,    -1,
    1840,    -1,    -1,    -1,    -1,   263,    -1,   265,   266,   267,
     268,    -1,    -1,    -1,    -1,    -1,    -1,  1857,  1858,  1859,
    1860,  1861,    -1,    -1,  1608,  1609,    -1,  1867,   286,    -1,
      -1,    -1,    -1,    -1,  1874,    -1,  1876,    -1,  1878,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1889,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1897,    -1,    -1,
      -1,    -1,  1646,     4,     5,    -1,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
    1920,  1921,    -1,    -1,   223,  1925,   979,    -1,    -1,    -1,
     983,   230,    -1,   232,   987,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1942,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    -1,  1953,    -1,    -1,    57,    58,    59,    60,
      -1,    -1,    -1,    -1,    65,    66,    67,    -1,    -1,    70,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1030,    -1,    -1,
      81,    -1,    -1,    -1,    -1,  1985,    -1,    -1,    -1,    -1,
      -1,  1991,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2000,  2001,  2002,  2003,  2004,  2005,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2019,
      -1,    -1,  2022,    -1,    -1,  2025,    -1,    -1,    -1,  2029,
      -1,    -1,    -1,    -1,    -1,  2035,  2036,  2037,  2038,  2039,
      -1,    -1,    -1,  1787,    -1,    -1,    -1,    -1,    -1,  2049,
     468,    -1,  2052,    -1,    -1,    -1,  1800,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1118,  1119,    -1,  1121,    -1,
    1123,  1124,    -1,  1817,  1127,  1128,  1129,  1130,  1131,  1132,
    1133,  1134,    -1,    -1,   185,   186,   187,     4,     5,    -1,
      -1,    -1,    -1,    -1,   576,    -1,   197,    -1,   199,   200,
      -1,    -1,    -1,  2103,  2104,  2105,  2106,  2107,  2108,  1162,
      -1,    -1,    -1,    -1,    -1,  1168,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1867,    -1,    -1,  2126,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    -1,    -1,    -1,    -1,
      57,    58,    59,    60,    -1,  1889,    -1,    -1,    65,    66,
      67,    -1,    -1,    70,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    81,    -1,    -1,    -1,  2168,  2169,
    2170,  2171,  2172,  2173,    -1,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,    -1,
    1243,  1244,  1245,   223,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   232,    -1,    -1,    -1,  1259,    -1,    -1,    -1,
      -1,    -1,    -1,   695,   696,   697,   698,   699,   700,   701,
     702,   703,   704,   705,    -1,   707,   708,   709,   710,   711,
     712,   713,    -1,    -1,    -1,   717,   718,   719,    -1,    -1,
      -1,   723,   724,    -1,   726,    -1,    -1,    -1,    -1,   731,
     732,   733,    -1,   735,    -1,    -1,    -1,    -1,    -1,    -1,
     742,   743,    -1,    -1,    -1,    -1,    -1,    -1,   185,   186,
     187,    -1,    -1,    -1,  1327,    -1,    -1,    -1,   760,    -1,
     197,    -1,   199,   200,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2035,  2036,  2037,  2038,  2039,    -1,    -1,  1351,    -1,
      -1,    -1,    -1,    -1,  1357,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1369,    -1,    -1,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,    -1,    -1,    -1,    -1,   223,  1391,  1392,
    1393,    -1,    -1,    -1,  1397,  1398,   232,  1400,    -1,  1402,
      -1,  1404,    -1,  1406,  1407,  1408,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
      -1,    -1,   854,  1426,   223,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2126,   232,    -1,    -1,    -1,    -1,    -1,  1442,
      -1,    -1,     3,     4,     5,    -1,    -1,  1450,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    -1,    -1,    -1,    12,
      13,    -1,    -1,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    -1,    -1,    -1,    65,    66,    67,    -1,    -1,    70,
      -1,    72,    73,    74,    -1,    -1,    -1,    -1,    -1,    80,
      81,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1536,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1549,    -1,    -1,    -1,
      -1,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    -1,    -1,    -1,   100,   101,   102,
      -1,   104,    -1,    -1,    -1,    -1,   109,   110,   111,   112,
     113,    -1,   115,   116,   117,    -1,    -1,    -1,    -1,   122,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,    -1,    -1,    -1,    -1,   223,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   177,   232,    -1,    -1,
      -1,  1624,    -1,   184,   185,   186,   187,   188,   161,   162,
     163,   192,   193,   194,   195,   196,   197,  1640,   199,   200,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1079,    -1,    -1,
      -1,  1654,    -1,   214,   215,    -1,    -1,    -1,   219,    -1,
      -1,  1664,    -1,   224,    -1,   226,    -1,   228,   229,    -1,
     231,  1674,   233,    -1,    -1,    -1,  1679,    -1,    -1,    -1,
    1112,  1113,    -1,    -1,  1052,  1053,    -1,    -1,    -1,    -1,
    1058,  1059,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   232,
      -1,    -1,    -1,  1706,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,    -1,    -1,
      -1,    -1,   223,    -1,    -1,    -1,  1729,    -1,    -1,    -1,
      -1,   232,    -1,     3,     4,     5,    -1,    -1,    -1,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    -1,    -1,    -1,
      -1,  1774,    -1,    -1,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    -1,    -1,    -1,    65,    66,    67,    -1,    -1,
      70,    -1,    72,    73,    74,    -1,    -1,    -1,    -1,    -1,
      80,    81,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,    -1,    -1,    -1,    -1,
     223,    -1,    -1,    -1,    -1,    -1,  1839,    -1,    -1,   232,
      -1,  1273,    -1,  1846,  1847,    -1,    -1,  1279,  1280,  1281,
    1282,  1283,    -1,  1285,    -1,  1287,  1288,    -1,  1290,  1291,
      -1,  1864,  1294,  1295,  1296,    -1,    -1,    -1,    -1,  1301,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1884,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1262,  1263,    -1,    -1,    -1,  1267,
    1268,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   184,   185,   186,   187,   188,    -1,
      -1,    -1,   192,   193,   194,   195,   196,   197,    -1,   199,
     200,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1372,    -1,    -1,  1946,   214,   215,    -1,    -1,    -1,   219,
      -1,    -1,    -1,    -1,   224,    -1,    -1,  1389,    -1,   229,
      -1,   231,  1965,    -1,    -1,  1968,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
      -1,    -1,     3,     4,   223,    -1,    -1,    -1,     9,    10,
      11,    -1,   231,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    53,    54,    55,    56,    -1,    -1,    -1,    -1,
      61,    -1,    -1,    -1,    -1,  1477,    -1,    -1,  2051,    -1,
    1482,    72,    73,    74,    -1,    12,    13,    -1,    -1,    80,
      -1,    -1,    -1,    84,    -1,    -1,    87,    -1,    -1,    90,
      -1,    92,    -1,    -1,    -1,    -1,    -1,    -1,    99,    -1,
      -1,    -1,  1514,  1515,    -1,    -1,  1518,  1519,    -1,   110,
      -1,    -1,   113,    -1,    -1,   116,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   124,   125,   126,   127,   128,    -1,    -1,
     131,   132,   133,   134,   135,    -1,    -1,   138,    -1,    -1,
     141,    -1,    -1,    -1,    -1,    -1,    -1,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      -1,    -1,    -1,   100,   101,   102,    -1,   104,    -1,    -1,
      -1,    -1,   109,   110,   111,   112,   113,    -1,   115,   116,
     117,  2164,    -1,   184,    -1,   122,    -1,   188,    -1,    -1,
      -1,   192,   193,   194,   195,   196,    -1,    -1,    -1,   200,
      -1,    -1,   139,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   214,   215,    -1,    -1,    -1,   219,    -1,
      -1,    -1,    -1,   224,   161,   162,   163,    -1,   229,    -1,
     231,   232,    -1,    -1,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,    -1,    -1,
      -1,    -1,   223,    -1,    -1,  1667,  1668,    -1,    -1,  1671,
    1672,   232,     3,     4,    -1,  1677,  1678,    -1,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    53,    54,    55,    56,    -1,    -1,  1730,  1731,
      61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    72,    73,    74,    -1,    12,    13,    -1,    -1,    80,
      -1,    -1,    -1,    84,    -1,    -1,    87,    -1,    -1,    90,
      -1,    92,    -1,    -1,    -1,    -1,    -1,    -1,    99,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   110,
      -1,    -1,   113,    -1,    -1,   116,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   124,   125,   126,   127,   128,    -1,    -1,
     131,   132,   133,   134,   135,    -1,    -1,   138,    -1,    -1,
     141,    -1,    -1,    -1,    -1,    -1,    -1,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      -1,    -1,    -1,   100,   101,   102,    -1,   104,    -1,    -1,
      -1,    -1,   109,   110,   111,   112,   113,    -1,   115,   116,
     117,    -1,    -1,   184,    -1,   122,    -1,   188,    -1,    -1,
      -1,   192,   193,   194,   195,   196,    -1,    -1,    -1,   200,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   214,   215,    -1,    -1,    -1,   219,    -1,
      -1,    -1,    -1,   224,   161,   162,   163,    -1,   229,    -1,
      -1,   232,     3,     4,     5,    -1,    -1,    -1,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    -1,    -1,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    -1,    -1,    -1,    65,    66,    67,    -1,    -1,    70,
      -1,    72,    73,    74,    -1,    -1,    -1,    -1,    -1,    80,
      81,    -1,    -1,    84,    -1,    -1,    87,    -1,    -1,    90,
      -1,    92,    -1,    -1,    -1,    -1,    -1,    -1,    99,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   110,
      -1,    -1,   113,    -1,    -1,   116,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   124,   125,   126,   127,   128,    -1,    -1,
     131,   132,   133,   134,   135,    -1,    -1,   138,    -1,    -1,
     141,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,    -1,    -1,    -1,    -1,   223,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   232,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   184,   185,   186,   187,   188,    -1,    -1,
      -1,   192,   193,   194,   195,   196,   197,    -1,   199,   200,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   214,   215,    -1,    -1,    -1,   219,    -1,
      -1,    -1,    -1,   224,    -1,     3,     4,     5,   229,    -1,
     231,     9,    10,    11,    -1,  2137,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    -1,    -1,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    -1,    -1,    -1,    65,    66,    67,
      -1,    -1,    70,    -1,    72,    73,    74,    -1,    -1,    -1,
      -1,    -1,    80,    81,    -1,    -1,    84,    -1,    -1,    87,
      -1,    -1,    90,    -1,    92,    -1,    -1,    -1,    -1,    -1,
      -1,    99,    -1,    -1,    -1,    -1,    -1,     4,     5,    -1,
      -1,    -1,   110,    -1,    -1,   113,    -1,    -1,   116,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   124,   125,   126,   127,
     128,    -1,    -1,   131,   132,   133,   134,   135,    -1,    -1,
     138,    -1,    -1,   141,    -1,    -1,    -1,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    -1,    -1,    -1,    -1,
      57,    58,    59,    60,    -1,    -1,    -1,    -1,    65,    66,
      67,    -1,    -1,    70,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    81,    -1,   184,   185,   186,   187,
     188,    -1,    -1,    -1,   192,   193,   194,   195,   196,   197,
      -1,   199,   200,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   214,   215,    -1,    -1,
      -1,   219,    -1,    -1,    -1,    -1,   224,    -1,     3,     4,
       5,   229,    -1,   231,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,    54,
      55,    56,    -1,    -1,    -1,    -1,    61,    -1,   185,   186,
     187,    -1,    -1,    -1,    -1,    -1,    -1,    72,    73,    74,
     197,    -1,   199,    -1,    -1,    80,    -1,    -1,    -1,    84,
      -1,    -1,    87,    -1,    -1,    90,    -1,    92,    -1,    -1,
      -1,    -1,    -1,    -1,    99,    -1,    -1,    -1,    -1,    -1,
      -1,     5,    -1,    -1,    -1,   110,    -1,    -1,   113,    -1,
      -1,   116,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   124,
     125,   126,   127,   128,    -1,    -1,   131,   132,   133,   134,
     135,    -1,    -1,   138,    -1,    -1,   141,    -1,    -1,    -1,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    -1,
      -1,    -1,    -1,    57,    58,    59,    60,    -1,    -1,    -1,
      -1,    65,    66,    67,    -1,    -1,    70,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,    -1,   184,
      -1,    -1,    -1,   188,    -1,    -1,    -1,   192,   193,   194,
     195,   196,    -1,    -1,    -1,   200,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   214,
     215,    -1,    -1,    -1,   219,    -1,    -1,    -1,    -1,   224,
      -1,     3,     4,     5,   229,    -1,   231,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    53,    54,    55,    56,    -1,    -1,    -1,    -1,    61,
      -1,   185,   186,   187,    -1,    -1,    -1,    -1,    -1,    -1,
      72,    73,    74,   197,    -1,   199,    -1,    -1,    80,    -1,
      -1,    -1,    84,    -1,    -1,    87,    -1,    -1,    90,    -1,
      92,    -1,    -1,    -1,    -1,    -1,    -1,    99,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   110,    -1,
      -1,   113,    -1,    -1,   116,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   124,   125,   126,   127,   128,    -1,    -1,   131,
     132,   133,   134,   135,    -1,    -1,   138,    -1,    -1,   141,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,    -1,    -1,    -1,    -1,   223,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   232,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   184,    -1,    -1,    -1,   188,    -1,    -1,    -1,
     192,   193,   194,   195,   196,    -1,    -1,    -1,   200,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   214,   215,    -1,    -1,    -1,   219,    -1,    -1,
      -1,    -1,   224,    -1,     3,     4,    -1,   229,    -1,   231,
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
      -1,   110,    -1,    -1,   113,    -1,    -1,   116,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   124,   125,   126,   127,   128,
      -1,    -1,   131,   132,   133,   134,   135,    -1,    -1,   138,
      -1,    -1,   141,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,    -1,    -1,    -1,
      -1,   223,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     232,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   184,    -1,    -1,    -1,   188,
      -1,    -1,    -1,   192,   193,   194,   195,   196,    -1,    -1,
      -1,   200,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   214,   215,    -1,    -1,    -1,
     219,    -1,    -1,    -1,    -1,   224,    -1,     3,     4,    -1,
     229,    -1,   231,     9,    10,    11,    -1,    -1,    14,    15,
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
      -1,    -1,   138,    -1,    -1,   141,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
      -1,    -1,    -1,    -1,   223,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   232,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   184,    -1,
      -1,    -1,   188,    -1,    -1,    -1,   192,   193,   194,   195,
     196,    -1,    -1,    -1,   200,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   214,   215,
      -1,    -1,    -1,   219,    -1,    -1,    -1,    -1,   224,    -1,
       3,     4,    -1,   229,    -1,   231,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      53,    54,    55,    56,    -1,    -1,    -1,    -1,    61,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,
      73,    74,    -1,    -1,    -1,    -1,    -1,    80,    -1,    -1,
      -1,    84,    -1,    -1,    87,    -1,    -1,    90,    -1,    92,
      -1,    -1,    -1,    -1,    -1,    -1,    99,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   110,    -1,    -1,
     113,    -1,    -1,   116,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   124,   125,   126,   127,   128,    -1,    -1,   131,   132,
     133,   134,   135,    -1,    -1,   138,    -1,    -1,   141,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,    -1,    -1,    -1,    -1,   223,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   232,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   184,    -1,    -1,    -1,   188,    -1,    -1,    -1,   192,
     193,   194,   195,   196,    -1,    -1,    -1,   200,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   214,   215,    -1,    -1,    -1,   219,    -1,    -1,    -1,
      -1,   224,    -1,     3,     4,    -1,   229,    -1,   231,     9,
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
      -1,   131,   132,   133,   134,   135,    -1,    -1,   138,    -1,
      -1,   141,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,    -1,    -1,    -1,    -1,
     223,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   232,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   184,    -1,    -1,    -1,   188,    -1,
      -1,    -1,   192,   193,   194,   195,   196,    -1,    -1,    -1,
     200,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   214,   215,    -1,    -1,    -1,   219,
      -1,    -1,    -1,    -1,   224,    -1,     3,     4,    -1,   229,
      -1,   231,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    53,    54,    55,    56,
      -1,    -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    72,    73,    74,    -1,    -1,
      -1,    -1,    -1,    80,    -1,    -1,    -1,    84,    -1,    -1,
      87,    -1,    -1,    90,    -1,    92,    -1,    -1,    -1,    -1,
      -1,    -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   110,    -1,    -1,   113,    -1,    -1,   116,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   124,   125,   126,
     127,   128,    -1,    -1,   131,   132,   133,   134,   135,    -1,
      -1,   138,    -1,    -1,   141,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,    -1,
      -1,    -1,    -1,   223,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   232,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   184,    -1,    -1,
      -1,   188,    -1,    -1,    -1,   192,   193,   194,   195,   196,
      -1,    -1,    -1,   200,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   214,   215,    -1,
      -1,    -1,   219,    -1,    -1,    -1,    -1,   224,    -1,     3,
       4,    -1,   229,    -1,   231,     9,    10,    11,    -1,    -1,
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
     134,   135,    -1,    -1,   138,    -1,    -1,   141,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,    -1,    -1,    -1,    -1,   223,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   232,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     184,    -1,    -1,    -1,   188,    -1,    -1,    -1,   192,   193,
     194,   195,   196,    -1,    -1,    -1,   200,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     214,   215,    -1,    -1,    -1,   219,    -1,    -1,    -1,    -1,
     224,    -1,     3,     4,    -1,   229,    -1,   231,     9,    10,
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
      -1,    -1,   113,    -1,    -1,   116,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   124,   125,   126,   127,   128,    -1,    -1,
     131,   132,   133,   134,   135,    -1,    -1,   138,    -1,    -1,
     141,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,    -1,    -1,    -1,    -1,   223,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   232,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   184,    -1,    -1,    -1,   188,    -1,    -1,
      -1,   192,   193,   194,   195,   196,    -1,    -1,    -1,   200,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   214,   215,    -1,    -1,    -1,   219,    -1,
      -1,    -1,    -1,   224,    -1,     3,     4,    -1,   229,    -1,
     231,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
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
     138,    -1,    -1,   141,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,    -1,    -1,
      -1,    -1,   223,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   232,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   184,    -1,    -1,    -1,
     188,    -1,    -1,    -1,   192,   193,   194,   195,   196,    -1,
      -1,    -1,   200,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   214,   215,    -1,    -1,
      -1,   219,    -1,    -1,    -1,    -1,   224,    -1,     3,     4,
      -1,   229,    -1,   231,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,    54,
      55,    56,    -1,    -1,    -1,    -1,    61,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,    73,    74,
      -1,    -1,    -1,    -1,    -1,    80,    -1,    -1,    -1,    84,
      -1,    -1,    87,    -1,    -1,    90,    -1,    92,    -1,    -1,
      -1,    -1,    -1,    -1,    99,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   110,    -1,    -1,   113,    -1,
      -1,   116,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   124,
     125,   126,   127,   128,    -1,    -1,   131,   132,   133,   134,
     135,    -1,    -1,   138,    -1,    -1,   141,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,    -1,    -1,    -1,    -1,   223,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   232,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   184,
      -1,    -1,    -1,   188,    -1,    -1,    -1,   192,   193,   194,
     195,   196,    -1,    -1,    -1,   200,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   214,
     215,    -1,    -1,    -1,   219,    -1,    -1,    -1,    -1,   224,
      -1,     3,     4,    -1,   229,    -1,   231,     9,    10,    11,
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
     132,   133,   134,   135,    -1,    -1,   138,    -1,    -1,   141,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,    -1,    -1,    -1,    -1,   223,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   232,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   184,    -1,    -1,    -1,   188,    -1,    -1,    -1,
     192,   193,   194,   195,   196,    -1,    -1,    -1,   200,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   214,   215,    -1,    -1,    -1,   219,    -1,    -1,
      -1,    -1,   224,    -1,     3,     4,    -1,   229,    -1,   231,
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
      -1,   110,    -1,    -1,   113,    -1,    -1,   116,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   124,   125,   126,   127,   128,
      -1,    -1,   131,   132,   133,   134,   135,    -1,    -1,   138,
      -1,    -1,   141,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,    -1,    -1,    -1,
      -1,   223,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     232,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   184,    -1,    -1,    -1,   188,
      -1,    -1,    -1,   192,   193,   194,   195,   196,    -1,    -1,
      -1,   200,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   214,   215,    -1,    -1,    -1,
     219,    -1,    -1,    -1,    -1,   224,    -1,     3,     4,    -1,
     229,    -1,   231,     9,    10,    11,    -1,    -1,    14,    15,
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
      -1,    -1,   138,    -1,    -1,   141,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
      -1,    -1,    -1,    -1,   223,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   232,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   184,    -1,
      -1,    -1,   188,    -1,    -1,    -1,   192,   193,   194,   195,
     196,    -1,    -1,    -1,   200,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   214,   215,
      -1,    -1,    -1,   219,    -1,    -1,    -1,    -1,   224,    -1,
       3,     4,     5,   229,    -1,   231,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    -1,
      -1,    -1,    65,    66,    67,    -1,    -1,    70,    -1,    72,
      73,    74,    -1,     3,     4,     5,    -1,    80,    81,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    -1,    -1,    -1,    65,    66,    67,    -1,    -1,
      70,    -1,    72,    73,    74,    -1,    -1,    -1,    -1,    -1,
      80,    81,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,    -1,    -1,    -1,    -1,
     223,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   232,
      -1,   184,   185,   186,   187,   188,    -1,    -1,    -1,   192,
     193,   194,   195,   196,   197,    -1,   199,   200,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   214,   215,    -1,    -1,    -1,   219,    -1,    -1,    -1,
      -1,   224,    -1,    -1,    -1,    -1,   229,    -1,   231,    -1,
      -1,    -1,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,    -1,    -1,    -1,    -1,
     223,    -1,    -1,    -1,   184,   185,   186,   187,   188,   232,
      -1,    -1,   192,   193,   194,   195,   196,   197,    -1,   199,
     200,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   214,   215,    -1,    -1,    -1,   219,
      -1,    -1,    -1,    -1,   224,    -1,     3,     4,    -1,   229,
      -1,   231,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      -1,    -1,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,    53,    54,    55,    56,
     223,    -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,   232,
      -1,    -1,    -1,    -1,    -1,    72,    73,    74,    -1,    -1,
      -1,    -1,    -1,    80,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,    -1,    -1,
      -1,    -1,   223,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   232,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     3,     4,    -1,    -1,    -1,    -1,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    53,    54,    55,    56,    -1,    -1,    -1,
      -1,    61,    -1,    -1,    -1,    -1,    -1,   184,    -1,    -1,
      -1,   188,    72,    73,    74,   192,   193,   194,   195,   196,
      80,    -1,    -1,   200,    84,    -1,    -1,    87,    -1,    -1,
      90,    -1,    92,    -1,    -1,    -1,    -1,   214,   215,    99,
      -1,    -1,   219,    -1,    -1,    -1,    -1,   224,    -1,    -1,
     110,    -1,   229,   113,   231,    -1,   116,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   124,   125,   126,   127,   128,    -1,
      -1,   131,   132,   133,   134,   135,    -1,    -1,   138,    -1,
      -1,   141,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,    -1,    -1,    -1,    -1,
     223,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   232,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   184,    -1,    -1,    -1,   188,    -1,
      -1,    -1,   192,   193,   194,   195,   196,    -1,    -1,    -1,
     200,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   214,   215,    -1,    -1,    -1,   219,
       3,     4,     5,    -1,   224,    -1,     9,    10,    11,   229,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    -1,
      -1,    -1,    65,    66,    67,    -1,    -1,    70,    -1,    72,
      73,    74,    -1,     3,     4,    -1,    -1,    80,    81,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    -1,    -1,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,    53,    54,    55,    56,   223,    -1,    -1,
      -1,    61,    -1,    -1,    -1,    -1,   232,    -1,    -1,    -1,
      -1,    -1,    72,    73,    74,    -1,    -1,    -1,    -1,    -1,
      80,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,    -1,    -1,    -1,    -1,   223,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   232,    -1,
      -1,   184,   185,   186,   187,   188,    -1,    -1,    -1,   192,
     193,   194,   195,   196,   197,    -1,   199,   200,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   214,   215,    -1,    -1,    -1,   219,    -1,    -1,    -1,
      -1,   224,    -1,    -1,    -1,    -1,   229,    -1,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,    -1,    -1,    -1,    -1,   223,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   184,   232,    -1,    -1,   188,    -1,
      -1,    -1,   192,   193,   194,   195,   196,    -1,    -1,    -1,
     200,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   214,   215,    -1,    -1,    -1,   219,
       3,     4,    -1,    -1,   224,   225,     9,    10,    11,   229,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
      53,    54,    55,    56,   223,    -1,    -1,    -1,    61,    -1,
      -1,    -1,    -1,   232,    -1,    -1,    -1,     3,     4,    72,
      73,    74,    -1,     9,    10,    11,    -1,    80,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    -1,    -1,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,    53,    54,    55,
      56,   223,    -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,
     232,    -1,    -1,    -1,    -1,    -1,    72,    73,    74,    -1,
      -1,    -1,    -1,    -1,    80,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,    -1,
      -1,    -1,    -1,   223,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   232,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   184,    -1,    -1,    -1,   188,    -1,    -1,    -1,   192,
     193,   194,   195,   196,    -1,    -1,    -1,   200,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   214,   215,    -1,    -1,    -1,   219,    -1,    -1,    -1,
      -1,   224,    -1,    -1,   227,    -1,   229,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,    -1,    -1,    -1,    -1,   223,    -1,    -1,   184,    -1,
      -1,    -1,   188,    -1,   232,    -1,   192,   193,   194,   195,
     196,    -1,    -1,    -1,   200,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   214,   215,
      -1,    -1,    -1,   219,     3,     4,    -1,    -1,   224,   225,
       9,    10,    11,   229,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    -1,    -1,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,    53,    54,    55,    56,   223,    -1,
      -1,    -1,    61,    -1,    -1,    -1,   231,    -1,    -1,    -1,
      -1,    -1,    -1,    72,    73,    74,     3,     4,    -1,     6,
      -1,    80,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      -1,    -1,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,    53,    54,    55,    56,
     223,    -1,    -1,    -1,    61,    -1,    -1,    -1,   231,    -1,
      -1,    -1,    -1,    -1,    -1,    72,    73,    74,    -1,    -1,
      -1,    -1,    -1,    80,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,    -1,    -1,
      -1,    -1,   223,    -1,   225,    -1,   227,    -1,    -1,   230,
      -1,    -1,    -1,    -1,    -1,   184,    -1,    -1,    -1,   188,
      -1,    -1,    -1,   192,   193,   194,   195,   196,    -1,    -1,
      -1,   200,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   214,   215,    -1,    -1,    -1,
     219,    -1,    -1,    -1,    -1,   224,    -1,    -1,   227,    -1,
     229,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,    -1,    -1,    -1,    -1,   223,
      -1,   225,    -1,    -1,    -1,    -1,   230,   184,    -1,    -1,
      -1,   188,    -1,    -1,    -1,   192,   193,   194,   195,   196,
      -1,    -1,    -1,   200,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   214,   215,    -1,
      -1,    -1,   219,     3,     4,    -1,     6,   224,    -1,     9,
      10,    11,   229,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    -1,    -1,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,    53,    54,    55,    56,   223,    -1,    -1,
      -1,    61,    -1,    -1,   230,    -1,    -1,    -1,    -1,    -1,
       3,     4,    72,    73,    74,    -1,     9,    10,    11,    -1,
      80,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
      53,    54,    55,    56,   223,    -1,    -1,    -1,    61,    -1,
      -1,   230,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,
      73,    74,    -1,    -1,    -1,    -1,    -1,    80,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,    -1,    -1,    -1,    -1,   223,    -1,    -1,    -1,
      -1,    -1,    -1,   230,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   184,    -1,    -1,    -1,   188,    -1,
      -1,    -1,   192,   193,   194,   195,   196,    -1,    -1,    -1,
     200,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   214,   215,    -1,    -1,    -1,   219,
      -1,    -1,    -1,    -1,   224,    12,    13,    -1,    -1,   229,
      -1,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,    -1,    -1,    -1,    -1,   223,
      -1,   184,    -1,    -1,    -1,   188,   230,    -1,    -1,   192,
     193,   194,   195,   196,    -1,    -1,    -1,   200,    12,    13,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   214,   215,    -1,    -1,    -1,   219,    -1,    -1,    -1,
      -1,   224,    -1,    -1,    -1,    -1,   229,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      12,    13,    -1,   100,   101,   102,    -1,   104,    -1,    -1,
      -1,    -1,   109,   110,   111,   112,   113,    -1,   115,   116,
     117,    -1,    -1,    -1,    -1,   122,    -1,    -1,    -1,    -1,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    -1,    -1,    -1,   100,   101,   102,    -1,
     104,    -1,    -1,    -1,    -1,   109,   110,   111,   112,   113,
      -1,   115,   116,   117,   161,   162,   163,    -1,   122,    -1,
      -1,    -1,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    12,    13,    -1,   100,   101,
     102,    -1,   104,    -1,    -1,    -1,    -1,   109,   110,   111,
     112,   113,    -1,   115,   116,   117,    -1,   161,   162,   163,
     122,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,    -1,    -1,    12,    13,   223,
      -1,    -1,    -1,    -1,    -1,   232,   230,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   161,
     162,   163,    -1,    -1,    -1,    -1,    -1,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      12,    13,    -1,   100,   101,   102,    -1,   104,   232,    -1,
      -1,    -1,   109,   110,   111,   112,   113,    -1,   115,   116,
     117,    -1,    -1,    -1,    -1,   122,    -1,    -1,    -1,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    12,    13,    -1,   100,   101,   102,    -1,   104,
     232,    -1,    -1,    -1,   109,   110,   111,   112,   113,    -1,
     115,   116,   117,    -1,   161,   162,   163,   122,    -1,    -1,
      -1,    -1,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    -1,    -1,    -1,   100,   101,
     102,    -1,   104,    -1,    -1,    -1,    -1,   109,   110,   111,
     112,   113,    -1,   115,   116,   117,   161,   162,   163,    -1,
     122,    -1,    -1,    -1,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    12,    13,    -1,
     100,   101,   102,    -1,   104,   232,    -1,    -1,    -1,   109,
     110,   111,   112,   113,    -1,   115,   116,   117,    -1,   161,
     162,   163,   122,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,    -1,    -1,    -1,
      -1,   223,    -1,    -1,    -1,    -1,    -1,   232,   230,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   161,   162,   163,    -1,    -1,    -1,    -1,    -1,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    -1,    -1,    -1,   100,   101,   102,    -1,   104,
     232,    -1,    -1,    -1,   109,   110,   111,   112,   113,    -1,
     115,   116,   117,    -1,    -1,    -1,    -1,   122,    -1,    -1,
      -1,    -1,    -1,    -1,     0,     1,    -1,    -1,     4,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    12,    13,    -1,    -1,
      -1,    -1,   232,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   161,   162,   163,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    -1,    -1,
      -1,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,    -1,    62,    63,    64,   223,
      -1,    -1,    68,    69,    -1,    71,   230,    -1,    -1,    75,
      76,    -1,    78,    79,    -1,    -1,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    -1,    -1,    99,   100,   101,   102,   232,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,    -1,    -1,   121,   122,   123,   124,   125,
     126,   127,   128,   129,    -1,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,    -1,    -1,
      -1,   147,   148,   149,    -1,    -1,    -1,    -1,    -1,   155,
       4,    -1,    -1,    -1,   160,   161,   162,   163,    12,    13,
     166,    -1,   168,    -1,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,    -1,    -1,
      -1,    -1,    -1,   189,   190,   191,    -1,    -1,    42,    43,
      -1,    -1,   198,    -1,   200,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,    63,
      64,    -1,    -1,    -1,    68,    69,    -1,    71,    -1,    -1,
      -1,    75,    76,    -1,    78,    79,    -1,    -1,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    -1,    -1,    99,   100,   101,   102,    -1,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,    -1,    -1,   121,   122,   123,
     124,   125,   126,   127,   128,   129,    -1,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
      -1,    -1,    -1,   147,   148,   149,    -1,    -1,    -1,    -1,
      -1,   155,    -1,    -1,    -1,    -1,   160,   161,   162,   163,
      -1,    -1,   166,    -1,   168,    -1,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
      -1,    -1,    -1,    -1,    -1,   189,   190,   191,    -1,    -1,
      -1,    -1,    -1,    -1,   198,    -1,   200,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,    -1,    -1,    -1,    -1,   223,    -1,    -1,    -1,    -1,
      -1,    -1,   230,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,    -1,    -1,    -1,
      -1,   223,    -1,    -1,    -1,    -1,    -1,    -1,   230,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,    -1,    -1,    -1,    -1,   223,    -1,    -1,
      -1,    -1,    -1,    -1,   230,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,    -1,
      -1,    -1,    -1,   223,    -1,    -1,    -1,    -1,    -1,    -1,
     230,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,    -1,    -1,    -1,    -1,   223,
      -1,    -1,    -1,    -1,    -1,    -1,   230,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,    -1,    -1,    -1,    -1,   223,    -1,    -1,    -1,    -1,
      -1,    -1,   230,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,    -1,    -1,    -1,
      -1,   223,    -1,    -1,    -1,    -1,    -1,    -1,   230,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,    -1,    -1,    -1,    -1,   223,    -1,    -1,
      -1,    -1,    -1,    -1,   230,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,    -1,
      -1,    -1,    -1,   223,    -1,    -1,    -1,    -1,    -1,    -1,
     230,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,    -1,    -1,    -1,    -1,   223,
      -1,    -1,    -1,    -1,    -1,    -1,   230,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,    -1,    -1,    -1,    -1,   223,    -1,    -1,    -1,    -1,
      -1,    -1,   230,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,    -1,    -1,    -1,
      -1,   223,    -1,    -1,    -1,    -1,    -1,    -1,   230,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,    -1,    -1,    -1,    -1,   223,    -1,    -1,
      -1,    -1,    -1,    -1,   230,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,    -1,
      -1,    -1,    -1,   223,    -1,    -1,    -1,    -1,    -1,    -1,
     230,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,    -1,    -1,    -1,    -1,   223,
      -1,    -1,    -1,    -1,    -1,    -1,   230,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,    -1,    -1,    -1,    -1,   223,    -1,    -1,    -1,    -1,
      -1,    -1,   230,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,    -1,    -1,    -1,
      -1,   223,    -1,    -1,    -1,    -1,    -1,    -1,   230,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,    -1,    -1,    -1,    -1,   223,    -1,    -1,
      -1,    -1,    -1,    -1,   230,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,    -1,
      -1,    -1,    -1,   223,    -1,    -1,    -1,    -1,    -1,    -1,
     230,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,    -1,    -1,    -1,    -1,   223,
      -1,    -1,    -1,    -1,    -1,    -1,   230,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,    -1,    -1,    -1,    -1,   223,    -1,    -1,    -1,    -1,
      -1,    -1,   230,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,    -1,    -1,    -1,
      -1,   223,    -1,    -1,    -1,    -1,    -1,    -1,   230,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,    -1,    -1,    -1,    -1,   223,    -1,    -1,
      -1,    -1,    -1,    -1,   230,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,    -1,
      -1,    -1,    -1,   223,    -1,    -1,    -1,    -1,    -1,    -1,
     230,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,    -1,    -1,    -1,    -1,   223,
      -1,    -1,    -1,    -1,    -1,    -1,   230,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,    -1,    -1,    -1,    -1,   223,    -1,    -1,    -1,    -1,
      -1,    -1,   230,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,    -1,    -1,    -1,
      -1,   223,    -1,    -1,    -1,    -1,    -1,    -1,   230,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,    -1,    -1,    -1,    -1,   223,    -1,    -1,
      -1,    -1,    -1,    -1,   230,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,    -1,
      -1,    -1,    -1,   223,    -1,    -1,    -1,    -1,    -1,    -1,
     230,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,    -1,    -1,    -1,    -1,   223,
      -1,    -1,    -1,    -1,    -1,    -1,   230,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,    -1,    -1,    -1,    -1,   223,    -1,    -1,    -1,    -1,
      -1,    -1,   230,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,    -1,    -1,    -1,
      -1,   223,    -1,    -1,    -1,    -1,    -1,    -1,   230,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,    -1,    -1,    -1,    -1,   223,    -1,    -1,
      -1,    -1,    -1,    -1,   230,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,    -1,
      -1,    -1,    -1,   223,    -1,    -1,    -1,    -1,    -1,    -1,
     230,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,    -1,    -1,    -1,    -1,   223,
      -1,    -1,    -1,    -1,    -1,    -1,   230,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,    -1,    -1,    -1,    -1,   223,    -1,    -1,    -1,    -1,
      -1,    -1,   230,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,    -1,    -1,    -1,
      -1,   223,    -1,    -1,    -1,    -1,    -1,    -1,   230,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,    -1,    -1,    -1,    -1,   223,    -1,    -1,
      -1,    -1,    -1,    -1,   230,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,    -1,
      -1,    -1,    -1,   223,    -1,    -1,    -1,    -1,    -1,    -1,
     230,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,    -1,    -1,    -1,    -1,   223,
      -1,    -1,    -1,    -1,    -1,    -1,   230,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,    -1,    -1,    -1,    -1,   223,    -1,    -1,    -1,    -1,
      -1,    -1,   230,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,    -1,    -1,    -1,
      -1,   223,    -1,    -1,    -1,    -1,    -1,    -1,   230,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,    -1,    -1,    -1,    -1,   223,    -1,    -1,
      -1,    -1,    -1,    -1,   230,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,    -1,
      -1,    -1,    -1,   223,    -1,    -1,    -1,    -1,    -1,    -1,
     230,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,    -1,    -1,    -1,    -1,   223,
      -1,    -1,    -1,    -1,    -1,    -1,   230,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,    -1,    -1,    -1,    -1,   223,    -1,    -1,    -1,    -1,
      -1,    -1,   230,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,    -1,    -1,    -1,
      -1,   223,    -1,    -1,    -1,    -1,    -1,    -1,   230,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,    -1,    -1,    -1,    -1,   223,    -1,    -1,
      -1,    -1,    -1,    -1,   230,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,    -1,
      -1,    -1,    -1,   223,    -1,   225,    -1,   227,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,    -1,    -1,    -1,    -1,   223,    -1,    -1,    -1,
     227,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,    -1,    -1,    -1,    -1,   223,
      -1,    -1,    -1,   227,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,    -1,    -1,
      -1,    -1,   223,    -1,    -1,    -1,   227,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,    -1,    -1,    -1,    -1,   223,    -1,    -1,    -1,   227,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,    -1,    -1,    -1,    -1,   223,    -1,
      -1,    -1,   227,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,    -1,    -1,    -1,
      -1,   223,    -1,    -1,    -1,   227,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
      -1,    -1,    -1,    -1,   223,    -1,    -1,    -1,   227,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,    -1,    -1,    -1,    -1,   223,    -1,    -1,
      -1,   227,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,    -1,    -1,    -1,    -1,
     223,    -1,    -1,    -1,   227,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,    -1,
      -1,    -1,    -1,   223,    -1,    -1,    -1,   227,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,    -1,    -1,    -1,    -1,   223,    -1,    -1,    -1,
     227,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,    -1,    -1,    -1,    -1,   223,
      -1,    -1,    -1,   227,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,    -1,    -1,
      -1,    -1,   223,    -1,    -1,    -1,   227,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,    -1,    -1,    -1,    -1,   223,    -1,    -1,    -1,   227,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,    -1,    -1,    -1,    -1,   223,    -1,
      -1,    -1,   227,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,    -1,    -1,    -1,
      -1,   223,    -1,   225,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,    -1,    -1,
      -1,    -1,   223,    -1,   225,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,    -1,
      -1,    -1,    -1,   223,    -1,   225,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
      -1,    -1,    -1,    -1,   223,    -1,   225,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,    -1,    -1,    -1,    -1,   223,    -1,   225,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,    -1,    -1,    -1,    -1,   223,    -1,   225,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,    -1,    -1,    -1,    -1,   223,    -1,   225,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,    -1,    -1,    -1,    -1,   223,    -1,
     225,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,    -1,    -1,    -1,    -1,   223,
      -1,   225,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,    -1,    -1,    -1,    -1,
     223,    -1,   225,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,    -1,    -1,    -1,
      -1,   223,    -1,   225,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,    -1,    -1,
      -1,    -1,   223,    -1,   225,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,    -1,
      -1,    -1,    -1,   223,    -1,   225,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
      -1,    -1,    -1,    -1,   223,    -1,   225,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,    -1,    -1,    -1,    -1,   223,    -1,   225,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,    -1,    -1,    -1,    -1,   223,    -1,   225,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,    -1,    -1,    -1,    -1,   223,    -1,   225,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,    -1,    -1,    -1,    -1,   223,    -1,
     225,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,    -1,    -1,    -1,    -1,   223,
      -1,   225,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,    -1,    -1,    -1,    -1,
     223,    -1,   225,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,    -1,    -1,    -1,
      -1,   223,    -1,   225,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,    -1,    -1,
      -1,    -1,   223,    -1,   225,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,    -1,
      -1,    -1,    -1,   223,    -1,   225,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
      -1,    -1,    -1,    -1,   223,    -1,   225,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,    -1,    -1,    -1,    -1,   223,    -1,   225,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,    -1,    -1,    -1,    -1,   223,    -1,   225,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,    -1,    -1,    -1,    -1,   223,    -1,   225,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,    -1,    -1,    -1,    -1,   223,    -1,
     225,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,    -1,    -1,    -1,    -1,   223,
      -1,   225,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,    -1,    -1,    -1,    -1,
     223,    -1,   225,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,    -1,    -1,    -1,
      -1,   223,    -1,   225,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,    -1,    -1,
      -1,    -1,   223,    -1,   225,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,    -1,
      -1,    -1,    -1,   223,    -1,   225,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
      -1,    -1,    -1,    -1,   223,    -1,   225,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,    -1,    -1,    -1,    -1,   223,    -1,   225,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,    -1,    -1,    -1,    -1,   223,    -1,   225,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,    -1,    -1,    -1,    -1,   223,    -1,   225,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,    -1,    -1,    -1,    -1,   223,    -1,
     225,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,    -1,    -1,    -1,    -1,   223,
      -1,   225,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,    -1,    -1,    -1,    -1,
     223,    -1,   225,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,    -1,    -1,    -1,
      -1,   223,    -1,   225,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,    -1,    -1,
      -1,    -1,   223,    -1,   225,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,    -1,
      -1,    -1,    -1,   223,    -1,   225,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
      -1,    -1,    -1,    -1,   223,    -1,   225,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,    -1,    -1,    -1,    -1,   223,    -1,   225,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,    -1,    -1,    -1,    -1,   223,    -1,   225,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,    -1,    -1,    -1,    -1,   223,    -1,   225,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,    -1,    -1,    -1,    -1,   223,    -1,
     225,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,    -1,    -1,    -1,    -1,   223,
      -1,   225,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,    -1,    -1,    -1,    -1,
     223,    -1,   225,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,    -1,    -1,    -1,
      -1,   223,    -1,   225,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,    -1,    -1,
      -1,    -1,   223,    -1,   225,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,    -1,
      -1,    -1,    -1,   223,    -1,   225,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
      -1,    -1,    -1,    -1,   223,    -1,   225,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,    -1,    -1,    -1,    -1,   223,    -1,   225,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,    -1,    -1,    -1,    -1,   223,    -1,   225,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,    -1,    -1,    -1,    -1,   223,    -1,   225,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,    -1,    -1,    -1,    -1,   223,    -1,
     225,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,    -1,    -1,    -1,    -1,   223
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,   235,   236,     6,     0,     4,    12,    13,    42,
      43,    62,    63,    64,    68,    69,    71,    75,    76,    78,
      79,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    99,   100,   101,   102,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   147,   148,   149,
     155,   160,   161,   162,   163,   166,   168,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   189,   190,   191,   198,   200,   237,   239,   240,   260,
     279,   280,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   307,   309,   310,   316,   317,   318,   319,   337,   338,
       3,     4,     5,     9,    10,    11,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    65,    66,    67,
      70,    72,    73,    74,    80,    81,   177,   184,   185,   186,
     187,   188,   192,   193,   194,   195,   196,   197,   199,   214,
     215,   219,   224,   226,   228,   229,   231,   233,   258,   320,
     321,   333,   334,   337,   338,    13,    90,   224,   224,     6,
     231,     6,     6,     6,     6,   224,     6,     6,   226,   226,
     224,   226,   258,   258,   224,   231,   224,   224,     4,   224,
     231,   224,   224,     4,   231,   224,   224,   224,   224,   224,
     224,   224,   224,   224,   103,    90,    90,     6,   231,    84,
      87,    90,   224,     4,    37,    38,    39,    40,    41,    84,
      87,    90,    92,   110,   113,   116,   215,   224,   231,   280,
     291,   307,   309,   320,   326,   328,   337,   338,   224,    90,
      90,   110,    87,    90,    92,    92,    84,    87,    90,    92,
      87,    90,    92,    87,    90,   224,    87,   166,   182,   183,
     231,   214,   215,   224,   231,   323,   324,   323,   231,    84,
      87,    90,   231,   323,     4,    84,    88,    94,    95,    97,
      98,   112,    90,    92,    90,    87,     4,   177,   231,   337,
     338,     4,     6,    84,    87,    90,    87,    90,     4,     4,
       4,     5,   224,   326,   327,     4,   224,   224,   224,     4,
     231,   330,   338,     4,   224,   224,   224,     6,     6,   226,
       4,   334,   338,   224,     4,   334,     5,   231,     5,   231,
       4,   320,   337,   226,   224,   231,     6,   224,   231,   224,
     226,   233,   258,     7,   201,   202,   203,   204,   221,   222,
     256,   257,     4,   224,   226,   228,   258,   258,   258,   258,
     258,   258,   258,   258,   258,   258,   258,   258,   258,   258,
     258,   258,   258,   258,   258,   258,   258,   258,   258,   258,
     258,   224,   224,   224,   258,   258,   258,   258,   224,   258,
     258,   258,   258,   258,   258,   224,   258,   258,   258,     7,
     224,   224,   224,   258,   258,   224,   224,   226,   320,   320,
     320,   225,   320,   227,   320,     4,   166,   167,   338,     4,
     280,   281,   282,   231,   231,     6,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     223,   231,     6,   224,   226,   257,     6,   320,     4,   333,
     334,   337,   338,   333,   320,   333,   336,   262,   267,   334,
     338,   320,   215,   320,   328,   329,   320,   320,   224,   320,
     329,   320,   320,   224,   329,   320,   320,   320,   320,   320,
     320,   333,   320,   320,   326,   224,   231,   329,   327,   327,
     327,   333,   224,   226,   228,   258,   224,   226,   258,   258,
     258,   258,     5,   169,   231,     5,   169,     5,   169,     5,
     169,   110,    84,    87,    90,    92,   231,   320,   328,   320,
     232,   329,     8,   216,   224,   226,   258,   320,   224,   224,
     224,   326,   327,   327,   327,   224,   224,   224,   224,   224,
     224,   326,   224,   326,   224,   326,   231,   231,   320,     4,
     326,   330,   231,   231,   323,   323,   323,   320,   320,   214,
     215,   231,   231,   323,   231,   231,   231,   214,   215,   224,
     282,   320,   323,   231,   224,   231,   224,   224,   224,   224,
     224,   224,   224,   327,   327,   326,   224,     4,   226,   226,
     282,     6,     6,   231,   231,   231,   327,   327,   226,   226,
     226,   320,     6,     6,   320,   320,   320,   228,   320,   231,
     169,   320,   320,   320,   320,     6,     6,   231,     6,   282,
       6,   282,   224,   226,   231,   224,   226,   333,   320,   282,
     326,   326,   225,   320,   227,   320,   231,   231,   334,   326,
       6,   226,   320,   320,     4,   320,   320,   320,   320,   320,
     320,   320,   320,   320,   320,   320,   320,   320,   320,   320,
     320,   320,   320,   320,   320,   320,   320,   336,   333,   336,
     333,   333,   333,   333,   333,   333,   333,   326,   333,   333,
     320,   333,   333,   333,   336,   333,   320,   334,   320,   333,
     333,   333,   333,   333,   338,   334,   338,     7,   204,   256,
     225,     7,   204,   256,   227,     7,   256,   257,   228,     7,
     258,   232,    84,    87,    90,    92,   110,   113,   279,   320,
     329,   320,   320,   320,   320,   320,   320,   320,   320,   320,
     320,   320,   320,   320,   320,   320,   241,   320,   320,     6,
     224,   226,   228,   225,   230,   224,   226,   225,   230,   230,
     225,   230,   227,   230,   261,   227,   261,   230,   230,   225,
     216,   230,   232,   225,   225,   320,   225,   232,   225,   225,
     320,   232,   225,   225,   225,   225,   225,   225,   225,   225,
     225,     7,   320,   320,   232,     6,     6,     6,   225,   320,
     320,     4,   225,   227,   231,   259,   231,   320,   328,   231,
     328,   338,   320,   320,   333,   320,    62,   320,    62,    62,
      62,     5,   231,     5,   231,     5,   231,     5,   231,   329,
     225,   232,   320,   231,   320,   328,   320,   320,   231,   259,
     225,   320,   320,   320,     7,     7,   313,   313,   320,   273,
     320,   334,   274,   320,   334,   275,   320,   334,   276,   320,
     334,   320,     6,   320,     6,   320,     6,   329,   329,   231,
     225,     6,   231,   282,   282,   230,   230,   230,   323,   323,
     281,   281,   230,   320,   320,   320,   320,   232,   295,   232,
     230,   282,   320,   320,   320,   320,   320,   320,   320,   320,
     320,     7,   314,     6,     7,   320,     6,   320,   320,   232,
     329,   329,   329,     6,     6,   320,   320,   320,   225,   225,
     225,   225,   166,   230,   282,   231,     8,   225,   225,   227,
     329,   232,   232,   282,   227,   225,   139,   308,   225,   230,
     232,     7,   204,   256,   225,     7,   204,   256,   227,   320,
     329,     6,     6,   320,   225,   227,   257,   259,   259,   259,
     259,   259,   259,   259,   259,   259,   259,   259,   230,   259,
     259,   259,   259,   259,   259,   259,   230,   230,   230,   259,
     230,   259,   259,   225,   225,   230,   259,   259,   230,   259,
     230,   230,   230,   230,   259,   259,   259,   225,   259,   322,
     335,     6,   230,   230,   225,   230,   259,   230,   259,   225,
     225,   227,    44,    44,   326,     7,   256,   257,    44,    44,
     326,   228,   256,   257,   334,   320,     6,     4,     4,   231,
     331,   259,   231,   231,   231,   231,   224,   110,   232,   232,
       8,     4,   156,   157,   158,   159,   232,   244,   248,   251,
     253,   254,   225,   227,   320,   320,     4,     6,   211,   238,
     329,   320,   320,     6,   329,   320,     6,   333,     6,   338,
       6,   333,   320,   334,     7,   320,   328,   169,     7,     7,
     225,     7,   169,     7,     7,   225,   169,     7,     7,     7,
       7,     7,     7,     7,     7,   320,   225,   232,   231,     6,
     225,   227,   329,   329,   225,   329,   227,   227,   230,   230,
     259,   230,   231,   232,   231,   231,   231,   329,   329,   329,
     329,   232,     7,     8,   329,   225,   227,   329,     7,   225,
     225,   225,   320,   326,     4,   312,     6,   225,   225,   230,
     225,   230,   225,   230,   225,   230,   225,   225,   225,   232,
     232,   329,   228,   282,   232,   232,   323,   320,   320,   232,
     232,   320,   323,   230,   230,   230,   119,   119,   136,   144,
     145,   146,   150,   151,   152,   153,   305,   306,   231,   323,
     232,   292,   225,   232,   225,   225,   225,   225,   225,   225,
     225,   320,     6,   320,   225,   227,   227,   232,   232,   232,
     227,   227,   230,     7,     7,     7,   228,   320,   232,   320,
     320,     7,   228,   232,   232,     7,     6,   320,   232,   231,
     326,     6,    44,    44,   326,   256,   257,    44,    44,   326,
     256,   257,   232,   232,   227,   257,   228,   257,   333,   320,
     320,   320,   320,   329,   333,   320,   326,   333,   333,   333,
     269,   271,   320,   333,   333,   320,   258,   258,     6,   320,
       6,   258,   258,     6,     4,   166,   167,   320,     6,     6,
       6,     7,   226,   330,   332,     6,   329,   329,   329,   329,
     320,   224,   259,   320,   245,   224,   224,   231,   255,     6,
     257,   257,   225,   227,   211,   333,   225,   225,   227,   225,
     230,     7,   224,   226,   259,   259,   323,    90,    92,   326,
     326,     7,   326,    90,    92,   326,   326,     7,    92,   326,
     326,   326,   326,   326,   326,   326,   326,     6,     7,     7,
     329,   228,   232,   232,   232,   320,   320,   320,   320,   320,
     320,   320,   232,   232,   232,   232,   326,   320,   232,   232,
     326,     7,     7,     7,   119,   311,     6,     7,   256,   320,
     256,   320,   256,   320,   256,   320,     7,     7,     7,     7,
       7,   232,     4,   232,   230,   230,   230,   232,   232,   323,
     323,   323,    87,     4,     6,   320,   231,     6,   224,     6,
     154,     6,   154,     6,   154,     6,   154,   232,   306,   282,
     230,   305,     7,     6,     7,     7,     7,     7,     7,     7,
       7,     6,   231,     6,     6,     6,    90,     7,     6,     6,
     320,   326,   326,   326,     4,   230,     8,     8,   225,     4,
       4,   230,   231,     6,   231,   326,   232,   258,   258,     6,
     320,     6,   258,   258,     6,   320,     6,   259,     6,     4,
       6,   259,   259,   259,   259,   259,   230,   230,   259,   225,
     259,   259,   230,   230,   259,   270,   230,   259,   272,   225,
     225,   259,   259,   259,   336,   336,     6,   259,   336,   336,
       7,   256,   257,   228,     7,     6,   330,   320,   230,   232,
     232,   232,   232,   232,   225,   320,   256,   224,   320,   320,
     325,   326,   231,   228,     6,     6,   238,     6,   320,   231,
     320,   334,   225,   227,     6,     6,     6,   231,   231,   112,
     278,   278,   326,     6,   231,   231,     6,     6,   326,   231,
       6,     6,     6,     6,     6,     6,     6,     6,     5,   326,
     232,     4,   259,   225,   227,   230,   230,   230,   230,   230,
     230,   230,     6,   259,     6,   326,   326,   326,     4,     6,
     326,   326,   326,   326,   326,   326,   326,   326,   231,   231,
       7,     6,     7,   320,   320,   320,   231,   231,   230,   232,
     230,   232,   230,   232,   231,   226,     6,   320,   326,   320,
       6,     6,     6,     6,   232,   320,   323,   232,     5,   326,
     231,   231,   231,   231,   231,   231,   231,   326,   329,   231,
     320,   227,     6,     6,   165,   320,   320,   320,     6,     6,
       7,   334,   282,   282,   230,     6,   259,   336,   336,     6,
     259,   336,   336,     6,   256,   257,   333,   320,   333,     4,
       4,   181,     6,   259,   259,     6,   259,   259,   334,   320,
       6,     4,   331,     6,   227,   330,     6,     6,     6,     6,
     225,   326,   242,   320,   230,   230,   230,   232,   243,   320,
       4,   333,   230,   326,   334,     7,     7,   320,   320,   323,
       6,     6,     6,   320,   320,     6,   320,     5,     6,   231,
     320,   320,   320,   320,   320,   320,   320,     6,   169,   277,
       6,   320,     6,     6,     6,     6,     6,     6,     4,     6,
       6,   329,   329,   320,   320,   334,   232,   225,   230,   232,
     281,   281,   323,     6,   296,   323,     6,   297,   323,     6,
     298,   326,   320,   232,   230,   225,   120,   232,   230,     6,
       6,   325,   323,   323,   323,   323,   323,   215,   323,     6,
     232,   320,     6,     6,   326,   230,   232,     8,   232,   225,
     231,   320,   334,   230,   308,   308,   326,     6,   259,   259,
       6,   259,   259,   326,   225,   259,   259,   231,   326,   334,
     231,   320,   334,   334,     6,     6,     6,     6,     6,     6,
       7,     6,   228,     6,   225,   230,   320,   320,   326,   231,
     230,   232,     6,   320,   263,   266,   231,   231,   232,   232,
     232,   232,   232,     5,   325,   259,   259,   230,   230,   230,
     230,   230,    88,     6,   231,   232,   232,   231,     6,     6,
     231,   320,   232,   232,   230,   231,   230,   231,   230,   231,
     232,   227,     6,   326,     7,    90,   231,   320,   232,   230,
     230,   230,   230,   230,   230,     6,   232,   164,   320,   320,
     329,     6,     6,   334,   232,   232,   232,     6,     6,     6,
       6,     6,   268,   320,   328,   336,   330,   167,   246,   320,
     230,   230,   325,   320,     6,   230,   269,   271,   326,   326,
       6,     6,     6,     6,     6,     6,   232,   320,   320,   320,
     320,   320,   231,   325,   124,   125,   130,   315,   124,   125,
     315,   329,   281,   230,   232,   320,   323,   305,   320,   323,
     305,   320,   323,   305,     6,   230,   232,   326,   231,   282,
     232,     6,   329,   323,   323,   323,   323,   323,   320,   232,
     232,   232,   225,   231,     6,   230,   232,     7,     7,   232,
       6,   231,   320,   320,   232,   320,   232,   232,   265,   264,
     231,   230,   230,   230,   230,   230,   320,   232,   231,   323,
     326,     6,   231,   323,     6,   232,   232,   320,   232,   230,
     232,   232,   230,   232,   232,   230,   232,   326,     6,   119,
     326,   232,   293,   231,   232,   230,   230,   230,   230,   230,
       6,     6,     6,   282,   320,   334,   338,   243,   225,   230,
       6,   231,   230,   269,   269,   320,   320,   320,   320,   320,
     320,   232,     6,   323,     6,   323,     6,     6,   232,     6,
     299,   320,     6,     6,   300,   320,     6,     6,   301,   320,
       6,   232,   320,   232,   305,   282,     6,   329,   329,   329,
     329,   323,   329,   308,     7,   224,   232,   249,   320,   325,
     320,   232,   232,   230,   230,   230,   230,   230,   230,   230,
     230,   231,   232,   231,   232,   231,   232,     6,     6,   232,
     232,   294,   232,   232,   232,   232,   230,   232,   232,   334,
     225,     6,   231,   225,   232,   232,   320,   320,   320,   320,
     320,   320,   323,   323,   305,     6,   302,   305,     6,   303,
     305,     6,   304,   305,     6,     6,     6,     6,   329,     6,
       6,   247,   333,   252,   231,     6,   232,   259,   230,   230,
     230,   230,   230,   230,   232,   231,   232,   231,   232,   231,
     232,   232,   230,   232,   231,   325,     6,   320,   320,   320,
     320,   320,   320,     6,   305,     6,   305,     6,   305,     6,
     333,     6,   250,   333,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   230,   232,     6,     6,     6,     6,
       6,     6,   333,     6
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
#line 1961 "Gmsh.y"
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
#line 1988 "Gmsh.y"
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
#line 2016 "Gmsh.y"
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
#line 2042 "Gmsh.y"
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
#line 2071 "Gmsh.y"
    {
     GModel::current()->getGEOInternals()->addCompoundMesh ( 1 , (yyvsp[(3) - (4)].l) );
   ;}
    break;

  case 184:
#line 2076 "Gmsh.y"
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
#line 2094 "Gmsh.y"
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
#line 2140 "Gmsh.y"
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
#line 2168 "Gmsh.y"
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
#line 2218 "Gmsh.y"
    {
      myGmshSurface = 0;
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 189:
#line 2224 "Gmsh.y"
    {
      myGmshSurface = gmshSurface::getSurface((int)(yyvsp[(3) - (4)].d));
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 190:
#line 2230 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (10)].d);
      myGmshSurface = gmshParametricSurface::NewParametricSurface(num, (yyvsp[(7) - (10)].c), (yyvsp[(8) - (10)].c), (yyvsp[(9) - (10)].c));
      (yyval.s).Type = 0;
      (yyval.s).Num = num;
    ;}
    break;

  case 191:
#line 2237 "Gmsh.y"
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
#line 2279 "Gmsh.y"
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
#line 2305 "Gmsh.y"
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
#line 2329 "Gmsh.y"
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
#line 2353 "Gmsh.y"
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
#line 2378 "Gmsh.y"
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
#line 2401 "Gmsh.y"
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
#line 2428 "Gmsh.y"
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
#line 2456 "Gmsh.y"
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
#line 2481 "Gmsh.y"
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

  case 201:
#line 2508 "Gmsh.y"
    {
      GModel::current()->getGEOInternals()->addCompoundMesh ( 2 , (yyvsp[(3) - (4)].l) );
    ;}
    break;

  case 202:
#line 2512 "Gmsh.y"
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

  case 203:
#line 2532 "Gmsh.y"
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

  case 204:
#line 2565 "Gmsh.y"
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

  case 205:
#line 2612 "Gmsh.y"
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

  case 206:
#line 2630 "Gmsh.y"
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

  case 207:
#line 2657 "Gmsh.y"
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

  case 208:
#line 2676 "Gmsh.y"
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

  case 209:
#line 2695 "Gmsh.y"
    {
      GModel::current()->getGEOInternals()->addCompoundMesh(3, (yyvsp[(3) - (4)].l));
    ;}
    break;

  case 210:
#line 2699 "Gmsh.y"
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

  case 211:
#line 2715 "Gmsh.y"
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

  case 212:
#line 2763 "Gmsh.y"
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

  case 213:
#line 2780 "Gmsh.y"
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

  case 214:
#line 2798 "Gmsh.y"
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

  case 215:
#line 2808 "Gmsh.y"
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

  case 216:
#line 2818 "Gmsh.y"
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

  case 217:
#line 2828 "Gmsh.y"
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

  case 218:
#line 2891 "Gmsh.y"
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

  case 219:
#line 2902 "Gmsh.y"
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

  case 220:
#line 2917 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 221:
#line 2918 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 222:
#line 2923 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    ;}
    break;

  case 223:
#line 2927 "Gmsh.y"
    {
      List_Add((yyval.l), &(yyvsp[(2) - (2)].s));
    ;}
    break;

  case 224:
#line 2931 "Gmsh.y"
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

  case 225:
#line 2960 "Gmsh.y"
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

  case 226:
#line 2989 "Gmsh.y"
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

  case 227:
#line 3018 "Gmsh.y"
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

  case 228:
#line 3052 "Gmsh.y"
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

  case 229:
#line 3074 "Gmsh.y"
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

  case 230:
#line 3101 "Gmsh.y"
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

  case 231:
#line 3123 "Gmsh.y"
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

  case 232:
#line 3145 "Gmsh.y"
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

  case 233:
#line 3167 "Gmsh.y"
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

  case 234:
#line 3223 "Gmsh.y"
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

  case 235:
#line 3247 "Gmsh.y"
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

  case 236:
#line 3272 "Gmsh.y"
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

  case 237:
#line 3297 "Gmsh.y"
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

  case 238:
#line 3410 "Gmsh.y"
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

  case 239:
#line 3429 "Gmsh.y"
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

  case 240:
#line 3472 "Gmsh.y"
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

  case 241:
#line 3493 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      GModel::current()->getFields()->deleteField((int)(yyvsp[(4) - (6)].d));
#endif
    ;}
    break;

  case 242:
#line 3499 "Gmsh.y"
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

  case 243:
#line 3514 "Gmsh.y"
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

  case 244:
#line 3542 "Gmsh.y"
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

  case 245:
#line 3559 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(4) - (5)].l), i, &TheShape);
	ColorShape(TheShape.Type, TheShape.Num, (yyvsp[(2) - (5)].u), false);
      }
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 246:
#line 3568 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(5) - (6)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(5) - (6)].l), i, &TheShape);
	ColorShape(TheShape.Type, TheShape.Num, (yyvsp[(3) - (6)].u), true);
      }
      List_Delete((yyvsp[(5) - (6)].l));
    ;}
    break;

  case 247:
#line 3582 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(4) - (5)].l), i, &TheShape);
	SetPartition(TheShape.Type, TheShape.Num, (yyvsp[(2) - (5)].d));
      }
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 248:
#line 3596 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 1, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 249:
#line 3602 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 0, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 250:
#line 3608 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 1, false);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 251:
#line 3617 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(4) - (5)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 1, true);
      }
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 252:
#line 3626 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 0, false);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 253:
#line 3635 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(4) - (5)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 0, true);
      }
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 254:
#line 3649 "Gmsh.y"
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

  case 255:
#line 3711 "Gmsh.y"
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

  case 256:
#line 3729 "Gmsh.y"
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

  case 257:
#line 3746 "Gmsh.y"
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

  case 258:
#line 3761 "Gmsh.y"
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

  case 259:
#line 3790 "Gmsh.y"
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

  case 260:
#line 3802 "Gmsh.y"
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

  case 261:
#line 3826 "Gmsh.y"
    {
      Msg::Exit(0);
    ;}
    break;

  case 262:
#line 3830 "Gmsh.y"
    {
      gmsh_yyerrorstate = 999; // this will be checked when yyparse returns
      YYABORT;
    ;}
    break;

  case 263:
#line 3835 "Gmsh.y"
    {
      // FIXME: this is a hack to force a transfer from the old DB to
      // the new DB. This will become unnecessary if/when we fill the
      // GModel directly during parsing.
      GModel::current()->importGEOInternals();
      GModel::current()->importOCCInternals();
    ;}
    break;

  case 264:
#line 3843 "Gmsh.y"
    {
      new GModel();
      GModel::current(GModel::list.size() - 1);
    ;}
    break;

  case 265:
#line 3848 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 0;
      GModel::current()->importGEOInternals();
      SetBoundingBox();
    ;}
    break;

  case 266:
#line 3854 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 1;
      SetBoundingBox((yyvsp[(3) - (15)].d), (yyvsp[(5) - (15)].d), (yyvsp[(7) - (15)].d), (yyvsp[(9) - (15)].d), (yyvsp[(11) - (15)].d), (yyvsp[(13) - (15)].d));
    ;}
    break;

  case 267:
#line 3859 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
      drawContext::global()->draw();
#endif
    ;}
    break;

  case 268:
#line 3865 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
     CTX::instance()->mesh.changed = ENT_ALL;
     for(unsigned int index = 0; index < PView::list.size(); index++)
       PView::list[index]->setChanged(true);
#endif
    ;}
    break;

  case 269:
#line 3873 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh();
    ;}
    break;

  case 270:
#line 3877 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh(1);
    ;}
    break;

  case 271:
#line 3881 "Gmsh.y"
    {
      GModel::current()->importGEOInternals();
      GModel::current()->refineMesh(CTX::instance()->mesh.secondOrderLinear);
    ;}
    break;

  case 272:
#line 3887 "Gmsh.y"
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

  case 273:
#line 3946 "Gmsh.y"
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

  case 274:
#line 3962 "Gmsh.y"
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

  case 275:
#line 3979 "Gmsh.y"
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

  case 276:
#line 3996 "Gmsh.y"
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

  case 277:
#line 4018 "Gmsh.y"
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

  case 278:
#line 4040 "Gmsh.y"
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

  case 279:
#line 4075 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip_until(NULL, "Return");
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 280:
#line 4083 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip_until(NULL, "Return");
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 281:
#line 4091 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    ;}
    break;

  case 282:
#line 4097 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 283:
#line 4104 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 284:
#line 4111 "Gmsh.y"
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

  case 285:
#line 4131 "Gmsh.y"
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

  case 286:
#line 4157 "Gmsh.y"
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

  case 287:
#line 4169 "Gmsh.y"
    {
      ImbricatedTest--;
      if(ImbricatedTest < 0)
        yymsg(1, "Orphan EndIf");
    ;}
    break;

  case 288:
#line 4181 "Gmsh.y"
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

  case 289:
#line 4211 "Gmsh.y"
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

  case 290:
#line 4242 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (13)].l),
		    (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].v)[0], (yyvsp[(7) - (13)].v)[1], (yyvsp[(7) - (13)].v)[2], (yyvsp[(9) - (13)].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[(12) - (13)].l));
    ;}
    break;

  case 291:
#line 4250 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 292:
#line 4256 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (7)].l),
		    (yyvsp[(2) - (7)].v)[0], (yyvsp[(2) - (7)].v)[1], (yyvsp[(2) - (7)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(4) - (7)].l));
    ;}
    break;

  case 293:
#line 4264 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 294:
#line 4270 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[(10) - (13)].l),
		    0., 0., 0., (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(10) - (13)].l));
    ;}
    break;

  case 295:
#line 4278 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 296:
#line 4284 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (15)].l),
		    (yyvsp[(3) - (15)].v)[0], (yyvsp[(3) - (15)].v)[1], (yyvsp[(3) - (15)].v)[2], (yyvsp[(5) - (15)].v)[0], (yyvsp[(5) - (15)].v)[1], (yyvsp[(5) - (15)].v)[2], (yyvsp[(7) - (15)].v)[0], (yyvsp[(7) - (15)].v)[1], (yyvsp[(7) - (15)].v)[2], (yyvsp[(9) - (15)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(12) - (15)].l));
    ;}
    break;

  case 297:
#line 4292 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 298:
#line 4298 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(BOUNDARY_LAYER, (yyvsp[(3) - (6)].l), 0., 0., 0., 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(3) - (6)].l));
    ;}
    break;

  case 299:
#line 4305 "Gmsh.y"
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

  case 300:
#line 4338 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      List_Delete((yyvsp[(6) - (7)].l));
    ;}
    break;

  case 301:
#line 4343 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      List_Delete((yyvsp[(6) - (12)].l));
      List_Delete((yyvsp[(11) - (12)].l));
    ;}
    break;

  case 302:
#line 4349 "Gmsh.y"
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
#line 4372 "Gmsh.y"
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
#line 4396 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 305:
#line 4403 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 306:
#line 4410 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 307:
#line 4417 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 308:
#line 4424 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 309:
#line 4431 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 310:
#line 4438 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 311:
#line 4445 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 312:
#line 4452 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 313:
#line 4459 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 314:
#line 4465 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 315:
#line 4472 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 316:
#line 4478 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 317:
#line 4485 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 318:
#line 4491 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 319:
#line 4498 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 320:
#line 4504 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 321:
#line 4511 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 322:
#line 4517 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 323:
#line 4524 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 324:
#line 4530 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 325:
#line 4537 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 326:
#line 4543 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 327:
#line 4550 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 328:
#line 4556 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 329:
#line 4563 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 330:
#line 4569 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 331:
#line 4580 "Gmsh.y"
    {
    ;}
    break;

  case 332:
#line 4583 "Gmsh.y"
    {
    ;}
    break;

  case 333:
#line 4589 "Gmsh.y"
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
#line 4601 "Gmsh.y"
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
#line 4621 "Gmsh.y"
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
#line 4645 "Gmsh.y"
    {
      extr.mesh.ScaleLast = true;
    ;}
    break;

  case 337:
#line 4649 "Gmsh.y"
    {
      extr.mesh.Recombine = true;
    ;}
    break;

  case 338:
#line 4653 "Gmsh.y"
    {
      extr.mesh.Recombine = (yyvsp[(2) - (3)].d) ? true : false;
    ;}
    break;

  case 339:
#line 4657 "Gmsh.y"
    {
      yymsg(0, "Keyword 'QuadTriSngl' deprecated. Use 'QuadTriNoNewVerts' instead.");
    ;}
    break;

  case 340:
#line 4661 "Gmsh.y"
    {
      yymsg(0, "Keyword 'QuadTriSngl' deprecated. Use 'QuadTriNoNewVerts' instead.");
    ;}
    break;

  case 341:
#line 4665 "Gmsh.y"
    {
      yymsg(0, "Method 'QuadTriDbl' deprecated. Use 'QuadTriAddVerts' instead, "
            "which has no requirement for the number of extrusion layers and meshes "
            "with body-centered vertices.");
    ;}
    break;

  case 342:
#line 4671 "Gmsh.y"
    {
      yymsg(0, "Method 'QuadTriDbl' deprecated. Use 'QuadTriAddVerts' instead, "
            "which has no requirement for the number of extrusion layers and meshes "
            "with body-centered vertices.");
    ;}
    break;

  case 343:
#line 4677 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1;
    ;}
    break;

  case 344:
#line 4681 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1_RECOMB;
    ;}
    break;

  case 345:
#line 4685 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1;
    ;}
    break;

  case 346:
#line 4689 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1_RECOMB;
    ;}
    break;

  case 347:
#line 4693 "Gmsh.y"
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
#line 4712 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (6)].c), "Index"))
        extr.mesh.BoundaryLayerIndex = (yyvsp[(4) - (6)].d);
      else if(!strcmp((yyvsp[(2) - (6)].c), "View"))
        extr.mesh.ViewIndex = (yyvsp[(4) - (6)].d);
      Free((yyvsp[(2) - (6)].c));
    ;}
    break;

  case 349:
#line 4724 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Union; ;}
    break;

  case 350:
#line 4725 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Intersection; ;}
    break;

  case 351:
#line 4726 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Difference; ;}
    break;

  case 352:
#line 4727 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Section; ;}
    break;

  case 353:
#line 4728 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Fragments; ;}
    break;

  case 354:
#line 4732 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 355:
#line 4733 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 356:
#line 4734 "Gmsh.y"
    { (yyval.i) = (yyvsp[(2) - (3)].d); ;}
    break;

  case 357:
#line 4739 "Gmsh.y"
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
#line 4772 "Gmsh.y"
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
#line 4799 "Gmsh.y"
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
#line 4821 "Gmsh.y"
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    ;}
    break;

  case 361:
#line 4825 "Gmsh.y"
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
#line 4840 "Gmsh.y"
    {
      (yyval.i) = -1; // left
    ;}
    break;

  case 363:
#line 4844 "Gmsh.y"
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
#line 4860 "Gmsh.y"
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   ;}
    break;

  case 365:
#line 4864 "Gmsh.y"
    {
     (yyval.l) = (yyvsp[(2) - (2)].l);
   ;}
    break;

  case 366:
#line 4869 "Gmsh.y"
    {
      (yyval.i) = 45;
    ;}
    break;

  case 367:
#line 4873 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(2) - (2)].d);
    ;}
    break;

  case 368:
#line 4879 "Gmsh.y"
    {
      (yyval.l) = List_Create(1, 1, sizeof(double));
    ;}
    break;

  case 369:
#line 4883 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
    ;}
    break;

  case 370:
#line 4890 "Gmsh.y"
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
#line 4946 "Gmsh.y"
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
#line 5016 "Gmsh.y"
    {
      yymsg(1, "Elliptic Surface is deprecated: use Transfinite instead (with smoothing)");
      List_Delete((yyvsp[(7) - (8)].l));
    ;}
    break;

  case 373:
#line 5021 "Gmsh.y"
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
#line 5088 "Gmsh.y"
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
#line 5124 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (8)].l)); i++){
	double d;
	List_Read((yyvsp[(4) - (8)].l), i, &d);
	CTX::instance()->mesh.algo2d_per_face[(int)d] = (int)(yyvsp[(7) - (8)].d);
      }
    ;}
    break;

  case 376:
#line 5132 "Gmsh.y"
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
#line 5175 "Gmsh.y"
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
#line 5214 "Gmsh.y"
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
#line 5235 "Gmsh.y"
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
#line 5267 "Gmsh.y"
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
#line 5294 "Gmsh.y"
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
#line 5320 "Gmsh.y"
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
#line 5346 "Gmsh.y"
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
#line 5372 "Gmsh.y"
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
#line 5398 "Gmsh.y"
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
#line 5419 "Gmsh.y"
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
#line 5447 "Gmsh.y"
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
#line 5475 "Gmsh.y"
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
#line 5503 "Gmsh.y"
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
#line 5531 "Gmsh.y"
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
#line 5559 "Gmsh.y"
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
#line 5598 "Gmsh.y"
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
#line 5637 "Gmsh.y"
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
#line 5658 "Gmsh.y"
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
#line 5679 "Gmsh.y"
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
#line 5706 "Gmsh.y"
    {
      ReplaceAllDuplicates();
    ;}
    break;

  case 397:
#line 5710 "Gmsh.y"
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
#line 5720 "Gmsh.y"
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
#line 5754 "Gmsh.y"
    { (yyval.c) = (char*)"Homology"; ;}
    break;

  case 400:
#line 5755 "Gmsh.y"
    { (yyval.c) = (char*)"Cohomology"; ;}
    break;

  case 401:
#line 5756 "Gmsh.y"
    { (yyval.c) = (char*)"Betti"; ;}
    break;

  case 402:
#line 5761 "Gmsh.y"
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest((yyvsp[(1) - (2)].c), domain, subdomain, dim);
    ;}
    break;

  case 403:
#line 5767 "Gmsh.y"
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
#line 5779 "Gmsh.y"
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
#line 5797 "Gmsh.y"
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
#line 5824 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d);           ;}
    break;

  case 407:
#line 5825 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (3)].d);           ;}
    break;

  case 408:
#line 5826 "Gmsh.y"
    { (yyval.d) = -(yyvsp[(2) - (2)].d);          ;}
    break;

  case 409:
#line 5827 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);           ;}
    break;

  case 410:
#line 5828 "Gmsh.y"
    { (yyval.d) = !(yyvsp[(2) - (2)].d);          ;}
    break;

  case 411:
#line 5829 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) - (yyvsp[(3) - (3)].d);      ;}
    break;

  case 412:
#line 5830 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) + (yyvsp[(3) - (3)].d);      ;}
    break;

  case 413:
#line 5831 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) * (yyvsp[(3) - (3)].d);      ;}
    break;

  case 414:
#line 5833 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (3)].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));
      else
	(yyval.d) = (yyvsp[(1) - (3)].d) / (yyvsp[(3) - (3)].d);
    ;}
    break;

  case 415:
#line 5839 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) % (int)(yyvsp[(3) - (3)].d);  ;}
    break;

  case 416:
#line 5840 "Gmsh.y"
    { (yyval.d) = pow((yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));  ;}
    break;

  case 417:
#line 5841 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d);      ;}
    break;

  case 418:
#line 5842 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) > (yyvsp[(3) - (3)].d);      ;}
    break;

  case 419:
#line 5843 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) <= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 420:
#line 5844 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) >= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 421:
#line 5845 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) == (yyvsp[(3) - (3)].d);     ;}
    break;

  case 422:
#line 5846 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) != (yyvsp[(3) - (3)].d);     ;}
    break;

  case 423:
#line 5847 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) && (yyvsp[(3) - (3)].d);     ;}
    break;

  case 424:
#line 5848 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) || (yyvsp[(3) - (3)].d);     ;}
    break;

  case 425:
#line 5849 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (5)].d) ? (yyvsp[(3) - (5)].d) : (yyvsp[(5) - (5)].d); ;}
    break;

  case 426:
#line 5850 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 427:
#line 5851 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 428:
#line 5852 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 429:
#line 5853 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 430:
#line 5854 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 431:
#line 5855 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 432:
#line 5856 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 433:
#line 5857 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 434:
#line 5858 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 435:
#line 5859 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 436:
#line 5860 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 437:
#line 5861 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 438:
#line 5862 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 439:
#line 5863 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 440:
#line 5864 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 441:
#line 5865 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 442:
#line 5866 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 443:
#line 5867 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d) + 0.5); ;}
    break;

  case 444:
#line 5868 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 445:
#line 5869 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 446:
#line 5870 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 447:
#line 5871 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 448:
#line 5880 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 449:
#line 5881 "Gmsh.y"
    { (yyval.d) = 3.141592653589793; ;}
    break;

  case 450:
#line 5882 "Gmsh.y"
    { (yyval.d) = (double)ImbricatedTest; ;}
    break;

  case 451:
#line 5883 "Gmsh.y"
    { (yyval.d) = Msg::GetCommRank(); ;}
    break;

  case 452:
#line 5884 "Gmsh.y"
    { (yyval.d) = Msg::GetCommSize(); ;}
    break;

  case 453:
#line 5885 "Gmsh.y"
    { (yyval.d) = GetGmshMajorVersion(); ;}
    break;

  case 454:
#line 5886 "Gmsh.y"
    { (yyval.d) = GetGmshMinorVersion(); ;}
    break;

  case 455:
#line 5887 "Gmsh.y"
    { (yyval.d) = GetGmshPatchVersion(); ;}
    break;

  case 456:
#line 5888 "Gmsh.y"
    { (yyval.d) = Cpu(); ;}
    break;

  case 457:
#line 5889 "Gmsh.y"
    { (yyval.d) = GetMemoryUsage()/1024./1024.; ;}
    break;

  case 458:
#line 5890 "Gmsh.y"
    { (yyval.d) = TotalRam(); ;}
    break;

  case 459:
#line 5895 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 460:
#line 5897 "Gmsh.y"
    {
      std::vector<double> val(1, (yyvsp[(3) - (6)].d));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.d) = val[0];
    ;}
    break;

  case 461:
#line 5903 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 462:
#line 5908 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 463:
#line 5913 "Gmsh.y"
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
#line 5930 "Gmsh.y"
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
#line 5948 "Gmsh.y"
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
#line 5966 "Gmsh.y"
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
#line 5984 "Gmsh.y"
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
#line 6002 "Gmsh.y"
    {
      (yyval.d) = gmsh_yysymbols.count((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 469:
#line 6007 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.d) = !StatFile(tmp);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 470:
#line 6013 "Gmsh.y"
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
#line 6028 "Gmsh.y"
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
#line 6047 "Gmsh.y"
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
#line 6067 "Gmsh.y"
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
#line 6087 "Gmsh.y"
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
#line 6107 "Gmsh.y"
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
#line 6130 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), (yyval.d));
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 477:
#line 6135 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), (yyval.d));
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 478:
#line 6140 "Gmsh.y"
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
#line 6150 "Gmsh.y"
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
#line 6160 "Gmsh.y"
    {
      (yyval.d) = Msg::GetValue((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 481:
#line 6165 "Gmsh.y"
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
#line 6176 "Gmsh.y"
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
#line 6185 "Gmsh.y"
    {
      (yyval.d) = strlen((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 484:
#line 6190 "Gmsh.y"
    {
      (yyval.d) = strcmp((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 485:
#line 6195 "Gmsh.y"
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
#line 6222 "Gmsh.y"
    {
      memcpy((yyval.v), (yyvsp[(1) - (1)].v), 5*sizeof(double));
    ;}
    break;

  case 487:
#line 6226 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 488:
#line 6230 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 489:
#line 6234 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] - (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 490:
#line 6238 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] + (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 491:
#line 6245 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (11)].d);  (yyval.v)[1] = (yyvsp[(4) - (11)].d);  (yyval.v)[2] = (yyvsp[(6) - (11)].d);  (yyval.v)[3] = (yyvsp[(8) - (11)].d); (yyval.v)[4] = (yyvsp[(10) - (11)].d);
    ;}
    break;

  case 492:
#line 6249 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (9)].d);  (yyval.v)[1] = (yyvsp[(4) - (9)].d);  (yyval.v)[2] = (yyvsp[(6) - (9)].d);  (yyval.v)[3] = (yyvsp[(8) - (9)].d); (yyval.v)[4] = 1.0;
    ;}
    break;

  case 493:
#line 6253 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 494:
#line 6257 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 495:
#line 6264 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].l)));
    ;}
    break;

  case 496:
#line 6269 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].l)));
    ;}
    break;

  case 497:
#line 6276 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 498:
#line 6281 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 499:
#line 6285 "Gmsh.y"
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    ;}
    break;

  case 500:
#line 6290 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 501:
#line 6294 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 502:
#line 6302 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (5)].d);
      }
    ;}
    break;

  case 503:
#line 6313 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 504:
#line 6317 "Gmsh.y"
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
#line 6329 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 506:
#line 6337 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (3)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (3)].d);
      }
    ;}
    break;

  case 507:
#line 6345 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      for(double d = (yyvsp[(1) - (3)].d); ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d <= (yyvsp[(3) - (3)].d)) : (d >= (yyvsp[(3) - (3)].d));
          ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d += 1.) : (d -= 1.))
	List_Add((yyval.l), &d);
    ;}
    break;

  case 508:
#line 6352 "Gmsh.y"
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
#line 6362 "Gmsh.y"
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
#line 6391 "Gmsh.y"
    {
      (yyval.l) = GetAllElementaryEntityNumbers(0);
    ;}
    break;

  case 511:
#line 6395 "Gmsh.y"
    {
      (yyval.l) = GetAllElementaryEntityNumbers(1);
    ;}
    break;

  case 512:
#line 6399 "Gmsh.y"
    {
      (yyval.l) = GetAllElementaryEntityNumbers(2);
    ;}
    break;

  case 513:
#line 6403 "Gmsh.y"
    {
      (yyval.l) = GetAllElementaryEntityNumbers(3);
    ;}
    break;

  case 514:
#line 6407 "Gmsh.y"
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(0);
    ;}
    break;

  case 515:
#line 6411 "Gmsh.y"
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(1);
    ;}
    break;

  case 516:
#line 6415 "Gmsh.y"
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(2);
    ;}
    break;

  case 517:
#line 6419 "Gmsh.y"
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(3);
    ;}
    break;

  case 518:
#line 6423 "Gmsh.y"
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
#line 6452 "Gmsh.y"
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
#line 6481 "Gmsh.y"
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
#line 6510 "Gmsh.y"
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
#line 6540 "Gmsh.y"
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
#line 6553 "Gmsh.y"
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
#line 6566 "Gmsh.y"
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
#line 6579 "Gmsh.y"
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
#line 6591 "Gmsh.y"
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
#line 6601 "Gmsh.y"
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
#line 6611 "Gmsh.y"
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
#line 6621 "Gmsh.y"
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
#line 6633 "Gmsh.y"
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
#line 6646 "Gmsh.y"
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
#line 6658 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 533:
#line 6662 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 534:
#line 6666 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (6)].l);
    ;}
    break;

  case 535:
#line 6670 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (6)].l);
    ;}
    break;

  case 536:
#line 6674 "Gmsh.y"
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
#line 6692 "Gmsh.y"
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
#line 6710 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = (yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1);
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 539:
#line 6718 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = pow(10,(yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1));
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 540:
#line 6726 "Gmsh.y"
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
#line 6755 "Gmsh.y"
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
#line 6768 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 543:
#line 6773 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 544:
#line 6777 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].d)));
    ;}
    break;

  case 545:
#line 6781 "Gmsh.y"
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
#line 6793 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (9)].d), (int)(yyvsp[(4) - (9)].d), (int)(yyvsp[(6) - (9)].d), (int)(yyvsp[(8) - (9)].d));
    ;}
    break;

  case 547:
#line 6797 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (7)].d), (int)(yyvsp[(4) - (7)].d), (int)(yyvsp[(6) - (7)].d), 255);
    ;}
    break;

  case 548:
#line 6809 "Gmsh.y"
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
#line 6826 "Gmsh.y"
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(5) - (5)].c), val);
      (yyval.u) = val;
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(5) - (5)].c));
    ;}
    break;

  case 550:
#line 6836 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 551:
#line 6840 "Gmsh.y"
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
#line 6855 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].u)));
    ;}
    break;

  case 553:
#line 6860 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].u)));
    ;}
    break;

  case 554:
#line 6867 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 555:
#line 6871 "Gmsh.y"
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
#line 6884 "Gmsh.y"
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
#line 6898 "Gmsh.y"
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
#line 6912 "Gmsh.y"
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
#line 6926 "Gmsh.y"
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
#line 6940 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 561:
#line 6948 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 562:
#line 6959 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 563:
#line 6963 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 564:
#line 6967 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    ;}
    break;

  case 565:
#line 6975 "Gmsh.y"
    {
      std::string exe = Msg::GetExecutableName();
      (yyval.c) = (char *)Malloc(exe.size() + 1);
      strcpy((yyval.c), exe.c_str());
    ;}
    break;

  case 566:
#line 6981 "Gmsh.y"
    {
      std::string action = Msg::GetOnelabAction();
      (yyval.c) = (char *)Malloc(action.size() + 1);
      strcpy((yyval.c), action.c_str());
    ;}
    break;

  case 567:
#line 6987 "Gmsh.y"
    {
      const char *env = GetEnvironmentVar((yyvsp[(3) - (4)].c));
      if(!env) env = "";
      (yyval.c) = (char *)Malloc((sizeof(env) + 1) * sizeof(char));
      strcpy((yyval.c), env);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 568:
#line 6995 "Gmsh.y"
    {
      std::string s = Msg::GetString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 569:
#line 7003 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (4)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 570:
#line 7010 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 571:
#line 7018 "Gmsh.y"
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
#line 7033 "Gmsh.y"
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
#line 7047 "Gmsh.y"
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
#line 7061 "Gmsh.y"
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
#line 7073 "Gmsh.y"
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
#line 7089 "Gmsh.y"
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
#line 7098 "Gmsh.y"
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
#line 7107 "Gmsh.y"
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
#line 7117 "Gmsh.y"
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
#line 7128 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (8)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (8)].d), (int)(yyvsp[(7) - (8)].d));
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (8)].c));
    ;}
    break;

  case 581:
#line 7136 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (6)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (6)].d), std::string::npos);
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 582:
#line 7144 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 583:
#line 7148 "Gmsh.y"
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
#line 7167 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 585:
#line 7174 "Gmsh.y"
    {
      std::string tmp = SplitFileName(GetAbsolutePath(gmsh_yyname))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
    ;}
    break;

  case 586:
#line 7180 "Gmsh.y"
    {
      std::string tmp = SplitFileName((yyvsp[(3) - (4)].c))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 587:
#line 7187 "Gmsh.y"
    {
      std::string tmp = GetAbsolutePath((yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 588:
#line 7194 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 589:
#line 7196 "Gmsh.y"
    {
      std::string val((yyvsp[(3) - (6)].c));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.c) = (char*)Malloc((val.size() + 1) * sizeof(char));
      strcpy((yyval.c), val.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 590:
#line 7207 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].c)));
    ;}
    break;

  case 591:
#line 7212 "Gmsh.y"
    { List_Add((yyval.l), &((yyvsp[(3) - (3)].c))); ;}
    break;

  case 592:
#line 7218 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 593:
#line 7227 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char)) ;
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)) ; strcat((yyval.c), tmpstr) ;
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 594:
#line 7240 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 595:
#line 7243 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 596:
#line 7247 "Gmsh.y"
    { (yyval.c) = (yyvsp[(3) - (4)].c); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 14587 "Gmsh.tab.cpp"
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


#line 7250 "Gmsh.y"


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

