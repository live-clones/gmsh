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
     tSCOPE = 264,
     tPi = 265,
     tMPI_Rank = 266,
     tMPI_Size = 267,
     tEuclidian = 268,
     tCoordinates = 269,
     tTestLevel = 270,
     tExp = 271,
     tLog = 272,
     tLog10 = 273,
     tSqrt = 274,
     tSin = 275,
     tAsin = 276,
     tCos = 277,
     tAcos = 278,
     tTan = 279,
     tRand = 280,
     tAtan = 281,
     tAtan2 = 282,
     tSinh = 283,
     tCosh = 284,
     tTanh = 285,
     tFabs = 286,
     tAbs = 287,
     tFloor = 288,
     tCeil = 289,
     tRound = 290,
     tMin = 291,
     tMax = 292,
     tFmod = 293,
     tModulo = 294,
     tHypot = 295,
     tList = 296,
     tLinSpace = 297,
     tLogSpace = 298,
     tListFromFile = 299,
     tCatenary = 300,
     tPrintf = 301,
     tError = 302,
     tWarning = 303,
     tStr = 304,
     tSprintf = 305,
     tStrCat = 306,
     tStrPrefix = 307,
     tStrRelative = 308,
     tStrReplace = 309,
     tAbsolutePath = 310,
     tDirName = 311,
     tStrSub = 312,
     tStrLen = 313,
     tFind = 314,
     tStrFind = 315,
     tStrCmp = 316,
     tStrChoice = 317,
     tUpperCase = 318,
     tLowerCase = 319,
     tLowerCaseIn = 320,
     tTextAttributes = 321,
     tBoundingBox = 322,
     tDraw = 323,
     tSetChanged = 324,
     tToday = 325,
     tFixRelativePath = 326,
     tCurrentDirectory = 327,
     tCurrentFileName = 328,
     tSyncModel = 329,
     tNewModel = 330,
     tMass = 331,
     tCenterOfMass = 332,
     tOnelabAction = 333,
     tOnelabRun = 334,
     tCodeName = 335,
     tCpu = 336,
     tMemory = 337,
     tTotalMemory = 338,
     tCreateTopology = 339,
     tCreateGeometry = 340,
     tClassifySurfaces = 341,
     tRenumberMeshNodes = 342,
     tRenumberMeshElements = 343,
     tDistanceFunction = 344,
     tDefineConstant = 345,
     tUndefineConstant = 346,
     tDefineNumber = 347,
     tDefineStruct = 348,
     tNameStruct = 349,
     tDimNameSpace = 350,
     tAppend = 351,
     tDefineString = 352,
     tSetNumber = 353,
     tSetTag = 354,
     tSetString = 355,
     tPoint = 356,
     tCircle = 357,
     tEllipse = 358,
     tCurve = 359,
     tSphere = 360,
     tPolarSphere = 361,
     tSurface = 362,
     tSpline = 363,
     tVolume = 364,
     tBox = 365,
     tCylinder = 366,
     tCone = 367,
     tTorus = 368,
     tEllipsoid = 369,
     tQuadric = 370,
     tShapeFromFile = 371,
     tRectangle = 372,
     tDisk = 373,
     tWire = 374,
     tGeoEntity = 375,
     tCharacteristic = 376,
     tLength = 377,
     tParametric = 378,
     tElliptic = 379,
     tRefineMesh = 380,
     tRecombineMesh = 381,
     tAdaptMesh = 382,
     tRelocateMesh = 383,
     tReorientMesh = 384,
     tSetFactory = 385,
     tThruSections = 386,
     tWedge = 387,
     tFillet = 388,
     tChamfer = 389,
     tPlane = 390,
     tRuled = 391,
     tTransfinite = 392,
     tPhysical = 393,
     tCompound = 394,
     tPeriodic = 395,
     tParent = 396,
     tUsing = 397,
     tPlugin = 398,
     tDegenerated = 399,
     tRecursive = 400,
     tSewing = 401,
     tRotate = 402,
     tTranslate = 403,
     tSymmetry = 404,
     tDilate = 405,
     tExtrude = 406,
     tLevelset = 407,
     tAffine = 408,
     tBooleanUnion = 409,
     tBooleanIntersection = 410,
     tBooleanDifference = 411,
     tBooleanSection = 412,
     tBooleanFragments = 413,
     tThickSolid = 414,
     tRecombine = 415,
     tSmoother = 416,
     tSplit = 417,
     tDelete = 418,
     tCoherence = 419,
     tIntersect = 420,
     tMeshAlgorithm = 421,
     tReverseMesh = 422,
     tMeshSizeFromBoundary = 423,
     tOnlyInitialMesh = 424,
     tLayers = 425,
     tScaleLast = 426,
     tHole = 427,
     tAlias = 428,
     tAliasWithOptions = 429,
     tCopyOptions = 430,
     tQuadTriAddVerts = 431,
     tQuadTriNoNewVerts = 432,
     tRecombLaterals = 433,
     tTransfQuadTri = 434,
     tText2D = 435,
     tText3D = 436,
     tInterpolationScheme = 437,
     tTime = 438,
     tCombine = 439,
     tBSpline = 440,
     tBezier = 441,
     tNurbs = 442,
     tNurbsOrder = 443,
     tNurbsKnots = 444,
     tColor = 445,
     tColorTable = 446,
     tFor = 447,
     tIn = 448,
     tEndFor = 449,
     tIf = 450,
     tElseIf = 451,
     tElse = 452,
     tEndIf = 453,
     tExit = 454,
     tAbort = 455,
     tField = 456,
     tReturn = 457,
     tCall = 458,
     tSlide = 459,
     tMacro = 460,
     tShow = 461,
     tHide = 462,
     tGetValue = 463,
     tGetStringValue = 464,
     tGetEnv = 465,
     tGetString = 466,
     tGetNumber = 467,
     tUnique = 468,
     tHomology = 469,
     tCohomology = 470,
     tBetti = 471,
     tExists = 472,
     tFileExists = 473,
     tGetForced = 474,
     tGetForcedStr = 475,
     tGMSH_MAJOR_VERSION = 476,
     tGMSH_MINOR_VERSION = 477,
     tGMSH_PATCH_VERSION = 478,
     tGmshExecutableName = 479,
     tSetPartition = 480,
     tNameToString = 481,
     tStringToName = 482,
     tAFFECTDIVIDE = 483,
     tAFFECTTIMES = 484,
     tAFFECTMINUS = 485,
     tAFFECTPLUS = 486,
     tOR = 487,
     tAND = 488,
     tNOTEQUAL = 489,
     tEQUAL = 490,
     tGREATERGREATER = 491,
     tLESSLESS = 492,
     tGREATEROREQUAL = 493,
     tLESSOREQUAL = 494,
     UNARYPREC = 495,
     tMINUSMINUS = 496,
     tPLUSPLUS = 497
   };
#endif
/* Tokens.  */
#define tDOUBLE 258
#define tSTRING 259
#define tBIGSTR 260
#define tEND 261
#define tAFFECT 262
#define tDOTS 263
#define tSCOPE 264
#define tPi 265
#define tMPI_Rank 266
#define tMPI_Size 267
#define tEuclidian 268
#define tCoordinates 269
#define tTestLevel 270
#define tExp 271
#define tLog 272
#define tLog10 273
#define tSqrt 274
#define tSin 275
#define tAsin 276
#define tCos 277
#define tAcos 278
#define tTan 279
#define tRand 280
#define tAtan 281
#define tAtan2 282
#define tSinh 283
#define tCosh 284
#define tTanh 285
#define tFabs 286
#define tAbs 287
#define tFloor 288
#define tCeil 289
#define tRound 290
#define tMin 291
#define tMax 292
#define tFmod 293
#define tModulo 294
#define tHypot 295
#define tList 296
#define tLinSpace 297
#define tLogSpace 298
#define tListFromFile 299
#define tCatenary 300
#define tPrintf 301
#define tError 302
#define tWarning 303
#define tStr 304
#define tSprintf 305
#define tStrCat 306
#define tStrPrefix 307
#define tStrRelative 308
#define tStrReplace 309
#define tAbsolutePath 310
#define tDirName 311
#define tStrSub 312
#define tStrLen 313
#define tFind 314
#define tStrFind 315
#define tStrCmp 316
#define tStrChoice 317
#define tUpperCase 318
#define tLowerCase 319
#define tLowerCaseIn 320
#define tTextAttributes 321
#define tBoundingBox 322
#define tDraw 323
#define tSetChanged 324
#define tToday 325
#define tFixRelativePath 326
#define tCurrentDirectory 327
#define tCurrentFileName 328
#define tSyncModel 329
#define tNewModel 330
#define tMass 331
#define tCenterOfMass 332
#define tOnelabAction 333
#define tOnelabRun 334
#define tCodeName 335
#define tCpu 336
#define tMemory 337
#define tTotalMemory 338
#define tCreateTopology 339
#define tCreateGeometry 340
#define tClassifySurfaces 341
#define tRenumberMeshNodes 342
#define tRenumberMeshElements 343
#define tDistanceFunction 344
#define tDefineConstant 345
#define tUndefineConstant 346
#define tDefineNumber 347
#define tDefineStruct 348
#define tNameStruct 349
#define tDimNameSpace 350
#define tAppend 351
#define tDefineString 352
#define tSetNumber 353
#define tSetTag 354
#define tSetString 355
#define tPoint 356
#define tCircle 357
#define tEllipse 358
#define tCurve 359
#define tSphere 360
#define tPolarSphere 361
#define tSurface 362
#define tSpline 363
#define tVolume 364
#define tBox 365
#define tCylinder 366
#define tCone 367
#define tTorus 368
#define tEllipsoid 369
#define tQuadric 370
#define tShapeFromFile 371
#define tRectangle 372
#define tDisk 373
#define tWire 374
#define tGeoEntity 375
#define tCharacteristic 376
#define tLength 377
#define tParametric 378
#define tElliptic 379
#define tRefineMesh 380
#define tRecombineMesh 381
#define tAdaptMesh 382
#define tRelocateMesh 383
#define tReorientMesh 384
#define tSetFactory 385
#define tThruSections 386
#define tWedge 387
#define tFillet 388
#define tChamfer 389
#define tPlane 390
#define tRuled 391
#define tTransfinite 392
#define tPhysical 393
#define tCompound 394
#define tPeriodic 395
#define tParent 396
#define tUsing 397
#define tPlugin 398
#define tDegenerated 399
#define tRecursive 400
#define tSewing 401
#define tRotate 402
#define tTranslate 403
#define tSymmetry 404
#define tDilate 405
#define tExtrude 406
#define tLevelset 407
#define tAffine 408
#define tBooleanUnion 409
#define tBooleanIntersection 410
#define tBooleanDifference 411
#define tBooleanSection 412
#define tBooleanFragments 413
#define tThickSolid 414
#define tRecombine 415
#define tSmoother 416
#define tSplit 417
#define tDelete 418
#define tCoherence 419
#define tIntersect 420
#define tMeshAlgorithm 421
#define tReverseMesh 422
#define tMeshSizeFromBoundary 423
#define tOnlyInitialMesh 424
#define tLayers 425
#define tScaleLast 426
#define tHole 427
#define tAlias 428
#define tAliasWithOptions 429
#define tCopyOptions 430
#define tQuadTriAddVerts 431
#define tQuadTriNoNewVerts 432
#define tRecombLaterals 433
#define tTransfQuadTri 434
#define tText2D 435
#define tText3D 436
#define tInterpolationScheme 437
#define tTime 438
#define tCombine 439
#define tBSpline 440
#define tBezier 441
#define tNurbs 442
#define tNurbsOrder 443
#define tNurbsKnots 444
#define tColor 445
#define tColorTable 446
#define tFor 447
#define tIn 448
#define tEndFor 449
#define tIf 450
#define tElseIf 451
#define tElse 452
#define tEndIf 453
#define tExit 454
#define tAbort 455
#define tField 456
#define tReturn 457
#define tCall 458
#define tSlide 459
#define tMacro 460
#define tShow 461
#define tHide 462
#define tGetValue 463
#define tGetStringValue 464
#define tGetEnv 465
#define tGetString 466
#define tGetNumber 467
#define tUnique 468
#define tHomology 469
#define tCohomology 470
#define tBetti 471
#define tExists 472
#define tFileExists 473
#define tGetForced 474
#define tGetForcedStr 475
#define tGMSH_MAJOR_VERSION 476
#define tGMSH_MINOR_VERSION 477
#define tGMSH_PATCH_VERSION 478
#define tGmshExecutableName 479
#define tSetPartition 480
#define tNameToString 481
#define tStringToName 482
#define tAFFECTDIVIDE 483
#define tAFFECTTIMES 484
#define tAFFECTMINUS 485
#define tAFFECTPLUS 486
#define tOR 487
#define tAND 488
#define tNOTEQUAL 489
#define tEQUAL 490
#define tGREATERGREATER 491
#define tLESSLESS 492
#define tGREATEROREQUAL 493
#define tLESSOREQUAL 494
#define UNARYPREC 495
#define tMINUSMINUS 496
#define tPLUSPLUS 497




/* Copy the first part of user declarations.  */
#line 1 "Gmsh.y"

// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

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

// global parser variables
std::string gmsh_yyname;
int gmsh_yyerrorstate = 0;
int gmsh_yyviewindex = 0;
std::map<std::string, gmsh_yysymbol> gmsh_yysymbols;
std::map<std::string, std::vector<std::string> > gmsh_yystringsymbols;
std::string gmsh_yyfactory;
NameSpaces gmsh_yynamespaces;

// static parser variables (accessible only in this file)
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
static fpos_t yyposImbricatedLoopsTab[MAX_RECUR_LOOPS];
static int yylinenoImbricatedLoopsTab[MAX_RECUR_LOOPS];
static double LoopControlVariablesTab[MAX_RECUR_LOOPS][3];
static std::string LoopControlVariablesNameTab[MAX_RECUR_LOOPS];
static std::string struct_name, struct_namespace;
static int dim_entity;

static std::map<std::string, std::vector<double> > floatOptions;
static std::map<std::string, std::vector<std::string> > charOptions;
static int flag_Enum, member_ValMax;

void init_options(int member_ValMax_ = 0)
{
  floatOptions.clear(); charOptions.clear();
  flag_Enum = 0; member_ValMax = member_ValMax_;
}

// parser functions defined at the end of this file
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
void ListOfShapes2VectorOfPairs(List_T *list, std::vector<std::pair<int, int> > &v);
void VectorOfPairs2ListOfShapes(const std::vector<std::pair<int, int> > &v, List_T *list);
void addPeriodicEdge(int, int, const std::vector<double>&);
void addPeriodicFace(int, int, const std::map<int, int>&);
void addPeriodicFace(int, int, const std::vector<double>&);
void computeAffineTransformation(SPoint3&, SPoint3&, double, SPoint3&,
                                 std::vector<double>&);
void addEmbedded(int dim, std::vector<int> tags, int dim2, int tag2);
void removeEmbedded(const std::vector<std::pair<int, int> > &dimTags, int dim);
void getAllElementaryTags(int dim, List_T *in);
void getAllPhysicalTags(int dim, List_T *in);
void getElementaryTagsForPhysicalGroups(int dim, List_T *in, List_T *out);
void getElementaryTagsInBoundingBox(int dim, double x1, double y1, double z1,
                                    double x2, double y2, double z2, List_T *out);
void getParentTags(int dim, List_T *in, List_T *out);
void getBoundingBox(int dim, List_T *in, List_T *out);
void setVisibility(int dim, int visible, bool recursive);
void setVisibility(const std::vector<std::pair<int, int> > &dimTags, int visible,
                   bool recursive);
void setColor(const std::vector<std::pair<int, int> > &dimTags, unsigned int val,
              bool recursive);

double treat_Struct_FullName_Float
  (char* c1, char* c2, int type_var = 1, int index = 0,
   double val_default = 0., int type_treat = 0);
double treat_Struct_FullName_dot_tSTRING_Float
  (char* c1, char* c2, char* c3, int index = 0,
   double val_default = 0., int type_treat = 0);
List_T * treat_Struct_FullName_dot_tSTRING_ListOfFloat
  (char* c1, char* c2, char* c3);
int treat_Struct_FullName_dot_tSTRING_Float_getDim
  (char* c1, char* c2, char* c3);
char* treat_Struct_FullName_String
  (char* c1, char* c2, int type_var = 1, int index = 0,
   char* val_default = NULL, int type_treat = 0);
char* treat_Struct_FullName_dot_tSTRING_String
  (char* c1, char* c2, char* c3, int index = 0,
   char* val_default = NULL, int type_treat = 0);
List_T * treat_Struct_FullName_dot_tSTRING_ListOfString
  (char* c1, char* c2, char* c3);

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
#line 165 "Gmsh.y"
{
  char *c;
  int i;
  unsigned int u;
  double d;
  double v[5];
  Shape s;
  List_T *l;
  struct TwoChar c2;
}
/* Line 193 of yacc.c.  */
#line 763 "Gmsh.tab.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 776 "Gmsh.tab.cpp"

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
#define YYLAST   17042

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  265
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  114
/* YYNRULES -- Number of rules.  */
#define YYNRULES  632
/* YYNRULES -- Number of states.  */
#define YYNSTATES  2257

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   497

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint16 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   250,     2,   262,     2,   247,   249,     2,
     255,   256,   245,   243,   264,   244,   261,   246,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     237,     2,   238,   232,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   257,     2,   258,   254,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   259,   248,   260,   263,     2,     2,     2,
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
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   233,   234,   235,
     236,   239,   240,   241,   242,   251,   252,   253
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,     9,    12,    14,    16,    18,
      24,    26,    28,    30,    32,    34,    36,    38,    40,    42,
      44,    46,    48,    50,    52,    54,    56,    58,    60,    66,
      72,    78,    86,    94,   102,   110,   120,   127,   134,   141,
     150,   151,   154,   157,   160,   163,   166,   169,   171,   175,
     177,   181,   182,   183,   194,   196,   200,   201,   215,   217,
     221,   222,   238,   247,   262,   263,   270,   272,   274,   276,
     278,   280,   282,   284,   286,   288,   290,   292,   294,   296,
     298,   300,   302,   308,   314,   317,   325,   333,   338,   342,
     349,   359,   367,   374,   382,   389,   394,   403,   413,   423,
     430,   440,   447,   457,   463,   472,   481,   493,   500,   510,
     516,   524,   534,   544,   556,   564,   574,   584,   585,   587,
     588,   592,   598,   599,   609,   610,   622,   628,   629,   639,
     640,   644,   648,   654,   660,   661,   664,   665,   667,   669,
     673,   676,   679,   682,   684,   689,   692,   695,   696,   699,
     701,   705,   708,   711,   714,   717,   720,   722,   724,   728,
     729,   735,   741,   747,   748,   751,   752,   755,   763,   771,
     779,   790,   801,   810,   819,   827,   835,   847,   855,   864,
     873,   882,   892,   896,   901,   912,   920,   928,   936,   944,
     952,   960,   968,   976,   984,   992,  1002,  1010,  1018,  1027,
    1036,  1049,  1050,  1060,  1062,  1064,  1066,  1068,  1073,  1075,
    1077,  1079,  1084,  1086,  1088,  1093,  1095,  1097,  1099,  1104,
    1110,  1122,  1128,  1138,  1148,  1156,  1161,  1171,  1181,  1183,
    1185,  1186,  1189,  1196,  1204,  1212,  1219,  1227,  1236,  1247,
    1262,  1279,  1292,  1307,  1322,  1337,  1352,  1361,  1370,  1377,
    1382,  1388,  1394,  1401,  1408,  1412,  1417,  1421,  1427,  1434,
    1440,  1445,  1449,  1454,  1458,  1463,  1469,  1474,  1480,  1484,
    1490,  1498,  1506,  1510,  1518,  1522,  1525,  1528,  1531,  1534,
    1537,  1553,  1556,  1559,  1562,  1572,  1584,  1587,  1590,  1593,
    1596,  1599,  1616,  1628,  1635,  1644,  1653,  1664,  1666,  1669,
    1672,  1674,  1678,  1682,  1687,  1692,  1694,  1696,  1702,  1714,
    1728,  1729,  1737,  1738,  1752,  1753,  1769,  1770,  1777,  1787,
    1790,  1794,  1805,  1819,  1821,  1824,  1830,  1838,  1841,  1844,
    1848,  1851,  1855,  1858,  1862,  1872,  1879,  1881,  1883,  1885,
    1887,  1889,  1890,  1893,  1897,  1901,  1906,  1916,  1921,  1936,
    1937,  1941,  1942,  1944,  1945,  1948,  1949,  1952,  1953,  1956,
    1963,  1971,  1978,  1984,  1988,  1997,  2006,  2015,  2024,  2033,
    2042,  2051,  2057,  2062,  2069,  2081,  2093,  2112,  2131,  2144,
    2157,  2170,  2181,  2186,  2191,  2196,  2201,  2206,  2209,  2213,
    2220,  2222,  2224,  2226,  2229,  2235,  2243,  2254,  2256,  2260,
    2263,  2266,  2269,  2273,  2277,  2281,  2285,  2289,  2293,  2297,
    2301,  2305,  2309,  2313,  2317,  2321,  2325,  2329,  2333,  2337,
    2341,  2347,  2352,  2357,  2362,  2367,  2372,  2377,  2382,  2387,
    2392,  2397,  2404,  2409,  2414,  2419,  2424,  2429,  2434,  2439,
    2444,  2451,  2458,  2465,  2470,  2477,  2484,  2486,  2488,  2490,
    2492,  2494,  2496,  2498,  2500,  2502,  2504,  2506,  2507,  2514,
    2516,  2521,  2528,  2530,  2535,  2540,  2545,  2552,  2558,  2566,
    2575,  2586,  2591,  2596,  2603,  2608,  2612,  2615,  2621,  2627,
    2631,  2637,  2644,  2653,  2660,  2669,  2676,  2681,  2689,  2696,
    2703,  2710,  2715,  2722,  2727,  2728,  2731,  2732,  2735,  2736,
    2744,  2746,  2750,  2752,  2755,  2756,  2760,  2762,  2765,  2768,
    2772,  2776,  2788,  2798,  2806,  2814,  2816,  2820,  2822,  2824,
    2827,  2831,  2836,  2842,  2844,  2848,  2850,  2853,  2857,  2861,
    2867,  2872,  2877,  2880,  2885,  2888,  2892,  2896,  2901,  2907,
    2913,  2919,  2921,  2923,  2925,  2929,  2935,  2943,  2948,  2953,
    2958,  2965,  2972,  2981,  2990,  2995,  3010,  3015,  3020,  3022,
    3024,  3028,  3032,  3042,  3050,  3052,  3058,  3062,  3069,  3071,
    3075,  3077,  3079,  3084,  3089,  3093,  3099,  3106,  3115,  3122,
    3127,  3133,  3135,  3140,  3142,  3144,  3146,  3148,  3153,  3160,
    3165,  3172,  3178,  3186,  3191,  3196,  3201,  3210,  3215,  3220,
    3225,  3230,  3239,  3248,  3255,  3260,  3267,  3272,  3274,  3276,
    3281,  3286,  3287,  3294,  3299,  3302,  3307,  3312,  3314,  3316,
    3320,  3322,  3324,  3328,  3332,  3336,  3342,  3350,  3356,  3362,
    3371,  3373,  3375
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     266,     0,    -1,   267,    -1,     1,     6,    -1,    -1,   267,
     268,    -1,   270,    -1,   271,    -1,   292,    -1,   130,   255,
     368,   256,     6,    -1,   311,    -1,   317,    -1,   321,    -1,
     322,    -1,   323,    -1,   324,    -1,   328,    -1,   337,    -1,
     338,    -1,   344,    -1,   345,    -1,   327,    -1,   326,    -1,
     325,    -1,   320,    -1,   347,    -1,   238,    -1,   239,    -1,
      46,   255,   368,   256,     6,    -1,    48,   255,   368,   256,
       6,    -1,    47,   255,   368,   256,     6,    -1,    46,   255,
     368,   256,   269,   368,     6,    -1,    46,   255,   368,   264,
     364,   256,     6,    -1,    48,   255,   368,   264,   364,   256,
       6,    -1,    47,   255,   368,   264,   364,   256,     6,    -1,
      46,   255,   368,   264,   364,   256,   269,   368,     6,    -1,
     378,   368,   259,   272,   260,     6,    -1,   173,     4,   257,
     348,   258,     6,    -1,   174,     4,   257,   348,   258,     6,
      -1,   175,     4,   257,   348,   264,   348,   258,     6,    -1,
      -1,   272,   275,    -1,   272,   279,    -1,   272,   282,    -1,
     272,   284,    -1,   272,   285,    -1,   272,   327,    -1,   348,
      -1,   273,   264,   348,    -1,   348,    -1,   274,   264,   348,
      -1,    -1,    -1,     4,   276,   255,   273,   256,   277,   259,
     274,   260,     6,    -1,   368,    -1,   278,   264,   368,    -1,
      -1,   180,   255,   348,   264,   348,   264,   348,   256,   280,
     259,   278,   260,     6,    -1,   368,    -1,   281,   264,   368,
      -1,    -1,   181,   255,   348,   264,   348,   264,   348,   264,
     348,   256,   283,   259,   281,   260,     6,    -1,   182,   259,
     360,   260,   259,   360,   260,     6,    -1,   182,   259,   360,
     260,   259,   360,   260,   259,   360,   260,   259,   360,   260,
       6,    -1,    -1,   183,   286,   259,   274,   260,     6,    -1,
       7,    -1,   231,    -1,   230,    -1,   229,    -1,   228,    -1,
     253,    -1,   252,    -1,   255,    -1,   257,    -1,   256,    -1,
     258,    -1,     4,    -1,    36,    -1,    37,    -1,   110,    -1,
     111,    -1,    90,   257,   294,   258,     6,    -1,    91,   257,
     298,   258,     6,    -1,   353,     6,    -1,    98,   289,   369,
     264,   348,   290,     6,    -1,   100,   289,   378,   264,   369,
     290,     6,    -1,   378,   287,   361,     6,    -1,   378,   288,
       6,    -1,   378,   289,   290,   287,   361,     6,    -1,   378,
     289,   259,   364,   260,   290,   287,   361,     6,    -1,   378,
     257,   348,   258,   287,   348,     6,    -1,   378,   257,   348,
     258,   288,     6,    -1,   378,   255,   348,   256,   287,   348,
       6,    -1,   378,   255,   348,   256,   288,     6,    -1,   378,
       7,   369,     6,    -1,   378,   289,   290,     7,    49,   289,
     290,     6,    -1,   378,   289,   290,     7,    49,   289,   373,
     290,     6,    -1,   378,   289,   290,   231,    49,   289,   373,
     290,     6,    -1,   378,   261,   291,     7,   369,     6,    -1,
     378,   257,   348,   258,   261,   291,     7,   369,     6,    -1,
     378,   261,   291,   287,   348,     6,    -1,   378,   257,   348,
     258,   261,   291,   287,   348,     6,    -1,   378,   261,   291,
     288,     6,    -1,   378,   257,   348,   258,   261,   291,   288,
       6,    -1,   378,   261,   190,   261,   291,     7,   365,     6,
      -1,   378,   257,   348,   258,   261,   190,   261,   291,     7,
     365,     6,    -1,   378,   261,   191,     7,   366,     6,    -1,
     378,   257,   348,   258,   261,   191,     7,   366,     6,    -1,
     378,   201,     7,   361,     6,    -1,   201,   257,   348,   258,
       7,   291,     6,    -1,   201,   257,   348,   258,   261,   291,
       7,   348,     6,    -1,   201,   257,   348,   258,   261,   291,
       7,   369,     6,    -1,   201,   257,   348,   258,   261,   291,
       7,   259,   364,   260,     6,    -1,   201,   257,   348,   258,
     261,   291,     6,    -1,   143,   255,     4,   256,   261,   291,
       7,   348,     6,    -1,   143,   255,     4,   256,   261,   291,
       7,   369,     6,    -1,    -1,   264,    -1,    -1,   294,   293,
     378,    -1,   294,   293,   378,     7,   348,    -1,    -1,   294,
     293,   378,     7,   259,   361,   295,   300,   260,    -1,    -1,
     294,   293,   378,   289,   290,     7,   259,   361,   296,   300,
     260,    -1,   294,   293,   378,     7,   369,    -1,    -1,   294,
     293,   378,     7,   259,   369,   297,   304,   260,    -1,    -1,
     298,   293,   368,    -1,   348,     7,   369,    -1,   299,   264,
     348,     7,   369,    -1,   363,     7,   378,   255,   256,    -1,
      -1,   264,   302,    -1,    -1,   302,    -1,   303,    -1,   302,
     264,   303,    -1,     4,   361,    -1,    36,   348,    -1,    37,
     348,    -1,     4,    -1,     4,   259,   299,   260,    -1,     4,
     369,    -1,     4,   372,    -1,    -1,   264,   305,    -1,   306,
      -1,   305,   264,   306,    -1,     4,   348,    -1,     4,   369,
      -1,   205,   369,    -1,     4,   374,    -1,     4,   372,    -1,
     348,    -1,   369,    -1,   369,   264,   348,    -1,    -1,   193,
     105,   259,   348,   260,    -1,   142,   101,   259,   364,   260,
      -1,   142,   120,   259,   364,   260,    -1,    -1,   135,   358,
      -1,    -1,   142,   146,    -1,   101,   255,   348,   256,     7,
     358,     6,    -1,   104,   255,   348,   256,     7,   361,     6,
      -1,   108,   255,   348,   256,     7,   361,     6,    -1,   139,
     108,   255,   348,   256,     7,   361,   142,   348,     6,    -1,
     139,   185,   255,   348,   256,     7,   361,   142,   348,     6,
      -1,   102,   255,   348,   256,     7,   361,   309,     6,    -1,
     103,   255,   348,   256,     7,   361,   309,     6,    -1,   185,
     255,   348,   256,     7,   361,     6,    -1,   186,   255,   348,
     256,     7,   361,     6,    -1,   187,   255,   348,   256,     7,
     361,   189,   361,   188,   348,     6,    -1,   119,   255,   348,
     256,     7,   361,     6,    -1,   104,     4,   255,   348,   256,
       7,   361,     6,    -1,   135,   107,   255,   348,   256,     7,
     361,     6,    -1,   107,   255,   348,   256,     7,   361,   308,
       6,    -1,   136,   107,   255,   348,   256,     7,   361,   308,
       6,    -1,    13,    14,     6,    -1,    14,   107,   348,     6,
      -1,   123,   107,   255,   348,   256,     7,     5,     5,     5,
       6,    -1,   105,   255,   348,   256,     7,   361,     6,    -1,
     106,   255,   348,   256,     7,   361,     6,    -1,   110,   255,
     348,   256,     7,   361,     6,    -1,   113,   255,   348,   256,
       7,   361,     6,    -1,   117,   255,   348,   256,     7,   361,
       6,    -1,   118,   255,   348,   256,     7,   361,     6,    -1,
     111,   255,   348,   256,     7,   361,     6,    -1,   112,   255,
     348,   256,     7,   361,     6,    -1,   132,   255,   348,   256,
       7,   361,     6,    -1,   159,   255,   348,   256,     7,   361,
       6,    -1,   107,     4,   255,   348,   256,     7,   361,   310,
       6,    -1,   109,   255,   348,   256,     7,   361,     6,    -1,
     131,   255,   348,   256,     7,   361,     6,    -1,   136,   131,
     255,   348,   256,     7,   361,     6,    -1,   139,   314,   255,
     348,   256,     7,   361,     6,    -1,   139,   314,   255,   348,
     256,     7,   361,     4,   259,   360,   260,     6,    -1,    -1,
     138,   313,   312,   255,   307,   256,   287,   361,     6,    -1,
     101,    -1,   104,    -1,   107,    -1,   109,    -1,   120,   259,
     348,   260,    -1,   104,    -1,   107,    -1,   109,    -1,   120,
     259,   348,   260,    -1,   104,    -1,   107,    -1,   120,   259,
     348,   260,    -1,   101,    -1,   104,    -1,   107,    -1,   120,
     259,   348,   260,    -1,   148,   358,   259,   318,   260,    -1,
     147,   259,   358,   264,   358,   264,   348,   260,   259,   318,
     260,    -1,   149,   358,   259,   318,   260,    -1,   150,   259,
     358,   264,   348,   260,   259,   318,   260,    -1,   150,   259,
     358,   264,   358,   260,   259,   318,   260,    -1,   153,   259,
     364,   260,   259,   318,   260,    -1,     4,   259,   318,   260,
      -1,   165,   104,   259,   364,   260,   107,   259,   348,   260,
      -1,   162,   104,   255,   348,   256,   259,   364,   260,     6,
      -1,   319,    -1,   317,    -1,    -1,   319,   311,    -1,   319,
     313,   259,   364,   260,     6,    -1,   319,   138,   313,   259,
     364,   260,     6,    -1,   319,   141,   313,   259,   364,   260,
       6,    -1,   319,   313,   259,     8,   260,     6,    -1,   319,
     138,   313,   259,     8,   260,     6,    -1,   152,   135,   255,
     348,   256,     7,   361,     6,    -1,   152,   101,   255,   348,
     256,     7,   259,   360,   260,     6,    -1,   152,   135,   255,
     348,   256,     7,   259,   358,   264,   358,   264,   364,   260,
       6,    -1,   152,   135,   255,   348,   256,     7,   259,   358,
     264,   358,   264,   358,   264,   364,   260,     6,    -1,   152,
     105,   255,   348,   256,     7,   259,   358,   264,   364,   260,
       6,    -1,   152,   111,   255,   348,   256,     7,   259,   358,
     264,   358,   264,   364,   260,     6,    -1,   152,   112,   255,
     348,   256,     7,   259,   358,   264,   358,   264,   364,   260,
       6,    -1,   152,   114,   255,   348,   256,     7,   259,   358,
     264,   358,   264,   364,   260,     6,    -1,   152,   115,   255,
     348,   256,     7,   259,   358,   264,   358,   264,   364,   260,
       6,    -1,   152,     4,   255,   348,   256,     7,   361,     6,
      -1,   152,     4,   255,   348,   256,     7,     5,     6,    -1,
     152,     4,   259,   348,   260,     6,    -1,   163,   259,   319,
     260,    -1,   145,   163,   259,   319,   260,    -1,   163,     4,
     259,   319,   260,    -1,   163,   201,   257,   348,   258,     6,
      -1,   163,     4,   257,   348,   258,     6,    -1,   163,   378,
       6,    -1,   163,     4,     4,     6,    -1,   163,    93,     6,
      -1,   190,   365,   259,   319,   260,    -1,   145,   190,   365,
     259,   319,   260,    -1,   225,   348,   259,   319,   260,    -1,
     206,   259,     8,   260,    -1,   206,     5,     6,    -1,   207,
     259,     8,   260,    -1,   207,     5,     6,    -1,   206,   259,
     319,   260,    -1,   145,   206,   259,   319,   260,    -1,   207,
     259,   319,   260,    -1,   145,   207,   259,   319,   260,    -1,
     378,   369,     6,    -1,    79,   255,   375,   256,     6,    -1,
     378,   378,   257,   348,   258,   368,     6,    -1,   378,   378,
     378,   257,   348,   258,     6,    -1,   378,   348,     6,    -1,
     143,   255,     4,   256,   261,     4,     6,    -1,   184,     4,
       6,    -1,   199,     6,    -1,   200,     6,    -1,    74,     6,
      -1,    75,     6,    -1,    67,     6,    -1,    67,   259,   348,
     264,   348,   264,   348,   264,   348,   264,   348,   264,   348,
     260,     6,    -1,    68,     6,    -1,    69,     6,    -1,    84,
       6,    -1,    86,   259,   348,   264,   348,   264,   348,   260,
       6,    -1,    86,   259,   348,   264,   348,   264,   348,   264,
     348,   260,     6,    -1,    85,     6,    -1,    87,     6,    -1,
      88,     6,    -1,   125,     6,    -1,   126,     6,    -1,   127,
     259,   364,   260,   259,   364,   260,   259,   360,   260,   259,
     348,   264,   348,   260,     6,    -1,   204,   255,   259,   364,
     260,   264,   369,   264,   369,   256,     6,    -1,   192,   255,
     348,     8,   348,   256,    -1,   192,   255,   348,     8,   348,
       8,   348,   256,    -1,   192,     4,   193,   259,   348,     8,
     348,   260,    -1,   192,     4,   193,   259,   348,     8,   348,
       8,   348,   260,    -1,   194,    -1,   205,     4,    -1,   205,
     369,    -1,   202,    -1,   203,   378,     6,    -1,   203,   369,
       6,    -1,   195,   255,   348,   256,    -1,   196,   255,   348,
     256,    -1,   197,    -1,   198,    -1,   151,   358,   259,   319,
     260,    -1,   151,   259,   358,   264,   358,   264,   348,   260,
     259,   319,   260,    -1,   151,   259,   358,   264,   358,   264,
     358,   264,   348,   260,   259,   319,   260,    -1,    -1,   151,
     358,   259,   319,   329,   333,   260,    -1,    -1,   151,   259,
     358,   264,   358,   264,   348,   260,   259,   319,   330,   333,
     260,    -1,    -1,   151,   259,   358,   264,   358,   264,   358,
     264,   348,   260,   259,   319,   331,   333,   260,    -1,    -1,
     151,   259,   319,   332,   333,   260,    -1,   151,   259,   319,
     260,   142,   119,   259,   348,   260,    -1,   131,   361,    -1,
     136,   131,   361,    -1,   133,   259,   364,   260,   259,   364,
     260,   259,   364,   260,    -1,   134,   259,   364,   260,   259,
     364,   260,   259,   364,   260,   259,   364,   260,    -1,   334,
      -1,   333,   334,    -1,   170,   259,   348,   260,     6,    -1,
     170,   259,   361,   264,   361,   260,     6,    -1,   171,     6,
      -1,   160,     6,    -1,   160,   348,     6,    -1,   176,     6,
      -1,   176,   178,     6,    -1,   177,     6,    -1,   177,   178,
       6,    -1,   172,   255,   348,   256,     7,   361,   142,   348,
       6,    -1,   142,     4,   257,   348,   258,     6,    -1,   154,
      -1,   155,    -1,   156,    -1,   157,    -1,   158,    -1,    -1,
     163,     6,    -1,   145,   163,     6,    -1,   163,   348,     6,
      -1,   145,   163,   348,     6,    -1,   335,   259,   319,   336,
     260,   259,   319,   336,   260,    -1,   116,   255,   368,   256,
      -1,   335,   255,   348,   256,     7,   259,   319,   336,   260,
     259,   319,   336,   260,     6,    -1,    -1,   142,     4,   348,
      -1,    -1,     4,    -1,    -1,     7,   361,    -1,    -1,     7,
     348,    -1,    -1,   153,   361,    -1,   121,   122,   362,     7,
     348,     6,    -1,   137,   104,   362,     7,   348,   339,     6,
      -1,   137,   107,   362,   341,   340,     6,    -1,   137,   109,
     362,   341,     6,    -1,   179,   362,     6,    -1,    99,   101,
     255,   348,   264,   348,   256,     6,    -1,    99,   104,   255,
     348,   264,   348,   256,     6,    -1,    99,   107,   255,   348,
     264,   348,   256,     6,    -1,    99,   109,   255,   348,   264,
     348,   256,     6,    -1,   166,   107,   259,   364,   260,     7,
     348,     6,    -1,   168,   107,   259,   364,   260,     7,   348,
       6,    -1,   169,   107,   259,   364,   260,     7,   348,     6,
      -1,   160,   107,   362,   342,     6,    -1,   160,   109,   362,
       6,    -1,   161,   107,   362,     7,   348,     6,    -1,   140,
     104,   259,   364,   260,     7,   259,   364,   260,   343,     6,
      -1,   140,   107,   259,   364,   260,     7,   259,   364,   260,
     343,     6,    -1,   140,   104,   259,   364,   260,     7,   259,
     364,   260,   147,   259,   358,   264,   358,   264,   348,   260,
       6,    -1,   140,   107,   259,   364,   260,     7,   259,   364,
     260,   147,   259,   358,   264,   358,   264,   348,   260,     6,
      -1,   140,   104,   259,   364,   260,     7,   259,   364,   260,
     148,   358,     6,    -1,   140,   107,   259,   364,   260,     7,
     259,   364,   260,   148,   358,     6,    -1,   140,   107,   348,
     259,   364,   260,     7,   348,   259,   364,   260,     6,    -1,
     313,   259,   364,   260,   193,   313,   259,   348,   260,     6,
      -1,   167,   315,   362,     6,    -1,   128,   316,   362,     6,
      -1,   129,   109,   361,     6,    -1,   144,   104,   361,     6,
      -1,   139,   314,   361,     6,    -1,   164,     6,    -1,   164,
       4,     6,    -1,   164,   101,   259,   364,   260,     6,    -1,
     214,    -1,   215,    -1,   216,    -1,   346,     6,    -1,   346,
     259,   361,   260,     6,    -1,   346,   259,   361,   264,   361,
     260,     6,    -1,   346,   255,   361,   256,   259,   361,   264,
     361,   260,     6,    -1,   349,    -1,   255,   348,   256,    -1,
     244,   348,    -1,   243,   348,    -1,   250,   348,    -1,   348,
     244,   348,    -1,   348,   243,   348,    -1,   348,   245,   348,
      -1,   348,   246,   348,    -1,   348,   248,   348,    -1,   348,
     249,   348,    -1,   348,   247,   348,    -1,   348,   254,   348,
      -1,   348,   237,   348,    -1,   348,   238,   348,    -1,   348,
     242,   348,    -1,   348,   241,   348,    -1,   348,   236,   348,
      -1,   348,   235,   348,    -1,   348,   234,   348,    -1,   348,
     233,   348,    -1,   348,   239,   348,    -1,   348,   240,   348,
      -1,   348,   232,   348,     8,   348,    -1,    16,   289,   348,
     290,    -1,    17,   289,   348,   290,    -1,    18,   289,   348,
     290,    -1,    19,   289,   348,   290,    -1,    20,   289,   348,
     290,    -1,    21,   289,   348,   290,    -1,    22,   289,   348,
     290,    -1,    23,   289,   348,   290,    -1,    24,   289,   348,
     290,    -1,    26,   289,   348,   290,    -1,    27,   289,   348,
     264,   348,   290,    -1,    28,   289,   348,   290,    -1,    29,
     289,   348,   290,    -1,    30,   289,   348,   290,    -1,    31,
     289,   348,   290,    -1,    32,   289,   348,   290,    -1,    33,
     289,   348,   290,    -1,    34,   289,   348,   290,    -1,    35,
     289,   348,   290,    -1,    38,   289,   348,   264,   348,   290,
      -1,    39,   289,   348,   264,   348,   290,    -1,    40,   289,
     348,   264,   348,   290,    -1,    25,   289,   348,   290,    -1,
      37,   289,   348,   264,   348,   290,    -1,    36,   289,   348,
     264,   348,   290,    -1,     3,    -1,    10,    -1,    15,    -1,
      11,    -1,    12,    -1,   221,    -1,   222,    -1,   223,    -1,
      81,    -1,    82,    -1,    83,    -1,    -1,    92,   289,   348,
     350,   300,   290,    -1,   353,    -1,   212,   289,   368,   290,
      -1,   212,   289,   368,   264,   348,   290,    -1,   355,    -1,
     378,   257,   348,   258,    -1,   378,   255,   348,   256,    -1,
     217,   255,   355,   256,    -1,   217,   255,   355,   261,   291,
     256,    -1,   219,   255,   355,   351,   256,    -1,   219,   255,
     355,   261,   291,   351,   256,    -1,   219,   255,   355,   289,
     348,   290,   351,   256,    -1,   219,   255,   355,   261,   291,
     289,   348,   290,   351,   256,    -1,   218,   255,   369,   256,
      -1,   262,   378,   289,   290,    -1,   262,   355,   261,   291,
     289,   290,    -1,    95,   289,   378,   290,    -1,    95,   289,
     290,    -1,   378,   288,    -1,   378,   257,   348,   258,   288,
      -1,   378,   255,   348,   256,   288,    -1,   378,   261,   291,
      -1,   378,     9,   378,   261,   291,    -1,   378,   261,   291,
     255,   348,   256,    -1,   378,     9,   378,   261,   291,   255,
     348,   256,    -1,   378,   261,   291,   257,   348,   258,    -1,
     378,     9,   378,   261,   291,   257,   348,   258,    -1,   378,
     257,   348,   258,   261,   291,    -1,   378,   261,   291,   288,
      -1,   378,   257,   348,   258,   261,   291,   288,    -1,   208,
     255,   368,   264,   348,   256,    -1,    59,   255,   361,   264,
     361,   256,    -1,    60,   289,   368,   264,   368,   290,    -1,
      58,   289,   368,   290,    -1,    61,   289,   368,   264,   368,
     290,    -1,    66,   255,   375,   256,    -1,    -1,   264,   348,
      -1,    -1,   264,   368,    -1,    -1,    93,   355,   357,   354,
     257,   301,   258,    -1,   378,    -1,   378,     9,   378,    -1,
      96,    -1,    96,   348,    -1,    -1,   255,   356,   256,    -1,
     359,    -1,   244,   358,    -1,   243,   358,    -1,   358,   244,
     358,    -1,   358,   243,   358,    -1,   259,   348,   264,   348,
     264,   348,   264,   348,   264,   348,   260,    -1,   259,   348,
     264,   348,   264,   348,   264,   348,   260,    -1,   259,   348,
     264,   348,   264,   348,   260,    -1,   255,   348,   264,   348,
     264,   348,   256,    -1,   361,    -1,   360,   264,   361,    -1,
     348,    -1,   363,    -1,   259,   260,    -1,   259,   364,   260,
      -1,   244,   259,   364,   260,    -1,   348,   245,   259,   364,
     260,    -1,   361,    -1,   259,     8,   260,    -1,     5,    -1,
     244,   363,    -1,   348,   245,   363,    -1,   348,     8,   348,
      -1,   348,     8,   348,     8,   348,    -1,   101,   259,   348,
     260,    -1,   101,   259,     8,   260,    -1,   101,     5,    -1,
     314,   259,     8,   260,    -1,   314,     5,    -1,   138,   313,
     362,    -1,   141,   313,   361,    -1,   313,   193,    67,   361,
      -1,    67,   313,   259,   364,   260,    -1,    76,   314,   259,
     348,   260,    -1,    77,   314,   259,   348,   260,    -1,   317,
      -1,   328,    -1,   337,    -1,   378,   289,   290,    -1,   378,
     261,   291,   289,   290,    -1,   378,     9,   378,   261,   291,
     289,   290,    -1,    41,   257,   378,   258,    -1,    41,   257,
     363,   258,    -1,    41,   255,   363,   256,    -1,    41,   289,
     259,   364,   260,   290,    -1,   378,   289,   259,   364,   260,
     290,    -1,    42,   289,   348,   264,   348,   264,   348,   290,
      -1,    43,   289,   348,   264,   348,   264,   348,   290,    -1,
      44,   289,   368,   290,    -1,    45,   289,   348,   264,   348,
     264,   348,   264,   348,   264,   348,   264,   348,   290,    -1,
     213,   289,   363,   290,    -1,    32,   289,   363,   290,    -1,
     348,    -1,   363,    -1,   364,   264,   348,    -1,   364,   264,
     363,    -1,   259,   348,   264,   348,   264,   348,   264,   348,
     260,    -1,   259,   348,   264,   348,   264,   348,   260,    -1,
     378,    -1,     4,   261,   190,   261,     4,    -1,   259,   367,
     260,    -1,   378,   257,   348,   258,   261,   191,    -1,   365,
      -1,   367,   264,   365,    -1,   369,    -1,   378,    -1,   378,
     257,   348,   258,    -1,   378,   255,   348,   256,    -1,   378,
     261,   291,    -1,   378,     9,   378,   261,   291,    -1,   378,
     261,   291,   255,   348,   256,    -1,   378,     9,   378,   261,
     291,   255,   348,   256,    -1,   378,   257,   348,   258,   261,
       4,    -1,   313,   259,   348,   260,    -1,   138,   313,   259,
     348,   260,    -1,     5,    -1,   226,   257,   378,   258,    -1,
      70,    -1,   224,    -1,    78,    -1,    80,    -1,   210,   255,
     368,   256,    -1,   209,   255,   368,   264,   368,   256,    -1,
     211,   289,   368,   290,    -1,   211,   289,   368,   264,   368,
     290,    -1,   220,   255,   355,   352,   256,    -1,   220,   255,
     355,   261,   291,   352,   256,    -1,    51,   289,   375,   290,
      -1,    52,   255,   368,   256,    -1,    53,   255,   368,   256,
      -1,    54,   255,   368,   264,   368,   264,   368,   256,    -1,
      49,   289,   375,   290,    -1,    63,   289,   368,   290,    -1,
      64,   289,   368,   290,    -1,    65,   289,   368,   290,    -1,
      62,   289,   348,   264,   368,   264,   368,   290,    -1,    57,
     289,   368,   264,   348,   264,   348,   290,    -1,    57,   289,
     368,   264,   348,   290,    -1,    50,   289,   368,   290,    -1,
      50,   289,   368,   264,   364,   290,    -1,    71,   289,   368,
     290,    -1,    72,    -1,    73,    -1,    56,   289,   368,   290,
      -1,    55,   289,   368,   290,    -1,    -1,    97,   289,   369,
     370,   304,   290,    -1,    94,   289,   371,   290,    -1,   262,
     348,    -1,   378,     9,   262,   348,    -1,    49,   289,   374,
     290,    -1,   375,    -1,   374,    -1,   259,   375,   260,    -1,
     368,    -1,   376,    -1,   375,   264,   368,    -1,   375,   264,
     376,    -1,   378,   255,   256,    -1,   378,   261,   291,   255,
     256,    -1,   378,     9,   378,   261,   291,   255,   256,    -1,
       4,   263,   259,   348,   260,    -1,   377,   263,   259,   348,
     260,    -1,   227,   257,   368,   258,   263,   259,   348,   260,
      -1,     4,    -1,   377,    -1,   227,   257,   368,   258,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   271,   271,   272,   277,   279,   283,   284,   285,   286,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   324,   328,   335,   340,
     345,   350,   364,   377,   390,   403,   431,   445,   458,   471,
     490,   495,   496,   497,   498,   499,   500,   504,   506,   511,
     513,   519,   623,   518,   641,   648,   659,   658,   676,   683,
     694,   693,   710,   727,   750,   749,   763,   764,   765,   766,
     767,   771,   772,   778,   778,   780,   780,   785,   786,   787,
     788,   789,   795,   796,   797,   798,   803,   809,   871,   886,
     915,   925,   930,   938,   943,   951,   960,   965,   977,   994,
    1000,  1009,  1027,  1045,  1054,  1066,  1071,  1079,  1099,  1122,
    1142,  1150,  1172,  1195,  1233,  1254,  1266,  1280,  1280,  1282,
    1284,  1293,  1303,  1302,  1323,  1322,  1340,  1350,  1349,  1363,
    1365,  1373,  1379,  1384,  1411,  1413,  1416,  1418,  1422,  1423,
    1427,  1439,  1443,  1447,  1460,  1474,  1482,  1495,  1497,  1501,
    1502,  1507,  1515,  1524,  1532,  1546,  1564,  1568,  1575,  1584,
    1587,  1593,  1597,  1609,  1612,  1619,  1622,  1628,  1651,  1667,
    1683,  1700,  1717,  1754,  1798,  1814,  1830,  1862,  1878,  1895,
    1911,  1961,  1979,  1985,  1991,  1998,  2029,  2044,  2066,  2089,
    2112,  2135,  2159,  2183,  2207,  2233,  2250,  2266,  2284,  2302,
    2314,  2328,  2327,  2357,  2359,  2361,  2363,  2365,  2373,  2375,
    2377,  2379,  2387,  2389,  2391,  2399,  2401,  2403,  2405,  2415,
    2431,  2447,  2463,  2479,  2495,  2512,  2549,  2571,  2595,  2596,
    2601,  2604,  2608,  2625,  2645,  2665,  2684,  2711,  2730,  2751,
    2766,  2782,  2800,  2851,  2872,  2894,  2917,  3022,  3038,  3073,
    3095,  3117,  3129,  3135,  3150,  3178,  3190,  3199,  3206,  3218,
    3238,  3242,  3247,  3251,  3256,  3263,  3270,  3277,  3289,  3362,
    3380,  3405,  3420,  3453,  3465,  3497,  3501,  3506,  3513,  3518,
    3528,  3533,  3539,  3547,  3551,  3555,  3559,  3563,  3567,  3571,
    3583,  3592,  3656,  3672,  3689,  3706,  3728,  3750,  3785,  3793,
    3801,  3807,  3814,  3821,  3841,  3867,  3879,  3890,  3908,  3926,
    3945,  3944,  3969,  3968,  3995,  3994,  4019,  4018,  4041,  4057,
    4074,  4091,  4114,  4142,  4145,  4151,  4163,  4183,  4187,  4191,
    4195,  4199,  4203,  4207,  4211,  4220,  4233,  4234,  4235,  4236,
    4237,  4241,  4242,  4243,  4244,  4245,  4248,  4272,  4291,  4314,
    4317,  4333,  4336,  4353,  4356,  4362,  4365,  4372,  4375,  4382,
    4404,  4445,  4489,  4528,  4553,  4565,  4577,  4589,  4601,  4618,
    4635,  4652,  4682,  4708,  4734,  4766,  4793,  4819,  4845,  4871,
    4897,  4919,  4930,  4978,  5032,  5047,  5059,  5070,  5077,  5092,
    5106,  5107,  5108,  5112,  5118,  5130,  5148,  5176,  5177,  5178,
    5179,  5180,  5181,  5182,  5183,  5184,  5191,  5192,  5193,  5194,
    5195,  5196,  5197,  5198,  5199,  5200,  5201,  5202,  5203,  5204,
    5205,  5206,  5207,  5208,  5209,  5210,  5211,  5212,  5213,  5214,
    5215,  5216,  5217,  5218,  5219,  5220,  5221,  5222,  5223,  5224,
    5225,  5226,  5227,  5228,  5229,  5230,  5239,  5240,  5241,  5242,
    5243,  5244,  5245,  5246,  5247,  5248,  5249,  5254,  5253,  5261,
    5263,  5268,  5273,  5277,  5282,  5287,  5291,  5295,  5299,  5303,
    5307,  5311,  5317,  5332,  5336,  5342,  5347,  5366,  5386,  5407,
    5411,  5415,  5419,  5423,  5427,  5431,  5436,  5446,  5456,  5461,
    5472,  5481,  5486,  5491,  5519,  5520,  5526,  5527,  5533,  5532,
    5555,  5557,  5562,  5564,  5570,  5571,  5576,  5580,  5584,  5588,
    5592,  5599,  5603,  5607,  5611,  5618,  5623,  5630,  5635,  5639,
    5644,  5648,  5656,  5667,  5671,  5675,  5689,  5697,  5705,  5712,
    5722,  5745,  5750,  5756,  5761,  5767,  5778,  5784,  5798,  5804,
    5816,  5830,  5840,  5850,  5860,  5872,  5876,  5881,  5893,  5897,
    5901,  5905,  5923,  5931,  5939,  5968,  5978,  5994,  6005,  6010,
    6014,  6018,  6030,  6034,  6046,  6063,  6073,  6077,  6092,  6097,
    6104,  6108,  6113,  6127,  6141,  6145,  6149,  6153,  6157,  6165,
    6171,  6180,  6184,  6188,  6196,  6202,  6208,  6212,  6219,  6227,
    6234,  6243,  6247,  6251,  6266,  6280,  6294,  6306,  6322,  6331,
    6340,  6350,  6361,  6369,  6377,  6381,  6400,  6407,  6413,  6419,
    6426,  6434,  6433,  6443,  6467,  6469,  6475,  6480,  6482,  6487,
    6492,  6497,  6499,  6503,  6515,  6529,  6533,  6540,  6548,  6556,
    6567,  6569,  6572
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "tDOUBLE", "tSTRING", "tBIGSTR", "tEND",
  "tAFFECT", "tDOTS", "tSCOPE", "tPi", "tMPI_Rank", "tMPI_Size",
  "tEuclidian", "tCoordinates", "tTestLevel", "tExp", "tLog", "tLog10",
  "tSqrt", "tSin", "tAsin", "tCos", "tAcos", "tTan", "tRand", "tAtan",
  "tAtan2", "tSinh", "tCosh", "tTanh", "tFabs", "tAbs", "tFloor", "tCeil",
  "tRound", "tMin", "tMax", "tFmod", "tModulo", "tHypot", "tList",
  "tLinSpace", "tLogSpace", "tListFromFile", "tCatenary", "tPrintf",
  "tError", "tWarning", "tStr", "tSprintf", "tStrCat", "tStrPrefix",
  "tStrRelative", "tStrReplace", "tAbsolutePath", "tDirName", "tStrSub",
  "tStrLen", "tFind", "tStrFind", "tStrCmp", "tStrChoice", "tUpperCase",
  "tLowerCase", "tLowerCaseIn", "tTextAttributes", "tBoundingBox", "tDraw",
  "tSetChanged", "tToday", "tFixRelativePath", "tCurrentDirectory",
  "tCurrentFileName", "tSyncModel", "tNewModel", "tMass", "tCenterOfMass",
  "tOnelabAction", "tOnelabRun", "tCodeName", "tCpu", "tMemory",
  "tTotalMemory", "tCreateTopology", "tCreateGeometry",
  "tClassifySurfaces", "tRenumberMeshNodes", "tRenumberMeshElements",
  "tDistanceFunction", "tDefineConstant", "tUndefineConstant",
  "tDefineNumber", "tDefineStruct", "tNameStruct", "tDimNameSpace",
  "tAppend", "tDefineString", "tSetNumber", "tSetTag", "tSetString",
  "tPoint", "tCircle", "tEllipse", "tCurve", "tSphere", "tPolarSphere",
  "tSurface", "tSpline", "tVolume", "tBox", "tCylinder", "tCone", "tTorus",
  "tEllipsoid", "tQuadric", "tShapeFromFile", "tRectangle", "tDisk",
  "tWire", "tGeoEntity", "tCharacteristic", "tLength", "tParametric",
  "tElliptic", "tRefineMesh", "tRecombineMesh", "tAdaptMesh",
  "tRelocateMesh", "tReorientMesh", "tSetFactory", "tThruSections",
  "tWedge", "tFillet", "tChamfer", "tPlane", "tRuled", "tTransfinite",
  "tPhysical", "tCompound", "tPeriodic", "tParent", "tUsing", "tPlugin",
  "tDegenerated", "tRecursive", "tSewing", "tRotate", "tTranslate",
  "tSymmetry", "tDilate", "tExtrude", "tLevelset", "tAffine",
  "tBooleanUnion", "tBooleanIntersection", "tBooleanDifference",
  "tBooleanSection", "tBooleanFragments", "tThickSolid", "tRecombine",
  "tSmoother", "tSplit", "tDelete", "tCoherence", "tIntersect",
  "tMeshAlgorithm", "tReverseMesh", "tMeshSizeFromBoundary",
  "tOnlyInitialMesh", "tLayers", "tScaleLast", "tHole", "tAlias",
  "tAliasWithOptions", "tCopyOptions", "tQuadTriAddVerts",
  "tQuadTriNoNewVerts", "tRecombLaterals", "tTransfQuadTri", "tText2D",
  "tText3D", "tInterpolationScheme", "tTime", "tCombine", "tBSpline",
  "tBezier", "tNurbs", "tNurbsOrder", "tNurbsKnots", "tColor",
  "tColorTable", "tFor", "tIn", "tEndFor", "tIf", "tElseIf", "tElse",
  "tEndIf", "tExit", "tAbort", "tField", "tReturn", "tCall", "tSlide",
  "tMacro", "tShow", "tHide", "tGetValue", "tGetStringValue", "tGetEnv",
  "tGetString", "tGetNumber", "tUnique", "tHomology", "tCohomology",
  "tBetti", "tExists", "tFileExists", "tGetForced", "tGetForcedStr",
  "tGMSH_MAJOR_VERSION", "tGMSH_MINOR_VERSION", "tGMSH_PATCH_VERSION",
  "tGmshExecutableName", "tSetPartition", "tNameToString", "tStringToName",
  "tAFFECTDIVIDE", "tAFFECTTIMES", "tAFFECTMINUS", "tAFFECTPLUS", "'?'",
  "tOR", "tAND", "tNOTEQUAL", "tEQUAL", "'<'", "'>'", "tGREATERGREATER",
  "tLESSLESS", "tGREATEROREQUAL", "tLESSOREQUAL", "'+'", "'-'", "'*'",
  "'/'", "'%'", "'|'", "'&'", "'!'", "UNARYPREC", "tMINUSMINUS",
  "tPLUSPLUS", "'^'", "'('", "')'", "'['", "']'", "'{'", "'}'", "'.'",
  "'#'", "'~'", "','", "$accept", "All", "GeoFormatItems", "GeoFormatItem",
  "SendToFile", "Printf", "View", "Views", "ElementCoords",
  "ElementValues", "Element", "@1", "@2", "Text2DValues", "Text2D", "@3",
  "Text3DValues", "Text3D", "@4", "InterpolationMatrix", "Time", "@5",
  "NumericAffectation", "NumericIncrement", "LP", "RP", "tSTRING_Reserved",
  "Affectation", "Comma", "DefineConstants", "@6", "@7", "@8",
  "UndefineConstants", "Enumeration", "FloatParameterOptionsOrNone",
  "FloatParameterOptionsOrNone_NoComma", "FloatParameterOptions",
  "FloatParameterOption", "CharParameterOptionsOrNone",
  "CharParameterOptions", "CharParameterOption",
  "PhysicalId_per_dim_entity", "SurfaceConstraints", "CircleOptions",
  "LoopOptions", "Shape", "@9", "GeoEntity", "GeoEntity123", "GeoEntity12",
  "GeoEntity02", "Transform", "MultipleShape", "ListOfShapes", "LevelSet",
  "Delete", "Colorify", "SetPartition", "Visibility", "Command", "Slide",
  "Loop", "Extrude", "@10", "@11", "@12", "@13", "ExtrudeParameters",
  "ExtrudeParameter", "BooleanOperator", "BooleanOption", "Boolean",
  "BooleanShape", "TransfiniteType", "TransfiniteArrangement",
  "TransfiniteCorners", "RecombineAngle", "PeriodicTransform",
  "Constraints", "Coherence", "HomologyCommand", "Homology", "FExpr",
  "FExpr_Single", "@14", "GetForced_Default", "GetForcedStr_Default",
  "DefineStruct", "@15", "Struct_FullName", "Append", "AppendOrNot",
  "VExpr", "VExpr_Single", "RecursiveListOfListOfDouble", "ListOfDouble",
  "ListOfDoubleOrAll", "FExpr_Multi", "RecursiveListOfDouble", "ColorExpr",
  "ListOfColor", "RecursiveListOfColor", "StringExprVar", "StringExpr",
  "@16", "NameStruct_Arg", "Str_BracedRecursiveListOfStringExprVar",
  "BracedOrNotRecursiveListOfStringExprVar",
  "BracedRecursiveListOfStringExprVar", "RecursiveListOfStringExprVar",
  "MultiStringExprVar", "StringIndex", "String__Index", 0
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
     455,   456,   457,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,   474,
     475,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,   486,    63,   487,   488,   489,   490,    60,    62,   491,
     492,   493,   494,    43,    45,    42,    47,    37,   124,    38,
      33,   495,   496,   497,    94,    40,    41,    91,    93,   123,
     125,    46,    35,   126,    44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   265,   266,   266,   267,   267,   268,   268,   268,   268,
     268,   268,   268,   268,   268,   268,   268,   268,   268,   268,
     268,   268,   268,   268,   268,   268,   269,   269,   270,   270,
     270,   270,   270,   270,   270,   270,   271,   271,   271,   271,
     272,   272,   272,   272,   272,   272,   272,   273,   273,   274,
     274,   276,   277,   275,   278,   278,   280,   279,   281,   281,
     283,   282,   284,   284,   286,   285,   287,   287,   287,   287,
     287,   288,   288,   289,   289,   290,   290,   291,   291,   291,
     291,   291,   292,   292,   292,   292,   292,   292,   292,   292,
     292,   292,   292,   292,   292,   292,   292,   292,   292,   292,
     292,   292,   292,   292,   292,   292,   292,   292,   292,   292,
     292,   292,   292,   292,   292,   292,   292,   293,   293,   294,
     294,   294,   295,   294,   296,   294,   294,   297,   294,   298,
     298,   299,   299,   299,   300,   300,   301,   301,   302,   302,
     303,   303,   303,   303,   303,   303,   303,   304,   304,   305,
     305,   306,   306,   306,   306,   306,   307,   307,   307,   308,
     308,   308,   308,   309,   309,   310,   310,   311,   311,   311,
     311,   311,   311,   311,   311,   311,   311,   311,   311,   311,
     311,   311,   311,   311,   311,   311,   311,   311,   311,   311,
     311,   311,   311,   311,   311,   311,   311,   311,   311,   311,
     311,   312,   311,   313,   313,   313,   313,   313,   314,   314,
     314,   314,   315,   315,   315,   316,   316,   316,   316,   317,
     317,   317,   317,   317,   317,   317,   317,   317,   318,   318,
     319,   319,   319,   319,   319,   319,   319,   320,   320,   320,
     320,   320,   320,   320,   320,   320,   320,   320,   320,   321,
     321,   321,   321,   321,   321,   321,   321,   322,   322,   323,
     324,   324,   324,   324,   324,   324,   324,   324,   325,   325,
     325,   325,   325,   325,   325,   325,   325,   325,   325,   325,
     325,   325,   325,   325,   325,   325,   325,   325,   325,   325,
     325,   325,   326,   327,   327,   327,   327,   327,   327,   327,
     327,   327,   327,   327,   327,   327,   327,   328,   328,   328,
     329,   328,   330,   328,   331,   328,   332,   328,   328,   328,
     328,   328,   328,   333,   333,   334,   334,   334,   334,   334,
     334,   334,   334,   334,   334,   334,   335,   335,   335,   335,
     335,   336,   336,   336,   336,   336,   337,   337,   338,   339,
     339,   340,   340,   341,   341,   342,   342,   343,   343,   344,
     344,   344,   344,   344,   344,   344,   344,   344,   344,   344,
     344,   344,   344,   344,   344,   344,   344,   344,   344,   344,
     344,   344,   344,   344,   344,   344,   344,   345,   345,   345,
     346,   346,   346,   347,   347,   347,   347,   348,   348,   348,
     348,   348,   348,   348,   348,   348,   348,   348,   348,   348,
     348,   348,   348,   348,   348,   348,   348,   348,   348,   348,
     348,   348,   348,   348,   348,   348,   348,   348,   348,   348,
     348,   348,   348,   348,   348,   348,   348,   348,   348,   348,
     348,   348,   348,   348,   348,   348,   349,   349,   349,   349,
     349,   349,   349,   349,   349,   349,   349,   350,   349,   349,
     349,   349,   349,   349,   349,   349,   349,   349,   349,   349,
     349,   349,   349,   349,   349,   349,   349,   349,   349,   349,
     349,   349,   349,   349,   349,   349,   349,   349,   349,   349,
     349,   349,   349,   349,   351,   351,   352,   352,   354,   353,
     355,   355,   356,   356,   357,   357,   358,   358,   358,   358,
     358,   359,   359,   359,   359,   360,   360,   361,   361,   361,
     361,   361,   361,   362,   362,   362,   363,   363,   363,   363,
     363,   363,   363,   363,   363,   363,   363,   363,   363,   363,
     363,   363,   363,   363,   363,   363,   363,   363,   363,   363,
     363,   363,   363,   363,   363,   363,   363,   363,   364,   364,
     364,   364,   365,   365,   365,   365,   366,   366,   367,   367,
     368,   368,   368,   368,   368,   368,   368,   368,   368,   368,
     368,   369,   369,   369,   369,   369,   369,   369,   369,   369,
     369,   369,   369,   369,   369,   369,   369,   369,   369,   369,
     369,   369,   369,   369,   369,   369,   369,   369,   369,   369,
     369,   370,   369,   369,   371,   371,   372,   373,   373,   374,
     375,   375,   375,   375,   376,   376,   376,   377,   377,   377,
     378,   378,   378
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     2,     1,     1,     1,     5,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     5,     5,
       5,     7,     7,     7,     7,     9,     6,     6,     6,     8,
       0,     2,     2,     2,     2,     2,     2,     1,     3,     1,
       3,     0,     0,    10,     1,     3,     0,    13,     1,     3,
       0,    15,     8,    14,     0,     6,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     5,     5,     2,     7,     7,     4,     3,     6,
       9,     7,     6,     7,     6,     4,     8,     9,     9,     6,
       9,     6,     9,     5,     8,     8,    11,     6,     9,     5,
       7,     9,     9,    11,     7,     9,     9,     0,     1,     0,
       3,     5,     0,     9,     0,    11,     5,     0,     9,     0,
       3,     3,     5,     5,     0,     2,     0,     1,     1,     3,
       2,     2,     2,     1,     4,     2,     2,     0,     2,     1,
       3,     2,     2,     2,     2,     2,     1,     1,     3,     0,
       5,     5,     5,     0,     2,     0,     2,     7,     7,     7,
      10,    10,     8,     8,     7,     7,    11,     7,     8,     8,
       8,     9,     3,     4,    10,     7,     7,     7,     7,     7,
       7,     7,     7,     7,     7,     9,     7,     7,     8,     8,
      12,     0,     9,     1,     1,     1,     1,     4,     1,     1,
       1,     4,     1,     1,     4,     1,     1,     1,     4,     5,
      11,     5,     9,     9,     7,     4,     9,     9,     1,     1,
       0,     2,     6,     7,     7,     6,     7,     8,    10,    14,
      16,    12,    14,    14,    14,    14,     8,     8,     6,     4,
       5,     5,     6,     6,     3,     4,     3,     5,     6,     5,
       4,     3,     4,     3,     4,     5,     4,     5,     3,     5,
       7,     7,     3,     7,     3,     2,     2,     2,     2,     2,
      15,     2,     2,     2,     9,    11,     2,     2,     2,     2,
       2,    16,    11,     6,     8,     8,    10,     1,     2,     2,
       1,     3,     3,     4,     4,     1,     1,     5,    11,    13,
       0,     7,     0,    13,     0,    15,     0,     6,     9,     2,
       3,    10,    13,     1,     2,     5,     7,     2,     2,     3,
       2,     3,     2,     3,     9,     6,     1,     1,     1,     1,
       1,     0,     2,     3,     3,     4,     9,     4,    14,     0,
       3,     0,     1,     0,     2,     0,     2,     0,     2,     6,
       7,     6,     5,     3,     8,     8,     8,     8,     8,     8,
       8,     5,     4,     6,    11,    11,    18,    18,    12,    12,
      12,    10,     4,     4,     4,     4,     4,     2,     3,     6,
       1,     1,     1,     2,     5,     7,    10,     1,     3,     2,
       2,     2,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       5,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     6,     4,     4,     4,     4,     4,     4,     4,     4,
       6,     6,     6,     4,     6,     6,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     6,     1,
       4,     6,     1,     4,     4,     4,     6,     5,     7,     8,
      10,     4,     4,     6,     4,     3,     2,     5,     5,     3,
       5,     6,     8,     6,     8,     6,     4,     7,     6,     6,
       6,     4,     6,     4,     0,     2,     0,     2,     0,     7,
       1,     3,     1,     2,     0,     3,     1,     2,     2,     3,
       3,    11,     9,     7,     7,     1,     3,     1,     1,     2,
       3,     4,     5,     1,     3,     1,     2,     3,     3,     5,
       4,     4,     2,     4,     2,     3,     3,     4,     5,     5,
       5,     1,     1,     1,     3,     5,     7,     4,     4,     4,
       6,     6,     8,     8,     4,    14,     4,     4,     1,     1,
       3,     3,     9,     7,     1,     5,     3,     6,     1,     3,
       1,     1,     4,     4,     3,     5,     6,     8,     6,     4,
       5,     1,     4,     1,     1,     1,     1,     4,     6,     4,
       6,     5,     7,     4,     4,     4,     8,     4,     4,     4,
       4,     8,     8,     6,     4,     6,     4,     1,     1,     4,
       4,     0,     6,     4,     2,     4,     4,     1,     1,     3,
       1,     1,     3,     3,     3,     5,     7,     5,     5,     8,
       1,     1,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     2,     3,     1,   630,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   203,
       0,     0,   204,     0,     0,   205,     0,   206,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   336,   337,   338,   339,   340,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   297,     0,     0,   305,   306,     0,     0,     0,   300,
       0,     0,     0,     0,     0,   390,   391,   392,     0,     0,
       5,     6,     7,     8,    10,     0,    11,    24,    12,    13,
      14,    15,    23,    22,    21,    16,     0,    17,    18,    19,
      20,     0,    25,     0,   631,     0,   230,     0,     0,     0,
       0,     0,     0,   279,     0,   281,   282,   277,   278,     0,
     283,   286,     0,   287,   288,   119,   129,   630,   504,   500,
      73,    74,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     289,   290,     0,   215,   216,   217,     0,     0,     0,     0,
     446,   447,   449,   450,   448,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   454,   455,   456,     0,     0,   203,   208,
     209,   210,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   451,   452,   453,     0,     0,     0,     0,
       0,     0,     0,     0,   541,   542,     0,   543,   517,   397,
     459,   462,   319,   518,   500,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   203,   204,   205,   206,   201,   208,
     209,     0,   210,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     506,     0,     0,   230,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   630,
       0,     0,   230,     0,     0,   387,     0,     0,     0,   212,
     213,     0,     0,     0,     0,     0,     0,     0,   525,     0,
       0,   523,     0,     0,     0,     0,     0,   630,     0,     0,
     564,     0,     0,     0,     0,   275,   276,     0,   581,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   583,     0,   607,   608,   585,   586,     0,     0,
       0,     0,     0,     0,   584,     0,     0,     0,     0,   298,
     299,     0,   230,     0,   230,     0,     0,     0,   500,     0,
       0,     0,   230,   393,     0,     0,    84,     0,    66,     0,
       0,    70,    69,    68,    67,    72,    71,    73,    74,     0,
       0,     0,     0,     0,     0,     0,   570,   500,     0,   229,
       0,   228,     0,   182,     0,     0,   570,   571,     0,     0,
       0,   620,     0,   621,   571,     0,   117,   117,     0,   498,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     558,   559,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    73,    74,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   532,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   400,     0,   399,   526,   401,     0,   519,     0,     0,
     500,     0,   534,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    73,    74,     0,   476,     0,
       0,     0,     0,     0,     0,     0,   320,     0,   353,   353,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   230,     0,   230,   230,     0,   508,   507,     0,     0,
       0,     0,   230,   230,     0,     0,     0,     0,   316,     0,
     230,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   355,     0,     0,     0,     0,     0,   230,   256,
       0,     0,   254,   388,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   363,   274,     0,     0,
       0,     0,     0,   230,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     302,   301,     0,   261,     0,     0,   263,     0,     0,     0,
     399,     0,   230,     0,     0,     0,     0,     0,     0,     0,
     341,     0,     0,     0,     0,     0,     0,     0,     0,    77,
      78,    79,    80,    81,     0,     0,     0,     0,    88,    75,
      76,     0,     0,     0,   272,    40,   268,     0,     0,     0,
       0,     0,   225,     0,     0,     0,     0,     0,   231,     0,
       0,   183,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     118,     0,     0,     0,   502,     0,     0,   501,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   347,
       0,     0,     0,   207,     0,     0,     0,     0,     0,     0,
     383,   384,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   500,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   457,   475,     0,     0,
       0,     0,   535,   536,     0,     0,     0,     0,     0,   494,
       0,   398,   520,     0,     0,     0,     0,   528,     0,   417,
     416,   415,   414,   410,   411,   418,   419,   413,   412,   403,
     402,     0,   404,   527,   405,   408,   406,   407,   409,   501,
       0,     0,   479,     0,   544,     0,     0,     0,     0,     0,
       0,     0,     0,   351,     0,     0,     0,     0,     0,     0,
     386,     0,     0,     0,     0,   385,     0,   230,     0,     0,
       0,     0,     0,   510,   509,     0,     0,     0,     0,     0,
       0,     0,   310,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   372,     0,     0,   255,
       0,     0,     0,   249,     0,     0,     0,     0,   382,     0,
       0,     0,     0,     0,   398,   524,     0,     0,     0,     0,
       0,     0,     0,     0,   303,   304,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   611,     0,     0,     0,   496,     0,
       0,   260,   264,   262,   266,     0,   404,     0,   501,   479,
     632,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      95,     0,     0,   398,     0,     0,     0,    66,     0,     0,
      87,     0,    66,    67,     0,     0,     0,   501,     0,     0,
     479,     0,     0,     0,   201,     0,     0,     0,   627,    28,
      26,    27,     0,     0,     0,     0,     0,   574,    30,     0,
      29,     0,     0,   269,   622,   623,     0,   624,   574,     0,
      82,   120,    83,   130,   503,   505,   136,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   560,   561,   218,     9,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   443,   430,     0,
     432,   433,   434,   435,   436,   557,   437,   438,   439,     0,
       0,     0,     0,     0,   549,   548,   547,     0,     0,     0,
     554,     0,   491,     0,     0,     0,   493,     0,     0,     0,
     134,   474,   531,   530,   211,     0,     0,   460,   556,   465,
       0,   471,     0,     0,     0,     0,   521,     0,     0,   472,
     537,   533,     0,     0,     0,     0,   464,   463,    73,    74,
     486,     0,     0,     0,     0,     0,     0,     0,   398,   349,
     354,   352,     0,   362,     0,   156,   157,     0,   211,     0,
     398,     0,     0,     0,     0,   250,     0,   265,   267,     0,
       0,     0,   219,   221,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   323,     0,   307,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   230,     0,
     356,   371,     0,     0,     0,   251,     0,     0,     0,     0,
     214,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   257,     0,     0,     0,     0,   597,     0,   604,   593,
     594,   595,     0,   610,   609,     0,     0,   598,   599,   600,
     606,   614,   613,     0,   147,     0,   587,     0,   589,     0,
       0,     0,   582,     0,   259,     0,     0,     0,     0,     0,
       0,     0,   342,     0,     0,     0,   394,     0,   628,     0,
     109,    66,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   103,     0,     0,     0,     0,   579,    51,
       0,     0,     0,    64,     0,    41,    42,    43,    44,    45,
      46,     0,   464,   463,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   573,   572,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   143,     0,     0,
       0,   137,   138,     0,     0,     0,     0,     0,     0,     0,
     163,   163,     0,     0,     0,     0,     0,   159,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   359,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   538,   539,   540,     0,     0,     0,     0,
       0,   494,   495,     0,   467,     0,     0,   529,   420,   522,
     480,   478,     0,   477,     0,     0,   545,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   361,     0,     0,     0,
       0,     0,     0,     0,     0,    77,     0,   258,     0,     0,
       0,     0,     0,     0,     0,   328,     0,     0,   327,     0,
     330,     0,   332,     0,   317,   324,     0,     0,     0,   248,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   373,
       0,   253,   252,   389,     0,     0,     0,     0,    37,    38,
       0,     0,     0,     0,   565,     0,     0,     0,   293,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     496,   497,   591,     0,   480,     0,     0,   230,   343,     0,
     344,   230,     0,     0,   580,     0,    94,     0,     0,     0,
       0,    92,     0,   568,     0,   107,     0,    99,   101,     0,
       0,     0,    89,     0,     0,     0,     0,     0,    36,   480,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    31,    32,     0,   575,     0,     0,    34,    33,
       0,   575,   625,     0,     0,   121,   126,     0,     0,     0,
     140,   145,   146,   141,   142,   499,     0,    85,     0,     0,
       0,     0,    86,   167,     0,     0,     0,     0,   168,   185,
     186,   165,     0,     0,     0,   169,   196,   187,   191,   192,
     188,   189,   190,   177,     0,     0,   431,   445,   444,   440,
     441,   442,   550,     0,     0,     0,   489,   490,   492,   135,
     458,   488,   461,   466,     0,     0,   494,   197,   473,    73,
      74,     0,   485,   481,   483,   551,   193,     0,     0,     0,
     159,     0,     0,   360,     0,   158,     0,     0,     0,     0,
       0,     0,   273,     0,     0,     0,     0,   230,   230,     0,
       0,   329,   517,     0,     0,   331,   333,     0,     0,   311,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     224,   194,     0,     0,     0,     0,     0,     0,   174,   175,
       0,     0,     0,     0,   110,   114,     0,   605,     0,     0,
     603,     0,   615,     0,     0,   148,   149,   612,   588,   590,
       0,     0,     0,     0,     0,     0,   341,   345,   341,     0,
     395,    93,     0,     0,    66,     0,     0,    91,     0,   566,
       0,     0,     0,     0,     0,     0,   618,   617,     0,     0,
       0,     0,     0,   515,     0,     0,    77,   270,   481,   271,
       0,     0,     0,     0,     0,   235,   232,     0,     0,   578,
     576,     0,     0,     0,     0,   122,   127,     0,     0,     0,
     558,   559,   139,   364,   365,   366,   367,   164,   172,   173,
     178,     0,     0,     0,     0,     0,   180,     0,     0,     0,
       0,     0,     0,   468,     0,     0,     0,   546,   487,     0,
       0,   179,     0,   198,   350,     0,     0,     0,     0,   199,
       0,     0,     0,     0,     0,     0,   514,   513,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   247,   246,
       0,     0,     0,     0,     0,     0,     0,     0,   237,     0,
       0,   368,   369,   370,    39,     0,   563,     0,     0,   295,
     294,     0,     0,     0,     0,     0,     0,   151,   152,   155,
     154,   153,     0,   592,     0,   629,     0,     0,     0,     0,
       0,     0,     0,     0,   104,   105,   569,     0,     0,     0,
      96,     0,     0,     0,    47,     0,     0,     0,     0,     0,
      49,     0,   236,   233,   234,    35,     0,     0,   626,   284,
       0,   134,   147,     0,     0,   144,     0,     0,     0,   166,
     195,     0,     0,     0,     0,     0,   552,   553,     0,   494,
     469,   482,   484,     0,     0,   181,   202,     0,     0,     0,
     357,   357,     0,   115,   116,   230,     0,   222,   223,   318,
       0,   325,     0,     0,   230,     0,     0,     0,     0,     0,
       0,     0,     0,   227,   226,     0,     0,     0,     0,   111,
     112,   596,   602,   601,   150,     0,     0,     0,   346,     0,
       0,   108,   100,   102,     0,    90,   619,    97,    98,    52,
       0,     0,     0,     0,   516,     0,     0,   482,   577,     0,
       0,     0,     0,   124,   616,     0,   131,     0,     0,     0,
       0,   184,     0,     0,     0,   321,     0,   170,   171,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   512,
       0,   335,     0,     0,   312,     0,   238,     0,     0,     0,
       0,     0,     0,     0,   562,   296,     0,     0,   381,   230,
     396,     0,   567,     0,    48,     0,     0,     0,    65,    50,
       0,   285,   123,   128,   134,     0,     0,   161,   162,   160,
       0,     0,   470,     0,     0,     0,     0,   358,   374,     0,
       0,   375,     0,   220,     0,   326,     0,   308,     0,   230,
       0,     0,     0,     0,     0,     0,   176,   113,   292,   341,
     106,     0,     0,     0,     0,     0,     0,   132,   133,     0,
       0,     0,   200,     0,   378,     0,   379,   380,   511,     0,
       0,   314,   241,     0,     0,     0,     0,     0,     0,     0,
       0,    56,     0,    62,     0,     0,   125,     0,     0,   322,
       0,     0,   334,   313,   309,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   242,   243,   244,   245,     0,   239,   348,
      53,     0,    60,     0,   280,     0,   555,     0,     0,   315,
       0,     0,    54,     0,     0,   291,     0,     0,   240,     0,
       0,     0,     0,     0,     0,    57,    55,     0,    58,     0,
     376,   377,     0,     0,    63,    61,    59
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,   120,  1092,   121,   122,  1076,  1943,  1949,
    1375,  1593,  2103,  2231,  1376,  2204,  2247,  1377,  2233,  1378,
    1379,  1597,   450,   608,   609,  1164,  1692,   123,   801,   476,
    1961,  2114,  1962,   477,  1829,  1457,  1410,  1411,  1412,  1557,
    1765,  1766,  1234,  1654,  1645,  1842,   778,   620,   282,   283,
     362,   207,   284,   460,   461,   127,   128,   129,   130,   131,
     132,   133,   134,   285,  1268,  2138,  2195,   970,  1264,  1265,
     286,  1055,   287,   138,  1485,  1232,   943,   985,  2073,   139,
     140,   141,   142,   288,   289,  1190,  1205,  1331,   290,   806,
     291,   805,   479,   637,   330,  1802,   371,   372,   293,   578,
     379,  1359,  1584,   471,   466,  1324,  1032,  1632,  1795,  1796,
    1017,   473,   144,   428
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1929
static const yytype_int16 yypact[] =
{
   12242,    49,    48, 12446, -1929, -1929,   114,    94,   -36,  -165,
    -128,  -109,    43,   201,   255,   262,   267,    59,   283,   354,
      88,   373,   394,   127,   133,    16,  -177,   635,  -177,   198,
     204,   241,    15,   264,   269,    50,   287,   296,   315,   413,
     419,   437,   450,   456,   462,   471,   248,   407,   362,   726,
     756,   349,   147,   660,   529,  6912,   530,   519,   531,   700,
     -70,    30,   527,   -32,   525,   572,   724,   -76,   570,  -100,
    -100,   578,   175,   367,   609, -1929, -1929, -1929, -1929, -1929,
     584,    89,   742,   772,    23,    80,   774,   789,   388,   798,
     799,   915,   918,   931,  5896,   943,   658,   702,   717,    13,
      53, -1929,   746,   748, -1929, -1929,   952,  1008,   762, -1929,
    1689,   778, 12692,    24,    25, -1929, -1929, -1929, 12058,   770,
   -1929, -1929, -1929, -1929, -1929,   776, -1929, -1929, -1929, -1929,
   -1929, -1929, -1929, -1929, -1929, -1929,   191, -1929, -1929, -1929,
   -1929,    73, -1929,  1030,   775,  5641,    35,   780,  1031, 12058,
   12630, 12630, 12630, -1929, 12058, -1929, -1929, -1929, -1929, 12630,
   -1929, -1929, 12058, -1929, -1929, -1929, -1929,   777,   786,  1034,
   -1929, -1929, 12728,   790,   792,   793,   796,    16, 12058, 12058,
   12058,   797, 12058, 12058, 12058,   801, 12058, 12058, 12058, 12058,
   12058, 12058, 12058, 12630, 12058, 12058, 12058, 12058,  5896,   802,
   -1929, -1929,  9685, -1929, -1929, -1929,   785,  5896,  7165, 12630,
   -1929, -1929, -1929, -1929, -1929,  -177,  -177,  -177,  -177,  -177,
    -177,  -177,  -177,  -177,  -177,  -177,  -177,  -177,  -177,  -177,
    -177,  -177,  -177,  -177,  -177,  -177,  -177,  -177,  -177,  -177,
     -35,  -177,  -177,  -177,  -177,  -177,   803,  -177,  -177,   804,
     527,   536,   536, -1929, -1929, -1929,  -177,  -177,    33,   861,
     867,   868,   805,  7165,   934,   527,   527,   807,  -177,  -177,
     811,   812,   813, -1929, -1929, -1929, 12058,  7418, 12058, 12058,
    7671,    16,   876,    42, -1929, -1929,   814, -1929,  4832, -1929,
   -1929, -1929, -1929, -1929,   100, 12058,  9685,  9685,   815,   817,
    7924,  5896,  5896,  5896, -1929, -1929, -1929, -1929, -1929, -1929,
   -1929,   819, -1929,   816,   822,  8177,   823, 10624,  1074,  7165,
     828,    13,   832,   833,  -100,  -100,  -100, 12058, 12058,   -28,
   -1929,   193,  -100, 10710,   378,   205,   838,   839,   840,   841,
     842,   843,   844,  9685, 12058,  5896,  5896,  5896,   846,    12,
    1096,   847, -1929,  1097,  1099, -1929,   848,   849,   851, -1929,
   -1929,   852,  5896,   853,   854,   857,   858,   859, -1929, 12058,
    6153, -1929,  1100,  1111, 12058, 12058, 12058,   -19, 12058,   860,
   -1929,   925, 12058, 12058, 12058, -1929, -1929, 12058, -1929,  -177,
    -177,  -177,   865,   872,   883,  -177,  -177,  -177,  -177,  -177,
    -177,  -177, -1929,  -177, -1929, -1929, -1929, -1929,  -177,  -177,
     884,   904,  -177,   905, -1929,   866,  1155,  1156,   906, -1929,
   -1929,  1158,  1159,  1160,  1162,  -177, 12058,  8640,   117, 12630,
    9685, 12058, -1929, -1929,  7165,  7165, -1929,   912, 12728,   527,
    1161, -1929, -1929, -1929, -1929, -1929, -1929, 12058, 12058,    56,
    7165,  1166,   435,   914,  1869,   916,  1168,    58,   917, -1929,
     919, 11767, 12058, -1929,  1926,  -211, -1929,    76,    65,    70,
   10913, -1929,   342, -1929,   101, 11328,  -199,  -143,  1081, -1929,
      16,   920, 12058, 12058, 12058, 12058,   921, 15113, 15138, 15163,
   12058, 15188, 15213, 15238, 12058, 15263, 15288, 15313, 15338, 15363,
   15388, 15413,   922, 15438, 15463, 15488,  5130,  1176, 12058,  9685,
    5048, -1929,   153, 12058,  1200,  1201,   953, 12058, 12058, 12058,
   12058, 12058, 12058, 12058, 12058, 12058, 12058, 12058, 12058, 12058,
   12058, 12058, 12058,  9685, 12058, 12058, 12058, 12058, 12058, 12058,
   12058, 12058,  9685,  9685,   951, 12058, 12058, 12630, 12058, 12630,
    7165, 12630, 12630, 12630,   956,   957,   958, 12058,    69, -1929,
   10963, 12058,  7165,  5896,  7165, 12630, 12630,  9685,    16, 12728,
      16,   959,  9685,   959, -1929,   959, 15513, -1929,   271,   950,
     108,  1145, -1929,  1210, 12058, 12058, 12058, 12058, 12058, 12058,
   12058, 12058, 12058, 12058, 12058, 12058, 12058, 12058,  8430, 12058,
   12058, 12058, 12058, 12058,    16, 12058, 12058,    99, -1929,   715,
   15538,   281,   294, 12058, 12058, 12058, -1929,  1216,  1217,  1217,
     970, 12058, 12058, 12058, 12058,  1220,  9685,  9685, 11254,   971,
    1222, -1929,   972, -1929, -1929,  -175, -1929, -1929, 11588, 11922,
    -100,  -100,    35,    35,  -103, 10710, 10710, 12058,  5962,   -86,
   -1929, 12058, 12058, 12058, 12058, 12058, 12058, 12058, 12058, 12058,
     316, 15563,  1223,  1226,  1227, 12058,  1229, 12058, -1929, -1929,
   12058,  6219, -1929, -1929,  9685,  9685,  9685, 12058,  1230,  9685,
    9685, 12058, 12058, 12058, 15588,   969, -1929, -1929, 15613, 15638,
   15663,  1043, 12241, -1929,   978,  5315, 15688, 15713, 14708, 12630,
   12630, 12630, 12630, 12630, 12630, 12630, 12630, 12630, 12058, 12630,
   12630, 12630, 12630,    14, 12728, 12630, 12630, 12630,    16,    16,
   -1929, -1929,  9685, -1929,   979,  6472, -1929,   981,  6725, 12058,
     959, 12058, -1929,    16, 12058, 12058,    99,   980,   384, 15738,
   11092,   986,   488, 12058,  1237,   988,  7165, 15763, 14735, -1929,
   -1929, -1929, -1929, -1929,   987,  1242,   158,  1244, -1929, -1929,
   -1929,  9685,   173, 12058, -1929, -1929, -1929,    16, 12058, 12058,
      99,   994, -1929,   997,   -67,   527,   -32,   527, -1929,   995,
   13812, -1929,   144,  9685,    16, 12058, 12058,    99,  1247,  9685,
    1249,  9685, 12058,  1250, 12630,    16, 11049,    99, 12058,  1251,
   -1929,    16,  1252, 12630, 12058,  1003,  1004, -1929, 12058, 12626,
   12687, 12723, 12756, 12728,  1253,  1256,  1259, 15788,  1260,  1261,
    1262, 15813,  1263,  1264,  1266,  1268,  1272,  1273,  1274, -1929,
    1275,  1276,  1277, -1929, 12058, 15838,  9685,  1026,  9685, 13841,
   -1929, -1929,  1280, 14681, 14681, 14681, 14681, 14681, 14681, 14681,
   14681, 14681, 14681, 14681, 12789, 14681, 14681, 14681, 14681,  1211,
     177, 14681, 14681, 14681, 12822, 12855, 12888, 12921, 12954,  5048,
    1032,  1029,    93,  9685, 12987, 13020,   177, 13053,   177,  1025,
    1027,  1028,   464,  9685, 12058, 12058, 16788, -1929,   177,  1036,
   13870, 13899, -1929, -1929,  1035,   230,   177,   -69,  1042,   476,
     496,  1283, -1929,    99,   177,  7165,  1040,  5557,  5583,   576,
     646,   441,   441,   406,   406,   406,   406,   406,   406,   416,
     416,  9685,   -46, -1929,   -46,   -46,   959,   959,   959,  1041,
   15863, 14762,   549,  9685, -1929,  1294,  1044,  1046, 15888, 15913,
   15938, 12058,  7165,  1302,  1301, 10376, 15963, 13928, 15988, 16013,
   -1929,   511,   523,  9685,  1047, -1929,  6978, -1929,  7231,  7484,
    -100, 12058, 12058, -1929, -1929,  1050,  1051, 10710,  8865,  1170,
     -48,  -100,  7737, 16038, 13957, 16063, 16088, 16113, 16138, 16163,
   16188, 16213,  1055,  1308, 12058,  1313, -1929, 12058, 16238, -1929,
   14789,  7990, 14816, -1929,   533,   539,   580, 13986, -1929,   582,
     583, 14843, 14870, 13086, -1929, -1929,  1314,  1316,  1318,  1059,
   12058,  8243, 12058, 12058, -1929, -1929,    29,   310,   336,   310,
    1070,  1072,  1065,   177,   177,  1066, 13119,   177,   177,   177,
     177, 12058,   177,  1322, -1929,  1069,  1078,   346,   544,  1077,
     588, -1929, -1929, -1929, -1929, 14681,   -46,  8496,  1075,   579,
    1076,  1144,  1331,  1177, 11297,  1083,  1082,  1338,  7165, 14015,
   -1929, 12058,  1339,   168,    34,    99,    22, 12728, 12058,  1340,
   -1929,   590,  1298,  1299,  7165, 14044,    31,  1088, 16263, 14897,
     513, 12058, 12058,  1095,  1092,  1101,  1093,  8683, -1929, -1929,
   -1929, -1929, 12630,   465,  1098, 16288, 14924,  1102, -1929,   482,
   -1929,   485, 13152, -1929, -1929, -1929,  1103, -1929,  1105, 13185,
   -1929,    67, -1929, -1929, 16788, -1929,    96, 14681, 12058, 12058,
   12058, 12058,   177,  -100,  7165,  7165,  1347,  7165,  7165,  7165,
    1351,  7165,  7165,  7165,  7165,  7165,  7165,  7165,  7165,  7165,
    7165,  2119,  1354,  9685,  5048, -1929, -1929, -1929, -1929, -1929,
   -1929, -1929, -1929, -1929, -1929, -1929, -1929, -1929, -1929, 12058,
   -1929, -1929, -1929, -1929, -1929, -1929, -1929, -1929, -1929, 12058,
   12058, 12058, 12058, 12058, -1929, -1929, -1929,   600, 12058, 12058,
   -1929, 12058, -1929,  7165, 12630, 12630, -1929,   602, 14073, 14102,
    1104, -1929, -1929, -1929,  1169, 12058, 12058, -1929, -1929, -1929,
      99, -1929,    99, 12058, 12058,  1109, -1929,  7165,  -177, -1929,
   -1929, -1929, 12058, 12058,   603,    99,   386,   405, 12058, 12058,
   -1929,   177,   605,  7165,  9685,  9685,  1359,  1360,  1362,  2265,
   -1929, -1929,  1364, -1929,  1115, 16788,  1108,  1366, -1929,  1367,
    1368,  1370,  1371,   613,   412, -1929,  9245, -1929, -1929,   -75,
   13218, 13251, -1929, -1929, 14131,   165,  1265,  1375, 11390,  1122,
    1376,  1128,    52,    57,   252, -1929,   -73, -1929,   -48,  1379,
    1382,  1383,  1384,  1385,  1386,  1387,  1388,  1389,    35,  7165,
   16788, -1929,  2380,  1130,  1391, -1929,  1393,  1394,  1295,  1396,
   -1929,  1398,  1399,  1395,  1401, 12058,  7165,  7165,  7165,  1404,
   13284, -1929,  8617,  1324,    99,    99, -1929,  9685, -1929, -1929,
   -1929, -1929, 12630, -1929, -1929, 12058, 12630, -1929, -1929, -1929,
   -1929, 16788, -1929,  1147,  1146, 12630, -1929, 12630, -1929,    99,
   12630,  1157, -1929,  1148, -1929,    99, 12058, 12058,  1152,   527,
    1163, 11638, -1929,  2725,  1165,  7165, -1929,  1154, -1929, 14160,
   -1929, -1929, 12058,  1409,    62, 12058,  1410,  1411,    13,  1414,
    1164,  1419,  2802, -1929,   177,  -177,  -177,  1420, -1929, -1929,
    1172,  1173,  1171, -1929,  1423, -1929, -1929, -1929, -1929, -1929,
   -1929,    99,   498,  4774, 12058, 14951, 16313, 12058,  8931, 12058,
    9685,  1174,   615,  1429,   154,    99, -1929,  1175, 12058,  1431,
    1432, 12058,    99, 11724, 12058,  9933,   177,  5098, 12058, 12058,
    1181,  1153, -1929,  1434, 16338, 16363, 16388, 16413,  1435,    36,
    1326,  1326,  7165,  1456,  1457,  1458,  7165,  -111,  1460,  1464,
    1465,  1466,  1467,  1469,  1470,  1471,  1475, -1929,  1478,   637,
   14681, 14681, 14681, 14681, 14681, 14681,   177, 13317, 13350, 13383,
    1228,   177,   177, -1929, -1929, -1929,    96,   177, 16438, 14681,
    1233,  -151, 16788, 14681, -1929,  1479,   177, 16788, 16788, -1929,
     219, -1929,    99, -1929, 16463, 14978, -1929,   177,  1486,   643,
     644,  7165,  7165,  7165,  1489,  1488, -1929,   214, 12058,  7165,
    7165,  7165,  1236,  1238,  1491,  1490,  1492, -1929, 12058, 12058,
   12058,  1241,  1243,  1246,  1254, -1929,  2949,  7165, -1929, 12058,
   -1929,  1495, -1929,  1497, -1929, -1929, 10710,   313,  6406, -1929,
    1248,  1255,  1257,  1258,  1267,  1269,  9179,  1270,  1500, -1929,
    9685, -1929, -1929, -1929,  1278, 12058, 12058, 12058, -1929, -1929,
   15005,  1502,  1503,  1321, -1929, 12058, 12058, 12058, -1929,  1506,
     170,   411,  1279,  3386,  1281, 12058,    40,   177,  1282,   177,
    1284, -1929, -1929, 12728,   363, 12058,  1285, -1929, -1929,  3004,
   -1929, -1929,  1286,  1507, -1929,  3148, -1929,  1271,  1511,   210,
    3273, -1929,    13, -1929,   650, -1929, 12058, -1929, -1929,   214,
    2191,  4337, -1929,  1287, 12058, 12058,  7165,  1288, -1929,     0,
     516,  1513, 16488,  1514,  1283, 16513,  1289,   651, 16538,   656,
    1515,  1516, -1929, -1929, 12630,  1291,  1520, 16563, -1929, -1929,
   13416,  1296, -1929,  9619,  5377, 16788, -1929,  1518,  -177,  7671,
   -1929, -1929, -1929, 16788, 16788, -1929,    96, -1929,  1523,  1525,
    1527,  1528, -1929, -1929,  -100,  1530,  1533,  1534, -1929, -1929,
   -1929,  1412,   -50,  1436,  1547, -1929, -1929, -1929, -1929, -1929,
   -1929, -1929, -1929, -1929,  1569,  1317, -1929, -1929, -1929, -1929,
   -1929, -1929, -1929, 12058, 12058, 12058, -1929, -1929, -1929,  1153,
   -1929, -1929, -1929, -1929, 12058,  1319,  1325, -1929, -1929, 12058,
   12058,   177,   386, -1929, -1929, -1929, -1929,  1323,  1327,  1571,
    -111,  1575, 12058, -1929,  7165, 16788,  1441,  1443,   757,  9685,
    9685, 12058, -1929, 10376, 14189, 16588,  9964,    35,    35, 12058,
   12058, -1929,   909,  1328, 16613, -1929, -1929, 14218,   -25, -1929,
    1584,  1585,  7165,  -100,  -100,  -100,  -100,  -100,  6659,  1588,
   -1929, -1929,   661, 12058,  3525,  3549,  3828,  1589, -1929, -1929,
    7165, 10312,   954, 16638, -1929, -1929, 10028, -1929, 12630, 12058,
   -1929, 12630, 16788, 10281, 12728,  1332, -1929, -1929, -1929, -1929,
    1341,  1335, 12058, 12058, 14247, 12058, 11092, -1929, 11092,  7165,
   -1929, -1929,    99,    22, 12728, 12058,  1595, -1929,  1596, -1929,
      13, 15032,  7165, 12630,  1597,   177, -1929,  1342,   177, 12058,
   13449, 13482,   664, -1929, 12058, 12058,  1345, -1929,  1346, -1929,
    1362,  1601,  1602,  1368,  1603, -1929, -1929,  1604, 12058, -1929,
   -1929, 12058, 11972,  1606, 12058, -1929, -1929,  1355,  4337,   672,
    4775,  1608, -1929, -1929, -1929, -1929, -1929,   510, -1929, -1929,
   -1929,  1473,  1607,  1357,  1358,  1361, -1929,  1618,  7165, 14681,
   14681, 13515, 14681, -1929,  1369, 16663, 15059, -1929, -1929,  9685,
    9685, -1929,  1621, -1929, 16788,  1622, 12058, 12058,  1373, -1929,
     673,   674, 14653,  3975,  1623,  1378, -1929, -1929, 12058,  1374,
    1380, 14276, 15086,  1624,  7165,  1631,  1390, 12058, -1929, -1929,
     680,    -6,   223,   227,   257,   270,  9432,   274, -1929,  1633,
   14305, -1929, -1929, -1929, -1929,  1453, -1929, 12058, 12058, -1929,
   -1929,  9685,  4003,  1636,  1392, 14681,   177, 16788, -1929, -1929,
   -1929, -1929,    40, -1929, 12728, -1929, 14334,  1408,  1413,  1416,
    1637,  1640,  1641,  4072, -1929, -1929, -1929,  1417,  1646,   681,
   -1929,  1650,  1663,   491, 16788, 12058, 12058,  1421,  7165,   682,
   16788, 16688, -1929, -1929, -1929, -1929, 16713, 13548, -1929, -1929,
   14363,  1104,  1146,  7165,   177, -1929, 12058, 12728,    16, -1929,
   -1929,  9685,  9685, 12058,  1664,   689, -1929, -1929, 12058,  1325,
   -1929, -1929, -1929,   692,   695, -1929, -1929,  4410,  4439,  7165,
     626,   629,  9685, -1929, -1929,    35, 10574, -1929, -1929, -1929,
    1665, -1929,  1422,  7165, -1929, 14392,  1666,  9685,  -100,  -100,
    -100,  -100,  -100, -1929, -1929, 12058, 14421, 14450,   703, -1929,
   -1929, -1929, -1929, -1929, -1929,  1425,  1673,  1424, -1929,  1678,
      13, -1929, -1929, -1929,  1452, -1929, -1929, -1929, -1929, -1929,
   12058, 13581, 13614,  7165, -1929,  1679, 12058,  1427, -1929, 12058,
    1681,  1428,  1430, -1929, -1929,  4806, -1929,  1437,   704,   705,
   14479, -1929,  1438, 13647,  1440, -1929,  1439, -1929, -1929,   706,
    1444,  -100,  7165,  1685,  1445,  -100,  1693,   719,  1442, -1929,
   12058, -1929,  1694,  1563,  9498,  1449, -1929,   720,   293,   335,
     339,   341,   343,  4483, -1929, -1929,  1704,  1705, -1929, -1929,
   -1929,  1706, -1929,  1454, 16788, 12058, 12058,   721, -1929, 16788,
   13680, -1929, -1929, -1929,  1104, 12728,  1459, -1929, -1929, -1929,
   12058, 12058, -1929,  9685,  1708,  -100,    95, -1929, -1929,  -100,
     132, -1929,  1712, -1929, 14508, -1929, 12058, -1929,   -48, -1929,
    1713,  9685,  9685,  9685,  9685,  9432, -1929, -1929, -1929, 11092,
   -1929, 12058, 16738, 13713,    44, 12058,  1461, -1929, -1929, 13746,
   13779,   722, -1929,   345, -1929,   347, -1929, -1929, -1929,  4728,
     333, 10753, -1929,   727,   728,   730,   733,   353,   735,  1463,
     738, -1929, 12058, -1929,  7165, 14537, -1929, 12058, 12058, -1929,
    -100,  -100, -1929, -1929, -1929,   -48,  1714,  1718,  1719,  1721,
    9685,  1722,  1724,  1725,  1477, 16763,   740,  1726, 14566, 14681,
     369,   371,   356, -1929, -1929, -1929, -1929,   760, -1929, -1929,
   -1929, 12630, -1929,  1498, -1929,  1728, -1929, 12058, 12058, -1929,
    1731,   765, -1929,  1504,  7165, -1929, 14595, 14624, -1929,  1742,
   12630, 12630,   766,  1744,  1750, -1929, -1929,   768, -1929,  1758,
   -1929, -1929,  1759, 12630, -1929, -1929, -1929
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1929, -1929, -1929, -1929,   372, -1929, -1929, -1929, -1929,  -383,
   -1929, -1929, -1929, -1929, -1929, -1929, -1929, -1929, -1929, -1929,
   -1929, -1929,  -728,  -137,  4524,  3143,  -406, -1929,  1293, -1929,
   -1929, -1929, -1929, -1929, -1929, -1928, -1929,   317,   135,  -188,
   -1929,  -147, -1929,    77,   357, -1929,  1776, -1929,   306,   -58,
   -1929, -1929,    -1,  -632,  -327, -1929, -1929, -1929, -1929, -1929,
   -1929, -1929,   708,  1778, -1929, -1929, -1929, -1929, -1264, -1261,
    1779, -1764,  1782, -1929, -1929, -1929,  1178, -1929,  -203, -1929,
   -1929, -1929, -1929,  2148, -1929, -1929, -1454,   231,  1789, -1929,
       7, -1929, -1929,    82, -1929, -1723,   526,  -183,  2803,  2495,
    -308,    10, -1929,  2285,   -89, -1929, -1929,    32,   203, -1717,
    -158,  1002, -1929,    -3
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -579
static const yytype_int16 yytable[] =
{
     145,   472,   126,  1515,  1517,   315,   648,  1685,   451,  1890,
     965,   966,  1927,   632,  1928,   507,   666,   377,   167,   181,
     167,   416,   169,   420,   514,   671,   167,   349,  1068,   421,
     423,  1652,   168,  2051,  1074,  1369,  1304,   299,   559,   458,
     299,  1351,  1643,   756,  1763,   782,  1920,   582,     5,   153,
    2183,  1843,   294,   783,   185,     4,   456,   381,  1510,   799,
     749,   300,   167,  1512,  1083,   800,   749,   767,   640,   641,
    1844,   149,   309,   167,  1405,   310,   311,   312,   170,   433,
     171,   353,  1653,   481,   354,   784,   355,   320,   313,   960,
     150,   294,   750,   751,  1257,   725,   380,   728,   750,   751,
    1407,  2164,   604,   749,   170,   740,   171,   417,   148,   604,
     795,  1964,  1258,  1203,   321,   802,   350,   480,   617,   618,
     619,   800,  1259,  1260,  1261,  1975,   733,   151,  1262,  1263,
     322,   323,  1408,  1409,   301,   750,   751,   302,  2166,   303,
     640,   641,   457,   325,   326,   459,   152,   467,   467,   467,
    1089,   329,   331,   314,   334,   327,   474,   640,   641,   328,
    1613,   967,   662,   663,   664,  1067,   752,   753,   640,   641,
     640,   641,   752,   753,   486,  1351,  1755,  1756,   971,   678,
    1072,   356,    68,    69,    70,    71,  2156,  1199,    74,  1498,
     467,  1516,  1200,   555,   556,   294,   345,    83,   346,   294,
      86,   932,   601,   602,   294,   294,   467,   155,   603,   752,
     753,  1370,  1371,  1372,  1373,   640,   641,  1784,   640,   641,
     542,  1351,   543,   100,   351,   101,   102,   103,   104,   105,
    1511,   642,  1854,   109,   110,  1513,   112,   640,   641,  1887,
     119,   119,   691,   119,   147,  1764,   754,   755,   203,   119,
     119,   204,  1577,  1578,   205,  1805,  1515,  1773,  2007,  -575,
     294,   156,   441,   442,   443,   444,  2069,   206,   157,   667,
     182,   668,   378,   158,   294,   147,  1031,   294,   580,   640,
     641,  1358,   352,   422,   424,   119,   445,   446,   579,   160,
    1305,  1374,   560,   294,   294,  1354,   119,   294,   294,   294,
     294,   583,   154,  2184,   956,   186,   958,   959,   382,   125,
     445,   446,   294,   768,   159,   769,   294,  -571,   380,   770,
    2107,   788,   170,   972,   171,   759,   790,   760,   434,   789,
    1049,   785,   435,   786,   791,  1352,  1355,   787,   640,   641,
     294,   991,   294,   294,   294,   445,   446,   162,   605,   744,
     606,  1176,   445,   446,   607,   605,   796,   606,   786,   294,
     161,   607,   797,   170,  1080,   171,  1011,   294,   308,   445,
     446,   335,   734,   146,   735,   640,   641,   147,   736,   163,
     892,  1097,  1090,  1091,   165,  2179,   441,   442,   443,   444,
     166,  1108,  1090,  1091,  1257,   882,   441,   442,   443,   444,
     164,   441,   442,   443,  1073,  1047,   635,   636,   640,   641,
     445,   446,  1258,   837,   644,   649,  1495,   838,   325,   326,
     445,   446,  1259,  1260,  1261,  1502,   467,   294,  1262,  1263,
     327,   294,   294,   759,   333,   760,   640,   641,   441,   442,
     443,   444,   441,   442,   443,   444,   431,   294,   750,   751,
     432,   453,   643,   178,   771,  1257,   453,   453,   453,   179,
     651,  2206,   445,   446,   652,   453,   640,   641,   336,   199,
     640,   641,   337,  1258,  1689,  1257,  1690,   807,   338,   339,
     898,   340,   341,  1259,  1260,  1261,   759,  2008,   760,  1262,
    1263,  2009,   359,  1258,  1196,   360,   180,  1208,  1257,   453,
     640,   641,   342,  1259,  1260,  1261,   294,   197,   361,  1262,
    1263,  2242,  1514,   640,   641,   453,  1258,   640,   641,   183,
    1806,  2010,   752,   753,   184,  2064,  1259,  1260,  1261,   198,
     294,   902,  1262,  1263,  2011,   838,   640,   641,  2012,   294,
     872,   936,   187,  1019,   467,   838,   467,   294,   467,   467,
     474,   188,   750,   751,   937,   888,   554,  2141,   838,   294,
     294,   294,   467,   467,   294,   169,   759,   169,   760,   294,
     189,   563,   564,  1729,   794,   897,   982,   899,   640,   641,
     838,   292,   640,   641,   640,   641,   640,   641,   640,   641,
     640,   641,   759,  2193,   760,   294,   640,   641,   793,  2142,
    1307,   929,   759,  2143,   760,  2144,   794,  2145,   202,  2190,
    1327,  2191,   640,   641,   640,   641,  2229,  2200,  1772,  1069,
    1773,   640,   641,   294,   294,  1034,   752,   753,   304,   316,
    1246,   305,   317,  2227,   306,  2228,   307,   650,   445,   446,
     309,   459,   459,   310,  1051,   312,  1527,    46,   838,   596,
     597,   731,   599,   600,   601,   602,   313,   445,   446,  1357,
     603,   731,   599,   600,   601,   602,  1472,   759,   190,   760,
     603,   294,   294,   294,   191,   838,   294,   294,   590,   591,
     592,   593,   594,   595,   596,   597,   731,   599,   600,   601,
     602,   759,   192,   760,   761,   603,   474,   467,   474,   467,
     467,   467,   467,   467,   467,   193,   467,   467,   467,   467,
    1033,   194,   467,   467,   467,   169,  1039,   195,  1085,   294,
    1186,  1394,   963,   964,  1122,  1038,   196,   636,   794,   838,
    1048,   170,   200,   171,   515,   453,   173,  1202,  1399,   174,
    1203,  1400,   175,   294,   176,   745,   838,  2039,  1057,   838,
     445,   446,  1058,   640,   641,  2040,  1206,  -573,   294,  1704,
     838,  1868,   201,  1869,  1077,   445,   446,   779,  1384,   208,
    1337,  1241,  -574,  2070,  2071,   838,  2074,  2075,   296,  2072,
     294,  1094,  2072,  1242,   209,   295,   294,   838,   294,   292,
     297,   474,  1106,  1287,  1460,  1220,  1461,   838,  1111,  1288,
     467,   445,   446,   838,  1218,  1329,  1219,   298,  1330,  1470,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   596,
     597,   731,   599,   600,   601,   602,   616,   318,   319,   324,
     603,   445,   446,   294,  1336,   294,  1337,   332,  1496,   344,
    1289,   625,  1291,  1292,   838,   630,   838,   838,  1333,   347,
    1364,  1785,   838,   453,   838,   453,  1236,   453,   453,   453,
    1446,  1792,  1453,  1469,   838,  1477,   838,   838,   343,   838,
     294,   453,   453,  1494,  2170,  1611,   348,   838,   357,   838,
     294,   588,   589,   590,   591,   592,   593,   594,   595,   596,
     597,   731,   599,   600,   601,   602,   358,  1665,  1549,  1550,
     603,   838,   294,  1697,  1698,   363,   364,   838,   838,  1515,
    1789,  1812,  1220,   374,  1790,   838,  1814,   584,   294,   365,
     838,  1899,   366,  1560,  1947,   838,  1353,  1356,  1948,  1564,
     294,  2212,  1965,  1990,  1991,   367,  1966,   838,   838,   294,
    2006,  2036,  2045,  1220,  1948,   794,  2046,   373,  1579,  2062,
     294,  1515,  2065,  1948,   779,  2066,   838,   375,   385,   838,
     741,   742,  1908,  2096,  2117,  2118,  2124,   838,   838,   838,
    1948,   759,   376,   760,   933,  1599,   757,   779,  1361,  2132,
    2140,  2154,  2189,   838,   838,  1948,   838,  2196,  2197,  1615,
    2198,   838,   838,  2199,   838,  2201,  1621,   838,  2203,   838,
    2223,   383,  2046,   384,  1948,   453,   453,   453,   453,   453,
     453,   453,   453,   453,   386,   453,   453,   453,   453,   387,
    2230,   453,   453,   453,   838,  2239,  2249,   429,  2252,  2240,
    1948,   779,  2253,   418,   779,   430,   436,   463,   437,   462,
     147,   478,  1249,   480,   513,   482,   779,   483,   484,  1255,
    1583,   485,   490,  1266,  -204,   294,   494,   508,   550,   553,
    -205,  -206,   565,  1360,   561,   562,   568,   569,   570,   581,
     613,   294,   614,   432,   621,   622,   879,   623,   629,  1471,
    1473,  1084,   626,  1086,   294,  1879,  1880,   631,   616,   467,
     893,   633,   634,   653,   654,   655,   656,   657,   658,   659,
     453,   665,   669,   672,   670,   673,   686,   674,   675,   453,
     676,   677,   679,   680,   681,   682,   683,   687,   694,   693,
     702,   294,   294,   719,   294,   294,   294,   703,   294,   294,
     294,   294,   294,   294,   294,   294,   294,   294,   704,   715,
     294,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     594,   595,   596,   597,   598,   599,   600,   601,   602,   716,
     718,   720,   721,   603,   723,   722,   726,   724,   746,  1883,
     727,   743,   758,   763,   766,   765,   146,   804,   829,   772,
     294,   467,   467,   834,   808,   813,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   594,   595,   596,   597,   731,
     599,   600,   601,   602,   294,  1419,   840,   841,   603,   842,
     873,   903,   905,   603,  1909,   883,   884,   885,   906,   584,
     294,   294,   294,   941,   942,   945,   950,   954,   955,  1005,
     984,   957,   986,  1009,   987,   989,   998,  1012,  1050,  1041,
    1776,  1043,  1056,  1060,  1778,  1471,  1473,  1061,  1065,  1066,
    1070,  1081,  1082,  1098,  1087,  1100,  1103,  1110,  1112,  1115,
    1123,  1116,   779,  1124,   779,   779,  1125,  1127,  1128,  1129,
    1131,  1132,  1062,  1133,  1788,  1134,   294,   459,   779,  1135,
    1136,  1137,  1138,  1139,  1140,  1143,  1147,  1175,  1174,  1183,
    1207,  1184,  1185,   294,   294,   294,  1192,   779,  1201,  1195,
    1211,  1223,  1215,  1224,   294,  1225,  1231,  1233,  1244,   467,
    1252,  1253,  1256,   467,  1278,  1279,  1626,   779,  1631,  1281,
    1299,  1296,   467,  1297,   467,  1298,  1310,   467,  1311,  1312,
    1315,  1323,  1547,  1325,  1326,  1332,  1335,  1339,  1340,  1338,
    1341,  1345,   294,  1344,  1346,  1350,  1363,  1365,  1366,  1381,
    1387,  1388,  1390,   779,  1422,   380,  1389,  1398,  1426,  1395,
    1403,  1438,  -207,  2078,  1402,  1464,  1481,  1482,  1456,  1483,
    1486,  1487,  1488,  1489,  1490,  1491,  1930,  1492,  1493,  1504,
     467,  1507,  1508,  1509,  1503,   294,  1518,   294,  1519,  1530,
    1520,  1521,  1522,  1523,  1524,  1525,  1526,  1531,   453,  1532,
    1533,  1538,  1534,  1535,   294,  1536,  1537,  1539,  1544,  1555,
    1556,  1565,  1563,  1562,  1573,  1576,  1581,  1636,  1582,   294,
    1585,  1586,  1567,   294,  1571,  1587,  1592,  1594,  1595,  1598,
    1596,  1210,  1797,  1797,  1610,  1612,  1616,  1618,  1619,  1635,
    1637,  1642,  1786,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   596,   597,   836,   599,   600,   601,
     602,  1644,  1648,  1649,  1650,   603,  1655,   759,  1230,   760,
    1656,  1657,  1658,  1659,  1771,  1660,  1661,  1662,   294,   294,
     294,  1663,  1936,  1664,  1676,  1687,   294,   294,   294,  1683,
     453,   453,  1696,  1702,  1703,  1709,  1712,  1710,  1711,  1713,
    1717,  1725,  1718,  1726,   294,  1719,  1741,  1732,  1748,  1749,
    1750,  1720,  1754,  1780,  1733,   294,  1734,  1735,  1783,  1807,
    1809,  1815,  1816,   294,  1819,  1827,  1736,   294,  1737,  1833,
    1740,  1834,  1782,  1835,  1836,  1826,  1838,  1743,  1768,  1839,
    1840,  1845,  1799,  1758,  1775,  1761,  1818,  1804,  1330,  1811,
    1779,  1822,   779,  1846,  1841,  1858,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   594,   595,   596,   597,   731,
     599,   600,   601,   602,  1847,  1853,  1848,  1861,   603,   380,
    1548,  1863,  1859,  1866,  1347,  1867,  1860,   474,   474,  1203,
    1888,  1889,  1884,   294,  1898,  1904,  1922,  1923,  1728,  1924,
    1367,  1934,  1935,  1940,  -578,  -576,   794,  1952,  1953,  1954,
    1955,   467,  1959,  1970,  1963,  1968,  1971,  1972,   453,  1969,
    1973,   294,   453,  1974,  1874,  1980,   294,  1985,  1986,  1994,
    2001,   453,  1989,   453,  1997,  1939,   453,  1995,  2003,  2013,
    1998,  2015,  2020,  2102,  2030,  1566,  2031,  2032,  2021,  2004,
    1420,  1421,  2035,  1423,  1424,  1425,  2037,  1427,  1428,  1429,
    1430,  1431,  1432,  1433,  1434,  1435,  1436,  1913,  2027,  2038,
    2061,  2081,  2086,  2028,  1918,  1921,  2029,  2084,  2034,  2098,
    2043,  2097,  2082,  2099,  2100,  2108,  -577,  2111,  2112,   453,
    2113,  2128,  2116,   167,   388,  1932,  2122,  2120,  2123,  2131,
    2135,   294,  2133,  2125,  2129,  2136,   294,   294,  2139,  1450,
    2147,  2148,  2150,  2151,  2162,  2158,   459,   459,  2167,  2172,
    2213,  2186,  2101,  2202,  2214,  2215,  1837,  2216,  2218,   294,
    2219,  2220,  2224,  1465,  2235,   294,  2221,  2238,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   294,  2245,  1478,
    2250,   398,   399,   400,   401,   467,  2251,  2234,   467,   402,
     403,   404,   405,  2241,  2254,  2255,  1614,   406,  2180,   407,
     803,  1832,  2149,  1679,  2052,  2024,   294,  1862,  1646,   124,
    1360,   135,   136,   408,  1380,   137,   409,   380,  2076,   294,
     474,  1770,   143,  1931,  1798,  1919,  1105,   944,     0,     0,
       0,     0,     0,     0,     0,  1528,     0,     0,     0,     0,
       0,     0,  2171,     0,     0,  1891,  1892,  1893,  1894,  1895,
    1897,     0,  1541,  1542,  1543,   474,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2025,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   294,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   294,   294,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1572,     0,     0,     0,   764,     0,     0,  2056,     0,
       0,   294,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   294,     0,     0,   453,   453,   410,   411,
     412,     0,     0,     0,     0,     0,     0,     0,   294,   413,
       0,     0,     0,   414,     0,   415,   119,     0,     0,     0,
     453,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   781,  1630,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   294,     0,     0,  1647,     0,
       0,     0,  1651,     0,     0,     0,     0,     0,     0,     0,
     294,     0,     0,     0,     0,  2057,     0,     0,   294,   294,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   294,     0,     0,   294,
       0,     0,     0,     0,   459,     0,     0,     0,     0,     0,
     294,     0,     0,     0,   294,     0,     0,  1699,  1700,  1701,
       0,     0,     0,     0,     0,  1706,  1707,  1708,     0,     0,
       0,     0,     0,     0,     0,     0,  2157,   380,     0,     0,
       0,     0,     0,  1723,     0,     0,     0,     0,     0,     0,
     294,     0,     0,     0,  1731,     0,     0,     0,     0,     0,
       0,     0,  1739,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   453,     0,     0,   453,     0,   294,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   779,     0,   779,     0,     0,     0,     0,     0,
    2088,  2089,  2090,  2091,  2092,     0,     0,     0,     0,   453,
       0,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     594,   595,   596,   597,   731,   599,   600,   601,   602,     0,
     294,     0,  1803,   603,     0,  1437,     0,     0,     0,     0,
       0,     0,     0,     0,   453,     0,     0,     0,   294,   294,
     294,   294,   294,     0,     0,     0,     0,     0,     0,     0,
    1825,     0,     0,  2126,     0,     0,     0,  2130,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   596,
     597,   731,   599,   600,   601,   602,     0,     0,     0,     0,
     603,   294,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   167,   388,   294,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2163,     0,     0,
       0,  2165,     0,     0,     0,     0,     0,     0,   467,     0,
       0,     0,     0,     0,     0,     0,     0,  2177,     0,     0,
    1865,   294,     0,     0,     0,     0,     0,   467,   467,     0,
     389,   390,   391,   392,   393,   394,   395,   396,   397,     0,
     467,     0,     0,   398,   399,   400,   401,     0,  1803,     0,
       0,   402,   403,   404,   405,     0,   427,     0,     0,   406,
       0,   407,  2210,  2211,     0,     0,  1905,     0,     0,     0,
       0,     0,     0,     0,     0,   408,     0,     0,   409,     0,
       0,     0,   304,   454,     0,   305,     0,   464,   306,     0,
     307,     0,   470,     0,     0,  1929,     0,     0,     0,     0,
     475,    46,     0,     0,     0,     0,     0,     0,  1938,     0,
       0,     0,     0,     0,     0,     0,   487,   488,   489,   439,
     491,   492,   493,     0,   495,   496,   497,   498,   499,   500,
     501,     0,   503,   504,   505,   506,     0,     0,     0,     0,
     510,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     594,   595,   596,   597,   731,   599,   600,   601,   602,     0,
       0,     0,     0,   603,  1803,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1529,     0,     0,     0,
     779,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     410,   411,   412,     0,     0,     0,     0,  1484,     0,     0,
    2002,   413,     0,     0,     0,   414,     0,   415,   119,     0,
       0,     0,     0,     0,   571,   573,   575,   576,   510,     0,
     455,     0,     0,     0,     0,   465,   468,   469,     0,     0,
       0,     0,     0,   610,   510,   510,     0,   759,     0,   760,
    1793,     0,     0,     0,     0,   779,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   628,     0,     0,     0,     0,
       0,     0,     0,     0,  2044,   638,   639,   779,   502,     0,
       0,   639,     0,     0,     0,     0,     0,     0,     0,  2053,
       0,   510,   661,     0,   516,     0,     0,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   594,   595,   596,   597,
     731,   599,   600,   601,   602,  1803,     0,   684,   510,   603,
       0,     0,   688,   689,   690,     0,   692,   453,     0,  2083,
     695,   696,   697,     0,     0,   698,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   453,   453,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   453,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1803,
       0,     0,     0,     0,   730,     0,     0,     0,   510,   739,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   747,   748,     0,  2127,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     780,     0,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   596,   597,   731,   599,   600,   601,   602,
     809,   810,   811,   812,   603,     0,     0,     0,   817,     0,
       0,     0,   821,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   835,   573,     0,     0,
       0,   839,     0,     0,     0,   843,   844,   845,   846,   847,
     848,   849,   850,   851,   852,   853,   854,   855,   856,   857,
     858,   859,   861,   862,   863,   864,   865,   866,   867,   868,
     869,   869,     0,   874,   875,     0,   877,   512,     0,     0,
       0,     0,     0,     0,     0,   886,     0,     0,   890,   891,
    1803,     0,     0,     0,   737,   869,     0,     0,     0,     0,
     510,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1570,   907,   908,   909,   910,   911,   912,   913,   914,
     915,   916,   917,   918,   919,   920,   922,   924,   925,   926,
     927,   928,     0,   930,   931,     0,     0,     0,     0,     0,
    1803,   938,   939,   940,     0,     0,     0,     0,     0,   946,
     947,   948,   949,     0,   510,   510,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   611,   612,   571,   730,   968,     0,     0,     0,   973,
     974,   975,   976,   977,   978,   979,   980,   981,  1588,     0,
       0,     0,     0,   988,     0,   990,     0,     0,   992,     0,
       0,     0,   510,   510,   510,   997,     0,   510,   510,  1001,
    1002,  1003,   876,     0,   878,     0,   880,   881,   660,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     894,   895,     0,     0,     0,     0,  1026,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     510,     0,     0,     0,     0,     0,     0,  1045,     0,  1046,
       0,     0,   930,   931,     0,     0,     0,     0,     0,     0,
       0,  1059,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   510,
       0,  1075,     0,     0,     0,     0,  1078,  1079,     0,     0,
       0,     0,     0,     0,     0,   738,     0,     0,     0,     0,
       0,   510,     0,  1095,  1096,     0,     0,   510,     0,   510,
    1102,     0,     0,     0,  1095,     0,  1109,     0,     0,     0,
       0,     0,  1114,     0,     0,  1721,  1117,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   594,   595,   596,   597,
     731,   599,   600,   601,   602,     0,     0,     0,     0,   603,
       0,     0,  1141,     0,   922,  1018,  1144,  1020,  1021,  1022,
    1023,  1024,  1025,     0,  1027,  1028,  1029,  1030,     0,     0,
    1035,  1036,  1037,     0,     0,   511,     0,     0,     0,     0,
    1777,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   510,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   510,  1188,  1189,   585,   586,   587,   588,   589,   590,
     591,   592,   593,   594,   595,   596,   597,   731,   599,   600,
     601,   602,     0,     0,     0,     0,   603,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   900,     0,   510,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1104,
     574,   510,     0,   511,     0,     0,     0,     0,  1113,  1229,
       0,     0,     0,  1235,     0,     0,     0,     0,     0,   511,
     511,   510,     0,     0,     0,     0,     0,     0,     0,  1250,
    1251,     0,     0,     0,     0,  1254,     0,     0,     0,     0,
       0,   951,   952,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1280,     0,     0,  1282,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   511,     0,     0,     0,
       0,     0,     0,     0,  1781,     0,     0,     0,  1300,     0,
    1302,  1303,     0,     0,     0,     0,     0,     0,     0,   994,
     995,   996,     0,   511,   999,  1000,     0,     0,     0,  1321,
       0,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     594,   595,   596,   597,   731,   599,   600,   601,   602,     0,
       0,     0,  1343,   603,     0,     0,     0,     0,     0,  1349,
       0,     0,     0,     0,     0,     0,  1362,  1040,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1385,
    1386,     0,     0,   511,     0,   510,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   594,   595,   596,   597,   731,
     599,   600,   601,   602,     0,     0,  1071,     0,   603,     0,
       0,     0,     0,     0,     0,     0,  1414,  1415,  1416,  1417,
       0,     0,     0,     0,     0,     0,     0,     0,  1093,  1787,
       0,     0,     0,     0,  1099,     0,  1101,     0,     0,     0,
       0,   510,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1440,     0,     0,
       0,     0,   574,     0,     0,     0,     0,  1441,  1442,  1443,
    1444,  1445,     0,     0,     0,     0,  1447,  1448,     0,  1449,
       0,     0,     0,     0,     0,     0,   860,     0,     0,     0,
       0,     0,     0,  1458,  1459,   870,   871,     0,     0,     0,
       0,  1462,  1463,     0,     0,     0,     0,     0,     0,     0,
    1467,  1468,     0,     0,     0,     0,  1474,  1475,  1177,     0,
     896,     0,   510,   510,     0,   511,     0,  1393,  1187,     0,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   594,
     595,   596,   597,   731,   599,   600,   601,   602,     0,     0,
       0,   923,   603,     0,     0,     0,  1506,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1214,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1222,   511,
     511,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1540,     0,     0,     0,     0,  1243,     0,
       0,     0,     0,     0,     0,   510,     0,     0,     0,     0,
       0,     0,     0,  1553,     0,     0,     0,     0,     0,  1451,
    1452,     0,     0,     0,     0,     0,     0,   511,   511,   511,
       0,     0,   511,   511,  1474,  1475,     0,     0,     0,  1569,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1575,     0,     0,  1580,     0,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   594,   595,   596,   597,   731,   599,
     600,   601,   602,     0,     0,   511,     0,   603,     0,     0,
       0,  1901,  1602,     0,     0,  1605,   510,  1608,   510,     0,
       0,     0,     0,     0,     0,     0,  1617,     0,     0,  1620,
       0,  1617,  1623,  1625,     0,  1902,  1633,  1634,     0,     0,
       0,     0,     0,     0,   511,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1392,     0,     0,     0,   511,     0,     0,     0,
       0,     0,   511,     0,   511,   762,     0,  1552,     0,     0,
       0,  1554,     0,     0,     0,     0,     0,     0,     0,     0,
    1558,     0,  1559,     0,     0,  1561,     0,     0,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   596,
     597,   731,   599,   600,   601,   602,  1705,     0,  1439,   923,
     603,  1145,   759,     0,   760,     0,  1714,  1715,  1716,     0,
    1759,     0,     0,     0,     0,  1722,     0,  1724,     0,     0,
       0,     0,     0,     0,  1727,     0,     0,     0,  1601,     0,
       0,     0,     0,     0,     0,     0,   511,     0,   510,     0,
       0,     0,     0,  1744,  1745,  1746,   511,     0,     0,     0,
       0,     0,     0,  1751,  1752,  1753,     0,     0,     0,     0,
       0,   887,     0,  1762,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1774,     0,     0,     0,     0,     0,  1479,
    1480,     0,     0,     0,   511,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1791,     0,   511,     0,     0,     0,
       0,     0,  1800,  1801,     0,     0,     0,     0,     0,     0,
       0,     0,   934,     0,     0,     0,   511,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   594,   595,   596,   597,
     731,   599,   600,   601,   602,     0,     0,  1830,     0,   603,
       0,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     594,   595,   596,   597,   731,   599,   600,   601,   602,     0,
       0,     0,  1551,   603,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1849,  1850,  1851,     0,     0,     0,     0,     0,     0,
       0,     0,  1852,     0,  1903,     0,     0,  1855,  1856,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1864,     0,     0,     0,     0,     0,     0,   510,   510,  1872,
       0,  1873,     0,     0,     0,     0,     0,  1881,  1882,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1607,     0,  1609,   510,     0,     0,     0,
     511,  1900,     0,     0,     0,     0,     0,     0,     0,  1817,
       0,     0,     0,     0,  1912,     0,     0,  1915,     0,     0,
       0,  1917,     0,     0,     0,     0,     0,     0,     0,     0,
    1855,  1856,     0,  1926,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1933,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   511,  1944,     0,     0,
       0,     0,  1950,  1951,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1956,     0,     0,  1957,
    1956,     0,  1960,     0,     0,     0,     0,     0,     0,     0,
       0,  1993,     0,     0,     0,     0,  1148,  1149,  1150,  1151,
    1152,  1153,  1154,  1155,  1156,  1157,  1158,     0,  1160,  1161,
    1162,  1163,     0,  1165,  1166,  1167,  1168,   510,   510,  2019,
       0,     0,     0,     0,  1987,  1988,     0,     0,     0,  1180,
       0,  1182,     0,     0,     0,  1742,  1996,   511,   511,     0,
       0,  1191,     0,     0,     0,  2005,     0,     0,  1197,  1198,
       0,     0,     0,  1914,   573,     0,  1916,  1209,     0,     0,
       0,     0,     0,     0,     0,  2016,  2017,     0,     0,   510,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   594,
     595,   596,   597,   731,   599,   600,   601,   602,  2033,     0,
       0,     0,   603,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2041,  2042,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     511,     0,     0,     0,  2055,     0,     0,     0,     0,   510,
     510,  2060,     0,     0,     0,     0,  2063,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     510,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   510,     0,     0,     0,     0,
    1306,  1308,  1309,  2093,     0,     0,  1313,  1314,     0,     0,
    1317,  1318,  1319,  1320,     0,  1322,     0,     0,     0,     0,
    1328,     0,     0,     0,     0,     0,     0,     0,  2104,     0,
       0,   511,     0,   511,  2109,     0,     0,  2110,     0,     0,
       0,     0,     0,     0,  1870,  1871,     0,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   594,   595,   596,   597,
     731,   599,   600,   601,   602,     0,     0,     0,  2134,   603,
       0,     0,     0,     0,     0,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   594,   595,   596,   597,   731,   599,
     600,   601,   602,  2152,  2153,     0,     0,   603,     0,     0,
    1413,     0,     0,     0,     0,  1418,     0,     0,  2159,  2160,
       0,   510,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2169,     0,     0,     0,     0,   510,
     510,   510,   510,   510,     0,     0,     0,     0,     0,  1950,
       0,     0,     0,  2185,   585,   586,   587,   588,   589,   590,
     591,   592,   593,   594,   595,   596,   597,   731,   599,   600,
     601,   602,     0,     0,     0,     0,   603,     0,     0,     0,
    2205,     0,     0,   511,     0,  2208,  2209,     0,     0,     0,
       0,   167,   388,     0,     0,     0,     0,     0,   510,     0,
       0,     0,     0,     0,  1983,  1984,     0,     0,     0,     0,
       0,     0,     0,     0,  1476,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2236,  2237,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   389,   390,   391,   392,
     393,   394,   395,   396,   397,     0,     0,     0,     0,   398,
     399,   400,   401,     0,     0,     0,  2018,   402,   403,   404,
     405,     0,     0,     0,     0,   406,  2067,   407,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   408,  1831,     0,   409,     0,     0,     0,   304,     0,
       0,   305,     0,     0,   306,  2068,   307,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    46,     0,     0,
       0,     0,     0,     0,     0,     0,  2058,  2059,     0,     0,
       0,     0,     0,     0,     0,   439,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2077,     0,  2146,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2087,     0,     0,     0,  2232,  1589,     0,     0,
       0,     0,   511,   511,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2246,  2248,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2256,     0,
       0,   511,     0,     0,     0,     0,   410,   411,   412,  1627,
     172,     0,   177,     0,     0,     0,     0,   413,     0,     0,
       0,   414,     0,   415,   119,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1666,  1667,  1668,  1669,  1670,  1671,  1672,
       0,     0,     0,     0,  1677,  1678,  1793,     0,     0,     0,
    1680,     0,  1682,     0,     0,     0,  1686,     0,     0,  1688,
       0,     0,     0,     0,     0,     0,     0,     0,  2161,     0,
    1695,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2173,  2174,  2175,  2176,
    2178,     0,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   596,   597,   731,   599,   600,   601,   602,
       0,     0,   511,   511,   603,     0,     0,     0,     0,   452,
       0,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     594,   595,   596,   597,   731,   599,   600,   601,   602,     0,
       0,     0,     0,   603,  1757,  2217,  1760,     0,     0,   574,
    1767,     0,  1769,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   511,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   594,   595,   596,   597,   731,   599,
     600,   601,   602,  1794,  2192,     0,     0,   603,     0,   517,
     518,   519,   520,   521,   522,   523,   524,   525,   526,   527,
     528,   529,   530,   531,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   541,   544,   545,   546,   547,   548,   549,
       0,   551,   552,     0,   511,   511,     0,     0,   167,   388,
     557,   558,  1967,   584,     0,     0,     0,     0,     0,     0,
       0,     0,   566,   567,     0,   511,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     511,     0,     0,  2115,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   389,   390,   391,   392,   393,   394,   395,
     396,   397,     0,     0,  1857,     0,   398,   399,   400,   401,
     584,     0,     0,     0,   402,   403,   404,   405,     0,     0,
       0,     0,   406,     0,   407,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   408,     0,
       0,   409,     0,     0,     0,   304,     0,     0,   305,     0,
       0,   306,     0,   307,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    46,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   439,   699,   700,   701,     0,     0,     0,   705,
     706,   707,   708,   709,   710,   711,   511,   712,     0,     0,
       0,     0,   713,   714,     0,     0,   717,     0,  1941,     0,
       0,  1942,     0,     0,   511,   511,   511,   511,   511,   729,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   594,
     595,   596,   597,   731,   599,   600,   601,   602,     0,     0,
       0,     0,   603,   410,   411,   412,     0,     0,     0,     0,
       0,     0,  1976,  1977,   413,  1979,     0,     0,   414,     0,
     415,   119,     0,   511,     0,     0,     0,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   594,   595,   596,   597,
     836,   599,   600,   601,   602,     0,   445,   446,     0,   603,
       0,     0,     0,  -572,     0,  1600,     0,     0,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   596,
     597,   731,   599,   600,   601,   602,   584,     0,  2022,  2023,
     603,     0,     0,     0,   585,   586,   587,   588,   589,   590,
     591,   592,   593,   594,   595,   596,   597,   598,   599,   600,
     601,   602,     0,     0,     0,     0,   603,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   210,     6,   388,   904,     0,     0,  2054,   211,   212,
     213,     0,     0,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,     0,     0,     0,  1628,   390,   391,
     392,   393,   394,   395,   396,   397,   245,   246,   247,   248,
     398,   399,   400,   401,   249,   250,     0,     0,   402,   403,
     404,   405,     0,     0,   251,   252,   406,     0,   407,   253,
     254,   255,     0,     0,     0,     0,     0,     0,     0,     0,
     256,    25,   408,   257,     0,   409,     0,     0,     0,   258,
       0,     0,   259,     0,     0,   260,     0,   261,     0,     0,
       0,     0,     0,     0,    42,     0,     0,     0,   262,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   263,
       0,    57,    58,     0,   264,     0,   265,     0,     0,   266,
       0,     0,     0,     0,     0,    68,    69,    70,    71,    72,
       0,    74,    75,    76,    77,    78,    79,     0,     0,     0,
      83,     0,     0,    86,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   594,
     595,   596,   597,   836,   599,   600,   601,   602,     0,     0,
       0,     0,   603,     0,     0,     0,   267,   410,   411,   412,
     268,   269,     0,     0,     0,   270,   271,   272,   413,   273,
     274,   275,   414,  1013,   415,   119,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   276,   277,     0,     0,     0,     0,     0,   278,     0,
       0,     0,  2226,   369,     0,     0,     0,  1629,     0,     0,
     281,     0,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   596,   597,   731,   599,   600,   601,   602,
     210,     6,   388,     0,   603,     0,     0,   211,   212,   213,
     833,     0,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,  1204,     0,     0,   389,   390,   391,   392,
     393,   394,   395,   396,   397,   245,   246,   247,   248,   398,
     399,   400,   401,   249,   250,     0,     0,   402,   403,   404,
     405,     0,     0,   251,   252,   406,  1221,   407,   253,   254,
     255,     0,     0,     0,     0,     0,     0,     0,     0,   256,
      25,   408,   257,     0,   409,     0,     0,     0,   258,     0,
       0,   259,     0,     0,   260,     0,   261,     0,     0,     0,
       0,     0,     0,    42,     0,     0,     0,   262,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   263,     0,
      57,    58,     0,   264,     0,   265,     0,     0,   266,     0,
       0,     0,     0,     0,    68,    69,    70,    71,    72,     0,
      74,    75,    76,    77,    78,    79,     0,     0,     0,    83,
       0,     0,    86,     0,     0,     0,     0,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   594,   595,   596,   597,
     731,   599,   600,   601,   602,  1212,     0,     0,     0,   603,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   267,   410,   411,   412,   268,
     269,  1213,     0,     0,   270,   271,   272,   413,   273,   274,
     275,   414,     0,   415,   119,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     276,   277,     0,     0,     0,     0,     0,   278,     0,     0,
       0,     0,   369,     0,     0,  1406,   280,     0,     0,   281,
       0,     0,     0,     0,   210,   167,   388,     0,   438,     0,
       0,   211,   212,   213,     0,     0,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   425,   232,   233,   234,   235,   236,   237,
     238,   239,     0,     0,     0,     0,     0,     0,     0,     0,
     389,   390,   391,   392,   393,   394,   395,   396,   397,   245,
     246,   247,   248,   398,   399,   400,   401,   249,     0,     0,
       0,   402,   403,   404,   405,     0,     0,     0,     0,   406,
       0,   407,   253,   254,   255,     0,     0,     0,     0,     0,
       0,     0,  1466,   256,    25,   408,   257,     0,   409,     0,
       0,     0,   304,     0,     0,   305,     0,     0,   306,     0,
     307,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    46,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   439,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   585,
     586,   587,   588,   589,   590,   591,   592,   593,   594,   595,
     596,   597,   731,   599,   600,   601,   602,     0,     0,     0,
       0,   603,     0,     0,     0,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   594,   595,   596,   597,   731,   599,
     600,   601,   602,     0,     0,     0,     0,   603,     0,     0,
       0,     0,   440,     0,     0,     0,     0,     0,     0,   267,
     410,   411,   412,   268,     0,     0,     0,     0,   270,   271,
     272,   413,   273,   274,   275,   414,     0,   415,   119,   441,
     442,   443,   444,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   276,   426,     0,     0,     0,  1590,
    1591,   278,     0,   445,   446,     0,   447,     0,   448,   210,
       6,   368,   449,   281,     0,     0,   211,   212,   213,     0,
       0,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   245,   246,   247,   248,     0,     0,
       0,     0,   249,   250,     0,     0,     0,     0,     0,     0,
       0,     0,   251,   252,     0,     7,     8,   253,   254,   255,
       0,     0,     0,     0,     0,  1684,     0,     0,   256,    25,
       0,   257,     0,     0,  1691,     0,     0,   258,     0,     0,
     259,     0,     0,   260,     0,   261,     0,     0,     0,     0,
       0,     0,    42,     0,     0,     0,   262,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   263,     0,    57,
      58,     0,   264,     0,   265,     0,     0,   266,     0,     0,
       0,     0,     0,    68,    69,    70,    71,    72,     0,    74,
      75,    76,    77,    78,    79,     0,     0,     0,    83,     0,
       0,    86,     0,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,     0,     0,     0,    43,
      44,    45,    46,     0,     0,    48,     0,     0,     0,     0,
       0,     0,     0,   773,    56,     0,     0,    59,   774,     0,
     775,   776,     0,   777,   267,     0,     0,     0,   268,   269,
       0,     0,     0,   270,   271,   272,     0,   273,   274,   275,
       0,    80,     0,   119,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   276,
     277,     0,     0,     0,     0,     0,   278,    96,    97,    98,
       0,   369,  1828,     0,     0,   370,   210,     6,   281,     0,
       0,   685,     0,   211,   212,   213,     0,     0,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   245,   246,   247,   248,     0,     0,     0,     0,   249,
     250,     0,   969,     0,     0,     0,     0,     0,     0,   251,
     252,     0,     7,     8,   253,   254,   255,     0,     0,     0,
       0,     0,     0,     0,     0,   256,    25,     0,   257,     0,
       0,     0,     0,     0,   258,     0,     0,   259,     0,     0,
     260,     0,   261,     0,     0,     0,     0,     0,     0,    42,
       0,     0,     0,   262,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   263,     0,    57,    58,     0,   264,
       0,   265,     0,     0,   266,     0,     0,     0,     0,     0,
      68,    69,    70,    71,    72,     0,    74,    75,    76,    77,
      78,    79,     0,     0,     0,    83,     0,     0,    86,     0,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,     0,     0,     0,    43,    44,    45,    46,
       0,     0,    48,     0,     0,     0,     0,     0,     0,     0,
     773,    56,     0,     0,    59,   774,     0,   775,   776,     0,
     777,   267,     0,     0,     0,   268,   269,     0,     0,     0,
     270,   271,   272,     0,   273,   274,   275,     0,    80,     0,
     119,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   276,   509,     0,     0,
       0,     0,     0,   278,    96,    97,    98,     0,   369,   210,
       6,  1730,     0,   577,     0,   281,   211,   212,   213,     0,
       0,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   245,   246,   247,   248,     0,     0,
       0,     0,   249,   250,     0,     0,     0,     0,     0,   993,
       0,     0,   251,   252,     0,     7,     8,   253,   254,   255,
       0,     0,     0,     0,     0,     0,     0,     0,   256,    25,
       0,   257,     0,     0,     0,     0,     0,   258,     0,     0,
     259,     0,     0,   260,     0,   261,     0,     0,     0,     0,
       0,     0,    42,     0,     0,     0,   262,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   263,     0,    57,
      58,     0,   264,     0,   265,     0,     0,   266,     0,     0,
       0,     0,     0,    68,    69,    70,    71,    72,     0,    74,
      75,    76,    77,    78,    79,     0,     0,     0,    83,     0,
       0,    86,     0,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,     0,     0,     0,    43,
      44,    45,    46,     0,     0,    48,     0,     0,     0,     0,
       0,     0,     0,   773,    56,     0,     0,    59,   774,     0,
     775,   776,     0,   777,   267,     0,     0,     0,   268,   269,
       0,     0,     0,   270,   271,   272,     0,   273,   274,   275,
       0,    80,     0,   119,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   276,
     277,     0,     0,     0,     0,     0,   278,    96,    97,    98,
       0,   369,   210,     6,     0,   280,     0,     0,   281,   211,
     212,   213,     0,     0,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   245,   246,   247,
     248,     0,     0,     0,     0,   249,   250,     0,     0,     0,
       0,     0,  1042,     0,     0,   251,   252,     0,     7,     8,
     253,   254,   255,     0,     0,     0,     0,     0,     0,     0,
       0,   256,    25,     0,   257,     0,     0,     0,     0,     0,
     258,     0,     0,   259,     0,     0,   260,     0,   261,     0,
       0,     0,     0,     0,     0,    42,     0,     0,     0,   262,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     263,     0,    57,    58,     0,   264,     0,   265,     0,     0,
     266,     0,     0,     0,     0,     0,    68,    69,    70,    71,
      72,     0,    74,    75,    76,    77,    78,    79,     0,     0,
       0,    83,     0,     0,    86,     0,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,     0,
       0,     0,    43,    44,    45,    46,     0,     0,    48,     0,
       0,     0,     0,     0,     0,     0,   773,    56,     0,     0,
      59,   774,     0,   775,   776,     0,   777,   267,     0,     0,
       0,   268,   269,     0,     0,     0,   270,   271,   272,     0,
     273,   274,   275,     0,    80,     0,   119,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   645,  1896,     0,     0,     0,     0,     0,   278,
      96,    97,    98,     0,   647,   210,     6,     0,   328,   577,
       0,   281,   211,   212,   213,     0,     0,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     245,   246,   247,   248,     0,     0,     0,     0,   249,   250,
       0,     0,     0,     0,     0,  1044,     0,     0,   251,   252,
       0,     7,     8,   253,   254,   255,     0,     0,     0,     0,
       0,     0,     0,     0,   256,    25,     0,   257,     0,     0,
       0,     0,     0,   258,     0,     0,   259,     0,     0,   260,
       0,   261,     0,     0,     0,     0,     0,     0,    42,     0,
       0,     0,   262,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   263,     0,    57,    58,     0,   264,     0,
     265,     0,     0,   266,     0,     0,     0,     0,     0,    68,
      69,    70,    71,    72,     0,    74,    75,    76,    77,    78,
      79,     0,     0,     0,    83,     0,     0,    86,     0,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,     0,     0,     0,    43,    44,    45,    46,     0,
       0,    48,     0,     0,     0,     0,     0,     0,     0,   773,
      56,     0,     0,    59,   774,     0,   775,   776,     0,   777,
     267,     0,     0,     0,   268,   269,     0,     0,     0,   270,
     271,   272,     0,   273,   274,   275,     0,    80,     0,   119,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   276,   277,     0,     0,     0,
       0,     0,   278,    96,    97,    98,     0,   279,   210,     6,
       0,   280,     0,     0,   281,   211,   212,   213,     0,     0,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   245,   246,   247,   248,     0,     0,     0,
       0,   249,   250,     0,     0,     0,     0,     0,  1245,     0,
       0,   251,   252,     0,     7,     8,   253,   254,   255,     0,
       0,     0,     0,     0,     0,     0,     0,   256,    25,     0,
     257,     0,     0,     0,     0,     0,   258,     0,     0,   259,
       0,     0,   260,     0,   261,     0,     0,     0,     0,     0,
       0,    42,     0,     0,     0,   262,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   263,     0,    57,    58,
       0,   264,     0,   265,     0,     0,   266,     0,     0,     0,
       0,     0,    68,    69,    70,    71,    72,     0,    74,    75,
      76,    77,    78,    79,     0,     0,     0,    83,     0,     0,
      86,     0,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,     0,     0,     0,    43,    44,
      45,    46,     0,     0,    48,     0,     0,     0,     0,     0,
       0,     0,   773,    56,     0,     0,    59,   774,     0,   775,
     776,     0,   777,   267,     0,     0,     0,   268,   269,     0,
       0,     0,   270,   271,   272,     0,   273,   274,   275,     0,
      80,     0,   119,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   276,   277,
       0,     0,     0,     0,     0,   278,    96,    97,    98,     0,
     369,   210,     6,     0,   280,     0,     0,   281,   211,   212,
     213,     0,     0,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   245,   246,   247,   248,
       0,     0,     0,     0,   249,   250,     0,     0,     0,     0,
       0,  1247,     0,     0,   251,   252,     0,     7,     8,   253,
     254,   255,     0,     0,     0,     0,     0,     0,     0,     0,
     256,    25,     0,   257,     0,     0,     0,     0,     0,   258,
       0,     0,   259,     0,     0,   260,     0,   261,     0,     0,
       0,     0,     0,     0,    42,     0,     0,     0,   262,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   263,
       0,    57,    58,     0,   264,     0,   265,     0,     0,   266,
       0,     0,     0,     0,     0,    68,    69,    70,    71,    72,
       0,    74,    75,    76,    77,    78,    79,     0,     0,     0,
      83,     0,     0,    86,     0,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,     0,     0,
       0,    43,    44,    45,    46,     0,     0,    48,     0,     0,
       0,     0,     0,     0,     0,   773,    56,     0,     0,    59,
     774,     0,   775,   776,     0,   777,   267,     0,     0,     0,
     268,   269,     0,     0,     0,   270,   271,   272,     0,   273,
     274,   275,     0,    80,     0,   119,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   276,   509,     0,     0,     0,     0,     0,   278,    96,
      97,    98,     0,   369,   210,     6,     0,   572,     0,     0,
     281,   211,   212,   213,     0,     0,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   245,
     246,   247,   248,     0,     0,     0,     0,   249,   250,     0,
       0,     0,     0,     0,  1248,     0,     0,   251,   252,     0,
       7,     8,   253,   254,   255,     0,     0,     0,     0,     0,
       0,     0,     0,   256,    25,     0,   257,     0,     0,     0,
       0,     0,   258,     0,     0,   259,     0,     0,   260,     0,
     261,     0,     0,     0,     0,     0,     0,    42,     0,     0,
       0,   262,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   263,     0,    57,    58,     0,   264,     0,   265,
       0,     0,   266,     0,     0,     0,     0,     0,    68,    69,
      70,    71,    72,     0,    74,    75,    76,    77,    78,    79,
       0,     0,     0,    83,     0,     0,    86,     0,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,     0,     0,     0,    43,    44,    45,    46,     0,     0,
      48,     0,     0,     0,     0,     0,     0,     0,   773,    56,
       0,     0,    59,   774,     0,   775,   776,     0,   777,   267,
       0,     0,     0,   268,   269,     0,     0,     0,   270,   271,
     272,     0,   273,   274,   275,     0,    80,     0,   119,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   276,   509,     0,     0,     0,     0,
       0,   278,    96,    97,    98,     0,   369,   210,     6,     0,
       0,   577,     0,   281,   211,   212,   213,     0,     0,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   245,   246,   247,   248,     0,     0,     0,     0,
     249,   250,     0,     0,     0,     0,     0,  1267,     0,     0,
     251,   252,     0,     7,     8,   253,   254,   255,     0,     0,
       0,     0,     0,     0,     0,     0,   256,    25,     0,   257,
       0,     0,     0,     0,     0,   258,     0,     0,   259,     0,
       0,   260,     0,   261,     0,     0,     0,     0,     0,     0,
      42,     0,     0,     0,   262,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   263,     0,    57,    58,     0,
     264,     0,   265,     0,     0,   266,     0,     0,     0,     0,
       0,    68,    69,    70,    71,    72,     0,    74,    75,    76,
      77,    78,    79,     0,     0,     0,    83,     0,     0,    86,
       0,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,     0,     0,     0,    43,    44,    45,
      46,     0,     0,    48,     0,     0,     0,     0,     0,     0,
       0,   773,    56,     0,     0,    59,   774,     0,   775,   776,
       0,   777,   267,     0,     0,     0,   268,   269,     0,     0,
       0,   270,   271,   272,     0,   273,   274,   275,     0,    80,
       0,   119,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   276,   277,     0,
       0,     0,     0,     0,   278,    96,    97,    98,     0,   615,
     210,     6,     0,   280,     0,     0,   281,   211,   212,   213,
       0,     0,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   245,   246,   247,   248,     0,
       0,     0,     0,   249,   250,     0,     0,     0,     0,     0,
    1285,     0,     0,   251,   252,     0,     7,     8,   253,   254,
     255,     0,     0,     0,     0,     0,     0,     0,     0,   256,
      25,     0,   257,     0,     0,     0,     0,     0,   258,     0,
       0,   259,     0,     0,   260,     0,   261,     0,     0,     0,
       0,     0,     0,    42,     0,     0,     0,   262,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   263,     0,
      57,    58,     0,   264,     0,   265,     0,     0,   266,     0,
       0,     0,     0,     0,    68,    69,    70,    71,    72,     0,
      74,    75,    76,    77,    78,    79,     0,     0,     0,    83,
       0,     0,    86,     0,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,     0,     0,     0,
      43,    44,    45,    46,     0,     0,    48,     0,     0,     0,
       0,     0,     0,     0,   773,    56,     0,     0,    59,   774,
       0,   775,   776,     0,   777,   267,     0,     0,     0,   268,
     269,     0,     0,     0,   270,   271,   272,     0,   273,   274,
     275,     0,    80,     0,   119,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     276,   277,     0,     0,     0,     0,     0,   278,    96,    97,
      98,     0,   624,   210,     6,     0,   280,     0,     0,   281,
     211,   212,   213,     0,     0,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   245,   246,
     247,   248,     0,     0,     0,     0,   249,   250,     0,     0,
       0,     0,     0,  1301,     0,     0,   251,   252,     0,     7,
       8,   253,   254,   255,     0,     0,     0,     0,     0,     0,
       0,     0,   256,    25,     0,   257,     0,     0,     0,     0,
       0,   258,     0,     0,   259,     0,     0,   260,     0,   261,
       0,     0,     0,     0,     0,     0,    42,     0,     0,     0,
     262,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   263,     0,    57,    58,     0,   264,     0,   265,     0,
       0,   266,     0,     0,     0,     0,     0,    68,    69,    70,
      71,    72,     0,    74,    75,    76,    77,    78,    79,     0,
       0,     0,    83,     0,     0,    86,     0,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
       0,     0,     0,    43,    44,    45,    46,     0,     0,    48,
       0,     0,     0,     0,     0,  1546,     0,   773,    56,     0,
       0,    59,   774,     0,   775,   776,     0,   777,   267,     0,
       0,     0,   268,   269,     0,     0,     0,   270,   271,   272,
       0,   273,   274,   275,     0,    80,     0,   119,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   276,   509,     0,     0,     0,     0,     0,
     278,    96,    97,    98,     0,   369,   210,     6,     0,   921,
       0,  1391,   281,   211,   212,   213,     0,     0,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   245,   246,   247,   248,     0,     0,     0,     0,   249,
     250,     0,     0,     0,     0,     0,  1334,     0,     0,   251,
     252,     0,     0,     0,   253,   254,   255,     0,     0,     0,
       0,     0,     0,     0,     0,   256,    25,     0,   257,     0,
       0,     0,     0,     0,   258,     0,     0,   259,     0,     0,
     260,     0,   261,     0,     0,     0,     0,     0,     0,    42,
       0,     0,     0,   262,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   263,     0,    57,    58,     0,   264,
       0,   265,     0,     0,   266,     0,     0,     0,     0,     0,
      68,    69,    70,    71,    72,     0,    74,    75,    76,    77,
      78,    79,     0,     0,     0,    83,     0,     0,    86,   585,
     586,   587,   588,   589,   590,   591,   592,   593,   594,   595,
     596,   597,   731,   599,   600,   601,   602,     0,     0,     0,
       0,   603,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   596,   597,   731,   599,   600,   601,   602,
       0,   267,     0,     0,   603,   268,   269,     0,     0,   732,
     270,   271,   272,     0,   273,   274,   275,     0,     0,     0,
     119,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   276,   509,     0,     0,
       0,     0,     0,   278,   210,     6,     0,     0,   369,  1606,
       0,   211,   212,   213,     0,   281,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   245,
     246,   247,   248,     0,     0,     0,     0,   249,   250,     0,
       0,     0,     0,     0,     0,     0,     0,   251,   252,     0,
       0,     0,   253,   254,   255,     0,     0,     0,     0,     0,
       0,     0,     0,   256,    25,     0,   257,     0,     0,     0,
       0,     0,   258,     0,     0,   259,     0,     0,   260,     0,
     261,     0,     0,     0,     0,     0,     0,    42,     0,     0,
       0,   262,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   263,     0,    57,    58,     0,   264,     0,   265,
       0,     0,   266,     0,     0,     0,     0,     0,    68,    69,
      70,    71,    72,     0,    74,    75,    76,    77,    78,    79,
       0,     0,     0,    83,     0,     0,    86,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   594,   595,   596,   597,
     731,   599,   600,   601,   602,     0,     0,     0,     0,   603,
       0,  1004,     0,     0,     0,     0,     0,     0,     0,   961,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   267,
       0,     0,     0,   268,   269,     0,     0,     0,   270,   271,
     272,     0,   273,   274,   275,     0,     0,     0,   119,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   276,   509,     0,     0,     0,     0,
       0,   278,   210,     6,     0,     0,   369,     0,     0,   211,
     212,   213,     0,   281,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   245,   246,   247,
     248,     0,     0,     0,     0,   249,   250,     0,     0,     0,
       0,     0,     0,     0,     0,   251,   252,     0,     7,     8,
     253,   254,   255,     0,     0,     0,     0,     0,     0,     0,
       0,   256,    25,     0,   257,     0,     0,     0,     0,     0,
     258,     0,     0,   259,     0,     0,   260,     0,   261,     0,
       0,     0,     0,     0,     0,    42,     0,     0,     0,   262,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     263,     0,    57,    58,     0,   264,     0,   265,     0,     0,
     266,     0,     0,     0,     0,     0,    68,    69,    70,    71,
      72,     0,    74,    75,    76,    77,    78,    79,     0,     0,
       0,    83,     0,     0,    86,     0,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,     0,
       0,     0,    43,    44,    45,    46,     0,     0,    48,     0,
       0,     0,     0,     0,     0,     0,   773,    56,     0,     0,
      59,   774,     0,   775,   776,     0,   777,   267,     0,     0,
       0,   268,   269,     0,     0,     0,   270,   271,   272,     0,
     273,   274,   275,     0,    80,     0,   119,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   276,   277,     0,     0,     0,     0,     0,   278,
      96,    97,    98,     0,   369,   210,     6,     0,  1738,     0,
       0,   281,   211,   212,   213,     0,     0,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     245,   246,   247,   248,     0,     0,     0,     0,   249,   250,
       0,     0,     0,     0,     0,  1497,     0,     0,   251,   252,
       0,     7,     8,   253,   254,   255,     0,     0,     0,     0,
       0,     0,     0,     0,   256,    25,     0,   257,     0,     0,
       0,     0,     0,   258,     0,     0,   259,     0,     0,   260,
       0,   261,     0,     0,     0,     0,     0,     0,    42,     0,
       0,     0,   262,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   263,     0,    57,    58,     0,   264,     0,
     265,     0,     0,   266,     0,     0,     0,     0,     0,    68,
      69,    70,    71,    72,     0,    74,    75,    76,    77,    78,
      79,     0,     0,     0,    83,     0,     0,    86,     0,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,     0,     0,     0,    43,    44,    45,    46,     0,
       0,    48,     0,     0,     0,     0,     0,     0,     0,   773,
      56,     0,     0,    59,   774,     0,   775,   776,     0,   777,
     267,     0,     0,     0,   268,   269,     0,     0,     0,   270,
     271,   272,     0,   273,   274,   275,     0,    80,     0,   119,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   645,  1896,     0,     0,     0,
       0,     0,   278,    96,    97,    98,     0,   647,   210,     6,
       0,   328,     0,     0,   281,   211,   212,   213,     0,     0,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   245,   246,   247,   248,     0,     0,     0,
       0,   249,   250,     0,     0,     0,     0,     0,  2137,     0,
       0,   251,   252,     0,     0,     0,   253,   254,   255,     0,
       0,     0,     0,     0,     0,     0,     0,   256,    25,     0,
     257,     0,     0,     0,     0,     0,   258,     0,     0,   259,
       0,     0,   260,     0,   261,     0,     0,     0,     0,     0,
       0,    42,     0,     0,     0,   262,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   263,     0,    57,    58,
       0,   264,     0,   265,     0,     0,   266,     0,     0,     0,
       0,     0,    68,    69,    70,    71,    72,     0,    74,    75,
      76,    77,    78,    79,     0,     0,     0,    83,     0,     0,
      86,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     594,   595,   596,   597,   731,   599,   600,   601,   602,     0,
       0,     0,     0,   603,     0,     0,     0,     0,     0,  1823,
       0,     0,     0,  1824,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   267,     0,     0,     0,   268,   269,     0,
       0,     0,   270,   271,   272,     0,   273,   274,   275,     0,
       0,     0,   119,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   276,   509,
       0,     0,     0,     0,     0,   278,   210,   167,   388,     0,
     369,     0,     0,   211,   212,   213,     0,   281,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   425,   232,   233,   234,   235,
     236,   237,   238,   239,     0,     0,     0,     0,     0,     0,
       0,     0,   389,   390,   391,   392,   393,   394,   395,   396,
     397,   245,   246,   247,   248,   398,   399,   400,   401,   249,
       0,     0,     0,   402,   403,   404,   405,     0,     0,     0,
       0,   406,     0,   407,   253,   254,   255,     0,     0,     0,
       0,     0,     0,     0,     0,   256,    25,   408,   257,     0,
     409,   210,   167,   388,     0,     0,     0,     0,   211,   212,
     213,     0,     0,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     425,   232,   233,   234,   235,   236,   237,   238,   239,     0,
       0,     0,     0,     0,     0,     0,     0,   389,   390,   391,
     392,   393,   394,   395,   396,   397,   245,   246,   247,   248,
     398,   399,   400,   401,   249,     0,     0,     0,   402,   403,
     404,   405,     0,     0,     0,     0,   406,     0,   407,   253,
     254,   255,     0,     0,     0,     0,     0,     0,     0,     0,
     256,    25,   408,   257,     0,   409,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   267,   410,   411,   412,   268,     0,     0,     0,     0,
     270,   271,   272,   413,   273,   274,   275,   414,     0,   415,
     119,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   276,   426,     0,     0,
       0,     0,     0,   278,     0,     0,     0,     0,   369,     0,
       0,     0,  1624,     0,     0,   281,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   594,   595,   596,   597,   731,
     599,   600,   601,   602,     0,     0,     0,     0,   603,     0,
       0,     0,     0,     0,  1877,     0,     0,     0,  1878,     0,
       0,     0,     0,     0,     0,     0,   267,   410,   411,   412,
     268,     0,     0,     0,     0,   270,   271,   272,   413,   273,
     274,   275,   414,     0,   415,   119,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   276,   426,     0,     0,     0,     0,     0,   278,     0,
       0,     0,     0,   369,   210,   167,   388,  1911,     0,     0,
     281,   211,   212,   213,     0,     0,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   425,   232,   233,   234,   235,   236,   237,
     238,   239,     0,     0,     0,     0,     0,     0,     0,     0,
    1628,   390,   391,   392,   393,   394,   395,   396,   397,   245,
     246,   247,   248,   398,   399,   400,   401,   249,     0,     0,
       0,   402,   403,   404,   405,     0,     0,     0,     0,   406,
       0,   407,   253,   254,   255,     0,     0,     0,     0,     0,
       0,     0,     0,   256,    25,   408,   257,     0,   409,   210,
     167,   388,     0,     0,     0,     0,   211,   212,   213,     0,
       0,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   425,   232,
     233,   234,   235,   236,   237,   238,   239,     0,     0,     0,
       0,     0,     0,     0,     0,   389,   390,   391,   392,   393,
     394,   395,   396,   397,   245,   246,   247,   248,   398,   399,
     400,   401,   249,     0,     0,     0,   402,   403,   404,   405,
       0,     0,     0,     0,   406,     0,   407,   253,   254,   255,
       0,     0,     0,     0,     0,     0,     0,     0,   256,    25,
     408,   257,     0,   409,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   267,
     410,   411,   412,   268,     0,     0,     0,     0,   270,   271,
     272,   413,   273,   274,   275,   414,     0,   415,   119,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   276,   426,     0,     0,     0,     0,
       0,   278,     0,     0,     0,     0,   369,     0,     0,     0,
    1793,     0,     0,   281,   585,   586,   587,   588,   589,   590,
     591,   592,   593,   594,   595,   596,   597,   731,   599,   600,
     601,   602,     0,     0,     0,     0,   603,     0,     0,     0,
       0,     0,  1906,     0,     0,     0,  1907,     0,     0,     0,
       0,     0,     0,     0,   267,   410,   411,   412,   268,     0,
       0,     0,     0,   270,   271,   272,   413,   273,   274,   275,
     414,     0,   415,   119,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   276,
     426,     0,     0,     0,     0,     0,   278,   210,   167,     0,
       0,   369,     0,     0,   211,   212,   213,     0,   281,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   425,   232,   233,   234,
     235,   236,   237,   238,   239,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   245,   246,   247,   248,     0,     0,     0,     0,
     249,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   253,   254,   255,     0,     0,
       0,     0,     0,   210,   167,     0,   256,    25,     0,   257,
     211,   212,   213,     0,     0,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   425,   232,   233,   234,   235,   236,   237,   238,
     239,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     7,     8,   245,   246,
     247,   248,     0,     0,     0,     0,   249,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   253,   254,   255,     0,     0,     0,     0,     0,     0,
       0,     0,   256,    25,     0,   257,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   594,   595,   596,   597,   731,
     599,   600,   601,   602,     0,     0,     0,     0,   603,     0,
       0,     0,   267,     0,  2079,     0,   268,     0,  2080,     0,
       0,   270,   271,   272,     0,   273,   274,   275,     0,     0,
       0,   119,     0,     0,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,   276,   426,     0,
      43,    44,    45,    46,   278,     0,    48,     0,     0,   369,
       0,     0,     0,   627,   773,    56,   281,     0,    59,   774,
       0,   775,   776,     0,   777,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    80,     0,     0,     0,     0,     0,   267,     0,
       0,     0,   268,     0,     0,     0,     0,   270,   271,   272,
       0,   273,   274,   275,     0,     0,     0,   119,    96,    97,
      98,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   645,   646,     0,     0,     0,     0,     0,
     278,     0,     0,     0,     0,   647,   210,   167,     0,   328,
       0,   889,   281,   211,   212,   213,     0,     0,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   425,   232,   233,   234,   235,
     236,   237,   238,   239,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2194,     0,     0,     0,     0,     0,     0,
       0,   245,   246,   247,   248,     0,     0,     0,     0,   249,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   253,   254,   255,     0,     0,     0,
       0,     0,   210,   167,     0,   256,    25,     0,   257,   211,
     212,   213,     0,     0,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   425,   232,   233,   234,   235,   236,   237,   238,   239,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     7,     8,   245,   246,   247,
     248,     0,     0,     0,     0,   249,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     253,   254,   255,     0,     0,     0,     0,     0,     0,     0,
       0,   256,    25,     0,   257,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   594,   595,   596,   597,   731,   599,
     600,   601,   602,     0,     0,     0,     0,   603,     0,     0,
       0,   267,     0,     0,     0,   268,     0,   792,     0,     0,
     270,   271,   272,     0,   273,   274,   275,     0,     0,     0,
     119,     0,     0,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,   276,   426,     0,    43,
      44,    45,    46,   278,     0,    48,     0,     0,   369,     0,
       0,     0,     0,   773,    56,   281,     0,    59,   774,     0,
     775,   776,     0,   777,     0,     0,     0,  1053,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    80,     0,     0,     0,  1054,     0,   267,     0,     0,
       0,   268,     0,     0,     0,     0,   270,   271,   272,     0,
     273,   274,   275,     0,     0,     0,   119,    96,    97,    98,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   276,   426,     0,     0,     0,     0,     0,   278,
     210,   167,     0,  1342,   369,  1107,     0,   211,   212,   213,
       0,   281,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   425,
     232,   233,   234,   235,   236,   237,   238,   239,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   245,   246,   247,   248,     0,
       0,     0,     0,   249,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   253,   254,
     255,     0,     0,     0,     0,     0,     0,     0,     0,   256,
      25,     0,   257,   210,   167,     0,  1505,     0,     0,     0,
     211,   212,   213,     0,     0,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   425,   232,   233,   234,   235,   236,   237,   238,
     239,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   245,   246,
     247,   248,     0,     0,     0,     0,   249,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   253,   254,   255,     0,     0,     0,     0,     0,     0,
       0,     0,   256,    25,     0,   257,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   594,   595,   596,   597,   731,
     599,   600,   601,   602,     0,   267,     0,     0,   603,   268,
       0,     0,     0,   953,   270,   271,   272,     0,   273,   274,
     275,     0,     0,     0,   119,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     276,   426,     0,     0,     0,     0,     0,   278,     0,     0,
       0,     0,   369,     0,     0,     0,     0,     0,     0,   281,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   594,
     595,   596,   597,   731,   599,   600,   601,   602,     0,     0,
       0,     0,   603,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   798,     0,     0,     0,     0,     0,   267,     0,
       0,     0,   268,     0,     0,     0,     0,   270,   271,   272,
       0,   273,   274,   275,     0,     0,     0,   119,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   276,   426,     0,     0,     0,     0,     0,
     278,   210,   167,     0,  1568,   369,     0,     0,   211,   212,
     213,     0,   281,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     425,   232,   233,   234,   235,   236,   237,   238,   239,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   245,   246,   247,   248,
       0,     0,     0,     0,   249,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   253,
     254,   255,     0,     0,     0,     0,     0,   210,   167,     0,
     256,    25,     0,   257,   211,   212,   213,     0,     0,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   425,   232,   233,   234,
     235,   236,   237,   238,   239,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       7,     8,   245,   246,   247,   248,     0,     0,     0,     0,
     249,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   253,   254,   255,     0,     0,
       0,     0,     0,     0,     0,     0,   256,    25,     0,   257,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   594,
     595,   596,   597,   731,   599,   600,   601,   602,     0,     0,
       0,     0,   603,     0,     0,     0,   267,     0,     0,     0,
     268,     0,   961,     0,     0,   270,   271,   272,     0,   273,
     274,   275,     0,     0,     0,   119,     0,     0,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,   276,   426,     0,    43,    44,    45,    46,   278,     0,
      48,     0,     0,   369,     0,     0,     0,     0,   773,    56,
     281,     0,    59,   774,     0,   775,   776,     0,   777,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    80,     0,     0,     0,
       0,     0,   267,     0,     0,     0,   268,     0,     0,     0,
       0,   270,   271,   272,     0,   273,   274,   275,     0,     0,
       0,   119,    96,    97,    98,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   276,   426,     0,
       0,     0,     0,     0,   278,   210,   167,     0,     0,   369,
    1622,     0,   211,   212,   213,     0,   281,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   425,   232,   233,   234,   235,   236,
     237,   238,   239,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     245,   246,   247,   248,     0,     0,     0,     0,   249,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   253,   254,   255,     0,     0,     0,     0,
       0,   210,   167,     0,   256,    25,     0,   257,   211,   212,
     213,     0,     0,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     425,   232,   233,   234,   235,   236,   237,   238,   239,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   245,   246,   247,   248,
       0,     0,     0,     0,   249,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   253,
     254,   255,     0,     0,     0,     0,     0,     0,     0,     0,
     256,    25,     0,   257,   585,   586,   587,   588,   589,   590,
     591,   592,   593,   594,   595,   596,   597,   731,   599,   600,
     601,   602,     0,     0,     0,     0,   603,     0,     0,     0,
     267,     0,     0,     0,   268,     0,   962,     0,     0,   270,
     271,   272,     0,   273,   274,   275,     0,     0,     0,   119,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   276,   426,     0,     0,     0,
       0,     0,   278,     0,     0,     0,     0,   369,  1958,     0,
       0,     0,     0,     0,   281,     0,     0,     0,     0,     0,
       0,     0,    -4,     1,     0,     0,    -4,     0,     0,     0,
       0,     0,     0,     0,     0,    -4,    -4,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   267,     0,     0,     0,
     268,     0,     0,     0,     0,   270,   271,   272,     0,   273,
     274,   275,     0,     0,     0,   119,     0,     0,    -4,    -4,
      -4,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   276,   426,     0,     0,     0,     0,     0,   278,    -4,
      -4,    -4,     0,   369,     0,     0,    -4,    -4,     0,     0,
     281,    -4,     0,     0,     0,     0,    -4,    -4,    -4,    -4,
      -4,     0,    -4,    -4,     0,    -4,     0,     0,     0,     0,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,     0,     0,    -4,    -4,
      -4,    -4,    -4,    -4,     0,    -4,     0,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,     0,     0,    -4,    -4,    -4,     0,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,     0,     0,     0,    -4,    -4,    -4,     0,     0,
       0,    -4,     0,     0,     0,     0,    -4,    -4,    -4,    -4,
       0,     0,    -4,     0,    -4,     0,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
       6,     0,     0,     0,     0,     0,    -4,    -4,    -4,     7,
       8,     0,     0,     0,     0,     0,     0,    -4,     0,    -4,
       0,     0,     0,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   596,   597,   731,   599,   600,   601,
     602,     0,     9,    10,    11,   603,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1010,     0,     0,     0,     0,
       0,     0,     0,    12,    13,    14,     0,     0,     0,     0,
      15,    16,     0,     0,     0,    17,     0,     0,     0,     0,
      18,    19,    20,    21,    22,     0,    23,    24,     0,    25,
       0,     0,     0,     0,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
       0,     0,    42,    43,    44,    45,    46,    47,     0,    48,
       0,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,     0,     0,    65,
      66,    67,     0,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,     0,     0,     0,    91,
      92,    93,     0,     0,     0,    94,     0,     0,     0,     0,
      95,    96,    97,    98,   167,   388,    99,     0,   100,     0,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,     0,     0,     0,     0,     0,     0,
     115,   116,   117,     0,     0,     0,     0,     0,     0,     0,
       0,   118,     0,   119,     0,     0,     0,     0,     0,   389,
     390,   391,   392,   393,   394,   395,   396,   397,     0,     0,
       0,     0,   398,   399,   400,   401,   419,   388,     0,     0,
     402,   403,   404,   405,     0,     0,     0,     0,   406,     0,
     407,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   408,     0,     0,   409,     0,     0,
       0,   304,     0,   388,   305,     0,     0,   306,     0,   307,
       0,   389,   390,   391,   392,   393,   394,   395,   396,   397,
      46,     0,     0,     0,   398,   399,   400,   401,     0,     0,
       0,     0,   402,   403,   404,   405,     0,     0,   439,     0,
     406,     0,   407,     0,     0,     0,     0,   389,   390,   391,
     392,   393,   394,   395,   396,   397,   408,     0,     0,   409,
     398,   399,   400,   401,     0,     0,     0,     0,   402,   403,
     404,   405,     0,     0,     0,     0,   406,     0,   407,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   408,     0,     0,   409,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   410,
     411,   412,     0,     0,     0,     0,     0,     0,     0,     0,
     413,     0,     0,     0,   414,     0,   415,   119,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   596,
     597,   731,   599,   600,   601,   602,     0,     0,     0,     0,
     603,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1118,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   410,   411,   412,     0,     0,     0,     0,     0,     0,
       0,     0,   413,     0,     0,     0,   414,     0,   415,   585,
     586,   587,   588,   589,   590,   591,   592,   593,   594,   595,
     596,   597,   731,   599,   600,   601,   602,   410,   411,   412,
       0,   603,     0,     0,     0,     0,     0,     0,   413,     0,
       0,  1119,   414,     0,   415,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   594,   595,   596,   597,   731,   599,
     600,   601,   602,     0,     0,     0,     0,   603,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1120,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   596,
     597,   731,   599,   600,   601,   602,     0,     0,     0,     0,
     603,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1121,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     594,   595,   596,   597,   731,   599,   600,   601,   602,     0,
       0,     0,     0,   603,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1159,   585,   586,   587,   588,   589,   590,
     591,   592,   593,   594,   595,   596,   597,   731,   599,   600,
     601,   602,     0,     0,     0,     0,   603,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1169,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   594,   595,   596,   597,
     731,   599,   600,   601,   602,     0,     0,     0,     0,   603,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1170,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   594,
     595,   596,   597,   731,   599,   600,   601,   602,     0,     0,
       0,     0,   603,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1171,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   596,   597,   731,   599,   600,   601,
     602,     0,     0,     0,     0,   603,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1172,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   594,   595,   596,   597,   731,
     599,   600,   601,   602,     0,     0,     0,     0,   603,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1173,   585,
     586,   587,   588,   589,   590,   591,   592,   593,   594,   595,
     596,   597,   731,   599,   600,   601,   602,     0,     0,     0,
       0,   603,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1178,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   596,   597,   731,   599,   600,   601,   602,
       0,     0,     0,     0,   603,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1179,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   594,   595,   596,   597,   731,   599,
     600,   601,   602,     0,     0,     0,     0,   603,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1181,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   596,
     597,   731,   599,   600,   601,   602,     0,     0,     0,     0,
     603,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1295,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     594,   595,   596,   597,   731,   599,   600,   601,   602,     0,
       0,     0,     0,   603,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1316,   585,   586,   587,   588,   589,   590,
     591,   592,   593,   594,   595,   596,   597,   731,   599,   600,
     601,   602,     0,     0,     0,     0,   603,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1401,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   594,   595,   596,   597,
     731,   599,   600,   601,   602,     0,     0,     0,     0,   603,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1404,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   594,
     595,   596,   597,   731,   599,   600,   601,   602,     0,     0,
       0,     0,   603,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1499,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   596,   597,   731,   599,   600,   601,
     602,     0,     0,     0,     0,   603,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1500,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   594,   595,   596,   597,   731,
     599,   600,   601,   602,     0,     0,     0,     0,   603,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1545,   585,
     586,   587,   588,   589,   590,   591,   592,   593,   594,   595,
     596,   597,   731,   599,   600,   601,   602,     0,     0,     0,
       0,   603,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1673,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   596,   597,   731,   599,   600,   601,   602,
       0,     0,     0,     0,   603,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1674,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   594,   595,   596,   597,   731,   599,
     600,   601,   602,     0,     0,     0,     0,   603,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1675,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   596,
     597,   731,   599,   600,   601,   602,     0,     0,     0,     0,
     603,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1821,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     594,   595,   596,   597,   731,   599,   600,   601,   602,     0,
       0,     0,     0,   603,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1945,   585,   586,   587,   588,   589,   590,
     591,   592,   593,   594,   595,   596,   597,   731,   599,   600,
     601,   602,     0,     0,     0,     0,   603,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1946,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   594,   595,   596,   597,
     731,   599,   600,   601,   602,     0,     0,     0,     0,   603,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1978,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   594,
     595,   596,   597,   731,   599,   600,   601,   602,     0,     0,
       0,     0,   603,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2049,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   596,   597,   731,   599,   600,   601,
     602,     0,     0,     0,     0,   603,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2105,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   594,   595,   596,   597,   731,
     599,   600,   601,   602,     0,     0,     0,     0,   603,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2106,   585,
     586,   587,   588,   589,   590,   591,   592,   593,   594,   595,
     596,   597,   731,   599,   600,   601,   602,     0,     0,     0,
       0,   603,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2121,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   596,   597,   731,   599,   600,   601,   602,
       0,     0,     0,     0,   603,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2155,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   594,   595,   596,   597,   731,   599,
     600,   601,   602,     0,     0,     0,     0,   603,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2182,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   596,
     597,   731,   599,   600,   601,   602,     0,     0,     0,     0,
     603,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2187,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     594,   595,   596,   597,   731,   599,   600,   601,   602,     0,
       0,     0,     0,   603,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2188,   585,   586,   587,   588,   589,   590,
     591,   592,   593,   594,   595,   596,   597,   731,   599,   600,
     601,   602,     0,     0,     0,     0,   603,     0,     0,     0,
       0,     0,  1088,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   596,   597,   731,   599,   600,   601,
     602,     0,     0,     0,     0,   603,     0,     0,     0,     0,
       0,  1146,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   596,   597,   731,   599,   600,   601,   602,
       0,     0,     0,     0,   603,     0,     0,     0,     0,     0,
    1193,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     594,   595,   596,   597,   731,   599,   600,   601,   602,     0,
       0,     0,     0,   603,     0,     0,     0,     0,     0,  1194,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   594,
     595,   596,   597,   731,   599,   600,   601,   602,     0,     0,
       0,     0,   603,     0,     0,     0,     0,     0,  1238,   585,
     586,   587,   588,   589,   590,   591,   592,   593,   594,   595,
     596,   597,   731,   599,   600,   601,   602,     0,     0,     0,
       0,   603,     0,     0,     0,     0,     0,  1270,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   596,
     597,   731,   599,   600,   601,   602,     0,     0,     0,     0,
     603,     0,     0,     0,     0,     0,  1290,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   594,   595,   596,   597,
     731,   599,   600,   601,   602,     0,     0,     0,     0,   603,
       0,     0,     0,     0,     0,  1348,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   594,   595,   596,   597,   731,
     599,   600,   601,   602,     0,     0,     0,     0,   603,     0,
       0,     0,     0,     0,  1368,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   594,   595,   596,   597,   731,   599,
     600,   601,   602,     0,     0,     0,     0,   603,     0,     0,
       0,     0,     0,  1454,   585,   586,   587,   588,   589,   590,
     591,   592,   593,   594,   595,   596,   597,   731,   599,   600,
     601,   602,     0,     0,     0,     0,   603,     0,     0,     0,
       0,     0,  1455,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   596,   597,   731,   599,   600,   601,
     602,     0,     0,     0,     0,   603,     0,     0,     0,     0,
       0,  1501,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   596,   597,   731,   599,   600,   601,   602,
       0,     0,     0,     0,   603,     0,     0,     0,     0,     0,
    1574,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     594,   595,   596,   597,   731,   599,   600,   601,   602,     0,
       0,     0,     0,   603,     0,     0,     0,     0,     0,  1875,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   594,
     595,   596,   597,   731,   599,   600,   601,   602,     0,     0,
       0,     0,   603,     0,     0,     0,     0,     0,  1886,   585,
     586,   587,   588,   589,   590,   591,   592,   593,   594,   595,
     596,   597,   731,   599,   600,   601,   602,     0,     0,     0,
       0,   603,     0,     0,     0,     0,     0,  1925,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   596,
     597,   731,   599,   600,   601,   602,     0,     0,     0,     0,
     603,     0,     0,     0,     0,     0,  1999,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   594,   595,   596,   597,
     731,   599,   600,   601,   602,     0,     0,     0,     0,   603,
       0,     0,     0,     0,     0,  2014,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   594,   595,   596,   597,   731,
     599,   600,   601,   602,     0,     0,     0,     0,   603,     0,
       0,     0,     0,     0,  2026,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   594,   595,   596,   597,   731,   599,
     600,   601,   602,     0,     0,     0,     0,   603,     0,     0,
       0,     0,     0,  2050,   585,   586,   587,   588,   589,   590,
     591,   592,   593,   594,   595,   596,   597,   731,   599,   600,
     601,   602,     0,     0,     0,     0,   603,     0,     0,     0,
       0,     0,  2085,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   596,   597,   731,   599,   600,   601,
     602,     0,     0,     0,     0,   603,     0,     0,     0,     0,
       0,  2094,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   596,   597,   731,   599,   600,   601,   602,
       0,     0,     0,     0,   603,     0,     0,     0,     0,     0,
    2095,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     594,   595,   596,   597,   731,   599,   600,   601,   602,     0,
       0,     0,     0,   603,     0,     0,     0,     0,     0,  2119,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   594,
     595,   596,   597,   731,   599,   600,   601,   602,     0,     0,
       0,     0,   603,     0,     0,     0,     0,     0,  2168,   585,
     586,   587,   588,   589,   590,   591,   592,   593,   594,   595,
     596,   597,   731,   599,   600,   601,   602,     0,     0,     0,
       0,   603,     0,     0,     0,     0,     0,  2207,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   596,
     597,   731,   599,   600,   601,   602,     0,     0,     0,     0,
     603,     0,     0,     0,     0,     0,  2225,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   594,   595,   596,   597,
     731,   599,   600,   601,   602,     0,     0,     0,     0,   603,
       0,     0,     0,     0,     0,  2243,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   594,   595,   596,   597,   731,
     599,   600,   601,   602,     0,     0,     0,     0,   603,     0,
       0,     0,     0,     0,  2244,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   594,   595,   596,   597,   731,   599,
     600,   601,   602,     0,     0,     0,     0,   603,     0,     0,
       0,     0,  1992,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   596,   597,   731,   599,   600,   601,
     602,     0,     0,     0,     0,   603,     0,   759,     0,   760,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   594,
     595,   596,   597,   731,   599,   600,   601,   602,     0,     0,
       0,     0,   603,     0,     0,     0,  1016,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   594,   595,   596,   597,
     731,   599,   600,   601,   602,     0,     0,     0,     0,   603,
       0,     0,     0,  1064,   585,   586,   587,   588,   589,   590,
     591,   592,   593,   594,   595,   596,   597,   731,   599,   600,
     601,   602,     0,     0,     0,     0,   603,     0,     0,     0,
    1217,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     594,   595,   596,   597,   731,   599,   600,   601,   602,     0,
       0,     0,     0,   603,     0,     0,     0,  1284,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   596,
     597,   731,   599,   600,   601,   602,     0,     0,     0,     0,
     603,     0,     0,     0,  1286,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   594,   595,   596,   597,   731,   599,
     600,   601,   602,     0,     0,     0,     0,   603,     0,     0,
       0,  1293,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   596,   597,   731,   599,   600,   601,   602,
       0,     0,     0,     0,   603,     0,     0,     0,  1294,   585,
     586,   587,   588,   589,   590,   591,   592,   593,   594,   595,
     596,   597,   731,   599,   600,   601,   602,     0,     0,     0,
       0,   603,     0,     0,     0,  1383,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   594,   595,   596,   597,   731,
     599,   600,   601,   602,     0,     0,     0,     0,   603,     0,
       0,     0,  1397,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   596,   597,   731,   599,   600,   601,
     602,     0,     0,     0,     0,   603,     0,     0,     0,  1603,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   594,
     595,   596,   597,   731,   599,   600,   601,   602,     0,     0,
       0,     0,   603,     0,     0,     0,  1694,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   594,   595,   596,   597,
     731,   599,   600,   601,   602,     0,     0,     0,     0,   603,
       0,     0,     0,  1747,   585,   586,   587,   588,   589,   590,
     591,   592,   593,   594,   595,   596,   597,   731,   599,   600,
     601,   602,     0,     0,     0,     0,   603,     0,     0,     0,
    1937,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     594,   595,   596,   597,   731,   599,   600,   601,   602,     0,
       0,     0,     0,   603,     0,     0,     0,  1982,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   596,
     597,   731,   599,   600,   601,   602,     0,     0,     0,     0,
     603,     0,     0,     0,  2000,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   594,   595,   596,   597,   731,   599,
     600,   601,   602,     0,     0,     0,     0,   603,     0,   814,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   594,
     595,   596,   597,   731,   599,   600,   601,   602,     0,     0,
       0,     0,   603,     0,   815,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   594,   595,   596,   597,   731,   599,
     600,   601,   602,     0,     0,     0,     0,   603,     0,   816,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   594,
     595,   596,   597,   731,   599,   600,   601,   602,     0,     0,
       0,     0,   603,     0,   818,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   594,   595,   596,   597,   731,   599,
     600,   601,   602,     0,     0,     0,     0,   603,     0,   819,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   594,
     595,   596,   597,   731,   599,   600,   601,   602,     0,     0,
       0,     0,   603,     0,   820,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   594,   595,   596,   597,   731,   599,
     600,   601,   602,     0,     0,     0,     0,   603,     0,   822,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   594,
     595,   596,   597,   731,   599,   600,   601,   602,     0,     0,
       0,     0,   603,     0,   823,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   594,   595,   596,   597,   731,   599,
     600,   601,   602,     0,     0,     0,     0,   603,     0,   824,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   594,
     595,   596,   597,   731,   599,   600,   601,   602,     0,     0,
       0,     0,   603,     0,   825,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   594,   595,   596,   597,   731,   599,
     600,   601,   602,     0,     0,     0,     0,   603,     0,   826,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   594,
     595,   596,   597,   731,   599,   600,   601,   602,     0,     0,
       0,     0,   603,     0,   827,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   594,   595,   596,   597,   731,   599,
     600,   601,   602,     0,     0,     0,     0,   603,     0,   828,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   594,
     595,   596,   597,   731,   599,   600,   601,   602,     0,     0,
       0,     0,   603,     0,   830,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   594,   595,   596,   597,   731,   599,
     600,   601,   602,     0,     0,     0,     0,   603,     0,   831,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   594,
     595,   596,   597,   731,   599,   600,   601,   602,     0,     0,
       0,     0,   603,     0,   832,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   594,   595,   596,   597,   731,   599,
     600,   601,   602,     0,     0,     0,     0,   603,     0,   901,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   594,
     595,   596,   597,   731,   599,   600,   601,   602,     0,     0,
       0,     0,   603,     0,   935,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   594,   595,   596,   597,   731,   599,
     600,   601,   602,     0,     0,     0,     0,   603,     0,   983,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   594,
     595,   596,   597,   731,   599,   600,   601,   602,     0,     0,
       0,     0,   603,     0,  1004,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   594,   595,   596,   597,   731,   599,
     600,   601,   602,     0,     0,     0,     0,   603,     0,  1006,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   594,
     595,   596,   597,   731,   599,   600,   601,   602,     0,     0,
       0,     0,   603,     0,  1007,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   594,   595,   596,   597,   731,   599,
     600,   601,   602,     0,     0,     0,     0,   603,     0,  1008,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   594,
     595,   596,   597,   731,   599,   600,   601,   602,     0,     0,
       0,     0,   603,     0,  1014,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   594,   595,   596,   597,   731,   599,
     600,   601,   602,     0,     0,     0,     0,   603,     0,  1015,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   594,
     595,   596,   597,   731,   599,   600,   601,   602,     0,     0,
       0,     0,   603,     0,  1052,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   594,   595,   596,   597,   731,   599,
     600,   601,   602,     0,     0,     0,     0,   603,     0,  1063,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   594,
     595,   596,   597,   731,   599,   600,   601,   602,     0,     0,
       0,     0,   603,     0,  1126,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   594,   595,   596,   597,   731,   599,
     600,   601,   602,     0,     0,     0,     0,   603,     0,  1130,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   594,
     595,   596,   597,   731,   599,   600,   601,   602,     0,     0,
       0,     0,   603,     0,  1142,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   594,   595,   596,   597,   731,   599,
     600,   601,   602,     0,     0,     0,     0,   603,     0,  1216,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   594,
     595,   596,   597,   731,   599,   600,   601,   602,     0,     0,
       0,     0,   603,     0,  1226,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   594,   595,   596,   597,   731,   599,
     600,   601,   602,     0,     0,     0,     0,   603,     0,  1227,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   594,
     595,   596,   597,   731,   599,   600,   601,   602,     0,     0,
       0,     0,   603,     0,  1228,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   594,   595,   596,   597,   731,   599,
     600,   601,   602,     0,     0,     0,     0,   603,     0,  1237,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   594,
     595,   596,   597,   731,   599,   600,   601,   602,     0,     0,
       0,     0,   603,     0,  1239,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   594,   595,   596,   597,   731,   599,
     600,   601,   602,     0,     0,     0,     0,   603,     0,  1240,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   594,
     595,   596,   597,   731,   599,   600,   601,   602,     0,     0,
       0,     0,   603,     0,  1269,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   594,   595,   596,   597,   731,   599,
     600,   601,   602,     0,     0,     0,     0,   603,     0,  1271,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   594,
     595,   596,   597,   731,   599,   600,   601,   602,     0,     0,
       0,     0,   603,     0,  1272,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   594,   595,   596,   597,   731,   599,
     600,   601,   602,     0,     0,     0,     0,   603,     0,  1273,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   594,
     595,   596,   597,   731,   599,   600,   601,   602,     0,     0,
       0,     0,   603,     0,  1274,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   594,   595,   596,   597,   731,   599,
     600,   601,   602,     0,     0,     0,     0,   603,     0,  1275,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   594,
     595,   596,   597,   731,   599,   600,   601,   602,     0,     0,
       0,     0,   603,     0,  1276,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   594,   595,   596,   597,   731,   599,
     600,   601,   602,     0,     0,     0,     0,   603,     0,  1277,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   594,
     595,   596,   597,   731,   599,   600,   601,   602,     0,     0,
       0,     0,   603,     0,  1283,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   594,   595,   596,   597,   731,   599,
     600,   601,   602,     0,     0,     0,     0,   603,     0,  1382,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   594,
     595,   596,   597,   731,   599,   600,   601,   602,     0,     0,
       0,     0,   603,     0,  1396,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   594,   595,   596,   597,   731,   599,
     600,   601,   602,     0,     0,     0,     0,   603,     0,  1604,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   594,
     595,   596,   597,   731,   599,   600,   601,   602,     0,     0,
       0,     0,   603,     0,  1638,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   594,   595,   596,   597,   731,   599,
     600,   601,   602,     0,     0,     0,     0,   603,     0,  1639,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   594,
     595,   596,   597,   731,   599,   600,   601,   602,     0,     0,
       0,     0,   603,     0,  1640,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   594,   595,   596,   597,   731,   599,
     600,   601,   602,     0,     0,     0,     0,   603,     0,  1641,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   594,
     595,   596,   597,   731,   599,   600,   601,   602,     0,     0,
       0,     0,   603,     0,  1681,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   594,   595,   596,   597,   731,   599,
     600,   601,   602,     0,     0,     0,     0,   603,     0,  1693,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   594,
     595,   596,   597,   731,   599,   600,   601,   602,     0,     0,
       0,     0,   603,     0,  1808,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   594,   595,   596,   597,   731,   599,
     600,   601,   602,     0,     0,     0,     0,   603,     0,  1810,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   594,
     595,   596,   597,   731,   599,   600,   601,   602,     0,     0,
       0,     0,   603,     0,  1813,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   594,   595,   596,   597,   731,   599,
     600,   601,   602,     0,     0,     0,     0,   603,     0,  1820,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   594,
     595,   596,   597,   731,   599,   600,   601,   602,     0,     0,
       0,     0,   603,     0,  1876,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   594,   595,   596,   597,   731,   599,
     600,   601,   602,     0,     0,     0,     0,   603,     0,  1885,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   594,
     595,   596,   597,   731,   599,   600,   601,   602,     0,     0,
       0,     0,   603,     0,  1910,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   594,   595,   596,   597,   731,   599,
     600,   601,   602,     0,     0,     0,     0,   603,     0,  1981,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   594,
     595,   596,   597,   731,   599,   600,   601,   602,     0,     0,
       0,     0,   603,     0,  2047,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   594,   595,   596,   597,   731,   599,
     600,   601,   602,     0,     0,     0,     0,   603,     0,  2048,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   594,
     595,   596,   597,   731,   599,   600,   601,   602,     0,     0,
       0,     0,   603,     0,  2181,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   594,   595,   596,   597,   731,   599,
     600,   601,   602,     0,     0,     0,     0,   603,     0,  2222,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   594,
     595,   596,   597,   731,   599,   600,   601,   602,     0,     0,
       0,     0,   603
};

static const yytype_int16 yycheck[] =
{
       3,   159,     3,  1264,  1268,    63,   333,  1461,   145,  1732,
     642,   643,  1776,   321,  1778,   198,     4,     4,     4,     4,
       4,   110,    25,   112,   207,   352,     4,     4,   756,     5,
       5,   142,    25,  1961,   762,     4,     7,   107,     5,     4,
     107,     7,     6,   449,     4,   256,  1763,     5,     0,     6,
       6,   101,    55,   264,     4,     6,   145,     4,     6,   258,
       4,   131,     4,     6,   131,   264,     4,     9,   243,   244,
     120,   107,   104,     4,     7,   107,   108,   109,   255,     6,
     257,    84,   193,   172,     4,     9,     6,   163,   120,   264,
     255,    94,    36,    37,   142,   422,    99,   424,    36,    37,
       4,     6,     9,     4,   255,   432,   257,   110,    14,     9,
       9,  1828,   160,   264,   190,   258,    93,     9,   301,   302,
     303,   264,   170,   171,   172,  1848,     9,   255,   176,   177,
     206,   207,    36,    37,   104,    36,    37,   107,     6,   109,
     243,   244,   145,   243,   244,   146,   255,   150,   151,   152,
       6,    69,    70,   185,    72,   255,   159,   243,   244,   259,
       6,   264,   345,   346,   347,     7,   110,   111,   243,   244,
     243,   244,   110,   111,   177,     7,     6,     7,   264,   362,
       7,   101,   147,   148,   149,   150,  2114,   256,   153,   264,
     193,   264,   261,   251,   252,   198,   107,   162,   109,   202,
     165,   607,   248,   249,   207,   208,   209,     6,   254,   110,
     111,   180,   181,   182,   183,   243,   244,     7,   243,   244,
     255,     7,   257,   192,   201,   194,   195,   196,   197,   198,
     178,   259,  1686,   202,   203,   178,   205,   243,   244,   264,
     227,   227,   261,   227,   263,   205,   190,   191,   101,   227,
     227,   104,   190,   191,   107,   255,  1517,   257,   264,   259,
     263,     6,   228,   229,   230,   231,  1989,   120,     6,   257,
     255,   259,   259,     6,   277,   263,   262,   280,   281,   243,
     244,   259,   259,   259,   259,   227,   252,   253,   281,     6,
     261,   260,   259,   296,   297,   261,   227,   300,   301,   302,
     303,   259,   259,   259,   631,   255,   633,   634,   255,     3,
     252,   253,   315,   255,   255,   257,   319,   259,   321,   261,
    2043,   256,   255,   650,   257,   256,   256,   258,   255,   264,
     736,   255,   259,   257,   264,  1063,  1064,   261,   243,   244,
     343,   668,   345,   346,   347,   252,   253,   259,   255,   438,
     257,   258,   252,   253,   261,   255,   255,   257,   257,   362,
       6,   261,   261,   255,   770,   257,   693,   370,    62,   252,
     253,     4,   255,   259,   257,   243,   244,   263,   261,     6,
     563,   787,   238,   239,   257,  2149,   228,   229,   230,   231,
     257,   797,   238,   239,   142,   553,   228,   229,   230,   231,
       6,   228,   229,   230,   231,   732,   324,   325,   243,   244,
     252,   253,   160,   260,   332,   333,     4,   264,   243,   244,
     252,   253,   170,   171,   172,   260,   429,   430,   176,   177,
     255,   434,   435,   256,   259,   258,   243,   244,   228,   229,
     230,   231,   228,   229,   230,   231,   255,   450,    36,    37,
     259,   145,   259,   255,   457,   142,   150,   151,   152,   255,
     255,  2184,   252,   253,   259,   159,   243,   244,   101,   107,
     243,   244,   105,   160,   255,   142,   257,   480,   111,   112,
     569,   114,   115,   170,   171,   172,   256,   264,   258,   176,
     177,   264,   104,   160,   264,   107,   255,   903,   142,   193,
     243,   244,   135,   170,   171,   172,   509,   259,   120,   176,
     177,  2234,   260,   243,   244,   209,   160,   243,   244,   255,
       4,   264,   110,   111,   255,  1979,   170,   171,   172,   122,
     533,   260,   176,   177,   264,   264,   243,   244,   264,   542,
     543,   260,   255,   701,   547,   264,   549,   550,   551,   552,
     553,   255,    36,    37,   260,   558,   250,   264,   264,   562,
     563,   564,   565,   566,   567,   568,   256,   570,   258,   572,
     255,   265,   266,   260,   264,   568,   260,   570,   243,   244,
     264,    55,   243,   244,   243,   244,   243,   244,   243,   244,
     243,   244,   256,   260,   258,   598,   243,   244,   256,   264,
     264,   604,   256,   264,   258,   264,   264,   264,   259,   264,
     264,   264,   243,   244,   243,   244,   260,   264,   255,   756,
     257,   243,   244,   626,   627,   714,   110,   111,   101,   104,
     957,   104,   107,   264,   107,   264,   109,   259,   252,   253,
     104,   642,   643,   107,   260,   109,  1278,   120,   264,   243,
     244,   245,   246,   247,   248,   249,   120,   252,   253,  1065,
     254,   245,   246,   247,   248,   249,   261,   256,   255,   258,
     254,   674,   675,   676,   255,   264,   679,   680,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   256,   255,   258,   259,   254,   699,   700,   701,   702,
     703,   704,   705,   706,   707,   255,   709,   710,   711,   712,
     713,   255,   715,   716,   717,   718,   719,   255,   776,   722,
     256,   256,   640,   641,   813,   718,   255,   645,   264,   264,
     733,   255,     6,   257,   208,   429,   101,   261,   256,   104,
     264,   256,   107,   746,   109,   439,   264,   256,   260,   264,
     252,   253,   264,   243,   244,   264,   260,   259,   761,  1487,
     264,     4,     6,     6,   767,   252,   253,   461,   255,   109,
     257,   260,   259,   147,   148,   264,   147,   148,   259,   153,
     783,   784,   153,   260,   255,   255,   789,   264,   791,   263,
     259,   794,   795,   260,  1200,   932,  1202,   264,   801,   260,
     803,   252,   253,   264,   255,   261,   257,   107,   264,  1215,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   300,   255,   104,   259,
     254,   252,   253,   836,   255,   838,   257,   259,  1244,   255,
     260,   315,   260,   260,   264,   319,   264,   264,   260,   107,
     260,  1579,   264,   547,   264,   549,   945,   551,   552,   553,
     260,  1589,   260,   260,   264,   260,   264,   264,   259,   264,
     873,   565,   566,   260,  2138,   260,   104,   264,   104,   264,
     883,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   107,   260,  1304,  1305,
     254,   264,   905,   260,   260,   107,   107,   264,   264,  2170,
     260,   260,  1049,   255,   264,   264,   260,     8,   921,     4,
     264,   260,     4,  1329,   260,   264,  1063,  1064,   264,  1335,
     933,  2195,   260,   260,   260,     4,   264,   264,   264,   942,
     260,   260,   260,  1080,   264,   264,   264,     4,  1354,   260,
     953,  2212,   260,   264,   648,   260,   264,   255,     6,   264,
     434,   435,     8,   260,   260,   260,   260,   264,   264,   264,
     264,   256,   255,   258,   259,  1381,   450,   671,  1067,   260,
     260,   260,   260,   264,   264,   264,   264,   260,   260,  1395,
     260,   264,   264,   260,   264,   260,  1402,   264,   260,   264,
     260,   255,   264,   255,   264,   699,   700,   701,   702,   703,
     704,   705,   706,   707,     6,   709,   710,   711,   712,   257,
     260,   715,   716,   717,   264,   260,   260,   257,   260,   264,
     264,   725,   264,   255,   728,   259,     6,     6,   263,   259,
     263,   255,   960,     9,   259,   255,   740,   255,   255,   967,
    1358,   255,   255,   971,   193,  1058,   255,   255,   255,   255,
     193,   193,   255,  1066,   259,   131,   255,   255,   255,   193,
     255,  1074,   255,   259,   255,   259,   550,   255,     4,  1216,
    1217,   775,   259,   777,  1087,  1717,  1718,   259,   562,  1092,
     564,   259,   259,   255,   255,   255,   255,   255,   255,   255,
     794,   255,     6,     6,   257,     6,     6,   259,   259,   803,
     259,   259,   259,   259,   257,   257,   257,     6,   193,   259,
     255,  1124,  1125,   257,  1127,  1128,  1129,   255,  1131,  1132,
    1133,  1134,  1135,  1136,  1137,  1138,  1139,  1140,   255,   255,
    1143,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   255,
     255,     6,     6,   254,     6,   259,     6,     8,     7,   260,
       8,   259,     6,   259,     6,   259,   259,    96,   256,   260,
    1183,  1184,  1185,     7,   264,   264,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,  1207,  1123,     6,     6,   254,   256,
     259,   261,    67,   254,   260,   259,   259,   259,     8,     8,
    1223,  1224,  1225,     7,     7,   255,     6,   256,     6,   260,
       7,   259,     6,   190,     7,     6,     6,   259,   258,   260,
    1567,   260,   256,     6,  1571,  1382,  1383,   259,   261,     7,
       6,   257,   255,     6,   259,     6,     6,     6,     6,   256,
       7,   257,   956,     7,   958,   959,     7,     7,     7,     7,
       7,     7,   746,     7,  1582,     7,  1279,  1278,   972,     7,
       7,     7,     7,     7,     7,   259,     6,   258,   256,   264,
       7,   264,   264,  1296,  1297,  1298,   260,   991,   256,   264,
     260,     7,   261,   259,  1307,   259,     4,     6,   261,  1312,
     260,   260,   142,  1316,   259,     7,  1405,  1011,  1407,     6,
     261,     7,  1325,     7,  1327,     7,   256,  1330,   256,   264,
     264,     9,     8,   264,   256,   258,   261,   193,     7,   263,
     163,   259,  1345,   260,     6,     6,     6,    49,    49,   261,
     255,   259,   259,  1047,     7,  1358,   255,   255,     7,   261,
     255,     7,   193,  1995,   261,   256,     7,     7,   264,     7,
       6,   256,   264,     7,     7,     7,  1782,     7,     7,     4,
    1383,   259,     6,   255,   119,  1388,     7,  1390,     6,   259,
       7,     7,     7,     7,     7,     7,     7,     6,  1092,     6,
       6,     6,   107,     7,  1407,     7,     7,     6,     4,   262,
     264,   259,   264,   256,   260,     6,     6,   264,     7,  1422,
       6,   257,   259,  1426,   259,     6,     6,   255,   255,     6,
     259,   905,  1590,  1591,   260,     6,   261,     6,     6,   258,
       6,     6,  1579,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   135,     6,     6,     6,   254,     6,   256,   942,   258,
       6,     6,     6,     6,  1563,     6,     6,     6,  1481,  1482,
    1483,     6,  1790,     5,   256,     6,  1489,  1490,  1491,   256,
    1184,  1185,     6,     4,     6,   259,     6,   259,     7,     7,
     259,     6,   259,     6,  1507,   259,     6,   259,     6,     6,
     189,   257,     6,     6,   259,  1518,   259,   259,     7,     6,
       6,     6,     6,  1526,     4,     7,   259,  1530,   259,     6,
     260,     6,   261,     6,     6,  1624,     6,   259,   256,     6,
       6,   105,   255,   264,   259,   264,   255,   259,   264,   260,
     264,   255,  1246,     6,   142,  1692,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,     5,   256,   259,     6,   254,  1582,
     256,     6,   259,   142,  1058,   142,   259,  1590,  1591,   264,
       6,     6,   264,  1596,     6,     6,   264,   256,  1516,   264,
    1074,     6,     6,     6,   259,   259,   264,     6,     6,     6,
       6,  1614,     6,     6,   259,     7,   259,   259,  1312,   146,
     259,  1624,  1316,     5,  1713,   256,  1629,     6,     6,     6,
       6,  1325,   259,  1327,   260,  1793,  1330,   259,     7,     6,
     260,   188,     6,   191,     7,  1339,     6,     6,   256,   259,
    1124,  1125,     6,  1127,  1128,  1129,     6,  1131,  1132,  1133,
    1134,  1135,  1136,  1137,  1138,  1139,  1140,  1756,   260,     6,
       6,     6,     6,   260,  1763,  1764,   260,  2004,   261,     6,
     259,   256,   260,   259,     6,     6,   259,     6,   260,  1383,
     260,     6,   255,     4,     5,  1784,   256,   259,   259,     6,
       6,  1704,   260,   259,   259,   142,  1709,  1710,   259,  1183,
       6,     6,     6,   259,     6,   256,  1717,  1718,     6,     6,
       6,   260,  2030,   260,     6,     6,  1644,     6,     6,  1732,
       6,     6,     6,  1207,     6,  1738,   259,     6,    49,    50,
      51,    52,    53,    54,    55,    56,    57,  1750,     6,  1223,
       6,    62,    63,    64,    65,  1758,     6,   259,  1761,    70,
      71,    72,    73,   259,     6,     6,  1394,    78,  2151,    80,
     477,  1636,  2099,  1456,  1962,  1922,  1779,  1700,  1421,     3,
    1783,     3,     3,    94,  1076,     3,    97,  1790,  1991,  1792,
    1793,  1560,     3,  1783,  1591,  1763,   794,   619,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1279,    -1,    -1,    -1,    -1,
      -1,    -1,  2139,    -1,    -1,  1733,  1734,  1735,  1736,  1737,
    1738,    -1,  1296,  1297,  1298,  1828,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1924,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1848,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1859,  1860,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1345,    -1,    -1,    -1,     6,    -1,    -1,  1967,    -1,
      -1,  1884,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1896,    -1,    -1,  1590,  1591,   209,   210,
     211,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1911,   220,
      -1,    -1,    -1,   224,    -1,   226,   227,    -1,    -1,    -1,
    1614,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     6,  1407,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1948,    -1,    -1,  1422,    -1,
      -1,    -1,  1426,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1963,    -1,    -1,    -1,    -1,  1968,    -1,    -1,  1971,  1972,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1989,    -1,    -1,  1992,
      -1,    -1,    -1,    -1,  1995,    -1,    -1,    -1,    -1,    -1,
    2003,    -1,    -1,    -1,  2007,    -1,    -1,  1481,  1482,  1483,
      -1,    -1,    -1,    -1,    -1,  1489,  1490,  1491,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2115,  2030,    -1,    -1,
      -1,    -1,    -1,  1507,    -1,    -1,    -1,    -1,    -1,    -1,
    2043,    -1,    -1,    -1,  1518,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1526,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1758,    -1,    -1,  1761,    -1,  2072,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1776,    -1,  1778,    -1,    -1,    -1,    -1,    -1,
    2008,  2009,  2010,  2011,  2012,    -1,    -1,    -1,    -1,  1793,
      -1,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,    -1,
    2123,    -1,  1596,   254,    -1,     6,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1828,    -1,    -1,    -1,  2141,  2142,
    2143,  2144,  2145,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1624,    -1,    -1,  2071,    -1,    -1,    -1,  2075,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,    -1,    -1,    -1,    -1,
     254,  2184,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     4,     5,  2200,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2125,    -1,    -1,
      -1,  2129,    -1,    -1,    -1,    -1,    -1,    -1,  2221,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2145,    -1,    -1,
    1704,  2234,    -1,    -1,    -1,    -1,    -1,  2240,  2241,    -1,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    -1,
    2253,    -1,    -1,    62,    63,    64,    65,    -1,  1732,    -1,
      -1,    70,    71,    72,    73,    -1,   118,    -1,    -1,    78,
      -1,    80,  2190,  2191,    -1,    -1,  1750,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    94,    -1,    -1,    97,    -1,
      -1,    -1,   101,   145,    -1,   104,    -1,   149,   107,    -1,
     109,    -1,   154,    -1,    -1,  1779,    -1,    -1,    -1,    -1,
     162,   120,    -1,    -1,    -1,    -1,    -1,    -1,  1792,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   178,   179,   180,   138,
     182,   183,   184,    -1,   186,   187,   188,   189,   190,   191,
     192,    -1,   194,   195,   196,   197,    -1,    -1,    -1,    -1,
     202,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,    -1,
      -1,    -1,    -1,   254,  1848,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     6,    -1,    -1,    -1,
    2084,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     209,   210,   211,    -1,    -1,    -1,    -1,   142,    -1,    -1,
    1884,   220,    -1,    -1,    -1,   224,    -1,   226,   227,    -1,
      -1,    -1,    -1,    -1,   276,   277,   278,   279,   280,    -1,
     145,    -1,    -1,    -1,    -1,   150,   151,   152,    -1,    -1,
      -1,    -1,    -1,   295,   296,   297,    -1,   256,    -1,   258,
     259,    -1,    -1,    -1,    -1,  2149,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   317,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1948,   327,   328,  2171,   193,    -1,
      -1,   333,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1963,
      -1,   343,   344,    -1,   209,    -1,    -1,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,  1989,    -1,   369,   370,   254,
      -1,    -1,   374,   375,   376,    -1,   378,  2221,    -1,  2003,
     382,   383,   384,    -1,    -1,   387,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2240,  2241,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2253,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2043,
      -1,    -1,    -1,    -1,   426,    -1,    -1,    -1,   430,   431,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   447,   448,    -1,  2072,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     462,    -1,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     482,   483,   484,   485,   254,    -1,    -1,    -1,   490,    -1,
      -1,    -1,   494,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   508,   509,    -1,    -1,
      -1,   513,    -1,    -1,    -1,   517,   518,   519,   520,   521,
     522,   523,   524,   525,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   541,
     542,   543,    -1,   545,   546,    -1,   548,   202,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   557,    -1,    -1,   560,   561,
    2184,    -1,    -1,    -1,   429,   567,    -1,    -1,    -1,    -1,
     572,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     6,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   596,   597,   598,   599,   600,   601,
     602,   603,    -1,   605,   606,    -1,    -1,    -1,    -1,    -1,
    2234,   613,   614,   615,    -1,    -1,    -1,    -1,    -1,   621,
     622,   623,   624,    -1,   626,   627,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   296,   297,   645,   646,   647,    -1,    -1,    -1,   651,
     652,   653,   654,   655,   656,   657,   658,   659,     6,    -1,
      -1,    -1,    -1,   665,    -1,   667,    -1,    -1,   670,    -1,
      -1,    -1,   674,   675,   676,   677,    -1,   679,   680,   681,
     682,   683,   547,    -1,   549,    -1,   551,   552,   343,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     565,   566,    -1,    -1,    -1,    -1,   708,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     722,    -1,    -1,    -1,    -1,    -1,    -1,   729,    -1,   731,
      -1,    -1,   734,   735,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   743,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   761,
      -1,   763,    -1,    -1,    -1,    -1,   768,   769,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   430,    -1,    -1,    -1,    -1,
      -1,   783,    -1,   785,   786,    -1,    -1,   789,    -1,   791,
     792,    -1,    -1,    -1,   796,    -1,   798,    -1,    -1,    -1,
      -1,    -1,   804,    -1,    -1,     6,   808,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,    -1,    -1,    -1,    -1,   254,
      -1,    -1,   834,    -1,   836,   700,   838,   702,   703,   704,
     705,   706,   707,    -1,   709,   710,   711,   712,    -1,    -1,
     715,   716,   717,    -1,    -1,   202,    -1,    -1,    -1,    -1,
       6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   873,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   883,   884,   885,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,    -1,    -1,    -1,    -1,   254,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   572,    -1,   921,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   794,
     277,   933,    -1,   280,    -1,    -1,    -1,    -1,   803,   941,
      -1,    -1,    -1,   945,    -1,    -1,    -1,    -1,    -1,   296,
     297,   953,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   961,
     962,    -1,    -1,    -1,    -1,   967,    -1,    -1,    -1,    -1,
      -1,   626,   627,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   984,    -1,    -1,   987,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   343,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     6,    -1,    -1,    -1,  1010,    -1,
    1012,  1013,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   674,
     675,   676,    -1,   370,   679,   680,    -1,    -1,    -1,  1031,
      -1,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,    -1,
      -1,    -1,  1054,   254,    -1,    -1,    -1,    -1,    -1,  1061,
      -1,    -1,    -1,    -1,    -1,    -1,  1068,   722,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1081,
    1082,    -1,    -1,   430,    -1,  1087,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,    -1,    -1,   761,    -1,   254,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1118,  1119,  1120,  1121,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   783,     6,
      -1,    -1,    -1,    -1,   789,    -1,   791,    -1,    -1,    -1,
      -1,  1143,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1159,    -1,    -1,
      -1,    -1,   509,    -1,    -1,    -1,    -1,  1169,  1170,  1171,
    1172,  1173,    -1,    -1,    -1,    -1,  1178,  1179,    -1,  1181,
      -1,    -1,    -1,    -1,    -1,    -1,   533,    -1,    -1,    -1,
      -1,    -1,    -1,  1195,  1196,   542,   543,    -1,    -1,    -1,
      -1,  1203,  1204,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1212,  1213,    -1,    -1,    -1,    -1,  1218,  1219,   873,    -1,
     567,    -1,  1224,  1225,    -1,   572,    -1,  1092,   883,    -1,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,    -1,    -1,
      -1,   598,   254,    -1,    -1,    -1,  1258,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   921,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   933,   626,
     627,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1295,    -1,    -1,    -1,    -1,   953,    -1,
      -1,    -1,    -1,    -1,    -1,  1307,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1315,    -1,    -1,    -1,    -1,    -1,  1184,
    1185,    -1,    -1,    -1,    -1,    -1,    -1,   674,   675,   676,
      -1,    -1,   679,   680,  1336,  1337,    -1,    -1,    -1,  1341,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1352,    -1,    -1,  1355,    -1,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,    -1,    -1,   722,    -1,   254,    -1,    -1,
      -1,     6,  1384,    -1,    -1,  1387,  1388,  1389,  1390,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1398,    -1,    -1,  1401,
      -1,  1403,  1404,  1405,    -1,     6,  1408,  1409,    -1,    -1,
      -1,    -1,    -1,    -1,   761,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1087,    -1,    -1,    -1,   783,    -1,    -1,    -1,
      -1,    -1,   789,    -1,   791,   452,    -1,  1312,    -1,    -1,
      -1,  1316,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1325,    -1,  1327,    -1,    -1,  1330,    -1,    -1,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,  1488,    -1,  1143,   836,
     254,   838,   256,    -1,   258,    -1,  1498,  1499,  1500,    -1,
     264,    -1,    -1,    -1,    -1,  1507,    -1,  1509,    -1,    -1,
      -1,    -1,    -1,    -1,  1516,    -1,    -1,    -1,  1383,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   873,    -1,  1530,    -1,
      -1,    -1,    -1,  1535,  1536,  1537,   883,    -1,    -1,    -1,
      -1,    -1,    -1,  1545,  1546,  1547,    -1,    -1,    -1,    -1,
      -1,   558,    -1,  1555,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1565,    -1,    -1,    -1,    -1,    -1,  1224,
    1225,    -1,    -1,    -1,   921,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1586,    -1,   933,    -1,    -1,    -1,
      -1,    -1,  1594,  1595,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   609,    -1,    -1,    -1,   953,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,    -1,    -1,  1629,    -1,   254,
      -1,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,    -1,
      -1,    -1,  1307,   254,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1673,  1674,  1675,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1684,    -1,     6,    -1,    -1,  1689,  1690,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1702,    -1,    -1,    -1,    -1,    -1,    -1,  1709,  1710,  1711,
      -1,  1713,    -1,    -1,    -1,    -1,    -1,  1719,  1720,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1388,    -1,  1390,  1738,    -1,    -1,    -1,
    1087,  1743,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1614,
      -1,    -1,    -1,    -1,  1756,    -1,    -1,  1759,    -1,    -1,
      -1,  1763,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1772,  1773,    -1,  1775,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1785,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1143,  1799,    -1,    -1,
      -1,    -1,  1804,  1805,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1818,    -1,    -1,  1821,
    1822,    -1,  1824,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     6,    -1,    -1,    -1,    -1,   843,   844,   845,   846,
     847,   848,   849,   850,   851,   852,   853,    -1,   855,   856,
     857,   858,    -1,   860,   861,   862,   863,  1859,  1860,     6,
      -1,    -1,    -1,    -1,  1866,  1867,    -1,    -1,    -1,   876,
      -1,   878,    -1,    -1,    -1,  1530,  1878,  1224,  1225,    -1,
      -1,   888,    -1,    -1,    -1,  1887,    -1,    -1,   895,   896,
      -1,    -1,    -1,  1758,  1896,    -1,  1761,   904,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1907,  1908,    -1,    -1,  1911,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,     6,    -1,
      -1,    -1,   254,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1945,  1946,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1307,    -1,    -1,    -1,  1966,    -1,    -1,    -1,    -1,  1971,
    1972,  1973,    -1,    -1,    -1,    -1,  1978,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1992,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2007,    -1,    -1,    -1,    -1,
    1017,  1018,  1019,  2015,    -1,    -1,  1023,  1024,    -1,    -1,
    1027,  1028,  1029,  1030,    -1,  1032,    -1,    -1,    -1,    -1,
    1037,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2040,    -1,
      -1,  1388,    -1,  1390,  2046,    -1,    -1,  2049,    -1,    -1,
      -1,    -1,    -1,    -1,  1709,  1710,    -1,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,    -1,    -1,    -1,  2080,   254,
      -1,    -1,    -1,    -1,    -1,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,  2105,  2106,    -1,    -1,   254,    -1,    -1,
    1117,    -1,    -1,    -1,    -1,  1122,    -1,    -1,  2120,  2121,
      -1,  2123,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2136,    -1,    -1,    -1,    -1,  2141,
    2142,  2143,  2144,  2145,    -1,    -1,    -1,    -1,    -1,  2151,
      -1,    -1,    -1,  2155,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,    -1,    -1,    -1,    -1,   254,    -1,    -1,    -1,
    2182,    -1,    -1,  1530,    -1,  2187,  2188,    -1,    -1,    -1,
      -1,     4,     5,    -1,    -1,    -1,    -1,    -1,  2200,    -1,
      -1,    -1,    -1,    -1,  1859,  1860,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1221,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2227,  2228,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    -1,    -1,    -1,    -1,    62,
      63,    64,    65,    -1,    -1,    -1,  1911,    70,    71,    72,
      73,    -1,    -1,    -1,    -1,    78,     6,    80,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    94,  1629,    -1,    97,    -1,    -1,    -1,   101,    -1,
      -1,   104,    -1,    -1,   107,     6,   109,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   120,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1971,  1972,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   138,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1992,    -1,     6,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2007,    -1,    -1,    -1,  2221,  1364,    -1,    -1,
      -1,    -1,  1709,  1710,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2240,  2241,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2253,    -1,
      -1,  1738,    -1,    -1,    -1,    -1,   209,   210,   211,  1406,
      26,    -1,    28,    -1,    -1,    -1,    -1,   220,    -1,    -1,
      -1,   224,    -1,   226,   227,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1440,  1441,  1442,  1443,  1444,  1445,  1446,
      -1,    -1,    -1,    -1,  1451,  1452,   259,    -1,    -1,    -1,
    1457,    -1,  1459,    -1,    -1,    -1,  1463,    -1,    -1,  1466,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2123,    -1,
    1477,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2141,  2142,  2143,  2144,
    2145,    -1,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
      -1,    -1,  1859,  1860,   254,    -1,    -1,    -1,    -1,   145,
      -1,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,    -1,
      -1,    -1,    -1,   254,  1551,  2200,  1553,    -1,    -1,  1896,
    1557,    -1,  1559,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1911,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,  1590,     6,    -1,    -1,   254,    -1,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
      -1,   247,   248,    -1,  1971,  1972,    -1,    -1,     4,     5,
     256,   257,     7,     8,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   268,   269,    -1,  1992,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2007,    -1,    -1,     7,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    -1,    -1,  1691,    -1,    62,    63,    64,    65,
       8,    -1,    -1,    -1,    70,    71,    72,    73,    -1,    -1,
      -1,    -1,    78,    -1,    80,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,    -1,
      -1,    97,    -1,    -1,    -1,   101,    -1,    -1,   104,    -1,
      -1,   107,    -1,   109,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   120,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   138,   389,   390,   391,    -1,    -1,    -1,   395,
     396,   397,   398,   399,   400,   401,  2123,   403,    -1,    -1,
      -1,    -1,   408,   409,    -1,    -1,   412,    -1,  1795,    -1,
      -1,  1798,    -1,    -1,  2141,  2142,  2143,  2144,  2145,   425,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,    -1,    -1,
      -1,    -1,   254,   209,   210,   211,    -1,    -1,    -1,    -1,
      -1,    -1,  1849,  1850,   220,  1852,    -1,    -1,   224,    -1,
     226,   227,    -1,  2200,    -1,    -1,    -1,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,    -1,   252,   253,    -1,   254,
      -1,    -1,    -1,   259,    -1,   261,    -1,    -1,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,     8,    -1,  1915,  1916,
     254,    -1,    -1,    -1,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,    -1,    -1,    -1,    -1,   254,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,   580,    -1,    -1,  1964,    10,    11,
      12,    -1,    -1,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    -1,    -1,    -1,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    -1,    -1,    70,    71,
      72,    73,    -1,    -1,    76,    77,    78,    -1,    80,    81,
      82,    83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      92,    93,    94,    95,    -1,    97,    -1,    -1,    -1,   101,
      -1,    -1,   104,    -1,    -1,   107,    -1,   109,    -1,    -1,
      -1,    -1,    -1,    -1,   116,    -1,    -1,    -1,   120,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   131,
      -1,   133,   134,    -1,   136,    -1,   138,    -1,    -1,   141,
      -1,    -1,    -1,    -1,    -1,   147,   148,   149,   150,   151,
      -1,   153,   154,   155,   156,   157,   158,    -1,    -1,    -1,
     162,    -1,    -1,   165,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,    -1,    -1,
      -1,    -1,   254,    -1,    -1,    -1,   208,   209,   210,   211,
     212,   213,    -1,    -1,    -1,   217,   218,   219,   220,   221,
     222,   223,   224,     8,   226,   227,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   243,   244,    -1,    -1,    -1,    -1,    -1,   250,    -1,
      -1,    -1,  2209,   255,    -1,    -1,    -1,   259,    -1,    -1,
     262,    -1,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
       3,     4,     5,    -1,   254,    -1,    -1,    10,    11,    12,
     260,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,   899,    -1,    -1,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    -1,    -1,    70,    71,    72,
      73,    -1,    -1,    76,    77,    78,   932,    80,    81,    82,
      83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,
      93,    94,    95,    -1,    97,    -1,    -1,    -1,   101,    -1,
      -1,   104,    -1,    -1,   107,    -1,   109,    -1,    -1,    -1,
      -1,    -1,    -1,   116,    -1,    -1,    -1,   120,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   131,    -1,
     133,   134,    -1,   136,    -1,   138,    -1,    -1,   141,    -1,
      -1,    -1,    -1,    -1,   147,   148,   149,   150,   151,    -1,
     153,   154,   155,   156,   157,   158,    -1,    -1,    -1,   162,
      -1,    -1,   165,    -1,    -1,    -1,    -1,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,     8,    -1,    -1,    -1,   254,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   208,   209,   210,   211,   212,
     213,     8,    -1,    -1,   217,   218,   219,   220,   221,   222,
     223,   224,    -1,   226,   227,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     243,   244,    -1,    -1,    -1,    -1,    -1,   250,    -1,    -1,
      -1,    -1,   255,    -1,    -1,  1111,   259,    -1,    -1,   262,
      -1,    -1,    -1,    -1,     3,     4,     5,    -1,     7,    -1,
      -1,    10,    11,    12,    -1,    -1,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    -1,    -1,
      -1,    70,    71,    72,    73,    -1,    -1,    -1,    -1,    78,
      -1,    80,    81,    82,    83,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1208,    92,    93,    94,    95,    -1,    97,    -1,
      -1,    -1,   101,    -1,    -1,   104,    -1,    -1,   107,    -1,
     109,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   120,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,    -1,    -1,    -1,
      -1,   254,    -1,    -1,    -1,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,    -1,    -1,    -1,    -1,   254,    -1,    -1,
      -1,    -1,   201,    -1,    -1,    -1,    -1,    -1,    -1,   208,
     209,   210,   211,   212,    -1,    -1,    -1,    -1,   217,   218,
     219,   220,   221,   222,   223,   224,    -1,   226,   227,   228,
     229,   230,   231,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   243,   244,    -1,    -1,    -1,  1365,
    1366,   250,    -1,   252,   253,    -1,   255,    -1,   257,     3,
       4,     5,   261,   262,    -1,    -1,    10,    11,    12,    -1,
      -1,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    58,    59,    60,    61,    -1,    -1,
      -1,    -1,    66,    67,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    76,    77,    -1,    13,    14,    81,    82,    83,
      -1,    -1,    -1,    -1,    -1,  1461,    -1,    -1,    92,    93,
      -1,    95,    -1,    -1,  1470,    -1,    -1,   101,    -1,    -1,
     104,    -1,    -1,   107,    -1,   109,    -1,    -1,    -1,    -1,
      -1,    -1,   116,    -1,    -1,    -1,   120,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   131,    -1,   133,
     134,    -1,   136,    -1,   138,    -1,    -1,   141,    -1,    -1,
      -1,    -1,    -1,   147,   148,   149,   150,   151,    -1,   153,
     154,   155,   156,   157,   158,    -1,    -1,    -1,   162,    -1,
      -1,   165,    -1,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,    -1,    -1,    -1,   117,
     118,   119,   120,    -1,    -1,   123,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   131,   132,    -1,    -1,   135,   136,    -1,
     138,   139,    -1,   141,   208,    -1,    -1,    -1,   212,   213,
      -1,    -1,    -1,   217,   218,   219,    -1,   221,   222,   223,
      -1,   159,    -1,   227,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   243,
     244,    -1,    -1,    -1,    -1,    -1,   250,   185,   186,   187,
      -1,   255,  1628,    -1,    -1,   259,     3,     4,   262,    -1,
      -1,     8,    -1,    10,    11,    12,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    58,    59,    60,    61,    -1,    -1,    -1,    -1,    66,
      67,    -1,   260,    -1,    -1,    -1,    -1,    -1,    -1,    76,
      77,    -1,    13,    14,    81,    82,    83,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    92,    93,    -1,    95,    -1,
      -1,    -1,    -1,    -1,   101,    -1,    -1,   104,    -1,    -1,
     107,    -1,   109,    -1,    -1,    -1,    -1,    -1,    -1,   116,
      -1,    -1,    -1,   120,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   131,    -1,   133,   134,    -1,   136,
      -1,   138,    -1,    -1,   141,    -1,    -1,    -1,    -1,    -1,
     147,   148,   149,   150,   151,    -1,   153,   154,   155,   156,
     157,   158,    -1,    -1,    -1,   162,    -1,    -1,   165,    -1,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,    -1,    -1,    -1,   117,   118,   119,   120,
      -1,    -1,   123,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     131,   132,    -1,    -1,   135,   136,    -1,   138,   139,    -1,
     141,   208,    -1,    -1,    -1,   212,   213,    -1,    -1,    -1,
     217,   218,   219,    -1,   221,   222,   223,    -1,   159,    -1,
     227,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   243,   244,    -1,    -1,
      -1,    -1,    -1,   250,   185,   186,   187,    -1,   255,     3,
       4,     5,    -1,   260,    -1,   262,    10,    11,    12,    -1,
      -1,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    58,    59,    60,    61,    -1,    -1,
      -1,    -1,    66,    67,    -1,    -1,    -1,    -1,    -1,   260,
      -1,    -1,    76,    77,    -1,    13,    14,    81,    82,    83,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    93,
      -1,    95,    -1,    -1,    -1,    -1,    -1,   101,    -1,    -1,
     104,    -1,    -1,   107,    -1,   109,    -1,    -1,    -1,    -1,
      -1,    -1,   116,    -1,    -1,    -1,   120,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   131,    -1,   133,
     134,    -1,   136,    -1,   138,    -1,    -1,   141,    -1,    -1,
      -1,    -1,    -1,   147,   148,   149,   150,   151,    -1,   153,
     154,   155,   156,   157,   158,    -1,    -1,    -1,   162,    -1,
      -1,   165,    -1,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,    -1,    -1,    -1,   117,
     118,   119,   120,    -1,    -1,   123,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   131,   132,    -1,    -1,   135,   136,    -1,
     138,   139,    -1,   141,   208,    -1,    -1,    -1,   212,   213,
      -1,    -1,    -1,   217,   218,   219,    -1,   221,   222,   223,
      -1,   159,    -1,   227,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   243,
     244,    -1,    -1,    -1,    -1,    -1,   250,   185,   186,   187,
      -1,   255,     3,     4,    -1,   259,    -1,    -1,   262,    10,
      11,    12,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,    59,    60,
      61,    -1,    -1,    -1,    -1,    66,    67,    -1,    -1,    -1,
      -1,    -1,   260,    -1,    -1,    76,    77,    -1,    13,    14,
      81,    82,    83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    92,    93,    -1,    95,    -1,    -1,    -1,    -1,    -1,
     101,    -1,    -1,   104,    -1,    -1,   107,    -1,   109,    -1,
      -1,    -1,    -1,    -1,    -1,   116,    -1,    -1,    -1,   120,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     131,    -1,   133,   134,    -1,   136,    -1,   138,    -1,    -1,
     141,    -1,    -1,    -1,    -1,    -1,   147,   148,   149,   150,
     151,    -1,   153,   154,   155,   156,   157,   158,    -1,    -1,
      -1,   162,    -1,    -1,   165,    -1,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,    -1,
      -1,    -1,   117,   118,   119,   120,    -1,    -1,   123,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   131,   132,    -1,    -1,
     135,   136,    -1,   138,   139,    -1,   141,   208,    -1,    -1,
      -1,   212,   213,    -1,    -1,    -1,   217,   218,   219,    -1,
     221,   222,   223,    -1,   159,    -1,   227,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   243,   244,    -1,    -1,    -1,    -1,    -1,   250,
     185,   186,   187,    -1,   255,     3,     4,    -1,   259,   260,
      -1,   262,    10,    11,    12,    -1,    -1,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      58,    59,    60,    61,    -1,    -1,    -1,    -1,    66,    67,
      -1,    -1,    -1,    -1,    -1,   260,    -1,    -1,    76,    77,
      -1,    13,    14,    81,    82,    83,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    92,    93,    -1,    95,    -1,    -1,
      -1,    -1,    -1,   101,    -1,    -1,   104,    -1,    -1,   107,
      -1,   109,    -1,    -1,    -1,    -1,    -1,    -1,   116,    -1,
      -1,    -1,   120,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   131,    -1,   133,   134,    -1,   136,    -1,
     138,    -1,    -1,   141,    -1,    -1,    -1,    -1,    -1,   147,
     148,   149,   150,   151,    -1,   153,   154,   155,   156,   157,
     158,    -1,    -1,    -1,   162,    -1,    -1,   165,    -1,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,    -1,    -1,    -1,   117,   118,   119,   120,    -1,
      -1,   123,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   131,
     132,    -1,    -1,   135,   136,    -1,   138,   139,    -1,   141,
     208,    -1,    -1,    -1,   212,   213,    -1,    -1,    -1,   217,
     218,   219,    -1,   221,   222,   223,    -1,   159,    -1,   227,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   243,   244,    -1,    -1,    -1,
      -1,    -1,   250,   185,   186,   187,    -1,   255,     3,     4,
      -1,   259,    -1,    -1,   262,    10,    11,    12,    -1,    -1,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    58,    59,    60,    61,    -1,    -1,    -1,
      -1,    66,    67,    -1,    -1,    -1,    -1,    -1,   260,    -1,
      -1,    76,    77,    -1,    13,    14,    81,    82,    83,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    93,    -1,
      95,    -1,    -1,    -1,    -1,    -1,   101,    -1,    -1,   104,
      -1,    -1,   107,    -1,   109,    -1,    -1,    -1,    -1,    -1,
      -1,   116,    -1,    -1,    -1,   120,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   131,    -1,   133,   134,
      -1,   136,    -1,   138,    -1,    -1,   141,    -1,    -1,    -1,
      -1,    -1,   147,   148,   149,   150,   151,    -1,   153,   154,
     155,   156,   157,   158,    -1,    -1,    -1,   162,    -1,    -1,
     165,    -1,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,    -1,    -1,    -1,   117,   118,
     119,   120,    -1,    -1,   123,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   131,   132,    -1,    -1,   135,   136,    -1,   138,
     139,    -1,   141,   208,    -1,    -1,    -1,   212,   213,    -1,
      -1,    -1,   217,   218,   219,    -1,   221,   222,   223,    -1,
     159,    -1,   227,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   243,   244,
      -1,    -1,    -1,    -1,    -1,   250,   185,   186,   187,    -1,
     255,     3,     4,    -1,   259,    -1,    -1,   262,    10,    11,
      12,    -1,    -1,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    58,    59,    60,    61,
      -1,    -1,    -1,    -1,    66,    67,    -1,    -1,    -1,    -1,
      -1,   260,    -1,    -1,    76,    77,    -1,    13,    14,    81,
      82,    83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      92,    93,    -1,    95,    -1,    -1,    -1,    -1,    -1,   101,
      -1,    -1,   104,    -1,    -1,   107,    -1,   109,    -1,    -1,
      -1,    -1,    -1,    -1,   116,    -1,    -1,    -1,   120,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   131,
      -1,   133,   134,    -1,   136,    -1,   138,    -1,    -1,   141,
      -1,    -1,    -1,    -1,    -1,   147,   148,   149,   150,   151,
      -1,   153,   154,   155,   156,   157,   158,    -1,    -1,    -1,
     162,    -1,    -1,   165,    -1,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,    -1,    -1,
      -1,   117,   118,   119,   120,    -1,    -1,   123,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   131,   132,    -1,    -1,   135,
     136,    -1,   138,   139,    -1,   141,   208,    -1,    -1,    -1,
     212,   213,    -1,    -1,    -1,   217,   218,   219,    -1,   221,
     222,   223,    -1,   159,    -1,   227,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   243,   244,    -1,    -1,    -1,    -1,    -1,   250,   185,
     186,   187,    -1,   255,     3,     4,    -1,   259,    -1,    -1,
     262,    10,    11,    12,    -1,    -1,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,
      59,    60,    61,    -1,    -1,    -1,    -1,    66,    67,    -1,
      -1,    -1,    -1,    -1,   260,    -1,    -1,    76,    77,    -1,
      13,    14,    81,    82,    83,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    92,    93,    -1,    95,    -1,    -1,    -1,
      -1,    -1,   101,    -1,    -1,   104,    -1,    -1,   107,    -1,
     109,    -1,    -1,    -1,    -1,    -1,    -1,   116,    -1,    -1,
      -1,   120,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   131,    -1,   133,   134,    -1,   136,    -1,   138,
      -1,    -1,   141,    -1,    -1,    -1,    -1,    -1,   147,   148,
     149,   150,   151,    -1,   153,   154,   155,   156,   157,   158,
      -1,    -1,    -1,   162,    -1,    -1,   165,    -1,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,    -1,    -1,    -1,   117,   118,   119,   120,    -1,    -1,
     123,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   131,   132,
      -1,    -1,   135,   136,    -1,   138,   139,    -1,   141,   208,
      -1,    -1,    -1,   212,   213,    -1,    -1,    -1,   217,   218,
     219,    -1,   221,   222,   223,    -1,   159,    -1,   227,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   243,   244,    -1,    -1,    -1,    -1,
      -1,   250,   185,   186,   187,    -1,   255,     3,     4,    -1,
      -1,   260,    -1,   262,    10,    11,    12,    -1,    -1,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    58,    59,    60,    61,    -1,    -1,    -1,    -1,
      66,    67,    -1,    -1,    -1,    -1,    -1,   260,    -1,    -1,
      76,    77,    -1,    13,    14,    81,    82,    83,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    92,    93,    -1,    95,
      -1,    -1,    -1,    -1,    -1,   101,    -1,    -1,   104,    -1,
      -1,   107,    -1,   109,    -1,    -1,    -1,    -1,    -1,    -1,
     116,    -1,    -1,    -1,   120,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   131,    -1,   133,   134,    -1,
     136,    -1,   138,    -1,    -1,   141,    -1,    -1,    -1,    -1,
      -1,   147,   148,   149,   150,   151,    -1,   153,   154,   155,
     156,   157,   158,    -1,    -1,    -1,   162,    -1,    -1,   165,
      -1,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,    -1,    -1,    -1,   117,   118,   119,
     120,    -1,    -1,   123,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   131,   132,    -1,    -1,   135,   136,    -1,   138,   139,
      -1,   141,   208,    -1,    -1,    -1,   212,   213,    -1,    -1,
      -1,   217,   218,   219,    -1,   221,   222,   223,    -1,   159,
      -1,   227,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   243,   244,    -1,
      -1,    -1,    -1,    -1,   250,   185,   186,   187,    -1,   255,
       3,     4,    -1,   259,    -1,    -1,   262,    10,    11,    12,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    58,    59,    60,    61,    -1,
      -1,    -1,    -1,    66,    67,    -1,    -1,    -1,    -1,    -1,
     260,    -1,    -1,    76,    77,    -1,    13,    14,    81,    82,
      83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,
      93,    -1,    95,    -1,    -1,    -1,    -1,    -1,   101,    -1,
      -1,   104,    -1,    -1,   107,    -1,   109,    -1,    -1,    -1,
      -1,    -1,    -1,   116,    -1,    -1,    -1,   120,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   131,    -1,
     133,   134,    -1,   136,    -1,   138,    -1,    -1,   141,    -1,
      -1,    -1,    -1,    -1,   147,   148,   149,   150,   151,    -1,
     153,   154,   155,   156,   157,   158,    -1,    -1,    -1,   162,
      -1,    -1,   165,    -1,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,    -1,    -1,    -1,
     117,   118,   119,   120,    -1,    -1,   123,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   131,   132,    -1,    -1,   135,   136,
      -1,   138,   139,    -1,   141,   208,    -1,    -1,    -1,   212,
     213,    -1,    -1,    -1,   217,   218,   219,    -1,   221,   222,
     223,    -1,   159,    -1,   227,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     243,   244,    -1,    -1,    -1,    -1,    -1,   250,   185,   186,
     187,    -1,   255,     3,     4,    -1,   259,    -1,    -1,   262,
      10,    11,    12,    -1,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,    59,
      60,    61,    -1,    -1,    -1,    -1,    66,    67,    -1,    -1,
      -1,    -1,    -1,   260,    -1,    -1,    76,    77,    -1,    13,
      14,    81,    82,    83,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    92,    93,    -1,    95,    -1,    -1,    -1,    -1,
      -1,   101,    -1,    -1,   104,    -1,    -1,   107,    -1,   109,
      -1,    -1,    -1,    -1,    -1,    -1,   116,    -1,    -1,    -1,
     120,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   131,    -1,   133,   134,    -1,   136,    -1,   138,    -1,
      -1,   141,    -1,    -1,    -1,    -1,    -1,   147,   148,   149,
     150,   151,    -1,   153,   154,   155,   156,   157,   158,    -1,
      -1,    -1,   162,    -1,    -1,   165,    -1,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
      -1,    -1,    -1,   117,   118,   119,   120,    -1,    -1,   123,
      -1,    -1,    -1,    -1,    -1,     8,    -1,   131,   132,    -1,
      -1,   135,   136,    -1,   138,   139,    -1,   141,   208,    -1,
      -1,    -1,   212,   213,    -1,    -1,    -1,   217,   218,   219,
      -1,   221,   222,   223,    -1,   159,    -1,   227,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   243,   244,    -1,    -1,    -1,    -1,    -1,
     250,   185,   186,   187,    -1,   255,     3,     4,    -1,   259,
      -1,     8,   262,    10,    11,    12,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    58,    59,    60,    61,    -1,    -1,    -1,    -1,    66,
      67,    -1,    -1,    -1,    -1,    -1,   260,    -1,    -1,    76,
      77,    -1,    -1,    -1,    81,    82,    83,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    92,    93,    -1,    95,    -1,
      -1,    -1,    -1,    -1,   101,    -1,    -1,   104,    -1,    -1,
     107,    -1,   109,    -1,    -1,    -1,    -1,    -1,    -1,   116,
      -1,    -1,    -1,   120,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   131,    -1,   133,   134,    -1,   136,
      -1,   138,    -1,    -1,   141,    -1,    -1,    -1,    -1,    -1,
     147,   148,   149,   150,   151,    -1,   153,   154,   155,   156,
     157,   158,    -1,    -1,    -1,   162,    -1,    -1,   165,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,    -1,    -1,    -1,
      -1,   254,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
      -1,   208,    -1,    -1,   254,   212,   213,    -1,    -1,   259,
     217,   218,   219,    -1,   221,   222,   223,    -1,    -1,    -1,
     227,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   243,   244,    -1,    -1,
      -1,    -1,    -1,   250,     3,     4,    -1,    -1,   255,     8,
      -1,    10,    11,    12,    -1,   262,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,
      59,    60,    61,    -1,    -1,    -1,    -1,    66,    67,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    76,    77,    -1,
      -1,    -1,    81,    82,    83,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    92,    93,    -1,    95,    -1,    -1,    -1,
      -1,    -1,   101,    -1,    -1,   104,    -1,    -1,   107,    -1,
     109,    -1,    -1,    -1,    -1,    -1,    -1,   116,    -1,    -1,
      -1,   120,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   131,    -1,   133,   134,    -1,   136,    -1,   138,
      -1,    -1,   141,    -1,    -1,    -1,    -1,    -1,   147,   148,
     149,   150,   151,    -1,   153,   154,   155,   156,   157,   158,
      -1,    -1,    -1,   162,    -1,    -1,   165,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,    -1,    -1,    -1,    -1,   254,
      -1,   256,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   264,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   208,
      -1,    -1,    -1,   212,   213,    -1,    -1,    -1,   217,   218,
     219,    -1,   221,   222,   223,    -1,    -1,    -1,   227,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   243,   244,    -1,    -1,    -1,    -1,
      -1,   250,     3,     4,    -1,    -1,   255,    -1,    -1,    10,
      11,    12,    -1,   262,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,    59,    60,
      61,    -1,    -1,    -1,    -1,    66,    67,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    76,    77,    -1,    13,    14,
      81,    82,    83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    92,    93,    -1,    95,    -1,    -1,    -1,    -1,    -1,
     101,    -1,    -1,   104,    -1,    -1,   107,    -1,   109,    -1,
      -1,    -1,    -1,    -1,    -1,   116,    -1,    -1,    -1,   120,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     131,    -1,   133,   134,    -1,   136,    -1,   138,    -1,    -1,
     141,    -1,    -1,    -1,    -1,    -1,   147,   148,   149,   150,
     151,    -1,   153,   154,   155,   156,   157,   158,    -1,    -1,
      -1,   162,    -1,    -1,   165,    -1,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,    -1,
      -1,    -1,   117,   118,   119,   120,    -1,    -1,   123,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   131,   132,    -1,    -1,
     135,   136,    -1,   138,   139,    -1,   141,   208,    -1,    -1,
      -1,   212,   213,    -1,    -1,    -1,   217,   218,   219,    -1,
     221,   222,   223,    -1,   159,    -1,   227,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   243,   244,    -1,    -1,    -1,    -1,    -1,   250,
     185,   186,   187,    -1,   255,     3,     4,    -1,   259,    -1,
      -1,   262,    10,    11,    12,    -1,    -1,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      58,    59,    60,    61,    -1,    -1,    -1,    -1,    66,    67,
      -1,    -1,    -1,    -1,    -1,   260,    -1,    -1,    76,    77,
      -1,    13,    14,    81,    82,    83,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    92,    93,    -1,    95,    -1,    -1,
      -1,    -1,    -1,   101,    -1,    -1,   104,    -1,    -1,   107,
      -1,   109,    -1,    -1,    -1,    -1,    -1,    -1,   116,    -1,
      -1,    -1,   120,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   131,    -1,   133,   134,    -1,   136,    -1,
     138,    -1,    -1,   141,    -1,    -1,    -1,    -1,    -1,   147,
     148,   149,   150,   151,    -1,   153,   154,   155,   156,   157,
     158,    -1,    -1,    -1,   162,    -1,    -1,   165,    -1,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,    -1,    -1,    -1,   117,   118,   119,   120,    -1,
      -1,   123,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   131,
     132,    -1,    -1,   135,   136,    -1,   138,   139,    -1,   141,
     208,    -1,    -1,    -1,   212,   213,    -1,    -1,    -1,   217,
     218,   219,    -1,   221,   222,   223,    -1,   159,    -1,   227,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   243,   244,    -1,    -1,    -1,
      -1,    -1,   250,   185,   186,   187,    -1,   255,     3,     4,
      -1,   259,    -1,    -1,   262,    10,    11,    12,    -1,    -1,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    58,    59,    60,    61,    -1,    -1,    -1,
      -1,    66,    67,    -1,    -1,    -1,    -1,    -1,   260,    -1,
      -1,    76,    77,    -1,    -1,    -1,    81,    82,    83,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    93,    -1,
      95,    -1,    -1,    -1,    -1,    -1,   101,    -1,    -1,   104,
      -1,    -1,   107,    -1,   109,    -1,    -1,    -1,    -1,    -1,
      -1,   116,    -1,    -1,    -1,   120,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   131,    -1,   133,   134,
      -1,   136,    -1,   138,    -1,    -1,   141,    -1,    -1,    -1,
      -1,    -1,   147,   148,   149,   150,   151,    -1,   153,   154,
     155,   156,   157,   158,    -1,    -1,    -1,   162,    -1,    -1,
     165,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,    -1,
      -1,    -1,    -1,   254,    -1,    -1,    -1,    -1,    -1,   260,
      -1,    -1,    -1,   264,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   208,    -1,    -1,    -1,   212,   213,    -1,
      -1,    -1,   217,   218,   219,    -1,   221,   222,   223,    -1,
      -1,    -1,   227,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   243,   244,
      -1,    -1,    -1,    -1,    -1,   250,     3,     4,     5,    -1,
     255,    -1,    -1,    10,    11,    12,    -1,   262,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      -1,    -1,    -1,    70,    71,    72,    73,    -1,    -1,    -1,
      -1,    78,    -1,    80,    81,    82,    83,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    92,    93,    94,    95,    -1,
      97,     3,     4,     5,    -1,    -1,    -1,    -1,    10,    11,
      12,    -1,    -1,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    -1,    -1,    -1,    70,    71,
      72,    73,    -1,    -1,    -1,    -1,    78,    -1,    80,    81,
      82,    83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      92,    93,    94,    95,    -1,    97,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   208,   209,   210,   211,   212,    -1,    -1,    -1,    -1,
     217,   218,   219,   220,   221,   222,   223,   224,    -1,   226,
     227,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   243,   244,    -1,    -1,
      -1,    -1,    -1,   250,    -1,    -1,    -1,    -1,   255,    -1,
      -1,    -1,   259,    -1,    -1,   262,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,    -1,    -1,    -1,    -1,   254,    -1,
      -1,    -1,    -1,    -1,   260,    -1,    -1,    -1,   264,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   208,   209,   210,   211,
     212,    -1,    -1,    -1,    -1,   217,   218,   219,   220,   221,
     222,   223,   224,    -1,   226,   227,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   243,   244,    -1,    -1,    -1,    -1,    -1,   250,    -1,
      -1,    -1,    -1,   255,     3,     4,     5,   259,    -1,    -1,
     262,    10,    11,    12,    -1,    -1,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    -1,    -1,
      -1,    70,    71,    72,    73,    -1,    -1,    -1,    -1,    78,
      -1,    80,    81,    82,    83,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    92,    93,    94,    95,    -1,    97,     3,
       4,     5,    -1,    -1,    -1,    -1,    10,    11,    12,    -1,
      -1,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    -1,    -1,    -1,    70,    71,    72,    73,
      -1,    -1,    -1,    -1,    78,    -1,    80,    81,    82,    83,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    93,
      94,    95,    -1,    97,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   208,
     209,   210,   211,   212,    -1,    -1,    -1,    -1,   217,   218,
     219,   220,   221,   222,   223,   224,    -1,   226,   227,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   243,   244,    -1,    -1,    -1,    -1,
      -1,   250,    -1,    -1,    -1,    -1,   255,    -1,    -1,    -1,
     259,    -1,    -1,   262,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,    -1,    -1,    -1,    -1,   254,    -1,    -1,    -1,
      -1,    -1,   260,    -1,    -1,    -1,   264,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   208,   209,   210,   211,   212,    -1,
      -1,    -1,    -1,   217,   218,   219,   220,   221,   222,   223,
     224,    -1,   226,   227,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   243,
     244,    -1,    -1,    -1,    -1,    -1,   250,     3,     4,    -1,
      -1,   255,    -1,    -1,    10,    11,    12,    -1,   262,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    58,    59,    60,    61,    -1,    -1,    -1,    -1,
      66,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    81,    82,    83,    -1,    -1,
      -1,    -1,    -1,     3,     4,    -1,    92,    93,    -1,    95,
      10,    11,    12,    -1,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    13,    14,    58,    59,
      60,    61,    -1,    -1,    -1,    -1,    66,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    81,    82,    83,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    92,    93,    -1,    95,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,    -1,    -1,    -1,    -1,   254,    -1,
      -1,    -1,   208,    -1,   260,    -1,   212,    -1,   264,    -1,
      -1,   217,   218,   219,    -1,   221,   222,   223,    -1,    -1,
      -1,   227,    -1,    -1,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   243,   244,    -1,
     117,   118,   119,   120,   250,    -1,   123,    -1,    -1,   255,
      -1,    -1,    -1,   259,   131,   132,   262,    -1,   135,   136,
      -1,   138,   139,    -1,   141,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   159,    -1,    -1,    -1,    -1,    -1,   208,    -1,
      -1,    -1,   212,    -1,    -1,    -1,    -1,   217,   218,   219,
      -1,   221,   222,   223,    -1,    -1,    -1,   227,   185,   186,
     187,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   243,   244,    -1,    -1,    -1,    -1,    -1,
     250,    -1,    -1,    -1,    -1,   255,     3,     4,    -1,   259,
      -1,     8,   262,    10,    11,    12,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   260,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    58,    59,    60,    61,    -1,    -1,    -1,    -1,    66,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    81,    82,    83,    -1,    -1,    -1,
      -1,    -1,     3,     4,    -1,    92,    93,    -1,    95,    10,
      11,    12,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    13,    14,    58,    59,    60,
      61,    -1,    -1,    -1,    -1,    66,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      81,    82,    83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    92,    93,    -1,    95,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,    -1,    -1,    -1,    -1,   254,    -1,    -1,
      -1,   208,    -1,    -1,    -1,   212,    -1,   264,    -1,    -1,
     217,   218,   219,    -1,   221,   222,   223,    -1,    -1,    -1,
     227,    -1,    -1,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   243,   244,    -1,   117,
     118,   119,   120,   250,    -1,   123,    -1,    -1,   255,    -1,
      -1,    -1,    -1,   131,   132,   262,    -1,   135,   136,    -1,
     138,   139,    -1,   141,    -1,    -1,    -1,   145,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   159,    -1,    -1,    -1,   163,    -1,   208,    -1,    -1,
      -1,   212,    -1,    -1,    -1,    -1,   217,   218,   219,    -1,
     221,   222,   223,    -1,    -1,    -1,   227,   185,   186,   187,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   243,   244,    -1,    -1,    -1,    -1,    -1,   250,
       3,     4,    -1,     6,   255,   256,    -1,    10,    11,    12,
      -1,   262,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    58,    59,    60,    61,    -1,
      -1,    -1,    -1,    66,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,    82,
      83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,
      93,    -1,    95,     3,     4,    -1,     6,    -1,    -1,    -1,
      10,    11,    12,    -1,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,    59,
      60,    61,    -1,    -1,    -1,    -1,    66,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    81,    82,    83,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    92,    93,    -1,    95,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,    -1,   208,    -1,    -1,   254,   212,
      -1,    -1,    -1,   259,   217,   218,   219,    -1,   221,   222,
     223,    -1,    -1,    -1,   227,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     243,   244,    -1,    -1,    -1,    -1,    -1,   250,    -1,    -1,
      -1,    -1,   255,    -1,    -1,    -1,    -1,    -1,    -1,   262,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,    -1,    -1,
      -1,    -1,   254,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   264,    -1,    -1,    -1,    -1,    -1,   208,    -1,
      -1,    -1,   212,    -1,    -1,    -1,    -1,   217,   218,   219,
      -1,   221,   222,   223,    -1,    -1,    -1,   227,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   243,   244,    -1,    -1,    -1,    -1,    -1,
     250,     3,     4,    -1,     6,   255,    -1,    -1,    10,    11,
      12,    -1,   262,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    58,    59,    60,    61,
      -1,    -1,    -1,    -1,    66,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,
      82,    83,    -1,    -1,    -1,    -1,    -1,     3,     4,    -1,
      92,    93,    -1,    95,    10,    11,    12,    -1,    -1,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      13,    14,    58,    59,    60,    61,    -1,    -1,    -1,    -1,
      66,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    81,    82,    83,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    92,    93,    -1,    95,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,    -1,    -1,
      -1,    -1,   254,    -1,    -1,    -1,   208,    -1,    -1,    -1,
     212,    -1,   264,    -1,    -1,   217,   218,   219,    -1,   221,
     222,   223,    -1,    -1,    -1,   227,    -1,    -1,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   243,   244,    -1,   117,   118,   119,   120,   250,    -1,
     123,    -1,    -1,   255,    -1,    -1,    -1,    -1,   131,   132,
     262,    -1,   135,   136,    -1,   138,   139,    -1,   141,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   159,    -1,    -1,    -1,
      -1,    -1,   208,    -1,    -1,    -1,   212,    -1,    -1,    -1,
      -1,   217,   218,   219,    -1,   221,   222,   223,    -1,    -1,
      -1,   227,   185,   186,   187,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   243,   244,    -1,
      -1,    -1,    -1,    -1,   250,     3,     4,    -1,    -1,   255,
     256,    -1,    10,    11,    12,    -1,   262,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      58,    59,    60,    61,    -1,    -1,    -1,    -1,    66,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    81,    82,    83,    -1,    -1,    -1,    -1,
      -1,     3,     4,    -1,    92,    93,    -1,    95,    10,    11,
      12,    -1,    -1,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    58,    59,    60,    61,
      -1,    -1,    -1,    -1,    66,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,
      82,    83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      92,    93,    -1,    95,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,    -1,    -1,    -1,    -1,   254,    -1,    -1,    -1,
     208,    -1,    -1,    -1,   212,    -1,   264,    -1,    -1,   217,
     218,   219,    -1,   221,   222,   223,    -1,    -1,    -1,   227,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   243,   244,    -1,    -1,    -1,
      -1,    -1,   250,    -1,    -1,    -1,    -1,   255,   256,    -1,
      -1,    -1,    -1,    -1,   262,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     0,     1,    -1,    -1,     4,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    13,    14,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   208,    -1,    -1,    -1,
     212,    -1,    -1,    -1,    -1,   217,   218,   219,    -1,   221,
     222,   223,    -1,    -1,    -1,   227,    -1,    -1,    46,    47,
      48,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   243,   244,    -1,    -1,    -1,    -1,    -1,   250,    67,
      68,    69,    -1,   255,    -1,    -1,    74,    75,    -1,    -1,
     262,    79,    -1,    -1,    -1,    -1,    84,    85,    86,    87,
      88,    -1,    90,    91,    -1,    93,    -1,    -1,    -1,    -1,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,    -1,    -1,   116,   117,
     118,   119,   120,   121,    -1,   123,    -1,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,    -1,    -1,   143,   144,   145,    -1,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,    -1,    -1,    -1,   173,   174,   175,    -1,    -1,
      -1,   179,    -1,    -1,    -1,    -1,   184,   185,   186,   187,
      -1,    -1,   190,    -1,   192,    -1,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
       4,    -1,    -1,    -1,    -1,    -1,   214,   215,   216,    13,
      14,    -1,    -1,    -1,    -1,    -1,    -1,   225,    -1,   227,
      -1,    -1,    -1,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,    -1,    46,    47,    48,   254,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   264,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    67,    68,    69,    -1,    -1,    -1,    -1,
      74,    75,    -1,    -1,    -1,    79,    -1,    -1,    -1,    -1,
      84,    85,    86,    87,    88,    -1,    90,    91,    -1,    93,
      -1,    -1,    -1,    -1,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
      -1,    -1,   116,   117,   118,   119,   120,   121,    -1,   123,
      -1,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,    -1,    -1,   143,
     144,   145,    -1,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,    -1,    -1,    -1,   173,
     174,   175,    -1,    -1,    -1,   179,    -1,    -1,    -1,    -1,
     184,   185,   186,   187,     4,     5,   190,    -1,   192,    -1,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,    -1,    -1,    -1,    -1,    -1,    -1,
     214,   215,   216,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   225,    -1,   227,    -1,    -1,    -1,    -1,    -1,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    -1,    -1,
      -1,    -1,    62,    63,    64,    65,     4,     5,    -1,    -1,
      70,    71,    72,    73,    -1,    -1,    -1,    -1,    78,    -1,
      80,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    94,    -1,    -1,    97,    -1,    -1,
      -1,   101,    -1,     5,   104,    -1,    -1,   107,    -1,   109,
      -1,    49,    50,    51,    52,    53,    54,    55,    56,    57,
     120,    -1,    -1,    -1,    62,    63,    64,    65,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    -1,    -1,   138,    -1,
      78,    -1,    80,    -1,    -1,    -1,    -1,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    94,    -1,    -1,    97,
      62,    63,    64,    65,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    -1,    -1,    -1,    -1,    78,    -1,    80,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    94,    -1,    -1,    97,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   209,
     210,   211,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     220,    -1,    -1,    -1,   224,    -1,   226,   227,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,    -1,    -1,    -1,    -1,
     254,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     264,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   209,   210,   211,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   220,    -1,    -1,    -1,   224,    -1,   226,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   209,   210,   211,
      -1,   254,    -1,    -1,    -1,    -1,    -1,    -1,   220,    -1,
      -1,   264,   224,    -1,   226,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,    -1,    -1,    -1,    -1,   254,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   264,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,    -1,    -1,    -1,    -1,
     254,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     264,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,    -1,
      -1,    -1,    -1,   254,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   264,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,    -1,    -1,    -1,    -1,   254,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   264,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,    -1,    -1,    -1,    -1,   254,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   264,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,    -1,    -1,
      -1,    -1,   254,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   264,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,    -1,    -1,    -1,    -1,   254,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   264,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,    -1,    -1,    -1,    -1,   254,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   264,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,    -1,    -1,    -1,
      -1,   254,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   264,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
      -1,    -1,    -1,    -1,   254,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   264,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,    -1,    -1,    -1,    -1,   254,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   264,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,    -1,    -1,    -1,    -1,
     254,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     264,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,    -1,
      -1,    -1,    -1,   254,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   264,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,    -1,    -1,    -1,    -1,   254,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   264,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,    -1,    -1,    -1,    -1,   254,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   264,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,    -1,    -1,
      -1,    -1,   254,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   264,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,    -1,    -1,    -1,    -1,   254,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   264,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,    -1,    -1,    -1,    -1,   254,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   264,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,    -1,    -1,    -1,
      -1,   254,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   264,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
      -1,    -1,    -1,    -1,   254,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   264,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,    -1,    -1,    -1,    -1,   254,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   264,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,    -1,    -1,    -1,    -1,
     254,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     264,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,    -1,
      -1,    -1,    -1,   254,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   264,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,    -1,    -1,    -1,    -1,   254,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   264,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,    -1,    -1,    -1,    -1,   254,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   264,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,    -1,    -1,
      -1,    -1,   254,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   264,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,    -1,    -1,    -1,    -1,   254,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   264,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,    -1,    -1,    -1,    -1,   254,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   264,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,    -1,    -1,    -1,
      -1,   254,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   264,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
      -1,    -1,    -1,    -1,   254,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   264,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,    -1,    -1,    -1,    -1,   254,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   264,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,    -1,    -1,    -1,    -1,
     254,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     264,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,    -1,
      -1,    -1,    -1,   254,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   264,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,    -1,    -1,    -1,    -1,   254,    -1,    -1,    -1,
      -1,    -1,   260,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,    -1,    -1,    -1,    -1,   254,    -1,    -1,    -1,    -1,
      -1,   260,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
      -1,    -1,    -1,    -1,   254,    -1,    -1,    -1,    -1,    -1,
     260,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,    -1,
      -1,    -1,    -1,   254,    -1,    -1,    -1,    -1,    -1,   260,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,    -1,    -1,
      -1,    -1,   254,    -1,    -1,    -1,    -1,    -1,   260,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,    -1,    -1,    -1,
      -1,   254,    -1,    -1,    -1,    -1,    -1,   260,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,    -1,    -1,    -1,    -1,
     254,    -1,    -1,    -1,    -1,    -1,   260,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,    -1,    -1,    -1,    -1,   254,
      -1,    -1,    -1,    -1,    -1,   260,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,    -1,    -1,    -1,    -1,   254,    -1,
      -1,    -1,    -1,    -1,   260,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,    -1,    -1,    -1,    -1,   254,    -1,    -1,
      -1,    -1,    -1,   260,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,    -1,    -1,    -1,    -1,   254,    -1,    -1,    -1,
      -1,    -1,   260,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,    -1,    -1,    -1,    -1,   254,    -1,    -1,    -1,    -1,
      -1,   260,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
      -1,    -1,    -1,    -1,   254,    -1,    -1,    -1,    -1,    -1,
     260,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,    -1,
      -1,    -1,    -1,   254,    -1,    -1,    -1,    -1,    -1,   260,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,    -1,    -1,
      -1,    -1,   254,    -1,    -1,    -1,    -1,    -1,   260,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,    -1,    -1,    -1,
      -1,   254,    -1,    -1,    -1,    -1,    -1,   260,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,    -1,    -1,    -1,    -1,
     254,    -1,    -1,    -1,    -1,    -1,   260,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,    -1,    -1,    -1,    -1,   254,
      -1,    -1,    -1,    -1,    -1,   260,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,    -1,    -1,    -1,    -1,   254,    -1,
      -1,    -1,    -1,    -1,   260,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,    -1,    -1,    -1,    -1,   254,    -1,    -1,
      -1,    -1,    -1,   260,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,    -1,    -1,    -1,    -1,   254,    -1,    -1,    -1,
      -1,    -1,   260,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,    -1,    -1,    -1,    -1,   254,    -1,    -1,    -1,    -1,
      -1,   260,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
      -1,    -1,    -1,    -1,   254,    -1,    -1,    -1,    -1,    -1,
     260,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,    -1,
      -1,    -1,    -1,   254,    -1,    -1,    -1,    -1,    -1,   260,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,    -1,    -1,
      -1,    -1,   254,    -1,    -1,    -1,    -1,    -1,   260,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,    -1,    -1,    -1,
      -1,   254,    -1,    -1,    -1,    -1,    -1,   260,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,    -1,    -1,    -1,    -1,
     254,    -1,    -1,    -1,    -1,    -1,   260,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,    -1,    -1,    -1,    -1,   254,
      -1,    -1,    -1,    -1,    -1,   260,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,    -1,    -1,    -1,    -1,   254,    -1,
      -1,    -1,    -1,    -1,   260,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,    -1,    -1,    -1,    -1,   254,    -1,    -1,
      -1,    -1,   259,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,    -1,    -1,    -1,    -1,   254,    -1,   256,    -1,   258,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,    -1,    -1,
      -1,    -1,   254,    -1,    -1,    -1,   258,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,    -1,    -1,    -1,    -1,   254,
      -1,    -1,    -1,   258,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,    -1,    -1,    -1,    -1,   254,    -1,    -1,    -1,
     258,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,    -1,
      -1,    -1,    -1,   254,    -1,    -1,    -1,   258,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,    -1,    -1,    -1,    -1,
     254,    -1,    -1,    -1,   258,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,    -1,    -1,    -1,    -1,   254,    -1,    -1,
      -1,   258,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
      -1,    -1,    -1,    -1,   254,    -1,    -1,    -1,   258,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,    -1,    -1,    -1,
      -1,   254,    -1,    -1,    -1,   258,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,    -1,    -1,    -1,    -1,   254,    -1,
      -1,    -1,   258,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,    -1,    -1,    -1,    -1,   254,    -1,    -1,    -1,   258,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,    -1,    -1,
      -1,    -1,   254,    -1,    -1,    -1,   258,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,    -1,    -1,    -1,    -1,   254,
      -1,    -1,    -1,   258,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,    -1,    -1,    -1,    -1,   254,    -1,    -1,    -1,
     258,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,    -1,
      -1,    -1,    -1,   254,    -1,    -1,    -1,   258,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,    -1,    -1,    -1,    -1,
     254,    -1,    -1,    -1,   258,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,    -1,    -1,    -1,    -1,   254,    -1,   256,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,    -1,    -1,
      -1,    -1,   254,    -1,   256,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,    -1,    -1,    -1,    -1,   254,    -1,   256,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,    -1,    -1,
      -1,    -1,   254,    -1,   256,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,    -1,    -1,    -1,    -1,   254,    -1,   256,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,    -1,    -1,
      -1,    -1,   254,    -1,   256,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,    -1,    -1,    -1,    -1,   254,    -1,   256,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,    -1,    -1,
      -1,    -1,   254,    -1,   256,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,    -1,    -1,    -1,    -1,   254,    -1,   256,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,    -1,    -1,
      -1,    -1,   254,    -1,   256,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,    -1,    -1,    -1,    -1,   254,    -1,   256,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,    -1,    -1,
      -1,    -1,   254,    -1,   256,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,    -1,    -1,    -1,    -1,   254,    -1,   256,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,    -1,    -1,
      -1,    -1,   254,    -1,   256,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,    -1,    -1,    -1,    -1,   254,    -1,   256,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,    -1,    -1,
      -1,    -1,   254,    -1,   256,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,    -1,    -1,    -1,    -1,   254,    -1,   256,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,    -1,    -1,
      -1,    -1,   254,    -1,   256,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,    -1,    -1,    -1,    -1,   254,    -1,   256,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,    -1,    -1,
      -1,    -1,   254,    -1,   256,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,    -1,    -1,    -1,    -1,   254,    -1,   256,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,    -1,    -1,
      -1,    -1,   254,    -1,   256,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,    -1,    -1,    -1,    -1,   254,    -1,   256,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,    -1,    -1,
      -1,    -1,   254,    -1,   256,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,    -1,    -1,    -1,    -1,   254,    -1,   256,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,    -1,    -1,
      -1,    -1,   254,    -1,   256,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,    -1,    -1,    -1,    -1,   254,    -1,   256,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,    -1,    -1,
      -1,    -1,   254,    -1,   256,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,    -1,    -1,    -1,    -1,   254,    -1,   256,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,    -1,    -1,
      -1,    -1,   254,    -1,   256,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,    -1,    -1,    -1,    -1,   254,    -1,   256,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,    -1,    -1,
      -1,    -1,   254,    -1,   256,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,    -1,    -1,    -1,    -1,   254,    -1,   256,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,    -1,    -1,
      -1,    -1,   254,    -1,   256,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,    -1,    -1,    -1,    -1,   254,    -1,   256,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,    -1,    -1,
      -1,    -1,   254,    -1,   256,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,    -1,    -1,    -1,    -1,   254,    -1,   256,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,    -1,    -1,
      -1,    -1,   254,    -1,   256,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,    -1,    -1,    -1,    -1,   254,    -1,   256,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,    -1,    -1,
      -1,    -1,   254,    -1,   256,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,    -1,    -1,    -1,    -1,   254,    -1,   256,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,    -1,    -1,
      -1,    -1,   254,    -1,   256,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,    -1,    -1,    -1,    -1,   254,    -1,   256,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,    -1,    -1,
      -1,    -1,   254,    -1,   256,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,    -1,    -1,    -1,    -1,   254,    -1,   256,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,    -1,    -1,
      -1,    -1,   254,    -1,   256,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,    -1,    -1,    -1,    -1,   254,    -1,   256,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,    -1,    -1,
      -1,    -1,   254,    -1,   256,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,    -1,    -1,    -1,    -1,   254,    -1,   256,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,    -1,    -1,
      -1,    -1,   254,    -1,   256,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,    -1,    -1,    -1,    -1,   254,    -1,   256,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,    -1,    -1,
      -1,    -1,   254,    -1,   256,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,    -1,    -1,    -1,    -1,   254,    -1,   256,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,    -1,    -1,
      -1,    -1,   254,    -1,   256,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,    -1,    -1,    -1,    -1,   254,    -1,   256,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,    -1,    -1,
      -1,    -1,   254,    -1,   256,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,    -1,    -1,    -1,    -1,   254,    -1,   256,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,    -1,    -1,
      -1,    -1,   254,    -1,   256,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,    -1,    -1,    -1,    -1,   254,    -1,   256,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,    -1,    -1,
      -1,    -1,   254,    -1,   256,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,    -1,    -1,    -1,    -1,   254,    -1,   256,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,    -1,    -1,
      -1,    -1,   254,    -1,   256,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,    -1,    -1,    -1,    -1,   254,    -1,   256,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,    -1,    -1,
      -1,    -1,   254,    -1,   256,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,    -1,    -1,    -1,    -1,   254,    -1,   256,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,    -1,    -1,
      -1,    -1,   254,    -1,   256,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,    -1,    -1,    -1,    -1,   254,    -1,   256,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,    -1,    -1,
      -1,    -1,   254
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,   266,   267,     6,     0,     4,    13,    14,    46,
      47,    48,    67,    68,    69,    74,    75,    79,    84,    85,
      86,    87,    88,    90,    91,    93,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   116,   117,   118,   119,   120,   121,   123,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   143,   144,   145,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   173,   174,   175,   179,   184,   185,   186,   187,   190,
     192,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   214,   215,   216,   225,   227,
     268,   270,   271,   292,   311,   313,   317,   320,   321,   322,
     323,   324,   325,   326,   327,   328,   335,   337,   338,   344,
     345,   346,   347,   353,   377,   378,   259,   263,    14,   107,
     255,   255,   255,     6,   259,     6,     6,     6,     6,   255,
       6,     6,   259,     6,     6,   257,   257,     4,   355,   378,
     255,   257,   289,   101,   104,   107,   109,   289,   255,   255,
     255,     4,   255,   255,   255,     4,   255,   255,   255,   255,
     255,   255,   255,   255,   255,   255,   255,   259,   122,   107,
       6,     6,   259,   101,   104,   107,   120,   316,   109,   255,
       3,    10,    11,    12,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    58,    59,    60,    61,    66,
      67,    76,    77,    81,    82,    83,    92,    95,   101,   104,
     107,   109,   120,   131,   136,   138,   141,   208,   212,   213,
     217,   218,   219,   221,   222,   223,   243,   244,   250,   255,
     259,   262,   313,   314,   317,   328,   335,   337,   348,   349,
     353,   355,   361,   363,   378,   255,   259,   259,   107,   107,
     131,   104,   107,   109,   101,   104,   107,   109,   313,   104,
     107,   108,   109,   120,   185,   314,   104,   107,   255,   104,
     163,   190,   206,   207,   259,   243,   244,   255,   259,   358,
     359,   358,   259,   259,   358,     4,   101,   105,   111,   112,
     114,   115,   135,   259,   255,   107,   109,   107,   104,     4,
      93,   201,   259,   378,     4,     6,   101,   104,   107,   104,
     107,   120,   315,   107,   107,     4,     4,     4,     5,   255,
     259,   361,   362,     4,   255,   255,   255,     4,   259,   365,
     378,     4,   255,   255,   255,     6,     6,   257,     5,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    62,    63,
      64,    65,    70,    71,    72,    73,    78,    80,    94,    97,
     209,   210,   211,   220,   224,   226,   369,   378,   255,     4,
     369,     5,   259,     5,   259,    32,   244,   348,   378,   257,
     259,   255,   259,     6,   255,   259,     6,   263,     7,   138,
     201,   228,   229,   230,   231,   252,   253,   255,   257,   261,
     287,   288,   289,   313,   348,   368,   369,   378,     4,   317,
     318,   319,   259,     6,   348,   368,   369,   378,   368,   368,
     348,   368,   375,   376,   378,   348,   294,   298,   255,   357,
       9,   369,   255,   255,   255,   255,   378,   348,   348,   348,
     255,   348,   348,   348,   255,   348,   348,   348,   348,   348,
     348,   348,   368,   348,   348,   348,   348,   362,   255,   244,
     348,   363,   364,   259,   362,   361,   368,   289,   289,   289,
     289,   289,   289,   289,   289,   289,   289,   289,   289,   289,
     289,   289,   289,   289,   289,   289,   289,   289,   289,   289,
     289,   289,   255,   257,   289,   289,   289,   289,   289,   289,
     255,   289,   289,   255,   313,   314,   314,   289,   289,     5,
     259,   259,   131,   313,   313,   255,   289,   289,   255,   255,
     255,   348,   259,   348,   363,   348,   348,   260,   364,   355,
     378,   193,     5,   259,     8,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   254,     9,   255,   257,   261,   288,   289,
     348,   364,   364,   255,   255,   255,   361,   362,   362,   362,
     312,   255,   259,   255,   255,   361,   259,   259,   348,     4,
     361,   259,   365,   259,   259,   358,   358,   358,   348,   348,
     243,   244,   259,   259,   358,   243,   244,   255,   319,   358,
     259,   255,   259,   255,   255,   255,   255,   255,   255,   255,
     364,   348,   362,   362,   362,   255,     4,   257,   259,     6,
     257,   319,     6,     6,   259,   259,   259,   259,   362,   259,
     259,   257,   257,   257,   348,     8,     6,     6,   348,   348,
     348,   261,   348,   259,   193,   348,   348,   348,   348,   289,
     289,   289,   255,   255,   255,   289,   289,   289,   289,   289,
     289,   289,   289,   289,   289,   255,   255,   289,   255,   257,
       6,     6,   259,     6,     8,   319,     6,     8,   319,   289,
     348,   245,   259,     9,   255,   257,   261,   368,   364,   348,
     319,   361,   361,   259,   369,   313,     7,   348,   348,     4,
      36,    37,   110,   111,   190,   191,   291,   361,     6,   256,
     258,   259,   290,   259,     6,   259,     6,     9,   255,   257,
     261,   378,   260,   131,   136,   138,   139,   141,   311,   313,
     348,     6,   256,   264,     9,   255,   257,   261,   256,   264,
     256,   264,   264,   256,   264,     9,   255,   261,   264,   258,
     264,   293,   258,   293,    96,   356,   354,   378,   264,   348,
     348,   348,   348,   264,   256,   256,   256,   348,   256,   256,
     256,   348,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   260,     7,   348,   245,   260,   264,   348,
       6,     6,   256,   348,   348,   348,   348,   348,   348,   348,
     348,   348,   348,   348,   348,   348,   348,   348,   348,   348,
     363,   348,   348,   348,   348,   348,   348,   348,   348,   348,
     363,   363,   378,   259,   348,   348,   368,   348,   368,   361,
     368,   368,   375,   259,   259,   259,   348,   290,   378,     8,
     348,   348,   362,   361,   368,   368,   363,   355,   369,   355,
     364,   256,   260,   261,   289,    67,     8,   348,   348,   348,
     348,   348,   348,   348,   348,   348,   348,   348,   348,   348,
     348,   259,   348,   363,   348,   348,   348,   348,   348,   378,
     348,   348,   291,   259,   290,   256,   260,   260,   348,   348,
     348,     7,     7,   341,   341,   255,   348,   348,   348,   348,
       6,   364,   364,   259,   256,     6,   319,   259,   319,   319,
     264,   264,   264,   358,   358,   318,   318,   264,   348,   260,
     332,   264,   319,   348,   348,   348,   348,   348,   348,   348,
     348,   348,   260,   256,     7,   342,     6,     7,   348,     6,
     348,   319,   348,   260,   364,   364,   364,   348,     6,   364,
     364,   348,   348,   348,   256,   260,   256,   256,   256,   190,
     264,   319,   259,     8,   256,   256,   258,   375,   368,   375,
     368,   368,   368,   368,   368,   368,   348,   368,   368,   368,
     368,   262,   371,   378,   369,   368,   368,   368,   355,   378,
     364,   260,   260,   260,   260,   348,   348,   319,   378,   291,
     258,   260,   256,   145,   163,   336,   256,   260,   264,   348,
       6,   259,   361,   256,   258,   261,     7,     7,   287,   288,
       6,   364,     7,   231,   287,   348,   272,   378,   348,   348,
     291,   257,   255,   131,   313,   314,   313,   259,   260,     6,
     238,   239,   269,   364,   378,   348,   348,   291,     6,   364,
       6,   364,   348,     6,   368,   376,   378,   256,   291,   348,
       6,   378,     6,   368,   348,   256,   257,   348,   264,   264,
     264,   264,   369,     7,     7,     7,   256,     7,     7,     7,
     256,     7,     7,     7,     7,     7,     7,     7,     7,     7,
       7,   348,   256,   259,   348,   363,   260,     6,   290,   290,
     290,   290,   290,   290,   290,   290,   290,   290,   290,   264,
     290,   290,   290,   290,   290,   290,   290,   290,   290,   264,
     264,   264,   264,   264,   256,   258,   258,   364,   264,   264,
     290,   264,   290,   264,   264,   264,   256,   364,   348,   348,
     350,   290,   260,   260,   260,   264,   264,   290,   290,   256,
     261,   256,   261,   264,   289,   351,   260,     7,   291,   290,
     361,   260,     8,     8,   364,   261,   256,   258,   255,   257,
     288,   289,   364,     7,   259,   259,   256,   256,   256,   348,
     361,     4,   340,     6,   307,   348,   369,   256,   260,   256,
     256,   260,   260,   364,   261,   260,   319,   260,   260,   358,
     348,   348,   260,   260,   348,   358,   142,   142,   160,   170,
     171,   172,   176,   177,   333,   334,   358,   260,   329,   256,
     260,   256,   256,   256,   256,   256,   256,   256,   259,     7,
     348,     6,   348,   256,   258,   260,   258,   260,   260,   260,
     260,   260,   260,   258,   258,   264,     7,     7,     7,   261,
     348,   260,   348,   348,     7,   261,   290,   264,   290,   290,
     256,   256,   264,   290,   290,   264,   264,   290,   290,   290,
     290,   348,   290,     9,   370,   264,   256,   264,   290,   261,
     264,   352,   258,   260,   260,   261,   255,   257,   263,   193,
       7,   163,     6,   348,   260,   259,     6,   361,   260,   348,
       6,     7,   287,   288,   261,   287,   288,   291,   259,   366,
     378,   369,   348,     6,   260,    49,    49,   361,   260,     4,
     180,   181,   182,   183,   260,   275,   279,   282,   284,   285,
     327,   261,   256,   258,   255,   348,   348,   255,   259,   255,
     259,     8,   364,   368,   256,   261,   256,   258,   255,   256,
     256,   264,   261,   255,   264,     7,   289,     4,    36,    37,
     301,   302,   303,   290,   348,   348,   348,   348,   290,   358,
     361,   361,     7,   361,   361,   361,     7,   361,   361,   361,
     361,   361,   361,   361,   361,   361,   361,     6,     7,   364,
     348,   348,   348,   348,   348,   348,   260,   348,   348,   348,
     361,   368,   368,   260,   260,   260,   264,   300,   348,   348,
     291,   291,   348,   348,   256,   361,   289,   348,   348,   260,
     291,   288,   261,   288,   348,   348,   290,   260,   361,   364,
     364,     7,     7,     7,   142,   339,     6,   256,   264,     7,
       7,     7,     7,     7,   260,     4,   291,   260,   264,   264,
     264,   260,   260,   119,     4,     6,   348,   259,     6,   255,
       6,   178,     6,   178,   260,   334,   264,   333,     7,     6,
       7,     7,     7,     7,     7,     7,     7,   318,   361,     6,
     259,     6,     6,     6,   107,     7,     7,     7,     6,     6,
     348,   361,   361,   361,     4,   264,     8,     8,   256,   291,
     291,   364,   368,   348,   368,   262,   264,   304,   368,   368,
     291,   368,   256,   264,   291,   259,   313,   259,     6,   348,
       6,   259,   361,   260,   260,   348,     6,   190,   191,   291,
     348,     6,     7,   365,   367,     6,   257,     6,     6,   290,
     289,   289,     6,   276,   255,   255,   259,   286,     6,   291,
     261,   368,   348,   258,   256,   348,     8,   364,   348,   364,
     260,   260,     6,     6,   269,   291,   261,   348,     6,     6,
     348,   291,   256,   348,   259,   348,   369,   290,    49,   259,
     361,   369,   372,   348,   348,   258,   264,     6,   256,   256,
     256,   256,     6,     6,   135,   309,   309,   361,     6,     6,
       6,   361,   142,   193,   308,     6,     6,     6,     6,     6,
       6,     6,     6,     6,     5,   260,   290,   290,   290,   290,
     290,   290,   290,   264,   264,   264,   256,   290,   290,   302,
     290,   256,   290,   256,   289,   351,   290,     6,   290,   255,
     257,   289,   291,   256,   258,   290,     6,   260,   260,   361,
     361,   361,     4,     6,   287,   348,   361,   361,   361,   259,
     259,     7,     6,     7,   348,   348,   348,   259,   259,   259,
     257,     6,   348,   361,   348,     6,     6,   348,   358,   260,
       5,   361,   259,   259,   259,   259,   259,   259,   259,   361,
     260,     6,   364,   259,   348,   348,   348,   258,     6,     6,
     189,   348,   348,   348,     6,     6,     7,   290,   264,   264,
     290,   264,   348,     4,   205,   305,   306,   290,   256,   290,
     352,   369,   255,   257,   348,   259,   319,     6,   319,   264,
       6,     6,   261,     7,     7,   287,   288,     6,   365,   260,
     264,   348,   287,   259,   290,   373,   374,   375,   373,   255,
     348,   348,   360,   361,   259,   255,     4,     6,   256,     6,
     256,   260,   260,   256,   260,     6,     6,   368,   255,     4,
     256,   264,   255,   260,   264,   361,   369,     7,   289,   299,
     348,   363,   303,     6,     6,     6,     6,   358,     6,     6,
       6,   142,   310,   101,   120,   105,     6,     5,   259,   348,
     348,   348,   348,   256,   351,   348,   348,   290,   288,   259,
     259,     6,   308,     6,   348,   361,   142,   142,     4,     6,
     364,   364,   348,   348,   369,   260,   256,   260,   264,   318,
     318,   348,   348,   260,   264,   256,   260,   264,     6,     6,
     360,   358,   358,   358,   358,   358,   244,   358,     6,   260,
     348,     6,     6,     6,     6,   361,   260,   264,     8,   260,
     256,   259,   348,   369,   368,   348,   368,   348,   369,   372,
     374,   369,   264,   256,   264,   260,   348,   336,   336,   361,
     291,   366,   369,   348,     6,     6,   365,   258,   361,   375,
       6,   290,   290,   273,   348,   264,   264,   260,   264,   274,
     348,   348,     6,     6,     6,     6,   348,   348,   256,     6,
     348,   295,   297,   259,   374,   260,   264,     7,     7,   146,
       6,   259,   259,   259,     5,   360,   290,   290,   264,   290,
     256,   256,   258,   364,   364,     6,     6,   348,   348,   259,
     260,   260,   259,     6,     6,   259,   348,   260,   260,   260,
     258,     6,   361,     7,   259,   348,   260,   264,   264,   264,
     264,   264,   264,     6,   260,   188,   348,   348,   364,     6,
       6,   256,   290,   290,   306,   369,   260,   260,   260,   260,
       7,     6,     6,     6,   261,     6,   260,     6,     6,   256,
     264,   348,   348,   259,   361,   260,   264,   256,   256,   264,
     260,   300,   304,   361,   290,   348,   369,   378,   364,   364,
     348,     6,   260,   348,   351,   260,   260,     6,     6,   360,
     147,   148,   153,   343,   147,   148,   343,   364,   318,   260,
     264,     6,   260,   361,   319,   260,     6,   364,   358,   358,
     358,   358,   358,   348,   260,   260,   260,   256,     6,   259,
       6,   365,   191,   277,   348,   264,   264,   360,     6,   348,
     348,     6,   260,   260,   296,     7,   255,   260,   260,   260,
     259,   264,   256,   259,   260,   259,   358,   361,     6,   259,
     358,     6,   260,   260,   348,     6,   142,   260,   330,   259,
     260,   264,   264,   264,   264,   264,     6,     6,     6,   319,
       6,   259,   348,   348,   260,   264,   300,   369,   256,   348,
     348,   364,     6,   358,     6,   358,     6,     6,   260,   348,
     333,   319,     6,   364,   364,   364,   364,   358,   364,   336,
     274,   256,   264,     6,   259,   348,   260,   264,   264,   260,
     264,   264,     6,   260,   260,   331,   260,   260,   260,   260,
     264,   260,   260,   260,   280,   348,   360,   260,   348,   348,
     358,   358,   333,     6,     6,     6,     6,   364,     6,     6,
       6,   259,   256,   260,     6,   260,   290,   264,   264,   260,
     260,   278,   368,   283,   259,     6,   348,   348,     6,   260,
     264,   259,   360,   260,   260,     6,   368,   281,   368,   260,
       6,     6,   260,   264,     6,     6,   368
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
#line 272 "Gmsh.y"
    { yyerrok; return 1; ;}
    break;

  case 6:
#line 283 "Gmsh.y"
    { return 1; ;}
    break;

  case 7:
#line 284 "Gmsh.y"
    { return 1; ;}
    break;

  case 8:
#line 285 "Gmsh.y"
    { return 1; ;}
    break;

  case 9:
#line 287 "Gmsh.y"
    {
      gmsh_yyfactory = (yyvsp[(3) - (5)].c);
      if(gmsh_yyfactory == "OpenCASCADE"){
        if(!GModel::current()->getOCCInternals())
          GModel::current()->createOCCInternals();
        for(int dim = -2; dim <= 3; dim++)
          GModel::current()->getOCCInternals()->setMaxTag
            (dim, std::max(GModel::current()->getOCCInternals()->getMaxTag(dim),
                           GModel::current()->getGEOInternals()->getMaxTag(dim)));
      }
      else if(GModel::current()->getOCCInternals()){
        for(int dim = -2; dim <= 3; dim++)
          GModel::current()->getGEOInternals()->setMaxTag
            (dim, std::max(GModel::current()->getGEOInternals()->getMaxTag(dim),
                           GModel::current()->getOCCInternals()->getMaxTag(dim)));
      }
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 10:
#line 305 "Gmsh.y"
    { return 1; ;}
    break;

  case 11:
#line 306 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 12:
#line 307 "Gmsh.y"
    { return 1; ;}
    break;

  case 13:
#line 308 "Gmsh.y"
    { return 1; ;}
    break;

  case 14:
#line 309 "Gmsh.y"
    { return 1; ;}
    break;

  case 15:
#line 310 "Gmsh.y"
    { return 1; ;}
    break;

  case 16:
#line 311 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 17:
#line 312 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 18:
#line 313 "Gmsh.y"
    { return 1; ;}
    break;

  case 19:
#line 314 "Gmsh.y"
    { return 1; ;}
    break;

  case 20:
#line 315 "Gmsh.y"
    { return 1; ;}
    break;

  case 21:
#line 316 "Gmsh.y"
    { return 1; ;}
    break;

  case 22:
#line 317 "Gmsh.y"
    { return 1; ;}
    break;

  case 23:
#line 318 "Gmsh.y"
    { return 1; ;}
    break;

  case 24:
#line 319 "Gmsh.y"
    { return 1; ;}
    break;

  case 25:
#line 320 "Gmsh.y"
    { return 1; ;}
    break;

  case 26:
#line 325 "Gmsh.y"
    {
      (yyval.c) = (char*)"w";
    ;}
    break;

  case 27:
#line 329 "Gmsh.y"
    {
      (yyval.c) = (char*)"a";
    ;}
    break;

  case 28:
#line 336 "Gmsh.y"
    {
      Msg::Direct((yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 29:
#line 341 "Gmsh.y"
    {
      Msg::Warning((yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 30:
#line 346 "Gmsh.y"
    {
      Msg::Error((yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 31:
#line 351 "Gmsh.y"
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

  case 32:
#line 365 "Gmsh.y"
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

  case 33:
#line 378 "Gmsh.y"
    {
      char tmpstring[5000];
      int i = printListOfDouble((yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].l), tmpstring);
      if(i < 0)
	yymsg(1, "Too few arguments in Error");
      else if(i > 0)
	yymsg(1, "%d extra argument%s in Error", i, (i > 1) ? "s" : "");
      else
	Msg::Warning(tmpstring);
      Free((yyvsp[(3) - (7)].c));
      List_Delete((yyvsp[(5) - (7)].l));
    ;}
    break;

  case 34:
#line 391 "Gmsh.y"
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

  case 35:
#line 404 "Gmsh.y"
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

  case 36:
#line 432 "Gmsh.y"
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

  case 37:
#line 446 "Gmsh.y"
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

  case 38:
#line 459 "Gmsh.y"
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

  case 39:
#line 472 "Gmsh.y"
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

  case 40:
#line 490 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData = new PViewDataList();
#endif
    ;}
    break;

  case 47:
#line 505 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(1) - (1)].d)); ;}
    break;

  case 48:
#line 507 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(3) - (3)].d)); ;}
    break;

  case 49:
#line 512 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(1) - (1)].d)); ;}
    break;

  case 50:
#line 514 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(3) - (3)].d)); ;}
    break;

  case 51:
#line 519 "Gmsh.y"
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

  case 52:
#line 623 "Gmsh.y"
    {
#if defined(HAVE_POST)
      if(ViewValueList){
	for(int i = 0; i < 3; i++)
	  for(std::size_t j = 0; j < ViewCoord.size() / 3; j++)
	    ViewValueList->push_back(ViewCoord[3 * j + i]);
      }
#endif
    ;}
    break;

  case 53:
#line 633 "Gmsh.y"
    {
#if defined(HAVE_POST)
      if(ViewValueList) (*ViewNumList)++;
#endif
    ;}
    break;

  case 54:
#line 642 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[(1) - (1)].c)[i]);
#endif
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 55:
#line 649 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[(3) - (3)].c)[i]);
#endif
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 56:
#line 659 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->T2D.push_back((yyvsp[(3) - (8)].d));
      ViewData->T2D.push_back((yyvsp[(5) - (8)].d));
      ViewData->T2D.push_back((yyvsp[(7) - (8)].d));
      ViewData->T2D.push_back(ViewData->T2C.size());
#endif
    ;}
    break;

  case 57:
#line 668 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->NbT2++;
#endif
    ;}
    break;

  case 58:
#line 677 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[(1) - (1)].c)[i]);
#endif
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 59:
#line 684 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[(3) - (3)].c)[i]);
#endif
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 60:
#line 694 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->T3D.push_back((yyvsp[(3) - (10)].d)); ViewData->T3D.push_back((yyvsp[(5) - (10)].d));
      ViewData->T3D.push_back((yyvsp[(7) - (10)].d)); ViewData->T3D.push_back((yyvsp[(9) - (10)].d));
      ViewData->T3D.push_back(ViewData->T3C.size());
#endif
    ;}
    break;

  case 61:
#line 702 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->NbT3++;
#endif
    ;}
    break;

  case 62:
#line 712 "Gmsh.y"
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

  case 63:
#line 731 "Gmsh.y"
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

  case 64:
#line 750 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewValueList = &ViewData->Time;
#endif
    ;}
    break;

  case 65:
#line 756 "Gmsh.y"
    {
    ;}
    break;

  case 66:
#line 763 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 67:
#line 764 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 68:
#line 765 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 69:
#line 766 "Gmsh.y"
    { (yyval.i) = 3; ;}
    break;

  case 70:
#line 767 "Gmsh.y"
    { (yyval.i) = 4; ;}
    break;

  case 71:
#line 771 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 72:
#line 772 "Gmsh.y"
    { (yyval.i) = -1; ;}
    break;

  case 73:
#line 778 "Gmsh.y"
    { (yyval.c) = (char*)"("; ;}
    break;

  case 74:
#line 778 "Gmsh.y"
    { (yyval.c) = (char*)"["; ;}
    break;

  case 75:
#line 780 "Gmsh.y"
    { (yyval.c) = (char*)")"; ;}
    break;

  case 76:
#line 780 "Gmsh.y"
    { (yyval.c) = (char*)"]"; ;}
    break;

  case 77:
#line 785 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 78:
#line 786 "Gmsh.y"
    { (yyval.c) = (char *)Malloc(4 * sizeof(char)); strcpy((yyval.c), "Min"); ;}
    break;

  case 79:
#line 787 "Gmsh.y"
    { (yyval.c) = (char *)Malloc(4 * sizeof(char)); strcpy((yyval.c), "Max"); ;}
    break;

  case 80:
#line 788 "Gmsh.y"
    { (yyval.c) = (char *)Malloc(4 * sizeof(char)); strcpy((yyval.c), "Box"); ;}
    break;

  case 81:
#line 789 "Gmsh.y"
    { (yyval.c) = (char *)Malloc(9 * sizeof(char)); strcpy((yyval.c), "Cylinder"); ;}
    break;

  case 85:
#line 799 "Gmsh.y"
    {
      Msg::SetOnelabNumber((yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].d));
      Free((yyvsp[(3) - (7)].c));
    ;}
    break;

  case 86:
#line 804 "Gmsh.y"
    {
      Msg::SetOnelabString((yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].c));
      Free((yyvsp[(3) - (7)].c));
      Free((yyvsp[(5) - (7)].c));
    ;}
    break;

  case 87:
#line 810 "Gmsh.y"
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

  case 88:
#line 872 "Gmsh.y"
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

  case 89:
#line 887 "Gmsh.y"
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
#line 916 "Gmsh.y"
    {
      assignVariables((yyvsp[(1) - (9)].c), (yyvsp[(4) - (9)].l), (yyvsp[(7) - (9)].i), (yyvsp[(8) - (9)].l));
      Free((yyvsp[(1) - (9)].c));
      List_Delete((yyvsp[(4) - (9)].l));
      List_Delete((yyvsp[(8) - (9)].l));
    ;}
    break;

  case 91:
#line 926 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    ;}
    break;

  case 92:
#line 931 "Gmsh.y"
    {
      incrementVariable((yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].i));
      Free((yyvsp[(1) - (6)].c));
    ;}
    break;

  case 93:
#line 939 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    ;}
    break;

  case 94:
#line 944 "Gmsh.y"
    {
      incrementVariable((yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].i));
      Free((yyvsp[(1) - (6)].c));
    ;}
    break;

  case 95:
#line 952 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[(1) - (4)].c)] = std::vector<std::string>(1, (yyvsp[(3) - (4)].c));
      Free((yyvsp[(1) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 96:
#line 961 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[(1) - (8)].c)] = std::vector<std::string>();
      Free((yyvsp[(1) - (8)].c));
    ;}
    break;

  case 97:
#line 966 "Gmsh.y"
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
#line 978 "Gmsh.y"
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
#line 995 "Gmsh.y"
    {
      std::string tmp((yyvsp[(5) - (6)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (6)].c), 0, (yyvsp[(3) - (6)].c), tmp);
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 100:
#line 1001 "Gmsh.y"
    {
      std::string tmp((yyvsp[(8) - (9)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (9)].c), (int)(yyvsp[(3) - (9)].d), (yyvsp[(6) - (9)].c), tmp);
      Free((yyvsp[(1) - (9)].c)); Free((yyvsp[(6) - (9)].c)); Free((yyvsp[(8) - (9)].c));
    ;}
    break;

  case 101:
#line 1010 "Gmsh.y"
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

  case 102:
#line 1028 "Gmsh.y"
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

  case 103:
#line 1046 "Gmsh.y"
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(3) - (5)].c), d)){
	d += (yyvsp[(4) - (5)].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (5)].c), 0, (yyvsp[(3) - (5)].c), d);
      }
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 104:
#line 1055 "Gmsh.y"
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[(1) - (8)].c), (int)(yyvsp[(3) - (8)].d), (yyvsp[(6) - (8)].c), d)){
	d += (yyvsp[(7) - (8)].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (8)].c), (int)(yyvsp[(3) - (8)].d), (yyvsp[(6) - (8)].c), d);
      }
      Free((yyvsp[(1) - (8)].c)); Free((yyvsp[(6) - (8)].c));
    ;}
    break;

  case 105:
#line 1067 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (8)].c), 0, (yyvsp[(5) - (8)].c), (yyvsp[(7) - (8)].u));
      Free((yyvsp[(1) - (8)].c)); Free((yyvsp[(5) - (8)].c));
    ;}
    break;

  case 106:
#line 1072 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (11)].c), (int)(yyvsp[(3) - (11)].d), (yyvsp[(8) - (11)].c), (yyvsp[(10) - (11)].u));
      Free((yyvsp[(1) - (11)].c)); Free((yyvsp[(8) - (11)].c));
    ;}
    break;

  case 107:
#line 1080 "Gmsh.y"
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

  case 108:
#line 1100 "Gmsh.y"
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

  case 109:
#line 1123 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(4) - (5)].l), tags);
      if(!strcmp((yyvsp[(1) - (5)].c),"Background")) {
	if (tags.size() > 1)
	  yymsg(0, "Only 1 field can be set as a background field.");
	else if (tags.size() == 0)
	  yymsg(1, "No field given (Background Field).");
	else
	  GModel::current()->getFields()->setBackgroundFieldId((int)tags[0]);
	  }
      else if(!strcmp((yyvsp[(1) - (5)].c),"BoundaryLayer"))
	GModel::current()->getFields()->addBoundaryLayerFieldId(tags);
      else
	yymsg(0, "Unknown command '%s Field'", (yyvsp[(1) - (5)].c));
#endif
      Free((yyvsp[(1) - (5)].c));
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 110:
#line 1143 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      if(!GModel::current()->getFields()->newField((int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c)))
	yymsg(0, "Cannot create field %i of type '%s'", (int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c));
#endif
      Free((yyvsp[(6) - (7)].c));
    ;}
    break;

  case 111:
#line 1151 "Gmsh.y"
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

  case 112:
#line 1173 "Gmsh.y"
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

  case 113:
#line 1196 "Gmsh.y"
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

  case 114:
#line 1234 "Gmsh.y"
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

  case 115:
#line 1255 "Gmsh.y"
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

  case 116:
#line 1267 "Gmsh.y"
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

  case 120:
#line 1285 "Gmsh.y"
    {
      std::string key((yyvsp[(3) - (3)].c));
      std::vector<double> val(1, 0.);
      if(!gmsh_yysymbols.count(key)){
        gmsh_yysymbols[key].value = val;
      }
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 121:
#line 1294 "Gmsh.y"
    {
      std::string key((yyvsp[(3) - (5)].c));
      std::vector<double> val(1, (yyvsp[(5) - (5)].d));
      if(!gmsh_yysymbols.count(key)){
        gmsh_yysymbols[key].value = val;
      }
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 122:
#line 1303 "Gmsh.y"
    { init_options(); ;}
    break;

  case 123:
#line 1305 "Gmsh.y"
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
      List_Delete((yyvsp[(6) - (9)].l));
    ;}
    break;

  case 124:
#line 1323 "Gmsh.y"
    { init_options(); ;}
    break;

  case 125:
#line 1325 "Gmsh.y"
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
      List_Delete((yyvsp[(8) - (11)].l));
    ;}
    break;

  case 126:
#line 1341 "Gmsh.y"
    {
      std::string key((yyvsp[(3) - (5)].c)), val((yyvsp[(5) - (5)].c));
      if(!gmsh_yystringsymbols.count(key)){
        gmsh_yystringsymbols[key] = std::vector<std::string>(1, val);
      }
      Free((yyvsp[(3) - (5)].c));
      Free((yyvsp[(5) - (5)].c));
    ;}
    break;

  case 127:
#line 1350 "Gmsh.y"
    { init_options(); ;}
    break;

  case 128:
#line 1352 "Gmsh.y"
    {
      std::string key((yyvsp[(3) - (9)].c)), val((yyvsp[(6) - (9)].c));
      if(!gmsh_yystringsymbols.count(key)){
        Msg::ExchangeOnelabParameter(key, val, floatOptions, charOptions);
        gmsh_yystringsymbols[key] = std::vector<std::string>(1, val);
      }
      Free((yyvsp[(3) - (9)].c));
      Free((yyvsp[(6) - (9)].c));
    ;}
    break;

  case 130:
#line 1366 "Gmsh.y"
    {
      std::string name((yyvsp[(3) - (3)].c));
      Msg::UndefineOnelabParameter(name);
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 131:
#line 1374 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(doubleXstring));
      doubleXstring v = {(yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].c)};
      List_Add((yyval.l), &v);
    ;}
    break;

  case 132:
#line 1380 "Gmsh.y"
    {
      doubleXstring v = {(yyvsp[(3) - (5)].d), (yyvsp[(5) - (5)].c)};
      List_Add((yyval.l), &v);
    ;}
    break;

  case 133:
#line 1385 "Gmsh.y"
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
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 140:
#line 1428 "Gmsh.y"
    {
      std::string key((yyvsp[(1) - (2)].c));
      for(int i = 0; i < List_Nbr((yyvsp[(2) - (2)].l)); i++){
        double v;
        List_Read((yyvsp[(2) - (2)].l), i, &v);
        floatOptions[key].push_back(v);
        if (flag_Enum && !i) { member_ValMax = (int)v; }
      }
      Free((yyvsp[(1) - (2)].c));
      List_Delete((yyvsp[(2) - (2)].l));
    ;}
    break;

  case 141:
#line 1440 "Gmsh.y"
    {
      floatOptions["Min"].push_back((yyvsp[(2) - (2)].d));
    ;}
    break;

  case 142:
#line 1444 "Gmsh.y"
    {
      floatOptions["Max"].push_back((yyvsp[(2) - (2)].d));
    ;}
    break;

  case 143:
#line 1448 "Gmsh.y"
    {
      std::string key((yyvsp[(1) - (1)].c));
      double v;
      if (!flag_Enum) {
        v = 1.;
        if (key == "Enum") flag_Enum = 1;
      }
      else
        v = (double)++member_ValMax;
      floatOptions[key].push_back(v);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 144:
#line 1461 "Gmsh.y"
    {
      std::string key((yyvsp[(1) - (4)].c));
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
        doubleXstring v;
        List_Read((yyvsp[(3) - (4)].l), i, &v);
        floatOptions[key].push_back(v.d);
        charOptions[key].push_back(v.s);
      }
      Free((yyvsp[(1) - (4)].c));
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++)
        Free(((doubleXstring*)List_Pointer((yyvsp[(3) - (4)].l), i))->s);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 145:
#line 1475 "Gmsh.y"
    {
      std::string key((yyvsp[(1) - (2)].c));
      std::string val((yyvsp[(2) - (2)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(1) - (2)].c));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 146:
#line 1483 "Gmsh.y"
    {
      std::string key((yyvsp[(1) - (2)].c));
      for(int i = 0; i < List_Nbr((yyvsp[(2) - (2)].l)); i++){
        char *v;
        List_Read((yyvsp[(2) - (2)].l), i, &v);
        charOptions[key].push_back(v);
      }
      Free((yyvsp[(1) - (2)].c));
      List_Delete((yyvsp[(2) - (2)].l));
    ;}
    break;

  case 151:
#line 1508 "Gmsh.y"
    {
      std::string key((yyvsp[(1) - (2)].c));
      double val = (yyvsp[(2) - (2)].d);
      floatOptions[key].push_back(val);
      Free((yyvsp[(1) - (2)].c));
    ;}
    break;

  case 152:
#line 1516 "Gmsh.y"
    {
      std::string key((yyvsp[(1) - (2)].c));
      std::string val((yyvsp[(2) - (2)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(1) - (2)].c));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 153:
#line 1525 "Gmsh.y"
    {
      std::string key("Macro");
      std::string val((yyvsp[(2) - (2)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 154:
#line 1533 "Gmsh.y"
    {
      std::string key((yyvsp[(1) - (2)].c));
      for(int i = 0; i < List_Nbr((yyvsp[(2) - (2)].l)); i++){
        char *s;
        List_Read((yyvsp[(2) - (2)].l), i, &s);
        std::string val(s);
        Free(s);
        charOptions[key].push_back(val);
      }
      Free((yyvsp[(1) - (2)].c));
      List_Delete((yyvsp[(2) - (2)].l));
    ;}
    break;

  case 155:
#line 1547 "Gmsh.y"
    {
      std::string key((yyvsp[(1) - (2)].c));
      for(int i = 0; i < List_Nbr((yyvsp[(2) - (2)].l)); i++){
        char *s;
        List_Read((yyvsp[(2) - (2)].l), i, &s);
        std::string val(s);
        Free(s);
        charOptions[key].push_back(val);
      }
      Free((yyvsp[(1) - (2)].c));
      List_Delete((yyvsp[(2) - (2)].l));
    ;}
    break;

  case 156:
#line 1565 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    ;}
    break;

  case 157:
#line 1569 "Gmsh.y"
    {
      int t = GModel::current()->getGEOInternals()->getMaxPhysicalTag();
      GModel::current()->getGEOInternals()->setMaxPhysicalTag(t + 1);
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (1)].c)), dim_entity, t + 1);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 158:
#line 1576 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (3)].c)), dim_entity, (yyvsp[(3) - (3)].d));
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 159:
#line 1584 "Gmsh.y"
    {
      (yyval.l) = 0;
    ;}
    break;

  case 160:
#line 1588 "Gmsh.y"
    {
      (yyval.l) = List_Create(1, 1, sizeof(double));
      double p = (yyvsp[(4) - (5)].d);
      List_Add((yyval.l), &p);
    ;}
    break;

  case 161:
#line 1594 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
    ;}
    break;

  case 162:
#line 1598 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      double flag = -1;
      List_Add((yyval.l), &flag);
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++)
        List_Add((yyval.l), List_Pointer((yyvsp[(4) - (5)].l), i));
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 163:
#line 1609 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = 0.;
    ;}
    break;

  case 164:
#line 1613 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 165:
#line 1619 "Gmsh.y"
    {
      (yyval.d) = 0;
    ;}
    break;

  case 166:
#line 1623 "Gmsh.y"
    {
      (yyval.d) = 1;
    ;}
    break;

  case 167:
#line 1629 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      double x = CTX::instance()->geom.scalingFactor * (yyvsp[(6) - (7)].v)[0];
      double y = CTX::instance()->geom.scalingFactor * (yyvsp[(6) - (7)].v)[1];
      double z = CTX::instance()->geom.scalingFactor * (yyvsp[(6) - (7)].v)[2];
      double lc = CTX::instance()->geom.scalingFactor * (yyvsp[(6) - (7)].v)[3];
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        r = GModel::current()->getOCCInternals()->addVertex(num, x, y, z, lc);
      }
      else{
        if(!myGmshSurface)
          r = GModel::current()->getGEOInternals()->addVertex(num, x, y, z, lc);
        else
          r = GModel::current()->getGEOInternals()->addVertex(num, x, y,
                                                              myGmshSurface, lc);
      }
      if(!r) yymsg(0, "Could not add point");
      AddToTemporaryBoundingBox(x, y, z);
      (yyval.s).Type = MSH_POINT;
      (yyval.s).Num = num;
    ;}
    break;

  case 168:
#line 1652 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(6) - (7)].l), tags);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        r = GModel::current()->getOCCInternals()->addLine(num, tags);
      }
      else{
        r = GModel::current()->getGEOInternals()->addLine(num, tags);
      }
      if(!r) yymsg(0, "Could not add line");
      List_Delete((yyvsp[(6) - (7)].l));
      (yyval.s).Type = MSH_SEGM_LINE;
      (yyval.s).Num = num;
    ;}
    break;

  case 169:
#line 1668 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(6) - (7)].l), tags);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        r = GModel::current()->getOCCInternals()->addSpline(num, tags);
      }
      else{
        r = GModel::current()->getGEOInternals()->addSpline(num, tags);
      }
      if(!r) yymsg(0, "Could not add spline");
      List_Delete((yyvsp[(6) - (7)].l));
      (yyval.s).Type = MSH_SEGM_SPLN;
      (yyval.s).Num = num;
    ;}
    break;

  case 170:
#line 1684 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (10)].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(7) - (10)].l), tags);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        yymsg(0, "Compound spline only available with built-in geometry kernel");
      }
      else{
        r = GModel::current()->getGEOInternals()->addCompoundSpline(num, tags,
                                                                    (int)(yyvsp[(9) - (10)].d));
      }
      if(!r) yymsg(0, "Could not add compound spline");
      List_Delete((yyvsp[(7) - (10)].l));
      (yyval.s).Type = MSH_SEGM_SPLN;
      (yyval.s).Num = num;
    ;}
    break;

  case 171:
#line 1701 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (10)].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(7) - (10)].l), tags);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        yymsg(0, "Compound spline only available with built-in geometry kernel");
      }
      else{
        r = GModel::current()->getGEOInternals()->addCompoundBSpline(num, tags,
                                                                     (int)(yyvsp[(9) - (10)].d));
      }
      if(!r) yymsg(0, "Could not add compound spline");
      List_Delete((yyvsp[(7) - (10)].l));
      (yyval.s).Type = MSH_SEGM_BSPLN;
      (yyval.s).Num = num;
    ;}
    break;

  case 172:
#line 1718 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (8)].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(6) - (8)].l), tags);
      std::vector<double> param; ListOfDouble2Vector((yyvsp[(6) - (8)].l), param);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        if(tags.size() == 3){
          r = GModel::current()->getOCCInternals()->addCircleArc
            (num, tags[0], tags[1], tags[2]);
        }
        else if(param.size() >= 4 && param.size() <= 6){
          double r = param[3];
          double a1 = (param.size() == 6) ? param[4] : 0.;
          double a2 = (param.size() == 6) ? param[5] :
            (param.size() == 5) ? param[4] : 2.*M_PI;
          r = GModel::current()->getOCCInternals()->addCircle
            (num, param[0], param[1], param[2], r, a1, a2);
        }
        else{
          yymsg(0, "Circle requires 3 points or 4 to 6 parameters");
        }
      }
      else{
        if(tags.size() == 3){
          r = GModel::current()->getGEOInternals()->addCircleArc
            (num, tags[0], tags[1], tags[2], (yyvsp[(7) - (8)].v)[0], (yyvsp[(7) - (8)].v)[1], (yyvsp[(7) - (8)].v)[2]);
        }
        else{
          yymsg(0, "Circle requires 3 points");
        }
      }
      if(!r) yymsg(0, "Could not add circle");
      List_Delete((yyvsp[(6) - (8)].l));
      (yyval.s).Type = MSH_SEGM_CIRC;
      (yyval.s).Num = num;
    ;}
    break;

  case 173:
#line 1755 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (8)].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(6) - (8)].l), tags);
      std::vector<double> param; ListOfDouble2Vector((yyvsp[(6) - (8)].l), param);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        if(tags.size() == 3){ // keep this for backward compatibility
          r = GModel::current()->getOCCInternals()->addEllipseArc
            (num, tags[0], tags[1], tags[0], tags[2]);
        }
        else if(tags.size() == 4){
          r = GModel::current()->getOCCInternals()->addEllipseArc
            (num, tags[0], tags[1], tags[2], tags[3]);
        }
        else if(param.size() >= 5 && param.size() <= 7){
          double a1 = (param.size() == 7) ? param[5] : 0.;
          double a2 = (param.size() == 7) ? param[6] :
            (param.size() == 6) ? param[5] : 2.*M_PI;
          r = GModel::current()->getOCCInternals()->addEllipse
            (num, param[0], param[1], param[2], param[3], param[4], a1, a2);
        }
        else{
          yymsg(0, "Ellipse requires 4 points, or 5 to 7 parameters");
        }
      }
      else{
        if(tags.size() == 3){ // to match occ
          r = GModel::current()->getGEOInternals()->addEllipseArc
            (num, tags[0], tags[1], tags[0], tags[2], (yyvsp[(7) - (8)].v)[0], (yyvsp[(7) - (8)].v)[1], (yyvsp[(7) - (8)].v)[2]);
        }
        else if(tags.size() == 4){
          r = GModel::current()->getGEOInternals()->addEllipseArc
            (num, tags[0], tags[1], tags[2], tags[3], (yyvsp[(7) - (8)].v)[0], (yyvsp[(7) - (8)].v)[1], (yyvsp[(7) - (8)].v)[2]);
        }
        else{
          yymsg(0, "Ellipse requires 4 points");
        }
      }
      if(!r) yymsg(0, "Could not add ellipse");
      List_Delete((yyvsp[(6) - (8)].l));
      (yyval.s).Type = MSH_SEGM_ELLI;
      (yyval.s).Num = num;
    ;}
    break;

  case 174:
#line 1799 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(6) - (7)].l), tags);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        r = GModel::current()->getOCCInternals()->addBSpline(num, tags);
      }
      else{
        r = GModel::current()->getGEOInternals()->addBSpline(num, tags);
      }
      if(!r) yymsg(0, "Could not add BSpline");
      List_Delete((yyvsp[(6) - (7)].l));
      (yyval.s).Type = MSH_SEGM_BSPLN;
      (yyval.s).Num = num;
    ;}
    break;

  case 175:
#line 1815 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(6) - (7)].l), tags);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        r = GModel::current()->getOCCInternals()->addBezier(num, tags);
      }
      else{
        r = GModel::current()->getGEOInternals()->addBezier(num, tags);
      }
      if(!r) yymsg(0, "Could not add Bezier");
      List_Delete((yyvsp[(6) - (7)].l));
      (yyval.s).Type = MSH_SEGM_BEZIER;
      (yyval.s).Num = num;
    ;}
    break;

  case 176:
#line 1832 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (11)].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(6) - (11)].l), tags);
      std::vector<double> seqknots; ListOfDouble2Vector((yyvsp[(8) - (11)].l), seqknots);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        int degree = (int)(yyvsp[(10) - (11)].d);
        std::vector<double> weights, knots;
        std::vector<int> mults;
        for(std::size_t i = 0; i < seqknots.size(); i++){
          if(!i || (i && fabs(seqknots[i] - seqknots[i - 1]) > 1e-12)){
            knots.push_back(seqknots[i]);
            mults.push_back(1);
          }
          else{
            mults.back() += 1;
          }
        }
        r = GModel::current()->getOCCInternals()->addBSpline
          (num, tags, degree, weights, knots, mults);
      }
      else{
        r = GModel::current()->getGEOInternals()->addBSpline(num, tags, seqknots);
      }
      if(!r) yymsg(0, "Could not add nurbs");
      List_Delete((yyvsp[(6) - (11)].l));
      List_Delete((yyvsp[(8) - (11)].l));
      (yyval.s).Type = MSH_SEGM_NURBS;
      (yyval.s).Num = num;
    ;}
    break;

  case 177:
#line 1863 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(6) - (7)].l), tags);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        r = GModel::current()->getOCCInternals()->addWire(num, tags, false);
      }
      else{
        yymsg(0, "Wire only available with OpenCASCADE geometry kernel");
      }
      if(!r) yymsg(0, "Could not add wire");
      List_Delete((yyvsp[(6) - (7)].l));
      (yyval.s).Type = MSH_SEGM_LOOP;
      (yyval.s).Num = num;
    ;}
    break;

  case 178:
#line 1879 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(7) - (8)].l), tags);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        r = GModel::current()->getOCCInternals()->addLineLoop(num, tags);
      }
      else{
        r = GModel::current()->getGEOInternals()->addLineLoop(num, tags);
      }
      if(!r) yymsg(0, "Could not add line loop");
      List_Delete((yyvsp[(7) - (8)].l));
      Free((yyvsp[(2) - (8)].c));
      (yyval.s).Type = MSH_SEGM_LOOP;
      (yyval.s).Num = num;
    ;}
    break;

  case 179:
#line 1896 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(7) - (8)].l), tags);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        r = GModel::current()->getOCCInternals()->addPlaneSurface(num, tags);
      }
      else{
        r = GModel::current()->getGEOInternals()->addPlaneSurface(num, tags);
      }
      if(!r) yymsg(0, "Could not add plane surface");
      List_Delete((yyvsp[(7) - (8)].l));
      (yyval.s).Type = MSH_SURF_PLAN;
      (yyval.s).Num = num;
    ;}
    break;

  case 180:
#line 1912 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (8)].d);
      std::vector<int> wires; ListOfDouble2Vector((yyvsp[(6) - (8)].l), wires);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        if(wires.size() != 1){
          yymsg(0, "OpenCASCADE surface filling requires a single line loop");
        }
        else{
          std::vector<int> constraints; ListOfDouble2Vector((yyvsp[(7) - (8)].l), constraints);
          std::vector<int> points, surfaces, continuity;
          if(constraints.size() >= 3 && constraints[0] < 0){
            // {-1, type, ent, type, ent, ...}
            for(std::size_t i = 2; i < constraints.size(); i+=2){
              int type = constraints[i - 1];
              if(type == 0){
                points.push_back(constraints[i]);
              }
              else if(type == 1 || type == 2){
                surfaces.push_back(constraints[i]);
                continuity.push_back(type);
              }
              else
                yymsg(0, "Unknown type of constraint for surface filling");
            }
          }
          else if(constraints.size() > 0){
            // {point, point, ...}
            points = constraints;
          }
          r = GModel::current()->getOCCInternals()->addSurfaceFilling
            (num, wires[0], points, surfaces, continuity);
        }
      }
      else{
        int sphereCenter = -1;
        if(List_Nbr((yyvsp[(7) - (8)].l)) == 1){
          double d; List_Read((yyvsp[(7) - (8)].l), 0, &d);
          sphereCenter = (int)d;
        }
        r = GModel::current()->getGEOInternals()->addSurfaceFilling
          (num, wires, sphereCenter);
      }
      if(!r) yymsg(0, "Could not add surface");
      List_Delete((yyvsp[(6) - (8)].l));
      List_Delete((yyvsp[(7) - (8)].l));
      (yyval.s).Type = MSH_SURF_REGL;
      (yyval.s).Num = num;
    ;}
    break;

  case 181:
#line 1962 "Gmsh.y"
    {
      yymsg(2, "'Ruled Surface' command is deprecated: use 'Surface' instead");
      int num = (int)(yyvsp[(4) - (9)].d);
      std::vector<int> wires; ListOfDouble2Vector((yyvsp[(7) - (9)].l), wires);
      int sphereCenter = -1;
      if(List_Nbr((yyvsp[(8) - (9)].l)) == 1){
        double d; List_Read((yyvsp[(8) - (9)].l), 0, &d);
        sphereCenter = (int)d;
      }
      bool r = GModel::current()->getGEOInternals()->addSurfaceFilling
        (num, wires, sphereCenter);
      if(!r) yymsg(0, "Could not add surface");
      List_Delete((yyvsp[(7) - (9)].l));
      List_Delete((yyvsp[(8) - (9)].l));
      (yyval.s).Type =  MSH_SURF_REGL;
      (yyval.s).Num = num;
    ;}
    break;

  case 182:
#line 1980 "Gmsh.y"
    {
      myGmshSurface = 0;
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 183:
#line 1986 "Gmsh.y"
    {
      myGmshSurface = gmshSurface::getSurface((int)(yyvsp[(3) - (4)].d));
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 184:
#line 1992 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (10)].d);
      myGmshSurface = gmshParametricSurface::NewParametricSurface(num, (yyvsp[(7) - (10)].c), (yyvsp[(8) - (10)].c), (yyvsp[(9) - (10)].c));
      (yyval.s).Type = 0;
      (yyval.s).Num = num;
    ;}
    break;

  case 185:
#line 1999 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(6) - (7)].l), tags);
      std::vector<double> param; ListOfDouble2Vector((yyvsp[(6) - (7)].l), param);
      (yyval.s).Type = 0;
      bool r = true;
      if(param.size() >= 4 && param.size() <= 7){
        if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
          double a1 = (param.size() >= 5) ? param[4] : -M_PI/2;
          double a2 = (param.size() >= 6) ? param[5] : M_PI/2;
          double a3 = (param.size() >= 7) ? param[6] : 2.*M_PI;
          r = GModel::current()->getOCCInternals()->addSphere
            (num, param[0], param[1], param[2], param[3], a1, a2, a3);
        }
        else{
          yymsg(0, "Sphere only available with OpenCASCADE geometry kernel");
        }
        (yyval.s).Type = MSH_VOLUME;
      }
      else if(tags.size() == 2){
        myGmshSurface = GModel::current()->getGEOInternals()->newGeometrySphere
          (num, tags[0], tags[1]);
      }
      else{
        yymsg(0, "Sphere requires 2 points or from 4 to 7 parameters");
      }
      if(!r) yymsg(0, "Could not add sphere");
      List_Delete((yyvsp[(6) - (7)].l));
      (yyval.s).Num = num;
    ;}
    break;

  case 186:
#line 2030 "Gmsh.y"
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

  case 187:
#line 2045 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      std::vector<double> param; ListOfDouble2Vector((yyvsp[(6) - (7)].l), param);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        if(param.size() == 6){
          r = GModel::current()->getOCCInternals()->addBox
            (num, param[0], param[1], param[2], param[3], param[4], param[5]);
        }
        else{
          yymsg(0, "Box requires 6 parameters");
        }
      }
      else{
        yymsg(0, "Box only available with OpenCASCADE geometry kernel");
      }
      if(!r) yymsg(0, "Could not add block");
      List_Delete((yyvsp[(6) - (7)].l));
      (yyval.s).Type = MSH_VOLUME;
      (yyval.s).Num = num;
    ;}
    break;

  case 188:
#line 2067 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      std::vector<double> param; ListOfDouble2Vector((yyvsp[(6) - (7)].l), param);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        if(param.size() == 5 || param.size() == 6){
          double alpha = (param.size() == 6) ? param[5] : 2*M_PI;
          r = GModel::current()->getOCCInternals()->addTorus
            (num, param[0], param[1], param[2], param[3], param[4], alpha);
        }
        else{
          yymsg(0, "Torus requires 5 ou 6 parameters");
        }
      }
      else{
        yymsg(0, "Torus only available with OpenCASCADE geometry kernel");
      }
      if(!r) yymsg(0, "Could not add torus");
      List_Delete((yyvsp[(6) - (7)].l));
      (yyval.s).Type = MSH_VOLUME;
      (yyval.s).Num = num;
    ;}
    break;

  case 189:
#line 2090 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      std::vector<double> param; ListOfDouble2Vector((yyvsp[(6) - (7)].l), param);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        if(param.size() == 5 || param.size() == 6){
          double r = (param.size() == 6) ? param[5] : 0.;
          r = GModel::current()->getOCCInternals()->addRectangle
            (num, param[0], param[1], param[2], param[3], param[4], r);
        }
        else{
          yymsg(0, "Rectangle requires 5 ou 6 parameters");
        }
      }
      else{
        yymsg(0, "Rectangle only available with OpenCASCADE geometry kernel");
      }
      if(!r) yymsg(0, "Could not add rectangle");
      List_Delete((yyvsp[(6) - (7)].l));
      (yyval.s).Type = MSH_SURF_PLAN;
      (yyval.s).Num = num;
    ;}
    break;

  case 190:
#line 2113 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      std::vector<double> param; ListOfDouble2Vector((yyvsp[(6) - (7)].l), param);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        if(param.size() == 4 || param.size() == 5){
          double ry = (param.size() == 5) ? param[4] : param[3];
          r = GModel::current()->getOCCInternals()->addDisk
            (num, param[0], param[1], param[2], param[3], ry);
        }
        else{
          yymsg(0, "Disk requires 4 or 5 parameters");
        }
      }
      else{
        yymsg(0, "Disk only available with OpenCASCADE geometry kernel");
      }
      if(!r) yymsg(0, "Could not add disk");
      List_Delete((yyvsp[(6) - (7)].l));
      (yyval.s).Type = MSH_SURF_PLAN;
      (yyval.s).Num = num;
    ;}
    break;

  case 191:
#line 2136 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      std::vector<double> param; ListOfDouble2Vector((yyvsp[(6) - (7)].l), param);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        if(param.size() == 7 || param.size() == 8){
          double angle = (param.size() == 8) ? param[7] : 2*M_PI;
          r = GModel::current()->getOCCInternals()->addCylinder
            (num, param[0], param[1], param[2], param[3], param[4], param[5],
             param[6], angle);
        }
        else{
          yymsg(0, "Cylinder requires 7 or 8 parameters");
        }
      }
      else{
        yymsg(0, "Cylinder only available with OpenCASCADE geometry kernel");
      }
      if(!r) yymsg(0, "Could not add cylinder");
      List_Delete((yyvsp[(6) - (7)].l));
      (yyval.s).Type = MSH_VOLUME;
      (yyval.s).Num = num;
    ;}
    break;

  case 192:
#line 2160 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      std::vector<double> param; ListOfDouble2Vector((yyvsp[(6) - (7)].l), param);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        if(param.size() == 8 || param.size() == 9){
          double alpha = (param.size() == 9) ? param[8] : 2*M_PI;
          r = GModel::current()->getOCCInternals()->addCone
            (num, param[0], param[1], param[2], param[3], param[4], param[5],
             param[6], param[7], alpha);
        }
        else{
          yymsg(0, "Cone requires 8 or 9 parameters");
        }
      }
      else{
        yymsg(0, "Cone only available with OpenCASCADE geometry kernel");
      }
      if(!r) yymsg(0, "Could not add cone");
      List_Delete((yyvsp[(6) - (7)].l));
      (yyval.s).Type = MSH_VOLUME;
      (yyval.s).Num = num;
    ;}
    break;

  case 193:
#line 2184 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      std::vector<double> param; ListOfDouble2Vector((yyvsp[(6) - (7)].l), param);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        if(param.size() == 6 || param.size() == 7){
          double ltx = (param.size() == 7) ? param[6] : 0.;
          r = GModel::current()->getOCCInternals()->addWedge
            (num, param[0], param[1], param[2], param[3], param[4], param[5],
             ltx);
        }
        else{
          yymsg(0, "Wedge requires 7 parameters");
        }
      }
      else{
        yymsg(0, "Wedge only available with OpenCASCADE geometry kernel");
      }
      if(!r) yymsg(0, "Could not add wedge");
      List_Delete((yyvsp[(6) - (7)].l));
      (yyval.s).Type = MSH_VOLUME;
      (yyval.s).Num = num;
    ;}
    break;

  case 194:
#line 2208 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      std::vector<double> param; ListOfDouble2Vector((yyvsp[(6) - (7)].l), param);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        if(param.size() >= 2){
          int in = (int)param[0];
          double offset = param[1];
          std::vector<int> exclude;
          for(std::size_t i = 2; i < param.size(); i++)
            exclude.push_back(param[i]);
          std::vector<std::pair<int, int> > outDimTags;
          r = GModel::current()->getOCCInternals()->addThickSolid
            (num, in, exclude, offset, outDimTags);
        }
        else{
          yymsg(0, "ThickSolid requires at least 2 parameters");
        }
      }
      else{
        yymsg(0, "ThickSolid only available with OpenCASCADE geometry kernel");
      }
      if(!r) yymsg(0, "Could not add thick solid");
      List_Delete((yyvsp[(6) - (7)].l));
    ;}
    break;

  case 195:
#line 2234 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (9)].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(7) - (9)].l), tags);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        r = GModel::current()->getOCCInternals()->addSurfaceLoop(num, tags, (yyvsp[(8) - (9)].d));
      }
      else{
        r = GModel::current()->getGEOInternals()->addSurfaceLoop(num, tags);
      }
      if(!r) yymsg(0, "Could not add surface loop");
      List_Delete((yyvsp[(7) - (9)].l));
      Free((yyvsp[(2) - (9)].c));
      (yyval.s).Type = MSH_SURF_LOOP;
      (yyval.s).Num = num;
    ;}
    break;

  case 196:
#line 2251 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(6) - (7)].l), tags);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        r = GModel::current()->getOCCInternals()->addVolume(num, tags);
      }
      else{
        r = GModel::current()->getGEOInternals()->addVolume(num, tags);
      }
      if(!r) yymsg(0, "Could not add volume");
      List_Delete((yyvsp[(6) - (7)].l));
      (yyval.s).Type = MSH_VOLUME;
      (yyval.s).Num = num;
    ;}
    break;

  case 197:
#line 2267 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      std::vector<int> wires; ListOfDouble2Vector((yyvsp[(6) - (7)].l), wires);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        std::vector<std::pair<int, int> > outDimTags;
        r = GModel::current()->getOCCInternals()->addThruSections
          (num, wires, true, false, outDimTags);
      }
      else{
        yymsg(0, "ThruSections only available with OpenCASCADE geometry kernel");
      }
      if(!r) yymsg(0, "Could not add thrusections");
      List_Delete((yyvsp[(6) - (7)].l));
      (yyval.s).Type = MSH_VOLUME;
      (yyval.s).Num = num;
    ;}
    break;

  case 198:
#line 2285 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].d);
      std::vector<int> wires; ListOfDouble2Vector((yyvsp[(7) - (8)].l), wires);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        std::vector<std::pair<int, int> > outDimTags;
        r = GModel::current()->getOCCInternals()->addThruSections
          (num, wires, true, true, outDimTags);
      }
      else{
        yymsg(0, "ThruSections only available with OpenCASCADE geometry kernel");
      }
      if(!r) yymsg(0, "Could not add ruled thrusections");
      List_Delete((yyvsp[(7) - (8)].l));
      (yyval.s).Type = MSH_VOLUME;
      (yyval.s).Num = num;
    ;}
    break;

  case 199:
#line 2303 "Gmsh.y"
    {
      if((yyvsp[(2) - (8)].i) == 1)
        yymsg(0, "`Compound Line (...) = {...};' is deprecated: use `Compound "
              "Spline|BSpline (...) = {...} Using ...;' instead, or the compound "
              "meshing constraint `Compound Curve {...};'");
      else
        yymsg(0, "`Compound Surface (...) = {...};' is deprecated: use the "
              "compound meshing constraint `Compound Surface {...};' instead");
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 200:
#line 2316 "Gmsh.y"
    {
      if((yyvsp[(2) - (12)].i) == 1)
        yymsg(0, "`Compound Line (...) = {...};' is deprecated: use `Compound "
              "Spline|BSpline (...) = {...} Using ...;' instead, or the compound "
              "meshing constraint `Compound Curve {...};'");
      else
        yymsg(0, "`Compound Surface (...) = {...};' is deprecated: use the "
              "compound meshing constraint `Compound Surface {...};' instead");
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 201:
#line 2328 "Gmsh.y"
    {
      dim_entity = (yyvsp[(2) - (2)].i);
    ;}
    break;

  case 202:
#line 2332 "Gmsh.y"
    {
      int num = (int)(yyvsp[(5) - (9)].i);
      int op = (yyvsp[(7) - (9)].i);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(8) - (9)].l), tags);
      bool r = GModel::current()->getGEOInternals()->modifyPhysicalGroup
        ((yyvsp[(2) - (9)].i), num, op, tags);
      if(!r)
        switch ((yyvsp[(2) - (9)].i)) {
        case 0: yymsg(0, "Could not modify physical point"); break;
        case 1: yymsg(0, "Could not modify physical line"); break;
        case 2: yymsg(0, "Could not modify physical surface"); break;
        case 3: yymsg(0, "Could not modify physical volume"); break;
        }
      List_Delete((yyvsp[(8) - (9)].l));
      switch ((yyvsp[(2) - (9)].i)) {
      case 0: (yyval.s).Type = MSH_PHYSICAL_POINT  ; break;
      case 1: (yyval.s).Type = MSH_PHYSICAL_LINE   ; break;
      case 2: (yyval.s).Type = MSH_PHYSICAL_SURFACE; break;
      case 3: (yyval.s).Type = MSH_PHYSICAL_VOLUME ; break;
      }
      (yyval.s).Num = num;
    ;}
    break;

  case 203:
#line 2358 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 204:
#line 2360 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 205:
#line 2362 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 206:
#line 2364 "Gmsh.y"
    { (yyval.i) = 3; ;}
    break;

  case 207:
#line 2366 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(3) - (4)].d);
      if ((yyval.i)<0 || (yyval.i)>3) yymsg(0, "GeoEntity dim out of range [0,3]");
    ;}
    break;

  case 208:
#line 2374 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 209:
#line 2376 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 210:
#line 2378 "Gmsh.y"
    { (yyval.i) = 3; ;}
    break;

  case 211:
#line 2380 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(3) - (4)].d);
      if ((yyval.i)<1 || (yyval.i)>3) yymsg(0, "GeoEntity dim out of range [1,3]");
    ;}
    break;

  case 212:
#line 2388 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 213:
#line 2390 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 214:
#line 2392 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(3) - (4)].d);
      if ((yyval.i)<1 || (yyval.i)>2) yymsg(0, "GeoEntity dim out of range [1,2]");
    ;}
    break;

  case 215:
#line 2400 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 216:
#line 2402 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 217:
#line 2404 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 218:
#line 2406 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(3) - (4)].d);
      if ((yyval.i)<0 || (yyval.i)>2) yymsg(0, "GeoEntity dim out of range [0,2]");
    ;}
    break;

  case 219:
#line 2416 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), dimTags);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        r = GModel::current()->getOCCInternals()->translate
          (dimTags, (yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2]);
      }
      else{
        r = GModel::current()->getGEOInternals()->translate
          (dimTags, (yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2]);
      }
      if(!r) yymsg(0, "Could not translate shapes");
      (yyval.l) = (yyvsp[(4) - (5)].l);
    ;}
    break;

  case 220:
#line 2432 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(10) - (11)].l), dimTags);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        r = GModel::current()->getOCCInternals()->rotate
          (dimTags, (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(7) - (11)].d));
      }
      else{
        r = GModel::current()->getGEOInternals()->rotate
          (dimTags, (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(7) - (11)].d));
      }
      if(!r) yymsg(0, "Could not rotate shapes");
      (yyval.l) = (yyvsp[(10) - (11)].l);
    ;}
    break;

  case 221:
#line 2448 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), dimTags);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        r = GModel::current()->getOCCInternals()->symmetry
          (dimTags, (yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], (yyvsp[(2) - (5)].v)[3]);
      }
      else{
        r = GModel::current()->getGEOInternals()->symmetry
          (dimTags, (yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], (yyvsp[(2) - (5)].v)[3]);
      }
      if(!r) yymsg(0, "Could not apply symmetry transform");
      (yyval.l) = (yyvsp[(4) - (5)].l);
    ;}
    break;

  case 222:
#line 2464 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(8) - (9)].l), dimTags);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        r = GModel::current()->getOCCInternals()->dilate
          (dimTags, (yyvsp[(3) - (9)].v)[0], (yyvsp[(3) - (9)].v)[1], (yyvsp[(3) - (9)].v)[2], (yyvsp[(5) - (9)].d), (yyvsp[(5) - (9)].d), (yyvsp[(5) - (9)].d));
      }
      else{
        r = GModel::current()->getGEOInternals()->dilate
          (dimTags, (yyvsp[(3) - (9)].v)[0], (yyvsp[(3) - (9)].v)[1], (yyvsp[(3) - (9)].v)[2], (yyvsp[(5) - (9)].d), (yyvsp[(5) - (9)].d), (yyvsp[(5) - (9)].d));
      }
      if(!r) yymsg(0, "Could not dilate shapes");
      (yyval.l) = (yyvsp[(8) - (9)].l);
    ;}
    break;

  case 223:
#line 2480 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(8) - (9)].l), dimTags);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        r = GModel::current()->getOCCInternals()->dilate
          (dimTags, (yyvsp[(3) - (9)].v)[0], (yyvsp[(3) - (9)].v)[1], (yyvsp[(3) - (9)].v)[2], (yyvsp[(5) - (9)].v)[0], (yyvsp[(5) - (9)].v)[1], (yyvsp[(5) - (9)].v)[2]);
      }
      else{
        r = GModel::current()->getGEOInternals()->dilate
          (dimTags, (yyvsp[(3) - (9)].v)[0], (yyvsp[(3) - (9)].v)[1], (yyvsp[(3) - (9)].v)[2], (yyvsp[(5) - (9)].v)[0], (yyvsp[(5) - (9)].v)[1], (yyvsp[(5) - (9)].v)[2]);
      }
      if(!r) yymsg(0, "Could not dilate shapes");
      (yyval.l) = (yyvsp[(8) - (9)].l);
    ;}
    break;

  case 224:
#line 2496 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(6) - (7)].l), dimTags);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        std::vector<double> mat;
        ListOfDouble2Vector((yyvsp[(3) - (7)].l), mat);
        r = GModel::current()->getOCCInternals()->affine(dimTags, mat);
      }
      else{
        yymsg(0, "Affine transform only available with OpenCASCADE geometry kernel");
      }
      if(!r) yymsg(0, "Could not transform shapes");
      List_Delete((yyvsp[(3) - (7)].l));
      (yyval.l) = (yyvsp[(6) - (7)].l);
    ;}
    break;

  case 225:
#line 2513 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > inDimTags, outDimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(3) - (4)].l), inDimTags);
      (yyval.l) = (yyvsp[(3) - (4)].l);
      List_Reset((yyval.l));
      std::string action((yyvsp[(1) - (4)].c));
      bool r = true;
      if(action == "Duplicata"){
        if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
          r = GModel::current()->getOCCInternals()->copy(inDimTags, outDimTags);
        }
        else{
          r = GModel::current()->getGEOInternals()->copy(inDimTags, outDimTags);
        }
      }
      else if(action == "Boundary" || action == "CombinedBoundary" ||
              action == "PointsOf"){
        // boundary operations are performed directly on GModel, which enables
        // to compute the boundary of hybrid CAD models; this also automatically
        // binds all boundary entities for OCC models
        if(GModel::current()->getOCCInternals() &&
           GModel::current()->getOCCInternals()->getChanged())
          GModel::current()->getOCCInternals()->synchronize(GModel::current());
        if(GModel::current()->getGEOInternals()->getChanged())
          GModel::current()->getGEOInternals()->synchronize(GModel::current());
        r = GModel::current()->getBoundaryTags
          (inDimTags, outDimTags, action == "CombinedBoundary", true,
           action == "PointsOf");
      }
      else{
        yymsg(0, "Unknown action on multiple shapes '%s'", (yyvsp[(1) - (4)].c));
      }
      if(!r) yymsg(0, "Could not apply operation on shapes");
      VectorOfPairs2ListOfShapes(outDimTags, (yyval.l));
      Free((yyvsp[(1) - (4)].c));
    ;}
    break;

  case 226:
#line 2550 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        yymsg(0, "Intersect line not available with OpenCASCADE geometry kernel");
      }
      else{
        std::vector<int> in, out; ListOfDouble2Vector((yyvsp[(4) - (9)].l), in);
        r = GModel::current()->getGEOInternals()->intersectCurvesWithSurface
          (in, (int)(yyvsp[(8) - (9)].d), out);
        for(std::size_t i = 0; i < out.size(); i++){
          Shape s;
          s.Type = MSH_POINT;
          s.Num = out[i];
          List_Add((yyval.l), &s);
        }
      }
      if(!r) yymsg(0, "Could not intersect line");
      List_Delete((yyvsp[(4) - (9)].l));
    ;}
    break;

  case 227:
#line 2572 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        yymsg(0, "Split Line not available with OpenCASCADE geometry kernel");
      }
      else{
        std::vector<int> vertices, curves; ListOfDouble2Vector((yyvsp[(7) - (9)].l), vertices);
        r = GModel::current()->getGEOInternals()->splitCurve
          ((int)(yyvsp[(4) - (9)].d), vertices, curves);
        for(std::size_t i = 0; i < curves.size(); i++){
          Shape s;
          s.Type = MSH_SEGM_LINE;
          s.Num = curves[i];
          List_Add((yyval.l), &s);
        }
      }
      if(!r) yymsg(0, "Could not split line");
      List_Delete((yyvsp[(7) - (9)].l));
    ;}
    break;

  case 228:
#line 2595 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 229:
#line 2596 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 230:
#line 2601 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    ;}
    break;

  case 231:
#line 2605 "Gmsh.y"
    {
      List_Add((yyval.l), &(yyvsp[(2) - (2)].s));
    ;}
    break;

  case 232:
#line 2609 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (6)].l)); i++){
	double d;
	List_Read((yyvsp[(4) - (6)].l), i, &d);
	Shape s;
	s.Num = (int)d;
        switch ((yyvsp[(2) - (6)].i)) {
        case 0: s.Type = MSH_POINT    ; break;
        case 1: s.Type = MSH_SEGM_LINE; break;
        case 2: s.Type = MSH_SURF_PLAN; break; // we don't care about the actual type
        case 3: s.Type = MSH_VOLUME   ; break;
        }
        List_Add((yyval.l), &s);
      }
      List_Delete((yyvsp[(4) - (6)].l));
    ;}
    break;

  case 233:
#line 2626 "Gmsh.y"
    {
      List_T *tmp = List_Create(10, 10, sizeof(double));
      getElementaryTagsForPhysicalGroups((yyvsp[(3) - (7)].i), (yyvsp[(5) - (7)].l), tmp);
      for(int i = 0; i < List_Nbr(tmp); i++){
	double d;
	List_Read(tmp, i, &d);
 	Shape s;
	s.Num = (int)d; // FIXME
        switch ((yyvsp[(3) - (7)].i)) {
        case 0: s.Type = MSH_POINT    ; break;
        case 1: s.Type = MSH_SEGM_LINE; break;
        case 2: s.Type = MSH_SURF_PLAN; break; // we don't care about the actual type
        case 3: s.Type = MSH_VOLUME   ; break;
        }
        List_Add((yyval.l), &s);
      }
      List_Delete(tmp);
      List_Delete((yyvsp[(5) - (7)].l));
    ;}
    break;

  case 234:
#line 2646 "Gmsh.y"
    {
      List_T *tmp = List_Create(10, 10, sizeof(double));
      getParentTags((yyvsp[(3) - (7)].i), (yyvsp[(5) - (7)].l), tmp);
      for(int i = 0; i < List_Nbr(tmp); i++){
	double d;
	List_Read(tmp, i, &d);
 	Shape s;
	s.Num = (int)d; // FIXME
        switch ((yyvsp[(3) - (7)].i)) {
        case 0: s.Type = MSH_POINT    ; break;
        case 1: s.Type = MSH_SEGM_LINE; break;
        case 2: s.Type = MSH_SURF_PLAN; break; // we don't care about the actual type
        case 3: s.Type = MSH_VOLUME   ; break;
        }
        List_Add((yyval.l), &s);
      }
      List_Delete(tmp);
      List_Delete((yyvsp[(5) - (7)].l));
    ;}
    break;

  case 235:
#line 2666 "Gmsh.y"
    {
      List_T *tmp = List_Create(10, 10, sizeof(double));
      getAllElementaryTags((yyvsp[(2) - (6)].i), tmp);
      for(int i = 0; i < List_Nbr(tmp); i++){
	double d;
	List_Read(tmp, i, &d);
	Shape s;
	s.Num = (int)d;
        switch ((yyvsp[(2) - (6)].i)) {
        case 0: s.Type = MSH_POINT    ; break;
        case 1: s.Type = MSH_SEGM_LINE; break;
        case 2: s.Type = MSH_SURF_PLAN; break; // we don't care about the actual type
        case 3: s.Type = MSH_VOLUME   ; break;
        }
        List_Add((yyval.l), &s);
      }
      List_Delete(tmp);
    ;}
    break;

  case 236:
#line 2685 "Gmsh.y"
    {
      List_T *tmp = List_Create(10, 10, sizeof(double));
      List_T *tmp2 = List_Create(10, 10, sizeof(double));
      getAllPhysicalTags((yyvsp[(3) - (7)].i), tmp2);
      getElementaryTagsForPhysicalGroups((yyvsp[(3) - (7)].i), tmp2, tmp);
      for(int i = 0; i < List_Nbr(tmp); i++){
	double d;
	List_Read(tmp, i, &d);
 	Shape s;
	s.Num = (int)d; // FIXME
        switch ((yyvsp[(3) - (7)].i)) {
        case 0: s.Type = MSH_POINT    ; break;
        case 1: s.Type = MSH_SEGM_LINE; break;
        case 2: s.Type = MSH_SURF_PLAN; break; // we don't care about the actual type
        case 3: s.Type = MSH_VOLUME   ; break;
        }
        List_Add((yyval.l), &s);
      }
      List_Delete(tmp);
      List_Delete(tmp2);
    ;}
    break;

  case 237:
#line 2712 "Gmsh.y"
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

  case 238:
#line 2731 "Gmsh.y"
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

  case 239:
#line 2753 "Gmsh.y"
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

  case 240:
#line 2768 "Gmsh.y"
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

  case 241:
#line 2783 "Gmsh.y"
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

  case 242:
#line 2802 "Gmsh.y"
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

  case 243:
#line 2853 "Gmsh.y"
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

  case 244:
#line 2874 "Gmsh.y"
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

  case 245:
#line 2896 "Gmsh.y"
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

  case 246:
#line 2918 "Gmsh.y"
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

  case 247:
#line 3023 "Gmsh.y"
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

  case 248:
#line 3039 "Gmsh.y"
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

  case 249:
#line 3074 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(3) - (4)].l), dimTags);
      bool changed = false;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        GModel::current()->getOCCInternals()->remove(dimTags);
        changed = GModel::current()->getOCCInternals()->getChanged();
        if(changed)
          GModel::current()->getOCCInternals()->synchronize(GModel::current());
      }
      else{
        GModel::current()->getGEOInternals()->remove(dimTags);
        changed = GModel::current()->getGEOInternals()->getChanged();
        if(changed)
          GModel::current()->getGEOInternals()->synchronize(GModel::current());
      }
      if(!changed){
        GModel::current()->remove(dimTags);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 250:
#line 3096 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), dimTags);
      bool changed = false;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        GModel::current()->getOCCInternals()->remove(dimTags, true);
        changed = GModel::current()->getOCCInternals()->getChanged();
        if(changed)
          GModel::current()->getOCCInternals()->synchronize(GModel::current());
      }
      else{
        GModel::current()->getGEOInternals()->remove(dimTags, true);
        changed = GModel::current()->getGEOInternals()->getChanged();
        if(changed)
          GModel::current()->getGEOInternals()->synchronize(GModel::current());
      }
      if(!changed){
        GModel::current()->remove(dimTags, true);
      }
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 251:
#line 3118 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), dimTags);
      if(!strcmp((yyvsp[(2) - (5)].c), "Embedded")){
        removeEmbedded(dimTags, -1);
      }
      else
	yymsg(0, "Unknown command 'Delete %s'", (yyvsp[(2) - (5)].c));
      List_Delete((yyvsp[(4) - (5)].l));
      Free((yyvsp[(2) - (5)].c));
    ;}
    break;

  case 252:
#line 3130 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      GModel::current()->getFields()->deleteField((int)(yyvsp[(4) - (6)].d));
#endif
    ;}
    break;

  case 253:
#line 3136 "Gmsh.y"
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

  case 254:
#line 3151 "Gmsh.y"
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
	GModel::current()->removePhysicalGroups();
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

  case 255:
#line 3179 "Gmsh.y"
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

  case 256:
#line 3191 "Gmsh.y"
    {
      gmsh_yynamespaces.clear();
    ;}
    break;

  case 257:
#line 3200 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), dimTags);
      setColor(dimTags, (yyvsp[(2) - (5)].u), false);
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 258:
#line 3207 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(5) - (6)].l), dimTags);
      setColor(dimTags, (yyvsp[(3) - (6)].u), true);
      List_Delete((yyvsp[(5) - (6)].l));
    ;}
    break;

  case 259:
#line 3219 "Gmsh.y"
    {
      yymsg(2, "'SetPartition' command is deprecated");
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), dimTags);
      for(std::size_t i = 0; i < dimTags.size(); i++){
        GEntity *ge = GModel::current()->getEntityByTag
          (dimTags[i].first, dimTags[i].second);
        if(ge){
          for(std::size_t j = 0; j < ge->getNumMeshElements(); j++)
            ge->getMeshElement(j)->setPartition((int)(yyvsp[(2) - (5)].d));
        }
      }
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 260:
#line 3239 "Gmsh.y"
    {
      setVisibility(-1, 1, false);
    ;}
    break;

  case 261:
#line 3243 "Gmsh.y"
    {
      setVisibility(-1, 1, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 262:
#line 3248 "Gmsh.y"
    {
      setVisibility(-1, 0, false);
    ;}
    break;

  case 263:
#line 3252 "Gmsh.y"
    {
      setVisibility(-1, 0, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 264:
#line 3257 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(3) - (4)].l), dimTags);
      setVisibility(dimTags, 1, false);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 265:
#line 3264 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), dimTags);
      setVisibility(dimTags, 1, true);
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 266:
#line 3271 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(3) - (4)].l), dimTags);
      setVisibility(dimTags, 0, false);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 267:
#line 3278 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), dimTags);
      setVisibility(dimTags, 0, true);
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 268:
#line 3290 "Gmsh.y"
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

  case 269:
#line 3363 "Gmsh.y"
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

  case 270:
#line 3381 "Gmsh.y"
    {
#if defined(HAVE_POST)
      if(!strcmp((yyvsp[(2) - (7)].c), "View")){
	int index = (int)(yyvsp[(4) - (7)].d);
	if(index >= 0 && index < (int)PView::list.size()){
          if(!strcmp((yyvsp[(1) - (7)].c), "Save")){
            std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(6) - (7)].c));
            PView::list[index]->write(tmp, CTX::instance()->post.fileFormat);
          }
          else if(!strcmp((yyvsp[(1) - (7)].c), "SendToServer")){
            PView::list[index]->sendToServer((yyvsp[(6) - (7)].c));
          }
          else{
            yymsg(0, "Unknown operation '%s' on view %d", (yyvsp[(1) - (7)].c), index);
          }
	}
	else
	  yymsg(0, "Unknown view %d", index);
      }
      else
	yymsg(0, "Unknown command '%s %s'", (yyvsp[(1) - (7)].c), (yyvsp[(2) - (7)].c));
#endif
      Free((yyvsp[(1) - (7)].c)); Free((yyvsp[(2) - (7)].c)); Free((yyvsp[(6) - (7)].c));
    ;}
    break;

  case 271:
#line 3406 "Gmsh.y"
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

  case 272:
#line 3421 "Gmsh.y"
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

  case 273:
#line 3454 "Gmsh.y"
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

  case 274:
#line 3466 "Gmsh.y"
    {
#if defined(HAVE_POST)
      if(!strcmp((yyvsp[(2) - (3)].c), "ElementsFromAllViews"))
	PView::combine(false, 1, CTX::instance()->post.combineRemoveOrig,
                       CTX::instance()->post.combineCopyOptions);
      else if(!strcmp((yyvsp[(2) - (3)].c), "ElementsFromVisibleViews"))
	PView::combine(false, 0, CTX::instance()->post.combineRemoveOrig,
                       CTX::instance()->post.combineCopyOptions);
      else if(!strcmp((yyvsp[(2) - (3)].c), "ElementsByViewName"))
	PView::combine(false, 2, CTX::instance()->post.combineRemoveOrig,
                       CTX::instance()->post.combineCopyOptions);
      else if(!strcmp((yyvsp[(2) - (3)].c), "TimeStepsFromAllViews"))
	PView::combine(true, 1, CTX::instance()->post.combineRemoveOrig,
                       CTX::instance()->post.combineCopyOptions);
      else if(!strcmp((yyvsp[(2) - (3)].c), "TimeStepsFromVisibleViews"))
	PView::combine(true, 0, CTX::instance()->post.combineRemoveOrig,
                       CTX::instance()->post.combineCopyOptions);
      else if(!strcmp((yyvsp[(2) - (3)].c), "TimeStepsByViewName"))
	PView::combine(true, 2, CTX::instance()->post.combineRemoveOrig,
                       CTX::instance()->post.combineCopyOptions);
      else if(!strcmp((yyvsp[(2) - (3)].c), "Views"))
	PView::combine(false, 1, CTX::instance()->post.combineRemoveOrig,
                       CTX::instance()->post.combineCopyOptions);
      else if(!strcmp((yyvsp[(2) - (3)].c), "TimeSteps"))
	PView::combine(true, 2, CTX::instance()->post.combineRemoveOrig,
                       CTX::instance()->post.combineCopyOptions);
      else
	yymsg(0, "Unknown 'Combine' command");
#endif
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 275:
#line 3498 "Gmsh.y"
    {
      Msg::Exit(0);
    ;}
    break;

  case 276:
#line 3502 "Gmsh.y"
    {
      gmsh_yyerrorstate = 999; // this will be checked when yyparse returns
      YYABORT;
    ;}
    break;

  case 277:
#line 3507 "Gmsh.y"
    {
      // force sync
      if(GModel::current()->getOCCInternals())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      GModel::current()->getGEOInternals()->synchronize(GModel::current());
    ;}
    break;

  case 278:
#line 3514 "Gmsh.y"
    {
      new GModel();
      GModel::current(GModel::list.size() - 1);
    ;}
    break;

  case 279:
#line 3519 "Gmsh.y"
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

  case 280:
#line 3529 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 1;
      SetBoundingBox((yyvsp[(3) - (15)].d), (yyvsp[(5) - (15)].d), (yyvsp[(7) - (15)].d), (yyvsp[(9) - (15)].d), (yyvsp[(11) - (15)].d), (yyvsp[(13) - (15)].d));
    ;}
    break;

  case 281:
#line 3534 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
      drawContext::global()->draw();
#endif
    ;}
    break;

  case 282:
#line 3540 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
     CTX::instance()->mesh.changed = ENT_ALL;
     for(std::size_t index = 0; index < PView::list.size(); index++)
       PView::list[index]->setChanged(true);
#endif
    ;}
    break;

  case 283:
#line 3548 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh();
    ;}
    break;

  case 284:
#line 3552 "Gmsh.y"
    {
      GModel::current()->classifySurfaces((yyvsp[(3) - (9)].d), (yyvsp[(5) - (9)].d), (yyvsp[(7) - (9)].d), M_PI);
    ;}
    break;

  case 285:
#line 3556 "Gmsh.y"
    {
      GModel::current()->classifySurfaces((yyvsp[(3) - (11)].d), (yyvsp[(5) - (11)].d), (yyvsp[(7) - (11)].d), (yyvsp[(9) - (11)].d));
    ;}
    break;

  case 286:
#line 3560 "Gmsh.y"
    {
      GModel::current()->createGeometryOfDiscreteEntities();
    ;}
    break;

  case 287:
#line 3564 "Gmsh.y"
    {
      GModel::current()->renumberMeshVertices();
    ;}
    break;

  case 288:
#line 3568 "Gmsh.y"
    {
      GModel::current()->renumberMeshElements();
    ;}
    break;

  case 289:
#line 3572 "Gmsh.y"
    {
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      if(GModel::current()->getGEOInternals()->getChanged())
        GModel::current()->getGEOInternals()->synchronize(GModel::current());
      GModel::current()->refineMesh(CTX::instance()->mesh.secondOrderLinear,
                                    CTX::instance()->mesh.algoSubdivide == 1,
                                    CTX::instance()->mesh.algoSubdivide == 2,
                                    CTX::instance()->mesh.algoSubdivide == 3);
    ;}
    break;

  case 290:
#line 3584 "Gmsh.y"
    {
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      if(GModel::current()->getGEOInternals()->getChanged())
        GModel::current()->getGEOInternals()->synchronize(GModel::current());
      GModel::current()->recombineMesh();
    ;}
    break;

  case 291:
#line 3594 "Gmsh.y"
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
        yymsg(0, "Need at least one adaptation technique");
      }
      else{
        std::vector<simpleFunction<double>*> f;
        for(int i = 0; i < List_Nbr((yyvsp[(6) - (16)].l)); i++){
          double d;
          List_Read((yyvsp[(6) - (16)].l), i, &d);
          gLevelset *l = gLevelset::find((int)d);
          if(l) f.push_back(l);
          else yymsg(0, "Unknown levelset %d", (int)d);
        }
        if(technique.size() != f.size()){
          yymsg(0, "Number of techniques != number of levelsets");
        }
        else{
          if(List_Nbr((yyvsp[(9) - (16)].l)) != (int)f.size()){
            yymsg(0, "Number of parameters != number of levelsets");
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

  case 292:
#line 3657 "Gmsh.y"
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

  case 293:
#line 3673 "Gmsh.y"
    {
      LoopControlVariablesTab[ImbricatedLoop][0] = (yyvsp[(3) - (6)].d);
      LoopControlVariablesTab[ImbricatedLoop][1] = (yyvsp[(5) - (6)].d);
      LoopControlVariablesTab[ImbricatedLoop][2] = 1.0;
      LoopControlVariablesNameTab[ImbricatedLoop] = "";
      fgetpos(gmsh_yyin, &yyposImbricatedLoopsTab[ImbricatedLoop]);
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

  case 294:
#line 3690 "Gmsh.y"
    {
      LoopControlVariablesTab[ImbricatedLoop][0] = (yyvsp[(3) - (8)].d);
      LoopControlVariablesTab[ImbricatedLoop][1] = (yyvsp[(5) - (8)].d);
      LoopControlVariablesTab[ImbricatedLoop][2] = (yyvsp[(7) - (8)].d);
      LoopControlVariablesNameTab[ImbricatedLoop] = "";
      fgetpos(gmsh_yyin, &yyposImbricatedLoopsTab[ImbricatedLoop]);
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

  case 295:
#line 3707 "Gmsh.y"
    {
      LoopControlVariablesTab[ImbricatedLoop][0] = (yyvsp[(5) - (8)].d);
      LoopControlVariablesTab[ImbricatedLoop][1] = (yyvsp[(7) - (8)].d);
      LoopControlVariablesTab[ImbricatedLoop][2] = 1.0;
      LoopControlVariablesNameTab[ImbricatedLoop] = (yyvsp[(2) - (8)].c);
      gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[(2) - (8)].c)]);
      s.list = false;
      s.value.resize(1);
      s.value[0] = (yyvsp[(5) - (8)].d);
      fgetpos(gmsh_yyin, &yyposImbricatedLoopsTab[ImbricatedLoop]);
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

  case 296:
#line 3729 "Gmsh.y"
    {
      LoopControlVariablesTab[ImbricatedLoop][0] = (yyvsp[(5) - (10)].d);
      LoopControlVariablesTab[ImbricatedLoop][1] = (yyvsp[(7) - (10)].d);
      LoopControlVariablesTab[ImbricatedLoop][2] = (yyvsp[(9) - (10)].d);
      LoopControlVariablesNameTab[ImbricatedLoop] = (yyvsp[(2) - (10)].c);
      gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[(2) - (10)].c)]);
      s.list = false;
      s.value.resize(1);
      s.value[0] = (yyvsp[(5) - (10)].d);
      fgetpos(gmsh_yyin, &yyposImbricatedLoopsTab[ImbricatedLoop]);
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

  case 297:
#line 3751 "Gmsh.y"
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
	  fsetpos(gmsh_yyin, &yyposImbricatedLoopsTab[ImbricatedLoop - 1]);
	  gmsh_yylineno = yylinenoImbricatedLoopsTab[ImbricatedLoop - 1];
	}
	else
	  ImbricatedLoop--;
      }
    ;}
    break;

  case 298:
#line 3786 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip(NULL, "Return");
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 299:
#line 3794 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip(NULL, "Return");
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 300:
#line 3802 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    ;}
    break;

  case 301:
#line 3808 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function '%s'", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 302:
#line 3815 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function '%s'", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 303:
#line 3822 "Gmsh.y"
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

  case 304:
#line 3842 "Gmsh.y"
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

  case 305:
#line 3868 "Gmsh.y"
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

  case 306:
#line 3880 "Gmsh.y"
    {
      ImbricatedTest--;
      if(ImbricatedTest < 0)
        yymsg(1, "Orphan EndIf");
    ;}
    break;

  case 307:
#line 3891 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > inDimTags, outDimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), inDimTags);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        r = GModel::current()->getOCCInternals()->extrude
          (inDimTags, (yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], outDimTags);
      }
      else{
        r = GModel::current()->getGEOInternals()->extrude
          (inDimTags, (yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], outDimTags);
      }
      if(!r) yymsg(0, "Could not extrude shapes");
      (yyval.l) = (yyvsp[(4) - (5)].l);
      List_Reset((yyval.l));
      VectorOfPairs2ListOfShapes(outDimTags, (yyval.l));
    ;}
    break;

  case 308:
#line 3909 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > inDimTags, outDimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(10) - (11)].l), inDimTags);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        r = GModel::current()->getOCCInternals()->revolve
          (inDimTags, (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(7) - (11)].d), outDimTags);
      }
      else{
        r = GModel::current()->getGEOInternals()->revolve
          (inDimTags, (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(7) - (11)].d), outDimTags);
      }
      if(!r) yymsg(0, "Could not extrude shapes");
      (yyval.l) = (yyvsp[(10) - (11)].l);
      List_Reset((yyval.l));
      VectorOfPairs2ListOfShapes(outDimTags, (yyval.l));
    ;}
    break;

  case 309:
#line 3927 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > inDimTags, outDimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(12) - (13)].l), inDimTags);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        yymsg(0, "Twisting extrude not available with OpenCASCADE geometry kernel");
      }
      else{
        r = GModel::current()->getGEOInternals()->twist
          (inDimTags, (yyvsp[(7) - (13)].v)[0], (yyvsp[(7) - (13)].v)[1], (yyvsp[(7) - (13)].v)[2], (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2],
           (yyvsp[(9) - (13)].d), outDimTags);
      }
      if(!r) yymsg(0, "Could not extrude shapes");
      (yyval.l) = (yyvsp[(12) - (13)].l);
      List_Reset((yyval.l));
      VectorOfPairs2ListOfShapes(outDimTags, (yyval.l));
    ;}
    break;

  case 310:
#line 3945 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 311:
#line 3951 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > inDimTags, outDimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (7)].l), inDimTags);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        r = GModel::current()->getOCCInternals()->extrude
          (inDimTags, (yyvsp[(2) - (7)].v)[0], (yyvsp[(2) - (7)].v)[1], (yyvsp[(2) - (7)].v)[2], outDimTags, &extr);
      }
      else{
        r = GModel::current()->getGEOInternals()->extrude
          (inDimTags, (yyvsp[(2) - (7)].v)[0], (yyvsp[(2) - (7)].v)[1], (yyvsp[(2) - (7)].v)[2], outDimTags, &extr);
      }
      if(!r) yymsg(0, "Could not extrude shapes");
      (yyval.l) = (yyvsp[(4) - (7)].l);
      List_Reset((yyval.l));
      VectorOfPairs2ListOfShapes(outDimTags, (yyval.l));
    ;}
    break;

  case 312:
#line 3969 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 313:
#line 3975 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > inDimTags, outDimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(10) - (13)].l), inDimTags);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        r = GModel::current()->getOCCInternals()->revolve
          (inDimTags, (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(7) - (13)].d), outDimTags,
           &extr);
      }
      else{
        r = GModel::current()->getGEOInternals()->revolve
          (inDimTags, (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(7) - (13)].d), outDimTags,
           &extr);
      }
      if(!r) yymsg(0, "Could not extrude shapes");
      (yyval.l) = (yyvsp[(10) - (13)].l);
      List_Reset((yyval.l));
      VectorOfPairs2ListOfShapes(outDimTags, (yyval.l));
    ;}
    break;

  case 314:
#line 3995 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 315:
#line 4001 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > inDimTags, outDimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(12) - (15)].l), inDimTags);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        yymsg(0, "Twisting extrude not available with OpenCASCADE geometry kernel");
      }
      else{
        r = GModel::current()->getGEOInternals()->twist
          (inDimTags, (yyvsp[(7) - (15)].v)[0], (yyvsp[(7) - (15)].v)[1], (yyvsp[(7) - (15)].v)[2], (yyvsp[(3) - (15)].v)[0], (yyvsp[(3) - (15)].v)[1], (yyvsp[(3) - (15)].v)[2], (yyvsp[(5) - (15)].v)[0], (yyvsp[(5) - (15)].v)[1], (yyvsp[(5) - (15)].v)[2],
           (yyvsp[(9) - (15)].d),  outDimTags, &extr);
      }
      if(!r) yymsg(0, "Could not extrude shapes");
      (yyval.l) = (yyvsp[(12) - (15)].l);
      List_Reset((yyval.l));
      VectorOfPairs2ListOfShapes(outDimTags, (yyval.l));
    ;}
    break;

  case 316:
#line 4019 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 317:
#line 4025 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > inDimTags, outDimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(3) - (6)].l), inDimTags);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        yymsg(0, "Boundary layer extrusion not available with OpenCASCADE geometry kernel");
      }
      else{
        r = GModel::current()->getGEOInternals()->boundaryLayer
          (inDimTags, outDimTags, &extr);
      }
      if(!r) yymsg(0, "Could not extrude shapes");
      (yyval.l) = (yyvsp[(3) - (6)].l);
      List_Reset((yyval.l));
      VectorOfPairs2ListOfShapes(outDimTags, (yyval.l));
    ;}
    break;

  case 318:
#line 4042 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > inDimTags, outDimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(3) - (9)].l), inDimTags);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        r = GModel::current()->getOCCInternals()->addPipe(inDimTags, (int)(yyvsp[(8) - (9)].d), outDimTags);
      }
      else{
        yymsg(0, "Pipe only available with OpenCASCADE geometry kernel");
      }
      if(!r) yymsg(0, "Could not extrude shapes");
      (yyval.l) = (yyvsp[(3) - (9)].l);
      List_Reset((yyval.l));
      VectorOfPairs2ListOfShapes(outDimTags, (yyval.l));
    ;}
    break;

  case 319:
#line 4058 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        std::vector<int> wires; ListOfDouble2Vector((yyvsp[(2) - (2)].l), wires);
        std::vector<std::pair<int, int> > outDimTags;
        r = GModel::current()->getOCCInternals()->addThruSections
          (-1, wires, false, false, outDimTags);
        VectorOfPairs2ListOfShapes(outDimTags, (yyval.l));
      }
      else{
        yymsg(0, "ThruSections only available with OpenCASCADE geometry kernel");
      }
      if(!r) yymsg(0, "Could not add thrusections");
      List_Delete((yyvsp[(2) - (2)].l));
    ;}
    break;

  case 320:
#line 4075 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        std::vector<int> wires; ListOfDouble2Vector((yyvsp[(3) - (3)].l), wires);
        std::vector<std::pair<int, int> > outDimTags;
        r = GModel::current()->getOCCInternals()->addThruSections
          (-1, wires, false, true, outDimTags);
        VectorOfPairs2ListOfShapes(outDimTags, (yyval.l));
      }
      else{
        yymsg(0, "ThruSections only available with OpenCASCADE geometry kernel");
      }
      if(!r) yymsg(0, "Could not add ruled thrusections");
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 321:
#line 4093 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        std::vector<int> regions, edges;
        ListOfDouble2Vector((yyvsp[(3) - (10)].l), regions); ListOfDouble2Vector((yyvsp[(6) - (10)].l), edges);
        std::vector<double> radii;
        ListOfDouble2Vector((yyvsp[(9) - (10)].l), radii);
        std::vector<std::pair<int, int> > outDimTags;
        r = GModel::current()->getOCCInternals()->fillet
          (regions, edges, radii, outDimTags, true);
        VectorOfPairs2ListOfShapes(outDimTags, (yyval.l));
      }
      else{
        yymsg(0, "Fillet only available with OpenCASCADE geometry kernel");
      }
      if(!r) yymsg(0, "Could not fillet shapes");
      List_Delete((yyvsp[(3) - (10)].l));
      List_Delete((yyvsp[(6) - (10)].l));
      List_Delete((yyvsp[(9) - (10)].l));
    ;}
    break;

  case 322:
#line 4116 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        std::vector<int> regions, edges, surfaces;
        ListOfDouble2Vector((yyvsp[(3) - (13)].l), regions); ListOfDouble2Vector((yyvsp[(6) - (13)].l), edges);
        ListOfDouble2Vector((yyvsp[(9) - (13)].l), surfaces);
        std::vector<double> distances;
        ListOfDouble2Vector((yyvsp[(12) - (13)].l), distances);
        std::vector<std::pair<int, int> > outDimTags;
        r = GModel::current()->getOCCInternals()->chamfer
          (regions, edges, surfaces, distances, outDimTags, true);
        VectorOfPairs2ListOfShapes(outDimTags, (yyval.l));
      }
      else{
        yymsg(0, "Chamfer only available with OpenCASCADE geometry kernel");
      }
      if(!r) yymsg(0, "Could not chamfer shapes");
      List_Delete((yyvsp[(3) - (13)].l));
      List_Delete((yyvsp[(6) - (13)].l));
      List_Delete((yyvsp[(9) - (13)].l));
      List_Delete((yyvsp[(12) - (13)].l));
    ;}
    break;

  case 323:
#line 4143 "Gmsh.y"
    {
    ;}
    break;

  case 324:
#line 4146 "Gmsh.y"
    {
    ;}
    break;

  case 325:
#line 4152 "Gmsh.y"
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

  case 326:
#line 4164 "Gmsh.y"
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

  case 327:
#line 4184 "Gmsh.y"
    {
      extr.mesh.ScaleLast = true;
    ;}
    break;

  case 328:
#line 4188 "Gmsh.y"
    {
      extr.mesh.Recombine = true;
    ;}
    break;

  case 329:
#line 4192 "Gmsh.y"
    {
      extr.mesh.Recombine = (yyvsp[(2) - (3)].d) ? true : false;
    ;}
    break;

  case 330:
#line 4196 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1;
    ;}
    break;

  case 331:
#line 4200 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1_RECOMB;
    ;}
    break;

  case 332:
#line 4204 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1;
    ;}
    break;

  case 333:
#line 4208 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1_RECOMB;
    ;}
    break;

  case 334:
#line 4212 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(6) - (9)].l), tags);
      int num = (int)(yyvsp[(3) - (9)].d);
      GModel::current()->getGEOInternals()->addDiscreteSurface(num);
      extr.mesh.Holes[num].first = (yyvsp[(8) - (9)].d);
      extr.mesh.Holes[num].second = tags;
      List_Delete((yyvsp[(6) - (9)].l));
    ;}
    break;

  case 335:
#line 4221 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (6)].c), "Index"))
        extr.mesh.BoundaryLayerIndex = (yyvsp[(4) - (6)].d);
      else if(!strcmp((yyvsp[(2) - (6)].c), "View"))
        extr.mesh.ViewIndex = (yyvsp[(4) - (6)].d);
      Free((yyvsp[(2) - (6)].c));
    ;}
    break;

  case 336:
#line 4233 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Union; ;}
    break;

  case 337:
#line 4234 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Intersection; ;}
    break;

  case 338:
#line 4235 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Difference; ;}
    break;

  case 339:
#line 4236 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Section; ;}
    break;

  case 340:
#line 4237 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Fragments; ;}
    break;

  case 341:
#line 4241 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 342:
#line 4242 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 343:
#line 4243 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 344:
#line 4244 "Gmsh.y"
    { (yyval.i) = (yyvsp[(2) - (3)].d) ? 1 : 0; ;}
    break;

  case 345:
#line 4245 "Gmsh.y"
    { (yyval.i) = (yyvsp[(3) - (4)].d) ? 2 : 0; ;}
    break;

  case 346:
#line 4250 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        std::vector<std::pair<int, int > > object, tool, out;
        std::vector<std::vector<std::pair<int, int > > > outMap;
        ListOfShapes2VectorOfPairs((yyvsp[(3) - (9)].l), object);
        ListOfShapes2VectorOfPairs((yyvsp[(7) - (9)].l), tool);
        // currently we don't distinguish between Delete and Recursive Delete:
        // we always delete recursively. Let us know if you have examples where
        // having the choice would be interesting
        r = GModel::current()->getOCCInternals()->booleanOperator
          (-1, (OCC_Internals::BooleanOperator)(yyvsp[(1) - (9)].i), object, tool, out, outMap, (yyvsp[(4) - (9)].i), (yyvsp[(8) - (9)].i));
        VectorOfPairs2ListOfShapes(out, (yyval.l));
      }
      else{
        yymsg(0, "Boolean operators only available with OpenCASCADE geometry kernel");
      }
      if(!r) yymsg(0, "Could not apply boolean operator");
      List_Delete((yyvsp[(3) - (9)].l));
      List_Delete((yyvsp[(7) - (9)].l));
    ;}
    break;

  case 347:
#line 4273 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        std::vector<std::pair<int, int> > out;
        std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
        GModel::current()->getOCCInternals()->importShapes(tmp, true, out);
        VectorOfPairs2ListOfShapes(out, (yyval.l));
      }
      else{
        yymsg(0, "ShapeFromFile only available with OpenCASCADE geometry kernel");
      }
      if(!r) yymsg(0, "Could import shape");
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 348:
#line 4293 "Gmsh.y"
    {
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        std::vector<std::pair<int, int> > object, tool, out;
        std::vector<std::vector<std::pair<int, int > > > outMap;
        ListOfShapes2VectorOfPairs((yyvsp[(7) - (14)].l), object);
        ListOfShapes2VectorOfPairs((yyvsp[(11) - (14)].l), tool);
        // currently we don't distinguish between Delete and Recursive Delete:
        // we always delete recursively. Let us know if you have examples where
        // having the choice would be interesting
        r = GModel::current()->getOCCInternals()->booleanOperator
          ((int)(yyvsp[(3) - (14)].d), (OCC_Internals::BooleanOperator)(yyvsp[(1) - (14)].i), object, tool, out, outMap, (yyvsp[(8) - (14)].i), (yyvsp[(12) - (14)].i));
      }
      if(!r) yymsg(0, "Could not apply boolean operator");
      List_Delete((yyvsp[(7) - (14)].l));
      List_Delete((yyvsp[(11) - (14)].l));
    ;}
    break;

  case 349:
#line 4314 "Gmsh.y"
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    ;}
    break;

  case 350:
#line 4318 "Gmsh.y"
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
#line 4333 "Gmsh.y"
    {
      (yyval.i) = -1; // left
    ;}
    break;

  case 352:
#line 4337 "Gmsh.y"
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
#line 4353 "Gmsh.y"
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   ;}
    break;

  case 354:
#line 4357 "Gmsh.y"
    {
     (yyval.l) = (yyvsp[(2) - (2)].l);
   ;}
    break;

  case 355:
#line 4362 "Gmsh.y"
    {
      (yyval.i) = 45;
    ;}
    break;

  case 356:
#line 4366 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(2) - (2)].d);
    ;}
    break;

  case 357:
#line 4372 "Gmsh.y"
    {
      (yyval.l) = List_Create(1, 1, sizeof(double));
    ;}
    break;

  case 358:
#line 4376 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
    ;}
    break;

  case 359:
#line 4383 "Gmsh.y"
    {
      // mesh sizes at vertices are stored in internal CAD data, as they can be
      // specified during vertex creation and copied around during CAD
      // operations
      List_T *tmp = (yyvsp[(3) - (6)].l);
      if(!(yyvsp[(3) - (6)].l)){
        tmp = List_Create(100, 100, sizeof(double));
        getAllElementaryTags(0, tmp);
      }
      for(int i = 0; i < List_Nbr(tmp); i++){
        double d;
        List_Read(tmp, i, &d);
        int tag = (int)d;
        if(GModel::current()->getOCCInternals())
          GModel::current()->getOCCInternals()->setMeshSize(0, tag, (yyvsp[(5) - (6)].d));
        GModel::current()->getGEOInternals()->setMeshSize(0, tag, (yyvsp[(5) - (6)].d));
        GVertex *gv = GModel::current()->getVertexByTag(tag);
        if(gv) gv->setPrescribedMeshSizeAtVertex((yyvsp[(5) - (6)].d));
      }
      List_Delete(tmp);
    ;}
    break;

  case 360:
#line 4405 "Gmsh.y"
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

  case 361:
#line 4446 "Gmsh.y"
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
              for(std::size_t j = 0; j < corners.size(); j++){
                GVertex *gv = GModel::current()->getVertexByTag(corners[j]);
                if(gv)
                  gf->meshAttributes.corners.push_back(gv);
                else
                  yymsg(0, "Unknown model point with tag %d", corners[j]);
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

  case 362:
#line 4490 "Gmsh.y"
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
              for(std::size_t i = 0; i < corners.size(); i++){
                GVertex *gv = GModel::current()->getVertexByTag(corners[i]);
                if(gv)
                  gr->meshAttributes.corners.push_back(gv);
                else
                  yymsg(0, "Unknown model point with tag %d", corners[i]);
              }
            }
          }
        }
        List_Delete((yyvsp[(3) - (5)].l));
      }
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 363:
#line 4529 "Gmsh.y"
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

  case 364:
#line 4554 "Gmsh.y"
    {
      int tag = (int)(yyvsp[(4) - (8)].d);
      GVertex *gf = GModel::current()->getVertexByTag(tag);
      if(gf){
	int new_tag = (int)(yyvsp[(6) - (8)].d);
	gf->setTag(new_tag);
      }
      else{
	yymsg(0, "Unknown model point %d",tag);
      }
    ;}
    break;

  case 365:
#line 4566 "Gmsh.y"
    {
      int tag = (int)(yyvsp[(4) - (8)].d);
      GEdge *gf = GModel::current()->getEdgeByTag(tag);
      if(gf){
	int new_tag = (int)(yyvsp[(6) - (8)].d);
	gf->setTag(new_tag);
      }
      else{
	yymsg(0, "Unknown model curve %d",tag);
      }
    ;}
    break;

  case 366:
#line 4578 "Gmsh.y"
    {
      int tag = (int)(yyvsp[(4) - (8)].d);
      GFace *gf = GModel::current()->getFaceByTag(tag);
      if(gf){
	int new_tag = (int)(yyvsp[(6) - (8)].d);
	gf->setTag(new_tag);
      }
      else{
	yymsg(0, "Unknown model surface %d",tag);
      }
    ;}
    break;

  case 367:
#line 4590 "Gmsh.y"
    {
      int tag = (int)(yyvsp[(4) - (8)].d);
      GRegion *gf = GModel::current()->getRegionByTag(tag);
      if(gf){
	int new_tag = (int)(yyvsp[(6) - (8)].d);
	gf->setTag(new_tag);
      }
      else{
	yymsg(0, "Unknown model volume %d",tag);
      }
    ;}
    break;

  case 368:
#line 4602 "Gmsh.y"
    {
      // mesh algorithm constraints are stored in GEO internals in addition to
      // GModel, as they can be copied around during GEO operations
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (8)].l)); i++){
        double d;
        List_Read((yyvsp[(4) - (8)].l), i, &d);
        int tag = (int)d;
        GModel::current()->getGEOInternals()->setMeshAlgorithm(2, tag, (int)(yyvsp[(7) - (8)].d));
        GFace *gf = GModel::current()->getFaceByTag(tag);
        if(gf) gf->setMeshingAlgo((int)(yyvsp[(7) - (8)].d));
      }
      List_Delete((yyvsp[(4) - (8)].l));
    ;}
    break;

  case 369:
#line 4619 "Gmsh.y"
    {
      // these constraints are stored in GEO internals in addition to GModel, as
      // they can be copied around during GEO operations
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (8)].l)); i++){
        double d;
        List_Read((yyvsp[(4) - (8)].l), i, &d);
        int tag = (int)d;
        GModel::current()->getGEOInternals()->setMeshSizeFromBoundary(2, tag, (int)(yyvsp[(7) - (8)].d));
        GFace *gf = GModel::current()->getFaceByTag(tag);
        if(gf) gf->setMeshSizeFromBoundary((int)(yyvsp[(7) - (8)].d));
      }
      List_Delete((yyvsp[(4) - (8)].l));
    ;}
    break;

  case 370:
#line 4636 "Gmsh.y"
    {
      // these constraints are stored in GEO internals in addition to GModel, as
      // they can be copied around during GEO operations
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (8)].l)); i++){
        double d;
        List_Read((yyvsp[(4) - (8)].l), i, &d);
        int tag = (int)d;
        GModel::current()->getGEOInternals()->setOnlyInitialMesh(2, tag, (int)(yyvsp[(7) - (8)].d));
        GFace *gf = GModel::current()->getFaceByTag(tag);
        if(gf) gf->setOnlyInitialMesh((int)(yyvsp[(7) - (8)].d));
      }
      List_Delete((yyvsp[(4) - (8)].l));
    ;}
    break;

  case 371:
#line 4653 "Gmsh.y"
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

  case 372:
#line 4683 "Gmsh.y"
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

  case 373:
#line 4709 "Gmsh.y"
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

  case 374:
#line 4736 "Gmsh.y"
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
#line 4768 "Gmsh.y"
    {
      if (List_Nbr((yyvsp[(4) - (11)].l)) != List_Nbr((yyvsp[(8) - (11)].l))){
        yymsg(0, "Number of master surfaces (%d) different from number of "
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
#line 4795 "Gmsh.y"
    {
      if (List_Nbr((yyvsp[(4) - (18)].l)) != List_Nbr((yyvsp[(8) - (18)].l))){
        yymsg(0, "Number of master curves (%d) different from number of "
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
#line 4821 "Gmsh.y"
    {
      if (List_Nbr((yyvsp[(4) - (18)].l)) != List_Nbr((yyvsp[(8) - (18)].l))){
        yymsg(0, "Number of master surfaces (%d) different from number of "
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
#line 4847 "Gmsh.y"
    {
      if (List_Nbr((yyvsp[(4) - (12)].l)) != List_Nbr((yyvsp[(8) - (12)].l))){
        yymsg(0, "Number of master curves (%d) different from number of "
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
#line 4873 "Gmsh.y"
    {
      if (List_Nbr((yyvsp[(4) - (12)].l)) != List_Nbr((yyvsp[(8) - (12)].l))){
        yymsg(0, "Number of master surfaces (%d) different from number of "
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
#line 4899 "Gmsh.y"
    {
      if (List_Nbr((yyvsp[(5) - (12)].l)) != List_Nbr((yyvsp[(10) - (12)].l))){
        yymsg(0, "Number of master surface curves (%d) different from number of "
              "slave (%d) curves", List_Nbr((yyvsp[(10) - (12)].l)), List_Nbr((yyvsp[(5) - (12)].l)));
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
#line 4920 "Gmsh.y"
    {
      if (((yyvsp[(6) - (10)].i)==2 || (yyvsp[(6) - (10)].i)==3) && (yyvsp[(1) - (10)].i)<(yyvsp[(6) - (10)].i) ) {
        std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (10)].l), tags);
        addEmbedded((yyvsp[(1) - (10)].i), tags, (yyvsp[(6) - (10)].i), (int)(yyvsp[(8) - (10)].d));
      }
      else {
        yymsg(0, "GeoEntity of dim %d In GeoEntity of dim %d not allowed", (yyvsp[(1) - (10)].i), (yyvsp[(6) - (10)].i));
      }
      List_Delete((yyvsp[(3) - (10)].l));
    ;}
    break;

  case 382:
#line 4931 "Gmsh.y"
    {
      // reverse mesh constraints are stored in GEO internals in addition to
      // GModel, as they can be copied around during GEO operations
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      if(!(yyvsp[(3) - (4)].l)){
        GModel::current()->getGEOInternals()->setReverseMesh((yyvsp[(2) - (4)].i), 0);
        switch ((yyvsp[(2) - (4)].i)) {
        case 1:
          for(GModel::eiter it = GModel::current()->firstEdge();
              it != GModel::current()->lastEdge(); it++){
            (*it)->meshAttributes.reverseMesh = 1;
          }
          break;
        case 2:
          for(GModel::fiter it = GModel::current()->firstFace();
              it != GModel::current()->lastFace(); it++){
            (*it)->meshAttributes.reverseMesh = 1;
          }
          break;
        }
      }
      else{
        for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
          double d;
          List_Read((yyvsp[(3) - (4)].l), i, &d);
          int num = (int)d;
          GModel::current()->getGEOInternals()->setReverseMesh((yyvsp[(2) - (4)].i), num);
          switch ((yyvsp[(2) - (4)].i)) {
          case 1:
            {
              GEdge *ge = GModel::current()->getEdgeByTag(num);
              if(ge) ge->meshAttributes.reverseMesh = 1;
            }
            break;
          case 2:
            {
              GFace *gf = GModel::current()->getFaceByTag(num);
              if(gf) gf->meshAttributes.reverseMesh = 1;
            }
            break;
          }
        }
        List_Delete((yyvsp[(3) - (4)].l));
      }
    ;}
    break;

  case 383:
#line 4979 "Gmsh.y"
    {
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      if(GModel::current()->getGEOInternals()->getChanged())
        GModel::current()->getGEOInternals()->synchronize(GModel::current());
      if(!(yyvsp[(3) - (4)].l)){
        switch ((yyvsp[(2) - (4)].i)) {
        case 0:
          for(GModel::viter it = GModel::current()->firstVertex();
              it != GModel::current()->lastVertex(); it++)
            (*it)->relocateMeshVertices();
          break;
        case 1:
          for(GModel::eiter it = GModel::current()->firstEdge();
              it != GModel::current()->lastEdge(); it++)
            (*it)->relocateMeshVertices();
          break;
        case 2:
          for(GModel::fiter it = GModel::current()->firstFace();
              it != GModel::current()->lastFace(); it++)
            (*it)->relocateMeshVertices();
          break;
        }
      }
      else{
        for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
          double d;
          List_Read((yyvsp[(3) - (4)].l), i, &d);
          switch ((yyvsp[(2) - (4)].i)) {
          case 0:
            {
              GVertex *gv = GModel::current()->getVertexByTag((int)d);
              if(gv) gv->relocateMeshVertices();
            }
            break;
          case 1:
            {
              GEdge *ge = GModel::current()->getEdgeByTag((int)d);
              if(ge) ge->relocateMeshVertices();
            }
            break;
          case 2:
            {
              GFace *gf = GModel::current()->getFaceByTag((int)d);
              if(gf) gf->relocateMeshVertices();
            }
            break;
          }
        }
        List_Delete((yyvsp[(3) - (4)].l));
      }
    ;}
    break;

  case 384:
#line 5033 "Gmsh.y"
    {
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      if(GModel::current()->getGEOInternals()->getChanged())
        GModel::current()->getGEOInternals()->synchronize(GModel::current());
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
        double d;
        List_Read((yyvsp[(3) - (4)].l), i, &d);
        GRegion *gr = GModel::current()->getRegionByTag((int)d);
        if(gr) gr->setOutwardOrientationMeshConstraint();
      }
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 385:
#line 5048 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	double dnum;
	List_Read((yyvsp[(3) - (4)].l), i, &dnum);
	int num = (int)dnum;
        GModel::current()->getGEOInternals()->setDegenerated(1, num);
        GEdge *ge = GModel::current()->getEdgeByTag(num);
        if(ge) ge->setTooSmall(true);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 386:
#line 5060 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (4)].l), tags);
      GModel::current()->getGEOInternals()->setCompoundMesh((yyvsp[(2) - (4)].i), tags);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 387:
#line 5071 "Gmsh.y"
    {
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals())
        GModel::current()->getOCCInternals()->removeAllDuplicates();
      else
        GModel::current()->getGEOInternals()->removeAllDuplicates();
    ;}
    break;

  case 388:
#line 5078 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (3)].c), "Geometry")){
        if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals())
          GModel::current()->getOCCInternals()->removeAllDuplicates();
        else
          GModel::current()->getGEOInternals()->removeAllDuplicates();
      }
      else if(!strcmp((yyvsp[(2) - (3)].c), "Mesh")){
        GModel::current()->removeDuplicateMeshVertices(CTX::instance()->geom.tolerance);
      }
      else
        yymsg(0, "Unknown coherence command");
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 389:
#line 5093 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(4) - (6)].l), tags);
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals())
        GModel::current()->getOCCInternals()->mergeVertices(tags);
      else
        GModel::current()->getGEOInternals()->mergeVertices(tags);
      List_Delete((yyvsp[(4) - (6)].l));
    ;}
    break;

  case 390:
#line 5106 "Gmsh.y"
    { (yyval.c) = (char*)"Homology"; ;}
    break;

  case 391:
#line 5107 "Gmsh.y"
    { (yyval.c) = (char*)"Cohomology"; ;}
    break;

  case 392:
#line 5108 "Gmsh.y"
    { (yyval.c) = (char*)"Betti"; ;}
    break;

  case 393:
#line 5113 "Gmsh.y"
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest((yyvsp[(1) - (2)].c), domain, subdomain, dim);
    ;}
    break;

  case 394:
#line 5119 "Gmsh.y"
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
#line 5131 "Gmsh.y"
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
#line 5149 "Gmsh.y"
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
#line 5176 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d);           ;}
    break;

  case 398:
#line 5177 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (3)].d);           ;}
    break;

  case 399:
#line 5178 "Gmsh.y"
    { (yyval.d) = -(yyvsp[(2) - (2)].d);          ;}
    break;

  case 400:
#line 5179 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);           ;}
    break;

  case 401:
#line 5180 "Gmsh.y"
    { (yyval.d) = !(yyvsp[(2) - (2)].d);          ;}
    break;

  case 402:
#line 5181 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) - (yyvsp[(3) - (3)].d);      ;}
    break;

  case 403:
#line 5182 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) + (yyvsp[(3) - (3)].d);      ;}
    break;

  case 404:
#line 5183 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) * (yyvsp[(3) - (3)].d);      ;}
    break;

  case 405:
#line 5185 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (3)].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));
      else
	(yyval.d) = (yyvsp[(1) - (3)].d) / (yyvsp[(3) - (3)].d);
    ;}
    break;

  case 406:
#line 5191 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) | (int)(yyvsp[(3) - (3)].d); ;}
    break;

  case 407:
#line 5192 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) & (int)(yyvsp[(3) - (3)].d); ;}
    break;

  case 408:
#line 5193 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) % (int)(yyvsp[(3) - (3)].d); ;}
    break;

  case 409:
#line 5194 "Gmsh.y"
    { (yyval.d) = pow((yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));  ;}
    break;

  case 410:
#line 5195 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d);      ;}
    break;

  case 411:
#line 5196 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) > (yyvsp[(3) - (3)].d);      ;}
    break;

  case 412:
#line 5197 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) <= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 413:
#line 5198 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) >= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 414:
#line 5199 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) == (yyvsp[(3) - (3)].d);     ;}
    break;

  case 415:
#line 5200 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) != (yyvsp[(3) - (3)].d);     ;}
    break;

  case 416:
#line 5201 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) && (yyvsp[(3) - (3)].d);     ;}
    break;

  case 417:
#line 5202 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) || (yyvsp[(3) - (3)].d);     ;}
    break;

  case 418:
#line 5203 "Gmsh.y"
    { (yyval.d) = ((int)(yyvsp[(1) - (3)].d) >> (int)(yyvsp[(3) - (3)].d)); ;}
    break;

  case 419:
#line 5204 "Gmsh.y"
    { (yyval.d) = ((int)(yyvsp[(1) - (3)].d) << (int)(yyvsp[(3) - (3)].d)); ;}
    break;

  case 420:
#line 5205 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (5)].d) ? (yyvsp[(3) - (5)].d) : (yyvsp[(5) - (5)].d); ;}
    break;

  case 421:
#line 5206 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 422:
#line 5207 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 423:
#line 5208 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 424:
#line 5209 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 425:
#line 5210 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 426:
#line 5211 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 427:
#line 5212 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 428:
#line 5213 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 429:
#line 5214 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 430:
#line 5215 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 431:
#line 5216 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 432:
#line 5217 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 433:
#line 5218 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 434:
#line 5219 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 435:
#line 5220 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 436:
#line 5221 "Gmsh.y"
    { (yyval.d) = std::abs((yyvsp[(3) - (4)].d)); ;}
    break;

  case 437:
#line 5222 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 438:
#line 5223 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 439:
#line 5224 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d) + 0.5); ;}
    break;

  case 440:
#line 5225 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 441:
#line 5226 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 442:
#line 5227 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 443:
#line 5228 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 444:
#line 5229 "Gmsh.y"
    { (yyval.d) = std::max((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 445:
#line 5230 "Gmsh.y"
    { (yyval.d) = std::min((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 446:
#line 5239 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 447:
#line 5240 "Gmsh.y"
    { (yyval.d) = 3.141592653589793; ;}
    break;

  case 448:
#line 5241 "Gmsh.y"
    { (yyval.d) = (double)ImbricatedTest; ;}
    break;

  case 449:
#line 5242 "Gmsh.y"
    { (yyval.d) = Msg::GetCommRank(); ;}
    break;

  case 450:
#line 5243 "Gmsh.y"
    { (yyval.d) = Msg::GetCommSize(); ;}
    break;

  case 451:
#line 5244 "Gmsh.y"
    { (yyval.d) = GetGmshMajorVersion(); ;}
    break;

  case 452:
#line 5245 "Gmsh.y"
    { (yyval.d) = GetGmshMinorVersion(); ;}
    break;

  case 453:
#line 5246 "Gmsh.y"
    { (yyval.d) = GetGmshPatchVersion(); ;}
    break;

  case 454:
#line 5247 "Gmsh.y"
    { (yyval.d) = Cpu(); ;}
    break;

  case 455:
#line 5248 "Gmsh.y"
    { (yyval.d) = GetMemoryUsage()/1024./1024.; ;}
    break;

  case 456:
#line 5249 "Gmsh.y"
    { (yyval.d) = TotalRam(); ;}
    break;

  case 457:
#line 5254 "Gmsh.y"
    { init_options(); ;}
    break;

  case 458:
#line 5256 "Gmsh.y"
    {
      std::vector<double> val(1, (yyvsp[(3) - (6)].d));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.d) = val[0];
    ;}
    break;

  case 459:
#line 5262 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 460:
#line 5264 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 461:
#line 5269 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 462:
#line 5274 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(1) - (1)].c2).char1, (yyvsp[(1) - (1)].c2).char2);
    ;}
    break;

  case 463:
#line 5279 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float(NULL, (yyvsp[(1) - (4)].c), 2, (int)(yyvsp[(3) - (4)].d));
    ;}
    break;

  case 464:
#line 5284 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float(NULL, (yyvsp[(1) - (4)].c), 2, (int)(yyvsp[(3) - (4)].d));
    ;}
    break;

  case 465:
#line 5288 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(3) - (4)].c2).char1, (yyvsp[(3) - (4)].c2).char2, 1, 0, 0., 1);
    ;}
    break;

  case 466:
#line 5292 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(3) - (6)].c2).char1, (yyvsp[(3) - (6)].c2).char2, (yyvsp[(5) - (6)].c), 0, 0., 1);
    ;}
    break;

  case 467:
#line 5296 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(3) - (5)].c2).char1, (yyvsp[(3) - (5)].c2).char2, 1, 0, (yyvsp[(4) - (5)].d), 2);
    ;}
    break;

  case 468:
#line 5300 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(3) - (7)].c2).char1, (yyvsp[(3) - (7)].c2).char2, (yyvsp[(5) - (7)].c), 0, (yyvsp[(6) - (7)].d), 2);
    ;}
    break;

  case 469:
#line 5304 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(3) - (8)].c2).char1, (yyvsp[(3) - (8)].c2).char2, 2, (int)(yyvsp[(5) - (8)].d), (yyvsp[(7) - (8)].d), 2);
    ;}
    break;

  case 470:
#line 5308 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(3) - (10)].c2).char1, (yyvsp[(3) - (10)].c2).char2, (yyvsp[(5) - (10)].c), (int)(yyvsp[(7) - (10)].d), (yyvsp[(9) - (10)].d), 2);
    ;}
    break;

  case 471:
#line 5312 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.d) = !StatFile(tmp);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 472:
#line 5318 "Gmsh.y"
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

  case 473:
#line 5333 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float_getDim((yyvsp[(2) - (6)].c2).char1, (yyvsp[(2) - (6)].c2).char2, (yyvsp[(4) - (6)].c));
    ;}
    break;

  case 474:
#line 5337 "Gmsh.y"
    {
      std::string struct_namespace((yyvsp[(3) - (4)].c));
      (yyval.d) = (double)gmsh_yynamespaces[struct_namespace].size();
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 475:
#line 5343 "Gmsh.y"
    {
      std::string struct_namespace(std::string(""));
      (yyval.d) = (double)gmsh_yynamespaces[struct_namespace].size();
    ;}
    break;

  case 476:
#line 5348 "Gmsh.y"
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

  case 477:
#line 5367 "Gmsh.y"
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

  case 478:
#line 5387 "Gmsh.y"
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

  case 479:
#line 5408 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(NULL, (yyvsp[(1) - (3)].c), (yyvsp[(3) - (3)].c));
    ;}
    break;

  case 480:
#line 5412 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c), (yyvsp[(5) - (5)].c));
    ;}
    break;

  case 481:
#line 5416 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(NULL, (yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].c), (int)(yyvsp[(5) - (6)].d));
    ;}
    break;

  case 482:
#line 5420 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(1) - (8)].c), (yyvsp[(3) - (8)].c), (yyvsp[(5) - (8)].c), (int)(yyvsp[(7) - (8)].d));
    ;}
    break;

  case 483:
#line 5424 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(NULL, (yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].c), (int)(yyvsp[(5) - (6)].d));
    ;}
    break;

  case 484:
#line 5428 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(1) - (8)].c), (yyvsp[(3) - (8)].c), (yyvsp[(5) - (8)].c), (int)(yyvsp[(7) - (8)].d));
    ;}
    break;

  case 485:
#line 5432 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), (yyval.d));
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 486:
#line 5437 "Gmsh.y"
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

  case 487:
#line 5447 "Gmsh.y"
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

  case 488:
#line 5457 "Gmsh.y"
    {
      (yyval.d) = Msg::GetValue((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 489:
#line 5462 "Gmsh.y"
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

  case 490:
#line 5473 "Gmsh.y"
    {
      std::string s((yyvsp[(3) - (6)].c)), substr((yyvsp[(5) - (6)].c));
      if(s.find(substr) != std::string::npos)
        (yyval.d) = 1.;
      else
        (yyval.d) = 0.;
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 491:
#line 5482 "Gmsh.y"
    {
      (yyval.d) = strlen((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 492:
#line 5487 "Gmsh.y"
    {
      (yyval.d) = strcmp((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 493:
#line 5492 "Gmsh.y"
    {
      int align = 0, font = 0, fontsize = CTX::instance()->glFontSize;
      if(List_Nbr((yyvsp[(3) - (4)].l)) % 2){
        yymsg(0, "Number of text attributes should be even");
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

  case 494:
#line 5519 "Gmsh.y"
    { (yyval.d) = 0.; ;}
    break;

  case 495:
#line 5521 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);;}
    break;

  case 496:
#line 5526 "Gmsh.y"
    { (yyval.c) = NULL; ;}
    break;

  case 497:
#line 5528 "Gmsh.y"
    { (yyval.c) = (yyvsp[(2) - (2)].c);;}
    break;

  case 498:
#line 5533 "Gmsh.y"
    {
      std::string struct_namespace((yyvsp[(2) - (3)].c2).char1? (yyvsp[(2) - (3)].c2).char1 : std::string("")),
        struct_name((yyvsp[(2) - (3)].c2).char2);
      init_options
        (gmsh_yynamespaces.getMember_ValMax(struct_namespace, struct_name));
    ;}
    break;

  case 499:
#line 5540 "Gmsh.y"
    {
      std::string struct_namespace((yyvsp[(2) - (7)].c2).char1? (yyvsp[(2) - (7)].c2).char1 : std::string("")),
        struct_name((yyvsp[(2) - (7)].c2).char2);
      Free((yyvsp[(2) - (7)].c2).char1); Free((yyvsp[(2) - (7)].c2).char2);
      int tag_out;
      if (gmsh_yynamespaces.defStruct(struct_namespace, struct_name,
                                      floatOptions, charOptions,
                                      tag_out, member_ValMax, (yyvsp[(3) - (7)].i)))
        yymsg(0, "Redefinition of Struct '%s::%s'",
              struct_namespace.c_str(), struct_name.c_str());
      (yyval.d) = (double)tag_out;
    ;}
    break;

  case 500:
#line 5556 "Gmsh.y"
    { (yyval.c2).char1 = NULL; (yyval.c2).char2 = (yyvsp[(1) - (1)].c); ;}
    break;

  case 501:
#line 5558 "Gmsh.y"
    { (yyval.c2).char1 = (yyvsp[(1) - (3)].c); (yyval.c2).char2 = (yyvsp[(3) - (3)].c); ;}
    break;

  case 502:
#line 5563 "Gmsh.y"
    { (yyval.i) = 99; ;}
    break;

  case 503:
#line 5565 "Gmsh.y"
    { (yyval.i) = (int)(yyvsp[(2) - (2)].d); ;}
    break;

  case 504:
#line 5570 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 505:
#line 5572 "Gmsh.y"
    { (yyval.i) = (yyvsp[(2) - (3)].i); ;}
    break;

  case 506:
#line 5577 "Gmsh.y"
    {
      memcpy((yyval.v), (yyvsp[(1) - (1)].v), 5*sizeof(double));
    ;}
    break;

  case 507:
#line 5581 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 508:
#line 5585 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 509:
#line 5589 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] - (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 510:
#line 5593 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] + (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 511:
#line 5600 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (11)].d);  (yyval.v)[1] = (yyvsp[(4) - (11)].d);  (yyval.v)[2] = (yyvsp[(6) - (11)].d);  (yyval.v)[3] = (yyvsp[(8) - (11)].d); (yyval.v)[4] = (yyvsp[(10) - (11)].d);
    ;}
    break;

  case 512:
#line 5604 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (9)].d);  (yyval.v)[1] = (yyvsp[(4) - (9)].d);  (yyval.v)[2] = (yyvsp[(6) - (9)].d);  (yyval.v)[3] = (yyvsp[(8) - (9)].d); (yyval.v)[4] = 1.0;
    ;}
    break;

  case 513:
#line 5608 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 514:
#line 5612 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 515:
#line 5619 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].l)));
    ;}
    break;

  case 516:
#line 5624 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].l)));
    ;}
    break;

  case 517:
#line 5631 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 518:
#line 5636 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 519:
#line 5640 "Gmsh.y"
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    ;}
    break;

  case 520:
#line 5645 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 521:
#line 5649 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 522:
#line 5657 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (5)].d);
      }
    ;}
    break;

  case 523:
#line 5668 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 524:
#line 5672 "Gmsh.y"
    {
      (yyval.l) = 0;
    ;}
    break;

  case 525:
#line 5676 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(1) - (1)].c), "*") || !strcmp((yyvsp[(1) - (1)].c), "all")){
        (yyval.l) = 0;
      }
      else{
        yyerror("Unknown special string for list replacement");
        (yyval.l) = List_Create(2, 1, sizeof(double));
      }
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 526:
#line 5690 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 527:
#line 5698 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (3)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (3)].d);
      }
    ;}
    break;

  case 528:
#line 5706 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      for(double d = (yyvsp[(1) - (3)].d); ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d <= (yyvsp[(3) - (3)].d)) : (d >= (yyvsp[(3) - (3)].d));
          ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d += 1.) : (d -= 1.))
	List_Add((yyval.l), &d);
    ;}
    break;

  case 529:
#line 5713 "Gmsh.y"
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

  case 530:
#line 5723 "Gmsh.y"
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
          yymsg(0, "Unknown model point with tag %d", tag);
        }
      }
      List_Add((yyval.l), &x);
      List_Add((yyval.l), &y);
      List_Add((yyval.l), &z);
    ;}
    break;

  case 531:
#line 5746 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags(0, (yyval.l));
    ;}
    break;

  case 532:
#line 5751 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags(0, (yyval.l));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 533:
#line 5757 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags((yyvsp[(1) - (4)].i), (yyval.l));
    ;}
    break;

  case 534:
#line 5762 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags((yyvsp[(1) - (2)].i), (yyval.l));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 535:
#line 5768 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      if(!(yyvsp[(3) - (3)].l)){
        getAllPhysicalTags((yyvsp[(2) - (3)].i), (yyval.l));
      }
      else{
        getElementaryTagsForPhysicalGroups((yyvsp[(2) - (3)].i), (yyvsp[(3) - (3)].l), (yyval.l));
        List_Delete((yyvsp[(3) - (3)].l));
      }
    ;}
    break;

  case 536:
#line 5779 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getParentTags((yyvsp[(2) - (3)].i), (yyvsp[(3) - (3)].l), (yyval.l));
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 537:
#line 5785 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      if(List_Nbr((yyvsp[(4) - (4)].l)) < 6) {
        yymsg(0, "Bounding box should be {xmin, ymin, zmin, xmax, ymax, zmax}");
      }
      else {
        double bb[6];
        for(int i = 0; i < 6; i++) List_Read((yyvsp[(4) - (4)].l), i, &bb[i]);
        getElementaryTagsInBoundingBox
          ((yyvsp[(1) - (4)].i), bb[0], bb[1], bb[2], bb[3], bb[4], bb[5], (yyval.l));
      }
      List_Delete((yyvsp[(4) - (4)].l));
    ;}
    break;

  case 538:
#line 5799 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getBoundingBox((yyvsp[(2) - (5)].i), (yyvsp[(4) - (5)].l), (yyval.l));
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 539:
#line 5805 "Gmsh.y"
    {
      (yyval.l) = List_Create(1, 1, sizeof(double));
      double m = 0;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        GModel::current()->getOCCInternals()->getMass((yyvsp[(2) - (5)].i), (int)(yyvsp[(4) - (5)].d), m);
      }
      else{
        yymsg(0, "Mass only available with OpenCASCADE geometry kernel");
      }
      List_Add((yyval.l), &m);
    ;}
    break;

  case 540:
#line 5817 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 1, sizeof(double));
      double x = 0., y = 0., z = 0.;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        GModel::current()->getOCCInternals()->getCenterOfMass((yyvsp[(2) - (5)].i), (int)(yyvsp[(4) - (5)].d), x, y, z);
      }
      else{
        yymsg(0, "CenterOfMass only available with OpenCASCADE geometry kernel");
      }
      List_Add((yyval.l), &x);
      List_Add((yyval.l), &y);
      List_Add((yyval.l), &z);
    ;}
    break;

  case 541:
#line 5831 "Gmsh.y"
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

  case 542:
#line 5841 "Gmsh.y"
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

  case 543:
#line 5851 "Gmsh.y"
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

  case 544:
#line 5861 "Gmsh.y"
    {
      (yyval.l) = List_Create(20, 20, sizeof(double));
      if(!gmsh_yysymbols.count((yyvsp[(1) - (3)].c)))
	yymsg(0, "Unknown variable '%s'", (yyvsp[(1) - (3)].c));
      else{
        gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[(1) - (3)].c)]);
	for(std::size_t i = 0; i < s.value.size(); i++)
	  List_Add((yyval.l), &s.value[i]);
      }
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 545:
#line 5873 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfFloat(NULL, (yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c));
    ;}
    break;

  case 546:
#line 5877 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfFloat((yyvsp[(1) - (7)].c), (yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].c));
    ;}
    break;

  case 547:
#line 5882 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      if(!gmsh_yysymbols.count((yyvsp[(3) - (4)].c)))
	yymsg(0, "Unknown variable '%s'", (yyvsp[(3) - (4)].c));
      else{
        gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[(3) - (4)].c)]);
	for(std::size_t i = 0; i < s.value.size(); i++)
	  List_Add((yyval.l), &s.value[i]);
      }
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 548:
#line 5894 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 549:
#line 5898 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 550:
#line 5902 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (6)].l);
    ;}
    break;

  case 551:
#line 5906 "Gmsh.y"
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

  case 552:
#line 5924 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = (yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1);
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 553:
#line 5932 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = pow(10,(yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1));
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 554:
#line 5940 "Gmsh.y"
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

  case 555:
#line 5969 "Gmsh.y"
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

  case 556:
#line 5979 "Gmsh.y"
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
      for(std::size_t i = 0; i < tmp.size(); i++){
        List_Add((yyval.l), &tmp[i]);
      }
    ;}
    break;

  case 557:
#line 5995 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
        double *d = (double*)List_Pointer((yyvsp[(3) - (4)].l), i);
        *d = std::abs(*d);
      }
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 558:
#line 6006 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 559:
#line 6011 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 560:
#line 6015 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].d)));
    ;}
    break;

  case 561:
#line 6019 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (3)].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 562:
#line 6031 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (9)].d), (int)(yyvsp[(4) - (9)].d), (int)(yyvsp[(6) - (9)].d), (int)(yyvsp[(8) - (9)].d));
    ;}
    break;

  case 563:
#line 6035 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (7)].d), (int)(yyvsp[(4) - (7)].d), (int)(yyvsp[(6) - (7)].d), 255);
    ;}
    break;

  case 564:
#line 6047 "Gmsh.y"
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

  case 565:
#line 6064 "Gmsh.y"
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(5) - (5)].c), val);
      (yyval.u) = val;
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(5) - (5)].c));
    ;}
    break;

  case 566:
#line 6074 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 567:
#line 6078 "Gmsh.y"
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

  case 568:
#line 6093 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].u)));
    ;}
    break;

  case 569:
#line 6098 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].u)));
    ;}
    break;

  case 570:
#line 6105 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 571:
#line 6109 "Gmsh.y"
    {
      // No need to extend to Struct_FullName (a Tag is not a String)
      (yyval.c) = treat_Struct_FullName_String(NULL, (yyvsp[(1) - (1)].c));
    ;}
    break;

  case 572:
#line 6114 "Gmsh.y"
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

  case 573:
#line 6128 "Gmsh.y"
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

  case 574:
#line 6142 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String(NULL, (yyvsp[(1) - (3)].c), (yyvsp[(3) - (3)].c));
    ;}
    break;

  case 575:
#line 6146 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c), (yyvsp[(5) - (5)].c));
    ;}
    break;

  case 576:
#line 6150 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String(NULL, (yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].c), (int)(yyvsp[(5) - (6)].d));
    ;}
    break;

  case 577:
#line 6154 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(1) - (8)].c), (yyvsp[(3) - (8)].c), (yyvsp[(5) - (8)].c), (int)(yyvsp[(7) - (8)].d));
    ;}
    break;

  case 578:
#line 6158 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 579:
#line 6166 "Gmsh.y"
    {
      std::string name = GModel::current()->getElementaryName((yyvsp[(1) - (4)].i), (int)(yyvsp[(3) - (4)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 580:
#line 6172 "Gmsh.y"
    {
      std::string name = GModel::current()->getPhysicalName((yyvsp[(2) - (5)].i), (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 581:
#line 6181 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 582:
#line 6185 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 583:
#line 6189 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    ;}
    break;

  case 584:
#line 6197 "Gmsh.y"
    {
      std::string exe = Msg::GetExecutableName();
      (yyval.c) = (char *)Malloc(exe.size() + 1);
      strcpy((yyval.c), exe.c_str());
    ;}
    break;

  case 585:
#line 6203 "Gmsh.y"
    {
      std::string action = Msg::GetOnelabAction();
      (yyval.c) = (char *)Malloc(action.size() + 1);
      strcpy((yyval.c), action.c_str());
    ;}
    break;

  case 586:
#line 6209 "Gmsh.y"
    {
      (yyval.c) = strsave((char*)"Gmsh");
    ;}
    break;

  case 587:
#line 6213 "Gmsh.y"
    {
      std::string env = GetEnvironmentVar((yyvsp[(3) - (4)].c));
      (yyval.c) = (char *)Malloc((env.size() + 1) * sizeof(char));
      strcpy((yyval.c), env.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 588:
#line 6220 "Gmsh.y"
    {
      std::string s = Msg::GetString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 589:
#line 6228 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (4)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 590:
#line 6235 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 591:
#line 6244 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_String(NULL, (yyvsp[(3) - (5)].c2).char2, 1, 0, (yyvsp[(4) - (5)].c), 2);
    ;}
    break;

  case 592:
#line 6248 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(3) - (7)].c2).char1, (yyvsp[(3) - (7)].c2).char2, (yyvsp[(5) - (7)].c), 0, (yyvsp[(6) - (7)].c), 2);
    ;}
    break;

  case 593:
#line 6252 "Gmsh.y"
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

  case 594:
#line 6267 "Gmsh.y"
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

  case 595:
#line 6281 "Gmsh.y"
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

  case 596:
#line 6295 "Gmsh.y"
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

  case 597:
#line 6307 "Gmsh.y"
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

  case 598:
#line 6323 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = toupper((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 599:
#line 6332 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = tolower((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 600:
#line 6341 "Gmsh.y"
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

  case 601:
#line 6351 "Gmsh.y"
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

  case 602:
#line 6362 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (8)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (8)].d), (int)(yyvsp[(7) - (8)].d));
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (8)].c));
    ;}
    break;

  case 603:
#line 6370 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (6)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (6)].d), std::string::npos);
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 604:
#line 6378 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 605:
#line 6382 "Gmsh.y"
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

  case 606:
#line 6401 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 607:
#line 6408 "Gmsh.y"
    {
      std::string tmp = SplitFileName(GetAbsolutePath(gmsh_yyname))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
    ;}
    break;

  case 608:
#line 6414 "Gmsh.y"
    {
      std::string tmp = GetFileNameWithoutPath(gmsh_yyname);
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
    ;}
    break;

  case 609:
#line 6420 "Gmsh.y"
    {
      std::string tmp = SplitFileName((yyvsp[(3) - (4)].c))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 610:
#line 6427 "Gmsh.y"
    {
      std::string tmp = GetAbsolutePath((yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 611:
#line 6434 "Gmsh.y"
    { init_options(); ;}
    break;

  case 612:
#line 6436 "Gmsh.y"
    {
      std::string val((yyvsp[(3) - (6)].c));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.c) = (char*)Malloc((val.size() + 1) * sizeof(char));
      strcpy((yyval.c), val.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 613:
#line 6444 "Gmsh.y"
    {
      std::string out;
      const std::string * key_struct = NULL;
      switch (gmsh_yynamespaces.get_key_struct_from_tag(struct_namespace,
                                                        (int)(yyvsp[(3) - (4)].d), key_struct)) {
      case 0:
        out = *key_struct;
        break;
      case 1:
        yymsg(1, "Unknown NameSpace '%s' of Struct", struct_namespace.c_str());
        break;
      case 2:
        yymsg(1, "Unknown Struct of index %d", (int)(yyvsp[(3) - (4)].d));
        break;
      default:
        break;
      }
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
    ;}
    break;

  case 614:
#line 6468 "Gmsh.y"
    { struct_namespace = std::string(""); (yyval.d) = (yyvsp[(2) - (2)].d); ;}
    break;

  case 615:
#line 6470 "Gmsh.y"
    { struct_namespace = (yyvsp[(1) - (4)].c); Free((yyvsp[(1) - (4)].c)); (yyval.d) = (yyvsp[(4) - (4)].d); ;}
    break;

  case 616:
#line 6476 "Gmsh.y"
    { (yyval.l) = (yyvsp[(3) - (4)].l); ;}
    break;

  case 617:
#line 6481 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 618:
#line 6483 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 619:
#line 6488 "Gmsh.y"
    { (yyval.l) = (yyvsp[(2) - (3)].l); ;}
    break;

  case 620:
#line 6493 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].c)));
    ;}
    break;

  case 621:
#line 6498 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 622:
#line 6500 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].c)));
    ;}
    break;

  case 623:
#line 6504 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	char* c;
	List_Read((yyvsp[(3) - (3)].l), i, &c);
	List_Add((yyval.l), &c);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 624:
#line 6516 "Gmsh.y"
    {
      (yyval.l) = List_Create(20, 20, sizeof(char *));
      if(!gmsh_yystringsymbols.count((yyvsp[(1) - (3)].c)))
	yymsg(0, "Unknown string variable '%s'", (yyvsp[(1) - (3)].c));
      else{
        std::vector<std::string> &s(gmsh_yystringsymbols[(yyvsp[(1) - (3)].c)]);
	for(std::size_t i = 0; i < s.size(); i++) {
          char * val_ = strsave((char*)s.at(i).c_str());
	  List_Add((yyval.l), &val_);
        }
      }
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 625:
#line 6530 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfString(NULL, (yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c));
    ;}
    break;

  case 626:
#line 6534 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfString((yyvsp[(1) - (7)].c), (yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].c));
    ;}
    break;

  case 627:
#line 6541 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 628:
#line 6549 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char)) ;
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)) ; strcat((yyval.c), tmpstr) ;
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 629:
#line 6557 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(7) - (8)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(3) - (8)].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[(3) - (8)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(3) - (8)].c));
    ;}
    break;

  case 630:
#line 6568 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 631:
#line 6570 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 632:
#line 6573 "Gmsh.y"
    { (yyval.c) = (yyvsp[(3) - (4)].c); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 14583 "Gmsh.tab.cpp"
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


#line 6576 "Gmsh.y"


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
  for(std::size_t i = 0; i < strlen(format); i++)
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
      for(std::size_t i = 0; i < s.value.size(); i++){
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
      std::string s = it->first + "[] = Str({";
      for(std::size_t i = 0; i < it->second.size(); i++){
        if(i) s += ", ";
        s += std::string("\"") + it->second[i] + "\"";
      }
      s += "});";
      vec.push_back(s);
    }
  }
  if (gmsh_yynamespaces.size()){
    if(help){
      vec.push_back("//");
      vec.push_back("// Structures");
      vec.push_back("//");
    }
    std::vector<std::string> strs;
    gmsh_yynamespaces.sprint(strs);
    vec.insert(vec.end(), strs.begin(), strs.end());
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

void ListOfShapes2VectorOfPairs(List_T *list, std::vector<std::pair<int, int> > &v)
{
  for(int i = 0; i < List_Nbr(list); i++){
    Shape s;
    List_Read(list, i, &s);
    int dim = s.Type / 100 - 1;
    if(dim >= 0 && dim <= 3) v.push_back(std::pair<int, int>(dim, s.Num));
  }
}

void VectorOfPairs2ListOfShapes(const std::vector<std::pair<int, int> > &v, List_T *list)
{
  for(std::size_t i = 0; i < v.size(); i++){
    int dim = v[i].first;
    int tag = v[i].second;
    Shape s;
    s.Type = (dim == 3) ? MSH_VOLUME : (dim == 2) ? MSH_SURF_PLAN :
      (dim == 1) ? MSH_SEGM_LINE : MSH_POINT;
    s.Num = tag;
    List_Add(list, &s);
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

  GFace *target = GModel::current()->getFaceByTag(std::abs(iTarget));
  GFace *source = GModel::current()->getFaceByTag(std::abs(iSource));
  if (!target || !source) {
    Msg::Error("Could not find surface %d or %d for periodic copy",
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

  GFace *target = GModel::current()->getFaceByTag(std::abs(iTarget));
  GFace *source = GModel::current()->getFaceByTag(std::abs(iSource));
  if (!target || !source) {
    Msg::Error("Could not find surface %d or %d for periodic copy",
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

  GEdge *target = GModel::current()->getEdgeByTag(std::abs(iTarget));
  GEdge *source = GModel::current()->getEdgeByTag(std::abs(iSource));
  if (!target || !source)
    Msg::Error("Could not find curve %d or %d for periodic copy",
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
      yymsg(0, "Unknown model surface with tag %d", tag2);
      return;
    }
    for(std::size_t i = 0; i < tags.size(); i++){
      if(dim == 0){
        GVertex *gv = GModel::current()->getVertexByTag(tags[i]);
        if(gv)
          gf->addEmbeddedVertex(gv);
        else
          yymsg(0, "Unknown model point %d", tags[i]);
      }
      else if(dim == 1){
        GEdge *ge = GModel::current()->getEdgeByTag(tags[i]);
        if(ge)
          gf->addEmbeddedEdge(ge);
        else
          yymsg(0, "Unknown model curve %d", tags[i]);
      }
    }
  }
  else if(dim2 == 3){
    GRegion *gr = GModel::current()->getRegionByTag(tag2);
    if(!gr){
      yymsg(0, "Unknown model volume with tag %d", tag2);
      return;
    }
    for(std::size_t i = 0; i < tags.size(); i++){
      if(dim == 0){
        GVertex *gv = GModel::current()->getVertexByTag(tags[i]);
        if(gv)
          gr->addEmbeddedVertex(gv);
        else
          yymsg(0, "Unknown model point with tag %d", tags[i]);
      }
      else if(dim == 1){
        GEdge *ge = GModel::current()->getEdgeByTag(tags[i]);
        if(ge)
          gr->addEmbeddedEdge(ge);
        else
          yymsg(0, "Unknown model curve with tag %d", tags[i]);
      }
      else if(dim == 2){
        GFace *gf = GModel::current()->getFaceByTag(tags[i]);
        if(gf)
          gr->addEmbeddedFace(gf);
        else
          yymsg(0, "Unknown model surface with tag %d", tags[i]);
      }
    }
  }
}

void removeEmbedded(const std::vector<std::pair<int, int> > &dimTags,
                    int rdim)
{
  if(GModel::current()->getOCCInternals() &&
     GModel::current()->getOCCInternals()->getChanged())
    GModel::current()->getOCCInternals()->synchronize(GModel::current());
  if(GModel::current()->getGEOInternals()->getChanged())
    GModel::current()->getGEOInternals()->synchronize(GModel::current());

  for(std::size_t i = 0; i < dimTags.size(); i++){
    int dim = dimTags[i].first, tag = dimTags[i].second;
    if(dim == 2){
      GFace *gf = GModel::current()->getFaceByTag(tag);
      if(gf) {
        if(rdim < 0 || rdim == 1) gf->embeddedEdges().clear();
        if(rdim < 0 || rdim == 0) gf->embeddedVertices().clear();
      }
      else
        yymsg(0, "Unknown model surface with tag %d", tag);
    }
    else if(dimTags[i].first == 3){
      GRegion *gr = GModel::current()->getRegionByTag(tag);
      if(gr) {
        if(rdim < 0 || rdim == 2) gr->embeddedFaces().clear();
        if(rdim < 0 || rdim == 1) gr->embeddedEdges().clear();
        if(rdim < 0 || rdim == 0) gr->embeddedVertices().clear();
      }
      else
        yymsg(0, "Unknown model volume with tag %d", tag);
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
  for(std::size_t i = 0; i < entities.size(); i++){
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
  if(GModel::current()->getOCCInternals() &&
     GModel::current()->getOCCInternals()->getChanged())
    GModel::current()->getOCCInternals()->synchronize(GModel::current());
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
  for(std::size_t i = 0; i < entities.size(); i++){
    double d = entities[i]->tag();
    List_Add(out, &d);
  }
}

void getParentTags(int dim, List_T *in, List_T *out)
{
  if(GModel::current()->getOCCInternals() &&
     GModel::current()->getOCCInternals()->getChanged())
    GModel::current()->getOCCInternals()->synchronize(GModel::current());
  if(GModel::current()->getGEOInternals()->getChanged())
    GModel::current()->getGEOInternals()->synchronize(GModel::current());

  for(int i = 0; i < List_Nbr(in); i++){
    double num;
    List_Read(in, i, &num);
    GEntity *ge = GModel::current()->getEntityByTag(dim, (int)num);
    if(ge){
      GEntity *parent = ge->getParentEntity();
      if(parent){
        double tag = parent->tag();
        List_Add(out, &tag);
      }
    }
  }
}

void getBoundingBox(int dim, List_T *in, List_T *out)
{
  if(GModel::current()->getOCCInternals() &&
     GModel::current()->getOCCInternals()->getChanged())
    GModel::current()->getOCCInternals()->synchronize(GModel::current());
  if(GModel::current()->getGEOInternals()->getChanged())
    GModel::current()->getGEOInternals()->synchronize(GModel::current());

  SBoundingBox3d box;
  for(int i = 0; i < List_Nbr(in); i++){
    double num;
    List_Read(in, i, &num);
    GEntity *ge = GModel::current()->getEntityByTag(dim, (int)num);
    if(ge) box += ge->bounds();
  }
  if(!box.empty()){
    double b[6] = {box.min().x(), box.min().y(), box.min().z(),
                   box.max().x(), box.max().y(), box.max().z()};
    for(int i = 0; i < 6; i++)
      List_Add(out, &b[i]);
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
  for(std::size_t i = 0; i < entities.size(); i++){
    entities[i]->setVisibility(visible);
  }
}

void setVisibility(const std::vector<std::pair<int, int> > &dimTags,
                   int visible, bool recursive)
{
  if(GModel::current()->getOCCInternals() &&
     GModel::current()->getOCCInternals()->getChanged())
    GModel::current()->getOCCInternals()->synchronize(GModel::current());
  if(GModel::current()->getGEOInternals()->getChanged())
    GModel::current()->getGEOInternals()->synchronize(GModel::current());

  for(std::size_t i = 0; i < dimTags.size(); i++){
    GEntity *ge = GModel::current()->getEntityByTag
      (dimTags[i].first, std::abs(dimTags[i].second));
    if(ge) ge->setVisibility(visible, recursive);
  }
}

void setColor(const std::vector<std::pair<int, int> > &dimTags,
              unsigned int val, bool recursive)
{
  if(GModel::current()->getOCCInternals() &&
     GModel::current()->getOCCInternals()->getChanged())
    GModel::current()->getOCCInternals()->synchronize(GModel::current());
  if(GModel::current()->getGEOInternals()->getChanged())
    GModel::current()->getGEOInternals()->synchronize(GModel::current());

  for(std::size_t i = 0; i < dimTags.size(); i++){
    GEntity *ge = GModel::current()->getEntityByTag
      (dimTags[i].first, std::abs(dimTags[i].second));
    if(ge) ge->setColor(val, recursive);
  }
}

double treat_Struct_FullName_Float
(char* c1, char* c2, int type_var, int index, double val_default, int type_treat)
{
  double out;
  if(!c1 && gmsh_yysymbols.count(c2)){
    if (type_treat == 1) out = 1.; // Exists (type_treat == 1)
    else { // Get (0) or GetForced (2)
      if (type_var == 1) {
        gmsh_yysymbol &s(gmsh_yysymbols[c2]);
        if(s.value.empty()){
          out = val_default;
          if (type_treat == 0) yymsg(0, "Uninitialized variable '%s'", c2);
        }
        else
          out = s.value[0];
      }
      else if (type_var == 2) {
        gmsh_yysymbol &s(gmsh_yysymbols[c2]);
        if(index < 0 || (int)s.value.size() < index + 1){
          out = val_default;
          if (type_treat == 0) yymsg(0, "Uninitialized variable '%s[%d]'", c2, index);
        }
        else{
          out = s.value[index];
        }
      }
      else {
        out = val_default;
      }
    }
  }
  else if(!c1 && type_treat == 1 && gmsh_yystringsymbols.count(c2)) {
    out = 1.;
  }
  else{
    if (type_var == 1) {
      std::string struct_namespace(c1? c1 : std::string("")), struct_name(c2);
      if(gmsh_yynamespaces.getTag(struct_namespace, struct_name, out)) {
        out = val_default;
        if (type_treat == 0) yymsg(0, "Unknown variable '%s'", struct_name.c_str());
      }
    }
    else {
      out = val_default;
      if (type_treat == 0) yymsg(0, "Unknown variable '%s(.)'", c2);
    }
  }
  Free(c1); Free(c2);
  return out;
}

double treat_Struct_FullName_dot_tSTRING_Float
(char* c1, char* c2, char* c3, int index, double val_default, int type_treat)
{
  double out;
  std::string struct_namespace(c1? c1 : std::string("")), struct_name(c2);
  std::string key_member(c3);
  switch (gmsh_yynamespaces.getMember
          (struct_namespace, struct_name, key_member, out, index)) {
  case 0:
    if (type_treat == 1) out = 1.; // Exists (type_treat == 1)
    break;
  case 1:
    if (!NumberOption(GMSH_GET, c2, 0, c3, out, type_treat==0))
      out = val_default;
    break;
  case 2:
    if (type_treat != 0) {
      const std::string * out_dummy = NULL;
      out = (gmsh_yynamespaces.getMember
             (struct_namespace, struct_name, key_member, out_dummy))?
        val_default : 1.;
    }
    else {
      out = val_default;
      if (type_treat == 0)
        yymsg(0, "Unknown member '%s' of Struct %s", c3, struct_name.c_str());
    }
    break;
  case 3:
    out = val_default;
    if (type_treat == 0)
      yymsg(0, "Index %d out of range", index);
    break;
  }
  Free(c1); Free(c2);
  Free(c3);
  return out;
}

List_T * treat_Struct_FullName_dot_tSTRING_ListOfFloat
(char* c1, char* c2, char* c3)
{
  List_T * out, * val_default = NULL;
  const std::vector<double> * out_vector; double val_;
  std::string struct_namespace(c1? c1 : std::string("")), struct_name(c2);
  std::string key_member(c3);
  switch (gmsh_yynamespaces.getMember_Vector
          (struct_namespace, struct_name, key_member, out_vector)) {
  case 0:
    out = List_Create(out_vector->size(), 1, sizeof(double));
    for(std::size_t i = 0; i < out_vector->size(); i++) {
      val_ = out_vector->at(i);
      List_Add(out, &val_);
    }
    break;
  case 1:
    yymsg(0, "Unknown Struct: %s", struct_name.c_str());
    out = val_default;
    break;
  case 2:
    out = val_default;
    yymsg(0, "Unknown member '%s' of Struct %s", c3, struct_name.c_str());
    break;
  }
  Free(c1); Free(c2);
  Free(c3);
  return out;
}

int treat_Struct_FullName_dot_tSTRING_Float_getDim
(char* c1, char* c2, char* c3)
{
  int out;
  std::string struct_namespace(c1? c1 : std::string("")), struct_name(c2);
  std::string key_member(c3);
  switch (gmsh_yynamespaces.getMember_Dim
          (struct_namespace, struct_name, key_member, out)) {
  case 0:
    break;
  case 1:
    out = 0;
    break;
  case 2:
    out = 0;
    yymsg(0, "Unknown member '%s' of Struct %s", c3, struct_name.c_str());
    break;
  }
  Free(c1); Free(c2);
  Free(c3);
  return out;
}

char * treat_Struct_FullName_String
(char* c1, char* c2, int type_var, int index, char * val_default, int type_treat)
{
  std::string string_default(val_default? val_default : std::string(""));
  const std::string * out = NULL;
  std::string out_tmp;
  if(!c1 && gmsh_yystringsymbols.count(c2)){
    // Get (0) or GetForced (2)
    if(gmsh_yystringsymbols[c2].size() != 1){
      out = &string_default;
      if (type_treat == 0)
        yymsg(0, "Expected single valued string variable '%s'", c2);
    }
    else {
      out_tmp = gmsh_yystringsymbols[c2][0];
      out = &out_tmp;
    }
  }
  else{
    out = &string_default;
    if (type_treat == 0) yymsg(0, "Unknown string variable '%s'", c2);
  }
  char* out_c = (char*)Malloc((out->size() + 1) * sizeof(char));
  strcpy(out_c, out->c_str());
  Free(c1); Free(c2);
  return out_c;
}

char* treat_Struct_FullName_dot_tSTRING_String
(char* c1, char* c2, char* c3, int index, char * val_default, int type_treat)
{
  std::string string_default(val_default? val_default : std::string(""));
  const std::string * out = NULL;
  std::string out_tmp; // PD: we should avoid that -> StringOption() to be changed
  std::string struct_namespace(c1? c1 : std::string("")), struct_name(c2);
  std::string key_member(c3);
  switch (gmsh_yynamespaces.getMember
          (struct_namespace, struct_name, key_member, out, index)) {
  case 0:
    break;
  case 1:
    if (StringOption(GMSH_GET, c2, 0, c3, out_tmp, type_treat==0))
      out = &out_tmp;
    else
      out = &string_default;
    break;
  case 2:
    out = &string_default;
    if (type_treat == 0)
      yymsg(0, "Unknown member '%s' of Struct %s", c3, struct_name.c_str());
    break;
  case 3:
    out = &string_default;
    if (type_treat == 0)
      yymsg(0, "Index %d out of range", index);
    break;
  }
  char* out_c = (char*)Malloc((out->size() + 1) * sizeof(char));
  strcpy(out_c, out->c_str());
  Free(c1); Free(c2);
  Free(c3);
  return out_c;
}

List_T * treat_Struct_FullName_dot_tSTRING_ListOfString
(char* c1, char* c2, char* c3)
{
  List_T * out, * val_default = NULL;
  const std::vector<std::string> * out_vector; char * val_;
  std::string struct_namespace(c1? c1 : std::string("")), struct_name(c2);
  std::string key_member(c3);
  switch (gmsh_yynamespaces.getMember_Vector
          (struct_namespace, struct_name, key_member, out_vector)) {
  case 0:
    out = List_Create(out_vector->size(), 1, sizeof(char *));
    for(std::size_t i = 0; i < out_vector->size(); i++) {
      val_ = strsave((char*)out_vector->at(i).c_str());
      List_Add(out, &val_);
    }
    break;
  case 1:
    yymsg(0, "Unknown Struct: %s", struct_name.c_str());
    out = val_default;
    break;
  case 2:
    out = val_default;
    yymsg(0, "Unknown member '%s' of Struct %s", c3, struct_name.c_str());
    break;
  }
  Free(c1); Free(c2);
  Free(c3);
  return out;
}

