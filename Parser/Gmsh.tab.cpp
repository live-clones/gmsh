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
     tPlane = 366,
     tRuled = 367,
     tTransfinite = 368,
     tComplex = 369,
     tPhysical = 370,
     tCompound = 371,
     tPeriodic = 372,
     tUsing = 373,
     tPlugin = 374,
     tDegenerated = 375,
     tRecursive = 376,
     tRotate = 377,
     tTranslate = 378,
     tSymmetry = 379,
     tDilate = 380,
     tExtrude = 381,
     tLevelset = 382,
     tAffine = 383,
     tBooleanUnion = 384,
     tBooleanIntersection = 385,
     tBooleanDifference = 386,
     tBooleanSection = 387,
     tBooleanFragments = 388,
     tRecombine = 389,
     tSmoother = 390,
     tSplit = 391,
     tDelete = 392,
     tCoherence = 393,
     tIntersect = 394,
     tMeshAlgorithm = 395,
     tReverse = 396,
     tLayers = 397,
     tScaleLast = 398,
     tHole = 399,
     tAlias = 400,
     tAliasWithOptions = 401,
     tCopyOptions = 402,
     tQuadTriAddVerts = 403,
     tQuadTriNoNewVerts = 404,
     tQuadTriSngl = 405,
     tQuadTriDbl = 406,
     tRecombLaterals = 407,
     tTransfQuadTri = 408,
     tText2D = 409,
     tText3D = 410,
     tInterpolationScheme = 411,
     tTime = 412,
     tCombine = 413,
     tBSpline = 414,
     tBezier = 415,
     tNurbs = 416,
     tNurbsOrder = 417,
     tNurbsKnots = 418,
     tColor = 419,
     tColorTable = 420,
     tFor = 421,
     tIn = 422,
     tEndFor = 423,
     tIf = 424,
     tElseIf = 425,
     tElse = 426,
     tEndIf = 427,
     tExit = 428,
     tAbort = 429,
     tField = 430,
     tReturn = 431,
     tCall = 432,
     tSlide = 433,
     tMacro = 434,
     tShow = 435,
     tHide = 436,
     tGetValue = 437,
     tGetStringValue = 438,
     tGetEnv = 439,
     tGetString = 440,
     tGetNumber = 441,
     tHomology = 442,
     tCohomology = 443,
     tBetti = 444,
     tExists = 445,
     tFileExists = 446,
     tGMSH_MAJOR_VERSION = 447,
     tGMSH_MINOR_VERSION = 448,
     tGMSH_PATCH_VERSION = 449,
     tGmshExecutableName = 450,
     tSetPartition = 451,
     tNameToString = 452,
     tStringToName = 453,
     tAFFECTDIVIDE = 454,
     tAFFECTTIMES = 455,
     tAFFECTMINUS = 456,
     tAFFECTPLUS = 457,
     tOR = 458,
     tAND = 459,
     tNOTEQUAL = 460,
     tEQUAL = 461,
     tGREATEROREQUAL = 462,
     tLESSOREQUAL = 463,
     UNARYPREC = 464,
     tMINUSMINUS = 465,
     tPLUSPLUS = 466
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
#define tPlane 366
#define tRuled 367
#define tTransfinite 368
#define tComplex 369
#define tPhysical 370
#define tCompound 371
#define tPeriodic 372
#define tUsing 373
#define tPlugin 374
#define tDegenerated 375
#define tRecursive 376
#define tRotate 377
#define tTranslate 378
#define tSymmetry 379
#define tDilate 380
#define tExtrude 381
#define tLevelset 382
#define tAffine 383
#define tBooleanUnion 384
#define tBooleanIntersection 385
#define tBooleanDifference 386
#define tBooleanSection 387
#define tBooleanFragments 388
#define tRecombine 389
#define tSmoother 390
#define tSplit 391
#define tDelete 392
#define tCoherence 393
#define tIntersect 394
#define tMeshAlgorithm 395
#define tReverse 396
#define tLayers 397
#define tScaleLast 398
#define tHole 399
#define tAlias 400
#define tAliasWithOptions 401
#define tCopyOptions 402
#define tQuadTriAddVerts 403
#define tQuadTriNoNewVerts 404
#define tQuadTriSngl 405
#define tQuadTriDbl 406
#define tRecombLaterals 407
#define tTransfQuadTri 408
#define tText2D 409
#define tText3D 410
#define tInterpolationScheme 411
#define tTime 412
#define tCombine 413
#define tBSpline 414
#define tBezier 415
#define tNurbs 416
#define tNurbsOrder 417
#define tNurbsKnots 418
#define tColor 419
#define tColorTable 420
#define tFor 421
#define tIn 422
#define tEndFor 423
#define tIf 424
#define tElseIf 425
#define tElse 426
#define tEndIf 427
#define tExit 428
#define tAbort 429
#define tField 430
#define tReturn 431
#define tCall 432
#define tSlide 433
#define tMacro 434
#define tShow 435
#define tHide 436
#define tGetValue 437
#define tGetStringValue 438
#define tGetEnv 439
#define tGetString 440
#define tGetNumber 441
#define tHomology 442
#define tCohomology 443
#define tBetti 444
#define tExists 445
#define tFileExists 446
#define tGMSH_MAJOR_VERSION 447
#define tGMSH_MINOR_VERSION 448
#define tGMSH_PATCH_VERSION 449
#define tGmshExecutableName 450
#define tSetPartition 451
#define tNameToString 452
#define tStringToName 453
#define tAFFECTDIVIDE 454
#define tAFFECTTIMES 455
#define tAFFECTMINUS 456
#define tAFFECTPLUS 457
#define tOR 458
#define tAND 459
#define tNOTEQUAL 460
#define tEQUAL 461
#define tGREATEROREQUAL 462
#define tLESSOREQUAL 463
#define UNARYPREC 464
#define tMINUSMINUS 465
#define tPLUSPLUS 466




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
#line 652 "Gmsh.tab.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 665 "Gmsh.tab.cpp"

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
#define YYLAST   13486

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  232
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  105
/* YYNRULES -- Number of rules.  */
#define YYNRULES  589
/* YYNRULES -- Number of states.  */
#define YYNSTATES  2180

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   466

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   217,     2,   227,     2,   216,     2,     2,
     222,   223,   214,   212,   228,   213,   226,   215,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     208,     2,   209,   203,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   224,     2,   225,   221,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   229,     2,   230,   231,     2,     2,     2,
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
     195,   196,   197,   198,   199,   200,   201,   202,   204,   205,
     206,   207,   210,   211,   218,   219,   220
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
    1110,  1115,  1124,  1137,  1146,  1155,  1163,  1171,  1176,  1185,
    1194,  1200,  1212,  1218,  1228,  1238,  1243,  1253,  1263,  1265,
    1267,  1268,  1271,  1278,  1285,  1292,  1299,  1308,  1319,  1334,
    1351,  1364,  1379,  1394,  1409,  1424,  1433,  1442,  1449,  1454,
    1461,  1468,  1472,  1477,  1483,  1490,  1496,  1500,  1504,  1509,
    1515,  1520,  1526,  1530,  1536,  1544,  1552,  1556,  1564,  1568,
    1571,  1574,  1577,  1580,  1583,  1599,  1602,  1605,  1608,  1611,
    1614,  1631,  1643,  1650,  1659,  1668,  1679,  1681,  1684,  1687,
    1689,  1693,  1697,  1702,  1707,  1709,  1711,  1717,  1729,  1743,
    1744,  1752,  1753,  1767,  1768,  1784,  1785,  1792,  1801,  1810,
    1819,  1832,  1845,  1858,  1873,  1888,  1903,  1904,  1917,  1918,
    1931,  1932,  1945,  1946,  1963,  1964,  1981,  1982,  1999,  2000,
    2019,  2020,  2039,  2040,  2059,  2061,  2064,  2070,  2078,  2088,
    2091,  2094,  2098,  2101,  2105,  2108,  2112,  2115,  2119,  2122,
    2126,  2136,  2143,  2145,  2147,  2149,  2151,  2153,  2154,  2157,
    2161,  2171,  2176,  2191,  2192,  2196,  2197,  2199,  2200,  2203,
    2204,  2207,  2208,  2211,  2219,  2226,  2235,  2241,  2245,  2254,
    2260,  2265,  2272,  2284,  2296,  2315,  2334,  2347,  2360,  2373,
    2384,  2395,  2406,  2417,  2428,  2433,  2438,  2443,  2448,  2453,
    2456,  2460,  2467,  2469,  2471,  2473,  2476,  2482,  2490,  2501,
    2503,  2507,  2510,  2513,  2516,  2520,  2524,  2528,  2532,  2536,
    2540,  2544,  2548,  2552,  2556,  2560,  2564,  2568,  2572,  2578,
    2583,  2588,  2593,  2598,  2603,  2608,  2613,  2618,  2623,  2628,
    2635,  2640,  2645,  2650,  2655,  2660,  2665,  2670,  2677,  2684,
    2691,  2696,  2698,  2700,  2702,  2704,  2706,  2708,  2710,  2712,
    2714,  2716,  2718,  2719,  2726,  2731,  2738,  2740,  2745,  2750,
    2755,  2760,  2765,  2770,  2775,  2778,  2784,  2790,  2796,  2802,
    2806,  2813,  2818,  2826,  2833,  2840,  2847,  2852,  2859,  2864,
    2866,  2869,  2872,  2876,  2880,  2892,  2902,  2910,  2918,  2920,
    2924,  2926,  2928,  2931,  2935,  2940,  2946,  2948,  2950,  2953,
    2957,  2961,  2967,  2972,  2975,  2978,  2981,  2984,  2988,  2992,
    2996,  3000,  3006,  3012,  3018,  3024,  3041,  3058,  3075,  3092,
    3094,  3096,  3098,  3102,  3106,  3111,  3116,  3121,  3128,  3135,
    3142,  3149,  3158,  3167,  3172,  3187,  3189,  3191,  3195,  3199,
    3209,  3217,  3219,  3225,  3229,  3236,  3238,  3242,  3244,  3246,
    3251,  3256,  3261,  3266,  3270,  3277,  3279,  3284,  3286,  3288,
    3290,  3295,  3302,  3307,  3314,  3319,  3324,  3329,  3338,  3343,
    3348,  3353,  3358,  3367,  3376,  3383,  3388,  3395,  3400,  3402,
    3407,  3412,  3413,  3420,  3422,  3426,  3432,  3438,  3440,  3442
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     233,     0,    -1,   234,    -1,     1,     6,    -1,    -1,   234,
     235,    -1,   238,    -1,   237,    -1,   258,    -1,   277,    -1,
     278,    -1,   282,    -1,   283,    -1,   284,    -1,   285,    -1,
     289,    -1,   307,    -1,   308,    -1,   314,    -1,   315,    -1,
     288,    -1,   287,    -1,   286,    -1,   281,    -1,   317,    -1,
     209,    -1,   209,   209,    -1,    42,   222,   331,   223,     6,
      -1,    43,   222,   331,   223,     6,    -1,    42,   222,   331,
     223,   236,   331,     6,    -1,    42,   222,   331,   228,   327,
     223,     6,    -1,    43,   222,   331,   228,   327,   223,     6,
      -1,    42,   222,   331,   228,   327,   223,   236,   331,     6,
      -1,     4,   331,   229,   239,   230,     6,    -1,   145,     4,
     224,   318,   225,     6,    -1,   146,     4,   224,   318,   225,
       6,    -1,   147,     4,   224,   318,   228,   318,   225,     6,
      -1,    -1,   239,   242,    -1,   239,   246,    -1,   239,   249,
      -1,   239,   251,    -1,   239,   252,    -1,   318,    -1,   240,
     228,   318,    -1,   318,    -1,   241,   228,   318,    -1,    -1,
      -1,     4,   243,   222,   240,   223,   244,   229,   241,   230,
       6,    -1,   331,    -1,   245,   228,   331,    -1,    -1,   154,
     222,   318,   228,   318,   228,   318,   223,   247,   229,   245,
     230,     6,    -1,   331,    -1,   248,   228,   331,    -1,    -1,
     155,   222,   318,   228,   318,   228,   318,   228,   318,   223,
     250,   229,   248,   230,     6,    -1,   156,   229,   323,   230,
     229,   323,   230,     6,    -1,   156,   229,   323,   230,   229,
     323,   230,   229,   323,   230,   229,   323,   230,     6,    -1,
      -1,   157,   253,   229,   241,   230,     6,    -1,     7,    -1,
     202,    -1,   201,    -1,   200,    -1,   199,    -1,   220,    -1,
     219,    -1,   222,    -1,   224,    -1,   223,    -1,   225,    -1,
      78,   224,   260,   225,     6,    -1,    79,   224,   265,   225,
       6,    -1,    82,   256,   332,   228,   318,   257,     6,    -1,
      83,   256,   336,   228,   332,   257,     6,    -1,   336,   254,
     324,     6,    -1,   336,   255,     6,    -1,     4,   224,   225,
     254,   324,     6,    -1,   335,   224,   225,   254,   324,     6,
      -1,     4,   224,   318,   225,   254,   318,     6,    -1,   335,
     224,   318,   225,   254,   318,     6,    -1,     4,   224,   318,
     225,   255,     6,    -1,   335,   224,   318,   225,   255,     6,
      -1,     4,   256,   229,   327,   230,   257,   254,   324,     6,
      -1,   335,   256,   229,   327,   230,   257,   254,   324,     6,
      -1,     4,   222,   223,   254,   324,     6,    -1,   335,   222,
     223,   254,   324,     6,    -1,     4,   222,   318,   223,   254,
     318,     6,    -1,   335,   222,   318,   223,   254,   318,     6,
      -1,     4,   222,   318,   223,   255,     6,    -1,   335,   222,
     318,   223,   255,     6,    -1,   336,     7,   332,     6,    -1,
       4,   224,   225,     7,    44,   256,   257,     6,    -1,   335,
     224,   225,     7,    44,   256,   257,     6,    -1,     4,   224,
     225,     7,    44,   256,   334,   257,     6,    -1,   335,   224,
     225,     7,    44,   256,   334,   257,     6,    -1,     4,   224,
     225,   202,    44,   256,   334,   257,     6,    -1,   335,   224,
     225,   202,    44,   256,   334,   257,     6,    -1,     4,   222,
     223,     7,    44,   256,   257,     6,    -1,   335,   222,   223,
       7,    44,   256,   257,     6,    -1,     4,   222,   223,     7,
      44,   256,   334,   257,     6,    -1,   335,   222,   223,     7,
      44,   256,   334,   257,     6,    -1,     4,   222,   223,   202,
      44,   256,   334,   257,     6,    -1,   335,   222,   223,   202,
      44,   256,   334,   257,     6,    -1,     4,   226,     4,     7,
     332,     6,    -1,     4,   224,   318,   225,   226,     4,     7,
     332,     6,    -1,     4,   226,     4,   254,   318,     6,    -1,
       4,   224,   318,   225,   226,     4,   254,   318,     6,    -1,
       4,   226,     4,   255,     6,    -1,     4,   224,   318,   225,
     226,     4,   255,     6,    -1,     4,   226,   164,   226,     4,
       7,   328,     6,    -1,     4,   224,   318,   225,   226,   164,
     226,     4,     7,   328,     6,    -1,     4,   226,   165,     7,
     329,     6,    -1,     4,   224,   318,   225,   226,   165,     7,
     329,     6,    -1,     4,   175,     7,   318,     6,    -1,   175,
     224,   318,   225,     7,     4,     6,    -1,   175,   224,   318,
     225,   226,     4,     7,   318,     6,    -1,   175,   224,   318,
     225,   226,     4,     7,   332,     6,    -1,   175,   224,   318,
     225,   226,     4,     7,   229,   327,   230,     6,    -1,   175,
     224,   318,   225,   226,     4,     6,    -1,   119,   222,     4,
     223,   226,     4,     7,   318,     6,    -1,   119,   222,     4,
     223,   226,     4,     7,   332,     6,    -1,    -1,   228,    -1,
      -1,   260,   259,   336,    -1,   260,   259,   336,     7,   318,
      -1,    -1,   260,   259,   336,     7,   229,   324,   261,   267,
     230,    -1,    -1,   260,   259,   336,   224,   225,     7,   229,
     324,   262,   267,   230,    -1,    -1,   260,   259,   336,   222,
     223,     7,   229,   324,   263,   267,   230,    -1,   260,   259,
     336,     7,   332,    -1,    -1,   260,   259,   336,     7,   229,
     332,   264,   269,   230,    -1,    -1,   265,   259,   331,    -1,
     318,     7,   332,    -1,   266,   228,   318,     7,   332,    -1,
     326,     7,   336,   222,   223,    -1,    -1,   267,   268,    -1,
     228,     4,   324,    -1,   228,     4,   229,   266,   230,    -1,
     228,     4,   332,    -1,    -1,   269,   270,    -1,   228,     4,
     318,    -1,   228,     4,   332,    -1,   228,   179,   332,    -1,
     228,     4,   229,   334,   230,    -1,   318,    -1,   332,    -1,
     332,   228,   318,    -1,   318,    -1,   332,    -1,   332,   228,
     318,    -1,   318,    -1,   332,    -1,   332,   228,   318,    -1,
     318,    -1,   332,    -1,   332,   228,   318,    -1,    -1,   167,
      88,   229,   318,   230,    -1,    -1,   111,   321,    -1,   109,
     222,   331,   223,     6,    -1,    84,   222,   318,   223,     7,
     321,     6,    -1,   115,    84,   222,   271,   223,   254,   324,
       6,    -1,   102,   103,   324,     7,   318,     6,    -1,    87,
     222,   318,   223,     7,   324,     6,    -1,   120,    87,   324,
       6,    -1,    91,   222,   318,   223,     7,   324,     6,    -1,
      85,   222,   318,   223,     7,   324,   276,     6,    -1,    86,
     222,   318,   223,     7,   324,   276,     6,    -1,   159,   222,
     318,   223,     7,   324,     6,    -1,   160,   222,   318,   223,
       7,   324,     6,    -1,   161,   222,   318,   223,     7,   324,
     163,   324,   162,   318,     6,    -1,    87,     4,   222,   318,
     223,     7,   324,     6,    -1,   116,    87,   324,     6,    -1,
     116,    87,   222,   318,   223,     7,   324,     6,    -1,   115,
      87,   222,   272,   223,   254,   324,     6,    -1,   111,    90,
     222,   318,   223,     7,   324,     6,    -1,   112,    90,   222,
     318,   223,     7,   324,   275,     6,    -1,    12,    13,     6,
      -1,    13,    90,   318,     6,    -1,   104,    90,   222,   318,
     223,     7,     5,     5,     5,     6,    -1,    88,   222,   318,
     223,     7,   324,     6,    -1,    89,   222,   318,   223,     7,
     324,     6,    -1,    93,   222,   318,   223,     7,   324,     6,
      -1,    96,   222,   318,   223,     7,   324,     6,    -1,   100,
     222,   318,   223,     7,   324,     6,    -1,   101,   222,   318,
     223,     7,   324,     6,    -1,    94,   222,   318,   223,     7,
     324,     6,    -1,    95,   222,   318,   223,     7,   324,     6,
      -1,    90,     4,   222,   318,   223,     7,   324,     6,    -1,
     116,    90,   324,     6,    -1,   116,    90,   222,   318,   223,
       7,   324,     6,    -1,   116,    90,   222,   318,   223,     7,
     324,     4,   229,   323,   230,     6,    -1,   115,    90,   222,
     273,   223,   254,   324,     6,    -1,   114,    92,   222,   318,
     223,     7,   324,     6,    -1,    92,   222,   318,   223,     7,
     324,     6,    -1,   110,   222,   318,   223,     7,   324,     6,
      -1,   116,    92,   324,     6,    -1,   116,    92,   222,   318,
     223,     7,   324,     6,    -1,   115,    92,   222,   274,   223,
     254,   324,     6,    -1,   123,   321,   229,   279,   230,    -1,
     122,   229,   321,   228,   321,   228,   318,   230,   229,   279,
     230,    -1,   124,   321,   229,   279,   230,    -1,   125,   229,
     321,   228,   318,   230,   229,   279,   230,    -1,   125,   229,
     321,   228,   321,   230,   229,   279,   230,    -1,     4,   229,
     279,   230,    -1,   139,    87,   229,   327,   230,    90,   229,
     318,   230,    -1,   136,    87,   222,   318,   223,   229,   327,
     230,     6,    -1,   280,    -1,   278,    -1,    -1,   280,   277,
      -1,   280,    84,   229,   327,   230,     6,    -1,   280,    87,
     229,   327,   230,     6,    -1,   280,    90,   229,   327,   230,
       6,    -1,   280,    92,   229,   327,   230,     6,    -1,   127,
     111,   222,   318,   223,     7,   324,     6,    -1,   127,    84,
     222,   318,   223,     7,   229,   323,   230,     6,    -1,   127,
     111,   222,   318,   223,     7,   229,   321,   228,   321,   228,
     327,   230,     6,    -1,   127,   111,   222,   318,   223,     7,
     229,   321,   228,   321,   228,   321,   228,   327,   230,     6,
      -1,   127,    88,   222,   318,   223,     7,   229,   321,   228,
     327,   230,     6,    -1,   127,    94,   222,   318,   223,     7,
     229,   321,   228,   321,   228,   327,   230,     6,    -1,   127,
      95,   222,   318,   223,     7,   229,   321,   228,   321,   228,
     327,   230,     6,    -1,   127,    97,   222,   318,   223,     7,
     229,   321,   228,   321,   228,   327,   230,     6,    -1,   127,
      98,   222,   318,   223,     7,   229,   321,   228,   321,   228,
     327,   230,     6,    -1,   127,     4,   222,   318,   223,     7,
     324,     6,    -1,   127,     4,   222,   318,   223,     7,     5,
       6,    -1,   127,     4,   229,   318,   230,     6,    -1,   137,
     229,   280,   230,    -1,   137,   175,   224,   318,   225,     6,
      -1,   137,     4,   224,   318,   225,     6,    -1,   137,   336,
       6,    -1,   137,     4,     4,     6,    -1,   164,   328,   229,
     280,   230,    -1,   121,   164,   328,   229,   280,   230,    -1,
     196,   318,   229,   280,   230,    -1,   180,     5,     6,    -1,
     181,     5,     6,    -1,   180,   229,   280,   230,    -1,   121,
     180,   229,   280,   230,    -1,   181,   229,   280,   230,    -1,
     121,   181,   229,   280,   230,    -1,     4,   332,     6,    -1,
      71,   222,   334,   223,     6,    -1,     4,     4,   224,   318,
     225,   331,     6,    -1,     4,     4,     4,   224,   318,   225,
       6,    -1,     4,   318,     6,    -1,   119,   222,     4,   223,
     226,     4,     6,    -1,   158,     4,     6,    -1,   173,     6,
      -1,   174,     6,    -1,    68,     6,    -1,    69,     6,    -1,
      62,     6,    -1,    62,   229,   318,   228,   318,   228,   318,
     228,   318,   228,   318,   228,   318,   230,     6,    -1,    63,
       6,    -1,    64,     6,    -1,    75,     6,    -1,    76,     6,
      -1,   106,     6,    -1,   107,   229,   327,   230,   229,   327,
     230,   229,   323,   230,   229,   318,   228,   318,   230,     6,
      -1,   178,   222,   229,   327,   230,   228,   332,   228,   332,
     223,     6,    -1,   166,   222,   318,     8,   318,   223,    -1,
     166,   222,   318,     8,   318,     8,   318,   223,    -1,   166,
       4,   167,   229,   318,     8,   318,   230,    -1,   166,     4,
     167,   229,   318,     8,   318,     8,   318,   230,    -1,   168,
      -1,   179,     4,    -1,   179,   332,    -1,   176,    -1,   177,
     336,     6,    -1,   177,   332,     6,    -1,   169,   222,   318,
     223,    -1,   170,   222,   318,   223,    -1,   171,    -1,   172,
      -1,   126,   321,   229,   280,   230,    -1,   126,   229,   321,
     228,   321,   228,   318,   230,   229,   280,   230,    -1,   126,
     229,   321,   228,   321,   228,   321,   228,   318,   230,   229,
     280,   230,    -1,    -1,   126,   321,   229,   280,   290,   303,
     230,    -1,    -1,   126,   229,   321,   228,   321,   228,   318,
     230,   229,   280,   291,   303,   230,    -1,    -1,   126,   229,
     321,   228,   321,   228,   321,   228,   318,   230,   229,   280,
     292,   303,   230,    -1,    -1,   126,   229,   280,   293,   303,
     230,    -1,   126,    84,   229,   318,   228,   321,   230,     6,
      -1,   126,    87,   229,   318,   228,   321,   230,     6,    -1,
     126,    90,   229,   318,   228,   321,   230,     6,    -1,   126,
      84,   229,   318,   228,   321,   228,   321,   228,   318,   230,
       6,    -1,   126,    87,   229,   318,   228,   321,   228,   321,
     228,   318,   230,     6,    -1,   126,    90,   229,   318,   228,
     321,   228,   321,   228,   318,   230,     6,    -1,   126,    84,
     229,   318,   228,   321,   228,   321,   228,   321,   228,   318,
     230,     6,    -1,   126,    87,   229,   318,   228,   321,   228,
     321,   228,   321,   228,   318,   230,     6,    -1,   126,    90,
     229,   318,   228,   321,   228,   321,   228,   321,   228,   318,
     230,     6,    -1,    -1,   126,    84,   229,   318,   228,   321,
     230,   294,   229,   303,   230,     6,    -1,    -1,   126,    87,
     229,   318,   228,   321,   230,   295,   229,   303,   230,     6,
      -1,    -1,   126,    90,   229,   318,   228,   321,   230,   296,
     229,   303,   230,     6,    -1,    -1,   126,    84,   229,   318,
     228,   321,   228,   321,   228,   318,   230,   297,   229,   303,
     230,     6,    -1,    -1,   126,    87,   229,   318,   228,   321,
     228,   321,   228,   318,   230,   298,   229,   303,   230,     6,
      -1,    -1,   126,    90,   229,   318,   228,   321,   228,   321,
     228,   318,   230,   299,   229,   303,   230,     6,    -1,    -1,
     126,    84,   229,   318,   228,   321,   228,   321,   228,   321,
     228,   318,   230,   300,   229,   303,   230,     6,    -1,    -1,
     126,    87,   229,   318,   228,   321,   228,   321,   228,   321,
     228,   318,   230,   301,   229,   303,   230,     6,    -1,    -1,
     126,    90,   229,   318,   228,   321,   228,   321,   228,   321,
     228,   318,   230,   302,   229,   303,   230,     6,    -1,   304,
      -1,   303,   304,    -1,   142,   229,   318,   230,     6,    -1,
     142,   229,   324,   228,   324,   230,     6,    -1,   142,   229,
     324,   228,   324,   228,   324,   230,     6,    -1,   143,     6,
      -1,   134,     6,    -1,   134,   318,     6,    -1,   150,     6,
      -1,   150,   152,     6,    -1,   151,     6,    -1,   151,   152,
       6,    -1,   148,     6,    -1,   148,   152,     6,    -1,   149,
       6,    -1,   149,   152,     6,    -1,   144,   222,   318,   223,
       7,   324,   118,   318,     6,    -1,   118,     4,   224,   318,
     225,     6,    -1,   129,    -1,   130,    -1,   131,    -1,   132,
      -1,   133,    -1,    -1,   137,     6,    -1,   137,   318,     6,
      -1,   305,   229,   280,   306,   230,   229,   280,   306,   230,
      -1,    99,   222,   331,   223,    -1,   305,   222,   318,   223,
       7,   229,   280,   306,   230,   229,   280,   306,   230,     6,
      -1,    -1,   118,     4,   318,    -1,    -1,     4,    -1,    -1,
       7,   324,    -1,    -1,     7,   318,    -1,    -1,   128,   324,
      -1,   113,    87,   325,     7,   318,   309,     6,    -1,   113,
      90,   325,   311,   310,     6,    -1,   105,    90,   229,   318,
     230,     7,   324,     6,    -1,   113,    92,   325,   311,     6,
      -1,   153,   325,     6,    -1,   140,    90,   229,   327,   230,
       7,   318,     6,    -1,   134,    90,   325,   312,     6,    -1,
     134,    92,   325,     6,    -1,   135,    90,   324,     7,   318,
       6,    -1,   117,    87,   229,   327,   230,     7,   229,   327,
     230,   313,     6,    -1,   117,    90,   229,   327,   230,     7,
     229,   327,   230,   313,     6,    -1,   117,    87,   229,   327,
     230,     7,   229,   327,   230,   122,   229,   321,   228,   321,
     228,   318,   230,     6,    -1,   117,    90,   229,   327,   230,
       7,   229,   327,   230,   122,   229,   321,   228,   321,   228,
     318,   230,     6,    -1,   117,    87,   229,   327,   230,     7,
     229,   327,   230,   123,   321,     6,    -1,   117,    90,   229,
     327,   230,     7,   229,   327,   230,   123,   321,     6,    -1,
     117,    90,   318,   229,   327,   230,     7,   318,   229,   327,
     230,     6,    -1,    84,   229,   327,   230,   167,    90,   229,
     318,   230,     6,    -1,    87,   229,   327,   230,   167,    90,
     229,   318,   230,     6,    -1,    84,   229,   327,   230,   167,
      92,   229,   318,   230,     6,    -1,    87,   229,   327,   230,
     167,    92,   229,   318,   230,     6,    -1,    90,   229,   327,
     230,   167,    92,   229,   318,   230,     6,    -1,   141,    90,
     325,     6,    -1,   141,    87,   325,     6,    -1,   108,    84,
     325,     6,    -1,   108,    87,   325,     6,    -1,   108,    90,
     325,     6,    -1,   138,     6,    -1,   138,     4,     6,    -1,
     138,    84,   229,   327,   230,     6,    -1,   187,    -1,   188,
      -1,   189,    -1,   316,     6,    -1,   316,   229,   324,   230,
       6,    -1,   316,   229,   324,   228,   324,   230,     6,    -1,
     316,   222,   324,   223,   229,   324,   228,   324,   230,     6,
      -1,   319,    -1,   222,   318,   223,    -1,   213,   318,    -1,
     212,   318,    -1,   217,   318,    -1,   318,   213,   318,    -1,
     318,   212,   318,    -1,   318,   214,   318,    -1,   318,   215,
     318,    -1,   318,   216,   318,    -1,   318,   221,   318,    -1,
     318,   208,   318,    -1,   318,   209,   318,    -1,   318,   211,
     318,    -1,   318,   210,   318,    -1,   318,   207,   318,    -1,
     318,   206,   318,    -1,   318,   205,   318,    -1,   318,   204,
     318,    -1,   318,   203,   318,     8,   318,    -1,    15,   256,
     318,   257,    -1,    16,   256,   318,   257,    -1,    17,   256,
     318,   257,    -1,    18,   256,   318,   257,    -1,    19,   256,
     318,   257,    -1,    20,   256,   318,   257,    -1,    21,   256,
     318,   257,    -1,    22,   256,   318,   257,    -1,    23,   256,
     318,   257,    -1,    25,   256,   318,   257,    -1,    26,   256,
     318,   228,   318,   257,    -1,    27,   256,   318,   257,    -1,
      28,   256,   318,   257,    -1,    29,   256,   318,   257,    -1,
      30,   256,   318,   257,    -1,    31,   256,   318,   257,    -1,
      32,   256,   318,   257,    -1,    33,   256,   318,   257,    -1,
      34,   256,   318,   228,   318,   257,    -1,    35,   256,   318,
     228,   318,   257,    -1,    36,   256,   318,   228,   318,   257,
      -1,    24,   256,   318,   257,    -1,     3,    -1,     9,    -1,
      14,    -1,    10,    -1,    11,    -1,   192,    -1,   193,    -1,
     194,    -1,    72,    -1,    73,    -1,    74,    -1,    -1,    80,
     256,   318,   320,   267,   257,    -1,   186,   256,   331,   257,
      -1,   186,   256,   331,   228,   318,   257,    -1,   336,    -1,
       4,   224,   318,   225,    -1,     4,   222,   318,   223,    -1,
     335,   224,   318,   225,    -1,   335,   222,   318,   223,    -1,
     190,   222,   336,   223,    -1,   191,   222,   332,   223,    -1,
     227,   336,   256,   257,    -1,   336,   255,    -1,     4,   224,
     318,   225,   255,    -1,     4,   222,   318,   223,   255,    -1,
     335,   224,   318,   225,   255,    -1,   335,   222,   318,   223,
     255,    -1,     4,   226,     4,    -1,     4,   224,   318,   225,
     226,     4,    -1,     4,   226,     4,   255,    -1,     4,   224,
     318,   225,   226,     4,   255,    -1,   182,   222,   331,   228,
     318,   223,    -1,    54,   222,   324,   228,   324,   223,    -1,
      55,   256,   331,   228,   331,   257,    -1,    53,   256,   331,
     257,    -1,    56,   256,   331,   228,   331,   257,    -1,    61,
     222,   334,   223,    -1,   322,    -1,   213,   321,    -1,   212,
     321,    -1,   321,   213,   321,    -1,   321,   212,   321,    -1,
     229,   318,   228,   318,   228,   318,   228,   318,   228,   318,
     230,    -1,   229,   318,   228,   318,   228,   318,   228,   318,
     230,    -1,   229,   318,   228,   318,   228,   318,   230,    -1,
     222,   318,   228,   318,   228,   318,   223,    -1,   324,    -1,
     323,   228,   324,    -1,   318,    -1,   326,    -1,   229,   230,
      -1,   229,   327,   230,    -1,   213,   229,   327,   230,    -1,
     318,   214,   229,   327,   230,    -1,   324,    -1,     5,    -1,
     213,   326,    -1,   318,   214,   326,    -1,   318,     8,   318,
      -1,   318,     8,   318,     8,   318,    -1,    84,   229,   318,
     230,    -1,    84,     5,    -1,    87,     5,    -1,    90,     5,
      -1,    92,     5,    -1,   115,    84,     5,    -1,   115,    87,
       5,    -1,   115,    90,     5,    -1,   115,    92,     5,    -1,
     115,    84,   229,   327,   230,    -1,   115,    87,   229,   327,
     230,    -1,   115,    90,   229,   327,   230,    -1,   115,    92,
     229,   327,   230,    -1,    84,   167,    62,   229,   318,   228,
     318,   228,   318,   228,   318,   228,   318,   228,   318,   230,
      -1,    87,   167,    62,   229,   318,   228,   318,   228,   318,
     228,   318,   228,   318,   228,   318,   230,    -1,    90,   167,
      62,   229,   318,   228,   318,   228,   318,   228,   318,   228,
     318,   228,   318,   230,    -1,    92,   167,    62,   229,   318,
     228,   318,   228,   318,   228,   318,   228,   318,   228,   318,
     230,    -1,   278,    -1,   289,    -1,   307,    -1,     4,   256,
     257,    -1,   335,   256,   257,    -1,    37,   224,   336,   225,
      -1,    37,   224,   326,   225,    -1,    37,   222,   326,   223,
      -1,    37,   224,   229,   327,   230,   225,    -1,    37,   222,
     229,   327,   230,   223,    -1,     4,   256,   229,   327,   230,
     257,    -1,   335,   256,   229,   327,   230,   257,    -1,    38,
     256,   318,   228,   318,   228,   318,   257,    -1,    39,   256,
     318,   228,   318,   228,   318,   257,    -1,    40,   256,   331,
     257,    -1,    41,   256,   318,   228,   318,   228,   318,   228,
     318,   228,   318,   228,   318,   257,    -1,   318,    -1,   326,
      -1,   327,   228,   318,    -1,   327,   228,   326,    -1,   229,
     318,   228,   318,   228,   318,   228,   318,   230,    -1,   229,
     318,   228,   318,   228,   318,   230,    -1,   336,    -1,     4,
     226,   164,   226,     4,    -1,   229,   330,   230,    -1,     4,
     224,   318,   225,   226,   165,    -1,   328,    -1,   330,   228,
     328,    -1,   332,    -1,   336,    -1,     4,   224,   318,   225,
      -1,   335,   224,   318,   225,    -1,     4,   222,   318,   223,
      -1,   335,   222,   318,   223,    -1,     4,   226,     4,    -1,
       4,   224,   318,   225,   226,     4,    -1,     5,    -1,   197,
     224,   336,   225,    -1,    65,    -1,   195,    -1,    70,    -1,
     184,   222,   331,   223,    -1,   183,   222,   331,   228,   331,
     223,    -1,   185,   256,   331,   257,    -1,   185,   256,   331,
     228,   331,   257,    -1,    46,   256,   334,   257,    -1,    47,
     222,   331,   223,    -1,    48,   222,   331,   223,    -1,    49,
     222,   331,   228,   331,   228,   331,   223,    -1,    44,   256,
     334,   257,    -1,    58,   256,   331,   257,    -1,    59,   256,
     331,   257,    -1,    60,   256,   331,   257,    -1,    57,   256,
     318,   228,   331,   228,   331,   257,    -1,    52,   256,   331,
     228,   318,   228,   318,   257,    -1,    52,   256,   331,   228,
     318,   257,    -1,    45,   256,   331,   257,    -1,    45,   256,
     331,   228,   327,   257,    -1,    66,   256,   331,   257,    -1,
      67,    -1,    51,   256,   331,   257,    -1,    50,   256,   331,
     257,    -1,    -1,    81,   256,   332,   333,   269,   257,    -1,
     331,    -1,   334,   228,   331,    -1,     4,   231,   229,   318,
     230,    -1,   335,   231,   229,   318,   230,    -1,     4,    -1,
     335,    -1,   198,   224,   331,   225,    -1
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
    2229,  2236,  2278,  2304,  2328,  2352,  2377,  2400,  2425,  2453,
    2480,  2484,  2503,  2537,  2584,  2602,  2629,  2647,  2651,  2667,
    2715,  2732,  2750,  2760,  2770,  2780,  2843,  2854,  2870,  2871,
    2876,  2879,  2883,  2912,  2941,  2970,  3004,  3026,  3052,  3074,
    3097,  3118,  3174,  3198,  3223,  3249,  3362,  3381,  3424,  3445,
    3451,  3466,  3494,  3511,  3520,  3534,  3548,  3554,  3560,  3569,
    3578,  3587,  3601,  3663,  3681,  3698,  3713,  3742,  3754,  3778,
    3782,  3787,  3795,  3800,  3806,  3811,  3817,  3825,  3829,  3833,
    3838,  3898,  3914,  3931,  3948,  3970,  3992,  4027,  4035,  4043,
    4049,  4056,  4063,  4083,  4109,  4121,  4133,  4163,  4194,  4203,
    4202,  4217,  4216,  4231,  4230,  4245,  4244,  4258,  4265,  4272,
    4279,  4286,  4293,  4300,  4307,  4314,  4322,  4321,  4335,  4334,
    4348,  4347,  4361,  4360,  4374,  4373,  4387,  4386,  4400,  4399,
    4413,  4412,  4426,  4425,  4442,  4445,  4451,  4463,  4483,  4507,
    4511,  4515,  4519,  4523,  4527,  4533,  4539,  4543,  4547,  4551,
    4555,  4574,  4587,  4588,  4589,  4590,  4591,  4595,  4596,  4597,
    4600,  4634,  4660,  4684,  4687,  4703,  4706,  4723,  4726,  4732,
    4735,  4742,  4745,  4752,  4808,  4878,  4883,  4950,  4986,  4994,
    5037,  5076,  5096,  5128,  5155,  5181,  5207,  5233,  5259,  5281,
    5309,  5337,  5365,  5393,  5421,  5460,  5499,  5520,  5541,  5568,
    5572,  5582,  5617,  5618,  5619,  5623,  5629,  5641,  5659,  5687,
    5688,  5689,  5690,  5691,  5692,  5693,  5694,  5695,  5702,  5703,
    5704,  5705,  5706,  5707,  5708,  5709,  5710,  5711,  5712,  5713,
    5714,  5715,  5716,  5717,  5718,  5719,  5720,  5721,  5722,  5723,
    5724,  5725,  5726,  5727,  5728,  5729,  5730,  5731,  5732,  5733,
    5734,  5743,  5744,  5745,  5746,  5747,  5748,  5749,  5750,  5751,
    5752,  5753,  5758,  5757,  5765,  5770,  5775,  5792,  5810,  5828,
    5846,  5864,  5869,  5875,  5890,  5909,  5929,  5949,  5969,  5992,
    5997,  6002,  6012,  6022,  6027,  6038,  6047,  6052,  6057,  6084,
    6088,  6092,  6096,  6100,  6107,  6111,  6115,  6119,  6126,  6131,
    6138,  6143,  6147,  6152,  6156,  6164,  6175,  6179,  6191,  6199,
    6207,  6214,  6224,  6253,  6257,  6261,  6265,  6269,  6273,  6277,
    6281,  6285,  6314,  6343,  6372,  6401,  6414,  6427,  6440,  6453,
    6463,  6473,  6483,  6495,  6508,  6520,  6524,  6528,  6532,  6536,
    6554,  6572,  6580,  6588,  6617,  6630,  6635,  6639,  6643,  6655,
    6659,  6671,  6688,  6698,  6702,  6717,  6722,  6729,  6733,  6746,
    6760,  6774,  6788,  6802,  6810,  6821,  6825,  6829,  6837,  6843,
    6849,  6857,  6865,  6872,  6880,  6895,  6909,  6923,  6935,  6951,
    6960,  6969,  6979,  6990,  6998,  7006,  7010,  7029,  7036,  7042,
    7049,  7057,  7056,  7069,  7074,  7080,  7089,  7102,  7105,  7109
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
  "tThruSections", "tPlane", "tRuled", "tTransfinite", "tComplex",
  "tPhysical", "tCompound", "tPeriodic", "tUsing", "tPlugin",
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
     455,   456,   457,    63,   458,   459,   460,   461,    60,    62,
     462,   463,    43,    45,    42,    47,    37,    33,   464,   465,
     466,    94,    40,    41,    91,    93,    46,    35,    44,   123,
     125,   126
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   232,   233,   233,   234,   234,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   236,   236,   237,   237,   237,
     237,   237,   237,   238,   238,   238,   238,   239,   239,   239,
     239,   239,   239,   240,   240,   241,   241,   243,   244,   242,
     245,   245,   247,   246,   248,   248,   250,   249,   251,   251,
     253,   252,   254,   254,   254,   254,   254,   255,   255,   256,
     256,   257,   257,   258,   258,   258,   258,   258,   258,   258,
     258,   258,   258,   258,   258,   258,   258,   258,   258,   258,
     258,   258,   258,   258,   258,   258,   258,   258,   258,   258,
     258,   258,   258,   258,   258,   258,   258,   258,   258,   258,
     258,   258,   258,   258,   258,   258,   258,   258,   258,   258,
     258,   258,   258,   258,   259,   259,   260,   260,   260,   261,
     260,   262,   260,   263,   260,   260,   264,   260,   265,   265,
     266,   266,   266,   267,   267,   268,   268,   268,   269,   269,
     270,   270,   270,   270,   271,   271,   271,   272,   272,   272,
     273,   273,   273,   274,   274,   274,   275,   275,   276,   276,
     277,   277,   277,   277,   277,   277,   277,   277,   277,   277,
     277,   277,   277,   277,   277,   277,   277,   277,   277,   277,
     277,   277,   277,   277,   277,   277,   277,   277,   277,   277,
     277,   277,   277,   277,   277,   277,   277,   277,   277,   277,
     278,   278,   278,   278,   278,   278,   278,   278,   279,   279,
     280,   280,   280,   280,   280,   280,   281,   281,   281,   281,
     281,   281,   281,   281,   281,   281,   281,   281,   282,   282,
     282,   282,   282,   283,   283,   284,   285,   285,   285,   285,
     285,   285,   286,   286,   286,   286,   286,   286,   286,   286,
     286,   286,   286,   286,   286,   286,   286,   286,   286,   286,
     286,   287,   288,   288,   288,   288,   288,   288,   288,   288,
     288,   288,   288,   288,   288,   288,   289,   289,   289,   290,
     289,   291,   289,   292,   289,   293,   289,   289,   289,   289,
     289,   289,   289,   289,   289,   289,   294,   289,   295,   289,
     296,   289,   297,   289,   298,   289,   299,   289,   300,   289,
     301,   289,   302,   289,   303,   303,   304,   304,   304,   304,
     304,   304,   304,   304,   304,   304,   304,   304,   304,   304,
     304,   304,   305,   305,   305,   305,   305,   306,   306,   306,
     307,   307,   308,   309,   309,   310,   310,   311,   311,   312,
     312,   313,   313,   314,   314,   314,   314,   314,   314,   314,
     314,   314,   314,   314,   314,   314,   314,   314,   314,   314,
     314,   314,   314,   314,   314,   314,   314,   314,   314,   315,
     315,   315,   316,   316,   316,   317,   317,   317,   317,   318,
     318,   318,   318,   318,   318,   318,   318,   318,   318,   318,
     318,   318,   318,   318,   318,   318,   318,   318,   318,   318,
     318,   318,   318,   318,   318,   318,   318,   318,   318,   318,
     318,   318,   318,   318,   318,   318,   318,   318,   318,   318,
     318,   319,   319,   319,   319,   319,   319,   319,   319,   319,
     319,   319,   320,   319,   319,   319,   319,   319,   319,   319,
     319,   319,   319,   319,   319,   319,   319,   319,   319,   319,
     319,   319,   319,   319,   319,   319,   319,   319,   319,   321,
     321,   321,   321,   321,   322,   322,   322,   322,   323,   323,
     324,   324,   324,   324,   324,   324,   325,   325,   326,   326,
     326,   326,   326,   326,   326,   326,   326,   326,   326,   326,
     326,   326,   326,   326,   326,   326,   326,   326,   326,   326,
     326,   326,   326,   326,   326,   326,   326,   326,   326,   326,
     326,   326,   326,   326,   326,   327,   327,   327,   327,   328,
     328,   328,   328,   329,   329,   330,   330,   331,   331,   331,
     331,   331,   331,   331,   331,   332,   332,   332,   332,   332,
     332,   332,   332,   332,   332,   332,   332,   332,   332,   332,
     332,   332,   332,   332,   332,   332,   332,   332,   332,   332,
     332,   333,   332,   334,   334,   335,   335,   336,   336,   336
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
      10,     7,     7,     7,     7,     7,     7,     7,     7,     8,
       4,     8,    12,     8,     8,     7,     7,     4,     8,     8,
       5,    11,     5,     9,     9,     4,     9,     9,     1,     1,
       0,     2,     6,     6,     6,     6,     8,    10,    14,    16,
      12,    14,    14,    14,    14,     8,     8,     6,     4,     6,
       6,     3,     4,     5,     6,     5,     3,     3,     4,     5,
       4,     5,     3,     5,     7,     7,     3,     7,     3,     2,
       2,     2,     2,     2,    15,     2,     2,     2,     2,     2,
      16,    11,     6,     8,     8,    10,     1,     2,     2,     1,
       3,     3,     4,     4,     1,     1,     5,    11,    13,     0,
       7,     0,    13,     0,    15,     0,     6,     8,     8,     8,
      12,    12,    12,    14,    14,    14,     0,    12,     0,    12,
       0,    12,     0,    16,     0,    16,     0,    16,     0,    18,
       0,    18,     0,    18,     1,     2,     5,     7,     9,     2,
       2,     3,     2,     3,     2,     3,     2,     3,     2,     3,
       9,     6,     1,     1,     1,     1,     1,     0,     2,     3,
       9,     4,    14,     0,     3,     0,     1,     0,     2,     0,
       2,     0,     2,     7,     6,     8,     5,     3,     8,     5,
       4,     6,    11,    11,    18,    18,    12,    12,    12,    10,
      10,    10,    10,    10,     4,     4,     4,     4,     4,     2,
       3,     6,     1,     1,     1,     2,     5,     7,    10,     1,
       3,     2,     2,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     5,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     6,
       4,     4,     4,     4,     4,     4,     4,     6,     6,     6,
       4,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     6,     4,     6,     1,     4,     4,     4,
       4,     4,     4,     4,     2,     5,     5,     5,     5,     3,
       6,     4,     7,     6,     6,     6,     4,     6,     4,     1,
       2,     2,     3,     3,    11,     9,     7,     7,     1,     3,
       1,     1,     2,     3,     4,     5,     1,     1,     2,     3,
       3,     5,     4,     2,     2,     2,     2,     3,     3,     3,
       3,     5,     5,     5,     5,    16,    16,    16,    16,     1,
       1,     1,     3,     3,     4,     4,     4,     6,     6,     6,
       6,     8,     8,     4,    14,     1,     1,     3,     3,     9,
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
       0,     0,     0,     2,     3,     1,   587,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   342,   343,   344,   345,   346,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   276,     0,     0,   284,
     285,     0,     0,     0,   279,     0,     0,     0,     0,     0,
     392,   393,   394,     0,     0,     5,     7,     6,     8,     9,
      10,    23,    11,    12,    13,    14,    22,    21,    20,    15,
       0,    16,    17,    18,    19,     0,    24,   588,     0,   441,
     587,   555,   442,   444,   445,   443,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   557,     0,   578,   559,
     449,   450,   451,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   446,   447,   448,   558,     0,     0,     0,
       0,    69,    70,     0,     0,   220,     0,     0,     0,   399,
       0,   547,   588,   456,     0,     0,     0,     0,   263,     0,
     265,   266,   261,   262,     0,   267,   268,   126,   138,    69,
      70,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   269,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   479,
       0,     0,     0,     0,     0,   220,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   587,
       0,   220,   588,     0,     0,   389,     0,     0,     0,     0,
       0,     0,     0,     0,   587,   497,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   519,
     520,     0,   521,   490,   496,     0,   491,   588,   456,     0,
       0,     0,     0,   587,     0,     0,   541,     0,     0,     0,
       0,   259,   260,     0,   587,     0,     0,     0,   277,   278,
       0,   220,     0,   220,   587,     0,   588,     0,     0,   220,
     395,     0,     0,    69,    70,     0,     0,    62,    66,    65,
      64,    63,    68,    67,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   402,   401,   403,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   219,     0,   218,     0,     0,   256,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    37,   252,     0,     0,   464,
     188,     0,   587,     0,   547,   588,   548,     0,     0,   583,
       0,   124,   124,     0,     0,     0,     0,   535,   536,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     357,   357,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   220,
     220,     0,   481,   480,     0,     0,     0,     0,   220,   220,
       0,     0,     0,     0,     0,     0,     0,   295,     0,   220,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   359,
       0,     0,     0,     0,     0,     0,     0,   241,   390,     0,
       0,     0,     0,     0,     0,     0,     0,    69,    70,     0,
       0,     0,     0,     0,     0,     0,     0,   503,     0,     0,
     504,     0,   505,     0,   506,     0,     0,     0,     0,     0,
       0,   401,   498,     0,   492,     0,     0,     0,   367,    69,
      70,     0,   258,     0,     0,     0,     0,     0,   220,     0,
       0,     0,     0,     0,   281,   280,     0,   246,     0,   247,
       0,     0,     0,   220,     0,     0,     0,     0,   347,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    78,
       0,     0,     0,   469,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   452,   581,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    62,    63,     0,   400,
      62,    63,     0,     0,    62,     0,     0,     0,     0,     0,
     215,     0,     0,     0,     0,   221,     0,     0,     0,   417,
     416,   415,   414,   410,   411,   413,   412,   405,   404,   406,
     407,   408,   409,     0,     0,     0,   189,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     125,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   351,     0,     0,     0,     0,
       0,     0,   386,   387,   388,     0,     0,     0,     0,     0,
       0,   355,     0,     0,     0,   154,   155,     0,   157,   158,
       0,   160,   161,     0,   163,   164,     0,   183,     0,   200,
       0,   207,     0,     0,     0,     0,   175,   220,     0,     0,
       0,     0,     0,   483,   482,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   289,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   370,     0,     0,   242,
       0,     0,   238,     0,     0,     0,   385,   384,     0,     0,
       0,     0,     0,   469,    71,    72,     0,   522,     0,     0,
       0,     0,     0,   456,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   507,     0,   508,     0,   509,     0,   510,
       0,     0,   400,   493,   500,     0,   406,   499,     0,     0,
       0,   523,     0,     0,     0,     0,     0,     0,     0,     0,
     282,   283,     0,     0,   248,   250,     0,   589,     0,     0,
       0,     0,     0,     0,    62,    63,     0,     0,    62,    63,
       0,     0,     0,     0,    93,    77,     0,   458,   457,   471,
     419,   420,   421,   422,   423,   424,   425,   426,   427,   440,
     428,     0,   430,   431,   432,   433,   434,   435,   436,     0,
       0,     0,   568,     0,   575,   564,   565,   566,     0,   580,
     579,     0,   476,     0,     0,     0,     0,   569,   570,   571,
     478,   577,   143,   148,   116,     0,     0,   560,     0,   562,
       0,   454,   461,   462,   556,     0,     0,     0,    62,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   110,
       0,     0,     0,     0,   463,     0,     0,     0,     0,   585,
       0,     0,    47,     0,     0,     0,    60,     0,    38,    39,
      40,    41,    42,   460,   459,     0,     0,   553,    27,    25,
       0,     0,     0,     0,    28,     0,     0,   253,   584,    73,
     127,    74,   139,     0,     0,     0,   537,   538,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     170,     0,     0,     0,   353,   358,   356,     0,   366,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   400,   400,
     400,     0,     0,     0,     0,     0,   249,   251,     0,     0,
       0,   210,   212,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   324,     0,
     286,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   360,   369,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   458,   457,     0,     0,   526,     0,   525,
     524,     0,     0,   533,     0,     0,   502,     0,     0,     0,
       0,     0,     0,     0,   494,     0,     0,   460,   459,     0,
       0,     0,     0,     0,     0,   243,     0,     0,     0,     0,
       0,   245,     0,   348,     0,     0,     0,     0,   396,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   586,
       0,     0,   466,     0,   465,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    87,     0,    91,     0,     0,
      79,     0,     0,     0,     0,    83,   106,   108,     0,     0,
     545,     0,   114,     0,     0,     0,     0,     0,   418,     0,
       0,     0,     0,     0,    33,   468,   467,   551,   549,    26,
       0,     0,   552,   550,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   168,   168,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   173,     0,     0,     0,     0,     0,     0,     0,
       0,   364,     0,     0,   156,     0,   159,     0,   162,     0,
     165,     0,     0,     0,     0,     0,     0,     0,   244,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   330,     0,
       0,   329,     0,   336,     0,   338,     0,   332,     0,   334,
       0,   296,   325,     0,     0,     0,   237,     0,     0,     0,
       0,     0,     0,     0,   371,     0,   240,   239,   391,     0,
       0,    34,    35,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   511,   512,   513,   514,   501,
     495,     0,     0,     0,     0,   542,     0,     0,     0,   272,
       0,     0,     0,   220,   349,   220,     0,     0,     0,     0,
      88,     0,    92,     0,     0,    80,     0,    84,     0,   255,
     470,   254,   429,   437,   438,   439,   576,     0,     0,   574,
     474,   475,   477,     0,     0,   453,   144,     0,   582,   149,
     473,   561,   563,   455,     0,     0,     0,    89,     0,     0,
       0,    62,     0,     0,     0,     0,    81,     0,     0,     0,
     543,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     488,     0,     0,    29,    30,     0,    31,     0,     0,   128,
     135,     0,     0,    75,    76,   171,     0,     0,     0,     0,
       0,     0,   174,     0,     0,   191,   192,     0,     0,   176,
     205,   193,   197,   198,   194,   195,   196,     0,     0,     0,
     206,     0,   166,     0,   363,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   257,     0,     0,     0,
       0,   220,   220,     0,   306,     0,   308,     0,   310,     0,
     331,   490,     0,     0,   337,   339,   333,   335,     0,     0,
     290,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   470,   529,   528,   527,     0,
       0,     0,     0,     0,     0,     0,   530,   179,   180,     0,
       0,     0,     0,   117,   121,     0,     0,   347,   347,     0,
     397,     0,     0,     0,    90,     0,     0,     0,    82,     0,
     472,     0,     0,     0,     0,     0,     0,   100,     0,     0,
      94,     0,     0,     0,     0,   111,     0,     0,   112,     0,
     546,   222,   223,   224,   225,     0,     0,    43,     0,     0,
       0,     0,     0,    45,   554,     0,     0,   129,   136,     0,
       0,     0,     0,   169,   177,   178,   182,     0,     0,   199,
       0,     0,   365,     0,   186,     0,     0,   354,   204,   172,
     185,   203,   209,   184,     0,   201,   208,     0,     0,     0,
       0,     0,     0,   487,     0,   486,     0,     0,     0,   297,
       0,     0,   298,     0,     0,   299,     0,     0,     0,     0,
       0,     0,     0,   236,   235,     0,     0,     0,     0,     0,
       0,     0,     0,   226,     0,     0,   368,    36,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   540,     0,   274,
     273,     0,     0,     0,     0,     0,     0,     0,   101,     0,
       0,    95,     0,     0,     0,   567,   573,   572,     0,   145,
     147,     0,   150,   151,   152,   102,   104,    96,    98,   107,
     109,     0,   115,     0,    85,    48,     0,     0,     0,   489,
       0,     0,     0,    32,     0,   143,   148,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   187,     0,   361,
     361,     0,   122,   123,   220,     0,   213,   214,     0,     0,
       0,     0,     0,     0,     0,   326,     0,     0,   220,     0,
       0,     0,     0,     0,     0,     0,     0,   217,   216,   531,
     532,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     118,   119,     0,     0,   350,     0,   103,   105,    97,    99,
      86,     0,   535,   536,     0,     0,   544,     0,    44,     0,
       0,     0,    46,    61,     0,     0,     0,   133,   131,   379,
     381,   380,   382,   383,   190,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   485,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   341,     0,
       0,     0,   291,     0,   227,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   539,   275,     0,
       0,   220,   398,     0,   146,     0,     0,   153,   113,     0,
       0,     0,     0,     0,   130,   137,   143,   143,     0,     0,
       0,     0,     0,   362,   372,     0,     0,   373,     0,   211,
       0,   312,     0,     0,   314,     0,     0,   316,     0,     0,
       0,   327,     0,   287,     0,   220,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   181,   120,   271,
     347,     0,   140,     0,     0,    52,     0,    58,     0,     0,
       0,     0,     0,   167,   202,     0,   376,     0,   377,   378,
     484,   300,     0,     0,   307,   301,     0,     0,   309,   302,
       0,     0,   311,     0,     0,     0,   293,   230,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   134,   132,     0,
       0,     0,     0,   318,     0,   320,     0,   322,   328,   340,
     292,   288,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   141,   142,    49,     0,    56,
       0,     0,     0,     0,     0,     0,   303,     0,     0,   304,
       0,     0,   305,     0,     0,   231,   232,   233,   234,     0,
     228,     0,     0,     0,     0,     0,   352,     0,    50,     0,
       0,   264,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   294,     0,   534,     0,     0,     0,     0,     0,     0,
       0,     0,   270,     0,     0,   313,     0,   315,     0,   317,
       0,   229,     0,     0,     0,     0,    51,    53,     0,    54,
       0,     0,     0,     0,     0,     0,   515,   516,   517,   518,
       0,     0,    59,   374,   375,   319,   321,   323,    55,    57
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,   105,  1080,   106,   107,   773,  1666,  1672,
    1068,  1299,  1877,  2117,  1069,  2053,  2158,  1070,  2119,  1071,
    1072,  1303,   394,   489,   207,   907,   108,   791,   501,  1805,
    1957,  1956,  1806,   502,  1871,  1267,  1476,  1268,  1479,   834,
     837,   840,   843,  1696,  1529,   755,   339,   465,   466,   111,
     112,   113,   114,   115,   116,   117,   118,   340,  1171,  1984,
    2072,   872,  1720,  1723,  1726,  2022,  2026,  2030,  2097,  2100,
    2103,  1167,  1168,   341,   960,   342,   122,  1350,  1127,   831,
     885,  1901,   123,   124,   125,   126,   343,   209,  1022,   563,
     289,  1509,   344,   345,   346,   635,   355,  1053,  1291,   499,
     494,  1023,   500,   376,   348
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1773
static const yytype_int16 yypact[] =
{
   10621,    65,   103, 10771, -1773, -1773,  4263,   108,    62,   -91,
     -59,    44,   121,   169,   182,   205,    -7,   232,   279,    69,
      88,  -175,  -175,  -162,   123,   143,    24,   216,   225,    31,
     245,   256,   290,   301,   313,   349,   353,   367,   382,   255,
     287,   342,   468,   268,    99,   388,   397,   429,   441,   644,
     414,   553,   674,    74,   402,   514,   -80,   413,  -115,  -115,
     419,   247,    59, -1773, -1773, -1773, -1773, -1773,   297,   582,
     588,    20,    48,   620,   639,   210,   734,   759,   765,  5876,
     788,   571,   590,   600,    22,    60, -1773,   627,   642, -1773,
   -1773,   836,   908,   602, -1773,  1409,   696,  4343,    -1,    14,
   -1773, -1773, -1773, 10185,   706, -1773, -1773, -1773, -1773, -1773,
   -1773, -1773, -1773, -1773, -1773, -1773, -1773, -1773, -1773, -1773,
      76, -1773, -1773, -1773, -1773,    19, -1773,    -5,   109, -1773,
       8, -1773, -1773, -1773, -1773, -1773,  -175,  -175,  -175,  -175,
    -175,  -175,  -175,  -175,  -175,  -175,  -175,  -175,  -175,  -175,
    -175,  -175,  -175,  -175,  -175,  -175,  -175,  -175,  -175,  -175,
    -175,   719,   732,   735,  -175,  -175,  -175,  -175,   739,  -175,
    -175,  -175,  -175,  -175,  -175,   743, -1773,  -175, -1773, -1773,
   -1773, -1773, -1773,  -175,  -175,   955,   751,   754,   755,  -175,
    -175,   776,   781, -1773, -1773, -1773, -1773,   807, 10185, 10185,
   10185,  9324,  9391,    26,    25,    57,   785,   818,   475, -1773,
     822,  1029,   145,   220,  1050, 10185,  4176,  4176, -1773, 10185,
   -1773, -1773, -1773, -1773,  4176, -1773, -1773, -1773, -1773, -1773,
   -1773,  4370,    25, 10185,  9109, 10185, 10185,   839, 10185,  9109,
   10185, 10185,   842,  9109, 10185, 10185, 10185, 10185, 10185, 10185,
    4176, 10185, 10185,  6612,   847,   843, -1773,  9109,  5876,  5876,
    5876,  4176, 10185,   858,   864,  5876,  5876,  5876,   871,   881,
     882,   895,   920,  6833,  7054,  7275,   850,  2980,  1088,  6612,
      22,   914,   931,  -115,  -115,  -115, 10185, 10185,  -174, -1773,
    -107,  -115,   932,   975,   976,  8822,   -89,   101,   962,   987,
     992,   998,  1002,  1012,  1017,  5876,  5876,  6612,  1019,    13,
     924, -1773,  1020,  1246,  1248, -1773,  1030,  1031,  1032,  5876,
    5876,  1042,  1043,  1048,   621, -1773,   276,  -175,  -175,  -175,
    -175,     6,    27,    41,    43,   769,  7496, 10185,  5206, -1773,
   -1773,  1044, -1773,  3160, -1773,  1268, -1773,   408,   359,  1271,
   10185, 10185, 10185,  -169, 10185,  1051, -1773,  1114, 10185, 10185,
   10185, -1773, -1773, 10185,  1053,  1290,  1291,  1071, -1773, -1773,
    1296, -1773,  1298, -1773,   565,  8538,   536,  4176, 10185, -1773,
   -1773,  6612,  6612,  9611,  9678,  1076,  1080,  4370, -1773, -1773,
   -1773, -1773, -1773, -1773,  6612,  1304,  1087, 10185, 10185,  1312,
   10185, 10185, 10185, 10185, 10185, 10185, 10185, 10185, 10185, 10185,
   10185, 10185, 10185, 10185, 10185, 10185, 10185, 10185, 10185, 10185,
   10185, 10185,  4176,  4176,  4176,  4176,  4176,  4176,  4176,  4176,
    4176,  4176,  6612,  4176,  4176, 10185,  4176,  4176,  4176,  4176,
    4176, 10185,  4370, 10185,  4176,  4176,  4176,  4176,  4176,    25,
    4370,    25,  1096,  1096,  1096,   148,  9006,   155,  9072,   119,
    1092,  1313,  -175,  1090, -1773,  1091,  5270, 10185,  9109, -1773,
   10185, 10185, 10185, 10185, 10185, 10185, 10185, 10185, 10185, 10185,
   10185, 10185, 10185, 10185, 10185, -1773, -1773, 10185, 10185, -1773,
   -1773,   625,   675,  -149, -1773,   552, -1773,   -77,  8853, -1773,
     104,  -139,  -113,  1100,  1102, 12152,  9109,  3568, -1773,   304,
   12173, 12194, 10185, 12215,   328, 12236, 12257, 10185,   365, 12278,
   12299, 12320, 12341, 12362, 12383,  1108, 12404, 12425,  1325, 10185,
   10185,   383,  1327,  1328,  1329,  1117, 12446, 10185, 10185,  1335,
    1336,  1336, 10185,  8894,  8894,  8894,  8894, 10185,  1340, 10185,
    1341, 10185,  1342,  9109,  9109,  8658,  1128,  1347,  1132, -1773,
   -1773,  -103, -1773, -1773,  9227,  9269,  -115,  -115,    57,    57,
     -95, 10185, 10185, 10185,  8822,  8822, 10185,  5270,   -68, -1773,
   10185, 10185, 10185, 10185, 10185, 10185, 10185, 10185, 10185,  1350,
    1356,  1362, 10185,  1357, 10185, 10185,  1774, -1773, -1773,  9109,
    9109,  9109,  1364,  1365, 10185, 10185, 10185, 10185, 10185,  1368,
     527,  7717,  7938, 10185, 10185,  4176, 10185, -1773,  1306, 10185,
   -1773,  1314, -1773,  1317, -1773,  1318,    37,    38,    39,    40,
    9109,  1096, -1773, 12467, -1773,   432, 10185,  8159, -1773, 10185,
   10185,   666, -1773, 12488, 12509, 12530,  1211,  9350, -1773,  1149,
    3632, 12551, 12572, 10435, -1773, -1773,  9109, -1773,  1938, -1773,
    3130, 10185, 10185, -1773, 10185, 10185,  1159, 12593,  5030,  1162,
     440,   284, 12614,   288, 11807, 10185,  9109,  1380,  1381, -1773,
   10185, 12635, 11830,   251,  8565,  8565,  8565,  8565,  8565,  8565,
    8565,  8565,  8565,  8565,  8565,  9447,  8565,  8565,  8565,  8565,
    8565,  8565,  8565,  9514,  9556,  9637,   684,   688,   684,  1165,
    1167,  1163,   252,   252,  1173,   252,  1179,  1180,  1181,  9734,
     252,   252,   252,   502,   252, 13265, -1773,   775,  1182,  1183,
    1189,   703,   710,  1192,  1193,  1194,  1376,  1377,  6612,   141,
    1378,  1379,  6612,    87,  4370, 10185,  1419,  1422,    32,   252,
   -1773,   122,    30,    36,   235, -1773,  3451,   547,  3747,  2004,
    2072,  1295,  1295,   604,   604,   604,   604,   667,   667,  1096,
    1096,  1096,  1096,    12, 12656, 11853, -1773, 10185, 10185,  1424,
      15,  9109, 10185, 10185,  1437,  9109, 10185,  1438,  4176,  1442,
   -1773,    25,  1443,  4176, 10185,  4370,  1445,  9109,  9109,  1305,
    1455,  1456, 12677,  1458,  1310,  1464,  1471, 12698,  1319,  1473,
    1474,  1476,  1477,  1480,  1482, -1773,  1484,  1485, 10185, 12719,
    4653,  1259, -1773, -1773, -1773,  1487,  1490, 12740, 12761, 10185,
    6612,  1491,  1492, 12782,  1276, 13265,  1272,  1278, 13265,  1285,
    1294, 13265,  1286,  1311, 13265,  1307, 12803, -1773, 12824, -1773,
   12845, -1773,   556,   583,  9109,  1315, -1773, -1773,  3299,  4727,
    -115, 10185, 10185, -1773, -1773,  1303,  1308,  8822,  9806,  9848,
    9923,  9160,   598,  -115, 10213, 12866,  4733, 12887, 12908, 12929,
   12950, 12971, 12992, 13013, 10185,  1530, -1773, 10185, 13034, -1773,
   11876, 11899, -1773,   593,   670,   689, -1773, -1773, 11922, 11945,
   10063, 13055, 11968,   359, -1773, -1773,  9109, -1773,  9109,  3568,
    1321,  9109,  1320,   -13, 10306, 10465,   252, 10767,  1322,  5103,
    1323,  1326,  1330, -1773,  9109, -1773,  9109, -1773,  9109, -1773,
    9109,   714, -1773, -1773,  3874,  9109,  1096, -1773, 13076, 11991,
    9109, -1773,  1532,  1533,  1535,  1324, 10185, 10250, 10185, 10185,
   -1773, -1773,    49,   740, -1773, -1773, 10335, -1773,  1539,  9898,
    1348,  1351,  6612,  1541,  1512,  1513,  6612,   141,  1537,  1540,
    6612,   141,  5331,   744, -1773, -1773, 12014,   253,  1198, -1773,
   -1773, -1773, -1773, -1773, -1773, -1773, -1773, -1773, -1773, -1773,
   -1773, 10185, -1773, -1773, -1773, -1773, -1773, -1773, -1773, 10185,
   10185, 10185, -1773,  9109, -1773, -1773, -1773, -1773,  4176, -1773,
   -1773, 10185, -1773,  6612,  4176,  4176,  4176, -1773, -1773, -1773,
   -1773, -1773, -1773, -1773, -1773, 10185,  4176, -1773,  4176, -1773,
   10185, -1773, -1773, -1773, -1773,  -175,  -175,  1573, -1773, 10185,
    1577,  -175,  -175,  1579,    33, 10185,  1580,  1581,   916, -1773,
    1584,  1371,    22,  1591, -1773,  9109,  9109,  9109,  9109, -1773,
     252, 10185, -1773,  1383,  1388,  1369, -1773,  1594, -1773, -1773,
   -1773, -1773, -1773,   445,   447, 13097, 12037, -1773, -1773,  1392,
    4176,   637, 13118, 12060, -1773,   657, 10793, -1773, -1773, -1773,
      68, -1773, -1773,  8565,   252,  -115,  3568, -1773,   902,  6612,
    6612,  1595,  6612,   903,  6612,  6612,  1604,  1520,  6612,  6612,
    6612,  6612,  6612,  6612,  6612,  6612,  1226,  1606,  1607,  9109,
   -1773,  6612,  1610,  1611,  2875, -1773, -1773,  1613, -1773,  1614,
     294, 10185,   294, 10185,   294, 10185,   294, 10185,  1620,  1621,
    1626,  1627,  1628,   774,  1633, 10372, -1773, -1773,   -63, 10819,
   10845, -1773, -1773,  5379,  -147,  -115,  -115,  -115,  1634,  9970,
    1391,  1636,  1417,    35,    47,    52,    53,   -14, -1773,   -54,
   -1773,   598,  1637,  1639,  1640,  1641,  1642,  1643,  1645,  1647,
    1651, 13265, -1773,  1316,  1414,  1653,  1654,  1656,  1578,  1673,
    1657,  1675, 10185,   359,   -48,   778,   779, -1773,   790, -1773,
   -1773, 10185, 10185, -1773, 10185, 10185, -1773, 10185, 10185, 10185,
     791,   796,   799,   800, -1773, 10185,   806,   359,   359,   811,
    6612,  6612,  6612,  1678, 10871, -1773,  3914,   195,  1679,  1680,
    1418, -1773,  1457, -1773,  1361,  1459,  6612,  1478, -1773,  -175,
    -175,  1681, 10185,  1683,  -175,  -175,  1700, 10185,  1701, -1773,
     252,  1704, -1773,  1708, -1773,  1707,  8565,  8565,  8565,  8565,
     711,  1486,  9046,  1462,   252,   252,  1489,   720,   741, 13139,
    1493,   252,  8565,  1141,  4176, -1773,  1488, -1773,  1141,  4176,
   -1773,   193,  1494,  1712,  1556, -1773, -1773, -1773,    22, 10185,
   -1773,   812, -1773,   815,   816,   820,   829,   294, 13265,  1499,
   10185, 10185,  6612,  1496, -1773, -1773, -1773, -1773,  1501, -1773,
    1709,    16, -1773, -1773,  1716, 10185,  4570,  1507,  1506,  1726,
    1727,    71,  1505,  1508,  1624,  1624,  6612,  1730,  1510,  1511,
    1735,  1737,  6612,  1515,  1740,  1741,  1743,  1744,  1745,  1747,
    1748,  1750, -1773,  1752,  6612,   832,  1767,  6612,  6612,  1772,
    1773, -1773,  6612,  6612, 13265,  6612, 13265,  6612, 13265,  6612,
   13265,  6612,  6612,  6612,  1551,  1552,  1775,   629, -1773, 10185,
   10185, 10185,  1554,  1555,  -143,  -140,  -117,  1561, -1773,  1616,
    6612, -1773, 10185, -1773,  1783, -1773,  1785, -1773,  1786, -1773,
    1787, -1773, -1773,  8822,   396,  6097, -1773,  1566,  1567,  1569,
    1570,  1571,  1572,  8380, -1773,  9109, -1773, -1773, -1773,  1574,
   10185, -1773, -1773, 12083,  1798,   252,  1583,  1582, 10897, 10923,
   10949, 10975, 11001, 11027, 11053, -1773, -1773, -1773, -1773, 13265,
   -1773,   252,  1802,  1803,  1648, -1773, 10185, 10185, 10185, -1773,
    1804,   686,  4370, -1773, -1773, -1773,  1585,  1806,  1141,  4176,
   -1773,  1749, -1773,  1141,  4176, -1773,  1972, -1773,   294, -1773,
     525, -1773, -1773, -1773, -1773, -1773, -1773,  4176, 10185, -1773,
   -1773, -1773, -1773,  4176,  1810, -1773, -1773,    23, -1773, -1773,
   -1773, -1773, -1773, -1773,  1811,   684,   684, -1773,  1827,   684,
     684,  4370, 10185,  1829,  1812,    32, -1773,  1830, 12106,    22,
   -1773,  1833,  1834,  1836,  1837,  6612, 10185, 11079, 11105,   837,
   -1773, 10185,  1840, -1773, -1773,  4176, -1773, 11131,  5434, 13265,
   -1773,  1838,  1839, -1773, -1773, -1773, 10185, 10185,  -115,  1841,
    1842,  1843, -1773, 10185, 10185, -1773, -1773,  1844, 10185, -1773,
   -1773, -1773, -1773, -1773, -1773, -1773, -1773,  1846,  1847,  1625,
   -1773,  1849,  1689, 10185, -1773,  1851,  1871,  1873,  1874,  1875,
    1876,  1069,  1881,  9109,  9109, 10185, -1773,  8894,  5552, 13160,
    3769,    57,    57,  -115,  1885,  -115,  1886,  -115,  1887, 10185,
   -1773,   594,  1667, 13181, -1773, -1773, -1773, -1773,  5592,   -36,
   -1773,  1890,  1892,  6612,  -115,  -115,  -115,  -115,  -115,  4965,
    1893,   848, 10185,  2030,  1894,   359, -1773, -1773, -1773, 10185,
   10185, 10185, 10185, 10185, 10185, 10185, -1773, -1773, -1773,  6612,
    4456,   663, 13202, -1773, -1773,  6318,  1674,  5030,  5030,  6612,
   -1773,  1895,   684,   684, -1773,  1897,   684,   684, -1773,  6612,
   -1773,  1682,  8565,   252,  5655,  6391,  4370, -1773,  1898,  1900,
   -1773,  1901,  1903,  1905,  2350, -1773,  1906,  1908, -1773,  1691,
   -1773, -1773, -1773, -1773, -1773,  1909,   687, 13265, 10185, 10185,
    6612,  1690,   857, 13265, -1773,  1914, 10185, -1773, -1773,  1692,
    1698,  5773,  5813,   202, -1773, -1773, -1773,  5994,  6034, -1773,
    6275,  1923, -1773,  6612, -1773,  1848,  1924, 13265, -1773, -1773,
   -1773, -1773, -1773, -1773,  1702, -1773, -1773,   870,   885,  8773,
    2456,  1926,  1710, -1773, 10185, -1773,  1699,  1711,   160, -1773,
    1713,   168, -1773,  1715,   238, -1773,  1717, 12129,  1931,  6612,
    1933,  1718, 10185, -1773, -1773,   905,   240,   292,   296,   298,
     305,  8601,   309, -1773,  1932,  6348, -1773, -1773,  8565,  8565,
   11157, 11183, 11209, 11235, 11261,  1805, 10185, -1773, 10185, -1773,
   -1773,  9109,  2508,  1939,  4370,  1719,  1736,  1738, -1773,  1942,
    1963, -1773,  1965,  1966,  1967, -1773, -1773, -1773,  5206, -1773,
   -1773,  4176, 13265, -1773, -1773, -1773, -1773, -1773, -1773, -1773,
   -1773,    22, -1773,  1809, -1773, -1773, 10185, 11287, 11313, -1773,
    6612, 10185,  1969, -1773, 11339, -1773, -1773,  6612,  6612,  1971,
    1974,  1975,  1976,  1983,  1984,   906,  1764, -1773,  6612,   262,
     426,  9109, -1773, -1773,    57,  4494, -1773, -1773,  8822,   598,
    8822,   598,  8822,   598,  1988, -1773,   910,  6612, -1773,  6509,
    1989,  9109,  -115,  -115,  -115,  -115,  -115, -1773, -1773, -1773,
   -1773, 10185, 10185, 10185, 10185, 10185, 10185,  6549,  6730,   911,
   -1773, -1773,  1776,  1768, -1773,  1990, -1773, -1773, -1773, -1773,
   -1773,   919,  2925,  1991,   925,  1997, -1773,  1781, 13265, 10185,
   10185,   926, 13265, -1773, 10185,   929,   938, -1773, -1773, -1773,
   -1773, -1773, -1773, -1773, -1773,  1782, 10185,   939,  1784,  -115,
    6612,  2006,  1788,  -115,  2008,   943,  1789, 10185, -1773,  6770,
     315,   507,  6951,   329,   940,  6991,   340,  1144, -1773,  6612,
    2010,  1902, 10457,  1792, -1773,   944,   375,   379,   387,   393,
     405, 11365, 11391, 11417, 11443, 11469,  2539, -1773, -1773,  2012,
    2029, -1773, -1773, 10185, -1773,  4370,    25, -1773, -1773, 10185,
   13223, 11495,    45, 11521, -1773, -1773, -1773, -1773, 10185,  7172,
    2031,  -115,   102, -1773, -1773,  -115,   113, -1773,  2037, -1773,
    7212,  2038, 10185,  2040,  2045, 10185,  2049,  2051, 10185,  2053,
    1831, -1773, 10185, -1773,   598, -1773,  2054,  9109,  9109,  9109,
    9109,  8601, 10185, 10185, 10185, 10185, 10185, -1773, -1773, -1773,
    5030,  3054, -1773,  1845,   948, -1773, 10185, -1773,  6612, 10185,
     949,   952, 11547, -1773, -1773,   410, -1773,   416, -1773, -1773,
   -1773, -1773,  1835,  7393, -1773, -1773,  1850,  7433, -1773, -1773,
    1852,  7614, -1773,  2056,  2669,  1164, 10494, -1773,   953,   966,
     967,   982,   482,   985, 11573, 11599, 11625, 11651, 11677,  1853,
    4370,  1854,  2057,  1855, 13244,   993,  7654, -1773, -1773, 10185,
    -115,  -115,   598,  2059,   598,  2062,   598,  2063, -1773, -1773,
   -1773, -1773,   598,  2064,  2066,  2067,  2069,  9109,  2070, 10185,
   10185, 10185, 10185, 10185,  2074, -1773, -1773, -1773,  4176, -1773,
    1857,  2076,  7835,   505,   515,  1255, -1773,  1860,  1481, -1773,
    1861,  1522, -1773,  1862,  1858, -1773, -1773, -1773, -1773,   997,
   -1773,  8565, 11703, 11729, 11755, 11781, -1773,  1000, -1773,  1863,
    6612, -1773,  2081, 10185, 10185,  2087,   598,  2088,   598,  2089,
     598, -1773,  2090, -1773, 10185, 10185, 10185, 10185,  4176,  2094,
    4176,  1001, -1773,  7875,  8056, -1773,  2216, -1773,  2501, -1773,
    2658, -1773,  8096,  8277,  8317,  8498, -1773, -1773,  1010, -1773,
    2095,  2096,  2097,  2098,  2099,  2100, -1773, -1773, -1773, -1773,
    4176,  2101, -1773, -1773, -1773, -1773, -1773, -1773, -1773, -1773
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1773, -1773, -1773, -1773,   767, -1773, -1773, -1773, -1773,   159,
   -1773, -1773, -1773, -1773, -1773, -1773, -1773, -1773, -1773, -1773,
   -1773, -1773,  -377,  -123,  2457,  3470, -1773,  1617, -1773, -1773,
   -1773, -1773, -1773, -1773, -1773, -1772, -1773,   303, -1773, -1773,
   -1773, -1773, -1773, -1773,   793,  2112,    17,  -555,  -280, -1773,
   -1773, -1773, -1773, -1773, -1773, -1773, -1773,  2113, -1773, -1773,
   -1773, -1773, -1773, -1773, -1773, -1773, -1773, -1773, -1773, -1773,
   -1773, -1170, -1149,  2117, -1618,  2118, -1773, -1773, -1773,  1587,
   -1773,   302, -1773, -1773, -1773, -1773,  1912, -1773, -1773,    80,
   -1773, -1591,  2713,   196,  3094,  2701,  -273,   628, -1773,   136,
     227, -1773,  -416,    -3,   275
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -555
static const yytype_int16 yytable[] =
{
     127,  1394,  1735,   212,   370,   395,   706,   558,   708,  1765,
    1766,   617,   396,   865,   866,   577,  1062,   593,  1392,   372,
     110,  1078,  1514,   723,   309,   380,   353,  1645,   237,   364,
     459,   596,   620,  1885,   237,   242,  1051,  1281,   566,   567,
     242,  1383,   923,   925,   927,   929,   622,   229,   624,   230,
     218,  2007,   314,  1385,   315,   568,  1228,   646,  1387,  1389,
     233,   463,   206,   297,   357,   566,   567,   234,   312,   566,
     567,     4,   566,   567,   780,  1316,   347,  1525,   738,   781,
     742,   312,   745,  1373,   280,  1573,   789,  1574,  1575,   790,
    1576,   658,   312,   660,  1038,   566,   567,   284,   285,   668,
     281,   282,  1815,     5,  1158,   566,   567,   286,  2016,   566,
     567,  1577,   792,  1578,   287,   790,   387,   566,   567,  2018,
    1159,   214,   569,   566,   567,   860,   744,   220,  1160,  1161,
    1162,   216,   316,   867,  1163,  1164,  1165,  1166,   288,   290,
     579,   296,   210,   298,   566,   567,   784,   299,  1038,   566,
     567,   785,   215,   300,   301,   736,   302,   303,   566,   567,
     873,   276,   740,   217,   277,  1369,  1063,  1064,  1065,  1066,
     304,   392,   393,   618,  1393,   221,   566,   567,  1414,    57,
      58,    59,    60,   258,  2010,  2011,   259,  1384,   222,   260,
     460,   461,  1732,    70,   621,   310,    73,  1282,  1283,  1386,
    1491,   312,  1646,  1438,  1388,  1390,   392,   393,   623,  1881,
     625,   223,  1200,   495,   495,   224,  1391,   383,   104,   384,
     104,   495,   464,   104,  1079,  1079,   385,  1897,   371,   312,
     397,   347,   398,   211,   399,   619,   347,   594,   225,   206,
     347,   381,  1067,   373,   206,  1392,   238,   495,   382,   311,
     347,   354,   238,   239,   347,   347,   347,   347,   495,  1056,
     243,  1052,   347,   347,   347,  1057,   924,   926,   928,   930,
     347,   347,   347,   219,  2008,  1229,   347,   312,   128,   858,
     859,   213,   358,   566,   567,   226,   388,   389,   390,   391,
    1317,   964,  1318,   227,   966,   968,   970,   319,   378,   874,
     320,  1038,   347,   347,   347,   379,   392,   393,   388,   389,
     390,   391,   228,  1044,   566,   567,   347,   347,   388,   389,
     390,   391,   365,   580,   369,   566,   567,   787,   392,   393,
     581,   292,   788,   347,   293,   347,   746,   294,   392,   393,
     388,   389,   390,   391,   233,   235,   313,   388,   389,   390,
     737,  1055,   493,   497,   388,   389,   390,   741,   253,   356,
     392,   393,  1039,   561,   562,   236,  1045,   487,   947,   488,
     366,   570,   566,   567,   495,   578,   385,   254,   347,   347,
     566,   567,  2049,   956,  1898,  1899,   525,   305,  1828,   306,
    1900,   347,   388,   389,   390,   391,  1830,   535,   470,   471,
     472,   473,   474,   475,   476,   477,   478,   479,   480,   481,
     482,   483,   392,   393,   566,   567,   484,  2055,  1439,   495,
     495,   495,   495,   495,   495,   495,   495,   495,   495,   347,
     495,   495,   255,   495,   495,   495,   495,   495,   240,   392,
     393,   495,   495,   495,   495,   495,   312,   241,   312,  -548,
     566,   567,   566,   567,   532,   533,   534,   245,   503,   284,
     285,   539,   540,   541,  1058,   347,  1832,   244,  1841,   286,
     392,   393,   392,   393,   256,   904,   295,   905,   245,   462,
    -553,   469,  -551,   388,   389,   390,   965,   388,   389,   390,
     969,   496,   496,   388,   389,   390,   391,   257,   611,   496,
     612,   589,   590,   347,   566,   567,   268,   504,   566,   567,
     566,   567,   246,   666,  1158,   602,   603,   566,   567,   263,
    1842,   566,   567,   247,  1843,   496,  1844,   566,   567,  2141,
    1159,   264,   798,  1845,   799,   248,   496,  1846,  1160,  1161,
    1162,   566,   567,  1972,  1163,  1164,  1165,  1166,  1902,  1903,
     347,   347,   566,   567,  1900,   356,   798,  1975,   804,   707,
     979,   709,   710,   711,   712,   713,   714,   715,  1978,   717,
     718,   249,   720,   721,   722,   250,   724,  1145,   392,   393,
     728,   729,   730,   731,   732,   464,   464,   566,   567,   251,
    1242,   566,   567,   798,  1247,   808,   347,   347,   347,   566,
     567,   279,   636,  1987,   252,   566,   567,  1988,   347,   347,
     261,   798,   495,   821,   677,  1989,  1040,   566,   567,   262,
    1046,  1990,   566,   567,   278,  1158,  1590,   347,   566,   567,
     639,   776,   640,  1991,   347,  1566,  1567,   269,  2060,   385,
     270,  1159,   283,   271,  2061,   272,   863,   864,   291,  1160,
    1161,  1162,   496,   347,   562,  1163,  1164,  1165,  1166,  1911,
     798,  1914,   933,  1917,   392,   393,   392,   393,   962,   726,
     963,  1758,   307,   347,  -552,   308,  -550,   734,   470,   471,
     472,   473,   474,   475,   476,   477,   478,   479,   480,   481,
     482,   483,  1624,  1625,   566,   567,   484,   496,   496,   496,
     496,   496,   496,   496,   496,   496,   496,   317,   496,   496,
    2077,   496,   496,   496,   496,   496,  1158,   566,   567,   496,
     496,   496,   496,   496,   733,  1020,   735,   566,   567,   318,
     788,   265,  1159,  2123,   266,   347,   267,  1973,   321,   347,
    1160,  1161,  1162,  2124,   392,   393,  1163,  1164,  1165,  1166,
     904,   916,   905,  1353,  -554,  1355,   906,  1357,   664,  1359,
     665,   273,  1392,   322,   274,  1392,   275,   385,  1392,   323,
     836,   839,   842,   845,   782,   798,   783,  1060,   347,  1290,
     979,  1024,   347,   385,   798,   495,  1141,   661,   312,   662,
     495,   609,   349,   350,   347,   347,   206,   470,   471,   472,
     473,   474,   475,   476,   477,   478,   479,   480,   637,   482,
     483,   798,   351,  1142,  2035,   484,   479,   480,   481,   482,
     483,   798,   352,  1187,  1728,   484,   363,   347,   470,   471,
     472,   473,   474,   475,   476,   477,   478,   479,   480,   481,
     482,   483,   361,   607,  1243,   608,   484,   609,  1248,   359,
     205,   347,   206,   626,  1252,  1254,   627,  1485,  1486,   628,
    1311,   629,  1489,  1490,   360,   798,   470,   471,   472,   473,
     474,   475,   476,   477,   478,   479,   480,   481,   482,   483,
    1314,   481,   482,   483,   484,   798,  1392,   913,   484,   904,
     496,   905,  2095,  1759,  2098,   940,  2101,   777,   798,   778,
    1188,   779,  2104,   347,  1492,   347,   206,   904,   347,   905,
    1795,   904,   788,   905,   362,  1796,  1003,   798,   367,  1189,
    1505,   347,  1287,   347,  1088,   347,   904,   347,   905,  1092,
     377,  1028,   347,   904,   904,   905,   905,   347,  1030,   798,
    1148,   425,   798,   904,  1214,   905,  1392,  1154,  1474,  1392,
    1305,  1306,  1392,  1169,   426,  1392,  2146,   427,  2148,   347,
    2150,   432,   443,   347,   904,   439,   905,   347,   798,  1477,
    1230,  1047,   798,   444,  1250,   495,   445,   446,   470,   471,
     472,   473,   474,   475,   476,   477,   478,   479,   480,   481,
     482,   483,  1322,  1328,  1323,  1329,   484,  1392,   449,  1392,
     347,  1392,   798,   450,  1366,   495,   798,   798,  1415,  1416,
     347,   495,   495,   495,   467,  1497,  1716,  1717,   798,   798,
    1417,  1425,  1094,   495,   798,   495,  1426,   798,   798,  1427,
    1428,   451,  1632,  1633,   798,   486,  1430,  1636,  1637,   798,
    1499,  1431,  1500,   798,   798,  1501,  1502,   468,   798,   312,
    1503,   485,   347,   347,   347,   347,   490,   798,  1158,  1504,
     798,   512,  1549,   496,   517,  1670,  1090,  1671,   496,   529,
    1252,  1254,   530,  1704,  1159,  1705,   798,   495,  1744,   553,
     537,  1639,  1160,  1161,  1162,  1801,   538,  1802,  1163,  1164,
    1165,  1166,   556,   542,  1305,  1306,   347,   347,   798,   347,
    1819,   347,   347,   543,   544,   347,   347,   347,   347,   347,
     347,   347,   347,   798,  1255,  1820,   347,   545,   347,   470,
     471,   472,   473,   474,   475,   476,   477,   478,   479,   480,
     481,   482,   483,  1670,  1670,  1840,  1895,   484,  1919,   798,
    1920,  1939,   546,   559,  1261,   492,   131,  1943,   595,  1944,
    1264,  1265,  1266,   788,  1670,  1947,  1952,  1474,  1493,  1954,
     560,   571,  1270,  1627,  1271,  1628,  1477,  1670,  1955,  1960,
    1976,   798,   798,  1968,  1986,  1321,  1801,  1474,  2052,  2057,
    1474,   798,  2058,  2073,   582,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   798,   798,  2074,  2075,   171,   172,
     173,   174,   492,   131,   572,   573,   176,   177,   178,   583,
     798,   179,  2076,   798,   584,  2078,  1310,   347,   347,   347,
     585,  1670,   184,  2090,   586,   798,  1660,  2132,  2138,  1670,
    2139,  2160,  1342,   347,   587,  1374,  1375,  1376,  2170,   588,
    2171,   592,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   385,   597,   496,   598,   171,   172,   173,   174,   599,
     600,   601,  1158,   176,   177,   178,   604,   605,   179,  1906,
     495,   495,   606,   379,   638,   495,   495,   642,  1159,   184,
     648,   649,  1158,   496,   206,   312,  1160,  1161,  1162,   496,
     496,   496,  1163,  1164,  1165,  1166,   654,   655,  1159,   347,
     656,   496,   657,   496,   659,   675,  1160,  1161,  1162,   676,
     679,   680,  1163,  1164,  1165,  1166,   683,   484,   747,   205,
     748,   750,  1404,   347,   187,   188,   189,   356,   794,   347,
     795,   815,   818,   822,   823,   824,   196,  1640,   197,   104,
     825,   347,   829,   830,   347,   347,   847,   849,   851,   347,
     347,   855,   347,   856,   347,   496,   347,   884,   347,   347,
     347,   857,   886,   889,   904,  1874,   905,  1444,   918,   887,
     896,   897,   903,  1158,  1979,   945,   920,   347,   948,   921,
     922,   187,   188,   189,   957,   961,   974,   975,  1006,  1159,
    1007,  1008,   347,   196,  2070,   197,   104,  1160,  1161,  1162,
     347,  1011,   347,  1163,  1164,  1165,  1166,  1013,  1014,  1015,
    1025,  1026,  1027,   364,   131,  1032,  1033,   392,   393,  1034,
    1035,  1036,  1041,  1042,  1253,  1049,  1050,  -549,  1077,   470,
     471,   472,   473,   474,   475,   476,   477,   478,   479,   480,
     481,   482,   483,  1084,  1087,   495,   495,   484,  1089,  1091,
     495,   495,  1095,   158,   159,   160,   161,   162,   163,   164,
     165,   166,  1099,  1100,   495,  1102,   171,   172,   173,   174,
     495,  1104,  1098,  1589,   176,   177,   178,  1103,  1105,   179,
    1108,  1109,  1640,  1110,  1111,  2125,  1107,  1112,  1119,  1113,
     184,  1114,  1115,  1120,  1487,  1126,   312,  1121,  1128,  1130,
    1131,  1132,   347,   475,   476,   477,   478,   479,   480,   481,
     482,   483,   495,  1133,  1135,   347,   484,  1134,  1875,   470,
     471,   472,   473,   474,   475,   476,   477,   478,   479,   480,
     481,   482,   483,  1151,  1136,  1137,  1182,   484,  1152,  1220,
    1221,  1144,  1222,  1520,  1197,  1199,  1232,  1238,   496,   496,
    1223,  1205,  1207,   496,   496,  1208,  1239,  1240,  1922,  1209,
     347,   347,  1496,   356,   470,   471,   472,   473,   474,   475,
     476,   477,   478,   479,   480,   481,   482,   483,  1235,  1275,
    1236,  1244,   484,  1277,  1245,  1280,  1285,  1286,   464,   464,
     347,  1288,   187,   188,   189,  1289,   347,  1292,  1302,  1158,
    1304,  1309,  1326,  1641,   196,  1300,   197,   104,  1683,  1643,
    1301,  1332,  1333,  1343,  1344,  1159,   347,  1347,  1348,  1351,
    1380,  1352,  1580,  1160,  1161,  1162,   347,  1361,  1362,  1163,
    1164,  1165,  1166,  1363,  1364,  1365,   347,  1367,  1377,  1382,
    1158,   347,  1381,  1405,  1395,  1396,  1442,  1397,  1398,  1399,
    1400,  1675,  1401,  1718,  1402,  1721,  1159,  1724,  1403,  1406,
    1407,  2000,  1408,  1411,  1160,  1161,  1162,   347,  1409,  1626,
    1163,  1164,  1165,  1166,  1736,  1737,  1738,  1739,  1740,  1742,
    1410,  1412,  1435,  1440,  1441,  1470,  1443,  1450,  1445,  1452,
     347,   470,   471,   472,   473,   474,   475,   476,   477,   478,
     479,   480,   481,   482,   483,  2036,  1455,  1457,  1447,   484,
    1459,  2127,  1460,  1461,  1467,  1513,  1481,  1473,  1653,  1495,
    1494,  1506,  1516,   496,   496,  1511,   347,  1512,   496,   496,
    1521,  1522,  1523,  1524,  1526,  1528,  1532,  1527,   347,  1533,
    1534,  1535,   496,  1536,  1538,  1678,  1539,  1540,   496,  1541,
    1542,  1543,  2129,  1544,  1545,  1634,  1546,  1547,   347,   470,
     471,   472,   473,   474,   475,   476,   477,   478,   479,   480,
     481,   482,   483,  1550,   356,   347,  1553,   484,   495,  1554,
    1563,  1564,  1565,  1571,  1572,  1579,     7,     8,   312,  1584,
     496,  1585,  1586,  1587,  1711,  1593,  1594,   347,  1595,  1596,
    1597,  1598,  1605,  1602,   347,   347,  1607,  1608,  1617,  1618,
    1623,  1619,  1630,  1629,  1644,   347,  1656,  1647,   347,   470,
     471,   472,   473,   474,   475,   476,   477,   478,   479,   480,
     481,   482,   483,  1650,   347,  1655,  1658,   484,   347,  1661,
    1662,   464,  1663,  1664,  1674,  1679,  1680,  1684,  1685,  1686,
    1689,  1691,  1763,  1692,  1693,  1694,  1695,  1698,   751,    24,
      25,   752,    27,    28,   753,    30,   754,    32,    33,    34,
      35,  1780,  1783,  1784,    37,    38,    39,  1699,    40,  1700,
    1701,  1702,  1703,    45,    46,    47,    48,  1706,    50,    51,
      52,  1719,  1722,  1725,    55,  1729,  1733,   347,  1734,  1743,
    1747,  1768,  1764,  1771,  1785,  1775,  1786,  1787,  1910,  1788,
    1913,  1789,  1916,  1791,  1792,  1794,   347,  1793,   208,  1800,
    1803,  1807,  1926,  1927,  1928,  1929,  1930,  1808,  1814,  1826,
    1817,  1818,  1823,    81,    82,    83,  1816,  1835,  1847,  1824,
    1837,  1827,  1829,   312,  1831,  1861,  1833,  1838,  1866,  1863,
       7,     8,   470,   471,   472,   473,   474,   475,   476,   477,
     478,   479,   480,   481,   482,   483,  1864,  1856,  1865,  1867,
     484,  1868,  1869,  1870,  1876,  1883,  1158,  1889,  1638,  1962,
    1890,  1891,  1892,  1966,   347,   347,   347,   347,   347,  1893,
    1894,  1862,  1159,  1896,  1918,  1924,  1942,  1941,  1946,  1940,
    1160,  1161,  1162,  1948,   892,   347,  1163,  1164,  1165,  1166,
    1949,  1958,  1964,  1961,  1967,   375,  1981,  1965,  1998,  1969,
    1982,  1985,   751,    24,    25,   752,    27,    28,   753,    30,
     754,    32,    33,    34,    35,  1999,  1746,  2014,    37,    38,
      39,  2015,    40,  2019,  2021,  2017,  2024,    45,    46,    47,
      48,  2025,    50,    51,    52,  2028,   496,  2029,    55,  2032,
    2037,  2033,  2068,  2087,  2062,  2096,   356,  2051,  2099,  2102,
    2105,  2042,  2106,  2107,   347,  2108,  2110,  2086,  1515,  2064,
    2116,  2066,  2121,  2084,  2088,   495,  2120,  2142,  2131,  2126,
    2128,  2130,  2140,  2145,  2147,  2149,  2151,    81,    82,    83,
    2157,  2172,  2173,  2174,  2175,  2176,  2177,  2179,  2004,  1886,
     452,   453,   454,   456,   458,   109,   119,   347,  1530,   793,
     120,   121,  1904,  1657,     0,     0,     0,   491,   832,     0,
       0,   498,     0,     0,     0,   495,     0,   495,     0,     0,
    2093,  2094,     0,     0,     0,   505,   507,   510,   511,     0,
     513,   507,   515,   516,     0,   507,   519,   520,   521,   522,
     523,   524,     0,   526,   527,     0,     0,   495,   954,   507,
       0,     0,  2002,     0,   536,   470,   471,   472,   473,   474,
     475,   476,   477,   478,   479,   480,   481,   482,   483,   555,
       0,     0,     0,   484,     0,     0,     0,     0,   564,   565,
       0,     0,     0,     0,     0,     0,     0,   565,     0,   472,
     473,   474,   475,   476,   477,   478,   479,   480,   481,   482,
     483,  2003,     0,     0,  2118,   484,     0,     0,     0,     0,
       0,     0,     0,   470,   471,   472,   473,   474,   475,   476,
     477,   478,   479,   480,   481,   482,   483,     0,   631,   633,
     507,   484,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   643,   644,   645,     0,   647,     0,     0,     0,
     650,   651,   652,     0,  2156,   653,  2159,  2085,   473,   474,
     475,   476,   477,   478,   479,   480,   481,   482,   483,     0,
     667,     0,     0,   484,     0,   672,   674,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2178,     0,     0,   681,
     682,     0,   684,   685,   686,   687,   688,   689,   690,   691,
     692,   693,   694,   695,   696,   697,   698,   699,   700,   701,
     702,   703,   704,   705,  1158,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   719,     0,     0,
    1159,     0,     0,   725,     0,   727,  1790,     0,  1160,  1161,
    1162,     0,     0,   496,  1163,  1164,  1165,  1166,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   756,
     507,     0,   758,   759,   760,   761,   762,   763,   764,   765,
     766,   767,   768,   769,   770,   771,   772,     0,     0,   774,
     775,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   496,     0,   496,     0,     0,   631,     0,
       0,     0,     0,     0,   802,     0,     0,     0,     0,   807,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   819,   820,     0,     0,   496,  2163,     0,     0,   827,
     828,     0,     0,     0,   833,   835,   838,   841,   844,   846,
       0,   848,  1822,   850,     0,   507,   507,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   231,   232,
       0,     0,     0,   868,   869,   870,   452,   453,   871,     0,
       0,     0,   875,   876,   877,   878,   879,   880,   881,   882,
     883,     0,     0,     0,   888,     0,   890,   891,     0,     0,
       0,   507,   507,   507,  1860,     0,   898,   899,   900,   901,
     902,     0,     0,   909,   909,   914,   915,     0,   917,     0,
       0,   919,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   507,     0,     0,  1997,     0,     0,   934,   936,
       0,   938,   939,   470,   471,   472,   473,   474,   475,   476,
     477,   478,   479,   480,   481,   482,   483,     0,   507,     0,
       0,   484,     0,   901,   902,     0,   938,   939,     0,     0,
       0,     0,     0,     0,   386,     0,     0,   972,   507,     0,
       0,     0,   976,   400,   401,   402,   403,   404,   405,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,   416,
     417,   418,   419,   420,   421,   422,   423,   424,     0,  1158,
       0,   428,   429,   430,   431,     0,   433,   434,   435,   436,
     437,   438,     0,     0,   440,  1159,     0,     0,     0,     0,
     441,   442,     0,  1160,  1161,  1162,   447,   448,     0,  1163,
    1164,  1165,  1166,     0,     0,     0,     0,  1048,     0,   470,
     471,   472,   473,   474,   475,   476,   477,   478,   479,   480,
     481,   482,   483,     0,     0,  2069,     0,   484,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1075,
    1076,     0,     0,   507,  1082,  1083,     0,   507,  1086,     0,
       0,     0,     0,     0,     0,     0,  1093,     0,     0,   936,
    1096,   470,   471,   472,   473,   474,   475,   476,   477,   478,
     479,   480,   481,   482,   483,     0,     0,     0,     0,   484,
    1116,  2164,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1124,   470,   471,   472,   473,   474,   475,   476,   477,
     478,   479,   480,   481,   482,   483,     0,     0,     0,     0,
     484,     0,     0,     0,     0,     0,   507,     0,     0,     0,
       0,     0,     0,  1149,  1150,     0,  1158,     0,     0,  1153,
       0,   610,     0,     0,   613,   614,   615,   616,     0,     0,
       0,     0,  1159,     0,     0,     0,  1181,     0,     0,  1183,
    1160,  1161,  1162,     0,   641,     0,  1163,  1164,  1165,  1166,
       0,     0,     0,     0,     0,     0,     0,     0,   507,     0,
     507,     0,     0,   507,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   507,     0,   507,     0,
     507,     0,   507,     0,     0,     0,     0,   507,     0,     0,
       0,     0,   507,     0,     0,     0,     0,     0,  1224,     0,
    1226,  1227,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1234,   470,   471,   472,   473,   474,   475,   476,   477,
     478,   479,   480,   481,   482,   483,     0,     0,  2165,     0,
     484,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1256,     0,     0,     0,     0,     0,     0,
       0,  1257,  1258,  1259,     0,   507,     0,     0,     0,   749,
       0,     0,     0,  1262,     0,     0,     0,     0,     0,     0,
       0,     0,  1945,   636,     0,   509,     0,  1269,     0,     0,
     514,     0,  1272,     0,   518,     0,     0,     0,     0,     0,
       0,  1276,     0,     0,     0,     0,     0,  1284,   531,     0,
       0,     0,     0,     0,     0,     0,   528,   507,   507,   507,
     507,     0,     0,  1298,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   129,   374,     0,   548,   550,   552,   132,
     133,   134,   557,  1349,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,     0,     0,     0,
     591,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   507,     0,   167,   168,   169,   170,     0,     0,     0,
       0,   175,     0,  1354,     0,  1356,     0,  1358,     0,  1360,
       0,     0,   180,   181,   182,     0,     0,     0,     0,     0,
     183,  2050,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1379,     0,     0,     0,     0,     0,     0,   470,   471,
     472,   473,   474,   475,   476,   477,   478,   479,   480,   481,
     482,   483,     0,     0,   669,   670,   484,     0,     0,     0,
       0,     0,     0,     0,  1413,     0,     0,   678,     0,     0,
       0,     0,     0,  1418,  1419,     0,  1420,  1421,     0,  1422,
    1423,  1424,     0,     0,     0,     0,     0,  1429,   470,   471,
     472,   473,   474,   475,   476,   477,   478,   479,   480,   797,
     482,   483,     7,     8,     0,   716,   484,     0,     0,     0,
       0,     0,     0,     0,  1451,     0,     0,     0,     0,  1456,
       0,     0,   186,     0,     0,     0,   190,     0,   636,   757,
     191,   192,   193,   194,   195,     0,     0,     0,   104,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   198,   199,     0,     0,     0,   200,     0,     0,
       0,  1498,   337,     0,     0,     0,     0,   204,     0,   554,
       0,     0,  1507,  1508,   751,    24,    25,   752,    27,    28,
     753,    30,   754,    32,    33,    34,    35,  1517,  1519,     0,
      37,    38,    39,     0,    40,     0,     0,     0,     0,    45,
      46,    47,    48,     0,    50,    51,    52,     0,     0,     0,
      55,     0,     0,     0,   852,   853,     0,   470,   471,   472,
     473,   474,   475,   476,   477,   478,   479,   480,   481,   482,
     483,     0,     0,     0,     0,   484,     0,     0,     0,     0,
       0,  1568,  1569,  1570,     0,     0,     0,     0,     0,    81,
      82,    83,  1581,     0,  1583,     0,     0,     0,     0,     0,
     893,   894,   895,     0,     0,  1588,     0,     0,     0,     0,
       0,     7,     8,     0,     0,     0,     0,   507,     0,     0,
       0,     0,  1603,     0,     0,     0,     0,     0,   508,     0,
       0,   931,     0,   508,     0,     0,     0,   508,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1620,  1621,
    1622,   508,     0,     0,     0,     0,     0,   953,     0,     0,
     955,     0,     0,   470,   471,   472,   473,   474,   475,   476,
     477,   478,   479,   480,   637,   482,   483,   973,     0,     0,
    1642,   484,     0,   751,    24,    25,   752,    27,    28,   753,
      30,   754,    32,    33,    34,    35,     0,     0,     0,    37,
      38,    39,     0,    40,  1654,     0,     0,     0,    45,    46,
      47,    48,     0,    50,    51,    52,     0,     0,  1667,    55,
       0,     0,     0,  1673,     0,     0,     0,     0,     0,     0,
     632,     0,   508,     0,     0,     0,     0,     0,  1681,  1682,
       0,     0,     0,     0,     0,  1687,  1688,     0,     0,     0,
    1690,  1037,     0,     0,     0,  1043,     0,     0,    81,    82,
      83,     0,     0,     0,     0,  1697,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   507,   507,  1709,     0,  1710,
       0,     0,  1081,     0,     0,     0,  1085,     0,     0,     0,
       0,  1727,  1273,  1274,     0,     0,     0,     0,  1278,  1279,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   507,     0,     0,  1745,     0,     0,     0,     0,     0,
       0,  1748,  1749,  1750,  1751,  1752,  1753,  1754,     0,  1146,
       0,     0,     0,     0,     0,     0,     0,  1762,     0,     0,
       0,     0,     0,  1125,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1143,     0,  1782,     0,     0,
       0,     0,   508,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   636,     0,     0,     0,
    1797,  1798,     0,     0,     0,     0,     0,     0,  1804,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     632,     0,     0,     0,     0,     0,     0,  1195,     0,  1196,
       0,     0,  1198,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1210,  1825,  1211,     0,  1212,
       0,  1213,     0,     0,     0,     0,  1216,     0,     0,     0,
     949,  1219,     0,     0,  1839,     0,     0,   508,   508,     0,
       0,     0,     0,   631,   470,   471,   472,   473,   474,   475,
     476,   477,   478,   479,   480,   481,   482,   483,  1857,     0,
    1858,     0,   484,   507,     0,  1237,     0,     0,     0,  1241,
       0,  1059,     0,  1246,     0,     0,     0,     0,     0,     0,
    1872,     0,     0,   508,   508,   508,  1448,  1449,     0,     0,
       0,  1453,  1454,     0,  1260,   910,   912,     0,  1878,     0,
       0,     0,     0,  1882,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   508,     0,  1263,     0,     0,     0,
       0,   937,     0,   507,     0,     0,     0,     0,     0,     0,
    1909,     0,  1912,     0,  1915,     0,     0,     0,     0,     0,
     508,     0,     0,   507,     0,  1061,  1293,  1294,  1295,  1296,
       0,     0,     0,  1931,  1932,  1933,  1934,  1935,  1936,     0,
     508,   470,   471,   472,   473,   474,   475,   476,   477,   478,
     479,   480,   797,   482,   483,     0,     0,     0,     0,   484,
       0,  1950,  1951,     0,     0,     0,  1953,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1959,     0,
       0,     0,  1324,  1325,     0,  1327,     0,  1330,  1331,  1970,
    1345,  1334,  1335,  1336,  1337,  1338,  1339,  1340,  1341,     0,
       0,     0,     0,     0,  1346,   470,   471,   472,   473,   474,
     475,   476,   477,   478,   479,   480,   481,   482,   483,     0,
       0,     0,     0,   484,     0,  2001,     0,     0,     0,     0,
       0,  1673,     0,     0,     0,     0,     0,     0,     0,     0,
    2012,     0,     0,     0,     0,   508,     0,     0,     0,   508,
       0,     0,  1215,     0,  2023,     0,     0,  2027,     0,     0,
    2031,   937,  1097,     0,  2034,     0,     0,     0,     0,   507,
     507,   507,   507,   507,  2044,  2045,  2046,  2047,  2048,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2054,     0,
       0,  2056,  1437,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1432,  1433,  1434,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   508,  1446,
     470,   471,   472,   473,   474,   475,   476,   477,   478,   479,
     480,   481,   482,   483,     0,     0,     0,     0,   484,     0,
       0,  2092,   470,   471,   472,   473,   474,   475,   476,   477,
     478,   479,   480,   481,   482,   483,     0,     0,     0,   507,
     484,  2111,  2112,  2113,  2114,  2115,     0,  1714,     0,  1715,
     508,     0,   508,     0,     0,   508,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1510,     0,     0,   508,     0,
     508,     0,   508,     0,   508,     0,     0,     0,     0,   508,
       0,     0,     0,     0,   508,  2143,  2144,     0,     0,  1531,
       0,     0,     0,     0,     0,  1537,  2152,  2153,  2154,  2155,
       0,     0,     0,     0,     0,     0,     0,  1548,     0,     0,
    1551,  1552,     0,     0,     0,  1555,  1556,     0,  1557,     0,
    1558,     0,  1559,     0,  1560,  1561,  1562,   470,   471,   472,
     473,   474,   475,   476,   477,   478,   479,   480,   481,   482,
     483,     0,     0,  1582,     0,   484,     0,   508,     0,     0,
       0,     0,     0,     0,     0,     0,  1601,     0,  1592,     0,
       0,   941,     0,     0,     0,     0,  1600,   470,   471,   472,
     473,   474,   475,   476,   477,   478,   479,   480,   481,   482,
     483,     0,     0,     0,     0,   484,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   508,
     508,   508,   508,     0,   980,   981,   982,   983,   984,   985,
     986,   987,   988,   989,   990,     0,   992,   993,   994,   995,
     996,   997,   998,     0,     0,     0,  1002,  1004,  1005,     0,
     492,   131,  1009,  1010,     0,  1012,     0,     0,     0,     0,
    1017,  1018,  1019,     0,  1021,     0,     0,     0,     0,     0,
       0,  1029,  1031,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   508,     0,     0,     0,     0,  1665,  1054,
     158,   159,   160,   161,   162,   163,   164,   165,   166,     0,
       0,  1677,     0,   171,   172,   173,   174,     0,     0,     0,
       0,   176,   177,   178,     0,     0,   179,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   184,     0,     0,
       0,     0,     0,     0,  1707,  1708,   129,   130,   131,     0,
       0,     0,   132,   133,   134,     0,     0,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
       0,     0,     0,     0,     0,     0,  1510,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,     0,     0,     0,   176,   177,
     178,     0,  1755,   179,     0,   180,   181,   182,     0,     0,
       0,     0,  1767,   183,   184,     0,     0,   368,   131,     0,
       0,     0,  1774,     0,     0,     0,     0,  1779,     0,   187,
     188,   189,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   196,     0,   197,   104,   131,     0,     0,     0,     0,
       0,     0,     0,  1799,     0,     0,  1203,   158,   159,   160,
     161,   162,   163,   164,   165,   166,     0,     0,     0,     0,
     171,   172,   173,   174,     0,     0,  1510,     0,   176,   177,
     178,     0,     0,   179,   158,   159,   160,   161,   162,   163,
     164,   165,   166,     0,   184,     0,     0,   171,   172,   173,
     174,     0,     0,     0,     0,   176,   177,   178,   185,     0,
     179,     0,  1836,     0,     0,   186,   187,   188,   189,   190,
       0,   184,     0,   191,   192,   193,   194,   195,   196,     0,
     197,   104,  1859,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   198,   199,     0,     0,     0,
     200,     0,     0,     0,     0,   201,     0,   202,     0,   203,
     204,     0,   205,     0,   206,     0,     0,     0,     0,   508,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1510,     0,     0,     0,     0,     0,     0,
    1887,  1888,  1905,     0,     0,     0,   187,   188,   189,     0,
    1297,  1510,     0,     0,     0,     0,     0,     0,   196,     0,
     197,     0,  1925,     0,     0,     0,     0,     0,     0,     0,
    1921,     0,     0,   187,   188,   189,     0,     0,     0,     0,
       0,     0,     0,  1319,  1320,   196,     0,   197,     0,     0,
       0,     0,     0,   129,   374,   131,     0,     0,     0,   132,
     133,   134,     0,     0,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,     0,     0,     0,
       0,     0,     0,  1963,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,  1980,     0,     0,   176,   177,   178,     0,     0,
     179,     0,   180,   181,   182,     0,     0,     0,     0,     0,
     183,   184,     0,     0,     0,     0,     0,   508,   508,   470,
     471,   472,   473,   474,   475,   476,   477,   478,   479,   480,
     481,   482,   483,     0,     0,     0,     0,   484,     0,     0,
       0,     0,     0,     0,  1756,     0,  1757,     0,  2038,  2039,
    2040,  2041,  2043,   508,     0,     0,     0,   470,   471,   472,
     473,   474,   475,   476,   477,   478,   479,   480,   481,   482,
     483,     0,     0,     0,     0,   484,     0,     0,     0,     0,
    1458,  1510,  1907,     0,  1908,     0,  1462,  1463,  1464,  1465,
    1466,     0,  1469,     0,  1471,  1472,     0,  1475,  1478,     7,
       8,  1482,  1483,  1484,     0,     0,     0,     0,  1488,     0,
       0,     0,   186,   187,   188,   189,   190,     0,     0,     0,
     191,   192,   193,   194,   195,   196,     0,   197,   104,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2109,     0,
       0,     0,   198,   199,     0,     0,     0,   200,     0,     0,
       0,     0,   337,     0,     0,     0,     0,   204,     0,  1518,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   751,    24,    25,   752,    27,    28,   753,    30,   754,
      32,    33,    34,    35,     0,     0,     0,    37,    38,    39,
       0,    40,     0,  1510,     0,   632,    45,    46,    47,    48,
       0,    50,    51,    52,     0,     0,     0,    55,     0,     0,
       0,     0,     0,     0,     0,   508,   470,   471,   472,   473,
     474,   475,   476,   477,   478,   479,   480,   481,   482,   483,
       0,     0,  1873,     0,   484,     0,     0,     0,     0,     0,
       0,     0,     0,  1118,     0,  1606,    81,    82,    83,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1616,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   508,     0,     0,  1631,     0,
       0,     0,     0,  1635,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   508,   470,   471,   472,   473,
     474,   475,   476,   477,   478,   479,   480,   481,   482,   483,
       0,     0,     0,     0,   484,  1648,  1649,  1147,     0,  1651,
    1652,     0,     0,  1173,     0,     0,     0,     0,   129,   324,
       0,     0,     0,     0,   132,   133,   134,     0,     0,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   167,   168,
     169,   170,     0,     0,     0,     0,   175,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   180,   181,   182,
       0,     0,     7,     8,     0,   183,     0,     0,     0,   331,
       0,     0,   332,     0,     0,   333,     0,   334,     0,     0,
       0,     0,     0,     0,    36,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     335,   508,   508,   508,   508,   508,     0,    57,    58,    59,
      60,    61,     0,     0,    63,    64,    65,    66,    67,     0,
       0,    70,  1769,  1770,    73,     0,  1772,  1773,     0,     0,
       0,     0,  1776,  1777,   751,    24,    25,   752,    27,    28,
     753,    30,   754,    32,    33,    34,    35,     0,     0,     0,
      37,    38,    39,     0,    40,     0,     0,     0,     0,    45,
      46,    47,    48,     0,    50,    51,    52,   186,     0,     0,
      55,   190,     0,     0,     0,   191,   192,   193,   194,   195,
       0,     0,     0,   104,     0,     0,     0,   959,     0,     0,
       0,   508,     0,     0,     0,     0,     0,   574,  1741,     0,
       0,     0,   200,     0,     0,     0,     0,   576,     0,    81,
      82,    83,   204,     0,   287,   634,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   129,
     324,     0,     0,     0,     0,   132,   133,   134,  1849,  1850,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   326,   327,   328,   329,   330,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   167,
     168,   169,   170,     0,     0,     0,     0,   175,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   180,   181,
     182,     0,     7,     8,     0,     0,   183,     0,     0,     0,
     331,     0,     0,   332,     0,     0,   333,     0,   334,     0,
       0,     0,     0,     0,     0,    36,   470,   471,   472,   473,
     474,   475,   476,   477,   478,   479,   480,   481,   482,   483,
       0,   335,     0,     0,   484,     0,     0,     0,    57,    58,
      59,    60,    61,  1206,     0,    63,    64,    65,    66,    67,
       0,     0,    70,     0,     0,    73,     0,     0,     0,     0,
       0,     0,     0,     0,   751,    24,    25,   752,    27,    28,
     753,    30,   754,    32,    33,    34,    35,     0,     0,     0,
      37,    38,    39,     0,    40,     0,     0,     0,     0,    45,
      46,    47,    48,     0,    50,    51,    52,     0,   186,     0,
      55,     0,   190,     0,     0,     0,   191,   192,   193,   194,
     195,     0,     0,     0,   104,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   198,   506,
       0,     0,     0,   200,     0,     0,     0,     0,   337,    81,
      82,    83,     0,   204,     0,     0,   634,   129,   324,   131,
       0,     0,     0,   132,   133,   134,     0,     0,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   326,   327,   328,   329,   330,     0,     0,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,     0,     0,     0,   176,
     177,   178,     0,     0,   179,     0,   180,   181,   182,     0,
       0,     0,     0,     0,   183,   184,     0,     0,   331,     0,
       0,   332,     0,     0,   333,     0,   334,     0,     0,     0,
       0,     0,     0,    36,   470,   471,   472,   473,   474,   475,
     476,   477,   478,   479,   480,   481,   482,   483,     0,   335,
       0,     0,   484,     0,     0,     0,    57,    58,    59,    60,
      61,  1249,     0,    63,    64,    65,    66,    67,     0,     0,
      70,     0,     0,    73,     0,     0,     0,     0,     0,     0,
       0,  2133,   470,   471,   472,   473,   474,   475,   476,   477,
     478,   479,   480,   481,   482,   483,     0,     0,     0,     0,
     484,     0,     0,     0,     0,     0,     0,     0,     0,  1372,
       0,     0,     0,     0,     0,     0,   186,   187,   188,   189,
     190,     0,     0,     0,   191,   192,   193,   194,   195,   196,
       0,   197,   104,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   198,   336,     0,     0,
       0,   200,     0,     0,     0,     0,   337,     0,   129,   324,
     131,   204,     0,   338,   132,   133,   134,     0,     0,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   326,   327,   328,   329,   330,     0,     0,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,     0,     0,     0,
     176,   177,   178,     0,     0,   179,     0,   180,   181,   182,
       0,     0,     0,     0,     0,   183,   184,     0,     0,   331,
       0,     0,   332,     0,     0,   333,     0,   334,     0,     0,
       0,     0,     0,     0,    36,   470,   471,   472,   473,   474,
     475,   476,   477,   478,   479,   480,   481,   482,   483,     0,
     335,     0,     0,   484,     0,     0,     0,    57,    58,    59,
      60,    61,  1712,     0,    63,    64,    65,    66,    67,     0,
       0,    70,     0,     0,    73,   470,   471,   472,   473,   474,
     475,   476,   477,   478,   479,   480,   481,   482,   483,     0,
       0,     0,     0,   484,     0,     0,     0,     0,     0,     0,
       0,     0,  1731,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   186,   187,   188,
     189,   190,     0,     0,     0,   191,   192,   193,   194,   195,
     196,     0,   197,   104,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   198,   336,     0,
       0,     0,   200,     0,     0,     0,     0,   337,     0,   129,
     324,   325,   204,     0,  1778,   132,   133,   134,     0,     0,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   326,   327,   328,   329,   330,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   167,
     168,   169,   170,     0,     0,     0,     0,   175,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   180,   181,
     182,     0,     0,     0,     0,     0,   183,     0,     0,     0,
     331,     0,     0,   332,     0,     0,   333,     0,   334,     0,
       0,     0,     0,     0,     0,    36,   470,   471,   472,   473,
     474,   475,   476,   477,   478,   479,   480,   481,   482,   483,
       0,   335,     0,     0,   484,     0,     0,     0,    57,    58,
      59,    60,    61,  1809,     0,    63,    64,    65,    66,    67,
       0,     0,    70,     0,     0,    73,   470,   471,   472,   473,
     474,   475,   476,   477,   478,   479,   480,   481,   482,   483,
       0,     0,     0,     0,   484,     0,     0,     0,     0,     0,
       0,     0,     0,  1810,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   186,     0,
       0,     0,   190,     0,     0,     0,   191,   192,   193,   194,
     195,     0,     0,     0,   104,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   198,   336,
       0,     0,     0,   200,     0,     0,     0,     0,   337,     0,
     129,   324,  1591,   204,     0,   338,   132,   133,   134,     0,
       0,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     167,   168,   169,   170,     0,     0,     0,     0,   175,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   180,
     181,   182,     0,     0,     0,     0,     0,   183,     0,     0,
       0,   331,     0,     0,   332,     0,     0,   333,     0,   334,
       0,     0,     0,     0,     0,     0,    36,   470,   471,   472,
     473,   474,   475,   476,   477,   478,   479,   480,   481,   482,
     483,     0,   335,     0,     0,   484,     0,     0,     0,    57,
      58,    59,    60,    61,  1811,     0,    63,    64,    65,    66,
      67,     0,     0,    70,     0,     0,    73,   470,   471,   472,
     473,   474,   475,   476,   477,   478,   479,   480,   481,   482,
     483,     0,     0,     0,     0,   484,     0,     0,     0,     0,
       0,     0,     0,     0,  1812,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   186,
       0,     0,     0,   190,     0,     0,     0,   191,   192,   193,
     194,   195,     0,     0,     0,   104,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   198,
     336,     0,     0,     0,   200,     0,     0,     0,     0,   337,
       0,   129,   374,   131,   204,     0,   338,   132,   133,   134,
       0,     0,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,     0,     0,     0,     0,     0,
       0,     0,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
       0,     0,     0,   176,   177,   178,     0,     0,   179,     0,
     180,   181,   182,     0,   129,   374,   131,     0,   183,   184,
     132,   133,   134,     0,     0,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,     0,     0,
       0,     0,     0,     0,     0,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,     0,     0,     0,   176,   177,   178,     0,
       0,   179,     0,   180,   181,   182,     0,     0,     0,     0,
       0,   183,   184,     0,     0,     0,     0,     0,   470,   471,
     472,   473,   474,   475,   476,   477,   478,   479,   480,   481,
     482,   483,     0,     0,     0,     0,   484,     0,     0,     0,
     186,   187,   188,   189,   190,  1813,     0,     0,   191,   192,
     193,   194,   195,   196,     0,   197,   104,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     198,   199,     0,     0,     0,   200,     0,     0,     0,     0,
     337,     0,     0,     0,     0,   204,     0,  1761,     0,     0,
       0,   470,   471,   472,   473,   474,   475,   476,   477,   478,
     479,   480,   481,   482,   483,     0,     0,     0,     0,   484,
       0,     0,     0,   186,   187,   188,   189,   190,  1848,     0,
       0,   191,   192,   193,   194,   195,   196,     0,   197,   104,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   198,   199,     0,     0,     0,   200,     0,
       0,     0,     0,   337,     0,   129,   324,     0,   204,     0,
    1781,   132,   133,   134,     0,     0,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   326,
     327,   328,   329,   330,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   167,   168,   169,   170,     0,
       0,     0,     0,   175,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   180,   181,   182,     0,     0,     0,
       0,     0,   183,     0,     0,     0,   331,     0,     0,   332,
       0,     0,   333,     0,   334,     0,     0,     0,     0,     0,
       0,    36,   470,   471,   472,   473,   474,   475,   476,   477,
     478,   479,   480,   481,   482,   483,     0,   335,     0,     0,
     484,     0,     0,     0,    57,    58,    59,    60,    61,  1923,
       0,    63,    64,    65,    66,    67,     0,     0,    70,     0,
       0,    73,   470,   471,   472,   473,   474,   475,   476,   477,
     478,   479,   480,   481,   482,   483,     0,     0,     0,     0,
     484,     0,     0,     0,     0,     0,     0,     0,     0,  1937,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   186,     0,     0,     0,   190,     0,
       0,     0,   191,   192,   193,   194,   195,     0,     0,     0,
     104,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   198,   336,     0,     0,     0,   200,
       0,     0,     0,     0,   337,     0,   129,   324,     0,   204,
       0,   338,   132,   133,   134,     0,     0,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   167,   168,   169,   170,
       0,     0,     0,     0,   175,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   180,   181,   182,     0,     0,
       0,     0,     0,   183,     0,     0,     0,   331,     0,     0,
     332,     0,     0,   333,     0,   334,     0,     0,     0,     0,
       0,     0,    36,   470,   471,   472,   473,   474,   475,   476,
     477,   478,   479,   480,   481,   482,   483,     0,   335,     0,
       0,   484,     0,     0,     0,    57,    58,    59,    60,    61,
    1938,     0,    63,    64,    65,    66,    67,     0,     0,    70,
       0,     0,    73,   470,   471,   472,   473,   474,   475,   476,
     477,   478,   479,   480,   481,   482,   483,     0,     0,     0,
       0,   484,     0,     0,     0,     0,     0,     0,     0,     0,
    1971,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   186,     0,     0,     0,   190,
       0,     0,     0,   191,   192,   193,   194,   195,     0,     0,
       0,   104,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   198,   336,     0,     0,     0,
     200,     0,     0,     0,     0,   547,     0,   129,   324,     0,
     204,     0,   338,   132,   133,   134,     0,     0,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   326,   327,   328,   329,   330,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   167,   168,   169,
     170,     0,     0,     0,     0,   175,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   180,   181,   182,     0,
       0,     0,     0,     0,   183,     0,     0,     0,   331,     0,
       0,   332,     0,     0,   333,     0,   334,     0,     0,     0,
       0,     0,     0,    36,   470,   471,   472,   473,   474,   475,
     476,   477,   478,   479,   480,   481,   482,   483,     0,   335,
       0,     0,   484,     0,     0,     0,    57,    58,    59,    60,
      61,  1974,     0,    63,    64,    65,    66,    67,     0,     0,
      70,     0,     0,    73,   470,   471,   472,   473,   474,   475,
     476,   477,   478,   479,   480,   481,   482,   483,     0,     0,
       0,     0,   484,     0,     0,     0,     0,     0,     0,     0,
       0,  1977,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   186,     0,     0,     0,
     190,     0,     0,     0,   191,   192,   193,   194,   195,     0,
       0,     0,   104,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   198,   336,     0,     0,
       0,   200,     0,     0,     0,     0,   549,     0,   129,   324,
       0,   204,     0,   338,   132,   133,   134,     0,     0,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   167,   168,
     169,   170,     0,     0,     0,     0,   175,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   180,   181,   182,
       0,     0,     0,     0,     0,   183,     0,     0,     0,   331,
       0,     0,   332,     0,     0,   333,     0,   334,     0,     0,
       0,     0,     0,     0,    36,   470,   471,   472,   473,   474,
     475,   476,   477,   478,   479,   480,   481,   482,   483,     0,
     335,     0,     0,   484,     0,     0,     0,    57,    58,    59,
      60,    61,  2013,     0,    63,    64,    65,    66,    67,     0,
       0,    70,     0,     0,    73,   470,   471,   472,   473,   474,
     475,   476,   477,   478,   479,   480,   481,   482,   483,     0,
       0,     0,     0,   484,     0,     0,     0,     0,     0,     0,
       0,     0,  2020,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   186,     0,     0,
       0,   190,     0,     0,     0,   191,   192,   193,   194,   195,
       0,     0,     0,   104,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   198,   336,     0,
       0,     0,   200,     0,     0,     0,     0,   551,     0,   129,
     324,     0,   204,     0,   338,   132,   133,   134,     0,     0,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   326,   327,   328,   329,   330,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   167,
     168,   169,   170,     0,     0,     0,     0,   175,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   180,   181,
     182,     0,     0,     0,     0,     0,   183,     0,     0,     0,
     331,     0,     0,   332,     0,     0,   333,     0,   334,     0,
       0,     0,     0,     0,     0,    36,   470,   471,   472,   473,
     474,   475,   476,   477,   478,   479,   480,   481,   482,   483,
       0,   335,     0,     0,   484,     0,     0,     0,    57,    58,
      59,    60,    61,  2063,     0,    63,    64,    65,    66,    67,
       0,     0,    70,     0,     0,    73,   470,   471,   472,   473,
     474,   475,   476,   477,   478,   479,   480,   481,   482,   483,
       0,     0,     0,     0,   484,     0,     0,     0,     0,     0,
       0,     0,     0,  2065,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   186,     0,
       0,     0,   190,     0,     0,     0,   191,   192,   193,   194,
     195,     0,     0,     0,   104,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   198,   506,
       0,     0,     0,   200,     0,     0,     0,     0,   337,     0,
     129,   324,     0,   204,     0,   630,   132,   133,   134,     0,
       0,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     167,   168,   169,   170,     0,     0,     0,     0,   175,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   180,
     181,   182,     0,     0,     0,     0,     0,   183,     0,     0,
       0,   331,     0,     0,   332,     0,     0,   333,     0,   334,
       0,     0,     0,     0,     0,     0,    36,   470,   471,   472,
     473,   474,   475,   476,   477,   478,   479,   480,   481,   482,
     483,     0,   335,     0,     0,   484,     0,     0,     0,    57,
      58,    59,    60,    61,  2067,     0,    63,    64,    65,    66,
      67,     0,     0,    70,     0,     0,    73,   470,   471,   472,
     473,   474,   475,   476,   477,   478,   479,   480,   481,   482,
     483,     0,     0,     0,     0,   484,     0,     0,     0,     0,
       0,     0,     0,     0,  2091,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   186,
       0,     0,     0,   190,     0,     0,     0,   191,   192,   193,
     194,   195,     0,     0,     0,   104,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   198,
     506,     0,     0,     0,   200,     0,     0,     0,     0,   337,
       0,   129,   324,     0,   204,     0,   908,   132,   133,   134,
       0,     0,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   326,   327,   328,   329,   330,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   167,   168,   169,   170,     0,     0,     0,     0,   175,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     180,   181,   182,     0,     0,     0,     0,     0,   183,     0,
       0,     0,   331,     0,     0,   332,     0,     0,   333,     0,
     334,     0,     0,     0,     0,     0,     0,    36,   470,   471,
     472,   473,   474,   475,   476,   477,   478,   479,   480,   481,
     482,   483,     0,   335,     0,     0,   484,     0,     0,     0,
      57,    58,    59,    60,    61,  2122,     0,    63,    64,    65,
      66,    67,     0,     0,    70,     0,     0,    73,   470,   471,
     472,   473,   474,   475,   476,   477,   478,   479,   480,   481,
     482,   483,     0,     0,     0,     0,   484,     0,     0,     0,
       0,     0,     0,     0,     0,  2161,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     186,     0,     0,     0,   190,     0,     0,     0,   191,   192,
     193,   194,   195,     0,     0,     0,   104,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     198,   506,     0,     0,     0,   200,     0,     0,     0,     0,
     337,     0,   129,   324,     0,   204,     0,   911,   132,   133,
     134,     0,     0,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   167,   168,   169,   170,     0,     0,     0,     0,
     175,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   180,   181,   182,     0,     0,     0,     0,     0,   183,
       0,     0,     0,   331,     0,     0,   332,     0,     0,   333,
       0,   334,     0,     0,     0,     0,     0,     0,    36,   470,
     471,   472,   473,   474,   475,   476,   477,   478,   479,   480,
     481,   482,   483,     0,   335,     0,     0,   484,     0,     0,
       0,    57,    58,    59,    60,    61,  2162,     0,    63,    64,
      65,    66,    67,     0,     0,    70,     0,     0,    73,   470,
     471,   472,   473,   474,   475,   476,   477,   478,   479,   480,
     481,   482,   483,     0,     0,     0,     0,   484,     0,     0,
       0,     0,     0,     0,     0,     0,  2166,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   186,     0,     0,     0,   190,     0,     0,     0,   191,
     192,   193,   194,   195,     0,     0,     0,   104,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   198,   506,     0,     0,     0,   200,     0,     0,     0,
       0,   337,     0,   129,   324,     0,   204,     0,   935,   132,
     133,   134,     0,     0,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   326,   327,   328,
     329,   330,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   167,   168,   169,   170,     0,     0,     0,
       0,   175,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   180,   181,   182,     0,     0,     0,     0,     0,
     183,     0,     0,     0,   331,     0,     0,   332,     0,     0,
     333,     0,   334,     0,     0,     0,     0,     0,     0,    36,
     470,   471,   472,   473,   474,   475,   476,   477,   478,   479,
     480,   481,   482,   483,     0,   335,     0,     0,   484,     0,
       0,     0,    57,    58,    59,    60,    61,  2167,     0,    63,
      64,    65,    66,    67,     0,     0,    70,     0,     0,    73,
     470,   471,   472,   473,   474,   475,   476,   477,   478,   479,
     480,   481,   482,   483,     0,     0,     0,     0,   484,     0,
       0,     0,     0,     0,     0,     0,     0,  2168,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   186,     0,     0,     0,   190,     0,     0,     0,
     191,   192,   193,   194,   195,     0,     0,     0,   104,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   198,   336,     0,     0,     0,   200,     0,     0,
       0,     0,   337,     0,   129,   324,     0,   204,     0,  1599,
     132,   133,   134,     0,     0,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   167,   168,   169,   170,     0,     0,
       0,     0,   175,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   180,   181,   182,     0,     0,     0,     0,
       0,   183,     0,     0,     0,   331,     0,     0,   332,     0,
       0,   333,     0,   334,     0,     0,     0,     0,     0,     0,
      36,   470,   471,   472,   473,   474,   475,   476,   477,   478,
     479,   480,   481,   482,   483,     0,   335,     0,     0,   484,
       0,     0,     0,    57,    58,    59,    60,    61,  2169,     0,
      63,    64,    65,    66,    67,     0,     0,    70,     0,     0,
      73,   470,   471,   472,   473,   474,   475,   476,   477,   478,
     479,   480,   481,   482,   483,     0,     0,     0,     0,   484,
       0,     0,     0,     0,     0,     0,     0,   663,   470,   471,
     472,   473,   474,   475,   476,   477,   478,   479,   480,   481,
     482,   483,     0,   186,     0,     0,   484,   190,   904,     0,
     905,   191,   192,   193,   194,   195,     0,     0,     0,   104,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   574,  1741,     0,     0,     0,   200,     0,
       0,     0,     0,   576,     0,   129,   374,     0,   204,     0,
     287,   132,   133,   134,     0,     0,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,     0,
       0,   470,   471,   472,   473,   474,   475,   476,   477,   478,
     479,   480,   481,   482,   483,   167,   168,   169,   170,   484,
       0,     0,     0,   175,     0,     0,     0,   854,     0,     0,
       0,     0,     0,     0,   180,   181,   182,   129,   374,   131,
       0,     0,   183,   132,   133,   134,     0,     0,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,     0,     0,     0,     0,     0,     0,     0,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,     0,     0,     0,   176,
     177,   178,     0,     0,   179,     0,   180,   181,   182,     0,
       0,     0,     0,     0,   183,   184,   470,   471,   472,   473,
     474,   475,   476,   477,   478,   479,   480,   481,   482,   483,
       0,     0,     0,     0,   484,     0,     0,     0,     0,     0,
       0,     0,  1821,     0,   186,     0,     0,     0,   190,     0,
       0,     0,   191,   192,   193,   194,   195,     0,     0,     0,
     104,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   574,   575,     0,     0,     0,   200,
       0,     0,     0,     0,   576,     0,     0,     0,     0,   204,
       0,   287,     0,     0,     0,     0,   470,   471,   472,   473,
     474,   475,   476,   477,   478,   479,   480,   481,   482,   483,
       0,     0,     0,     0,   484,     0,   186,   187,   188,   189,
     190,   786,     0,     0,   191,   192,   193,   194,   195,   196,
       0,   197,   104,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   198,   199,     0,     0,
       0,   200,   129,   324,     0,     0,   337,     0,   132,   133,
     134,   204,     0,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   167,   168,   169,   170,     0,     0,     0,     0,
     175,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   180,   181,   182,     0,     0,     0,     0,     0,   183,
       0,     0,     0,   331,     0,     0,   332,     0,     0,   333,
       0,   334,     0,     0,     0,     0,     0,     0,    36,   470,
     471,   472,   473,   474,   475,   476,   477,   478,   479,   480,
     481,   482,   483,     0,   335,     0,     0,   484,     0,   739,
       0,    57,    58,    59,    60,    61,     0,     0,    63,    64,
      65,    66,    67,     0,     0,    70,     0,     0,    73,   470,
     471,   472,   473,   474,   475,   476,   477,   478,   479,   480,
     481,   482,   483,     0,     0,     0,     0,   484,     0,   904,
       0,   905,     0,     0,  1468,   470,   471,   472,   473,   474,
     475,   476,   477,   478,   479,   480,   481,   482,   483,     0,
       0,   186,     0,   484,     0,   190,     0,   743,     0,   191,
     192,   193,   194,   195,     0,     0,     0,   104,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   198,   506,     0,     0,     0,   200,   129,   374,     0,
       0,   337,     0,   132,   133,   134,   204,     0,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,     0,     0,   470,   471,   472,   473,   474,   475,   476,
     477,   478,   479,   480,   481,   482,   483,   167,   168,   169,
     170,   484,     0,   932,     0,   175,     0,     0,   861,     0,
       0,     0,     0,     0,   129,   374,   180,   181,   182,     0,
     132,   133,   134,     0,   183,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,     0,     0,
     470,   471,   472,   473,   474,   475,   476,   477,   478,   479,
     480,   481,   482,   483,   167,   168,   169,   170,   484,     0,
       0,     0,   175,     0,     0,   861,     0,     0,     0,     0,
       0,     0,     0,   180,   181,   182,     0,     0,     0,     0,
       0,   183,   470,   471,   472,   473,   474,   475,   476,   477,
     478,   479,   480,   481,   482,   483,     0,     0,     0,     0,
     484,     0,     0,     0,     0,     0,     0,   862,     0,     0,
       0,     0,     0,     0,     0,     0,   186,     0,     0,     0,
     190,     0,     0,     0,   191,   192,   193,   194,   195,     0,
       0,     0,   104,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   198,   199,     0,     0,
       0,   200,     0,     0,     0,     0,   337,   455,     0,     0,
       0,   204,     0,   470,   471,   472,   473,   474,   475,   476,
     477,   478,   479,   480,   481,   482,   483,     0,     0,     0,
       0,   484,     0,   186,     0,     0,     0,   190,   946,     0,
       0,   191,   192,   193,   194,   195,     0,     0,     0,   104,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   198,   199,     0,     0,     0,   200,     0,
       0,     0,     0,   337,   129,   374,   457,     0,   204,     0,
     132,   133,   134,     0,     0,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,     0,     0,
     470,   471,   472,   473,   474,   475,   476,   477,   478,   479,
     480,   481,   482,   483,   167,   168,   169,   170,   484,     0,
       0,     0,   175,     0,     0,   991,     0,     0,     0,     0,
       0,   129,   374,   180,   181,   182,     0,   132,   133,   134,
       0,   183,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,     0,     0,   470,   471,   472,
     473,   474,   475,   476,   477,   478,   479,   480,   481,   482,
     483,   167,   168,   169,   170,   484,     0,     0,     0,   175,
       0,     0,   999,     0,     0,     0,     0,     0,     0,     0,
     180,   181,   182,     0,     0,     0,     0,     0,   183,   470,
     471,   472,   473,   474,   475,   476,   477,   478,   479,   480,
     481,   482,   483,     0,     0,     0,     0,   484,     0,     0,
       0,     0,     0,     0,  1000,     0,     0,     0,     0,     0,
       0,     0,     0,   186,     0,     0,     0,   190,     0,     0,
       0,   191,   192,   193,   194,   195,     0,     0,     0,   104,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   198,   199,     0,     0,     0,   200,     0,
       0,     0,     0,   337,   671,     0,     0,     0,   204,     0,
     470,   471,   472,   473,   474,   475,   476,   477,   478,   479,
     480,   481,   482,   483,     0,     0,     0,     0,   484,     0,
     186,     0,     0,     0,   190,  1001,     0,     0,   191,   192,
     193,   194,   195,     0,     0,     0,   104,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     198,   199,     0,     0,     0,   200,     0,     0,     0,     0,
     337,   129,   374,   673,  1233,   204,     0,   132,   133,   134,
       0,     0,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,     0,     0,   470,   471,   472,
     473,   474,   475,   476,   477,   478,   479,   480,   481,   482,
     483,   167,   168,   169,   170,   484,     0,     0,     0,   175,
       0,     0,  1016,     0,     0,     0,     0,     0,     0,     0,
     180,   181,   182,   129,   374,     0,  1378,     0,   183,   132,
     133,   134,     0,     0,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,     0,     0,   470,
     471,   472,   473,   474,   475,   476,   477,   478,   479,   480,
     481,   482,   483,   167,   168,   169,   170,   484,     0,     0,
       0,   175,     0,     0,  1155,     0,     0,     0,     0,     0,
       0,     0,   180,   181,   182,     0,     0,     0,     0,     0,
     183,   470,   471,   472,   473,   474,   475,   476,   477,   478,
     479,   480,   481,   482,   483,     0,     0,     0,     0,   484,
       0,     0,     0,     0,     0,     0,  1156,     0,     0,     0,
     186,     0,     0,     0,   190,     0,     0,     0,   191,   192,
     193,   194,   195,     0,     0,     0,   104,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     198,   199,     0,     0,     0,   200,     0,     0,     0,     0,
     337,     0,     0,     0,     0,   204,   470,   471,   472,   473,
     474,   475,   476,   477,   478,   479,   480,   481,   482,   483,
       0,     0,     0,     0,   484,     0,     0,     0,     0,     0,
       0,  1157,   186,     0,     0,     0,   190,     0,     0,     0,
     191,   192,   193,   194,   195,     0,     0,     0,   104,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   198,   199,     0,     0,     0,   200,   129,   374,
       0,     0,   337,     0,   132,   133,   134,   204,     0,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,     0,     0,     0,     7,     8,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   167,   168,
     169,   170,     0,     0,     0,     0,   175,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   180,   181,   182,
       0,     0,     7,     8,     0,   183,   470,   471,   472,   473,
     474,   475,   476,   477,   478,   479,   480,   481,   482,   483,
       0,     0,     0,     0,   484,     0,     0,     0,     0,     0,
       0,  1192,     0,     0,     0,     0,     0,   751,    24,    25,
     752,    27,    28,   753,    30,   754,    32,    33,    34,    35,
       0,     0,     0,    37,    38,    39,     0,    40,     0,     0,
       0,     0,    45,    46,    47,    48,     0,    50,    51,    52,
       0,     0,     0,    55,   751,    24,    25,   752,    27,    28,
     753,    30,   754,    32,    33,    34,    35,     7,     8,     0,
      37,    38,    39,     0,    40,     0,     0,     0,     0,    45,
      46,    47,    48,     0,    50,    51,    52,   186,     0,     0,
      55,   190,    81,    82,    83,   191,   192,   193,   194,   195,
       0,     0,     0,   104,     7,     8,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   198,   199,     0,
       0,     0,   200,     0,     0,     0,     0,   337,     0,    81,
      82,    83,   204,     0,     0,     0,     0,     0,     0,   751,
      24,    25,   752,    27,    28,   753,    30,   754,    32,    33,
      34,    35,     0,     0,     0,    37,    38,    39,     0,    40,
       0,     0,     0,  1170,    45,    46,    47,    48,     0,    50,
      51,    52,     0,     0,     0,    55,   751,    24,    25,   752,
      27,    28,   753,    30,   754,    32,    33,    34,    35,     7,
       8,     0,    37,    38,    39,     0,    40,     0,     0,     0,
    1225,    45,    46,    47,    48,     0,    50,    51,    52,     0,
       0,     0,    55,     0,    81,    82,    83,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     7,     8,     0,   470,
     471,   472,   473,   474,   475,   476,   477,   478,   479,   480,
     481,   482,   483,     0,     0,     0,     0,   484,     0,     0,
       0,    81,    82,    83,  1201,     0,     0,     0,     0,     0,
       0,   751,    24,    25,   752,    27,    28,   753,    30,   754,
      32,    33,    34,    35,     0,     0,     0,    37,    38,    39,
       0,    40,     0,     0,     0,  1231,    45,    46,    47,    48,
       0,    50,    51,    52,     0,     0,     0,    55,   751,    24,
      25,   752,    27,    28,   753,    30,   754,    32,    33,    34,
      35,     0,     0,     0,    37,    38,    39,     0,    40,     0,
       0,     0,  1368,    45,    46,    47,    48,     0,    50,    51,
      52,     0,     0,     0,    55,     0,    81,    82,    83,     0,
       0,    -4,     1,     0,     0,    -4,     0,     0,     0,     0,
       0,     0,     0,    -4,    -4,     0,     0,     0,   470,   471,
     472,   473,   474,   475,   476,   477,   478,   479,   480,   481,
     482,   483,     0,    81,    82,    83,   484,     0,     0,     0,
     952,     0,     0,    -4,    -4,     0,     0,     0,   470,   471,
     472,   473,   474,   475,   476,   477,   478,   479,   480,   481,
     482,   483,     0,    -4,    -4,    -4,   484,  1983,     0,    -4,
      -4,     0,    -4,  1202,     0,     0,    -4,    -4,     0,    -4,
      -4,     0,     0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,     0,
      -4,    -4,    -4,    -4,  2071,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,     0,     0,     0,    -4,    -4,    -4,     0,
       0,     0,     0,     0,    -4,     6,     0,     0,     0,    -4,
      -4,    -4,    -4,     7,     8,    -4,     0,    -4,     0,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,     0,     0,     0,     0,     0,    -4,    -4,
      -4,     0,     0,     9,    10,     0,     0,    -4,     0,    -4,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    11,    12,    13,     0,     0,     0,    14,
      15,     0,    16,     0,     0,     0,    17,    18,     0,    19,
      20,     0,     0,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,     0,     0,
      36,    37,    38,    39,     0,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,     0,
      54,    55,    56,    57,    58,    59,    60,    61,    62,     0,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,     0,     0,     0,    76,    77,    78,     0,
       0,     0,     0,     0,    79,     0,     0,     0,     0,    80,
      81,    82,    83,     0,     0,    84,     0,    85,     0,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,     0,     0,     0,     0,     0,   100,   101,
     102,     0,     0,     0,     0,     0,     0,   103,     0,   104,
     470,   471,   472,   473,   474,   475,   476,   477,   478,   479,
     480,   481,   482,   483,     0,     0,     0,     0,   484,     0,
       0,     0,     0,     0,     0,  1204,   470,   471,   472,   473,
     474,   475,   476,   477,   478,   479,   480,   481,   482,   483,
       0,     0,     0,     0,   484,     0,     0,     0,     0,     0,
       0,  1315,   470,   471,   472,   473,   474,   475,   476,   477,
     478,   479,   480,   481,   482,   483,     0,     0,     0,     0,
     484,     0,     0,     0,     0,     0,     0,  1370,   470,   471,
     472,   473,   474,   475,   476,   477,   478,   479,   480,   481,
     482,   483,     0,     0,     0,     0,   484,     0,     0,     0,
       0,     0,     0,  1371,   470,   471,   472,   473,   474,   475,
     476,   477,   478,   479,   480,   481,   482,   483,     0,     0,
       0,     0,   484,     0,     0,     0,     0,     0,     0,  1436,
     470,   471,   472,   473,   474,   475,   476,   477,   478,   479,
     480,   481,   482,   483,     0,     0,     0,     0,   484,     0,
       0,     0,     0,     0,     0,  1609,   470,   471,   472,   473,
     474,   475,   476,   477,   478,   479,   480,   481,   482,   483,
       0,     0,     0,     0,   484,     0,     0,     0,     0,     0,
       0,  1610,   470,   471,   472,   473,   474,   475,   476,   477,
     478,   479,   480,   481,   482,   483,     0,     0,     0,     0,
     484,     0,     0,     0,     0,     0,     0,  1611,   470,   471,
     472,   473,   474,   475,   476,   477,   478,   479,   480,   481,
     482,   483,     0,     0,     0,     0,   484,     0,     0,     0,
       0,     0,     0,  1612,   470,   471,   472,   473,   474,   475,
     476,   477,   478,   479,   480,   481,   482,   483,     0,     0,
       0,     0,   484,     0,     0,     0,     0,     0,     0,  1613,
     470,   471,   472,   473,   474,   475,   476,   477,   478,   479,
     480,   481,   482,   483,     0,     0,     0,     0,   484,     0,
       0,     0,     0,     0,     0,  1614,   470,   471,   472,   473,
     474,   475,   476,   477,   478,   479,   480,   481,   482,   483,
       0,     0,     0,     0,   484,     0,     0,     0,     0,     0,
       0,  1615,   470,   471,   472,   473,   474,   475,   476,   477,
     478,   479,   480,   481,   482,   483,     0,     0,     0,     0,
     484,     0,     0,     0,     0,     0,     0,  1668,   470,   471,
     472,   473,   474,   475,   476,   477,   478,   479,   480,   481,
     482,   483,     0,     0,     0,     0,   484,     0,     0,     0,
       0,     0,     0,  1669,   470,   471,   472,   473,   474,   475,
     476,   477,   478,   479,   480,   481,   482,   483,     0,     0,
       0,     0,   484,     0,     0,     0,     0,     0,     0,  1676,
     470,   471,   472,   473,   474,   475,   476,   477,   478,   479,
     480,   481,   482,   483,     0,     0,     0,     0,   484,     0,
       0,     0,     0,     0,     0,  1851,   470,   471,   472,   473,
     474,   475,   476,   477,   478,   479,   480,   481,   482,   483,
       0,     0,     0,     0,   484,     0,     0,     0,     0,     0,
       0,  1852,   470,   471,   472,   473,   474,   475,   476,   477,
     478,   479,   480,   481,   482,   483,     0,     0,     0,     0,
     484,     0,     0,     0,     0,     0,     0,  1853,   470,   471,
     472,   473,   474,   475,   476,   477,   478,   479,   480,   481,
     482,   483,     0,     0,     0,     0,   484,     0,     0,     0,
       0,     0,     0,  1854,   470,   471,   472,   473,   474,   475,
     476,   477,   478,   479,   480,   481,   482,   483,     0,     0,
       0,     0,   484,     0,     0,     0,     0,     0,     0,  1855,
     470,   471,   472,   473,   474,   475,   476,   477,   478,   479,
     480,   481,   482,   483,     0,     0,     0,     0,   484,     0,
       0,     0,     0,     0,     0,  1879,   470,   471,   472,   473,
     474,   475,   476,   477,   478,   479,   480,   481,   482,   483,
       0,     0,     0,     0,   484,     0,     0,     0,     0,     0,
       0,  1880,   470,   471,   472,   473,   474,   475,   476,   477,
     478,   479,   480,   481,   482,   483,     0,     0,     0,     0,
     484,     0,     0,     0,     0,     0,     0,  1884,   470,   471,
     472,   473,   474,   475,   476,   477,   478,   479,   480,   481,
     482,   483,     0,     0,     0,     0,   484,     0,     0,     0,
       0,     0,     0,  1992,   470,   471,   472,   473,   474,   475,
     476,   477,   478,   479,   480,   481,   482,   483,     0,     0,
       0,     0,   484,     0,     0,     0,     0,     0,     0,  1993,
     470,   471,   472,   473,   474,   475,   476,   477,   478,   479,
     480,   481,   482,   483,     0,     0,     0,     0,   484,     0,
       0,     0,     0,     0,     0,  1994,   470,   471,   472,   473,
     474,   475,   476,   477,   478,   479,   480,   481,   482,   483,
       0,     0,     0,     0,   484,     0,     0,     0,     0,     0,
       0,  1995,   470,   471,   472,   473,   474,   475,   476,   477,
     478,   479,   480,   481,   482,   483,     0,     0,     0,     0,
     484,     0,     0,     0,     0,     0,     0,  1996,   470,   471,
     472,   473,   474,   475,   476,   477,   478,   479,   480,   481,
     482,   483,     0,     0,     0,     0,   484,     0,     0,     0,
       0,     0,     0,  2006,   470,   471,   472,   473,   474,   475,
     476,   477,   478,   479,   480,   481,   482,   483,     0,     0,
       0,     0,   484,     0,     0,     0,     0,     0,     0,  2009,
     470,   471,   472,   473,   474,   475,   476,   477,   478,   479,
     480,   481,   482,   483,     0,     0,     0,     0,   484,     0,
       0,     0,     0,     0,     0,  2059,   470,   471,   472,   473,
     474,   475,   476,   477,   478,   479,   480,   481,   482,   483,
       0,     0,     0,     0,   484,     0,     0,     0,     0,     0,
       0,  2079,   470,   471,   472,   473,   474,   475,   476,   477,
     478,   479,   480,   481,   482,   483,     0,     0,     0,     0,
     484,     0,     0,     0,     0,     0,     0,  2080,   470,   471,
     472,   473,   474,   475,   476,   477,   478,   479,   480,   481,
     482,   483,     0,     0,     0,     0,   484,     0,     0,     0,
       0,     0,     0,  2081,   470,   471,   472,   473,   474,   475,
     476,   477,   478,   479,   480,   481,   482,   483,     0,     0,
       0,     0,   484,     0,     0,     0,     0,     0,     0,  2082,
     470,   471,   472,   473,   474,   475,   476,   477,   478,   479,
     480,   481,   482,   483,     0,     0,     0,     0,   484,     0,
       0,     0,     0,     0,     0,  2083,   470,   471,   472,   473,
     474,   475,   476,   477,   478,   479,   480,   481,   482,   483,
       0,     0,     0,     0,   484,     0,     0,     0,     0,     0,
       0,  2134,   470,   471,   472,   473,   474,   475,   476,   477,
     478,   479,   480,   481,   482,   483,     0,     0,     0,     0,
     484,     0,     0,     0,     0,     0,     0,  2135,   470,   471,
     472,   473,   474,   475,   476,   477,   478,   479,   480,   481,
     482,   483,     0,     0,     0,     0,   484,     0,     0,     0,
       0,     0,     0,  2136,   470,   471,   472,   473,   474,   475,
     476,   477,   478,   479,   480,   481,   482,   483,     0,     0,
       0,     0,   484,     0,     0,     0,     0,     0,     0,  2137,
     470,   471,   472,   473,   474,   475,   476,   477,   478,   479,
     480,   481,   482,   483,     0,     0,     0,     0,   484,     0,
       0,     0,   971,   470,   471,   472,   473,   474,   475,   476,
     477,   478,   479,   480,   481,   482,   483,     0,     0,     0,
       0,   484,     0,     0,     0,   978,   470,   471,   472,   473,
     474,   475,   476,   477,   478,   479,   480,   481,   482,   483,
       0,     0,     0,     0,   484,     0,     0,     0,  1074,   470,
     471,   472,   473,   474,   475,   476,   477,   478,   479,   480,
     481,   482,   483,     0,     0,     0,     0,   484,     0,     0,
       0,  1185,   470,   471,   472,   473,   474,   475,   476,   477,
     478,   479,   480,   481,   482,   483,     0,     0,     0,     0,
     484,     0,     0,     0,  1186,   470,   471,   472,   473,   474,
     475,   476,   477,   478,   479,   480,   481,   482,   483,     0,
       0,     0,     0,   484,     0,     0,     0,  1190,   470,   471,
     472,   473,   474,   475,   476,   477,   478,   479,   480,   481,
     482,   483,     0,     0,     0,     0,   484,     0,     0,     0,
    1191,   470,   471,   472,   473,   474,   475,   476,   477,   478,
     479,   480,   481,   482,   483,     0,     0,     0,     0,   484,
       0,     0,     0,  1194,   470,   471,   472,   473,   474,   475,
     476,   477,   478,   479,   480,   481,   482,   483,     0,     0,
       0,     0,   484,     0,     0,     0,  1218,   470,   471,   472,
     473,   474,   475,   476,   477,   478,   479,   480,   481,   482,
     483,     0,     0,     0,     0,   484,     0,     0,     0,  1251,
     470,   471,   472,   473,   474,   475,   476,   477,   478,   479,
     480,   481,   482,   483,     0,     0,     0,     0,   484,     0,
       0,     0,  1308,   470,   471,   472,   473,   474,   475,   476,
     477,   478,   479,   480,   481,   482,   483,     0,     0,     0,
       0,   484,     0,     0,     0,  1313,   470,   471,   472,   473,
     474,   475,   476,   477,   478,   479,   480,   481,   482,   483,
       0,     0,     0,     0,   484,     0,     0,     0,  1604,   470,
     471,   472,   473,   474,   475,   476,   477,   478,   479,   480,
     481,   482,   483,     0,     0,     0,     0,   484,     0,     0,
       0,  1659,   470,   471,   472,   473,   474,   475,   476,   477,
     478,   479,   480,   481,   482,   483,     0,     0,     0,     0,
     484,     0,     0,     0,  1834,   470,   471,   472,   473,   474,
     475,   476,   477,   478,   479,   480,   481,   482,   483,     0,
       0,     0,     0,   484,     0,   796,   470,   471,   472,   473,
     474,   475,   476,   477,   478,   479,   480,   481,   482,   483,
       0,     0,     0,     0,   484,     0,   800,   470,   471,   472,
     473,   474,   475,   476,   477,   478,   479,   480,   481,   482,
     483,     0,     0,     0,     0,   484,     0,   801,   470,   471,
     472,   473,   474,   475,   476,   477,   478,   479,   480,   481,
     482,   483,     0,     0,     0,     0,   484,     0,   803,   470,
     471,   472,   473,   474,   475,   476,   477,   478,   479,   480,
     481,   482,   483,     0,     0,     0,     0,   484,     0,   805,
     470,   471,   472,   473,   474,   475,   476,   477,   478,   479,
     480,   481,   482,   483,     0,     0,     0,     0,   484,     0,
     806,   470,   471,   472,   473,   474,   475,   476,   477,   478,
     479,   480,   481,   482,   483,     0,     0,     0,     0,   484,
       0,   809,   470,   471,   472,   473,   474,   475,   476,   477,
     478,   479,   480,   481,   482,   483,     0,     0,     0,     0,
     484,     0,   810,   470,   471,   472,   473,   474,   475,   476,
     477,   478,   479,   480,   481,   482,   483,     0,     0,     0,
       0,   484,     0,   811,   470,   471,   472,   473,   474,   475,
     476,   477,   478,   479,   480,   481,   482,   483,     0,     0,
       0,     0,   484,     0,   812,   470,   471,   472,   473,   474,
     475,   476,   477,   478,   479,   480,   481,   482,   483,     0,
       0,     0,     0,   484,     0,   813,   470,   471,   472,   473,
     474,   475,   476,   477,   478,   479,   480,   481,   482,   483,
       0,     0,     0,     0,   484,     0,   814,   470,   471,   472,
     473,   474,   475,   476,   477,   478,   479,   480,   481,   482,
     483,     0,     0,     0,     0,   484,     0,   816,   470,   471,
     472,   473,   474,   475,   476,   477,   478,   479,   480,   481,
     482,   483,     0,     0,     0,     0,   484,     0,   817,   470,
     471,   472,   473,   474,   475,   476,   477,   478,   479,   480,
     481,   482,   483,     0,     0,     0,     0,   484,     0,   826,
     470,   471,   472,   473,   474,   475,   476,   477,   478,   479,
     480,   481,   482,   483,     0,     0,     0,     0,   484,     0,
     932,   470,   471,   472,   473,   474,   475,   476,   477,   478,
     479,   480,   481,   482,   483,     0,     0,     0,     0,   484,
       0,   942,   470,   471,   472,   473,   474,   475,   476,   477,
     478,   479,   480,   481,   482,   483,     0,     0,     0,     0,
     484,     0,   943,   470,   471,   472,   473,   474,   475,   476,
     477,   478,   479,   480,   481,   482,   483,     0,     0,     0,
       0,   484,     0,   944,   470,   471,   472,   473,   474,   475,
     476,   477,   478,   479,   480,   481,   482,   483,     0,     0,
       0,     0,   484,     0,   950,   470,   471,   472,   473,   474,
     475,   476,   477,   478,   479,   480,   481,   482,   483,     0,
       0,     0,     0,   484,     0,   951,   470,   471,   472,   473,
     474,   475,   476,   477,   478,   479,   480,   481,   482,   483,
       0,     0,     0,     0,   484,     0,   958,   470,   471,   472,
     473,   474,   475,   476,   477,   478,   479,   480,   481,   482,
     483,     0,     0,     0,     0,   484,     0,   967,   470,   471,
     472,   473,   474,   475,   476,   477,   478,   479,   480,   481,
     482,   483,     0,     0,     0,     0,   484,     0,   977,   470,
     471,   472,   473,   474,   475,   476,   477,   478,   479,   480,
     481,   482,   483,     0,     0,     0,     0,   484,     0,  1073,
     470,   471,   472,   473,   474,   475,   476,   477,   478,   479,
     480,   481,   482,   483,     0,     0,     0,     0,   484,     0,
    1101,   470,   471,   472,   473,   474,   475,   476,   477,   478,
     479,   480,   481,   482,   483,     0,     0,     0,     0,   484,
       0,  1106,   470,   471,   472,   473,   474,   475,   476,   477,
     478,   479,   480,   481,   482,   483,     0,     0,     0,     0,
     484,     0,  1117,   470,   471,   472,   473,   474,   475,   476,
     477,   478,   479,   480,   481,   482,   483,     0,     0,     0,
       0,   484,     0,  1122,   470,   471,   472,   473,   474,   475,
     476,   477,   478,   479,   480,   481,   482,   483,     0,     0,
       0,     0,   484,     0,  1123,   470,   471,   472,   473,   474,
     475,   476,   477,   478,   479,   480,   481,   482,   483,     0,
       0,     0,     0,   484,     0,  1129,   470,   471,   472,   473,
     474,   475,   476,   477,   478,   479,   480,   481,   482,   483,
       0,     0,     0,     0,   484,     0,  1138,   470,   471,   472,
     473,   474,   475,   476,   477,   478,   479,   480,   481,   482,
     483,     0,     0,     0,     0,   484,     0,  1139,   470,   471,
     472,   473,   474,   475,   476,   477,   478,   479,   480,   481,
     482,   483,     0,     0,     0,     0,   484,     0,  1140,   470,
     471,   472,   473,   474,   475,   476,   477,   478,   479,   480,
     481,   482,   483,     0,     0,     0,     0,   484,     0,  1172,
     470,   471,   472,   473,   474,   475,   476,   477,   478,   479,
     480,   481,   482,   483,     0,     0,     0,     0,   484,     0,
    1174,   470,   471,   472,   473,   474,   475,   476,   477,   478,
     479,   480,   481,   482,   483,     0,     0,     0,     0,   484,
       0,  1175,   470,   471,   472,   473,   474,   475,   476,   477,
     478,   479,   480,   481,   482,   483,     0,     0,     0,     0,
     484,     0,  1176,   470,   471,   472,   473,   474,   475,   476,
     477,   478,   479,   480,   481,   482,   483,     0,     0,     0,
       0,   484,     0,  1177,   470,   471,   472,   473,   474,   475,
     476,   477,   478,   479,   480,   481,   482,   483,     0,     0,
       0,     0,   484,     0,  1178,   470,   471,   472,   473,   474,
     475,   476,   477,   478,   479,   480,   481,   482,   483,     0,
       0,     0,     0,   484,     0,  1179,   470,   471,   472,   473,
     474,   475,   476,   477,   478,   479,   480,   481,   482,   483,
       0,     0,     0,     0,   484,     0,  1180,   470,   471,   472,
     473,   474,   475,   476,   477,   478,   479,   480,   481,   482,
     483,     0,     0,     0,     0,   484,     0,  1184,   470,   471,
     472,   473,   474,   475,   476,   477,   478,   479,   480,   481,
     482,   483,     0,     0,     0,     0,   484,     0,  1193,   470,
     471,   472,   473,   474,   475,   476,   477,   478,   479,   480,
     481,   482,   483,     0,     0,     0,     0,   484,     0,  1217,
     470,   471,   472,   473,   474,   475,   476,   477,   478,   479,
     480,   481,   482,   483,     0,     0,     0,     0,   484,     0,
    1307,   470,   471,   472,   473,   474,   475,   476,   477,   478,
     479,   480,   481,   482,   483,     0,     0,     0,     0,   484,
       0,  1312,   470,   471,   472,   473,   474,   475,   476,   477,
     478,   479,   480,   481,   482,   483,     0,     0,     0,     0,
     484,     0,  1480,   470,   471,   472,   473,   474,   475,   476,
     477,   478,   479,   480,   481,   482,   483,     0,     0,     0,
       0,   484,     0,  1713,   470,   471,   472,   473,   474,   475,
     476,   477,   478,   479,   480,   481,   482,   483,     0,     0,
       0,     0,   484,     0,  1730,   470,   471,   472,   473,   474,
     475,   476,   477,   478,   479,   480,   481,   482,   483,     0,
       0,     0,     0,   484,     0,  1760,   470,   471,   472,   473,
     474,   475,   476,   477,   478,   479,   480,   481,   482,   483,
       0,     0,     0,     0,   484,     0,  2005,   470,   471,   472,
     473,   474,   475,   476,   477,   478,   479,   480,   481,   482,
     483,     0,     0,     0,     0,   484,     0,  2089,   470,   471,
     472,   473,   474,   475,   476,   477,   478,   479,   480,   481,
     482,   483,     0,     0,     0,     0,   484
};

static const yytype_int16 yycheck[] =
{
       3,  1171,  1593,     6,     5,   128,   422,   280,   424,  1627,
    1628,     5,     4,   568,   569,   295,     4,     4,  1167,     5,
       3,     6,     6,   439,     4,     6,     4,     4,     4,     4,
       4,   311,     5,  1805,     4,     4,     4,     4,   212,   213,
       4,     6,     5,     5,     5,     5,     5,   222,     5,   224,
       6,     6,     4,     6,     6,   229,     7,   226,     6,     6,
     222,     4,   231,     4,     4,   212,   213,   229,    71,   212,
     213,     6,   212,   213,   223,     7,    79,     6,   455,   228,
     457,    84,   459,   230,   164,   228,   225,   230,   228,   228,
     230,   371,    95,   373,     7,   212,   213,   212,   213,   379,
     180,   181,  1693,     0,   118,   212,   213,   222,     6,   212,
     213,   228,   225,   230,   229,   228,     7,   212,   213,     6,
     134,    13,   229,   212,   213,   228,     7,     6,   142,   143,
     144,   222,    84,   228,   148,   149,   150,   151,    58,    59,
     229,    61,     6,    84,   212,   213,   223,    88,     7,   212,
     213,   228,    90,    94,    95,     7,    97,    98,   212,   213,
     228,    87,     7,   222,    90,   228,   154,   155,   156,   157,
     111,   219,   220,   167,   228,     6,   212,   213,   226,   122,
     123,   124,   125,    84,  1956,  1957,    87,   152,     6,    90,
     164,   165,   228,   136,   167,   175,   139,   164,   165,   152,
       7,   204,   179,     8,   152,   152,   219,   220,   167,  1800,
     167,     6,   225,   216,   217,   222,   230,   222,   198,   224,
     198,   224,   205,   198,   209,   209,   231,  1818,   229,   232,
     222,   234,   224,     6,   226,   229,   239,   224,     6,   231,
     243,   222,   230,   229,   231,  1394,   222,   250,   229,   229,
     253,   229,   222,   229,   257,   258,   259,   260,   261,   229,
     229,   229,   265,   266,   267,   229,   229,   229,   229,   229,
     273,   274,   275,   229,   229,   226,   279,   280,     3,   559,
     560,     6,   222,   212,   213,     6,   199,   200,   201,   202,
     222,     7,   224,   224,   671,     7,   673,    87,   222,   579,
      90,     7,   305,   306,   307,   229,   219,   220,   199,   200,
     201,   202,   224,   226,   212,   213,   319,   320,   199,   200,
     201,   202,    95,   222,    97,   212,   213,   223,   219,   220,
     229,    84,   228,   336,    87,   338,   459,    90,   219,   220,
     199,   200,   201,   202,   222,   222,    71,   199,   200,   201,
     202,   229,   216,   217,   199,   200,   201,   202,   103,    84,
     219,   220,   739,   283,   284,   222,   743,   222,   648,   224,
      95,   291,   212,   213,   377,   295,   231,    90,   381,   382,
     212,   213,  2000,   663,   122,   123,   250,    90,   228,    92,
     128,   394,   199,   200,   201,   202,   228,   261,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   219,   220,   212,   213,   221,  2008,   223,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,    90,   436,   437,   438,   439,   440,   222,   219,
     220,   444,   445,   446,   447,   448,   449,   222,   451,   229,
     212,   213,   212,   213,   258,   259,   260,   222,   231,   212,
     213,   265,   266,   267,   229,   468,   228,   222,   228,   222,
     219,   220,   219,   220,     6,   223,   229,   225,   222,   204,
     229,     6,   229,   199,   200,   201,   202,   199,   200,   201,
     202,   216,   217,   199,   200,   201,   202,   229,   222,   224,
     224,   305,   306,   506,   212,   213,    92,   232,   212,   213,
     212,   213,   222,   377,   118,   319,   320,   212,   213,    90,
     228,   212,   213,   222,   228,   250,   228,   212,   213,  2120,
     134,    90,   228,   228,   230,   222,   261,   228,   142,   143,
     144,   212,   213,   228,   148,   149,   150,   151,   122,   123,
     553,   554,   212,   213,   128,   280,   228,   228,   230,   423,
     683,   425,   426,   427,   428,   429,   430,   431,   228,   433,
     434,   222,   436,   437,   438,   222,   440,   857,   219,   220,
     444,   445,   446,   447,   448,   568,   569,   212,   213,   222,
     967,   212,   213,   228,   971,   230,   599,   600,   601,   212,
     213,    87,     8,   228,   222,   212,   213,   228,   611,   612,
     222,   228,   615,   230,   387,   228,   739,   212,   213,   222,
     743,   228,   212,   213,   222,   118,   230,   630,   212,   213,
     222,     6,   224,   228,   637,     6,     7,    84,   228,   231,
      87,   134,   229,    90,   228,    92,   566,   567,   229,   142,
     143,   144,   377,   656,   574,   148,   149,   150,   151,  1829,
     228,  1831,   230,  1833,   219,   220,   219,   220,   228,   442,
     230,     8,    90,   676,   229,    87,   229,   450,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,     6,     7,   212,   213,   221,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,    87,   433,   434,
     228,   436,   437,   438,   439,   440,   118,   212,   213,   444,
     445,   446,   447,   448,   449,   223,   451,   212,   213,    90,
     228,    87,   134,   228,    90,   738,    92,   230,     4,   742,
     142,   143,   144,   228,   219,   220,   148,   149,   150,   151,
     223,   615,   225,  1130,   229,  1132,   229,  1134,   222,  1136,
     224,    87,  1911,     4,    90,  1914,    92,   231,  1917,     4,
     543,   544,   545,   546,   222,   228,   224,   230,   781,  1052,
     903,     6,   785,   231,   228,   788,   230,   222,   791,   224,
     793,   226,     4,   222,   797,   798,   231,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   228,   222,   230,  1984,   221,   212,   213,   214,   215,
     216,   228,   222,   230,   230,   221,   224,   830,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,     6,   222,   967,   224,   221,   226,   971,   222,
     229,   854,   231,    84,   977,   978,    87,  1273,  1274,    90,
     223,    92,  1278,  1279,   222,   228,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     223,   214,   215,   216,   221,   228,  2035,   612,   221,   223,
     615,   225,  2062,   230,  2064,   229,  2066,   222,   228,   224,
     230,   226,  2072,   906,  1281,   908,   231,   223,   911,   225,
     223,   223,   228,   225,     6,   228,   228,   228,   222,   230,
    1297,   924,     6,   926,   788,   928,   223,   930,   225,   793,
     224,   228,   935,   223,   223,   225,   225,   940,   228,   228,
     860,   222,   228,   223,   230,   225,  2095,   867,   228,  2098,
    1073,  1074,  2101,   873,   222,  2104,  2126,   222,  2128,   962,
    2130,   222,     7,   966,   223,   222,   225,   970,   228,   228,
     230,   744,   228,   222,   230,   978,   222,   222,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,    90,    90,    92,    92,   221,  2146,   222,  2148,
    1003,  2150,   228,   222,   230,  1008,   228,   228,   230,   230,
    1013,  1014,  1015,  1016,   229,  1288,  1571,  1572,   228,   228,
     230,   230,   795,  1026,   228,  1028,   230,   228,   228,   230,
     230,   224,  1448,  1449,   228,     6,   230,  1453,  1454,   228,
     228,   230,   230,   228,   228,   230,   230,   229,   228,  1052,
     230,   229,  1055,  1056,  1057,  1058,     6,   228,   118,   230,
     228,   222,   230,   788,   222,   228,   791,   230,   793,   222,
    1193,  1194,   229,     4,   134,     6,   228,  1080,   230,   229,
     222,  1458,   142,   143,   144,   228,   222,   230,   148,   149,
     150,   151,     4,   222,  1217,  1218,  1099,  1100,   228,  1102,
     230,  1104,  1105,   222,   222,  1108,  1109,  1110,  1111,  1112,
    1113,  1114,  1115,   228,   978,   230,  1119,   222,  1121,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   228,   228,   230,   230,   221,   228,   228,
     230,   230,   222,   229,  1008,     4,     5,   228,   224,   230,
    1014,  1015,  1016,   228,   228,   230,   230,   228,  1281,   230,
     229,   229,  1026,  1443,  1028,  1445,   228,   228,   230,   230,
     230,   228,   228,   230,   230,  1095,   228,   228,   230,   230,
     228,   228,   230,   230,   222,    44,    45,    46,    47,    48,
      49,    50,    51,    52,   228,   228,   230,   230,    57,    58,
      59,    60,     4,     5,   229,   229,    65,    66,    67,   222,
     228,    70,   230,   228,   222,   230,  1080,  1220,  1221,  1222,
     222,   228,    81,   230,   222,   228,  1499,   230,   228,   228,
     230,   230,     6,  1236,   222,  1155,  1156,  1157,   228,   222,
     230,   222,    44,    45,    46,    47,    48,    49,    50,    51,
      52,   231,     6,   978,     6,    57,    58,    59,    60,   229,
     229,   229,   118,    65,    66,    67,   224,   224,    70,  1824,
    1273,  1274,   224,   229,     6,  1278,  1279,     6,   134,    81,
     229,   167,   118,  1008,   231,  1288,   142,   143,   144,  1014,
    1015,  1016,   148,   149,   150,   151,     6,     6,   134,  1302,
     229,  1026,     6,  1028,     6,   229,   142,   143,   144,   229,
       6,   224,   148,   149,   150,   151,     4,   221,   226,   229,
       7,   230,     6,  1326,   183,   184,   185,  1052,   228,  1332,
     228,   223,     7,     6,     6,     6,   195,  1460,   197,   198,
     223,  1344,     7,     7,  1347,  1348,     6,     6,     6,  1352,
    1353,   223,  1355,     6,  1357,  1080,  1359,     7,  1361,  1362,
    1363,   229,     6,     6,   223,  1781,   225,     6,    62,     7,
       6,     6,     4,   118,   230,   164,    62,  1380,   229,    62,
      62,   183,   184,   185,   225,   223,     6,     6,   223,   134,
     223,   228,  1395,   195,   230,   197,   198,   142,   143,   144,
    1403,   228,  1405,   148,   149,   150,   151,   228,   228,   228,
     228,   228,   223,     4,     5,   223,   223,   219,   220,   225,
      44,    44,    44,    44,   226,     6,     4,   229,     4,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,     6,     6,  1448,  1449,   221,     6,     6,
    1453,  1454,     7,    44,    45,    46,    47,    48,    49,    50,
      51,    52,     7,     7,  1467,     7,    57,    58,    59,    60,
    1473,     7,   167,  1393,    65,    66,    67,   167,     7,    70,
       7,     7,  1605,     7,     7,   230,   167,     7,   229,     7,
      81,     7,     7,     6,     6,     4,  1499,     7,     6,   223,
     228,   223,  1505,   208,   209,   210,   211,   212,   213,   214,
     215,   216,  1515,   228,   228,  1518,   221,   223,  1791,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   230,   223,   228,     6,   221,   230,     7,
       7,   226,     7,  1316,   223,   225,     7,     6,  1273,  1274,
     226,   229,   229,  1278,  1279,   229,    44,    44,  1838,   229,
    1563,  1564,     6,  1288,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   230,     6,
     229,    44,   221,     6,    44,     6,     6,     6,  1571,  1572,
    1593,     7,   183,   184,   185,   224,  1599,     6,   229,   118,
       6,   209,     7,  1467,   195,   222,   197,   198,  1528,  1473,
     222,     7,    92,     7,     7,   134,  1619,     7,     7,     6,
     229,     7,     6,   142,   143,   144,  1629,     7,     7,   148,
     149,   150,   151,     7,     7,     7,  1639,     4,     4,   222,
     118,  1644,     6,   229,     7,     6,   228,     7,     7,     7,
       7,  1515,     7,  1573,     7,  1575,   134,  1577,     7,     6,
       6,  1941,     6,     6,   142,   143,   144,  1670,    90,  1442,
     148,   149,   150,   151,  1594,  1595,  1596,  1597,  1598,  1599,
       7,     6,     4,     4,     4,   223,   229,     6,   229,     6,
    1693,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,  1985,     6,     6,   230,   221,
       6,   230,     4,     6,   228,     6,   223,   228,  1491,     7,
     226,   222,     6,  1448,  1449,   229,  1729,   226,  1453,  1454,
     223,   225,     6,     6,   229,   111,     6,   229,  1741,   229,
     229,     6,  1467,     6,   229,  1518,     6,     6,  1473,     6,
       6,     6,   230,     6,     6,     6,     6,     5,  1761,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,     6,  1499,  1778,     4,   221,  1781,     6,
     229,   229,     7,   229,   229,   224,    12,    13,  1791,     6,
    1515,     6,     6,     6,  1567,   229,   229,  1800,   229,   229,
     229,   229,     4,   229,  1807,  1808,   223,   225,     6,     6,
       6,   163,     6,   228,     4,  1818,     4,     6,  1821,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,     6,  1837,     6,     6,   221,  1841,     6,
       6,  1824,     6,     6,     4,     7,     7,     6,     6,     6,
       6,     5,  1625,     6,   229,     6,   167,     6,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,  1644,  1645,  1646,   100,   101,   102,     6,   104,     6,
       6,     6,     6,   109,   110,   111,   112,     6,   114,   115,
     116,     6,     6,     6,   120,   228,     6,  1900,     6,     6,
       6,     6,   228,     6,     6,   223,     6,     6,  1828,     6,
    1830,     6,  1832,     7,     6,     6,  1919,   226,     6,   229,
       6,   229,  1842,  1843,  1844,  1845,  1846,   229,     5,   230,
       6,   229,     6,   159,   160,   161,    88,     6,     6,   229,
       7,   230,   229,  1946,   229,     6,   229,   229,     6,   230,
      12,    13,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   230,   162,   230,     6,
     221,     6,     6,     6,   165,     6,   118,     6,     6,  1899,
       6,     6,     6,  1903,  1987,  1988,  1989,  1990,  1991,     6,
       6,  1764,   134,   229,     6,     6,     6,   229,     7,   223,
     142,   143,   144,     6,   230,  2008,   148,   149,   150,   151,
     229,   229,     6,   229,     6,   103,     6,   229,     6,   230,
     118,   229,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,     6,     6,     6,   100,   101,
     102,  1961,   104,     6,     6,  1965,     6,   109,   110,   111,
     112,     6,   114,   115,   116,     6,  1781,     6,   120,     6,
       6,   230,     6,     6,   229,     6,  1791,   222,     6,     6,
       6,  1991,     6,     6,  2077,     6,     6,   223,  1311,   229,
       6,   229,     6,   230,   229,  2088,   229,     6,   230,   229,
     229,   229,   229,     6,     6,     6,     6,   159,   160,   161,
       6,     6,     6,     6,     6,     6,     6,     6,  1949,  1806,
     198,   199,   200,   201,   202,     3,     3,  2120,  1325,   502,
       3,     3,  1820,  1495,    -1,    -1,    -1,   215,   541,    -1,
      -1,   219,    -1,    -1,    -1,  2138,    -1,  2140,    -1,    -1,
    2060,  2061,    -1,    -1,    -1,   233,   234,   235,   236,    -1,
     238,   239,   240,   241,    -1,   243,   244,   245,   246,   247,
     248,   249,    -1,   251,   252,    -1,    -1,  2170,   230,   257,
      -1,    -1,  1945,    -1,   262,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   277,
      -1,    -1,    -1,   221,    -1,    -1,    -1,    -1,   286,   287,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   295,    -1,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,  1946,    -1,    -1,  2088,   221,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,    -1,   336,   337,
     338,   221,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   350,   351,   352,    -1,   354,    -1,    -1,    -1,
     358,   359,   360,    -1,  2138,   363,  2140,  2050,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,    -1,
     378,    -1,    -1,   221,    -1,   383,   384,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2170,    -1,    -1,   397,
     398,    -1,   400,   401,   402,   403,   404,   405,   406,   407,
     408,   409,   410,   411,   412,   413,   414,   415,   416,   417,
     418,   419,   420,   421,   118,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   435,    -1,    -1,
     134,    -1,    -1,   441,    -1,   443,     6,    -1,   142,   143,
     144,    -1,    -1,  2088,   148,   149,   150,   151,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   467,
     468,    -1,   470,   471,   472,   473,   474,   475,   476,   477,
     478,   479,   480,   481,   482,   483,   484,    -1,    -1,   487,
     488,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2138,    -1,  2140,    -1,    -1,   506,    -1,
      -1,    -1,    -1,    -1,   512,    -1,    -1,    -1,    -1,   517,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   529,   530,    -1,    -1,  2170,   230,    -1,    -1,   537,
     538,    -1,    -1,    -1,   542,   543,   544,   545,   546,   547,
      -1,   549,     6,   551,    -1,   553,   554,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,    22,
      -1,    -1,    -1,   571,   572,   573,   574,   575,   576,    -1,
      -1,    -1,   580,   581,   582,   583,   584,   585,   586,   587,
     588,    -1,    -1,    -1,   592,    -1,   594,   595,    -1,    -1,
      -1,   599,   600,   601,     6,    -1,   604,   605,   606,   607,
     608,    -1,    -1,   611,   612,   613,   614,    -1,   616,    -1,
      -1,   619,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   630,    -1,    -1,     6,    -1,    -1,   636,   637,
      -1,   639,   640,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,    -1,   656,    -1,
      -1,   221,    -1,   661,   662,    -1,   664,   665,    -1,    -1,
      -1,    -1,    -1,    -1,   127,    -1,    -1,   675,   676,    -1,
      -1,    -1,   680,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,    -1,   118,
      -1,   164,   165,   166,   167,    -1,   169,   170,   171,   172,
     173,   174,    -1,    -1,   177,   134,    -1,    -1,    -1,    -1,
     183,   184,    -1,   142,   143,   144,   189,   190,    -1,   148,
     149,   150,   151,    -1,    -1,    -1,    -1,   745,    -1,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,    -1,    -1,     6,    -1,   221,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   777,
     778,    -1,    -1,   781,   782,   783,    -1,   785,   786,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   794,    -1,    -1,   797,
     798,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,    -1,    -1,    -1,    -1,   221,
     818,   230,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   829,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,    -1,    -1,    -1,    -1,
     221,    -1,    -1,    -1,    -1,    -1,   854,    -1,    -1,    -1,
      -1,    -1,    -1,   861,   862,    -1,   118,    -1,    -1,   867,
      -1,   324,    -1,    -1,   327,   328,   329,   330,    -1,    -1,
      -1,    -1,   134,    -1,    -1,    -1,   884,    -1,    -1,   887,
     142,   143,   144,    -1,   347,    -1,   148,   149,   150,   151,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   906,    -1,
     908,    -1,    -1,   911,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   924,    -1,   926,    -1,
     928,    -1,   930,    -1,    -1,    -1,    -1,   935,    -1,    -1,
      -1,    -1,   940,    -1,    -1,    -1,    -1,    -1,   946,    -1,
     948,   949,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   959,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,    -1,    -1,   230,    -1,
     221,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   991,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   999,  1000,  1001,    -1,  1003,    -1,    -1,    -1,   462,
      -1,    -1,    -1,  1011,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     7,     8,    -1,   234,    -1,  1025,    -1,    -1,
     239,    -1,  1030,    -1,   243,    -1,    -1,    -1,    -1,    -1,
      -1,  1039,    -1,    -1,    -1,    -1,    -1,  1045,   257,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   253,  1055,  1056,  1057,
    1058,    -1,    -1,  1061,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     3,     4,    -1,   273,   274,   275,     9,
      10,    11,   279,   118,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    -1,    -1,    -1,
     307,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1119,    -1,    53,    54,    55,    56,    -1,    -1,    -1,
      -1,    61,    -1,  1131,    -1,  1133,    -1,  1135,    -1,  1137,
      -1,    -1,    72,    73,    74,    -1,    -1,    -1,    -1,    -1,
      80,     7,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1159,    -1,    -1,    -1,    -1,    -1,    -1,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,    -1,    -1,   381,   382,   221,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1192,    -1,    -1,   394,    -1,    -1,
      -1,    -1,    -1,  1201,  1202,    -1,  1204,  1205,    -1,  1207,
    1208,  1209,    -1,    -1,    -1,    -1,    -1,  1215,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,    12,    13,    -1,   432,   221,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1242,    -1,    -1,    -1,    -1,  1247,
      -1,    -1,   182,    -1,    -1,    -1,   186,    -1,     8,   468,
     190,   191,   192,   193,   194,    -1,    -1,    -1,   198,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   212,   213,    -1,    -1,    -1,   217,    -1,    -1,
      -1,  1289,   222,    -1,    -1,    -1,    -1,   227,    -1,   229,
      -1,    -1,  1300,  1301,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,  1315,  1316,    -1,
     100,   101,   102,    -1,   104,    -1,    -1,    -1,    -1,   109,
     110,   111,   112,    -1,   114,   115,   116,    -1,    -1,    -1,
     120,    -1,    -1,    -1,   553,   554,    -1,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,    -1,    -1,    -1,    -1,   221,    -1,    -1,    -1,    -1,
      -1,  1369,  1370,  1371,    -1,    -1,    -1,    -1,    -1,   159,
     160,   161,  1380,    -1,  1382,    -1,    -1,    -1,    -1,    -1,
     599,   600,   601,    -1,    -1,  1393,    -1,    -1,    -1,    -1,
      -1,    12,    13,    -1,    -1,    -1,    -1,  1405,    -1,    -1,
      -1,    -1,  1410,    -1,    -1,    -1,    -1,    -1,   234,    -1,
      -1,   630,    -1,   239,    -1,    -1,    -1,   243,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1436,  1437,
    1438,   257,    -1,    -1,    -1,    -1,    -1,   656,    -1,    -1,
     230,    -1,    -1,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   676,    -1,    -1,
    1468,   221,    -1,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    -1,    -1,    -1,   100,
     101,   102,    -1,   104,  1492,    -1,    -1,    -1,   109,   110,
     111,   112,    -1,   114,   115,   116,    -1,    -1,  1506,   120,
      -1,    -1,    -1,  1511,    -1,    -1,    -1,    -1,    -1,    -1,
     336,    -1,   338,    -1,    -1,    -1,    -1,    -1,  1526,  1527,
      -1,    -1,    -1,    -1,    -1,  1533,  1534,    -1,    -1,    -1,
    1538,   738,    -1,    -1,    -1,   742,    -1,    -1,   159,   160,
     161,    -1,    -1,    -1,    -1,  1553,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1563,  1564,  1565,    -1,  1567,
      -1,    -1,   781,    -1,    -1,    -1,   785,    -1,    -1,    -1,
      -1,  1579,  1035,  1036,    -1,    -1,    -1,    -1,  1041,  1042,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1599,    -1,    -1,  1602,    -1,    -1,    -1,    -1,    -1,
      -1,  1609,  1610,  1611,  1612,  1613,  1614,  1615,    -1,   230,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1625,    -1,    -1,
      -1,    -1,    -1,   830,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   854,    -1,  1645,    -1,    -1,
      -1,    -1,   468,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     8,    -1,    -1,    -1,
    1668,  1669,    -1,    -1,    -1,    -1,    -1,    -1,  1676,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     506,    -1,    -1,    -1,    -1,    -1,    -1,   906,    -1,   908,
      -1,    -1,   911,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   924,  1714,   926,    -1,   928,
      -1,   930,    -1,    -1,    -1,    -1,   935,    -1,    -1,    -1,
       8,   940,    -1,    -1,  1732,    -1,    -1,   553,   554,    -1,
      -1,    -1,    -1,  1741,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,  1756,    -1,
    1758,    -1,   221,  1761,    -1,   962,    -1,    -1,    -1,   966,
      -1,   230,    -1,   970,    -1,    -1,    -1,    -1,    -1,    -1,
    1778,    -1,    -1,   599,   600,   601,  1239,  1240,    -1,    -1,
      -1,  1244,  1245,    -1,  1003,   611,   612,    -1,  1796,    -1,
      -1,    -1,    -1,  1801,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   630,    -1,  1013,    -1,    -1,    -1,
      -1,   637,    -1,  1821,    -1,    -1,    -1,    -1,    -1,    -1,
    1828,    -1,  1830,    -1,  1832,    -1,    -1,    -1,    -1,    -1,
     656,    -1,    -1,  1841,    -1,     8,  1055,  1056,  1057,  1058,
      -1,    -1,    -1,  1851,  1852,  1853,  1854,  1855,  1856,    -1,
     676,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,    -1,    -1,    -1,    -1,   221,
      -1,  1879,  1880,    -1,    -1,    -1,  1884,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1896,    -1,
      -1,    -1,  1099,  1100,    -1,  1102,    -1,  1104,  1105,  1907,
    1119,  1108,  1109,  1110,  1111,  1112,  1113,  1114,  1115,    -1,
      -1,    -1,    -1,    -1,  1121,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,    -1,
      -1,    -1,    -1,   221,    -1,  1943,    -1,    -1,    -1,    -1,
      -1,  1949,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1958,    -1,    -1,    -1,    -1,   781,    -1,    -1,    -1,   785,
      -1,    -1,     8,    -1,  1972,    -1,    -1,  1975,    -1,    -1,
    1978,   797,   798,    -1,  1982,    -1,    -1,    -1,    -1,  1987,
    1988,  1989,  1990,  1991,  1992,  1993,  1994,  1995,  1996,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2006,    -1,
      -1,  2009,     8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1220,  1221,  1222,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   854,  1236,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,    -1,    -1,    -1,    -1,   221,    -1,
      -1,  2059,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,    -1,    -1,    -1,  2077,
     221,  2079,  2080,  2081,  2082,  2083,    -1,   228,    -1,   230,
     906,    -1,   908,    -1,    -1,   911,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1302,    -1,    -1,   924,    -1,
     926,    -1,   928,    -1,   930,    -1,    -1,    -1,    -1,   935,
      -1,    -1,    -1,    -1,   940,  2123,  2124,    -1,    -1,  1326,
      -1,    -1,    -1,    -1,    -1,  1332,  2134,  2135,  2136,  2137,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1344,    -1,    -1,
    1347,  1348,    -1,    -1,    -1,  1352,  1353,    -1,  1355,    -1,
    1357,    -1,  1359,    -1,  1361,  1362,  1363,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,    -1,    -1,  1380,    -1,   221,    -1,  1003,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1405,    -1,  1395,    -1,
      -1,   641,    -1,    -1,    -1,    -1,  1403,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,    -1,    -1,    -1,    -1,   221,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1055,
    1056,  1057,  1058,    -1,   684,   685,   686,   687,   688,   689,
     690,   691,   692,   693,   694,    -1,   696,   697,   698,   699,
     700,   701,   702,    -1,    -1,    -1,   706,   707,   708,    -1,
       4,     5,   712,   713,    -1,   715,    -1,    -1,    -1,    -1,
     720,   721,   722,    -1,   724,    -1,    -1,    -1,    -1,    -1,
      -1,   731,   732,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1119,    -1,    -1,    -1,    -1,  1505,   749,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    -1,
      -1,  1518,    -1,    57,    58,    59,    60,    -1,    -1,    -1,
      -1,    65,    66,    67,    -1,    -1,    70,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,    -1,    -1,
      -1,    -1,    -1,    -1,  1563,  1564,     3,     4,     5,    -1,
      -1,    -1,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      -1,    -1,    -1,    -1,    -1,    -1,  1593,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    -1,    -1,    -1,    65,    66,
      67,    -1,  1619,    70,    -1,    72,    73,    74,    -1,    -1,
      -1,    -1,  1629,    80,    81,    -1,    -1,     4,     5,    -1,
      -1,    -1,  1639,    -1,    -1,    -1,    -1,  1644,    -1,   183,
     184,   185,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   195,    -1,   197,   198,     5,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1670,    -1,    -1,   916,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    -1,    -1,    -1,    -1,
      57,    58,    59,    60,    -1,    -1,  1693,    -1,    65,    66,
      67,    -1,    -1,    70,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    -1,    81,    -1,    -1,    57,    58,    59,
      60,    -1,    -1,    -1,    -1,    65,    66,    67,   175,    -1,
      70,    -1,  1729,    -1,    -1,   182,   183,   184,   185,   186,
      -1,    81,    -1,   190,   191,   192,   193,   194,   195,    -1,
     197,   198,  1761,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   212,   213,    -1,    -1,    -1,
     217,    -1,    -1,    -1,    -1,   222,    -1,   224,    -1,   226,
     227,    -1,   229,    -1,   231,    -1,    -1,    -1,    -1,  1405,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1800,    -1,    -1,    -1,    -1,    -1,    -1,
    1807,  1808,  1821,    -1,    -1,    -1,   183,   184,   185,    -1,
    1060,  1818,    -1,    -1,    -1,    -1,    -1,    -1,   195,    -1,
     197,    -1,  1841,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1837,    -1,    -1,   183,   184,   185,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1093,  1094,   195,    -1,   197,    -1,    -1,
      -1,    -1,    -1,     3,     4,     5,    -1,    -1,    -1,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    -1,    -1,    -1,
      -1,    -1,    -1,  1900,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,  1919,    -1,    -1,    65,    66,    67,    -1,    -1,
      70,    -1,    72,    73,    74,    -1,    -1,    -1,    -1,    -1,
      80,    81,    -1,    -1,    -1,    -1,    -1,  1563,  1564,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,    -1,    -1,    -1,    -1,   221,    -1,    -1,
      -1,    -1,    -1,    -1,   228,    -1,   230,    -1,  1987,  1988,
    1989,  1990,  1991,  1599,    -1,    -1,    -1,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,    -1,    -1,    -1,    -1,   221,    -1,    -1,    -1,    -1,
    1250,  2008,   228,    -1,   230,    -1,  1256,  1257,  1258,  1259,
    1260,    -1,  1262,    -1,  1264,  1265,    -1,  1267,  1268,    12,
      13,  1271,  1272,  1273,    -1,    -1,    -1,    -1,  1278,    -1,
      -1,    -1,   182,   183,   184,   185,   186,    -1,    -1,    -1,
     190,   191,   192,   193,   194,   195,    -1,   197,   198,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2077,    -1,
      -1,    -1,   212,   213,    -1,    -1,    -1,   217,    -1,    -1,
      -1,    -1,   222,    -1,    -1,    -1,    -1,   227,    -1,   229,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    -1,    -1,    -1,   100,   101,   102,
      -1,   104,    -1,  2120,    -1,  1741,   109,   110,   111,   112,
      -1,   114,   115,   116,    -1,    -1,    -1,   120,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1761,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
      -1,    -1,  1778,    -1,   221,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   230,    -1,  1415,   159,   160,   161,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1431,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1821,    -1,    -1,  1448,    -1,
      -1,    -1,    -1,  1453,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1841,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
      -1,    -1,    -1,    -1,   221,  1485,  1486,   230,    -1,  1489,
    1490,    -1,    -1,   230,    -1,    -1,    -1,    -1,     3,     4,
      -1,    -1,    -1,    -1,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,    54,
      55,    56,    -1,    -1,    -1,    -1,    61,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,    73,    74,
      -1,    -1,    12,    13,    -1,    80,    -1,    -1,    -1,    84,
      -1,    -1,    87,    -1,    -1,    90,    -1,    92,    -1,    -1,
      -1,    -1,    -1,    -1,    99,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     115,  1987,  1988,  1989,  1990,  1991,    -1,   122,   123,   124,
     125,   126,    -1,    -1,   129,   130,   131,   132,   133,    -1,
      -1,   136,  1632,  1633,   139,    -1,  1636,  1637,    -1,    -1,
      -1,    -1,  1642,  1643,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    -1,    -1,    -1,
     100,   101,   102,    -1,   104,    -1,    -1,    -1,    -1,   109,
     110,   111,   112,    -1,   114,   115,   116,   182,    -1,    -1,
     120,   186,    -1,    -1,    -1,   190,   191,   192,   193,   194,
      -1,    -1,    -1,   198,    -1,    -1,    -1,   137,    -1,    -1,
      -1,  2077,    -1,    -1,    -1,    -1,    -1,   212,   213,    -1,
      -1,    -1,   217,    -1,    -1,    -1,    -1,   222,    -1,   159,
     160,   161,   227,    -1,   229,   230,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,    -1,    -1,    -1,    -1,     9,    10,    11,  1748,  1749,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,
      54,    55,    56,    -1,    -1,    -1,    -1,    61,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,    73,
      74,    -1,    12,    13,    -1,    -1,    80,    -1,    -1,    -1,
      84,    -1,    -1,    87,    -1,    -1,    90,    -1,    92,    -1,
      -1,    -1,    -1,    -1,    -1,    99,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
      -1,   115,    -1,    -1,   221,    -1,    -1,    -1,   122,   123,
     124,   125,   126,   230,    -1,   129,   130,   131,   132,   133,
      -1,    -1,   136,    -1,    -1,   139,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    -1,    -1,    -1,
     100,   101,   102,    -1,   104,    -1,    -1,    -1,    -1,   109,
     110,   111,   112,    -1,   114,   115,   116,    -1,   182,    -1,
     120,    -1,   186,    -1,    -1,    -1,   190,   191,   192,   193,
     194,    -1,    -1,    -1,   198,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   212,   213,
      -1,    -1,    -1,   217,    -1,    -1,    -1,    -1,   222,   159,
     160,   161,    -1,   227,    -1,    -1,   230,     3,     4,     5,
      -1,    -1,    -1,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    -1,    -1,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    -1,    -1,    -1,    65,
      66,    67,    -1,    -1,    70,    -1,    72,    73,    74,    -1,
      -1,    -1,    -1,    -1,    80,    81,    -1,    -1,    84,    -1,
      -1,    87,    -1,    -1,    90,    -1,    92,    -1,    -1,    -1,
      -1,    -1,    -1,    99,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,    -1,   115,
      -1,    -1,   221,    -1,    -1,    -1,   122,   123,   124,   125,
     126,   230,    -1,   129,   130,   131,   132,   133,    -1,    -1,
     136,    -1,    -1,   139,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2111,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,    -1,    -1,    -1,    -1,
     221,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   230,
      -1,    -1,    -1,    -1,    -1,    -1,   182,   183,   184,   185,
     186,    -1,    -1,    -1,   190,   191,   192,   193,   194,   195,
      -1,   197,   198,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   212,   213,    -1,    -1,
      -1,   217,    -1,    -1,    -1,    -1,   222,    -1,     3,     4,
       5,   227,    -1,   229,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    -1,    -1,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    -1,    -1,    -1,
      65,    66,    67,    -1,    -1,    70,    -1,    72,    73,    74,
      -1,    -1,    -1,    -1,    -1,    80,    81,    -1,    -1,    84,
      -1,    -1,    87,    -1,    -1,    90,    -1,    92,    -1,    -1,
      -1,    -1,    -1,    -1,    99,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,    -1,
     115,    -1,    -1,   221,    -1,    -1,    -1,   122,   123,   124,
     125,   126,   230,    -1,   129,   130,   131,   132,   133,    -1,
      -1,   136,    -1,    -1,   139,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,    -1,
      -1,    -1,    -1,   221,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   230,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   182,   183,   184,
     185,   186,    -1,    -1,    -1,   190,   191,   192,   193,   194,
     195,    -1,   197,   198,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   212,   213,    -1,
      -1,    -1,   217,    -1,    -1,    -1,    -1,   222,    -1,     3,
       4,     5,   227,    -1,   229,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,
      54,    55,    56,    -1,    -1,    -1,    -1,    61,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,    73,
      74,    -1,    -1,    -1,    -1,    -1,    80,    -1,    -1,    -1,
      84,    -1,    -1,    87,    -1,    -1,    90,    -1,    92,    -1,
      -1,    -1,    -1,    -1,    -1,    99,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
      -1,   115,    -1,    -1,   221,    -1,    -1,    -1,   122,   123,
     124,   125,   126,   230,    -1,   129,   130,   131,   132,   133,
      -1,    -1,   136,    -1,    -1,   139,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
      -1,    -1,    -1,    -1,   221,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   230,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   182,    -1,
      -1,    -1,   186,    -1,    -1,    -1,   190,   191,   192,   193,
     194,    -1,    -1,    -1,   198,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   212,   213,
      -1,    -1,    -1,   217,    -1,    -1,    -1,    -1,   222,    -1,
       3,     4,     5,   227,    -1,   229,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      53,    54,    55,    56,    -1,    -1,    -1,    -1,    61,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,
      73,    74,    -1,    -1,    -1,    -1,    -1,    80,    -1,    -1,
      -1,    84,    -1,    -1,    87,    -1,    -1,    90,    -1,    92,
      -1,    -1,    -1,    -1,    -1,    -1,    99,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,    -1,   115,    -1,    -1,   221,    -1,    -1,    -1,   122,
     123,   124,   125,   126,   230,    -1,   129,   130,   131,   132,
     133,    -1,    -1,   136,    -1,    -1,   139,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,    -1,    -1,    -1,    -1,   221,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   230,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   182,
      -1,    -1,    -1,   186,    -1,    -1,    -1,   190,   191,   192,
     193,   194,    -1,    -1,    -1,   198,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   212,
     213,    -1,    -1,    -1,   217,    -1,    -1,    -1,    -1,   222,
      -1,     3,     4,     5,   227,    -1,   229,     9,    10,    11,
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
      -1,    80,    81,    -1,    -1,    -1,    -1,    -1,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,    -1,    -1,    -1,    -1,   221,    -1,    -1,    -1,
     182,   183,   184,   185,   186,   230,    -1,    -1,   190,   191,
     192,   193,   194,   195,    -1,   197,   198,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     212,   213,    -1,    -1,    -1,   217,    -1,    -1,    -1,    -1,
     222,    -1,    -1,    -1,    -1,   227,    -1,   229,    -1,    -1,
      -1,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,    -1,    -1,    -1,    -1,   221,
      -1,    -1,    -1,   182,   183,   184,   185,   186,   230,    -1,
      -1,   190,   191,   192,   193,   194,   195,    -1,   197,   198,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   212,   213,    -1,    -1,    -1,   217,    -1,
      -1,    -1,    -1,   222,    -1,     3,     4,    -1,   227,    -1,
     229,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    53,    54,    55,    56,    -1,
      -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    72,    73,    74,    -1,    -1,    -1,
      -1,    -1,    80,    -1,    -1,    -1,    84,    -1,    -1,    87,
      -1,    -1,    90,    -1,    92,    -1,    -1,    -1,    -1,    -1,
      -1,    99,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,    -1,   115,    -1,    -1,
     221,    -1,    -1,    -1,   122,   123,   124,   125,   126,   230,
      -1,   129,   130,   131,   132,   133,    -1,    -1,   136,    -1,
      -1,   139,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,    -1,    -1,    -1,    -1,
     221,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   230,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   182,    -1,    -1,    -1,   186,    -1,
      -1,    -1,   190,   191,   192,   193,   194,    -1,    -1,    -1,
     198,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   212,   213,    -1,    -1,    -1,   217,
      -1,    -1,    -1,    -1,   222,    -1,     3,     4,    -1,   227,
      -1,   229,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    53,    54,    55,    56,
      -1,    -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    72,    73,    74,    -1,    -1,
      -1,    -1,    -1,    80,    -1,    -1,    -1,    84,    -1,    -1,
      87,    -1,    -1,    90,    -1,    92,    -1,    -1,    -1,    -1,
      -1,    -1,    99,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,    -1,   115,    -1,
      -1,   221,    -1,    -1,    -1,   122,   123,   124,   125,   126,
     230,    -1,   129,   130,   131,   132,   133,    -1,    -1,   136,
      -1,    -1,   139,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,    -1,    -1,    -1,
      -1,   221,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     230,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   182,    -1,    -1,    -1,   186,
      -1,    -1,    -1,   190,   191,   192,   193,   194,    -1,    -1,
      -1,   198,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   212,   213,    -1,    -1,    -1,
     217,    -1,    -1,    -1,    -1,   222,    -1,     3,     4,    -1,
     227,    -1,   229,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,    54,    55,
      56,    -1,    -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    72,    73,    74,    -1,
      -1,    -1,    -1,    -1,    80,    -1,    -1,    -1,    84,    -1,
      -1,    87,    -1,    -1,    90,    -1,    92,    -1,    -1,    -1,
      -1,    -1,    -1,    99,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,    -1,   115,
      -1,    -1,   221,    -1,    -1,    -1,   122,   123,   124,   125,
     126,   230,    -1,   129,   130,   131,   132,   133,    -1,    -1,
     136,    -1,    -1,   139,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,    -1,    -1,
      -1,    -1,   221,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   230,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   182,    -1,    -1,    -1,
     186,    -1,    -1,    -1,   190,   191,   192,   193,   194,    -1,
      -1,    -1,   198,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   212,   213,    -1,    -1,
      -1,   217,    -1,    -1,    -1,    -1,   222,    -1,     3,     4,
      -1,   227,    -1,   229,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,    54,
      55,    56,    -1,    -1,    -1,    -1,    61,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,    73,    74,
      -1,    -1,    -1,    -1,    -1,    80,    -1,    -1,    -1,    84,
      -1,    -1,    87,    -1,    -1,    90,    -1,    92,    -1,    -1,
      -1,    -1,    -1,    -1,    99,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,    -1,
     115,    -1,    -1,   221,    -1,    -1,    -1,   122,   123,   124,
     125,   126,   230,    -1,   129,   130,   131,   132,   133,    -1,
      -1,   136,    -1,    -1,   139,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,    -1,
      -1,    -1,    -1,   221,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   230,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   182,    -1,    -1,
      -1,   186,    -1,    -1,    -1,   190,   191,   192,   193,   194,
      -1,    -1,    -1,   198,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   212,   213,    -1,
      -1,    -1,   217,    -1,    -1,    -1,    -1,   222,    -1,     3,
       4,    -1,   227,    -1,   229,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,
      54,    55,    56,    -1,    -1,    -1,    -1,    61,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,    73,
      74,    -1,    -1,    -1,    -1,    -1,    80,    -1,    -1,    -1,
      84,    -1,    -1,    87,    -1,    -1,    90,    -1,    92,    -1,
      -1,    -1,    -1,    -1,    -1,    99,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
      -1,   115,    -1,    -1,   221,    -1,    -1,    -1,   122,   123,
     124,   125,   126,   230,    -1,   129,   130,   131,   132,   133,
      -1,    -1,   136,    -1,    -1,   139,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
      -1,    -1,    -1,    -1,   221,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   230,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   182,    -1,
      -1,    -1,   186,    -1,    -1,    -1,   190,   191,   192,   193,
     194,    -1,    -1,    -1,   198,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   212,   213,
      -1,    -1,    -1,   217,    -1,    -1,    -1,    -1,   222,    -1,
       3,     4,    -1,   227,    -1,   229,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      53,    54,    55,    56,    -1,    -1,    -1,    -1,    61,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,
      73,    74,    -1,    -1,    -1,    -1,    -1,    80,    -1,    -1,
      -1,    84,    -1,    -1,    87,    -1,    -1,    90,    -1,    92,
      -1,    -1,    -1,    -1,    -1,    -1,    99,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,    -1,   115,    -1,    -1,   221,    -1,    -1,    -1,   122,
     123,   124,   125,   126,   230,    -1,   129,   130,   131,   132,
     133,    -1,    -1,   136,    -1,    -1,   139,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,    -1,    -1,    -1,    -1,   221,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   230,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   182,
      -1,    -1,    -1,   186,    -1,    -1,    -1,   190,   191,   192,
     193,   194,    -1,    -1,    -1,   198,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   212,
     213,    -1,    -1,    -1,   217,    -1,    -1,    -1,    -1,   222,
      -1,     3,     4,    -1,   227,    -1,   229,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    53,    54,    55,    56,    -1,    -1,    -1,    -1,    61,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      72,    73,    74,    -1,    -1,    -1,    -1,    -1,    80,    -1,
      -1,    -1,    84,    -1,    -1,    87,    -1,    -1,    90,    -1,
      92,    -1,    -1,    -1,    -1,    -1,    -1,    99,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,    -1,   115,    -1,    -1,   221,    -1,    -1,    -1,
     122,   123,   124,   125,   126,   230,    -1,   129,   130,   131,
     132,   133,    -1,    -1,   136,    -1,    -1,   139,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,    -1,    -1,    -1,    -1,   221,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   230,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     182,    -1,    -1,    -1,   186,    -1,    -1,    -1,   190,   191,
     192,   193,   194,    -1,    -1,    -1,   198,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     212,   213,    -1,    -1,    -1,   217,    -1,    -1,    -1,    -1,
     222,    -1,     3,     4,    -1,   227,    -1,   229,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    53,    54,    55,    56,    -1,    -1,    -1,    -1,
      61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    72,    73,    74,    -1,    -1,    -1,    -1,    -1,    80,
      -1,    -1,    -1,    84,    -1,    -1,    87,    -1,    -1,    90,
      -1,    92,    -1,    -1,    -1,    -1,    -1,    -1,    99,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,    -1,   115,    -1,    -1,   221,    -1,    -1,
      -1,   122,   123,   124,   125,   126,   230,    -1,   129,   130,
     131,   132,   133,    -1,    -1,   136,    -1,    -1,   139,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,    -1,    -1,    -1,    -1,   221,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   230,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   182,    -1,    -1,    -1,   186,    -1,    -1,    -1,   190,
     191,   192,   193,   194,    -1,    -1,    -1,   198,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   212,   213,    -1,    -1,    -1,   217,    -1,    -1,    -1,
      -1,   222,    -1,     3,     4,    -1,   227,    -1,   229,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    53,    54,    55,    56,    -1,    -1,    -1,
      -1,    61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    72,    73,    74,    -1,    -1,    -1,    -1,    -1,
      80,    -1,    -1,    -1,    84,    -1,    -1,    87,    -1,    -1,
      90,    -1,    92,    -1,    -1,    -1,    -1,    -1,    -1,    99,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,    -1,   115,    -1,    -1,   221,    -1,
      -1,    -1,   122,   123,   124,   125,   126,   230,    -1,   129,
     130,   131,   132,   133,    -1,    -1,   136,    -1,    -1,   139,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,    -1,    -1,    -1,    -1,   221,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   230,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   182,    -1,    -1,    -1,   186,    -1,    -1,    -1,
     190,   191,   192,   193,   194,    -1,    -1,    -1,   198,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   212,   213,    -1,    -1,    -1,   217,    -1,    -1,
      -1,    -1,   222,    -1,     3,     4,    -1,   227,    -1,   229,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    53,    54,    55,    56,    -1,    -1,
      -1,    -1,    61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    72,    73,    74,    -1,    -1,    -1,    -1,
      -1,    80,    -1,    -1,    -1,    84,    -1,    -1,    87,    -1,
      -1,    90,    -1,    92,    -1,    -1,    -1,    -1,    -1,    -1,
      99,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,    -1,   115,    -1,    -1,   221,
      -1,    -1,    -1,   122,   123,   124,   125,   126,   230,    -1,
     129,   130,   131,   132,   133,    -1,    -1,   136,    -1,    -1,
     139,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,    -1,    -1,    -1,    -1,   221,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   229,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,    -1,   182,    -1,    -1,   221,   186,   223,    -1,
     225,   190,   191,   192,   193,   194,    -1,    -1,    -1,   198,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   212,   213,    -1,    -1,    -1,   217,    -1,
      -1,    -1,    -1,   222,    -1,     3,     4,    -1,   227,    -1,
     229,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    -1,
      -1,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,    53,    54,    55,    56,   221,
      -1,    -1,    -1,    61,    -1,    -1,    -1,   229,    -1,    -1,
      -1,    -1,    -1,    -1,    72,    73,    74,     3,     4,     5,
      -1,    -1,    80,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    -1,    -1,    -1,    65,
      66,    67,    -1,    -1,    70,    -1,    72,    73,    74,    -1,
      -1,    -1,    -1,    -1,    80,    81,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
      -1,    -1,    -1,    -1,   221,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   229,    -1,   182,    -1,    -1,    -1,   186,    -1,
      -1,    -1,   190,   191,   192,   193,   194,    -1,    -1,    -1,
     198,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   212,   213,    -1,    -1,    -1,   217,
      -1,    -1,    -1,    -1,   222,    -1,    -1,    -1,    -1,   227,
      -1,   229,    -1,    -1,    -1,    -1,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
      -1,    -1,    -1,    -1,   221,    -1,   182,   183,   184,   185,
     186,   228,    -1,    -1,   190,   191,   192,   193,   194,   195,
      -1,   197,   198,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   212,   213,    -1,    -1,
      -1,   217,     3,     4,    -1,    -1,   222,    -1,     9,    10,
      11,   227,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    53,    54,    55,    56,    -1,    -1,    -1,    -1,
      61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    72,    73,    74,    -1,    -1,    -1,    -1,    -1,    80,
      -1,    -1,    -1,    84,    -1,    -1,    87,    -1,    -1,    90,
      -1,    92,    -1,    -1,    -1,    -1,    -1,    -1,    99,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,    -1,   115,    -1,    -1,   221,    -1,   223,
      -1,   122,   123,   124,   125,   126,    -1,    -1,   129,   130,
     131,   132,   133,    -1,    -1,   136,    -1,    -1,   139,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,    -1,    -1,    -1,    -1,   221,    -1,   223,
      -1,   225,    -1,    -1,   228,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,    -1,
      -1,   182,    -1,   221,    -1,   186,    -1,   225,    -1,   190,
     191,   192,   193,   194,    -1,    -1,    -1,   198,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   212,   213,    -1,    -1,    -1,   217,     3,     4,    -1,
      -1,   222,    -1,     9,    10,    11,   227,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    -1,    -1,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,    53,    54,    55,
      56,   221,    -1,   223,    -1,    61,    -1,    -1,   228,    -1,
      -1,    -1,    -1,    -1,     3,     4,    72,    73,    74,    -1,
       9,    10,    11,    -1,    80,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    -1,    -1,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,    53,    54,    55,    56,   221,    -1,
      -1,    -1,    61,    -1,    -1,   228,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    72,    73,    74,    -1,    -1,    -1,    -1,
      -1,    80,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,    -1,    -1,    -1,    -1,
     221,    -1,    -1,    -1,    -1,    -1,    -1,   228,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   182,    -1,    -1,    -1,
     186,    -1,    -1,    -1,   190,   191,   192,   193,   194,    -1,
      -1,    -1,   198,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   212,   213,    -1,    -1,
      -1,   217,    -1,    -1,    -1,    -1,   222,   223,    -1,    -1,
      -1,   227,    -1,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,    -1,    -1,    -1,
      -1,   221,    -1,   182,    -1,    -1,    -1,   186,   228,    -1,
      -1,   190,   191,   192,   193,   194,    -1,    -1,    -1,   198,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   212,   213,    -1,    -1,    -1,   217,    -1,
      -1,    -1,    -1,   222,     3,     4,   225,    -1,   227,    -1,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    -1,    -1,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,    53,    54,    55,    56,   221,    -1,
      -1,    -1,    61,    -1,    -1,   228,    -1,    -1,    -1,    -1,
      -1,     3,     4,    72,    73,    74,    -1,     9,    10,    11,
      -1,    80,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    -1,    -1,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,    53,    54,    55,    56,   221,    -1,    -1,    -1,    61,
      -1,    -1,   228,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      72,    73,    74,    -1,    -1,    -1,    -1,    -1,    80,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,    -1,    -1,    -1,    -1,   221,    -1,    -1,
      -1,    -1,    -1,    -1,   228,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   182,    -1,    -1,    -1,   186,    -1,    -1,
      -1,   190,   191,   192,   193,   194,    -1,    -1,    -1,   198,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   212,   213,    -1,    -1,    -1,   217,    -1,
      -1,    -1,    -1,   222,   223,    -1,    -1,    -1,   227,    -1,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,    -1,    -1,    -1,    -1,   221,    -1,
     182,    -1,    -1,    -1,   186,   228,    -1,    -1,   190,   191,
     192,   193,   194,    -1,    -1,    -1,   198,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     212,   213,    -1,    -1,    -1,   217,    -1,    -1,    -1,    -1,
     222,     3,     4,   225,     6,   227,    -1,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    -1,    -1,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,    53,    54,    55,    56,   221,    -1,    -1,    -1,    61,
      -1,    -1,   228,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      72,    73,    74,     3,     4,    -1,     6,    -1,    80,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    -1,    -1,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,    53,    54,    55,    56,   221,    -1,    -1,
      -1,    61,    -1,    -1,   228,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    72,    73,    74,    -1,    -1,    -1,    -1,    -1,
      80,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,    -1,    -1,    -1,    -1,   221,
      -1,    -1,    -1,    -1,    -1,    -1,   228,    -1,    -1,    -1,
     182,    -1,    -1,    -1,   186,    -1,    -1,    -1,   190,   191,
     192,   193,   194,    -1,    -1,    -1,   198,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     212,   213,    -1,    -1,    -1,   217,    -1,    -1,    -1,    -1,
     222,    -1,    -1,    -1,    -1,   227,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
      -1,    -1,    -1,    -1,   221,    -1,    -1,    -1,    -1,    -1,
      -1,   228,   182,    -1,    -1,    -1,   186,    -1,    -1,    -1,
     190,   191,   192,   193,   194,    -1,    -1,    -1,   198,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   212,   213,    -1,    -1,    -1,   217,     3,     4,
      -1,    -1,   222,    -1,     9,    10,    11,   227,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    -1,    -1,    -1,    12,    13,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,    54,
      55,    56,    -1,    -1,    -1,    -1,    61,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,    73,    74,
      -1,    -1,    12,    13,    -1,    80,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
      -1,    -1,    -1,    -1,   221,    -1,    -1,    -1,    -1,    -1,
      -1,   228,    -1,    -1,    -1,    -1,    -1,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      -1,    -1,    -1,   100,   101,   102,    -1,   104,    -1,    -1,
      -1,    -1,   109,   110,   111,   112,    -1,   114,   115,   116,
      -1,    -1,    -1,   120,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    12,    13,    -1,
     100,   101,   102,    -1,   104,    -1,    -1,    -1,    -1,   109,
     110,   111,   112,    -1,   114,   115,   116,   182,    -1,    -1,
     120,   186,   159,   160,   161,   190,   191,   192,   193,   194,
      -1,    -1,    -1,   198,    12,    13,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   212,   213,    -1,
      -1,    -1,   217,    -1,    -1,    -1,    -1,   222,    -1,   159,
     160,   161,   227,    -1,    -1,    -1,    -1,    -1,    -1,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    -1,    -1,    -1,   100,   101,   102,    -1,   104,
      -1,    -1,    -1,   230,   109,   110,   111,   112,    -1,   114,
     115,   116,    -1,    -1,    -1,   120,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    12,
      13,    -1,   100,   101,   102,    -1,   104,    -1,    -1,    -1,
     230,   109,   110,   111,   112,    -1,   114,   115,   116,    -1,
      -1,    -1,   120,    -1,   159,   160,   161,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    12,    13,    -1,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,    -1,    -1,    -1,    -1,   221,    -1,    -1,
      -1,   159,   160,   161,   228,    -1,    -1,    -1,    -1,    -1,
      -1,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    -1,    -1,    -1,   100,   101,   102,
      -1,   104,    -1,    -1,    -1,   230,   109,   110,   111,   112,
      -1,   114,   115,   116,    -1,    -1,    -1,   120,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    -1,    -1,    -1,   100,   101,   102,    -1,   104,    -1,
      -1,    -1,   230,   109,   110,   111,   112,    -1,   114,   115,
     116,    -1,    -1,    -1,   120,    -1,   159,   160,   161,    -1,
      -1,     0,     1,    -1,    -1,     4,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    12,    13,    -1,    -1,    -1,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,    -1,   159,   160,   161,   221,    -1,    -1,    -1,
     225,    -1,    -1,    42,    43,    -1,    -1,    -1,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,    -1,    62,    63,    64,   221,   230,    -1,    68,
      69,    -1,    71,   228,    -1,    -1,    75,    76,    -1,    78,
      79,    -1,    -1,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    -1,    -1,
      99,   100,   101,   102,   230,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,    -1,
     119,   120,   121,   122,   123,   124,   125,   126,   127,    -1,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,    -1,    -1,    -1,   145,   146,   147,    -1,
      -1,    -1,    -1,    -1,   153,     4,    -1,    -1,    -1,   158,
     159,   160,   161,    12,    13,   164,    -1,   166,    -1,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,    -1,    -1,    -1,    -1,    -1,   187,   188,
     189,    -1,    -1,    42,    43,    -1,    -1,   196,    -1,   198,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    62,    63,    64,    -1,    -1,    -1,    68,
      69,    -1,    71,    -1,    -1,    -1,    75,    76,    -1,    78,
      79,    -1,    -1,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    -1,    -1,
      99,   100,   101,   102,    -1,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,    -1,
     119,   120,   121,   122,   123,   124,   125,   126,   127,    -1,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,    -1,    -1,    -1,   145,   146,   147,    -1,
      -1,    -1,    -1,    -1,   153,    -1,    -1,    -1,    -1,   158,
     159,   160,   161,    -1,    -1,   164,    -1,   166,    -1,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,    -1,    -1,    -1,    -1,    -1,   187,   188,
     189,    -1,    -1,    -1,    -1,    -1,    -1,   196,    -1,   198,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,    -1,    -1,    -1,    -1,   221,    -1,
      -1,    -1,    -1,    -1,    -1,   228,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
      -1,    -1,    -1,    -1,   221,    -1,    -1,    -1,    -1,    -1,
      -1,   228,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,    -1,    -1,    -1,    -1,
     221,    -1,    -1,    -1,    -1,    -1,    -1,   228,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,    -1,    -1,    -1,    -1,   221,    -1,    -1,    -1,
      -1,    -1,    -1,   228,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,    -1,    -1,
      -1,    -1,   221,    -1,    -1,    -1,    -1,    -1,    -1,   228,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,    -1,    -1,    -1,    -1,   221,    -1,
      -1,    -1,    -1,    -1,    -1,   228,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
      -1,    -1,    -1,    -1,   221,    -1,    -1,    -1,    -1,    -1,
      -1,   228,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,    -1,    -1,    -1,    -1,
     221,    -1,    -1,    -1,    -1,    -1,    -1,   228,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,    -1,    -1,    -1,    -1,   221,    -1,    -1,    -1,
      -1,    -1,    -1,   228,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,    -1,    -1,
      -1,    -1,   221,    -1,    -1,    -1,    -1,    -1,    -1,   228,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,    -1,    -1,    -1,    -1,   221,    -1,
      -1,    -1,    -1,    -1,    -1,   228,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
      -1,    -1,    -1,    -1,   221,    -1,    -1,    -1,    -1,    -1,
      -1,   228,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,    -1,    -1,    -1,    -1,
     221,    -1,    -1,    -1,    -1,    -1,    -1,   228,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,    -1,    -1,    -1,    -1,   221,    -1,    -1,    -1,
      -1,    -1,    -1,   228,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,    -1,    -1,
      -1,    -1,   221,    -1,    -1,    -1,    -1,    -1,    -1,   228,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,    -1,    -1,    -1,    -1,   221,    -1,
      -1,    -1,    -1,    -1,    -1,   228,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
      -1,    -1,    -1,    -1,   221,    -1,    -1,    -1,    -1,    -1,
      -1,   228,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,    -1,    -1,    -1,    -1,
     221,    -1,    -1,    -1,    -1,    -1,    -1,   228,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,    -1,    -1,    -1,    -1,   221,    -1,    -1,    -1,
      -1,    -1,    -1,   228,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,    -1,    -1,
      -1,    -1,   221,    -1,    -1,    -1,    -1,    -1,    -1,   228,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,    -1,    -1,    -1,    -1,   221,    -1,
      -1,    -1,    -1,    -1,    -1,   228,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
      -1,    -1,    -1,    -1,   221,    -1,    -1,    -1,    -1,    -1,
      -1,   228,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,    -1,    -1,    -1,    -1,
     221,    -1,    -1,    -1,    -1,    -1,    -1,   228,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,    -1,    -1,    -1,    -1,   221,    -1,    -1,    -1,
      -1,    -1,    -1,   228,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,    -1,    -1,
      -1,    -1,   221,    -1,    -1,    -1,    -1,    -1,    -1,   228,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,    -1,    -1,    -1,    -1,   221,    -1,
      -1,    -1,    -1,    -1,    -1,   228,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
      -1,    -1,    -1,    -1,   221,    -1,    -1,    -1,    -1,    -1,
      -1,   228,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,    -1,    -1,    -1,    -1,
     221,    -1,    -1,    -1,    -1,    -1,    -1,   228,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,    -1,    -1,    -1,    -1,   221,    -1,    -1,    -1,
      -1,    -1,    -1,   228,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,    -1,    -1,
      -1,    -1,   221,    -1,    -1,    -1,    -1,    -1,    -1,   228,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,    -1,    -1,    -1,    -1,   221,    -1,
      -1,    -1,    -1,    -1,    -1,   228,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
      -1,    -1,    -1,    -1,   221,    -1,    -1,    -1,    -1,    -1,
      -1,   228,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,    -1,    -1,    -1,    -1,
     221,    -1,    -1,    -1,    -1,    -1,    -1,   228,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,    -1,    -1,    -1,    -1,   221,    -1,    -1,    -1,
      -1,    -1,    -1,   228,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,    -1,    -1,
      -1,    -1,   221,    -1,    -1,    -1,    -1,    -1,    -1,   228,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,    -1,    -1,    -1,    -1,   221,    -1,
      -1,    -1,    -1,    -1,    -1,   228,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
      -1,    -1,    -1,    -1,   221,    -1,    -1,    -1,    -1,    -1,
      -1,   228,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,    -1,    -1,    -1,    -1,
     221,    -1,    -1,    -1,    -1,    -1,    -1,   228,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,    -1,    -1,    -1,    -1,   221,    -1,    -1,    -1,
      -1,    -1,    -1,   228,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,    -1,    -1,
      -1,    -1,   221,    -1,    -1,    -1,    -1,    -1,    -1,   228,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,    -1,    -1,    -1,    -1,   221,    -1,
      -1,    -1,   225,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,    -1,    -1,    -1,
      -1,   221,    -1,    -1,    -1,   225,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
      -1,    -1,    -1,    -1,   221,    -1,    -1,    -1,   225,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,    -1,    -1,    -1,    -1,   221,    -1,    -1,
      -1,   225,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,    -1,    -1,    -1,    -1,
     221,    -1,    -1,    -1,   225,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,    -1,
      -1,    -1,    -1,   221,    -1,    -1,    -1,   225,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,    -1,    -1,    -1,    -1,   221,    -1,    -1,    -1,
     225,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,    -1,    -1,    -1,    -1,   221,
      -1,    -1,    -1,   225,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,    -1,    -1,
      -1,    -1,   221,    -1,    -1,    -1,   225,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,    -1,    -1,    -1,    -1,   221,    -1,    -1,    -1,   225,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,    -1,    -1,    -1,    -1,   221,    -1,
      -1,    -1,   225,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,    -1,    -1,    -1,
      -1,   221,    -1,    -1,    -1,   225,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
      -1,    -1,    -1,    -1,   221,    -1,    -1,    -1,   225,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,    -1,    -1,    -1,    -1,   221,    -1,    -1,
      -1,   225,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,    -1,    -1,    -1,    -1,
     221,    -1,    -1,    -1,   225,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,    -1,
      -1,    -1,    -1,   221,    -1,   223,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
      -1,    -1,    -1,    -1,   221,    -1,   223,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,    -1,    -1,    -1,    -1,   221,    -1,   223,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,    -1,    -1,    -1,    -1,   221,    -1,   223,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,    -1,    -1,    -1,    -1,   221,    -1,   223,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,    -1,    -1,    -1,    -1,   221,    -1,
     223,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,    -1,    -1,    -1,    -1,   221,
      -1,   223,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,    -1,    -1,    -1,    -1,
     221,    -1,   223,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,    -1,    -1,    -1,
      -1,   221,    -1,   223,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,    -1,    -1,
      -1,    -1,   221,    -1,   223,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,    -1,
      -1,    -1,    -1,   221,    -1,   223,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
      -1,    -1,    -1,    -1,   221,    -1,   223,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,    -1,    -1,    -1,    -1,   221,    -1,   223,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,    -1,    -1,    -1,    -1,   221,    -1,   223,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,    -1,    -1,    -1,    -1,   221,    -1,   223,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,    -1,    -1,    -1,    -1,   221,    -1,
     223,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,    -1,    -1,    -1,    -1,   221,
      -1,   223,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,    -1,    -1,    -1,    -1,
     221,    -1,   223,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,    -1,    -1,    -1,
      -1,   221,    -1,   223,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,    -1,    -1,
      -1,    -1,   221,    -1,   223,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,    -1,
      -1,    -1,    -1,   221,    -1,   223,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
      -1,    -1,    -1,    -1,   221,    -1,   223,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,    -1,    -1,    -1,    -1,   221,    -1,   223,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,    -1,    -1,    -1,    -1,   221,    -1,   223,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,    -1,    -1,    -1,    -1,   221,    -1,   223,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,    -1,    -1,    -1,    -1,   221,    -1,
     223,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,    -1,    -1,    -1,    -1,   221,
      -1,   223,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,    -1,    -1,    -1,    -1,
     221,    -1,   223,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,    -1,    -1,    -1,
      -1,   221,    -1,   223,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,    -1,    -1,
      -1,    -1,   221,    -1,   223,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,    -1,
      -1,    -1,    -1,   221,    -1,   223,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
      -1,    -1,    -1,    -1,   221,    -1,   223,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,    -1,    -1,    -1,    -1,   221,    -1,   223,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,    -1,    -1,    -1,    -1,   221,    -1,   223,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,    -1,    -1,    -1,    -1,   221,    -1,   223,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,    -1,    -1,    -1,    -1,   221,    -1,
     223,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,    -1,    -1,    -1,    -1,   221,
      -1,   223,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,    -1,    -1,    -1,    -1,
     221,    -1,   223,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,    -1,    -1,    -1,
      -1,   221,    -1,   223,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,    -1,    -1,
      -1,    -1,   221,    -1,   223,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,    -1,
      -1,    -1,    -1,   221,    -1,   223,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
      -1,    -1,    -1,    -1,   221,    -1,   223,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,    -1,    -1,    -1,    -1,   221,    -1,   223,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,    -1,    -1,    -1,    -1,   221,    -1,   223,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,    -1,    -1,    -1,    -1,   221,    -1,   223,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,    -1,    -1,    -1,    -1,   221,    -1,
     223,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,    -1,    -1,    -1,    -1,   221,
      -1,   223,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,    -1,    -1,    -1,    -1,
     221,    -1,   223,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,    -1,    -1,    -1,
      -1,   221,    -1,   223,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,    -1,    -1,
      -1,    -1,   221,    -1,   223,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,    -1,
      -1,    -1,    -1,   221,    -1,   223,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
      -1,    -1,    -1,    -1,   221,    -1,   223,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,    -1,    -1,    -1,    -1,   221,    -1,   223,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,    -1,    -1,    -1,    -1,   221
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,   233,   234,     6,     0,     4,    12,    13,    42,
      43,    62,    63,    64,    68,    69,    71,    75,    76,    78,
      79,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    99,   100,   101,   102,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   145,   146,   147,   153,
     158,   159,   160,   161,   164,   166,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     187,   188,   189,   196,   198,   235,   237,   238,   258,   277,
     278,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     305,   307,   308,   314,   315,   316,   317,   335,   336,     3,
       4,     5,     9,    10,    11,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    65,    66,    67,    70,
      72,    73,    74,    80,    81,   175,   182,   183,   184,   185,
     186,   190,   191,   192,   193,   194,   195,   197,   212,   213,
     217,   222,   224,   226,   227,   229,   231,   256,   318,   319,
     331,   332,   335,   336,    13,    90,   222,   222,     6,   229,
       6,     6,     6,     6,   222,     6,     6,   224,   224,   222,
     224,   256,   256,   222,   229,   222,   222,     4,   222,   229,
     222,   222,     4,   229,   222,   222,   222,   222,   222,   222,
     222,   222,   222,   103,    90,    90,     6,   229,    84,    87,
      90,   222,   222,    90,    90,    87,    90,    92,    92,    84,
      87,    90,    92,    87,    90,    92,    87,    90,   222,    87,
     164,   180,   181,   229,   212,   213,   222,   229,   321,   322,
     321,   229,    84,    87,    90,   229,   321,     4,    84,    88,
      94,    95,    97,    98,   111,    90,    92,    90,    87,     4,
     175,   229,   335,   336,     4,     6,    84,    87,    90,    87,
      90,     4,     4,     4,     4,     5,    37,    38,    39,    40,
      41,    84,    87,    90,    92,   115,   213,   222,   229,   278,
     289,   305,   307,   318,   324,   325,   326,   335,   336,     4,
     222,   222,   222,     4,   229,   328,   336,     4,   222,   222,
     222,     6,     6,   224,     4,   332,   336,   222,     4,   332,
       5,   229,     5,   229,     4,   318,   335,   224,   222,   229,
       6,   222,   229,   222,   224,   231,   256,     7,   199,   200,
     201,   202,   219,   220,   254,   255,     4,   222,   224,   226,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   256,   256,   222,   222,   222,   256,   256,
     256,   256,   222,   256,   256,   256,   256,   256,   256,   222,
     256,   256,   256,     7,   222,   222,   222,   256,   256,   222,
     222,   224,   318,   318,   318,   223,   318,   225,   318,     4,
     164,   165,   336,     4,   278,   279,   280,   229,   229,     6,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   221,   229,     6,   222,   224,   255,
       6,   318,     4,   331,   332,   335,   336,   331,   318,   331,
     334,   260,   265,   332,   336,   318,   213,   318,   326,   327,
     318,   318,   222,   318,   327,   318,   318,   222,   327,   318,
     318,   318,   318,   318,   318,   331,   318,   318,   324,   222,
     229,   327,   325,   325,   325,   331,   318,   222,   222,   325,
     325,   325,   222,   222,   222,   222,   222,   222,   324,   222,
     324,   222,   324,   229,   229,   318,     4,   324,   328,   229,
     229,   321,   321,   321,   318,   318,   212,   213,   229,   229,
     321,   229,   229,   229,   212,   213,   222,   280,   321,   229,
     222,   229,   222,   222,   222,   222,   222,   222,   222,   325,
     325,   324,   222,     4,   224,   224,   280,     6,     6,   229,
     229,   229,   325,   325,   224,   224,   224,   222,   224,   226,
     256,   222,   224,   256,   256,   256,   256,     5,   167,   229,
       5,   167,     5,   167,     5,   167,    84,    87,    90,    92,
     229,   318,   326,   318,   230,   327,     8,   214,     6,   222,
     224,   256,     6,   318,   318,   318,   226,   318,   229,   167,
     318,   318,   318,   318,     6,     6,   229,     6,   280,     6,
     280,   222,   224,   229,   222,   224,   331,   318,   280,   324,
     324,   223,   318,   225,   318,   229,   229,   332,   324,     6,
     224,   318,   318,     4,   318,   318,   318,   318,   318,   318,
     318,   318,   318,   318,   318,   318,   318,   318,   318,   318,
     318,   318,   318,   318,   318,   318,   334,   331,   334,   331,
     331,   331,   331,   331,   331,   331,   324,   331,   331,   318,
     331,   331,   331,   334,   331,   318,   332,   318,   331,   331,
     331,   331,   331,   336,   332,   336,     7,   202,   254,   223,
       7,   202,   254,   225,     7,   254,   255,   226,     7,   256,
     230,    84,    87,    90,    92,   277,   318,   327,   318,   318,
     318,   318,   318,   318,   318,   318,   318,   318,   318,   318,
     318,   318,   318,   239,   318,   318,     6,   222,   224,   226,
     223,   228,   222,   224,   223,   228,   228,   223,   228,   225,
     228,   259,   225,   259,   228,   228,   223,   214,   228,   230,
     223,   223,   318,   223,   230,   223,   223,   318,   230,   223,
     223,   223,   223,   223,   223,   223,   223,   223,     7,   318,
     318,   230,     6,     6,     6,   223,   223,   318,   318,     7,
       7,   311,   311,   318,   271,   318,   332,   272,   318,   332,
     273,   318,   332,   274,   318,   332,   318,     6,   318,     6,
     318,     6,   327,   327,   229,   223,     6,   229,   280,   280,
     228,   228,   228,   321,   321,   279,   279,   228,   318,   318,
     318,   318,   293,   228,   280,   318,   318,   318,   318,   318,
     318,   318,   318,   318,     7,   312,     6,     7,   318,     6,
     318,   318,   230,   327,   327,   327,     6,     6,   318,   318,
     318,   318,   318,     4,   223,   225,   229,   257,   229,   318,
     326,   229,   326,   336,   318,   318,   331,   318,    62,   318,
      62,    62,    62,     5,   229,     5,   229,     5,   229,     5,
     229,   327,   223,   230,   318,   229,   318,   326,   318,   318,
     229,   257,   223,   223,   223,   164,   228,   280,   229,     8,
     223,   223,   225,   327,   230,   230,   280,   225,   223,   137,
     306,   223,   228,   230,     7,   202,   254,   223,     7,   202,
     254,   225,   318,   327,     6,     6,   318,   223,   225,   255,
     257,   257,   257,   257,   257,   257,   257,   257,   257,   257,
     257,   228,   257,   257,   257,   257,   257,   257,   257,   228,
     228,   228,   257,   228,   257,   257,   223,   223,   228,   257,
     257,   228,   257,   228,   228,   228,   228,   257,   257,   257,
     223,   257,   320,   333,     6,   228,   228,   223,   228,   257,
     228,   257,   223,   223,   225,    44,    44,   324,     7,   254,
     255,    44,    44,   324,   226,   254,   255,   332,   318,     6,
       4,     4,   229,   329,   257,   229,   229,   229,   229,   230,
     230,     8,     4,   154,   155,   156,   157,   230,   242,   246,
     249,   251,   252,   223,   225,   318,   318,     4,     6,   209,
     236,   327,   318,   318,     6,   327,   318,     6,   331,     6,
     336,     6,   331,   318,   332,     7,   318,   326,   167,     7,
       7,   223,     7,   167,     7,     7,   223,   167,     7,     7,
       7,     7,     7,     7,     7,     7,   318,   223,   230,   229,
       6,     7,   223,   223,   318,   324,     4,   310,     6,   223,
     223,   228,   223,   228,   223,   228,   223,   228,   223,   223,
     223,   230,   230,   327,   226,   280,   230,   230,   321,   318,
     318,   230,   230,   318,   321,   228,   228,   228,   118,   134,
     142,   143,   144,   148,   149,   150,   151,   303,   304,   321,
     230,   290,   223,   230,   223,   223,   223,   223,   223,   223,
     223,   318,     6,   318,   223,   225,   225,   230,   230,   230,
     225,   225,   228,   223,   225,   327,   327,   223,   327,   225,
     225,   228,   228,   257,   228,   229,   230,   229,   229,   229,
     327,   327,   327,   327,   230,     8,   327,   223,   225,   327,
       7,     7,     7,   226,   318,   230,   318,   318,     7,   226,
     230,   230,     7,     6,   318,   230,   229,   324,     6,    44,
      44,   324,   254,   255,    44,    44,   324,   254,   255,   230,
     230,   225,   255,   226,   255,   331,   318,   318,   318,   318,
     327,   331,   318,   324,   331,   331,   331,   267,   269,   318,
     331,   331,   318,   256,   256,     6,   318,     6,   256,   256,
       6,     4,   164,   165,   318,     6,     6,     6,     7,   224,
     328,   330,     6,   327,   327,   327,   327,   257,   318,   243,
     222,   222,   229,   253,     6,   255,   255,   223,   225,   209,
     331,   223,   223,   225,   223,   228,     7,   222,   224,   257,
     257,   321,    90,    92,   324,   324,     7,   324,    90,    92,
     324,   324,     7,    92,   324,   324,   324,   324,   324,   324,
     324,   324,     6,     7,     7,   327,   324,     7,     7,   118,
     309,     6,     7,   254,   318,   254,   318,   254,   318,   254,
     318,     7,     7,     7,     7,     7,   230,     4,   230,   228,
     228,   228,   230,   230,   321,   321,   321,     4,     6,   318,
     229,     6,   222,     6,   152,     6,   152,     6,   152,     6,
     152,   230,   304,   228,   303,     7,     6,     7,     7,     7,
       7,     7,     7,     7,     6,   229,     6,     6,     6,    90,
       7,     6,     6,   318,   226,   230,   230,   230,   318,   318,
     318,   318,   318,   318,   318,   230,   230,   230,   230,   318,
     230,   230,   324,   324,   324,     4,   228,     8,     8,   223,
       4,     4,   228,   229,     6,   229,   324,   230,   256,   256,
       6,   318,     6,   256,   256,     6,   318,     6,   257,     6,
       4,     6,   257,   257,   257,   257,   257,   228,   228,   257,
     223,   257,   257,   228,   228,   257,   268,   228,   257,   270,
     223,   223,   257,   257,   257,   334,   334,     6,   257,   334,
     334,     7,   254,   255,   226,     7,     6,   328,   318,   228,
     230,   230,   230,   230,   230,   254,   222,   318,   318,   323,
     324,   229,   226,     6,     6,   236,     6,   318,   229,   318,
     332,   223,   225,     6,     6,     6,   229,   229,   111,   276,
     276,   324,     6,   229,   229,     6,     6,   324,   229,     6,
       6,     6,     6,     6,     6,     6,     6,     5,   324,   230,
       6,   324,   324,     4,     6,   324,   324,   324,   324,   324,
     324,   324,   324,   229,   229,     7,     6,     7,   318,   318,
     318,   229,   229,   228,   230,   228,   230,   228,   230,   224,
       6,   318,   324,   318,     6,     6,     6,     6,   318,   321,
     230,     5,   324,   229,   229,   229,   229,   229,   229,   229,
     324,   327,   229,   318,   225,     4,   257,   223,   225,   228,
     228,   228,   228,   228,   228,   228,   257,     6,     6,   163,
     318,   318,   318,     6,     6,     7,   332,   280,   280,   228,
       6,   257,   334,   334,     6,   257,   334,   334,     6,   254,
     255,   331,   318,   331,     4,     4,   179,     6,   257,   257,
       6,   257,   257,   332,   318,     6,     4,   329,     6,   225,
     328,     6,     6,     6,     6,   324,   240,   318,   228,   228,
     228,   230,   241,   318,     4,   331,   228,   324,   332,     7,
       7,   318,   318,   321,     6,     6,     6,   318,   318,     6,
     318,     5,     6,   229,     6,   167,   275,   318,     6,     6,
       6,     6,     6,     6,     4,     6,     6,   327,   327,   318,
     318,   332,   230,   223,   228,   230,   279,   279,   321,     6,
     294,   321,     6,   295,   321,     6,   296,   318,   230,   228,
     223,   230,   228,     6,     6,   323,   321,   321,   321,   321,
     321,   213,   321,     6,   230,   318,     6,     6,   318,   318,
     318,   318,   318,   318,   318,   324,   228,   230,     8,   230,
     223,   229,   318,   332,   228,   306,   306,   324,     6,   257,
     257,     6,   257,   257,   324,   223,   257,   257,   229,   324,
     332,   229,   318,   332,   332,     6,     6,     6,     6,     6,
       6,     7,     6,   226,     6,   223,   228,   318,   318,   324,
     229,   228,   230,     6,   318,   261,   264,   229,   229,   230,
     230,   230,   230,   230,     5,   323,    88,     6,   229,   230,
     230,   229,     6,     6,   229,   318,   230,   230,   228,   229,
     228,   229,   228,   229,   225,     6,   324,     7,   229,   318,
     230,   228,   228,   228,   228,   228,   228,     6,   230,   257,
     257,   228,   228,   228,   228,   228,   162,   318,   318,   327,
       6,     6,   332,   230,   230,   230,     6,     6,     6,     6,
       6,   266,   318,   326,   334,   328,   165,   244,   318,   228,
     228,   323,   318,     6,   228,   267,   269,   324,   324,     6,
       6,     6,     6,     6,     6,   230,   229,   323,   122,   123,
     128,   313,   122,   123,   313,   327,   279,   228,   230,   318,
     321,   303,   318,   321,   303,   318,   321,   303,     6,   228,
     230,   324,   280,   230,     6,   327,   321,   321,   321,   321,
     321,   318,   318,   318,   318,   318,   318,   230,   230,   230,
     223,   229,     6,   228,   230,     7,     7,   230,     6,   229,
     318,   318,   230,   318,   230,   230,   263,   262,   229,   318,
     230,   229,   321,   324,     6,   229,   321,     6,   230,   230,
     318,   230,   228,   230,   230,   228,   230,   230,   228,   230,
     324,     6,   118,   230,   291,   229,   230,   228,   228,   228,
     228,   228,   228,   228,   228,   228,   228,     6,     6,     6,
     280,   318,   332,   336,   241,   223,   228,     6,   229,   228,
     267,   267,   318,   230,     6,   321,     6,   321,     6,     6,
     230,     6,   297,   318,     6,     6,   298,   318,     6,     6,
     299,   318,     6,   230,   318,   303,   280,     6,   327,   327,
     327,   327,   321,   327,   318,   318,   318,   318,   318,   306,
       7,   222,   230,   247,   318,   323,   318,   230,   230,   228,
     228,   228,   229,   230,   229,   230,   229,   230,     6,     6,
     230,   230,   292,   230,   230,   230,   230,   228,   230,   228,
     228,   228,   228,   228,   230,   332,   223,     6,   229,   223,
     230,   230,   318,   321,   321,   303,     6,   300,   303,     6,
     301,   303,     6,   302,   303,     6,     6,     6,     6,   327,
       6,   318,   318,   318,   318,   318,     6,   245,   331,   250,
     229,     6,   230,   228,   228,   230,   229,   230,   229,   230,
     229,   230,   230,   257,   228,   228,   228,   228,   228,   230,
     229,   323,     6,   318,   318,     6,   303,     6,   303,     6,
     303,     6,   318,   318,   318,   318,   331,     6,   248,   331,
     230,   230,   230,   230,   230,   230,   230,   230,   230,   230,
     228,   230,     6,     6,     6,     6,     6,     6,   331,     6
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

  case 198:
#line 2426 "Gmsh.y"
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
#line 2454 "Gmsh.y"
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

  case 200:
#line 2481 "Gmsh.y"
    {
      GModel::current()->getGEOInternals()->addCompoundMesh ( 2 , (yyvsp[(3) - (4)].l) );
    ;}
    break;

  case 201:
#line 2485 "Gmsh.y"
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

  case 202:
#line 2505 "Gmsh.y"
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

  case 203:
#line 2538 "Gmsh.y"
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

  case 204:
#line 2585 "Gmsh.y"
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

  case 205:
#line 2603 "Gmsh.y"
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

  case 206:
#line 2630 "Gmsh.y"
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

  case 207:
#line 2648 "Gmsh.y"
    {
      GModel::current()->getGEOInternals()->addCompoundMesh(3, (yyvsp[(3) - (4)].l));
    ;}
    break;

  case 208:
#line 2652 "Gmsh.y"
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

  case 209:
#line 2668 "Gmsh.y"
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
#line 2716 "Gmsh.y"
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

  case 211:
#line 2733 "Gmsh.y"
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

  case 212:
#line 2751 "Gmsh.y"
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

  case 213:
#line 2761 "Gmsh.y"
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

  case 214:
#line 2771 "Gmsh.y"
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

  case 215:
#line 2781 "Gmsh.y"
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

  case 216:
#line 2844 "Gmsh.y"
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

  case 217:
#line 2855 "Gmsh.y"
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

  case 218:
#line 2870 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 219:
#line 2871 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 220:
#line 2876 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    ;}
    break;

  case 221:
#line 2880 "Gmsh.y"
    {
      List_Add((yyval.l), &(yyvsp[(2) - (2)].s));
    ;}
    break;

  case 222:
#line 2884 "Gmsh.y"
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

  case 223:
#line 2913 "Gmsh.y"
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

  case 224:
#line 2942 "Gmsh.y"
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

  case 225:
#line 2971 "Gmsh.y"
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

  case 226:
#line 3005 "Gmsh.y"
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
#line 3027 "Gmsh.y"
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
#line 3054 "Gmsh.y"
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
#line 3076 "Gmsh.y"
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
#line 3098 "Gmsh.y"
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
#line 3120 "Gmsh.y"
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
#line 3176 "Gmsh.y"
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
#line 3200 "Gmsh.y"
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
#line 3225 "Gmsh.y"
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
#line 3250 "Gmsh.y"
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
#line 3363 "Gmsh.y"
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
#line 3382 "Gmsh.y"
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
#line 3425 "Gmsh.y"
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

  case 239:
#line 3446 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      GModel::current()->getFields()->deleteField((int)(yyvsp[(4) - (6)].d));
#endif
    ;}
    break;

  case 240:
#line 3452 "Gmsh.y"
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
#line 3467 "Gmsh.y"
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

  case 242:
#line 3495 "Gmsh.y"
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
#line 3512 "Gmsh.y"
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
#line 3521 "Gmsh.y"
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
#line 3535 "Gmsh.y"
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
#line 3549 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 1, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 247:
#line 3555 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 0, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 248:
#line 3561 "Gmsh.y"
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
#line 3570 "Gmsh.y"
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
#line 3579 "Gmsh.y"
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
#line 3588 "Gmsh.y"
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
#line 3602 "Gmsh.y"
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

  case 253:
#line 3664 "Gmsh.y"
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
#line 3682 "Gmsh.y"
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
#line 3699 "Gmsh.y"
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
#line 3714 "Gmsh.y"
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

  case 257:
#line 3743 "Gmsh.y"
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
#line 3755 "Gmsh.y"
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
#line 3779 "Gmsh.y"
    {
      Msg::Exit(0);
    ;}
    break;

  case 260:
#line 3783 "Gmsh.y"
    {
      gmsh_yyerrorstate = 999; // this will be checked when yyparse returns
      YYABORT;
    ;}
    break;

  case 261:
#line 3788 "Gmsh.y"
    {
      // FIXME: this is a hack to force a transfer from the old DB to
      // the new DB. This will become unnecessary if/when we fill the
      // GModel directly during parsing.
      GModel::current()->importGEOInternals();
      GModel::current()->importOCCInternals();
    ;}
    break;

  case 262:
#line 3796 "Gmsh.y"
    {
      new GModel();
      GModel::current(GModel::list.size() - 1);
    ;}
    break;

  case 263:
#line 3801 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 0;
      GModel::current()->importGEOInternals();
      SetBoundingBox();
    ;}
    break;

  case 264:
#line 3807 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 1;
      SetBoundingBox((yyvsp[(3) - (15)].d), (yyvsp[(5) - (15)].d), (yyvsp[(7) - (15)].d), (yyvsp[(9) - (15)].d), (yyvsp[(11) - (15)].d), (yyvsp[(13) - (15)].d));
    ;}
    break;

  case 265:
#line 3812 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
      drawContext::global()->draw();
#endif
    ;}
    break;

  case 266:
#line 3818 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
     CTX::instance()->mesh.changed = ENT_ALL;
     for(unsigned int index = 0; index < PView::list.size(); index++)
       PView::list[index]->setChanged(true);
#endif
    ;}
    break;

  case 267:
#line 3826 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh();
    ;}
    break;

  case 268:
#line 3830 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh(1);
    ;}
    break;

  case 269:
#line 3834 "Gmsh.y"
    {
      GModel::current()->importGEOInternals();
      GModel::current()->refineMesh(CTX::instance()->mesh.secondOrderLinear);
    ;}
    break;

  case 270:
#line 3840 "Gmsh.y"
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

  case 271:
#line 3899 "Gmsh.y"
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
#line 3915 "Gmsh.y"
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
#line 3932 "Gmsh.y"
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
#line 3949 "Gmsh.y"
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
#line 3971 "Gmsh.y"
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
#line 3993 "Gmsh.y"
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
#line 4028 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip_until(NULL, "Return");
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 278:
#line 4036 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip_until(NULL, "Return");
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 279:
#line 4044 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    ;}
    break;

  case 280:
#line 4050 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 281:
#line 4057 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 282:
#line 4064 "Gmsh.y"
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
#line 4084 "Gmsh.y"
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
#line 4110 "Gmsh.y"
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
#line 4122 "Gmsh.y"
    {
      ImbricatedTest--;
      if(ImbricatedTest < 0)
        yymsg(1, "Orphan EndIf");
    ;}
    break;

  case 286:
#line 4134 "Gmsh.y"
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

  case 287:
#line 4164 "Gmsh.y"
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

  case 288:
#line 4195 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (13)].l),
		    (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].v)[0], (yyvsp[(7) - (13)].v)[1], (yyvsp[(7) - (13)].v)[2], (yyvsp[(9) - (13)].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[(12) - (13)].l));
    ;}
    break;

  case 289:
#line 4203 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 290:
#line 4209 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (7)].l),
		    (yyvsp[(2) - (7)].v)[0], (yyvsp[(2) - (7)].v)[1], (yyvsp[(2) - (7)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(4) - (7)].l));
    ;}
    break;

  case 291:
#line 4217 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 292:
#line 4223 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[(10) - (13)].l),
		    0., 0., 0., (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(10) - (13)].l));
    ;}
    break;

  case 293:
#line 4231 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 294:
#line 4237 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (15)].l),
		    (yyvsp[(3) - (15)].v)[0], (yyvsp[(3) - (15)].v)[1], (yyvsp[(3) - (15)].v)[2], (yyvsp[(5) - (15)].v)[0], (yyvsp[(5) - (15)].v)[1], (yyvsp[(5) - (15)].v)[2], (yyvsp[(7) - (15)].v)[0], (yyvsp[(7) - (15)].v)[1], (yyvsp[(7) - (15)].v)[2], (yyvsp[(9) - (15)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(12) - (15)].l));
    ;}
    break;

  case 295:
#line 4245 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 296:
#line 4251 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(BOUNDARY_LAYER, (yyvsp[(3) - (6)].l), 0., 0., 0., 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(3) - (6)].l));
    ;}
    break;

  case 297:
#line 4259 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 298:
#line 4266 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 299:
#line 4273 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 300:
#line 4280 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 301:
#line 4287 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 302:
#line 4294 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 303:
#line 4301 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 304:
#line 4308 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 305:
#line 4315 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 306:
#line 4322 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 307:
#line 4328 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 308:
#line 4335 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 309:
#line 4341 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 310:
#line 4348 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 311:
#line 4354 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 312:
#line 4361 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 313:
#line 4367 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 314:
#line 4374 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 315:
#line 4380 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 316:
#line 4387 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 317:
#line 4393 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 318:
#line 4400 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 319:
#line 4406 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 320:
#line 4413 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 321:
#line 4419 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 322:
#line 4426 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 323:
#line 4432 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 324:
#line 4443 "Gmsh.y"
    {
    ;}
    break;

  case 325:
#line 4446 "Gmsh.y"
    {
    ;}
    break;

  case 326:
#line 4452 "Gmsh.y"
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

  case 327:
#line 4464 "Gmsh.y"
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

  case 328:
#line 4484 "Gmsh.y"
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

  case 329:
#line 4508 "Gmsh.y"
    {
      extr.mesh.ScaleLast = true;
    ;}
    break;

  case 330:
#line 4512 "Gmsh.y"
    {
      extr.mesh.Recombine = true;
    ;}
    break;

  case 331:
#line 4516 "Gmsh.y"
    {
      extr.mesh.Recombine = (yyvsp[(2) - (3)].d) ? true : false;
    ;}
    break;

  case 332:
#line 4520 "Gmsh.y"
    {
      yymsg(0, "Keyword 'QuadTriSngl' deprecated. Use 'QuadTriNoNewVerts' instead.");
    ;}
    break;

  case 333:
#line 4524 "Gmsh.y"
    {
      yymsg(0, "Keyword 'QuadTriSngl' deprecated. Use 'QuadTriNoNewVerts' instead.");
    ;}
    break;

  case 334:
#line 4528 "Gmsh.y"
    {
      yymsg(0, "Method 'QuadTriDbl' deprecated. Use 'QuadTriAddVerts' instead, "
            "which has no requirement for the number of extrusion layers and meshes "
            "with body-centered vertices.");
    ;}
    break;

  case 335:
#line 4534 "Gmsh.y"
    {
      yymsg(0, "Method 'QuadTriDbl' deprecated. Use 'QuadTriAddVerts' instead, "
            "which has no requirement for the number of extrusion layers and meshes "
            "with body-centered vertices.");
    ;}
    break;

  case 336:
#line 4540 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1;
    ;}
    break;

  case 337:
#line 4544 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1_RECOMB;
    ;}
    break;

  case 338:
#line 4548 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1;
    ;}
    break;

  case 339:
#line 4552 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1_RECOMB;
    ;}
    break;

  case 340:
#line 4556 "Gmsh.y"
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

  case 341:
#line 4575 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (6)].c), "Index"))
        extr.mesh.BoundaryLayerIndex = (yyvsp[(4) - (6)].d);
      else if(!strcmp((yyvsp[(2) - (6)].c), "View"))
        extr.mesh.ViewIndex = (yyvsp[(4) - (6)].d);
      Free((yyvsp[(2) - (6)].c));
    ;}
    break;

  case 342:
#line 4587 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Union; ;}
    break;

  case 343:
#line 4588 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Intersection; ;}
    break;

  case 344:
#line 4589 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Difference; ;}
    break;

  case 345:
#line 4590 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Section; ;}
    break;

  case 346:
#line 4591 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Fragments; ;}
    break;

  case 347:
#line 4595 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 348:
#line 4596 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 349:
#line 4597 "Gmsh.y"
    { (yyval.i) = (yyvsp[(2) - (3)].d); ;}
    break;

  case 350:
#line 4602 "Gmsh.y"
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

  case 351:
#line 4635 "Gmsh.y"
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

  case 352:
#line 4662 "Gmsh.y"
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

  case 353:
#line 4684 "Gmsh.y"
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    ;}
    break;

  case 354:
#line 4688 "Gmsh.y"
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
#line 4703 "Gmsh.y"
    {
      (yyval.i) = -1; // left
    ;}
    break;

  case 356:
#line 4707 "Gmsh.y"
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
#line 4723 "Gmsh.y"
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   ;}
    break;

  case 358:
#line 4727 "Gmsh.y"
    {
     (yyval.l) = (yyvsp[(2) - (2)].l);
   ;}
    break;

  case 359:
#line 4732 "Gmsh.y"
    {
      (yyval.i) = 45;
    ;}
    break;

  case 360:
#line 4736 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(2) - (2)].d);
    ;}
    break;

  case 361:
#line 4742 "Gmsh.y"
    {
      (yyval.l) = List_Create(1, 1, sizeof(double));
    ;}
    break;

  case 362:
#line 4746 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
    ;}
    break;

  case 363:
#line 4753 "Gmsh.y"
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

  case 364:
#line 4809 "Gmsh.y"
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

  case 365:
#line 4879 "Gmsh.y"
    {
      yymsg(1, "Elliptic Surface is deprecated: use Transfinite instead (with smoothing)");
      List_Delete((yyvsp[(7) - (8)].l));
    ;}
    break;

  case 366:
#line 4884 "Gmsh.y"
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

  case 367:
#line 4951 "Gmsh.y"
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

  case 368:
#line 4987 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (8)].l)); i++){
	double d;
	List_Read((yyvsp[(4) - (8)].l), i, &d);
	CTX::instance()->mesh.algo2d_per_face[(int)d] = (int)(yyvsp[(7) - (8)].d);
      }
    ;}
    break;

  case 369:
#line 4995 "Gmsh.y"
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

  case 370:
#line 5038 "Gmsh.y"
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

  case 371:
#line 5077 "Gmsh.y"
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

  case 372:
#line 5098 "Gmsh.y"
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

  case 373:
#line 5130 "Gmsh.y"
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

  case 374:
#line 5157 "Gmsh.y"
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

  case 375:
#line 5183 "Gmsh.y"
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

  case 376:
#line 5209 "Gmsh.y"
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

  case 377:
#line 5235 "Gmsh.y"
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

  case 378:
#line 5261 "Gmsh.y"
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

  case 379:
#line 5282 "Gmsh.y"
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

  case 380:
#line 5310 "Gmsh.y"
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

  case 381:
#line 5338 "Gmsh.y"
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

  case 382:
#line 5366 "Gmsh.y"
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

  case 383:
#line 5394 "Gmsh.y"
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

  case 384:
#line 5422 "Gmsh.y"
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

  case 385:
#line 5461 "Gmsh.y"
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

  case 386:
#line 5500 "Gmsh.y"
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

  case 387:
#line 5521 "Gmsh.y"
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

  case 388:
#line 5542 "Gmsh.y"
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

  case 389:
#line 5569 "Gmsh.y"
    {
      ReplaceAllDuplicates();
    ;}
    break;

  case 390:
#line 5573 "Gmsh.y"
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

  case 391:
#line 5583 "Gmsh.y"
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

  case 392:
#line 5617 "Gmsh.y"
    { (yyval.c) = (char*)"Homology"; ;}
    break;

  case 393:
#line 5618 "Gmsh.y"
    { (yyval.c) = (char*)"Cohomology"; ;}
    break;

  case 394:
#line 5619 "Gmsh.y"
    { (yyval.c) = (char*)"Betti"; ;}
    break;

  case 395:
#line 5624 "Gmsh.y"
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest((yyvsp[(1) - (2)].c), domain, subdomain, dim);
    ;}
    break;

  case 396:
#line 5630 "Gmsh.y"
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

  case 397:
#line 5642 "Gmsh.y"
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

  case 398:
#line 5660 "Gmsh.y"
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

  case 399:
#line 5687 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d);           ;}
    break;

  case 400:
#line 5688 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (3)].d);           ;}
    break;

  case 401:
#line 5689 "Gmsh.y"
    { (yyval.d) = -(yyvsp[(2) - (2)].d);          ;}
    break;

  case 402:
#line 5690 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);           ;}
    break;

  case 403:
#line 5691 "Gmsh.y"
    { (yyval.d) = !(yyvsp[(2) - (2)].d);          ;}
    break;

  case 404:
#line 5692 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) - (yyvsp[(3) - (3)].d);      ;}
    break;

  case 405:
#line 5693 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) + (yyvsp[(3) - (3)].d);      ;}
    break;

  case 406:
#line 5694 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) * (yyvsp[(3) - (3)].d);      ;}
    break;

  case 407:
#line 5696 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (3)].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));
      else
	(yyval.d) = (yyvsp[(1) - (3)].d) / (yyvsp[(3) - (3)].d);
    ;}
    break;

  case 408:
#line 5702 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) % (int)(yyvsp[(3) - (3)].d);  ;}
    break;

  case 409:
#line 5703 "Gmsh.y"
    { (yyval.d) = pow((yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));  ;}
    break;

  case 410:
#line 5704 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d);      ;}
    break;

  case 411:
#line 5705 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) > (yyvsp[(3) - (3)].d);      ;}
    break;

  case 412:
#line 5706 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) <= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 413:
#line 5707 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) >= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 414:
#line 5708 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) == (yyvsp[(3) - (3)].d);     ;}
    break;

  case 415:
#line 5709 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) != (yyvsp[(3) - (3)].d);     ;}
    break;

  case 416:
#line 5710 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) && (yyvsp[(3) - (3)].d);     ;}
    break;

  case 417:
#line 5711 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) || (yyvsp[(3) - (3)].d);     ;}
    break;

  case 418:
#line 5712 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (5)].d) ? (yyvsp[(3) - (5)].d) : (yyvsp[(5) - (5)].d); ;}
    break;

  case 419:
#line 5713 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 420:
#line 5714 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 421:
#line 5715 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 422:
#line 5716 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 423:
#line 5717 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 424:
#line 5718 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 425:
#line 5719 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 426:
#line 5720 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 427:
#line 5721 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 428:
#line 5722 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 429:
#line 5723 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 430:
#line 5724 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 431:
#line 5725 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 432:
#line 5726 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 433:
#line 5727 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 434:
#line 5728 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 435:
#line 5729 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 436:
#line 5730 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d) + 0.5); ;}
    break;

  case 437:
#line 5731 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 438:
#line 5732 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 439:
#line 5733 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 440:
#line 5734 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 441:
#line 5743 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 442:
#line 5744 "Gmsh.y"
    { (yyval.d) = 3.141592653589793; ;}
    break;

  case 443:
#line 5745 "Gmsh.y"
    { (yyval.d) = (double)ImbricatedTest; ;}
    break;

  case 444:
#line 5746 "Gmsh.y"
    { (yyval.d) = Msg::GetCommRank(); ;}
    break;

  case 445:
#line 5747 "Gmsh.y"
    { (yyval.d) = Msg::GetCommSize(); ;}
    break;

  case 446:
#line 5748 "Gmsh.y"
    { (yyval.d) = GetGmshMajorVersion(); ;}
    break;

  case 447:
#line 5749 "Gmsh.y"
    { (yyval.d) = GetGmshMinorVersion(); ;}
    break;

  case 448:
#line 5750 "Gmsh.y"
    { (yyval.d) = GetGmshPatchVersion(); ;}
    break;

  case 449:
#line 5751 "Gmsh.y"
    { (yyval.d) = Cpu(); ;}
    break;

  case 450:
#line 5752 "Gmsh.y"
    { (yyval.d) = GetMemoryUsage()/1024./1024.; ;}
    break;

  case 451:
#line 5753 "Gmsh.y"
    { (yyval.d) = TotalRam(); ;}
    break;

  case 452:
#line 5758 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 453:
#line 5760 "Gmsh.y"
    {
      std::vector<double> val(1, (yyvsp[(3) - (6)].d));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.d) = val[0];
    ;}
    break;

  case 454:
#line 5766 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 455:
#line 5771 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 456:
#line 5776 "Gmsh.y"
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

  case 457:
#line 5793 "Gmsh.y"
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

  case 458:
#line 5811 "Gmsh.y"
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

  case 459:
#line 5829 "Gmsh.y"
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
#line 5847 "Gmsh.y"
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
#line 5865 "Gmsh.y"
    {
      (yyval.d) = gmsh_yysymbols.count((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 462:
#line 5870 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.d) = !StatFile(tmp);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 463:
#line 5876 "Gmsh.y"
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

  case 464:
#line 5891 "Gmsh.y"
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

  case 465:
#line 5910 "Gmsh.y"
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

  case 466:
#line 5930 "Gmsh.y"
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

  case 467:
#line 5950 "Gmsh.y"
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

  case 469:
#line 5993 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), (yyval.d));
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 470:
#line 5998 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), (yyval.d));
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 471:
#line 6003 "Gmsh.y"
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

  case 472:
#line 6013 "Gmsh.y"
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

  case 473:
#line 6023 "Gmsh.y"
    {
      (yyval.d) = Msg::GetValue((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 474:
#line 6028 "Gmsh.y"
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

  case 475:
#line 6039 "Gmsh.y"
    {
      std::string s((yyvsp[(3) - (6)].c)), substr((yyvsp[(5) - (6)].c));
      if(s.find(substr) != std::string::npos)
        (yyval.d) = 1.;
      else
        (yyval.d) = 0.;
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 476:
#line 6048 "Gmsh.y"
    {
      (yyval.d) = strlen((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 477:
#line 6053 "Gmsh.y"
    {
      (yyval.d) = strcmp((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 478:
#line 6058 "Gmsh.y"
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

  case 479:
#line 6085 "Gmsh.y"
    {
      memcpy((yyval.v), (yyvsp[(1) - (1)].v), 5*sizeof(double));
    ;}
    break;

  case 480:
#line 6089 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 481:
#line 6093 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 482:
#line 6097 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] - (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 483:
#line 6101 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] + (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 484:
#line 6108 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (11)].d);  (yyval.v)[1] = (yyvsp[(4) - (11)].d);  (yyval.v)[2] = (yyvsp[(6) - (11)].d);  (yyval.v)[3] = (yyvsp[(8) - (11)].d); (yyval.v)[4] = (yyvsp[(10) - (11)].d);
    ;}
    break;

  case 485:
#line 6112 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (9)].d);  (yyval.v)[1] = (yyvsp[(4) - (9)].d);  (yyval.v)[2] = (yyvsp[(6) - (9)].d);  (yyval.v)[3] = (yyvsp[(8) - (9)].d); (yyval.v)[4] = 1.0;
    ;}
    break;

  case 486:
#line 6116 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 487:
#line 6120 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 488:
#line 6127 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].l)));
    ;}
    break;

  case 489:
#line 6132 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].l)));
    ;}
    break;

  case 490:
#line 6139 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 491:
#line 6144 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 492:
#line 6148 "Gmsh.y"
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    ;}
    break;

  case 493:
#line 6153 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 494:
#line 6157 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 495:
#line 6165 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (5)].d);
      }
    ;}
    break;

  case 496:
#line 6176 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 497:
#line 6180 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(1) - (1)].c), "*") || !strcmp((yyvsp[(1) - (1)].c), "all"))
        (yyval.l) = 0;
      else{
        yyerror("Unknown special string for list replacement");
        (yyval.l) = List_Create(2, 1, sizeof(double));
      }
    ;}
    break;

  case 498:
#line 6192 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 499:
#line 6200 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (3)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (3)].d);
      }
    ;}
    break;

  case 500:
#line 6208 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      for(double d = (yyvsp[(1) - (3)].d); ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d <= (yyvsp[(3) - (3)].d)) : (d >= (yyvsp[(3) - (3)].d));
          ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d += 1.) : (d -= 1.))
	List_Add((yyval.l), &d);
    ;}
    break;

  case 501:
#line 6215 "Gmsh.y"
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

  case 502:
#line 6225 "Gmsh.y"
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

  case 503:
#line 6254 "Gmsh.y"
    {
      (yyval.l) = GetAllElementaryEntityNumbers(0);
    ;}
    break;

  case 504:
#line 6258 "Gmsh.y"
    {
      (yyval.l) = GetAllElementaryEntityNumbers(1);
    ;}
    break;

  case 505:
#line 6262 "Gmsh.y"
    {
      (yyval.l) = GetAllElementaryEntityNumbers(2);
    ;}
    break;

  case 506:
#line 6266 "Gmsh.y"
    {
      (yyval.l) = GetAllElementaryEntityNumbers(3);
    ;}
    break;

  case 507:
#line 6270 "Gmsh.y"
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(0);
    ;}
    break;

  case 508:
#line 6274 "Gmsh.y"
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(1);
    ;}
    break;

  case 509:
#line 6278 "Gmsh.y"
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(2);
    ;}
    break;

  case 510:
#line 6282 "Gmsh.y"
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(3);
    ;}
    break;

  case 511:
#line 6286 "Gmsh.y"
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

  case 512:
#line 6315 "Gmsh.y"
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

  case 513:
#line 6344 "Gmsh.y"
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

  case 514:
#line 6373 "Gmsh.y"
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

  case 515:
#line 6403 "Gmsh.y"
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

  case 516:
#line 6416 "Gmsh.y"
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

  case 517:
#line 6429 "Gmsh.y"
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

  case 518:
#line 6442 "Gmsh.y"
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

  case 519:
#line 6454 "Gmsh.y"
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

  case 520:
#line 6464 "Gmsh.y"
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

  case 521:
#line 6474 "Gmsh.y"
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
#line 6484 "Gmsh.y"
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

  case 523:
#line 6496 "Gmsh.y"
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

  case 524:
#line 6509 "Gmsh.y"
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

  case 525:
#line 6521 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 526:
#line 6525 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 527:
#line 6529 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (6)].l);
    ;}
    break;

  case 528:
#line 6533 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (6)].l);
    ;}
    break;

  case 529:
#line 6537 "Gmsh.y"
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

  case 530:
#line 6555 "Gmsh.y"
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

  case 531:
#line 6573 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = (yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1);
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 532:
#line 6581 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = pow(10,(yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1));
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 533:
#line 6589 "Gmsh.y"
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

  case 534:
#line 6618 "Gmsh.y"
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

  case 535:
#line 6631 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 536:
#line 6636 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 537:
#line 6640 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].d)));
    ;}
    break;

  case 538:
#line 6644 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (3)].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 539:
#line 6656 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (9)].d), (int)(yyvsp[(4) - (9)].d), (int)(yyvsp[(6) - (9)].d), (int)(yyvsp[(8) - (9)].d));
    ;}
    break;

  case 540:
#line 6660 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (7)].d), (int)(yyvsp[(4) - (7)].d), (int)(yyvsp[(6) - (7)].d), 255);
    ;}
    break;

  case 541:
#line 6672 "Gmsh.y"
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

  case 542:
#line 6689 "Gmsh.y"
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(5) - (5)].c), val);
      (yyval.u) = val;
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(5) - (5)].c));
    ;}
    break;

  case 543:
#line 6699 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 544:
#line 6703 "Gmsh.y"
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

  case 545:
#line 6718 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].u)));
    ;}
    break;

  case 546:
#line 6723 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].u)));
    ;}
    break;

  case 547:
#line 6730 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 548:
#line 6734 "Gmsh.y"
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

  case 549:
#line 6747 "Gmsh.y"
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

  case 550:
#line 6761 "Gmsh.y"
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

  case 551:
#line 6775 "Gmsh.y"
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
#line 6789 "Gmsh.y"
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
#line 6803 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 554:
#line 6811 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 555:
#line 6822 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 556:
#line 6826 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 557:
#line 6830 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    ;}
    break;

  case 558:
#line 6838 "Gmsh.y"
    {
      std::string exe = Msg::GetExecutableName();
      (yyval.c) = (char *)Malloc(exe.size() + 1);
      strcpy((yyval.c), exe.c_str());
    ;}
    break;

  case 559:
#line 6844 "Gmsh.y"
    {
      std::string action = Msg::GetOnelabAction();
      (yyval.c) = (char *)Malloc(action.size() + 1);
      strcpy((yyval.c), action.c_str());
    ;}
    break;

  case 560:
#line 6850 "Gmsh.y"
    {
      const char *env = GetEnvironmentVar((yyvsp[(3) - (4)].c));
      if(!env) env = "";
      (yyval.c) = (char *)Malloc((sizeof(env) + 1) * sizeof(char));
      strcpy((yyval.c), env);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 561:
#line 6858 "Gmsh.y"
    {
      std::string s = Msg::GetString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 562:
#line 6866 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (4)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 563:
#line 6873 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 564:
#line 6881 "Gmsh.y"
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

  case 565:
#line 6896 "Gmsh.y"
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

  case 566:
#line 6910 "Gmsh.y"
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

  case 567:
#line 6924 "Gmsh.y"
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

  case 568:
#line 6936 "Gmsh.y"
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

  case 569:
#line 6952 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = toupper((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 570:
#line 6961 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = tolower((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 571:
#line 6970 "Gmsh.y"
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

  case 572:
#line 6980 "Gmsh.y"
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

  case 573:
#line 6991 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (8)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (8)].d), (int)(yyvsp[(7) - (8)].d));
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (8)].c));
    ;}
    break;

  case 574:
#line 6999 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (6)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (6)].d), std::string::npos);
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 575:
#line 7007 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 576:
#line 7011 "Gmsh.y"
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

  case 577:
#line 7030 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 578:
#line 7037 "Gmsh.y"
    {
      std::string tmp = SplitFileName(GetAbsolutePath(gmsh_yyname))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
    ;}
    break;

  case 579:
#line 7043 "Gmsh.y"
    {
      std::string tmp = SplitFileName((yyvsp[(3) - (4)].c))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 580:
#line 7050 "Gmsh.y"
    {
      std::string tmp = GetAbsolutePath((yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 581:
#line 7057 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 582:
#line 7059 "Gmsh.y"
    {
      std::string val((yyvsp[(3) - (6)].c));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.c) = (char*)Malloc((val.size() + 1) * sizeof(char));
      strcpy((yyval.c), val.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 583:
#line 7070 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].c)));
    ;}
    break;

  case 584:
#line 7075 "Gmsh.y"
    { List_Add((yyval.l), &((yyvsp[(3) - (3)].c))); ;}
    break;

  case 585:
#line 7081 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 586:
#line 7090 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char)) ;
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)) ; strcat((yyval.c), tmpstr) ;
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 587:
#line 7103 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 588:
#line 7106 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 589:
#line 7110 "Gmsh.y"
    { (yyval.c) = (yyvsp[(3) - (4)].c); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 14203 "Gmsh.tab.cpp"
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


#line 7113 "Gmsh.y"


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

