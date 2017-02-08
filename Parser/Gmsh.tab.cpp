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
     tCharacteristic = 354,
     tLength = 355,
     tParametric = 356,
     tElliptic = 357,
     tRefineMesh = 358,
     tAdaptMesh = 359,
     tRelocateMesh = 360,
     tSetFactory = 361,
     tThruSections = 362,
     tPlane = 363,
     tRuled = 364,
     tTransfinite = 365,
     tComplex = 366,
     tPhysical = 367,
     tCompound = 368,
     tPeriodic = 369,
     tUsing = 370,
     tPlugin = 371,
     tDegenerated = 372,
     tRecursive = 373,
     tRotate = 374,
     tTranslate = 375,
     tSymmetry = 376,
     tDilate = 377,
     tExtrude = 378,
     tLevelset = 379,
     tAffine = 380,
     tBooleanUnion = 381,
     tBooleanIntersection = 382,
     tBooleanDifference = 383,
     tBooleanSection = 384,
     tBooleanFragments = 385,
     tRecombine = 386,
     tSmoother = 387,
     tSplit = 388,
     tDelete = 389,
     tCoherence = 390,
     tIntersect = 391,
     tMeshAlgorithm = 392,
     tReverse = 393,
     tLayers = 394,
     tScaleLast = 395,
     tHole = 396,
     tAlias = 397,
     tAliasWithOptions = 398,
     tCopyOptions = 399,
     tQuadTriAddVerts = 400,
     tQuadTriNoNewVerts = 401,
     tQuadTriSngl = 402,
     tQuadTriDbl = 403,
     tRecombLaterals = 404,
     tTransfQuadTri = 405,
     tText2D = 406,
     tText3D = 407,
     tInterpolationScheme = 408,
     tTime = 409,
     tCombine = 410,
     tBSpline = 411,
     tBezier = 412,
     tNurbs = 413,
     tNurbsOrder = 414,
     tNurbsKnots = 415,
     tColor = 416,
     tColorTable = 417,
     tFor = 418,
     tIn = 419,
     tEndFor = 420,
     tIf = 421,
     tElseIf = 422,
     tElse = 423,
     tEndIf = 424,
     tExit = 425,
     tAbort = 426,
     tField = 427,
     tReturn = 428,
     tCall = 429,
     tSlide = 430,
     tMacro = 431,
     tShow = 432,
     tHide = 433,
     tGetValue = 434,
     tGetStringValue = 435,
     tGetEnv = 436,
     tGetString = 437,
     tGetNumber = 438,
     tHomology = 439,
     tCohomology = 440,
     tBetti = 441,
     tExists = 442,
     tFileExists = 443,
     tGMSH_MAJOR_VERSION = 444,
     tGMSH_MINOR_VERSION = 445,
     tGMSH_PATCH_VERSION = 446,
     tGmshExecutableName = 447,
     tSetPartition = 448,
     tNameToString = 449,
     tStringToName = 450,
     tAFFECTDIVIDE = 451,
     tAFFECTTIMES = 452,
     tAFFECTMINUS = 453,
     tAFFECTPLUS = 454,
     tOR = 455,
     tAND = 456,
     tNOTEQUAL = 457,
     tEQUAL = 458,
     tGREATEROREQUAL = 459,
     tLESSOREQUAL = 460,
     UNARYPREC = 461,
     tMINUSMINUS = 462,
     tPLUSPLUS = 463
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
#define tCharacteristic 354
#define tLength 355
#define tParametric 356
#define tElliptic 357
#define tRefineMesh 358
#define tAdaptMesh 359
#define tRelocateMesh 360
#define tSetFactory 361
#define tThruSections 362
#define tPlane 363
#define tRuled 364
#define tTransfinite 365
#define tComplex 366
#define tPhysical 367
#define tCompound 368
#define tPeriodic 369
#define tUsing 370
#define tPlugin 371
#define tDegenerated 372
#define tRecursive 373
#define tRotate 374
#define tTranslate 375
#define tSymmetry 376
#define tDilate 377
#define tExtrude 378
#define tLevelset 379
#define tAffine 380
#define tBooleanUnion 381
#define tBooleanIntersection 382
#define tBooleanDifference 383
#define tBooleanSection 384
#define tBooleanFragments 385
#define tRecombine 386
#define tSmoother 387
#define tSplit 388
#define tDelete 389
#define tCoherence 390
#define tIntersect 391
#define tMeshAlgorithm 392
#define tReverse 393
#define tLayers 394
#define tScaleLast 395
#define tHole 396
#define tAlias 397
#define tAliasWithOptions 398
#define tCopyOptions 399
#define tQuadTriAddVerts 400
#define tQuadTriNoNewVerts 401
#define tQuadTriSngl 402
#define tQuadTriDbl 403
#define tRecombLaterals 404
#define tTransfQuadTri 405
#define tText2D 406
#define tText3D 407
#define tInterpolationScheme 408
#define tTime 409
#define tCombine 410
#define tBSpline 411
#define tBezier 412
#define tNurbs 413
#define tNurbsOrder 414
#define tNurbsKnots 415
#define tColor 416
#define tColorTable 417
#define tFor 418
#define tIn 419
#define tEndFor 420
#define tIf 421
#define tElseIf 422
#define tElse 423
#define tEndIf 424
#define tExit 425
#define tAbort 426
#define tField 427
#define tReturn 428
#define tCall 429
#define tSlide 430
#define tMacro 431
#define tShow 432
#define tHide 433
#define tGetValue 434
#define tGetStringValue 435
#define tGetEnv 436
#define tGetString 437
#define tGetNumber 438
#define tHomology 439
#define tCohomology 440
#define tBetti 441
#define tExists 442
#define tFileExists 443
#define tGMSH_MAJOR_VERSION 444
#define tGMSH_MINOR_VERSION 445
#define tGMSH_PATCH_VERSION 446
#define tGmshExecutableName 447
#define tSetPartition 448
#define tNameToString 449
#define tStringToName 450
#define tAFFECTDIVIDE 451
#define tAFFECTTIMES 452
#define tAFFECTMINUS 453
#define tAFFECTPLUS 454
#define tOR 455
#define tAND 456
#define tNOTEQUAL 457
#define tEQUAL 458
#define tGREATEROREQUAL 459
#define tLESSOREQUAL 460
#define UNARYPREC 461
#define tMINUSMINUS 462
#define tPLUSPLUS 463




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
#line 646 "Gmsh.tab.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 659 "Gmsh.tab.cpp"

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
#define YYLAST   13561

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  229
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  105
/* YYNRULES -- Number of rules.  */
#define YYNRULES  585
/* YYNRULES -- Number of states.  */
#define YYNSTATES  2152

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   463

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   214,     2,   224,     2,   213,     2,     2,
     219,   220,   211,   209,   225,   210,   223,   212,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     205,     2,   206,   200,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   221,     2,   222,   218,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   226,     2,   227,   228,     2,     2,     2,
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
     195,   196,   197,   198,   199,   201,   202,   203,   204,   207,
     208,   215,   216,   217
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
    1026,  1037,  1045,  1053,  1061,  1069,  1078,  1083,  1092,  1105,
    1114,  1123,  1131,  1139,  1144,  1153,  1162,  1168,  1180,  1186,
    1196,  1206,  1211,  1221,  1231,  1233,  1235,  1236,  1239,  1246,
    1253,  1260,  1267,  1276,  1287,  1302,  1319,  1332,  1347,  1362,
    1377,  1392,  1401,  1410,  1417,  1422,  1429,  1436,  1440,  1445,
    1451,  1458,  1464,  1468,  1472,  1477,  1483,  1488,  1494,  1498,
    1504,  1512,  1520,  1524,  1532,  1536,  1539,  1542,  1545,  1548,
    1551,  1567,  1570,  1573,  1576,  1579,  1582,  1599,  1611,  1618,
    1627,  1636,  1647,  1649,  1652,  1655,  1657,  1661,  1665,  1670,
    1675,  1677,  1679,  1685,  1697,  1711,  1712,  1720,  1721,  1735,
    1736,  1752,  1753,  1760,  1769,  1778,  1787,  1800,  1813,  1826,
    1841,  1856,  1871,  1872,  1885,  1886,  1899,  1900,  1913,  1914,
    1931,  1932,  1949,  1950,  1967,  1968,  1987,  1988,  2007,  2008,
    2027,  2029,  2032,  2038,  2046,  2056,  2059,  2062,  2066,  2069,
    2073,  2076,  2080,  2083,  2087,  2090,  2094,  2104,  2111,  2113,
    2115,  2117,  2119,  2121,  2122,  2125,  2129,  2139,  2144,  2159,
    2160,  2164,  2165,  2167,  2168,  2171,  2172,  2175,  2176,  2179,
    2187,  2194,  2203,  2209,  2213,  2222,  2228,  2233,  2240,  2252,
    2264,  2283,  2302,  2315,  2328,  2341,  2352,  2363,  2374,  2385,
    2396,  2401,  2406,  2411,  2416,  2421,  2424,  2428,  2435,  2437,
    2439,  2441,  2444,  2450,  2458,  2469,  2471,  2475,  2478,  2481,
    2484,  2488,  2492,  2496,  2500,  2504,  2508,  2512,  2516,  2520,
    2524,  2528,  2532,  2536,  2540,  2546,  2551,  2556,  2561,  2566,
    2571,  2576,  2581,  2586,  2591,  2596,  2603,  2608,  2613,  2618,
    2623,  2628,  2633,  2638,  2645,  2652,  2659,  2664,  2666,  2668,
    2670,  2672,  2674,  2676,  2678,  2680,  2682,  2684,  2686,  2687,
    2694,  2699,  2706,  2708,  2713,  2718,  2723,  2728,  2733,  2738,
    2743,  2746,  2752,  2758,  2764,  2770,  2774,  2781,  2786,  2794,
    2801,  2808,  2815,  2820,  2827,  2832,  2834,  2837,  2840,  2844,
    2848,  2860,  2870,  2878,  2886,  2888,  2892,  2894,  2896,  2899,
    2903,  2908,  2914,  2916,  2918,  2921,  2925,  2929,  2935,  2940,
    2943,  2946,  2949,  2952,  2956,  2960,  2964,  2968,  2974,  2980,
    2986,  2992,  3009,  3026,  3043,  3060,  3062,  3064,  3066,  3070,
    3074,  3079,  3084,  3089,  3096,  3103,  3110,  3117,  3126,  3135,
    3140,  3155,  3157,  3159,  3163,  3167,  3177,  3185,  3187,  3193,
    3197,  3204,  3206,  3210,  3212,  3214,  3219,  3224,  3229,  3234,
    3238,  3245,  3247,  3252,  3254,  3256,  3258,  3263,  3270,  3275,
    3282,  3287,  3292,  3297,  3306,  3311,  3316,  3321,  3326,  3335,
    3344,  3351,  3356,  3363,  3368,  3370,  3375,  3380,  3381,  3388,
    3390,  3394,  3400,  3406,  3408,  3410
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     230,     0,    -1,   231,    -1,     1,     6,    -1,    -1,   231,
     232,    -1,   235,    -1,   234,    -1,   255,    -1,   274,    -1,
     275,    -1,   279,    -1,   280,    -1,   281,    -1,   282,    -1,
     286,    -1,   304,    -1,   305,    -1,   311,    -1,   312,    -1,
     285,    -1,   284,    -1,   283,    -1,   278,    -1,   314,    -1,
     206,    -1,   206,   206,    -1,    42,   219,   328,   220,     6,
      -1,    43,   219,   328,   220,     6,    -1,    42,   219,   328,
     220,   233,   328,     6,    -1,    42,   219,   328,   225,   324,
     220,     6,    -1,    43,   219,   328,   225,   324,   220,     6,
      -1,    42,   219,   328,   225,   324,   220,   233,   328,     6,
      -1,     4,   328,   226,   236,   227,     6,    -1,   142,     4,
     221,   315,   222,     6,    -1,   143,     4,   221,   315,   222,
       6,    -1,   144,     4,   221,   315,   225,   315,   222,     6,
      -1,    -1,   236,   239,    -1,   236,   243,    -1,   236,   246,
      -1,   236,   248,    -1,   236,   249,    -1,   315,    -1,   237,
     225,   315,    -1,   315,    -1,   238,   225,   315,    -1,    -1,
      -1,     4,   240,   219,   237,   220,   241,   226,   238,   227,
       6,    -1,   328,    -1,   242,   225,   328,    -1,    -1,   151,
     219,   315,   225,   315,   225,   315,   220,   244,   226,   242,
     227,     6,    -1,   328,    -1,   245,   225,   328,    -1,    -1,
     152,   219,   315,   225,   315,   225,   315,   225,   315,   220,
     247,   226,   245,   227,     6,    -1,   153,   226,   320,   227,
     226,   320,   227,     6,    -1,   153,   226,   320,   227,   226,
     320,   227,   226,   320,   227,   226,   320,   227,     6,    -1,
      -1,   154,   250,   226,   238,   227,     6,    -1,     7,    -1,
     199,    -1,   198,    -1,   197,    -1,   196,    -1,   217,    -1,
     216,    -1,   219,    -1,   221,    -1,   220,    -1,   222,    -1,
      78,   221,   257,   222,     6,    -1,    79,   221,   262,   222,
       6,    -1,    82,   253,   329,   225,   315,   254,     6,    -1,
      83,   253,   333,   225,   329,   254,     6,    -1,   333,   251,
     321,     6,    -1,   333,   252,     6,    -1,     4,   221,   222,
     251,   321,     6,    -1,   332,   221,   222,   251,   321,     6,
      -1,     4,   221,   315,   222,   251,   315,     6,    -1,   332,
     221,   315,   222,   251,   315,     6,    -1,     4,   221,   315,
     222,   252,     6,    -1,   332,   221,   315,   222,   252,     6,
      -1,     4,   253,   226,   324,   227,   254,   251,   321,     6,
      -1,   332,   253,   226,   324,   227,   254,   251,   321,     6,
      -1,     4,   219,   220,   251,   321,     6,    -1,   332,   219,
     220,   251,   321,     6,    -1,     4,   219,   315,   220,   251,
     315,     6,    -1,   332,   219,   315,   220,   251,   315,     6,
      -1,     4,   219,   315,   220,   252,     6,    -1,   332,   219,
     315,   220,   252,     6,    -1,   333,     7,   329,     6,    -1,
       4,   221,   222,     7,    44,   253,   254,     6,    -1,   332,
     221,   222,     7,    44,   253,   254,     6,    -1,     4,   221,
     222,     7,    44,   253,   331,   254,     6,    -1,   332,   221,
     222,     7,    44,   253,   331,   254,     6,    -1,     4,   221,
     222,   199,    44,   253,   331,   254,     6,    -1,   332,   221,
     222,   199,    44,   253,   331,   254,     6,    -1,     4,   219,
     220,     7,    44,   253,   254,     6,    -1,   332,   219,   220,
       7,    44,   253,   254,     6,    -1,     4,   219,   220,     7,
      44,   253,   331,   254,     6,    -1,   332,   219,   220,     7,
      44,   253,   331,   254,     6,    -1,     4,   219,   220,   199,
      44,   253,   331,   254,     6,    -1,   332,   219,   220,   199,
      44,   253,   331,   254,     6,    -1,     4,   223,     4,     7,
     329,     6,    -1,     4,   221,   315,   222,   223,     4,     7,
     329,     6,    -1,     4,   223,     4,   251,   315,     6,    -1,
       4,   221,   315,   222,   223,     4,   251,   315,     6,    -1,
       4,   223,     4,   252,     6,    -1,     4,   221,   315,   222,
     223,     4,   252,     6,    -1,     4,   223,   161,   223,     4,
       7,   325,     6,    -1,     4,   221,   315,   222,   223,   161,
     223,     4,     7,   325,     6,    -1,     4,   223,   162,     7,
     326,     6,    -1,     4,   221,   315,   222,   223,   162,     7,
     326,     6,    -1,     4,   172,     7,   315,     6,    -1,   172,
     221,   315,   222,     7,     4,     6,    -1,   172,   221,   315,
     222,   223,     4,     7,   315,     6,    -1,   172,   221,   315,
     222,   223,     4,     7,   329,     6,    -1,   172,   221,   315,
     222,   223,     4,     7,   226,   324,   227,     6,    -1,   172,
     221,   315,   222,   223,     4,     6,    -1,   116,   219,     4,
     220,   223,     4,     7,   315,     6,    -1,   116,   219,     4,
     220,   223,     4,     7,   329,     6,    -1,    -1,   225,    -1,
      -1,   257,   256,   333,    -1,   257,   256,   333,     7,   315,
      -1,    -1,   257,   256,   333,     7,   226,   321,   258,   264,
     227,    -1,    -1,   257,   256,   333,   221,   222,     7,   226,
     321,   259,   264,   227,    -1,    -1,   257,   256,   333,   219,
     220,     7,   226,   321,   260,   264,   227,    -1,   257,   256,
     333,     7,   329,    -1,    -1,   257,   256,   333,     7,   226,
     329,   261,   266,   227,    -1,    -1,   262,   256,   328,    -1,
     315,     7,   329,    -1,   263,   225,   315,     7,   329,    -1,
     323,     7,   333,   219,   220,    -1,    -1,   264,   265,    -1,
     225,     4,   321,    -1,   225,     4,   226,   263,   227,    -1,
     225,     4,   329,    -1,    -1,   266,   267,    -1,   225,     4,
     315,    -1,   225,     4,   329,    -1,   225,   176,   329,    -1,
     225,     4,   226,   331,   227,    -1,   315,    -1,   329,    -1,
     329,   225,   315,    -1,   315,    -1,   329,    -1,   329,   225,
     315,    -1,   315,    -1,   329,    -1,   329,   225,   315,    -1,
     315,    -1,   329,    -1,   329,   225,   315,    -1,    -1,   164,
      88,   226,   315,   227,    -1,    -1,   108,   318,    -1,   106,
     219,   328,   220,     6,    -1,    84,   219,   315,   220,     7,
     318,     6,    -1,   112,    84,   219,   268,   220,   251,   321,
       6,    -1,    99,   100,   321,     7,   315,     6,    -1,    87,
     219,   315,   220,     7,   321,     6,    -1,   117,    87,   321,
       6,    -1,    91,   219,   315,   220,     7,   321,     6,    -1,
      85,   219,   315,   220,     7,   321,   273,     6,    -1,    86,
     219,   315,   220,     7,   321,   273,     6,    -1,   156,   219,
     315,   220,     7,   321,     6,    -1,   157,   219,   315,   220,
       7,   321,     6,    -1,   158,   219,   315,   220,     7,   321,
     160,   321,   159,   315,     6,    -1,    87,     4,   219,   315,
     220,     7,   321,     6,    -1,   113,    87,   321,     6,    -1,
     113,    87,   219,   315,   220,     7,   321,     6,    -1,   112,
      87,   219,   269,   220,   251,   321,     6,    -1,   108,    90,
     219,   315,   220,     7,   321,     6,    -1,   109,    90,   219,
     315,   220,     7,   321,   272,     6,    -1,    12,    13,     6,
      -1,    13,    90,   315,     6,    -1,   101,    90,   219,   315,
     220,     7,     5,     5,     5,     6,    -1,    88,   219,   315,
     220,     7,   321,     6,    -1,    89,   219,   315,   220,     7,
     321,     6,    -1,    93,   219,   315,   220,     7,   321,     6,
      -1,    94,   219,   315,   220,     7,   321,     6,    -1,    90,
       4,   219,   315,   220,     7,   321,     6,    -1,   113,    90,
     321,     6,    -1,   113,    90,   219,   315,   220,     7,   321,
       6,    -1,   113,    90,   219,   315,   220,     7,   321,     4,
     226,   320,   227,     6,    -1,   112,    90,   219,   270,   220,
     251,   321,     6,    -1,   111,    92,   219,   315,   220,     7,
     321,     6,    -1,    92,   219,   315,   220,     7,   321,     6,
      -1,   107,   219,   315,   220,     7,   321,     6,    -1,   113,
      92,   321,     6,    -1,   113,    92,   219,   315,   220,     7,
     321,     6,    -1,   112,    92,   219,   271,   220,   251,   321,
       6,    -1,   120,   318,   226,   276,   227,    -1,   119,   226,
     318,   225,   318,   225,   315,   227,   226,   276,   227,    -1,
     121,   318,   226,   276,   227,    -1,   122,   226,   318,   225,
     315,   227,   226,   276,   227,    -1,   122,   226,   318,   225,
     318,   227,   226,   276,   227,    -1,     4,   226,   276,   227,
      -1,   136,    87,   226,   324,   227,    90,   226,   315,   227,
      -1,   133,    87,   219,   315,   220,   226,   324,   227,     6,
      -1,   277,    -1,   275,    -1,    -1,   277,   274,    -1,   277,
      84,   226,   324,   227,     6,    -1,   277,    87,   226,   324,
     227,     6,    -1,   277,    90,   226,   324,   227,     6,    -1,
     277,    92,   226,   324,   227,     6,    -1,   124,   108,   219,
     315,   220,     7,   321,     6,    -1,   124,    84,   219,   315,
     220,     7,   226,   320,   227,     6,    -1,   124,   108,   219,
     315,   220,     7,   226,   318,   225,   318,   225,   324,   227,
       6,    -1,   124,   108,   219,   315,   220,     7,   226,   318,
     225,   318,   225,   318,   225,   324,   227,     6,    -1,   124,
      88,   219,   315,   220,     7,   226,   318,   225,   324,   227,
       6,    -1,   124,    94,   219,   315,   220,     7,   226,   318,
     225,   318,   225,   324,   227,     6,    -1,   124,    95,   219,
     315,   220,     7,   226,   318,   225,   318,   225,   324,   227,
       6,    -1,   124,    96,   219,   315,   220,     7,   226,   318,
     225,   318,   225,   324,   227,     6,    -1,   124,    97,   219,
     315,   220,     7,   226,   318,   225,   318,   225,   324,   227,
       6,    -1,   124,     4,   219,   315,   220,     7,   321,     6,
      -1,   124,     4,   219,   315,   220,     7,     5,     6,    -1,
     124,     4,   226,   315,   227,     6,    -1,   134,   226,   277,
     227,    -1,   134,   172,   221,   315,   222,     6,    -1,   134,
       4,   221,   315,   222,     6,    -1,   134,   333,     6,    -1,
     134,     4,     4,     6,    -1,   161,   325,   226,   277,   227,
      -1,   118,   161,   325,   226,   277,   227,    -1,   193,   315,
     226,   277,   227,    -1,   177,     5,     6,    -1,   178,     5,
       6,    -1,   177,   226,   277,   227,    -1,   118,   177,   226,
     277,   227,    -1,   178,   226,   277,   227,    -1,   118,   178,
     226,   277,   227,    -1,     4,   329,     6,    -1,    71,   219,
     331,   220,     6,    -1,     4,     4,   221,   315,   222,   328,
       6,    -1,     4,     4,     4,   221,   315,   222,     6,    -1,
       4,   315,     6,    -1,   116,   219,     4,   220,   223,     4,
       6,    -1,   155,     4,     6,    -1,   170,     6,    -1,   171,
       6,    -1,    68,     6,    -1,    69,     6,    -1,    62,     6,
      -1,    62,   226,   315,   225,   315,   225,   315,   225,   315,
     225,   315,   225,   315,   227,     6,    -1,    63,     6,    -1,
      64,     6,    -1,    75,     6,    -1,    76,     6,    -1,   103,
       6,    -1,   104,   226,   324,   227,   226,   324,   227,   226,
     320,   227,   226,   315,   225,   315,   227,     6,    -1,   175,
     219,   226,   324,   227,   225,   329,   225,   329,   220,     6,
      -1,   163,   219,   315,     8,   315,   220,    -1,   163,   219,
     315,     8,   315,     8,   315,   220,    -1,   163,     4,   164,
     226,   315,     8,   315,   227,    -1,   163,     4,   164,   226,
     315,     8,   315,     8,   315,   227,    -1,   165,    -1,   176,
       4,    -1,   176,   329,    -1,   173,    -1,   174,   333,     6,
      -1,   174,   329,     6,    -1,   166,   219,   315,   220,    -1,
     167,   219,   315,   220,    -1,   168,    -1,   169,    -1,   123,
     318,   226,   277,   227,    -1,   123,   226,   318,   225,   318,
     225,   315,   227,   226,   277,   227,    -1,   123,   226,   318,
     225,   318,   225,   318,   225,   315,   227,   226,   277,   227,
      -1,    -1,   123,   318,   226,   277,   287,   300,   227,    -1,
      -1,   123,   226,   318,   225,   318,   225,   315,   227,   226,
     277,   288,   300,   227,    -1,    -1,   123,   226,   318,   225,
     318,   225,   318,   225,   315,   227,   226,   277,   289,   300,
     227,    -1,    -1,   123,   226,   277,   290,   300,   227,    -1,
     123,    84,   226,   315,   225,   318,   227,     6,    -1,   123,
      87,   226,   315,   225,   318,   227,     6,    -1,   123,    90,
     226,   315,   225,   318,   227,     6,    -1,   123,    84,   226,
     315,   225,   318,   225,   318,   225,   315,   227,     6,    -1,
     123,    87,   226,   315,   225,   318,   225,   318,   225,   315,
     227,     6,    -1,   123,    90,   226,   315,   225,   318,   225,
     318,   225,   315,   227,     6,    -1,   123,    84,   226,   315,
     225,   318,   225,   318,   225,   318,   225,   315,   227,     6,
      -1,   123,    87,   226,   315,   225,   318,   225,   318,   225,
     318,   225,   315,   227,     6,    -1,   123,    90,   226,   315,
     225,   318,   225,   318,   225,   318,   225,   315,   227,     6,
      -1,    -1,   123,    84,   226,   315,   225,   318,   227,   291,
     226,   300,   227,     6,    -1,    -1,   123,    87,   226,   315,
     225,   318,   227,   292,   226,   300,   227,     6,    -1,    -1,
     123,    90,   226,   315,   225,   318,   227,   293,   226,   300,
     227,     6,    -1,    -1,   123,    84,   226,   315,   225,   318,
     225,   318,   225,   315,   227,   294,   226,   300,   227,     6,
      -1,    -1,   123,    87,   226,   315,   225,   318,   225,   318,
     225,   315,   227,   295,   226,   300,   227,     6,    -1,    -1,
     123,    90,   226,   315,   225,   318,   225,   318,   225,   315,
     227,   296,   226,   300,   227,     6,    -1,    -1,   123,    84,
     226,   315,   225,   318,   225,   318,   225,   318,   225,   315,
     227,   297,   226,   300,   227,     6,    -1,    -1,   123,    87,
     226,   315,   225,   318,   225,   318,   225,   318,   225,   315,
     227,   298,   226,   300,   227,     6,    -1,    -1,   123,    90,
     226,   315,   225,   318,   225,   318,   225,   318,   225,   315,
     227,   299,   226,   300,   227,     6,    -1,   301,    -1,   300,
     301,    -1,   139,   226,   315,   227,     6,    -1,   139,   226,
     321,   225,   321,   227,     6,    -1,   139,   226,   321,   225,
     321,   225,   321,   227,     6,    -1,   140,     6,    -1,   131,
       6,    -1,   131,   315,     6,    -1,   147,     6,    -1,   147,
     149,     6,    -1,   148,     6,    -1,   148,   149,     6,    -1,
     145,     6,    -1,   145,   149,     6,    -1,   146,     6,    -1,
     146,   149,     6,    -1,   141,   219,   315,   220,     7,   321,
     115,   315,     6,    -1,   115,     4,   221,   315,   222,     6,
      -1,   126,    -1,   127,    -1,   128,    -1,   129,    -1,   130,
      -1,    -1,   134,     6,    -1,   134,   315,     6,    -1,   302,
     226,   277,   303,   227,   226,   277,   303,   227,    -1,    98,
     219,   328,   220,    -1,   302,   219,   315,   220,     7,   226,
     277,   303,   227,   226,   277,   303,   227,     6,    -1,    -1,
     115,     4,   315,    -1,    -1,     4,    -1,    -1,     7,   321,
      -1,    -1,     7,   315,    -1,    -1,   125,   321,    -1,   110,
      87,   322,     7,   315,   306,     6,    -1,   110,    90,   322,
     308,   307,     6,    -1,   102,    90,   226,   315,   227,     7,
     321,     6,    -1,   110,    92,   322,   308,     6,    -1,   150,
     322,     6,    -1,   137,    90,   226,   324,   227,     7,   315,
       6,    -1,   131,    90,   322,   309,     6,    -1,   131,    92,
     322,     6,    -1,   132,    90,   321,     7,   315,     6,    -1,
     114,    87,   226,   324,   227,     7,   226,   324,   227,   310,
       6,    -1,   114,    90,   226,   324,   227,     7,   226,   324,
     227,   310,     6,    -1,   114,    87,   226,   324,   227,     7,
     226,   324,   227,   119,   226,   318,   225,   318,   225,   315,
     227,     6,    -1,   114,    90,   226,   324,   227,     7,   226,
     324,   227,   119,   226,   318,   225,   318,   225,   315,   227,
       6,    -1,   114,    87,   226,   324,   227,     7,   226,   324,
     227,   120,   318,     6,    -1,   114,    90,   226,   324,   227,
       7,   226,   324,   227,   120,   318,     6,    -1,   114,    90,
     315,   226,   324,   227,     7,   315,   226,   324,   227,     6,
      -1,    84,   226,   324,   227,   164,    90,   226,   315,   227,
       6,    -1,    87,   226,   324,   227,   164,    90,   226,   315,
     227,     6,    -1,    84,   226,   324,   227,   164,    92,   226,
     315,   227,     6,    -1,    87,   226,   324,   227,   164,    92,
     226,   315,   227,     6,    -1,    90,   226,   324,   227,   164,
      92,   226,   315,   227,     6,    -1,   138,    90,   322,     6,
      -1,   138,    87,   322,     6,    -1,   105,    84,   322,     6,
      -1,   105,    87,   322,     6,    -1,   105,    90,   322,     6,
      -1,   135,     6,    -1,   135,     4,     6,    -1,   135,    84,
     226,   324,   227,     6,    -1,   184,    -1,   185,    -1,   186,
      -1,   313,     6,    -1,   313,   226,   321,   227,     6,    -1,
     313,   226,   321,   225,   321,   227,     6,    -1,   313,   219,
     321,   220,   226,   321,   225,   321,   227,     6,    -1,   316,
      -1,   219,   315,   220,    -1,   210,   315,    -1,   209,   315,
      -1,   214,   315,    -1,   315,   210,   315,    -1,   315,   209,
     315,    -1,   315,   211,   315,    -1,   315,   212,   315,    -1,
     315,   213,   315,    -1,   315,   218,   315,    -1,   315,   205,
     315,    -1,   315,   206,   315,    -1,   315,   208,   315,    -1,
     315,   207,   315,    -1,   315,   204,   315,    -1,   315,   203,
     315,    -1,   315,   202,   315,    -1,   315,   201,   315,    -1,
     315,   200,   315,     8,   315,    -1,    15,   253,   315,   254,
      -1,    16,   253,   315,   254,    -1,    17,   253,   315,   254,
      -1,    18,   253,   315,   254,    -1,    19,   253,   315,   254,
      -1,    20,   253,   315,   254,    -1,    21,   253,   315,   254,
      -1,    22,   253,   315,   254,    -1,    23,   253,   315,   254,
      -1,    25,   253,   315,   254,    -1,    26,   253,   315,   225,
     315,   254,    -1,    27,   253,   315,   254,    -1,    28,   253,
     315,   254,    -1,    29,   253,   315,   254,    -1,    30,   253,
     315,   254,    -1,    31,   253,   315,   254,    -1,    32,   253,
     315,   254,    -1,    33,   253,   315,   254,    -1,    34,   253,
     315,   225,   315,   254,    -1,    35,   253,   315,   225,   315,
     254,    -1,    36,   253,   315,   225,   315,   254,    -1,    24,
     253,   315,   254,    -1,     3,    -1,     9,    -1,    14,    -1,
      10,    -1,    11,    -1,   189,    -1,   190,    -1,   191,    -1,
      72,    -1,    73,    -1,    74,    -1,    -1,    80,   253,   315,
     317,   264,   254,    -1,   183,   253,   328,   254,    -1,   183,
     253,   328,   225,   315,   254,    -1,   333,    -1,     4,   221,
     315,   222,    -1,     4,   219,   315,   220,    -1,   332,   221,
     315,   222,    -1,   332,   219,   315,   220,    -1,   187,   219,
     333,   220,    -1,   188,   219,   329,   220,    -1,   224,   333,
     253,   254,    -1,   333,   252,    -1,     4,   221,   315,   222,
     252,    -1,     4,   219,   315,   220,   252,    -1,   332,   221,
     315,   222,   252,    -1,   332,   219,   315,   220,   252,    -1,
       4,   223,     4,    -1,     4,   221,   315,   222,   223,     4,
      -1,     4,   223,     4,   252,    -1,     4,   221,   315,   222,
     223,     4,   252,    -1,   179,   219,   328,   225,   315,   220,
      -1,    54,   219,   321,   225,   321,   220,    -1,    55,   253,
     328,   225,   328,   254,    -1,    53,   253,   328,   254,    -1,
      56,   253,   328,   225,   328,   254,    -1,    61,   219,   331,
     220,    -1,   319,    -1,   210,   318,    -1,   209,   318,    -1,
     318,   210,   318,    -1,   318,   209,   318,    -1,   226,   315,
     225,   315,   225,   315,   225,   315,   225,   315,   227,    -1,
     226,   315,   225,   315,   225,   315,   225,   315,   227,    -1,
     226,   315,   225,   315,   225,   315,   227,    -1,   219,   315,
     225,   315,   225,   315,   220,    -1,   321,    -1,   320,   225,
     321,    -1,   315,    -1,   323,    -1,   226,   227,    -1,   226,
     324,   227,    -1,   210,   226,   324,   227,    -1,   315,   211,
     226,   324,   227,    -1,   321,    -1,     5,    -1,   210,   323,
      -1,   315,   211,   323,    -1,   315,     8,   315,    -1,   315,
       8,   315,     8,   315,    -1,    84,   226,   315,   227,    -1,
      84,     5,    -1,    87,     5,    -1,    90,     5,    -1,    92,
       5,    -1,   112,    84,     5,    -1,   112,    87,     5,    -1,
     112,    90,     5,    -1,   112,    92,     5,    -1,   112,    84,
     226,   324,   227,    -1,   112,    87,   226,   324,   227,    -1,
     112,    90,   226,   324,   227,    -1,   112,    92,   226,   324,
     227,    -1,    84,   164,    62,   226,   315,   225,   315,   225,
     315,   225,   315,   225,   315,   225,   315,   227,    -1,    87,
     164,    62,   226,   315,   225,   315,   225,   315,   225,   315,
     225,   315,   225,   315,   227,    -1,    90,   164,    62,   226,
     315,   225,   315,   225,   315,   225,   315,   225,   315,   225,
     315,   227,    -1,    92,   164,    62,   226,   315,   225,   315,
     225,   315,   225,   315,   225,   315,   225,   315,   227,    -1,
     275,    -1,   286,    -1,   304,    -1,     4,   253,   254,    -1,
     332,   253,   254,    -1,    37,   221,   333,   222,    -1,    37,
     221,   323,   222,    -1,    37,   219,   323,   220,    -1,    37,
     221,   226,   324,   227,   222,    -1,    37,   219,   226,   324,
     227,   220,    -1,     4,   253,   226,   324,   227,   254,    -1,
     332,   253,   226,   324,   227,   254,    -1,    38,   253,   315,
     225,   315,   225,   315,   254,    -1,    39,   253,   315,   225,
     315,   225,   315,   254,    -1,    40,   253,   328,   254,    -1,
      41,   253,   315,   225,   315,   225,   315,   225,   315,   225,
     315,   225,   315,   254,    -1,   315,    -1,   323,    -1,   324,
     225,   315,    -1,   324,   225,   323,    -1,   226,   315,   225,
     315,   225,   315,   225,   315,   227,    -1,   226,   315,   225,
     315,   225,   315,   227,    -1,   333,    -1,     4,   223,   161,
     223,     4,    -1,   226,   327,   227,    -1,     4,   221,   315,
     222,   223,   162,    -1,   325,    -1,   327,   225,   325,    -1,
     329,    -1,   333,    -1,     4,   221,   315,   222,    -1,   332,
     221,   315,   222,    -1,     4,   219,   315,   220,    -1,   332,
     219,   315,   220,    -1,     4,   223,     4,    -1,     4,   221,
     315,   222,   223,     4,    -1,     5,    -1,   194,   221,   333,
     222,    -1,    65,    -1,   192,    -1,    70,    -1,   181,   219,
     328,   220,    -1,   180,   219,   328,   225,   328,   220,    -1,
     182,   253,   328,   254,    -1,   182,   253,   328,   225,   328,
     254,    -1,    46,   253,   331,   254,    -1,    47,   219,   328,
     220,    -1,    48,   219,   328,   220,    -1,    49,   219,   328,
     225,   328,   225,   328,   220,    -1,    44,   253,   331,   254,
      -1,    58,   253,   328,   254,    -1,    59,   253,   328,   254,
      -1,    60,   253,   328,   254,    -1,    57,   253,   315,   225,
     328,   225,   328,   254,    -1,    52,   253,   328,   225,   315,
     225,   315,   254,    -1,    52,   253,   328,   225,   315,   254,
      -1,    45,   253,   328,   254,    -1,    45,   253,   328,   225,
     324,   254,    -1,    66,   253,   328,   254,    -1,    67,    -1,
      51,   253,   328,   254,    -1,    50,   253,   328,   254,    -1,
      -1,    81,   253,   329,   330,   266,   254,    -1,   328,    -1,
     331,   225,   328,    -1,     4,   228,   226,   315,   227,    -1,
     332,   228,   226,   315,   227,    -1,     4,    -1,   332,    -1,
     195,   221,   328,   222,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   209,   209,   210,   215,   217,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   243,   247,   254,   259,   264,
     278,   291,   304,   332,   346,   359,   372,   391,   396,   397,
     398,   399,   400,   404,   406,   411,   413,   419,   523,   418,
     541,   548,   559,   558,   576,   583,   594,   593,   610,   627,
     650,   649,   663,   664,   665,   666,   667,   671,   672,   678,
     678,   679,   679,   685,   686,   687,   692,   698,   760,   777,
     806,   835,   840,   845,   850,   855,   862,   872,   901,   930,
     935,   940,   945,   953,   962,   968,   974,   987,  1000,  1015,
    1032,  1038,  1044,  1057,  1070,  1085,  1102,  1108,  1117,  1135,
    1153,  1162,  1174,  1179,  1187,  1207,  1230,  1241,  1249,  1271,
    1294,  1332,  1353,  1365,  1379,  1379,  1381,  1383,  1392,  1402,
    1401,  1422,  1421,  1440,  1439,  1457,  1467,  1466,  1480,  1482,
    1490,  1496,  1501,  1527,  1528,  1532,  1543,  1558,  1568,  1569,
    1574,  1582,  1591,  1599,  1617,  1621,  1627,  1635,  1639,  1645,
    1653,  1657,  1663,  1671,  1675,  1681,  1690,  1693,  1706,  1709,
    1717,  1727,  1755,  1798,  1821,  1850,  1871,  1889,  1929,  1959,
    1977,  1995,  2022,  2051,  2056,  2074,  2120,  2138,  2177,  2183,
    2189,  2196,  2237,  2263,  2287,  2312,  2329,  2333,  2352,  2386,
    2433,  2451,  2468,  2486,  2490,  2506,  2554,  2564,  2574,  2584,
    2594,  2604,  2651,  2662,  2678,  2679,  2684,  2687,  2691,  2720,
    2749,  2778,  2812,  2834,  2860,  2882,  2905,  2926,  2982,  3006,
    3031,  3057,  3170,  3189,  3232,  3246,  3252,  3267,  3295,  3312,
    3321,  3335,  3349,  3355,  3361,  3370,  3379,  3388,  3402,  3464,
    3482,  3499,  3514,  3543,  3555,  3579,  3583,  3588,  3596,  3601,
    3607,  3612,  3618,  3626,  3630,  3634,  3639,  3699,  3715,  3732,
    3749,  3771,  3793,  3828,  3836,  3844,  3850,  3857,  3864,  3884,
    3910,  3922,  3934,  3942,  3950,  3959,  3958,  3973,  3972,  3987,
    3986,  4001,  4000,  4014,  4021,  4028,  4035,  4042,  4049,  4056,
    4063,  4070,  4078,  4077,  4091,  4090,  4104,  4103,  4117,  4116,
    4130,  4129,  4143,  4142,  4156,  4155,  4169,  4168,  4182,  4181,
    4198,  4201,  4207,  4219,  4239,  4263,  4267,  4271,  4275,  4279,
    4283,  4289,  4295,  4299,  4303,  4307,  4311,  4330,  4343,  4344,
    4345,  4346,  4347,  4351,  4352,  4353,  4356,  4381,  4406,  4428,
    4431,  4447,  4450,  4467,  4470,  4476,  4479,  4486,  4489,  4496,
    4552,  4622,  4627,  4694,  4730,  4738,  4781,  4820,  4840,  4872,
    4899,  4925,  4951,  4977,  5003,  5025,  5053,  5081,  5109,  5137,
    5165,  5204,  5243,  5264,  5285,  5312,  5316,  5326,  5361,  5362,
    5363,  5367,  5373,  5385,  5403,  5431,  5432,  5433,  5434,  5435,
    5436,  5437,  5438,  5439,  5446,  5447,  5448,  5449,  5450,  5451,
    5452,  5453,  5454,  5455,  5456,  5457,  5458,  5459,  5460,  5461,
    5462,  5463,  5464,  5465,  5466,  5467,  5468,  5469,  5470,  5471,
    5472,  5473,  5474,  5475,  5476,  5477,  5478,  5487,  5488,  5489,
    5490,  5491,  5492,  5493,  5494,  5495,  5496,  5497,  5502,  5501,
    5509,  5514,  5519,  5536,  5554,  5572,  5590,  5608,  5613,  5619,
    5634,  5653,  5673,  5693,  5713,  5736,  5741,  5746,  5756,  5766,
    5771,  5782,  5791,  5796,  5801,  5828,  5832,  5836,  5840,  5844,
    5851,  5855,  5859,  5863,  5870,  5875,  5882,  5887,  5891,  5896,
    5900,  5908,  5919,  5923,  5935,  5943,  5951,  5958,  5968,  5997,
    6001,  6005,  6009,  6013,  6017,  6021,  6025,  6029,  6058,  6087,
    6116,  6145,  6158,  6171,  6184,  6197,  6207,  6217,  6227,  6239,
    6252,  6264,  6268,  6272,  6276,  6280,  6298,  6316,  6324,  6332,
    6361,  6374,  6379,  6383,  6387,  6399,  6403,  6415,  6432,  6442,
    6446,  6461,  6466,  6473,  6477,  6490,  6504,  6518,  6532,  6546,
    6554,  6565,  6569,  6573,  6581,  6587,  6593,  6601,  6609,  6616,
    6624,  6639,  6653,  6667,  6679,  6695,  6704,  6713,  6723,  6734,
    6742,  6750,  6754,  6773,  6780,  6786,  6793,  6801,  6800,  6813,
    6818,  6824,  6833,  6846,  6849,  6853
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
  "tCone", "tEllipsoid", "tQuadric", "tShapeFromFile", "tCharacteristic",
  "tLength", "tParametric", "tElliptic", "tRefineMesh", "tAdaptMesh",
  "tRelocateMesh", "tSetFactory", "tThruSections", "tPlane", "tRuled",
  "tTransfinite", "tComplex", "tPhysical", "tCompound", "tPeriodic",
  "tUsing", "tPlugin", "tDegenerated", "tRecursive", "tRotate",
  "tTranslate", "tSymmetry", "tDilate", "tExtrude", "tLevelset", "tAffine",
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
      63,   455,   456,   457,   458,    60,    62,   459,   460,    43,
      45,    42,    47,    37,    33,   461,   462,   463,    94,    40,
      41,    91,    93,    46,    35,    44,   123,   125,   126
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   229,   230,   230,   231,   231,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   233,   233,   234,   234,   234,
     234,   234,   234,   235,   235,   235,   235,   236,   236,   236,
     236,   236,   236,   237,   237,   238,   238,   240,   241,   239,
     242,   242,   244,   243,   245,   245,   247,   246,   248,   248,
     250,   249,   251,   251,   251,   251,   251,   252,   252,   253,
     253,   254,   254,   255,   255,   255,   255,   255,   255,   255,
     255,   255,   255,   255,   255,   255,   255,   255,   255,   255,
     255,   255,   255,   255,   255,   255,   255,   255,   255,   255,
     255,   255,   255,   255,   255,   255,   255,   255,   255,   255,
     255,   255,   255,   255,   255,   255,   255,   255,   255,   255,
     255,   255,   255,   255,   256,   256,   257,   257,   257,   258,
     257,   259,   257,   260,   257,   257,   261,   257,   262,   262,
     263,   263,   263,   264,   264,   265,   265,   265,   266,   266,
     267,   267,   267,   267,   268,   268,   268,   269,   269,   269,
     270,   270,   270,   271,   271,   271,   272,   272,   273,   273,
     274,   274,   274,   274,   274,   274,   274,   274,   274,   274,
     274,   274,   274,   274,   274,   274,   274,   274,   274,   274,
     274,   274,   274,   274,   274,   274,   274,   274,   274,   274,
     274,   274,   274,   274,   274,   274,   275,   275,   275,   275,
     275,   275,   275,   275,   276,   276,   277,   277,   277,   277,
     277,   277,   278,   278,   278,   278,   278,   278,   278,   278,
     278,   278,   278,   278,   279,   279,   279,   279,   279,   280,
     280,   281,   282,   282,   282,   282,   282,   282,   283,   283,
     283,   283,   283,   283,   283,   283,   283,   283,   283,   283,
     283,   283,   283,   283,   283,   283,   283,   284,   285,   285,
     285,   285,   285,   285,   285,   285,   285,   285,   285,   285,
     285,   285,   286,   286,   286,   287,   286,   288,   286,   289,
     286,   290,   286,   286,   286,   286,   286,   286,   286,   286,
     286,   286,   291,   286,   292,   286,   293,   286,   294,   286,
     295,   286,   296,   286,   297,   286,   298,   286,   299,   286,
     300,   300,   301,   301,   301,   301,   301,   301,   301,   301,
     301,   301,   301,   301,   301,   301,   301,   301,   302,   302,
     302,   302,   302,   303,   303,   303,   304,   304,   305,   306,
     306,   307,   307,   308,   308,   309,   309,   310,   310,   311,
     311,   311,   311,   311,   311,   311,   311,   311,   311,   311,
     311,   311,   311,   311,   311,   311,   311,   311,   311,   311,
     311,   311,   311,   311,   311,   312,   312,   312,   313,   313,
     313,   314,   314,   314,   314,   315,   315,   315,   315,   315,
     315,   315,   315,   315,   315,   315,   315,   315,   315,   315,
     315,   315,   315,   315,   315,   315,   315,   315,   315,   315,
     315,   315,   315,   315,   315,   315,   315,   315,   315,   315,
     315,   315,   315,   315,   315,   315,   315,   316,   316,   316,
     316,   316,   316,   316,   316,   316,   316,   316,   317,   316,
     316,   316,   316,   316,   316,   316,   316,   316,   316,   316,
     316,   316,   316,   316,   316,   316,   316,   316,   316,   316,
     316,   316,   316,   316,   316,   318,   318,   318,   318,   318,
     319,   319,   319,   319,   320,   320,   321,   321,   321,   321,
     321,   321,   322,   322,   323,   323,   323,   323,   323,   323,
     323,   323,   323,   323,   323,   323,   323,   323,   323,   323,
     323,   323,   323,   323,   323,   323,   323,   323,   323,   323,
     323,   323,   323,   323,   323,   323,   323,   323,   323,   323,
     323,   324,   324,   324,   324,   325,   325,   325,   325,   326,
     326,   327,   327,   328,   328,   328,   328,   328,   328,   328,
     328,   329,   329,   329,   329,   329,   329,   329,   329,   329,
     329,   329,   329,   329,   329,   329,   329,   329,   329,   329,
     329,   329,   329,   329,   329,   329,   329,   330,   329,   331,
     331,   332,   332,   333,   333,   333
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
      10,     7,     7,     7,     7,     8,     4,     8,    12,     8,
       8,     7,     7,     4,     8,     8,     5,    11,     5,     9,
       9,     4,     9,     9,     1,     1,     0,     2,     6,     6,
       6,     6,     8,    10,    14,    16,    12,    14,    14,    14,
      14,     8,     8,     6,     4,     6,     6,     3,     4,     5,
       6,     5,     3,     3,     4,     5,     4,     5,     3,     5,
       7,     7,     3,     7,     3,     2,     2,     2,     2,     2,
      15,     2,     2,     2,     2,     2,    16,    11,     6,     8,
       8,    10,     1,     2,     2,     1,     3,     3,     4,     4,
       1,     1,     5,    11,    13,     0,     7,     0,    13,     0,
      15,     0,     6,     8,     8,     8,    12,    12,    12,    14,
      14,    14,     0,    12,     0,    12,     0,    12,     0,    16,
       0,    16,     0,    16,     0,    18,     0,    18,     0,    18,
       1,     2,     5,     7,     9,     2,     2,     3,     2,     3,
       2,     3,     2,     3,     2,     3,     9,     6,     1,     1,
       1,     1,     1,     0,     2,     3,     9,     4,    14,     0,
       3,     0,     1,     0,     2,     0,     2,     0,     2,     7,
       6,     8,     5,     3,     8,     5,     4,     6,    11,    11,
      18,    18,    12,    12,    12,    10,    10,    10,    10,    10,
       4,     4,     4,     4,     4,     2,     3,     6,     1,     1,
       1,     2,     5,     7,    10,     1,     3,     2,     2,     2,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     5,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     6,     4,     4,     4,     4,
       4,     4,     4,     6,     6,     6,     4,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     6,
       4,     6,     1,     4,     4,     4,     4,     4,     4,     4,
       2,     5,     5,     5,     5,     3,     6,     4,     7,     6,
       6,     6,     4,     6,     4,     1,     2,     2,     3,     3,
      11,     9,     7,     7,     1,     3,     1,     1,     2,     3,
       4,     5,     1,     1,     2,     3,     3,     5,     4,     2,
       2,     2,     2,     3,     3,     3,     3,     5,     5,     5,
       5,    16,    16,    16,    16,     1,     1,     1,     3,     3,
       4,     4,     4,     6,     6,     6,     6,     8,     8,     4,
      14,     1,     1,     3,     3,     9,     7,     1,     5,     3,
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
       0,     0,     0,     2,     3,     1,   583,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   338,
     339,   340,   341,   342,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   272,     0,     0,   280,   281,     0,     0,     0,
     275,     0,     0,     0,     0,     0,   388,   389,   390,     0,
       0,     5,     7,     6,     8,     9,    10,    23,    11,    12,
      13,    14,    22,    21,    20,    15,     0,    16,    17,    18,
      19,     0,    24,   584,     0,   437,   583,   551,   438,   440,
     441,   439,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   553,     0,   574,   555,   445,   446,   447,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   442,
     443,   444,   554,     0,     0,     0,     0,    69,    70,     0,
       0,   216,     0,     0,     0,   395,     0,   543,   584,   452,
       0,     0,     0,     0,   259,     0,   261,   262,   257,   258,
       0,   263,   264,   126,   138,    69,    70,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   265,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   475,     0,     0,     0,     0,     0,   216,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   583,     0,   216,   584,     0,     0,   385,     0,     0,
       0,     0,     0,     0,     0,     0,   583,   493,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   515,   516,     0,   517,   486,   492,     0,   487,   584,
     452,     0,     0,     0,     0,   583,     0,     0,   537,     0,
       0,     0,     0,   255,   256,     0,   583,     0,     0,     0,
     273,   274,     0,   216,     0,   216,   583,     0,   584,     0,
       0,   216,   391,     0,     0,    69,    70,     0,     0,    62,
      66,    65,    64,    63,    68,    67,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   398,   397,   399,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   215,     0,   214,     0,
       0,   252,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    37,   248,     0,
       0,   460,   188,     0,   583,     0,   543,   584,   544,     0,
       0,   579,     0,   124,   124,     0,     0,     0,     0,   531,
     532,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   353,   353,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   216,   216,     0,
     477,   476,     0,     0,     0,     0,   216,   216,     0,     0,
       0,     0,     0,     0,     0,   291,     0,   216,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   355,     0,     0,
       0,     0,     0,     0,     0,   237,   386,     0,     0,     0,
       0,     0,     0,     0,     0,    69,    70,     0,     0,     0,
       0,     0,     0,     0,     0,   499,     0,     0,   500,     0,
     501,     0,   502,     0,     0,     0,     0,     0,     0,   397,
     494,     0,   488,     0,     0,     0,   363,    69,    70,     0,
     254,     0,     0,     0,     0,     0,   216,     0,     0,     0,
       0,     0,   277,   276,     0,   242,     0,   243,     0,     0,
       0,   216,     0,     0,     0,     0,   343,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    78,     0,     0,
       0,   465,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   448,   577,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    62,    63,     0,   396,    62,    63,
       0,     0,    62,     0,     0,     0,     0,     0,   211,     0,
       0,     0,     0,   217,     0,     0,     0,   413,   412,   411,
     410,   406,   407,   409,   408,   401,   400,   402,   403,   404,
     405,     0,     0,     0,   189,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   125,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   347,     0,     0,     0,     0,   382,   383,   384,     0,
       0,     0,     0,     0,     0,   351,     0,     0,     0,   154,
     155,     0,   157,   158,     0,   160,   161,     0,   163,   164,
       0,   183,     0,   196,     0,   203,     0,     0,     0,     0,
     175,   216,     0,     0,     0,     0,     0,   479,   478,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   285,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     366,     0,     0,   238,     0,     0,   234,     0,     0,     0,
     381,   380,     0,     0,     0,     0,     0,   465,    71,    72,
       0,   518,     0,     0,     0,     0,     0,   452,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   503,     0,   504,
       0,   505,     0,   506,     0,     0,   396,   489,   496,     0,
     402,   495,     0,     0,     0,   519,     0,     0,     0,     0,
       0,     0,     0,     0,   278,   279,     0,     0,   244,   246,
       0,   585,     0,     0,     0,     0,     0,     0,    62,    63,
       0,     0,    62,    63,     0,     0,     0,     0,    93,    77,
       0,   454,   453,   467,   415,   416,   417,   418,   419,   420,
     421,   422,   423,   436,   424,     0,   426,   427,   428,   429,
     430,   431,   432,     0,     0,     0,   564,     0,   571,   560,
     561,   562,     0,   576,   575,     0,   472,     0,     0,     0,
       0,   565,   566,   567,   474,   573,   143,   148,   116,     0,
       0,   556,     0,   558,     0,   450,   457,   458,   552,     0,
       0,     0,    62,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   110,     0,     0,     0,     0,   459,     0,
       0,     0,     0,   581,     0,     0,    47,     0,     0,     0,
      60,     0,    38,    39,    40,    41,    42,   456,   455,     0,
       0,   549,    27,    25,     0,     0,     0,     0,    28,     0,
       0,   249,   580,    73,   127,    74,   139,     0,     0,     0,
     533,   534,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     170,     0,     0,     0,   349,   354,   352,     0,   362,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   396,   396,
     396,     0,     0,     0,     0,     0,   245,   247,     0,     0,
       0,   206,   208,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   320,     0,
     282,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   356,   365,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   454,   453,     0,     0,   522,     0,   521,
     520,     0,     0,   529,     0,     0,   498,     0,     0,     0,
       0,     0,     0,     0,   490,     0,     0,   456,   455,     0,
       0,     0,     0,     0,     0,   239,     0,     0,     0,     0,
       0,   241,     0,   344,     0,     0,     0,     0,   392,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   582,
       0,     0,   462,     0,   461,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    87,     0,    91,     0,     0,
      79,     0,     0,     0,     0,    83,   106,   108,     0,     0,
     541,     0,   114,     0,     0,     0,     0,     0,   414,     0,
       0,     0,     0,     0,    33,   464,   463,   547,   545,    26,
       0,     0,   548,   546,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   168,   168,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   173,     0,
       0,     0,     0,     0,     0,     0,     0,   360,     0,     0,
     156,     0,   159,     0,   162,     0,   165,     0,     0,     0,
       0,     0,     0,     0,   240,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   326,     0,     0,   325,     0,   332,
       0,   334,     0,   328,     0,   330,     0,   292,   321,     0,
       0,     0,   233,     0,     0,     0,     0,     0,     0,     0,
     367,     0,   236,   235,   387,     0,     0,    34,    35,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   507,   508,   509,   510,   497,   491,     0,     0,     0,
       0,   538,     0,     0,     0,   268,     0,     0,     0,   216,
     345,   216,     0,     0,     0,     0,    88,     0,    92,     0,
       0,    80,     0,    84,     0,   251,   466,   250,   425,   433,
     434,   435,   572,     0,     0,   570,   470,   471,   473,     0,
       0,   449,   144,     0,   578,   149,   469,   557,   559,   451,
       0,     0,     0,    89,     0,     0,     0,    62,     0,     0,
       0,     0,    81,     0,     0,     0,   539,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   484,     0,     0,    29,
      30,     0,    31,     0,     0,   128,   135,     0,     0,    75,
      76,   171,     0,     0,     0,     0,     0,     0,   174,     0,
       0,   191,   192,     0,     0,   176,   201,   193,   194,     0,
       0,     0,   202,     0,   166,     0,   359,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   253,     0,
       0,     0,     0,   216,   216,     0,   302,     0,   304,     0,
     306,     0,   327,   486,     0,     0,   333,   335,   329,   331,
       0,     0,   286,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   466,   525,   524,
     523,     0,     0,     0,     0,     0,     0,     0,   526,   179,
     180,     0,     0,     0,     0,   117,   121,     0,     0,   343,
     343,     0,   393,     0,     0,     0,    90,     0,     0,     0,
      82,     0,   468,     0,     0,     0,     0,     0,     0,   100,
       0,     0,    94,     0,     0,     0,     0,   111,     0,     0,
     112,     0,   542,   218,   219,   220,   221,     0,     0,    43,
       0,     0,     0,     0,     0,    45,   550,     0,     0,   129,
     136,     0,     0,     0,     0,   169,   177,   178,   182,     0,
       0,   195,     0,     0,   361,     0,   186,     0,     0,   350,
     200,   172,   185,   199,   205,   184,     0,   197,   204,     0,
       0,     0,     0,     0,     0,   483,     0,   482,     0,     0,
       0,   293,     0,     0,   294,     0,     0,   295,     0,     0,
       0,     0,     0,     0,     0,   232,   231,     0,     0,     0,
       0,     0,     0,     0,     0,   222,     0,     0,   364,    36,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   536,
       0,   270,   269,     0,     0,     0,     0,     0,     0,     0,
     101,     0,     0,    95,     0,     0,     0,   563,   569,   568,
       0,   145,   147,     0,   150,   151,   152,   102,   104,    96,
      98,   107,   109,     0,   115,     0,    85,    48,     0,     0,
       0,   485,     0,     0,     0,    32,     0,   143,   148,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   187,
       0,   357,   357,     0,   122,   123,   216,     0,   209,   210,
       0,     0,     0,     0,     0,     0,     0,   322,     0,     0,
     216,     0,     0,     0,     0,     0,     0,     0,     0,   213,
     212,   527,   528,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   118,   119,     0,     0,   346,     0,   103,   105,
      97,    99,    86,     0,   531,   532,     0,     0,   540,     0,
      44,     0,     0,     0,    46,    61,     0,     0,     0,   133,
     131,   375,   377,   376,   378,   379,   190,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     481,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     337,     0,     0,     0,   287,     0,   223,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   535,
     271,     0,     0,   216,   394,     0,   146,     0,     0,   153,
     113,     0,     0,     0,     0,     0,   130,   137,   143,   143,
       0,     0,     0,     0,     0,   358,   368,     0,     0,   369,
       0,   207,     0,   308,     0,     0,   310,     0,     0,   312,
       0,     0,     0,   323,     0,   283,     0,   216,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   181,
     120,   267,   343,     0,   140,     0,     0,    52,     0,    58,
       0,     0,     0,     0,     0,   167,   198,     0,   372,     0,
     373,   374,   480,   296,     0,     0,   303,   297,     0,     0,
     305,   298,     0,     0,   307,     0,     0,     0,   289,   226,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   134,
     132,     0,     0,     0,     0,   314,     0,   316,     0,   318,
     324,   336,   288,   284,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   141,   142,    49,
       0,    56,     0,     0,     0,     0,     0,     0,   299,     0,
       0,   300,     0,     0,   301,     0,     0,   227,   228,   229,
     230,     0,   224,     0,     0,     0,     0,     0,   348,     0,
      50,     0,     0,   260,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   290,     0,   530,     0,     0,     0,     0,
       0,     0,     0,     0,   266,     0,     0,   309,     0,   311,
       0,   313,     0,   225,     0,     0,     0,     0,    51,    53,
       0,    54,     0,     0,     0,     0,     0,     0,   511,   512,
     513,   514,     0,     0,    59,   370,   371,   315,   317,   319,
      55,    57
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,   101,  1064,   102,   103,   761,  1638,  1644,
    1052,  1279,  1849,  2089,  1053,  2025,  2130,  1054,  2091,  1055,
    1056,  1283,   386,   481,   203,   891,   104,   779,   493,  1777,
    1929,  1928,  1778,   494,  1843,  1247,  1452,  1248,  1455,   818,
     821,   824,   827,  1668,  1505,   743,   331,   457,   458,   107,
     108,   109,   110,   111,   112,   113,   114,   332,  1151,  1956,
    2044,   856,  1692,  1695,  1698,  1994,  1998,  2002,  2069,  2072,
    2075,  1147,  1148,   333,   944,   334,   118,  1326,  1107,   815,
     869,  1873,   119,   120,   121,   122,   335,   205,  1006,   551,
     281,  1485,   336,   337,   338,   623,   347,  1037,  1271,   491,
     486,  1007,   492,   368,   340
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1742
static const yytype_int16 yypact[] =
{
   10410,     8,    22, 10557, -1742, -1742,  4286,    69,   -42,  -161,
    -133,    49,   146,   157,   190,   223,    -8,   237,   297,    -1,
      67,  -145,  -145,  -194,    20,    73,    19,    98,   110,    31,
     141,   167,   188,   191,   211,   278,   361,   364,   455,   267,
     366,   315,   337,   488,   497,   806,   467,   742,   852,   -43,
     398,   533,   -99,   399,   -95,   -95,   403,   236,    38, -1742,
   -1742, -1742, -1742, -1742,   316,   553,   616,    26,    63,   624,
     651,    52,   745,   756,   763,  5570,   771,   527,   565,   570,
      27,    14, -1742,   571,   589, -1742, -1742,   803,   858,   623,
   -1742,  4382,   646,  5048,    40,    41, -1742, -1742, -1742, 10256,
     662, -1742, -1742, -1742, -1742, -1742, -1742, -1742, -1742, -1742,
   -1742, -1742, -1742, -1742, -1742, -1742,  -106, -1742, -1742, -1742,
   -1742,    55, -1742,   144,   270, -1742,     7, -1742, -1742, -1742,
   -1742, -1742,  -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,
    -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,
    -145,  -145,  -145,  -145,  -145,  -145,  -145,   650,   683,   684,
    -145,  -145,  -145,  -145,   696,  -145,  -145,  -145,  -145,  -145,
    -145,   714, -1742,  -145, -1742, -1742, -1742, -1742, -1742,  -145,
    -145,   870,   722,   727,   738,  -145,  -145,   746,   749, -1742,
   -1742, -1742, -1742,   772, 10256, 10256, 10256,  9404,  9471,   149,
      24,   632,   761,   780,   612, -1742,   784,   971,   416,   274,
     992, 10256,  4930,  4930, -1742, 10256, -1742, -1742, -1742, -1742,
    4930, -1742, -1742, -1742, -1742, -1742, -1742,  5447,    24, 10256,
    9192, 10256, 10256,   792, 10256,  9192, 10256, 10256,   795,  9192,
   10256, 10256, 10256, 10256,  4930,  6515,   796,   793, -1742,  9192,
    5570,  5570,  5570,  4930, 10256,   811,   812,  5570,  5570,  5570,
     825,   840,   841,   848,   860,  6733,  6951,  7169,   809,  8695,
    1046,  6515,    27,   828,   861,   -95,   -95,   -95, 10256, 10256,
    -156, -1742,   -65,   -95,   862,   867,   919,  8762,   -31,   -89,
     907,   927,   959,   962,   975,   981,   982,  5570,  5570,  6515,
     988,    23,   950, -1742,   983,  1184,  1206, -1742,  1027,  1028,
    1051,  5570,  5570,  1084,  1093,  1095,   691, -1742,  -103,  -145,
    -145,  -145,  -145,    35,    16,    21,    28,   874,  7387, 10256,
    4742, -1742, -1742,  1078, -1742,  3431, -1742,  1242, -1742,   419,
     158,  1266, 10256, 10256, 10256,  -189, 10256,  1092, -1742,  1155,
   10256, 10256, 10256, -1742, -1742, 10256,  1094,  1317,  1318,  1101,
   -1742, -1742,  1323, -1742,  1325, -1742,   699,  8722,   676,  4930,
   10256, -1742, -1742,  6515,  6515,  9688,  9755,  1107,  1111,  5447,
   -1742, -1742, -1742, -1742, -1742, -1742,  6515,  1332,  1118, 10256,
   10256,  1350, 10256, 10256, 10256, 10256, 10256, 10256, 10256, 10256,
   10256, 10256, 10256, 10256, 10256, 10256, 10256, 10256, 10256, 10256,
   10256, 10256, 10256, 10256,  4930,  4930,  4930,  4930,  4930,  4930,
    4930,  4930,  4930,  4930,  6515,  4930,  4930, 10256,  4930,  4930,
    4930,  4930,  4930, 10256,  5447, 10256,  4930,  4930,  4930,  4930,
    4930,    24,  5447,    24,  1137,  1137,  1137,   101, 12293,   197,
   11902,   282,  1133,  1351,  -145,  1134, -1742,  1135,  5625, 10256,
    9192, -1742, 10256, 10256, 10256, 10256, 10256, 10256, 10256, 10256,
   10256, 10256, 10256, 10256, 10256, 10256, 10256, -1742, -1742, 10256,
   10256, -1742, -1742,   648,   717,  -126, -1742,   704, -1742,    87,
   10095, -1742,   117,  -118,   -71,  1136,  1138, 12314,  9192,  3657,
   -1742,   214, 12335, 12356, 10256, 12377,   246, 12398, 12419, 10256,
     247, 12440, 12461, 12482, 12503,  1152,  1366, 10256, 10256,   308,
    1368,  1371,  1373,  1160, 12524, 10256, 10256,  1388,  1389,  1389,
   10256,  8980,  8980,  8980,  8980, 10256,  1391, 10256,  1392, 10256,
    1394,  9192,  9192,  9811,  1198,  1395,  1193, -1742, -1742,   -98,
   -1742, -1742, 10137, 10163,   -95,   -95,   632,   632,   121, 10256,
   10256, 10256,  8762,  8762, 10256,  5625,   129, -1742, 10256, 10256,
   10256, 10256, 10256, 10256, 10256, 10256, 10256,  1413,  1417,  1418,
   10256,  1423, 10256, 10256,  1258, -1742, -1742,  9192,  9192,  9192,
    1424,  1425, 10256, 10256, 10256, 10256, 10256,  1420,   102,  7605,
    7823, 10256, 10256,  4930, 10256, -1742,  1370, 10256, -1742,  1372,
   -1742,  1377, -1742,  1379,    44,    45,    46,    47,  9192,  1137,
   -1742, 12545, -1742,   338, 10256,  8041, -1742, 10256, 10256,   498,
   -1742, 12566, 12587, 12608,  1272, 10190, -1742,  1209,  3773, 12629,
   12650, 11925, -1742, -1742,  9192, -1742,  1913, -1742,  2171, 10256,
   10256, -1742, 10256, 10256,  1220, 12671,  5816,  1227,   425,   201,
   12692,   205, 11948, 10256,  9192,  1443,  1444, -1742, 10256, 12713,
   11971,   314, 11879, 11879, 11879, 11879, 11879, 11879, 11879, 11879,
   11879, 11879, 11879, 10553, 11879, 11879, 11879, 11879, 11879, 11879,
   11879, 10579, 10605, 10631,   272,   506,   272,  1246,  1247,  1243,
     446,   446,  1244,   446,  1248,  1250,  1251, 10657,   446,   446,
     446,   162,   446, 13343, -1742,   900,  1254,  1255,  1261,   750,
     760,  1262,  1267,  1249,  1442,  1445,  6515,   286,  1446,  1448,
    6515,   136,  5447, 10256,  1487,  1495,    33,   446, -1742,   -33,
      39,    34,   -19, -1742,  4815,   461,  3799,   592,  1199,   816,
     816,   627,   627,   627,   627,   -63,   -63,  1137,  1137,  1137,
    1137,    13, 12734, 11994, -1742, 10256, 10256,  1496,     9,  9192,
   10256, 10256,  1497,  9192, 10256,  1513,  4930,  1514, -1742,    24,
    1515,  4930, 10256,  5447,  1494,  9192,  9192,  1338,  1517,  1519,
   12755,  1520,  1358,  1521,  1524, 12776,  1361,  1529,  1530,  1531,
    1532, -1742, 10256, 12797,  4855,  1319, -1742, -1742, -1742,  1537,
    1539, 12818, 12839, 10256,  6515,  1543,  1542, 12860,  1330, 13343,
    1326,  1334, 13343,  1331,  1335, 13343,  1333,  1337, 13343,  1340,
   12881, -1742, 12902, -1742, 12923, -1742,   606,   744,  9192,  1336,
   -1742, -1742,  2563,  2932,   -95, 10256, 10256, -1742, -1742,  1339,
    1342,  8762, 10683, 10709, 10735,  9997,   517,   -95,  3023, 12944,
    5091, 12965, 12986, 13007, 13028, 13049, 13070, 13091, 10256,  1557,
   -1742, 10256, 13112, -1742, 12017, 12040, -1742,   751,   765,   777,
   -1742, -1742, 12063, 12086, 10761, 13133, 12109,   158, -1742, -1742,
    9192, -1742,  9192,  3657,  1347,  9192,  1348,   377, 10787, 10813,
     446, 10839,  1346,  5670,  1353,  1354,  1356, -1742,  9192, -1742,
    9192, -1742,  9192, -1742,  9192,   818, -1742, -1742,  3823,  9192,
    1137, -1742, 13154, 12132,  9192, -1742,  1566,  1567,  1569,  1360,
   10256,  3084, 10256, 10256, -1742, -1742,    61,   837, -1742, -1742,
    3187, -1742,  1570,  9972,  1357,  1359,  6515,  1580,  1546,  1547,
    6515,   286,  1548,  1549,  6515,   286,  5734,   838, -1742, -1742,
   12155,   372,   124, -1742, -1742, -1742, -1742, -1742, -1742, -1742,
   -1742, -1742, -1742, -1742, -1742, 10256, -1742, -1742, -1742, -1742,
   -1742, -1742, -1742, 10256, 10256, 10256, -1742,  9192, -1742, -1742,
   -1742, -1742,  4930, -1742, -1742, 10256, -1742,  6515,  4930,  4930,
    4930, -1742, -1742, -1742, -1742, -1742, -1742, -1742, -1742, 10256,
    4930, -1742,  4930, -1742, 10256, -1742, -1742, -1742, -1742,  -145,
    -145,  1581, -1742, 10256,  1588,  -145,  -145,  1589,   153, 10256,
    1590,  1593,   947, -1742,  1594,  1381,    27,  1597, -1742,  9192,
    9192,  9192,  9192, -1742,   446, 10256, -1742,  1385,  1387,  1374,
   -1742,  1604, -1742, -1742, -1742, -1742, -1742,   654,   656, 13175,
   12178, -1742, -1742,  1405,  4930,   245, 13196, 12201, -1742,   299,
   10865, -1742, -1742, -1742,    59, -1742, -1742, 11879,   446,   -95,
    3657, -1742,   834,  6515,  6515,  1605,  6515,   976,  6515,  6515,
    1607,  1523,  6515,  6515,  6515,  6515,  1014,  1609,  1611,  9192,
   -1742,  6515,  1612,  1613,  2591, -1742, -1742,  1616, -1742,  1618,
     384, 10256,   384, 10256,   384, 10256,   384, 10256,  1625,  1627,
    1633,  1636,  1638,   846,  1620,  3309, -1742, -1742,   139, 10891,
   10917, -1742, -1742,  5943,  -117,   -95,   -95,   -95,  1640, 10044,
    1421,  1642,  1427,    53,    54,    57,    74,   -50, -1742,   148,
   -1742,   517,  1644,  1647,  1648,  1649,  1654,  1661,  1662,  1663,
    1670, 13343, -1742,  1089,  1434,  1672,  1673,  1674,  1600,  1684,
    1686,  1687, 10256,   158,   658,   847,   850, -1742,   851, -1742,
   -1742, 10256, 10256, -1742, 10256, 10256, -1742, 10256, 10256, 10256,
     857,   872,   889,   890, -1742, 10256,   894,   158,   158,   895,
    6515,  6515,  6515,  1695, 10943, -1742,  3947,   469,  1704,  1705,
    1488, -1742,  1486, -1742,  1181,  1489,  6515,  1493, -1742,  -145,
    -145,  1708, 10256,  1710,  -145,  -145,  1715, 10256,  1717, -1742,
     446,  1718, -1742,  1723, -1742,  1722, 11879, 11879, 11879, 11879,
     766,  1504,  9925,  1511,   446,   446,  1508,   783,   831, 13217,
    1516,   446, 11879,  1637,  4930, -1742,  1252, -1742,  1637,  4930,
   -1742,   329,  1512,  1727,  1305, -1742, -1742, -1742,    27, 10256,
   -1742,   898, -1742,   902,   908,   909,   912,   384, 13343,  1522,
   10256, 10256,  6515,  1526, -1742, -1742, -1742, -1742,  1536, -1742,
    1731,    18, -1742, -1742,  1734, 10256,  5788,  1533,  1527,  1736,
    1737,     4,  1528,  1535,  1658,  1658,  6515,  1738,  1544,  1545,
    1749,  1766,  6515,  1552,  1767,  1768,  1769,  1773, -1742,  1775,
    6515,   913,  1776,  6515,  6515,  1777,  1779, -1742,  6515,  6515,
   13343,  6515, 13343,  6515, 13343,  6515, 13343,  6515,  6515,  6515,
    1560,  1562,  1782,   560, -1742, 10256, 10256, 10256,  1571,  1576,
    -125,  -104,   -69,  1574, -1742,  1872,  6515, -1742, 10256, -1742,
    1790, -1742,  1797, -1742,  1798, -1742,  1799, -1742, -1742,  8762,
     640,  6006, -1742,  1582,  1583,  1585,  1586,  1595,  1596,  8259,
   -1742,  9192, -1742, -1742, -1742,  1598, 10256, -1742, -1742, 12224,
    1803,   446,  1563,  1592, 10969, 10995, 11021, 11047, 11073, 11099,
   11125, -1742, -1742, -1742, -1742, 13343, -1742,   446,  1809,  1810,
    1660, -1742, 10256, 10256, 10256, -1742,  1817,   584,  5447, -1742,
   -1742, -1742,  1601,  1819,  1637,  4930, -1742,  1892, -1742,  1637,
    4930, -1742,  1911, -1742,   384, -1742,   674, -1742, -1742, -1742,
   -1742, -1742, -1742,  4930, 10256, -1742, -1742, -1742, -1742,  4930,
    1823, -1742, -1742,    25, -1742, -1742, -1742, -1742, -1742, -1742,
    1824,   272,   272, -1742,  1827,   272,   272,  5447, 10256,  1828,
    1831,    33, -1742,  1830, 12247,    27, -1742,  1832,  1833,  1834,
    1835,  6515, 10256, 11151, 11177,   916, -1742, 10256,  1838, -1742,
   -1742,  4930, -1742, 11203,  5134, 13343, -1742,  1821,  1839, -1742,
   -1742, -1742, 10256, 10256,   -95,  1841,  1843,  1844, -1742, 10256,
   10256, -1742, -1742,  1845, 10256, -1742, -1742, -1742, -1742,  1847,
    1848,  1629, -1742,  1850,  1689, 10256, -1742,  1852,  1856,  1858,
    1860,  1862,  1864,  1157,  1867,  9192,  9192, 10256, -1742,  8980,
    6181, 13238,  2248,   632,   632,   -95,  1868,   -95,  1869,   -95,
    1873, 10256, -1742,   305,  1656, 13259, -1742, -1742, -1742, -1742,
    6254,   152, -1742,  1876,  1877,  6515,   -95,   -95,   -95,   -95,
     -95,  4517,  1883,   937, 10256,  1941,  1888,   158, -1742, -1742,
   -1742, 10256, 10256, 10256, 10256, 10256, 10256, 10256, -1742, -1742,
   -1742,  6515,  3543,   401, 13280, -1742, -1742,  6224,  1675,  5816,
    5816,  6515, -1742,  1893,   272,   272, -1742,  1900,   272,   272,
   -1742,  6515, -1742,  1688, 11879,   446,  5352,  6297,  5447, -1742,
    1904,  1905, -1742,  1906,  1907,  1908,  2022, -1742,  1909,  1912,
   -1742,  1614, -1742, -1742, -1742, -1742, -1742,  1918,   396, 13343,
   10256, 10256,  6515,  1702,   941, 13343, -1742,  1923, 10256, -1742,
   -1742,  1706,  1707,  6452,  6670,   554, -1742, -1742, -1742,  6888,
    7106, -1742,  7324,  1925, -1742,  6515, -1742,  1846,  1929, 13343,
   -1742, -1742, -1742, -1742, -1742, -1742,  1712, -1742, -1742,   942,
     945,  9883,  2397,  1930,  1713, -1742, 10256, -1742,  1714,  1716,
     159, -1742,  1719,   222, -1742,  1720,   233, -1742,  1724, 12270,
    1936,  6515,  1924,  1725, 10256, -1742, -1742,   949,   239,   250,
     312,   367,   414,  8477,   417, -1742,  1938,  7542, -1742, -1742,
   11879, 11879, 11229, 11255, 11281, 11307, 11333,  1789, 10256, -1742,
   10256, -1742, -1742,  9192,  2619,  1943,  5447,  1728,  1739,  1744,
   -1742,  1946,  1948, -1742,  1958,  1959,  1968, -1742, -1742, -1742,
    4742, -1742, -1742,  4930, 13343, -1742, -1742, -1742, -1742, -1742,
   -1742, -1742, -1742,    27, -1742,  1813, -1742, -1742, 10256, 11359,
   11385, -1742,  6515, 10256,  1972, -1742, 11411, -1742, -1742,  6515,
    6515,  1973,  1975,  1976,  1978,  1979,  1980,   952,  1761, -1742,
    6515,   810,   835,  9192, -1742, -1742,   632,  4693, -1742, -1742,
    8762,   517,  8762,   517,  8762,   517,  1982, -1742,   955,  6515,
   -1742,  7760,  1983,  9192,   -95,   -95,   -95,   -95,   -95, -1742,
   -1742, -1742, -1742, 10256, 10256, 10256, 10256, 10256, 10256,  7978,
    8196,   964, -1742, -1742,  1770,  1765, -1742,  1990, -1742, -1742,
   -1742, -1742, -1742,   968,  2204,  2001,   978,  2003, -1742,  1784,
   13343, 10256, 10256,   979, 13343, -1742, 10256,  1003,  1004, -1742,
   -1742, -1742, -1742, -1742, -1742, -1742, -1742,  1785, 10256,  1008,
    1787,   -95,  6515,  2009,  1791,   -95,  2010,  1009,  1796, 10256,
   -1742,  8414,   421,   901,  8534,   424,  1490,  8601,   475,  1518,
   -1742,  6515,  2012,  1916,  3510,  1801, -1742,  1012,   500,   512,
     520,   523,   547, 11437, 11463, 11489, 11515, 11541,  2720, -1742,
   -1742,  2027,  2028, -1742, -1742, 10256, -1742,  5447,    24, -1742,
   -1742, 10256, 13301, 11567,    50, 11593, -1742, -1742, -1742, -1742,
   10256,  8643,  2029,   -95,    77, -1742, -1742,   -95,    81, -1742,
    2030, -1742,  8862,  2031, 10256,  2034,  2035, 10256,  2037,  2038,
   10256,  2039,  1820, -1742, 10256, -1742,   517, -1742,  2042,  9192,
    9192,  9192,  9192,  8477, 10256, 10256, 10256, 10256, 10256, -1742,
   -1742, -1742,  5816,  3008, -1742,  1836,  1018, -1742, 10256, -1742,
    6515, 10256,  1019,  1022, 11619, -1742, -1742,   549, -1742,   552,
   -1742, -1742, -1742, -1742,  1825,  8890, -1742, -1742,  1837,  8918,
   -1742, -1742,  1861,  9129, -1742,  2044,  2850,  1617,  3617, -1742,
    1032,  1035,  1036,  1039,   582,  1042, 11645, 11671, 11697, 11723,
   11749,  1826,  5447,  1840,  2048,  1865, 13322,  1053,  9243, -1742,
   -1742, 10256,   -95,   -95,   517,  2050,   517,  2052,   517,  2053,
   -1742, -1742, -1742, -1742,   517,  2055,  2056,  2058,  2059,  9192,
    2061, 10256, 10256, 10256, 10256, 10256,  2080, -1742, -1742, -1742,
    4930, -1742,  1880,  2082,  9310,   618,   653,  1653, -1742,  1882,
    1745, -1742,  1899,  1756, -1742,  1901,  1822, -1742, -1742, -1742,
   -1742,  1057, -1742, 11879, 11775, 11801, 11827, 11853, -1742,  1060,
   -1742,  1902,  6515, -1742,  2120, 10256, 10256,  2124,   517,  2125,
     517,  2126,   517, -1742,  2127, -1742, 10256, 10256, 10256, 10256,
    4930,  2128,  4930,  1083, -1742,  9352,  9429, -1742,  2040, -1742,
    2160, -1742,  2497, -1742,  9527,  9594,  9636,  9713, -1742, -1742,
    1088, -1742,  2129,  2130,  2150,  2151,  2152,  2154, -1742, -1742,
   -1742, -1742,  4930,  2161, -1742, -1742, -1742, -1742, -1742, -1742,
   -1742, -1742
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1742, -1742, -1742, -1742,   875, -1742, -1742, -1742, -1742,   248,
   -1742, -1742, -1742, -1742, -1742, -1742, -1742, -1742, -1742, -1742,
   -1742, -1742,  -376,    12,  4061,  3426, -1742,  1676, -1742, -1742,
   -1742, -1742, -1742, -1742, -1742, -1741, -1742,   390, -1742, -1742,
   -1742, -1742, -1742, -1742,   868,  2169,    17,  -544,  -246, -1742,
   -1742, -1742, -1742, -1742, -1742, -1742, -1742,  2172, -1742, -1742,
   -1742, -1742, -1742, -1742, -1742, -1742, -1742, -1742, -1742, -1742,
   -1742, -1150, -1139,  2173, -1593,  2174, -1742, -1742, -1742,  1645,
   -1742,   397, -1742, -1742, -1742, -1742,  1967, -1742, -1742,   105,
   -1742, -1556,  2477,  1186,   953,  2459,  -267,   719, -1742,   132,
      10, -1742,  -412,    -3,   276
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -551
static const yytype_int16 yytable[] =
{
     123,  1370,   694,   208,   696,   546,  1737,  1738,  1368,  1707,
    1501,   388,   849,   850,     4,  1062,   207,  1046,   349,   711,
     106,   608,     5,   233,  1490,   229,   610,   581,   356,  1617,
     301,   345,   230,   612,   634,   238,  1857,  1035,   238,   202,
     605,   565,   289,   233,   268,   362,   364,   269,   211,   907,
     909,   911,   913,   554,   555,   214,  1979,   584,   212,  1359,
    1361,   372,   272,  1363,   304,  1138,  1296,   306,  1208,   307,
     556,   726,   339,   730,   225,   733,   226,   304,   273,   274,
    1365,  1139,   210,  1988,   554,   555,   213,  1990,   304,  1140,
    1141,  1142,   554,   555,   768,  1143,  1144,  1145,  1146,   769,
    1545,   357,  1546,   361,   777,   554,   555,   778,   724,  1787,
    1349,   554,   555,   370,   276,   277,   599,   646,   600,   648,
     371,  1547,   290,  1548,   278,   656,   291,   844,   484,   127,
     568,   279,   292,   293,   294,   295,   387,   569,   206,   311,
     554,   555,   312,  1022,   554,   555,   296,   308,   473,   474,
     475,   780,   216,   451,   778,   476,  1549,  1261,  1550,   280,
     282,   557,   288,   217,  1047,  1048,  1049,  1050,   154,   155,
     156,   157,   158,   159,   160,   161,   162,  1367,   554,   555,
     609,   167,   168,   169,   170,   611,   229,  1982,  1983,   172,
     173,   174,   613,  1039,   175,   567,   218,   304,   302,   606,
     241,  1618,  1360,  1362,   728,   180,  1364,  1042,   948,   487,
     487,   220,   952,   554,   555,  1063,  1853,   487,   456,   100,
     223,   100,   100,  1366,  1063,   304,   389,   339,   390,   219,
     391,  1368,   339,   350,  1869,   202,   339,   495,   234,   231,
    1051,   487,   339,   221,   582,   235,   339,   339,   339,   339,
     487,   202,   303,   346,   339,   339,   339,   239,   234,  1036,
    1041,   607,   339,   339,   339,  1040,   363,   365,   339,   304,
     908,   910,   912,   914,   373,   215,  1980,   379,  1297,   124,
    1298,   374,   209,   950,  1209,   954,   554,   555,   224,   732,
     554,   555,   232,  1022,   339,   339,   339,   380,   381,   382,
     725,   842,   843,   222,   183,   184,   185,   772,   339,   339,
     452,   453,   773,   624,  1262,  1263,   192,   236,   193,   100,
     284,   858,   888,   285,   889,   339,   286,   339,   890,   237,
     554,   555,   380,   381,   382,   383,  1467,   775,   554,   555,
     384,   385,   776,   305,   485,   489,   851,  1233,   554,   555,
    -545,  1023,   384,   385,   857,  1029,   348,   554,   555,  1028,
     240,   554,   555,   375,  1345,   376,   487,   358,   554,   555,
     339,   339,   377,  1369,   384,   385,   515,  1704,   245,  2021,
     549,   550,  1004,   339,  1800,   523,   241,   776,   558,   665,
     931,  1022,   566,   380,   381,   382,   729,   380,   381,   382,
     949,   380,   381,   382,   953,   940,   297,   242,   298,  1730,
     243,   487,   487,   487,   487,   487,   487,   487,   487,   487,
     487,   339,   487,   487,  2027,   487,   487,   487,   487,   487,
     244,   554,   555,   487,   487,   487,   487,   487,   304,   786,
     304,   787,   554,   555,   714,   276,   277,  1802,   554,   555,
     250,   246,   722,   251,   247,   278,   252,   339,  1804,   554,
     555,   248,   287,   734,  1813,  1291,   380,   381,   382,   383,
     786,   786,   786,   792,   796,  1814,   454,  1414,   380,   381,
     382,   383,   380,   381,   382,   383,   384,   385,   488,   488,
     384,   385,   888,   249,   889,   339,   488,   776,   384,   385,
    -544,   654,   384,   385,   496,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   471,   472,   625,   474,   475,  1294,
     488,   554,   555,   476,   786,   380,   381,   382,   383,   488,
     384,   385,  1700,   786,   253,   805,  2113,  1815,   339,   339,
    -549,   820,   823,   826,   829,   384,   385,   695,   348,   697,
     698,   699,   700,   701,   702,   703,   254,   705,   706,   260,
     708,   709,   710,   786,   712,   917,  1538,  1539,   716,   717,
     718,   719,   720,   456,   456,  1222,   554,   555,   255,  1227,
     380,   381,   382,   383,   339,   339,   339,   256,   384,   385,
    1596,  1597,  1816,   384,   385,  1125,   339,   339,  -547,  1180,
     487,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,   472,   473,   474,   475,   339,  1767,   270,   461,   476,
     271,  1768,   339,   554,   555,   275,   554,   555,  1731,   283,
     554,   555,  1138,   554,   555,   479,   455,   480,   627,  1817,
     628,   339,  1818,   299,   377,   488,  1944,   377,  1139,  1947,
     946,  1883,   947,  1886,   764,  1889,  1140,  1141,  1142,   847,
     848,   339,  1143,  1144,  1145,  1146,   888,   550,   889,   462,
     463,   464,   465,   466,   467,   468,   469,   470,   471,   472,
     473,   474,   475,   963,   554,   555,   786,   476,  1044,  1415,
     488,   488,   488,   488,   488,   488,   488,   488,   488,   488,
    1950,   488,   488,   300,   488,   488,   488,   488,   488,   554,
     555,   309,   488,   488,   488,   488,   488,   721,   888,   723,
     889,   554,   555,   339,   924,  1959,   888,   339,   889,   554,
     555,   987,   554,   555,  1329,   900,  1331,  1960,  1333,  1024,
    1335,   310,  1031,  1030,  1368,  1961,   342,  1368,  1962,   313,
    1368,    53,    54,    55,    56,  1138,   554,   555,   554,   555,
     314,   554,   555,   554,   555,    66,   339,   315,    69,  1270,
     339,  1139,  1963,   487,  2032,   341,   304,  2033,   487,  1140,
    1141,  1142,   339,   339,   343,  1143,  1144,  1145,  1146,   344,
     351,   554,   555,  1078,   464,   465,   466,   467,   468,   469,
     470,   471,   472,   473,   474,   475,  2007,  2049,   352,   353,
     476,   339,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,   472,   473,   474,   475,   261,   554,   555,   262,
     476,   786,   263,  1121,   264,   339,   471,   472,   473,   474,
     475,  1461,  1462,  2095,   355,   476,  1465,  1466,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,   472,   473,
     474,   475,   554,   555,   354,   359,   476,  1562,  1368,   417,
     384,   385,   384,   385,   384,   385,   897,   435,  2096,   488,
    -548,  1390,  -546,   369,  2067,  1468,  2070,   339,  2073,   339,
     384,   385,   339,   257,  2076,   652,   258,   653,   259,   963,
    -550,  1481,   418,   419,   377,   339,  1008,   339,  1072,   339,
     595,   339,   596,  1076,   597,   424,   339,   201,   649,   202,
     650,   339,   597,   770,  1302,   771,  1303,   202,  1368,  1870,
    1871,  1368,   377,   431,  1368,  1872,   765,  1368,   766,   265,
     767,   436,   266,   339,   267,   202,   437,   339,  2118,  1128,
    2120,   339,  2122,  1267,  1874,  1875,  1134,   438,   614,   487,
    1872,   615,  1149,  1223,   616,   441,   617,  1228,   442,   786,
     888,  1122,   889,  1232,  1234,  1012,   786,   478,  1167,  1368,
     888,  1368,   889,  1368,   339,  1014,   888,   459,   889,   487,
     786,   786,  1168,   443,   339,   487,   487,   487,   482,  1688,
    1689,  1473,   786,   888,  1169,   889,   460,   487,  1450,   487,
     477,   504,  1604,  1605,   509,   517,  1138,  1608,  1609,   518,
    1318,   467,   468,   469,   470,   471,   472,   473,   474,   475,
     525,   526,  1139,   304,   476,   541,   339,   339,   339,   339,
    1140,  1141,  1142,   786,   530,  1194,  1143,  1144,  1145,  1146,
     544,   888,   488,   889,   547,  1074,  1453,   488,  1611,   531,
     532,   487,   786,   786,  1210,  1230,  1308,   533,  1309,  1285,
    1286,   786,   786,  1342,  1391,   786,   786,  1392,  1393,   534,
     339,   339,   786,   339,  1401,   339,   339,   548,   559,   339,
     339,   339,   339,   560,  1235,  1380,   339,   786,   339,  1402,
     462,   463,   464,   465,   466,   467,   468,   469,   470,   471,
     472,   473,   474,   475,   786,   786,  1403,  1404,   476,   786,
     786,  1406,  1407,  1475,  1241,  1476,   570,   786,  1945,  1477,
    1244,  1245,  1246,   786,   786,  1478,  1479,   786,   786,  1480,
    1521,  1642,  1250,  1643,  1251,   561,   571,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,   474,
     475,  1676,   786,  1677,  1716,   476,  1773,   786,  1774,  1791,
     786,   583,  1792,  1599,  1642,  1600,  1812,  1642,   572,  1867,
    1891,   573,  1892,   500,  1301,  1232,  1234,  1420,   500,   786,
     585,  1911,   500,  1915,   574,  1916,  1290,   339,   339,   339,
     575,   576,   500,   776,  1642,  1919,  1924,   580,  1632,  1285,
    1286,   377,   586,   339,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   471,   472,   473,   474,   475,  1450,  1453,
    1926,  1927,   476,  1642,   786,  1932,  1940,   786,   488,  1958,
    1350,  1351,  1352,  1773,  1450,  2024,  2029,  1450,   626,  2030,
     487,   487,  1878,   587,   588,   487,   487,   786,  1463,  2045,
     786,   786,  2046,  2047,   786,   304,  2048,   786,   488,  2050,
       7,     8,   630,  1469,   488,   488,   488,   589,  1642,   339,
    2062,   620,   786,   500,  2104,  2110,   488,  2111,   488,   462,
     463,   464,   465,   466,   467,   468,   469,   470,   471,   472,
     473,   474,   475,   339,   371,   592,  1496,   476,  1642,   339,
    2132,  1472,   348,  2142,   593,  2143,   594,   339,   636,   637,
     339,   339,   202,   642,   643,   339,   339,   644,   339,   645,
     339,   647,   339,   663,   339,   339,   339,   664,   667,   668,
     488,  1846,   739,    24,    25,   740,    27,    28,   741,    30,
     742,    32,    33,   339,   671,   476,   735,    35,   736,    36,
     201,   782,   738,   783,    41,    42,    43,    44,   339,    46,
      47,    48,   801,   802,   806,    51,   339,   807,   339,   808,
     809,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,   472,   473,   474,   475,   813,   814,   831,   833,   476,
     835,   840,   465,   466,   467,   468,   469,   470,   471,   472,
     473,   474,   475,   500,    77,    78,    79,   476,   839,   841,
     868,   487,   487,   870,   887,   871,   487,   487,  1598,   873,
     880,   881,   902,   929,   904,   932,   520,   521,   522,   905,
     487,   906,   941,   527,   528,   529,   487,   945,  1612,   958,
     959,   620,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,   472,   473,   474,   475,   990,   991,   992,   995,
     476,  1018,   304,   997,  1561,   998,   999,  1625,   339,  1009,
    1010,  1011,  1016,   577,   578,   876,  1019,  1017,   487,  1020,
    1025,   339,  1026,  1033,   500,   500,  1847,   590,   591,  1034,
    1061,  1079,  1082,  1068,  1650,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   471,   472,   473,   474,   475,  1071,
    1073,  1075,  1087,   476,  1083,  1091,  1084,  1086,  1088,   488,
     488,  1089,   339,   339,   488,   488,  1092,  1093,  1094,  1095,
     500,   500,   500,  1100,   348,  1099,  1101,  1106,  1108,  1683,
    1110,  1111,   894,   896,  1112,  1114,  1113,  1116,  1115,  1124,
     456,   456,   339,  1162,  1894,  1117,  1131,  1177,   339,  1132,
    1179,   500,  1185,  1200,  1201,  1613,  1202,  1212,   921,  1187,
    1188,  1615,  1189,  1203,  1215,  1216,  1218,  1255,   339,  1612,
    1219,  1220,  1224,  1225,  1257,  1260,  1265,   500,   339,  1266,
    1282,  1268,  1269,  1272,  1280,  1138,  1281,  1735,   339,  1655,
    1284,  1289,  1306,   339,  1312,  1313,  1319,   500,  1320,  1323,
    1324,  1139,  1327,  1647,  1343,  1328,  1752,  1755,  1756,  1140,
    1141,  1142,  1337,  1138,  1338,  1143,  1144,  1145,  1146,   339,
    1339,   484,   127,  1340,  1353,  1341,  1358,  1356,  1357,  1139,
    1690,  1371,  1693,  1372,  1696,  1373,  1374,  1140,  1141,  1142,
    1381,  1375,   339,  1143,  1144,  1145,  1146,  1972,  1376,  1377,
    1378,  1708,  1709,  1710,  1711,  1712,  1714,  1379,  1382,  1383,
    1384,   154,   155,   156,   157,   158,   159,   160,   161,   162,
    1385,  1386,  1387,  1388,   167,   168,   169,   170,   339,  1411,
     488,   488,   172,   173,   174,   488,   488,   175,  1416,  1417,
     339,  2008,  1419,  1418,  1426,  1421,  1428,  1948,   180,   488,
    1423,  1431,   500,  1433,  1435,   488,   500,  1436,  1437,  1443,
     339,  1446,  1138,  1449,  1471,  1470,  1457,  1489,   921,  1081,
    1492,  1482,  1499,  1500,  1508,  1951,  1834,   339,  1139,  1498,
     487,   348,  1487,  1497,  1502,  1511,  1140,  1141,  1142,  1488,
     304,  1503,  1143,  1144,  1145,  1146,  1504,   488,  1138,   339,
    1509,  1510,  1512,  1515,  1516,  1517,   339,   339,  1514,  1518,
    1519,  1525,  1522,  1579,  1139,  1526,  1535,   339,  1536,  1537,
     339,   500,  1140,  1141,  1142,  1551,  1556,  1543,  1143,  1144,
    1145,  1146,  1544,  1557,  1558,  1559,   339,  1577,  1565,  1566,
     339,  1567,  1568,   456,  1580,  1589,  1590,   183,   184,   185,
    1591,  1569,  1570,  1595,  1574,  1602,  1601,  1616,  1651,   192,
    1619,   193,   100,  1622,  1627,  1628,  1630,  1765,  1633,  1634,
    1635,  1636,  1646,   500,  2042,   500,  1652,  1656,   500,  1657,
    1658,  1661,  1663,  1667,  1664,  1665,  1666,   888,  1670,   889,
    1138,   500,  1671,   500,  1672,   500,  1673,   500,  1674,   339,
    1675,  1138,   500,  1678,  1691,  1694,  1139,   500,  1552,  1697,
    2097,  1701,  1705,  1706,  1140,  1141,  1142,  1139,   339,  1715,
    1143,  1144,  1145,  1146,  1719,  1140,  1141,  1142,  1606,  1740,
    1736,  1143,  1144,  1145,  1146,  1882,  1743,  1885,  1747,  1888,
    1757,  1758,  1759,  1760,  1761,   304,  1763,  1610,  1764,  1898,
    1899,  1900,  1901,  1902,  1766,     7,     8,  1974,  1772,  1775,
    1786,  1809,  1779,  1780,  1788,  1789,  1795,  1138,  1790,  1796,
     500,  1798,  1807,  1799,  1819,  1801,  1803,  1718,  1828,  1833,
    1805,  1810,  1838,  1139,  1839,  1835,   339,   339,   339,   339,
     339,  1140,  1141,  1142,  1840,  1841,  1836,  1143,  1144,  1145,
    1146,  1837,  2099,   204,  1842,  1848,  1934,   339,  1855,  1861,
    1938,  1862,  1863,  2101,  1864,  1865,  1866,  1868,  1890,  1896,
    1912,  1913,   500,   500,   500,   500,  1914,   739,    24,    25,
     740,    27,    28,   741,    30,   742,    32,    33,  1918,  1920,
    1921,  1930,    35,  1933,    36,  1936,  1939,  1937,  1953,    41,
      42,    43,    44,  1941,    46,    47,    48,  1957,  1762,   488,
      51,  1954,  2057,  1970,  1971,  1986,  1991,  1993,  1987,   348,
    1996,  1997,  1989,  2000,  2001,  2004,   339,  2005,  2009,  2103,
    2040,  2034,   500,  2056,  2059,  2023,  2068,   487,  2071,  2074,
    2058,  2077,  2078,  2036,  2079,  2080,   367,  2082,  2014,    77,
      78,    79,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,   472,   473,   474,   475,  2088,  2038,  2093,   339,
     476,  2060,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,   472,   473,   474,   475,  2092,   487,  2098,   487,
     476,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,   472,   473,   474,   475,  2100,  2114,  2102,  2112,   476,
    2117,  2119,  2121,  2123,  2129,  2144,  2145,  2065,  2066,   487,
     938,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,   472,   473,   474,   475,  1138,  2146,  2147,  2148,   476,
    2149,   444,   445,   446,   448,   450,  1491,  2151,  1858,  1976,
     781,  1139,   105,  1506,   816,   115,   116,   117,   483,  1140,
    1141,  1142,   490,     7,     8,  1143,  1144,  1145,  1146,  1876,
    1629,     0,  2090,     0,  1975,     0,   497,   499,   502,   503,
       0,   505,   499,   507,   508,     0,   499,   511,   512,   513,
     514,  1917,   624,     0,     0,     0,   499,     0,     0,     0,
       0,   524,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,   472,   473,   474,   475,   543,     0,     0,     0,
     476,     0,  2128,     0,  2131,   552,   553,     0,     0,     0,
       0,     0,     0,     0,   553,   739,    24,    25,   740,    27,
      28,   741,    30,   742,    32,    33,     0,  2135,     0,     0,
      35,     0,    36,     0,  2150,  1138,     0,    41,    42,    43,
      44,     0,    46,    47,    48,     0,     0,     0,    51,     0,
       0,  1139,     0,     0,     0,   619,   621,   499,     0,  1140,
    1141,  1142,     0,     0,     0,  1143,  1144,  1145,  1146,   631,
     632,   633,     0,   635,     0,     0,     0,   638,   639,   640,
       0,     0,   641,     0,     0,     0,     0,    77,    78,    79,
       0,     0,     0,     0,   500,     0,   488,   655,     0,     0,
       0,     0,   660,   662,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   669,   670,     0,   672,
     673,   674,   675,   676,   677,   678,   679,   680,   681,   682,
     683,   684,   685,   686,   687,   688,   689,   690,   691,   692,
     693,     0,     0,     0,     0,     0,   488,  2136,   488,     0,
       0,     0,     0,     0,   707,     0,     0,     0,   939,     0,
     713,     0,   715,  1794,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   471,   472,   785,   474,   475,   488,     0,
       0,     0,   476,     0,     0,     0,   744,   499,     0,   746,
     747,   748,   749,   750,   751,   752,   753,   754,   755,   756,
     757,   758,   759,   760,     0,     0,   762,   763,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,   472,   473,
     474,   475,     0,     0,     0,   619,   476,     0,     0,     0,
       0,   790,     0,  1686,     0,  1687,   795,     0,     0,     0,
       0,     0,     0,     0,   803,   804,     0,     0,   500,   500,
       0,     0,   811,   812,     0,     0,     0,   817,   819,   822,
     825,   828,   830,     0,   832,     0,   834,     0,   499,   499,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   500,     0,   852,   853,   854,   444,
     445,   855,     0,     0,     0,   859,   860,   861,   862,   863,
     864,   865,   866,   867,     0,     0,     0,   872,     0,   874,
     875,     0,     0,     0,   499,   499,   499,     0,     0,   882,
     883,   884,   885,   886,     0,     0,   893,   893,   898,   899,
       0,   901,     0,     0,   903,     7,     8,     0,     0,     0,
       0,     0,     0,     0,     0,   499,     0,     0,     0,     0,
       0,   918,   920,     0,   922,   923,     0,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,   474,
     475,   499,  1138,     0,     0,   476,   885,   886,     0,   922,
     923,     0,     0,     0,     0,  1832,     0,     0,  1139,     0,
     956,   499,     0,     0,     0,   960,  1140,  1141,  1142,     0,
       0,     0,  1143,  1144,  1145,  1146,     0,   739,    24,    25,
     740,    27,    28,   741,    30,   742,    32,    33,     0,     0,
       0,     0,    35,     0,    36,     0,   620,     0,     0,    41,
      42,    43,    44,     0,    46,    47,    48,     0,     0,     0,
      51,     0,     0,     0,     0,     0,   500,     0,     0,   501,
       0,     0,     0,     0,   506,     0,     0,     0,   510,     0,
    1032,     0,     0,  1845,     0,     0,  1325,     0,   519,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    77,
      78,    79,   516,     0,  2137,     0,  1969,     0,     0,     0,
       0,     0,  1059,  1060,     0,     0,   499,  1066,  1067,     0,
     499,  1070,   536,   538,   540,     0,   500,     0,   545,  1077,
       0,     0,   920,  1080,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   500,     0,     0,  1096,
       0,     0,     0,     0,     0,     0,   579,     0,     0,     0,
    1104,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1126,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,   472,   473,   474,   475,   499,     0,     0,     0,   476,
       0,     0,  1129,  1130,     0,     0,     0,     0,  1133,   462,
     463,   464,   465,   466,   467,   468,   469,   470,   471,   472,
     473,   474,   475,     0,     0,  1161,     0,   476,  1163,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     657,   658,     0,     0,     0,     0,  2041,   499,     0,   499,
       0,     0,   499,   666,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   499,     0,   499,     0,   499,
       0,   499,     0,     0,     0,     0,   499,     0,     0,     0,
       0,   499,     0,     0,     0,     0,     0,  1204,     0,  1206,
    1207,   704,     0,     0,     0,     0,     0,     0,     0,     0,
    1214,     0,   500,   500,   500,   500,   500,     0,     0,   745,
     462,   463,   464,   465,   466,   467,   468,   469,   470,   471,
     472,   473,   474,   475,     0,     0,     0,     0,   476,     0,
       0,     0,  1236,     0,     7,     8,     0,     0,     0,     0,
    1237,  1238,  1239,     0,   499,     0,     0,     0,     0,     0,
       0,     0,  1242,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1249,     0,     0,     0,
       0,  1252,     0,     0,     0,     0,     0,     0,     0,     0,
    1256,     0,     0,     0,     0,     0,  1264,     0,     0,     0,
     836,   837,   500,     0,     0,     0,   499,   499,   499,   499,
       0,     0,  1278,     0,     0,  2022,   739,    24,    25,   740,
      27,    28,   741,    30,   742,    32,    33,     0,     0,     0,
       0,    35,     0,    36,     0,     7,     8,     0,    41,    42,
      43,    44,     0,    46,    47,    48,   877,   878,   879,    51,
     462,   463,   464,   465,   466,   467,   468,   469,   470,   471,
     472,   473,   474,   475,     0,     0,   499,     0,   476,     0,
       0,     0,     0,     0,     0,     0,     0,   915,  1330,     0,
    1332,     0,  1334,     0,  1336,     0,     0,     0,    77,    78,
      79,     0,     0,     0,     0,     0,     7,     8,     0,     0,
       0,     0,     0,   937,     0,     0,  1355,   739,    24,    25,
     740,    27,    28,   741,    30,   742,    32,    33,     0,     0,
       0,     0,    35,   957,    36,     0,     0,     0,     0,    41,
      42,    43,    44,     0,    46,    47,    48,     0,     0,  1389,
      51,     0,     0,     0,     0,     0,     0,     0,  1394,  1395,
       0,  1396,  1397,     0,  1398,  1399,  1400,     0,     0,  1127,
       0,     0,  1405,     0,     0,     0,     0,     0,   739,    24,
      25,   740,    27,    28,   741,    30,   742,    32,    33,    77,
      78,    79,     0,    35,     0,    36,     0,     0,     0,  1427,
      41,    42,    43,    44,  1432,    46,    47,    48,     0,     7,
       8,    51,     0,  1021,     0,     0,     0,  1027,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,   472,   473,
     474,   475,     0,     0,     0,     0,   476,     0,  1065,     0,
       0,     0,  1069,     0,     0,     0,  1474,     0,     0,     0,
      77,    78,    79,     0,     0,     0,     0,  1483,  1484,     0,
    1150,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1493,  1495,     0,     0,     0,     0,     0,     0,
       0,   739,    24,    25,   740,    27,    28,   741,    30,   742,
      32,    33,     0,     0,     0,     0,    35,     0,    36,     0,
       0,  1105,     0,    41,    42,    43,    44,  1123,    46,    47,
      48,     0,     0,     0,    51,     0,     0,     0,     0,     0,
       0,  1205,  1540,  1541,  1542,     0,     0,     0,     0,     0,
       0,     7,     8,  1553,     0,  1555,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1560,     0,     0,     0,
       0,     0,     0,    77,    78,    79,     0,     0,   499,  1175,
       0,  1176,     0,  1575,  1178,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1190,     0,  1191,
       0,  1192,     0,  1193,     0,     0,     0,     0,  1196,  1592,
    1593,  1594,     0,  1199,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   739,    24,    25,   740,    27,    28,   741,
      30,   742,    32,    33,     0,     0,     0,     0,    35,     0,
      36,  1614,     0,     0,  1211,    41,    42,    43,    44,     0,
      46,    47,    48,  1217,     0,     0,    51,  1221,     0,     0,
       0,  1226,     0,     0,     0,  1626,     0,     0,     0,   624,
       0,     0,     0,     0,     0,     0,  1240,     0,     0,  1639,
       0,     0,     0,     0,  1645,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    77,    78,    79,     0,  1653,
    1654,     0,     0,     0,  1243,     0,  1659,  1660,     0,     0,
       0,  1662,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1669,     0,     0,     0,     0,     0,  1273,  1274,
    1275,  1276,   499,   499,  1681,     0,  1682,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1699,     0,
       0,     0,     7,     8,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1344,     0,   499,     0,
       0,  1717,     0,     0,     0,     0,     0,     0,  1720,  1721,
    1722,  1723,  1724,  1725,  1726,     0,     0,     0,  1321,     0,
    1304,  1305,     0,  1307,  1734,  1310,  1311,     0,     0,  1314,
    1315,  1316,  1317,     0,     0,     0,     0,     0,  1322,     0,
       0,     0,     0,     0,  1754,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   739,    24,    25,   740,    27,    28,
     741,    30,   742,    32,    33,     0,     0,  1769,  1770,    35,
       0,    36,     0,     0,     0,  1776,    41,    42,    43,    44,
       0,    46,    47,    48,     0,     0,     0,    51,     0,     7,
       8,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,   472,   625,   474,   475,     0,     0,     0,     0,   476,
       0,     0,     0,  1797,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   624,    77,    78,    79,     0,
       0,  1811,     0,     0,     0,     0,     0,  1408,  1409,  1410,
     619,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1422,     0,  1829,     0,  1830,     0,     0,
     499,   739,    24,    25,   740,    27,    28,   741,    30,   742,
      32,    33,     0,     0,     0,     0,    35,  1844,    36,     0,
       0,     0,     0,    41,    42,    43,    44,     0,    46,    47,
      48,     0,     0,     0,    51,  1850,     0,  1955,     0,     0,
    1854,     0,     0,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,   472,   473,   474,   475,     0,     0,  1486,
     499,   476,     0,     0,     0,     0,     0,  1881,  1728,  1884,
    1729,  1887,     0,    77,    78,    79,     0,     0,     0,     0,
     499,   933,     0,  1507,     0,     0,     0,     0,     0,  1513,
    1903,  1904,  1905,  1906,  1907,  1908,     0,  1520,     0,     0,
    1523,  1524,     0,     0,     0,  1527,  1528,  1045,  1529,     0,
    1530,     0,  1531,     0,  1532,  1533,  1534,     0,  1922,  1923,
       0,     0,     0,  1925,     0,     0,     0,     0,     0,     0,
       0,  1195,     0,  1554,     0,  1931,     0,     0,     0,     0,
    1573,     0,     0,     0,  2043,     0,  1942,     0,  1564,     0,
       0,     0,     0,     0,     0,     0,  1572,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   785,   474,
     475,     0,     0,     0,     0,   476,     0,     0,     0,     0,
       0,     0,  1973,     0,     0,     0,     0,     0,  1645,     0,
       0,     0,     0,     0,     0,     0,     0,  1984,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1995,     0,     0,  1999,     0,     0,  2003,     0,     0,
       0,  2006,     0,     0,     0,     0,   499,   499,   499,   499,
     499,  2016,  2017,  2018,  2019,  2020,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2026,     0,     0,  2028,     0,
       0,     0,     0,     0,     0,  1413,     0,     0,  1637,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1649,     0,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,   472,   473,   474,   475,     0,     0,     0,
       0,   476,     0,     0,  1679,  1680,     0,     0,  2064,   462,
     463,   464,   465,   466,   467,   468,   469,   470,   471,   472,
     473,   474,   475,     0,     0,     0,   499,   476,  2083,  2084,
    2085,  2086,  2087,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,   472,   473,   474,   475,     0,     0,     0,
       0,   476,  1486,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   925,     0,     0,     0,     0,
       0,     0,  2115,  2116,     0,     0,     0,     0,  1727,     0,
       0,     0,     0,  2124,  2125,  2126,  2127,     0,  1739,     0,
       0,     0,   227,   228,     0,     0,     0,     0,  1746,     0,
       0,     0,     0,  1751,     0,     0,     0,     0,   964,   965,
     966,   967,   968,   969,   970,   971,   972,   973,   974,     0,
     976,   977,   978,   979,   980,   981,   982,     0,     0,  1771,
     986,   988,   989,     0,     0,     0,   993,   994,     0,   996,
       0,     0,     0,     0,  1001,  1002,  1003,     0,  1005,     0,
       0,     0,  1486,     0,     0,  1013,  1015,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,   474,
     475,     0,     0,  1038,     0,   476,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1808,     0,
       0,     0,     0,     0,   378,     0,     0,     0,     0,     0,
       0,     0,  1831,   392,   393,   394,   395,   396,   397,   398,
     399,   400,   401,   402,   403,   404,   405,   406,   407,   408,
     409,   410,   411,   412,   413,   414,   415,   416,     0,     0,
       0,   420,   421,   422,   423,     0,   425,   426,   427,   428,
     429,   430,     0,     0,   432,     0,     0,     0,     0,     0,
     433,   434,     0,     0,     0,     0,   439,   440,     0,  1486,
       0,     0,  1877,     0,     0,     0,  1859,  1860,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1486,     0,     0,
       0,     0,  1897,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1893,     0,     0,   125,
     126,   127,     0,     0,     0,   128,   129,   130,     0,     0,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,     0,     0,     0,  1183,     0,     0,     0,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,     0,  1935,
       0,   172,   173,   174,     0,     0,   175,     0,   176,   177,
     178,     0,     0,     0,     0,     0,   179,   180,  1952,     0,
       0,     0,     0,     0,     0,     0,     0,   598,     0,     0,
     601,   602,   603,   604,     0,     0,   356,   127,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     629,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2010,  2011,
    2012,  2013,  2015,     0,     0,     0,   154,   155,   156,   157,
     158,   159,   160,   161,   162,     0,     0,     0,     0,   167,
     168,   169,   170,     0,     0,     0,     0,   172,   173,   174,
       0,     0,   175,     0,     0,     0,     0,  1486,   181,     0,
       0,     0,     0,   180,     0,   182,   183,   184,   185,   186,
    1277,     0,     0,   187,   188,   189,   190,   191,   192,     0,
     193,   100,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   194,   195,     0,     0,     0,
     196,     0,     0,  1299,  1300,   197,     0,   198,  2081,   199,
     200,     0,   201,     0,   202,   737,     0,     0,     0,     0,
     125,   316,     0,     0,     0,     0,   128,   129,   130,     0,
       0,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   318,   319,   320,   321,   322,     0,
       0,     0,   183,   184,   185,     0,     0,     0,     0,  1486,
     163,   164,   165,   166,   192,     0,   193,   100,   171,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   176,
     177,   178,     0,     0,     0,     0,     0,   179,     0,     0,
       0,   323,     0,     0,   324,     0,     0,   325,     0,   326,
       0,     0,     0,     0,     0,    34,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   327,
       0,     0,     0,     0,     0,     0,    53,    54,    55,    56,
      57,     0,     0,    59,    60,    61,    62,    63,     0,     0,
      66,     0,     0,    69,     0,     0,  1434,     0,     0,     0,
       0,     0,  1438,  1439,  1440,  1441,  1442,     0,  1445,     0,
    1447,  1448,     0,  1451,  1454,     0,     0,  1458,  1459,  1460,
       0,     0,     0,     0,  1464,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   182,     0,     0,     0,
     186,     0,     0,     0,   187,   188,   189,   190,   191,     0,
       0,     0,   100,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   562,  1713,     0,     0,
       0,   196,     0,     0,     0,     0,   564,     0,     0,     0,
       0,   200,     0,   279,   622,   125,   316,     0,     0,     0,
       0,   128,   129,   130,     0,     0,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   318,
     319,   320,   321,   322,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   163,   164,   165,   166,     0,
       0,     0,     0,   171,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   176,   177,   178,  1578,     0,     0,
       0,     0,   179,     0,     0,     0,   323,     0,     0,   324,
       0,     0,   325,  1588,   326,     0,     0,     0,     0,     0,
      34,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1603,     0,     0,     0,   327,  1607,     0,     0,     0,     0,
       0,    53,    54,    55,    56,    57,     0,     0,    59,    60,
      61,    62,    63,     0,     0,    66,     0,     0,    69,     0,
       0,     0,     0,     0,     0,     0,     0,  1620,  1621,     0,
       0,  1623,  1624,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,   472,   473,   474,   475,     0,     0,     0,
       0,   476,     0,     0,     0,     0,     0,     0,  1879,     0,
    1880,   182,     0,     0,     0,   186,     0,     0,     0,   187,
     188,   189,   190,   191,   484,   127,     0,   100,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   194,   498,     0,     0,     0,   196,     0,     0,     0,
       0,   329,     0,     0,     0,     0,   200,     0,     0,   622,
       0,     0,     0,     0,   154,   155,   156,   157,   158,   159,
     160,   161,   162,     0,     0,     0,     0,   167,   168,   169,
     170,     0,     0,     0,     0,   172,   173,   174,     0,     0,
     175,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   180,     0,     0,     0,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   471,   472,   473,   474,   475,     0,
    1741,  1742,     0,   476,  1744,  1745,     0,     0,     0,     0,
    1748,  1749,  1043,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   360,   127,     0,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   471,   472,   473,   474,   475,     0,
       0,     0,     0,   476,     0,     0,     0,     0,     0,     0,
    1253,  1254,  1098,     0,     0,     0,  1258,  1259,     0,     0,
       0,     0,   154,   155,   156,   157,   158,   159,   160,   161,
     162,     0,     0,     0,     0,   167,   168,   169,   170,     0,
     183,   184,   185,   172,   173,   174,     0,     0,   175,     0,
       0,     0,   192,     0,   193,   100,     0,     0,     0,   180,
       0,     0,     0,     0,     0,     0,     0,   125,   316,   127,
       0,     0,     0,   128,   129,   130,  1821,  1822,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   318,   319,   320,   321,   322,     0,     0,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,     0,     0,     0,   172,
     173,   174,     0,     0,   175,     0,   176,   177,   178,     0,
       0,     0,     0,     0,   179,   180,     0,     0,   323,     0,
       0,   324,     0,     0,   325,     0,   326,     0,   183,   184,
     185,     0,    34,     0,     0,     0,     0,     0,     0,     0,
     192,     0,   193,     0,     0,     0,   327,     0,     0,     0,
       0,     0,     0,    53,    54,    55,    56,    57,     0,     0,
      59,    60,    61,    62,    63,     0,     0,    66,     0,     0,
      69,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1424,  1425,     0,     0,     0,  1429,  1430,     0,     0,     0,
       0,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,   472,   473,   474,   475,     0,     0,     0,     0,   476,
       0,     0,     0,   182,   183,   184,   185,   186,  1153,     0,
       0,   187,   188,   189,   190,   191,   192,     0,   193,   100,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   194,   328,     0,     0,     0,   196,     0,
       0,     0,     0,   329,     0,   125,   316,   127,   200,     0,
     330,   128,   129,   130,     0,     0,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   318,
     319,   320,   321,   322,     0,     0,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,     0,     0,     0,   172,   173,   174,
       0,     0,   175,     0,   176,   177,   178,     0,     0,     0,
       0,     0,   179,   180,     0,     0,   323,     0,     0,   324,
       0,     0,   325,     0,   326,     0,     0,     0,     0,     0,
      34,     0,   127,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   327,     0,     0,     0,     0,     0,
       0,    53,    54,    55,    56,    57,     0,     0,    59,    60,
      61,    62,    63,     0,     0,    66,     0,     0,    69,     0,
       0,   154,   155,   156,   157,   158,   159,   160,   161,   162,
       0,     0,     0,     0,   167,   168,   169,   170,     0,  2105,
       0,     0,   172,   173,   174,     0,     0,   175,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   180,     0,
       0,   182,   183,   184,   185,   186,     0,     0,     0,   187,
     188,   189,   190,   191,   192,     0,   193,   100,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   194,   328,     0,     0,     0,   196,     0,     0,     0,
       0,   329,     0,   125,   316,   317,   200,     0,  1750,   128,
     129,   130,     0,     0,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   318,   319,   320,
     321,   322,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   163,   164,   165,   166,   183,   184,   185,
       0,   171,     0,     0,     0,     0,     0,     7,     8,   192,
       0,   193,   176,   177,   178,     0,     0,     0,     0,     0,
     179,     0,     0,     0,   323,     0,     0,   324,     0,     0,
     325,     0,   326,     0,     0,     0,     0,     0,    34,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   327,     0,     0,     0,     0,     0,     0,    53,
      54,    55,    56,    57,     0,     0,    59,    60,    61,    62,
      63,     0,     0,    66,     0,     0,    69,     0,     0,   739,
      24,    25,   740,    27,    28,   741,    30,   742,    32,    33,
       0,     0,     0,     0,    35,     0,    36,     0,     0,     0,
       0,    41,    42,    43,    44,     0,    46,    47,    48,     0,
       0,     0,    51,     0,     0,     0,     0,     0,     0,   182,
       0,     0,     0,   186,     0,     0,     0,   187,   188,   189,
     190,   191,     0,     0,     0,   100,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   194,
     328,    77,    78,    79,   196,     0,     0,     0,     0,   329,
       0,   125,   366,   127,   200,     0,   330,   128,   129,   130,
       0,     0,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,     0,     0,     0,     7,     8,
       0,     0,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
       0,     0,     0,   172,   173,   174,     0,     0,   175,     0,
     176,   177,   178,     0,     0,     0,     0,     0,   179,   180,
     462,   463,   464,   465,   466,   467,   468,   469,   470,   471,
     472,   473,   474,   475,     0,     0,     0,     0,   476,     0,
       0,     0,     0,     0,     0,     0,     0,  1186,     0,     0,
     739,    24,    25,   740,    27,    28,   741,    30,   742,    32,
      33,     0,     0,     0,     0,    35,     0,    36,     0,     0,
       0,     0,    41,    42,    43,    44,     0,    46,    47,    48,
       0,     0,     0,    51,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   471,   472,   473,   474,   475,     0,     0,
     943,     0,   476,     0,     0,     0,     0,     0,     0,     0,
       0,  1229,     0,     0,     0,     0,     0,   182,   183,   184,
     185,   186,    77,    78,    79,   187,   188,   189,   190,   191,
     192,     0,   193,   100,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   194,   195,     0,
       0,     0,   196,     0,     0,     0,     0,   329,     0,   125,
     316,  1563,   200,     0,  1494,   128,   129,   130,     0,     0,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   318,   319,   320,   321,   322,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   163,
     164,   165,   166,     0,     0,     0,     0,   171,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   176,   177,
     178,     0,     0,     0,     0,     0,   179,     0,     0,     0,
     323,     0,     0,   324,     0,     0,   325,     0,   326,     0,
       0,     0,     0,     0,    34,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   327,     0,
       0,     0,     0,     0,     0,    53,    54,    55,    56,    57,
       0,     0,    59,    60,    61,    62,    63,     0,     0,    66,
       0,     0,    69,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,   472,   473,   474,   475,     0,     0,     0,
       0,   476,     0,     0,     0,     0,     0,     0,     0,     0,
    1348,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   182,     0,     0,     0,   186,
       0,     0,     0,   187,   188,   189,   190,   191,     0,     0,
       0,   100,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   194,   328,     0,     0,     0,
     196,     0,     0,     0,     0,   329,     0,   125,   366,   127,
     200,     0,   330,   128,   129,   130,     0,     0,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,     0,     0,     0,     0,     0,     0,     0,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,     0,     0,     0,   172,
     173,   174,     0,     0,   175,     0,   176,   177,   178,     0,
     125,   366,   127,     0,   179,   180,   128,   129,   130,     0,
       0,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,     0,     0,     0,     0,     0,     0,
       0,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,     0,
       0,     0,   172,   173,   174,     0,     0,   175,     0,   176,
     177,   178,     0,     0,     0,     0,     0,   179,   180,     0,
       0,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,   472,   473,   474,   475,     0,     0,     0,     0,   476,
       0,     0,     0,   182,   183,   184,   185,   186,  1684,     0,
       0,   187,   188,   189,   190,   191,   192,     0,   193,   100,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   194,   195,     0,     0,     0,   196,     0,
       0,     0,     0,   329,     0,     0,     0,     0,   200,     0,
    1733,     0,     0,     0,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   471,   472,   473,   474,   475,     0,     0,
       0,     0,   476,     0,     0,     0,   182,   183,   184,   185,
     186,  1703,     0,     0,   187,   188,   189,   190,   191,   192,
       0,   193,   100,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   194,   195,     0,     0,
       0,   196,     0,     0,     0,     0,   329,     0,   125,   316,
       0,   200,     0,  1753,   128,   129,   130,     0,     0,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   318,   319,   320,   321,   322,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   163,   164,
     165,   166,     0,     0,     0,     0,   171,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   176,   177,   178,
       0,     0,     0,     0,     0,   179,     0,     0,     0,   323,
       0,     0,   324,     0,     0,   325,     0,   326,     0,     0,
       0,     0,     0,    34,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   327,     0,     0,
       0,     0,     0,     0,    53,    54,    55,    56,    57,     0,
       0,    59,    60,    61,    62,    63,     0,     0,    66,     0,
       0,    69,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,   472,   473,   474,   475,     0,     0,     0,     0,
     476,     0,     0,     0,     0,     0,     0,     0,     0,  1781,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   182,     0,     0,     0,   186,     0,
       0,     0,   187,   188,   189,   190,   191,     0,     0,     0,
     100,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   194,   328,     0,     0,     0,   196,
       0,     0,     0,     0,   329,     0,   125,   316,     0,   200,
       0,   330,   128,   129,   130,     0,     0,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     318,   319,   320,   321,   322,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   163,   164,   165,   166,
       0,     0,     0,     0,   171,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   176,   177,   178,     0,     0,
       0,     0,     0,   179,     0,     0,     0,   323,     0,     0,
     324,     0,     0,   325,     0,   326,     0,     0,     0,     0,
       0,    34,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   327,     0,     0,     0,     0,
       0,     0,    53,    54,    55,    56,    57,     0,     0,    59,
      60,    61,    62,    63,     0,     0,    66,     0,     0,    69,
     462,   463,   464,   465,   466,   467,   468,   469,   470,   471,
     472,   473,   474,   475,     0,     0,     0,     0,   476,     0,
       0,     0,     0,     0,     0,     0,     0,  1782,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   182,     0,     0,     0,   186,     0,     0,     0,
     187,   188,   189,   190,   191,     0,     0,     0,   100,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   194,   328,     0,     0,     0,   196,     0,     0,
       0,     0,   535,     0,   125,   316,     0,   200,     0,   330,
     128,   129,   130,     0,     0,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   318,   319,
     320,   321,   322,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   163,   164,   165,   166,     0,     0,
       0,     0,   171,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   176,   177,   178,     0,     0,     0,     0,
       0,   179,     0,     0,     0,   323,     0,     0,   324,     0,
       0,   325,     0,   326,     0,     0,     0,     0,     0,    34,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   327,     0,     0,     0,     0,     0,     0,
      53,    54,    55,    56,    57,     0,     0,    59,    60,    61,
      62,    63,     0,     0,    66,     0,     0,    69,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,   472,   473,
     474,   475,     0,     0,     0,     0,   476,     0,     0,     0,
       0,     0,     0,     0,     0,  1783,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     182,     0,     0,     0,   186,     0,     0,     0,   187,   188,
     189,   190,   191,     0,     0,     0,   100,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     194,   328,     0,     0,     0,   196,     0,     0,     0,     0,
     537,     0,   125,   316,     0,   200,     0,   330,   128,   129,
     130,     0,     0,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   318,   319,   320,   321,
     322,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   163,   164,   165,   166,     0,     0,     0,     0,
     171,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   176,   177,   178,     0,     0,     0,     0,     0,   179,
       0,     0,     0,   323,     0,     0,   324,     0,     0,   325,
       0,   326,     0,     0,     0,     0,     0,    34,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   327,     0,     0,     0,     0,     0,     0,    53,    54,
      55,    56,    57,     0,     0,    59,    60,    61,    62,    63,
       0,     0,    66,     0,     0,    69,   462,   463,   464,   465,
     466,   467,   468,   469,   470,   471,   472,   473,   474,   475,
       0,     0,     0,     0,   476,     0,     0,     0,     0,     0,
       0,     0,     0,  1784,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   182,     0,
       0,     0,   186,     0,     0,     0,   187,   188,   189,   190,
     191,     0,     0,     0,   100,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   194,   328,
       0,     0,     0,   196,     0,     0,     0,     0,   539,     0,
     125,   316,     0,   200,     0,   330,   128,   129,   130,     0,
       0,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   318,   319,   320,   321,   322,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     163,   164,   165,   166,     0,     0,     0,     0,   171,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   176,
     177,   178,     0,     0,     0,     0,     0,   179,     0,     0,
       0,   323,     0,     0,   324,     0,     0,   325,     0,   326,
       0,     0,     0,     0,     0,    34,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   327,
       0,     0,     0,     0,     0,     0,    53,    54,    55,    56,
      57,     0,     0,    59,    60,    61,    62,    63,     0,     0,
      66,     0,     0,    69,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   471,   472,   473,   474,   475,     0,     0,
       0,     0,   476,     0,     0,     0,     0,     0,     0,     0,
       0,  1785,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   182,     0,     0,     0,
     186,     0,     0,     0,   187,   188,   189,   190,   191,     0,
       0,     0,   100,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   194,   498,     0,     0,
       0,   196,     0,     0,     0,     0,   329,     0,   125,   316,
       0,   200,     0,   618,   128,   129,   130,     0,     0,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   318,   319,   320,   321,   322,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   163,   164,
     165,   166,     0,     0,     0,     0,   171,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   176,   177,   178,
       0,     0,     0,     0,     0,   179,     0,     0,     0,   323,
       0,     0,   324,     0,     0,   325,     0,   326,     0,     0,
       0,     0,     0,    34,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   327,     0,     0,
       0,     0,     0,     0,    53,    54,    55,    56,    57,     0,
       0,    59,    60,    61,    62,    63,     0,     0,    66,     0,
       0,    69,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,   472,   473,   474,   475,     0,     0,     0,     0,
     476,     0,     0,     0,     0,     0,     0,     0,     0,  1820,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   182,     0,     0,     0,   186,     0,
       0,     0,   187,   188,   189,   190,   191,     0,     0,     0,
     100,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   194,   498,     0,     0,     0,   196,
       0,     0,     0,     0,   329,     0,   125,   316,     0,   200,
       0,   892,   128,   129,   130,     0,     0,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     318,   319,   320,   321,   322,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   163,   164,   165,   166,
       0,     0,     0,     0,   171,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   176,   177,   178,     0,     0,
       0,     0,     0,   179,     0,     0,     0,   323,     0,     0,
     324,     0,     0,   325,     0,   326,     0,     0,     0,     0,
       0,    34,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   327,     0,     0,     0,     0,
       0,     0,    53,    54,    55,    56,    57,     0,     0,    59,
      60,    61,    62,    63,     0,     0,    66,     0,     0,    69,
     462,   463,   464,   465,   466,   467,   468,   469,   470,   471,
     472,   473,   474,   475,     0,     0,     0,     0,   476,     0,
       0,     0,     0,     0,     0,     0,     0,  1895,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   182,     0,     0,     0,   186,     0,     0,     0,
     187,   188,   189,   190,   191,     0,     0,     0,   100,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   194,   498,     0,     0,     0,   196,     0,     0,
       0,     0,   329,     0,   125,   316,     0,   200,     0,   895,
     128,   129,   130,     0,     0,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   318,   319,
     320,   321,   322,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   163,   164,   165,   166,     0,     0,
       0,     0,   171,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   176,   177,   178,     0,     0,     0,     0,
       0,   179,     0,     0,     0,   323,     0,     0,   324,     0,
       0,   325,     0,   326,     0,     0,     0,     0,     0,    34,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   327,     0,     0,     0,     0,     0,     0,
      53,    54,    55,    56,    57,     0,     0,    59,    60,    61,
      62,    63,     0,     0,    66,     0,     0,    69,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,   472,   473,
     474,   475,     0,     0,     0,     0,   476,     0,     0,     0,
       0,     0,     0,     0,     0,  1909,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     182,     0,     0,     0,   186,     0,     0,     0,   187,   188,
     189,   190,   191,     0,     0,     0,   100,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     194,   498,     0,     0,     0,   196,     0,     0,     0,     0,
     329,     0,   125,   316,     0,   200,     0,   919,   128,   129,
     130,     0,     0,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   318,   319,   320,   321,
     322,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   163,   164,   165,   166,     0,     0,     0,     0,
     171,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   176,   177,   178,     0,     0,     0,     0,     0,   179,
       0,     0,     0,   323,     0,     0,   324,     0,     0,   325,
       0,   326,     0,     0,     0,     0,     0,    34,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   327,     0,     0,     0,     0,     0,     0,    53,    54,
      55,    56,    57,     0,     0,    59,    60,    61,    62,    63,
       0,     0,    66,     0,     0,    69,   462,   463,   464,   465,
     466,   467,   468,   469,   470,   471,   472,   473,   474,   475,
       0,     0,     0,     0,   476,     0,     0,     0,     0,     0,
       0,     0,     0,  1910,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   182,     0,
       0,     0,   186,     0,     0,     0,   187,   188,   189,   190,
     191,     0,     0,     0,   100,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   194,   328,
       0,     0,     0,   196,     0,     0,     0,     0,   329,     0,
     125,   316,     0,   200,     0,  1571,   128,   129,   130,     0,
       0,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   318,   319,   320,   321,   322,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     163,   164,   165,   166,     0,     0,     0,     0,   171,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   176,
     177,   178,     0,     0,     0,     0,     0,   179,     0,     0,
       0,   323,     0,     0,   324,     0,     0,   325,     0,   326,
       0,     0,     0,     0,     0,    34,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   327,
       0,     0,     0,     0,     0,     0,    53,    54,    55,    56,
      57,     0,     0,    59,    60,    61,    62,    63,     0,     0,
      66,     0,     0,    69,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   471,   472,   473,   474,   475,     0,     0,
       0,     0,   476,     0,     0,     0,     0,     0,     0,     0,
       0,  1943,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   182,     0,     0,     0,
     186,     0,     0,     0,   187,   188,   189,   190,   191,     0,
       0,     0,   100,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   562,  1713,     0,     0,
       0,   196,     0,     0,     0,     0,   564,     0,   125,   366,
       0,   200,     0,   279,   128,   129,   130,     0,     0,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,     0,     0,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   471,   472,   473,   474,   475,   163,   164,
     165,   166,   476,     0,     0,     0,   171,     0,     0,     0,
       0,  1946,     0,     0,     0,   125,   366,   176,   177,   178,
       0,   128,   129,   130,     0,   179,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,     0,
       0,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,   472,   473,   474,   475,   163,   164,   165,   166,   476,
       0,     0,     0,   171,     0,     0,     0,     0,  1949,     0,
       0,     0,     0,     0,   176,   177,   178,     0,     0,     0,
       0,     0,   179,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,   472,   473,   474,   475,     0,     0,     0,
       0,   476,     0,     0,     0,     0,     0,     0,     0,     0,
    1985,     0,     0,     0,   182,     0,     0,     0,   186,     0,
       0,     0,   187,   188,   189,   190,   191,     0,     0,     0,
     100,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   194,   195,     0,     0,     0,   196,
       0,     0,     0,     0,   329,     0,     0,     0,     0,   200,
       0,   542,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,   472,   473,   474,   475,     0,     0,     0,     0,
     476,   182,     0,     0,     0,   186,     0,     0,   651,   187,
     188,   189,   190,   191,     0,     0,     0,   100,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   562,   563,     0,     0,     0,   196,     0,     0,     0,
       0,   564,     0,   125,   366,   127,   200,     0,   279,   128,
     129,   130,     0,     0,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,     0,     0,     0,
       0,     0,     0,     0,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,     0,     0,     0,   172,   173,   174,     0,     0,
     175,     0,   176,   177,   178,     0,     0,     0,     0,     0,
     179,   180,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,   472,   473,   474,   475,     0,     0,     0,     0,
     476,     0,     0,     0,     0,     0,     0,     0,     0,  1992,
     462,   463,   464,   465,   466,   467,   468,   469,   470,   471,
     472,   473,   474,   475,     0,     0,     0,     0,   476,     0,
       0,     0,     0,     0,     0,     0,     0,  2035,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,   472,   473,
     474,   475,     0,     0,     0,     0,   476,     0,     0,     0,
       0,     0,     0,     0,     0,  2037,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   182,
     183,   184,   185,   186,     0,     0,     0,   187,   188,   189,
     190,   191,   192,     0,   193,   100,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   194,
     195,     0,     0,     0,   196,   125,   316,     0,     0,   329,
       0,   128,   129,   130,   200,     0,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   318,
     319,   320,   321,   322,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   163,   164,   165,   166,     0,
       0,     0,     0,   171,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   176,   177,   178,     0,     0,     0,
       0,     0,   179,     0,     0,     0,   323,     0,     0,   324,
       0,     0,   325,     0,   326,     0,     0,     0,     0,     0,
      34,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   327,     0,     0,     0,     0,     0,
       0,    53,    54,    55,    56,    57,     0,     0,    59,    60,
      61,    62,    63,     0,     0,    66,     0,     0,    69,   462,
     463,   464,   465,   466,   467,   468,   469,   470,   471,   472,
     473,   474,   475,     0,     0,     0,     0,   476,     0,     0,
       0,     0,     0,     0,     0,     0,  2039,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   182,     0,     0,     0,   186,     0,     0,     0,   187,
     188,   189,   190,   191,     0,     0,     0,   100,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   194,   498,     0,     0,     0,   196,   125,   366,     0,
       0,   329,     0,   128,   129,   130,   200,     0,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,     0,     0,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,   472,   473,   474,   475,   163,   164,   165,
     166,   476,     0,     0,     0,   171,     0,     0,     0,     0,
    2063,     0,     0,     0,   125,   366,   176,   177,   178,     0,
     128,   129,   130,     0,   179,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,     0,     0,
     462,   463,   464,   465,   466,   467,   468,   469,   470,   471,
     472,   473,   474,   475,   163,   164,   165,   166,   476,     0,
       0,     0,   171,     0,     0,     0,     0,  2094,     0,     0,
       0,     0,     0,   176,   177,   178,     0,     0,     0,     0,
       0,   179,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,   472,   473,   474,   475,     0,     0,     0,     0,
     476,     0,     0,     0,     0,     0,     0,     0,     0,  2133,
       0,     0,     0,   182,     0,     0,     0,   186,     0,     0,
       0,   187,   188,   189,   190,   191,     0,     0,     0,   100,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   194,   195,     0,     0,     0,   196,     0,
       0,     0,     0,   329,   447,     0,     0,     0,   200,   462,
     463,   464,   465,   466,   467,   468,   469,   470,   471,   472,
     473,   474,   475,     0,     0,     0,     0,   476,     0,     0,
     182,     0,     0,     0,   186,     0,  2134,     0,   187,   188,
     189,   190,   191,     0,     0,     0,   100,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     194,   195,     0,     0,     0,   196,     0,     0,     0,     0,
     329,   125,   366,   449,     0,   200,     0,   128,   129,   130,
       0,     0,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,     0,     0,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,   474,
     475,   163,   164,   165,   166,   476,     0,     0,     0,   171,
       0,     0,     0,     0,  2138,     0,     0,     0,   125,   366,
     176,   177,   178,     0,   128,   129,   130,     0,   179,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,     0,     0,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   471,   472,   473,   474,   475,   163,   164,
     165,   166,   476,     0,     0,     0,   171,     0,     0,     0,
       0,  2139,     0,     0,     0,     0,     0,   176,   177,   178,
       0,     0,     0,     0,     0,   179,   462,   463,   464,   465,
     466,   467,   468,   469,   470,   471,   472,   473,   474,   475,
       0,     0,     0,     0,   476,     0,     0,     0,     0,     0,
       0,     0,     0,  2140,     0,     0,     0,   182,     0,     0,
       0,   186,     0,     0,     0,   187,   188,   189,   190,   191,
       0,     0,     0,   100,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   194,   195,     0,
       0,     0,   196,     0,     0,     0,     0,   329,   659,     0,
       0,     0,   200,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,   472,   473,   474,   475,     0,     0,     0,
       0,   476,     0,     0,   182,     0,     0,     0,   186,     0,
    2141,     0,   187,   188,   189,   190,   191,     0,     0,     0,
     100,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   194,   195,     0,     0,     0,   196,
       0,     0,     0,     0,   329,   125,   366,   661,  1213,   200,
       0,   128,   129,   130,     0,     0,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,     0,
       0,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,   472,   473,   474,   475,   163,   164,   165,   166,   476,
       0,     0,     0,   171,     0,     0,     0,   838,     0,     0,
       0,     0,     0,     0,   176,   177,   178,   125,   366,     0,
    1354,     0,   179,   128,   129,   130,     0,     0,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,     0,     0,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,   472,   473,   474,   475,   163,   164,   165,
     166,   476,     0,     0,     0,   171,     0,     0,     0,  1793,
       0,     0,     0,     0,     0,     0,   176,   177,   178,     0,
       0,     0,     0,     0,   179,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   471,   472,   473,   474,   475,     0,
       0,     0,     0,   476,     0,   888,     0,   889,     0,     0,
    1444,   182,     0,     0,     0,   186,     0,     0,     0,   187,
     188,   189,   190,   191,     0,     0,     0,   100,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   194,   195,     0,     0,     0,   196,     0,     0,     0,
       0,   329,     0,     0,     0,     0,   200,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,   474,
     475,     0,     0,     0,     0,   476,     0,   916,     0,     0,
       0,     0,   845,   182,     0,     0,     0,   186,     0,     0,
       0,   187,   188,   189,   190,   191,     0,     0,     0,   100,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   194,   195,     0,     0,     0,   196,   125,
     366,     0,     0,   329,     0,   128,   129,   130,   200,     0,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,     0,     0,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   471,   472,   473,   474,   475,   163,
     164,   165,   166,   476,     0,     0,     0,   171,     0,     0,
     774,     0,     0,     0,     0,     0,     0,     0,   176,   177,
     178,     0,     0,     0,     0,     0,   179,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,   474,
     475,     0,     0,     0,     0,   476,     0,     0,     0,     0,
       0,     0,   845,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,   472,   473,   474,   475,     0,     0,     0,
       0,   476,     0,     0,     0,     0,     0,     0,   846,     0,
     462,   463,   464,   465,   466,   467,   468,   469,   470,   471,
     472,   473,   474,   475,     0,     0,     0,     0,   476,     0,
      -4,     1,     0,     0,    -4,   930,     0,     0,     0,     0,
       0,     0,    -4,    -4,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   182,     0,     0,     0,   186,
       0,     0,     0,   187,   188,   189,   190,   191,     0,     0,
       0,   100,    -4,    -4,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   194,   195,     0,     0,     0,
     196,     0,    -4,    -4,    -4,   329,     0,     0,    -4,    -4,
     200,    -4,     0,     0,     0,    -4,    -4,     0,    -4,    -4,
       0,     0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,     0,     0,     0,    -4,    -4,
       0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,     0,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,     0,    -4,    -4,    -4,    -4,
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
      32,    33,     0,     0,     0,    34,    35,     0,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,     0,    50,    51,    52,    53,    54,    55,    56,
      57,    58,     0,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,     0,     0,     0,    72,
      73,    74,     0,     0,     0,     0,     0,    75,     0,     0,
       0,     0,    76,    77,    78,    79,     0,     0,    80,     0,
      81,     0,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,     0,     0,     0,     0,
       0,    96,    97,    98,     0,     0,     0,     0,     0,     0,
      99,     0,   100,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,   472,   473,   474,   475,     0,     0,     0,
       0,   476,     0,     0,     0,     0,     0,     0,   975,   462,
     463,   464,   465,   466,   467,   468,   469,   470,   471,   472,
     473,   474,   475,     0,     0,     0,     0,   476,     0,     0,
       0,     0,     0,     0,   983,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   471,   472,   473,   474,   475,     0,
       0,     0,     0,   476,     0,     0,     0,     0,     0,     0,
     984,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,   472,   473,   474,   475,     0,     0,     0,     0,   476,
       0,     0,     0,     0,     0,     0,   985,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,   474,
     475,     0,     0,     0,     0,   476,     0,     0,     0,     0,
       0,     0,  1000,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,   472,   473,   474,   475,     0,     0,     0,
       0,   476,     0,     0,     0,     0,     0,     0,  1135,   462,
     463,   464,   465,   466,   467,   468,   469,   470,   471,   472,
     473,   474,   475,     0,     0,     0,     0,   476,     0,     0,
       0,     0,     0,     0,  1136,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   471,   472,   473,   474,   475,     0,
       0,     0,     0,   476,     0,     0,     0,     0,     0,     0,
    1137,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,   472,   473,   474,   475,     0,     0,     0,     0,   476,
       0,     0,     0,     0,     0,     0,  1172,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,   474,
     475,     0,     0,     0,     0,   476,     0,     0,     0,     0,
       0,     0,  1181,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,   472,   473,   474,   475,     0,     0,     0,
       0,   476,     0,     0,     0,     0,     0,     0,  1182,   462,
     463,   464,   465,   466,   467,   468,   469,   470,   471,   472,
     473,   474,   475,     0,     0,     0,     0,   476,     0,     0,
       0,     0,     0,     0,  1184,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   471,   472,   473,   474,   475,     0,
       0,     0,     0,   476,     0,     0,     0,     0,     0,     0,
    1295,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,   472,   473,   474,   475,     0,     0,     0,     0,   476,
       0,     0,     0,     0,     0,     0,  1346,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,   474,
     475,     0,     0,     0,     0,   476,     0,     0,     0,     0,
       0,     0,  1347,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,   472,   473,   474,   475,     0,     0,     0,
       0,   476,     0,     0,     0,     0,     0,     0,  1412,   462,
     463,   464,   465,   466,   467,   468,   469,   470,   471,   472,
     473,   474,   475,     0,     0,     0,     0,   476,     0,     0,
       0,     0,     0,     0,  1581,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   471,   472,   473,   474,   475,     0,
       0,     0,     0,   476,     0,     0,     0,     0,     0,     0,
    1582,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,   472,   473,   474,   475,     0,     0,     0,     0,   476,
       0,     0,     0,     0,     0,     0,  1583,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,   474,
     475,     0,     0,     0,     0,   476,     0,     0,     0,     0,
       0,     0,  1584,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,   472,   473,   474,   475,     0,     0,     0,
       0,   476,     0,     0,     0,     0,     0,     0,  1585,   462,
     463,   464,   465,   466,   467,   468,   469,   470,   471,   472,
     473,   474,   475,     0,     0,     0,     0,   476,     0,     0,
       0,     0,     0,     0,  1586,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   471,   472,   473,   474,   475,     0,
       0,     0,     0,   476,     0,     0,     0,     0,     0,     0,
    1587,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,   472,   473,   474,   475,     0,     0,     0,     0,   476,
       0,     0,     0,     0,     0,     0,  1640,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,   474,
     475,     0,     0,     0,     0,   476,     0,     0,     0,     0,
       0,     0,  1641,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,   472,   473,   474,   475,     0,     0,     0,
       0,   476,     0,     0,     0,     0,     0,     0,  1648,   462,
     463,   464,   465,   466,   467,   468,   469,   470,   471,   472,
     473,   474,   475,     0,     0,     0,     0,   476,     0,     0,
       0,     0,     0,     0,  1823,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   471,   472,   473,   474,   475,     0,
       0,     0,     0,   476,     0,     0,     0,     0,     0,     0,
    1824,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,   472,   473,   474,   475,     0,     0,     0,     0,   476,
       0,     0,     0,     0,     0,     0,  1825,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,   474,
     475,     0,     0,     0,     0,   476,     0,     0,     0,     0,
       0,     0,  1826,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,   472,   473,   474,   475,     0,     0,     0,
       0,   476,     0,     0,     0,     0,     0,     0,  1827,   462,
     463,   464,   465,   466,   467,   468,   469,   470,   471,   472,
     473,   474,   475,     0,     0,     0,     0,   476,     0,     0,
       0,     0,     0,     0,  1851,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   471,   472,   473,   474,   475,     0,
       0,     0,     0,   476,     0,     0,     0,     0,     0,     0,
    1852,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,   472,   473,   474,   475,     0,     0,     0,     0,   476,
       0,     0,     0,     0,     0,     0,  1856,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,   474,
     475,     0,     0,     0,     0,   476,     0,     0,     0,     0,
       0,     0,  1964,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,   472,   473,   474,   475,     0,     0,     0,
       0,   476,     0,     0,     0,     0,     0,     0,  1965,   462,
     463,   464,   465,   466,   467,   468,   469,   470,   471,   472,
     473,   474,   475,     0,     0,     0,     0,   476,     0,     0,
       0,     0,     0,     0,  1966,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   471,   472,   473,   474,   475,     0,
       0,     0,     0,   476,     0,     0,     0,     0,     0,     0,
    1967,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,   472,   473,   474,   475,     0,     0,     0,     0,   476,
       0,     0,     0,     0,     0,     0,  1968,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,   474,
     475,     0,     0,     0,     0,   476,     0,     0,     0,     0,
       0,     0,  1978,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,   472,   473,   474,   475,     0,     0,     0,
       0,   476,     0,     0,     0,     0,     0,     0,  1981,   462,
     463,   464,   465,   466,   467,   468,   469,   470,   471,   472,
     473,   474,   475,     0,     0,     0,     0,   476,     0,     0,
       0,     0,     0,     0,  2031,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   471,   472,   473,   474,   475,     0,
       0,     0,     0,   476,     0,     0,     0,     0,     0,     0,
    2051,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,   472,   473,   474,   475,     0,     0,     0,     0,   476,
       0,     0,     0,     0,     0,     0,  2052,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,   474,
     475,     0,     0,     0,     0,   476,     0,     0,     0,     0,
       0,     0,  2053,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,   472,   473,   474,   475,     0,     0,     0,
       0,   476,     0,     0,     0,     0,     0,     0,  2054,   462,
     463,   464,   465,   466,   467,   468,   469,   470,   471,   472,
     473,   474,   475,     0,     0,     0,     0,   476,     0,     0,
       0,     0,     0,     0,  2055,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   471,   472,   473,   474,   475,     0,
       0,     0,     0,   476,     0,     0,     0,     0,     0,     0,
    2106,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,   472,   473,   474,   475,     0,     0,     0,     0,   476,
       0,     0,     0,     0,     0,     0,  2107,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,   474,
     475,     0,     0,     0,     0,   476,     0,     0,     0,     0,
       0,     0,  2108,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,   472,   473,   474,   475,     0,     0,     0,
       0,   476,     0,     0,     0,     0,     0,     0,  2109,   462,
     463,   464,   465,   466,   467,   468,   469,   470,   471,   472,
     473,   474,   475,     0,     0,     0,     0,   476,     0,   888,
       0,   889,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,   472,   473,   474,   475,     0,     0,     0,     0,
     476,     0,     0,     0,   731,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   471,   472,   473,   474,   475,     0,
       0,     0,     0,   476,     0,     0,     0,   936,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,   472,   473,
     474,   475,     0,     0,     0,     0,   476,     0,     0,     0,
     955,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,   472,   473,   474,   475,     0,     0,     0,     0,   476,
       0,     0,     0,   962,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   471,   472,   473,   474,   475,     0,     0,
       0,     0,   476,     0,     0,     0,  1058,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,   474,
     475,     0,     0,     0,     0,   476,     0,     0,     0,  1165,
     462,   463,   464,   465,   466,   467,   468,   469,   470,   471,
     472,   473,   474,   475,     0,     0,     0,     0,   476,     0,
       0,     0,  1166,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,   472,   473,   474,   475,     0,     0,     0,
       0,   476,     0,     0,     0,  1170,   462,   463,   464,   465,
     466,   467,   468,   469,   470,   471,   472,   473,   474,   475,
       0,     0,     0,     0,   476,     0,     0,     0,  1171,   462,
     463,   464,   465,   466,   467,   468,   469,   470,   471,   472,
     473,   474,   475,     0,     0,     0,     0,   476,     0,     0,
       0,  1174,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,   472,   473,   474,   475,     0,     0,     0,     0,
     476,     0,     0,     0,  1198,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   471,   472,   473,   474,   475,     0,
       0,     0,     0,   476,     0,     0,     0,  1231,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,   472,   473,
     474,   475,     0,     0,     0,     0,   476,     0,     0,     0,
    1288,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,   472,   473,   474,   475,     0,     0,     0,     0,   476,
       0,     0,     0,  1293,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   471,   472,   473,   474,   475,     0,     0,
       0,     0,   476,     0,     0,     0,  1576,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,   474,
     475,     0,     0,     0,     0,   476,     0,     0,     0,  1631,
     462,   463,   464,   465,   466,   467,   468,   469,   470,   471,
     472,   473,   474,   475,     0,     0,     0,     0,   476,     0,
       0,     0,  1806,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,   472,   473,   474,   475,     0,     0,     0,
       0,   476,     0,   727,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   471,   472,   473,   474,   475,     0,     0,
       0,     0,   476,     0,   784,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   471,   472,   473,   474,   475,     0,
       0,     0,     0,   476,     0,   788,   462,   463,   464,   465,
     466,   467,   468,   469,   470,   471,   472,   473,   474,   475,
       0,     0,     0,     0,   476,     0,   789,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,   474,
     475,     0,     0,     0,     0,   476,     0,   791,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,   472,   473,
     474,   475,     0,     0,     0,     0,   476,     0,   793,   462,
     463,   464,   465,   466,   467,   468,   469,   470,   471,   472,
     473,   474,   475,     0,     0,     0,     0,   476,     0,   794,
     462,   463,   464,   465,   466,   467,   468,   469,   470,   471,
     472,   473,   474,   475,     0,     0,     0,     0,   476,     0,
     797,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,   472,   473,   474,   475,     0,     0,     0,     0,   476,
       0,   798,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,   472,   473,   474,   475,     0,     0,     0,     0,
     476,     0,   799,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,   472,   473,   474,   475,     0,     0,     0,
       0,   476,     0,   800,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   471,   472,   473,   474,   475,     0,     0,
       0,     0,   476,     0,   810,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   471,   472,   473,   474,   475,     0,
       0,     0,     0,   476,     0,   916,   462,   463,   464,   465,
     466,   467,   468,   469,   470,   471,   472,   473,   474,   475,
       0,     0,     0,     0,   476,     0,   926,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,   474,
     475,     0,     0,     0,     0,   476,     0,   927,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,   472,   473,
     474,   475,     0,     0,     0,     0,   476,     0,   928,   462,
     463,   464,   465,   466,   467,   468,   469,   470,   471,   472,
     473,   474,   475,     0,     0,     0,     0,   476,     0,   934,
     462,   463,   464,   465,   466,   467,   468,   469,   470,   471,
     472,   473,   474,   475,     0,     0,     0,     0,   476,     0,
     935,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,   472,   473,   474,   475,     0,     0,     0,     0,   476,
       0,   942,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,   472,   473,   474,   475,     0,     0,     0,     0,
     476,     0,   951,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,   472,   473,   474,   475,     0,     0,     0,
       0,   476,     0,   961,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   471,   472,   473,   474,   475,     0,     0,
       0,     0,   476,     0,  1057,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   471,   472,   473,   474,   475,     0,
       0,     0,     0,   476,     0,  1085,   462,   463,   464,   465,
     466,   467,   468,   469,   470,   471,   472,   473,   474,   475,
       0,     0,     0,     0,   476,     0,  1090,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,   474,
     475,     0,     0,     0,     0,   476,     0,  1097,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,   472,   473,
     474,   475,     0,     0,     0,     0,   476,     0,  1102,   462,
     463,   464,   465,   466,   467,   468,   469,   470,   471,   472,
     473,   474,   475,     0,     0,     0,     0,   476,     0,  1103,
     462,   463,   464,   465,   466,   467,   468,   469,   470,   471,
     472,   473,   474,   475,     0,     0,     0,     0,   476,     0,
    1109,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,   472,   473,   474,   475,     0,     0,     0,     0,   476,
       0,  1118,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,   472,   473,   474,   475,     0,     0,     0,     0,
     476,     0,  1119,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,   472,   473,   474,   475,     0,     0,     0,
       0,   476,     0,  1120,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   471,   472,   473,   474,   475,     0,     0,
       0,     0,   476,     0,  1152,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   471,   472,   473,   474,   475,     0,
       0,     0,     0,   476,     0,  1154,   462,   463,   464,   465,
     466,   467,   468,   469,   470,   471,   472,   473,   474,   475,
       0,     0,     0,     0,   476,     0,  1155,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,   474,
     475,     0,     0,     0,     0,   476,     0,  1156,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,   472,   473,
     474,   475,     0,     0,     0,     0,   476,     0,  1157,   462,
     463,   464,   465,   466,   467,   468,   469,   470,   471,   472,
     473,   474,   475,     0,     0,     0,     0,   476,     0,  1158,
     462,   463,   464,   465,   466,   467,   468,   469,   470,   471,
     472,   473,   474,   475,     0,     0,     0,     0,   476,     0,
    1159,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,   472,   473,   474,   475,     0,     0,     0,     0,   476,
       0,  1160,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,   472,   473,   474,   475,     0,     0,     0,     0,
     476,     0,  1164,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,   472,   473,   474,   475,     0,     0,     0,
       0,   476,     0,  1173,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   471,   472,   473,   474,   475,     0,     0,
       0,     0,   476,     0,  1197,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   471,   472,   473,   474,   475,     0,
       0,     0,     0,   476,     0,  1287,   462,   463,   464,   465,
     466,   467,   468,   469,   470,   471,   472,   473,   474,   475,
       0,     0,     0,     0,   476,     0,  1292,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,   474,
     475,     0,     0,     0,     0,   476,     0,  1456,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,   472,   473,
     474,   475,     0,     0,     0,     0,   476,     0,  1685,   462,
     463,   464,   465,   466,   467,   468,   469,   470,   471,   472,
     473,   474,   475,     0,     0,     0,     0,   476,     0,  1702,
     462,   463,   464,   465,   466,   467,   468,   469,   470,   471,
     472,   473,   474,   475,     0,     0,     0,     0,   476,     0,
    1732,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,   472,   473,   474,   475,     0,     0,     0,     0,   476,
       0,  1977,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,   472,   473,   474,   475,     0,     0,     0,     0,
     476,     0,  2061,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,   472,   473,   474,   475,     0,     0,     0,
       0,   476
};

static const yytype_int16 yycheck[] =
{
       3,  1151,   414,     6,   416,   272,  1599,  1600,  1147,  1565,
       6,     4,   556,   557,     6,     6,     6,     4,     4,   431,
       3,     5,     0,     4,     6,   219,     5,     4,     4,     4,
       4,     4,   226,     5,   223,     4,  1777,     4,     4,   228,
       5,   287,     4,     4,    87,     5,     5,    90,    90,     5,
       5,     5,     5,   209,   210,     6,     6,   303,   219,     6,
       6,     6,   161,     6,    67,   115,     7,     4,     7,     6,
     226,   447,    75,   449,   219,   451,   221,    80,   177,   178,
       6,   131,    13,     6,   209,   210,   219,     6,    91,   139,
     140,   141,   209,   210,   220,   145,   146,   147,   148,   225,
     225,    91,   227,    93,   222,   209,   210,   225,     7,  1665,
     227,   209,   210,   219,   209,   210,   219,   363,   221,   365,
     226,   225,    84,   227,   219,   371,    88,   225,     4,     5,
     219,   226,    94,    95,    96,    97,   124,   226,     6,    87,
     209,   210,    90,     7,   209,   210,   108,    84,   211,   212,
     213,   222,     6,     4,   225,   218,   225,     4,   227,    54,
      55,   226,    57,     6,   151,   152,   153,   154,    44,    45,
      46,    47,    48,    49,    50,    51,    52,   227,   209,   210,
     164,    57,    58,    59,    60,   164,   219,  1928,  1929,    65,
      66,    67,   164,   226,    70,   226,     6,   200,   172,   164,
     219,   176,   149,   149,     7,    81,   149,   226,     7,   212,
     213,   219,     7,   209,   210,   206,  1772,   220,   201,   195,
     221,   195,   195,   149,   206,   228,   219,   230,   221,     6,
     223,  1370,   235,   219,  1790,   228,   239,   227,   219,   219,
     227,   244,   245,     6,   221,   226,   249,   250,   251,   252,
     253,   228,   226,   226,   257,   258,   259,   226,   219,   226,
     226,   226,   265,   266,   267,   226,   226,   226,   271,   272,
     226,   226,   226,   226,   219,   226,   226,     7,   219,     3,
     221,   226,     6,   659,   223,   661,   209,   210,   221,     7,
     209,   210,   219,     7,   297,   298,   299,   196,   197,   198,
     199,   547,   548,     6,   180,   181,   182,   220,   311,   312,
     161,   162,   225,     8,   161,   162,   192,   219,   194,   195,
      84,   567,   220,    87,   222,   328,    90,   330,   226,   219,
     209,   210,   196,   197,   198,   199,     7,   220,   209,   210,
     216,   217,   225,    67,   212,   213,   225,   223,   209,   210,
     226,   727,   216,   217,   225,   731,    80,   209,   210,   223,
     219,   209,   210,   219,   225,   221,   369,    91,   209,   210,
     373,   374,   228,   225,   216,   217,   244,   225,   100,  1972,
     275,   276,   220,   386,   225,   253,   219,   225,   283,   379,
     636,     7,   287,   196,   197,   198,   199,   196,   197,   198,
     199,   196,   197,   198,   199,   651,    90,   219,    92,     8,
     219,   414,   415,   416,   417,   418,   419,   420,   421,   422,
     423,   424,   425,   426,  1980,   428,   429,   430,   431,   432,
     219,   209,   210,   436,   437,   438,   439,   440,   441,   225,
     443,   227,   209,   210,   434,   209,   210,   225,   209,   210,
      84,    90,   442,    87,    90,   219,    90,   460,   225,   209,
     210,     6,   226,   451,   225,   220,   196,   197,   198,   199,
     225,   225,   225,   227,   227,   225,   200,     8,   196,   197,
     198,   199,   196,   197,   198,   199,   216,   217,   212,   213,
     216,   217,   220,   226,   222,   498,   220,   225,   216,   217,
     226,   369,   216,   217,   228,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   220,
     244,   209,   210,   218,   225,   196,   197,   198,   199,   253,
     216,   217,   227,   225,   219,   227,  2092,   225,   541,   542,
     226,   531,   532,   533,   534,   216,   217,   415,   272,   417,
     418,   419,   420,   421,   422,   423,   219,   425,   426,    92,
     428,   429,   430,   225,   432,   227,     6,     7,   436,   437,
     438,   439,   440,   556,   557,   951,   209,   210,    90,   955,
     196,   197,   198,   199,   587,   588,   589,    90,   216,   217,
       6,     7,   225,   216,   217,   841,   599,   600,   226,   222,
     603,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   618,   220,   219,     6,   218,
      87,   225,   625,   209,   210,   226,   209,   210,   227,   226,
     209,   210,   115,   209,   210,   219,     4,   221,   219,   225,
     221,   644,   225,    90,   228,   369,   225,   228,   131,   225,
     225,  1801,   227,  1803,     6,  1805,   139,   140,   141,   554,
     555,   664,   145,   146,   147,   148,   220,   562,   222,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   671,   209,   210,   225,   218,   227,   220,
     414,   415,   416,   417,   418,   419,   420,   421,   422,   423,
     225,   425,   426,    87,   428,   429,   430,   431,   432,   209,
     210,    87,   436,   437,   438,   439,   440,   441,   220,   443,
     222,   209,   210,   726,   226,   225,   220,   730,   222,   209,
     210,   225,   209,   210,  1110,   603,  1112,   225,  1114,   727,
    1116,    90,   732,   731,  1883,   225,   219,  1886,   225,     4,
    1889,   119,   120,   121,   122,   115,   209,   210,   209,   210,
       4,   209,   210,   209,   210,   133,   769,     4,   136,  1036,
     773,   131,   225,   776,   225,     4,   779,   225,   781,   139,
     140,   141,   785,   786,   219,   145,   146,   147,   148,   219,
     219,   209,   210,   783,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,  1956,   225,   219,     6,
     218,   814,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,    84,   209,   210,    87,
     218,   225,    90,   227,    92,   838,   209,   210,   211,   212,
     213,  1253,  1254,   225,   221,   218,  1258,  1259,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   209,   210,     6,   219,   218,   227,  2007,   219,
     216,   217,   216,   217,   216,   217,   600,     7,   225,   603,
     226,   223,   226,   221,  2034,  1261,  2036,   890,  2038,   892,
     216,   217,   895,    87,  2044,   219,    90,   221,    92,   887,
     226,  1277,   219,   219,   228,   908,     6,   910,   776,   912,
     219,   914,   221,   781,   223,   219,   919,   226,   219,   228,
     221,   924,   223,   219,    90,   221,    92,   228,  2067,   119,
     120,  2070,   228,   219,  2073,   125,   219,  2076,   221,    87,
     223,   219,    90,   946,    92,   228,   219,   950,  2098,   844,
    2100,   954,  2102,     6,   119,   120,   851,   219,    84,   962,
     125,    87,   857,   951,    90,   219,    92,   955,   219,   225,
     220,   227,   222,   961,   962,   225,   225,     6,   227,  2118,
     220,  2120,   222,  2122,   987,   225,   220,   226,   222,   992,
     225,   225,   227,   221,   997,   998,   999,  1000,     6,  1543,
    1544,  1268,   225,   220,   227,   222,   226,  1010,   225,  1012,
     226,   219,  1424,  1425,   219,   219,   115,  1429,  1430,   226,
       6,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     219,   219,   131,  1036,   218,   226,  1039,  1040,  1041,  1042,
     139,   140,   141,   225,   219,   227,   145,   146,   147,   148,
       4,   220,   776,   222,   226,   779,   225,   781,  1434,   219,
     219,  1064,   225,   225,   227,   227,    90,   219,    92,  1057,
    1058,   225,   225,   227,   227,   225,   225,   227,   227,   219,
    1083,  1084,   225,  1086,   227,  1088,  1089,   226,   226,  1092,
    1093,  1094,  1095,   226,   962,     6,  1099,   225,  1101,   227,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   225,   225,   227,   227,   218,   225,
     225,   227,   227,   225,   992,   227,   219,   225,   227,   227,
     998,   999,  1000,   225,   225,   227,   227,   225,   225,   227,
     227,   225,  1010,   227,  1012,   226,   219,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,     4,   225,     6,   227,   218,   225,   225,   227,   227,
     225,   221,   227,  1419,   225,  1421,   227,   225,   219,   227,
     225,   219,   227,   230,  1079,  1173,  1174,     6,   235,   225,
       6,   227,   239,   225,   219,   227,  1064,  1200,  1201,  1202,
     219,   219,   249,   225,   225,   227,   227,   219,  1475,  1197,
    1198,   228,     6,  1216,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   225,   225,
     227,   227,   218,   225,   225,   227,   227,   225,   962,   227,
    1135,  1136,  1137,   225,   225,   227,   227,   225,     6,   227,
    1253,  1254,  1796,   226,   226,  1258,  1259,   225,     6,   227,
     225,   225,   227,   227,   225,  1268,   227,   225,   992,   227,
      12,    13,     6,  1261,   998,   999,  1000,   226,   225,  1282,
     227,   328,   225,   330,   227,   225,  1010,   227,  1012,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,  1306,   226,   221,  1296,   218,   225,  1312,
     227,     6,  1036,   225,   221,   227,   221,  1320,   226,   164,
    1323,  1324,   228,     6,     6,  1328,  1329,   226,  1331,     6,
    1333,     6,  1335,   226,  1337,  1338,  1339,   226,     6,   221,
    1064,  1753,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,  1356,     4,   218,   223,    99,     7,   101,
     226,   225,   227,   225,   106,   107,   108,   109,  1371,   111,
     112,   113,   220,     7,     6,   117,  1379,     6,  1381,     6,
     220,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,     7,     7,     6,     6,   218,
       6,     6,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   460,   156,   157,   158,   218,   220,   226,
       7,  1424,  1425,     6,     4,     7,  1429,  1430,  1418,     6,
       6,     6,    62,   161,    62,   226,   250,   251,   252,    62,
    1443,    62,   222,   257,   258,   259,  1449,   220,  1436,     6,
       6,   498,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   220,   220,   225,   225,
     218,   222,  1475,   225,  1369,   225,   225,  1467,  1481,   225,
     225,   220,   220,   297,   298,   227,    44,   220,  1491,    44,
      44,  1494,    44,     6,   541,   542,  1763,   311,   312,     4,
       4,     7,   164,     6,  1494,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,     6,
       6,     6,   164,   218,     7,   164,     7,     7,     7,  1253,
    1254,     7,  1535,  1536,  1258,  1259,     7,     7,     7,     7,
     587,   588,   589,     6,  1268,   226,     7,     4,     6,  1539,
     220,   225,   599,   600,   220,   220,   225,   220,   225,   223,
    1543,  1544,  1565,     6,  1810,   225,   227,   220,  1571,   227,
     222,   618,   226,     7,     7,  1443,     7,     7,   625,   226,
     226,  1449,   226,   223,   227,   226,     6,     6,  1591,  1577,
      44,    44,    44,    44,     6,     6,     6,   644,  1601,     6,
     226,     7,   221,     6,   219,   115,   219,  1597,  1611,  1504,
       6,   206,     7,  1616,     7,    92,     7,   664,     7,     7,
       7,   131,     6,  1491,     4,     7,  1616,  1617,  1618,   139,
     140,   141,     7,   115,     7,   145,   146,   147,   148,  1642,
       7,     4,     5,     7,     4,     7,   219,   226,     6,   131,
    1545,     7,  1547,     6,  1549,     7,     7,   139,   140,   141,
     226,     7,  1665,   145,   146,   147,   148,  1913,     7,     7,
       7,  1566,  1567,  1568,  1569,  1570,  1571,     7,     6,     6,
       6,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      90,     7,     6,     6,    57,    58,    59,    60,  1701,     4,
    1424,  1425,    65,    66,    67,  1429,  1430,    70,     4,     4,
    1713,  1957,   226,   225,     6,   226,     6,   227,    81,  1443,
     227,     6,   769,     6,     6,  1449,   773,     4,     6,   225,
    1733,   220,   115,   225,     7,   223,   220,     6,   785,   786,
       6,   219,     6,     6,     6,   227,  1736,  1750,   131,   222,
    1753,  1475,   226,   220,   226,     6,   139,   140,   141,   223,
    1763,   226,   145,   146,   147,   148,   108,  1491,   115,  1772,
     226,   226,     6,     6,     6,     6,  1779,  1780,   226,     6,
       5,     4,     6,   220,   131,     6,   226,  1790,   226,     7,
    1793,   838,   139,   140,   141,   221,     6,   226,   145,   146,
     147,   148,   226,     6,     6,     6,  1809,     4,   226,   226,
    1813,   226,   226,  1796,   222,     6,     6,   180,   181,   182,
     160,   226,   226,     6,   226,     6,   225,     4,     7,   192,
       6,   194,   195,     6,     6,     4,     6,   223,     6,     6,
       6,     6,     4,   890,   227,   892,     7,     6,   895,     6,
       6,     6,     5,   164,     6,   226,     6,   220,     6,   222,
     115,   908,     6,   910,     6,   912,     6,   914,     6,  1872,
       6,   115,   919,     6,     6,     6,   131,   924,     6,     6,
     227,   225,     6,     6,   139,   140,   141,   131,  1891,     6,
     145,   146,   147,   148,     6,   139,   140,   141,     6,     6,
     225,   145,   146,   147,   148,  1800,     6,  1802,   220,  1804,
       6,     6,     6,     6,     6,  1918,     7,     6,     6,  1814,
    1815,  1816,  1817,  1818,     6,    12,    13,  1917,   226,     6,
       5,     7,   226,   226,    88,     6,     6,   115,   226,   226,
     987,   227,     6,   227,     6,   226,   226,     6,   159,     6,
     226,   226,     6,   131,     6,   227,  1959,  1960,  1961,  1962,
    1963,   139,   140,   141,     6,     6,   227,   145,   146,   147,
     148,   227,   227,     6,     6,   162,  1871,  1980,     6,     6,
    1875,     6,     6,   227,     6,     6,     6,   226,     6,     6,
     220,   226,  1039,  1040,  1041,  1042,     6,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,     7,     6,
     226,   226,    99,   226,   101,     6,     6,   226,     6,   106,
     107,   108,   109,   227,   111,   112,   113,   226,     6,  1753,
     117,   115,  2022,     6,     6,     6,     6,     6,  1933,  1763,
       6,     6,  1937,     6,     6,     6,  2049,   227,     6,   227,
       6,   226,  1099,   227,     6,   219,     6,  2060,     6,     6,
     220,     6,     6,   226,     6,     6,    99,     6,  1963,   156,
     157,   158,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,     6,   226,     6,  2092,
     218,   226,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   226,  2110,   226,  2112,
     218,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   226,     6,   226,   226,   218,
       6,     6,     6,     6,     6,     6,     6,  2032,  2033,  2142,
     227,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   115,     6,     6,     6,   218,
       6,   194,   195,   196,   197,   198,  1291,     6,  1778,  1921,
     494,   131,     3,  1305,   529,     3,     3,     3,   211,   139,
     140,   141,   215,    12,    13,   145,   146,   147,   148,  1792,
    1471,    -1,  2060,    -1,  1918,    -1,   229,   230,   231,   232,
      -1,   234,   235,   236,   237,    -1,   239,   240,   241,   242,
     243,     7,     8,    -1,    -1,    -1,   249,    -1,    -1,    -1,
      -1,   254,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   269,    -1,    -1,    -1,
     218,    -1,  2110,    -1,  2112,   278,   279,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   287,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    -1,   227,    -1,    -1,
      99,    -1,   101,    -1,  2142,   115,    -1,   106,   107,   108,
     109,    -1,   111,   112,   113,    -1,    -1,    -1,   117,    -1,
      -1,   131,    -1,    -1,    -1,   328,   329,   330,    -1,   139,
     140,   141,    -1,    -1,    -1,   145,   146,   147,   148,   342,
     343,   344,    -1,   346,    -1,    -1,    -1,   350,   351,   352,
      -1,    -1,   355,    -1,    -1,    -1,    -1,   156,   157,   158,
      -1,    -1,    -1,    -1,  1381,    -1,  2060,   370,    -1,    -1,
      -1,    -1,   375,   376,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   389,   390,    -1,   392,
     393,   394,   395,   396,   397,   398,   399,   400,   401,   402,
     403,   404,   405,   406,   407,   408,   409,   410,   411,   412,
     413,    -1,    -1,    -1,    -1,    -1,  2110,   227,  2112,    -1,
      -1,    -1,    -1,    -1,   427,    -1,    -1,    -1,   227,    -1,
     433,    -1,   435,     6,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,  2142,    -1,
      -1,    -1,   218,    -1,    -1,    -1,   459,   460,    -1,   462,
     463,   464,   465,   466,   467,   468,   469,   470,   471,   472,
     473,   474,   475,   476,    -1,    -1,   479,   480,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,    -1,    -1,    -1,   498,   218,    -1,    -1,    -1,
      -1,   504,    -1,   225,    -1,   227,   509,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   517,   518,    -1,    -1,  1535,  1536,
      -1,    -1,   525,   526,    -1,    -1,    -1,   530,   531,   532,
     533,   534,   535,    -1,   537,    -1,   539,    -1,   541,   542,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1571,    -1,   559,   560,   561,   562,
     563,   564,    -1,    -1,    -1,   568,   569,   570,   571,   572,
     573,   574,   575,   576,    -1,    -1,    -1,   580,    -1,   582,
     583,    -1,    -1,    -1,   587,   588,   589,    -1,    -1,   592,
     593,   594,   595,   596,    -1,    -1,   599,   600,   601,   602,
      -1,   604,    -1,    -1,   607,    12,    13,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   618,    -1,    -1,    -1,    -1,
      -1,   624,   625,    -1,   627,   628,    -1,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   644,   115,    -1,    -1,   218,   649,   650,    -1,   652,
     653,    -1,    -1,    -1,    -1,     6,    -1,    -1,   131,    -1,
     663,   664,    -1,    -1,    -1,   668,   139,   140,   141,    -1,
      -1,    -1,   145,   146,   147,   148,    -1,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    -1,    -1,
      -1,    -1,    99,    -1,   101,    -1,  1713,    -1,    -1,   106,
     107,   108,   109,    -1,   111,   112,   113,    -1,    -1,    -1,
     117,    -1,    -1,    -1,    -1,    -1,  1733,    -1,    -1,   230,
      -1,    -1,    -1,    -1,   235,    -1,    -1,    -1,   239,    -1,
     733,    -1,    -1,  1750,    -1,    -1,   115,    -1,   249,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   156,
     157,   158,   245,    -1,   227,    -1,     6,    -1,    -1,    -1,
      -1,    -1,   765,   766,    -1,    -1,   769,   770,   771,    -1,
     773,   774,   265,   266,   267,    -1,  1793,    -1,   271,   782,
      -1,    -1,   785,   786,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1813,    -1,    -1,   802,
      -1,    -1,    -1,    -1,    -1,    -1,   299,    -1,    -1,    -1,
     813,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     227,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   838,    -1,    -1,    -1,   218,
      -1,    -1,   845,   846,    -1,    -1,    -1,    -1,   851,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,    -1,    -1,   868,    -1,   218,   871,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     373,   374,    -1,    -1,    -1,    -1,     6,   890,    -1,   892,
      -1,    -1,   895,   386,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   908,    -1,   910,    -1,   912,
      -1,   914,    -1,    -1,    -1,    -1,   919,    -1,    -1,    -1,
      -1,   924,    -1,    -1,    -1,    -1,    -1,   930,    -1,   932,
     933,   424,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     943,    -1,  1959,  1960,  1961,  1962,  1963,    -1,    -1,   460,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,    -1,    -1,    -1,    -1,   218,    -1,
      -1,    -1,   975,    -1,    12,    13,    -1,    -1,    -1,    -1,
     983,   984,   985,    -1,   987,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   995,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1009,    -1,    -1,    -1,
      -1,  1014,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1023,    -1,    -1,    -1,    -1,    -1,  1029,    -1,    -1,    -1,
     541,   542,  2049,    -1,    -1,    -1,  1039,  1040,  1041,  1042,
      -1,    -1,  1045,    -1,    -1,     7,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    -1,    -1,    -1,
      -1,    99,    -1,   101,    -1,    12,    13,    -1,   106,   107,
     108,   109,    -1,   111,   112,   113,   587,   588,   589,   117,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,    -1,    -1,  1099,    -1,   218,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   618,  1111,    -1,
    1113,    -1,  1115,    -1,  1117,    -1,    -1,    -1,   156,   157,
     158,    -1,    -1,    -1,    -1,    -1,    12,    13,    -1,    -1,
      -1,    -1,    -1,   644,    -1,    -1,  1139,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    -1,    -1,
      -1,    -1,    99,   664,   101,    -1,    -1,    -1,    -1,   106,
     107,   108,   109,    -1,   111,   112,   113,    -1,    -1,  1172,
     117,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1181,  1182,
      -1,  1184,  1185,    -1,  1187,  1188,  1189,    -1,    -1,   227,
      -1,    -1,  1195,    -1,    -1,    -1,    -1,    -1,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,   156,
     157,   158,    -1,    99,    -1,   101,    -1,    -1,    -1,  1222,
     106,   107,   108,   109,  1227,   111,   112,   113,    -1,    12,
      13,   117,    -1,   726,    -1,    -1,    -1,   730,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,    -1,    -1,    -1,    -1,   218,    -1,   769,    -1,
      -1,    -1,   773,    -1,    -1,    -1,  1269,    -1,    -1,    -1,
     156,   157,   158,    -1,    -1,    -1,    -1,  1280,  1281,    -1,
     227,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1295,  1296,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    -1,    -1,    -1,    -1,    99,    -1,   101,    -1,
      -1,   814,    -1,   106,   107,   108,   109,   838,   111,   112,
     113,    -1,    -1,    -1,   117,    -1,    -1,    -1,    -1,    -1,
      -1,   227,  1345,  1346,  1347,    -1,    -1,    -1,    -1,    -1,
      -1,    12,    13,  1356,    -1,  1358,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1369,    -1,    -1,    -1,
      -1,    -1,    -1,   156,   157,   158,    -1,    -1,  1381,   890,
      -1,   892,    -1,  1386,   895,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   908,    -1,   910,
      -1,   912,    -1,   914,    -1,    -1,    -1,    -1,   919,  1412,
    1413,  1414,    -1,   924,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    -1,    -1,    -1,    -1,    99,    -1,
     101,  1444,    -1,    -1,   227,   106,   107,   108,   109,    -1,
     111,   112,   113,   946,    -1,    -1,   117,   950,    -1,    -1,
      -1,   954,    -1,    -1,    -1,  1468,    -1,    -1,    -1,     8,
      -1,    -1,    -1,    -1,    -1,    -1,   987,    -1,    -1,  1482,
      -1,    -1,    -1,    -1,  1487,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   156,   157,   158,    -1,  1502,
    1503,    -1,    -1,    -1,   997,    -1,  1509,  1510,    -1,    -1,
      -1,  1514,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1525,    -1,    -1,    -1,    -1,    -1,  1039,  1040,
    1041,  1042,  1535,  1536,  1537,    -1,  1539,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1551,    -1,
      -1,    -1,    12,    13,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   227,    -1,  1571,    -1,
      -1,  1574,    -1,    -1,    -1,    -1,    -1,    -1,  1581,  1582,
    1583,  1584,  1585,  1586,  1587,    -1,    -1,    -1,  1099,    -1,
    1083,  1084,    -1,  1086,  1597,  1088,  1089,    -1,    -1,  1092,
    1093,  1094,  1095,    -1,    -1,    -1,    -1,    -1,  1101,    -1,
      -1,    -1,    -1,    -1,  1617,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    -1,    -1,  1640,  1641,    99,
      -1,   101,    -1,    -1,    -1,  1648,   106,   107,   108,   109,
      -1,   111,   112,   113,    -1,    -1,    -1,   117,    -1,    12,
      13,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,    -1,    -1,    -1,    -1,   218,
      -1,    -1,    -1,  1686,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     8,   156,   157,   158,    -1,
      -1,  1704,    -1,    -1,    -1,    -1,    -1,  1200,  1201,  1202,
    1713,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1216,    -1,  1728,    -1,  1730,    -1,    -1,
    1733,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    -1,    -1,    -1,    -1,    99,  1750,   101,    -1,
      -1,    -1,    -1,   106,   107,   108,   109,    -1,   111,   112,
     113,    -1,    -1,    -1,   117,  1768,    -1,   227,    -1,    -1,
    1773,    -1,    -1,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,    -1,    -1,  1282,
    1793,   218,    -1,    -1,    -1,    -1,    -1,  1800,   225,  1802,
     227,  1804,    -1,   156,   157,   158,    -1,    -1,    -1,    -1,
    1813,     8,    -1,  1306,    -1,    -1,    -1,    -1,    -1,  1312,
    1823,  1824,  1825,  1826,  1827,  1828,    -1,  1320,    -1,    -1,
    1323,  1324,    -1,    -1,    -1,  1328,  1329,     8,  1331,    -1,
    1333,    -1,  1335,    -1,  1337,  1338,  1339,    -1,  1851,  1852,
      -1,    -1,    -1,  1856,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     8,    -1,  1356,    -1,  1868,    -1,    -1,    -1,    -1,
    1381,    -1,    -1,    -1,   227,    -1,  1879,    -1,  1371,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1379,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,    -1,    -1,    -1,    -1,   218,    -1,    -1,    -1,    -1,
      -1,    -1,  1915,    -1,    -1,    -1,    -1,    -1,  1921,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1930,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1944,    -1,    -1,  1947,    -1,    -1,  1950,    -1,    -1,
      -1,  1954,    -1,    -1,    -1,    -1,  1959,  1960,  1961,  1962,
    1963,  1964,  1965,  1966,  1967,  1968,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1978,    -1,    -1,  1981,    -1,
      -1,    -1,    -1,    -1,    -1,     8,    -1,    -1,  1481,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1494,    -1,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,    -1,    -1,    -1,
      -1,   218,    -1,    -1,  1535,  1536,    -1,    -1,  2031,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,    -1,    -1,    -1,  2049,   218,  2051,  2052,
    2053,  2054,  2055,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,    -1,    -1,    -1,
      -1,   218,  1565,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   629,    -1,    -1,    -1,    -1,
      -1,    -1,  2095,  2096,    -1,    -1,    -1,    -1,  1591,    -1,
      -1,    -1,    -1,  2106,  2107,  2108,  2109,    -1,  1601,    -1,
      -1,    -1,    21,    22,    -1,    -1,    -1,    -1,  1611,    -1,
      -1,    -1,    -1,  1616,    -1,    -1,    -1,    -1,   672,   673,
     674,   675,   676,   677,   678,   679,   680,   681,   682,    -1,
     684,   685,   686,   687,   688,   689,   690,    -1,    -1,  1642,
     694,   695,   696,    -1,    -1,    -1,   700,   701,    -1,   703,
      -1,    -1,    -1,    -1,   708,   709,   710,    -1,   712,    -1,
      -1,    -1,  1665,    -1,    -1,   719,   720,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,    -1,    -1,   737,    -1,   218,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1701,    -1,
      -1,    -1,    -1,    -1,   123,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1733,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,    -1,    -1,
      -1,   160,   161,   162,   163,    -1,   165,   166,   167,   168,
     169,   170,    -1,    -1,   173,    -1,    -1,    -1,    -1,    -1,
     179,   180,    -1,    -1,    -1,    -1,   185,   186,    -1,  1772,
      -1,    -1,  1793,    -1,    -1,    -1,  1779,  1780,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1790,    -1,    -1,
      -1,    -1,  1813,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1809,    -1,    -1,     3,
       4,     5,    -1,    -1,    -1,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    -1,    -1,    -1,   900,    -1,    -1,    -1,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    -1,  1872,
      -1,    65,    66,    67,    -1,    -1,    70,    -1,    72,    73,
      74,    -1,    -1,    -1,    -1,    -1,    80,    81,  1891,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   316,    -1,    -1,
     319,   320,   321,   322,    -1,    -1,     4,     5,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     339,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1959,  1960,
    1961,  1962,  1963,    -1,    -1,    -1,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    -1,    -1,    -1,    -1,    57,
      58,    59,    60,    -1,    -1,    -1,    -1,    65,    66,    67,
      -1,    -1,    70,    -1,    -1,    -1,    -1,  1980,   172,    -1,
      -1,    -1,    -1,    81,    -1,   179,   180,   181,   182,   183,
    1044,    -1,    -1,   187,   188,   189,   190,   191,   192,    -1,
     194,   195,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   209,   210,    -1,    -1,    -1,
     214,    -1,    -1,  1077,  1078,   219,    -1,   221,  2049,   223,
     224,    -1,   226,    -1,   228,   454,    -1,    -1,    -1,    -1,
       3,     4,    -1,    -1,    -1,    -1,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    -1,
      -1,    -1,   180,   181,   182,    -1,    -1,    -1,    -1,  2092,
      53,    54,    55,    56,   192,    -1,   194,   195,    61,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,
      73,    74,    -1,    -1,    -1,    -1,    -1,    80,    -1,    -1,
      -1,    84,    -1,    -1,    87,    -1,    -1,    90,    -1,    92,
      -1,    -1,    -1,    -1,    -1,    98,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   112,
      -1,    -1,    -1,    -1,    -1,    -1,   119,   120,   121,   122,
     123,    -1,    -1,   126,   127,   128,   129,   130,    -1,    -1,
     133,    -1,    -1,   136,    -1,    -1,  1230,    -1,    -1,    -1,
      -1,    -1,  1236,  1237,  1238,  1239,  1240,    -1,  1242,    -1,
    1244,  1245,    -1,  1247,  1248,    -1,    -1,  1251,  1252,  1253,
      -1,    -1,    -1,    -1,  1258,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   179,    -1,    -1,    -1,
     183,    -1,    -1,    -1,   187,   188,   189,   190,   191,    -1,
      -1,    -1,   195,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   209,   210,    -1,    -1,
      -1,   214,    -1,    -1,    -1,    -1,   219,    -1,    -1,    -1,
      -1,   224,    -1,   226,   227,     3,     4,    -1,    -1,    -1,
      -1,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    53,    54,    55,    56,    -1,
      -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    72,    73,    74,  1391,    -1,    -1,
      -1,    -1,    80,    -1,    -1,    -1,    84,    -1,    -1,    87,
      -1,    -1,    90,  1407,    92,    -1,    -1,    -1,    -1,    -1,
      98,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1424,    -1,    -1,    -1,   112,  1429,    -1,    -1,    -1,    -1,
      -1,   119,   120,   121,   122,   123,    -1,    -1,   126,   127,
     128,   129,   130,    -1,    -1,   133,    -1,    -1,   136,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1461,  1462,    -1,
      -1,  1465,  1466,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,    -1,    -1,    -1,
      -1,   218,    -1,    -1,    -1,    -1,    -1,    -1,   225,    -1,
     227,   179,    -1,    -1,    -1,   183,    -1,    -1,    -1,   187,
     188,   189,   190,   191,     4,     5,    -1,   195,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   209,   210,    -1,    -1,    -1,   214,    -1,    -1,    -1,
      -1,   219,    -1,    -1,    -1,    -1,   224,    -1,    -1,   227,
      -1,    -1,    -1,    -1,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    -1,    -1,    -1,    -1,    57,    58,    59,
      60,    -1,    -1,    -1,    -1,    65,    66,    67,    -1,    -1,
      70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    81,    -1,    -1,    -1,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,    -1,
    1604,  1605,    -1,   218,  1608,  1609,    -1,    -1,    -1,    -1,
    1614,  1615,   227,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     4,     5,    -1,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,    -1,
      -1,    -1,    -1,   218,    -1,    -1,    -1,    -1,    -1,    -1,
    1019,  1020,   227,    -1,    -1,    -1,  1025,  1026,    -1,    -1,
      -1,    -1,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    -1,    -1,    -1,    -1,    57,    58,    59,    60,    -1,
     180,   181,   182,    65,    66,    67,    -1,    -1,    70,    -1,
      -1,    -1,   192,    -1,   194,   195,    -1,    -1,    -1,    81,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
      -1,    -1,    -1,     9,    10,    11,  1720,  1721,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    -1,    -1,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    -1,    -1,    -1,    65,
      66,    67,    -1,    -1,    70,    -1,    72,    73,    74,    -1,
      -1,    -1,    -1,    -1,    80,    81,    -1,    -1,    84,    -1,
      -1,    87,    -1,    -1,    90,    -1,    92,    -1,   180,   181,
     182,    -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     192,    -1,   194,    -1,    -1,    -1,   112,    -1,    -1,    -1,
      -1,    -1,    -1,   119,   120,   121,   122,   123,    -1,    -1,
     126,   127,   128,   129,   130,    -1,    -1,   133,    -1,    -1,
     136,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1219,  1220,    -1,    -1,    -1,  1224,  1225,    -1,    -1,    -1,
      -1,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,    -1,    -1,    -1,    -1,   218,
      -1,    -1,    -1,   179,   180,   181,   182,   183,   227,    -1,
      -1,   187,   188,   189,   190,   191,   192,    -1,   194,   195,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   209,   210,    -1,    -1,    -1,   214,    -1,
      -1,    -1,    -1,   219,    -1,     3,     4,     5,   224,    -1,
     226,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    -1,    -1,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    -1,    -1,    -1,    65,    66,    67,
      -1,    -1,    70,    -1,    72,    73,    74,    -1,    -1,    -1,
      -1,    -1,    80,    81,    -1,    -1,    84,    -1,    -1,    87,
      -1,    -1,    90,    -1,    92,    -1,    -1,    -1,    -1,    -1,
      98,    -1,     5,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   112,    -1,    -1,    -1,    -1,    -1,
      -1,   119,   120,   121,   122,   123,    -1,    -1,   126,   127,
     128,   129,   130,    -1,    -1,   133,    -1,    -1,   136,    -1,
      -1,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      -1,    -1,    -1,    -1,    57,    58,    59,    60,    -1,  2083,
      -1,    -1,    65,    66,    67,    -1,    -1,    70,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,    -1,
      -1,   179,   180,   181,   182,   183,    -1,    -1,    -1,   187,
     188,   189,   190,   191,   192,    -1,   194,   195,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   209,   210,    -1,    -1,    -1,   214,    -1,    -1,    -1,
      -1,   219,    -1,     3,     4,     5,   224,    -1,   226,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    53,    54,    55,    56,   180,   181,   182,
      -1,    61,    -1,    -1,    -1,    -1,    -1,    12,    13,   192,
      -1,   194,    72,    73,    74,    -1,    -1,    -1,    -1,    -1,
      80,    -1,    -1,    -1,    84,    -1,    -1,    87,    -1,    -1,
      90,    -1,    92,    -1,    -1,    -1,    -1,    -1,    98,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   112,    -1,    -1,    -1,    -1,    -1,    -1,   119,
     120,   121,   122,   123,    -1,    -1,   126,   127,   128,   129,
     130,    -1,    -1,   133,    -1,    -1,   136,    -1,    -1,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      -1,    -1,    -1,    -1,    99,    -1,   101,    -1,    -1,    -1,
      -1,   106,   107,   108,   109,    -1,   111,   112,   113,    -1,
      -1,    -1,   117,    -1,    -1,    -1,    -1,    -1,    -1,   179,
      -1,    -1,    -1,   183,    -1,    -1,    -1,   187,   188,   189,
     190,   191,    -1,    -1,    -1,   195,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   209,
     210,   156,   157,   158,   214,    -1,    -1,    -1,    -1,   219,
      -1,     3,     4,     5,   224,    -1,   226,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    -1,    -1,    -1,    12,    13,
      -1,    -1,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      -1,    -1,    -1,    65,    66,    67,    -1,    -1,    70,    -1,
      72,    73,    74,    -1,    -1,    -1,    -1,    -1,    80,    81,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,    -1,    -1,    -1,    -1,   218,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   227,    -1,    -1,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    -1,    -1,    -1,    -1,    99,    -1,   101,    -1,    -1,
      -1,    -1,   106,   107,   108,   109,    -1,   111,   112,   113,
      -1,    -1,    -1,   117,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,    -1,    -1,
     134,    -1,   218,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   227,    -1,    -1,    -1,    -1,    -1,   179,   180,   181,
     182,   183,   156,   157,   158,   187,   188,   189,   190,   191,
     192,    -1,   194,   195,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   209,   210,    -1,
      -1,    -1,   214,    -1,    -1,    -1,    -1,   219,    -1,     3,
       4,     5,   224,    -1,   226,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,
      54,    55,    56,    -1,    -1,    -1,    -1,    61,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,    73,
      74,    -1,    -1,    -1,    -1,    -1,    80,    -1,    -1,    -1,
      84,    -1,    -1,    87,    -1,    -1,    90,    -1,    92,    -1,
      -1,    -1,    -1,    -1,    98,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   112,    -1,
      -1,    -1,    -1,    -1,    -1,   119,   120,   121,   122,   123,
      -1,    -1,   126,   127,   128,   129,   130,    -1,    -1,   133,
      -1,    -1,   136,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,    -1,    -1,    -1,
      -1,   218,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     227,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   179,    -1,    -1,    -1,   183,
      -1,    -1,    -1,   187,   188,   189,   190,   191,    -1,    -1,
      -1,   195,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   209,   210,    -1,    -1,    -1,
     214,    -1,    -1,    -1,    -1,   219,    -1,     3,     4,     5,
     224,    -1,   226,     9,    10,    11,    -1,    -1,    14,    15,
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
      73,    74,    -1,    -1,    -1,    -1,    -1,    80,    81,    -1,
      -1,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,    -1,    -1,    -1,    -1,   218,
      -1,    -1,    -1,   179,   180,   181,   182,   183,   227,    -1,
      -1,   187,   188,   189,   190,   191,   192,    -1,   194,   195,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   209,   210,    -1,    -1,    -1,   214,    -1,
      -1,    -1,    -1,   219,    -1,    -1,    -1,    -1,   224,    -1,
     226,    -1,    -1,    -1,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,    -1,    -1,
      -1,    -1,   218,    -1,    -1,    -1,   179,   180,   181,   182,
     183,   227,    -1,    -1,   187,   188,   189,   190,   191,   192,
      -1,   194,   195,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   209,   210,    -1,    -1,
      -1,   214,    -1,    -1,    -1,    -1,   219,    -1,     3,     4,
      -1,   224,    -1,   226,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,    54,
      55,    56,    -1,    -1,    -1,    -1,    61,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,    73,    74,
      -1,    -1,    -1,    -1,    -1,    80,    -1,    -1,    -1,    84,
      -1,    -1,    87,    -1,    -1,    90,    -1,    92,    -1,    -1,
      -1,    -1,    -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   112,    -1,    -1,
      -1,    -1,    -1,    -1,   119,   120,   121,   122,   123,    -1,
      -1,   126,   127,   128,   129,   130,    -1,    -1,   133,    -1,
      -1,   136,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,    -1,    -1,    -1,    -1,
     218,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   227,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   179,    -1,    -1,    -1,   183,    -1,
      -1,    -1,   187,   188,   189,   190,   191,    -1,    -1,    -1,
     195,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   209,   210,    -1,    -1,    -1,   214,
      -1,    -1,    -1,    -1,   219,    -1,     3,     4,    -1,   224,
      -1,   226,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    53,    54,    55,    56,
      -1,    -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    72,    73,    74,    -1,    -1,
      -1,    -1,    -1,    80,    -1,    -1,    -1,    84,    -1,    -1,
      87,    -1,    -1,    90,    -1,    92,    -1,    -1,    -1,    -1,
      -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   112,    -1,    -1,    -1,    -1,
      -1,    -1,   119,   120,   121,   122,   123,    -1,    -1,   126,
     127,   128,   129,   130,    -1,    -1,   133,    -1,    -1,   136,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,    -1,    -1,    -1,    -1,   218,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   227,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   179,    -1,    -1,    -1,   183,    -1,    -1,    -1,
     187,   188,   189,   190,   191,    -1,    -1,    -1,   195,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   209,   210,    -1,    -1,    -1,   214,    -1,    -1,
      -1,    -1,   219,    -1,     3,     4,    -1,   224,    -1,   226,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    53,    54,    55,    56,    -1,    -1,
      -1,    -1,    61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    72,    73,    74,    -1,    -1,    -1,    -1,
      -1,    80,    -1,    -1,    -1,    84,    -1,    -1,    87,    -1,
      -1,    90,    -1,    92,    -1,    -1,    -1,    -1,    -1,    98,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   112,    -1,    -1,    -1,    -1,    -1,    -1,
     119,   120,   121,   122,   123,    -1,    -1,   126,   127,   128,
     129,   130,    -1,    -1,   133,    -1,    -1,   136,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,    -1,    -1,    -1,    -1,   218,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   227,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     179,    -1,    -1,    -1,   183,    -1,    -1,    -1,   187,   188,
     189,   190,   191,    -1,    -1,    -1,   195,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     209,   210,    -1,    -1,    -1,   214,    -1,    -1,    -1,    -1,
     219,    -1,     3,     4,    -1,   224,    -1,   226,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    53,    54,    55,    56,    -1,    -1,    -1,    -1,
      61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    72,    73,    74,    -1,    -1,    -1,    -1,    -1,    80,
      -1,    -1,    -1,    84,    -1,    -1,    87,    -1,    -1,    90,
      -1,    92,    -1,    -1,    -1,    -1,    -1,    98,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   112,    -1,    -1,    -1,    -1,    -1,    -1,   119,   120,
     121,   122,   123,    -1,    -1,   126,   127,   128,   129,   130,
      -1,    -1,   133,    -1,    -1,   136,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
      -1,    -1,    -1,    -1,   218,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   227,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   179,    -1,
      -1,    -1,   183,    -1,    -1,    -1,   187,   188,   189,   190,
     191,    -1,    -1,    -1,   195,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   209,   210,
      -1,    -1,    -1,   214,    -1,    -1,    -1,    -1,   219,    -1,
       3,     4,    -1,   224,    -1,   226,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      53,    54,    55,    56,    -1,    -1,    -1,    -1,    61,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,
      73,    74,    -1,    -1,    -1,    -1,    -1,    80,    -1,    -1,
      -1,    84,    -1,    -1,    87,    -1,    -1,    90,    -1,    92,
      -1,    -1,    -1,    -1,    -1,    98,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   112,
      -1,    -1,    -1,    -1,    -1,    -1,   119,   120,   121,   122,
     123,    -1,    -1,   126,   127,   128,   129,   130,    -1,    -1,
     133,    -1,    -1,   136,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,    -1,    -1,
      -1,    -1,   218,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   227,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   179,    -1,    -1,    -1,
     183,    -1,    -1,    -1,   187,   188,   189,   190,   191,    -1,
      -1,    -1,   195,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   209,   210,    -1,    -1,
      -1,   214,    -1,    -1,    -1,    -1,   219,    -1,     3,     4,
      -1,   224,    -1,   226,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,    54,
      55,    56,    -1,    -1,    -1,    -1,    61,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,    73,    74,
      -1,    -1,    -1,    -1,    -1,    80,    -1,    -1,    -1,    84,
      -1,    -1,    87,    -1,    -1,    90,    -1,    92,    -1,    -1,
      -1,    -1,    -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   112,    -1,    -1,
      -1,    -1,    -1,    -1,   119,   120,   121,   122,   123,    -1,
      -1,   126,   127,   128,   129,   130,    -1,    -1,   133,    -1,
      -1,   136,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,    -1,    -1,    -1,    -1,
     218,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   227,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   179,    -1,    -1,    -1,   183,    -1,
      -1,    -1,   187,   188,   189,   190,   191,    -1,    -1,    -1,
     195,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   209,   210,    -1,    -1,    -1,   214,
      -1,    -1,    -1,    -1,   219,    -1,     3,     4,    -1,   224,
      -1,   226,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    53,    54,    55,    56,
      -1,    -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    72,    73,    74,    -1,    -1,
      -1,    -1,    -1,    80,    -1,    -1,    -1,    84,    -1,    -1,
      87,    -1,    -1,    90,    -1,    92,    -1,    -1,    -1,    -1,
      -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   112,    -1,    -1,    -1,    -1,
      -1,    -1,   119,   120,   121,   122,   123,    -1,    -1,   126,
     127,   128,   129,   130,    -1,    -1,   133,    -1,    -1,   136,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,    -1,    -1,    -1,    -1,   218,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   227,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   179,    -1,    -1,    -1,   183,    -1,    -1,    -1,
     187,   188,   189,   190,   191,    -1,    -1,    -1,   195,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   209,   210,    -1,    -1,    -1,   214,    -1,    -1,
      -1,    -1,   219,    -1,     3,     4,    -1,   224,    -1,   226,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    53,    54,    55,    56,    -1,    -1,
      -1,    -1,    61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    72,    73,    74,    -1,    -1,    -1,    -1,
      -1,    80,    -1,    -1,    -1,    84,    -1,    -1,    87,    -1,
      -1,    90,    -1,    92,    -1,    -1,    -1,    -1,    -1,    98,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   112,    -1,    -1,    -1,    -1,    -1,    -1,
     119,   120,   121,   122,   123,    -1,    -1,   126,   127,   128,
     129,   130,    -1,    -1,   133,    -1,    -1,   136,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,    -1,    -1,    -1,    -1,   218,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   227,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     179,    -1,    -1,    -1,   183,    -1,    -1,    -1,   187,   188,
     189,   190,   191,    -1,    -1,    -1,   195,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     209,   210,    -1,    -1,    -1,   214,    -1,    -1,    -1,    -1,
     219,    -1,     3,     4,    -1,   224,    -1,   226,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    53,    54,    55,    56,    -1,    -1,    -1,    -1,
      61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    72,    73,    74,    -1,    -1,    -1,    -1,    -1,    80,
      -1,    -1,    -1,    84,    -1,    -1,    87,    -1,    -1,    90,
      -1,    92,    -1,    -1,    -1,    -1,    -1,    98,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   112,    -1,    -1,    -1,    -1,    -1,    -1,   119,   120,
     121,   122,   123,    -1,    -1,   126,   127,   128,   129,   130,
      -1,    -1,   133,    -1,    -1,   136,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
      -1,    -1,    -1,    -1,   218,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   227,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   179,    -1,
      -1,    -1,   183,    -1,    -1,    -1,   187,   188,   189,   190,
     191,    -1,    -1,    -1,   195,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   209,   210,
      -1,    -1,    -1,   214,    -1,    -1,    -1,    -1,   219,    -1,
       3,     4,    -1,   224,    -1,   226,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      53,    54,    55,    56,    -1,    -1,    -1,    -1,    61,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,
      73,    74,    -1,    -1,    -1,    -1,    -1,    80,    -1,    -1,
      -1,    84,    -1,    -1,    87,    -1,    -1,    90,    -1,    92,
      -1,    -1,    -1,    -1,    -1,    98,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   112,
      -1,    -1,    -1,    -1,    -1,    -1,   119,   120,   121,   122,
     123,    -1,    -1,   126,   127,   128,   129,   130,    -1,    -1,
     133,    -1,    -1,   136,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,    -1,    -1,
      -1,    -1,   218,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   227,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   179,    -1,    -1,    -1,
     183,    -1,    -1,    -1,   187,   188,   189,   190,   191,    -1,
      -1,    -1,   195,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   209,   210,    -1,    -1,
      -1,   214,    -1,    -1,    -1,    -1,   219,    -1,     3,     4,
      -1,   224,    -1,   226,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    -1,    -1,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,    53,    54,
      55,    56,   218,    -1,    -1,    -1,    61,    -1,    -1,    -1,
      -1,   227,    -1,    -1,    -1,     3,     4,    72,    73,    74,
      -1,     9,    10,    11,    -1,    80,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    -1,
      -1,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,    53,    54,    55,    56,   218,
      -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,   227,    -1,
      -1,    -1,    -1,    -1,    72,    73,    74,    -1,    -1,    -1,
      -1,    -1,    80,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,    -1,    -1,    -1,
      -1,   218,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     227,    -1,    -1,    -1,   179,    -1,    -1,    -1,   183,    -1,
      -1,    -1,   187,   188,   189,   190,   191,    -1,    -1,    -1,
     195,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   209,   210,    -1,    -1,    -1,   214,
      -1,    -1,    -1,    -1,   219,    -1,    -1,    -1,    -1,   224,
      -1,   226,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,    -1,    -1,    -1,    -1,
     218,   179,    -1,    -1,    -1,   183,    -1,    -1,   226,   187,
     188,   189,   190,   191,    -1,    -1,    -1,   195,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   209,   210,    -1,    -1,    -1,   214,    -1,    -1,    -1,
      -1,   219,    -1,     3,     4,     5,   224,    -1,   226,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    -1,    -1,    -1,    65,    66,    67,    -1,    -1,
      70,    -1,    72,    73,    74,    -1,    -1,    -1,    -1,    -1,
      80,    81,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,    -1,    -1,    -1,    -1,
     218,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   227,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,    -1,    -1,    -1,    -1,   218,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   227,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,    -1,    -1,    -1,    -1,   218,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   227,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   179,
     180,   181,   182,   183,    -1,    -1,    -1,   187,   188,   189,
     190,   191,   192,    -1,   194,   195,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   209,
     210,    -1,    -1,    -1,   214,     3,     4,    -1,    -1,   219,
      -1,     9,    10,    11,   224,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    53,    54,    55,    56,    -1,
      -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    72,    73,    74,    -1,    -1,    -1,
      -1,    -1,    80,    -1,    -1,    -1,    84,    -1,    -1,    87,
      -1,    -1,    90,    -1,    92,    -1,    -1,    -1,    -1,    -1,
      98,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   112,    -1,    -1,    -1,    -1,    -1,
      -1,   119,   120,   121,   122,   123,    -1,    -1,   126,   127,
     128,   129,   130,    -1,    -1,   133,    -1,    -1,   136,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,    -1,    -1,    -1,    -1,   218,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   227,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   179,    -1,    -1,    -1,   183,    -1,    -1,    -1,   187,
     188,   189,   190,   191,    -1,    -1,    -1,   195,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   209,   210,    -1,    -1,    -1,   214,     3,     4,    -1,
      -1,   219,    -1,     9,    10,    11,   224,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    -1,    -1,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,    53,    54,    55,
      56,   218,    -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,
     227,    -1,    -1,    -1,     3,     4,    72,    73,    74,    -1,
       9,    10,    11,    -1,    80,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    -1,    -1,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,    53,    54,    55,    56,   218,    -1,
      -1,    -1,    61,    -1,    -1,    -1,    -1,   227,    -1,    -1,
      -1,    -1,    -1,    72,    73,    74,    -1,    -1,    -1,    -1,
      -1,    80,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,    -1,    -1,    -1,    -1,
     218,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   227,
      -1,    -1,    -1,   179,    -1,    -1,    -1,   183,    -1,    -1,
      -1,   187,   188,   189,   190,   191,    -1,    -1,    -1,   195,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   209,   210,    -1,    -1,    -1,   214,    -1,
      -1,    -1,    -1,   219,   220,    -1,    -1,    -1,   224,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,    -1,    -1,    -1,    -1,   218,    -1,    -1,
     179,    -1,    -1,    -1,   183,    -1,   227,    -1,   187,   188,
     189,   190,   191,    -1,    -1,    -1,   195,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     209,   210,    -1,    -1,    -1,   214,    -1,    -1,    -1,    -1,
     219,     3,     4,   222,    -1,   224,    -1,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    -1,    -1,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,    53,    54,    55,    56,   218,    -1,    -1,    -1,    61,
      -1,    -1,    -1,    -1,   227,    -1,    -1,    -1,     3,     4,
      72,    73,    74,    -1,     9,    10,    11,    -1,    80,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    -1,    -1,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,    53,    54,
      55,    56,   218,    -1,    -1,    -1,    61,    -1,    -1,    -1,
      -1,   227,    -1,    -1,    -1,    -1,    -1,    72,    73,    74,
      -1,    -1,    -1,    -1,    -1,    80,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
      -1,    -1,    -1,    -1,   218,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   227,    -1,    -1,    -1,   179,    -1,    -1,
      -1,   183,    -1,    -1,    -1,   187,   188,   189,   190,   191,
      -1,    -1,    -1,   195,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   209,   210,    -1,
      -1,    -1,   214,    -1,    -1,    -1,    -1,   219,   220,    -1,
      -1,    -1,   224,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,    -1,    -1,    -1,
      -1,   218,    -1,    -1,   179,    -1,    -1,    -1,   183,    -1,
     227,    -1,   187,   188,   189,   190,   191,    -1,    -1,    -1,
     195,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   209,   210,    -1,    -1,    -1,   214,
      -1,    -1,    -1,    -1,   219,     3,     4,   222,     6,   224,
      -1,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    -1,
      -1,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,    53,    54,    55,    56,   218,
      -1,    -1,    -1,    61,    -1,    -1,    -1,   226,    -1,    -1,
      -1,    -1,    -1,    -1,    72,    73,    74,     3,     4,    -1,
       6,    -1,    80,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    -1,    -1,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,    53,    54,    55,
      56,   218,    -1,    -1,    -1,    61,    -1,    -1,    -1,   226,
      -1,    -1,    -1,    -1,    -1,    -1,    72,    73,    74,    -1,
      -1,    -1,    -1,    -1,    80,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,    -1,
      -1,    -1,    -1,   218,    -1,   220,    -1,   222,    -1,    -1,
     225,   179,    -1,    -1,    -1,   183,    -1,    -1,    -1,   187,
     188,   189,   190,   191,    -1,    -1,    -1,   195,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   209,   210,    -1,    -1,    -1,   214,    -1,    -1,    -1,
      -1,   219,    -1,    -1,    -1,    -1,   224,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,    -1,    -1,    -1,    -1,   218,    -1,   220,    -1,    -1,
      -1,    -1,   225,   179,    -1,    -1,    -1,   183,    -1,    -1,
      -1,   187,   188,   189,   190,   191,    -1,    -1,    -1,   195,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   209,   210,    -1,    -1,    -1,   214,     3,
       4,    -1,    -1,   219,    -1,     9,    10,    11,   224,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    -1,    -1,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,    53,
      54,    55,    56,   218,    -1,    -1,    -1,    61,    -1,    -1,
     225,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,    73,
      74,    -1,    -1,    -1,    -1,    -1,    80,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,    -1,    -1,    -1,    -1,   218,    -1,    -1,    -1,    -1,
      -1,    -1,   225,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,    -1,    -1,    -1,
      -1,   218,    -1,    -1,    -1,    -1,    -1,    -1,   225,    -1,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,    -1,    -1,    -1,    -1,   218,    -1,
       0,     1,    -1,    -1,     4,   225,    -1,    -1,    -1,    -1,
      -1,    -1,    12,    13,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   179,    -1,    -1,    -1,   183,
      -1,    -1,    -1,   187,   188,   189,   190,   191,    -1,    -1,
      -1,   195,    42,    43,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   209,   210,    -1,    -1,    -1,
     214,    -1,    62,    63,    64,   219,    -1,    -1,    68,    69,
     224,    71,    -1,    -1,    -1,    75,    76,    -1,    78,    79,
      -1,    -1,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    -1,    -1,    -1,    98,    99,
      -1,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,    -1,   116,   117,   118,   119,
     120,   121,   122,   123,   124,    -1,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,    -1,
      -1,    -1,   142,   143,   144,    -1,    -1,    -1,    -1,    -1,
     150,     4,    -1,    -1,    -1,   155,   156,   157,   158,    12,
      13,   161,    -1,   163,    -1,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,    -1,
      -1,    -1,    -1,    -1,   184,   185,   186,    -1,    -1,    42,
      43,    -1,    -1,   193,    -1,   195,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,
      63,    64,    -1,    -1,    -1,    68,    69,    -1,    71,    -1,
      -1,    -1,    75,    76,    -1,    78,    79,    -1,    -1,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    -1,    -1,    -1,    98,    99,    -1,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,    -1,   116,   117,   118,   119,   120,   121,   122,
     123,   124,    -1,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,    -1,    -1,    -1,   142,
     143,   144,    -1,    -1,    -1,    -1,    -1,   150,    -1,    -1,
      -1,    -1,   155,   156,   157,   158,    -1,    -1,   161,    -1,
     163,    -1,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,    -1,    -1,    -1,    -1,
      -1,   184,   185,   186,    -1,    -1,    -1,    -1,    -1,    -1,
     193,    -1,   195,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,    -1,    -1,    -1,
      -1,   218,    -1,    -1,    -1,    -1,    -1,    -1,   225,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,    -1,    -1,    -1,    -1,   218,    -1,    -1,
      -1,    -1,    -1,    -1,   225,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,    -1,
      -1,    -1,    -1,   218,    -1,    -1,    -1,    -1,    -1,    -1,
     225,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,    -1,    -1,    -1,    -1,   218,
      -1,    -1,    -1,    -1,    -1,    -1,   225,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,    -1,    -1,    -1,    -1,   218,    -1,    -1,    -1,    -1,
      -1,    -1,   225,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,    -1,    -1,    -1,
      -1,   218,    -1,    -1,    -1,    -1,    -1,    -1,   225,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,    -1,    -1,    -1,    -1,   218,    -1,    -1,
      -1,    -1,    -1,    -1,   225,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,    -1,
      -1,    -1,    -1,   218,    -1,    -1,    -1,    -1,    -1,    -1,
     225,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,    -1,    -1,    -1,    -1,   218,
      -1,    -1,    -1,    -1,    -1,    -1,   225,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,    -1,    -1,    -1,    -1,   218,    -1,    -1,    -1,    -1,
      -1,    -1,   225,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,    -1,    -1,    -1,
      -1,   218,    -1,    -1,    -1,    -1,    -1,    -1,   225,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,    -1,    -1,    -1,    -1,   218,    -1,    -1,
      -1,    -1,    -1,    -1,   225,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,    -1,
      -1,    -1,    -1,   218,    -1,    -1,    -1,    -1,    -1,    -1,
     225,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,    -1,    -1,    -1,    -1,   218,
      -1,    -1,    -1,    -1,    -1,    -1,   225,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,    -1,    -1,    -1,    -1,   218,    -1,    -1,    -1,    -1,
      -1,    -1,   225,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,    -1,    -1,    -1,
      -1,   218,    -1,    -1,    -1,    -1,    -1,    -1,   225,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,    -1,    -1,    -1,    -1,   218,    -1,    -1,
      -1,    -1,    -1,    -1,   225,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,    -1,
      -1,    -1,    -1,   218,    -1,    -1,    -1,    -1,    -1,    -1,
     225,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,    -1,    -1,    -1,    -1,   218,
      -1,    -1,    -1,    -1,    -1,    -1,   225,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,    -1,    -1,    -1,    -1,   218,    -1,    -1,    -1,    -1,
      -1,    -1,   225,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,    -1,    -1,    -1,
      -1,   218,    -1,    -1,    -1,    -1,    -1,    -1,   225,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,    -1,    -1,    -1,    -1,   218,    -1,    -1,
      -1,    -1,    -1,    -1,   225,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,    -1,
      -1,    -1,    -1,   218,    -1,    -1,    -1,    -1,    -1,    -1,
     225,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,    -1,    -1,    -1,    -1,   218,
      -1,    -1,    -1,    -1,    -1,    -1,   225,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,    -1,    -1,    -1,    -1,   218,    -1,    -1,    -1,    -1,
      -1,    -1,   225,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,    -1,    -1,    -1,
      -1,   218,    -1,    -1,    -1,    -1,    -1,    -1,   225,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,    -1,    -1,    -1,    -1,   218,    -1,    -1,
      -1,    -1,    -1,    -1,   225,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,    -1,
      -1,    -1,    -1,   218,    -1,    -1,    -1,    -1,    -1,    -1,
     225,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,    -1,    -1,    -1,    -1,   218,
      -1,    -1,    -1,    -1,    -1,    -1,   225,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,    -1,    -1,    -1,    -1,   218,    -1,    -1,    -1,    -1,
      -1,    -1,   225,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,    -1,    -1,    -1,
      -1,   218,    -1,    -1,    -1,    -1,    -1,    -1,   225,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,    -1,    -1,    -1,    -1,   218,    -1,    -1,
      -1,    -1,    -1,    -1,   225,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,    -1,
      -1,    -1,    -1,   218,    -1,    -1,    -1,    -1,    -1,    -1,
     225,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,    -1,    -1,    -1,    -1,   218,
      -1,    -1,    -1,    -1,    -1,    -1,   225,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,    -1,    -1,    -1,    -1,   218,    -1,    -1,    -1,    -1,
      -1,    -1,   225,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,    -1,    -1,    -1,
      -1,   218,    -1,    -1,    -1,    -1,    -1,    -1,   225,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,    -1,    -1,    -1,    -1,   218,    -1,    -1,
      -1,    -1,    -1,    -1,   225,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,    -1,
      -1,    -1,    -1,   218,    -1,    -1,    -1,    -1,    -1,    -1,
     225,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,    -1,    -1,    -1,    -1,   218,
      -1,    -1,    -1,    -1,    -1,    -1,   225,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,    -1,    -1,    -1,    -1,   218,    -1,    -1,    -1,    -1,
      -1,    -1,   225,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,    -1,    -1,    -1,
      -1,   218,    -1,    -1,    -1,    -1,    -1,    -1,   225,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,    -1,    -1,    -1,    -1,   218,    -1,    -1,
      -1,    -1,    -1,    -1,   225,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,    -1,
      -1,    -1,    -1,   218,    -1,    -1,    -1,    -1,    -1,    -1,
     225,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,    -1,    -1,    -1,    -1,   218,
      -1,    -1,    -1,    -1,    -1,    -1,   225,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,    -1,    -1,    -1,    -1,   218,    -1,    -1,    -1,    -1,
      -1,    -1,   225,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,    -1,    -1,    -1,
      -1,   218,    -1,    -1,    -1,    -1,    -1,    -1,   225,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,    -1,    -1,    -1,    -1,   218,    -1,    -1,
      -1,    -1,    -1,    -1,   225,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,    -1,
      -1,    -1,    -1,   218,    -1,    -1,    -1,    -1,    -1,    -1,
     225,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,    -1,    -1,    -1,    -1,   218,
      -1,    -1,    -1,    -1,    -1,    -1,   225,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,    -1,    -1,    -1,    -1,   218,    -1,    -1,    -1,    -1,
      -1,    -1,   225,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,    -1,    -1,    -1,
      -1,   218,    -1,    -1,    -1,    -1,    -1,    -1,   225,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,    -1,    -1,    -1,    -1,   218,    -1,   220,
      -1,   222,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,    -1,    -1,    -1,    -1,
     218,    -1,    -1,    -1,   222,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,    -1,
      -1,    -1,    -1,   218,    -1,    -1,    -1,   222,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,    -1,    -1,    -1,    -1,   218,    -1,    -1,    -1,
     222,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,    -1,    -1,    -1,    -1,   218,
      -1,    -1,    -1,   222,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,    -1,    -1,
      -1,    -1,   218,    -1,    -1,    -1,   222,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,    -1,    -1,    -1,    -1,   218,    -1,    -1,    -1,   222,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,    -1,    -1,    -1,    -1,   218,    -1,
      -1,    -1,   222,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,    -1,    -1,    -1,
      -1,   218,    -1,    -1,    -1,   222,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
      -1,    -1,    -1,    -1,   218,    -1,    -1,    -1,   222,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,    -1,    -1,    -1,    -1,   218,    -1,    -1,
      -1,   222,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,    -1,    -1,    -1,    -1,
     218,    -1,    -1,    -1,   222,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,    -1,
      -1,    -1,    -1,   218,    -1,    -1,    -1,   222,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,    -1,    -1,    -1,    -1,   218,    -1,    -1,    -1,
     222,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,    -1,    -1,    -1,    -1,   218,
      -1,    -1,    -1,   222,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,    -1,    -1,
      -1,    -1,   218,    -1,    -1,    -1,   222,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,    -1,    -1,    -1,    -1,   218,    -1,    -1,    -1,   222,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,    -1,    -1,    -1,    -1,   218,    -1,
      -1,    -1,   222,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,    -1,    -1,    -1,
      -1,   218,    -1,   220,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,    -1,    -1,
      -1,    -1,   218,    -1,   220,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,    -1,
      -1,    -1,    -1,   218,    -1,   220,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
      -1,    -1,    -1,    -1,   218,    -1,   220,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,    -1,    -1,    -1,    -1,   218,    -1,   220,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,    -1,    -1,    -1,    -1,   218,    -1,   220,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,    -1,    -1,    -1,    -1,   218,    -1,   220,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,    -1,    -1,    -1,    -1,   218,    -1,
     220,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,    -1,    -1,    -1,    -1,   218,
      -1,   220,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,    -1,    -1,    -1,    -1,
     218,    -1,   220,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,    -1,    -1,    -1,
      -1,   218,    -1,   220,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,    -1,    -1,
      -1,    -1,   218,    -1,   220,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,    -1,
      -1,    -1,    -1,   218,    -1,   220,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
      -1,    -1,    -1,    -1,   218,    -1,   220,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,    -1,    -1,    -1,    -1,   218,    -1,   220,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,    -1,    -1,    -1,    -1,   218,    -1,   220,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,    -1,    -1,    -1,    -1,   218,    -1,   220,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,    -1,    -1,    -1,    -1,   218,    -1,
     220,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,    -1,    -1,    -1,    -1,   218,
      -1,   220,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,    -1,    -1,    -1,    -1,
     218,    -1,   220,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,    -1,    -1,    -1,
      -1,   218,    -1,   220,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,    -1,    -1,
      -1,    -1,   218,    -1,   220,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,    -1,
      -1,    -1,    -1,   218,    -1,   220,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
      -1,    -1,    -1,    -1,   218,    -1,   220,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,    -1,    -1,    -1,    -1,   218,    -1,   220,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,    -1,    -1,    -1,    -1,   218,    -1,   220,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,    -1,    -1,    -1,    -1,   218,    -1,   220,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,    -1,    -1,    -1,    -1,   218,    -1,
     220,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,    -1,    -1,    -1,    -1,   218,
      -1,   220,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,    -1,    -1,    -1,    -1,
     218,    -1,   220,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,    -1,    -1,    -1,
      -1,   218,    -1,   220,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,    -1,    -1,
      -1,    -1,   218,    -1,   220,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,    -1,
      -1,    -1,    -1,   218,    -1,   220,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
      -1,    -1,    -1,    -1,   218,    -1,   220,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,    -1,    -1,    -1,    -1,   218,    -1,   220,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,    -1,    -1,    -1,    -1,   218,    -1,   220,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,    -1,    -1,    -1,    -1,   218,    -1,   220,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,    -1,    -1,    -1,    -1,   218,    -1,
     220,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,    -1,    -1,    -1,    -1,   218,
      -1,   220,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,    -1,    -1,    -1,    -1,
     218,    -1,   220,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,    -1,    -1,    -1,
      -1,   218,    -1,   220,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,    -1,    -1,
      -1,    -1,   218,    -1,   220,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,    -1,
      -1,    -1,    -1,   218,    -1,   220,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
      -1,    -1,    -1,    -1,   218,    -1,   220,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,    -1,    -1,    -1,    -1,   218,    -1,   220,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,    -1,    -1,    -1,    -1,   218,    -1,   220,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,    -1,    -1,    -1,    -1,   218,    -1,   220,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,    -1,    -1,    -1,    -1,   218,    -1,
     220,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,    -1,    -1,    -1,    -1,   218,
      -1,   220,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,    -1,    -1,    -1,    -1,
     218,    -1,   220,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,    -1,    -1,    -1,
      -1,   218
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,   230,   231,     6,     0,     4,    12,    13,    42,
      43,    62,    63,    64,    68,    69,    71,    75,    76,    78,
      79,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    98,    99,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   142,   143,   144,   150,   155,   156,   157,   158,
     161,   163,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   184,   185,   186,   193,
     195,   232,   234,   235,   255,   274,   275,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   302,   304,   305,   311,
     312,   313,   314,   332,   333,     3,     4,     5,     9,    10,
      11,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    65,    66,    67,    70,    72,    73,    74,    80,
      81,   172,   179,   180,   181,   182,   183,   187,   188,   189,
     190,   191,   192,   194,   209,   210,   214,   219,   221,   223,
     224,   226,   228,   253,   315,   316,   328,   329,   332,   333,
      13,    90,   219,   219,     6,   226,     6,     6,     6,     6,
     219,     6,     6,   221,   221,   219,   221,   253,   253,   219,
     226,   219,   219,     4,   219,   226,   219,   219,     4,   226,
     219,   219,   219,   219,   219,   100,    90,    90,     6,   226,
      84,    87,    90,   219,   219,    90,    90,    87,    90,    92,
      92,    84,    87,    90,    92,    87,    90,    92,    87,    90,
     219,    87,   161,   177,   178,   226,   209,   210,   219,   226,
     318,   319,   318,   226,    84,    87,    90,   226,   318,     4,
      84,    88,    94,    95,    96,    97,   108,    90,    92,    90,
      87,     4,   172,   226,   332,   333,     4,     6,    84,    87,
      90,    87,    90,     4,     4,     4,     4,     5,    37,    38,
      39,    40,    41,    84,    87,    90,    92,   112,   210,   219,
     226,   275,   286,   302,   304,   315,   321,   322,   323,   332,
     333,     4,   219,   219,   219,     4,   226,   325,   333,     4,
     219,   219,   219,     6,     6,   221,     4,   329,   333,   219,
       4,   329,     5,   226,     5,   226,     4,   315,   332,   221,
     219,   226,     6,   219,   226,   219,   221,   228,   253,     7,
     196,   197,   198,   199,   216,   217,   251,   252,     4,   219,
     221,   223,   253,   253,   253,   253,   253,   253,   253,   253,
     253,   253,   253,   253,   253,   253,   253,   253,   253,   253,
     253,   253,   253,   253,   253,   253,   253,   219,   219,   219,
     253,   253,   253,   253,   219,   253,   253,   253,   253,   253,
     253,   219,   253,   253,   253,     7,   219,   219,   219,   253,
     253,   219,   219,   221,   315,   315,   315,   220,   315,   222,
     315,     4,   161,   162,   333,     4,   275,   276,   277,   226,
     226,     6,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   218,   226,     6,   219,
     221,   252,     6,   315,     4,   328,   329,   332,   333,   328,
     315,   328,   331,   257,   262,   329,   333,   315,   210,   315,
     323,   324,   315,   315,   219,   315,   324,   315,   315,   219,
     324,   315,   315,   315,   315,   328,   321,   219,   226,   324,
     322,   322,   322,   328,   315,   219,   219,   322,   322,   322,
     219,   219,   219,   219,   219,   219,   321,   219,   321,   219,
     321,   226,   226,   315,     4,   321,   325,   226,   226,   318,
     318,   318,   315,   315,   209,   210,   226,   226,   318,   226,
     226,   226,   209,   210,   219,   277,   318,   226,   219,   226,
     219,   219,   219,   219,   219,   219,   219,   322,   322,   321,
     219,     4,   221,   221,   277,     6,     6,   226,   226,   226,
     322,   322,   221,   221,   221,   219,   221,   223,   253,   219,
     221,   253,   253,   253,   253,     5,   164,   226,     5,   164,
       5,   164,     5,   164,    84,    87,    90,    92,   226,   315,
     323,   315,   227,   324,     8,   211,     6,   219,   221,   253,
       6,   315,   315,   315,   223,   315,   226,   164,   315,   315,
     315,   315,     6,     6,   226,     6,   277,     6,   277,   219,
     221,   226,   219,   221,   328,   315,   277,   321,   321,   220,
     315,   222,   315,   226,   226,   329,   321,     6,   221,   315,
     315,     4,   315,   315,   315,   315,   315,   315,   315,   315,
     315,   315,   315,   315,   315,   315,   315,   315,   315,   315,
     315,   315,   315,   315,   331,   328,   331,   328,   328,   328,
     328,   328,   328,   328,   321,   328,   328,   315,   328,   328,
     328,   331,   328,   315,   329,   315,   328,   328,   328,   328,
     328,   333,   329,   333,     7,   199,   251,   220,     7,   199,
     251,   222,     7,   251,   252,   223,     7,   253,   227,    84,
      87,    90,    92,   274,   315,   324,   315,   315,   315,   315,
     315,   315,   315,   315,   315,   315,   315,   315,   315,   315,
     315,   236,   315,   315,     6,   219,   221,   223,   220,   225,
     219,   221,   220,   225,   225,   220,   225,   222,   225,   256,
     222,   256,   225,   225,   220,   211,   225,   227,   220,   220,
     315,   220,   227,   220,   220,   315,   227,   220,   220,   220,
     220,   220,     7,   315,   315,   227,     6,     6,     6,   220,
     220,   315,   315,     7,     7,   308,   308,   315,   268,   315,
     329,   269,   315,   329,   270,   315,   329,   271,   315,   329,
     315,     6,   315,     6,   315,     6,   324,   324,   226,   220,
       6,   226,   277,   277,   225,   225,   225,   318,   318,   276,
     276,   225,   315,   315,   315,   315,   290,   225,   277,   315,
     315,   315,   315,   315,   315,   315,   315,   315,     7,   309,
       6,     7,   315,     6,   315,   315,   227,   324,   324,   324,
       6,     6,   315,   315,   315,   315,   315,     4,   220,   222,
     226,   254,   226,   315,   323,   226,   323,   333,   315,   315,
     328,   315,    62,   315,    62,    62,    62,     5,   226,     5,
     226,     5,   226,     5,   226,   324,   220,   227,   315,   226,
     315,   323,   315,   315,   226,   254,   220,   220,   220,   161,
     225,   277,   226,     8,   220,   220,   222,   324,   227,   227,
     277,   222,   220,   134,   303,   220,   225,   227,     7,   199,
     251,   220,     7,   199,   251,   222,   315,   324,     6,     6,
     315,   220,   222,   252,   254,   254,   254,   254,   254,   254,
     254,   254,   254,   254,   254,   225,   254,   254,   254,   254,
     254,   254,   254,   225,   225,   225,   254,   225,   254,   254,
     220,   220,   225,   254,   254,   225,   254,   225,   225,   225,
     225,   254,   254,   254,   220,   254,   317,   330,     6,   225,
     225,   220,   225,   254,   225,   254,   220,   220,   222,    44,
      44,   321,     7,   251,   252,    44,    44,   321,   223,   251,
     252,   329,   315,     6,     4,     4,   226,   326,   254,   226,
     226,   226,   226,   227,   227,     8,     4,   151,   152,   153,
     154,   227,   239,   243,   246,   248,   249,   220,   222,   315,
     315,     4,     6,   206,   233,   324,   315,   315,     6,   324,
     315,     6,   328,     6,   333,     6,   328,   315,   329,     7,
     315,   323,   164,     7,     7,   220,     7,   164,     7,     7,
     220,   164,     7,     7,     7,     7,   315,   220,   227,   226,
       6,     7,   220,   220,   315,   321,     4,   307,     6,   220,
     220,   225,   220,   225,   220,   225,   220,   225,   220,   220,
     220,   227,   227,   324,   223,   277,   227,   227,   318,   315,
     315,   227,   227,   315,   318,   225,   225,   225,   115,   131,
     139,   140,   141,   145,   146,   147,   148,   300,   301,   318,
     227,   287,   220,   227,   220,   220,   220,   220,   220,   220,
     220,   315,     6,   315,   220,   222,   222,   227,   227,   227,
     222,   222,   225,   220,   222,   324,   324,   220,   324,   222,
     222,   225,   225,   254,   225,   226,   227,   226,   226,   226,
     324,   324,   324,   324,   227,     8,   324,   220,   222,   324,
       7,     7,     7,   223,   315,   227,   315,   315,     7,   223,
     227,   227,     7,     6,   315,   227,   226,   321,     6,    44,
      44,   321,   251,   252,    44,    44,   321,   251,   252,   227,
     227,   222,   252,   223,   252,   328,   315,   315,   315,   315,
     324,   328,   315,   321,   328,   328,   328,   264,   266,   315,
     328,   328,   315,   253,   253,     6,   315,     6,   253,   253,
       6,     4,   161,   162,   315,     6,     6,     6,     7,   221,
     325,   327,     6,   324,   324,   324,   324,   254,   315,   240,
     219,   219,   226,   250,     6,   252,   252,   220,   222,   206,
     328,   220,   220,   222,   220,   225,     7,   219,   221,   254,
     254,   318,    90,    92,   321,   321,     7,   321,    90,    92,
     321,   321,     7,    92,   321,   321,   321,   321,     6,     7,
       7,   324,   321,     7,     7,   115,   306,     6,     7,   251,
     315,   251,   315,   251,   315,   251,   315,     7,     7,     7,
       7,     7,   227,     4,   227,   225,   225,   225,   227,   227,
     318,   318,   318,     4,     6,   315,   226,     6,   219,     6,
     149,     6,   149,     6,   149,     6,   149,   227,   301,   225,
     300,     7,     6,     7,     7,     7,     7,     7,     7,     7,
       6,   226,     6,     6,     6,    90,     7,     6,     6,   315,
     223,   227,   227,   227,   315,   315,   315,   315,   315,   315,
     315,   227,   227,   227,   227,   315,   227,   227,   321,   321,
     321,     4,   225,     8,     8,   220,     4,     4,   225,   226,
       6,   226,   321,   227,   253,   253,     6,   315,     6,   253,
     253,     6,   315,     6,   254,     6,     4,     6,   254,   254,
     254,   254,   254,   225,   225,   254,   220,   254,   254,   225,
     225,   254,   265,   225,   254,   267,   220,   220,   254,   254,
     254,   331,   331,     6,   254,   331,   331,     7,   251,   252,
     223,     7,     6,   325,   315,   225,   227,   227,   227,   227,
     227,   251,   219,   315,   315,   320,   321,   226,   223,     6,
       6,   233,     6,   315,   226,   315,   329,   220,   222,     6,
       6,     6,   226,   226,   108,   273,   273,   321,     6,   226,
     226,     6,     6,   321,   226,     6,     6,     6,     6,     5,
     321,   227,     6,   321,   321,     4,     6,   321,   321,   321,
     321,   321,   321,   321,   321,   226,   226,     7,     6,     7,
     315,   315,   315,   226,   226,   225,   227,   225,   227,   225,
     227,   221,     6,   315,   321,   315,     6,     6,     6,     6,
     315,   318,   227,     5,   321,   226,   226,   226,   226,   226,
     226,   226,   321,   324,   226,   315,   222,     4,   254,   220,
     222,   225,   225,   225,   225,   225,   225,   225,   254,     6,
       6,   160,   315,   315,   315,     6,     6,     7,   329,   277,
     277,   225,     6,   254,   331,   331,     6,   254,   331,   331,
       6,   251,   252,   328,   315,   328,     4,     4,   176,     6,
     254,   254,     6,   254,   254,   329,   315,     6,     4,   326,
       6,   222,   325,     6,     6,     6,     6,   321,   237,   315,
     225,   225,   225,   227,   238,   315,     4,   328,   225,   321,
     329,     7,     7,   315,   315,   318,     6,     6,     6,   315,
     315,     6,   315,     5,     6,   226,     6,   164,   272,   315,
       6,     6,     6,     6,     6,     6,     4,     6,     6,   324,
     324,   315,   315,   329,   227,   220,   225,   227,   276,   276,
     318,     6,   291,   318,     6,   292,   318,     6,   293,   315,
     227,   225,   220,   227,   225,     6,     6,   320,   318,   318,
     318,   318,   318,   210,   318,     6,   227,   315,     6,     6,
     315,   315,   315,   315,   315,   315,   315,   321,   225,   227,
       8,   227,   220,   226,   315,   329,   225,   303,   303,   321,
       6,   254,   254,     6,   254,   254,   321,   220,   254,   254,
     226,   321,   329,   226,   315,   329,   329,     6,     6,     6,
       6,     6,     6,     7,     6,   223,     6,   220,   225,   315,
     315,   321,   226,   225,   227,     6,   315,   258,   261,   226,
     226,   227,   227,   227,   227,   227,     5,   320,    88,     6,
     226,   227,   227,   226,     6,     6,   226,   315,   227,   227,
     225,   226,   225,   226,   225,   226,   222,     6,   321,     7,
     226,   315,   227,   225,   225,   225,   225,   225,   225,     6,
     227,   254,   254,   225,   225,   225,   225,   225,   159,   315,
     315,   324,     6,     6,   329,   227,   227,   227,     6,     6,
       6,     6,     6,   263,   315,   323,   331,   325,   162,   241,
     315,   225,   225,   320,   315,     6,   225,   264,   266,   321,
     321,     6,     6,     6,     6,     6,     6,   227,   226,   320,
     119,   120,   125,   310,   119,   120,   310,   324,   276,   225,
     227,   315,   318,   300,   315,   318,   300,   315,   318,   300,
       6,   225,   227,   321,   277,   227,     6,   324,   318,   318,
     318,   318,   318,   315,   315,   315,   315,   315,   315,   227,
     227,   227,   220,   226,     6,   225,   227,     7,     7,   227,
       6,   226,   315,   315,   227,   315,   227,   227,   260,   259,
     226,   315,   227,   226,   318,   321,     6,   226,   318,     6,
     227,   227,   315,   227,   225,   227,   227,   225,   227,   227,
     225,   227,   321,     6,   115,   227,   288,   226,   227,   225,
     225,   225,   225,   225,   225,   225,   225,   225,   225,     6,
       6,     6,   277,   315,   329,   333,   238,   220,   225,     6,
     226,   225,   264,   264,   315,   227,     6,   318,     6,   318,
       6,     6,   227,     6,   294,   315,     6,     6,   295,   315,
       6,     6,   296,   315,     6,   227,   315,   300,   277,     6,
     324,   324,   324,   324,   318,   324,   315,   315,   315,   315,
     315,   303,     7,   219,   227,   244,   315,   320,   315,   227,
     227,   225,   225,   225,   226,   227,   226,   227,   226,   227,
       6,     6,   227,   227,   289,   227,   227,   227,   227,   225,
     227,   225,   225,   225,   225,   225,   227,   329,   220,     6,
     226,   220,   227,   227,   315,   318,   318,   300,     6,   297,
     300,     6,   298,   300,     6,   299,   300,     6,     6,     6,
       6,   324,     6,   315,   315,   315,   315,   315,     6,   242,
     328,   247,   226,     6,   227,   225,   225,   227,   226,   227,
     226,   227,   226,   227,   227,   254,   225,   225,   225,   225,
     225,   227,   226,   320,     6,   315,   315,     6,   300,     6,
     300,     6,   300,     6,   315,   315,   315,   315,   328,     6,
     245,   328,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   227,   225,   227,     6,     6,     6,     6,     6,     6,
     328,     6
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
#line 210 "Gmsh.y"
    { yyerrok; return 1; ;}
    break;

  case 6:
#line 221 "Gmsh.y"
    { return 1; ;}
    break;

  case 7:
#line 222 "Gmsh.y"
    { return 1; ;}
    break;

  case 8:
#line 223 "Gmsh.y"
    { return 1; ;}
    break;

  case 9:
#line 224 "Gmsh.y"
    { return 1; ;}
    break;

  case 10:
#line 225 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 11:
#line 226 "Gmsh.y"
    { return 1; ;}
    break;

  case 12:
#line 227 "Gmsh.y"
    { return 1; ;}
    break;

  case 13:
#line 228 "Gmsh.y"
    { return 1; ;}
    break;

  case 14:
#line 229 "Gmsh.y"
    { return 1; ;}
    break;

  case 15:
#line 230 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 16:
#line 231 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 17:
#line 232 "Gmsh.y"
    { return 1; ;}
    break;

  case 18:
#line 233 "Gmsh.y"
    { return 1; ;}
    break;

  case 19:
#line 234 "Gmsh.y"
    { return 1; ;}
    break;

  case 20:
#line 235 "Gmsh.y"
    { return 1; ;}
    break;

  case 21:
#line 236 "Gmsh.y"
    { return 1; ;}
    break;

  case 22:
#line 237 "Gmsh.y"
    { return 1; ;}
    break;

  case 23:
#line 238 "Gmsh.y"
    { return 1; ;}
    break;

  case 24:
#line 239 "Gmsh.y"
    { return 1; ;}
    break;

  case 25:
#line 244 "Gmsh.y"
    {
      (yyval.c) = (char*)"w";
    ;}
    break;

  case 26:
#line 248 "Gmsh.y"
    {
      (yyval.c) = (char*)"a";
    ;}
    break;

  case 27:
#line 255 "Gmsh.y"
    {
      Msg::Direct((yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 28:
#line 260 "Gmsh.y"
    {
      Msg::Error((yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 29:
#line 265 "Gmsh.y"
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
#line 279 "Gmsh.y"
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
#line 292 "Gmsh.y"
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
#line 305 "Gmsh.y"
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
#line 333 "Gmsh.y"
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
#line 347 "Gmsh.y"
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
#line 360 "Gmsh.y"
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
#line 373 "Gmsh.y"
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
#line 391 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData = new PViewDataList();
#endif
    ;}
    break;

  case 43:
#line 405 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(1) - (1)].d)); ;}
    break;

  case 44:
#line 407 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(3) - (3)].d)); ;}
    break;

  case 45:
#line 412 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(1) - (1)].d)); ;}
    break;

  case 46:
#line 414 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(3) - (3)].d)); ;}
    break;

  case 47:
#line 419 "Gmsh.y"
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
#line 523 "Gmsh.y"
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
#line 533 "Gmsh.y"
    {
#if defined(HAVE_POST)
      if(ViewValueList) (*ViewNumList)++;
#endif
    ;}
    break;

  case 50:
#line 542 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[(1) - (1)].c)[i]);
#endif
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 51:
#line 549 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[(3) - (3)].c)[i]);
#endif
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 52:
#line 559 "Gmsh.y"
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
#line 568 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->NbT2++;
#endif
    ;}
    break;

  case 54:
#line 577 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[(1) - (1)].c)[i]);
#endif
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 55:
#line 584 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[(3) - (3)].c)[i]);
#endif
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 56:
#line 594 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->T3D.push_back((yyvsp[(3) - (10)].d)); ViewData->T3D.push_back((yyvsp[(5) - (10)].d));
      ViewData->T3D.push_back((yyvsp[(7) - (10)].d)); ViewData->T3D.push_back((yyvsp[(9) - (10)].d));
      ViewData->T3D.push_back(ViewData->T3C.size());
#endif
    ;}
    break;

  case 57:
#line 602 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->NbT3++;
#endif
    ;}
    break;

  case 58:
#line 612 "Gmsh.y"
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
#line 631 "Gmsh.y"
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
#line 650 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewValueList = &ViewData->Time;
#endif
    ;}
    break;

  case 61:
#line 656 "Gmsh.y"
    {
    ;}
    break;

  case 62:
#line 663 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 63:
#line 664 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 64:
#line 665 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 65:
#line 666 "Gmsh.y"
    { (yyval.i) = 3; ;}
    break;

  case 66:
#line 667 "Gmsh.y"
    { (yyval.i) = 4; ;}
    break;

  case 67:
#line 671 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 68:
#line 672 "Gmsh.y"
    { (yyval.i) = -1; ;}
    break;

  case 69:
#line 678 "Gmsh.y"
    { (yyval.c) = (char*)"("; ;}
    break;

  case 70:
#line 678 "Gmsh.y"
    { (yyval.c) = (char*)"["; ;}
    break;

  case 71:
#line 679 "Gmsh.y"
    { (yyval.c) = (char*)")"; ;}
    break;

  case 72:
#line 679 "Gmsh.y"
    { (yyval.c) = (char*)"]"; ;}
    break;

  case 75:
#line 688 "Gmsh.y"
    {
      Msg::SetOnelabNumber((yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].d));
      Free((yyvsp[(3) - (7)].c));
    ;}
    break;

  case 76:
#line 693 "Gmsh.y"
    {
      Msg::SetOnelabString((yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].c));
      Free((yyvsp[(3) - (7)].c));
      Free((yyvsp[(5) - (7)].c));
    ;}
    break;

  case 77:
#line 699 "Gmsh.y"
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
#line 761 "Gmsh.y"
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
#line 778 "Gmsh.y"
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
#line 807 "Gmsh.y"
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
#line 836 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    ;}
    break;

  case 82:
#line 841 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    ;}
    break;

  case 83:
#line 846 "Gmsh.y"
    {
      incrementVariable((yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].i));
      Free((yyvsp[(1) - (6)].c));
    ;}
    break;

  case 84:
#line 851 "Gmsh.y"
    {
      incrementVariable((yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].i));
      Free((yyvsp[(1) - (6)].c));
    ;}
    break;

  case 85:
#line 856 "Gmsh.y"
    {
      assignVariables((yyvsp[(1) - (9)].c), (yyvsp[(4) - (9)].l), (yyvsp[(7) - (9)].i), (yyvsp[(8) - (9)].l));
      Free((yyvsp[(1) - (9)].c));
      List_Delete((yyvsp[(4) - (9)].l));
      List_Delete((yyvsp[(8) - (9)].l));
    ;}
    break;

  case 86:
#line 863 "Gmsh.y"
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
#line 902 "Gmsh.y"
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
#line 931 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    ;}
    break;

  case 90:
#line 936 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    ;}
    break;

  case 91:
#line 941 "Gmsh.y"
    {
      incrementVariable((yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].i));
      Free((yyvsp[(1) - (6)].c));
    ;}
    break;

  case 92:
#line 946 "Gmsh.y"
    {
      incrementVariable((yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].i));
      Free((yyvsp[(1) - (6)].c));
    ;}
    break;

  case 93:
#line 954 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[(1) - (4)].c)] = std::vector<std::string>(1, (yyvsp[(3) - (4)].c));
      Free((yyvsp[(1) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 94:
#line 963 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[(1) - (8)].c)] = std::vector<std::string>();
      Free((yyvsp[(1) - (8)].c));
    ;}
    break;

  case 95:
#line 969 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[(1) - (8)].c)] = std::vector<std::string>();
      Free((yyvsp[(1) - (8)].c));
    ;}
    break;

  case 96:
#line 975 "Gmsh.y"
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
#line 988 "Gmsh.y"
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
#line 1001 "Gmsh.y"
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
#line 1016 "Gmsh.y"
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
#line 1033 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[(1) - (8)].c)] = std::vector<std::string>();
      Free((yyvsp[(1) - (8)].c));
    ;}
    break;

  case 101:
#line 1039 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[(1) - (8)].c)] = std::vector<std::string>();
      Free((yyvsp[(1) - (8)].c));
    ;}
    break;

  case 102:
#line 1045 "Gmsh.y"
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
#line 1058 "Gmsh.y"
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
#line 1071 "Gmsh.y"
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
#line 1086 "Gmsh.y"
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
#line 1103 "Gmsh.y"
    {
      std::string tmp((yyvsp[(5) - (6)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (6)].c), 0, (yyvsp[(3) - (6)].c), tmp);
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 107:
#line 1109 "Gmsh.y"
    {
      std::string tmp((yyvsp[(8) - (9)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (9)].c), (int)(yyvsp[(3) - (9)].d), (yyvsp[(6) - (9)].c), tmp);
      Free((yyvsp[(1) - (9)].c)); Free((yyvsp[(6) - (9)].c)); Free((yyvsp[(8) - (9)].c));
    ;}
    break;

  case 108:
#line 1118 "Gmsh.y"
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
#line 1136 "Gmsh.y"
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
#line 1154 "Gmsh.y"
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
#line 1163 "Gmsh.y"
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
#line 1175 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (8)].c), 0, (yyvsp[(5) - (8)].c), (yyvsp[(7) - (8)].u));
      Free((yyvsp[(1) - (8)].c)); Free((yyvsp[(5) - (8)].c));
    ;}
    break;

  case 113:
#line 1180 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (11)].c), (int)(yyvsp[(3) - (11)].d), (yyvsp[(8) - (11)].c), (yyvsp[(10) - (11)].u));
      Free((yyvsp[(1) - (11)].c)); Free((yyvsp[(8) - (11)].c));
    ;}
    break;

  case 114:
#line 1188 "Gmsh.y"
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
#line 1208 "Gmsh.y"
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
#line 1231 "Gmsh.y"
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
#line 1242 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      if(!GModel::current()->getFields()->newField((int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c)))
	yymsg(0, "Cannot create field %i of type '%s'", (int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c));
#endif
      Free((yyvsp[(6) - (7)].c));
    ;}
    break;

  case 118:
#line 1250 "Gmsh.y"
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
#line 1272 "Gmsh.y"
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
#line 1295 "Gmsh.y"
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
#line 1333 "Gmsh.y"
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
#line 1354 "Gmsh.y"
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
#line 1366 "Gmsh.y"
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
#line 1384 "Gmsh.y"
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
#line 1393 "Gmsh.y"
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
#line 1402 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 130:
#line 1404 "Gmsh.y"
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
#line 1422 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 132:
#line 1424 "Gmsh.y"
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
#line 1440 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 134:
#line 1442 "Gmsh.y"
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
#line 1458 "Gmsh.y"
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
#line 1467 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 137:
#line 1469 "Gmsh.y"
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
#line 1483 "Gmsh.y"
    {
      std::string name((yyvsp[(3) - (3)].c));
      Msg::UndefineOnelabParameter(name);
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 140:
#line 1491 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(doubleXstring));
      doubleXstring v = {(yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].c)};
      List_Add((yyval.l), &v);
    ;}
    break;

  case 141:
#line 1497 "Gmsh.y"
    {
      doubleXstring v = {(yyvsp[(3) - (5)].d), (yyvsp[(5) - (5)].c)};
      List_Add((yyval.l), &v);
    ;}
    break;

  case 142:
#line 1502 "Gmsh.y"
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
#line 1533 "Gmsh.y"
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
#line 1544 "Gmsh.y"
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
#line 1559 "Gmsh.y"
    {
      std::string key((yyvsp[(2) - (3)].c));
      std::string val((yyvsp[(3) - (3)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(2) - (3)].c));
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 150:
#line 1575 "Gmsh.y"
    {
      std::string key((yyvsp[(2) - (3)].c));
      double val = (yyvsp[(3) - (3)].d);
      floatOptions[key].push_back(val);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 151:
#line 1583 "Gmsh.y"
    {
      std::string key((yyvsp[(2) - (3)].c));
      std::string val((yyvsp[(3) - (3)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(2) - (3)].c));
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 152:
#line 1592 "Gmsh.y"
    {
      std::string key("Macro");
      std::string val((yyvsp[(3) - (3)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 153:
#line 1600 "Gmsh.y"
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
#line 1618 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    ;}
    break;

  case 155:
#line 1622 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[(1) - (1)].c)), 0, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 156:
#line 1628 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (3)].c)), 0, (yyvsp[(3) - (3)].d));
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 157:
#line 1636 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    ;}
    break;

  case 158:
#line 1640 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[(1) - (1)].c)), 1, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 159:
#line 1646 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (3)].c)), 1, (yyvsp[(3) - (3)].d));
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 160:
#line 1654 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    ;}
    break;

  case 161:
#line 1658 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[(1) - (1)].c)), 2, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 162:
#line 1664 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (3)].c)), 2, (yyvsp[(3) - (3)].d));
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 163:
#line 1672 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    ;}
    break;

  case 164:
#line 1676 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[(1) - (1)].c)), 3, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 165:
#line 1682 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (3)].c)), 3, (yyvsp[(3) - (3)].d));
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 166:
#line 1690 "Gmsh.y"
    {
      (yyval.l) = 0;
    ;}
    break;

  case 167:
#line 1694 "Gmsh.y"
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
#line 1706 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = 0.;
    ;}
    break;

  case 169:
#line 1710 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 170:
#line 1718 "Gmsh.y"
    {
      // FIXME: when changing to OpenCASCADE, get maxTag for all dimensions
      // and add that info in OCC_Internals - same in the other direction
      factory = (yyvsp[(3) - (5)].c);
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 171:
#line 1728 "Gmsh.y"
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
#line 1756 "Gmsh.y"
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
#line 1799 "Gmsh.y"
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
#line 1822 "Gmsh.y"
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
#line 1851 "Gmsh.y"
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
#line 1872 "Gmsh.y"
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
#line 1890 "Gmsh.y"
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
#line 1930 "Gmsh.y"
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
#line 1960 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      if(FindCurve(num)){
	yymsg(0, "Curve %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt((yyvsp[(6) - (7)].l));
	Curve *c = Create_Curve(num, MSH_SEGM_BSPLN, 2, temp, NULL,
				-1, -1, 0., 1.);
	Tree_Add(GModel::current()->getGEOInternals()->Curves, &c);
	CreateReversedCurve(c);
	List_Delete(temp);
      }
      List_Delete((yyvsp[(6) - (7)].l));
      (yyval.s).Type = MSH_SEGM_BSPLN;
      (yyval.s).Num = num;
    ;}
    break;

  case 180:
#line 1978 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      if(FindCurve(num)){
	yymsg(0, "Curve %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt((yyvsp[(6) - (7)].l));
	Curve *c = Create_Curve(num, MSH_SEGM_BEZIER, 2, temp, NULL,
				-1, -1, 0., 1.);
	Tree_Add(GModel::current()->getGEOInternals()->Curves, &c);
	CreateReversedCurve(c);
	List_Delete(temp);
      }
      List_Delete((yyvsp[(6) - (7)].l));
      (yyval.s).Type = MSH_SEGM_BEZIER;
      (yyval.s).Num = num;
    ;}
    break;

  case 181:
#line 1997 "Gmsh.y"
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
#line 2023 "Gmsh.y"
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
#line 2052 "Gmsh.y"
    {
     GModel::current()->getGEOInternals()->addCompoundMesh ( 1 , (yyvsp[(3) - (4)].l) );
   ;}
    break;

  case 184:
#line 2057 "Gmsh.y"
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
#line 2075 "Gmsh.y"
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
#line 2121 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].d);
      if(FindSurface(num)){
	yymsg(0, "Surface %d already exists", num);
      }
      else{
	Surface *s = Create_Surface(num, MSH_SURF_PLAN);
	List_T *temp = ListOfDouble2ListOfInt((yyvsp[(7) - (8)].l));
	setSurfaceGeneratrices(s, temp);
	List_Delete(temp);
	End_Surface(s);
	Tree_Add(GModel::current()->getGEOInternals()->Surfaces, &s);
      }
      List_Delete((yyvsp[(7) - (8)].l));
      (yyval.s).Type = MSH_SURF_PLAN;
      (yyval.s).Num = num;
    ;}
    break;

  case 187:
#line 2139 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (9)].d), type = 0;
      if(FindSurface(num)){
	yymsg(0, "Surface %d already exists", num);
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
      List_Delete((yyvsp[(7) - (9)].l));
      (yyval.s).Type = type;
      (yyval.s).Num = num;
    ;}
    break;

  case 188:
#line 2178 "Gmsh.y"
    {
      myGmshSurface = 0;
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 189:
#line 2184 "Gmsh.y"
    {
      myGmshSurface = gmshSurface::getSurface((int)(yyvsp[(3) - (4)].d));
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 190:
#line 2190 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (10)].d);
      myGmshSurface = gmshParametricSurface::NewParametricSurface(num, (yyvsp[(7) - (10)].c), (yyvsp[(8) - (10)].c), (yyvsp[(9) - (10)].c));
      (yyval.s).Type = 0;
      (yyval.s).Num = num;
    ;}
    break;

  case 191:
#line 2197 "Gmsh.y"
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
#line 2238 "Gmsh.y"
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
#line 2264 "Gmsh.y"
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
#line 2288 "Gmsh.y"
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

  case 195:
#line 2313 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].d);
      if(FindSurfaceLoop(num)){
	yymsg(0, "Surface loop %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt((yyvsp[(7) - (8)].l));
	SurfaceLoop *l = Create_SurfaceLoop(num, temp);
	Tree_Add(GModel::current()->getGEOInternals()->SurfaceLoops, &l);
	List_Delete(temp);
      }
      List_Delete((yyvsp[(7) - (8)].l));
      Free((yyvsp[(2) - (8)].c));
      (yyval.s).Type = MSH_SURF_LOOP;
      (yyval.s).Num = num;
    ;}
    break;

  case 196:
#line 2330 "Gmsh.y"
    {
      GModel::current()->getGEOInternals()->addCompoundMesh ( 2 , (yyvsp[(3) - (4)].l) );
    ;}
    break;

  case 197:
#line 2334 "Gmsh.y"
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

  case 198:
#line 2354 "Gmsh.y"
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

  case 199:
#line 2387 "Gmsh.y"
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

  case 200:
#line 2434 "Gmsh.y"
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

  case 201:
#line 2452 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      if(FindVolume(num)){
	yymsg(0, "Volume %d already exists", num);
      }
      else{
	Volume *v = Create_Volume(num, MSH_VOLUME);
	List_T *temp = ListOfDouble2ListOfInt((yyvsp[(6) - (7)].l));
	setVolumeSurfaces(v, temp);
	List_Delete(temp);
	Tree_Add(GModel::current()->getGEOInternals()->Volumes, &v);
      }
      List_Delete((yyvsp[(6) - (7)].l));
      (yyval.s).Type = MSH_VOLUME;
      (yyval.s).Num = num;
    ;}
    break;

  case 202:
#line 2469 "Gmsh.y"
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

  case 203:
#line 2487 "Gmsh.y"
    {
      GModel::current()->getGEOInternals()->addCompoundMesh(3, (yyvsp[(3) - (4)].l));
    ;}
    break;

  case 204:
#line 2491 "Gmsh.y"
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

  case 205:
#line 2507 "Gmsh.y"
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

  case 206:
#line 2555 "Gmsh.y"
    {
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        Msg::Error("TODO OCC Translate");
      }
      else{
        TranslateShapes((yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], (yyvsp[(4) - (5)].l));
      }
      (yyval.l) = (yyvsp[(4) - (5)].l);
    ;}
    break;

  case 207:
#line 2565 "Gmsh.y"
    {
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        Msg::Error("TODO OCC Rotate");
      }
      else{
        RotateShapes((yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(7) - (11)].d), (yyvsp[(10) - (11)].l));
      }
      (yyval.l) = (yyvsp[(10) - (11)].l);
    ;}
    break;

  case 208:
#line 2575 "Gmsh.y"
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

  case 209:
#line 2585 "Gmsh.y"
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

  case 210:
#line 2595 "Gmsh.y"
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

  case 211:
#line 2605 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
      if(!strcmp((yyvsp[(1) - (4)].c), "Duplicata")){
        for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
          Shape TheShape;
          List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
          if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
            Msg::Error("TODO OCC Copy");
          }
          else{
            CopyShape(TheShape.Type, TheShape.Num, &TheShape.Num);
          }
          List_Add((yyval.l), &TheShape);
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

  case 212:
#line 2652 "Gmsh.y"
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

  case 213:
#line 2663 "Gmsh.y"
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

  case 214:
#line 2678 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 215:
#line 2679 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 216:
#line 2684 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    ;}
    break;

  case 217:
#line 2688 "Gmsh.y"
    {
      List_Add((yyval.l), &(yyvsp[(2) - (2)].s));
    ;}
    break;

  case 218:
#line 2692 "Gmsh.y"
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

  case 219:
#line 2721 "Gmsh.y"
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

  case 220:
#line 2750 "Gmsh.y"
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

  case 221:
#line 2779 "Gmsh.y"
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

  case 222:
#line 2813 "Gmsh.y"
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

  case 223:
#line 2835 "Gmsh.y"
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

  case 224:
#line 2862 "Gmsh.y"
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

  case 225:
#line 2884 "Gmsh.y"
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

  case 226:
#line 2906 "Gmsh.y"
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

  case 227:
#line 2928 "Gmsh.y"
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

  case 228:
#line 2984 "Gmsh.y"
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

  case 229:
#line 3008 "Gmsh.y"
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

  case 230:
#line 3033 "Gmsh.y"
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

  case 231:
#line 3058 "Gmsh.y"
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

  case 232:
#line 3171 "Gmsh.y"
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

  case 233:
#line 3190 "Gmsh.y"
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

  case 234:
#line 3233 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
        if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
          Msg::Error("TODO OCC Delete");
        }
        else{
          DeleteShape(TheShape.Type, TheShape.Num);
        }
      }
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 235:
#line 3247 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      GModel::current()->getFields()->deleteField((int)(yyvsp[(4) - (6)].d));
#endif
    ;}
    break;

  case 236:
#line 3253 "Gmsh.y"
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

  case 237:
#line 3268 "Gmsh.y"
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

  case 238:
#line 3296 "Gmsh.y"
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

  case 239:
#line 3313 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(4) - (5)].l), i, &TheShape);
	ColorShape(TheShape.Type, TheShape.Num, (yyvsp[(2) - (5)].u), false);
      }
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 240:
#line 3322 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(5) - (6)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(5) - (6)].l), i, &TheShape);
	ColorShape(TheShape.Type, TheShape.Num, (yyvsp[(3) - (6)].u), true);
      }
      List_Delete((yyvsp[(5) - (6)].l));
    ;}
    break;

  case 241:
#line 3336 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(4) - (5)].l), i, &TheShape);
	SetPartition(TheShape.Type, TheShape.Num, (yyvsp[(2) - (5)].d));
      }
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 242:
#line 3350 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 1, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 243:
#line 3356 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 0, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 244:
#line 3362 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 1, false);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 245:
#line 3371 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(4) - (5)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 1, true);
      }
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 246:
#line 3380 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 0, false);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 247:
#line 3389 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(4) - (5)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 0, true);
      }
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 248:
#line 3403 "Gmsh.y"
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

  case 249:
#line 3465 "Gmsh.y"
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

  case 250:
#line 3483 "Gmsh.y"
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

  case 251:
#line 3500 "Gmsh.y"
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

  case 252:
#line 3515 "Gmsh.y"
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

  case 253:
#line 3544 "Gmsh.y"
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

  case 254:
#line 3556 "Gmsh.y"
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

  case 255:
#line 3580 "Gmsh.y"
    {
      Msg::Exit(0);
    ;}
    break;

  case 256:
#line 3584 "Gmsh.y"
    {
      gmsh_yyerrorstate = 999; // this will be checked when yyparse returns
      YYABORT;
    ;}
    break;

  case 257:
#line 3589 "Gmsh.y"
    {
      // FIXME: this is a hack to force a transfer from the old DB to
      // the new DB. This will become unnecessary if/when we fill the
      // GModel directly during parsing.
      GModel::current()->importGEOInternals();
      GModel::current()->importOCCInternals();
    ;}
    break;

  case 258:
#line 3597 "Gmsh.y"
    {
      new GModel();
      GModel::current(GModel::list.size() - 1);
    ;}
    break;

  case 259:
#line 3602 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 0;
      GModel::current()->importGEOInternals();
      SetBoundingBox();
    ;}
    break;

  case 260:
#line 3608 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 1;
      SetBoundingBox((yyvsp[(3) - (15)].d), (yyvsp[(5) - (15)].d), (yyvsp[(7) - (15)].d), (yyvsp[(9) - (15)].d), (yyvsp[(11) - (15)].d), (yyvsp[(13) - (15)].d));
    ;}
    break;

  case 261:
#line 3613 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
      drawContext::global()->draw();
#endif
    ;}
    break;

  case 262:
#line 3619 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
     CTX::instance()->mesh.changed = ENT_ALL;
     for(unsigned int index = 0; index < PView::list.size(); index++)
       PView::list[index]->setChanged(true);
#endif
    ;}
    break;

  case 263:
#line 3627 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh();
    ;}
    break;

  case 264:
#line 3631 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh(1);
    ;}
    break;

  case 265:
#line 3635 "Gmsh.y"
    {
      GModel::current()->importGEOInternals();
      GModel::current()->refineMesh(CTX::instance()->mesh.secondOrderLinear);
    ;}
    break;

  case 266:
#line 3641 "Gmsh.y"
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

  case 267:
#line 3700 "Gmsh.y"
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

  case 268:
#line 3716 "Gmsh.y"
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

  case 269:
#line 3733 "Gmsh.y"
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

  case 270:
#line 3750 "Gmsh.y"
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

  case 271:
#line 3772 "Gmsh.y"
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

  case 272:
#line 3794 "Gmsh.y"
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

  case 273:
#line 3829 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip_until(NULL, "Return");
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 274:
#line 3837 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip_until(NULL, "Return");
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 275:
#line 3845 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    ;}
    break;

  case 276:
#line 3851 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 277:
#line 3858 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 278:
#line 3865 "Gmsh.y"
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

  case 279:
#line 3885 "Gmsh.y"
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

  case 280:
#line 3911 "Gmsh.y"
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

  case 281:
#line 3923 "Gmsh.y"
    {
      ImbricatedTest--;
      if(ImbricatedTest < 0)
        yymsg(1, "Orphan EndIf");
    ;}
    break;

  case 282:
#line 3935 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (5)].l),
		    (yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    NULL, (yyval.l));
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 283:
#line 3943 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[(10) - (11)].l),
		    0., 0., 0., (yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(7) - (11)].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[(10) - (11)].l));
    ;}
    break;

  case 284:
#line 3951 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (13)].l),
		    (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].v)[0], (yyvsp[(7) - (13)].v)[1], (yyvsp[(7) - (13)].v)[2], (yyvsp[(9) - (13)].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[(12) - (13)].l));
    ;}
    break;

  case 285:
#line 3959 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 286:
#line 3965 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (7)].l),
		    (yyvsp[(2) - (7)].v)[0], (yyvsp[(2) - (7)].v)[1], (yyvsp[(2) - (7)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(4) - (7)].l));
    ;}
    break;

  case 287:
#line 3973 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 288:
#line 3979 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[(10) - (13)].l),
		    0., 0., 0., (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(10) - (13)].l));
    ;}
    break;

  case 289:
#line 3987 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 290:
#line 3993 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (15)].l),
		    (yyvsp[(3) - (15)].v)[0], (yyvsp[(3) - (15)].v)[1], (yyvsp[(3) - (15)].v)[2], (yyvsp[(5) - (15)].v)[0], (yyvsp[(5) - (15)].v)[1], (yyvsp[(5) - (15)].v)[2], (yyvsp[(7) - (15)].v)[0], (yyvsp[(7) - (15)].v)[1], (yyvsp[(7) - (15)].v)[2], (yyvsp[(9) - (15)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(12) - (15)].l));
    ;}
    break;

  case 291:
#line 4001 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 292:
#line 4007 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(BOUNDARY_LAYER, (yyvsp[(3) - (6)].l), 0., 0., 0., 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(3) - (6)].l));
    ;}
    break;

  case 293:
#line 4015 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 294:
#line 4022 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 295:
#line 4029 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 296:
#line 4036 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 297:
#line 4043 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 298:
#line 4050 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 299:
#line 4057 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 300:
#line 4064 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 301:
#line 4071 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 302:
#line 4078 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 303:
#line 4084 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 304:
#line 4091 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 305:
#line 4097 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 306:
#line 4104 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 307:
#line 4110 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 308:
#line 4117 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 309:
#line 4123 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 310:
#line 4130 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 311:
#line 4136 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 312:
#line 4143 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 313:
#line 4149 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 314:
#line 4156 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 315:
#line 4162 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 316:
#line 4169 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 317:
#line 4175 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 318:
#line 4182 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 319:
#line 4188 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 320:
#line 4199 "Gmsh.y"
    {
    ;}
    break;

  case 321:
#line 4202 "Gmsh.y"
    {
    ;}
    break;

  case 322:
#line 4208 "Gmsh.y"
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

  case 323:
#line 4220 "Gmsh.y"
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

  case 324:
#line 4240 "Gmsh.y"
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

  case 325:
#line 4264 "Gmsh.y"
    {
      extr.mesh.ScaleLast = true;
    ;}
    break;

  case 326:
#line 4268 "Gmsh.y"
    {
      extr.mesh.Recombine = true;
    ;}
    break;

  case 327:
#line 4272 "Gmsh.y"
    {
      extr.mesh.Recombine = (yyvsp[(2) - (3)].d) ? true : false;
    ;}
    break;

  case 328:
#line 4276 "Gmsh.y"
    {
      yymsg(0, "Keyword 'QuadTriSngl' deprecated. Use 'QuadTriNoNewVerts' instead.");
    ;}
    break;

  case 329:
#line 4280 "Gmsh.y"
    {
      yymsg(0, "Keyword 'QuadTriSngl' deprecated. Use 'QuadTriNoNewVerts' instead.");
    ;}
    break;

  case 330:
#line 4284 "Gmsh.y"
    {
      yymsg(0, "Method 'QuadTriDbl' deprecated. Use 'QuadTriAddVerts' instead, "
            "which has no requirement for the number of extrusion layers and meshes "
            "with body-centered vertices.");
    ;}
    break;

  case 331:
#line 4290 "Gmsh.y"
    {
      yymsg(0, "Method 'QuadTriDbl' deprecated. Use 'QuadTriAddVerts' instead, "
            "which has no requirement for the number of extrusion layers and meshes "
            "with body-centered vertices.");
    ;}
    break;

  case 332:
#line 4296 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1;
    ;}
    break;

  case 333:
#line 4300 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1_RECOMB;
    ;}
    break;

  case 334:
#line 4304 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1;
    ;}
    break;

  case 335:
#line 4308 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1_RECOMB;
    ;}
    break;

  case 336:
#line 4312 "Gmsh.y"
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

  case 337:
#line 4331 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (6)].c), "Index"))
        extr.mesh.BoundaryLayerIndex = (yyvsp[(4) - (6)].d);
      else if(!strcmp((yyvsp[(2) - (6)].c), "View"))
        extr.mesh.ViewIndex = (yyvsp[(4) - (6)].d);
      Free((yyvsp[(2) - (6)].c));
    ;}
    break;

  case 338:
#line 4343 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Union; ;}
    break;

  case 339:
#line 4344 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Intersection; ;}
    break;

  case 340:
#line 4345 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Difference; ;}
    break;

  case 341:
#line 4346 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Section; ;}
    break;

  case 342:
#line 4347 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Fragments; ;}
    break;

  case 343:
#line 4351 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 344:
#line 4352 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 345:
#line 4353 "Gmsh.y"
    { (yyval.i) = (yyvsp[(2) - (3)].d); ;}
    break;

  case 346:
#line 4358 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        std::vector<int> shape[4], tool[4];
        for(int i = 0; i < List_Nbr((yyvsp[(3) - (9)].l)); i++){
          Shape s; List_Read((yyvsp[(3) - (9)].l), i, &s); shape[3].push_back(s.Num);
        }
        for(int i = 0; i < List_Nbr((yyvsp[(7) - (9)].l)); i++){
          Shape s; List_Read((yyvsp[(7) - (9)].l), i, &s); tool[3].push_back(s.Num);
        }
        std::vector<int> out[4];
        GModel::current()->getOCCInternals()->applyBooleanOperator
          (-1, (OCC_Internals::BooleanOperator)(yyvsp[(1) - (9)].i), shape, tool, out, (yyvsp[(4) - (9)].i), (yyvsp[(8) - (9)].i));
        for(unsigned int i = 0; i < out[3].size(); i++){
          Shape s;
          s.Num = out[3][i];
          s.Type = MSH_VOLUME;
          List_Add((yyval.l), &s);
        }
      }
      List_Delete((yyvsp[(3) - (9)].l));
      List_Delete((yyvsp[(7) - (9)].l));
    ;}
    break;

  case 347:
#line 4382 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        std::vector<int> out[4];
        GModel::current()->getOCCInternals()->importShape((yyvsp[(3) - (4)].c), out);
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

  case 348:
#line 4408 "Gmsh.y"
    {
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        std::vector<int> shape[4], tool[4];
        for(int i = 0; i < List_Nbr((yyvsp[(7) - (14)].l)); i++){
          Shape s; List_Read((yyvsp[(7) - (14)].l), i, &s); shape[3].push_back(s.Num);
        }
        for(int i = 0; i < List_Nbr((yyvsp[(11) - (14)].l)); i++){
          Shape s; List_Read((yyvsp[(11) - (14)].l), i, &s); tool[3].push_back(s.Num);
        }
        std::vector<int> out[4];
        GModel::current()->getOCCInternals()->applyBooleanOperator
          ((int)(yyvsp[(3) - (14)].d), (OCC_Internals::BooleanOperator)(yyvsp[(1) - (14)].i), shape, tool, out, (yyvsp[(8) - (14)].i), (yyvsp[(12) - (14)].i));
      }
      List_Delete((yyvsp[(7) - (14)].l));
      List_Delete((yyvsp[(11) - (14)].l));
    ;}
    break;

  case 349:
#line 4428 "Gmsh.y"
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    ;}
    break;

  case 350:
#line 4432 "Gmsh.y"
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

  case 351:
#line 4447 "Gmsh.y"
    {
      (yyval.i) = -1; // left
    ;}
    break;

  case 352:
#line 4451 "Gmsh.y"
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

  case 353:
#line 4467 "Gmsh.y"
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   ;}
    break;

  case 354:
#line 4471 "Gmsh.y"
    {
     (yyval.l) = (yyvsp[(2) - (2)].l);
   ;}
    break;

  case 355:
#line 4476 "Gmsh.y"
    {
      (yyval.i) = 45;
    ;}
    break;

  case 356:
#line 4480 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(2) - (2)].d);
    ;}
    break;

  case 357:
#line 4486 "Gmsh.y"
    {
      (yyval.l) = List_Create(1, 1, sizeof(double));
    ;}
    break;

  case 358:
#line 4490 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
    ;}
    break;

  case 359:
#line 4497 "Gmsh.y"
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

  case 360:
#line 4553 "Gmsh.y"
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

  case 361:
#line 4623 "Gmsh.y"
    {
      yymsg(1, "Elliptic Surface is deprecated: use Transfinite instead (with smoothing)");
      List_Delete((yyvsp[(7) - (8)].l));
    ;}
    break;

  case 362:
#line 4628 "Gmsh.y"
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

  case 363:
#line 4695 "Gmsh.y"
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

  case 364:
#line 4731 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (8)].l)); i++){
	double d;
	List_Read((yyvsp[(4) - (8)].l), i, &d);
	CTX::instance()->mesh.algo2d_per_face[(int)d] = (int)(yyvsp[(7) - (8)].d);
      }
    ;}
    break;

  case 365:
#line 4739 "Gmsh.y"
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

  case 366:
#line 4782 "Gmsh.y"
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

  case 367:
#line 4821 "Gmsh.y"
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

  case 368:
#line 4842 "Gmsh.y"
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

  case 369:
#line 4874 "Gmsh.y"
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

  case 370:
#line 4901 "Gmsh.y"
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

  case 371:
#line 4927 "Gmsh.y"
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

  case 372:
#line 4953 "Gmsh.y"
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

  case 373:
#line 4979 "Gmsh.y"
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

  case 374:
#line 5005 "Gmsh.y"
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

  case 375:
#line 5026 "Gmsh.y"
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

  case 376:
#line 5054 "Gmsh.y"
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

  case 377:
#line 5082 "Gmsh.y"
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

  case 378:
#line 5110 "Gmsh.y"
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

  case 379:
#line 5138 "Gmsh.y"
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

  case 380:
#line 5166 "Gmsh.y"
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

  case 381:
#line 5205 "Gmsh.y"
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

  case 382:
#line 5244 "Gmsh.y"
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

  case 383:
#line 5265 "Gmsh.y"
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

  case 384:
#line 5286 "Gmsh.y"
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

  case 385:
#line 5313 "Gmsh.y"
    {
      ReplaceAllDuplicates();
    ;}
    break;

  case 386:
#line 5317 "Gmsh.y"
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

  case 387:
#line 5327 "Gmsh.y"
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

  case 388:
#line 5361 "Gmsh.y"
    { (yyval.c) = (char*)"Homology"; ;}
    break;

  case 389:
#line 5362 "Gmsh.y"
    { (yyval.c) = (char*)"Cohomology"; ;}
    break;

  case 390:
#line 5363 "Gmsh.y"
    { (yyval.c) = (char*)"Betti"; ;}
    break;

  case 391:
#line 5368 "Gmsh.y"
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest((yyvsp[(1) - (2)].c), domain, subdomain, dim);
    ;}
    break;

  case 392:
#line 5374 "Gmsh.y"
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

  case 393:
#line 5386 "Gmsh.y"
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

  case 394:
#line 5404 "Gmsh.y"
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

  case 395:
#line 5431 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d);           ;}
    break;

  case 396:
#line 5432 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (3)].d);           ;}
    break;

  case 397:
#line 5433 "Gmsh.y"
    { (yyval.d) = -(yyvsp[(2) - (2)].d);          ;}
    break;

  case 398:
#line 5434 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);           ;}
    break;

  case 399:
#line 5435 "Gmsh.y"
    { (yyval.d) = !(yyvsp[(2) - (2)].d);          ;}
    break;

  case 400:
#line 5436 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) - (yyvsp[(3) - (3)].d);      ;}
    break;

  case 401:
#line 5437 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) + (yyvsp[(3) - (3)].d);      ;}
    break;

  case 402:
#line 5438 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) * (yyvsp[(3) - (3)].d);      ;}
    break;

  case 403:
#line 5440 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (3)].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));
      else
	(yyval.d) = (yyvsp[(1) - (3)].d) / (yyvsp[(3) - (3)].d);
    ;}
    break;

  case 404:
#line 5446 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) % (int)(yyvsp[(3) - (3)].d);  ;}
    break;

  case 405:
#line 5447 "Gmsh.y"
    { (yyval.d) = pow((yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));  ;}
    break;

  case 406:
#line 5448 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d);      ;}
    break;

  case 407:
#line 5449 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) > (yyvsp[(3) - (3)].d);      ;}
    break;

  case 408:
#line 5450 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) <= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 409:
#line 5451 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) >= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 410:
#line 5452 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) == (yyvsp[(3) - (3)].d);     ;}
    break;

  case 411:
#line 5453 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) != (yyvsp[(3) - (3)].d);     ;}
    break;

  case 412:
#line 5454 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) && (yyvsp[(3) - (3)].d);     ;}
    break;

  case 413:
#line 5455 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) || (yyvsp[(3) - (3)].d);     ;}
    break;

  case 414:
#line 5456 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (5)].d) ? (yyvsp[(3) - (5)].d) : (yyvsp[(5) - (5)].d); ;}
    break;

  case 415:
#line 5457 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 416:
#line 5458 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 417:
#line 5459 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 418:
#line 5460 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 419:
#line 5461 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 420:
#line 5462 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 421:
#line 5463 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 422:
#line 5464 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 423:
#line 5465 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 424:
#line 5466 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 425:
#line 5467 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 426:
#line 5468 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 427:
#line 5469 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 428:
#line 5470 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 429:
#line 5471 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 430:
#line 5472 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 431:
#line 5473 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 432:
#line 5474 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d) + 0.5); ;}
    break;

  case 433:
#line 5475 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 434:
#line 5476 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 435:
#line 5477 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 436:
#line 5478 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 437:
#line 5487 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 438:
#line 5488 "Gmsh.y"
    { (yyval.d) = 3.141592653589793; ;}
    break;

  case 439:
#line 5489 "Gmsh.y"
    { (yyval.d) = (double)ImbricatedTest; ;}
    break;

  case 440:
#line 5490 "Gmsh.y"
    { (yyval.d) = Msg::GetCommRank(); ;}
    break;

  case 441:
#line 5491 "Gmsh.y"
    { (yyval.d) = Msg::GetCommSize(); ;}
    break;

  case 442:
#line 5492 "Gmsh.y"
    { (yyval.d) = GetGmshMajorVersion(); ;}
    break;

  case 443:
#line 5493 "Gmsh.y"
    { (yyval.d) = GetGmshMinorVersion(); ;}
    break;

  case 444:
#line 5494 "Gmsh.y"
    { (yyval.d) = GetGmshPatchVersion(); ;}
    break;

  case 445:
#line 5495 "Gmsh.y"
    { (yyval.d) = Cpu(); ;}
    break;

  case 446:
#line 5496 "Gmsh.y"
    { (yyval.d) = GetMemoryUsage()/1024./1024.; ;}
    break;

  case 447:
#line 5497 "Gmsh.y"
    { (yyval.d) = TotalRam(); ;}
    break;

  case 448:
#line 5502 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 449:
#line 5504 "Gmsh.y"
    {
      std::vector<double> val(1, (yyvsp[(3) - (6)].d));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.d) = val[0];
    ;}
    break;

  case 450:
#line 5510 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 451:
#line 5515 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 452:
#line 5520 "Gmsh.y"
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

  case 453:
#line 5537 "Gmsh.y"
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

  case 454:
#line 5555 "Gmsh.y"
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

  case 455:
#line 5573 "Gmsh.y"
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
#line 5591 "Gmsh.y"
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
#line 5609 "Gmsh.y"
    {
      (yyval.d) = gmsh_yysymbols.count((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 458:
#line 5614 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.d) = !StatFile(tmp);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 459:
#line 5620 "Gmsh.y"
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

  case 460:
#line 5635 "Gmsh.y"
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

  case 461:
#line 5654 "Gmsh.y"
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

  case 462:
#line 5674 "Gmsh.y"
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

  case 463:
#line 5694 "Gmsh.y"
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
#line 5714 "Gmsh.y"
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
#line 5737 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), (yyval.d));
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 466:
#line 5742 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), (yyval.d));
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 467:
#line 5747 "Gmsh.y"
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

  case 468:
#line 5757 "Gmsh.y"
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

  case 469:
#line 5767 "Gmsh.y"
    {
      (yyval.d) = Msg::GetValue((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 470:
#line 5772 "Gmsh.y"
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

  case 471:
#line 5783 "Gmsh.y"
    {
      std::string s((yyvsp[(3) - (6)].c)), substr((yyvsp[(5) - (6)].c));
      if(s.find(substr) != std::string::npos)
        (yyval.d) = 1.;
      else
        (yyval.d) = 0.;
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 472:
#line 5792 "Gmsh.y"
    {
      (yyval.d) = strlen((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 473:
#line 5797 "Gmsh.y"
    {
      (yyval.d) = strcmp((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 474:
#line 5802 "Gmsh.y"
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

  case 475:
#line 5829 "Gmsh.y"
    {
      memcpy((yyval.v), (yyvsp[(1) - (1)].v), 5*sizeof(double));
    ;}
    break;

  case 476:
#line 5833 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 477:
#line 5837 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 478:
#line 5841 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] - (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 479:
#line 5845 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] + (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 480:
#line 5852 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (11)].d);  (yyval.v)[1] = (yyvsp[(4) - (11)].d);  (yyval.v)[2] = (yyvsp[(6) - (11)].d);  (yyval.v)[3] = (yyvsp[(8) - (11)].d); (yyval.v)[4] = (yyvsp[(10) - (11)].d);
    ;}
    break;

  case 481:
#line 5856 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (9)].d);  (yyval.v)[1] = (yyvsp[(4) - (9)].d);  (yyval.v)[2] = (yyvsp[(6) - (9)].d);  (yyval.v)[3] = (yyvsp[(8) - (9)].d); (yyval.v)[4] = 1.0;
    ;}
    break;

  case 482:
#line 5860 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 483:
#line 5864 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 484:
#line 5871 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].l)));
    ;}
    break;

  case 485:
#line 5876 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].l)));
    ;}
    break;

  case 486:
#line 5883 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 487:
#line 5888 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 488:
#line 5892 "Gmsh.y"
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    ;}
    break;

  case 489:
#line 5897 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 490:
#line 5901 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 491:
#line 5909 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (5)].d);
      }
    ;}
    break;

  case 492:
#line 5920 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 493:
#line 5924 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(1) - (1)].c), "*") || !strcmp((yyvsp[(1) - (1)].c), "all"))
        (yyval.l) = 0;
      else{
        yyerror("Unknown special string for list replacement");
        (yyval.l) = List_Create(2, 1, sizeof(double));
      }
    ;}
    break;

  case 494:
#line 5936 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 495:
#line 5944 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (3)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (3)].d);
      }
    ;}
    break;

  case 496:
#line 5952 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      for(double d = (yyvsp[(1) - (3)].d); ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d <= (yyvsp[(3) - (3)].d)) : (d >= (yyvsp[(3) - (3)].d));
          ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d += 1.) : (d -= 1.))
	List_Add((yyval.l), &d);
    ;}
    break;

  case 497:
#line 5959 "Gmsh.y"
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

  case 498:
#line 5969 "Gmsh.y"
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

  case 499:
#line 5998 "Gmsh.y"
    {
      (yyval.l) = GetAllElementaryEntityNumbers(0);
    ;}
    break;

  case 500:
#line 6002 "Gmsh.y"
    {
      (yyval.l) = GetAllElementaryEntityNumbers(1);
    ;}
    break;

  case 501:
#line 6006 "Gmsh.y"
    {
      (yyval.l) = GetAllElementaryEntityNumbers(2);
    ;}
    break;

  case 502:
#line 6010 "Gmsh.y"
    {
      (yyval.l) = GetAllElementaryEntityNumbers(3);
    ;}
    break;

  case 503:
#line 6014 "Gmsh.y"
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(0);
    ;}
    break;

  case 504:
#line 6018 "Gmsh.y"
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(1);
    ;}
    break;

  case 505:
#line 6022 "Gmsh.y"
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(2);
    ;}
    break;

  case 506:
#line 6026 "Gmsh.y"
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(3);
    ;}
    break;

  case 507:
#line 6030 "Gmsh.y"
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

  case 508:
#line 6059 "Gmsh.y"
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

  case 509:
#line 6088 "Gmsh.y"
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

  case 510:
#line 6117 "Gmsh.y"
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

  case 511:
#line 6147 "Gmsh.y"
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

  case 512:
#line 6160 "Gmsh.y"
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

  case 513:
#line 6173 "Gmsh.y"
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

  case 514:
#line 6186 "Gmsh.y"
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

  case 515:
#line 6198 "Gmsh.y"
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

  case 516:
#line 6208 "Gmsh.y"
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

  case 517:
#line 6218 "Gmsh.y"
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
#line 6228 "Gmsh.y"
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

  case 519:
#line 6240 "Gmsh.y"
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

  case 520:
#line 6253 "Gmsh.y"
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

  case 521:
#line 6265 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 522:
#line 6269 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 523:
#line 6273 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (6)].l);
    ;}
    break;

  case 524:
#line 6277 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (6)].l);
    ;}
    break;

  case 525:
#line 6281 "Gmsh.y"
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

  case 526:
#line 6299 "Gmsh.y"
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

  case 527:
#line 6317 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = (yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1);
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 528:
#line 6325 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = pow(10,(yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1));
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 529:
#line 6333 "Gmsh.y"
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

  case 530:
#line 6362 "Gmsh.y"
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

  case 531:
#line 6375 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 532:
#line 6380 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 533:
#line 6384 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].d)));
    ;}
    break;

  case 534:
#line 6388 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (3)].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 535:
#line 6400 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (9)].d), (int)(yyvsp[(4) - (9)].d), (int)(yyvsp[(6) - (9)].d), (int)(yyvsp[(8) - (9)].d));
    ;}
    break;

  case 536:
#line 6404 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (7)].d), (int)(yyvsp[(4) - (7)].d), (int)(yyvsp[(6) - (7)].d), 255);
    ;}
    break;

  case 537:
#line 6416 "Gmsh.y"
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

  case 538:
#line 6433 "Gmsh.y"
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(5) - (5)].c), val);
      (yyval.u) = val;
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(5) - (5)].c));
    ;}
    break;

  case 539:
#line 6443 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 540:
#line 6447 "Gmsh.y"
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

  case 541:
#line 6462 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].u)));
    ;}
    break;

  case 542:
#line 6467 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].u)));
    ;}
    break;

  case 543:
#line 6474 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 544:
#line 6478 "Gmsh.y"
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

  case 545:
#line 6491 "Gmsh.y"
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

  case 546:
#line 6505 "Gmsh.y"
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

  case 547:
#line 6519 "Gmsh.y"
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
#line 6533 "Gmsh.y"
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
#line 6547 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 550:
#line 6555 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 551:
#line 6566 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 552:
#line 6570 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 553:
#line 6574 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    ;}
    break;

  case 554:
#line 6582 "Gmsh.y"
    {
      std::string exe = Msg::GetExecutableName();
      (yyval.c) = (char *)Malloc(exe.size() + 1);
      strcpy((yyval.c), exe.c_str());
    ;}
    break;

  case 555:
#line 6588 "Gmsh.y"
    {
      std::string action = Msg::GetOnelabAction();
      (yyval.c) = (char *)Malloc(action.size() + 1);
      strcpy((yyval.c), action.c_str());
    ;}
    break;

  case 556:
#line 6594 "Gmsh.y"
    {
      const char *env = GetEnvironmentVar((yyvsp[(3) - (4)].c));
      if(!env) env = "";
      (yyval.c) = (char *)Malloc((sizeof(env) + 1) * sizeof(char));
      strcpy((yyval.c), env);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 557:
#line 6602 "Gmsh.y"
    {
      std::string s = Msg::GetString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 558:
#line 6610 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (4)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 559:
#line 6617 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 560:
#line 6625 "Gmsh.y"
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

  case 561:
#line 6640 "Gmsh.y"
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

  case 562:
#line 6654 "Gmsh.y"
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

  case 563:
#line 6668 "Gmsh.y"
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

  case 564:
#line 6680 "Gmsh.y"
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

  case 565:
#line 6696 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = toupper((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 566:
#line 6705 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = tolower((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 567:
#line 6714 "Gmsh.y"
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

  case 568:
#line 6724 "Gmsh.y"
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

  case 569:
#line 6735 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (8)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (8)].d), (int)(yyvsp[(7) - (8)].d));
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (8)].c));
    ;}
    break;

  case 570:
#line 6743 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (6)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (6)].d), std::string::npos);
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 571:
#line 6751 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 572:
#line 6755 "Gmsh.y"
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

  case 573:
#line 6774 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 574:
#line 6781 "Gmsh.y"
    {
      std::string tmp = SplitFileName(GetAbsolutePath(gmsh_yyname))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
    ;}
    break;

  case 575:
#line 6787 "Gmsh.y"
    {
      std::string tmp = SplitFileName((yyvsp[(3) - (4)].c))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 576:
#line 6794 "Gmsh.y"
    {
      std::string tmp = GetAbsolutePath((yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 577:
#line 6801 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 578:
#line 6803 "Gmsh.y"
    {
      std::string val((yyvsp[(3) - (6)].c));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.c) = (char*)Malloc((val.size() + 1) * sizeof(char));
      strcpy((yyval.c), val.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 579:
#line 6814 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].c)));
    ;}
    break;

  case 580:
#line 6819 "Gmsh.y"
    { List_Add((yyval.l), &((yyvsp[(3) - (3)].c))); ;}
    break;

  case 581:
#line 6825 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 582:
#line 6834 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char)) ;
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)) ; strcat((yyval.c), tmpstr) ;
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 583:
#line 6847 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 584:
#line 6850 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 585:
#line 6854 "Gmsh.y"
    { (yyval.c) = (yyvsp[(3) - (4)].c); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 13936 "Gmsh.tab.cpp"
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


#line 6857 "Gmsh.y"


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

