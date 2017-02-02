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
     tCharacteristic = 353,
     tLength = 354,
     tParametric = 355,
     tElliptic = 356,
     tRefineMesh = 357,
     tAdaptMesh = 358,
     tRelocateMesh = 359,
     tSetFactory = 360,
     tThruSections = 361,
     tPlane = 362,
     tRuled = 363,
     tTransfinite = 364,
     tComplex = 365,
     tPhysical = 366,
     tCompound = 367,
     tPeriodic = 368,
     tUsing = 369,
     tPlugin = 370,
     tDegenerated = 371,
     tRecursive = 372,
     tRotate = 373,
     tTranslate = 374,
     tSymmetry = 375,
     tDilate = 376,
     tExtrude = 377,
     tLevelset = 378,
     tAffine = 379,
     tBooleanUnion = 380,
     tBooleanIntersection = 381,
     tBooleanSubtraction = 382,
     tRecombine = 383,
     tSmoother = 384,
     tSplit = 385,
     tDelete = 386,
     tCoherence = 387,
     tIntersect = 388,
     tMeshAlgorithm = 389,
     tReverse = 390,
     tLayers = 391,
     tScaleLast = 392,
     tHole = 393,
     tAlias = 394,
     tAliasWithOptions = 395,
     tCopyOptions = 396,
     tQuadTriAddVerts = 397,
     tQuadTriNoNewVerts = 398,
     tQuadTriSngl = 399,
     tQuadTriDbl = 400,
     tRecombLaterals = 401,
     tTransfQuadTri = 402,
     tText2D = 403,
     tText3D = 404,
     tInterpolationScheme = 405,
     tTime = 406,
     tCombine = 407,
     tBSpline = 408,
     tBezier = 409,
     tNurbs = 410,
     tNurbsOrder = 411,
     tNurbsKnots = 412,
     tColor = 413,
     tColorTable = 414,
     tFor = 415,
     tIn = 416,
     tEndFor = 417,
     tIf = 418,
     tElseIf = 419,
     tElse = 420,
     tEndIf = 421,
     tExit = 422,
     tAbort = 423,
     tField = 424,
     tReturn = 425,
     tCall = 426,
     tSlide = 427,
     tMacro = 428,
     tShow = 429,
     tHide = 430,
     tGetValue = 431,
     tGetStringValue = 432,
     tGetEnv = 433,
     tGetString = 434,
     tGetNumber = 435,
     tHomology = 436,
     tCohomology = 437,
     tBetti = 438,
     tExists = 439,
     tFileExists = 440,
     tGMSH_MAJOR_VERSION = 441,
     tGMSH_MINOR_VERSION = 442,
     tGMSH_PATCH_VERSION = 443,
     tGmshExecutableName = 444,
     tSetPartition = 445,
     tNameToString = 446,
     tStringToName = 447,
     tAFFECTDIVIDE = 448,
     tAFFECTTIMES = 449,
     tAFFECTMINUS = 450,
     tAFFECTPLUS = 451,
     tOR = 452,
     tAND = 453,
     tNOTEQUAL = 454,
     tEQUAL = 455,
     tGREATEROREQUAL = 456,
     tLESSOREQUAL = 457,
     UNARYPREC = 458,
     tMINUSMINUS = 459,
     tPLUSPLUS = 460
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
#define tCharacteristic 353
#define tLength 354
#define tParametric 355
#define tElliptic 356
#define tRefineMesh 357
#define tAdaptMesh 358
#define tRelocateMesh 359
#define tSetFactory 360
#define tThruSections 361
#define tPlane 362
#define tRuled 363
#define tTransfinite 364
#define tComplex 365
#define tPhysical 366
#define tCompound 367
#define tPeriodic 368
#define tUsing 369
#define tPlugin 370
#define tDegenerated 371
#define tRecursive 372
#define tRotate 373
#define tTranslate 374
#define tSymmetry 375
#define tDilate 376
#define tExtrude 377
#define tLevelset 378
#define tAffine 379
#define tBooleanUnion 380
#define tBooleanIntersection 381
#define tBooleanSubtraction 382
#define tRecombine 383
#define tSmoother 384
#define tSplit 385
#define tDelete 386
#define tCoherence 387
#define tIntersect 388
#define tMeshAlgorithm 389
#define tReverse 390
#define tLayers 391
#define tScaleLast 392
#define tHole 393
#define tAlias 394
#define tAliasWithOptions 395
#define tCopyOptions 396
#define tQuadTriAddVerts 397
#define tQuadTriNoNewVerts 398
#define tQuadTriSngl 399
#define tQuadTriDbl 400
#define tRecombLaterals 401
#define tTransfQuadTri 402
#define tText2D 403
#define tText3D 404
#define tInterpolationScheme 405
#define tTime 406
#define tCombine 407
#define tBSpline 408
#define tBezier 409
#define tNurbs 410
#define tNurbsOrder 411
#define tNurbsKnots 412
#define tColor 413
#define tColorTable 414
#define tFor 415
#define tIn 416
#define tEndFor 417
#define tIf 418
#define tElseIf 419
#define tElse 420
#define tEndIf 421
#define tExit 422
#define tAbort 423
#define tField 424
#define tReturn 425
#define tCall 426
#define tSlide 427
#define tMacro 428
#define tShow 429
#define tHide 430
#define tGetValue 431
#define tGetStringValue 432
#define tGetEnv 433
#define tGetString 434
#define tGetNumber 435
#define tHomology 436
#define tCohomology 437
#define tBetti 438
#define tExists 439
#define tFileExists 440
#define tGMSH_MAJOR_VERSION 441
#define tGMSH_MINOR_VERSION 442
#define tGMSH_PATCH_VERSION 443
#define tGmshExecutableName 444
#define tSetPartition 445
#define tNameToString 446
#define tStringToName 447
#define tAFFECTDIVIDE 448
#define tAFFECTTIMES 449
#define tAFFECTMINUS 450
#define tAFFECTPLUS 451
#define tOR 452
#define tAND 453
#define tNOTEQUAL 454
#define tEQUAL 455
#define tGREATEROREQUAL 456
#define tLESSOREQUAL 457
#define UNARYPREC 458
#define tMINUSMINUS 459
#define tPLUSPLUS 460




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
#line 640 "Gmsh.tab.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 653 "Gmsh.tab.cpp"

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
#define YYLAST   12955

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  226
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  105
/* YYNRULES -- Number of rules.  */
#define YYNRULES  582
/* YYNRULES -- Number of states.  */
#define YYNSTATES  2148

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   460

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   211,     2,   221,     2,   210,     2,     2,
     216,   217,   208,   206,   222,   207,   220,   209,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     202,     2,   203,   197,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   218,     2,   219,   215,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   223,     2,   224,   225,     2,     2,     2,
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
     195,   196,   198,   199,   200,   201,   204,   205,   212,   213,
     214
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
    1114,  1123,  1131,  1141,  1146,  1155,  1164,  1170,  1182,  1188,
    1198,  1208,  1213,  1223,  1233,  1235,  1237,  1238,  1241,  1248,
    1255,  1262,  1269,  1278,  1289,  1304,  1321,  1334,  1349,  1364,
    1379,  1394,  1403,  1412,  1419,  1424,  1431,  1438,  1442,  1447,
    1453,  1460,  1466,  1470,  1474,  1479,  1485,  1490,  1496,  1500,
    1506,  1514,  1522,  1526,  1534,  1538,  1541,  1544,  1547,  1550,
    1553,  1569,  1572,  1575,  1578,  1581,  1584,  1601,  1613,  1620,
    1629,  1638,  1649,  1651,  1654,  1657,  1659,  1663,  1667,  1672,
    1677,  1679,  1681,  1687,  1699,  1713,  1714,  1722,  1723,  1737,
    1738,  1754,  1755,  1762,  1771,  1780,  1789,  1802,  1815,  1828,
    1843,  1858,  1873,  1874,  1887,  1888,  1901,  1902,  1915,  1916,
    1933,  1934,  1951,  1952,  1969,  1970,  1989,  1990,  2009,  2010,
    2029,  2031,  2034,  2040,  2048,  2058,  2061,  2064,  2068,  2071,
    2075,  2078,  2082,  2085,  2089,  2092,  2096,  2106,  2113,  2115,
    2117,  2119,  2120,  2123,  2127,  2137,  2152,  2153,  2157,  2158,
    2160,  2161,  2164,  2165,  2168,  2169,  2172,  2180,  2187,  2196,
    2202,  2206,  2215,  2221,  2226,  2233,  2245,  2257,  2276,  2295,
    2308,  2321,  2334,  2345,  2356,  2367,  2378,  2389,  2394,  2399,
    2404,  2409,  2414,  2417,  2421,  2428,  2430,  2432,  2434,  2437,
    2443,  2451,  2462,  2464,  2468,  2471,  2474,  2477,  2481,  2485,
    2489,  2493,  2497,  2501,  2505,  2509,  2513,  2517,  2521,  2525,
    2529,  2533,  2539,  2544,  2549,  2554,  2559,  2564,  2569,  2574,
    2579,  2584,  2589,  2596,  2601,  2606,  2611,  2616,  2621,  2626,
    2631,  2638,  2645,  2652,  2657,  2659,  2661,  2663,  2665,  2667,
    2669,  2671,  2673,  2675,  2677,  2679,  2680,  2687,  2692,  2699,
    2701,  2706,  2711,  2716,  2721,  2726,  2731,  2736,  2739,  2745,
    2751,  2757,  2763,  2767,  2774,  2779,  2787,  2794,  2801,  2808,
    2813,  2820,  2825,  2827,  2830,  2833,  2837,  2841,  2853,  2863,
    2871,  2879,  2881,  2885,  2887,  2889,  2892,  2896,  2901,  2907,
    2909,  2911,  2914,  2918,  2922,  2928,  2933,  2936,  2939,  2942,
    2945,  2949,  2953,  2957,  2961,  2967,  2973,  2979,  2985,  3002,
    3019,  3036,  3053,  3055,  3057,  3059,  3063,  3067,  3072,  3077,
    3082,  3089,  3096,  3103,  3110,  3119,  3128,  3133,  3148,  3150,
    3152,  3156,  3160,  3170,  3178,  3180,  3186,  3190,  3197,  3199,
    3203,  3205,  3207,  3212,  3217,  3222,  3227,  3231,  3238,  3240,
    3245,  3247,  3249,  3251,  3256,  3263,  3268,  3275,  3280,  3285,
    3290,  3299,  3304,  3309,  3314,  3319,  3328,  3337,  3344,  3349,
    3356,  3361,  3363,  3368,  3373,  3374,  3381,  3383,  3387,  3393,
    3399,  3401,  3403
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     227,     0,    -1,   228,    -1,     1,     6,    -1,    -1,   228,
     229,    -1,   232,    -1,   231,    -1,   252,    -1,   271,    -1,
     272,    -1,   276,    -1,   277,    -1,   278,    -1,   279,    -1,
     283,    -1,   301,    -1,   302,    -1,   308,    -1,   309,    -1,
     282,    -1,   281,    -1,   280,    -1,   275,    -1,   311,    -1,
     203,    -1,   203,   203,    -1,    42,   216,   325,   217,     6,
      -1,    43,   216,   325,   217,     6,    -1,    42,   216,   325,
     217,   230,   325,     6,    -1,    42,   216,   325,   222,   321,
     217,     6,    -1,    43,   216,   325,   222,   321,   217,     6,
      -1,    42,   216,   325,   222,   321,   217,   230,   325,     6,
      -1,     4,   325,   223,   233,   224,     6,    -1,   139,     4,
     218,   312,   219,     6,    -1,   140,     4,   218,   312,   219,
       6,    -1,   141,     4,   218,   312,   222,   312,   219,     6,
      -1,    -1,   233,   236,    -1,   233,   240,    -1,   233,   243,
      -1,   233,   245,    -1,   233,   246,    -1,   312,    -1,   234,
     222,   312,    -1,   312,    -1,   235,   222,   312,    -1,    -1,
      -1,     4,   237,   216,   234,   217,   238,   223,   235,   224,
       6,    -1,   325,    -1,   239,   222,   325,    -1,    -1,   148,
     216,   312,   222,   312,   222,   312,   217,   241,   223,   239,
     224,     6,    -1,   325,    -1,   242,   222,   325,    -1,    -1,
     149,   216,   312,   222,   312,   222,   312,   222,   312,   217,
     244,   223,   242,   224,     6,    -1,   150,   223,   317,   224,
     223,   317,   224,     6,    -1,   150,   223,   317,   224,   223,
     317,   224,   223,   317,   224,   223,   317,   224,     6,    -1,
      -1,   151,   247,   223,   235,   224,     6,    -1,     7,    -1,
     196,    -1,   195,    -1,   194,    -1,   193,    -1,   214,    -1,
     213,    -1,   216,    -1,   218,    -1,   217,    -1,   219,    -1,
      78,   218,   254,   219,     6,    -1,    79,   218,   259,   219,
       6,    -1,    82,   250,   326,   222,   312,   251,     6,    -1,
      83,   250,   330,   222,   326,   251,     6,    -1,   330,   248,
     318,     6,    -1,   330,   249,     6,    -1,     4,   218,   219,
     248,   318,     6,    -1,   329,   218,   219,   248,   318,     6,
      -1,     4,   218,   312,   219,   248,   312,     6,    -1,   329,
     218,   312,   219,   248,   312,     6,    -1,     4,   218,   312,
     219,   249,     6,    -1,   329,   218,   312,   219,   249,     6,
      -1,     4,   250,   223,   321,   224,   251,   248,   318,     6,
      -1,   329,   250,   223,   321,   224,   251,   248,   318,     6,
      -1,     4,   216,   217,   248,   318,     6,    -1,   329,   216,
     217,   248,   318,     6,    -1,     4,   216,   312,   217,   248,
     312,     6,    -1,   329,   216,   312,   217,   248,   312,     6,
      -1,     4,   216,   312,   217,   249,     6,    -1,   329,   216,
     312,   217,   249,     6,    -1,   330,     7,   326,     6,    -1,
       4,   218,   219,     7,    44,   250,   251,     6,    -1,   329,
     218,   219,     7,    44,   250,   251,     6,    -1,     4,   218,
     219,     7,    44,   250,   328,   251,     6,    -1,   329,   218,
     219,     7,    44,   250,   328,   251,     6,    -1,     4,   218,
     219,   196,    44,   250,   328,   251,     6,    -1,   329,   218,
     219,   196,    44,   250,   328,   251,     6,    -1,     4,   216,
     217,     7,    44,   250,   251,     6,    -1,   329,   216,   217,
       7,    44,   250,   251,     6,    -1,     4,   216,   217,     7,
      44,   250,   328,   251,     6,    -1,   329,   216,   217,     7,
      44,   250,   328,   251,     6,    -1,     4,   216,   217,   196,
      44,   250,   328,   251,     6,    -1,   329,   216,   217,   196,
      44,   250,   328,   251,     6,    -1,     4,   220,     4,     7,
     326,     6,    -1,     4,   218,   312,   219,   220,     4,     7,
     326,     6,    -1,     4,   220,     4,   248,   312,     6,    -1,
       4,   218,   312,   219,   220,     4,   248,   312,     6,    -1,
       4,   220,     4,   249,     6,    -1,     4,   218,   312,   219,
     220,     4,   249,     6,    -1,     4,   220,   158,   220,     4,
       7,   322,     6,    -1,     4,   218,   312,   219,   220,   158,
     220,     4,     7,   322,     6,    -1,     4,   220,   159,     7,
     323,     6,    -1,     4,   218,   312,   219,   220,   159,     7,
     323,     6,    -1,     4,   169,     7,   312,     6,    -1,   169,
     218,   312,   219,     7,     4,     6,    -1,   169,   218,   312,
     219,   220,     4,     7,   312,     6,    -1,   169,   218,   312,
     219,   220,     4,     7,   326,     6,    -1,   169,   218,   312,
     219,   220,     4,     7,   223,   321,   224,     6,    -1,   169,
     218,   312,   219,   220,     4,     6,    -1,   115,   216,     4,
     217,   220,     4,     7,   312,     6,    -1,   115,   216,     4,
     217,   220,     4,     7,   326,     6,    -1,    -1,   222,    -1,
      -1,   254,   253,   330,    -1,   254,   253,   330,     7,   312,
      -1,    -1,   254,   253,   330,     7,   223,   318,   255,   261,
     224,    -1,    -1,   254,   253,   330,   218,   219,     7,   223,
     318,   256,   261,   224,    -1,    -1,   254,   253,   330,   216,
     217,     7,   223,   318,   257,   261,   224,    -1,   254,   253,
     330,     7,   326,    -1,    -1,   254,   253,   330,     7,   223,
     326,   258,   263,   224,    -1,    -1,   259,   253,   325,    -1,
     312,     7,   326,    -1,   260,   222,   312,     7,   326,    -1,
     320,     7,   330,   216,   217,    -1,    -1,   261,   262,    -1,
     222,     4,   318,    -1,   222,     4,   223,   260,   224,    -1,
     222,     4,   326,    -1,    -1,   263,   264,    -1,   222,     4,
     312,    -1,   222,     4,   326,    -1,   222,   173,   326,    -1,
     222,     4,   223,   328,   224,    -1,   312,    -1,   326,    -1,
     326,   222,   312,    -1,   312,    -1,   326,    -1,   326,   222,
     312,    -1,   312,    -1,   326,    -1,   326,   222,   312,    -1,
     312,    -1,   326,    -1,   326,   222,   312,    -1,    -1,   161,
      88,   223,   312,   224,    -1,    -1,   107,   315,    -1,   105,
     216,   325,   217,     6,    -1,    84,   216,   312,   217,     7,
     315,     6,    -1,   111,    84,   216,   265,   217,   248,   318,
       6,    -1,    98,    99,   318,     7,   312,     6,    -1,    87,
     216,   312,   217,     7,   318,     6,    -1,   116,    87,   318,
       6,    -1,    91,   216,   312,   217,     7,   318,     6,    -1,
      85,   216,   312,   217,     7,   318,   270,     6,    -1,    86,
     216,   312,   217,     7,   318,   270,     6,    -1,   153,   216,
     312,   217,     7,   318,     6,    -1,   154,   216,   312,   217,
       7,   318,     6,    -1,   155,   216,   312,   217,     7,   318,
     157,   318,   156,   312,     6,    -1,    87,     4,   216,   312,
     217,     7,   318,     6,    -1,   112,    87,   318,     6,    -1,
     112,    87,   216,   312,   217,     7,   318,     6,    -1,   111,
      87,   216,   266,   217,   248,   318,     6,    -1,   107,    90,
     216,   312,   217,     7,   318,     6,    -1,   108,    90,   216,
     312,   217,     7,   318,   269,     6,    -1,    12,    13,     6,
      -1,    13,    90,   312,     6,    -1,   100,    90,   216,   312,
     217,     7,     5,     5,     5,     6,    -1,    88,   216,   312,
     217,     7,   318,     6,    -1,    89,   216,   312,   217,     7,
     318,     6,    -1,    93,   216,   312,   217,     7,   318,     6,
      -1,    94,   216,   312,   217,     7,   318,     6,    -1,    90,
       4,   216,   312,   217,     7,   318,     6,    -1,   112,    90,
     318,     6,    -1,   112,    90,   216,   312,   217,     7,   318,
       6,    -1,   112,    90,   216,   312,   217,     7,   318,     4,
     223,   317,   224,     6,    -1,   111,    90,   216,   267,   217,
     248,   318,     6,    -1,   110,    92,   216,   312,   217,     7,
     318,     6,    -1,    92,   216,   312,   217,     7,   318,     6,
      -1,   106,   216,   312,   217,     7,   223,   317,   224,     6,
      -1,   112,    92,   318,     6,    -1,   112,    92,   216,   312,
     217,     7,   318,     6,    -1,   111,    92,   216,   268,   217,
     248,   318,     6,    -1,   119,   315,   223,   273,   224,    -1,
     118,   223,   315,   222,   315,   222,   312,   224,   223,   273,
     224,    -1,   120,   315,   223,   273,   224,    -1,   121,   223,
     315,   222,   312,   224,   223,   273,   224,    -1,   121,   223,
     315,   222,   315,   224,   223,   273,   224,    -1,     4,   223,
     273,   224,    -1,   133,    87,   223,   321,   224,    90,   223,
     312,   224,    -1,   130,    87,   216,   312,   217,   223,   321,
     224,     6,    -1,   274,    -1,   272,    -1,    -1,   274,   271,
      -1,   274,    84,   223,   321,   224,     6,    -1,   274,    87,
     223,   321,   224,     6,    -1,   274,    90,   223,   321,   224,
       6,    -1,   274,    92,   223,   321,   224,     6,    -1,   123,
     107,   216,   312,   217,     7,   318,     6,    -1,   123,    84,
     216,   312,   217,     7,   223,   317,   224,     6,    -1,   123,
     107,   216,   312,   217,     7,   223,   315,   222,   315,   222,
     321,   224,     6,    -1,   123,   107,   216,   312,   217,     7,
     223,   315,   222,   315,   222,   315,   222,   321,   224,     6,
      -1,   123,    88,   216,   312,   217,     7,   223,   315,   222,
     321,   224,     6,    -1,   123,    94,   216,   312,   217,     7,
     223,   315,   222,   315,   222,   321,   224,     6,    -1,   123,
      95,   216,   312,   217,     7,   223,   315,   222,   315,   222,
     321,   224,     6,    -1,   123,    96,   216,   312,   217,     7,
     223,   315,   222,   315,   222,   321,   224,     6,    -1,   123,
      97,   216,   312,   217,     7,   223,   315,   222,   315,   222,
     321,   224,     6,    -1,   123,     4,   216,   312,   217,     7,
     318,     6,    -1,   123,     4,   216,   312,   217,     7,     5,
       6,    -1,   123,     4,   223,   312,   224,     6,    -1,   131,
     223,   274,   224,    -1,   131,   169,   218,   312,   219,     6,
      -1,   131,     4,   218,   312,   219,     6,    -1,   131,   330,
       6,    -1,   131,     4,     4,     6,    -1,   158,   322,   223,
     274,   224,    -1,   117,   158,   322,   223,   274,   224,    -1,
     190,   312,   223,   274,   224,    -1,   174,     5,     6,    -1,
     175,     5,     6,    -1,   174,   223,   274,   224,    -1,   117,
     174,   223,   274,   224,    -1,   175,   223,   274,   224,    -1,
     117,   175,   223,   274,   224,    -1,     4,   326,     6,    -1,
      71,   216,   328,   217,     6,    -1,     4,     4,   218,   312,
     219,   325,     6,    -1,     4,     4,     4,   218,   312,   219,
       6,    -1,     4,   312,     6,    -1,   115,   216,     4,   217,
     220,     4,     6,    -1,   152,     4,     6,    -1,   167,     6,
      -1,   168,     6,    -1,    68,     6,    -1,    69,     6,    -1,
      62,     6,    -1,    62,   223,   312,   222,   312,   222,   312,
     222,   312,   222,   312,   222,   312,   224,     6,    -1,    63,
       6,    -1,    64,     6,    -1,    75,     6,    -1,    76,     6,
      -1,   102,     6,    -1,   103,   223,   321,   224,   223,   321,
     224,   223,   317,   224,   223,   312,   222,   312,   224,     6,
      -1,   172,   216,   223,   321,   224,   222,   326,   222,   326,
     217,     6,    -1,   160,   216,   312,     8,   312,   217,    -1,
     160,   216,   312,     8,   312,     8,   312,   217,    -1,   160,
       4,   161,   223,   312,     8,   312,   224,    -1,   160,     4,
     161,   223,   312,     8,   312,     8,   312,   224,    -1,   162,
      -1,   173,     4,    -1,   173,   326,    -1,   170,    -1,   171,
     330,     6,    -1,   171,   326,     6,    -1,   163,   216,   312,
     217,    -1,   164,   216,   312,   217,    -1,   165,    -1,   166,
      -1,   122,   315,   223,   274,   224,    -1,   122,   223,   315,
     222,   315,   222,   312,   224,   223,   274,   224,    -1,   122,
     223,   315,   222,   315,   222,   315,   222,   312,   224,   223,
     274,   224,    -1,    -1,   122,   315,   223,   274,   284,   297,
     224,    -1,    -1,   122,   223,   315,   222,   315,   222,   312,
     224,   223,   274,   285,   297,   224,    -1,    -1,   122,   223,
     315,   222,   315,   222,   315,   222,   312,   224,   223,   274,
     286,   297,   224,    -1,    -1,   122,   223,   274,   287,   297,
     224,    -1,   122,    84,   223,   312,   222,   315,   224,     6,
      -1,   122,    87,   223,   312,   222,   315,   224,     6,    -1,
     122,    90,   223,   312,   222,   315,   224,     6,    -1,   122,
      84,   223,   312,   222,   315,   222,   315,   222,   312,   224,
       6,    -1,   122,    87,   223,   312,   222,   315,   222,   315,
     222,   312,   224,     6,    -1,   122,    90,   223,   312,   222,
     315,   222,   315,   222,   312,   224,     6,    -1,   122,    84,
     223,   312,   222,   315,   222,   315,   222,   315,   222,   312,
     224,     6,    -1,   122,    87,   223,   312,   222,   315,   222,
     315,   222,   315,   222,   312,   224,     6,    -1,   122,    90,
     223,   312,   222,   315,   222,   315,   222,   315,   222,   312,
     224,     6,    -1,    -1,   122,    84,   223,   312,   222,   315,
     224,   288,   223,   297,   224,     6,    -1,    -1,   122,    87,
     223,   312,   222,   315,   224,   289,   223,   297,   224,     6,
      -1,    -1,   122,    90,   223,   312,   222,   315,   224,   290,
     223,   297,   224,     6,    -1,    -1,   122,    84,   223,   312,
     222,   315,   222,   315,   222,   312,   224,   291,   223,   297,
     224,     6,    -1,    -1,   122,    87,   223,   312,   222,   315,
     222,   315,   222,   312,   224,   292,   223,   297,   224,     6,
      -1,    -1,   122,    90,   223,   312,   222,   315,   222,   315,
     222,   312,   224,   293,   223,   297,   224,     6,    -1,    -1,
     122,    84,   223,   312,   222,   315,   222,   315,   222,   315,
     222,   312,   224,   294,   223,   297,   224,     6,    -1,    -1,
     122,    87,   223,   312,   222,   315,   222,   315,   222,   315,
     222,   312,   224,   295,   223,   297,   224,     6,    -1,    -1,
     122,    90,   223,   312,   222,   315,   222,   315,   222,   315,
     222,   312,   224,   296,   223,   297,   224,     6,    -1,   298,
      -1,   297,   298,    -1,   136,   223,   312,   224,     6,    -1,
     136,   223,   318,   222,   318,   224,     6,    -1,   136,   223,
     318,   222,   318,   222,   318,   224,     6,    -1,   137,     6,
      -1,   128,     6,    -1,   128,   312,     6,    -1,   144,     6,
      -1,   144,   146,     6,    -1,   145,     6,    -1,   145,   146,
       6,    -1,   142,     6,    -1,   142,   146,     6,    -1,   143,
       6,    -1,   143,   146,     6,    -1,   138,   216,   312,   217,
       7,   318,   114,   312,     6,    -1,   114,     4,   218,   312,
     219,     6,    -1,   125,    -1,   126,    -1,   127,    -1,    -1,
     131,     6,    -1,   131,   312,     6,    -1,   299,   223,   274,
     300,   224,   223,   274,   300,   224,    -1,   299,   216,   312,
     217,     7,   223,   274,   300,   224,   223,   274,   300,   224,
       6,    -1,    -1,   114,     4,   312,    -1,    -1,     4,    -1,
      -1,     7,   318,    -1,    -1,     7,   312,    -1,    -1,   124,
     318,    -1,   109,    87,   319,     7,   312,   303,     6,    -1,
     109,    90,   319,   305,   304,     6,    -1,   101,    90,   223,
     312,   224,     7,   318,     6,    -1,   109,    92,   319,   305,
       6,    -1,   147,   319,     6,    -1,   134,    90,   223,   321,
     224,     7,   312,     6,    -1,   128,    90,   319,   306,     6,
      -1,   128,    92,   319,     6,    -1,   129,    90,   318,     7,
     312,     6,    -1,   113,    87,   223,   321,   224,     7,   223,
     321,   224,   307,     6,    -1,   113,    90,   223,   321,   224,
       7,   223,   321,   224,   307,     6,    -1,   113,    87,   223,
     321,   224,     7,   223,   321,   224,   118,   223,   315,   222,
     315,   222,   312,   224,     6,    -1,   113,    90,   223,   321,
     224,     7,   223,   321,   224,   118,   223,   315,   222,   315,
     222,   312,   224,     6,    -1,   113,    87,   223,   321,   224,
       7,   223,   321,   224,   119,   315,     6,    -1,   113,    90,
     223,   321,   224,     7,   223,   321,   224,   119,   315,     6,
      -1,   113,    90,   312,   223,   321,   224,     7,   312,   223,
     321,   224,     6,    -1,    84,   223,   321,   224,   161,    90,
     223,   312,   224,     6,    -1,    87,   223,   321,   224,   161,
      90,   223,   312,   224,     6,    -1,    84,   223,   321,   224,
     161,    92,   223,   312,   224,     6,    -1,    87,   223,   321,
     224,   161,    92,   223,   312,   224,     6,    -1,    90,   223,
     321,   224,   161,    92,   223,   312,   224,     6,    -1,   135,
      90,   319,     6,    -1,   135,    87,   319,     6,    -1,   104,
      84,   319,     6,    -1,   104,    87,   319,     6,    -1,   104,
      90,   319,     6,    -1,   132,     6,    -1,   132,     4,     6,
      -1,   132,    84,   223,   321,   224,     6,    -1,   181,    -1,
     182,    -1,   183,    -1,   310,     6,    -1,   310,   223,   318,
     224,     6,    -1,   310,   223,   318,   222,   318,   224,     6,
      -1,   310,   216,   318,   217,   223,   318,   222,   318,   224,
       6,    -1,   313,    -1,   216,   312,   217,    -1,   207,   312,
      -1,   206,   312,    -1,   211,   312,    -1,   312,   207,   312,
      -1,   312,   206,   312,    -1,   312,   208,   312,    -1,   312,
     209,   312,    -1,   312,   210,   312,    -1,   312,   215,   312,
      -1,   312,   202,   312,    -1,   312,   203,   312,    -1,   312,
     205,   312,    -1,   312,   204,   312,    -1,   312,   201,   312,
      -1,   312,   200,   312,    -1,   312,   199,   312,    -1,   312,
     198,   312,    -1,   312,   197,   312,     8,   312,    -1,    15,
     250,   312,   251,    -1,    16,   250,   312,   251,    -1,    17,
     250,   312,   251,    -1,    18,   250,   312,   251,    -1,    19,
     250,   312,   251,    -1,    20,   250,   312,   251,    -1,    21,
     250,   312,   251,    -1,    22,   250,   312,   251,    -1,    23,
     250,   312,   251,    -1,    25,   250,   312,   251,    -1,    26,
     250,   312,   222,   312,   251,    -1,    27,   250,   312,   251,
      -1,    28,   250,   312,   251,    -1,    29,   250,   312,   251,
      -1,    30,   250,   312,   251,    -1,    31,   250,   312,   251,
      -1,    32,   250,   312,   251,    -1,    33,   250,   312,   251,
      -1,    34,   250,   312,   222,   312,   251,    -1,    35,   250,
     312,   222,   312,   251,    -1,    36,   250,   312,   222,   312,
     251,    -1,    24,   250,   312,   251,    -1,     3,    -1,     9,
      -1,    14,    -1,    10,    -1,    11,    -1,   186,    -1,   187,
      -1,   188,    -1,    72,    -1,    73,    -1,    74,    -1,    -1,
      80,   250,   312,   314,   261,   251,    -1,   180,   250,   325,
     251,    -1,   180,   250,   325,   222,   312,   251,    -1,   330,
      -1,     4,   218,   312,   219,    -1,     4,   216,   312,   217,
      -1,   329,   218,   312,   219,    -1,   329,   216,   312,   217,
      -1,   184,   216,   330,   217,    -1,   185,   216,   326,   217,
      -1,   221,   330,   250,   251,    -1,   330,   249,    -1,     4,
     218,   312,   219,   249,    -1,     4,   216,   312,   217,   249,
      -1,   329,   218,   312,   219,   249,    -1,   329,   216,   312,
     217,   249,    -1,     4,   220,     4,    -1,     4,   218,   312,
     219,   220,     4,    -1,     4,   220,     4,   249,    -1,     4,
     218,   312,   219,   220,     4,   249,    -1,   176,   216,   325,
     222,   312,   217,    -1,    54,   216,   318,   222,   318,   217,
      -1,    55,   250,   325,   222,   325,   251,    -1,    53,   250,
     325,   251,    -1,    56,   250,   325,   222,   325,   251,    -1,
      61,   216,   328,   217,    -1,   316,    -1,   207,   315,    -1,
     206,   315,    -1,   315,   207,   315,    -1,   315,   206,   315,
      -1,   223,   312,   222,   312,   222,   312,   222,   312,   222,
     312,   224,    -1,   223,   312,   222,   312,   222,   312,   222,
     312,   224,    -1,   223,   312,   222,   312,   222,   312,   224,
      -1,   216,   312,   222,   312,   222,   312,   217,    -1,   318,
      -1,   317,   222,   318,    -1,   312,    -1,   320,    -1,   223,
     224,    -1,   223,   321,   224,    -1,   207,   223,   321,   224,
      -1,   312,   208,   223,   321,   224,    -1,   318,    -1,     5,
      -1,   207,   320,    -1,   312,   208,   320,    -1,   312,     8,
     312,    -1,   312,     8,   312,     8,   312,    -1,    84,   223,
     312,   224,    -1,    84,     5,    -1,    87,     5,    -1,    90,
       5,    -1,    92,     5,    -1,   111,    84,     5,    -1,   111,
      87,     5,    -1,   111,    90,     5,    -1,   111,    92,     5,
      -1,   111,    84,   223,   321,   224,    -1,   111,    87,   223,
     321,   224,    -1,   111,    90,   223,   321,   224,    -1,   111,
      92,   223,   321,   224,    -1,    84,   161,    62,   223,   312,
     222,   312,   222,   312,   222,   312,   222,   312,   222,   312,
     224,    -1,    87,   161,    62,   223,   312,   222,   312,   222,
     312,   222,   312,   222,   312,   222,   312,   224,    -1,    90,
     161,    62,   223,   312,   222,   312,   222,   312,   222,   312,
     222,   312,   222,   312,   224,    -1,    92,   161,    62,   223,
     312,   222,   312,   222,   312,   222,   312,   222,   312,   222,
     312,   224,    -1,   272,    -1,   283,    -1,   301,    -1,     4,
     250,   251,    -1,   329,   250,   251,    -1,    37,   218,   330,
     219,    -1,    37,   218,   320,   219,    -1,    37,   216,   320,
     217,    -1,    37,   218,   223,   321,   224,   219,    -1,    37,
     216,   223,   321,   224,   217,    -1,     4,   250,   223,   321,
     224,   251,    -1,   329,   250,   223,   321,   224,   251,    -1,
      38,   250,   312,   222,   312,   222,   312,   251,    -1,    39,
     250,   312,   222,   312,   222,   312,   251,    -1,    40,   250,
     325,   251,    -1,    41,   250,   312,   222,   312,   222,   312,
     222,   312,   222,   312,   222,   312,   251,    -1,   312,    -1,
     320,    -1,   321,   222,   312,    -1,   321,   222,   320,    -1,
     223,   312,   222,   312,   222,   312,   222,   312,   224,    -1,
     223,   312,   222,   312,   222,   312,   224,    -1,   330,    -1,
       4,   220,   158,   220,     4,    -1,   223,   324,   224,    -1,
       4,   218,   312,   219,   220,   159,    -1,   322,    -1,   324,
     222,   322,    -1,   326,    -1,   330,    -1,     4,   218,   312,
     219,    -1,   329,   218,   312,   219,    -1,     4,   216,   312,
     217,    -1,   329,   216,   312,   217,    -1,     4,   220,     4,
      -1,     4,   218,   312,   219,   220,     4,    -1,     5,    -1,
     191,   218,   330,   219,    -1,    65,    -1,   189,    -1,    70,
      -1,   178,   216,   325,   217,    -1,   177,   216,   325,   222,
     325,   217,    -1,   179,   250,   325,   251,    -1,   179,   250,
     325,   222,   325,   251,    -1,    46,   250,   328,   251,    -1,
      47,   216,   325,   217,    -1,    48,   216,   325,   217,    -1,
      49,   216,   325,   222,   325,   222,   325,   217,    -1,    44,
     250,   328,   251,    -1,    58,   250,   325,   251,    -1,    59,
     250,   325,   251,    -1,    60,   250,   325,   251,    -1,    57,
     250,   312,   222,   325,   222,   325,   251,    -1,    52,   250,
     325,   222,   312,   222,   312,   251,    -1,    52,   250,   325,
     222,   312,   251,    -1,    45,   250,   325,   251,    -1,    45,
     250,   325,   222,   321,   251,    -1,    66,   250,   325,   251,
      -1,    67,    -1,    51,   250,   325,   251,    -1,    50,   250,
     325,   251,    -1,    -1,    81,   250,   326,   327,   263,   251,
      -1,   325,    -1,   328,   222,   325,    -1,     4,   225,   223,
     312,   224,    -1,   329,   225,   223,   312,   224,    -1,     4,
      -1,   329,    -1,   192,   218,   325,   219,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   208,   208,   209,   214,   216,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   242,   246,   253,   258,   263,
     277,   290,   303,   331,   345,   358,   371,   390,   395,   396,
     397,   398,   399,   403,   405,   410,   412,   418,   522,   417,
     540,   547,   558,   557,   575,   582,   593,   592,   609,   626,
     649,   648,   662,   663,   664,   665,   666,   670,   671,   677,
     677,   678,   678,   684,   685,   686,   691,   697,   759,   776,
     805,   834,   839,   844,   849,   854,   861,   871,   900,   929,
     934,   939,   944,   952,   961,   967,   973,   986,   999,  1014,
    1031,  1037,  1043,  1056,  1069,  1084,  1101,  1107,  1116,  1134,
    1152,  1161,  1173,  1178,  1186,  1206,  1229,  1240,  1248,  1270,
    1293,  1331,  1352,  1364,  1378,  1378,  1380,  1382,  1391,  1401,
    1400,  1421,  1420,  1439,  1438,  1456,  1466,  1465,  1479,  1481,
    1489,  1495,  1500,  1526,  1527,  1531,  1542,  1557,  1567,  1568,
    1573,  1581,  1590,  1598,  1616,  1620,  1626,  1634,  1638,  1644,
    1652,  1656,  1662,  1670,  1674,  1680,  1689,  1692,  1705,  1708,
    1716,  1724,  1752,  1795,  1818,  1836,  1857,  1875,  1915,  1945,
    1963,  1981,  2008,  2027,  2032,  2050,  2096,  2114,  2153,  2159,
    2165,  2172,  2213,  2239,  2263,  2288,  2305,  2309,  2328,  2362,
    2409,  2427,  2444,  2473,  2477,  2493,  2541,  2546,  2551,  2556,
    2561,  2566,  2589,  2595,  2606,  2607,  2612,  2615,  2619,  2648,
    2677,  2706,  2740,  2762,  2788,  2810,  2833,  2854,  2910,  2934,
    2959,  2985,  3098,  3117,  3160,  3169,  3175,  3190,  3218,  3235,
    3244,  3258,  3272,  3278,  3284,  3293,  3302,  3311,  3325,  3387,
    3405,  3422,  3437,  3466,  3478,  3502,  3506,  3511,  3519,  3524,
    3530,  3535,  3541,  3549,  3553,  3557,  3562,  3622,  3638,  3655,
    3672,  3694,  3716,  3751,  3759,  3767,  3773,  3780,  3787,  3807,
    3833,  3845,  3857,  3865,  3873,  3882,  3881,  3896,  3895,  3910,
    3909,  3924,  3923,  3937,  3944,  3951,  3958,  3965,  3972,  3979,
    3986,  3993,  4001,  4000,  4014,  4013,  4027,  4026,  4040,  4039,
    4053,  4052,  4066,  4065,  4079,  4078,  4092,  4091,  4105,  4104,
    4121,  4124,  4130,  4142,  4162,  4186,  4190,  4194,  4198,  4202,
    4206,  4212,  4218,  4222,  4226,  4230,  4234,  4253,  4266,  4267,
    4268,  4272,  4273,  4274,  4277,  4298,  4318,  4321,  4337,  4340,
    4357,  4360,  4366,  4369,  4376,  4379,  4386,  4442,  4512,  4517,
    4584,  4620,  4628,  4671,  4710,  4730,  4762,  4789,  4815,  4841,
    4867,  4893,  4915,  4943,  4971,  4999,  5027,  5055,  5094,  5133,
    5154,  5175,  5202,  5206,  5216,  5251,  5252,  5253,  5257,  5263,
    5275,  5293,  5321,  5322,  5323,  5324,  5325,  5326,  5327,  5328,
    5329,  5336,  5337,  5338,  5339,  5340,  5341,  5342,  5343,  5344,
    5345,  5346,  5347,  5348,  5349,  5350,  5351,  5352,  5353,  5354,
    5355,  5356,  5357,  5358,  5359,  5360,  5361,  5362,  5363,  5364,
    5365,  5366,  5367,  5368,  5377,  5378,  5379,  5380,  5381,  5382,
    5383,  5384,  5385,  5386,  5387,  5392,  5391,  5399,  5404,  5409,
    5426,  5444,  5462,  5480,  5498,  5503,  5509,  5524,  5543,  5563,
    5583,  5603,  5626,  5631,  5636,  5646,  5656,  5661,  5672,  5681,
    5686,  5691,  5718,  5722,  5726,  5730,  5734,  5741,  5745,  5749,
    5753,  5760,  5765,  5772,  5777,  5781,  5786,  5790,  5798,  5809,
    5813,  5825,  5833,  5841,  5848,  5858,  5887,  5891,  5895,  5899,
    5903,  5907,  5911,  5915,  5919,  5948,  5977,  6006,  6035,  6048,
    6061,  6074,  6087,  6097,  6107,  6117,  6129,  6142,  6154,  6158,
    6162,  6166,  6170,  6188,  6206,  6214,  6222,  6251,  6264,  6269,
    6273,  6277,  6289,  6293,  6305,  6322,  6332,  6336,  6351,  6356,
    6363,  6367,  6380,  6394,  6408,  6422,  6436,  6444,  6455,  6459,
    6463,  6471,  6477,  6483,  6491,  6499,  6506,  6514,  6529,  6543,
    6557,  6569,  6585,  6594,  6603,  6613,  6624,  6632,  6640,  6644,
    6663,  6670,  6676,  6683,  6691,  6690,  6703,  6708,  6714,  6723,
    6736,  6739,  6743
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
  "tCone", "tEllipsoid", "tQuadric", "tCharacteristic", "tLength",
  "tParametric", "tElliptic", "tRefineMesh", "tAdaptMesh", "tRelocateMesh",
  "tSetFactory", "tThruSections", "tPlane", "tRuled", "tTransfinite",
  "tComplex", "tPhysical", "tCompound", "tPeriodic", "tUsing", "tPlugin",
  "tDegenerated", "tRecursive", "tRotate", "tTranslate", "tSymmetry",
  "tDilate", "tExtrude", "tLevelset", "tAffine", "tBooleanUnion",
  "tBooleanIntersection", "tBooleanSubtraction", "tRecombine", "tSmoother",
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
     445,   446,   447,   448,   449,   450,   451,    63,   452,   453,
     454,   455,    60,    62,   456,   457,    43,    45,    42,    47,
      37,    33,   458,   459,   460,    94,    40,    41,    91,    93,
      46,    35,    44,   123,   125,   126
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   226,   227,   227,   228,   228,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   230,   230,   231,   231,   231,
     231,   231,   231,   232,   232,   232,   232,   233,   233,   233,
     233,   233,   233,   234,   234,   235,   235,   237,   238,   236,
     239,   239,   241,   240,   242,   242,   244,   243,   245,   245,
     247,   246,   248,   248,   248,   248,   248,   249,   249,   250,
     250,   251,   251,   252,   252,   252,   252,   252,   252,   252,
     252,   252,   252,   252,   252,   252,   252,   252,   252,   252,
     252,   252,   252,   252,   252,   252,   252,   252,   252,   252,
     252,   252,   252,   252,   252,   252,   252,   252,   252,   252,
     252,   252,   252,   252,   252,   252,   252,   252,   252,   252,
     252,   252,   252,   252,   253,   253,   254,   254,   254,   255,
     254,   256,   254,   257,   254,   254,   258,   254,   259,   259,
     260,   260,   260,   261,   261,   262,   262,   262,   263,   263,
     264,   264,   264,   264,   265,   265,   265,   266,   266,   266,
     267,   267,   267,   268,   268,   268,   269,   269,   270,   270,
     271,   271,   271,   271,   271,   271,   271,   271,   271,   271,
     271,   271,   271,   271,   271,   271,   271,   271,   271,   271,
     271,   271,   271,   271,   271,   271,   271,   271,   271,   271,
     271,   271,   271,   271,   271,   271,   272,   272,   272,   272,
     272,   272,   272,   272,   273,   273,   274,   274,   274,   274,
     274,   274,   275,   275,   275,   275,   275,   275,   275,   275,
     275,   275,   275,   275,   276,   276,   276,   276,   276,   277,
     277,   278,   279,   279,   279,   279,   279,   279,   280,   280,
     280,   280,   280,   280,   280,   280,   280,   280,   280,   280,
     280,   280,   280,   280,   280,   280,   280,   281,   282,   282,
     282,   282,   282,   282,   282,   282,   282,   282,   282,   282,
     282,   282,   283,   283,   283,   284,   283,   285,   283,   286,
     283,   287,   283,   283,   283,   283,   283,   283,   283,   283,
     283,   283,   288,   283,   289,   283,   290,   283,   291,   283,
     292,   283,   293,   283,   294,   283,   295,   283,   296,   283,
     297,   297,   298,   298,   298,   298,   298,   298,   298,   298,
     298,   298,   298,   298,   298,   298,   298,   298,   299,   299,
     299,   300,   300,   300,   301,   302,   303,   303,   304,   304,
     305,   305,   306,   306,   307,   307,   308,   308,   308,   308,
     308,   308,   308,   308,   308,   308,   308,   308,   308,   308,
     308,   308,   308,   308,   308,   308,   308,   308,   308,   308,
     308,   308,   309,   309,   309,   310,   310,   310,   311,   311,
     311,   311,   312,   312,   312,   312,   312,   312,   312,   312,
     312,   312,   312,   312,   312,   312,   312,   312,   312,   312,
     312,   312,   312,   312,   312,   312,   312,   312,   312,   312,
     312,   312,   312,   312,   312,   312,   312,   312,   312,   312,
     312,   312,   312,   312,   313,   313,   313,   313,   313,   313,
     313,   313,   313,   313,   313,   314,   313,   313,   313,   313,
     313,   313,   313,   313,   313,   313,   313,   313,   313,   313,
     313,   313,   313,   313,   313,   313,   313,   313,   313,   313,
     313,   313,   315,   315,   315,   315,   315,   316,   316,   316,
     316,   317,   317,   318,   318,   318,   318,   318,   318,   319,
     319,   320,   320,   320,   320,   320,   320,   320,   320,   320,
     320,   320,   320,   320,   320,   320,   320,   320,   320,   320,
     320,   320,   320,   320,   320,   320,   320,   320,   320,   320,
     320,   320,   320,   320,   320,   320,   320,   320,   321,   321,
     321,   321,   322,   322,   322,   322,   323,   323,   324,   324,
     325,   325,   325,   325,   325,   325,   325,   325,   326,   326,
     326,   326,   326,   326,   326,   326,   326,   326,   326,   326,
     326,   326,   326,   326,   326,   326,   326,   326,   326,   326,
     326,   326,   326,   326,   327,   326,   328,   328,   329,   329,
     330,   330,   330
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
       8,     7,     9,     4,     8,     8,     5,    11,     5,     9,
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
       1,     0,     2,     3,     9,    14,     0,     3,     0,     1,
       0,     2,     0,     2,     0,     2,     7,     6,     8,     5,
       3,     8,     5,     4,     6,    11,    11,    18,    18,    12,
      12,    12,    10,    10,    10,    10,    10,     4,     4,     4,
       4,     4,     2,     3,     6,     1,     1,     1,     2,     5,
       7,    10,     1,     3,     2,     2,     2,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     5,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     6,     4,     4,     4,     4,     4,     4,     4,
       6,     6,     6,     4,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     0,     6,     4,     6,     1,
       4,     4,     4,     4,     4,     4,     4,     2,     5,     5,
       5,     5,     3,     6,     4,     7,     6,     6,     6,     4,
       6,     4,     1,     2,     2,     3,     3,    11,     9,     7,
       7,     1,     3,     1,     1,     2,     3,     4,     5,     1,
       1,     2,     3,     3,     5,     4,     2,     2,     2,     2,
       3,     3,     3,     3,     5,     5,     5,     5,    16,    16,
      16,    16,     1,     1,     1,     3,     3,     4,     4,     4,
       6,     6,     6,     6,     8,     8,     4,    14,     1,     1,
       3,     3,     9,     7,     1,     5,     3,     6,     1,     3,
       1,     1,     4,     4,     4,     4,     3,     6,     1,     4,
       1,     1,     1,     4,     6,     4,     6,     4,     4,     4,
       8,     4,     4,     4,     4,     8,     8,     6,     4,     6,
       4,     1,     4,     4,     0,     6,     1,     3,     5,     5,
       1,     1,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     2,     3,     1,   580,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   338,   339,
     340,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   272,
       0,     0,   280,   281,     0,     0,     0,   275,     0,     0,
       0,     0,     0,   385,   386,   387,     0,     0,     5,     7,
       6,     8,     9,    10,    23,    11,    12,    13,    14,    22,
      21,    20,    15,     0,    16,    17,    18,    19,     0,    24,
     581,     0,   434,   580,   548,   435,   437,   438,   436,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   550,
       0,   571,   552,   442,   443,   444,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   439,   440,   441,   551,
       0,     0,     0,     0,    69,    70,     0,     0,   216,     0,
       0,     0,   392,     0,   540,   581,   449,     0,     0,     0,
       0,   259,     0,   261,   262,   257,   258,     0,   263,   264,
     126,   138,    69,    70,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   265,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   472,     0,     0,
       0,     0,     0,   216,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   580,     0,   216,
     581,     0,     0,   382,     0,     0,     0,     0,     0,     0,
       0,     0,   580,   490,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   512,   513,     0,
     514,   483,   489,     0,   484,   581,   449,     0,     0,     0,
       0,   580,     0,     0,   534,     0,     0,     0,     0,   255,
     256,     0,   580,     0,     0,     0,   273,   274,     0,   216,
       0,   216,   580,     0,   581,     0,     0,   216,   388,     0,
       0,    69,    70,     0,     0,    62,    66,    65,    64,    63,
      68,    67,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     395,   394,   396,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   215,     0,   214,     0,     0,   252,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    37,   248,     0,     0,   457,   188,     0,
     580,     0,   540,   581,   541,     0,     0,   576,     0,   124,
     124,     0,     0,     0,     0,   528,   529,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   350,   350,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   216,   216,     0,   474,   473,     0,     0,     0,
       0,   216,   216,     0,     0,     0,     0,     0,     0,     0,
     291,     0,   216,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   352,     0,     0,     0,     0,     0,     0,     0,
     237,   383,     0,     0,     0,     0,     0,     0,     0,     0,
      69,    70,     0,     0,     0,     0,     0,     0,     0,     0,
     496,     0,     0,   497,     0,   498,     0,   499,     0,     0,
       0,     0,     0,     0,   394,   491,     0,   485,     0,     0,
       0,   360,    69,    70,     0,   254,     0,     0,     0,     0,
       0,   216,     0,     0,     0,     0,     0,   277,   276,     0,
     242,     0,   243,     0,     0,     0,   216,     0,     0,     0,
       0,   341,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    78,     0,     0,     0,   462,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   445,   574,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    62,
      63,     0,   393,    62,    63,     0,     0,    62,     0,     0,
       0,     0,     0,   211,     0,     0,     0,     0,   217,     0,
       0,     0,   410,   409,   408,   407,   403,   404,   406,   405,
     398,   397,   399,   400,   401,   402,     0,     0,     0,   189,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   125,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     379,   380,   381,     0,     0,     0,     0,     0,     0,   348,
       0,     0,     0,   154,   155,     0,   157,   158,     0,   160,
     161,     0,   163,   164,     0,   183,     0,   196,     0,   203,
       0,     0,     0,     0,   175,   216,     0,     0,     0,     0,
       0,   476,   475,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   285,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   363,     0,     0,   238,     0,     0,
     234,     0,     0,     0,   378,   377,     0,     0,     0,     0,
       0,   462,    71,    72,     0,   515,     0,     0,     0,     0,
       0,   449,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   500,     0,   501,     0,   502,     0,   503,     0,     0,
     393,   486,   493,     0,   399,   492,     0,     0,     0,   516,
       0,     0,     0,     0,     0,     0,     0,     0,   278,   279,
       0,     0,   244,   246,     0,   582,     0,     0,     0,     0,
       0,     0,    62,    63,     0,     0,    62,    63,     0,     0,
       0,     0,    93,    77,     0,   451,   450,   464,   412,   413,
     414,   415,   416,   417,   418,   419,   420,   433,   421,     0,
     423,   424,   425,   426,   427,   428,   429,     0,     0,     0,
     561,     0,   568,   557,   558,   559,     0,   573,   572,     0,
     469,     0,     0,     0,     0,   562,   563,   564,   471,   570,
     143,   148,   116,     0,     0,   553,     0,   555,     0,   447,
     454,   455,   549,     0,     0,     0,    62,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   110,     0,     0,
       0,     0,   456,     0,     0,     0,     0,   578,     0,     0,
      47,     0,     0,     0,    60,     0,    38,    39,    40,    41,
      42,   453,   452,     0,     0,   546,    27,    25,     0,     0,
       0,     0,    28,     0,     0,   249,   577,    73,   127,    74,
     139,     0,     0,     0,   530,   531,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   170,     0,     0,     0,   346,   351,
     349,     0,   359,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   393,   393,   393,     0,     0,     0,     0,     0,
     245,   247,     0,     0,     0,   206,   208,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   320,     0,   282,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   353,   362,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   451,   450,     0,
       0,   519,     0,   518,   517,     0,     0,   526,     0,     0,
     495,     0,     0,     0,     0,     0,     0,     0,   487,     0,
       0,   453,   452,     0,     0,     0,     0,     0,     0,   239,
       0,     0,     0,     0,     0,   241,     0,   342,     0,     0,
       0,     0,   389,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   579,     0,     0,   459,     0,   458,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    87,
       0,    91,     0,     0,    79,     0,     0,     0,     0,    83,
     106,   108,     0,     0,   538,     0,   114,     0,     0,     0,
       0,     0,   411,     0,     0,     0,     0,     0,    33,   461,
     460,   544,   542,    26,     0,     0,   545,   543,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   168,   168,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   173,     0,     0,     0,     0,     0,     0,     0,
       0,   357,     0,     0,   156,     0,   159,     0,   162,     0,
     165,     0,     0,     0,     0,     0,     0,     0,   240,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   326,     0,
       0,   325,     0,   332,     0,   334,     0,   328,     0,   330,
       0,   292,   321,     0,     0,     0,   233,     0,     0,     0,
       0,     0,     0,     0,   364,     0,   236,   235,   384,     0,
       0,    34,    35,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   504,   505,   506,   507,   494,
     488,     0,     0,     0,     0,   535,     0,     0,     0,   268,
       0,     0,     0,   216,   343,   216,     0,     0,     0,     0,
      88,     0,    92,     0,     0,    80,     0,    84,     0,   251,
     463,   250,   422,   430,   431,   432,   569,     0,     0,   567,
     467,   468,   470,     0,     0,   446,   144,     0,   575,   149,
     466,   554,   556,   448,     0,     0,     0,    89,     0,     0,
       0,    62,     0,     0,     0,     0,    81,     0,     0,     0,
     536,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     481,     0,     0,    29,    30,     0,    31,     0,     0,   128,
     135,     0,     0,    75,    76,   171,     0,     0,     0,     0,
       0,     0,   174,     0,     0,   191,   192,     0,     0,   176,
     201,   193,   194,     0,     0,     0,     0,     0,   166,     0,
     356,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   253,     0,     0,     0,     0,   216,   216,     0,
     302,     0,   304,     0,   306,     0,   327,   483,     0,     0,
     333,   335,   329,   331,     0,     0,   286,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   463,   522,   521,   520,     0,     0,     0,     0,     0,
       0,     0,   523,   179,   180,     0,     0,     0,     0,   117,
     121,     0,     0,   341,   341,     0,   390,     0,     0,     0,
      90,     0,     0,     0,    82,     0,   465,     0,     0,     0,
       0,     0,     0,   100,     0,     0,    94,     0,     0,     0,
       0,   111,     0,     0,   112,     0,   539,   218,   219,   220,
     221,     0,     0,    43,     0,     0,     0,     0,     0,    45,
     547,     0,     0,   129,   136,     0,     0,     0,     0,   169,
     177,   178,   182,     0,     0,   195,     0,     0,   358,     0,
       0,   186,     0,     0,   347,   200,   172,   185,   199,   205,
     184,     0,   197,   204,     0,     0,     0,     0,     0,     0,
     480,     0,   479,     0,     0,     0,   293,     0,     0,   294,
       0,     0,   295,     0,     0,     0,     0,     0,     0,     0,
     232,   231,     0,     0,     0,     0,     0,     0,     0,     0,
     222,     0,     0,   361,    36,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   533,     0,   270,   269,     0,     0,
       0,     0,     0,     0,     0,   101,     0,     0,    95,     0,
       0,     0,   560,   566,   565,     0,   145,   147,     0,   150,
     151,   152,   102,   104,    96,    98,   107,   109,     0,   115,
       0,    85,    48,     0,     0,     0,   482,     0,     0,     0,
      32,     0,   143,   148,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   202,     0,   187,     0,   354,   354,     0,
     122,   123,   216,     0,   209,   210,     0,     0,     0,     0,
       0,     0,     0,   322,     0,     0,   216,     0,     0,     0,
       0,     0,     0,     0,     0,   213,   212,   524,   525,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   118,   119,
       0,     0,   344,     0,   103,   105,    97,    99,    86,     0,
     528,   529,     0,     0,   537,     0,    44,     0,     0,     0,
      46,    61,     0,     0,     0,   133,   131,   372,   374,   373,
     375,   376,   190,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   478,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   337,     0,     0,     0,
     287,     0,   223,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   532,   271,     0,     0,   216,
     391,     0,   146,     0,     0,   153,   113,     0,     0,     0,
       0,     0,   130,   137,   143,   143,     0,     0,     0,     0,
       0,   355,   365,     0,     0,   366,     0,   207,     0,   308,
       0,     0,   310,     0,     0,   312,     0,     0,     0,   323,
       0,   283,     0,   216,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   181,   120,   267,   341,     0,
     140,     0,     0,    52,     0,    58,     0,     0,     0,     0,
       0,   167,   198,     0,   369,     0,   370,   371,   477,   296,
       0,     0,   303,   297,     0,     0,   305,   298,     0,     0,
     307,     0,     0,     0,   289,   226,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   134,   132,     0,     0,     0,
       0,   314,     0,   316,     0,   318,   324,   336,   288,   284,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   141,   142,    49,     0,    56,     0,     0,
       0,     0,     0,     0,   299,     0,     0,   300,     0,     0,
     301,     0,     0,   227,   228,   229,   230,     0,   224,     0,
       0,     0,     0,     0,   345,     0,    50,     0,     0,   260,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   290,
       0,   527,     0,     0,     0,     0,     0,     0,     0,     0,
     266,     0,     0,   309,     0,   311,     0,   313,     0,   225,
       0,     0,     0,     0,    51,    53,     0,    54,     0,     0,
       0,     0,     0,     0,   508,   509,   510,   511,     0,     0,
      59,   367,   368,   315,   317,   319,    55,    57
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    98,  1058,    99,   100,   756,  1632,  1638,
    1046,  1273,  1845,  2085,  1047,  2021,  2126,  1048,  2087,  1049,
    1050,  1277,   382,   477,   200,   885,   101,   774,   489,  1772,
    1925,  1924,  1773,   490,  1839,  1241,  1446,  1242,  1449,   812,
     815,   818,   821,  1663,  1499,   738,   327,   453,   454,   104,
     105,   106,   107,   108,   109,   110,   111,   328,  1145,  1952,
    2040,   850,  1687,  1690,  1693,  1990,  1994,  1998,  2065,  2068,
    2071,  1141,  1142,   329,   938,   330,   115,  1320,  1101,   809,
     863,  1869,   116,   117,   118,   119,   331,   202,  1000,   546,
     277,  1479,   332,   333,   334,   618,   343,  1031,  1265,   487,
     482,  1001,   488,   364,   336
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1757
static const yytype_int16 yypact[] =
{
   10038,    70,    64, 10182, -1757, -1757,  4486,    18,    63,  -156,
    -114,    59,   109,   143,   177,   192,   -11,   217,   279,    85,
      93,  -173,  -173,   -89,   102,   116,    54,   135,   145,    31,
     188,   204,   234,   245,   223,   186,   296,   387,   247,   499,
     324,   332,   422,   488,   263,   469,   844,   660,   244,   369,
     507,  -107,   390,  -136,  -136,   418,   503,    35, -1757, -1757,
   -1757,    80,   542,   548,    26,    36,   557,   605,   348,   712,
     721,   738,  6327,   745,   513,   544,   550,    25,    37, -1757,
     560,   594, -1757, -1757,   857,   874,   484, -1757,  7933,   668,
    8363,    43,    50, -1757, -1757, -1757,  9887,   670, -1757, -1757,
   -1757, -1757, -1757, -1757, -1757, -1757, -1757, -1757, -1757, -1757,
   -1757, -1757, -1757,   -71, -1757, -1757, -1757, -1757,     3, -1757,
     -70,   101, -1757,    16, -1757, -1757, -1757, -1757, -1757,  -173,
    -173,  -173,  -173,  -173,  -173,  -173,  -173,  -173,  -173,  -173,
    -173,  -173,  -173,  -173,  -173,  -173,  -173,  -173,  -173,  -173,
    -173,  -173,  -173,  -173,   675,   681,   686,  -173,  -173,  -173,
    -173,   691,  -173,  -173,  -173,  -173,  -173,  -173,   711, -1757,
    -173, -1757, -1757, -1757, -1757, -1757,  -173,  -173,   923,   717,
     723,   732,  -173,  -173,   754,   777, -1757, -1757, -1757, -1757,
     741,  9887,  9887,  9887,  2542,  3105,    23,    21,   424,   740,
     776,   300, -1757,   787,  1005,   -51,   -34,  1008,  9887,  8148,
    8148, -1757,  9887, -1757, -1757, -1757, -1757,  8148, -1757, -1757,
   -1757, -1757, -1757, -1757,  4705,    21,  9887,  9116,  9887,  9887,
     799,  9887,  9116,  9887,  9887,   809,  9116,  9887,  9887,  9887,
    9887,  6757,   813,   814, -1757,  9116,  6327,  6327,  6327,  8148,
    9887,   822,   845,  6327,  6327,  6327,   846,   860,   865,   866,
     871,  6972,  7187,  7402,   900,  1207,  1016,  6757,    25,   901,
     913,  -136,  -136,  -136,  9887,  9887,  -101, -1757,   -82,  -136,
     914,   927,   954,  1805,   -63,   -57,   887,   895,   939,   962,
     974,   989,   993,  6327,  6327,  6757,  1003,    10,   875, -1757,
     892,  1214,  1241, -1757,  1046,  1089,  1098,  6327,  6327,  1039,
    1057,  1099,   688, -1757,  -104,  -173,  -173,  -173,  -173,    39,
      14,    27,    29,   859,  7617,  9887,  5165, -1757, -1757,  1155,
   -1757,  2465, -1757,  1329, -1757,   260,   213,  1339,  9887,  9887,
    9887,   -85,  9887,  1156, -1757,  1203,  9887,  9887,  9887, -1757,
   -1757,  9887,  1143,  1370,  1374,  1159, -1757, -1757,  1378, -1757,
    1379, -1757,   156,  4618,   519,  8148,  9887, -1757, -1757,  6757,
    6757,  9325,  9392,  1163,  1166,  4705, -1757, -1757, -1757, -1757,
   -1757, -1757,  6757,  1384,  1188,  9887,  9887,  1396,  9887,  9887,
    9887,  9887,  9887,  9887,  9887,  9887,  9887,  9887,  9887,  9887,
    9887,  9887,  9887,  9887,  9887,  9887,  9887,  9887,  9887,  9887,
    8148,  8148,  8148,  8148,  8148,  8148,  8148,  8148,  8148,  8148,
    6757,  8148,  8148,  9887,  8148,  8148,  8148,  8148,  8148,  9887,
    4705,  9887,  8148,  8148,  8148,  8148,  8148,    21,  4705,    21,
    1192,  1192,  1192,    15, 11690,   195,  9079,   114,  1189,  1401,
    -173,  1187, -1757,  1193,  5444,  9887,  9116, -1757,  9887,  9887,
    9887,  9887,  9887,  9887,  9887,  9887,  9887,  9887,  9887,  9887,
    9887,  9887,  9887, -1757, -1757,  9887,  9887, -1757, -1757,   399,
     696,   341, -1757,   539, -1757,   474,  9234, -1757,   545,   273,
     304,  1190,  1200, 11711,  9116,  2759, -1757,   170, 11732, 11753,
    9887, 11774,   215, 11795, 11816,  9887,   289, 11837, 11858, 11879,
   11900,  1404,  9887,  9887,   308,  1418,  1419,  1420,  1210, 11921,
    9887,  9887,  1422,  1424,  1424,  9887,  8907,  8907,  8907,  8907,
    9887,  1426,  9887,  1429,  9887,  1430,  9116,  9116,  8848,  1220,
    1432,  1216, -1757, -1757,   -49, -1757, -1757,  9276,  9351,  -136,
    -136,   424,   424,   -30,  9887,  9887,  9887,  1805,  1805,  9887,
    5444,   158, -1757,  9887,  9887,  9887,  9887,  9887,  9887,  9887,
    9887,  9887,  1434,  1437,  1438,  9887,  1440,  9887,  9887,  1041,
   -1757, -1757,  9116,  9116,  9116,  1444,  1445,  9887,  9887,  9887,
    9887,  9887,  1448,   336,  7832,  8047,  9887,  9887,  8148,  9887,
   -1757,  1382,  9887, -1757,  1397, -1757,  1398, -1757,  1403,    51,
      52,    57,    58,  9116,  1192, -1757, 11942, -1757,   430,  9887,
    8262, -1757,  9887,  9887,   460, -1757, 11963, 11984, 12005,  1300,
    9448, -1757,  1246,  2825, 12026, 12047, 11322, -1757, -1757,  9116,
   -1757,  3388, -1757,  4628,  9887,  9887, -1757,  9887,  9887,  1251,
   12068,  4317,  1254,   431,   205, 12089,   286, 11345,  9887,  9116,
    1468,  1469, -1757,  9887, 12110, 11368,   183,  6025,  6025,  6025,
    6025,  6025,  6025,  6025,  6025,  6025,  6025,  6025,  9520,  6025,
    6025,  6025,  6025,  6025,  6025,  6025,  9562,  9631,  9729,  -118,
     151,  -118,  1259,  1261,  1255,   495,   495,  1257,   495,  1258,
    1264,  1265,  9771,   495,   495,   495,   585,   495, 12740, -1757,
     582,  1267,  1268,  1266,   553,   725,  1275,  1276,  1262,  1450,
    1451,  6757,   164,  1452,  1453,  6757,   106,  4705,  9887,  1492,
    1496,    33,   495, -1757,   -38,    55,    34,   -32, -1757,  3750,
     663,  2873,  1830,  2570,   863,   863,   658,   658,   658,   658,
     667,   667,  1192,  1192,  1192,  1192,    13, 12131, 11391, -1757,
    9887,  9887,  1497,    17,  9116,  9887,  9887,  1498,  9116,  9887,
    1499,  8148,  1500, -1757,    21,  1501,  8148,  9887,  4705,  1495,
    9116,  9116,  1342,  1504,  1506, 12152,  1507,  1347,  1510,  1511,
   12173,  1358,  1513,  1514,  1515,  1517,  9887, 12194,  3825,  1302,
   -1757, -1757, -1757,  1522,  1523, 12215, 12236,  9887,  6757,  1525,
    1526, 12257,  1316, 12740,  1312,  1321, 12740,  1317,  1324, 12740,
    1320,  1327, 12740,  1323, 12278, -1757, 12299, -1757, 12320, -1757,
     674,   698,  9116,  1328, -1757, -1757,  6162,  6377,  -136,  9887,
    9887, -1757, -1757,  1326,  1330,  1805,  9797,  9825, 10178,  9167,
     562,  -136,  6592, 12341,  3902, 12362, 12383, 12404, 12425, 12446,
   12467, 12488,  9887,  1541, -1757,  9887, 12509, -1757, 11414, 11437,
   -1757,   749,   752,   753, -1757, -1757, 11460, 11483, 10204, 12530,
   11506,   213, -1757, -1757,  9116, -1757,  9116,  2759,  1334,  9116,
    1333,   275, 10230, 10256,   495, 10282,  1332,  3942,  1337,  1338,
    1344, -1757,  9116, -1757,  9116, -1757,  9116, -1757,  9116,   757,
   -1757, -1757,  2990,  9116,  1192, -1757, 12551, 11529,  9116, -1757,
    1546,  1561,  1562,  1350,  9887,  6807,  9887,  9887, -1757, -1757,
      11,   763, -1757, -1757,  7022, -1757,  1564,  9606,  1349,  1353,
    6757,  1571,  1534,  1535,  6757,   164,  1536,  1537,  6757,   164,
    4013,   770, -1757, -1757, 11552,   270,  1870, -1757, -1757, -1757,
   -1757, -1757, -1757, -1757, -1757, -1757, -1757, -1757, -1757,  9887,
   -1757, -1757, -1757, -1757, -1757, -1757, -1757,  9887,  9887,  9887,
   -1757,  9116, -1757, -1757, -1757, -1757,  8148, -1757, -1757,  9887,
   -1757,  6757,  8148,  8148,  8148, -1757, -1757, -1757, -1757, -1757,
   -1757, -1757, -1757,  9887,  8148, -1757,  8148, -1757,  9887, -1757,
   -1757, -1757, -1757,  -173,  -173,  1578, -1757,  9887,  1579,  -173,
    -173,  1580,    45,  9887,  1581,  1583,   616, -1757,  1584,  1372,
      25,  1587, -1757,  9116,  9116,  9116,  9116, -1757,   495,  9887,
   -1757,  1380,  1381,  1371, -1757,  1589, -1757, -1757, -1757, -1757,
   -1757,   410,   437, 12572, 11575, -1757, -1757,  1395,  8148,   586,
   12593, 11598, -1757,   615, 10308, -1757, -1757, -1757,    68, -1757,
   -1757,  6025,   495,  -136,  2759, -1757,   908,  6757,  6757,  1593,
    6757,   912,  6757,  6757,  1594,  1512,  6757,  6757,  6757,  6757,
     842,  1596,  1598,  9116, -1757,  1383,  1601,  1602,  3232, -1757,
   -1757,  1604, -1757,  1605,   453,  9887,   453,  9887,   453,  9887,
     453,  9887,  1606,  1616,  1617,  1618,  1619,   784,  1607,  7237,
   -1757, -1757,   265, 10334, 10360, -1757, -1757,  4164,  -124,  -136,
    -136,  -136,  1627,  9678,  1409,  1632,  1423,    40,    41,    47,
      75,   716, -1757,   268, -1757,   562,  1634,  1636,  1639,  1640,
    1641,  1642,  1643,  1645,  1648, 12740, -1757,   966,  1431,  1637,
    1651,  1652,  1585,  1666,  1668,  1670,  9887,   213,  -141,   785,
     797, -1757,   804, -1757, -1757,  9887,  9887, -1757,  9887,  9887,
   -1757,  9887,  9887,  9887,   834,   870,   876,   877, -1757,  9887,
     880,   213,   213,   884,  6757,  6757,  6757,  1691, 10386, -1757,
    3165,   367,  1694,  1695,  1472, -1757,  1477, -1757,  1462,  1478,
    6757,  1479, -1757,  -173,  -173,  1698,  9887,  1714,  -173,  -173,
    1720,  9887,  1723, -1757,   495,  1724, -1757,  1727, -1757,  1726,
    6025,  6025,  6025,  6025,   733,  1516,  9053,  1519,   495,   495,
    1518,   743,   747, 12614,  1520,   495,  6025,  1570,  8148, -1757,
    1482, -1757,  1570,  8148, -1757,   189,  1521,  1736,  1647, -1757,
   -1757, -1757,    25,  9887, -1757,   888, -1757,   894,   920,   921,
     932,   453, 12740,  1528,  9887,  9887,  6757,  1527, -1757, -1757,
   -1757, -1757,  1531, -1757,  1728,    22, -1757, -1757,  1740,  9887,
    5824,  1539,  1533,  1747,  1748,     9,  1540,  1542,  1626,  1626,
    6757,  1751,  1544,  1545,  1752,  1754,  6757,  1550,  1763,  1768,
    1769,  1770, -1757,  1772,  6757,   938,  6757,  6757,  6757,  1775,
    1774, -1757,  6757,  6757, 12740,  6757, 12740,  6757, 12740,  6757,
   12740,  6757,  6757,  6757,  1558,  1559,  1778,   726, -1757,  9887,
    9887,  9887,  1567,  1572,  -129,   -96,   -68,  1586, -1757,  1690,
    6757, -1757,  9887, -1757,  1790, -1757,  1791, -1757,  1797, -1757,
    1799, -1757, -1757,  1805,   781,  6542, -1757,  1588,  1590,  1595,
    1620,  1644,  1646,  8477, -1757,  9116, -1757, -1757, -1757,  1649,
    9887, -1757, -1757, 11621,  1803,   495,  1600,  1591, 10412, 10438,
   10464, 10490, 10516, 10542, 10568, -1757, -1757, -1757, -1757, 12740,
   -1757,   495,  1806,  1857,  1707, -1757,  9887,  9887,  9887, -1757,
    1862,   793,  4705, -1757, -1757, -1757,  1654,  1864,  1570,  8148,
   -1757,  1760, -1757,  1570,  8148, -1757,  1972, -1757,   453, -1757,
     471, -1757, -1757, -1757, -1757, -1757, -1757,  8148,  9887, -1757,
   -1757, -1757, -1757,  8148,  1867, -1757, -1757,    99, -1757, -1757,
   -1757, -1757, -1757, -1757,  1875,  -118,  -118, -1757,  1876,  -118,
    -118,  4705,  9887,  1877,  1869,    33, -1757,  1895, 11644,    25,
   -1757,  1896,  1897,  1898,  1900,  6757,  9887, 10594, 10620,   960,
   -1757,  9887,  1903, -1757, -1757,  8148, -1757, 10646,  5394, 12740,
   -1757,  1901,  1902, -1757, -1757, -1757,  9887,  9887,  -136,  1904,
    1906,  1907, -1757,  9887,  9887, -1757, -1757,  1917,  9887, -1757,
   -1757, -1757, -1757,  1919,  1920,  1702,   961,  1925,  1771,  9887,
   -1757,  1927,  1928,  1932,  1933,  1935,  1936,  1182,  1937,  9116,
    9116,  9887, -1757,  8907,  4371, 12635,  3329,   424,   424,  -136,
    1939,  -136,  1940,  -136,  1941,  9887, -1757,   139,  1749, 12656,
   -1757, -1757, -1757, -1757,  4590,   340, -1757,  1942,  1943,  6757,
    -136,  -136,  -136,  -136,  -136,  4903,  1944,   965,  9887,  1992,
    1968,   213, -1757, -1757, -1757,  9887,  9887,  9887,  9887,  9887,
    9887,  9887, -1757, -1757, -1757,  6757,  3368,   465, 12677, -1757,
   -1757,  5897,  1755,  4317,  4317,  6757, -1757,  1973,  -118,  -118,
   -1757,  1974,  -118,  -118, -1757,  6757, -1757,  1765,  6025,   495,
    5609,  6112,  4705, -1757,  1977,  1978, -1757,  1981,  1982,  1993,
    2115, -1757,  1997,  2001, -1757,  1788, -1757, -1757, -1757, -1757,
   -1757,  2003,   628, 12740,  9887,  9887,  6757,  1787,   975, 12740,
   -1757,  2008,  9887, -1757, -1757,  1792,  1794,  4656,  4802,   664,
   -1757, -1757, -1757,  4840,  4933, -1757,  5064,  2013, -1757,  6757,
    2014, -1757,  1931,  2016, 12740, -1757, -1757, -1757, -1757, -1757,
   -1757,  1800, -1757, -1757,   976,   984,  9016,  2160,  2019,  1804,
   -1757,  9887, -1757,  1817,  1819,   405, -1757,  1821,   409, -1757,
    1823,   412, -1757,  1827, 11667,  2045,  6757,  2047,  1829,  9887,
   -1757, -1757,   990,   423,   436,   475,   481,   486,  8692,   514,
   -1757,  2049,  5120, -1757, -1757,  6025,  6025, 10672, 10698, 10724,
   10750, 10776,  1908,  9887, -1757,  9887, -1757, -1757,  9116,  2427,
    2050,  4705,  1833,  1834,  1836, -1757,  2057,  2059, -1757,  2060,
    2061,  2062, -1757, -1757, -1757,  5165, -1757, -1757,  8148, 12740,
   -1757, -1757, -1757, -1757, -1757, -1757, -1757, -1757,    25, -1757,
    1910, -1757, -1757,  9887, 10802, 10828, -1757,  6757,  9887,  2064,
   -1757, 10854, -1757, -1757,  6757,  6757,  2070,  2071,  2072,  2073,
    2074,  2075,   991, -1757,  1866, -1757,  6757,   206,   502,  9116,
   -1757, -1757,   424,  3711, -1757, -1757,  1805,   562,  1805,   562,
    1805,   562,  2081, -1757,  1024,  6757, -1757,  5293,  2085,  9116,
    -136,  -136,  -136,  -136,  -136, -1757, -1757, -1757, -1757,  9887,
    9887,  9887,  9887,  9887,  9887,  5508,  5546,  1030, -1757, -1757,
    1878,  1871, -1757,  2090, -1757, -1757, -1757, -1757, -1757,  1031,
    1151,  2091,  1034,  2093, -1757,  1874, 12740,  9887,  9887,  1042,
   12740, -1757,  9887,  1048,  1052, -1757, -1757, -1757, -1757, -1757,
   -1757, -1757, -1757,  1879,  9887,  1062,  1881,  -136,  6757,  2094,
    1887,  -136,  2095,  1066,  1891,  9887, -1757,  5782,   517,   977,
    5854,   521,  1157,  5997,   524,  1195, -1757,  6757,  2116,  2009,
    7452,  1905, -1757,  1067,   534,   547,   552,   587,   589, 10880,
   10906, 10932, 10958, 10984,  2491, -1757, -1757,  2118,  2120, -1757,
   -1757,  9887, -1757,  4705,    21, -1757, -1757,  9887, 12698, 11010,
      60, 11036, -1757, -1757, -1757, -1757,  9887,  6226,  2121,  -136,
      82, -1757, -1757,  -136,   110, -1757,  2125, -1757,  6441,  2126,
    9887,  2127,  2128,  9887,  2131,  2133,  9887,  2134,  1918, -1757,
    9887, -1757,   562, -1757,  2135,  9116,  9116,  9116,  9116,  8692,
    9887,  9887,  9887,  9887,  9887, -1757, -1757, -1757,  4317,  1509,
   -1757,  1930,  1074, -1757,  9887, -1757,  6757,  9887,  1082,  1083,
   11062, -1757, -1757,   621, -1757,   627, -1757, -1757, -1757, -1757,
    1921,  6656, -1757, -1757,  1924,  6871, -1757, -1757,  1926,  7086,
   -1757,  2137,  2725,  1260,  7667, -1757,  1086,  1094,  1103,  1112,
     629,  1119, 11088, 11114, 11140, 11166, 11192,  1929,  4705,  1934,
    2142,  1938, 12719,  1122,  7301, -1757, -1757,  9887,  -136,  -136,
     562,  2144,   562,  2146,   562,  2150, -1757, -1757, -1757, -1757,
     562,  2151,  2152,  2154,  2156,  9116,  2158,  9887,  9887,  9887,
    9887,  9887,  2159, -1757, -1757, -1757,  8148, -1757,  1960,  2161,
    7516,   633,   650,  1319, -1757,  1961,  1421, -1757,  1962,  1656,
   -1757,  1963,  1858, -1757, -1757, -1757, -1757,  1141, -1757,  6025,
   11218, 11244, 11270, 11296, -1757,  1145, -1757,  1965,  6757, -1757,
    2197,  9887,  9887,  2202,   562,  2204,   562,  2206,   562, -1757,
    2207, -1757,  9887,  9887,  9887,  9887,  8148,  2208,  8148,  1149,
   -1757,  8376,  8414, -1757,  2283, -1757,  2378, -1757,  2685, -1757,
    8591,  8629,  8792,  8820, -1757, -1757,  1153, -1757,  2209,  2210,
    2211,  2215,  2217,  2218, -1757, -1757, -1757, -1757,  8148,  2219,
   -1757, -1757, -1757, -1757, -1757, -1757, -1757, -1757
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1757, -1757, -1757, -1757,   944, -1757, -1757, -1757, -1757,   313,
   -1757, -1757, -1757, -1757, -1757, -1757, -1757, -1757, -1757, -1757,
   -1757, -1757,  -393,    12,  4151,  3383, -1757,  1742, -1757, -1757,
   -1757, -1757, -1757, -1757, -1757, -1756, -1757,   461, -1757, -1757,
   -1757, -1757, -1757, -1757,   934,  2232,    -1,  -541,  -275, -1757,
   -1757, -1757, -1757, -1757, -1757, -1757, -1757,  2233, -1757, -1757,
   -1757, -1757, -1757, -1757, -1757, -1757, -1757, -1757, -1757, -1757,
   -1757, -1140, -1134,  2234, -1581,  2235, -1757, -1757, -1757,  1715,
   -1757,   452, -1757, -1757, -1757, -1757,  1880, -1757, -1757,  1456,
   -1757, -1290,  2573,  -157,  3102,  3357,  -267,   778, -1757,   103,
     111, -1757,  -406,    -3,    30
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -548
static const yytype_int16 yytable[] =
{
     120,   541,   103,   205,   689,  1364,   691,  1362,   560,   368,
     843,   844,  1732,  1733,   576,  1495,  1853,  1040,  1202,   603,
     384,   706,   719,  1056,   579,   352,  1516,   447,  1484,   341,
     297,   207,   605,   121,   607,   235,   206,  1029,   235,   285,
     302,   345,   303,   222,   600,   223,  1353,  1355,   358,  1255,
     721,   268,   725,  1357,   728,   360,   901,   903,   230,   230,
     209,   300,   905,   907,     5,   211,  1975,   269,   270,   335,
     272,   273,   380,   381,   300,  1290,     4,   549,   550,  1384,
     274,  1359,   549,   550,   641,   300,   643,   275,  1984,   515,
     516,   517,   651,  1539,   301,  1540,   522,   523,   524,   882,
    1343,   883,   210,  1611,   771,   549,   550,   344,   375,   203,
     549,   550,   594,  1016,   595,   213,  1986,   204,   354,   286,
     304,   727,   551,   287,   549,   550,  1541,   226,  1542,   288,
     289,   290,   291,   383,   227,   629,   572,   573,   549,   550,
     199,   552,   292,   549,   550,   366,   371,   619,   372,   214,
     585,   586,   367,   208,  1543,   373,  1544,   549,   550,   563,
     562,  1041,  1042,  1043,  1044,   475,   564,   476,  1978,  1979,
     293,  1016,   294,   838,   373,   604,   549,   550,   226,   380,
     381,   448,   449,   215,   238,  1033,  1354,  1356,   606,  -541,
     608,  1036,   845,  1358,   300,   298,  1461,   452,   216,   353,
     601,   357,   723,  1256,  1257,   217,   483,   483,   376,   377,
     378,   720,   942,    97,   483,   549,   550,    97,    97,   369,
    1057,  1360,   300,   218,   335,  1057,   370,   450,   577,   335,
    1362,  1203,   385,   335,   386,   199,   387,  1045,   335,   484,
     484,   199,   335,   335,   335,   335,   483,   484,   342,   299,
     335,   335,   335,   346,   236,   492,  1030,  1035,   335,   335,
     335,   944,   602,   948,   335,   300,   359,   836,   837,  1702,
     231,   231,  1612,   361,   902,   904,   242,   232,  1034,   484,
     906,   908,   212,  1976,  1291,   219,  1292,   852,   549,   550,
     335,   335,   335,   946,   376,   377,   378,   379,   344,   376,
     377,   378,   379,   220,   335,   335,   457,   376,   377,   378,
     379,   221,   481,   485,   380,   381,   549,   550,   228,   380,
     381,   335,   241,   335,  1866,  1867,  1022,   380,   381,  1017,
    1868,   264,   229,  1023,   265,   491,   458,   459,   460,   461,
     462,   463,   464,   465,   466,   467,   468,   620,   470,   471,
     253,   233,   518,   254,   472,   255,   925,   376,   377,   378,
     379,   234,   483,  1695,   549,   550,   335,   335,   882,  1782,
     883,   934,   644,   981,   645,  1408,   592,   380,   381,   335,
     851,   199,   376,   377,   378,   379,   243,  2017,   376,   377,
     378,   724,   781,   244,   782,   484,   380,   381,   376,   377,
     378,   943,   380,   381,   237,   759,  -546,   483,   483,   483,
     483,   483,   483,   483,   483,   483,   483,   335,   483,   483,
     238,   483,   483,   483,   483,   483,   380,   381,   451,   483,
     483,   483,   483,   483,   300,   307,   300,   781,   308,   787,
     484,   484,   484,   484,   484,   484,   484,   484,   484,   484,
     239,   484,   484,   335,   484,   484,   484,   484,   484,   729,
    1016,   240,   484,   484,   484,   484,   484,   716,   649,   718,
     245,   549,   550,  1725,   549,   550,   622,  1849,   623,   376,
     377,   378,   947,   380,   381,   373,   660,  1339,   380,   381,
    1363,   335,   772,  -544,  1174,   773,  1865,   458,   459,   460,
     461,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,   781,   251,   791,   690,   472,   692,   693,   694,   695,
     696,   697,   698,   775,   700,   701,   773,   703,   704,   705,
     781,   707,   799,   335,   335,   711,   712,   713,   714,   715,
     249,   709,    52,    53,    54,    55,   549,   550,   250,   717,
     452,   452,  1216,   882,    63,   883,  1221,    66,   763,   884,
    1119,   256,  1699,   764,   458,   459,   460,   461,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,   252,   335,
     335,   335,   472,   246,  1409,   266,   247,   280,  1002,   248,
     281,   335,   335,   282,   267,   483,   458,   459,   460,   461,
     462,   463,   464,   465,   466,   467,   468,   469,   470,   471,
     335,   549,   550,   271,   472,   549,   550,   335,   549,   550,
    1870,  1871,  1261,   380,   381,   891,  1868,  1796,   484,   549,
     550,  1798,   295,  -545,  1800,   296,   335,   814,   817,   820,
     823,   279,   549,   550,   305,  1809,   376,   377,   378,   379,
     380,   381,   781,   940,   911,   941,   335,  1879,  1810,  1882,
    -543,  1885,   458,   459,   460,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   470,   471,  1132,   882,   957,   883,
     472,   549,   550,   918,   380,   381,  2023,   549,   550,  1726,
    1133,   767,   549,   550,  -547,   306,   768,  1811,  1134,  1135,
    1136,   894,   351,  1812,  1137,  1138,  1139,  1140,  1813,   272,
     273,  1323,   882,  1325,   883,  1327,   309,  1329,   335,   274,
     549,   550,   335,   549,   550,   310,   283,   549,   550,   338,
     549,   550,  1532,  1533,  1018,   647,  1814,   648,  1024,  1940,
     549,   550,   311,  1943,   373,  1362,  1946,   261,  1362,   337,
     262,  1362,   263,   549,   550,   765,  1955,   766,   549,   550,
     339,   335,   770,  1264,   373,   335,   340,   771,   483,  1956,
     882,   300,   883,   483,  1957,  1006,   347,   335,   335,   458,
     459,   460,   461,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,   549,   550,   549,   550,   472,  2109,  1590,
    1591,   484,   998,  1285,  1068,   335,   484,   771,   781,  1958,
     348,  1959,  2003,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   549,   550,   335,
    1132,   472,  1288,   549,   550,   549,   550,   781,  1025,   549,
     550,  1455,  1456,  2028,  1133,  1762,  1459,  1460,  1312,  2029,
    1763,  2045,  1134,  1135,  1136,  2091,   549,   550,  1137,  1138,
    1139,  1140,  1462,   349,   467,   468,   469,   470,   471,  1362,
     549,   550,  2092,   472,  1066,   469,   470,   471,  1475,  1070,
     350,   335,   472,   335,   355,   781,   335,  1038,   365,  1072,
    2063,   413,  2066,   957,  2069,  1132,   781,   414,  1115,   335,
    2072,   335,   415,   335,   590,   335,   591,   420,   592,  1133,
     335,   198,   760,   199,   761,   335,   762,  1134,  1135,  1136,
     781,   199,  1116,  1137,  1138,  1139,  1140,   427,   257,  1362,
     431,   258,  1362,   432,   259,  1362,   260,   335,  1362,   433,
    1361,   335,   882,   609,   883,   335,   610,  1008,   434,   611,
     882,   612,   883,   483,  2114,   781,  2116,  1217,  2118,   439,
     882,  1222,   883,   455,   882,  1444,   883,  1226,  1228,  1447,
     437,   781,  1374,  1161,   781,   781,  1162,  1163,   335,   781,
    1362,  1188,  1362,   483,  1362,   781,   484,  1204,   335,   483,
     483,   483,   781,   438,  1224,  1467,  1683,  1684,  1296,   456,
    1297,   483,  1302,   483,  1303,  1556,   781,   781,  1336,  1385,
     473,   474,  1598,  1599,   478,   500,   484,  1602,  1603,   781,
     539,  1386,   484,   484,   484,   505,   781,   300,  1387,   512,
     335,   335,   335,   335,   484,  1605,   484,   513,   520,   458,
     459,   460,   461,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,     7,     8,   483,   781,   472,  1395,  1229,
     344,   521,   525,  1279,  1280,   463,   464,   465,   466,   467,
     468,   469,   470,   471,   335,   335,   526,   335,   472,   335,
     335,   527,   528,   335,   335,   335,   335,   529,   484,  1235,
     335,  1132,   781,   578,  1396,  1238,  1239,  1240,   781,   781,
    1397,  1398,   781,   565,  1400,  1133,   781,  1244,  1401,  1245,
    1469,   566,  1470,  1134,  1135,  1136,   781,   373,  1471,  1137,
    1138,  1139,  1140,   536,   542,   734,    24,    25,   735,    27,
      28,   736,    30,   737,    32,    33,   543,   554,  1593,    34,
    1594,    35,   781,   781,  1472,  1473,    40,    41,    42,    43,
     555,    45,    46,    47,   781,   567,  1474,    50,  1913,   619,
     781,  1284,  1515,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   556,   568,  1226,
    1228,   472,  1636,  1636,  1637,  1660,  1671,   781,  1672,  1711,
     569,   335,   335,   335,    74,    75,    76,  1768,   781,  1769,
    1787,  1941,  1626,  1279,  1280,   570,   781,   335,  1788,   571,
     122,   362,  1636,  1636,  1808,  1863,   125,   126,   127,   575,
     580,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   483,   483,  1887,   581,  1888,   483,
     483,  1874,   781,  1911,  1907,  1912,   771,   587,  1915,   300,
     160,   161,   162,   163,  1636,   870,  1920,  1463,   168,   582,
    1444,  1132,  1922,   335,  1447,   588,  1923,   484,   484,   173,
     174,   175,   484,   484,  1636,  1133,  1928,   176,   781,   781,
    1936,  1954,   344,  1134,  1135,  1136,  1768,   335,  2020,  1137,
    1138,  1139,  1140,   335,  1444,  1444,  2025,  2026,   781,  1132,
    2041,   335,   583,   335,   335,   335,   781,   589,  2042,   335,
     335,   584,   335,  1133,   335,   781,   335,  2043,   335,   335,
     335,  1134,  1135,  1136,   781,   621,  2044,  1137,  1138,  1139,
    1140,   781,  1842,  2046,  1636,   625,  2058,   335,   458,   459,
     460,   461,   462,   463,   464,   465,   466,   467,   468,   780,
     470,   471,   335,   781,   632,  2100,   472,  2106,   199,  2107,
     335,  1636,   335,  2128,  1132,  2138,   637,  2139,   367,   631,
     638,  1944,   639,   179,   640,   642,   658,   183,  1133,   659,
     662,   184,   185,   186,   187,   188,  1134,  1135,  1136,    97,
     666,  1490,  1137,  1138,  1139,  1140,   663,   472,   731,   730,
     198,   796,   777,   191,   192,   483,   483,   733,   193,  1947,
     483,   483,   778,   325,   800,   801,   802,   803,   197,   807,
     537,   808,   825,  1132,   483,   827,   829,   833,   834,   835,
     483,   862,  1606,   864,   896,   865,   867,  1133,   484,   484,
     874,   875,   881,   484,   484,  1134,  1135,  1136,   923,   898,
     899,  1137,  1138,  1139,  1140,   900,   300,   484,  1414,   926,
     935,   939,   335,   484,   952,   953,   984,   986,   985,   989,
     991,  1012,   483,  1005,  2038,   335,   992,   993,  1457,  1003,
    1004,  1843,  1010,  1011,  1013,  1014,  1019,  1020,  1027,   344,
    1028,  1055,  1073,  1076,  1062,  1065,  1067,  1069,  1081,   276,
     278,  1077,   284,  1078,  1080,   484,  2018,  1082,  1083,  1085,
    1086,  1087,  1088,  1592,  1089,  1093,   335,   335,  1094,  1100,
    1095,  1890,  1102,  1104,  1105,  1132,   452,   452,  1106,  1107,
    1607,  1108,  1109,  2093,  1110,  1111,  1609,  1156,  1118,  1133,
    1125,  1171,  1173,  1194,  1126,  1179,   335,  1134,  1135,  1136,
    1181,  1182,   335,  1137,  1138,  1139,  1140,  1183,  1195,  1196,
    1197,  1206,  1619,  1209,   480,   124,  1210,  1212,  1213,  1214,
    1218,  1219,   335,  1606,  1249,  1251,  1254,  1259,  1641,  1260,
    1263,  1262,   335,  1266,  1276,  1278,  1274,  1275,  1283,  1644,
    1300,  1306,   335,  1313,  1307,  1314,  1316,   335,  1317,  1318,
    1321,  1337,  1322,  1331,   151,   152,   153,   154,   155,   156,
     157,   158,   159,  1332,  1333,  1334,  1335,   164,   165,   166,
     167,  1347,  1350,   335,  1968,   169,   170,   171,  1351,  1352,
     172,  1365,  1366,  1376,  1678,  2095,  1367,  1368,  1369,  1370,
    1371,   177,  1372,  1466,  1375,  1373,   335,  1377,  1378,   458,
     459,   460,   461,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,  1380,  1381,  1379,  1382,   472,  2004,   458,
     459,   460,   461,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,   335,  1412,  1405,  1546,   472,  1410,  1411,
    1413,  1415,  1730,  1417,  1420,   335,   458,   459,   460,   461,
     462,   463,   464,   465,   466,   467,   468,   469,   470,   471,
    1422,  1747,  1750,  1751,   472,   335,  1425,   544,   545,  1427,
    1429,  1430,  1431,  1498,  1483,   553,  1440,  1451,  1437,   561,
    1443,  1464,   335,  1465,  1476,   483,  1486,   180,   181,   182,
    1481,  1482,  1492,  1493,  1494,   300,  1491,  1502,  1505,   189,
    1506,   190,    97,  1496,   335,  1497,  1600,  1503,  1504,  1509,
    1132,   335,   335,  1508,  1510,  1511,  1512,  1513,   484,  1519,
    1520,  1529,  1530,   335,  1133,  1531,   335,   882,   344,   883,
    1537,   452,  1134,  1135,  1136,  1538,  1550,  1551,  1137,  1138,
    1139,  1140,   335,  1552,  1545,  1553,   335,  1571,   122,   362,
    1574,  1559,  1583,  1560,   125,   126,   127,  1573,  1561,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,  1830,  1562,   458,   459,   460,   461,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,   160,   161,
     162,   163,   472,  1584,  1585,   335,   168,  1563,  1589,  1564,
    1596,  1610,  1568,  1622,   480,   124,  1595,   173,   174,   175,
    2097,  1613,  1616,  1621,   335,   176,   201,   458,   459,   460,
     461,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,  1624,  1627,  1628,  1629,   472,  1630,  1640,  1645,  1646,
    1650,   300,  1651,  1652,   151,   152,   153,   154,   155,   156,
     157,   158,   159,  1655,  1657,  1659,  1658,   164,   165,   166,
     167,  1661,  1662,  1665,  1666,   169,   170,   171,  1667,  1668,
     172,  1669,  1670,  1673,  1971,  1686,  1689,  1692,  1700,  1701,
    1710,   177,   335,   335,   335,   335,   335,   458,   459,   460,
     461,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,  1696,  1132,   335,  1714,   472,   363,  1731,  1604,  1735,
    1738,   179,  1742,  1752,  1753,   183,  1133,  1754,  1755,   184,
     185,   186,   187,   188,  1134,  1135,  1136,    97,  1713,  1756,
    1137,  1138,  1139,  1140,  1758,   841,   842,  1759,  1760,  1761,
    1767,   557,   558,   545,  1770,  1774,   193,  1775,  1781,  1784,
    1783,   559,  1785,  1786,  1970,  1791,   197,  1792,   275,   460,
     461,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,  1794,   335,  1795,  1797,   472,  1799,   180,   181,   182,
    1801,  1803,  1806,   483,  1805,  1815,  1829,  1831,  1832,   189,
    1833,   190,    97,  1834,  1824,  1835,  1836,  1837,  1838,  1844,
    1851,   440,   441,   442,   444,   446,  1857,  1858,  1859,  1860,
    1861,  1862,  2099,   380,   381,   335,   484,  1886,   479,  1864,
    1227,  1892,   486,  -542,  1909,  1908,  1910,  1917,  1914,  1916,
    1932,  1935,  1926,   483,  1929,   483,   493,   495,   498,   499,
    1933,   501,   495,   503,   504,  1937,   495,   507,   508,   509,
     510,  1757,  1949,  1950,  1966,   495,  1967,  1982,  1953,  2053,
     519,  1987,  1989,  1992,  1993,   483,   484,  1996,   484,  1997,
    2000,  2005,  2001,  2036,  2030,   538,  2019,  2032,  2055,  2034,
    2064,  2054,  2067,  2052,   547,   548,  2070,  2073,  2074,  2086,
    2075,  2056,  2076,   548,  2078,  2084,  1790,  2089,   484,   458,
     459,   460,   461,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,  2088,  2094,  2096,  2098,   472,  2108,   458,
     459,   460,   461,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,  2110,   614,   616,   495,   472,  2113,  2124,
    2115,  2127,  2117,  2119,  2125,  2140,  2141,  2142,   626,   627,
     628,  2143,   630,  2144,  2145,  2147,   633,   634,   635,  1485,
    1972,   636,   776,  1500,  1854,   102,   112,   113,   114,   810,
    1872,  2146,     0,  1623,     0,     0,   650,     0,     0,     0,
       0,   655,   657,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   664,   665,     0,   667,   668,
     669,   670,   671,   672,   673,   674,   675,   676,   677,   678,
     679,   680,   681,   682,   683,   684,   685,   686,   687,   688,
       0,     0,     0,     0,  1122,     0,     0,     0,     0,     0,
       0,  1128,     0,   702,     0,     0,     0,  1143,     0,   708,
       0,   710,   458,   459,   460,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   470,   471,     0,     0,     0,     0,
     472,     0,     0,     0,     0,   739,   495,     0,   741,   742,
     743,   744,   745,   746,   747,   748,   749,   750,   751,   752,
     753,   754,   755,     0,     0,   757,   758,   458,   459,   460,
     461,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,     0,     0,     0,   614,   472,     0,     0,     0,     0,
     785,     0,     0,     0,     0,   790,     0,     0,     0,     0,
       0,     0,   797,   798,     0,     0,     0,  1132,     0,     0,
     805,   806,     0,     0,     0,   811,   813,   816,   819,   822,
     824,  1133,   826,     0,   828,     0,   495,   495,     0,  1134,
    1135,  1136,     0,     0,     0,  1137,  1138,  1139,  1140,     0,
       0,     0,     0,  1828,   846,   847,   848,   440,   441,   849,
       0,     0,     0,   853,   854,   855,   856,   857,   858,   859,
     860,   861,     0,     0,     0,   866,     0,   868,   869,     0,
       0,     0,   495,   495,   495,     0,     0,   876,   877,   878,
     879,   880,     0,   619,   887,   887,   892,   893,     0,   895,
       0,     0,   897,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1132,   495,     0,     0,     0,  1965,     0,   912,
     914,     0,   916,   917,     0,     0,  1133,  2131,     0,     0,
       0,     0,     0,     0,  1134,  1135,  1136,     0,     0,   495,
    1137,  1138,  1139,  1140,   879,   880,     0,   916,   917,  1295,
       0,     0,     0,     0,     0,     0,     0,     0,   950,   495,
       0,     0,     0,   954,     0,   122,   362,     0,     0,     0,
       0,   125,   126,   127,     0,     0,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,     0,
       0,     0,     0,     0,     0,  1344,  1345,  1346,     0,     0,
       0,     0,     0,     0,     0,   160,   161,   162,   163,     0,
       0,     0,  2132,   168,     0,     0,     0,     0,  1026,     0,
       0,     0,     0,     0,   173,   174,   175,     0,     0,     0,
       0,     0,   176,     0,   458,   459,   460,   461,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,     0,     0,
    1053,  1054,   472,     0,   495,  1060,  1061,     0,   495,  1064,
       0,     0,     0,     0,     0,     0,     0,  1071,     0,     0,
     914,  1074,   458,   459,   460,   461,   462,   463,   464,   465,
     466,   467,   468,   620,   470,   471,  1090,     0,     0,     0,
     472,     0,     0,     0,     0,     0,     0,  1098,   458,   459,
     460,   461,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,     0,     0,     0,     0,   472,     0,     0,     0,
       0,     0,   495,     0,     0,     0,     0,     0,   179,  1123,
    1124,     0,   183,     0,     0,  1127,   184,   185,   186,   187,
     188,  2037,     0,     0,    97,     0,     0,     0,     0,     0,
       0,     0,  1155,     0,     0,  1157,     0,     0,   191,   192,
       0,     0,     0,   193,     0,     0,     0,     0,   325,   443,
       0,     0,     0,   197,   495,     0,   495,   619,     0,   495,
     461,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,     0,   495,     0,   495,   472,   495,     0,   495,     0,
       0,     0,     0,   495,     0,     0,     0,     0,   495,  1132,
       0,     0,     0,     0,  1198,     0,  1200,  1201,     0,     0,
       0,     0,     0,  1133,   511,     0,     0,  1208,     0,  1555,
       0,  1134,  1135,  1136,     0,     0,     0,  1137,  1138,  1139,
    1140,     0,     0,   927,   531,   533,   535,     0,     0,     0,
     540,     0,     0,     0,     0,     0,     0,     0,     0,  1230,
       0,     0,     0,     0,     0,     0,     0,  1231,  1232,  1233,
       0,   495,     0,     0,     0,     0,     0,     0,   574,  1236,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1039,     0,  1243,     0,     0,     0,     0,  1246,     0,
       0,     0,     0,     0,     0,     0,     0,  1250,     0,     0,
       0,     0,     0,  1258,     0,     0,     0,     0,     0,  2133,
       0,     0,     0,   495,   495,   495,   495,     0,     0,  1272,
       0,     0,   458,   459,   460,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   470,   471,     0,     0,     0,     0,
     472,     0,   652,   653,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1649,   661,   458,   459,   460,   461,
     462,   463,   464,   465,   466,   467,   468,   780,   470,   471,
       0,     0,     0,   495,   472,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1324,     0,  1326,     0,  1328,
       0,  1330,     0,   699,     0,  1685,     0,  1688,  1189,  1691,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1349,     0,     0,  1703,  1704,  1705,  1706,
    1707,  1709,   458,   459,   460,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   470,   471,     0,     0,     0,     0,
     472,     0,     0,     0,     0,     0,  1383,     0,     0,     0,
       0,     0,     0,     0,     0,  1388,  1389,     0,  1390,  1391,
       0,  1392,  1393,  1394,     0,     0,     0,     0,     0,  1399,
     458,   459,   460,   461,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   471,     0,     0,     0,     0,   472,     0,
       0,     0,     0,     0,     0,     0,  1421,     0,     0,     0,
       0,  1426,     0,     0,     0,     0,     0,     0,   122,   362,
       0,     0,     0,     0,   125,   126,   127,     0,     0,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,     0,  1468,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1477,  1478,     0,     0,   160,   161,
     162,   163,     0,     0,     0,     0,   168,     0,     0,  1487,
    1489,     0,     0,  1407,     0,     0,     0,   173,   174,   175,
       0,     0,     0,     0,     0,   176,     0,   458,   459,   460,
     461,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,     0,     0,     0,     0,   472,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1534,
    1535,  1536,     0,     0,     0,     0,     0,     0,     0,     0,
    1547,     0,  1549,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1554,     0,     0,     0,     0,     0,     0,
       0,     0,  1878,     0,  1881,   495,  1884,     0,     0,     0,
    1569,     0,     0,     0,     0,     0,  1894,  1895,  1896,  1897,
    1898,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   179,     0,     0,     0,   183,  1586,  1587,  1588,   184,
     185,   186,   187,   188,  1015,     0,     0,    97,  1021,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   191,   192,     0,     0,     0,   193,     0,  1608,     0,
       0,   325,     0,  1930,   445,     0,   197,  1934,     0,   496,
       0,     0,     0,     0,   496,     0,     0,     0,   496,     0,
       0,     0,  1620,     0,     0,     0,  1319,   496,     0,     0,
       0,     0,     0,     0,     0,     0,  1633,     0,     0,     0,
       0,  1639,   458,   459,   460,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   470,   471,  1647,  1648,     0,     0,
     472,  1099,     0,  1653,  1654,  1983,     0,     0,  1656,  1985,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1664,
       7,     8,     0,     0,     0,     0,     0,     0,     0,   495,
     495,  1676,     0,  1677,     0,  2010,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1694,   615,     0,   496,   458,
     459,   460,   461,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,     0,     0,   495,     0,   472,  1712,     0,
       0,     0,     0,     0,     0,  1715,  1716,  1717,  1718,  1719,
    1720,  1721,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1729,   734,    24,    25,   735,    27,    28,   736,    30,
     737,    32,    33,     0,  2061,  2062,    34,     0,    35,     0,
       0,  1749,     0,    40,    41,    42,    43,     0,    45,    46,
      47,     0,     0,     0,    50,     0,     0,     0,     0,     0,
       0,     0,     0,  1211,  1764,  1765,     0,  1215,     0,     0,
       0,  1220,  1771,     0,     0,     0,   458,   459,   460,   461,
     462,   463,   464,   465,   466,   467,   468,   469,   470,   471,
       0,    74,    75,    76,   472,     0,     0,     0,     0,     0,
       0,  1681,     0,  1682,     0,     0,     0,     0,   496,     0,
       0,  1793,     0,     0,  1237,   458,   459,   460,   461,   462,
     463,   464,   465,   466,   467,   468,   469,   470,   471,  1807,
       0,     0,     0,   472,   497,     0,     0,     0,   614,   502,
    1723,     0,  1724,   506,     0,     0,   615,     0,     0,     0,
       0,     0,   514,  1825,     0,  1826,     0,     0,   495,     0,
       0,     0,   932,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1840,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   496,   496,
       0,     0,     0,  1846,     0,     0,     0,     0,  1850,     0,
    1298,  1299,     0,  1301,     0,  1304,  1305,     0,     0,  1308,
    1309,  1310,  1311,     0,     0,     0,     0,     0,     0,   495,
       0,     0,     0,     0,     0,     0,  1877,     0,  1880,     0,
    1883,     0,     0,     0,   496,   496,   496,     0,     0,   495,
       0,     0,     0,     0,     0,     0,   888,   890,     0,  1899,
    1900,  1901,  1902,  1903,  1904,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   496,     0,     0,     0,     0,
       0,     0,   915,     0,     0,     0,     0,  1918,  1919,     0,
       0,     0,  1921,     0,     0,     0,     0,     0,     0,     0,
       0,   496,     0,     0,  1927,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1938,     0,     0,     0,     0,
       0,   496,     0,     0,     0,     0,     0,  1402,  1403,  1404,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1416,     0,     0,     0,     0,     0,     0,
       0,  1969,     0,     0,     0,     0,     0,  1639,     0,     0,
       0,     0,     0,     0,     0,     0,  1980,     0,     0,     0,
       0,     0,     0,   740,     0,     0,     0,     0,     0,     0,
    1991,     0,     0,  1995,     0,     0,  1999,     0,     0,     0,
    2002,     0,     0,     0,     0,   495,   495,   495,   495,   495,
    2012,  2013,  2014,  2015,  2016,     0,     0,     0,     0,  1480,
       0,     0,     0,     0,  2022,     0,     0,  2024,     0,     0,
       0,     0,     0,     0,     0,     0,   496,     0,     0,     0,
     496,     0,     0,  1501,     0,     0,     0,     0,     0,  1507,
       0,     0,   915,  1075,     0,     0,     0,  1514,     0,  1480,
    1517,  1518,     0,   830,   831,  1521,  1522,     0,  1523,     0,
    1524,     0,  1525,     0,  1526,  1527,  1528,  2060,   458,   459,
     460,   461,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,     0,  1548,     0,   495,   472,  2079,  2080,  2081,
    2082,  2083,     0,  1875,   496,  1876,     0,     0,  1558,   871,
     872,   873,     0,     0,     0,     0,  1566,   458,   459,   460,
     461,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,     0,     0,     0,     0,   472,     0,     0,     0,     0,
     909,  2111,  2112,     0,  1037,     0,     0,     0,     0,     0,
       0,     0,  2120,  2121,  2122,  2123,   496,     0,   496,     0,
       0,   496,     0,     0,     0,     0,   931,     0,     0,     0,
       0,     0,     0,     0,   496,     0,   496,   919,   496,     0,
     496,     0,     0,     0,     0,   496,   951,     0,     0,     0,
     496,     0,   458,   459,   460,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   470,   471,     0,     0,     0,     0,
     472,     0,     0,     0,     0,     0,     0,     0,  1631,  1092,
     958,   959,   960,   961,   962,   963,   964,   965,   966,   967,
     968,  1643,   970,   971,   972,   973,   974,   975,   976,     0,
       0,     0,   980,   982,   983,     0,     0,     0,   987,   988,
       0,   990,     0,   496,     0,     0,   995,   996,   997,     0,
     999,     0,     0,     0,     0,     0,     0,  1007,  1009,   458,
     459,   460,   461,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,     0,     0,  1032,     0,   472,     0,     0,
       0,  1059,     0,     0,     0,  1063,  1147,     0,     0,     0,
       0,     0,  1480,     0,     0,   496,   496,   496,   496,   458,
     459,   460,   461,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,     0,     0,     0,     0,   472,  1722,     0,
       0,     0,     0,     0,     0,     0,  1180,     0,  1734,     0,
       0,     0,   224,   225,     0,     0,     0,     0,  1741,     0,
       0,     0,     0,  1746,     0,     0,     0,     0,     0,  1117,
       0,     0,     0,     0,     0,   496,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1766,
     458,   459,   460,   461,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   471,     0,     0,     0,     0,   472,     0,
       0,     0,  1480,     0,     0,     0,     0,  1223,     0,     0,
       0,  1169,     0,  1170,     0,     0,  1172,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1184,
       0,  1185,     0,  1186,     0,  1187,     0,     0,     0,  1804,
    1190,   374,     0,     0,     0,  1193,     0,  1177,     0,     0,
     388,   389,   390,   391,   392,   393,   394,   395,   396,   397,
     398,   399,   400,   401,   402,   403,   404,   405,   406,   407,
     408,   409,   410,   411,   412,     0,     0,     0,   416,   417,
     418,   419,     0,   421,   422,   423,   424,   425,   426,     0,
       0,   428,     0,     0,     0,     0,     0,   429,   430,     7,
       8,     0,     0,   435,   436,     0,     0,     0,  1234,     0,
    1480,     0,     0,     0,     0,     0,     0,  1855,  1856,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1480,
       0,   458,   459,   460,   461,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   471,     0,     0,     0,  1889,   472,
       0,     0,     0,     0,     0,     0,     0,     0,  1342,     0,
    1267,  1268,  1269,  1270,     0,     0,     0,     0,     0,     0,
       0,   734,    24,    25,   735,    27,    28,   736,    30,   737,
      32,    33,     0,     0,     0,    34,     0,    35,     0,     0,
       0,  1271,    40,    41,    42,    43,     0,    45,    46,    47,
       0,     0,     0,    50,     0,     0,     0,     0,     0,     0,
       0,  1931,     0,     0,     0,     0,     0,     0,   937,     0,
    1315,     0,     0,     0,  1293,  1294,     0,     0,     0,     0,
    1948,     0,     0,   593,     0,     0,   596,   597,   598,   599,
      74,    75,    76,     0,     0,     0,     0,   496,     0,     0,
       0,     0,     0,     0,     0,     0,   624,     0,     0,   122,
     123,   124,     0,     0,     0,   125,   126,   127,     0,     0,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,     0,     0,     0,     0,     0,     0,     0,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,     0,  1480,
       0,   169,   170,   171,     0,     0,   172,     0,   173,   174,
     175,     0,     0,     0,     0,     0,   176,   177,   458,   459,
     460,   461,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,     0,     0,     0,     0,   472,     0,     0,     0,
       0,     0,     0,     0,     0,  1679,     0,     0,     0,     0,
       0,   732,     0,     0,     0,     0,     0,  1428,     0,     0,
       0,     0,     0,  1432,  1433,  1434,  1435,  1436,     0,  1439,
       0,  1441,  1442,     0,  1445,  1448,     0,     0,  1452,  1453,
    1454,   496,   496,     0,     0,  1458,     0,     0,     0,     0,
       7,     8,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   178,     0,     0,     0,     0,
       0,  1480,   179,   180,   181,   182,   183,   496,     0,     0,
     184,   185,   186,   187,   188,   189,     0,   190,    97,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   191,   192,     0,     0,     0,   193,     0,     0,
       0,     0,   194,     0,   195,     0,   196,   197,     0,   198,
     124,   199,   734,    24,    25,   735,    27,    28,   736,    30,
     737,    32,    33,     0,     0,     0,    34,     0,    35,     0,
       0,     0,  1567,    40,    41,    42,    43,     0,    45,    46,
      47,     0,     0,     0,    50,     0,     0,     0,     0,   151,
     152,   153,   154,   155,   156,   157,   158,   159,     0,     0,
       0,     0,   164,   165,   166,   167,     0,     0,  1572,     0,
     169,   170,   171,     0,     0,   172,     0,     0,     0,     0,
       0,    74,    75,    76,  1582,     0,   177,   458,   459,   460,
     461,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,  1597,     0,     0,     0,   472,  1601,     0,     0,     0,
     615,     0,     0,     0,  1698,   458,   459,   460,   461,   462,
     463,   464,   465,   466,   467,   468,   469,   470,   471,     0,
     496,     0,     0,   472,     0,     0,     0,     0,  1614,  1615,
       0,   646,  1617,  1618,     0,     0,     0,  1841,     0,     0,
       0,     0,   933,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,     0,     0,     0,
       0,   472,     0,     0,     0,     0,     0,     0,     0,     0,
    1776,     0,   180,   181,   182,     0,  1674,  1675,     0,     0,
       0,   496,     0,     0,   189,     0,   190,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   122,   312,     0,     0,
       0,   496,   125,   126,   127,     0,     0,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     314,   315,   316,   317,   318,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   160,   161,   162,   163,
       0,     0,     0,     0,   168,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   173,   174,   175,     0,     0,
       0,  1736,  1737,   176,     0,  1739,  1740,   319,     0,     0,
     320,  1743,  1744,   321,     0,   322,     0,     0,     0,   458,
     459,   460,   461,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,     0,   323,     0,     0,   472,     0,     0,
       0,    52,    53,    54,    55,    56,  1777,     0,    58,    59,
      60,     0,     0,    63,     0,     0,    66,   458,   459,   460,
     461,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,     0,     0,     0,     0,   472,     0,   496,   496,   496,
     496,   496,     0,     0,  1778,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   179,
       0,     0,     0,   183,     0,  1827,     0,   184,   185,   186,
     187,   188,     0,     0,     0,    97,     0,     0,  1817,  1818,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   557,
    1708,     0,     0,     0,   193,     0,     0,     0,     0,   559,
       0,     0,     0,     0,   197,     0,   275,   617,     0,     0,
     458,   459,   460,   461,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   471,     0,     0,  1873,   496,   472,     0,
       0,     0,     0,     0,     0,     0,     0,  1779,     0,     0,
       0,     0,     0,     0,  1247,  1248,  1893,     0,   122,   312,
    1252,  1253,     0,     0,   125,   126,   127,     0,     0,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   314,   315,   316,   317,   318,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   160,   161,
     162,   163,     0,     0,     0,     0,   168,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   173,   174,   175,
       0,     0,     0,     0,     0,   176,     0,     0,     0,   319,
       0,     0,   320,     0,     0,   321,     0,   322,     0,     0,
       0,   458,   459,   460,   461,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   471,     0,   323,     0,     0,   472,
       0,     0,     0,    52,    53,    54,    55,    56,  1780,     0,
      58,    59,    60,     0,     0,    63,     0,     0,    66,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2006,  2007,  2008,  2009,  2011,   458,   459,   460,
     461,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,     0,     0,     0,     0,   472,     0,     0,     0,     0,
       0,   179,     0,     0,  1816,   183,     0,     0,     0,   184,
     185,   186,   187,   188,     0,     0,     0,    97,     0,     0,
       0,     0,     0,     0,  1418,  1419,     0,     0,     0,  1423,
    1424,   191,   494,     0,     0,     0,   193,     0,     0,     0,
       0,   325,     0,     0,     0,     0,   197,     0,     0,   617,
       0,     0,     0,     0,     0,     0,     0,   122,   312,   124,
       0,     0,  2077,   125,   126,   127,     0,     0,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   314,   315,   316,   317,   318,     0,     0,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,     7,     8,     0,   169,
     170,   171,  2101,     0,   172,     0,   173,   174,   175,     0,
       0,     0,     0,     0,   176,   177,     0,     0,   319,     0,
       0,   320,     0,     0,   321,     0,   322,     0,     0,     0,
     458,   459,   460,   461,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   471,     0,   323,     0,     0,   472,     0,
       0,     0,    52,    53,    54,    55,    56,  1891,     0,    58,
      59,    60,     0,     0,    63,     0,     0,    66,   734,    24,
      25,   735,    27,    28,   736,    30,   737,    32,    33,     0,
       0,     0,    34,     0,    35,     0,     0,     0,     0,    40,
      41,    42,    43,     0,    45,    46,    47,     0,     0,     0,
      50,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     179,   180,   181,   182,   183,     0,     0,     0,   184,   185,
     186,   187,   188,   189,     0,   190,    97,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    74,    75,    76,
     191,   324,     0,     0,     0,   193,     0,     0,     0,     0,
     325,     0,   122,   312,   124,   197,     0,   326,   125,   126,
     127,     0,     0,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   314,   315,   316,   317,
     318,     0,     0,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,     0,     0,     0,   169,   170,   171,     0,     0,   172,
       0,   173,   174,   175,     0,     0,     0,     0,     0,   176,
     177,     0,     0,   319,     0,     0,   320,     0,     0,   321,
       0,   322,     0,     0,     0,   458,   459,   460,   461,   462,
     463,   464,   465,   466,   467,   468,   469,   470,   471,     0,
     323,     0,     0,   472,     0,     0,     0,    52,    53,    54,
      55,    56,  1905,     0,    58,    59,    60,     0,     0,    63,
       0,     0,    66,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,     0,     0,     0,
       0,   472,     0,     0,     0,     0,     0,     0,     0,     0,
    1906,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   179,   180,   181,   182,   183,
       0,     0,     0,   184,   185,   186,   187,   188,   189,     0,
     190,    97,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   191,   324,     0,     0,     0,
     193,     0,     0,     0,     0,   325,     0,   122,   362,   124,
     197,     0,  1745,   125,   126,   127,     0,     0,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,     0,     0,     0,     0,     0,     0,     0,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,     0,     0,     0,   169,
     170,   171,     0,     0,   172,     0,   173,   174,   175,     0,
     122,   362,   124,     0,   176,   177,   125,   126,   127,     0,
       0,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,     0,     0,     0,     0,     0,     0,
       0,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,     0,
       0,     0,   169,   170,   171,     0,     0,   172,     0,   173,
     174,   175,     0,     0,     0,     0,     0,   176,   177,   458,
     459,   460,   461,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,     0,     0,     0,     0,   472,     0,     0,
     179,   180,   181,   182,   183,     0,  1939,     0,   184,   185,
     186,   187,   188,   189,     0,   190,    97,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     191,   192,     0,     0,     0,   193,     0,     0,     0,     0,
     325,     0,     0,     0,     0,   197,     0,  1488,     0,     0,
       0,   458,   459,   460,   461,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   471,     0,     0,     0,     0,   472,
       0,     0,     0,   179,   180,   181,   182,   183,  1942,     0,
       0,   184,   185,   186,   187,   188,   189,     0,   190,    97,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   191,   192,     0,     0,     0,   193,     0,
       0,     0,     0,   325,     0,   122,   362,   124,   197,     0,
    1728,   125,   126,   127,     0,     0,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,     0,
       0,     0,     0,     0,     0,     0,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,     7,     8,     0,   169,   170,   171,
       0,     0,   172,     0,   173,   174,   175,     0,     0,     0,
       0,     0,   176,   177,   458,   459,   460,   461,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,     0,     0,
       0,     0,   472,     0,     0,     0,     0,     0,     0,     0,
       0,  1945,   458,   459,   460,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   470,   471,     0,     0,     0,     0,
     472,     0,   882,     0,   883,     0,   734,    24,    25,   735,
      27,    28,   736,    30,   737,    32,    33,     0,     0,     0,
      34,     0,    35,     0,     0,     0,     0,    40,    41,    42,
      43,     0,    45,    46,    47,     0,     0,     0,    50,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   179,   180,
     181,   182,   183,     0,     0,     0,   184,   185,   186,   187,
     188,   189,     0,   190,    97,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    74,    75,    76,   191,   192,
       0,     0,     0,   193,     0,     0,     0,     0,   325,     0,
     122,   312,   313,   197,     0,  1748,   125,   126,   127,     0,
       0,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   314,   315,   316,   317,   318,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     160,   161,   162,   163,     0,     0,  1120,     0,   168,     7,
       8,     0,     0,     0,     0,     0,     0,     0,     0,   173,
     174,   175,     0,     0,     0,     0,     0,   176,     0,     0,
       0,   319,     0,     0,   320,     0,     0,   321,     0,   322,
       0,     0,     0,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,     0,   323,     0,
       0,   472,     0,     0,     0,    52,    53,    54,    55,    56,
    1981,     0,    58,    59,    60,     0,     0,    63,     0,     0,
      66,   734,    24,    25,   735,    27,    28,   736,    30,   737,
      32,    33,     0,     0,     0,    34,     0,    35,     0,     0,
       0,     0,    40,    41,    42,    43,     0,    45,    46,    47,
       0,     0,     0,    50,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   179,     0,     0,     0,   183,     0,     0,
       0,   184,   185,   186,   187,   188,     0,     0,     0,    97,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      74,    75,    76,   191,   324,     0,     0,     0,   193,     0,
       0,     0,     0,   325,     0,   122,   312,  1557,   197,     0,
     326,   125,   126,   127,     0,     0,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   314,
     315,   316,   317,   318,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   160,   161,   162,   163,     0,
       0,  1121,     0,   168,     7,     8,     0,     0,     0,     0,
       0,     0,     0,     0,   173,   174,   175,     0,     0,     0,
       0,     0,   176,     0,     0,     0,   319,     0,     0,   320,
       0,     0,   321,     0,   322,     0,     0,     0,   458,   459,
     460,   461,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,     0,   323,     0,     0,   472,     0,     0,     0,
      52,    53,    54,    55,    56,  1988,     0,    58,    59,    60,
       0,     0,    63,     0,     0,    66,   734,    24,    25,   735,
      27,    28,   736,    30,   737,    32,    33,     0,     0,     0,
      34,     0,    35,     0,     0,     0,     0,    40,    41,    42,
      43,     0,    45,    46,    47,     0,     0,     0,    50,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   179,     0,
       0,     0,   183,     0,     0,     0,   184,   185,   186,   187,
     188,     0,     0,     0,    97,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    74,    75,    76,   191,   324,
       0,     0,     0,   193,     0,     0,     0,     0,   325,     0,
     122,   312,     0,   197,     0,   326,   125,   126,   127,     0,
       0,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   314,   315,   316,   317,   318,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     160,   161,   162,   163,     0,     0,  1144,     0,   168,     7,
       8,     0,     0,     0,     0,     0,     0,     0,     0,   173,
     174,   175,     0,     0,     0,     0,     0,   176,     0,     0,
       0,   319,     0,     0,   320,     0,     0,   321,     0,   322,
       0,     0,     0,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,     0,   323,     0,
       0,   472,     0,     0,     0,    52,    53,    54,    55,    56,
    2031,     0,    58,    59,    60,     0,     0,    63,     0,     0,
      66,   734,    24,    25,   735,    27,    28,   736,    30,   737,
      32,    33,     0,     0,     0,    34,     0,    35,     0,     0,
       0,     0,    40,    41,    42,    43,     0,    45,    46,    47,
       0,     0,     0,    50,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   179,     0,     0,     0,   183,     0,     0,
       0,   184,   185,   186,   187,   188,     0,     0,     0,    97,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      74,    75,    76,   191,   324,     0,     0,     0,   193,     0,
       0,     0,     0,   325,     0,   122,   312,     0,   197,     0,
     326,   125,   126,   127,     0,     0,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   314,
     315,   316,   317,   318,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   160,   161,   162,   163,     0,
       0,  1199,     0,   168,     7,     8,     0,     0,     0,     0,
       0,     0,     0,     0,   173,   174,   175,     0,     0,     0,
       0,     0,   176,     0,     0,     0,   319,     0,     0,   320,
       0,     0,   321,     0,   322,     0,     0,     0,   458,   459,
     460,   461,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,     0,   323,     0,     0,   472,     0,     0,     0,
      52,    53,    54,    55,    56,  2033,     0,    58,    59,    60,
       0,     0,    63,     0,     0,    66,   734,    24,    25,   735,
      27,    28,   736,    30,   737,    32,    33,     0,     0,     0,
      34,     0,    35,     0,     0,     0,     0,    40,    41,    42,
      43,     0,    45,    46,    47,     0,     0,     0,    50,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   179,     0,
       0,     0,   183,     0,     0,     0,   184,   185,   186,   187,
     188,     0,     0,     0,    97,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    74,    75,    76,   191,   324,
       0,     0,     0,   193,     0,     0,     0,     0,   530,     0,
     122,   312,     0,   197,     0,   326,   125,   126,   127,     0,
       0,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   314,   315,   316,   317,   318,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     160,   161,   162,   163,     0,     0,  1205,     0,   168,     7,
       8,     0,     0,     0,     0,     0,     0,     0,     0,   173,
     174,   175,     0,     0,     0,     0,     0,   176,     0,     0,
       0,   319,     0,     0,   320,     0,     0,   321,     0,   322,
       0,     0,     0,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,     0,   323,     0,
       0,   472,     0,     0,     0,    52,    53,    54,    55,    56,
    2035,     0,    58,    59,    60,     0,     0,    63,     0,     0,
      66,   734,    24,    25,   735,    27,    28,   736,    30,   737,
      32,    33,     0,     0,     0,    34,     0,    35,     0,     0,
       0,     0,    40,    41,    42,    43,     0,    45,    46,    47,
       0,     0,     0,    50,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   179,     0,     0,     0,   183,     0,     0,
       0,   184,   185,   186,   187,   188,     0,     0,     0,    97,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      74,    75,    76,   191,   324,     0,     0,     0,   193,     0,
       0,     0,     0,   532,     0,   122,   312,     0,   197,     0,
     326,   125,   126,   127,     0,     0,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   314,
     315,   316,   317,   318,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   160,   161,   162,   163,     0,
       0,  1338,     0,   168,     7,     8,     0,     0,     0,     0,
       0,     0,     0,     0,   173,   174,   175,     0,     0,     0,
       0,     0,   176,     0,     0,     0,   319,     0,     0,   320,
       0,     0,   321,     0,   322,     0,     0,     0,   458,   459,
     460,   461,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,     0,   323,     0,     0,   472,     0,     0,     0,
      52,    53,    54,    55,    56,  2059,     0,    58,    59,    60,
       0,     0,    63,     0,     0,    66,   734,    24,    25,   735,
      27,    28,   736,    30,   737,    32,    33,     0,     0,     0,
      34,     0,    35,     0,     0,     0,     0,    40,    41,    42,
      43,     0,    45,    46,    47,     0,     0,     0,    50,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   179,     0,
       0,     0,   183,     0,     0,     0,   184,   185,   186,   187,
     188,     0,     0,     0,    97,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    74,    75,    76,   191,   324,
       0,     0,     0,   193,     0,     0,     0,     0,   534,     0,
     122,   312,     0,   197,     0,   326,   125,   126,   127,     0,
       0,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   314,   315,   316,   317,   318,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     160,   161,   162,   163,     0,     0,  1951,     0,   168,     7,
       8,     0,     0,     0,     0,     0,     0,     0,     0,   173,
     174,   175,     0,     0,     0,     0,     0,   176,     0,     0,
       0,   319,     0,     0,   320,     0,     0,   321,     0,   322,
       0,     0,     0,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,     0,   323,     0,
       0,   472,     0,     0,     0,    52,    53,    54,    55,    56,
    2090,     0,    58,    59,    60,     0,     0,    63,     0,     0,
      66,   734,    24,    25,   735,    27,    28,   736,    30,   737,
      32,    33,     0,     0,     0,    34,     0,    35,     0,     0,
       0,     0,    40,    41,    42,    43,     0,    45,    46,    47,
       0,     0,     0,    50,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   179,     0,     0,     0,   183,     0,     0,
       0,   184,   185,   186,   187,   188,     0,     0,     0,    97,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      74,    75,    76,   191,   494,     0,     0,     0,   193,     0,
       0,     0,     0,   325,     0,   122,   312,     0,   197,     0,
     613,   125,   126,   127,     0,     0,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   314,
     315,   316,   317,   318,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   160,   161,   162,   163,     0,
       0,  2039,     0,   168,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   173,   174,   175,     0,     0,     0,
       0,     0,   176,     0,     0,     0,   319,     0,     0,   320,
       0,     0,   321,     0,   322,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   352,   124,     0,
       0,     0,     0,   323,     0,     0,     0,     0,     0,     0,
      52,    53,    54,    55,    56,     0,     0,    58,    59,    60,
       0,     0,    63,     0,     0,    66,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   151,   152,   153,
     154,   155,   156,   157,   158,   159,     0,     0,     0,     0,
     164,   165,   166,   167,     0,     0,     0,     0,   169,   170,
     171,     0,     0,   172,     0,     0,     0,     0,   179,     0,
       0,     0,   183,     0,   177,     0,   184,   185,   186,   187,
     188,     0,     0,     0,    97,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   191,   494,
       0,     0,     0,   193,     0,     0,     0,     0,   325,     0,
     122,   312,     0,   197,     0,   886,   125,   126,   127,     0,
       0,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   314,   315,   316,   317,   318,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     160,   161,   162,   163,     0,     0,     0,     0,   168,     0,
     180,   181,   182,     0,     0,     0,     0,     0,     0,   173,
     174,   175,   189,     0,   190,    97,     0,   176,     0,     0,
       0,   319,     0,     0,   320,     0,     0,   321,     0,   322,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   480,   124,     0,     0,     0,     0,   323,     0,
       0,     0,     0,     0,     0,    52,    53,    54,    55,    56,
       0,     0,    58,    59,    60,     0,     0,    63,     0,     0,
      66,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   151,   152,   153,   154,   155,   156,   157,   158,
     159,     0,     0,     0,     0,   164,   165,   166,   167,     0,
       0,     0,     0,   169,   170,   171,     0,     0,   172,     0,
       0,     0,     0,   179,     0,     0,     0,   183,     0,   177,
       0,   184,   185,   186,   187,   188,     0,     0,     0,    97,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   191,   494,     0,     0,     0,   193,     0,
       0,     0,     0,   325,     0,   122,   312,     0,   197,     0,
     889,   125,   126,   127,     0,     0,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   314,
     315,   316,   317,   318,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   160,   161,   162,   163,     0,
       0,     0,     0,   168,     0,   180,   181,   182,     0,     0,
       0,     0,     0,     0,   173,   174,   175,   189,     0,   190,
      97,     0,   176,     0,     0,     0,   319,     0,     0,   320,
       0,     0,   321,     0,   322,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   356,   124,     0,
       0,     0,     0,   323,     0,     0,     0,     0,     0,     0,
      52,    53,    54,    55,    56,     0,     0,    58,    59,    60,
       0,     0,    63,     0,     0,    66,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   151,   152,   153,
     154,   155,   156,   157,   158,   159,     0,     0,     0,     0,
     164,   165,   166,   167,     0,     0,     0,     0,   169,   170,
     171,     0,     0,   172,     0,     0,     0,     0,   179,     0,
       0,     0,   183,     0,   177,     0,   184,   185,   186,   187,
     188,     0,     0,     0,    97,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   191,   494,
       0,     0,     0,   193,     0,     0,     0,     0,   325,     0,
     122,   312,     0,   197,     0,   913,   125,   126,   127,     0,
       0,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   314,   315,   316,   317,   318,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     160,   161,   162,   163,     0,     0,     0,     0,   168,     0,
     180,   181,   182,     0,     0,     0,     0,     0,     0,   173,
     174,   175,   189,     0,   190,     0,     0,   176,     0,     0,
       0,   319,     0,     0,   320,     0,     0,   321,     0,   322,
       0,     0,     0,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,     0,   323,     0,
       0,   472,     0,     0,     0,    52,    53,    54,    55,    56,
    2129,     0,    58,    59,    60,     0,     0,    63,     0,     0,
      66,   458,   459,   460,   461,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   471,     0,     0,     0,     0,   472,
       0,     0,     0,     0,     0,     0,     0,     0,  2130,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   179,     0,     0,     0,   183,     0,     0,
       0,   184,   185,   186,   187,   188,     0,     0,     0,    97,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   191,   324,     0,     0,     0,   193,     0,
       0,     0,     0,   325,     0,   122,   312,     0,   197,     0,
    1565,   125,   126,   127,     0,     0,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   314,
     315,   316,   317,   318,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   160,   161,   162,   163,     0,
       0,     0,     0,   168,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   173,   174,   175,     0,     0,     0,
       0,     0,   176,     0,     0,     0,   319,     0,     0,   320,
       0,     0,   321,     0,   322,     0,     0,     0,   458,   459,
     460,   461,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,     0,   323,     0,     0,   472,     0,     0,     0,
      52,    53,    54,    55,    56,  2134,     0,    58,    59,    60,
       0,     0,    63,     0,     0,    66,   458,   459,   460,   461,
     462,   463,   464,   465,   466,   467,   468,   469,   470,   471,
       0,     0,     0,     0,   472,     0,     0,     0,     0,     0,
       0,     0,     0,  2135,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   179,     0,
       0,     0,   183,     0,     0,     0,   184,   185,   186,   187,
     188,     0,     0,     0,    97,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   557,  1708,
       0,     0,     0,   193,     0,     0,     0,     0,   559,     0,
     122,   362,   124,   197,     0,   275,   125,   126,   127,     0,
       0,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,     0,     0,     0,     0,     0,     0,
       0,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,     0,
       0,     0,   169,   170,   171,     0,     0,   172,     0,   173,
     174,   175,     0,     0,     0,     0,     0,   176,   177,   458,
     459,   460,   461,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,     0,     0,     0,     0,   472,     0,     0,
       0,     0,     0,     0,     0,     0,  2136,   458,   459,   460,
     461,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,     0,     0,     0,     0,   472,     0,     0,     0,     0,
       0,     0,     0,     0,  2137,   458,   459,   460,   461,   462,
     463,   464,   465,   466,   467,   468,   469,   470,   471,     0,
       0,     0,     0,   472,     0,     0,     0,     0,     0,     0,
       0,   832,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   179,   180,   181,   182,   183,     0,     0,
       0,   184,   185,   186,   187,   188,   189,     0,   190,    97,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   191,   192,     0,     0,     0,   193,   122,
     312,     0,     0,   325,     0,   125,   126,   127,   197,     0,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   314,   315,   316,   317,   318,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   160,
     161,   162,   163,     0,     0,     0,     0,   168,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   173,   174,
     175,     0,     0,     0,     0,     0,   176,     0,     0,     0,
     319,     0,     0,   320,     0,     0,   321,     0,   322,     0,
       0,     0,     0,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   323,     0,     0,
       0,   472,     0,     0,    52,    53,    54,    55,    56,  1789,
       0,    58,    59,    60,     0,     0,    63,     0,     0,    66,
     458,   459,   460,   461,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   471,     0,     0,     0,     0,   472,     0,
     882,     0,   883,     0,     0,  1438,   458,   459,   460,   461,
     462,   463,   464,   465,   466,   467,   468,   469,   470,   471,
       0,     0,   179,     0,   472,     0,   183,     0,   726,     0,
     184,   185,   186,   187,   188,     0,     0,     0,    97,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   191,   494,     0,     0,     0,   193,   122,   362,
       0,     0,   325,     0,   125,   126,   127,   197,     0,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,     0,     0,   458,   459,   460,   461,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,   160,   161,
     162,   163,   472,     0,   910,     0,   168,     0,     0,   839,
       0,     0,     0,     0,     0,   122,   362,   173,   174,   175,
       0,   125,   126,   127,     0,   176,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,     0,
       0,   458,   459,   460,   461,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   471,   160,   161,   162,   163,   472,
       0,     0,     0,   168,     0,     0,   769,     0,     0,     0,
       0,     0,     0,     0,   173,   174,   175,     0,     0,     0,
       0,     0,   176,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,     0,     0,     0,
       0,   472,     0,     0,     0,     0,     0,     0,   839,     0,
       0,   179,     0,     0,     0,   183,     0,     0,     0,   184,
     185,   186,   187,   188,     0,     0,     0,    97,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   191,   192,     0,     0,     0,   193,     0,     0,     0,
       0,   325,   654,     0,     0,     0,   197,     0,   458,   459,
     460,   461,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,     0,     0,     0,     0,   472,     0,   179,     0,
       0,     0,   183,   840,     0,     0,   184,   185,   186,   187,
     188,     0,     0,     0,    97,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   191,   192,
       0,     0,     0,   193,     0,     0,     0,     0,   325,   122,
     362,   656,  1207,   197,     0,   125,   126,   127,     0,     0,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,     0,     0,   458,   459,   460,   461,   462,
     463,   464,   465,   466,   467,   468,   469,   470,   471,   160,
     161,   162,   163,   472,     0,     0,     0,   168,     0,     0,
     924,     0,     0,     0,     0,     0,     0,     0,   173,   174,
     175,   122,   362,     0,  1348,     0,   176,   125,   126,   127,
       0,     0,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,     0,     0,   458,   459,   460,
     461,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,   160,   161,   162,   163,   472,     0,     0,     0,   168,
       0,     0,   969,     0,     0,     0,     0,     0,     0,     0,
     173,   174,   175,     0,     0,     0,     0,     0,   176,   458,
     459,   460,   461,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,     0,     0,     0,     0,   472,     0,     0,
       0,     0,   179,     0,   977,     0,   183,     0,     0,     0,
     184,   185,   186,   187,   188,     0,     0,     0,    97,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   191,   192,     0,     0,     0,   193,     0,     0,
       0,     0,   325,     0,     0,     0,     0,   197,   458,   459,
     460,   461,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,     0,     0,     0,     0,   472,     0,     0,     0,
       0,     0,     0,   978,   179,     0,     0,     0,   183,     0,
       0,     0,   184,   185,   186,   187,   188,     0,     0,     0,
      97,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   191,   192,     0,     0,     0,   193,
     122,   362,     0,     0,   325,     0,   125,   126,   127,   197,
       0,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,     0,     0,   458,   459,   460,   461,
     462,   463,   464,   465,   466,   467,   468,   469,   470,   471,
     160,   161,   162,   163,   472,     0,     0,     0,   168,     0,
       0,   979,     0,     0,     0,     0,     0,     0,     0,   173,
     174,   175,     0,     0,     0,     0,     0,   176,   458,   459,
     460,   461,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,     0,     0,     0,     0,   472,     0,     0,     0,
       0,     0,     0,   994,   458,   459,   460,   461,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,     0,     0,
       0,     0,   472,     0,     0,     0,     0,     0,     0,  1129,
       0,     0,   458,   459,   460,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   470,   471,     0,     0,    -4,     1,
     472,     0,    -4,     0,     0,     0,     0,  1130,     0,     0,
      -4,    -4,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   179,     0,     0,     0,   183,     0,     0,
       0,   184,   185,   186,   187,   188,     0,     0,     0,    97,
      -4,    -4,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   191,   192,     0,     0,     0,   193,     0,
      -4,    -4,    -4,   325,     0,     0,    -4,    -4,   197,    -4,
       0,     0,     0,    -4,    -4,     0,    -4,    -4,     0,     0,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,     0,     0,     0,    -4,     0,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,     0,     0,     0,    -4,    -4,    -4,
       0,     0,     0,     0,     0,    -4,     6,     0,     0,     0,
      -4,    -4,    -4,    -4,     7,     8,    -4,     0,    -4,     0,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,     0,     0,     0,     0,     0,    -4,
      -4,    -4,     0,     0,     9,    10,     0,     0,    -4,     0,
      -4,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    11,    12,    13,     0,     0,     0,
      14,    15,     0,    16,     0,     0,     0,    17,    18,     0,
      19,    20,     0,     0,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,     0,     0,     0,
      34,     0,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,     0,    49,    50,    51,
      52,    53,    54,    55,    56,    57,     0,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,     0,     0,
       0,    69,    70,    71,     0,     0,     0,     0,     0,    72,
       0,     0,     0,     0,    73,    74,    75,    76,     0,     0,
      77,     0,    78,     0,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,     0,     0,
       0,     0,     0,    93,    94,    95,     0,     0,     0,     0,
       0,     0,    96,     0,    97,   458,   459,   460,   461,   462,
     463,   464,   465,   466,   467,   468,   469,   470,   471,     0,
       0,     0,     0,   472,     0,     0,     0,     0,     0,     0,
    1131,   458,   459,   460,   461,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   471,     0,     0,     0,     0,   472,
       0,     0,     0,     0,     0,     0,  1166,   458,   459,   460,
     461,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,     0,     0,     0,     0,   472,     0,     0,     0,     0,
       0,     0,  1175,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,     0,     0,     0,
       0,   472,     0,     0,     0,     0,     0,     0,  1176,   458,
     459,   460,   461,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,     0,     0,     0,     0,   472,     0,     0,
       0,     0,     0,     0,  1178,   458,   459,   460,   461,   462,
     463,   464,   465,   466,   467,   468,   469,   470,   471,     0,
       0,     0,     0,   472,     0,     0,     0,     0,     0,     0,
    1289,   458,   459,   460,   461,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   471,     0,     0,     0,     0,   472,
       0,     0,     0,     0,     0,     0,  1340,   458,   459,   460,
     461,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,     0,     0,     0,     0,   472,     0,     0,     0,     0,
       0,     0,  1341,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,     0,     0,     0,
       0,   472,     0,     0,     0,     0,     0,     0,  1406,   458,
     459,   460,   461,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,     0,     0,     0,     0,   472,     0,     0,
       0,     0,     0,     0,  1575,   458,   459,   460,   461,   462,
     463,   464,   465,   466,   467,   468,   469,   470,   471,     0,
       0,     0,     0,   472,     0,     0,     0,     0,     0,     0,
    1576,   458,   459,   460,   461,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   471,     0,     0,     0,     0,   472,
       0,     0,     0,     0,     0,     0,  1577,   458,   459,   460,
     461,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,     0,     0,     0,     0,   472,     0,     0,     0,     0,
       0,     0,  1578,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,     0,     0,     0,
       0,   472,     0,     0,     0,     0,     0,     0,  1579,   458,
     459,   460,   461,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,     0,     0,     0,     0,   472,     0,     0,
       0,     0,     0,     0,  1580,   458,   459,   460,   461,   462,
     463,   464,   465,   466,   467,   468,   469,   470,   471,     0,
       0,     0,     0,   472,     0,     0,     0,     0,     0,     0,
    1581,   458,   459,   460,   461,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   471,     0,     0,     0,     0,   472,
       0,     0,     0,     0,     0,     0,  1634,   458,   459,   460,
     461,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,     0,     0,     0,     0,   472,     0,     0,     0,     0,
       0,     0,  1635,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,     0,     0,     0,
       0,   472,     0,     0,     0,     0,     0,     0,  1642,   458,
     459,   460,   461,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,     0,     0,     0,     0,   472,     0,     0,
       0,     0,     0,     0,  1819,   458,   459,   460,   461,   462,
     463,   464,   465,   466,   467,   468,   469,   470,   471,     0,
       0,     0,     0,   472,     0,     0,     0,     0,     0,     0,
    1820,   458,   459,   460,   461,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   471,     0,     0,     0,     0,   472,
       0,     0,     0,     0,     0,     0,  1821,   458,   459,   460,
     461,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,     0,     0,     0,     0,   472,     0,     0,     0,     0,
       0,     0,  1822,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,     0,     0,     0,
       0,   472,     0,     0,     0,     0,     0,     0,  1823,   458,
     459,   460,   461,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,     0,     0,     0,     0,   472,     0,     0,
       0,     0,     0,     0,  1847,   458,   459,   460,   461,   462,
     463,   464,   465,   466,   467,   468,   469,   470,   471,     0,
       0,     0,     0,   472,     0,     0,     0,     0,     0,     0,
    1848,   458,   459,   460,   461,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   471,     0,     0,     0,     0,   472,
       0,     0,     0,     0,     0,     0,  1852,   458,   459,   460,
     461,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,     0,     0,     0,     0,   472,     0,     0,     0,     0,
       0,     0,  1960,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,     0,     0,     0,
       0,   472,     0,     0,     0,     0,     0,     0,  1961,   458,
     459,   460,   461,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,     0,     0,     0,     0,   472,     0,     0,
       0,     0,     0,     0,  1962,   458,   459,   460,   461,   462,
     463,   464,   465,   466,   467,   468,   469,   470,   471,     0,
       0,     0,     0,   472,     0,     0,     0,     0,     0,     0,
    1963,   458,   459,   460,   461,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   471,     0,     0,     0,     0,   472,
       0,     0,     0,     0,     0,     0,  1964,   458,   459,   460,
     461,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,     0,     0,     0,     0,   472,     0,     0,     0,     0,
       0,     0,  1974,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,     0,     0,     0,
       0,   472,     0,     0,     0,     0,     0,     0,  1977,   458,
     459,   460,   461,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,     0,     0,     0,     0,   472,     0,     0,
       0,     0,     0,     0,  2027,   458,   459,   460,   461,   462,
     463,   464,   465,   466,   467,   468,   469,   470,   471,     0,
       0,     0,     0,   472,     0,     0,     0,     0,     0,     0,
    2047,   458,   459,   460,   461,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   471,     0,     0,     0,     0,   472,
       0,     0,     0,     0,     0,     0,  2048,   458,   459,   460,
     461,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,     0,     0,     0,     0,   472,     0,     0,     0,     0,
       0,     0,  2049,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,     0,     0,     0,
       0,   472,     0,     0,     0,     0,     0,     0,  2050,   458,
     459,   460,   461,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,     0,     0,     0,     0,   472,     0,     0,
       0,     0,     0,     0,  2051,   458,   459,   460,   461,   462,
     463,   464,   465,   466,   467,   468,   469,   470,   471,     0,
       0,     0,     0,   472,     0,     0,     0,     0,     0,     0,
    2102,   458,   459,   460,   461,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   471,     0,     0,     0,     0,   472,
       0,     0,     0,     0,     0,     0,  2103,   458,   459,   460,
     461,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,     0,     0,     0,     0,   472,     0,     0,     0,     0,
       0,     0,  2104,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,     0,     0,     0,
       0,   472,     0,     0,     0,     0,     0,     0,  2105,   458,
     459,   460,   461,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,     0,     0,     0,     0,   472,     0,     0,
       0,   930,   458,   459,   460,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   470,   471,     0,     0,     0,     0,
     472,     0,     0,     0,   949,   458,   459,   460,   461,   462,
     463,   464,   465,   466,   467,   468,   469,   470,   471,     0,
       0,     0,     0,   472,     0,     0,     0,   956,   458,   459,
     460,   461,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,     0,     0,     0,     0,   472,     0,     0,     0,
    1052,   458,   459,   460,   461,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   471,     0,     0,     0,     0,   472,
       0,     0,     0,  1159,   458,   459,   460,   461,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,     0,     0,
       0,     0,   472,     0,     0,     0,  1160,   458,   459,   460,
     461,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,     0,     0,     0,     0,   472,     0,     0,     0,  1164,
     458,   459,   460,   461,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   471,     0,     0,     0,     0,   472,     0,
       0,     0,  1165,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,     0,     0,     0,
       0,   472,     0,     0,     0,  1168,   458,   459,   460,   461,
     462,   463,   464,   465,   466,   467,   468,   469,   470,   471,
       0,     0,     0,     0,   472,     0,     0,     0,  1192,   458,
     459,   460,   461,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,     0,     0,     0,     0,   472,     0,     0,
       0,  1225,   458,   459,   460,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   470,   471,     0,     0,     0,     0,
     472,     0,     0,     0,  1282,   458,   459,   460,   461,   462,
     463,   464,   465,   466,   467,   468,   469,   470,   471,     0,
       0,     0,     0,   472,     0,     0,     0,  1287,   458,   459,
     460,   461,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,     0,     0,     0,     0,   472,     0,     0,     0,
    1570,   458,   459,   460,   461,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   471,     0,     0,     0,     0,   472,
       0,     0,     0,  1625,   458,   459,   460,   461,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,     0,     0,
       0,     0,   472,     0,     0,     0,  1802,   458,   459,   460,
     461,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,     0,     0,     0,     0,   472,     0,   722,   458,   459,
     460,   461,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,     0,     0,     0,     0,   472,     0,   779,   458,
     459,   460,   461,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,     0,     0,     0,     0,   472,     0,   783,
     458,   459,   460,   461,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   471,     0,     0,     0,     0,   472,     0,
     784,   458,   459,   460,   461,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   471,     0,     0,     0,     0,   472,
       0,   786,   458,   459,   460,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   470,   471,     0,     0,     0,     0,
     472,     0,   788,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,     0,     0,     0,
       0,   472,     0,   789,   458,   459,   460,   461,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,     0,     0,
       0,     0,   472,     0,   792,   458,   459,   460,   461,   462,
     463,   464,   465,   466,   467,   468,   469,   470,   471,     0,
       0,     0,     0,   472,     0,   793,   458,   459,   460,   461,
     462,   463,   464,   465,   466,   467,   468,   469,   470,   471,
       0,     0,     0,     0,   472,     0,   794,   458,   459,   460,
     461,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,     0,     0,     0,     0,   472,     0,   795,   458,   459,
     460,   461,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,     0,     0,     0,     0,   472,     0,   804,   458,
     459,   460,   461,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,     0,     0,     0,     0,   472,     0,   910,
     458,   459,   460,   461,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   471,     0,     0,     0,     0,   472,     0,
     920,   458,   459,   460,   461,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   471,     0,     0,     0,     0,   472,
       0,   921,   458,   459,   460,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   470,   471,     0,     0,     0,     0,
     472,     0,   922,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,     0,     0,     0,
       0,   472,     0,   928,   458,   459,   460,   461,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,     0,     0,
       0,     0,   472,     0,   929,   458,   459,   460,   461,   462,
     463,   464,   465,   466,   467,   468,   469,   470,   471,     0,
       0,     0,     0,   472,     0,   936,   458,   459,   460,   461,
     462,   463,   464,   465,   466,   467,   468,   469,   470,   471,
       0,     0,     0,     0,   472,     0,   945,   458,   459,   460,
     461,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,     0,     0,     0,     0,   472,     0,   955,   458,   459,
     460,   461,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,     0,     0,     0,     0,   472,     0,  1051,   458,
     459,   460,   461,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,     0,     0,     0,     0,   472,     0,  1079,
     458,   459,   460,   461,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   471,     0,     0,     0,     0,   472,     0,
    1084,   458,   459,   460,   461,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   471,     0,     0,     0,     0,   472,
       0,  1091,   458,   459,   460,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   470,   471,     0,     0,     0,     0,
     472,     0,  1096,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,     0,     0,     0,
       0,   472,     0,  1097,   458,   459,   460,   461,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,     0,     0,
       0,     0,   472,     0,  1103,   458,   459,   460,   461,   462,
     463,   464,   465,   466,   467,   468,   469,   470,   471,     0,
       0,     0,     0,   472,     0,  1112,   458,   459,   460,   461,
     462,   463,   464,   465,   466,   467,   468,   469,   470,   471,
       0,     0,     0,     0,   472,     0,  1113,   458,   459,   460,
     461,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,     0,     0,     0,     0,   472,     0,  1114,   458,   459,
     460,   461,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,     0,     0,     0,     0,   472,     0,  1146,   458,
     459,   460,   461,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,     0,     0,     0,     0,   472,     0,  1148,
     458,   459,   460,   461,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   471,     0,     0,     0,     0,   472,     0,
    1149,   458,   459,   460,   461,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   471,     0,     0,     0,     0,   472,
       0,  1150,   458,   459,   460,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   470,   471,     0,     0,     0,     0,
     472,     0,  1151,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,     0,     0,     0,
       0,   472,     0,  1152,   458,   459,   460,   461,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,     0,     0,
       0,     0,   472,     0,  1153,   458,   459,   460,   461,   462,
     463,   464,   465,   466,   467,   468,   469,   470,   471,     0,
       0,     0,     0,   472,     0,  1154,   458,   459,   460,   461,
     462,   463,   464,   465,   466,   467,   468,   469,   470,   471,
       0,     0,     0,     0,   472,     0,  1158,   458,   459,   460,
     461,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,     0,     0,     0,     0,   472,     0,  1167,   458,   459,
     460,   461,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,     0,     0,     0,     0,   472,     0,  1191,   458,
     459,   460,   461,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,     0,     0,     0,     0,   472,     0,  1281,
     458,   459,   460,   461,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   471,     0,     0,     0,     0,   472,     0,
    1286,   458,   459,   460,   461,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   471,     0,     0,     0,     0,   472,
       0,  1450,   458,   459,   460,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   470,   471,     0,     0,     0,     0,
     472,     0,  1680,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,     0,     0,     0,
       0,   472,     0,  1697,   458,   459,   460,   461,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,     0,     0,
       0,     0,   472,     0,  1727,   458,   459,   460,   461,   462,
     463,   464,   465,   466,   467,   468,   469,   470,   471,     0,
       0,     0,     0,   472,     0,  1973,   458,   459,   460,   461,
     462,   463,   464,   465,   466,   467,   468,   469,   470,   471,
       0,     0,     0,     0,   472,     0,  2057,   458,   459,   460,
     461,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,     0,     0,     0,     0,   472
};

static const yytype_int16 yycheck[] =
{
       3,   268,     3,     6,   410,  1145,   412,  1141,   283,     6,
     551,   552,  1593,  1594,     4,     6,  1772,     4,     7,     5,
       4,   427,     7,     6,   299,     4,  1316,     4,     6,     4,
       4,    13,     5,     3,     5,     4,     6,     4,     4,     4,
       4,     4,     6,   216,     5,   218,     6,     6,     5,     4,
     443,   158,   445,     6,   447,     5,     5,     5,     4,     4,
     216,    64,     5,     5,     0,     6,     6,   174,   175,    72,
     206,   207,   213,   214,    77,     7,     6,   206,   207,   220,
     216,     6,   206,   207,   359,    88,   361,   223,     6,   246,
     247,   248,   367,   222,    64,   224,   253,   254,   255,   217,
     224,   219,   216,     4,   222,   206,   207,    77,     7,     6,
     206,   207,   216,     7,   218,     6,     6,     6,    88,    84,
      84,     7,   223,    88,   206,   207,   222,   216,   224,    94,
      95,    96,    97,   121,   223,   220,   293,   294,   206,   207,
     225,   223,   107,   206,   207,   216,   216,     8,   218,     6,
     307,   308,   223,    90,   222,   225,   224,   206,   207,   216,
     223,   148,   149,   150,   151,   216,   223,   218,  1924,  1925,
      90,     7,    92,   222,   225,   161,   206,   207,   216,   213,
     214,   158,   159,     6,   216,   223,   146,   146,   161,   223,
     161,   223,   222,   146,   197,   169,     7,   198,     6,    88,
     161,    90,     7,   158,   159,   216,   209,   210,   193,   194,
     195,   196,     7,   192,   217,   206,   207,   192,   192,   216,
     203,   146,   225,     6,   227,   203,   223,   197,   218,   232,
    1364,   220,   216,   236,   218,   225,   220,   224,   241,   209,
     210,   225,   245,   246,   247,   248,   249,   217,   223,   223,
     253,   254,   255,   216,   223,   225,   223,   223,   261,   262,
     263,   654,   223,   656,   267,   268,   223,   542,   543,  1559,
     216,   216,   173,   223,   223,   223,    90,   223,   223,   249,
     223,   223,   223,   223,   216,     6,   218,   562,   206,   207,
     293,   294,   295,     7,   193,   194,   195,   196,   268,   193,
     194,   195,   196,   218,   307,   308,     6,   193,   194,   195,
     196,   218,   209,   210,   213,   214,   206,   207,   216,   213,
     214,   324,    99,   326,   118,   119,   220,   213,   214,   722,
     124,    87,   216,   726,    90,   224,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
      87,   216,   249,    90,   215,    92,   631,   193,   194,   195,
     196,   216,   365,   224,   206,   207,   369,   370,   217,  1659,
     219,   646,   216,   222,   218,     8,   220,   213,   214,   382,
     222,   225,   193,   194,   195,   196,    90,  1968,   193,   194,
     195,   196,   222,     6,   224,   365,   213,   214,   193,   194,
     195,   196,   213,   214,   216,     6,   223,   410,   411,   412,
     413,   414,   415,   416,   417,   418,   419,   420,   421,   422,
     216,   424,   425,   426,   427,   428,   213,   214,     4,   432,
     433,   434,   435,   436,   437,    87,   439,   222,    90,   224,
     410,   411,   412,   413,   414,   415,   416,   417,   418,   419,
     216,   421,   422,   456,   424,   425,   426,   427,   428,   447,
       7,   216,   432,   433,   434,   435,   436,   437,   365,   439,
     223,   206,   207,     8,   206,   207,   216,  1767,   218,   193,
     194,   195,   196,   213,   214,   225,   375,   222,   213,   214,
     222,   494,   219,   223,   219,   222,  1786,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   222,    90,   224,   411,   215,   413,   414,   415,   416,
     417,   418,   419,   219,   421,   422,   222,   424,   425,   426,
     222,   428,   224,   536,   537,   432,   433,   434,   435,   436,
     216,   430,   118,   119,   120,   121,   206,   207,   216,   438,
     551,   552,   945,   217,   130,   219,   949,   133,   217,   223,
     835,    92,   222,   222,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,    90,   582,
     583,   584,   215,    84,   217,   216,    87,    84,     6,    90,
      87,   594,   595,    90,    87,   598,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     613,   206,   207,   223,   215,   206,   207,   620,   206,   207,
     118,   119,     6,   213,   214,   595,   124,   222,   598,   206,
     207,   222,    90,   223,   222,    87,   639,   526,   527,   528,
     529,   223,   206,   207,    87,   222,   193,   194,   195,   196,
     213,   214,   222,   222,   224,   224,   659,  1797,   222,  1799,
     223,  1801,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   114,   217,   666,   219,
     215,   206,   207,   223,   213,   214,  1976,   206,   207,   224,
     128,   217,   206,   207,   223,    90,   222,   222,   136,   137,
     138,   598,   218,   222,   142,   143,   144,   145,   222,   206,
     207,  1104,   217,  1106,   219,  1108,     4,  1110,   721,   216,
     206,   207,   725,   206,   207,     4,   223,   206,   207,   216,
     206,   207,     6,     7,   722,   216,   222,   218,   726,   222,
     206,   207,     4,   222,   225,  1879,   222,    87,  1882,     4,
      90,  1885,    92,   206,   207,   216,   222,   218,   206,   207,
     216,   764,   217,  1030,   225,   768,   216,   222,   771,   222,
     217,   774,   219,   776,   222,   222,   216,   780,   781,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   206,   207,   206,   207,   215,  2088,     6,
       7,   771,   217,   217,   774,   808,   776,   222,   222,   222,
     216,   222,  1952,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   206,   207,   832,
     114,   215,   217,   206,   207,   206,   207,   222,   727,   206,
     207,  1247,  1248,   222,   128,   217,  1252,  1253,     6,   222,
     222,   222,   136,   137,   138,   222,   206,   207,   142,   143,
     144,   145,  1255,     6,   206,   207,   208,   209,   210,  2003,
     206,   207,   222,   215,   771,   208,   209,   210,  1271,   776,
       6,   884,   215,   886,   216,   222,   889,   224,   218,   778,
    2030,   216,  2032,   881,  2034,   114,   222,   216,   224,   902,
    2040,   904,   216,   906,   216,   908,   218,   216,   220,   128,
     913,   223,   216,   225,   218,   918,   220,   136,   137,   138,
     222,   225,   224,   142,   143,   144,   145,   216,    84,  2063,
       7,    87,  2066,   216,    90,  2069,    92,   940,  2072,   216,
     224,   944,   217,    84,   219,   948,    87,   222,   216,    90,
     217,    92,   219,   956,  2094,   222,  2096,   945,  2098,   218,
     217,   949,   219,   223,   217,   222,   219,   955,   956,   222,
     216,   222,     6,   224,   222,   222,   224,   224,   981,   222,
    2114,   224,  2116,   986,  2118,   222,   956,   224,   991,   992,
     993,   994,   222,   216,   224,  1262,  1537,  1538,    90,   223,
      92,  1004,    90,  1006,    92,   224,   222,   222,   224,   224,
     223,     6,  1418,  1419,     6,   216,   986,  1423,  1424,   222,
       4,   224,   992,   993,   994,   216,   222,  1030,   224,   216,
    1033,  1034,  1035,  1036,  1004,  1428,  1006,   223,   216,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,    12,    13,  1058,   222,   215,   224,   956,
    1030,   216,   216,  1051,  1052,   202,   203,   204,   205,   206,
     207,   208,   209,   210,  1077,  1078,   216,  1080,   215,  1082,
    1083,   216,   216,  1086,  1087,  1088,  1089,   216,  1058,   986,
    1093,   114,   222,   218,   224,   992,   993,   994,   222,   222,
     224,   224,   222,   216,   224,   128,   222,  1004,   224,  1006,
     222,   216,   224,   136,   137,   138,   222,   225,   224,   142,
     143,   144,   145,   223,   223,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,   223,   223,  1413,    98,
    1415,   100,   222,   222,   224,   224,   105,   106,   107,   108,
     223,   110,   111,   112,   222,   216,   224,   116,     7,     8,
     222,  1058,   224,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   223,   216,  1167,
    1168,   215,   222,   222,   224,   224,     4,   222,     6,   224,
     216,  1194,  1195,  1196,   153,   154,   155,   222,   222,   224,
     224,   224,  1469,  1191,  1192,   216,   222,  1210,   224,   216,
       3,     4,   222,   222,   224,   224,     9,    10,    11,   216,
       6,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,  1247,  1248,   222,     6,   224,  1252,
    1253,  1792,   222,   222,   224,   224,   222,   218,   224,  1262,
      53,    54,    55,    56,   222,   224,   224,  1255,    61,   223,
     222,   114,   224,  1276,   222,   218,   224,  1247,  1248,    72,
      73,    74,  1252,  1253,   222,   128,   224,    80,   222,   222,
     224,   224,  1262,   136,   137,   138,   222,  1300,   224,   142,
     143,   144,   145,  1306,   222,   222,   224,   224,   222,   114,
     224,  1314,   223,  1316,  1317,  1318,   222,   218,   224,  1322,
    1323,   223,  1325,   128,  1327,   222,  1329,   224,  1331,  1332,
    1333,   136,   137,   138,   222,     6,   224,   142,   143,   144,
     145,   222,  1748,   224,   222,     6,   224,  1350,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,  1365,   222,   161,   224,   215,   222,   225,   224,
    1373,   222,  1375,   224,   114,   222,     6,   224,   223,   223,
       6,   224,   223,   176,     6,     6,   223,   180,   128,   223,
       6,   184,   185,   186,   187,   188,   136,   137,   138,   192,
       4,  1290,   142,   143,   144,   145,   218,   215,     7,   220,
     223,     7,   222,   206,   207,  1418,  1419,   224,   211,   224,
    1423,  1424,   222,   216,     6,     6,     6,   217,   221,     7,
     223,     7,     6,   114,  1437,     6,     6,   217,     6,   223,
    1443,     7,  1430,     6,    62,     7,     6,   128,  1418,  1419,
       6,     6,     4,  1423,  1424,   136,   137,   138,   158,    62,
      62,   142,   143,   144,   145,    62,  1469,  1437,     6,   223,
     219,   217,  1475,  1443,     6,     6,   217,   222,   217,   222,
     222,   219,  1485,   217,   224,  1488,   222,   222,     6,   222,
     222,  1758,   217,   217,    44,    44,    44,    44,     6,  1469,
       4,     4,     7,   161,     6,     6,     6,     6,   161,    53,
      54,     7,    56,     7,     7,  1485,     7,     7,     7,   161,
       7,     7,     7,  1412,     7,   223,  1529,  1530,     6,     4,
       7,  1806,     6,   217,   222,   114,  1537,  1538,   217,   222,
    1437,   217,   222,   224,   217,   222,  1443,     6,   220,   128,
     224,   217,   219,     7,   224,   223,  1559,   136,   137,   138,
     223,   223,  1565,   142,   143,   144,   145,   223,     7,     7,
     220,     7,  1461,   224,     4,     5,   223,     6,    44,    44,
      44,    44,  1585,  1571,     6,     6,     6,     6,  1485,     6,
     218,     7,  1595,     6,   223,     6,   216,   216,   203,  1488,
       7,     7,  1605,     7,    92,     7,   223,  1610,     7,     7,
       6,     4,     7,     7,    44,    45,    46,    47,    48,    49,
      50,    51,    52,     7,     7,     7,     7,    57,    58,    59,
      60,     4,   223,  1636,  1909,    65,    66,    67,     6,   216,
      70,     7,     6,     6,  1533,   224,     7,     7,     7,     7,
       7,    81,     7,     6,   223,     7,  1659,     6,     6,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,     7,     6,    90,     6,   215,  1953,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,  1696,   222,     4,     6,   215,     4,     4,
     223,   223,  1591,   224,     6,  1708,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
       6,  1610,  1611,  1612,   215,  1728,     6,   271,   272,     6,
       6,     4,     6,   107,     6,   279,   217,   217,   222,   283,
     222,   220,  1745,     7,   216,  1748,     6,   177,   178,   179,
     223,   220,   219,     6,     6,  1758,   217,     6,     6,   189,
       6,   191,   192,   223,  1767,   223,     6,   223,   223,     6,
     114,  1774,  1775,   223,     6,     6,     6,     5,  1748,     4,
       6,   223,   223,  1786,   128,     7,  1789,   217,  1758,   219,
     223,  1792,   136,   137,   138,   223,     6,     6,   142,   143,
     144,   145,  1805,     6,   218,     6,  1809,     4,     3,     4,
     219,   223,     6,   223,     9,    10,    11,   217,   223,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,  1731,   223,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,    53,    54,
      55,    56,   215,     6,   157,  1868,    61,   223,     6,   223,
       6,     4,   223,     4,     4,     5,   222,    72,    73,    74,
     224,     6,     6,     6,  1887,    80,     6,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,     6,     6,     6,     6,   215,     6,     4,     7,     7,
       6,  1914,     6,     6,    44,    45,    46,    47,    48,    49,
      50,    51,    52,     6,     5,   223,     6,    57,    58,    59,
      60,     6,   161,     6,     6,    65,    66,    67,     6,     6,
      70,     6,     6,     6,  1914,     6,     6,     6,     6,     6,
       6,    81,  1955,  1956,  1957,  1958,  1959,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   222,   114,  1976,     6,   215,    96,   222,     6,     6,
       6,   176,   217,     6,     6,   180,   128,     6,     6,   184,
     185,   186,   187,   188,   136,   137,   138,   192,     6,     6,
     142,   143,   144,   145,     7,   549,   550,     6,   220,     6,
     223,   206,   207,   557,     6,   223,   211,   223,     5,    88,
       6,   216,     6,   223,  1913,     6,   221,   223,   223,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   224,  2045,   224,   223,   215,   223,   177,   178,   179,
     223,     6,   223,  2056,     7,     6,     6,   224,   224,   189,
     224,   191,   192,     6,   156,     6,     6,     6,     6,   159,
       6,   191,   192,   193,   194,   195,     6,     6,     6,     6,
       6,     6,   224,   213,   214,  2088,  2056,     6,   208,   223,
     220,     6,   212,   223,   223,   217,     6,   223,     7,     6,
       6,     6,   223,  2106,   223,  2108,   226,   227,   228,   229,
     223,   231,   232,   233,   234,   224,   236,   237,   238,   239,
     240,     6,     6,   114,     6,   245,     6,     6,   223,  2018,
     250,     6,     6,     6,     6,  2138,  2106,     6,  2108,     6,
       6,     6,   224,     6,   223,   265,   216,   223,     6,   223,
       6,   217,     6,   224,   274,   275,     6,     6,     6,  2056,
       6,   223,     6,   283,     6,     6,     6,     6,  2138,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   223,   223,   223,   223,   215,   223,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,     6,   324,   325,   326,   215,     6,  2106,
       6,  2108,     6,     6,     6,     6,     6,     6,   338,   339,
     340,     6,   342,     6,     6,     6,   346,   347,   348,  1285,
    1917,   351,   490,  1299,  1773,     3,     3,     3,     3,   524,
    1788,  2138,    -1,  1465,    -1,    -1,   366,    -1,    -1,    -1,
      -1,   371,   372,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   385,   386,    -1,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,   398,   399,
     400,   401,   402,   403,   404,   405,   406,   407,   408,   409,
      -1,    -1,    -1,    -1,   838,    -1,    -1,    -1,    -1,    -1,
      -1,   845,    -1,   423,    -1,    -1,    -1,   851,    -1,   429,
      -1,   431,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,    -1,    -1,    -1,    -1,
     215,    -1,    -1,    -1,    -1,   455,   456,    -1,   458,   459,
     460,   461,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,   472,    -1,    -1,   475,   476,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,    -1,    -1,    -1,   494,   215,    -1,    -1,    -1,    -1,
     500,    -1,    -1,    -1,    -1,   505,    -1,    -1,    -1,    -1,
      -1,    -1,   512,   513,    -1,    -1,    -1,   114,    -1,    -1,
     520,   521,    -1,    -1,    -1,   525,   526,   527,   528,   529,
     530,   128,   532,    -1,   534,    -1,   536,   537,    -1,   136,
     137,   138,    -1,    -1,    -1,   142,   143,   144,   145,    -1,
      -1,    -1,    -1,     6,   554,   555,   556,   557,   558,   559,
      -1,    -1,    -1,   563,   564,   565,   566,   567,   568,   569,
     570,   571,    -1,    -1,    -1,   575,    -1,   577,   578,    -1,
      -1,    -1,   582,   583,   584,    -1,    -1,   587,   588,   589,
     590,   591,    -1,     8,   594,   595,   596,   597,    -1,   599,
      -1,    -1,   602,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   114,   613,    -1,    -1,    -1,     6,    -1,   619,
     620,    -1,   622,   623,    -1,    -1,   128,   224,    -1,    -1,
      -1,    -1,    -1,    -1,   136,   137,   138,    -1,    -1,   639,
     142,   143,   144,   145,   644,   645,    -1,   647,   648,  1073,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   658,   659,
      -1,    -1,    -1,   663,    -1,     3,     4,    -1,    -1,    -1,
      -1,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    -1,
      -1,    -1,    -1,    -1,    -1,  1129,  1130,  1131,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    53,    54,    55,    56,    -1,
      -1,    -1,   224,    61,    -1,    -1,    -1,    -1,   728,    -1,
      -1,    -1,    -1,    -1,    72,    73,    74,    -1,    -1,    -1,
      -1,    -1,    80,    -1,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,    -1,    -1,
     760,   761,   215,    -1,   764,   765,   766,    -1,   768,   769,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   777,    -1,    -1,
     780,   781,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   796,    -1,    -1,    -1,
     215,    -1,    -1,    -1,    -1,    -1,    -1,   807,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,    -1,    -1,    -1,    -1,   215,    -1,    -1,    -1,
      -1,    -1,   832,    -1,    -1,    -1,    -1,    -1,   176,   839,
     840,    -1,   180,    -1,    -1,   845,   184,   185,   186,   187,
     188,     6,    -1,    -1,   192,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   862,    -1,    -1,   865,    -1,    -1,   206,   207,
      -1,    -1,    -1,   211,    -1,    -1,    -1,    -1,   216,   217,
      -1,    -1,    -1,   221,   884,    -1,   886,     8,    -1,   889,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,    -1,   902,    -1,   904,   215,   906,    -1,   908,    -1,
      -1,    -1,    -1,   913,    -1,    -1,    -1,    -1,   918,   114,
      -1,    -1,    -1,    -1,   924,    -1,   926,   927,    -1,    -1,
      -1,    -1,    -1,   128,   241,    -1,    -1,   937,    -1,  1363,
      -1,   136,   137,   138,    -1,    -1,    -1,   142,   143,   144,
     145,    -1,    -1,     8,   261,   262,   263,    -1,    -1,    -1,
     267,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   969,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   977,   978,   979,
      -1,   981,    -1,    -1,    -1,    -1,    -1,    -1,   295,   989,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     8,    -1,  1003,    -1,    -1,    -1,    -1,  1008,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1017,    -1,    -1,
      -1,    -1,    -1,  1023,    -1,    -1,    -1,    -1,    -1,   224,
      -1,    -1,    -1,  1033,  1034,  1035,  1036,    -1,    -1,  1039,
      -1,    -1,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,    -1,    -1,    -1,    -1,
     215,    -1,   369,   370,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1498,   382,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
      -1,    -1,    -1,  1093,   215,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1105,    -1,  1107,    -1,  1109,
      -1,  1111,    -1,   420,    -1,  1539,    -1,  1541,     8,  1543,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1133,    -1,    -1,  1560,  1561,  1562,  1563,
    1564,  1565,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,    -1,    -1,    -1,    -1,
     215,    -1,    -1,    -1,    -1,    -1,  1166,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1175,  1176,    -1,  1178,  1179,
      -1,  1181,  1182,  1183,    -1,    -1,    -1,    -1,    -1,  1189,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,    -1,    -1,    -1,    -1,   215,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1216,    -1,    -1,    -1,
      -1,  1221,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
      -1,    -1,    -1,    -1,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    -1,  1263,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1274,  1275,    -1,    -1,    53,    54,
      55,    56,    -1,    -1,    -1,    -1,    61,    -1,    -1,  1289,
    1290,    -1,    -1,     8,    -1,    -1,    -1,    72,    73,    74,
      -1,    -1,    -1,    -1,    -1,    80,    -1,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,    -1,    -1,    -1,    -1,   215,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1339,
    1340,  1341,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1350,    -1,  1352,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1363,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1796,    -1,  1798,  1375,  1800,    -1,    -1,    -1,
    1380,    -1,    -1,    -1,    -1,    -1,  1810,  1811,  1812,  1813,
    1814,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   176,    -1,    -1,    -1,   180,  1406,  1407,  1408,   184,
     185,   186,   187,   188,   721,    -1,    -1,   192,   725,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   206,   207,    -1,    -1,    -1,   211,    -1,  1438,    -1,
      -1,   216,    -1,  1867,   219,    -1,   221,  1871,    -1,   227,
      -1,    -1,    -1,    -1,   232,    -1,    -1,    -1,   236,    -1,
      -1,    -1,  1462,    -1,    -1,    -1,   114,   245,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1476,    -1,    -1,    -1,
      -1,  1481,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,  1496,  1497,    -1,    -1,
     215,   808,    -1,  1503,  1504,  1929,    -1,    -1,  1508,  1933,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1519,
      12,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1529,
    1530,  1531,    -1,  1533,    -1,  1959,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1545,   324,    -1,   326,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,    -1,    -1,  1565,    -1,   215,  1568,    -1,
      -1,    -1,    -1,    -1,    -1,  1575,  1576,  1577,  1578,  1579,
    1580,  1581,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1591,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    -1,  2028,  2029,    98,    -1,   100,    -1,
      -1,  1611,    -1,   105,   106,   107,   108,    -1,   110,   111,
     112,    -1,    -1,    -1,   116,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   940,  1634,  1635,    -1,   944,    -1,    -1,
      -1,   948,  1642,    -1,    -1,    -1,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
      -1,   153,   154,   155,   215,    -1,    -1,    -1,    -1,    -1,
      -1,   222,    -1,   224,    -1,    -1,    -1,    -1,   456,    -1,
      -1,  1681,    -1,    -1,   991,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,  1699,
      -1,    -1,    -1,   215,   227,    -1,    -1,    -1,  1708,   232,
     222,    -1,   224,   236,    -1,    -1,   494,    -1,    -1,    -1,
      -1,    -1,   245,  1723,    -1,  1725,    -1,    -1,  1728,    -1,
      -1,    -1,   224,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1745,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   536,   537,
      -1,    -1,    -1,  1763,    -1,    -1,    -1,    -1,  1768,    -1,
    1077,  1078,    -1,  1080,    -1,  1082,  1083,    -1,    -1,  1086,
    1087,  1088,  1089,    -1,    -1,    -1,    -1,    -1,    -1,  1789,
      -1,    -1,    -1,    -1,    -1,    -1,  1796,    -1,  1798,    -1,
    1800,    -1,    -1,    -1,   582,   583,   584,    -1,    -1,  1809,
      -1,    -1,    -1,    -1,    -1,    -1,   594,   595,    -1,  1819,
    1820,  1821,  1822,  1823,  1824,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   613,    -1,    -1,    -1,    -1,
      -1,    -1,   620,    -1,    -1,    -1,    -1,  1847,  1848,    -1,
      -1,    -1,  1852,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   639,    -1,    -1,  1864,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1875,    -1,    -1,    -1,    -1,
      -1,   659,    -1,    -1,    -1,    -1,    -1,  1194,  1195,  1196,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1210,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1911,    -1,    -1,    -1,    -1,    -1,  1917,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1926,    -1,    -1,    -1,
      -1,    -1,    -1,   456,    -1,    -1,    -1,    -1,    -1,    -1,
    1940,    -1,    -1,  1943,    -1,    -1,  1946,    -1,    -1,    -1,
    1950,    -1,    -1,    -1,    -1,  1955,  1956,  1957,  1958,  1959,
    1960,  1961,  1962,  1963,  1964,    -1,    -1,    -1,    -1,  1276,
      -1,    -1,    -1,    -1,  1974,    -1,    -1,  1977,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   764,    -1,    -1,    -1,
     768,    -1,    -1,  1300,    -1,    -1,    -1,    -1,    -1,  1306,
      -1,    -1,   780,   781,    -1,    -1,    -1,  1314,    -1,  1316,
    1317,  1318,    -1,   536,   537,  1322,  1323,    -1,  1325,    -1,
    1327,    -1,  1329,    -1,  1331,  1332,  1333,  2027,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,    -1,  1350,    -1,  2045,   215,  2047,  2048,  2049,
    2050,  2051,    -1,   222,   832,   224,    -1,    -1,  1365,   582,
     583,   584,    -1,    -1,    -1,    -1,  1373,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,    -1,    -1,    -1,    -1,   215,    -1,    -1,    -1,    -1,
     613,  2091,  2092,    -1,   224,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2102,  2103,  2104,  2105,   884,    -1,   886,    -1,
      -1,   889,    -1,    -1,    -1,    -1,   639,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   902,    -1,   904,   624,   906,    -1,
     908,    -1,    -1,    -1,    -1,   913,   659,    -1,    -1,    -1,
     918,    -1,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,    -1,    -1,    -1,    -1,
     215,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1475,   224,
     667,   668,   669,   670,   671,   672,   673,   674,   675,   676,
     677,  1488,   679,   680,   681,   682,   683,   684,   685,    -1,
      -1,    -1,   689,   690,   691,    -1,    -1,    -1,   695,   696,
      -1,   698,    -1,   981,    -1,    -1,   703,   704,   705,    -1,
     707,    -1,    -1,    -1,    -1,    -1,    -1,   714,   715,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,    -1,    -1,   732,    -1,   215,    -1,    -1,
      -1,   764,    -1,    -1,    -1,   768,   224,    -1,    -1,    -1,
      -1,    -1,  1559,    -1,    -1,  1033,  1034,  1035,  1036,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,    -1,    -1,    -1,    -1,   215,  1585,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   224,    -1,  1595,    -1,
      -1,    -1,    21,    22,    -1,    -1,    -1,    -1,  1605,    -1,
      -1,    -1,    -1,  1610,    -1,    -1,    -1,    -1,    -1,   832,
      -1,    -1,    -1,    -1,    -1,  1093,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1636,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,    -1,    -1,    -1,    -1,   215,    -1,
      -1,    -1,  1659,    -1,    -1,    -1,    -1,   224,    -1,    -1,
      -1,   884,    -1,   886,    -1,    -1,   889,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   902,
      -1,   904,    -1,   906,    -1,   908,    -1,    -1,    -1,  1696,
     913,   120,    -1,    -1,    -1,   918,    -1,   894,    -1,    -1,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,    -1,    -1,    -1,   157,   158,
     159,   160,    -1,   162,   163,   164,   165,   166,   167,    -1,
      -1,   170,    -1,    -1,    -1,    -1,    -1,   176,   177,    12,
      13,    -1,    -1,   182,   183,    -1,    -1,    -1,   981,    -1,
    1767,    -1,    -1,    -1,    -1,    -1,    -1,  1774,  1775,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1786,
      -1,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,    -1,    -1,    -1,  1805,   215,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   224,    -1,
    1033,  1034,  1035,  1036,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    -1,    -1,    -1,    98,    -1,   100,    -1,    -1,
      -1,  1038,   105,   106,   107,   108,    -1,   110,   111,   112,
      -1,    -1,    -1,   116,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1868,    -1,    -1,    -1,    -1,    -1,    -1,   131,    -1,
    1093,    -1,    -1,    -1,  1071,  1072,    -1,    -1,    -1,    -1,
    1887,    -1,    -1,   312,    -1,    -1,   315,   316,   317,   318,
     153,   154,   155,    -1,    -1,    -1,    -1,  1375,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   335,    -1,    -1,     3,
       4,     5,    -1,    -1,    -1,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    -1,  1976,
      -1,    65,    66,    67,    -1,    -1,    70,    -1,    72,    73,
      74,    -1,    -1,    -1,    -1,    -1,    80,    81,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,    -1,    -1,    -1,    -1,   215,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   224,    -1,    -1,    -1,    -1,
      -1,   450,    -1,    -1,    -1,    -1,    -1,  1224,    -1,    -1,
      -1,    -1,    -1,  1230,  1231,  1232,  1233,  1234,    -1,  1236,
      -1,  1238,  1239,    -1,  1241,  1242,    -1,    -1,  1245,  1246,
    1247,  1529,  1530,    -1,    -1,  1252,    -1,    -1,    -1,    -1,
      12,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   169,    -1,    -1,    -1,    -1,
      -1,  2088,   176,   177,   178,   179,   180,  1565,    -1,    -1,
     184,   185,   186,   187,   188,   189,    -1,   191,   192,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   206,   207,    -1,    -1,    -1,   211,    -1,    -1,
      -1,    -1,   216,    -1,   218,    -1,   220,   221,    -1,   223,
       5,   225,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    -1,    -1,    -1,    98,    -1,   100,    -1,
      -1,    -1,  1375,   105,   106,   107,   108,    -1,   110,   111,
     112,    -1,    -1,    -1,   116,    -1,    -1,    -1,    -1,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    -1,    -1,
      -1,    -1,    57,    58,    59,    60,    -1,    -1,  1385,    -1,
      65,    66,    67,    -1,    -1,    70,    -1,    -1,    -1,    -1,
      -1,   153,   154,   155,  1401,    -1,    81,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,  1418,    -1,    -1,    -1,   215,  1423,    -1,    -1,    -1,
    1708,    -1,    -1,    -1,   224,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,    -1,
    1728,    -1,    -1,   215,    -1,    -1,    -1,    -1,  1455,  1456,
      -1,   223,  1459,  1460,    -1,    -1,    -1,  1745,    -1,    -1,
      -1,    -1,   224,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,    -1,    -1,    -1,
      -1,   215,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     224,    -1,   177,   178,   179,    -1,  1529,  1530,    -1,    -1,
      -1,  1789,    -1,    -1,   189,    -1,   191,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,    -1,    -1,
      -1,  1809,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    53,    54,    55,    56,
      -1,    -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    72,    73,    74,    -1,    -1,
      -1,  1598,  1599,    80,    -1,  1602,  1603,    84,    -1,    -1,
      87,  1608,  1609,    90,    -1,    92,    -1,    -1,    -1,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,    -1,   111,    -1,    -1,   215,    -1,    -1,
      -1,   118,   119,   120,   121,   122,   224,    -1,   125,   126,
     127,    -1,    -1,   130,    -1,    -1,   133,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,    -1,    -1,    -1,    -1,   215,    -1,  1955,  1956,  1957,
    1958,  1959,    -1,    -1,   224,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   176,
      -1,    -1,    -1,   180,    -1,  1728,    -1,   184,   185,   186,
     187,   188,    -1,    -1,    -1,   192,    -1,    -1,  1715,  1716,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   206,
     207,    -1,    -1,    -1,   211,    -1,    -1,    -1,    -1,   216,
      -1,    -1,    -1,    -1,   221,    -1,   223,   224,    -1,    -1,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,    -1,    -1,  1789,  2045,   215,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   224,    -1,    -1,
      -1,    -1,    -1,    -1,  1013,  1014,  1809,    -1,     3,     4,
    1019,  1020,    -1,    -1,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,    54,
      55,    56,    -1,    -1,    -1,    -1,    61,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,    73,    74,
      -1,    -1,    -1,    -1,    -1,    80,    -1,    -1,    -1,    84,
      -1,    -1,    87,    -1,    -1,    90,    -1,    92,    -1,    -1,
      -1,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,    -1,   111,    -1,    -1,   215,
      -1,    -1,    -1,   118,   119,   120,   121,   122,   224,    -1,
     125,   126,   127,    -1,    -1,   130,    -1,    -1,   133,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1955,  1956,  1957,  1958,  1959,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,    -1,    -1,    -1,    -1,   215,    -1,    -1,    -1,    -1,
      -1,   176,    -1,    -1,   224,   180,    -1,    -1,    -1,   184,
     185,   186,   187,   188,    -1,    -1,    -1,   192,    -1,    -1,
      -1,    -1,    -1,    -1,  1213,  1214,    -1,    -1,    -1,  1218,
    1219,   206,   207,    -1,    -1,    -1,   211,    -1,    -1,    -1,
      -1,   216,    -1,    -1,    -1,    -1,   221,    -1,    -1,   224,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
      -1,    -1,  2045,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    -1,    -1,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    12,    13,    -1,    65,
      66,    67,  2079,    -1,    70,    -1,    72,    73,    74,    -1,
      -1,    -1,    -1,    -1,    80,    81,    -1,    -1,    84,    -1,
      -1,    87,    -1,    -1,    90,    -1,    92,    -1,    -1,    -1,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,    -1,   111,    -1,    -1,   215,    -1,
      -1,    -1,   118,   119,   120,   121,   122,   224,    -1,   125,
     126,   127,    -1,    -1,   130,    -1,    -1,   133,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    -1,
      -1,    -1,    98,    -1,   100,    -1,    -1,    -1,    -1,   105,
     106,   107,   108,    -1,   110,   111,   112,    -1,    -1,    -1,
     116,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     176,   177,   178,   179,   180,    -1,    -1,    -1,   184,   185,
     186,   187,   188,   189,    -1,   191,   192,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   153,   154,   155,
     206,   207,    -1,    -1,    -1,   211,    -1,    -1,    -1,    -1,
     216,    -1,     3,     4,     5,   221,    -1,   223,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    -1,    -1,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    -1,    -1,    -1,    65,    66,    67,    -1,    -1,    70,
      -1,    72,    73,    74,    -1,    -1,    -1,    -1,    -1,    80,
      81,    -1,    -1,    84,    -1,    -1,    87,    -1,    -1,    90,
      -1,    92,    -1,    -1,    -1,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,    -1,
     111,    -1,    -1,   215,    -1,    -1,    -1,   118,   119,   120,
     121,   122,   224,    -1,   125,   126,   127,    -1,    -1,   130,
      -1,    -1,   133,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,    -1,    -1,    -1,
      -1,   215,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     224,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   176,   177,   178,   179,   180,
      -1,    -1,    -1,   184,   185,   186,   187,   188,   189,    -1,
     191,   192,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   206,   207,    -1,    -1,    -1,
     211,    -1,    -1,    -1,    -1,   216,    -1,     3,     4,     5,
     221,    -1,   223,     9,    10,    11,    -1,    -1,    14,    15,
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
      73,    74,    -1,    -1,    -1,    -1,    -1,    80,    81,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,    -1,    -1,    -1,    -1,   215,    -1,    -1,
     176,   177,   178,   179,   180,    -1,   224,    -1,   184,   185,
     186,   187,   188,   189,    -1,   191,   192,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     206,   207,    -1,    -1,    -1,   211,    -1,    -1,    -1,    -1,
     216,    -1,    -1,    -1,    -1,   221,    -1,   223,    -1,    -1,
      -1,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,    -1,    -1,    -1,    -1,   215,
      -1,    -1,    -1,   176,   177,   178,   179,   180,   224,    -1,
      -1,   184,   185,   186,   187,   188,   189,    -1,   191,   192,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   206,   207,    -1,    -1,    -1,   211,    -1,
      -1,    -1,    -1,   216,    -1,     3,     4,     5,   221,    -1,
     223,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    12,    13,    -1,    65,    66,    67,
      -1,    -1,    70,    -1,    72,    73,    74,    -1,    -1,    -1,
      -1,    -1,    80,    81,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,    -1,    -1,
      -1,    -1,   215,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   224,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,    -1,    -1,    -1,    -1,
     215,    -1,   217,    -1,   219,    -1,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    -1,    -1,    -1,
      98,    -1,   100,    -1,    -1,    -1,    -1,   105,   106,   107,
     108,    -1,   110,   111,   112,    -1,    -1,    -1,   116,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   176,   177,
     178,   179,   180,    -1,    -1,    -1,   184,   185,   186,   187,
     188,   189,    -1,   191,   192,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   153,   154,   155,   206,   207,
      -1,    -1,    -1,   211,    -1,    -1,    -1,    -1,   216,    -1,
       3,     4,     5,   221,    -1,   223,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      53,    54,    55,    56,    -1,    -1,   224,    -1,    61,    12,
      13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,
      73,    74,    -1,    -1,    -1,    -1,    -1,    80,    -1,    -1,
      -1,    84,    -1,    -1,    87,    -1,    -1,    90,    -1,    92,
      -1,    -1,    -1,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,    -1,   111,    -1,
      -1,   215,    -1,    -1,    -1,   118,   119,   120,   121,   122,
     224,    -1,   125,   126,   127,    -1,    -1,   130,    -1,    -1,
     133,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    -1,    -1,    -1,    98,    -1,   100,    -1,    -1,
      -1,    -1,   105,   106,   107,   108,    -1,   110,   111,   112,
      -1,    -1,    -1,   116,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   176,    -1,    -1,    -1,   180,    -1,    -1,
      -1,   184,   185,   186,   187,   188,    -1,    -1,    -1,   192,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     153,   154,   155,   206,   207,    -1,    -1,    -1,   211,    -1,
      -1,    -1,    -1,   216,    -1,     3,     4,     5,   221,    -1,
     223,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    53,    54,    55,    56,    -1,
      -1,   224,    -1,    61,    12,    13,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    72,    73,    74,    -1,    -1,    -1,
      -1,    -1,    80,    -1,    -1,    -1,    84,    -1,    -1,    87,
      -1,    -1,    90,    -1,    92,    -1,    -1,    -1,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,    -1,   111,    -1,    -1,   215,    -1,    -1,    -1,
     118,   119,   120,   121,   122,   224,    -1,   125,   126,   127,
      -1,    -1,   130,    -1,    -1,   133,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    -1,    -1,    -1,
      98,    -1,   100,    -1,    -1,    -1,    -1,   105,   106,   107,
     108,    -1,   110,   111,   112,    -1,    -1,    -1,   116,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   176,    -1,
      -1,    -1,   180,    -1,    -1,    -1,   184,   185,   186,   187,
     188,    -1,    -1,    -1,   192,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   153,   154,   155,   206,   207,
      -1,    -1,    -1,   211,    -1,    -1,    -1,    -1,   216,    -1,
       3,     4,    -1,   221,    -1,   223,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      53,    54,    55,    56,    -1,    -1,   224,    -1,    61,    12,
      13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,
      73,    74,    -1,    -1,    -1,    -1,    -1,    80,    -1,    -1,
      -1,    84,    -1,    -1,    87,    -1,    -1,    90,    -1,    92,
      -1,    -1,    -1,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,    -1,   111,    -1,
      -1,   215,    -1,    -1,    -1,   118,   119,   120,   121,   122,
     224,    -1,   125,   126,   127,    -1,    -1,   130,    -1,    -1,
     133,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    -1,    -1,    -1,    98,    -1,   100,    -1,    -1,
      -1,    -1,   105,   106,   107,   108,    -1,   110,   111,   112,
      -1,    -1,    -1,   116,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   176,    -1,    -1,    -1,   180,    -1,    -1,
      -1,   184,   185,   186,   187,   188,    -1,    -1,    -1,   192,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     153,   154,   155,   206,   207,    -1,    -1,    -1,   211,    -1,
      -1,    -1,    -1,   216,    -1,     3,     4,    -1,   221,    -1,
     223,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    53,    54,    55,    56,    -1,
      -1,   224,    -1,    61,    12,    13,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    72,    73,    74,    -1,    -1,    -1,
      -1,    -1,    80,    -1,    -1,    -1,    84,    -1,    -1,    87,
      -1,    -1,    90,    -1,    92,    -1,    -1,    -1,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,    -1,   111,    -1,    -1,   215,    -1,    -1,    -1,
     118,   119,   120,   121,   122,   224,    -1,   125,   126,   127,
      -1,    -1,   130,    -1,    -1,   133,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    -1,    -1,    -1,
      98,    -1,   100,    -1,    -1,    -1,    -1,   105,   106,   107,
     108,    -1,   110,   111,   112,    -1,    -1,    -1,   116,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   176,    -1,
      -1,    -1,   180,    -1,    -1,    -1,   184,   185,   186,   187,
     188,    -1,    -1,    -1,   192,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   153,   154,   155,   206,   207,
      -1,    -1,    -1,   211,    -1,    -1,    -1,    -1,   216,    -1,
       3,     4,    -1,   221,    -1,   223,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      53,    54,    55,    56,    -1,    -1,   224,    -1,    61,    12,
      13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,
      73,    74,    -1,    -1,    -1,    -1,    -1,    80,    -1,    -1,
      -1,    84,    -1,    -1,    87,    -1,    -1,    90,    -1,    92,
      -1,    -1,    -1,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,    -1,   111,    -1,
      -1,   215,    -1,    -1,    -1,   118,   119,   120,   121,   122,
     224,    -1,   125,   126,   127,    -1,    -1,   130,    -1,    -1,
     133,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    -1,    -1,    -1,    98,    -1,   100,    -1,    -1,
      -1,    -1,   105,   106,   107,   108,    -1,   110,   111,   112,
      -1,    -1,    -1,   116,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   176,    -1,    -1,    -1,   180,    -1,    -1,
      -1,   184,   185,   186,   187,   188,    -1,    -1,    -1,   192,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     153,   154,   155,   206,   207,    -1,    -1,    -1,   211,    -1,
      -1,    -1,    -1,   216,    -1,     3,     4,    -1,   221,    -1,
     223,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    53,    54,    55,    56,    -1,
      -1,   224,    -1,    61,    12,    13,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    72,    73,    74,    -1,    -1,    -1,
      -1,    -1,    80,    -1,    -1,    -1,    84,    -1,    -1,    87,
      -1,    -1,    90,    -1,    92,    -1,    -1,    -1,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,    -1,   111,    -1,    -1,   215,    -1,    -1,    -1,
     118,   119,   120,   121,   122,   224,    -1,   125,   126,   127,
      -1,    -1,   130,    -1,    -1,   133,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    -1,    -1,    -1,
      98,    -1,   100,    -1,    -1,    -1,    -1,   105,   106,   107,
     108,    -1,   110,   111,   112,    -1,    -1,    -1,   116,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   176,    -1,
      -1,    -1,   180,    -1,    -1,    -1,   184,   185,   186,   187,
     188,    -1,    -1,    -1,   192,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   153,   154,   155,   206,   207,
      -1,    -1,    -1,   211,    -1,    -1,    -1,    -1,   216,    -1,
       3,     4,    -1,   221,    -1,   223,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      53,    54,    55,    56,    -1,    -1,   224,    -1,    61,    12,
      13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,
      73,    74,    -1,    -1,    -1,    -1,    -1,    80,    -1,    -1,
      -1,    84,    -1,    -1,    87,    -1,    -1,    90,    -1,    92,
      -1,    -1,    -1,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,    -1,   111,    -1,
      -1,   215,    -1,    -1,    -1,   118,   119,   120,   121,   122,
     224,    -1,   125,   126,   127,    -1,    -1,   130,    -1,    -1,
     133,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    -1,    -1,    -1,    98,    -1,   100,    -1,    -1,
      -1,    -1,   105,   106,   107,   108,    -1,   110,   111,   112,
      -1,    -1,    -1,   116,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   176,    -1,    -1,    -1,   180,    -1,    -1,
      -1,   184,   185,   186,   187,   188,    -1,    -1,    -1,   192,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     153,   154,   155,   206,   207,    -1,    -1,    -1,   211,    -1,
      -1,    -1,    -1,   216,    -1,     3,     4,    -1,   221,    -1,
     223,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    53,    54,    55,    56,    -1,
      -1,   224,    -1,    61,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    72,    73,    74,    -1,    -1,    -1,
      -1,    -1,    80,    -1,    -1,    -1,    84,    -1,    -1,    87,
      -1,    -1,    90,    -1,    92,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     4,     5,    -1,
      -1,    -1,    -1,   111,    -1,    -1,    -1,    -1,    -1,    -1,
     118,   119,   120,   121,   122,    -1,    -1,   125,   126,   127,
      -1,    -1,   130,    -1,    -1,   133,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    -1,    -1,    -1,    -1,
      57,    58,    59,    60,    -1,    -1,    -1,    -1,    65,    66,
      67,    -1,    -1,    70,    -1,    -1,    -1,    -1,   176,    -1,
      -1,    -1,   180,    -1,    81,    -1,   184,   185,   186,   187,
     188,    -1,    -1,    -1,   192,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   206,   207,
      -1,    -1,    -1,   211,    -1,    -1,    -1,    -1,   216,    -1,
       3,     4,    -1,   221,    -1,   223,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      53,    54,    55,    56,    -1,    -1,    -1,    -1,    61,    -1,
     177,   178,   179,    -1,    -1,    -1,    -1,    -1,    -1,    72,
      73,    74,   189,    -1,   191,   192,    -1,    80,    -1,    -1,
      -1,    84,    -1,    -1,    87,    -1,    -1,    90,    -1,    92,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     4,     5,    -1,    -1,    -1,    -1,   111,    -1,
      -1,    -1,    -1,    -1,    -1,   118,   119,   120,   121,   122,
      -1,    -1,   125,   126,   127,    -1,    -1,   130,    -1,    -1,
     133,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    -1,    -1,    -1,    -1,    57,    58,    59,    60,    -1,
      -1,    -1,    -1,    65,    66,    67,    -1,    -1,    70,    -1,
      -1,    -1,    -1,   176,    -1,    -1,    -1,   180,    -1,    81,
      -1,   184,   185,   186,   187,   188,    -1,    -1,    -1,   192,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   206,   207,    -1,    -1,    -1,   211,    -1,
      -1,    -1,    -1,   216,    -1,     3,     4,    -1,   221,    -1,
     223,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    53,    54,    55,    56,    -1,
      -1,    -1,    -1,    61,    -1,   177,   178,   179,    -1,    -1,
      -1,    -1,    -1,    -1,    72,    73,    74,   189,    -1,   191,
     192,    -1,    80,    -1,    -1,    -1,    84,    -1,    -1,    87,
      -1,    -1,    90,    -1,    92,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     4,     5,    -1,
      -1,    -1,    -1,   111,    -1,    -1,    -1,    -1,    -1,    -1,
     118,   119,   120,   121,   122,    -1,    -1,   125,   126,   127,
      -1,    -1,   130,    -1,    -1,   133,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    -1,    -1,    -1,    -1,
      57,    58,    59,    60,    -1,    -1,    -1,    -1,    65,    66,
      67,    -1,    -1,    70,    -1,    -1,    -1,    -1,   176,    -1,
      -1,    -1,   180,    -1,    81,    -1,   184,   185,   186,   187,
     188,    -1,    -1,    -1,   192,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   206,   207,
      -1,    -1,    -1,   211,    -1,    -1,    -1,    -1,   216,    -1,
       3,     4,    -1,   221,    -1,   223,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      53,    54,    55,    56,    -1,    -1,    -1,    -1,    61,    -1,
     177,   178,   179,    -1,    -1,    -1,    -1,    -1,    -1,    72,
      73,    74,   189,    -1,   191,    -1,    -1,    80,    -1,    -1,
      -1,    84,    -1,    -1,    87,    -1,    -1,    90,    -1,    92,
      -1,    -1,    -1,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,    -1,   111,    -1,
      -1,   215,    -1,    -1,    -1,   118,   119,   120,   121,   122,
     224,    -1,   125,   126,   127,    -1,    -1,   130,    -1,    -1,
     133,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,    -1,    -1,    -1,    -1,   215,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   224,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   176,    -1,    -1,    -1,   180,    -1,    -1,
      -1,   184,   185,   186,   187,   188,    -1,    -1,    -1,   192,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   206,   207,    -1,    -1,    -1,   211,    -1,
      -1,    -1,    -1,   216,    -1,     3,     4,    -1,   221,    -1,
     223,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    53,    54,    55,    56,    -1,
      -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    72,    73,    74,    -1,    -1,    -1,
      -1,    -1,    80,    -1,    -1,    -1,    84,    -1,    -1,    87,
      -1,    -1,    90,    -1,    92,    -1,    -1,    -1,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,    -1,   111,    -1,    -1,   215,    -1,    -1,    -1,
     118,   119,   120,   121,   122,   224,    -1,   125,   126,   127,
      -1,    -1,   130,    -1,    -1,   133,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
      -1,    -1,    -1,    -1,   215,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   224,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   176,    -1,
      -1,    -1,   180,    -1,    -1,    -1,   184,   185,   186,   187,
     188,    -1,    -1,    -1,   192,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   206,   207,
      -1,    -1,    -1,   211,    -1,    -1,    -1,    -1,   216,    -1,
       3,     4,     5,   221,    -1,   223,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    -1,
      -1,    -1,    65,    66,    67,    -1,    -1,    70,    -1,    72,
      73,    74,    -1,    -1,    -1,    -1,    -1,    80,    81,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,    -1,    -1,    -1,    -1,   215,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   224,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,    -1,    -1,    -1,    -1,   215,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   224,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,    -1,
      -1,    -1,    -1,   215,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   223,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   176,   177,   178,   179,   180,    -1,    -1,
      -1,   184,   185,   186,   187,   188,   189,    -1,   191,   192,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   206,   207,    -1,    -1,    -1,   211,     3,
       4,    -1,    -1,   216,    -1,     9,    10,    11,   221,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,
      54,    55,    56,    -1,    -1,    -1,    -1,    61,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,    73,
      74,    -1,    -1,    -1,    -1,    -1,    80,    -1,    -1,    -1,
      84,    -1,    -1,    87,    -1,    -1,    90,    -1,    92,    -1,
      -1,    -1,    -1,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   111,    -1,    -1,
      -1,   215,    -1,    -1,   118,   119,   120,   121,   122,   223,
      -1,   125,   126,   127,    -1,    -1,   130,    -1,    -1,   133,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,    -1,    -1,    -1,    -1,   215,    -1,
     217,    -1,   219,    -1,    -1,   222,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
      -1,    -1,   176,    -1,   215,    -1,   180,    -1,   219,    -1,
     184,   185,   186,   187,   188,    -1,    -1,    -1,   192,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   206,   207,    -1,    -1,    -1,   211,     3,     4,
      -1,    -1,   216,    -1,     9,    10,    11,   221,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    -1,    -1,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,    53,    54,
      55,    56,   215,    -1,   217,    -1,    61,    -1,    -1,   222,
      -1,    -1,    -1,    -1,    -1,     3,     4,    72,    73,    74,
      -1,     9,    10,    11,    -1,    80,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    -1,
      -1,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,    53,    54,    55,    56,   215,
      -1,    -1,    -1,    61,    -1,    -1,   222,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    72,    73,    74,    -1,    -1,    -1,
      -1,    -1,    80,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,    -1,    -1,    -1,
      -1,   215,    -1,    -1,    -1,    -1,    -1,    -1,   222,    -1,
      -1,   176,    -1,    -1,    -1,   180,    -1,    -1,    -1,   184,
     185,   186,   187,   188,    -1,    -1,    -1,   192,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   206,   207,    -1,    -1,    -1,   211,    -1,    -1,    -1,
      -1,   216,   217,    -1,    -1,    -1,   221,    -1,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,    -1,    -1,    -1,    -1,   215,    -1,   176,    -1,
      -1,    -1,   180,   222,    -1,    -1,   184,   185,   186,   187,
     188,    -1,    -1,    -1,   192,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   206,   207,
      -1,    -1,    -1,   211,    -1,    -1,    -1,    -1,   216,     3,
       4,   219,     6,   221,    -1,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    -1,    -1,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,    53,
      54,    55,    56,   215,    -1,    -1,    -1,    61,    -1,    -1,
     222,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,    73,
      74,     3,     4,    -1,     6,    -1,    80,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    -1,    -1,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,    53,    54,    55,    56,   215,    -1,    -1,    -1,    61,
      -1,    -1,   222,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      72,    73,    74,    -1,    -1,    -1,    -1,    -1,    80,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,    -1,    -1,    -1,    -1,   215,    -1,    -1,
      -1,    -1,   176,    -1,   222,    -1,   180,    -1,    -1,    -1,
     184,   185,   186,   187,   188,    -1,    -1,    -1,   192,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   206,   207,    -1,    -1,    -1,   211,    -1,    -1,
      -1,    -1,   216,    -1,    -1,    -1,    -1,   221,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,    -1,    -1,    -1,    -1,   215,    -1,    -1,    -1,
      -1,    -1,    -1,   222,   176,    -1,    -1,    -1,   180,    -1,
      -1,    -1,   184,   185,   186,   187,   188,    -1,    -1,    -1,
     192,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   206,   207,    -1,    -1,    -1,   211,
       3,     4,    -1,    -1,   216,    -1,     9,    10,    11,   221,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
      53,    54,    55,    56,   215,    -1,    -1,    -1,    61,    -1,
      -1,   222,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,
      73,    74,    -1,    -1,    -1,    -1,    -1,    80,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,    -1,    -1,    -1,    -1,   215,    -1,    -1,    -1,
      -1,    -1,    -1,   222,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,    -1,    -1,
      -1,    -1,   215,    -1,    -1,    -1,    -1,    -1,    -1,   222,
      -1,    -1,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,    -1,    -1,     0,     1,
     215,    -1,     4,    -1,    -1,    -1,    -1,   222,    -1,    -1,
      12,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   176,    -1,    -1,    -1,   180,    -1,    -1,
      -1,   184,   185,   186,   187,   188,    -1,    -1,    -1,   192,
      42,    43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   206,   207,    -1,    -1,    -1,   211,    -1,
      62,    63,    64,   216,    -1,    -1,    68,    69,   221,    71,
      -1,    -1,    -1,    75,    76,    -1,    78,    79,    -1,    -1,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    -1,    -1,    -1,    98,    -1,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,    -1,   115,   116,   117,   118,   119,   120,   121,
     122,   123,    -1,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,    -1,    -1,    -1,   139,   140,   141,
      -1,    -1,    -1,    -1,    -1,   147,     4,    -1,    -1,    -1,
     152,   153,   154,   155,    12,    13,   158,    -1,   160,    -1,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,    -1,    -1,    -1,    -1,    -1,   181,
     182,   183,    -1,    -1,    42,    43,    -1,    -1,   190,    -1,
     192,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    62,    63,    64,    -1,    -1,    -1,
      68,    69,    -1,    71,    -1,    -1,    -1,    75,    76,    -1,
      78,    79,    -1,    -1,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    -1,    -1,    -1,
      98,    -1,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,    -1,   115,   116,   117,
     118,   119,   120,   121,   122,   123,    -1,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,    -1,    -1,
      -1,   139,   140,   141,    -1,    -1,    -1,    -1,    -1,   147,
      -1,    -1,    -1,    -1,   152,   153,   154,   155,    -1,    -1,
     158,    -1,   160,    -1,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,    -1,    -1,
      -1,    -1,    -1,   181,   182,   183,    -1,    -1,    -1,    -1,
      -1,    -1,   190,    -1,   192,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,    -1,
      -1,    -1,    -1,   215,    -1,    -1,    -1,    -1,    -1,    -1,
     222,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,    -1,    -1,    -1,    -1,   215,
      -1,    -1,    -1,    -1,    -1,    -1,   222,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,    -1,    -1,    -1,    -1,   215,    -1,    -1,    -1,    -1,
      -1,    -1,   222,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,    -1,    -1,    -1,
      -1,   215,    -1,    -1,    -1,    -1,    -1,    -1,   222,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,    -1,    -1,    -1,    -1,   215,    -1,    -1,
      -1,    -1,    -1,    -1,   222,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,    -1,
      -1,    -1,    -1,   215,    -1,    -1,    -1,    -1,    -1,    -1,
     222,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,    -1,    -1,    -1,    -1,   215,
      -1,    -1,    -1,    -1,    -1,    -1,   222,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,    -1,    -1,    -1,    -1,   215,    -1,    -1,    -1,    -1,
      -1,    -1,   222,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,    -1,    -1,    -1,
      -1,   215,    -1,    -1,    -1,    -1,    -1,    -1,   222,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,    -1,    -1,    -1,    -1,   215,    -1,    -1,
      -1,    -1,    -1,    -1,   222,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,    -1,
      -1,    -1,    -1,   215,    -1,    -1,    -1,    -1,    -1,    -1,
     222,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,    -1,    -1,    -1,    -1,   215,
      -1,    -1,    -1,    -1,    -1,    -1,   222,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,    -1,    -1,    -1,    -1,   215,    -1,    -1,    -1,    -1,
      -1,    -1,   222,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,    -1,    -1,    -1,
      -1,   215,    -1,    -1,    -1,    -1,    -1,    -1,   222,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,    -1,    -1,    -1,    -1,   215,    -1,    -1,
      -1,    -1,    -1,    -1,   222,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,    -1,
      -1,    -1,    -1,   215,    -1,    -1,    -1,    -1,    -1,    -1,
     222,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,    -1,    -1,    -1,    -1,   215,
      -1,    -1,    -1,    -1,    -1,    -1,   222,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,    -1,    -1,    -1,    -1,   215,    -1,    -1,    -1,    -1,
      -1,    -1,   222,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,    -1,    -1,    -1,
      -1,   215,    -1,    -1,    -1,    -1,    -1,    -1,   222,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,    -1,    -1,    -1,    -1,   215,    -1,    -1,
      -1,    -1,    -1,    -1,   222,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,    -1,
      -1,    -1,    -1,   215,    -1,    -1,    -1,    -1,    -1,    -1,
     222,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,    -1,    -1,    -1,    -1,   215,
      -1,    -1,    -1,    -1,    -1,    -1,   222,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,    -1,    -1,    -1,    -1,   215,    -1,    -1,    -1,    -1,
      -1,    -1,   222,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,    -1,    -1,    -1,
      -1,   215,    -1,    -1,    -1,    -1,    -1,    -1,   222,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,    -1,    -1,    -1,    -1,   215,    -1,    -1,
      -1,    -1,    -1,    -1,   222,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,    -1,
      -1,    -1,    -1,   215,    -1,    -1,    -1,    -1,    -1,    -1,
     222,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,    -1,    -1,    -1,    -1,   215,
      -1,    -1,    -1,    -1,    -1,    -1,   222,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,    -1,    -1,    -1,    -1,   215,    -1,    -1,    -1,    -1,
      -1,    -1,   222,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,    -1,    -1,    -1,
      -1,   215,    -1,    -1,    -1,    -1,    -1,    -1,   222,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,    -1,    -1,    -1,    -1,   215,    -1,    -1,
      -1,    -1,    -1,    -1,   222,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,    -1,
      -1,    -1,    -1,   215,    -1,    -1,    -1,    -1,    -1,    -1,
     222,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,    -1,    -1,    -1,    -1,   215,
      -1,    -1,    -1,    -1,    -1,    -1,   222,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,    -1,    -1,    -1,    -1,   215,    -1,    -1,    -1,    -1,
      -1,    -1,   222,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,    -1,    -1,    -1,
      -1,   215,    -1,    -1,    -1,    -1,    -1,    -1,   222,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,    -1,    -1,    -1,    -1,   215,    -1,    -1,
      -1,    -1,    -1,    -1,   222,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,    -1,
      -1,    -1,    -1,   215,    -1,    -1,    -1,    -1,    -1,    -1,
     222,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,    -1,    -1,    -1,    -1,   215,
      -1,    -1,    -1,    -1,    -1,    -1,   222,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,    -1,    -1,    -1,    -1,   215,    -1,    -1,    -1,    -1,
      -1,    -1,   222,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,    -1,    -1,    -1,
      -1,   215,    -1,    -1,    -1,    -1,    -1,    -1,   222,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,    -1,    -1,    -1,    -1,   215,    -1,    -1,
      -1,    -1,    -1,    -1,   222,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,    -1,
      -1,    -1,    -1,   215,    -1,    -1,    -1,    -1,    -1,    -1,
     222,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,    -1,    -1,    -1,    -1,   215,
      -1,    -1,    -1,    -1,    -1,    -1,   222,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,    -1,    -1,    -1,    -1,   215,    -1,    -1,    -1,    -1,
      -1,    -1,   222,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,    -1,    -1,    -1,
      -1,   215,    -1,    -1,    -1,    -1,    -1,    -1,   222,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,    -1,    -1,    -1,    -1,   215,    -1,    -1,
      -1,   219,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,    -1,    -1,    -1,    -1,
     215,    -1,    -1,    -1,   219,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,    -1,
      -1,    -1,    -1,   215,    -1,    -1,    -1,   219,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,    -1,    -1,    -1,    -1,   215,    -1,    -1,    -1,
     219,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,    -1,    -1,    -1,    -1,   215,
      -1,    -1,    -1,   219,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,    -1,    -1,
      -1,    -1,   215,    -1,    -1,    -1,   219,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,    -1,    -1,    -1,    -1,   215,    -1,    -1,    -1,   219,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,    -1,    -1,    -1,    -1,   215,    -1,
      -1,    -1,   219,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,    -1,    -1,    -1,
      -1,   215,    -1,    -1,    -1,   219,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
      -1,    -1,    -1,    -1,   215,    -1,    -1,    -1,   219,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,    -1,    -1,    -1,    -1,   215,    -1,    -1,
      -1,   219,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,    -1,    -1,    -1,    -1,
     215,    -1,    -1,    -1,   219,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,    -1,
      -1,    -1,    -1,   215,    -1,    -1,    -1,   219,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,    -1,    -1,    -1,    -1,   215,    -1,    -1,    -1,
     219,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,    -1,    -1,    -1,    -1,   215,
      -1,    -1,    -1,   219,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,    -1,    -1,
      -1,    -1,   215,    -1,    -1,    -1,   219,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,    -1,    -1,    -1,    -1,   215,    -1,   217,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,    -1,    -1,    -1,    -1,   215,    -1,   217,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,    -1,    -1,    -1,    -1,   215,    -1,   217,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,    -1,    -1,    -1,    -1,   215,    -1,
     217,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,    -1,    -1,    -1,    -1,   215,
      -1,   217,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,    -1,    -1,    -1,    -1,
     215,    -1,   217,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,    -1,    -1,    -1,
      -1,   215,    -1,   217,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,    -1,    -1,
      -1,    -1,   215,    -1,   217,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,    -1,
      -1,    -1,    -1,   215,    -1,   217,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
      -1,    -1,    -1,    -1,   215,    -1,   217,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,    -1,    -1,    -1,    -1,   215,    -1,   217,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,    -1,    -1,    -1,    -1,   215,    -1,   217,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,    -1,    -1,    -1,    -1,   215,    -1,   217,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,    -1,    -1,    -1,    -1,   215,    -1,
     217,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,    -1,    -1,    -1,    -1,   215,
      -1,   217,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,    -1,    -1,    -1,    -1,
     215,    -1,   217,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,    -1,    -1,    -1,
      -1,   215,    -1,   217,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,    -1,    -1,
      -1,    -1,   215,    -1,   217,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,    -1,
      -1,    -1,    -1,   215,    -1,   217,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
      -1,    -1,    -1,    -1,   215,    -1,   217,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,    -1,    -1,    -1,    -1,   215,    -1,   217,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,    -1,    -1,    -1,    -1,   215,    -1,   217,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,    -1,    -1,    -1,    -1,   215,    -1,   217,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,    -1,    -1,    -1,    -1,   215,    -1,
     217,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,    -1,    -1,    -1,    -1,   215,
      -1,   217,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,    -1,    -1,    -1,    -1,
     215,    -1,   217,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,    -1,    -1,    -1,
      -1,   215,    -1,   217,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,    -1,    -1,
      -1,    -1,   215,    -1,   217,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,    -1,
      -1,    -1,    -1,   215,    -1,   217,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
      -1,    -1,    -1,    -1,   215,    -1,   217,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,    -1,    -1,    -1,    -1,   215,    -1,   217,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,    -1,    -1,    -1,    -1,   215,    -1,   217,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,    -1,    -1,    -1,    -1,   215,    -1,   217,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,    -1,    -1,    -1,    -1,   215,    -1,
     217,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,    -1,    -1,    -1,    -1,   215,
      -1,   217,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,    -1,    -1,    -1,    -1,
     215,    -1,   217,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,    -1,    -1,    -1,
      -1,   215,    -1,   217,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,    -1,    -1,
      -1,    -1,   215,    -1,   217,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,    -1,
      -1,    -1,    -1,   215,    -1,   217,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
      -1,    -1,    -1,    -1,   215,    -1,   217,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,    -1,    -1,    -1,    -1,   215,    -1,   217,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,    -1,    -1,    -1,    -1,   215,    -1,   217,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,    -1,    -1,    -1,    -1,   215,    -1,   217,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,    -1,    -1,    -1,    -1,   215,    -1,
     217,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,    -1,    -1,    -1,    -1,   215,
      -1,   217,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,    -1,    -1,    -1,    -1,
     215,    -1,   217,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,    -1,    -1,    -1,
      -1,   215,    -1,   217,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,    -1,    -1,
      -1,    -1,   215,    -1,   217,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,    -1,
      -1,    -1,    -1,   215,    -1,   217,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
      -1,    -1,    -1,    -1,   215,    -1,   217,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,    -1,    -1,    -1,    -1,   215
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,   227,   228,     6,     0,     4,    12,    13,    42,
      43,    62,    63,    64,    68,    69,    71,    75,    76,    78,
      79,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    98,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   139,
     140,   141,   147,   152,   153,   154,   155,   158,   160,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   181,   182,   183,   190,   192,   229,   231,
     232,   252,   271,   272,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   299,   301,   302,   308,   309,   310,   311,
     329,   330,     3,     4,     5,     9,    10,    11,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    65,
      66,    67,    70,    72,    73,    74,    80,    81,   169,   176,
     177,   178,   179,   180,   184,   185,   186,   187,   188,   189,
     191,   206,   207,   211,   216,   218,   220,   221,   223,   225,
     250,   312,   313,   325,   326,   329,   330,    13,    90,   216,
     216,     6,   223,     6,     6,     6,     6,   216,     6,     6,
     218,   218,   216,   218,   250,   250,   216,   223,   216,   216,
       4,   216,   223,   216,   216,     4,   223,   216,   216,   216,
     216,    99,    90,    90,     6,   223,    84,    87,    90,   216,
     216,    90,    90,    87,    90,    92,    92,    84,    87,    90,
      92,    87,    90,    92,    87,    90,   216,    87,   158,   174,
     175,   223,   206,   207,   216,   223,   315,   316,   315,   223,
      84,    87,    90,   223,   315,     4,    84,    88,    94,    95,
      96,    97,   107,    90,    92,    90,    87,     4,   169,   223,
     329,   330,     4,     6,    84,    87,    90,    87,    90,     4,
       4,     4,     4,     5,    37,    38,    39,    40,    41,    84,
      87,    90,    92,   111,   207,   216,   223,   272,   283,   299,
     301,   312,   318,   319,   320,   329,   330,     4,   216,   216,
     216,     4,   223,   322,   330,     4,   216,   216,   216,     6,
       6,   218,     4,   326,   330,   216,     4,   326,     5,   223,
       5,   223,     4,   312,   329,   218,   216,   223,     6,   216,
     223,   216,   218,   225,   250,     7,   193,   194,   195,   196,
     213,   214,   248,   249,     4,   216,   218,   220,   250,   250,
     250,   250,   250,   250,   250,   250,   250,   250,   250,   250,
     250,   250,   250,   250,   250,   250,   250,   250,   250,   250,
     250,   250,   250,   216,   216,   216,   250,   250,   250,   250,
     216,   250,   250,   250,   250,   250,   250,   216,   250,   250,
     250,     7,   216,   216,   216,   250,   250,   216,   216,   218,
     312,   312,   312,   217,   312,   219,   312,     4,   158,   159,
     330,     4,   272,   273,   274,   223,   223,     6,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   215,   223,     6,   216,   218,   249,     6,   312,
       4,   325,   326,   329,   330,   325,   312,   325,   328,   254,
     259,   326,   330,   312,   207,   312,   320,   321,   312,   312,
     216,   312,   321,   312,   312,   216,   321,   312,   312,   312,
     312,   318,   216,   223,   321,   319,   319,   319,   325,   312,
     216,   216,   319,   319,   319,   216,   216,   216,   216,   216,
     216,   318,   216,   318,   216,   318,   223,   223,   312,     4,
     318,   322,   223,   223,   315,   315,   315,   312,   312,   206,
     207,   223,   223,   315,   223,   223,   223,   206,   207,   216,
     274,   315,   223,   216,   223,   216,   216,   216,   216,   216,
     216,   216,   319,   319,   318,   216,     4,   218,   218,   274,
       6,     6,   223,   223,   223,   319,   319,   218,   218,   218,
     216,   218,   220,   250,   216,   218,   250,   250,   250,   250,
       5,   161,   223,     5,   161,     5,   161,     5,   161,    84,
      87,    90,    92,   223,   312,   320,   312,   224,   321,     8,
     208,     6,   216,   218,   250,     6,   312,   312,   312,   220,
     312,   223,   161,   312,   312,   312,   312,     6,     6,   223,
       6,   274,     6,   274,   216,   218,   223,   216,   218,   325,
     312,   274,   318,   318,   217,   312,   219,   312,   223,   223,
     326,   318,     6,   218,   312,   312,     4,   312,   312,   312,
     312,   312,   312,   312,   312,   312,   312,   312,   312,   312,
     312,   312,   312,   312,   312,   312,   312,   312,   312,   328,
     325,   328,   325,   325,   325,   325,   325,   325,   325,   318,
     325,   325,   312,   325,   325,   325,   328,   325,   312,   326,
     312,   325,   325,   325,   325,   325,   330,   326,   330,     7,
     196,   248,   217,     7,   196,   248,   219,     7,   248,   249,
     220,     7,   250,   224,    84,    87,    90,    92,   271,   312,
     321,   312,   312,   312,   312,   312,   312,   312,   312,   312,
     312,   312,   312,   312,   312,   312,   233,   312,   312,     6,
     216,   218,   220,   217,   222,   216,   218,   217,   222,   222,
     217,   222,   219,   222,   253,   219,   253,   222,   222,   217,
     208,   222,   224,   217,   217,   312,   217,   224,   217,   217,
     312,   224,   217,   217,   217,   217,     7,   312,   312,   224,
       6,     6,     6,   217,   217,   312,   312,     7,     7,   305,
     305,   312,   265,   312,   326,   266,   312,   326,   267,   312,
     326,   268,   312,   326,   312,     6,   312,     6,   312,     6,
     321,   321,   223,   217,     6,   223,   274,   274,   222,   222,
     222,   315,   315,   273,   273,   222,   312,   312,   312,   312,
     287,   222,   274,   312,   312,   312,   312,   312,   312,   312,
     312,   312,     7,   306,     6,     7,   312,     6,   312,   312,
     224,   321,   321,   321,     6,     6,   312,   312,   312,   312,
     312,     4,   217,   219,   223,   251,   223,   312,   320,   223,
     320,   330,   312,   312,   325,   312,    62,   312,    62,    62,
      62,     5,   223,     5,   223,     5,   223,     5,   223,   321,
     217,   224,   312,   223,   312,   320,   312,   312,   223,   251,
     217,   217,   217,   158,   222,   274,   223,     8,   217,   217,
     219,   321,   224,   224,   274,   219,   217,   131,   300,   217,
     222,   224,     7,   196,   248,   217,     7,   196,   248,   219,
     312,   321,     6,     6,   312,   217,   219,   249,   251,   251,
     251,   251,   251,   251,   251,   251,   251,   251,   251,   222,
     251,   251,   251,   251,   251,   251,   251,   222,   222,   222,
     251,   222,   251,   251,   217,   217,   222,   251,   251,   222,
     251,   222,   222,   222,   222,   251,   251,   251,   217,   251,
     314,   327,     6,   222,   222,   217,   222,   251,   222,   251,
     217,   217,   219,    44,    44,   318,     7,   248,   249,    44,
      44,   318,   220,   248,   249,   326,   312,     6,     4,     4,
     223,   323,   251,   223,   223,   223,   223,   224,   224,     8,
       4,   148,   149,   150,   151,   224,   236,   240,   243,   245,
     246,   217,   219,   312,   312,     4,     6,   203,   230,   321,
     312,   312,     6,   321,   312,     6,   325,     6,   330,     6,
     325,   312,   326,     7,   312,   320,   161,     7,     7,   217,
       7,   161,     7,     7,   217,   161,     7,     7,     7,     7,
     312,   217,   224,   223,     6,     7,   217,   217,   312,   318,
       4,   304,     6,   217,   217,   222,   217,   222,   217,   222,
     217,   222,   217,   217,   217,   224,   224,   321,   220,   274,
     224,   224,   315,   312,   312,   224,   224,   312,   315,   222,
     222,   222,   114,   128,   136,   137,   138,   142,   143,   144,
     145,   297,   298,   315,   224,   284,   217,   224,   217,   217,
     217,   217,   217,   217,   217,   312,     6,   312,   217,   219,
     219,   224,   224,   224,   219,   219,   222,   217,   219,   321,
     321,   217,   321,   219,   219,   222,   222,   251,   222,   223,
     224,   223,   223,   223,   321,   321,   321,   321,   224,     8,
     321,   217,   219,   321,     7,     7,     7,   220,   312,   224,
     312,   312,     7,   220,   224,   224,     7,     6,   312,   224,
     223,   318,     6,    44,    44,   318,   248,   249,    44,    44,
     318,   248,   249,   224,   224,   219,   249,   220,   249,   325,
     312,   312,   312,   312,   321,   325,   312,   318,   325,   325,
     325,   261,   263,   312,   325,   325,   312,   250,   250,     6,
     312,     6,   250,   250,     6,     4,   158,   159,   312,     6,
       6,     6,     7,   218,   322,   324,     6,   321,   321,   321,
     321,   251,   312,   237,   216,   216,   223,   247,     6,   249,
     249,   217,   219,   203,   325,   217,   217,   219,   217,   222,
       7,   216,   218,   251,   251,   315,    90,    92,   318,   318,
       7,   318,    90,    92,   318,   318,     7,    92,   318,   318,
     318,   318,     6,     7,     7,   321,   223,     7,     7,   114,
     303,     6,     7,   248,   312,   248,   312,   248,   312,   248,
     312,     7,     7,     7,     7,     7,   224,     4,   224,   222,
     222,   222,   224,   224,   315,   315,   315,     4,     6,   312,
     223,     6,   216,     6,   146,     6,   146,     6,   146,     6,
     146,   224,   298,   222,   297,     7,     6,     7,     7,     7,
       7,     7,     7,     7,     6,   223,     6,     6,     6,    90,
       7,     6,     6,   312,   220,   224,   224,   224,   312,   312,
     312,   312,   312,   312,   312,   224,   224,   224,   224,   312,
     224,   224,   318,   318,   318,     4,   222,     8,     8,   217,
       4,     4,   222,   223,     6,   223,   318,   224,   250,   250,
       6,   312,     6,   250,   250,     6,   312,     6,   251,     6,
       4,     6,   251,   251,   251,   251,   251,   222,   222,   251,
     217,   251,   251,   222,   222,   251,   262,   222,   251,   264,
     217,   217,   251,   251,   251,   328,   328,     6,   251,   328,
     328,     7,   248,   249,   220,     7,     6,   322,   312,   222,
     224,   224,   224,   224,   224,   248,   216,   312,   312,   317,
     318,   223,   220,     6,     6,   230,     6,   312,   223,   312,
     326,   217,   219,     6,     6,     6,   223,   223,   107,   270,
     270,   318,     6,   223,   223,     6,     6,   318,   223,     6,
       6,     6,     6,     5,   318,   224,   317,   318,   318,     4,
       6,   318,   318,   318,   318,   318,   318,   318,   318,   223,
     223,     7,     6,     7,   312,   312,   312,   223,   223,   222,
     224,   222,   224,   222,   224,   218,     6,   312,   318,   312,
       6,     6,     6,     6,   312,   315,   224,     5,   318,   223,
     223,   223,   223,   223,   223,   223,   318,   321,   223,   312,
     219,     4,   251,   217,   219,   222,   222,   222,   222,   222,
     222,   222,   251,     6,     6,   157,   312,   312,   312,     6,
       6,     7,   326,   274,   274,   222,     6,   251,   328,   328,
       6,   251,   328,   328,     6,   248,   249,   325,   312,   325,
       4,     4,   173,     6,   251,   251,     6,   251,   251,   326,
     312,     6,     4,   323,     6,   219,   322,     6,     6,     6,
       6,   318,   234,   312,   222,   222,   222,   224,   235,   312,
       4,   325,   222,   318,   326,     7,     7,   312,   312,   315,
       6,     6,     6,   312,   312,     6,   312,     5,     6,   223,
     224,     6,   161,   269,   312,     6,     6,     6,     6,     6,
       6,     4,     6,     6,   321,   321,   312,   312,   326,   224,
     217,   222,   224,   273,   273,   315,     6,   288,   315,     6,
     289,   315,     6,   290,   312,   224,   222,   217,   224,   222,
       6,     6,   317,   315,   315,   315,   315,   315,   207,   315,
       6,   224,   312,     6,     6,   312,   312,   312,   312,   312,
     312,   312,   318,   222,   224,     8,   224,   217,   223,   312,
     326,   222,   300,   300,   318,     6,   251,   251,     6,   251,
     251,   318,   217,   251,   251,   223,   318,   326,   223,   312,
     326,   326,     6,     6,     6,     6,     6,     6,     7,     6,
     220,     6,   217,   222,   312,   312,   318,   223,   222,   224,
       6,   312,   255,   258,   223,   223,   224,   224,   224,   224,
     224,     5,   317,     6,    88,     6,   223,   224,   224,   223,
       6,     6,   223,   312,   224,   224,   222,   223,   222,   223,
     222,   223,   219,     6,   318,     7,   223,   312,   224,   222,
     222,   222,   222,   222,   222,     6,   224,   251,   251,   222,
     222,   222,   222,   222,   156,   312,   312,   321,     6,     6,
     326,   224,   224,   224,     6,     6,     6,     6,     6,   260,
     312,   320,   328,   322,   159,   238,   312,   222,   222,   317,
     312,     6,   222,   261,   263,   318,   318,     6,     6,     6,
       6,     6,     6,   224,   223,   317,   118,   119,   124,   307,
     118,   119,   307,   321,   273,   222,   224,   312,   315,   297,
     312,   315,   297,   312,   315,   297,     6,   222,   224,   318,
     274,   224,     6,   321,   315,   315,   315,   315,   315,   312,
     312,   312,   312,   312,   312,   224,   224,   224,   217,   223,
       6,   222,   224,     7,     7,   224,     6,   223,   312,   312,
     224,   312,   224,   224,   257,   256,   223,   312,   224,   223,
     315,   318,     6,   223,   315,     6,   224,   224,   312,   224,
     222,   224,   224,   222,   224,   224,   222,   224,   318,     6,
     114,   224,   285,   223,   224,   222,   222,   222,   222,   222,
     222,   222,   222,   222,   222,     6,     6,     6,   274,   312,
     326,   330,   235,   217,   222,     6,   223,   222,   261,   261,
     312,   224,     6,   315,     6,   315,     6,     6,   224,     6,
     291,   312,     6,     6,   292,   312,     6,     6,   293,   312,
       6,   224,   312,   297,   274,     6,   321,   321,   321,   321,
     315,   321,   312,   312,   312,   312,   312,   300,     7,   216,
     224,   241,   312,   317,   312,   224,   224,   222,   222,   222,
     223,   224,   223,   224,   223,   224,     6,     6,   224,   224,
     286,   224,   224,   224,   224,   222,   224,   222,   222,   222,
     222,   222,   224,   326,   217,     6,   223,   217,   224,   224,
     312,   315,   315,   297,     6,   294,   297,     6,   295,   297,
       6,   296,   297,     6,     6,     6,     6,   321,     6,   312,
     312,   312,   312,   312,     6,   239,   325,   244,   223,     6,
     224,   222,   222,   224,   223,   224,   223,   224,   223,   224,
     224,   251,   222,   222,   222,   222,   222,   224,   223,   317,
       6,   312,   312,     6,   297,     6,   297,     6,   297,     6,
     312,   312,   312,   312,   325,     6,   242,   325,   224,   224,
     224,   224,   224,   224,   224,   224,   224,   224,   222,   224,
       6,     6,     6,     6,     6,     6,   325,     6
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
#line 209 "Gmsh.y"
    { yyerrok; return 1; ;}
    break;

  case 6:
#line 220 "Gmsh.y"
    { return 1; ;}
    break;

  case 7:
#line 221 "Gmsh.y"
    { return 1; ;}
    break;

  case 8:
#line 222 "Gmsh.y"
    { return 1; ;}
    break;

  case 9:
#line 223 "Gmsh.y"
    { return 1; ;}
    break;

  case 10:
#line 224 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 11:
#line 225 "Gmsh.y"
    { return 1; ;}
    break;

  case 12:
#line 226 "Gmsh.y"
    { return 1; ;}
    break;

  case 13:
#line 227 "Gmsh.y"
    { return 1; ;}
    break;

  case 14:
#line 228 "Gmsh.y"
    { return 1; ;}
    break;

  case 15:
#line 229 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 16:
#line 230 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 17:
#line 231 "Gmsh.y"
    { return 1; ;}
    break;

  case 18:
#line 232 "Gmsh.y"
    { return 1; ;}
    break;

  case 19:
#line 233 "Gmsh.y"
    { return 1; ;}
    break;

  case 20:
#line 234 "Gmsh.y"
    { return 1; ;}
    break;

  case 21:
#line 235 "Gmsh.y"
    { return 1; ;}
    break;

  case 22:
#line 236 "Gmsh.y"
    { return 1; ;}
    break;

  case 23:
#line 237 "Gmsh.y"
    { return 1; ;}
    break;

  case 24:
#line 238 "Gmsh.y"
    { return 1; ;}
    break;

  case 25:
#line 243 "Gmsh.y"
    {
      (yyval.c) = (char*)"w";
    ;}
    break;

  case 26:
#line 247 "Gmsh.y"
    {
      (yyval.c) = (char*)"a";
    ;}
    break;

  case 27:
#line 254 "Gmsh.y"
    {
      Msg::Direct((yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 28:
#line 259 "Gmsh.y"
    {
      Msg::Error((yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 29:
#line 264 "Gmsh.y"
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
#line 278 "Gmsh.y"
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
#line 291 "Gmsh.y"
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
#line 304 "Gmsh.y"
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
#line 332 "Gmsh.y"
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
#line 346 "Gmsh.y"
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
#line 359 "Gmsh.y"
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
#line 372 "Gmsh.y"
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
#line 390 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData = new PViewDataList();
#endif
    ;}
    break;

  case 43:
#line 404 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(1) - (1)].d)); ;}
    break;

  case 44:
#line 406 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(3) - (3)].d)); ;}
    break;

  case 45:
#line 411 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(1) - (1)].d)); ;}
    break;

  case 46:
#line 413 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(3) - (3)].d)); ;}
    break;

  case 47:
#line 418 "Gmsh.y"
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
#line 522 "Gmsh.y"
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
#line 532 "Gmsh.y"
    {
#if defined(HAVE_POST)
      if(ViewValueList) (*ViewNumList)++;
#endif
    ;}
    break;

  case 50:
#line 541 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[(1) - (1)].c)[i]);
#endif
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 51:
#line 548 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[(3) - (3)].c)[i]);
#endif
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 52:
#line 558 "Gmsh.y"
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
#line 567 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->NbT2++;
#endif
    ;}
    break;

  case 54:
#line 576 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[(1) - (1)].c)[i]);
#endif
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 55:
#line 583 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[(3) - (3)].c)[i]);
#endif
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 56:
#line 593 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->T3D.push_back((yyvsp[(3) - (10)].d)); ViewData->T3D.push_back((yyvsp[(5) - (10)].d));
      ViewData->T3D.push_back((yyvsp[(7) - (10)].d)); ViewData->T3D.push_back((yyvsp[(9) - (10)].d));
      ViewData->T3D.push_back(ViewData->T3C.size());
#endif
    ;}
    break;

  case 57:
#line 601 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->NbT3++;
#endif
    ;}
    break;

  case 58:
#line 611 "Gmsh.y"
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
#line 630 "Gmsh.y"
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
#line 649 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewValueList = &ViewData->Time;
#endif
    ;}
    break;

  case 61:
#line 655 "Gmsh.y"
    {
    ;}
    break;

  case 62:
#line 662 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 63:
#line 663 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 64:
#line 664 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 65:
#line 665 "Gmsh.y"
    { (yyval.i) = 3; ;}
    break;

  case 66:
#line 666 "Gmsh.y"
    { (yyval.i) = 4; ;}
    break;

  case 67:
#line 670 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 68:
#line 671 "Gmsh.y"
    { (yyval.i) = -1; ;}
    break;

  case 69:
#line 677 "Gmsh.y"
    { (yyval.c) = (char*)"("; ;}
    break;

  case 70:
#line 677 "Gmsh.y"
    { (yyval.c) = (char*)"["; ;}
    break;

  case 71:
#line 678 "Gmsh.y"
    { (yyval.c) = (char*)")"; ;}
    break;

  case 72:
#line 678 "Gmsh.y"
    { (yyval.c) = (char*)"]"; ;}
    break;

  case 75:
#line 687 "Gmsh.y"
    {
      Msg::SetOnelabNumber((yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].d));
      Free((yyvsp[(3) - (7)].c));
    ;}
    break;

  case 76:
#line 692 "Gmsh.y"
    {
      Msg::SetOnelabString((yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].c));
      Free((yyvsp[(3) - (7)].c));
      Free((yyvsp[(5) - (7)].c));
    ;}
    break;

  case 77:
#line 698 "Gmsh.y"
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
#line 760 "Gmsh.y"
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
#line 777 "Gmsh.y"
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
#line 806 "Gmsh.y"
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
#line 835 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    ;}
    break;

  case 82:
#line 840 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    ;}
    break;

  case 83:
#line 845 "Gmsh.y"
    {
      incrementVariable((yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].i));
      Free((yyvsp[(1) - (6)].c));
    ;}
    break;

  case 84:
#line 850 "Gmsh.y"
    {
      incrementVariable((yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].i));
      Free((yyvsp[(1) - (6)].c));
    ;}
    break;

  case 85:
#line 855 "Gmsh.y"
    {
      assignVariables((yyvsp[(1) - (9)].c), (yyvsp[(4) - (9)].l), (yyvsp[(7) - (9)].i), (yyvsp[(8) - (9)].l));
      Free((yyvsp[(1) - (9)].c));
      List_Delete((yyvsp[(4) - (9)].l));
      List_Delete((yyvsp[(8) - (9)].l));
    ;}
    break;

  case 86:
#line 862 "Gmsh.y"
    {
      assignVariables((yyvsp[(1) - (9)].c), (yyvsp[(4) - (9)].l), (yyvsp[(7) - (9)].i), (yyvsp[(8) - (9)].l));
      Free((yyvsp[(1) - (9)].c));
      List_Delete((yyvsp[(4) - (9)].l));
      List_Delete((yyvsp[(8) - (9)].l));
    ;}
    break;

  case 87:
#line 872 "Gmsh.y"
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
#line 901 "Gmsh.y"
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
#line 930 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    ;}
    break;

  case 90:
#line 935 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    ;}
    break;

  case 91:
#line 940 "Gmsh.y"
    {
      incrementVariable((yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].i));
      Free((yyvsp[(1) - (6)].c));
    ;}
    break;

  case 92:
#line 945 "Gmsh.y"
    {
      incrementVariable((yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].i));
      Free((yyvsp[(1) - (6)].c));
    ;}
    break;

  case 93:
#line 953 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[(1) - (4)].c)] = std::vector<std::string>(1, (yyvsp[(3) - (4)].c));
      Free((yyvsp[(1) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 94:
#line 962 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[(1) - (8)].c)] = std::vector<std::string>();
      Free((yyvsp[(1) - (8)].c));
    ;}
    break;

  case 95:
#line 968 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[(1) - (8)].c)] = std::vector<std::string>();
      Free((yyvsp[(1) - (8)].c));
    ;}
    break;

  case 96:
#line 974 "Gmsh.y"
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
#line 987 "Gmsh.y"
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
#line 1000 "Gmsh.y"
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
#line 1015 "Gmsh.y"
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
#line 1032 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[(1) - (8)].c)] = std::vector<std::string>();
      Free((yyvsp[(1) - (8)].c));
    ;}
    break;

  case 101:
#line 1038 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[(1) - (8)].c)] = std::vector<std::string>();
      Free((yyvsp[(1) - (8)].c));
    ;}
    break;

  case 102:
#line 1044 "Gmsh.y"
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
#line 1057 "Gmsh.y"
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
#line 1070 "Gmsh.y"
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
#line 1085 "Gmsh.y"
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
#line 1102 "Gmsh.y"
    {
      std::string tmp((yyvsp[(5) - (6)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (6)].c), 0, (yyvsp[(3) - (6)].c), tmp);
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 107:
#line 1108 "Gmsh.y"
    {
      std::string tmp((yyvsp[(8) - (9)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (9)].c), (int)(yyvsp[(3) - (9)].d), (yyvsp[(6) - (9)].c), tmp);
      Free((yyvsp[(1) - (9)].c)); Free((yyvsp[(6) - (9)].c)); Free((yyvsp[(8) - (9)].c));
    ;}
    break;

  case 108:
#line 1117 "Gmsh.y"
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
#line 1135 "Gmsh.y"
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
#line 1153 "Gmsh.y"
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
#line 1162 "Gmsh.y"
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
#line 1174 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (8)].c), 0, (yyvsp[(5) - (8)].c), (yyvsp[(7) - (8)].u));
      Free((yyvsp[(1) - (8)].c)); Free((yyvsp[(5) - (8)].c));
    ;}
    break;

  case 113:
#line 1179 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (11)].c), (int)(yyvsp[(3) - (11)].d), (yyvsp[(8) - (11)].c), (yyvsp[(10) - (11)].u));
      Free((yyvsp[(1) - (11)].c)); Free((yyvsp[(8) - (11)].c));
    ;}
    break;

  case 114:
#line 1187 "Gmsh.y"
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
#line 1207 "Gmsh.y"
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
#line 1230 "Gmsh.y"
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
#line 1241 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      if(!GModel::current()->getFields()->newField((int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c)))
	yymsg(0, "Cannot create field %i of type '%s'", (int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c));
#endif
      Free((yyvsp[(6) - (7)].c));
    ;}
    break;

  case 118:
#line 1249 "Gmsh.y"
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
#line 1271 "Gmsh.y"
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
#line 1294 "Gmsh.y"
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
#line 1332 "Gmsh.y"
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
#line 1353 "Gmsh.y"
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
#line 1365 "Gmsh.y"
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
#line 1383 "Gmsh.y"
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
#line 1392 "Gmsh.y"
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
#line 1401 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 130:
#line 1403 "Gmsh.y"
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
#line 1421 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 132:
#line 1423 "Gmsh.y"
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
#line 1439 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 134:
#line 1441 "Gmsh.y"
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
#line 1457 "Gmsh.y"
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
#line 1466 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 137:
#line 1468 "Gmsh.y"
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
#line 1482 "Gmsh.y"
    {
      std::string name((yyvsp[(3) - (3)].c));
      Msg::UndefineOnelabParameter(name);
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 140:
#line 1490 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(doubleXstring));
      doubleXstring v = {(yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].c)};
      List_Add((yyval.l), &v);
    ;}
    break;

  case 141:
#line 1496 "Gmsh.y"
    {
      doubleXstring v = {(yyvsp[(3) - (5)].d), (yyvsp[(5) - (5)].c)};
      List_Add((yyval.l), &v);
    ;}
    break;

  case 142:
#line 1501 "Gmsh.y"
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
#line 1532 "Gmsh.y"
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
#line 1543 "Gmsh.y"
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
#line 1558 "Gmsh.y"
    {
      std::string key((yyvsp[(2) - (3)].c));
      std::string val((yyvsp[(3) - (3)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(2) - (3)].c));
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 150:
#line 1574 "Gmsh.y"
    {
      std::string key((yyvsp[(2) - (3)].c));
      double val = (yyvsp[(3) - (3)].d);
      floatOptions[key].push_back(val);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 151:
#line 1582 "Gmsh.y"
    {
      std::string key((yyvsp[(2) - (3)].c));
      std::string val((yyvsp[(3) - (3)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(2) - (3)].c));
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 152:
#line 1591 "Gmsh.y"
    {
      std::string key("Macro");
      std::string val((yyvsp[(3) - (3)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 153:
#line 1599 "Gmsh.y"
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
#line 1617 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    ;}
    break;

  case 155:
#line 1621 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[(1) - (1)].c)), 0, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 156:
#line 1627 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (3)].c)), 0, (yyvsp[(3) - (3)].d));
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 157:
#line 1635 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    ;}
    break;

  case 158:
#line 1639 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[(1) - (1)].c)), 1, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 159:
#line 1645 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (3)].c)), 1, (yyvsp[(3) - (3)].d));
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 160:
#line 1653 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    ;}
    break;

  case 161:
#line 1657 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[(1) - (1)].c)), 2, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 162:
#line 1663 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (3)].c)), 2, (yyvsp[(3) - (3)].d));
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 163:
#line 1671 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    ;}
    break;

  case 164:
#line 1675 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[(1) - (1)].c)), 3, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 165:
#line 1681 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (3)].c)), 3, (yyvsp[(3) - (3)].d));
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 166:
#line 1689 "Gmsh.y"
    {
      (yyval.l) = 0;
    ;}
    break;

  case 167:
#line 1693 "Gmsh.y"
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
#line 1705 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = 0.;
    ;}
    break;

  case 169:
#line 1709 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 170:
#line 1717 "Gmsh.y"
    {
      factory = (yyvsp[(3) - (5)].c);
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 171:
#line 1725 "Gmsh.y"
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
#line 1753 "Gmsh.y"
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
#line 1796 "Gmsh.y"
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
#line 1819 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      if(FindCurve(num)){
	yymsg(0, "Curve %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt((yyvsp[(6) - (7)].l));
	Curve *c = Create_Curve(num, MSH_SEGM_LINE, 1, temp, NULL,
				-1, -1, 0., 1.);
	Tree_Add(GModel::current()->getGEOInternals()->Curves, &c);
	CreateReversedCurve(c);
	List_Delete(temp);
      }
      List_Delete((yyvsp[(6) - (7)].l));
      (yyval.s).Type = MSH_SEGM_LINE;
      (yyval.s).Num = num;
    ;}
    break;

  case 175:
#line 1837 "Gmsh.y"
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
#line 1858 "Gmsh.y"
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
#line 1876 "Gmsh.y"
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
#line 1916 "Gmsh.y"
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
#line 1946 "Gmsh.y"
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
#line 1964 "Gmsh.y"
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
#line 1983 "Gmsh.y"
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
#line 2009 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].d);
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
      List_Delete((yyvsp[(7) - (8)].l));
      Free((yyvsp[(2) - (8)].c));
      (yyval.s).Type = MSH_SEGM_LOOP;
      (yyval.s).Num = num;
    ;}
    break;

  case 183:
#line 2028 "Gmsh.y"
    {
     GModel::current()->getGEOInternals()->addCompoundMesh ( 1 , (yyvsp[(3) - (4)].l) );
   ;}
    break;

  case 184:
#line 2033 "Gmsh.y"
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
#line 2051 "Gmsh.y"
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
#line 2097 "Gmsh.y"
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
#line 2115 "Gmsh.y"
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
#line 2154 "Gmsh.y"
    {
      myGmshSurface = 0;
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 189:
#line 2160 "Gmsh.y"
    {
      myGmshSurface = gmshSurface::getSurface((int)(yyvsp[(3) - (4)].d));
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 190:
#line 2166 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (10)].d);
      myGmshSurface = gmshParametricSurface::NewParametricSurface(num, (yyvsp[(7) - (10)].c), (yyvsp[(8) - (10)].c), (yyvsp[(9) - (10)].c));
      (yyval.s).Type = 0;
      (yyval.s).Num = num;
    ;}
    break;

  case 191:
#line 2173 "Gmsh.y"
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
#line 2214 "Gmsh.y"
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
#line 2240 "Gmsh.y"
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
#line 2264 "Gmsh.y"
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
#line 2289 "Gmsh.y"
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
#line 2306 "Gmsh.y"
    {
      GModel::current()->getGEOInternals()->addCompoundMesh ( 2 , (yyvsp[(3) - (4)].l) );
    ;}
    break;

  case 197:
#line 2310 "Gmsh.y"
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
#line 2330 "Gmsh.y"
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
#line 2363 "Gmsh.y"
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
#line 2410 "Gmsh.y"
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
#line 2428 "Gmsh.y"
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
#line 2445 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (9)].d);
      if(FindVolume(num)){
	yymsg(0, "Volume %d already exists", num);
      }
      else{
        if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
          std::vector<std::vector<int> > edges;
          for(int i = 0; i < List_Nbr((yyvsp[(7) - (9)].l)); i++){
            List_T *l; List_Read((yyvsp[(7) - (9)].l), i, &l);
            std::vector<int> v;
            for(int j = 0; j < List_Nbr(l); j++){
              double d = 0; List_Read(l, j, &d); v.push_back(d);
            }
            edges.push_back(v);
          }
          GModel::current()->getOCCInternals()->addThruSections(num, edges);
        }
        else{
          yymsg(0, "ThruSections only available with OpenCASCADE factory");
        }
      }
      for(int i = 0; i < List_Nbr((yyvsp[(7) - (9)].l)); i++)
        List_Delete(*(List_T**)List_Pointer((yyvsp[(7) - (9)].l), i));
      List_Delete((yyvsp[(7) - (9)].l));
      (yyval.s).Type = MSH_VOLUME;
      (yyval.s).Num = num;
    ;}
    break;

  case 203:
#line 2474 "Gmsh.y"
    {
      GModel::current()->getGEOInternals()->addCompoundMesh ( 3 , (yyvsp[(3) - (4)].l) );
    ;}
    break;

  case 204:
#line 2478 "Gmsh.y"
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
#line 2494 "Gmsh.y"
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
#line 2542 "Gmsh.y"
    {
      TranslateShapes((yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], (yyvsp[(4) - (5)].l));
      (yyval.l) = (yyvsp[(4) - (5)].l);
    ;}
    break;

  case 207:
#line 2547 "Gmsh.y"
    {
      RotateShapes((yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(7) - (11)].d), (yyvsp[(10) - (11)].l));
      (yyval.l) = (yyvsp[(10) - (11)].l);
    ;}
    break;

  case 208:
#line 2552 "Gmsh.y"
    {
      SymmetryShapes((yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], (yyvsp[(2) - (5)].v)[3], (yyvsp[(4) - (5)].l));
      (yyval.l) = (yyvsp[(4) - (5)].l);
    ;}
    break;

  case 209:
#line 2557 "Gmsh.y"
    {
      DilatShapes((yyvsp[(3) - (9)].v)[0], (yyvsp[(3) - (9)].v)[1], (yyvsp[(3) - (9)].v)[2], (yyvsp[(5) - (9)].d), (yyvsp[(5) - (9)].d), (yyvsp[(5) - (9)].d), (yyvsp[(8) - (9)].l));
      (yyval.l) = (yyvsp[(8) - (9)].l);
    ;}
    break;

  case 210:
#line 2562 "Gmsh.y"
    {
      DilatShapes((yyvsp[(3) - (9)].v)[0], (yyvsp[(3) - (9)].v)[1], (yyvsp[(3) - (9)].v)[2], (yyvsp[(5) - (9)].v)[0], (yyvsp[(5) - (9)].v)[1], (yyvsp[(5) - (9)].v)[2], (yyvsp[(8) - (9)].l));
      (yyval.l) = (yyvsp[(8) - (9)].l);
    ;}
    break;

  case 211:
#line 2567 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
      if(!strcmp((yyvsp[(1) - (4)].c), "Duplicata")){
        for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
          Shape TheShape;
          List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
          CopyShape(TheShape.Type, TheShape.Num, &TheShape.Num);
          List_Add((yyval.l), &TheShape);
        }
      }
      else if(!strcmp((yyvsp[(1) - (4)].c), "Boundary")){
        BoundaryShapes((yyvsp[(3) - (4)].l), (yyval.l), false);
      }
      else if(!strcmp((yyvsp[(1) - (4)].c), "CombinedBoundary")){
        BoundaryShapes((yyvsp[(3) - (4)].l), (yyval.l), true);
      }
      else{
        yymsg(0, "Unknown command on multiple shapes: '%s'", (yyvsp[(1) - (4)].c));
      }
      Free((yyvsp[(1) - (4)].c));
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 212:
#line 2590 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      IntersectCurvesWithSurface((yyvsp[(4) - (9)].l), (int)(yyvsp[(8) - (9)].d), (yyval.l));
      List_Delete((yyvsp[(4) - (9)].l));
    ;}
    break;

  case 213:
#line 2596 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape*));
      List_T *tmp = ListOfDouble2ListOfInt((yyvsp[(7) - (9)].l));
      List_Delete((yyvsp[(7) - (9)].l));
      SplitCurve((int)(yyvsp[(4) - (9)].d), tmp, (yyval.l));
      List_Delete(tmp);
    ;}
    break;

  case 214:
#line 2606 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 215:
#line 2607 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 216:
#line 2612 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    ;}
    break;

  case 217:
#line 2616 "Gmsh.y"
    {
      List_Add((yyval.l), &(yyvsp[(2) - (2)].s));
    ;}
    break;

  case 218:
#line 2620 "Gmsh.y"
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
              TheShape.Type = MSH_UNKNOWN;
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
#line 2649 "Gmsh.y"
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
              TheShape.Type = MSH_UNKNOWN;
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
#line 2678 "Gmsh.y"
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
              TheShape.Type = MSH_UNKNOWN;
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
#line 2707 "Gmsh.y"
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
              TheShape.Type = MSH_UNKNOWN;
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
#line 2741 "Gmsh.y"
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
#line 2763 "Gmsh.y"
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
#line 2790 "Gmsh.y"
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
#line 2812 "Gmsh.y"
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
#line 2834 "Gmsh.y"
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
#line 2856 "Gmsh.y"
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
#line 2912 "Gmsh.y"
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
#line 2936 "Gmsh.y"
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
#line 2961 "Gmsh.y"
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
#line 2986 "Gmsh.y"
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
#line 3099 "Gmsh.y"
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
#line 3118 "Gmsh.y"
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
#line 3161 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
	DeleteShape(TheShape.Type, TheShape.Num);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 235:
#line 3170 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      GModel::current()->getFields()->deleteField((int)(yyvsp[(4) - (6)].d));
#endif
    ;}
    break;

  case 236:
#line 3176 "Gmsh.y"
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
#line 3191 "Gmsh.y"
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
#line 3219 "Gmsh.y"
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
#line 3236 "Gmsh.y"
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
#line 3245 "Gmsh.y"
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
#line 3259 "Gmsh.y"
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
#line 3273 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 1, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 243:
#line 3279 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 0, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 244:
#line 3285 "Gmsh.y"
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
#line 3294 "Gmsh.y"
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
#line 3303 "Gmsh.y"
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
#line 3312 "Gmsh.y"
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
#line 3326 "Gmsh.y"
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
#line 3388 "Gmsh.y"
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
#line 3406 "Gmsh.y"
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
#line 3423 "Gmsh.y"
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
#line 3438 "Gmsh.y"
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
#line 3467 "Gmsh.y"
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
#line 3479 "Gmsh.y"
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
#line 3503 "Gmsh.y"
    {
      Msg::Exit(0);
    ;}
    break;

  case 256:
#line 3507 "Gmsh.y"
    {
      gmsh_yyerrorstate = 999; // this will be checked when yyparse returns
      YYABORT;
    ;}
    break;

  case 257:
#line 3512 "Gmsh.y"
    {
      // FIXME: this is a hack to force a transfer from the old DB to
      // the new DB. This will become unnecessary if/when we fill the
      // GModel directly during parsing.
      GModel::current()->importGEOInternals();
      GModel::current()->importOCCInternals();
    ;}
    break;

  case 258:
#line 3520 "Gmsh.y"
    {
      new GModel();
      GModel::current(GModel::list.size() - 1);
    ;}
    break;

  case 259:
#line 3525 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 0;
      GModel::current()->importGEOInternals();
      SetBoundingBox();
    ;}
    break;

  case 260:
#line 3531 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 1;
      SetBoundingBox((yyvsp[(3) - (15)].d), (yyvsp[(5) - (15)].d), (yyvsp[(7) - (15)].d), (yyvsp[(9) - (15)].d), (yyvsp[(11) - (15)].d), (yyvsp[(13) - (15)].d));
    ;}
    break;

  case 261:
#line 3536 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
      drawContext::global()->draw();
#endif
    ;}
    break;

  case 262:
#line 3542 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
     CTX::instance()->mesh.changed = ENT_ALL;
     for(unsigned int index = 0; index < PView::list.size(); index++)
       PView::list[index]->setChanged(true);
#endif
    ;}
    break;

  case 263:
#line 3550 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh();
    ;}
    break;

  case 264:
#line 3554 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh(1);
    ;}
    break;

  case 265:
#line 3558 "Gmsh.y"
    {
      GModel::current()->importGEOInternals();
      GModel::current()->refineMesh(CTX::instance()->mesh.secondOrderLinear);
    ;}
    break;

  case 266:
#line 3564 "Gmsh.y"
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
#line 3623 "Gmsh.y"
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
#line 3639 "Gmsh.y"
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
#line 3656 "Gmsh.y"
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
#line 3673 "Gmsh.y"
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
#line 3695 "Gmsh.y"
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
#line 3717 "Gmsh.y"
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
#line 3752 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip_until(NULL, "Return");
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 274:
#line 3760 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip_until(NULL, "Return");
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 275:
#line 3768 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    ;}
    break;

  case 276:
#line 3774 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 277:
#line 3781 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 278:
#line 3788 "Gmsh.y"
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
#line 3808 "Gmsh.y"
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
#line 3834 "Gmsh.y"
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
#line 3846 "Gmsh.y"
    {
      ImbricatedTest--;
      if(ImbricatedTest < 0)
        yymsg(1, "Orphan EndIf");
    ;}
    break;

  case 282:
#line 3858 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (5)].l),
		    (yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    NULL, (yyval.l));
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 283:
#line 3866 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[(10) - (11)].l),
		    0., 0., 0., (yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(7) - (11)].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[(10) - (11)].l));
    ;}
    break;

  case 284:
#line 3874 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (13)].l),
		    (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].v)[0], (yyvsp[(7) - (13)].v)[1], (yyvsp[(7) - (13)].v)[2], (yyvsp[(9) - (13)].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[(12) - (13)].l));
    ;}
    break;

  case 285:
#line 3882 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 286:
#line 3888 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (7)].l),
		    (yyvsp[(2) - (7)].v)[0], (yyvsp[(2) - (7)].v)[1], (yyvsp[(2) - (7)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(4) - (7)].l));
    ;}
    break;

  case 287:
#line 3896 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 288:
#line 3902 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[(10) - (13)].l),
		    0., 0., 0., (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(10) - (13)].l));
    ;}
    break;

  case 289:
#line 3910 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 290:
#line 3916 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (15)].l),
		    (yyvsp[(3) - (15)].v)[0], (yyvsp[(3) - (15)].v)[1], (yyvsp[(3) - (15)].v)[2], (yyvsp[(5) - (15)].v)[0], (yyvsp[(5) - (15)].v)[1], (yyvsp[(5) - (15)].v)[2], (yyvsp[(7) - (15)].v)[0], (yyvsp[(7) - (15)].v)[1], (yyvsp[(7) - (15)].v)[2], (yyvsp[(9) - (15)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(12) - (15)].l));
    ;}
    break;

  case 291:
#line 3924 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 292:
#line 3930 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(BOUNDARY_LAYER, (yyvsp[(3) - (6)].l), 0., 0., 0., 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(3) - (6)].l));
    ;}
    break;

  case 293:
#line 3938 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 294:
#line 3945 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 295:
#line 3952 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 296:
#line 3959 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 297:
#line 3966 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 298:
#line 3973 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 299:
#line 3980 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 300:
#line 3987 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 301:
#line 3994 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 302:
#line 4001 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 303:
#line 4007 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 304:
#line 4014 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 305:
#line 4020 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 306:
#line 4027 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 307:
#line 4033 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 308:
#line 4040 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 309:
#line 4046 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 310:
#line 4053 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 311:
#line 4059 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 312:
#line 4066 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 313:
#line 4072 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 314:
#line 4079 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 315:
#line 4085 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 316:
#line 4092 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 317:
#line 4098 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 318:
#line 4105 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 319:
#line 4111 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 320:
#line 4122 "Gmsh.y"
    {
    ;}
    break;

  case 321:
#line 4125 "Gmsh.y"
    {
    ;}
    break;

  case 322:
#line 4131 "Gmsh.y"
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
#line 4143 "Gmsh.y"
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
#line 4163 "Gmsh.y"
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
#line 4187 "Gmsh.y"
    {
      extr.mesh.ScaleLast = true;
    ;}
    break;

  case 326:
#line 4191 "Gmsh.y"
    {
      extr.mesh.Recombine = true;
    ;}
    break;

  case 327:
#line 4195 "Gmsh.y"
    {
      extr.mesh.Recombine = (yyvsp[(2) - (3)].d) ? true : false;
    ;}
    break;

  case 328:
#line 4199 "Gmsh.y"
    {
      yymsg(0, "Keyword 'QuadTriSngl' deprecated. Use 'QuadTriNoNewVerts' instead.");
    ;}
    break;

  case 329:
#line 4203 "Gmsh.y"
    {
      yymsg(0, "Keyword 'QuadTriSngl' deprecated. Use 'QuadTriNoNewVerts' instead.");
    ;}
    break;

  case 330:
#line 4207 "Gmsh.y"
    {
      yymsg(0, "Method 'QuadTriDbl' deprecated. Use 'QuadTriAddVerts' instead, "
            "which has no requirement for the number of extrusion layers and meshes "
            "with body-centered vertices.");
    ;}
    break;

  case 331:
#line 4213 "Gmsh.y"
    {
      yymsg(0, "Method 'QuadTriDbl' deprecated. Use 'QuadTriAddVerts' instead, "
            "which has no requirement for the number of extrusion layers and meshes "
            "with body-centered vertices.");
    ;}
    break;

  case 332:
#line 4219 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1;
    ;}
    break;

  case 333:
#line 4223 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1_RECOMB;
    ;}
    break;

  case 334:
#line 4227 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1;
    ;}
    break;

  case 335:
#line 4231 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1_RECOMB;
    ;}
    break;

  case 336:
#line 4235 "Gmsh.y"
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
#line 4254 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (6)].c), "Index"))
        extr.mesh.BoundaryLayerIndex = (yyvsp[(4) - (6)].d);
      else if(!strcmp((yyvsp[(2) - (6)].c), "View"))
        extr.mesh.ViewIndex = (yyvsp[(4) - (6)].d);
      Free((yyvsp[(2) - (6)].c));
    ;}
    break;

  case 338:
#line 4266 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Fuse; ;}
    break;

  case 339:
#line 4267 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Intersection; ;}
    break;

  case 340:
#line 4268 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Cut; ;}
    break;

  case 341:
#line 4272 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 342:
#line 4273 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 343:
#line 4274 "Gmsh.y"
    { (yyval.i) = (yyvsp[(2) - (3)].d); ;}
    break;

  case 344:
#line 4278 "Gmsh.y"
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
        GModel::current()->getOCCInternals()->applyBooleanOperator
          (-1, shape, tool, (OCC_Internals::BooleanOperator)(yyvsp[(1) - (9)].i), (yyvsp[(4) - (9)].i), (yyvsp[(8) - (9)].i));
        // FIXME add to returned list of shapes
      }
      List_Delete((yyvsp[(3) - (9)].l));
      List_Delete((yyvsp[(7) - (9)].l));
    ;}
    break;

  case 345:
#line 4299 "Gmsh.y"
    {
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        std::vector<int> shape[4], tool[4];
        for(int i = 0; i < List_Nbr((yyvsp[(7) - (14)].l)); i++){
          Shape s; List_Read((yyvsp[(7) - (14)].l), i, &s); shape[3].push_back(s.Num);
        }
        for(int i = 0; i < List_Nbr((yyvsp[(11) - (14)].l)); i++){
          Shape s; List_Read((yyvsp[(11) - (14)].l), i, &s); tool[3].push_back(s.Num);
        }
        GModel::current()->getOCCInternals()->applyBooleanOperator
          ((int)(yyvsp[(3) - (14)].d), shape, tool, (OCC_Internals::BooleanOperator)(yyvsp[(1) - (14)].i), (yyvsp[(8) - (14)].i), (yyvsp[(12) - (14)].i));
      }
      List_Delete((yyvsp[(7) - (14)].l));
      List_Delete((yyvsp[(11) - (14)].l));
    ;}
    break;

  case 346:
#line 4318 "Gmsh.y"
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    ;}
    break;

  case 347:
#line 4322 "Gmsh.y"
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

  case 348:
#line 4337 "Gmsh.y"
    {
      (yyval.i) = -1; // left
    ;}
    break;

  case 349:
#line 4341 "Gmsh.y"
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

  case 350:
#line 4357 "Gmsh.y"
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   ;}
    break;

  case 351:
#line 4361 "Gmsh.y"
    {
     (yyval.l) = (yyvsp[(2) - (2)].l);
   ;}
    break;

  case 352:
#line 4366 "Gmsh.y"
    {
      (yyval.i) = 45;
    ;}
    break;

  case 353:
#line 4370 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(2) - (2)].d);
    ;}
    break;

  case 354:
#line 4376 "Gmsh.y"
    {
      (yyval.l) = List_Create(1, 1, sizeof(double));
    ;}
    break;

  case 355:
#line 4380 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
    ;}
    break;

  case 356:
#line 4387 "Gmsh.y"
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

  case 357:
#line 4443 "Gmsh.y"
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

  case 358:
#line 4513 "Gmsh.y"
    {
      yymsg(1, "Elliptic Surface is deprecated: use Transfinite instead (with smoothing)");
      List_Delete((yyvsp[(7) - (8)].l));
    ;}
    break;

  case 359:
#line 4518 "Gmsh.y"
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

  case 360:
#line 4585 "Gmsh.y"
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

  case 361:
#line 4621 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (8)].l)); i++){
	double d;
	List_Read((yyvsp[(4) - (8)].l), i, &d);
	CTX::instance()->mesh.algo2d_per_face[(int)d] = (int)(yyvsp[(7) - (8)].d);
      }
    ;}
    break;

  case 362:
#line 4629 "Gmsh.y"
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

  case 363:
#line 4672 "Gmsh.y"
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

  case 364:
#line 4711 "Gmsh.y"
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

  case 365:
#line 4732 "Gmsh.y"
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

  case 366:
#line 4764 "Gmsh.y"
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

  case 367:
#line 4791 "Gmsh.y"
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

  case 368:
#line 4817 "Gmsh.y"
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

  case 369:
#line 4843 "Gmsh.y"
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

  case 370:
#line 4869 "Gmsh.y"
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

  case 371:
#line 4895 "Gmsh.y"
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

  case 372:
#line 4916 "Gmsh.y"
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

  case 373:
#line 4944 "Gmsh.y"
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

  case 374:
#line 4972 "Gmsh.y"
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

  case 375:
#line 5000 "Gmsh.y"
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

  case 376:
#line 5028 "Gmsh.y"
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

  case 377:
#line 5056 "Gmsh.y"
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

  case 378:
#line 5095 "Gmsh.y"
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

  case 379:
#line 5134 "Gmsh.y"
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

  case 380:
#line 5155 "Gmsh.y"
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

  case 381:
#line 5176 "Gmsh.y"
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

  case 382:
#line 5203 "Gmsh.y"
    {
      ReplaceAllDuplicates();
    ;}
    break;

  case 383:
#line 5207 "Gmsh.y"
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

  case 384:
#line 5217 "Gmsh.y"
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

  case 385:
#line 5251 "Gmsh.y"
    { (yyval.c) = (char*)"Homology"; ;}
    break;

  case 386:
#line 5252 "Gmsh.y"
    { (yyval.c) = (char*)"Cohomology"; ;}
    break;

  case 387:
#line 5253 "Gmsh.y"
    { (yyval.c) = (char*)"Betti"; ;}
    break;

  case 388:
#line 5258 "Gmsh.y"
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest((yyvsp[(1) - (2)].c), domain, subdomain, dim);
    ;}
    break;

  case 389:
#line 5264 "Gmsh.y"
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

  case 390:
#line 5276 "Gmsh.y"
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

  case 391:
#line 5294 "Gmsh.y"
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

  case 392:
#line 5321 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d);           ;}
    break;

  case 393:
#line 5322 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (3)].d);           ;}
    break;

  case 394:
#line 5323 "Gmsh.y"
    { (yyval.d) = -(yyvsp[(2) - (2)].d);          ;}
    break;

  case 395:
#line 5324 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);           ;}
    break;

  case 396:
#line 5325 "Gmsh.y"
    { (yyval.d) = !(yyvsp[(2) - (2)].d);          ;}
    break;

  case 397:
#line 5326 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) - (yyvsp[(3) - (3)].d);      ;}
    break;

  case 398:
#line 5327 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) + (yyvsp[(3) - (3)].d);      ;}
    break;

  case 399:
#line 5328 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) * (yyvsp[(3) - (3)].d);      ;}
    break;

  case 400:
#line 5330 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (3)].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));
      else
	(yyval.d) = (yyvsp[(1) - (3)].d) / (yyvsp[(3) - (3)].d);
    ;}
    break;

  case 401:
#line 5336 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) % (int)(yyvsp[(3) - (3)].d);  ;}
    break;

  case 402:
#line 5337 "Gmsh.y"
    { (yyval.d) = pow((yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));  ;}
    break;

  case 403:
#line 5338 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d);      ;}
    break;

  case 404:
#line 5339 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) > (yyvsp[(3) - (3)].d);      ;}
    break;

  case 405:
#line 5340 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) <= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 406:
#line 5341 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) >= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 407:
#line 5342 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) == (yyvsp[(3) - (3)].d);     ;}
    break;

  case 408:
#line 5343 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) != (yyvsp[(3) - (3)].d);     ;}
    break;

  case 409:
#line 5344 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) && (yyvsp[(3) - (3)].d);     ;}
    break;

  case 410:
#line 5345 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) || (yyvsp[(3) - (3)].d);     ;}
    break;

  case 411:
#line 5346 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (5)].d) ? (yyvsp[(3) - (5)].d) : (yyvsp[(5) - (5)].d); ;}
    break;

  case 412:
#line 5347 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 413:
#line 5348 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 414:
#line 5349 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 415:
#line 5350 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 416:
#line 5351 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 417:
#line 5352 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 418:
#line 5353 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 419:
#line 5354 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 420:
#line 5355 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 421:
#line 5356 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 422:
#line 5357 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 423:
#line 5358 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 424:
#line 5359 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 425:
#line 5360 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 426:
#line 5361 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 427:
#line 5362 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 428:
#line 5363 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 429:
#line 5364 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d) + 0.5); ;}
    break;

  case 430:
#line 5365 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 431:
#line 5366 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 432:
#line 5367 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 433:
#line 5368 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 434:
#line 5377 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 435:
#line 5378 "Gmsh.y"
    { (yyval.d) = 3.141592653589793; ;}
    break;

  case 436:
#line 5379 "Gmsh.y"
    { (yyval.d) = (double)ImbricatedTest; ;}
    break;

  case 437:
#line 5380 "Gmsh.y"
    { (yyval.d) = Msg::GetCommRank(); ;}
    break;

  case 438:
#line 5381 "Gmsh.y"
    { (yyval.d) = Msg::GetCommSize(); ;}
    break;

  case 439:
#line 5382 "Gmsh.y"
    { (yyval.d) = GetGmshMajorVersion(); ;}
    break;

  case 440:
#line 5383 "Gmsh.y"
    { (yyval.d) = GetGmshMinorVersion(); ;}
    break;

  case 441:
#line 5384 "Gmsh.y"
    { (yyval.d) = GetGmshPatchVersion(); ;}
    break;

  case 442:
#line 5385 "Gmsh.y"
    { (yyval.d) = Cpu(); ;}
    break;

  case 443:
#line 5386 "Gmsh.y"
    { (yyval.d) = GetMemoryUsage()/1024./1024.; ;}
    break;

  case 444:
#line 5387 "Gmsh.y"
    { (yyval.d) = TotalRam(); ;}
    break;

  case 445:
#line 5392 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 446:
#line 5394 "Gmsh.y"
    {
      std::vector<double> val(1, (yyvsp[(3) - (6)].d));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.d) = val[0];
    ;}
    break;

  case 447:
#line 5400 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 448:
#line 5405 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 449:
#line 5410 "Gmsh.y"
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

  case 450:
#line 5427 "Gmsh.y"
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

  case 451:
#line 5445 "Gmsh.y"
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

  case 452:
#line 5463 "Gmsh.y"
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

  case 453:
#line 5481 "Gmsh.y"
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
#line 5499 "Gmsh.y"
    {
      (yyval.d) = gmsh_yysymbols.count((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 455:
#line 5504 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.d) = !StatFile(tmp);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 456:
#line 5510 "Gmsh.y"
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

  case 457:
#line 5525 "Gmsh.y"
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

  case 458:
#line 5544 "Gmsh.y"
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

  case 459:
#line 5564 "Gmsh.y"
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

  case 460:
#line 5584 "Gmsh.y"
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

  case 461:
#line 5604 "Gmsh.y"
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
#line 5627 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), (yyval.d));
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 463:
#line 5632 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), (yyval.d));
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 464:
#line 5637 "Gmsh.y"
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

  case 465:
#line 5647 "Gmsh.y"
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

  case 466:
#line 5657 "Gmsh.y"
    {
      (yyval.d) = Msg::GetValue((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 467:
#line 5662 "Gmsh.y"
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

  case 468:
#line 5673 "Gmsh.y"
    {
      std::string s((yyvsp[(3) - (6)].c)), substr((yyvsp[(5) - (6)].c));
      if(s.find(substr) != std::string::npos)
        (yyval.d) = 1.;
      else
        (yyval.d) = 0.;
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 469:
#line 5682 "Gmsh.y"
    {
      (yyval.d) = strlen((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 470:
#line 5687 "Gmsh.y"
    {
      (yyval.d) = strcmp((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 471:
#line 5692 "Gmsh.y"
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

  case 472:
#line 5719 "Gmsh.y"
    {
      memcpy((yyval.v), (yyvsp[(1) - (1)].v), 5*sizeof(double));
    ;}
    break;

  case 473:
#line 5723 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 474:
#line 5727 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 475:
#line 5731 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] - (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 476:
#line 5735 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] + (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 477:
#line 5742 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (11)].d);  (yyval.v)[1] = (yyvsp[(4) - (11)].d);  (yyval.v)[2] = (yyvsp[(6) - (11)].d);  (yyval.v)[3] = (yyvsp[(8) - (11)].d); (yyval.v)[4] = (yyvsp[(10) - (11)].d);
    ;}
    break;

  case 478:
#line 5746 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (9)].d);  (yyval.v)[1] = (yyvsp[(4) - (9)].d);  (yyval.v)[2] = (yyvsp[(6) - (9)].d);  (yyval.v)[3] = (yyvsp[(8) - (9)].d); (yyval.v)[4] = 1.0;
    ;}
    break;

  case 479:
#line 5750 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 480:
#line 5754 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 481:
#line 5761 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].l)));
    ;}
    break;

  case 482:
#line 5766 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].l)));
    ;}
    break;

  case 483:
#line 5773 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 484:
#line 5778 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 485:
#line 5782 "Gmsh.y"
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    ;}
    break;

  case 486:
#line 5787 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 487:
#line 5791 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 488:
#line 5799 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (5)].d);
      }
    ;}
    break;

  case 489:
#line 5810 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 490:
#line 5814 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(1) - (1)].c), "*") || !strcmp((yyvsp[(1) - (1)].c), "all"))
        (yyval.l) = 0;
      else{
        yyerror("Unknown special string for list replacement");
        (yyval.l) = List_Create(2, 1, sizeof(double));
      }
    ;}
    break;

  case 491:
#line 5826 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 492:
#line 5834 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (3)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (3)].d);
      }
    ;}
    break;

  case 493:
#line 5842 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      for(double d = (yyvsp[(1) - (3)].d); ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d <= (yyvsp[(3) - (3)].d)) : (d >= (yyvsp[(3) - (3)].d));
          ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d += 1.) : (d -= 1.))
	List_Add((yyval.l), &d);
    ;}
    break;

  case 494:
#line 5849 "Gmsh.y"
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

  case 495:
#line 5859 "Gmsh.y"
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

  case 496:
#line 5888 "Gmsh.y"
    {
      (yyval.l) = GetAllElementaryEntityNumbers(0);
    ;}
    break;

  case 497:
#line 5892 "Gmsh.y"
    {
      (yyval.l) = GetAllElementaryEntityNumbers(1);
    ;}
    break;

  case 498:
#line 5896 "Gmsh.y"
    {
      (yyval.l) = GetAllElementaryEntityNumbers(2);
    ;}
    break;

  case 499:
#line 5900 "Gmsh.y"
    {
      (yyval.l) = GetAllElementaryEntityNumbers(3);
    ;}
    break;

  case 500:
#line 5904 "Gmsh.y"
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(0);
    ;}
    break;

  case 501:
#line 5908 "Gmsh.y"
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(1);
    ;}
    break;

  case 502:
#line 5912 "Gmsh.y"
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(2);
    ;}
    break;

  case 503:
#line 5916 "Gmsh.y"
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(3);
    ;}
    break;

  case 504:
#line 5920 "Gmsh.y"
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

  case 505:
#line 5949 "Gmsh.y"
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

  case 506:
#line 5978 "Gmsh.y"
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

  case 507:
#line 6007 "Gmsh.y"
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

  case 508:
#line 6037 "Gmsh.y"
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

  case 509:
#line 6050 "Gmsh.y"
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

  case 510:
#line 6063 "Gmsh.y"
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

  case 511:
#line 6076 "Gmsh.y"
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

  case 512:
#line 6088 "Gmsh.y"
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

  case 513:
#line 6098 "Gmsh.y"
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

  case 514:
#line 6108 "Gmsh.y"
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

  case 515:
#line 6118 "Gmsh.y"
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

  case 516:
#line 6130 "Gmsh.y"
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

  case 517:
#line 6143 "Gmsh.y"
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

  case 518:
#line 6155 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 519:
#line 6159 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 520:
#line 6163 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (6)].l);
    ;}
    break;

  case 521:
#line 6167 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (6)].l);
    ;}
    break;

  case 522:
#line 6171 "Gmsh.y"
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

  case 523:
#line 6189 "Gmsh.y"
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

  case 524:
#line 6207 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = (yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1);
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 525:
#line 6215 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = pow(10,(yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1));
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 526:
#line 6223 "Gmsh.y"
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

  case 527:
#line 6252 "Gmsh.y"
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

  case 528:
#line 6265 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 529:
#line 6270 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 530:
#line 6274 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].d)));
    ;}
    break;

  case 531:
#line 6278 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (3)].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 532:
#line 6290 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (9)].d), (int)(yyvsp[(4) - (9)].d), (int)(yyvsp[(6) - (9)].d), (int)(yyvsp[(8) - (9)].d));
    ;}
    break;

  case 533:
#line 6294 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (7)].d), (int)(yyvsp[(4) - (7)].d), (int)(yyvsp[(6) - (7)].d), 255);
    ;}
    break;

  case 534:
#line 6306 "Gmsh.y"
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

  case 535:
#line 6323 "Gmsh.y"
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(5) - (5)].c), val);
      (yyval.u) = val;
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(5) - (5)].c));
    ;}
    break;

  case 536:
#line 6333 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 537:
#line 6337 "Gmsh.y"
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

  case 538:
#line 6352 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].u)));
    ;}
    break;

  case 539:
#line 6357 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].u)));
    ;}
    break;

  case 540:
#line 6364 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 541:
#line 6368 "Gmsh.y"
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

  case 542:
#line 6381 "Gmsh.y"
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

  case 543:
#line 6395 "Gmsh.y"
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

  case 544:
#line 6409 "Gmsh.y"
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

  case 545:
#line 6423 "Gmsh.y"
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
#line 6437 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 547:
#line 6445 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 548:
#line 6456 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 549:
#line 6460 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 550:
#line 6464 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    ;}
    break;

  case 551:
#line 6472 "Gmsh.y"
    {
      std::string exe = Msg::GetExecutableName();
      (yyval.c) = (char *)Malloc(exe.size() + 1);
      strcpy((yyval.c), exe.c_str());
    ;}
    break;

  case 552:
#line 6478 "Gmsh.y"
    {
      std::string action = Msg::GetOnelabAction();
      (yyval.c) = (char *)Malloc(action.size() + 1);
      strcpy((yyval.c), action.c_str());
    ;}
    break;

  case 553:
#line 6484 "Gmsh.y"
    {
      const char *env = GetEnvironmentVar((yyvsp[(3) - (4)].c));
      if(!env) env = "";
      (yyval.c) = (char *)Malloc((sizeof(env) + 1) * sizeof(char));
      strcpy((yyval.c), env);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 554:
#line 6492 "Gmsh.y"
    {
      std::string s = Msg::GetString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 555:
#line 6500 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (4)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 556:
#line 6507 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 557:
#line 6515 "Gmsh.y"
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

  case 558:
#line 6530 "Gmsh.y"
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

  case 559:
#line 6544 "Gmsh.y"
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

  case 560:
#line 6558 "Gmsh.y"
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

  case 561:
#line 6570 "Gmsh.y"
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

  case 562:
#line 6586 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = toupper((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 563:
#line 6595 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = tolower((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 564:
#line 6604 "Gmsh.y"
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

  case 565:
#line 6614 "Gmsh.y"
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

  case 566:
#line 6625 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (8)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (8)].d), (int)(yyvsp[(7) - (8)].d));
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (8)].c));
    ;}
    break;

  case 567:
#line 6633 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (6)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (6)].d), std::string::npos);
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 568:
#line 6641 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 569:
#line 6645 "Gmsh.y"
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

  case 570:
#line 6664 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 571:
#line 6671 "Gmsh.y"
    {
      std::string tmp = SplitFileName(GetAbsolutePath(gmsh_yyname))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
    ;}
    break;

  case 572:
#line 6677 "Gmsh.y"
    {
      std::string tmp = SplitFileName((yyvsp[(3) - (4)].c))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 573:
#line 6684 "Gmsh.y"
    {
      std::string tmp = GetAbsolutePath((yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 574:
#line 6691 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 575:
#line 6693 "Gmsh.y"
    {
      std::string val((yyvsp[(3) - (6)].c));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.c) = (char*)Malloc((val.size() + 1) * sizeof(char));
      strcpy((yyval.c), val.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 576:
#line 6704 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].c)));
    ;}
    break;

  case 577:
#line 6709 "Gmsh.y"
    { List_Add((yyval.l), &((yyvsp[(3) - (3)].c))); ;}
    break;

  case 578:
#line 6715 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 579:
#line 6724 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char)) ;
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)) ; strcat((yyval.c), tmpstr) ;
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 580:
#line 6737 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 581:
#line 6740 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 582:
#line 6744 "Gmsh.y"
    { (yyval.c) = (yyvsp[(3) - (4)].c); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 13685 "Gmsh.tab.cpp"
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


#line 6747 "Gmsh.y"


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

