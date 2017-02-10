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
     tShapeFromFile = 353,
     tRectangle = 354,
     tDisk = 355,
     tCharacteristic = 356,
     tLength = 357,
     tParametric = 358,
     tElliptic = 359,
     tRefineMesh = 360,
     tAdaptMesh = 361,
     tRelocateMesh = 362,
     tSetFactory = 363,
     tThruSections = 364,
     tPlane = 365,
     tRuled = 366,
     tTransfinite = 367,
     tComplex = 368,
     tPhysical = 369,
     tCompound = 370,
     tPeriodic = 371,
     tUsing = 372,
     tPlugin = 373,
     tDegenerated = 374,
     tRecursive = 375,
     tRotate = 376,
     tTranslate = 377,
     tSymmetry = 378,
     tDilate = 379,
     tExtrude = 380,
     tLevelset = 381,
     tAffine = 382,
     tBooleanUnion = 383,
     tBooleanIntersection = 384,
     tBooleanDifference = 385,
     tBooleanSection = 386,
     tBooleanFragments = 387,
     tRecombine = 388,
     tSmoother = 389,
     tSplit = 390,
     tDelete = 391,
     tCoherence = 392,
     tIntersect = 393,
     tMeshAlgorithm = 394,
     tReverse = 395,
     tLayers = 396,
     tScaleLast = 397,
     tHole = 398,
     tAlias = 399,
     tAliasWithOptions = 400,
     tCopyOptions = 401,
     tQuadTriAddVerts = 402,
     tQuadTriNoNewVerts = 403,
     tQuadTriSngl = 404,
     tQuadTriDbl = 405,
     tRecombLaterals = 406,
     tTransfQuadTri = 407,
     tText2D = 408,
     tText3D = 409,
     tInterpolationScheme = 410,
     tTime = 411,
     tCombine = 412,
     tBSpline = 413,
     tBezier = 414,
     tNurbs = 415,
     tNurbsOrder = 416,
     tNurbsKnots = 417,
     tColor = 418,
     tColorTable = 419,
     tFor = 420,
     tIn = 421,
     tEndFor = 422,
     tIf = 423,
     tElseIf = 424,
     tElse = 425,
     tEndIf = 426,
     tExit = 427,
     tAbort = 428,
     tField = 429,
     tReturn = 430,
     tCall = 431,
     tSlide = 432,
     tMacro = 433,
     tShow = 434,
     tHide = 435,
     tGetValue = 436,
     tGetStringValue = 437,
     tGetEnv = 438,
     tGetString = 439,
     tGetNumber = 440,
     tHomology = 441,
     tCohomology = 442,
     tBetti = 443,
     tExists = 444,
     tFileExists = 445,
     tGMSH_MAJOR_VERSION = 446,
     tGMSH_MINOR_VERSION = 447,
     tGMSH_PATCH_VERSION = 448,
     tGmshExecutableName = 449,
     tSetPartition = 450,
     tNameToString = 451,
     tStringToName = 452,
     tAFFECTDIVIDE = 453,
     tAFFECTTIMES = 454,
     tAFFECTMINUS = 455,
     tAFFECTPLUS = 456,
     tOR = 457,
     tAND = 458,
     tNOTEQUAL = 459,
     tEQUAL = 460,
     tGREATEROREQUAL = 461,
     tLESSOREQUAL = 462,
     UNARYPREC = 463,
     tMINUSMINUS = 464,
     tPLUSPLUS = 465
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
#define tShapeFromFile 353
#define tRectangle 354
#define tDisk 355
#define tCharacteristic 356
#define tLength 357
#define tParametric 358
#define tElliptic 359
#define tRefineMesh 360
#define tAdaptMesh 361
#define tRelocateMesh 362
#define tSetFactory 363
#define tThruSections 364
#define tPlane 365
#define tRuled 366
#define tTransfinite 367
#define tComplex 368
#define tPhysical 369
#define tCompound 370
#define tPeriodic 371
#define tUsing 372
#define tPlugin 373
#define tDegenerated 374
#define tRecursive 375
#define tRotate 376
#define tTranslate 377
#define tSymmetry 378
#define tDilate 379
#define tExtrude 380
#define tLevelset 381
#define tAffine 382
#define tBooleanUnion 383
#define tBooleanIntersection 384
#define tBooleanDifference 385
#define tBooleanSection 386
#define tBooleanFragments 387
#define tRecombine 388
#define tSmoother 389
#define tSplit 390
#define tDelete 391
#define tCoherence 392
#define tIntersect 393
#define tMeshAlgorithm 394
#define tReverse 395
#define tLayers 396
#define tScaleLast 397
#define tHole 398
#define tAlias 399
#define tAliasWithOptions 400
#define tCopyOptions 401
#define tQuadTriAddVerts 402
#define tQuadTriNoNewVerts 403
#define tQuadTriSngl 404
#define tQuadTriDbl 405
#define tRecombLaterals 406
#define tTransfQuadTri 407
#define tText2D 408
#define tText3D 409
#define tInterpolationScheme 410
#define tTime 411
#define tCombine 412
#define tBSpline 413
#define tBezier 414
#define tNurbs 415
#define tNurbsOrder 416
#define tNurbsKnots 417
#define tColor 418
#define tColorTable 419
#define tFor 420
#define tIn 421
#define tEndFor 422
#define tIf 423
#define tElseIf 424
#define tElse 425
#define tEndIf 426
#define tExit 427
#define tAbort 428
#define tField 429
#define tReturn 430
#define tCall 431
#define tSlide 432
#define tMacro 433
#define tShow 434
#define tHide 435
#define tGetValue 436
#define tGetStringValue 437
#define tGetEnv 438
#define tGetString 439
#define tGetNumber 440
#define tHomology 441
#define tCohomology 442
#define tBetti 443
#define tExists 444
#define tFileExists 445
#define tGMSH_MAJOR_VERSION 446
#define tGMSH_MINOR_VERSION 447
#define tGMSH_PATCH_VERSION 448
#define tGmshExecutableName 449
#define tSetPartition 450
#define tNameToString 451
#define tStringToName 452
#define tAFFECTDIVIDE 453
#define tAFFECTTIMES 454
#define tAFFECTMINUS 455
#define tAFFECTPLUS 456
#define tOR 457
#define tAND 458
#define tNOTEQUAL 459
#define tEQUAL 460
#define tGREATEROREQUAL 461
#define tLESSOREQUAL 462
#define UNARYPREC 463
#define tMINUSMINUS 464
#define tPLUSPLUS 465




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
#line 650 "Gmsh.tab.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 663 "Gmsh.tab.cpp"

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
#define YYLAST   13379

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  231
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  105
/* YYNRULES -- Number of rules.  */
#define YYNRULES  587
/* YYNRULES -- Number of states.  */
#define YYNSTATES  2166

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   465

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   216,     2,   226,     2,   215,     2,     2,
     221,   222,   213,   211,   227,   212,   225,   214,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     207,     2,   208,   202,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   223,     2,   224,   220,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   228,     2,   229,   230,     2,     2,     2,
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
     195,   196,   197,   198,   199,   200,   201,   203,   204,   205,
     206,   209,   210,   217,   218,   219
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
    1026,  1037,  1045,  1053,  1061,  1069,  1077,  1085,  1094,  1099,
    1108,  1121,  1130,  1139,  1147,  1155,  1160,  1169,  1178,  1184,
    1196,  1202,  1212,  1222,  1227,  1237,  1247,  1249,  1251,  1252,
    1255,  1262,  1269,  1276,  1283,  1292,  1303,  1318,  1335,  1348,
    1363,  1378,  1393,  1408,  1417,  1426,  1433,  1438,  1445,  1452,
    1456,  1461,  1467,  1474,  1480,  1484,  1488,  1493,  1499,  1504,
    1510,  1514,  1520,  1528,  1536,  1540,  1548,  1552,  1555,  1558,
    1561,  1564,  1567,  1583,  1586,  1589,  1592,  1595,  1598,  1615,
    1627,  1634,  1643,  1652,  1663,  1665,  1668,  1671,  1673,  1677,
    1681,  1686,  1691,  1693,  1695,  1701,  1713,  1727,  1728,  1736,
    1737,  1751,  1752,  1768,  1769,  1776,  1785,  1794,  1803,  1816,
    1829,  1842,  1857,  1872,  1887,  1888,  1901,  1902,  1915,  1916,
    1929,  1930,  1947,  1948,  1965,  1966,  1983,  1984,  2003,  2004,
    2023,  2024,  2043,  2045,  2048,  2054,  2062,  2072,  2075,  2078,
    2082,  2085,  2089,  2092,  2096,  2099,  2103,  2106,  2110,  2120,
    2127,  2129,  2131,  2133,  2135,  2137,  2138,  2141,  2145,  2155,
    2160,  2175,  2176,  2180,  2181,  2183,  2184,  2187,  2188,  2191,
    2192,  2195,  2203,  2210,  2219,  2225,  2229,  2238,  2244,  2249,
    2256,  2268,  2280,  2299,  2318,  2331,  2344,  2357,  2368,  2379,
    2390,  2401,  2412,  2417,  2422,  2427,  2432,  2437,  2440,  2444,
    2451,  2453,  2455,  2457,  2460,  2466,  2474,  2485,  2487,  2491,
    2494,  2497,  2500,  2504,  2508,  2512,  2516,  2520,  2524,  2528,
    2532,  2536,  2540,  2544,  2548,  2552,  2556,  2562,  2567,  2572,
    2577,  2582,  2587,  2592,  2597,  2602,  2607,  2612,  2619,  2624,
    2629,  2634,  2639,  2644,  2649,  2654,  2661,  2668,  2675,  2680,
    2682,  2684,  2686,  2688,  2690,  2692,  2694,  2696,  2698,  2700,
    2702,  2703,  2710,  2715,  2722,  2724,  2729,  2734,  2739,  2744,
    2749,  2754,  2759,  2762,  2768,  2774,  2780,  2786,  2790,  2797,
    2802,  2810,  2817,  2824,  2831,  2836,  2843,  2848,  2850,  2853,
    2856,  2860,  2864,  2876,  2886,  2894,  2902,  2904,  2908,  2910,
    2912,  2915,  2919,  2924,  2930,  2932,  2934,  2937,  2941,  2945,
    2951,  2956,  2959,  2962,  2965,  2968,  2972,  2976,  2980,  2984,
    2990,  2996,  3002,  3008,  3025,  3042,  3059,  3076,  3078,  3080,
    3082,  3086,  3090,  3095,  3100,  3105,  3112,  3119,  3126,  3133,
    3142,  3151,  3156,  3171,  3173,  3175,  3179,  3183,  3193,  3201,
    3203,  3209,  3213,  3220,  3222,  3226,  3228,  3230,  3235,  3240,
    3245,  3250,  3254,  3261,  3263,  3268,  3270,  3272,  3274,  3279,
    3286,  3291,  3298,  3303,  3308,  3313,  3322,  3327,  3332,  3337,
    3342,  3351,  3360,  3367,  3372,  3379,  3384,  3386,  3391,  3396,
    3397,  3404,  3406,  3410,  3416,  3422,  3424,  3426
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     232,     0,    -1,   233,    -1,     1,     6,    -1,    -1,   233,
     234,    -1,   237,    -1,   236,    -1,   257,    -1,   276,    -1,
     277,    -1,   281,    -1,   282,    -1,   283,    -1,   284,    -1,
     288,    -1,   306,    -1,   307,    -1,   313,    -1,   314,    -1,
     287,    -1,   286,    -1,   285,    -1,   280,    -1,   316,    -1,
     208,    -1,   208,   208,    -1,    42,   221,   330,   222,     6,
      -1,    43,   221,   330,   222,     6,    -1,    42,   221,   330,
     222,   235,   330,     6,    -1,    42,   221,   330,   227,   326,
     222,     6,    -1,    43,   221,   330,   227,   326,   222,     6,
      -1,    42,   221,   330,   227,   326,   222,   235,   330,     6,
      -1,     4,   330,   228,   238,   229,     6,    -1,   144,     4,
     223,   317,   224,     6,    -1,   145,     4,   223,   317,   224,
       6,    -1,   146,     4,   223,   317,   227,   317,   224,     6,
      -1,    -1,   238,   241,    -1,   238,   245,    -1,   238,   248,
      -1,   238,   250,    -1,   238,   251,    -1,   317,    -1,   239,
     227,   317,    -1,   317,    -1,   240,   227,   317,    -1,    -1,
      -1,     4,   242,   221,   239,   222,   243,   228,   240,   229,
       6,    -1,   330,    -1,   244,   227,   330,    -1,    -1,   153,
     221,   317,   227,   317,   227,   317,   222,   246,   228,   244,
     229,     6,    -1,   330,    -1,   247,   227,   330,    -1,    -1,
     154,   221,   317,   227,   317,   227,   317,   227,   317,   222,
     249,   228,   247,   229,     6,    -1,   155,   228,   322,   229,
     228,   322,   229,     6,    -1,   155,   228,   322,   229,   228,
     322,   229,   228,   322,   229,   228,   322,   229,     6,    -1,
      -1,   156,   252,   228,   240,   229,     6,    -1,     7,    -1,
     201,    -1,   200,    -1,   199,    -1,   198,    -1,   219,    -1,
     218,    -1,   221,    -1,   223,    -1,   222,    -1,   224,    -1,
      78,   223,   259,   224,     6,    -1,    79,   223,   264,   224,
       6,    -1,    82,   255,   331,   227,   317,   256,     6,    -1,
      83,   255,   335,   227,   331,   256,     6,    -1,   335,   253,
     323,     6,    -1,   335,   254,     6,    -1,     4,   223,   224,
     253,   323,     6,    -1,   334,   223,   224,   253,   323,     6,
      -1,     4,   223,   317,   224,   253,   317,     6,    -1,   334,
     223,   317,   224,   253,   317,     6,    -1,     4,   223,   317,
     224,   254,     6,    -1,   334,   223,   317,   224,   254,     6,
      -1,     4,   255,   228,   326,   229,   256,   253,   323,     6,
      -1,   334,   255,   228,   326,   229,   256,   253,   323,     6,
      -1,     4,   221,   222,   253,   323,     6,    -1,   334,   221,
     222,   253,   323,     6,    -1,     4,   221,   317,   222,   253,
     317,     6,    -1,   334,   221,   317,   222,   253,   317,     6,
      -1,     4,   221,   317,   222,   254,     6,    -1,   334,   221,
     317,   222,   254,     6,    -1,   335,     7,   331,     6,    -1,
       4,   223,   224,     7,    44,   255,   256,     6,    -1,   334,
     223,   224,     7,    44,   255,   256,     6,    -1,     4,   223,
     224,     7,    44,   255,   333,   256,     6,    -1,   334,   223,
     224,     7,    44,   255,   333,   256,     6,    -1,     4,   223,
     224,   201,    44,   255,   333,   256,     6,    -1,   334,   223,
     224,   201,    44,   255,   333,   256,     6,    -1,     4,   221,
     222,     7,    44,   255,   256,     6,    -1,   334,   221,   222,
       7,    44,   255,   256,     6,    -1,     4,   221,   222,     7,
      44,   255,   333,   256,     6,    -1,   334,   221,   222,     7,
      44,   255,   333,   256,     6,    -1,     4,   221,   222,   201,
      44,   255,   333,   256,     6,    -1,   334,   221,   222,   201,
      44,   255,   333,   256,     6,    -1,     4,   225,     4,     7,
     331,     6,    -1,     4,   223,   317,   224,   225,     4,     7,
     331,     6,    -1,     4,   225,     4,   253,   317,     6,    -1,
       4,   223,   317,   224,   225,     4,   253,   317,     6,    -1,
       4,   225,     4,   254,     6,    -1,     4,   223,   317,   224,
     225,     4,   254,     6,    -1,     4,   225,   163,   225,     4,
       7,   327,     6,    -1,     4,   223,   317,   224,   225,   163,
     225,     4,     7,   327,     6,    -1,     4,   225,   164,     7,
     328,     6,    -1,     4,   223,   317,   224,   225,   164,     7,
     328,     6,    -1,     4,   174,     7,   317,     6,    -1,   174,
     223,   317,   224,     7,     4,     6,    -1,   174,   223,   317,
     224,   225,     4,     7,   317,     6,    -1,   174,   223,   317,
     224,   225,     4,     7,   331,     6,    -1,   174,   223,   317,
     224,   225,     4,     7,   228,   326,   229,     6,    -1,   174,
     223,   317,   224,   225,     4,     6,    -1,   118,   221,     4,
     222,   225,     4,     7,   317,     6,    -1,   118,   221,     4,
     222,   225,     4,     7,   331,     6,    -1,    -1,   227,    -1,
      -1,   259,   258,   335,    -1,   259,   258,   335,     7,   317,
      -1,    -1,   259,   258,   335,     7,   228,   323,   260,   266,
     229,    -1,    -1,   259,   258,   335,   223,   224,     7,   228,
     323,   261,   266,   229,    -1,    -1,   259,   258,   335,   221,
     222,     7,   228,   323,   262,   266,   229,    -1,   259,   258,
     335,     7,   331,    -1,    -1,   259,   258,   335,     7,   228,
     331,   263,   268,   229,    -1,    -1,   264,   258,   330,    -1,
     317,     7,   331,    -1,   265,   227,   317,     7,   331,    -1,
     325,     7,   335,   221,   222,    -1,    -1,   266,   267,    -1,
     227,     4,   323,    -1,   227,     4,   228,   265,   229,    -1,
     227,     4,   331,    -1,    -1,   268,   269,    -1,   227,     4,
     317,    -1,   227,     4,   331,    -1,   227,   178,   331,    -1,
     227,     4,   228,   333,   229,    -1,   317,    -1,   331,    -1,
     331,   227,   317,    -1,   317,    -1,   331,    -1,   331,   227,
     317,    -1,   317,    -1,   331,    -1,   331,   227,   317,    -1,
     317,    -1,   331,    -1,   331,   227,   317,    -1,    -1,   166,
      88,   228,   317,   229,    -1,    -1,   110,   320,    -1,   108,
     221,   330,   222,     6,    -1,    84,   221,   317,   222,     7,
     320,     6,    -1,   114,    84,   221,   270,   222,   253,   323,
       6,    -1,   101,   102,   323,     7,   317,     6,    -1,    87,
     221,   317,   222,     7,   323,     6,    -1,   119,    87,   323,
       6,    -1,    91,   221,   317,   222,     7,   323,     6,    -1,
      85,   221,   317,   222,     7,   323,   275,     6,    -1,    86,
     221,   317,   222,     7,   323,   275,     6,    -1,   158,   221,
     317,   222,     7,   323,     6,    -1,   159,   221,   317,   222,
       7,   323,     6,    -1,   160,   221,   317,   222,     7,   323,
     162,   323,   161,   317,     6,    -1,    87,     4,   221,   317,
     222,     7,   323,     6,    -1,   115,    87,   323,     6,    -1,
     115,    87,   221,   317,   222,     7,   323,     6,    -1,   114,
      87,   221,   271,   222,   253,   323,     6,    -1,   110,    90,
     221,   317,   222,     7,   323,     6,    -1,   111,    90,   221,
     317,   222,     7,   323,   274,     6,    -1,    12,    13,     6,
      -1,    13,    90,   317,     6,    -1,   103,    90,   221,   317,
     222,     7,     5,     5,     5,     6,    -1,    88,   221,   317,
     222,     7,   323,     6,    -1,    89,   221,   317,   222,     7,
     323,     6,    -1,    93,   221,   317,   222,     7,   323,     6,
      -1,    99,   221,   317,   222,     7,   323,     6,    -1,   100,
     221,   317,   222,     7,   323,     6,    -1,    94,   221,   317,
     222,     7,   323,     6,    -1,    90,     4,   221,   317,   222,
       7,   323,     6,    -1,   115,    90,   323,     6,    -1,   115,
      90,   221,   317,   222,     7,   323,     6,    -1,   115,    90,
     221,   317,   222,     7,   323,     4,   228,   322,   229,     6,
      -1,   114,    90,   221,   272,   222,   253,   323,     6,    -1,
     113,    92,   221,   317,   222,     7,   323,     6,    -1,    92,
     221,   317,   222,     7,   323,     6,    -1,   109,   221,   317,
     222,     7,   323,     6,    -1,   115,    92,   323,     6,    -1,
     115,    92,   221,   317,   222,     7,   323,     6,    -1,   114,
      92,   221,   273,   222,   253,   323,     6,    -1,   122,   320,
     228,   278,   229,    -1,   121,   228,   320,   227,   320,   227,
     317,   229,   228,   278,   229,    -1,   123,   320,   228,   278,
     229,    -1,   124,   228,   320,   227,   317,   229,   228,   278,
     229,    -1,   124,   228,   320,   227,   320,   229,   228,   278,
     229,    -1,     4,   228,   278,   229,    -1,   138,    87,   228,
     326,   229,    90,   228,   317,   229,    -1,   135,    87,   221,
     317,   222,   228,   326,   229,     6,    -1,   279,    -1,   277,
      -1,    -1,   279,   276,    -1,   279,    84,   228,   326,   229,
       6,    -1,   279,    87,   228,   326,   229,     6,    -1,   279,
      90,   228,   326,   229,     6,    -1,   279,    92,   228,   326,
     229,     6,    -1,   126,   110,   221,   317,   222,     7,   323,
       6,    -1,   126,    84,   221,   317,   222,     7,   228,   322,
     229,     6,    -1,   126,   110,   221,   317,   222,     7,   228,
     320,   227,   320,   227,   326,   229,     6,    -1,   126,   110,
     221,   317,   222,     7,   228,   320,   227,   320,   227,   320,
     227,   326,   229,     6,    -1,   126,    88,   221,   317,   222,
       7,   228,   320,   227,   326,   229,     6,    -1,   126,    94,
     221,   317,   222,     7,   228,   320,   227,   320,   227,   326,
     229,     6,    -1,   126,    95,   221,   317,   222,     7,   228,
     320,   227,   320,   227,   326,   229,     6,    -1,   126,    96,
     221,   317,   222,     7,   228,   320,   227,   320,   227,   326,
     229,     6,    -1,   126,    97,   221,   317,   222,     7,   228,
     320,   227,   320,   227,   326,   229,     6,    -1,   126,     4,
     221,   317,   222,     7,   323,     6,    -1,   126,     4,   221,
     317,   222,     7,     5,     6,    -1,   126,     4,   228,   317,
     229,     6,    -1,   136,   228,   279,   229,    -1,   136,   174,
     223,   317,   224,     6,    -1,   136,     4,   223,   317,   224,
       6,    -1,   136,   335,     6,    -1,   136,     4,     4,     6,
      -1,   163,   327,   228,   279,   229,    -1,   120,   163,   327,
     228,   279,   229,    -1,   195,   317,   228,   279,   229,    -1,
     179,     5,     6,    -1,   180,     5,     6,    -1,   179,   228,
     279,   229,    -1,   120,   179,   228,   279,   229,    -1,   180,
     228,   279,   229,    -1,   120,   180,   228,   279,   229,    -1,
       4,   331,     6,    -1,    71,   221,   333,   222,     6,    -1,
       4,     4,   223,   317,   224,   330,     6,    -1,     4,     4,
       4,   223,   317,   224,     6,    -1,     4,   317,     6,    -1,
     118,   221,     4,   222,   225,     4,     6,    -1,   157,     4,
       6,    -1,   172,     6,    -1,   173,     6,    -1,    68,     6,
      -1,    69,     6,    -1,    62,     6,    -1,    62,   228,   317,
     227,   317,   227,   317,   227,   317,   227,   317,   227,   317,
     229,     6,    -1,    63,     6,    -1,    64,     6,    -1,    75,
       6,    -1,    76,     6,    -1,   105,     6,    -1,   106,   228,
     326,   229,   228,   326,   229,   228,   322,   229,   228,   317,
     227,   317,   229,     6,    -1,   177,   221,   228,   326,   229,
     227,   331,   227,   331,   222,     6,    -1,   165,   221,   317,
       8,   317,   222,    -1,   165,   221,   317,     8,   317,     8,
     317,   222,    -1,   165,     4,   166,   228,   317,     8,   317,
     229,    -1,   165,     4,   166,   228,   317,     8,   317,     8,
     317,   229,    -1,   167,    -1,   178,     4,    -1,   178,   331,
      -1,   175,    -1,   176,   335,     6,    -1,   176,   331,     6,
      -1,   168,   221,   317,   222,    -1,   169,   221,   317,   222,
      -1,   170,    -1,   171,    -1,   125,   320,   228,   279,   229,
      -1,   125,   228,   320,   227,   320,   227,   317,   229,   228,
     279,   229,    -1,   125,   228,   320,   227,   320,   227,   320,
     227,   317,   229,   228,   279,   229,    -1,    -1,   125,   320,
     228,   279,   289,   302,   229,    -1,    -1,   125,   228,   320,
     227,   320,   227,   317,   229,   228,   279,   290,   302,   229,
      -1,    -1,   125,   228,   320,   227,   320,   227,   320,   227,
     317,   229,   228,   279,   291,   302,   229,    -1,    -1,   125,
     228,   279,   292,   302,   229,    -1,   125,    84,   228,   317,
     227,   320,   229,     6,    -1,   125,    87,   228,   317,   227,
     320,   229,     6,    -1,   125,    90,   228,   317,   227,   320,
     229,     6,    -1,   125,    84,   228,   317,   227,   320,   227,
     320,   227,   317,   229,     6,    -1,   125,    87,   228,   317,
     227,   320,   227,   320,   227,   317,   229,     6,    -1,   125,
      90,   228,   317,   227,   320,   227,   320,   227,   317,   229,
       6,    -1,   125,    84,   228,   317,   227,   320,   227,   320,
     227,   320,   227,   317,   229,     6,    -1,   125,    87,   228,
     317,   227,   320,   227,   320,   227,   320,   227,   317,   229,
       6,    -1,   125,    90,   228,   317,   227,   320,   227,   320,
     227,   320,   227,   317,   229,     6,    -1,    -1,   125,    84,
     228,   317,   227,   320,   229,   293,   228,   302,   229,     6,
      -1,    -1,   125,    87,   228,   317,   227,   320,   229,   294,
     228,   302,   229,     6,    -1,    -1,   125,    90,   228,   317,
     227,   320,   229,   295,   228,   302,   229,     6,    -1,    -1,
     125,    84,   228,   317,   227,   320,   227,   320,   227,   317,
     229,   296,   228,   302,   229,     6,    -1,    -1,   125,    87,
     228,   317,   227,   320,   227,   320,   227,   317,   229,   297,
     228,   302,   229,     6,    -1,    -1,   125,    90,   228,   317,
     227,   320,   227,   320,   227,   317,   229,   298,   228,   302,
     229,     6,    -1,    -1,   125,    84,   228,   317,   227,   320,
     227,   320,   227,   320,   227,   317,   229,   299,   228,   302,
     229,     6,    -1,    -1,   125,    87,   228,   317,   227,   320,
     227,   320,   227,   320,   227,   317,   229,   300,   228,   302,
     229,     6,    -1,    -1,   125,    90,   228,   317,   227,   320,
     227,   320,   227,   320,   227,   317,   229,   301,   228,   302,
     229,     6,    -1,   303,    -1,   302,   303,    -1,   141,   228,
     317,   229,     6,    -1,   141,   228,   323,   227,   323,   229,
       6,    -1,   141,   228,   323,   227,   323,   227,   323,   229,
       6,    -1,   142,     6,    -1,   133,     6,    -1,   133,   317,
       6,    -1,   149,     6,    -1,   149,   151,     6,    -1,   150,
       6,    -1,   150,   151,     6,    -1,   147,     6,    -1,   147,
     151,     6,    -1,   148,     6,    -1,   148,   151,     6,    -1,
     143,   221,   317,   222,     7,   323,   117,   317,     6,    -1,
     117,     4,   223,   317,   224,     6,    -1,   128,    -1,   129,
      -1,   130,    -1,   131,    -1,   132,    -1,    -1,   136,     6,
      -1,   136,   317,     6,    -1,   304,   228,   279,   305,   229,
     228,   279,   305,   229,    -1,    98,   221,   330,   222,    -1,
     304,   221,   317,   222,     7,   228,   279,   305,   229,   228,
     279,   305,   229,     6,    -1,    -1,   117,     4,   317,    -1,
      -1,     4,    -1,    -1,     7,   323,    -1,    -1,     7,   317,
      -1,    -1,   127,   323,    -1,   112,    87,   324,     7,   317,
     308,     6,    -1,   112,    90,   324,   310,   309,     6,    -1,
     104,    90,   228,   317,   229,     7,   323,     6,    -1,   112,
      92,   324,   310,     6,    -1,   152,   324,     6,    -1,   139,
      90,   228,   326,   229,     7,   317,     6,    -1,   133,    90,
     324,   311,     6,    -1,   133,    92,   324,     6,    -1,   134,
      90,   323,     7,   317,     6,    -1,   116,    87,   228,   326,
     229,     7,   228,   326,   229,   312,     6,    -1,   116,    90,
     228,   326,   229,     7,   228,   326,   229,   312,     6,    -1,
     116,    87,   228,   326,   229,     7,   228,   326,   229,   121,
     228,   320,   227,   320,   227,   317,   229,     6,    -1,   116,
      90,   228,   326,   229,     7,   228,   326,   229,   121,   228,
     320,   227,   320,   227,   317,   229,     6,    -1,   116,    87,
     228,   326,   229,     7,   228,   326,   229,   122,   320,     6,
      -1,   116,    90,   228,   326,   229,     7,   228,   326,   229,
     122,   320,     6,    -1,   116,    90,   317,   228,   326,   229,
       7,   317,   228,   326,   229,     6,    -1,    84,   228,   326,
     229,   166,    90,   228,   317,   229,     6,    -1,    87,   228,
     326,   229,   166,    90,   228,   317,   229,     6,    -1,    84,
     228,   326,   229,   166,    92,   228,   317,   229,     6,    -1,
      87,   228,   326,   229,   166,    92,   228,   317,   229,     6,
      -1,    90,   228,   326,   229,   166,    92,   228,   317,   229,
       6,    -1,   140,    90,   324,     6,    -1,   140,    87,   324,
       6,    -1,   107,    84,   324,     6,    -1,   107,    87,   324,
       6,    -1,   107,    90,   324,     6,    -1,   137,     6,    -1,
     137,     4,     6,    -1,   137,    84,   228,   326,   229,     6,
      -1,   186,    -1,   187,    -1,   188,    -1,   315,     6,    -1,
     315,   228,   323,   229,     6,    -1,   315,   228,   323,   227,
     323,   229,     6,    -1,   315,   221,   323,   222,   228,   323,
     227,   323,   229,     6,    -1,   318,    -1,   221,   317,   222,
      -1,   212,   317,    -1,   211,   317,    -1,   216,   317,    -1,
     317,   212,   317,    -1,   317,   211,   317,    -1,   317,   213,
     317,    -1,   317,   214,   317,    -1,   317,   215,   317,    -1,
     317,   220,   317,    -1,   317,   207,   317,    -1,   317,   208,
     317,    -1,   317,   210,   317,    -1,   317,   209,   317,    -1,
     317,   206,   317,    -1,   317,   205,   317,    -1,   317,   204,
     317,    -1,   317,   203,   317,    -1,   317,   202,   317,     8,
     317,    -1,    15,   255,   317,   256,    -1,    16,   255,   317,
     256,    -1,    17,   255,   317,   256,    -1,    18,   255,   317,
     256,    -1,    19,   255,   317,   256,    -1,    20,   255,   317,
     256,    -1,    21,   255,   317,   256,    -1,    22,   255,   317,
     256,    -1,    23,   255,   317,   256,    -1,    25,   255,   317,
     256,    -1,    26,   255,   317,   227,   317,   256,    -1,    27,
     255,   317,   256,    -1,    28,   255,   317,   256,    -1,    29,
     255,   317,   256,    -1,    30,   255,   317,   256,    -1,    31,
     255,   317,   256,    -1,    32,   255,   317,   256,    -1,    33,
     255,   317,   256,    -1,    34,   255,   317,   227,   317,   256,
      -1,    35,   255,   317,   227,   317,   256,    -1,    36,   255,
     317,   227,   317,   256,    -1,    24,   255,   317,   256,    -1,
       3,    -1,     9,    -1,    14,    -1,    10,    -1,    11,    -1,
     191,    -1,   192,    -1,   193,    -1,    72,    -1,    73,    -1,
      74,    -1,    -1,    80,   255,   317,   319,   266,   256,    -1,
     185,   255,   330,   256,    -1,   185,   255,   330,   227,   317,
     256,    -1,   335,    -1,     4,   223,   317,   224,    -1,     4,
     221,   317,   222,    -1,   334,   223,   317,   224,    -1,   334,
     221,   317,   222,    -1,   189,   221,   335,   222,    -1,   190,
     221,   331,   222,    -1,   226,   335,   255,   256,    -1,   335,
     254,    -1,     4,   223,   317,   224,   254,    -1,     4,   221,
     317,   222,   254,    -1,   334,   223,   317,   224,   254,    -1,
     334,   221,   317,   222,   254,    -1,     4,   225,     4,    -1,
       4,   223,   317,   224,   225,     4,    -1,     4,   225,     4,
     254,    -1,     4,   223,   317,   224,   225,     4,   254,    -1,
     181,   221,   330,   227,   317,   222,    -1,    54,   221,   323,
     227,   323,   222,    -1,    55,   255,   330,   227,   330,   256,
      -1,    53,   255,   330,   256,    -1,    56,   255,   330,   227,
     330,   256,    -1,    61,   221,   333,   222,    -1,   321,    -1,
     212,   320,    -1,   211,   320,    -1,   320,   212,   320,    -1,
     320,   211,   320,    -1,   228,   317,   227,   317,   227,   317,
     227,   317,   227,   317,   229,    -1,   228,   317,   227,   317,
     227,   317,   227,   317,   229,    -1,   228,   317,   227,   317,
     227,   317,   229,    -1,   221,   317,   227,   317,   227,   317,
     222,    -1,   323,    -1,   322,   227,   323,    -1,   317,    -1,
     325,    -1,   228,   229,    -1,   228,   326,   229,    -1,   212,
     228,   326,   229,    -1,   317,   213,   228,   326,   229,    -1,
     323,    -1,     5,    -1,   212,   325,    -1,   317,   213,   325,
      -1,   317,     8,   317,    -1,   317,     8,   317,     8,   317,
      -1,    84,   228,   317,   229,    -1,    84,     5,    -1,    87,
       5,    -1,    90,     5,    -1,    92,     5,    -1,   114,    84,
       5,    -1,   114,    87,     5,    -1,   114,    90,     5,    -1,
     114,    92,     5,    -1,   114,    84,   228,   326,   229,    -1,
     114,    87,   228,   326,   229,    -1,   114,    90,   228,   326,
     229,    -1,   114,    92,   228,   326,   229,    -1,    84,   166,
      62,   228,   317,   227,   317,   227,   317,   227,   317,   227,
     317,   227,   317,   229,    -1,    87,   166,    62,   228,   317,
     227,   317,   227,   317,   227,   317,   227,   317,   227,   317,
     229,    -1,    90,   166,    62,   228,   317,   227,   317,   227,
     317,   227,   317,   227,   317,   227,   317,   229,    -1,    92,
     166,    62,   228,   317,   227,   317,   227,   317,   227,   317,
     227,   317,   227,   317,   229,    -1,   277,    -1,   288,    -1,
     306,    -1,     4,   255,   256,    -1,   334,   255,   256,    -1,
      37,   223,   335,   224,    -1,    37,   223,   325,   224,    -1,
      37,   221,   325,   222,    -1,    37,   223,   228,   326,   229,
     224,    -1,    37,   221,   228,   326,   229,   222,    -1,     4,
     255,   228,   326,   229,   256,    -1,   334,   255,   228,   326,
     229,   256,    -1,    38,   255,   317,   227,   317,   227,   317,
     256,    -1,    39,   255,   317,   227,   317,   227,   317,   256,
      -1,    40,   255,   330,   256,    -1,    41,   255,   317,   227,
     317,   227,   317,   227,   317,   227,   317,   227,   317,   256,
      -1,   317,    -1,   325,    -1,   326,   227,   317,    -1,   326,
     227,   325,    -1,   228,   317,   227,   317,   227,   317,   227,
     317,   229,    -1,   228,   317,   227,   317,   227,   317,   229,
      -1,   335,    -1,     4,   225,   163,   225,     4,    -1,   228,
     329,   229,    -1,     4,   223,   317,   224,   225,   164,    -1,
     327,    -1,   329,   227,   327,    -1,   331,    -1,   335,    -1,
       4,   223,   317,   224,    -1,   334,   223,   317,   224,    -1,
       4,   221,   317,   222,    -1,   334,   221,   317,   222,    -1,
       4,   225,     4,    -1,     4,   223,   317,   224,   225,     4,
      -1,     5,    -1,   196,   223,   335,   224,    -1,    65,    -1,
     194,    -1,    70,    -1,   183,   221,   330,   222,    -1,   182,
     221,   330,   227,   330,   222,    -1,   184,   255,   330,   256,
      -1,   184,   255,   330,   227,   330,   256,    -1,    46,   255,
     333,   256,    -1,    47,   221,   330,   222,    -1,    48,   221,
     330,   222,    -1,    49,   221,   330,   227,   330,   227,   330,
     222,    -1,    44,   255,   333,   256,    -1,    58,   255,   330,
     256,    -1,    59,   255,   330,   256,    -1,    60,   255,   330,
     256,    -1,    57,   255,   317,   227,   330,   227,   330,   256,
      -1,    52,   255,   330,   227,   317,   227,   317,   256,    -1,
      52,   255,   330,   227,   317,   256,    -1,    45,   255,   330,
     256,    -1,    45,   255,   330,   227,   326,   256,    -1,    66,
     255,   330,   256,    -1,    67,    -1,    51,   255,   330,   256,
      -1,    50,   255,   330,   256,    -1,    -1,    81,   255,   331,
     332,   268,   256,    -1,   330,    -1,   333,   227,   330,    -1,
       4,   230,   228,   317,   229,    -1,   334,   230,   228,   317,
     229,    -1,     4,    -1,   334,    -1,   197,   223,   330,   224,
      -1
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
    1987,  2014,  2041,  2070,  2075,  2093,  2139,  2167,  2216,  2222,
    2228,  2235,  2276,  2302,  2326,  2351,  2374,  2399,  2426,  2430,
    2449,  2483,  2530,  2548,  2575,  2593,  2597,  2613,  2661,  2678,
    2696,  2706,  2716,  2726,  2789,  2800,  2816,  2817,  2822,  2825,
    2829,  2858,  2887,  2916,  2950,  2972,  2998,  3020,  3043,  3064,
    3120,  3144,  3169,  3195,  3308,  3327,  3370,  3391,  3397,  3412,
    3440,  3457,  3466,  3480,  3494,  3500,  3506,  3515,  3524,  3533,
    3547,  3609,  3627,  3644,  3659,  3688,  3700,  3724,  3728,  3733,
    3741,  3746,  3752,  3757,  3763,  3771,  3775,  3779,  3784,  3844,
    3860,  3877,  3894,  3916,  3938,  3973,  3981,  3989,  3995,  4002,
    4009,  4029,  4055,  4067,  4079,  4087,  4095,  4104,  4103,  4118,
    4117,  4132,  4131,  4146,  4145,  4159,  4166,  4173,  4180,  4187,
    4194,  4201,  4208,  4215,  4223,  4222,  4236,  4235,  4249,  4248,
    4262,  4261,  4275,  4274,  4288,  4287,  4301,  4300,  4314,  4313,
    4327,  4326,  4343,  4346,  4352,  4364,  4384,  4408,  4412,  4416,
    4420,  4424,  4428,  4434,  4440,  4444,  4448,  4452,  4456,  4475,
    4488,  4489,  4490,  4491,  4492,  4496,  4497,  4498,  4501,  4535,
    4561,  4585,  4588,  4604,  4607,  4624,  4627,  4633,  4636,  4643,
    4646,  4653,  4709,  4779,  4784,  4851,  4887,  4895,  4938,  4977,
    4997,  5029,  5056,  5082,  5108,  5134,  5160,  5182,  5210,  5238,
    5266,  5294,  5322,  5361,  5400,  5421,  5442,  5469,  5473,  5483,
    5518,  5519,  5520,  5524,  5530,  5542,  5560,  5588,  5589,  5590,
    5591,  5592,  5593,  5594,  5595,  5596,  5603,  5604,  5605,  5606,
    5607,  5608,  5609,  5610,  5611,  5612,  5613,  5614,  5615,  5616,
    5617,  5618,  5619,  5620,  5621,  5622,  5623,  5624,  5625,  5626,
    5627,  5628,  5629,  5630,  5631,  5632,  5633,  5634,  5635,  5644,
    5645,  5646,  5647,  5648,  5649,  5650,  5651,  5652,  5653,  5654,
    5659,  5658,  5666,  5671,  5676,  5693,  5711,  5729,  5747,  5765,
    5770,  5776,  5791,  5810,  5830,  5850,  5870,  5893,  5898,  5903,
    5913,  5923,  5928,  5939,  5948,  5953,  5958,  5985,  5989,  5993,
    5997,  6001,  6008,  6012,  6016,  6020,  6027,  6032,  6039,  6044,
    6048,  6053,  6057,  6065,  6076,  6080,  6092,  6100,  6108,  6115,
    6125,  6154,  6158,  6162,  6166,  6170,  6174,  6178,  6182,  6186,
    6215,  6244,  6273,  6302,  6315,  6328,  6341,  6354,  6364,  6374,
    6384,  6396,  6409,  6421,  6425,  6429,  6433,  6437,  6455,  6473,
    6481,  6489,  6518,  6531,  6536,  6540,  6544,  6556,  6560,  6572,
    6589,  6599,  6603,  6618,  6623,  6630,  6634,  6647,  6661,  6675,
    6689,  6703,  6711,  6722,  6726,  6730,  6738,  6744,  6750,  6758,
    6766,  6773,  6781,  6796,  6810,  6824,  6836,  6852,  6861,  6870,
    6880,  6891,  6899,  6907,  6911,  6930,  6937,  6943,  6950,  6958,
    6957,  6970,  6975,  6981,  6990,  7003,  7006,  7010
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
  "tCone", "tEllipsoid", "tQuadric", "tShapeFromFile", "tRectangle",
  "tDisk", "tCharacteristic", "tLength", "tParametric", "tElliptic",
  "tRefineMesh", "tAdaptMesh", "tRelocateMesh", "tSetFactory",
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
     455,   456,    63,   457,   458,   459,   460,    60,    62,   461,
     462,    43,    45,    42,    47,    37,    33,   463,   464,   465,
      94,    40,    41,    91,    93,    46,    35,    44,   123,   125,
     126
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   231,   232,   232,   233,   233,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   235,   235,   236,   236,   236,
     236,   236,   236,   237,   237,   237,   237,   238,   238,   238,
     238,   238,   238,   239,   239,   240,   240,   242,   243,   241,
     244,   244,   246,   245,   247,   247,   249,   248,   250,   250,
     252,   251,   253,   253,   253,   253,   253,   254,   254,   255,
     255,   256,   256,   257,   257,   257,   257,   257,   257,   257,
     257,   257,   257,   257,   257,   257,   257,   257,   257,   257,
     257,   257,   257,   257,   257,   257,   257,   257,   257,   257,
     257,   257,   257,   257,   257,   257,   257,   257,   257,   257,
     257,   257,   257,   257,   257,   257,   257,   257,   257,   257,
     257,   257,   257,   257,   258,   258,   259,   259,   259,   260,
     259,   261,   259,   262,   259,   259,   263,   259,   264,   264,
     265,   265,   265,   266,   266,   267,   267,   267,   268,   268,
     269,   269,   269,   269,   270,   270,   270,   271,   271,   271,
     272,   272,   272,   273,   273,   273,   274,   274,   275,   275,
     276,   276,   276,   276,   276,   276,   276,   276,   276,   276,
     276,   276,   276,   276,   276,   276,   276,   276,   276,   276,
     276,   276,   276,   276,   276,   276,   276,   276,   276,   276,
     276,   276,   276,   276,   276,   276,   276,   276,   277,   277,
     277,   277,   277,   277,   277,   277,   278,   278,   279,   279,
     279,   279,   279,   279,   280,   280,   280,   280,   280,   280,
     280,   280,   280,   280,   280,   280,   281,   281,   281,   281,
     281,   282,   282,   283,   284,   284,   284,   284,   284,   284,
     285,   285,   285,   285,   285,   285,   285,   285,   285,   285,
     285,   285,   285,   285,   285,   285,   285,   285,   285,   286,
     287,   287,   287,   287,   287,   287,   287,   287,   287,   287,
     287,   287,   287,   287,   288,   288,   288,   289,   288,   290,
     288,   291,   288,   292,   288,   288,   288,   288,   288,   288,
     288,   288,   288,   288,   293,   288,   294,   288,   295,   288,
     296,   288,   297,   288,   298,   288,   299,   288,   300,   288,
     301,   288,   302,   302,   303,   303,   303,   303,   303,   303,
     303,   303,   303,   303,   303,   303,   303,   303,   303,   303,
     304,   304,   304,   304,   304,   305,   305,   305,   306,   306,
     307,   308,   308,   309,   309,   310,   310,   311,   311,   312,
     312,   313,   313,   313,   313,   313,   313,   313,   313,   313,
     313,   313,   313,   313,   313,   313,   313,   313,   313,   313,
     313,   313,   313,   313,   313,   313,   313,   314,   314,   314,
     315,   315,   315,   316,   316,   316,   316,   317,   317,   317,
     317,   317,   317,   317,   317,   317,   317,   317,   317,   317,
     317,   317,   317,   317,   317,   317,   317,   317,   317,   317,
     317,   317,   317,   317,   317,   317,   317,   317,   317,   317,
     317,   317,   317,   317,   317,   317,   317,   317,   317,   318,
     318,   318,   318,   318,   318,   318,   318,   318,   318,   318,
     319,   318,   318,   318,   318,   318,   318,   318,   318,   318,
     318,   318,   318,   318,   318,   318,   318,   318,   318,   318,
     318,   318,   318,   318,   318,   318,   318,   320,   320,   320,
     320,   320,   321,   321,   321,   321,   322,   322,   323,   323,
     323,   323,   323,   323,   324,   324,   325,   325,   325,   325,
     325,   325,   325,   325,   325,   325,   325,   325,   325,   325,
     325,   325,   325,   325,   325,   325,   325,   325,   325,   325,
     325,   325,   325,   325,   325,   325,   325,   325,   325,   325,
     325,   325,   325,   326,   326,   326,   326,   327,   327,   327,
     327,   328,   328,   329,   329,   330,   330,   330,   330,   330,
     330,   330,   330,   331,   331,   331,   331,   331,   331,   331,
     331,   331,   331,   331,   331,   331,   331,   331,   331,   331,
     331,   331,   331,   331,   331,   331,   331,   331,   331,   332,
     331,   333,   333,   334,   334,   335,   335,   335
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
      10,     7,     7,     7,     7,     7,     7,     8,     4,     8,
      12,     8,     8,     7,     7,     4,     8,     8,     5,    11,
       5,     9,     9,     4,     9,     9,     1,     1,     0,     2,
       6,     6,     6,     6,     8,    10,    14,    16,    12,    14,
      14,    14,    14,     8,     8,     6,     4,     6,     6,     3,
       4,     5,     6,     5,     3,     3,     4,     5,     4,     5,
       3,     5,     7,     7,     3,     7,     3,     2,     2,     2,
       2,     2,    15,     2,     2,     2,     2,     2,    16,    11,
       6,     8,     8,    10,     1,     2,     2,     1,     3,     3,
       4,     4,     1,     1,     5,    11,    13,     0,     7,     0,
      13,     0,    15,     0,     6,     8,     8,     8,    12,    12,
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
       8,     4,    14,     1,     1,     3,     3,     9,     7,     1,
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
       0,     0,     0,     2,     3,     1,   585,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   340,   341,   342,   343,   344,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   274,     0,     0,   282,   283,     0,
       0,     0,   277,     0,     0,     0,     0,     0,   390,   391,
     392,     0,     0,     5,     7,     6,     8,     9,    10,    23,
      11,    12,    13,    14,    22,    21,    20,    15,     0,    16,
      17,    18,    19,     0,    24,   586,     0,   439,   585,   553,
     440,   442,   443,   441,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   555,     0,   576,   557,   447,   448,
     449,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   444,   445,   446,   556,     0,     0,     0,     0,    69,
      70,     0,     0,   218,     0,     0,     0,   397,     0,   545,
     586,   454,     0,     0,     0,     0,   261,     0,   263,   264,
     259,   260,     0,   265,   266,   126,   138,    69,    70,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   267,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   477,     0,     0,     0,     0,
       0,   218,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   585,     0,   218,   586,     0,
       0,   387,     0,     0,     0,     0,     0,     0,     0,     0,
     585,   495,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   517,   518,     0,   519,   488,
     494,     0,   489,   586,   454,     0,     0,     0,     0,   585,
       0,     0,   539,     0,     0,     0,     0,   257,   258,     0,
     585,     0,     0,     0,   275,   276,     0,   218,     0,   218,
     585,     0,   586,     0,     0,   218,   393,     0,     0,    69,
      70,     0,     0,    62,    66,    65,    64,    63,    68,    67,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   400,   399,
     401,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     217,     0,   216,     0,     0,   254,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    37,   250,     0,     0,   462,   188,     0,   585,     0,
     545,   586,   546,     0,     0,   581,     0,   124,   124,     0,
       0,     0,     0,   533,   534,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   355,   355,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   218,   218,     0,   479,   478,     0,     0,
       0,     0,   218,   218,     0,     0,     0,     0,     0,     0,
       0,   293,     0,   218,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   357,     0,     0,     0,     0,     0,     0,
       0,   239,   388,     0,     0,     0,     0,     0,     0,     0,
       0,    69,    70,     0,     0,     0,     0,     0,     0,     0,
       0,   501,     0,     0,   502,     0,   503,     0,   504,     0,
       0,     0,     0,     0,     0,   399,   496,     0,   490,     0,
       0,     0,   365,    69,    70,     0,   256,     0,     0,     0,
       0,     0,   218,     0,     0,     0,     0,     0,   279,   278,
       0,   244,     0,   245,     0,     0,     0,   218,     0,     0,
       0,     0,   345,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    78,     0,     0,     0,   467,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   450,
     579,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      62,    63,     0,   398,    62,    63,     0,     0,    62,     0,
       0,     0,     0,     0,   213,     0,     0,     0,     0,   219,
       0,     0,     0,   415,   414,   413,   412,   408,   409,   411,
     410,   403,   402,   404,   405,   406,   407,     0,     0,     0,
     189,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   125,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   349,     0,     0,
       0,     0,     0,     0,   384,   385,   386,     0,     0,     0,
       0,     0,     0,   353,     0,     0,     0,   154,   155,     0,
     157,   158,     0,   160,   161,     0,   163,   164,     0,   183,
       0,   198,     0,   205,     0,     0,     0,     0,   175,   218,
       0,     0,     0,     0,     0,   481,   480,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   287,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   368,     0,
       0,   240,     0,     0,   236,     0,     0,     0,   383,   382,
       0,     0,     0,     0,     0,   467,    71,    72,     0,   520,
       0,     0,     0,     0,     0,   454,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   505,     0,   506,     0,   507,
       0,   508,     0,     0,   398,   491,   498,     0,   404,   497,
       0,     0,     0,   521,     0,     0,     0,     0,     0,     0,
       0,     0,   280,   281,     0,     0,   246,   248,     0,   587,
       0,     0,     0,     0,     0,     0,    62,    63,     0,     0,
      62,    63,     0,     0,     0,     0,    93,    77,     0,   456,
     455,   469,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   438,   426,     0,   428,   429,   430,   431,   432,   433,
     434,     0,     0,     0,   566,     0,   573,   562,   563,   564,
       0,   578,   577,     0,   474,     0,     0,     0,     0,   567,
     568,   569,   476,   575,   143,   148,   116,     0,     0,   558,
       0,   560,     0,   452,   459,   460,   554,     0,     0,     0,
      62,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   110,     0,     0,     0,     0,   461,     0,     0,     0,
       0,   583,     0,     0,    47,     0,     0,     0,    60,     0,
      38,    39,    40,    41,    42,   458,   457,     0,     0,   551,
      27,    25,     0,     0,     0,     0,    28,     0,     0,   251,
     582,    73,   127,    74,   139,     0,     0,     0,   535,   536,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     170,     0,     0,     0,   351,   356,   354,     0,   364,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   398,   398,
     398,     0,     0,     0,     0,     0,   247,   249,     0,     0,
       0,   208,   210,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   322,     0,
     284,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   358,   367,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   456,   455,     0,     0,   524,     0,   523,
     522,     0,     0,   531,     0,     0,   500,     0,     0,     0,
       0,     0,     0,     0,   492,     0,     0,   458,   457,     0,
       0,     0,     0,     0,     0,   241,     0,     0,     0,     0,
       0,   243,     0,   346,     0,     0,     0,     0,   394,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   584,
       0,     0,   464,     0,   463,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    87,     0,    91,     0,     0,
      79,     0,     0,     0,     0,    83,   106,   108,     0,     0,
     543,     0,   114,     0,     0,     0,     0,     0,   416,     0,
       0,     0,     0,     0,    33,   466,   465,   549,   547,    26,
       0,     0,   550,   548,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   168,   168,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     173,     0,     0,     0,     0,     0,     0,     0,     0,   362,
       0,     0,   156,     0,   159,     0,   162,     0,   165,     0,
       0,     0,     0,     0,     0,     0,   242,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   328,     0,     0,   327,
       0,   334,     0,   336,     0,   330,     0,   332,     0,   294,
     323,     0,     0,     0,   235,     0,     0,     0,     0,     0,
       0,     0,   369,     0,   238,   237,   389,     0,     0,    34,
      35,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   509,   510,   511,   512,   499,   493,     0,
       0,     0,     0,   540,     0,     0,     0,   270,     0,     0,
       0,   218,   347,   218,     0,     0,     0,     0,    88,     0,
      92,     0,     0,    80,     0,    84,     0,   253,   468,   252,
     427,   435,   436,   437,   574,     0,     0,   572,   472,   473,
     475,     0,     0,   451,   144,     0,   580,   149,   471,   559,
     561,   453,     0,     0,     0,    89,     0,     0,     0,    62,
       0,     0,     0,     0,    81,     0,     0,     0,   541,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   486,     0,
       0,    29,    30,     0,    31,     0,     0,   128,   135,     0,
       0,    75,    76,   171,     0,     0,     0,     0,     0,     0,
     174,     0,     0,   191,   192,     0,     0,   176,   203,   193,
     196,   194,   195,     0,     0,     0,   204,     0,   166,     0,
     361,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   255,     0,     0,     0,     0,   218,   218,     0,
     304,     0,   306,     0,   308,     0,   329,   488,     0,     0,
     335,   337,   331,   333,     0,     0,   288,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   468,   527,   526,   525,     0,     0,     0,     0,     0,
       0,     0,   528,   179,   180,     0,     0,     0,     0,   117,
     121,     0,     0,   345,   345,     0,   395,     0,     0,     0,
      90,     0,     0,     0,    82,     0,   470,     0,     0,     0,
       0,     0,     0,   100,     0,     0,    94,     0,     0,     0,
       0,   111,     0,     0,   112,     0,   544,   220,   221,   222,
     223,     0,     0,    43,     0,     0,     0,     0,     0,    45,
     552,     0,     0,   129,   136,     0,     0,     0,     0,   169,
     177,   178,   182,     0,     0,   197,     0,     0,   363,     0,
     186,     0,     0,   352,   202,   172,   185,   201,   207,   184,
       0,   199,   206,     0,     0,     0,     0,     0,     0,   485,
       0,   484,     0,     0,     0,   295,     0,     0,   296,     0,
       0,   297,     0,     0,     0,     0,     0,     0,     0,   234,
     233,     0,     0,     0,     0,     0,     0,     0,     0,   224,
       0,     0,   366,    36,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   538,     0,   272,   271,     0,     0,     0,
       0,     0,     0,     0,   101,     0,     0,    95,     0,     0,
       0,   565,   571,   570,     0,   145,   147,     0,   150,   151,
     152,   102,   104,    96,    98,   107,   109,     0,   115,     0,
      85,    48,     0,     0,     0,   487,     0,     0,     0,    32,
       0,   143,   148,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   187,     0,   359,   359,     0,   122,   123,
     218,     0,   211,   212,     0,     0,     0,     0,     0,     0,
       0,   324,     0,     0,   218,     0,     0,     0,     0,     0,
       0,     0,     0,   215,   214,   529,   530,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   118,   119,     0,     0,
     348,     0,   103,   105,    97,    99,    86,     0,   533,   534,
       0,     0,   542,     0,    44,     0,     0,     0,    46,    61,
       0,     0,     0,   133,   131,   377,   379,   378,   380,   381,
     190,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   483,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   339,     0,     0,     0,   289,     0,
     225,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   537,   273,     0,     0,   218,   396,     0,
     146,     0,     0,   153,   113,     0,     0,     0,     0,     0,
     130,   137,   143,   143,     0,     0,     0,     0,     0,   360,
     370,     0,     0,   371,     0,   209,     0,   310,     0,     0,
     312,     0,     0,   314,     0,     0,     0,   325,     0,   285,
       0,   218,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   181,   120,   269,   345,     0,   140,     0,
       0,    52,     0,    58,     0,     0,     0,     0,     0,   167,
     200,     0,   374,     0,   375,   376,   482,   298,     0,     0,
     305,   299,     0,     0,   307,   300,     0,     0,   309,     0,
       0,     0,   291,   228,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   134,   132,     0,     0,     0,     0,   316,
       0,   318,     0,   320,   326,   338,   290,   286,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   141,   142,    49,     0,    56,     0,     0,     0,     0,
       0,     0,   301,     0,     0,   302,     0,     0,   303,     0,
       0,   229,   230,   231,   232,     0,   226,     0,     0,     0,
       0,     0,   350,     0,    50,     0,     0,   262,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   292,     0,   532,
       0,     0,     0,     0,     0,     0,     0,     0,   268,     0,
       0,   311,     0,   313,     0,   315,     0,   227,     0,     0,
       0,     0,    51,    53,     0,    54,     0,     0,     0,     0,
       0,     0,   513,   514,   515,   516,     0,     0,    59,   372,
     373,   317,   319,   321,    55,    57
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,   103,  1072,   104,   105,   767,  1652,  1658,
    1060,  1289,  1863,  2103,  1061,  2039,  2144,  1062,  2105,  1063,
    1064,  1293,   390,   485,   205,   899,   106,   785,   497,  1791,
    1943,  1942,  1792,   498,  1857,  1257,  1464,  1258,  1467,   826,
     829,   832,   835,  1682,  1517,   749,   335,   461,   462,   109,
     110,   111,   112,   113,   114,   115,   116,   336,  1161,  1970,
    2058,   864,  1706,  1709,  1712,  2008,  2012,  2016,  2083,  2086,
    2089,  1157,  1158,   337,   952,   338,   120,  1338,  1117,   823,
     877,  1887,   121,   122,   123,   124,   339,   207,  1014,   557,
     285,  1497,   340,   341,   342,   629,   351,  1045,  1281,   495,
     490,  1015,   496,   372,   344
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1772
static const yytype_int16 yypact[] =
{
   10377,    40,    91, 10526, -1772, -1772,  4797,    86,    34,  -194,
     -88,    50,   139,   161,   172,   203,    -4,   242,   275,   -72,
      -2,   -89,   -89,  -135,    82,    90,    21,   135,   148,    28,
     181,   228,   252,   255,   271,   281,   285,   185,   366,   432,
     509,   303,   102,   314,   321,   458,   464,   586,   477,   648,
     801,   233,   352,   494,   -85,   390,  -139,  -139,   408,   243,
      66, -1772, -1772, -1772, -1772, -1772,   232,   543,   555,    13,
      65,   573,   590,   295,   686,   700,   715,  5710,   732,   491,
     521,   560,     5,    24, -1772,   641,   646, -1772, -1772,   769,
     840,   528, -1772,  3405,   651,  5585,    35,    37, -1772, -1772,
   -1772, 10221,   655, -1772, -1772, -1772, -1772, -1772, -1772, -1772,
   -1772, -1772, -1772, -1772, -1772, -1772, -1772, -1772,   126, -1772,
   -1772, -1772, -1772,    56, -1772,   -57,    96, -1772,    14, -1772,
   -1772, -1772, -1772, -1772,   -89,   -89,   -89,   -89,   -89,   -89,
     -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,
     -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,   660,
     668,   669,   -89,   -89,   -89,   -89,   678,   -89,   -89,   -89,
     -89,   -89,   -89,   684, -1772,   -89, -1772, -1772, -1772, -1772,
   -1772,   -89,   -89,   895,   691,   702,   705,   -89,   -89,   706,
     709, -1772, -1772, -1772, -1772,   713, 10221, 10221, 10221,  9363,
    9430,    27,    31,   324,   712,   729,   625, -1772,   733,   943,
     -46,   -75,   959, 10221,  6764,  6764, -1772, 10221, -1772, -1772,
   -1772, -1772,  6764, -1772, -1772, -1772, -1772, -1772, -1772,  4692,
      31, 10221,  9149, 10221, 10221,   748, 10221,  9149, 10221, 10221,
     752,  9149, 10221, 10221, 10221, 10221,  6764, 10221, 10221,  6663,
     770,   749, -1772,  9149,  5710,  5710,  5710,  6764, 10221,   778,
     791,  5710,  5710,  5710,   798,   832,   841,   869,   874,  6883,
    7103,  7323,   762,  2655,   949,  6663,     5,   772,   799,  -139,
    -139,  -139, 10221, 10221,   -93, -1772,   -70,  -139,   814,   815,
     839,  8863,   -15,   144,   875,   927,   940,   968,   973,   980,
     993,  5710,  5710,  6663,   997,    17,   845, -1772,   991,  1144,
    1171, -1772,   977,  1013,  1021,  5710,  5710,  1033,  1040,  1044,
     525, -1772,    70,   -89,   -89,   -89,   -89,     8,    38,    39,
      48,   728,  7543, 10221,  5039, -1772, -1772,  1036, -1772,  1095,
   -1772,  1265, -1772,    -5,  -155,  1266, 10221, 10221, 10221,  -189,
   10221,  1060, -1772,  1111, 10221, 10221, 10221, -1772, -1772, 10221,
    1056,  1284,  1286,  1066, -1772, -1772,  1289, -1772,  1290, -1772,
     441,  3412,   504,  6764, 10221, -1772, -1772,  6663,  6663,  9649,
    9716,  1084,  1086,  4692, -1772, -1772, -1772, -1772, -1772, -1772,
    6663,  1310,  1097, 10221, 10221,  1314, 10221, 10221, 10221, 10221,
   10221, 10221, 10221, 10221, 10221, 10221, 10221, 10221, 10221, 10221,
   10221, 10221, 10221, 10221, 10221, 10221, 10221, 10221,  6764,  6764,
    6764,  6764,  6764,  6764,  6764,  6764,  6764,  6764,  6663,  6764,
    6764, 10221,  6764,  6764,  6764,  6764,  6764, 10221,  4692, 10221,
    6764,  6764,  6764,  6764,  6764,    31,  4692,    31,  1103,  1103,
    1103,   140, 12086,   152,  5838,   118,  1099,  1318,   -89,  1098,
   -1772,  1101,  6205, 10221,  9149, -1772, 10221, 10221, 10221, 10221,
   10221, 10221, 10221, 10221, 10221, 10221, 10221, 10221, 10221, 10221,
   10221, -1772, -1772, 10221, 10221, -1772, -1772,  1268,   584,  -173,
   -1772,   650, -1772,   -24,  9675, -1772,   290,   187,   236,  1100,
    1104, 12107,  9149,  3542, -1772,   253, 12128, 12149, 10221, 12170,
     501, 12191, 12212, 10221,   577, 12233, 12254, 12275, 12296,  1106,
   12317, 12338,  1327, 10221, 10221,   594,  1329,  1333,  1335,  1121,
   12359, 10221, 10221,  1342,  1343,  1343, 10221,  8935,  8935,  8935,
    8935, 10221,  1347, 10221,  1348, 10221,  1349,  9149,  9149,  9388,
    1134,  1351,  1130, -1772, -1772,  -114, -1772, -1772,  9772,  9844,
    -139,  -139,   324,   324,   146, 10221, 10221, 10221,  8863,  8863,
   10221,  6205,   177, -1772, 10221, 10221, 10221, 10221, 10221, 10221,
   10221, 10221, 10221,  1356,  1358,  1366, 10221,  1368, 10221, 10221,
    1309, -1772, -1772,  9149,  9149,  9149,  1369,  1370, 10221, 10221,
   10221, 10221, 10221,  1373,   246,  7763,  7983, 10221, 10221,  6764,
   10221, -1772,  1316, 10221, -1772,  1317, -1772,  1321, -1772,  1324,
      42,    43,    46,    47,  9149,  1103, -1772, 12380, -1772,   595,
   10221,  8203, -1772, 10221, 10221,   301, -1772, 12401, 12422, 12443,
    1224,  9886, -1772,  1161,  3628, 12464, 12485, 11718, -1772, -1772,
    9149, -1772,  2005, -1772,  2971, 10221, 10221, -1772, 10221, 10221,
    1167, 12506,  4825,  1170,   681,   194, 12527,   200, 11741, 10221,
    9149,  1398,  1399, -1772, 10221, 12548, 11764,   -63,  3982,  3982,
    3982,  3982,  3982,  3982,  3982,  3982,  3982,  3982,  3982,  9960,
    3982,  3982,  3982,  3982,  3982,  3982,  3982, 10058, 10100, 10126,
     159,   639,   159,  1193,  1199,  1198,   530,   530,  1202,   530,
    1203,  1204,  1205, 10152,   530,   530,   530,   400,   530,  4687,
   -1772,  1305,  1213,  1218,  1225,   679,   687,  1227,  1228,  1222,
    1382,  1407,  6663,   145,  1409,  1410,  6663,   107,  4692, 10221,
    1449,  1452,    29,   530, -1772,   182,    41,    33,   215, -1772,
    2934,   693,  3687,  2533,  2323,   872,   872,   672,   672,   672,
     672,   385,   385,  1103,  1103,  1103,  1103,    26, 12569, 11787,
   -1772, 10221, 10221,  1453,    16,  9149, 10221, 10221,  1456,  9149,
   10221,  1457,  6764,  1458, -1772,    31,  1459,  6764, 10221,  4692,
    1478,  9149,  9149,  1293,  1479,  1480, 12590,  1484,  1300,  1485,
    1486, 12611,  1323,  1489,  1492,  1494,  1495, -1772,  1497,  1514,
   10221, 12632,  3177,  1267, -1772, -1772, -1772,  1516,  1517, 12653,
   12674, 10221,  6663,  1522,  1521, 12695,  1306,  4687,  1302,  1308,
    4687,  1304,  1311,  4687,  1307,  1313,  4687,  1312, 12716, -1772,
   12737, -1772, 12758, -1772,   721,   725,  9149,  1315, -1772, -1772,
    3205,  3329,  -139, 10221, 10221, -1772, -1772,  1303,  1319,  8863,
   10522, 10548, 10574,  9553,   923,  -139,  3558, 12779,  5607, 12800,
   12821, 12842, 12863, 12884, 12905, 12926, 10221,  1544, -1772, 10221,
   12947, -1772, 11810, 11833, -1772,   737,   741,   745, -1772, -1772,
   11856, 11879, 10600, 12968, 11902,  -155, -1772, -1772,  9149, -1772,
    9149,  3542,  1330,  9149,  1345,  -108, 10626, 10652,   530, 10678,
    1325,  5810,  1352,  1355,  1357, -1772,  9149, -1772,  9149, -1772,
    9149, -1772,  9149,   756, -1772, -1772,  3865,  9149,  1103, -1772,
   12989, 11925,  9149, -1772,  1563,  1564,  1568,  1354, 10221,  3600,
   10221, 10221, -1772, -1772,    58,   757, -1772, -1772,  3903, -1772,
    1577,  9935,  1359,  1362,  6663,  1580,  1547,  1548,  6663,   145,
    1549,  1550,  6663,   145,  6047,   779, -1772, -1772, 11948,   406,
    1188, -1772, -1772, -1772, -1772, -1772, -1772, -1772, -1772, -1772,
   -1772, -1772, -1772, 10221, -1772, -1772, -1772, -1772, -1772, -1772,
   -1772, 10221, 10221, 10221, -1772,  9149, -1772, -1772, -1772, -1772,
    6764, -1772, -1772, 10221, -1772,  6663,  6764,  6764,  6764, -1772,
   -1772, -1772, -1772, -1772, -1772, -1772, -1772, 10221,  6764, -1772,
    6764, -1772, 10221, -1772, -1772, -1772, -1772,   -89,   -89,  1581,
   -1772, 10221,  1591,   -89,   -89,  1592,    30, 10221,  1595,  1598,
    1353, -1772,  1599,  1384,     5,  1602, -1772,  9149,  9149,  9149,
    9149, -1772,   530, 10221, -1772,  1389,  1390,  1377, -1772,  1607,
   -1772, -1772, -1772, -1772, -1772,   411,   552, 13010, 11971, -1772,
   -1772,  1406,  6764,   460, 13031, 11994, -1772,   461, 10704, -1772,
   -1772, -1772,     9, -1772, -1772,  3982,   530,  -139,  3542, -1772,
     921,  6663,  6663,  1609,  6663,   926,  6663,  6663,  1610,  1526,
    6663,  6663,  6663,  6663,  6663,  6663,  1488,  1612,  1614,  9149,
   -1772,  6663,  1619,  1626,  1744, -1772, -1772,  1628, -1772,  1631,
     208, 10221,   208, 10221,   208, 10221,   208, 10221,  1633,  1635,
    1637,  1638,  1639,   805,  1632,  4258, -1772, -1772,   201, 10730,
   10756, -1772, -1772,  6327,  -124,  -139,  -139,  -139,  1643, 10007,
    1420,  1644,  1428,    18,    32,    44,    55,   -41, -1772,   223,
   -1772,   923,  1645,  1648,  1649,  1650,  1651,  1652,  1659,  1660,
    1661,  4687, -1772,  1543,  1423,  1663,  1664,  1665,  1565,  1666,
    1668,  1671, 10221,  -155,   143,   806,   809, -1772,   810, -1772,
   -1772, 10221, 10221, -1772, 10221, 10221, -1772, 10221, 10221, 10221,
     821,   822,   825,   830, -1772, 10221,   834,  -155,  -155,   847,
    6663,  6663,  6663,  1674, 10782, -1772,  3941,   910,  1675,  1676,
    1445, -1772,  1454, -1772,  1603,  1455,  6663,  1460, -1772,   -89,
     -89,  1678, 10221,  1679,   -89,   -89,  1681, 10221,  1682, -1772,
     530,  1698, -1772,  1677, -1772,  1707,  3982,  3982,  3982,  3982,
     711,  1491,  9595,  1498,   530,   530,  1496,   719,   720, 13052,
    1499,   530,  3982,  1963,  6764, -1772,  1629, -1772,  1963,  6764,
   -1772,   178,  1501,  1709,  1711, -1772, -1772, -1772,     5, 10221,
   -1772,   878, -1772,   882,   899,   900,   904,   208,  4687,  1506,
   10221, 10221,  6663,  1502, -1772, -1772, -1772, -1772,  1507, -1772,
    1716,    23, -1772, -1772,  1725, 10221,  5930,  1511,  1512,  1729,
    1731,    74,  1510,  1513,  1630,  1630,  6663,  1733,  1515,  1531,
    1736,  1756,  6663,  1537,  1760,  1761,  1762,  1763,  1764,  1765,
   -1772,  1767,  6663,   908,  1769,  6663,  6663,  1773,  1772, -1772,
    6663,  6663,  4687,  6663,  4687,  6663,  4687,  6663,  4687,  6663,
    6663,  6663,  1545,  1551,  1774,   328, -1772, 10221, 10221, 10221,
    1552,  1554,  -152,  -144,   -81,  1561, -1772,  1928,  6663, -1772,
   10221, -1772,  1779, -1772,  1780, -1772,  1781, -1772,  1782, -1772,
   -1772,  8863,   -21,  6150, -1772,  1566,  1567,  1569,  1570,  1571,
    1572,  8423, -1772,  9149, -1772, -1772, -1772,  1574, 10221, -1772,
   -1772, 12017,  1785,   530,  1597,  1579, 10808, 10834, 10860, 10886,
   10912, 10938, 10964, -1772, -1772, -1772, -1772,  4687, -1772,   530,
    1786,  1787,  1667, -1772, 10221, 10221, 10221, -1772,  1815,   804,
    4692, -1772, -1772, -1772,  1600,  1816,  1963,  6764, -1772,  2036,
   -1772,  1963,  6764, -1772,  2069, -1772,   208, -1772,   559, -1772,
   -1772, -1772, -1772, -1772, -1772,  6764, 10221, -1772, -1772, -1772,
   -1772,  6764,  1822, -1772, -1772,    22, -1772, -1772, -1772, -1772,
   -1772, -1772,  1839,   159,   159, -1772,  1840,   159,   159,  4692,
   10221,  1841,  1824,    29, -1772,  1845, 12040,     5, -1772,  1846,
    1848,  1849,  1850,  6663, 10221, 10990, 11016,   909, -1772, 10221,
    1853, -1772, -1772,  6764, -1772, 11042,  5270,  4687, -1772,  1851,
    1852, -1772, -1772, -1772, 10221, 10221,  -139,  1854,  1856,  1857,
   -1772, 10221, 10221, -1772, -1772,  1858, 10221, -1772, -1772, -1772,
   -1772, -1772, -1772,  1860,  1861,  1641, -1772,  1865,  1708, 10221,
   -1772,  1867,  1869,  1870,  1872,  1873,  1874,  1139,  1875,  9149,
    9149, 10221, -1772,  8935,  6400, 13073,  4439,   324,   324,  -139,
    1878,  -139,  1879,  -139,  1880, 10221, -1772,   554,  1662, 13094,
   -1772, -1772, -1772, -1772,  6780,   254, -1772,  1881,  1882,  6663,
    -139,  -139,  -139,  -139,  -139,  4502,  1884,   917, 10221,  2094,
    1885,  -155, -1772, -1772, -1772, 10221, 10221, 10221, 10221, 10221,
   10221, 10221, -1772, -1772, -1772,  6663,  4986,   588, 13115, -1772,
   -1772,  6370,  1670,  4825,  4825,  6663, -1772,  1886,   159,   159,
   -1772,  1887,   159,   159, -1772,  6663, -1772,  1673,  3982,   530,
    5490,  6443,  4692, -1772,  1893,  1894, -1772,  1895,  1897,  1898,
    2262, -1772,  1899,  1901, -1772,  1680, -1772, -1772, -1772, -1772,
   -1772,  1921,   632,  4687, 10221, 10221,  6663,  1700,   920,  4687,
   -1772,  1924, 10221, -1772, -1772,  1704,  1705,  6820,  7000,   574,
   -1772, -1772, -1772,  7040,  7220, -1772,  7260,  1930, -1772,  6663,
   -1772,  1855,  1931,  4687, -1772, -1772, -1772, -1772, -1772, -1772,
    1710, -1772, -1772,   924,   929,  9486,  2413,  1933,  1712, -1772,
   10221, -1772,  1713,  1715,   282, -1772,  1732,   289, -1772,  1734,
     293, -1772,  1735, 12063,  1935,  6663,  1929,  1738, 10221, -1772,
   -1772,   930,   299,   316,   360,   368,   374,  8643,   377, -1772,
    1955,  7440, -1772, -1772,  3982,  3982, 11068, 11094, 11120, 11146,
   11172,  1814, 10221, -1772, 10221, -1772, -1772,  9149,  2599,  1970,
    4692,  1748,  1749,  1750, -1772,  1974,  1975, -1772,  1976,  1977,
    1978, -1772, -1772, -1772,  5039, -1772, -1772,  6764,  4687, -1772,
   -1772, -1772, -1772, -1772, -1772, -1772, -1772,     5, -1772,  1823,
   -1772, -1772, 10221, 11198, 11224, -1772,  6663, 10221,  1980, -1772,
   11250, -1772, -1772,  6663,  6663,  1982,  1983,  1984,  1986,  1987,
    1988,   933,  1768, -1772,  6663,   330,   425,  9149, -1772, -1772,
     324,  5207, -1772, -1772,  8863,   923,  8863,   923,  8863,   923,
    1989, -1772,   939,  6663, -1772,  7480,  1995,  9149,  -139,  -139,
    -139,  -139,  -139, -1772, -1772, -1772, -1772, 10221, 10221, 10221,
   10221, 10221, 10221,  7660,  7700,   946, -1772, -1772,  1783,  1775,
   -1772,  1996, -1772, -1772, -1772, -1772, -1772,   947,  2983,  1997,
     951,  2010, -1772,  1791,  4687, 10221, 10221,   956,  4687, -1772,
   10221,   957,   961, -1772, -1772, -1772, -1772, -1772, -1772, -1772,
   -1772,  1796, 10221,   970,  1797,  -139,  6663,  2020,  1804,  -139,
    2028,   971,  1806, 10221, -1772,  7880,   382,   336,  7920,   396,
     391,  8100,   399,   502, -1772,  6663,  2030,  1920,  5765,  1810,
   -1772,   975,   405,   426,   443,   445,   447, 11276, 11302, 11328,
   11354, 11380,  2730, -1772, -1772,  2033,  2035, -1772, -1772, 10221,
   -1772,  4692,    31, -1772, -1772, 10221, 13136, 11406,    52, 11432,
   -1772, -1772, -1772, -1772, 10221,  8140,  2037,  -139,    78, -1772,
   -1772,  -139,    98, -1772,  2039, -1772,  8320,  2040, 10221,  2041,
    2042, 10221,  2043,  2045, 10221,  2046,  1825, -1772, 10221, -1772,
     923, -1772,  2047,  9149,  9149,  9149,  9149,  8643, 10221, 10221,
   10221, 10221, 10221, -1772, -1772, -1772,  4825,  3039, -1772,  1834,
     983, -1772, 10221, -1772,  6663, 10221,   984,   988, 11458, -1772,
   -1772,   457, -1772,   474, -1772, -1772, -1772, -1772,  1828,  8360,
   -1772, -1772,  1830,  8540, -1772, -1772,  1833,  8580, -1772,  2056,
    2906,   708,  5980, -1772,   995,  1001,  1002,  1015,   499,  1023,
   11484, 11510, 11536, 11562, 11588,  1835,  4692,  1843,  2057,  1838,
   13157,  1030,  8700, -1772, -1772, 10221,  -139,  -139,   923,  2061,
     923,  2062,   923,  2063, -1772, -1772, -1772, -1772,   923,  2064,
    2066,  2067,  2068,  9149,  2070, 10221, 10221, 10221, 10221, 10221,
    2071, -1772, -1772, -1772,  6764, -1772,  1859,  2072,  8816,   510,
     512,   727, -1772,  1889,   846, -1772,  1900,   881, -1772,  1916,
    1022, -1772, -1772, -1772, -1772,  1041, -1772,  3982, 11614, 11640,
   11666, 11692, -1772,  1049, -1772,  1922,  6663, -1772,  2073, 10221,
   10221,  2075,   923,  2076,   923,  2077,   923, -1772,  2078, -1772,
   10221, 10221, 10221, 10221,  6764,  2079,  6764,  1055, -1772,  8892,
    9046, -1772,  1219, -1772,  1294, -1772,  1482, -1772,  9086,  9200,
    9267,  9309, -1772, -1772,  1058, -1772,  2080,  2082,  2095,  2096,
    2101,  2103, -1772, -1772, -1772, -1772,  6764,  2104, -1772, -1772,
   -1772, -1772, -1772, -1772, -1772, -1772
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1772, -1772, -1772, -1772,   811, -1772, -1772, -1772, -1772,   190,
   -1772, -1772, -1772, -1772, -1772, -1772, -1772, -1772, -1772, -1772,
   -1772, -1772,  -445,    12,  4153,  3529, -1772,  1624, -1772, -1772,
   -1772, -1772, -1772, -1772, -1772, -1771, -1772,   337, -1772, -1772,
   -1772, -1772, -1772, -1772,   836,  2146,    20,  -548,  -252, -1772,
   -1772, -1772, -1772, -1772, -1772, -1772, -1772,  2149, -1772, -1772,
   -1772, -1772, -1772, -1772, -1772, -1772, -1772, -1772, -1772, -1772,
   -1772, -1154, -1156,  2151, -1602,  2152, -1772, -1772, -1772,  1621,
   -1772,   355, -1772, -1772, -1772, -1772,  1979, -1772, -1772,    80,
   -1772, -1522,  2774,   235,  2633,   950,  -271,   675, -1772,   134,
      75, -1772,  -416,    -3,   273
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -553
static const yytype_int16 yytable[] =
{
     125,  1380,   700,   210,   702,   552,   732,  1382,   736,   349,
     739,  1751,  1752,   611,   857,   858,  1306,   305,   392,   717,
    1871,   587,  1070,   108,  1371,   235,  1631,   214,   353,  1502,
    1054,   455,   240,  1043,  1271,   360,   640,   240,  1373,   571,
     366,   204,   368,   614,   616,   235,     4,   915,   917,   774,
    1375,   919,   921,   618,   775,   590,   216,  1721,  1993,   560,
     561,  1377,   376,   388,   389,  1218,   308,   560,   561,   310,
     293,   311,   280,   281,   343,  1559,  1148,  1560,   276,   308,
    1513,   209,   282,  1561,  2002,  1562,   231,   560,   561,   283,
     308,     5,  1149,   232,   277,   278,  1148,   560,   561,   212,
    1150,  1151,  1152,   383,  2004,  1361,  1153,  1154,  1155,  1156,
     388,   389,  1149,   852,  1030,   652,  1190,   654,   560,   561,
    1150,  1151,  1152,   662,   213,   738,  1153,  1154,  1155,  1156,
     560,   561,   227,   215,   228,   562,   284,   286,   391,   292,
     208,   560,   561,   388,   389,   218,  1563,   730,  1564,   312,
     294,   225,  1030,  -546,   295,   388,   389,  1801,   563,   734,
     296,   297,   298,   299,   379,  -551,   380,   219,   361,  1372,
     365,  1996,  1997,   381,   612,   483,   300,   484,   220,  1055,
    1056,  1057,  1058,  1374,   381,  1479,   254,   306,  1379,   255,
     456,   457,   256,  1272,  1273,  1376,   560,   561,   778,   308,
    1632,   956,   102,   779,   615,   617,  1378,   960,  1576,   221,
     102,   491,   491,   573,   619,  1030,   633,   222,   634,   491,
     958,   226,   962,   460,  1071,   381,  1380,   308,   102,   343,
    1307,  1071,  1308,   350,   343,   393,   613,   394,   343,   395,
     588,   307,   236,   491,   204,   354,   343,   204,   223,   237,
     343,   343,   343,   343,   491,  1059,   241,  1044,   343,   343,
     343,  1049,   236,   367,  1867,   369,   343,   343,   343,  1048,
     916,   918,   343,   308,   920,   922,   126,   377,   217,   211,
    1994,   224,  1883,  1219,   378,   560,   561,   249,  1031,   560,
     561,   605,  1037,   606,   384,   385,   386,   387,   343,   343,
     343,   850,   851,   233,   499,   384,   385,   386,   387,   560,
     561,   234,   343,   343,   388,   389,   384,   385,   386,   387,
     272,   866,   301,   273,   302,   388,   389,   288,   459,   343,
     289,   343,  1036,   290,  1552,  1553,   388,   389,   384,   385,
     386,   731,   309,   384,   385,   386,   387,   374,   489,   493,
     384,   385,   386,   735,   375,   352,   238,   560,   561,   555,
     556,   388,   389,   388,   389,   574,   362,   564,  1402,   239,
     491,   572,   575,   859,   343,   343,   384,   385,   386,   387,
     519,   896,   315,   897,  2035,   316,   782,   343,   560,   561,
     939,   529,   384,   385,   386,   957,   388,   389,   384,   385,
     386,   961,   242,   231,   865,   948,   384,   385,   386,   387,
    1047,   783,   560,   561,   784,   491,   491,   491,   491,   491,
     491,   491,   491,   491,   491,   343,   491,   491,  1357,   491,
     491,   491,   491,   491,   560,   561,   243,   491,   491,   491,
     491,   491,   308,  1050,   308,    55,    56,    57,    58,   243,
    1381,  1884,  1885,  1148,   280,   281,   250,  1886,   671,    68,
     786,   343,    71,   784,   282,   560,   561,   740,   896,  1149,
     897,   291,  2041,   244,   898,   458,   245,  1150,  1151,  1152,
     792,  1718,   793,  1153,  1154,  1155,  1156,   492,   492,   526,
     527,   528,   246,   560,   561,   492,   533,   534,   535,   343,
     560,   561,   247,   500,   560,   561,   248,   660,  1148,  1814,
     560,   561,   781,   720,  1232,   252,  1816,   782,  1237,   492,
    1818,   728,   251,   896,  1149,   897,  1827,   560,   561,   932,
     492,   253,  1150,  1151,  1152,   257,   583,   584,  1153,  1154,
    1155,  1156,   258,  1828,   343,   343,  1888,  1889,   259,   352,
     596,   597,  1886,   701,   260,   703,   704,   705,   706,   707,
     708,   709,   630,   711,   712,  1959,   714,   715,   716,   264,
     718,   560,   561,   274,   722,   723,   724,   725,   726,   560,
     561,   275,   460,   460,  2127,   560,   561,  1829,   560,   561,
     343,   343,   343,   560,   561,  1830,  1744,  1135,   477,   478,
     479,  1831,   343,   343,  1832,   480,   491,   560,   561,  1958,
     560,   561,   828,   831,   834,   837,   560,   561,   279,  1148,
    1962,   343,  1012,  1961,   388,   389,  1964,   782,   343,   388,
     389,   465,  1973,   303,  -549,  1149,   287,   560,   561,  -550,
     855,   856,   304,  1150,  1151,  1152,   492,   343,   556,  1153,
    1154,  1155,  1156,  1974,   560,   561,   560,   561,   560,   561,
     313,  1897,   655,  1900,   656,  1903,   603,   343,   560,   561,
    1975,   204,  1976,   261,  1977,  1341,   262,  1343,   263,  1345,
     314,  1347,  1301,  1304,  2046,   560,   561,   792,   792,   971,
     317,   492,   492,   492,   492,   492,   492,   492,   492,   492,
     492,  2047,   492,   492,   318,   492,   492,   492,   492,   492,
     560,   561,   346,   492,   492,   492,   492,   492,   727,   319,
     729,   560,   561,   560,   561,   658,  2063,   659,   792,   343,
     798,  1965,   265,   343,   381,   266,   345,  2109,   267,  2110,
     268,  1380,   347,   908,  1380,  1032,   601,  1380,   602,  1038,
     603,   359,   896,   203,   897,   204,   466,   467,   468,   469,
     470,   471,   472,   473,   474,   475,   476,   631,   478,   479,
     388,   389,   343,  1280,   480,   357,   343,   388,   389,   491,
    -548,   348,   308,  1714,   491,   560,   561,  -552,   343,   343,
     466,   467,   468,   469,   470,   471,   472,   473,   474,   475,
     476,   477,   478,   479,   792,   771,   802,   772,   480,   773,
    1610,  1611,   620,  1039,   204,   621,  2021,  1745,   622,   343,
     623,   792,   792,   813,   925,  1148,  1480,   466,   467,   468,
     469,   470,   471,   472,   473,   474,   475,   476,   477,   478,
     479,  1149,  1493,   343,  1148,   480,   358,  1473,  1474,  1150,
    1151,  1152,  1477,  1478,  1781,  1153,  1154,  1155,  1156,  1782,
    1149,   896,   355,   897,  1086,  1380,   995,   356,  1150,  1151,
    1152,   776,   363,   777,  1153,  1154,  1155,  1156,   373,   905,
     381,   421,   492,   475,   476,   477,   478,   479,   269,   422,
     423,   270,   480,   271,  2081,   343,  2084,   343,  2087,   428,
     343,   896,   439,   897,  2090,   435,  1020,   971,   954,   896,
     955,   897,   440,   343,  1022,   343,  1080,   343,  1426,   343,
     792,  1084,  1052,   441,   343,  1380,   442,   445,  1380,   343,
     446,  1380,  1138,   896,  1380,   897,   447,  2056,   792,  1144,
     463,   896,   896,   897,   897,  1159,  1462,  1465,   792,   482,
    1131,   343,   792,   550,  1132,   343,  2111,   464,  2132,   343,
    2134,   481,  2136,  1148,   792,   486,  1177,   491,   792,   508,
    1178,  1233,   792,   513,  1179,  1238,  1380,   524,  1380,  1149,
    1380,  1242,  1244,   792,   792,  1204,  1220,  1150,  1151,  1152,
     547,   523,   343,  1153,  1154,  1155,  1156,   491,  1148,   531,
     553,  1625,   343,   491,   491,   491,   792,  1485,  1240,  1702,
    1703,  1312,   532,  1313,  1149,   491,  1318,   491,  1319,   536,
    1618,  1619,  1150,  1151,  1152,  1622,  1623,   554,  1153,  1154,
    1155,  1156,   792,   792,  1354,  1403,   792,   792,  1404,  1405,
    1148,   308,   565,   566,   343,   343,   343,   343,   792,   792,
    1413,  1414,   792,   537,  1415,   492,  1149,   792,  1082,  1416,
     492,   792,   538,  1418,  1150,  1151,  1152,   567,   589,   491,
    1153,  1154,  1155,  1156,   792,  2113,  1419,  1295,  1296,   471,
     472,   473,   474,   475,   476,   477,   478,   479,   343,   343,
     539,   343,   480,   343,   343,   540,   576,   343,   343,   343,
     343,   343,   343,   630,  1245,  1487,   343,  1488,   343,   792,
    2115,  1489,   466,   467,   468,   469,   470,   471,   472,   473,
     474,   475,   476,   477,   478,   479,   792,   792,  1490,  1491,
     480,   792,  1427,  1492,  1251,   792,  1656,  1535,  1657,  1148,
    1254,  1255,  1256,  1690,   792,  1691,  1730,  1787,   577,  1788,
     591,   792,  1260,  1805,  1261,  1149,   792,  1656,  1806,  1826,
    1656,   578,  1881,  1150,  1151,  1152,  1905,  1311,  1906,  1153,
    1154,  1155,  1156,   792,  1929,  1925,  1930,   592,   782,  1613,
    1933,  1614,   505,  1656,  1462,  1938,  1940,   510,  1465,   579,
    1941,   514,   488,   129,   580,  1242,  1244,  1656,   792,  1946,
    1954,   581,   792,   525,  1972,   593,  1300,   343,   343,   343,
    1787,  1462,  2038,  2043,   582,  1462,  1646,  2044,   586,  1295,
    1296,   381,   792,   343,  2059,  1362,  1363,  1364,   792,   792,
    2060,  2061,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   594,   792,   492,  2062,   169,   170,   171,   172,   595,
     792,  2117,  2064,   174,   175,   176,   598,  1656,   177,  2076,
     491,   491,  1892,   599,   375,   491,   491,   600,   792,   182,
    2118,   632,   636,   492,   770,   308,  2124,   643,  2125,   492,
     492,   492,  1656,  1481,  2146,  2156,   204,  2157,   642,   343,
     648,   492,   649,   492,   650,   651,   653,   466,   467,   468,
     469,   470,   471,   472,   473,   474,   475,   476,   631,   478,
     479,  1016,   669,   343,   670,   480,   673,   352,   677,   343,
     674,     7,     8,   480,   741,   742,   203,   788,   807,   343,
     744,   789,   343,   343,   810,   814,  1148,   343,   343,   815,
     343,   816,   343,   817,   343,   492,   343,   343,   343,   821,
     822,  1860,  1149,   839,   841,   843,   847,   848,   849,  1277,
    1150,  1151,  1152,   876,   878,   343,  1153,  1154,  1155,  1156,
     185,   186,   187,   879,   881,   888,   889,   895,   910,   912,
     343,  1508,   194,   913,   195,   102,   914,   937,   343,   940,
     343,   949,   953,   745,    24,    25,   746,    27,    28,   747,
      30,   748,    32,    33,   966,   967,   388,   389,    35,    36,
      37,  1148,    38,  1243,   751,   998,  -547,    43,    44,    45,
      46,   999,    48,    49,    50,  1000,  1027,  1149,    53,  1003,
    1005,  1006,  1007,   491,   491,  1150,  1151,  1152,   491,   491,
    1017,  1153,  1154,  1155,  1156,  1018,  1026,  1019,  2149,  1024,
    1025,  1028,   491,  1033,  1034,  1041,  1042,  1069,   491,  1090,
    1626,  1575,  1076,  1079,  1081,  1083,  1095,    79,    80,    81,
     466,   467,   468,   469,   470,   471,   472,   473,   474,   475,
     476,   477,   478,   479,   308,  1087,  1091,  1092,   480,  1099,
     343,  1094,  1096,  1097,  1330,  1109,  1100,   844,   845,  1101,
     491,  1102,  1103,   343,  1104,  1612,  1861,   466,   467,   468,
     469,   470,   471,   472,   473,   474,   475,   476,   477,   478,
     479,  1105,  1110,  2150,  1111,   480,  1116,  1118,  1120,  1121,
    1122,  1123,  1141,  1124,  1125,  1126,   492,   492,   884,  1127,
    1134,   492,   492,   885,   886,   887,   343,   343,  1142,  1392,
    1172,   352,  1187,  1195,  1639,   466,   467,   468,   469,   470,
     471,   472,   473,   474,   475,   476,   477,   478,   479,  1189,
    1210,  1211,  1908,   480,   923,  1212,   343,   460,   460,  1213,
    1197,  1664,   343,  1198,  1222,  1199,  1228,  1265,  1225,  1627,
    1226,  1229,  1230,  1234,  1235,  1629,  1669,  1267,  1270,  1148,
     945,  1275,   343,  1626,  1276,  1292,  1278,  1279,  1282,  1432,
    1290,  1291,   343,  1294,  1299,  1149,  1316,  1322,  1323,  1331,
     965,  1332,   343,  1150,  1151,  1152,  1335,   343,  1697,  1153,
    1154,  1155,  1156,  1336,  1339,  1475,  1355,  1661,  1340,  1704,
    1349,  1707,  1350,  1710,  1351,  1352,  1353,  1365,  1368,  1370,
    1369,  1393,  1383,   343,  1384,  1397,  1385,  1386,  1387,  1388,
    1722,  1723,  1724,  1725,  1726,  1728,  1389,  1390,  1391,  1394,
    1395,  1396,  1430,  1398,  1399,  1986,   343,  1400,  1423,  1428,
    1429,  1448,  1431,  1433,  1438,  1440,  1749,  1443,  1445,  1435,
     466,   467,   468,   469,   470,   471,   472,   473,   474,   475,
     476,   477,   478,   479,  1447,  1766,  1769,  1770,   480,   492,
     492,  2151,   343,  1449,   492,   492,  1483,  1484,  1455,  2022,
    1458,  1469,  1501,  1461,   343,  1073,  1482,  1494,   492,  1077,
    1499,  1504,  1500,  1509,   492,  1511,  1510,  1512,  1514,  1520,
    1516,  1515,  1523,  1521,   343,   466,   467,   468,   469,   470,
     471,   472,   473,   474,   475,   476,   477,   478,   479,  1522,
     352,   343,  1524,   480,   491,  1526,  1527,  1528,  1529,  1530,
    1531,  1532,  1533,  1549,   308,  1536,   492,  1539,  1540,  1550,
    1557,  1551,  1558,   343,  1565,  1570,  1571,  1572,  1573,  1591,
     343,   343,  1603,  1604,  1579,  1580,  1133,  1581,  1582,  1583,
    1584,   343,  1588,  1594,   343,   466,   467,   468,   469,   470,
     471,   472,   473,   474,   475,   476,   477,   478,   479,  1593,
     343,  1609,  1616,   480,   343,  1848,  1630,  1615,  1642,  1605,
     460,   466,   467,   468,   469,   470,   471,   472,   473,   474,
     475,   476,   477,   478,   479,  1633,  1636,  1641,  1185,   480,
    1186,  1644,  1647,  1188,  1648,  1649,  1650,  1660,  1665,  1666,
    1670,  1337,  1671,  1672,  1675,  1677,  1200,  1678,  1201,  1679,
    1202,  1680,  1203,  1684,  1681,  1685,  1686,  1206,  1687,  1688,
    1689,  1692,  1209,   343,  1705,  1708,  1711,  1719,  1720,  1715,
    1729,  1733,  1754,  1757,  1896,  1761,  1899,  1750,  1902,  1771,
    1772,  1773,   343,  1774,  1775,  1779,  1777,  1778,  1912,  1913,
    1914,  1915,  1916,   466,   467,   468,   469,   470,   471,   472,
     473,   474,   475,   476,   477,   478,   479,  1780,  1786,   308,
    1789,   480,  1793,  1794,  1566,  1800,  1823,  1803,  1804,  1809,
    1810,  1821,  1812,  1802,  1813,  1250,   466,   467,   468,   469,
     470,   471,   472,   473,   474,   475,   476,   477,   478,   479,
    1815,  1833,  1817,  1819,   480,  1948,  1824,   488,   129,  1952,
     343,   343,   343,   343,   343,  1842,  1847,  1849,  1850,  1851,
    1852,  1853,  1854,  1855,  1856,   206,  1869,  1862,  1875,  1876,
    1877,   343,  1878,  1879,  1880,  1904,  1882,  1283,  1284,  1285,
    1286,  1910,  1928,  1927,  1932,  1926,  1988,   156,   157,   158,
     159,   160,   161,   162,   163,   164,  1934,     7,     8,  1935,
     169,   170,   171,   172,  1944,  1947,  1950,  2001,   174,   175,
     176,  2003,  1951,   177,  1953,  1955,  1967,  1968,  1971,  1984,
     492,  1985,  1620,  2000,   182,  2005,  2007,  2010,  2011,  2014,
     352,  2015,  2018,  2023,  2019,  2037,  2048,  2028,  2050,  1333,
     343,  2052,  2054,  2073,  2070,  2072,  2074,  2082,  2085,  2088,
    2091,   491,  2092,  2093,  2094,  1624,  2096,  2102,  2107,  2128,
     371,  2131,  2133,  2135,  2137,  2143,  2158,  2106,  2159,   745,
      24,    25,   746,    27,    28,   747,    30,   748,    32,    33,
    1732,  2160,  2161,   343,    35,    36,    37,  2162,    38,  2163,
    2165,  2071,  1503,    43,    44,    45,    46,  2112,    48,    49,
      50,   491,   787,   491,    53,  1990,  2079,  2080,  2114,  1872,
     466,   467,   468,   469,   470,   471,   472,   473,   474,   475,
     476,   477,   478,   479,  2116,   185,   186,   187,   480,   107,
    2126,  1518,   117,   491,   118,   119,   824,   194,  1643,   195,
     102,  1890,     0,    79,    80,    81,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   448,   449,   450,   452,   454,
       0,     0,     0,     0,     0,   896,     0,   897,     0,     0,
       0,     0,   487,     0,     0,     0,   494,     0,     0,     0,
       0,     0,     0,     0,     0,  1989,     0,     0,  2104,     0,
     501,   503,   506,   507,     0,   509,   503,   511,   512,     0,
     503,   515,   516,   517,   518,     0,   520,   521,     0,     0,
       0,     0,   503,     0,   946,     0,     0,   530,   466,   467,
     468,   469,   470,   471,   472,   473,   474,   475,   476,   477,
     478,   479,   549,     0,     0,     0,   480,     0,  2142,     0,
    2145,   558,   559,     0,     0,     0,     0,     0,  1776,     0,
     559,   466,   467,   468,   469,   470,   471,   472,   473,   474,
     475,   476,   477,   478,   479,     0,     0,     0,     0,   480,
    2164,     0,     0,     0,     0,     0,   466,   467,   468,   469,
     470,   471,   472,   473,   474,   475,   476,   477,   478,   479,
       0,   625,   627,   503,   480,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   637,   638,   639,     0,   641,
       0,     0,     0,   644,   645,   646,     0,     0,   647,     0,
       0,     0,     0,  1587,     0,     0,     0,   492,     0,     0,
       0,     0,     0,   661,     0,     0,     0,     0,   666,   668,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   675,   676,     0,   678,   679,   680,   681,   682,
     683,   684,   685,   686,   687,   688,   689,   690,   691,   692,
     693,   694,   695,   696,   697,   698,   699,   492,     0,   492,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     713,     0,     0,     0,     0,     0,   719,     0,   721,  1808,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   492,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   750,   503,     0,   752,   753,   754,   755,   756,
     757,   758,   759,   760,   761,   762,   763,   764,   765,   766,
       0,     0,   768,   769,   466,   467,   468,   469,   470,   471,
     472,   473,   474,   475,   476,   477,   478,   479,     0,     0,
       0,   625,   480,     0,     0,     0,     0,   796,     0,     0,
       0,     0,   801,     0,     0,     0,     0,     0,     0,  1693,
    1694,     0,   811,   812,     0,     0,     0,     0,     0,     0,
     819,   820,     0,     0,     0,   825,   827,   830,   833,   836,
     838,     0,   840,     0,   842,     0,   503,   503,   469,   470,
     471,   472,   473,   474,   475,   476,   477,   478,   479,     0,
       0,     0,     0,   480,   860,   861,   862,   448,   449,   863,
       0,     0,     0,   867,   868,   869,   870,   871,   872,   873,
     874,   875,     0,     0,     0,   880,     0,   882,   883,     0,
       0,     0,   503,   503,   503,     0,     0,   890,   891,   892,
     893,   894,     0,     0,   901,   901,   906,   907,     0,   909,
       0,     0,   911,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   503,     0,  1846,     0,     0,     0,   926,
     928,     0,   930,   931,     0,   466,   467,   468,   469,   470,
     471,   472,   473,   474,   475,   476,   477,   478,   479,   503,
       0,     0,     0,   480,   893,   894,     0,   930,   931,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   964,   503,
       0,     0,     0,   968,     0,     0,     0,     0,   127,   370,
       0,     0,     0,     0,   130,   131,   132,     0,     0,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,     0,     0,     0,     0,     0,  1845,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   165,   166,
     167,   168,     0,     0,     0,     0,   173,     0,  1040,     0,
       0,     0,     0,     0,     0,     0,     0,   178,   179,   180,
       0,     0,     0,     0,     0,   181,  1983,   468,   469,   470,
     471,   472,   473,   474,   475,   476,   477,   478,   479,     0,
    1067,  1068,     0,   480,   503,  1074,  1075,  1891,   503,  1078,
       0,     0,     0,     0,     0,     0,     0,  1085,     0,     0,
     928,  1088,     0,     0,     0,     0,     0,  1911,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1106,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1114,   466,   467,   468,   469,   470,   471,   472,   473,   474,
     475,   476,   477,   478,   479,     0,     0,     0,     0,   480,
       0,     0,     0,     0,     0,   503,     0,     0,     0,     0,
       0,     0,  1139,  1140,     0,     0,   184,     0,  1143,     0,
     188,     0,     0,     0,   189,   190,   191,   192,   193,     0,
       0,     0,   102,     0,     0,  1171,     0,     0,  1173,     0,
       0,     0,     0,     0,     0,   504,   196,   197,     0,     0,
     504,   198,     0,     0,   504,     0,   333,   503,     0,   503,
       0,   202,   503,   548,     0,     0,   504,     0,     0,     0,
       0,     0,     0,     0,     0,   503,     0,   503,     0,   503,
       0,   503,     0,     0,     0,     0,   503,     0,     0,     0,
       0,   503,  2055,     0,     0,     0,     0,  1214,     0,  1216,
    1217,     0,     0,  2024,  2025,  2026,  2027,  2029,     0,     0,
    1224,     0,   466,   467,   468,   469,   470,   471,   472,   473,
     474,   475,   476,   477,   478,   479,     0,     0,     0,     0,
     480,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1246,     0,     0,   626,     0,   504,     0,     0,
    1247,  1248,  1249,     0,   503,     0,     0,     0,     0,     0,
       0,     0,  1252,     7,     8,     0,     0,     0,     0,     0,
    1931,   630,     0,     0,     0,     0,  1259,     0,     0,     0,
       0,  1262,     0,     0,     0,     0,     0,     0,     0,     0,
    1266,     0,     0,  2095,     0,     0,  1274,     0,     0,     0,
       0,     0,     0,   522,     0,     0,   503,   503,   503,   503,
       0,     0,  1288,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   542,   544,   546,  2036,     0,     0,   551,
       0,     0,     0,     0,     0,   745,    24,    25,   746,    27,
      28,   747,    30,   748,    32,    33,     0,     0,     0,     0,
      35,    36,    37,     0,    38,     0,     0,   585,     0,    43,
      44,    45,    46,     0,    48,    49,    50,     0,   503,     0,
      53,     0,     0,     0,     0,     0,     0,   504,     0,     0,
    1342,     0,  1344,     0,  1346,     0,  1348,     0,   466,   467,
     468,   469,   470,   471,   472,   473,   474,   475,   476,   477,
     478,   479,     0,     0,     0,     0,   480,     0,  1367,    79,
      80,    81,     0,     0,     0,   626,   466,   467,   468,   469,
     470,   471,   472,   473,   474,   475,   476,   477,   478,   479,
       0,   663,   664,     0,   480,     0,     0,     0,     0,     0,
       0,  1401,     0,  1051,   672,     0,     0,     0,     0,     0,
    1406,  1407,     0,  1408,  1409,     0,  1410,  1411,  1412,     0,
     504,   504,     0,     0,  1417,   466,   467,   468,   469,   470,
     471,   472,   473,   474,   475,   476,   791,   478,   479,     0,
     947,     0,   710,   480,     0,     0,     0,     0,     0,     0,
       0,  1439,     0,     0,     0,     0,  1444,     7,     8,     0,
       0,     0,     0,     0,     0,     0,   504,   504,   504,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   902,   904,
       0,   466,   467,   468,   469,   470,   471,   472,   473,   474,
     475,   476,   477,   478,   479,     0,     0,   504,  1486,   480,
       0,     0,     0,     0,   929,     0,     0,     0,     0,  1495,
    1496,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   504,  1505,  1507,     0,     0,     0,   745,
      24,    25,   746,    27,    28,   747,    30,   748,    32,    33,
       0,     0,     0,   504,    35,    36,    37,     0,    38,     0,
       0,     0,     0,    43,    44,    45,    46,     0,    48,    49,
      50,     0,     0,     0,    53,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1554,  1555,  1556,     0,
       0,     7,     8,     0,     0,     0,     0,  1567,     0,  1569,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1574,     0,     0,    79,    80,    81,     0,     0,     0,     0,
       0,     0,   503,     0,     0,     0,     0,  1589,     0,   466,
     467,   468,   469,   470,   471,   472,   473,   474,   475,   476,
     477,   478,   479,     0,     0,     0,     0,   480,     0,     0,
       0,     0,     0,  1606,  1607,  1608,  1108,     0,   504,   360,
     129,     0,   504,   745,    24,    25,   746,    27,    28,   747,
      30,   748,    32,    33,   929,  1089,     0,     0,    35,    36,
      37,     0,    38,     0,  1136,  1628,     0,    43,    44,    45,
      46,     0,    48,    49,    50,     0,     0,     0,    53,   156,
     157,   158,   159,   160,   161,   162,   163,   164,     0,  1640,
       0,     0,   169,   170,   171,   172,     0,     0,     0,     0,
     174,   175,   176,  1653,     0,   177,     0,     0,  1659,   504,
       0,     0,     0,     0,     0,     0,   182,    79,    80,    81,
       0,     0,     0,  1667,  1668,     0,     0,     0,     0,     0,
    1673,  1674,     0,     0,     0,  1676,  1029,     0,     0,     0,
    1035,     0,     0,     0,     0,     0,     0,     0,  1683,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   503,   503,
    1695,   504,  1696,   504,     0,     0,   504,     0,     0,     0,
       0,     0,     0,     0,  1713,     0,     0,     0,     0,   504,
     630,   504,     0,   504,     0,   504,     0,     0,  1137,     0,
     504,     0,     0,     0,   503,   504,     0,  1731,     0,     0,
       7,     8,     0,     0,  1734,  1735,  1736,  1737,  1738,  1739,
    1740,     0,     0,     0,     0,     0,     0,   185,   186,   187,
    1748,     0,     0,     0,     0,     0,  1115,     0,     0,   194,
       0,   195,   102,     0,     0,     0,     0,     0,     0,     0,
    1768,     0,     7,     8,   466,   467,   468,   469,   470,   471,
     472,   473,   474,   475,   476,   477,   478,   479,   504,     0,
       0,     0,   480,  1783,  1784,     0,   941,     0,     0,     0,
     657,  1790,   745,    24,    25,   746,    27,    28,   747,    30,
     748,    32,    33,     0,     0,     0,     0,    35,    36,    37,
       0,    38,     0,     0,     0,     0,    43,    44,    45,    46,
       0,    48,    49,    50,     0,     0,     0,    53,     0,  1811,
     504,   504,   504,   504,   745,    24,    25,   746,    27,    28,
     747,    30,   748,    32,    33,  1053,     0,  1825,     0,    35,
      36,    37,     0,    38,     0,     0,   625,     0,    43,    44,
      45,    46,     0,    48,    49,    50,    79,    80,    81,    53,
       0,  1843,     0,  1844,     0,     0,   503,     0,  1227,     0,
       0,     0,  1231,     0,     0,     0,  1236,     0,     0,     0,
       0,     0,   504,  1858,   466,   467,   468,   469,   470,   471,
     472,   473,   474,   475,   476,   791,   478,   479,    79,    80,
      81,  1864,   480,     0,     0,     0,  1868,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1253,
       0,     0,     0,     0,     0,     0,   503,  1160,     0,     0,
       0,     0,     0,  1895,     0,  1898,     0,  1901,     0,     0,
       0,     0,     0,     0,     0,     0,   503,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1917,  1918,  1919,  1920,
    1921,  1922,     0,     0,     0,     0,     0,     0,     0,  1215,
     466,   467,   468,   469,   470,   471,   472,   473,   474,   475,
     476,   477,   478,   479,  1936,  1937,     0,     0,   480,  1939,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1945,     0,     0,     0,  1314,  1315,     0,  1317,     0,
    1320,  1321,  1956,  1205,  1324,  1325,  1326,  1327,  1328,  1329,
       0,     0,     0,     0,     0,  1334,     0,     0,     0,   466,
     467,   468,   469,   470,   471,   472,   473,   474,   475,   476,
     477,   478,   479,     0,     0,     0,     0,   480,  1987,     0,
       0,     0,     0,     0,  1659,     7,     8,     0,     0,     0,
       0,     0,     0,  1998,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2009,     0,     0,
    2013,     0,     0,  2017,     0,     0,     0,  2020,     0,  1425,
       0,     0,   503,   503,   503,   503,   503,  2030,  2031,  2032,
    2033,  2034,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2040,     0,     0,  2042,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1420,  1421,  1422,   745,    24,    25,
     746,    27,    28,   747,    30,   748,    32,    33,     0,     0,
    1434,     0,    35,    36,    37,     0,    38,     0,     0,     0,
       0,    43,    44,    45,    46,     0,    48,    49,    50,     0,
       0,     0,    53,     0,  2078,     0,   504,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   503,     0,  2097,  2098,  2099,  2100,  2101,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    79,    80,    81,     0,     0,  1498,   466,   467,   468,
     469,   470,   471,   472,   473,   474,   475,   476,   477,   478,
     479,     0,     0,     0,     0,   480,     0,     0,  2129,  2130,
    1519,     0,     0,     0,     0,     0,  1525,     0,     0,  2138,
    2139,  2140,  2141,     0,     0,     0,  1534,     0,     0,  1537,
    1538,     0,     0,     0,  1541,  1542,     0,  1543,     0,  1544,
       0,  1545,     0,  1546,  1547,  1548,     0,     0,     0,     0,
       0,     0,  1221,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1568,   466,   467,   468,   469,   470,   471,   472,
     473,   474,   475,   476,   477,   478,   479,  1578,     0,     0,
       0,   480,     0,     0,   933,  1586,     0,     0,     0,     0,
       0,     0,     0,     0,   229,   230,     0,     0,     0,     0,
       0,     0,   504,   504,   466,   467,   468,   469,   470,   471,
     472,   473,   474,   475,   476,   477,   478,   479,     0,     0,
       0,     0,   480,     0,   896,     0,   897,   972,   973,   974,
     975,   976,   977,   978,   979,   980,   981,   982,   504,   984,
     985,   986,   987,   988,   989,   990,     0,     0,     0,   994,
     996,   997,     0,     0,     0,  1001,  1002,     0,  1004,     0,
       0,     0,     0,  1009,  1010,  1011,     0,  1013,     0,     0,
       0,     0,     0,     0,  1021,  1023,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1651,     0,     0,
       7,     8,  1046,     0,     0,     0,     0,     0,   382,     0,
    1663,     0,     0,     0,     0,     0,     0,   396,   397,   398,
     399,   400,   401,   402,   403,   404,   405,   406,   407,   408,
     409,   410,   411,   412,   413,   414,   415,   416,   417,   418,
     419,   420,     0,     0,     0,   424,   425,   426,   427,     0,
     429,   430,   431,   432,   433,   434,     0,     0,   436,     0,
       0,     0,     0,     0,   437,   438,     0,     0,     0,     0,
     443,   444,   745,    24,    25,   746,    27,    28,   747,    30,
     748,    32,    33,  1498,     0,     0,     0,    35,    36,    37,
     626,    38,     0,     0,     0,     0,    43,    44,    45,    46,
       0,    48,    49,    50,     0,     0,     0,    53,     0,  1741,
     504,     0,     0,     0,     0,     0,     0,     0,     0,  1753,
       0,     0,     0,     0,     0,     0,     0,  1859,     0,  1760,
       0,     0,     0,     0,  1765,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    79,    80,    81,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1785,     0,     0,     0,     0,     0,     0,  1193,     0,     0,
     504,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1498,     0,     0,     0,     0,     0,     0,
     504,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   604,     0,     0,   607,   608,   609,   610,
       0,     0,     0,     0,     0,     0,     0,  1356,     0,  1822,
       0,     0,     0,     0,     0,     0,   635,     0,     0,     0,
       0,     0,     0,     0,     0,   127,   320,     0,     0,     0,
       0,   130,   131,   132,     0,     0,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   322,
     323,   324,   325,   326,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   165,   166,   167,   168,     0,
    1498,     0,     0,   173,     0,     0,     0,  1873,  1874,     0,
       0,     0,     0,     0,   178,   179,   180,     0,  1498,     0,
       0,  1287,   181,     0,     0,     0,   327,     0,     0,   328,
       0,     0,   329,     0,   330,     0,     0,  1907,     0,     0,
      34,     0,     0,     0,     0,     0,   504,   504,   504,   504,
     504,   743,     0,     0,  1309,  1310,   331,     0,     0,     0,
       0,     0,     0,    55,    56,    57,    58,    59,     0,     0,
      61,    62,    63,    64,    65,     0,     0,    68,     0,     0,
      71,   466,   467,   468,   469,   470,   471,   472,   473,   474,
     475,   476,   477,   478,   479,     0,     0,     0,     0,   480,
    1949,     0,     0,     0,     0,     0,  1700,     0,  1701,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1966,
       0,     0,     0,   184,     0,     0,     0,   188,     0,     0,
       0,   189,   190,   191,   192,   193,   504,   129,     0,   102,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   568,  1727,     0,     0,     0,   198,     0,
       0,     0,     0,   570,     0,     0,     0,     0,   202,     0,
     283,   628,     0,     0,     0,     0,   156,   157,   158,   159,
     160,   161,   162,   163,   164,     0,     0,     0,     0,   169,
     170,   171,   172,     0,     0,     0,     0,   174,   175,   176,
       0,     0,   177,     0,     0,     0,     0,     0,  1498,  1446,
       0,     0,     0,   182,     0,  1450,  1451,  1452,  1453,  1454,
       0,  1457,     0,  1459,  1460,     0,  1463,  1466,     0,     0,
    1470,  1471,  1472,     0,     0,     0,     0,  1476,     0,     0,
     127,   128,   129,     0,     0,     0,   130,   131,   132,     0,
       0,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,     0,     0,     0,     7,     8,     0,
       0,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,     0,
       0,     0,   174,   175,   176,     0,     0,   177,     0,   178,
     179,   180,     0,     0,   185,   186,   187,   181,   182,     0,
    1498,     0,     0,     0,     0,     0,   194,     0,   195,   466,
     467,   468,   469,   470,   471,   472,   473,   474,   475,   476,
     477,   478,   479,     0,     0,     0,     0,   480,     0,   745,
      24,    25,   746,    27,    28,   747,    30,   748,    32,    33,
       0,     0,     0,     0,    35,    36,    37,     0,    38,     0,
       0,     0,  1592,    43,    44,    45,    46,     0,    48,    49,
      50,     0,     0,     0,    53,     0,     0,     0,  1602,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   951,     0,     0,     0,  1617,     0,     0,     0,     0,
    1621,   183,     0,     0,     0,     0,     0,     0,   184,   185,
     186,   187,   188,    79,    80,    81,   189,   190,   191,   192,
     193,   194,     0,   195,   102,     0,     0,     0,     0,     0,
       0,     0,  1634,  1635,     0,     0,  1637,  1638,   196,   197,
       0,     0,     0,   198,     0,     0,     0,     0,   199,     0,
     200,     0,   201,   202,     0,   203,     0,   204,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   127,   320,     0,     0,     0,     0,   130,   131,
     132,     0,     0,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   322,   323,   324,   325,
     326,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   165,   166,   167,   168,     0,     0,     0,     0,
     173,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   178,   179,   180,     0,     0,     0,     0,     0,   181,
       0,     0,     0,   327,     0,     0,   328,     0,     0,   329,
       0,   330,     0,     0,     0,     0,     0,    34,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1755,  1756,     0,
       0,  1758,  1759,   331,     0,     0,     0,  1762,  1763,     0,
      55,    56,    57,    58,    59,     0,     0,    61,    62,    63,
      64,    65,     0,     0,    68,     0,     0,    71,     0,     0,
    1263,  1264,     0,     0,     0,     0,  1268,  1269,   466,   467,
     468,   469,   470,   471,   472,   473,   474,   475,   476,   477,
     478,   479,     0,     0,     0,     0,   480,     0,     0,     0,
       0,     0,     0,  1742,     0,  1743,     0,     0,     0,     0,
     184,     0,     0,     0,   188,     0,     0,     0,   189,   190,
     191,   192,   193,     0,     0,     0,   102,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     196,   502,     0,     0,     0,   198,     0,     0,     0,     0,
     333,     0,     0,  1835,  1836,   202,     0,     0,   628,     0,
       0,     0,     0,   127,   320,   129,     0,     0,     0,   130,
     131,   132,     0,     0,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   322,   323,   324,
     325,   326,     0,     0,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,     0,     0,     0,   174,   175,   176,     0,     0,
     177,     0,   178,   179,   180,     0,     0,     0,     0,     0,
     181,   182,     0,     0,   327,     0,     0,   328,     0,     0,
     329,     0,   330,     0,     0,     0,     0,     0,    34,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1436,  1437,   331,     0,     0,  1441,  1442,     0,
       0,    55,    56,    57,    58,    59,     0,     0,    61,    62,
      63,    64,    65,     0,     0,    68,     0,     0,    71,   466,
     467,   468,   469,   470,   471,   472,   473,   474,   475,   476,
     477,   478,   479,     0,     0,     0,     0,   480,     0,     0,
       0,     0,     0,     0,  1893,     0,  1894,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   184,   185,   186,   187,   188,     0,     0,     0,   189,
     190,   191,   192,   193,   194,     0,   195,   102,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   196,   332,     0,     0,     0,   198,     0,     0,     0,
       0,   333,     0,   127,   320,   129,   202,     0,   334,   130,
     131,   132,     0,     0,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   322,   323,   324,
     325,   326,     0,     0,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,     0,     0,     0,   174,   175,   176,     0,     0,
     177,     0,   178,   179,   180,     0,     0,     0,     0,     0,
     181,   182,     0,     0,   327,     0,     0,   328,     0,     0,
     329,     0,   330,     0,     0,     0,     0,     0,    34,   364,
     129,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   331,     0,     0,     0,     0,     0,
       0,    55,    56,    57,    58,    59,     0,     0,    61,    62,
      63,    64,    65,     0,     0,    68,  2119,     0,    71,   156,
     157,   158,   159,   160,   161,   162,   163,   164,     0,     0,
       0,     0,   169,   170,   171,   172,     0,     0,     0,     0,
     174,   175,   176,     0,     0,   177,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   182,     0,     0,     0,
       0,   184,   185,   186,   187,   188,     0,     0,     0,   189,
     190,   191,   192,   193,   194,     0,   195,   102,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   196,   332,     0,     0,     0,   198,     0,     0,     0,
       0,   333,     0,   127,   320,   321,   202,     0,  1764,   130,
     131,   132,     0,     0,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   322,   323,   324,
     325,   326,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   165,   166,   167,   168,   185,   186,   187,
       0,   173,     0,     0,     0,     0,     0,     7,     8,   194,
       0,   195,   178,   179,   180,     0,     0,     0,     0,     0,
     181,     0,     0,     0,   327,     0,     0,   328,     0,     0,
     329,     0,   330,     0,     0,     0,     0,     0,    34,   466,
     467,   468,   469,   470,   471,   472,   473,   474,   475,   476,
     477,   478,   479,     0,   331,     0,     0,   480,     0,     0,
       0,    55,    56,    57,    58,    59,  1163,     0,    61,    62,
      63,    64,    65,     0,     0,    68,     0,     0,    71,   745,
      24,    25,   746,    27,    28,   747,    30,   748,    32,    33,
       0,     0,     0,     0,    35,    36,    37,     0,    38,     0,
       0,     0,     0,    43,    44,    45,    46,     0,    48,    49,
      50,     0,     0,     0,    53,     0,     0,     0,     0,     0,
       0,   184,     0,     0,     0,   188,     0,     0,     0,   189,
     190,   191,   192,   193,     0,     0,     0,   102,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   196,   332,    79,    80,    81,   198,     0,     0,     0,
       0,   333,     0,   127,   370,   129,   202,     0,   334,   130,
     131,   132,     0,     0,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,     0,     0,     0,
       0,     0,     0,     0,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,     7,     8,  1969,   174,   175,   176,     0,     0,
     177,     0,   178,   179,   180,     0,     0,     0,     0,     0,
     181,   182,   466,   467,   468,   469,   470,   471,   472,   473,
     474,   475,   476,   477,   478,   479,     0,     0,     0,     0,
     480,     0,     0,     0,     0,     0,     0,     0,     0,  1196,
     466,   467,   468,   469,   470,   471,   472,   473,   474,   475,
     476,   477,   478,   479,     0,     0,     0,     0,   480,     0,
       0,     0,   737,     0,   745,    24,    25,   746,    27,    28,
     747,    30,   748,    32,    33,     0,     0,     0,     0,    35,
      36,    37,     0,    38,     0,     0,     0,     0,    43,    44,
      45,    46,     0,    48,    49,    50,     0,     0,     0,    53,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   184,   185,   186,   187,   188,     0,     0,     0,   189,
     190,   191,   192,   193,   194,     0,   195,   102,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    79,    80,
      81,   196,   197,     0,     0,     0,   198,     0,     0,     0,
       0,   333,     0,   127,   320,  1577,   202,     0,  1506,   130,
     131,   132,     0,     0,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   322,   323,   324,
     325,   326,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   165,   166,   167,   168,     0,     0,  2057,
       0,   173,     0,     0,     0,     0,     0,     7,     8,     0,
       0,     0,   178,   179,   180,     0,     0,     0,     0,     0,
     181,     0,     0,     0,   327,     0,     0,   328,     0,     0,
     329,     0,   330,     0,     0,     0,     0,     0,    34,   466,
     467,   468,   469,   470,   471,   472,   473,   474,   475,   476,
     477,   478,   479,     0,   331,     0,     0,   480,     0,     0,
       0,    55,    56,    57,    58,    59,  1239,     0,    61,    62,
      63,    64,    65,     0,     0,    68,     0,     0,    71,   745,
      24,    25,   746,    27,    28,   747,    30,   748,    32,    33,
       0,     0,     0,     0,    35,    36,    37,     0,    38,     0,
       0,     0,     0,    43,    44,    45,    46,     0,    48,    49,
      50,     0,     0,     0,    53,     0,     0,     0,     0,     0,
       0,   184,     0,     0,     0,   188,     0,     0,     0,   189,
     190,   191,   192,   193,     0,     0,     0,   102,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   196,   332,    79,    80,    81,   198,     0,     0,     0,
       0,   333,     0,   127,   370,   129,   202,     0,   334,   130,
     131,   132,     0,     0,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,     0,     0,     0,
       0,     0,     0,     0,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,     0,     0,     0,   174,   175,   176,     0,     0,
     177,     0,   178,   179,   180,     0,   127,   370,   129,     0,
     181,   182,   130,   131,   132,     0,     0,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
       0,     0,     0,     0,     0,     0,     0,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,     0,     0,     0,   174,   175,
     176,     0,     0,   177,     0,   178,   179,   180,     0,     0,
       0,     0,     0,   181,   182,     0,     0,     0,     0,   466,
     467,   468,   469,   470,   471,   472,   473,   474,   475,   476,
     477,   478,   479,     0,     0,     0,     0,   480,     0,     0,
       0,   184,   185,   186,   187,   188,  1360,     0,     0,   189,
     190,   191,   192,   193,   194,     0,   195,   102,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   196,   197,     0,     0,     0,   198,     0,     0,     0,
       0,   333,     0,     0,     0,     0,   202,     0,  1747,     0,
       0,     0,   466,   467,   468,   469,   470,   471,   472,   473,
     474,   475,   476,   477,   478,   479,     0,     0,     0,     0,
     480,     0,     0,     0,   184,   185,   186,   187,   188,  1698,
       0,     0,   189,   190,   191,   192,   193,   194,     0,   195,
     102,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   196,   197,     0,     0,     0,   198,
       0,     0,     0,     0,   333,     0,   127,   320,     0,   202,
       0,  1767,   130,   131,   132,     0,     0,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     322,   323,   324,   325,   326,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   165,   166,   167,   168,
       0,     0,     0,     0,   173,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   178,   179,   180,     0,     0,
       0,     0,     0,   181,     0,     0,     0,   327,     0,     0,
     328,     0,     0,   329,     0,   330,     0,     0,     0,     0,
       0,    34,     0,     0,     0,     0,     0,     0,   488,   129,
       0,     0,     0,     0,     0,     0,     0,   331,     0,     0,
       0,     0,     0,     0,    55,    56,    57,    58,    59,     0,
       0,    61,    62,    63,    64,    65,     0,     0,    68,     0,
       0,    71,     0,     0,     0,     0,     0,     0,   156,   157,
     158,   159,   160,   161,   162,   163,   164,     0,     0,     0,
       0,   169,   170,   171,   172,     0,     0,     0,     0,   174,
     175,   176,     0,     0,   177,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   184,   182,     0,     0,   188,     0,
       0,     0,   189,   190,   191,   192,   193,     0,     0,     0,
     102,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   196,   332,     0,     0,     0,   198,
       0,     0,     0,     0,   333,     0,   127,   320,     0,   202,
       0,   334,   130,   131,   132,     0,     0,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     322,   323,   324,   325,   326,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   165,   166,   167,   168,
       0,     0,     0,     0,   173,     0,   185,   186,   187,     0,
       0,     0,     0,     0,     0,   178,   179,   180,   194,     0,
     195,   102,     0,   181,     0,     0,     0,   327,     0,     0,
     328,     0,     0,   329,     0,   330,     0,     0,     0,     0,
       0,    34,   466,   467,   468,   469,   470,   471,   472,   473,
     474,   475,   476,   477,   478,   479,     0,   331,     0,     0,
     480,     0,     0,     0,    55,    56,    57,    58,    59,  1717,
       0,    61,    62,    63,    64,    65,     0,     0,    68,     0,
       0,    71,   466,   467,   468,   469,   470,   471,   472,   473,
     474,   475,   476,   477,   478,   479,     0,     0,     0,     0,
     480,     0,     0,     0,     0,     0,     0,     0,     0,  1795,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   184,     0,     0,     0,   188,     0,
       0,     0,   189,   190,   191,   192,   193,     0,     0,     0,
     102,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   196,   332,     0,     0,     0,   198,
       0,     0,     0,     0,   541,     0,   127,   320,     0,   202,
       0,   334,   130,   131,   132,     0,     0,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     322,   323,   324,   325,   326,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   165,   166,   167,   168,
       0,     0,     0,     0,   173,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   178,   179,   180,     0,     0,
       0,     0,     0,   181,     0,     0,     0,   327,     0,     0,
     328,     0,     0,   329,     0,   330,     0,     0,     0,     0,
       0,    34,   466,   467,   468,   469,   470,   471,   472,   473,
     474,   475,   476,   477,   478,   479,     0,   331,     0,     0,
     480,     0,     0,     0,    55,    56,    57,    58,    59,  1796,
       0,    61,    62,    63,    64,    65,     0,     0,    68,     0,
       0,    71,   466,   467,   468,   469,   470,   471,   472,   473,
     474,   475,   476,   477,   478,   479,     0,     0,     0,     0,
     480,     0,     0,     0,     0,     0,     0,     0,     0,  1797,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   184,     0,     0,     0,   188,     0,
       0,     0,   189,   190,   191,   192,   193,     0,     0,     0,
     102,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   196,   332,     0,     0,     0,   198,
       0,     0,     0,     0,   543,     0,   127,   320,     0,   202,
       0,   334,   130,   131,   132,     0,     0,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     322,   323,   324,   325,   326,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   165,   166,   167,   168,
       0,     0,     0,     0,   173,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   178,   179,   180,     0,     0,
       0,     0,     0,   181,     0,     0,     0,   327,     0,     0,
     328,     0,     0,   329,     0,   330,     0,     0,     0,     0,
       0,    34,   466,   467,   468,   469,   470,   471,   472,   473,
     474,   475,   476,   477,   478,   479,     0,   331,     0,     0,
     480,     0,     0,     0,    55,    56,    57,    58,    59,  1798,
       0,    61,    62,    63,    64,    65,     0,     0,    68,     0,
       0,    71,   466,   467,   468,   469,   470,   471,   472,   473,
     474,   475,   476,   477,   478,   479,     0,     0,     0,     0,
     480,     0,     0,     0,     0,     0,     0,     0,     0,  1799,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   184,     0,     0,     0,   188,     0,
       0,     0,   189,   190,   191,   192,   193,     0,     0,     0,
     102,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   196,   332,     0,     0,     0,   198,
       0,     0,     0,     0,   545,     0,   127,   320,     0,   202,
       0,   334,   130,   131,   132,     0,     0,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     322,   323,   324,   325,   326,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   165,   166,   167,   168,
       0,     0,     0,     0,   173,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   178,   179,   180,     0,     0,
       0,     0,     0,   181,     0,     0,     0,   327,     0,     0,
     328,     0,     0,   329,     0,   330,     0,     0,     0,     0,
       0,    34,   466,   467,   468,   469,   470,   471,   472,   473,
     474,   475,   476,   477,   478,   479,     0,   331,     0,     0,
     480,     0,     0,     0,    55,    56,    57,    58,    59,  1834,
       0,    61,    62,    63,    64,    65,     0,     0,    68,     0,
       0,    71,   466,   467,   468,   469,   470,   471,   472,   473,
     474,   475,   476,   477,   478,   479,     0,     0,     0,     0,
     480,     0,     0,     0,     0,     0,     0,     0,     0,  1909,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   184,     0,     0,     0,   188,     0,
       0,     0,   189,   190,   191,   192,   193,     0,     0,     0,
     102,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   196,   502,     0,     0,     0,   198,
       0,     0,     0,     0,   333,     0,   127,   320,     0,   202,
       0,   624,   130,   131,   132,     0,     0,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     322,   323,   324,   325,   326,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   165,   166,   167,   168,
       0,     0,     0,     0,   173,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   178,   179,   180,     0,     0,
       0,     0,     0,   181,     0,     0,     0,   327,     0,     0,
     328,     0,     0,   329,     0,   330,     0,     0,     0,     0,
       0,    34,   466,   467,   468,   469,   470,   471,   472,   473,
     474,   475,   476,   477,   478,   479,     0,   331,     0,     0,
     480,     0,     0,     0,    55,    56,    57,    58,    59,  1923,
       0,    61,    62,    63,    64,    65,     0,     0,    68,     0,
       0,    71,   466,   467,   468,   469,   470,   471,   472,   473,
     474,   475,   476,   477,   478,   479,     0,     0,     0,     0,
     480,     0,     0,     0,     0,     0,     0,     0,     0,  1924,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   184,     0,     0,     0,   188,     0,
       0,     0,   189,   190,   191,   192,   193,     0,     0,     0,
     102,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   196,   502,     0,     0,     0,   198,
       0,     0,     0,     0,   333,     0,   127,   320,     0,   202,
       0,   900,   130,   131,   132,     0,     0,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     322,   323,   324,   325,   326,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   165,   166,   167,   168,
       0,     0,     0,     0,   173,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   178,   179,   180,     0,     0,
       0,     0,     0,   181,     0,     0,     0,   327,     0,     0,
     328,     0,     0,   329,     0,   330,     0,     0,     0,     0,
       0,    34,   466,   467,   468,   469,   470,   471,   472,   473,
     474,   475,   476,   477,   478,   479,     0,   331,     0,     0,
     480,     0,     0,     0,    55,    56,    57,    58,    59,  1957,
       0,    61,    62,    63,    64,    65,     0,     0,    68,     0,
       0,    71,   466,   467,   468,   469,   470,   471,   472,   473,
     474,   475,   476,   477,   478,   479,     0,     0,     0,     0,
     480,     0,     0,     0,     0,     0,     0,     0,     0,  1960,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   184,     0,     0,     0,   188,     0,
       0,     0,   189,   190,   191,   192,   193,     0,     0,     0,
     102,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   196,   502,     0,     0,     0,   198,
       0,     0,     0,     0,   333,     0,   127,   320,     0,   202,
       0,   903,   130,   131,   132,     0,     0,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     322,   323,   324,   325,   326,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   165,   166,   167,   168,
       0,     0,     0,     0,   173,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   178,   179,   180,     0,     0,
       0,     0,     0,   181,     0,     0,     0,   327,     0,     0,
     328,     0,     0,   329,     0,   330,     0,     0,     0,     0,
       0,    34,   466,   467,   468,   469,   470,   471,   472,   473,
     474,   475,   476,   477,   478,   479,     0,   331,     0,     0,
     480,     0,     0,     0,    55,    56,    57,    58,    59,  1963,
       0,    61,    62,    63,    64,    65,     0,     0,    68,     0,
       0,    71,   466,   467,   468,   469,   470,   471,   472,   473,
     474,   475,   476,   477,   478,   479,     0,     0,     0,     0,
     480,     0,     0,     0,     0,     0,     0,     0,     0,  1999,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   184,     0,     0,     0,   188,     0,
       0,     0,   189,   190,   191,   192,   193,     0,     0,     0,
     102,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   196,   502,     0,     0,     0,   198,
       0,     0,     0,     0,   333,     0,   127,   320,     0,   202,
       0,   927,   130,   131,   132,     0,     0,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     322,   323,   324,   325,   326,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   165,   166,   167,   168,
       0,     0,     0,     0,   173,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   178,   179,   180,     0,     0,
       0,     0,     0,   181,     0,     0,     0,   327,     0,     0,
     328,     0,     0,   329,     0,   330,     0,     0,     0,     0,
       0,    34,   466,   467,   468,   469,   470,   471,   472,   473,
     474,   475,   476,   477,   478,   479,     0,   331,     0,     0,
     480,     0,     0,     0,    55,    56,    57,    58,    59,  2006,
       0,    61,    62,    63,    64,    65,     0,     0,    68,     0,
       0,    71,   466,   467,   468,   469,   470,   471,   472,   473,
     474,   475,   476,   477,   478,   479,     0,     0,     0,     0,
     480,     0,     0,     0,     0,     0,     0,     0,     0,  2049,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   184,     0,     0,     0,   188,     0,
       0,     0,   189,   190,   191,   192,   193,     0,     0,     0,
     102,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   196,   332,     0,     0,     0,   198,
       0,     0,     0,     0,   333,     0,   127,   320,     0,   202,
       0,  1585,   130,   131,   132,     0,     0,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     322,   323,   324,   325,   326,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   165,   166,   167,   168,
       0,     0,     0,     0,   173,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   178,   179,   180,     0,     0,
       0,     0,     0,   181,     0,     0,     0,   327,     0,     0,
     328,     0,     0,   329,     0,   330,     0,     0,     0,     0,
       0,    34,   466,   467,   468,   469,   470,   471,   472,   473,
     474,   475,   476,   477,   478,   479,     0,   331,     0,     0,
     480,     0,     0,     0,    55,    56,    57,    58,    59,  2051,
       0,    61,    62,    63,    64,    65,     0,     0,    68,     0,
       0,    71,   466,   467,   468,   469,   470,   471,   472,   473,
     474,   475,   476,   477,   478,   479,     0,     0,     0,     0,
     480,     0,     0,     0,     0,     0,     0,     0,     0,  2053,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   184,     0,     0,     0,   188,     0,
       0,     0,   189,   190,   191,   192,   193,     0,     0,     0,
     102,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   568,  1727,     0,     0,     0,   198,
       0,     0,     0,     0,   570,     0,   127,   370,     0,   202,
       0,   283,   130,   131,   132,     0,     0,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
       0,     0,   466,   467,   468,   469,   470,   471,   472,   473,
     474,   475,   476,   477,   478,   479,   165,   166,   167,   168,
     480,     0,     0,     0,   173,     0,     0,     0,     0,  2077,
       0,     0,     0,     0,     0,   178,   179,   180,   127,   370,
     129,     0,     0,   181,   130,   131,   132,     0,     0,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,     0,     0,     0,     0,     0,     0,     0,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,     0,     0,     0,
     174,   175,   176,     0,     0,   177,     0,   178,   179,   180,
       0,     0,     0,     0,     0,   181,   182,     0,   466,   467,
     468,   469,   470,   471,   472,   473,   474,   475,   476,   477,
     478,   479,     0,     0,     0,     0,   480,     0,     0,     0,
       0,     0,     0,     0,   184,  2108,     0,     0,   188,     0,
       0,     0,   189,   190,   191,   192,   193,     0,     0,     0,
     102,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   568,   569,     0,     0,     0,   198,
       0,     0,     0,     0,   570,     0,     0,     0,     0,   202,
       0,   283,     0,     0,   466,   467,   468,   469,   470,   471,
     472,   473,   474,   475,   476,   477,   478,   479,     0,     0,
       0,     0,   480,     0,     0,     0,   184,   185,   186,   187,
     188,  2147,     0,     0,   189,   190,   191,   192,   193,   194,
       0,   195,   102,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   196,   197,     0,     0,
       0,   198,   127,   320,     0,     0,   333,     0,   130,   131,
     132,   202,     0,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   322,   323,   324,   325,
     326,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   165,   166,   167,   168,     0,     0,     0,     0,
     173,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   178,   179,   180,     0,     0,     0,     0,     0,   181,
       0,     0,     0,   327,     0,     0,   328,     0,     0,   329,
       0,   330,     0,     0,     0,     0,     0,    34,   466,   467,
     468,   469,   470,   471,   472,   473,   474,   475,   476,   477,
     478,   479,     0,   331,     0,     0,   480,     0,     0,     0,
      55,    56,    57,    58,    59,  2148,     0,    61,    62,    63,
      64,    65,     0,     0,    68,     0,     0,    71,   466,   467,
     468,   469,   470,   471,   472,   473,   474,   475,   476,   477,
     478,   479,     0,     0,     0,     0,   480,     0,     0,     0,
       0,     0,     0,     0,     0,  2152,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     184,     0,     0,     0,   188,     0,     0,     0,   189,   190,
     191,   192,   193,     0,     0,     0,   102,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     196,   502,     0,     0,     0,   198,   127,   370,     0,     0,
     333,     0,   130,   131,   132,   202,     0,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
       0,     0,   466,   467,   468,   469,   470,   471,   472,   473,
     474,   475,   476,   477,   478,   479,   165,   166,   167,   168,
     480,     0,     0,     0,   173,     0,     0,     0,     0,  2153,
       0,     0,     0,   127,   370,   178,   179,   180,     0,   130,
     131,   132,     0,   181,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,     0,     0,   466,
     467,   468,   469,   470,   471,   472,   473,   474,   475,   476,
     477,   478,   479,   165,   166,   167,   168,   480,     0,     0,
       0,   173,     0,     0,     0,     0,  2154,     0,     0,     0,
       0,     0,   178,   179,   180,     0,     0,     0,     0,     0,
     181,   466,   467,   468,   469,   470,   471,   472,   473,   474,
     475,   476,   477,   478,   479,     0,     0,     0,     0,   480,
       0,     0,     0,     0,     0,     0,     0,     0,  2155,     0,
       0,     0,     0,     0,   184,     0,     0,     0,   188,     0,
       0,     0,   189,   190,   191,   192,   193,     0,     0,     0,
     102,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   196,   197,     0,     0,     0,   198,
       0,     0,     0,     0,   333,   451,     0,     0,     0,   202,
     466,   467,   468,   469,   470,   471,   472,   473,   474,   475,
     476,   477,   478,   479,     0,     0,     0,     0,   480,     0,
       0,   184,     0,     0,     0,   188,   846,     0,     0,   189,
     190,   191,   192,   193,     0,     0,     0,   102,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   196,   197,     0,     0,     0,   198,     0,     0,     0,
       0,   333,   127,   370,   453,     0,   202,     0,   130,   131,
     132,     0,     0,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,     0,     0,   466,   467,
     468,   469,   470,   471,   472,   473,   474,   475,   476,   477,
     478,   479,   165,   166,   167,   168,   480,     0,     0,     0,
     173,     0,     0,     0,  1807,     0,     0,     0,     0,   127,
     370,   178,   179,   180,     0,   130,   131,   132,     0,   181,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,     0,     0,   466,   467,   468,   469,   470,
     471,   472,   473,   474,   475,   476,   477,   478,   479,   165,
     166,   167,   168,   480,     0,   924,     0,   173,     0,     0,
     853,     0,     0,     0,     0,     0,     0,     0,   178,   179,
     180,     0,     0,     0,     0,     0,   181,   466,   467,   468,
     469,   470,   471,   472,   473,   474,   475,   476,   477,   478,
     479,     0,     0,     0,     0,   480,     0,   896,     0,   897,
       0,     0,  1456,     0,     0,     0,     0,     0,     0,     0,
     184,     0,     0,     0,   188,     0,     0,     0,   189,   190,
     191,   192,   193,     0,     0,     0,   102,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     196,   197,     0,     0,     0,   198,     0,     0,     0,     0,
     333,   665,     0,     0,     0,   202,     0,   466,   467,   468,
     469,   470,   471,   472,   473,   474,   475,   476,   477,   478,
     479,     0,     0,     0,     0,   480,     0,   184,     0,     0,
       0,   188,   780,     0,     0,   189,   190,   191,   192,   193,
       0,     0,     0,   102,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   196,   197,     0,
       0,     0,   198,     0,     0,     0,     0,   333,   127,   370,
     667,  1223,   202,     0,   130,   131,   132,     0,     0,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,     0,     0,   466,   467,   468,   469,   470,   471,
     472,   473,   474,   475,   476,   477,   478,   479,   165,   166,
     167,   168,   480,     0,     0,     0,   173,     0,     0,   853,
       0,     0,     0,     0,     0,     0,     0,   178,   179,   180,
     127,   370,     0,  1366,     0,   181,   130,   131,   132,     0,
       0,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,     0,     0,   466,   467,   468,   469,
     470,   471,   472,   473,   474,   475,   476,   477,   478,   479,
     165,   166,   167,   168,   480,     0,     0,     0,   173,     0,
       0,   854,     0,     0,     0,     0,     0,     0,     0,   178,
     179,   180,     0,     0,     0,     0,     0,   181,   466,   467,
     468,   469,   470,   471,   472,   473,   474,   475,   476,   477,
     478,   479,     0,     0,     0,     0,   480,     0,     0,     0,
       0,     0,     0,   938,     0,     0,   184,     0,     0,     0,
     188,     0,     0,     0,   189,   190,   191,   192,   193,     0,
       0,     0,   102,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   196,   197,     0,     0,
       0,   198,     0,     0,     0,     0,   333,     0,     0,     0,
       0,   202,   466,   467,   468,   469,   470,   471,   472,   473,
     474,   475,   476,   477,   478,   479,     0,     0,     0,     0,
     480,     0,     0,     0,     0,     0,     0,   983,   184,     0,
       0,     0,   188,     0,     0,     0,   189,   190,   191,   192,
     193,     0,     0,     0,   102,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   196,   197,
       0,     0,     0,   198,   127,   370,     0,     0,   333,     0,
     130,   131,   132,   202,     0,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,     0,     0,
     466,   467,   468,   469,   470,   471,   472,   473,   474,   475,
     476,   477,   478,   479,   165,   166,   167,   168,   480,     0,
       0,     0,   173,     0,     0,   991,     0,     0,     0,     0,
       0,     0,     0,   178,   179,   180,     0,     0,     0,     0,
       0,   181,   466,   467,   468,   469,   470,   471,   472,   473,
     474,   475,   476,   477,   478,   479,     0,     0,     0,     0,
     480,     0,     0,     0,     0,     0,     0,   992,   466,   467,
     468,   469,   470,   471,   472,   473,   474,   475,   476,   477,
     478,   479,     0,     0,     0,     0,   480,     0,     0,     0,
       0,     0,     0,   993,   466,   467,   468,   469,   470,   471,
     472,   473,   474,   475,   476,   477,   478,   479,     0,     0,
       0,     0,   480,     0,     0,     0,     0,    -4,     1,  1008,
       0,    -4,     0,     0,     0,     0,     0,     0,     0,    -4,
      -4,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   184,     0,     0,     0,   188,     0,     0,     0,
     189,   190,   191,   192,   193,     0,     0,     0,   102,    -4,
      -4,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   196,   197,     0,     0,     0,   198,     0,    -4,
      -4,    -4,   333,     0,     0,    -4,    -4,   202,    -4,     0,
       0,     0,    -4,    -4,     0,    -4,    -4,     0,     0,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,     0,     0,     0,    -4,    -4,    -4,    -4,     0,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,     0,    -4,    -4,    -4,    -4,    -4,
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
      33,     0,     0,     0,    34,    35,    36,    37,     0,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,     0,    52,    53,    54,    55,    56,    57,
      58,    59,    60,     0,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,     0,     0,     0,
      74,    75,    76,     0,     0,     0,     0,     0,    77,     0,
       0,     0,     0,    78,    79,    80,    81,     0,     0,    82,
       0,    83,     0,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,     0,     0,     0,
       0,     0,    98,    99,   100,     0,     0,     0,     0,     0,
       0,   101,     0,   102,   466,   467,   468,   469,   470,   471,
     472,   473,   474,   475,   476,   477,   478,   479,     0,     0,
       0,     0,   480,     0,     0,     0,     0,     0,     0,  1145,
     466,   467,   468,   469,   470,   471,   472,   473,   474,   475,
     476,   477,   478,   479,     0,     0,     0,     0,   480,     0,
       0,     0,     0,     0,     0,  1146,   466,   467,   468,   469,
     470,   471,   472,   473,   474,   475,   476,   477,   478,   479,
       0,     0,     0,     0,   480,     0,     0,     0,     0,     0,
       0,  1147,   466,   467,   468,   469,   470,   471,   472,   473,
     474,   475,   476,   477,   478,   479,     0,     0,     0,     0,
     480,     0,     0,     0,     0,     0,     0,  1182,   466,   467,
     468,   469,   470,   471,   472,   473,   474,   475,   476,   477,
     478,   479,     0,     0,     0,     0,   480,     0,     0,     0,
       0,     0,     0,  1191,   466,   467,   468,   469,   470,   471,
     472,   473,   474,   475,   476,   477,   478,   479,     0,     0,
       0,     0,   480,     0,     0,     0,     0,     0,     0,  1192,
     466,   467,   468,   469,   470,   471,   472,   473,   474,   475,
     476,   477,   478,   479,     0,     0,     0,     0,   480,     0,
       0,     0,     0,     0,     0,  1194,   466,   467,   468,   469,
     470,   471,   472,   473,   474,   475,   476,   477,   478,   479,
       0,     0,     0,     0,   480,     0,     0,     0,     0,     0,
       0,  1305,   466,   467,   468,   469,   470,   471,   472,   473,
     474,   475,   476,   477,   478,   479,     0,     0,     0,     0,
     480,     0,     0,     0,     0,     0,     0,  1358,   466,   467,
     468,   469,   470,   471,   472,   473,   474,   475,   476,   477,
     478,   479,     0,     0,     0,     0,   480,     0,     0,     0,
       0,     0,     0,  1359,   466,   467,   468,   469,   470,   471,
     472,   473,   474,   475,   476,   477,   478,   479,     0,     0,
       0,     0,   480,     0,     0,     0,     0,     0,     0,  1424,
     466,   467,   468,   469,   470,   471,   472,   473,   474,   475,
     476,   477,   478,   479,     0,     0,     0,     0,   480,     0,
       0,     0,     0,     0,     0,  1595,   466,   467,   468,   469,
     470,   471,   472,   473,   474,   475,   476,   477,   478,   479,
       0,     0,     0,     0,   480,     0,     0,     0,     0,     0,
       0,  1596,   466,   467,   468,   469,   470,   471,   472,   473,
     474,   475,   476,   477,   478,   479,     0,     0,     0,     0,
     480,     0,     0,     0,     0,     0,     0,  1597,   466,   467,
     468,   469,   470,   471,   472,   473,   474,   475,   476,   477,
     478,   479,     0,     0,     0,     0,   480,     0,     0,     0,
       0,     0,     0,  1598,   466,   467,   468,   469,   470,   471,
     472,   473,   474,   475,   476,   477,   478,   479,     0,     0,
       0,     0,   480,     0,     0,     0,     0,     0,     0,  1599,
     466,   467,   468,   469,   470,   471,   472,   473,   474,   475,
     476,   477,   478,   479,     0,     0,     0,     0,   480,     0,
       0,     0,     0,     0,     0,  1600,   466,   467,   468,   469,
     470,   471,   472,   473,   474,   475,   476,   477,   478,   479,
       0,     0,     0,     0,   480,     0,     0,     0,     0,     0,
       0,  1601,   466,   467,   468,   469,   470,   471,   472,   473,
     474,   475,   476,   477,   478,   479,     0,     0,     0,     0,
     480,     0,     0,     0,     0,     0,     0,  1654,   466,   467,
     468,   469,   470,   471,   472,   473,   474,   475,   476,   477,
     478,   479,     0,     0,     0,     0,   480,     0,     0,     0,
       0,     0,     0,  1655,   466,   467,   468,   469,   470,   471,
     472,   473,   474,   475,   476,   477,   478,   479,     0,     0,
       0,     0,   480,     0,     0,     0,     0,     0,     0,  1662,
     466,   467,   468,   469,   470,   471,   472,   473,   474,   475,
     476,   477,   478,   479,     0,     0,     0,     0,   480,     0,
       0,     0,     0,     0,     0,  1837,   466,   467,   468,   469,
     470,   471,   472,   473,   474,   475,   476,   477,   478,   479,
       0,     0,     0,     0,   480,     0,     0,     0,     0,     0,
       0,  1838,   466,   467,   468,   469,   470,   471,   472,   473,
     474,   475,   476,   477,   478,   479,     0,     0,     0,     0,
     480,     0,     0,     0,     0,     0,     0,  1839,   466,   467,
     468,   469,   470,   471,   472,   473,   474,   475,   476,   477,
     478,   479,     0,     0,     0,     0,   480,     0,     0,     0,
       0,     0,     0,  1840,   466,   467,   468,   469,   470,   471,
     472,   473,   474,   475,   476,   477,   478,   479,     0,     0,
       0,     0,   480,     0,     0,     0,     0,     0,     0,  1841,
     466,   467,   468,   469,   470,   471,   472,   473,   474,   475,
     476,   477,   478,   479,     0,     0,     0,     0,   480,     0,
       0,     0,     0,     0,     0,  1865,   466,   467,   468,   469,
     470,   471,   472,   473,   474,   475,   476,   477,   478,   479,
       0,     0,     0,     0,   480,     0,     0,     0,     0,     0,
       0,  1866,   466,   467,   468,   469,   470,   471,   472,   473,
     474,   475,   476,   477,   478,   479,     0,     0,     0,     0,
     480,     0,     0,     0,     0,     0,     0,  1870,   466,   467,
     468,   469,   470,   471,   472,   473,   474,   475,   476,   477,
     478,   479,     0,     0,     0,     0,   480,     0,     0,     0,
       0,     0,     0,  1978,   466,   467,   468,   469,   470,   471,
     472,   473,   474,   475,   476,   477,   478,   479,     0,     0,
       0,     0,   480,     0,     0,     0,     0,     0,     0,  1979,
     466,   467,   468,   469,   470,   471,   472,   473,   474,   475,
     476,   477,   478,   479,     0,     0,     0,     0,   480,     0,
       0,     0,     0,     0,     0,  1980,   466,   467,   468,   469,
     470,   471,   472,   473,   474,   475,   476,   477,   478,   479,
       0,     0,     0,     0,   480,     0,     0,     0,     0,     0,
       0,  1981,   466,   467,   468,   469,   470,   471,   472,   473,
     474,   475,   476,   477,   478,   479,     0,     0,     0,     0,
     480,     0,     0,     0,     0,     0,     0,  1982,   466,   467,
     468,   469,   470,   471,   472,   473,   474,   475,   476,   477,
     478,   479,     0,     0,     0,     0,   480,     0,     0,     0,
       0,     0,     0,  1992,   466,   467,   468,   469,   470,   471,
     472,   473,   474,   475,   476,   477,   478,   479,     0,     0,
       0,     0,   480,     0,     0,     0,     0,     0,     0,  1995,
     466,   467,   468,   469,   470,   471,   472,   473,   474,   475,
     476,   477,   478,   479,     0,     0,     0,     0,   480,     0,
       0,     0,     0,     0,     0,  2045,   466,   467,   468,   469,
     470,   471,   472,   473,   474,   475,   476,   477,   478,   479,
       0,     0,     0,     0,   480,     0,     0,     0,     0,     0,
       0,  2065,   466,   467,   468,   469,   470,   471,   472,   473,
     474,   475,   476,   477,   478,   479,     0,     0,     0,     0,
     480,     0,     0,     0,     0,     0,     0,  2066,   466,   467,
     468,   469,   470,   471,   472,   473,   474,   475,   476,   477,
     478,   479,     0,     0,     0,     0,   480,     0,     0,     0,
       0,     0,     0,  2067,   466,   467,   468,   469,   470,   471,
     472,   473,   474,   475,   476,   477,   478,   479,     0,     0,
       0,     0,   480,     0,     0,     0,     0,     0,     0,  2068,
     466,   467,   468,   469,   470,   471,   472,   473,   474,   475,
     476,   477,   478,   479,     0,     0,     0,     0,   480,     0,
       0,     0,     0,     0,     0,  2069,   466,   467,   468,   469,
     470,   471,   472,   473,   474,   475,   476,   477,   478,   479,
       0,     0,     0,     0,   480,     0,     0,     0,     0,     0,
       0,  2120,   466,   467,   468,   469,   470,   471,   472,   473,
     474,   475,   476,   477,   478,   479,     0,     0,     0,     0,
     480,     0,     0,     0,     0,     0,     0,  2121,   466,   467,
     468,   469,   470,   471,   472,   473,   474,   475,   476,   477,
     478,   479,     0,     0,     0,     0,   480,     0,     0,     0,
       0,     0,     0,  2122,   466,   467,   468,   469,   470,   471,
     472,   473,   474,   475,   476,   477,   478,   479,     0,     0,
       0,     0,   480,     0,     0,     0,     0,     0,     0,  2123,
     466,   467,   468,   469,   470,   471,   472,   473,   474,   475,
     476,   477,   478,   479,     0,     0,     0,     0,   480,     0,
       0,     0,   944,   466,   467,   468,   469,   470,   471,   472,
     473,   474,   475,   476,   477,   478,   479,     0,     0,     0,
       0,   480,     0,     0,     0,   963,   466,   467,   468,   469,
     470,   471,   472,   473,   474,   475,   476,   477,   478,   479,
       0,     0,     0,     0,   480,     0,     0,     0,   970,   466,
     467,   468,   469,   470,   471,   472,   473,   474,   475,   476,
     477,   478,   479,     0,     0,     0,     0,   480,     0,     0,
       0,  1066,   466,   467,   468,   469,   470,   471,   472,   473,
     474,   475,   476,   477,   478,   479,     0,     0,     0,     0,
     480,     0,     0,     0,  1175,   466,   467,   468,   469,   470,
     471,   472,   473,   474,   475,   476,   477,   478,   479,     0,
       0,     0,     0,   480,     0,     0,     0,  1176,   466,   467,
     468,   469,   470,   471,   472,   473,   474,   475,   476,   477,
     478,   479,     0,     0,     0,     0,   480,     0,     0,     0,
    1180,   466,   467,   468,   469,   470,   471,   472,   473,   474,
     475,   476,   477,   478,   479,     0,     0,     0,     0,   480,
       0,     0,     0,  1181,   466,   467,   468,   469,   470,   471,
     472,   473,   474,   475,   476,   477,   478,   479,     0,     0,
       0,     0,   480,     0,     0,     0,  1184,   466,   467,   468,
     469,   470,   471,   472,   473,   474,   475,   476,   477,   478,
     479,     0,     0,     0,     0,   480,     0,     0,     0,  1208,
     466,   467,   468,   469,   470,   471,   472,   473,   474,   475,
     476,   477,   478,   479,     0,     0,     0,     0,   480,     0,
       0,     0,  1241,   466,   467,   468,   469,   470,   471,   472,
     473,   474,   475,   476,   477,   478,   479,     0,     0,     0,
       0,   480,     0,     0,     0,  1298,   466,   467,   468,   469,
     470,   471,   472,   473,   474,   475,   476,   477,   478,   479,
       0,     0,     0,     0,   480,     0,     0,     0,  1303,   466,
     467,   468,   469,   470,   471,   472,   473,   474,   475,   476,
     477,   478,   479,     0,     0,     0,     0,   480,     0,     0,
       0,  1590,   466,   467,   468,   469,   470,   471,   472,   473,
     474,   475,   476,   477,   478,   479,     0,     0,     0,     0,
     480,     0,     0,     0,  1645,   466,   467,   468,   469,   470,
     471,   472,   473,   474,   475,   476,   477,   478,   479,     0,
       0,     0,     0,   480,     0,     0,     0,  1820,   466,   467,
     468,   469,   470,   471,   472,   473,   474,   475,   476,   477,
     478,   479,     0,     0,     0,     0,   480,     0,   733,   466,
     467,   468,   469,   470,   471,   472,   473,   474,   475,   476,
     477,   478,   479,     0,     0,     0,     0,   480,     0,   790,
     466,   467,   468,   469,   470,   471,   472,   473,   474,   475,
     476,   477,   478,   479,     0,     0,     0,     0,   480,     0,
     794,   466,   467,   468,   469,   470,   471,   472,   473,   474,
     475,   476,   477,   478,   479,     0,     0,     0,     0,   480,
       0,   795,   466,   467,   468,   469,   470,   471,   472,   473,
     474,   475,   476,   477,   478,   479,     0,     0,     0,     0,
     480,     0,   797,   466,   467,   468,   469,   470,   471,   472,
     473,   474,   475,   476,   477,   478,   479,     0,     0,     0,
       0,   480,     0,   799,   466,   467,   468,   469,   470,   471,
     472,   473,   474,   475,   476,   477,   478,   479,     0,     0,
       0,     0,   480,     0,   800,   466,   467,   468,   469,   470,
     471,   472,   473,   474,   475,   476,   477,   478,   479,     0,
       0,     0,     0,   480,     0,   803,   466,   467,   468,   469,
     470,   471,   472,   473,   474,   475,   476,   477,   478,   479,
       0,     0,     0,     0,   480,     0,   804,   466,   467,   468,
     469,   470,   471,   472,   473,   474,   475,   476,   477,   478,
     479,     0,     0,     0,     0,   480,     0,   805,   466,   467,
     468,   469,   470,   471,   472,   473,   474,   475,   476,   477,
     478,   479,     0,     0,     0,     0,   480,     0,   806,   466,
     467,   468,   469,   470,   471,   472,   473,   474,   475,   476,
     477,   478,   479,     0,     0,     0,     0,   480,     0,   808,
     466,   467,   468,   469,   470,   471,   472,   473,   474,   475,
     476,   477,   478,   479,     0,     0,     0,     0,   480,     0,
     809,   466,   467,   468,   469,   470,   471,   472,   473,   474,
     475,   476,   477,   478,   479,     0,     0,     0,     0,   480,
       0,   818,   466,   467,   468,   469,   470,   471,   472,   473,
     474,   475,   476,   477,   478,   479,     0,     0,     0,     0,
     480,     0,   924,   466,   467,   468,   469,   470,   471,   472,
     473,   474,   475,   476,   477,   478,   479,     0,     0,     0,
       0,   480,     0,   934,   466,   467,   468,   469,   470,   471,
     472,   473,   474,   475,   476,   477,   478,   479,     0,     0,
       0,     0,   480,     0,   935,   466,   467,   468,   469,   470,
     471,   472,   473,   474,   475,   476,   477,   478,   479,     0,
       0,     0,     0,   480,     0,   936,   466,   467,   468,   469,
     470,   471,   472,   473,   474,   475,   476,   477,   478,   479,
       0,     0,     0,     0,   480,     0,   942,   466,   467,   468,
     469,   470,   471,   472,   473,   474,   475,   476,   477,   478,
     479,     0,     0,     0,     0,   480,     0,   943,   466,   467,
     468,   469,   470,   471,   472,   473,   474,   475,   476,   477,
     478,   479,     0,     0,     0,     0,   480,     0,   950,   466,
     467,   468,   469,   470,   471,   472,   473,   474,   475,   476,
     477,   478,   479,     0,     0,     0,     0,   480,     0,   959,
     466,   467,   468,   469,   470,   471,   472,   473,   474,   475,
     476,   477,   478,   479,     0,     0,     0,     0,   480,     0,
     969,   466,   467,   468,   469,   470,   471,   472,   473,   474,
     475,   476,   477,   478,   479,     0,     0,     0,     0,   480,
       0,  1065,   466,   467,   468,   469,   470,   471,   472,   473,
     474,   475,   476,   477,   478,   479,     0,     0,     0,     0,
     480,     0,  1093,   466,   467,   468,   469,   470,   471,   472,
     473,   474,   475,   476,   477,   478,   479,     0,     0,     0,
       0,   480,     0,  1098,   466,   467,   468,   469,   470,   471,
     472,   473,   474,   475,   476,   477,   478,   479,     0,     0,
       0,     0,   480,     0,  1107,   466,   467,   468,   469,   470,
     471,   472,   473,   474,   475,   476,   477,   478,   479,     0,
       0,     0,     0,   480,     0,  1112,   466,   467,   468,   469,
     470,   471,   472,   473,   474,   475,   476,   477,   478,   479,
       0,     0,     0,     0,   480,     0,  1113,   466,   467,   468,
     469,   470,   471,   472,   473,   474,   475,   476,   477,   478,
     479,     0,     0,     0,     0,   480,     0,  1119,   466,   467,
     468,   469,   470,   471,   472,   473,   474,   475,   476,   477,
     478,   479,     0,     0,     0,     0,   480,     0,  1128,   466,
     467,   468,   469,   470,   471,   472,   473,   474,   475,   476,
     477,   478,   479,     0,     0,     0,     0,   480,     0,  1129,
     466,   467,   468,   469,   470,   471,   472,   473,   474,   475,
     476,   477,   478,   479,     0,     0,     0,     0,   480,     0,
    1130,   466,   467,   468,   469,   470,   471,   472,   473,   474,
     475,   476,   477,   478,   479,     0,     0,     0,     0,   480,
       0,  1162,   466,   467,   468,   469,   470,   471,   472,   473,
     474,   475,   476,   477,   478,   479,     0,     0,     0,     0,
     480,     0,  1164,   466,   467,   468,   469,   470,   471,   472,
     473,   474,   475,   476,   477,   478,   479,     0,     0,     0,
       0,   480,     0,  1165,   466,   467,   468,   469,   470,   471,
     472,   473,   474,   475,   476,   477,   478,   479,     0,     0,
       0,     0,   480,     0,  1166,   466,   467,   468,   469,   470,
     471,   472,   473,   474,   475,   476,   477,   478,   479,     0,
       0,     0,     0,   480,     0,  1167,   466,   467,   468,   469,
     470,   471,   472,   473,   474,   475,   476,   477,   478,   479,
       0,     0,     0,     0,   480,     0,  1168,   466,   467,   468,
     469,   470,   471,   472,   473,   474,   475,   476,   477,   478,
     479,     0,     0,     0,     0,   480,     0,  1169,   466,   467,
     468,   469,   470,   471,   472,   473,   474,   475,   476,   477,
     478,   479,     0,     0,     0,     0,   480,     0,  1170,   466,
     467,   468,   469,   470,   471,   472,   473,   474,   475,   476,
     477,   478,   479,     0,     0,     0,     0,   480,     0,  1174,
     466,   467,   468,   469,   470,   471,   472,   473,   474,   475,
     476,   477,   478,   479,     0,     0,     0,     0,   480,     0,
    1183,   466,   467,   468,   469,   470,   471,   472,   473,   474,
     475,   476,   477,   478,   479,     0,     0,     0,     0,   480,
       0,  1207,   466,   467,   468,   469,   470,   471,   472,   473,
     474,   475,   476,   477,   478,   479,     0,     0,     0,     0,
     480,     0,  1297,   466,   467,   468,   469,   470,   471,   472,
     473,   474,   475,   476,   477,   478,   479,     0,     0,     0,
       0,   480,     0,  1302,   466,   467,   468,   469,   470,   471,
     472,   473,   474,   475,   476,   477,   478,   479,     0,     0,
       0,     0,   480,     0,  1468,   466,   467,   468,   469,   470,
     471,   472,   473,   474,   475,   476,   477,   478,   479,     0,
       0,     0,     0,   480,     0,  1699,   466,   467,   468,   469,
     470,   471,   472,   473,   474,   475,   476,   477,   478,   479,
       0,     0,     0,     0,   480,     0,  1716,   466,   467,   468,
     469,   470,   471,   472,   473,   474,   475,   476,   477,   478,
     479,     0,     0,     0,     0,   480,     0,  1746,   466,   467,
     468,   469,   470,   471,   472,   473,   474,   475,   476,   477,
     478,   479,     0,     0,     0,     0,   480,     0,  1991,   466,
     467,   468,   469,   470,   471,   472,   473,   474,   475,   476,
     477,   478,   479,     0,     0,     0,     0,   480,     0,  2075
};

static const yytype_int16 yycheck[] =
{
       3,  1157,   418,     6,   420,   276,   451,  1161,   453,     4,
     455,  1613,  1614,     5,   562,   563,     7,     4,     4,   435,
    1791,     4,     6,     3,     6,     4,     4,   221,     4,     6,
       4,     4,     4,     4,     4,     4,   225,     4,     6,   291,
       5,   230,     5,     5,     5,     4,     6,     5,     5,   222,
       6,     5,     5,     5,   227,   307,     6,  1579,     6,   211,
     212,     6,     6,   218,   219,     7,    69,   211,   212,     4,
       4,     6,   211,   212,    77,   227,   117,   229,   163,    82,
       6,     6,   221,   227,     6,   229,   221,   211,   212,   228,
      93,     0,   133,   228,   179,   180,   117,   211,   212,    13,
     141,   142,   143,     7,     6,   229,   147,   148,   149,   150,
     218,   219,   133,   227,     7,   367,   224,   369,   211,   212,
     141,   142,   143,   375,    90,     7,   147,   148,   149,   150,
     211,   212,   221,   221,   223,   228,    56,    57,   126,    59,
       6,   211,   212,   218,   219,     6,   227,     7,   229,    84,
      84,   223,     7,   228,    88,   218,   219,  1679,   228,     7,
      94,    95,    96,    97,   221,   228,   223,     6,    93,   151,
      95,  1942,  1943,   230,   166,   221,   110,   223,     6,   153,
     154,   155,   156,   151,   230,     7,    84,   174,   229,    87,
     163,   164,    90,   163,   164,   151,   211,   212,   222,   202,
     178,     7,   197,   227,   166,   166,   151,     7,   229,     6,
     197,   214,   215,   228,   166,     7,   221,   221,   223,   222,
     665,   223,   667,   203,   208,   230,  1382,   230,   197,   232,
     221,   208,   223,   228,   237,   221,   228,   223,   241,   225,
     223,   228,   221,   246,   230,   221,   249,   230,     6,   228,
     253,   254,   255,   256,   257,   229,   228,   228,   261,   262,
     263,   228,   221,   228,  1786,   228,   269,   270,   271,   228,
     228,   228,   275,   276,   228,   228,     3,   221,   228,     6,
     228,     6,  1804,   225,   228,   211,   212,   102,   733,   211,
     212,   221,   737,   223,   198,   199,   200,   201,   301,   302,
     303,   553,   554,   221,   229,   198,   199,   200,   201,   211,
     212,   221,   315,   316,   218,   219,   198,   199,   200,   201,
      87,   573,    90,    90,    92,   218,   219,    84,     4,   332,
      87,   334,   225,    90,     6,     7,   218,   219,   198,   199,
     200,   201,    69,   198,   199,   200,   201,   221,   214,   215,
     198,   199,   200,   201,   228,    82,   221,   211,   212,   279,
     280,   218,   219,   218,   219,   221,    93,   287,   225,   221,
     373,   291,   228,   227,   377,   378,   198,   199,   200,   201,
     246,   222,    87,   224,  1986,    90,   227,   390,   211,   212,
     642,   257,   198,   199,   200,   201,   218,   219,   198,   199,
     200,   201,   221,   221,   227,   657,   198,   199,   200,   201,
     228,   224,   211,   212,   227,   418,   419,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   227,   432,
     433,   434,   435,   436,   211,   212,   221,   440,   441,   442,
     443,   444,   445,   228,   447,   121,   122,   123,   124,   221,
     227,   121,   122,   117,   211,   212,    90,   127,   383,   135,
     224,   464,   138,   227,   221,   211,   212,   455,   222,   133,
     224,   228,  1994,   221,   228,   202,   221,   141,   142,   143,
     227,   227,   229,   147,   148,   149,   150,   214,   215,   254,
     255,   256,   221,   211,   212,   222,   261,   262,   263,   502,
     211,   212,   221,   230,   211,   212,   221,   373,   117,   227,
     211,   212,   222,   438,   959,     6,   227,   227,   963,   246,
     227,   446,    90,   222,   133,   224,   227,   211,   212,   228,
     257,   228,   141,   142,   143,   221,   301,   302,   147,   148,
     149,   150,   221,   227,   547,   548,   121,   122,    90,   276,
     315,   316,   127,   419,    90,   421,   422,   423,   424,   425,
     426,   427,     8,   429,   430,   229,   432,   433,   434,    92,
     436,   211,   212,   221,   440,   441,   442,   443,   444,   211,
     212,    87,   562,   563,  2106,   211,   212,   227,   211,   212,
     593,   594,   595,   211,   212,   227,     8,   849,   213,   214,
     215,   227,   605,   606,   227,   220,   609,   211,   212,   227,
     211,   212,   537,   538,   539,   540,   211,   212,   228,   117,
     229,   624,   222,   227,   218,   219,   227,   227,   631,   218,
     219,     6,   227,    90,   228,   133,   228,   211,   212,   228,
     560,   561,    87,   141,   142,   143,   373,   650,   568,   147,
     148,   149,   150,   227,   211,   212,   211,   212,   211,   212,
      87,  1815,   221,  1817,   223,  1819,   225,   670,   211,   212,
     227,   230,   227,    87,   227,  1120,    90,  1122,    92,  1124,
      90,  1126,   222,   222,   227,   211,   212,   227,   227,   677,
       4,   418,   419,   420,   421,   422,   423,   424,   425,   426,
     427,   227,   429,   430,     4,   432,   433,   434,   435,   436,
     211,   212,   221,   440,   441,   442,   443,   444,   445,     4,
     447,   211,   212,   211,   212,   221,   227,   223,   227,   732,
     229,   229,    84,   736,   230,    87,     4,   227,    90,   227,
      92,  1897,   221,   609,  1900,   733,   221,  1903,   223,   737,
     225,   223,   222,   228,   224,   230,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     218,   219,   775,  1044,   220,     6,   779,   218,   219,   782,
     228,   221,   785,   229,   787,   211,   212,   228,   791,   792,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   227,   221,   229,   223,   220,   225,
       6,     7,    84,   738,   230,    87,  1970,   229,    90,   822,
      92,   227,   227,   229,   229,   117,  1271,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   133,  1287,   846,   117,   220,     6,  1263,  1264,   141,
     142,   143,  1268,  1269,   222,   147,   148,   149,   150,   227,
     133,   222,   221,   224,   789,  2021,   227,   221,   141,   142,
     143,   221,   221,   223,   147,   148,   149,   150,   223,   606,
     230,   221,   609,   211,   212,   213,   214,   215,    87,   221,
     221,    90,   220,    92,  2048,   898,  2050,   900,  2052,   221,
     903,   222,     7,   224,  2058,   221,   227,   895,   227,   222,
     229,   224,   221,   916,   227,   918,   782,   920,     8,   922,
     227,   787,   229,   221,   927,  2081,   221,   221,  2084,   932,
     221,  2087,   852,   222,  2090,   224,   223,   229,   227,   859,
     228,   222,   222,   224,   224,   865,   227,   227,   227,     6,
     229,   954,   227,     4,   229,   958,   229,   228,  2112,   962,
    2114,   228,  2116,   117,   227,     6,   229,   970,   227,   221,
     229,   959,   227,   221,   229,   963,  2132,   228,  2134,   133,
    2136,   969,   970,   227,   227,   229,   229,   141,   142,   143,
     228,   221,   995,   147,   148,   149,   150,  1000,   117,   221,
     228,  1446,  1005,  1006,  1007,  1008,   227,  1278,   229,  1557,
    1558,    90,   221,    92,   133,  1018,    90,  1020,    92,   221,
    1436,  1437,   141,   142,   143,  1441,  1442,   228,   147,   148,
     149,   150,   227,   227,   229,   229,   227,   227,   229,   229,
     117,  1044,   228,   228,  1047,  1048,  1049,  1050,   227,   227,
     229,   229,   227,   221,   229,   782,   133,   227,   785,   229,
     787,   227,   221,   229,   141,   142,   143,   228,   223,  1072,
     147,   148,   149,   150,   227,   229,   229,  1065,  1066,   207,
     208,   209,   210,   211,   212,   213,   214,   215,  1091,  1092,
     221,  1094,   220,  1096,  1097,   221,   221,  1100,  1101,  1102,
    1103,  1104,  1105,     8,   970,   227,  1109,   229,  1111,   227,
     229,   229,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   227,   227,   229,   229,
     220,   227,   222,   229,  1000,   227,   227,   229,   229,   117,
    1006,  1007,  1008,     4,   227,     6,   229,   227,   221,   229,
       6,   227,  1018,   229,  1020,   133,   227,   227,   229,   229,
     227,   221,   229,   141,   142,   143,   227,  1087,   229,   147,
     148,   149,   150,   227,   227,   229,   229,     6,   227,  1431,
     229,  1433,   232,   227,   227,   229,   229,   237,   227,   221,
     229,   241,     4,     5,   221,  1183,  1184,   227,   227,   229,
     229,   221,   227,   253,   229,   228,  1072,  1210,  1211,  1212,
     227,   227,   229,   229,   221,   227,  1487,   229,   221,  1207,
    1208,   230,   227,  1226,   229,  1145,  1146,  1147,   227,   227,
     229,   229,    44,    45,    46,    47,    48,    49,    50,    51,
      52,   228,   227,   970,   229,    57,    58,    59,    60,   228,
     227,   229,   229,    65,    66,    67,   223,   227,    70,   229,
    1263,  1264,  1810,   223,   228,  1268,  1269,   223,   227,    81,
     229,     6,     6,  1000,     6,  1278,   227,   166,   229,  1006,
    1007,  1008,   227,  1271,   229,   227,   230,   229,   228,  1292,
       6,  1018,     6,  1020,   228,     6,     6,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,     6,   228,  1316,   228,   220,     6,  1044,     4,  1322,
     223,    12,    13,   220,   225,     7,   228,   227,   222,  1332,
     229,   227,  1335,  1336,     7,     6,   117,  1340,  1341,     6,
    1343,     6,  1345,   222,  1347,  1072,  1349,  1350,  1351,     7,
       7,  1767,   133,     6,     6,     6,   222,     6,   228,     6,
     141,   142,   143,     7,     6,  1368,   147,   148,   149,   150,
     182,   183,   184,     7,     6,     6,     6,     4,    62,    62,
    1383,  1306,   194,    62,   196,   197,    62,   163,  1391,   228,
    1393,   224,   222,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,     6,     6,   218,   219,    99,   100,
     101,   117,   103,   225,   464,   222,   228,   108,   109,   110,
     111,   222,   113,   114,   115,   227,    44,   133,   119,   227,
     227,   227,   227,  1436,  1437,   141,   142,   143,  1441,  1442,
     227,   147,   148,   149,   150,   227,   224,   222,   229,   222,
     222,    44,  1455,    44,    44,     6,     4,     4,  1461,   166,
    1448,  1381,     6,     6,     6,     6,   166,   158,   159,   160,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,  1487,     7,     7,     7,   220,   166,
    1493,     7,     7,     7,     6,   228,     7,   547,   548,     7,
    1503,     7,     7,  1506,     7,  1430,  1777,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,     7,     6,   229,     7,   220,     4,     6,   222,   227,
     222,   227,   229,   222,   227,   222,  1263,  1264,   229,   227,
     225,  1268,  1269,   593,   594,   595,  1549,  1550,   229,     6,
       6,  1278,   222,   228,  1479,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   224,
       7,     7,  1824,   220,   624,     7,  1579,  1557,  1558,   225,
     228,  1506,  1585,   228,     7,   228,     6,     6,   229,  1455,
     228,    44,    44,    44,    44,  1461,  1516,     6,     6,   117,
     650,     6,  1605,  1591,     6,   228,     7,   223,     6,     6,
     221,   221,  1615,     6,   208,   133,     7,     7,    92,     7,
     670,     7,  1625,   141,   142,   143,     7,  1630,  1553,   147,
     148,   149,   150,     7,     6,     6,     4,  1503,     7,  1559,
       7,  1561,     7,  1563,     7,     7,     7,     4,   228,   221,
       6,   228,     7,  1656,     6,    90,     7,     7,     7,     7,
    1580,  1581,  1582,  1583,  1584,  1585,     7,     7,     7,     6,
       6,     6,   227,     7,     6,  1927,  1679,     6,     4,     4,
       4,     4,   228,   228,     6,     6,  1611,     6,     6,   229,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,     6,  1630,  1631,  1632,   220,  1436,
    1437,   229,  1715,     6,  1441,  1442,     7,     6,   227,  1971,
     222,   222,     6,   227,  1727,   775,   225,   221,  1455,   779,
     228,     6,   225,   222,  1461,     6,   224,     6,   228,     6,
     110,   228,     6,   228,  1747,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   228,
    1487,  1764,     6,   220,  1767,   228,     6,     6,     6,     6,
       6,     6,     5,   228,  1777,     6,  1503,     4,     6,   228,
     228,     7,   228,  1786,   223,     6,     6,     6,     6,     4,
    1793,  1794,     6,     6,   228,   228,   846,   228,   228,   228,
     228,  1804,   228,   224,  1807,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   222,
    1823,     6,     6,   220,  1827,  1750,     4,   227,     4,   162,
    1810,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,     6,     6,     6,   898,   220,
     900,     6,     6,   903,     6,     6,     6,     4,     7,     7,
       6,   117,     6,     6,     6,     5,   916,     6,   918,   228,
     920,     6,   922,     6,   166,     6,     6,   927,     6,     6,
       6,     6,   932,  1886,     6,     6,     6,     6,     6,   227,
       6,     6,     6,     6,  1814,   222,  1816,   227,  1818,     6,
       6,     6,  1905,     6,     6,   225,     7,     6,  1828,  1829,
    1830,  1831,  1832,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,     6,   228,  1932,
       6,   220,   228,   228,     6,     5,     7,     6,   228,     6,
     228,     6,   229,    88,   229,   995,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     228,     6,   228,   228,   220,  1885,   228,     4,     5,  1889,
    1973,  1974,  1975,  1976,  1977,   161,     6,   229,   229,   229,
       6,     6,     6,     6,     6,     6,     6,   164,     6,     6,
       6,  1994,     6,     6,     6,     6,   228,  1047,  1048,  1049,
    1050,     6,     6,   228,     7,   222,  1931,    44,    45,    46,
      47,    48,    49,    50,    51,    52,     6,    12,    13,   228,
      57,    58,    59,    60,   228,   228,     6,  1947,    65,    66,
      67,  1951,   228,    70,     6,   229,     6,   117,   228,     6,
    1767,     6,     6,     6,    81,     6,     6,     6,     6,     6,
    1777,     6,     6,     6,   229,   221,   228,  1977,   228,  1109,
    2063,   228,     6,     6,   229,   222,   228,     6,     6,     6,
       6,  2074,     6,     6,     6,     6,     6,     6,     6,     6,
     101,     6,     6,     6,     6,     6,     6,   228,     6,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
       6,     6,     6,  2106,    99,   100,   101,     6,   103,     6,
       6,  2036,  1301,   108,   109,   110,   111,   228,   113,   114,
     115,  2124,   498,  2126,   119,  1935,  2046,  2047,   228,  1792,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   228,   182,   183,   184,   220,     3,
     228,  1315,     3,  2156,     3,     3,   535,   194,  1483,   196,
     197,  1806,    -1,   158,   159,   160,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   196,   197,   198,   199,   200,
      -1,    -1,    -1,    -1,    -1,   222,    -1,   224,    -1,    -1,
      -1,    -1,   213,    -1,    -1,    -1,   217,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1932,    -1,    -1,  2074,    -1,
     231,   232,   233,   234,    -1,   236,   237,   238,   239,    -1,
     241,   242,   243,   244,   245,    -1,   247,   248,    -1,    -1,
      -1,    -1,   253,    -1,   229,    -1,    -1,   258,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   273,    -1,    -1,    -1,   220,    -1,  2124,    -1,
    2126,   282,   283,    -1,    -1,    -1,    -1,    -1,     6,    -1,
     291,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,    -1,    -1,    -1,    -1,   220,
    2156,    -1,    -1,    -1,    -1,    -1,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
      -1,   332,   333,   334,   220,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   346,   347,   348,    -1,   350,
      -1,    -1,    -1,   354,   355,   356,    -1,    -1,   359,    -1,
      -1,    -1,    -1,  1393,    -1,    -1,    -1,  2074,    -1,    -1,
      -1,    -1,    -1,   374,    -1,    -1,    -1,    -1,   379,   380,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   393,   394,    -1,   396,   397,   398,   399,   400,
     401,   402,   403,   404,   405,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   415,   416,   417,  2124,    -1,  2126,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     431,    -1,    -1,    -1,    -1,    -1,   437,    -1,   439,     6,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2156,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   463,   464,    -1,   466,   467,   468,   469,   470,
     471,   472,   473,   474,   475,   476,   477,   478,   479,   480,
      -1,    -1,   483,   484,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,    -1,    -1,
      -1,   502,   220,    -1,    -1,    -1,    -1,   508,    -1,    -1,
      -1,    -1,   513,    -1,    -1,    -1,    -1,    -1,    -1,  1549,
    1550,    -1,   523,   524,    -1,    -1,    -1,    -1,    -1,    -1,
     531,   532,    -1,    -1,    -1,   536,   537,   538,   539,   540,
     541,    -1,   543,    -1,   545,    -1,   547,   548,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,    -1,
      -1,    -1,    -1,   220,   565,   566,   567,   568,   569,   570,
      -1,    -1,    -1,   574,   575,   576,   577,   578,   579,   580,
     581,   582,    -1,    -1,    -1,   586,    -1,   588,   589,    -1,
      -1,    -1,   593,   594,   595,    -1,    -1,   598,   599,   600,
     601,   602,    -1,    -1,   605,   606,   607,   608,    -1,   610,
      -1,    -1,   613,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   624,    -1,     6,    -1,    -1,    -1,   630,
     631,    -1,   633,   634,    -1,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   650,
      -1,    -1,    -1,   220,   655,   656,    -1,   658,   659,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   669,   670,
      -1,    -1,    -1,   674,    -1,    -1,    -1,    -1,     3,     4,
      -1,    -1,    -1,    -1,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    -1,    -1,    -1,    -1,    -1,  1747,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,    54,
      55,    56,    -1,    -1,    -1,    -1,    61,    -1,   739,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,    73,    74,
      -1,    -1,    -1,    -1,    -1,    80,     6,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,    -1,
     771,   772,    -1,   220,   775,   776,   777,  1807,   779,   780,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   788,    -1,    -1,
     791,   792,    -1,    -1,    -1,    -1,    -1,  1827,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   810,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     821,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,    -1,    -1,    -1,    -1,   220,
      -1,    -1,    -1,    -1,    -1,   846,    -1,    -1,    -1,    -1,
      -1,    -1,   853,   854,    -1,    -1,   181,    -1,   859,    -1,
     185,    -1,    -1,    -1,   189,   190,   191,   192,   193,    -1,
      -1,    -1,   197,    -1,    -1,   876,    -1,    -1,   879,    -1,
      -1,    -1,    -1,    -1,    -1,   232,   211,   212,    -1,    -1,
     237,   216,    -1,    -1,   241,    -1,   221,   898,    -1,   900,
      -1,   226,   903,   228,    -1,    -1,   253,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   916,    -1,   918,    -1,   920,
      -1,   922,    -1,    -1,    -1,    -1,   927,    -1,    -1,    -1,
      -1,   932,     6,    -1,    -1,    -1,    -1,   938,    -1,   940,
     941,    -1,    -1,  1973,  1974,  1975,  1976,  1977,    -1,    -1,
     951,    -1,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,    -1,    -1,    -1,    -1,
     220,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   983,    -1,    -1,   332,    -1,   334,    -1,    -1,
     991,   992,   993,    -1,   995,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1003,    12,    13,    -1,    -1,    -1,    -1,    -1,
       7,     8,    -1,    -1,    -1,    -1,  1017,    -1,    -1,    -1,
      -1,  1022,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1031,    -1,    -1,  2063,    -1,    -1,  1037,    -1,    -1,    -1,
      -1,    -1,    -1,   249,    -1,    -1,  1047,  1048,  1049,  1050,
      -1,    -1,  1053,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   269,   270,   271,     7,    -1,    -1,   275,
      -1,    -1,    -1,    -1,    -1,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    -1,    -1,    -1,    -1,
      99,   100,   101,    -1,   103,    -1,    -1,   303,    -1,   108,
     109,   110,   111,    -1,   113,   114,   115,    -1,  1109,    -1,
     119,    -1,    -1,    -1,    -1,    -1,    -1,   464,    -1,    -1,
    1121,    -1,  1123,    -1,  1125,    -1,  1127,    -1,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,    -1,    -1,    -1,    -1,   220,    -1,  1149,   158,
     159,   160,    -1,    -1,    -1,   502,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
      -1,   377,   378,    -1,   220,    -1,    -1,    -1,    -1,    -1,
      -1,  1182,    -1,   229,   390,    -1,    -1,    -1,    -1,    -1,
    1191,  1192,    -1,  1194,  1195,    -1,  1197,  1198,  1199,    -1,
     547,   548,    -1,    -1,  1205,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,    -1,
     229,    -1,   428,   220,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1232,    -1,    -1,    -1,    -1,  1237,    12,    13,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   593,   594,   595,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   605,   606,
      -1,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,    -1,    -1,   624,  1279,   220,
      -1,    -1,    -1,    -1,   631,    -1,    -1,    -1,    -1,  1290,
    1291,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   650,  1305,  1306,    -1,    -1,    -1,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      -1,    -1,    -1,   670,    99,   100,   101,    -1,   103,    -1,
      -1,    -1,    -1,   108,   109,   110,   111,    -1,   113,   114,
     115,    -1,    -1,    -1,   119,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1357,  1358,  1359,    -1,
      -1,    12,    13,    -1,    -1,    -1,    -1,  1368,    -1,  1370,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1381,    -1,    -1,   158,   159,   160,    -1,    -1,    -1,    -1,
      -1,    -1,  1393,    -1,    -1,    -1,    -1,  1398,    -1,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,    -1,    -1,    -1,    -1,   220,    -1,    -1,
      -1,    -1,    -1,  1424,  1425,  1426,   229,    -1,   775,     4,
       5,    -1,   779,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,   791,   792,    -1,    -1,    99,   100,
     101,    -1,   103,    -1,   229,  1456,    -1,   108,   109,   110,
     111,    -1,   113,   114,   115,    -1,    -1,    -1,   119,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    -1,  1480,
      -1,    -1,    57,    58,    59,    60,    -1,    -1,    -1,    -1,
      65,    66,    67,  1494,    -1,    70,    -1,    -1,  1499,   846,
      -1,    -1,    -1,    -1,    -1,    -1,    81,   158,   159,   160,
      -1,    -1,    -1,  1514,  1515,    -1,    -1,    -1,    -1,    -1,
    1521,  1522,    -1,    -1,    -1,  1526,   732,    -1,    -1,    -1,
     736,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1539,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1549,  1550,
    1551,   898,  1553,   900,    -1,    -1,   903,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1565,    -1,    -1,    -1,    -1,   916,
       8,   918,    -1,   920,    -1,   922,    -1,    -1,   229,    -1,
     927,    -1,    -1,    -1,  1585,   932,    -1,  1588,    -1,    -1,
      12,    13,    -1,    -1,  1595,  1596,  1597,  1598,  1599,  1600,
    1601,    -1,    -1,    -1,    -1,    -1,    -1,   182,   183,   184,
    1611,    -1,    -1,    -1,    -1,    -1,   822,    -1,    -1,   194,
      -1,   196,   197,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1631,    -1,    12,    13,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   995,    -1,
      -1,    -1,   220,  1654,  1655,    -1,     8,    -1,    -1,    -1,
     228,  1662,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    -1,    -1,    -1,    -1,    99,   100,   101,
      -1,   103,    -1,    -1,    -1,    -1,   108,   109,   110,   111,
      -1,   113,   114,   115,    -1,    -1,    -1,   119,    -1,  1700,
    1047,  1048,  1049,  1050,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,     8,    -1,  1718,    -1,    99,
     100,   101,    -1,   103,    -1,    -1,  1727,    -1,   108,   109,
     110,   111,    -1,   113,   114,   115,   158,   159,   160,   119,
      -1,  1742,    -1,  1744,    -1,    -1,  1747,    -1,   954,    -1,
      -1,    -1,   958,    -1,    -1,    -1,   962,    -1,    -1,    -1,
      -1,    -1,  1109,  1764,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   158,   159,
     160,  1782,   220,    -1,    -1,    -1,  1787,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1005,
      -1,    -1,    -1,    -1,    -1,    -1,  1807,   229,    -1,    -1,
      -1,    -1,    -1,  1814,    -1,  1816,    -1,  1818,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1827,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1837,  1838,  1839,  1840,
    1841,  1842,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   229,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,  1865,  1866,    -1,    -1,   220,  1870,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1882,    -1,    -1,    -1,  1091,  1092,    -1,  1094,    -1,
    1096,  1097,  1893,     8,  1100,  1101,  1102,  1103,  1104,  1105,
      -1,    -1,    -1,    -1,    -1,  1111,    -1,    -1,    -1,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,    -1,    -1,    -1,    -1,   220,  1929,    -1,
      -1,    -1,    -1,    -1,  1935,    12,    13,    -1,    -1,    -1,
      -1,    -1,    -1,  1944,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1958,    -1,    -1,
    1961,    -1,    -1,  1964,    -1,    -1,    -1,  1968,    -1,     8,
      -1,    -1,  1973,  1974,  1975,  1976,  1977,  1978,  1979,  1980,
    1981,  1982,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1992,    -1,    -1,  1995,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1210,  1211,  1212,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    -1,    -1,
    1226,    -1,    99,   100,   101,    -1,   103,    -1,    -1,    -1,
      -1,   108,   109,   110,   111,    -1,   113,   114,   115,    -1,
      -1,    -1,   119,    -1,  2045,    -1,  1393,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2063,    -1,  2065,  2066,  2067,  2068,  2069,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   158,   159,   160,    -1,    -1,  1292,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,    -1,    -1,    -1,    -1,   220,    -1,    -1,  2109,  2110,
    1316,    -1,    -1,    -1,    -1,    -1,  1322,    -1,    -1,  2120,
    2121,  2122,  2123,    -1,    -1,    -1,  1332,    -1,    -1,  1335,
    1336,    -1,    -1,    -1,  1340,  1341,    -1,  1343,    -1,  1345,
      -1,  1347,    -1,  1349,  1350,  1351,    -1,    -1,    -1,    -1,
      -1,    -1,   229,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1368,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,  1383,    -1,    -1,
      -1,   220,    -1,    -1,   635,  1391,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    21,    22,    -1,    -1,    -1,    -1,
      -1,    -1,  1549,  1550,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,    -1,    -1,
      -1,    -1,   220,    -1,   222,    -1,   224,   678,   679,   680,
     681,   682,   683,   684,   685,   686,   687,   688,  1585,   690,
     691,   692,   693,   694,   695,   696,    -1,    -1,    -1,   700,
     701,   702,    -1,    -1,    -1,   706,   707,    -1,   709,    -1,
      -1,    -1,    -1,   714,   715,   716,    -1,   718,    -1,    -1,
      -1,    -1,    -1,    -1,   725,   726,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1493,    -1,    -1,
      12,    13,   743,    -1,    -1,    -1,    -1,    -1,   125,    -1,
    1506,    -1,    -1,    -1,    -1,    -1,    -1,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,    -1,    -1,    -1,   162,   163,   164,   165,    -1,
     167,   168,   169,   170,   171,   172,    -1,    -1,   175,    -1,
      -1,    -1,    -1,    -1,   181,   182,    -1,    -1,    -1,    -1,
     187,   188,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,  1579,    -1,    -1,    -1,    99,   100,   101,
    1727,   103,    -1,    -1,    -1,    -1,   108,   109,   110,   111,
      -1,   113,   114,   115,    -1,    -1,    -1,   119,    -1,  1605,
    1747,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1615,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1764,    -1,  1625,
      -1,    -1,    -1,    -1,  1630,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   158,   159,   160,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1656,    -1,    -1,    -1,    -1,    -1,    -1,   908,    -1,    -1,
    1807,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1679,    -1,    -1,    -1,    -1,    -1,    -1,
    1827,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   320,    -1,    -1,   323,   324,   325,   326,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   229,    -1,  1715,
      -1,    -1,    -1,    -1,    -1,    -1,   343,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,    -1,    -1,    -1,
      -1,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    53,    54,    55,    56,    -1,
    1786,    -1,    -1,    61,    -1,    -1,    -1,  1793,  1794,    -1,
      -1,    -1,    -1,    -1,    72,    73,    74,    -1,  1804,    -1,
      -1,  1052,    80,    -1,    -1,    -1,    84,    -1,    -1,    87,
      -1,    -1,    90,    -1,    92,    -1,    -1,  1823,    -1,    -1,
      98,    -1,    -1,    -1,    -1,    -1,  1973,  1974,  1975,  1976,
    1977,   458,    -1,    -1,  1085,  1086,   114,    -1,    -1,    -1,
      -1,    -1,    -1,   121,   122,   123,   124,   125,    -1,    -1,
     128,   129,   130,   131,   132,    -1,    -1,   135,    -1,    -1,
     138,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,    -1,    -1,    -1,    -1,   220,
    1886,    -1,    -1,    -1,    -1,    -1,   227,    -1,   229,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1905,
      -1,    -1,    -1,   181,    -1,    -1,    -1,   185,    -1,    -1,
      -1,   189,   190,   191,   192,   193,  2063,     5,    -1,   197,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   211,   212,    -1,    -1,    -1,   216,    -1,
      -1,    -1,    -1,   221,    -1,    -1,    -1,    -1,   226,    -1,
     228,   229,    -1,    -1,    -1,    -1,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    -1,    -1,    -1,    -1,    57,
      58,    59,    60,    -1,    -1,    -1,    -1,    65,    66,    67,
      -1,    -1,    70,    -1,    -1,    -1,    -1,    -1,  1994,  1240,
      -1,    -1,    -1,    81,    -1,  1246,  1247,  1248,  1249,  1250,
      -1,  1252,    -1,  1254,  1255,    -1,  1257,  1258,    -1,    -1,
    1261,  1262,  1263,    -1,    -1,    -1,    -1,  1268,    -1,    -1,
       3,     4,     5,    -1,    -1,    -1,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,    -1,    12,    13,    -1,
      -1,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    -1,
      -1,    -1,    65,    66,    67,    -1,    -1,    70,    -1,    72,
      73,    74,    -1,    -1,   182,   183,   184,    80,    81,    -1,
    2106,    -1,    -1,    -1,    -1,    -1,   194,    -1,   196,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,    -1,    -1,    -1,    -1,   220,    -1,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      -1,    -1,    -1,    -1,    99,   100,   101,    -1,   103,    -1,
      -1,    -1,  1403,   108,   109,   110,   111,    -1,   113,   114,
     115,    -1,    -1,    -1,   119,    -1,    -1,    -1,  1419,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   136,    -1,    -1,    -1,  1436,    -1,    -1,    -1,    -1,
    1441,   174,    -1,    -1,    -1,    -1,    -1,    -1,   181,   182,
     183,   184,   185,   158,   159,   160,   189,   190,   191,   192,
     193,   194,    -1,   196,   197,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1473,  1474,    -1,    -1,  1477,  1478,   211,   212,
      -1,    -1,    -1,   216,    -1,    -1,    -1,    -1,   221,    -1,
     223,    -1,   225,   226,    -1,   228,    -1,   230,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,    -1,    -1,    -1,    -1,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    53,    54,    55,    56,    -1,    -1,    -1,    -1,
      61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    72,    73,    74,    -1,    -1,    -1,    -1,    -1,    80,
      -1,    -1,    -1,    84,    -1,    -1,    87,    -1,    -1,    90,
      -1,    92,    -1,    -1,    -1,    -1,    -1,    98,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1618,  1619,    -1,
      -1,  1622,  1623,   114,    -1,    -1,    -1,  1628,  1629,    -1,
     121,   122,   123,   124,   125,    -1,    -1,   128,   129,   130,
     131,   132,    -1,    -1,   135,    -1,    -1,   138,    -1,    -1,
    1027,  1028,    -1,    -1,    -1,    -1,  1033,  1034,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,    -1,    -1,    -1,    -1,   220,    -1,    -1,    -1,
      -1,    -1,    -1,   227,    -1,   229,    -1,    -1,    -1,    -1,
     181,    -1,    -1,    -1,   185,    -1,    -1,    -1,   189,   190,
     191,   192,   193,    -1,    -1,    -1,   197,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     211,   212,    -1,    -1,    -1,   216,    -1,    -1,    -1,    -1,
     221,    -1,    -1,  1734,  1735,   226,    -1,    -1,   229,    -1,
      -1,    -1,    -1,     3,     4,     5,    -1,    -1,    -1,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    -1,    -1,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    -1,    -1,    -1,    65,    66,    67,    -1,    -1,
      70,    -1,    72,    73,    74,    -1,    -1,    -1,    -1,    -1,
      80,    81,    -1,    -1,    84,    -1,    -1,    87,    -1,    -1,
      90,    -1,    92,    -1,    -1,    -1,    -1,    -1,    98,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1229,  1230,   114,    -1,    -1,  1234,  1235,    -1,
      -1,   121,   122,   123,   124,   125,    -1,    -1,   128,   129,
     130,   131,   132,    -1,    -1,   135,    -1,    -1,   138,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,    -1,    -1,    -1,    -1,   220,    -1,    -1,
      -1,    -1,    -1,    -1,   227,    -1,   229,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   181,   182,   183,   184,   185,    -1,    -1,    -1,   189,
     190,   191,   192,   193,   194,    -1,   196,   197,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   211,   212,    -1,    -1,    -1,   216,    -1,    -1,    -1,
      -1,   221,    -1,     3,     4,     5,   226,    -1,   228,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    -1,    -1,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    -1,    -1,    -1,    65,    66,    67,    -1,    -1,
      70,    -1,    72,    73,    74,    -1,    -1,    -1,    -1,    -1,
      80,    81,    -1,    -1,    84,    -1,    -1,    87,    -1,    -1,
      90,    -1,    92,    -1,    -1,    -1,    -1,    -1,    98,     4,
       5,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   114,    -1,    -1,    -1,    -1,    -1,
      -1,   121,   122,   123,   124,   125,    -1,    -1,   128,   129,
     130,   131,   132,    -1,    -1,   135,  2097,    -1,   138,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    -1,    -1,
      -1,    -1,    57,    58,    59,    60,    -1,    -1,    -1,    -1,
      65,    66,    67,    -1,    -1,    70,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    81,    -1,    -1,    -1,
      -1,   181,   182,   183,   184,   185,    -1,    -1,    -1,   189,
     190,   191,   192,   193,   194,    -1,   196,   197,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   211,   212,    -1,    -1,    -1,   216,    -1,    -1,    -1,
      -1,   221,    -1,     3,     4,     5,   226,    -1,   228,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    53,    54,    55,    56,   182,   183,   184,
      -1,    61,    -1,    -1,    -1,    -1,    -1,    12,    13,   194,
      -1,   196,    72,    73,    74,    -1,    -1,    -1,    -1,    -1,
      80,    -1,    -1,    -1,    84,    -1,    -1,    87,    -1,    -1,
      90,    -1,    92,    -1,    -1,    -1,    -1,    -1,    98,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,    -1,   114,    -1,    -1,   220,    -1,    -1,
      -1,   121,   122,   123,   124,   125,   229,    -1,   128,   129,
     130,   131,   132,    -1,    -1,   135,    -1,    -1,   138,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      -1,    -1,    -1,    -1,    99,   100,   101,    -1,   103,    -1,
      -1,    -1,    -1,   108,   109,   110,   111,    -1,   113,   114,
     115,    -1,    -1,    -1,   119,    -1,    -1,    -1,    -1,    -1,
      -1,   181,    -1,    -1,    -1,   185,    -1,    -1,    -1,   189,
     190,   191,   192,   193,    -1,    -1,    -1,   197,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   211,   212,   158,   159,   160,   216,    -1,    -1,    -1,
      -1,   221,    -1,     3,     4,     5,   226,    -1,   228,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    12,    13,   229,    65,    66,    67,    -1,    -1,
      70,    -1,    72,    73,    74,    -1,    -1,    -1,    -1,    -1,
      80,    81,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,    -1,    -1,    -1,    -1,
     220,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   229,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,    -1,    -1,    -1,    -1,   220,    -1,
      -1,    -1,   224,    -1,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    -1,    -1,    -1,    -1,    99,
     100,   101,    -1,   103,    -1,    -1,    -1,    -1,   108,   109,
     110,   111,    -1,   113,   114,   115,    -1,    -1,    -1,   119,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   181,   182,   183,   184,   185,    -1,    -1,    -1,   189,
     190,   191,   192,   193,   194,    -1,   196,   197,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   158,   159,
     160,   211,   212,    -1,    -1,    -1,   216,    -1,    -1,    -1,
      -1,   221,    -1,     3,     4,     5,   226,    -1,   228,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    53,    54,    55,    56,    -1,    -1,   229,
      -1,    61,    -1,    -1,    -1,    -1,    -1,    12,    13,    -1,
      -1,    -1,    72,    73,    74,    -1,    -1,    -1,    -1,    -1,
      80,    -1,    -1,    -1,    84,    -1,    -1,    87,    -1,    -1,
      90,    -1,    92,    -1,    -1,    -1,    -1,    -1,    98,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,    -1,   114,    -1,    -1,   220,    -1,    -1,
      -1,   121,   122,   123,   124,   125,   229,    -1,   128,   129,
     130,   131,   132,    -1,    -1,   135,    -1,    -1,   138,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      -1,    -1,    -1,    -1,    99,   100,   101,    -1,   103,    -1,
      -1,    -1,    -1,   108,   109,   110,   111,    -1,   113,   114,
     115,    -1,    -1,    -1,   119,    -1,    -1,    -1,    -1,    -1,
      -1,   181,    -1,    -1,    -1,   185,    -1,    -1,    -1,   189,
     190,   191,   192,   193,    -1,    -1,    -1,   197,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   211,   212,   158,   159,   160,   216,    -1,    -1,    -1,
      -1,   221,    -1,     3,     4,     5,   226,    -1,   228,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    -1,    -1,    -1,    65,    66,    67,    -1,    -1,
      70,    -1,    72,    73,    74,    -1,     3,     4,     5,    -1,
      80,    81,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    -1,    -1,    -1,    65,    66,
      67,    -1,    -1,    70,    -1,    72,    73,    74,    -1,    -1,
      -1,    -1,    -1,    80,    81,    -1,    -1,    -1,    -1,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,    -1,    -1,    -1,    -1,   220,    -1,    -1,
      -1,   181,   182,   183,   184,   185,   229,    -1,    -1,   189,
     190,   191,   192,   193,   194,    -1,   196,   197,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   211,   212,    -1,    -1,    -1,   216,    -1,    -1,    -1,
      -1,   221,    -1,    -1,    -1,    -1,   226,    -1,   228,    -1,
      -1,    -1,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,    -1,    -1,    -1,    -1,
     220,    -1,    -1,    -1,   181,   182,   183,   184,   185,   229,
      -1,    -1,   189,   190,   191,   192,   193,   194,    -1,   196,
     197,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   211,   212,    -1,    -1,    -1,   216,
      -1,    -1,    -1,    -1,   221,    -1,     3,     4,    -1,   226,
      -1,   228,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    53,    54,    55,    56,
      -1,    -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    72,    73,    74,    -1,    -1,
      -1,    -1,    -1,    80,    -1,    -1,    -1,    84,    -1,    -1,
      87,    -1,    -1,    90,    -1,    92,    -1,    -1,    -1,    -1,
      -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,     4,     5,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   114,    -1,    -1,
      -1,    -1,    -1,    -1,   121,   122,   123,   124,   125,    -1,
      -1,   128,   129,   130,   131,   132,    -1,    -1,   135,    -1,
      -1,   138,    -1,    -1,    -1,    -1,    -1,    -1,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    -1,    -1,    -1,
      -1,    57,    58,    59,    60,    -1,    -1,    -1,    -1,    65,
      66,    67,    -1,    -1,    70,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   181,    81,    -1,    -1,   185,    -1,
      -1,    -1,   189,   190,   191,   192,   193,    -1,    -1,    -1,
     197,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   211,   212,    -1,    -1,    -1,   216,
      -1,    -1,    -1,    -1,   221,    -1,     3,     4,    -1,   226,
      -1,   228,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    53,    54,    55,    56,
      -1,    -1,    -1,    -1,    61,    -1,   182,   183,   184,    -1,
      -1,    -1,    -1,    -1,    -1,    72,    73,    74,   194,    -1,
     196,   197,    -1,    80,    -1,    -1,    -1,    84,    -1,    -1,
      87,    -1,    -1,    90,    -1,    92,    -1,    -1,    -1,    -1,
      -1,    98,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,    -1,   114,    -1,    -1,
     220,    -1,    -1,    -1,   121,   122,   123,   124,   125,   229,
      -1,   128,   129,   130,   131,   132,    -1,    -1,   135,    -1,
      -1,   138,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,    -1,    -1,    -1,    -1,
     220,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   229,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   181,    -1,    -1,    -1,   185,    -1,
      -1,    -1,   189,   190,   191,   192,   193,    -1,    -1,    -1,
     197,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   211,   212,    -1,    -1,    -1,   216,
      -1,    -1,    -1,    -1,   221,    -1,     3,     4,    -1,   226,
      -1,   228,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    53,    54,    55,    56,
      -1,    -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    72,    73,    74,    -1,    -1,
      -1,    -1,    -1,    80,    -1,    -1,    -1,    84,    -1,    -1,
      87,    -1,    -1,    90,    -1,    92,    -1,    -1,    -1,    -1,
      -1,    98,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,    -1,   114,    -1,    -1,
     220,    -1,    -1,    -1,   121,   122,   123,   124,   125,   229,
      -1,   128,   129,   130,   131,   132,    -1,    -1,   135,    -1,
      -1,   138,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,    -1,    -1,    -1,    -1,
     220,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   229,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   181,    -1,    -1,    -1,   185,    -1,
      -1,    -1,   189,   190,   191,   192,   193,    -1,    -1,    -1,
     197,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   211,   212,    -1,    -1,    -1,   216,
      -1,    -1,    -1,    -1,   221,    -1,     3,     4,    -1,   226,
      -1,   228,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    53,    54,    55,    56,
      -1,    -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    72,    73,    74,    -1,    -1,
      -1,    -1,    -1,    80,    -1,    -1,    -1,    84,    -1,    -1,
      87,    -1,    -1,    90,    -1,    92,    -1,    -1,    -1,    -1,
      -1,    98,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,    -1,   114,    -1,    -1,
     220,    -1,    -1,    -1,   121,   122,   123,   124,   125,   229,
      -1,   128,   129,   130,   131,   132,    -1,    -1,   135,    -1,
      -1,   138,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,    -1,    -1,    -1,    -1,
     220,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   229,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   181,    -1,    -1,    -1,   185,    -1,
      -1,    -1,   189,   190,   191,   192,   193,    -1,    -1,    -1,
     197,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   211,   212,    -1,    -1,    -1,   216,
      -1,    -1,    -1,    -1,   221,    -1,     3,     4,    -1,   226,
      -1,   228,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    53,    54,    55,    56,
      -1,    -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    72,    73,    74,    -1,    -1,
      -1,    -1,    -1,    80,    -1,    -1,    -1,    84,    -1,    -1,
      87,    -1,    -1,    90,    -1,    92,    -1,    -1,    -1,    -1,
      -1,    98,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,    -1,   114,    -1,    -1,
     220,    -1,    -1,    -1,   121,   122,   123,   124,   125,   229,
      -1,   128,   129,   130,   131,   132,    -1,    -1,   135,    -1,
      -1,   138,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,    -1,    -1,    -1,    -1,
     220,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   229,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   181,    -1,    -1,    -1,   185,    -1,
      -1,    -1,   189,   190,   191,   192,   193,    -1,    -1,    -1,
     197,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   211,   212,    -1,    -1,    -1,   216,
      -1,    -1,    -1,    -1,   221,    -1,     3,     4,    -1,   226,
      -1,   228,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    53,    54,    55,    56,
      -1,    -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    72,    73,    74,    -1,    -1,
      -1,    -1,    -1,    80,    -1,    -1,    -1,    84,    -1,    -1,
      87,    -1,    -1,    90,    -1,    92,    -1,    -1,    -1,    -1,
      -1,    98,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,    -1,   114,    -1,    -1,
     220,    -1,    -1,    -1,   121,   122,   123,   124,   125,   229,
      -1,   128,   129,   130,   131,   132,    -1,    -1,   135,    -1,
      -1,   138,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,    -1,    -1,    -1,    -1,
     220,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   229,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   181,    -1,    -1,    -1,   185,    -1,
      -1,    -1,   189,   190,   191,   192,   193,    -1,    -1,    -1,
     197,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   211,   212,    -1,    -1,    -1,   216,
      -1,    -1,    -1,    -1,   221,    -1,     3,     4,    -1,   226,
      -1,   228,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    53,    54,    55,    56,
      -1,    -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    72,    73,    74,    -1,    -1,
      -1,    -1,    -1,    80,    -1,    -1,    -1,    84,    -1,    -1,
      87,    -1,    -1,    90,    -1,    92,    -1,    -1,    -1,    -1,
      -1,    98,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,    -1,   114,    -1,    -1,
     220,    -1,    -1,    -1,   121,   122,   123,   124,   125,   229,
      -1,   128,   129,   130,   131,   132,    -1,    -1,   135,    -1,
      -1,   138,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,    -1,    -1,    -1,    -1,
     220,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   229,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   181,    -1,    -1,    -1,   185,    -1,
      -1,    -1,   189,   190,   191,   192,   193,    -1,    -1,    -1,
     197,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   211,   212,    -1,    -1,    -1,   216,
      -1,    -1,    -1,    -1,   221,    -1,     3,     4,    -1,   226,
      -1,   228,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    53,    54,    55,    56,
      -1,    -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    72,    73,    74,    -1,    -1,
      -1,    -1,    -1,    80,    -1,    -1,    -1,    84,    -1,    -1,
      87,    -1,    -1,    90,    -1,    92,    -1,    -1,    -1,    -1,
      -1,    98,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,    -1,   114,    -1,    -1,
     220,    -1,    -1,    -1,   121,   122,   123,   124,   125,   229,
      -1,   128,   129,   130,   131,   132,    -1,    -1,   135,    -1,
      -1,   138,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,    -1,    -1,    -1,    -1,
     220,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   229,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   181,    -1,    -1,    -1,   185,    -1,
      -1,    -1,   189,   190,   191,   192,   193,    -1,    -1,    -1,
     197,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   211,   212,    -1,    -1,    -1,   216,
      -1,    -1,    -1,    -1,   221,    -1,     3,     4,    -1,   226,
      -1,   228,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    53,    54,    55,    56,
      -1,    -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    72,    73,    74,    -1,    -1,
      -1,    -1,    -1,    80,    -1,    -1,    -1,    84,    -1,    -1,
      87,    -1,    -1,    90,    -1,    92,    -1,    -1,    -1,    -1,
      -1,    98,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,    -1,   114,    -1,    -1,
     220,    -1,    -1,    -1,   121,   122,   123,   124,   125,   229,
      -1,   128,   129,   130,   131,   132,    -1,    -1,   135,    -1,
      -1,   138,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,    -1,    -1,    -1,    -1,
     220,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   229,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   181,    -1,    -1,    -1,   185,    -1,
      -1,    -1,   189,   190,   191,   192,   193,    -1,    -1,    -1,
     197,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   211,   212,    -1,    -1,    -1,   216,
      -1,    -1,    -1,    -1,   221,    -1,     3,     4,    -1,   226,
      -1,   228,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    53,    54,    55,    56,
      -1,    -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    72,    73,    74,    -1,    -1,
      -1,    -1,    -1,    80,    -1,    -1,    -1,    84,    -1,    -1,
      87,    -1,    -1,    90,    -1,    92,    -1,    -1,    -1,    -1,
      -1,    98,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,    -1,   114,    -1,    -1,
     220,    -1,    -1,    -1,   121,   122,   123,   124,   125,   229,
      -1,   128,   129,   130,   131,   132,    -1,    -1,   135,    -1,
      -1,   138,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,    -1,    -1,    -1,    -1,
     220,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   229,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   181,    -1,    -1,    -1,   185,    -1,
      -1,    -1,   189,   190,   191,   192,   193,    -1,    -1,    -1,
     197,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   211,   212,    -1,    -1,    -1,   216,
      -1,    -1,    -1,    -1,   221,    -1,     3,     4,    -1,   226,
      -1,   228,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      -1,    -1,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,    53,    54,    55,    56,
     220,    -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,   229,
      -1,    -1,    -1,    -1,    -1,    72,    73,    74,     3,     4,
       5,    -1,    -1,    80,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    -1,    -1,    -1,
      65,    66,    67,    -1,    -1,    70,    -1,    72,    73,    74,
      -1,    -1,    -1,    -1,    -1,    80,    81,    -1,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,    -1,    -1,    -1,    -1,   220,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   181,   229,    -1,    -1,   185,    -1,
      -1,    -1,   189,   190,   191,   192,   193,    -1,    -1,    -1,
     197,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   211,   212,    -1,    -1,    -1,   216,
      -1,    -1,    -1,    -1,   221,    -1,    -1,    -1,    -1,   226,
      -1,   228,    -1,    -1,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,    -1,    -1,
      -1,    -1,   220,    -1,    -1,    -1,   181,   182,   183,   184,
     185,   229,    -1,    -1,   189,   190,   191,   192,   193,   194,
      -1,   196,   197,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   211,   212,    -1,    -1,
      -1,   216,     3,     4,    -1,    -1,   221,    -1,     9,    10,
      11,   226,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    53,    54,    55,    56,    -1,    -1,    -1,    -1,
      61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    72,    73,    74,    -1,    -1,    -1,    -1,    -1,    80,
      -1,    -1,    -1,    84,    -1,    -1,    87,    -1,    -1,    90,
      -1,    92,    -1,    -1,    -1,    -1,    -1,    98,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,    -1,   114,    -1,    -1,   220,    -1,    -1,    -1,
     121,   122,   123,   124,   125,   229,    -1,   128,   129,   130,
     131,   132,    -1,    -1,   135,    -1,    -1,   138,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,    -1,    -1,    -1,    -1,   220,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   229,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     181,    -1,    -1,    -1,   185,    -1,    -1,    -1,   189,   190,
     191,   192,   193,    -1,    -1,    -1,   197,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     211,   212,    -1,    -1,    -1,   216,     3,     4,    -1,    -1,
     221,    -1,     9,    10,    11,   226,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      -1,    -1,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,    53,    54,    55,    56,
     220,    -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,   229,
      -1,    -1,    -1,     3,     4,    72,    73,    74,    -1,     9,
      10,    11,    -1,    80,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    -1,    -1,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,    53,    54,    55,    56,   220,    -1,    -1,
      -1,    61,    -1,    -1,    -1,    -1,   229,    -1,    -1,    -1,
      -1,    -1,    72,    73,    74,    -1,    -1,    -1,    -1,    -1,
      80,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,    -1,    -1,    -1,    -1,   220,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   229,    -1,
      -1,    -1,    -1,    -1,   181,    -1,    -1,    -1,   185,    -1,
      -1,    -1,   189,   190,   191,   192,   193,    -1,    -1,    -1,
     197,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   211,   212,    -1,    -1,    -1,   216,
      -1,    -1,    -1,    -1,   221,   222,    -1,    -1,    -1,   226,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,    -1,    -1,    -1,    -1,   220,    -1,
      -1,   181,    -1,    -1,    -1,   185,   228,    -1,    -1,   189,
     190,   191,   192,   193,    -1,    -1,    -1,   197,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   211,   212,    -1,    -1,    -1,   216,    -1,    -1,    -1,
      -1,   221,     3,     4,   224,    -1,   226,    -1,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    -1,    -1,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,    53,    54,    55,    56,   220,    -1,    -1,    -1,
      61,    -1,    -1,    -1,   228,    -1,    -1,    -1,    -1,     3,
       4,    72,    73,    74,    -1,     9,    10,    11,    -1,    80,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    -1,    -1,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,    53,
      54,    55,    56,   220,    -1,   222,    -1,    61,    -1,    -1,
     227,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,    73,
      74,    -1,    -1,    -1,    -1,    -1,    80,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,    -1,    -1,    -1,    -1,   220,    -1,   222,    -1,   224,
      -1,    -1,   227,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     181,    -1,    -1,    -1,   185,    -1,    -1,    -1,   189,   190,
     191,   192,   193,    -1,    -1,    -1,   197,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     211,   212,    -1,    -1,    -1,   216,    -1,    -1,    -1,    -1,
     221,   222,    -1,    -1,    -1,   226,    -1,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,    -1,    -1,    -1,    -1,   220,    -1,   181,    -1,    -1,
      -1,   185,   227,    -1,    -1,   189,   190,   191,   192,   193,
      -1,    -1,    -1,   197,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   211,   212,    -1,
      -1,    -1,   216,    -1,    -1,    -1,    -1,   221,     3,     4,
     224,     6,   226,    -1,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    -1,    -1,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,    53,    54,
      55,    56,   220,    -1,    -1,    -1,    61,    -1,    -1,   227,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,    73,    74,
       3,     4,    -1,     6,    -1,    80,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
      53,    54,    55,    56,   220,    -1,    -1,    -1,    61,    -1,
      -1,   227,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,
      73,    74,    -1,    -1,    -1,    -1,    -1,    80,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,    -1,    -1,    -1,    -1,   220,    -1,    -1,    -1,
      -1,    -1,    -1,   227,    -1,    -1,   181,    -1,    -1,    -1,
     185,    -1,    -1,    -1,   189,   190,   191,   192,   193,    -1,
      -1,    -1,   197,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   211,   212,    -1,    -1,
      -1,   216,    -1,    -1,    -1,    -1,   221,    -1,    -1,    -1,
      -1,   226,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,    -1,    -1,    -1,    -1,
     220,    -1,    -1,    -1,    -1,    -1,    -1,   227,   181,    -1,
      -1,    -1,   185,    -1,    -1,    -1,   189,   190,   191,   192,
     193,    -1,    -1,    -1,   197,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   211,   212,
      -1,    -1,    -1,   216,     3,     4,    -1,    -1,   221,    -1,
       9,    10,    11,   226,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    -1,    -1,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,    53,    54,    55,    56,   220,    -1,
      -1,    -1,    61,    -1,    -1,   227,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    72,    73,    74,    -1,    -1,    -1,    -1,
      -1,    80,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,    -1,    -1,    -1,    -1,
     220,    -1,    -1,    -1,    -1,    -1,    -1,   227,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,    -1,    -1,    -1,    -1,   220,    -1,    -1,    -1,
      -1,    -1,    -1,   227,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,    -1,    -1,
      -1,    -1,   220,    -1,    -1,    -1,    -1,     0,     1,   227,
      -1,     4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    12,
      13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   181,    -1,    -1,    -1,   185,    -1,    -1,    -1,
     189,   190,   191,   192,   193,    -1,    -1,    -1,   197,    42,
      43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   211,   212,    -1,    -1,    -1,   216,    -1,    62,
      63,    64,   221,    -1,    -1,    68,    69,   226,    71,    -1,
      -1,    -1,    75,    76,    -1,    78,    79,    -1,    -1,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    -1,    -1,    -1,    98,    99,   100,   101,    -1,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,    -1,   118,   119,   120,   121,   122,
     123,   124,   125,   126,    -1,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,    -1,    -1,
      -1,   144,   145,   146,    -1,    -1,    -1,    -1,    -1,   152,
       4,    -1,    -1,    -1,   157,   158,   159,   160,    12,    13,
     163,    -1,   165,    -1,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,    -1,    -1,
      -1,    -1,    -1,   186,   187,   188,    -1,    -1,    42,    43,
      -1,    -1,   195,    -1,   197,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,    63,
      64,    -1,    -1,    -1,    68,    69,    -1,    71,    -1,    -1,
      -1,    75,    76,    -1,    78,    79,    -1,    -1,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    -1,    -1,    -1,    98,    99,   100,   101,    -1,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,    -1,   118,   119,   120,   121,   122,   123,
     124,   125,   126,    -1,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,    -1,    -1,    -1,
     144,   145,   146,    -1,    -1,    -1,    -1,    -1,   152,    -1,
      -1,    -1,    -1,   157,   158,   159,   160,    -1,    -1,   163,
      -1,   165,    -1,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,    -1,    -1,    -1,
      -1,    -1,   186,   187,   188,    -1,    -1,    -1,    -1,    -1,
      -1,   195,    -1,   197,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,    -1,    -1,
      -1,    -1,   220,    -1,    -1,    -1,    -1,    -1,    -1,   227,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,    -1,    -1,    -1,    -1,   220,    -1,
      -1,    -1,    -1,    -1,    -1,   227,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
      -1,    -1,    -1,    -1,   220,    -1,    -1,    -1,    -1,    -1,
      -1,   227,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,    -1,    -1,    -1,    -1,
     220,    -1,    -1,    -1,    -1,    -1,    -1,   227,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,    -1,    -1,    -1,    -1,   220,    -1,    -1,    -1,
      -1,    -1,    -1,   227,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,    -1,    -1,
      -1,    -1,   220,    -1,    -1,    -1,    -1,    -1,    -1,   227,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,    -1,    -1,    -1,    -1,   220,    -1,
      -1,    -1,    -1,    -1,    -1,   227,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
      -1,    -1,    -1,    -1,   220,    -1,    -1,    -1,    -1,    -1,
      -1,   227,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,    -1,    -1,    -1,    -1,
     220,    -1,    -1,    -1,    -1,    -1,    -1,   227,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,    -1,    -1,    -1,    -1,   220,    -1,    -1,    -1,
      -1,    -1,    -1,   227,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,    -1,    -1,
      -1,    -1,   220,    -1,    -1,    -1,    -1,    -1,    -1,   227,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,    -1,    -1,    -1,    -1,   220,    -1,
      -1,    -1,    -1,    -1,    -1,   227,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
      -1,    -1,    -1,    -1,   220,    -1,    -1,    -1,    -1,    -1,
      -1,   227,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,    -1,    -1,    -1,    -1,
     220,    -1,    -1,    -1,    -1,    -1,    -1,   227,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,    -1,    -1,    -1,    -1,   220,    -1,    -1,    -1,
      -1,    -1,    -1,   227,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,    -1,    -1,
      -1,    -1,   220,    -1,    -1,    -1,    -1,    -1,    -1,   227,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,    -1,    -1,    -1,    -1,   220,    -1,
      -1,    -1,    -1,    -1,    -1,   227,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
      -1,    -1,    -1,    -1,   220,    -1,    -1,    -1,    -1,    -1,
      -1,   227,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,    -1,    -1,    -1,    -1,
     220,    -1,    -1,    -1,    -1,    -1,    -1,   227,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,    -1,    -1,    -1,    -1,   220,    -1,    -1,    -1,
      -1,    -1,    -1,   227,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,    -1,    -1,
      -1,    -1,   220,    -1,    -1,    -1,    -1,    -1,    -1,   227,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,    -1,    -1,    -1,    -1,   220,    -1,
      -1,    -1,    -1,    -1,    -1,   227,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
      -1,    -1,    -1,    -1,   220,    -1,    -1,    -1,    -1,    -1,
      -1,   227,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,    -1,    -1,    -1,    -1,
     220,    -1,    -1,    -1,    -1,    -1,    -1,   227,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,    -1,    -1,    -1,    -1,   220,    -1,    -1,    -1,
      -1,    -1,    -1,   227,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,    -1,    -1,
      -1,    -1,   220,    -1,    -1,    -1,    -1,    -1,    -1,   227,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,    -1,    -1,    -1,    -1,   220,    -1,
      -1,    -1,    -1,    -1,    -1,   227,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
      -1,    -1,    -1,    -1,   220,    -1,    -1,    -1,    -1,    -1,
      -1,   227,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,    -1,    -1,    -1,    -1,
     220,    -1,    -1,    -1,    -1,    -1,    -1,   227,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,    -1,    -1,    -1,    -1,   220,    -1,    -1,    -1,
      -1,    -1,    -1,   227,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,    -1,    -1,
      -1,    -1,   220,    -1,    -1,    -1,    -1,    -1,    -1,   227,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,    -1,    -1,    -1,    -1,   220,    -1,
      -1,    -1,    -1,    -1,    -1,   227,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
      -1,    -1,    -1,    -1,   220,    -1,    -1,    -1,    -1,    -1,
      -1,   227,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,    -1,    -1,    -1,    -1,
     220,    -1,    -1,    -1,    -1,    -1,    -1,   227,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,    -1,    -1,    -1,    -1,   220,    -1,    -1,    -1,
      -1,    -1,    -1,   227,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,    -1,    -1,
      -1,    -1,   220,    -1,    -1,    -1,    -1,    -1,    -1,   227,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,    -1,    -1,    -1,    -1,   220,    -1,
      -1,    -1,    -1,    -1,    -1,   227,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
      -1,    -1,    -1,    -1,   220,    -1,    -1,    -1,    -1,    -1,
      -1,   227,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,    -1,    -1,    -1,    -1,
     220,    -1,    -1,    -1,    -1,    -1,    -1,   227,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,    -1,    -1,    -1,    -1,   220,    -1,    -1,    -1,
      -1,    -1,    -1,   227,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,    -1,    -1,
      -1,    -1,   220,    -1,    -1,    -1,    -1,    -1,    -1,   227,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,    -1,    -1,    -1,    -1,   220,    -1,
      -1,    -1,    -1,    -1,    -1,   227,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
      -1,    -1,    -1,    -1,   220,    -1,    -1,    -1,    -1,    -1,
      -1,   227,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,    -1,    -1,    -1,    -1,
     220,    -1,    -1,    -1,    -1,    -1,    -1,   227,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,    -1,    -1,    -1,    -1,   220,    -1,    -1,    -1,
      -1,    -1,    -1,   227,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,    -1,    -1,
      -1,    -1,   220,    -1,    -1,    -1,    -1,    -1,    -1,   227,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,    -1,    -1,    -1,    -1,   220,    -1,
      -1,    -1,   224,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,    -1,    -1,    -1,
      -1,   220,    -1,    -1,    -1,   224,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
      -1,    -1,    -1,    -1,   220,    -1,    -1,    -1,   224,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,    -1,    -1,    -1,    -1,   220,    -1,    -1,
      -1,   224,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,    -1,    -1,    -1,    -1,
     220,    -1,    -1,    -1,   224,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,    -1,
      -1,    -1,    -1,   220,    -1,    -1,    -1,   224,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,    -1,    -1,    -1,    -1,   220,    -1,    -1,    -1,
     224,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,    -1,    -1,    -1,    -1,   220,
      -1,    -1,    -1,   224,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,    -1,    -1,
      -1,    -1,   220,    -1,    -1,    -1,   224,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,    -1,    -1,    -1,    -1,   220,    -1,    -1,    -1,   224,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,    -1,    -1,    -1,    -1,   220,    -1,
      -1,    -1,   224,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,    -1,    -1,    -1,
      -1,   220,    -1,    -1,    -1,   224,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
      -1,    -1,    -1,    -1,   220,    -1,    -1,    -1,   224,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,    -1,    -1,    -1,    -1,   220,    -1,    -1,
      -1,   224,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,    -1,    -1,    -1,    -1,
     220,    -1,    -1,    -1,   224,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,    -1,
      -1,    -1,    -1,   220,    -1,    -1,    -1,   224,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,    -1,    -1,    -1,    -1,   220,    -1,   222,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,    -1,    -1,    -1,    -1,   220,    -1,   222,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,    -1,    -1,    -1,    -1,   220,    -1,
     222,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,    -1,    -1,    -1,    -1,   220,
      -1,   222,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,    -1,    -1,    -1,    -1,
     220,    -1,   222,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,    -1,    -1,    -1,
      -1,   220,    -1,   222,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,    -1,    -1,
      -1,    -1,   220,    -1,   222,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,    -1,
      -1,    -1,    -1,   220,    -1,   222,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
      -1,    -1,    -1,    -1,   220,    -1,   222,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,    -1,    -1,    -1,    -1,   220,    -1,   222,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,    -1,    -1,    -1,    -1,   220,    -1,   222,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,    -1,    -1,    -1,    -1,   220,    -1,   222,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,    -1,    -1,    -1,    -1,   220,    -1,
     222,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,    -1,    -1,    -1,    -1,   220,
      -1,   222,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,    -1,    -1,    -1,    -1,
     220,    -1,   222,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,    -1,    -1,    -1,
      -1,   220,    -1,   222,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,    -1,    -1,
      -1,    -1,   220,    -1,   222,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,    -1,
      -1,    -1,    -1,   220,    -1,   222,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
      -1,    -1,    -1,    -1,   220,    -1,   222,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,    -1,    -1,    -1,    -1,   220,    -1,   222,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,    -1,    -1,    -1,    -1,   220,    -1,   222,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,    -1,    -1,    -1,    -1,   220,    -1,   222,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,    -1,    -1,    -1,    -1,   220,    -1,
     222,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,    -1,    -1,    -1,    -1,   220,
      -1,   222,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,    -1,    -1,    -1,    -1,
     220,    -1,   222,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,    -1,    -1,    -1,
      -1,   220,    -1,   222,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,    -1,    -1,
      -1,    -1,   220,    -1,   222,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,    -1,
      -1,    -1,    -1,   220,    -1,   222,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
      -1,    -1,    -1,    -1,   220,    -1,   222,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,    -1,    -1,    -1,    -1,   220,    -1,   222,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,    -1,    -1,    -1,    -1,   220,    -1,   222,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,    -1,    -1,    -1,    -1,   220,    -1,   222,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,    -1,    -1,    -1,    -1,   220,    -1,
     222,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,    -1,    -1,    -1,    -1,   220,
      -1,   222,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,    -1,    -1,    -1,    -1,
     220,    -1,   222,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,    -1,    -1,    -1,
      -1,   220,    -1,   222,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,    -1,    -1,
      -1,    -1,   220,    -1,   222,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,    -1,
      -1,    -1,    -1,   220,    -1,   222,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
      -1,    -1,    -1,    -1,   220,    -1,   222,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,    -1,    -1,    -1,    -1,   220,    -1,   222,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,    -1,    -1,    -1,    -1,   220,    -1,   222,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,    -1,    -1,    -1,    -1,   220,    -1,   222,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,    -1,    -1,    -1,    -1,   220,    -1,
     222,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,    -1,    -1,    -1,    -1,   220,
      -1,   222,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,    -1,    -1,    -1,    -1,
     220,    -1,   222,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,    -1,    -1,    -1,
      -1,   220,    -1,   222,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,    -1,    -1,
      -1,    -1,   220,    -1,   222,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,    -1,
      -1,    -1,    -1,   220,    -1,   222,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
      -1,    -1,    -1,    -1,   220,    -1,   222,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,    -1,    -1,    -1,    -1,   220,    -1,   222,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,    -1,    -1,    -1,    -1,   220,    -1,   222,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,    -1,    -1,    -1,    -1,   220,    -1,   222
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,   232,   233,     6,     0,     4,    12,    13,    42,
      43,    62,    63,    64,    68,    69,    71,    75,    76,    78,
      79,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    98,    99,   100,   101,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   144,   145,   146,   152,   157,   158,
     159,   160,   163,   165,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   186,   187,
     188,   195,   197,   234,   236,   237,   257,   276,   277,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   304,   306,
     307,   313,   314,   315,   316,   334,   335,     3,     4,     5,
       9,    10,    11,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    65,    66,    67,    70,    72,    73,
      74,    80,    81,   174,   181,   182,   183,   184,   185,   189,
     190,   191,   192,   193,   194,   196,   211,   212,   216,   221,
     223,   225,   226,   228,   230,   255,   317,   318,   330,   331,
     334,   335,    13,    90,   221,   221,     6,   228,     6,     6,
       6,     6,   221,     6,     6,   223,   223,   221,   223,   255,
     255,   221,   228,   221,   221,     4,   221,   228,   221,   221,
       4,   228,   221,   221,   221,   221,   221,   221,   221,   102,
      90,    90,     6,   228,    84,    87,    90,   221,   221,    90,
      90,    87,    90,    92,    92,    84,    87,    90,    92,    87,
      90,    92,    87,    90,   221,    87,   163,   179,   180,   228,
     211,   212,   221,   228,   320,   321,   320,   228,    84,    87,
      90,   228,   320,     4,    84,    88,    94,    95,    96,    97,
     110,    90,    92,    90,    87,     4,   174,   228,   334,   335,
       4,     6,    84,    87,    90,    87,    90,     4,     4,     4,
       4,     5,    37,    38,    39,    40,    41,    84,    87,    90,
      92,   114,   212,   221,   228,   277,   288,   304,   306,   317,
     323,   324,   325,   334,   335,     4,   221,   221,   221,     4,
     228,   327,   335,     4,   221,   221,   221,     6,     6,   223,
       4,   331,   335,   221,     4,   331,     5,   228,     5,   228,
       4,   317,   334,   223,   221,   228,     6,   221,   228,   221,
     223,   230,   255,     7,   198,   199,   200,   201,   218,   219,
     253,   254,     4,   221,   223,   225,   255,   255,   255,   255,
     255,   255,   255,   255,   255,   255,   255,   255,   255,   255,
     255,   255,   255,   255,   255,   255,   255,   255,   255,   255,
     255,   221,   221,   221,   255,   255,   255,   255,   221,   255,
     255,   255,   255,   255,   255,   221,   255,   255,   255,     7,
     221,   221,   221,   255,   255,   221,   221,   223,   317,   317,
     317,   222,   317,   224,   317,     4,   163,   164,   335,     4,
     277,   278,   279,   228,   228,     6,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     220,   228,     6,   221,   223,   254,     6,   317,     4,   330,
     331,   334,   335,   330,   317,   330,   333,   259,   264,   331,
     335,   317,   212,   317,   325,   326,   317,   317,   221,   317,
     326,   317,   317,   221,   326,   317,   317,   317,   317,   330,
     317,   317,   323,   221,   228,   326,   324,   324,   324,   330,
     317,   221,   221,   324,   324,   324,   221,   221,   221,   221,
     221,   221,   323,   221,   323,   221,   323,   228,   228,   317,
       4,   323,   327,   228,   228,   320,   320,   320,   317,   317,
     211,   212,   228,   228,   320,   228,   228,   228,   211,   212,
     221,   279,   320,   228,   221,   228,   221,   221,   221,   221,
     221,   221,   221,   324,   324,   323,   221,     4,   223,   223,
     279,     6,     6,   228,   228,   228,   324,   324,   223,   223,
     223,   221,   223,   225,   255,   221,   223,   255,   255,   255,
     255,     5,   166,   228,     5,   166,     5,   166,     5,   166,
      84,    87,    90,    92,   228,   317,   325,   317,   229,   326,
       8,   213,     6,   221,   223,   255,     6,   317,   317,   317,
     225,   317,   228,   166,   317,   317,   317,   317,     6,     6,
     228,     6,   279,     6,   279,   221,   223,   228,   221,   223,
     330,   317,   279,   323,   323,   222,   317,   224,   317,   228,
     228,   331,   323,     6,   223,   317,   317,     4,   317,   317,
     317,   317,   317,   317,   317,   317,   317,   317,   317,   317,
     317,   317,   317,   317,   317,   317,   317,   317,   317,   317,
     333,   330,   333,   330,   330,   330,   330,   330,   330,   330,
     323,   330,   330,   317,   330,   330,   330,   333,   330,   317,
     331,   317,   330,   330,   330,   330,   330,   335,   331,   335,
       7,   201,   253,   222,     7,   201,   253,   224,     7,   253,
     254,   225,     7,   255,   229,    84,    87,    90,    92,   276,
     317,   326,   317,   317,   317,   317,   317,   317,   317,   317,
     317,   317,   317,   317,   317,   317,   317,   238,   317,   317,
       6,   221,   223,   225,   222,   227,   221,   223,   222,   227,
     227,   222,   227,   224,   227,   258,   224,   258,   227,   227,
     222,   213,   227,   229,   222,   222,   317,   222,   229,   222,
     222,   317,   229,   222,   222,   222,   222,   222,   222,   222,
       7,   317,   317,   229,     6,     6,     6,   222,   222,   317,
     317,     7,     7,   310,   310,   317,   270,   317,   331,   271,
     317,   331,   272,   317,   331,   273,   317,   331,   317,     6,
     317,     6,   317,     6,   326,   326,   228,   222,     6,   228,
     279,   279,   227,   227,   227,   320,   320,   278,   278,   227,
     317,   317,   317,   317,   292,   227,   279,   317,   317,   317,
     317,   317,   317,   317,   317,   317,     7,   311,     6,     7,
     317,     6,   317,   317,   229,   326,   326,   326,     6,     6,
     317,   317,   317,   317,   317,     4,   222,   224,   228,   256,
     228,   317,   325,   228,   325,   335,   317,   317,   330,   317,
      62,   317,    62,    62,    62,     5,   228,     5,   228,     5,
     228,     5,   228,   326,   222,   229,   317,   228,   317,   325,
     317,   317,   228,   256,   222,   222,   222,   163,   227,   279,
     228,     8,   222,   222,   224,   326,   229,   229,   279,   224,
     222,   136,   305,   222,   227,   229,     7,   201,   253,   222,
       7,   201,   253,   224,   317,   326,     6,     6,   317,   222,
     224,   254,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   227,   256,   256,   256,   256,   256,   256,
     256,   227,   227,   227,   256,   227,   256,   256,   222,   222,
     227,   256,   256,   227,   256,   227,   227,   227,   227,   256,
     256,   256,   222,   256,   319,   332,     6,   227,   227,   222,
     227,   256,   227,   256,   222,   222,   224,    44,    44,   323,
       7,   253,   254,    44,    44,   323,   225,   253,   254,   331,
     317,     6,     4,     4,   228,   328,   256,   228,   228,   228,
     228,   229,   229,     8,     4,   153,   154,   155,   156,   229,
     241,   245,   248,   250,   251,   222,   224,   317,   317,     4,
       6,   208,   235,   326,   317,   317,     6,   326,   317,     6,
     330,     6,   335,     6,   330,   317,   331,     7,   317,   325,
     166,     7,     7,   222,     7,   166,     7,     7,   222,   166,
       7,     7,     7,     7,     7,     7,   317,   222,   229,   228,
       6,     7,   222,   222,   317,   323,     4,   309,     6,   222,
     222,   227,   222,   227,   222,   227,   222,   227,   222,   222,
     222,   229,   229,   326,   225,   279,   229,   229,   320,   317,
     317,   229,   229,   317,   320,   227,   227,   227,   117,   133,
     141,   142,   143,   147,   148,   149,   150,   302,   303,   320,
     229,   289,   222,   229,   222,   222,   222,   222,   222,   222,
     222,   317,     6,   317,   222,   224,   224,   229,   229,   229,
     224,   224,   227,   222,   224,   326,   326,   222,   326,   224,
     224,   227,   227,   256,   227,   228,   229,   228,   228,   228,
     326,   326,   326,   326,   229,     8,   326,   222,   224,   326,
       7,     7,     7,   225,   317,   229,   317,   317,     7,   225,
     229,   229,     7,     6,   317,   229,   228,   323,     6,    44,
      44,   323,   253,   254,    44,    44,   323,   253,   254,   229,
     229,   224,   254,   225,   254,   330,   317,   317,   317,   317,
     326,   330,   317,   323,   330,   330,   330,   266,   268,   317,
     330,   330,   317,   255,   255,     6,   317,     6,   255,   255,
       6,     4,   163,   164,   317,     6,     6,     6,     7,   223,
     327,   329,     6,   326,   326,   326,   326,   256,   317,   242,
     221,   221,   228,   252,     6,   254,   254,   222,   224,   208,
     330,   222,   222,   224,   222,   227,     7,   221,   223,   256,
     256,   320,    90,    92,   323,   323,     7,   323,    90,    92,
     323,   323,     7,    92,   323,   323,   323,   323,   323,   323,
       6,     7,     7,   326,   323,     7,     7,   117,   308,     6,
       7,   253,   317,   253,   317,   253,   317,   253,   317,     7,
       7,     7,     7,     7,   229,     4,   229,   227,   227,   227,
     229,   229,   320,   320,   320,     4,     6,   317,   228,     6,
     221,     6,   151,     6,   151,     6,   151,     6,   151,   229,
     303,   227,   302,     7,     6,     7,     7,     7,     7,     7,
       7,     7,     6,   228,     6,     6,     6,    90,     7,     6,
       6,   317,   225,   229,   229,   229,   317,   317,   317,   317,
     317,   317,   317,   229,   229,   229,   229,   317,   229,   229,
     323,   323,   323,     4,   227,     8,     8,   222,     4,     4,
     227,   228,     6,   228,   323,   229,   255,   255,     6,   317,
       6,   255,   255,     6,   317,     6,   256,     6,     4,     6,
     256,   256,   256,   256,   256,   227,   227,   256,   222,   256,
     256,   227,   227,   256,   267,   227,   256,   269,   222,   222,
     256,   256,   256,   333,   333,     6,   256,   333,   333,     7,
     253,   254,   225,     7,     6,   327,   317,   227,   229,   229,
     229,   229,   229,   253,   221,   317,   317,   322,   323,   228,
     225,     6,     6,   235,     6,   317,   228,   317,   331,   222,
     224,     6,     6,     6,   228,   228,   110,   275,   275,   323,
       6,   228,   228,     6,     6,   323,   228,     6,     6,     6,
       6,     6,     6,     5,   323,   229,     6,   323,   323,     4,
       6,   323,   323,   323,   323,   323,   323,   323,   323,   228,
     228,     7,     6,     7,   317,   317,   317,   228,   228,   227,
     229,   227,   229,   227,   229,   223,     6,   317,   323,   317,
       6,     6,     6,     6,   317,   320,   229,     5,   323,   228,
     228,   228,   228,   228,   228,   228,   323,   326,   228,   317,
     224,     4,   256,   222,   224,   227,   227,   227,   227,   227,
     227,   227,   256,     6,     6,   162,   317,   317,   317,     6,
       6,     7,   331,   279,   279,   227,     6,   256,   333,   333,
       6,   256,   333,   333,     6,   253,   254,   330,   317,   330,
       4,     4,   178,     6,   256,   256,     6,   256,   256,   331,
     317,     6,     4,   328,     6,   224,   327,     6,     6,     6,
       6,   323,   239,   317,   227,   227,   227,   229,   240,   317,
       4,   330,   227,   323,   331,     7,     7,   317,   317,   320,
       6,     6,     6,   317,   317,     6,   317,     5,     6,   228,
       6,   166,   274,   317,     6,     6,     6,     6,     6,     6,
       4,     6,     6,   326,   326,   317,   317,   331,   229,   222,
     227,   229,   278,   278,   320,     6,   293,   320,     6,   294,
     320,     6,   295,   317,   229,   227,   222,   229,   227,     6,
       6,   322,   320,   320,   320,   320,   320,   212,   320,     6,
     229,   317,     6,     6,   317,   317,   317,   317,   317,   317,
     317,   323,   227,   229,     8,   229,   222,   228,   317,   331,
     227,   305,   305,   323,     6,   256,   256,     6,   256,   256,
     323,   222,   256,   256,   228,   323,   331,   228,   317,   331,
     331,     6,     6,     6,     6,     6,     6,     7,     6,   225,
       6,   222,   227,   317,   317,   323,   228,   227,   229,     6,
     317,   260,   263,   228,   228,   229,   229,   229,   229,   229,
       5,   322,    88,     6,   228,   229,   229,   228,     6,     6,
     228,   317,   229,   229,   227,   228,   227,   228,   227,   228,
     224,     6,   323,     7,   228,   317,   229,   227,   227,   227,
     227,   227,   227,     6,   229,   256,   256,   227,   227,   227,
     227,   227,   161,   317,   317,   326,     6,     6,   331,   229,
     229,   229,     6,     6,     6,     6,     6,   265,   317,   325,
     333,   327,   164,   243,   317,   227,   227,   322,   317,     6,
     227,   266,   268,   323,   323,     6,     6,     6,     6,     6,
       6,   229,   228,   322,   121,   122,   127,   312,   121,   122,
     312,   326,   278,   227,   229,   317,   320,   302,   317,   320,
     302,   317,   320,   302,     6,   227,   229,   323,   279,   229,
       6,   326,   320,   320,   320,   320,   320,   317,   317,   317,
     317,   317,   317,   229,   229,   229,   222,   228,     6,   227,
     229,     7,     7,   229,     6,   228,   317,   317,   229,   317,
     229,   229,   262,   261,   228,   317,   229,   228,   320,   323,
       6,   228,   320,     6,   229,   229,   317,   229,   227,   229,
     229,   227,   229,   229,   227,   229,   323,     6,   117,   229,
     290,   228,   229,   227,   227,   227,   227,   227,   227,   227,
     227,   227,   227,     6,     6,     6,   279,   317,   331,   335,
     240,   222,   227,     6,   228,   227,   266,   266,   317,   229,
       6,   320,     6,   320,     6,     6,   229,     6,   296,   317,
       6,     6,   297,   317,     6,     6,   298,   317,     6,   229,
     317,   302,   279,     6,   326,   326,   326,   326,   320,   326,
     317,   317,   317,   317,   317,   305,     7,   221,   229,   246,
     317,   322,   317,   229,   229,   227,   227,   227,   228,   229,
     228,   229,   228,   229,     6,     6,   229,   229,   291,   229,
     229,   229,   229,   227,   229,   227,   227,   227,   227,   227,
     229,   331,   222,     6,   228,   222,   229,   229,   317,   320,
     320,   302,     6,   299,   302,     6,   300,   302,     6,   301,
     302,     6,     6,     6,     6,   326,     6,   317,   317,   317,
     317,   317,     6,   244,   330,   249,   228,     6,   229,   227,
     227,   229,   228,   229,   228,   229,   228,   229,   229,   256,
     227,   227,   227,   227,   227,   229,   228,   322,     6,   317,
     317,     6,   302,     6,   302,     6,   302,     6,   317,   317,
     317,   317,   330,     6,   247,   330,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   227,   229,     6,     6,
       6,     6,     6,     6,   330,     6
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
          GModel::current()->getOCCInternals()->addRuledFace(num, wires);
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
#line 2217 "Gmsh.y"
    {
      myGmshSurface = 0;
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 189:
#line 2223 "Gmsh.y"
    {
      myGmshSurface = gmshSurface::getSurface((int)(yyvsp[(3) - (4)].d));
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 190:
#line 2229 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (10)].d);
      myGmshSurface = gmshParametricSurface::NewParametricSurface(num, (yyvsp[(7) - (10)].c), (yyvsp[(8) - (10)].c), (yyvsp[(9) - (10)].c));
      (yyval.s).Type = 0;
      (yyval.s).Num = num;
    ;}
    break;

  case 191:
#line 2236 "Gmsh.y"
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
#line 2277 "Gmsh.y"
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
#line 2303 "Gmsh.y"
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
#line 2327 "Gmsh.y"
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

  case 195:
#line 2352 "Gmsh.y"
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

  case 196:
#line 2375 "Gmsh.y"
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

  case 197:
#line 2400 "Gmsh.y"
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

  case 198:
#line 2427 "Gmsh.y"
    {
      GModel::current()->getGEOInternals()->addCompoundMesh ( 2 , (yyvsp[(3) - (4)].l) );
    ;}
    break;

  case 199:
#line 2431 "Gmsh.y"
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

  case 200:
#line 2451 "Gmsh.y"
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

  case 201:
#line 2484 "Gmsh.y"
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

  case 202:
#line 2531 "Gmsh.y"
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

  case 203:
#line 2549 "Gmsh.y"
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

  case 204:
#line 2576 "Gmsh.y"
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

  case 205:
#line 2594 "Gmsh.y"
    {
      GModel::current()->getGEOInternals()->addCompoundMesh(3, (yyvsp[(3) - (4)].l));
    ;}
    break;

  case 206:
#line 2598 "Gmsh.y"
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

  case 207:
#line 2614 "Gmsh.y"
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

  case 208:
#line 2662 "Gmsh.y"
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

  case 209:
#line 2679 "Gmsh.y"
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

  case 210:
#line 2697 "Gmsh.y"
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

  case 211:
#line 2707 "Gmsh.y"
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

  case 212:
#line 2717 "Gmsh.y"
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

  case 213:
#line 2727 "Gmsh.y"
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

  case 214:
#line 2790 "Gmsh.y"
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

  case 215:
#line 2801 "Gmsh.y"
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

  case 216:
#line 2816 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 217:
#line 2817 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 218:
#line 2822 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    ;}
    break;

  case 219:
#line 2826 "Gmsh.y"
    {
      List_Add((yyval.l), &(yyvsp[(2) - (2)].s));
    ;}
    break;

  case 220:
#line 2830 "Gmsh.y"
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

  case 221:
#line 2859 "Gmsh.y"
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

  case 222:
#line 2888 "Gmsh.y"
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

  case 223:
#line 2917 "Gmsh.y"
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

  case 224:
#line 2951 "Gmsh.y"
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

  case 225:
#line 2973 "Gmsh.y"
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

  case 226:
#line 3000 "Gmsh.y"
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

  case 227:
#line 3022 "Gmsh.y"
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

  case 228:
#line 3044 "Gmsh.y"
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

  case 229:
#line 3066 "Gmsh.y"
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

  case 230:
#line 3122 "Gmsh.y"
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

  case 231:
#line 3146 "Gmsh.y"
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

  case 232:
#line 3171 "Gmsh.y"
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

  case 233:
#line 3196 "Gmsh.y"
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

  case 234:
#line 3309 "Gmsh.y"
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

  case 235:
#line 3328 "Gmsh.y"
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

  case 236:
#line 3371 "Gmsh.y"
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

  case 237:
#line 3392 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      GModel::current()->getFields()->deleteField((int)(yyvsp[(4) - (6)].d));
#endif
    ;}
    break;

  case 238:
#line 3398 "Gmsh.y"
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

  case 239:
#line 3413 "Gmsh.y"
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

  case 240:
#line 3441 "Gmsh.y"
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

  case 241:
#line 3458 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(4) - (5)].l), i, &TheShape);
	ColorShape(TheShape.Type, TheShape.Num, (yyvsp[(2) - (5)].u), false);
      }
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 242:
#line 3467 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(5) - (6)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(5) - (6)].l), i, &TheShape);
	ColorShape(TheShape.Type, TheShape.Num, (yyvsp[(3) - (6)].u), true);
      }
      List_Delete((yyvsp[(5) - (6)].l));
    ;}
    break;

  case 243:
#line 3481 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(4) - (5)].l), i, &TheShape);
	SetPartition(TheShape.Type, TheShape.Num, (yyvsp[(2) - (5)].d));
      }
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 244:
#line 3495 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 1, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 245:
#line 3501 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 0, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 246:
#line 3507 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 1, false);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 247:
#line 3516 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(4) - (5)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 1, true);
      }
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 248:
#line 3525 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 0, false);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 249:
#line 3534 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(4) - (5)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 0, true);
      }
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 250:
#line 3548 "Gmsh.y"
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

  case 251:
#line 3610 "Gmsh.y"
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

  case 252:
#line 3628 "Gmsh.y"
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

  case 253:
#line 3645 "Gmsh.y"
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

  case 254:
#line 3660 "Gmsh.y"
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

  case 255:
#line 3689 "Gmsh.y"
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

  case 256:
#line 3701 "Gmsh.y"
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

  case 257:
#line 3725 "Gmsh.y"
    {
      Msg::Exit(0);
    ;}
    break;

  case 258:
#line 3729 "Gmsh.y"
    {
      gmsh_yyerrorstate = 999; // this will be checked when yyparse returns
      YYABORT;
    ;}
    break;

  case 259:
#line 3734 "Gmsh.y"
    {
      // FIXME: this is a hack to force a transfer from the old DB to
      // the new DB. This will become unnecessary if/when we fill the
      // GModel directly during parsing.
      GModel::current()->importGEOInternals();
      GModel::current()->importOCCInternals();
    ;}
    break;

  case 260:
#line 3742 "Gmsh.y"
    {
      new GModel();
      GModel::current(GModel::list.size() - 1);
    ;}
    break;

  case 261:
#line 3747 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 0;
      GModel::current()->importGEOInternals();
      SetBoundingBox();
    ;}
    break;

  case 262:
#line 3753 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 1;
      SetBoundingBox((yyvsp[(3) - (15)].d), (yyvsp[(5) - (15)].d), (yyvsp[(7) - (15)].d), (yyvsp[(9) - (15)].d), (yyvsp[(11) - (15)].d), (yyvsp[(13) - (15)].d));
    ;}
    break;

  case 263:
#line 3758 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
      drawContext::global()->draw();
#endif
    ;}
    break;

  case 264:
#line 3764 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
     CTX::instance()->mesh.changed = ENT_ALL;
     for(unsigned int index = 0; index < PView::list.size(); index++)
       PView::list[index]->setChanged(true);
#endif
    ;}
    break;

  case 265:
#line 3772 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh();
    ;}
    break;

  case 266:
#line 3776 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh(1);
    ;}
    break;

  case 267:
#line 3780 "Gmsh.y"
    {
      GModel::current()->importGEOInternals();
      GModel::current()->refineMesh(CTX::instance()->mesh.secondOrderLinear);
    ;}
    break;

  case 268:
#line 3786 "Gmsh.y"
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

  case 269:
#line 3845 "Gmsh.y"
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

  case 270:
#line 3861 "Gmsh.y"
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

  case 271:
#line 3878 "Gmsh.y"
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

  case 272:
#line 3895 "Gmsh.y"
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

  case 273:
#line 3917 "Gmsh.y"
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

  case 274:
#line 3939 "Gmsh.y"
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

  case 275:
#line 3974 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip_until(NULL, "Return");
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 276:
#line 3982 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip_until(NULL, "Return");
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 277:
#line 3990 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    ;}
    break;

  case 278:
#line 3996 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 279:
#line 4003 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 280:
#line 4010 "Gmsh.y"
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

  case 281:
#line 4030 "Gmsh.y"
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

  case 282:
#line 4056 "Gmsh.y"
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

  case 283:
#line 4068 "Gmsh.y"
    {
      ImbricatedTest--;
      if(ImbricatedTest < 0)
        yymsg(1, "Orphan EndIf");
    ;}
    break;

  case 284:
#line 4080 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (5)].l),
		    (yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    NULL, (yyval.l));
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 285:
#line 4088 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[(10) - (11)].l),
		    0., 0., 0., (yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(7) - (11)].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[(10) - (11)].l));
    ;}
    break;

  case 286:
#line 4096 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (13)].l),
		    (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].v)[0], (yyvsp[(7) - (13)].v)[1], (yyvsp[(7) - (13)].v)[2], (yyvsp[(9) - (13)].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[(12) - (13)].l));
    ;}
    break;

  case 287:
#line 4104 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 288:
#line 4110 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (7)].l),
		    (yyvsp[(2) - (7)].v)[0], (yyvsp[(2) - (7)].v)[1], (yyvsp[(2) - (7)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(4) - (7)].l));
    ;}
    break;

  case 289:
#line 4118 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 290:
#line 4124 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[(10) - (13)].l),
		    0., 0., 0., (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(10) - (13)].l));
    ;}
    break;

  case 291:
#line 4132 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 292:
#line 4138 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (15)].l),
		    (yyvsp[(3) - (15)].v)[0], (yyvsp[(3) - (15)].v)[1], (yyvsp[(3) - (15)].v)[2], (yyvsp[(5) - (15)].v)[0], (yyvsp[(5) - (15)].v)[1], (yyvsp[(5) - (15)].v)[2], (yyvsp[(7) - (15)].v)[0], (yyvsp[(7) - (15)].v)[1], (yyvsp[(7) - (15)].v)[2], (yyvsp[(9) - (15)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(12) - (15)].l));
    ;}
    break;

  case 293:
#line 4146 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 294:
#line 4152 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(BOUNDARY_LAYER, (yyvsp[(3) - (6)].l), 0., 0., 0., 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(3) - (6)].l));
    ;}
    break;

  case 295:
#line 4160 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 296:
#line 4167 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 297:
#line 4174 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 298:
#line 4181 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 299:
#line 4188 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 300:
#line 4195 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 301:
#line 4202 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 302:
#line 4209 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 303:
#line 4216 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 304:
#line 4223 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 305:
#line 4229 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 306:
#line 4236 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 307:
#line 4242 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 308:
#line 4249 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 309:
#line 4255 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 310:
#line 4262 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 311:
#line 4268 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 312:
#line 4275 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 313:
#line 4281 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 314:
#line 4288 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 315:
#line 4294 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 316:
#line 4301 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 317:
#line 4307 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 318:
#line 4314 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 319:
#line 4320 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 320:
#line 4327 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 321:
#line 4333 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 322:
#line 4344 "Gmsh.y"
    {
    ;}
    break;

  case 323:
#line 4347 "Gmsh.y"
    {
    ;}
    break;

  case 324:
#line 4353 "Gmsh.y"
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

  case 325:
#line 4365 "Gmsh.y"
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

  case 326:
#line 4385 "Gmsh.y"
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

  case 327:
#line 4409 "Gmsh.y"
    {
      extr.mesh.ScaleLast = true;
    ;}
    break;

  case 328:
#line 4413 "Gmsh.y"
    {
      extr.mesh.Recombine = true;
    ;}
    break;

  case 329:
#line 4417 "Gmsh.y"
    {
      extr.mesh.Recombine = (yyvsp[(2) - (3)].d) ? true : false;
    ;}
    break;

  case 330:
#line 4421 "Gmsh.y"
    {
      yymsg(0, "Keyword 'QuadTriSngl' deprecated. Use 'QuadTriNoNewVerts' instead.");
    ;}
    break;

  case 331:
#line 4425 "Gmsh.y"
    {
      yymsg(0, "Keyword 'QuadTriSngl' deprecated. Use 'QuadTriNoNewVerts' instead.");
    ;}
    break;

  case 332:
#line 4429 "Gmsh.y"
    {
      yymsg(0, "Method 'QuadTriDbl' deprecated. Use 'QuadTriAddVerts' instead, "
            "which has no requirement for the number of extrusion layers and meshes "
            "with body-centered vertices.");
    ;}
    break;

  case 333:
#line 4435 "Gmsh.y"
    {
      yymsg(0, "Method 'QuadTriDbl' deprecated. Use 'QuadTriAddVerts' instead, "
            "which has no requirement for the number of extrusion layers and meshes "
            "with body-centered vertices.");
    ;}
    break;

  case 334:
#line 4441 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1;
    ;}
    break;

  case 335:
#line 4445 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1_RECOMB;
    ;}
    break;

  case 336:
#line 4449 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1;
    ;}
    break;

  case 337:
#line 4453 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1_RECOMB;
    ;}
    break;

  case 338:
#line 4457 "Gmsh.y"
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

  case 339:
#line 4476 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (6)].c), "Index"))
        extr.mesh.BoundaryLayerIndex = (yyvsp[(4) - (6)].d);
      else if(!strcmp((yyvsp[(2) - (6)].c), "View"))
        extr.mesh.ViewIndex = (yyvsp[(4) - (6)].d);
      Free((yyvsp[(2) - (6)].c));
    ;}
    break;

  case 340:
#line 4488 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Union; ;}
    break;

  case 341:
#line 4489 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Intersection; ;}
    break;

  case 342:
#line 4490 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Difference; ;}
    break;

  case 343:
#line 4491 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Section; ;}
    break;

  case 344:
#line 4492 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Fragments; ;}
    break;

  case 345:
#line 4496 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 346:
#line 4497 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 347:
#line 4498 "Gmsh.y"
    { (yyval.i) = (yyvsp[(2) - (3)].d); ;}
    break;

  case 348:
#line 4503 "Gmsh.y"
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

  case 349:
#line 4536 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        std::vector<int> out[4];
        std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
        GModel::current()->getOCCInternals()->importShapes(tmp, out);
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

  case 350:
#line 4563 "Gmsh.y"
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

  case 351:
#line 4585 "Gmsh.y"
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    ;}
    break;

  case 352:
#line 4589 "Gmsh.y"
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

  case 353:
#line 4604 "Gmsh.y"
    {
      (yyval.i) = -1; // left
    ;}
    break;

  case 354:
#line 4608 "Gmsh.y"
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

  case 355:
#line 4624 "Gmsh.y"
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   ;}
    break;

  case 356:
#line 4628 "Gmsh.y"
    {
     (yyval.l) = (yyvsp[(2) - (2)].l);
   ;}
    break;

  case 357:
#line 4633 "Gmsh.y"
    {
      (yyval.i) = 45;
    ;}
    break;

  case 358:
#line 4637 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(2) - (2)].d);
    ;}
    break;

  case 359:
#line 4643 "Gmsh.y"
    {
      (yyval.l) = List_Create(1, 1, sizeof(double));
    ;}
    break;

  case 360:
#line 4647 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
    ;}
    break;

  case 361:
#line 4654 "Gmsh.y"
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

  case 362:
#line 4710 "Gmsh.y"
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

  case 363:
#line 4780 "Gmsh.y"
    {
      yymsg(1, "Elliptic Surface is deprecated: use Transfinite instead (with smoothing)");
      List_Delete((yyvsp[(7) - (8)].l));
    ;}
    break;

  case 364:
#line 4785 "Gmsh.y"
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

  case 365:
#line 4852 "Gmsh.y"
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

  case 366:
#line 4888 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (8)].l)); i++){
	double d;
	List_Read((yyvsp[(4) - (8)].l), i, &d);
	CTX::instance()->mesh.algo2d_per_face[(int)d] = (int)(yyvsp[(7) - (8)].d);
      }
    ;}
    break;

  case 367:
#line 4896 "Gmsh.y"
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

  case 368:
#line 4939 "Gmsh.y"
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

  case 369:
#line 4978 "Gmsh.y"
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

  case 370:
#line 4999 "Gmsh.y"
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

  case 371:
#line 5031 "Gmsh.y"
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

  case 372:
#line 5058 "Gmsh.y"
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

  case 373:
#line 5084 "Gmsh.y"
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

  case 374:
#line 5110 "Gmsh.y"
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

  case 375:
#line 5136 "Gmsh.y"
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

  case 376:
#line 5162 "Gmsh.y"
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

  case 377:
#line 5183 "Gmsh.y"
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

  case 378:
#line 5211 "Gmsh.y"
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

  case 379:
#line 5239 "Gmsh.y"
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

  case 380:
#line 5267 "Gmsh.y"
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

  case 381:
#line 5295 "Gmsh.y"
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

  case 382:
#line 5323 "Gmsh.y"
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

  case 383:
#line 5362 "Gmsh.y"
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

  case 384:
#line 5401 "Gmsh.y"
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

  case 385:
#line 5422 "Gmsh.y"
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

  case 386:
#line 5443 "Gmsh.y"
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

  case 387:
#line 5470 "Gmsh.y"
    {
      ReplaceAllDuplicates();
    ;}
    break;

  case 388:
#line 5474 "Gmsh.y"
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

  case 389:
#line 5484 "Gmsh.y"
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

  case 390:
#line 5518 "Gmsh.y"
    { (yyval.c) = (char*)"Homology"; ;}
    break;

  case 391:
#line 5519 "Gmsh.y"
    { (yyval.c) = (char*)"Cohomology"; ;}
    break;

  case 392:
#line 5520 "Gmsh.y"
    { (yyval.c) = (char*)"Betti"; ;}
    break;

  case 393:
#line 5525 "Gmsh.y"
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest((yyvsp[(1) - (2)].c), domain, subdomain, dim);
    ;}
    break;

  case 394:
#line 5531 "Gmsh.y"
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

  case 395:
#line 5543 "Gmsh.y"
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

  case 396:
#line 5561 "Gmsh.y"
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

  case 397:
#line 5588 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d);           ;}
    break;

  case 398:
#line 5589 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (3)].d);           ;}
    break;

  case 399:
#line 5590 "Gmsh.y"
    { (yyval.d) = -(yyvsp[(2) - (2)].d);          ;}
    break;

  case 400:
#line 5591 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);           ;}
    break;

  case 401:
#line 5592 "Gmsh.y"
    { (yyval.d) = !(yyvsp[(2) - (2)].d);          ;}
    break;

  case 402:
#line 5593 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) - (yyvsp[(3) - (3)].d);      ;}
    break;

  case 403:
#line 5594 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) + (yyvsp[(3) - (3)].d);      ;}
    break;

  case 404:
#line 5595 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) * (yyvsp[(3) - (3)].d);      ;}
    break;

  case 405:
#line 5597 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (3)].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));
      else
	(yyval.d) = (yyvsp[(1) - (3)].d) / (yyvsp[(3) - (3)].d);
    ;}
    break;

  case 406:
#line 5603 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) % (int)(yyvsp[(3) - (3)].d);  ;}
    break;

  case 407:
#line 5604 "Gmsh.y"
    { (yyval.d) = pow((yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));  ;}
    break;

  case 408:
#line 5605 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d);      ;}
    break;

  case 409:
#line 5606 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) > (yyvsp[(3) - (3)].d);      ;}
    break;

  case 410:
#line 5607 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) <= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 411:
#line 5608 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) >= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 412:
#line 5609 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) == (yyvsp[(3) - (3)].d);     ;}
    break;

  case 413:
#line 5610 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) != (yyvsp[(3) - (3)].d);     ;}
    break;

  case 414:
#line 5611 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) && (yyvsp[(3) - (3)].d);     ;}
    break;

  case 415:
#line 5612 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) || (yyvsp[(3) - (3)].d);     ;}
    break;

  case 416:
#line 5613 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (5)].d) ? (yyvsp[(3) - (5)].d) : (yyvsp[(5) - (5)].d); ;}
    break;

  case 417:
#line 5614 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 418:
#line 5615 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 419:
#line 5616 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 420:
#line 5617 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 421:
#line 5618 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 422:
#line 5619 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 423:
#line 5620 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 424:
#line 5621 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 425:
#line 5622 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 426:
#line 5623 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 427:
#line 5624 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 428:
#line 5625 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 429:
#line 5626 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 430:
#line 5627 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 431:
#line 5628 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 432:
#line 5629 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 433:
#line 5630 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 434:
#line 5631 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d) + 0.5); ;}
    break;

  case 435:
#line 5632 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 436:
#line 5633 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 437:
#line 5634 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 438:
#line 5635 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 439:
#line 5644 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 440:
#line 5645 "Gmsh.y"
    { (yyval.d) = 3.141592653589793; ;}
    break;

  case 441:
#line 5646 "Gmsh.y"
    { (yyval.d) = (double)ImbricatedTest; ;}
    break;

  case 442:
#line 5647 "Gmsh.y"
    { (yyval.d) = Msg::GetCommRank(); ;}
    break;

  case 443:
#line 5648 "Gmsh.y"
    { (yyval.d) = Msg::GetCommSize(); ;}
    break;

  case 444:
#line 5649 "Gmsh.y"
    { (yyval.d) = GetGmshMajorVersion(); ;}
    break;

  case 445:
#line 5650 "Gmsh.y"
    { (yyval.d) = GetGmshMinorVersion(); ;}
    break;

  case 446:
#line 5651 "Gmsh.y"
    { (yyval.d) = GetGmshPatchVersion(); ;}
    break;

  case 447:
#line 5652 "Gmsh.y"
    { (yyval.d) = Cpu(); ;}
    break;

  case 448:
#line 5653 "Gmsh.y"
    { (yyval.d) = GetMemoryUsage()/1024./1024.; ;}
    break;

  case 449:
#line 5654 "Gmsh.y"
    { (yyval.d) = TotalRam(); ;}
    break;

  case 450:
#line 5659 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 451:
#line 5661 "Gmsh.y"
    {
      std::vector<double> val(1, (yyvsp[(3) - (6)].d));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.d) = val[0];
    ;}
    break;

  case 452:
#line 5667 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 453:
#line 5672 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 454:
#line 5677 "Gmsh.y"
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

  case 455:
#line 5694 "Gmsh.y"
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
#line 5712 "Gmsh.y"
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

  case 457:
#line 5730 "Gmsh.y"
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
#line 5748 "Gmsh.y"
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
#line 5766 "Gmsh.y"
    {
      (yyval.d) = gmsh_yysymbols.count((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 460:
#line 5771 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.d) = !StatFile(tmp);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 461:
#line 5777 "Gmsh.y"
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

  case 462:
#line 5792 "Gmsh.y"
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

  case 463:
#line 5811 "Gmsh.y"
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
#line 5831 "Gmsh.y"
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

  case 465:
#line 5851 "Gmsh.y"
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
#line 5871 "Gmsh.y"
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
#line 5894 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), (yyval.d));
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 468:
#line 5899 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), (yyval.d));
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 469:
#line 5904 "Gmsh.y"
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

  case 470:
#line 5914 "Gmsh.y"
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

  case 471:
#line 5924 "Gmsh.y"
    {
      (yyval.d) = Msg::GetValue((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 472:
#line 5929 "Gmsh.y"
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

  case 473:
#line 5940 "Gmsh.y"
    {
      std::string s((yyvsp[(3) - (6)].c)), substr((yyvsp[(5) - (6)].c));
      if(s.find(substr) != std::string::npos)
        (yyval.d) = 1.;
      else
        (yyval.d) = 0.;
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 474:
#line 5949 "Gmsh.y"
    {
      (yyval.d) = strlen((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 475:
#line 5954 "Gmsh.y"
    {
      (yyval.d) = strcmp((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 476:
#line 5959 "Gmsh.y"
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

  case 477:
#line 5986 "Gmsh.y"
    {
      memcpy((yyval.v), (yyvsp[(1) - (1)].v), 5*sizeof(double));
    ;}
    break;

  case 478:
#line 5990 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 479:
#line 5994 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 480:
#line 5998 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] - (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 481:
#line 6002 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] + (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 482:
#line 6009 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (11)].d);  (yyval.v)[1] = (yyvsp[(4) - (11)].d);  (yyval.v)[2] = (yyvsp[(6) - (11)].d);  (yyval.v)[3] = (yyvsp[(8) - (11)].d); (yyval.v)[4] = (yyvsp[(10) - (11)].d);
    ;}
    break;

  case 483:
#line 6013 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (9)].d);  (yyval.v)[1] = (yyvsp[(4) - (9)].d);  (yyval.v)[2] = (yyvsp[(6) - (9)].d);  (yyval.v)[3] = (yyvsp[(8) - (9)].d); (yyval.v)[4] = 1.0;
    ;}
    break;

  case 484:
#line 6017 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 485:
#line 6021 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 486:
#line 6028 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].l)));
    ;}
    break;

  case 487:
#line 6033 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].l)));
    ;}
    break;

  case 488:
#line 6040 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 489:
#line 6045 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 490:
#line 6049 "Gmsh.y"
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    ;}
    break;

  case 491:
#line 6054 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 492:
#line 6058 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 493:
#line 6066 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (5)].d);
      }
    ;}
    break;

  case 494:
#line 6077 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 495:
#line 6081 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(1) - (1)].c), "*") || !strcmp((yyvsp[(1) - (1)].c), "all"))
        (yyval.l) = 0;
      else{
        yyerror("Unknown special string for list replacement");
        (yyval.l) = List_Create(2, 1, sizeof(double));
      }
    ;}
    break;

  case 496:
#line 6093 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 497:
#line 6101 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (3)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (3)].d);
      }
    ;}
    break;

  case 498:
#line 6109 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      for(double d = (yyvsp[(1) - (3)].d); ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d <= (yyvsp[(3) - (3)].d)) : (d >= (yyvsp[(3) - (3)].d));
          ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d += 1.) : (d -= 1.))
	List_Add((yyval.l), &d);
    ;}
    break;

  case 499:
#line 6116 "Gmsh.y"
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

  case 500:
#line 6126 "Gmsh.y"
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

  case 501:
#line 6155 "Gmsh.y"
    {
      (yyval.l) = GetAllElementaryEntityNumbers(0);
    ;}
    break;

  case 502:
#line 6159 "Gmsh.y"
    {
      (yyval.l) = GetAllElementaryEntityNumbers(1);
    ;}
    break;

  case 503:
#line 6163 "Gmsh.y"
    {
      (yyval.l) = GetAllElementaryEntityNumbers(2);
    ;}
    break;

  case 504:
#line 6167 "Gmsh.y"
    {
      (yyval.l) = GetAllElementaryEntityNumbers(3);
    ;}
    break;

  case 505:
#line 6171 "Gmsh.y"
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(0);
    ;}
    break;

  case 506:
#line 6175 "Gmsh.y"
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(1);
    ;}
    break;

  case 507:
#line 6179 "Gmsh.y"
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(2);
    ;}
    break;

  case 508:
#line 6183 "Gmsh.y"
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(3);
    ;}
    break;

  case 509:
#line 6187 "Gmsh.y"
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

  case 510:
#line 6216 "Gmsh.y"
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

  case 511:
#line 6245 "Gmsh.y"
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

  case 512:
#line 6274 "Gmsh.y"
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

  case 513:
#line 6304 "Gmsh.y"
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

  case 514:
#line 6317 "Gmsh.y"
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

  case 515:
#line 6330 "Gmsh.y"
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

  case 516:
#line 6343 "Gmsh.y"
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

  case 517:
#line 6355 "Gmsh.y"
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

  case 518:
#line 6365 "Gmsh.y"
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

  case 519:
#line 6375 "Gmsh.y"
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
#line 6385 "Gmsh.y"
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

  case 521:
#line 6397 "Gmsh.y"
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

  case 522:
#line 6410 "Gmsh.y"
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

  case 523:
#line 6422 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 524:
#line 6426 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 525:
#line 6430 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (6)].l);
    ;}
    break;

  case 526:
#line 6434 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (6)].l);
    ;}
    break;

  case 527:
#line 6438 "Gmsh.y"
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

  case 528:
#line 6456 "Gmsh.y"
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

  case 529:
#line 6474 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = (yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1);
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 530:
#line 6482 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = pow(10,(yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1));
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 531:
#line 6490 "Gmsh.y"
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

  case 532:
#line 6519 "Gmsh.y"
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

  case 533:
#line 6532 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 534:
#line 6537 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 535:
#line 6541 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].d)));
    ;}
    break;

  case 536:
#line 6545 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (3)].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 537:
#line 6557 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (9)].d), (int)(yyvsp[(4) - (9)].d), (int)(yyvsp[(6) - (9)].d), (int)(yyvsp[(8) - (9)].d));
    ;}
    break;

  case 538:
#line 6561 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (7)].d), (int)(yyvsp[(4) - (7)].d), (int)(yyvsp[(6) - (7)].d), 255);
    ;}
    break;

  case 539:
#line 6573 "Gmsh.y"
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

  case 540:
#line 6590 "Gmsh.y"
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(5) - (5)].c), val);
      (yyval.u) = val;
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(5) - (5)].c));
    ;}
    break;

  case 541:
#line 6600 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 542:
#line 6604 "Gmsh.y"
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

  case 543:
#line 6619 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].u)));
    ;}
    break;

  case 544:
#line 6624 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].u)));
    ;}
    break;

  case 545:
#line 6631 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 546:
#line 6635 "Gmsh.y"
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

  case 547:
#line 6648 "Gmsh.y"
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
#line 6662 "Gmsh.y"
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

  case 549:
#line 6676 "Gmsh.y"
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
#line 6690 "Gmsh.y"
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
#line 6704 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 552:
#line 6712 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 553:
#line 6723 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 554:
#line 6727 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 555:
#line 6731 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    ;}
    break;

  case 556:
#line 6739 "Gmsh.y"
    {
      std::string exe = Msg::GetExecutableName();
      (yyval.c) = (char *)Malloc(exe.size() + 1);
      strcpy((yyval.c), exe.c_str());
    ;}
    break;

  case 557:
#line 6745 "Gmsh.y"
    {
      std::string action = Msg::GetOnelabAction();
      (yyval.c) = (char *)Malloc(action.size() + 1);
      strcpy((yyval.c), action.c_str());
    ;}
    break;

  case 558:
#line 6751 "Gmsh.y"
    {
      const char *env = GetEnvironmentVar((yyvsp[(3) - (4)].c));
      if(!env) env = "";
      (yyval.c) = (char *)Malloc((sizeof(env) + 1) * sizeof(char));
      strcpy((yyval.c), env);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 559:
#line 6759 "Gmsh.y"
    {
      std::string s = Msg::GetString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 560:
#line 6767 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (4)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 561:
#line 6774 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 562:
#line 6782 "Gmsh.y"
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

  case 563:
#line 6797 "Gmsh.y"
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

  case 564:
#line 6811 "Gmsh.y"
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

  case 565:
#line 6825 "Gmsh.y"
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

  case 566:
#line 6837 "Gmsh.y"
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

  case 567:
#line 6853 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = toupper((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 568:
#line 6862 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = tolower((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 569:
#line 6871 "Gmsh.y"
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

  case 570:
#line 6881 "Gmsh.y"
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

  case 571:
#line 6892 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (8)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (8)].d), (int)(yyvsp[(7) - (8)].d));
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (8)].c));
    ;}
    break;

  case 572:
#line 6900 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (6)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (6)].d), std::string::npos);
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 573:
#line 6908 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 574:
#line 6912 "Gmsh.y"
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

  case 575:
#line 6931 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 576:
#line 6938 "Gmsh.y"
    {
      std::string tmp = SplitFileName(GetAbsolutePath(gmsh_yyname))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
    ;}
    break;

  case 577:
#line 6944 "Gmsh.y"
    {
      std::string tmp = SplitFileName((yyvsp[(3) - (4)].c))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 578:
#line 6951 "Gmsh.y"
    {
      std::string tmp = GetAbsolutePath((yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 579:
#line 6958 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 580:
#line 6960 "Gmsh.y"
    {
      std::string val((yyvsp[(3) - (6)].c));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.c) = (char*)Malloc((val.size() + 1) * sizeof(char));
      strcpy((yyval.c), val.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 581:
#line 6971 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].c)));
    ;}
    break;

  case 582:
#line 6976 "Gmsh.y"
    { List_Add((yyval.l), &((yyvsp[(3) - (3)].c))); ;}
    break;

  case 583:
#line 6982 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 584:
#line 6991 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char)) ;
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)) ; strcat((yyval.c), tmpstr) ;
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 585:
#line 7004 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 586:
#line 7007 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 587:
#line 7011 "Gmsh.y"
    { (yyval.c) = (yyvsp[(3) - (4)].c); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 14070 "Gmsh.tab.cpp"
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


#line 7014 "Gmsh.y"


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

