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
     tStep = 281,
     tAtan = 282,
     tAtan2 = 283,
     tSinh = 284,
     tCosh = 285,
     tTanh = 286,
     tFabs = 287,
     tAbs = 288,
     tFloor = 289,
     tCeil = 290,
     tRound = 291,
     tMin = 292,
     tMax = 293,
     tFmod = 294,
     tModulo = 295,
     tHypot = 296,
     tList = 297,
     tLinSpace = 298,
     tLogSpace = 299,
     tListFromFile = 300,
     tCatenary = 301,
     tPrintf = 302,
     tError = 303,
     tWarning = 304,
     tStr = 305,
     tSprintf = 306,
     tStrCat = 307,
     tStrPrefix = 308,
     tStrRelative = 309,
     tStrReplace = 310,
     tAbsolutePath = 311,
     tDirName = 312,
     tStrSub = 313,
     tStrLen = 314,
     tFind = 315,
     tStrFind = 316,
     tStrCmp = 317,
     tStrChoice = 318,
     tUpperCase = 319,
     tLowerCase = 320,
     tLowerCaseIn = 321,
     tTextAttributes = 322,
     tBoundingBox = 323,
     tDraw = 324,
     tSetChanged = 325,
     tToday = 326,
     tFixRelativePath = 327,
     tCurrentDirectory = 328,
     tCurrentFileName = 329,
     tSyncModel = 330,
     tNewModel = 331,
     tMass = 332,
     tCenterOfMass = 333,
     tMatrixOfInertia = 334,
     tOnelabAction = 335,
     tOnelabRun = 336,
     tCodeName = 337,
     tCpu = 338,
     tMemory = 339,
     tTotalMemory = 340,
     tCreateTopology = 341,
     tCreateGeometry = 342,
     tClassifySurfaces = 343,
     tRenumberMeshNodes = 344,
     tRenumberMeshElements = 345,
     tDistanceFunction = 346,
     tDefineConstant = 347,
     tUndefineConstant = 348,
     tDefineNumber = 349,
     tDefineStruct = 350,
     tNameStruct = 351,
     tDimNameSpace = 352,
     tAppend = 353,
     tDefineString = 354,
     tSetNumber = 355,
     tSetTag = 356,
     tSetString = 357,
     tPoint = 358,
     tCircle = 359,
     tEllipse = 360,
     tCurve = 361,
     tSphere = 362,
     tPolarSphere = 363,
     tSurface = 364,
     tSpline = 365,
     tVolume = 366,
     tBox = 367,
     tCylinder = 368,
     tCone = 369,
     tTorus = 370,
     tEllipsoid = 371,
     tQuadric = 372,
     tShapeFromFile = 373,
     tRectangle = 374,
     tDisk = 375,
     tWire = 376,
     tGeoEntity = 377,
     tNormal = 378,
     tCurvature = 379,
     tCharacteristic = 380,
     tLength = 381,
     tParametric = 382,
     tElliptic = 383,
     tRefineMesh = 384,
     tRecombineMesh = 385,
     tAdaptMesh = 386,
     tTransformMesh = 387,
     tRelocateMesh = 388,
     tReorientMesh = 389,
     tSetFactory = 390,
     tThruSections = 391,
     tWedge = 392,
     tFillet = 393,
     tChamfer = 394,
     tPlane = 395,
     tRuled = 396,
     tTransfinite = 397,
     tPhysical = 398,
     tCompound = 399,
     tPeriodic = 400,
     tParent = 401,
     tUsing = 402,
     tPlugin = 403,
     tDegenerated = 404,
     tRecursive = 405,
     tSewing = 406,
     tRotate = 407,
     tTranslate = 408,
     tSymmetry = 409,
     tDilate = 410,
     tExtrude = 411,
     tLevelset = 412,
     tAffine = 413,
     tClosest = 414,
     tBooleanUnion = 415,
     tBooleanIntersection = 416,
     tBooleanDifference = 417,
     tBooleanSection = 418,
     tBooleanFragments = 419,
     tThickSolid = 420,
     tRecombine = 421,
     tSmoother = 422,
     tSplit = 423,
     tDelete = 424,
     tCoherence = 425,
     tHealShapes = 426,
     tIntersect = 427,
     tMeshAlgorithm = 428,
     tReverseMesh = 429,
     tMeshSize = 430,
     tMeshSizeFromBoundary = 431,
     tLayers = 432,
     tScaleLast = 433,
     tHole = 434,
     tAlias = 435,
     tAliasWithOptions = 436,
     tCopyOptions = 437,
     tQuadTriAddVerts = 438,
     tQuadTriNoNewVerts = 439,
     tRecombLaterals = 440,
     tTransfQuadTri = 441,
     tText2D = 442,
     tText3D = 443,
     tInterpolationScheme = 444,
     tTime = 445,
     tCombine = 446,
     tBSpline = 447,
     tBezier = 448,
     tNurbs = 449,
     tNurbsOrder = 450,
     tNurbsKnots = 451,
     tColor = 452,
     tColorTable = 453,
     tFor = 454,
     tIn = 455,
     tEndFor = 456,
     tIf = 457,
     tElseIf = 458,
     tElse = 459,
     tEndIf = 460,
     tExit = 461,
     tAbort = 462,
     tField = 463,
     tReturn = 464,
     tCall = 465,
     tSlide = 466,
     tMacro = 467,
     tShow = 468,
     tHide = 469,
     tGetValue = 470,
     tGetStringValue = 471,
     tGetEnv = 472,
     tGetString = 473,
     tGetNumber = 474,
     tUnique = 475,
     tSetMaxTag = 476,
     tHomology = 477,
     tCohomology = 478,
     tBetti = 479,
     tExists = 480,
     tFileExists = 481,
     tGetForced = 482,
     tGetForcedStr = 483,
     tGMSH_MAJOR_VERSION = 484,
     tGMSH_MINOR_VERSION = 485,
     tGMSH_PATCH_VERSION = 486,
     tGmshExecutableName = 487,
     tSetPartition = 488,
     tNameToString = 489,
     tStringToName = 490,
     tUnsplitWindow = 491,
     tAFFECTDIVIDE = 492,
     tAFFECTTIMES = 493,
     tAFFECTMINUS = 494,
     tAFFECTPLUS = 495,
     tOR = 496,
     tAND = 497,
     tNOTEQUAL = 498,
     tEQUAL = 499,
     tGREATERGREATER = 500,
     tLESSLESS = 501,
     tGREATEROREQUAL = 502,
     tLESSOREQUAL = 503,
     UNARYPREC = 504,
     tMINUSMINUS = 505,
     tPLUSPLUS = 506
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
#define tStep 281
#define tAtan 282
#define tAtan2 283
#define tSinh 284
#define tCosh 285
#define tTanh 286
#define tFabs 287
#define tAbs 288
#define tFloor 289
#define tCeil 290
#define tRound 291
#define tMin 292
#define tMax 293
#define tFmod 294
#define tModulo 295
#define tHypot 296
#define tList 297
#define tLinSpace 298
#define tLogSpace 299
#define tListFromFile 300
#define tCatenary 301
#define tPrintf 302
#define tError 303
#define tWarning 304
#define tStr 305
#define tSprintf 306
#define tStrCat 307
#define tStrPrefix 308
#define tStrRelative 309
#define tStrReplace 310
#define tAbsolutePath 311
#define tDirName 312
#define tStrSub 313
#define tStrLen 314
#define tFind 315
#define tStrFind 316
#define tStrCmp 317
#define tStrChoice 318
#define tUpperCase 319
#define tLowerCase 320
#define tLowerCaseIn 321
#define tTextAttributes 322
#define tBoundingBox 323
#define tDraw 324
#define tSetChanged 325
#define tToday 326
#define tFixRelativePath 327
#define tCurrentDirectory 328
#define tCurrentFileName 329
#define tSyncModel 330
#define tNewModel 331
#define tMass 332
#define tCenterOfMass 333
#define tMatrixOfInertia 334
#define tOnelabAction 335
#define tOnelabRun 336
#define tCodeName 337
#define tCpu 338
#define tMemory 339
#define tTotalMemory 340
#define tCreateTopology 341
#define tCreateGeometry 342
#define tClassifySurfaces 343
#define tRenumberMeshNodes 344
#define tRenumberMeshElements 345
#define tDistanceFunction 346
#define tDefineConstant 347
#define tUndefineConstant 348
#define tDefineNumber 349
#define tDefineStruct 350
#define tNameStruct 351
#define tDimNameSpace 352
#define tAppend 353
#define tDefineString 354
#define tSetNumber 355
#define tSetTag 356
#define tSetString 357
#define tPoint 358
#define tCircle 359
#define tEllipse 360
#define tCurve 361
#define tSphere 362
#define tPolarSphere 363
#define tSurface 364
#define tSpline 365
#define tVolume 366
#define tBox 367
#define tCylinder 368
#define tCone 369
#define tTorus 370
#define tEllipsoid 371
#define tQuadric 372
#define tShapeFromFile 373
#define tRectangle 374
#define tDisk 375
#define tWire 376
#define tGeoEntity 377
#define tNormal 378
#define tCurvature 379
#define tCharacteristic 380
#define tLength 381
#define tParametric 382
#define tElliptic 383
#define tRefineMesh 384
#define tRecombineMesh 385
#define tAdaptMesh 386
#define tTransformMesh 387
#define tRelocateMesh 388
#define tReorientMesh 389
#define tSetFactory 390
#define tThruSections 391
#define tWedge 392
#define tFillet 393
#define tChamfer 394
#define tPlane 395
#define tRuled 396
#define tTransfinite 397
#define tPhysical 398
#define tCompound 399
#define tPeriodic 400
#define tParent 401
#define tUsing 402
#define tPlugin 403
#define tDegenerated 404
#define tRecursive 405
#define tSewing 406
#define tRotate 407
#define tTranslate 408
#define tSymmetry 409
#define tDilate 410
#define tExtrude 411
#define tLevelset 412
#define tAffine 413
#define tClosest 414
#define tBooleanUnion 415
#define tBooleanIntersection 416
#define tBooleanDifference 417
#define tBooleanSection 418
#define tBooleanFragments 419
#define tThickSolid 420
#define tRecombine 421
#define tSmoother 422
#define tSplit 423
#define tDelete 424
#define tCoherence 425
#define tHealShapes 426
#define tIntersect 427
#define tMeshAlgorithm 428
#define tReverseMesh 429
#define tMeshSize 430
#define tMeshSizeFromBoundary 431
#define tLayers 432
#define tScaleLast 433
#define tHole 434
#define tAlias 435
#define tAliasWithOptions 436
#define tCopyOptions 437
#define tQuadTriAddVerts 438
#define tQuadTriNoNewVerts 439
#define tRecombLaterals 440
#define tTransfQuadTri 441
#define tText2D 442
#define tText3D 443
#define tInterpolationScheme 444
#define tTime 445
#define tCombine 446
#define tBSpline 447
#define tBezier 448
#define tNurbs 449
#define tNurbsOrder 450
#define tNurbsKnots 451
#define tColor 452
#define tColorTable 453
#define tFor 454
#define tIn 455
#define tEndFor 456
#define tIf 457
#define tElseIf 458
#define tElse 459
#define tEndIf 460
#define tExit 461
#define tAbort 462
#define tField 463
#define tReturn 464
#define tCall 465
#define tSlide 466
#define tMacro 467
#define tShow 468
#define tHide 469
#define tGetValue 470
#define tGetStringValue 471
#define tGetEnv 472
#define tGetString 473
#define tGetNumber 474
#define tUnique 475
#define tSetMaxTag 476
#define tHomology 477
#define tCohomology 478
#define tBetti 479
#define tExists 480
#define tFileExists 481
#define tGetForced 482
#define tGetForcedStr 483
#define tGMSH_MAJOR_VERSION 484
#define tGMSH_MINOR_VERSION 485
#define tGMSH_PATCH_VERSION 486
#define tGmshExecutableName 487
#define tSetPartition 488
#define tNameToString 489
#define tStringToName 490
#define tUnsplitWindow 491
#define tAFFECTDIVIDE 492
#define tAFFECTTIMES 493
#define tAFFECTMINUS 494
#define tAFFECTPLUS 495
#define tOR 496
#define tAND 497
#define tNOTEQUAL 498
#define tEQUAL 499
#define tGREATERGREATER 500
#define tLESSLESS 501
#define tGREATEROREQUAL 502
#define tLESSOREQUAL 503
#define UNARYPREC 504
#define tMINUSMINUS 505
#define tPLUSPLUS 506




/* Copy the first part of user declarations.  */
#line 1 "Gmsh.y"

// Gmsh - Copyright (C) 1997-2025 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

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

#if defined(HAVE_FLTK)
#include "FlGui.h"
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
int printListOfDouble(const char *format, List_T *list, std::string &buffer);
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
   char* val_default = nullptr, int type_treat = 0);
char* treat_Struct_FullName_dot_tSTRING_String
  (char* c1, char* c2, char* c3, int index = 0,
   char* val_default = nullptr, int type_treat = 0);
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
#line 169 "Gmsh.y"
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
#line 785 "Gmsh.tab.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 798 "Gmsh.tab.cpp"

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
#define YYLAST   19196

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  274
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  115
/* YYNRULES -- Number of rules.  */
#define YYNRULES  655
/* YYNRULES -- Number of states.  */
#define YYNSTATES  2363

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   506

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint16 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   259,     2,   271,     2,   256,   258,     2,
     264,   265,   254,   252,   273,   253,   270,   255,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     246,     2,   247,   241,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   266,     2,   267,   263,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   268,   257,   269,   272,     2,     2,     2,
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
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   242,   243,   244,   245,
     248,   249,   250,   251,   260,   261,   262
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
     298,   300,   302,   304,   310,   316,   319,   327,   335,   340,
     344,   351,   361,   369,   376,   384,   391,   396,   405,   415,
     425,   432,   442,   449,   459,   465,   474,   483,   495,   502,
     512,   518,   526,   536,   546,   556,   564,   574,   584,   585,
     587,   588,   592,   598,   599,   609,   610,   622,   628,   629,
     639,   640,   644,   648,   654,   660,   661,   664,   665,   667,
     669,   673,   676,   679,   682,   685,   687,   692,   695,   698,
     699,   702,   704,   708,   711,   714,   717,   720,   723,   725,
     727,   731,   732,   738,   744,   750,   751,   754,   755,   758,
     766,   774,   782,   793,   804,   813,   822,   830,   838,   850,
     858,   867,   876,   885,   895,   904,   913,   917,   922,   933,
     941,   949,   957,   965,   973,   981,   989,   997,  1005,  1013,
    1023,  1031,  1039,  1048,  1057,  1070,  1071,  1081,  1083,  1085,
    1087,  1089,  1094,  1096,  1098,  1100,  1105,  1107,  1109,  1114,
    1116,  1118,  1120,  1125,  1131,  1143,  1149,  1159,  1169,  1177,
    1185,  1190,  1200,  1211,  1221,  1223,  1225,  1226,  1229,  1236,
    1244,  1252,  1259,  1267,  1276,  1287,  1302,  1319,  1332,  1347,
    1362,  1377,  1392,  1401,  1410,  1417,  1422,  1428,  1434,  1441,
    1448,  1452,  1457,  1461,  1467,  1474,  1480,  1485,  1489,  1494,
    1498,  1503,  1509,  1514,  1520,  1524,  1530,  1538,  1546,  1550,
    1553,  1561,  1565,  1568,  1572,  1575,  1578,  1581,  1584,  1600,
    1603,  1606,  1614,  1617,  1627,  1639,  1642,  1647,  1650,  1653,
    1656,  1659,  1676,  1682,  1691,  1703,  1710,  1719,  1728,  1739,
    1741,  1744,  1747,  1749,  1753,  1757,  1762,  1767,  1769,  1771,
    1777,  1789,  1803,  1804,  1812,  1813,  1827,  1828,  1844,  1845,
    1852,  1862,  1865,  1869,  1880,  1894,  1896,  1899,  1905,  1913,
    1916,  1919,  1923,  1926,  1930,  1933,  1937,  1947,  1954,  1956,
    1958,  1960,  1962,  1964,  1965,  1968,  1972,  1976,  1981,  1991,
    1996,  2011,  2012,  2016,  2017,  2019,  2020,  2023,  2024,  2027,
    2028,  2031,  2037,  2044,  2052,  2059,  2065,  2069,  2078,  2085,
    2094,  2103,  2109,  2114,  2121,  2133,  2145,  2164,  2183,  2196,
    2209,  2222,  2233,  2238,  2243,  2248,  2253,  2258,  2265,  2268,
    2272,  2279,  2282,  2284,  2286,  2288,  2291,  2297,  2305,  2316,
    2318,  2322,  2325,  2328,  2331,  2335,  2339,  2343,  2347,  2351,
    2355,  2359,  2363,  2367,  2371,  2375,  2379,  2383,  2387,  2391,
    2395,  2399,  2403,  2409,  2414,  2419,  2424,  2429,  2434,  2439,
    2444,  2449,  2454,  2459,  2464,  2471,  2476,  2481,  2486,  2491,
    2496,  2501,  2506,  2511,  2518,  2525,  2532,  2537,  2544,  2551,
    2553,  2555,  2557,  2559,  2561,  2563,  2565,  2567,  2569,  2571,
    2573,  2574,  2581,  2583,  2588,  2595,  2597,  2602,  2607,  2612,
    2619,  2625,  2633,  2642,  2653,  2658,  2663,  2670,  2675,  2679,
    2682,  2688,  2694,  2698,  2704,  2711,  2720,  2727,  2736,  2743,
    2748,  2756,  2763,  2770,  2777,  2782,  2789,  2794,  2795,  2798,
    2799,  2802,  2803,  2811,  2813,  2817,  2819,  2822,  2823,  2827,
    2829,  2832,  2835,  2839,  2843,  2855,  2865,  2873,  2881,  2883,
    2887,  2889,  2891,  2894,  2898,  2903,  2909,  2912,  2916,  2921,
    2923,  2927,  2929,  2932,  2936,  2940,  2946,  2951,  2956,  2959,
    2964,  2967,  2971,  2975,  2980,  2986,  2992,  2998,  3004,  3011,
    3023,  3035,  3045,  3056,  3062,  3064,  3066,  3068,  3072,  3078,
    3086,  3091,  3096,  3101,  3108,  3115,  3124,  3133,  3138,  3153,
    3158,  3163,  3165,  3167,  3171,  3175,  3185,  3193,  3195,  3201,
    3205,  3212,  3214,  3218,  3220,  3222,  3227,  3232,  3236,  3242,
    3249,  3258,  3265,  3270,  3276,  3278,  3283,  3285,  3287,  3289,
    3291,  3296,  3303,  3308,  3315,  3321,  3329,  3334,  3339,  3344,
    3353,  3358,  3363,  3368,  3373,  3382,  3391,  3398,  3403,  3410,
    3415,  3417,  3419,  3424,  3429,  3430,  3437,  3442,  3445,  3450,
    3455,  3457,  3459,  3463,  3465,  3467,  3471,  3475,  3479,  3485,
    3493,  3499,  3505,  3514,  3516,  3518
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     275,     0,    -1,   276,    -1,     1,     6,    -1,    -1,   276,
     277,    -1,   279,    -1,   280,    -1,   301,    -1,   135,   264,
     378,   265,     6,    -1,   320,    -1,   326,    -1,   330,    -1,
     331,    -1,   332,    -1,   333,    -1,   337,    -1,   346,    -1,
     347,    -1,   353,    -1,   354,    -1,   336,    -1,   335,    -1,
     334,    -1,   329,    -1,   356,    -1,   247,    -1,   248,    -1,
      47,   264,   378,   265,     6,    -1,    49,   264,   378,   265,
       6,    -1,    48,   264,   378,   265,     6,    -1,    47,   264,
     378,   265,   278,   378,     6,    -1,    47,   264,   378,   273,
     374,   265,     6,    -1,    49,   264,   378,   273,   374,   265,
       6,    -1,    48,   264,   378,   273,   374,   265,     6,    -1,
      47,   264,   378,   273,   374,   265,   278,   378,     6,    -1,
     388,   378,   268,   281,   269,     6,    -1,   180,     4,   266,
     357,   267,     6,    -1,   181,     4,   266,   357,   267,     6,
      -1,   182,     4,   266,   357,   273,   357,   267,     6,    -1,
      -1,   281,   284,    -1,   281,   288,    -1,   281,   291,    -1,
     281,   293,    -1,   281,   294,    -1,   281,   336,    -1,   357,
      -1,   282,   273,   357,    -1,   357,    -1,   283,   273,   357,
      -1,    -1,    -1,     4,   285,   264,   282,   265,   286,   268,
     283,   269,     6,    -1,   378,    -1,   287,   273,   378,    -1,
      -1,   187,   264,   357,   273,   357,   273,   357,   265,   289,
     268,   287,   269,     6,    -1,   378,    -1,   290,   273,   378,
      -1,    -1,   188,   264,   357,   273,   357,   273,   357,   273,
     357,   265,   292,   268,   290,   269,     6,    -1,   189,   268,
     369,   269,   268,   369,   269,     6,    -1,   189,   268,   369,
     269,   268,   369,   269,   268,   369,   269,   268,   369,   269,
       6,    -1,    -1,   190,   295,   268,   283,   269,     6,    -1,
       7,    -1,   240,    -1,   239,    -1,   238,    -1,   237,    -1,
     262,    -1,   261,    -1,   264,    -1,   266,    -1,   265,    -1,
     267,    -1,     4,    -1,    37,    -1,    38,    -1,    26,    -1,
     112,    -1,   113,    -1,    92,   266,   303,   267,     6,    -1,
      93,   266,   307,   267,     6,    -1,   362,     6,    -1,   100,
     298,   379,   273,   357,   299,     6,    -1,   102,   298,   379,
     273,   379,   299,     6,    -1,   388,   296,   370,     6,    -1,
     388,   297,     6,    -1,   388,   298,   299,   296,   370,     6,
      -1,   388,   298,   268,   374,   269,   299,   296,   370,     6,
      -1,   388,   266,   357,   267,   296,   357,     6,    -1,   388,
     266,   357,   267,   297,     6,    -1,   388,   264,   357,   265,
     296,   357,     6,    -1,   388,   264,   357,   265,   297,     6,
      -1,   388,     7,   379,     6,    -1,   388,   298,   299,     7,
      50,   298,   299,     6,    -1,   388,   298,   299,     7,    50,
     298,   383,   299,     6,    -1,   388,   298,   299,   240,    50,
     298,   383,   299,     6,    -1,   388,   270,   300,     7,   379,
       6,    -1,   388,   266,   357,   267,   270,   300,     7,   379,
       6,    -1,   388,   270,   300,   296,   357,     6,    -1,   388,
     266,   357,   267,   270,   300,   296,   357,     6,    -1,   388,
     270,   300,   297,     6,    -1,   388,   266,   357,   267,   270,
     300,   297,     6,    -1,   388,   270,   197,   270,   300,     7,
     375,     6,    -1,   388,   266,   357,   267,   270,   197,   270,
     300,     7,   375,     6,    -1,   388,   270,   198,     7,   376,
       6,    -1,   388,   266,   357,   267,   270,   198,     7,   376,
       6,    -1,   388,   208,     7,   370,     6,    -1,   208,   266,
     357,   267,     7,   300,     6,    -1,   208,   266,   357,   267,
     270,   300,     7,   357,     6,    -1,   208,   266,   357,   267,
     270,   300,     7,   379,     6,    -1,   208,   266,   357,   267,
     270,   300,     7,   371,     6,    -1,   208,   266,   357,   267,
     270,   300,     6,    -1,   148,   264,     4,   265,   270,   300,
       7,   357,     6,    -1,   148,   264,     4,   265,   270,   300,
       7,   379,     6,    -1,    -1,   273,    -1,    -1,   303,   302,
     388,    -1,   303,   302,   388,     7,   357,    -1,    -1,   303,
     302,   388,     7,   268,   370,   304,   309,   269,    -1,    -1,
     303,   302,   388,   298,   299,     7,   268,   370,   305,   309,
     269,    -1,   303,   302,   388,     7,   379,    -1,    -1,   303,
     302,   388,     7,   268,   379,   306,   313,   269,    -1,    -1,
     307,   302,   378,    -1,   357,     7,   379,    -1,   308,   273,
     357,     7,   379,    -1,   373,     7,   388,   264,   265,    -1,
      -1,   273,   311,    -1,    -1,   311,    -1,   312,    -1,   311,
     273,   312,    -1,     4,   370,    -1,    37,   357,    -1,    38,
     357,    -1,    26,   357,    -1,     4,    -1,     4,   268,   308,
     269,    -1,     4,   379,    -1,     4,   382,    -1,    -1,   273,
     314,    -1,   315,    -1,   314,   273,   315,    -1,     4,   357,
      -1,     4,   379,    -1,   212,   379,    -1,     4,   384,    -1,
       4,   382,    -1,   357,    -1,   379,    -1,   379,   273,   357,
      -1,    -1,   200,   107,   268,   357,   269,    -1,   147,   103,
     268,   374,   269,    -1,   147,   122,   268,   374,   269,    -1,
      -1,   140,   367,    -1,    -1,   147,   151,    -1,   103,   264,
     357,   265,     7,   367,     6,    -1,   106,   264,   357,   265,
       7,   370,     6,    -1,   110,   264,   357,   265,     7,   370,
       6,    -1,   144,   110,   264,   357,   265,     7,   370,   147,
     357,     6,    -1,   144,   192,   264,   357,   265,     7,   370,
     147,   357,     6,    -1,   104,   264,   357,   265,     7,   370,
     318,     6,    -1,   105,   264,   357,   265,     7,   370,   318,
       6,    -1,   192,   264,   357,   265,     7,   370,     6,    -1,
     193,   264,   357,   265,     7,   370,     6,    -1,   194,   264,
     357,   265,     7,   370,   196,   370,   195,   357,     6,    -1,
     121,   264,   357,   265,     7,   370,     6,    -1,   106,     4,
     264,   357,   265,     7,   370,     6,    -1,   140,   109,   264,
     357,   265,     7,   370,     6,    -1,   109,   264,   357,   265,
       7,   370,   317,     6,    -1,   141,   109,   264,   357,   265,
       7,   370,   317,     6,    -1,   192,   109,   264,   357,   265,
       7,   370,     6,    -1,   193,   109,   264,   357,   265,     7,
     370,     6,    -1,    13,    14,     6,    -1,    14,   109,   357,
       6,    -1,   127,   109,   264,   357,   265,     7,     5,     5,
       5,     6,    -1,   107,   264,   357,   265,     7,   370,     6,
      -1,   108,   264,   357,   265,     7,   370,     6,    -1,   112,
     264,   357,   265,     7,   370,     6,    -1,   115,   264,   357,
     265,     7,   370,     6,    -1,   119,   264,   357,   265,     7,
     370,     6,    -1,   120,   264,   357,   265,     7,   370,     6,
      -1,   113,   264,   357,   265,     7,   370,     6,    -1,   114,
     264,   357,   265,     7,   370,     6,    -1,   137,   264,   357,
     265,     7,   370,     6,    -1,   165,   264,   357,   265,     7,
     370,     6,    -1,   109,     4,   264,   357,   265,     7,   370,
     319,     6,    -1,   111,   264,   357,   265,     7,   370,     6,
      -1,   136,   264,   357,   265,     7,   370,     6,    -1,   141,
     136,   264,   357,   265,     7,   370,     6,    -1,   144,   323,
     264,   357,   265,     7,   370,     6,    -1,   144,   323,   264,
     357,   265,     7,   370,     4,   268,   369,   269,     6,    -1,
      -1,   143,   322,   321,   264,   316,   265,   296,   370,     6,
      -1,   103,    -1,   106,    -1,   109,    -1,   111,    -1,   122,
     268,   357,   269,    -1,   106,    -1,   109,    -1,   111,    -1,
     122,   268,   357,   269,    -1,   106,    -1,   109,    -1,   122,
     268,   357,   269,    -1,   103,    -1,   106,    -1,   109,    -1,
     122,   268,   357,   269,    -1,   153,   367,   268,   327,   269,
      -1,   152,   268,   367,   273,   367,   273,   357,   269,   268,
     327,   269,    -1,   154,   367,   268,   327,   269,    -1,   155,
     268,   367,   273,   357,   269,   268,   327,   269,    -1,   155,
     268,   367,   273,   367,   269,   268,   327,   269,    -1,   158,
     268,   374,   269,   268,   327,   269,    -1,   159,   268,   374,
     269,   268,   327,   269,    -1,     4,   268,   327,   269,    -1,
     172,   106,   268,   374,   269,   109,   268,   357,   269,    -1,
     168,   106,   268,   357,   269,   103,   268,   374,   269,     6,
      -1,   168,   106,   264,   357,   265,   268,   374,   269,     6,
      -1,   328,    -1,   326,    -1,    -1,   328,   320,    -1,   328,
     322,   268,   374,   269,     6,    -1,   328,   143,   322,   268,
     374,   269,     6,    -1,   328,   146,   322,   268,   374,   269,
       6,    -1,   328,   322,   268,     8,   269,     6,    -1,   328,
     143,   322,   268,     8,   269,     6,    -1,   157,   140,   264,
     357,   265,     7,   370,     6,    -1,   157,   103,   264,   357,
     265,     7,   268,   369,   269,     6,    -1,   157,   140,   264,
     357,   265,     7,   268,   367,   273,   367,   273,   374,   269,
       6,    -1,   157,   140,   264,   357,   265,     7,   268,   367,
     273,   367,   273,   367,   273,   374,   269,     6,    -1,   157,
     107,   264,   357,   265,     7,   268,   367,   273,   374,   269,
       6,    -1,   157,   113,   264,   357,   265,     7,   268,   367,
     273,   367,   273,   374,   269,     6,    -1,   157,   114,   264,
     357,   265,     7,   268,   367,   273,   367,   273,   374,   269,
       6,    -1,   157,   116,   264,   357,   265,     7,   268,   367,
     273,   367,   273,   374,   269,     6,    -1,   157,   117,   264,
     357,   265,     7,   268,   367,   273,   367,   273,   374,   269,
       6,    -1,   157,     4,   264,   357,   265,     7,   370,     6,
      -1,   157,     4,   264,   357,   265,     7,     5,     6,    -1,
     157,     4,   268,   357,   269,     6,    -1,   169,   268,   328,
     269,    -1,   150,   169,   268,   328,   269,    -1,   169,     4,
     268,   328,   269,    -1,   169,   208,   266,   357,   267,     6,
      -1,   169,     4,   266,   357,   267,     6,    -1,   169,   388,
       6,    -1,   169,     4,     4,     6,    -1,   169,    95,     6,
      -1,   197,   375,   268,   328,   269,    -1,   150,   197,   375,
     268,   328,   269,    -1,   233,   357,   268,   328,   269,    -1,
     213,   268,     8,   269,    -1,   213,     5,     6,    -1,   214,
     268,     8,   269,    -1,   214,     5,     6,    -1,   213,   268,
     328,   269,    -1,   150,   213,   268,   328,   269,    -1,   214,
     268,   328,   269,    -1,   150,   214,   268,   328,   269,    -1,
     388,   379,     6,    -1,    81,   264,   385,   265,     6,    -1,
     388,   388,   266,   357,   267,   378,     6,    -1,   388,   388,
     388,   266,   357,   267,     6,    -1,   388,   357,     6,    -1,
     236,     6,    -1,   148,   264,     4,   265,   270,     4,     6,
      -1,   191,     4,     6,    -1,   206,     6,    -1,   206,   357,
       6,    -1,   207,     6,    -1,    75,     6,    -1,    76,     6,
      -1,    68,     6,    -1,    68,   268,   357,   273,   357,   273,
     357,   273,   357,   273,   357,   273,   357,   269,     6,    -1,
      69,     6,    -1,    70,     6,    -1,    86,   268,   357,   273,
     357,   269,     6,    -1,    86,     6,    -1,    88,   268,   357,
     273,   357,   273,   357,   269,     6,    -1,    88,   268,   357,
     273,   357,   273,   357,   273,   357,   269,     6,    -1,    87,
       6,    -1,    87,   268,   328,   269,    -1,    89,     6,    -1,
      90,     6,    -1,   129,     6,    -1,   130,     6,    -1,   131,
     268,   374,   269,   268,   374,   269,   268,   369,   269,   268,
     357,   273,   357,   269,     6,    -1,   132,   268,   374,   269,
       6,    -1,   132,   268,   374,   269,   268,   327,   269,     6,
      -1,   211,   264,   268,   374,   269,   273,   379,   273,   379,
     265,     6,    -1,   199,   264,   357,     8,   357,   265,    -1,
     199,   264,   357,     8,   357,     8,   357,   265,    -1,   199,
       4,   200,   268,   357,     8,   357,   269,    -1,   199,     4,
     200,   268,   357,     8,   357,     8,   357,   269,    -1,   201,
      -1,   212,     4,    -1,   212,   379,    -1,   209,    -1,   210,
     388,     6,    -1,   210,   379,     6,    -1,   202,   264,   357,
     265,    -1,   203,   264,   357,   265,    -1,   204,    -1,   205,
      -1,   156,   367,   268,   328,   269,    -1,   156,   268,   367,
     273,   367,   273,   357,   269,   268,   328,   269,    -1,   156,
     268,   367,   273,   367,   273,   367,   273,   357,   269,   268,
     328,   269,    -1,    -1,   156,   367,   268,   328,   338,   342,
     269,    -1,    -1,   156,   268,   367,   273,   367,   273,   357,
     269,   268,   328,   339,   342,   269,    -1,    -1,   156,   268,
     367,   273,   367,   273,   367,   273,   357,   269,   268,   328,
     340,   342,   269,    -1,    -1,   156,   268,   328,   341,   342,
     269,    -1,   156,   268,   328,   269,   147,   121,   268,   357,
     269,    -1,   136,   370,    -1,   141,   136,   370,    -1,   138,
     268,   374,   269,   268,   374,   269,   268,   374,   269,    -1,
     139,   268,   374,   269,   268,   374,   269,   268,   374,   269,
     268,   374,   269,    -1,   343,    -1,   342,   343,    -1,   177,
     268,   357,   269,     6,    -1,   177,   268,   370,   273,   370,
     269,     6,    -1,   178,     6,    -1,   166,     6,    -1,   166,
     357,     6,    -1,   183,     6,    -1,   183,   185,     6,    -1,
     184,     6,    -1,   184,   185,     6,    -1,   179,   264,   357,
     265,     7,   370,   147,   357,     6,    -1,   147,     4,   266,
     357,   267,     6,    -1,   160,    -1,   161,    -1,   162,    -1,
     163,    -1,   164,    -1,    -1,   169,     6,    -1,   150,   169,
       6,    -1,   169,   357,     6,    -1,   150,   169,   357,     6,
      -1,   344,   268,   328,   345,   269,   268,   328,   345,   269,
      -1,   118,   264,   378,   265,    -1,   344,   264,   357,   265,
       7,   268,   328,   345,   269,   268,   328,   345,   269,     6,
      -1,    -1,   147,     4,   357,    -1,    -1,     4,    -1,    -1,
       7,   370,    -1,    -1,     7,   357,    -1,    -1,   158,   370,
      -1,   175,   372,     7,   357,     6,    -1,   125,   126,   372,
       7,   357,     6,    -1,   142,   106,   372,     7,   357,   348,
       6,    -1,   142,   109,   372,   350,   349,     6,    -1,   142,
     111,   372,   350,     6,    -1,   186,   372,     6,    -1,   101,
     322,   264,   357,   273,   357,   265,     6,    -1,   221,   322,
     264,   357,   265,     6,    -1,   173,   109,   268,   374,   269,
       7,   357,     6,    -1,   176,   109,   268,   374,   269,     7,
     357,     6,    -1,   166,   109,   372,   351,     6,    -1,   166,
     111,   372,     6,    -1,   167,   109,   372,     7,   357,     6,
      -1,   145,   106,   268,   374,   269,     7,   268,   374,   269,
     352,     6,    -1,   145,   109,   268,   374,   269,     7,   268,
     374,   269,   352,     6,    -1,   145,   106,   268,   374,   269,
       7,   268,   374,   269,   152,   268,   367,   273,   367,   273,
     357,   269,     6,    -1,   145,   109,   268,   374,   269,     7,
     268,   374,   269,   152,   268,   367,   273,   367,   273,   357,
     269,     6,    -1,   145,   106,   268,   374,   269,     7,   268,
     374,   269,   153,   367,     6,    -1,   145,   109,   268,   374,
     269,     7,   268,   374,   269,   153,   367,     6,    -1,   145,
     109,   357,   268,   374,   269,     7,   357,   268,   374,   269,
       6,    -1,   322,   268,   374,   269,   200,   322,   268,   357,
     269,     6,    -1,   174,   324,   372,     6,    -1,   133,   325,
     372,     6,    -1,   134,   111,   370,     6,    -1,   149,   106,
     370,     6,    -1,   144,   323,   370,     6,    -1,   144,   323,
     370,   173,   357,     6,    -1,   170,     6,    -1,   170,     4,
       6,    -1,   170,   103,   268,   374,   269,     6,    -1,   171,
       6,    -1,   222,    -1,   223,    -1,   224,    -1,   355,     6,
      -1,   355,   268,   370,   269,     6,    -1,   355,   268,   370,
     273,   370,   269,     6,    -1,   355,   264,   370,   265,   268,
     370,   273,   370,   269,     6,    -1,   358,    -1,   264,   357,
     265,    -1,   253,   357,    -1,   252,   357,    -1,   259,   357,
      -1,   357,   253,   357,    -1,   357,   252,   357,    -1,   357,
     254,   357,    -1,   357,   255,   357,    -1,   357,   257,   357,
      -1,   357,   258,   357,    -1,   357,   256,   357,    -1,   357,
     263,   357,    -1,   357,   246,   357,    -1,   357,   247,   357,
      -1,   357,   251,   357,    -1,   357,   250,   357,    -1,   357,
     245,   357,    -1,   357,   244,   357,    -1,   357,   243,   357,
      -1,   357,   242,   357,    -1,   357,   248,   357,    -1,   357,
     249,   357,    -1,   357,   241,   357,     8,   357,    -1,    26,
     298,   357,   299,    -1,    16,   298,   357,   299,    -1,    17,
     298,   357,   299,    -1,    18,   298,   357,   299,    -1,    19,
     298,   357,   299,    -1,    20,   298,   357,   299,    -1,    21,
     298,   357,   299,    -1,    22,   298,   357,   299,    -1,    23,
     298,   357,   299,    -1,    24,   298,   357,   299,    -1,    27,
     298,   357,   299,    -1,    28,   298,   357,   273,   357,   299,
      -1,    29,   298,   357,   299,    -1,    30,   298,   357,   299,
      -1,    31,   298,   357,   299,    -1,    32,   298,   357,   299,
      -1,    33,   298,   357,   299,    -1,    34,   298,   357,   299,
      -1,    35,   298,   357,   299,    -1,    36,   298,   357,   299,
      -1,    39,   298,   357,   273,   357,   299,    -1,    40,   298,
     357,   273,   357,   299,    -1,    41,   298,   357,   273,   357,
     299,    -1,    25,   298,   357,   299,    -1,    38,   298,   357,
     273,   357,   299,    -1,    37,   298,   357,   273,   357,   299,
      -1,     3,    -1,    10,    -1,    15,    -1,    11,    -1,    12,
      -1,   229,    -1,   230,    -1,   231,    -1,    83,    -1,    84,
      -1,    85,    -1,    -1,    94,   298,   357,   359,   309,   299,
      -1,   362,    -1,   219,   298,   378,   299,    -1,   219,   298,
     378,   273,   357,   299,    -1,   364,    -1,   388,   266,   357,
     267,    -1,   388,   264,   357,   265,    -1,   225,   264,   364,
     265,    -1,   225,   264,   364,   270,   300,   265,    -1,   227,
     264,   364,   360,   265,    -1,   227,   264,   364,   270,   300,
     360,   265,    -1,   227,   264,   364,   298,   357,   299,   360,
     265,    -1,   227,   264,   364,   270,   300,   298,   357,   299,
     360,   265,    -1,   226,   264,   379,   265,    -1,   271,   388,
     298,   299,    -1,   271,   364,   270,   300,   298,   299,    -1,
      97,   298,   388,   299,    -1,    97,   298,   299,    -1,   388,
     297,    -1,   388,   266,   357,   267,   297,    -1,   388,   264,
     357,   265,   297,    -1,   388,   270,   300,    -1,   388,     9,
     388,   270,   300,    -1,   388,   270,   300,   264,   357,   265,
      -1,   388,     9,   388,   270,   300,   264,   357,   265,    -1,
     388,   270,   300,   266,   357,   267,    -1,   388,     9,   388,
     270,   300,   266,   357,   267,    -1,   388,   266,   357,   267,
     270,   300,    -1,   388,   270,   300,   297,    -1,   388,   266,
     357,   267,   270,   300,   297,    -1,   215,   264,   378,   273,
     357,   265,    -1,    60,   264,   370,   273,   370,   265,    -1,
      61,   298,   378,   273,   378,   299,    -1,    59,   298,   378,
     299,    -1,    62,   298,   378,   273,   378,   299,    -1,    67,
     264,   385,   265,    -1,    -1,   273,   357,    -1,    -1,   273,
     378,    -1,    -1,    95,   364,   366,   363,   266,   310,   267,
      -1,   388,    -1,   388,     9,   388,    -1,    98,    -1,    98,
     357,    -1,    -1,   264,   365,   265,    -1,   368,    -1,   253,
     367,    -1,   252,   367,    -1,   367,   253,   367,    -1,   367,
     252,   367,    -1,   268,   357,   273,   357,   273,   357,   273,
     357,   273,   357,   269,    -1,   268,   357,   273,   357,   273,
     357,   273,   357,   269,    -1,   268,   357,   273,   357,   273,
     357,   269,    -1,   264,   357,   273,   357,   273,   357,   265,
      -1,   370,    -1,   369,   273,   370,    -1,   357,    -1,   373,
      -1,   268,   269,    -1,   268,   374,   269,    -1,   253,   268,
     374,   269,    -1,   357,   254,   268,   374,   269,    -1,   268,
     269,    -1,   268,   374,   269,    -1,   253,   268,   374,   269,
      -1,   370,    -1,   268,     8,   269,    -1,     5,    -1,   253,
     373,    -1,   357,   254,   373,    -1,   357,     8,   357,    -1,
     357,     8,   357,     8,   357,    -1,   103,   268,   357,   269,
      -1,   103,   268,     8,   269,    -1,   103,     5,    -1,   323,
     268,     8,   269,    -1,   323,     5,    -1,   143,   322,   372,
      -1,   146,   322,   370,    -1,   322,   200,    68,   370,    -1,
      68,   322,   268,   374,   269,    -1,    77,   323,   268,   357,
     269,    -1,    78,   323,   268,   357,   269,    -1,    79,   323,
     268,   357,   269,    -1,   127,    68,   324,   268,   357,   269,
      -1,   123,   109,   268,   357,   269,   127,   268,   357,   273,
     357,   269,    -1,   124,   109,   268,   357,   269,   127,   268,
     357,   273,   357,   269,    -1,   124,   106,   268,   357,   269,
     127,   268,   357,   269,    -1,   127,   103,   268,   357,   269,
     200,   109,   268,   357,   269,    -1,   197,   323,   268,   357,
     269,    -1,   326,    -1,   337,    -1,   346,    -1,   388,   298,
     299,    -1,   388,   270,   300,   298,   299,    -1,   388,     9,
     388,   270,   300,   298,   299,    -1,    42,   266,   388,   267,
      -1,    42,   266,   373,   267,    -1,    42,   264,   373,   265,
      -1,    42,   298,   268,   374,   269,   299,    -1,   388,   298,
     268,   374,   269,   299,    -1,    43,   298,   357,   273,   357,
     273,   357,   299,    -1,    44,   298,   357,   273,   357,   273,
     357,   299,    -1,    45,   298,   378,   299,    -1,    46,   298,
     357,   273,   357,   273,   357,   273,   357,   273,   357,   273,
     357,   299,    -1,   220,   298,   373,   299,    -1,    33,   298,
     373,   299,    -1,   357,    -1,   373,    -1,   374,   273,   357,
      -1,   374,   273,   373,    -1,   268,   357,   273,   357,   273,
     357,   273,   357,   269,    -1,   268,   357,   273,   357,   273,
     357,   269,    -1,   388,    -1,     4,   270,   197,   270,     4,
      -1,   268,   377,   269,    -1,   388,   266,   357,   267,   270,
     198,    -1,   375,    -1,   377,   273,   375,    -1,   379,    -1,
     388,    -1,   388,   266,   357,   267,    -1,   388,   264,   357,
     265,    -1,   388,   270,   300,    -1,   388,     9,   388,   270,
     300,    -1,   388,   270,   300,   264,   357,   265,    -1,   388,
       9,   388,   270,   300,   264,   357,   265,    -1,   388,   266,
     357,   267,   270,     4,    -1,   322,   268,   357,   269,    -1,
     143,   322,   268,   357,   269,    -1,     5,    -1,   234,   266,
     388,   267,    -1,    71,    -1,   232,    -1,    80,    -1,    82,
      -1,   217,   264,   378,   265,    -1,   216,   264,   378,   273,
     378,   265,    -1,   218,   298,   378,   299,    -1,   218,   298,
     378,   273,   378,   299,    -1,   228,   264,   364,   361,   265,
      -1,   228,   264,   364,   270,   300,   361,   265,    -1,    52,
     298,   385,   299,    -1,    53,   264,   378,   265,    -1,    54,
     264,   378,   265,    -1,    55,   264,   378,   273,   378,   273,
     378,   265,    -1,    50,   298,   385,   299,    -1,    64,   298,
     378,   299,    -1,    65,   298,   378,   299,    -1,    66,   298,
     378,   299,    -1,    63,   298,   357,   273,   378,   273,   378,
     299,    -1,    58,   298,   378,   273,   357,   273,   357,   299,
      -1,    58,   298,   378,   273,   357,   299,    -1,    51,   298,
     378,   299,    -1,    51,   298,   378,   273,   374,   299,    -1,
      72,   298,   378,   299,    -1,    73,    -1,    74,    -1,    57,
     298,   378,   299,    -1,    56,   298,   378,   299,    -1,    -1,
      99,   298,   379,   380,   313,   299,    -1,    96,   298,   381,
     299,    -1,   271,   357,    -1,   388,     9,   271,   357,    -1,
      50,   298,   384,   299,    -1,   385,    -1,   384,    -1,   268,
     385,   269,    -1,   378,    -1,   386,    -1,   385,   273,   378,
      -1,   385,   273,   386,    -1,   388,   264,   265,    -1,   388,
     270,   300,   264,   265,    -1,   388,     9,   388,   270,   300,
     264,   265,    -1,     4,   272,   268,   357,   269,    -1,   387,
     272,   268,   357,   269,    -1,   235,   266,   378,   267,   272,
     268,   357,   269,    -1,     4,    -1,   387,    -1,   235,   266,
     378,   267,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   275,   275,   276,   281,   283,   287,   288,   289,   290,
     319,   320,   321,   322,   323,   324,   325,   326,   327,   328,
     329,   330,   331,   332,   333,   334,   338,   342,   349,   354,
     359,   364,   378,   391,   404,   417,   445,   459,   472,   485,
     504,   509,   510,   511,   512,   513,   514,   518,   520,   525,
     527,   533,   637,   532,   655,   662,   673,   672,   690,   697,
     708,   707,   724,   741,   764,   763,   777,   778,   779,   780,
     781,   785,   786,   792,   792,   794,   794,   799,   800,   801,
     802,   803,   804,   810,   811,   812,   813,   818,   824,   885,
     900,   928,   938,   943,   951,   956,   964,   973,   978,   990,
    1007,  1013,  1022,  1040,  1058,  1067,  1079,  1084,  1092,  1112,
    1135,  1155,  1163,  1180,  1198,  1236,  1257,  1269,  1283,  1283,
    1285,  1287,  1296,  1306,  1305,  1326,  1325,  1343,  1353,  1352,
    1366,  1368,  1376,  1382,  1387,  1414,  1416,  1419,  1421,  1425,
    1426,  1430,  1442,  1446,  1450,  1454,  1467,  1481,  1489,  1502,
    1504,  1508,  1509,  1514,  1522,  1531,  1539,  1553,  1571,  1575,
    1582,  1591,  1594,  1600,  1604,  1616,  1619,  1626,  1629,  1635,
    1658,  1674,  1690,  1707,  1724,  1761,  1805,  1821,  1837,  1869,
    1885,  1902,  1918,  1968,  1986,  2007,  2028,  2034,  2040,  2047,
    2078,  2093,  2115,  2138,  2161,  2184,  2208,  2232,  2256,  2282,
    2299,  2315,  2333,  2351,  2363,  2377,  2376,  2406,  2408,  2410,
    2412,  2414,  2422,  2424,  2426,  2428,  2436,  2438,  2440,  2448,
    2450,  2452,  2454,  2464,  2480,  2496,  2512,  2528,  2544,  2561,
    2587,  2629,  2650,  2671,  2697,  2698,  2703,  2706,  2710,  2727,
    2747,  2767,  2786,  2813,  2832,  2853,  2868,  2884,  2902,  2953,
    2974,  2996,  3019,  3124,  3140,  3175,  3200,  3225,  3237,  3243,
    3258,  3289,  3301,  3310,  3317,  3329,  3349,  3353,  3358,  3362,
    3367,  3374,  3381,  3388,  3400,  3473,  3491,  3516,  3531,  3580,
    3586,  3598,  3630,  3634,  3638,  3643,  3650,  3655,  3665,  3670,
    3676,  3684,  3695,  3703,  3707,  3711,  3715,  3722,  3726,  3730,
    3742,  3751,  3810,  3830,  3856,  3872,  3889,  3906,  3928,  3950,
    3985,  3993,  4001,  4007,  4014,  4021,  4041,  4067,  4079,  4090,
    4108,  4126,  4145,  4144,  4169,  4168,  4195,  4194,  4219,  4218,
    4241,  4257,  4274,  4291,  4314,  4342,  4345,  4351,  4363,  4383,
    4387,  4391,  4395,  4399,  4403,  4407,  4411,  4420,  4433,  4434,
    4435,  4436,  4437,  4441,  4442,  4443,  4444,  4445,  4448,  4472,
    4491,  4514,  4517,  4545,  4548,  4565,  4568,  4574,  4577,  4584,
    4587,  4594,  4617,  4636,  4677,  4722,  4762,  4787,  4794,  4805,
    4822,  4839,  4869,  4895,  4921,  4953,  4981,  5007,  5033,  5059,
    5085,  5107,  5119,  5167,  5221,  5236,  5248,  5254,  5266,  5273,
    5288,  5297,  5318,  5319,  5320,  5324,  5330,  5342,  5360,  5388,
    5389,  5390,  5391,  5392,  5393,  5394,  5395,  5396,  5403,  5404,
    5405,  5406,  5407,  5408,  5409,  5410,  5411,  5412,  5413,  5414,
    5415,  5416,  5417,  5418,  5419,  5420,  5421,  5422,  5423,  5424,
    5425,  5426,  5427,  5428,  5429,  5430,  5431,  5432,  5433,  5434,
    5435,  5436,  5437,  5438,  5439,  5440,  5441,  5442,  5443,  5452,
    5453,  5454,  5455,  5456,  5457,  5458,  5459,  5460,  5461,  5462,
    5467,  5466,  5474,  5478,  5483,  5488,  5492,  5497,  5502,  5506,
    5510,  5514,  5518,  5522,  5526,  5532,  5547,  5551,  5557,  5562,
    5581,  5601,  5622,  5626,  5630,  5634,  5638,  5642,  5646,  5651,
    5661,  5671,  5676,  5687,  5696,  5701,  5706,  5734,  5735,  5741,
    5742,  5748,  5747,  5770,  5772,  5777,  5779,  5785,  5786,  5791,
    5795,  5799,  5803,  5807,  5814,  5818,  5822,  5826,  5833,  5838,
    5845,  5850,  5854,  5858,  5862,  5870,  5881,  5885,  5889,  5900,
    5904,  5908,  5922,  5930,  5938,  5945,  5955,  5978,  5983,  5989,
    5994,  6000,  6011,  6017,  6031,  6037,  6049,  6063,  6076,  6106,
    6129,  6149,  6168,  6188,  6205,  6215,  6225,  6235,  6247,  6251,
    6256,  6268,  6272,  6276,  6280,  6298,  6306,  6314,  6343,  6353,
    6369,  6380,  6385,  6389,  6393,  6405,  6409,  6421,  6438,  6448,
    6452,  6467,  6472,  6479,  6483,  6488,  6502,  6516,  6520,  6524,
    6528,  6532,  6540,  6546,  6555,  6559,  6563,  6571,  6577,  6583,
    6587,  6594,  6602,  6609,  6618,  6622,  6626,  6641,  6655,  6669,
    6681,  6697,  6706,  6715,  6725,  6736,  6744,  6752,  6756,  6774,
    6781,  6787,  6793,  6800,  6808,  6807,  6817,  6841,  6843,  6849,
    6854,  6856,  6861,  6866,  6871,  6873,  6877,  6889,  6903,  6907,
    6914,  6922,  6930,  6941,  6943,  6946
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
  "tSqrt", "tSin", "tAsin", "tCos", "tAcos", "tTan", "tRand", "tStep",
  "tAtan", "tAtan2", "tSinh", "tCosh", "tTanh", "tFabs", "tAbs", "tFloor",
  "tCeil", "tRound", "tMin", "tMax", "tFmod", "tModulo", "tHypot", "tList",
  "tLinSpace", "tLogSpace", "tListFromFile", "tCatenary", "tPrintf",
  "tError", "tWarning", "tStr", "tSprintf", "tStrCat", "tStrPrefix",
  "tStrRelative", "tStrReplace", "tAbsolutePath", "tDirName", "tStrSub",
  "tStrLen", "tFind", "tStrFind", "tStrCmp", "tStrChoice", "tUpperCase",
  "tLowerCase", "tLowerCaseIn", "tTextAttributes", "tBoundingBox", "tDraw",
  "tSetChanged", "tToday", "tFixRelativePath", "tCurrentDirectory",
  "tCurrentFileName", "tSyncModel", "tNewModel", "tMass", "tCenterOfMass",
  "tMatrixOfInertia", "tOnelabAction", "tOnelabRun", "tCodeName", "tCpu",
  "tMemory", "tTotalMemory", "tCreateTopology", "tCreateGeometry",
  "tClassifySurfaces", "tRenumberMeshNodes", "tRenumberMeshElements",
  "tDistanceFunction", "tDefineConstant", "tUndefineConstant",
  "tDefineNumber", "tDefineStruct", "tNameStruct", "tDimNameSpace",
  "tAppend", "tDefineString", "tSetNumber", "tSetTag", "tSetString",
  "tPoint", "tCircle", "tEllipse", "tCurve", "tSphere", "tPolarSphere",
  "tSurface", "tSpline", "tVolume", "tBox", "tCylinder", "tCone", "tTorus",
  "tEllipsoid", "tQuadric", "tShapeFromFile", "tRectangle", "tDisk",
  "tWire", "tGeoEntity", "tNormal", "tCurvature", "tCharacteristic",
  "tLength", "tParametric", "tElliptic", "tRefineMesh", "tRecombineMesh",
  "tAdaptMesh", "tTransformMesh", "tRelocateMesh", "tReorientMesh",
  "tSetFactory", "tThruSections", "tWedge", "tFillet", "tChamfer",
  "tPlane", "tRuled", "tTransfinite", "tPhysical", "tCompound",
  "tPeriodic", "tParent", "tUsing", "tPlugin", "tDegenerated",
  "tRecursive", "tSewing", "tRotate", "tTranslate", "tSymmetry", "tDilate",
  "tExtrude", "tLevelset", "tAffine", "tClosest", "tBooleanUnion",
  "tBooleanIntersection", "tBooleanDifference", "tBooleanSection",
  "tBooleanFragments", "tThickSolid", "tRecombine", "tSmoother", "tSplit",
  "tDelete", "tCoherence", "tHealShapes", "tIntersect", "tMeshAlgorithm",
  "tReverseMesh", "tMeshSize", "tMeshSizeFromBoundary", "tLayers",
  "tScaleLast", "tHole", "tAlias", "tAliasWithOptions", "tCopyOptions",
  "tQuadTriAddVerts", "tQuadTriNoNewVerts", "tRecombLaterals",
  "tTransfQuadTri", "tText2D", "tText3D", "tInterpolationScheme", "tTime",
  "tCombine", "tBSpline", "tBezier", "tNurbs", "tNurbsOrder",
  "tNurbsKnots", "tColor", "tColorTable", "tFor", "tIn", "tEndFor", "tIf",
  "tElseIf", "tElse", "tEndIf", "tExit", "tAbort", "tField", "tReturn",
  "tCall", "tSlide", "tMacro", "tShow", "tHide", "tGetValue",
  "tGetStringValue", "tGetEnv", "tGetString", "tGetNumber", "tUnique",
  "tSetMaxTag", "tHomology", "tCohomology", "tBetti", "tExists",
  "tFileExists", "tGetForced", "tGetForcedStr", "tGMSH_MAJOR_VERSION",
  "tGMSH_MINOR_VERSION", "tGMSH_PATCH_VERSION", "tGmshExecutableName",
  "tSetPartition", "tNameToString", "tStringToName", "tUnsplitWindow",
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
  "GeoEntity012", "Transform", "MultipleShape", "ListOfShapes", "LevelSet",
  "Delete", "Colorify", "SetPartition", "Visibility", "Command", "Slide",
  "Loop", "Extrude", "@10", "@11", "@12", "@13", "ExtrudeParameters",
  "ExtrudeParameter", "BooleanOperator", "BooleanOption", "Boolean",
  "BooleanShape", "TransfiniteType", "TransfiniteArrangement",
  "TransfiniteCorners", "RecombineAngle", "PeriodicTransform",
  "Constraints", "Coherence", "HomologyCommand", "Homology", "FExpr",
  "FExpr_Single", "@14", "GetForced_Default", "GetForcedStr_Default",
  "DefineStruct", "@15", "Struct_FullName", "Append", "AppendOrNot",
  "VExpr", "VExpr_Single", "RecursiveListOfListOfDouble", "ListOfDouble",
  "ListOfDoubleWithBraces", "ListOfDoubleOrAll", "FExpr_Multi",
  "RecursiveListOfDouble", "ColorExpr", "ListOfColor",
  "RecursiveListOfColor", "StringExprVar", "StringExpr", "@16",
  "NameStruct_Arg", "Str_BracedRecursiveListOfStringExprVar",
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
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     495,    63,   496,   497,   498,   499,    60,    62,   500,   501,
     502,   503,    43,    45,    42,    47,    37,   124,    38,    33,
     504,   505,   506,    94,    40,    41,    91,    93,   123,   125,
      46,    35,   126,    44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   274,   275,   275,   276,   276,   277,   277,   277,   277,
     277,   277,   277,   277,   277,   277,   277,   277,   277,   277,
     277,   277,   277,   277,   277,   277,   278,   278,   279,   279,
     279,   279,   279,   279,   279,   279,   280,   280,   280,   280,
     281,   281,   281,   281,   281,   281,   281,   282,   282,   283,
     283,   285,   286,   284,   287,   287,   289,   288,   290,   290,
     292,   291,   293,   293,   295,   294,   296,   296,   296,   296,
     296,   297,   297,   298,   298,   299,   299,   300,   300,   300,
     300,   300,   300,   301,   301,   301,   301,   301,   301,   301,
     301,   301,   301,   301,   301,   301,   301,   301,   301,   301,
     301,   301,   301,   301,   301,   301,   301,   301,   301,   301,
     301,   301,   301,   301,   301,   301,   301,   301,   302,   302,
     303,   303,   303,   304,   303,   305,   303,   303,   306,   303,
     307,   307,   308,   308,   308,   309,   309,   310,   310,   311,
     311,   312,   312,   312,   312,   312,   312,   312,   312,   313,
     313,   314,   314,   315,   315,   315,   315,   315,   316,   316,
     316,   317,   317,   317,   317,   318,   318,   319,   319,   320,
     320,   320,   320,   320,   320,   320,   320,   320,   320,   320,
     320,   320,   320,   320,   320,   320,   320,   320,   320,   320,
     320,   320,   320,   320,   320,   320,   320,   320,   320,   320,
     320,   320,   320,   320,   320,   321,   320,   322,   322,   322,
     322,   322,   323,   323,   323,   323,   324,   324,   324,   325,
     325,   325,   325,   326,   326,   326,   326,   326,   326,   326,
     326,   326,   326,   326,   327,   327,   328,   328,   328,   328,
     328,   328,   328,   329,   329,   329,   329,   329,   329,   329,
     329,   329,   329,   329,   329,   330,   330,   330,   330,   330,
     330,   330,   330,   331,   331,   332,   333,   333,   333,   333,
     333,   333,   333,   333,   334,   334,   334,   334,   334,   334,
     334,   334,   334,   334,   334,   334,   334,   334,   334,   334,
     334,   334,   334,   334,   334,   334,   334,   334,   334,   334,
     334,   334,   334,   334,   335,   336,   336,   336,   336,   336,
     336,   336,   336,   336,   336,   336,   336,   336,   336,   337,
     337,   337,   338,   337,   339,   337,   340,   337,   341,   337,
     337,   337,   337,   337,   337,   342,   342,   343,   343,   343,
     343,   343,   343,   343,   343,   343,   343,   343,   344,   344,
     344,   344,   344,   345,   345,   345,   345,   345,   346,   346,
     347,   348,   348,   349,   349,   350,   350,   351,   351,   352,
     352,   353,   353,   353,   353,   353,   353,   353,   353,   353,
     353,   353,   353,   353,   353,   353,   353,   353,   353,   353,
     353,   353,   353,   353,   353,   353,   353,   353,   354,   354,
     354,   354,   355,   355,   355,   356,   356,   356,   356,   357,
     357,   357,   357,   357,   357,   357,   357,   357,   357,   357,
     357,   357,   357,   357,   357,   357,   357,   357,   357,   357,
     357,   357,   357,   357,   357,   357,   357,   357,   357,   357,
     357,   357,   357,   357,   357,   357,   357,   357,   357,   357,
     357,   357,   357,   357,   357,   357,   357,   357,   357,   358,
     358,   358,   358,   358,   358,   358,   358,   358,   358,   358,
     359,   358,   358,   358,   358,   358,   358,   358,   358,   358,
     358,   358,   358,   358,   358,   358,   358,   358,   358,   358,
     358,   358,   358,   358,   358,   358,   358,   358,   358,   358,
     358,   358,   358,   358,   358,   358,   358,   360,   360,   361,
     361,   363,   362,   364,   364,   365,   365,   366,   366,   367,
     367,   367,   367,   367,   368,   368,   368,   368,   369,   369,
     370,   370,   370,   370,   370,   370,   371,   371,   371,   372,
     372,   372,   373,   373,   373,   373,   373,   373,   373,   373,
     373,   373,   373,   373,   373,   373,   373,   373,   373,   373,
     373,   373,   373,   373,   373,   373,   373,   373,   373,   373,
     373,   373,   373,   373,   373,   373,   373,   373,   373,   373,
     373,   374,   374,   374,   374,   375,   375,   375,   375,   376,
     376,   377,   377,   378,   378,   378,   378,   378,   378,   378,
     378,   378,   378,   378,   379,   379,   379,   379,   379,   379,
     379,   379,   379,   379,   379,   379,   379,   379,   379,   379,
     379,   379,   379,   379,   379,   379,   379,   379,   379,   379,
     379,   379,   379,   379,   380,   379,   379,   381,   381,   382,
     383,   383,   384,   385,   385,   385,   385,   386,   386,   386,
     387,   387,   387,   388,   388,   388
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
       1,     1,     1,     5,     5,     2,     7,     7,     4,     3,
       6,     9,     7,     6,     7,     6,     4,     8,     9,     9,
       6,     9,     6,     9,     5,     8,     8,    11,     6,     9,
       5,     7,     9,     9,     9,     7,     9,     9,     0,     1,
       0,     3,     5,     0,     9,     0,    11,     5,     0,     9,
       0,     3,     3,     5,     5,     0,     2,     0,     1,     1,
       3,     2,     2,     2,     2,     1,     4,     2,     2,     0,
       2,     1,     3,     2,     2,     2,     2,     2,     1,     1,
       3,     0,     5,     5,     5,     0,     2,     0,     2,     7,
       7,     7,    10,    10,     8,     8,     7,     7,    11,     7,
       8,     8,     8,     9,     8,     8,     3,     4,    10,     7,
       7,     7,     7,     7,     7,     7,     7,     7,     7,     9,
       7,     7,     8,     8,    12,     0,     9,     1,     1,     1,
       1,     4,     1,     1,     1,     4,     1,     1,     4,     1,
       1,     1,     4,     5,    11,     5,     9,     9,     7,     7,
       4,     9,    10,     9,     1,     1,     0,     2,     6,     7,
       7,     6,     7,     8,    10,    14,    16,    12,    14,    14,
      14,    14,     8,     8,     6,     4,     5,     5,     6,     6,
       3,     4,     3,     5,     6,     5,     4,     3,     4,     3,
       4,     5,     4,     5,     3,     5,     7,     7,     3,     2,
       7,     3,     2,     3,     2,     2,     2,     2,    15,     2,
       2,     7,     2,     9,    11,     2,     4,     2,     2,     2,
       2,    16,     5,     8,    11,     6,     8,     8,    10,     1,
       2,     2,     1,     3,     3,     4,     4,     1,     1,     5,
      11,    13,     0,     7,     0,    13,     0,    15,     0,     6,
       9,     2,     3,    10,    13,     1,     2,     5,     7,     2,
       2,     3,     2,     3,     2,     3,     9,     6,     1,     1,
       1,     1,     1,     0,     2,     3,     3,     4,     9,     4,
      14,     0,     3,     0,     1,     0,     2,     0,     2,     0,
       2,     5,     6,     7,     6,     5,     3,     8,     6,     8,
       8,     5,     4,     6,    11,    11,    18,    18,    12,    12,
      12,    10,     4,     4,     4,     4,     4,     6,     2,     3,
       6,     2,     1,     1,     1,     2,     5,     7,    10,     1,
       3,     2,     2,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     5,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     6,     4,     4,     4,     4,     4,
       4,     4,     4,     6,     6,     6,     4,     6,     6,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     6,     1,     4,     6,     1,     4,     4,     4,     6,
       5,     7,     8,    10,     4,     4,     6,     4,     3,     2,
       5,     5,     3,     5,     6,     8,     6,     8,     6,     4,
       7,     6,     6,     6,     4,     6,     4,     0,     2,     0,
       2,     0,     7,     1,     3,     1,     2,     0,     3,     1,
       2,     2,     3,     3,    11,     9,     7,     7,     1,     3,
       1,     1,     2,     3,     4,     5,     2,     3,     4,     1,
       3,     1,     2,     3,     3,     5,     4,     4,     2,     4,
       2,     3,     3,     4,     5,     5,     5,     5,     6,    11,
      11,     9,    10,     5,     1,     1,     1,     3,     5,     7,
       4,     4,     4,     6,     6,     8,     8,     4,    14,     4,
       4,     1,     1,     3,     3,     9,     7,     1,     5,     3,
       6,     1,     3,     1,     1,     4,     4,     3,     5,     6,
       8,     6,     4,     5,     1,     4,     1,     1,     1,     1,
       4,     6,     4,     6,     5,     7,     4,     4,     4,     8,
       4,     4,     4,     4,     8,     8,     6,     4,     6,     4,
       1,     1,     4,     4,     0,     6,     4,     2,     4,     4,
       1,     1,     3,     1,     1,     3,     3,     3,     5,     7,
       5,     5,     8,     1,     1,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     2,     3,     1,   653,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   207,
       0,     0,   208,     0,     0,   209,     0,   210,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   348,   349,   350,
     351,   352,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   309,     0,     0,   317,   318,     0,
       0,     0,   312,     0,     0,     0,     0,     0,     0,   402,
     403,   404,     0,     0,     0,     5,     6,     7,     8,    10,
       0,    11,    24,    12,    13,    14,    15,    23,    22,    21,
      16,     0,    17,    18,    19,    20,     0,    25,     0,   654,
       0,   236,     0,     0,     0,     0,     0,     0,   287,     0,
     289,   290,   285,   286,     0,   292,     0,   295,   236,     0,
     297,   298,   120,   130,   653,   517,   513,    73,    74,     0,
     207,   208,   209,   210,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   299,   300,
       0,     0,   219,   220,   221,     0,     0,     0,     0,   459,
     460,   462,   463,   461,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   467,   468,   469,     0,     0,   207,
     212,   213,   214,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   464,   465,
     466,     0,     0,     0,     0,     0,     0,     0,     0,   564,
     565,     0,   566,   530,   409,   472,   475,   331,   531,   513,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   205,
     212,   213,     0,   214,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   519,     0,     0,   236,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   653,     0,     0,   236,     0,     0,   398,     0,   401,
       0,     0,   216,   217,     0,     0,   541,     0,     0,   539,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   653,     0,     0,   587,     0,     0,     0,     0,
     282,     0,     0,     0,   513,   284,     0,   604,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   606,     0,   630,   631,   608,   609,     0,     0,     0,
       0,     0,     0,   607,     0,     0,     0,     0,   310,   311,
       0,   236,     0,   236,     0,     0,     0,   279,     0,     0,
     236,   405,     0,     0,    85,     0,    66,     0,     0,    70,
      69,    68,    67,    72,    71,    73,    74,     0,     0,     0,
       0,     0,     0,     0,   593,   513,     0,   235,     0,   234,
       0,   186,     0,     0,   593,   594,     0,     0,     0,   643,
       0,   644,   594,     0,     0,     0,   118,   118,     0,   511,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   581,   582,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    73,    74,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   548,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   412,     0,   411,
     542,   413,     0,   532,     0,     0,   513,     0,   550,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    73,    74,     0,   489,     0,     0,     0,     0,     0,
       0,     0,   332,     0,   365,   365,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   236,     0,   236,
     236,     0,   521,   520,     0,     0,     0,     0,   236,   236,
       0,     0,     0,     0,   328,     0,   236,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   367,
       0,     0,     0,     0,     0,     0,   236,   262,     0,     0,
     260,   399,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   376,   281,     0,     0,     0,     0,
       0,     0,     0,   236,     0,     0,     0,     0,     0,   411,
     283,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   314,   313,
       0,   267,     0,     0,   269,     0,     0,     0,   236,     0,
       0,     0,   353,     0,     0,     0,     0,     0,     0,     0,
       0,    77,    80,    78,    79,    81,    82,     0,     0,     0,
       0,    89,    75,    76,     0,     0,     0,   278,    40,   274,
       0,     0,     0,     0,     0,   230,     0,     0,     0,     0,
       0,   237,     0,     0,   187,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   296,     0,     0,   119,     0,     0,     0,   515,
       0,     0,   514,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   359,     0,     0,     0,   211,     0,     0,     0,     0,
       0,     0,     0,   393,   394,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   513,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   470,   488,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   551,   552,     0,     0,     0,     0,     0,     0,
     507,     0,   410,   533,     0,     0,     0,     0,   544,     0,
     429,   428,   427,   426,   422,   423,   430,   431,   425,   424,
     415,   414,     0,   416,   543,   417,   420,   418,   419,   421,
     514,     0,     0,   492,     0,   567,     0,     0,     0,     0,
       0,     0,     0,     0,   363,     0,     0,     0,     0,     0,
       0,   396,     0,     0,     0,     0,     0,   395,     0,   236,
       0,     0,     0,     0,     0,   523,   522,     0,     0,     0,
       0,     0,     0,     0,   322,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   382,
       0,     0,     0,   261,     0,     0,     0,   255,     0,     0,
       0,     0,   392,   410,   540,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     315,   316,     0,   416,   514,   492,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   634,     0,     0,     0,   509,     0,
       0,   266,   270,   268,   272,     0,     0,   655,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    96,     0,     0,
     410,     0,     0,     0,    66,     0,     0,    88,     0,    66,
      67,     0,     0,     0,   514,     0,     0,   492,     0,     0,
       0,   205,     0,     0,     0,   650,    28,    26,    27,     0,
       0,     0,     0,     0,   597,    30,     0,    29,     0,     0,
     275,   645,   646,     0,   647,   597,     0,     0,    83,   121,
      84,   131,   516,   518,   137,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   583,
     584,   302,   236,   222,     9,   434,   435,   436,   437,   438,
     439,   440,   441,   442,   456,   433,   443,     0,   445,   446,
     447,   448,   449,   580,   450,   451,   452,     0,     0,     0,
       0,     0,   572,   571,   570,     0,     0,     0,   577,     0,
     504,     0,     0,     0,   506,     0,     0,     0,     0,   135,
     487,   547,   546,   215,     0,     0,     0,     0,     0,     0,
       0,     0,   473,   579,   478,     0,   484,     0,     0,     0,
       0,   534,     0,     0,   485,   553,   549,     0,     0,     0,
       0,   477,   476,    73,    74,   499,     0,     0,     0,     0,
       0,     0,     0,   410,   361,   366,   364,     0,   375,     0,
     158,   159,     0,   215,     0,   410,     0,     0,     0,     0,
       0,   256,     0,   271,   273,     0,     0,     0,   223,   225,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   335,     0,   319,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   236,   236,     0,   368,   381,     0,
       0,     0,     0,   257,     0,     0,     0,     0,   218,   371,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   263,     0,     0,     0,     0,     0,     0,     0,   620,
       0,   627,   616,   617,   618,     0,   633,   632,     0,     0,
     621,   622,   623,   629,   637,   636,     0,   149,     0,   610,
       0,   612,     0,     0,     0,   605,     0,     0,   265,     0,
       0,     0,     0,   354,     0,     0,     0,   406,     0,   651,
       0,   110,    66,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   104,     0,     0,     0,     0,   602,
      51,     0,     0,     0,    64,     0,    41,    42,    43,    44,
      45,    46,     0,   477,   476,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   596,   595,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   145,
       0,     0,     0,     0,   138,   139,     0,     0,     0,     0,
     165,   165,     0,     0,     0,     0,     0,   161,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   372,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   554,   555,   556,   557,     0,     0,
       0,     0,     0,     0,     0,   563,     0,     0,     0,   507,
     508,     0,   480,     0,     0,   545,   432,   535,   493,   491,
       0,   490,     0,     0,   568,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   374,     0,     0,     0,     0,     0,
     397,     0,     0,     0,    77,     0,   264,     0,     0,     0,
       0,     0,     0,     0,   340,     0,     0,   339,     0,   342,
       0,   344,     0,   329,   336,     0,     0,     0,   254,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   383,
       0,     0,   259,   258,   400,     0,     0,     0,    37,    38,
       0,     0,     0,     0,     0,     0,   588,     0,     0,     0,
     305,   493,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   509,   510,   614,     0,   378,     0,     0,
     236,   355,     0,   356,   236,     0,     0,   603,     0,    95,
       0,     0,     0,     0,    93,     0,   591,     0,   108,     0,
     100,   102,     0,     0,     0,    90,     0,     0,     0,     0,
       0,    36,   493,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    31,    32,     0,   598,     0,
       0,    34,    33,     0,   598,   648,   291,     0,     0,   122,
     127,     0,     0,     0,   141,   147,   148,   144,   142,   143,
     512,     0,    86,     0,    87,   169,     0,     0,     0,     0,
     170,   189,   190,   167,     0,     0,     0,   171,   200,   191,
     195,   196,   192,   193,   194,   179,     0,     0,     0,   444,
     458,   457,   453,   454,   455,   573,     0,     0,     0,   502,
     503,   505,   136,   471,     0,     0,     0,   558,     0,   501,
     474,   479,     0,     0,   507,   201,   486,    73,    74,     0,
     498,   494,   496,   574,   197,     0,     0,     0,   161,     0,
       0,   373,     0,   160,     0,     0,     0,     0,     0,     0,
     280,     0,     0,     0,     0,   236,   236,     0,     0,   341,
     530,     0,     0,   343,   345,     0,     0,   323,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   228,   229,
     198,     0,     0,     0,     0,     0,     0,     0,   176,     0,
     177,     0,     0,     0,     0,     0,     0,   111,   115,     0,
     628,     0,     0,   626,     0,   638,     0,     0,   150,   151,
     635,   611,   613,     0,     0,     0,     0,   353,   357,   353,
       0,   407,    94,     0,     0,    66,     0,     0,    92,     0,
     589,     0,     0,     0,     0,     0,     0,   641,   640,     0,
       0,     0,     0,     0,   528,     0,     0,    77,   276,   494,
     277,     0,     0,     0,     0,     0,   241,   238,     0,     0,
     601,   599,     0,     0,     0,     0,   123,   128,     0,     0,
       0,   581,   582,   140,   377,   166,   174,   175,   180,     0,
       0,     0,     0,     0,   182,     0,     0,   303,     0,     0,
       0,     0,     0,     0,     0,     0,   481,     0,     0,     0,
     569,   500,     0,     0,   181,     0,   202,   362,     0,     0,
       0,     0,   203,     0,     0,     0,     0,     0,     0,   527,
     526,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   253,   252,     0,     0,     0,     0,     0,     0,     0,
       0,   243,     0,     0,     0,   379,   380,    39,   184,   185,
       0,   586,     0,     0,   307,   306,     0,     0,     0,     0,
       0,     0,     0,     0,   153,   154,   157,   156,   155,     0,
     615,     0,   652,     0,     0,     0,     0,     0,     0,     0,
       0,   105,   106,   592,     0,     0,     0,    97,     0,     0,
       0,    47,     0,     0,     0,     0,     0,    49,     0,   242,
     239,   240,    35,     0,     0,   649,   293,     0,   135,   149,
       0,     0,   146,     0,     0,     0,   168,   199,     0,     0,
       0,     0,     0,   575,   576,     0,     0,     0,     0,     0,
     507,   482,   495,   497,     0,     0,   183,   206,     0,     0,
       0,   369,   369,     0,   116,   117,   236,     0,   226,   227,
     330,     0,   337,     0,     0,   236,     0,     0,     0,     0,
       0,     0,     0,     0,   233,     0,   231,     0,     0,     0,
       0,   536,     0,   112,   114,   113,   619,   625,   624,   152,
       0,     0,     0,   358,     0,     0,   109,   101,   103,     0,
      91,   642,    98,    99,    52,     0,     0,     0,     0,   529,
       0,     0,   495,   600,     0,     0,     0,     0,   125,   639,
       0,   132,     0,     0,     0,     0,   188,     0,     0,     0,
     561,     0,     0,     0,   333,     0,   172,   173,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   525,     0,
     347,     0,     0,   324,     0,   244,     0,     0,     0,     0,
       0,     0,   232,     0,   585,   308,     0,   537,     0,   391,
     236,   408,     0,   590,     0,    48,     0,     0,     0,    65,
      50,     0,   294,   124,   129,   135,     0,     0,   163,   164,
     162,     0,     0,     0,     0,   562,   483,     0,     0,     0,
       0,   370,   384,     0,     0,   385,     0,   224,     0,   338,
       0,   320,     0,   236,     0,     0,     0,     0,     0,     0,
     178,   538,   304,   353,   107,     0,     0,     0,     0,     0,
       0,   133,   134,     0,     0,   559,   560,     0,   204,     0,
     388,     0,   389,   390,   524,     0,     0,   326,   247,     0,
       0,     0,     0,     0,     0,     0,     0,    56,     0,    62,
       0,     0,   126,     0,     0,   334,     0,     0,   346,   325,
     321,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   248,
     249,   250,   251,     0,   245,   360,    53,     0,    60,     0,
     288,     0,   578,     0,     0,   327,     0,     0,    54,     0,
       0,   301,     0,     0,   246,     0,     0,     0,     0,     0,
       0,    57,    55,     0,    58,     0,   386,   387,     0,     0,
      63,    61,    59
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,   125,  1139,   126,   127,  1123,  2030,  2036,
    1436,  1666,  2204,  2337,  1437,  2310,  2353,  1438,  2339,  1439,
    1440,  1670,   468,   634,   635,  1212,  1770,   128,   836,   496,
    2048,  2215,  2049,   497,  1910,  1519,  1473,  1474,  1475,  1630,
    1848,  1849,  1289,  1726,  1717,  1920,   811,   646,   297,   298,
     375,   216,   299,   478,   479,   132,   133,   134,   135,   136,
     137,   138,   139,   300,  1324,  2242,  2301,  1012,  1320,  1321,
     301,  1102,   302,   143,  1553,  1287,   984,  1028,  2172,   144,
     145,   146,   147,   303,   304,  1239,  1260,  1394,   305,   841,
     306,   840,   499,   663,   341,  1883,   379,  1999,   380,   308,
     604,   394,  1420,  1657,   489,   484,  1387,  1082,  1706,  1876,
    1877,  1067,   491,   149,   404
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -2007
static const yytype_int16 yypact[] =
{
   14287,    33,    72, 14499, -2007, -2007,   -35,   125,     3,   -72,
     -34,    11,    42,   215,   258,   276,   288,   138,    48,    50,
     174,   451,   493,   256,   294,    34,  -171,   548,  -171,   282,
     306,   328,    19,   375,   384,    26,   391,   455,   466,   479,
     485,   492,   505,   513,   554,   556,   453,   677,   717,   817,
     825,   578,   596,   611,   353,   602,  7452,   607,   606,   612,
     742,   -59,   667,   548,    -9,   338,   620,   794,   -88,   680,
     -96,   -96,   681,   262,    57,   687,   693, -2007, -2007, -2007,
   -2007, -2007,   648,    69,   827,   868,    16,    60,   970,   905,
     921,   244,  6404,   930,  1040,  1047,  1048,  6404,  1053,   -85,
     -76,   795,    27,    41, -2007,   796,   818, -2007, -2007, 11299,
    1052,   815, -2007, 14763,   819, 14800,    20,    23,   548, -2007,
   -2007, -2007, 13210,   823,  1079, -2007, -2007, -2007, -2007, -2007,
     822, -2007, -2007, -2007, -2007, -2007, -2007, -2007, -2007, -2007,
   -2007,    67, -2007, -2007, -2007, -2007,    43, -2007,  1081,   820,
    6140,    32,   826,  1087, 13210, 14690, 14690, 14690, -2007, 13210,
   -2007, -2007, -2007, -2007, 14690, -2007, 13210, -2007, -2007, 13210,
   -2007, -2007, -2007, -2007,   824,   834,  1086, -2007, -2007, 14876,
   -2007, -2007, -2007, -2007,   835, 14876, 13210, 13210, 13210,   836,
   13210, 13210, 13210,   837, 13210, 13210, 13210, 13210, 13210, 13210,
   13210, 14690, 13210, 13210, 13210, 13210,  6404,   839, -2007, -2007,
   10586, 10586, -2007, -2007, -2007,   838,  6404,  7714, 14690, -2007,
   -2007, -2007, -2007, -2007,  -171,  -171,  -171,  -171,  -171,  -171,
    -171,  -171,  -171,  -171,  -171,  -171,  -171,  -171,  -171,  -171,
    -171,  -171,  -171,  -171,  -171,  -171,  -171,  -171,  -171,  -171,
      93,  -171,  -171,  -171,  -171,  -171,   840,  -171,  -171,   841,
     548,   661,   661,   661, -2007, -2007, -2007,  -171,  -171,    29,
     909,   912,   913,   846,  1006,   474,   -21,  7714,   980,   548,
     548,   661,   853,  -171,  -171,   855,   856,   857, -2007, -2007,
   -2007, 13210,  7976, 13210, 13210,  8238,    34,   922,    35, -2007,
   -2007,   858, -2007,  2487, -2007, -2007, -2007, -2007, -2007,   153,
   13210, 10586, 10586,   859,   860,  8500,  6404,  6404,  6404, -2007,
   -2007, -2007,   861, -2007,   862,   863,  8762,   866, 11460,  1124,
    7714,   867,    27,   869,   872,   -96,   -96,   -96, 13210, 13210,
    -103, -2007,   -58,   -96, 11556,   326,   203,   865,   877,   878,
     880,   881,   883,   884, 10586, 10586, 13210,  6404,  6404,  6404,
     253,     5,  1137,   885, -2007,  1143,  1144, -2007,   886, -2007,
     887,   888, -2007, -2007,   890,  6404, -2007, 13210,  6666, -2007,
    1145,   891,   894,   896,   897,  1147,  1158,   901, 13210,   904,
   13210, 13210,   108, 13210,   915, -2007,   972, 13210, 13210, 13210,
   -2007,  -171, 13210,   232,   160, -2007, 13210, -2007,  -171,  -171,
    -171,   920,   923,   924,  -171,  -171,  -171,  -171,  -171,  -171,
    -171, -2007,  -171, -2007, -2007, -2007, -2007,  -171,  -171,   925,
     926,  -171,   927, -2007,   928,  1180,  1187,   929, -2007, -2007,
    1189,  1188,  1193,  1194,   937, 11502, 14690, -2007, 10586, 13210,
   -2007, -2007,  7714,  7714, -2007,   935, 14876,   548,  1197, -2007,
   -2007, -2007, -2007, -2007, -2007, 13210, 13210,    25,  7714,  1199,
     361,   938,   969,   939,  1202,    99,   979, -2007,   982, 15008,
   13210, -2007,  1482,  -106, -2007,    58,   -38,   193,  9732, -2007,
     196, -2007,    98,  9994,  2748, 10256,   -20,    71,  1150, -2007,
      34,   976, 13210,   981, 17258, 17283, 17308, 13210, 17333, 17358,
   17383, 13210, 17408, 17433, 17458, 17483, 17508, 17533, 17558,   988,
   17583, 17608, 17633, 15523,  1245, 13210, 10586,  4984, -2007,   304,
     346, 13210,  1249,  1250,   992, 13210, 13210, 13210, 13210, 13210,
   13210, 13210, 13210, 13210, 13210, 13210, 13210, 13210, 13210, 13210,
   13210, 13210, 10586, 13210, 13210, 13210, 13210, 13210, 13210, 13210,
   13210, 10586, 10586,   990, 13210, 13210, 14690, 13210, 14690,  7714,
   14690, 14690, 14690,   993,   994,   995,   996, 13210,    37, -2007,
   11818, 13210,   997,   998,   999,   244,  1000,  7714,  6404,  7714,
    1001, 14690, 14690, 10586,    34, 14876,    34,  1007, 10586,  1007,
   -2007,  1007, 17658, -2007,   392,  1002,    79,  1192, -2007,  1263,
   13210, 13210, 13210, 13210, 13210, 13210, 13210, 13210, 13210, 13210,
   13210, 13210, 13210, 13210,  9024, 13210, 13210, 13210, 13210, 13210,
      34, 13210, 13210,   425, -2007,   788, 17683,   523,   536, 13210,
   13210, 13210, -2007,  1266,  1267,  1267,  1014, 13210, 13210, 13210,
   13210,    46, 10586, 10586, 16770,  1015,  1273, -2007,  1013, -2007,
   -2007,  -177, -2007, -2007, 10518, 10874,   -96,   -96,    32,    32,
    -131, 11556, 11556, 13210,  3281,  -107, -2007, 13210, 13210, 13210,
   13210, 13210, 13210, 13210, 13210, 13210,   579,   581, 17708,  1275,
    1279,  1280, 13210, 13210,  1282, 13210, -2007, -2007, 13210,  4618,
   -2007, -2007, 10586, 10586, 10586, 13210,  1283, 17733,  1017, 13210,
   10586, 13210, 13210, 13210, -2007, -2007, 13210, 17758, 13210, 17783,
   17808,  1093, 11415, -2007,  1023,  7384, 17833, 17858, 13210,  1007,
   -2007, 13210,    34, 13210, 13210,   425, 16853, 14690, 14690, 14690,
   14690, 14690, 14690, 14690, 14690, 14690, 13210, 14690, 14690, 14690,
   14690,    14, 14876, 14690, 14690, 14690,    34,    34, -2007, -2007,
   10586, -2007,  1024, 11596, -2007,  1025, 13239, 13210, -2007,  1028,
     587, 17883, 14932,  1027,   588, 13210,  1290,  1029,  7714, 17908,
   16880, -2007, -2007, -2007, -2007, -2007, -2007,  1030,  1291,   194,
    1295, -2007, -2007, -2007, 10586,   269, 13210, -2007, -2007, -2007,
      34, 13210, 13210,   425,  1036, -2007,  1039,   -31,   548,    -9,
     548, -2007,  1037, 15552, -2007,   126, 10586,    34, 13210, 13210,
     425,  1298, 10586,  1300, 10586, 13210,  1301, 14690,    34, 11906,
     425, 13210, -2007, 13210,  1302, -2007,    34,  1303, 14690, 13210,
    1049,  1046, -2007, 13210, 11763, 14876,  1306,  1308,  1309, 17933,
    1310,  1312,  1314, 17958,  1319,  1321,  1322,  1323,  1324,  1325,
    1329, -2007,  1330,  1331,  1332, -2007, 13210, 17983, 10586,  1072,
   10586,    52, 15581, -2007, -2007,  1336, 16826, 16826, 16826, 16826,
   16826, 16826, 16826, 16826, 16826, 16826, 16826, 16826, 11849, 16826,
   16826, 16826, 16826,   821,   280, 16826, 16826, 16826, 12118, 12194,
   12460, 12546, 12805,  4984,  1080,  1082,   146, 10586, 12891, 13067,
     280, 13165,   280,  1073,  1074,  1075,   231, 10586, 13210, 13210,
   13210, 18933, -2007,   280,  1084, 15610, 15639, 13210, 13210, 13210,
    1083, 13210, -2007, -2007, 13210,  1077,   181,   280,  -141,  1091,
     458,   589,  1350, -2007,   425,   280,  7714,  1089,  7646,  7908,
    1424,   770,   987,   987,   532,   532,   532,   532,   532,   532,
     544,   544, 10586,   148, -2007,   148,   148,  1007,  1007,  1007,
    1090, 18008, 16907,   577, 10586, -2007,  1352,  1094,  1095, 18033,
   18058, 18083, 13210,  7714,  1357,  1358, 11202, 18108, 15668, 18133,
   18158, -2007, 13210,   590,   600, 10586,  1096, -2007, 13379, -2007,
   13442, 13552,   -96, 13210, 13210, -2007, -2007,  1099,  1100, 11556,
    8433,  1218,   457,   -96, 13615, 18183, 15697, 18208, 18233, 18258,
   18283, 18308, 18333, 18358,  1102,  1103,  1366, 13210,  1368, -2007,
   13210, 18383, 15726, -2007, 16934, 13725, 16961, -2007,   603,   608,
     610, 15755, -2007, -2007, -2007,  2332,   613, 16988, 17015, 13348,
   18408,  1370, 18433,  1371,  1372,  1105, 13210, 13788, 13210, 13210,
   -2007, -2007, 16826,   148,  1110,   583,    36,   393,   498,   393,
    1116,  1117,  1111,   280,   280,  1113, 13521,   280,   280,   280,
     280, 13210,   280,  1374, -2007,  1115,  1126,   501,   436,  1122,
     616, -2007, -2007, -2007, -2007, 18458, 13898,  1120,  1195,  1386,
    1225, 12163,  1127,  1129,  1392,  7714, 15784, -2007, 13210,  1393,
     198,   109,   425,    28, 14876, 13210,  1395, -2007,   621,  1354,
    1355,  7714, 15813,    56,  1132, 18483, 17042,   566, 13210, 13210,
    1142,  1139,  1146,  1140,  9286, -2007, -2007, -2007, -2007, 14690,
     332,  1141, 18508, 17069,  1148, -2007,   343, -2007,   357, 13694,
   -2007, -2007, -2007,  1149, -2007,  1151, 15842, 13867, -2007,    66,
   -2007, -2007, 18933, -2007,    80, 16826, 13210,   280,   -96,  7714,
    7714,  1402,  7714,  7714,  7714,  1406,  7714,  7714,  7714,  7714,
    7714,  7714,  7714,  7714,  7714,  7714,  2402,  1407, 10586,  4984,
   -2007, -2007,    32, -2007, -2007, -2007, -2007, -2007, -2007, -2007,
   -2007, -2007, -2007, -2007, -2007, -2007, -2007, 13210, -2007, -2007,
   -2007, -2007, -2007, -2007, -2007, -2007, -2007, 13210, 13210, 13210,
   13210, 13210, -2007, -2007, -2007,   622, 13210, 13210, -2007, 13210,
   -2007,  7714, 14690, 14690, -2007,   623, 15871, 15900, 15929,  1152,
   -2007, -2007, -2007,  1217, 15958, 15987, 16016, 13210, 16045, 16074,
   13210, 13210, -2007, -2007, -2007,   425, -2007,   425, 13210, 13210,
    1156, -2007,  7714,  -171, -2007, -2007, -2007, 13210, 13210,   624,
     425,   465,  -142, 13210, 13210, -2007,   280,   630,  7714, 10586,
   10586,  1415,  1417,  1420,  5360, -2007, -2007,  1422, -2007,  1164,
   18933,  1157,  1425, -2007,  1426,  1427,  2522,  1428,  1429,   632,
     490, -2007, 13961, -2007, -2007,   -77, 14066, 14286, -2007, -2007,
   16103,  -138,  1316,  1434, 12258,  1163,  1433,  1176,    40,    65,
     -92, -2007,   -71, -2007,   457,  1435,  1437,  1445,  1446,  1447,
    1448,  1449,  1450,  1451,    32,    32,  7714, 18933, -2007,  2803,
    1191,  1341,  1454, -2007,  1456,  1457,  1356,  1460, -2007, -2007,
    1461,  1458,  1466, 13210,  1467,  7714,  1468,  7714,  7714,  1469,
   14914, -2007,  8170,  1631,   425, 13210, 13210,   425,   425, -2007,
   10586, -2007, -2007, -2007, -2007, 14690, -2007, -2007, 13210, 14690,
   -2007, -2007, -2007, -2007, 18933, -2007,  1205,  1204, 14690, -2007,
   14690, -2007,   425, 14690,  1213, -2007,  1207,  1475, -2007,  1214,
     548,  1216, 12515, -2007,  3585,  1219,  7714, -2007,  1229, -2007,
   16132, -2007, -2007, 13210,  1479,    31, 13210,  1480,  1496,    27,
    1498,  1242,  1503,  3715, -2007,   280,  -171,  -171,  1504, -2007,
   -2007,  1253,  1257,  1246, -2007,  1507, -2007, -2007, -2007, -2007,
   -2007, -2007,   425,   289,  3651, 13210, 17096, 18533, 13210,  9543,
   13210, 10586,  1254,   637,  1516,   152,   425, -2007,  1255, 13210,
    1520,  1521, 13210,   425, 12603,  1523, 13210,  2453,   280,  5616,
   13210, 13210, 13210,  1264,  1259, -2007,  1524, 18558,  1527,   124,
    1394,  1394,  7714,  1529,  1530,  1531,  7714,  -110,  1532,  1533,
    1534,  1535,  1536,  1538,  1539,  1543,  1544, -2007,  1546,   642,
    1284, 16826, 16826, 16826, 16826, 16826, 16826,   280, 14962, 14995,
   15028,  1287,   280,   280, -2007, -2007, -2007, -2007,    80,   280,
    1430,  1431,  1432, 16161,  1361, -2007, 18583, 16826,  1299,   -25,
   18933, 16826, -2007,  1557,   280, 18933, 18933, -2007,   161, -2007,
     425, -2007, 18608, 17123, -2007,   280,  1559,   644,   649,  7714,
    7714,  7714,  1562,  1561, -2007,   273, 13210,  7714,  7714,  7714,
   -2007,  1304,  1307,  1563,  1565,  1567, -2007, 13210, 13210, 13210,
    1313,  1315,  1317,  1311, -2007,  4807,  7714, -2007, 13210, -2007,
    1570, -2007,  1572, -2007, -2007, 11556,   -43,  6928, -2007,  1318,
    1320,  1326,  1327,  1328,  1333,  9800,  1334,  1335,  1574, -2007,
   10586,  1337, -2007, -2007, -2007,  1338, 13210, 13210, -2007, -2007,
   17150,  7714,  1576,  7714,  1581,  1373, -2007, 13210, 13210, 13210,
   -2007,   398,  1583,   486,   539,  1339,  3241,  1340, 13210,    22,
     280,  1342,   280,  1343, -2007, -2007, 14876, -2007, 13210,  1346,
   -2007, -2007,  4930, -2007, -2007,  1345,  1585, -2007,  5123, -2007,
    1360,  1586,   263,  5146, -2007,    27, -2007,   650, -2007, 13210,
   -2007, -2007,   273,  5027,  1847, -2007,  1347, 13210, 13210,  7714,
    1363, -2007,   -12,   494,  1592, 18633,  1593,  1350, 18658,  1367,
     652, 18683,   655,  1594,  1596, -2007, -2007, 14690,  1351,  1564,
   18708, -2007, -2007, 15061,  1376, -2007, -2007,  8694,  5878, 18933,
   -2007,  1618,  -171,  8238, -2007, -2007, -2007, 18933, 18933, 18933,
   -2007,    80, -2007,  1629, -2007, -2007,   -96,  1632,  1635,  1636,
   -2007, -2007, -2007,  1497,   -24,  1540,  1637, -2007, -2007, -2007,
   -2007, -2007, -2007, -2007, -2007, -2007,  1640,  1378,  1642, -2007,
   -2007, -2007, -2007, -2007, -2007, -2007, 13210, 13210, 13210, -2007,
   -2007, -2007,  1259, -2007,  1381,  1382,  1383, -2007,  1545, -2007,
   -2007, -2007, 13210,  1388,  1384, -2007, -2007, 13210, 13210,   280,
     465, -2007, -2007, -2007, -2007,  1387,  1390,  1650,  -110,  1656,
   13210, -2007,  7714, 18933,  1517,  1518,   804, 10586, 10586, 13210,
   -2007, 11202, 16190, 18733,  8956,    32,    32, 13210, 13210, -2007,
     140,  1410, 18758, -2007, -2007, 16219,   -41, -2007,  1657,  1679,
    7714,   -96,   -96,   -96,   -96,   -96,  7190,  1680, -2007, -2007,
   -2007,   657, 10586, 13210,  5248,  5271,  1682,  1683, -2007,  1684,
   -2007,  7714,  9218,   433, 18783, 13210, 13210, -2007, -2007, 10843,
   -2007, 14690, 13210, -2007, 14690, 18933, 10940, 14876,  1418, -2007,
   -2007, -2007, -2007,  1436,  1419, 16248, 13210, 14932, -2007, 14932,
    7714, -2007, -2007,   425,    28, 14876, 13210,  1687, -2007,  1688,
   -2007,    27, 17177,  7714, 14690,  1690,   280, -2007,  1438,   280,
   13210, 15094, 15127,   658, -2007, 13210, 13210,  1439, -2007,  1440,
   -2007,  1420,  1691,  1692,  1427,  1693, -2007, -2007,  1696, 13210,
   -2007, -2007, 13210, 12860,  1697, 13210, -2007, -2007,  1441,  1847,
     660,  6860,  1698, -2007, -2007,   541, -2007, -2007, -2007,  1553,
    1704,  1444,  1452,  1453, -2007,  1708,  7714, -2007, 16826, 16826,
   15160, 13210, 13210, 13210,  1473, 16826, -2007,  1477, 18808, 17204,
   -2007, -2007, 10586, 10586, -2007,  1709, -2007, 18933,  1710, 13210,
   13210,  1476, -2007,   665,   666, 16798,  5333,  1712,  1478, -2007,
   -2007, 13210,  1474,  1491, 16277, 17231,  1713,  7714,  1707,  1481,
   13210, -2007, -2007,   668,   266,   291,   301,   303,   309, 10062,
     372, -2007,  1741,   671, 16306, -2007, -2007, -2007, -2007, -2007,
    1556, -2007, 13210, 13210, -2007, -2007, 12948, 10324,  5810,  1742,
    1755,  1499, 16826,   280, 18933, -2007, -2007, -2007, -2007,    22,
   -2007, 14876, -2007, 16335,  1493,  1494,  1500,  1758,  1761,  1762,
    6022, -2007, -2007, -2007,  1501,  1764,   673, -2007,  1766,  1767,
     443, 18933, 13210, 13210,  1506,  7714,   678, 18933, 18833, -2007,
   -2007, -2007, -2007, 18858, 15193, -2007, -2007, 16364,  1152,  1204,
    7714,   280, -2007, 13210, 14876,    34, -2007, -2007, 10586, 10586,
   13210,  1769,   685, -2007, -2007, 13210, 15226, 16393, 15259, 13210,
    1384, -2007, -2007, -2007,   691,   694, -2007, -2007,  6063,  6086,
    7714,   664,   684, 10586, -2007, -2007,    32,  9475, -2007, -2007,
   -2007,  1770, -2007,  1509,  7714, -2007, 16422,  1774, 10586,   -96,
     -96,   -96,   -96,   -96, -2007,  1775, -2007, 13210, 16451, 16480,
   10586, -2007,   699, -2007, -2007, -2007, -2007, -2007, -2007, -2007,
    1525,  1776,  1515, -2007,  1780,    27, -2007, -2007, -2007,  1590,
   -2007, -2007, -2007, -2007, -2007, 13210, 15292, 15325,  7714, -2007,
    1783, 13210,  1526, -2007, 13210,  1785,  1537,  1541, -2007, -2007,
    7122, -2007,  1528,   700,   712, 16509, -2007,  1547, 15358, 13210,
   -2007, 13210, 16538,  1551, -2007,  1549, -2007, -2007,   713,  1550,
     -96,  7714,  1787,  1552,   -96,  1792,   714,  1542, -2007, 13210,
   -2007,  1793,  1653, 14071,  1555, -2007,   715,   390,   394,   400,
     440,   442, -2007,  6339, -2007, -2007,   720, -2007,  1795, -2007,
   -2007, -2007,  1796, -2007,  1558, 18933, 13210, 13210,   722, -2007,
   18933, 15391, -2007, -2007, -2007,  1152, 14876,  1560, -2007, -2007,
   -2007, 13210, 13210, 16567, 16596, -2007, -2007, 10586,  1797,   -96,
     187, -2007, -2007,   -96,   200, -2007,  1798, -2007, 16625, -2007,
   13210, -2007,   457, -2007,  1799, 10586, 10586, 10586, 10586, 10062,
   -2007, -2007, -2007, 14932, -2007, 13210, 18883, 15424,    53, 13210,
    1566, -2007, -2007, 15457, 15490, -2007, -2007,   727, -2007,   445,
   -2007,   452, -2007, -2007, -2007,  6598,   434, 14134, -2007,   728,
     729,   734,   735,   459,   736,  1568,   737, -2007, 13210, -2007,
    7714, 16654, -2007, 13210, 13210, -2007,   -96,   -96, -2007, -2007,
   -2007,   457,  1802,  1806,  1815,  1821, 10586,  1823,  1824,  1825,
    1571, 18908,   768,  1826, 16683, 16826,   507,   509,   454, -2007,
   -2007, -2007, -2007,   769, -2007, -2007, -2007, 14690, -2007,  1575,
   -2007,  1827, -2007, 13210, 13210, -2007,  1828,   774, -2007,  1577,
    7714, -2007, 16712, 16741, -2007,  1830, 14690, 14690,   776,  1834,
    1836, -2007, -2007,   777, -2007,  1838, -2007, -2007,  1840, 14690,
   -2007, -2007, -2007
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -2007, -2007, -2007, -2007,   395, -2007, -2007, -2007, -2007,  -408,
   -2007, -2007, -2007, -2007, -2007, -2007, -2007, -2007, -2007, -2007,
   -2007, -2007,  -774,  -133,  3927,  3484,  -402, -2007,  1359, -2007,
   -2007, -2007, -2007, -2007, -2007, -2006, -2007,   331,   142,  -195,
   -2007,  -154, -2007,    81,   377, -2007,  1857, -2007,   752,   -45,
    1277, -2007,     0,  -663,  -124, -2007, -2007, -2007, -2007, -2007,
   -2007, -2007,   740,  1861, -2007, -2007, -2007, -2007, -1322, -1319,
    1862, -1849,  1863, -2007, -2007, -2007,  1222, -2007,  -213, -2007,
   -2007, -2007, -2007,  2637, -2007, -2007, -1522,   257,  1889, -2007,
       2, -2007, -2007,   -57, -2007, -1799,   831, -2007,   -17,  3225,
    3324,  -328,    44, -2007,   879,   355, -2007, -2007,    47,   243,
   -1776,  -152,  1068, -2007,    -3
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -602
static const yytype_int16 yytable[] =
{
     150,  1584,  1586,   131,   658,  1007,  1008,  1763,  2014,   694,
    2015,  1973,   490,   340,   342,  1115,   345,   469,   174,   326,
     361,  1121,   176,   189,   387,   440,  1846,   175,   442,   781,
     193,   392,   174,   389,   579,   781,   476,  1724,   174,     4,
     608,   174,  2146,  1367,   494,   396,  1579,   585,   158,   451,
     314,   782,   991,   309,   165,  1313,   167,   782,  1191,  2289,
    1430,   346,   783,   784,   366,   789,   367,   817,   783,   784,
    2007,  1581,     5,  1467,  1314,   666,   667,   315,   314,  1921,
     385,   331,   586,   365,  1469,  1315,  1316,  1317,   500,   309,
    1725,  1318,  1319,   177,   309,   178,  1002,   320,  1922,   395,
     321,   322,   323,   174,  1313,  1130,  1470,   828,   800,   332,
     436,   362,   154,   324,   666,   667,  1412,  1471,  1472,   463,
     464,   666,   667,  1314,  1254,   333,   334,  2062,  1540,  1255,
    1715,  1571,  1136,  2051,  1315,  1316,  1317,   785,   786,   153,
    1318,  1319,  1009,   785,   786,   666,   667,   475,   610,   666,
     667,   477,   485,   485,   485,   630,   336,   337,  1686,   815,
     347,   492,   630,   368,   348,   668,  1013,   816,   338,   732,
     349,   350,   339,   351,   352,   666,   667,  1583,   357,   388,
     358,   666,   667,   325,    69,    70,    71,    72,   390,   524,
      75,    76,   155,  2270,   666,   667,  1567,   353,   485,   532,
      85,  1114,  1585,   309,    89,  1412,  2272,   309,   309,  2260,
     669,   666,   667,   309,   309,   485,   574,   575,   576,   992,
     674,   160,   787,   788,   363,  1580,  1807,   821,  1650,  1651,
     156,   973,  1970,   151,  1847,   822,   590,   152,   730,   177,
     699,   178,  1937,  1431,  1432,  1433,  1434,   834,  1258,   123,
    1582,   123,  1886,   835,  1836,   103,  -598,   104,   105,   106,
     107,   108,   123,   123,   161,   112,   113,  1584,   115,   123,
    1865,   695,   123,   696,   309,   157,  1119,   152,   661,   662,
    1412,  2168,   162,   190,   364,  1081,   670,   675,   441,   309,
     194,   443,   309,   606,   163,   393,  1419,   580,   605,   643,
     644,   645,   792,   609,   793,   397,  1368,   452,   309,   309,
     159,   453,   309,   309,   309,   309,   166,   763,   168,   766,
    1192,  2290,   818,   309,   819,  1435,   772,   309,   820,   395,
     177,   449,   178,  1065,   123,   450,  1413,  1416,   837,  2208,
     689,   690,   691,   177,   835,   178,   459,   460,   461,   462,
     372,   309,   309,   373,   309,   309,   309,   561,   706,   562,
     463,   464,   829,   801,   819,   802,   374,  -594,   830,   803,
     463,   464,   309,  1137,  1138,   309,   666,   667,   721,  1415,
     152,   611,   612,   613,   614,   615,   616,   617,   618,   619,
     620,   621,   622,   623,   624,   625,   626,   627,   628,  1137,
    1138,  1127,   164,   629,  2285,   627,   628,   463,   464,  1966,
     631,   629,   632,  1224,   463,   464,   633,   631,  1144,   632,
     916,   463,   464,   633,   733,  1767,   734,  1768,  1155,   781,
     735,   459,   460,   461,   462,   459,   460,   461,   462,   666,
     667,  1993,   169,   485,   327,   309,   792,   328,   793,   309,
     309,   782,   666,   667,  1251,   463,   464,   170,   823,   463,
     464,   826,   783,   784,   217,   309,   824,   677,   435,   827,
     439,   678,   804,   611,   612,   613,   614,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   731,   625,   626,   627,
     628,  2312,  1838,  1839,  1564,   629,  1234,   842,  1887,   171,
     459,   460,   461,   462,   827,   474,   459,   460,   461,  1120,
     459,   460,   461,   462,   336,   337,   782,   692,   666,   667,
     782,   693,   172,   309,   463,   464,   338,   783,   784,  1500,
     344,   783,   784,   998,   501,  1000,  1001,   785,   786,  2098,
     503,  2348,  1263,   666,   667,   792,   186,   793,  2163,   309,
     463,   464,  1014,   666,   667,   666,   667,  -596,   309,   906,
     173,   666,   667,   485,  2099,   485,   309,   485,   485,   492,
     187,   932,  1035,   869,  2100,   923,  2101,   870,   666,   667,
     583,  1313,  2102,   584,   309,   309,   309,  1069,   485,   485,
     309,   176,   188,   176,   676,   309,   938,  1455,   940,  1057,
    1314,  1313,   785,   786,  1313,   870,   785,   786,  1460,  1005,
    1006,  1315,  1316,  1317,   662,   871,   870,  1318,  1319,   870,
    1314,   309,  1461,  1314,   666,   667,   792,   970,   793,   794,
     870,  1315,  1316,  1317,  1315,  1316,  1317,  1318,  1319,   191,
    1318,  1319,   666,   667,  1096,  2103,   666,   667,   192,   309,
     309,   180,   666,   667,   181,   195,  1116,   182,   792,   183,
     793,   943,  1835,  2245,  1836,   870,   827,  2246,   477,   477,
      46,  1596,  1597,  2247,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   621,   622,   623,   731,   625,   626,
     627,   628,   666,   667,   666,   667,   629,   666,   667,   309,
     309,   309,  1994,  2299,   666,   667,  1392,   309,  2134,  1393,
    1418,   666,   667,  2248,   212,  2249,  2135,   213,  2296,   196,
     214,   205,   177,  2335,   178,  2297,   463,   464,  1257,  1064,
     197,  1258,  2306,   215,   492,   485,   492,   485,   485,   485,
     485,   485,   485,   198,   485,   485,   485,   485,  1083,   199,
     485,   485,   485,   176,  1089,   130,   200,   309,  1088,   666,
     667,   666,   667,   792,  1132,   793,   792,   320,   793,   201,
     321,  1370,   323,   316,  1390,   309,   317,   202,   318,   184,
    2333,  1782,  2334,   324,   622,   623,   731,   625,   626,   627,
     628,   309,   977,   666,   667,   629,   870,  1124,   731,   625,
     626,   627,   628,   206,   792,   978,   793,   629,  1951,   870,
    1952,   776,   870,   309,  1141,   319,  2169,  2170,   203,   309,
     204,   309,  2171,   208,   492,  1153,   207,   463,   464,   610,
    1445,   209,  1366,  1159,  -597,   485,  2173,  2174,   463,   464,
    1275,  1273,  2171,  1274,   463,   464,   210,  1365,  1024,  1366,
    1025,   313,   870,  1528,   870,  1529,  1098,  1104,  1261,  1297,
     870,  1105,   870,   870,   211,   309,   218,   309,  1538,  1298,
     444,   310,  1345,   870,   311,  1302,   870,  1346,  1866,  1347,
     312,   870,  1350,   870,   329,  1396,   870,   307,  1873,   870,
    1425,  1507,  1514,  1537,   870,   870,   870,   870,  1565,  1545,
     330,  1563,   471,   870,   309,   870,  1684,   471,   471,   471,
     870,  1737,   356,  1775,   309,   870,   471,   870,  1776,  1870,
    2276,  1893,   870,  1871,  1895,   870,  1982,  2034,   870,  2052,
     870,  2035,  1275,  2053,  2081,  2082,   359,  2097,   870,   870,
    2105,  2035,  2131,   309,   870,  1305,   827,  2140,   335,   343,
     939,  2141,  1311,   471,  2157,   354,  1322,  1584,  2035,   309,
    2164,   355,  1621,  2165,   870,  1622,  1623,   870,  2197,  2218,
     471,   309,   870,   870,   360,   797,   369,  1414,  1417,  2318,
     309,  2219,  2228,  2236,  2244,   870,  2035,   870,   870,  2251,
    1633,  2258,   309,   870,  1275,  2035,  2295,  2302,  2303,  1584,
     870,   870,   870,  2304,  2305,  2307,  2309,   870,   870,   870,
    2141,   370,   573,  1652,   614,   615,   616,   617,   618,   619,
     620,   621,   622,   623,   731,   625,   626,   627,   628,   473,
     371,   588,   589,   629,   483,   486,   487,  2329,  2336,   381,
    1672,  2035,   870,  2345,   382,  2355,  2358,  2346,   533,  2035,
    2359,   383,   384,   792,  1688,   793,   974,   386,   405,   391,
     398,  1694,   611,   612,   613,   614,   615,   616,   617,   618,
     619,   620,   621,   622,   623,   868,   625,   626,   627,   628,
     519,   406,   399,   437,   629,   447,   792,   454,   793,   446,
     448,  1656,   455,   481,   480,   500,   152,   534,   498,   502,
     507,   511,   309,   525,   569,   572,   531,  1084,   307,  -208,
    1421,  1479,  -209,  -210,   581,   582,   587,   591,   309,   594,
     595,   596,   607,   639,   640,   647,   450,   649,   655,   679,
     648,   309,  1962,  1963,   652,   657,   485,   659,  1539,  1541,
     660,   680,   681,   697,   682,   683,   642,   684,   685,   700,
     701,   698,   709,   714,   702,   703,   704,   651,   705,   710,
     711,   656,   712,   713,   715,   716,   309,   309,   718,   309,
     309,   309,   724,   309,   309,   309,   309,   309,   309,   309,
     309,   309,   309,   723,   740,   309,   758,   741,   742,   753,
     754,   756,   477,   759,   757,   761,   762,   760,   471,   764,
    1167,   767,   765,   775,   778,   791,   796,   798,   799,   777,
     611,   612,   613,   614,   615,   616,   617,   618,   619,   620,
     621,   622,   623,   731,   625,   626,   627,   628,   309,   485,
     485,   812,   629,   616,   617,   618,   619,   620,   621,   622,
     623,   731,   625,   626,   627,   628,   812,   151,   839,   843,
     629,   805,   866,   861,   845,   873,   874,   875,   907,   309,
     946,   917,   918,   919,   920,   927,   928,   929,   931,   934,
     629,   947,   944,   982,   983,   309,   309,   309,   986,   997,
     996,   999,  1027,   773,   774,  1029,  1044,  1030,  1033,  1042,
    1055,  1058,  1103,  1091,  1093,  1097,  1107,  1108,  1113,   790,
    1112,  1117,  1128,  1129,  1145,  1134,  1147,  1150,  1158,  1160,
    1539,  1541,  1164,  1168,  1163,  1169,  1170,  1172,   471,  1173,
     471,  1174,   471,   471,   471,   769,  1176,  1869,  1177,  1178,
    1179,  1180,  1181,   309,   477,   477,  1182,  1183,  1184,  1185,
    1188,  1291,  1194,   471,   471,  1222,  1231,  1232,  1233,  1223,
    1250,  1247,   309,  1241,   309,   309,  1256,  1262,  1266,  1278,
    1270,  1286,  1279,  1280,  1288,  1312,  1300,   309,  1308,  1309,
    1334,  1335,   485,  1336,  1338,  1359,   485,  1355,  1357,  1358,
    1364,  1373,  1374,  1386,  1375,   485,  1378,   485,  1388,  1395,
     485,  1389,  1399,  1401,  1402,  1400,  1405,  1406,  1407,  1411,
     913,  1424,  1442,   309,  1426,  1427,  1448,  1449,  1451,  1482,
    1450,  1456,  1459,  1486,  1498,  1464,   395,  -211,   642,  1463,
     933,  1532,  1549,  2177,  1550,  1518,   812,  1551,  1554,  1555,
    1556,  1576,  1557,  1558,  1559,  1561,  1562,  1572,  1573,  1577,
    1578,   485,  1587,  1588,  1601,   910,   309,   912,   309,   914,
     915,   812,  1589,  1590,  1591,  1592,  1593,  1594,  1595,  1600,
    1602,  2017,  1603,  1604,  1608,  1605,   309,  1606,  1607,  1422,
     935,   936,  1609,  1616,  1611,  1613,  1628,  1629,  1635,   309,
    1636,  1637,  1638,   309,  1640,  1649,  1654,  1644,   814,   471,
     471,   471,   471,   471,   471,   471,   471,   471,  1646,   471,
     471,   471,   471,  1655,  1658,   471,   471,   471,  1659,  1660,
    1665,  1878,  1878,  1671,  1669,   812,  1857,  1667,   812,  1867,
    1859,  1668,  1685,  1683,   812,  1689,  1691,  1692,  1806,  1696,
    1712,  1710,  1711,  1714,  1716,  1720,  1721,  1722,  1727,  1728,
    1729,  1730,  1731,  2023,  1732,  1733,   309,   309,   309,  1734,
    1735,  1736,  1749,  1738,   309,   309,   309,  1754,  1755,  1756,
    1131,  1758,  1133,  1765,  1761,  1774,  1780,  1781,  1900,  1831,
    1789,  1790,  1787,   309,  1791,  1788,  1803,  1798,  1804,   471,
    1820,  1795,  1828,  1796,   309,  1797,  1810,  1830,  1811,  1837,
     471,  1861,   309,  1864,  1812,  1813,  1814,   309,  1888,  1890,
    1896,  1815,  1897,  1818,  1819,  1822,  1823,  1851,   309,  1109,
     309,  1880,  1841,  1844,  1856,  1899,  1393,  1068,  1860,  1070,
    1071,  1072,  1073,  1074,  1075,  1908,  1077,  1078,  1079,  1080,
    1863,  1885,  1085,  1086,  1087,  1914,  1892,  1941,  1916,  1619,
    1903,  1917,  1918,  1924,  1919,  1925,  1926,  1923,  1927,  1931,
    1932,  1933,   395,  1936,  1934,  1942,  1944,  1258,  1943,  1915,
     492,   492,  1946,  1971,  1949,  1950,   309,   613,   614,   615,
     616,   617,   618,   619,   620,   621,   622,   623,   731,   625,
     626,   627,   628,  1967,   485,  1972,  1981,   629,  1987,  1988,
    1989,  2009,  2011,  2021,  2022,   309,  2027,  2039,  2040,  2041,
     309,  2010,  2042,  2046,  2056,  2055,  1151,  -601,  -599,  2050,
    2057,   827,  2058,  2061,  2094,  2076,  2077,  1161,  2085,  2092,
    2059,  2060,  2026,   611,   612,   613,   614,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   731,   625,   626,   627,
     628,  2069,  2071,  2088,  2080,   629,  2086,  2104,  2114,  2095,
     812,  2107,   812,   812,  1974,  1975,  1976,  1977,  1978,  1980,
    2089,  2115,  2122,  2123,  2116,  2125,   812,  2126,  2127,  2124,
    2130,  2129,  2132,  2133,  2138,  2156,  2180,  1265,  2181,   309,
    2185,  2192,  2199,  2200,   309,   309,  2201,   812,  2203,  2209,
    2198,  2212,  2217,  2232,  -600,   477,   477,  2202,  2235,  2239,
    2240,  2252,  2254,  2268,  2273,  2278,  2213,   309,  2319,   812,
    2214,  2237,  2320,   309,  1285,  2221,  2226,  2227,  2229,   309,
    2233,  2321,  1700,  2243,  1705,  2262,  2255,  2322,   309,  2324,
    2325,  2326,  2330,  2341,  2344,  2292,  2351,  2308,   485,  2327,
    2356,   485,  2357,  2340,  2360,  2347,  2361,  2286,   812,  1752,
    1687,   174,   407,  1913,  2147,  2119,   838,   309,  1718,  1945,
     129,  1421,   930,  1441,   140,   141,   142,   985,   395,  2175,
     309,   492,   611,   612,   613,   614,   615,   616,   617,   618,
     619,   620,   621,   622,   623,   731,   625,   626,   627,   628,
    1853,   471,   148,  2006,   629,  1152,  1620,   408,   409,   410,
     411,   412,   413,   414,   415,   416,   492,  1879,  2018,     0,
     417,   418,   419,   420,     0,     0,     0,     0,   421,   422,
     423,   424,     0,   309,     0,     0,     0,   425,     0,   426,
       0,     0,     0,     0,     0,     0,  1408,     0,     0,   309,
     309,     0,     0,   427,     0,     0,   428,     0,     0,     0,
     180,     0,  1428,   181,     0,     0,   182,     0,   183,     0,
       0,     0,     0,     0,   309,     0,     0,     0,     0,    46,
       0,  2183,     0,     0,     0,     0,   309,     0,     0,     0,
       0,     0,     0,     0,   471,   471,     0,     0,     0,     0,
     457,  1854,     0,     0,   309,     0,     0,     0,     0,     0,
    1480,  1481,     0,  1483,  1484,  1485,     0,  1487,  1488,  1489,
    1490,  1491,  1492,  1493,  1494,  1495,  1496,     0,  1454,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   309,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2187,  2188,  2189,  2190,  2191,   309,     0,     0,
       0,     0,  2152,  1907,   812,   309,   309,     0,     0,     0,
       0,     0,  1511,   429,   430,   431,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   432,  2253,   309,     0,   433,
     309,   434,   123,     0,     0,     0,   477,     0,     0,     0,
       0,   309,     0,  1533,     0,   309,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   309,     0,  1546,
       0,  1512,  1513,  2230,     0,  1874,     0,  2234,     0,  2277,
       0,     0,   395,     0,     0,     0,     0,   471,     0,     0,
       0,   471,     0,     0,     0,   309,     0,     0,     0,     0,
     471,     0,   471,     0,     0,   471,  1957,     0,     0,     0,
       0,     0,  1639,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1598,   309,     0,
       0,     0,  2269,     0,     0,     0,  2271,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1612,     0,  1614,  1615,
       0,     0,  2283,     0,  2000,     0,   471,     0,     0,     0,
       0,  2005,  2008,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2019,     0,     0,     0,   309,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1645,     0,  2316,
    2317,     0,   309,   309,   309,   309,   309,     0,     0,     0,
       0,     0,     0,     0,  1625,     0,     0,     0,  1627,     0,
       0,     0,     0,     0,     0,     0,     0,  1631,     0,  1632,
       0,     0,  1634,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   309,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1704,     0,     0,   309,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1719,     0,     0,     0,  1723,     0,     0,
       0,     0,     0,  1674,   485,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   309,  1349,     0,
       0,     0,     0,   485,   485,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   485,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2120,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1777,  1778,  1779,     0,     0,     0,     0,     0,  1784,  1785,
    1786,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1801,  1497,  2151,
       0,     0,     0,     0,     0,   471,   471,     0,  1809,     0,
       0,     0,     0,     0,     0,     0,  1817,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   471,
       0,     0,  1827,     0,  1829,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   219,   174,   407,     0,
       0,     0,     0,   220,   221,   222,     0,     0,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   401,   242,   243,   244,
     245,   246,   247,   248,   249,   610,     0,     0,     0,     0,
    1884,     0,     0,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   255,   256,   257,   258,   417,   418,   419,   420,
     259,     0,     0,     0,   421,   422,   423,   424,  1560,  1906,
       0,     0,     0,   425,     0,   426,   264,   265,   266,     0,
       0,     0,     0,     0,     0,     0,     0,   267,    25,   427,
     268,     0,   428,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1898,     0,     0,     0,
       0,  2261,     0,   611,   612,   613,   614,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   731,   625,   626,   627,
     628,     0,     0,   471,     0,   629,   471,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   812,
       0,   812,     0,  1948,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   471,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1884,     0,   611,   612,   613,   614,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   731,   625,   626,   627,
     628,   471,  1990,     0,     0,   629,     0,     0,   282,   429,
     430,   431,   283,     0,     0,     0,     0,     0,   285,   286,
     287,   432,   288,   289,   290,   433,     0,   434,   123,     0,
       0,  2016,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2025,   291,   402,     0,     0,     0,
       0,     0,   293,     0,     0,     0,     0,   377,     0,     0,
    2001,  1698,     0,  2003,   296,     0,     0,     0,   611,   612,
     613,   614,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   625,   626,   627,   628,   403,     0,     0,     0,
     629,     0,     0,     0,     0,     0,     0,  1884,     0,   445,
       0,     7,     8,   611,   612,   613,   614,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   731,   625,   626,   627,
     628,     0,     0,     0,     0,   629,     0,   472,     0,     0,
       0,   482,     0,     0,     0,     0,   488,     0,  2093,     0,
       0,     0,     0,   493,     0,     0,   495,     0,     0,  1599,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   504,   505,   506,     0,   508,   509,   510,
       0,   512,   513,   514,   515,   516,   517,   518,     0,   520,
     521,   522,   523,     0,     0,     0,     0,   527,   527,     0,
       0,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,     0,     0,  2139,    43,    44,    45,
      46,     0,     0,     0,     0,    48,     0,     0,     0,     0,
       0,  2148,     0,     0,   806,    57,     0,     0,    60,   807,
       0,   808,   809,     0,   810,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1884,     0,    82,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2182,     0,     0,   597,   599,
     601,   602,   527,     0,     0,   812,     0,     0,     0,     0,
      99,   100,   101,     0,     0,     0,     0,   636,   527,   527,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   654,     0,     0,     0,  1884,
       0,     0,     0,     0,     0,   664,   665,     0,     0,     0,
       0,   665,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   527,   527,   688,     0,     0,     0,     0,     0,     0,
       0,     0,  2231,     0,     0,   812,     0,     0,     0,     0,
       0,     0,     0,     0,   707,   527,     0,   832,     0,     0,
       0,     0,     0,     0,     0,   717,     0,   719,   720,   812,
     722,     0,     0,     0,   725,   726,   727,     0,     0,   729,
       0,     0,     0,   736,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   621,   622,   623,   731,   625,   626,
     627,   628,     0,     0,     0,     0,   629,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   471,
       0,     0,     0,     0,     0,   527,   771,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   471,   471,
       0,     0,   779,   780,     0,     0,     0,     0,     0,     0,
       0,   471,     0,     0,     0,     0,     0,   813,     0,     0,
       0,  1884,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   844,
       0,     0,     0,     0,   849,     0,     0,     0,   853,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   867,   599,     0,     0,     0,     0,   872,     0,
       0,  1884,   876,   877,   878,   879,   880,   881,   882,   883,
     884,   885,   886,   887,   888,   889,   890,   891,   892,   893,
     895,   896,   897,   898,   899,   900,   901,   902,   903,   903,
       0,   908,   909,     0,   911,     0,  2338,     0,     0,     0,
       0,     0,     0,     0,   921,     0,     0,   925,   926,     0,
       0,     0,     0,     0,     0,  2352,  2354,     0,     0,     0,
     903,     0,     0,     0,     0,   527,     0,     0,  2362,     0,
       0,     0,     0,     0,     0,     0,     0,   948,   949,   950,
     951,   952,   953,   954,   955,   956,   957,   958,   959,   960,
     961,   963,   965,   966,   967,   968,   969,     0,   971,   972,
       0,     0,     0,     0,     0,     0,   979,   980,   981,     0,
       0,     0,     0,     0,   987,   988,   989,   990,     0,   527,
     527,     0,     0,     0,     7,     8,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   597,   729,
    1010,     0,     0,     0,  1015,  1016,  1017,  1018,  1019,  1020,
    1021,  1022,  1023,     0,     0,     0,     0,     0,     0,  1031,
    1032,     0,  1034,     0,     0,  1036,     0,     0,     0,   527,
     527,   527,  1041,     0,     0,     0,  1045,   527,  1047,  1048,
    1049,     0,     0,  1050,     0,  1052,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1062,     0,     0,  1063,     0,
     971,   972,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1076,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,   527,     0,     0,
      43,    44,    45,    46,  1095,     0,     0,     0,    48,     0,
       0,     0,  1106,     0,     0,     0,     0,   806,    57,     0,
       0,    60,   807,     0,   808,   809,     0,   810,     0,     0,
       0,   527,     0,  1122,     0,   528,   528,     0,  1125,  1126,
       0,     0,     0,     0,     0,     0,    82,     0,     0,     0,
       0,     0,     0,   527,     0,  1142,  1143,     0,     0,   527,
       0,   527,  1149,     0,     0,     0,  1142,     0,  1156,     0,
    1157,     0,     0,    99,   100,   101,  1162,     0,     0,     0,
    1165,     0,   611,   612,   613,   614,   615,   616,   617,   618,
     619,   620,   621,   622,   623,   731,   625,   626,   627,   628,
       0,     0,     0,  1186,   629,   963,   792,  1189,   793,     0,
       0,     0,     0,     0,  1842,     0,     0,   600,     0,     0,
     528,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   529,   530,   528,   528,     0,     0,
       0,     0,     0,     0,   527,     0,     0,     0,     0,     0,
    1011,     0,     0,     0,   527,  1236,  1237,  1238,     0,     0,
       0,     0,     0,     0,  1244,  1245,  1246,     0,  1248,     0,
       0,  1249,     0,     0,     0,     0,     0,     0,     0,   528,
     528,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1643,     0,     0,     0,     0,     0,     0,     0,   527,
       0,     0,     0,   528,     0,     0,     0,     0,     0,     0,
       0,   527,     0,     0,     0,     0,     0,     0,     0,  1284,
       0,     0,     0,  1290,     0,     0,     0,     0,     0,  1296,
       0,     0,   527,     0,     0,   637,   638,     0,     0,     0,
    1306,  1307,     0,     0,     0,     0,  1310,     0,     0,     0,
       0,     0,     0,     0,     0,   174,   407,     0,     0,     0,
       0,     0,     0,     0,  1337,     0,     0,  1339,     0,     0,
       0,     0,     0,   528,     0,     0,     0,     0,   686,   687,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1360,     0,  1362,  1363,     0,     0,     0,
       0,   408,   409,   410,   411,   412,   413,   414,   415,   416,
       0,     0,     0,     0,   417,   418,   419,   420,  1384,     0,
       0,  1661,   421,   422,   423,   424,     0,     0,     0,     0,
       0,   425,     0,   426,     0,     0,     0,     0,  1404,     0,
       0,     0,     0,     0,     0,  1410,     0,   427,     0,     0,
     428,   600,  1423,     0,   180,     0,     0,   181,     0,     0,
     182,     0,   183,     0,     0,  1446,  1447,     0,     0,     0,
       0,   527,   770,    46,     0,     0,     0,   894,     0,     0,
       0,     0,     0,     0,     0,     0,   904,   905,     0,     0,
       0,     0,     0,     0,   457,     0,     0,     0,     0,     0,
       0,     0,     0,  1477,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   937,     0,
       0,     0,     0,   528,     0,   527,   611,   612,   613,   614,
     615,   616,   617,   618,   619,   620,   621,   622,   623,   731,
     625,   626,   627,   628,  1501,     0,     0,     0,   629,   964,
       0,     0,     0,     0,  1502,  1503,  1504,  1505,  1506,     0,
       0,     0,     0,  1508,  1509,     0,  1510,   429,   430,   431,
       0,     0,     0,     0,     0,     0,     0,   528,   528,   432,
       0,     0,     0,   433,  1523,   434,   123,  1526,  1527,     0,
       0,     0,     0,     0,     0,  1530,  1531,     0,     0,     0,
       0,     0,     0,     0,  1535,  1536,     0,     0,     0,     0,
    1542,  1543,   463,   464,     0,     0,   527,   527,     0,  -595,
       0,  1673,   941,     0,     0,     0,     0,   528,   528,   528,
       0,     0,     0,     0,     0,   528,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1575,     0,   179,   795,   185,   611,   612,   613,   614,
     615,   616,   617,   618,   619,   620,   621,   622,   623,   731,
     625,   626,   627,   628,     0,     0,   993,   994,   629,     0,
       0,     0,     0,     0,     0,   528,     0,     0,     0,     0,
    1610,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1542,  1543,     0,     0,     0,   527,     0,     0,
       0,     0,     0,     0,     0,  1626,     0,     0,     0,   528,
       0,     0,     0,     0,     0,     0,  1038,  1039,  1040,     0,
       0,     0,     0,     0,  1046,     0,     0,     0,     0,  1642,
       0,   528,     0,     0,     0,     0,     0,   528,     0,   528,
    1648,     0,     0,  1653,     0,     0,     0,     0,     0,     0,
       0,     0,   922,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   470,     0,     0,
       0,     0,  1675,     0,  1090,  1678,   527,  1681,   527,     0,
       0,     0,     0,   964,     0,  1190,  1690,     0,     0,  1693,
       0,  1690,     0,  1697,  1699,     0,     0,  1707,  1708,  1709,
       0,     0,     0,     0,     0,     0,     0,     0,  1118,   975,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   528,     0,     0,     0,     0,     0,     0,     0,
    1140,     0,   528,     0,     0,     0,  1146,     0,  1148,     0,
       0,   535,   536,   537,   538,   539,   540,   541,   542,   543,
     544,   545,   546,   547,   548,   549,   550,   551,   552,   553,
     554,   555,   556,   557,   558,   559,   560,   563,   564,   565,
     566,   567,   568,     0,   570,   571,     0,   528,     0,     0,
       0,     0,     0,  1783,   577,   578,     0,     0,     0,   528,
       0,     0,     0,     0,  1792,  1793,  1794,     0,     0,     0,
     592,   593,     0,  1800,     0,  1802,     0,     0,     0,     0,
     528,     0,  1805,     0,     0,     0,     0,     0,     0,     0,
       0,  1225,     0,     0,     0,     0,     0,   527,     0,     0,
       0,  1235,     0,  1824,  1825,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1832,  1833,  1834,     0,     0,     0,
       0,     0,     0,     0,     0,  1845,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1855,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1269,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1872,     0,  1277,     0,
       0,     0,     0,     0,  1881,  1882,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1299,
       0,     0,     0,     0,     0,     0,     0,     0,   728,     0,
       0,     0,     0,     0,     0,   737,   738,   739,     0,     0,
    1911,   743,   744,   745,   746,   747,   748,   749,     0,   750,
       0,     0,     0,     0,   751,   752,     0,     0,   755,   528,
    1195,  1196,  1197,  1198,  1199,  1200,  1201,  1202,  1203,  1204,
    1205,  1206,     0,  1208,  1209,  1210,  1211,     0,  1213,  1214,
    1215,  1216,     0,  1928,  1929,  1930,     0,     0,     0,     0,
       0,     0,     0,     0,  1228,     0,  1230,     0,     0,  1935,
       0,     0,     0,     0,  1938,  1939,     0,  1240,     0,     0,
       0,     0,     0,   528,     0,     0,     0,  1947,     0,     0,
    1252,  1253,     0,     0,   527,   527,  1955,     0,  1956,  1264,
       0,     0,     0,     0,  1964,  1965,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   527,     0,     0,     0,     0,  1453,   527,
    1984,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1938,  1939,     0,     0,  1998,     0,     0,  2002,
       0,     0,     0,  2004,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2013,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2020,   528,   528,     0,     0,     0,     0,
       0,     0,  1499,     0,     0,     0,     0,  2031,     0,     0,
       0,     0,  2037,  2038,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   945,     0,     0,  2043,     0,     0,  2044,
    2043,     0,  2047,     0,     0,     0,     0,     0,     0,     0,
       0,  1369,  1371,  1372,     0,     0,     0,  1376,  1377,     0,
       0,  1380,  1381,  1382,  1383,     0,  1385,     0,  2066,  2067,
    2068,  1391,     0,     0,     0,     0,     0,     0,     0,   527,
     527,     0,     0,     0,     0,     0,  2078,  2079,     0,     0,
       0,     0,     0,     0,     0,   528,     0,     0,  2087,     0,
       0,     0,     0,  1547,  1548,     0,     0,  2096,     0,     0,
       0,     0,     0,     0,     0,     0,   599,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2108,
    2109,     7,     8,   729,   527,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1476,
       0,  1478,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2136,
    2137,     0,     0,     0,   528,     0,   528,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2150,     0,     0,     0,  1624,   527,   527,  2155,     0,     0,
       0,     0,  2158,     0,     0,     0,  2162,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     527,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,     0,   527,     0,    43,    44,    45,
      46,     0,     0,     0,  2193,    48,     0,   527,     0,     0,
       0,     0,     0,     0,   806,    57,     0,     0,    60,   807,
    1544,   808,   809,     0,   810,     0,     0,     0,     0,     0,
       0,     0,  2205,  1680,     0,  1682,     0,     0,  2210,     0,
       0,  2211,     0,    82,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2223,     0,  2224,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      99,   100,   101,  1799,     0,     0,  2238,     0,     0,     0,
       0,     0,     0,     0,     0,   528,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2256,  2257,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2263,  2264,
       0,     0,     0,     0,   527,     0,     0,  1259,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2275,     0,     0,
       0,     0,   527,   527,   527,   527,   527,  1037,     0,     0,
       0,     0,  2037,     0,     0,     0,  2291,     0,     0,     0,
    1276,     0,     0,     0,     0,     0,     0,     0,     0,  1662,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1821,  2311,     0,     0,  1912,     0,
    2314,  2315,     0,     0,     0,     0,  1858,     0,     0,     0,
       0,     0,     0,   527,     0,     0,     0,     0,     0,     0,
       0,     0,  1701,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2342,  2343,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1739,  1740,  1741,  1742,  1743,
    1744,  1745,   610,     0,     0,     0,  1750,  1751,     0,     0,
       0,     0,     0,  1753,     0,     0,     0,     0,     0,     0,
       0,  1760,   528,   528,     0,  1764,     0,     0,  1766,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1773,
       0,   174,   407,     0,     0,     0,     0,     0,     0,     0,
       0,   528,     0,     0,     0,     0,     0,   528,   611,   612,
     613,   614,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   731,   625,   626,   627,   628,     0,     0,     0,     0,
     629,     0,     0,     0,     0,     0,     0,   408,   409,   410,
     411,   412,   413,   414,   415,   416,  1468,     0,     0,     0,
     417,   418,   419,   420,     0,     0,     0,     0,   421,   422,
     423,   424,     0,     0,     0,     0,     0,   425,  1840,   426,
    1843,  1953,  1954,     0,  1850,     0,  1852,     0,     0,     0,
       0,     0,     0,   427,     0,     0,   428,     0,     0,  1862,
     180,     0,     0,   181,     0,     0,   182,     0,   183,     0,
       0,     0,     0,     0,     0,     0,  1983,  1875,     0,    46,
       0,     0,  1868,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   528,   528,     0,
     457,   611,   612,   613,   614,   615,   616,   617,   618,   619,
     620,   621,   622,   623,   731,   625,   626,   627,   628,     0,
    1534,     0,     0,   629,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   600,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   528,     0,     0,   611,   612,   613,   614,   615,
     616,   617,   618,   619,   620,   621,   622,   623,   868,   625,
     626,   627,   628,   429,   430,   431,     0,   629,     0,     0,
       0,     0,     0,  1940,  1985,   432,     0,     0,     0,   433,
       0,   434,   123,     0,     0,     0,  2074,  2075,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1986,     0,     0,
       0,     0,     0,   528,   528,     0,     0,     0,     0,     0,
       0,     0,   792,     0,   793,  1874,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   528,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2112,     0,   528,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   528,     0,     0,     0,  2084,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1663,  1664,     0,     0,     0,     0,     0,
    2028,     0,     0,  2029,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   621,   622,   623,   731,   625,   626,
     627,   628,  2153,  2154,     0,     0,   629,   611,   612,   613,
     614,   615,   616,   617,   618,   619,   620,   621,   622,   623,
     731,   625,   626,   627,   628,     0,     0,  2176,     0,   629,
       0,     0,  2063,  2064,     0,     0,     0,     0,     0,  2070,
       0,     0,  2186,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2196,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   528,     0,     0,     0,  1762,     0,     0,     0,
       0,     0,     0,     0,     0,  1769,     0,     0,     0,     0,
     528,   528,   528,   528,   528,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2117,  2118,     0,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   621,
     622,   623,   731,   625,   626,   627,   628,  1552,     0,     0,
       0,   629,   611,   612,   613,   614,   615,   616,   617,   618,
     619,   620,   621,   622,   623,   731,   625,   626,   627,   628,
       0,   528,     0,     0,   629,  2149,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2267,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2279,
    2280,  2281,  2282,  2284,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   621,   622,   623,   731,   625,   626,
     627,   628,     0,     0,     0,     0,   629,     0,     0,     0,
       0,   611,   612,   613,   614,   615,   616,   617,   618,   619,
     620,   621,   622,   623,   731,   625,   626,   627,   628,   219,
       6,   407,     0,   629,     0,     0,   220,   221,   222,  1909,
    2323,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,     0,     0,     0,  1702,   409,   410,   411,
     412,   413,   414,   415,   416,   255,   256,   257,   258,   417,
     418,   419,   420,   259,   260,     0,     0,   421,   422,   423,
     424,     0,     0,   261,   262,   263,   425,     0,   426,   264,
     265,   266,     0,     0,     0,     0,     0,     0,     0,     0,
     267,    25,   427,   268,     0,   428,     0,     0,     0,   269,
       0,     0,   270,     0,     0,   271,     0,   272,     0,     0,
       0,     0,     0,     0,    42,     0,     0,     0,   273,   274,
     275,     0,     0,   276,     0,     0,     0,     0,     0,     0,
       0,     0,   277,     0,    58,    59,     0,   278,     0,   279,
       0,     0,   280,     0,     0,     0,     0,     0,    69,    70,
      71,    72,    73,     0,    75,    76,    77,    78,    79,    80,
      81,     0,     0,     0,    85,     0,     0,     0,    89,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2332,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   281,     0,     0,  2113,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   282,   429,   430,   431,   283,   284,     0,     0,     0,
       0,   285,   286,   287,   432,   288,   289,   290,   433,     0,
     434,   123,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   291,   292,
       0,     0,     0,     0,     0,   293,     0,     0,     0,     0,
     377,   219,     6,   407,  1703,     0,     0,   296,   220,   221,
     222,     0,     0,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,     0,     0,     0,   408,   409,
     410,   411,   412,   413,   414,   415,   416,   255,   256,   257,
     258,   417,   418,   419,   420,   259,   260,     0,     0,   421,
     422,   423,   424,     0,     0,   261,   262,   263,   425,     0,
     426,   264,   265,   266,     0,     0,     0,     0,     0,     0,
       0,     0,   267,    25,   427,   268,     0,   428,     0,     0,
       0,   269,     0,     0,   270,     0,     0,   271,     0,   272,
       0,     0,     0,     0,     0,     0,    42,     0,     0,     0,
     273,   274,   275,     0,     0,   276,     0,     0,     0,     0,
       0,     0,     0,     0,   277,     0,    58,    59,     0,   278,
       0,   279,     0,     0,   280,     0,     0,     0,  2128,     0,
      69,    70,    71,    72,    73,     0,    75,    76,    77,    78,
      79,    80,    81,     0,     0,     0,    85,     0,     0,     0,
      89,   611,   612,   613,   614,   615,   616,   617,   618,   619,
     620,   621,   622,   623,   731,   625,   626,   627,   628,  2166,
       0,     0,     0,   629,     0,   281,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2167,   282,   429,   430,   431,   283,   284,     0,
       0,     0,     0,   285,   286,   287,   432,   288,   289,   290,
     433,     0,   434,   123,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     291,   292,     0,     0,     0,     0,     0,   293,     0,     0,
       0,     0,   377,   219,   174,   407,   295,   456,     0,   296,
     220,   221,   222,     0,     0,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   401,   242,   243,   244,   245,   246,   247,
     248,   249,     0,     0,     0,     0,     0,     0,     0,     0,
     408,   409,   410,   411,   412,   413,   414,   415,   416,   255,
     256,   257,   258,   417,   418,   419,   420,   259,     0,     0,
       0,   421,   422,   423,   424,     0,     0,     0,     0,     0,
     425,     0,   426,   264,   265,   266,     0,     0,     0,     0,
       0,     0,     0,     0,   267,    25,   427,   268,     0,   428,
       0,     0,     0,   180,     0,     0,   181,     0,     0,   182,
       0,   183,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    46,   611,   612,   613,   614,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   731,   625,   626,   627,
     628,     0,     0,   457,     0,   629,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   621,   622,   623,   731,   625,   626,
     627,   628,     0,     0,     0,     0,   629,   611,   612,   613,
     614,   615,   616,   617,   618,   619,   620,   621,   622,   623,
     731,   625,   626,   627,   628,  2250,     0,     0,   458,   629,
       0,     0,     0,     0,     0,   282,   429,   430,   431,   283,
       0,     0,     0,     0,     0,   285,   286,   287,   432,   288,
     289,   290,   433,     0,   434,   123,     0,   459,   460,   461,
     462,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   291,   402,     0,     0,     0,     0,     0,   293,
       0,   463,   464,     0,   465,     0,   466,   219,     6,   376,
     467,   296,     0,     0,   220,   221,   222,     0,     0,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   255,   256,   257,   258,     0,     0,     0,
       0,   259,   260,     0,     0,     0,     0,     0,     0,     0,
       0,   261,   262,   263,     0,     0,     0,   264,   265,   266,
       0,     0,     0,     0,     0,     0,     0,     0,   267,    25,
       0,   268,     0,     0,     0,     0,     0,   269,     0,     0,
     270,     0,     0,   271,     0,   272,     0,     0,     0,     0,
       0,     0,    42,     0,     0,     0,   273,   274,   275,     0,
       0,   276,     0,     0,     0,     0,     0,     0,     0,     0,
     277,     0,    58,    59,     0,   278,     0,   279,     0,     0,
     280,     0,     0,     0,     0,     0,    69,    70,    71,    72,
      73,     0,    75,    76,    77,    78,    79,    80,    81,     0,
       0,     0,    85,     0,     0,     0,    89,     0,     0,     0,
     611,   612,   613,   614,   615,   616,   617,   618,   619,   620,
     621,   622,   623,   731,   625,   626,   627,   628,     0,     0,
       0,   281,   629,     0,  2298,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   282,
       0,     0,     0,   283,   284,     0,     0,     0,     0,   285,
     286,   287,     0,   288,   289,   290,     0,     0,     0,   123,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   291,   292,     0,     0,
       0,     0,     0,   293,     0,     0,     0,     0,   377,   219,
       6,     0,   378,     0,   708,   296,   220,   221,   222,     0,
       0,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   255,   256,   257,   258,     0,
       0,     0,     0,   259,   260,     0,     0,     0,     0,     0,
       0,     0,     0,   261,   262,   263,     0,     0,     0,   264,
     265,   266,     0,     0,     0,     0,     0,     0,     0,     0,
     267,    25,     0,   268,     0,     0,     0,     0,     0,   269,
       0,     0,   270,     0,     0,   271,     0,   272,     0,     0,
       0,     0,     0,     0,    42,     0,     0,     0,   273,   274,
     275,     0,     0,   276,     0,     0,     0,     0,     0,     0,
       0,     0,   277,     0,    58,    59,     0,   278,     0,   279,
       0,     0,   280,     0,     0,     0,     0,     0,    69,    70,
      71,    72,    73,     0,    75,    76,    77,    78,    79,    80,
      81,     0,     0,     0,    85,     0,     0,     0,    89,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   621,
     622,   623,   731,   625,   626,   627,   628,     0,     0,     0,
       0,   629,     0,   281,     0,     0,     0,  2054,   610,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   282,     0,     0,     0,   283,   284,     0,     0,     0,
       0,   285,   286,   287,     0,   288,   289,   290,     0,     0,
       0,   123,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   291,   526,
       0,     0,     0,     0,     0,   293,     0,     0,     0,     0,
     377,   219,     6,  1808,     0,   603,     0,   296,   220,   221,
     222,     0,     0,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   255,   256,   257,
     258,     0,     0,     0,     0,   259,   260,     0,     0,     0,
       0,     0,     0,     0,     0,   261,   262,   263,     0,     0,
       0,   264,   265,   266,     0,     0,     0,     0,     0,     0,
       0,     0,   267,    25,     0,   268,     0,     0,     0,     0,
       0,   269,     0,     0,   270,     0,     0,   271,     0,   272,
       0,     0,     0,     0,     0,     0,    42,     0,     0,     0,
     273,   274,   275,     0,     0,   276,     0,     0,     0,     0,
       0,     0,     0,     0,   277,     0,    58,    59,     0,   278,
       0,   279,     0,     0,   280,     0,     0,     0,     0,     0,
      69,    70,    71,    72,    73,     0,    75,    76,    77,    78,
      79,    80,    81,     0,     0,     0,    85,     0,     0,     0,
      89,   611,   612,   613,   614,   615,   616,   617,   618,   619,
     620,   621,   622,   623,   868,   625,   626,   627,   628,     0,
       0,     0,     0,   629,     0,   281,     0,     0,     0,  2216,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   282,     0,     0,     0,   283,   284,     0,
       0,     0,     0,   285,   286,   287,     0,   288,   289,   290,
       0,     0,     0,   123,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     291,   292,     0,     0,     0,     0,     0,   293,     0,     0,
       0,     0,   377,   219,     6,     0,   295,     0,     0,   296,
     220,   221,   222,     0,     0,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   255,
     256,   257,   258,     0,     0,     0,     0,   259,   260,     0,
       0,     0,     0,     0,     0,     0,     0,   261,   262,   263,
       0,     0,     0,   264,   265,   266,     0,     0,     0,     0,
       0,     0,     0,     0,   267,    25,     0,   268,     0,     0,
       0,     0,     0,   269,     0,     0,   270,     0,     0,   271,
       0,   272,     0,     0,     0,     0,     0,     0,    42,     0,
       0,     0,   273,   274,   275,     0,     0,   276,     0,     0,
       0,     0,     0,     0,     0,     0,   277,     0,    58,    59,
       0,   278,     0,   279,     0,     0,   280,     0,     0,     0,
       0,     0,    69,    70,    71,    72,    73,     0,    75,    76,
      77,    78,    79,    80,    81,     0,     0,     0,    85,     0,
       0,     0,    89,   611,   612,   613,   614,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   731,   625,   626,   627,
     628,     0,     0,     0,     0,   629,     0,   281,     0,     0,
       0,     0,  1059,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   282,     0,     0,     0,   283,
     284,     0,     0,     0,     0,   285,   286,   287,     0,   288,
     289,   290,     0,     0,     0,   123,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   671,  1979,     0,     0,     0,     0,     0,   293,
       0,     0,     0,     0,   673,   219,     6,     0,   339,   603,
       0,   296,   220,   221,   222,     0,     0,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   255,   256,   257,   258,     0,     0,     0,     0,   259,
     260,     0,     0,     0,     0,     0,     0,     0,     0,   261,
     262,   263,     0,     0,     0,   264,   265,   266,     0,     0,
       0,     0,     0,     0,     0,     0,   267,    25,     0,   268,
       0,     0,     0,     0,     0,   269,     0,     0,   270,     0,
       0,   271,     0,   272,     0,     0,     0,     0,     0,     0,
      42,     0,     0,     0,   273,   274,   275,     0,     0,   276,
       0,     0,     0,     0,     0,     0,     0,     0,   277,     0,
      58,    59,     0,   278,     0,   279,     0,     0,   280,     0,
       0,     0,     0,     0,    69,    70,    71,    72,    73,     0,
      75,    76,    77,    78,    79,    80,    81,     0,     0,     0,
      85,     0,     0,     0,    89,   611,   612,   613,   614,   615,
     616,   617,   618,   619,   620,   621,   622,   623,   731,   625,
     626,   627,   628,     0,     0,     0,     0,   629,     0,   281,
       0,     0,     0,     0,  1267,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   282,     0,     0,
       0,   283,   284,     0,     0,     0,     0,   285,   286,   287,
       0,   288,   289,   290,     0,     0,     0,   123,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   291,   292,     0,     0,     0,     0,
       0,   293,     0,     0,     0,     0,   294,   219,     6,     0,
     295,     0,     0,   296,   220,   221,   222,     0,     0,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   255,   256,   257,   258,     0,     0,     0,
       0,   259,   260,     0,     0,     0,     0,     0,     0,     0,
       0,   261,   262,   263,     0,     0,     0,   264,   265,   266,
       0,     0,     0,     0,     0,     0,     0,     0,   267,    25,
       0,   268,     0,     0,     0,     0,     0,   269,     0,     0,
     270,     0,     0,   271,     0,   272,     0,     0,     0,     0,
       0,     0,    42,     0,     0,     0,   273,   274,   275,     0,
       0,   276,     0,     0,     0,     0,     0,     0,     0,     0,
     277,     0,    58,    59,     0,   278,     0,   279,     0,     0,
     280,     0,     0,     0,     0,     0,    69,    70,    71,    72,
      73,     0,    75,    76,    77,    78,    79,    80,    81,     0,
       0,     0,    85,     0,     0,     0,    89,   611,   612,   613,
     614,   615,   616,   617,   618,   619,   620,   621,   622,   623,
     731,   625,   626,   627,   628,     0,     0,     0,     0,   629,
       0,   281,     0,     0,     0,     0,  1268,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   282,
       0,     0,     0,   283,   284,     0,     0,     0,     0,   285,
     286,   287,     0,   288,   289,   290,     0,     0,     0,   123,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   291,   292,     0,     0,
       0,     0,     0,   293,     0,     0,     0,     0,   377,   219,
       6,     0,   295,     0,     0,   296,   220,   221,   222,     0,
       0,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   255,   256,   257,   258,     0,
       0,     0,     0,   259,   260,     0,     0,     0,     0,     0,
       0,     0,     0,   261,   262,   263,     0,     0,     0,   264,
     265,   266,     0,     0,     0,     0,     0,     0,     0,     0,
     267,    25,     0,   268,     0,     0,     0,     0,     0,   269,
       0,     0,   270,     0,     0,   271,     0,   272,     0,     0,
       0,     0,     0,     0,    42,     0,     0,     0,   273,   274,
     275,     0,     0,   276,     0,     0,     0,     0,     0,     0,
       0,     0,   277,     0,    58,    59,     0,   278,     0,   279,
       0,     0,   280,     0,     0,     0,     0,     0,    69,    70,
      71,    72,    73,     0,    75,    76,    77,    78,    79,    80,
      81,     0,     0,     0,    85,     0,     0,     0,    89,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   621,
     622,   623,   731,   625,   626,   627,   628,     0,     0,     0,
       0,   629,     0,   281,     0,     0,     0,     0,  1618,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   282,     0,     0,     0,   283,   284,     0,     0,     0,
       0,   285,   286,   287,     0,   288,   289,   290,     0,     0,
       0,   123,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   291,   526,
       0,     0,     0,     0,     0,   293,     0,     0,     0,     0,
     377,   219,     6,     0,   598,     0,     0,   296,   220,   221,
     222,     0,     0,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   255,   256,   257,
     258,     0,     0,     0,     0,   259,   260,     0,     0,     0,
       0,     0,     0,     0,     0,   261,   262,   263,     0,     0,
       0,   264,   265,   266,     0,     0,     0,     0,     0,     0,
       0,     0,   267,    25,     0,   268,     0,     0,     0,     0,
       0,   269,     0,     0,   270,     0,     0,   271,     0,   272,
       0,     0,     0,     0,     0,     0,    42,     0,     0,     0,
     273,   274,   275,     0,     0,   276,     0,     0,     0,     0,
       0,     0,     0,     0,   277,     0,    58,    59,     0,   278,
       0,   279,     0,     0,   280,     0,     0,     0,     0,     0,
      69,    70,    71,    72,    73,     0,    75,    76,    77,    78,
      79,    80,    81,     0,     0,     0,    85,     0,     0,     0,
      89,   611,   612,   613,   614,   615,   616,   617,   618,   619,
     620,   621,   622,   623,   731,   625,   626,   627,   628,     0,
       0,     0,     0,   629,     0,   281,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   282,     0,     0,     0,   283,   284,     0,
       0,     0,     0,   285,   286,   287,     0,   288,   289,   290,
       0,     0,     0,   123,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     291,   526,     0,     0,     0,     0,     0,   293,     0,     0,
       0,     0,   377,   219,     6,     0,     0,   603,     0,   296,
     220,   221,   222,     0,     0,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   255,
     256,   257,   258,     0,     0,     0,     0,   259,   260,     0,
       0,     0,     0,     0,     0,     0,     0,   261,   262,   263,
       0,     0,     0,   264,   265,   266,     0,     0,     0,     0,
       0,     0,     0,     0,   267,    25,     0,   268,     0,     0,
       0,     0,     0,   269,     0,     0,   270,     0,     0,   271,
       0,   272,     0,     0,     0,     0,     0,     0,    42,     0,
       0,     0,   273,   274,   275,     0,     0,   276,     0,     0,
       0,     0,     0,     0,     0,     0,   277,     0,    58,    59,
       0,   278,     0,   279,     0,     0,   280,     0,     0,     0,
       0,     0,    69,    70,    71,    72,    73,     0,    75,    76,
      77,    78,    79,    80,    81,     0,     0,     0,    85,     0,
       0,     0,    89,     0,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   621,   622,   623,   731,   625,   626,
     627,   628,     0,     0,     0,     0,   629,   281,  1043,     0,
       0,     0,     0,     0,     0,     0,  1003,     0,     0,     0,
       0,     0,     0,     0,     0,   282,     0,     0,     0,   283,
     284,     0,     0,     0,     0,   285,   286,   287,     0,   288,
     289,   290,     0,     0,     0,   123,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   291,   292,     0,     0,     0,     0,     0,   293,
       0,     0,     0,     0,   641,   219,     6,     0,   295,     0,
       0,   296,   220,   221,   222,     0,     0,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   255,   256,   257,   258,     0,     0,     0,     0,   259,
     260,     0,     0,     0,     0,     0,     0,     0,     0,   261,
     262,   263,     0,     0,     0,   264,   265,   266,     0,     0,
       0,     0,     0,     0,     0,     0,   267,    25,     0,   268,
       0,     0,     0,     0,     0,   269,     0,     0,   270,     0,
       0,   271,     0,   272,     0,     0,     0,     0,     0,     0,
      42,     0,     0,     0,   273,   274,   275,     0,     0,   276,
       0,     0,     0,     0,     0,     0,     0,     0,   277,     0,
      58,    59,     0,   278,     0,   279,     0,     0,   280,     0,
       0,     0,     0,     0,    69,    70,    71,    72,    73,     0,
      75,    76,    77,    78,    79,    80,    81,     0,     0,     0,
      85,     0,     0,     0,    89,   611,   612,   613,   614,   615,
     616,   617,   618,   619,   620,   621,   622,   623,   731,   625,
     626,   627,   628,     0,     0,     0,     0,   629,     0,   281,
       0,     0,     0,  1904,     0,     0,     0,  1905,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   282,     0,     0,
       0,   283,   284,     0,     0,     0,     0,   285,   286,   287,
       0,   288,   289,   290,     0,     0,     0,   123,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   291,   292,     0,     0,     0,     0,
       0,   293,     0,     0,     0,     0,   650,   219,     6,     0,
     295,     0,     0,   296,   220,   221,   222,     0,     0,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   255,   256,   257,   258,     0,     0,     0,
       0,   259,   260,     0,     0,     0,     0,     0,     0,     0,
       0,   261,   262,   263,     0,     0,     0,   264,   265,   266,
       0,     0,     0,     0,     0,     0,     0,     0,   267,    25,
       0,   268,     0,     0,     0,     0,     0,   269,     0,     0,
     270,     0,     0,   271,     0,   272,     0,     0,     0,     0,
       0,     0,    42,     0,     0,     0,   273,   274,   275,     0,
       0,   276,     0,     0,     0,     0,     0,     0,     0,     0,
     277,     0,    58,    59,     0,   278,     0,   279,     0,     0,
     280,     0,     0,     0,     0,     0,    69,    70,    71,    72,
      73,     0,    75,    76,    77,    78,    79,    80,    81,     0,
       0,     0,    85,     0,     0,     0,    89,   611,   612,   613,
     614,   615,   616,   617,   618,   619,   620,   621,   622,   623,
     731,   625,   626,   627,   628,     0,     0,     0,     0,   629,
       0,   281,     0,     0,     0,  1960,     0,     0,     0,  1961,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   282,
       0,     0,     0,   283,   284,     0,     0,     0,     0,   285,
     286,   287,     0,   288,   289,   290,     0,     0,     0,   123,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   291,   526,     0,     0,
       0,     0,     0,   293,     0,     0,     0,     0,   377,   219,
       6,     0,   962,     0,  1452,   296,   220,   221,   222,     0,
       0,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   255,   256,   257,   258,     0,
       0,     0,     0,   259,   260,     0,     0,     0,     0,     0,
       0,     0,     0,   261,   262,   263,     0,     0,     0,   264,
     265,   266,     0,     0,     0,     0,     0,     0,     0,     0,
     267,    25,     0,   268,     0,     0,     0,     0,     0,   269,
       0,     0,   270,     0,     0,   271,     0,   272,     0,     0,
       0,     0,     0,     0,    42,     0,     0,     0,   273,   274,
     275,     0,     0,   276,     0,     0,     0,     0,     0,     0,
       0,     0,   277,     0,    58,    59,     0,   278,     0,   279,
       0,     0,   280,     0,     0,     0,     0,     0,    69,    70,
      71,    72,    73,     0,    75,    76,    77,    78,    79,    80,
      81,     0,     0,     0,    85,     0,     0,     0,    89,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   621,
     622,   623,   731,   625,   626,   627,   628,     0,     0,     0,
       0,   629,     0,   281,     0,     0,     0,  1991,     0,     0,
       0,  1992,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   282,     0,     0,     0,   283,   284,     0,     0,     0,
       0,   285,   286,   287,     0,   288,   289,   290,     0,     0,
       0,   123,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   291,   526,
       0,     0,     0,     0,     0,   293,   219,     6,     0,     0,
     377,  1679,     0,   220,   221,   222,     0,   296,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   255,   256,   257,   258,     0,     0,     0,     0,
     259,   260,     0,     0,     0,     0,     0,     0,     0,     0,
     261,   262,   263,     0,     0,     0,   264,   265,   266,     0,
       0,     0,     0,     0,     0,     0,     0,   267,    25,     0,
     268,     0,     0,     0,     0,     0,   269,     0,     0,   270,
       0,     0,   271,     0,   272,     0,     0,     0,     0,     0,
       0,    42,     0,     0,     0,   273,   274,   275,     0,     0,
     276,     0,     0,     0,     0,     0,     0,     0,     0,   277,
       0,    58,    59,     0,   278,     0,   279,     0,     0,   280,
       0,     0,     0,     0,     0,    69,    70,    71,    72,    73,
       0,    75,    76,    77,    78,    79,    80,    81,     0,     0,
       0,    85,     0,     0,     0,    89,   611,   612,   613,   614,
     615,   616,   617,   618,   619,   620,   621,   622,   623,   731,
     625,   626,   627,   628,     0,     0,     0,     0,   629,     0,
     281,     0,     0,     0,  2178,     0,     0,     0,  2179,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   282,     0,
       0,     0,   283,   284,     0,     0,     0,     0,   285,   286,
     287,     0,   288,   289,   290,     0,     0,     0,   123,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   291,   526,     0,     0,     0,
       0,     0,   293,   219,     6,     0,     0,   377,     0,     0,
     220,   221,   222,     0,   296,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   255,
     256,   257,   258,     0,     0,     0,     0,   259,   260,     0,
       0,     0,     0,     0,     0,     0,     0,   261,   262,   263,
       0,     0,     0,   264,   265,   266,     0,     0,     0,     0,
       0,     0,     0,     0,   267,    25,     0,   268,     0,     0,
       0,     0,     0,   269,     0,     0,   270,     0,     0,   271,
       0,   272,     0,     0,     0,     0,     0,     0,    42,     0,
       0,     0,   273,   274,   275,     0,     0,   276,     0,     0,
       0,     0,     0,     0,     0,     0,   277,     0,    58,    59,
       0,   278,     0,   279,     0,     0,   280,     0,     0,     0,
       0,     0,    69,    70,    71,    72,    73,     0,    75,    76,
      77,    78,    79,    80,    81,     0,     0,     0,    85,     0,
       0,     0,    89,   611,   612,   613,   614,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   731,   625,   626,   627,
     628,     0,     0,     0,     0,   629,     0,   281,     0,     0,
       0,     0,     0,     0,     0,   825,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   282,     0,     0,     0,   283,
     284,     0,     0,     0,     0,   285,   286,   287,     0,   288,
     289,   290,     0,     0,     0,   123,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   291,   292,     0,     0,     0,     0,     0,   293,
       0,     0,     0,     0,   377,   219,     6,     0,  1816,     0,
       0,   296,   220,   221,   222,     0,     0,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   255,   256,   257,   258,     0,     0,     0,     0,   259,
     260,     0,     0,     0,     0,     0,     0,     0,     0,   261,
     262,   263,     0,     0,     0,   264,   265,   266,     0,     0,
       0,     0,     0,     0,     0,     0,   267,    25,     0,   268,
       0,     0,     0,     0,     0,   269,     0,     0,   270,     0,
       0,   271,     0,   272,     0,     0,     0,     0,     0,     0,
      42,     0,     0,     0,   273,   274,   275,     0,     0,   276,
       0,     0,     0,     0,     0,     0,     0,     0,   277,     0,
      58,    59,     0,   278,     0,   279,     0,     0,   280,     0,
       0,     0,     0,     0,    69,    70,    71,    72,    73,     0,
      75,    76,    77,    78,    79,    80,    81,     0,     0,     0,
      85,     0,     0,     0,    89,   611,   612,   613,   614,   615,
     616,   617,   618,   619,   620,   621,   622,   623,   731,   625,
     626,   627,   628,     0,     0,     0,     0,   629,     0,   281,
       0,     0,     0,     0,     0,     0,     0,   831,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   282,     0,     0,
       0,   283,   284,     0,     0,     0,     0,   285,   286,   287,
       0,   288,   289,   290,     0,     0,     0,   123,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   671,  1979,     0,     0,     0,     0,
       0,   293,     0,     0,     0,     0,   673,   219,     6,     0,
     339,     0,     0,   296,   220,   221,   222,     0,     0,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   255,   256,   257,   258,     0,     0,     0,
       0,   259,   260,     0,     0,     0,     0,     0,     0,     0,
       0,   261,   262,   263,     0,     0,     0,   264,   265,   266,
       0,     0,     0,     0,     0,     0,     0,     0,   267,    25,
       0,   268,     0,     0,     0,     0,     0,   269,     0,     0,
     270,     0,     0,   271,     0,   272,     0,     0,     0,     0,
       0,     0,    42,     0,     0,     0,   273,   274,   275,     0,
       0,   276,     0,     0,     0,     0,     0,     0,     0,     0,
     277,     0,    58,    59,     0,   278,     0,   279,     0,     0,
     280,     0,     0,     0,     0,     0,    69,    70,    71,    72,
      73,     0,    75,    76,    77,    78,    79,    80,    81,     0,
       0,     0,    85,     0,     0,     0,    89,   611,   612,   613,
     614,   615,   616,   617,   618,   619,   620,   621,   622,   623,
     731,   625,   626,   627,   628,     0,     0,     0,     0,   629,
       0,   281,     0,     0,     0,     0,     0,     0,     0,   833,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   282,
       0,     0,     0,   283,   284,     0,     0,     0,     0,   285,
     286,   287,     0,   288,   289,   290,     0,     0,     0,   123,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   291,   526,     0,     0,
       0,     0,     0,   293,     0,     0,     0,     0,   377,   219,
       6,     0,     0,  2111,     0,   296,   220,   221,   222,     0,
       0,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   255,   256,   257,   258,     0,
       0,     0,     0,   259,   260,     0,     0,     0,     0,     0,
       0,     0,     0,   261,   262,   263,     0,     0,     0,   264,
     265,   266,     0,     0,     0,     0,     0,     0,     0,     0,
     267,    25,     0,   268,     0,     0,     0,     0,     0,   269,
       0,     0,   270,     0,     0,   271,     0,   272,     0,     0,
       0,     0,     0,     0,    42,     0,     0,     0,   273,   274,
     275,     0,     0,   276,     0,     0,     0,     0,     0,     0,
       0,     0,   277,     0,    58,    59,     0,   278,     0,   279,
       0,     0,   280,     0,     0,     0,     0,     0,    69,    70,
      71,    72,    73,     0,    75,    76,    77,    78,    79,    80,
      81,     0,     0,     0,    85,     0,     0,     0,    89,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   621,
     622,   623,   731,   625,   626,   627,   628,     0,     0,     0,
       0,   629,     0,   281,     0,     0,     0,     0,     0,     0,
       0,  1003,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   282,     0,     0,     0,   283,   284,     0,     0,     0,
       0,   285,   286,   287,     0,   288,   289,   290,     0,     0,
       0,   123,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   291,   526,
       0,     0,     0,     0,     0,   293,   219,   174,   407,     0,
     377,     0,     0,   220,   221,   222,     0,   296,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   401,   242,   243,   244,
     245,   246,   247,   248,   249,     0,     0,     0,     0,     0,
       0,     0,     0,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   255,   256,   257,   258,   417,   418,   419,   420,
     259,     0,     0,     0,   421,   422,   423,   424,     0,     0,
       0,     0,     0,   425,     0,   426,   264,   265,   266,     0,
       0,     0,     0,     0,     0,     0,     0,   267,    25,   427,
     268,     0,   428,   219,   174,   407,     0,     0,     0,     0,
     220,   221,   222,     0,     0,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   401,   242,   243,   244,   245,   246,   247,
     248,   249,     0,     0,     0,     0,     0,     0,     0,     0,
    1702,   409,   410,   411,   412,   413,   414,   415,   416,   255,
     256,   257,   258,   417,   418,   419,   420,   259,     0,     0,
       0,   421,   422,   423,   424,     0,     0,     0,     0,     0,
     425,     0,   426,   264,   265,   266,     0,     0,     0,     0,
       0,     0,     0,     0,   267,    25,   427,   268,     0,   428,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   282,   429,
     430,   431,   283,     0,     0,     0,     0,     0,   285,   286,
     287,   432,   288,   289,   290,   433,     0,   434,   123,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   291,  1996,     0,     0,     0,
       0,     0,   293,     0,     0,     0,     0,   377,     0,     0,
       0,  1997,     0,     0,   296,   611,   612,   613,   614,   615,
     616,   617,   618,   619,   620,   621,   622,   623,   731,   625,
     626,   627,   628,     0,     0,     0,     0,   629,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1004,     0,     0,
       0,     0,     0,     0,     0,   282,   429,   430,   431,   283,
       0,     0,     0,     0,     0,   285,   286,   287,   432,   288,
     289,   290,   433,     0,   434,   123,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   291,   402,     0,     0,     0,     0,     0,   293,
       0,     0,     0,     0,   377,   219,   174,   407,  1874,     0,
       0,   296,   220,   221,   222,     0,     0,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   401,   242,   243,   244,   245,
     246,   247,   248,   249,     0,     0,     0,     0,     0,     0,
       0,     0,   408,   409,   410,   411,   412,   413,   414,   415,
     416,   255,   256,   257,   258,   417,   418,   419,   420,   259,
       0,     0,     0,   421,   422,   423,   424,     0,     0,     0,
       0,     0,   425,     0,   426,   264,   265,   266,     0,     0,
       0,     0,     0,     0,     0,     0,   267,    25,   427,   268,
       0,   428,   219,   174,     0,   400,     0,     0,     0,   220,
     221,   222,     0,     0,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   401,   242,   243,   244,   245,   246,   247,   248,
     249,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   255,   256,
     257,   258,     0,     0,     0,     0,   259,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   264,   265,   266,     0,     0,     0,     0,     0,
       0,     0,     0,   267,    25,     0,   268,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   282,   429,   430,
     431,   283,     0,     0,     0,     0,     0,   285,   286,   287,
     432,   288,   289,   290,   433,     0,   434,   123,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   291,   402,     0,     0,     0,     0,
       0,   293,     0,   219,   174,     0,   377,     0,     0,     0,
     220,   221,   222,   296,     0,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   401,   242,   243,   244,   245,   246,   247,
     248,   249,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   282,     0,     0,     0,   283,   255,
     256,   257,   258,     0,   285,   286,   287,   259,   288,   289,
     290,     0,     0,     0,   123,     0,     0,     0,     0,     0,
       0,     0,     0,   264,   265,   266,     0,     0,     0,     0,
       0,   291,   402,     0,   267,    25,     0,   268,   293,   219,
     174,     0,     0,   377,     0,     0,   220,   221,   222,     0,
     296,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   401,
     242,   243,   244,   245,   246,   247,   248,   249,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     7,
       8,     0,     0,     0,     0,   255,   256,   257,   258,     0,
       0,     0,     0,   259,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   264,
     265,   266,     0,     0,     0,     0,     0,     0,     0,     0,
     267,    25,     0,   268,     0,     0,   611,   612,   613,   614,
     615,   616,   617,   618,   619,   620,   621,   622,   623,   731,
     625,   626,   627,   628,     0,   282,     0,     0,   629,   283,
       0,     0,     0,     0,     0,   285,   286,   287,  1056,   288,
     289,   290,     0,     0,     0,   123,     0,     0,     0,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,   291,   402,     0,    43,    44,    45,    46,   293,
       0,     0,     0,    48,   377,     0,     0,     0,   653,     0,
       0,   296,   806,    57,     0,     0,    60,   807,     0,   808,
     809,     0,   810,   611,   612,   613,   614,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   731,   625,   626,   627,
     628,    82,     0,     0,     0,   629,     0,     0,     0,     0,
     768,   282,     0,     0,     0,   283,     0,     0,     0,     0,
       0,   285,   286,   287,     0,   288,   289,   290,    99,   100,
     101,   123,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   671,   672,
       0,     0,     0,     0,     0,   293,     0,     0,     0,     0,
     673,   219,   174,     0,   339,     0,   924,   296,   220,   221,
     222,     0,     0,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   401,   242,   243,   244,   245,   246,   247,   248,   249,
       0,     0,     0,     0,     0,  1092,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   255,   256,   257,
     258,     0,     0,     0,     0,   259,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   264,   265,   266,     0,     0,     0,     0,     0,   219,
     174,     0,   267,    25,     0,   268,   220,   221,   222,     0,
       0,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   401,
     242,   243,   244,   245,   246,   247,   248,   249,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   255,   256,   257,   258,     0,
       0,     0,     0,   259,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   264,
     265,   266,     0,     0,     0,     0,     0,     0,     0,     0,
     267,    25,     0,   268,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   621,   622,   623,   731,   625,   626,
     627,   628,     0,     0,     0,     0,   629,     0,     0,     0,
       0,     0,     0,   282,     0,     0,  1166,   283,     0,     0,
       0,     0,     0,   285,   286,   287,     0,   288,   289,   290,
       0,     0,     0,   123,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     291,   402,     0,     0,     0,     0,     0,   293,     0,     0,
       0,     0,   377,     0,     0,     0,     0,     0,     0,   296,
     611,   612,   613,   614,   615,   616,   617,   618,   619,   620,
     621,   622,   623,   731,   625,   626,   627,   628,     0,     0,
       0,     0,   629,     0,     0,     0,     0,     0,     0,     0,
       0,   282,  1207,     0,     0,   283,     0,     0,     0,     0,
       0,   285,   286,   287,     0,   288,   289,   290,     0,     0,
       0,   123,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   291,   402,
       0,     0,     0,     0,     0,   293,   219,   174,     0,  1403,
     377,  1154,     0,   220,   221,   222,     0,   296,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   401,   242,   243,   244,
     245,   246,   247,   248,   249,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   255,   256,   257,   258,     0,     0,     0,     0,
     259,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   264,   265,   266,     0,
       0,     0,     0,     0,     0,     0,     0,   267,    25,     0,
     268,   219,   174,     0,  1574,     0,     0,     0,   220,   221,
     222,     0,     0,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   401,   242,   243,   244,   245,   246,   247,   248,   249,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   255,   256,   257,
     258,     0,     0,     0,     0,   259,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   264,   265,   266,     0,     0,     0,     0,     0,     0,
       0,     0,   267,    25,     0,   268,     0,     0,     0,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   621,
     622,   623,   731,   625,   626,   627,   628,     0,   282,     0,
       0,   629,   283,     0,     0,     0,     0,     0,   285,   286,
     287,  1217,   288,   289,   290,     0,     0,     0,   123,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   291,   402,     0,     0,     0,
       0,     0,   293,     0,     0,     0,     0,   377,     0,     0,
       0,     0,     0,     0,   296,   611,   612,   613,   614,   615,
     616,   617,   618,   619,   620,   621,   622,   623,   731,   625,
     626,   627,   628,     0,     0,     0,     0,   629,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1218,     0,     0,
       0,     0,     0,   282,     0,     0,     0,   283,     0,     0,
       0,     0,     0,   285,   286,   287,     0,   288,   289,   290,
       0,     0,     0,   123,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     291,   402,     0,     0,     0,     0,     0,   293,   219,   174,
       0,  1641,   377,     0,     0,   220,   221,   222,     0,   296,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   401,   242,
     243,   244,   245,   246,   247,   248,   249,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   255,   256,   257,   258,     0,     0,
       0,     0,   259,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   264,   265,
     266,     0,     0,     0,     0,     0,   219,   174,     0,   267,
      25,     0,   268,   220,   221,   222,     0,     0,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   401,   242,   243,   244,
     245,   246,   247,   248,   249,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   255,   256,   257,   258,     0,     0,     0,     0,
     259,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   264,   265,   266,     0,
       0,     0,     0,     0,     0,     0,     0,   267,    25,     0,
     268,   611,   612,   613,   614,   615,   616,   617,   618,   619,
     620,   621,   622,   623,   731,   625,   626,   627,   628,     0,
       0,     0,     0,   629,     0,     0,     0,     0,     0,     0,
     282,     0,     0,  1219,   283,     0,     0,     0,     0,     0,
     285,   286,   287,     0,   288,   289,   290,     0,     0,     0,
     123,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   291,   402,     0,
       0,     0,     0,     0,   293,     0,     0,     0,     0,   377,
       0,     0,     0,     0,     0,     0,   296,   611,   612,   613,
     614,   615,   616,   617,   618,   619,   620,   621,   622,   623,
     731,   625,   626,   627,   628,     0,     0,     0,     0,   629,
       0,     0,     0,     0,     0,     0,     0,     0,   282,  1220,
       0,     0,   283,     0,     0,     0,     0,     0,   285,   286,
     287,     0,   288,   289,   290,     0,     0,     0,   123,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   291,   402,     0,     0,     0,
       0,     0,   293,   219,   174,     0,     0,   377,  1695,     0,
     220,   221,   222,     0,   296,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   401,   242,   243,   244,   245,   246,   247,
     248,   249,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   255,
     256,   257,   258,     0,     0,     0,     0,   259,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   264,   265,   266,     0,     0,     0,     0,
       0,   219,   174,     0,   267,    25,     0,   268,   220,   221,
     222,     0,     0,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   401,   242,   243,   244,   245,   246,   247,   248,   249,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   255,   256,   257,
     258,     0,     0,     0,     0,   259,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   264,   265,   266,     0,     0,     0,     0,     0,     0,
       0,     0,   267,    25,     0,   268,   611,   612,   613,   614,
     615,   616,   617,   618,   619,   620,   621,   622,   623,   731,
     625,   626,   627,   628,     0,     0,     0,     0,   629,     0,
       0,     0,     0,     0,     0,   282,     0,     0,  1221,   283,
       0,     0,     0,     0,     0,   285,   286,   287,     0,   288,
     289,   290,     0,     0,     0,   123,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   291,   402,     0,     0,     0,     0,     0,   293,
       0,     0,     0,     0,   377,  2045,     0,     0,     0,     0,
       0,   296,   611,   612,   613,   614,   615,   616,   617,   618,
     619,   620,   621,   622,   623,   731,   625,   626,   627,   628,
       0,     0,     0,     0,   629,     0,     0,     0,     0,     0,
       0,     0,     0,   282,  1226,     0,     0,   283,     0,     0,
       0,     0,     0,   285,   286,   287,     0,   288,   289,   290,
       0,     0,     0,   123,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     291,   402,     0,     0,     0,     0,     0,   293,     0,     0,
       0,     0,   377,   219,   174,     0,  2110,     0,     0,   296,
     220,   221,   222,     0,     0,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   401,   242,   243,   244,   245,   246,   247,
     248,   249,     7,     8,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   255,
     256,   257,   258,     0,     0,     0,     0,   259,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   264,   265,   266,     0,     0,     0,     0,
       0,     0,     0,     0,   267,    25,     0,   268,   611,   612,
     613,   614,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   731,   625,   626,   627,   628,     0,     0,     0,     0,
     629,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1227,     0,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,     0,     0,     0,    43,    44,
      45,    46,     0,     0,     0,     0,    48,     0,     0,     0,
       0,     0,     0,     0,     0,   806,    57,     0,     0,    60,
     807,     0,   808,   809,     0,   810,     0,     0,     0,     0,
       0,     0,     7,     8,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    82,     0,   611,   612,   613,   614,
     615,   616,   617,   618,   619,   620,   621,   622,   623,   731,
     625,   626,   627,   628,     0,   282,     0,     0,   629,   283,
       0,    99,   100,   101,     0,   285,   286,   287,  1229,   288,
     289,   290,     0,     0,     0,   123,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     7,     8,     0,     0,     0,
       0,     0,   291,   402,     0,     0,     0,     0,     0,   293,
       0,     0,     0,     0,   377,     0,     0,     0,     0,     0,
       0,   296,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,     0,     0,     0,    43,    44,
      45,    46,     0,     0,     0,     0,    48,     0,  1094,     0,
       0,     0,     0,     0,     0,   806,    57,     0,     0,    60,
     807,     0,   808,   809,     0,   810,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    82,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,     0,     0,
       0,    43,    44,    45,    46,     7,     8,     0,     0,    48,
       0,    99,   100,   101,     0,     0,     0,     0,   806,    57,
       0,     0,    60,   807,     0,   808,   809,     0,   810,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   621,
     622,   623,   731,   625,   626,   627,   628,    82,     0,     0,
       0,   629,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1353,     0,     0,     0,     0,     0,     0,     7,     8,
       0,     0,     0,     0,    99,   100,   101,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1301,     0,
       0,     0,     0,     0,     0,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,     0,     0,
       0,    43,    44,    45,    46,     0,     0,     0,     0,    48,
       0,     0,     0,     0,     0,     0,     0,     0,   806,    57,
       0,     0,    60,   807,     0,   808,   809,     0,   810,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1303,     0,     0,     0,     0,     0,    82,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,     0,     0,     0,    43,    44,    45,    46,     7,     8,
       0,     0,    48,     0,    99,   100,   101,     0,     0,     0,
       0,   806,    57,     0,     0,    60,   807,     0,   808,   809,
       0,   810,   611,   612,   613,   614,   615,   616,   617,   618,
     619,   620,   621,   622,   623,   731,   625,   626,   627,   628,
      82,     0,     0,     0,   629,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1379,     0,     0,     0,     0,     0,
       0,     7,     8,     0,     0,     0,     0,    99,   100,   101,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1304,     0,     0,     0,     0,     0,     0,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,     0,     0,     0,    43,    44,    45,    46,     0,     0,
       0,     0,    48,     0,     0,     0,     0,     0,     0,     0,
       0,   806,    57,     0,     0,    60,   807,     0,   808,   809,
       0,   810,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1323,     0,     0,     0,     0,     0,
      82,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,     0,     0,     0,    43,    44,    45,
      46,     7,     8,     0,     0,    48,     0,    99,   100,   101,
       0,     0,     0,     0,   806,    57,     0,     0,    60,   807,
       0,   808,   809,     0,   810,   611,   612,   613,   614,   615,
     616,   617,   618,   619,   620,   621,   622,   623,   731,   625,
     626,   627,   628,    82,     0,     0,     0,   629,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1462,     0,     0,
       0,     0,     0,     0,     7,     8,     0,     0,     0,     0,
      99,   100,   101,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1343,     0,     0,     0,     0,     0,
       0,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,     0,     0,     0,    43,    44,    45,
      46,     0,     0,     0,     0,    48,     0,     0,     0,     0,
       0,     0,     0,     0,   806,    57,     0,     0,    60,   807,
       0,   808,   809,     0,   810,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1361,     0,     0,
       0,     0,     0,    82,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,     0,     0,     0,
      43,    44,    45,    46,     7,     8,     0,     0,    48,     0,
      99,   100,   101,     0,     0,     0,     0,   806,    57,     0,
       0,    60,   807,     0,   808,   809,     0,   810,   611,   612,
     613,   614,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   731,   625,   626,   627,   628,    82,     0,     0,     0,
     629,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1466,     0,     0,     0,     0,     0,     0,     7,     8,     0,
       0,     0,     0,    99,   100,   101,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1398,     0,     0,
       0,     0,     0,     0,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,     0,     0,     0,
      43,    44,    45,    46,     0,     0,     0,     0,    48,     0,
       0,     0,     0,     0,     0,     0,     0,   806,    57,     0,
       0,    60,   807,     0,   808,   809,     0,   810,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1566,     0,     0,     0,     0,     0,    82,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
       0,     0,     0,    43,    44,    45,    46,     0,     0,     0,
       0,    48,     0,    99,   100,   101,     0,     0,     0,     0,
     806,    57,     0,     0,    60,   807,     0,   808,   809,     0,
     810,     0,     0,     0,     0,     0,     0,    -4,     1,     0,
       0,    -4,     0,     0,     0,     0,     0,     0,     0,    82,
      -4,    -4,     0,     0,     0,     0,     0,   611,   612,   613,
     614,   615,   616,   617,   618,   619,   620,   621,   622,   623,
     731,   625,   626,   627,   628,     0,    99,   100,   101,   629,
       0,     0,     0,     0,    -4,    -4,    -4,     0,     0,  1568,
    2241,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    -4,    -4,    -4,     0,     0,
       0,     0,    -4,    -4,     0,     0,     0,     0,    -4,     0,
       0,     0,     0,    -4,    -4,    -4,    -4,    -4,     0,    -4,
      -4,     0,    -4,     0,     0,     0,     0,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,  2300,     0,    -4,    -4,    -4,    -4,    -4,
       0,     0,    -4,     0,    -4,     0,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,     0,     0,    -4,    -4,    -4,     0,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,     0,     0,     0,    -4,    -4,    -4,
       0,     0,     0,    -4,     0,     0,     0,     0,    -4,    -4,
      -4,    -4,     0,     0,    -4,     0,    -4,     0,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,     0,     6,     0,     0,     0,     0,    -4,    -4,
      -4,    -4,     7,     8,     0,     0,     0,     0,     0,     0,
      -4,     0,    -4,    -4,     0,     0,     0,   611,   612,   613,
     614,   615,   616,   617,   618,   619,   620,   621,   622,   623,
     731,   625,   626,   627,   628,     0,     9,    10,    11,   629,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1569,
       0,     0,     0,     0,     0,     0,     0,    12,    13,    14,
       0,     0,     0,     0,    15,    16,     0,     0,     0,     0,
      17,     0,     0,     0,     0,    18,    19,    20,    21,    22,
       0,    23,    24,     0,    25,     0,     0,     0,     0,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,     0,     0,    42,    43,    44,
      45,    46,     0,     0,    47,     0,    48,     0,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,     0,     0,    66,    67,    68,
       0,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,     0,     0,     0,    94,
      95,    96,     0,     0,     0,    97,     0,     0,     0,     0,
      98,    99,   100,   101,   174,   407,   102,     0,   103,     0,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,     0,     0,     0,     0,     0,     0,
     118,   119,   120,   121,     0,     0,     0,     0,     0,     0,
       0,     0,   122,     0,   123,   124,     0,     0,     0,     0,
     408,   409,   410,   411,   412,   413,   414,   415,   416,     0,
       0,     0,     0,   417,   418,   419,   420,     0,     0,     0,
       0,   421,   422,   423,   424,     0,     0,   174,   407,     0,
     425,     0,   426,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   427,     0,     0,   428,
       0,     0,     0,   180,     0,     0,   181,     0,     0,   182,
       0,   183,     0,     0,   438,   407,     0,     0,     0,     0,
       0,     0,    46,   408,   409,   410,   411,   412,   413,   414,
     415,   416,     0,     0,     0,     0,   417,   418,   419,   420,
       0,     0,     0,   457,   421,   422,   423,   424,     0,     0,
       0,     0,     0,   425,     0,   426,     0,     0,     0,     0,
     408,   409,   410,   411,   412,   413,   414,   415,   416,   427,
       0,     0,   428,   417,   418,   419,   420,     0,     0,     0,
       0,   421,   422,   423,   424,     0,     0,     0,     0,     0,
     425,   407,   426,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   427,     0,     0,   428,
       0,     0,     0,     0,     0,     0,   429,   430,   431,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   432,     0,
       0,     0,   433,     0,   434,   123,   408,   409,   410,   411,
     412,   413,   414,   415,   416,     0,     0,     0,     0,   417,
     418,   419,   420,     0,     0,     7,     8,   421,   422,   423,
     424,     0,     0,     0,     0,     0,   425,     0,   426,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   427,     0,     0,   428,     0,     0,     0,   429,
     430,   431,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   432,     0,     0,     0,   433,     0,   434,   123,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   429,   430,   431,     0,
       0,     7,     8,     0,     0,     0,     0,     0,   432,     0,
       0,     0,   433,     0,   434,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,     0,     0,
       0,    43,    44,    45,    46,     0,     0,     0,     0,    48,
       0,     0,     0,     0,     0,     0,     0,     0,   806,    57,
       0,     0,    60,   807,     0,   808,   809,     0,   810,     0,
       0,     0,  1100,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   429,   430,   431,     0,     0,    82,     0,     0,
       0,  1101,     0,     0,   432,     0,     0,     0,   433,     0,
     434,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    99,   100,   101,    43,    44,    45,
      46,     0,     0,     0,     0,    48,     0,     0,     0,     0,
       0,     0,     0,     0,   806,    57,     0,     0,    60,   807,
       0,   808,   809,     0,   810,   611,   612,   613,   614,   615,
     616,   617,   618,   619,   620,   621,   622,   623,   731,   625,
     626,   627,   628,    82,     0,     0,     0,   629,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1617,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      99,   100,   101,   611,   612,   613,   614,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   731,   625,   626,   627,
     628,     0,     0,     0,     0,   629,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1746,   611,   612,   613,   614,
     615,   616,   617,   618,   619,   620,   621,   622,   623,   731,
     625,   626,   627,   628,     0,     0,     0,     0,   629,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1747,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   621,
     622,   623,   731,   625,   626,   627,   628,     0,     0,     0,
       0,   629,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1748,   611,   612,   613,   614,   615,   616,   617,   618,
     619,   620,   621,   622,   623,   731,   625,   626,   627,   628,
       0,     0,     0,     0,   629,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1902,   611,   612,   613,   614,   615,
     616,   617,   618,   619,   620,   621,   622,   623,   731,   625,
     626,   627,   628,     0,     0,     0,     0,   629,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2032,   611,   612,
     613,   614,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   731,   625,   626,   627,   628,     0,     0,     0,     0,
     629,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2033,   611,   612,   613,   614,   615,   616,   617,   618,   619,
     620,   621,   622,   623,   731,   625,   626,   627,   628,     0,
       0,     0,     0,   629,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2065,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   621,   622,   623,   731,   625,   626,
     627,   628,     0,     0,     0,     0,   629,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2144,   611,   612,   613,
     614,   615,   616,   617,   618,   619,   620,   621,   622,   623,
     731,   625,   626,   627,   628,     0,     0,     0,     0,   629,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2159,
     611,   612,   613,   614,   615,   616,   617,   618,   619,   620,
     621,   622,   623,   731,   625,   626,   627,   628,     0,     0,
       0,     0,   629,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2161,   611,   612,   613,   614,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   731,   625,   626,   627,
     628,     0,     0,     0,     0,   629,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2206,   611,   612,   613,   614,
     615,   616,   617,   618,   619,   620,   621,   622,   623,   731,
     625,   626,   627,   628,     0,     0,     0,     0,   629,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2207,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   621,
     622,   623,   731,   625,   626,   627,   628,     0,     0,     0,
       0,   629,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2222,   611,   612,   613,   614,   615,   616,   617,   618,
     619,   620,   621,   622,   623,   731,   625,   626,   627,   628,
       0,     0,     0,     0,   629,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2259,   611,   612,   613,   614,   615,
     616,   617,   618,   619,   620,   621,   622,   623,   731,   625,
     626,   627,   628,     0,     0,     0,     0,   629,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2288,   611,   612,
     613,   614,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   731,   625,   626,   627,   628,     0,     0,     0,     0,
     629,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2293,   611,   612,   613,   614,   615,   616,   617,   618,   619,
     620,   621,   622,   623,   731,   625,   626,   627,   628,     0,
       0,     0,     0,   629,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2294,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   621,   622,   623,   731,   625,   626,
     627,   628,     0,     0,     0,     0,   629,     0,     0,     0,
       0,     0,   865,   611,   612,   613,   614,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   731,   625,   626,   627,
     628,     0,     0,     0,     0,   629,     0,     0,     0,     0,
       0,  1135,   611,   612,   613,   614,   615,   616,   617,   618,
     619,   620,   621,   622,   623,   731,   625,   626,   627,   628,
       0,     0,     0,     0,   629,     0,     0,     0,     0,     0,
    1193,   611,   612,   613,   614,   615,   616,   617,   618,   619,
     620,   621,   622,   623,   731,   625,   626,   627,   628,     0,
       0,     0,     0,   629,     0,     0,     0,     0,     0,  1242,
     611,   612,   613,   614,   615,   616,   617,   618,   619,   620,
     621,   622,   623,   731,   625,   626,   627,   628,     0,     0,
       0,     0,   629,     0,     0,     0,     0,     0,  1243,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   621,
     622,   623,   731,   625,   626,   627,   628,     0,     0,     0,
       0,   629,     0,     0,     0,     0,     0,  1293,   611,   612,
     613,   614,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   731,   625,   626,   627,   628,     0,     0,     0,     0,
     629,     0,     0,     0,     0,     0,  1326,   611,   612,   613,
     614,   615,   616,   617,   618,   619,   620,   621,   622,   623,
     731,   625,   626,   627,   628,     0,     0,     0,     0,   629,
       0,     0,     0,     0,     0,  1341,   611,   612,   613,   614,
     615,   616,   617,   618,   619,   620,   621,   622,   623,   731,
     625,   626,   627,   628,     0,     0,     0,     0,   629,     0,
       0,     0,     0,     0,  1348,   611,   612,   613,   614,   615,
     616,   617,   618,   619,   620,   621,   622,   623,   731,   625,
     626,   627,   628,     0,     0,     0,     0,   629,     0,     0,
       0,     0,     0,  1409,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   621,   622,   623,   731,   625,   626,
     627,   628,     0,     0,     0,     0,   629,     0,     0,     0,
       0,     0,  1429,   611,   612,   613,   614,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   731,   625,   626,   627,
     628,     0,     0,     0,     0,   629,     0,     0,     0,     0,
       0,  1465,   611,   612,   613,   614,   615,   616,   617,   618,
     619,   620,   621,   622,   623,   731,   625,   626,   627,   628,
       0,     0,     0,     0,   629,     0,     0,     0,     0,     0,
    1515,   611,   612,   613,   614,   615,   616,   617,   618,   619,
     620,   621,   622,   623,   731,   625,   626,   627,   628,     0,
       0,     0,     0,   629,     0,     0,     0,     0,     0,  1516,
     611,   612,   613,   614,   615,   616,   617,   618,   619,   620,
     621,   622,   623,   731,   625,   626,   627,   628,     0,     0,
       0,     0,   629,     0,     0,     0,     0,     0,  1517,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   621,
     622,   623,   731,   625,   626,   627,   628,     0,     0,     0,
       0,   629,     0,     0,     0,     0,     0,  1520,   611,   612,
     613,   614,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   731,   625,   626,   627,   628,     0,     0,     0,     0,
     629,     0,     0,     0,     0,     0,  1521,   611,   612,   613,
     614,   615,   616,   617,   618,   619,   620,   621,   622,   623,
     731,   625,   626,   627,   628,     0,     0,     0,     0,   629,
       0,     0,     0,     0,     0,  1522,   611,   612,   613,   614,
     615,   616,   617,   618,   619,   620,   621,   622,   623,   731,
     625,   626,   627,   628,     0,     0,     0,     0,   629,     0,
       0,     0,     0,     0,  1524,   611,   612,   613,   614,   615,
     616,   617,   618,   619,   620,   621,   622,   623,   731,   625,
     626,   627,   628,     0,     0,     0,     0,   629,     0,     0,
       0,     0,     0,  1525,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   621,   622,   623,   731,   625,   626,
     627,   628,     0,     0,     0,     0,   629,     0,     0,     0,
       0,     0,  1570,   611,   612,   613,   614,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   731,   625,   626,   627,
     628,     0,     0,     0,     0,   629,     0,     0,     0,     0,
       0,  1647,   611,   612,   613,   614,   615,   616,   617,   618,
     619,   620,   621,   622,   623,   731,   625,   626,   627,   628,
       0,     0,     0,     0,   629,     0,     0,     0,     0,     0,
    1757,   611,   612,   613,   614,   615,   616,   617,   618,   619,
     620,   621,   622,   623,   731,   625,   626,   627,   628,     0,
       0,     0,     0,   629,     0,     0,     0,     0,     0,  1958,
     611,   612,   613,   614,   615,   616,   617,   618,   619,   620,
     621,   622,   623,   731,   625,   626,   627,   628,     0,     0,
       0,     0,   629,     0,     0,     0,     0,     0,  1969,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   621,
     622,   623,   731,   625,   626,   627,   628,     0,     0,     0,
       0,   629,     0,     0,     0,     0,     0,  2012,   611,   612,
     613,   614,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   731,   625,   626,   627,   628,     0,     0,     0,     0,
     629,     0,     0,     0,     0,     0,  2090,   611,   612,   613,
     614,   615,   616,   617,   618,   619,   620,   621,   622,   623,
     731,   625,   626,   627,   628,     0,     0,     0,     0,   629,
       0,     0,     0,     0,     0,  2106,   611,   612,   613,   614,
     615,   616,   617,   618,   619,   620,   621,   622,   623,   731,
     625,   626,   627,   628,     0,     0,     0,     0,   629,     0,
       0,     0,     0,     0,  2121,   611,   612,   613,   614,   615,
     616,   617,   618,   619,   620,   621,   622,   623,   731,   625,
     626,   627,   628,     0,     0,     0,     0,   629,     0,     0,
       0,     0,     0,  2145,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   621,   622,   623,   731,   625,   626,
     627,   628,     0,     0,     0,     0,   629,     0,     0,     0,
       0,     0,  2160,   611,   612,   613,   614,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   731,   625,   626,   627,
     628,     0,     0,     0,     0,   629,     0,     0,     0,     0,
       0,  2184,   611,   612,   613,   614,   615,   616,   617,   618,
     619,   620,   621,   622,   623,   731,   625,   626,   627,   628,
       0,     0,     0,     0,   629,     0,     0,     0,     0,     0,
    2194,   611,   612,   613,   614,   615,   616,   617,   618,   619,
     620,   621,   622,   623,   731,   625,   626,   627,   628,     0,
       0,     0,     0,   629,     0,     0,     0,     0,     0,  2195,
     611,   612,   613,   614,   615,   616,   617,   618,   619,   620,
     621,   622,   623,   731,   625,   626,   627,   628,     0,     0,
       0,     0,   629,     0,     0,     0,     0,     0,  2220,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   621,
     622,   623,   731,   625,   626,   627,   628,     0,     0,     0,
       0,   629,     0,     0,     0,     0,     0,  2225,   611,   612,
     613,   614,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   731,   625,   626,   627,   628,     0,     0,     0,     0,
     629,     0,     0,     0,     0,     0,  2265,   611,   612,   613,
     614,   615,   616,   617,   618,   619,   620,   621,   622,   623,
     731,   625,   626,   627,   628,     0,     0,     0,     0,   629,
       0,     0,     0,     0,     0,  2266,   611,   612,   613,   614,
     615,   616,   617,   618,   619,   620,   621,   622,   623,   731,
     625,   626,   627,   628,     0,     0,     0,     0,   629,     0,
       0,     0,     0,     0,  2274,   611,   612,   613,   614,   615,
     616,   617,   618,   619,   620,   621,   622,   623,   731,   625,
     626,   627,   628,     0,     0,     0,     0,   629,     0,     0,
       0,     0,     0,  2313,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   621,   622,   623,   731,   625,   626,
     627,   628,     0,     0,     0,     0,   629,     0,     0,     0,
       0,     0,  2331,   611,   612,   613,   614,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   731,   625,   626,   627,
     628,     0,     0,     0,     0,   629,     0,     0,     0,     0,
       0,  2349,   611,   612,   613,   614,   615,   616,   617,   618,
     619,   620,   621,   622,   623,   731,   625,   626,   627,   628,
       0,     0,     0,     0,   629,     0,     0,     0,     0,     0,
    2350,   611,   612,   613,   614,   615,   616,   617,   618,   619,
     620,   621,   622,   623,   731,   625,   626,   627,   628,     0,
       0,     0,     0,   629,     0,     0,     0,     0,   995,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   621,
     622,   623,   731,   625,   626,   627,   628,     0,     0,     0,
       0,   629,     0,     0,     0,     0,  2083,   611,   612,   613,
     614,   615,   616,   617,   618,   619,   620,   621,   622,   623,
     731,   625,   626,   627,   628,     0,     0,     0,     0,   629,
       0,   792,     0,   793,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   621,   622,   623,   731,   625,   626,
     627,   628,     0,     0,     0,     0,   629,     0,     0,     0,
    1066,   611,   612,   613,   614,   615,   616,   617,   618,   619,
     620,   621,   622,   623,   731,   625,   626,   627,   628,     0,
       0,     0,     0,   629,     0,     0,     0,  1111,   611,   612,
     613,   614,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   731,   625,   626,   627,   628,     0,     0,     0,     0,
     629,     0,     0,     0,  1272,   611,   612,   613,   614,   615,
     616,   617,   618,   619,   620,   621,   622,   623,   731,   625,
     626,   627,   628,     0,     0,     0,     0,   629,     0,     0,
       0,  1342,   611,   612,   613,   614,   615,   616,   617,   618,
     619,   620,   621,   622,   623,   731,   625,   626,   627,   628,
       0,     0,     0,     0,   629,     0,     0,     0,  1344,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   621,
     622,   623,   731,   625,   626,   627,   628,     0,     0,     0,
       0,   629,     0,     0,     0,  1351,   611,   612,   613,   614,
     615,   616,   617,   618,   619,   620,   621,   622,   623,   731,
     625,   626,   627,   628,     0,     0,     0,     0,   629,     0,
       0,     0,  1352,   611,   612,   613,   614,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   731,   625,   626,   627,
     628,     0,     0,     0,     0,   629,     0,     0,     0,  1444,
     611,   612,   613,   614,   615,   616,   617,   618,   619,   620,
     621,   622,   623,   731,   625,   626,   627,   628,     0,     0,
       0,     0,   629,     0,     0,     0,  1458,   611,   612,   613,
     614,   615,   616,   617,   618,   619,   620,   621,   622,   623,
     731,   625,   626,   627,   628,     0,     0,     0,     0,   629,
       0,     0,     0,  1676,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   621,   622,   623,   731,   625,   626,
     627,   628,     0,     0,     0,     0,   629,     0,     0,     0,
    1772,   611,   612,   613,   614,   615,   616,   617,   618,   619,
     620,   621,   622,   623,   731,   625,   626,   627,   628,     0,
       0,     0,     0,   629,     0,     0,     0,  1826,   611,   612,
     613,   614,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   731,   625,   626,   627,   628,     0,     0,     0,     0,
     629,     0,     0,     0,  2024,   611,   612,   613,   614,   615,
     616,   617,   618,   619,   620,   621,   622,   623,   731,   625,
     626,   627,   628,     0,     0,     0,     0,   629,     0,     0,
       0,  2073,   611,   612,   613,   614,   615,   616,   617,   618,
     619,   620,   621,   622,   623,   731,   625,   626,   627,   628,
       0,     0,     0,     0,   629,     0,     0,     0,  2091,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   621,
     622,   623,   731,   625,   626,   627,   628,     0,     0,     0,
       0,   629,     0,   846,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   621,   622,   623,   731,   625,   626,
     627,   628,     0,     0,     0,     0,   629,     0,   847,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   621,
     622,   623,   731,   625,   626,   627,   628,     0,     0,     0,
       0,   629,     0,   848,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   621,   622,   623,   731,   625,   626,
     627,   628,     0,     0,     0,     0,   629,     0,   850,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   621,
     622,   623,   731,   625,   626,   627,   628,     0,     0,     0,
       0,   629,     0,   851,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   621,   622,   623,   731,   625,   626,
     627,   628,     0,     0,     0,     0,   629,     0,   852,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   621,
     622,   623,   731,   625,   626,   627,   628,     0,     0,     0,
       0,   629,     0,   854,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   621,   622,   623,   731,   625,   626,
     627,   628,     0,     0,     0,     0,   629,     0,   855,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   621,
     622,   623,   731,   625,   626,   627,   628,     0,     0,     0,
       0,   629,     0,   856,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   621,   622,   623,   731,   625,   626,
     627,   628,     0,     0,     0,     0,   629,     0,   857,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   621,
     622,   623,   731,   625,   626,   627,   628,     0,     0,     0,
       0,   629,     0,   858,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   621,   622,   623,   731,   625,   626,
     627,   628,     0,     0,     0,     0,   629,     0,   859,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   621,
     622,   623,   731,   625,   626,   627,   628,     0,     0,     0,
       0,   629,     0,   860,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   621,   622,   623,   731,   625,   626,
     627,   628,     0,     0,     0,     0,   629,     0,   862,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   621,
     622,   623,   731,   625,   626,   627,   628,     0,     0,     0,
       0,   629,     0,   863,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   621,   622,   623,   731,   625,   626,
     627,   628,     0,     0,     0,     0,   629,     0,   864,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   621,
     622,   623,   731,   625,   626,   627,   628,     0,     0,     0,
       0,   629,     0,   942,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   621,   622,   623,   731,   625,   626,
     627,   628,     0,     0,     0,     0,   629,     0,   976,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   621,
     622,   623,   731,   625,   626,   627,   628,     0,     0,     0,
       0,   629,     0,  1026,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   621,   622,   623,   731,   625,   626,
     627,   628,     0,     0,     0,     0,   629,     0,  1043,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   621,
     622,   623,   731,   625,   626,   627,   628,     0,     0,     0,
       0,   629,     0,  1051,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   621,   622,   623,   731,   625,   626,
     627,   628,     0,     0,     0,     0,   629,     0,  1053,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   621,
     622,   623,   731,   625,   626,   627,   628,     0,     0,     0,
       0,   629,     0,  1054,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   621,   622,   623,   731,   625,   626,
     627,   628,     0,     0,     0,     0,   629,     0,  1060,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   621,
     622,   623,   731,   625,   626,   627,   628,     0,     0,     0,
       0,   629,     0,  1061,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   621,   622,   623,   731,   625,   626,
     627,   628,     0,     0,     0,     0,   629,     0,  1099,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   621,
     622,   623,   731,   625,   626,   627,   628,     0,     0,     0,
       0,   629,     0,  1110,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   621,   622,   623,   731,   625,   626,
     627,   628,     0,     0,     0,     0,   629,     0,  1171,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   621,
     622,   623,   731,   625,   626,   627,   628,     0,     0,     0,
       0,   629,     0,  1175,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   621,   622,   623,   731,   625,   626,
     627,   628,     0,     0,     0,     0,   629,     0,  1187,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   621,
     622,   623,   731,   625,   626,   627,   628,     0,     0,     0,
       0,   629,     0,  1271,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   621,   622,   623,   731,   625,   626,
     627,   628,     0,     0,     0,     0,   629,     0,  1281,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   621,
     622,   623,   731,   625,   626,   627,   628,     0,     0,     0,
       0,   629,     0,  1282,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   621,   622,   623,   731,   625,   626,
     627,   628,     0,     0,     0,     0,   629,     0,  1283,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   621,
     622,   623,   731,   625,   626,   627,   628,     0,     0,     0,
       0,   629,     0,  1292,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   621,   622,   623,   731,   625,   626,
     627,   628,     0,     0,     0,     0,   629,     0,  1294,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   621,
     622,   623,   731,   625,   626,   627,   628,     0,     0,     0,
       0,   629,     0,  1295,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   621,   622,   623,   731,   625,   626,
     627,   628,     0,     0,     0,     0,   629,     0,  1325,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   621,
     622,   623,   731,   625,   626,   627,   628,     0,     0,     0,
       0,   629,     0,  1327,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   621,   622,   623,   731,   625,   626,
     627,   628,     0,     0,     0,     0,   629,     0,  1328,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   621,
     622,   623,   731,   625,   626,   627,   628,     0,     0,     0,
       0,   629,     0,  1329,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   621,   622,   623,   731,   625,   626,
     627,   628,     0,     0,     0,     0,   629,     0,  1330,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   621,
     622,   623,   731,   625,   626,   627,   628,     0,     0,     0,
       0,   629,     0,  1331,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   621,   622,   623,   731,   625,   626,
     627,   628,     0,     0,     0,     0,   629,     0,  1332,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   621,
     622,   623,   731,   625,   626,   627,   628,     0,     0,     0,
       0,   629,     0,  1333,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   621,   622,   623,   731,   625,   626,
     627,   628,     0,     0,     0,     0,   629,     0,  1340,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   621,
     622,   623,   731,   625,   626,   627,   628,     0,     0,     0,
       0,   629,     0,  1354,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   621,   622,   623,   731,   625,   626,
     627,   628,     0,     0,     0,     0,   629,     0,  1356,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   621,
     622,   623,   731,   625,   626,   627,   628,     0,     0,     0,
       0,   629,     0,  1397,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   621,   622,   623,   731,   625,   626,
     627,   628,     0,     0,     0,     0,   629,     0,  1443,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   621,
     622,   623,   731,   625,   626,   627,   628,     0,     0,     0,
       0,   629,     0,  1457,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   621,   622,   623,   731,   625,   626,
     627,   628,     0,     0,     0,     0,   629,     0,  1677,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   621,
     622,   623,   731,   625,   626,   627,   628,     0,     0,     0,
       0,   629,     0,  1713,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   621,   622,   623,   731,   625,   626,
     627,   628,     0,     0,     0,     0,   629,     0,  1759,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   621,
     622,   623,   731,   625,   626,   627,   628,     0,     0,     0,
       0,   629,     0,  1771,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   621,   622,   623,   731,   625,   626,
     627,   628,     0,     0,     0,     0,   629,     0,  1889,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   621,
     622,   623,   731,   625,   626,   627,   628,     0,     0,     0,
       0,   629,     0,  1891,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   621,   622,   623,   731,   625,   626,
     627,   628,     0,     0,     0,     0,   629,     0,  1894,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   621,
     622,   623,   731,   625,   626,   627,   628,     0,     0,     0,
       0,   629,     0,  1901,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   621,   622,   623,   731,   625,   626,
     627,   628,     0,     0,     0,     0,   629,     0,  1959,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   621,
     622,   623,   731,   625,   626,   627,   628,     0,     0,     0,
       0,   629,     0,  1968,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   621,   622,   623,   731,   625,   626,
     627,   628,     0,     0,     0,     0,   629,     0,  1995,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   621,
     622,   623,   731,   625,   626,   627,   628,     0,     0,     0,
       0,   629,     0,  2072,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   621,   622,   623,   731,   625,   626,
     627,   628,     0,     0,     0,     0,   629,     0,  2142,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   621,
     622,   623,   731,   625,   626,   627,   628,     0,     0,     0,
       0,   629,     0,  2143,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   621,   622,   623,   731,   625,   626,
     627,   628,     0,     0,     0,     0,   629,     0,  2287,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   621,
     622,   623,   731,   625,   626,   627,   628,     0,     0,     0,
       0,   629,     0,  2328,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   621,   622,   623,   731,   625,   626,
     627,   628,     0,     0,     0,     0,   629
};

static const yytype_int16 yycheck[] =
{
       3,  1320,  1324,     3,   332,   668,   669,  1529,  1857,     4,
    1859,  1810,   164,    70,    71,   789,    73,   150,     4,    64,
       4,   795,    25,     4,   109,     5,     4,    25,     5,     4,
       4,     4,     4,   109,     5,     4,     4,   147,     4,     6,
       5,     4,  2048,     7,   168,     4,     6,    68,     6,     6,
     109,    26,     6,    56,     6,   147,     6,    26,     6,     6,
       4,     4,    37,    38,     4,   467,     6,     9,    37,    38,
    1846,     6,     0,     7,   166,   252,   253,   136,   109,   103,
      97,   169,   103,    86,     4,   177,   178,   179,     9,    92,
     200,   183,   184,   264,    97,   266,   273,   106,   122,   102,
     109,   110,   111,     4,   147,   136,    26,     9,     9,   197,
     113,    95,   109,   122,   252,   253,     7,    37,    38,   261,
     262,   252,   253,   166,   265,   213,   214,  1926,   270,   270,
       6,   269,     6,  1909,   177,   178,   179,   112,   113,    14,
     183,   184,   273,   112,   113,   252,   253,   150,     8,   252,
     253,   151,   155,   156,   157,     9,   252,   253,     6,   265,
     103,   164,     9,   103,   107,   268,   273,   273,   264,     9,
     113,   114,   268,   116,   117,   252,   253,   269,   109,   264,
     111,   252,   253,   192,   152,   153,   154,   155,   264,   206,
     158,   159,   264,     6,   252,   253,   273,   140,   201,   216,
     168,     7,   273,   206,   172,     7,     6,   210,   211,  2215,
     268,   252,   253,   216,   217,   218,   261,   262,   263,   173,
     344,     6,   197,   198,   208,   185,   269,   265,   197,   198,
     264,   633,   273,   268,   212,   273,   281,   272,     6,   264,
     364,   266,  1764,   187,   188,   189,   190,   267,   273,   235,
     185,   235,   264,   273,   266,   199,   268,   201,   202,   203,
     204,   205,   235,   235,     6,   209,   210,  1586,   212,   235,
       7,   266,   235,   268,   277,   264,     7,   272,   335,   336,
       7,  2080,     6,   264,   268,   271,   343,   344,   268,   292,
     264,   268,   295,   296,     6,   268,   268,   268,   296,   316,
     317,   318,   265,   268,   267,   264,   270,   264,   311,   312,
     268,   268,   315,   316,   317,   318,   268,   441,   268,   443,
     268,   268,   264,   326,   266,   269,   450,   330,   270,   332,
     264,   264,   266,   735,   235,   268,  1110,  1111,   267,  2138,
     357,   358,   359,   264,   273,   266,   237,   238,   239,   240,
     106,   354,   355,   109,   357,   358,   359,   264,   375,   266,
     261,   262,   264,   264,   266,   266,   122,   268,   270,   270,
     261,   262,   375,   247,   248,   378,   252,   253,   270,   270,
     272,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   247,
     248,   803,   264,   263,  2253,   257,   258,   261,   262,   269,
     264,   263,   266,   267,   261,   262,   270,   264,   820,   266,
     572,   261,   262,   270,   264,   264,   266,   266,   830,     4,
     270,   237,   238,   239,   240,   237,   238,   239,   240,   252,
     253,     8,   268,   446,   106,   448,   265,   109,   267,   452,
     453,    26,   252,   253,   273,   261,   262,     6,   265,   261,
     262,   265,    37,    38,   111,   468,   273,   264,   113,   273,
     115,   268,   475,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,  2290,     6,     7,     4,   263,   265,   500,     4,     6,
     237,   238,   239,   240,   273,   150,   237,   238,   239,   240,
     237,   238,   239,   240,   252,   253,    26,   264,   252,   253,
      26,   268,   266,   526,   261,   262,   264,    37,    38,  1192,
     268,    37,    38,   657,   179,   659,   660,   112,   113,   273,
     185,  2340,   944,   252,   253,   265,   264,   267,  2070,   552,
     261,   262,   676,   252,   253,   252,   253,   268,   561,   562,
     266,   252,   253,   566,   273,   568,   569,   570,   571,   572,
     264,   588,   696,   269,   273,   578,   273,   273,   252,   253,
     106,   147,   273,   109,   587,   588,   589,   739,   591,   592,
     593,   594,   264,   596,   268,   598,   594,   265,   596,   723,
     166,   147,   112,   113,   147,   273,   112,   113,   265,   666,
     667,   177,   178,   179,   671,   269,   273,   183,   184,   273,
     166,   624,   265,   166,   252,   253,   265,   630,   267,   268,
     273,   177,   178,   179,   177,   178,   179,   183,   184,   264,
     183,   184,   252,   253,   768,   273,   252,   253,   264,   652,
     653,   103,   252,   253,   106,   264,   789,   109,   265,   111,
     267,   269,   264,   273,   266,   273,   273,   273,   668,   669,
     122,  1334,  1335,   273,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   252,   253,   252,   253,   263,   252,   253,   702,
     703,   704,   269,   269,   252,   253,   270,   710,   265,   273,
    1112,   252,   253,   273,   103,   273,   273,   106,   273,   264,
     109,   268,   264,   269,   266,   273,   261,   262,   270,   732,
     264,   273,   273,   122,   737,   738,   739,   740,   741,   742,
     743,   744,   745,   264,   747,   748,   749,   750,   751,   264,
     753,   754,   755,   756,   757,     3,   264,   760,   756,   252,
     253,   252,   253,   265,   809,   267,   265,   106,   267,   264,
     109,   273,   111,   106,   273,   778,   109,   264,   111,    27,
     273,  1555,   273,   122,   252,   253,   254,   255,   256,   257,
     258,   794,   269,   252,   253,   263,   273,   800,   254,   255,
     256,   257,   258,   126,   265,   269,   267,   263,     4,   273,
       6,   456,   273,   816,   817,    63,   152,   153,   264,   822,
     264,   824,   158,     6,   827,   828,   109,   261,   262,     8,
     264,     6,   266,   836,   268,   838,   152,   153,   261,   262,
     973,   264,   158,   266,   261,   262,   268,   264,   269,   266,
     269,   109,   273,  1255,   273,  1257,   269,   269,   269,   269,
     273,   273,   273,   273,   268,   868,   264,   870,  1270,   269,
     118,   264,   269,   273,   268,   999,   273,   269,  1652,   269,
     268,   273,   269,   273,   264,   269,   273,    56,  1662,   273,
     269,   269,   269,   269,   273,   273,   273,   273,  1300,   269,
     106,   269,   150,   273,   907,   273,   269,   155,   156,   157,
     273,   269,   264,   269,   917,   273,   164,   273,   269,   269,
    2242,   269,   273,   273,   269,   273,   269,   269,   273,   269,
     273,   273,  1065,   273,   269,   269,   109,   269,   273,   273,
     269,   273,   269,   946,   273,  1002,   273,   269,   268,   268,
     595,   273,  1009,   201,   269,   268,  1013,  2276,   273,   962,
     269,   268,  1364,   269,   273,  1367,  1368,   273,   269,   269,
     218,   974,   273,   273,   106,     6,     6,  1110,  1111,  2301,
     983,   269,   269,   269,   269,   273,   273,   273,   273,   269,
    1392,   269,   995,   273,  1127,   273,   269,   269,   269,  2318,
     273,   273,   273,   269,   269,   269,   269,   273,   273,   273,
     273,   106,   260,  1415,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   150,
     109,   279,   280,   263,   155,   156,   157,   269,   269,   109,
    1442,   273,   273,   269,     4,   269,   269,   273,   217,   273,
     273,     4,     4,   265,  1456,   267,   268,     4,     6,   264,
     264,  1463,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     201,   266,   264,   264,   263,     6,   265,     6,   267,   266,
     268,  1419,   272,     6,   268,     9,   272,   218,   264,   264,
     264,   264,  1105,   264,   264,   264,   268,   752,   277,   200,
    1113,  1168,   200,   200,   268,   109,   136,   264,  1121,   264,
     264,   264,   200,   264,   264,   264,   268,   264,     4,   264,
     268,  1134,  1795,  1796,   268,   268,  1139,   268,  1271,  1272,
     268,   264,   264,     6,   264,   264,   315,   264,   264,     6,
       6,   266,     7,     6,   268,   268,   268,   326,   268,   268,
     266,   330,   266,   266,     6,   264,  1169,  1170,   264,  1172,
    1173,  1174,   200,  1176,  1177,  1178,  1179,  1180,  1181,  1182,
    1183,  1184,  1185,   268,   264,  1188,     6,   264,   264,   264,
     264,   264,  1192,     6,   266,     6,     8,   268,   446,     6,
     845,   264,     8,   268,     7,     6,   268,   268,     6,   457,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,  1231,  1232,
    1233,   479,   263,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   494,   268,    98,   273,
     263,   269,     7,   265,   273,     6,     6,   265,   268,  1262,
      68,   268,   268,   268,   268,   268,   268,   268,   268,   268,
     263,     8,   270,     7,     7,  1278,  1279,  1280,   264,     6,
     265,   268,     7,   452,   453,     6,   269,     7,     6,     6,
     197,   268,   265,   269,   269,   267,     6,   268,     7,   468,
     270,     6,   266,   264,     6,   268,     6,     6,     6,     6,
    1443,  1444,   266,     7,   265,     7,     7,     7,   566,     7,
     568,     7,   570,   571,   572,   446,     7,  1655,     7,     7,
       7,     7,     7,  1336,  1334,  1335,     7,     7,     7,     7,
     268,   986,     6,   591,   592,   265,   273,   273,   273,   267,
     273,   268,  1355,   269,  1357,  1358,   265,     7,   269,     7,
     270,     4,   268,   268,     6,   147,   270,  1370,   269,   269,
     268,   268,  1375,     7,     6,   270,  1379,     7,     7,     7,
     270,   265,   265,     9,   273,  1388,   273,  1390,   273,   267,
    1393,   265,   272,     7,   169,   200,   269,   268,     6,     6,
     569,     6,   270,  1406,    50,    50,   264,   268,   268,     7,
     264,   270,   264,     7,     7,   264,  1419,   200,   587,   270,
     589,   265,     7,  2086,     7,   273,   674,     7,     6,   265,
     273,   268,     7,     7,     7,     7,     7,   121,     4,     6,
     264,  1444,     7,     6,   103,   566,  1449,   568,  1451,   570,
     571,   699,     7,     7,     7,     7,     7,     7,     7,   268,
       6,  1863,     6,     6,     6,   109,  1469,     7,     7,  1114,
     591,   592,     6,     4,     7,     7,   271,   273,   265,  1482,
     273,     6,   268,  1486,   268,     6,     6,   268,     6,   737,
     738,   739,   740,   741,   742,   743,   744,   745,   269,   747,
     748,   749,   750,     7,     6,   753,   754,   755,   266,     6,
       6,  1663,  1664,     6,   268,   763,  1640,   264,   766,  1652,
    1644,   264,     6,   269,   772,   270,     6,     6,  1585,     6,
       6,   267,   273,     6,   140,     6,     6,     6,     6,     6,
       6,     6,     6,  1871,     6,     6,  1549,  1550,  1551,     6,
       6,     5,   265,   269,  1557,  1558,  1559,   127,   127,   127,
     808,   200,   810,     6,   265,     6,     4,     6,     4,   196,
       7,     6,   268,  1576,     7,   268,     6,   266,     6,   827,
       6,   268,     6,   268,  1587,   268,   268,     6,   268,     6,
     838,     6,  1595,     7,   268,   268,   268,  1600,     6,     6,
       6,   268,     6,   269,   269,   268,   268,   265,  1611,   778,
    1613,   264,   273,   273,   268,   264,   273,   738,   273,   740,
     741,   742,   743,   744,   745,     7,   747,   748,   749,   750,
     270,   268,   753,   754,   755,     6,   269,  1770,     6,     8,
     264,     6,     6,     6,   147,     5,   268,   107,     6,   268,
     268,   268,  1655,   265,   109,   268,     6,   273,   268,  1716,
    1663,  1664,     6,     6,   147,   147,  1669,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   273,  1687,     6,     6,   263,     6,     6,
       6,   273,   273,     6,     6,  1698,     6,     6,     6,     6,
    1703,   265,     6,     6,   151,     7,   827,   268,   268,   268,
       6,   273,   268,     5,     7,     6,     6,   838,     6,     6,
     268,   268,  1874,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   268,   265,   269,   268,   263,   268,     6,     6,   268,
     998,   195,  1000,  1001,  1811,  1812,  1813,  1814,  1815,  1816,
     269,     6,   269,   269,   265,     7,  1014,     6,     6,   269,
       6,   270,     6,     6,   268,     6,     6,   946,   269,  1782,
       6,     6,     6,   268,  1787,  1788,     6,  1035,   198,     6,
     265,     6,   264,     6,   268,  1795,  1796,  2125,     6,     6,
     147,     6,     6,     6,     6,     6,   269,  1810,     6,  1057,
     269,   269,     6,  1816,   983,   268,   265,   268,   268,  1822,
     268,     6,  1467,   268,  1469,   265,   268,     6,  1831,     6,
       6,     6,     6,     6,     6,   269,     6,   269,  1841,   268,
       6,  1844,     6,   268,     6,   268,     6,  2255,  1096,  1518,
    1455,     4,     5,  1711,  2049,  2009,   497,  1860,  1481,  1778,
       3,  1864,   585,  1123,     3,     3,     3,   645,  1871,  2082,
    1873,  1874,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
    1633,  1139,     3,  1846,   263,   827,   265,    50,    51,    52,
      53,    54,    55,    56,    57,    58,  1909,  1664,  1864,    -1,
      63,    64,    65,    66,    -1,    -1,    -1,    -1,    71,    72,
      73,    74,    -1,  1926,    -1,    -1,    -1,    80,    -1,    82,
      -1,    -1,    -1,    -1,    -1,    -1,  1105,    -1,    -1,  1942,
    1943,    -1,    -1,    96,    -1,    -1,    99,    -1,    -1,    -1,
     103,    -1,  1121,   106,    -1,    -1,   109,    -1,   111,    -1,
      -1,    -1,    -1,    -1,  1967,    -1,    -1,    -1,    -1,   122,
      -1,  2095,    -1,    -1,    -1,    -1,  1979,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1232,  1233,    -1,    -1,    -1,    -1,
     143,  1636,    -1,    -1,  1997,    -1,    -1,    -1,    -1,    -1,
    1169,  1170,    -1,  1172,  1173,  1174,    -1,  1176,  1177,  1178,
    1179,  1180,  1181,  1182,  1183,  1184,  1185,    -1,  1139,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2035,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2099,  2100,  2101,  2102,  2103,  2050,    -1,    -1,
      -1,    -1,  2055,  1698,  1302,  2058,  2059,    -1,    -1,    -1,
      -1,    -1,  1231,   216,   217,   218,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   228,  2200,  2080,    -1,   232,
    2083,   234,   235,    -1,    -1,    -1,  2086,    -1,    -1,    -1,
      -1,  2094,    -1,  1262,    -1,  2098,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2110,    -1,  1278,
      -1,  1232,  1233,  2170,    -1,   268,    -1,  2174,    -1,  2243,
      -1,    -1,  2125,    -1,    -1,    -1,    -1,  1375,    -1,    -1,
      -1,  1379,    -1,    -1,    -1,  2138,    -1,    -1,    -1,    -1,
    1388,    -1,  1390,    -1,    -1,  1393,  1791,    -1,    -1,    -1,
      -1,    -1,  1400,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1336,  2171,    -1,
      -1,    -1,  2229,    -1,    -1,    -1,  2233,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1355,    -1,  1357,  1358,
      -1,    -1,  2249,    -1,  1839,    -1,  1444,    -1,    -1,    -1,
      -1,  1846,  1847,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1865,    -1,    -1,    -1,  2227,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1406,    -1,  2296,
    2297,    -1,  2245,  2246,  2247,  2248,  2249,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1375,    -1,    -1,    -1,  1379,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1388,    -1,  1390,
      -1,    -1,  1393,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2290,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1469,    -1,    -1,  2306,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1482,    -1,    -1,    -1,  1486,    -1,    -1,
      -1,    -1,    -1,  1444,  2327,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2340,     6,    -1,
      -1,    -1,    -1,  2346,  2347,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2359,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2011,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1549,  1550,  1551,    -1,    -1,    -1,    -1,    -1,  1557,  1558,
    1559,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1576,     6,  2054,
      -1,    -1,    -1,    -1,    -1,  1663,  1664,    -1,  1587,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1595,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1687,
      -1,    -1,  1611,    -1,  1613,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,    -1,
      -1,    -1,    -1,    10,    11,    12,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,     8,    -1,    -1,    -1,    -1,
    1669,    -1,    -1,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    -1,    -1,    -1,    71,    72,    73,    74,     6,  1698,
      -1,    -1,    -1,    80,    -1,    82,    83,    84,    85,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,    95,    96,
      97,    -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1687,    -1,    -1,    -1,
      -1,  2216,    -1,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,    -1,    -1,  1841,    -1,   263,  1844,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1857,
      -1,  1859,    -1,  1782,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1874,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1810,    -1,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,  1909,  1831,    -1,    -1,   263,    -1,    -1,   215,   216,
     217,   218,   219,    -1,    -1,    -1,    -1,    -1,   225,   226,
     227,   228,   229,   230,   231,   232,    -1,   234,   235,    -1,
      -1,  1860,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1873,   252,   253,    -1,    -1,    -1,
      -1,    -1,   259,    -1,    -1,    -1,    -1,   264,    -1,    -1,
    1841,   268,    -1,  1844,   271,    -1,    -1,    -1,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   109,    -1,    -1,    -1,
     263,    -1,    -1,    -1,    -1,    -1,    -1,  1926,    -1,   122,
      -1,    13,    14,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,    -1,    -1,    -1,    -1,   263,    -1,   150,    -1,    -1,
      -1,   154,    -1,    -1,    -1,    -1,   159,    -1,  1967,    -1,
      -1,    -1,    -1,   166,    -1,    -1,   169,    -1,    -1,     6,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   186,   187,   188,    -1,   190,   191,   192,
      -1,   194,   195,   196,   197,   198,   199,   200,    -1,   202,
     203,   204,   205,    -1,    -1,    -1,    -1,   210,   211,    -1,
      -1,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,    -1,    -1,  2035,   119,   120,   121,
     122,    -1,    -1,    -1,    -1,   127,    -1,    -1,    -1,    -1,
      -1,  2050,    -1,    -1,   136,   137,    -1,    -1,   140,   141,
      -1,   143,   144,    -1,   146,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2080,    -1,   165,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2094,    -1,    -1,   291,   292,
     293,   294,   295,    -1,    -1,  2183,    -1,    -1,    -1,    -1,
     192,   193,   194,    -1,    -1,    -1,    -1,   310,   311,   312,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   328,    -1,    -1,    -1,  2138,
      -1,    -1,    -1,    -1,    -1,   338,   339,    -1,    -1,    -1,
      -1,   344,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   354,   355,   356,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2171,    -1,    -1,  2253,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   377,   378,    -1,   269,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   388,    -1,   390,   391,  2277,
     393,    -1,    -1,    -1,   397,   398,   399,    -1,    -1,   402,
      -1,    -1,    -1,   406,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,    -1,    -1,    -1,    -1,   263,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2327,
      -1,    -1,    -1,    -1,    -1,   448,   449,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2346,  2347,
      -1,    -1,   465,   466,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2359,    -1,    -1,    -1,    -1,    -1,   480,    -1,    -1,
      -1,  2290,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   502,
      -1,    -1,    -1,    -1,   507,    -1,    -1,    -1,   511,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   525,   526,    -1,    -1,    -1,    -1,   531,    -1,
      -1,  2340,   535,   536,   537,   538,   539,   540,   541,   542,
     543,   544,   545,   546,   547,   548,   549,   550,   551,   552,
     553,   554,   555,   556,   557,   558,   559,   560,   561,   562,
      -1,   564,   565,    -1,   567,    -1,  2327,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   577,    -1,    -1,   580,   581,    -1,
      -1,    -1,    -1,    -1,    -1,  2346,  2347,    -1,    -1,    -1,
     593,    -1,    -1,    -1,    -1,   598,    -1,    -1,  2359,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   610,   611,   612,
     613,   614,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   625,   626,   627,   628,   629,    -1,   631,   632,
      -1,    -1,    -1,    -1,    -1,    -1,   639,   640,   641,    -1,
      -1,    -1,    -1,    -1,   647,   648,   649,   650,    -1,   652,
     653,    -1,    -1,    -1,    13,    14,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   671,   672,
     673,    -1,    -1,    -1,   677,   678,   679,   680,   681,   682,
     683,   684,   685,    -1,    -1,    -1,    -1,    -1,    -1,   692,
     693,    -1,   695,    -1,    -1,   698,    -1,    -1,    -1,   702,
     703,   704,   705,    -1,    -1,    -1,   709,   710,   711,   712,
     713,    -1,    -1,   716,    -1,   718,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   728,    -1,    -1,   731,    -1,
     733,   734,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   746,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   760,    -1,    -1,
     119,   120,   121,   122,   767,    -1,    -1,    -1,   127,    -1,
      -1,    -1,   775,    -1,    -1,    -1,    -1,   136,   137,    -1,
      -1,   140,   141,    -1,   143,   144,    -1,   146,    -1,    -1,
      -1,   794,    -1,   796,    -1,   210,   211,    -1,   801,   802,
      -1,    -1,    -1,    -1,    -1,    -1,   165,    -1,    -1,    -1,
      -1,    -1,    -1,   816,    -1,   818,   819,    -1,    -1,   822,
      -1,   824,   825,    -1,    -1,    -1,   829,    -1,   831,    -1,
     833,    -1,    -1,   192,   193,   194,   839,    -1,    -1,    -1,
     843,    -1,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
      -1,    -1,    -1,   866,   263,   868,   265,   870,   267,    -1,
      -1,    -1,    -1,    -1,   273,    -1,    -1,   292,    -1,    -1,
     295,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   210,   211,   311,   312,    -1,    -1,
      -1,    -1,    -1,    -1,   907,    -1,    -1,    -1,    -1,    -1,
     269,    -1,    -1,    -1,   917,   918,   919,   920,    -1,    -1,
      -1,    -1,    -1,    -1,   927,   928,   929,    -1,   931,    -1,
      -1,   934,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   354,
     355,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   962,
      -1,    -1,    -1,   378,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   974,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   982,
      -1,    -1,    -1,   986,    -1,    -1,    -1,    -1,    -1,   992,
      -1,    -1,   995,    -1,    -1,   311,   312,    -1,    -1,    -1,
    1003,  1004,    -1,    -1,    -1,    -1,  1009,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     4,     5,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1027,    -1,    -1,  1030,    -1,    -1,
      -1,    -1,    -1,   448,    -1,    -1,    -1,    -1,   354,   355,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1056,    -1,  1058,  1059,    -1,    -1,    -1,
      -1,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      -1,    -1,    -1,    -1,    63,    64,    65,    66,  1081,    -1,
      -1,     6,    71,    72,    73,    74,    -1,    -1,    -1,    -1,
      -1,    80,    -1,    82,    -1,    -1,    -1,    -1,  1101,    -1,
      -1,    -1,    -1,    -1,    -1,  1108,    -1,    96,    -1,    -1,
      99,   526,  1115,    -1,   103,    -1,    -1,   106,    -1,    -1,
     109,    -1,   111,    -1,    -1,  1128,  1129,    -1,    -1,    -1,
      -1,  1134,   448,   122,    -1,    -1,    -1,   552,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   561,   562,    -1,    -1,
      -1,    -1,    -1,    -1,   143,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1166,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   593,    -1,
      -1,    -1,    -1,   598,    -1,  1188,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,  1207,    -1,    -1,    -1,   263,   624,
      -1,    -1,    -1,    -1,  1217,  1218,  1219,  1220,  1221,    -1,
      -1,    -1,    -1,  1226,  1227,    -1,  1229,   216,   217,   218,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   652,   653,   228,
      -1,    -1,    -1,   232,  1247,   234,   235,  1250,  1251,    -1,
      -1,    -1,    -1,    -1,    -1,  1258,  1259,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1267,  1268,    -1,    -1,    -1,    -1,
    1273,  1274,   261,   262,    -1,    -1,  1279,  1280,    -1,   268,
      -1,   270,   598,    -1,    -1,    -1,    -1,   702,   703,   704,
      -1,    -1,    -1,    -1,    -1,   710,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1314,    -1,    26,   470,    28,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,    -1,    -1,   652,   653,   263,    -1,
      -1,    -1,    -1,    -1,    -1,   760,    -1,    -1,    -1,    -1,
    1353,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1365,  1366,    -1,    -1,    -1,  1370,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1378,    -1,    -1,    -1,   794,
      -1,    -1,    -1,    -1,    -1,    -1,   702,   703,   704,    -1,
      -1,    -1,    -1,    -1,   710,    -1,    -1,    -1,    -1,  1402,
      -1,   816,    -1,    -1,    -1,    -1,    -1,   822,    -1,   824,
    1413,    -1,    -1,  1416,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   578,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   150,    -1,    -1,
      -1,    -1,  1445,    -1,   760,  1448,  1449,  1450,  1451,    -1,
      -1,    -1,    -1,   868,    -1,   870,  1459,    -1,    -1,  1462,
      -1,  1464,    -1,  1466,  1467,    -1,    -1,  1470,  1471,  1472,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   794,   635,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   907,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     816,    -1,   917,    -1,    -1,    -1,   822,    -1,   824,    -1,
      -1,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,    -1,   257,   258,    -1,   962,    -1,    -1,
      -1,    -1,    -1,  1556,   267,   268,    -1,    -1,    -1,   974,
      -1,    -1,    -1,    -1,  1567,  1568,  1569,    -1,    -1,    -1,
     283,   284,    -1,  1576,    -1,  1578,    -1,    -1,    -1,    -1,
     995,    -1,  1585,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   907,    -1,    -1,    -1,    -1,    -1,  1600,    -1,    -1,
      -1,   917,    -1,  1606,  1607,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1617,  1618,  1619,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1628,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1638,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   962,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1659,    -1,   974,    -1,
      -1,    -1,    -1,    -1,  1667,  1668,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   995,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   401,    -1,
      -1,    -1,    -1,    -1,    -1,   408,   409,   410,    -1,    -1,
    1703,   414,   415,   416,   417,   418,   419,   420,    -1,   422,
      -1,    -1,    -1,    -1,   427,   428,    -1,    -1,   431,  1134,
     876,   877,   878,   879,   880,   881,   882,   883,   884,   885,
     886,   887,    -1,   889,   890,   891,   892,    -1,   894,   895,
     896,   897,    -1,  1746,  1747,  1748,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   910,    -1,   912,    -1,    -1,  1762,
      -1,    -1,    -1,    -1,  1767,  1768,    -1,   923,    -1,    -1,
      -1,    -1,    -1,  1188,    -1,    -1,    -1,  1780,    -1,    -1,
     936,   937,    -1,    -1,  1787,  1788,  1789,    -1,  1791,   945,
      -1,    -1,    -1,    -1,  1797,  1798,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1816,    -1,    -1,    -1,    -1,  1134,  1822,
    1823,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1835,  1836,    -1,    -1,  1839,    -1,    -1,  1842,
      -1,    -1,    -1,  1846,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1856,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1866,  1279,  1280,    -1,    -1,    -1,    -1,
      -1,    -1,  1188,    -1,    -1,    -1,    -1,  1880,    -1,    -1,
      -1,    -1,  1885,  1886,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   606,    -1,    -1,  1899,    -1,    -1,  1902,
    1903,    -1,  1905,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1067,  1068,  1069,    -1,    -1,    -1,  1073,  1074,    -1,
      -1,  1077,  1078,  1079,  1080,    -1,  1082,    -1,  1931,  1932,
    1933,  1087,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1942,
    1943,    -1,    -1,    -1,    -1,    -1,  1949,  1950,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1370,    -1,    -1,  1961,    -1,
      -1,    -1,    -1,  1279,  1280,    -1,    -1,  1970,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1979,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1992,
    1993,    13,    14,  1996,  1997,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1165,
      -1,  1167,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2032,
    2033,    -1,    -1,    -1,  1449,    -1,  1451,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2053,    -1,    -1,    -1,  1370,  2058,  2059,  2060,    -1,    -1,
      -1,    -1,  2065,    -1,    -1,    -1,  2069,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2083,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,    -1,  2098,    -1,   119,   120,   121,
     122,    -1,    -1,    -1,  2107,   127,    -1,  2110,    -1,    -1,
      -1,    -1,    -1,    -1,   136,   137,    -1,    -1,   140,   141,
    1276,   143,   144,    -1,   146,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2135,  1449,    -1,  1451,    -1,    -1,  2141,    -1,
      -1,  2144,    -1,   165,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2159,    -1,  2161,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     192,   193,   194,     6,    -1,    -1,  2179,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1600,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2206,  2207,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2221,  2222,
      -1,    -1,    -1,    -1,  2227,    -1,    -1,   940,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2240,    -1,    -1,
      -1,    -1,  2245,  2246,  2247,  2248,  2249,   269,    -1,    -1,
      -1,    -1,  2255,    -1,    -1,    -1,  2259,    -1,    -1,    -1,
     973,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1425,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1600,  2288,    -1,    -1,  1703,    -1,
    2293,  2294,    -1,    -1,    -1,    -1,     6,    -1,    -1,    -1,
      -1,    -1,    -1,  2306,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1468,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2333,  2334,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1501,  1502,  1503,  1504,  1505,
    1506,  1507,     8,    -1,    -1,    -1,  1512,  1513,    -1,    -1,
      -1,    -1,    -1,  1519,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1527,  1787,  1788,    -1,  1531,    -1,    -1,  1534,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1545,
      -1,     4,     5,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1816,    -1,    -1,    -1,    -1,    -1,  1822,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,    -1,    -1,    -1,    -1,
     263,    -1,    -1,    -1,    -1,    -1,    -1,    50,    51,    52,
      53,    54,    55,    56,    57,    58,  1159,    -1,    -1,    -1,
      63,    64,    65,    66,    -1,    -1,    -1,    -1,    71,    72,
      73,    74,    -1,    -1,    -1,    -1,    -1,    80,  1624,    82,
    1626,  1787,  1788,    -1,  1630,    -1,  1632,    -1,    -1,    -1,
      -1,    -1,    -1,    96,    -1,    -1,    99,    -1,    -1,     6,
     103,    -1,    -1,   106,    -1,    -1,   109,    -1,   111,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1822,  1663,    -1,   122,
      -1,    -1,     6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1942,  1943,    -1,
     143,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,    -1,
    1263,    -1,    -1,   263,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1979,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1997,    -1,    -1,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   216,   217,   218,    -1,   263,    -1,    -1,
      -1,    -1,    -1,  1769,     6,   228,    -1,    -1,    -1,   232,
      -1,   234,   235,    -1,    -1,    -1,  1942,  1943,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     6,    -1,    -1,
      -1,    -1,    -1,  2058,  2059,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   265,    -1,   267,   268,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2083,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1997,    -1,  2098,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2110,    -1,    -1,    -1,     6,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1426,  1427,    -1,    -1,    -1,    -1,    -1,
    1876,    -1,    -1,  1879,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,  2058,  2059,    -1,    -1,   263,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,    -1,    -1,  2083,    -1,   263,
      -1,    -1,  1928,  1929,    -1,    -1,    -1,    -1,    -1,  1935,
      -1,    -1,  2098,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2110,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2227,    -1,    -1,    -1,  1529,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1538,    -1,    -1,    -1,    -1,
    2245,  2246,  2247,  2248,  2249,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2002,  2003,    -1,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   147,    -1,    -1,
      -1,   263,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
      -1,  2306,    -1,    -1,   263,  2051,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2227,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2245,
    2246,  2247,  2248,  2249,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,    -1,    -1,    -1,    -1,   263,    -1,    -1,    -1,
      -1,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,     3,
       4,     5,    -1,   263,    -1,    -1,    10,    11,    12,  1702,
    2306,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    -1,    -1,    -1,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    -1,    -1,    71,    72,    73,
      74,    -1,    -1,    77,    78,    79,    80,    -1,    82,    83,
      84,    85,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      94,    95,    96,    97,    -1,    99,    -1,    -1,    -1,   103,
      -1,    -1,   106,    -1,    -1,   109,    -1,   111,    -1,    -1,
      -1,    -1,    -1,    -1,   118,    -1,    -1,    -1,   122,   123,
     124,    -1,    -1,   127,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   136,    -1,   138,   139,    -1,   141,    -1,   143,
      -1,    -1,   146,    -1,    -1,    -1,    -1,    -1,   152,   153,
     154,   155,   156,    -1,   158,   159,   160,   161,   162,   163,
     164,    -1,    -1,    -1,   168,    -1,    -1,    -1,   172,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2315,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   197,    -1,    -1,     6,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   215,   216,   217,   218,   219,   220,    -1,    -1,    -1,
      -1,   225,   226,   227,   228,   229,   230,   231,   232,    -1,
     234,   235,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   252,   253,
      -1,    -1,    -1,    -1,    -1,   259,    -1,    -1,    -1,    -1,
     264,     3,     4,     5,   268,    -1,    -1,   271,    10,    11,
      12,    -1,    -1,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    -1,    -1,    -1,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    -1,    -1,    71,
      72,    73,    74,    -1,    -1,    77,    78,    79,    80,    -1,
      82,    83,    84,    85,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    94,    95,    96,    97,    -1,    99,    -1,    -1,
      -1,   103,    -1,    -1,   106,    -1,    -1,   109,    -1,   111,
      -1,    -1,    -1,    -1,    -1,    -1,   118,    -1,    -1,    -1,
     122,   123,   124,    -1,    -1,   127,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   136,    -1,   138,   139,    -1,   141,
      -1,   143,    -1,    -1,   146,    -1,    -1,    -1,     6,    -1,
     152,   153,   154,   155,   156,    -1,   158,   159,   160,   161,
     162,   163,   164,    -1,    -1,    -1,   168,    -1,    -1,    -1,
     172,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,     6,
      -1,    -1,    -1,   263,    -1,   197,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     6,   215,   216,   217,   218,   219,   220,    -1,
      -1,    -1,    -1,   225,   226,   227,   228,   229,   230,   231,
     232,    -1,   234,   235,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     252,   253,    -1,    -1,    -1,    -1,    -1,   259,    -1,    -1,
      -1,    -1,   264,     3,     4,     5,   268,     7,    -1,   271,
      10,    11,    12,    -1,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    -1,    -1,
      -1,    71,    72,    73,    74,    -1,    -1,    -1,    -1,    -1,
      80,    -1,    82,    83,    84,    85,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    94,    95,    96,    97,    -1,    99,
      -1,    -1,    -1,   103,    -1,    -1,   106,    -1,    -1,   109,
      -1,   111,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   122,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,    -1,    -1,   143,    -1,   263,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,    -1,    -1,    -1,    -1,   263,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,     6,    -1,    -1,   208,   263,
      -1,    -1,    -1,    -1,    -1,   215,   216,   217,   218,   219,
      -1,    -1,    -1,    -1,    -1,   225,   226,   227,   228,   229,
     230,   231,   232,    -1,   234,   235,    -1,   237,   238,   239,
     240,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   252,   253,    -1,    -1,    -1,    -1,    -1,   259,
      -1,   261,   262,    -1,   264,    -1,   266,     3,     4,     5,
     270,   271,    -1,    -1,    10,    11,    12,    -1,    -1,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    59,    60,    61,    62,    -1,    -1,    -1,
      -1,    67,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    77,    78,    79,    -1,    -1,    -1,    83,    84,    85,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,    95,
      -1,    97,    -1,    -1,    -1,    -1,    -1,   103,    -1,    -1,
     106,    -1,    -1,   109,    -1,   111,    -1,    -1,    -1,    -1,
      -1,    -1,   118,    -1,    -1,    -1,   122,   123,   124,    -1,
      -1,   127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     136,    -1,   138,   139,    -1,   141,    -1,   143,    -1,    -1,
     146,    -1,    -1,    -1,    -1,    -1,   152,   153,   154,   155,
     156,    -1,   158,   159,   160,   161,   162,   163,   164,    -1,
      -1,    -1,   168,    -1,    -1,    -1,   172,    -1,    -1,    -1,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,    -1,    -1,
      -1,   197,   263,    -1,     6,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   215,
      -1,    -1,    -1,   219,   220,    -1,    -1,    -1,    -1,   225,
     226,   227,    -1,   229,   230,   231,    -1,    -1,    -1,   235,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   252,   253,    -1,    -1,
      -1,    -1,    -1,   259,    -1,    -1,    -1,    -1,   264,     3,
       4,    -1,   268,    -1,     8,   271,    10,    11,    12,    -1,
      -1,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    59,    60,    61,    62,    -1,
      -1,    -1,    -1,    67,    68,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    77,    78,    79,    -1,    -1,    -1,    83,
      84,    85,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      94,    95,    -1,    97,    -1,    -1,    -1,    -1,    -1,   103,
      -1,    -1,   106,    -1,    -1,   109,    -1,   111,    -1,    -1,
      -1,    -1,    -1,    -1,   118,    -1,    -1,    -1,   122,   123,
     124,    -1,    -1,   127,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   136,    -1,   138,   139,    -1,   141,    -1,   143,
      -1,    -1,   146,    -1,    -1,    -1,    -1,    -1,   152,   153,
     154,   155,   156,    -1,   158,   159,   160,   161,   162,   163,
     164,    -1,    -1,    -1,   168,    -1,    -1,    -1,   172,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,    -1,    -1,    -1,
      -1,   263,    -1,   197,    -1,    -1,    -1,     7,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   215,    -1,    -1,    -1,   219,   220,    -1,    -1,    -1,
      -1,   225,   226,   227,    -1,   229,   230,   231,    -1,    -1,
      -1,   235,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   252,   253,
      -1,    -1,    -1,    -1,    -1,   259,    -1,    -1,    -1,    -1,
     264,     3,     4,     5,    -1,   269,    -1,   271,    10,    11,
      12,    -1,    -1,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,    60,    61,
      62,    -1,    -1,    -1,    -1,    67,    68,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    77,    78,    79,    -1,    -1,
      -1,    83,    84,    85,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    94,    95,    -1,    97,    -1,    -1,    -1,    -1,
      -1,   103,    -1,    -1,   106,    -1,    -1,   109,    -1,   111,
      -1,    -1,    -1,    -1,    -1,    -1,   118,    -1,    -1,    -1,
     122,   123,   124,    -1,    -1,   127,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   136,    -1,   138,   139,    -1,   141,
      -1,   143,    -1,    -1,   146,    -1,    -1,    -1,    -1,    -1,
     152,   153,   154,   155,   156,    -1,   158,   159,   160,   161,
     162,   163,   164,    -1,    -1,    -1,   168,    -1,    -1,    -1,
     172,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,    -1,
      -1,    -1,    -1,   263,    -1,   197,    -1,    -1,    -1,     7,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   215,    -1,    -1,    -1,   219,   220,    -1,
      -1,    -1,    -1,   225,   226,   227,    -1,   229,   230,   231,
      -1,    -1,    -1,   235,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     252,   253,    -1,    -1,    -1,    -1,    -1,   259,    -1,    -1,
      -1,    -1,   264,     3,     4,    -1,   268,    -1,    -1,   271,
      10,    11,    12,    -1,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,
      60,    61,    62,    -1,    -1,    -1,    -1,    67,    68,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,    78,    79,
      -1,    -1,    -1,    83,    84,    85,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    94,    95,    -1,    97,    -1,    -1,
      -1,    -1,    -1,   103,    -1,    -1,   106,    -1,    -1,   109,
      -1,   111,    -1,    -1,    -1,    -1,    -1,    -1,   118,    -1,
      -1,    -1,   122,   123,   124,    -1,    -1,   127,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   136,    -1,   138,   139,
      -1,   141,    -1,   143,    -1,    -1,   146,    -1,    -1,    -1,
      -1,    -1,   152,   153,   154,   155,   156,    -1,   158,   159,
     160,   161,   162,   163,   164,    -1,    -1,    -1,   168,    -1,
      -1,    -1,   172,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,    -1,    -1,    -1,    -1,   263,    -1,   197,    -1,    -1,
      -1,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   215,    -1,    -1,    -1,   219,
     220,    -1,    -1,    -1,    -1,   225,   226,   227,    -1,   229,
     230,   231,    -1,    -1,    -1,   235,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   252,   253,    -1,    -1,    -1,    -1,    -1,   259,
      -1,    -1,    -1,    -1,   264,     3,     4,    -1,   268,   269,
      -1,   271,    10,    11,    12,    -1,    -1,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    59,    60,    61,    62,    -1,    -1,    -1,    -1,    67,
      68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,
      78,    79,    -1,    -1,    -1,    83,    84,    85,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    94,    95,    -1,    97,
      -1,    -1,    -1,    -1,    -1,   103,    -1,    -1,   106,    -1,
      -1,   109,    -1,   111,    -1,    -1,    -1,    -1,    -1,    -1,
     118,    -1,    -1,    -1,   122,   123,   124,    -1,    -1,   127,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   136,    -1,
     138,   139,    -1,   141,    -1,   143,    -1,    -1,   146,    -1,
      -1,    -1,    -1,    -1,   152,   153,   154,   155,   156,    -1,
     158,   159,   160,   161,   162,   163,   164,    -1,    -1,    -1,
     168,    -1,    -1,    -1,   172,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,    -1,    -1,    -1,    -1,   263,    -1,   197,
      -1,    -1,    -1,    -1,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   215,    -1,    -1,
      -1,   219,   220,    -1,    -1,    -1,    -1,   225,   226,   227,
      -1,   229,   230,   231,    -1,    -1,    -1,   235,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   252,   253,    -1,    -1,    -1,    -1,
      -1,   259,    -1,    -1,    -1,    -1,   264,     3,     4,    -1,
     268,    -1,    -1,   271,    10,    11,    12,    -1,    -1,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    59,    60,    61,    62,    -1,    -1,    -1,
      -1,    67,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    77,    78,    79,    -1,    -1,    -1,    83,    84,    85,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,    95,
      -1,    97,    -1,    -1,    -1,    -1,    -1,   103,    -1,    -1,
     106,    -1,    -1,   109,    -1,   111,    -1,    -1,    -1,    -1,
      -1,    -1,   118,    -1,    -1,    -1,   122,   123,   124,    -1,
      -1,   127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     136,    -1,   138,   139,    -1,   141,    -1,   143,    -1,    -1,
     146,    -1,    -1,    -1,    -1,    -1,   152,   153,   154,   155,
     156,    -1,   158,   159,   160,   161,   162,   163,   164,    -1,
      -1,    -1,   168,    -1,    -1,    -1,   172,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,    -1,    -1,    -1,    -1,   263,
      -1,   197,    -1,    -1,    -1,    -1,     8,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   215,
      -1,    -1,    -1,   219,   220,    -1,    -1,    -1,    -1,   225,
     226,   227,    -1,   229,   230,   231,    -1,    -1,    -1,   235,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   252,   253,    -1,    -1,
      -1,    -1,    -1,   259,    -1,    -1,    -1,    -1,   264,     3,
       4,    -1,   268,    -1,    -1,   271,    10,    11,    12,    -1,
      -1,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    59,    60,    61,    62,    -1,
      -1,    -1,    -1,    67,    68,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    77,    78,    79,    -1,    -1,    -1,    83,
      84,    85,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      94,    95,    -1,    97,    -1,    -1,    -1,    -1,    -1,   103,
      -1,    -1,   106,    -1,    -1,   109,    -1,   111,    -1,    -1,
      -1,    -1,    -1,    -1,   118,    -1,    -1,    -1,   122,   123,
     124,    -1,    -1,   127,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   136,    -1,   138,   139,    -1,   141,    -1,   143,
      -1,    -1,   146,    -1,    -1,    -1,    -1,    -1,   152,   153,
     154,   155,   156,    -1,   158,   159,   160,   161,   162,   163,
     164,    -1,    -1,    -1,   168,    -1,    -1,    -1,   172,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,    -1,    -1,    -1,
      -1,   263,    -1,   197,    -1,    -1,    -1,    -1,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   215,    -1,    -1,    -1,   219,   220,    -1,    -1,    -1,
      -1,   225,   226,   227,    -1,   229,   230,   231,    -1,    -1,
      -1,   235,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   252,   253,
      -1,    -1,    -1,    -1,    -1,   259,    -1,    -1,    -1,    -1,
     264,     3,     4,    -1,   268,    -1,    -1,   271,    10,    11,
      12,    -1,    -1,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,    60,    61,
      62,    -1,    -1,    -1,    -1,    67,    68,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    77,    78,    79,    -1,    -1,
      -1,    83,    84,    85,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    94,    95,    -1,    97,    -1,    -1,    -1,    -1,
      -1,   103,    -1,    -1,   106,    -1,    -1,   109,    -1,   111,
      -1,    -1,    -1,    -1,    -1,    -1,   118,    -1,    -1,    -1,
     122,   123,   124,    -1,    -1,   127,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   136,    -1,   138,   139,    -1,   141,
      -1,   143,    -1,    -1,   146,    -1,    -1,    -1,    -1,    -1,
     152,   153,   154,   155,   156,    -1,   158,   159,   160,   161,
     162,   163,   164,    -1,    -1,    -1,   168,    -1,    -1,    -1,
     172,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,    -1,
      -1,    -1,    -1,   263,    -1,   197,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   215,    -1,    -1,    -1,   219,   220,    -1,
      -1,    -1,    -1,   225,   226,   227,    -1,   229,   230,   231,
      -1,    -1,    -1,   235,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     252,   253,    -1,    -1,    -1,    -1,    -1,   259,    -1,    -1,
      -1,    -1,   264,     3,     4,    -1,    -1,   269,    -1,   271,
      10,    11,    12,    -1,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,
      60,    61,    62,    -1,    -1,    -1,    -1,    67,    68,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,    78,    79,
      -1,    -1,    -1,    83,    84,    85,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    94,    95,    -1,    97,    -1,    -1,
      -1,    -1,    -1,   103,    -1,    -1,   106,    -1,    -1,   109,
      -1,   111,    -1,    -1,    -1,    -1,    -1,    -1,   118,    -1,
      -1,    -1,   122,   123,   124,    -1,    -1,   127,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   136,    -1,   138,   139,
      -1,   141,    -1,   143,    -1,    -1,   146,    -1,    -1,    -1,
      -1,    -1,   152,   153,   154,   155,   156,    -1,   158,   159,
     160,   161,   162,   163,   164,    -1,    -1,    -1,   168,    -1,
      -1,    -1,   172,    -1,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,    -1,    -1,    -1,    -1,   263,   197,   265,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   273,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   215,    -1,    -1,    -1,   219,
     220,    -1,    -1,    -1,    -1,   225,   226,   227,    -1,   229,
     230,   231,    -1,    -1,    -1,   235,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   252,   253,    -1,    -1,    -1,    -1,    -1,   259,
      -1,    -1,    -1,    -1,   264,     3,     4,    -1,   268,    -1,
      -1,   271,    10,    11,    12,    -1,    -1,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    59,    60,    61,    62,    -1,    -1,    -1,    -1,    67,
      68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,
      78,    79,    -1,    -1,    -1,    83,    84,    85,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    94,    95,    -1,    97,
      -1,    -1,    -1,    -1,    -1,   103,    -1,    -1,   106,    -1,
      -1,   109,    -1,   111,    -1,    -1,    -1,    -1,    -1,    -1,
     118,    -1,    -1,    -1,   122,   123,   124,    -1,    -1,   127,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   136,    -1,
     138,   139,    -1,   141,    -1,   143,    -1,    -1,   146,    -1,
      -1,    -1,    -1,    -1,   152,   153,   154,   155,   156,    -1,
     158,   159,   160,   161,   162,   163,   164,    -1,    -1,    -1,
     168,    -1,    -1,    -1,   172,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,    -1,    -1,    -1,    -1,   263,    -1,   197,
      -1,    -1,    -1,   269,    -1,    -1,    -1,   273,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   215,    -1,    -1,
      -1,   219,   220,    -1,    -1,    -1,    -1,   225,   226,   227,
      -1,   229,   230,   231,    -1,    -1,    -1,   235,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   252,   253,    -1,    -1,    -1,    -1,
      -1,   259,    -1,    -1,    -1,    -1,   264,     3,     4,    -1,
     268,    -1,    -1,   271,    10,    11,    12,    -1,    -1,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    59,    60,    61,    62,    -1,    -1,    -1,
      -1,    67,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    77,    78,    79,    -1,    -1,    -1,    83,    84,    85,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,    95,
      -1,    97,    -1,    -1,    -1,    -1,    -1,   103,    -1,    -1,
     106,    -1,    -1,   109,    -1,   111,    -1,    -1,    -1,    -1,
      -1,    -1,   118,    -1,    -1,    -1,   122,   123,   124,    -1,
      -1,   127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     136,    -1,   138,   139,    -1,   141,    -1,   143,    -1,    -1,
     146,    -1,    -1,    -1,    -1,    -1,   152,   153,   154,   155,
     156,    -1,   158,   159,   160,   161,   162,   163,   164,    -1,
      -1,    -1,   168,    -1,    -1,    -1,   172,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,    -1,    -1,    -1,    -1,   263,
      -1,   197,    -1,    -1,    -1,   269,    -1,    -1,    -1,   273,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   215,
      -1,    -1,    -1,   219,   220,    -1,    -1,    -1,    -1,   225,
     226,   227,    -1,   229,   230,   231,    -1,    -1,    -1,   235,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   252,   253,    -1,    -1,
      -1,    -1,    -1,   259,    -1,    -1,    -1,    -1,   264,     3,
       4,    -1,   268,    -1,     8,   271,    10,    11,    12,    -1,
      -1,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    59,    60,    61,    62,    -1,
      -1,    -1,    -1,    67,    68,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    77,    78,    79,    -1,    -1,    -1,    83,
      84,    85,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      94,    95,    -1,    97,    -1,    -1,    -1,    -1,    -1,   103,
      -1,    -1,   106,    -1,    -1,   109,    -1,   111,    -1,    -1,
      -1,    -1,    -1,    -1,   118,    -1,    -1,    -1,   122,   123,
     124,    -1,    -1,   127,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   136,    -1,   138,   139,    -1,   141,    -1,   143,
      -1,    -1,   146,    -1,    -1,    -1,    -1,    -1,   152,   153,
     154,   155,   156,    -1,   158,   159,   160,   161,   162,   163,
     164,    -1,    -1,    -1,   168,    -1,    -1,    -1,   172,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,    -1,    -1,    -1,
      -1,   263,    -1,   197,    -1,    -1,    -1,   269,    -1,    -1,
      -1,   273,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   215,    -1,    -1,    -1,   219,   220,    -1,    -1,    -1,
      -1,   225,   226,   227,    -1,   229,   230,   231,    -1,    -1,
      -1,   235,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   252,   253,
      -1,    -1,    -1,    -1,    -1,   259,     3,     4,    -1,    -1,
     264,     8,    -1,    10,    11,    12,    -1,   271,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    59,    60,    61,    62,    -1,    -1,    -1,    -1,
      67,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      77,    78,    79,    -1,    -1,    -1,    83,    84,    85,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,    95,    -1,
      97,    -1,    -1,    -1,    -1,    -1,   103,    -1,    -1,   106,
      -1,    -1,   109,    -1,   111,    -1,    -1,    -1,    -1,    -1,
      -1,   118,    -1,    -1,    -1,   122,   123,   124,    -1,    -1,
     127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   136,
      -1,   138,   139,    -1,   141,    -1,   143,    -1,    -1,   146,
      -1,    -1,    -1,    -1,    -1,   152,   153,   154,   155,   156,
      -1,   158,   159,   160,   161,   162,   163,   164,    -1,    -1,
      -1,   168,    -1,    -1,    -1,   172,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,    -1,    -1,    -1,    -1,   263,    -1,
     197,    -1,    -1,    -1,   269,    -1,    -1,    -1,   273,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   215,    -1,
      -1,    -1,   219,   220,    -1,    -1,    -1,    -1,   225,   226,
     227,    -1,   229,   230,   231,    -1,    -1,    -1,   235,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   252,   253,    -1,    -1,    -1,
      -1,    -1,   259,     3,     4,    -1,    -1,   264,    -1,    -1,
      10,    11,    12,    -1,   271,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,
      60,    61,    62,    -1,    -1,    -1,    -1,    67,    68,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,    78,    79,
      -1,    -1,    -1,    83,    84,    85,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    94,    95,    -1,    97,    -1,    -1,
      -1,    -1,    -1,   103,    -1,    -1,   106,    -1,    -1,   109,
      -1,   111,    -1,    -1,    -1,    -1,    -1,    -1,   118,    -1,
      -1,    -1,   122,   123,   124,    -1,    -1,   127,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   136,    -1,   138,   139,
      -1,   141,    -1,   143,    -1,    -1,   146,    -1,    -1,    -1,
      -1,    -1,   152,   153,   154,   155,   156,    -1,   158,   159,
     160,   161,   162,   163,   164,    -1,    -1,    -1,   168,    -1,
      -1,    -1,   172,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,    -1,    -1,    -1,    -1,   263,    -1,   197,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   273,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   215,    -1,    -1,    -1,   219,
     220,    -1,    -1,    -1,    -1,   225,   226,   227,    -1,   229,
     230,   231,    -1,    -1,    -1,   235,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   252,   253,    -1,    -1,    -1,    -1,    -1,   259,
      -1,    -1,    -1,    -1,   264,     3,     4,    -1,   268,    -1,
      -1,   271,    10,    11,    12,    -1,    -1,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    59,    60,    61,    62,    -1,    -1,    -1,    -1,    67,
      68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,
      78,    79,    -1,    -1,    -1,    83,    84,    85,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    94,    95,    -1,    97,
      -1,    -1,    -1,    -1,    -1,   103,    -1,    -1,   106,    -1,
      -1,   109,    -1,   111,    -1,    -1,    -1,    -1,    -1,    -1,
     118,    -1,    -1,    -1,   122,   123,   124,    -1,    -1,   127,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   136,    -1,
     138,   139,    -1,   141,    -1,   143,    -1,    -1,   146,    -1,
      -1,    -1,    -1,    -1,   152,   153,   154,   155,   156,    -1,
     158,   159,   160,   161,   162,   163,   164,    -1,    -1,    -1,
     168,    -1,    -1,    -1,   172,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,    -1,    -1,    -1,    -1,   263,    -1,   197,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   273,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   215,    -1,    -1,
      -1,   219,   220,    -1,    -1,    -1,    -1,   225,   226,   227,
      -1,   229,   230,   231,    -1,    -1,    -1,   235,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   252,   253,    -1,    -1,    -1,    -1,
      -1,   259,    -1,    -1,    -1,    -1,   264,     3,     4,    -1,
     268,    -1,    -1,   271,    10,    11,    12,    -1,    -1,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    59,    60,    61,    62,    -1,    -1,    -1,
      -1,    67,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    77,    78,    79,    -1,    -1,    -1,    83,    84,    85,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,    95,
      -1,    97,    -1,    -1,    -1,    -1,    -1,   103,    -1,    -1,
     106,    -1,    -1,   109,    -1,   111,    -1,    -1,    -1,    -1,
      -1,    -1,   118,    -1,    -1,    -1,   122,   123,   124,    -1,
      -1,   127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     136,    -1,   138,   139,    -1,   141,    -1,   143,    -1,    -1,
     146,    -1,    -1,    -1,    -1,    -1,   152,   153,   154,   155,
     156,    -1,   158,   159,   160,   161,   162,   163,   164,    -1,
      -1,    -1,   168,    -1,    -1,    -1,   172,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,    -1,    -1,    -1,    -1,   263,
      -1,   197,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   273,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   215,
      -1,    -1,    -1,   219,   220,    -1,    -1,    -1,    -1,   225,
     226,   227,    -1,   229,   230,   231,    -1,    -1,    -1,   235,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   252,   253,    -1,    -1,
      -1,    -1,    -1,   259,    -1,    -1,    -1,    -1,   264,     3,
       4,    -1,    -1,   269,    -1,   271,    10,    11,    12,    -1,
      -1,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    59,    60,    61,    62,    -1,
      -1,    -1,    -1,    67,    68,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    77,    78,    79,    -1,    -1,    -1,    83,
      84,    85,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      94,    95,    -1,    97,    -1,    -1,    -1,    -1,    -1,   103,
      -1,    -1,   106,    -1,    -1,   109,    -1,   111,    -1,    -1,
      -1,    -1,    -1,    -1,   118,    -1,    -1,    -1,   122,   123,
     124,    -1,    -1,   127,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   136,    -1,   138,   139,    -1,   141,    -1,   143,
      -1,    -1,   146,    -1,    -1,    -1,    -1,    -1,   152,   153,
     154,   155,   156,    -1,   158,   159,   160,   161,   162,   163,
     164,    -1,    -1,    -1,   168,    -1,    -1,    -1,   172,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,    -1,    -1,    -1,
      -1,   263,    -1,   197,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   273,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   215,    -1,    -1,    -1,   219,   220,    -1,    -1,    -1,
      -1,   225,   226,   227,    -1,   229,   230,   231,    -1,    -1,
      -1,   235,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   252,   253,
      -1,    -1,    -1,    -1,    -1,   259,     3,     4,     5,    -1,
     264,    -1,    -1,    10,    11,    12,    -1,   271,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    -1,    -1,    -1,    71,    72,    73,    74,    -1,    -1,
      -1,    -1,    -1,    80,    -1,    82,    83,    84,    85,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,    95,    96,
      97,    -1,    99,     3,     4,     5,    -1,    -1,    -1,    -1,
      10,    11,    12,    -1,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    -1,    -1,
      -1,    71,    72,    73,    74,    -1,    -1,    -1,    -1,    -1,
      80,    -1,    82,    83,    84,    85,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    94,    95,    96,    97,    -1,    99,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   215,   216,
     217,   218,   219,    -1,    -1,    -1,    -1,    -1,   225,   226,
     227,   228,   229,   230,   231,   232,    -1,   234,   235,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   252,   253,    -1,    -1,    -1,
      -1,    -1,   259,    -1,    -1,    -1,    -1,   264,    -1,    -1,
      -1,   268,    -1,    -1,   271,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,    -1,    -1,    -1,    -1,   263,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   273,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   215,   216,   217,   218,   219,
      -1,    -1,    -1,    -1,    -1,   225,   226,   227,   228,   229,
     230,   231,   232,    -1,   234,   235,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   252,   253,    -1,    -1,    -1,    -1,    -1,   259,
      -1,    -1,    -1,    -1,   264,     3,     4,     5,   268,    -1,
      -1,   271,    10,    11,    12,    -1,    -1,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      -1,    -1,    -1,    71,    72,    73,    74,    -1,    -1,    -1,
      -1,    -1,    80,    -1,    82,    83,    84,    85,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    94,    95,    96,    97,
      -1,    99,     3,     4,    -1,     6,    -1,    -1,    -1,    10,
      11,    12,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,    60,
      61,    62,    -1,    -1,    -1,    -1,    67,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    83,    84,    85,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    94,    95,    -1,    97,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   215,   216,   217,
     218,   219,    -1,    -1,    -1,    -1,    -1,   225,   226,   227,
     228,   229,   230,   231,   232,    -1,   234,   235,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   252,   253,    -1,    -1,    -1,    -1,
      -1,   259,    -1,     3,     4,    -1,   264,    -1,    -1,    -1,
      10,    11,    12,   271,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   215,    -1,    -1,    -1,   219,    59,
      60,    61,    62,    -1,   225,   226,   227,    67,   229,   230,
     231,    -1,    -1,    -1,   235,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    83,    84,    85,    -1,    -1,    -1,    -1,
      -1,   252,   253,    -1,    94,    95,    -1,    97,   259,     3,
       4,    -1,    -1,   264,    -1,    -1,    10,    11,    12,    -1,
     271,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    13,
      14,    -1,    -1,    -1,    -1,    59,    60,    61,    62,    -1,
      -1,    -1,    -1,    67,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    83,
      84,    85,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      94,    95,    -1,    97,    -1,    -1,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,    -1,   215,    -1,    -1,   263,   219,
      -1,    -1,    -1,    -1,    -1,   225,   226,   227,   273,   229,
     230,   231,    -1,    -1,    -1,   235,    -1,    -1,    -1,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   252,   253,    -1,   119,   120,   121,   122,   259,
      -1,    -1,    -1,   127,   264,    -1,    -1,    -1,   268,    -1,
      -1,   271,   136,   137,    -1,    -1,   140,   141,    -1,   143,
     144,    -1,   146,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   165,    -1,    -1,    -1,   263,    -1,    -1,    -1,    -1,
     268,   215,    -1,    -1,    -1,   219,    -1,    -1,    -1,    -1,
      -1,   225,   226,   227,    -1,   229,   230,   231,   192,   193,
     194,   235,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   252,   253,
      -1,    -1,    -1,    -1,    -1,   259,    -1,    -1,    -1,    -1,
     264,     3,     4,    -1,   268,    -1,     8,   271,    10,    11,
      12,    -1,    -1,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      -1,    -1,    -1,    -1,    -1,   269,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,    60,    61,
      62,    -1,    -1,    -1,    -1,    67,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    83,    84,    85,    -1,    -1,    -1,    -1,    -1,     3,
       4,    -1,    94,    95,    -1,    97,    10,    11,    12,    -1,
      -1,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    59,    60,    61,    62,    -1,
      -1,    -1,    -1,    67,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    83,
      84,    85,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      94,    95,    -1,    97,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,    -1,    -1,    -1,    -1,   263,    -1,    -1,    -1,
      -1,    -1,    -1,   215,    -1,    -1,   273,   219,    -1,    -1,
      -1,    -1,    -1,   225,   226,   227,    -1,   229,   230,   231,
      -1,    -1,    -1,   235,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     252,   253,    -1,    -1,    -1,    -1,    -1,   259,    -1,    -1,
      -1,    -1,   264,    -1,    -1,    -1,    -1,    -1,    -1,   271,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,    -1,    -1,
      -1,    -1,   263,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   215,   273,    -1,    -1,   219,    -1,    -1,    -1,    -1,
      -1,   225,   226,   227,    -1,   229,   230,   231,    -1,    -1,
      -1,   235,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   252,   253,
      -1,    -1,    -1,    -1,    -1,   259,     3,     4,    -1,     6,
     264,   265,    -1,    10,    11,    12,    -1,   271,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    59,    60,    61,    62,    -1,    -1,    -1,    -1,
      67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    83,    84,    85,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,    95,    -1,
      97,     3,     4,    -1,     6,    -1,    -1,    -1,    10,    11,
      12,    -1,    -1,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,    60,    61,
      62,    -1,    -1,    -1,    -1,    67,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    83,    84,    85,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    94,    95,    -1,    97,    -1,    -1,    -1,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,    -1,   215,    -1,
      -1,   263,   219,    -1,    -1,    -1,    -1,    -1,   225,   226,
     227,   273,   229,   230,   231,    -1,    -1,    -1,   235,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   252,   253,    -1,    -1,    -1,
      -1,    -1,   259,    -1,    -1,    -1,    -1,   264,    -1,    -1,
      -1,    -1,    -1,    -1,   271,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,    -1,    -1,    -1,    -1,   263,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   273,    -1,    -1,
      -1,    -1,    -1,   215,    -1,    -1,    -1,   219,    -1,    -1,
      -1,    -1,    -1,   225,   226,   227,    -1,   229,   230,   231,
      -1,    -1,    -1,   235,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     252,   253,    -1,    -1,    -1,    -1,    -1,   259,     3,     4,
      -1,     6,   264,    -1,    -1,    10,    11,    12,    -1,   271,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    59,    60,    61,    62,    -1,    -1,
      -1,    -1,    67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    83,    84,
      85,    -1,    -1,    -1,    -1,    -1,     3,     4,    -1,    94,
      95,    -1,    97,    10,    11,    12,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    59,    60,    61,    62,    -1,    -1,    -1,    -1,
      67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    83,    84,    85,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,    95,    -1,
      97,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,    -1,
      -1,    -1,    -1,   263,    -1,    -1,    -1,    -1,    -1,    -1,
     215,    -1,    -1,   273,   219,    -1,    -1,    -1,    -1,    -1,
     225,   226,   227,    -1,   229,   230,   231,    -1,    -1,    -1,
     235,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   252,   253,    -1,
      -1,    -1,    -1,    -1,   259,    -1,    -1,    -1,    -1,   264,
      -1,    -1,    -1,    -1,    -1,    -1,   271,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,    -1,    -1,    -1,    -1,   263,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   215,   273,
      -1,    -1,   219,    -1,    -1,    -1,    -1,    -1,   225,   226,
     227,    -1,   229,   230,   231,    -1,    -1,    -1,   235,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   252,   253,    -1,    -1,    -1,
      -1,    -1,   259,     3,     4,    -1,    -1,   264,   265,    -1,
      10,    11,    12,    -1,   271,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,
      60,    61,    62,    -1,    -1,    -1,    -1,    67,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    83,    84,    85,    -1,    -1,    -1,    -1,
      -1,     3,     4,    -1,    94,    95,    -1,    97,    10,    11,
      12,    -1,    -1,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,    60,    61,
      62,    -1,    -1,    -1,    -1,    67,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    83,    84,    85,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    94,    95,    -1,    97,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,    -1,    -1,    -1,    -1,   263,    -1,
      -1,    -1,    -1,    -1,    -1,   215,    -1,    -1,   273,   219,
      -1,    -1,    -1,    -1,    -1,   225,   226,   227,    -1,   229,
     230,   231,    -1,    -1,    -1,   235,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   252,   253,    -1,    -1,    -1,    -1,    -1,   259,
      -1,    -1,    -1,    -1,   264,   265,    -1,    -1,    -1,    -1,
      -1,   271,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
      -1,    -1,    -1,    -1,   263,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   215,   273,    -1,    -1,   219,    -1,    -1,
      -1,    -1,    -1,   225,   226,   227,    -1,   229,   230,   231,
      -1,    -1,    -1,   235,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     252,   253,    -1,    -1,    -1,    -1,    -1,   259,    -1,    -1,
      -1,    -1,   264,     3,     4,    -1,   268,    -1,    -1,   271,
      10,    11,    12,    -1,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,
      60,    61,    62,    -1,    -1,    -1,    -1,    67,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    83,    84,    85,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    94,    95,    -1,    97,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,    -1,    -1,    -1,    -1,
     263,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     273,    -1,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,    -1,    -1,    -1,   119,   120,
     121,   122,    -1,    -1,    -1,    -1,   127,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   136,   137,    -1,    -1,   140,
     141,    -1,   143,   144,    -1,   146,    -1,    -1,    -1,    -1,
      -1,    -1,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   165,    -1,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,    -1,   215,    -1,    -1,   263,   219,
      -1,   192,   193,   194,    -1,   225,   226,   227,   273,   229,
     230,   231,    -1,    -1,    -1,   235,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    13,    14,    -1,    -1,    -1,
      -1,    -1,   252,   253,    -1,    -1,    -1,    -1,    -1,   259,
      -1,    -1,    -1,    -1,   264,    -1,    -1,    -1,    -1,    -1,
      -1,   271,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,    -1,    -1,    -1,   119,   120,
     121,   122,    -1,    -1,    -1,    -1,   127,    -1,   269,    -1,
      -1,    -1,    -1,    -1,    -1,   136,   137,    -1,    -1,   140,
     141,    -1,   143,   144,    -1,   146,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   165,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,    -1,    -1,
      -1,   119,   120,   121,   122,    13,    14,    -1,    -1,   127,
      -1,   192,   193,   194,    -1,    -1,    -1,    -1,   136,   137,
      -1,    -1,   140,   141,    -1,   143,   144,    -1,   146,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   165,    -1,    -1,
      -1,   263,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   273,    -1,    -1,    -1,    -1,    -1,    -1,    13,    14,
      -1,    -1,    -1,    -1,   192,   193,   194,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   269,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,    -1,    -1,
      -1,   119,   120,   121,   122,    -1,    -1,    -1,    -1,   127,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   136,   137,
      -1,    -1,   140,   141,    -1,   143,   144,    -1,   146,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   269,    -1,    -1,    -1,    -1,    -1,   165,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,    -1,    -1,    -1,   119,   120,   121,   122,    13,    14,
      -1,    -1,   127,    -1,   192,   193,   194,    -1,    -1,    -1,
      -1,   136,   137,    -1,    -1,   140,   141,    -1,   143,   144,
      -1,   146,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     165,    -1,    -1,    -1,   263,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   273,    -1,    -1,    -1,    -1,    -1,
      -1,    13,    14,    -1,    -1,    -1,    -1,   192,   193,   194,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   269,    -1,    -1,    -1,    -1,    -1,    -1,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,    -1,    -1,    -1,   119,   120,   121,   122,    -1,    -1,
      -1,    -1,   127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   136,   137,    -1,    -1,   140,   141,    -1,   143,   144,
      -1,   146,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   269,    -1,    -1,    -1,    -1,    -1,
     165,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,    -1,    -1,    -1,   119,   120,   121,
     122,    13,    14,    -1,    -1,   127,    -1,   192,   193,   194,
      -1,    -1,    -1,    -1,   136,   137,    -1,    -1,   140,   141,
      -1,   143,   144,    -1,   146,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   165,    -1,    -1,    -1,   263,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   273,    -1,    -1,
      -1,    -1,    -1,    -1,    13,    14,    -1,    -1,    -1,    -1,
     192,   193,   194,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   269,    -1,    -1,    -1,    -1,    -1,
      -1,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,    -1,    -1,    -1,   119,   120,   121,
     122,    -1,    -1,    -1,    -1,   127,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   136,   137,    -1,    -1,   140,   141,
      -1,   143,   144,    -1,   146,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   269,    -1,    -1,
      -1,    -1,    -1,   165,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,    -1,    -1,    -1,
     119,   120,   121,   122,    13,    14,    -1,    -1,   127,    -1,
     192,   193,   194,    -1,    -1,    -1,    -1,   136,   137,    -1,
      -1,   140,   141,    -1,   143,   144,    -1,   146,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   165,    -1,    -1,    -1,
     263,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     273,    -1,    -1,    -1,    -1,    -1,    -1,    13,    14,    -1,
      -1,    -1,    -1,   192,   193,   194,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   269,    -1,    -1,
      -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,    -1,    -1,    -1,
     119,   120,   121,   122,    -1,    -1,    -1,    -1,   127,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   136,   137,    -1,
      -1,   140,   141,    -1,   143,   144,    -1,   146,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     269,    -1,    -1,    -1,    -1,    -1,   165,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
      -1,    -1,    -1,   119,   120,   121,   122,    -1,    -1,    -1,
      -1,   127,    -1,   192,   193,   194,    -1,    -1,    -1,    -1,
     136,   137,    -1,    -1,   140,   141,    -1,   143,   144,    -1,
     146,    -1,    -1,    -1,    -1,    -1,    -1,     0,     1,    -1,
      -1,     4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   165,
      13,    14,    -1,    -1,    -1,    -1,    -1,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,    -1,   192,   193,   194,   263,
      -1,    -1,    -1,    -1,    47,    48,    49,    -1,    -1,   273,
     269,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    68,    69,    70,    -1,    -1,
      -1,    -1,    75,    76,    -1,    -1,    -1,    -1,    81,    -1,
      -1,    -1,    -1,    86,    87,    88,    89,    90,    -1,    92,
      93,    -1,    95,    -1,    -1,    -1,    -1,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   269,    -1,   118,   119,   120,   121,   122,
      -1,    -1,   125,    -1,   127,    -1,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,    -1,    -1,   148,   149,   150,    -1,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,    -1,    -1,    -1,   180,   181,   182,
      -1,    -1,    -1,   186,    -1,    -1,    -1,    -1,   191,   192,
     193,   194,    -1,    -1,   197,    -1,   199,    -1,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,    -1,     4,    -1,    -1,    -1,    -1,   221,   222,
     223,   224,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,
     233,    -1,   235,   236,    -1,    -1,    -1,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,    -1,    47,    48,    49,   263,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   273,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    68,    69,    70,
      -1,    -1,    -1,    -1,    75,    76,    -1,    -1,    -1,    -1,
      81,    -1,    -1,    -1,    -1,    86,    87,    88,    89,    90,
      -1,    92,    93,    -1,    95,    -1,    -1,    -1,    -1,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,    -1,    -1,   118,   119,   120,
     121,   122,    -1,    -1,   125,    -1,   127,    -1,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,    -1,    -1,   148,   149,   150,
      -1,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,    -1,    -1,    -1,   180,
     181,   182,    -1,    -1,    -1,   186,    -1,    -1,    -1,    -1,
     191,   192,   193,   194,     4,     5,   197,    -1,   199,    -1,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,    -1,    -1,    -1,    -1,    -1,    -1,
     221,   222,   223,   224,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   233,    -1,   235,   236,    -1,    -1,    -1,    -1,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    -1,
      -1,    -1,    -1,    63,    64,    65,    66,    -1,    -1,    -1,
      -1,    71,    72,    73,    74,    -1,    -1,     4,     5,    -1,
      80,    -1,    82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    96,    -1,    -1,    99,
      -1,    -1,    -1,   103,    -1,    -1,   106,    -1,    -1,   109,
      -1,   111,    -1,    -1,     4,     5,    -1,    -1,    -1,    -1,
      -1,    -1,   122,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    -1,    -1,    -1,    -1,    63,    64,    65,    66,
      -1,    -1,    -1,   143,    71,    72,    73,    74,    -1,    -1,
      -1,    -1,    -1,    80,    -1,    82,    -1,    -1,    -1,    -1,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    96,
      -1,    -1,    99,    63,    64,    65,    66,    -1,    -1,    -1,
      -1,    71,    72,    73,    74,    -1,    -1,    -1,    -1,    -1,
      80,     5,    82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    96,    -1,    -1,    99,
      -1,    -1,    -1,    -1,    -1,    -1,   216,   217,   218,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   228,    -1,
      -1,    -1,   232,    -1,   234,   235,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    -1,    -1,    -1,    -1,    63,
      64,    65,    66,    -1,    -1,    13,    14,    71,    72,    73,
      74,    -1,    -1,    -1,    -1,    -1,    80,    -1,    82,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    96,    -1,    -1,    99,    -1,    -1,    -1,   216,
     217,   218,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   228,    -1,    -1,    -1,   232,    -1,   234,   235,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   216,   217,   218,    -1,
      -1,    13,    14,    -1,    -1,    -1,    -1,    -1,   228,    -1,
      -1,    -1,   232,    -1,   234,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,    -1,    -1,
      -1,   119,   120,   121,   122,    -1,    -1,    -1,    -1,   127,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   136,   137,
      -1,    -1,   140,   141,    -1,   143,   144,    -1,   146,    -1,
      -1,    -1,   150,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   216,   217,   218,    -1,    -1,   165,    -1,    -1,
      -1,   169,    -1,    -1,   228,    -1,    -1,    -1,   232,    -1,
     234,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   192,   193,   194,   119,   120,   121,
     122,    -1,    -1,    -1,    -1,   127,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   136,   137,    -1,    -1,   140,   141,
      -1,   143,   144,    -1,   146,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   165,    -1,    -1,    -1,   263,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   273,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     192,   193,   194,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,    -1,    -1,    -1,    -1,   263,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   273,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,    -1,    -1,    -1,    -1,   263,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   273,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,    -1,    -1,    -1,
      -1,   263,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   273,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
      -1,    -1,    -1,    -1,   263,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   273,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,    -1,    -1,    -1,    -1,   263,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   273,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,    -1,    -1,    -1,    -1,
     263,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     273,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,    -1,
      -1,    -1,    -1,   263,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   273,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,    -1,    -1,    -1,    -1,   263,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   273,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,    -1,    -1,    -1,    -1,   263,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   273,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,    -1,    -1,
      -1,    -1,   263,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   273,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,    -1,    -1,    -1,    -1,   263,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   273,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,    -1,    -1,    -1,    -1,   263,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   273,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,    -1,    -1,    -1,
      -1,   263,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   273,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
      -1,    -1,    -1,    -1,   263,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   273,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,    -1,    -1,    -1,    -1,   263,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   273,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,    -1,    -1,    -1,    -1,
     263,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     273,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,    -1,
      -1,    -1,    -1,   263,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   273,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,    -1,    -1,    -1,    -1,   263,    -1,    -1,    -1,
      -1,    -1,   269,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,    -1,    -1,    -1,    -1,   263,    -1,    -1,    -1,    -1,
      -1,   269,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
      -1,    -1,    -1,    -1,   263,    -1,    -1,    -1,    -1,    -1,
     269,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,    -1,
      -1,    -1,    -1,   263,    -1,    -1,    -1,    -1,    -1,   269,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,    -1,    -1,
      -1,    -1,   263,    -1,    -1,    -1,    -1,    -1,   269,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,    -1,    -1,    -1,
      -1,   263,    -1,    -1,    -1,    -1,    -1,   269,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,    -1,    -1,    -1,    -1,
     263,    -1,    -1,    -1,    -1,    -1,   269,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,    -1,    -1,    -1,    -1,   263,
      -1,    -1,    -1,    -1,    -1,   269,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,    -1,    -1,    -1,    -1,   263,    -1,
      -1,    -1,    -1,    -1,   269,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,    -1,    -1,    -1,    -1,   263,    -1,    -1,
      -1,    -1,    -1,   269,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,    -1,    -1,    -1,    -1,   263,    -1,    -1,    -1,
      -1,    -1,   269,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,    -1,    -1,    -1,    -1,   263,    -1,    -1,    -1,    -1,
      -1,   269,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
      -1,    -1,    -1,    -1,   263,    -1,    -1,    -1,    -1,    -1,
     269,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,    -1,
      -1,    -1,    -1,   263,    -1,    -1,    -1,    -1,    -1,   269,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,    -1,    -1,
      -1,    -1,   263,    -1,    -1,    -1,    -1,    -1,   269,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,    -1,    -1,    -1,
      -1,   263,    -1,    -1,    -1,    -1,    -1,   269,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,    -1,    -1,    -1,    -1,
     263,    -1,    -1,    -1,    -1,    -1,   269,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,    -1,    -1,    -1,    -1,   263,
      -1,    -1,    -1,    -1,    -1,   269,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,    -1,    -1,    -1,    -1,   263,    -1,
      -1,    -1,    -1,    -1,   269,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,    -1,    -1,    -1,    -1,   263,    -1,    -1,
      -1,    -1,    -1,   269,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,    -1,    -1,    -1,    -1,   263,    -1,    -1,    -1,
      -1,    -1,   269,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,    -1,    -1,    -1,    -1,   263,    -1,    -1,    -1,    -1,
      -1,   269,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
      -1,    -1,    -1,    -1,   263,    -1,    -1,    -1,    -1,    -1,
     269,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,    -1,
      -1,    -1,    -1,   263,    -1,    -1,    -1,    -1,    -1,   269,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,    -1,    -1,
      -1,    -1,   263,    -1,    -1,    -1,    -1,    -1,   269,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,    -1,    -1,    -1,
      -1,   263,    -1,    -1,    -1,    -1,    -1,   269,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,    -1,    -1,    -1,    -1,
     263,    -1,    -1,    -1,    -1,    -1,   269,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,    -1,    -1,    -1,    -1,   263,
      -1,    -1,    -1,    -1,    -1,   269,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,    -1,    -1,    -1,    -1,   263,    -1,
      -1,    -1,    -1,    -1,   269,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,    -1,    -1,    -1,    -1,   263,    -1,    -1,
      -1,    -1,    -1,   269,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,    -1,    -1,    -1,    -1,   263,    -1,    -1,    -1,
      -1,    -1,   269,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,    -1,    -1,    -1,    -1,   263,    -1,    -1,    -1,    -1,
      -1,   269,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
      -1,    -1,    -1,    -1,   263,    -1,    -1,    -1,    -1,    -1,
     269,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,    -1,
      -1,    -1,    -1,   263,    -1,    -1,    -1,    -1,    -1,   269,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,    -1,    -1,
      -1,    -1,   263,    -1,    -1,    -1,    -1,    -1,   269,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,    -1,    -1,    -1,
      -1,   263,    -1,    -1,    -1,    -1,    -1,   269,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,    -1,    -1,    -1,    -1,
     263,    -1,    -1,    -1,    -1,    -1,   269,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,    -1,    -1,    -1,    -1,   263,
      -1,    -1,    -1,    -1,    -1,   269,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,    -1,    -1,    -1,    -1,   263,    -1,
      -1,    -1,    -1,    -1,   269,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,    -1,    -1,    -1,    -1,   263,    -1,    -1,
      -1,    -1,    -1,   269,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,    -1,    -1,    -1,    -1,   263,    -1,    -1,    -1,
      -1,    -1,   269,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,    -1,    -1,    -1,    -1,   263,    -1,    -1,    -1,    -1,
      -1,   269,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
      -1,    -1,    -1,    -1,   263,    -1,    -1,    -1,    -1,    -1,
     269,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,    -1,
      -1,    -1,    -1,   263,    -1,    -1,    -1,    -1,   268,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,    -1,    -1,    -1,
      -1,   263,    -1,    -1,    -1,    -1,   268,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,    -1,    -1,    -1,    -1,   263,
      -1,   265,    -1,   267,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,    -1,    -1,    -1,    -1,   263,    -1,    -1,    -1,
     267,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,    -1,
      -1,    -1,    -1,   263,    -1,    -1,    -1,   267,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,    -1,    -1,    -1,    -1,
     263,    -1,    -1,    -1,   267,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,    -1,    -1,    -1,    -1,   263,    -1,    -1,
      -1,   267,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
      -1,    -1,    -1,    -1,   263,    -1,    -1,    -1,   267,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,    -1,    -1,    -1,
      -1,   263,    -1,    -1,    -1,   267,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,    -1,    -1,    -1,    -1,   263,    -1,
      -1,    -1,   267,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,    -1,    -1,    -1,    -1,   263,    -1,    -1,    -1,   267,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,    -1,    -1,
      -1,    -1,   263,    -1,    -1,    -1,   267,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,    -1,    -1,    -1,    -1,   263,
      -1,    -1,    -1,   267,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,    -1,    -1,    -1,    -1,   263,    -1,    -1,    -1,
     267,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,    -1,
      -1,    -1,    -1,   263,    -1,    -1,    -1,   267,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,    -1,    -1,    -1,    -1,
     263,    -1,    -1,    -1,   267,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,    -1,    -1,    -1,    -1,   263,    -1,    -1,
      -1,   267,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
      -1,    -1,    -1,    -1,   263,    -1,    -1,    -1,   267,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,    -1,    -1,    -1,
      -1,   263,    -1,   265,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,    -1,    -1,    -1,    -1,   263,    -1,   265,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,    -1,    -1,    -1,
      -1,   263,    -1,   265,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,    -1,    -1,    -1,    -1,   263,    -1,   265,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,    -1,    -1,    -1,
      -1,   263,    -1,   265,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,    -1,    -1,    -1,    -1,   263,    -1,   265,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,    -1,    -1,    -1,
      -1,   263,    -1,   265,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,    -1,    -1,    -1,    -1,   263,    -1,   265,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,    -1,    -1,    -1,
      -1,   263,    -1,   265,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,    -1,    -1,    -1,    -1,   263,    -1,   265,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,    -1,    -1,    -1,
      -1,   263,    -1,   265,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,    -1,    -1,    -1,    -1,   263,    -1,   265,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,    -1,    -1,    -1,
      -1,   263,    -1,   265,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,    -1,    -1,    -1,    -1,   263,    -1,   265,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,    -1,    -1,    -1,
      -1,   263,    -1,   265,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,    -1,    -1,    -1,    -1,   263,    -1,   265,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,    -1,    -1,    -1,
      -1,   263,    -1,   265,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,    -1,    -1,    -1,    -1,   263,    -1,   265,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,    -1,    -1,    -1,
      -1,   263,    -1,   265,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,    -1,    -1,    -1,    -1,   263,    -1,   265,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,    -1,    -1,    -1,
      -1,   263,    -1,   265,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,    -1,    -1,    -1,    -1,   263,    -1,   265,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,    -1,    -1,    -1,
      -1,   263,    -1,   265,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,    -1,    -1,    -1,    -1,   263,    -1,   265,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,    -1,    -1,    -1,
      -1,   263,    -1,   265,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,    -1,    -1,    -1,    -1,   263,    -1,   265,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,    -1,    -1,    -1,
      -1,   263,    -1,   265,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,    -1,    -1,    -1,    -1,   263,    -1,   265,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,    -1,    -1,    -1,
      -1,   263,    -1,   265,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,    -1,    -1,    -1,    -1,   263,    -1,   265,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,    -1,    -1,    -1,
      -1,   263,    -1,   265,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,    -1,    -1,    -1,    -1,   263,    -1,   265,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,    -1,    -1,    -1,
      -1,   263,    -1,   265,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,    -1,    -1,    -1,    -1,   263,    -1,   265,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,    -1,    -1,    -1,
      -1,   263,    -1,   265,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,    -1,    -1,    -1,    -1,   263,    -1,   265,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,    -1,    -1,    -1,
      -1,   263,    -1,   265,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,    -1,    -1,    -1,    -1,   263,    -1,   265,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,    -1,    -1,    -1,
      -1,   263,    -1,   265,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,    -1,    -1,    -1,    -1,   263,    -1,   265,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,    -1,    -1,    -1,
      -1,   263,    -1,   265,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,    -1,    -1,    -1,    -1,   263,    -1,   265,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,    -1,    -1,    -1,
      -1,   263,    -1,   265,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,    -1,    -1,    -1,    -1,   263,    -1,   265,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,    -1,    -1,    -1,
      -1,   263,    -1,   265,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,    -1,    -1,    -1,    -1,   263,    -1,   265,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,    -1,    -1,    -1,
      -1,   263,    -1,   265,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,    -1,    -1,    -1,    -1,   263,    -1,   265,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,    -1,    -1,    -1,
      -1,   263,    -1,   265,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,    -1,    -1,    -1,    -1,   263,    -1,   265,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,    -1,    -1,    -1,
      -1,   263,    -1,   265,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,    -1,    -1,    -1,    -1,   263,    -1,   265,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,    -1,    -1,    -1,
      -1,   263,    -1,   265,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,    -1,    -1,    -1,    -1,   263,    -1,   265,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,    -1,    -1,    -1,
      -1,   263,    -1,   265,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,    -1,    -1,    -1,    -1,   263,    -1,   265,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,    -1,    -1,    -1,
      -1,   263,    -1,   265,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,    -1,    -1,    -1,    -1,   263,    -1,   265,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,    -1,    -1,    -1,
      -1,   263,    -1,   265,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,    -1,    -1,    -1,    -1,   263,    -1,   265,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,    -1,    -1,    -1,
      -1,   263,    -1,   265,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,    -1,    -1,    -1,    -1,   263,    -1,   265,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,    -1,    -1,    -1,
      -1,   263,    -1,   265,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,    -1,    -1,    -1,    -1,   263,    -1,   265,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,    -1,    -1,    -1,
      -1,   263,    -1,   265,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,    -1,    -1,    -1,    -1,   263,    -1,   265,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,    -1,    -1,    -1,
      -1,   263,    -1,   265,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,    -1,    -1,    -1,    -1,   263
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,   275,   276,     6,     0,     4,    13,    14,    47,
      48,    49,    68,    69,    70,    75,    76,    81,    86,    87,
      88,    89,    90,    92,    93,    95,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   118,   119,   120,   121,   122,   125,   127,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   148,   149,   150,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   180,   181,   182,   186,   191,   192,
     193,   194,   197,   199,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   221,   222,
     223,   224,   233,   235,   236,   277,   279,   280,   301,   320,
     322,   326,   329,   330,   331,   332,   333,   334,   335,   336,
     337,   344,   346,   347,   353,   354,   355,   356,   362,   387,
     388,   268,   272,    14,   109,   264,   264,   264,     6,   268,
       6,     6,     6,     6,   264,     6,   268,     6,   268,   268,
       6,     6,   266,   266,     4,   364,   388,   264,   266,   298,
     103,   106,   109,   111,   322,   298,   264,   264,   264,     4,
     264,   264,   264,     4,   264,   264,   264,   264,   264,   264,
     264,   264,   264,   264,   264,   268,   126,   109,     6,     6,
     268,   268,   103,   106,   109,   122,   325,   111,   264,     3,
      10,    11,    12,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    59,    60,    61,    62,    67,
      68,    77,    78,    79,    83,    84,    85,    94,    97,   103,
     106,   109,   111,   122,   123,   124,   127,   136,   141,   143,
     146,   197,   215,   219,   220,   225,   226,   227,   229,   230,
     231,   252,   253,   259,   264,   268,   271,   322,   323,   326,
     337,   344,   346,   357,   358,   362,   364,   370,   373,   388,
     264,   268,   268,   109,   109,   136,   106,   109,   111,   322,
     106,   109,   110,   111,   122,   192,   323,   106,   109,   264,
     106,   169,   197,   213,   214,   268,   252,   253,   264,   268,
     367,   368,   367,   268,   268,   367,     4,   103,   107,   113,
     114,   116,   117,   140,   268,   268,   264,   109,   111,   109,
     106,     4,    95,   208,   268,   388,     4,     6,   103,     6,
     106,   109,   106,   109,   122,   324,     5,   264,   268,   370,
     372,   109,     4,     4,     4,   372,     4,   109,   264,   109,
     264,   264,     4,   268,   375,   388,     4,   264,   264,   264,
       6,    33,   253,   357,   388,     6,   266,     5,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    63,    64,    65,
      66,    71,    72,    73,    74,    80,    82,    96,    99,   216,
     217,   218,   228,   232,   234,   379,   388,   264,     4,   379,
       5,   268,     5,   268,   322,   357,   266,     6,   268,   264,
     268,     6,   264,   268,     6,   272,     7,   143,   208,   237,
     238,   239,   240,   261,   262,   264,   266,   270,   296,   297,
     298,   322,   357,   378,   379,   388,     4,   326,   327,   328,
     268,     6,   357,   378,   379,   388,   378,   378,   357,   378,
     385,   386,   388,   357,   328,   357,   303,   307,   264,   366,
       9,   379,   264,   379,   357,   357,   357,   264,   357,   357,
     357,   264,   357,   357,   357,   357,   357,   357,   357,   378,
     357,   357,   357,   357,   372,   264,   253,   357,   373,   374,
     374,   268,   372,   370,   378,   298,   298,   298,   298,   298,
     298,   298,   298,   298,   298,   298,   298,   298,   298,   298,
     298,   298,   298,   298,   298,   298,   298,   298,   298,   298,
     298,   264,   266,   298,   298,   298,   298,   298,   298,   264,
     298,   298,   264,   322,   323,   323,   323,   298,   298,     5,
     268,   268,   109,   106,   109,    68,   103,   136,   322,   322,
     323,   264,   298,   298,   264,   264,   264,   357,   268,   357,
     373,   357,   357,   269,   374,   364,   388,   200,     5,   268,
       8,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   263,
       9,   264,   266,   270,   297,   298,   357,   374,   374,   264,
     264,   264,   370,   372,   372,   372,   321,   264,   268,   264,
     264,   370,   268,   268,   357,     4,   370,   268,   375,   268,
     268,   367,   367,   367,   357,   357,   252,   253,   268,   268,
     367,   252,   253,   264,   328,   367,   268,   264,   268,   264,
     264,   264,   264,   264,   264,   264,   374,   374,   357,   372,
     372,   372,   264,   268,     4,   266,   268,     6,   266,   328,
       6,     6,   268,   268,   268,   268,   372,   357,     8,     7,
     268,   266,   266,   266,     6,     6,   264,   357,   264,   357,
     357,   270,   357,   268,   200,   357,   357,   357,   298,   357,
       6,   254,     9,   264,   266,   270,   357,   298,   298,   298,
     264,   264,   264,   298,   298,   298,   298,   298,   298,   298,
     298,   298,   298,   264,   264,   298,   264,   266,     6,     6,
     268,     6,     8,   328,     6,     8,   328,   264,   268,   378,
     374,   357,   328,   370,   370,   268,   379,   322,     7,   357,
     357,     4,    26,    37,    38,   112,   113,   197,   198,   300,
     370,     6,   265,   267,   268,   299,   268,     6,   268,     6,
       9,   264,   266,   270,   388,   269,   136,   141,   143,   144,
     146,   320,   322,   357,     6,   265,   273,     9,   264,   266,
     270,   265,   273,   265,   273,   273,   265,   273,     9,   264,
     270,   273,   269,   273,   267,   273,   302,   267,   302,    98,
     365,   363,   388,   273,   357,   273,   265,   265,   265,   357,
     265,   265,   265,   357,   265,   265,   265,   265,   265,   265,
     265,   265,   265,   265,   265,   269,     7,   357,   254,   269,
     273,   269,   357,     6,     6,   265,   357,   357,   357,   357,
     357,   357,   357,   357,   357,   357,   357,   357,   357,   357,
     357,   357,   357,   357,   373,   357,   357,   357,   357,   357,
     357,   357,   357,   357,   373,   373,   388,   268,   357,   357,
     378,   357,   378,   370,   378,   378,   385,   268,   268,   268,
     268,   357,   299,   388,     8,   357,   357,   268,   268,   268,
     324,   268,   372,   370,   268,   378,   378,   373,   364,   379,
     364,   374,   265,   269,   270,   298,    68,     8,   357,   357,
     357,   357,   357,   357,   357,   357,   357,   357,   357,   357,
     357,   357,   268,   357,   373,   357,   357,   357,   357,   357,
     388,   357,   357,   300,   268,   299,   265,   269,   269,   357,
     357,   357,     7,     7,   350,   350,   264,   357,   357,   357,
     357,     6,   173,   374,   374,   268,   265,     6,   328,   268,
     328,   328,   273,   273,   273,   367,   367,   327,   327,   273,
     357,   269,   341,   273,   328,   357,   357,   357,   357,   357,
     357,   357,   357,   357,   269,   269,   265,     7,   351,     6,
       7,   357,   357,     6,   357,   328,   357,   269,   374,   374,
     374,   357,     6,   265,   269,   357,   374,   357,   357,   357,
     357,   265,   357,   265,   265,   197,   273,   328,   268,     8,
     265,   265,   357,   357,   388,   300,   267,   385,   378,   385,
     378,   378,   378,   378,   378,   378,   357,   378,   378,   378,
     378,   271,   381,   388,   379,   378,   378,   378,   364,   388,
     374,   269,   269,   269,   269,   357,   328,   267,   269,   265,
     150,   169,   345,   265,   269,   273,   357,     6,   268,   370,
     265,   267,   270,     7,     7,   296,   297,     6,   374,     7,
     240,   296,   357,   281,   388,   357,   357,   300,   266,   264,
     136,   322,   323,   322,   268,   269,     6,   247,   248,   278,
     374,   388,   357,   357,   300,     6,   374,     6,   374,   357,
       6,   378,   386,   388,   265,   300,   357,   357,     6,   388,
       6,   378,   357,   265,   266,   357,   273,   379,     7,     7,
       7,   265,     7,     7,     7,   265,     7,     7,     7,     7,
       7,     7,     7,     7,     7,     7,   357,   265,   268,   357,
     373,     6,   268,   269,     6,   299,   299,   299,   299,   299,
     299,   299,   299,   299,   299,   299,   299,   273,   299,   299,
     299,   299,   299,   299,   299,   299,   299,   273,   273,   273,
     273,   273,   265,   267,   267,   374,   273,   273,   299,   273,
     299,   273,   273,   273,   265,   374,   357,   357,   357,   359,
     299,   269,   269,   269,   357,   357,   357,   268,   357,   357,
     273,   273,   299,   299,   265,   270,   265,   270,   273,   298,
     360,   269,     7,   300,   299,   370,   269,     8,     8,   374,
     270,   265,   267,   264,   266,   297,   298,   374,     7,   268,
     268,   265,   265,   265,   357,   370,     4,   349,     6,   316,
     357,   379,   265,   269,   265,   265,   357,   269,   269,   374,
     270,   269,   328,   269,   269,   367,   357,   357,   269,   269,
     357,   367,   147,   147,   166,   177,   178,   179,   183,   184,
     342,   343,   367,   269,   338,   265,   269,   265,   265,   265,
     265,   265,   265,   265,   268,   268,     7,   357,     6,   357,
     265,   269,   267,   269,   267,   269,   269,   269,   269,     6,
     269,   267,   267,   273,   265,     7,   265,     7,     7,   270,
     357,   269,   357,   357,   270,   264,   266,     7,   270,   299,
     273,   299,   299,   265,   265,   273,   299,   299,   273,   273,
     299,   299,   299,   299,   357,   299,     9,   380,   273,   265,
     273,   299,   270,   273,   361,   267,   269,   265,   269,   272,
     200,     7,   169,     6,   357,   269,   268,     6,   370,   269,
     357,     6,     7,   296,   297,   270,   296,   297,   300,   268,
     376,   388,   379,   357,     6,   269,    50,    50,   370,   269,
       4,   187,   188,   189,   190,   269,   284,   288,   291,   293,
     294,   336,   270,   265,   267,   264,   357,   357,   264,   268,
     264,   268,     8,   374,   378,   265,   270,   265,   267,   264,
     265,   265,   273,   270,   264,   269,   273,     7,   298,     4,
      26,    37,    38,   310,   311,   312,   299,   357,   299,   367,
     370,   370,     7,   370,   370,   370,     7,   370,   370,   370,
     370,   370,   370,   370,   370,   370,   370,     6,     7,   374,
     327,   357,   357,   357,   357,   357,   357,   269,   357,   357,
     357,   370,   378,   378,   269,   269,   269,   269,   273,   309,
     269,   269,   269,   357,   269,   269,   357,   357,   300,   300,
     357,   357,   265,   370,   298,   357,   357,   269,   300,   297,
     270,   297,   357,   357,   299,   269,   370,   374,   374,     7,
       7,     7,   147,   348,     6,   265,   273,     7,     7,     7,
       6,     7,     7,   269,     4,   300,   269,   273,   273,   273,
     269,   269,   121,     4,     6,   357,   268,     6,   264,     6,
     185,     6,   185,   269,   343,   273,   342,     7,     6,     7,
       7,     7,     7,     7,     7,     7,   327,   327,   370,     6,
     268,   103,     6,     6,     6,   109,     7,     7,     6,     6,
     357,     7,   370,     7,   370,   370,     4,   273,     8,     8,
     265,   300,   300,   300,   374,   378,   357,   378,   271,   273,
     313,   378,   378,   300,   378,   265,   273,     6,   268,   322,
     268,     6,   357,     6,   268,   370,   269,   269,   357,     6,
     197,   198,   300,   357,     6,     7,   375,   377,     6,   266,
       6,     6,   299,   298,   298,     6,   285,   264,   264,   268,
     295,     6,   300,   270,   378,   357,   267,   265,   357,     8,
     374,   357,   374,   269,   269,     6,     6,   278,   300,   270,
     357,     6,     6,   357,   300,   265,     6,   357,   268,   357,
     379,   299,    50,   268,   370,   379,   382,   357,   357,   357,
     267,   273,     6,   265,     6,     6,   140,   318,   318,   370,
       6,     6,     6,   370,   147,   200,   317,     6,     6,     6,
       6,     6,     6,     6,     6,     6,     5,   269,   269,   299,
     299,   299,   299,   299,   299,   299,   273,   273,   273,   265,
     299,   299,   311,   299,   127,   127,   127,   269,   200,   265,
     299,   265,   298,   360,   299,     6,   299,   264,   266,   298,
     300,   265,   267,   299,     6,   269,   269,   370,   370,   370,
       4,     6,   296,   357,   370,   370,   370,   268,   268,     7,
       6,     7,   357,   357,   357,   268,   268,   268,   266,     6,
     357,   370,   357,     6,     6,   357,   367,   269,     5,   370,
     268,   268,   268,   268,   268,   268,   268,   370,   269,   269,
       6,   374,   268,   268,   357,   357,   267,   370,     6,   370,
       6,   196,   357,   357,   357,   264,   266,     6,     6,     7,
     299,   273,   273,   299,   273,   357,     4,   212,   314,   315,
     299,   265,   299,   361,   379,   357,   268,   328,     6,   328,
     273,     6,     6,   270,     7,     7,   296,   297,     6,   375,
     269,   273,   357,   296,   268,   299,   383,   384,   385,   383,
     264,   357,   357,   369,   370,   268,   264,     4,     6,   265,
       6,   265,   269,   269,   265,   269,     6,     6,   378,   264,
       4,   265,   273,   264,   269,   273,   370,   379,     7,   298,
     308,   357,   373,   312,     6,   367,     6,     6,     6,   147,
     319,   103,   122,   107,     6,     5,   268,     6,   357,   357,
     357,   268,   268,   268,   109,   357,   265,   360,   357,   357,
     299,   297,   268,   268,     6,   317,     6,   357,   370,   147,
     147,     4,     6,   374,   374,   357,   357,   379,   269,   265,
     269,   273,   327,   327,   357,   357,   269,   273,   265,   269,
     273,     6,     6,   369,   367,   367,   367,   367,   367,   253,
     367,     6,   269,   374,   357,     6,     6,     6,     6,     6,
     370,   269,   273,     8,   269,   265,   253,   268,   357,   371,
     379,   378,   357,   378,   357,   379,   382,   384,   379,   273,
     265,   273,   269,   357,   345,   345,   370,   300,   376,   379,
     357,     6,     6,   375,   267,   370,   385,     6,   299,   299,
     282,   357,   273,   273,   269,   273,   283,   357,   357,     6,
       6,     6,     6,   357,   357,   265,     6,   357,   304,   306,
     268,   384,   269,   273,     7,     7,   151,     6,   268,   268,
     268,     5,   369,   299,   299,   273,   357,   357,   357,   268,
     299,   265,   265,   267,   374,   374,     6,     6,   357,   357,
     268,   269,   269,   268,     6,     6,   268,   357,   269,   269,
     269,   267,     6,   370,     7,   268,   357,   269,   273,   273,
     273,   273,   273,   273,     6,   269,   269,   195,   357,   357,
     268,   269,   374,     6,     6,     6,   265,   299,   299,   315,
     379,   269,   269,   269,   269,     7,     6,     6,     6,   270,
       6,   269,     6,     6,   265,   273,   357,   357,   268,   370,
     269,   273,   265,   265,   273,   269,   309,   313,   370,   299,
     357,   379,   388,   374,   374,   357,     6,   269,   357,   273,
     269,   273,   357,   360,   269,   269,     6,     6,   369,   152,
     153,   158,   352,   152,   153,   352,   374,   327,   269,   273,
       6,   269,   370,   328,   269,     6,   374,   367,   367,   367,
     367,   367,     6,   357,   269,   269,   374,   269,   265,     6,
     268,     6,   375,   198,   286,   357,   273,   273,   369,     6,
     357,   357,     6,   269,   269,   305,     7,   264,   269,   269,
     269,   268,   273,   357,   357,   269,   265,   268,   269,   268,
     367,   370,     6,   268,   367,     6,   269,   269,   357,     6,
     147,   269,   339,   268,   269,   273,   273,   273,   273,   273,
       6,   269,     6,   328,     6,   268,   357,   357,   269,   273,
     309,   379,   265,   357,   357,   269,   269,   374,     6,   367,
       6,   367,     6,     6,   269,   357,   342,   328,     6,   374,
     374,   374,   374,   367,   374,   345,   283,   265,   273,     6,
     268,   357,   269,   273,   273,   269,   273,   273,     6,   269,
     269,   340,   269,   269,   269,   269,   273,   269,   269,   269,
     289,   357,   369,   269,   357,   357,   367,   367,   342,     6,
       6,     6,     6,   374,     6,     6,     6,   268,   265,   269,
       6,   269,   299,   273,   273,   269,   269,   287,   378,   292,
     268,     6,   357,   357,     6,   269,   273,   268,   369,   269,
     269,     6,   378,   290,   378,   269,     6,     6,   269,   273,
       6,     6,   378
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
#line 276 "Gmsh.y"
    { yyerrok; return 1; ;}
    break;

  case 6:
#line 287 "Gmsh.y"
    { return 1; ;}
    break;

  case 7:
#line 288 "Gmsh.y"
    { return 1; ;}
    break;

  case 8:
#line 289 "Gmsh.y"
    { return 1; ;}
    break;

  case 9:
#line 291 "Gmsh.y"
    {
      // synchronize with GModel before switching kernel
      if(GModel::current()->getGEOInternals()->getChanged())
        GModel::current()->getGEOInternals()->synchronize(GModel::current());
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      gmsh_yyfactory = (yyvsp[(3) - (5)].c);
      if(gmsh_yyfactory == "OpenCASCADE"){
        if(!GModel::current()->getOCCInternals())
          GModel::current()->createOCCInternals();
        for(int dim = -2; dim <= 3; dim++)
          GModel::current()->getOCCInternals()->setMaxTag
            (dim, std::max(GModel::current()->getOCCInternals()->getMaxTag(dim),
                           GModel::current()->getGEOInternals()->getMaxTag(dim)));
      }
      else {
        if(gmsh_yyfactory != "Built-in" && gmsh_yyfactory != "Gmsh")
          yymsg(1, "Unknown factory \"%s\" - using \"Built-in\" instead", (yyvsp[(3) - (5)].c));
        if(GModel::current()->getOCCInternals()){
          for(int dim = -2; dim <= 3; dim++)
            GModel::current()->getGEOInternals()->setMaxTag
              (dim, std::max(GModel::current()->getGEOInternals()->getMaxTag(dim),
                             GModel::current()->getOCCInternals()->getMaxTag(dim)));
        }
      }
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 10:
#line 319 "Gmsh.y"
    { return 1; ;}
    break;

  case 11:
#line 320 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 12:
#line 321 "Gmsh.y"
    { return 1; ;}
    break;

  case 13:
#line 322 "Gmsh.y"
    { return 1; ;}
    break;

  case 14:
#line 323 "Gmsh.y"
    { return 1; ;}
    break;

  case 15:
#line 324 "Gmsh.y"
    { return 1; ;}
    break;

  case 16:
#line 325 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 17:
#line 326 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 18:
#line 327 "Gmsh.y"
    { return 1; ;}
    break;

  case 19:
#line 328 "Gmsh.y"
    { return 1; ;}
    break;

  case 20:
#line 329 "Gmsh.y"
    { return 1; ;}
    break;

  case 21:
#line 330 "Gmsh.y"
    { return 1; ;}
    break;

  case 22:
#line 331 "Gmsh.y"
    { return 1; ;}
    break;

  case 23:
#line 332 "Gmsh.y"
    { return 1; ;}
    break;

  case 24:
#line 333 "Gmsh.y"
    { return 1; ;}
    break;

  case 25:
#line 334 "Gmsh.y"
    { return 1; ;}
    break;

  case 26:
#line 339 "Gmsh.y"
    {
      (yyval.c) = (char*)"w";
    ;}
    break;

  case 27:
#line 343 "Gmsh.y"
    {
      (yyval.c) = (char*)"a";
    ;}
    break;

  case 28:
#line 350 "Gmsh.y"
    {
      Msg::Direct((yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 29:
#line 355 "Gmsh.y"
    {
      Msg::Warning((yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 30:
#line 360 "Gmsh.y"
    {
      Msg::Error((yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 31:
#line 365 "Gmsh.y"
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
#line 379 "Gmsh.y"
    {
      std::string tmpstring;
      int i = printListOfDouble((yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].l), tmpstring);
      if(i < 0)
	yymsg(0, "Too few arguments in Printf");
      else if(i > 0)
	yymsg(0, "%d extra argument%s in Printf", i, (i > 1) ? "s" : "");
      else
	Msg::Direct(tmpstring.c_str());
      Free((yyvsp[(3) - (7)].c));
      List_Delete((yyvsp[(5) - (7)].l));
    ;}
    break;

  case 33:
#line 392 "Gmsh.y"
    {
      std::string tmpstring;
      int i = printListOfDouble((yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].l), tmpstring);
      if(i < 0)
	yymsg(1, "Too few arguments in Error");
      else if(i > 0)
	yymsg(1, "%d extra argument%s in Error", i, (i > 1) ? "s" : "");
      else
	Msg::Warning(tmpstring.c_str());
      Free((yyvsp[(3) - (7)].c));
      List_Delete((yyvsp[(5) - (7)].l));
    ;}
    break;

  case 34:
#line 405 "Gmsh.y"
    {
      std::string tmpstring;
      int i = printListOfDouble((yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].l), tmpstring);
      if(i < 0)
	yymsg(0, "Too few arguments in Error");
      else if(i > 0)
	yymsg(0, "%d extra argument%s in Error", i, (i > 1) ? "s" : "");
      else
	Msg::Error(tmpstring.c_str());
      Free((yyvsp[(3) - (7)].c));
      List_Delete((yyvsp[(5) - (7)].l));
    ;}
    break;

  case 35:
#line 418 "Gmsh.y"
    {
      std::string tmpstring;
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
	  fprintf(fp, "%s\n", tmpstring.c_str());
	  fclose(fp);
	}
      }
      Free((yyvsp[(3) - (9)].c));
      Free((yyvsp[(8) - (9)].c));
      List_Delete((yyvsp[(5) - (9)].l));
    ;}
    break;

  case 36:
#line 446 "Gmsh.y"
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
#line 460 "Gmsh.y"
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
#line 473 "Gmsh.y"
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
#line 486 "Gmsh.y"
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
#line 504 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData = new PViewDataList();
#endif
    ;}
    break;

  case 47:
#line 519 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(1) - (1)].d)); ;}
    break;

  case 48:
#line 521 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(3) - (3)].d)); ;}
    break;

  case 49:
#line 526 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(1) - (1)].d)); ;}
    break;

  case 50:
#line 528 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(3) - (3)].d)); ;}
    break;

  case 51:
#line 533 "Gmsh.y"
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
#line 637 "Gmsh.y"
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
#line 647 "Gmsh.y"
    {
#if defined(HAVE_POST)
      if(ViewValueList) (*ViewNumList)++;
#endif
    ;}
    break;

  case 54:
#line 656 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[(1) - (1)].c)[i]);
#endif
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 55:
#line 663 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[(3) - (3)].c)[i]);
#endif
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 56:
#line 673 "Gmsh.y"
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
#line 682 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->NbT2++;
#endif
    ;}
    break;

  case 58:
#line 691 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[(1) - (1)].c)[i]);
#endif
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 59:
#line 698 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[(3) - (3)].c)[i]);
#endif
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 60:
#line 708 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->T3D.push_back((yyvsp[(3) - (10)].d)); ViewData->T3D.push_back((yyvsp[(5) - (10)].d));
      ViewData->T3D.push_back((yyvsp[(7) - (10)].d)); ViewData->T3D.push_back((yyvsp[(9) - (10)].d));
      ViewData->T3D.push_back(ViewData->T3C.size());
#endif
    ;}
    break;

  case 61:
#line 716 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->NbT3++;
#endif
    ;}
    break;

  case 62:
#line 726 "Gmsh.y"
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
#line 745 "Gmsh.y"
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
#line 764 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewValueList = &ViewData->Time;
#endif
    ;}
    break;

  case 65:
#line 770 "Gmsh.y"
    {
    ;}
    break;

  case 66:
#line 777 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 67:
#line 778 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 68:
#line 779 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 69:
#line 780 "Gmsh.y"
    { (yyval.i) = 3; ;}
    break;

  case 70:
#line 781 "Gmsh.y"
    { (yyval.i) = 4; ;}
    break;

  case 71:
#line 785 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 72:
#line 786 "Gmsh.y"
    { (yyval.i) = -1; ;}
    break;

  case 73:
#line 792 "Gmsh.y"
    { (yyval.c) = (char*)"("; ;}
    break;

  case 74:
#line 792 "Gmsh.y"
    { (yyval.c) = (char*)"["; ;}
    break;

  case 75:
#line 794 "Gmsh.y"
    { (yyval.c) = (char*)")"; ;}
    break;

  case 76:
#line 794 "Gmsh.y"
    { (yyval.c) = (char*)"]"; ;}
    break;

  case 77:
#line 799 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 78:
#line 800 "Gmsh.y"
    { (yyval.c) = (char *)Malloc(4 * sizeof(char)); strcpy((yyval.c), "Min"); ;}
    break;

  case 79:
#line 801 "Gmsh.y"
    { (yyval.c) = (char *)Malloc(4 * sizeof(char)); strcpy((yyval.c), "Max"); ;}
    break;

  case 80:
#line 802 "Gmsh.y"
    { (yyval.c) = (char *)Malloc(5 * sizeof(char)); strcpy((yyval.c), "Step"); ;}
    break;

  case 81:
#line 803 "Gmsh.y"
    { (yyval.c) = (char *)Malloc(4 * sizeof(char)); strcpy((yyval.c), "Box"); ;}
    break;

  case 82:
#line 804 "Gmsh.y"
    { (yyval.c) = (char *)Malloc(9 * sizeof(char)); strcpy((yyval.c), "Cylinder"); ;}
    break;

  case 86:
#line 814 "Gmsh.y"
    {
      Msg::SetOnelabNumber((yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].d));
      Free((yyvsp[(3) - (7)].c));
    ;}
    break;

  case 87:
#line 819 "Gmsh.y"
    {
      Msg::SetOnelabString((yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].c));
      Free((yyvsp[(3) - (7)].c));
      Free((yyvsp[(5) - (7)].c));
    ;}
    break;

  case 88:
#line 825 "Gmsh.y"
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
              auto it = std::find(s.value.begin(), s.value.end(), d);
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

  case 89:
#line 886 "Gmsh.y"
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

  case 90:
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
          auto it = std::find(s.value.begin(), s.value.end(), d);
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
#line 929 "Gmsh.y"
    {
      assignVariables((yyvsp[(1) - (9)].c), (yyvsp[(4) - (9)].l), (yyvsp[(7) - (9)].i), (yyvsp[(8) - (9)].l));
      Free((yyvsp[(1) - (9)].c));
      List_Delete((yyvsp[(4) - (9)].l));
      List_Delete((yyvsp[(8) - (9)].l));
    ;}
    break;

  case 92:
#line 939 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    ;}
    break;

  case 93:
#line 944 "Gmsh.y"
    {
      incrementVariable((yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].i));
      Free((yyvsp[(1) - (6)].c));
    ;}
    break;

  case 94:
#line 952 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    ;}
    break;

  case 95:
#line 957 "Gmsh.y"
    {
      incrementVariable((yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].i));
      Free((yyvsp[(1) - (6)].c));
    ;}
    break;

  case 96:
#line 965 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[(1) - (4)].c)] = std::vector<std::string>(1, (yyvsp[(3) - (4)].c));
      Free((yyvsp[(1) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 97:
#line 974 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[(1) - (8)].c)] = std::vector<std::string>();
      Free((yyvsp[(1) - (8)].c));
    ;}
    break;

  case 98:
#line 979 "Gmsh.y"
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
#line 991 "Gmsh.y"
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
#line 1008 "Gmsh.y"
    {
      std::string tmp((yyvsp[(5) - (6)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (6)].c), 0, (yyvsp[(3) - (6)].c), tmp);
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 101:
#line 1014 "Gmsh.y"
    {
      std::string tmp((yyvsp[(8) - (9)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (9)].c), (int)(yyvsp[(3) - (9)].d), (yyvsp[(6) - (9)].c), tmp);
      Free((yyvsp[(1) - (9)].c)); Free((yyvsp[(6) - (9)].c)); Free((yyvsp[(8) - (9)].c));
    ;}
    break;

  case 102:
#line 1023 "Gmsh.y"
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

  case 103:
#line 1041 "Gmsh.y"
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

  case 104:
#line 1059 "Gmsh.y"
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(3) - (5)].c), d)){
	d += (yyvsp[(4) - (5)].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (5)].c), 0, (yyvsp[(3) - (5)].c), d);
      }
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 105:
#line 1068 "Gmsh.y"
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[(1) - (8)].c), (int)(yyvsp[(3) - (8)].d), (yyvsp[(6) - (8)].c), d)){
	d += (yyvsp[(7) - (8)].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (8)].c), (int)(yyvsp[(3) - (8)].d), (yyvsp[(6) - (8)].c), d);
      }
      Free((yyvsp[(1) - (8)].c)); Free((yyvsp[(6) - (8)].c));
    ;}
    break;

  case 106:
#line 1080 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (8)].c), 0, (yyvsp[(5) - (8)].c), (yyvsp[(7) - (8)].u));
      Free((yyvsp[(1) - (8)].c)); Free((yyvsp[(5) - (8)].c));
    ;}
    break;

  case 107:
#line 1085 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (11)].c), (int)(yyvsp[(3) - (11)].d), (yyvsp[(8) - (11)].c), (yyvsp[(10) - (11)].u));
      Free((yyvsp[(1) - (11)].c)); Free((yyvsp[(8) - (11)].c));
    ;}
    break;

  case 108:
#line 1093 "Gmsh.y"
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

  case 109:
#line 1113 "Gmsh.y"
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

  case 110:
#line 1136 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(4) - (5)].l), tags);
      if(!strcmp((yyvsp[(1) - (5)].c),"Background")) {
	if(tags.size() > 1)
	  yymsg(0, "Only 1 field can be set as a background field.");
	else if(tags.size() == 0)
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

  case 111:
#line 1156 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      if(!GModel::current()->getFields()->newField((int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c)))
	yymsg(0, "Cannot create field %i of type '%s'", (int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c));
#endif
      Free((yyvsp[(6) - (7)].c));
    ;}
    break;

  case 112:
#line 1164 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      Field *field = GModel::current()->getFields()->get((int)(yyvsp[(3) - (9)].d));
      if(field){
	FieldOption *option = field->options[(yyvsp[(6) - (9)].c)];
	if(option)
	  option->numericalValue((yyvsp[(8) - (9)].d));
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

  case 113:
#line 1181 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      Field *field = GModel::current()->getFields()->get((int)(yyvsp[(3) - (9)].d));
      if(field){
	FieldOption *option = field->options[(yyvsp[(6) - (9)].c)];
	if(option)
	  option->string((yyvsp[(8) - (9)].c));
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

  case 114:
#line 1199 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      Field *field = GModel::current()->getFields()->get((int)(yyvsp[(3) - (9)].d));
      if(field){
	FieldOption *option = field->options[(yyvsp[(6) - (9)].c)];
	if(option){
	  if(option->getType() == FIELD_OPTION_LIST) {
	    std::list<int> vl = option->list();
	    vl.clear();
	    for(int i = 0; i < List_Nbr((yyvsp[(8) - (9)].l)); i++){
	      double id;
	      List_Read((yyvsp[(8) - (9)].l), i, &id);
	      vl.push_back((int)id);
	    }
	    option->list(vl);
	  }
	  else {
	    std::list<double> vl = option->listdouble();
	    vl.clear();
	    for(int i = 0; i < List_Nbr((yyvsp[(8) - (9)].l)); i++){
	      double id;
	      List_Read((yyvsp[(8) - (9)].l), i, &id);
	      vl.push_back(id);
	    }
	    option->listdouble(vl);
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
      List_Delete((yyvsp[(8) - (9)].l));
    ;}
    break;

  case 115:
#line 1237 "Gmsh.y"
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

  case 116:
#line 1258 "Gmsh.y"
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

  case 117:
#line 1270 "Gmsh.y"
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

  case 121:
#line 1288 "Gmsh.y"
    {
      std::string key((yyvsp[(3) - (3)].c));
      std::vector<double> val(1, 0.);
      if(!gmsh_yysymbols.count(key)){
        gmsh_yysymbols[key].value = val;
      }
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 122:
#line 1297 "Gmsh.y"
    {
      std::string key((yyvsp[(3) - (5)].c));
      std::vector<double> val(1, (yyvsp[(5) - (5)].d));
      if(!gmsh_yysymbols.count(key)){
        gmsh_yysymbols[key].value = val;
      }
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 123:
#line 1306 "Gmsh.y"
    { init_options(); ;}
    break;

  case 124:
#line 1308 "Gmsh.y"
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

  case 125:
#line 1326 "Gmsh.y"
    { init_options(); ;}
    break;

  case 126:
#line 1328 "Gmsh.y"
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

  case 127:
#line 1344 "Gmsh.y"
    {
      std::string key((yyvsp[(3) - (5)].c)), val((yyvsp[(5) - (5)].c));
      if(!gmsh_yystringsymbols.count(key)){
        gmsh_yystringsymbols[key] = std::vector<std::string>(1, val);
      }
      Free((yyvsp[(3) - (5)].c));
      Free((yyvsp[(5) - (5)].c));
    ;}
    break;

  case 128:
#line 1353 "Gmsh.y"
    { init_options(); ;}
    break;

  case 129:
#line 1355 "Gmsh.y"
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

  case 131:
#line 1369 "Gmsh.y"
    {
      std::string name((yyvsp[(3) - (3)].c));
      Msg::UndefineOnelabParameter(name);
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 132:
#line 1377 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(doubleXstring));
      doubleXstring v = {(yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].c)};
      List_Add((yyval.l), &v);
    ;}
    break;

  case 133:
#line 1383 "Gmsh.y"
    {
      doubleXstring v = {(yyvsp[(3) - (5)].d), (yyvsp[(5) - (5)].c)};
      List_Add((yyval.l), &v);
    ;}
    break;

  case 134:
#line 1388 "Gmsh.y"
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

  case 141:
#line 1431 "Gmsh.y"
    {
      std::string key((yyvsp[(1) - (2)].c));
      for(int i = 0; i < List_Nbr((yyvsp[(2) - (2)].l)); i++){
        double v;
        List_Read((yyvsp[(2) - (2)].l), i, &v);
        floatOptions[key].push_back(v);
        if(flag_Enum && !i) { member_ValMax = (int)v; }
      }
      Free((yyvsp[(1) - (2)].c));
      List_Delete((yyvsp[(2) - (2)].l));
    ;}
    break;

  case 142:
#line 1443 "Gmsh.y"
    {
      floatOptions["Min"].push_back((yyvsp[(2) - (2)].d));
    ;}
    break;

  case 143:
#line 1447 "Gmsh.y"
    {
      floatOptions["Max"].push_back((yyvsp[(2) - (2)].d));
    ;}
    break;

  case 144:
#line 1451 "Gmsh.y"
    {
      floatOptions["Step"].push_back((yyvsp[(2) - (2)].d));
    ;}
    break;

  case 145:
#line 1455 "Gmsh.y"
    {
      std::string key((yyvsp[(1) - (1)].c));
      double v;
      if(!flag_Enum) {
        v = 1.;
        if(key == "Enum") flag_Enum = 1;
      }
      else
        v = (double)++member_ValMax;
      floatOptions[key].push_back(v);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 146:
#line 1468 "Gmsh.y"
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

  case 147:
#line 1482 "Gmsh.y"
    {
      std::string key((yyvsp[(1) - (2)].c));
      std::string val((yyvsp[(2) - (2)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(1) - (2)].c));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 148:
#line 1490 "Gmsh.y"
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

  case 153:
#line 1515 "Gmsh.y"
    {
      std::string key((yyvsp[(1) - (2)].c));
      double val = (yyvsp[(2) - (2)].d);
      floatOptions[key].push_back(val);
      Free((yyvsp[(1) - (2)].c));
    ;}
    break;

  case 154:
#line 1523 "Gmsh.y"
    {
      std::string key((yyvsp[(1) - (2)].c));
      std::string val((yyvsp[(2) - (2)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(1) - (2)].c));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 155:
#line 1532 "Gmsh.y"
    {
      std::string key("Macro");
      std::string val((yyvsp[(2) - (2)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 156:
#line 1540 "Gmsh.y"
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

  case 157:
#line 1554 "Gmsh.y"
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

  case 158:
#line 1572 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    ;}
    break;

  case 159:
#line 1576 "Gmsh.y"
    {
      int t = GModel::current()->getGEOInternals()->getMaxPhysicalTag();
      GModel::current()->getGEOInternals()->setMaxPhysicalTag(t + 1);
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (1)].c)), dim_entity, t + 1);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 160:
#line 1583 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (3)].c)), dim_entity, (yyvsp[(3) - (3)].d));
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 161:
#line 1591 "Gmsh.y"
    {
      (yyval.l) = 0;
    ;}
    break;

  case 162:
#line 1595 "Gmsh.y"
    {
      (yyval.l) = List_Create(1, 1, sizeof(double));
      double p = (yyvsp[(4) - (5)].d);
      List_Add((yyval.l), &p);
    ;}
    break;

  case 163:
#line 1601 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
    ;}
    break;

  case 164:
#line 1605 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      double flag = -1;
      List_Add((yyval.l), &flag);
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++)
        List_Add((yyval.l), List_Pointer((yyvsp[(4) - (5)].l), i));
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 165:
#line 1616 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = 0.;
    ;}
    break;

  case 166:
#line 1620 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 167:
#line 1626 "Gmsh.y"
    {
      (yyval.d) = 0;
    ;}
    break;

  case 168:
#line 1630 "Gmsh.y"
    {
      (yyval.d) = 1;
    ;}
    break;

  case 169:
#line 1636 "Gmsh.y"
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

  case 170:
#line 1659 "Gmsh.y"
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

  case 171:
#line 1675 "Gmsh.y"
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

  case 172:
#line 1691 "Gmsh.y"
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

  case 173:
#line 1708 "Gmsh.y"
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

  case 174:
#line 1725 "Gmsh.y"
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

  case 175:
#line 1762 "Gmsh.y"
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

  case 176:
#line 1806 "Gmsh.y"
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

  case 177:
#line 1822 "Gmsh.y"
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

  case 178:
#line 1839 "Gmsh.y"
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

  case 179:
#line 1870 "Gmsh.y"
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

  case 180:
#line 1886 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(7) - (8)].l), tags);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        r = GModel::current()->getOCCInternals()->addCurveLoop(num, tags);
      }
      else{
        r = GModel::current()->getGEOInternals()->addCurveLoop(num, tags);
      }
      if(!r) yymsg(0, "Could not add curve loop");
      List_Delete((yyvsp[(7) - (8)].l));
      Free((yyvsp[(2) - (8)].c));
      (yyval.s).Type = MSH_SEGM_LOOP;
      (yyval.s).Num = num;
    ;}
    break;

  case 181:
#line 1903 "Gmsh.y"
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

  case 182:
#line 1919 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (8)].d);
      std::vector<int> wires; ListOfDouble2Vector((yyvsp[(6) - (8)].l), wires);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        if(wires.size() != 1){
          yymsg(0, "OpenCASCADE surface filling requires a single curve loop");
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

  case 183:
#line 1969 "Gmsh.y"
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

  case 184:
#line 1987 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].d);
      std::vector<int> wires; ListOfDouble2Vector((yyvsp[(7) - (8)].l), wires);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        if(wires.size() != 1) {
          yymsg(0, "OpenCASCADE BSpline filling requires a single curve loop");
        }
        else {
          r = GModel::current()->getOCCInternals()->addBSplineFilling(num, wires[0]);
        }
      }
      else{
        yymsg(0, "BSpline surface only available with OpenCASCADE geometry kernel");
      }
      if(!r) yymsg(0, "Could not add BSpline surface");
      List_Delete((yyvsp[(7) - (8)].l));
      (yyval.s).Type = MSH_SURF_REGL;
      (yyval.s).Num = num;
    ;}
    break;

  case 185:
#line 2008 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].d);
      std::vector<int> wires; ListOfDouble2Vector((yyvsp[(7) - (8)].l), wires);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        if(wires.size() != 1) {
          yymsg(0, "OpenCASCADE BSpline filling requires a single curve loop");
        }
        else {
          r = GModel::current()->getOCCInternals()->addBezierFilling(num, wires[0]);
        }
      }
      else{
        yymsg(0, "Bezier surface only available with OpenCASCADE geometry kernel");
      }
      if(!r) yymsg(0, "Could not add Bezier surface");
      List_Delete((yyvsp[(7) - (8)].l));
      (yyval.s).Type = MSH_SURF_REGL;
      (yyval.s).Num = num;
    ;}
    break;

  case 186:
#line 2029 "Gmsh.y"
    {
      myGmshSurface = 0;
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 187:
#line 2035 "Gmsh.y"
    {
      myGmshSurface = gmshSurface::getSurface((int)(yyvsp[(3) - (4)].d));
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 188:
#line 2041 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (10)].d);
      myGmshSurface = gmshParametricSurface::NewParametricSurface(num, (yyvsp[(7) - (10)].c), (yyvsp[(8) - (10)].c), (yyvsp[(9) - (10)].c));
      (yyval.s).Type = 0;
      (yyval.s).Num = num;
    ;}
    break;

  case 189:
#line 2048 "Gmsh.y"
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

  case 190:
#line 2079 "Gmsh.y"
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
#line 2094 "Gmsh.y"
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

  case 192:
#line 2116 "Gmsh.y"
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

  case 193:
#line 2139 "Gmsh.y"
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

  case 194:
#line 2162 "Gmsh.y"
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

  case 195:
#line 2185 "Gmsh.y"
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

  case 196:
#line 2209 "Gmsh.y"
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

  case 197:
#line 2233 "Gmsh.y"
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

  case 198:
#line 2257 "Gmsh.y"
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

  case 199:
#line 2283 "Gmsh.y"
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

  case 200:
#line 2300 "Gmsh.y"
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

  case 201:
#line 2316 "Gmsh.y"
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

  case 202:
#line 2334 "Gmsh.y"
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

  case 203:
#line 2352 "Gmsh.y"
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

  case 204:
#line 2365 "Gmsh.y"
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

  case 205:
#line 2377 "Gmsh.y"
    {
      dim_entity = (yyvsp[(2) - (2)].i);
    ;}
    break;

  case 206:
#line 2381 "Gmsh.y"
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

  case 207:
#line 2407 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 208:
#line 2409 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 209:
#line 2411 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 210:
#line 2413 "Gmsh.y"
    { (yyval.i) = 3; ;}
    break;

  case 211:
#line 2415 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(3) - (4)].d);
      if((yyval.i) < 0 || (yyval.i) > 3) yymsg(0, "GeoEntity dim out of range [0,3]");
    ;}
    break;

  case 212:
#line 2423 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 213:
#line 2425 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 214:
#line 2427 "Gmsh.y"
    { (yyval.i) = 3; ;}
    break;

  case 215:
#line 2429 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(3) - (4)].d);
      if((yyval.i)<1 || (yyval.i)>3) yymsg(0, "GeoEntity dim out of range [1,3]");
    ;}
    break;

  case 216:
#line 2437 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 217:
#line 2439 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 218:
#line 2441 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(3) - (4)].d);
      if((yyval.i)<1 || (yyval.i)>2) yymsg(0, "GeoEntity dim out of range [1,2]");
    ;}
    break;

  case 219:
#line 2449 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 220:
#line 2451 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 221:
#line 2453 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 222:
#line 2455 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(3) - (4)].d);
      if((yyval.i) < 0 || (yyval.i) > 2) yymsg(0, "GeoEntity dim out of range [0,2]");
    ;}
    break;

  case 223:
#line 2465 "Gmsh.y"
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

  case 224:
#line 2481 "Gmsh.y"
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

  case 225:
#line 2497 "Gmsh.y"
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

  case 226:
#line 2513 "Gmsh.y"
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

  case 227:
#line 2529 "Gmsh.y"
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

  case 228:
#line 2545 "Gmsh.y"
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

  case 229:
#line 2562 "Gmsh.y"
    {
      std::vector<double> xyz; ListOfDouble2Vector((yyvsp[(3) - (7)].l), xyz);
      std::vector<std::pair<int, int> > dimTags, outDimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(6) - (7)].l), dimTags);
      (yyval.l) = (yyvsp[(6) - (7)].l);
      List_Reset((yyval.l));
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        if(xyz.size() == 3) {
          std::vector<double> dist, coord;
          r = GModel::current()->getOCCInternals()->getClosestEntities
            (xyz[0], xyz[1], xyz[2], dimTags, outDimTags, dist, coord,
             (int)dimTags.size());
        }
        else {
          yymsg(0, "Closest first argument should contain 3 coordinates");
        }
      }
      else{
        yymsg(0, "Closest entity only available with OpenCASCADE geometry kernel");
      }
      if(!r) yymsg(0, "Closest entity search failed");
      else VectorOfPairs2ListOfShapes(outDimTags, (yyval.l));
      List_Delete((yyvsp[(3) - (7)].l));
    ;}
    break;

  case 230:
#line 2588 "Gmsh.y"
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
              action == "OrientedBoundary" || action == "OrientedCombinedBoundary" ||
              action == "PointsOf"){
        // boundary operations are performed directly on GModel, which enables
        // to compute the boundary of hybrid CAD models; this also automatically
        // binds all boundary entities for OCC models
        if(GModel::current()->getOCCInternals() &&
           GModel::current()->getOCCInternals()->getChanged())
          GModel::current()->getOCCInternals()->synchronize(GModel::current());
        if(GModel::current()->getGEOInternals()->getChanged())
          GModel::current()->getGEOInternals()->synchronize(GModel::current());
        bool combined = (action == "CombinedBoundary" ||
                         action == "OrientedCombinedBoundary");
        bool oriented = (action == "OrientedBoundary" ||
                         action == "OrientedCombinedBoundary");
        bool recursive = action == "PointsOf";
        r = GModel::current()->getBoundaryTags
          (inDimTags, outDimTags, combined, oriented, recursive);
      }
      else{
        yymsg(0, "Unknown action on multiple shapes '%s'", (yyvsp[(1) - (4)].c));
      }
      if(!r) yymsg(0, "Could not apply operation on shapes");
      VectorOfPairs2ListOfShapes(outDimTags, (yyval.l));
      Free((yyvsp[(1) - (4)].c));
    ;}
    break;

  case 231:
#line 2630 "Gmsh.y"
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

  case 232:
#line 2651 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        yymsg(0, "Split Curve not available with OpenCASCADE geometry kernel");
      }
      else{
        std::vector<int> vertices, curves; ListOfDouble2Vector((yyvsp[(8) - (10)].l), vertices);
        r = GModel::current()->getGEOInternals()->splitCurve
          ((int)(yyvsp[(4) - (10)].d), vertices, curves);
        for(std::size_t i = 0; i < curves.size(); i++){
          Shape s;
          s.Type = MSH_SEGM_LINE;
          s.Num = curves[i];
          List_Add((yyval.l), &s);
        }
      }
      if(!r) yymsg(0, "Could not split curve");
      List_Delete((yyvsp[(8) - (10)].l));
    ;}
    break;

  case 233:
#line 2672 "Gmsh.y"
    {
      yymsg(2, "'Split Curve(c) {...}' is deprecated: "
            "use 'Split Curve {c} Point {...}' instead");
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        yymsg(0, "Split Curve not available with OpenCASCADE geometry kernel");
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
      if(!r) yymsg(0, "Could not split curve");
      List_Delete((yyvsp[(7) - (9)].l));
    ;}
    break;

  case 234:
#line 2697 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 235:
#line 2698 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 236:
#line 2703 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    ;}
    break;

  case 237:
#line 2707 "Gmsh.y"
    {
      List_Add((yyval.l), &(yyvsp[(2) - (2)].s));
    ;}
    break;

  case 238:
#line 2711 "Gmsh.y"
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

  case 239:
#line 2728 "Gmsh.y"
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

  case 240:
#line 2748 "Gmsh.y"
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

  case 241:
#line 2768 "Gmsh.y"
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

  case 242:
#line 2787 "Gmsh.y"
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

  case 243:
#line 2814 "Gmsh.y"
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

  case 244:
#line 2833 "Gmsh.y"
    {
      int t = (int)(yyvsp[(4) - (10)].d);
      if(gLevelset::find(t)){
	yymsg(0, "Levelset %d already exists", t);
      }
      else {
	fullMatrix<double> centers(List_Nbr((yyvsp[(8) - (10)].l)),3);
	for(int i = 0; i < List_Nbr((yyvsp[(8) - (10)].l)); i++){
	  List_T *l = *(List_T**)List_Pointer((yyvsp[(8) - (10)].l), i);
	  for(int j = 0; j < List_Nbr(l); j++){
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

  case 245:
#line 2855 "Gmsh.y"
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

  case 246:
#line 2870 "Gmsh.y"
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

  case 247:
#line 2885 "Gmsh.y"
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

  case 248:
#line 2904 "Gmsh.y"
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

  case 249:
#line 2955 "Gmsh.y"
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

  case 250:
#line 2976 "Gmsh.y"
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

  case 251:
#line 2998 "Gmsh.y"
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

  case 252:
#line 3020 "Gmsh.y"
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
          gLevelset *ls = nullptr;
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

  case 253:
#line 3125 "Gmsh.y"
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

  case 254:
#line 3141 "Gmsh.y"
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

  case 255:
#line 3176 "Gmsh.y"
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
        std::vector<GEntity*> removed;
        GModel::current()->remove(dimTags, removed);
        Msg::Debug("Destroying %zu entities in model", removed.size());
        for(std::size_t i = 0; i < removed.size(); i++) delete removed[i];
      }
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 256:
#line 3201 "Gmsh.y"
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
        std::vector<GEntity*> removed;
        GModel::current()->remove(dimTags, removed, true);
        Msg::Debug("Destroying %zu entities in model", removed.size());
        for(std::size_t i = 0; i < removed.size(); i++) delete removed[i];
      }
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 257:
#line 3226 "Gmsh.y"
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

  case 258:
#line 3238 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      GModel::current()->getFields()->deleteField((int)(yyvsp[(4) - (6)].d));
#endif
    ;}
    break;

  case 259:
#line 3244 "Gmsh.y"
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

  case 260:
#line 3259 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (3)].c), "All")){
        ClearProject();
      }
      else if(!strcmp((yyvsp[(2) - (3)].c), "Meshes")){
	GModel::current()->deleteMesh();
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

  case 261:
#line 3290 "Gmsh.y"
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

  case 262:
#line 3302 "Gmsh.y"
    {
      gmsh_yynamespaces.clear();
    ;}
    break;

  case 263:
#line 3311 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), dimTags);
      setColor(dimTags, (yyvsp[(2) - (5)].u), false);
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 264:
#line 3318 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(5) - (6)].l), dimTags);
      setColor(dimTags, (yyvsp[(3) - (6)].u), true);
      List_Delete((yyvsp[(5) - (6)].l));
    ;}
    break;

  case 265:
#line 3330 "Gmsh.y"
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

  case 266:
#line 3350 "Gmsh.y"
    {
      setVisibility(-1, 1, false);
    ;}
    break;

  case 267:
#line 3354 "Gmsh.y"
    {
      setVisibility(-1, 1, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 268:
#line 3359 "Gmsh.y"
    {
      setVisibility(-1, 0, false);
    ;}
    break;

  case 269:
#line 3363 "Gmsh.y"
    {
      setVisibility(-1, 0, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 270:
#line 3368 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(3) - (4)].l), dimTags);
      setVisibility(dimTags, 1, false);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 271:
#line 3375 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), dimTags);
      setVisibility(dimTags, 1, true);
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 272:
#line 3382 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(3) - (4)].l), dimTags);
      setVisibility(dimTags, 0, false);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 273:
#line 3389 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), dimTags);
      setVisibility(dimTags, 0, true);
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 274:
#line 3401 "Gmsh.y"
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

  case 275:
#line 3474 "Gmsh.y"
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

  case 276:
#line 3492 "Gmsh.y"
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

  case 277:
#line 3517 "Gmsh.y"
    {
#if defined(HAVE_POST) && defined(HAVE_MESH)
      if(!strcmp((yyvsp[(1) - (7)].c), "Background") && !strcmp((yyvsp[(2) - (7)].c), "Mesh") && !strcmp((yyvsp[(3) - (7)].c), "View")){
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

  case 278:
#line 3532 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(1) - (3)].c), "Sleep")) {
	SleepInSeconds((yyvsp[(2) - (3)].d));
      }
      else if(!strcmp((yyvsp[(1) - (3)].c), "Remesh")) {
	yymsg(0, "Surface remeshing must be reinterfaced");
      }
      else if(!strcmp((yyvsp[(1) - (3)].c), "Mesh")) {
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
      else if(!strcmp((yyvsp[(1) - (3)].c), "SetOrder")) {
#if defined(HAVE_MESH)
        SetOrderN(GModel::current(), (yyvsp[(2) - (3)].d), CTX::instance()->mesh.secondOrderLinear,
                  CTX::instance()->mesh.secondOrderIncomplete,
                  CTX::instance()->mesh.meshOnlyVisible);
#endif
      }
      else if(!strcmp((yyvsp[(1) - (3)].c), "PartitionMesh")) {
        GModel::current()->partitionMesh((yyvsp[(2) - (3)].d));
      }
      else if(!strcmp((yyvsp[(1) - (3)].c), "SetCurrentWindow")) {
#if defined(HAVE_FLTK)
        FlGui::instance()->setCurrentOpenglWindow((int)(yyvsp[(2) - (3)].d));
#endif
      }
      else if(!strcmp((yyvsp[(1) - (3)].c), "SplitCurrentWindowHorizontal")) {
#if defined(HAVE_FLTK)
        FlGui::instance()->splitCurrentOpenglWindow('h', (yyvsp[(2) - (3)].d));
#endif
      }
      else if(!strcmp((yyvsp[(1) - (3)].c), "SplitCurrentWindowVertical")) {
#if defined(HAVE_FLTK)
        FlGui::instance()->splitCurrentOpenglWindow('v', (yyvsp[(2) - (3)].d));
#endif
      }
      else {
	yymsg(0, "Unknown command '%s'", (yyvsp[(1) - (3)].c));
      }
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 279:
#line 3581 "Gmsh.y"
    {
#if defined(HAVE_FLTK)
      FlGui::instance()->splitCurrentOpenglWindow('u');
#endif
    ;}
    break;

  case 280:
#line 3587 "Gmsh.y"
    {
#if defined(HAVE_PLUGINS)
       try {
	 PluginManager::instance()->action((yyvsp[(3) - (7)].c), (yyvsp[(6) - (7)].c), 0);
       }
       catch(...) {
	 yymsg(0, "Failed action '%s' or unknown plugin '%s'", (yyvsp[(6) - (7)].c), (yyvsp[(3) - (7)].c));
       }
#endif
       Free((yyvsp[(3) - (7)].c)); Free((yyvsp[(6) - (7)].c));
     ;}
    break;

  case 281:
#line 3599 "Gmsh.y"
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

  case 282:
#line 3631 "Gmsh.y"
    {
      Msg::Exit(0, false); // will return 0 only if no meshing error occurred
    ;}
    break;

  case 283:
#line 3635 "Gmsh.y"
    {
      Msg::Exit((int)(yyvsp[(2) - (3)].d), true); // will always return the specified value
    ;}
    break;

  case 284:
#line 3639 "Gmsh.y"
    {
      gmsh_yyerrorstate = 999; // this will be checked when yyparse returns
      YYABORT;
    ;}
    break;

  case 285:
#line 3644 "Gmsh.y"
    {
      // force sync
      if(GModel::current()->getOCCInternals())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      GModel::current()->getGEOInternals()->synchronize(GModel::current());
    ;}
    break;

  case 286:
#line 3651 "Gmsh.y"
    {
      new GModel();
      GModel::current(GModel::list.size() - 1);
    ;}
    break;

  case 287:
#line 3656 "Gmsh.y"
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

  case 288:
#line 3666 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 1;
      SetBoundingBox((yyvsp[(3) - (15)].d), (yyvsp[(5) - (15)].d), (yyvsp[(7) - (15)].d), (yyvsp[(9) - (15)].d), (yyvsp[(11) - (15)].d), (yyvsp[(13) - (15)].d));
    ;}
    break;

  case 289:
#line 3671 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
      drawContext::global()->draw(false); // not rate limited
#endif
    ;}
    break;

  case 290:
#line 3677 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
     CTX::instance()->mesh.changed = ENT_ALL;
     for(std::size_t index = 0; index < PView::list.size(); index++)
       PView::list[index]->setChanged(true);
#endif
    ;}
    break;

  case 291:
#line 3685 "Gmsh.y"
    {
      if((yyvsp[(3) - (7)].d)) {
        GModel::current()->makeDiscreteRegionsSimplyConnected();
        GModel::current()->makeDiscreteFacesSimplyConnected();
      }
      GModel::current()->createTopologyFromMesh();
      if((yyvsp[(5) - (7)].d)) {
        GModel::current()->exportDiscreteGEOInternals();
      }
    ;}
    break;

  case 292:
#line 3696 "Gmsh.y"
    {
      GModel::current()->makeDiscreteRegionsSimplyConnected();
      GModel::current()->makeDiscreteFacesSimplyConnected();
      GModel::current()->createTopologyFromMesh();
      // Warning: this clears GEO_Internals!
      GModel::current()->exportDiscreteGEOInternals();
    ;}
    break;

  case 293:
#line 3704 "Gmsh.y"
    {
      GModel::current()->classifySurfaces((yyvsp[(3) - (9)].d), (yyvsp[(5) - (9)].d), (yyvsp[(7) - (9)].d), M_PI);
    ;}
    break;

  case 294:
#line 3708 "Gmsh.y"
    {
      GModel::current()->classifySurfaces((yyvsp[(3) - (11)].d), (yyvsp[(5) - (11)].d), (yyvsp[(7) - (11)].d), (yyvsp[(9) - (11)].d));
    ;}
    break;

  case 295:
#line 3712 "Gmsh.y"
    {
      GModel::current()->createGeometryOfDiscreteEntities();
    ;}
    break;

  case 296:
#line 3716 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(3) - (4)].l), dimTags);
      GModel::current()->createGeometryOfDiscreteEntities(dimTags);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 297:
#line 3723 "Gmsh.y"
    {
      GModel::current()->renumberMeshVertices();
    ;}
    break;

  case 298:
#line 3727 "Gmsh.y"
    {
      GModel::current()->renumberMeshElements();
    ;}
    break;

  case 299:
#line 3731 "Gmsh.y"
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

  case 300:
#line 3743 "Gmsh.y"
    {
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      if(GModel::current()->getGEOInternals()->getChanged())
        GModel::current()->getGEOInternals()->synchronize(GModel::current());
      GModel::current()->recombineMesh();
    ;}
    break;

  case 301:
#line 3753 "Gmsh.y"
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

  case 302:
#line 3811 "Gmsh.y"
    {
      std::vector<double> affineTransform;
      ListOfDouble2Vector((yyvsp[(3) - (5)].l), affineTransform);
      if(affineTransform.size() >= 12) {
        std::vector<GEntity *> entities;
        GModel::current()->getEntities(entities);
        for(auto e : entities) {
          for(std::size_t j = 0; j < e->getNumMeshVertices(); j++) {
            MVertex *v = e->getMeshVertex(j);
            SPoint3 pt = v->point();
            pt.transform(affineTransform);
            v->setXYZ(pt);
          }
        }
      }
      else
        yymsg(0, "Affine transform matrix requires at least 12 entries");
      List_Delete((yyvsp[(3) - (5)].l));
    ;}
    break;

  case 303:
#line 3831 "Gmsh.y"
    {
      std::vector<double> affineTransform;
      ListOfDouble2Vector((yyvsp[(3) - (8)].l), affineTransform);
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(6) - (8)].l), dimTags);
      for(std::size_t i = 0; i < dimTags.size(); i++) {
        GEntity *e = GModel::current()->getEntityByTag
          (dimTags[i].first, dimTags[i].second);
        if(e){
          for(std::size_t j = 0; j < e->getNumMeshVertices(); j++) {
            MVertex *v = e->getMeshVertex(j);
            SPoint3 pt = v->point();
            pt.transform(affineTransform);
            v->setXYZ(pt);
          }
        }
      }
      List_Delete((yyvsp[(3) - (8)].l));
      List_Delete((yyvsp[(6) - (8)].l));
    ;}
    break;

  case 304:
#line 3857 "Gmsh.y"
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

  case 305:
#line 3873 "Gmsh.y"
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

  case 306:
#line 3890 "Gmsh.y"
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

  case 307:
#line 3907 "Gmsh.y"
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

  case 308:
#line 3929 "Gmsh.y"
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

  case 309:
#line 3951 "Gmsh.y"
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

  case 310:
#line 3986 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip(nullptr, "Return");
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 311:
#line 3994 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip(nullptr, "Return");
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 312:
#line 4002 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    ;}
    break;

  case 313:
#line 4008 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function '%s'", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 314:
#line 4015 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function '%s'", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 315:
#line 4022 "Gmsh.y"
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

  case 316:
#line 4042 "Gmsh.y"
    {
      if(ImbricatedTest > 0){
        if(statusImbricatedTests[ImbricatedTest]){
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

  case 317:
#line 4068 "Gmsh.y"
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

  case 318:
#line 4080 "Gmsh.y"
    {
      ImbricatedTest--;
      if(ImbricatedTest < 0)
        yymsg(1, "Orphan EndIf");
    ;}
    break;

  case 319:
#line 4091 "Gmsh.y"
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

  case 320:
#line 4109 "Gmsh.y"
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

  case 321:
#line 4127 "Gmsh.y"
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

  case 322:
#line 4145 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 323:
#line 4151 "Gmsh.y"
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

  case 324:
#line 4169 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 325:
#line 4175 "Gmsh.y"
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

  case 326:
#line 4195 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 327:
#line 4201 "Gmsh.y"
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

  case 328:
#line 4219 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 329:
#line 4225 "Gmsh.y"
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

  case 330:
#line 4242 "Gmsh.y"
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

  case 331:
#line 4258 "Gmsh.y"
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

  case 332:
#line 4275 "Gmsh.y"
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

  case 333:
#line 4293 "Gmsh.y"
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

  case 334:
#line 4316 "Gmsh.y"
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

  case 335:
#line 4343 "Gmsh.y"
    {
    ;}
    break;

  case 336:
#line 4346 "Gmsh.y"
    {
    ;}
    break;

  case 337:
#line 4352 "Gmsh.y"
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

  case 338:
#line 4364 "Gmsh.y"
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

  case 339:
#line 4384 "Gmsh.y"
    {
      extr.mesh.ScaleLast = true;
    ;}
    break;

  case 340:
#line 4388 "Gmsh.y"
    {
      extr.mesh.Recombine = true;
    ;}
    break;

  case 341:
#line 4392 "Gmsh.y"
    {
      extr.mesh.Recombine = (yyvsp[(2) - (3)].d) ? true : false;
    ;}
    break;

  case 342:
#line 4396 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1;
    ;}
    break;

  case 343:
#line 4400 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1_RECOMB;
    ;}
    break;

  case 344:
#line 4404 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1;
    ;}
    break;

  case 345:
#line 4408 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1_RECOMB;
    ;}
    break;

  case 346:
#line 4412 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(6) - (9)].l), tags);
      int num = (int)(yyvsp[(3) - (9)].d);
      GModel::current()->getGEOInternals()->addDiscreteSurface(num);
      extr.mesh.Holes[num].first = (yyvsp[(8) - (9)].d);
      extr.mesh.Holes[num].second = tags;
      List_Delete((yyvsp[(6) - (9)].l));
    ;}
    break;

  case 347:
#line 4421 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (6)].c), "Index"))
        extr.mesh.BoundaryLayerIndex = (yyvsp[(4) - (6)].d);
      else if(!strcmp((yyvsp[(2) - (6)].c), "View"))
        extr.mesh.ViewIndex = (yyvsp[(4) - (6)].d);
      Free((yyvsp[(2) - (6)].c));
    ;}
    break;

  case 348:
#line 4433 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Union; ;}
    break;

  case 349:
#line 4434 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Intersection; ;}
    break;

  case 350:
#line 4435 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Difference; ;}
    break;

  case 351:
#line 4436 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Section; ;}
    break;

  case 352:
#line 4437 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Fragments; ;}
    break;

  case 353:
#line 4441 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 354:
#line 4442 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 355:
#line 4443 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 356:
#line 4444 "Gmsh.y"
    { (yyval.i) = (yyvsp[(2) - (3)].d) ? 1 : 0; ;}
    break;

  case 357:
#line 4445 "Gmsh.y"
    { (yyval.i) = (yyvsp[(3) - (4)].d) ? 2 : 0; ;}
    break;

  case 358:
#line 4450 "Gmsh.y"
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

  case 359:
#line 4473 "Gmsh.y"
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

  case 360:
#line 4493 "Gmsh.y"
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

  case 361:
#line 4514 "Gmsh.y"
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    ;}
    break;

  case 362:
#line 4518 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (3)].c), "Progression") || !strcmp((yyvsp[(2) - (3)].c), "Power"))
        (yyval.v)[0] = 1.;
      else if(!strcmp((yyvsp[(2) - (3)].c), "Bump"))
        (yyval.v)[0] = 2.;
      else if(!strcmp((yyvsp[(2) - (3)].c), "Beta"))
        (yyval.v)[0] = 3.;
      else if(!strcmp((yyvsp[(2) - (3)].c), "Progression_HWall"))
        (yyval.v)[0] = 5.;
      else if(!strcmp((yyvsp[(2) - (3)].c), "Bump_HWall"))
        (yyval.v)[0] = 6.;
      else if(!strcmp((yyvsp[(2) - (3)].c), "Beta_HWall"))
        (yyval.v)[0] = 7.;
      else if(!strcmp((yyvsp[(2) - (3)].c), "Beta_Symmetrical"))
        (yyval.v)[0] = 8.;
      else if(!strcmp((yyvsp[(2) - (3)].c), "Beta_Symmetrical_HWall"))
        (yyval.v)[0] = 9.;
      else{
        yymsg(0, "Unknown transfinite mesh type");
        (yyval.v)[0] = 1.;
      }
      (yyval.v)[1] = (yyvsp[(3) - (3)].d);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 363:
#line 4545 "Gmsh.y"
    {
      (yyval.i) = -1; // left
    ;}
    break;

  case 364:
#line 4549 "Gmsh.y"
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

  case 365:
#line 4565 "Gmsh.y"
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   ;}
    break;

  case 366:
#line 4569 "Gmsh.y"
    {
     (yyval.l) = (yyvsp[(2) - (2)].l);
   ;}
    break;

  case 367:
#line 4574 "Gmsh.y"
    {
      (yyval.i) = 45;
    ;}
    break;

  case 368:
#line 4578 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(2) - (2)].d);
    ;}
    break;

  case 369:
#line 4584 "Gmsh.y"
    {
      (yyval.l) = List_Create(1, 1, sizeof(double));
    ;}
    break;

  case 370:
#line 4588 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
    ;}
    break;

  case 371:
#line 4595 "Gmsh.y"
    {
      // mesh sizes at vertices are stored in internal CAD data, as they can be
      // specified during vertex creation and copied around during CAD
      // operations
      List_T *tmp = (yyvsp[(2) - (5)].l);
      if(!(yyvsp[(2) - (5)].l)){
        tmp = List_Create(100, 100, sizeof(double));
        getAllElementaryTags(0, tmp);
      }
      for(int i = 0; i < List_Nbr(tmp); i++){
        double d;
        List_Read(tmp, i, &d);
        int tag = (int)d;
        if(GModel::current()->getOCCInternals())
          GModel::current()->getOCCInternals()->setMeshSize(0, tag, (yyvsp[(4) - (5)].d));
        GModel::current()->getGEOInternals()->setMeshSize(0, tag, (yyvsp[(4) - (5)].d));
        GVertex *gv = GModel::current()->getVertexByTag(tag);
        if(gv) gv->setPrescribedMeshSizeAtVertex((yyvsp[(4) - (5)].d));
      }
      List_Delete(tmp);
    ;}
    break;

  case 372:
#line 4618 "Gmsh.y"
    {
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

  case 373:
#line 4637 "Gmsh.y"
    {
      // transfinite constraints are stored in GEO internals in addition to
      // GModel, as they can be copied around during GEO operations
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      int type = (int)(yyvsp[(6) - (7)].v)[0];
      double coef = (yyvsp[(6) - (7)].v)[1];
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

  case 374:
#line 4678 "Gmsh.y"
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
            gf->meshAttributes.corners.clear();
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

  case 375:
#line 4723 "Gmsh.y"
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
            gr->meshAttributes.corners.clear();
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

  case 376:
#line 4763 "Gmsh.y"
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

  case 377:
#line 4788 "Gmsh.y"
    {
      int dim = (int)(yyvsp[(2) - (8)].i);
      int tag = (int)(yyvsp[(4) - (8)].d);
      int new_tag = (int)(yyvsp[(6) - (8)].d);
      GModel::current()->changeEntityTag(dim, tag, new_tag);
    ;}
    break;

  case 378:
#line 4795 "Gmsh.y"
    {
      int dim = (int)(yyvsp[(2) - (6)].i);
      int tag = (int)(yyvsp[(4) - (6)].d);
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        GModel::current()->getOCCInternals()->setMaxTag(dim, tag);
      }
      else {
        GModel::current()->getGEOInternals()->setMaxTag(dim, tag);
      }
    ;}
    break;

  case 379:
#line 4806 "Gmsh.y"
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

  case 380:
#line 4823 "Gmsh.y"
    {
      // mesh size from boundary onstraints are stored in GEO internals in
      // addition to GModel, as they can be copied around during GEO operations
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

  case 381:
#line 4840 "Gmsh.y"
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

  case 382:
#line 4870 "Gmsh.y"
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

  case 383:
#line 4896 "Gmsh.y"
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

  case 384:
#line 4923 "Gmsh.y"
    {
      if(List_Nbr((yyvsp[(4) - (11)].l)) != List_Nbr((yyvsp[(8) - (11)].l))){
        yymsg(0, "Wrong number of curves in periodicity constraint (%d -> %d)",
              List_Nbr((yyvsp[(8) - (11)].l)), List_Nbr((yyvsp[(4) - (11)].l)));
      }
      else{
        std::vector<double> transfo;
        if(List_Nbr((yyvsp[(10) - (11)].l)) != 0) {
          if(List_Nbr((yyvsp[(10) - (11)].l)) < 12){
            yymsg(0, "Affine transformation requires at least 12 entries "
                  "(%d provided)", List_Nbr((yyvsp[(10) - (11)].l)));
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

  case 385:
#line 4955 "Gmsh.y"
    {
      if(List_Nbr((yyvsp[(4) - (11)].l)) != List_Nbr((yyvsp[(8) - (11)].l))){
        yymsg(0, "Wrong number surfaces in periodicity constraint (%d -> %d)",
              List_Nbr((yyvsp[(8) - (11)].l)), List_Nbr((yyvsp[(4) - (11)].l)));
      }
      else{
        if(List_Nbr((yyvsp[(10) - (11)].l)) < 12){
          // FIXME full automatic case here if List_Nbr($10) == 0)
          yymsg(0, "Affine transformation requires at least 12 entries "
                "(%d provided)", List_Nbr((yyvsp[(10) - (11)].l)));
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

  case 386:
#line 4983 "Gmsh.y"
    {
      if(List_Nbr((yyvsp[(4) - (18)].l)) != List_Nbr((yyvsp[(8) - (18)].l))){
        yymsg(0, "Wrong number of curves in periodicity constraint (%d -> %d)",
              List_Nbr((yyvsp[(8) - (18)].l)), List_Nbr((yyvsp[(4) - (18)].l)));
      }
      else{
        SPoint3 axis((yyvsp[(12) - (18)].v)[0], (yyvsp[(12) - (18)].v)[1], (yyvsp[(12) - (18)].v)[2]);
        SPoint3 origin((yyvsp[(14) - (18)].v)[0], (yyvsp[(14) - (18)].v)[1], (yyvsp[(14) - (18)].v)[2]);
        double  angle((yyvsp[(16) - (18)].d));
        SPoint3 translation(0, 0, 0);

        std::vector<double> transfo;
        computeAffineTransformation(origin, axis, angle, translation, transfo);

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

  case 387:
#line 5009 "Gmsh.y"
    {
      if(List_Nbr((yyvsp[(4) - (18)].l)) != List_Nbr((yyvsp[(8) - (18)].l))){
        yymsg(0, "Wrong number of surfaces in periodicity constraint (%d -> %d)",
              List_Nbr((yyvsp[(8) - (18)].l)), List_Nbr((yyvsp[(4) - (18)].l)));
      }
      else{
        SPoint3 origin((yyvsp[(14) - (18)].v)[0], (yyvsp[(14) - (18)].v)[1], (yyvsp[(14) - (18)].v)[2]);
        SPoint3 axis((yyvsp[(12) - (18)].v)[0], (yyvsp[(12) - (18)].v)[1], (yyvsp[(12) - (18)].v)[2]);
        double  angle((yyvsp[(16) - (18)].d));
        SPoint3 translation(0, 0, 0);

        std::vector<double> transfo;
        computeAffineTransformation(origin, axis, angle, translation, transfo);

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

  case 388:
#line 5035 "Gmsh.y"
    {
      if(List_Nbr((yyvsp[(4) - (12)].l)) != List_Nbr((yyvsp[(8) - (12)].l))){
        yymsg(0, "Wrong number of curves in periodicity constraint (%d -> %d)",
              List_Nbr((yyvsp[(8) - (12)].l)), List_Nbr((yyvsp[(4) - (12)].l)));
      }
      else{
        SPoint3 origin(0, 0, 0);
        SPoint3 axis(0, 0, 0);
        double  angle(0);
        SPoint3 translation((yyvsp[(11) - (12)].v)[0], (yyvsp[(11) - (12)].v)[1], (yyvsp[(11) - (12)].v)[2]);

        std::vector<double> transfo;
        computeAffineTransformation(origin, axis, angle, translation, transfo);

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

  case 389:
#line 5061 "Gmsh.y"
    {
      if(List_Nbr((yyvsp[(4) - (12)].l)) != List_Nbr((yyvsp[(8) - (12)].l))){
        yymsg(0, "Wrong number of surfaces in periodicity constraint (%d -> %d)",
              List_Nbr((yyvsp[(8) - (12)].l)), List_Nbr((yyvsp[(4) - (12)].l)));
      }
      else{
        SPoint3 origin(0, 0, 0);
        SPoint3 axis(0, 0, 0);
        double  angle(0);
        SPoint3 translation((yyvsp[(11) - (12)].v)[0], (yyvsp[(11) - (12)].v)[1], (yyvsp[(11) - (12)].v)[2]);

        std::vector<double> transfo;
        computeAffineTransformation(origin, axis, angle, translation, transfo);

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

  case 390:
#line 5087 "Gmsh.y"
    {
      if(List_Nbr((yyvsp[(5) - (12)].l)) != List_Nbr((yyvsp[(10) - (12)].l))){
        yymsg(0, "Wrong number of surface curves in periodicity constraint (%d -> %d)",
              List_Nbr((yyvsp[(10) - (12)].l)), List_Nbr((yyvsp[(5) - (12)].l)));
      }
      else{
        int j_master = (int)(yyvsp[(8) - (12)].d);
        int j_slave = (int)(yyvsp[(3) - (12)].d);
        std::map<int,int> edgeCounterParts;
        for(int i = 0; i < List_Nbr((yyvsp[(5) - (12)].l)); i++){
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

  case 391:
#line 5108 "Gmsh.y"
    {
      if(((yyvsp[(6) - (10)].i) == 2 || (yyvsp[(6) - (10)].i) == 3) && (yyvsp[(1) - (10)].i) < (yyvsp[(6) - (10)].i)) {
        std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (10)].l), tags);
        addEmbedded((yyvsp[(1) - (10)].i), tags, (yyvsp[(6) - (10)].i), (int)(yyvsp[(8) - (10)].d));
      }
      else {
        yymsg(0, "Entity of dimension %d cannot be embedded in entity of dimension %d",
              (yyvsp[(1) - (10)].i), (yyvsp[(6) - (10)].i));
      }
      List_Delete((yyvsp[(3) - (10)].l));
    ;}
    break;

  case 392:
#line 5120 "Gmsh.y"
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

  case 393:
#line 5168 "Gmsh.y"
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

  case 394:
#line 5222 "Gmsh.y"
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

  case 395:
#line 5237 "Gmsh.y"
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

  case 396:
#line 5249 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (4)].l), tags);
      GModel::current()->getGEOInternals()->setCompoundMesh((yyvsp[(2) - (4)].i), tags);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 397:
#line 5255 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (6)].l), tags);
      tags.push_back(- (int) (yyvsp[(5) - (6)].d));
      GModel::current()->getGEOInternals()->setCompoundMesh((yyvsp[(2) - (6)].i), tags);
      List_Delete((yyvsp[(3) - (6)].l));
    ;}
    break;

  case 398:
#line 5267 "Gmsh.y"
    {
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals())
        GModel::current()->getOCCInternals()->removeAllDuplicates();
      else
        GModel::current()->getGEOInternals()->removeAllDuplicates();
    ;}
    break;

  case 399:
#line 5274 "Gmsh.y"
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

  case 400:
#line 5289 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(4) - (6)].l), tags);
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals())
        GModel::current()->getOCCInternals()->mergeVertices(tags);
      else
        GModel::current()->getGEOInternals()->mergeVertices(tags);
      List_Delete((yyvsp[(4) - (6)].l));
    ;}
    break;

  case 401:
#line 5298 "Gmsh.y"
    {
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()) {
        std::vector<std::pair<int, int> > in, out;
        GModel::current()->getOCCInternals()->healShapes
          (in, out, CTX::instance()->geom.tolerance,
           CTX::instance()->geom.occFixDegenerated,
           CTX::instance()->geom.occFixSmallEdges,
           CTX::instance()->geom.occFixSmallFaces,
           CTX::instance()->geom.occSewFaces,
           CTX::instance()->geom.occMakeSolids);
      }
      else {
        yymsg(0, "HealShapes only available with OpenCASCADE geometry kernel");
      }
    ;}
    break;

  case 402:
#line 5318 "Gmsh.y"
    { (yyval.c) = (char*)"Homology"; ;}
    break;

  case 403:
#line 5319 "Gmsh.y"
    { (yyval.c) = (char*)"Cohomology"; ;}
    break;

  case 404:
#line 5320 "Gmsh.y"
    { (yyval.c) = (char*)"Betti"; ;}
    break;

  case 405:
#line 5325 "Gmsh.y"
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest((yyvsp[(1) - (2)].c), domain, subdomain, dim);
    ;}
    break;

  case 406:
#line 5331 "Gmsh.y"
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

  case 407:
#line 5343 "Gmsh.y"
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

  case 408:
#line 5361 "Gmsh.y"
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

  case 409:
#line 5388 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d);           ;}
    break;

  case 410:
#line 5389 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (3)].d);           ;}
    break;

  case 411:
#line 5390 "Gmsh.y"
    { (yyval.d) = -(yyvsp[(2) - (2)].d);          ;}
    break;

  case 412:
#line 5391 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);           ;}
    break;

  case 413:
#line 5392 "Gmsh.y"
    { (yyval.d) = !(yyvsp[(2) - (2)].d);          ;}
    break;

  case 414:
#line 5393 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) - (yyvsp[(3) - (3)].d);      ;}
    break;

  case 415:
#line 5394 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) + (yyvsp[(3) - (3)].d);      ;}
    break;

  case 416:
#line 5395 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) * (yyvsp[(3) - (3)].d);      ;}
    break;

  case 417:
#line 5397 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (3)].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));
      else
	(yyval.d) = (yyvsp[(1) - (3)].d) / (yyvsp[(3) - (3)].d);
    ;}
    break;

  case 418:
#line 5403 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) | (int)(yyvsp[(3) - (3)].d); ;}
    break;

  case 419:
#line 5404 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) & (int)(yyvsp[(3) - (3)].d); ;}
    break;

  case 420:
#line 5405 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) % (int)(yyvsp[(3) - (3)].d); ;}
    break;

  case 421:
#line 5406 "Gmsh.y"
    { (yyval.d) = pow((yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));  ;}
    break;

  case 422:
#line 5407 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d);      ;}
    break;

  case 423:
#line 5408 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) > (yyvsp[(3) - (3)].d);      ;}
    break;

  case 424:
#line 5409 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) <= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 425:
#line 5410 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) >= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 426:
#line 5411 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) == (yyvsp[(3) - (3)].d);     ;}
    break;

  case 427:
#line 5412 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) != (yyvsp[(3) - (3)].d);     ;}
    break;

  case 428:
#line 5413 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) && (yyvsp[(3) - (3)].d);     ;}
    break;

  case 429:
#line 5414 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) || (yyvsp[(3) - (3)].d);     ;}
    break;

  case 430:
#line 5415 "Gmsh.y"
    { (yyval.d) = ((int)(yyvsp[(1) - (3)].d) >> (int)(yyvsp[(3) - (3)].d)); ;}
    break;

  case 431:
#line 5416 "Gmsh.y"
    { (yyval.d) = ((int)(yyvsp[(1) - (3)].d) << (int)(yyvsp[(3) - (3)].d)); ;}
    break;

  case 432:
#line 5417 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (5)].d) ? (yyvsp[(3) - (5)].d) : (yyvsp[(5) - (5)].d); ;}
    break;

  case 433:
#line 5418 "Gmsh.y"
    { (yyval.d) = ((yyvsp[(3) - (4)].d) < 0) ? 0 : 1; ;}
    break;

  case 434:
#line 5419 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 435:
#line 5420 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 436:
#line 5421 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 437:
#line 5422 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 438:
#line 5423 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 439:
#line 5424 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 440:
#line 5425 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 441:
#line 5426 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 442:
#line 5427 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 443:
#line 5428 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 444:
#line 5429 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 445:
#line 5430 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 446:
#line 5431 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 447:
#line 5432 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 448:
#line 5433 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 449:
#line 5434 "Gmsh.y"
    { (yyval.d) = std::abs((yyvsp[(3) - (4)].d)); ;}
    break;

  case 450:
#line 5435 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 451:
#line 5436 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 452:
#line 5437 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d) + 0.5); ;}
    break;

  case 453:
#line 5438 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 454:
#line 5439 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 455:
#line 5440 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 456:
#line 5441 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 457:
#line 5442 "Gmsh.y"
    { (yyval.d) = std::max((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 458:
#line 5443 "Gmsh.y"
    { (yyval.d) = std::min((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 459:
#line 5452 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 460:
#line 5453 "Gmsh.y"
    { (yyval.d) = 3.141592653589793; ;}
    break;

  case 461:
#line 5454 "Gmsh.y"
    { (yyval.d) = (double)ImbricatedTest; ;}
    break;

  case 462:
#line 5455 "Gmsh.y"
    { (yyval.d) = Msg::GetCommRank(); ;}
    break;

  case 463:
#line 5456 "Gmsh.y"
    { (yyval.d) = Msg::GetCommSize(); ;}
    break;

  case 464:
#line 5457 "Gmsh.y"
    { (yyval.d) = GetGmshMajorVersion(); ;}
    break;

  case 465:
#line 5458 "Gmsh.y"
    { (yyval.d) = GetGmshMinorVersion(); ;}
    break;

  case 466:
#line 5459 "Gmsh.y"
    { (yyval.d) = GetGmshPatchVersion(); ;}
    break;

  case 467:
#line 5460 "Gmsh.y"
    { (yyval.d) = Cpu(); ;}
    break;

  case 468:
#line 5461 "Gmsh.y"
    { (yyval.d) = GetMemoryUsage()/1024./1024.; ;}
    break;

  case 469:
#line 5462 "Gmsh.y"
    { (yyval.d) = TotalRam(); ;}
    break;

  case 470:
#line 5467 "Gmsh.y"
    { init_options(); ;}
    break;

  case 471:
#line 5469 "Gmsh.y"
    {
      std::vector<double> val(1, (yyvsp[(3) - (6)].d));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.d) = val[0];
    ;}
    break;

  case 472:
#line 5475 "Gmsh.y"
    {
      (yyval.d) = (yyvsp[(1) - (1)].d);
    ;}
    break;

  case 473:
#line 5479 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 474:
#line 5484 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 475:
#line 5489 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(1) - (1)].c2).char1, (yyvsp[(1) - (1)].c2).char2);
    ;}
    break;

  case 476:
#line 5494 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float(nullptr, (yyvsp[(1) - (4)].c), 2, (int)(yyvsp[(3) - (4)].d));
    ;}
    break;

  case 477:
#line 5499 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float(nullptr, (yyvsp[(1) - (4)].c), 2, (int)(yyvsp[(3) - (4)].d));
    ;}
    break;

  case 478:
#line 5503 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(3) - (4)].c2).char1, (yyvsp[(3) - (4)].c2).char2, 1, 0, 0., 1);
    ;}
    break;

  case 479:
#line 5507 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(3) - (6)].c2).char1, (yyvsp[(3) - (6)].c2).char2, (yyvsp[(5) - (6)].c), 0, 0., 1);
    ;}
    break;

  case 480:
#line 5511 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(3) - (5)].c2).char1, (yyvsp[(3) - (5)].c2).char2, 1, 0, (yyvsp[(4) - (5)].d), 2);
    ;}
    break;

  case 481:
#line 5515 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(3) - (7)].c2).char1, (yyvsp[(3) - (7)].c2).char2, (yyvsp[(5) - (7)].c), 0, (yyvsp[(6) - (7)].d), 2);
    ;}
    break;

  case 482:
#line 5519 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(3) - (8)].c2).char1, (yyvsp[(3) - (8)].c2).char2, 2, (int)(yyvsp[(5) - (8)].d), (yyvsp[(7) - (8)].d), 2);
    ;}
    break;

  case 483:
#line 5523 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(3) - (10)].c2).char1, (yyvsp[(3) - (10)].c2).char2, (yyvsp[(5) - (10)].c), (int)(yyvsp[(7) - (10)].d), (yyvsp[(9) - (10)].d), 2);
    ;}
    break;

  case 484:
#line 5527 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.d) = !StatFile(tmp);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 485:
#line 5533 "Gmsh.y"
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

  case 486:
#line 5548 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float_getDim((yyvsp[(2) - (6)].c2).char1, (yyvsp[(2) - (6)].c2).char2, (yyvsp[(4) - (6)].c));
    ;}
    break;

  case 487:
#line 5552 "Gmsh.y"
    {
      std::string struct_namespace((yyvsp[(3) - (4)].c));
      (yyval.d) = (double)gmsh_yynamespaces[struct_namespace].size();
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 488:
#line 5558 "Gmsh.y"
    {
      std::string struct_namespace(std::string(""));
      (yyval.d) = (double)gmsh_yynamespaces[struct_namespace].size();
    ;}
    break;

  case 489:
#line 5563 "Gmsh.y"
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

  case 490:
#line 5582 "Gmsh.y"
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

  case 491:
#line 5602 "Gmsh.y"
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

  case 492:
#line 5623 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(nullptr, (yyvsp[(1) - (3)].c), (yyvsp[(3) - (3)].c));
    ;}
    break;

  case 493:
#line 5627 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c), (yyvsp[(5) - (5)].c));
    ;}
    break;

  case 494:
#line 5631 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(nullptr, (yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].c), (int)(yyvsp[(5) - (6)].d));
    ;}
    break;

  case 495:
#line 5635 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(1) - (8)].c), (yyvsp[(3) - (8)].c), (yyvsp[(5) - (8)].c), (int)(yyvsp[(7) - (8)].d));
    ;}
    break;

  case 496:
#line 5639 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(nullptr, (yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].c), (int)(yyvsp[(5) - (6)].d));
    ;}
    break;

  case 497:
#line 5643 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(1) - (8)].c), (yyvsp[(3) - (8)].c), (yyvsp[(5) - (8)].c), (int)(yyvsp[(7) - (8)].d));
    ;}
    break;

  case 498:
#line 5647 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), (yyval.d));
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 499:
#line 5652 "Gmsh.y"
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

  case 500:
#line 5662 "Gmsh.y"
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

  case 501:
#line 5672 "Gmsh.y"
    {
      (yyval.d) = Msg::GetValue((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 502:
#line 5677 "Gmsh.y"
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

  case 503:
#line 5688 "Gmsh.y"
    {
      std::string s((yyvsp[(3) - (6)].c)), substr((yyvsp[(5) - (6)].c));
      if(s.find(substr) != std::string::npos)
        (yyval.d) = 1.;
      else
        (yyval.d) = 0.;
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 504:
#line 5697 "Gmsh.y"
    {
      (yyval.d) = strlen((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 505:
#line 5702 "Gmsh.y"
    {
      (yyval.d) = strcmp((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 506:
#line 5707 "Gmsh.y"
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

  case 507:
#line 5734 "Gmsh.y"
    { (yyval.d) = 0.; ;}
    break;

  case 508:
#line 5736 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);;}
    break;

  case 509:
#line 5741 "Gmsh.y"
    { (yyval.c) = nullptr; ;}
    break;

  case 510:
#line 5743 "Gmsh.y"
    { (yyval.c) = (yyvsp[(2) - (2)].c);;}
    break;

  case 511:
#line 5748 "Gmsh.y"
    {
      std::string struct_namespace((yyvsp[(2) - (3)].c2).char1? (yyvsp[(2) - (3)].c2).char1 : std::string("")),
        struct_name((yyvsp[(2) - (3)].c2).char2);
      init_options
        (gmsh_yynamespaces.getMember_ValMax(struct_namespace, struct_name));
    ;}
    break;

  case 512:
#line 5755 "Gmsh.y"
    {
      std::string struct_namespace((yyvsp[(2) - (7)].c2).char1? (yyvsp[(2) - (7)].c2).char1 : std::string("")),
        struct_name((yyvsp[(2) - (7)].c2).char2);
      Free((yyvsp[(2) - (7)].c2).char1); Free((yyvsp[(2) - (7)].c2).char2);
      int tag_out;
      if(gmsh_yynamespaces.defStruct(struct_namespace, struct_name,
                                      floatOptions, charOptions,
                                      tag_out, member_ValMax, (yyvsp[(3) - (7)].i)))
        yymsg(0, "Redefinition of Struct '%s::%s'",
              struct_namespace.c_str(), struct_name.c_str());
      (yyval.d) = (double)tag_out;
    ;}
    break;

  case 513:
#line 5771 "Gmsh.y"
    { (yyval.c2).char1 = nullptr; (yyval.c2).char2 = (yyvsp[(1) - (1)].c); ;}
    break;

  case 514:
#line 5773 "Gmsh.y"
    { (yyval.c2).char1 = (yyvsp[(1) - (3)].c); (yyval.c2).char2 = (yyvsp[(3) - (3)].c); ;}
    break;

  case 515:
#line 5778 "Gmsh.y"
    { (yyval.i) = 99; ;}
    break;

  case 516:
#line 5780 "Gmsh.y"
    { (yyval.i) = (int)(yyvsp[(2) - (2)].d); ;}
    break;

  case 517:
#line 5785 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 518:
#line 5787 "Gmsh.y"
    { (yyval.i) = (yyvsp[(2) - (3)].i); ;}
    break;

  case 519:
#line 5792 "Gmsh.y"
    {
      memcpy((yyval.v), (yyvsp[(1) - (1)].v), 5 * sizeof(double));
    ;}
    break;

  case 520:
#line 5796 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 521:
#line 5800 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 522:
#line 5804 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] - (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 523:
#line 5808 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] + (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 524:
#line 5815 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (11)].d);  (yyval.v)[1] = (yyvsp[(4) - (11)].d);  (yyval.v)[2] = (yyvsp[(6) - (11)].d);  (yyval.v)[3] = (yyvsp[(8) - (11)].d); (yyval.v)[4] = (yyvsp[(10) - (11)].d);
    ;}
    break;

  case 525:
#line 5819 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (9)].d);  (yyval.v)[1] = (yyvsp[(4) - (9)].d);  (yyval.v)[2] = (yyvsp[(6) - (9)].d);  (yyval.v)[3] = (yyvsp[(8) - (9)].d); (yyval.v)[4] = 1.0;
    ;}
    break;

  case 526:
#line 5823 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 527:
#line 5827 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 528:
#line 5834 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].l)));
    ;}
    break;

  case 529:
#line 5839 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].l)));
    ;}
    break;

  case 530:
#line 5846 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 531:
#line 5851 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 532:
#line 5855 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
    ;}
    break;

  case 533:
#line 5859 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 534:
#line 5863 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 535:
#line 5871 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (5)].d);
      }
    ;}
    break;

  case 536:
#line 5882 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
    ;}
    break;

  case 537:
#line 5886 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 538:
#line 5890 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 539:
#line 5901 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 540:
#line 5905 "Gmsh.y"
    {
      (yyval.l) = 0;
    ;}
    break;

  case 541:
#line 5909 "Gmsh.y"
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

  case 542:
#line 5923 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 543:
#line 5931 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (3)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (3)].d);
      }
    ;}
    break;

  case 544:
#line 5939 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      for(double d = (yyvsp[(1) - (3)].d); ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d <= (yyvsp[(3) - (3)].d)) : (d >= (yyvsp[(3) - (3)].d));
          ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d += 1.) : (d -= 1.))
	List_Add((yyval.l), &d);
    ;}
    break;

  case 545:
#line 5946 "Gmsh.y"
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

  case 546:
#line 5956 "Gmsh.y"
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

  case 547:
#line 5979 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags(0, (yyval.l));
    ;}
    break;

  case 548:
#line 5984 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags(0, (yyval.l));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 549:
#line 5990 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags((yyvsp[(1) - (4)].i), (yyval.l));
    ;}
    break;

  case 550:
#line 5995 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags((yyvsp[(1) - (2)].i), (yyval.l));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 551:
#line 6001 "Gmsh.y"
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

  case 552:
#line 6012 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getParentTags((yyvsp[(2) - (3)].i), (yyvsp[(3) - (3)].l), (yyval.l));
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 553:
#line 6018 "Gmsh.y"
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

  case 554:
#line 6032 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getBoundingBox((yyvsp[(2) - (5)].i), (yyvsp[(4) - (5)].l), (yyval.l));
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 555:
#line 6038 "Gmsh.y"
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

  case 556:
#line 6050 "Gmsh.y"
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

  case 557:
#line 6064 "Gmsh.y"
    {
      (yyval.l) = List_Create(9, 1, sizeof(double));
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        std::vector<double> mat;
        GModel::current()->getOCCInternals()->getMatrixOfInertia((yyvsp[(2) - (5)].i), (int)(yyvsp[(4) - (5)].d), mat);
        for(std::size_t i = 0; i < mat.size(); i++)
          List_Add((yyval.l), &mat[i]);
      }
      else{
        yymsg(0, "MatrixOfInertia only available with OpenCASCADE geometry kernel");
      }
    ;}
    break;

  case 558:
#line 6077 "Gmsh.y"
    {
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      if(GModel::current()->getGEOInternals()->getChanged())
        GModel::current()->getGEOInternals()->synchronize(GModel::current());
      (yyval.l) = List_Create(9, 1, sizeof(double));
      GEntity *entity = GModel::current()->getEntityByTag((yyvsp[(3) - (6)].i), (int)(yyvsp[(5) - (6)].d));
      if(!entity) {
        yymsg(0, "%s %d does not exist", ((yyvsp[(3) - (6)].i) == 1) ? "Curve" : "Surface",
              (int)(yyvsp[(5) - (6)].d));
      }
      else {
        Range<double> u = entity->parBounds(0);
        double umin = u.low(), umax = u.high();
        if((yyvsp[(3) - (6)].i) == 1) {
          List_Add((yyval.l), &umin);
          List_Add((yyval.l), &umax);
        }
        else {
          Range<double> v = entity->parBounds(1);
          double vmin = v.low(), vmax = v.high();
          List_Add((yyval.l), &umin);
          List_Add((yyval.l), &vmin);
          List_Add((yyval.l), &umax);
          List_Add((yyval.l), &vmax);
        }
      }
    ;}
    break;

  case 559:
#line 6107 "Gmsh.y"
    {
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      if(GModel::current()->getGEOInternals()->getChanged())
        GModel::current()->getGEOInternals()->synchronize(GModel::current());
      (yyval.l) = List_Create(9, 1, sizeof(double));
      int tag = (int)(yyvsp[(4) - (11)].d);
      GFace *gf = GModel::current()->getFaceByTag(tag);
      if(gf) {
        SPoint2 param((yyvsp[(8) - (11)].d), (yyvsp[(10) - (11)].d));
        SVector3 n = gf->normal(param);
        double x = n.x(), y = n.y(), z = n.z();
        List_Add((yyval.l), &x);
        List_Add((yyval.l), &y);
        List_Add((yyval.l), &z);
      }
      else {
        yymsg(0, "Surface %d does not exist", tag);
      }
    ;}
    break;

  case 560:
#line 6130 "Gmsh.y"
    {
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      if(GModel::current()->getGEOInternals()->getChanged())
        GModel::current()->getGEOInternals()->synchronize(GModel::current());
      (yyval.l) = List_Create(9, 1, sizeof(double));
      int tag = (int)(yyvsp[(4) - (11)].d);
      GFace *gf = GModel::current()->getFaceByTag(tag);
      if(gf) {
        SPoint2 param((yyvsp[(8) - (11)].d), (yyvsp[(10) - (11)].d));
        double c = gf->curvatureMax(param);
        List_Add((yyval.l), &c);
      }
      else {
        yymsg(0, "Surface %d does not exist", tag);
      }
    ;}
    break;

  case 561:
#line 6150 "Gmsh.y"
    {
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      if(GModel::current()->getGEOInternals()->getChanged())
        GModel::current()->getGEOInternals()->synchronize(GModel::current());
      (yyval.l) = List_Create(9, 1, sizeof(double));
      int tag = (int)(yyvsp[(4) - (9)].d);
      GEdge *ge = GModel::current()->getEdgeByTag(tag);
      if(ge) {
        double c = ge->curvature(8);
        List_Add((yyval.l), &c);
      }
      else {
        yymsg(0, "Curve %d does not exist", tag);
      }
    ;}
    break;

  case 562:
#line 6169 "Gmsh.y"
    {
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      if(GModel::current()->getGEOInternals()->getChanged())
        GModel::current()->getGEOInternals()->synchronize(GModel::current());
      (yyval.l) = List_Create(9, 1, sizeof(double));
      GVertex *gv = GModel::current()->getVertexByTag((int)(yyvsp[(4) - (10)].d));
      GFace *gf = GModel::current()->getFaceByTag((int)(yyvsp[(9) - (10)].d));
      if(gv && gf) {
        SPoint2 p = gv->reparamOnFace(gf, 0);
        double u = p.x(), v = p.y();
        List_Add((yyval.l), &u);
        List_Add((yyval.l), &v);
      }
      else {
        yymsg(0, "Point %d or surface %d does not exist", (int)(yyvsp[(4) - (10)].d), (int)(yyvsp[(9) - (10)].d));
      }
    ;}
    break;

  case 563:
#line 6189 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 1, sizeof(double));
      double r = 0., g = 0., b = 0., a = 0.;
      GEntity *ge = GModel::current()->getEntityByTag((yyvsp[(2) - (5)].i), (int)(yyvsp[(4) - (5)].d));
      if(ge){
        unsigned int value = ge->getColor();
        r = CTX::instance()->unpackRed(value);
        g = CTX::instance()->unpackGreen(value);
        b = CTX::instance()->unpackBlue(value);
        a = CTX::instance()->unpackAlpha(value);
        List_Add((yyval.l), &r);
        List_Add((yyval.l), &g);
        List_Add((yyval.l), &b);
        List_Add((yyval.l), &a);
      }
    ;}
    break;

  case 564:
#line 6206 "Gmsh.y"
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

  case 565:
#line 6216 "Gmsh.y"
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

  case 566:
#line 6226 "Gmsh.y"
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

  case 567:
#line 6236 "Gmsh.y"
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

  case 568:
#line 6248 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfFloat(nullptr, (yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c));
    ;}
    break;

  case 569:
#line 6252 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfFloat((yyvsp[(1) - (7)].c), (yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].c));
    ;}
    break;

  case 570:
#line 6257 "Gmsh.y"
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

  case 571:
#line 6269 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 572:
#line 6273 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 573:
#line 6277 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (6)].l);
    ;}
    break;

  case 574:
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

  case 575:
#line 6299 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = (yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1);
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 576:
#line 6307 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = pow(10,(yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1));
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 577:
#line 6315 "Gmsh.y"
    {
      Msg::Barrier();
      FILE *File;
      (yyval.l) = List_Create(100, 100, sizeof(double));
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      if(!(File = Fopen(tmp.c_str(), "r"))){
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
            char dummy[65];
            if(fscanf(File, "%64s", dummy) == 1)
              yymsg(1, "Ignoring '%s' in file '%s'", dummy, (yyvsp[(3) - (4)].c));
          }
        }
	fclose(File);
      }
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 578:
#line 6344 "Gmsh.y"
    {
      double x0 = (yyvsp[(3) - (14)].d), x1 = (yyvsp[(5) - (14)].d), y0 = (yyvsp[(7) - (14)].d), y1 = (yyvsp[(9) - (14)].d), ys = (yyvsp[(11) - (14)].d);
      int N = (int)(yyvsp[(13) - (14)].d);
      std::vector<double> y(N);
      if(!catenary(x0, x1, y0, y1, ys, N, &y[0]))
        yymsg(1, "Catenary did not converge, using linear interpolation");
      (yyval.l) = List_Create(N,10,sizeof(double));
      for(int i = 0; i < N; i++) List_Add((yyval.l), &y[i]);
    ;}
    break;

  case 579:
#line 6354 "Gmsh.y"
    {
      std::vector<double> tmp;
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
        double d; List_Read((yyvsp[(3) - (4)].l), i, &d);
        tmp.push_back(d);
      }
      std::sort(tmp.begin(), tmp.end());
      auto last = std::unique(tmp.begin(), tmp.end());
      tmp.erase(last, tmp.end());
      (yyval.l) = (yyvsp[(3) - (4)].l);
      List_Reset((yyval.l));
      for(std::size_t i = 0; i < tmp.size(); i++){
        List_Add((yyval.l), &tmp[i]);
      }
    ;}
    break;

  case 580:
#line 6370 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
        double *d = (double*)List_Pointer((yyvsp[(3) - (4)].l), i);
        *d = std::abs(*d);
      }
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 581:
#line 6381 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 582:
#line 6386 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 583:
#line 6390 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].d)));
    ;}
    break;

  case 584:
#line 6394 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (3)].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 585:
#line 6406 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (9)].d), (int)(yyvsp[(4) - (9)].d), (int)(yyvsp[(6) - (9)].d), (int)(yyvsp[(8) - (9)].d));
    ;}
    break;

  case 586:
#line 6410 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (7)].d), (int)(yyvsp[(4) - (7)].d), (int)(yyvsp[(6) - (7)].d), 255);
    ;}
    break;

  case 587:
#line 6422 "Gmsh.y"
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

  case 588:
#line 6439 "Gmsh.y"
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(5) - (5)].c), val);
      (yyval.u) = val;
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(5) - (5)].c));
    ;}
    break;

  case 589:
#line 6449 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 590:
#line 6453 "Gmsh.y"
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

  case 591:
#line 6468 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].u)));
    ;}
    break;

  case 592:
#line 6473 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].u)));
    ;}
    break;

  case 593:
#line 6480 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 594:
#line 6484 "Gmsh.y"
    {
      // No need to extend to Struct_FullName (a Tag is not a String)
      (yyval.c) = treat_Struct_FullName_String(nullptr, (yyvsp[(1) - (1)].c));
    ;}
    break;

  case 595:
#line 6489 "Gmsh.y"
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

  case 596:
#line 6503 "Gmsh.y"
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

  case 597:
#line 6517 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String(nullptr, (yyvsp[(1) - (3)].c), (yyvsp[(3) - (3)].c));
    ;}
    break;

  case 598:
#line 6521 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c), (yyvsp[(5) - (5)].c));
    ;}
    break;

  case 599:
#line 6525 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String(nullptr, (yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].c), (int)(yyvsp[(5) - (6)].d));
    ;}
    break;

  case 600:
#line 6529 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(1) - (8)].c), (yyvsp[(3) - (8)].c), (yyvsp[(5) - (8)].c), (int)(yyvsp[(7) - (8)].d));
    ;}
    break;

  case 601:
#line 6533 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 602:
#line 6541 "Gmsh.y"
    {
      std::string name = GModel::current()->getElementaryName((yyvsp[(1) - (4)].i), (int)(yyvsp[(3) - (4)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 603:
#line 6547 "Gmsh.y"
    {
      std::string name = GModel::current()->getPhysicalName((yyvsp[(2) - (5)].i), (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 604:
#line 6556 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 605:
#line 6560 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 606:
#line 6564 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    ;}
    break;

  case 607:
#line 6572 "Gmsh.y"
    {
      std::string exe = Msg::GetExecutableName();
      (yyval.c) = (char *)Malloc(exe.size() + 1);
      strcpy((yyval.c), exe.c_str());
    ;}
    break;

  case 608:
#line 6578 "Gmsh.y"
    {
      std::string action = Msg::GetOnelabAction();
      (yyval.c) = (char *)Malloc(action.size() + 1);
      strcpy((yyval.c), action.c_str());
    ;}
    break;

  case 609:
#line 6584 "Gmsh.y"
    {
      (yyval.c) = strsave((char*)"Gmsh");
    ;}
    break;

  case 610:
#line 6588 "Gmsh.y"
    {
      std::string env = GetEnvironmentVar((yyvsp[(3) - (4)].c));
      (yyval.c) = (char *)Malloc((env.size() + 1) * sizeof(char));
      strcpy((yyval.c), env.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 611:
#line 6595 "Gmsh.y"
    {
      std::string s = Msg::GetString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 612:
#line 6603 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (4)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 613:
#line 6610 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 614:
#line 6619 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_String(nullptr, (yyvsp[(3) - (5)].c2).char2, 1, 0, (yyvsp[(4) - (5)].c), 2);
    ;}
    break;

  case 615:
#line 6623 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(3) - (7)].c2).char1, (yyvsp[(3) - (7)].c2).char2, (yyvsp[(5) - (7)].c), 0, (yyvsp[(6) - (7)].c), 2);
    ;}
    break;

  case 616:
#line 6627 "Gmsh.y"
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

  case 617:
#line 6642 "Gmsh.y"
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

  case 618:
#line 6656 "Gmsh.y"
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
	strcpy((yyval.c), &(yyvsp[(3) - (4)].c)[i + 1]);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 619:
#line 6670 "Gmsh.y"
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

  case 620:
#line 6682 "Gmsh.y"
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

  case 621:
#line 6698 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = toupper((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 622:
#line 6707 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = tolower((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 623:
#line 6716 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        if(i > 0 && (yyvsp[(3) - (4)].c)[i-1] != '_')
          (yyvsp[(3) - (4)].c)[i] = tolower((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 624:
#line 6726 "Gmsh.y"
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

  case 625:
#line 6737 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (8)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (8)].d), (int)(yyvsp[(7) - (8)].d));
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (8)].c));
    ;}
    break;

  case 626:
#line 6745 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (6)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (6)].d), std::string::npos);
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 627:
#line 6753 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 628:
#line 6757 "Gmsh.y"
    {
      std::string tmpstring;
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
	(yyval.c) = strsave((char*)tmpstring.c_str());
	Free((yyvsp[(3) - (6)].c));
      }
      List_Delete((yyvsp[(5) - (6)].l));
    ;}
    break;

  case 629:
#line 6775 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 630:
#line 6782 "Gmsh.y"
    {
      std::string tmp = SplitFileName(GetAbsolutePath(gmsh_yyname))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
    ;}
    break;

  case 631:
#line 6788 "Gmsh.y"
    {
      std::string tmp = GetFileNameWithoutPath(gmsh_yyname);
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
    ;}
    break;

  case 632:
#line 6794 "Gmsh.y"
    {
      std::string tmp = SplitFileName((yyvsp[(3) - (4)].c))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 633:
#line 6801 "Gmsh.y"
    {
      std::string tmp = GetAbsolutePath((yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 634:
#line 6808 "Gmsh.y"
    { init_options(); ;}
    break;

  case 635:
#line 6810 "Gmsh.y"
    {
      std::string val((yyvsp[(3) - (6)].c));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.c) = (char*)Malloc((val.size() + 1) * sizeof(char));
      strcpy((yyval.c), val.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 636:
#line 6818 "Gmsh.y"
    {
      std::string out;
      const std::string * key_struct = nullptr;
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

  case 637:
#line 6842 "Gmsh.y"
    { struct_namespace = std::string(""); (yyval.d) = (yyvsp[(2) - (2)].d); ;}
    break;

  case 638:
#line 6844 "Gmsh.y"
    { struct_namespace = (yyvsp[(1) - (4)].c); Free((yyvsp[(1) - (4)].c)); (yyval.d) = (yyvsp[(4) - (4)].d); ;}
    break;

  case 639:
#line 6850 "Gmsh.y"
    { (yyval.l) = (yyvsp[(3) - (4)].l); ;}
    break;

  case 640:
#line 6855 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 641:
#line 6857 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 642:
#line 6862 "Gmsh.y"
    { (yyval.l) = (yyvsp[(2) - (3)].l); ;}
    break;

  case 643:
#line 6867 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].c)));
    ;}
    break;

  case 644:
#line 6872 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 645:
#line 6874 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].c)));
    ;}
    break;

  case 646:
#line 6878 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	char* c;
	List_Read((yyvsp[(3) - (3)].l), i, &c);
	List_Add((yyval.l), &c);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 647:
#line 6890 "Gmsh.y"
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

  case 648:
#line 6904 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfString(nullptr, (yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c));
    ;}
    break;

  case 649:
#line 6908 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfString((yyvsp[(1) - (7)].c), (yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].c));
    ;}
    break;

  case 650:
#line 6915 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr) + 1) * sizeof(char));
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 651:
#line 6923 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr) + 1) * sizeof(char)) ;
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)) ; strcat((yyval.c), tmpstr) ;
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 652:
#line 6931 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(7) - (8)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(3) - (8)].c))+strlen(tmpstr) + 1) * sizeof(char));
      strcpy((yyval.c), (yyvsp[(3) - (8)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(3) - (8)].c));
    ;}
    break;

  case 653:
#line 6942 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 654:
#line 6944 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 655:
#line 6947 "Gmsh.y"
    { (yyval.c) = (yyvsp[(3) - (4)].c); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 15530 "Gmsh.tab.cpp"
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


#line 6950 "Gmsh.y"


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

int printListOfDouble(const char *format, List_T *list, std::string &buffer)
{
  buffer = format;

  int numFormats = 0;
  for(std::size_t i = 0; i < strlen(format); i++) {
    if(format[i] == '%') numFormats++;
  }

  // if format does not contain formatting characters, dump the list (useful for
  // quick debugging of lists)
  if(!numFormats){
    for(int i = 0; i < List_Nbr(list); i++){
      double d;
      List_Read(list, i, &d);
      char tmp[256];
      sprintf(tmp, " [%d]%g", i, d);
      buffer += tmp;
    }
    return 0;
  }

  char tmp1[256], tmp2[256];
  int j = 0, k = 0;

  while(j < (int)strlen(format) && format[j] != '%') j++;
  buffer.resize(j);

  for(int i = 0; i < List_Nbr(list); i++){
    k = j;
    j++;
    if(j < (int)strlen(format)){
      if(format[j] == '%'){
	buffer += "%";
	j++;
      }
      while(j < (int)strlen(format) && format[j] != '%') j++;
      if(k != j){
	strncpy(tmp1, &(format[k]), j-k);
	tmp1[j-k] = '\0';
	sprintf(tmp2, tmp1, *(double*)List_Pointer(list, i));
	buffer += tmp2;
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
  for(auto it = gmsh_yysymbols.begin(); it != gmsh_yysymbols.end(); it++){
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
  for(auto it = gmsh_yystringsymbols.begin(); it != gmsh_yystringsymbols.end();
      it++){
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
  if(gmsh_yynamespaces.size()){
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
    if(dim >= 0 && dim <= 3) v.push_back(std::make_pair(dim, s.Num));
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
  if(gmsh_yyname.empty())
    Msg::Error("%s (%s)", s, gmsh_yytext);
  else
    Msg::Error("'%s', line %d: %s (%s)", gmsh_yyname.c_str(), gmsh_yylineno - 1,
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
    if(gmsh_yyname.empty())
      Msg::Error("%s", tmp);
    else
      Msg::Error("'%s', line %d: %s", gmsh_yyname.c_str(), gmsh_yylineno - 1, tmp);
    gmsh_yyerrorstate++;
  }
  else if(level == 1){
    if(gmsh_yyname.empty())
      Msg::Warning("%s", tmp);
    else
      Msg::Warning("'%s', line %d: %s", gmsh_yyname.c_str(), gmsh_yylineno - 1, tmp);
  }
  else{
    if(gmsh_yyname.empty())
      Msg::Info("%s", tmp);
    else
      Msg::Info("'%s', line %d: %s", gmsh_yyname.c_str(), gmsh_yylineno - 1, tmp);
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
  if(!target || !source) {
    Msg::Error("Could not find surface %d or %d for periodic copy",
               iTarget, iSource);
    return;
  }
  target->setMeshMaster(source, affineTransform);
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
  for(auto sIter = edgeCounterparts.begin(); sIter != edgeCounterparts.end();
      ++sIter) {
    Msg::Info("%d - %d", sIter->first, sIter->second);
  }

  GFace *target = GModel::current()->getFaceByTag(std::abs(iTarget));
  GFace *source = GModel::current()->getFaceByTag(std::abs(iSource));
  if(!target || !source) {
    Msg::Error("Could not find surface %d or %d for periodic copy",
               iTarget,iSource);
    return;
  }
  target->setMeshMaster(source, edgeCounterparts);
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
  if(!target || !source) {
    Msg::Error("Could not find curve %d or %d for periodic copy",
               iTarget,iSource);
    return;
  }
  if(affineTransform.size() >= 12) {
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

  tfo[0 * 4 + 0] = ca + ux * ux * (1. - ca);
  tfo[0 * 4 + 1] = ux * uy * (1. - ca) - uz * sa;
  tfo[0 * 4 + 2] = ux * uz * (1. - ca) + uy * sa;

  tfo[1 * 4 + 0] = ux * uy * (1. - ca) + uz * sa;
  tfo[1 * 4 + 1] = ca + uy * uy * (1. - ca);
  tfo[1 * 4 + 2] = uy * uz * (1. - ca) - ux * sa;

  tfo[2 * 4 + 0] = ux * uz * (1. - ca) - uy * sa;
  tfo[2 * 4 + 1] = uy * uz * (1. - ca) + ux * sa;
  tfo[2 * 4 + 2] = ca + uz * uz * (1. - ca);

  int idx = 0;
  for(size_t i = 0; i < 3; i++,idx++) {
    int tIdx = i * 4 + 3;
    tfo[tIdx] = origin[i] + translation[i];
    for(int j = 0; j < 3; j++,idx++) tfo[tIdx] -= tfo[idx] * origin[j];
  }

  for(int i = 0; i < 4; i++) tfo[12 + i] = 0;
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
  if(GModel::current()->getOCCInternals() &&
     GModel::current()->getOCCInternals()->getChanged())
    GModel::current()->getOCCInternals()->synchronize(GModel::current());
  if(GModel::current()->getGEOInternals()->getChanged())
    GModel::current()->getGEOInternals()->synchronize(GModel::current());

  std::map<int, std::vector<GEntity*> > groups;
  GModel::current()->getPhysicalGroups(dim, groups);
  for(auto it = groups.begin(); it != groups.end(); it++){
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
    auto it = groups.find(num);
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
    if(type_treat == 1) out = 1.; // Exists (type_treat == 1)
    else { // Get (0) or GetForced (2)
      if(type_var == 1) {
        gmsh_yysymbol &s(gmsh_yysymbols[c2]);
        if(s.value.empty()){
          out = val_default;
          if(type_treat == 0) yymsg(0, "Uninitialized variable '%s'", c2);
        }
        else
          out = s.value[0];
      }
      else if(type_var == 2) {
        gmsh_yysymbol &s(gmsh_yysymbols[c2]);
        if(index < 0 || (int)s.value.size() < index + 1){
          out = val_default;
          if(type_treat == 0) yymsg(0, "Uninitialized variable '%s[%d]'", c2, index);
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
    if(type_var == 1) {
      std::string struct_namespace(c1? c1 : std::string("")), struct_name(c2);
      if(gmsh_yynamespaces.getTag(struct_namespace, struct_name, out)) {
        out = val_default;
        if(type_treat == 0) yymsg(0, "Unknown variable '%s'", struct_name.c_str());
      }
    }
    else {
      out = val_default;
      if(type_treat == 0) yymsg(0, "Unknown variable '%s(.)'", c2);
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
    if(type_treat == 1) out = 1.; // Exists (type_treat == 1)
    break;
  case 1:
    if(!NumberOption(GMSH_GET, c2, 0, c3, out, type_treat==0))
      out = val_default;
    break;
  case 2:
    if(type_treat != 0) {
      const std::string * out_dummy = nullptr;
      out = (gmsh_yynamespaces.getMember
             (struct_namespace, struct_name, key_member, out_dummy))?
        val_default : 1.;
    }
    else {
      out = val_default;
      if(type_treat == 0)
        yymsg(0, "Unknown member '%s' of Struct %s", c3, struct_name.c_str());
    }
    break;
  case 3:
    out = val_default;
    if(type_treat == 0)
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
  List_T * out, * val_default = nullptr;
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
  const std::string * out = nullptr;
  std::string out_tmp;
  if(!c1 && gmsh_yystringsymbols.count(c2)){
    // Get (0) or GetForced (2)
    if(gmsh_yystringsymbols[c2].size() != 1){
      out = &string_default;
      if(type_treat == 0)
        yymsg(0, "Expected single valued string variable '%s'", c2);
    }
    else {
      out_tmp = gmsh_yystringsymbols[c2][0];
      out = &out_tmp;
    }
  }
  else{
    out = &string_default;
    if(type_treat == 0) yymsg(0, "Unknown string variable '%s'", c2);
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
  const std::string * out = nullptr;
  std::string out_tmp; // PD: we should avoid that -> StringOption() to be changed
  std::string struct_namespace(c1? c1 : std::string("")), struct_name(c2);
  std::string key_member(c3);
  switch (gmsh_yynamespaces.getMember
          (struct_namespace, struct_name, key_member, out, index)) {
  case 0:
    break;
  case 1:
    if(StringOption(GMSH_GET, c2, 0, c3, out_tmp, type_treat==0))
      out = &out_tmp;
    else
      out = &string_default;
    break;
  case 2:
    out = &string_default;
    if(type_treat == 0)
      yymsg(0, "Unknown member '%s' of Struct %s", c3, struct_name.c_str());
    break;
  case 3:
    out = &string_default;
    if(type_treat == 0)
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
  List_T * out, * val_default = nullptr;
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

