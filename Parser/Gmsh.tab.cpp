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
     tPhysical = 375,
     tCompound = 376,
     tPeriodic = 377,
     tUsing = 378,
     tPlugin = 379,
     tDegenerated = 380,
     tRecursive = 381,
     tRotate = 382,
     tTranslate = 383,
     tSymmetry = 384,
     tDilate = 385,
     tExtrude = 386,
     tLevelset = 387,
     tAffine = 388,
     tBooleanUnion = 389,
     tBooleanIntersection = 390,
     tBooleanDifference = 391,
     tBooleanSection = 392,
     tBooleanFragments = 393,
     tThickSolid = 394,
     tRecombine = 395,
     tSmoother = 396,
     tSplit = 397,
     tDelete = 398,
     tCoherence = 399,
     tIntersect = 400,
     tMeshAlgorithm = 401,
     tReverse = 402,
     tLayers = 403,
     tScaleLast = 404,
     tHole = 405,
     tAlias = 406,
     tAliasWithOptions = 407,
     tCopyOptions = 408,
     tQuadTriAddVerts = 409,
     tQuadTriNoNewVerts = 410,
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
#define tPhysical 375
#define tCompound 376
#define tPeriodic 377
#define tUsing 378
#define tPlugin 379
#define tDegenerated 380
#define tRecursive 381
#define tRotate 382
#define tTranslate 383
#define tSymmetry 384
#define tDilate 385
#define tExtrude 386
#define tLevelset 387
#define tAffine 388
#define tBooleanUnion 389
#define tBooleanIntersection 390
#define tBooleanDifference 391
#define tBooleanSection 392
#define tBooleanFragments 393
#define tThickSolid 394
#define tRecombine 395
#define tSmoother 396
#define tSplit 397
#define tDelete 398
#define tCoherence 399
#define tIntersect 400
#define tMeshAlgorithm 401
#define tReverse 402
#define tLayers 403
#define tScaleLast 404
#define tHole 405
#define tAlias 406
#define tAliasWithOptions 407
#define tCopyOptions 408
#define tQuadTriAddVerts 409
#define tQuadTriNoNewVerts 410
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
#include "GeoDefines.h"
#include "Geo.h" // FIXME: remove once Extrusion has been refactored
#include "ExtrudeParams.h"
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

#define MAX_RECUR_TESTS 100
#define MAX_RECUR_LOOPS 100

// Global parser variables
std::string gmsh_yyname;
int gmsh_yyerrorstate = 0;
int gmsh_yyviewindex = 0;
std::map<std::string, gmsh_yysymbol> gmsh_yysymbols;
std::map<std::string, std::vector<std::string> > gmsh_yystringsymbols;

// Static parser variables (accessible only in this file)
#if defined(HAVE_POST)
static PViewDataList *ViewData = 0;
#endif
static std::vector<double> ViewCoord;
static std::vector<double> *ViewValueList = 0;
static int *ViewNumList = 0;
static ExtrudeParams extr;
static gmshSurface *myGmshSurface = 0;
static int statusImbricatedTests[MAX_RECUR_TESTS];
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
char *strsave(char *ptr);
void skip(const char *skip, const char *until);
void skipTest(const char *skip, const char *until,
              const char *until2, int l_until2_sub, int *type_until2);
void assignVariable(const std::string &name, int index, int assignType,
                    double value);
void assignVariables(const std::string &name, List_T *indices, int assignType,
                     List_T *values);
void incrementVariable(const std::string &name, int index, double value);
int printListOfDouble(char *format, List_T *list, char *buffer);
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
void getAllElementaryTags(int dim, List_T *in);
void getAllPhysicalTags(int dim, List_T *in);
void getElementaryTagsForPhysicalGroups(int dim, List_T *in, List_T *out);
void getElementaryTagsInBoundingBox(int dim, double x1, double y1, double z1,
                                    double x2, double y2, double z2, List_T *out);
void setVisibility(int dim, int visible, bool recursive);
void setVisibility(std::vector<int> tags[4], int visible, bool recursive);
void setColor(std::vector<int> tags[4], unsigned int val, bool recursive);

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
#line 133 "Gmsh.y"
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
#line 678 "Gmsh.tab.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 691 "Gmsh.tab.cpp"

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
#define YYLAST   14696

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  237
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  102
/* YYNRULES -- Number of rules.  */
#define YYNRULES  577
/* YYNRULES -- Number of states.  */
#define YYNSTATES  2170

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
    1111,  1124,  1133,  1141,  1149,  1158,  1167,  1176,  1185,  1194,
    1203,  1209,  1221,  1227,  1237,  1247,  1252,  1262,  1272,  1274,
    1276,  1277,  1280,  1287,  1294,  1301,  1308,  1317,  1328,  1343,
    1360,  1373,  1388,  1403,  1418,  1433,  1442,  1451,  1458,  1463,
    1470,  1477,  1481,  1486,  1492,  1499,  1505,  1509,  1513,  1518,
    1524,  1529,  1535,  1539,  1545,  1553,  1561,  1565,  1573,  1577,
    1580,  1583,  1586,  1589,  1592,  1608,  1611,  1614,  1617,  1620,
    1623,  1640,  1652,  1659,  1668,  1677,  1688,  1690,  1693,  1696,
    1698,  1702,  1706,  1711,  1716,  1718,  1720,  1726,  1738,  1752,
    1753,  1761,  1762,  1776,  1777,  1793,  1794,  1801,  1811,  1814,
    1818,  1829,  1831,  1834,  1840,  1848,  1851,  1854,  1858,  1861,
    1865,  1868,  1872,  1882,  1889,  1891,  1893,  1895,  1897,  1899,
    1900,  1903,  1907,  1917,  1922,  1937,  1938,  1942,  1943,  1945,
    1946,  1949,  1950,  1953,  1954,  1957,  1964,  1972,  1979,  1985,
    1989,  1998,  2004,  2009,  2016,  2028,  2040,  2059,  2078,  2091,
    2104,  2117,  2128,  2139,  2150,  2161,  2172,  2177,  2182,  2187,
    2192,  2197,  2202,  2207,  2212,  2217,  2220,  2224,  2231,  2233,
    2235,  2237,  2240,  2246,  2254,  2265,  2267,  2271,  2274,  2277,
    2280,  2284,  2288,  2292,  2296,  2300,  2304,  2308,  2312,  2316,
    2320,  2324,  2328,  2332,  2336,  2342,  2347,  2352,  2357,  2362,
    2367,  2372,  2377,  2382,  2387,  2392,  2399,  2404,  2409,  2414,
    2419,  2424,  2429,  2434,  2441,  2448,  2455,  2460,  2462,  2464,
    2466,  2468,  2470,  2472,  2474,  2476,  2478,  2480,  2482,  2483,
    2490,  2492,  2497,  2504,  2506,  2511,  2516,  2521,  2526,  2531,
    2536,  2541,  2544,  2550,  2556,  2562,  2568,  2572,  2579,  2584,
    2592,  2599,  2606,  2613,  2618,  2625,  2630,  2631,  2640,  2642,
    2647,  2649,  2650,  2654,  2656,  2659,  2662,  2666,  2670,  2682,
    2692,  2700,  2708,  2710,  2714,  2716,  2718,  2721,  2725,  2730,
    2736,  2738,  2740,  2743,  2747,  2751,  2757,  2762,  2765,  2768,
    2771,  2774,  2778,  2782,  2786,  2790,  2807,  2824,  2841,  2858,
    2860,  2862,  2864,  2868,  2872,  2877,  2882,  2887,  2894,  2901,
    2908,  2915,  2924,  2933,  2938,  2953,  2958,  2960,  2962,  2966,
    2970,  2980,  2988,  2990,  2996,  3000,  3007,  3009,  3013,  3015,
    3017,  3022,  3027,  3032,  3037,  3041,  3048,  3054,  3060,  3066,
    3072,  3074,  3079,  3081,  3083,  3085,  3090,  3097,  3102,  3109,
    3114,  3119,  3124,  3133,  3138,  3143,  3148,  3153,  3162,  3171,
    3178,  3183,  3190,  3195,  3197,  3202,  3207,  3208,  3215,  3220,
    3223,  3229,  3231,  3235,  3241,  3247,  3249,  3251
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     238,     0,    -1,   239,    -1,     1,     6,    -1,    -1,   239,
     240,    -1,   242,    -1,   243,    -1,   263,    -1,   112,   227,
     332,   228,     6,    -1,   282,    -1,   283,    -1,   287,    -1,
     288,    -1,   289,    -1,   290,    -1,   294,    -1,   303,    -1,
     304,    -1,   310,    -1,   311,    -1,   293,    -1,   292,    -1,
     291,    -1,   286,    -1,   313,    -1,   214,    -1,   214,   214,
      -1,    42,   227,   332,   228,     6,    -1,    43,   227,   332,
     228,     6,    -1,    42,   227,   332,   228,   241,   332,     6,
      -1,    42,   227,   332,   233,   328,   228,     6,    -1,    43,
     227,   332,   233,   328,   228,     6,    -1,    42,   227,   332,
     233,   328,   228,   241,   332,     6,    -1,     4,   332,   234,
     244,   235,     6,    -1,   151,     4,   229,   314,   230,     6,
      -1,   152,     4,   229,   314,   230,     6,    -1,   153,     4,
     229,   314,   233,   314,   230,     6,    -1,    -1,   244,   247,
      -1,   244,   251,    -1,   244,   254,    -1,   244,   256,    -1,
     244,   257,    -1,   314,    -1,   245,   233,   314,    -1,   314,
      -1,   246,   233,   314,    -1,    -1,    -1,     4,   248,   227,
     245,   228,   249,   234,   246,   235,     6,    -1,   332,    -1,
     250,   233,   332,    -1,    -1,   158,   227,   314,   233,   314,
     233,   314,   228,   252,   234,   250,   235,     6,    -1,   332,
      -1,   253,   233,   332,    -1,    -1,   159,   227,   314,   233,
     314,   233,   314,   233,   314,   228,   255,   234,   253,   235,
       6,    -1,   160,   234,   324,   235,   234,   324,   235,     6,
      -1,   160,   234,   324,   235,   234,   324,   235,   234,   324,
     235,   234,   324,   235,     6,    -1,    -1,   161,   258,   234,
     246,   235,     6,    -1,     7,    -1,   207,    -1,   206,    -1,
     205,    -1,   204,    -1,   225,    -1,   224,    -1,   227,    -1,
     229,    -1,   228,    -1,   230,    -1,    78,   229,   265,   230,
       6,    -1,    79,   229,   270,   230,     6,    -1,   317,     6,
      -1,    84,   261,   333,   233,   314,   262,     6,    -1,    85,
     261,   338,   233,   333,   262,     6,    -1,   338,   259,   325,
       6,    -1,   338,   260,     6,    -1,     4,   229,   230,   259,
     325,     6,    -1,   337,   229,   230,   259,   325,     6,    -1,
       4,   229,   314,   230,   259,   314,     6,    -1,   337,   229,
     314,   230,   259,   314,     6,    -1,     4,   229,   314,   230,
     260,     6,    -1,   337,   229,   314,   230,   260,     6,    -1,
       4,   261,   234,   328,   235,   262,   259,   325,     6,    -1,
     337,   261,   234,   328,   235,   262,   259,   325,     6,    -1,
       4,   227,   228,   259,   325,     6,    -1,   337,   227,   228,
     259,   325,     6,    -1,     4,   227,   314,   228,   259,   314,
       6,    -1,   337,   227,   314,   228,   259,   314,     6,    -1,
       4,   227,   314,   228,   260,     6,    -1,   337,   227,   314,
     228,   260,     6,    -1,   338,     7,   333,     6,    -1,     4,
     229,   230,     7,    44,   261,   262,     6,    -1,   337,   229,
     230,     7,    44,   261,   262,     6,    -1,     4,   229,   230,
       7,    44,   261,   336,   262,     6,    -1,   337,   229,   230,
       7,    44,   261,   336,   262,     6,    -1,     4,   229,   230,
     207,    44,   261,   336,   262,     6,    -1,   337,   229,   230,
     207,    44,   261,   336,   262,     6,    -1,     4,   227,   228,
       7,    44,   261,   262,     6,    -1,   337,   227,   228,     7,
      44,   261,   262,     6,    -1,     4,   227,   228,     7,    44,
     261,   336,   262,     6,    -1,   337,   227,   228,     7,    44,
     261,   336,   262,     6,    -1,     4,   227,   228,   207,    44,
     261,   336,   262,     6,    -1,   337,   227,   228,   207,    44,
     261,   336,   262,     6,    -1,     4,   231,     4,     7,   333,
       6,    -1,     4,   229,   314,   230,   231,     4,     7,   333,
       6,    -1,     4,   231,     4,   259,   314,     6,    -1,     4,
     229,   314,   230,   231,     4,   259,   314,     6,    -1,     4,
     231,     4,   260,     6,    -1,     4,   229,   314,   230,   231,
       4,   260,     6,    -1,     4,   231,   168,   231,     4,     7,
     329,     6,    -1,     4,   229,   314,   230,   231,   168,   231,
       4,     7,   329,     6,    -1,     4,   231,   169,     7,   330,
       6,    -1,     4,   229,   314,   230,   231,   169,     7,   330,
       6,    -1,     4,   179,     7,   314,     6,    -1,   179,   229,
     314,   230,     7,     4,     6,    -1,   179,   229,   314,   230,
     231,     4,     7,   314,     6,    -1,   179,   229,   314,   230,
     231,     4,     7,   333,     6,    -1,   179,   229,   314,   230,
     231,     4,     7,   234,   328,   235,     6,    -1,   179,   229,
     314,   230,   231,     4,     6,    -1,   124,   227,     4,   228,
     231,     4,     7,   314,     6,    -1,   124,   227,     4,   228,
     231,     4,     7,   333,     6,    -1,    -1,   233,    -1,    -1,
     265,   264,   338,    -1,   265,   264,   338,     7,   314,    -1,
      -1,   265,   264,   338,     7,   234,   325,   266,   272,   235,
      -1,    -1,   265,   264,   338,   229,   230,     7,   234,   325,
     267,   272,   235,    -1,    -1,   265,   264,   338,   227,   228,
       7,   234,   325,   268,   272,   235,    -1,   265,   264,   338,
       7,   333,    -1,    -1,   265,   264,   338,     7,   234,   333,
     269,   274,   235,    -1,    -1,   270,   264,   332,    -1,   314,
       7,   333,    -1,   271,   233,   314,     7,   333,    -1,   327,
       7,   338,   227,   228,    -1,    -1,   272,   273,    -1,   233,
       4,   325,    -1,   233,     4,   234,   271,   235,    -1,   233,
       4,   333,    -1,    -1,   274,   275,    -1,   233,     4,   314,
      -1,   233,     4,   333,    -1,   233,   183,   333,    -1,   233,
       4,   234,   336,   235,    -1,   314,    -1,   333,    -1,   333,
     233,   314,    -1,   314,    -1,   333,    -1,   333,   233,   314,
      -1,   314,    -1,   333,    -1,   333,   233,   314,    -1,   314,
      -1,   333,    -1,   333,   233,   314,    -1,    -1,   171,    90,
     234,   314,   235,    -1,    -1,   117,   322,    -1,    86,   227,
     314,   228,     7,   322,     6,    -1,    89,   227,   314,   228,
       7,   325,     6,    -1,    93,   227,   314,   228,     7,   325,
       6,    -1,    87,   227,   314,   228,     7,   325,   281,     6,
      -1,    88,   227,   314,   228,     7,   325,   281,     6,    -1,
     163,   227,   314,   228,     7,   325,     6,    -1,   164,   227,
     314,   228,     7,   325,     6,    -1,   165,   227,   314,   228,
       7,   325,   167,   325,   166,   314,     6,    -1,   121,    89,
     227,   314,   228,     7,   325,     6,    -1,   104,   227,   314,
     228,     7,   325,     6,    -1,    89,     4,   227,   314,   228,
       7,   325,     6,    -1,   117,    92,   227,   314,   228,     7,
     325,     6,    -1,    92,   227,   314,   228,     7,   325,   280,
       6,    -1,   118,    92,   227,   314,   228,     7,   325,   280,
       6,    -1,    12,    13,     6,    -1,    13,    92,   314,     6,
      -1,   107,    92,   227,   314,   228,     7,     5,     5,     5,
       6,    -1,    90,   227,   314,   228,     7,   325,     6,    -1,
      91,   227,   314,   228,     7,   325,     6,    -1,    95,   227,
     314,   228,     7,   325,     6,    -1,    98,   227,   314,   228,
       7,   325,     6,    -1,   102,   227,   314,   228,     7,   325,
       6,    -1,   103,   227,   314,   228,     7,   325,     6,    -1,
      96,   227,   314,   228,     7,   325,     6,    -1,    97,   227,
     314,   228,     7,   325,     6,    -1,   114,   227,   314,   228,
       7,   325,     6,    -1,   139,   227,   314,   228,     7,   325,
       6,    -1,   121,    92,   227,   314,   228,     7,   325,     6,
      -1,   121,    92,   227,   314,   228,     7,   325,     4,   234,
     324,   235,     6,    -1,    92,     4,   227,   314,   228,     7,
     325,     6,    -1,    94,   227,   314,   228,     7,   325,     6,
      -1,   113,   227,   314,   228,     7,   325,     6,    -1,   118,
     113,   227,   314,   228,     7,   325,     6,    -1,   121,    94,
     227,   314,   228,     7,   325,     6,    -1,   120,    86,   227,
     276,   228,   259,   325,     6,    -1,   120,    89,   227,   277,
     228,   259,   325,     6,    -1,   120,    92,   227,   278,   228,
     259,   325,     6,    -1,   120,    94,   227,   279,   228,   259,
     325,     6,    -1,   128,   322,   234,   284,   235,    -1,   127,
     234,   322,   233,   322,   233,   314,   235,   234,   284,   235,
      -1,   129,   322,   234,   284,   235,    -1,   130,   234,   322,
     233,   314,   235,   234,   284,   235,    -1,   130,   234,   322,
     233,   322,   235,   234,   284,   235,    -1,     4,   234,   284,
     235,    -1,   145,    89,   234,   328,   235,    92,   234,   314,
     235,    -1,   142,    89,   227,   314,   228,   234,   328,   235,
       6,    -1,   285,    -1,   283,    -1,    -1,   285,   282,    -1,
     285,    86,   234,   328,   235,     6,    -1,   285,    89,   234,
     328,   235,     6,    -1,   285,    92,   234,   328,   235,     6,
      -1,   285,    94,   234,   328,   235,     6,    -1,   132,   117,
     227,   314,   228,     7,   325,     6,    -1,   132,    86,   227,
     314,   228,     7,   234,   324,   235,     6,    -1,   132,   117,
     227,   314,   228,     7,   234,   322,   233,   322,   233,   328,
     235,     6,    -1,   132,   117,   227,   314,   228,     7,   234,
     322,   233,   322,   233,   322,   233,   328,   235,     6,    -1,
     132,    90,   227,   314,   228,     7,   234,   322,   233,   328,
     235,     6,    -1,   132,    96,   227,   314,   228,     7,   234,
     322,   233,   322,   233,   328,   235,     6,    -1,   132,    97,
     227,   314,   228,     7,   234,   322,   233,   322,   233,   328,
     235,     6,    -1,   132,    99,   227,   314,   228,     7,   234,
     322,   233,   322,   233,   328,   235,     6,    -1,   132,   100,
     227,   314,   228,     7,   234,   322,   233,   322,   233,   328,
     235,     6,    -1,   132,     4,   227,   314,   228,     7,   325,
       6,    -1,   132,     4,   227,   314,   228,     7,     5,     6,
      -1,   132,     4,   234,   314,   235,     6,    -1,   143,   234,
     285,   235,    -1,   143,   179,   229,   314,   230,     6,    -1,
     143,     4,   229,   314,   230,     6,    -1,   143,   338,     6,
      -1,   143,     4,     4,     6,    -1,   168,   329,   234,   285,
     235,    -1,   126,   168,   329,   234,   285,   235,    -1,   201,
     314,   234,   285,   235,    -1,   184,     5,     6,    -1,   185,
       5,     6,    -1,   184,   234,   285,   235,    -1,   126,   184,
     234,   285,   235,    -1,   185,   234,   285,   235,    -1,   126,
     185,   234,   285,   235,    -1,     4,   333,     6,    -1,    71,
     227,   336,   228,     6,    -1,     4,     4,   229,   314,   230,
     332,     6,    -1,     4,     4,     4,   229,   314,   230,     6,
      -1,     4,   314,     6,    -1,   124,   227,     4,   228,   231,
       4,     6,    -1,   162,     4,     6,    -1,   177,     6,    -1,
     178,     6,    -1,    68,     6,    -1,    69,     6,    -1,    62,
       6,    -1,    62,   234,   314,   233,   314,   233,   314,   233,
     314,   233,   314,   233,   314,   235,     6,    -1,    63,     6,
      -1,    64,     6,    -1,    75,     6,    -1,    76,     6,    -1,
     109,     6,    -1,   110,   234,   328,   235,   234,   328,   235,
     234,   324,   235,   234,   314,   233,   314,   235,     6,    -1,
     182,   227,   234,   328,   235,   233,   333,   233,   333,   228,
       6,    -1,   170,   227,   314,     8,   314,   228,    -1,   170,
     227,   314,     8,   314,     8,   314,   228,    -1,   170,     4,
     171,   234,   314,     8,   314,   235,    -1,   170,     4,   171,
     234,   314,     8,   314,     8,   314,   235,    -1,   172,    -1,
     183,     4,    -1,   183,   333,    -1,   180,    -1,   181,   338,
       6,    -1,   181,   333,     6,    -1,   173,   227,   314,   228,
      -1,   174,   227,   314,   228,    -1,   175,    -1,   176,    -1,
     131,   322,   234,   285,   235,    -1,   131,   234,   322,   233,
     322,   233,   314,   235,   234,   285,   235,    -1,   131,   234,
     322,   233,   322,   233,   322,   233,   314,   235,   234,   285,
     235,    -1,    -1,   131,   322,   234,   285,   295,   299,   235,
      -1,    -1,   131,   234,   322,   233,   322,   233,   314,   235,
     234,   285,   296,   299,   235,    -1,    -1,   131,   234,   322,
     233,   322,   233,   322,   233,   314,   235,   234,   285,   297,
     299,   235,    -1,    -1,   131,   234,   285,   298,   299,   235,
      -1,   131,   234,   285,   235,   123,   104,   234,   314,   235,
      -1,   113,   325,    -1,   118,   113,   325,    -1,   115,   234,
     328,   235,   234,   328,   235,   234,   314,   235,    -1,   300,
      -1,   299,   300,    -1,   148,   234,   314,   235,     6,    -1,
     148,   234,   325,   233,   325,   235,     6,    -1,   149,     6,
      -1,   140,     6,    -1,   140,   314,     6,    -1,   154,     6,
      -1,   154,   156,     6,    -1,   155,     6,    -1,   155,   156,
       6,    -1,   150,   227,   314,   228,     7,   325,   123,   314,
       6,    -1,   123,     4,   229,   314,   230,     6,    -1,   134,
      -1,   135,    -1,   136,    -1,   137,    -1,   138,    -1,    -1,
     143,     6,    -1,   143,   314,     6,    -1,   301,   234,   285,
     302,   235,   234,   285,   302,   235,    -1,   101,   227,   332,
     228,    -1,   301,   227,   314,   228,     7,   234,   285,   302,
     235,   234,   285,   302,   235,     6,    -1,    -1,   123,     4,
     314,    -1,    -1,     4,    -1,    -1,     7,   325,    -1,    -1,
       7,   314,    -1,    -1,   133,   325,    -1,   105,   106,   325,
       7,   314,     6,    -1,   119,    89,   326,     7,   314,   305,
       6,    -1,   119,    92,   326,   307,   306,     6,    -1,   119,
      94,   326,   307,     6,    -1,   157,   326,     6,    -1,   146,
      92,   234,   328,   235,     7,   314,     6,    -1,   140,    92,
     326,   308,     6,    -1,   140,    94,   326,     6,    -1,   141,
      92,   326,     7,   314,     6,    -1,   122,    89,   234,   328,
     235,     7,   234,   328,   235,   309,     6,    -1,   122,    92,
     234,   328,   235,     7,   234,   328,   235,   309,     6,    -1,
     122,    89,   234,   328,   235,     7,   234,   328,   235,   127,
     234,   322,   233,   322,   233,   314,   235,     6,    -1,   122,
      92,   234,   328,   235,     7,   234,   328,   235,   127,   234,
     322,   233,   322,   233,   314,   235,     6,    -1,   122,    89,
     234,   328,   235,     7,   234,   328,   235,   128,   322,     6,
      -1,   122,    92,   234,   328,   235,     7,   234,   328,   235,
     128,   322,     6,    -1,   122,    92,   314,   234,   328,   235,
       7,   314,   234,   328,   235,     6,    -1,    86,   234,   328,
     235,   171,    92,   234,   314,   235,     6,    -1,    89,   234,
     328,   235,   171,    92,   234,   314,   235,     6,    -1,    86,
     234,   328,   235,   171,    94,   234,   314,   235,     6,    -1,
      89,   234,   328,   235,   171,    94,   234,   314,   235,     6,
      -1,    92,   234,   328,   235,   171,    94,   234,   314,   235,
       6,    -1,   147,    92,   326,     6,    -1,   147,    89,   326,
       6,    -1,   111,    86,   326,     6,    -1,   111,    89,   326,
       6,    -1,   111,    92,   326,     6,    -1,   125,    89,   325,
       6,    -1,   121,    89,   325,     6,    -1,   121,    92,   325,
       6,    -1,   121,    94,   325,     6,    -1,   144,     6,    -1,
     144,     4,     6,    -1,   144,    86,   234,   328,   235,     6,
      -1,   192,    -1,   193,    -1,   194,    -1,   312,     6,    -1,
     312,   234,   325,   235,     6,    -1,   312,   234,   325,   233,
     325,   235,     6,    -1,   312,   227,   325,   228,   234,   325,
     233,   325,   235,     6,    -1,   315,    -1,   227,   314,   228,
      -1,   218,   314,    -1,   217,   314,    -1,   222,   314,    -1,
     314,   218,   314,    -1,   314,   217,   314,    -1,   314,   219,
     314,    -1,   314,   220,   314,    -1,   314,   221,   314,    -1,
     314,   226,   314,    -1,   314,   213,   314,    -1,   314,   214,
     314,    -1,   314,   216,   314,    -1,   314,   215,   314,    -1,
     314,   212,   314,    -1,   314,   211,   314,    -1,   314,   210,
     314,    -1,   314,   209,   314,    -1,   314,   208,   314,     8,
     314,    -1,    15,   261,   314,   262,    -1,    16,   261,   314,
     262,    -1,    17,   261,   314,   262,    -1,    18,   261,   314,
     262,    -1,    19,   261,   314,   262,    -1,    20,   261,   314,
     262,    -1,    21,   261,   314,   262,    -1,    22,   261,   314,
     262,    -1,    23,   261,   314,   262,    -1,    25,   261,   314,
     262,    -1,    26,   261,   314,   233,   314,   262,    -1,    27,
     261,   314,   262,    -1,    28,   261,   314,   262,    -1,    29,
     261,   314,   262,    -1,    30,   261,   314,   262,    -1,    31,
     261,   314,   262,    -1,    32,   261,   314,   262,    -1,    33,
     261,   314,   262,    -1,    34,   261,   314,   233,   314,   262,
      -1,    35,   261,   314,   233,   314,   262,    -1,    36,   261,
     314,   233,   314,   262,    -1,    24,   261,   314,   262,    -1,
       3,    -1,     9,    -1,    14,    -1,    10,    -1,    11,    -1,
     197,    -1,   198,    -1,   199,    -1,    72,    -1,    73,    -1,
      74,    -1,    -1,    80,   261,   314,   316,   272,   262,    -1,
     317,    -1,   190,   261,   332,   262,    -1,   190,   261,   332,
     233,   314,   262,    -1,   338,    -1,     4,   229,   314,   230,
      -1,     4,   227,   314,   228,    -1,   337,   229,   314,   230,
      -1,   337,   227,   314,   228,    -1,   195,   227,   338,   228,
      -1,   196,   227,   333,   228,    -1,   232,   338,   261,   262,
      -1,   338,   260,    -1,     4,   229,   314,   230,   260,    -1,
       4,   227,   314,   228,   260,    -1,   337,   229,   314,   230,
     260,    -1,   337,   227,   314,   228,   260,    -1,   338,   231,
     320,    -1,     4,   229,   314,   230,   231,     4,    -1,   338,
     231,   320,   260,    -1,     4,   229,   314,   230,   231,     4,
     260,    -1,   186,   227,   332,   233,   314,   228,    -1,    54,
     227,   325,   233,   325,   228,    -1,    55,   261,   332,   233,
     332,   262,    -1,    53,   261,   332,   262,    -1,    56,   261,
     332,   233,   332,   262,    -1,    61,   227,   336,   228,    -1,
      -1,    81,   319,   318,   321,   229,   314,   272,   230,    -1,
     338,    -1,   338,     8,     8,   338,    -1,     4,    -1,    -1,
     234,   338,   235,    -1,   323,    -1,   218,   322,    -1,   217,
     322,    -1,   322,   218,   322,    -1,   322,   217,   322,    -1,
     234,   314,   233,   314,   233,   314,   233,   314,   233,   314,
     235,    -1,   234,   314,   233,   314,   233,   314,   233,   314,
     235,    -1,   234,   314,   233,   314,   233,   314,   235,    -1,
     227,   314,   233,   314,   233,   314,   228,    -1,   325,    -1,
     324,   233,   325,    -1,   314,    -1,   327,    -1,   234,   235,
      -1,   234,   328,   235,    -1,   218,   234,   328,   235,    -1,
     314,   219,   234,   328,   235,    -1,   325,    -1,     5,    -1,
     218,   327,    -1,   314,   219,   327,    -1,   314,     8,   314,
      -1,   314,     8,   314,     8,   314,    -1,    86,   234,   314,
     235,    -1,    86,     5,    -1,    89,     5,    -1,    92,     5,
      -1,    94,     5,    -1,   120,    86,   326,    -1,   120,    89,
     326,    -1,   120,    92,   326,    -1,   120,    94,   326,    -1,
      86,   171,    62,   234,   314,   233,   314,   233,   314,   233,
     314,   233,   314,   233,   314,   235,    -1,    89,   171,    62,
     234,   314,   233,   314,   233,   314,   233,   314,   233,   314,
     233,   314,   235,    -1,    92,   171,    62,   234,   314,   233,
     314,   233,   314,   233,   314,   233,   314,   233,   314,   235,
      -1,    94,   171,    62,   234,   314,   233,   314,   233,   314,
     233,   314,   233,   314,   233,   314,   235,    -1,   283,    -1,
     294,    -1,   303,    -1,     4,   261,   262,    -1,   337,   261,
     262,    -1,    37,   229,   338,   230,    -1,    37,   229,   327,
     230,    -1,    37,   227,   327,   228,    -1,    37,   229,   234,
     328,   235,   230,    -1,    37,   227,   234,   328,   235,   228,
      -1,     4,   261,   234,   328,   235,   262,    -1,   337,   261,
     234,   328,   235,   262,    -1,    38,   261,   314,   233,   314,
     233,   314,   262,    -1,    39,   261,   314,   233,   314,   233,
     314,   262,    -1,    40,   261,   332,   262,    -1,    41,   261,
     314,   233,   314,   233,   314,   233,   314,   233,   314,   233,
     314,   262,    -1,   191,   261,   327,   262,    -1,   314,    -1,
     327,    -1,   328,   233,   314,    -1,   328,   233,   327,    -1,
     234,   314,   233,   314,   233,   314,   233,   314,   235,    -1,
     234,   314,   233,   314,   233,   314,   235,    -1,   338,    -1,
       4,   231,   168,   231,     4,    -1,   234,   331,   235,    -1,
       4,   229,   314,   230,   231,   169,    -1,   329,    -1,   331,
     233,   329,    -1,   333,    -1,   338,    -1,     4,   229,   314,
     230,    -1,   337,   229,   314,   230,    -1,     4,   227,   314,
     228,    -1,   337,   227,   314,   228,    -1,   338,   231,   320,
      -1,     4,   229,   314,   230,   231,     4,    -1,   120,    86,
     234,   314,   235,    -1,   120,    89,   234,   314,   235,    -1,
     120,    92,   234,   314,   235,    -1,   120,    94,   234,   314,
     235,    -1,     5,    -1,   202,   229,   338,   230,    -1,    65,
      -1,   200,    -1,    70,    -1,   188,   227,   332,   228,    -1,
     187,   227,   332,   233,   332,   228,    -1,   189,   261,   332,
     262,    -1,   189,   261,   332,   233,   332,   262,    -1,    46,
     261,   336,   262,    -1,    47,   227,   332,   228,    -1,    48,
     227,   332,   228,    -1,    49,   227,   332,   233,   332,   233,
     332,   228,    -1,    44,   261,   336,   262,    -1,    58,   261,
     332,   262,    -1,    59,   261,   332,   262,    -1,    60,   261,
     332,   262,    -1,    57,   261,   314,   233,   332,   233,   332,
     262,    -1,    52,   261,   332,   233,   314,   233,   314,   262,
      -1,    52,   261,   332,   233,   314,   262,    -1,    45,   261,
     332,   262,    -1,    45,   261,   332,   233,   328,   262,    -1,
      66,   261,   332,   262,    -1,    67,    -1,    51,   261,   332,
     262,    -1,    50,   261,   332,   262,    -1,    -1,    83,   261,
     333,   334,   274,   262,    -1,    82,   261,   335,   262,    -1,
     232,   314,    -1,   338,     8,     8,   232,   314,    -1,   332,
      -1,   336,   233,   332,    -1,     4,   236,   234,   314,   235,
      -1,   337,   236,   234,   314,   235,    -1,     4,    -1,   337,
      -1,   203,   229,   332,   230,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   227,   227,   228,   233,   235,   239,   240,   241,   242,
     259,   260,   261,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   278,   282,   289,   294,
     299,   313,   326,   339,   367,   381,   394,   407,   426,   431,
     432,   433,   434,   435,   439,   441,   446,   448,   454,   558,
     453,   576,   583,   594,   593,   611,   618,   629,   628,   645,
     662,   685,   684,   698,   699,   700,   701,   702,   706,   707,
     713,   713,   714,   714,   720,   721,   722,   723,   728,   734,
     796,   813,   842,   871,   876,   881,   886,   891,   898,   908,
     937,   966,   971,   976,   981,   989,   998,  1004,  1010,  1023,
    1036,  1051,  1068,  1074,  1080,  1093,  1106,  1121,  1138,  1145,
    1154,  1173,  1192,  1202,  1214,  1220,  1228,  1249,  1272,  1283,
    1291,  1313,  1336,  1374,  1395,  1407,  1421,  1421,  1423,  1425,
    1434,  1444,  1443,  1464,  1463,  1482,  1481,  1499,  1509,  1508,
    1522,  1524,  1532,  1538,  1543,  1569,  1570,  1574,  1585,  1600,
    1610,  1611,  1616,  1624,  1633,  1641,  1659,  1663,  1669,  1677,
    1681,  1687,  1695,  1699,  1705,  1713,  1717,  1723,  1732,  1735,
    1742,  1745,  1752,  1773,  1787,  1801,  1836,  1874,  1888,  1902,
    1922,  1931,  1945,  1960,  1974,  1993,  2003,  2009,  2015,  2022,
    2049,  2064,  2084,  2105,  2126,  2147,  2169,  2191,  2212,  2235,
    2244,  2265,  2280,  2294,  2309,  2324,  2333,  2343,  2353,  2363,
    2378,  2389,  2402,  2414,  2426,  2438,  2475,  2486,  2502,  2503,
    2508,  2511,  2515,  2526,  2537,  2548,  2564,  2583,  2604,  2619,
    2635,  2653,  2704,  2725,  2747,  2770,  2875,  2891,  2926,  2940,
    2946,  2961,  2989,  3006,  3012,  3023,  3037,  3043,  3049,  3055,
    3061,  3067,  3078,  3151,  3169,  3186,  3201,  3234,  3246,  3270,
    3274,  3279,  3286,  3291,  3301,  3306,  3312,  3320,  3324,  3328,
    3337,  3401,  3417,  3434,  3451,  3473,  3495,  3530,  3538,  3546,
    3552,  3559,  3566,  3586,  3612,  3624,  3636,  3652,  3668,  3677,
    3676,  3691,  3690,  3705,  3704,  3719,  3718,  3731,  3744,  3758,
    3772,  3791,  3794,  3800,  3812,  3832,  3836,  3840,  3844,  3848,
    3852,  3856,  3860,  3869,  3882,  3883,  3884,  3885,  3886,  3890,
    3891,  3892,  3895,  3913,  3930,  3947,  3950,  3966,  3969,  3986,
    3989,  3995,  3998,  4005,  4008,  4015,  4032,  4073,  4117,  4156,
    4181,  4190,  4220,  4246,  4272,  4304,  4331,  4357,  4383,  4409,
    4435,  4457,  4463,  4469,  4475,  4481,  4487,  4513,  4539,  4556,
    4573,  4590,  4602,  4608,  4614,  4626,  4630,  4640,  4651,  4652,
    4653,  4657,  4663,  4675,  4693,  4721,  4722,  4723,  4724,  4725,
    4726,  4727,  4728,  4729,  4736,  4737,  4738,  4739,  4740,  4741,
    4742,  4743,  4744,  4745,  4746,  4747,  4748,  4749,  4750,  4751,
    4752,  4753,  4754,  4755,  4756,  4757,  4758,  4759,  4760,  4761,
    4762,  4763,  4764,  4765,  4766,  4767,  4768,  4777,  4778,  4779,
    4780,  4781,  4782,  4783,  4784,  4785,  4786,  4787,  4792,  4791,
    4799,  4801,  4806,  4811,  4834,  4852,  4870,  4888,  4906,  4911,
    4917,  4932,  4951,  4971,  4991,  5011,  5041,  5059,  5064,  5074,
    5084,  5089,  5100,  5109,  5114,  5119,  5148,  5147,  5160,  5162,
    5167,  5176,  5178,  5187,  5191,  5195,  5199,  5203,  5210,  5214,
    5218,  5222,  5229,  5234,  5241,  5246,  5250,  5255,  5259,  5267,
    5278,  5282,  5294,  5302,  5310,  5317,  5327,  5350,  5356,  5362,
    5368,  5374,  5385,  5396,  5407,  5418,  5424,  5430,  5436,  5442,
    5452,  5462,  5472,  5484,  5497,  5509,  5513,  5517,  5521,  5525,
    5543,  5561,  5569,  5577,  5606,  5616,  5635,  5640,  5644,  5648,
    5660,  5664,  5676,  5693,  5703,  5707,  5722,  5727,  5734,  5738,
    5751,  5765,  5779,  5793,  5807,  5828,  5836,  5842,  5848,  5854,
    5863,  5867,  5871,  5879,  5885,  5891,  5899,  5907,  5914,  5922,
    5937,  5951,  5965,  5977,  5993,  6002,  6011,  6021,  6032,  6040,
    6048,  6052,  6071,  6078,  6084,  6091,  6099,  6098,  6108,  6122,
    6124,  6129,  6134,  6142,  6151,  6164,  6167,  6171
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
  "tFillet", "tChamfer", "tPlane", "tRuled", "tTransfinite", "tPhysical",
  "tCompound", "tPeriodic", "tUsing", "tPlugin", "tDegenerated",
  "tRecursive", "tRotate", "tTranslate", "tSymmetry", "tDilate",
  "tExtrude", "tLevelset", "tAffine", "tBooleanUnion",
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
  "Command", "Slide", "Loop", "Extrude", "@10", "@11", "@12", "@13",
  "ExtrudeParameters", "ExtrudeParameter", "BooleanOperator",
  "BooleanOption", "Boolean", "BooleanShape", "TransfiniteType",
  "TransfiniteArrangement", "TransfiniteCorners", "RecombineAngle",
  "PeriodicTransform", "Constraints", "Coherence", "HomologyCommand",
  "Homology", "FExpr", "FExpr_Single", "@14", "DefineStruct", "@15",
  "Struct_FullName", "tSTRING_Member_Float",
  "Option_SaveStructNameInConstant", "VExpr", "VExpr_Single",
  "RecursiveListOfListOfDouble", "ListOfDouble", "ListOfDoubleOrAll",
  "FExpr_Multi", "RecursiveListOfDouble", "ColorExpr", "ListOfColor",
  "RecursiveListOfColor", "StringExprVar", "StringExpr", "@16",
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
     240,   240,   240,   240,   240,   240,   241,   241,   242,   242,
     242,   242,   242,   242,   243,   243,   243,   243,   244,   244,
     244,   244,   244,   244,   245,   245,   246,   246,   248,   249,
     247,   250,   250,   252,   251,   253,   253,   255,   254,   256,
     256,   258,   257,   259,   259,   259,   259,   259,   260,   260,
     261,   261,   262,   262,   263,   263,   263,   263,   263,   263,
     263,   263,   263,   263,   263,   263,   263,   263,   263,   263,
     263,   263,   263,   263,   263,   263,   263,   263,   263,   263,
     263,   263,   263,   263,   263,   263,   263,   263,   263,   263,
     263,   263,   263,   263,   263,   263,   263,   263,   263,   263,
     263,   263,   263,   263,   263,   263,   264,   264,   265,   265,
     265,   266,   265,   267,   265,   268,   265,   265,   269,   265,
     270,   270,   271,   271,   271,   272,   272,   273,   273,   273,
     274,   274,   275,   275,   275,   275,   276,   276,   276,   277,
     277,   277,   278,   278,   278,   279,   279,   279,   280,   280,
     281,   281,   282,   282,   282,   282,   282,   282,   282,   282,
     282,   282,   282,   282,   282,   282,   282,   282,   282,   282,
     282,   282,   282,   282,   282,   282,   282,   282,   282,   282,
     282,   282,   282,   282,   282,   282,   282,   282,   282,   282,
     283,   283,   283,   283,   283,   283,   283,   283,   284,   284,
     285,   285,   285,   285,   285,   285,   286,   286,   286,   286,
     286,   286,   286,   286,   286,   286,   286,   286,   287,   287,
     287,   287,   287,   288,   288,   289,   290,   290,   290,   290,
     290,   290,   291,   291,   291,   291,   291,   291,   291,   291,
     291,   291,   291,   291,   291,   291,   291,   291,   291,   291,
     291,   292,   293,   293,   293,   293,   293,   293,   293,   293,
     293,   293,   293,   293,   293,   293,   294,   294,   294,   295,
     294,   296,   294,   297,   294,   298,   294,   294,   294,   294,
     294,   299,   299,   300,   300,   300,   300,   300,   300,   300,
     300,   300,   300,   300,   301,   301,   301,   301,   301,   302,
     302,   302,   303,   303,   304,   305,   305,   306,   306,   307,
     307,   308,   308,   309,   309,   310,   310,   310,   310,   310,
     310,   310,   310,   310,   310,   310,   310,   310,   310,   310,
     310,   310,   310,   310,   310,   310,   310,   310,   310,   310,
     310,   310,   310,   310,   310,   311,   311,   311,   312,   312,
     312,   313,   313,   313,   313,   314,   314,   314,   314,   314,
     314,   314,   314,   314,   314,   314,   314,   314,   314,   314,
     314,   314,   314,   314,   314,   314,   314,   314,   314,   314,
     314,   314,   314,   314,   314,   314,   314,   314,   314,   314,
     314,   314,   314,   314,   314,   314,   314,   315,   315,   315,
     315,   315,   315,   315,   315,   315,   315,   315,   316,   315,
     315,   315,   315,   315,   315,   315,   315,   315,   315,   315,
     315,   315,   315,   315,   315,   315,   315,   315,   315,   315,
     315,   315,   315,   315,   315,   315,   318,   317,   319,   319,
     320,   321,   321,   322,   322,   322,   322,   322,   323,   323,
     323,   323,   324,   324,   325,   325,   325,   325,   325,   325,
     326,   326,   327,   327,   327,   327,   327,   327,   327,   327,
     327,   327,   327,   327,   327,   327,   327,   327,   327,   327,
     327,   327,   327,   327,   327,   327,   327,   327,   327,   327,
     327,   327,   327,   327,   327,   327,   328,   328,   328,   328,
     329,   329,   329,   329,   330,   330,   331,   331,   332,   332,
     332,   332,   332,   332,   332,   332,   332,   332,   332,   332,
     333,   333,   333,   333,   333,   333,   333,   333,   333,   333,
     333,   333,   333,   333,   333,   333,   333,   333,   333,   333,
     333,   333,   333,   333,   333,   333,   334,   333,   333,   335,
     335,   336,   336,   337,   337,   338,   338,   338
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
      12,     8,     7,     7,     8,     8,     8,     8,     8,     8,
       5,    11,     5,     9,     9,     4,     9,     9,     1,     1,
       0,     2,     6,     6,     6,     6,     8,    10,    14,    16,
      12,    14,    14,    14,    14,     8,     8,     6,     4,     6,
       6,     3,     4,     5,     6,     5,     3,     3,     4,     5,
       4,     5,     3,     5,     7,     7,     3,     7,     3,     2,
       2,     2,     2,     2,    15,     2,     2,     2,     2,     2,
      16,    11,     6,     8,     8,    10,     1,     2,     2,     1,
       3,     3,     4,     4,     1,     1,     5,    11,    13,     0,
       7,     0,    13,     0,    15,     0,     6,     9,     2,     3,
      10,     1,     2,     5,     7,     2,     2,     3,     2,     3,
       2,     3,     9,     6,     1,     1,     1,     1,     1,     0,
       2,     3,     9,     4,    14,     0,     3,     0,     1,     0,
       2,     0,     2,     0,     2,     6,     7,     6,     5,     3,
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
       2,     3,     3,     3,     3,    16,    16,    16,    16,     1,
       1,     1,     3,     3,     4,     4,     4,     6,     6,     6,
       6,     8,     8,     4,    14,     4,     1,     1,     3,     3,
       9,     7,     1,     5,     3,     6,     1,     3,     1,     1,
       4,     4,     4,     4,     3,     6,     5,     5,     5,     5,
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
       0,     0,     0,     2,     3,     1,   575,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   314,   315,   316,   317,   318,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   276,
       0,     0,   284,   285,     0,     0,     0,   279,     0,     0,
       0,     0,     0,   368,   369,   370,     0,     0,     5,     6,
       7,     8,    10,    11,    24,    12,    13,    14,    15,    23,
      22,    21,    16,     0,    17,    18,    19,    20,     0,    25,
       0,   576,     0,   417,   575,   540,   418,   420,   421,   419,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     542,     0,   563,   544,   425,   426,   427,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   422,
     423,   424,   543,     0,     0,     0,     0,    70,    71,     0,
       0,   220,     0,     0,     0,   375,   430,     0,   528,   576,
     433,     0,     0,     0,     0,   263,     0,   265,   266,   261,
     262,     0,   267,   268,   128,   140,   575,   456,   576,   458,
      70,    71,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   269,     0,
       0,     0,     0,     0,   575,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   499,   500,     0,   501,   474,   298,   475,   576,   433,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   463,     0,
       0,   220,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   575,     0,   220,     0,
       0,   365,     0,     0,     0,     0,     0,     0,     0,     0,
     481,     0,   480,     0,     0,     0,     0,     0,   575,     0,
       0,   522,     0,     0,     0,     0,   259,   260,     0,     0,
       0,     0,   277,   278,     0,   220,     0,   220,   575,     0,
     576,     0,     0,   220,   371,     0,     0,    76,    70,    71,
       0,     0,    63,    67,    66,    65,    64,    69,    68,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   378,   377,   379,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   219,     0,   218,     0,     0,   256,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    38,   252,     0,     0,     0,   441,
     186,     0,   575,     0,   528,   576,   529,     0,     0,   571,
       0,   126,   126,   461,     0,     0,     0,     0,     0,   516,
     517,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    70,
      71,     0,     0,     0,     0,     0,     0,     0,   487,     0,
       0,   488,     0,   489,     0,   490,     0,     0,     0,     0,
       0,     0,     0,     0,   377,   482,     0,   476,     0,     0,
       0,    70,    71,     0,     0,     0,     0,     0,     0,     0,
     299,     0,   329,   329,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     220,   220,     0,   465,   464,     0,     0,     0,     0,   220,
     220,     0,     0,     0,     0,   295,     0,   220,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   331,     0,
       0,     0,     0,     0,     0,     0,   241,   366,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   339,   258,     0,
       0,     0,     0,     0,   220,     0,     0,     0,     0,     0,
     281,   280,     0,   246,     0,   247,     0,     0,     0,   220,
       0,     0,     0,     0,   319,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    80,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     428,     0,     0,     0,   566,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    63,    64,
       0,   376,    63,    64,     0,     0,    63,     0,     0,     0,
       0,     0,   215,     0,     0,     0,     0,     0,     0,     0,
     221,     0,     0,     0,   393,   392,   391,   390,   386,   387,
     389,   388,   381,   380,   382,   383,   384,   385,     0,     0,
       0,   460,   446,   187,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   127,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   323,     0,     0,     0,
       0,     0,     0,   358,   359,   360,     0,     0,     0,    72,
      73,     0,   502,     0,     0,     0,     0,     0,   433,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   491,   492,
     493,   494,     0,     0,   376,   477,   484,     0,   382,   483,
       0,     0,     0,   503,   446,     0,     0,     0,     0,     0,
       0,     0,   327,     0,     0,   156,   157,     0,   159,   160,
       0,   162,   163,     0,   165,   166,     0,   362,     0,   363,
       0,   364,     0,     0,     0,     0,   361,   220,     0,     0,
       0,     0,     0,   467,   466,     0,     0,     0,     0,     0,
       0,     0,   289,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   342,     0,     0,   242,     0,
       0,   238,     0,     0,     0,   357,   356,     0,     0,     0,
     376,     0,     0,     0,     0,     0,     0,     0,     0,   282,
     283,     0,     0,   248,   250,     0,   577,     0,     0,     0,
       0,     0,     0,    63,    64,     0,     0,    63,    64,     0,
       0,     0,     0,    95,    79,     0,   435,   434,   395,   396,
     397,   398,   399,   400,   401,   402,   403,   416,   404,     0,
     406,   407,   408,   409,   410,   411,   412,     0,     0,     0,
     553,     0,   560,   549,   550,   551,     0,   565,   564,     0,
     453,     0,     0,     0,     0,   554,   555,   556,   455,   562,
     145,   569,   568,     0,   150,     0,     0,     0,     0,   118,
       0,     0,   545,     0,   547,     0,   431,   438,   439,   541,
       0,     0,     0,    63,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   112,     0,     0,     0,     0,   440,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   573,
       0,     0,    48,     0,     0,     0,    61,     0,    39,    40,
      41,    42,    43,   437,   436,   448,     0,     0,    28,    26,
       0,     0,     0,     0,   534,    29,     0,     0,   253,   572,
      74,   129,    75,   141,     0,     0,   459,     0,     0,     0,
     518,   519,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     9,   435,   434,     0,     0,
     506,     0,   505,   504,     0,     0,   513,     0,     0,   486,
       0,     0,     0,   515,   478,     0,     0,     0,   437,   436,
       0,     0,     0,     0,     0,   376,   325,   330,   328,     0,
     338,     0,     0,     0,     0,     0,     0,     0,     0,   376,
     376,   376,     0,     0,     0,     0,     0,   249,   251,     0,
       0,     0,   210,   212,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   301,     0,   286,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   332,
     341,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   243,     0,     0,     0,
       0,     0,   245,     0,   320,     0,     0,     0,     0,   372,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     574,     0,     0,   443,     0,   442,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   536,   537,   538,   539,     0,     0,     0,     0,     0,
       0,    89,     0,    93,     0,     0,    81,     0,     0,     0,
       0,    85,   108,   110,     0,     0,   526,     0,   116,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   394,
       0,     0,     0,     0,     0,    34,   445,   444,   532,   530,
      27,     0,     0,   533,   531,     0,     0,     0,     0,     0,
     462,   145,     0,     0,     0,     0,     0,   170,   170,     0,
       0,     0,     0,     0,     0,     0,   168,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   335,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   485,   479,     0,     0,     0,     0,     0,     0,
       0,     0,   337,     0,   158,     0,   161,     0,   164,     0,
     167,     0,     0,     0,     0,     0,     0,     0,   244,     0,
       0,     0,     0,     0,     0,     0,   306,     0,     0,   305,
       0,   308,     0,   310,     0,   296,   302,     0,     0,     0,
     237,     0,     0,     0,     0,     0,     0,     0,     0,   343,
       0,   240,   239,   367,     0,     0,    35,    36,     0,     0,
       0,     0,   523,     0,     0,     0,   272,     0,     0,     0,
     220,   321,   220,     0,     0,     0,     0,    90,     0,    94,
       0,     0,    82,     0,    86,     0,   255,   447,   254,   405,
     413,   414,   415,   561,     0,     0,   559,   451,   452,   454,
       0,     0,   429,   146,     0,     0,   567,   151,   450,   546,
     548,   432,     0,     0,     0,    91,     0,     0,     0,    63,
       0,     0,     0,     0,    83,     0,     0,     0,   524,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   472,     0,     0,    30,    31,     0,    32,
       0,     0,   130,   137,     0,     0,     0,    77,    78,   172,
       0,     0,     0,     0,     0,     0,   173,     0,     0,   189,
     190,     0,     0,     0,     0,   174,   202,   191,   195,   196,
     192,   193,   194,   181,     0,     0,   447,   509,   508,   507,
       0,     0,     0,     0,     0,     0,     0,   203,   510,   197,
       0,     0,   168,     0,     0,   336,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   257,     0,     0,     0,
       0,   220,   220,     0,     0,   307,   474,     0,     0,   309,
     311,     0,     0,   290,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   198,     0,     0,     0,     0,   177,
     178,     0,     0,     0,     0,   119,   123,     0,     0,   319,
     319,     0,   373,     0,     0,     0,    92,     0,     0,     0,
      84,     0,   449,     0,     0,     0,     0,   570,     0,     0,
     102,     0,     0,    96,     0,     0,     0,     0,   113,     0,
       0,   114,     0,   527,   222,   223,   224,   225,     0,     0,
       0,     0,     0,     0,    44,     0,     0,     0,     0,     0,
      46,   535,     0,     0,   131,   138,     0,     0,   457,     0,
       0,   171,   175,   176,   182,     0,     0,   201,     0,   184,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   183,     0,   204,   326,   206,   207,   208,   209,   180,
       0,   199,   205,     0,     0,     0,     0,     0,     0,   471,
       0,   470,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   236,   235,     0,     0,     0,     0,     0,     0,     0,
       0,   226,     0,     0,   340,    37,     0,     0,   521,     0,
     274,   273,     0,     0,     0,     0,     0,     0,     0,   103,
       0,     0,    97,     0,     0,     0,   552,   558,   557,     0,
     147,   149,     0,   152,   153,   154,   104,   106,    98,   100,
     109,   111,     0,   117,     0,    87,    49,     0,     0,     0,
     473,     0,     0,     0,    33,     0,   145,   150,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   511,   512,
       0,     0,     0,     0,     0,     0,   185,     0,   333,   333,
       0,   124,   125,   220,     0,   213,   214,   297,     0,   303,
       0,     0,   220,     0,     0,     0,     0,     0,     0,     0,
       0,   217,   216,     0,     0,     0,     0,   120,   121,     0,
       0,   322,     0,   105,   107,    99,   101,    88,     0,   516,
     517,     0,     0,   525,     0,    45,     0,     0,     0,    47,
      62,     0,     0,     0,   135,   133,   351,   353,   352,   354,
       0,   355,   188,     0,     0,     0,     0,     0,     0,   300,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   469,   313,     0,     0,   291,     0,   227,     0,     0,
       0,     0,     0,     0,     0,   520,   275,     0,     0,   220,
     374,     0,   148,     0,     0,   155,   115,     0,     0,     0,
       0,     0,   132,   139,   145,   145,   169,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   334,   344,     0,     0,
     345,     0,   211,     0,   304,     0,   287,     0,   220,     0,
       0,     0,     0,     0,     0,   179,   122,   271,   319,     0,
     142,     0,     0,    53,     0,    59,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   200,     0,   348,     0,
     349,   350,   468,     0,     0,   293,   230,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   136,   134,     0,     0,     0,     0,     0,     0,     0,
       0,   312,   292,   288,     0,     0,     0,     0,     0,     0,
       0,     0,   143,   144,    50,     0,    57,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   231,   232,
     233,   234,     0,   228,   324,     0,    51,     0,     0,   264,
       0,   514,     0,     0,     0,     0,     0,     0,   294,     0,
       0,     0,     0,     0,   270,     0,     0,     0,     0,     0,
       0,   229,    52,    54,     0,    55,     0,   495,   496,   497,
     498,     0,     0,     0,     0,    60,   346,   347,    56,    58
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,   108,  1130,   109,   110,   808,  1733,  1739,
    1118,  1360,  1934,  2125,  1119,  2077,  2154,  1120,  2127,  1121,
    1122,  1364,   409,   509,   213,   872,   111,   828,   521,  1866,
    2005,  2004,  1867,   522,  1928,  1318,  1533,  1320,  1537,   914,
     917,   920,   923,  1603,  1593,   790,   291,   484,   485,   114,
     115,   116,   117,   118,   119,   120,   121,   292,  1248,  2027,
    2094,   950,  1244,  1245,   293,   999,   294,   125,  1431,  1209,
     912,   964,  1964,   126,   127,   128,   129,   295,   215,  1060,
     216,   523,   237,   812,   832,   624,   328,  1572,   362,   363,
     297,   588,   370,  1098,  1347,   519,   514,  1064,   752,   520,
     390,   299
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1676
static const yytype_int16 yypact[] =
{
   11466,    56,    43, 11612, -1676, -1676,  4813,   110,   -55,   -89,
     -78,    49,   210,   230,   235,   271,   -21,   290,   326,   121,
     129,    23,   405,   405,  -147,   139,   168,    24,   176,   225,
      26,   239,   286,   294,   335,   346,   365,   378,   387,   413,
     420,   270,   393,   385,   320,   394,   451,  6418,   457,   462,
     529,   -39,   104,   676,   617,     1,   481,   648,   -20,   506,
    -126,  -126,   539,   -71,    25, -1676, -1676, -1676, -1676, -1676,
     556,   654,   694,   674,    15,    69,   719,   725,   469,   816,
     819,   828,  5966,   849,   565,   666,   669,    20,    61, -1676,
     683,   687, -1676, -1676,   859,   918,   712, -1676,  5156,   702,
    4125,    40,    46, -1676, -1676, -1676, 10837,   762, -1676, -1676,
   -1676, -1676, -1676, -1676, -1676, -1676, -1676, -1676, -1676, -1676,
   -1676, -1676, -1676,   -15, -1676, -1676, -1676, -1676,    11, -1676,
     926,   158,   283, -1676,    19, -1676, -1676, -1676, -1676, -1676,
     405,   405,   405,   405,   405,   405,   405,   405,   405,   405,
     405,   405,   405,   405,   405,   405,   405,   405,   405,   405,
     405,   405,   405,   405,   405,   721,   754,   765,   405,   405,
     405,   405,   768,   405,   405,   405,   405,   405,   405,   773,
   -1676,   405, -1676, -1676, -1676, -1676, -1676,   405,   405,   405,
     696,   945,   777,   785,   786,   405,   405,   797,   810, -1676,
   -1676, -1676, -1676,   774, 10837, 10837, 10837,  9958, 10178,    35,
      23,   327,   794,   818,   329, -1676, -1676,   842,  1040,   241,
      89,  1047, 10837,  3958,  3958, -1676, 10837, -1676, -1676, -1676,
   -1676,  3958, -1676, -1676, -1676, -1676,   841, -1676,   845,  1081,
   -1676, -1676,  3735,    23, 10837,  9663, 10837, 10837,   865, 10837,
    9663, 10837, 10837,   869, 10837,  9663, 10837, 10837, 10837, 10837,
   10837, 10837,  3958, 10837, 10837, 10837,  6644,   875, -1676,  9663,
    5966,  5966,  5966,  3958,   -12,   494,   405,   405,   405,   405,
      28,    29,    30,    31,  6644,  1001,   770,   405,  6870, 10837,
    5281, -1676, -1676,   883, -1676,  2624, -1676, -1676,   297,   -74,
   10837,  9663,   899,   921,  7096,  5966,  5966,  5966,   927,   949,
     970,   981,  7322,  7548,  7774,   987,  4411,  1215,  6644,    20,
     992,   993,  -126,  -126,  -126, 10837, 10837,  -101, -1676,   -57,
    -126,  4702,   -46,     0,  1002,  1006,  1007,  1009,  1010,  1011,
    1015, 10837,  5966,  5966,  5966,  1017,    21,   999, -1676,  1239,
    1240, -1676,  1016,  1018,  1019,  5966,  5966,  1020,  1022,  1025,
   -1676, 10837, -1676,  1266,  1268, 10837, 10837, 10837,   -53, 10837,
    1041, -1676,  1105, 10837, 10837, 10837, -1676, -1676, 10837,  1271,
    1272,  1046, -1676, -1676,  1273, -1676,  1275, -1676,   416,  4587,
     417,  3958, 10837, -1676, -1676,  6644,  6644, -1676, 10251, 10471,
    1048,  1049,  3735, -1676, -1676, -1676, -1676, -1676, -1676,  6644,
    1280,  1058, 10837, 10837, 10837, 10837, 10837, 10837, 10837, 10837,
   10837, 10837, 10837, 10837, 10837, 10837, 10837, 10837, 10837, 10837,
   10837, 10837, 10837, 10837, 10837, 10837,  3958,  3958,  3958,  3958,
    3958,  3958,  3958,  3958,  3958,  3958,  6644,  3958,  3958, 10837,
    3958,  3958,  3958,  3958,  3958, 10837,    73,  3735,  1054,  1055,
    1056,  1057, 10837,  3958,  3958,  3958,  3958,  3958,    23,  3735,
      23,  1066,  1066,  1066,   123,  2690,   138, 12777,   364,  1062,
    1287,   405,  1061, -1676,  1063, 11748, 10837,  9663, -1676, 10837,
   10837, 10837, 10837, 10837, 10837, 10837, 10837, 10837, 10837, 10837,
   10837, 10837, 10837, 10837, -1676, -1676, 10837, 10837,  1293, -1676,
   -1676,   846,   476,    91, -1676,   524,  1068,   144, 10496, -1676,
     357,   392,   453,  1067,  1292,  1072,  1073, 13168,  9663,  2712,
   -1676,   489, 13189, 13210, 10837, 13231,   517, 13252, 13273, 10837,
   13294,   576, 13315, 13336, 13357, 13378, 13399, 13420,  1079, 13441,
   13462, 13483,  1302, 10837,   650,  1304,  1305,  1306,  1085, 10837,
   10837,   -91,  8000,  8226, 10837, 10837,  3958, 10837, -1676,  1252,
   10837, -1676,  1253, -1676,  1254, -1676,  1255,  6644,  5966,  5966,
    5966,  5966,  9663,  9663,  1066, -1676, 13504, -1676,   671, 10837,
    8452, 10837, 10837,   171,  1293, 13525,   672, 10837, 10837, 10837,
   -1676,  1311,  1312,  1312,  9883,  9883,  9883,  9883, 10837,  1314,
   10837,  1316, 10837,  1318,  9663,  9663, 10204,  1097,  1322,  1095,
   -1676, -1676,  -157, -1676, -1676, 10595, 10668,  -126,  -126,   327,
     327,  -104,  4702,  4702, 10837,   876,   -44, -1676, 10837, 10837,
   10837, 10837, 10837, 10837, 10837, 10837, 10837, 13546,  1323,  1328,
    1329, 10837,  1332, 10837, 10837,  1392, -1676, -1676,  9663,  9663,
    9663,  1333,  1334, 10837, 10837, 10837, 13567, -1676, -1676, 13588,
   13609, 13630,  1167, 10711, -1676,  1108,  3012, 13651, 13672, 12800,
   -1676, -1676,  9663, -1676,  2710, -1676,  2979, 10837, 10837, -1676,
   10837, 10837,  1116, 13693,  9465,  1119,   682,   163, 13714,   218,
   12823, 10837,  9663,  1342,  1343, -1676, 10837, 13735, 12846, 12754,
   12754, 12754, 12754, 12754, 12754, 12754, 12754, 12754, 12754, 12754,
   10791, 12754, 12754, 12754, 12754, 12754, 12754, 12754, 10960, 10986,
   11148,  -123,   199,  -123,  1122,  1123,  1124,   681,   681,  1125,
     681,  1126,  1128,  1130, 11272,   681,   681,   681,   536,   681,
   14470, 10837,   681,  1347, -1676, 10837, 10837, 10837, 10837,   920,
    1133,  1136,  1142,   585,   596,  1143,  1144,  1145,  1330,  1337,
    6644,   391,  1338,  1339,  6644,   155,  3735, 10837,  1350,  1369,
      27,   681, -1676,    52,    37,    38,   173,  1149,   -35,   744,
   -1676,  3296,   685,  3040,   629,  1045,   661,   661,   310,   310,
     310,   310,   -34,   -34,  1066,  1066,  1066,  1066,     8, 13756,
   12869, -1676,   112, -1676, 10837, 10837,    16,  9663, 10837, 10837,
    1293,  1371,  9663, 10837,  1372,  3958,  1378, -1676,    23,  1379,
    3958,    23,  1158,    23, 10837,  3735,  1384,  9663,  9663,  1222,
    1387,  1388, 13777,  1390,  1227,  1393,  1394, 13798,  1399,  1232,
    1400,  1401,  1402,  1404,  1405,  1406, -1676,  1407,  1408,  1409,
   10837, 13819,  1183, -1676, -1676, -1676,  1412, 13840, 12892, -1676,
   -1676,  9663, -1676,  9663,  2712,  1191,  9663,  1190,   495, 11305,
   11662,   681, 11688,  1188,  4450,  1193,  1194,  1195, -1676, -1676,
   -1676, -1676,   681,   686,  1424, -1676,  3144,  9663,  1066, -1676,
   13861, 12915,  9663, -1676,   426,  1426,  1201, 13882, 13903, 13924,
   10837,  6644,  1433,  1450,  1229, 14470,  1225,  1234, 14470,  1228,
    1235, 14470,  1231,  1237, 14470,  1236, 13945, -1676, 13966, -1676,
   13987, -1676,   692,   695,  9663,  1241, -1676, -1676,  3364, 10985,
    -126, 10837, 10837, -1676, -1676,  1238,  1256,  4702, 10375,  1344,
     -14,  -126, 11025, 14008,  4732, 14029, 14050, 14071, 14092, 14113,
   14134, 14155,  1453, 10837,  1462, -1676, 10837, 14176, -1676, 12938,
   12961, -1676,   700,   703,   704, -1676, -1676, 12984, 13007, 11714,
   -1676,  1464,  1468,  1469,  1261, 10837, 11141, 10837, 10837, -1676,
   -1676,    51,   707, -1676, -1676, 11179, -1676,  1486, 10544,  1262,
    1264,  6644,  1494,  1460,  1470,  6644,   391,  1471,  1472,  6644,
     391,  4760,   711, -1676, -1676, 13030,   149,  1165, -1676, -1676,
   -1676, -1676, -1676, -1676, -1676, -1676, -1676, -1676, -1676, 10837,
   -1676, -1676, -1676, -1676, -1676, -1676, -1676, 10837, 10837, 10837,
   -1676,  9663, -1676, -1676, -1676, -1676,  3958, -1676, -1676, 10837,
   -1676,  6644,  3958,  3958,  3958, -1676, -1676, -1676, -1676, -1676,
   -1676, 14470, -1676,  1509, -1676,  5219,  5452,  5678,  5904, -1676,
   10837,  3958, -1676,  3958, -1676, 10837, -1676, -1676, -1676, -1676,
     405,   405,  1512, -1676, 10837,  1513,   405,   405,  1514,   124,
   10837,  1517,  1518,   969, -1676,  1519,  1296,    20,  1522, -1676,
    9663,  9663,  9663,  9663, 10837,  1303,  1325,  1335,  1336, -1676,
     681, 10837, -1676,  1340,  1341,  1295, -1676,  1526, -1676, -1676,
   -1676, -1676, -1676,   275,   359, -1676, 14197, 13053, -1676,  1345,
    3958,   544, 14218, 13076, -1676, -1676,   638, 11740, -1676, -1676,
   -1676,    62, -1676, -1676,  1315, 10837, -1676, 12754,   681,  -126,
    2712, -1676,   853,  6644,  6644,  1542,  6644,   857,  6644,  6644,
    1553,  6644,  1467,  6644,  6644,  6644,  6644,  6644,  6644,  6644,
    6644,  6644,  1327,  1557,  9663, -1676,   426,    75,   720,   723,
   -1676,   724, -1676, -1676, 10837, 10837, -1676, 10837, 10837, -1676,
   10837, 10837, 10837, -1676, -1676,  6644, 10837,   749,   426,   426,
     752,  6644,  9663,  1559,  1562,  1563,  2358, -1676, -1676,  1565,
   -1676,   288, 10837,   288, 10837,   288, 10837,   288, 10837,  1566,
    1567,  1569,  1570,  1572,   753,  1568, 11234, -1676, -1676,   -42,
   11766, 11792, -1676, -1676,  6130,  -150,  1476,  1577, 10764,  1348,
    1578,  1358,    34,    53,   -51, -1676,   -38, -1676,   -14,  1579,
    1581,  1582,  1583,  1584,  1585,  1586,  1587,  1589,  6644, 14470,
   -1676,  1396,  1354,  1591,  1592,  1593,  1508,  1594,  1596,  1612,
   10837,  6644,  6644,  6644,  1615, 11818, -1676,  3461,   200,  1619,
    1620,  1395, -1676,  1397, -1676,  1505,  1398,  6644,  1403, -1676,
     405,   405,  1623, 10837,  1624,   405,   405,  1627, 10837,  1628,
   -1676,   681,  1630, -1676,  1633, -1676,  1636, 12754, 12754, 12754,
   12754,   630,  1410, 10418,  1411,   681,   681,  1413,   639,  1415,
     662, -1676, -1676, -1676, -1676, 14239,  1416,   681, 12754,  1870,
    3958, -1676,  1527, -1676,  1870,  3958, -1676,   395,  1414,  1641,
    1552, -1676, -1676, -1676,    20, 10837, -1676,   766, -1676,   772,
     775,   776,   783, 14260, 10837, 10837, 10837, 10837,   288, 14470,
    1425, 10837, 10837,  6644,  1419, -1676, -1676, -1676, -1676,  1423,
   -1676,  1649,    64, -1676, -1676,  1650, 10837,  9130,  1429,  1428,
   -1676, 14470,  1653,  1654,    14,  1427,  1430,  1545,  1545,  6644,
    1659,  1432,  1434,  1661,  1670,  6644,  1506,  1445,  1674,  1675,
    1676,  1677,  1678,  1679,  1680,  1681,  1685, -1676,  1687,   784,
    1689,   681,  1466,  1465, 11844, 11870, 11896, 11922, 11948, 11974,
   12000,  1690, 14470, -1676,   681,  1691,   787,  6644,  6644,  6644,
    1695,  1694, -1676,  6644, 14470,  6644, 14470,  6644, 14470,  6644,
   14470,  6644,  6644,  6644,  1473,  1475,  1697,   894, -1676, 10837,
   10837, 10837,  1478,  1493,  1496,  1477, -1676,  1789,  6644, -1676,
   10837, -1676,  1696, -1676,  1699, -1676, -1676,  4702,     4,  6192,
   -1676,  1498,  1499,  1515,  1516,  1520,  1521,  8678,  1722, -1676,
    9663, -1676, -1676, -1676,  1523, 10837, -1676, -1676, 13099,  1745,
    1746,  1534, -1676, 10837, 10837, 10837, -1676,  1750,   954,  3735,
   -1676, -1676, -1676,  1525,  1769,  1870,  3958, -1676,  1895, -1676,
    1870,  3958, -1676,  1971, -1676,   288, -1676,   379, -1676, -1676,
   -1676, -1676, -1676, -1676,  3958, 10837, -1676, -1676, -1676, -1676,
    3958,  1772, -1676, -1676, 10837,    22, -1676, -1676, -1676, -1676,
   -1676, -1676,  1771,  -123,  -123, -1676,  1773,  -123,  -123,  3735,
   10837,  1775,  1778,    27, -1676,  1777, 13122,    20, -1676,  1779,
    1780,  1781,  1782,  1424, 14281, 14302, 14323, 14344,  6644, 10837,
   12026, 12052,   788, -1676, 10837,  1785, -1676, -1676,  3958, -1676,
   12078,  5514, 14470, -1676,  1783,  1784,   477, -1676, -1676, -1676,
   10837, 10837,  -126,  1786,  1787,  1792, -1676, 10837, 10837, -1676,
   -1676,  1793,  1710,  1797, 10837, -1676, -1676, -1676, -1676, -1676,
   -1676, -1676, -1676, -1676,  1799,  1550,   426, -1676, -1676, -1676,
   10837, 10837, 10837, 10837, 10837, 10837, 10837, -1676, -1676, -1676,
    1571,  1801,  1506,  1802, 10837, -1676,  1803,  1804,  1805,  1806,
    1807,  1021,  1808,  9663,  9663, 10837, -1676,  9883,  6356, 14365,
    2252,   327,   327, 10837, 10837, -1676,   450,  1590, 14386, -1676,
   -1676,  6582,   -36, -1676,  1810,  1811,  6644,  -126,  -126,  -126,
    -126,  -126,  5054,  1812, -1676,   800, 10837,  2014,  1814, -1676,
   -1676,  6644,  3632,   586, 14407, -1676, -1676,  9211,  1597,  9465,
    9465,  6644, -1676,  1816,  -123,  -123, -1676,  1818,  -123,  -123,
   -1676,  6644, -1676,  1598, 12754,   681,  5740, 14470,  9437,  3735,
   -1676,  1819,  1823, -1676,  1825,  1826,  1827,  2043, -1676,  1828,
    1831, -1676,  1603, -1676, -1676, -1676, -1676, -1676,  1563,  1566,
    1567,  1569,  1832,   658, 14470, 10837, 10837,  6644,  1606,   801,
   14470, -1676,  1835, 10837, -1676, -1676,  1608,  1609, -1676,  6808,
    7034,   759, -1676, -1676, -1676,  7260,  7486, -1676,  1610, -1676,
    7712,  1840,  6644, 12754, 12754, 12104, 12130, 12156, 12182, 12208,
   10837, -1676,  1841, -1676, 14470, -1676, -1676, -1676, -1676, -1676,
    1616, -1676, -1676,   809,   812, 10302,  2083,  1845,  1618, -1676,
   10837, -1676,  1611,  1621,  7938, 13145,  1847,  6644,  1848,  1625,
   10837, -1676, -1676,   836,    -4,   131,   164,   213,   258,  8904,
     264, -1676,  1851,  8164, -1676, -1676,  1688, 10837, -1676, 10837,
   -1676, -1676,  9663,  2408,  1854,  3735,  1626,  1629,  1632, -1676,
    1856,  1857, -1676,  1862,  1864,  1865, -1676, -1676, -1676,  5281,
   -1676, -1676,  3958, 14470, -1676, -1676, -1676, -1676, -1676, -1676,
   -1676, -1676,    20, -1676,  1703, -1676, -1676, 10837, 12234, 12260,
   -1676,  6644, 10837,  1867, -1676, 12286, -1676, -1676,  6644,  6644,
    1871,  1872,  1873,  1874, 10837,  1875,  1876,   851, -1676, -1676,
   10837, 10837, 10837, 10837, 10837,  8390, -1676,  6644,   521,   547,
    9663, -1676, -1676,   327,  4292, -1676, -1676, -1676,  1877, -1676,
    1651,  6644, -1676,  8616,  1879,  9663,  -126,  -126,  -126,  -126,
    -126, -1676, -1676, 10837,  8842,  9087,   852, -1676, -1676,  1648,
    1655, -1676,  1882, -1676, -1676, -1676, -1676, -1676,   855,  1233,
    1883,   860,  1885, -1676,  1660, 14470, 10837, 10837,   868, 14470,
   -1676, 10837,   873,   874, -1676, -1676, -1676, -1676, -1676, -1676,
    9157, -1676, -1676,  1662, 12312, 12338, 12364, 12390, 12416, -1676,
     877,  1663,  -126,  6644,  1887,  1665,  -126,  1889,   880,  1668,
   10837, -1676, -1676,  1894,  1800, 11298,  1671, -1676,   885,   285,
     299,   302,   334,   339,  2451, -1676, -1676,  1898,  1900, -1676,
   -1676, 10837, -1676,  3735,    23, -1676, -1676, 10837, 14428, 12442,
      50, 12468, -1676, -1676, -1676, -1676, -1676, 10837, 10837, 10837,
   10837, 10837, 10837,  1901,  -126,    90, -1676, -1676,  -126,   100,
   -1676,  1902, -1676,  9313, -1676, 10837, -1676,   -14, -1676,  1918,
    9663,  9663,  9663,  9663,  8904, -1676, -1676, -1676,  9465,  2208,
   -1676,  1698,   890, -1676, 10837, -1676,  6644, 10837,   909,   910,
   12494, 12520, 12546, 12572, 12598, 12624, -1676,   348, -1676,   400,
   -1676, -1676, -1676,  2470,   356, 11337, -1676,   914,   924,   939,
     940,   406,   958,  1704,  3735,  1705,  1920,  1700, 14449,   961,
    9379, -1676, -1676, 10837, 10837, 10837, 10837, 10837, 10837,  -126,
    -126, -1676, -1676, -1676,   -14,  1925,  1926,  1932,  1935,  9663,
    1936,  1937, -1676, -1676, -1676,  3958, -1676,  1711,  1938,  9601,
   12754, 12650, 12676, 12702, 12728,   409,   455,   626, -1676, -1676,
   -1676, -1676,   967, -1676, -1676,   971, -1676,  1712,  6644, -1676,
    1941, -1676, 10837, 10837, 10837, 10837, 10837, 10837, -1676,  1942,
    3958,  1943,  3958,   972, -1676,  9789,  9832,  9908, 10009, 10082,
   10125, -1676, -1676, -1676,   985, -1676,  1944, -1676, -1676, -1676,
   -1676,  1945,  1948,  3958,  1950, -1676, -1676, -1676, -1676, -1676
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1676, -1676, -1676, -1676,   587, -1676, -1676, -1676, -1676,   -40,
   -1676, -1676, -1676, -1676, -1676, -1676, -1676, -1676, -1676, -1676,
   -1676, -1676,  -424,   -94,  4090,  2989, -1676,  1436, -1676, -1676,
   -1676, -1676, -1676, -1676, -1676, -1368, -1676,    94, -1676, -1676,
   -1676, -1676, -1676,   330,   575,  1961,    -1,  -620,  -299, -1676,
   -1676, -1676, -1676, -1676, -1676, -1676, -1676,  1963, -1676, -1676,
   -1676, -1676, -1243, -1233,  1964, -1675,  1965, -1676, -1676, -1676,
    1367, -1676,    82, -1676, -1676, -1676, -1676,  1949, -1676, -1676,
    1969, -1676, -1676,  -587, -1676,     3, -1676, -1650,  2893,  -224,
    2448,  2713,  -318,   421, -1676,   250,     2, -1676, -1676,  -432,
      -3,   291
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -536
static const yytype_int16 yytable[] =
{
     131,   619,   113,   219,   731,  1468,   733,   904,   218,   945,
     946,  1466,  1112,  1586,  1826,  1827,  1803,   394,   238,   346,
    1589,   748,  1128,   411,   368,   652,  1708,   236,   248,   333,
     253,  1096,   635,   568,   571,   573,   575,   222,   410,   478,
    1461,   248,   253,     5,   298,   384,   555,   556,   557,   655,
     770,   386,   774,   303,   777,   225,  2045,   303,  1279,  1463,
     627,   628,     4,   327,   329,   372,   332,   627,   628,  1377,
    1577,   238,  1237,   350,   304,   351,   940,   236,  1105,   298,
     244,   601,   602,   603,   238,  1453,   684,   245,   686,  1238,
     315,   323,   324,   316,   694,   238,  2058,  1239,  1240,  1241,
     379,   325,   383,  1242,  1243,   869,  2060,   870,   326,  1237,
     825,   334,  1877,   627,   628,   335,   627,   628,   648,   649,
     650,   336,   337,   221,   338,   339,  1238,  1237,  1337,   947,
     768,   661,   662,   629,  1239,  1240,  1241,   869,   223,   870,
    1242,  1243,   340,   871,  1238,   772,   323,   324,   319,   224,
     407,   408,  1239,  1240,  1241,   352,   325,   594,  1242,  1243,
     627,   628,  1083,   331,   320,   321,  1113,  1114,  1115,  1116,
    1003,   627,   628,   627,   628,   627,   628,   630,   672,   627,
     628,   627,   628,   212,  1465,   500,   501,   502,   637,   951,
    1462,  1449,   503,   305,   347,  1467,   306,  1800,   307,   569,
     572,   574,   576,   479,   480,  1709,   231,   238,  1495,  1464,
     483,  1938,   392,   627,   628,   559,   227,   560,   107,   393,
     515,   515,   211,   107,   212,  1007,   107,   638,   515,  1905,
    1129,   627,   628,  1134,   639,  1466,   228,  1960,   395,  1663,
     238,   229,   298,  1117,   525,   396,   412,   298,   413,   348,
     653,   249,   298,   254,   369,   212,   217,   212,   250,   515,
     255,  1097,   570,   298,   249,   254,   298,   298,   298,   298,
     515,  1101,  1102,  1005,   385,  1009,   107,   230,  1129,   244,
     387,   298,  1280,   226,  2046,   298,  1100,   298,   373,  1378,
     402,  1379,  1338,  1339,   132,  1083,   232,   220,   298,   407,
     408,   298,   298,   298,   298,   751,  1410,   627,   628,   298,
     298,   298,   239,   407,   408,   298,   238,   627,   628,   816,
     508,   938,   939,  -529,   817,   622,   623,   403,   404,   405,
     769,   482,   233,   631,   636,   488,   407,   408,   952,   298,
     298,   298,   403,   404,   405,   773,  -534,  1084,   627,   628,
     234,  1090,   298,   298,   888,   889,   890,   891,   235,   403,
     404,   405,   406,  2073,  1906,   349,   246,   403,   404,   405,
    1004,   776,   821,   407,   408,   986,   266,   822,   371,   407,
     408,   627,   628,  -532,   778,   398,  1089,   399,   515,   380,
     995,   268,   298,   298,   400,   247,  2079,  1907,  1083,   869,
     257,   870,  1549,   251,   703,   902,   298,  1103,   489,   490,
     491,   492,   493,   494,   495,   496,   497,   498,   499,   500,
     501,   502,   403,   404,   405,  1008,   503,   869,  1496,   870,
     627,   628,  1041,   515,   515,   515,   515,   515,   515,   515,
     515,   515,   515,   298,   515,   515,  1908,   515,   515,   515,
     515,   515,   252,   238,    59,    60,    61,    62,   589,   754,
     515,   515,   515,   515,   515,   238,   256,   238,   506,    73,
     507,   766,    76,   513,   517,   627,   628,   400,  2143,  1237,
     270,   627,   628,   271,   298,   267,   272,   403,   404,   405,
     406,  1909,   403,   404,   405,   406,  1238,  1910,  1942,   407,
     408,   481,   627,   628,  1239,  1240,  1241,   407,   408,  -533,
    1242,  1243,   548,   257,   516,   516,   627,   628,  2030,   627,
     628,   258,   516,   558,   591,   298,   592,   498,   499,   500,
     501,   502,  2031,   400,   526,  2032,   503,   489,   490,   491,
     492,   493,   494,   495,   496,   497,   498,   499,   500,   501,
     502,   627,   628,   516,   269,   503,   627,   628,   355,   298,
     298,   356,   259,   515,   516,   627,   628,  2033,   403,   404,
     405,   406,  2034,   260,   298,   298,   298,   298,   298,   298,
     298,  2089,  1293,   407,   408,   824,  1298,   298,   407,   408,
     825,  2092,   261,  -531,  1819,   403,   404,   405,   406,   403,
     404,   405,   406,   407,   408,   262,   916,   919,   922,   925,
     371,   298,   298,  -535,   263,   407,   408,   627,   628,   407,
     408,   302,   826,   627,   628,   827,   627,   628,   483,   483,
     943,   944,   240,  2090,   241,   623,  2048,  2049,  1226,  2099,
     264,   692,  2136,   687,   690,   688,   691,   265,  1961,  1962,
     407,   408,   212,   400,  1963,   298,   298,   298,   489,   490,
     491,   492,   493,   494,   495,   496,   497,   498,   499,   590,
     501,   502,   627,   628,  1965,  1966,   503,  1085,   273,   298,
    1963,  1091,   516,   829,   300,  1796,   827,   732,  2137,   734,
     735,   736,   737,   738,   739,   740,   301,   742,   743,   298,
     745,   746,   747,   814,   749,   815,   312,  1748,   317,   313,
    1531,   314,   212,   760,   761,   762,   763,   764,  1125,   407,
     408,   562,   838,   563,   839,  1183,   594,   516,   516,   516,
     516,   516,   516,   516,   516,   516,   516,   318,   516,   516,
     322,   516,   516,   516,   516,   516,   342,   753,   343,  1237,
     838,   818,   844,   819,   516,   516,   516,   516,   516,   765,
     400,   767,   308,   345,  1058,   309,  1238,   298,   310,   825,
     311,   298,  1372,   330,  1239,  1240,  1241,   838,  1092,  1346,
    1242,  1243,   458,   341,  2064,   459,   344,  1433,   460,  1435,
     461,  1437,   365,  1439,   489,   490,   491,   492,   493,   494,
     495,   496,   497,   498,   499,   500,   501,   502,   353,   838,
    1125,   849,   503,   869,   298,   870,   881,   354,  1073,   298,
     357,  1820,   515,   358,   869,   238,   870,   515,   238,  1075,
     238,  1466,   359,  1106,   298,   298,  1107,  1148,  1108,   491,
     492,   493,   494,   495,   496,   497,   498,   499,   500,   501,
     502,  2117,   813,   364,   878,   503,   578,   516,   869,   579,
     870,  2138,   580,   838,   581,   376,  1375,   869,   298,   870,
     298,   838,  1531,   298,   494,   495,   496,   497,   498,   499,
     500,   501,   502,   838,  1466,   862,  1856,   503,     7,     8,
     869,  1857,   870,   366,   298,  1535,   367,  1543,  1544,   298,
    1646,  1647,  1547,  1548,   838,   838,   895,   906,   298,   869,
     374,   870,  1294,  1550,   375,  1001,  1299,  1002,   838,   838,
    1110,  1194,  1303,  1305,   377,   838,  1069,  1222,   838,   381,
    1223,   298,   397,   838,  1568,  1265,   838,   838,  1266,  1267,
     838,   378,  1281,  1229,   838,  1385,  1301,  1386,   439,  1391,
    1235,  1392,   462,   838,  1246,  1411,   838,   838,  1412,  1413,
    1686,  1687,   783,    25,    26,   784,    28,    29,   785,    31,
     786,    33,    34,    35,    36,  1343,   627,   628,    38,    39,
      40,   440,   838,    42,  1423,   838,   838,  1424,  1446,   787,
      48,   391,   441,    50,   788,   446,    53,   789,   298,  1557,
     453,  1558,   298,   470,   463,   838,   298,  1559,   838,   838,
    1560,  1561,   464,   465,   515,    70,   838,   838,  1562,  1615,
     838,  1737,  1630,  1738,   468,  1780,  1555,  1781,   486,  1366,
    1367,  1792,  1793,   838,  1862,  1812,  1863,   469,   298,    84,
      85,    86,   838,   515,  1888,   838,   505,  1889,   298,   515,
     515,   515,   487,   510,   489,   490,   491,   492,   493,   494,
     495,   496,   497,   498,   499,   500,   501,   502,   515,  1737,
     515,  1904,   503,  1694,  1695,  1139,   504,   212,  1698,  1699,
    1143,   400,  1303,  1305,  1737,   838,  1953,  1987,  1991,   524,
    1992,  1701,   534,   825,   238,  1995,   539,   298,   298,   298,
     298,  1737,   553,  2000,  1366,  1367,  1531,  1535,  2002,  2003,
    1737,   949,  2013,   838,   577,  2021,   516,   393,   838,  1141,
    2029,   516,  1144,  1862,  1146,  2076,   597,   515,   489,   490,
     491,   492,   493,   494,   495,   496,   497,   498,   499,   500,
     501,   502,  1531,  1531,  2081,  2082,   503,   838,   598,  2095,
     298,   298,  1384,   298,   604,   298,   298,   838,   298,  2096,
     298,   298,   298,   298,   298,   298,   298,   298,   298,   512,
     135,   298,   838,   838,  2097,  2098,   605,   489,   490,   491,
     492,   493,   494,   495,   496,   497,   498,   499,   500,   501,
     502,   838,   298,  2100,  1737,   503,  2107,   606,   298,   298,
     838,  1689,  2139,  1690,  2140,  1737,  2141,  2156,   607,   162,
     163,   164,   165,   166,   167,   168,   169,   170,  2163,   617,
    2164,   614,   175,   176,   177,   178,   620,   621,   654,   640,
     180,   181,   182,   641,   642,   183,   643,   644,   645,  1723,
    1993,   589,   646,  1551,   651,   656,   657,   188,   189,   663,
     658,   664,   659,   660,   665,   298,   492,   493,   494,   495,
     496,   497,   498,   499,   500,   501,   502,  1306,   298,   298,
     298,   503,   667,  1969,   668,   674,   675,   680,   681,   683,
     682,   685,   701,   702,   298,   190,   705,   706,   755,   756,
     757,   758,   503,   779,   780,   211,  1312,   811,   782,   820,
     833,   831,  1315,  1316,  1317,   834,   835,   856,   516,   860,
     863,   864,   865,   866,   883,   885,   886,   887,   910,   911,
     927,  1326,   929,  1327,   931,   935,   515,   515,   936,   937,
     963,   515,   515,  1407,   965,   984,   966,   516,   968,   975,
     976,   238,   987,   516,   516,   516,   996,  1000,  1013,  1014,
    1044,  1045,   193,   194,   195,  1063,  1094,  1046,  1049,  1051,
     298,  1052,   516,  1053,   516,   202,  1070,   203,   107,  1071,
    1072,  1077,  1078,  1095,  1080,  1079,  1104,  1135,  1138,  1583,
    1371,  1081,  1086,  1087,  1140,  1142,   298,  1145,   371,   407,
     408,  1149,   298,  1152,  1153,  1154,  1304,  1156,  1157,  -530,
    1158,  1159,  1479,  1162,     7,     8,  1161,  1163,  1164,  1165,
    1931,  1166,  1167,  1168,  1169,  1170,  1171,  1174,  1175,  1180,
    1182,   516,  1188,  1702,   298,   298,   298,  1190,  1191,  1192,
     298,  1195,   298,  1201,   298,  1202,   298,  1208,   298,   298,
     298,   489,   490,   491,   492,   493,   494,   495,   496,   497,
     498,   499,   837,   501,   502,   298,  1210,  1211,  1212,   503,
    1258,  1214,  1213,  1215,  1216,  1217,   298,  1236,  1260,  1218,
    1662,  1271,  1225,  1232,   298,  1272,  1273,   298,   783,    25,
      26,   784,    28,    29,   785,    31,   786,    33,    34,    35,
      36,  1233,  1274,  1283,    38,    39,    40,  1286,  1287,    42,
    1289,  1688,   515,   515,  1290,   787,    48,   515,   515,    50,
     788,  1501,    53,   789,  1291,  1295,  1296,  1319,  1331,  1333,
    1336,   515,  1702,  1341,  1342,  1345,  1344,   515,  1348,  1363,
    1354,    70,  1365,  1545,  1932,   489,   490,   491,   492,   493,
     494,   495,   496,   497,   498,   499,   500,   501,   502,  1389,
    1380,  1716,  1355,   503,   238,    84,    85,    86,  1554,  1370,
    1395,  1397,  1356,  1357,  1408,   298,  1427,  1361,  1362,  1428,
    1429,  1432,  1447,  1441,  1442,   515,  1443,  1444,   298,  1445,
    1454,  1455,  1458,  1745,  1459,  1460,  1469,  1470,  1480,  1471,
    1472,  1473,  1474,  1475,  1476,  1751,  1477,  1481,  1482,  1483,
    1484,  1485,  1486,  1975,   489,   490,   491,   492,   493,   494,
     495,   496,   497,   498,   499,   500,   501,   502,  1487,  1492,
     516,   516,   503,  1497,  1498,   516,   516,   971,  1499,  1507,
    1509,  1500,  1502,  1512,  1514,   371,  1516,  1517,  1504,  1527,
     298,   298,  1518,  1524,  1539,  1552,  1530,  1534,  1553,  1787,
     483,   483,  1569,  1574,  1575,  1576,  1579,  1584,  1585,  1587,
    1588,  1590,  1592,   298,  1591,  1596,  1597,  1599,  1598,   298,
    1804,  1805,  1806,  1807,  1808,  1810,  1600,  1602,   298,  1604,
    1605,  1606,  1607,  1608,  1609,  1610,  1611,  1612,   298,  1824,
    2038,  1613,  1614,  1616,  1618,  1619,  1627,  1629,   298,  1634,
    1635,  1681,  1659,   298,  1645,  1660,  1654,  1643,  1841,  1644,
    1844,  1845,  1651,   489,   490,   491,   492,   493,   494,   495,
     496,   497,   498,   499,   500,   501,   502,  1652,  1674,  2065,
    1653,   503,  1666,  1667,   298,   489,   490,   491,   492,   493,
     494,   495,   496,   497,   498,   499,   500,   501,   502,  1668,
    1669,  1679,  1680,   503,  1670,  1671,  1685,  1676,  1691,   298,
     489,   490,   491,   492,   493,   494,   495,   496,   497,   498,
     499,   500,   501,   502,  1703,  1692,  1706,  1710,   503,  1713,
    1705,  1718,  1719,  1721,  1762,  1724,  1725,  1726,  1727,  1741,
    1746,  1747,  1752,  1753,   298,  1655,   516,   516,  1754,  1757,
    1758,   516,   516,  1759,  1761,  1770,   298,  1771,  1773,  1775,
    1776,  1777,  1778,  1779,  1782,   516,  1801,  1802,  1811,   298,
    1815,   516,  1829,  1797,  1832,  1846,  1836,  1919,  1742,  1847,
    1825,  1848,  1849,  1850,  1854,  1852,   298,  1853,  1855,   515,
    1861,  1864,  1868,  1869,  1874,  1876,  1895,  1886,   371,   238,
    1887,  1892,  1893,  1899,  1913,  1901,  1896,  1911,   298,  1902,
    1918,  1920,  1923,  1924,  1921,   298,   298,  1922,  1925,   516,
    1926,  1927,  1933,  1940,   512,   135,  1988,  1946,  1947,  1948,
    1949,  1951,  1952,  1972,   298,  1977,  1973,   298,  1990,  1989,
    1994,  1996,   483,  2017,  1997,  2020,  2007,  2014,   298,  2018,
    2024,  1696,   298,  2022,  2036,  2028,  2037,  2056,  2061,  1979,
    1980,  1981,  1982,  1983,   162,   163,   164,   165,   166,   167,
     168,   169,   170,  2025,  2066,  2075,  2104,   175,   176,   177,
     178,  2118,  2119,  2103,  2105,   180,   181,   182,  2120,  2101,
     183,  2121,  2123,  2124,  2129,  2128,  2142,  2144,  2151,  2153,
    2165,  2166,   188,   189,  2167,   214,  2169,  2042,   830,  1578,
     298,  1943,  1772,  1594,   112,  2015,   122,   123,   124,  2019,
     913,  1967,   130,     0,  1720,     0,     0,  1700,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     190,   238,     0,     0,     0,  2040,     0,   489,   490,   491,
     492,   493,   494,   495,   496,   497,   498,   499,   500,   501,
     502,     0,     0,     0,     0,   503,     0,  2057,     0,     0,
    1814,  2059,     0,     0,     0,     0,     0,   298,   298,   298,
     298,   298,     0,     0,     0,     0,     0,  2071,     0,     0,
       0,     0,     0,   298,     0,     0,     0,     0,     0,  1851,
       0,     0,     0,     0,     0,   389,     0,   193,   194,   195,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     202,     0,   203,   107,     0,     0,  2102,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1891,
       0,     0,  2115,  2116,     0,     0,   298,     0,   869,     0,
     870,     0,   515,   489,   490,   491,   492,   493,   494,   495,
     496,   497,   498,   499,   500,   501,   502,     0,     0,     0,
       0,   503,     0,     0,     0,   298,     0,     0,     0,     0,
       0,     0,     0,   516,     0,     0,     0,   515,     0,   515,
       0,     0,     0,   371,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   471,   472,   473,   475,   477,     0,     0,
     515,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   511,     0,     0,     0,   518,     0,     0,     0,   489,
     490,   491,   492,   493,   494,   495,   496,   497,   498,   499,
     500,   501,   502,   527,   529,   532,   533,   503,   535,   529,
     537,   538,     0,   540,   529,   542,   543,   544,   545,   546,
     547,     0,   549,   550,   551,  2074,     0,     0,   529,     0,
       0,     0,   489,   490,   491,   492,   493,   494,   495,   496,
     497,   498,   499,   500,   501,   502,     0,   584,   586,   529,
     503,     0,     0,     0,     0,     0,     0,     0,     0,   595,
     529,   489,   490,   491,   492,   493,   494,   495,   496,   497,
     498,   499,   500,   501,   502,   616,     0,     0,     0,   503,
       0,     0,     0,     0,   625,   626,     0,     0,     0,     0,
     626,     0,     0,     0,     0,  2041,     0,     0,     0,     0,
     647,   489,   490,   491,   492,   493,   494,   495,   496,   497,
     498,   499,   500,   501,   502,     0,     0,     0,     0,   503,
     666,     0,     0,     0,   669,   670,   671,     0,   673,     0,
       0,     0,   676,   677,   678,     0,     0,   679,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   693,     0,     0,     0,     0,     0,   698,   700,     0,
       0,     0,     0,     0,     0,  2126,     0,     0,     0,     0,
       0,   707,   708,   709,   710,   711,   712,   713,   714,   715,
     716,   717,   718,   719,   720,   721,   722,   723,   724,   725,
     726,   727,   728,   729,   730,     0,     0,     0,     0,     0,
    2152,     0,  2155,     0,     0,     0,   516,     0,   744,     0,
       0,     0,     0,     0,   750,     0,     0,     0,     0,     0,
       0,   759,     0,  2168,  1917,     0,   489,   490,   491,   492,
     493,   494,   495,   496,   497,   498,   499,   500,   501,   502,
       0,   516,     0,   516,   503,   791,   529,     0,   793,   794,
     795,   796,   797,   798,   799,   800,   801,   802,   803,   804,
     805,   806,   807,     0,   516,   809,   810,  2035,     0,     0,
     489,   490,   491,   492,   493,   494,   495,   496,   497,   498,
     499,   500,   501,   502,     0,     0,  2091,   584,   503,     0,
       0,  1430,     0,   842,     0,  1790,     0,  1791,   847,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   861,     0,     0,     0,     0,     0,   867,   868,
       0,   874,   874,   879,   880,     0,   882,     0,     0,   884,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   874,   529,     0,     0,     0,     0,     0,   896,   898,
     900,   901,     0,     0,     0,     0,   907,   908,   909,     0,
       0,     0,     0,   915,   918,   921,   924,   926,     0,   928,
       0,   930,     0,   529,   529,     0,   489,   490,   491,   492,
     493,   494,   495,   496,   497,   498,   499,   500,   501,   502,
       0,   471,   472,   948,   503,     0,     0,   953,   954,   955,
     956,   957,   958,   959,   960,   961,     0,     0,     0,     0,
     967,     0,   969,   970,     0,     0,     0,   529,   529,   529,
       0,     0,   977,   978,   979,     0,   489,   490,   491,   492,
     493,   494,   495,   496,   497,   498,   499,   500,   501,   502,
       0,   529,   589,     0,   503,     0,   867,   868,     0,   900,
     901,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1011,   529,     0,     0,     0,  1015,     0,     0,     0,   489,
     490,   491,   492,   493,   494,   495,   496,   497,   498,   499,
     500,   501,   502,     0,     0,     0,     0,   503,   489,   490,
     491,   492,   493,   494,   495,   496,   497,   498,   499,   500,
     501,   502,     0,   530,     0,     0,   503,     0,   530,     0,
    1061,     0,     0,   530,  1065,  1066,  1067,  1068,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   530,     0,     0,
     589,     0,     7,     8,     0,     0,  1093,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   585,     0,   530,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   530,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1126,  1127,     0,   529,  1132,  1133,     0,
       0,   529,  1137,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1147,     0,     0,   898,  1150,     0,     0,
       0,     0,     0,     0,     0,     0,   783,    25,    26,   784,
      28,    29,   785,    31,   786,    33,    34,    35,    36,  1172,
       0,     0,    38,    39,    40,     0,     0,    42,     0,     0,
     529,     0,   529,   787,    48,   529,     0,    50,   788,     0,
      53,   789,   489,   490,   491,   492,   493,   494,   495,   496,
     497,   498,   499,   590,   501,   502,   529,     0,     0,    70,
     503,   529,     0,     0,     0,     0,     0,     0,     0,  1206,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    84,    85,    86,     0,     0,     0,     0,
       0,     0,     0,   529,     0,     0,     0,     0,     0,     0,
    1230,  1231,     0,     0,     0,     0,  1234,     0,   489,   490,
     491,   492,   493,   494,   495,   496,   497,   498,   499,   500,
     501,   502,  1259,     0,     0,  1261,   503,     0,   771,     0,
     489,   490,   491,   492,   493,   494,   495,   496,   497,   498,
     499,   837,   501,   502,  1275,   530,  1277,  1278,   503,     0,
     296,     0,     0,     0,     0,   993,     0,  1285,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   531,     0,
       0,     0,     0,   536,     0,     0,     0,     0,   541,     0,
       0,     0,     0,     0,     0,     0,   585,     0,  1307,     0,
       0,     0,   554,     0,     0,     0,  1308,  1309,  1310,     0,
     529,     7,     8,     0,     0,     0,     0,     0,  1313,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     875,   877,     0,     0,   596,     0,     0,     0,     0,  1325,
     988,     0,     0,     0,  1328,     0,     0,     0,     0,     0,
     892,   530,     0,  1332,     0,     0,     0,     0,   899,  1340,
       0,     0,     0,     0,     0,     0,     0,     0,  1111,   529,
     529,   529,   529,  1353,     0,     0,     0,     0,     0,     0,
    1359,     0,   530,   530,     0,   783,    25,    26,   784,    28,
      29,   785,    31,   786,    33,    34,    35,    36,     0,     0,
       0,    38,    39,    40,     0,     0,    42,     0,     0,     0,
       0,     0,   787,    48,  1381,     0,    50,   788,     0,    53,
     789,     0,     0,     0,     0,     0,   530,   530,   530,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    70,     0,
       0,     0,     0,   529,     0,     0,     0,     0,     0,     0,
     530,     0,     0,  1414,  1415,     0,  1416,  1417,     0,  1418,
    1419,  1420,    84,    85,    86,  1422,     0,     0,     0,     0,
     530,   529,  1196,     0,     0,     0,     0,     0,     0,   552,
       0,  1434,     0,  1436,     0,  1438,     0,  1440,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   296,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1457,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   600,     0,     0,
     792,     0,     0,     0,     0,   609,   611,   613,     0,     0,
       0,   618,     0,     0,   994,     0,     0,     0,     0,  1488,
     489,   490,   491,   492,   493,   494,   495,   496,   497,   498,
     499,   500,   501,   502,     0,     0,     0,     0,   503,     0,
       0,     0,  1508,     0,     0,     0,     0,  1513,   489,   490,
     491,   492,   493,   494,   495,   496,   497,   498,   499,   500,
     501,   502,     0,     0,     0,   530,   503,     0,     0,     0,
     530,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   899,  1151,     0,   695,   696,
       0,     0,     0,     0,  1556,     0,   893,     0,     0,     0,
       0,     0,   704,  1564,  1565,  1566,  1567,     0,     0,     0,
    1570,  1571,     0,     0,     0,     0,     0,     0,     0,   530,
       0,   530,     0,     0,   530,  1580,  1582,   932,   933,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   741,
       0,     0,     0,     0,     0,   530,     0,     0,     0,     0,
     530,     0,   489,   490,   491,   492,   493,   494,   495,   496,
     497,   498,   499,   500,   501,   502,     0,     0,     0,     0,
     503,   972,   973,   974,     0,     0,     7,     8,     0,     0,
       0,     0,   530,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   992,     0,     0,  1648,  1649,
    1650,     0,     0,     0,     0,     0,     0,  1656,     0,  1658,
       0,     0,     0,     0,     0,  1012,  1661,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   529,
       0,     0,     0,     0,  1677,     0,     0,     0,     0,     0,
       0,     0,  1682,  1683,  1684,     0,     0,     0,     0,     0,
     783,    25,    26,   784,    28,    29,   785,    31,   786,    33,
      34,    35,    36,     0,     0,     0,    38,    39,    40,  1494,
     600,    42,     0,     0,  1704,     0,     0,   787,    48,     0,
       0,    50,   788,  1707,    53,   789,     0,     0,     0,   530,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1717,
       0,     0,     0,    70,   489,   490,   491,   492,   493,   494,
     495,   496,   497,   498,   499,   500,   501,   502,  1734,     0,
       0,     0,   503,  1740,     0,     0,     0,    84,    85,    86,
    1131,  1109,     0,     0,     0,  1136,     0,     0,     0,  1749,
    1750,     0,     0,     0,     0,     0,  1755,  1756,   530,   530,
     530,   530,     0,  1760,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1763,
    1764,  1765,  1766,  1767,  1768,  1769,     0,     0,     0,     0,
       0,     0,   903,  1774,  1178,     0,  1179,     0,     0,  1181,
       0,     0,   529,   529,  1785,     0,  1786,     0,     0,  1227,
       0,     0,  1794,  1795,     0,     0,     0,     0,     0,     0,
    1197,     0,     0,     0,     0,  1200,     0,     0,     0,     0,
       0,   529,   530,     0,     0,  1813,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1823,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1224,     0,     0,
     530,     0,     0,     0,     0,     0,     0,  1843,     0,     0,
       0,     0,     0,  1082,     0,     0,     0,  1088,     0,   489,
     490,   491,   492,   493,   494,   495,   496,   497,   498,   499,
     500,   501,   502,     0,  1858,  1859,     0,   503,     0,     0,
       0,     0,  1865,     0,     0,     0,     0,     0,  1018,  1019,
    1020,  1021,  1022,  1023,  1024,  1025,  1026,  1027,  1028,     0,
    1030,  1031,  1032,  1033,  1034,  1035,  1036,     0,     0,  1885,
    1040,  1042,  1043,     0,     0,     0,  1047,  1048,     0,  1050,
       0,     0,     0,     0,  1055,  1056,  1057,     0,  1059,  1894,
     135,  1062,     0,     0,     0,     0,     0,     0,     0,  1903,
       0,     0,  1074,  1076,  1311,     0,     0,     0,   584,     0,
       0,     0,     0,     0,     0,     0,  1914,     0,  1915,     0,
    1099,   529,     0,     0,     0,     0,     0,     0,     0,   162,
     163,   164,   165,   166,   167,   168,   169,   170,  1929,     0,
       0,     0,   175,   176,   177,   178,     0,     0,     0,     0,
     180,   181,   182,     0,  1207,   183,  1935,     0,     0,     0,
       0,  1939,     0,  1349,  1350,  1351,  1352,   188,   189,     0,
       0,     0,     0,  1950,     0,     0,     0,     0,     0,  1954,
    1955,  1956,  1957,  1958,     0,     0,     0,     0,     0,   529,
     489,   490,   491,   492,   493,   494,   495,   496,   497,   498,
     499,   500,   501,   502,   529,     0,     0,     0,   503,     0,
       0,     0,  1984,     0,     0,  1817,     0,  1818,     0,     0,
    1186,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1193,     0,     0,     0,  1998,  1999,  1409,     0,     0,
    2001,     0,     0,     0,  1288,     0,     0,     0,  1292,     0,
       0,     0,  1297,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1426,     0,     0,     0,  2023,
       0,     0,   193,   194,   195,     0,     0,     0,   530,     0,
       0,     0,     0,     0,     0,   202,     0,   203,     0,     0,
    2039,     0,     0,     0,  1314,     0,  1740,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2050,  2051,  2052,  2053,
    2054,  2055,   512,   135,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2063,     0,     0,     0,     0,   529,
     529,   529,   529,   529,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2078,     0,     0,  2080,     0,     0,     0,
       0,     0,   162,   163,   164,   165,   166,   167,   168,   169,
     170,     0,     0,     0,     0,   175,   176,   177,   178,     0,
       0,     0,     0,   180,   181,   182,     0,     0,   183,     0,
       0,     0,  2109,  2110,  2111,  2112,  2113,  2114,     0,     0,
     188,   189,     0,     0,     0,     0,  1387,  1388,   529,  1390,
       0,  1393,  1394,     0,  1396,     0,  1398,  1399,  1400,  1401,
    1402,  1403,  1404,  1405,  1406,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   190,     0,
       0,  2145,  2146,  2147,  2148,  2149,  2150,     0,  1421,     0,
       0,   530,   530,     0,  1425,     0,     0,     0,     0,  1358,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   242,   243,     0,     0,     0,     0,     0,     0,
     530,     0,     0,     0,     0,     0,     0,     0,     0,   382,
     135,     0,     0,     0,     0,     0,  1382,  1383,     0,     0,
       0,     0,     0,     0,     0,   193,   194,   195,     0,     0,
       0,  1478,     0,     0,     0,     0,     0,     0,   202,     0,
     203,   107,     0,     0,  1489,  1490,  1491,     0,     0,   162,
     163,   164,   165,   166,   167,   168,   169,   170,     0,     0,
    1503,     0,   175,   176,   177,   178,     0,     0,     0,     0,
     180,   181,   182,  1675,     0,   183,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   188,   189,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   401,     0,     0,     0,     0,     0,     0,     0,     0,
     414,   415,   416,   417,   418,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,     0,  1573,   585,   442,   443,
     444,   445,     0,   447,   448,   449,   450,   451,   452,     0,
     530,   454,     0,     0,     0,     0,     0,   455,   456,   457,
       0,     0,  1595,     0,     0,   466,   467,  1930,  1601,     0,
    1515,     0,     0,     0,     0,     0,  1519,  1520,  1521,  1522,
    1523,     0,  1526,     0,  1528,  1529,     0,  1532,     0,  1536,
       0,     0,   193,   194,   195,     0,  1540,  1541,  1542,     0,
    1631,  1632,  1633,  1546,     0,   202,  1636,   203,  1637,     0,
    1638,     0,  1639,     0,  1640,  1641,  1642,     0,   530,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1657,     0,   530,     0,     0,  1783,  1784,     0,     0,
       0,     0,  1665,     0,   561,     0,   564,   565,   566,   567,
    1673,     0,     0,     0,     0,     0,     0,   582,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   593,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1617,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1628,   133,   388,     0,     0,     0,     0,
     136,   137,   138,     0,     0,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1732,     0,     0,   171,   172,   173,   174,     0,     0,
       0,     0,   179,     0,  1744,     0,     0,     0,   530,   530,
     530,   530,   530,   184,   185,   186,     0,     0,     0,     0,
       0,   187,    21,     0,  1693,     0,     0,     0,     0,  1697,
     489,   490,   491,   492,   493,   494,   495,   496,   497,   498,
     499,   500,   501,   502,     0,     0,     0,     0,   503,     0,
       0,     0,     0,     0,     0,  1970,     0,  1971,     0,     0,
       0,     0,  1711,  1712,     0,  1916,  1714,  1715,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   530,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1573,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   781,     0,     0,  1816,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1828,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1835,     0,     0,   192,     0,  1840,
       0,   196,     0,  1968,     0,     0,   197,   198,   199,   200,
     201,     0,     0,     0,   107,     0,     0,     0,  1978,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   204,   205,
    1860,     0,     0,   206,     0,     0,     0,     0,   361,     0,
       0,     0,     0,   210,     0,   615,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1573,     0,     0,   489,   490,
     491,   492,   493,   494,   495,   496,   497,   498,   499,   500,
     501,   502,     0,     0,     0,     0,   503,     0,     0,     0,
       0,     0,     0,  1830,  1831,  1189,     0,  1833,  1834,     0,
    1900,     0,     0,  1837,  1838,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   133,   388,     0,     0,     0,
       0,   136,   137,   138,     0,     0,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,     0,
       0,     0,     0,  2067,  2068,  2069,  2070,  2072,     0,     0,
       0,     0,  1878,  1879,  1573,   171,   172,   173,   174,     0,
       0,  1944,  1945,   179,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   184,   185,   186,     0,     0,     0,
    1573,     0,   187,    21,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1974,   489,   490,   491,   492,   493,
     494,   495,   496,   497,   498,   499,   500,   501,   502,     0,
       0,     0,  2122,   503,     0,     0,   133,   134,   135,     0,
       0,   689,   136,   137,   138,     0,     0,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
       0,     0,     0,     0,     0,     0,  2016,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,     0,     0,     0,   180,   181,
     182,     0,     0,   183,     0,   184,   185,   186,   192,     0,
       0,     0,   196,   187,    21,   188,   189,   197,   198,   199,
     200,   201,     0,     0,     0,   107,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   632,
     633,     0,     0,     0,   206,     0,     0,     0,     0,   634,
       0,     0,     0,   190,   210,     0,   326,     0,     0,  1573,
     489,   490,   491,   492,   493,   494,   495,   496,   497,   498,
     499,   500,   501,   502,     0,     0,     0,     0,   503,     0,
       0,     0,     0,     0,     0,     0,     0,  1250,   489,   490,
     491,   492,   493,   494,   495,   496,   497,   498,   499,   500,
     501,   502,     0,     0,     0,     0,   503,     0,     0,     0,
       0,     0,   191,     0,     0,  1300,     0,     0,     0,   192,
     193,   194,   195,   196,     0,     0,     0,     0,   197,   198,
     199,   200,   201,   202,     0,   203,   107,     0,     0,     0,
       0,  1573,     0,     0,     0,     0,     0,     0,     0,     0,
     204,   205,     0,     0,     0,   206,     0,     0,     0,     0,
     207,     0,   208,     0,   209,   210,     0,   211,     0,   212,
       0,     0,     0,     0,     0,     0,     0,   133,   274,     0,
       0,     0,     0,   136,   137,   138,     0,     0,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   275,   276,   277,   278,   279,     0,     0,     0,  2131,
       0,     0,     0,     0,     0,     0,     0,   171,   172,   173,
     174,     0,     0,     0,     0,   179,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   184,   185,   186,     0,
       0,     0,     0,     0,   187,    21,     0,     0,     0,     0,
     280,     0,     0,   281,     0,     0,   282,     0,   283,     0,
       0,     0,     0,     0,     0,    37,     0,     0,     0,     0,
     236,   135,     0,     0,     0,     0,     0,   284,     0,    49,
    1329,  1330,   285,     0,   286,     0,  1334,  1335,     0,     0,
       0,    59,    60,    61,    62,    63,     0,     0,    65,    66,
      67,    68,    69,     0,     0,     0,    73,     0,     0,    76,
     162,   163,   164,   165,   166,   167,   168,   169,   170,     0,
       0,     0,     0,   175,   176,   177,   178,     0,     0,     0,
       0,   180,   181,   182,     0,     0,   183,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   188,   189,
     192,     0,     0,     0,   196,   287,     0,     0,     0,   197,
     198,   199,   200,   201,     0,     0,     0,   107,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   632,  1809,     0,     0,     0,   206,     0,     0,     0,
       0,   634,     0,     0,   133,   274,   210,     0,   326,   587,
     136,   137,   138,     0,     0,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   275,   276,
     277,   278,   279,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   171,   172,   173,   174,     0,     0,
       0,     0,   179,   193,   194,   195,     0,     0,     0,     0,
       0,     0,     0,   184,   185,   186,   202,     0,   203,   107,
       0,   187,    21,     0,     0,     0,     0,   280,     0,     0,
     281,     0,     0,   282,     0,   283,     0,     0,     0,     0,
    1505,  1506,    37,     0,     0,  1510,  1511,     0,     0,     0,
       0,     0,     0,     0,   284,     0,    49,     0,     0,   285,
       0,   286,     0,     0,     0,     0,     0,     0,    59,    60,
      61,    62,    63,     0,     0,    65,    66,    67,    68,    69,
       0,     0,     0,    73,     0,     0,    76,   489,   490,   491,
     492,   493,   494,   495,   496,   497,   498,   499,   500,   501,
     502,     0,     0,     0,     0,   503,     0,     0,     0,     0,
       0,     0,     0,     0,  1321,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   192,     0,     0,
       0,   196,   287,     0,     0,     0,   197,   198,   199,   200,
     201,     0,     0,     0,   107,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   204,   528,
       0,     0,     0,   206,     0,     0,     0,     0,   361,     0,
       0,     0,     0,   210,     0,     0,   587,   133,   274,   135,
       0,     0,     0,   136,   137,   138,     0,     0,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   275,   276,   277,   278,   279,     0,     0,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,     0,     0,     0,   180,
     181,   182,     0,     0,   183,     0,   184,   185,   186,     0,
       0,     0,     0,     0,   187,    21,   188,   189,     0,     0,
     280,     0,     0,   281,     0,     0,   282,     0,   283,     0,
       0,     0,     0,     0,     0,    37,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   284,     0,    49,
       0,     0,   285,     0,   286,     0,     0,     0,     0,     0,
       0,    59,    60,    61,    62,    63,     0,     0,    65,    66,
      67,    68,    69,     0,     0,     0,    73,     0,     0,    76,
     489,   490,   491,   492,   493,   494,   495,   496,   497,   498,
     499,   500,   501,   502,     0,     0,     0,     0,   503,     0,
       0,     0,     0,     0,     0,     0,     0,  1322,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     192,   193,   194,   195,   196,   287,     0,     0,     0,   197,
     198,   199,   200,   201,   202,     0,   203,   107,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   204,   288,     0,     0,     0,   206,     0,     0,     0,
       0,   361,     0,   133,   274,   135,   210,     0,   290,   136,
     137,   138,     0,     0,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   275,   276,   277,
     278,   279,     0,     0,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,     0,     0,     0,   180,   181,   182,     0,     0,
     183,     0,   184,   185,   186,     0,     0,     0,     0,     0,
     187,    21,   188,   189,     0,     0,   280,     0,     0,   281,
       0,     0,   282,     0,   283,     0,     0,     0,     0,     0,
       0,    37,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   284,     0,    49,     0,     0,   285,     0,
     286,     0,     0,     0,     0,     0,     0,    59,    60,    61,
      62,    63,     0,     0,    65,    66,    67,    68,    69,     0,
       0,     0,    73,     0,     0,    76,   489,   490,   491,   492,
     493,   494,   495,   496,   497,   498,   499,   500,   501,   502,
       0,     0,     0,     0,   503,     0,     0,     0,     0,     0,
       0,     0,     0,  1323,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   192,   193,   194,   195,
     196,   287,     0,     0,     0,   197,   198,   199,   200,   201,
     202,     0,   203,   107,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   204,   288,     0,
       0,     0,   206,     0,     0,     0,     0,   361,     0,   133,
     274,   360,   210,     0,  1839,   136,   137,   138,     0,     0,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   275,   276,   277,   278,   279,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   171,
     172,   173,   174,     0,     0,     0,     0,   179,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   184,   185,
     186,     0,     0,     0,     0,     0,   187,    21,     0,     0,
       0,     0,   280,     0,     0,   281,     0,     0,   282,     0,
     283,     0,     0,     0,     0,     0,     0,    37,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   284,
       0,    49,     0,     0,   285,     0,   286,     0,     0,     0,
       0,     0,     0,    59,    60,    61,    62,    63,     0,     0,
      65,    66,    67,    68,    69,     0,     0,     0,    73,     0,
       0,    76,   489,   490,   491,   492,   493,   494,   495,   496,
     497,   498,   499,   500,   501,   502,     0,     0,     0,     0,
     503,     0,     0,     0,     0,     0,     0,     0,     0,  1324,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   192,     0,     0,     0,   196,   287,     0,     0,
       0,   197,   198,   199,   200,   201,     0,     0,     0,   107,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   204,   288,     0,     0,     0,   206,     0,
       0,     0,     0,   361,     0,   133,   274,  1664,   210,     0,
     290,   136,   137,   138,     0,     0,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   275,
     276,   277,   278,   279,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   171,   172,   173,   174,     0,
       0,     0,     0,   179,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   184,   185,   186,     0,     0,     0,
       0,     0,   187,    21,     0,     0,     0,     0,   280,     0,
       0,   281,     0,     0,   282,     0,   283,     0,     0,     0,
       0,     0,     0,    37,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   284,     0,    49,     0,     0,
     285,     0,   286,     0,     0,     0,     0,     0,     0,    59,
      60,    61,    62,    63,     0,     0,    65,    66,    67,    68,
      69,     0,     0,     0,    73,     0,     0,    76,   489,   490,
     491,   492,   493,   494,   495,   496,   497,   498,   499,   500,
     501,   502,     0,     0,     0,     0,   503,     0,     0,     0,
       0,     0,     0,     0,     0,  1452,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   192,     0,
       0,     0,   196,   287,     0,     0,     0,   197,   198,   199,
     200,   201,     0,     0,     0,   107,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   204,
     288,     0,     0,     0,   206,     0,     0,     0,     0,   361,
       0,   133,   274,     0,   210,     0,   290,   136,   137,   138,
       0,     0,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   275,   276,   277,   278,   279,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   171,   172,   173,   174,     0,     0,     0,     0,   179,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     184,   185,   186,     0,     0,     0,     0,     0,   187,    21,
       0,     0,     0,     0,   280,     0,     0,   281,     0,     0,
     282,     0,   283,     0,     0,     0,     0,     0,     0,    37,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   284,     0,    49,     0,     0,   285,     0,   286,     0,
       0,     0,     0,     0,     0,    59,    60,    61,    62,    63,
       0,     0,    65,    66,    67,    68,    69,     0,     0,     0,
      73,     0,     0,    76,   489,   490,   491,   492,   493,   494,
     495,   496,   497,   498,   499,   500,   501,   502,     0,     0,
       0,     0,   503,     0,     0,     0,     0,     0,     0,     0,
       0,  1788,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   192,     0,     0,     0,   196,   287,
       0,     0,     0,   197,   198,   199,   200,   201,     0,     0,
       0,   107,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   204,   288,     0,     0,     0,
     206,     0,     0,     0,     0,   289,     0,   133,   274,     0,
     210,     0,   290,   136,   137,   138,     0,     0,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   275,   276,   277,   278,   279,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   171,   172,   173,
     174,     0,     0,     0,     0,   179,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   184,   185,   186,     0,
       0,     0,     0,     0,   187,    21,     0,     0,     0,     0,
     280,     0,     0,   281,     0,     0,   282,     0,   283,     0,
       0,     0,     0,     0,     0,    37,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   284,     0,    49,
       0,     0,   285,     0,   286,     0,     0,     0,     0,     0,
       0,    59,    60,    61,    62,    63,     0,     0,    65,    66,
      67,    68,    69,     0,     0,     0,    73,     0,     0,    76,
     489,   490,   491,   492,   493,   494,   495,   496,   497,   498,
     499,   500,   501,   502,     0,     0,     0,     0,   503,     0,
       0,     0,     0,     0,     0,     0,     0,  1799,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     192,     0,     0,     0,   196,   287,     0,     0,     0,   197,
     198,   199,   200,   201,     0,     0,     0,   107,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   204,   288,     0,     0,     0,   206,     0,     0,     0,
       0,   361,     0,   133,   274,     0,   210,     0,   290,   136,
     137,   138,     0,     0,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   275,   276,   277,
     278,   279,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   171,   172,   173,   174,     0,     0,     0,
       0,   179,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   184,   185,   186,     0,     0,     0,     0,     0,
     187,    21,     0,     0,     0,     0,   280,     0,     0,   281,
       0,     0,   282,     0,   283,     0,     0,     0,     0,     0,
       0,    37,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   284,     0,    49,     0,     0,   285,     0,
     286,     0,     0,     0,     0,     0,     0,    59,    60,    61,
      62,    63,     0,     0,    65,    66,    67,    68,    69,     0,
       0,     0,    73,     0,     0,    76,   489,   490,   491,   492,
     493,   494,   495,   496,   497,   498,   499,   500,   501,   502,
       0,     0,     0,     0,   503,     0,     0,     0,     0,     0,
       0,     0,     0,  1870,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   192,     0,     0,     0,
     196,   287,     0,     0,     0,   197,   198,   199,   200,   201,
       0,     0,     0,   107,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   204,   528,     0,
       0,     0,   206,     0,     0,     0,     0,   361,     0,   133,
     274,     0,   210,     0,   583,   136,   137,   138,     0,     0,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   275,   276,   277,   278,   279,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   171,
     172,   173,   174,     0,     0,     0,     0,   179,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   184,   185,
     186,     0,     0,     0,     0,     0,   187,    21,     0,     0,
       0,     0,   280,     0,     0,   281,     0,     0,   282,     0,
     283,     0,     0,     0,     0,     0,     0,    37,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   284,
       0,    49,     0,     0,   285,     0,   286,     0,     0,     0,
       0,     0,     0,    59,    60,    61,    62,    63,     0,     0,
      65,    66,    67,    68,    69,     0,     0,     0,    73,     0,
       0,    76,   489,   490,   491,   492,   493,   494,   495,   496,
     497,   498,   499,   500,   501,   502,     0,     0,     0,     0,
     503,     0,     0,     0,     0,     0,     0,     0,     0,  1871,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   192,     0,     0,     0,   196,   287,     0,     0,
       0,   197,   198,   199,   200,   201,     0,     0,     0,   107,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   204,   288,     0,     0,     0,   206,     0,
       0,     0,     0,   599,     0,   133,   274,     0,   210,     0,
     290,   136,   137,   138,     0,     0,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   275,
     276,   277,   278,   279,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   171,   172,   173,   174,     0,
       0,     0,     0,   179,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   184,   185,   186,     0,     0,     0,
       0,     0,   187,    21,     0,     0,     0,     0,   280,     0,
       0,   281,     0,     0,   282,     0,   283,     0,     0,     0,
       0,     0,     0,    37,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   284,     0,    49,     0,     0,
     285,     0,   286,     0,     0,     0,     0,     0,     0,    59,
      60,    61,    62,    63,     0,     0,    65,    66,    67,    68,
      69,     0,     0,     0,    73,     0,     0,    76,   489,   490,
     491,   492,   493,   494,   495,   496,   497,   498,   499,   500,
     501,   502,     0,     0,     0,     0,   503,     0,     0,     0,
       0,     0,     0,     0,     0,  1872,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   192,     0,
       0,     0,   196,   287,     0,     0,     0,   197,   198,   199,
     200,   201,     0,     0,     0,   107,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   204,
     288,     0,     0,     0,   206,     0,     0,     0,     0,   608,
       0,   133,   274,     0,   210,     0,   290,   136,   137,   138,
       0,     0,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   275,   276,   277,   278,   279,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   171,   172,   173,   174,     0,     0,     0,     0,   179,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     184,   185,   186,     0,     0,     0,     0,     0,   187,    21,
       0,     0,     0,     0,   280,     0,     0,   281,     0,     0,
     282,     0,   283,     0,     0,     0,     0,     0,     0,    37,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   284,     0,    49,     0,     0,   285,     0,   286,     0,
       0,     0,     0,     0,     0,    59,    60,    61,    62,    63,
       0,     0,    65,    66,    67,    68,    69,     0,     0,     0,
      73,     0,     0,    76,   489,   490,   491,   492,   493,   494,
     495,   496,   497,   498,   499,   500,   501,   502,     0,     0,
       0,     0,   503,     0,     0,     0,     0,     0,     0,     0,
       0,  1873,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   192,     0,     0,     0,   196,   287,
       0,     0,     0,   197,   198,   199,   200,   201,     0,     0,
       0,   107,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   204,   288,     0,     0,     0,
     206,     0,     0,     0,     0,   610,     0,   133,   274,     0,
     210,     0,   290,   136,   137,   138,     0,     0,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   275,   276,   277,   278,   279,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   171,   172,   173,
     174,     0,     0,     0,     0,   179,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   184,   185,   186,     0,
       0,     0,     0,     0,   187,    21,     0,     0,     0,     0,
     280,     0,     0,   281,     0,     0,   282,     0,   283,     0,
       0,     0,     0,     0,     0,    37,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   284,     0,    49,
       0,     0,   285,     0,   286,     0,     0,     0,     0,     0,
       0,    59,    60,    61,    62,    63,     0,     0,    65,    66,
      67,    68,    69,     0,     0,     0,    73,     0,     0,    76,
     489,   490,   491,   492,   493,   494,   495,   496,   497,   498,
     499,   500,   501,   502,     0,     0,     0,     0,   503,     0,
       0,     0,     0,     0,     0,     0,     0,  1875,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     192,     0,     0,     0,   196,   287,     0,     0,     0,   197,
     198,   199,   200,   201,     0,     0,     0,   107,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   204,   288,     0,     0,     0,   206,     0,     0,     0,
       0,   612,     0,   133,   274,     0,   210,     0,   290,   136,
     137,   138,     0,     0,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   275,   276,   277,
     278,   279,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   171,   172,   173,   174,     0,     0,     0,
       0,   179,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   184,   185,   186,     0,     0,     0,     0,     0,
     187,    21,     0,     0,     0,     0,   280,     0,     0,   281,
       0,     0,   282,     0,   283,     0,     0,     0,     0,     0,
       0,    37,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   284,     0,    49,     0,     0,   285,     0,
     286,     0,     0,     0,     0,     0,     0,    59,    60,    61,
      62,    63,     0,     0,    65,    66,    67,    68,    69,     0,
       0,     0,    73,     0,     0,    76,   489,   490,   491,   492,
     493,   494,   495,   496,   497,   498,   499,   500,   501,   502,
       0,     0,     0,     0,   503,     0,     0,     0,     0,     0,
       0,     0,     0,  1897,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   192,     0,     0,     0,
     196,   287,     0,     0,     0,   197,   198,   199,   200,   201,
       0,     0,     0,   107,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   204,   528,     0,
       0,     0,   206,     0,     0,     0,     0,   361,     0,   133,
     274,     0,   210,     0,   873,   136,   137,   138,     0,     0,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   275,   276,   277,   278,   279,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   171,
     172,   173,   174,     0,     0,     0,     0,   179,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   184,   185,
     186,     0,     0,     0,     0,     0,   187,    21,     0,     0,
       0,     0,   280,     0,     0,   281,     0,     0,   282,     0,
     283,     0,     0,     0,     0,     0,     0,    37,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   284,
       0,    49,     0,     0,   285,     0,   286,     0,     0,     0,
       0,     0,     0,    59,    60,    61,    62,    63,     0,     0,
      65,    66,    67,    68,    69,     0,     0,     0,    73,     0,
       0,    76,   489,   490,   491,   492,   493,   494,   495,   496,
     497,   498,   499,   500,   501,   502,     0,     0,     0,     0,
     503,     0,     0,     0,     0,     0,     0,     0,     0,  1912,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   192,     0,     0,     0,   196,   287,     0,     0,
       0,   197,   198,   199,   200,   201,     0,     0,     0,   107,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   204,   528,     0,     0,     0,   206,     0,
       0,     0,     0,   361,     0,   133,   274,     0,   210,     0,
     876,   136,   137,   138,     0,     0,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   275,
     276,   277,   278,   279,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   171,   172,   173,   174,     0,
       0,     0,     0,   179,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   184,   185,   186,     0,     0,     0,
       0,     0,   187,    21,     0,     0,     0,     0,   280,     0,
       0,   281,     0,     0,   282,     0,   283,     0,     0,     0,
       0,     0,     0,    37,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   284,     0,    49,     0,     0,
     285,     0,   286,     0,     0,     0,     0,     0,     0,    59,
      60,    61,    62,    63,     0,     0,    65,    66,    67,    68,
      69,     0,     0,     0,    73,     0,     0,    76,   489,   490,
     491,   492,   493,   494,   495,   496,   497,   498,   499,   500,
     501,   502,     0,     0,     0,     0,   503,     0,     0,     0,
       0,     0,     0,     0,     0,  1959,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   192,     0,
       0,     0,   196,   287,     0,     0,     0,   197,   198,   199,
     200,   201,     0,     0,     0,   107,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   204,
     528,     0,     0,     0,   206,     0,     0,     0,     0,   361,
       0,   133,   274,     0,   210,     0,   897,   136,   137,   138,
       0,     0,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   275,   276,   277,   278,   279,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   171,   172,   173,   174,     0,     0,     0,     0,   179,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     184,   185,   186,     0,     0,     0,     0,     0,   187,    21,
       0,     0,     0,     0,   280,     0,     0,   281,     0,     0,
     282,     0,   283,     0,     0,     0,     0,     0,     0,    37,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   284,     0,    49,     0,     0,   285,     0,   286,     0,
       0,     0,     0,     0,     0,    59,    60,    61,    62,    63,
       0,     0,    65,    66,    67,    68,    69,     0,     0,     0,
      73,     0,     0,    76,   489,   490,   491,   492,   493,   494,
     495,   496,   497,   498,   499,   500,   501,   502,     0,     0,
       0,     0,   503,     0,     0,     0,     0,     0,     0,     0,
       0,  1976,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   192,     0,     0,     0,   196,   287,
       0,     0,     0,   197,   198,   199,   200,   201,     0,     0,
       0,   107,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   204,   288,     0,     0,     0,
     206,     0,     0,     0,     0,   361,     0,   133,   274,     0,
     210,     0,  1672,   136,   137,   138,     0,     0,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   275,   276,   277,   278,   279,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   171,   172,   173,
     174,     0,     0,     0,     0,   179,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   184,   185,   186,     0,
       0,     0,     0,     0,   187,    21,     0,     0,     0,     0,
     280,     0,     0,   281,     0,     0,   282,     0,   283,     0,
       0,     0,     0,     0,     0,    37,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   284,     0,    49,
       0,     0,   285,     0,   286,     0,     0,     0,     0,     0,
       0,    59,    60,    61,    62,    63,     0,     0,    65,    66,
      67,    68,    69,     0,     0,     0,    73,     0,     0,    76,
     489,   490,   491,   492,   493,   494,   495,   496,   497,   498,
     499,   500,   501,   502,     0,     0,     0,     0,   503,     0,
       0,     0,     0,     0,     0,     0,     0,  1985,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     192,     0,     0,     0,   196,   287,     0,     0,     0,   197,
     198,   199,   200,   201,     0,     0,     0,   107,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   632,  1809,     0,     0,     0,   206,     0,     0,     0,
       0,   634,     0,   133,   388,   135,   210,     0,   326,   136,
     137,   138,     0,     0,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,     0,     0,     0,
       0,     0,     0,     0,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,     0,     0,     0,   180,   181,   182,     0,     0,
     183,     0,   184,   185,   186,     0,     0,     0,     0,     0,
     187,    21,   188,   189,   133,   388,   135,     0,     0,     0,
     136,   137,   138,     0,     0,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,     0,     0,
       0,     0,     0,     0,     0,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,     0,     0,     0,   180,   181,   182,     0,
       0,   183,     0,   184,   185,   186,     0,     0,     0,     0,
       0,   187,    21,   188,   189,   489,   490,   491,   492,   493,
     494,   495,   496,   497,   498,   499,   500,   501,   502,     0,
       0,     0,     0,   503,     0,     0,   192,   193,   194,   195,
     196,     0,  1986,     0,     0,   197,   198,   199,   200,   201,
     202,     0,   203,   107,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   204,   205,     0,
       0,     0,   206,     0,     0,     0,     0,   361,     0,     0,
       0,     0,   210,     0,  1581,   489,   490,   491,   492,   493,
     494,   495,   496,   497,   498,   499,   500,   501,   502,     0,
       0,     0,     0,   503,     0,     0,     0,     0,     0,     0,
       0,     0,  2006,     0,     0,     0,     0,   192,   193,   194,
     195,   196,     0,     0,     0,     0,   197,   198,   199,   200,
     201,   202,     0,   203,   107,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   204,   205,
       0,     0,     0,   206,     0,     0,     0,     0,   361,     0,
     133,   388,   135,   210,     0,  1822,   136,   137,   138,     0,
       0,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,     0,     0,     0,     7,     8,     0,
       0,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,     0,
       0,     0,   180,   181,   182,     0,     0,   183,     0,   184,
     185,   186,     0,     0,     0,     0,     0,   187,    21,   188,
     189,   489,   490,   491,   492,   493,   494,   495,   496,   497,
     498,   499,   500,   501,   502,     0,     0,     0,     0,   503,
       0,     0,     0,     0,     0,     0,     0,     0,  2062,     0,
       0,   783,    25,    26,   784,    28,    29,   785,    31,   786,
      33,    34,    35,    36,     0,     0,     0,    38,    39,    40,
       0,     0,    42,     0,     0,     0,     0,     0,   787,    48,
       0,     0,    50,   788,     0,    53,   789,   489,   490,   491,
     492,   493,   494,   495,   496,   497,   498,   499,   500,   501,
     502,     0,     0,     0,    70,   503,     0,     0,   998,     0,
       0,     0,     0,     0,  2108,     0,     0,     0,     0,     0,
       0,     0,     0,   192,   193,   194,   195,   196,    84,    85,
      86,     0,   197,   198,   199,   200,   201,   202,     0,   203,
     107,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   204,   205,     0,     0,     0,   206,
       0,     0,     0,     0,   361,     0,   133,   274,     0,   210,
       0,  1842,   136,   137,   138,     0,     0,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     275,   276,   277,   278,   279,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   171,   172,   173,   174,
       0,     0,     0,     0,   179,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   184,   185,   186,     0,     0,
       0,     0,     0,   187,    21,     0,     0,     0,     0,   280,
       0,     0,   281,     0,     0,   282,     0,   283,     0,     0,
       0,     0,     0,     0,    37,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   284,     0,    49,     0,
       0,   285,     0,   286,     0,     0,     0,     0,     0,     0,
      59,    60,    61,    62,    63,     0,     0,    65,    66,    67,
      68,    69,     0,     0,     0,    73,     0,     0,    76,   489,
     490,   491,   492,   493,   494,   495,   496,   497,   498,   499,
     500,   501,   502,     0,     0,     0,     0,   503,     0,     0,
       0,     0,     0,     0,     0,     0,  2130,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   192,
       0,     0,     0,   196,   287,     0,     0,     0,   197,   198,
     199,   200,   201,     0,     0,     0,   107,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     204,   528,     0,     0,     0,   206,   133,   388,   135,     0,
     361,     0,   136,   137,   138,   210,     0,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
       0,     0,     0,     0,     0,     0,     0,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,     0,     0,     0,   180,   181,
     182,     0,     0,   183,     0,   184,   185,   186,     0,     0,
       0,   133,   388,   187,    21,   188,   189,   136,   137,   138,
       0,     0,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,     0,     0,   489,   490,   491,
     492,   493,   494,   495,   496,   497,   498,   499,   500,   501,
     502,   171,   172,   173,   174,   503,     0,     0,     0,   179,
       0,     0,     0,     0,  2157,     0,     0,     0,     0,     0,
     184,   185,   186,     0,     0,     0,     0,     0,   187,    21,
     489,   490,   491,   492,   493,   494,   495,   496,   497,   498,
     499,   500,   501,   502,     0,     0,     0,     0,   503,     0,
       0,     0,     0,     0,     0,     0,     0,  2158,     0,   192,
     193,   194,   195,   196,     0,     0,     0,     0,   197,   198,
     199,   200,   201,   202,     0,   203,   107,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     204,   205,     0,     0,     0,   206,     0,     0,     0,     0,
     361,     0,     0,     0,     0,   210,   489,   490,   491,   492,
     493,   494,   495,   496,   497,   498,   499,   500,   501,   502,
       0,     0,     0,     0,   503,     0,     0,     0,     0,     0,
       0,     0,     0,  2159,   192,     0,     0,     0,   196,     0,
       0,     0,     0,   197,   198,   199,   200,   201,     0,     0,
       0,   107,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   204,   205,     0,     0,     0,
     206,   133,   388,     0,     0,   361,   474,   136,   137,   138,
     210,     0,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,     0,     0,   489,   490,   491,
     492,   493,   494,   495,   496,   497,   498,   499,   500,   501,
     502,   171,   172,   173,   174,   503,     0,     0,     0,   179,
       0,     0,     0,     0,  2160,     0,     0,     0,     0,     0,
     184,   185,   186,     0,   133,   388,     0,     0,   187,    21,
     136,   137,   138,     0,     0,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,     0,     0,
     489,   490,   491,   492,   493,   494,   495,   496,   497,   498,
     499,   500,   501,   502,   171,   172,   173,   174,   503,     0,
       0,     0,   179,     0,     0,     0,     0,  2161,     0,     0,
       0,     0,     0,   184,   185,   186,     0,     0,     0,     0,
       0,   187,    21,   489,   490,   491,   492,   493,   494,   495,
     496,   497,   498,   499,   500,   501,   502,     0,     0,     0,
       0,   503,     0,     0,     0,     0,     0,     0,     0,     0,
    2162,     0,     0,     0,   192,     0,     0,     0,   196,     0,
       0,     0,     0,   197,   198,   199,   200,   201,     0,     0,
       0,   107,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   204,   205,     0,     0,     0,
     206,     0,     0,     0,     0,   361,     0,     0,   476,     0,
     210,     0,   489,   490,   491,   492,   493,   494,   495,   496,
     497,   498,   499,   500,   501,   502,     0,     0,     0,     0,
     503,     0,     0,     0,     0,     0,     0,   192,   934,     0,
       0,   196,     0,     0,     0,     0,   197,   198,   199,   200,
     201,     0,     0,     0,   107,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   204,   205,
       0,     0,     0,   206,   133,   388,     0,     0,   361,   697,
     136,   137,   138,   210,     0,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,     0,     0,
     489,   490,   491,   492,   493,   494,   495,   496,   497,   498,
     499,   500,   501,   502,   171,   172,   173,   174,   503,     0,
       0,     0,   179,     0,     0,     0,  1890,     0,     0,     0,
       0,     0,     0,   184,   185,   186,     0,   133,   388,     0,
    1284,   187,    21,   136,   137,   138,     0,     0,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,     0,     0,   489,   490,   491,   492,   493,   494,   495,
     496,   497,   498,   499,   500,   501,   502,   171,   172,   173,
     174,   503,     0,   980,     0,   179,     0,     0,   941,     0,
       0,     0,     0,     0,     0,     0,   184,   185,   186,     0,
       0,     0,     0,     0,   187,    21,   489,   490,   491,   492,
     493,   494,   495,   496,   497,   498,   499,   500,   501,   502,
       0,     0,     0,     0,   503,     0,   869,     0,   870,     0,
       0,  1525,     0,     0,     0,     0,     0,   192,     0,     0,
       0,   196,     0,     0,     0,     0,   197,   198,   199,   200,
     201,     0,     0,     0,   107,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   204,   205,
       0,     0,     0,   206,     0,     0,     0,     0,   361,     0,
       0,   699,     0,   210,   489,   490,   491,   492,   493,   494,
     495,   496,   497,   498,   499,   500,   501,   502,     0,     0,
       0,     0,   503,     0,     0,     0,     0,     0,     0,   823,
     192,     0,     0,     0,   196,     0,     0,     0,     0,   197,
     198,   199,   200,   201,     0,     0,     0,   107,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   204,   205,     0,     0,     0,   206,   133,   388,     0,
    1456,   361,     0,   136,   137,   138,   210,     0,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,     0,     0,   489,   490,   491,   492,   493,   494,   495,
     496,   497,   498,   499,   500,   501,   502,   171,   172,   173,
     174,   503,     0,     0,     0,   179,     0,     0,   941,     0,
       0,     0,     0,     0,     0,     0,   184,   185,   186,     0,
     133,   388,     0,     0,   187,    21,   136,   137,   138,     0,
       0,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,     0,     0,   489,   490,   491,   492,
     493,   494,   495,   496,   497,   498,   499,   500,   501,   502,
     171,   172,   173,   174,   503,     0,     0,     0,   179,     0,
       0,   942,     0,     0,     0,     0,     0,     0,     0,   184,
     185,   186,     0,     0,     0,     0,     0,   187,    21,   489,
     490,   491,   492,   493,   494,   495,   496,   497,   498,   499,
     500,   501,   502,     0,     0,     0,     0,   503,     0,     0,
       0,     0,     0,     0,   985,     0,     0,     0,     0,     0,
     192,     0,     0,     0,   196,     0,     0,     0,     0,   197,
     198,   199,   200,   201,     0,     0,     0,   107,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   204,   205,     0,     0,     0,   206,     0,     0,     0,
       0,   361,     0,     0,     0,     0,   210,     7,     8,   489,
     490,   491,   492,   493,   494,   495,   496,   497,   498,   499,
     500,   501,   502,     0,     0,     0,     0,   503,     0,     0,
       0,     0,     0,   192,  1029,     0,     0,   196,     0,     0,
       0,     0,   197,   198,   199,   200,   201,     7,     8,     0,
     107,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   204,   205,     0,     0,     0,   206,
       0,     0,     0,     0,   361,     0,     0,     0,     0,   210,
       0,   783,    25,    26,   784,    28,    29,   785,    31,   786,
      33,    34,    35,    36,     0,     0,     0,    38,    39,    40,
       0,     0,    42,     0,     0,     0,     0,     0,   787,    48,
       0,     0,    50,   788,     0,    53,   789,     0,     0,     0,
       0,   783,    25,    26,   784,    28,    29,   785,    31,   786,
      33,    34,    35,    36,    70,     0,     0,    38,    39,    40,
       0,     0,    42,     0,     0,     0,     0,     0,   787,    48,
       0,     0,    50,   788,     0,    53,   789,     0,    84,    85,
      86,     0,     0,     7,     8,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    70,     0,     0,     0,   489,   490,
     491,   492,   493,   494,   495,   496,   497,   498,   499,   500,
     501,   502,     0,     0,     0,     0,   503,     0,    84,    85,
      86,     7,     8,  1037,   489,   490,   491,   492,   493,   494,
     495,   496,   497,   498,   499,   500,   501,   502,     0,     0,
       0,     0,   503,     0,     0,     0,     0,     0,     0,  1038,
    1228,     0,     0,     0,     0,     0,     0,   783,    25,    26,
     784,    28,    29,   785,    31,   786,    33,    34,    35,    36,
       0,     0,     0,    38,    39,    40,     7,     8,    42,     0,
       0,     0,     0,     0,   787,    48,     0,     0,    50,   788,
    1247,    53,   789,     0,     0,   783,    25,    26,   784,    28,
      29,   785,    31,   786,    33,    34,    35,    36,     0,     0,
      70,    38,    39,    40,     0,     0,    42,     0,     0,     0,
       0,     0,   787,    48,     0,     0,    50,   788,     0,    53,
     789,     0,     0,     0,    84,    85,    86,     0,     0,     0,
       7,     8,     0,     0,     0,     0,     0,     0,    70,     0,
     783,    25,    26,   784,    28,    29,   785,    31,   786,    33,
      34,    35,    36,     0,     0,     0,    38,    39,    40,     0,
       0,    42,    84,    85,    86,     0,     0,   787,    48,     7,
       8,    50,   788,     0,    53,   789,   489,   490,   491,   492,
     493,   494,   495,   496,   497,   498,   499,   500,   501,   502,
       0,     0,     0,    70,   503,     0,  1276,     0,     0,     0,
       0,  1039,     0,     0,   783,    25,    26,   784,    28,    29,
     785,    31,   786,    33,    34,    35,    36,    84,    85,    86,
      38,    39,    40,     0,     0,    42,     0,     0,     0,     0,
       0,   787,    48,     0,  1282,    50,   788,     0,    53,   789,
       0,     0,     0,   783,    25,    26,   784,    28,    29,   785,
      31,   786,    33,    34,    35,    36,     0,    70,     0,    38,
      39,    40,     0,     0,    42,     0,     0,     0,     0,     0,
     787,    48,     0,     0,    50,   788,     0,    53,   789,     0,
       0,    84,    85,    86,     0,     0,    -4,     1,     0,  1448,
      -4,     0,     0,     0,     0,     0,    70,     0,    -4,    -4,
     489,   490,   491,   492,   493,   494,   495,   496,   497,   498,
     499,   500,   501,   502,     0,     0,     0,     0,   503,     0,
      84,    85,    86,     0,     0,  1054,     0,     0,    -4,    -4,
       0,     0,     0,   489,   490,   491,   492,   493,   494,   495,
     496,   497,   498,   499,   500,   501,   502,     0,    -4,    -4,
      -4,   503,     0,  2026,    -4,    -4,     0,    -4,  1184,     0,
       0,    -4,    -4,     0,    -4,    -4,     0,    -4,     0,     0,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,     0,     0,    -4,    -4,    -4,
      -4,    -4,  2093,    -4,     0,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,     0,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,     0,     0,     6,    -4,    -4,    -4,
       0,     0,     0,    -4,     7,     8,     0,     0,    -4,    -4,
      -4,    -4,     0,     0,    -4,     0,    -4,     0,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,     0,     0,     9,    10,     0,     0,    -4,    -4,
      -4,     0,     0,     0,     0,     0,     0,    -4,     0,    -4,
       0,     0,     0,     0,    11,    12,    13,     0,     0,     0,
      14,    15,     0,    16,     0,     0,     0,    17,    18,     0,
      19,    20,     0,    21,     0,     0,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,     0,     0,    37,    38,    39,    40,    41,     0,    42,
       0,    43,    44,    45,    46,    47,    48,    49,     0,    50,
      51,    52,    53,    54,    55,     0,    56,    57,    58,    59,
      60,    61,    62,    63,    64,     0,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
       7,     8,     0,    79,    80,    81,     0,     0,     0,    82,
       0,     0,     0,     0,    83,    84,    85,    86,     0,     0,
      87,     0,    88,     0,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,     0,     0,
       0,     0,     0,     0,   103,   104,   105,     0,     0,     0,
       0,     0,     0,   106,     0,   107,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   783,    25,    26,   784,    28,    29,
     785,    31,   786,    33,    34,    35,    36,     0,     0,     0,
      38,    39,    40,     0,     0,    42,     0,     0,     0,     0,
       0,   787,    48,     0,     0,    50,   788,     0,    53,   789,
     489,   490,   491,   492,   493,   494,   495,   496,   497,   498,
     499,   500,   501,   502,     0,     0,     0,    70,   503,     0,
       0,     0,     0,     0,     0,  1185,   489,   490,   491,   492,
     493,   494,   495,   496,   497,   498,   499,   500,   501,   502,
       0,    84,    85,    86,   503,     0,     0,     0,     0,     0,
       0,  1187,   489,   490,   491,   492,   493,   494,   495,   496,
     497,   498,   499,   500,   501,   502,     0,     0,     0,     0,
     503,     0,     0,     0,     0,     0,     0,  1270,   489,   490,
     491,   492,   493,   494,   495,   496,   497,   498,   499,   500,
     501,   502,     0,     0,     0,     0,   503,     0,     0,     0,
       0,     0,     0,  1376,   489,   490,   491,   492,   493,   494,
     495,   496,   497,   498,   499,   500,   501,   502,     0,     0,
       0,     0,   503,     0,     0,     0,     0,     0,     0,  1450,
     489,   490,   491,   492,   493,   494,   495,   496,   497,   498,
     499,   500,   501,   502,     0,     0,     0,     0,   503,     0,
       0,     0,     0,     0,     0,  1451,   489,   490,   491,   492,
     493,   494,   495,   496,   497,   498,   499,   500,   501,   502,
       0,     0,     0,     0,   503,     0,     0,     0,     0,     0,
       0,  1493,   489,   490,   491,   492,   493,   494,   495,   496,
     497,   498,   499,   500,   501,   502,     0,     0,     0,     0,
     503,     0,     0,     0,     0,     0,     0,  1620,   489,   490,
     491,   492,   493,   494,   495,   496,   497,   498,   499,   500,
     501,   502,     0,     0,     0,     0,   503,     0,     0,     0,
       0,     0,     0,  1621,   489,   490,   491,   492,   493,   494,
     495,   496,   497,   498,   499,   500,   501,   502,     0,     0,
       0,     0,   503,     0,     0,     0,     0,     0,     0,  1622,
     489,   490,   491,   492,   493,   494,   495,   496,   497,   498,
     499,   500,   501,   502,     0,     0,     0,     0,   503,     0,
       0,     0,     0,     0,     0,  1623,   489,   490,   491,   492,
     493,   494,   495,   496,   497,   498,   499,   500,   501,   502,
       0,     0,     0,     0,   503,     0,     0,     0,     0,     0,
       0,  1624,   489,   490,   491,   492,   493,   494,   495,   496,
     497,   498,   499,   500,   501,   502,     0,     0,     0,     0,
     503,     0,     0,     0,     0,     0,     0,  1625,   489,   490,
     491,   492,   493,   494,   495,   496,   497,   498,   499,   500,
     501,   502,     0,     0,     0,     0,   503,     0,     0,     0,
       0,     0,     0,  1626,   489,   490,   491,   492,   493,   494,
     495,   496,   497,   498,   499,   500,   501,   502,     0,     0,
       0,     0,   503,     0,     0,     0,     0,     0,     0,  1735,
     489,   490,   491,   492,   493,   494,   495,   496,   497,   498,
     499,   500,   501,   502,     0,     0,     0,     0,   503,     0,
       0,     0,     0,     0,     0,  1736,   489,   490,   491,   492,
     493,   494,   495,   496,   497,   498,   499,   500,   501,   502,
       0,     0,     0,     0,   503,     0,     0,     0,     0,     0,
       0,  1743,   489,   490,   491,   492,   493,   494,   495,   496,
     497,   498,   499,   500,   501,   502,     0,     0,     0,     0,
     503,     0,     0,     0,     0,     0,     0,  1880,   489,   490,
     491,   492,   493,   494,   495,   496,   497,   498,   499,   500,
     501,   502,     0,     0,     0,     0,   503,     0,     0,     0,
       0,     0,     0,  1881,   489,   490,   491,   492,   493,   494,
     495,   496,   497,   498,   499,   500,   501,   502,     0,     0,
       0,     0,   503,     0,     0,     0,     0,     0,     0,  1882,
     489,   490,   491,   492,   493,   494,   495,   496,   497,   498,
     499,   500,   501,   502,     0,     0,     0,     0,   503,     0,
       0,     0,     0,     0,     0,  1883,   489,   490,   491,   492,
     493,   494,   495,   496,   497,   498,   499,   500,   501,   502,
       0,     0,     0,     0,   503,     0,     0,     0,     0,     0,
       0,  1884,   489,   490,   491,   492,   493,   494,   495,   496,
     497,   498,   499,   500,   501,   502,     0,     0,     0,     0,
     503,     0,     0,     0,     0,     0,     0,  1936,   489,   490,
     491,   492,   493,   494,   495,   496,   497,   498,   499,   500,
     501,   502,     0,     0,     0,     0,   503,     0,     0,     0,
       0,     0,     0,  1937,   489,   490,   491,   492,   493,   494,
     495,   496,   497,   498,   499,   500,   501,   502,     0,     0,
       0,     0,   503,     0,     0,     0,     0,     0,     0,  1941,
     489,   490,   491,   492,   493,   494,   495,   496,   497,   498,
     499,   500,   501,   502,     0,     0,     0,     0,   503,     0,
       0,     0,     0,     0,     0,  2008,   489,   490,   491,   492,
     493,   494,   495,   496,   497,   498,   499,   500,   501,   502,
       0,     0,     0,     0,   503,     0,     0,     0,     0,     0,
       0,  2009,   489,   490,   491,   492,   493,   494,   495,   496,
     497,   498,   499,   500,   501,   502,     0,     0,     0,     0,
     503,     0,     0,     0,     0,     0,     0,  2010,   489,   490,
     491,   492,   493,   494,   495,   496,   497,   498,   499,   500,
     501,   502,     0,     0,     0,     0,   503,     0,     0,     0,
       0,     0,     0,  2011,   489,   490,   491,   492,   493,   494,
     495,   496,   497,   498,   499,   500,   501,   502,     0,     0,
       0,     0,   503,     0,     0,     0,     0,     0,     0,  2012,
     489,   490,   491,   492,   493,   494,   495,   496,   497,   498,
     499,   500,   501,   502,     0,     0,     0,     0,   503,     0,
       0,     0,     0,     0,     0,  2044,   489,   490,   491,   492,
     493,   494,   495,   496,   497,   498,   499,   500,   501,   502,
       0,     0,     0,     0,   503,     0,     0,     0,     0,     0,
       0,  2047,   489,   490,   491,   492,   493,   494,   495,   496,
     497,   498,   499,   500,   501,   502,     0,     0,     0,     0,
     503,     0,     0,     0,     0,     0,     0,  2083,   489,   490,
     491,   492,   493,   494,   495,   496,   497,   498,   499,   500,
     501,   502,     0,     0,     0,     0,   503,     0,     0,     0,
       0,     0,     0,  2084,   489,   490,   491,   492,   493,   494,
     495,   496,   497,   498,   499,   500,   501,   502,     0,     0,
       0,     0,   503,     0,     0,     0,     0,     0,     0,  2085,
     489,   490,   491,   492,   493,   494,   495,   496,   497,   498,
     499,   500,   501,   502,     0,     0,     0,     0,   503,     0,
       0,     0,     0,     0,     0,  2086,   489,   490,   491,   492,
     493,   494,   495,   496,   497,   498,   499,   500,   501,   502,
       0,     0,     0,     0,   503,     0,     0,     0,     0,     0,
       0,  2087,   489,   490,   491,   492,   493,   494,   495,   496,
     497,   498,   499,   500,   501,   502,     0,     0,     0,     0,
     503,     0,     0,     0,     0,     0,     0,  2088,   489,   490,
     491,   492,   493,   494,   495,   496,   497,   498,   499,   500,
     501,   502,     0,     0,     0,     0,   503,     0,     0,     0,
       0,     0,     0,  2132,   489,   490,   491,   492,   493,   494,
     495,   496,   497,   498,   499,   500,   501,   502,     0,     0,
       0,     0,   503,     0,     0,     0,     0,     0,     0,  2133,
     489,   490,   491,   492,   493,   494,   495,   496,   497,   498,
     499,   500,   501,   502,     0,     0,     0,     0,   503,     0,
       0,     0,     0,     0,     0,  2134,   489,   490,   491,   492,
     493,   494,   495,   496,   497,   498,   499,   500,   501,   502,
       0,     0,     0,     0,   503,     0,     0,     0,     0,     0,
       0,  2135,   489,   490,   491,   492,   493,   494,   495,   496,
     497,   498,   499,   500,   501,   502,     0,     0,     0,     0,
     503,     0,   869,     0,   870,   489,   490,   491,   492,   493,
     494,   495,   496,   497,   498,   499,   500,   501,   502,     0,
       0,     0,     0,   503,     0,     0,     0,   775,   489,   490,
     491,   492,   493,   494,   495,   496,   497,   498,   499,   500,
     501,   502,     0,     0,     0,     0,   503,     0,     0,     0,
     991,   489,   490,   491,   492,   493,   494,   495,   496,   497,
     498,   499,   500,   501,   502,     0,     0,     0,     0,   503,
       0,     0,     0,  1010,   489,   490,   491,   492,   493,   494,
     495,   496,   497,   498,   499,   500,   501,   502,     0,     0,
       0,     0,   503,     0,     0,     0,  1017,   489,   490,   491,
     492,   493,   494,   495,   496,   497,   498,   499,   500,   501,
     502,     0,     0,     0,     0,   503,     0,     0,     0,  1124,
     489,   490,   491,   492,   493,   494,   495,   496,   497,   498,
     499,   500,   501,   502,     0,     0,     0,     0,   503,     0,
       0,     0,  1177,   489,   490,   491,   492,   493,   494,   495,
     496,   497,   498,   499,   500,   501,   502,     0,     0,     0,
       0,   503,     0,     0,     0,  1199,   489,   490,   491,   492,
     493,   494,   495,   496,   497,   498,   499,   500,   501,   502,
       0,     0,     0,     0,   503,     0,     0,     0,  1263,   489,
     490,   491,   492,   493,   494,   495,   496,   497,   498,   499,
     500,   501,   502,     0,     0,     0,     0,   503,     0,     0,
       0,  1264,   489,   490,   491,   492,   493,   494,   495,   496,
     497,   498,   499,   500,   501,   502,     0,     0,     0,     0,
     503,     0,     0,     0,  1268,   489,   490,   491,   492,   493,
     494,   495,   496,   497,   498,   499,   500,   501,   502,     0,
       0,     0,     0,   503,     0,     0,     0,  1269,   489,   490,
     491,   492,   493,   494,   495,   496,   497,   498,   499,   500,
     501,   502,     0,     0,     0,     0,   503,     0,     0,     0,
    1302,   489,   490,   491,   492,   493,   494,   495,   496,   497,
     498,   499,   500,   501,   502,     0,     0,     0,     0,   503,
       0,     0,     0,  1369,   489,   490,   491,   492,   493,   494,
     495,   496,   497,   498,   499,   500,   501,   502,     0,     0,
       0,     0,   503,     0,     0,     0,  1374,   489,   490,   491,
     492,   493,   494,   495,   496,   497,   498,   499,   500,   501,
     502,     0,     0,     0,     0,   503,     0,     0,     0,  1678,
     489,   490,   491,   492,   493,   494,   495,   496,   497,   498,
     499,   500,   501,   502,     0,     0,     0,     0,   503,     0,
       0,     0,  1722,   489,   490,   491,   492,   493,   494,   495,
     496,   497,   498,   499,   500,   501,   502,     0,     0,     0,
       0,   503,     0,     0,     0,  1898,   489,   490,   491,   492,
     493,   494,   495,   496,   497,   498,   499,   500,   501,   502,
       0,     0,     0,     0,   503,     0,   836,   489,   490,   491,
     492,   493,   494,   495,   496,   497,   498,   499,   500,   501,
     502,     0,     0,     0,     0,   503,     0,   840,   489,   490,
     491,   492,   493,   494,   495,   496,   497,   498,   499,   500,
     501,   502,     0,     0,     0,     0,   503,     0,   841,   489,
     490,   491,   492,   493,   494,   495,   496,   497,   498,   499,
     500,   501,   502,     0,     0,     0,     0,   503,     0,   843,
     489,   490,   491,   492,   493,   494,   495,   496,   497,   498,
     499,   500,   501,   502,     0,     0,     0,     0,   503,     0,
     845,   489,   490,   491,   492,   493,   494,   495,   496,   497,
     498,   499,   500,   501,   502,     0,     0,     0,     0,   503,
       0,   846,   489,   490,   491,   492,   493,   494,   495,   496,
     497,   498,   499,   500,   501,   502,     0,     0,     0,     0,
     503,     0,   848,   489,   490,   491,   492,   493,   494,   495,
     496,   497,   498,   499,   500,   501,   502,     0,     0,     0,
       0,   503,     0,   850,   489,   490,   491,   492,   493,   494,
     495,   496,   497,   498,   499,   500,   501,   502,     0,     0,
       0,     0,   503,     0,   851,   489,   490,   491,   492,   493,
     494,   495,   496,   497,   498,   499,   500,   501,   502,     0,
       0,     0,     0,   503,     0,   852,   489,   490,   491,   492,
     493,   494,   495,   496,   497,   498,   499,   500,   501,   502,
       0,     0,     0,     0,   503,     0,   853,   489,   490,   491,
     492,   493,   494,   495,   496,   497,   498,   499,   500,   501,
     502,     0,     0,     0,     0,   503,     0,   854,   489,   490,
     491,   492,   493,   494,   495,   496,   497,   498,   499,   500,
     501,   502,     0,     0,     0,     0,   503,     0,   855,   489,
     490,   491,   492,   493,   494,   495,   496,   497,   498,   499,
     500,   501,   502,     0,     0,     0,     0,   503,     0,   857,
     489,   490,   491,   492,   493,   494,   495,   496,   497,   498,
     499,   500,   501,   502,     0,     0,     0,     0,   503,     0,
     858,   489,   490,   491,   492,   493,   494,   495,   496,   497,
     498,   499,   500,   501,   502,     0,     0,     0,     0,   503,
       0,   859,   489,   490,   491,   492,   493,   494,   495,   496,
     497,   498,   499,   500,   501,   502,     0,     0,     0,     0,
     503,     0,   894,   489,   490,   491,   492,   493,   494,   495,
     496,   497,   498,   499,   500,   501,   502,     0,     0,     0,
       0,   503,     0,   905,   489,   490,   491,   492,   493,   494,
     495,   496,   497,   498,   499,   500,   501,   502,     0,     0,
       0,     0,   503,     0,   962,   489,   490,   491,   492,   493,
     494,   495,   496,   497,   498,   499,   500,   501,   502,     0,
       0,     0,     0,   503,     0,   980,   489,   490,   491,   492,
     493,   494,   495,   496,   497,   498,   499,   500,   501,   502,
       0,     0,     0,     0,   503,     0,   981,   489,   490,   491,
     492,   493,   494,   495,   496,   497,   498,   499,   500,   501,
     502,     0,     0,     0,     0,   503,     0,   982,   489,   490,
     491,   492,   493,   494,   495,   496,   497,   498,   499,   500,
     501,   502,     0,     0,     0,     0,   503,     0,   983,   489,
     490,   491,   492,   493,   494,   495,   496,   497,   498,   499,
     500,   501,   502,     0,     0,     0,     0,   503,     0,   989,
     489,   490,   491,   492,   493,   494,   495,   496,   497,   498,
     499,   500,   501,   502,     0,     0,     0,     0,   503,     0,
     990,   489,   490,   491,   492,   493,   494,   495,   496,   497,
     498,   499,   500,   501,   502,     0,     0,     0,     0,   503,
       0,   997,   489,   490,   491,   492,   493,   494,   495,   496,
     497,   498,   499,   500,   501,   502,     0,     0,     0,     0,
     503,     0,  1006,   489,   490,   491,   492,   493,   494,   495,
     496,   497,   498,   499,   500,   501,   502,     0,     0,     0,
       0,   503,     0,  1016,   489,   490,   491,   492,   493,   494,
     495,   496,   497,   498,   499,   500,   501,   502,     0,     0,
       0,     0,   503,     0,  1123,   489,   490,   491,   492,   493,
     494,   495,   496,   497,   498,   499,   500,   501,   502,     0,
       0,     0,     0,   503,     0,  1155,   489,   490,   491,   492,
     493,   494,   495,   496,   497,   498,   499,   500,   501,   502,
       0,     0,     0,     0,   503,     0,  1160,   489,   490,   491,
     492,   493,   494,   495,   496,   497,   498,   499,   500,   501,
     502,     0,     0,     0,     0,   503,     0,  1173,   489,   490,
     491,   492,   493,   494,   495,   496,   497,   498,   499,   500,
     501,   502,     0,     0,     0,     0,   503,     0,  1176,   489,
     490,   491,   492,   493,   494,   495,   496,   497,   498,   499,
     500,   501,   502,     0,     0,     0,     0,   503,     0,  1198,
     489,   490,   491,   492,   493,   494,   495,   496,   497,   498,
     499,   500,   501,   502,     0,     0,     0,     0,   503,     0,
    1203,   489,   490,   491,   492,   493,   494,   495,   496,   497,
     498,   499,   500,   501,   502,     0,     0,     0,     0,   503,
       0,  1204,   489,   490,   491,   492,   493,   494,   495,   496,
     497,   498,   499,   500,   501,   502,     0,     0,     0,     0,
     503,     0,  1205,   489,   490,   491,   492,   493,   494,   495,
     496,   497,   498,   499,   500,   501,   502,     0,     0,     0,
       0,   503,     0,  1219,   489,   490,   491,   492,   493,   494,
     495,   496,   497,   498,   499,   500,   501,   502,     0,     0,
       0,     0,   503,     0,  1220,   489,   490,   491,   492,   493,
     494,   495,   496,   497,   498,   499,   500,   501,   502,     0,
       0,     0,     0,   503,     0,  1221,   489,   490,   491,   492,
     493,   494,   495,   496,   497,   498,   499,   500,   501,   502,
       0,     0,     0,     0,   503,     0,  1249,   489,   490,   491,
     492,   493,   494,   495,   496,   497,   498,   499,   500,   501,
     502,     0,     0,     0,     0,   503,     0,  1251,   489,   490,
     491,   492,   493,   494,   495,   496,   497,   498,   499,   500,
     501,   502,     0,     0,     0,     0,   503,     0,  1252,   489,
     490,   491,   492,   493,   494,   495,   496,   497,   498,   499,
     500,   501,   502,     0,     0,     0,     0,   503,     0,  1253,
     489,   490,   491,   492,   493,   494,   495,   496,   497,   498,
     499,   500,   501,   502,     0,     0,     0,     0,   503,     0,
    1254,   489,   490,   491,   492,   493,   494,   495,   496,   497,
     498,   499,   500,   501,   502,     0,     0,     0,     0,   503,
       0,  1255,   489,   490,   491,   492,   493,   494,   495,   496,
     497,   498,   499,   500,   501,   502,     0,     0,     0,     0,
     503,     0,  1256,   489,   490,   491,   492,   493,   494,   495,
     496,   497,   498,   499,   500,   501,   502,     0,     0,     0,
       0,   503,     0,  1257,   489,   490,   491,   492,   493,   494,
     495,   496,   497,   498,   499,   500,   501,   502,     0,     0,
       0,     0,   503,     0,  1262,   489,   490,   491,   492,   493,
     494,   495,   496,   497,   498,   499,   500,   501,   502,     0,
       0,     0,     0,   503,     0,  1368,   489,   490,   491,   492,
     493,   494,   495,   496,   497,   498,   499,   500,   501,   502,
       0,     0,     0,     0,   503,     0,  1373,   489,   490,   491,
     492,   493,   494,   495,   496,   497,   498,   499,   500,   501,
     502,     0,     0,     0,     0,   503,     0,  1538,   489,   490,
     491,   492,   493,   494,   495,   496,   497,   498,   499,   500,
     501,   502,     0,     0,     0,     0,   503,     0,  1563,   489,
     490,   491,   492,   493,   494,   495,   496,   497,   498,   499,
     500,   501,   502,     0,     0,     0,     0,   503,     0,  1728,
     489,   490,   491,   492,   493,   494,   495,   496,   497,   498,
     499,   500,   501,   502,     0,     0,     0,     0,   503,     0,
    1729,   489,   490,   491,   492,   493,   494,   495,   496,   497,
     498,   499,   500,   501,   502,     0,     0,     0,     0,   503,
       0,  1730,   489,   490,   491,   492,   493,   494,   495,   496,
     497,   498,   499,   500,   501,   502,     0,     0,     0,     0,
     503,     0,  1731,   489,   490,   491,   492,   493,   494,   495,
     496,   497,   498,   499,   500,   501,   502,     0,     0,     0,
       0,   503,     0,  1789,   489,   490,   491,   492,   493,   494,
     495,   496,   497,   498,   499,   500,   501,   502,     0,     0,
       0,     0,   503,     0,  1798,   489,   490,   491,   492,   493,
     494,   495,   496,   497,   498,   499,   500,   501,   502,     0,
       0,     0,     0,   503,     0,  1821,   489,   490,   491,   492,
     493,   494,   495,   496,   497,   498,   499,   500,   501,   502,
       0,     0,     0,     0,   503,     0,  2043,   489,   490,   491,
     492,   493,   494,   495,   496,   497,   498,   499,   500,   501,
     502,     0,     0,     0,     0,   503,     0,  2106,   489,   490,
     491,   492,   493,   494,   495,   496,   497,   498,   499,   500,
     501,   502,     0,     0,     0,     0,   503
};

static const yytype_int16 yycheck[] =
{
       3,   319,     3,     6,   436,  1248,   438,   594,     6,   629,
     630,  1244,     4,  1381,  1689,  1690,  1666,     6,    21,     4,
       6,   453,     6,     4,     4,     4,     4,     4,     4,     4,
       4,     4,   331,     5,     5,     5,     5,    92,   132,     4,
       6,     4,     4,     0,    47,     5,   270,   271,   272,   348,
     474,     5,   476,    92,   478,     6,     6,    92,     7,     6,
     217,   218,     6,    60,    61,     4,    63,   217,   218,     7,
       6,    74,   123,     4,   113,     6,   233,     4,   113,    82,
     227,   305,   306,   307,    87,   235,   385,   234,   387,   140,
      89,   217,   218,    92,   393,    98,     6,   148,   149,   150,
      98,   227,   100,   154,   155,   228,     6,   230,   234,   123,
     233,    86,  1762,   217,   218,    90,   217,   218,   342,   343,
     344,    96,    97,    13,    99,   100,   140,   123,     4,   233,
       7,   355,   356,   234,   148,   149,   150,   228,   227,   230,
     154,   155,   117,   234,   140,     7,   217,   218,   168,   227,
     224,   225,   148,   149,   150,    86,   227,   231,   154,   155,
     217,   218,     7,   234,   184,   185,   158,   159,   160,   161,
       7,   217,   218,   217,   218,   217,   218,   234,   231,   217,
     218,   217,   218,   236,   235,   219,   220,   221,   234,   233,
     156,   233,   226,    89,   179,   233,    92,   233,    94,   171,
     171,   171,   171,   168,   169,   183,   227,   210,     8,   156,
     211,  1861,   227,   217,   218,   227,     6,   229,   203,   234,
     223,   224,   234,   203,   236,     7,   203,   227,   231,   233,
     214,   217,   218,   820,   234,  1468,     6,  1887,   227,   235,
     243,     6,   245,   235,   242,   234,   227,   250,   229,   234,
     229,   227,   255,   227,   234,   236,     6,   236,   234,   262,
     234,   234,   234,   266,   227,   227,   269,   270,   271,   272,
     273,   234,   234,   697,   234,   699,   203,     6,   214,   227,
     234,   284,   231,   234,   234,   288,   234,   290,   227,   227,
       7,   229,   168,   169,     3,     7,     6,     6,   301,   224,
     225,   304,   305,   306,   307,   232,   231,   217,   218,   312,
     313,   314,    21,   224,   225,   318,   319,   217,   218,   228,
     231,   620,   621,   234,   233,   322,   323,   204,   205,   206,
     207,     4,     6,   330,   331,     6,   224,   225,   637,   342,
     343,   344,   204,   205,   206,   207,   234,   771,   217,   218,
     229,   775,   355,   356,   578,   579,   580,   581,   229,   204,
     205,   206,   207,  2038,   233,    74,   227,   204,   205,   206,
     207,     7,   228,   224,   225,   674,   106,   233,    87,   224,
     225,   217,   218,   234,   478,   227,   231,   229,   391,    98,
     689,     6,   395,   396,   236,   227,  2046,   233,     7,   228,
     227,   230,     7,   227,   402,   234,   409,   234,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   204,   205,   206,   207,   226,   228,   228,   230,
     217,   218,   233,   436,   437,   438,   439,   440,   441,   442,
     443,   444,   445,   446,   447,   448,   233,   450,   451,   452,
     453,   454,   227,   456,   127,   128,   129,   130,     8,   457,
     463,   464,   465,   466,   467,   468,   227,   470,   227,   142,
     229,   469,   145,   223,   224,   217,   218,   236,  2128,   123,
      86,   217,   218,    89,   487,    92,    92,   204,   205,   206,
     207,   233,   204,   205,   206,   207,   140,   233,  1866,   224,
     225,   210,   217,   218,   148,   149,   150,   224,   225,   234,
     154,   155,   262,   227,   223,   224,   217,   218,   233,   217,
     218,   227,   231,   273,   227,   528,   229,   217,   218,   219,
     220,   221,   233,   236,   243,   233,   226,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   217,   218,   262,   234,   226,   217,   218,    89,   562,
     563,    92,   227,   566,   273,   217,   218,   233,   204,   205,
     206,   207,   233,   227,   577,   578,   579,   580,   581,   582,
     583,   233,  1006,   224,   225,   228,  1010,   590,   224,   225,
     233,   235,   227,   234,     8,   204,   205,   206,   207,   204,
     205,   206,   207,   224,   225,   227,   604,   605,   606,   607,
     319,   614,   615,   234,   227,   224,   225,   217,   218,   224,
     225,    92,   230,   217,   218,   233,   217,   218,   629,   630,
     627,   628,   227,   233,   229,   632,  2004,  2005,   937,   233,
     227,   391,   233,   227,   227,   229,   229,   227,   127,   128,
     224,   225,   236,   236,   133,   658,   659,   660,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   217,   218,   127,   128,   226,   771,   227,   682,
     133,   775,   391,   230,   227,   235,   233,   437,   233,   439,
     440,   441,   442,   443,   444,   445,   234,   447,   448,   702,
     450,   451,   452,   227,   454,   229,    89,   230,   227,    92,
     233,    94,   236,   463,   464,   465,   466,   467,   812,   224,
     225,   227,   233,   229,   235,   230,   231,   436,   437,   438,
     439,   440,   441,   442,   443,   444,   445,    89,   447,   448,
     234,   450,   451,   452,   453,   454,    92,   456,    94,   123,
     233,   227,   235,   229,   463,   464,   465,   466,   467,   468,
     236,   470,    86,    89,   228,    89,   140,   770,    92,   233,
      94,   774,   228,   234,   148,   149,   150,   233,   776,  1097,
     154,   155,    86,   227,  2027,    89,    92,  1211,    92,  1213,
      94,  1215,   227,  1217,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,    89,   233,
     904,   235,   226,   228,   817,   230,   566,    92,   233,   822,
       4,   235,   825,     4,   228,   828,   230,   830,   831,   233,
     833,  2064,     4,    89,   837,   838,    92,   835,    94,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,  2094,     6,     4,   563,   226,    86,   566,   228,    89,
     230,   235,    92,   233,    94,     6,   228,   228,   871,   230,
     873,   233,   233,   876,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   233,  2117,   235,   228,   226,    12,    13,
     228,   233,   230,   227,   897,   233,   227,  1329,  1330,   902,
       6,     7,  1334,  1335,   233,   233,   235,   235,   911,   228,
     227,   230,  1006,  1337,   227,   233,  1010,   235,   233,   233,
     235,   235,  1016,  1017,     6,   233,     6,   235,   233,   227,
     235,   934,     6,   233,  1358,   235,   233,   233,   235,   235,
     233,   229,   235,   940,   233,    92,   235,    94,   227,    92,
     947,    94,     7,   233,   951,   235,   233,   233,   235,   235,
       6,     7,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,     6,   217,   218,   102,   103,
     104,   227,   233,   107,   235,   233,   233,   235,   235,   113,
     114,   229,   227,   117,   118,   227,   120,   121,  1001,   233,
     227,   235,  1005,   229,   227,   233,  1009,   235,   233,   233,
     235,   235,   227,   227,  1017,   139,   233,   233,   235,   235,
     233,   233,   235,   235,   227,     4,  1344,     6,   234,  1123,
    1124,  1651,  1652,   233,   233,   235,   235,   227,  1041,   163,
     164,   165,   233,  1046,   235,   233,     6,   235,  1051,  1052,
    1053,  1054,   234,     6,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,  1071,   233,
    1073,   235,   226,  1505,  1506,   825,   234,   236,  1510,  1511,
     830,   236,  1176,  1177,   233,   233,   235,   235,   233,     8,
     235,  1515,   227,   233,  1097,   235,   227,  1100,  1101,  1102,
    1103,   233,   227,   235,  1198,  1199,   233,   233,   235,   235,
     233,   235,   235,   233,   113,   235,   825,   234,   233,   828,
     235,   830,   831,   233,   833,   235,   227,  1130,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   233,   233,   235,   235,   226,   233,   227,   235,
    1153,  1154,  1149,  1156,   227,  1158,  1159,   233,  1161,   235,
    1163,  1164,  1165,  1166,  1167,  1168,  1169,  1170,  1171,     4,
       5,  1174,   233,   233,   235,   235,   227,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   233,  1195,   235,   233,   226,   235,   227,  1201,  1202,
     233,  1500,   235,  1502,   233,   233,   235,   235,   227,    44,
      45,    46,    47,    48,    49,    50,    51,    52,   233,     4,
     235,   234,    57,    58,    59,    60,   234,   234,   229,   227,
      65,    66,    67,   227,   227,    70,   227,   227,   227,  1557,
       7,     8,   227,  1337,   227,     6,     6,    82,    83,   229,
     234,   229,   234,   234,   229,  1258,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,  1017,  1271,  1272,
    1273,   226,     6,  1893,     6,   234,   171,     6,     6,     6,
     234,     6,   234,   234,  1287,   120,     6,   229,   234,   234,
     234,   234,   226,   231,     7,   234,  1046,     4,   235,   231,
       8,   234,  1052,  1053,  1054,   233,   233,   228,  1017,     7,
       6,     6,     6,   228,    62,    62,    62,    62,     7,     7,
       6,  1071,     6,  1073,     6,   228,  1329,  1330,     6,   234,
       7,  1334,  1335,     6,     6,   168,     7,  1046,     6,     6,
       6,  1344,   234,  1052,  1053,  1054,   230,   228,     6,     6,
     228,   228,   187,   188,   189,     8,     6,   233,   233,   233,
    1363,   233,  1071,   233,  1073,   200,   233,   202,   203,   233,
     228,   228,   228,     4,    44,   230,   227,     6,     6,  1377,
    1130,    44,    44,    44,     6,     6,  1389,   229,  1097,   224,
     225,     7,  1395,   171,     7,     7,   231,     7,   171,   234,
       7,     7,     6,   171,    12,    13,     7,     7,     7,     7,
    1842,     7,     7,     7,     7,     7,     7,   234,     6,   228,
     230,  1130,   234,  1517,  1427,  1428,  1429,   234,   234,   234,
    1433,     7,  1435,     7,  1437,   234,  1439,     4,  1441,  1442,
    1443,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,  1458,     6,   228,   233,   226,
       7,   233,   228,   228,   233,   228,  1469,   123,     6,   233,
    1467,     7,   231,   235,  1477,     7,     7,  1480,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,   235,   231,     7,   102,   103,   104,   235,   234,   107,
       6,  1499,  1505,  1506,    44,   113,   114,  1510,  1511,   117,
     118,     6,   120,   121,    44,    44,    44,     8,     6,     6,
       6,  1524,  1616,     6,     6,   229,     7,  1530,     6,   234,
     227,   139,     6,     6,  1852,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,     7,
     235,  1549,   227,   226,  1557,   163,   164,   165,     6,   214,
       7,    94,   227,   227,     7,  1568,     7,   227,   227,     7,
       7,     6,     4,     7,     7,  1578,     7,     7,  1581,     7,
     104,     4,   234,  1581,     6,   227,     7,     6,   234,     7,
       7,     7,     7,     7,     7,  1592,     7,     6,     6,     6,
      92,     7,     6,  1902,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,     6,     4,
    1329,  1330,   226,     4,     4,  1334,  1335,   235,   233,     6,
       6,   234,   234,     6,     6,  1344,     6,     4,   235,   228,
    1643,  1644,     6,   233,   228,   231,   233,   232,     7,  1647,
    1651,  1652,   227,   234,   231,     6,     6,   228,   230,     6,
       6,   234,   117,  1666,   234,     6,   234,     6,   234,  1672,
    1667,  1668,  1669,  1670,  1671,  1672,     6,   171,  1681,   234,
       6,     6,     6,     6,     6,     6,     6,     6,  1691,  1687,
    1989,     6,     5,     4,   228,   230,     6,     6,  1701,     4,
       6,   167,     6,  1706,     7,     6,   229,   234,  1706,   234,
    1708,  1709,   234,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   234,     6,  2028,
     234,   226,   234,   234,  1737,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   234,
     234,     6,     6,   226,   234,   234,     6,   234,   233,  1762,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,  1524,     6,     4,     6,   226,     6,
    1530,     6,     4,     6,   234,     6,     6,     6,     6,     4,
       7,     7,     6,     6,  1797,     6,  1505,  1506,     6,     6,
      90,  1510,  1511,     6,     5,   234,  1809,     6,     6,     6,
       6,     6,     6,     6,     6,  1524,     6,     6,     6,  1822,
       6,  1530,     6,   233,     6,     6,   228,  1825,  1578,     6,
     233,     6,     6,     6,   231,     7,  1839,     6,     6,  1842,
     234,     6,   234,   234,   234,     5,   235,     6,  1557,  1852,
     234,     6,   234,     6,   166,     7,   235,     6,  1861,   234,
       6,   235,     6,     6,   235,  1868,  1869,   235,     6,  1578,
       6,     6,   169,     6,     4,     5,   228,     6,     6,     6,
       6,     6,     6,     6,  1887,     6,   235,  1890,     6,   234,
       7,     6,  1893,     6,   234,     6,   234,   234,  1901,   234,
       6,     6,  1905,   235,     6,   234,     6,     6,     6,  1906,
    1907,  1908,  1909,  1910,    44,    45,    46,    47,    48,    49,
      50,    51,    52,   123,     6,   227,     6,    57,    58,    59,
      60,     6,     6,   228,   234,    65,    66,    67,     6,   235,
      70,     6,     6,     6,     6,   234,   234,     6,     6,     6,
       6,     6,    82,    83,     6,     6,     6,  1997,   522,  1372,
    1963,  1867,  1632,  1388,     3,  1962,     3,     3,     3,  1966,
     603,  1889,     3,    -1,  1553,    -1,    -1,     6,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     120,  1994,    -1,    -1,    -1,  1993,    -1,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,    -1,    -1,    -1,    -1,   226,    -1,  2014,    -1,    -1,
       6,  2018,    -1,    -1,    -1,    -1,    -1,  2030,  2031,  2032,
    2033,  2034,    -1,    -1,    -1,    -1,    -1,  2034,    -1,    -1,
      -1,    -1,    -1,  2046,    -1,    -1,    -1,    -1,    -1,     6,
      -1,    -1,    -1,    -1,    -1,   106,    -1,   187,   188,   189,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     200,    -1,   202,   203,    -1,    -1,  2074,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     6,
      -1,    -1,  2089,  2090,    -1,    -1,  2099,    -1,   228,    -1,
     230,    -1,  2105,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,    -1,    -1,    -1,
      -1,   226,    -1,    -1,    -1,  2128,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1842,    -1,    -1,    -1,  2140,    -1,  2142,
      -1,    -1,    -1,  1852,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   204,   205,   206,   207,   208,    -1,    -1,
    2163,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   222,    -1,    -1,    -1,   226,    -1,    -1,    -1,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   244,   245,   246,   247,   226,   249,   250,
     251,   252,    -1,   254,   255,   256,   257,   258,   259,   260,
     261,    -1,   263,   264,   265,     7,    -1,    -1,   269,    -1,
      -1,    -1,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,    -1,   288,   289,   290,
     226,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   300,
     301,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   316,    -1,    -1,    -1,   226,
      -1,    -1,    -1,    -1,   325,   326,    -1,    -1,    -1,    -1,
     331,    -1,    -1,    -1,    -1,  1994,    -1,    -1,    -1,    -1,
     341,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,    -1,    -1,    -1,    -1,   226,
     361,    -1,    -1,    -1,   365,   366,   367,    -1,   369,    -1,
      -1,    -1,   373,   374,   375,    -1,    -1,   378,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   392,    -1,    -1,    -1,    -1,    -1,   398,   399,    -1,
      -1,    -1,    -1,    -1,    -1,  2105,    -1,    -1,    -1,    -1,
      -1,   412,   413,   414,   415,   416,   417,   418,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,   435,    -1,    -1,    -1,    -1,    -1,
    2140,    -1,  2142,    -1,    -1,    -1,  2105,    -1,   449,    -1,
      -1,    -1,    -1,    -1,   455,    -1,    -1,    -1,    -1,    -1,
      -1,   462,    -1,  2163,     6,    -1,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
      -1,  2140,    -1,  2142,   226,   486,   487,    -1,   489,   490,
     491,   492,   493,   494,   495,   496,   497,   498,   499,   500,
     501,   502,   503,    -1,  2163,   506,   507,     6,    -1,    -1,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,    -1,    -1,     6,   528,   226,    -1,
      -1,   123,    -1,   534,    -1,   233,    -1,   235,   539,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   553,    -1,    -1,    -1,    -1,    -1,   559,   560,
      -1,   562,   563,   564,   565,    -1,   567,    -1,    -1,   570,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   582,   583,    -1,    -1,    -1,    -1,    -1,   589,   590,
     591,   592,    -1,    -1,    -1,    -1,   597,   598,   599,    -1,
      -1,    -1,    -1,   604,   605,   606,   607,   608,    -1,   610,
      -1,   612,    -1,   614,   615,    -1,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
      -1,   632,   633,   634,   226,    -1,    -1,   638,   639,   640,
     641,   642,   643,   644,   645,   646,    -1,    -1,    -1,    -1,
     651,    -1,   653,   654,    -1,    -1,    -1,   658,   659,   660,
      -1,    -1,   663,   664,   665,    -1,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
      -1,   682,     8,    -1,   226,    -1,   687,   688,    -1,   690,
     691,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     701,   702,    -1,    -1,    -1,   706,    -1,    -1,    -1,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,    -1,    -1,    -1,    -1,   226,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,    -1,   245,    -1,    -1,   226,    -1,   250,    -1,
     751,    -1,    -1,   255,   755,   756,   757,   758,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   269,    -1,    -1,
       8,    -1,    12,    13,    -1,    -1,   777,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   288,    -1,   290,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   301,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   814,   815,    -1,   817,   818,   819,    -1,
      -1,   822,   823,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   834,    -1,    -1,   837,   838,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,   860,
      -1,    -1,   102,   103,   104,    -1,    -1,   107,    -1,    -1,
     871,    -1,   873,   113,   114,   876,    -1,   117,   118,    -1,
     120,   121,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   897,    -1,    -1,   139,
     226,   902,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   910,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   163,   164,   165,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   934,    -1,    -1,    -1,    -1,    -1,    -1,
     941,   942,    -1,    -1,    -1,    -1,   947,    -1,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   963,    -1,    -1,   966,   226,    -1,   228,    -1,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   985,   487,   987,   988,   226,    -1,
      47,    -1,    -1,    -1,    -1,   235,    -1,   998,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   245,    -1,
      -1,    -1,    -1,   250,    -1,    -1,    -1,    -1,   255,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   528,    -1,  1029,    -1,
      -1,    -1,   269,    -1,    -1,    -1,  1037,  1038,  1039,    -1,
    1041,    12,    13,    -1,    -1,    -1,    -1,    -1,  1049,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     562,   563,    -1,    -1,   301,    -1,    -1,    -1,    -1,  1070,
       8,    -1,    -1,    -1,  1075,    -1,    -1,    -1,    -1,    -1,
     582,   583,    -1,  1084,    -1,    -1,    -1,    -1,   590,  1090,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     8,  1100,
    1101,  1102,  1103,  1104,    -1,    -1,    -1,    -1,    -1,    -1,
    1111,    -1,   614,   615,    -1,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    -1,    -1,
      -1,   102,   103,   104,    -1,    -1,   107,    -1,    -1,    -1,
      -1,    -1,   113,   114,  1145,    -1,   117,   118,    -1,   120,
     121,    -1,    -1,    -1,    -1,    -1,   658,   659,   660,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   139,    -1,
      -1,    -1,    -1,  1174,    -1,    -1,    -1,    -1,    -1,    -1,
     682,    -1,    -1,  1184,  1185,    -1,  1187,  1188,    -1,  1190,
    1191,  1192,   163,   164,   165,  1196,    -1,    -1,    -1,    -1,
     702,  1202,     8,    -1,    -1,    -1,    -1,    -1,    -1,   266,
      -1,  1212,    -1,  1214,    -1,  1216,    -1,  1218,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   284,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1238,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   304,    -1,    -1,
     487,    -1,    -1,    -1,    -1,   312,   313,   314,    -1,    -1,
      -1,   318,    -1,    -1,   235,    -1,    -1,    -1,    -1,  1270,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,    -1,    -1,    -1,    -1,   226,    -1,
      -1,    -1,  1293,    -1,    -1,    -1,    -1,  1298,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,    -1,    -1,    -1,   817,   226,    -1,    -1,    -1,
     822,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   837,   838,    -1,   395,   396,
      -1,    -1,    -1,    -1,  1345,    -1,   583,    -1,    -1,    -1,
      -1,    -1,   409,  1354,  1355,  1356,  1357,    -1,    -1,    -1,
    1361,  1362,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   871,
      -1,   873,    -1,    -1,   876,  1376,  1377,   614,   615,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   446,
      -1,    -1,    -1,    -1,    -1,   897,    -1,    -1,    -1,    -1,
     902,    -1,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,    -1,    -1,    -1,    -1,
     226,   658,   659,   660,    -1,    -1,    12,    13,    -1,    -1,
      -1,    -1,   934,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   682,    -1,    -1,  1449,  1450,
    1451,    -1,    -1,    -1,    -1,    -1,    -1,  1458,    -1,  1460,
      -1,    -1,    -1,    -1,    -1,   702,  1467,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1480,
      -1,    -1,    -1,    -1,  1485,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1493,  1494,  1495,    -1,    -1,    -1,    -1,    -1,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    -1,    -1,    -1,   102,   103,   104,     8,
     577,   107,    -1,    -1,  1525,    -1,    -1,   113,   114,    -1,
      -1,   117,   118,  1534,   120,   121,    -1,    -1,    -1,  1041,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1550,
      -1,    -1,    -1,   139,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,  1569,    -1,
      -1,    -1,   226,  1574,    -1,    -1,    -1,   163,   164,   165,
     817,   235,    -1,    -1,    -1,   822,    -1,    -1,    -1,  1590,
    1591,    -1,    -1,    -1,    -1,    -1,  1597,  1598,  1100,  1101,
    1102,  1103,    -1,  1604,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1620,
    1621,  1622,  1623,  1624,  1625,  1626,    -1,    -1,    -1,    -1,
      -1,    -1,   593,  1634,   871,    -1,   873,    -1,    -1,   876,
      -1,    -1,  1643,  1644,  1645,    -1,  1647,    -1,    -1,   235,
      -1,    -1,  1653,  1654,    -1,    -1,    -1,    -1,    -1,    -1,
     897,    -1,    -1,    -1,    -1,   902,    -1,    -1,    -1,    -1,
      -1,  1672,  1174,    -1,    -1,  1676,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1687,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   934,    -1,    -1,
    1202,    -1,    -1,    -1,    -1,    -1,    -1,  1708,    -1,    -1,
      -1,    -1,    -1,   770,    -1,    -1,    -1,   774,    -1,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,    -1,  1735,  1736,    -1,   226,    -1,    -1,
      -1,    -1,  1743,    -1,    -1,    -1,    -1,    -1,   709,   710,
     711,   712,   713,   714,   715,   716,   717,   718,   719,    -1,
     721,   722,   723,   724,   725,   726,   727,    -1,    -1,  1770,
     731,   732,   733,    -1,    -1,    -1,   737,   738,    -1,   740,
      -1,    -1,    -1,    -1,   745,   746,   747,    -1,   749,  1790,
       5,   752,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1800,
      -1,    -1,   763,   764,  1041,    -1,    -1,    -1,  1809,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1817,    -1,  1819,    -1,
     781,  1822,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,
      45,    46,    47,    48,    49,    50,    51,    52,  1839,    -1,
      -1,    -1,    57,    58,    59,    60,    -1,    -1,    -1,    -1,
      65,    66,    67,    -1,   911,    70,  1857,    -1,    -1,    -1,
      -1,  1862,    -1,  1100,  1101,  1102,  1103,    82,    83,    -1,
      -1,    -1,    -1,  1874,    -1,    -1,    -1,    -1,    -1,  1880,
    1881,  1882,  1883,  1884,    -1,    -1,    -1,    -1,    -1,  1890,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,  1905,    -1,    -1,    -1,   226,    -1,
      -1,    -1,  1913,    -1,    -1,   233,    -1,   235,    -1,    -1,
     881,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   892,    -1,    -1,    -1,  1936,  1937,  1174,    -1,    -1,
    1941,    -1,    -1,    -1,  1001,    -1,    -1,    -1,  1005,    -1,
      -1,    -1,  1009,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1202,    -1,    -1,    -1,  1970,
      -1,    -1,   187,   188,   189,    -1,    -1,    -1,  1480,    -1,
      -1,    -1,    -1,    -1,    -1,   200,    -1,   202,    -1,    -1,
    1991,    -1,    -1,    -1,  1051,    -1,  1997,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2007,  2008,  2009,  2010,
    2011,  2012,     4,     5,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2025,    -1,    -1,    -1,    -1,  2030,
    2031,  2032,  2033,  2034,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2044,    -1,    -1,  2047,    -1,    -1,    -1,
      -1,    -1,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    -1,    -1,    -1,    -1,    57,    58,    59,    60,    -1,
      -1,    -1,    -1,    65,    66,    67,    -1,    -1,    70,    -1,
      -1,    -1,  2083,  2084,  2085,  2086,  2087,  2088,    -1,    -1,
      82,    83,    -1,    -1,    -1,    -1,  1153,  1154,  2099,  1156,
      -1,  1158,  1159,    -1,  1161,    -1,  1163,  1164,  1165,  1166,
    1167,  1168,  1169,  1170,  1171,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   120,    -1,
      -1,  2132,  2133,  2134,  2135,  2136,  2137,    -1,  1195,    -1,
      -1,  1643,  1644,    -1,  1201,    -1,    -1,    -1,    -1,  1110,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    22,    23,    -1,    -1,    -1,    -1,    -1,    -1,
    1672,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     4,
       5,    -1,    -1,    -1,    -1,    -1,  1147,  1148,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   187,   188,   189,    -1,    -1,
      -1,  1258,    -1,    -1,    -1,    -1,    -1,    -1,   200,    -1,
     202,   203,    -1,    -1,  1271,  1272,  1273,    -1,    -1,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    -1,    -1,
    1287,    -1,    57,    58,    59,    60,    -1,    -1,    -1,    -1,
      65,    66,    67,  1480,    -1,    70,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    82,    83,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   131,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,    -1,  1363,  1809,   168,   169,
     170,   171,    -1,   173,   174,   175,   176,   177,   178,    -1,
    1822,   181,    -1,    -1,    -1,    -1,    -1,   187,   188,   189,
      -1,    -1,  1389,    -1,    -1,   195,   196,  1839,  1395,    -1,
    1301,    -1,    -1,    -1,    -1,    -1,  1307,  1308,  1309,  1310,
    1311,    -1,  1313,    -1,  1315,  1316,    -1,  1318,    -1,  1320,
      -1,    -1,   187,   188,   189,    -1,  1327,  1328,  1329,    -1,
    1427,  1428,  1429,  1334,    -1,   200,  1433,   202,  1435,    -1,
    1437,    -1,  1439,    -1,  1441,  1442,  1443,    -1,  1890,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1458,    -1,  1905,    -1,    -1,  1643,  1644,    -1,    -1,
      -1,    -1,  1469,    -1,   274,    -1,   276,   277,   278,   279,
    1477,    -1,    -1,    -1,    -1,    -1,    -1,   287,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   298,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1411,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1424,     3,     4,    -1,    -1,    -1,    -1,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1568,    -1,    -1,    53,    54,    55,    56,    -1,    -1,
      -1,    -1,    61,    -1,  1581,    -1,    -1,    -1,  2030,  2031,
    2032,  2033,  2034,    72,    73,    74,    -1,    -1,    -1,    -1,
      -1,    80,    81,    -1,  1505,    -1,    -1,    -1,    -1,  1510,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,    -1,    -1,    -1,    -1,   226,    -1,
      -1,    -1,    -1,    -1,    -1,   233,    -1,   235,    -1,    -1,
      -1,    -1,  1543,  1544,    -1,  1822,  1547,  1548,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2099,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1666,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   481,    -1,    -1,  1681,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1691,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1701,    -1,    -1,   186,    -1,  1706,
      -1,   190,    -1,  1890,    -1,    -1,   195,   196,   197,   198,
     199,    -1,    -1,    -1,   203,    -1,    -1,    -1,  1905,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   217,   218,
    1737,    -1,    -1,   222,    -1,    -1,    -1,    -1,   227,    -1,
      -1,    -1,    -1,   232,    -1,   234,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1762,    -1,    -1,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,    -1,    -1,    -1,    -1,   226,    -1,    -1,    -1,
      -1,    -1,    -1,  1694,  1695,   235,    -1,  1698,  1699,    -1,
    1797,    -1,    -1,  1704,  1705,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,    -1,    -1,    -1,
      -1,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    -1,
      -1,    -1,    -1,  2030,  2031,  2032,  2033,  2034,    -1,    -1,
      -1,    -1,  1763,  1764,  1861,    53,    54,    55,    56,    -1,
      -1,  1868,  1869,    61,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    72,    73,    74,    -1,    -1,    -1,
    1887,    -1,    80,    81,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1901,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,    -1,
      -1,    -1,  2099,   226,    -1,    -1,     3,     4,     5,    -1,
      -1,   234,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      -1,    -1,    -1,    -1,    -1,    -1,  1963,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    -1,    -1,    -1,    65,    66,
      67,    -1,    -1,    70,    -1,    72,    73,    74,   186,    -1,
      -1,    -1,   190,    80,    81,    82,    83,   195,   196,   197,
     198,   199,    -1,    -1,    -1,   203,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   217,
     218,    -1,    -1,    -1,   222,    -1,    -1,    -1,    -1,   227,
      -1,    -1,    -1,   120,   232,    -1,   234,    -1,    -1,  2046,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,    -1,    -1,    -1,    -1,   226,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   235,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,    -1,    -1,    -1,    -1,   226,    -1,    -1,    -1,
      -1,    -1,   179,    -1,    -1,   235,    -1,    -1,    -1,   186,
     187,   188,   189,   190,    -1,    -1,    -1,    -1,   195,   196,
     197,   198,   199,   200,    -1,   202,   203,    -1,    -1,    -1,
      -1,  2128,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     217,   218,    -1,    -1,    -1,   222,    -1,    -1,    -1,    -1,
     227,    -1,   229,    -1,   231,   232,    -1,   234,    -1,   236,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,    -1,
      -1,    -1,    -1,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    -1,    -1,    -1,  2110,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,    54,    55,
      56,    -1,    -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    72,    73,    74,    -1,
      -1,    -1,    -1,    -1,    80,    81,    -1,    -1,    -1,    -1,
      86,    -1,    -1,    89,    -1,    -1,    92,    -1,    94,    -1,
      -1,    -1,    -1,    -1,    -1,   101,    -1,    -1,    -1,    -1,
       4,     5,    -1,    -1,    -1,    -1,    -1,   113,    -1,   115,
    1080,  1081,   118,    -1,   120,    -1,  1086,  1087,    -1,    -1,
      -1,   127,   128,   129,   130,   131,    -1,    -1,   134,   135,
     136,   137,   138,    -1,    -1,    -1,   142,    -1,    -1,   145,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    -1,
      -1,    -1,    -1,    57,    58,    59,    60,    -1,    -1,    -1,
      -1,    65,    66,    67,    -1,    -1,    70,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    82,    83,
     186,    -1,    -1,    -1,   190,   191,    -1,    -1,    -1,   195,
     196,   197,   198,   199,    -1,    -1,    -1,   203,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   217,   218,    -1,    -1,    -1,   222,    -1,    -1,    -1,
      -1,   227,    -1,    -1,     3,     4,   232,    -1,   234,   235,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    53,    54,    55,    56,    -1,    -1,
      -1,    -1,    61,   187,   188,   189,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    72,    73,    74,   200,    -1,   202,   203,
      -1,    80,    81,    -1,    -1,    -1,    -1,    86,    -1,    -1,
      89,    -1,    -1,    92,    -1,    94,    -1,    -1,    -1,    -1,
    1290,  1291,   101,    -1,    -1,  1295,  1296,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   113,    -1,   115,    -1,    -1,   118,
      -1,   120,    -1,    -1,    -1,    -1,    -1,    -1,   127,   128,
     129,   130,   131,    -1,    -1,   134,   135,   136,   137,   138,
      -1,    -1,    -1,   142,    -1,    -1,   145,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,    -1,    -1,    -1,    -1,   226,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   235,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   186,    -1,    -1,
      -1,   190,   191,    -1,    -1,    -1,   195,   196,   197,   198,
     199,    -1,    -1,    -1,   203,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   217,   218,
      -1,    -1,    -1,   222,    -1,    -1,    -1,    -1,   227,    -1,
      -1,    -1,    -1,   232,    -1,    -1,   235,     3,     4,     5,
      -1,    -1,    -1,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    -1,    -1,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    -1,    -1,    -1,    65,
      66,    67,    -1,    -1,    70,    -1,    72,    73,    74,    -1,
      -1,    -1,    -1,    -1,    80,    81,    82,    83,    -1,    -1,
      86,    -1,    -1,    89,    -1,    -1,    92,    -1,    94,    -1,
      -1,    -1,    -1,    -1,    -1,   101,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,    -1,   115,
      -1,    -1,   118,    -1,   120,    -1,    -1,    -1,    -1,    -1,
      -1,   127,   128,   129,   130,   131,    -1,    -1,   134,   135,
     136,   137,   138,    -1,    -1,    -1,   142,    -1,    -1,   145,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,    -1,    -1,    -1,    -1,   226,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   235,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     186,   187,   188,   189,   190,   191,    -1,    -1,    -1,   195,
     196,   197,   198,   199,   200,    -1,   202,   203,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   217,   218,    -1,    -1,    -1,   222,    -1,    -1,    -1,
      -1,   227,    -1,     3,     4,     5,   232,    -1,   234,     9,
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
      -1,    -1,    -1,   113,    -1,   115,    -1,    -1,   118,    -1,
     120,    -1,    -1,    -1,    -1,    -1,    -1,   127,   128,   129,
     130,   131,    -1,    -1,   134,   135,   136,   137,   138,    -1,
      -1,    -1,   142,    -1,    -1,   145,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
      -1,    -1,    -1,    -1,   226,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   235,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   186,   187,   188,   189,
     190,   191,    -1,    -1,    -1,   195,   196,   197,   198,   199,
     200,    -1,   202,   203,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   217,   218,    -1,
      -1,    -1,   222,    -1,    -1,    -1,    -1,   227,    -1,     3,
       4,     5,   232,    -1,   234,     9,    10,    11,    -1,    -1,
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
      -1,   115,    -1,    -1,   118,    -1,   120,    -1,    -1,    -1,
      -1,    -1,    -1,   127,   128,   129,   130,   131,    -1,    -1,
     134,   135,   136,   137,   138,    -1,    -1,    -1,   142,    -1,
      -1,   145,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,    -1,    -1,    -1,    -1,
     226,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   235,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   186,    -1,    -1,    -1,   190,   191,    -1,    -1,
      -1,   195,   196,   197,   198,   199,    -1,    -1,    -1,   203,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   217,   218,    -1,    -1,    -1,   222,    -1,
      -1,    -1,    -1,   227,    -1,     3,     4,     5,   232,    -1,
     234,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
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
     118,    -1,   120,    -1,    -1,    -1,    -1,    -1,    -1,   127,
     128,   129,   130,   131,    -1,    -1,   134,   135,   136,   137,
     138,    -1,    -1,    -1,   142,    -1,    -1,   145,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,    -1,    -1,    -1,    -1,   226,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   235,    -1,    -1,    -1,    -1,
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
      72,    73,    74,    -1,    -1,    -1,    -1,    -1,    80,    81,
      -1,    -1,    -1,    -1,    86,    -1,    -1,    89,    -1,    -1,
      92,    -1,    94,    -1,    -1,    -1,    -1,    -1,    -1,   101,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   113,    -1,   115,    -1,    -1,   118,    -1,   120,    -1,
      -1,    -1,    -1,    -1,    -1,   127,   128,   129,   130,   131,
      -1,    -1,   134,   135,   136,   137,   138,    -1,    -1,    -1,
     142,    -1,    -1,   145,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,    -1,    -1,
      -1,    -1,   226,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   235,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
      -1,    -1,    -1,    -1,    80,    81,    -1,    -1,    -1,    -1,
      86,    -1,    -1,    89,    -1,    -1,    92,    -1,    94,    -1,
      -1,    -1,    -1,    -1,    -1,   101,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,    -1,   115,
      -1,    -1,   118,    -1,   120,    -1,    -1,    -1,    -1,    -1,
      -1,   127,   128,   129,   130,   131,    -1,    -1,   134,   135,
     136,   137,   138,    -1,    -1,    -1,   142,    -1,    -1,   145,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,    -1,    -1,    -1,    -1,   226,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   235,    -1,    -1,
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
      80,    81,    -1,    -1,    -1,    -1,    86,    -1,    -1,    89,
      -1,    -1,    92,    -1,    94,    -1,    -1,    -1,    -1,    -1,
      -1,   101,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   113,    -1,   115,    -1,    -1,   118,    -1,
     120,    -1,    -1,    -1,    -1,    -1,    -1,   127,   128,   129,
     130,   131,    -1,    -1,   134,   135,   136,   137,   138,    -1,
      -1,    -1,   142,    -1,    -1,   145,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
      -1,    -1,    -1,    -1,   226,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   235,    -1,    -1,    -1,    -1,    -1,    -1,
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
      74,    -1,    -1,    -1,    -1,    -1,    80,    81,    -1,    -1,
      -1,    -1,    86,    -1,    -1,    89,    -1,    -1,    92,    -1,
      94,    -1,    -1,    -1,    -1,    -1,    -1,   101,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,
      -1,   115,    -1,    -1,   118,    -1,   120,    -1,    -1,    -1,
      -1,    -1,    -1,   127,   128,   129,   130,   131,    -1,    -1,
     134,   135,   136,   137,   138,    -1,    -1,    -1,   142,    -1,
      -1,   145,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,    -1,    -1,    -1,    -1,
     226,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   235,
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
      -1,    -1,    80,    81,    -1,    -1,    -1,    -1,    86,    -1,
      -1,    89,    -1,    -1,    92,    -1,    94,    -1,    -1,    -1,
      -1,    -1,    -1,   101,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   113,    -1,   115,    -1,    -1,
     118,    -1,   120,    -1,    -1,    -1,    -1,    -1,    -1,   127,
     128,   129,   130,   131,    -1,    -1,   134,   135,   136,   137,
     138,    -1,    -1,    -1,   142,    -1,    -1,   145,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,    -1,    -1,    -1,    -1,   226,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   235,    -1,    -1,    -1,    -1,
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
      72,    73,    74,    -1,    -1,    -1,    -1,    -1,    80,    81,
      -1,    -1,    -1,    -1,    86,    -1,    -1,    89,    -1,    -1,
      92,    -1,    94,    -1,    -1,    -1,    -1,    -1,    -1,   101,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   113,    -1,   115,    -1,    -1,   118,    -1,   120,    -1,
      -1,    -1,    -1,    -1,    -1,   127,   128,   129,   130,   131,
      -1,    -1,   134,   135,   136,   137,   138,    -1,    -1,    -1,
     142,    -1,    -1,   145,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,    -1,    -1,
      -1,    -1,   226,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   235,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
      -1,    -1,    -1,    -1,    80,    81,    -1,    -1,    -1,    -1,
      86,    -1,    -1,    89,    -1,    -1,    92,    -1,    94,    -1,
      -1,    -1,    -1,    -1,    -1,   101,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,    -1,   115,
      -1,    -1,   118,    -1,   120,    -1,    -1,    -1,    -1,    -1,
      -1,   127,   128,   129,   130,   131,    -1,    -1,   134,   135,
     136,   137,   138,    -1,    -1,    -1,   142,    -1,    -1,   145,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,    -1,    -1,    -1,    -1,   226,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   235,    -1,    -1,
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
      80,    81,    -1,    -1,    -1,    -1,    86,    -1,    -1,    89,
      -1,    -1,    92,    -1,    94,    -1,    -1,    -1,    -1,    -1,
      -1,   101,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   113,    -1,   115,    -1,    -1,   118,    -1,
     120,    -1,    -1,    -1,    -1,    -1,    -1,   127,   128,   129,
     130,   131,    -1,    -1,   134,   135,   136,   137,   138,    -1,
      -1,    -1,   142,    -1,    -1,   145,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
      -1,    -1,    -1,    -1,   226,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   235,    -1,    -1,    -1,    -1,    -1,    -1,
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
      74,    -1,    -1,    -1,    -1,    -1,    80,    81,    -1,    -1,
      -1,    -1,    86,    -1,    -1,    89,    -1,    -1,    92,    -1,
      94,    -1,    -1,    -1,    -1,    -1,    -1,   101,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,
      -1,   115,    -1,    -1,   118,    -1,   120,    -1,    -1,    -1,
      -1,    -1,    -1,   127,   128,   129,   130,   131,    -1,    -1,
     134,   135,   136,   137,   138,    -1,    -1,    -1,   142,    -1,
      -1,   145,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,    -1,    -1,    -1,    -1,
     226,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   235,
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
      -1,    -1,    80,    81,    -1,    -1,    -1,    -1,    86,    -1,
      -1,    89,    -1,    -1,    92,    -1,    94,    -1,    -1,    -1,
      -1,    -1,    -1,   101,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   113,    -1,   115,    -1,    -1,
     118,    -1,   120,    -1,    -1,    -1,    -1,    -1,    -1,   127,
     128,   129,   130,   131,    -1,    -1,   134,   135,   136,   137,
     138,    -1,    -1,    -1,   142,    -1,    -1,   145,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,    -1,    -1,    -1,    -1,   226,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   235,    -1,    -1,    -1,    -1,
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
      72,    73,    74,    -1,    -1,    -1,    -1,    -1,    80,    81,
      -1,    -1,    -1,    -1,    86,    -1,    -1,    89,    -1,    -1,
      92,    -1,    94,    -1,    -1,    -1,    -1,    -1,    -1,   101,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   113,    -1,   115,    -1,    -1,   118,    -1,   120,    -1,
      -1,    -1,    -1,    -1,    -1,   127,   128,   129,   130,   131,
      -1,    -1,   134,   135,   136,   137,   138,    -1,    -1,    -1,
     142,    -1,    -1,   145,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,    -1,    -1,
      -1,    -1,   226,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   235,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
      -1,    -1,    -1,    -1,    80,    81,    -1,    -1,    -1,    -1,
      86,    -1,    -1,    89,    -1,    -1,    92,    -1,    94,    -1,
      -1,    -1,    -1,    -1,    -1,   101,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,    -1,   115,
      -1,    -1,   118,    -1,   120,    -1,    -1,    -1,    -1,    -1,
      -1,   127,   128,   129,   130,   131,    -1,    -1,   134,   135,
     136,   137,   138,    -1,    -1,    -1,   142,    -1,    -1,   145,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,    -1,    -1,    -1,    -1,   226,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   235,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     186,    -1,    -1,    -1,   190,   191,    -1,    -1,    -1,   195,
     196,   197,   198,   199,    -1,    -1,    -1,   203,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   217,   218,    -1,    -1,    -1,   222,    -1,    -1,    -1,
      -1,   227,    -1,     3,     4,     5,   232,    -1,   234,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    -1,    -1,    -1,    65,    66,    67,    -1,    -1,
      70,    -1,    72,    73,    74,    -1,    -1,    -1,    -1,    -1,
      80,    81,    82,    83,     3,     4,     5,    -1,    -1,    -1,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    -1,    -1,    -1,    65,    66,    67,    -1,
      -1,    70,    -1,    72,    73,    74,    -1,    -1,    -1,    -1,
      -1,    80,    81,    82,    83,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,    -1,
      -1,    -1,    -1,   226,    -1,    -1,   186,   187,   188,   189,
     190,    -1,   235,    -1,    -1,   195,   196,   197,   198,   199,
     200,    -1,   202,   203,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   217,   218,    -1,
      -1,    -1,   222,    -1,    -1,    -1,    -1,   227,    -1,    -1,
      -1,    -1,   232,    -1,   234,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,    -1,
      -1,    -1,    -1,   226,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   235,    -1,    -1,    -1,    -1,   186,   187,   188,
     189,   190,    -1,    -1,    -1,    -1,   195,   196,   197,   198,
     199,   200,    -1,   202,   203,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   217,   218,
      -1,    -1,    -1,   222,    -1,    -1,    -1,    -1,   227,    -1,
       3,     4,     5,   232,    -1,   234,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,    -1,    12,    13,    -1,
      -1,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    -1,
      -1,    -1,    65,    66,    67,    -1,    -1,    70,    -1,    72,
      73,    74,    -1,    -1,    -1,    -1,    -1,    80,    81,    82,
      83,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,    -1,    -1,    -1,    -1,   226,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   235,    -1,
      -1,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    -1,    -1,    -1,   102,   103,   104,
      -1,    -1,   107,    -1,    -1,    -1,    -1,    -1,   113,   114,
      -1,    -1,   117,   118,    -1,   120,   121,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,    -1,    -1,    -1,   139,   226,    -1,    -1,   143,    -1,
      -1,    -1,    -1,    -1,   235,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   186,   187,   188,   189,   190,   163,   164,
     165,    -1,   195,   196,   197,   198,   199,   200,    -1,   202,
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
      -1,    -1,    -1,    80,    81,    -1,    -1,    -1,    -1,    86,
      -1,    -1,    89,    -1,    -1,    92,    -1,    94,    -1,    -1,
      -1,    -1,    -1,    -1,   101,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   113,    -1,   115,    -1,
      -1,   118,    -1,   120,    -1,    -1,    -1,    -1,    -1,    -1,
     127,   128,   129,   130,   131,    -1,    -1,   134,   135,   136,
     137,   138,    -1,    -1,    -1,   142,    -1,    -1,   145,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,    -1,    -1,    -1,    -1,   226,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   235,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   186,
      -1,    -1,    -1,   190,   191,    -1,    -1,    -1,   195,   196,
     197,   198,   199,    -1,    -1,    -1,   203,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     217,   218,    -1,    -1,    -1,   222,     3,     4,     5,    -1,
     227,    -1,     9,    10,    11,   232,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    -1,    -1,    -1,    65,    66,
      67,    -1,    -1,    70,    -1,    72,    73,    74,    -1,    -1,
      -1,     3,     4,    80,    81,    82,    83,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    -1,    -1,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,    53,    54,    55,    56,   226,    -1,    -1,    -1,    61,
      -1,    -1,    -1,    -1,   235,    -1,    -1,    -1,    -1,    -1,
      72,    73,    74,    -1,    -1,    -1,    -1,    -1,    80,    81,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,    -1,    -1,    -1,    -1,   226,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   235,    -1,   186,
     187,   188,   189,   190,    -1,    -1,    -1,    -1,   195,   196,
     197,   198,   199,   200,    -1,   202,   203,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     217,   218,    -1,    -1,    -1,   222,    -1,    -1,    -1,    -1,
     227,    -1,    -1,    -1,    -1,   232,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
      -1,    -1,    -1,    -1,   226,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   235,   186,    -1,    -1,    -1,   190,    -1,
      -1,    -1,    -1,   195,   196,   197,   198,   199,    -1,    -1,
      -1,   203,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   217,   218,    -1,    -1,    -1,
     222,     3,     4,    -1,    -1,   227,   228,     9,    10,    11,
     232,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    -1,    -1,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,    53,    54,    55,    56,   226,    -1,    -1,    -1,    61,
      -1,    -1,    -1,    -1,   235,    -1,    -1,    -1,    -1,    -1,
      72,    73,    74,    -1,     3,     4,    -1,    -1,    80,    81,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    -1,    -1,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,    53,    54,    55,    56,   226,    -1,
      -1,    -1,    61,    -1,    -1,    -1,    -1,   235,    -1,    -1,
      -1,    -1,    -1,    72,    73,    74,    -1,    -1,    -1,    -1,
      -1,    80,    81,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,    -1,    -1,    -1,
      -1,   226,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     235,    -1,    -1,    -1,   186,    -1,    -1,    -1,   190,    -1,
      -1,    -1,    -1,   195,   196,   197,   198,   199,    -1,    -1,
      -1,   203,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   217,   218,    -1,    -1,    -1,
     222,    -1,    -1,    -1,    -1,   227,    -1,    -1,   230,    -1,
     232,    -1,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,    -1,    -1,    -1,    -1,
     226,    -1,    -1,    -1,    -1,    -1,    -1,   186,   234,    -1,
      -1,   190,    -1,    -1,    -1,    -1,   195,   196,   197,   198,
     199,    -1,    -1,    -1,   203,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   217,   218,
      -1,    -1,    -1,   222,     3,     4,    -1,    -1,   227,   228,
       9,    10,    11,   232,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    -1,    -1,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,    53,    54,    55,    56,   226,    -1,
      -1,    -1,    61,    -1,    -1,    -1,   234,    -1,    -1,    -1,
      -1,    -1,    -1,    72,    73,    74,    -1,     3,     4,    -1,
       6,    80,    81,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    -1,    -1,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,    53,    54,    55,
      56,   226,    -1,   228,    -1,    61,    -1,    -1,   233,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    72,    73,    74,    -1,
      -1,    -1,    -1,    -1,    80,    81,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
      -1,    -1,    -1,    -1,   226,    -1,   228,    -1,   230,    -1,
      -1,   233,    -1,    -1,    -1,    -1,    -1,   186,    -1,    -1,
      -1,   190,    -1,    -1,    -1,    -1,   195,   196,   197,   198,
     199,    -1,    -1,    -1,   203,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   217,   218,
      -1,    -1,    -1,   222,    -1,    -1,    -1,    -1,   227,    -1,
      -1,   230,    -1,   232,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,    -1,    -1,
      -1,    -1,   226,    -1,    -1,    -1,    -1,    -1,    -1,   233,
     186,    -1,    -1,    -1,   190,    -1,    -1,    -1,    -1,   195,
     196,   197,   198,   199,    -1,    -1,    -1,   203,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   217,   218,    -1,    -1,    -1,   222,     3,     4,    -1,
       6,   227,    -1,     9,    10,    11,   232,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    -1,    -1,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,    53,    54,    55,
      56,   226,    -1,    -1,    -1,    61,    -1,    -1,   233,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    72,    73,    74,    -1,
       3,     4,    -1,    -1,    80,    81,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
      53,    54,    55,    56,   226,    -1,    -1,    -1,    61,    -1,
      -1,   233,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,
      73,    74,    -1,    -1,    -1,    -1,    -1,    80,    81,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,    -1,    -1,    -1,    -1,   226,    -1,    -1,
      -1,    -1,    -1,    -1,   233,    -1,    -1,    -1,    -1,    -1,
     186,    -1,    -1,    -1,   190,    -1,    -1,    -1,    -1,   195,
     196,   197,   198,   199,    -1,    -1,    -1,   203,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   217,   218,    -1,    -1,    -1,   222,    -1,    -1,    -1,
      -1,   227,    -1,    -1,    -1,    -1,   232,    12,    13,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,    -1,    -1,    -1,    -1,   226,    -1,    -1,
      -1,    -1,    -1,   186,   233,    -1,    -1,   190,    -1,    -1,
      -1,    -1,   195,   196,   197,   198,   199,    12,    13,    -1,
     203,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   217,   218,    -1,    -1,    -1,   222,
      -1,    -1,    -1,    -1,   227,    -1,    -1,    -1,    -1,   232,
      -1,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    -1,    -1,    -1,   102,   103,   104,
      -1,    -1,   107,    -1,    -1,    -1,    -1,    -1,   113,   114,
      -1,    -1,   117,   118,    -1,   120,   121,    -1,    -1,    -1,
      -1,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,   139,    -1,    -1,   102,   103,   104,
      -1,    -1,   107,    -1,    -1,    -1,    -1,    -1,   113,   114,
      -1,    -1,   117,   118,    -1,   120,   121,    -1,   163,   164,
     165,    -1,    -1,    12,    13,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   139,    -1,    -1,    -1,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,    -1,    -1,    -1,    -1,   226,    -1,   163,   164,
     165,    12,    13,   233,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,    -1,    -1,
      -1,    -1,   226,    -1,    -1,    -1,    -1,    -1,    -1,   233,
     235,    -1,    -1,    -1,    -1,    -1,    -1,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      -1,    -1,    -1,   102,   103,   104,    12,    13,   107,    -1,
      -1,    -1,    -1,    -1,   113,   114,    -1,    -1,   117,   118,
     235,   120,   121,    -1,    -1,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    -1,    -1,
     139,   102,   103,   104,    -1,    -1,   107,    -1,    -1,    -1,
      -1,    -1,   113,   114,    -1,    -1,   117,   118,    -1,   120,
     121,    -1,    -1,    -1,   163,   164,   165,    -1,    -1,    -1,
      12,    13,    -1,    -1,    -1,    -1,    -1,    -1,   139,    -1,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    -1,    -1,    -1,   102,   103,   104,    -1,
      -1,   107,   163,   164,   165,    -1,    -1,   113,   114,    12,
      13,   117,   118,    -1,   120,   121,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
      -1,    -1,    -1,   139,   226,    -1,   235,    -1,    -1,    -1,
      -1,   233,    -1,    -1,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,   163,   164,   165,
     102,   103,   104,    -1,    -1,   107,    -1,    -1,    -1,    -1,
      -1,   113,   114,    -1,   235,   117,   118,    -1,   120,   121,
      -1,    -1,    -1,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    -1,   139,    -1,   102,
     103,   104,    -1,    -1,   107,    -1,    -1,    -1,    -1,    -1,
     113,   114,    -1,    -1,   117,   118,    -1,   120,   121,    -1,
      -1,   163,   164,   165,    -1,    -1,     0,     1,    -1,   235,
       4,    -1,    -1,    -1,    -1,    -1,   139,    -1,    12,    13,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,    -1,    -1,    -1,    -1,   226,    -1,
     163,   164,   165,    -1,    -1,   233,    -1,    -1,    42,    43,
      -1,    -1,    -1,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,    -1,    62,    63,
      64,   226,    -1,   235,    68,    69,    -1,    71,   233,    -1,
      -1,    75,    76,    -1,    78,    79,    -1,    81,    -1,    -1,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    -1,    -1,   101,   102,   103,
     104,   105,   235,   107,    -1,   109,   110,   111,   112,   113,
     114,   115,    -1,   117,   118,   119,   120,   121,   122,    -1,
     124,   125,   126,   127,   128,   129,   130,   131,   132,    -1,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,    -1,    -1,     4,   151,   152,   153,
      -1,    -1,    -1,   157,    12,    13,    -1,    -1,   162,   163,
     164,   165,    -1,    -1,   168,    -1,   170,    -1,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,    -1,    -1,    42,    43,    -1,    -1,   192,   193,
     194,    -1,    -1,    -1,    -1,    -1,    -1,   201,    -1,   203,
      -1,    -1,    -1,    -1,    62,    63,    64,    -1,    -1,    -1,
      68,    69,    -1,    71,    -1,    -1,    -1,    75,    76,    -1,
      78,    79,    -1,    81,    -1,    -1,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    -1,    -1,   101,   102,   103,   104,   105,    -1,   107,
      -1,   109,   110,   111,   112,   113,   114,   115,    -1,   117,
     118,   119,   120,   121,   122,    -1,   124,   125,   126,   127,
     128,   129,   130,   131,   132,    -1,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
      12,    13,    -1,   151,   152,   153,    -1,    -1,    -1,   157,
      -1,    -1,    -1,    -1,   162,   163,   164,   165,    -1,    -1,
     168,    -1,   170,    -1,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,    -1,    -1,
      -1,    -1,    -1,    -1,   192,   193,   194,    -1,    -1,    -1,
      -1,    -1,    -1,   201,    -1,   203,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    -1,    -1,    -1,
     102,   103,   104,    -1,    -1,   107,    -1,    -1,    -1,    -1,
      -1,   113,   114,    -1,    -1,   117,   118,    -1,   120,   121,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,    -1,    -1,    -1,   139,   226,    -1,
      -1,    -1,    -1,    -1,    -1,   233,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
      -1,   163,   164,   165,   226,    -1,    -1,    -1,    -1,    -1,
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
     226,    -1,   228,    -1,   230,   208,   209,   210,   211,   212,
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
      79,    81,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,   101,   102,   103,
     104,   105,   107,   109,   110,   111,   112,   113,   114,   115,
     117,   118,   119,   120,   121,   122,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   151,
     152,   153,   157,   162,   163,   164,   165,   168,   170,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   192,   193,   194,   201,   203,   240,   242,
     243,   263,   282,   283,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   301,   303,   304,   310,   311,   312,   313,
     317,   337,   338,     3,     4,     5,     9,    10,    11,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      65,    66,    67,    70,    72,    73,    74,    80,    82,    83,
     120,   179,   186,   187,   188,   189,   190,   195,   196,   197,
     198,   199,   200,   202,   217,   218,   222,   227,   229,   231,
     232,   234,   236,   261,   314,   315,   317,   332,   333,   337,
     338,    13,    92,   227,   227,     6,   234,     6,     6,     6,
       6,   227,     6,     6,   229,   229,     4,   319,   337,   338,
     227,   229,   261,   261,   227,   234,   227,   227,     4,   227,
     234,   227,   227,     4,   227,   234,   227,   227,   227,   227,
     227,   227,   227,   227,   227,   227,   106,    92,     6,   234,
      86,    89,    92,   227,     4,    37,    38,    39,    40,    41,
      86,    89,    92,    94,   113,   118,   120,   191,   218,   227,
     234,   283,   294,   301,   303,   314,   325,   327,   337,   338,
     227,   234,    92,    92,   113,    89,    92,    94,    86,    89,
      92,    94,    89,    92,    94,    89,    92,   227,    89,   168,
     184,   185,   234,   217,   218,   227,   234,   322,   323,   322,
     234,   234,   322,     4,    86,    90,    96,    97,    99,   100,
     117,   227,    92,    94,    92,    89,     4,   179,   234,   338,
       4,     6,    86,    89,    92,    89,    92,     4,     4,     4,
       5,   227,   325,   326,     4,   227,   227,   227,     4,   234,
     329,   338,     4,   227,   227,   227,     6,     6,   229,   333,
     338,   227,     4,   333,     5,   234,     5,   234,     4,   314,
     337,   229,   227,   234,     6,   227,   234,     6,   227,   229,
     236,   261,     7,   204,   205,   206,   207,   224,   225,   259,
     260,     4,   227,   229,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   227,
     227,   227,   261,   261,   261,   261,   227,   261,   261,   261,
     261,   261,   261,   227,   261,   261,   261,   261,    86,    89,
      92,    94,     7,   227,   227,   227,   261,   261,   227,   227,
     229,   314,   314,   314,   228,   314,   230,   314,     4,   168,
     169,   338,     4,   283,   284,   285,   234,   234,     6,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   226,   234,     6,   227,   229,   231,   260,
       6,   314,     4,   332,   333,   337,   338,   332,   314,   332,
     336,   265,   270,   318,     8,   333,   338,   314,   218,   314,
     327,   328,   314,   314,   227,   314,   328,   314,   314,   227,
     314,   328,   314,   314,   314,   314,   314,   314,   332,   314,
     314,   314,   325,   227,   328,   326,   326,   326,   332,   227,
     229,   261,   227,   229,   261,   261,   261,   261,     5,   171,
     234,     5,   171,     5,   171,     5,   171,   113,    86,    89,
      92,    94,   261,   234,   314,   327,   314,   235,   328,     8,
     219,   227,   229,   261,   231,   314,   328,   227,   227,   227,
     325,   326,   326,   326,   227,   227,   227,   227,   227,   325,
     227,   325,   227,   325,   234,   234,   314,     4,   325,   329,
     234,   234,   322,   322,   322,   314,   314,   217,   218,   234,
     234,   322,   217,   218,   227,   285,   322,   234,   227,   234,
     227,   227,   227,   227,   227,   227,   227,   314,   326,   326,
     326,   227,     4,   229,   229,   285,     6,     6,   234,   234,
     234,   326,   326,   229,   229,   229,   314,     6,     6,   314,
     314,   314,   231,   314,   234,   171,   314,   314,   314,   314,
       6,     6,   234,     6,   285,     6,   285,   227,   229,   234,
     227,   229,   332,   314,   285,   325,   325,   228,   314,   230,
     314,   234,   234,   333,   325,     6,   229,   314,   314,   314,
     314,   314,   314,   314,   314,   314,   314,   314,   314,   314,
     314,   314,   314,   314,   314,   314,   314,   314,   314,   314,
     314,   336,   332,   336,   332,   332,   332,   332,   332,   332,
     332,   325,   332,   332,   314,   332,   332,   332,   336,   332,
     314,   232,   335,   338,   333,   234,   234,   234,   234,   314,
     332,   332,   332,   332,   332,   338,   333,   338,     7,   207,
     259,   228,     7,   207,   259,   230,     7,   259,   260,   231,
       7,   261,   235,    86,    89,    92,    94,   113,   118,   121,
     282,   314,   328,   314,   314,   314,   314,   314,   314,   314,
     314,   314,   314,   314,   314,   314,   314,   314,   244,   314,
     314,     4,   320,     6,   227,   229,   228,   233,   227,   229,
     231,   228,   233,   233,   228,   233,   230,   233,   264,   230,
     264,   234,   321,     8,   233,   233,   228,   219,   233,   235,
     228,   228,   314,   228,   235,   228,   228,   314,   228,   235,
     228,   228,   228,   228,   228,   228,   228,   228,   228,   228,
       7,   314,   235,     6,     6,     6,   228,   314,   314,   228,
     230,   234,   262,   234,   314,   327,   234,   327,   338,   314,
     314,   332,   314,    62,   314,    62,    62,    62,   326,   326,
     326,   326,   327,   328,   228,   235,   314,   234,   314,   327,
     314,   314,   234,   262,   320,   228,   235,   314,   314,   314,
       7,     7,   307,   307,   276,   314,   333,   277,   314,   333,
     278,   314,   333,   279,   314,   333,   314,     6,   314,     6,
     314,     6,   328,   328,   234,   228,     6,   234,   285,   285,
     233,   233,   233,   322,   322,   284,   284,   233,   314,   235,
     298,   233,   285,   314,   314,   314,   314,   314,   314,   314,
     314,   314,   228,     7,   308,     6,     7,   314,     6,   314,
     314,   235,   328,   328,   328,     6,     6,   314,   314,   314,
     228,   228,   228,   228,   168,   233,   285,   234,     8,   228,
     228,   230,   328,   235,   235,   285,   230,   228,   143,   302,
     228,   233,   235,     7,   207,   259,   228,     7,   207,   259,
     230,   314,   328,     6,     6,   314,   228,   230,   262,   262,
     262,   262,   262,   262,   262,   262,   262,   262,   262,   233,
     262,   262,   262,   262,   262,   262,   262,   233,   233,   233,
     262,   233,   262,   262,   228,   228,   233,   262,   262,   233,
     262,   233,   233,   233,   233,   262,   262,   262,   228,   262,
     316,   314,   262,     8,   334,   314,   314,   314,   314,     6,
     233,   233,   228,   233,   262,   233,   262,   228,   228,   230,
      44,    44,   325,     7,   259,   260,    44,    44,   325,   231,
     259,   260,   333,   314,     6,     4,     4,   234,   330,   262,
     234,   234,   234,   234,   227,   113,    89,    92,    94,   235,
     235,     8,     4,   158,   159,   160,   161,   235,   247,   251,
     254,   256,   257,   228,   230,   260,   314,   314,     6,   214,
     241,   328,   314,   314,   320,     6,   328,   314,     6,   332,
       6,   338,     6,   332,   338,   229,   338,   314,   333,     7,
     314,   327,   171,     7,     7,   228,     7,   171,     7,     7,
     228,     7,   171,     7,     7,     7,     7,     7,     7,     7,
       7,     7,   314,   228,   234,     6,   228,   230,   328,   328,
     228,   328,   230,   230,   233,   233,   262,   233,   234,   235,
     234,   234,   234,   262,   235,     7,     8,   328,   228,   230,
     328,     7,   234,   228,   228,   228,   314,   325,     4,   306,
       6,   228,   233,   228,   233,   228,   233,   228,   233,   228,
     228,   228,   235,   235,   328,   231,   285,   235,   235,   322,
     314,   314,   235,   235,   314,   322,   123,   123,   140,   148,
     149,   150,   154,   155,   299,   300,   322,   235,   295,   228,
     235,   228,   228,   228,   228,   228,   228,   228,     7,   314,
       6,   314,   228,   230,   230,   235,   235,   235,   230,   230,
     233,     7,     7,     7,   231,   314,   235,   314,   314,     7,
     231,   235,   235,     7,     6,   314,   235,   234,   325,     6,
      44,    44,   325,   259,   260,    44,    44,   325,   259,   260,
     235,   235,   230,   260,   231,   260,   332,   314,   314,   314,
     314,   328,   332,   314,   325,   332,   332,   332,   272,     8,
     274,   235,   235,   235,   235,   314,   332,   332,   314,   261,
     261,     6,   314,     6,   261,   261,     6,     4,   168,   169,
     314,     6,     6,     6,     7,   229,   329,   331,     6,   328,
     328,   328,   328,   314,   227,   227,   227,   227,   262,   314,
     248,   227,   227,   234,   258,     6,   260,   260,   228,   230,
     214,   332,   228,   228,   230,   228,   233,     7,   227,   229,
     235,   314,   262,   262,   322,    92,    94,   325,   325,     7,
     325,    92,    94,   325,   325,     7,   325,    94,   325,   325,
     325,   325,   325,   325,   325,   325,   325,     6,     7,   328,
     231,   235,   235,   235,   314,   314,   314,   314,   314,   314,
     314,   325,   314,   235,   235,   325,   328,     7,     7,     7,
     123,   305,     6,   259,   314,   259,   314,   259,   314,   259,
     314,     7,     7,     7,     7,     7,   235,     4,   235,   233,
     233,   233,   235,   235,   104,     4,     6,   314,   234,     6,
     227,     6,   156,     6,   156,   235,   300,   233,   299,     7,
       6,     7,     7,     7,     7,     7,     7,     7,   325,     6,
     234,     6,     6,     6,    92,     7,     6,     6,   314,   325,
     325,   325,     4,   233,     8,     8,   228,     4,     4,   233,
     234,     6,   234,   325,   235,   261,   261,     6,   314,     6,
     261,   261,     6,   314,     6,   262,     6,     4,     6,   262,
     262,   262,   262,   262,   233,   233,   262,   228,   262,   262,
     233,   233,   262,   273,   232,   233,   262,   275,   228,   228,
     262,   262,   262,   336,   336,     6,   262,   336,   336,     7,
     259,   260,   231,     7,     6,   329,   314,   233,   235,   235,
     235,   235,   235,   228,   314,   314,   314,   314,   259,   227,
     314,   314,   324,   325,   234,   231,     6,     6,   241,     6,
     314,   234,   314,   333,   228,   230,   272,     6,     6,     6,
     234,   234,   117,   281,   281,   325,     6,   234,   234,     6,
       6,   325,   171,   280,   234,     6,     6,     6,     6,     6,
       6,     6,     6,     6,     5,   235,     4,   262,   228,   230,
     233,   233,   233,   233,   233,   233,   233,     6,   262,     6,
     235,   325,   325,   325,     4,     6,   325,   325,   325,   325,
     325,   325,   325,   234,   234,     7,     6,     7,   314,   314,
     314,   234,   234,   234,   229,     6,   314,   325,   314,     6,
       6,   314,   322,   235,     5,   325,   234,   234,   234,   234,
     234,   234,   234,   325,     6,   328,   234,   314,   230,     6,
       6,   167,   314,   314,   314,     6,     6,     7,   333,   285,
     285,   233,     6,   262,   336,   336,     6,   262,   336,   336,
       6,   259,   260,   332,   314,   332,     4,   314,     4,   183,
       6,   262,   262,     6,   262,   262,   333,   314,     6,     4,
     330,     6,   230,   329,     6,     6,     6,     6,   228,   228,
     228,   228,   325,   245,   314,   233,   233,   233,   235,   246,
     314,     4,   332,   233,   325,   333,     7,     7,   230,   314,
     314,   322,     6,     6,     6,   314,   314,     6,    90,     6,
     314,     5,   234,   314,   314,   314,   314,   314,   314,   314,
     234,     6,   280,     6,   314,     6,     6,     6,     6,     6,
       4,     6,     6,   328,   328,   314,   314,   333,   235,   228,
     233,   235,   284,   284,   314,   314,   235,   233,   228,   235,
     233,     6,     6,   324,   322,   322,   322,   322,   322,   218,
     322,     6,   235,   314,     6,     6,   325,   233,   235,     8,
     235,   228,   234,   314,   333,   233,   302,   302,   325,     6,
     262,   262,     6,   262,   262,   325,   228,   262,   262,   234,
     325,   333,   234,   314,   333,   333,     6,     6,     6,     6,
       6,     6,     7,     6,   231,     6,   228,   233,   314,   314,
     325,   234,   233,   235,     6,   314,   266,   269,   234,   234,
     235,   235,   235,   235,   234,   235,     5,   324,   262,   262,
     233,   233,   233,   233,   233,   314,     6,   234,   235,   235,
     234,     6,     6,   234,   314,   235,   235,   235,   230,     6,
     325,     7,   234,   314,   235,   233,   233,   233,   233,   233,
     233,     6,   235,   166,   314,   314,   328,     6,     6,   333,
     235,   235,   235,     6,     6,     6,     6,     6,   271,   314,
     327,   336,   329,   169,   249,   314,   233,   233,   324,   314,
       6,   233,   272,   274,   325,   325,     6,     6,     6,     6,
     314,     6,     6,   235,   314,   314,   314,   314,   314,   235,
     324,   127,   128,   133,   309,   127,   128,   309,   328,   284,
     233,   235,     6,   235,   325,   285,   235,     6,   328,   322,
     322,   322,   322,   322,   314,   235,   235,   235,   228,   234,
       6,   233,   235,     7,     7,   235,     6,   234,   314,   314,
     235,   314,   235,   235,   268,   267,   235,   234,   233,   233,
     233,   233,   233,   235,   234,   322,   325,     6,   234,   322,
       6,   235,   235,   314,     6,   123,   235,   296,   234,   235,
     233,   233,   233,   233,   233,     6,     6,     6,   285,   314,
     333,   338,   246,   228,   233,     6,   234,   233,   272,   272,
     314,   314,   314,   314,   314,   314,     6,   322,     6,   322,
       6,     6,   235,   314,   299,   285,     6,   328,   328,   328,
     328,   322,   328,   302,     7,   227,   235,   252,   314,   324,
     314,   235,   235,   233,   233,   233,   233,   233,   233,   233,
     233,     6,   235,   235,   297,   235,   235,   235,   235,   233,
     235,   235,   333,   228,     6,   234,   228,   235,   235,   314,
     314,   314,   314,   314,   314,   322,   322,   299,     6,     6,
       6,     6,   328,     6,     6,   250,   332,   255,   234,     6,
     235,   262,   233,   233,   233,   233,   233,   233,   235,   235,
     233,   235,   234,   324,     6,   314,   314,   314,   314,   314,
     314,     6,   332,     6,   253,   332,   235,   235,   235,   235,
     235,   235,   235,   233,   235,     6,     6,     6,   332,     6
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
#line 228 "Gmsh.y"
    { yyerrok; return 1; ;}
    break;

  case 6:
#line 239 "Gmsh.y"
    { return 1; ;}
    break;

  case 7:
#line 240 "Gmsh.y"
    { return 1; ;}
    break;

  case 8:
#line 241 "Gmsh.y"
    { return 1; ;}
    break;

  case 9:
#line 243 "Gmsh.y"
    {
      factory = (yyvsp[(3) - (5)].c);
      if(factory == "OpenCASCADE"){
        if(!GModel::current()->getOCCInternals())
          GModel::current()->createOCCInternals();
        for(int dim = -2; dim <= 3; dim++)
          GModel::current()->getOCCInternals()->setMaxTag
            (dim, GModel::current()->getGEOInternals()->getMaxTag(dim));
      }
      else if(GModel::current()->getOCCInternals()){
        for(int dim = -2; dim <= 3; dim++)
          GModel::current()->getGEOInternals()->setMaxTag
            (dim, GModel::current()->getOCCInternals()->getMaxTag(dim));
      }
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 10:
#line 259 "Gmsh.y"
    { return 1; ;}
    break;

  case 11:
#line 260 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 12:
#line 261 "Gmsh.y"
    { return 1; ;}
    break;

  case 13:
#line 262 "Gmsh.y"
    { return 1; ;}
    break;

  case 14:
#line 263 "Gmsh.y"
    { return 1; ;}
    break;

  case 15:
#line 264 "Gmsh.y"
    { return 1; ;}
    break;

  case 16:
#line 265 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 17:
#line 266 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 18:
#line 267 "Gmsh.y"
    { return 1; ;}
    break;

  case 19:
#line 268 "Gmsh.y"
    { return 1; ;}
    break;

  case 20:
#line 269 "Gmsh.y"
    { return 1; ;}
    break;

  case 21:
#line 270 "Gmsh.y"
    { return 1; ;}
    break;

  case 22:
#line 271 "Gmsh.y"
    { return 1; ;}
    break;

  case 23:
#line 272 "Gmsh.y"
    { return 1; ;}
    break;

  case 24:
#line 273 "Gmsh.y"
    { return 1; ;}
    break;

  case 25:
#line 274 "Gmsh.y"
    { return 1; ;}
    break;

  case 26:
#line 279 "Gmsh.y"
    {
      (yyval.c) = (char*)"w";
    ;}
    break;

  case 27:
#line 283 "Gmsh.y"
    {
      (yyval.c) = (char*)"a";
    ;}
    break;

  case 28:
#line 290 "Gmsh.y"
    {
      Msg::Direct((yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 29:
#line 295 "Gmsh.y"
    {
      Msg::Error((yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 30:
#line 300 "Gmsh.y"
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
#line 314 "Gmsh.y"
    {
      char tmpstring[5000];
      int i = printListOfDouble((yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].l), tmpstring);
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
#line 327 "Gmsh.y"
    {
      char tmpstring[5000];
      int i = printListOfDouble((yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].l), tmpstring);
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
#line 340 "Gmsh.y"
    {
      char tmpstring[5000];
      int i = printListOfDouble((yyvsp[(3) - (9)].c), (yyvsp[(5) - (9)].l), tmpstring);
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
#line 368 "Gmsh.y"
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
#line 382 "Gmsh.y"
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
#line 395 "Gmsh.y"
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
#line 408 "Gmsh.y"
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
#line 426 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData = new PViewDataList();
#endif
    ;}
    break;

  case 44:
#line 440 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(1) - (1)].d)); ;}
    break;

  case 45:
#line 442 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(3) - (3)].d)); ;}
    break;

  case 46:
#line 447 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(1) - (1)].d)); ;}
    break;

  case 47:
#line 449 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(3) - (3)].d)); ;}
    break;

  case 48:
#line 454 "Gmsh.y"
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
#line 558 "Gmsh.y"
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
#line 568 "Gmsh.y"
    {
#if defined(HAVE_POST)
      if(ViewValueList) (*ViewNumList)++;
#endif
    ;}
    break;

  case 51:
#line 577 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[(1) - (1)].c)[i]);
#endif
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 52:
#line 584 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[(3) - (3)].c)[i]);
#endif
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 53:
#line 594 "Gmsh.y"
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
#line 603 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->NbT2++;
#endif
    ;}
    break;

  case 55:
#line 612 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[(1) - (1)].c)[i]);
#endif
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 56:
#line 619 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[(3) - (3)].c)[i]);
#endif
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 57:
#line 629 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->T3D.push_back((yyvsp[(3) - (10)].d)); ViewData->T3D.push_back((yyvsp[(5) - (10)].d));
      ViewData->T3D.push_back((yyvsp[(7) - (10)].d)); ViewData->T3D.push_back((yyvsp[(9) - (10)].d));
      ViewData->T3D.push_back(ViewData->T3C.size());
#endif
    ;}
    break;

  case 58:
#line 637 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->NbT3++;
#endif
    ;}
    break;

  case 59:
#line 647 "Gmsh.y"
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
#line 666 "Gmsh.y"
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
#line 685 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewValueList = &ViewData->Time;
#endif
    ;}
    break;

  case 62:
#line 691 "Gmsh.y"
    {
    ;}
    break;

  case 63:
#line 698 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 64:
#line 699 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 65:
#line 700 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 66:
#line 701 "Gmsh.y"
    { (yyval.i) = 3; ;}
    break;

  case 67:
#line 702 "Gmsh.y"
    { (yyval.i) = 4; ;}
    break;

  case 68:
#line 706 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 69:
#line 707 "Gmsh.y"
    { (yyval.i) = -1; ;}
    break;

  case 70:
#line 713 "Gmsh.y"
    { (yyval.c) = (char*)"("; ;}
    break;

  case 71:
#line 713 "Gmsh.y"
    { (yyval.c) = (char*)"["; ;}
    break;

  case 72:
#line 714 "Gmsh.y"
    { (yyval.c) = (char*)")"; ;}
    break;

  case 73:
#line 714 "Gmsh.y"
    { (yyval.c) = (char*)"]"; ;}
    break;

  case 77:
#line 724 "Gmsh.y"
    {
      Msg::SetOnelabNumber((yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].d));
      Free((yyvsp[(3) - (7)].c));
    ;}
    break;

  case 78:
#line 729 "Gmsh.y"
    {
      Msg::SetOnelabString((yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].c));
      Free((yyvsp[(3) - (7)].c));
      Free((yyvsp[(5) - (7)].c));
    ;}
    break;

  case 79:
#line 735 "Gmsh.y"
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
#line 797 "Gmsh.y"
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
#line 814 "Gmsh.y"
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
#line 843 "Gmsh.y"
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
#line 872 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    ;}
    break;

  case 84:
#line 877 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    ;}
    break;

  case 85:
#line 882 "Gmsh.y"
    {
      incrementVariable((yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].i));
      Free((yyvsp[(1) - (6)].c));
    ;}
    break;

  case 86:
#line 887 "Gmsh.y"
    {
      incrementVariable((yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].i));
      Free((yyvsp[(1) - (6)].c));
    ;}
    break;

  case 87:
#line 892 "Gmsh.y"
    {
      assignVariables((yyvsp[(1) - (9)].c), (yyvsp[(4) - (9)].l), (yyvsp[(7) - (9)].i), (yyvsp[(8) - (9)].l));
      Free((yyvsp[(1) - (9)].c));
      List_Delete((yyvsp[(4) - (9)].l));
      List_Delete((yyvsp[(8) - (9)].l));
    ;}
    break;

  case 88:
#line 899 "Gmsh.y"
    {
      assignVariables((yyvsp[(1) - (9)].c), (yyvsp[(4) - (9)].l), (yyvsp[(7) - (9)].i), (yyvsp[(8) - (9)].l));
      Free((yyvsp[(1) - (9)].c));
      List_Delete((yyvsp[(4) - (9)].l));
      List_Delete((yyvsp[(8) - (9)].l));
    ;}
    break;

  case 89:
#line 909 "Gmsh.y"
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
#line 938 "Gmsh.y"
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
#line 967 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    ;}
    break;

  case 92:
#line 972 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    ;}
    break;

  case 93:
#line 977 "Gmsh.y"
    {
      incrementVariable((yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].i));
      Free((yyvsp[(1) - (6)].c));
    ;}
    break;

  case 94:
#line 982 "Gmsh.y"
    {
      incrementVariable((yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].i));
      Free((yyvsp[(1) - (6)].c));
    ;}
    break;

  case 95:
#line 990 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[(1) - (4)].c)] = std::vector<std::string>(1, (yyvsp[(3) - (4)].c));
      Free((yyvsp[(1) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 96:
#line 999 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[(1) - (8)].c)] = std::vector<std::string>();
      Free((yyvsp[(1) - (8)].c));
    ;}
    break;

  case 97:
#line 1005 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[(1) - (8)].c)] = std::vector<std::string>();
      Free((yyvsp[(1) - (8)].c));
    ;}
    break;

  case 98:
#line 1011 "Gmsh.y"
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
#line 1024 "Gmsh.y"
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

  case 101:
#line 1052 "Gmsh.y"
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
#line 1069 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[(1) - (8)].c)] = std::vector<std::string>();
      Free((yyvsp[(1) - (8)].c));
    ;}
    break;

  case 103:
#line 1075 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[(1) - (8)].c)] = std::vector<std::string>();
      Free((yyvsp[(1) - (8)].c));
    ;}
    break;

  case 104:
#line 1081 "Gmsh.y"
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
#line 1094 "Gmsh.y"
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

  case 107:
#line 1122 "Gmsh.y"
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
#line 1139 "Gmsh.y"
    {
      std::string tmp((yyvsp[(5) - (6)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (6)].c), 0, (yyvsp[(3) - (6)].c), tmp);
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 109:
#line 1146 "Gmsh.y"
    {
      std::string tmp((yyvsp[(8) - (9)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (9)].c), (int)(yyvsp[(3) - (9)].d), (yyvsp[(6) - (9)].c), tmp);
      Free((yyvsp[(1) - (9)].c)); Free((yyvsp[(6) - (9)].c)); Free((yyvsp[(8) - (9)].c));
    ;}
    break;

  case 110:
#line 1155 "Gmsh.y"
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
#line 1174 "Gmsh.y"
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
#line 1193 "Gmsh.y"
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
#line 1203 "Gmsh.y"
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
#line 1215 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (8)].c), 0, (yyvsp[(5) - (8)].c), (yyvsp[(7) - (8)].u));
      Free((yyvsp[(1) - (8)].c)); Free((yyvsp[(5) - (8)].c));
    ;}
    break;

  case 115:
#line 1221 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (11)].c), (int)(yyvsp[(3) - (11)].d), (yyvsp[(8) - (11)].c), (yyvsp[(10) - (11)].u));
      Free((yyvsp[(1) - (11)].c)); Free((yyvsp[(8) - (11)].c));
    ;}
    break;

  case 116:
#line 1229 "Gmsh.y"
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
#line 1250 "Gmsh.y"
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
#line 1273 "Gmsh.y"
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
#line 1284 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      if(!GModel::current()->getFields()->newField((int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c)))
	yymsg(0, "Cannot create field %i of type '%s'", (int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c));
#endif
      Free((yyvsp[(6) - (7)].c));
    ;}
    break;

  case 120:
#line 1292 "Gmsh.y"
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
#line 1314 "Gmsh.y"
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
#line 1337 "Gmsh.y"
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
#line 1375 "Gmsh.y"
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
#line 1396 "Gmsh.y"
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
#line 1408 "Gmsh.y"
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
#line 1426 "Gmsh.y"
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
#line 1435 "Gmsh.y"
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
#line 1444 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 132:
#line 1446 "Gmsh.y"
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
#line 1464 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 134:
#line 1466 "Gmsh.y"
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
#line 1482 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 136:
#line 1484 "Gmsh.y"
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
#line 1500 "Gmsh.y"
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
#line 1509 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 139:
#line 1511 "Gmsh.y"
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
#line 1525 "Gmsh.y"
    {
      std::string name((yyvsp[(3) - (3)].c));
      Msg::UndefineOnelabParameter(name);
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 142:
#line 1533 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(doubleXstring));
      doubleXstring v = {(yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].c)};
      List_Add((yyval.l), &v);
    ;}
    break;

  case 143:
#line 1539 "Gmsh.y"
    {
      doubleXstring v = {(yyvsp[(3) - (5)].d), (yyvsp[(5) - (5)].c)};
      List_Add((yyval.l), &v);
    ;}
    break;

  case 144:
#line 1544 "Gmsh.y"
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
#line 1575 "Gmsh.y"
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
#line 1586 "Gmsh.y"
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
#line 1601 "Gmsh.y"
    {
      std::string key((yyvsp[(2) - (3)].c));
      std::string val((yyvsp[(3) - (3)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(2) - (3)].c));
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 152:
#line 1617 "Gmsh.y"
    {
      std::string key((yyvsp[(2) - (3)].c));
      double val = (yyvsp[(3) - (3)].d);
      floatOptions[key].push_back(val);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 153:
#line 1625 "Gmsh.y"
    {
      std::string key((yyvsp[(2) - (3)].c));
      std::string val((yyvsp[(3) - (3)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(2) - (3)].c));
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 154:
#line 1634 "Gmsh.y"
    {
      std::string key("Macro");
      std::string val((yyvsp[(3) - (3)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 155:
#line 1642 "Gmsh.y"
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
#line 1660 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    ;}
    break;

  case 157:
#line 1664 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[(1) - (1)].c)), 0, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 158:
#line 1670 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (3)].c)), 0, (yyvsp[(3) - (3)].d));
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 159:
#line 1678 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    ;}
    break;

  case 160:
#line 1682 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[(1) - (1)].c)), 1, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 161:
#line 1688 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (3)].c)), 1, (yyvsp[(3) - (3)].d));
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 162:
#line 1696 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    ;}
    break;

  case 163:
#line 1700 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[(1) - (1)].c)), 2, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 164:
#line 1706 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (3)].c)), 2, (yyvsp[(3) - (3)].d));
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 165:
#line 1714 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    ;}
    break;

  case 166:
#line 1718 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[(1) - (1)].c)), 3, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 167:
#line 1724 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (3)].c)), 3, (yyvsp[(3) - (3)].d));
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 168:
#line 1732 "Gmsh.y"
    {
      (yyval.i) = -1;
    ;}
    break;

  case 169:
#line 1736 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(4) - (5)].d);
    ;}
    break;

  case 170:
#line 1742 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = 0.;
    ;}
    break;

  case 171:
#line 1746 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 172:
#line 1753 "Gmsh.y"
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
#line 1774 "Gmsh.y"
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
#line 1788 "Gmsh.y"
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
#line 1802 "Gmsh.y"
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
#line 1837 "Gmsh.y"
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
#line 1875 "Gmsh.y"
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
#line 1889 "Gmsh.y"
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
#line 1904 "Gmsh.y"
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
#line 1923 "Gmsh.y"
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
#line 1932 "Gmsh.y"
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
#line 1946 "Gmsh.y"
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
#line 1961 "Gmsh.y"
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
#line 1975 "Gmsh.y"
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
#line 1994 "Gmsh.y"
    {
      yymsg(2, "'Ruled Surface' command is deprecated: use 'Surface' instead");
      int num = (int)(yyvsp[(4) - (9)].d);
      std::vector<int> wires; ListOfDouble2Vector((yyvsp[(7) - (9)].l), wires);
      GModel::current()->getGEOInternals()->addSurfaceFilling(num, wires, (yyvsp[(8) - (9)].i));
      List_Delete((yyvsp[(7) - (9)].l));
      (yyval.s).Type =  MSH_SURF_REGL;
      (yyval.s).Num = num;
    ;}
    break;

  case 186:
#line 2004 "Gmsh.y"
    {
      myGmshSurface = 0;
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 187:
#line 2010 "Gmsh.y"
    {
      myGmshSurface = gmshSurface::getSurface((int)(yyvsp[(3) - (4)].d));
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 188:
#line 2016 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (10)].d);
      myGmshSurface = gmshParametricSurface::NewParametricSurface(num, (yyvsp[(7) - (10)].c), (yyvsp[(8) - (10)].c), (yyvsp[(9) - (10)].c));
      (yyval.s).Type = 0;
      (yyval.s).Num = num;
    ;}
    break;

  case 189:
#line 2023 "Gmsh.y"
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
#line 2050 "Gmsh.y"
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
#line 2065 "Gmsh.y"
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
#line 2085 "Gmsh.y"
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
#line 2106 "Gmsh.y"
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
#line 2127 "Gmsh.y"
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
#line 2148 "Gmsh.y"
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
#line 2170 "Gmsh.y"
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
#line 2192 "Gmsh.y"
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
#line 2213 "Gmsh.y"
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
#line 2236 "Gmsh.y"
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
#line 2246 "Gmsh.y"
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
#line 2266 "Gmsh.y"
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
#line 2281 "Gmsh.y"
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

  case 204:
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

  case 205:
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

  case 206:
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

  case 207:
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

  case 208:
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

  case 209:
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

  case 210:
#line 2379 "Gmsh.y"
    {
      std::vector<int> tags[4]; ListOfShapes2Vectors((yyvsp[(4) - (5)].l), tags);
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        GModel::current()->getOCCInternals()->translate(tags, (yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2]);
      }
      else{
        GModel::current()->getGEOInternals()->translate(tags, (yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2]);
      }
      (yyval.l) = (yyvsp[(4) - (5)].l);
    ;}
    break;

  case 211:
#line 2390 "Gmsh.y"
    {
      std::vector<int> tags[4]; ListOfShapes2Vectors((yyvsp[(10) - (11)].l), tags);
      if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        GModel::current()->getOCCInternals()->rotate
          (tags, (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(7) - (11)].d));
      }
      else{
        GModel::current()->getGEOInternals()->rotate
          (tags, (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(7) - (11)].d));
      }
      (yyval.l) = (yyvsp[(10) - (11)].l);
    ;}
    break;

  case 212:
#line 2403 "Gmsh.y"
    {
      std::vector<int> tags[4]; ListOfShapes2Vectors((yyvsp[(4) - (5)].l), tags);
      if(factory == "OpenCASCADE"){
        Msg::Error("Symmetry not implemented yet with OpenCASCADE factory");
      }
      else{
        GModel::current()->getGEOInternals()->symmetry
          (tags, (yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], (yyvsp[(2) - (5)].v)[3]);
      }
      (yyval.l) = (yyvsp[(4) - (5)].l);
    ;}
    break;

  case 213:
#line 2415 "Gmsh.y"
    {
      std::vector<int> tags[4]; ListOfShapes2Vectors((yyvsp[(8) - (9)].l), tags);
      if(factory == "OpenCASCADE"){
        yymsg(0, "Dilate not implemented yet with OpenCASCADE factory");
      }
      else{
        GModel::current()->getGEOInternals()->dilate
          (tags, (yyvsp[(3) - (9)].v)[0], (yyvsp[(3) - (9)].v)[1], (yyvsp[(3) - (9)].v)[2], (yyvsp[(5) - (9)].d), (yyvsp[(5) - (9)].d), (yyvsp[(5) - (9)].d));
      }
      (yyval.l) = (yyvsp[(8) - (9)].l);
    ;}
    break;

  case 214:
#line 2427 "Gmsh.y"
    {
      std::vector<int> tags[4]; ListOfShapes2Vectors((yyvsp[(8) - (9)].l), tags);
      if(factory == "OpenCASCADE"){
        yymsg(0, "Dilate not implemented yet with OpenCASCADE factory");
      }
      else{
        GModel::current()->getGEOInternals()->dilate
          (tags, (yyvsp[(3) - (9)].v)[0], (yyvsp[(3) - (9)].v)[1], (yyvsp[(3) - (9)].v)[2], (yyvsp[(5) - (9)].v)[0], (yyvsp[(5) - (9)].v)[1], (yyvsp[(5) - (9)].v)[2]);
      }
      (yyval.l) = (yyvsp[(8) - (9)].l);
    ;}
    break;

  case 215:
#line 2439 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
      std::string action((yyvsp[(1) - (4)].c));
      if(action == "Duplicata"){
        // don't use per-dimension vectors here, in order to respect the input
        // ordering (points can e.g. be given after surfaces) in the output
        for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
          Shape s; List_Read((yyvsp[(3) - (4)].l), i, &s); int dim = s.Type / 100 - 1;
          if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
            s.Num = GModel::current()->getOCCInternals()->copy(dim, s.Num);
          }
          else{
            s.Num = GModel::current()->getGEOInternals()->copy(dim, s.Num);
          }
          List_Add((yyval.l), &s);
        }
      }
      else if(action == "Boundary" || action == "CombinedBoundary"){
        // boundary operations are performed directly on GModel, which enables
        // to compute the boundary of hybrid CAD models; this also automatically
        // binds all boundary entities for OCC models
        if(GModel::current()->getOCCInternals() &&
           GModel::current()->getOCCInternals()->getChanged())
          GModel::current()->getOCCInternals()->synchronize(GModel::current());
        if(GModel::current()->getGEOInternals()->getChanged())
          GModel::current()->getGEOInternals()->synchronize(GModel::current());
        std::vector<int> in[4], out[4]; ListOfShapes2Vectors((yyvsp[(3) - (4)].l), in);
        GModel::current()->getBoundaryTags(in, out, action == "CombinedBoundary");
        Vectors2ListOfShapes(out, (yyval.l));
      }
      else{
        yymsg(0, "Unknown action on multiple shapes: %s", (yyvsp[(1) - (4)].c));
      }
      Free((yyvsp[(1) - (4)].c));
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 216:
#line 2476 "Gmsh.y"
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

  case 217:
#line 2487 "Gmsh.y"
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

  case 218:
#line 2502 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 219:
#line 2503 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 220:
#line 2508 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    ;}
    break;

  case 221:
#line 2512 "Gmsh.y"
    {
      List_Add((yyval.l), &(yyvsp[(2) - (2)].s));
    ;}
    break;

  case 222:
#line 2516 "Gmsh.y"
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

  case 223:
#line 2527 "Gmsh.y"
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

  case 224:
#line 2538 "Gmsh.y"
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

  case 225:
#line 2549 "Gmsh.y"
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

  case 226:
#line 2565 "Gmsh.y"
    {
      if(List_Nbr((yyvsp[(7) - (8)].l)) == 4){
        int t = (int)(yyvsp[(4) - (8)].d);
        if(gLevelset::find(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          double d[4];
          for(int i = 0; i < 4; i++)
            List_Read((yyvsp[(7) - (8)].l), i, &d[i]);
          gLevelset *ls = new gLevelsetPlane(d[0], d[1], d[2], d[3], t);
          gLevelset::add(ls);
        }
      }
      else
        yymsg(0, "Wrong number of arguments for levelset definition");
      List_Delete((yyvsp[(7) - (8)].l));
    ;}
    break;

  case 227:
#line 2584 "Gmsh.y"
    {
      int t = (int)(yyvsp[(4) - (10)].d);
      if(gLevelset::find(t)){
	yymsg(0, "Levelset %d already exists", t);
      }
      else {
	fullMatrix<double> centers(List_Nbr((yyvsp[(8) - (10)].l)),3);
	for (int i = 0; i < List_Nbr((yyvsp[(8) - (10)].l)); i++){
	  List_T *l = *(List_T**)List_Pointer((yyvsp[(8) - (10)].l), i);
	  for (int j = 0; j < List_Nbr(l); j++){
	    centers(i,j) = (double)(*(double*)List_Pointer(l, j));
	  }
	}
        gLevelset *ls = new gLevelsetPoints(centers, t);
        gLevelset::add(ls);
      }
      for(int i = 0; i < List_Nbr((yyvsp[(8) - (10)].l)); i++)
        List_Delete(*(List_T**)List_Pointer((yyvsp[(8) - (10)].l), i));
      List_Delete((yyvsp[(8) - (10)].l));
    ;}
    break;

  case 228:
#line 2606 "Gmsh.y"
    {
      int t = (int)(yyvsp[(4) - (14)].d);
      if(gLevelset::find(t)){
        yymsg(0, "Levelset %d already exists", t);
      }
      else {
        double pt[3] = {(yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2]};
        double n[3] = {(yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2]};
        gLevelset *ls = new gLevelsetPlane(pt, n, t);
        gLevelset::add(ls);
      }
      List_Delete((yyvsp[(12) - (14)].l));
    ;}
    break;

  case 229:
#line 2621 "Gmsh.y"
    {
      int t = (int)(yyvsp[(4) - (16)].d);
      if(gLevelset::find(t)){
        yymsg(0, "Levelset %d already exists", t);
      }
      else {
        double pt1[3] = {(yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2]};
        double pt2[3] = {(yyvsp[(10) - (16)].v)[0], (yyvsp[(10) - (16)].v)[1], (yyvsp[(10) - (16)].v)[2]};
        double pt3[3] = {(yyvsp[(12) - (16)].v)[0], (yyvsp[(12) - (16)].v)[1], (yyvsp[(12) - (16)].v)[2]};
        gLevelset *ls = new gLevelsetPlane(pt1, pt2, pt3, t);
        gLevelset::add(ls);
      }
      List_Delete((yyvsp[(14) - (16)].l));
    ;}
    break;

  case 230:
#line 2636 "Gmsh.y"
    {
      if(List_Nbr((yyvsp[(10) - (12)].l)) == 1){
        int t = (int)(yyvsp[(4) - (12)].d);
        if(gLevelset::find(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          double d;
          List_Read((yyvsp[(10) - (12)].l), 0, &d);
          gLevelset *ls = new gLevelsetSphere((yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], d, t);
          gLevelset::add(ls);
        }
      }
      else
        yymsg(0, "Wrong number of arguments for levelset definition");
      List_Delete((yyvsp[(10) - (12)].l));
    ;}
    break;

  case 231:
#line 2655 "Gmsh.y"
    {
      if(List_Nbr((yyvsp[(12) - (14)].l)) == 1){
        int t = (int)(yyvsp[(4) - (14)].d);
        if(gLevelset::find(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          double d;
          List_Read((yyvsp[(12) - (14)].l), 0, &d);
          double pt[3] = {(yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2]};
          double dir[3] = {(yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2]};
          gLevelset *ls = new gLevelsetGenCylinder(pt, dir, d, t);
          gLevelset::add(ls);
        }
      }
      else if(List_Nbr((yyvsp[(12) - (14)].l)) == 2){
        int t = (int)(yyvsp[(4) - (14)].d);
        if(gLevelset::find(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          double d[2];
          for(int i = 0; i < 2; i++)
            List_Read((yyvsp[(12) - (14)].l), i, &d[i]);
          double pt[3] = {(yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2]};
          double dir[3] = {(yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2]};
          gLevelset *ls = new gLevelsetCylinder(pt, dir, d[0], d[1], t);
          gLevelset::add(ls);
        }
      }
      else if(List_Nbr((yyvsp[(12) - (14)].l)) == 3){
        int t = (int)(yyvsp[(4) - (14)].d);
        if(gLevelset::find(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          double d[3];
          for(int i = 0; i < 3; i++)
            List_Read((yyvsp[(12) - (14)].l), i, &d[i]);
          double pt[3] = {(yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2]};
          double dir[3] = {(yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2]};
          gLevelset *ls = new gLevelsetCylinder(pt, dir, d[0], d[1], d[2], t);
          gLevelset::add(ls);
        }
      }
      else
        yymsg(0, "Wrong number of arguments for levelset definition");
      List_Delete((yyvsp[(12) - (14)].l));
    ;}
    break;

  case 232:
#line 2706 "Gmsh.y"
    {
      if(List_Nbr((yyvsp[(12) - (14)].l)) == 1){
        int t = (int)(yyvsp[(4) - (14)].d);
        if(gLevelset::find(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          double d;
          List_Read((yyvsp[(12) - (14)].l), 0, &d);
          double pt[3] = {(yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2]};
          double dir[3] = {(yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2]};
          gLevelset *ls = new gLevelsetCone(pt, dir, d, t);
          gLevelset::add(ls);
        }
      }
      else
        yymsg(0, "Wrong number of arguments for levelset definition");
      List_Delete((yyvsp[(12) - (14)].l));
    ;}
    break;

  case 233:
#line 2727 "Gmsh.y"
    {
      if(List_Nbr((yyvsp[(12) - (14)].l)) == 3){
        int t = (int)(yyvsp[(4) - (14)].d);
        if(gLevelset::find(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          double d[3];
          for(int i = 0; i < 3; i++)
            List_Read((yyvsp[(12) - (14)].l), i, &d[i]);
          double pt[3] = {(yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2]};
          double dir[3] = {(yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2]};
          gLevelset *ls = new gLevelsetEllipsoid(pt, dir, d[0], d[1], d[2], t);
          gLevelset::add(ls);
        }
      }
      else
        yymsg(0, "Wrong number of arguments for levelset definition");
      List_Delete((yyvsp[(12) - (14)].l));
    ;}
    break;

  case 234:
#line 2749 "Gmsh.y"
    {
      if(List_Nbr((yyvsp[(12) - (14)].l)) == 5){
        int t = (int)(yyvsp[(4) - (14)].d);
        if(gLevelset::find(t)){
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
          gLevelset::add(ls);
        }
      }
      else
        yymsg(0, "Wrong number of arguments for levelset definition");
      List_Delete((yyvsp[(12) - (14)].l));
    ;}
    break;

  case 235:
#line 2771 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (8)].c), "Union")){
        int t = (int)(yyvsp[(4) - (8)].d);
        if(gLevelset::find(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          std::vector<gLevelset *> vl;
          for(int i = 0; i < List_Nbr((yyvsp[(7) - (8)].l)); i++) {
            double d; List_Read((yyvsp[(7) - (8)].l), i, &d);
            gLevelset *pl = gLevelset::find((int)d);
	    if(!pl) yymsg(0, "Unknown levelset %d", (int)d);
            else vl.push_back(pl);
          }
          gLevelset *ls = new gLevelsetUnion(vl, true, t);
          gLevelset::add(ls);
        }
      }
      else if(!strcmp((yyvsp[(2) - (8)].c), "Intersection")){
        int t = (int)(yyvsp[(4) - (8)].d);
        if(gLevelset::find(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          std::vector<gLevelset *> vl;
          for(int i = 0; i < List_Nbr((yyvsp[(7) - (8)].l)); i++) {
            double d; List_Read((yyvsp[(7) - (8)].l), i, &d);
            gLevelset *pl = gLevelset::find((int)d);
	    if(!pl) yymsg(0, "Unknown levelset %d", (int)d);
            else vl.push_back(pl);
          }
          gLevelset *ls = new gLevelsetIntersection(vl, true, t);
          gLevelset::add(ls);
        }
      }
      else if(!strcmp((yyvsp[(2) - (8)].c), "Cut")){
        int t = (int)(yyvsp[(4) - (8)].d);
        if(gLevelset::find(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          std::vector<gLevelset *> vl;
          for(int i = 0; i < List_Nbr((yyvsp[(7) - (8)].l)); i++) {
            double d; List_Read((yyvsp[(7) - (8)].l), i, &d);
            gLevelset *pl = gLevelset::find((int)d);
	    if(!pl) yymsg(0, "Unknown levelset %d", (int)d);
            else vl.push_back(pl);
          }
          gLevelset *ls = new gLevelsetCut(vl, true, t);
          gLevelset::add(ls);
        }
      }
      else if(!strcmp((yyvsp[(2) - (8)].c), "Crack")){
        int t = (int)(yyvsp[(4) - (8)].d);
        if(gLevelset::find(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          std::vector<gLevelset *> vl;
          for(int i = 0; i < List_Nbr((yyvsp[(7) - (8)].l)); i++) {
            double d; List_Read((yyvsp[(7) - (8)].l), i, &d);
            gLevelset *pl = gLevelset::find((int)d);
	    if(!pl) yymsg(0, "Unknown levelset %d", (int)d);
            else vl.push_back(pl);
          }
          gLevelset *ls = new gLevelsetCrack(vl, false, t);
          gLevelset::add(ls);
        }
      }
      else if(!strcmp((yyvsp[(2) - (8)].c), "Reverse")){
        int t = (int)(yyvsp[(4) - (8)].d);
        if(gLevelset::find(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          double d;
          List_Read((yyvsp[(7) - (8)].l), 0, &d);
          gLevelset *pl = gLevelset::find((int)d);
          gLevelset *ls = NULL;
          if(!pl) yymsg(0, "Unknown levelset %d", (int)d);
          else ls = new gLevelsetReverse(pl, t);
          if(ls) gLevelset::add(ls);
        }
      }
#if defined(HAVE_POST)
      else if(!strcmp((yyvsp[(2) - (8)].c), "PostView")){
        int t = (int)(yyvsp[(4) - (8)].d);
        if(gLevelset::find(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          if(List_Nbr((yyvsp[(7) - (8)].l)) > 0){
            double d; List_Read((yyvsp[(7) - (8)].l), 0, &d);
            gLevelset *ls = new gLevelsetPostView((int)d, t);
            gLevelset::add(ls);
          }
        }
      }
#endif
      else
        yymsg(0, "Wrong number of arguments for levelset definition");
      Free((yyvsp[(2) - (8)].c));
      List_Delete((yyvsp[(7) - (8)].l));
    ;}
    break;

  case 236:
#line 2876 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (8)].c), "MathEval")){
        int t = (int)(yyvsp[(4) - (8)].d);
        if(gLevelset::find(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          gLevelset *ls = new gLevelsetMathEval((yyvsp[(7) - (8)].c), t);
          gLevelset::add(ls);
        }
      }
      else
        yymsg(0, "Unknown levelset '%s'", (yyvsp[(2) - (8)].c));
      Free((yyvsp[(2) - (8)].c)); Free((yyvsp[(7) - (8)].c));
    ;}
    break;

  case 237:
#line 2892 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (6)].c), "CutMesh")){
        int t = (int)(yyvsp[(4) - (6)].d);
        if(gLevelset::find(t)){
          GModel::current()->buildCutGModel(gLevelset::find(t), true, false);
        }
        else
          yymsg(0, "Unknown levelset %d", t);
      }
      else if(!strcmp((yyvsp[(2) - (6)].c), "CutMeshTri")){
        int t = (int)(yyvsp[(4) - (6)].d);
        if(gLevelset::find(t)){
          GModel::current()->buildCutGModel(gLevelset::find(t), true, true);
        }
        else
          yymsg(0, "Unknown levelset %d", t);
      }
      else if(!strcmp((yyvsp[(2) - (6)].c), "SplitMesh")){
        int t = (int)(yyvsp[(4) - (6)].d);
        if(gLevelset::find(t)){
          GModel::current()->buildCutGModel(gLevelset::find(t), false, true);
        }
        else
          yymsg(0, "Unknown levelset %d", t);
      }
      else
        yymsg(0, "Unknown levelset '%s'", (yyvsp[(2) - (6)].c));
      Free((yyvsp[(2) - (6)].c));
    ;}
    break;

  case 238:
#line 2927 "Gmsh.y"
    {
      std::vector<int> tags[4]; ListOfShapes2Vectors((yyvsp[(3) - (4)].l), tags);
      for(int dim = 0; dim < 4; dim++){
        for(unsigned int i = 0; i < tags[dim].size(); i++){
          if(factory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
            GModel::current()->getOCCInternals()->remove(dim, tags[dim][i]);
          }
          GModel::current()->getGEOInternals()->remove(dim, tags[dim][i]);
          GModel::current()->remove(dim, tags[dim][i]);
        }
      }
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 239:
#line 2941 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      GModel::current()->getFields()->deleteField((int)(yyvsp[(4) - (6)].d));
#endif
    ;}
    break;

  case 240:
#line 2947 "Gmsh.y"
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
#line 2962 "Gmsh.y"
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

  case 242:
#line 2990 "Gmsh.y"
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
#line 3007 "Gmsh.y"
    {
      std::vector<int> tags[4]; ListOfShapes2Vectors((yyvsp[(4) - (5)].l), tags);
      setColor(tags, (yyvsp[(2) - (5)].u), false);
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 244:
#line 3013 "Gmsh.y"
    {
      std::vector<int> tags[4]; ListOfShapes2Vectors((yyvsp[(5) - (6)].l), tags);
      setColor(tags, (yyvsp[(3) - (6)].u), true);
      List_Delete((yyvsp[(5) - (6)].l));
    ;}
    break;

  case 245:
#line 3024 "Gmsh.y"
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
#line 3038 "Gmsh.y"
    {
      std::string what = (yyvsp[(2) - (3)].c);
      setVisibility(-1, 1, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 247:
#line 3044 "Gmsh.y"
    {
      std::string what = (yyvsp[(2) - (3)].c);
      setVisibility(-1, 0, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 248:
#line 3050 "Gmsh.y"
    {
      std::vector<int> tags[4]; ListOfShapes2Vectors((yyvsp[(3) - (4)].l), tags);
      setVisibility(tags, 1, false);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 249:
#line 3056 "Gmsh.y"
    {
      std::vector<int> tags[4]; ListOfShapes2Vectors((yyvsp[(4) - (5)].l), tags);
      setVisibility(tags, 1, true);
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 250:
#line 3062 "Gmsh.y"
    {
      std::vector<int> tags[4]; ListOfShapes2Vectors((yyvsp[(3) - (4)].l), tags);
      setVisibility(tags, 0, false);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 251:
#line 3068 "Gmsh.y"
    {
      std::vector<int> tags[4]; ListOfShapes2Vectors((yyvsp[(4) - (5)].l), tags);
      setVisibility(tags, 0, true);
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 252:
#line 3079 "Gmsh.y"
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

  case 253:
#line 3152 "Gmsh.y"
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
#line 3170 "Gmsh.y"
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
#line 3187 "Gmsh.y"
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
#line 3202 "Gmsh.y"
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

  case 257:
#line 3235 "Gmsh.y"
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
#line 3247 "Gmsh.y"
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
#line 3271 "Gmsh.y"
    {
      Msg::Exit(0);
    ;}
    break;

  case 260:
#line 3275 "Gmsh.y"
    {
      gmsh_yyerrorstate = 999; // this will be checked when yyparse returns
      YYABORT;
    ;}
    break;

  case 261:
#line 3280 "Gmsh.y"
    {
      // force sync
      if(GModel::current()->getOCCInternals())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      GModel::current()->getGEOInternals()->synchronize(GModel::current());
    ;}
    break;

  case 262:
#line 3287 "Gmsh.y"
    {
      new GModel();
      GModel::current(GModel::list.size() - 1);
    ;}
    break;

  case 263:
#line 3292 "Gmsh.y"
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

  case 264:
#line 3302 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 1;
      SetBoundingBox((yyvsp[(3) - (15)].d), (yyvsp[(5) - (15)].d), (yyvsp[(7) - (15)].d), (yyvsp[(9) - (15)].d), (yyvsp[(11) - (15)].d), (yyvsp[(13) - (15)].d));
    ;}
    break;

  case 265:
#line 3307 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
      drawContext::global()->draw();
#endif
    ;}
    break;

  case 266:
#line 3313 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
     CTX::instance()->mesh.changed = ENT_ALL;
     for(unsigned int index = 0; index < PView::list.size(); index++)
       PView::list[index]->setChanged(true);
#endif
    ;}
    break;

  case 267:
#line 3321 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh();
    ;}
    break;

  case 268:
#line 3325 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh(1);
    ;}
    break;

  case 269:
#line 3329 "Gmsh.y"
    {
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      if(GModel::current()->getGEOInternals()->getChanged())
        GModel::current()->getGEOInternals()->synchronize(GModel::current());
      GModel::current()->refineMesh(CTX::instance()->mesh.secondOrderLinear);
    ;}
    break;

  case 270:
#line 3339 "Gmsh.y"
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
          gLevelset *l = gLevelset::find((int)d);
          if(l) f.push_back(l);
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

  case 271:
#line 3402 "Gmsh.y"
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
#line 3418 "Gmsh.y"
    {
      LoopControlVariablesTab[ImbricatedLoop][0] = (yyvsp[(3) - (6)].d);
      LoopControlVariablesTab[ImbricatedLoop][1] = (yyvsp[(5) - (6)].d);
      LoopControlVariablesTab[ImbricatedLoop][2] = 1.0;
      LoopControlVariablesNameTab[ImbricatedLoop] = "";
      gmshgetpos(gmsh_yyin, &yyposImbricatedLoopsTab[ImbricatedLoop]);
      yylinenoImbricatedLoopsTab[ImbricatedLoop] = gmsh_yylineno;
      if((yyvsp[(3) - (6)].d) > (yyvsp[(5) - (6)].d))
	skip("For", "EndFor");
      else
	ImbricatedLoop++;
      if(ImbricatedLoop > MAX_RECUR_LOOPS - 1){
	yymsg(0, "Reached maximum number of imbricated loops");
	ImbricatedLoop = MAX_RECUR_LOOPS - 1;
      }
    ;}
    break;

  case 273:
#line 3435 "Gmsh.y"
    {
      LoopControlVariablesTab[ImbricatedLoop][0] = (yyvsp[(3) - (8)].d);
      LoopControlVariablesTab[ImbricatedLoop][1] = (yyvsp[(5) - (8)].d);
      LoopControlVariablesTab[ImbricatedLoop][2] = (yyvsp[(7) - (8)].d);
      LoopControlVariablesNameTab[ImbricatedLoop] = "";
      gmshgetpos(gmsh_yyin, &yyposImbricatedLoopsTab[ImbricatedLoop]);
      yylinenoImbricatedLoopsTab[ImbricatedLoop] = gmsh_yylineno;
      if(((yyvsp[(7) - (8)].d) > 0. && (yyvsp[(3) - (8)].d) > (yyvsp[(5) - (8)].d)) || ((yyvsp[(7) - (8)].d) < 0. && (yyvsp[(3) - (8)].d) < (yyvsp[(5) - (8)].d)))
	skip("For", "EndFor");
      else
	ImbricatedLoop++;
      if(ImbricatedLoop > MAX_RECUR_LOOPS - 1){
	yymsg(0, "Reached maximum number of imbricated loops");
	ImbricatedLoop = MAX_RECUR_LOOPS - 1;
      }
    ;}
    break;

  case 274:
#line 3452 "Gmsh.y"
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
	skip("For", "EndFor");
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
#line 3474 "Gmsh.y"
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
	skip("For", "EndFor");
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
#line 3496 "Gmsh.y"
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
#line 3531 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip(NULL, "Return");
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 278:
#line 3539 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip(NULL, "Return");
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 279:
#line 3547 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    ;}
    break;

  case 280:
#line 3553 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 281:
#line 3560 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 282:
#line 3567 "Gmsh.y"
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
        skipTest("If", "EndIf", "ElseIf", 4, &type_until2);
        if(!type_until2) ImbricatedTest--; // EndIf reached
      }
    ;}
    break;

  case 283:
#line 3587 "Gmsh.y"
    {
      if(ImbricatedTest > 0){
        if (statusImbricatedTests[ImbricatedTest]){
          // Last test (If or ElseIf) was true, thus go after EndIf (out of If EndIf)
          skip("If", "EndIf");
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
            skipTest("If", "EndIf", "ElseIf", 4, &type_until2);
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
#line 3613 "Gmsh.y"
    {
      if(ImbricatedTest > 0){
        if(statusImbricatedTests[ImbricatedTest]){
          skip("If", "EndIf");
          ImbricatedTest--;
        }
      }
      else{
	yymsg(0, "Orphan Else");
      }
    ;}
    break;

  case 285:
#line 3625 "Gmsh.y"
    {
      ImbricatedTest--;
      if(ImbricatedTest < 0)
        yymsg(1, "Orphan EndIf");
    ;}
    break;

  case 286:
#line 3637 "Gmsh.y"
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

  case 287:
#line 3653 "Gmsh.y"
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

  case 288:
#line 3669 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (13)].l),
		    (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].v)[0], (yyvsp[(7) - (13)].v)[1], (yyvsp[(7) - (13)].v)[2], (yyvsp[(9) - (13)].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[(12) - (13)].l));
    ;}
    break;

  case 289:
#line 3677 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 290:
#line 3683 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (7)].l),
		    (yyvsp[(2) - (7)].v)[0], (yyvsp[(2) - (7)].v)[1], (yyvsp[(2) - (7)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(4) - (7)].l));
    ;}
    break;

  case 291:
#line 3691 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 292:
#line 3697 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[(10) - (13)].l),
		    0., 0., 0., (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(10) - (13)].l));
    ;}
    break;

  case 293:
#line 3705 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 294:
#line 3711 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (15)].l),
		    (yyvsp[(3) - (15)].v)[0], (yyvsp[(3) - (15)].v)[1], (yyvsp[(3) - (15)].v)[2], (yyvsp[(5) - (15)].v)[0], (yyvsp[(5) - (15)].v)[1], (yyvsp[(5) - (15)].v)[2], (yyvsp[(7) - (15)].v)[0], (yyvsp[(7) - (15)].v)[1], (yyvsp[(7) - (15)].v)[2], (yyvsp[(9) - (15)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(12) - (15)].l));
    ;}
    break;

  case 295:
#line 3719 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 296:
#line 3725 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(BOUNDARY_LAYER, (yyvsp[(3) - (6)].l), 0., 0., 0., 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(3) - (6)].l));
    ;}
    break;

  case 297:
#line 3732 "Gmsh.y"
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

  case 298:
#line 3745 "Gmsh.y"
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

  case 299:
#line 3759 "Gmsh.y"
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

  case 300:
#line 3773 "Gmsh.y"
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

  case 301:
#line 3792 "Gmsh.y"
    {
    ;}
    break;

  case 302:
#line 3795 "Gmsh.y"
    {
    ;}
    break;

  case 303:
#line 3801 "Gmsh.y"
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

  case 304:
#line 3813 "Gmsh.y"
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

  case 305:
#line 3833 "Gmsh.y"
    {
      extr.mesh.ScaleLast = true;
    ;}
    break;

  case 306:
#line 3837 "Gmsh.y"
    {
      extr.mesh.Recombine = true;
    ;}
    break;

  case 307:
#line 3841 "Gmsh.y"
    {
      extr.mesh.Recombine = (yyvsp[(2) - (3)].d) ? true : false;
    ;}
    break;

  case 308:
#line 3845 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1;
    ;}
    break;

  case 309:
#line 3849 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1_RECOMB;
    ;}
    break;

  case 310:
#line 3853 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1;
    ;}
    break;

  case 311:
#line 3857 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1_RECOMB;
    ;}
    break;

  case 312:
#line 3861 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(6) - (9)].l), tags);
      int num = (int)(yyvsp[(3) - (9)].d);
      GModel::current()->getGEOInternals()->addDiscreteSurface(num);
      extr.mesh.Holes[num].first = (yyvsp[(8) - (9)].d);
      extr.mesh.Holes[num].second = tags;
      List_Delete((yyvsp[(6) - (9)].l));
    ;}
    break;

  case 313:
#line 3870 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (6)].c), "Index"))
        extr.mesh.BoundaryLayerIndex = (yyvsp[(4) - (6)].d);
      else if(!strcmp((yyvsp[(2) - (6)].c), "View"))
        extr.mesh.ViewIndex = (yyvsp[(4) - (6)].d);
      Free((yyvsp[(2) - (6)].c));
    ;}
    break;

  case 314:
#line 3882 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Union; ;}
    break;

  case 315:
#line 3883 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Intersection; ;}
    break;

  case 316:
#line 3884 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Difference; ;}
    break;

  case 317:
#line 3885 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Section; ;}
    break;

  case 318:
#line 3886 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Fragments; ;}
    break;

  case 319:
#line 3890 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 320:
#line 3891 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 321:
#line 3892 "Gmsh.y"
    { (yyval.i) = (yyvsp[(2) - (3)].d); ;}
    break;

  case 322:
#line 3897 "Gmsh.y"
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

  case 323:
#line 3914 "Gmsh.y"
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

  case 324:
#line 3932 "Gmsh.y"
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

  case 325:
#line 3947 "Gmsh.y"
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    ;}
    break;

  case 326:
#line 3951 "Gmsh.y"
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

  case 327:
#line 3966 "Gmsh.y"
    {
      (yyval.i) = -1; // left
    ;}
    break;

  case 328:
#line 3970 "Gmsh.y"
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

  case 329:
#line 3986 "Gmsh.y"
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   ;}
    break;

  case 330:
#line 3990 "Gmsh.y"
    {
     (yyval.l) = (yyvsp[(2) - (2)].l);
   ;}
    break;

  case 331:
#line 3995 "Gmsh.y"
    {
      (yyval.i) = 45;
    ;}
    break;

  case 332:
#line 3999 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(2) - (2)].d);
    ;}
    break;

  case 333:
#line 4005 "Gmsh.y"
    {
      (yyval.l) = List_Create(1, 1, sizeof(double));
    ;}
    break;

  case 334:
#line 4009 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
    ;}
    break;

  case 335:
#line 4016 "Gmsh.y"
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

  case 336:
#line 4033 "Gmsh.y"
    {
      // transfinite constraints are stored in GEO internals in addition to
      // GModel, as they can be copied around during GEO operations
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

  case 337:
#line 4074 "Gmsh.y"
    {
      // transfinite constraints are stored in GEO internals in addition to
      // GModel, as they can be copied around during GEO operations
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

  case 338:
#line 4118 "Gmsh.y"
    {
      // transfinite constraints are stored in GEO internals in addition to
      // GModel, as they can be copied around during GEO operations
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

  case 339:
#line 4157 "Gmsh.y"
    {
      // transfinite constraints are stored in GEO internals in addition to
      // GModel, as they can be copied around during GEO operations
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

  case 340:
#line 4182 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (8)].l)); i++){
	double d;
	List_Read((yyvsp[(4) - (8)].l), i, &d);
	CTX::instance()->mesh.algo2d_per_face[(int)d] = (int)(yyvsp[(7) - (8)].d);
      }
      List_Delete((yyvsp[(4) - (8)].l));
    ;}
    break;

  case 341:
#line 4191 "Gmsh.y"
    {
      // recombine constraints are stored in GEO internals in addition to
      // GModel, as they can be copied around during GEO operations
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

  case 342:
#line 4221 "Gmsh.y"
    {
      // recombine constraints are stored in GEO internals in addition to
      // GModel, as they can be copied around during GEO operations
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

  case 343:
#line 4247 "Gmsh.y"
    {
      // smoothing constraints are stored in GEO internals in addition to
      // GModel, as they can be copied around during GEO operations
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

  case 344:
#line 4274 "Gmsh.y"
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

  case 345:
#line 4306 "Gmsh.y"
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

  case 346:
#line 4333 "Gmsh.y"
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

  case 347:
#line 4359 "Gmsh.y"
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

  case 348:
#line 4385 "Gmsh.y"
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

  case 349:
#line 4411 "Gmsh.y"
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

  case 350:
#line 4437 "Gmsh.y"
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

  case 351:
#line 4458 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (10)].l), tags);
      addEmbedded(0, tags, 2, (int)(yyvsp[(8) - (10)].d));
      List_Delete((yyvsp[(3) - (10)].l));
    ;}
    break;

  case 352:
#line 4464 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (10)].l), tags);
      addEmbedded(1, tags, 2, (int)(yyvsp[(8) - (10)].d));
      List_Delete((yyvsp[(3) - (10)].l));
    ;}
    break;

  case 353:
#line 4470 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (10)].l), tags);
      addEmbedded(0, tags, 3, (int)(yyvsp[(8) - (10)].d));
      List_Delete((yyvsp[(3) - (10)].l));
    ;}
    break;

  case 354:
#line 4476 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (10)].l), tags);
      addEmbedded(1, tags, 3, (int)(yyvsp[(8) - (10)].d));
      List_Delete((yyvsp[(3) - (10)].l));
    ;}
    break;

  case 355:
#line 4482 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (10)].l), tags);
      addEmbedded(2, tags, 3, (int)(yyvsp[(8) - (10)].d));
      List_Delete((yyvsp[(3) - (10)].l));
    ;}
    break;

  case 356:
#line 4488 "Gmsh.y"
    {
      // reverse mesh constraints are stored in GEO internals in addition to
      // GModel, as they can be copied around during GEO operations
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

  case 357:
#line 4514 "Gmsh.y"
    {
      // reverse mesh constraints are stored in GEO internals in addition to
      // GModel, as they can be copied around during GEO operations
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

  case 358:
#line 4540 "Gmsh.y"
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

  case 359:
#line 4557 "Gmsh.y"
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

  case 360:
#line 4574 "Gmsh.y"
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

  case 361:
#line 4591 "Gmsh.y"
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

  case 362:
#line 4603 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (4)].l), tags);
      GModel::current()->getGEOInternals()->setCompoundMesh(1, tags);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 363:
#line 4609 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (4)].l), tags);
      GModel::current()->getGEOInternals()->setCompoundMesh(2, tags);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 364:
#line 4615 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (4)].l), tags);
      GModel::current()->getGEOInternals()->setCompoundMesh(3, tags);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 365:
#line 4627 "Gmsh.y"
    {
      GModel::current()->getGEOInternals()->removeAllDuplicates();
    ;}
    break;

  case 366:
#line 4631 "Gmsh.y"
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

  case 367:
#line 4641 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(4) - (6)].l), tags);
      GModel::current()->getGEOInternals()->mergeVertices(tags);
      List_Delete((yyvsp[(4) - (6)].l));
    ;}
    break;

  case 368:
#line 4651 "Gmsh.y"
    { (yyval.c) = (char*)"Homology"; ;}
    break;

  case 369:
#line 4652 "Gmsh.y"
    { (yyval.c) = (char*)"Cohomology"; ;}
    break;

  case 370:
#line 4653 "Gmsh.y"
    { (yyval.c) = (char*)"Betti"; ;}
    break;

  case 371:
#line 4658 "Gmsh.y"
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest((yyvsp[(1) - (2)].c), domain, subdomain, dim);
    ;}
    break;

  case 372:
#line 4664 "Gmsh.y"
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

  case 373:
#line 4676 "Gmsh.y"
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

  case 374:
#line 4694 "Gmsh.y"
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

  case 375:
#line 4721 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d);           ;}
    break;

  case 376:
#line 4722 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (3)].d);           ;}
    break;

  case 377:
#line 4723 "Gmsh.y"
    { (yyval.d) = -(yyvsp[(2) - (2)].d);          ;}
    break;

  case 378:
#line 4724 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);           ;}
    break;

  case 379:
#line 4725 "Gmsh.y"
    { (yyval.d) = !(yyvsp[(2) - (2)].d);          ;}
    break;

  case 380:
#line 4726 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) - (yyvsp[(3) - (3)].d);      ;}
    break;

  case 381:
#line 4727 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) + (yyvsp[(3) - (3)].d);      ;}
    break;

  case 382:
#line 4728 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) * (yyvsp[(3) - (3)].d);      ;}
    break;

  case 383:
#line 4730 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (3)].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));
      else
	(yyval.d) = (yyvsp[(1) - (3)].d) / (yyvsp[(3) - (3)].d);
    ;}
    break;

  case 384:
#line 4736 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) % (int)(yyvsp[(3) - (3)].d);  ;}
    break;

  case 385:
#line 4737 "Gmsh.y"
    { (yyval.d) = pow((yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));  ;}
    break;

  case 386:
#line 4738 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d);      ;}
    break;

  case 387:
#line 4739 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) > (yyvsp[(3) - (3)].d);      ;}
    break;

  case 388:
#line 4740 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) <= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 389:
#line 4741 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) >= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 390:
#line 4742 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) == (yyvsp[(3) - (3)].d);     ;}
    break;

  case 391:
#line 4743 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) != (yyvsp[(3) - (3)].d);     ;}
    break;

  case 392:
#line 4744 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) && (yyvsp[(3) - (3)].d);     ;}
    break;

  case 393:
#line 4745 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) || (yyvsp[(3) - (3)].d);     ;}
    break;

  case 394:
#line 4746 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (5)].d) ? (yyvsp[(3) - (5)].d) : (yyvsp[(5) - (5)].d); ;}
    break;

  case 395:
#line 4747 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 396:
#line 4748 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 397:
#line 4749 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 398:
#line 4750 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 399:
#line 4751 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 400:
#line 4752 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 401:
#line 4753 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 402:
#line 4754 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 403:
#line 4755 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 404:
#line 4756 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 405:
#line 4757 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 406:
#line 4758 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 407:
#line 4759 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 408:
#line 4760 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 409:
#line 4761 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 410:
#line 4762 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 411:
#line 4763 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 412:
#line 4764 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d) + 0.5); ;}
    break;

  case 413:
#line 4765 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 414:
#line 4766 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 415:
#line 4767 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 416:
#line 4768 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 417:
#line 4777 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 418:
#line 4778 "Gmsh.y"
    { (yyval.d) = 3.141592653589793; ;}
    break;

  case 419:
#line 4779 "Gmsh.y"
    { (yyval.d) = (double)ImbricatedTest; ;}
    break;

  case 420:
#line 4780 "Gmsh.y"
    { (yyval.d) = Msg::GetCommRank(); ;}
    break;

  case 421:
#line 4781 "Gmsh.y"
    { (yyval.d) = Msg::GetCommSize(); ;}
    break;

  case 422:
#line 4782 "Gmsh.y"
    { (yyval.d) = GetGmshMajorVersion(); ;}
    break;

  case 423:
#line 4783 "Gmsh.y"
    { (yyval.d) = GetGmshMinorVersion(); ;}
    break;

  case 424:
#line 4784 "Gmsh.y"
    { (yyval.d) = GetGmshPatchVersion(); ;}
    break;

  case 425:
#line 4785 "Gmsh.y"
    { (yyval.d) = Cpu(); ;}
    break;

  case 426:
#line 4786 "Gmsh.y"
    { (yyval.d) = GetMemoryUsage()/1024./1024.; ;}
    break;

  case 427:
#line 4787 "Gmsh.y"
    { (yyval.d) = TotalRam(); ;}
    break;

  case 428:
#line 4792 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 429:
#line 4794 "Gmsh.y"
    {
      std::vector<double> val(1, (yyvsp[(3) - (6)].d));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.d) = val[0];
    ;}
    break;

  case 430:
#line 4800 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 431:
#line 4802 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 432:
#line 4807 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 433:
#line 4812 "Gmsh.y"
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

  case 434:
#line 4835 "Gmsh.y"
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

  case 435:
#line 4853 "Gmsh.y"
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

  case 436:
#line 4871 "Gmsh.y"
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

  case 437:
#line 4889 "Gmsh.y"
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

  case 438:
#line 4907 "Gmsh.y"
    {
      (yyval.d) = gmsh_yysymbols.count((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 439:
#line 4912 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.d) = !StatFile(tmp);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 440:
#line 4918 "Gmsh.y"
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

  case 441:
#line 4933 "Gmsh.y"
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

  case 442:
#line 4952 "Gmsh.y"
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

  case 443:
#line 4972 "Gmsh.y"
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

  case 444:
#line 4992 "Gmsh.y"
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

  case 445:
#line 5012 "Gmsh.y"
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

  case 446:
#line 5042 "Gmsh.y"
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

  case 447:
#line 5060 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), (yyval.d));
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 448:
#line 5065 "Gmsh.y"
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

  case 449:
#line 5075 "Gmsh.y"
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

  case 450:
#line 5085 "Gmsh.y"
    {
      (yyval.d) = Msg::GetValue((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 451:
#line 5090 "Gmsh.y"
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

  case 452:
#line 5101 "Gmsh.y"
    {
      std::string s((yyvsp[(3) - (6)].c)), substr((yyvsp[(5) - (6)].c));
      if(s.find(substr) != std::string::npos)
        (yyval.d) = 1.;
      else
        (yyval.d) = 0.;
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 453:
#line 5110 "Gmsh.y"
    {
      (yyval.d) = strlen((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 454:
#line 5115 "Gmsh.y"
    {
      (yyval.d) = strcmp((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 455:
#line 5120 "Gmsh.y"
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

  case 456:
#line 5148 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 457:
#line 5151 "Gmsh.y"
    {
      std::string key(Struct_Name);
      StructTable_M[key] = Struct((int)(yyvsp[(6) - (8)].d), 1, floatOptions, charOptions);
      (yyval.d) = (yyvsp[(6) - (8)].d);
      Free(Struct_Name);
    ;}
    break;

  case 458:
#line 5161 "Gmsh.y"
    { Struct_NameSpace = NULL; Struct_Name = (yyvsp[(1) - (1)].c); ;}
    break;

  case 459:
#line 5163 "Gmsh.y"
    { Struct_NameSpace = (yyvsp[(1) - (4)].c); Struct_Name = (yyvsp[(4) - (4)].c); ;}
    break;

  case 460:
#line 5168 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); flag_tSTRING_alloc = 1; ;}
    break;

  case 462:
#line 5179 "Gmsh.y"
    {
      std::string key((yyvsp[(2) - (3)].c)), val(Struct_Name);
      gmsh_yystringsymbols[key] = std::vector<std::string>(1, val);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 463:
#line 5188 "Gmsh.y"
    {
      memcpy((yyval.v), (yyvsp[(1) - (1)].v), 5*sizeof(double));
    ;}
    break;

  case 464:
#line 5192 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 465:
#line 5196 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 466:
#line 5200 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] - (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 467:
#line 5204 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] + (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 468:
#line 5211 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (11)].d);  (yyval.v)[1] = (yyvsp[(4) - (11)].d);  (yyval.v)[2] = (yyvsp[(6) - (11)].d);  (yyval.v)[3] = (yyvsp[(8) - (11)].d); (yyval.v)[4] = (yyvsp[(10) - (11)].d);
    ;}
    break;

  case 469:
#line 5215 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (9)].d);  (yyval.v)[1] = (yyvsp[(4) - (9)].d);  (yyval.v)[2] = (yyvsp[(6) - (9)].d);  (yyval.v)[3] = (yyvsp[(8) - (9)].d); (yyval.v)[4] = 1.0;
    ;}
    break;

  case 470:
#line 5219 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 471:
#line 5223 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 472:
#line 5230 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].l)));
    ;}
    break;

  case 473:
#line 5235 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].l)));
    ;}
    break;

  case 474:
#line 5242 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 475:
#line 5247 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 476:
#line 5251 "Gmsh.y"
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    ;}
    break;

  case 477:
#line 5256 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 478:
#line 5260 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 479:
#line 5268 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (5)].d);
      }
    ;}
    break;

  case 480:
#line 5279 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 481:
#line 5283 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(1) - (1)].c), "*") || !strcmp((yyvsp[(1) - (1)].c), "all"))
        (yyval.l) = 0;
      else{
        yyerror("Unknown special string for list replacement");
        (yyval.l) = List_Create(2, 1, sizeof(double));
      }
    ;}
    break;

  case 482:
#line 5295 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 483:
#line 5303 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (3)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (3)].d);
      }
    ;}
    break;

  case 484:
#line 5311 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      for(double d = (yyvsp[(1) - (3)].d); ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d <= (yyvsp[(3) - (3)].d)) : (d >= (yyvsp[(3) - (3)].d));
          ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d += 1.) : (d -= 1.))
	List_Add((yyval.l), &d);
    ;}
    break;

  case 485:
#line 5318 "Gmsh.y"
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

  case 486:
#line 5328 "Gmsh.y"
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

  case 487:
#line 5351 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags(0, (yyval.l));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 488:
#line 5357 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags(1, (yyval.l));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 489:
#line 5363 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags(2, (yyval.l));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 490:
#line 5369 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags(3, (yyval.l));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 491:
#line 5375 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      if(!(yyvsp[(3) - (3)].l)){
        getAllPhysicalTags(0, (yyval.l));
      }
      else{
        getElementaryTagsForPhysicalGroups(0, (yyvsp[(3) - (3)].l), (yyval.l));
        List_Delete((yyvsp[(3) - (3)].l));
      }
    ;}
    break;

  case 492:
#line 5386 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      if(!(yyvsp[(3) - (3)].l)){
        getAllPhysicalTags(1, (yyval.l));
      }
      else{
        getElementaryTagsForPhysicalGroups(1, (yyvsp[(3) - (3)].l), (yyval.l));
        List_Delete((yyvsp[(3) - (3)].l));
      }
    ;}
    break;

  case 493:
#line 5397 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      if(!(yyvsp[(3) - (3)].l)){
        getAllPhysicalTags(2, (yyval.l));
      }
      else{
        getElementaryTagsForPhysicalGroups(2, (yyvsp[(3) - (3)].l), (yyval.l));
        List_Delete((yyvsp[(3) - (3)].l));
      }
    ;}
    break;

  case 494:
#line 5408 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      if(!(yyvsp[(3) - (3)].l)){
        getAllPhysicalTags(3, (yyval.l));
      }
      else{
        getElementaryTagsForPhysicalGroups(3, (yyvsp[(3) - (3)].l), (yyval.l));
        List_Delete((yyvsp[(3) - (3)].l));
      }
    ;}
    break;

  case 495:
#line 5420 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getElementaryTagsInBoundingBox(0, (yyvsp[(5) - (16)].d), (yyvsp[(7) - (16)].d), (yyvsp[(9) - (16)].d), (yyvsp[(11) - (16)].d), (yyvsp[(13) - (16)].d), (yyvsp[(15) - (16)].d), (yyval.l));
    ;}
    break;

  case 496:
#line 5426 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getElementaryTagsInBoundingBox(1, (yyvsp[(5) - (16)].d), (yyvsp[(7) - (16)].d), (yyvsp[(9) - (16)].d), (yyvsp[(11) - (16)].d), (yyvsp[(13) - (16)].d), (yyvsp[(15) - (16)].d), (yyval.l));
    ;}
    break;

  case 497:
#line 5432 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getElementaryTagsInBoundingBox(2, (yyvsp[(5) - (16)].d), (yyvsp[(7) - (16)].d), (yyvsp[(9) - (16)].d), (yyvsp[(11) - (16)].d), (yyvsp[(13) - (16)].d), (yyvsp[(15) - (16)].d), (yyval.l));
    ;}
    break;

  case 498:
#line 5438 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getElementaryTagsInBoundingBox(3, (yyvsp[(5) - (16)].d), (yyvsp[(7) - (16)].d), (yyvsp[(9) - (16)].d), (yyvsp[(11) - (16)].d), (yyvsp[(13) - (16)].d), (yyvsp[(15) - (16)].d), (yyval.l));
    ;}
    break;

  case 499:
#line 5443 "Gmsh.y"
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

  case 500:
#line 5453 "Gmsh.y"
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

  case 501:
#line 5463 "Gmsh.y"
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

  case 502:
#line 5473 "Gmsh.y"
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

  case 503:
#line 5485 "Gmsh.y"
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

  case 504:
#line 5498 "Gmsh.y"
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

  case 505:
#line 5510 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 506:
#line 5514 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 507:
#line 5518 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (6)].l);
    ;}
    break;

  case 508:
#line 5522 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (6)].l);
    ;}
    break;

  case 509:
#line 5526 "Gmsh.y"
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

  case 510:
#line 5544 "Gmsh.y"
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

  case 511:
#line 5562 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = (yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1);
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 512:
#line 5570 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = pow(10,(yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1));
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 513:
#line 5578 "Gmsh.y"
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

  case 514:
#line 5607 "Gmsh.y"
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

  case 515:
#line 5617 "Gmsh.y"
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

  case 516:
#line 5636 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 517:
#line 5641 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 518:
#line 5645 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].d)));
    ;}
    break;

  case 519:
#line 5649 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (3)].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 520:
#line 5661 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (9)].d), (int)(yyvsp[(4) - (9)].d), (int)(yyvsp[(6) - (9)].d), (int)(yyvsp[(8) - (9)].d));
    ;}
    break;

  case 521:
#line 5665 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (7)].d), (int)(yyvsp[(4) - (7)].d), (int)(yyvsp[(6) - (7)].d), 255);
    ;}
    break;

  case 522:
#line 5677 "Gmsh.y"
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

  case 523:
#line 5694 "Gmsh.y"
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(5) - (5)].c), val);
      (yyval.u) = val;
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(5) - (5)].c));
    ;}
    break;

  case 524:
#line 5704 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 525:
#line 5708 "Gmsh.y"
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

  case 526:
#line 5723 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].u)));
    ;}
    break;

  case 527:
#line 5728 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].u)));
    ;}
    break;

  case 528:
#line 5735 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 529:
#line 5739 "Gmsh.y"
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

  case 530:
#line 5752 "Gmsh.y"
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

  case 531:
#line 5766 "Gmsh.y"
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

  case 532:
#line 5780 "Gmsh.y"
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

  case 533:
#line 5794 "Gmsh.y"
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

  case 534:
#line 5808 "Gmsh.y"
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

  case 535:
#line 5829 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 536:
#line 5837 "Gmsh.y"
    {
      std::string name = GModel::current()->getPhysicalName(0, (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 537:
#line 5843 "Gmsh.y"
    {
      std::string name = GModel::current()->getPhysicalName(1, (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 538:
#line 5849 "Gmsh.y"
    {
      std::string name = GModel::current()->getPhysicalName(2, (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 539:
#line 5855 "Gmsh.y"
    {
      std::string name = GModel::current()->getPhysicalName(3, (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 540:
#line 5864 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 541:
#line 5868 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 542:
#line 5872 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    ;}
    break;

  case 543:
#line 5880 "Gmsh.y"
    {
      std::string exe = Msg::GetExecutableName();
      (yyval.c) = (char *)Malloc(exe.size() + 1);
      strcpy((yyval.c), exe.c_str());
    ;}
    break;

  case 544:
#line 5886 "Gmsh.y"
    {
      std::string action = Msg::GetOnelabAction();
      (yyval.c) = (char *)Malloc(action.size() + 1);
      strcpy((yyval.c), action.c_str());
    ;}
    break;

  case 545:
#line 5892 "Gmsh.y"
    {
      const char *env = GetEnvironmentVar((yyvsp[(3) - (4)].c));
      if(!env) env = "";
      (yyval.c) = (char *)Malloc((sizeof(env) + 1) * sizeof(char));
      strcpy((yyval.c), env);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 546:
#line 5900 "Gmsh.y"
    {
      std::string s = Msg::GetString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 547:
#line 5908 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (4)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 548:
#line 5915 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 549:
#line 5923 "Gmsh.y"
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

  case 550:
#line 5938 "Gmsh.y"
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

  case 551:
#line 5952 "Gmsh.y"
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

  case 552:
#line 5966 "Gmsh.y"
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

  case 553:
#line 5978 "Gmsh.y"
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

  case 554:
#line 5994 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = toupper((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 555:
#line 6003 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = tolower((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 556:
#line 6012 "Gmsh.y"
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

  case 557:
#line 6022 "Gmsh.y"
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

  case 558:
#line 6033 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (8)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (8)].d), (int)(yyvsp[(7) - (8)].d));
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (8)].c));
    ;}
    break;

  case 559:
#line 6041 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (6)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (6)].d), std::string::npos);
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 560:
#line 6049 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 561:
#line 6053 "Gmsh.y"
    {
      char tmpstring[5000];
      int i = printListOfDouble((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].l), tmpstring);
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

  case 562:
#line 6072 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 563:
#line 6079 "Gmsh.y"
    {
      std::string tmp = SplitFileName(GetAbsolutePath(gmsh_yyname))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
    ;}
    break;

  case 564:
#line 6085 "Gmsh.y"
    {
      std::string tmp = SplitFileName((yyvsp[(3) - (4)].c))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 565:
#line 6092 "Gmsh.y"
    {
      std::string tmp = GetAbsolutePath((yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 566:
#line 6099 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 567:
#line 6101 "Gmsh.y"
    {
      std::string val((yyvsp[(3) - (6)].c));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.c) = (char*)Malloc((val.size() + 1) * sizeof(char));
      strcpy((yyval.c), val.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 568:
#line 6109 "Gmsh.y"
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

  case 569:
#line 6123 "Gmsh.y"
    { Struct_NameSpace = NULL; (yyval.d) = (yyvsp[(2) - (2)].d); ;}
    break;

  case 570:
#line 6125 "Gmsh.y"
    { Struct_NameSpace = (yyvsp[(1) - (5)].c); (yyval.d) = (yyvsp[(5) - (5)].d); ;}
    break;

  case 571:
#line 6130 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].c)));
    ;}
    break;

  case 572:
#line 6135 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].c)));
    ;}
    break;

  case 573:
#line 6143 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 574:
#line 6152 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char)) ;
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)) ; strcat((yyval.c), tmpstr) ;
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 575:
#line 6165 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 576:
#line 6168 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 577:
#line 6172 "Gmsh.y"
    { (yyval.c) = (yyvsp[(3) - (4)].c); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 13434 "Gmsh.tab.cpp"
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


#line 6175 "Gmsh.y"


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

int printListOfDouble(char *format, List_T *list, char *buffer)
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
      (dim == 3) ? MSH_VOLUME :
      (dim == 2) ? MSH_SURF_PLAN :
      (dim == 1) ? MSH_SEGM_LINE :
      MSH_POINT;
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
  else if(level == 1){
    Msg::Warning("'%s', line %d : %s", gmsh_yyname.c_str(), gmsh_yylineno - 1, tmp);
  }
  else{
    Msg::Info("'%s', line %d : %s", gmsh_yyname.c_str(), gmsh_yylineno - 1, tmp);
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

void getAllElementaryTags(int dim, List_T *out)
{
  if(GModel::current()->getOCCInternals() &&
     GModel::current()->getOCCInternals()->getChanged())
    GModel::current()->getOCCInternals()->synchronize(GModel::current());
  if(GModel::current()->getGEOInternals()->getChanged())
    GModel::current()->getGEOInternals()->synchronize(GModel::current());

  std::vector<GEntity*> entities;
  GModel::current()->getEntities(entities, dim);
  for(unsigned int i = 0; i < entities.size(); i++){
    double tag = entities[i]->tag();
    List_Add(out, &tag);
  }
}

void getAllPhysicalTags(int dim, List_T *out)
{
  if(GModel::current()->getGEOInternals()->getChanged())
    GModel::current()->getGEOInternals()->synchronize(GModel::current());

  std::map<int, std::vector<GEntity*> > groups;
  GModel::current()->getPhysicalGroups(dim, groups);
  for(std::map<int, std::vector<GEntity*> >::iterator it = groups.begin();
      it != groups.end(); it++){
    double d = it->first;
    List_Add(out, &d);
  }
}

void getElementaryTagsForPhysicalGroups(int dim, List_T *in, List_T *out)
{
  if(GModel::current()->getGEOInternals()->getChanged())
    GModel::current()->getGEOInternals()->synchronize(GModel::current());

  std::map<int, std::vector<GEntity*> > groups;
  GModel::current()->getPhysicalGroups(dim, groups);
  for(int i = 0; i < List_Nbr(in); i++){
    double num;
    List_Read(in, i, &num);
    std::map<int, std::vector<GEntity*> >::iterator it = groups.find(num);
    if(it != groups.end()){
      for(unsigned j = 0; j < it->second.size(); j++){
        double d = it->second[j]->tag();
        List_Add(out, &d);
      }
    }
  }
}

void getElementaryTagsInBoundingBox(int dim, double x1, double y1, double z1,
                                    double x2, double y2, double z2, List_T *out)
{
  if(GModel::current()->getOCCInternals() &&
     GModel::current()->getOCCInternals()->getChanged())
    GModel::current()->getOCCInternals()->synchronize(GModel::current());
  if(GModel::current()->getGEOInternals()->getChanged())
    GModel::current()->getGEOInternals()->synchronize(GModel::current());

  SBoundingBox3d box(x1, y1, z1, x2, y2, z2);
  std::vector<GEntity*> entities;
  GModel::current()->getEntitiesInBox(entities, box, dim);
  for(unsigned int i = 0; i < entities.size(); i++){
    double d = entities[i]->tag();
    List_Add(out, &d);
  }
}

void setVisibility(int dim, int visible, bool recursive)
{
  if(GModel::current()->getOCCInternals() &&
     GModel::current()->getOCCInternals()->getChanged())
    GModel::current()->getOCCInternals()->synchronize(GModel::current());
  if(GModel::current()->getGEOInternals()->getChanged())
    GModel::current()->getGEOInternals()->synchronize(GModel::current());

  std::vector<GEntity*> entities;
  GModel::current()->getEntities(entities, dim);
  for(unsigned int i = 0; i < entities.size(); i++){
    entities[i]->setVisibility(visible);
  }
}

void setVisibility(std::vector<int> tags[4], int visible, bool recursive)
{
  if(GModel::current()->getOCCInternals() &&
     GModel::current()->getOCCInternals()->getChanged())
    GModel::current()->getOCCInternals()->synchronize(GModel::current());
  if(GModel::current()->getGEOInternals()->getChanged())
    GModel::current()->getGEOInternals()->synchronize(GModel::current());

  for(int dim = 0; dim < 4; dim++){
    for(unsigned int i = 0; i < tags[dim].size(); i++){
      GEntity *ge = GModel::current()->getEntityByTag(dim, std::abs(tags[dim][i]));
      if(ge) ge->setVisibility(visible, recursive);
    }
  }
}

void setColor(std::vector<int> tags[4], unsigned int val, bool recursive)
{
  if(GModel::current()->getOCCInternals() &&
     GModel::current()->getOCCInternals()->getChanged())
    GModel::current()->getOCCInternals()->synchronize(GModel::current());
  if(GModel::current()->getGEOInternals()->getChanged())
    GModel::current()->getGEOInternals()->synchronize(GModel::current());

  for(int dim = 0; dim < 4; dim++){
    for(unsigned int i = 0; i < tags[dim].size(); i++){
      GEntity *ge = GModel::current()->getEntityByTag(dim, std::abs(tags[dim][i]));
      if(ge) ge->setColor(val, recursive);
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
    tag = GModel::current()->getGEOInternals()->getMaxTag(3) + 1;
  if(GModel::current()->getOCCInternals())
    tag = std::max(tag, GModel::current()->getOCCInternals()->getMaxTag(3) + 1);
  return tag;
}

int NEWREG()
{
  int tag = 0;
  for(int dim = -2; dim <= 3; dim++){
    if(dim)
      tag = std::max(tag, GModel::current()->getGEOInternals()->getMaxTag(dim) + 1);
  }
  tag = std::max(tag, GModel::current()->getGEOInternals()->MaxPhysicalNum + 1);
  if(GModel::current()->getOCCInternals()){
    for(int dim = -2; dim <= 3; dim++){
      if(dim)
        tag = std::max(tag, GModel::current()->getOCCInternals()->getMaxTag(dim) + 1);
    }
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

