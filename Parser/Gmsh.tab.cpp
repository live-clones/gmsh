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
     tPlugin = 375,
     tDegenerated = 376,
     tRecursive = 377,
     tRotate = 378,
     tTranslate = 379,
     tSymmetry = 380,
     tDilate = 381,
     tExtrude = 382,
     tLevelset = 383,
     tAffine = 384,
     tBooleanUnion = 385,
     tBooleanIntersection = 386,
     tBooleanDifference = 387,
     tBooleanSection = 388,
     tBooleanFragments = 389,
     tRecombine = 390,
     tSmoother = 391,
     tSplit = 392,
     tDelete = 393,
     tCoherence = 394,
     tIntersect = 395,
     tMeshAlgorithm = 396,
     tReverse = 397,
     tLayers = 398,
     tScaleLast = 399,
     tHole = 400,
     tAlias = 401,
     tAliasWithOptions = 402,
     tCopyOptions = 403,
     tQuadTriAddVerts = 404,
     tQuadTriNoNewVerts = 405,
     tQuadTriSngl = 406,
     tQuadTriDbl = 407,
     tRecombLaterals = 408,
     tTransfQuadTri = 409,
     tText2D = 410,
     tText3D = 411,
     tInterpolationScheme = 412,
     tTime = 413,
     tCombine = 414,
     tBSpline = 415,
     tBezier = 416,
     tNurbs = 417,
     tNurbsOrder = 418,
     tNurbsKnots = 419,
     tColor = 420,
     tColorTable = 421,
     tFor = 422,
     tIn = 423,
     tEndFor = 424,
     tIf = 425,
     tElseIf = 426,
     tElse = 427,
     tEndIf = 428,
     tExit = 429,
     tAbort = 430,
     tField = 431,
     tReturn = 432,
     tCall = 433,
     tSlide = 434,
     tMacro = 435,
     tShow = 436,
     tHide = 437,
     tGetValue = 438,
     tGetStringValue = 439,
     tGetEnv = 440,
     tGetString = 441,
     tGetNumber = 442,
     tHomology = 443,
     tCohomology = 444,
     tBetti = 445,
     tExists = 446,
     tFileExists = 447,
     tGMSH_MAJOR_VERSION = 448,
     tGMSH_MINOR_VERSION = 449,
     tGMSH_PATCH_VERSION = 450,
     tGmshExecutableName = 451,
     tSetPartition = 452,
     tNameToString = 453,
     tStringToName = 454,
     tAFFECTDIVIDE = 455,
     tAFFECTTIMES = 456,
     tAFFECTMINUS = 457,
     tAFFECTPLUS = 458,
     tOR = 459,
     tAND = 460,
     tNOTEQUAL = 461,
     tEQUAL = 462,
     tGREATEROREQUAL = 463,
     tLESSOREQUAL = 464,
     UNARYPREC = 465,
     tMINUSMINUS = 466,
     tPLUSPLUS = 467
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
#define tPlugin 375
#define tDegenerated 376
#define tRecursive 377
#define tRotate 378
#define tTranslate 379
#define tSymmetry 380
#define tDilate 381
#define tExtrude 382
#define tLevelset 383
#define tAffine 384
#define tBooleanUnion 385
#define tBooleanIntersection 386
#define tBooleanDifference 387
#define tBooleanSection 388
#define tBooleanFragments 389
#define tRecombine 390
#define tSmoother 391
#define tSplit 392
#define tDelete 393
#define tCoherence 394
#define tIntersect 395
#define tMeshAlgorithm 396
#define tReverse 397
#define tLayers 398
#define tScaleLast 399
#define tHole 400
#define tAlias 401
#define tAliasWithOptions 402
#define tCopyOptions 403
#define tQuadTriAddVerts 404
#define tQuadTriNoNewVerts 405
#define tQuadTriSngl 406
#define tQuadTriDbl 407
#define tRecombLaterals 408
#define tTransfQuadTri 409
#define tText2D 410
#define tText3D 411
#define tInterpolationScheme 412
#define tTime 413
#define tCombine 414
#define tBSpline 415
#define tBezier 416
#define tNurbs 417
#define tNurbsOrder 418
#define tNurbsKnots 419
#define tColor 420
#define tColorTable 421
#define tFor 422
#define tIn 423
#define tEndFor 424
#define tIf 425
#define tElseIf 426
#define tElse 427
#define tEndIf 428
#define tExit 429
#define tAbort 430
#define tField 431
#define tReturn 432
#define tCall 433
#define tSlide 434
#define tMacro 435
#define tShow 436
#define tHide 437
#define tGetValue 438
#define tGetStringValue 439
#define tGetEnv 440
#define tGetString 441
#define tGetNumber 442
#define tHomology 443
#define tCohomology 444
#define tBetti 445
#define tExists 446
#define tFileExists 447
#define tGMSH_MAJOR_VERSION 448
#define tGMSH_MINOR_VERSION 449
#define tGMSH_PATCH_VERSION 450
#define tGmshExecutableName 451
#define tSetPartition 452
#define tNameToString 453
#define tStringToName 454
#define tAFFECTDIVIDE 455
#define tAFFECTTIMES 456
#define tAFFECTMINUS 457
#define tAFFECTPLUS 458
#define tOR 459
#define tAND 460
#define tNOTEQUAL 461
#define tEQUAL 462
#define tGREATEROREQUAL 463
#define tLESSOREQUAL 464
#define UNARYPREC 465
#define tMINUSMINUS 466
#define tPLUSPLUS 467




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
#line 654 "Gmsh.tab.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 667 "Gmsh.tab.cpp"

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
#define YYLAST   13785

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  233
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  105
/* YYNRULES -- Number of rules.  */
#define YYNRULES  591
/* YYNRULES -- Number of states.  */
#define YYNSTATES  2193

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   467

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   218,     2,   228,     2,   217,     2,     2,
     223,   224,   215,   213,   229,   214,   227,   216,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     209,     2,   210,   204,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   225,     2,   226,   222,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   230,     2,   231,   232,     2,     2,     2,
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
     195,   196,   197,   198,   199,   200,   201,   202,   203,   205,
     206,   207,   208,   211,   212,   219,   220,   221
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
    1109,  1118,  1123,  1132,  1145,  1154,  1163,  1171,  1179,  1184,
    1193,  1202,  1208,  1220,  1226,  1236,  1246,  1251,  1261,  1271,
    1273,  1275,  1276,  1279,  1286,  1293,  1300,  1307,  1316,  1327,
    1342,  1359,  1372,  1387,  1402,  1417,  1432,  1441,  1450,  1457,
    1462,  1469,  1476,  1480,  1485,  1491,  1498,  1504,  1508,  1512,
    1517,  1523,  1528,  1534,  1538,  1544,  1552,  1560,  1564,  1572,
    1576,  1579,  1582,  1585,  1588,  1591,  1607,  1610,  1613,  1616,
    1619,  1622,  1639,  1651,  1658,  1667,  1676,  1687,  1689,  1692,
    1695,  1697,  1701,  1705,  1710,  1715,  1717,  1719,  1725,  1737,
    1751,  1752,  1760,  1761,  1775,  1776,  1792,  1793,  1800,  1810,
    1819,  1828,  1837,  1850,  1863,  1876,  1891,  1906,  1921,  1922,
    1935,  1936,  1949,  1950,  1963,  1964,  1981,  1982,  1999,  2000,
    2017,  2018,  2037,  2038,  2057,  2058,  2077,  2079,  2082,  2088,
    2096,  2106,  2109,  2112,  2116,  2119,  2123,  2126,  2130,  2133,
    2137,  2140,  2144,  2154,  2161,  2163,  2165,  2167,  2169,  2171,
    2172,  2175,  2179,  2189,  2194,  2209,  2210,  2214,  2215,  2217,
    2218,  2221,  2222,  2225,  2226,  2229,  2237,  2244,  2253,  2259,
    2263,  2272,  2278,  2283,  2290,  2302,  2314,  2333,  2352,  2365,
    2378,  2391,  2402,  2413,  2424,  2435,  2446,  2451,  2456,  2461,
    2466,  2471,  2474,  2478,  2485,  2487,  2489,  2491,  2494,  2500,
    2508,  2519,  2521,  2525,  2528,  2531,  2534,  2538,  2542,  2546,
    2550,  2554,  2558,  2562,  2566,  2570,  2574,  2578,  2582,  2586,
    2590,  2596,  2601,  2606,  2611,  2616,  2621,  2626,  2631,  2636,
    2641,  2646,  2653,  2658,  2663,  2668,  2673,  2678,  2683,  2688,
    2695,  2702,  2709,  2714,  2716,  2718,  2720,  2722,  2724,  2726,
    2728,  2730,  2732,  2734,  2736,  2737,  2744,  2749,  2756,  2758,
    2763,  2768,  2773,  2778,  2783,  2788,  2793,  2796,  2802,  2808,
    2814,  2820,  2824,  2831,  2836,  2844,  2851,  2858,  2865,  2870,
    2877,  2882,  2884,  2887,  2890,  2894,  2898,  2910,  2920,  2928,
    2936,  2938,  2942,  2944,  2946,  2949,  2953,  2958,  2964,  2966,
    2968,  2971,  2975,  2979,  2985,  2990,  2993,  2996,  2999,  3002,
    3006,  3010,  3014,  3018,  3024,  3030,  3036,  3042,  3059,  3076,
    3093,  3110,  3112,  3114,  3116,  3120,  3124,  3129,  3134,  3139,
    3146,  3153,  3160,  3167,  3176,  3185,  3190,  3205,  3207,  3209,
    3213,  3217,  3227,  3235,  3237,  3243,  3247,  3254,  3256,  3260,
    3262,  3264,  3269,  3274,  3279,  3284,  3288,  3295,  3297,  3302,
    3304,  3306,  3308,  3313,  3320,  3325,  3332,  3337,  3342,  3347,
    3356,  3361,  3366,  3371,  3376,  3385,  3394,  3401,  3406,  3413,
    3418,  3420,  3425,  3430,  3431,  3438,  3440,  3444,  3450,  3456,
    3458,  3460
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     234,     0,    -1,   235,    -1,     1,     6,    -1,    -1,   235,
     236,    -1,   239,    -1,   238,    -1,   259,    -1,   278,    -1,
     279,    -1,   283,    -1,   284,    -1,   285,    -1,   286,    -1,
     290,    -1,   308,    -1,   309,    -1,   315,    -1,   316,    -1,
     289,    -1,   288,    -1,   287,    -1,   282,    -1,   318,    -1,
     210,    -1,   210,   210,    -1,    42,   223,   332,   224,     6,
      -1,    43,   223,   332,   224,     6,    -1,    42,   223,   332,
     224,   237,   332,     6,    -1,    42,   223,   332,   229,   328,
     224,     6,    -1,    43,   223,   332,   229,   328,   224,     6,
      -1,    42,   223,   332,   229,   328,   224,   237,   332,     6,
      -1,     4,   332,   230,   240,   231,     6,    -1,   146,     4,
     225,   319,   226,     6,    -1,   147,     4,   225,   319,   226,
       6,    -1,   148,     4,   225,   319,   229,   319,   226,     6,
      -1,    -1,   240,   243,    -1,   240,   247,    -1,   240,   250,
      -1,   240,   252,    -1,   240,   253,    -1,   319,    -1,   241,
     229,   319,    -1,   319,    -1,   242,   229,   319,    -1,    -1,
      -1,     4,   244,   223,   241,   224,   245,   230,   242,   231,
       6,    -1,   332,    -1,   246,   229,   332,    -1,    -1,   155,
     223,   319,   229,   319,   229,   319,   224,   248,   230,   246,
     231,     6,    -1,   332,    -1,   249,   229,   332,    -1,    -1,
     156,   223,   319,   229,   319,   229,   319,   229,   319,   224,
     251,   230,   249,   231,     6,    -1,   157,   230,   324,   231,
     230,   324,   231,     6,    -1,   157,   230,   324,   231,   230,
     324,   231,   230,   324,   231,   230,   324,   231,     6,    -1,
      -1,   158,   254,   230,   242,   231,     6,    -1,     7,    -1,
     203,    -1,   202,    -1,   201,    -1,   200,    -1,   221,    -1,
     220,    -1,   223,    -1,   225,    -1,   224,    -1,   226,    -1,
      78,   225,   261,   226,     6,    -1,    79,   225,   266,   226,
       6,    -1,    82,   257,   333,   229,   319,   258,     6,    -1,
      83,   257,   337,   229,   333,   258,     6,    -1,   337,   255,
     325,     6,    -1,   337,   256,     6,    -1,     4,   225,   226,
     255,   325,     6,    -1,   336,   225,   226,   255,   325,     6,
      -1,     4,   225,   319,   226,   255,   319,     6,    -1,   336,
     225,   319,   226,   255,   319,     6,    -1,     4,   225,   319,
     226,   256,     6,    -1,   336,   225,   319,   226,   256,     6,
      -1,     4,   257,   230,   328,   231,   258,   255,   325,     6,
      -1,   336,   257,   230,   328,   231,   258,   255,   325,     6,
      -1,     4,   223,   224,   255,   325,     6,    -1,   336,   223,
     224,   255,   325,     6,    -1,     4,   223,   319,   224,   255,
     319,     6,    -1,   336,   223,   319,   224,   255,   319,     6,
      -1,     4,   223,   319,   224,   256,     6,    -1,   336,   223,
     319,   224,   256,     6,    -1,   337,     7,   333,     6,    -1,
       4,   225,   226,     7,    44,   257,   258,     6,    -1,   336,
     225,   226,     7,    44,   257,   258,     6,    -1,     4,   225,
     226,     7,    44,   257,   335,   258,     6,    -1,   336,   225,
     226,     7,    44,   257,   335,   258,     6,    -1,     4,   225,
     226,   203,    44,   257,   335,   258,     6,    -1,   336,   225,
     226,   203,    44,   257,   335,   258,     6,    -1,     4,   223,
     224,     7,    44,   257,   258,     6,    -1,   336,   223,   224,
       7,    44,   257,   258,     6,    -1,     4,   223,   224,     7,
      44,   257,   335,   258,     6,    -1,   336,   223,   224,     7,
      44,   257,   335,   258,     6,    -1,     4,   223,   224,   203,
      44,   257,   335,   258,     6,    -1,   336,   223,   224,   203,
      44,   257,   335,   258,     6,    -1,     4,   227,     4,     7,
     333,     6,    -1,     4,   225,   319,   226,   227,     4,     7,
     333,     6,    -1,     4,   227,     4,   255,   319,     6,    -1,
       4,   225,   319,   226,   227,     4,   255,   319,     6,    -1,
       4,   227,     4,   256,     6,    -1,     4,   225,   319,   226,
     227,     4,   256,     6,    -1,     4,   227,   165,   227,     4,
       7,   329,     6,    -1,     4,   225,   319,   226,   227,   165,
     227,     4,     7,   329,     6,    -1,     4,   227,   166,     7,
     330,     6,    -1,     4,   225,   319,   226,   227,   166,     7,
     330,     6,    -1,     4,   176,     7,   319,     6,    -1,   176,
     225,   319,   226,     7,     4,     6,    -1,   176,   225,   319,
     226,   227,     4,     7,   319,     6,    -1,   176,   225,   319,
     226,   227,     4,     7,   333,     6,    -1,   176,   225,   319,
     226,   227,     4,     7,   230,   328,   231,     6,    -1,   176,
     225,   319,   226,   227,     4,     6,    -1,   120,   223,     4,
     224,   227,     4,     7,   319,     6,    -1,   120,   223,     4,
     224,   227,     4,     7,   333,     6,    -1,    -1,   229,    -1,
      -1,   261,   260,   337,    -1,   261,   260,   337,     7,   319,
      -1,    -1,   261,   260,   337,     7,   230,   325,   262,   268,
     231,    -1,    -1,   261,   260,   337,   225,   226,     7,   230,
     325,   263,   268,   231,    -1,    -1,   261,   260,   337,   223,
     224,     7,   230,   325,   264,   268,   231,    -1,   261,   260,
     337,     7,   333,    -1,    -1,   261,   260,   337,     7,   230,
     333,   265,   270,   231,    -1,    -1,   266,   260,   332,    -1,
     319,     7,   333,    -1,   267,   229,   319,     7,   333,    -1,
     327,     7,   337,   223,   224,    -1,    -1,   268,   269,    -1,
     229,     4,   325,    -1,   229,     4,   230,   267,   231,    -1,
     229,     4,   333,    -1,    -1,   270,   271,    -1,   229,     4,
     319,    -1,   229,     4,   333,    -1,   229,   180,   333,    -1,
     229,     4,   230,   335,   231,    -1,   319,    -1,   333,    -1,
     333,   229,   319,    -1,   319,    -1,   333,    -1,   333,   229,
     319,    -1,   319,    -1,   333,    -1,   333,   229,   319,    -1,
     319,    -1,   333,    -1,   333,   229,   319,    -1,    -1,   168,
      88,   230,   319,   231,    -1,    -1,   112,   322,    -1,   109,
     223,   332,   224,     6,    -1,    84,   223,   319,   224,     7,
     322,     6,    -1,   116,    84,   223,   272,   224,   255,   325,
       6,    -1,   102,   103,   325,     7,   319,     6,    -1,    87,
     223,   319,   224,     7,   325,     6,    -1,   121,    87,   325,
       6,    -1,    91,   223,   319,   224,     7,   325,     6,    -1,
      85,   223,   319,   224,     7,   325,   277,     6,    -1,    86,
     223,   319,   224,     7,   325,   277,     6,    -1,   160,   223,
     319,   224,     7,   325,     6,    -1,   161,   223,   319,   224,
       7,   325,     6,    -1,   162,   223,   319,   224,     7,   325,
     164,   325,   163,   319,     6,    -1,    87,     4,   223,   319,
     224,     7,   325,     6,    -1,   117,    87,   325,     6,    -1,
     117,    87,   223,   319,   224,     7,   325,     6,    -1,   116,
      87,   223,   273,   224,   255,   325,     6,    -1,   112,    90,
     223,   319,   224,     7,   325,     6,    -1,   113,    90,   223,
     319,   224,     7,   325,   276,     6,    -1,    12,    13,     6,
      -1,    13,    90,   319,     6,    -1,   104,    90,   223,   319,
     224,     7,     5,     5,     5,     6,    -1,    88,   223,   319,
     224,     7,   325,     6,    -1,    89,   223,   319,   224,     7,
     325,     6,    -1,    93,   223,   319,   224,     7,   325,     6,
      -1,    96,   223,   319,   224,     7,   325,     6,    -1,   100,
     223,   319,   224,     7,   325,     6,    -1,   101,   223,   319,
     224,     7,   325,     6,    -1,    94,   223,   319,   224,     7,
     325,     6,    -1,    95,   223,   319,   224,     7,   325,     6,
      -1,   111,   223,   319,   224,     7,   325,     6,    -1,    90,
       4,   223,   319,   224,     7,   325,     6,    -1,   117,    90,
     325,     6,    -1,   117,    90,   223,   319,   224,     7,   325,
       6,    -1,   117,    90,   223,   319,   224,     7,   325,     4,
     230,   324,   231,     6,    -1,   116,    90,   223,   274,   224,
     255,   325,     6,    -1,   115,    92,   223,   319,   224,     7,
     325,     6,    -1,    92,   223,   319,   224,     7,   325,     6,
      -1,   110,   223,   319,   224,     7,   325,     6,    -1,   117,
      92,   325,     6,    -1,   117,    92,   223,   319,   224,     7,
     325,     6,    -1,   116,    92,   223,   275,   224,   255,   325,
       6,    -1,   124,   322,   230,   280,   231,    -1,   123,   230,
     322,   229,   322,   229,   319,   231,   230,   280,   231,    -1,
     125,   322,   230,   280,   231,    -1,   126,   230,   322,   229,
     319,   231,   230,   280,   231,    -1,   126,   230,   322,   229,
     322,   231,   230,   280,   231,    -1,     4,   230,   280,   231,
      -1,   140,    87,   230,   328,   231,    90,   230,   319,   231,
      -1,   137,    87,   223,   319,   224,   230,   328,   231,     6,
      -1,   281,    -1,   279,    -1,    -1,   281,   278,    -1,   281,
      84,   230,   328,   231,     6,    -1,   281,    87,   230,   328,
     231,     6,    -1,   281,    90,   230,   328,   231,     6,    -1,
     281,    92,   230,   328,   231,     6,    -1,   128,   112,   223,
     319,   224,     7,   325,     6,    -1,   128,    84,   223,   319,
     224,     7,   230,   324,   231,     6,    -1,   128,   112,   223,
     319,   224,     7,   230,   322,   229,   322,   229,   328,   231,
       6,    -1,   128,   112,   223,   319,   224,     7,   230,   322,
     229,   322,   229,   322,   229,   328,   231,     6,    -1,   128,
      88,   223,   319,   224,     7,   230,   322,   229,   328,   231,
       6,    -1,   128,    94,   223,   319,   224,     7,   230,   322,
     229,   322,   229,   328,   231,     6,    -1,   128,    95,   223,
     319,   224,     7,   230,   322,   229,   322,   229,   328,   231,
       6,    -1,   128,    97,   223,   319,   224,     7,   230,   322,
     229,   322,   229,   328,   231,     6,    -1,   128,    98,   223,
     319,   224,     7,   230,   322,   229,   322,   229,   328,   231,
       6,    -1,   128,     4,   223,   319,   224,     7,   325,     6,
      -1,   128,     4,   223,   319,   224,     7,     5,     6,    -1,
     128,     4,   230,   319,   231,     6,    -1,   138,   230,   281,
     231,    -1,   138,   176,   225,   319,   226,     6,    -1,   138,
       4,   225,   319,   226,     6,    -1,   138,   337,     6,    -1,
     138,     4,     4,     6,    -1,   165,   329,   230,   281,   231,
      -1,   122,   165,   329,   230,   281,   231,    -1,   197,   319,
     230,   281,   231,    -1,   181,     5,     6,    -1,   182,     5,
       6,    -1,   181,   230,   281,   231,    -1,   122,   181,   230,
     281,   231,    -1,   182,   230,   281,   231,    -1,   122,   182,
     230,   281,   231,    -1,     4,   333,     6,    -1,    71,   223,
     335,   224,     6,    -1,     4,     4,   225,   319,   226,   332,
       6,    -1,     4,     4,     4,   225,   319,   226,     6,    -1,
       4,   319,     6,    -1,   120,   223,     4,   224,   227,     4,
       6,    -1,   159,     4,     6,    -1,   174,     6,    -1,   175,
       6,    -1,    68,     6,    -1,    69,     6,    -1,    62,     6,
      -1,    62,   230,   319,   229,   319,   229,   319,   229,   319,
     229,   319,   229,   319,   231,     6,    -1,    63,     6,    -1,
      64,     6,    -1,    75,     6,    -1,    76,     6,    -1,   106,
       6,    -1,   107,   230,   328,   231,   230,   328,   231,   230,
     324,   231,   230,   319,   229,   319,   231,     6,    -1,   179,
     223,   230,   328,   231,   229,   333,   229,   333,   224,     6,
      -1,   167,   223,   319,     8,   319,   224,    -1,   167,   223,
     319,     8,   319,     8,   319,   224,    -1,   167,     4,   168,
     230,   319,     8,   319,   231,    -1,   167,     4,   168,   230,
     319,     8,   319,     8,   319,   231,    -1,   169,    -1,   180,
       4,    -1,   180,   333,    -1,   177,    -1,   178,   337,     6,
      -1,   178,   333,     6,    -1,   170,   223,   319,   224,    -1,
     171,   223,   319,   224,    -1,   172,    -1,   173,    -1,   127,
     322,   230,   281,   231,    -1,   127,   230,   322,   229,   322,
     229,   319,   231,   230,   281,   231,    -1,   127,   230,   322,
     229,   322,   229,   322,   229,   319,   231,   230,   281,   231,
      -1,    -1,   127,   322,   230,   281,   291,   304,   231,    -1,
      -1,   127,   230,   322,   229,   322,   229,   319,   231,   230,
     281,   292,   304,   231,    -1,    -1,   127,   230,   322,   229,
     322,   229,   322,   229,   319,   231,   230,   281,   293,   304,
     231,    -1,    -1,   127,   230,   281,   294,   304,   231,    -1,
     127,   230,   281,   231,   119,    87,   230,   325,   231,    -1,
     127,    84,   230,   319,   229,   322,   231,     6,    -1,   127,
      87,   230,   319,   229,   322,   231,     6,    -1,   127,    90,
     230,   319,   229,   322,   231,     6,    -1,   127,    84,   230,
     319,   229,   322,   229,   322,   229,   319,   231,     6,    -1,
     127,    87,   230,   319,   229,   322,   229,   322,   229,   319,
     231,     6,    -1,   127,    90,   230,   319,   229,   322,   229,
     322,   229,   319,   231,     6,    -1,   127,    84,   230,   319,
     229,   322,   229,   322,   229,   322,   229,   319,   231,     6,
      -1,   127,    87,   230,   319,   229,   322,   229,   322,   229,
     322,   229,   319,   231,     6,    -1,   127,    90,   230,   319,
     229,   322,   229,   322,   229,   322,   229,   319,   231,     6,
      -1,    -1,   127,    84,   230,   319,   229,   322,   231,   295,
     230,   304,   231,     6,    -1,    -1,   127,    87,   230,   319,
     229,   322,   231,   296,   230,   304,   231,     6,    -1,    -1,
     127,    90,   230,   319,   229,   322,   231,   297,   230,   304,
     231,     6,    -1,    -1,   127,    84,   230,   319,   229,   322,
     229,   322,   229,   319,   231,   298,   230,   304,   231,     6,
      -1,    -1,   127,    87,   230,   319,   229,   322,   229,   322,
     229,   319,   231,   299,   230,   304,   231,     6,    -1,    -1,
     127,    90,   230,   319,   229,   322,   229,   322,   229,   319,
     231,   300,   230,   304,   231,     6,    -1,    -1,   127,    84,
     230,   319,   229,   322,   229,   322,   229,   322,   229,   319,
     231,   301,   230,   304,   231,     6,    -1,    -1,   127,    87,
     230,   319,   229,   322,   229,   322,   229,   322,   229,   319,
     231,   302,   230,   304,   231,     6,    -1,    -1,   127,    90,
     230,   319,   229,   322,   229,   322,   229,   322,   229,   319,
     231,   303,   230,   304,   231,     6,    -1,   305,    -1,   304,
     305,    -1,   143,   230,   319,   231,     6,    -1,   143,   230,
     325,   229,   325,   231,     6,    -1,   143,   230,   325,   229,
     325,   229,   325,   231,     6,    -1,   144,     6,    -1,   135,
       6,    -1,   135,   319,     6,    -1,   151,     6,    -1,   151,
     153,     6,    -1,   152,     6,    -1,   152,   153,     6,    -1,
     149,     6,    -1,   149,   153,     6,    -1,   150,     6,    -1,
     150,   153,     6,    -1,   145,   223,   319,   224,     7,   325,
     119,   319,     6,    -1,   119,     4,   225,   319,   226,     6,
      -1,   130,    -1,   131,    -1,   132,    -1,   133,    -1,   134,
      -1,    -1,   138,     6,    -1,   138,   319,     6,    -1,   306,
     230,   281,   307,   231,   230,   281,   307,   231,    -1,    99,
     223,   332,   224,    -1,   306,   223,   319,   224,     7,   230,
     281,   307,   231,   230,   281,   307,   231,     6,    -1,    -1,
     119,     4,   319,    -1,    -1,     4,    -1,    -1,     7,   325,
      -1,    -1,     7,   319,    -1,    -1,   129,   325,    -1,   114,
      87,   326,     7,   319,   310,     6,    -1,   114,    90,   326,
     312,   311,     6,    -1,   105,    90,   230,   319,   231,     7,
     325,     6,    -1,   114,    92,   326,   312,     6,    -1,   154,
     326,     6,    -1,   141,    90,   230,   328,   231,     7,   319,
       6,    -1,   135,    90,   326,   313,     6,    -1,   135,    92,
     326,     6,    -1,   136,    90,   325,     7,   319,     6,    -1,
     118,    87,   230,   328,   231,     7,   230,   328,   231,   314,
       6,    -1,   118,    90,   230,   328,   231,     7,   230,   328,
     231,   314,     6,    -1,   118,    87,   230,   328,   231,     7,
     230,   328,   231,   123,   230,   322,   229,   322,   229,   319,
     231,     6,    -1,   118,    90,   230,   328,   231,     7,   230,
     328,   231,   123,   230,   322,   229,   322,   229,   319,   231,
       6,    -1,   118,    87,   230,   328,   231,     7,   230,   328,
     231,   124,   322,     6,    -1,   118,    90,   230,   328,   231,
       7,   230,   328,   231,   124,   322,     6,    -1,   118,    90,
     319,   230,   328,   231,     7,   319,   230,   328,   231,     6,
      -1,    84,   230,   328,   231,   168,    90,   230,   319,   231,
       6,    -1,    87,   230,   328,   231,   168,    90,   230,   319,
     231,     6,    -1,    84,   230,   328,   231,   168,    92,   230,
     319,   231,     6,    -1,    87,   230,   328,   231,   168,    92,
     230,   319,   231,     6,    -1,    90,   230,   328,   231,   168,
      92,   230,   319,   231,     6,    -1,   142,    90,   326,     6,
      -1,   142,    87,   326,     6,    -1,   108,    84,   326,     6,
      -1,   108,    87,   326,     6,    -1,   108,    90,   326,     6,
      -1,   139,     6,    -1,   139,     4,     6,    -1,   139,    84,
     230,   328,   231,     6,    -1,   188,    -1,   189,    -1,   190,
      -1,   317,     6,    -1,   317,   230,   325,   231,     6,    -1,
     317,   230,   325,   229,   325,   231,     6,    -1,   317,   223,
     325,   224,   230,   325,   229,   325,   231,     6,    -1,   320,
      -1,   223,   319,   224,    -1,   214,   319,    -1,   213,   319,
      -1,   218,   319,    -1,   319,   214,   319,    -1,   319,   213,
     319,    -1,   319,   215,   319,    -1,   319,   216,   319,    -1,
     319,   217,   319,    -1,   319,   222,   319,    -1,   319,   209,
     319,    -1,   319,   210,   319,    -1,   319,   212,   319,    -1,
     319,   211,   319,    -1,   319,   208,   319,    -1,   319,   207,
     319,    -1,   319,   206,   319,    -1,   319,   205,   319,    -1,
     319,   204,   319,     8,   319,    -1,    15,   257,   319,   258,
      -1,    16,   257,   319,   258,    -1,    17,   257,   319,   258,
      -1,    18,   257,   319,   258,    -1,    19,   257,   319,   258,
      -1,    20,   257,   319,   258,    -1,    21,   257,   319,   258,
      -1,    22,   257,   319,   258,    -1,    23,   257,   319,   258,
      -1,    25,   257,   319,   258,    -1,    26,   257,   319,   229,
     319,   258,    -1,    27,   257,   319,   258,    -1,    28,   257,
     319,   258,    -1,    29,   257,   319,   258,    -1,    30,   257,
     319,   258,    -1,    31,   257,   319,   258,    -1,    32,   257,
     319,   258,    -1,    33,   257,   319,   258,    -1,    34,   257,
     319,   229,   319,   258,    -1,    35,   257,   319,   229,   319,
     258,    -1,    36,   257,   319,   229,   319,   258,    -1,    24,
     257,   319,   258,    -1,     3,    -1,     9,    -1,    14,    -1,
      10,    -1,    11,    -1,   193,    -1,   194,    -1,   195,    -1,
      72,    -1,    73,    -1,    74,    -1,    -1,    80,   257,   319,
     321,   268,   258,    -1,   187,   257,   332,   258,    -1,   187,
     257,   332,   229,   319,   258,    -1,   337,    -1,     4,   225,
     319,   226,    -1,     4,   223,   319,   224,    -1,   336,   225,
     319,   226,    -1,   336,   223,   319,   224,    -1,   191,   223,
     337,   224,    -1,   192,   223,   333,   224,    -1,   228,   337,
     257,   258,    -1,   337,   256,    -1,     4,   225,   319,   226,
     256,    -1,     4,   223,   319,   224,   256,    -1,   336,   225,
     319,   226,   256,    -1,   336,   223,   319,   224,   256,    -1,
       4,   227,     4,    -1,     4,   225,   319,   226,   227,     4,
      -1,     4,   227,     4,   256,    -1,     4,   225,   319,   226,
     227,     4,   256,    -1,   183,   223,   332,   229,   319,   224,
      -1,    54,   223,   325,   229,   325,   224,    -1,    55,   257,
     332,   229,   332,   258,    -1,    53,   257,   332,   258,    -1,
      56,   257,   332,   229,   332,   258,    -1,    61,   223,   335,
     224,    -1,   323,    -1,   214,   322,    -1,   213,   322,    -1,
     322,   214,   322,    -1,   322,   213,   322,    -1,   230,   319,
     229,   319,   229,   319,   229,   319,   229,   319,   231,    -1,
     230,   319,   229,   319,   229,   319,   229,   319,   231,    -1,
     230,   319,   229,   319,   229,   319,   231,    -1,   223,   319,
     229,   319,   229,   319,   224,    -1,   325,    -1,   324,   229,
     325,    -1,   319,    -1,   327,    -1,   230,   231,    -1,   230,
     328,   231,    -1,   214,   230,   328,   231,    -1,   319,   215,
     230,   328,   231,    -1,   325,    -1,     5,    -1,   214,   327,
      -1,   319,   215,   327,    -1,   319,     8,   319,    -1,   319,
       8,   319,     8,   319,    -1,    84,   230,   319,   231,    -1,
      84,     5,    -1,    87,     5,    -1,    90,     5,    -1,    92,
       5,    -1,   116,    84,     5,    -1,   116,    87,     5,    -1,
     116,    90,     5,    -1,   116,    92,     5,    -1,   116,    84,
     230,   328,   231,    -1,   116,    87,   230,   328,   231,    -1,
     116,    90,   230,   328,   231,    -1,   116,    92,   230,   328,
     231,    -1,    84,   168,    62,   230,   319,   229,   319,   229,
     319,   229,   319,   229,   319,   229,   319,   231,    -1,    87,
     168,    62,   230,   319,   229,   319,   229,   319,   229,   319,
     229,   319,   229,   319,   231,    -1,    90,   168,    62,   230,
     319,   229,   319,   229,   319,   229,   319,   229,   319,   229,
     319,   231,    -1,    92,   168,    62,   230,   319,   229,   319,
     229,   319,   229,   319,   229,   319,   229,   319,   231,    -1,
     279,    -1,   290,    -1,   308,    -1,     4,   257,   258,    -1,
     336,   257,   258,    -1,    37,   225,   337,   226,    -1,    37,
     225,   327,   226,    -1,    37,   223,   327,   224,    -1,    37,
     225,   230,   328,   231,   226,    -1,    37,   223,   230,   328,
     231,   224,    -1,     4,   257,   230,   328,   231,   258,    -1,
     336,   257,   230,   328,   231,   258,    -1,    38,   257,   319,
     229,   319,   229,   319,   258,    -1,    39,   257,   319,   229,
     319,   229,   319,   258,    -1,    40,   257,   332,   258,    -1,
      41,   257,   319,   229,   319,   229,   319,   229,   319,   229,
     319,   229,   319,   258,    -1,   319,    -1,   327,    -1,   328,
     229,   319,    -1,   328,   229,   327,    -1,   230,   319,   229,
     319,   229,   319,   229,   319,   231,    -1,   230,   319,   229,
     319,   229,   319,   231,    -1,   337,    -1,     4,   227,   165,
     227,     4,    -1,   230,   331,   231,    -1,     4,   225,   319,
     226,   227,   166,    -1,   329,    -1,   331,   229,   329,    -1,
     333,    -1,   337,    -1,     4,   225,   319,   226,    -1,   336,
     225,   319,   226,    -1,     4,   223,   319,   224,    -1,   336,
     223,   319,   224,    -1,     4,   227,     4,    -1,     4,   225,
     319,   226,   227,     4,    -1,     5,    -1,   198,   225,   337,
     226,    -1,    65,    -1,   196,    -1,    70,    -1,   185,   223,
     332,   224,    -1,   184,   223,   332,   229,   332,   224,    -1,
     186,   257,   332,   258,    -1,   186,   257,   332,   229,   332,
     258,    -1,    46,   257,   335,   258,    -1,    47,   223,   332,
     224,    -1,    48,   223,   332,   224,    -1,    49,   223,   332,
     229,   332,   229,   332,   224,    -1,    44,   257,   335,   258,
      -1,    58,   257,   332,   258,    -1,    59,   257,   332,   258,
      -1,    60,   257,   332,   258,    -1,    57,   257,   319,   229,
     332,   229,   332,   258,    -1,    52,   257,   332,   229,   319,
     229,   319,   258,    -1,    52,   257,   332,   229,   319,   258,
      -1,    45,   257,   332,   258,    -1,    45,   257,   332,   229,
     328,   258,    -1,    66,   257,   332,   258,    -1,    67,    -1,
      51,   257,   332,   258,    -1,    50,   257,   332,   258,    -1,
      -1,    81,   257,   333,   334,   270,   258,    -1,   332,    -1,
     335,   229,   332,    -1,     4,   232,   230,   319,   231,    -1,
     336,   232,   230,   319,   231,    -1,     4,    -1,   336,    -1,
     199,   225,   332,   226,    -1
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
    2480,  2507,  2511,  2530,  2564,  2611,  2629,  2656,  2674,  2678,
    2694,  2742,  2759,  2777,  2787,  2797,  2807,  2870,  2881,  2897,
    2898,  2903,  2906,  2910,  2939,  2968,  2997,  3031,  3053,  3079,
    3101,  3124,  3145,  3201,  3225,  3250,  3276,  3389,  3408,  3451,
    3472,  3478,  3493,  3521,  3538,  3547,  3561,  3575,  3581,  3587,
    3596,  3605,  3614,  3628,  3690,  3708,  3725,  3740,  3769,  3781,
    3805,  3809,  3814,  3822,  3827,  3833,  3838,  3844,  3852,  3856,
    3860,  3865,  3925,  3941,  3958,  3975,  3997,  4019,  4054,  4062,
    4070,  4076,  4083,  4090,  4110,  4136,  4148,  4160,  4190,  4221,
    4230,  4229,  4244,  4243,  4258,  4257,  4272,  4271,  4284,  4318,
    4325,  4332,  4339,  4346,  4353,  4360,  4367,  4374,  4382,  4381,
    4395,  4394,  4408,  4407,  4421,  4420,  4434,  4433,  4447,  4446,
    4460,  4459,  4473,  4472,  4486,  4485,  4502,  4505,  4511,  4523,
    4543,  4567,  4571,  4575,  4579,  4583,  4587,  4593,  4599,  4603,
    4607,  4611,  4615,  4634,  4647,  4648,  4649,  4650,  4651,  4655,
    4656,  4657,  4660,  4694,  4720,  4744,  4747,  4763,  4766,  4783,
    4786,  4792,  4795,  4802,  4805,  4812,  4868,  4938,  4943,  5010,
    5046,  5054,  5097,  5136,  5156,  5188,  5215,  5241,  5267,  5293,
    5319,  5341,  5369,  5397,  5425,  5453,  5481,  5520,  5559,  5580,
    5601,  5628,  5632,  5642,  5677,  5678,  5679,  5683,  5689,  5701,
    5719,  5747,  5748,  5749,  5750,  5751,  5752,  5753,  5754,  5755,
    5762,  5763,  5764,  5765,  5766,  5767,  5768,  5769,  5770,  5771,
    5772,  5773,  5774,  5775,  5776,  5777,  5778,  5779,  5780,  5781,
    5782,  5783,  5784,  5785,  5786,  5787,  5788,  5789,  5790,  5791,
    5792,  5793,  5794,  5803,  5804,  5805,  5806,  5807,  5808,  5809,
    5810,  5811,  5812,  5813,  5818,  5817,  5825,  5830,  5835,  5852,
    5870,  5888,  5906,  5924,  5929,  5935,  5950,  5969,  5989,  6009,
    6029,  6052,  6057,  6062,  6072,  6082,  6087,  6098,  6107,  6112,
    6117,  6144,  6148,  6152,  6156,  6160,  6167,  6171,  6175,  6179,
    6186,  6191,  6198,  6203,  6207,  6212,  6216,  6224,  6235,  6239,
    6251,  6259,  6267,  6274,  6284,  6313,  6317,  6321,  6325,  6329,
    6333,  6337,  6341,  6345,  6374,  6403,  6432,  6461,  6474,  6487,
    6500,  6513,  6523,  6533,  6543,  6555,  6568,  6580,  6584,  6588,
    6592,  6596,  6614,  6632,  6640,  6648,  6677,  6690,  6695,  6699,
    6703,  6715,  6719,  6731,  6748,  6758,  6762,  6777,  6782,  6789,
    6793,  6806,  6820,  6834,  6848,  6862,  6870,  6881,  6885,  6889,
    6897,  6903,  6909,  6917,  6925,  6932,  6940,  6955,  6969,  6983,
    6995,  7011,  7020,  7029,  7039,  7050,  7058,  7066,  7070,  7089,
    7096,  7102,  7109,  7117,  7116,  7129,  7134,  7140,  7149,  7162,
    7165,  7169
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
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,    63,   459,   460,   461,   462,    60,
      62,   463,   464,    43,    45,    42,    47,    37,    33,   465,
     466,   467,    94,    40,    41,    91,    93,    46,    35,    44,
     123,   125,   126
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   233,   234,   234,   235,   235,   236,   236,   236,   236,
     236,   236,   236,   236,   236,   236,   236,   236,   236,   236,
     236,   236,   236,   236,   236,   237,   237,   238,   238,   238,
     238,   238,   238,   239,   239,   239,   239,   240,   240,   240,
     240,   240,   240,   241,   241,   242,   242,   244,   245,   243,
     246,   246,   248,   247,   249,   249,   251,   250,   252,   252,
     254,   253,   255,   255,   255,   255,   255,   256,   256,   257,
     257,   258,   258,   259,   259,   259,   259,   259,   259,   259,
     259,   259,   259,   259,   259,   259,   259,   259,   259,   259,
     259,   259,   259,   259,   259,   259,   259,   259,   259,   259,
     259,   259,   259,   259,   259,   259,   259,   259,   259,   259,
     259,   259,   259,   259,   259,   259,   259,   259,   259,   259,
     259,   259,   259,   259,   260,   260,   261,   261,   261,   262,
     261,   263,   261,   264,   261,   261,   265,   261,   266,   266,
     267,   267,   267,   268,   268,   269,   269,   269,   270,   270,
     271,   271,   271,   271,   272,   272,   272,   273,   273,   273,
     274,   274,   274,   275,   275,   275,   276,   276,   277,   277,
     278,   278,   278,   278,   278,   278,   278,   278,   278,   278,
     278,   278,   278,   278,   278,   278,   278,   278,   278,   278,
     278,   278,   278,   278,   278,   278,   278,   278,   278,   278,
     278,   278,   278,   278,   278,   278,   278,   278,   278,   278,
     278,   279,   279,   279,   279,   279,   279,   279,   279,   280,
     280,   281,   281,   281,   281,   281,   281,   282,   282,   282,
     282,   282,   282,   282,   282,   282,   282,   282,   282,   283,
     283,   283,   283,   283,   284,   284,   285,   286,   286,   286,
     286,   286,   286,   287,   287,   287,   287,   287,   287,   287,
     287,   287,   287,   287,   287,   287,   287,   287,   287,   287,
     287,   287,   288,   289,   289,   289,   289,   289,   289,   289,
     289,   289,   289,   289,   289,   289,   289,   290,   290,   290,
     291,   290,   292,   290,   293,   290,   294,   290,   290,   290,
     290,   290,   290,   290,   290,   290,   290,   290,   295,   290,
     296,   290,   297,   290,   298,   290,   299,   290,   300,   290,
     301,   290,   302,   290,   303,   290,   304,   304,   305,   305,
     305,   305,   305,   305,   305,   305,   305,   305,   305,   305,
     305,   305,   305,   305,   306,   306,   306,   306,   306,   307,
     307,   307,   308,   308,   309,   310,   310,   311,   311,   312,
     312,   313,   313,   314,   314,   315,   315,   315,   315,   315,
     315,   315,   315,   315,   315,   315,   315,   315,   315,   315,
     315,   315,   315,   315,   315,   315,   315,   315,   315,   315,
     315,   316,   316,   316,   317,   317,   317,   318,   318,   318,
     318,   319,   319,   319,   319,   319,   319,   319,   319,   319,
     319,   319,   319,   319,   319,   319,   319,   319,   319,   319,
     319,   319,   319,   319,   319,   319,   319,   319,   319,   319,
     319,   319,   319,   319,   319,   319,   319,   319,   319,   319,
     319,   319,   319,   320,   320,   320,   320,   320,   320,   320,
     320,   320,   320,   320,   321,   320,   320,   320,   320,   320,
     320,   320,   320,   320,   320,   320,   320,   320,   320,   320,
     320,   320,   320,   320,   320,   320,   320,   320,   320,   320,
     320,   322,   322,   322,   322,   322,   323,   323,   323,   323,
     324,   324,   325,   325,   325,   325,   325,   325,   326,   326,
     327,   327,   327,   327,   327,   327,   327,   327,   327,   327,
     327,   327,   327,   327,   327,   327,   327,   327,   327,   327,
     327,   327,   327,   327,   327,   327,   327,   327,   327,   327,
     327,   327,   327,   327,   327,   327,   327,   328,   328,   328,
     328,   329,   329,   329,   329,   330,   330,   331,   331,   332,
     332,   332,   332,   332,   332,   332,   332,   333,   333,   333,
     333,   333,   333,   333,   333,   333,   333,   333,   333,   333,
     333,   333,   333,   333,   333,   333,   333,   333,   333,   333,
     333,   333,   333,   334,   333,   335,   335,   336,   336,   337,
     337,   337
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
       8,     4,     8,    12,     8,     8,     7,     7,     4,     8,
       8,     5,    11,     5,     9,     9,     4,     9,     9,     1,
       1,     0,     2,     6,     6,     6,     6,     8,    10,    14,
      16,    12,    14,    14,    14,    14,     8,     8,     6,     4,
       6,     6,     3,     4,     5,     6,     5,     3,     3,     4,
       5,     4,     5,     3,     5,     7,     7,     3,     7,     3,
       2,     2,     2,     2,     2,    15,     2,     2,     2,     2,
       2,    16,    11,     6,     8,     8,    10,     1,     2,     2,
       1,     3,     3,     4,     4,     1,     1,     5,    11,    13,
       0,     7,     0,    13,     0,    15,     0,     6,     9,     8,
       8,     8,    12,    12,    12,    14,    14,    14,     0,    12,
       0,    12,     0,    12,     0,    16,     0,    16,     0,    16,
       0,    18,     0,    18,     0,    18,     1,     2,     5,     7,
       9,     2,     2,     3,     2,     3,     2,     3,     2,     3,
       2,     3,     9,     6,     1,     1,     1,     1,     1,     0,
       2,     3,     9,     4,    14,     0,     3,     0,     1,     0,
       2,     0,     2,     0,     2,     7,     6,     8,     5,     3,
       8,     5,     4,     6,    11,    11,    18,    18,    12,    12,
      12,    10,    10,    10,    10,    10,     4,     4,     4,     4,
       4,     2,     3,     6,     1,     1,     1,     2,     5,     7,
      10,     1,     3,     2,     2,     2,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       5,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     6,     4,     4,     4,     4,     4,     4,     4,     6,
       6,     6,     4,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     6,     4,     6,     1,     4,
       4,     4,     4,     4,     4,     4,     2,     5,     5,     5,
       5,     3,     6,     4,     7,     6,     6,     6,     4,     6,
       4,     1,     2,     2,     3,     3,    11,     9,     7,     7,
       1,     3,     1,     1,     2,     3,     4,     5,     1,     1,
       2,     3,     3,     5,     4,     2,     2,     2,     2,     3,
       3,     3,     3,     5,     5,     5,     5,    16,    16,    16,
      16,     1,     1,     1,     3,     3,     4,     4,     4,     6,
       6,     6,     6,     8,     8,     4,    14,     1,     1,     3,
       3,     9,     7,     1,     5,     3,     6,     1,     3,     1,
       1,     4,     4,     4,     4,     3,     6,     1,     4,     1,
       1,     1,     4,     6,     4,     6,     4,     4,     4,     8,
       4,     4,     4,     4,     8,     8,     6,     4,     6,     4,
       1,     4,     4,     0,     6,     1,     3,     5,     5,     1,
       1,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     2,     3,     1,   589,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   344,   345,   346,   347,   348,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   277,     0,     0,
     285,   286,     0,     0,     0,   280,     0,     0,     0,     0,
       0,   394,   395,   396,     0,     0,     5,     7,     6,     8,
       9,    10,    23,    11,    12,    13,    14,    22,    21,    20,
      15,     0,    16,    17,    18,    19,     0,    24,   590,     0,
     443,   589,   557,   444,   446,   447,   445,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   559,     0,   580,
     561,   451,   452,   453,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   448,   449,   450,   560,     0,     0,
       0,     0,    69,    70,     0,     0,   221,     0,     0,     0,
     401,     0,   549,   590,   458,     0,     0,     0,     0,   264,
       0,   266,   267,   262,   263,     0,   268,   269,   126,   138,
      69,    70,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   270,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   481,     0,     0,     0,     0,     0,   221,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   589,     0,   221,   590,     0,     0,   391,     0,     0,
       0,     0,     0,     0,     0,     0,   589,   499,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   521,   522,     0,   523,   492,   498,     0,   493,   590,
     458,     0,     0,     0,     0,   589,     0,     0,   543,     0,
       0,     0,     0,   260,   261,     0,   589,     0,     0,     0,
     278,   279,     0,   221,     0,   221,   589,     0,   590,     0,
       0,   221,   397,     0,     0,    69,    70,     0,     0,    62,
      66,    65,    64,    63,    68,    67,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   404,   403,   405,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   220,     0,   219,     0,
       0,   257,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    37,   253,     0,
       0,   466,   188,     0,   589,     0,   549,   590,   550,     0,
       0,   585,     0,   124,   124,     0,     0,     0,     0,   537,
     538,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   359,   359,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   221,   221,     0,   483,   482,     0,     0,     0,
       0,   221,   221,     0,     0,     0,     0,     0,     0,     0,
     296,     0,   221,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   361,     0,     0,     0,     0,     0,     0,     0,
     242,   392,     0,     0,     0,     0,     0,     0,     0,     0,
      69,    70,     0,     0,     0,     0,     0,     0,     0,     0,
     505,     0,     0,   506,     0,   507,     0,   508,     0,     0,
       0,     0,     0,     0,   403,   500,     0,   494,     0,     0,
       0,   369,    69,    70,     0,   259,     0,     0,     0,     0,
       0,   221,     0,     0,     0,     0,     0,   282,   281,     0,
     247,     0,   248,     0,     0,     0,   221,     0,     0,     0,
       0,   349,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    78,     0,     0,     0,   471,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   454,   583,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    62,
      63,     0,   402,    62,    63,     0,     0,    62,     0,     0,
       0,     0,     0,   216,     0,     0,     0,     0,   222,     0,
       0,     0,   419,   418,   417,   416,   412,   413,   415,   414,
     407,   406,   408,   409,   410,   411,     0,     0,     0,   189,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   125,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   353,     0,
       0,     0,     0,     0,     0,   388,   389,   390,     0,     0,
       0,     0,     0,     0,     0,   357,     0,     0,     0,   154,
     155,     0,   157,   158,     0,   160,   161,     0,   163,   164,
       0,   183,     0,   201,     0,   208,     0,     0,     0,     0,
     175,   221,     0,     0,     0,     0,     0,   485,   484,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   290,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   372,     0,     0,   243,     0,     0,   239,     0,     0,
       0,   387,   386,     0,     0,     0,     0,     0,   471,    71,
      72,     0,   524,     0,     0,     0,     0,     0,   458,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   509,     0,
     510,     0,   511,     0,   512,     0,     0,   402,   495,   502,
       0,   408,   501,     0,     0,     0,   525,     0,     0,     0,
       0,     0,     0,     0,     0,   283,   284,     0,     0,   249,
     251,     0,   591,     0,     0,     0,     0,     0,     0,    62,
      63,     0,     0,    62,    63,     0,     0,     0,     0,    93,
      77,     0,   460,   459,   473,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   442,   430,     0,   432,   433,   434,
     435,   436,   437,   438,     0,     0,     0,   570,     0,   577,
     566,   567,   568,     0,   582,   581,     0,   478,     0,     0,
       0,     0,   571,   572,   573,   480,   579,   143,   148,   116,
       0,     0,   562,     0,   564,     0,   456,   463,   464,   558,
       0,     0,     0,    62,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   110,     0,     0,     0,     0,   465,
       0,     0,     0,     0,   587,     0,     0,    47,     0,     0,
       0,    60,     0,    38,    39,    40,    41,    42,   462,   461,
       0,     0,   555,    27,    25,     0,     0,     0,     0,    28,
       0,     0,   254,   586,    73,   127,    74,   139,     0,     0,
       0,   539,   540,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   170,     0,     0,     0,     0,
     355,   360,   358,     0,   368,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   402,   402,   402,     0,     0,     0,
       0,     0,   250,   252,     0,     0,     0,   211,   213,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   326,     0,   287,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   362,   371,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     460,   459,     0,     0,   528,     0,   527,   526,     0,     0,
     535,     0,     0,   504,     0,     0,     0,     0,     0,     0,
       0,   496,     0,     0,   462,   461,     0,     0,     0,     0,
       0,     0,   244,     0,     0,     0,     0,     0,   246,     0,
     350,     0,     0,     0,     0,   398,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   588,     0,     0,   468,
       0,   467,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    87,     0,    91,     0,     0,    79,     0,     0,
       0,     0,    83,   106,   108,     0,     0,   547,     0,   114,
       0,     0,     0,     0,     0,   420,     0,     0,     0,     0,
       0,    33,   470,   469,   553,   551,    26,     0,     0,   554,
     552,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   168,   168,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   173,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   366,
       0,     0,   156,     0,   159,     0,   162,     0,   165,     0,
       0,     0,     0,     0,     0,     0,   245,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   332,     0,     0,
     331,     0,   338,     0,   340,     0,   334,     0,   336,     0,
     297,   327,     0,     0,     0,   238,     0,     0,     0,     0,
       0,     0,     0,   373,     0,   241,   240,   393,     0,     0,
      34,    35,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   513,   514,   515,   516,   503,   497,
       0,     0,     0,     0,   544,     0,     0,     0,   273,     0,
       0,     0,   221,   351,   221,     0,     0,     0,     0,    88,
       0,    92,     0,     0,    80,     0,    84,     0,   256,   472,
     255,   431,   439,   440,   441,   578,     0,     0,   576,   476,
     477,   479,     0,     0,   455,   144,     0,   584,   149,   475,
     563,   565,   457,     0,     0,     0,    89,     0,     0,     0,
      62,     0,     0,     0,     0,    81,     0,     0,     0,   545,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   490,
       0,     0,    29,    30,     0,    31,     0,     0,   128,   135,
       0,     0,    75,    76,   171,     0,     0,     0,     0,     0,
       0,   174,     0,     0,   191,   192,     0,     0,   176,   206,
     193,   197,   198,   194,   195,   196,     0,     0,     0,   207,
     199,     0,   166,     0,   365,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   258,     0,     0,     0,
       0,   221,   221,     0,   308,     0,   310,     0,   312,     0,
       0,   333,   492,     0,     0,   339,   341,   335,   337,     0,
       0,   291,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   472,   531,   530,   529,
       0,     0,     0,     0,     0,     0,     0,   532,   179,   180,
       0,     0,     0,     0,   117,   121,     0,     0,   349,   349,
       0,   399,     0,     0,     0,    90,     0,     0,     0,    82,
       0,   474,     0,     0,     0,     0,     0,     0,   100,     0,
       0,    94,     0,     0,     0,     0,   111,     0,     0,   112,
       0,   548,   223,   224,   225,   226,     0,     0,    43,     0,
       0,     0,     0,     0,    45,   556,     0,     0,   129,   136,
       0,     0,     0,     0,   169,   177,   178,   182,     0,     0,
     200,     0,     0,   367,     0,   186,     0,     0,   356,   205,
     172,   185,   204,   210,   184,     0,   202,   209,     0,     0,
       0,     0,     0,     0,   489,     0,   488,     0,     0,     0,
     299,     0,     0,   300,     0,     0,   301,     0,     0,     0,
       0,     0,     0,     0,     0,   237,   236,     0,     0,     0,
       0,     0,     0,     0,     0,   227,     0,     0,   370,    36,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   542,
       0,   275,   274,     0,     0,     0,     0,     0,     0,     0,
     101,     0,     0,    95,     0,     0,     0,   569,   575,   574,
       0,   145,   147,     0,   150,   151,   152,   102,   104,    96,
      98,   107,   109,     0,   115,     0,    85,    48,     0,     0,
       0,   491,     0,     0,     0,    32,     0,   143,   148,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   187,
       0,   363,   363,     0,   122,   123,   221,     0,   214,   215,
       0,     0,     0,     0,     0,     0,   298,     0,   328,     0,
       0,   221,     0,     0,     0,     0,     0,     0,     0,     0,
     218,   217,   533,   534,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   118,   119,     0,     0,   352,     0,   103,
     105,    97,    99,    86,     0,   537,   538,     0,     0,   546,
       0,    44,     0,     0,     0,    46,    61,     0,     0,     0,
     133,   131,   381,   383,   382,   384,   385,   190,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   487,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   343,     0,     0,     0,   292,     0,   228,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     541,   276,     0,     0,   221,   400,     0,   146,     0,     0,
     153,   113,     0,     0,     0,     0,     0,   130,   137,   143,
     143,     0,     0,     0,     0,     0,   364,   374,     0,     0,
     375,     0,   212,     0,   314,     0,     0,   316,     0,     0,
     318,     0,     0,     0,   329,     0,   288,     0,   221,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     181,   120,   272,   349,     0,   140,     0,     0,    52,     0,
      58,     0,     0,     0,     0,     0,   167,   203,     0,   378,
       0,   379,   380,   486,   302,     0,     0,   309,   303,     0,
       0,   311,   304,     0,     0,   313,     0,     0,     0,   294,
     231,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     134,   132,     0,     0,     0,     0,   320,     0,   322,     0,
     324,   330,   342,   293,   289,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   141,   142,
      49,     0,    56,     0,     0,     0,     0,     0,     0,   305,
       0,     0,   306,     0,     0,   307,     0,     0,   232,   233,
     234,   235,     0,   229,     0,     0,     0,     0,     0,   354,
       0,    50,     0,     0,   265,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   295,     0,   536,     0,     0,     0,
       0,     0,     0,     0,     0,   271,     0,     0,   315,     0,
     317,     0,   319,     0,   230,     0,     0,     0,     0,    51,
      53,     0,    54,     0,     0,     0,     0,     0,     0,   517,
     518,   519,   520,     0,     0,    59,   376,   377,   321,   323,
     325,    55,    57
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,   106,  1085,   107,   108,   776,  1677,  1683,
    1073,  1306,  1890,  2130,  1074,  2066,  2171,  1075,  2132,  1076,
    1077,  1310,   396,   491,   208,   912,   109,   794,   503,  1817,
    1970,  1969,  1818,   504,  1884,  1274,  1485,  1275,  1488,   838,
     841,   844,   847,  1707,  1538,   758,   341,   467,   468,   112,
     113,   114,   115,   116,   117,   118,   119,   342,  1178,  1997,
    2085,   877,  1731,  1734,  1737,  2035,  2039,  2043,  2110,  2113,
    2116,  1174,  1175,   343,   965,   344,   123,  1358,  1133,   835,
     890,  1914,   124,   125,   126,   127,   345,   210,  1027,   566,
     291,  1518,   346,   347,   348,   638,   357,  1058,  1298,   501,
     496,  1028,   502,   378,   350
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1789
static const yytype_int16 yypact[] =
{
   10623,    43,    36, 10774, -1789, -1789,  4724,    42,    40,  -123,
    -105,    15,   180,   200,   210,   225,    98,   303,   353,   150,
     237,   -38,   -38,  -191,   141,   267,    24,   289,   307,    12,
     346,   361,   379,   387,   410,   417,   421,   429,   448,   308,
      62,   469,   574,   447,   551,   463,   478,   500,   569,   640,
     561,   644,   659,   592,   110,   524,   671,   -15,   533,   -58,
     -58,   547,   373,    80, -1789, -1789, -1789, -1789, -1789,   428,
     705,   737,     8,    48,   756,   718,   249,   817,   853,   878,
    6148,   882,   628,   662,   668,    10,    11, -1789,   681,   688,
   -1789, -1789,   893,   909,   700, -1789,  6027,   706,  7210,    32,
      33, -1789, -1789, -1789, 10116,   710, -1789, -1789, -1789, -1789,
   -1789, -1789, -1789, -1789, -1789, -1789, -1789, -1789, -1789, -1789,
   -1789,   -54, -1789, -1789, -1789, -1789,    47, -1789,   145,   124,
   -1789,     1, -1789, -1789, -1789, -1789, -1789,   -38,   -38,   -38,
     -38,   -38,   -38,   -38,   -38,   -38,   -38,   -38,   -38,   -38,
     -38,   -38,   -38,   -38,   -38,   -38,   -38,   -38,   -38,   -38,
     -38,   -38,   715,   725,   739,   -38,   -38,   -38,   -38,   743,
     -38,   -38,   -38,   -38,   -38,   -38,   747, -1789,   -38, -1789,
   -1789, -1789, -1789, -1789,   -38,   -38,   934,   750,   751,   754,
     -38,   -38,   764,   771, -1789, -1789, -1789, -1789,   719, 10116,
   10116, 10116,  4190,  4798,    46,    18,   328,   748,   768,   881,
   -1789,   769,   997,   178,  -111,   998, 10116,  6263,  6263, -1789,
   10116, -1789, -1789, -1789, -1789,  6263, -1789, -1789, -1789, -1789,
   -1789, -1789,  7432,    18, 10116,  9545, 10116, 10116,   788, 10116,
    9545, 10116, 10116,   789,  9545, 10116, 10116, 10116, 10116, 10116,
   10116,  6263, 10116, 10116,  7109,   796,   797, -1789,  9545,  6148,
    6148,  6148,  6263, 10116, 10116,   803,   828,  6148,  6148,  6148,
     829,   860,   861,   876,   877,  7331,  7553,  7775,   812,  2614,
    1052,  7109,    10,   840,   875,   -58,   -58,   -58, 10116, 10116,
    -154, -1789,  -139,   -58,   879,   914,   915,  2884,  -108,   139,
     885,   913,   917,   927,   938,   978,   986,  6148,  6148,  7109,
    1018,    14,   855, -1789,   900,  1236,  1261, -1789,  1041,  1046,
    1051,  6148,  6148,  1060,  1065,  1079,   325, -1789,   383,   -38,
     -38,   -38,   -38,    22,    25,    26,    28,   822,  7997, 10116,
    5475, -1789, -1789,  1075, -1789,  1112, -1789,  1301, -1789,   241,
     474,  1302, 10116, 10116, 10116,  -162, 10116,  1080, -1789,  1145,
   10116, 10116, 10116, -1789, -1789, 10116,  1082,  1306,  1309,  1101,
   -1789, -1789,  1327, -1789,  1331, -1789,   175,  5198,   259,  6263,
   10116, -1789, -1789,  7109,  7109,  9429,  9761,  1102,  1108,  7432,
   -1789, -1789, -1789, -1789, -1789, -1789,  7109,  1333,  1116, 10116,
   10116,  1338, 10116, 10116, 10116, 10116, 10116, 10116, 10116, 10116,
   10116, 10116, 10116, 10116, 10116, 10116, 10116, 10116, 10116, 10116,
   10116, 10116, 10116, 10116,  6263,  6263,  6263,  6263,  6263,  6263,
    6263,  6263,  6263,  6263,  7109,  6263,  6263, 10116,  6263,  6263,
    6263,  6263,  6263, 10116,  7432, 10116,  6263,  6263,  6263,  6263,
    6263,    18,  7432,    18,  1121,  1121,  1121,   184, 12408,   188,
    6044,   146,  1117,  1339,   -38,  1115, -1789,  1118, 10905, 10116,
    9545, -1789, 10116, 10116, 10116, 10116, 10116, 10116, 10116, 10116,
   10116, 10116, 10116, 10116, 10116, 10116, 10116, -1789, -1789, 10116,
   10116, -1789, -1789,   973,   296,  -143, -1789,   382, -1789,   -70,
    9668, -1789,    93,   166,   186,  1122,  1125, 12429,  9545,  3835,
   -1789,   558, 12450, 12471, 10116, 12492,   596, 12513, 12534, 10116,
     625, 12555, 12576, 12597, 12618, 12639, 12660,  1123, 12681, 12702,
    1343, 10116, 10116,   666,  1349,  1350,  1353,  1137, 12723, 12744,
   10116, 10116,  1358,  1362,  1362, 10116,  9329,  9329,  9329,  9329,
   10116,  1364, 10116,  1366, 10116,  1367,  9545,  9545,  9207,  1150,
    1370,  1147, -1789, -1789,  -151, -1789, -1789,  9786,  9884,   -58,
     -58,   328,   328,  -102, 10116, 10116, 10116,  2884,  2884, 10116,
    3097,    94, -1789, 10116, 10116, 10116, 10116, 10116, 10116, 10116,
   10116, 10116,  1371,  1373,  1374, 10116,  1376, 10116, 10116,  3294,
   -1789, -1789,  9545,  9545,  9545,  1382,  1383, 10116, 10116, 10116,
   10116, 10116,  1386,   315,  8219,  8441, 10116, 10116,  6263, 10116,
   -1789,  1318, 10116, -1789,  1329, -1789,  1330, -1789,  1332,    37,
      38,    39,    41,  9545,  1121, -1789, 12765, -1789,   676, 10116,
    8663, -1789, 10116, 10116,   566, -1789, 12786, 12807, 12828,  1228,
    9951, -1789,  1166,  4025, 12849, 12870, 10350, -1789, -1789,  9545,
   -1789,  4379, -1789,  4530, 10116, 10116, -1789, 10116, 10116,  1173,
   12891,  5539,  1176,   693,   216, 12912,   324, 10436, 10116,  9545,
    1396,  1398, -1789, 10116, 12933, 12086,   -73,  9509,  9509,  9509,
    9509,  9509,  9509,  9509,  9509,  9509,  9509,  9509,  9993,  9509,
    9509,  9509,  9509,  9509,  9509,  9509, 10075, 10466, 10823,   246,
     655,   246,  1179,  1181,  1177,   556,   556,  1183,   556,  1184,
    1185,  1186, 10864,   556,   556,   556,   154,   556, 13563, -1789,
    1628,  1187,  1188,  1194,   694,   707,  1197,  1198,  1182,  1380,
    1381,  7109,   151,  1384,  1390,  7109,   113,  7432, 10116,  1404,
    1423,    20,   556, -1789,   219,    30,    31,   287, -1789,  3592,
     729,  4070,  1368,  1515,  1429,  1429,   476,   476,   476,   476,
     282,   282,  1121,  1121,  1121,  1121,     5, 12954, 12109, -1789,
   10116, 10116,  1426,    34,  9545, 10116, 10116,  1430,  9545, 10116,
    1438,  6263,  1440, -1789,    18,  1441,  6263, 10116,  7432,  1428,
    9545,  9545,  1275,  1442,  1443, 12975,  1444,  1280,  1445,  1446,
   12996,  1289,  1449,  1451,  1455,  1456,  1457,  1458, -1789,  1459,
    1460, 10116, 13017,  4340,  1242, -1789, -1789, -1789,  1468,  1473,
    1483, 13038, 13059, 10116,  7109,  1487,  1486, 13080,  1269, 13563,
    1270,  1274, 13563,  1271,  1277, 13563,  1279,  1282, 13563,  1281,
   13101, -1789, 13122, -1789, 13143, -1789,   730,   734,  9545,  1285,
   -1789, -1789,  4948,  5122,   -58, 10116, 10116, -1789, -1789,  1278,
    1283,  2884, 10890, 10916, 10942,  9596,  1401,   857,   -58,  6420,
   13164,  4373, 13185, 13206, 13227, 13248, 13269, 13290, 13311, 10116,
    1509, -1789, 10116, 13332, -1789, 12132, 12155, -1789,   738,   755,
     759, -1789, -1789, 12178, 12201, 10968, 13353, 12224,   474, -1789,
   -1789,  9545, -1789,  9545,  3835,  1299,  9545,  1300,   549, 10994,
   11020,   556, 11046,  1295,  4457,  1297,  1298,  1303, -1789,  9545,
   -1789,  9545, -1789,  9545, -1789,  9545,   793, -1789, -1789,  4090,
    9545,  1121, -1789, 13374, 12247,  9545, -1789,  1522,  1523,  1524,
    1308, 10116, 10261, 10116, 10116, -1789, -1789,    49,   794, -1789,
   -1789, 10315, -1789,  1529,  9833,  1307,  1313,  7109,  1531,  1495,
    1501,  7109,   151,  1506,  1507,  7109,   151,  4633,   802, -1789,
   -1789, 12270,   -41,  1199, -1789, -1789, -1789, -1789, -1789, -1789,
   -1789, -1789, -1789, -1789, -1789, -1789, 10116, -1789, -1789, -1789,
   -1789, -1789, -1789, -1789, 10116, 10116, 10116, -1789,  9545, -1789,
   -1789, -1789, -1789,  6263, -1789, -1789, 10116, -1789,  7109,  6263,
    6263,  6263, -1789, -1789, -1789, -1789, -1789, -1789, -1789, -1789,
   10116,  6263, -1789,  6263, -1789, 10116, -1789, -1789, -1789, -1789,
     -38,   -38,  1546, -1789, 10116,  1547,   -38,   -38,  1548,    53,
   10116,  1549,  1550,  1728, -1789,  1553,  1336,    10,  1556, -1789,
    9545,  9545,  9545,  9545, -1789,   556, 10116, -1789,  1342,  1344,
    1357, -1789,  1560, -1789, -1789, -1789, -1789, -1789,   -22,   108,
   13395, 12293, -1789, -1789,  1359,  6263,   265, 13416, 12316, -1789,
     320, 11072, -1789, -1789, -1789,    57, -1789, -1789,  9509,   556,
     -58,  3835, -1789,   942,  7109,  7109,  1561,  7109,   957,  7109,
    7109,  1565,  1496,  7109,  7109,  7109,  7109,  7109,  7109,  7109,
    7109,  1772,  1582,  1584,  9545, -1789,  7109,  7109,  1585,  1586,
     -71, -1789, -1789,  1589, -1789,  1590,   335, 10116,   335, 10116,
     335, 10116,   335, 10116,  1591,  1593,  1595,  1596,  1599,   819,
    1592, 10378, -1789, -1789,   144, 11098, 11124, -1789, -1789,  4889,
    -106,   -58,   -58,   -58,  1521,  1605, 10049,  1385,  1604,  1388,
      35,    52,    60,    74,   -48, -1789,   227, -1789,   857,  1606,
    1608,  1609,  1610,  1611,  1613,  1617,  1619,  1622, 13563, -1789,
    1798,  1400,  1625,  1626,  1643,  1564,  1648,  1644,  1650, 10116,
     474,   -17,   824,   832, -1789,   833, -1789, -1789, 10116, 10116,
   -1789, 10116, 10116, -1789, 10116, 10116, 10116,   836,   837,   842,
     846, -1789, 10116,   847,   474,   474,   850,  7109,  7109,  7109,
    1653, 11150, -1789,  4301,   412,  1654,  1655,  1431, -1789,  1432,
   -1789,  1897,  1434,  7109,  1435, -1789,   -38,   -38,  1659, 10116,
    1662,   -38,   -38,  1663, 10116,  1664, -1789,   556,  1665, -1789,
    1671, -1789,  1670,  9509,  9509,  9509,  9509,   721,  1448,  9710,
    1469,   556,   556,  1466,   727,   728, 13437,  1476,   556,  9509,
    1437,  6263, -1789,  2019, -1789,  1437,  6263, -1789,   313,  1472,
    1696,  2044, -1789, -1789, -1789,    10, 10116, -1789,   898, -1789,
     899,   902,   906,   910,   335, 13563,  1389, 10116, 10116,  7109,
    1477, -1789, -1789, -1789, -1789,  1478, -1789,  1702,    73, -1789,
   -1789,  1703, 10116,  6370,  1488,  1484,  1705,  1707,     7,  1485,
    1503,  1602,  1602,  7109,  1733,  1512,  1513,  1738,  1739,  7109,
    1517,  1745,  1746,  1747,  1749,  1750,  1751,  1752,  1753, -1789,
    1756,  7109,   920,  1757,  1758,  7109,  7109,  1761,  1760, -1789,
    7109,  7109, 13563,  7109, 13563,  7109, 13563,  7109, 13563,  7109,
    7109,  7109,  1532,  1537,  1762,   807, -1789, 10116, 10116, 10116,
    1538,  1541,  -146,  -141,  -115,  1542,  1551, -1789,  2365,  7109,
   -1789, 10116, -1789,  1767, -1789,  1768, -1789,  1769, -1789,  1771,
   -1789, -1789,  2884,   336,  6592, -1789,  1552,  1554,  1555,  1558,
    1559,  1562,  8885, -1789,  9545, -1789, -1789, -1789,  1566, 10116,
   -1789, -1789, 12339,  1775,   556,  1557,  1568, 11176, 11202, 11228,
   11254, 11280, 11306, 11332, -1789, -1789, -1789, -1789, 13563, -1789,
     556,  1774,  1777,  1627, -1789, 10116, 10116, 10116, -1789,  1789,
     826,  7432, -1789, -1789, -1789,  1569,  1791,  1437,  6263, -1789,
    2449, -1789,  1437,  6263, -1789,  2525, -1789,   335, -1789,   135,
   -1789, -1789, -1789, -1789, -1789, -1789,  6263, 10116, -1789, -1789,
   -1789, -1789,  6263,  1795, -1789, -1789,    21, -1789, -1789, -1789,
   -1789, -1789, -1789,  1797,   246,   246, -1789,  1799,   246,   246,
    7432, 10116,  1800,  1803,    20, -1789,  1802, 12362,    10, -1789,
    1804,  1805,  1806,  1807,  7109, 10116, 11358, 11384,   928, -1789,
   10116,  1810, -1789, -1789,  6263, -1789, 11410,  5704, 13563, -1789,
    1794,  1808, -1789, -1789, -1789, 10116, 10116,   -58,  1812,  1813,
    1814, -1789, 10116, 10116, -1789, -1789,  1815, 10116, -1789, -1789,
   -1789, -1789, -1789, -1789, -1789, -1789,  1817,  1818,  1598, -1789,
   -1789,  1819,  1658, 10116, -1789,  1823,  1825,  1840,  1842,  1843,
    1846,  1154,  1847,  9545,  9545, 10116, -1789,  9329,  4932, 13458,
    1475,   328,   328,   -58,  1848,   -58,  1850,   -58,  1851,  7109,
   10116, -1789,    81,  1594, 13479, -1789, -1789, -1789, -1789,  5135,
     245, -1789,  1852,  1854,  7109,   -58,   -58,   -58,   -58,   -58,
    5238,  1855,   936, 10116,  2797,  1856,   474, -1789, -1789, -1789,
   10116, 10116, 10116, 10116, 10116, 10116, 10116, -1789, -1789, -1789,
    7109,  1832,   661, 13500, -1789, -1789,  6814,  1634,  5539,  5539,
    7109, -1789,  1883,   246,   246, -1789,  1884,   246,   246, -1789,
    7109, -1789,  1667,  9509,   556,  5926,  6887,  7432, -1789,  1890,
    1898, -1789,  1900,  1901,  1902,  2824, -1789,  1906,  1903, -1789,
    1687, -1789, -1789, -1789, -1789, -1789,  1909,   327, 13563, 10116,
   10116,  7109,  1686,   937, 13563, -1789,  1913, 10116, -1789, -1789,
    1690,  1691,  5372,  5601,   648, -1789, -1789, -1789,  5641,  6259,
   -1789,  6489,  1917, -1789,  7109, -1789,  1835,  1918, 13563, -1789,
   -1789, -1789, -1789, -1789, -1789,  1695, -1789, -1789,   940,   941,
    9482,  2944,  1920,  1697, -1789, 10116, -1789,  1699,  1715,   264,
   -1789,  1698,   318, -1789,  1717,   329, -1789,  1718,  1721, 12385,
    1943,  7109,  1947,  1729, 10116, -1789, -1789,   944,   348,   384,
     418,   432,   436,  9107,   441, -1789,  1951,  6529, -1789, -1789,
    9509,  9509, 11436, 11462, 11488, 11514, 11540,  1801, 10116, -1789,
   10116, -1789, -1789,  9545,  3083,  1952,  7432,  1730,  1731,  1732,
   -1789,  1954,  1959, -1789,  1965,  1966,  1967, -1789, -1789, -1789,
    5475, -1789, -1789,  6263, 13563, -1789, -1789, -1789, -1789, -1789,
   -1789, -1789, -1789,    10, -1789,  1824, -1789, -1789, 10116, 11566,
   11592, -1789,  7109, 10116,  1968, -1789, 11618, -1789, -1789,  7109,
    7109,  1985,  1986,  1987,  1989,  1990,  2010,   962,  1787, -1789,
    7109,   677,   723,  9545, -1789, -1789,   328,  3145, -1789, -1789,
    2884,   857,  2884,   857,  2884,   857, -1789,  2013, -1789,   963,
    7109, -1789,  6765,  2015,  9545,   -58,   -58,   -58,   -58,   -58,
   -1789, -1789, -1789, -1789, 10116, 10116, 10116, 10116, 10116, 10116,
    6844,  7450,   967, -1789, -1789,  1809,  1792, -1789,  2018, -1789,
   -1789, -1789, -1789, -1789,   968,  3411,  2021,   976,  2020, -1789,
    1821, 13563, 10116, 10116,   979, 13563, -1789, 10116,   983,   984,
   -1789, -1789, -1789, -1789, -1789, -1789, -1789, -1789,  1822, 10116,
     987,  1830,   -58,  7109,  2024,  1834,   -58,  2025,   988,  1831,
   10116, -1789,  7490,   449,   357,  7672,   483,   523,  7712,   486,
     622, -1789,  7109,  2026,  1915, 10432,  1836, -1789,   991,   508,
     519,   521,   526,   531, 11644, 11670, 11696, 11722, 11748,  3360,
   -1789, -1789,  2029,  2049, -1789, -1789, 10116, -1789,  7432,    18,
   -1789, -1789, 10116, 13521, 11774,    45, 11800, -1789, -1789, -1789,
   -1789, 10116,  7894,  2059,   -58,    86, -1789, -1789,   -58,    88,
   -1789,  2061, -1789,  7934,  2062, 10116,  2063,  2064, 10116,  2066,
    2067, 10116,  2068,  1844, -1789, 10116, -1789,   857, -1789,  2071,
    9545,  9545,  9545,  9545,  9107, 10116, 10116, 10116, 10116, 10116,
   -1789, -1789, -1789,  5539,  3535, -1789,  1859,   992, -1789, 10116,
   -1789,  7109, 10116,  1000,  1001, 11826, -1789, -1789,   539, -1789,
     565, -1789, -1789, -1789, -1789,  1849,  8116, -1789, -1789,  1853,
    8156, -1789, -1789,  1858,  8338, -1789,  2072,  3385,   667, 10495,
   -1789,  1004,  1007,  1008,  1023,   570,  1024, 11852, 11878, 11904,
   11930, 11956,  1860,  7432,  1862,  2078,  1863, 13542,  1031,  8378,
   -1789, -1789, 10116,   -58,   -58,   857,  2084,   857,  2086,   857,
    2088, -1789, -1789, -1789, -1789,   857,  2089,  2090,  2091,  2093,
    9545,  2094, 10116, 10116, 10116, 10116, 10116,  2110, -1789, -1789,
   -1789,  6263, -1789,  1887,  2112,  8560,   609,   631,   685, -1789,
    1891,   894, -1789,  1892,  1003, -1789,  1893,  1144, -1789, -1789,
   -1789, -1789,  1039, -1789,  9509, 11982, 12008, 12034, 12060, -1789,
    1055, -1789,  1899,  7109, -1789,  2114, 10116, 10116,  2125,   857,
    2126,   857,  2127,   857, -1789,  2128, -1789, 10116, 10116, 10116,
   10116,  6263,  2129,  6263,  1071, -1789,  8600,  8782, -1789,  1288,
   -1789,  1326, -1789,  1397, -1789,  8822,  9004,  9044,  9264, -1789,
   -1789,  1072, -1789,  2130,  2131,  2132,  2133,  2134,  2136, -1789,
   -1789, -1789, -1789,  6263,  2137, -1789, -1789, -1789, -1789, -1789,
   -1789, -1789, -1789
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1789, -1789, -1789, -1789,   831, -1789, -1789, -1789, -1789,   182,
   -1789, -1789, -1789, -1789, -1789, -1789, -1789, -1789, -1789, -1789,
   -1789, -1789,  -333,   -82,  1727,  3437, -1789,  1642, -1789, -1789,
   -1789, -1789, -1789, -1789, -1789, -1788, -1789,   333, -1789, -1789,
   -1789, -1789, -1789, -1789,   815,  2149,    23,  -561,  -252, -1789,
   -1789, -1789, -1789, -1789, -1789, -1789, -1789,  2150, -1789, -1789,
   -1789, -1789, -1789, -1789, -1789, -1789, -1789, -1789, -1789, -1789,
   -1789, -1158, -1168,  2151, -1631,  2152, -1789, -1789, -1789,  1612,
   -1789,   326, -1789, -1789, -1789, -1789,  1925, -1789, -1789,   111,
   -1789, -1587,  2746,   581,  3397,  3027,  -281,   653, -1789,   143,
      17, -1789,  -422,    -3,   278
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -557
static const yytype_int16 yytable[] =
{
     128,   561,   709,   213,   711,   398,  1401,  1777,  1778,  1067,
     869,   870,   311,  1534,   355,   359,   243,  1747,   596,   726,
    1403,   219,   366,   212,  1056,  1656,   111,   620,   238,  1898,
     623,   625,   234,   627,   238,   243,     5,   372,   374,   235,
    1083,  1392,   928,   930,   932,   580,   934,   397,  1357,     4,
     461,  2020,   316,   382,   317,   215,  1235,  1288,  1394,   569,
     570,   599,   569,   570,  1323,   649,  1396,   569,   570,   314,
     207,  1165,   569,   570,   569,   570,   571,   349,   864,  1523,
    1398,   783,   314,  1583,   299,  1584,   784,  1166,  1585,   639,
    1586,   572,  2029,   314,  2031,  1167,  1168,  1169,   569,   570,
     217,  1170,  1171,  1172,  1173,   569,   570,   569,   570,   394,
     395,   569,   570,   367,  1587,   371,  1588,  1827,   218,  -550,
    1043,   661,   582,   663,   741,  1381,   745,   871,   748,   671,
     216,   389,   318,   472,   473,   474,   475,   476,   477,   478,
     479,   480,   481,   482,   483,   484,   485,   394,   395,   211,
     282,   486,   255,   747,   787,   286,   287,  -555,  1043,   788,
    1068,  1069,  1070,  1071,   300,   288,   283,   284,   301,   380,
     290,   292,   289,   298,   302,   303,   381,   304,   305,   394,
     395,  2023,  2024,  1400,   312,   230,   221,   231,  1393,  -553,
     621,   739,   306,   624,   626,   743,   628,   278,   394,   395,
     279,  1657,   314,   394,   395,  1395,   222,   105,  -554,   105,
    1423,   462,   463,  1397,   497,   497,   223,   105,  1289,  1290,
     569,   570,   497,   969,   399,  1894,   400,  1399,   401,   466,
     314,   224,   349,   207,   360,  1401,  1072,   349,   313,   597,
     356,   349,   244,  1910,  1084,   220,   207,   239,   497,   505,
    1057,   349,   622,   239,   240,   349,   349,   349,   349,   497,
    1061,  1062,   373,   375,   349,   349,   349,   929,   931,   933,
     383,   935,   349,   349,   349,  2021,  1236,   384,   349,   314,
    1324,   129,  1325,  1084,   214,   472,   473,   474,   475,   476,
     477,   478,   479,   480,   481,   482,   640,   484,   485,   569,
     570,   569,   570,   486,   349,   349,   349,   569,   570,   226,
     862,   863,  1740,   390,   391,   392,   393,   790,   349,   349,
    1500,   225,   791,   878,   390,   391,   392,   393,   394,   395,
     879,   973,   465,   394,   395,   349,   321,   349,  -552,   322,
    1049,   971,  1043,   975,   394,   395,   390,   391,   392,   393,
     315,   390,   391,   392,   393,   394,   395,   569,   570,   227,
     495,   499,   583,   358,   236,  -556,   394,   395,   385,   584,
     386,   394,   395,  1377,   368,   228,   497,   387,  1025,   749,
     349,   349,  2062,   791,   390,   391,   392,   740,   390,   391,
     392,   744,   792,   349,   527,   793,   564,   565,   664,   952,
     665,   489,   612,   490,   573,   537,   680,   207,   581,  1044,
     387,   254,   795,  1050,   961,   793,   390,   391,   392,   970,
    1447,   497,   497,   497,   497,   497,   497,   497,   497,   497,
     497,   349,   497,   497,  2068,   497,   497,   497,   497,   497,
     569,   570,   234,   497,   497,   497,   497,   497,   314,  1060,
     314,    58,    59,    60,    61,  1165,  1402,   294,   569,   570,
     295,   729,   229,   296,   642,    71,   643,   349,    74,   737,
     909,  1166,   910,   387,  1744,   791,  1165,   569,   570,  1167,
    1168,  1169,   667,   464,   668,  1170,  1171,  1172,  1173,  1318,
     237,   387,  1166,  1840,   801,   498,   498,   483,   484,   485,
    1167,  1168,  1169,   498,   486,   349,  1170,  1171,  1172,  1173,
     246,   506,   241,   390,   391,   392,   393,  1063,   307,   780,
     308,   781,   669,   782,   390,   391,   392,   974,   207,   498,
     242,   569,   570,   394,   395,   390,   391,   392,   393,   909,
     498,   910,   569,   570,  1321,   911,  2154,  1842,   610,   801,
     611,  1807,   612,   349,   349,   206,  1808,   207,  1844,   256,
     358,   569,   570,   840,   843,   846,   849,  1601,   710,   245,
     712,   713,   714,   715,   716,   717,   718,  1854,   720,   721,
     257,   723,   724,   725,   246,   727,   286,   287,  1986,   731,
     732,   733,   734,   735,   466,   466,   288,   569,   570,   349,
     349,   349,   247,   297,   984,   785,   614,   786,   615,  1151,
     248,   349,   349,  1855,   387,   497,   472,   473,   474,   475,
     476,   477,   478,   479,   480,   481,   482,   483,   484,   485,
     349,   569,   570,   249,   486,   259,  1448,   349,   260,  1249,
     250,   261,  1165,  1254,   251,   569,   570,  1856,   267,   569,
     570,   268,   252,   269,   569,   570,   349,   498,  1166,   265,
    1045,  1857,   569,   570,  1051,  1858,  1167,  1168,  1169,  1770,
    1859,   253,  1170,  1171,  1172,  1173,   349,   258,  1985,   275,
     867,   868,   276,  1924,   277,  1927,   262,  1930,   565,   481,
     482,   483,   484,   485,   394,   395,   569,   570,   486,   569,
     570,   263,   498,   498,   498,   498,   498,   498,   498,   498,
     498,   498,  1988,   498,   498,  1991,   498,   498,   498,   498,
     498,   569,   570,   264,   498,   498,   498,   498,   498,   736,
     266,   738,   569,   570,   569,   570,   270,  2000,   349,   569,
     570,  1165,   349,   271,   569,   570,   272,   280,  2001,   273,
    2002,   274,   569,   570,  1989,  2003,  1401,  1166,   281,  1401,
    2004,   921,  1401,   285,  1052,  1167,  1168,  1169,  2073,   394,
     395,  1170,  1171,  1172,  1173,  1207,  1297,   293,   569,   570,
     909,   349,   910,   569,   570,   349,  1165,   801,   497,   802,
     909,   314,   910,   497,  2074,   309,   945,   349,   349,  2090,
    1911,  1912,  1166,  1361,  1165,  1363,  1913,  1365,   320,  1367,
    1167,  1168,  1169,  1576,  1577,  1099,  1170,  1171,  1172,  1173,
    1166,   323,   569,   570,   310,   801,   984,   807,  1167,  1168,
    1169,   349,  1635,  1636,  1170,  1171,  1172,  1173,  2136,  2048,
     534,   535,   536,   319,   569,   570,  1915,  1916,   542,   543,
     544,   352,  1913,  1992,   801,   349,   811,   324,  1494,  1495,
    2137,   569,   570,  1498,  1499,   472,   473,   474,   475,   476,
     477,   478,   479,   480,   481,   482,   483,   484,   485,   909,
    1401,   910,   325,   486,  1008,   353,   351,   471,   592,   593,
    1250,   354,  1771,   918,  1255,   801,   498,   824,  2083,   363,
    1259,  1261,   605,   606,   361,   801,   629,   938,   349,   630,
     349,   362,   631,   349,   632,   364,  2138,  2108,   909,  2111,
     910,  2114,   967,  1033,   968,   365,   349,  2117,   349,   369,
     349,   909,   349,   910,  1093,   379,  1035,   349,   427,  1097,
    1401,   445,   349,  1401,   453,   909,  1401,   910,   428,  1401,
     801,   909,   909,   910,   910,  1501,  1483,  1486,   801,   801,
    1065,  1147,   429,   801,   349,  1148,   434,   801,   349,  1194,
     441,  1514,   349,   446,   447,  1154,  1165,   448,   469,   779,
     497,  2159,  1160,  2161,   801,  2163,  1195,   451,   801,  1176,
    1196,  1401,  1166,  1401,   452,  1401,  1312,  1313,   470,   487,
    1167,  1168,  1169,   488,   492,   349,  1170,  1171,  1172,  1173,
     497,   514,   519,  1165,  1506,   349,   497,   497,   497,   531,
    1727,  1728,   801,   801,  1221,  1237,   540,   532,   497,  1166,
     497,   801,  1329,  1257,  1330,  1643,  1644,  1167,  1168,  1169,
    1647,  1648,   556,  1170,  1171,  1172,  1173,  1335,   801,  1336,
    1374,   541,   545,   801,   314,  1424,   559,   349,   349,   349,
     349,   801,   801,  1425,  1426,   801,   801,  1434,  1435,   498,
     562,   801,  1095,  1436,   498,   801,   801,  1437,  1439,   801,
     598,  1440,   497,   546,   547,   472,   473,   474,   475,   476,
     477,   478,   479,   480,   481,   482,   483,   484,   485,   548,
     549,   349,   349,   486,   349,   563,   349,   349,   585,   574,
     349,   349,   349,   349,   349,   349,   349,   349,  1259,  1261,
     639,   349,  1165,   349,   349,  2140,  1262,  1508,   801,  1509,
    1510,   801,   387,  1511,  1650,   801,   586,  1512,  1166,   801,
     587,  1513,  1312,  1313,   575,   576,  1167,  1168,  1169,   801,
     588,  1558,  1170,  1171,  1172,  1173,  1268,  1681,  1715,  1682,
    1716,   589,  1271,  1272,  1273,   801,  1813,  1756,  1814,   801,
     801,  1831,  1832,  1681,  1277,  1853,  1278,   472,   473,   474,
     475,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,  1681,  1932,  1908,  1933,   486,   801,  1956,  1952,  1957,
    1638,   590,  1639,   494,   132,   791,  1502,  1960,  1681,   591,
    1965,  1328,  1483,  1486,  1967,  1968,  1681,   801,  1973,  1981,
     801,  1813,  1999,  2065,   349,   349,   349,  1671,  1317,  1483,
    1483,  2070,  2071,   801,  2142,  2086,   801,   801,  2087,  2088,
     349,   595,   600,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   801,   801,  2089,  2091,   172,   173,   174,   175,
    1681,   498,  2103,  1165,   177,   178,   179,   601,   801,   180,
    2145,   602,  1382,  1383,  1384,  1919,   603,   497,   497,  1166,
     185,   604,   497,   497,  2151,   607,  2152,  1167,  1168,  1169,
     608,   498,   314,  1170,  1171,  1172,  1173,   498,   498,   498,
    1681,  2183,  2173,  2184,   609,   381,   349,   641,   645,   498,
     651,   498,   657,   652,   207,   658,   472,   473,   474,   475,
     476,   477,   478,   479,   480,   481,   482,   640,   484,   485,
     349,   659,   678,   660,   486,   358,   349,   662,   679,   682,
    1529,   683,   686,   486,   750,   206,   751,   818,   349,   753,
     821,   797,   349,   349,   798,   825,   826,   349,   349,   827,
     349,   828,   349,   498,   349,   833,   349,   349,   349,   834,
     851,  1887,   853,   855,   859,  2144,   860,   861,   889,   891,
     923,   892,   894,   188,   189,   190,   349,  1651,   901,   902,
     908,   925,   926,   950,   927,   197,   953,   198,   105,   962,
     966,   349,   979,  1011,   980,  1012,  1013,  1165,  1039,   349,
    1054,   349,  1016,  1018,  1019,  1020,  1030,  1031,  1032,   394,
     395,  1037,  1038,  1166,  1040,  1041,  1260,  1055,  1046,  -551,
    1082,  1167,  1168,  1169,  1047,  1100,  1089,  1170,  1171,  1172,
    1173,   494,   132,  1103,  1092,  1165,  1094,  1096,  1108,  1104,
    1105,  1107,  1109,  1110,   497,   497,  1113,  1112,  1114,   497,
     497,  1166,  1115,  1116,  1117,  1118,  1119,  1120,  1637,  1167,
    1168,  1169,  1124,   497,  1125,  1170,  1171,  1172,  1173,   497,
    1126,   159,   160,   161,   162,   163,   164,   165,   166,   167,
    1127,  1132,  1134,  1136,   172,   173,   174,   175,  1138,  1137,
    1139,  1140,   177,   178,   179,   314,  1142,   180,  1141,  1157,
    1143,   349,  1150,  1600,  1158,  1189,  1165,  1664,   185,  2176,
    1164,   497,  1888,  1204,   349,  1212,  1206,  1214,  1215,  1227,
    1228,  1229,  1166,  1216,  1651,  1230,  1239,  1245,  1242,  1246,
    1167,  1168,  1169,  1243,  1689,  1247,  1170,  1171,  1172,  1173,
    1251,  1252,  1282,  1284,  1287,  1292,  1293,  2177,   498,   498,
    1295,  1296,  1299,   498,   498,  1307,  1311,  1308,  1333,  1316,
     349,   349,  1339,   358,   474,   475,   476,   477,   478,   479,
     480,   481,   482,   483,   484,   485,   349,  1309,  1340,  1350,
     486,  1351,  1355,  1356,  1722,  1359,  1375,  1360,  1369,  1935,
    1370,   349,  1371,  1372,   466,   466,  1373,   349,  1385,  1386,
    1390,  1391,  1515,  1404,  1405,  1389,  1406,  1407,  1408,  1652,
    1409,   188,   189,   190,  1410,  1654,  1411,   349,  2178,  1412,
    1414,  1415,  1416,   197,  1029,   198,   105,   349,   477,   478,
     479,   480,   481,   482,   483,   484,   485,   349,  1694,  1417,
    1420,   486,   349,  1775,  1418,  1419,  1421,  1444,  1449,  1450,
    1451,   909,  1452,   910,  1454,  1459,  1456,  1686,  1461,  1464,
    1466,  1468,  1792,  1795,  1796,  1469,  1470,  1476,   349,   472,
     473,   474,   475,   476,   477,   478,   479,   480,   481,   482,
     483,   484,   485,  1479,  1729,  1482,  1732,   486,  1735,  1503,
    1490,   349,  2013,  1504,  1725,  1521,  1726,  1520,  1522,  1525,
    1531,  1532,  1530,  1533,  1537,  1535,  1748,  1749,  1750,  1751,
    1752,  1754,   475,   476,   477,   478,   479,   480,   481,   482,
     483,   484,   485,  1536,  1294,   498,   498,   486,   349,  1541,
     498,   498,  1542,  1543,  1544,  1545,  2049,  1547,   232,   233,
     349,  1548,  1549,  1550,   498,  1551,  1552,  1553,  1554,  1555,
     498,  1556,  1573,  1559,  1560,  1563,  1564,  1574,  1581,  1575,
     349,  1582,  1589,  1595,  1596,  1597,  1590,  1598,  1349,  1616,
    1628,  1618,  1604,  1629,  1605,  1606,   358,   349,  1607,  1608,
     497,  1630,  1609,  1875,  1619,  1634,  1613,  1641,  1640,  1655,
     314,  1690,   498,  1658,  1413,  1661,  1666,  1667,  1669,   349,
    1672,  1673,  1674,  1675,  1685,  1691,   349,   349,  1695,  1696,
    1697,  1700,  1702,  1741,  1703,  1705,  1706,   349,  1704,  1709,
     349,  1710,   472,   473,   474,   475,   476,   477,   478,   479,
     480,   481,   482,   483,   484,   485,  1711,   349,  1712,  1713,
     486,   349,  1714,  1717,  1730,   388,  1733,  1736,  1745,   466,
    1746,  1755,  1759,  1776,   402,   403,   404,   405,   406,   407,
     408,   409,   410,   411,   412,   413,   414,   415,   416,   417,
     418,   419,   420,   421,   422,   423,   424,   425,   426,  1780,
    1783,  1787,   430,   431,   432,   433,  1797,   435,   436,   437,
     438,   439,   440,  1453,  1798,   442,  1799,  1800,  1801,  1804,
     349,   443,   444,  1803,  1805,  1806,  1812,   449,   450,  1815,
    1819,  1820,  1826,  1828,  1829,  1830,  1835,  1836,  1841,   349,
    1838,   209,   472,   473,   474,   475,   476,   477,   478,   479,
     480,   481,   482,   483,   484,   485,  1839,  1843,  1845,  1848,
     486,  1923,  1846,  1926,  1850,  1929,   314,  1860,  1874,  1851,
    1879,  1876,  1877,  1878,  1869,  1880,  1939,  1940,  1941,  1942,
    1943,  1881,  1882,  1883,  1896,  2015,   472,   473,   474,   475,
     476,   477,   478,   479,   480,   481,   482,   483,   484,   485,
    1889,  1902,  1903,  1904,   486,  1905,  1906,   349,   349,   349,
     349,   349,   472,   473,   474,   475,   476,   477,   478,   479,
     480,   481,   482,   483,   484,   485,  1907,  1909,   349,  1931,
     486,  1937,  1954,  1975,  1955,  1496,  1961,  1979,  1959,   377,
    1977,  1980,  1994,  1953,  1995,  2011,   472,   473,   474,   475,
     476,   477,   478,   479,   480,   481,   482,   483,   484,   485,
    1505,  1962,  1971,   613,   486,  2012,   616,   617,   618,   619,
    1974,  1768,  1982,  1769,  1978,  2027,  1998,  2032,  2034,  2037,
    2038,   498,  2041,  2042,  2045,  2046,   644,  2050,  2081,  2075,
    2098,   358,  2064,  2077,  2100,  2028,  2099,   349,  2079,  2030,
    2109,  2097,  2112,  2101,  2115,  2118,  2119,  2120,   497,  2121,
    2123,   472,   473,   474,   475,   476,   477,   478,   479,   480,
     481,   482,   483,   484,   485,  2055,  2129,  2133,  2134,   486,
    2155,  2139,  2141,  2143,   454,   455,   456,   458,   460,  2153,
     349,  2158,  2160,  2162,  2164,  2170,  2185,  2186,  2187,  2188,
    2189,   493,  2190,  2192,  2017,   500,   796,  1539,   497,  1524,
     497,  1899,   110,   120,   121,   122,   836,  1668,  1917,   507,
     509,   512,   513,     0,   515,   509,   517,   518,     0,   509,
     521,   522,   523,   524,   525,   526,     0,   528,   529,     0,
     497,     0,     0,   509,  2106,  2107,     0,     0,   538,   539,
       0,   752,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   558,     0,     0,     0,     0,     0,
       0,     0,     0,   567,   568,     0,     0,     0,     0,     0,
       0,     0,   568,   472,   473,   474,   475,   476,   477,   478,
     479,   480,   481,   482,   483,   484,   485,  2016,     0,     0,
       0,   486,     0,     0,  2131,     0,     0,     0,   472,   473,
     474,   475,   476,   477,   478,   479,   480,   481,   482,   483,
     484,   485,     0,   634,   636,   509,   486,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   646,   647,   648,
       0,   650,     0,     0,     0,   653,   654,   655,     0,     0,
     656,     0,     0,     0,  2169,     0,  2172,     0,     0,     0,
       0,     0,     0,     0,     0,   670,     0,     0,     0,     0,
     675,   677,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   684,   685,  2191,   687,   688,   689,
     690,   691,   692,   693,   694,   695,   696,   697,   698,   699,
     700,   701,   702,   703,   704,   705,   706,   707,   708,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   722,     0,     0,     0,     0,     0,   728,     0,
     730,  1591,     0,     0,     0,     0,     0,     0,     0,   498,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   759,   509,     0,   761,   762,   763,
     764,   765,   766,   767,   768,   769,   770,   771,   772,   773,
     774,   775,     0,     0,   777,   778,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   498,
       0,   498,     0,   634,     0,     0,     0,     0,     0,   805,
       0,     0,     0,     0,   810,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1645,   822,   823,     0,     0,
       0,   498,     0,     0,     0,   831,   832,     0,     0,     0,
     837,   839,   842,   845,   848,   850,     0,   852,     0,   854,
       0,   509,   509,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   872,
     873,   874,   454,   455,   875,     0,     0,     0,   880,   881,
     882,   883,   884,   885,   886,   887,   888,     0,     0,     0,
     893,     0,   895,   896,     0,     0,     0,   509,   509,   509,
       0,  1649,   903,   904,   905,   906,   907,     0,     0,   914,
     914,   919,   920,     0,   922,     0,     0,   924,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   509,     0,
       0,     0,     0,     0,   939,   941,     0,   943,   944,   472,
     473,   474,   475,   476,   477,   478,   479,   480,   481,   482,
     483,   484,   485,     0,   509,     0,     0,   486,     0,   906,
     907,     0,   943,   944,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   977,   509,     0,     0,     0,   981,     0,
       0,     0,     0,     0,     0,     0,     0,   130,   376,     0,
       0,     0,     0,   133,   134,   135,     0,     0,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,     0,     0,   472,   473,   474,   475,   476,   477,   478,
     479,   480,   481,   482,   483,   484,   485,   168,   169,   170,
     171,   486,     0,  1053,     0,   176,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   181,   182,   183,     0,
       0,     0,     0,     0,   184,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1080,  1081,     0,     0,   509,
    1087,  1088,     0,   509,  1091,     0,     0,     0,     0,     0,
       0,     0,  1098,     0,     0,   941,  1101,     0,     0,   472,
     473,   474,   475,   476,   477,   478,   479,   480,   481,   482,
     483,   484,   485,     0,     0,     0,  1121,   486,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1130,     0,
       0,     0,     0,     0,     0,     0,     0,  1280,  1281,     0,
       0,     0,     0,  1285,  1286,     0,     0,     0,     0,     0,
       0,     0,     0,   509,     0,     0,     0,     0,     0,     0,
    1155,  1156,     0,     0,     0,     0,  1159,   187,     0,     0,
       0,   191,     0,  1758,     0,   192,   193,   194,   195,   196,
       0,     0,     0,   105,  1188,     0,     0,  1190,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   199,   200,     0,
    1802,     0,   201,     0,     0,     0,   509,   339,   509,     0,
       0,   509,   205,     0,   557,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   509,     0,   509,     0,   509,     0,
     509,     0,     0,     0,     0,   509,     0,     0,     0,     0,
     509,     0,     0,     0,     0,     0,  1231,     0,  1233,  1234,
       0,     0,     0,     0,     0,     0,     0,   130,   376,  1241,
       0,     0,     0,   133,   134,   135,     0,     0,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,  1263,     0,     0,     0,     0,     0,     0,     0,  1264,
    1265,  1266,     0,   509,     0,     0,     0,   168,   169,   170,
     171,  1269,     0,     0,     0,   176,     0,     0,     0,     0,
    1834,     0,     0,     0,     0,  1276,   181,   182,   183,     0,
    1279,     0,     0,     0,   184,     0,     0,     0,     0,  1283,
       0,     0,     0,  1457,  1458,  1291,     0,     0,  1462,  1463,
       0,     0,     0,     0,     0,   509,   509,   509,   509,     0,
       0,  1305,     0,     0,     0,     0,     0,     0,     0,     0,
     530,   472,   473,   474,   475,   476,   477,   478,   479,   480,
     481,   482,   483,   484,   485,     0,     0,     0,     0,   486,
       0,   551,   553,   555,     0,     0,     0,   560,   472,   473,
     474,   475,   476,   477,   478,   479,   480,   481,   482,   483,
     484,   485,     0,     0,     0,     0,   486,     0,     0,   509,
       0,     0,     0,     0,     0,   594,     0,     0,     0,     0,
       0,     0,  1362,     0,  1364,     0,  1366,   187,  1368,     0,
       0,   191,     0,     0,     0,   192,   193,   194,   195,   196,
       0,     0,     0,   105,     0,     0,     0,     0,     0,  1873,
       0,  1388,     0,     0,     0,     0,     0,   577,   578,     0,
       0,     0,   201,     0,     0,     0,     0,   579,     0,     7,
       8,     0,   205,     0,   289,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1422,     0,     0,     0,     0,   672,
     673,     0,     0,  1427,  1428,     0,  1429,  1430,     0,  1431,
    1432,  1433,   681,     0,     0,     0,     0,  1438,   472,   473,
     474,   475,   476,   477,   478,   479,   480,   481,   482,   483,
     484,   485,     0,     0,     0,     0,   486,     0,     0,     0,
       0,     0,     0,     0,  1460,     0,     0,     0,     0,  1465,
     719,   754,    24,    25,   755,    27,    28,   756,    30,   757,
      32,    33,    34,    35,     0,     0,     0,    37,    38,    39,
       0,    40,     0,     0,     0,     0,    45,    46,    47,    48,
      49,     0,    51,    52,    53,     0,     0,     0,    56,     0,
       0,  1507,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1516,  1517,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1526,  1528,     0,
       0,     0,     0,     0,     0,     0,     0,    82,    83,    84,
       0,     0,   511,     0,     0,     0,     0,   516,     0,     0,
       0,   520,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   533,     0,   472,   473,   474,
     475,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,     0,  1578,  1579,  1580,   486,     7,     8,     0,     0,
       0,     0,     0,     0,  1592,     0,  1594,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1599,   876,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   509,
       0,     0,     0,     0,  1614,     0,     0,     0,     0,   472,
     473,   474,   475,   476,   477,   478,   479,   480,   481,   482,
     483,   484,   485,     0,     0,     0,  2010,   486,     0,     0,
    1631,  1632,  1633,     0,  1920,     0,  1921,     0,   754,    24,
      25,   755,    27,    28,   756,    30,   757,    32,    33,    34,
      35,  2082,     0,     0,    37,    38,    39,     0,    40,     0,
       0,     0,  1653,    45,    46,    47,    48,    49,     0,    51,
      52,    53,     0,     0,     0,    56,     0,     0,  1958,   639,
       0,     0,     0,     0,     0,     0,  1665,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1678,     0,     0,     0,     0,  1684,     0,     0,     0,     0,
       0,     0,     0,     0,    82,    83,    84,     0,     0,     0,
    1692,  1693,     0,     0,     0,     0,     0,  1698,  1699,     0,
       0,     0,  1701,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1042,  1708,     0,
       0,  1048,     0,     0,     0,     0,     0,   760,   509,   509,
    1720,     0,  1721,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1739,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   897,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   509,     0,     0,  1757,     0,
       0,     0,  2063,     0,     0,  1760,  1761,  1762,  1763,  1764,
    1765,  1766,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1774,     0,     0,   472,   473,   474,   475,   476,   477,
     478,   479,   480,   481,   482,   483,   484,   485,     0,     0,
    1131,  1794,   486,   856,   857,     0,     0,     0,     0,   472,
     473,   474,   475,   476,   477,   478,   479,   480,   481,   482,
     483,   484,   485,     0,  1809,  1810,     0,   486,     0,     0,
       0,     0,  1816,     0,     0,   472,   473,   474,   475,   476,
     477,   478,   479,   480,   481,   482,   800,   484,   485,   898,
     899,   900,   510,   486,     0,     0,     0,   510,     0,     0,
       0,   510,     0,     0,     0,     0,     0,     0,     0,     0,
    1837,     0,     0,     0,     0,   510,     0,     0,     0,     0,
     936,     0,     0,     0,     0,     0,     0,     0,     0,  1852,
       0,     0,     0,     0,     0,     0,     0,     0,   634,     0,
       0,     0,     0,     0,     0,     0,   958,     0,     0,     0,
       0,     0,     0,  1870,     0,  1871,     0,     0,   509,     0,
       0,     0,     0,     0,     0,     0,   978,     0,     0,     0,
       0,     0,     0,  1244,     0,  1885,     0,  1248,     0,     0,
       0,  1253,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1891,     0,   635,     0,   510,  1895,   472,
     473,   474,   475,   476,   477,   478,   479,   480,   481,   482,
     483,   484,   485,     0,     0,     0,     0,   486,   509,     0,
       0,     0,     0,     0,  1270,  1922,     0,  1925,     0,  1928,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   509,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1944,
    1945,  1946,  1947,  1948,  1949,     0,   472,   473,   474,   475,
     476,   477,   478,   479,   480,   481,   482,   483,   484,   485,
       0,  1086,     0,     0,   486,  1090,     0,  1963,  1964,     0,
       0,     0,  1966,  1064,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1972,     0,     0,     0,     0,     0,
       0,     0,     0,   639,     0,  1983,     0,     0,     0,     0,
    1331,  1332,     0,  1334,     0,  1337,  1338,     0,     0,  1341,
    1342,  1343,  1344,  1345,  1346,  1347,  1348,   510,     0,     0,
       0,     0,  1353,  1354,     0,     0,     0,     0,     0,     0,
       0,  2014,     0,     0,     0,  1149,     0,  1684,     0,     0,
       0,     0,     0,     0,     0,     0,  2025,     0,     0,     0,
       0,     0,     0,     0,     0,   635,     0,     0,     0,     0,
    2036,     0,     0,  2040,     0,     0,  2044,     0,     0,     0,
    2047,     0,     0,     0,     0,   509,   509,   509,   509,   509,
    2057,  2058,  2059,  2060,  2061,     0,     0,     0,  1202,     0,
    1203,     0,     0,  1205,  2067,     0,     0,  2069,     0,     0,
       0,     0,     0,   510,   510,     0,  1217,     0,  1218,     0,
    1219,     0,  1220,     0,     0,     0,     0,  1223,     0,     0,
       0,     0,  1226,  1441,  1442,  1443,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1455,
       0,     0,     0,     0,     0,     0,     0,  2105,     0,   510,
     510,   510,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   915,   917,     0,     0,   509,     0,  2124,  2125,  2126,
    2127,  2128,     0,     0,     0,     0,     0,     0,     0,     0,
     510,     0,     0,   954,     0,  1267,     0,   942,     0,   472,
     473,   474,   475,   476,   477,   478,   479,   480,   481,   482,
     800,   484,   485,     0,     0,  1519,   510,   486,     0,     0,
       0,  2156,  2157,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2165,  2166,  2167,  2168,   510,     0,  1066,  1540,
       0,   946,     0,     0,     0,  1546,     0,  1300,  1301,  1302,
    1303,     0,     0,     0,     0,     0,     0,  1557,  1222,     0,
       0,  1561,  1562,     0,     0,     0,  1565,  1566,     0,  1567,
       0,  1568,     0,  1569,     0,  1570,  1571,  1572,     0,     0,
       0,     0,     0,     0,   985,   986,   987,   988,   989,   990,
     991,   992,   993,   994,   995,  1593,   997,   998,   999,  1000,
    1001,  1002,  1003,     0,     0,     0,  1007,  1009,  1010,     0,
    1603,  1352,  1014,  1015,     0,  1017,     0,     0,  1611,     0,
    1022,  1023,  1024,     0,  1026,     0,     0,     0,     0,     0,
       0,  1034,  1036,     0,     0,     0,     0,     0,     0,     0,
       0,   510,     0,     0,     0,   510,     0,     0,     0,  1059,
       0,     0,     0,   130,   376,     0,     0,   942,  1102,   133,
     134,   135,     0,     0,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,     0,     0,   472,
     473,   474,   475,   476,   477,   478,   479,   480,   481,   482,
     483,   484,   485,   168,   169,   170,   171,   486,     0,     0,
       0,   176,     0,     0,     0,   510,     0,     0,     0,     0,
    1676,     0,   181,   182,   183,     0,     0,     0,     0,     0,
     184,     0,     0,  1688,   472,   473,   474,   475,   476,   477,
     478,   479,   480,   481,   482,   483,   484,   485,     0,     0,
       0,     0,   486,     0,   472,   473,   474,   475,   476,   477,
     478,   479,   480,   481,   482,   483,   484,   485,   510,  1446,
     510,     0,   486,   510,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   510,     0,   510,     0,
     510,     0,   510,     0,     0,  1738,     0,   510,     0,     0,
       0,     0,   510,     0,     0,     0,     0,     0,     0,     0,
    1519,     0,     0,     0,     0,     0,     0,     0,  1210,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   187,     0,     0,  1767,   191,     0,     0,
       0,   192,   193,   194,   195,   196,  1779,     0,     0,   105,
       0,     7,     8,     0,     0,     0,  1786,     0,     0,     0,
       0,  1791,     0,   199,   200,   510,     0,     0,   201,     0,
       0,     0,     0,   339,   457,     0,     0,     0,   205,     0,
       0,     0,     0,     0,     0,     0,     0,  1811,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1612,     0,     0,     0,     0,     0,     0,     0,     0,
    1519,     0,     0,     0,     0,     0,     0,   510,   510,   510,
     510,     0,     0,   754,    24,    25,   755,    27,    28,   756,
      30,   757,    32,    33,    34,    35,     0,     0,     0,    37,
      38,    39,     0,    40,     0,     0,     0,  1849,    45,    46,
      47,    48,    49,     0,    51,    52,    53,     0,     0,     0,
      56,     0,  1304,     0,     0,   472,   473,   474,   475,   476,
     477,   478,   479,   480,   481,   482,   483,   484,   485,     0,
       0,   510,     0,   486,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1326,  1327,     0,     0,    82,
      83,    84,     7,     8,   472,   473,   474,   475,   476,   477,
     478,   479,   480,   481,   482,   483,   484,   485,  1519,     0,
       0,     0,   486,     0,     0,  1900,  1901,     0,     0,     0,
       0,  1123,     0,     0,     0,     0,  1519,   472,   473,   474,
     475,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,     0,     0,     0,     0,   486,  1934,     0,     0,     0,
    1718,  1719,     0,     0,  1180,     0,     0,     0,     0,     0,
     959,     0,     0,     0,   754,    24,    25,   755,    27,    28,
     756,    30,   757,    32,    33,    34,    35,     0,     0,     0,
      37,    38,    39,     0,    40,     0,     0,     0,     0,    45,
      46,    47,    48,    49,     0,    51,    52,    53,     0,     0,
       0,    56,     0,     0,     0,     0,     0,     0,     0,  1976,
       0,   472,   473,   474,   475,   476,   477,   478,   479,   480,
     481,   482,   483,   484,   485,     0,     0,     0,  1993,   486,
       0,     0,     0,     0,     0,     0,     0,     0,  1213,     0,
      82,    83,    84,     0,  1467,     0,     0,     0,     0,     0,
    1471,  1472,  1473,  1474,  1475,     0,  1478,     0,  1480,  1481,
       0,  1484,  1487,     0,     0,  1491,  1492,  1493,     0,     0,
       0,     0,  1497,     0,     0,     0,     0,   130,   131,   132,
       0,     0,     0,   133,   134,   135,     0,     0,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   960,     0,     0,     0,     0,     0,  1519,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,     0,     0,     0,   177,
     178,   179,     0,     0,   180,     0,   181,   182,   183,     0,
    1872,   130,   376,     0,   184,   185,     0,   133,   134,   135,
       0,   510,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,     0,     0,   472,   473,   474,
     475,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,   168,   169,   170,   171,   486,     0,     0,     0,   176,
    1918,  1617,     0,     0,  1256,     0,     0,     0,     0,     0,
     181,   182,   183,     0,     0,     0,     0,  1627,   184,  1519,
       0,  1938,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1642,     0,     0,     0,     0,  1646,
     186,     0,     0,     0,     0,     0,     0,   187,   188,   189,
     190,   191,     0,     0,     0,   192,   193,   194,   195,   196,
     197,     0,   198,   105,     0,     0,     0,     0,     0,     0,
       0,  1659,  1660,     0,     0,  1662,  1663,   199,   200,     0,
       0,     0,   201,     0,     0,     0,     0,   202,     0,   203,
       0,   204,   205,     0,   206,     0,   207,     0,     0,     0,
       7,     8,     0,     0,     0,     0,     0,     0,     0,     0,
     510,   510,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   187,     0,     0,     0,   191,     0,     0,     0,   192,
     193,   194,   195,   196,     0,     0,     0,   105,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   510,     0,     0,
       0,   199,   200,     0,     0,     0,   201,     0,     0,     0,
       0,   339,     0,     0,   459,     0,   205,  2051,  2052,  2053,
    2054,  2056,   754,    24,    25,   755,    27,    28,   756,    30,
     757,    32,    33,    34,    35,     0,     0,     0,    37,    38,
      39,     0,    40,     0,     0,     0,     0,    45,    46,    47,
      48,    49,     0,    51,    52,    53,     0,     0,     0,    56,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1781,  1782,     0,     0,  1784,  1785,     0,     0,     0,     0,
    1788,  1789,     0,   472,   473,   474,   475,   476,   477,   478,
     479,   480,   481,   482,   483,   484,   485,     0,    82,    83,
      84,   486,     0,     0,     0,     0,     0,  2122,     0,     0,
    1380,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     7,     8,   472,   473,   474,   475,
     476,   477,   478,   479,   480,   481,   482,   483,   484,   485,
     635,     0,     0,     0,   486,     0,     0,     0,     0,     0,
       0,     0,     0,  1723,     0,     0,     0,     0,     0,     0,
     510,     0,     0,     0,     0,     0,     0,     0,     0,  1152,
       0,     0,     0,     0,     0,     0,     0,  1886,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1862,  1863,     0,
       0,     0,     0,     0,     0,     0,   754,    24,    25,   755,
      27,    28,   756,    30,   757,    32,    33,    34,    35,     0,
       0,     0,    37,    38,    39,     0,    40,     0,     0,     0,
     510,    45,    46,    47,    48,    49,     0,    51,    52,    53,
       0,   130,   326,    56,     0,     0,     0,   133,   134,   135,
       0,   510,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   328,   329,   330,   331,   332,
       0,     0,    82,    83,    84,     0,     0,     0,     0,     0,
       0,   168,   169,   170,   171,     0,     0,     0,     0,   176,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     181,   182,   183,     0,     0,     0,     0,     0,   184,     0,
       0,     0,   333,     0,     0,   334,     0,     0,   335,     0,
     336,     0,     0,     0,     0,     0,     0,    36,     0,   472,
     473,   474,   475,   476,   477,   478,   479,   480,   481,   482,
     483,   484,   485,  1153,   337,     0,     0,   486,     0,     0,
       0,    58,    59,    60,    61,    62,  1743,     0,    64,    65,
      66,    67,    68,     0,     0,    71,     0,     0,    74,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   510,   510,   510,
     510,   510,   472,   473,   474,   475,   476,   477,   478,   479,
     480,   481,   482,   483,   484,   485,     0,     0,     0,     0,
     486,   187,     0,     0,     0,   191,     0,     0,   666,   192,
     193,   194,   195,   196,     0,     0,     0,   105,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   577,  1753,     0,     0,     0,   201,     0,     0,     0,
       0,   579,     0,     0,     0,     0,   205,     0,   289,   637,
       0,     0,     0,     0,     0,     0,     0,     0,   130,   326,
       0,     0,     0,     0,   133,   134,   135,   510,     0,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   328,   329,   330,   331,   332,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   168,   169,
     170,   171,     0,     0,     0,     0,   176,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   181,   182,   183,
       0,     7,     8,     0,     0,   184,     0,     0,     0,   333,
       0,  2146,   334,     0,     0,   335,     0,   336,     0,     0,
       0,     0,     0,     0,    36,     0,   472,   473,   474,   475,
     476,   477,   478,   479,   480,   481,   482,   483,   484,   485,
       0,   337,     0,     0,   486,     0,     0,     0,    58,    59,
      60,    61,    62,  1821,     0,    64,    65,    66,    67,    68,
       0,     0,    71,     0,     0,    74,     0,     0,     0,     0,
       0,     0,     0,   754,    24,    25,   755,    27,    28,   756,
      30,   757,    32,    33,    34,    35,     0,     0,     0,    37,
      38,    39,     0,    40,     0,     0,     0,     0,    45,    46,
      47,    48,    49,     0,    51,    52,    53,     0,   187,     0,
      56,     0,   191,     0,     0,     0,   192,   193,   194,   195,
     196,     0,     0,     0,   105,     0,     0,   964,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   199,   508,
       0,     0,     0,   201,     0,     0,     0,     0,   339,    82,
      83,    84,     0,   205,     0,     0,   637,   130,   326,   132,
       0,     0,     0,   133,   134,   135,     0,     0,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   328,   329,   330,   331,   332,     0,     0,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,     0,     0,     0,   177,
     178,   179,     0,     0,   180,     0,   181,   182,   183,     0,
       0,     0,     0,     0,   184,   185,     0,     0,   333,     0,
       0,   334,     0,     0,   335,     0,   336,     0,     0,     0,
       0,     0,     0,    36,     0,   472,   473,   474,   475,   476,
     477,   478,   479,   480,   481,   482,   483,   484,   485,     0,
     337,     0,     0,   486,     0,     0,     0,    58,    59,    60,
      61,    62,  1822,     0,    64,    65,    66,    67,    68,     0,
       0,    71,     0,     0,    74,   472,   473,   474,   475,   476,
     477,   478,   479,   480,   481,   482,   483,   484,   485,     0,
       0,     0,     0,   486,     0,     0,     0,     0,     0,     0,
       0,     0,  1823,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   187,   188,   189,
     190,   191,     0,     0,     0,   192,   193,   194,   195,   196,
     197,     0,   198,   105,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   199,   338,     0,
       0,     0,   201,     0,     0,     0,     0,   339,     0,   130,
     326,   132,   205,     0,   340,   133,   134,   135,     0,     0,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   328,   329,   330,   331,   332,     0,     0,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,     0,     0,
       0,   177,   178,   179,     0,     0,   180,     0,   181,   182,
     183,     0,     0,     0,     0,     0,   184,   185,     0,     0,
     333,     0,     0,   334,     0,     0,   335,     0,   336,     0,
       0,     0,     0,     0,     0,    36,     0,     0,     0,     0,
       0,   366,   132,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   337,     0,     0,     0,     0,     0,     0,    58,
      59,    60,    61,    62,     0,     0,    64,    65,    66,    67,
      68,     0,     0,    71,     0,     0,    74,     0,     0,     0,
       0,   159,   160,   161,   162,   163,   164,   165,   166,   167,
       0,     0,     0,     0,   172,   173,   174,   175,     0,     0,
       0,     0,   177,   178,   179,     0,     0,   180,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   185,   187,
     188,   189,   190,   191,     0,     0,     0,   192,   193,   194,
     195,   196,   197,     0,   198,   105,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   199,
     338,     0,     0,     0,   201,     0,     0,     0,     0,   339,
       0,   130,   326,   327,   205,     0,  1790,   133,   134,   135,
       0,     0,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   328,   329,   330,   331,   332,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   168,   169,   170,   171,     0,     0,     0,     0,   176,
       0,   188,   189,   190,     0,     0,     0,     0,     0,     0,
     181,   182,   183,   197,     0,   198,   105,     0,   184,     0,
       0,     0,   333,     0,     0,   334,     0,     0,   335,     0,
     336,     0,     0,     0,     0,     0,     0,    36,   472,   473,
     474,   475,   476,   477,   478,   479,   480,   481,   482,   483,
     484,   485,     0,     0,   337,     0,   486,   494,   132,     0,
     746,    58,    59,    60,    61,    62,     0,     0,    64,    65,
      66,    67,    68,     0,     0,    71,     0,     0,    74,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   159,   160,   161,
     162,   163,   164,   165,   166,   167,     0,     0,     0,     0,
     172,   173,   174,   175,     0,     0,     0,     0,   177,   178,
     179,   187,     0,   180,     0,   191,     0,     0,     0,   192,
     193,   194,   195,   196,   185,     0,     0,   105,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   199,   338,     0,     0,     0,   201,     0,     0,     0,
       0,   339,     0,   130,   376,   132,   205,     0,   340,   133,
     134,   135,     0,     0,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,     0,     0,     0,
       0,     0,     0,     0,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,     7,     8,     0,   177,   178,   179,     0,     0,
     180,     0,   181,   182,   183,     0,     0,   188,   189,   190,
     184,   185,     0,     0,     0,     0,     0,     0,     0,   197,
       0,   198,   105,   472,   473,   474,   475,   476,   477,   478,
     479,   480,   481,   482,   483,   484,   485,     0,     0,     0,
       0,   486,     0,     0,     0,     0,     0,     0,     0,     0,
    1824,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   754,    24,    25,   755,    27,    28,
     756,    30,   757,    32,    33,    34,    35,     0,     0,     0,
      37,    38,    39,     0,    40,     0,     0,     0,     0,    45,
      46,    47,    48,    49,     0,    51,    52,    53,     0,     0,
       0,    56,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   187,   188,   189,   190,   191,     0,     0,
       0,   192,   193,   194,   195,   196,   197,     0,   198,   105,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      82,    83,    84,   199,   200,     0,     0,     0,   201,     0,
       0,     0,     0,   339,     0,   130,   326,  1602,   205,     0,
    1527,   133,   134,   135,     0,     0,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   328,
     329,   330,   331,   332,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   168,   169,   170,   171,     0,
       0,  1177,     0,   176,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   181,   182,   183,     0,     0,     0,
       0,     0,   184,     0,     0,     0,   333,     0,     0,   334,
       0,     0,   335,     0,   336,     0,     0,     0,     0,     0,
       0,    36,     0,   472,   473,   474,   475,   476,   477,   478,
     479,   480,   481,   482,   483,   484,   485,     0,   337,     0,
       0,   486,     0,     0,     0,    58,    59,    60,    61,    62,
    1825,     0,    64,    65,    66,    67,    68,     0,     0,    71,
       0,     0,    74,   472,   473,   474,   475,   476,   477,   478,
     479,   480,   481,   482,   483,   484,   485,     0,     0,     0,
       0,   486,     0,     0,     0,     0,     0,     0,     0,     0,
    1861,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   187,     0,     0,     0,   191,
       0,     0,     0,   192,   193,   194,   195,   196,     0,     0,
       0,   105,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   199,   338,     0,     0,     0,
     201,     0,     0,     0,     0,   339,     0,   130,   376,   132,
     205,     0,   340,   133,   134,   135,     0,     0,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,     0,     0,     0,     0,     0,     0,     0,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,     0,     0,     0,   177,
     178,   179,     0,     0,   180,     0,   181,   182,   183,     0,
     130,   376,   132,     0,   184,   185,   133,   134,   135,     0,
       0,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,     0,     0,     0,     0,     0,     0,
       0,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,     0,
       0,     0,   177,   178,   179,     0,     0,   180,     0,   181,
     182,   183,     0,     0,     0,     0,     0,   184,   185,   472,
     473,   474,   475,   476,   477,   478,   479,   480,   481,   482,
     483,   484,   485,     0,     0,     0,     0,   486,     0,     0,
       0,     0,     0,     0,     0,     0,  1936,   187,   188,   189,
     190,   191,     0,     0,     0,   192,   193,   194,   195,   196,
     197,     0,   198,   105,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   199,   200,     0,
       0,     0,   201,     0,     0,     0,     0,   339,     0,     0,
       0,     0,   205,     0,  1773,     0,     0,     0,   472,   473,
     474,   475,   476,   477,   478,   479,   480,   481,   482,   483,
     484,   485,     0,     0,     0,     0,   486,     0,     0,     0,
     187,   188,   189,   190,   191,  1950,     0,     0,   192,   193,
     194,   195,   196,   197,     0,   198,   105,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     199,   200,     0,     0,     0,   201,     0,     0,     0,     0,
     339,     0,   130,   326,     0,   205,     0,  1793,   133,   134,
     135,     0,     0,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   328,   329,   330,   331,
     332,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   168,   169,   170,   171,     0,     0,     0,     0,
     176,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   181,   182,   183,     0,     0,     0,     0,     0,   184,
       0,     0,     0,   333,     0,     0,   334,     0,     0,   335,
       0,   336,     0,     0,     0,     0,     0,     0,    36,     0,
       0,     0,     0,     0,   370,   132,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   337,     0,     0,     0,     0,
       0,     0,    58,    59,    60,    61,    62,     0,     0,    64,
      65,    66,    67,    68,     0,     0,    71,     0,     0,    74,
       0,     0,     0,     0,   159,   160,   161,   162,   163,   164,
     165,   166,   167,     0,     0,     0,     0,   172,   173,   174,
     175,     0,     0,     0,     0,   177,   178,   179,     0,     0,
     180,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   185,   187,     0,     0,     0,   191,     0,     0,     0,
     192,   193,   194,   195,   196,     0,     0,     0,   105,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   199,   338,     0,     0,     0,   201,     0,     0,
       0,     0,   339,     0,   130,   326,     0,   205,     0,   340,
     133,   134,   135,     0,     0,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   328,   329,
     330,   331,   332,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   168,   169,   170,   171,     0,     0,
       0,     0,   176,     0,   188,   189,   190,     0,     0,     0,
       0,     0,     0,   181,   182,   183,   197,     0,   198,     0,
       0,   184,     0,     0,     0,   333,     0,     0,   334,     0,
       0,   335,     0,   336,     0,     0,     0,     0,     0,     0,
      36,     0,     0,     0,     0,     0,     0,   132,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   337,     0,     0,
       0,     0,     0,     0,    58,    59,    60,    61,    62,     0,
       0,    64,    65,    66,    67,    68,     0,     0,    71,     0,
       0,    74,     0,     0,     0,     0,   159,   160,   161,   162,
     163,   164,   165,   166,   167,     0,     0,     0,     0,   172,
     173,   174,   175,     0,     0,     0,     0,   177,   178,   179,
       0,     0,   180,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   185,   187,     0,     0,     0,   191,     0,
       0,     0,   192,   193,   194,   195,   196,     0,     0,     0,
     105,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   199,   338,     0,     0,     0,   201,
       0,     0,     0,     0,   550,     0,   130,   326,     0,   205,
       0,   340,   133,   134,   135,     0,     0,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     328,   329,   330,   331,   332,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   168,   169,   170,   171,
       0,     0,     0,     0,   176,     0,   188,   189,   190,     0,
       0,     0,     0,     0,     0,   181,   182,   183,   197,     0,
     198,     0,     0,   184,     0,     0,     0,   333,     0,     0,
     334,     0,     0,   335,     0,   336,     0,     0,     0,     0,
       0,     0,    36,     0,   472,   473,   474,   475,   476,   477,
     478,   479,   480,   481,   482,   483,   484,   485,     0,   337,
       0,     0,   486,     0,     0,     0,    58,    59,    60,    61,
      62,  1951,     0,    64,    65,    66,    67,    68,     0,     0,
      71,     0,     0,    74,   472,   473,   474,   475,   476,   477,
     478,   479,   480,   481,   482,   483,   484,   485,     0,     0,
       0,     0,   486,     0,     0,     0,     0,     0,     0,     0,
       0,  1984,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   187,     0,     0,     0,
     191,     0,     0,     0,   192,   193,   194,   195,   196,     0,
       0,     0,   105,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   199,   338,     0,     0,
       0,   201,     0,     0,     0,     0,   552,     0,   130,   326,
       0,   205,     0,   340,   133,   134,   135,     0,     0,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   328,   329,   330,   331,   332,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   168,   169,
     170,   171,     0,     0,     0,     0,   176,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   181,   182,   183,
       0,     0,     0,     0,     0,   184,     0,     0,     0,   333,
       0,     0,   334,     0,     0,   335,     0,   336,     0,     0,
       0,     0,     0,     0,    36,     0,   472,   473,   474,   475,
     476,   477,   478,   479,   480,   481,   482,   483,   484,   485,
       0,   337,     0,     0,   486,     0,     0,     0,    58,    59,
      60,    61,    62,  1987,     0,    64,    65,    66,    67,    68,
       0,     0,    71,     0,     0,    74,   472,   473,   474,   475,
     476,   477,   478,   479,   480,   481,   482,   483,   484,   485,
       0,     0,     0,     0,   486,     0,     0,     0,     0,     0,
       0,     0,     0,  1990,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   187,     0,
       0,     0,   191,     0,     0,     0,   192,   193,   194,   195,
     196,     0,     0,     0,   105,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   199,   338,
       0,     0,     0,   201,     0,     0,     0,     0,   554,     0,
     130,   326,     0,   205,     0,   340,   133,   134,   135,     0,
       0,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   328,   329,   330,   331,   332,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     168,   169,   170,   171,     0,     0,     0,     0,   176,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   181,
     182,   183,     0,     0,     0,     0,     0,   184,     0,     0,
       0,   333,     0,     0,   334,     0,     0,   335,     0,   336,
       0,     0,     0,     0,     0,     0,    36,     0,   472,   473,
     474,   475,   476,   477,   478,   479,   480,   481,   482,   483,
     484,   485,     0,   337,     0,     0,   486,     0,     0,     0,
      58,    59,    60,    61,    62,  2026,     0,    64,    65,    66,
      67,    68,     0,     0,    71,     0,     0,    74,   472,   473,
     474,   475,   476,   477,   478,   479,   480,   481,   482,   483,
     484,   485,     0,     0,     0,     0,   486,     0,     0,     0,
       0,     0,     0,     0,     0,  2033,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     187,     0,     0,     0,   191,     0,     0,     0,   192,   193,
     194,   195,   196,     0,     0,     0,   105,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     199,   508,     0,     0,     0,   201,     0,     0,     0,     0,
     339,     0,   130,   326,     0,   205,     0,   633,   133,   134,
     135,     0,     0,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   328,   329,   330,   331,
     332,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   168,   169,   170,   171,     0,     0,     0,     0,
     176,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   181,   182,   183,     0,     0,     0,     0,     0,   184,
       0,     0,     0,   333,     0,     0,   334,     0,     0,   335,
       0,   336,     0,     0,     0,     0,     0,     0,    36,     0,
     472,   473,   474,   475,   476,   477,   478,   479,   480,   481,
     482,   483,   484,   485,     0,   337,     0,     0,   486,     0,
       0,     0,    58,    59,    60,    61,    62,  2076,     0,    64,
      65,    66,    67,    68,     0,     0,    71,     0,     0,    74,
     472,   473,   474,   475,   476,   477,   478,   479,   480,   481,
     482,   483,   484,   485,     0,     0,     0,     0,   486,     0,
       0,     0,     0,     0,     0,     0,     0,  2078,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   187,     0,     0,     0,   191,     0,     0,     0,
     192,   193,   194,   195,   196,     0,     0,     0,   105,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   199,   508,     0,     0,     0,   201,     0,     0,
       0,     0,   339,     0,   130,   326,     0,   205,     0,   913,
     133,   134,   135,     0,     0,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   328,   329,
     330,   331,   332,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   168,   169,   170,   171,     0,     0,
       0,     0,   176,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   181,   182,   183,     0,     0,     0,     0,
       0,   184,     0,     0,     0,   333,     0,     0,   334,     0,
       0,   335,     0,   336,     0,     0,     0,     0,     0,     0,
      36,     0,   472,   473,   474,   475,   476,   477,   478,   479,
     480,   481,   482,   483,   484,   485,     0,   337,     0,     0,
     486,     0,     0,     0,    58,    59,    60,    61,    62,  2080,
       0,    64,    65,    66,    67,    68,     0,     0,    71,     0,
       0,    74,   472,   473,   474,   475,   476,   477,   478,   479,
     480,   481,   482,   483,   484,   485,     0,     0,     0,     0,
     486,     0,     0,     0,     0,     0,     0,     0,     0,  2104,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   187,     0,     0,     0,   191,     0,
       0,     0,   192,   193,   194,   195,   196,     0,     0,     0,
     105,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   199,   508,     0,     0,     0,   201,
       0,     0,     0,     0,   339,     0,   130,   326,     0,   205,
       0,   916,   133,   134,   135,     0,     0,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     328,   329,   330,   331,   332,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   168,   169,   170,   171,
       0,     0,     0,     0,   176,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   181,   182,   183,     0,     0,
       0,     0,     0,   184,     0,     0,     0,   333,     0,     0,
     334,     0,     0,   335,     0,   336,     0,     0,     0,     0,
       0,     0,    36,     0,   472,   473,   474,   475,   476,   477,
     478,   479,   480,   481,   482,   483,   484,   485,     0,   337,
       0,     0,   486,     0,     0,     0,    58,    59,    60,    61,
      62,  2135,     0,    64,    65,    66,    67,    68,     0,     0,
      71,     0,     0,    74,   472,   473,   474,   475,   476,   477,
     478,   479,   480,   481,   482,   483,   484,   485,     0,     0,
       0,     0,   486,     0,     0,     0,     0,     0,     0,     0,
       0,  2174,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   187,     0,     0,     0,
     191,     0,     0,     0,   192,   193,   194,   195,   196,     0,
       0,     0,   105,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   199,   508,     0,     0,
       0,   201,     0,     0,     0,     0,   339,     0,   130,   326,
       0,   205,     0,   940,   133,   134,   135,     0,     0,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   328,   329,   330,   331,   332,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   168,   169,
     170,   171,     0,     0,     0,     0,   176,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   181,   182,   183,
       0,     0,     0,     0,     0,   184,     0,     0,     0,   333,
       0,     0,   334,     0,     0,   335,     0,   336,     0,     0,
       0,     0,     0,     0,    36,     0,   472,   473,   474,   475,
     476,   477,   478,   479,   480,   481,   482,   483,   484,   485,
       0,   337,     0,     0,   486,     0,     0,     0,    58,    59,
      60,    61,    62,  2175,     0,    64,    65,    66,    67,    68,
       0,     0,    71,     0,     0,    74,   472,   473,   474,   475,
     476,   477,   478,   479,   480,   481,   482,   483,   484,   485,
       0,     0,     0,     0,   486,     0,     0,     0,     0,     0,
       0,     0,     0,  2179,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   187,     0,
       0,     0,   191,     0,     0,     0,   192,   193,   194,   195,
     196,     0,     0,     0,   105,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   199,   338,
       0,     0,     0,   201,     0,     0,     0,     0,   339,     0,
     130,   326,     0,   205,     0,  1610,   133,   134,   135,     0,
       0,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   328,   329,   330,   331,   332,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     168,   169,   170,   171,     0,     0,     0,     0,   176,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   181,
     182,   183,     0,     0,     0,     0,     0,   184,     0,     0,
       0,   333,     0,     0,   334,     0,     0,   335,     0,   336,
       0,     0,     0,     0,     0,     0,    36,     0,   472,   473,
     474,   475,   476,   477,   478,   479,   480,   481,   482,   483,
     484,   485,     0,   337,     0,     0,   486,     0,     0,     0,
      58,    59,    60,    61,    62,  2180,     0,    64,    65,    66,
      67,    68,     0,     0,    71,     0,     0,    74,   472,   473,
     474,   475,   476,   477,   478,   479,   480,   481,   482,   483,
     484,   485,     0,     0,     0,     0,   486,     0,     0,     0,
       0,     0,     0,     0,     0,  2181,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     187,     0,     0,     0,   191,     0,     0,     0,   192,   193,
     194,   195,   196,     0,     0,     0,   105,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     577,  1753,     0,     0,     0,   201,     0,     0,     0,     0,
     579,     0,   130,   376,   132,   205,     0,   289,   133,   134,
     135,     0,     0,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,     0,     0,     0,     0,
       0,     0,     0,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,     0,     0,     0,   177,   178,   179,     0,     0,   180,
       0,   181,   182,   183,     0,     0,     0,     0,     0,   184,
     185,   472,   473,   474,   475,   476,   477,   478,   479,   480,
     481,   482,   483,   484,   485,     0,     0,     0,     0,   486,
       0,     0,   130,   376,     0,     0,     0,   858,   133,   134,
     135,     0,     0,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,     0,     0,   472,   473,
     474,   475,   476,   477,   478,   479,   480,   481,   482,   483,
     484,   485,   168,   169,   170,   171,   486,     0,     0,     0,
     176,     0,     0,     0,     0,  2182,     0,     0,     0,     0,
       0,   181,   182,   183,     0,     0,     0,     0,     0,   184,
       0,     0,   187,   188,   189,   190,   191,     0,     0,     0,
     192,   193,   194,   195,   196,   197,     0,   198,   105,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   199,   200,     0,     0,     0,   201,   130,   326,
       0,     0,   339,     0,   133,   134,   135,   205,     0,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   328,   329,   330,   331,   332,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   168,   169,
     170,   171,     0,     0,     0,     0,   176,     0,     0,     0,
       0,     0,   187,     0,     0,     0,   191,   181,   182,   183,
     192,   193,   194,   195,   196,   184,     0,     0,   105,   333,
       0,     0,   334,     0,     0,   335,     0,   336,     0,     0,
       0,     0,   199,   200,    36,     0,     0,   201,     0,     0,
       0,     0,   339,   674,     0,     0,     0,   205,     0,     0,
       0,   337,     0,     0,     0,     0,     0,     0,    58,    59,
      60,    61,    62,     0,     0,    64,    65,    66,    67,    68,
       0,     0,    71,     0,     0,    74,   472,   473,   474,   475,
     476,   477,   478,   479,   480,   481,   482,   483,   484,   485,
       0,     0,     0,     0,   486,     0,     0,     0,     0,     0,
       0,     0,  1833,   472,   473,   474,   475,   476,   477,   478,
     479,   480,   481,   482,   483,   484,   485,     0,   187,     0,
       0,   486,   191,   909,     0,   910,   192,   193,   194,   195,
     196,     0,     0,     0,   105,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   199,   508,
       0,     0,     0,   201,   130,   376,     0,     0,   339,     0,
     133,   134,   135,   205,     0,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,     0,     0,
     472,   473,   474,   475,   476,   477,   478,   479,   480,   481,
     482,   483,   484,   485,   168,   169,   170,   171,   486,     0,
     937,     0,   176,     0,     0,   865,     0,     0,     0,     0,
       0,     0,     0,   181,   182,   183,   130,   376,     0,  1240,
       0,   184,   133,   134,   135,     0,     0,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
       0,     0,   472,   473,   474,   475,   476,   477,   478,   479,
     480,   481,   482,   483,   484,   485,   168,   169,   170,   171,
     486,     0,     0,     0,   176,     0,     0,   789,     0,     0,
       0,     0,     0,     0,     0,   181,   182,   183,     0,     0,
       0,     0,     0,   184,   472,   473,   474,   475,   476,   477,
     478,   479,   480,   481,   482,   483,   484,   485,     0,     0,
       0,     0,   486,     0,   909,     0,   910,     0,     0,  1477,
       0,     0,     0,     0,   187,     0,     0,     0,   191,     0,
       0,     0,   192,   193,   194,   195,   196,     0,     0,     0,
     105,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   199,   200,     0,     0,     0,   201,
       0,     0,     0,     0,   339,     0,     0,   676,     0,   205,
     472,   473,   474,   475,   476,   477,   478,   479,   480,   481,
     482,   483,   484,   485,     0,     0,     0,     0,   486,     0,
       0,     0,     0,     0,     0,   865,   187,     0,     0,     0,
     191,     0,     0,     0,   192,   193,   194,   195,   196,     0,
       0,     0,   105,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   199,   200,     0,     0,
       0,   201,   130,   376,     0,  1387,   339,     0,   133,   134,
     135,   205,     0,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,     0,     0,   472,   473,
     474,   475,   476,   477,   478,   479,   480,   481,   482,   483,
     484,   485,   168,   169,   170,   171,   486,     0,     0,     0,
     176,     0,     0,   866,     0,     0,     0,     0,     0,   130,
     376,   181,   182,   183,     0,   133,   134,   135,     0,   184,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,     0,     0,   472,   473,   474,   475,   476,
     477,   478,   479,   480,   481,   482,   483,   484,   485,   168,
     169,   170,   171,   486,     0,     0,     0,   176,     0,     0,
     951,     0,     0,     0,     0,     0,     0,     0,   181,   182,
     183,     0,     0,     0,     0,     0,   184,   472,   473,   474,
     475,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,     0,     0,     0,     0,   486,     0,     0,     0,     0,
       0,     0,   996,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   187,     0,     0,     0,   191,     0,     0,     0,
     192,   193,   194,   195,   196,     0,     0,     0,   105,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   199,   200,     0,     0,     0,   201,     0,     0,
       0,     0,   339,     7,     8,     0,     0,   205,     0,   472,
     473,   474,   475,   476,   477,   478,   479,   480,   481,   482,
     483,   484,   485,     0,     0,     0,     0,   486,     0,   187,
       0,     0,     0,   191,  1004,     0,     0,   192,   193,   194,
     195,   196,     0,     0,     0,   105,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     7,     8,   199,
     200,     0,     0,     0,   201,     0,     0,     0,     0,   339,
       0,     0,     0,     0,   205,   754,    24,    25,   755,    27,
      28,   756,    30,   757,    32,    33,    34,    35,     0,     0,
       0,    37,    38,    39,     0,    40,     0,     0,     0,     0,
      45,    46,    47,    48,    49,     0,    51,    52,    53,     0,
       0,     0,    56,     0,     0,     0,     0,     0,     0,     0,
       7,     8,     0,     0,     0,     0,     0,     0,     0,   754,
      24,    25,   755,    27,    28,   756,    30,   757,    32,    33,
      34,    35,     0,     0,     0,    37,    38,    39,     0,    40,
       0,    82,    83,    84,    45,    46,    47,    48,    49,     0,
      51,    52,    53,     0,     0,     0,    56,     0,     0,     0,
       0,     0,     0,     0,     7,     8,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   754,    24,    25,   755,    27,    28,   756,    30,
     757,    32,    33,    34,    35,    82,    83,    84,    37,    38,
      39,     0,    40,     0,     0,     0,     0,    45,    46,    47,
      48,    49,  1232,    51,    52,    53,     0,     0,     0,    56,
       0,     0,     0,     0,     0,     0,     0,     7,     8,     0,
       0,     0,     0,     0,     0,     0,   754,    24,    25,   755,
      27,    28,   756,    30,   757,    32,    33,    34,    35,     0,
       0,     0,    37,    38,    39,     0,    40,     0,    82,    83,
      84,    45,    46,    47,    48,    49,  1238,    51,    52,    53,
       0,     0,     0,    56,   472,   473,   474,   475,   476,   477,
     478,   479,   480,   481,   482,   483,   484,   485,     0,     0,
       0,     0,   486,     0,     0,     0,   957,     0,     0,   754,
      24,    25,   755,    27,    28,   756,    30,   757,    32,    33,
      34,    35,    82,    83,    84,    37,    38,    39,     0,    40,
       0,     0,     0,     0,    45,    46,    47,    48,    49,  1376,
      51,    52,    53,     0,     0,     0,    56,     0,     0,     0,
       0,     0,     0,    -4,     1,     0,     0,    -4,     0,     0,
       0,     0,     0,     0,     0,    -4,    -4,     0,     0,     0,
     472,   473,   474,   475,   476,   477,   478,   479,   480,   481,
     482,   483,   484,   485,     0,    82,    83,    84,   486,     0,
       0,     0,   976,  1996,     0,    -4,    -4,     0,     0,     0,
     472,   473,   474,   475,   476,   477,   478,   479,   480,   481,
     482,   483,   484,   485,     0,    -4,    -4,    -4,   486,     0,
       0,    -4,    -4,     0,    -4,  1005,     0,     0,    -4,    -4,
       0,    -4,    -4,     0,     0,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
       0,     0,    -4,    -4,    -4,    -4,  2084,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,     0,     0,     0,    -4,
      -4,    -4,     0,     0,     0,     0,     0,    -4,     6,     0,
       0,     0,    -4,    -4,    -4,    -4,     7,     8,    -4,     0,
      -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,     0,     0,     0,     0,
       0,    -4,    -4,    -4,     0,     0,     9,    10,     0,     0,
      -4,     0,    -4,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    11,    12,    13,     0,
       0,     0,    14,    15,     0,    16,     0,     0,     0,    17,
      18,     0,    19,    20,     0,     0,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,     0,     0,    36,    37,    38,    39,     0,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,     0,    55,    56,    57,    58,    59,    60,
      61,    62,    63,     0,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,     7,     8,     0,
      77,    78,    79,     0,     0,     0,     0,     0,    80,     0,
       0,     0,     0,    81,    82,    83,    84,     0,     0,    85,
       0,    86,     0,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,     0,     0,     0,
       0,     0,   101,   102,   103,     0,     0,     0,     0,     0,
       0,   104,     0,   105,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   754,
      24,    25,   755,    27,    28,   756,    30,   757,    32,    33,
      34,    35,     0,     0,     0,    37,    38,    39,     0,    40,
       0,     0,     0,     0,    45,    46,    47,    48,    49,     0,
      51,    52,    53,     0,     0,     0,    56,   472,   473,   474,
     475,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,     0,     0,     0,     0,   486,     0,     0,     0,     0,
       0,     0,  1006,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    82,    83,    84,   472,   473,
     474,   475,   476,   477,   478,   479,   480,   481,   482,   483,
     484,   485,     0,     0,     0,     0,   486,     0,     0,     0,
       0,     0,     0,  1021,   472,   473,   474,   475,   476,   477,
     478,   479,   480,   481,   482,   483,   484,   485,     0,     0,
       0,     0,   486,     0,     0,     0,     0,     0,     0,  1161,
     472,   473,   474,   475,   476,   477,   478,   479,   480,   481,
     482,   483,   484,   485,     0,     0,     0,     0,   486,     0,
       0,     0,     0,     0,     0,  1162,   472,   473,   474,   475,
     476,   477,   478,   479,   480,   481,   482,   483,   484,   485,
       0,     0,     0,     0,   486,     0,     0,     0,     0,     0,
       0,  1163,   472,   473,   474,   475,   476,   477,   478,   479,
     480,   481,   482,   483,   484,   485,     0,     0,     0,     0,
     486,     0,     0,     0,     0,     0,     0,  1199,   472,   473,
     474,   475,   476,   477,   478,   479,   480,   481,   482,   483,
     484,   485,     0,     0,     0,     0,   486,     0,     0,     0,
       0,     0,     0,  1208,   472,   473,   474,   475,   476,   477,
     478,   479,   480,   481,   482,   483,   484,   485,     0,     0,
       0,     0,   486,     0,     0,     0,     0,     0,     0,  1209,
     472,   473,   474,   475,   476,   477,   478,   479,   480,   481,
     482,   483,   484,   485,     0,     0,     0,     0,   486,     0,
       0,     0,     0,     0,     0,  1211,   472,   473,   474,   475,
     476,   477,   478,   479,   480,   481,   482,   483,   484,   485,
       0,     0,     0,     0,   486,     0,     0,     0,     0,     0,
       0,  1322,   472,   473,   474,   475,   476,   477,   478,   479,
     480,   481,   482,   483,   484,   485,     0,     0,     0,     0,
     486,     0,     0,     0,     0,     0,     0,  1378,   472,   473,
     474,   475,   476,   477,   478,   479,   480,   481,   482,   483,
     484,   485,     0,     0,     0,     0,   486,     0,     0,     0,
       0,     0,     0,  1379,   472,   473,   474,   475,   476,   477,
     478,   479,   480,   481,   482,   483,   484,   485,     0,     0,
       0,     0,   486,     0,     0,     0,     0,     0,     0,  1445,
     472,   473,   474,   475,   476,   477,   478,   479,   480,   481,
     482,   483,   484,   485,     0,     0,     0,     0,   486,     0,
       0,     0,     0,     0,     0,  1620,   472,   473,   474,   475,
     476,   477,   478,   479,   480,   481,   482,   483,   484,   485,
       0,     0,     0,     0,   486,     0,     0,     0,     0,     0,
       0,  1621,   472,   473,   474,   475,   476,   477,   478,   479,
     480,   481,   482,   483,   484,   485,     0,     0,     0,     0,
     486,     0,     0,     0,     0,     0,     0,  1622,   472,   473,
     474,   475,   476,   477,   478,   479,   480,   481,   482,   483,
     484,   485,     0,     0,     0,     0,   486,     0,     0,     0,
       0,     0,     0,  1623,   472,   473,   474,   475,   476,   477,
     478,   479,   480,   481,   482,   483,   484,   485,     0,     0,
       0,     0,   486,     0,     0,     0,     0,     0,     0,  1624,
     472,   473,   474,   475,   476,   477,   478,   479,   480,   481,
     482,   483,   484,   485,     0,     0,     0,     0,   486,     0,
       0,     0,     0,     0,     0,  1625,   472,   473,   474,   475,
     476,   477,   478,   479,   480,   481,   482,   483,   484,   485,
       0,     0,     0,     0,   486,     0,     0,     0,     0,     0,
       0,  1626,   472,   473,   474,   475,   476,   477,   478,   479,
     480,   481,   482,   483,   484,   485,     0,     0,     0,     0,
     486,     0,     0,     0,     0,     0,     0,  1679,   472,   473,
     474,   475,   476,   477,   478,   479,   480,   481,   482,   483,
     484,   485,     0,     0,     0,     0,   486,     0,     0,     0,
       0,     0,     0,  1680,   472,   473,   474,   475,   476,   477,
     478,   479,   480,   481,   482,   483,   484,   485,     0,     0,
       0,     0,   486,     0,     0,     0,     0,     0,     0,  1687,
     472,   473,   474,   475,   476,   477,   478,   479,   480,   481,
     482,   483,   484,   485,     0,     0,     0,     0,   486,     0,
       0,     0,     0,     0,     0,  1864,   472,   473,   474,   475,
     476,   477,   478,   479,   480,   481,   482,   483,   484,   485,
       0,     0,     0,     0,   486,     0,     0,     0,     0,     0,
       0,  1865,   472,   473,   474,   475,   476,   477,   478,   479,
     480,   481,   482,   483,   484,   485,     0,     0,     0,     0,
     486,     0,     0,     0,     0,     0,     0,  1866,   472,   473,
     474,   475,   476,   477,   478,   479,   480,   481,   482,   483,
     484,   485,     0,     0,     0,     0,   486,     0,     0,     0,
       0,     0,     0,  1867,   472,   473,   474,   475,   476,   477,
     478,   479,   480,   481,   482,   483,   484,   485,     0,     0,
       0,     0,   486,     0,     0,     0,     0,     0,     0,  1868,
     472,   473,   474,   475,   476,   477,   478,   479,   480,   481,
     482,   483,   484,   485,     0,     0,     0,     0,   486,     0,
       0,     0,     0,     0,     0,  1892,   472,   473,   474,   475,
     476,   477,   478,   479,   480,   481,   482,   483,   484,   485,
       0,     0,     0,     0,   486,     0,     0,     0,     0,     0,
       0,  1893,   472,   473,   474,   475,   476,   477,   478,   479,
     480,   481,   482,   483,   484,   485,     0,     0,     0,     0,
     486,     0,     0,     0,     0,     0,     0,  1897,   472,   473,
     474,   475,   476,   477,   478,   479,   480,   481,   482,   483,
     484,   485,     0,     0,     0,     0,   486,     0,     0,     0,
       0,     0,     0,  2005,   472,   473,   474,   475,   476,   477,
     478,   479,   480,   481,   482,   483,   484,   485,     0,     0,
       0,     0,   486,     0,     0,     0,     0,     0,     0,  2006,
     472,   473,   474,   475,   476,   477,   478,   479,   480,   481,
     482,   483,   484,   485,     0,     0,     0,     0,   486,     0,
       0,     0,     0,     0,     0,  2007,   472,   473,   474,   475,
     476,   477,   478,   479,   480,   481,   482,   483,   484,   485,
       0,     0,     0,     0,   486,     0,     0,     0,     0,     0,
       0,  2008,   472,   473,   474,   475,   476,   477,   478,   479,
     480,   481,   482,   483,   484,   485,     0,     0,     0,     0,
     486,     0,     0,     0,     0,     0,     0,  2009,   472,   473,
     474,   475,   476,   477,   478,   479,   480,   481,   482,   483,
     484,   485,     0,     0,     0,     0,   486,     0,     0,     0,
       0,     0,     0,  2019,   472,   473,   474,   475,   476,   477,
     478,   479,   480,   481,   482,   483,   484,   485,     0,     0,
       0,     0,   486,     0,     0,     0,     0,     0,     0,  2022,
     472,   473,   474,   475,   476,   477,   478,   479,   480,   481,
     482,   483,   484,   485,     0,     0,     0,     0,   486,     0,
       0,     0,     0,     0,     0,  2072,   472,   473,   474,   475,
     476,   477,   478,   479,   480,   481,   482,   483,   484,   485,
       0,     0,     0,     0,   486,     0,     0,     0,     0,     0,
       0,  2092,   472,   473,   474,   475,   476,   477,   478,   479,
     480,   481,   482,   483,   484,   485,     0,     0,     0,     0,
     486,     0,     0,     0,     0,     0,     0,  2093,   472,   473,
     474,   475,   476,   477,   478,   479,   480,   481,   482,   483,
     484,   485,     0,     0,     0,     0,   486,     0,     0,     0,
       0,     0,     0,  2094,   472,   473,   474,   475,   476,   477,
     478,   479,   480,   481,   482,   483,   484,   485,     0,     0,
       0,     0,   486,     0,     0,     0,     0,     0,     0,  2095,
     472,   473,   474,   475,   476,   477,   478,   479,   480,   481,
     482,   483,   484,   485,     0,     0,     0,     0,   486,     0,
       0,     0,     0,     0,     0,  2096,   472,   473,   474,   475,
     476,   477,   478,   479,   480,   481,   482,   483,   484,   485,
       0,     0,     0,     0,   486,     0,     0,     0,     0,     0,
       0,  2147,   472,   473,   474,   475,   476,   477,   478,   479,
     480,   481,   482,   483,   484,   485,     0,     0,     0,     0,
     486,     0,     0,     0,     0,     0,     0,  2148,   472,   473,
     474,   475,   476,   477,   478,   479,   480,   481,   482,   483,
     484,   485,     0,     0,     0,     0,   486,     0,     0,     0,
       0,     0,     0,  2149,   472,   473,   474,   475,   476,   477,
     478,   479,   480,   481,   482,   483,   484,   485,     0,     0,
       0,     0,   486,     0,     0,     0,     0,     0,     0,  2150,
     472,   473,   474,   475,   476,   477,   478,   479,   480,   481,
     482,   483,   484,   485,     0,     0,     0,     0,   486,     0,
       0,     0,   983,   472,   473,   474,   475,   476,   477,   478,
     479,   480,   481,   482,   483,   484,   485,     0,     0,     0,
       0,   486,     0,     0,     0,  1079,   472,   473,   474,   475,
     476,   477,   478,   479,   480,   481,   482,   483,   484,   485,
       0,     0,     0,     0,   486,     0,     0,     0,  1192,   472,
     473,   474,   475,   476,   477,   478,   479,   480,   481,   482,
     483,   484,   485,     0,     0,     0,     0,   486,     0,     0,
       0,  1193,   472,   473,   474,   475,   476,   477,   478,   479,
     480,   481,   482,   483,   484,   485,     0,     0,     0,     0,
     486,     0,     0,     0,  1197,   472,   473,   474,   475,   476,
     477,   478,   479,   480,   481,   482,   483,   484,   485,     0,
       0,     0,     0,   486,     0,     0,     0,  1198,   472,   473,
     474,   475,   476,   477,   478,   479,   480,   481,   482,   483,
     484,   485,     0,     0,     0,     0,   486,     0,     0,     0,
    1201,   472,   473,   474,   475,   476,   477,   478,   479,   480,
     481,   482,   483,   484,   485,     0,     0,     0,     0,   486,
       0,     0,     0,  1225,   472,   473,   474,   475,   476,   477,
     478,   479,   480,   481,   482,   483,   484,   485,     0,     0,
       0,     0,   486,     0,     0,     0,  1258,   472,   473,   474,
     475,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,     0,     0,     0,     0,   486,     0,     0,     0,  1315,
     472,   473,   474,   475,   476,   477,   478,   479,   480,   481,
     482,   483,   484,   485,     0,     0,     0,     0,   486,     0,
       0,     0,  1320,   472,   473,   474,   475,   476,   477,   478,
     479,   480,   481,   482,   483,   484,   485,     0,     0,     0,
       0,   486,     0,     0,     0,  1615,   472,   473,   474,   475,
     476,   477,   478,   479,   480,   481,   482,   483,   484,   485,
       0,     0,     0,     0,   486,     0,     0,     0,  1670,   472,
     473,   474,   475,   476,   477,   478,   479,   480,   481,   482,
     483,   484,   485,     0,     0,     0,     0,   486,     0,     0,
       0,  1847,   472,   473,   474,   475,   476,   477,   478,   479,
     480,   481,   482,   483,   484,   485,     0,     0,     0,     0,
     486,     0,   742,   472,   473,   474,   475,   476,   477,   478,
     479,   480,   481,   482,   483,   484,   485,     0,     0,     0,
       0,   486,     0,   799,   472,   473,   474,   475,   476,   477,
     478,   479,   480,   481,   482,   483,   484,   485,     0,     0,
       0,     0,   486,     0,   803,   472,   473,   474,   475,   476,
     477,   478,   479,   480,   481,   482,   483,   484,   485,     0,
       0,     0,     0,   486,     0,   804,   472,   473,   474,   475,
     476,   477,   478,   479,   480,   481,   482,   483,   484,   485,
       0,     0,     0,     0,   486,     0,   806,   472,   473,   474,
     475,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,     0,     0,     0,     0,   486,     0,   808,   472,   473,
     474,   475,   476,   477,   478,   479,   480,   481,   482,   483,
     484,   485,     0,     0,     0,     0,   486,     0,   809,   472,
     473,   474,   475,   476,   477,   478,   479,   480,   481,   482,
     483,   484,   485,     0,     0,     0,     0,   486,     0,   812,
     472,   473,   474,   475,   476,   477,   478,   479,   480,   481,
     482,   483,   484,   485,     0,     0,     0,     0,   486,     0,
     813,   472,   473,   474,   475,   476,   477,   478,   479,   480,
     481,   482,   483,   484,   485,     0,     0,     0,     0,   486,
       0,   814,   472,   473,   474,   475,   476,   477,   478,   479,
     480,   481,   482,   483,   484,   485,     0,     0,     0,     0,
     486,     0,   815,   472,   473,   474,   475,   476,   477,   478,
     479,   480,   481,   482,   483,   484,   485,     0,     0,     0,
       0,   486,     0,   816,   472,   473,   474,   475,   476,   477,
     478,   479,   480,   481,   482,   483,   484,   485,     0,     0,
       0,     0,   486,     0,   817,   472,   473,   474,   475,   476,
     477,   478,   479,   480,   481,   482,   483,   484,   485,     0,
       0,     0,     0,   486,     0,   819,   472,   473,   474,   475,
     476,   477,   478,   479,   480,   481,   482,   483,   484,   485,
       0,     0,     0,     0,   486,     0,   820,   472,   473,   474,
     475,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,     0,     0,     0,     0,   486,     0,   829,   472,   473,
     474,   475,   476,   477,   478,   479,   480,   481,   482,   483,
     484,   485,     0,     0,     0,     0,   486,     0,   830,   472,
     473,   474,   475,   476,   477,   478,   479,   480,   481,   482,
     483,   484,   485,     0,     0,     0,     0,   486,     0,   937,
     472,   473,   474,   475,   476,   477,   478,   479,   480,   481,
     482,   483,   484,   485,     0,     0,     0,     0,   486,     0,
     947,   472,   473,   474,   475,   476,   477,   478,   479,   480,
     481,   482,   483,   484,   485,     0,     0,     0,     0,   486,
       0,   948,   472,   473,   474,   475,   476,   477,   478,   479,
     480,   481,   482,   483,   484,   485,     0,     0,     0,     0,
     486,     0,   949,   472,   473,   474,   475,   476,   477,   478,
     479,   480,   481,   482,   483,   484,   485,     0,     0,     0,
       0,   486,     0,   955,   472,   473,   474,   475,   476,   477,
     478,   479,   480,   481,   482,   483,   484,   485,     0,     0,
       0,     0,   486,     0,   956,   472,   473,   474,   475,   476,
     477,   478,   479,   480,   481,   482,   483,   484,   485,     0,
       0,     0,     0,   486,     0,   963,   472,   473,   474,   475,
     476,   477,   478,   479,   480,   481,   482,   483,   484,   485,
       0,     0,     0,     0,   486,     0,   972,   472,   473,   474,
     475,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,     0,     0,     0,     0,   486,     0,   982,   472,   473,
     474,   475,   476,   477,   478,   479,   480,   481,   482,   483,
     484,   485,     0,     0,     0,     0,   486,     0,  1078,   472,
     473,   474,   475,   476,   477,   478,   479,   480,   481,   482,
     483,   484,   485,     0,     0,     0,     0,   486,     0,  1106,
     472,   473,   474,   475,   476,   477,   478,   479,   480,   481,
     482,   483,   484,   485,     0,     0,     0,     0,   486,     0,
    1111,   472,   473,   474,   475,   476,   477,   478,   479,   480,
     481,   482,   483,   484,   485,     0,     0,     0,     0,   486,
       0,  1122,   472,   473,   474,   475,   476,   477,   478,   479,
     480,   481,   482,   483,   484,   485,     0,     0,     0,     0,
     486,     0,  1128,   472,   473,   474,   475,   476,   477,   478,
     479,   480,   481,   482,   483,   484,   485,     0,     0,     0,
       0,   486,     0,  1129,   472,   473,   474,   475,   476,   477,
     478,   479,   480,   481,   482,   483,   484,   485,     0,     0,
       0,     0,   486,     0,  1135,   472,   473,   474,   475,   476,
     477,   478,   479,   480,   481,   482,   483,   484,   485,     0,
       0,     0,     0,   486,     0,  1144,   472,   473,   474,   475,
     476,   477,   478,   479,   480,   481,   482,   483,   484,   485,
       0,     0,     0,     0,   486,     0,  1145,   472,   473,   474,
     475,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,     0,     0,     0,     0,   486,     0,  1146,   472,   473,
     474,   475,   476,   477,   478,   479,   480,   481,   482,   483,
     484,   485,     0,     0,     0,     0,   486,     0,  1179,   472,
     473,   474,   475,   476,   477,   478,   479,   480,   481,   482,
     483,   484,   485,     0,     0,     0,     0,   486,     0,  1181,
     472,   473,   474,   475,   476,   477,   478,   479,   480,   481,
     482,   483,   484,   485,     0,     0,     0,     0,   486,     0,
    1182,   472,   473,   474,   475,   476,   477,   478,   479,   480,
     481,   482,   483,   484,   485,     0,     0,     0,     0,   486,
       0,  1183,   472,   473,   474,   475,   476,   477,   478,   479,
     480,   481,   482,   483,   484,   485,     0,     0,     0,     0,
     486,     0,  1184,   472,   473,   474,   475,   476,   477,   478,
     479,   480,   481,   482,   483,   484,   485,     0,     0,     0,
       0,   486,     0,  1185,   472,   473,   474,   475,   476,   477,
     478,   479,   480,   481,   482,   483,   484,   485,     0,     0,
       0,     0,   486,     0,  1186,   472,   473,   474,   475,   476,
     477,   478,   479,   480,   481,   482,   483,   484,   485,     0,
       0,     0,     0,   486,     0,  1187,   472,   473,   474,   475,
     476,   477,   478,   479,   480,   481,   482,   483,   484,   485,
       0,     0,     0,     0,   486,     0,  1191,   472,   473,   474,
     475,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,     0,     0,     0,     0,   486,     0,  1200,   472,   473,
     474,   475,   476,   477,   478,   479,   480,   481,   482,   483,
     484,   485,     0,     0,     0,     0,   486,     0,  1224,   472,
     473,   474,   475,   476,   477,   478,   479,   480,   481,   482,
     483,   484,   485,     0,     0,     0,     0,   486,     0,  1314,
     472,   473,   474,   475,   476,   477,   478,   479,   480,   481,
     482,   483,   484,   485,     0,     0,     0,     0,   486,     0,
    1319,   472,   473,   474,   475,   476,   477,   478,   479,   480,
     481,   482,   483,   484,   485,     0,     0,     0,     0,   486,
       0,  1489,   472,   473,   474,   475,   476,   477,   478,   479,
     480,   481,   482,   483,   484,   485,     0,     0,     0,     0,
     486,     0,  1724,   472,   473,   474,   475,   476,   477,   478,
     479,   480,   481,   482,   483,   484,   485,     0,     0,     0,
       0,   486,     0,  1742,   472,   473,   474,   475,   476,   477,
     478,   479,   480,   481,   482,   483,   484,   485,     0,     0,
       0,     0,   486,     0,  1772,   472,   473,   474,   475,   476,
     477,   478,   479,   480,   481,   482,   483,   484,   485,     0,
       0,     0,     0,   486,     0,  2018,   472,   473,   474,   475,
     476,   477,   478,   479,   480,   481,   482,   483,   484,   485,
       0,     0,     0,     0,   486,     0,  2102,   472,   473,   474,
     475,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,     0,     0,     0,     0,   486
};

static const yytype_int16 yycheck[] =
{
       3,   282,   424,     6,   426,     4,  1174,  1638,  1639,     4,
     571,   572,     4,     6,     4,     4,     4,  1604,     4,   441,
    1178,     6,     4,     6,     4,     4,     3,     5,     4,  1817,
       5,     5,   223,     5,     4,     4,     0,     5,     5,   230,
       6,     6,     5,     5,     5,   297,     5,   129,   119,     6,
       4,     6,     4,     6,     6,    13,     7,     4,     6,   213,
     214,   313,   213,   214,     7,   227,     6,   213,   214,    72,
     232,   119,   213,   214,   213,   214,   230,    80,   229,     6,
       6,   224,    85,   229,     4,   231,   229,   135,   229,     8,
     231,   230,     6,    96,     6,   143,   144,   145,   213,   214,
     223,   149,   150,   151,   152,   213,   214,   213,   214,   220,
     221,   213,   214,    96,   229,    98,   231,  1704,   223,   230,
       7,   373,   230,   375,   457,   231,   459,   229,   461,   381,
      90,     7,    84,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   220,   221,     6,
     165,   222,    90,     7,   224,   213,   214,   230,     7,   229,
     155,   156,   157,   158,    84,   223,   181,   182,    88,   223,
      59,    60,   230,    62,    94,    95,   230,    97,    98,   220,
     221,  1969,  1970,   231,   176,   223,     6,   225,   153,   230,
     168,     7,   112,   168,   168,     7,   168,    87,   220,   221,
      90,   180,   205,   220,   221,   153,     6,   199,   230,   199,
     227,   165,   166,   153,   217,   218,     6,   199,   165,   166,
     213,   214,   225,     7,   223,  1812,   225,   153,   227,   206,
     233,     6,   235,   232,   223,  1403,   231,   240,   230,   225,
     230,   244,   230,  1830,   210,   230,   232,   223,   251,   232,
     230,   254,   230,   223,   230,   258,   259,   260,   261,   262,
     230,   230,   230,   230,   267,   268,   269,   230,   230,   230,
     223,   230,   275,   276,   277,   230,   227,   230,   281,   282,
     223,     3,   225,   210,     6,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   213,
     214,   213,   214,   222,   307,   308,   309,   213,   214,     6,
     562,   563,   231,   200,   201,   202,   203,   224,   321,   322,
       7,   223,   229,   229,   200,   201,   202,   203,   220,   221,
     582,     7,     4,   220,   221,   338,    87,   340,   230,    90,
     227,   674,     7,   676,   220,   221,   200,   201,   202,   203,
      72,   200,   201,   202,   203,   220,   221,   213,   214,     6,
     217,   218,   223,    85,   223,   230,   220,   221,   223,   230,
     225,   220,   221,   229,    96,   225,   379,   232,   224,   461,
     383,   384,  2013,   229,   200,   201,   202,   203,   200,   201,
     202,   203,   226,   396,   251,   229,   285,   286,   223,   651,
     225,   223,   227,   225,   293,   262,   389,   232,   297,   742,
     232,   103,   226,   746,   666,   229,   200,   201,   202,   203,
       8,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,   435,   436,  2021,   438,   439,   440,   441,   442,
     213,   214,   223,   446,   447,   448,   449,   450,   451,   230,
     453,   123,   124,   125,   126,   119,   229,    84,   213,   214,
      87,   444,   225,    90,   223,   137,   225,   470,   140,   452,
     224,   135,   226,   232,   229,   229,   119,   213,   214,   143,
     144,   145,   223,   205,   225,   149,   150,   151,   152,   224,
     223,   232,   135,   229,   229,   217,   218,   215,   216,   217,
     143,   144,   145,   225,   222,   508,   149,   150,   151,   152,
     223,   233,   223,   200,   201,   202,   203,   230,    90,   223,
      92,   225,   379,   227,   200,   201,   202,   203,   232,   251,
     223,   213,   214,   220,   221,   200,   201,   202,   203,   224,
     262,   226,   213,   214,   224,   230,  2133,   229,   223,   229,
     225,   224,   227,   556,   557,   230,   229,   232,   229,    90,
     282,   213,   214,   546,   547,   548,   549,   231,   425,   223,
     427,   428,   429,   430,   431,   432,   433,   229,   435,   436,
       6,   438,   439,   440,   223,   442,   213,   214,   231,   446,
     447,   448,   449,   450,   571,   572,   223,   213,   214,   602,
     603,   604,   223,   230,   686,   223,   223,   225,   225,   861,
     223,   614,   615,   229,   232,   618,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     633,   213,   214,   223,   222,    84,   224,   640,    87,   972,
     223,    90,   119,   976,   223,   213,   214,   229,    87,   213,
     214,    90,   223,    92,   213,   214,   659,   379,   135,    90,
     742,   229,   213,   214,   746,   229,   143,   144,   145,     8,
     229,   223,   149,   150,   151,   152,   679,   230,   229,    87,
     569,   570,    90,  1841,    92,  1843,   223,  1845,   577,   213,
     214,   215,   216,   217,   220,   221,   213,   214,   222,   213,
     214,   223,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   229,   435,   436,   229,   438,   439,   440,   441,
     442,   213,   214,   223,   446,   447,   448,   449,   450,   451,
      90,   453,   213,   214,   213,   214,    92,   229,   741,   213,
     214,   119,   745,    84,   213,   214,    87,   223,   229,    90,
     229,    92,   213,   214,   231,   229,  1924,   135,    87,  1927,
     229,   618,  1930,   230,   747,   143,   144,   145,   229,   220,
     221,   149,   150,   151,   152,   226,  1057,   230,   213,   214,
     224,   784,   226,   213,   214,   788,   119,   229,   791,   231,
     224,   794,   226,   796,   229,    90,   230,   800,   801,   229,
     123,   124,   135,  1136,   119,  1138,   129,  1140,    90,  1142,
     143,   144,   145,     6,     7,   798,   149,   150,   151,   152,
     135,     4,   213,   214,    87,   229,   908,   231,   143,   144,
     145,   834,     6,     7,   149,   150,   151,   152,   229,  1997,
     259,   260,   261,    87,   213,   214,   123,   124,   267,   268,
     269,   223,   129,   231,   229,   858,   231,     4,  1280,  1281,
     229,   213,   214,  1285,  1286,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   224,
    2048,   226,     4,   222,   229,   223,     4,     6,   307,   308,
     972,   223,   231,   615,   976,   229,   618,   231,   231,     6,
     982,   983,   321,   322,   223,   229,    84,   231,   911,    87,
     913,   223,    90,   916,    92,     6,   231,  2075,   224,  2077,
     226,  2079,   229,   229,   231,   225,   929,  2085,   931,   223,
     933,   224,   935,   226,   791,   225,   229,   940,   223,   796,
    2108,     7,   945,  2111,   225,   224,  2114,   226,   223,  2117,
     229,   224,   224,   226,   226,  1288,   229,   229,   229,   229,
     231,   231,   223,   229,   967,   231,   223,   229,   971,   231,
     223,  1304,   975,   223,   223,   864,   119,   223,   230,     6,
     983,  2139,   871,  2141,   229,  2143,   231,   223,   229,   878,
     231,  2159,   135,  2161,   223,  2163,  1078,  1079,   230,   230,
     143,   144,   145,     6,     6,  1008,   149,   150,   151,   152,
    1013,   223,   223,   119,  1295,  1018,  1019,  1020,  1021,   223,
    1581,  1582,   229,   229,   231,   231,   223,   230,  1031,   135,
    1033,   229,    90,   231,    92,  1457,  1458,   143,   144,   145,
    1462,  1463,   230,   149,   150,   151,   152,    90,   229,    92,
     231,   223,   223,   229,  1057,   231,     4,  1060,  1061,  1062,
    1063,   229,   229,   231,   231,   229,   229,   231,   231,   791,
     230,   229,   794,   231,   796,   229,   229,   231,   231,   229,
     225,   231,  1085,   223,   223,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   223,
     223,  1104,  1105,   222,  1107,   230,  1109,  1110,   223,   230,
    1113,  1114,  1115,  1116,  1117,  1118,  1119,  1120,  1200,  1201,
       8,  1124,   119,  1126,  1127,   231,   983,   229,   229,   231,
     231,   229,   232,   231,  1467,   229,   223,   231,   135,   229,
     223,   231,  1224,  1225,   230,   230,   143,   144,   145,   229,
     223,   231,   149,   150,   151,   152,  1013,   229,     4,   231,
       6,   223,  1019,  1020,  1021,   229,   229,   231,   231,   229,
     229,   231,   231,   229,  1031,   231,  1033,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   229,   229,   231,   231,   222,   229,   229,   231,   231,
    1452,   223,  1454,     4,     5,   229,  1288,   231,   229,   223,
     231,  1100,   229,   229,   231,   231,   229,   229,   231,   231,
     229,   229,   231,   231,  1227,  1228,  1229,  1508,  1085,   229,
     229,   231,   231,   229,   231,   231,   229,   229,   231,   231,
    1243,   223,     6,    44,    45,    46,    47,    48,    49,    50,
      51,    52,   229,   229,   231,   231,    57,    58,    59,    60,
     229,   983,   231,   119,    65,    66,    67,     6,   229,    70,
     231,   230,  1161,  1162,  1163,  1836,   230,  1280,  1281,   135,
      81,   230,  1285,  1286,   229,   225,   231,   143,   144,   145,
     225,  1013,  1295,   149,   150,   151,   152,  1019,  1020,  1021,
     229,   229,   231,   231,   225,   230,  1309,     6,     6,  1031,
     230,  1033,     6,   168,   232,     6,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
    1333,   230,   230,     6,   222,  1057,  1339,     6,   230,     6,
    1323,   225,     4,   222,   227,   230,     7,   224,  1351,   231,
       7,   229,  1355,  1356,   229,     6,     6,  1360,  1361,     6,
    1363,   224,  1365,  1085,  1367,     7,  1369,  1370,  1371,     7,
       6,  1793,     6,     6,   224,   231,     6,   230,     7,     6,
      62,     7,     6,   184,   185,   186,  1389,  1469,     6,     6,
       4,    62,    62,   165,    62,   196,   230,   198,   199,   226,
     224,  1404,     6,   224,     6,   224,   229,   119,   226,  1412,
       6,  1414,   229,   229,   229,   229,   229,   229,   224,   220,
     221,   224,   224,   135,    44,    44,   227,     4,    44,   230,
       4,   143,   144,   145,    44,     7,     6,   149,   150,   151,
     152,     4,     5,   168,     6,   119,     6,     6,   168,     7,
       7,     7,     7,     7,  1457,  1458,     7,   168,     7,  1462,
    1463,   135,     7,     7,     7,     7,     7,     7,  1451,   143,
     144,   145,   230,  1476,     6,   149,   150,   151,   152,  1482,
       7,    44,    45,    46,    47,    48,    49,    50,    51,    52,
       7,     4,     6,   224,    57,    58,    59,    60,   224,   229,
     229,   224,    65,    66,    67,  1508,   224,    70,   229,   231,
     229,  1514,   227,  1402,   231,     6,   119,  1500,    81,   231,
     119,  1524,  1803,   224,  1527,   230,   226,   230,   230,     7,
       7,     7,   135,   230,  1616,   227,     7,     6,   231,    44,
     143,   144,   145,   230,  1527,    44,   149,   150,   151,   152,
      44,    44,     6,     6,     6,     6,     6,   231,  1280,  1281,
       7,   225,     6,  1285,  1286,   223,     6,   223,     7,   210,
    1573,  1574,     7,  1295,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,  1589,   230,    92,     7,
     222,     7,     7,     7,  1577,     6,     4,     7,     7,  1851,
       7,  1604,     7,     7,  1581,  1582,     7,  1610,    87,     4,
       6,   223,   223,     7,     6,   230,     7,     7,     7,  1476,
       7,   184,   185,   186,     7,  1482,     7,  1630,   231,     7,
     230,     6,     6,   196,     6,   198,   199,  1640,   209,   210,
     211,   212,   213,   214,   215,   216,   217,  1650,  1537,     6,
       6,   222,  1655,  1636,    90,     7,     6,     4,     4,     4,
     229,   224,   230,   226,   230,     6,   231,  1524,     6,     6,
       6,     6,  1655,  1656,  1657,     4,     6,   229,  1681,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   224,  1583,   229,  1585,   222,  1587,   227,
     224,  1704,  1954,     7,   229,   227,   231,   230,     6,     6,
     226,     6,   224,     6,   112,   230,  1605,  1606,  1607,  1608,
    1609,  1610,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   230,     6,  1457,  1458,   222,  1741,     6,
    1462,  1463,   230,   230,     6,     6,  1998,   230,    21,    22,
    1753,     6,     6,     6,  1476,     6,     6,     6,     6,     6,
    1482,     5,   230,     6,     6,     4,     6,   230,   230,     7,
    1773,   230,   230,     6,     6,     6,   225,     6,     6,     4,
       6,   224,   230,     6,   230,   230,  1508,  1790,   230,   230,
    1793,   164,   230,  1776,   226,     6,   230,     6,   229,     4,
    1803,     7,  1524,     6,     6,     6,     6,     4,     6,  1812,
       6,     6,     6,     6,     4,     7,  1819,  1820,     6,     6,
       6,     6,     5,   229,     6,     6,   168,  1830,   230,     6,
    1833,     6,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,     6,  1850,     6,     6,
     222,  1854,     6,     6,     6,   128,     6,     6,     6,  1836,
       6,     6,     6,   229,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,     6,
       6,   224,   165,   166,   167,   168,     6,   170,   171,   172,
     173,   174,   175,     6,     6,   178,     6,     6,     6,     6,
    1913,   184,   185,     7,   227,     6,   230,   190,   191,     6,
     230,   230,     5,    88,     6,   230,     6,   230,   230,  1932,
     231,     6,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   231,   230,   230,     6,
     222,  1840,   231,  1842,     7,  1844,  1959,     6,     6,   230,
       6,   231,   231,   231,   163,     6,  1855,  1856,  1857,  1858,
    1859,     6,     6,     6,     6,  1958,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     166,     6,     6,     6,   222,     6,     6,  2000,  2001,  2002,
    2003,  2004,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,     6,   230,  2021,     6,
     222,     6,   230,  1912,     6,     6,     6,  1916,     7,   104,
       6,     6,     6,   224,   119,     6,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
       6,   230,   230,   326,   222,     6,   329,   330,   331,   332,
     230,   229,   231,   231,   230,     6,   230,     6,     6,     6,
       6,  1793,     6,     6,     6,   231,   349,     6,     6,   230,
    2063,  1803,   223,   230,     6,  1974,   224,  2090,   230,  1978,
       6,   231,     6,   230,     6,     6,     6,     6,  2101,     6,
       6,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,  2004,     6,   230,     6,   222,
       6,   230,   230,   230,   199,   200,   201,   202,   203,   230,
    2133,     6,     6,     6,     6,     6,     6,     6,     6,     6,
       6,   216,     6,     6,  1962,   220,   504,  1332,  2151,  1318,
    2153,  1818,     3,     3,     3,     3,   544,  1504,  1832,   234,
     235,   236,   237,    -1,   239,   240,   241,   242,    -1,   244,
     245,   246,   247,   248,   249,   250,    -1,   252,   253,    -1,
    2183,    -1,    -1,   258,  2073,  2074,    -1,    -1,   263,   264,
      -1,   464,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   279,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   288,   289,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   297,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,  1959,    -1,    -1,
      -1,   222,    -1,    -1,  2101,    -1,    -1,    -1,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,    -1,   338,   339,   340,   222,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   352,   353,   354,
      -1,   356,    -1,    -1,    -1,   360,   361,   362,    -1,    -1,
     365,    -1,    -1,    -1,  2151,    -1,  2153,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   380,    -1,    -1,    -1,    -1,
     385,   386,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   399,   400,  2183,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   437,    -1,    -1,    -1,    -1,    -1,   443,    -1,
     445,     6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2101,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   469,   470,    -1,   472,   473,   474,
     475,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,   486,    -1,    -1,   489,   490,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2151,
      -1,  2153,    -1,   508,    -1,    -1,    -1,    -1,    -1,   514,
      -1,    -1,    -1,    -1,   519,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     6,   531,   532,    -1,    -1,
      -1,  2183,    -1,    -1,    -1,   540,   541,    -1,    -1,    -1,
     545,   546,   547,   548,   549,   550,    -1,   552,    -1,   554,
      -1,   556,   557,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   574,
     575,   576,   577,   578,   579,    -1,    -1,    -1,   583,   584,
     585,   586,   587,   588,   589,   590,   591,    -1,    -1,    -1,
     595,    -1,   597,   598,    -1,    -1,    -1,   602,   603,   604,
      -1,     6,   607,   608,   609,   610,   611,    -1,    -1,   614,
     615,   616,   617,    -1,   619,    -1,    -1,   622,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   633,    -1,
      -1,    -1,    -1,    -1,   639,   640,    -1,   642,   643,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,    -1,   659,    -1,    -1,   222,    -1,   664,
     665,    -1,   667,   668,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   678,   679,    -1,    -1,    -1,   683,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,    -1,
      -1,    -1,    -1,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    -1,    -1,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,    53,    54,    55,
      56,   222,    -1,   748,    -1,    61,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    72,    73,    74,    -1,
      -1,    -1,    -1,    -1,    80,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   780,   781,    -1,    -1,   784,
     785,   786,    -1,   788,   789,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   797,    -1,    -1,   800,   801,    -1,    -1,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,    -1,    -1,    -1,   821,   222,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   833,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1040,  1041,    -1,
      -1,    -1,    -1,  1046,  1047,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   858,    -1,    -1,    -1,    -1,    -1,    -1,
     865,   866,    -1,    -1,    -1,    -1,   871,   183,    -1,    -1,
      -1,   187,    -1,     6,    -1,   191,   192,   193,   194,   195,
      -1,    -1,    -1,   199,   889,    -1,    -1,   892,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   213,   214,    -1,
       6,    -1,   218,    -1,    -1,    -1,   911,   223,   913,    -1,
      -1,   916,   228,    -1,   230,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   929,    -1,   931,    -1,   933,    -1,
     935,    -1,    -1,    -1,    -1,   940,    -1,    -1,    -1,    -1,
     945,    -1,    -1,    -1,    -1,    -1,   951,    -1,   953,   954,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,   964,
      -1,    -1,    -1,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,   996,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1004,
    1005,  1006,    -1,  1008,    -1,    -1,    -1,    53,    54,    55,
      56,  1016,    -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,
       6,    -1,    -1,    -1,    -1,  1030,    72,    73,    74,    -1,
    1035,    -1,    -1,    -1,    80,    -1,    -1,    -1,    -1,  1044,
      -1,    -1,    -1,  1246,  1247,  1050,    -1,    -1,  1251,  1252,
      -1,    -1,    -1,    -1,    -1,  1060,  1061,  1062,  1063,    -1,
      -1,  1066,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     254,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,    -1,    -1,    -1,    -1,   222,
      -1,   275,   276,   277,    -1,    -1,    -1,   281,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,    -1,    -1,    -1,    -1,   222,    -1,    -1,  1124,
      -1,    -1,    -1,    -1,    -1,   309,    -1,    -1,    -1,    -1,
      -1,    -1,  1137,    -1,  1139,    -1,  1141,   183,  1143,    -1,
      -1,   187,    -1,    -1,    -1,   191,   192,   193,   194,   195,
      -1,    -1,    -1,   199,    -1,    -1,    -1,    -1,    -1,     6,
      -1,  1166,    -1,    -1,    -1,    -1,    -1,   213,   214,    -1,
      -1,    -1,   218,    -1,    -1,    -1,    -1,   223,    -1,    12,
      13,    -1,   228,    -1,   230,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1199,    -1,    -1,    -1,    -1,   383,
     384,    -1,    -1,  1208,  1209,    -1,  1211,  1212,    -1,  1214,
    1215,  1216,   396,    -1,    -1,    -1,    -1,  1222,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,    -1,    -1,    -1,    -1,   222,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1249,    -1,    -1,    -1,    -1,  1254,
     434,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    -1,    -1,    -1,   100,   101,   102,
      -1,   104,    -1,    -1,    -1,    -1,   109,   110,   111,   112,
     113,    -1,   115,   116,   117,    -1,    -1,    -1,   121,    -1,
      -1,  1296,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1307,  1308,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1322,  1323,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   160,   161,   162,
      -1,    -1,   235,    -1,    -1,    -1,    -1,   240,    -1,    -1,
      -1,   244,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   258,    -1,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,    -1,  1377,  1378,  1379,   222,    12,    13,    -1,    -1,
      -1,    -1,    -1,    -1,  1389,    -1,  1391,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1402,   231,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1414,
      -1,    -1,    -1,    -1,  1419,    -1,    -1,    -1,    -1,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,    -1,    -1,    -1,     6,   222,    -1,    -1,
    1445,  1446,  1447,    -1,   229,    -1,   231,    -1,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,     6,    -1,    -1,   100,   101,   102,    -1,   104,    -1,
      -1,    -1,  1477,   109,   110,   111,   112,   113,    -1,   115,
     116,   117,    -1,    -1,    -1,   121,    -1,    -1,     7,     8,
      -1,    -1,    -1,    -1,    -1,    -1,  1501,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1515,    -1,    -1,    -1,    -1,  1520,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   160,   161,   162,    -1,    -1,    -1,
    1535,  1536,    -1,    -1,    -1,    -1,    -1,  1542,  1543,    -1,
      -1,    -1,  1547,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   741,  1563,    -1,
      -1,   745,    -1,    -1,    -1,    -1,    -1,   470,  1573,  1574,
    1575,    -1,  1577,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1590,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   231,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1610,    -1,    -1,  1613,    -1,
      -1,    -1,     7,    -1,    -1,  1620,  1621,  1622,  1623,  1624,
    1625,  1626,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1636,    -1,    -1,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,    -1,    -1,
     834,  1656,   222,   556,   557,    -1,    -1,    -1,    -1,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,    -1,  1679,  1680,    -1,   222,    -1,    -1,
      -1,    -1,  1687,    -1,    -1,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   602,
     603,   604,   235,   222,    -1,    -1,    -1,   240,    -1,    -1,
      -1,   244,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1725,    -1,    -1,    -1,    -1,   258,    -1,    -1,    -1,    -1,
     633,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1744,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1753,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   659,    -1,    -1,    -1,
      -1,    -1,    -1,  1768,    -1,  1770,    -1,    -1,  1773,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   679,    -1,    -1,    -1,
      -1,    -1,    -1,   967,    -1,  1790,    -1,   971,    -1,    -1,
      -1,   975,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1808,    -1,   338,    -1,   340,  1813,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,    -1,    -1,    -1,    -1,   222,  1833,    -1,
      -1,    -1,    -1,    -1,  1018,  1840,    -1,  1842,    -1,  1844,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1854,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1864,
    1865,  1866,  1867,  1868,  1869,    -1,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
      -1,   784,    -1,    -1,   222,   788,    -1,  1892,  1893,    -1,
      -1,    -1,  1897,   231,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1909,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     8,    -1,  1920,    -1,    -1,    -1,    -1,
    1104,  1105,    -1,  1107,    -1,  1109,  1110,    -1,    -1,  1113,
    1114,  1115,  1116,  1117,  1118,  1119,  1120,   470,    -1,    -1,
      -1,    -1,  1126,  1127,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1956,    -1,    -1,    -1,   858,    -1,  1962,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1971,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   508,    -1,    -1,    -1,    -1,
    1985,    -1,    -1,  1988,    -1,    -1,  1991,    -1,    -1,    -1,
    1995,    -1,    -1,    -1,    -1,  2000,  2001,  2002,  2003,  2004,
    2005,  2006,  2007,  2008,  2009,    -1,    -1,    -1,   911,    -1,
     913,    -1,    -1,   916,  2019,    -1,    -1,  2022,    -1,    -1,
      -1,    -1,    -1,   556,   557,    -1,   929,    -1,   931,    -1,
     933,    -1,   935,    -1,    -1,    -1,    -1,   940,    -1,    -1,
      -1,    -1,   945,  1227,  1228,  1229,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1243,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2072,    -1,   602,
     603,   604,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   614,   615,    -1,    -1,  2090,    -1,  2092,  2093,  2094,
    2095,  2096,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     633,    -1,    -1,     8,    -1,  1008,    -1,   640,    -1,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,    -1,    -1,  1309,   659,   222,    -1,    -1,
      -1,  2136,  2137,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2147,  2148,  2149,  2150,   679,    -1,     8,  1333,
      -1,   644,    -1,    -1,    -1,  1339,    -1,  1060,  1061,  1062,
    1063,    -1,    -1,    -1,    -1,    -1,    -1,  1351,     8,    -1,
      -1,  1355,  1356,    -1,    -1,    -1,  1360,  1361,    -1,  1363,
      -1,  1365,    -1,  1367,    -1,  1369,  1370,  1371,    -1,    -1,
      -1,    -1,    -1,    -1,   687,   688,   689,   690,   691,   692,
     693,   694,   695,   696,   697,  1389,   699,   700,   701,   702,
     703,   704,   705,    -1,    -1,    -1,   709,   710,   711,    -1,
    1404,  1124,   715,   716,    -1,   718,    -1,    -1,  1412,    -1,
     723,   724,   725,    -1,   727,    -1,    -1,    -1,    -1,    -1,
      -1,   734,   735,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   784,    -1,    -1,    -1,   788,    -1,    -1,    -1,   752,
      -1,    -1,    -1,     3,     4,    -1,    -1,   800,   801,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    -1,    -1,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,    53,    54,    55,    56,   222,    -1,    -1,
      -1,    61,    -1,    -1,    -1,   858,    -1,    -1,    -1,    -1,
    1514,    -1,    72,    73,    74,    -1,    -1,    -1,    -1,    -1,
      80,    -1,    -1,  1527,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,    -1,    -1,
      -1,    -1,   222,    -1,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   911,     8,
     913,    -1,   222,   916,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   929,    -1,   931,    -1,
     933,    -1,   935,    -1,    -1,  1589,    -1,   940,    -1,    -1,
      -1,    -1,   945,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1604,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   921,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   183,    -1,    -1,  1630,   187,    -1,    -1,
      -1,   191,   192,   193,   194,   195,  1640,    -1,    -1,   199,
      -1,    12,    13,    -1,    -1,    -1,  1650,    -1,    -1,    -1,
      -1,  1655,    -1,   213,   214,  1008,    -1,    -1,   218,    -1,
      -1,    -1,    -1,   223,   224,    -1,    -1,    -1,   228,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1681,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1414,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1704,    -1,    -1,    -1,    -1,    -1,    -1,  1060,  1061,  1062,
    1063,    -1,    -1,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    -1,    -1,    -1,   100,
     101,   102,    -1,   104,    -1,    -1,    -1,  1741,   109,   110,
     111,   112,   113,    -1,   115,   116,   117,    -1,    -1,    -1,
     121,    -1,  1065,    -1,    -1,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,    -1,
      -1,  1124,    -1,   222,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1098,  1099,    -1,    -1,   160,
     161,   162,    12,    13,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,  1812,    -1,
      -1,    -1,   222,    -1,    -1,  1819,  1820,    -1,    -1,    -1,
      -1,   231,    -1,    -1,    -1,    -1,  1830,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,    -1,    -1,    -1,    -1,   222,  1850,    -1,    -1,    -1,
    1573,  1574,    -1,    -1,   231,    -1,    -1,    -1,    -1,    -1,
     231,    -1,    -1,    -1,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    -1,    -1,    -1,
     100,   101,   102,    -1,   104,    -1,    -1,    -1,    -1,   109,
     110,   111,   112,   113,    -1,   115,   116,   117,    -1,    -1,
      -1,   121,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1913,
      -1,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,    -1,    -1,    -1,  1932,   222,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   231,    -1,
     160,   161,   162,    -1,  1257,    -1,    -1,    -1,    -1,    -1,
    1263,  1264,  1265,  1266,  1267,    -1,  1269,    -1,  1271,  1272,
      -1,  1274,  1275,    -1,    -1,  1278,  1279,  1280,    -1,    -1,
      -1,    -1,  1285,    -1,    -1,    -1,    -1,     3,     4,     5,
      -1,    -1,    -1,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,   231,    -1,    -1,    -1,    -1,    -1,  2021,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    -1,    -1,    -1,    65,
      66,    67,    -1,    -1,    70,    -1,    72,    73,    74,    -1,
    1773,     3,     4,    -1,    80,    81,    -1,     9,    10,    11,
      -1,  1414,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    -1,    -1,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,    53,    54,    55,    56,   222,    -1,    -1,    -1,    61,
    1833,  1424,    -1,    -1,   231,    -1,    -1,    -1,    -1,    -1,
      72,    73,    74,    -1,    -1,    -1,    -1,  1440,    80,  2133,
      -1,  1854,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1457,    -1,    -1,    -1,    -1,  1462,
     176,    -1,    -1,    -1,    -1,    -1,    -1,   183,   184,   185,
     186,   187,    -1,    -1,    -1,   191,   192,   193,   194,   195,
     196,    -1,   198,   199,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1494,  1495,    -1,    -1,  1498,  1499,   213,   214,    -1,
      -1,    -1,   218,    -1,    -1,    -1,    -1,   223,    -1,   225,
      -1,   227,   228,    -1,   230,    -1,   232,    -1,    -1,    -1,
      12,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1573,  1574,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   183,    -1,    -1,    -1,   187,    -1,    -1,    -1,   191,
     192,   193,   194,   195,    -1,    -1,    -1,   199,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1610,    -1,    -1,
      -1,   213,   214,    -1,    -1,    -1,   218,    -1,    -1,    -1,
      -1,   223,    -1,    -1,   226,    -1,   228,  2000,  2001,  2002,
    2003,  2004,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    -1,    -1,    -1,   100,   101,
     102,    -1,   104,    -1,    -1,    -1,    -1,   109,   110,   111,
     112,   113,    -1,   115,   116,   117,    -1,    -1,    -1,   121,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1643,  1644,    -1,    -1,  1647,  1648,    -1,    -1,    -1,    -1,
    1653,  1654,    -1,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,    -1,   160,   161,
     162,   222,    -1,    -1,    -1,    -1,    -1,  2090,    -1,    -1,
     231,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    12,    13,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
    1753,    -1,    -1,    -1,   222,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   231,    -1,    -1,    -1,    -1,    -1,    -1,
    1773,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   231,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1790,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1760,  1761,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    -1,
      -1,    -1,   100,   101,   102,    -1,   104,    -1,    -1,    -1,
    1833,   109,   110,   111,   112,   113,    -1,   115,   116,   117,
      -1,     3,     4,   121,    -1,    -1,    -1,     9,    10,    11,
      -1,  1854,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      -1,    -1,   160,   161,   162,    -1,    -1,    -1,    -1,    -1,
      -1,    53,    54,    55,    56,    -1,    -1,    -1,    -1,    61,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      72,    73,    74,    -1,    -1,    -1,    -1,    -1,    80,    -1,
      -1,    -1,    84,    -1,    -1,    87,    -1,    -1,    90,    -1,
      92,    -1,    -1,    -1,    -1,    -1,    -1,    99,    -1,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   231,   116,    -1,    -1,   222,    -1,    -1,
      -1,   123,   124,   125,   126,   127,   231,    -1,   130,   131,
     132,   133,   134,    -1,    -1,   137,    -1,    -1,   140,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2000,  2001,  2002,
    2003,  2004,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,    -1,    -1,    -1,    -1,
     222,   183,    -1,    -1,    -1,   187,    -1,    -1,   230,   191,
     192,   193,   194,   195,    -1,    -1,    -1,   199,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   213,   214,    -1,    -1,    -1,   218,    -1,    -1,    -1,
      -1,   223,    -1,    -1,    -1,    -1,   228,    -1,   230,   231,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
      -1,    -1,    -1,    -1,     9,    10,    11,  2090,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,    54,
      55,    56,    -1,    -1,    -1,    -1,    61,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,    73,    74,
      -1,    12,    13,    -1,    -1,    80,    -1,    -1,    -1,    84,
      -1,  2124,    87,    -1,    -1,    90,    -1,    92,    -1,    -1,
      -1,    -1,    -1,    -1,    99,    -1,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
      -1,   116,    -1,    -1,   222,    -1,    -1,    -1,   123,   124,
     125,   126,   127,   231,    -1,   130,   131,   132,   133,   134,
      -1,    -1,   137,    -1,    -1,   140,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    -1,    -1,    -1,   100,
     101,   102,    -1,   104,    -1,    -1,    -1,    -1,   109,   110,
     111,   112,   113,    -1,   115,   116,   117,    -1,   183,    -1,
     121,    -1,   187,    -1,    -1,    -1,   191,   192,   193,   194,
     195,    -1,    -1,    -1,   199,    -1,    -1,   138,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   213,   214,
      -1,    -1,    -1,   218,    -1,    -1,    -1,    -1,   223,   160,
     161,   162,    -1,   228,    -1,    -1,   231,     3,     4,     5,
      -1,    -1,    -1,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    -1,    -1,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    -1,    -1,    -1,    65,
      66,    67,    -1,    -1,    70,    -1,    72,    73,    74,    -1,
      -1,    -1,    -1,    -1,    80,    81,    -1,    -1,    84,    -1,
      -1,    87,    -1,    -1,    90,    -1,    92,    -1,    -1,    -1,
      -1,    -1,    -1,    99,    -1,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,    -1,
     116,    -1,    -1,   222,    -1,    -1,    -1,   123,   124,   125,
     126,   127,   231,    -1,   130,   131,   132,   133,   134,    -1,
      -1,   137,    -1,    -1,   140,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,    -1,
      -1,    -1,    -1,   222,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   231,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   183,   184,   185,
     186,   187,    -1,    -1,    -1,   191,   192,   193,   194,   195,
     196,    -1,   198,   199,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   213,   214,    -1,
      -1,    -1,   218,    -1,    -1,    -1,    -1,   223,    -1,     3,
       4,     5,   228,    -1,   230,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    -1,    -1,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    -1,    -1,
      -1,    65,    66,    67,    -1,    -1,    70,    -1,    72,    73,
      74,    -1,    -1,    -1,    -1,    -1,    80,    81,    -1,    -1,
      84,    -1,    -1,    87,    -1,    -1,    90,    -1,    92,    -1,
      -1,    -1,    -1,    -1,    -1,    99,    -1,    -1,    -1,    -1,
      -1,     4,     5,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   116,    -1,    -1,    -1,    -1,    -1,    -1,   123,
     124,   125,   126,   127,    -1,    -1,   130,   131,   132,   133,
     134,    -1,    -1,   137,    -1,    -1,   140,    -1,    -1,    -1,
      -1,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      -1,    -1,    -1,    -1,    57,    58,    59,    60,    -1,    -1,
      -1,    -1,    65,    66,    67,    -1,    -1,    70,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,   183,
     184,   185,   186,   187,    -1,    -1,    -1,   191,   192,   193,
     194,   195,   196,    -1,   198,   199,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   213,
     214,    -1,    -1,    -1,   218,    -1,    -1,    -1,    -1,   223,
      -1,     3,     4,     5,   228,    -1,   230,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    53,    54,    55,    56,    -1,    -1,    -1,    -1,    61,
      -1,   184,   185,   186,    -1,    -1,    -1,    -1,    -1,    -1,
      72,    73,    74,   196,    -1,   198,   199,    -1,    80,    -1,
      -1,    -1,    84,    -1,    -1,    87,    -1,    -1,    90,    -1,
      92,    -1,    -1,    -1,    -1,    -1,    -1,    99,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,    -1,    -1,   116,    -1,   222,     4,     5,    -1,
     226,   123,   124,   125,   126,   127,    -1,    -1,   130,   131,
     132,   133,   134,    -1,    -1,   137,    -1,    -1,   140,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    -1,    -1,    -1,    -1,
      57,    58,    59,    60,    -1,    -1,    -1,    -1,    65,    66,
      67,   183,    -1,    70,    -1,   187,    -1,    -1,    -1,   191,
     192,   193,   194,   195,    81,    -1,    -1,   199,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   213,   214,    -1,    -1,    -1,   218,    -1,    -1,    -1,
      -1,   223,    -1,     3,     4,     5,   228,    -1,   230,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    12,    13,    -1,    65,    66,    67,    -1,    -1,
      70,    -1,    72,    73,    74,    -1,    -1,   184,   185,   186,
      80,    81,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   196,
      -1,   198,   199,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,    -1,    -1,    -1,
      -1,   222,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     231,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    -1,    -1,    -1,
     100,   101,   102,    -1,   104,    -1,    -1,    -1,    -1,   109,
     110,   111,   112,   113,    -1,   115,   116,   117,    -1,    -1,
      -1,   121,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   183,   184,   185,   186,   187,    -1,    -1,
      -1,   191,   192,   193,   194,   195,   196,    -1,   198,   199,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     160,   161,   162,   213,   214,    -1,    -1,    -1,   218,    -1,
      -1,    -1,    -1,   223,    -1,     3,     4,     5,   228,    -1,
     230,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    53,    54,    55,    56,    -1,
      -1,   231,    -1,    61,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    72,    73,    74,    -1,    -1,    -1,
      -1,    -1,    80,    -1,    -1,    -1,    84,    -1,    -1,    87,
      -1,    -1,    90,    -1,    92,    -1,    -1,    -1,    -1,    -1,
      -1,    99,    -1,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,    -1,   116,    -1,
      -1,   222,    -1,    -1,    -1,   123,   124,   125,   126,   127,
     231,    -1,   130,   131,   132,   133,   134,    -1,    -1,   137,
      -1,    -1,   140,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,    -1,    -1,    -1,
      -1,   222,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     231,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   183,    -1,    -1,    -1,   187,
      -1,    -1,    -1,   191,   192,   193,   194,   195,    -1,    -1,
      -1,   199,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   213,   214,    -1,    -1,    -1,
     218,    -1,    -1,    -1,    -1,   223,    -1,     3,     4,     5,
     228,    -1,   230,     9,    10,    11,    -1,    -1,    14,    15,
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
      73,    74,    -1,    -1,    -1,    -1,    -1,    80,    81,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,    -1,    -1,    -1,    -1,   222,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   231,   183,   184,   185,
     186,   187,    -1,    -1,    -1,   191,   192,   193,   194,   195,
     196,    -1,   198,   199,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   213,   214,    -1,
      -1,    -1,   218,    -1,    -1,    -1,    -1,   223,    -1,    -1,
      -1,    -1,   228,    -1,   230,    -1,    -1,    -1,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,    -1,    -1,    -1,    -1,   222,    -1,    -1,    -1,
     183,   184,   185,   186,   187,   231,    -1,    -1,   191,   192,
     193,   194,   195,   196,    -1,   198,   199,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     213,   214,    -1,    -1,    -1,   218,    -1,    -1,    -1,    -1,
     223,    -1,     3,     4,    -1,   228,    -1,   230,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    53,    54,    55,    56,    -1,    -1,    -1,    -1,
      61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    72,    73,    74,    -1,    -1,    -1,    -1,    -1,    80,
      -1,    -1,    -1,    84,    -1,    -1,    87,    -1,    -1,    90,
      -1,    92,    -1,    -1,    -1,    -1,    -1,    -1,    99,    -1,
      -1,    -1,    -1,    -1,     4,     5,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   116,    -1,    -1,    -1,    -1,
      -1,    -1,   123,   124,   125,   126,   127,    -1,    -1,   130,
     131,   132,   133,   134,    -1,    -1,   137,    -1,    -1,   140,
      -1,    -1,    -1,    -1,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    -1,    -1,    -1,    -1,    57,    58,    59,
      60,    -1,    -1,    -1,    -1,    65,    66,    67,    -1,    -1,
      70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    81,   183,    -1,    -1,    -1,   187,    -1,    -1,    -1,
     191,   192,   193,   194,   195,    -1,    -1,    -1,   199,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   213,   214,    -1,    -1,    -1,   218,    -1,    -1,
      -1,    -1,   223,    -1,     3,     4,    -1,   228,    -1,   230,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    53,    54,    55,    56,    -1,    -1,
      -1,    -1,    61,    -1,   184,   185,   186,    -1,    -1,    -1,
      -1,    -1,    -1,    72,    73,    74,   196,    -1,   198,    -1,
      -1,    80,    -1,    -1,    -1,    84,    -1,    -1,    87,    -1,
      -1,    90,    -1,    92,    -1,    -1,    -1,    -1,    -1,    -1,
      99,    -1,    -1,    -1,    -1,    -1,    -1,     5,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   116,    -1,    -1,
      -1,    -1,    -1,    -1,   123,   124,   125,   126,   127,    -1,
      -1,   130,   131,   132,   133,   134,    -1,    -1,   137,    -1,
      -1,   140,    -1,    -1,    -1,    -1,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    -1,    -1,    -1,    -1,    57,
      58,    59,    60,    -1,    -1,    -1,    -1,    65,    66,    67,
      -1,    -1,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    81,   183,    -1,    -1,    -1,   187,    -1,
      -1,    -1,   191,   192,   193,   194,   195,    -1,    -1,    -1,
     199,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   213,   214,    -1,    -1,    -1,   218,
      -1,    -1,    -1,    -1,   223,    -1,     3,     4,    -1,   228,
      -1,   230,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    53,    54,    55,    56,
      -1,    -1,    -1,    -1,    61,    -1,   184,   185,   186,    -1,
      -1,    -1,    -1,    -1,    -1,    72,    73,    74,   196,    -1,
     198,    -1,    -1,    80,    -1,    -1,    -1,    84,    -1,    -1,
      87,    -1,    -1,    90,    -1,    92,    -1,    -1,    -1,    -1,
      -1,    -1,    99,    -1,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,    -1,   116,
      -1,    -1,   222,    -1,    -1,    -1,   123,   124,   125,   126,
     127,   231,    -1,   130,   131,   132,   133,   134,    -1,    -1,
     137,    -1,    -1,   140,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,    -1,    -1,
      -1,    -1,   222,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   231,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   183,    -1,    -1,    -1,
     187,    -1,    -1,    -1,   191,   192,   193,   194,   195,    -1,
      -1,    -1,   199,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   213,   214,    -1,    -1,
      -1,   218,    -1,    -1,    -1,    -1,   223,    -1,     3,     4,
      -1,   228,    -1,   230,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,    54,
      55,    56,    -1,    -1,    -1,    -1,    61,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,    73,    74,
      -1,    -1,    -1,    -1,    -1,    80,    -1,    -1,    -1,    84,
      -1,    -1,    87,    -1,    -1,    90,    -1,    92,    -1,    -1,
      -1,    -1,    -1,    -1,    99,    -1,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
      -1,   116,    -1,    -1,   222,    -1,    -1,    -1,   123,   124,
     125,   126,   127,   231,    -1,   130,   131,   132,   133,   134,
      -1,    -1,   137,    -1,    -1,   140,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
      -1,    -1,    -1,    -1,   222,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   231,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   183,    -1,
      -1,    -1,   187,    -1,    -1,    -1,   191,   192,   193,   194,
     195,    -1,    -1,    -1,   199,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   213,   214,
      -1,    -1,    -1,   218,    -1,    -1,    -1,    -1,   223,    -1,
       3,     4,    -1,   228,    -1,   230,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      53,    54,    55,    56,    -1,    -1,    -1,    -1,    61,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,
      73,    74,    -1,    -1,    -1,    -1,    -1,    80,    -1,    -1,
      -1,    84,    -1,    -1,    87,    -1,    -1,    90,    -1,    92,
      -1,    -1,    -1,    -1,    -1,    -1,    99,    -1,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,    -1,   116,    -1,    -1,   222,    -1,    -1,    -1,
     123,   124,   125,   126,   127,   231,    -1,   130,   131,   132,
     133,   134,    -1,    -1,   137,    -1,    -1,   140,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,    -1,    -1,    -1,    -1,   222,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   231,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     183,    -1,    -1,    -1,   187,    -1,    -1,    -1,   191,   192,
     193,   194,   195,    -1,    -1,    -1,   199,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     213,   214,    -1,    -1,    -1,   218,    -1,    -1,    -1,    -1,
     223,    -1,     3,     4,    -1,   228,    -1,   230,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    53,    54,    55,    56,    -1,    -1,    -1,    -1,
      61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    72,    73,    74,    -1,    -1,    -1,    -1,    -1,    80,
      -1,    -1,    -1,    84,    -1,    -1,    87,    -1,    -1,    90,
      -1,    92,    -1,    -1,    -1,    -1,    -1,    -1,    99,    -1,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,    -1,   116,    -1,    -1,   222,    -1,
      -1,    -1,   123,   124,   125,   126,   127,   231,    -1,   130,
     131,   132,   133,   134,    -1,    -1,   137,    -1,    -1,   140,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,    -1,    -1,    -1,    -1,   222,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   231,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   183,    -1,    -1,    -1,   187,    -1,    -1,    -1,
     191,   192,   193,   194,   195,    -1,    -1,    -1,   199,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   213,   214,    -1,    -1,    -1,   218,    -1,    -1,
      -1,    -1,   223,    -1,     3,     4,    -1,   228,    -1,   230,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    53,    54,    55,    56,    -1,    -1,
      -1,    -1,    61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    72,    73,    74,    -1,    -1,    -1,    -1,
      -1,    80,    -1,    -1,    -1,    84,    -1,    -1,    87,    -1,
      -1,    90,    -1,    92,    -1,    -1,    -1,    -1,    -1,    -1,
      99,    -1,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,    -1,   116,    -1,    -1,
     222,    -1,    -1,    -1,   123,   124,   125,   126,   127,   231,
      -1,   130,   131,   132,   133,   134,    -1,    -1,   137,    -1,
      -1,   140,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,    -1,    -1,    -1,    -1,
     222,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   231,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   183,    -1,    -1,    -1,   187,    -1,
      -1,    -1,   191,   192,   193,   194,   195,    -1,    -1,    -1,
     199,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   213,   214,    -1,    -1,    -1,   218,
      -1,    -1,    -1,    -1,   223,    -1,     3,     4,    -1,   228,
      -1,   230,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    53,    54,    55,    56,
      -1,    -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    72,    73,    74,    -1,    -1,
      -1,    -1,    -1,    80,    -1,    -1,    -1,    84,    -1,    -1,
      87,    -1,    -1,    90,    -1,    92,    -1,    -1,    -1,    -1,
      -1,    -1,    99,    -1,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,    -1,   116,
      -1,    -1,   222,    -1,    -1,    -1,   123,   124,   125,   126,
     127,   231,    -1,   130,   131,   132,   133,   134,    -1,    -1,
     137,    -1,    -1,   140,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,    -1,    -1,
      -1,    -1,   222,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   231,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   183,    -1,    -1,    -1,
     187,    -1,    -1,    -1,   191,   192,   193,   194,   195,    -1,
      -1,    -1,   199,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   213,   214,    -1,    -1,
      -1,   218,    -1,    -1,    -1,    -1,   223,    -1,     3,     4,
      -1,   228,    -1,   230,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,    54,
      55,    56,    -1,    -1,    -1,    -1,    61,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,    73,    74,
      -1,    -1,    -1,    -1,    -1,    80,    -1,    -1,    -1,    84,
      -1,    -1,    87,    -1,    -1,    90,    -1,    92,    -1,    -1,
      -1,    -1,    -1,    -1,    99,    -1,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
      -1,   116,    -1,    -1,   222,    -1,    -1,    -1,   123,   124,
     125,   126,   127,   231,    -1,   130,   131,   132,   133,   134,
      -1,    -1,   137,    -1,    -1,   140,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
      -1,    -1,    -1,    -1,   222,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   231,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   183,    -1,
      -1,    -1,   187,    -1,    -1,    -1,   191,   192,   193,   194,
     195,    -1,    -1,    -1,   199,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   213,   214,
      -1,    -1,    -1,   218,    -1,    -1,    -1,    -1,   223,    -1,
       3,     4,    -1,   228,    -1,   230,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      53,    54,    55,    56,    -1,    -1,    -1,    -1,    61,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,
      73,    74,    -1,    -1,    -1,    -1,    -1,    80,    -1,    -1,
      -1,    84,    -1,    -1,    87,    -1,    -1,    90,    -1,    92,
      -1,    -1,    -1,    -1,    -1,    -1,    99,    -1,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,    -1,   116,    -1,    -1,   222,    -1,    -1,    -1,
     123,   124,   125,   126,   127,   231,    -1,   130,   131,   132,
     133,   134,    -1,    -1,   137,    -1,    -1,   140,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,    -1,    -1,    -1,    -1,   222,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   231,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     183,    -1,    -1,    -1,   187,    -1,    -1,    -1,   191,   192,
     193,   194,   195,    -1,    -1,    -1,   199,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     213,   214,    -1,    -1,    -1,   218,    -1,    -1,    -1,    -1,
     223,    -1,     3,     4,     5,   228,    -1,   230,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    -1,    -1,    -1,    65,    66,    67,    -1,    -1,    70,
      -1,    72,    73,    74,    -1,    -1,    -1,    -1,    -1,    80,
      81,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,    -1,    -1,    -1,    -1,   222,
      -1,    -1,     3,     4,    -1,    -1,    -1,   230,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    -1,    -1,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,    53,    54,    55,    56,   222,    -1,    -1,    -1,
      61,    -1,    -1,    -1,    -1,   231,    -1,    -1,    -1,    -1,
      -1,    72,    73,    74,    -1,    -1,    -1,    -1,    -1,    80,
      -1,    -1,   183,   184,   185,   186,   187,    -1,    -1,    -1,
     191,   192,   193,   194,   195,   196,    -1,   198,   199,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   213,   214,    -1,    -1,    -1,   218,     3,     4,
      -1,    -1,   223,    -1,     9,    10,    11,   228,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,    54,
      55,    56,    -1,    -1,    -1,    -1,    61,    -1,    -1,    -1,
      -1,    -1,   183,    -1,    -1,    -1,   187,    72,    73,    74,
     191,   192,   193,   194,   195,    80,    -1,    -1,   199,    84,
      -1,    -1,    87,    -1,    -1,    90,    -1,    92,    -1,    -1,
      -1,    -1,   213,   214,    99,    -1,    -1,   218,    -1,    -1,
      -1,    -1,   223,   224,    -1,    -1,    -1,   228,    -1,    -1,
      -1,   116,    -1,    -1,    -1,    -1,    -1,    -1,   123,   124,
     125,   126,   127,    -1,    -1,   130,   131,   132,   133,   134,
      -1,    -1,   137,    -1,    -1,   140,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
      -1,    -1,    -1,    -1,   222,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   230,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,    -1,   183,    -1,
      -1,   222,   187,   224,    -1,   226,   191,   192,   193,   194,
     195,    -1,    -1,    -1,   199,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   213,   214,
      -1,    -1,    -1,   218,     3,     4,    -1,    -1,   223,    -1,
       9,    10,    11,   228,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    -1,    -1,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,    53,    54,    55,    56,   222,    -1,
     224,    -1,    61,    -1,    -1,   229,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    72,    73,    74,     3,     4,    -1,     6,
      -1,    80,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      -1,    -1,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,    53,    54,    55,    56,
     222,    -1,    -1,    -1,    61,    -1,    -1,   229,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    72,    73,    74,    -1,    -1,
      -1,    -1,    -1,    80,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,    -1,    -1,
      -1,    -1,   222,    -1,   224,    -1,   226,    -1,    -1,   229,
      -1,    -1,    -1,    -1,   183,    -1,    -1,    -1,   187,    -1,
      -1,    -1,   191,   192,   193,   194,   195,    -1,    -1,    -1,
     199,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   213,   214,    -1,    -1,    -1,   218,
      -1,    -1,    -1,    -1,   223,    -1,    -1,   226,    -1,   228,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,    -1,    -1,    -1,    -1,   222,    -1,
      -1,    -1,    -1,    -1,    -1,   229,   183,    -1,    -1,    -1,
     187,    -1,    -1,    -1,   191,   192,   193,   194,   195,    -1,
      -1,    -1,   199,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   213,   214,    -1,    -1,
      -1,   218,     3,     4,    -1,     6,   223,    -1,     9,    10,
      11,   228,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    -1,    -1,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,    53,    54,    55,    56,   222,    -1,    -1,    -1,
      61,    -1,    -1,   229,    -1,    -1,    -1,    -1,    -1,     3,
       4,    72,    73,    74,    -1,     9,    10,    11,    -1,    80,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    -1,    -1,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,    53,
      54,    55,    56,   222,    -1,    -1,    -1,    61,    -1,    -1,
     229,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,    73,
      74,    -1,    -1,    -1,    -1,    -1,    80,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,    -1,    -1,    -1,    -1,   222,    -1,    -1,    -1,    -1,
      -1,    -1,   229,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   183,    -1,    -1,    -1,   187,    -1,    -1,    -1,
     191,   192,   193,   194,   195,    -1,    -1,    -1,   199,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   213,   214,    -1,    -1,    -1,   218,    -1,    -1,
      -1,    -1,   223,    12,    13,    -1,    -1,   228,    -1,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,    -1,    -1,    -1,    -1,   222,    -1,   183,
      -1,    -1,    -1,   187,   229,    -1,    -1,   191,   192,   193,
     194,   195,    -1,    -1,    -1,   199,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    12,    13,   213,
     214,    -1,    -1,    -1,   218,    -1,    -1,    -1,    -1,   223,
      -1,    -1,    -1,    -1,   228,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    -1,    -1,
      -1,   100,   101,   102,    -1,   104,    -1,    -1,    -1,    -1,
     109,   110,   111,   112,   113,    -1,   115,   116,   117,    -1,
      -1,    -1,   121,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      12,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    -1,    -1,    -1,   100,   101,   102,    -1,   104,
      -1,   160,   161,   162,   109,   110,   111,   112,   113,    -1,
     115,   116,   117,    -1,    -1,    -1,   121,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    12,    13,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,   160,   161,   162,   100,   101,
     102,    -1,   104,    -1,    -1,    -1,    -1,   109,   110,   111,
     112,   113,   231,   115,   116,   117,    -1,    -1,    -1,   121,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    12,    13,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    -1,
      -1,    -1,   100,   101,   102,    -1,   104,    -1,   160,   161,
     162,   109,   110,   111,   112,   113,   231,   115,   116,   117,
      -1,    -1,    -1,   121,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,    -1,    -1,
      -1,    -1,   222,    -1,    -1,    -1,   226,    -1,    -1,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,   160,   161,   162,   100,   101,   102,    -1,   104,
      -1,    -1,    -1,    -1,   109,   110,   111,   112,   113,   231,
     115,   116,   117,    -1,    -1,    -1,   121,    -1,    -1,    -1,
      -1,    -1,    -1,     0,     1,    -1,    -1,     4,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    12,    13,    -1,    -1,    -1,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,    -1,   160,   161,   162,   222,    -1,
      -1,    -1,   226,   231,    -1,    42,    43,    -1,    -1,    -1,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,    -1,    62,    63,    64,   222,    -1,
      -1,    68,    69,    -1,    71,   229,    -1,    -1,    75,    76,
      -1,    78,    79,    -1,    -1,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      -1,    -1,    99,   100,   101,   102,   231,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,    -1,   120,   121,   122,   123,   124,   125,   126,
     127,   128,    -1,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,    -1,    -1,    -1,   146,
     147,   148,    -1,    -1,    -1,    -1,    -1,   154,     4,    -1,
      -1,    -1,   159,   160,   161,   162,    12,    13,   165,    -1,
     167,    -1,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,    -1,    -1,    -1,    -1,
      -1,   188,   189,   190,    -1,    -1,    42,    43,    -1,    -1,
     197,    -1,   199,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    62,    63,    64,    -1,
      -1,    -1,    68,    69,    -1,    71,    -1,    -1,    -1,    75,
      76,    -1,    78,    79,    -1,    -1,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    -1,    -1,    99,   100,   101,   102,    -1,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,    -1,   120,   121,   122,   123,   124,   125,
     126,   127,   128,    -1,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,    12,    13,    -1,
     146,   147,   148,    -1,    -1,    -1,    -1,    -1,   154,    -1,
      -1,    -1,    -1,   159,   160,   161,   162,    -1,    -1,   165,
      -1,   167,    -1,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,    -1,    -1,    -1,
      -1,    -1,   188,   189,   190,    -1,    -1,    -1,    -1,    -1,
      -1,   197,    -1,   199,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    -1,    -1,    -1,   100,   101,   102,    -1,   104,
      -1,    -1,    -1,    -1,   109,   110,   111,   112,   113,    -1,
     115,   116,   117,    -1,    -1,    -1,   121,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,    -1,    -1,    -1,    -1,   222,    -1,    -1,    -1,    -1,
      -1,    -1,   229,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   160,   161,   162,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,    -1,    -1,    -1,    -1,   222,    -1,    -1,    -1,
      -1,    -1,    -1,   229,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,    -1,    -1,
      -1,    -1,   222,    -1,    -1,    -1,    -1,    -1,    -1,   229,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,    -1,    -1,    -1,    -1,   222,    -1,
      -1,    -1,    -1,    -1,    -1,   229,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
      -1,    -1,    -1,    -1,   222,    -1,    -1,    -1,    -1,    -1,
      -1,   229,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,    -1,    -1,    -1,    -1,
     222,    -1,    -1,    -1,    -1,    -1,    -1,   229,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,    -1,    -1,    -1,    -1,   222,    -1,    -1,    -1,
      -1,    -1,    -1,   229,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,    -1,    -1,
      -1,    -1,   222,    -1,    -1,    -1,    -1,    -1,    -1,   229,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,    -1,    -1,    -1,    -1,   222,    -1,
      -1,    -1,    -1,    -1,    -1,   229,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
      -1,    -1,    -1,    -1,   222,    -1,    -1,    -1,    -1,    -1,
      -1,   229,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,    -1,    -1,    -1,    -1,
     222,    -1,    -1,    -1,    -1,    -1,    -1,   229,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,    -1,    -1,    -1,    -1,   222,    -1,    -1,    -1,
      -1,    -1,    -1,   229,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,    -1,    -1,
      -1,    -1,   222,    -1,    -1,    -1,    -1,    -1,    -1,   229,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,    -1,    -1,    -1,    -1,   222,    -1,
      -1,    -1,    -1,    -1,    -1,   229,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
      -1,    -1,    -1,    -1,   222,    -1,    -1,    -1,    -1,    -1,
      -1,   229,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,    -1,    -1,    -1,    -1,
     222,    -1,    -1,    -1,    -1,    -1,    -1,   229,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,    -1,    -1,    -1,    -1,   222,    -1,    -1,    -1,
      -1,    -1,    -1,   229,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,    -1,    -1,
      -1,    -1,   222,    -1,    -1,    -1,    -1,    -1,    -1,   229,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,    -1,    -1,    -1,    -1,   222,    -1,
      -1,    -1,    -1,    -1,    -1,   229,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
      -1,    -1,    -1,    -1,   222,    -1,    -1,    -1,    -1,    -1,
      -1,   229,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,    -1,    -1,    -1,    -1,
     222,    -1,    -1,    -1,    -1,    -1,    -1,   229,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,    -1,    -1,    -1,    -1,   222,    -1,    -1,    -1,
      -1,    -1,    -1,   229,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,    -1,    -1,
      -1,    -1,   222,    -1,    -1,    -1,    -1,    -1,    -1,   229,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,    -1,    -1,    -1,    -1,   222,    -1,
      -1,    -1,    -1,    -1,    -1,   229,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
      -1,    -1,    -1,    -1,   222,    -1,    -1,    -1,    -1,    -1,
      -1,   229,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,    -1,    -1,    -1,    -1,
     222,    -1,    -1,    -1,    -1,    -1,    -1,   229,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,    -1,    -1,    -1,    -1,   222,    -1,    -1,    -1,
      -1,    -1,    -1,   229,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,    -1,    -1,
      -1,    -1,   222,    -1,    -1,    -1,    -1,    -1,    -1,   229,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,    -1,    -1,    -1,    -1,   222,    -1,
      -1,    -1,    -1,    -1,    -1,   229,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
      -1,    -1,    -1,    -1,   222,    -1,    -1,    -1,    -1,    -1,
      -1,   229,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,    -1,    -1,    -1,    -1,
     222,    -1,    -1,    -1,    -1,    -1,    -1,   229,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,    -1,    -1,    -1,    -1,   222,    -1,    -1,    -1,
      -1,    -1,    -1,   229,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,    -1,    -1,
      -1,    -1,   222,    -1,    -1,    -1,    -1,    -1,    -1,   229,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,    -1,    -1,    -1,    -1,   222,    -1,
      -1,    -1,    -1,    -1,    -1,   229,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
      -1,    -1,    -1,    -1,   222,    -1,    -1,    -1,    -1,    -1,
      -1,   229,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,    -1,    -1,    -1,    -1,
     222,    -1,    -1,    -1,    -1,    -1,    -1,   229,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,    -1,    -1,    -1,    -1,   222,    -1,    -1,    -1,
      -1,    -1,    -1,   229,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,    -1,    -1,
      -1,    -1,   222,    -1,    -1,    -1,    -1,    -1,    -1,   229,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,    -1,    -1,    -1,    -1,   222,    -1,
      -1,    -1,    -1,    -1,    -1,   229,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
      -1,    -1,    -1,    -1,   222,    -1,    -1,    -1,    -1,    -1,
      -1,   229,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,    -1,    -1,    -1,    -1,
     222,    -1,    -1,    -1,    -1,    -1,    -1,   229,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,    -1,    -1,    -1,    -1,   222,    -1,    -1,    -1,
      -1,    -1,    -1,   229,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,    -1,    -1,
      -1,    -1,   222,    -1,    -1,    -1,    -1,    -1,    -1,   229,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,    -1,    -1,    -1,    -1,   222,    -1,
      -1,    -1,    -1,    -1,    -1,   229,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
      -1,    -1,    -1,    -1,   222,    -1,    -1,    -1,    -1,    -1,
      -1,   229,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,    -1,    -1,    -1,    -1,
     222,    -1,    -1,    -1,    -1,    -1,    -1,   229,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,    -1,    -1,    -1,    -1,   222,    -1,    -1,    -1,
      -1,    -1,    -1,   229,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,    -1,    -1,
      -1,    -1,   222,    -1,    -1,    -1,    -1,    -1,    -1,   229,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,    -1,    -1,    -1,    -1,   222,    -1,
      -1,    -1,   226,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,    -1,    -1,    -1,
      -1,   222,    -1,    -1,    -1,   226,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
      -1,    -1,    -1,    -1,   222,    -1,    -1,    -1,   226,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,    -1,    -1,    -1,    -1,   222,    -1,    -1,
      -1,   226,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,    -1,    -1,    -1,    -1,
     222,    -1,    -1,    -1,   226,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,    -1,
      -1,    -1,    -1,   222,    -1,    -1,    -1,   226,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,    -1,    -1,    -1,    -1,   222,    -1,    -1,    -1,
     226,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,    -1,    -1,    -1,    -1,   222,
      -1,    -1,    -1,   226,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,    -1,    -1,
      -1,    -1,   222,    -1,    -1,    -1,   226,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,    -1,    -1,    -1,    -1,   222,    -1,    -1,    -1,   226,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,    -1,    -1,    -1,    -1,   222,    -1,
      -1,    -1,   226,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,    -1,    -1,    -1,
      -1,   222,    -1,    -1,    -1,   226,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
      -1,    -1,    -1,    -1,   222,    -1,    -1,    -1,   226,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,    -1,    -1,    -1,    -1,   222,    -1,    -1,
      -1,   226,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,    -1,    -1,    -1,    -1,
     222,    -1,   224,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,    -1,    -1,    -1,
      -1,   222,    -1,   224,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,    -1,    -1,
      -1,    -1,   222,    -1,   224,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,    -1,
      -1,    -1,    -1,   222,    -1,   224,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
      -1,    -1,    -1,    -1,   222,    -1,   224,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,    -1,    -1,    -1,    -1,   222,    -1,   224,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,    -1,    -1,    -1,    -1,   222,    -1,   224,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,    -1,    -1,    -1,    -1,   222,    -1,   224,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,    -1,    -1,    -1,    -1,   222,    -1,
     224,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,    -1,    -1,    -1,    -1,   222,
      -1,   224,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,    -1,    -1,    -1,    -1,
     222,    -1,   224,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,    -1,    -1,    -1,
      -1,   222,    -1,   224,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,    -1,    -1,
      -1,    -1,   222,    -1,   224,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,    -1,
      -1,    -1,    -1,   222,    -1,   224,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
      -1,    -1,    -1,    -1,   222,    -1,   224,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,    -1,    -1,    -1,    -1,   222,    -1,   224,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,    -1,    -1,    -1,    -1,   222,    -1,   224,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,    -1,    -1,    -1,    -1,   222,    -1,   224,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,    -1,    -1,    -1,    -1,   222,    -1,
     224,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,    -1,    -1,    -1,    -1,   222,
      -1,   224,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,    -1,    -1,    -1,    -1,
     222,    -1,   224,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,    -1,    -1,    -1,
      -1,   222,    -1,   224,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,    -1,    -1,
      -1,    -1,   222,    -1,   224,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,    -1,
      -1,    -1,    -1,   222,    -1,   224,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
      -1,    -1,    -1,    -1,   222,    -1,   224,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,    -1,    -1,    -1,    -1,   222,    -1,   224,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,    -1,    -1,    -1,    -1,   222,    -1,   224,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,    -1,    -1,    -1,    -1,   222,    -1,   224,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,    -1,    -1,    -1,    -1,   222,    -1,
     224,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,    -1,    -1,    -1,    -1,   222,
      -1,   224,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,    -1,    -1,    -1,    -1,
     222,    -1,   224,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,    -1,    -1,    -1,
      -1,   222,    -1,   224,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,    -1,    -1,
      -1,    -1,   222,    -1,   224,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,    -1,
      -1,    -1,    -1,   222,    -1,   224,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
      -1,    -1,    -1,    -1,   222,    -1,   224,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,    -1,    -1,    -1,    -1,   222,    -1,   224,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,    -1,    -1,    -1,    -1,   222,    -1,   224,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,    -1,    -1,    -1,    -1,   222,    -1,   224,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,    -1,    -1,    -1,    -1,   222,    -1,
     224,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,    -1,    -1,    -1,    -1,   222,
      -1,   224,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,    -1,    -1,    -1,    -1,
     222,    -1,   224,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,    -1,    -1,    -1,
      -1,   222,    -1,   224,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,    -1,    -1,
      -1,    -1,   222,    -1,   224,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,    -1,
      -1,    -1,    -1,   222,    -1,   224,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
      -1,    -1,    -1,    -1,   222,    -1,   224,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,    -1,    -1,    -1,    -1,   222,    -1,   224,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,    -1,    -1,    -1,    -1,   222,    -1,   224,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,    -1,    -1,    -1,    -1,   222,    -1,   224,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,    -1,    -1,    -1,    -1,   222,    -1,
     224,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,    -1,    -1,    -1,    -1,   222,
      -1,   224,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,    -1,    -1,    -1,    -1,
     222,    -1,   224,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,    -1,    -1,    -1,
      -1,   222,    -1,   224,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,    -1,    -1,
      -1,    -1,   222,    -1,   224,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,    -1,
      -1,    -1,    -1,   222,    -1,   224,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
      -1,    -1,    -1,    -1,   222,    -1,   224,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,    -1,    -1,    -1,    -1,   222
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,   234,   235,     6,     0,     4,    12,    13,    42,
      43,    62,    63,    64,    68,    69,    71,    75,    76,    78,
      79,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    99,   100,   101,   102,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   146,   147,   148,
     154,   159,   160,   161,   162,   165,   167,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   188,   189,   190,   197,   199,   236,   238,   239,   259,
     278,   279,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   306,   308,   309,   315,   316,   317,   318,   336,   337,
       3,     4,     5,     9,    10,    11,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    65,    66,    67,
      70,    72,    73,    74,    80,    81,   176,   183,   184,   185,
     186,   187,   191,   192,   193,   194,   195,   196,   198,   213,
     214,   218,   223,   225,   227,   228,   230,   232,   257,   319,
     320,   332,   333,   336,   337,    13,    90,   223,   223,     6,
     230,     6,     6,     6,     6,   223,     6,     6,   225,   225,
     223,   225,   257,   257,   223,   230,   223,   223,     4,   223,
     230,   223,   223,     4,   230,   223,   223,   223,   223,   223,
     223,   223,   223,   223,   103,    90,    90,     6,   230,    84,
      87,    90,   223,   223,   223,    90,    90,    87,    90,    92,
      92,    84,    87,    90,    92,    87,    90,    92,    87,    90,
     223,    87,   165,   181,   182,   230,   213,   214,   223,   230,
     322,   323,   322,   230,    84,    87,    90,   230,   322,     4,
      84,    88,    94,    95,    97,    98,   112,    90,    92,    90,
      87,     4,   176,   230,   336,   337,     4,     6,    84,    87,
      90,    87,    90,     4,     4,     4,     4,     5,    37,    38,
      39,    40,    41,    84,    87,    90,    92,   116,   214,   223,
     230,   279,   290,   306,   308,   319,   325,   326,   327,   336,
     337,     4,   223,   223,   223,     4,   230,   329,   337,     4,
     223,   223,   223,     6,     6,   225,     4,   333,   337,   223,
       4,   333,     5,   230,     5,   230,     4,   319,   336,   225,
     223,   230,     6,   223,   230,   223,   225,   232,   257,     7,
     200,   201,   202,   203,   220,   221,   255,   256,     4,   223,
     225,   227,   257,   257,   257,   257,   257,   257,   257,   257,
     257,   257,   257,   257,   257,   257,   257,   257,   257,   257,
     257,   257,   257,   257,   257,   257,   257,   223,   223,   223,
     257,   257,   257,   257,   223,   257,   257,   257,   257,   257,
     257,   223,   257,   257,   257,     7,   223,   223,   223,   257,
     257,   223,   223,   225,   319,   319,   319,   224,   319,   226,
     319,     4,   165,   166,   337,     4,   279,   280,   281,   230,
     230,     6,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   222,   230,     6,   223,
     225,   256,     6,   319,     4,   332,   333,   336,   337,   332,
     319,   332,   335,   261,   266,   333,   337,   319,   214,   319,
     327,   328,   319,   319,   223,   319,   328,   319,   319,   223,
     328,   319,   319,   319,   319,   319,   319,   332,   319,   319,
     325,   223,   230,   328,   326,   326,   326,   332,   319,   319,
     223,   223,   326,   326,   326,   223,   223,   223,   223,   223,
     223,   325,   223,   325,   223,   325,   230,   230,   319,     4,
     325,   329,   230,   230,   322,   322,   322,   319,   319,   213,
     214,   230,   230,   322,   230,   230,   230,   213,   214,   223,
     281,   322,   230,   223,   230,   223,   223,   223,   223,   223,
     223,   223,   326,   326,   325,   223,     4,   225,   225,   281,
       6,     6,   230,   230,   230,   326,   326,   225,   225,   225,
     223,   225,   227,   257,   223,   225,   257,   257,   257,   257,
       5,   168,   230,     5,   168,     5,   168,     5,   168,    84,
      87,    90,    92,   230,   319,   327,   319,   231,   328,     8,
     215,     6,   223,   225,   257,     6,   319,   319,   319,   227,
     319,   230,   168,   319,   319,   319,   319,     6,     6,   230,
       6,   281,     6,   281,   223,   225,   230,   223,   225,   332,
     319,   281,   325,   325,   224,   319,   226,   319,   230,   230,
     333,   325,     6,   225,   319,   319,     4,   319,   319,   319,
     319,   319,   319,   319,   319,   319,   319,   319,   319,   319,
     319,   319,   319,   319,   319,   319,   319,   319,   319,   335,
     332,   335,   332,   332,   332,   332,   332,   332,   332,   325,
     332,   332,   319,   332,   332,   332,   335,   332,   319,   333,
     319,   332,   332,   332,   332,   332,   337,   333,   337,     7,
     203,   255,   224,     7,   203,   255,   226,     7,   255,   256,
     227,     7,   257,   231,    84,    87,    90,    92,   278,   319,
     328,   319,   319,   319,   319,   319,   319,   319,   319,   319,
     319,   319,   319,   319,   319,   319,   240,   319,   319,     6,
     223,   225,   227,   224,   229,   223,   225,   224,   229,   229,
     224,   229,   226,   229,   260,   226,   260,   229,   229,   224,
     215,   229,   231,   224,   224,   319,   224,   231,   224,   224,
     319,   231,   224,   224,   224,   224,   224,   224,   224,   224,
     224,     7,   319,   319,   231,     6,     6,     6,   224,   224,
     224,   319,   319,     7,     7,   312,   312,   319,   272,   319,
     333,   273,   319,   333,   274,   319,   333,   275,   319,   333,
     319,     6,   319,     6,   319,     6,   328,   328,   230,   224,
       6,   230,   281,   281,   229,   229,   229,   322,   322,   280,
     280,   229,   319,   319,   319,   319,   231,   294,   229,   281,
     319,   319,   319,   319,   319,   319,   319,   319,   319,     7,
     313,     6,     7,   319,     6,   319,   319,   231,   328,   328,
     328,     6,     6,   319,   319,   319,   319,   319,     4,   224,
     226,   230,   258,   230,   319,   327,   230,   327,   337,   319,
     319,   332,   319,    62,   319,    62,    62,    62,     5,   230,
       5,   230,     5,   230,     5,   230,   328,   224,   231,   319,
     230,   319,   327,   319,   319,   230,   258,   224,   224,   224,
     165,   229,   281,   230,     8,   224,   224,   226,   328,   231,
     231,   281,   226,   224,   138,   307,   224,   229,   231,     7,
     203,   255,   224,     7,   203,   255,   226,   319,   328,     6,
       6,   319,   224,   226,   256,   258,   258,   258,   258,   258,
     258,   258,   258,   258,   258,   258,   229,   258,   258,   258,
     258,   258,   258,   258,   229,   229,   229,   258,   229,   258,
     258,   224,   224,   229,   258,   258,   229,   258,   229,   229,
     229,   229,   258,   258,   258,   224,   258,   321,   334,     6,
     229,   229,   224,   229,   258,   229,   258,   224,   224,   226,
      44,    44,   325,     7,   255,   256,    44,    44,   325,   227,
     255,   256,   333,   319,     6,     4,     4,   230,   330,   258,
     230,   230,   230,   230,   231,   231,     8,     4,   155,   156,
     157,   158,   231,   243,   247,   250,   252,   253,   224,   226,
     319,   319,     4,     6,   210,   237,   328,   319,   319,     6,
     328,   319,     6,   332,     6,   337,     6,   332,   319,   333,
       7,   319,   327,   168,     7,     7,   224,     7,   168,     7,
       7,   224,   168,     7,     7,     7,     7,     7,     7,     7,
       7,   319,   224,   231,   230,     6,     7,     7,   224,   224,
     319,   325,     4,   311,     6,   224,   224,   229,   224,   229,
     224,   229,   224,   229,   224,   224,   224,   231,   231,   328,
     227,   281,   231,   231,   322,   319,   319,   231,   231,   319,
     322,   229,   229,   229,   119,   119,   135,   143,   144,   145,
     149,   150,   151,   152,   304,   305,   322,   231,   291,   224,
     231,   224,   224,   224,   224,   224,   224,   224,   319,     6,
     319,   224,   226,   226,   231,   231,   231,   226,   226,   229,
     224,   226,   328,   328,   224,   328,   226,   226,   229,   229,
     258,   229,   230,   231,   230,   230,   230,   328,   328,   328,
     328,   231,     8,   328,   224,   226,   328,     7,     7,     7,
     227,   319,   231,   319,   319,     7,   227,   231,   231,     7,
       6,   319,   231,   230,   325,     6,    44,    44,   325,   255,
     256,    44,    44,   325,   255,   256,   231,   231,   226,   256,
     227,   256,   332,   319,   319,   319,   319,   328,   332,   319,
     325,   332,   332,   332,   268,   270,   319,   332,   332,   319,
     257,   257,     6,   319,     6,   257,   257,     6,     4,   165,
     166,   319,     6,     6,     6,     7,   225,   329,   331,     6,
     328,   328,   328,   328,   258,   319,   244,   223,   223,   230,
     254,     6,   256,   256,   224,   226,   210,   332,   224,   224,
     226,   224,   229,     7,   223,   225,   258,   258,   322,    90,
      92,   325,   325,     7,   325,    90,    92,   325,   325,     7,
      92,   325,   325,   325,   325,   325,   325,   325,   325,     6,
       7,     7,   328,   325,   325,     7,     7,   119,   310,     6,
       7,   255,   319,   255,   319,   255,   319,   255,   319,     7,
       7,     7,     7,     7,   231,     4,   231,   229,   229,   229,
     231,   231,   322,   322,   322,    87,     4,     6,   319,   230,
       6,   223,     6,   153,     6,   153,     6,   153,     6,   153,
     231,   305,   229,   304,     7,     6,     7,     7,     7,     7,
       7,     7,     7,     6,   230,     6,     6,     6,    90,     7,
       6,     6,   319,   227,   231,   231,   231,   319,   319,   319,
     319,   319,   319,   319,   231,   231,   231,   231,   319,   231,
     231,   325,   325,   325,     4,   229,     8,     8,   224,     4,
       4,   229,   230,     6,   230,   325,   231,   257,   257,     6,
     319,     6,   257,   257,     6,   319,     6,   258,     6,     4,
       6,   258,   258,   258,   258,   258,   229,   229,   258,   224,
     258,   258,   229,   229,   258,   269,   229,   258,   271,   224,
     224,   258,   258,   258,   335,   335,     6,   258,   335,   335,
       7,   255,   256,   227,     7,     6,   329,   319,   229,   231,
     231,   231,   231,   231,   255,   223,   319,   319,   324,   325,
     230,   227,     6,     6,   237,     6,   319,   230,   319,   333,
     224,   226,     6,     6,     6,   230,   230,   112,   277,   277,
     325,     6,   230,   230,     6,     6,   325,   230,     6,     6,
       6,     6,     6,     6,     6,     6,     5,   325,   231,     6,
       6,   325,   325,     4,     6,   325,   325,   325,   325,   325,
     325,   325,   325,   230,   230,     7,     6,     7,   319,   319,
     319,   230,   230,   229,   231,   229,   231,   229,   231,   230,
     225,     6,   319,   325,   319,     6,     6,     6,     6,   319,
     322,   231,     5,   325,   230,   230,   230,   230,   230,   230,
     230,   325,   328,   230,   319,   226,     4,   258,   224,   226,
     229,   229,   229,   229,   229,   229,   229,   258,     6,     6,
     164,   319,   319,   319,     6,     6,     7,   333,   281,   281,
     229,     6,   258,   335,   335,     6,   258,   335,   335,     6,
     255,   256,   332,   319,   332,     4,     4,   180,     6,   258,
     258,     6,   258,   258,   333,   319,     6,     4,   330,     6,
     226,   329,     6,     6,     6,     6,   325,   241,   319,   229,
     229,   229,   231,   242,   319,     4,   332,   229,   325,   333,
       7,     7,   319,   319,   322,     6,     6,     6,   319,   319,
       6,   319,     5,     6,   230,     6,   168,   276,   319,     6,
       6,     6,     6,     6,     6,     4,     6,     6,   328,   328,
     319,   319,   333,   231,   224,   229,   231,   280,   280,   322,
       6,   295,   322,     6,   296,   322,     6,   297,   325,   319,
     231,   229,   224,   231,   229,     6,     6,   324,   322,   322,
     322,   322,   322,   214,   322,     6,   231,   319,     6,     6,
     319,   319,   319,   319,   319,   319,   319,   325,   229,   231,
       8,   231,   224,   230,   319,   333,   229,   307,   307,   325,
       6,   258,   258,     6,   258,   258,   325,   224,   258,   258,
     230,   325,   333,   230,   319,   333,   333,     6,     6,     6,
       6,     6,     6,     7,     6,   227,     6,   224,   229,   319,
     319,   325,   230,   229,   231,     6,   319,   262,   265,   230,
     230,   231,   231,   231,   231,   231,     5,   324,    88,     6,
     230,   231,   231,   230,     6,     6,   230,   319,   231,   231,
     229,   230,   229,   230,   229,   230,   231,   226,     6,   325,
       7,   230,   319,   231,   229,   229,   229,   229,   229,   229,
       6,   231,   258,   258,   229,   229,   229,   229,   229,   163,
     319,   319,   328,     6,     6,   333,   231,   231,   231,     6,
       6,     6,     6,     6,   267,   319,   327,   335,   329,   166,
     245,   319,   229,   229,   324,   319,     6,   229,   268,   270,
     325,   325,     6,     6,     6,     6,     6,     6,   231,   230,
     324,   123,   124,   129,   314,   123,   124,   314,   328,   280,
     229,   231,   319,   322,   304,   319,   322,   304,   319,   322,
     304,     6,   229,   231,   325,   281,   231,     6,   328,   322,
     322,   322,   322,   322,   319,   319,   319,   319,   319,   319,
     231,   231,   231,   224,   230,     6,   229,   231,     7,     7,
     231,     6,   230,   319,   319,   231,   319,   231,   231,   264,
     263,   230,   319,   231,   230,   322,   325,     6,   230,   322,
       6,   231,   231,   319,   231,   229,   231,   231,   229,   231,
     231,   229,   231,   325,     6,   119,   231,   292,   230,   231,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   229,
       6,     6,     6,   281,   319,   333,   337,   242,   224,   229,
       6,   230,   229,   268,   268,   319,   231,     6,   322,     6,
     322,     6,     6,   231,     6,   298,   319,     6,     6,   299,
     319,     6,     6,   300,   319,     6,   231,   319,   304,   281,
       6,   328,   328,   328,   328,   322,   328,   319,   319,   319,
     319,   319,   307,     7,   223,   231,   248,   319,   324,   319,
     231,   231,   229,   229,   229,   230,   231,   230,   231,   230,
     231,     6,     6,   231,   231,   293,   231,   231,   231,   231,
     229,   231,   229,   229,   229,   229,   229,   231,   333,   224,
       6,   230,   224,   231,   231,   319,   322,   322,   304,     6,
     301,   304,     6,   302,   304,     6,   303,   304,     6,     6,
       6,     6,   328,     6,   319,   319,   319,   319,   319,     6,
     246,   332,   251,   230,     6,   231,   229,   229,   231,   230,
     231,   230,   231,   230,   231,   231,   258,   229,   229,   229,
     229,   229,   231,   230,   324,     6,   319,   319,     6,   304,
       6,   304,     6,   304,     6,   319,   319,   319,   319,   332,
       6,   249,   332,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   229,   231,     6,     6,     6,     6,     6,
       6,   332,     6
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
        std::vector<int> wires;
        for(int i = 0; i < List_Nbr((yyvsp[(6) - (7)].l)); i++){
          double d; List_Read((yyvsp[(6) - (7)].l), i, &d);
          wires.push_back((int)std::abs(d));
        }
        GModel::current()->getOCCInternals()->addThruSections(num, wires);
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
#line 2675 "Gmsh.y"
    {
      GModel::current()->getGEOInternals()->addCompoundMesh(3, (yyvsp[(3) - (4)].l));
    ;}
    break;

  case 209:
#line 2679 "Gmsh.y"
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

  case 210:
#line 2695 "Gmsh.y"
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
#line 2743 "Gmsh.y"
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

  case 212:
#line 2760 "Gmsh.y"
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

  case 213:
#line 2778 "Gmsh.y"
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

  case 214:
#line 2788 "Gmsh.y"
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

  case 215:
#line 2798 "Gmsh.y"
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

  case 216:
#line 2808 "Gmsh.y"
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

  case 217:
#line 2871 "Gmsh.y"
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

  case 218:
#line 2882 "Gmsh.y"
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

  case 219:
#line 2897 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 220:
#line 2898 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 221:
#line 2903 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    ;}
    break;

  case 222:
#line 2907 "Gmsh.y"
    {
      List_Add((yyval.l), &(yyvsp[(2) - (2)].s));
    ;}
    break;

  case 223:
#line 2911 "Gmsh.y"
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

  case 224:
#line 2940 "Gmsh.y"
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

  case 225:
#line 2969 "Gmsh.y"
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

  case 226:
#line 2998 "Gmsh.y"
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

  case 227:
#line 3032 "Gmsh.y"
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
#line 3054 "Gmsh.y"
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
#line 3081 "Gmsh.y"
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
#line 3103 "Gmsh.y"
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
#line 3125 "Gmsh.y"
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
#line 3147 "Gmsh.y"
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
#line 3203 "Gmsh.y"
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
#line 3227 "Gmsh.y"
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
#line 3252 "Gmsh.y"
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
#line 3277 "Gmsh.y"
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
#line 3390 "Gmsh.y"
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
#line 3409 "Gmsh.y"
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
#line 3452 "Gmsh.y"
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

  case 240:
#line 3473 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      GModel::current()->getFields()->deleteField((int)(yyvsp[(4) - (6)].d));
#endif
    ;}
    break;

  case 241:
#line 3479 "Gmsh.y"
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
#line 3494 "Gmsh.y"
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

  case 243:
#line 3522 "Gmsh.y"
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
#line 3539 "Gmsh.y"
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
#line 3548 "Gmsh.y"
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
#line 3562 "Gmsh.y"
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
#line 3576 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 1, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 248:
#line 3582 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 0, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 249:
#line 3588 "Gmsh.y"
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
#line 3597 "Gmsh.y"
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
#line 3606 "Gmsh.y"
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
#line 3615 "Gmsh.y"
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
#line 3629 "Gmsh.y"
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
#line 3691 "Gmsh.y"
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
#line 3709 "Gmsh.y"
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
#line 3726 "Gmsh.y"
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
#line 3741 "Gmsh.y"
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
#line 3770 "Gmsh.y"
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
#line 3782 "Gmsh.y"
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
#line 3806 "Gmsh.y"
    {
      Msg::Exit(0);
    ;}
    break;

  case 261:
#line 3810 "Gmsh.y"
    {
      gmsh_yyerrorstate = 999; // this will be checked when yyparse returns
      YYABORT;
    ;}
    break;

  case 262:
#line 3815 "Gmsh.y"
    {
      // FIXME: this is a hack to force a transfer from the old DB to
      // the new DB. This will become unnecessary if/when we fill the
      // GModel directly during parsing.
      GModel::current()->importGEOInternals();
      GModel::current()->importOCCInternals();
    ;}
    break;

  case 263:
#line 3823 "Gmsh.y"
    {
      new GModel();
      GModel::current(GModel::list.size() - 1);
    ;}
    break;

  case 264:
#line 3828 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 0;
      GModel::current()->importGEOInternals();
      SetBoundingBox();
    ;}
    break;

  case 265:
#line 3834 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 1;
      SetBoundingBox((yyvsp[(3) - (15)].d), (yyvsp[(5) - (15)].d), (yyvsp[(7) - (15)].d), (yyvsp[(9) - (15)].d), (yyvsp[(11) - (15)].d), (yyvsp[(13) - (15)].d));
    ;}
    break;

  case 266:
#line 3839 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
      drawContext::global()->draw();
#endif
    ;}
    break;

  case 267:
#line 3845 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
     CTX::instance()->mesh.changed = ENT_ALL;
     for(unsigned int index = 0; index < PView::list.size(); index++)
       PView::list[index]->setChanged(true);
#endif
    ;}
    break;

  case 268:
#line 3853 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh();
    ;}
    break;

  case 269:
#line 3857 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh(1);
    ;}
    break;

  case 270:
#line 3861 "Gmsh.y"
    {
      GModel::current()->importGEOInternals();
      GModel::current()->refineMesh(CTX::instance()->mesh.secondOrderLinear);
    ;}
    break;

  case 271:
#line 3867 "Gmsh.y"
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
#line 3926 "Gmsh.y"
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
#line 3942 "Gmsh.y"
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
#line 3959 "Gmsh.y"
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
#line 3976 "Gmsh.y"
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
#line 3998 "Gmsh.y"
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
#line 4020 "Gmsh.y"
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
#line 4055 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip_until(NULL, "Return");
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 279:
#line 4063 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip_until(NULL, "Return");
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 280:
#line 4071 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    ;}
    break;

  case 281:
#line 4077 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 282:
#line 4084 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 283:
#line 4091 "Gmsh.y"
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
#line 4111 "Gmsh.y"
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
#line 4137 "Gmsh.y"
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
#line 4149 "Gmsh.y"
    {
      ImbricatedTest--;
      if(ImbricatedTest < 0)
        yymsg(1, "Orphan EndIf");
    ;}
    break;

  case 287:
#line 4161 "Gmsh.y"
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

  case 288:
#line 4191 "Gmsh.y"
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

  case 289:
#line 4222 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (13)].l),
		    (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].v)[0], (yyvsp[(7) - (13)].v)[1], (yyvsp[(7) - (13)].v)[2], (yyvsp[(9) - (13)].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[(12) - (13)].l));
    ;}
    break;

  case 290:
#line 4230 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 291:
#line 4236 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (7)].l),
		    (yyvsp[(2) - (7)].v)[0], (yyvsp[(2) - (7)].v)[1], (yyvsp[(2) - (7)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(4) - (7)].l));
    ;}
    break;

  case 292:
#line 4244 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 293:
#line 4250 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[(10) - (13)].l),
		    0., 0., 0., (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(10) - (13)].l));
    ;}
    break;

  case 294:
#line 4258 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 295:
#line 4264 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (15)].l),
		    (yyvsp[(3) - (15)].v)[0], (yyvsp[(3) - (15)].v)[1], (yyvsp[(3) - (15)].v)[2], (yyvsp[(5) - (15)].v)[0], (yyvsp[(5) - (15)].v)[1], (yyvsp[(5) - (15)].v)[2], (yyvsp[(7) - (15)].v)[0], (yyvsp[(7) - (15)].v)[1], (yyvsp[(7) - (15)].v)[2], (yyvsp[(9) - (15)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(12) - (15)].l));
    ;}
    break;

  case 296:
#line 4272 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 297:
#line 4278 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(BOUNDARY_LAYER, (yyvsp[(3) - (6)].l), 0., 0., 0., 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(3) - (6)].l));
    ;}
    break;

  case 298:
#line 4285 "Gmsh.y"
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

  case 299:
#line 4319 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 300:
#line 4326 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 301:
#line 4333 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 302:
#line 4340 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 303:
#line 4347 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 304:
#line 4354 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 305:
#line 4361 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 306:
#line 4368 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 307:
#line 4375 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 308:
#line 4382 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 309:
#line 4388 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 310:
#line 4395 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 311:
#line 4401 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 312:
#line 4408 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 313:
#line 4414 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 314:
#line 4421 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 315:
#line 4427 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 316:
#line 4434 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 317:
#line 4440 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 318:
#line 4447 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 319:
#line 4453 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 320:
#line 4460 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 321:
#line 4466 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 322:
#line 4473 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 323:
#line 4479 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 324:
#line 4486 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 325:
#line 4492 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 326:
#line 4503 "Gmsh.y"
    {
    ;}
    break;

  case 327:
#line 4506 "Gmsh.y"
    {
    ;}
    break;

  case 328:
#line 4512 "Gmsh.y"
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

  case 329:
#line 4524 "Gmsh.y"
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

  case 330:
#line 4544 "Gmsh.y"
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

  case 331:
#line 4568 "Gmsh.y"
    {
      extr.mesh.ScaleLast = true;
    ;}
    break;

  case 332:
#line 4572 "Gmsh.y"
    {
      extr.mesh.Recombine = true;
    ;}
    break;

  case 333:
#line 4576 "Gmsh.y"
    {
      extr.mesh.Recombine = (yyvsp[(2) - (3)].d) ? true : false;
    ;}
    break;

  case 334:
#line 4580 "Gmsh.y"
    {
      yymsg(0, "Keyword 'QuadTriSngl' deprecated. Use 'QuadTriNoNewVerts' instead.");
    ;}
    break;

  case 335:
#line 4584 "Gmsh.y"
    {
      yymsg(0, "Keyword 'QuadTriSngl' deprecated. Use 'QuadTriNoNewVerts' instead.");
    ;}
    break;

  case 336:
#line 4588 "Gmsh.y"
    {
      yymsg(0, "Method 'QuadTriDbl' deprecated. Use 'QuadTriAddVerts' instead, "
            "which has no requirement for the number of extrusion layers and meshes "
            "with body-centered vertices.");
    ;}
    break;

  case 337:
#line 4594 "Gmsh.y"
    {
      yymsg(0, "Method 'QuadTriDbl' deprecated. Use 'QuadTriAddVerts' instead, "
            "which has no requirement for the number of extrusion layers and meshes "
            "with body-centered vertices.");
    ;}
    break;

  case 338:
#line 4600 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1;
    ;}
    break;

  case 339:
#line 4604 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1_RECOMB;
    ;}
    break;

  case 340:
#line 4608 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1;
    ;}
    break;

  case 341:
#line 4612 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1_RECOMB;
    ;}
    break;

  case 342:
#line 4616 "Gmsh.y"
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

  case 343:
#line 4635 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (6)].c), "Index"))
        extr.mesh.BoundaryLayerIndex = (yyvsp[(4) - (6)].d);
      else if(!strcmp((yyvsp[(2) - (6)].c), "View"))
        extr.mesh.ViewIndex = (yyvsp[(4) - (6)].d);
      Free((yyvsp[(2) - (6)].c));
    ;}
    break;

  case 344:
#line 4647 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Union; ;}
    break;

  case 345:
#line 4648 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Intersection; ;}
    break;

  case 346:
#line 4649 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Difference; ;}
    break;

  case 347:
#line 4650 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Section; ;}
    break;

  case 348:
#line 4651 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Fragments; ;}
    break;

  case 349:
#line 4655 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 350:
#line 4656 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 351:
#line 4657 "Gmsh.y"
    { (yyval.i) = (yyvsp[(2) - (3)].d); ;}
    break;

  case 352:
#line 4662 "Gmsh.y"
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

  case 353:
#line 4695 "Gmsh.y"
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

  case 354:
#line 4722 "Gmsh.y"
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

  case 355:
#line 4744 "Gmsh.y"
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    ;}
    break;

  case 356:
#line 4748 "Gmsh.y"
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

  case 357:
#line 4763 "Gmsh.y"
    {
      (yyval.i) = -1; // left
    ;}
    break;

  case 358:
#line 4767 "Gmsh.y"
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

  case 359:
#line 4783 "Gmsh.y"
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   ;}
    break;

  case 360:
#line 4787 "Gmsh.y"
    {
     (yyval.l) = (yyvsp[(2) - (2)].l);
   ;}
    break;

  case 361:
#line 4792 "Gmsh.y"
    {
      (yyval.i) = 45;
    ;}
    break;

  case 362:
#line 4796 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(2) - (2)].d);
    ;}
    break;

  case 363:
#line 4802 "Gmsh.y"
    {
      (yyval.l) = List_Create(1, 1, sizeof(double));
    ;}
    break;

  case 364:
#line 4806 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
    ;}
    break;

  case 365:
#line 4813 "Gmsh.y"
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

  case 366:
#line 4869 "Gmsh.y"
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

  case 367:
#line 4939 "Gmsh.y"
    {
      yymsg(1, "Elliptic Surface is deprecated: use Transfinite instead (with smoothing)");
      List_Delete((yyvsp[(7) - (8)].l));
    ;}
    break;

  case 368:
#line 4944 "Gmsh.y"
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

  case 369:
#line 5011 "Gmsh.y"
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

  case 370:
#line 5047 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (8)].l)); i++){
	double d;
	List_Read((yyvsp[(4) - (8)].l), i, &d);
	CTX::instance()->mesh.algo2d_per_face[(int)d] = (int)(yyvsp[(7) - (8)].d);
      }
    ;}
    break;

  case 371:
#line 5055 "Gmsh.y"
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

  case 372:
#line 5098 "Gmsh.y"
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

  case 373:
#line 5137 "Gmsh.y"
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

  case 374:
#line 5158 "Gmsh.y"
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
#line 5190 "Gmsh.y"
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
#line 5217 "Gmsh.y"
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
#line 5243 "Gmsh.y"
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
#line 5269 "Gmsh.y"
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
#line 5295 "Gmsh.y"
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
#line 5321 "Gmsh.y"
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
#line 5342 "Gmsh.y"
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

  case 382:
#line 5370 "Gmsh.y"
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

  case 383:
#line 5398 "Gmsh.y"
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

  case 384:
#line 5426 "Gmsh.y"
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

  case 385:
#line 5454 "Gmsh.y"
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

  case 386:
#line 5482 "Gmsh.y"
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

  case 387:
#line 5521 "Gmsh.y"
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

  case 388:
#line 5560 "Gmsh.y"
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

  case 389:
#line 5581 "Gmsh.y"
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

  case 390:
#line 5602 "Gmsh.y"
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

  case 391:
#line 5629 "Gmsh.y"
    {
      ReplaceAllDuplicates();
    ;}
    break;

  case 392:
#line 5633 "Gmsh.y"
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

  case 393:
#line 5643 "Gmsh.y"
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

  case 394:
#line 5677 "Gmsh.y"
    { (yyval.c) = (char*)"Homology"; ;}
    break;

  case 395:
#line 5678 "Gmsh.y"
    { (yyval.c) = (char*)"Cohomology"; ;}
    break;

  case 396:
#line 5679 "Gmsh.y"
    { (yyval.c) = (char*)"Betti"; ;}
    break;

  case 397:
#line 5684 "Gmsh.y"
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest((yyvsp[(1) - (2)].c), domain, subdomain, dim);
    ;}
    break;

  case 398:
#line 5690 "Gmsh.y"
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

  case 399:
#line 5702 "Gmsh.y"
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

  case 400:
#line 5720 "Gmsh.y"
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

  case 401:
#line 5747 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d);           ;}
    break;

  case 402:
#line 5748 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (3)].d);           ;}
    break;

  case 403:
#line 5749 "Gmsh.y"
    { (yyval.d) = -(yyvsp[(2) - (2)].d);          ;}
    break;

  case 404:
#line 5750 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);           ;}
    break;

  case 405:
#line 5751 "Gmsh.y"
    { (yyval.d) = !(yyvsp[(2) - (2)].d);          ;}
    break;

  case 406:
#line 5752 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) - (yyvsp[(3) - (3)].d);      ;}
    break;

  case 407:
#line 5753 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) + (yyvsp[(3) - (3)].d);      ;}
    break;

  case 408:
#line 5754 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) * (yyvsp[(3) - (3)].d);      ;}
    break;

  case 409:
#line 5756 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (3)].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));
      else
	(yyval.d) = (yyvsp[(1) - (3)].d) / (yyvsp[(3) - (3)].d);
    ;}
    break;

  case 410:
#line 5762 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) % (int)(yyvsp[(3) - (3)].d);  ;}
    break;

  case 411:
#line 5763 "Gmsh.y"
    { (yyval.d) = pow((yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));  ;}
    break;

  case 412:
#line 5764 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d);      ;}
    break;

  case 413:
#line 5765 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) > (yyvsp[(3) - (3)].d);      ;}
    break;

  case 414:
#line 5766 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) <= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 415:
#line 5767 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) >= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 416:
#line 5768 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) == (yyvsp[(3) - (3)].d);     ;}
    break;

  case 417:
#line 5769 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) != (yyvsp[(3) - (3)].d);     ;}
    break;

  case 418:
#line 5770 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) && (yyvsp[(3) - (3)].d);     ;}
    break;

  case 419:
#line 5771 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) || (yyvsp[(3) - (3)].d);     ;}
    break;

  case 420:
#line 5772 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (5)].d) ? (yyvsp[(3) - (5)].d) : (yyvsp[(5) - (5)].d); ;}
    break;

  case 421:
#line 5773 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 422:
#line 5774 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 423:
#line 5775 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 424:
#line 5776 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 425:
#line 5777 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 426:
#line 5778 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 427:
#line 5779 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 428:
#line 5780 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 429:
#line 5781 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 430:
#line 5782 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 431:
#line 5783 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 432:
#line 5784 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 433:
#line 5785 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 434:
#line 5786 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 435:
#line 5787 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 436:
#line 5788 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 437:
#line 5789 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 438:
#line 5790 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d) + 0.5); ;}
    break;

  case 439:
#line 5791 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 440:
#line 5792 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 441:
#line 5793 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 442:
#line 5794 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 443:
#line 5803 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 444:
#line 5804 "Gmsh.y"
    { (yyval.d) = 3.141592653589793; ;}
    break;

  case 445:
#line 5805 "Gmsh.y"
    { (yyval.d) = (double)ImbricatedTest; ;}
    break;

  case 446:
#line 5806 "Gmsh.y"
    { (yyval.d) = Msg::GetCommRank(); ;}
    break;

  case 447:
#line 5807 "Gmsh.y"
    { (yyval.d) = Msg::GetCommSize(); ;}
    break;

  case 448:
#line 5808 "Gmsh.y"
    { (yyval.d) = GetGmshMajorVersion(); ;}
    break;

  case 449:
#line 5809 "Gmsh.y"
    { (yyval.d) = GetGmshMinorVersion(); ;}
    break;

  case 450:
#line 5810 "Gmsh.y"
    { (yyval.d) = GetGmshPatchVersion(); ;}
    break;

  case 451:
#line 5811 "Gmsh.y"
    { (yyval.d) = Cpu(); ;}
    break;

  case 452:
#line 5812 "Gmsh.y"
    { (yyval.d) = GetMemoryUsage()/1024./1024.; ;}
    break;

  case 453:
#line 5813 "Gmsh.y"
    { (yyval.d) = TotalRam(); ;}
    break;

  case 454:
#line 5818 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 455:
#line 5820 "Gmsh.y"
    {
      std::vector<double> val(1, (yyvsp[(3) - (6)].d));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.d) = val[0];
    ;}
    break;

  case 456:
#line 5826 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 457:
#line 5831 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 458:
#line 5836 "Gmsh.y"
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

  case 459:
#line 5853 "Gmsh.y"
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

  case 460:
#line 5871 "Gmsh.y"
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

  case 461:
#line 5889 "Gmsh.y"
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

  case 462:
#line 5907 "Gmsh.y"
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
#line 5925 "Gmsh.y"
    {
      (yyval.d) = gmsh_yysymbols.count((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 464:
#line 5930 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.d) = !StatFile(tmp);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 465:
#line 5936 "Gmsh.y"
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

  case 466:
#line 5951 "Gmsh.y"
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

  case 467:
#line 5970 "Gmsh.y"
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

  case 468:
#line 5990 "Gmsh.y"
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

  case 469:
#line 6010 "Gmsh.y"
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

  case 470:
#line 6030 "Gmsh.y"
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
#line 6053 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), (yyval.d));
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 472:
#line 6058 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), (yyval.d));
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 473:
#line 6063 "Gmsh.y"
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

  case 474:
#line 6073 "Gmsh.y"
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

  case 475:
#line 6083 "Gmsh.y"
    {
      (yyval.d) = Msg::GetValue((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 476:
#line 6088 "Gmsh.y"
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

  case 477:
#line 6099 "Gmsh.y"
    {
      std::string s((yyvsp[(3) - (6)].c)), substr((yyvsp[(5) - (6)].c));
      if(s.find(substr) != std::string::npos)
        (yyval.d) = 1.;
      else
        (yyval.d) = 0.;
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 478:
#line 6108 "Gmsh.y"
    {
      (yyval.d) = strlen((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 479:
#line 6113 "Gmsh.y"
    {
      (yyval.d) = strcmp((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 480:
#line 6118 "Gmsh.y"
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

  case 481:
#line 6145 "Gmsh.y"
    {
      memcpy((yyval.v), (yyvsp[(1) - (1)].v), 5*sizeof(double));
    ;}
    break;

  case 482:
#line 6149 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 483:
#line 6153 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 484:
#line 6157 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] - (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 485:
#line 6161 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] + (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 486:
#line 6168 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (11)].d);  (yyval.v)[1] = (yyvsp[(4) - (11)].d);  (yyval.v)[2] = (yyvsp[(6) - (11)].d);  (yyval.v)[3] = (yyvsp[(8) - (11)].d); (yyval.v)[4] = (yyvsp[(10) - (11)].d);
    ;}
    break;

  case 487:
#line 6172 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (9)].d);  (yyval.v)[1] = (yyvsp[(4) - (9)].d);  (yyval.v)[2] = (yyvsp[(6) - (9)].d);  (yyval.v)[3] = (yyvsp[(8) - (9)].d); (yyval.v)[4] = 1.0;
    ;}
    break;

  case 488:
#line 6176 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 489:
#line 6180 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 490:
#line 6187 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].l)));
    ;}
    break;

  case 491:
#line 6192 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].l)));
    ;}
    break;

  case 492:
#line 6199 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 493:
#line 6204 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 494:
#line 6208 "Gmsh.y"
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    ;}
    break;

  case 495:
#line 6213 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 496:
#line 6217 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 497:
#line 6225 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (5)].d);
      }
    ;}
    break;

  case 498:
#line 6236 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 499:
#line 6240 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(1) - (1)].c), "*") || !strcmp((yyvsp[(1) - (1)].c), "all"))
        (yyval.l) = 0;
      else{
        yyerror("Unknown special string for list replacement");
        (yyval.l) = List_Create(2, 1, sizeof(double));
      }
    ;}
    break;

  case 500:
#line 6252 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 501:
#line 6260 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (3)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (3)].d);
      }
    ;}
    break;

  case 502:
#line 6268 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      for(double d = (yyvsp[(1) - (3)].d); ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d <= (yyvsp[(3) - (3)].d)) : (d >= (yyvsp[(3) - (3)].d));
          ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d += 1.) : (d -= 1.))
	List_Add((yyval.l), &d);
    ;}
    break;

  case 503:
#line 6275 "Gmsh.y"
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

  case 504:
#line 6285 "Gmsh.y"
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

  case 505:
#line 6314 "Gmsh.y"
    {
      (yyval.l) = GetAllElementaryEntityNumbers(0);
    ;}
    break;

  case 506:
#line 6318 "Gmsh.y"
    {
      (yyval.l) = GetAllElementaryEntityNumbers(1);
    ;}
    break;

  case 507:
#line 6322 "Gmsh.y"
    {
      (yyval.l) = GetAllElementaryEntityNumbers(2);
    ;}
    break;

  case 508:
#line 6326 "Gmsh.y"
    {
      (yyval.l) = GetAllElementaryEntityNumbers(3);
    ;}
    break;

  case 509:
#line 6330 "Gmsh.y"
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(0);
    ;}
    break;

  case 510:
#line 6334 "Gmsh.y"
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(1);
    ;}
    break;

  case 511:
#line 6338 "Gmsh.y"
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(2);
    ;}
    break;

  case 512:
#line 6342 "Gmsh.y"
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(3);
    ;}
    break;

  case 513:
#line 6346 "Gmsh.y"
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

  case 514:
#line 6375 "Gmsh.y"
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

  case 515:
#line 6404 "Gmsh.y"
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

  case 516:
#line 6433 "Gmsh.y"
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

  case 517:
#line 6463 "Gmsh.y"
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

  case 518:
#line 6476 "Gmsh.y"
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

  case 519:
#line 6489 "Gmsh.y"
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

  case 520:
#line 6502 "Gmsh.y"
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

  case 521:
#line 6514 "Gmsh.y"
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

  case 522:
#line 6524 "Gmsh.y"
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

  case 523:
#line 6534 "Gmsh.y"
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

  case 524:
#line 6544 "Gmsh.y"
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

  case 525:
#line 6556 "Gmsh.y"
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

  case 526:
#line 6569 "Gmsh.y"
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

  case 527:
#line 6581 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 528:
#line 6585 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 529:
#line 6589 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (6)].l);
    ;}
    break;

  case 530:
#line 6593 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (6)].l);
    ;}
    break;

  case 531:
#line 6597 "Gmsh.y"
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

  case 532:
#line 6615 "Gmsh.y"
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

  case 533:
#line 6633 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = (yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1);
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 534:
#line 6641 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = pow(10,(yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1));
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 535:
#line 6649 "Gmsh.y"
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

  case 536:
#line 6678 "Gmsh.y"
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

  case 537:
#line 6691 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 538:
#line 6696 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 539:
#line 6700 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].d)));
    ;}
    break;

  case 540:
#line 6704 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (3)].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 541:
#line 6716 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (9)].d), (int)(yyvsp[(4) - (9)].d), (int)(yyvsp[(6) - (9)].d), (int)(yyvsp[(8) - (9)].d));
    ;}
    break;

  case 542:
#line 6720 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (7)].d), (int)(yyvsp[(4) - (7)].d), (int)(yyvsp[(6) - (7)].d), 255);
    ;}
    break;

  case 543:
#line 6732 "Gmsh.y"
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

  case 544:
#line 6749 "Gmsh.y"
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(5) - (5)].c), val);
      (yyval.u) = val;
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(5) - (5)].c));
    ;}
    break;

  case 545:
#line 6759 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 546:
#line 6763 "Gmsh.y"
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

  case 547:
#line 6778 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].u)));
    ;}
    break;

  case 548:
#line 6783 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].u)));
    ;}
    break;

  case 549:
#line 6790 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 550:
#line 6794 "Gmsh.y"
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

  case 551:
#line 6807 "Gmsh.y"
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

  case 552:
#line 6821 "Gmsh.y"
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

  case 553:
#line 6835 "Gmsh.y"
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

  case 554:
#line 6849 "Gmsh.y"
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

  case 555:
#line 6863 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 556:
#line 6871 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 557:
#line 6882 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 558:
#line 6886 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 559:
#line 6890 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    ;}
    break;

  case 560:
#line 6898 "Gmsh.y"
    {
      std::string exe = Msg::GetExecutableName();
      (yyval.c) = (char *)Malloc(exe.size() + 1);
      strcpy((yyval.c), exe.c_str());
    ;}
    break;

  case 561:
#line 6904 "Gmsh.y"
    {
      std::string action = Msg::GetOnelabAction();
      (yyval.c) = (char *)Malloc(action.size() + 1);
      strcpy((yyval.c), action.c_str());
    ;}
    break;

  case 562:
#line 6910 "Gmsh.y"
    {
      const char *env = GetEnvironmentVar((yyvsp[(3) - (4)].c));
      if(!env) env = "";
      (yyval.c) = (char *)Malloc((sizeof(env) + 1) * sizeof(char));
      strcpy((yyval.c), env);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 563:
#line 6918 "Gmsh.y"
    {
      std::string s = Msg::GetString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 564:
#line 6926 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (4)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 565:
#line 6933 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 566:
#line 6941 "Gmsh.y"
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

  case 567:
#line 6956 "Gmsh.y"
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

  case 568:
#line 6970 "Gmsh.y"
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

  case 569:
#line 6984 "Gmsh.y"
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

  case 570:
#line 6996 "Gmsh.y"
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

  case 571:
#line 7012 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = toupper((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 572:
#line 7021 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = tolower((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 573:
#line 7030 "Gmsh.y"
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

  case 574:
#line 7040 "Gmsh.y"
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

  case 575:
#line 7051 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (8)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (8)].d), (int)(yyvsp[(7) - (8)].d));
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (8)].c));
    ;}
    break;

  case 576:
#line 7059 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (6)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (6)].d), std::string::npos);
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 577:
#line 7067 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 578:
#line 7071 "Gmsh.y"
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

  case 579:
#line 7090 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 580:
#line 7097 "Gmsh.y"
    {
      std::string tmp = SplitFileName(GetAbsolutePath(gmsh_yyname))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
    ;}
    break;

  case 581:
#line 7103 "Gmsh.y"
    {
      std::string tmp = SplitFileName((yyvsp[(3) - (4)].c))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 582:
#line 7110 "Gmsh.y"
    {
      std::string tmp = GetAbsolutePath((yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 583:
#line 7117 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 584:
#line 7119 "Gmsh.y"
    {
      std::string val((yyvsp[(3) - (6)].c));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.c) = (char*)Malloc((val.size() + 1) * sizeof(char));
      strcpy((yyval.c), val.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 585:
#line 7130 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].c)));
    ;}
    break;

  case 586:
#line 7135 "Gmsh.y"
    { List_Add((yyval.l), &((yyvsp[(3) - (3)].c))); ;}
    break;

  case 587:
#line 7141 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 588:
#line 7150 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char)) ;
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)) ; strcat((yyval.c), tmpstr) ;
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 589:
#line 7163 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 590:
#line 7166 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 591:
#line 7170 "Gmsh.y"
    { (yyval.c) = (yyvsp[(3) - (4)].c); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 14343 "Gmsh.tab.cpp"
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


#line 7173 "Gmsh.y"


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

