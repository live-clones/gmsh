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
     tEuclidean = 268,
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
     tCreateMeshEdges = 346,
     tCreateMeshFaces = 347,
     tDistanceFunction = 348,
     tDefineConstant = 349,
     tUndefineConstant = 350,
     tDefineNumber = 351,
     tDefineStruct = 352,
     tNameStruct = 353,
     tDimNameSpace = 354,
     tAppend = 355,
     tDefineString = 356,
     tSetNumber = 357,
     tSetTag = 358,
     tSetString = 359,
     tPoint = 360,
     tCircle = 361,
     tEllipse = 362,
     tCurve = 363,
     tSphere = 364,
     tPolarSphere = 365,
     tSurface = 366,
     tSpline = 367,
     tVolume = 368,
     tBox = 369,
     tCylinder = 370,
     tCone = 371,
     tTorus = 372,
     tEllipsoid = 373,
     tQuadric = 374,
     tShapeFromFile = 375,
     tRectangle = 376,
     tDisk = 377,
     tWire = 378,
     tGeoEntity = 379,
     tNormal = 380,
     tCurvature = 381,
     tCharacteristic = 382,
     tLength = 383,
     tParametric = 384,
     tElliptic = 385,
     tRefineMesh = 386,
     tRecombineMesh = 387,
     tAdaptMesh = 388,
     tTransformMesh = 389,
     tRelocateMesh = 390,
     tReorientMesh = 391,
     tSetFactory = 392,
     tThruSections = 393,
     tWedge = 394,
     tFillet = 395,
     tChamfer = 396,
     tPlane = 397,
     tRuled = 398,
     tTransfinite = 399,
     tPhysical = 400,
     tCompound = 401,
     tPeriodic = 402,
     tParent = 403,
     tUsing = 404,
     tPlugin = 405,
     tDegenerated = 406,
     tRecursive = 407,
     tSewing = 408,
     tRotate = 409,
     tTranslate = 410,
     tSymmetry = 411,
     tDilate = 412,
     tExtrude = 413,
     tAffine = 414,
     tClosest = 415,
     tBooleanUnion = 416,
     tBooleanIntersection = 417,
     tBooleanDifference = 418,
     tBooleanSection = 419,
     tBooleanFragments = 420,
     tThickSolid = 421,
     tRecombine = 422,
     tSmoother = 423,
     tSplit = 424,
     tDelete = 425,
     tCoherence = 426,
     tHealShapes = 427,
     tRecognizeShapes = 428,
     tIntersect = 429,
     tMeshAlgorithm = 430,
     tReverseMesh = 431,
     tMeshSize = 432,
     tMeshSizeFromBoundary = 433,
     tLayers = 434,
     tScaleLast = 435,
     tHole = 436,
     tAlias = 437,
     tAliasWithOptions = 438,
     tCopyOptions = 439,
     tQuadTriAddVerts = 440,
     tQuadTriNoNewVerts = 441,
     tRecombLaterals = 442,
     tTransfQuadTri = 443,
     tText2D = 444,
     tText3D = 445,
     tInterpolationScheme = 446,
     tTime = 447,
     tCombine = 448,
     tBSpline = 449,
     tBezier = 450,
     tNurbs = 451,
     tNurbsOrder = 452,
     tNurbsKnots = 453,
     tColor = 454,
     tColorTable = 455,
     tFor = 456,
     tIn = 457,
     tEndFor = 458,
     tIf = 459,
     tElseIf = 460,
     tElse = 461,
     tEndIf = 462,
     tExit = 463,
     tAbort = 464,
     tField = 465,
     tReturn = 466,
     tCall = 467,
     tSlide = 468,
     tMacro = 469,
     tShow = 470,
     tHide = 471,
     tGetValue = 472,
     tGetStringValue = 473,
     tGetEnv = 474,
     tGetString = 475,
     tGetNumber = 476,
     tUnique = 477,
     tSetMaxTag = 478,
     tHomology = 479,
     tCohomology = 480,
     tBetti = 481,
     tExists = 482,
     tFileExists = 483,
     tGetForced = 484,
     tGetForcedStr = 485,
     tGMSH_MAJOR_VERSION = 486,
     tGMSH_MINOR_VERSION = 487,
     tGMSH_PATCH_VERSION = 488,
     tGmshExecutableName = 489,
     tSetPartition = 490,
     tNameToString = 491,
     tStringToName = 492,
     tUnsplitWindow = 493,
     tAFFECTDIVIDE = 494,
     tAFFECTTIMES = 495,
     tAFFECTMINUS = 496,
     tAFFECTPLUS = 497,
     tOR = 498,
     tAND = 499,
     tNOTEQUAL = 500,
     tEQUAL = 501,
     tGREATERGREATER = 502,
     tLESSLESS = 503,
     tGREATEROREQUAL = 504,
     tLESSOREQUAL = 505,
     UNARYPREC = 506,
     tMINUSMINUS = 507,
     tPLUSPLUS = 508
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
#define tEuclidean 268
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
#define tCreateMeshEdges 346
#define tCreateMeshFaces 347
#define tDistanceFunction 348
#define tDefineConstant 349
#define tUndefineConstant 350
#define tDefineNumber 351
#define tDefineStruct 352
#define tNameStruct 353
#define tDimNameSpace 354
#define tAppend 355
#define tDefineString 356
#define tSetNumber 357
#define tSetTag 358
#define tSetString 359
#define tPoint 360
#define tCircle 361
#define tEllipse 362
#define tCurve 363
#define tSphere 364
#define tPolarSphere 365
#define tSurface 366
#define tSpline 367
#define tVolume 368
#define tBox 369
#define tCylinder 370
#define tCone 371
#define tTorus 372
#define tEllipsoid 373
#define tQuadric 374
#define tShapeFromFile 375
#define tRectangle 376
#define tDisk 377
#define tWire 378
#define tGeoEntity 379
#define tNormal 380
#define tCurvature 381
#define tCharacteristic 382
#define tLength 383
#define tParametric 384
#define tElliptic 385
#define tRefineMesh 386
#define tRecombineMesh 387
#define tAdaptMesh 388
#define tTransformMesh 389
#define tRelocateMesh 390
#define tReorientMesh 391
#define tSetFactory 392
#define tThruSections 393
#define tWedge 394
#define tFillet 395
#define tChamfer 396
#define tPlane 397
#define tRuled 398
#define tTransfinite 399
#define tPhysical 400
#define tCompound 401
#define tPeriodic 402
#define tParent 403
#define tUsing 404
#define tPlugin 405
#define tDegenerated 406
#define tRecursive 407
#define tSewing 408
#define tRotate 409
#define tTranslate 410
#define tSymmetry 411
#define tDilate 412
#define tExtrude 413
#define tAffine 414
#define tClosest 415
#define tBooleanUnion 416
#define tBooleanIntersection 417
#define tBooleanDifference 418
#define tBooleanSection 419
#define tBooleanFragments 420
#define tThickSolid 421
#define tRecombine 422
#define tSmoother 423
#define tSplit 424
#define tDelete 425
#define tCoherence 426
#define tHealShapes 427
#define tRecognizeShapes 428
#define tIntersect 429
#define tMeshAlgorithm 430
#define tReverseMesh 431
#define tMeshSize 432
#define tMeshSizeFromBoundary 433
#define tLayers 434
#define tScaleLast 435
#define tHole 436
#define tAlias 437
#define tAliasWithOptions 438
#define tCopyOptions 439
#define tQuadTriAddVerts 440
#define tQuadTriNoNewVerts 441
#define tRecombLaterals 442
#define tTransfQuadTri 443
#define tText2D 444
#define tText3D 445
#define tInterpolationScheme 446
#define tTime 447
#define tCombine 448
#define tBSpline 449
#define tBezier 450
#define tNurbs 451
#define tNurbsOrder 452
#define tNurbsKnots 453
#define tColor 454
#define tColorTable 455
#define tFor 456
#define tIn 457
#define tEndFor 458
#define tIf 459
#define tElseIf 460
#define tElse 461
#define tEndIf 462
#define tExit 463
#define tAbort 464
#define tField 465
#define tReturn 466
#define tCall 467
#define tSlide 468
#define tMacro 469
#define tShow 470
#define tHide 471
#define tGetValue 472
#define tGetStringValue 473
#define tGetEnv 474
#define tGetString 475
#define tGetNumber 476
#define tUnique 477
#define tSetMaxTag 478
#define tHomology 479
#define tCohomology 480
#define tBetti 481
#define tExists 482
#define tFileExists 483
#define tGetForced 484
#define tGetForcedStr 485
#define tGMSH_MAJOR_VERSION 486
#define tGMSH_MINOR_VERSION 487
#define tGMSH_PATCH_VERSION 488
#define tGmshExecutableName 489
#define tSetPartition 490
#define tNameToString 491
#define tStringToName 492
#define tUnsplitWindow 493
#define tAFFECTDIVIDE 494
#define tAFFECTTIMES 495
#define tAFFECTMINUS 496
#define tAFFECTPLUS 497
#define tOR 498
#define tAND 499
#define tNOTEQUAL 500
#define tEQUAL 501
#define tGREATERGREATER 502
#define tLESSLESS 503
#define tGREATEROREQUAL 504
#define tLESSOREQUAL 505
#define UNARYPREC 506
#define tMINUSMINUS 507
#define tPLUSPLUS 508




/* Copy the first part of user declarations.  */
#line 1 "Gmsh.y"

// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
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
#if defined(HAVE_DISCRETECAD)
#include "DiscreteCADModeler.h"
#endif
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
static std::vector<std::string> ViewStrings;
static std::vector<double> ViewTime;
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
void DiscreteShapeFromFile(const char *fileName, double angle,
                           double curveAngle, double tolerance,
                           List_T *shapes);
void DiscreteClassify(List_T *list, double angle, double curveAngle,
                      List_T *shapes);
void DiscreteRecognize(List_T *list, double angle, double tolerance,
                       List_T *shapes);
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
void getElementaryTagsForPhysicalNames(int dim, List_T *in, List_T *out);
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
#line 180 "Gmsh.y"
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
#line 800 "Gmsh.tab.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 813 "Gmsh.tab.cpp"

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
#define YYLAST   18926

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  276
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  115
/* YYNRULES -- Number of rules.  */
#define YYNRULES  655
/* YYNRULES -- Number of states.  */
#define YYNSTATES  2284

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   508

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint16 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   261,     2,   273,     2,   258,   260,     2,
     266,   267,   256,   254,   275,   255,   272,   257,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     248,     2,   249,   243,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   268,     2,   269,   265,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   270,   259,   271,   274,     2,     2,     2,
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
     235,   236,   237,   238,   239,   240,   241,   242,   244,   245,
     246,   247,   250,   251,   252,   253,   262,   263,   264
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,     9,    12,    14,    16,    18,
      24,    26,    28,    30,    32,    34,    36,    38,    40,    42,
      44,    46,    48,    50,    52,    54,    56,    58,    64,    70,
      76,    84,    92,   100,   108,   118,   125,   132,   139,   148,
     149,   152,   155,   158,   161,   164,   167,   169,   173,   175,
     179,   180,   181,   192,   194,   198,   199,   213,   215,   219,
     220,   236,   245,   260,   261,   268,   270,   272,   274,   276,
     278,   280,   282,   284,   286,   288,   290,   292,   294,   296,
     298,   300,   302,   308,   314,   317,   325,   333,   338,   342,
     349,   359,   367,   374,   382,   389,   394,   403,   413,   423,
     430,   440,   447,   457,   463,   472,   481,   493,   500,   510,
     516,   524,   534,   544,   554,   562,   572,   582,   583,   585,
     586,   590,   596,   597,   607,   608,   620,   626,   627,   637,
     638,   642,   646,   652,   658,   659,   662,   663,   665,   667,
     671,   674,   677,   680,   683,   685,   690,   693,   696,   697,
     700,   702,   706,   709,   712,   715,   718,   721,   723,   725,
     729,   730,   736,   742,   748,   749,   752,   753,   756,   764,
     772,   780,   791,   802,   811,   820,   828,   836,   848,   856,
     865,   874,   883,   893,   902,   911,   915,   920,   931,   939,
     947,   955,   963,   971,   979,   987,   995,  1003,  1011,  1021,
    1029,  1037,  1046,  1055,  1068,  1069,  1079,  1081,  1083,  1085,
    1087,  1092,  1094,  1096,  1098,  1103,  1105,  1107,  1112,  1114,
    1116,  1118,  1123,  1129,  1141,  1147,  1157,  1167,  1175,  1183,
    1188,  1198,  1209,  1219,  1221,  1223,  1224,  1227,  1234,  1242,
    1250,  1258,  1265,  1273,  1278,  1284,  1290,  1297,  1304,  1308,
    1313,  1317,  1323,  1330,  1336,  1341,  1345,  1350,  1354,  1359,
    1365,  1370,  1376,  1380,  1386,  1394,  1402,  1406,  1409,  1417,
    1421,  1424,  1428,  1431,  1434,  1437,  1440,  1456,  1459,  1462,
    1470,  1473,  1483,  1495,  1498,  1503,  1506,  1509,  1512,  1515,
    1518,  1521,  1527,  1536,  1548,  1555,  1564,  1573,  1584,  1586,
    1589,  1592,  1594,  1598,  1602,  1607,  1612,  1614,  1616,  1622,
    1634,  1648,  1649,  1657,  1658,  1672,  1673,  1689,  1690,  1697,
    1707,  1710,  1714,  1725,  1739,  1741,  1744,  1750,  1758,  1761,
    1764,  1768,  1771,  1775,  1778,  1782,  1792,  1799,  1801,  1803,
    1805,  1807,  1809,  1810,  1813,  1817,  1821,  1826,  1836,  1841,
    1849,  1859,  1867,  1877,  1884,  1893,  1904,  1919,  1920,  1924,
    1925,  1927,  1928,  1931,  1932,  1935,  1936,  1939,  1945,  1952,
    1960,  1967,  1973,  1977,  1986,  1993,  2002,  2011,  2017,  2022,
    2029,  2041,  2053,  2072,  2091,  2104,  2117,  2130,  2141,  2146,
    2151,  2156,  2161,  2166,  2173,  2176,  2180,  2187,  2192,  2195,
    2197,  2199,  2201,  2204,  2210,  2218,  2229,  2231,  2235,  2238,
    2241,  2244,  2248,  2252,  2256,  2260,  2264,  2268,  2272,  2276,
    2280,  2284,  2288,  2292,  2296,  2300,  2304,  2308,  2312,  2316,
    2322,  2327,  2332,  2337,  2342,  2347,  2352,  2357,  2362,  2367,
    2372,  2377,  2384,  2389,  2394,  2399,  2404,  2409,  2414,  2419,
    2424,  2431,  2438,  2445,  2450,  2457,  2464,  2466,  2468,  2470,
    2472,  2474,  2476,  2478,  2480,  2482,  2484,  2486,  2487,  2494,
    2496,  2501,  2508,  2510,  2515,  2520,  2525,  2532,  2538,  2546,
    2555,  2566,  2571,  2576,  2583,  2588,  2592,  2595,  2601,  2607,
    2611,  2617,  2624,  2633,  2640,  2649,  2656,  2661,  2669,  2676,
    2683,  2690,  2695,  2702,  2707,  2708,  2711,  2712,  2715,  2716,
    2724,  2726,  2730,  2732,  2735,  2736,  2740,  2742,  2745,  2748,
    2752,  2756,  2768,  2778,  2786,  2794,  2796,  2800,  2802,  2804,
    2807,  2811,  2816,  2822,  2825,  2829,  2834,  2836,  2840,  2842,
    2845,  2849,  2853,  2859,  2864,  2869,  2872,  2877,  2880,  2884,
    2890,  2894,  2899,  2905,  2911,  2917,  2923,  2930,  2942,  2954,
    2964,  2975,  2981,  2983,  2985,  2987,  2991,  2997,  3005,  3010,
    3015,  3020,  3027,  3034,  3043,  3052,  3057,  3072,  3077,  3082,
    3084,  3086,  3090,  3094,  3096,  3100,  3110,  3118,  3120,  3126,
    3130,  3137,  3139,  3143,  3145,  3147,  3152,  3157,  3161,  3167,
    3174,  3183,  3190,  3195,  3201,  3203,  3208,  3210,  3212,  3214,
    3216,  3221,  3228,  3233,  3240,  3246,  3254,  3259,  3264,  3269,
    3278,  3283,  3288,  3293,  3298,  3307,  3316,  3323,  3328,  3335,
    3340,  3342,  3344,  3349,  3354,  3355,  3362,  3367,  3370,  3375,
    3380,  3382,  3384,  3388,  3390,  3392,  3396,  3400,  3404,  3410,
    3418,  3424,  3430,  3439,  3441,  3443
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     277,     0,    -1,   278,    -1,     1,     6,    -1,    -1,   278,
     279,    -1,   281,    -1,   282,    -1,   303,    -1,   137,   266,
     380,   267,     6,    -1,   322,    -1,   328,    -1,   331,    -1,
     332,    -1,   333,    -1,   334,    -1,   338,    -1,   347,    -1,
     348,    -1,   354,    -1,   355,    -1,   337,    -1,   336,    -1,
     335,    -1,   357,    -1,   249,    -1,   250,    -1,    47,   266,
     380,   267,     6,    -1,    49,   266,   380,   267,     6,    -1,
      48,   266,   380,   267,     6,    -1,    47,   266,   380,   267,
     280,   380,     6,    -1,    47,   266,   380,   275,   375,   267,
       6,    -1,    49,   266,   380,   275,   375,   267,     6,    -1,
      48,   266,   380,   275,   375,   267,     6,    -1,    47,   266,
     380,   275,   375,   267,   280,   380,     6,    -1,   390,   380,
     270,   283,   271,     6,    -1,   182,     4,   268,   358,   269,
       6,    -1,   183,     4,   268,   358,   269,     6,    -1,   184,
       4,   268,   358,   275,   358,   269,     6,    -1,    -1,   283,
     286,    -1,   283,   290,    -1,   283,   293,    -1,   283,   295,
      -1,   283,   296,    -1,   283,   337,    -1,   358,    -1,   284,
     275,   358,    -1,   358,    -1,   285,   275,   358,    -1,    -1,
      -1,     4,   287,   266,   284,   267,   288,   270,   285,   271,
       6,    -1,   380,    -1,   289,   275,   380,    -1,    -1,   189,
     266,   358,   275,   358,   275,   358,   267,   291,   270,   289,
     271,     6,    -1,   380,    -1,   292,   275,   380,    -1,    -1,
     190,   266,   358,   275,   358,   275,   358,   275,   358,   267,
     294,   270,   292,   271,     6,    -1,   191,   270,   370,   271,
     270,   370,   271,     6,    -1,   191,   270,   370,   271,   270,
     370,   271,   270,   370,   271,   270,   370,   271,     6,    -1,
      -1,   192,   297,   270,   285,   271,     6,    -1,     7,    -1,
     242,    -1,   241,    -1,   240,    -1,   239,    -1,   264,    -1,
     263,    -1,   266,    -1,   268,    -1,   267,    -1,   269,    -1,
       4,    -1,    37,    -1,    38,    -1,    26,    -1,   114,    -1,
     115,    -1,    94,   268,   305,   269,     6,    -1,    95,   268,
     309,   269,     6,    -1,   363,     6,    -1,   102,   300,   381,
     275,   358,   301,     6,    -1,   104,   300,   381,   275,   381,
     301,     6,    -1,   390,   298,   371,     6,    -1,   390,   299,
       6,    -1,   390,   300,   301,   298,   371,     6,    -1,   390,
     300,   270,   375,   271,   301,   298,   371,     6,    -1,   390,
     268,   358,   269,   298,   358,     6,    -1,   390,   268,   358,
     269,   299,     6,    -1,   390,   266,   358,   267,   298,   358,
       6,    -1,   390,   266,   358,   267,   299,     6,    -1,   390,
       7,   381,     6,    -1,   390,   300,   301,     7,    50,   300,
     301,     6,    -1,   390,   300,   301,     7,    50,   300,   385,
     301,     6,    -1,   390,   300,   301,   242,    50,   300,   385,
     301,     6,    -1,   390,   272,   302,     7,   381,     6,    -1,
     390,   268,   358,   269,   272,   302,     7,   381,     6,    -1,
     390,   272,   302,   298,   358,     6,    -1,   390,   268,   358,
     269,   272,   302,   298,   358,     6,    -1,   390,   272,   302,
     299,     6,    -1,   390,   268,   358,   269,   272,   302,   299,
       6,    -1,   390,   272,   199,   272,   302,     7,   377,     6,
      -1,   390,   268,   358,   269,   272,   199,   272,   302,     7,
     377,     6,    -1,   390,   272,   200,     7,   378,     6,    -1,
     390,   268,   358,   269,   272,   200,     7,   378,     6,    -1,
     390,   210,     7,   371,     6,    -1,   210,   268,   358,   269,
       7,   302,     6,    -1,   210,   268,   358,   269,   272,   302,
       7,   358,     6,    -1,   210,   268,   358,   269,   272,   302,
       7,   381,     6,    -1,   210,   268,   358,   269,   272,   302,
       7,   372,     6,    -1,   210,   268,   358,   269,   272,   302,
       6,    -1,   150,   266,     4,   267,   272,   302,     7,   358,
       6,    -1,   150,   266,     4,   267,   272,   302,     7,   381,
       6,    -1,    -1,   275,    -1,    -1,   305,   304,   390,    -1,
     305,   304,   390,     7,   358,    -1,    -1,   305,   304,   390,
       7,   270,   371,   306,   311,   271,    -1,    -1,   305,   304,
     390,   300,   301,     7,   270,   371,   307,   311,   271,    -1,
     305,   304,   390,     7,   381,    -1,    -1,   305,   304,   390,
       7,   270,   381,   308,   315,   271,    -1,    -1,   309,   304,
     380,    -1,   358,     7,   381,    -1,   310,   275,   358,     7,
     381,    -1,   374,     7,   390,   266,   267,    -1,    -1,   275,
     313,    -1,    -1,   313,    -1,   314,    -1,   313,   275,   314,
      -1,     4,   371,    -1,    37,   358,    -1,    38,   358,    -1,
      26,   358,    -1,     4,    -1,     4,   270,   310,   271,    -1,
       4,   381,    -1,     4,   384,    -1,    -1,   275,   316,    -1,
     317,    -1,   316,   275,   317,    -1,     4,   358,    -1,     4,
     381,    -1,   214,   381,    -1,     4,   386,    -1,     4,   384,
      -1,   358,    -1,   381,    -1,   381,   275,   358,    -1,    -1,
     202,   109,   270,   358,   271,    -1,   149,   105,   270,   375,
     271,    -1,   149,   124,   270,   375,   271,    -1,    -1,   142,
     368,    -1,    -1,   149,   153,    -1,   105,   266,   358,   267,
       7,   368,     6,    -1,   108,   266,   358,   267,     7,   371,
       6,    -1,   112,   266,   358,   267,     7,   371,     6,    -1,
     146,   112,   266,   358,   267,     7,   371,   149,   358,     6,
      -1,   146,   194,   266,   358,   267,     7,   371,   149,   358,
       6,    -1,   106,   266,   358,   267,     7,   371,   320,     6,
      -1,   107,   266,   358,   267,     7,   371,   320,     6,    -1,
     194,   266,   358,   267,     7,   371,     6,    -1,   195,   266,
     358,   267,     7,   371,     6,    -1,   196,   266,   358,   267,
       7,   371,   198,   371,   197,   358,     6,    -1,   123,   266,
     358,   267,     7,   371,     6,    -1,   108,     4,   266,   358,
     267,     7,   371,     6,    -1,   142,   111,   266,   358,   267,
       7,   371,     6,    -1,   111,   266,   358,   267,     7,   371,
     319,     6,    -1,   143,   111,   266,   358,   267,     7,   371,
     319,     6,    -1,   194,   111,   266,   358,   267,     7,   371,
       6,    -1,   195,   111,   266,   358,   267,     7,   371,     6,
      -1,    13,    14,     6,    -1,    14,   111,   358,     6,    -1,
     129,   111,   266,   358,   267,     7,     5,     5,     5,     6,
      -1,   109,   266,   358,   267,     7,   371,     6,    -1,   110,
     266,   358,   267,     7,   371,     6,    -1,   114,   266,   358,
     267,     7,   371,     6,    -1,   117,   266,   358,   267,     7,
     371,     6,    -1,   121,   266,   358,   267,     7,   371,     6,
      -1,   122,   266,   358,   267,     7,   371,     6,    -1,   115,
     266,   358,   267,     7,   371,     6,    -1,   116,   266,   358,
     267,     7,   371,     6,    -1,   139,   266,   358,   267,     7,
     371,     6,    -1,   166,   266,   358,   267,     7,   371,     6,
      -1,   111,     4,   266,   358,   267,     7,   371,   321,     6,
      -1,   113,   266,   358,   267,     7,   371,     6,    -1,   138,
     266,   358,   267,     7,   371,     6,    -1,   143,   138,   266,
     358,   267,     7,   371,     6,    -1,   146,   325,   266,   358,
     267,     7,   371,     6,    -1,   146,   325,   266,   358,   267,
       7,   371,     4,   270,   370,   271,     6,    -1,    -1,   145,
     324,   323,   266,   318,   267,   298,   371,     6,    -1,   105,
      -1,   108,    -1,   111,    -1,   113,    -1,   124,   270,   358,
     271,    -1,   108,    -1,   111,    -1,   113,    -1,   124,   270,
     358,   271,    -1,   108,    -1,   111,    -1,   124,   270,   358,
     271,    -1,   105,    -1,   108,    -1,   111,    -1,   124,   270,
     358,   271,    -1,   155,   368,   270,   329,   271,    -1,   154,
     270,   368,   275,   368,   275,   358,   271,   270,   329,   271,
      -1,   156,   368,   270,   329,   271,    -1,   157,   270,   368,
     275,   358,   271,   270,   329,   271,    -1,   157,   270,   368,
     275,   368,   271,   270,   329,   271,    -1,   159,   270,   375,
     271,   270,   329,   271,    -1,   160,   270,   375,   271,   270,
     329,   271,    -1,     4,   270,   329,   271,    -1,   174,   108,
     270,   375,   271,   111,   270,   358,   271,    -1,   169,   108,
     270,   358,   271,   105,   270,   375,   271,     6,    -1,   169,
     108,   266,   358,   267,   270,   375,   271,     6,    -1,   330,
      -1,   328,    -1,    -1,   330,   322,    -1,   330,   324,   270,
     375,   271,     6,    -1,   330,   145,   324,   270,   375,   271,
       6,    -1,   330,   145,   324,   270,   376,   271,     6,    -1,
     330,   148,   324,   270,   375,   271,     6,    -1,   330,   324,
     270,     8,   271,     6,    -1,   330,   145,   324,   270,     8,
     271,     6,    -1,   170,   270,   330,   271,    -1,   152,   170,
     270,   330,   271,    -1,   170,     4,   270,   330,   271,    -1,
     170,   210,   268,   358,   269,     6,    -1,   170,     4,   268,
     358,   269,     6,    -1,   170,   390,     6,    -1,   170,     4,
       4,     6,    -1,   170,    97,     6,    -1,   199,   377,   270,
     330,   271,    -1,   152,   199,   377,   270,   330,   271,    -1,
     235,   358,   270,   330,   271,    -1,   215,   270,     8,   271,
      -1,   215,     5,     6,    -1,   216,   270,     8,   271,    -1,
     216,     5,     6,    -1,   215,   270,   330,   271,    -1,   152,
     215,   270,   330,   271,    -1,   216,   270,   330,   271,    -1,
     152,   216,   270,   330,   271,    -1,   390,   381,     6,    -1,
      81,   266,   387,   267,     6,    -1,   390,   390,   268,   358,
     269,   380,     6,    -1,   390,   390,   390,   268,   358,   269,
       6,    -1,   390,   358,     6,    -1,   238,     6,    -1,   150,
     266,     4,   267,   272,     4,     6,    -1,   193,     4,     6,
      -1,   208,     6,    -1,   208,   358,     6,    -1,   209,     6,
      -1,    75,     6,    -1,    76,     6,    -1,    68,     6,    -1,
      68,   270,   358,   275,   358,   275,   358,   275,   358,   275,
     358,   275,   358,   271,     6,    -1,    69,     6,    -1,    70,
       6,    -1,    86,   270,   358,   275,   358,   271,     6,    -1,
      86,     6,    -1,    88,   270,   358,   275,   358,   275,   358,
     271,     6,    -1,    88,   270,   358,   275,   358,   275,   358,
     275,   358,   271,     6,    -1,    87,     6,    -1,    87,   270,
     330,   271,    -1,    89,     6,    -1,    90,     6,    -1,    91,
       6,    -1,    92,     6,    -1,   131,     6,    -1,   132,     6,
      -1,   134,   270,   375,   271,     6,    -1,   134,   270,   375,
     271,   270,   329,   271,     6,    -1,   213,   266,   270,   375,
     271,   275,   381,   275,   381,   267,     6,    -1,   201,   266,
     358,     8,   358,   267,    -1,   201,   266,   358,     8,   358,
       8,   358,   267,    -1,   201,     4,   202,   270,   358,     8,
     358,   271,    -1,   201,     4,   202,   270,   358,     8,   358,
       8,   358,   271,    -1,   203,    -1,   214,     4,    -1,   214,
     381,    -1,   211,    -1,   212,   390,     6,    -1,   212,   381,
       6,    -1,   204,   266,   358,   267,    -1,   205,   266,   358,
     267,    -1,   206,    -1,   207,    -1,   158,   368,   270,   330,
     271,    -1,   158,   270,   368,   275,   368,   275,   358,   271,
     270,   330,   271,    -1,   158,   270,   368,   275,   368,   275,
     368,   275,   358,   271,   270,   330,   271,    -1,    -1,   158,
     368,   270,   330,   339,   343,   271,    -1,    -1,   158,   270,
     368,   275,   368,   275,   358,   271,   270,   330,   340,   343,
     271,    -1,    -1,   158,   270,   368,   275,   368,   275,   368,
     275,   358,   271,   270,   330,   341,   343,   271,    -1,    -1,
     158,   270,   330,   342,   343,   271,    -1,   158,   270,   330,
     271,   149,   123,   270,   358,   271,    -1,   138,   371,    -1,
     143,   138,   371,    -1,   140,   270,   375,   271,   270,   375,
     271,   270,   375,   271,    -1,   141,   270,   375,   271,   270,
     375,   271,   270,   375,   271,   270,   375,   271,    -1,   344,
      -1,   343,   344,    -1,   179,   270,   358,   271,     6,    -1,
     179,   270,   371,   275,   371,   271,     6,    -1,   180,     6,
      -1,   167,     6,    -1,   167,   358,     6,    -1,   185,     6,
      -1,   185,   187,     6,    -1,   186,     6,    -1,   186,   187,
       6,    -1,   181,   266,   358,   267,     7,   371,   149,   358,
       6,    -1,   149,     4,   268,   358,   269,     6,    -1,   161,
      -1,   162,    -1,   163,    -1,   164,    -1,   165,    -1,    -1,
     170,     6,    -1,   152,   170,     6,    -1,   170,   358,     6,
      -1,   152,   170,   358,     6,    -1,   345,   270,   330,   346,
     271,   270,   330,   346,   271,    -1,   120,   266,   380,   267,
      -1,    88,   270,   330,   271,   270,   358,   271,    -1,    88,
     270,   330,   271,   270,   358,   275,   358,   271,    -1,   173,
     270,   330,   271,   270,   358,   271,    -1,   173,   270,   330,
     271,   270,   358,   275,   358,   271,    -1,   120,   266,   380,
     275,   358,   267,    -1,   120,   266,   380,   275,   358,   275,
     358,   267,    -1,   120,   266,   380,   275,   358,   275,   358,
     275,   358,   267,    -1,   345,   266,   358,   267,     7,   270,
     330,   346,   271,   270,   330,   346,   271,     6,    -1,    -1,
     149,     4,   358,    -1,    -1,     4,    -1,    -1,     7,   371,
      -1,    -1,     7,   358,    -1,    -1,   159,   371,    -1,   177,
     373,     7,   358,     6,    -1,   127,   128,   373,     7,   358,
       6,    -1,   144,   108,   373,     7,   358,   349,     6,    -1,
     144,   111,   373,   351,   350,     6,    -1,   144,   113,   373,
     351,     6,    -1,   188,   373,     6,    -1,   103,   324,   266,
     358,   275,   358,   267,     6,    -1,   223,   324,   266,   358,
     267,     6,    -1,   175,   111,   270,   375,   271,     7,   358,
       6,    -1,   178,   111,   270,   375,   271,     7,   358,     6,
      -1,   167,   111,   373,   352,     6,    -1,   167,   113,   373,
       6,    -1,   168,   111,   373,     7,   358,     6,    -1,   147,
     108,   270,   375,   271,     7,   270,   375,   271,   353,     6,
      -1,   147,   111,   270,   375,   271,     7,   270,   375,   271,
     353,     6,    -1,   147,   108,   270,   375,   271,     7,   270,
     375,   271,   154,   270,   368,   275,   368,   275,   358,   271,
       6,    -1,   147,   111,   270,   375,   271,     7,   270,   375,
     271,   154,   270,   368,   275,   368,   275,   358,   271,     6,
      -1,   147,   108,   270,   375,   271,     7,   270,   375,   271,
     155,   368,     6,    -1,   147,   111,   270,   375,   271,     7,
     270,   375,   271,   155,   368,     6,    -1,   147,   111,   358,
     270,   375,   271,     7,   358,   270,   375,   271,     6,    -1,
     324,   270,   375,   271,   202,   324,   270,   358,   271,     6,
      -1,   176,   326,   373,     6,    -1,   135,   327,   373,     6,
      -1,   136,   113,   371,     6,    -1,   151,   108,   371,     6,
      -1,   146,   325,   371,     6,    -1,   146,   325,   371,   175,
     358,     6,    -1,   171,     6,    -1,   171,     4,     6,    -1,
     171,   105,   270,   375,   271,     6,    -1,   172,   270,   330,
     271,    -1,   172,     6,    -1,   224,    -1,   225,    -1,   226,
      -1,   356,     6,    -1,   356,   270,   371,   271,     6,    -1,
     356,   270,   371,   275,   371,   271,     6,    -1,   356,   266,
     371,   267,   270,   371,   275,   371,   271,     6,    -1,   359,
      -1,   266,   358,   267,    -1,   255,   358,    -1,   254,   358,
      -1,   261,   358,    -1,   358,   255,   358,    -1,   358,   254,
     358,    -1,   358,   256,   358,    -1,   358,   257,   358,    -1,
     358,   259,   358,    -1,   358,   260,   358,    -1,   358,   258,
     358,    -1,   358,   265,   358,    -1,   358,   248,   358,    -1,
     358,   249,   358,    -1,   358,   253,   358,    -1,   358,   252,
     358,    -1,   358,   247,   358,    -1,   358,   246,   358,    -1,
     358,   245,   358,    -1,   358,   244,   358,    -1,   358,   250,
     358,    -1,   358,   251,   358,    -1,   358,   243,   358,     8,
     358,    -1,    26,   300,   358,   301,    -1,    16,   300,   358,
     301,    -1,    17,   300,   358,   301,    -1,    18,   300,   358,
     301,    -1,    19,   300,   358,   301,    -1,    20,   300,   358,
     301,    -1,    21,   300,   358,   301,    -1,    22,   300,   358,
     301,    -1,    23,   300,   358,   301,    -1,    24,   300,   358,
     301,    -1,    27,   300,   358,   301,    -1,    28,   300,   358,
     275,   358,   301,    -1,    29,   300,   358,   301,    -1,    30,
     300,   358,   301,    -1,    31,   300,   358,   301,    -1,    32,
     300,   358,   301,    -1,    33,   300,   358,   301,    -1,    34,
     300,   358,   301,    -1,    35,   300,   358,   301,    -1,    36,
     300,   358,   301,    -1,    39,   300,   358,   275,   358,   301,
      -1,    40,   300,   358,   275,   358,   301,    -1,    41,   300,
     358,   275,   358,   301,    -1,    25,   300,   358,   301,    -1,
      38,   300,   358,   275,   358,   301,    -1,    37,   300,   358,
     275,   358,   301,    -1,     3,    -1,    10,    -1,    15,    -1,
      11,    -1,    12,    -1,   231,    -1,   232,    -1,   233,    -1,
      83,    -1,    84,    -1,    85,    -1,    -1,    96,   300,   358,
     360,   311,   301,    -1,   363,    -1,   221,   300,   380,   301,
      -1,   221,   300,   380,   275,   358,   301,    -1,   365,    -1,
     390,   268,   358,   269,    -1,   390,   266,   358,   267,    -1,
     227,   266,   365,   267,    -1,   227,   266,   365,   272,   302,
     267,    -1,   229,   266,   365,   361,   267,    -1,   229,   266,
     365,   272,   302,   361,   267,    -1,   229,   266,   365,   300,
     358,   301,   361,   267,    -1,   229,   266,   365,   272,   302,
     300,   358,   301,   361,   267,    -1,   228,   266,   381,   267,
      -1,   273,   390,   300,   301,    -1,   273,   365,   272,   302,
     300,   301,    -1,    99,   300,   390,   301,    -1,    99,   300,
     301,    -1,   390,   299,    -1,   390,   268,   358,   269,   299,
      -1,   390,   266,   358,   267,   299,    -1,   390,   272,   302,
      -1,   390,     9,   390,   272,   302,    -1,   390,   272,   302,
     266,   358,   267,    -1,   390,     9,   390,   272,   302,   266,
     358,   267,    -1,   390,   272,   302,   268,   358,   269,    -1,
     390,     9,   390,   272,   302,   268,   358,   269,    -1,   390,
     268,   358,   269,   272,   302,    -1,   390,   272,   302,   299,
      -1,   390,   268,   358,   269,   272,   302,   299,    -1,   217,
     266,   380,   275,   358,   267,    -1,    60,   266,   371,   275,
     371,   267,    -1,    61,   300,   380,   275,   380,   301,    -1,
      59,   300,   380,   301,    -1,    62,   300,   380,   275,   380,
     301,    -1,    67,   266,   387,   267,    -1,    -1,   275,   358,
      -1,    -1,   275,   380,    -1,    -1,    97,   365,   367,   364,
     268,   312,   269,    -1,   390,    -1,   390,     9,   390,    -1,
     100,    -1,   100,   358,    -1,    -1,   266,   366,   267,    -1,
     369,    -1,   255,   368,    -1,   254,   368,    -1,   368,   255,
     368,    -1,   368,   254,   368,    -1,   270,   358,   275,   358,
     275,   358,   275,   358,   275,   358,   271,    -1,   270,   358,
     275,   358,   275,   358,   275,   358,   271,    -1,   270,   358,
     275,   358,   275,   358,   271,    -1,   266,   358,   275,   358,
     275,   358,   267,    -1,   371,    -1,   370,   275,   371,    -1,
     358,    -1,   374,    -1,   270,   271,    -1,   270,   375,   271,
      -1,   255,   270,   375,   271,    -1,   358,   256,   270,   375,
     271,    -1,   270,   271,    -1,   270,   375,   271,    -1,   255,
     270,   375,   271,    -1,   371,    -1,   270,     8,   271,    -1,
       5,    -1,   255,   374,    -1,   358,   256,   374,    -1,   358,
       8,   358,    -1,   358,     8,   358,     8,   358,    -1,   105,
     270,   358,   271,    -1,   105,   270,     8,   271,    -1,   105,
       5,    -1,   325,   270,     8,   271,    -1,   325,     5,    -1,
     145,   324,   373,    -1,   145,   324,   270,   376,   271,    -1,
     148,   324,   371,    -1,   324,   202,    68,   371,    -1,    68,
     324,   270,   375,   271,    -1,    77,   325,   270,   358,   271,
      -1,    78,   325,   270,   358,   271,    -1,    79,   325,   270,
     358,   271,    -1,   129,    68,   326,   270,   358,   271,    -1,
     125,   111,   270,   358,   271,   129,   270,   358,   275,   358,
     271,    -1,   126,   111,   270,   358,   271,   129,   270,   358,
     275,   358,   271,    -1,   126,   108,   270,   358,   271,   129,
     270,   358,   271,    -1,   129,   105,   270,   358,   271,   202,
     111,   270,   358,   271,    -1,   199,   325,   270,   358,   271,
      -1,   328,    -1,   338,    -1,   347,    -1,   390,   300,   301,
      -1,   390,   272,   302,   300,   301,    -1,   390,     9,   390,
     272,   302,   300,   301,    -1,    42,   268,   390,   269,    -1,
      42,   268,   374,   269,    -1,    42,   266,   374,   267,    -1,
      42,   300,   270,   375,   271,   301,    -1,   390,   300,   270,
     375,   271,   301,    -1,    43,   300,   358,   275,   358,   275,
     358,   301,    -1,    44,   300,   358,   275,   358,   275,   358,
     301,    -1,    45,   300,   380,   301,    -1,    46,   300,   358,
     275,   358,   275,   358,   275,   358,   275,   358,   275,   358,
     301,    -1,   222,   300,   374,   301,    -1,    33,   300,   374,
     301,    -1,   358,    -1,   374,    -1,   375,   275,   358,    -1,
     375,   275,   374,    -1,   381,    -1,   376,   275,   381,    -1,
     270,   358,   275,   358,   275,   358,   275,   358,   271,    -1,
     270,   358,   275,   358,   275,   358,   271,    -1,   390,    -1,
       4,   272,   199,   272,     4,    -1,   270,   379,   271,    -1,
     390,   268,   358,   269,   272,   200,    -1,   377,    -1,   379,
     275,   377,    -1,   381,    -1,   390,    -1,   390,   268,   358,
     269,    -1,   390,   266,   358,   267,    -1,   390,   272,   302,
      -1,   390,     9,   390,   272,   302,    -1,   390,   272,   302,
     266,   358,   267,    -1,   390,     9,   390,   272,   302,   266,
     358,   267,    -1,   390,   268,   358,   269,   272,     4,    -1,
     324,   270,   358,   271,    -1,   145,   324,   270,   358,   271,
      -1,     5,    -1,   236,   268,   390,   269,    -1,    71,    -1,
     234,    -1,    80,    -1,    82,    -1,   219,   266,   380,   267,
      -1,   218,   266,   380,   275,   380,   267,    -1,   220,   300,
     380,   301,    -1,   220,   300,   380,   275,   380,   301,    -1,
     230,   266,   365,   362,   267,    -1,   230,   266,   365,   272,
     302,   362,   267,    -1,    52,   300,   387,   301,    -1,    53,
     266,   380,   267,    -1,    54,   266,   380,   267,    -1,    55,
     266,   380,   275,   380,   275,   380,   267,    -1,    50,   300,
     387,   301,    -1,    64,   300,   380,   301,    -1,    65,   300,
     380,   301,    -1,    66,   300,   380,   301,    -1,    63,   300,
     358,   275,   380,   275,   380,   301,    -1,    58,   300,   380,
     275,   358,   275,   358,   301,    -1,    58,   300,   380,   275,
     358,   301,    -1,    51,   300,   380,   301,    -1,    51,   300,
     380,   275,   375,   301,    -1,    72,   300,   380,   301,    -1,
      73,    -1,    74,    -1,    57,   300,   380,   301,    -1,    56,
     300,   380,   301,    -1,    -1,   101,   300,   381,   382,   315,
     301,    -1,    98,   300,   383,   301,    -1,   273,   358,    -1,
     390,     9,   273,   358,    -1,    50,   300,   386,   301,    -1,
     387,    -1,   386,    -1,   270,   387,   271,    -1,   380,    -1,
     388,    -1,   387,   275,   380,    -1,   387,   275,   388,    -1,
     390,   266,   267,    -1,   390,   272,   302,   266,   267,    -1,
     390,     9,   390,   272,   302,   266,   267,    -1,     4,   274,
     270,   358,   271,    -1,   389,   274,   270,   358,   271,    -1,
     237,   268,   380,   269,   274,   270,   358,   271,    -1,     4,
      -1,   389,    -1,   237,   268,   380,   269,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   287,   287,   288,   293,   295,   299,   300,   301,   302,
     336,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,   349,   350,   354,   358,   365,   370,   375,
     380,   394,   407,   420,   433,   461,   475,   488,   501,   520,
     525,   526,   527,   528,   529,   530,   534,   536,   541,   543,
     549,   568,   548,   581,   586,   595,   594,   607,   612,   621,
     620,   633,   650,   673,   672,   690,   691,   692,   693,   694,
     698,   699,   705,   705,   707,   707,   712,   713,   714,   715,
     716,   717,   723,   724,   725,   726,   731,   737,   798,   813,
     841,   851,   856,   864,   869,   877,   886,   891,   903,   920,
     926,   935,   953,   971,   980,   992,   997,  1005,  1025,  1048,
    1068,  1076,  1093,  1111,  1149,  1170,  1182,  1196,  1196,  1198,
    1200,  1209,  1219,  1218,  1239,  1238,  1256,  1266,  1265,  1279,
    1281,  1289,  1295,  1300,  1327,  1329,  1332,  1334,  1338,  1339,
    1343,  1355,  1359,  1363,  1367,  1380,  1394,  1402,  1415,  1417,
    1421,  1422,  1427,  1435,  1444,  1452,  1466,  1484,  1488,  1499,
    1508,  1511,  1517,  1521,  1533,  1536,  1543,  1546,  1552,  1575,
    1591,  1607,  1624,  1641,  1678,  1722,  1738,  1754,  1786,  1802,
    1819,  1835,  1885,  1903,  1924,  1945,  1951,  1957,  1964,  2005,
    2020,  2052,  2086,  2119,  2154,  2189,  2224,  2248,  2274,  2291,
    2307,  2325,  2343,  2355,  2369,  2368,  2398,  2400,  2402,  2404,
    2406,  2414,  2416,  2418,  2420,  2428,  2430,  2432,  2440,  2442,
    2444,  2446,  2456,  2472,  2488,  2504,  2520,  2536,  2553,  2579,
    2622,  2643,  2664,  2690,  2691,  2696,  2699,  2703,  2720,  2740,
    2760,  2780,  2799,  2826,  2851,  2876,  2888,  2894,  2909,  2940,
    2952,  2961,  2968,  2980,  3000,  3004,  3009,  3013,  3018,  3025,
    3032,  3039,  3051,  3127,  3145,  3170,  3185,  3236,  3242,  3254,
    3286,  3290,  3294,  3299,  3307,  3312,  3323,  3328,  3334,  3342,
    3353,  3361,  3365,  3369,  3373,  3380,  3384,  3388,  3392,  3396,
    3409,  3419,  3439,  3465,  3481,  3498,  3515,  3537,  3559,  3594,
    3602,  3610,  3616,  3623,  3630,  3650,  3676,  3688,  3699,  3717,
    3735,  3754,  3753,  3778,  3777,  3804,  3803,  3828,  3827,  3850,
    3866,  3883,  3900,  3937,  3965,  3968,  3974,  3986,  4006,  4010,
    4014,  4018,  4022,  4026,  4030,  4034,  4043,  4056,  4057,  4058,
    4059,  4060,  4064,  4065,  4066,  4067,  4068,  4071,  4111,  4138,
    4144,  4150,  4156,  4162,  4168,  4174,  4183,  4221,  4224,  4252,
    4255,  4272,  4275,  4281,  4284,  4291,  4294,  4301,  4324,  4343,
    4385,  4431,  4472,  4498,  4505,  4516,  4534,  4552,  4583,  4610,
    4637,  4669,  4697,  4723,  4749,  4775,  4801,  4823,  4835,  4884,
    4939,  4955,  4967,  4973,  4985,  4992,  5007,  5016,  5048,  5077,
    5078,  5079,  5083,  5089,  5101,  5119,  5147,  5148,  5149,  5150,
    5151,  5152,  5153,  5154,  5155,  5162,  5163,  5164,  5165,  5166,
    5167,  5168,  5169,  5170,  5171,  5172,  5173,  5174,  5175,  5176,
    5177,  5178,  5179,  5180,  5181,  5182,  5183,  5184,  5185,  5186,
    5187,  5188,  5189,  5190,  5191,  5192,  5193,  5194,  5195,  5196,
    5197,  5198,  5199,  5200,  5201,  5202,  5211,  5212,  5213,  5214,
    5215,  5216,  5217,  5218,  5219,  5220,  5221,  5226,  5225,  5233,
    5237,  5242,  5247,  5251,  5256,  5261,  5265,  5269,  5273,  5277,
    5281,  5285,  5291,  5306,  5310,  5316,  5321,  5340,  5360,  5381,
    5385,  5389,  5393,  5397,  5401,  5405,  5410,  5420,  5430,  5435,
    5446,  5455,  5460,  5465,  5493,  5494,  5500,  5501,  5507,  5506,
    5529,  5531,  5536,  5538,  5544,  5545,  5550,  5554,  5558,  5562,
    5566,  5573,  5577,  5581,  5585,  5592,  5597,  5604,  5609,  5613,
    5617,  5621,  5629,  5640,  5644,  5648,  5659,  5663,  5667,  5681,
    5689,  5697,  5704,  5714,  5737,  5742,  5748,  5753,  5759,  5770,
    5776,  5782,  5796,  5802,  5814,  5828,  5841,  5872,  5896,  5917,
    5937,  5958,  5975,  5985,  5995,  6005,  6017,  6021,  6026,  6038,
    6042,  6046,  6050,  6068,  6076,  6084,  6113,  6123,  6139,  6150,
    6155,  6159,  6163,  6175,  6180,  6187,  6191,  6203,  6220,  6230,
    6234,  6249,  6254,  6261,  6265,  6270,  6284,  6298,  6302,  6306,
    6310,  6314,  6322,  6328,  6337,  6341,  6345,  6353,  6359,  6365,
    6369,  6376,  6384,  6391,  6400,  6404,  6408,  6423,  6437,  6451,
    6463,  6479,  6488,  6497,  6507,  6518,  6526,  6534,  6538,  6556,
    6563,  6569,  6575,  6582,  6590,  6589,  6599,  6623,  6625,  6631,
    6636,  6638,  6643,  6648,  6653,  6655,  6659,  6671,  6685,  6689,
    6696,  6704,  6712,  6723,  6725,  6728
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "tDOUBLE", "tSTRING", "tBIGSTR", "tEND",
  "tAFFECT", "tDOTS", "tSCOPE", "tPi", "tMPI_Rank", "tMPI_Size",
  "tEuclidean", "tCoordinates", "tTestLevel", "tExp", "tLog", "tLog10",
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
  "tCreateMeshEdges", "tCreateMeshFaces", "tDistanceFunction",
  "tDefineConstant", "tUndefineConstant", "tDefineNumber", "tDefineStruct",
  "tNameStruct", "tDimNameSpace", "tAppend", "tDefineString", "tSetNumber",
  "tSetTag", "tSetString", "tPoint", "tCircle", "tEllipse", "tCurve",
  "tSphere", "tPolarSphere", "tSurface", "tSpline", "tVolume", "tBox",
  "tCylinder", "tCone", "tTorus", "tEllipsoid", "tQuadric",
  "tShapeFromFile", "tRectangle", "tDisk", "tWire", "tGeoEntity",
  "tNormal", "tCurvature", "tCharacteristic", "tLength", "tParametric",
  "tElliptic", "tRefineMesh", "tRecombineMesh", "tAdaptMesh",
  "tTransformMesh", "tRelocateMesh", "tReorientMesh", "tSetFactory",
  "tThruSections", "tWedge", "tFillet", "tChamfer", "tPlane", "tRuled",
  "tTransfinite", "tPhysical", "tCompound", "tPeriodic", "tParent",
  "tUsing", "tPlugin", "tDegenerated", "tRecursive", "tSewing", "tRotate",
  "tTranslate", "tSymmetry", "tDilate", "tExtrude", "tAffine", "tClosest",
  "tBooleanUnion", "tBooleanIntersection", "tBooleanDifference",
  "tBooleanSection", "tBooleanFragments", "tThickSolid", "tRecombine",
  "tSmoother", "tSplit", "tDelete", "tCoherence", "tHealShapes",
  "tRecognizeShapes", "tIntersect", "tMeshAlgorithm", "tReverseMesh",
  "tMeshSize", "tMeshSizeFromBoundary", "tLayers", "tScaleLast", "tHole",
  "tAlias", "tAliasWithOptions", "tCopyOptions", "tQuadTriAddVerts",
  "tQuadTriNoNewVerts", "tRecombLaterals", "tTransfQuadTri", "tText2D",
  "tText3D", "tInterpolationScheme", "tTime", "tCombine", "tBSpline",
  "tBezier", "tNurbs", "tNurbsOrder", "tNurbsKnots", "tColor",
  "tColorTable", "tFor", "tIn", "tEndFor", "tIf", "tElseIf", "tElse",
  "tEndIf", "tExit", "tAbort", "tField", "tReturn", "tCall", "tSlide",
  "tMacro", "tShow", "tHide", "tGetValue", "tGetStringValue", "tGetEnv",
  "tGetString", "tGetNumber", "tUnique", "tSetMaxTag", "tHomology",
  "tCohomology", "tBetti", "tExists", "tFileExists", "tGetForced",
  "tGetForcedStr", "tGMSH_MAJOR_VERSION", "tGMSH_MINOR_VERSION",
  "tGMSH_PATCH_VERSION", "tGmshExecutableName", "tSetPartition",
  "tNameToString", "tStringToName", "tUnsplitWindow", "tAFFECTDIVIDE",
  "tAFFECTTIMES", "tAFFECTMINUS", "tAFFECTPLUS", "'?'", "tOR", "tAND",
  "tNOTEQUAL", "tEQUAL", "'<'", "'>'", "tGREATERGREATER", "tLESSLESS",
  "tGREATEROREQUAL", "tLESSOREQUAL", "'+'", "'-'", "'*'", "'/'", "'%'",
  "'|'", "'&'", "'!'", "UNARYPREC", "tMINUSMINUS", "tPLUSPLUS", "'^'",
  "'('", "')'", "'['", "']'", "'{'", "'}'", "'.'", "'#'", "'~'", "','",
  "$accept", "All", "GeoFormatItems", "GeoFormatItem", "SendToFile",
  "Printf", "View", "Views", "ElementCoords", "ElementValues", "Element",
  "@1", "@2", "Text2DValues", "Text2D", "@3", "Text3DValues", "Text3D",
  "@4", "InterpolationMatrix", "Time", "@5", "NumericAffectation",
  "NumericIncrement", "LP", "RP", "tSTRING_Reserved", "Affectation",
  "Comma", "DefineConstants", "@6", "@7", "@8", "UndefineConstants",
  "Enumeration", "FloatParameterOptionsOrNone",
  "FloatParameterOptionsOrNone_NoComma", "FloatParameterOptions",
  "FloatParameterOption", "CharParameterOptionsOrNone",
  "CharParameterOptions", "CharParameterOption",
  "PhysicalId_per_dim_entity", "SurfaceConstraints", "CircleOptions",
  "LoopOptions", "Shape", "@9", "GeoEntity", "GeoEntity123", "GeoEntity12",
  "GeoEntity012", "Transform", "MultipleShape", "ListOfShapes", "Delete",
  "Colorify", "SetPartition", "Visibility", "Command", "Slide", "Loop",
  "Extrude", "@10", "@11", "@12", "@13", "ExtrudeParameters",
  "ExtrudeParameter", "BooleanOperator", "BooleanOption", "Boolean",
  "BooleanShape", "TransfiniteType", "TransfiniteArrangement",
  "TransfiniteCorners", "RecombineAngle", "PeriodicTransform",
  "Constraints", "Coherence", "HomologyCommand", "Homology", "FExpr",
  "FExpr_Single", "@14", "GetForced_Default", "GetForcedStr_Default",
  "DefineStruct", "@15", "Struct_FullName", "Append", "AppendOrNot",
  "VExpr", "VExpr_Single", "RecursiveListOfListOfDouble", "ListOfDouble",
  "ListOfDoubleWithBraces", "ListOfDoubleOrAll", "FExpr_Multi",
  "RecursiveListOfDouble", "ListOfPhysicalNames", "ColorExpr",
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
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     495,   496,   497,    63,   498,   499,   500,   501,    60,    62,
     502,   503,   504,   505,    43,    45,    42,    47,    37,   124,
      38,    33,   506,   507,   508,    94,    40,    41,    91,    93,
     123,   125,    46,    35,   126,    44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   276,   277,   277,   278,   278,   279,   279,   279,   279,
     279,   279,   279,   279,   279,   279,   279,   279,   279,   279,
     279,   279,   279,   279,   279,   280,   280,   281,   281,   281,
     281,   281,   281,   281,   281,   282,   282,   282,   282,   283,
     283,   283,   283,   283,   283,   283,   284,   284,   285,   285,
     287,   288,   286,   289,   289,   291,   290,   292,   292,   294,
     293,   295,   295,   297,   296,   298,   298,   298,   298,   298,
     299,   299,   300,   300,   301,   301,   302,   302,   302,   302,
     302,   302,   303,   303,   303,   303,   303,   303,   303,   303,
     303,   303,   303,   303,   303,   303,   303,   303,   303,   303,
     303,   303,   303,   303,   303,   303,   303,   303,   303,   303,
     303,   303,   303,   303,   303,   303,   303,   304,   304,   305,
     305,   305,   306,   305,   307,   305,   305,   308,   305,   309,
     309,   310,   310,   310,   311,   311,   312,   312,   313,   313,
     314,   314,   314,   314,   314,   314,   314,   314,   315,   315,
     316,   316,   317,   317,   317,   317,   317,   318,   318,   318,
     319,   319,   319,   319,   320,   320,   321,   321,   322,   322,
     322,   322,   322,   322,   322,   322,   322,   322,   322,   322,
     322,   322,   322,   322,   322,   322,   322,   322,   322,   322,
     322,   322,   322,   322,   322,   322,   322,   322,   322,   322,
     322,   322,   322,   322,   323,   322,   324,   324,   324,   324,
     324,   325,   325,   325,   325,   326,   326,   326,   327,   327,
     327,   327,   328,   328,   328,   328,   328,   328,   328,   328,
     328,   328,   328,   329,   329,   330,   330,   330,   330,   330,
     330,   330,   330,   331,   331,   331,   331,   331,   331,   331,
     331,   332,   332,   333,   334,   334,   334,   334,   334,   334,
     334,   334,   335,   335,   335,   335,   335,   335,   335,   335,
     335,   335,   335,   335,   335,   335,   335,   335,   335,   335,
     335,   335,   335,   335,   335,   335,   335,   335,   335,   335,
     335,   335,   335,   336,   337,   337,   337,   337,   337,   337,
     337,   337,   337,   337,   337,   337,   337,   337,   338,   338,
     338,   339,   338,   340,   338,   341,   338,   342,   338,   338,
     338,   338,   338,   338,   343,   343,   344,   344,   344,   344,
     344,   344,   344,   344,   344,   344,   344,   345,   345,   345,
     345,   345,   346,   346,   346,   346,   346,   347,   347,   347,
     347,   347,   347,   347,   347,   347,   348,   349,   349,   350,
     350,   351,   351,   352,   352,   353,   353,   354,   354,   354,
     354,   354,   354,   354,   354,   354,   354,   354,   354,   354,
     354,   354,   354,   354,   354,   354,   354,   354,   354,   354,
     354,   354,   354,   354,   355,   355,   355,   355,   355,   356,
     356,   356,   357,   357,   357,   357,   358,   358,   358,   358,
     358,   358,   358,   358,   358,   358,   358,   358,   358,   358,
     358,   358,   358,   358,   358,   358,   358,   358,   358,   358,
     358,   358,   358,   358,   358,   358,   358,   358,   358,   358,
     358,   358,   358,   358,   358,   358,   358,   358,   358,   358,
     358,   358,   358,   358,   358,   358,   359,   359,   359,   359,
     359,   359,   359,   359,   359,   359,   359,   360,   359,   359,
     359,   359,   359,   359,   359,   359,   359,   359,   359,   359,
     359,   359,   359,   359,   359,   359,   359,   359,   359,   359,
     359,   359,   359,   359,   359,   359,   359,   359,   359,   359,
     359,   359,   359,   359,   361,   361,   362,   362,   364,   363,
     365,   365,   366,   366,   367,   367,   368,   368,   368,   368,
     368,   369,   369,   369,   369,   370,   370,   371,   371,   371,
     371,   371,   371,   372,   372,   372,   373,   373,   373,   374,
     374,   374,   374,   374,   374,   374,   374,   374,   374,   374,
     374,   374,   374,   374,   374,   374,   374,   374,   374,   374,
     374,   374,   374,   374,   374,   374,   374,   374,   374,   374,
     374,   374,   374,   374,   374,   374,   374,   374,   374,   375,
     375,   375,   375,   376,   376,   377,   377,   377,   377,   378,
     378,   379,   379,   380,   380,   380,   380,   380,   380,   380,
     380,   380,   380,   380,   381,   381,   381,   381,   381,   381,
     381,   381,   381,   381,   381,   381,   381,   381,   381,   381,
     381,   381,   381,   381,   381,   381,   381,   381,   381,   381,
     381,   381,   381,   381,   382,   381,   381,   383,   383,   384,
     385,   385,   386,   387,   387,   387,   387,   388,   388,   388,
     389,   389,   389,   390,   390,   390
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     2,     1,     1,     1,     5,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     5,     5,     5,
       7,     7,     7,     7,     9,     6,     6,     6,     8,     0,
       2,     2,     2,     2,     2,     2,     1,     3,     1,     3,
       0,     0,    10,     1,     3,     0,    13,     1,     3,     0,
      15,     8,    14,     0,     6,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     5,     5,     2,     7,     7,     4,     3,     6,
       9,     7,     6,     7,     6,     4,     8,     9,     9,     6,
       9,     6,     9,     5,     8,     8,    11,     6,     9,     5,
       7,     9,     9,     9,     7,     9,     9,     0,     1,     0,
       3,     5,     0,     9,     0,    11,     5,     0,     9,     0,
       3,     3,     5,     5,     0,     2,     0,     1,     1,     3,
       2,     2,     2,     2,     1,     4,     2,     2,     0,     2,
       1,     3,     2,     2,     2,     2,     2,     1,     1,     3,
       0,     5,     5,     5,     0,     2,     0,     2,     7,     7,
       7,    10,    10,     8,     8,     7,     7,    11,     7,     8,
       8,     8,     9,     8,     8,     3,     4,    10,     7,     7,
       7,     7,     7,     7,     7,     7,     7,     7,     9,     7,
       7,     8,     8,    12,     0,     9,     1,     1,     1,     1,
       4,     1,     1,     1,     4,     1,     1,     4,     1,     1,
       1,     4,     5,    11,     5,     9,     9,     7,     7,     4,
       9,    10,     9,     1,     1,     0,     2,     6,     7,     7,
       7,     6,     7,     4,     5,     5,     6,     6,     3,     4,
       3,     5,     6,     5,     4,     3,     4,     3,     4,     5,
       4,     5,     3,     5,     7,     7,     3,     2,     7,     3,
       2,     3,     2,     2,     2,     2,    15,     2,     2,     7,
       2,     9,    11,     2,     4,     2,     2,     2,     2,     2,
       2,     5,     8,    11,     6,     8,     8,    10,     1,     2,
       2,     1,     3,     3,     4,     4,     1,     1,     5,    11,
      13,     0,     7,     0,    13,     0,    15,     0,     6,     9,
       2,     3,    10,    13,     1,     2,     5,     7,     2,     2,
       3,     2,     3,     2,     3,     9,     6,     1,     1,     1,
       1,     1,     0,     2,     3,     3,     4,     9,     4,     7,
       9,     7,     9,     6,     8,    10,    14,     0,     3,     0,
       1,     0,     2,     0,     2,     0,     2,     5,     6,     7,
       6,     5,     3,     8,     6,     8,     8,     5,     4,     6,
      11,    11,    18,    18,    12,    12,    12,    10,     4,     4,
       4,     4,     4,     6,     2,     3,     6,     4,     2,     1,
       1,     1,     2,     5,     7,    10,     1,     3,     2,     2,
       2,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     5,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     6,     4,     4,     4,     4,     4,     4,     4,     4,
       6,     6,     6,     4,     6,     6,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     6,     1,
       4,     6,     1,     4,     4,     4,     6,     5,     7,     8,
      10,     4,     4,     6,     4,     3,     2,     5,     5,     3,
       5,     6,     8,     6,     8,     6,     4,     7,     6,     6,
       6,     4,     6,     4,     0,     2,     0,     2,     0,     7,
       1,     3,     1,     2,     0,     3,     1,     2,     2,     3,
       3,    11,     9,     7,     7,     1,     3,     1,     1,     2,
       3,     4,     5,     2,     3,     4,     1,     3,     1,     2,
       3,     3,     5,     4,     4,     2,     4,     2,     3,     5,
       3,     4,     5,     5,     5,     5,     6,    11,    11,     9,
      10,     5,     1,     1,     1,     3,     5,     7,     4,     4,
       4,     6,     6,     8,     8,     4,    14,     4,     4,     1,
       1,     3,     3,     1,     3,     9,     7,     1,     5,     3,
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
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   206,     0,     0,   207,     0,     0,   208,     0,   209,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   337,   338,   339,
     340,   341,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   298,     0,     0,   306,   307,
       0,     0,     0,   301,     0,     0,     0,     0,     0,     0,
     399,   400,   401,     0,     0,     0,     5,     6,     7,     8,
      10,     0,    11,    12,    13,    14,    15,    23,    22,    21,
      16,     0,    17,    18,    19,    20,     0,    24,     0,   654,
       0,   235,     0,     0,     0,     0,     0,     0,   275,     0,
     277,   278,   273,   274,     0,   280,     0,   283,   235,   235,
     285,   286,   287,   288,   119,   129,   653,   514,   510,    72,
      73,     0,   206,   207,   208,   209,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     289,   290,     0,   218,   219,   220,     0,     0,     0,     0,
     456,   457,   459,   460,   458,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   464,   465,   466,     0,     0,
       0,   206,   211,   212,   213,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     461,   462,   463,     0,     0,     0,     0,     0,     0,     0,
       0,   562,   563,     0,   564,   527,   406,   469,   472,   320,
     528,   510,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   204,   211,   212,     0,   213,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   516,     0,     0,   235,     0,     0,     0,
       0,     0,     0,     0,     0,   653,     0,     0,   235,     0,
       0,   394,     0,   398,   235,   235,     0,     0,   215,   216,
       0,     0,   538,     0,     0,   536,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   653,     0,
       0,   587,     0,     0,     0,     0,   270,     0,     0,     0,
     510,   272,     0,   604,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   606,     0,   630,
     631,   608,   609,     0,     0,     0,     0,     0,     0,   607,
       0,     0,     0,     0,   299,   300,     0,   235,     0,   235,
       0,     0,     0,   267,     0,     0,   235,   402,     0,     0,
      84,     0,    65,     0,     0,    69,    68,    67,    66,    71,
      70,    72,    73,     0,     0,     0,     0,     0,     0,     0,
     593,   510,     0,   234,     0,   233,     0,   185,     0,     0,
     593,   594,     0,     0,     0,   643,     0,   644,   594,     0,
       0,     0,     0,   117,   117,     0,   508,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   579,   580,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    72,    73,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   235,     0,     0,   545,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   409,     0,   408,   539,   410,     0,
     529,     0,     0,   510,     0,   547,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    72,    73,
       0,   486,     0,     0,     0,     0,     0,     0,     0,   321,
       0,   361,   361,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   235,     0,   235,   235,     0,   518,
     517,     0,     0,     0,     0,   235,   235,     0,     0,     0,
       0,   317,     0,   235,     0,     0,     0,   363,     0,     0,
       0,     0,     0,     0,   235,   250,     0,     0,   248,   395,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   372,   269,     0,     0,     0,     0,
       0,     0,     0,   235,     0,     0,     0,     0,     0,   408,
     271,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   303,   302,
       0,   255,     0,     0,   257,     0,     0,     0,   235,     0,
       0,     0,   342,     0,     0,     0,     0,     0,     0,     0,
       0,    76,    79,    77,    78,    80,    81,     0,     0,     0,
       0,    88,    74,    75,     0,     0,     0,   266,    39,   262,
       0,     0,     0,     0,     0,   229,     0,     0,     0,     0,
       0,   236,     0,     0,   186,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   284,     0,     0,     0,   118,     0,     0,     0,
     512,     0,     0,   511,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   348,     0,     0,     0,     0,   210,     0,     0,
       0,     0,     0,     0,   389,   390,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   510,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   467,   485,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   548,   550,     0,     0,     0,     0,
       0,     0,   504,     0,   407,   530,     0,     0,     0,     0,
     541,     0,   426,   425,   424,   423,   419,   420,   427,   428,
     422,   421,   412,   411,     0,   413,   540,   414,   417,   415,
     416,   418,   511,     0,     0,   489,     0,   565,     0,     0,
       0,     0,     0,     0,     0,     0,   359,     0,     0,     0,
       0,     0,     0,   392,     0,     0,     0,     0,     0,   391,
       0,   235,     0,     0,     0,     0,     0,   520,   519,     0,
       0,     0,     0,     0,     0,     0,   311,     0,     0,     0,
       0,     0,   378,     0,     0,     0,   249,     0,     0,     0,
     243,     0,   397,     0,     0,     0,     0,   388,   407,   537,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   304,   305,     0,   413,   511,
     489,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   634,
       0,     0,     0,   506,     0,     0,   254,   258,   256,   260,
       0,     0,   655,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    95,     0,     0,   407,     0,     0,     0,    65,
       0,     0,    87,     0,    65,    66,     0,     0,     0,   511,
       0,     0,   489,     0,     0,     0,   204,     0,     0,     0,
     650,    27,    25,    26,     0,     0,     0,     0,     0,   597,
      29,     0,    28,     0,     0,   263,   645,   646,     0,   647,
     597,     0,     0,     0,    82,   120,    83,   130,   513,   515,
     136,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   291,   235,   581,   582,   221,
       9,   431,   432,   433,   434,   435,   436,   437,   438,   439,
     453,   430,   440,     0,   442,   443,   444,   445,   446,   578,
     447,   448,   449,     0,     0,     0,     0,     0,   570,   569,
     568,     0,     0,     0,   575,     0,   501,     0,     0,     0,
     503,     0,     0,     0,     0,   134,   484,   544,   543,   214,
       0,     0,     0,     0,     0,     0,   583,     0,     0,     0,
     470,   577,   475,     0,   481,     0,     0,     0,     0,   531,
       0,     0,   482,   551,   546,     0,     0,     0,     0,   474,
     473,    72,    73,   496,     0,     0,     0,     0,     0,     0,
       0,   407,   357,   362,   360,     0,   371,     0,   157,   158,
       0,   214,     0,   407,     0,     0,     0,     0,     0,   244,
       0,   259,   261,     0,     0,     0,   222,   224,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   324,
       0,   308,     0,   235,   235,     0,   364,   377,     0,     0,
       0,     0,   245,     0,     0,     0,     0,     0,   217,   367,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   251,     0,     0,     0,     0,     0,     0,     0,   620,
       0,   627,   616,   617,   618,     0,   633,   632,     0,     0,
     621,   622,   623,   629,   637,   636,     0,   148,     0,   610,
       0,   612,     0,     0,     0,   605,     0,     0,   253,     0,
       0,     0,     0,   343,     0,     0,     0,   403,     0,   651,
       0,   109,    65,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   103,     0,     0,     0,     0,   602,
      50,     0,     0,     0,    63,     0,    40,    41,    42,    43,
      44,    45,     0,   474,   473,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   596,   595,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     144,     0,     0,     0,     0,   137,   138,     0,     0,     0,
       0,   164,   164,     0,     0,     0,     0,     0,   160,     0,
       0,     0,     0,     0,     0,   353,     0,     0,     0,     0,
     368,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   552,   553,   554,   555,
       0,     0,     0,     0,     0,     0,     0,   549,     0,   561,
       0,     0,     0,   504,   505,     0,   477,     0,     0,   542,
     429,   532,   490,   488,     0,   487,     0,     0,   566,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   370,     0,
       0,     0,     0,     0,   393,     0,     0,     0,    76,     0,
     252,     0,     0,     0,     0,     0,     0,     0,   329,     0,
       0,   328,     0,   331,     0,   333,     0,   318,   325,     0,
       0,     0,     0,     0,   379,     0,     0,   247,   246,   396,
       0,     0,     0,     0,    36,    37,     0,     0,     0,     0,
       0,     0,   588,     0,     0,     0,   294,   490,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   506,
     507,   614,     0,   374,     0,     0,   235,   344,     0,   345,
     235,     0,     0,   603,     0,    94,     0,     0,     0,     0,
      92,     0,   591,     0,   107,     0,    99,   101,     0,     0,
       0,    89,     0,     0,     0,     0,     0,    35,   490,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    30,    31,     0,   598,     0,     0,    33,    32,
       0,   598,   648,   279,   349,     0,     0,     0,   121,   126,
       0,     0,     0,   140,   146,   147,   143,   141,   142,   509,
       0,    85,     0,    86,   168,     0,     0,     0,     0,   169,
     188,   189,   166,     0,     0,     0,   170,   199,   190,   194,
     195,   191,     0,   192,   193,   178,     0,     0,   441,   455,
     454,   450,   451,   452,   571,     0,     0,     0,   499,   500,
     502,   135,   468,     0,     0,     0,   556,     0,   584,   498,
     471,   476,     0,     0,   504,   200,   483,    72,    73,     0,
     495,   491,   493,   572,   196,     0,     0,     0,   160,     0,
       0,   369,     0,   159,     0,     0,     0,     0,     0,     0,
     268,     0,     0,     0,     0,   235,   235,     0,     0,   330,
     527,     0,     0,   332,   334,     0,     0,   312,   227,   228,
     197,     0,     0,   351,     0,     0,     0,     0,     0,     0,
     175,     0,   176,     0,     0,     0,     0,     0,     0,   110,
     114,     0,   628,     0,     0,   626,     0,   638,     0,     0,
     149,   150,   635,   611,   613,     0,     0,     0,     0,   342,
     346,   342,     0,   404,    93,     0,     0,    65,     0,     0,
      91,     0,   589,     0,     0,     0,     0,     0,     0,   641,
     640,     0,     0,     0,     0,     0,   525,     0,     0,    76,
     264,   491,   265,     0,     0,     0,     0,     0,     0,   241,
     237,     0,     0,   601,   599,     0,     0,     0,     0,     0,
     122,   127,     0,     0,     0,   579,   580,   139,   373,   165,
     173,   174,   179,     0,     0,     0,     0,     0,   181,   354,
       0,     0,   292,     0,     0,     0,     0,     0,     0,     0,
       0,   478,     0,     0,     0,   567,   497,     0,     0,   180,
       0,   201,   358,     0,     0,     0,     0,   202,     0,     0,
       0,     0,     0,     0,   524,   523,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     375,   376,    38,   183,   184,     0,   586,     0,     0,   296,
     295,     0,     0,     0,     0,     0,     0,     0,     0,   152,
     153,   156,   155,   154,     0,   615,     0,   652,     0,     0,
       0,     0,     0,     0,     0,     0,   104,   105,   592,     0,
       0,     0,    96,     0,     0,     0,    46,     0,     0,     0,
       0,     0,    48,     0,   242,   238,   239,   240,    34,     0,
       0,   649,   350,   281,     0,   134,   148,     0,     0,   145,
       0,     0,     0,   167,   198,     0,     0,     0,     0,     0,
     573,   574,     0,     0,     0,     0,     0,   504,   479,   492,
     494,     0,     0,   182,   205,     0,     0,     0,   365,   365,
       0,   115,   116,   235,     0,   225,   226,   319,     0,   326,
       0,     0,   235,     0,   232,     0,   352,   230,     0,     0,
       0,     0,   533,     0,   111,   113,   112,   619,   625,   624,
     151,     0,     0,     0,   347,     0,     0,   108,   100,   102,
       0,    90,   642,    97,    98,    51,     0,     0,     0,     0,
     526,     0,     0,   492,   600,     0,     0,     0,     0,   124,
     639,     0,   131,     0,     0,     0,     0,   355,   187,     0,
       0,   559,     0,     0,     0,   322,     0,   171,   172,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   522,
       0,   336,     0,     0,   313,     0,   231,     0,   585,   297,
       0,   534,     0,   387,   235,   405,     0,   590,     0,    47,
       0,     0,     0,    64,    49,     0,   282,   123,   128,   134,
       0,     0,   162,   163,   161,     0,     0,     0,   560,   480,
       0,     0,     0,     0,   366,   380,     0,     0,   381,     0,
     223,     0,   327,     0,   309,     0,   235,   177,   535,   293,
     342,   106,     0,     0,     0,     0,     0,     0,   132,   133,
       0,   557,   558,     0,   203,     0,   384,     0,   385,   386,
     521,     0,     0,   315,     0,     0,    55,     0,    61,     0,
       0,   125,     0,   323,     0,     0,   335,   314,   310,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     356,    52,     0,    59,     0,   276,   576,     0,     0,   316,
       0,    53,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    56,    54,     0,    57,     0,   382,   383,     0,
       0,    62,    60,    58
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,   126,  1124,   127,   128,  1108,  1995,  2001,
    1416,  1642,  2158,  2260,  1417,  2242,  2274,  1418,  2262,  1419,
    1420,  1646,   464,   631,   632,  1198,  1750,   129,   827,   493,
    2015,  2169,  2016,   494,  1884,  1501,  1454,  1455,  1456,  1606,
    1820,  1821,  1277,  1705,  1696,  1894,   801,   643,   299,   300,
     371,   217,   301,   474,   475,   133,   134,   135,   136,   137,
     138,   139,   302,  1312,  2195,  2239,  1004,  1308,  1309,   303,
    1087,   304,   143,  1537,  1275,   976,  1011,  2133,   144,   145,
     146,   147,   305,   306,  1225,  1248,  1374,   307,   832,   308,
     831,   496,   659,   343,  1855,   375,  1964,   376,   310,   601,
    1235,   390,  1400,  1633,   485,   480,  1367,  1067,  1685,  1848,
    1849,  1052,   487,   149,   400
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1993
static const yytype_int16 yypact[] =
{
   14270,    57,   110, 14484, -1993, -1993,  -178,   151,    79,   -67,
     -60,   -40,    33,   251,   334,   345,   352,   104,    34,    35,
     -39,   377,   387,   431,   443,   255,   281,    41,   116,   531,
     116,   278,   328,   394,    43,   437,   456,    46,   457,   467,
     473,   479,   480,   511,   518,   539,   554,   559,    31,   388,
     500,   560,   679,   516,    87,   700,   561,  7628,   577,   538,
     558,   742,   -49,   385,   531,   -55,   427,   609,   738,  -100,
     619,   -73,   -73,   624,    -8,   642,   664, -1993, -1993, -1993,
   -1993, -1993,   615,   295,   772,   802,     7,    72,    36,   669,
     810,   814,   261,  5736,   821,   940,   943,   946,  5736,   951,
     -75,   -62,   690,    13,    47, -1993,   707,   722, -1993, -1993,
    2485,   983,   724, -1993,  6936,   727, 14741,     3,    20,   531,
   -1993, -1993, -1993, 12741,   726,   984, -1993, -1993, -1993, -1993,
   -1993,   725, -1993, -1993, -1993, -1993, -1993, -1993, -1993, -1993,
   -1993,   248, -1993, -1993, -1993, -1993,    32, -1993,   990,   723,
    6834,   446,   728,   993, 12741, 14677, 14677, 14677, -1993, 12741,
   -1993, -1993, -1993, -1993, 14677, -1993, 12741, -1993, -1993, 12741,
   -1993, -1993, -1993, -1993, -1993, -1993,   747,   756,   992, -1993,
   -1993, 14803, -1993, -1993, -1993, -1993,   757, 14803, 12741, 12741,
   12741,   763, 12741, 12741, 12741,   764, 12741, 12741, 12741, 12741,
   12741, 12741, 12741, 14677, 12741, 12741, 12741, 12741,  5736,   766,
   -1993, -1993,  9999, -1993, -1993, -1993,   755,  5736,  7892, 14677,
   -1993, -1993, -1993, -1993, -1993,   116,   116,   116,   116,   116,
     116,   116,   116,   116,   116,   116,   116,   116,   116,   116,
     116,   116,   116,   116,   116,   116,   116,   116,   116,   116,
     116,   156,   116,   116,   116,   116,   116,   767,   116,   116,
     768,   531,   537,   537,   537, -1993, -1993, -1993,   765,   116,
     116,    23,   834,   835,   837,   770,   931,   551,    -2,  7892,
     905,   531,   531,   537,   778,   116,   116,   780,   781,   783,
   -1993, -1993, -1993, 12741,  8156, 12741, 12741,  8420,    41,   843,
      27, -1993, -1993,   797, -1993,  4829, -1993, -1993, -1993, -1993,
   -1993,   141, 12741,  9999,  9999,   806,   807,  8684,  5736,  5736,
    5736, -1993, -1993, -1993,   811, -1993,   798,   812,  8948,   801,
   10979,  1075,  7892,   815,    13,   816,   818,   -73,   -73,   -73,
   12741, 12741,   140, -1993,   146,   -73, 11069,   319,  9999,  9999,
   12741,  5736,  5736,  5736,   290,    18,  1074,   822, -1993,  1076,
    1078, -1993,   823, -1993, -1993, -1993,   824,   826, -1993, -1993,
     827,  5736, -1993, 12741,  7100, -1993,  1084,   828,   831,   832,
     833,  1096,  1098,   839, 12741,   840, 12741, 12741,   170, 12741,
     838, -1993,   879, 12741, 12741, 12741, -1993,   116, 12741,   974,
     155, -1993, 12741, -1993,   116,   116,   116,   841,   844,   845,
     116,   116,   116,   116,   116,   116,   116, -1993,   116, -1993,
   -1993, -1993, -1993,   116,   116,   846,   847,   116,   851, -1993,
     850,  1103,  1113,   855, -1993, -1993,  1114,  1118,  1121,  1120,
     863, 16672, 14677, -1993,  9999, 12741, -1993, -1993,  7892,  7892,
   -1993,   861, 14803,   531,  1125, -1993, -1993, -1993, -1993, -1993,
   -1993, 12741, 12741,   422,  7892,  1127,   343,   864,  1453,   865,
    1130,    89,   867, -1993,   868, 14936, 12741, -1993,  1619,  -162,
   -1993,    52,   -92,    12,  9144, -1993,   176, -1993,    88,  9408,
    4719,  5381,  9667,   -99,   -81,  1040, -1993,    41,   869, 12741,
     871, 17161, 17186, 17211, 12741, 17236, 17261, 17286, 12741, 17311,
   17336, 17361, 17386, 17411, 17436, 17461,   225, 17486, 17511, 17536,
    5478,  1135, 12741,  9999,  4858, -1993,   -35, 12741,  1137,  1141,
     881, 12741, 12741, 12741, 12741, 12741, 12741, 12741, 12741, 12741,
   12741, 12741, 12741, 12741, 12741, 12741, 12741, 12741,  9999, 12741,
   12741, 12741, 12741, 12741, 12741, 12741, 12741,  9999,  9999,   880,
   12741, 12741, 14677, 12741, 14677,  7892, 14677, 14677, 14677,   884,
     888,   896,   900, -1993, 12741,    15, -1993, 11333, 12741,   901,
     902,   903,   261,   904,  7892,  7364,  7892,   908, 14677, 14677,
    9999,    41, 14803,    41,   886,  9999,   886, -1993,   886, 17561,
   -1993,   258,   877,    66,  1107, -1993,  1171, 12741, 12741, 12741,
   12741, 12741, 12741, 12741, 12741, 12741, 12741, 12741, 12741, 12741,
   12741,  9212, 12741, 12741, 12741, 12741, 12741,    41, 12741, 12741,
     502, -1993,   371, 17586,   430,   489, 12741, 12741, 12741, -1993,
    1192,  1195,  1195,   941, 12741, 12741, 12741, 12741,    28,  9999,
    9999, 16700,   937,  1200, -1993,   939, -1993, -1993,  -174, -1993,
   -1993,  9931, 10289,   -73,   -73,   446,   446,  -126, 11069, 11069,
   12741,  5520,   -68, -1993,   491,   499, 17611,  1201,  1204,  1205,
   12741, 12741,  1207, 12741, -1993, -1993, 12741, 12924, -1993, -1993,
    9999, 12986, 13092,  9999,  9999, 12741,  1229, 17636,   965, 12741,
    9999, 12741, 12741, 12741, -1993, -1993, 12741, 17661, 12741, 17686,
   17711,  1012, 10652, -1993,   967,  4898, 17736, 17761, 12741,   886,
   -1993, 12741,    41, 12741, 12741,   502, 16756, 14677, 14677, 14677,
   14677, 14677, 14677, 14677, 14677, 14677, 12741, 14677, 14677, 14677,
   14677,    26, 14803, 14677, 14677, 14677,    41,    41, -1993, -1993,
    9999, -1993,   969, 13154, -1993,   970, 13260, 12741, -1993,   973,
     501, 17786, 14824,   971,   504, 12741,  1237,   975,  7892, 17811,
   16783, -1993, -1993, -1993, -1993, -1993, -1993,   972,  1239,   189,
    1242, -1993, -1993, -1993,  9999,   223, 12741, -1993, -1993, -1993,
      41, 12741, 12741,   502,   981, -1993,   985,   -29,   531,   -55,
     531, -1993,   980, 15454, -1993,   115,  9999,    41, 12741, 12741,
     502,  1246,  9999,  1247,  9999, 12741,  1248, 14677,    41, 11423,
     502, 12741, -1993,   986, 12741,  1249, -1993,    41,  1251, 14677,
   12741,   991,   998, -1993, 12741, 10926, 14803,  1252,  1253,  1260,
   17836,  1261,  1262,  1263, 17861,  1264,  1265,  1266,  1267,  1268,
    1269,  1271, -1993, 12741,  1272,  1273,  1274, -1993, 12741, 17886,
    9999,    37,  9999, 15483, -1993, -1993,  1276,  6716,  6716,  6716,
    6716,  6716,  6716,  6716,  6716,  6716,  6716,  6716,  6716, 11010,
    6716,  6716,  6716,  6716,   759,   310,  6716,  6716,  6716, 11280,
   11364, 11637, 11713, 11985,  4858,  1016,  1015,    75,  9999, 12069,
   12334,   310, 12418,   310,  1010,  1011,  1014,   250,  9999, 12741,
   12741, 12741, 18661, -1993,   310,  1019, 15512, 15541, 12741, 12741,
   12741,  1021, 12741,  6037, -1993, -1993, 12741,  1017,   145,   310,
    -127,  1026,  -181,   507,  1287, -1993,   502,   310,  7892,  1024,
    5354,  5970,   805,   542,   582,   582,   455,   455,   455,   455,
     455,   455,  -124,  -124,  9999,   207, -1993,   207,   207,   886,
     886,   886,  1028, 17911, 16810,   495,  9999, -1993,  1289,  1033,
    1034, 17936, 17961, 17986, 12741,  7892,  1301,  1300, 10720, 18011,
   15570, 18036, 18061, -1993, 12741,   535,   541,  9999,  1035, -1993,
   13322, -1993, 13428, 13490,   -73, 12741, 12741, -1993, -1993,  1037,
    1038, 11069,  7033,  1161,    -1,   -73, 13596,  1041,  1045,  1309,
   12741,  1311, -1993, 12741, 18086, 15599, -1993, 16837, 13658, 16864,
   -1993,   546, -1993,  1048,   547,   548, 15628, -1993, -1993, -1993,
    1935,   574, 16891, 16918, 12674, 18111,  1312, 18136,  1313,  1314,
    1050, 12741, 13764, 12741, 12741, -1993, -1993,  6716,   207,  1053,
     505,    24,   382,   389,   382,  1059,  1060,  1054,   310,   310,
    1055, 13918,   310,   310,   310,   310, 12741,   310,  1319, -1993,
    1056,  1066,   419,  -145,  1067,   580, -1993, -1993, -1993, -1993,
   18161, 13826,  1063,  1136,  1332,  1170, 11682,  1070,  1072,  1337,
    7892, 15657, -1993, 12741,  1338,   194,   139,   502,    19, 14803,
   12741,  1339, -1993,   581,  1296,  1298,  7892, 15686,   185,  1077,
   18186, 16945,   486, 12741, 12741,  1085,  1083,  1088,  1087,  9476,
   -1993, -1993, -1993, -1993, 14677,   276,  1086, 18211, 16972,  1089,
   -1993,   300, -1993,   309, 14055, -1993, -1993, -1993,  1090, -1993,
    1093, 15715, 12741, 14269, -1993,    53, -1993, -1993, 18661, -1993,
     134,  6716, 12741,   310,   -73,  7892,  7892,  1353,  7892,  7892,
    7892,  1356,  7892,  7892,  7892,  7892,  7892,  7892,  7892,  7297,
    7892,  7892,  7892,  1985,  1357, -1993,   446,  4858, -1993, -1993,
   -1993, -1993, -1993, -1993, -1993, -1993, -1993, -1993, -1993, -1993,
   -1993, -1993, -1993, 12741, -1993, -1993, -1993, -1993, -1993, -1993,
   -1993, -1993, -1993, 12741, 12741, 12741, 12741, 12741, -1993, -1993,
   -1993,   583, 12741, 12741, -1993, 12741, -1993,  7892, 14677, 14677,
   -1993,   589, 15744, 15773, 15802,  1091, -1993, -1993, -1993,  1166,
   15831, 15860, 15889, 12741, 15918,   590, -1993, 15947, 12741, 12741,
   -1993, -1993, -1993,   502, -1993,   502, 12741, 12741,  1106, -1993,
    7892,   116, -1993, -1993, -1993, 12741, 12741,   591,   502,   -41,
     -51, 12741, 12741, -1993,   310,   596,  7892,  9999,  9999,  1367,
    1368,  1369,  2438, -1993, -1993,  1371, -1993,  1112, 18661,  1105,
    1374, -1993,  1375,  1377,  2133,  1378,  1379,   597,   520, -1993,
   13932, -1993, -1993,   -30, 14752, 14860, -1993, -1993, 15976,  -112,
    1270,  1383, 11779,  1119,  1382,  1124,    21,    40,   -61, -1993,
     -26, -1993,    -1,   446,   446,  7892, 18661, -1993,  2190,  1128,
    1286,  1389, -1993,  1394,  1395, 12741,  1291,  1396, -1993, -1993,
    1397,  1399,  1400, 12741,  1401,  7892,  1404,  7892,  7892,  1403,
   14893, -1993,  6243,   938,   502, 12741, 12741,   502,   502, -1993,
    9999, -1993, -1993, -1993, -1993, 14677, -1993, -1993, 12741, 14677,
   -1993, -1993, -1993, -1993, 18661, -1993,  1139,  1138, 14677, -1993,
   14677, -1993,   502, 14677,  1147, -1993,  1140,  1410, -1993,  1148,
     531,  1149, 12038, -1993,  2670,  1150,  7892, -1993,  1146, -1993,
   16005, -1993, -1993, 12741,  1416,   493, 12741,  1417,  1418,    13,
    1421,  1156,  1424,  2703, -1993,   310,   116,   116,  1425, -1993,
   -1993,  1167,  1168,  1162, -1993,  1429, -1993, -1993, -1993, -1993,
   -1993, -1993,   502,   436,  2556, 12741, 16999, 18236, 12741,  6311,
   12741,  9999,  1165,   602,  1431,   117,   502, -1993,  1169, 12741,
    1432,  1433, 12741,   502, 12128,  1436,  5768, 12741, 10258,   310,
    5212, 12741, 12741, 12741,  1174,  1173, -1993,  1438, 18261,  1439,
      68,  1304,  1304,  7892,  1443,  1444,  1445,  7892,   -90,  1446,
    1447,  1448,  1449,  1450,  1451, -1993, 12741,  1452,  1455,  1456,
   -1993,  1466,  1206,  6716,  6716,  6716,  6716,  6716,  6716,   310,
   14926, 14959, 14992,  1209,   310,   310, -1993, -1993, -1993, -1993,
     134,   310,  1355,  1361,  1362, 16034,  1280, -1993, 14803, -1993,
   18286,  6716,  1226,   172, 18661,  6716, -1993,  1488,   310, 18661,
   18661, -1993,   357, -1993,   502, -1993, 18311, 17026, -1993,   310,
    1489,   603,   605,  7892,  7892,  7892,  1492,  1491, -1993,   268,
   12741,  7892,  7892,  7892, -1993,  1228,  1230,  1494,  1493,  1495,
   -1993, 12741, 12741, 12741,  1233,  1235,  1236,  1241, -1993,  2880,
    7892, -1993, 12741, -1993,  1505, -1993,  1507, -1993, -1993, 11069,
     -23,  1243,  1244,  1511, -1993,  9999,  1250, -1993, -1993, -1993,
    7560,  1254, 12741, 12741, -1993, -1993, 17053,  7892,  1513,  7892,
    1515,  1320, -1993, 12741, 12741, 12741, -1993,   485,  1516,   262,
     429,  1259,  6503,  1275, 12741,    29,   310,  1256,   310,  1278,
   -1993, -1993, 14803, -1993, 12741,  1255, -1993, -1993,  3320, -1993,
   -1993,  1279,  1520, -1993,  3384, -1993,  1257,  1521,   263,  3470,
   -1993,    13, -1993,   611, -1993, 12741, -1993, -1993,   268,  3772,
   12791, -1993,  1277, 12741, 12741,  7892,  1281, -1993,   -15,   593,
    1529, 18336,  1530,  1287, 18361,  1284,   613,   625, 18386,   626,
    1531,  1535, -1993, -1993, 14677,  1282,  1523, 18411, -1993, -1993,
   15025,  1283, -1993, -1993, -1993, 12741,  7824,  6570, 18661, -1993,
    1537,   116,  8420, -1993, -1993, -1993, 18661, 18661, 18661, -1993,
     134, -1993,  1536, -1993, -1993,   -73,  1539,  1540,  1541, -1993,
   -1993, -1993,  1407,   -38,  1454,  1552, -1993, -1993, -1993, -1993,
   -1993, -1993,  8089, -1993, -1993, -1993,  1554,  1555, -1993, -1993,
   -1993, -1993, -1993, -1993, -1993, 12741, 12741, 12741, -1993, -1993,
   -1993,  1173, -1993,  1290,  1292,  1295, -1993,  1457, -1993, -1993,
   -1993, -1993, 12741,  1299,  1294, -1993, -1993, 12741, 12741,   310,
     -41, -1993, -1993, -1993, -1993,  1297,  1303,  1564,   -90,  1565,
   12741, -1993,  7892, 18661,  1426,  1427,   779,  9999,  9999, 12741,
   -1993, 10720, 16063, 18436,  8352,   446,   446, 12741, 12741, -1993,
     230,  1302, 18461, -1993, -1993, 16092,   216, -1993, -1993, -1993,
   -1993,   631,  9999, -1993, 12741, 12741,  3503,  3853,  1568,  1572,
   -1993,  1573, -1993,  7892,  8616,   424, 18486, 12741, 12741, -1993,
   -1993, 10357, -1993, 14677, 12741, -1993, 14677, 18661, 10621, 14803,
    1305, -1993, -1993, -1993, -1993,  1315,  1308, 16121, 12741, 14824,
   -1993, 14824,  7892, -1993, -1993,   502,    19, 14803, 12741,  1579,
   -1993,  1581, -1993,    13, 17080,  7892, 14677,  1582,   310, -1993,
    1316,   310, 12741, 15058, 15091,   632, -1993, 12741, 12741,  1322,
   -1993,  1323, -1993,  1369,  1583,  1588,  1589,  1377,  1590, -1993,
   -1993,  1591, 12741, -1993, -1993, 12741, 12387, 16150,  1593, 12741,
   -1993, -1993,  1330, 12791,   633,  2057,  1594, -1993, -1993,   200,
   -1993, -1993, -1993,  1459,  1596,  1333,  1334,  1335, -1993, -1993,
   12741,  1602, -1993,  6716,  6716, 15124, 12741, 12741, 12741,  1343,
    6716, -1993,  1341, 18511, 17107, -1993, -1993,  9999,  9999, -1993,
    1603, -1993, 18661,  1609, 12741, 12741,  1346, -1993,   638,   640,
   16728,  3938,  1611,  1348, -1993, -1993, 12741,  1349,  1350, 16179,
   17134,  1613,  7892,  1615,  1354, 12741,  1617,   646, 16208, 16237,
   -1993, -1993, -1993, -1993, -1993,  1430, -1993, 12741, 12741, -1993,
   -1993, 12477,  9735,  3975,  1620,  1623,  1364,  6716,   310, 18661,
   -1993, -1993, -1993, -1993,    29, -1993, 14803, -1993, 16266,  1363,
    1370,  1372,  1625,  1627,  1629,  4108, -1993, -1993, -1993,  1366,
    1633,   648, -1993,  1634,  1638,   362, 18661, 12741, 12741,  1385,
    7892,   653, 18661, 18536, -1993, -1993, -1993, -1993, -1993, 18561,
   15157, -1993, -1993, -1993, 16295,  1091,  1138,  7892,   310, -1993,
   12741, 14803,    41, -1993, -1993,  9999,  9999, 12741, 18586,  1639,
   -1993, -1993, 12741, 15190, 16324, 15223, 12741,  1294, -1993, -1993,
   -1993,   655,   656, -1993, -1993,  4142,  4421,  7892,   -82,   562,
    9999, -1993, -1993,   446,  8880, -1993, -1993, -1993,  1654, -1993,
    1398,  7892, -1993, 16353, -1993,  1659, -1993, -1993, 12741, 16382,
   16411,  9999, -1993,   662, -1993, -1993, -1993, -1993, -1993, -1993,
   -1993,  1406,  1660,  1408, -1993,  1661,    13, -1993, -1993, -1993,
    1468, -1993, -1993, -1993, -1993, -1993, 12741, 15256, 15289,  7892,
   -1993,  1664, 12741,  1412, -1993, 12741,  1665,  1405,  1409, -1993,
   -1993,  2726, -1993,  1411,   670,   686, 16440, -1993, -1993, 15322,
   12741, -1993, 12741, 16469,  1419, -1993,  1413, -1993, -1993,   687,
    1414,   -73,  7892,  1679,  1420,   -73,  1681,   693,  1422, -1993,
   12741, -1993,  1682,  1542, 13994,  1458, -1993,  4457, -1993, -1993,
     694, -1993,  1683, -1993, -1993, -1993,  1688, -1993,  1460, 18661,
   12741, 12741,   695, -1993, 18661, 15355, -1993, -1993, -1993,  1091,
   14803,  1462, -1993, -1993, -1993, 12741, 16498, 16527, -1993, -1993,
    9999,  1708,   -73,    73, -1993, -1993,   -73,   108, -1993,  1709,
   -1993, 16556, -1993, 12741, -1993,    -1, -1993, -1993, -1993, -1993,
   14824, -1993, 12741, 18611, 15388,    38, 12741,  1463, -1993, -1993,
   15421, -1993, -1993,   696, -1993,   257, -1993,   267, -1993, -1993,
   -1993,  4528,   -12, 14100,  1464,   703, -1993, 12741, -1993,  7892,
   16585, -1993, 12741, -1993,   -73,   -73, -1993, -1993, -1993,    -1,
    1710,  1714,  1461, 18636,   704,  1715,  6716,   293,   316,   447,
   -1993, -1993, 14677, -1993,  1467, -1993, -1993, 12741, 12741, -1993,
     710, -1993,  1471,  7892, 16614, 16643,  1716, 14677, 14677,   711,
    1717,  1719, -1993, -1993,   716, -1993,  1720, -1993, -1993,  1721,
   14677, -1993, -1993, -1993
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1993, -1993, -1993, -1993,   298, -1993, -1993, -1993, -1993,  -464,
   -1993, -1993, -1993, -1993, -1993, -1993, -1993, -1993, -1993, -1993,
   -1993, -1993,  -759,  -136,  4780,  4067,  -395, -1993,  1258, -1993,
   -1993, -1993, -1993, -1993, -1993, -1967, -1993,   242,    54,  -273,
   -1993,  -229, -1993,   -11,   284, -1993,  1746, -1993,   919,   -44,
    1172, -1993,     0,  -661,  -104, -1993, -1993, -1993, -1993, -1993,
   -1993,   647,  1747, -1993, -1993, -1993, -1993, -1297, -1306,  1753,
   -1813,  1754, -1993, -1993, -1993,  1126, -1993,  -289, -1993, -1993,
   -1993, -1993,  2699, -1993, -1993, -1503,   152,  1759, -1993,     2,
   -1993, -1993,   -65, -1993, -1992,   813, -1993,   -86,  3622,  1512,
     337,  -333,   -69, -1993,   735,   -79, -1993, -1993,   -48,   123,
   -1766,  -151,   952, -1993,    -3
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -602
static const yytype_int16 yytable[] =
{
     150,   655,  1568,   132,   999,  1000,   342,   344,   436,   347,
    1743,   355,   381,   486,   465,  1570,  1979,   388,  1980,   176,
    1100,   328,   682,   176,   178,   438,  1106,  1563,   576,   177,
     176,  1347,   605,  1818,   983,   431,   383,   435,   447,   158,
     165,   167,   363,  1175,  2228,   176,  1565,   191,  2107,   385,
     195,   392,  1972,   322,   311,  2129,   323,   324,   325,  1703,
    1448,   807,   316,     4,   490,   491,   582,  1895,   779,   326,
     333,   470,  2130,  2131,  1694,   497,   360,  2132,   361,  2216,
     663,   664,   316,   359,   627,   179,  1896,   180,  1301,   317,
     311,  1245,   151,   176,  1246,   311,   152,   818,   790,   334,
     391,   994,   498,   583,   356,   805,  1302,  2162,   500,  1115,
       5,   432,  1704,   806,  2218,   335,   336,  2018,  1303,  1304,
    1305,  1121,   521,  1663,  1306,  1307,  1301,  1372,   663,   664,
    1373,   528,   721,   622,   623,   624,   625,  1301,  1450,   327,
    1242,   626,   663,   664,  1302,  1243,  1392,   471,  1301,  1001,
     627,   473,   481,   481,   481,  1302,  1303,  1304,  1305,  1555,
    1451,   488,  1306,  1307,   722,   153,  1302,  1303,  1304,  1305,
     825,  1452,  1453,  1306,  1307,   811,   826,   362,  1303,  1304,
    1305,   338,   339,   812,  1306,  1307,   663,   664,   828,  1410,
     154,   384,   213,   340,   826,   214,  1099,   341,   215,   155,
     481,  1392,  2207,   984,   386,   311,   156,  1005,  1564,   311,
    1567,   216,   459,   460,   311,   311,   481,   357,   570,   571,
     572,  1524,   459,   460,   663,   664,   157,  1566,   663,   664,
    1104,   169,   640,   641,   642,   965,   861,  2244,   607,   587,
     862,  1912,   671,  1819,   124,  1551,   338,   339,  1787,  1569,
     124,  1858,   124,  1808,   687,  -598,   124,   160,   340,  2237,
     691,   692,   346,   124,  1568,   677,   678,   679,  1810,  1811,
    1837,  2269,   658,   437,   660,  1392,   311,   358,   124,   813,
     667,   672,   782,   389,   783,   696,   683,   814,   684,  1399,
     439,   311,   152,   577,   311,   603,  1348,   606,   448,  1066,
     602,   207,   449,   159,   166,   168,   364,  1176,  2229,   192,
     311,   311,   196,   393,   311,   311,   311,   311,   808,   179,
     809,   180,   663,   664,   810,   311,   124,   663,   664,   311,
    1050,   391,   179,   753,   180,   756,  1393,  1396,   459,   460,
     161,   628,   762,   629,  1210,   311,   311,   630,   311,   311,
     311,   162,   459,   460,   819,   791,   809,   792,   163,  -594,
     820,   793,   663,   664,  1122,  1123,  1122,  1123,   311,   368,
     164,   311,   369,   766,  1411,  1412,  1413,  1414,   455,   456,
     457,   458,   179,   170,   180,   370,   104,  2224,   105,   106,
     107,   108,   109,   171,   663,   664,   113,   114,  1112,   116,
     663,   664,   459,   460,   459,   460,   351,   628,   352,   629,
     665,  1395,   782,   630,   783,  1129,   666,   907,   459,   460,
    1239,   723,   557,   724,   558,  1140,   771,   725,   455,   456,
     457,   458,  1958,   455,   456,   457,   458,   172,   179,   481,
     180,   311,   711,   816,   152,   311,   311,  1246,   772,   173,
     472,   817,   459,   460,   663,   664,  1415,   459,   460,   773,
     774,   311,   455,   456,   457,  1105,   624,   625,   794,   491,
     663,   664,   626,   608,   609,   610,   611,   612,   613,   614,
     615,   616,   617,   618,   619,   620,   621,   622,   623,   624,
     625,  1945,   852,   318,   833,   626,   319,   771,   320,   924,
     853,  1941,   455,   456,   457,   458,   771,   455,   456,   457,
     458,   663,   664,   931,   445,  1482,   208,  1220,   446,   772,
     311,   663,   664,   174,  1548,   817,   459,   460,   772,   935,
     773,   774,  2234,   862,  2124,   329,   775,   776,   330,   773,
     774,  1251,  2235,  1435,   188,   311,   772,   663,   664,   175,
     990,   862,   992,   993,   311,   897,   680,   773,   774,   481,
     681,   481,   311,   481,   481,   488,   210,  1440,  2257,  1006,
     663,   664,   914,   663,   664,   862,  1441,   782,  1054,   783,
    1018,   311,   311,   311,   862,   481,   481,   311,   178,   673,
     178,  2258,   311,   930,   189,   932,  1301,  1859,   997,   998,
      70,    71,    72,    73,   660,    75,    76,   775,   776,  1042,
     782,   209,   783,   784,  1302,    85,   775,   776,   311,   772,
      90,   777,   778,  1747,   962,  1748,  1303,  1304,  1305,  2095,
     773,   774,  1306,  1307,   775,   776,   182,  2096,   782,   183,
     783,   966,   184,  1101,   185,   322,   311,   311,   323,   782,
     325,   783,  1571,  1572,  1081,    48,   782,   817,   783,   580,
     190,   326,   581,  1069,  1350,   473,   473,   608,   609,   610,
     611,   612,   613,   614,   615,   616,   617,   618,   619,   620,
     721,   622,   623,   624,   625,   211,   782,   311,   783,   626,
     311,   311,  1626,  1627,  1370,  1959,   782,   311,   783,   459,
     460,   969,  1398,   193,   862,   862,  -596,   775,   776,   619,
     620,   721,   622,   623,   624,   625,  2134,  2135,  2259,  1049,
     626,  2132,   194,   197,   488,   481,   488,   481,   481,   481,
     481,   481,   481,   198,   481,   481,   481,   481,  1068,   199,
     481,   481,   481,   178,  1074,   200,   201,   311,  1073,   459,
     460,  1807,  1425,  1808,  1346,  1117,  -597,  1153,   459,   460,
     970,  1261,  1007,  1262,   862,   311,   862,   607,   459,   460,
    1008,  1345,  1083,  1346,   862,  1089,   862,   202,  1249,  1090,
    1762,   311,   862,  1926,   203,  1927,   212,  1109,   611,   612,
     613,   614,   615,   616,   617,   618,   619,   620,   721,   622,
     623,   624,   625,   311,  1126,   204,  1285,   626,   313,   311,
     862,   311,  1286,   218,   488,  1138,   862,  1324,  1326,  1327,
     205,   862,   862,   862,  1145,   206,   481,   219,   314,  1263,
     613,   614,   615,   616,   617,   618,   619,   620,   721,   622,
     623,   624,   625,   312,  1236,  1330,   332,   626,  1512,   862,
    1513,  1376,  1405,   315,  1489,   862,   862,   311,   862,   311,
    1496,  1507,  1521,  1522,   862,  1508,   862,  1529,  1547,  1838,
     309,   862,   862,  1661,  1755,   331,  1756,   862,   862,  1845,
     862,   350,  1842,   353,  1865,   469,  1843,  1290,   862,   337,
     479,   482,   483,  1549,   345,   311,  1866,  1868,  2222,  1279,
    1508,   862,  1946,  1999,  2019,   311,   862,  2000,  2020,  2048,
     354,  2049,   348,   862,  1263,   862,  1568,  2065,   366,  2092,
     311,   862,   131,   817,  2101,   367,  2125,  2126,  2102,  1293,
     862,   862,   377,  2151,   349,   311,  1299,   862,   516,   365,
    1310,  2172,  2249,  1568,   378,   862,  1595,   379,   186,  1597,
     380,   311,  1598,  1599,   530,   382,   387,  2173,  2181,  1394,
    1397,   862,  2000,   311,  2189,  2198,  2205,  2233,   862,   862,
    2000,   862,   311,   394,  2241,  2254,  1263,  1609,  2102,  2000,
     720,  2266,  2276,   321,   311,  2267,  2000,  2279,   395,   401,
     443,  2280,   402,   433,   442,   444,   450,   451,   476,   477,
    1628,   497,   608,   609,   610,   611,   612,   613,   614,   615,
     616,   617,   618,   619,   620,   860,   622,   623,   624,   625,
    1402,   152,   495,   499,   626,   527,   782,  1648,   783,   504,
     508,   529,   522,   565,   568,   573,  -207,  -208,   440,  -209,
     578,  1665,   579,   584,   588,   604,   591,   592,  1671,   593,
     610,   611,   612,   613,   614,   615,   616,   617,   618,   619,
     620,   721,   622,   623,   624,   625,  1632,   446,   645,   467,
     626,   649,   636,   637,   467,   467,   467,   644,   646,   652,
     685,   714,   688,   467,   689,   654,   656,   311,   657,  1460,
     686,   699,   309,   690,   693,  1401,   694,   695,   700,   701,
     702,   703,   704,   311,   705,   706,   708,   730,   713,   748,
     731,   732,   743,   744,  1937,  1938,   311,   746,   747,   749,
     751,   481,   467,  1523,  1525,   750,   752,   754,   755,   757,
     639,   765,   768,   781,   786,   788,   789,   151,   467,   795,
     830,   648,   858,   864,   834,   653,   836,   865,   866,   936,
     898,   626,   311,   311,   908,   311,   311,   311,   909,   311,
     311,   311,   311,   311,   311,   311,   910,   311,   311,   311,
     911,   918,   919,   920,   922,   938,   473,   759,   926,   939,
     569,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   721,   622,   623,   624,   625,   974,
     585,   586,   975,   626,   988,  1596,   989,   978,  1010,   991,
    1012,  1040,  1013,  1016,   311,   481,   481,   608,   609,   610,
     611,   612,   613,   614,   615,   616,   617,   618,   619,   620,
     721,   622,   623,   624,   625,  1027,  1029,  1043,  1088,   626,
    1076,  1078,  1082,  1092,  1097,  1093,  1098,   311,  1102,  1113,
    1119,  1114,  1130,  1132,  1135,  1144,  1142,  1146,  1149,  1154,
    1155,   763,   764,   311,   311,   311,  1150,  1156,  1158,  1159,
    1160,  1162,  1163,  1164,  1165,  1166,  1167,   780,  1168,  1170,
    1171,  1172,  1180,  1208,  1209,  1217,  1218,  1523,  1525,  1219,
    1227,  1233,  1238,  1244,  1250,  1254,  1266,   901,  1841,   903,
    1258,   905,   906,  1267,  1268,  1274,  1276,  1288,  1296,  1297,
    1300,  1313,   311,   473,   473,  1314,  1315,  1317,  1325,  1335,
    1337,  1338,  1339,   927,   928,  1344,  1353,  1354,  1366,  1355,
    1358,  1368,   311,  1369,   311,   311,  1375,  1379,  1380,  1381,
    1382,  1385,  1386,  1387,  1391,  1404,  1406,   311,  1407,  1422,
    1236,  1428,   481,  1429,  1430,  1439,   481,  1431,  1436,  1444,
    1463,   467,  1443,  1467,  1481,   481,  1500,   481,  -210,  1679,
     481,  1684,   767,  1516,  1533,  1534,  1535,  1538,   904,  1539,
    1540,  1541,  1542,   311,  1543,  1545,  1546,  1557,  1561,  1560,
    1562,  1576,  2138,  1556,   802,  1577,   391,   639,  1575,   925,
    1578,  1579,  1581,  1582,  1583,  1584,  1585,  1592,  1587,   802,
     802,  1589,  1604,  1605,  1611,  1612,  1613,  1622,  1614,  1616,
    1620,   481,  1625,  1630,  1635,  1631,   311,  1634,   311,  1738,
    1636,  1641,  1645,  1643,  1644,  1647,  1660,  1662,  1668,  1669,
    1982,  1666,  1673,  1689,  1691,  1693,  1695,   311,  1690,  1699,
    1700,  1701,  1706,  1707,  1708,  1709,  1710,  1711,  1713,   787,
     311,  1714,  1715,  1053,   311,  1055,  1056,  1057,  1058,  1059,
    1060,  1716,  1062,  1063,  1064,  1065,  1728,  1717,  1070,  1071,
    1072,   467,  1737,   467,  1733,   467,   467,   467,  1850,  1850,
    1734,  1735,  1839,  1741,  1745,  1754,  1760,  1761,  1767,  1770,
    1768,  1769,  1771,  1775,  1786,  1776,  1777,   467,   467,  1778,
    1988,  1783,  1829,  1784,  1788,  1789,  1831,  1790,  1803,  1800,
    1792,  1802,  1809,  1823,  1795,  1828,  1833,  1873,  1836,  1835,
     311,   311,   311,  1826,  1813,  1860,  1862,  1869,   311,   311,
     311,  1870,  1888,  1852,  1882,  1890,  1891,  1892,  1872,  1876,
    1816,  1857,  1136,  1373,  1832,  1864,  1893,   311,  1898,  1901,
    1906,  1902,  1907,  1897,  1147,  1908,  1911,  1917,  1909,  1246,
    1919,  1921,   311,  1918,  1952,  1924,  1925,  1942,  1953,  1954,
    1974,  1094,  1975,  1976,   311,  1986,   311,  1987,  1992,  2004,
     802,   817,  -601,  -599,  2005,  2006,  2007,  2008,  1881,  2013,
    2017,  2022,  2024,  2025,  2026,  2027,   802,  2029,  2038,  2043,
     802,   802,  2023,  2036,  1916,  2044,  2047,  2052,  2053,  2059,
    2055,  2056,  2061,  2064,  2062,   804,  2075,  2068,   391,  2076,
    1889,  2077,  2086,  2087,  2083,  2088,   488,   488,  2090,  2091,
    2093,  2084,   311,  2085,  2094,  2118,   467,   467,   467,   467,
     467,   467,   467,   467,   467,  2099,   467,   467,   467,   467,
    2141,   481,   467,   467,   467,  2146,  2153,  2155,  2157,  2142,
    2163,  2166,   802,  2152,   311,   802,  2167,  2171,  2154,   311,
    2168,   802,  -600,  2180,  2182,  2185,  2179,  2188,  2192,  2199,
    2186,  2193,  1932,  2190,  2201,  1991,   608,   609,   610,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   721,
     622,   623,   624,   625,  2214,  2219,  2250,  1116,   626,  1118,
    2251,  2255,  2272,  2277,   526,  2278,  2281,  2282,  2196,  2209,
    2202,  2252,  1965,  1664,  2231,  2240,   467,  2263,  2225,  1970,
    1973,  2268,  1731,  2108,  1887,  2080,  1697,  1920,   467,   130,
     140,  1253,   829,  2156,   921,  1421,   141,   142,  1984,   311,
    2136,  1825,   148,  1851,   311,   311,  1657,  1983,   977,  1137,
    1971,     0,     0,     0,     0,   473,   473,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1273,   311,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     311,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     481,     0,     0,   481,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   634,   635,     0,     0,   311,
       0,     0,     0,  1401,     0,     0,     0,     0,     0,     0,
     391,     0,   311,   488,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1434,
     674,   675,   608,   609,   610,   611,   612,   613,   614,   615,
     616,   617,   618,   619,   620,   721,   622,   623,   624,   625,
     488,     0,     0,     0,   626,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2081,     0,     0,
       0,     0,     0,  1388,     0,     0,     0,     0,     0,   802,
       0,   802,   802,     0,   311,   311,     0,     0,     0,  1408,
       0,     0,     0,     0,     0,   802,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   802,     0,   311,
       0,  1329,  2112,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1494,  1495,     0,   760,     0,  2144,   311,
       0,   802,     0,     0,     0,     0,     0,     0,  1461,  1462,
       0,  1464,  1465,  1466,     0,  1468,  1469,  1470,  1471,  1472,
    1473,  1474,     0,  1477,  1478,  1479,     0,     0,     0,     0,
       0,  1480,     0,     0,     0,     0,     0,   311,     0,     0,
     802,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   311,     0,     0,     0,     0,  2113,
       0,     0,   311,   311,     0,     0,     0,     0,     0,     0,
    1493,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   467,   311,     0,     0,   311,     0,     0,
    2200,     0,     0,   473,     0,     0,     0,     0,   311,     0,
       0,     0,     0,  1517,  2021,   607,  2183,     0,   311,     0,
    2187,     0,     0,     0,     0,     0,     0,     0,     0,  1530,
       0,     0,     0,   391,     0,     0,     0,     0,     0,     0,
    1601,  2208,  2223,     0,  1603,     0,   311,     0,     0,     0,
       0,     0,     0,  1607,     0,  1608,     0,   933,  1610,     0,
       0,     0,     0,     0,     0,     0,     0,  2215,     0,     0,
       0,  2217,     0,     0,     0,     0,     0,     0,  1573,   311,
       0,     0,     0,     0,     0,     0,     0,   467,   467,  1544,
       0,     0,     0,     0,     0,     0,     0,     0,  1588,     0,
    1590,  1591,     0,     0,     0,     0,     0,     0,     0,  1650,
       0,   985,   986,     0,     0,     0,     0,     0,     0,  2247,
    2248,     0,     0,     0,     0,     0,     0,   311,   608,   609,
     610,   611,   612,   613,   614,   615,   616,   617,   618,   619,
     620,   721,   622,   623,   624,   625,  1574,     0,     0,  1621,
     626,     0,  1021,     0,     0,  1024,  1025,     0,     0,   802,
       0,     0,  1031,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   311,     0,   608,   609,
     610,   611,   612,   613,   614,   615,   616,   617,   618,   619,
     620,   721,   622,   623,   624,   625,     0,     0,     0,   481,
     626,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     311,     0,  1075,  1683,   481,   481,     0,     0,     0,     0,
       0,     0,     0,     0,   467,     0,  1698,   481,   467,     0,
    1702,     0,     0,     0,     0,     0,     0,   467,     0,   467,
       0,     0,   467,     0,     0,     0,  1103,     0,     0,  1615,
     608,   609,   610,   611,   612,   613,   614,   615,   616,   617,
     618,   619,   620,   860,   622,   623,   624,   625,  1125,     0,
       0,     0,   626,     0,  1131,     0,  1133,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   467,     0,     0,  1757,  1758,  1759,     0,
       0,     0,     0,     0,  1764,  1765,  1766,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1781,     0,     0,   608,   609,   610,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   721,
     622,   623,   624,   625,     0,     0,     0,     0,   626,  1871,
    1799,     0,  1801,     0,     0,     0,     0,     0,     0,     0,
    1211,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1221,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   608,   609,   610,   611,   612,   613,   614,
     615,   616,   617,   618,   619,   620,   721,   622,   623,   624,
     625,     0,     0,     0,     0,   626,     0,     0,  1856,     0,
       0,     0,     0,     0,     0,     0,  1257,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1265,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   220,   176,
    1880,   396,     0,     0,     0,   221,   222,   223,     0,  1287,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   397,   243,
     244,   245,   246,   247,   248,   249,   250,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   256,   257,   258,   259,  1966,     0,
       0,  1968,   260,     0,     0,     0,     0,     0,   467,   467,
     176,   403,     0,     0,     0,     0,     0,     0,   265,   266,
     267,     0,     0,     0,     0,  1923,     0,     0,     0,     0,
       0,   269,    27,   467,   270,     0,     0,  1536,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   404,   405,   406,   407,
     408,   409,   410,   411,   412,     0,  1955,     0,     0,   413,
     414,   415,   416,     0,     0,     0,     0,   417,   418,   419,
     420,  1433,     0,     0,     0,     0,   421,     0,   422,     0,
       0,     0,     0,     0,     0,  1981,     0,     0,     0,     0,
       0,     0,     0,     0,   423,     0,     0,   424,  1990,     0,
       0,   182,     0,     0,   183,     0,     0,   184,     0,   185,
       0,     0,     0,     0,     0,     0,  1619,     0,     0,     0,
      48,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   721,   622,   623,   624,   625,     0,
       0,   453,   284,   626,     0,     0,   285,     0,     0,  1637,
       0,     0,   287,   288,   289,     0,   290,   291,   292,     0,
       0,     0,   124,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   467,  2170,     0,   467,     0,     0,     0,   293,
     398,     0,     0,     0,     0,     0,   295,     0,   802,     0,
     802,   373,     0,     0,     0,  2060,     0,     0,   298,     0,
       0,     0,     0,     0,     0,   467,     0,     0,     0,     0,
       0,     0,     0,     0,   425,   426,   427,     0,     0,  1531,
    1532,     0,     0,     0,     0,     0,   428,     0,     0,     0,
     429,     0,   430,   124,     0,     0,     0,     0,     0,     0,
       0,     0,   467,     0,     0,     0,     0,     0,     0,   399,
       0,     0,     0,  2100,     0,     0,     0,     0,     0,   459,
     460,     0,   441,     0,     0,     0,  -595,     0,  1649,     0,
    2109,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   468,
       0,     0,     0,   478,     0,     0,     0,     0,   484,     0,
    1856,     0,  1600,     0,     0,   489,     0,     0,   492,     0,
       0,     0,     0,     0,  2143,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1779,   501,   502,   503,
       0,   505,   506,   507,     0,   509,   510,   511,   512,   513,
     514,   515,     0,   517,   518,   519,   520,     0,     0,     0,
       0,   524,  1856,   608,   609,   610,   611,   612,   613,   614,
     615,   616,   617,   618,   619,   620,   721,   622,   623,   624,
     625,     0,     0,     0,     0,   626,     0,     0,     0,     0,
       0,  1656,     0,  1659,     0,  2184,   608,   609,   610,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   721,
     622,   623,   624,   625,     0,     0,     0,     0,   626,   608,
     609,   610,   611,   612,   613,   614,   615,   616,   617,   618,
     619,   620,   721,   622,   623,   624,   625,  2261,     0,     0,
       0,   626,   594,   596,   598,   599,   524,     0,     0,     0,
       0,     0,  2273,  2275,     0,     0,     0,     0,     0,     0,
       0,   633,   524,   524,     0,  2283,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   651,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   661,
     662,     0,  1856,     0,     0,   662,     0,   524,   524,   676,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   802,     0,     0,     0,     0,     0,     0,
       0,     0,   697,   524,     0,     0,  1856,     0,     0,     0,
       0,     0,     0,   707,     0,   709,   710,  1791,   712,     0,
       0,     0,   715,   716,   717,     0,     0,   719,     0,     0,
       0,   726,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   802,
       0,     0,     0,   608,   609,   610,   611,   612,   613,   614,
     615,   616,   617,   618,   619,   620,   721,   622,   623,   624,
     625,     0,   802,   524,   761,   626,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     769,   770,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   467,     0,     0,     0,   803,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   467,   467,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   835,   467,
       0,     0,     0,   840,     0,     0,     0,   844,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   859,   596,     0,     0,     0,   863,     0,     0,     0,
     867,   868,   869,   870,   871,   872,   873,   874,   875,   876,
     877,   878,   879,   880,   881,   882,   883,   884,   886,   887,
     888,   889,   890,   891,   892,   893,   894,   894,     0,   899,
     900,     0,   902,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   912,     0,     0,   916,   917,     0,  1928,
    1929,     0,     0,     0,     0,     0,     0,     0,     0,   894,
       0,     0,     0,     0,   524,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1947,     0,   940,   941,   942,   943,
     944,   945,   946,   947,   948,   949,   950,   951,   952,   953,
     955,   957,   958,   959,   960,   961,  1830,   963,   964,     0,
       0,     0,     0,     0,     0,   971,   972,   973,     0,     0,
       0,     0,     0,   979,   980,   981,   982,     0,   524,   524,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   594,   719,  1002,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1014,
    1015,     0,  1017,     0,     0,  1019,     0,     0,     0,   524,
    1834,     0,   524,   524,  1026,     0,     0,     0,  1030,   524,
    1032,  1033,  1034,     0,     0,  1035,     0,  1037,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1047,     0,     0,
    1048,     0,   963,   964,     0,     0,     0,     0,     0,  2041,
    2042,     0,     0,     0,     0,  1061,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   524,
       0,     0,     0,     0,     0,     0,  1080,     0,     0,     0,
       0,     0,     0,     0,  1091,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2073,     0,  1840,     0,     0,     0,
       0,     0,     0,   524,     0,  1107,     0,     0,     0,     0,
    1110,  1111,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   524,     0,  1127,  1128,  1950,
       0,   524,     0,   524,  1134,     0,     0,     0,  1127,     0,
    1141,     0,     0,  1143,     0,     0,     0,     0,     0,  1148,
       0,     0,     0,  1151,     0,     0,     0,  2114,  2115,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1169,     0,     0,     0,     0,  1173,     0,   955,
       0,  1177,  2137,   608,   609,   610,   611,   612,   613,   614,
     615,   616,   617,   618,   619,   620,   721,   622,   623,   624,
     625,     0,     0,  2150,     0,   626,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   524,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   524,  1222,  1223,
    1224,     0,     0,     0,     0,     0,     0,  1230,  1231,  1232,
       0,  1234,   524,     0,     0,  1237,     0,   608,   609,   610,
     611,   612,   613,   614,   615,   616,   617,   618,   619,   620,
     721,   622,   623,   624,   625,     0,     0,     0,     0,   626,
       0,     0,     0,   524,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   524,     0,     0,     0,     0,
       0,     0,     0,  1272,     0,     0,     0,  1278,     0,     0,
       0,     0,     0,  1284,     0,     0,   524,     0,     0,     0,
       0,     0,  2213,     0,  1294,  1295,     0,     0,     0,     0,
    1298,     0,     0,     0,     0,     0,     0,     0,     0,  1316,
       0,     0,  1318,   608,   609,   610,   611,   612,   613,   614,
     615,   616,   617,   618,   619,   620,   721,   622,   623,   624,
     625,     0,     0,     0,     0,   626,     0,     0,     0,     0,
    1340,     0,  1342,  1343,     0,     0,   608,   609,   610,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   721,
     622,   623,   624,   625,     0,  1364,     0,     0,   626,     0,
       0,     0,     0,     0,     0,     0,   176,   403,     0,     0,
       0,     0,     0,     0,     0,  1384,     0,     0,     0,     0,
       0,     0,  1390,     0,     0,     0,     0,     0,     0,  1403,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1426,  1427,     0,     0,     0,     0,   524,     0,
       0,     0,   404,   405,   406,   407,   408,   409,   410,   411,
     412,     0,     0,     0,   525,   413,   414,   415,   416,     0,
       0,  1446,     0,   417,   418,   419,   420,     0,     0,     0,
       0,  1458,   421,     0,   422,     0,     0,     0,     0,  1951,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     423,     0,     0,   424,     0,     0,     0,   182,     0,     0,
     183,     0,     0,   184,     0,   185,     0,     0,     0,     0,
       0,     0,  1483,     0,     0,     0,    48,     0,     0,     0,
       0,     0,  1484,  1485,  1486,  1487,  1488,     0,     0,     0,
       0,  1490,  1491,     0,  1492,     0,   597,   453,     0,   525,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1505,     0,     0,   525,   525,  1510,  1511,     0,
       0,     0,     0,     0,  2051,  1514,  1515,     0,     0,     0,
       0,     0,     0,     0,  1519,  1520,     0,     0,     0,     0,
    1526,  1527,     0,     0,     0,     0,   524,   524,     0,     0,
     525,   525,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2074,     0,     0,     0,     0,     0,     0,     0,     0,
     425,   426,   427,     0,     0,     0,   525,     0,     0,     0,
       0,  1559,   428,     0,     0,     0,   429,     0,   430,   124,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1580,     0,     0,     0,     0,     0,
       0,     0,  1586,     0,     0,     0,     0,     0,     0,   782,
       0,   783,  1846,     0,  1526,  1527,     0,     0,     0,   524,
       0,     0,     0,     0,     0,     0,     0,  1602,     0,     0,
       0,     0,     0,     0,     0,     0,   525,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1618,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1624,     0,     0,  1629,   608,   609,   610,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   721,
     622,   623,   624,   625,  2089,     0,     0,     0,   626,     0,
       0,     0,     0,     0,  1651,     0,     0,  1654,   524,  1658,
     524,     0,     0,     0,     0,     0,     0,     0,  1667,     0,
       0,  1670,     0,  1667,     0,   597,  1676,  1678,  2127,     0,
    1686,  1687,  1688,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     885,     0,     0,     0,     0,  1712,     0,     0,     0,   895,
     896,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   721,   622,   623,   624,   625,     0,
       0,     0,     0,   626,     0,     0,     0,     0,     0,     0,
       0,     0,   929,     0,     0,     0,     0,   525,   608,   609,
     610,   611,   612,   613,   614,   615,   616,   617,   618,   619,
     620,   721,   622,   623,   624,   625,     0,     0,     0,  1763,
     626,     0,     0,   956,     0,     0,     0,     0,     0,     0,
    1772,  1773,  1774,     0,     0,     0,     0,     0,     0,  1780,
       0,  1782,     0,     0,     0,     0,     0,     0,  1785,     0,
       0,   525,   525,     0,   524,     0,     0,     0,     0,     0,
       0,  1796,  1797,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1804,  1805,  1806,     0,     0,     0,     0,     0,
       0,     0,     0,  1817,     0,     0,     0,     0,     0,     0,
       0,     0,   525,  1827,     0,   525,   525,     0,     0,     0,
       0,     0,   525,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1844,     0,     0,     0,     0,     0,
       0,     0,  1853,  1854,     0,     0,     0,     0,     0,     0,
       0,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   721,   622,   623,   624,   625,     0,
       0,     0,   525,   626,  1877,     0,     0,     0,     0,     0,
       0,  1885,     0,     0,     0,   608,   609,   610,   611,   612,
     613,   614,   615,   616,   617,   618,   619,   620,   721,   622,
     623,   624,   625,     0,     0,     0,   525,   626,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1903,  1904,  1905,  2128,   525,     0,
       0,     0,     0,     0,   525,     0,   525,     0,     0,     0,
       0,  1910,     0,     0,     0,     0,  1913,  1914,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1922,
       0,     0,     0,  2197,     0,     0,   524,   524,  1930,     0,
    1931,     0,     0,     0,     0,     0,  1939,  1940,     0,     0,
       0,     0,   956,     0,  1178,     0,     0,     0,     0,     0,
       0,   524,     0,  1948,  1949,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1913,  1914,     0,     0,
    1963,     0,     0,  1967,     0,     0,     0,  1969,     0,     0,
     525,     0,     0,     0,     0,     0,     0,  1978,     0,     0,
     525,     0,     0,   785,  2236,     0,     0,  1985,     0,     0,
       0,     0,     0,     0,     0,   525,     0,     0,     0,     0,
       0,  1996,     0,     0,     0,     0,  2002,  2003,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2009,     0,     0,  2010,  2009,   525,     0,  2014,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   525,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2028,
       0,     0,     0,     0,     0,  2033,  2034,  2035,     0,   525,
       0,     0,     0,     0,     0,     0,   524,   524,     0,     0,
       0,     0,     0,  2045,  2046,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2054,     0,     0,     0,     0,
       0,     0,   913,     0,  2063,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2069,  2070,     0,     0,
     719,   524,     0,     0,   608,   609,   610,   611,   612,   613,
     614,   615,   616,   617,   618,   619,   620,   721,   622,   623,
     624,   625,     0,     0,     0,     0,   626,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2097,  2098,     0,   967,
     608,   609,   610,   611,   612,   613,   614,   615,   616,   617,
     618,   619,   620,   721,   622,   623,   624,   625,     0,  2111,
       0,     0,   626,     0,   524,   524,  2116,     0,     0,     0,
       0,  2119,     7,     8,     0,  2123,     0,     0,     0,     0,
       0,   525,     0,     0,     0,     0,     0,     0,     0,   524,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2147,     0,     0,
     524,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   721,   622,   623,   624,   625,     0,
       0,     0,     0,   626,     0,  2159,     0,     0,     0,     0,
       0,  2164,     0,     0,  2165,     0,     0,     0,   181,     0,
     187,     0,     0,     0,     0,     0,     0,     0,     0,  2176,
       0,  2177,     0,     0,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,   607,     0,  2191,
      45,    46,    47,    48,     0,     0,     0,     0,    50,     0,
       0,     0,     0,     0,     0,     0,     0,   796,    58,  2203,
    2204,    61,   797,     0,   798,   799,   607,   800,     0,     0,
       0,     0,     0,     0,  2210,     0,     0,     0,     0,   524,
       0,     0,     0,     0,     0,    82,     0,     0,     0,   525,
     525,     0,  2221,     0,     0,     0,     0,     0,     0,     0,
       0,  2002,     0,     0,     0,  2230,  1044,     0,     0,     0,
       0,     0,     0,   100,   101,   102,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2243,     0,     0,     0,
     466,  2246,     0,     0,  1181,  1182,  1183,  1184,  1185,  1186,
    1187,  1188,  1189,  1190,  1191,  1192,     0,  1194,  1195,  1196,
    1197,     0,  1199,  1200,  1201,  1202,  2264,  2265,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1214,     0,
    1216,     0,   525,     0,     0,     0,     0,     0,     0,     0,
       0,  1226,     0,     0,     0,     0,     0,     0,     0,     0,
     822,     0,     0,     0,     0,  1240,  1241,     0,     0,     0,
       0,     0,     0,     0,  1252,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   541,   542,   543,   544,   545,
     546,   547,   548,   549,   550,   551,   552,   553,   554,   555,
     556,   559,   560,   561,   562,   563,   564,     0,   566,   567,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   574,
     575,   525,     0,   525,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   589,   590,     0,     0,     0,
       0,     0,   608,   609,   610,   611,   612,   613,   614,   615,
     616,   617,   618,   619,   620,   621,   622,   623,   624,   625,
       0,     0,     0,     0,   626,     0,     0,     0,     0,     0,
       0,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   860,   622,   623,   624,   625,  1349,
    1351,  1352,     0,   626,     0,  1356,  1357,     0,     0,  1360,
    1361,  1362,  1363,     0,  1365,     0,     0,     0,     0,  1371,
       0,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   721,   622,   623,   624,   625,     0,
       0,     0,     0,   626,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   718,     0,     0,
       0,     0,     0,     0,   727,   728,   729,     0,     0,     0,
     733,   734,   735,   736,   737,   738,   739,   525,   740,     0,
       0,     0,     0,   741,   742,     0,     0,   745,     0,     0,
       0,     0,     0,     0,     0,   220,     6,   403,  1457,     0,
    1459,     0,   221,   222,   223,     0,     0,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,     0,
       0,     0,  1681,   405,   406,   407,   408,   409,   410,   411,
     412,   256,   257,   258,   259,   413,   414,   415,   416,   260,
     261,     0,     0,   417,   418,   419,   420,     0,     0,   262,
     263,   264,   421,     0,   422,   265,   266,   267,     0,     0,
     268,     0,     0,     0,  1886,     0,     0,     0,   269,    27,
     423,   270,     0,   424,     0,     0,     0,   271,     0,     0,
     272,     0,     0,   273,     0,   274,     0,     0,     0,     0,
       0,  1528,    44,     0,     0,     0,   275,   276,   277,     0,
       0,   278,     0,     0,     0,     0,     0,     0,     0,     0,
     279,     0,    59,    60,     0,   280,     0,   281,     0,     0,
     282,     0,  1255,     0,     0,     0,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,     0,     0,
       0,    85,     0,   937,     0,    89,    90,     0,     0,   525,
     525,     0,     0,     0,     7,     8,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   283,     0,     0,   525,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   284,
     425,   426,   427,   285,   286,     0,     0,     0,     0,   287,
     288,   289,   428,   290,   291,   292,   429,     0,   430,   124,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   293,   294,     0,     0,
       0,     0,  1638,   295,     0,     0,     0,     0,   373,     0,
       0,     0,  1682,     0,     0,   298,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,     0,
       0,     0,    45,    46,    47,    48,     0,     0,     0,     0,
      50,     0,     0,     0,     0,     0,  1680,     0,     0,   796,
      58,     0,     0,    61,   797,     0,   798,   799,     0,   800,
       0,     0,     0,     7,     8,     0,     0,     0,     0,   525,
     525,     0,     0,     0,     0,     0,     0,    82,     0,     0,
    1718,  1719,  1720,  1721,  1722,  1723,  1724,     0,     0,     0,
       0,  1729,  1730,     0,     0,     0,     0,     0,  1732,     0,
       0,     0,     0,     0,     0,   100,   101,   102,  1740,     0,
       0,     0,  1744,     0,   525,  1746,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1753,   608,   609,   610,
     611,   612,   613,   614,   615,   616,   617,   618,   619,   620,
     721,   622,   623,   624,   625,     0,     0,     0,     0,   626,
       0,     0,     0,     0,     0,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,     0,     0,
       0,    45,    46,    47,    48,     0,     0,   525,   525,    50,
       0,     0,   823,     0,     0,     0,     0,     0,   796,    58,
       0,     0,    61,   797,     0,   798,   799,  1812,   800,  1815,
       0,     0,   525,  1822,     0,  1824,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    82,     0,     0,     0,
       0,     0,     0,   525,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1847,     0,     0,     0,
       0,     0,  1247,     0,   100,   101,   102,     0,     0,     0,
       0,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   721,   622,   623,   624,   625,   220,
       6,   372,     0,   626,     0,  1264,   221,   222,   223,   857,
       0,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,     0,     0,     0,     0,     0,     0,     0,
       0,  1003,     0,     0,     0,   256,   257,   258,   259,     0,
       0,     0,   525,   260,   261,     0,     0,     0,     0,     0,
       0,     0,     0,   262,   263,   264,  1915,     0,     0,   265,
     266,   267,     0,     0,   268,     0,     0,     0,     0,     0,
       0,     0,   269,    27,     0,   270,     0,     0,     0,     0,
       0,   271,     0,     0,   272,     0,     0,   273,     0,   274,
       0,     0,     0,     0,     0,     0,    44,     0,     0,     0,
     275,   276,   277,     0,     0,   278,     0,     0,     0,     0,
       0,     0,     0,     0,   279,     0,    59,    60,     0,   280,
       0,   281,     0,     0,   282,     0,     0,     0,     0,     0,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,     0,     0,     0,    85,     0,     0,     0,    89,
      90,     0,     0,     0,     0,  1993,     0,     0,  1994,     0,
       0,     0,     0,     0,     0,  1449,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   283,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   284,     0,     0,     0,   285,   286,     0,
       0,     0,     0,   287,   288,   289,     0,   290,   291,   292,
    2030,  2031,     0,   124,     0,     0,     0,  2037,  1256,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     293,   294,     0,     0,     0,     0,     0,   295,     0,     0,
       0,     0,   373,     0,     0,     0,   374,     0,     0,   298,
       0,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   721,   622,   623,   624,   625,     0,
       0,  1518,     0,   626,  2078,  2079,     0,     0,     0,  1674,
     220,     6,   403,  1675,     0,   698,     0,   221,   222,   223,
       0,     0,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,     0,  2110,     0,   404,   405,   406,
     407,   408,   409,   410,   411,   412,   256,   257,   258,   259,
     413,   414,   415,   416,   260,   261,     0,     0,   417,   418,
     419,   420,     0,     0,   262,   263,   264,   421,     0,   422,
     265,   266,   267,     0,     0,   268,     0,     0,     0,     0,
       0,     0,     0,   269,    27,   423,   270,     0,   424,     0,
       0,     0,   271,     0,     0,   272,     0,     0,   273,     0,
     274,     0,     0,     0,     0,     0,     0,    44,     0,     0,
       0,   275,   276,   277,     0,     0,   278,     0,     0,     0,
       0,     0,     0,     0,     0,   279,     0,    59,    60,     0,
     280,     0,   281,     0,     0,   282,  1639,  1640,     0,     0,
       0,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,     0,     0,     0,    85,     0,     0,     0,
      89,    90,     0,   608,   609,   610,   611,   612,   613,   614,
     615,   616,   617,   618,   619,   620,   721,   622,   623,   624,
     625,     0,     0,     0,     0,   626,   283,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1594,     0,     0,   284,   425,   426,   427,   285,   286,
       0,     0,     0,     0,   287,   288,   289,   428,   290,   291,
     292,   429,     0,   430,   124,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   293,   523,  1742,     0,     0,     0,     0,   295,     0,
       0,     0,  1749,   373,     0,     0,     0,     0,   600,     0,
     298,     0,     0,  2256,   220,     6,   403,     0,     0,  1655,
       0,   221,   222,   223,     0,     0,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,     0,     0,
       0,   404,   405,   406,   407,   408,   409,   410,   411,   412,
     256,   257,   258,   259,   413,   414,   415,   416,   260,   261,
       0,     0,   417,   418,   419,   420,     0,     0,   262,   263,
     264,   421,     0,   422,   265,   266,   267,     0,     0,   268,
       0,     0,     0,     0,     0,     0,     0,   269,    27,   423,
     270,     0,   424,     0,     0,     0,   271,     0,     0,   272,
       0,     0,   273,     0,   274,     0,     0,     0,     0,     0,
       0,    44,     0,     0,     0,   275,   276,   277,     0,     0,
     278,     0,     0,     0,     0,     0,     0,     0,     0,   279,
       0,    59,    60,     0,   280,     0,   281,     0,     0,   282,
       0,  1883,     0,     0,     0,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,     0,     0,     0,
      85,     0,     0,     0,    89,    90,   608,   609,   610,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   721,
     622,   623,   624,   625,     0,     0,     0,     0,   626,     0,
     283,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   284,   425,
     426,   427,   285,   286,     0,     0,     0,     0,   287,   288,
     289,   428,   290,   291,   292,   429,     0,   430,   124,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   293,   523,     0,     0,     0,
       0,     0,   295,   220,     6,   403,     0,   373,     0,     0,
     221,   222,   223,     0,   298,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,     0,     0,     0,
     404,   405,   406,   407,   408,   409,   410,   411,   412,   256,
     257,   258,   259,   413,   414,   415,   416,   260,   261,     0,
       0,   417,   418,   419,   420,     0,     0,   262,   263,   264,
     421,     0,   422,   265,   266,   267,     0,     0,   268,     0,
       0,     0,     0,     0,     0,     0,   269,    27,   423,   270,
       0,   424,     0,     0,     0,   271,     0,     0,   272,     0,
       0,   273,     0,   274,     0,     0,     0,     0,     0,     0,
      44,     0,     0,     0,   275,   276,   277,     0,     0,   278,
       0,     0,     0,     0,     0,     0,     0,     0,   279,     0,
      59,    60,     0,   280,     0,   281,     0,     0,   282,     0,
       0,     0,     0,     0,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,     0,     0,     0,    85,
       0,     0,     0,    89,    90,     0,   608,   609,   610,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   721,
     622,   623,   624,   625,     0,     0,     0,     0,   626,   283,
     782,     0,   783,     0,     0,     0,     0,     0,  1814,     0,
       0,     0,     0,     0,     0,     0,     0,   284,   425,   426,
     427,   285,   286,     0,     0,     0,     0,   287,   288,   289,
     428,   290,   291,   292,   429,     0,   430,   124,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   293,   294,     0,     0,     0,     0,
       0,   295,     0,     0,     0,     0,   373,   220,   176,   403,
     297,   452,     0,   298,   221,   222,   223,     0,     0,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   397,   243,   244,
     245,   246,   247,   248,   249,   250,     0,     0,     0,     0,
       0,     0,     0,     0,   404,   405,   406,   407,   408,   409,
     410,   411,   412,   256,   257,   258,   259,   413,   414,   415,
     416,   260,     0,     0,     0,   417,   418,   419,   420,     0,
       0,     0,     0,     0,   421,     0,   422,   265,   266,   267,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     269,    27,   423,   270,     0,   424,     0,     0,     0,   182,
     176,   403,   183,     0,     0,   184,     0,   185,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    48,   608,
     609,   610,   611,   612,   613,   614,   615,   616,   617,   618,
     619,   620,   721,   622,   623,   624,   625,     0,     0,   453,
       0,   626,     0,   782,     0,   783,   404,   405,   406,   407,
     408,   409,   410,   411,   412,     0,     0,     0,     0,   413,
     414,   415,   416,     0,     0,     0,     0,   417,   418,   419,
     420,     0,     0,     0,     0,     0,   421,     0,   422,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   423,     0,     0,   424,     0,     0,
       0,     0,     0,     0,   454,     0,     0,     0,     0,     0,
       0,   284,   425,   426,   427,   285,     0,     0,     0,     0,
       0,   287,   288,   289,   428,   290,   291,   292,   429,     0,
     430,   124,     0,   455,   456,   457,   458,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   293,   398,
       0,     0,     0,     0,     0,   295,     0,   459,   460,     0,
     461,     0,   462,   220,     6,     0,   463,   298,   698,     0,
     221,   222,   223,     0,     0,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,     0,     0,     0,
       0,     0,     0,     0,   425,   426,   427,     0,     0,   256,
     257,   258,   259,     0,     0,     0,   428,   260,   261,     0,
     429,     0,   430,   124,     0,     0,     0,   262,   263,   264,
       0,     0,     0,   265,   266,   267,     0,     0,   268,     0,
       0,     0,     0,     0,     0,     0,   269,    27,     0,   270,
       0,     0,     0,     0,     0,   271,     0,     0,   272,     0,
       0,   273,     0,   274,     0,     0,     0,     0,     0,     0,
      44,     0,     0,     0,   275,   276,   277,     0,     0,   278,
       0,     0,     0,     0,     0,     0,     0,     0,   279,     0,
      59,    60,     0,   280,     0,   281,     0,     0,   282,     0,
       0,     0,     0,     0,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,     0,     0,     0,    85,
       0,     0,     0,    89,    90,     0,   608,   609,   610,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   721,
     622,   623,   624,   625,     0,     0,     0,     0,   626,   283,
    1028,     0,     0,     0,     0,     0,     0,     0,   995,     0,
       0,     0,     0,     0,     0,     0,     0,   284,     0,     0,
       0,   285,   286,     0,     0,     0,     0,   287,   288,   289,
       0,   290,   291,   292,     0,     0,     0,   124,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   293,   523,     0,     0,     0,     0,
       0,   295,     0,     0,     0,     0,   373,   220,     6,   372,
       0,   600,     0,   298,   221,   222,   223,     0,     0,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   256,   257,   258,   259,     0,     0,     0,
       0,   260,   261,     0,     0,     0,     0,     0,     0,     0,
       0,   262,   263,   264,     0,     0,     0,   265,   266,   267,
       0,     0,   268,     0,     0,     0,     0,     0,     0,     0,
     269,    27,     0,   270,     0,     0,     0,     0,     0,   271,
       0,     0,   272,     0,     0,   273,     0,   274,     0,     0,
       0,     0,     0,     0,    44,     0,     0,     0,   275,   276,
     277,     0,     0,   278,     0,     0,     0,     0,     0,     0,
       0,     0,   279,     0,    59,    60,     0,   280,     0,   281,
       0,     0,   282,     0,     0,     0,     0,     0,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
       0,     0,     0,    85,     0,     0,     0,    89,    90,     0,
     608,   609,   610,   611,   612,   613,   614,   615,   616,   617,
     618,   619,   620,   721,   622,   623,   624,   625,     0,     0,
       0,     0,   626,   283,  1475,     0,     0,     0,     0,     0,
       0,     0,  1476,     0,     0,     0,     0,     0,     0,     0,
       0,   284,     0,     0,     0,   285,   286,     0,     0,     0,
       0,   287,   288,   289,     0,   290,   291,   292,     0,     0,
       0,   124,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   293,   294,
       0,     0,     0,     0,     0,   295,     0,     0,     0,     0,
     373,   220,     6,     0,   923,     0,     0,   298,   221,   222,
     223,     0,     0,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   256,   257,   258,
     259,     0,     0,     0,     0,   260,   261,     0,     0,     0,
       0,     0,     0,     0,     0,   262,   263,   264,     0,     0,
       0,   265,   266,   267,     0,     0,   268,     0,     0,     0,
       0,     0,     0,     0,   269,    27,     0,   270,     0,     0,
       0,     0,     0,   271,     0,     0,   272,     0,     0,   273,
       0,   274,     0,     0,     0,     0,     0,     0,    44,     0,
       0,     0,   275,   276,   277,     0,     0,   278,     0,     0,
       0,     0,     0,     0,     0,     0,   279,     0,    59,    60,
       0,   280,     0,   281,     0,     0,   282,     0,     0,     0,
       0,     0,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,     0,     0,     0,    85,     0,     0,
       0,    89,    90,   608,   609,   610,   611,   612,   613,   614,
     615,   616,   617,   618,   619,   620,   721,   622,   623,   624,
     625,     0,     0,     0,     0,   626,     0,   283,     0,     0,
       0,  1793,     0,     0,     0,  1794,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   284,     0,     0,     0,   285,
     286,     0,     0,     0,     0,   287,   288,   289,     0,   290,
     291,   292,     0,     0,     0,   124,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   293,   294,     0,     0,     0,     0,     0,   295,
       0,     0,     0,     0,   296,   220,     6,     0,   297,     0,
       0,   298,   221,   222,   223,     0,     0,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   256,   257,   258,   259,     0,     0,     0,     0,   260,
     261,     0,     0,     0,     0,     0,     0,     0,     0,   262,
     263,   264,     0,     0,     0,   265,   266,   267,     0,     0,
     268,     0,     0,     0,     0,     0,     0,     0,   269,    27,
       0,   270,     0,     0,     0,     0,     0,   271,     0,     0,
     272,     0,     0,   273,     0,   274,     0,     0,     0,     0,
       0,     0,    44,     0,     0,     0,   275,   276,   277,     0,
       0,   278,     0,     0,     0,     0,     0,     0,     0,     0,
     279,     0,    59,    60,     0,   280,     0,   281,     0,     0,
     282,     0,     0,     0,     0,     0,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,     0,     0,
       0,    85,     0,     0,     0,    89,    90,   608,   609,   610,
     611,   612,   613,   614,   615,   616,   617,   618,   619,   620,
     721,   622,   623,   624,   625,     0,     0,     0,     0,   626,
       0,   283,     0,     0,     0,  1878,     0,     0,     0,  1879,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   284,
       0,     0,     0,   285,   286,     0,     0,     0,     0,   287,
     288,   289,     0,   290,   291,   292,     0,     0,     0,   124,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   293,   294,     0,     0,
       0,     0,     0,   295,     0,     0,     0,     0,   373,   220,
       6,     0,   297,     0,     0,   298,   221,   222,   223,     0,
       0,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   256,   257,   258,   259,     0,
       0,     0,     0,   260,   261,     0,     0,     0,     0,     0,
       0,     0,     0,   262,   263,   264,     0,     0,     0,   265,
     266,   267,     0,     0,   268,     0,     0,     0,     0,     0,
       0,     0,   269,    27,     0,   270,     0,     0,     0,     0,
       0,   271,     0,     0,   272,     0,     0,   273,     0,   274,
       0,     0,     0,     0,     0,     0,    44,     0,     0,     0,
     275,   276,   277,     0,     0,   278,     0,     0,     0,     0,
       0,     0,     0,     0,   279,     0,    59,    60,     0,   280,
       0,   281,     0,     0,   282,     0,     0,     0,     0,     0,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,     0,     0,     0,    85,     0,     0,     0,    89,
      90,     0,   608,   609,   610,   611,   612,   613,   614,   615,
     616,   617,   618,   619,   620,   721,   622,   623,   624,   625,
       0,     0,     0,     0,   626,   283,  1899,     0,     0,     0,
       0,     0,     0,     0,  1900,     0,     0,     0,     0,     0,
       0,     0,     0,   284,     0,     0,     0,   285,   286,     0,
       0,     0,     0,   287,   288,   289,     0,   290,   291,   292,
       0,     0,     0,   124,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     293,   523,     0,     0,     0,     0,     0,   295,     0,     0,
       0,     0,   373,   220,     6,     0,   595,     0,     0,   298,
     221,   222,   223,     0,     0,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   256,
     257,   258,   259,     0,     0,     0,     0,   260,   261,     0,
       0,     0,     0,     0,     0,     0,     0,   262,   263,   264,
       0,     0,     0,   265,   266,   267,     0,     0,   268,     0,
       0,     0,     0,     0,     0,     0,   269,    27,     0,   270,
       0,     0,     0,     0,     0,   271,     0,     0,   272,     0,
       0,   273,     0,   274,     0,     0,     0,     0,     0,     0,
      44,     0,     0,     0,   275,   276,   277,     0,     0,   278,
       0,     0,     0,     0,     0,     0,     0,     0,   279,     0,
      59,    60,     0,   280,     0,   281,     0,     0,   282,     0,
       0,     0,     0,     0,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,     0,     0,     0,    85,
       0,     0,     0,    89,    90,   608,   609,   610,   611,   612,
     613,   614,   615,   616,   617,   618,   619,   620,   721,   622,
     623,   624,   625,     0,     0,     0,     0,   626,     0,   283,
       0,     0,     0,  1935,     0,     0,     0,  1936,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   284,     0,     0,
       0,   285,   286,     0,     0,     0,     0,   287,   288,   289,
       0,   290,   291,   292,     0,     0,     0,   124,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   293,   523,     0,     0,     0,     0,
       0,   295,     0,     0,     0,     0,   373,   220,     6,     0,
       0,   600,     0,   298,   221,   222,   223,     0,     0,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   256,   257,   258,   259,     0,     0,     0,
       0,   260,   261,     0,     0,     0,     0,     0,     0,     0,
       0,   262,   263,   264,     0,     0,     0,   265,   266,   267,
       0,     0,   268,     0,     0,     0,     0,     0,     0,     0,
     269,    27,     0,   270,     0,     0,     0,     0,     0,   271,
       0,     0,   272,     0,     0,   273,     0,   274,     0,     0,
       0,     0,     0,     0,    44,     0,     0,     0,   275,   276,
     277,     0,     0,   278,     0,     0,     0,     0,     0,     0,
       0,     0,   279,     0,    59,    60,     0,   280,     0,   281,
       0,     0,   282,     0,     0,     0,     0,     0,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
       0,     0,     0,    85,     0,     0,     0,    89,    90,   608,
     609,   610,   611,   612,   613,   614,   615,   616,   617,   618,
     619,   620,   721,   622,   623,   624,   625,     0,     0,     0,
       0,   626,     0,   283,     0,     0,     0,  1956,     0,     0,
       0,  1957,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   284,     0,     0,     0,   285,   286,     0,     0,     0,
       0,   287,   288,   289,     0,   290,   291,   292,     0,     0,
       0,   124,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   293,   294,
       0,     0,     0,     0,     0,   295,     0,     0,     0,     0,
     638,   220,     6,     0,   297,     0,     0,   298,   221,   222,
     223,     0,     0,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   256,   257,   258,
     259,     0,     0,     0,     0,   260,   261,     0,     0,     0,
       0,     0,     0,     0,     0,   262,   263,   264,     0,     0,
       0,   265,   266,   267,     0,     0,   268,     0,     0,     0,
       0,     0,     0,     0,   269,    27,     0,   270,     0,     0,
       0,     0,     0,   271,     0,     0,   272,     0,     0,   273,
       0,   274,     0,     0,     0,     0,     0,     0,    44,     0,
       0,     0,   275,   276,   277,     0,     0,   278,     0,     0,
       0,     0,     0,     0,     0,     0,   279,     0,    59,    60,
       0,   280,     0,   281,     0,     0,   282,     0,     0,     0,
       0,     0,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,     0,     0,     0,    85,     0,     0,
       0,    89,    90,   608,   609,   610,   611,   612,   613,   614,
     615,   616,   617,   618,   619,   620,   721,   622,   623,   624,
     625,     0,     0,     0,     0,   626,     0,   283,     0,     0,
       0,  2139,     0,     0,     0,  2140,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   284,     0,     0,     0,   285,
     286,     0,     0,     0,     0,   287,   288,   289,     0,   290,
     291,   292,     0,     0,     0,   124,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   293,   294,     0,     0,     0,     0,     0,   295,
       0,     0,     0,     0,   647,   220,     6,     0,   297,     0,
       0,   298,   221,   222,   223,     0,     0,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   256,   257,   258,   259,     0,     0,     0,     0,   260,
     261,     0,     0,     0,     0,     0,     0,     0,     0,   262,
     263,   264,     0,     0,     0,   265,   266,   267,     0,     0,
     268,     0,     0,     0,     0,     0,     0,     0,   269,    27,
       0,   270,     0,     0,     0,     0,     0,   271,     0,     0,
     272,     0,     0,   273,     0,   274,     0,     0,     0,     0,
       0,     0,    44,     0,     0,     0,   275,   276,   277,     0,
       0,   278,     0,     0,     0,     0,     0,     0,     0,     0,
     279,     0,    59,    60,     0,   280,     0,   281,     0,     0,
     282,     0,     0,     0,     0,     0,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,     0,     0,
       0,    85,     0,     0,     0,    89,    90,   608,   609,   610,
     611,   612,   613,   614,   615,   616,   617,   618,   619,   620,
     721,   622,   623,   624,   625,     0,     0,     0,     0,   626,
       0,   283,     0,     0,     0,     0,     0,     0,     0,   815,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   284,
       0,     0,     0,   285,   286,     0,     0,     0,     0,   287,
     288,   289,     0,   290,   291,   292,     0,     0,     0,   124,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   293,   523,     0,     0,
       0,     0,     0,   295,     0,     0,     0,     0,   373,   220,
       6,     0,   954,     0,  1432,   298,   221,   222,   223,     0,
       0,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   256,   257,   258,   259,     0,
       0,     0,     0,   260,   261,     0,     0,     0,     0,     0,
       0,     0,     0,   262,   263,   264,     0,     0,     0,   265,
     266,   267,     0,     0,   268,     0,     0,     0,     0,     0,
       0,     0,   269,    27,     0,   270,     0,     0,     0,     0,
       0,   271,     0,     0,   272,     0,     0,   273,     0,   274,
       0,     0,     0,     0,     0,     0,    44,     0,     0,     0,
     275,   276,   277,     0,     0,   278,     0,     0,     0,     0,
       0,     0,     0,     0,   279,     0,    59,    60,     0,   280,
       0,   281,     0,     0,   282,     0,     0,     0,     0,     0,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,     0,     0,     0,    85,     0,     0,     0,    89,
      90,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   721,   622,   623,   624,   625,     0,
       0,     0,     0,   626,     0,   283,     0,     0,     0,     0,
       0,     0,     0,   821,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   284,     0,     0,     0,   285,   286,     0,
       0,     0,     0,   287,   288,   289,     0,   290,   291,   292,
       0,     0,     0,   124,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     293,   523,     0,     0,     0,     0,     0,   295,   220,     6,
       0,     0,   373,     0,     0,   221,   222,   223,     0,   298,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   256,   257,   258,   259,     0,     0,
       0,     0,   260,   261,     0,     0,     0,     0,     0,     0,
       0,     0,   262,   263,   264,     0,     0,     0,   265,   266,
     267,     0,     0,   268,     0,     0,     0,     0,     0,     0,
       0,   269,    27,     0,   270,     0,     0,     0,     0,     0,
     271,     0,     0,   272,     0,     0,   273,     0,   274,     0,
       0,     0,     0,     0,     0,    44,     0,     0,     0,   275,
     276,   277,     0,     0,   278,     0,     0,     0,     0,     0,
       0,     0,     0,   279,     0,    59,    60,     0,   280,     0,
     281,     0,     0,   282,     0,     0,     0,     0,     0,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,     0,     0,     0,    85,     0,     0,     0,    89,    90,
     608,   609,   610,   611,   612,   613,   614,   615,   616,   617,
     618,   619,   620,   721,   622,   623,   624,   625,     0,     0,
       0,     0,   626,     0,   283,     0,     0,     0,     0,     0,
       0,     0,   824,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   284,     0,     0,     0,   285,   286,     0,     0,
       0,     0,   287,   288,   289,     0,   290,   291,   292,     0,
       0,     0,   124,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   293,
     523,     0,     0,     0,     0,     0,   295,     0,     0,     0,
       0,   373,   220,     6,     0,     0,  2072,     0,   298,   221,
     222,   223,     0,     0,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   256,   257,
     258,   259,     0,     0,     0,     0,   260,   261,     0,     0,
       0,     0,     0,     0,     0,     0,   262,   263,   264,     0,
       0,     0,   265,   266,   267,     0,     0,   268,     0,     0,
       0,     0,     0,     0,     0,   269,    27,     0,   270,     0,
       0,     0,     0,     0,   271,     0,     0,   272,     0,     0,
     273,     0,   274,     0,     0,     0,     0,     0,     0,    44,
       0,     0,     0,   275,   276,   277,     0,     0,   278,     0,
       0,     0,     0,     0,     0,     0,     0,   279,     0,    59,
      60,     0,   280,     0,   281,     0,     0,   282,     0,     0,
       0,     0,     0,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,     0,     0,     0,    85,     0,
       0,     0,    89,    90,   608,   609,   610,   611,   612,   613,
     614,   615,   616,   617,   618,   619,   620,   721,   622,   623,
     624,   625,     0,     0,     0,     0,   626,     0,   283,     0,
       0,     0,     0,     0,     0,     0,   995,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   284,     0,     0,     0,
     285,   286,     0,     0,     0,     0,   287,   288,   289,     0,
     290,   291,   292,     0,     0,     0,   124,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   293,   523,     0,     0,     0,     0,     0,
     295,   220,   176,   403,     0,   373,     0,     0,   221,   222,
     223,     0,   298,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   397,   243,   244,   245,   246,   247,   248,   249,   250,
       0,     0,     0,     0,     0,     0,     0,     0,   404,   405,
     406,   407,   408,   409,   410,   411,   412,   256,   257,   258,
     259,   413,   414,   415,   416,   260,     0,     0,     0,   417,
     418,   419,   420,     0,     0,     0,     0,     0,   421,     0,
     422,   265,   266,   267,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   269,    27,   423,   270,     0,   424,
     220,   176,   403,     0,     0,     0,     0,   221,   222,   223,
       0,     0,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     397,   243,   244,   245,   246,   247,   248,   249,   250,     0,
       0,     0,     0,     0,     0,     0,     0,   404,   405,   406,
     407,   408,   409,   410,   411,   412,   256,   257,   258,   259,
     413,   414,   415,   416,   260,     0,     0,     0,   417,   418,
     419,   420,     0,     0,     0,     0,     0,   421,     0,   422,
     265,   266,   267,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   269,    27,   423,   270,     0,   424,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   284,   425,   426,   427,   285,
       0,     0,     0,     0,     0,   287,   288,   289,   428,   290,
     291,   292,   429,     0,   430,   124,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   293,   398,     0,     0,     0,     0,     0,   295,
       0,     0,     0,     0,   373,     0,     0,     0,  1677,     0,
       0,   298,   608,   609,   610,   611,   612,   613,   614,   615,
     616,   617,   618,   619,   620,   721,   622,   623,   624,   625,
       0,     0,     0,     0,   626,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   996,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   284,   425,   426,   427,   285,     0,
       0,     0,     0,     0,   287,   288,   289,   428,   290,   291,
     292,   429,     0,   430,   124,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   293,  1961,     0,     0,     0,     0,     0,   295,     0,
       0,     0,     0,   373,   220,   176,   403,  1962,     0,     0,
     298,   221,   222,   223,     0,     0,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   397,   243,   244,   245,   246,   247,
     248,   249,   250,     0,     0,     0,     0,     0,     0,     0,
       0,  1681,   405,   406,   407,   408,   409,   410,   411,   412,
     256,   257,   258,   259,   413,   414,   415,   416,   260,     0,
       0,     0,   417,   418,   419,   420,     0,     0,     0,     0,
       0,   421,     0,   422,   265,   266,   267,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   269,    27,   423,
     270,     0,   424,   220,   176,   403,     0,     0,     0,     0,
     221,   222,   223,     0,     0,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   397,   243,   244,   245,   246,   247,   248,
     249,   250,     0,     0,     0,     0,     0,     0,     0,     0,
     404,   405,   406,   407,   408,   409,   410,   411,   412,   256,
     257,   258,   259,   413,   414,   415,   416,   260,     0,     0,
       0,   417,   418,   419,   420,     0,     0,     0,     0,     0,
     421,     0,   422,   265,   266,   267,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   269,    27,   423,   270,
       0,   424,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   284,   425,
     426,   427,   285,     0,     0,     0,     0,     0,   287,   288,
     289,   428,   290,   291,   292,   429,     0,   430,   124,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   293,   398,     0,     0,     0,
       0,     0,   295,     0,     0,     0,     0,   373,     0,     0,
       0,  1846,     0,     0,   298,   608,   609,   610,   611,   612,
     613,   614,   615,   616,   617,   618,   619,   620,   721,   622,
     623,   624,   625,     0,     0,     0,     0,   626,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1041,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   284,   425,   426,
     427,   285,     0,     0,     0,     0,     0,   287,   288,   289,
     428,   290,   291,   292,   429,     0,   430,   124,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   293,   398,     0,     0,     0,     0,
       0,   295,   220,   176,     0,     0,   373,     0,     0,   221,
     222,   223,     0,   298,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   397,   243,   244,   245,   246,   247,   248,   249,
     250,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   256,   257,
     258,   259,     0,     0,     0,     0,   260,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   265,   266,   267,     0,     0,     0,     0,     0,
       0,     0,   220,   176,     0,   269,    27,     0,   270,   221,
     222,   223,     0,     0,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   397,   243,   244,   245,   246,   247,   248,   249,
     250,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   256,   257,
     258,   259,     0,     0,     0,     0,   260,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   265,   266,   267,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   269,    27,     0,   270,   608,
     609,   610,   611,   612,   613,   614,   615,   616,   617,   618,
     619,   620,   721,   622,   623,   624,   625,     0,     0,     0,
       0,   626,     0,     0,     0,     0,   284,     0,     0,     0,
     285,  1152,     0,     0,     0,     0,   287,   288,   289,     0,
     290,   291,   292,     0,     0,     0,   124,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   293,   398,     0,     0,     0,     0,     0,
     295,     0,     0,     0,     0,   373,     0,     0,     0,   650,
       0,     0,   298,   608,   609,   610,   611,   612,   613,   614,
     615,   616,   617,   618,   619,   620,   721,   622,   623,   624,
     625,     0,     0,     0,     0,   626,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1193,   284,     0,     0,     0,
     285,     0,     0,     0,     0,     0,   287,   288,   289,     0,
     290,   291,   292,     0,     0,     0,   124,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   668,   669,     0,     0,     0,     0,     0,
     295,     0,     0,     0,     0,   670,   220,   176,     0,   341,
       0,   915,   298,   221,   222,   223,     0,     0,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   397,   243,   244,   245,
     246,   247,   248,   249,   250,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   256,   257,   258,   259,     0,     0,     0,     0,
     260,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   265,   266,   267,     0,
       0,     0,     0,     0,     0,     0,   220,   176,     0,   269,
      27,     0,   270,   221,   222,   223,     0,     0,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   397,   243,   244,   245,
     246,   247,   248,   249,   250,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   256,   257,   258,   259,     0,     0,     0,     0,
     260,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   265,   266,   267,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   269,
      27,     0,   270,   608,   609,   610,   611,   612,   613,   614,
     615,   616,   617,   618,   619,   620,   721,   622,   623,   624,
     625,     0,     0,     0,     0,   626,     0,     0,     0,     0,
     284,     0,     0,     0,   285,  1203,     0,     0,     0,     0,
     287,   288,   289,     0,   290,   291,   292,     0,     0,     0,
     124,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   293,   398,     0,
       0,     0,     0,     0,   295,     0,     0,     0,     0,   373,
       0,     0,     0,     0,     0,     0,   298,   608,   609,   610,
     611,   612,   613,   614,   615,   616,   617,   618,   619,   620,
     721,   622,   623,   624,   625,     0,     0,     0,     0,   626,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1204,
     284,     0,     0,     0,   285,     0,     0,     0,     0,     0,
     287,   288,   289,     0,   290,   291,   292,     0,     0,     0,
     124,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   293,   398,     0,
       0,     0,     0,     0,   295,   220,   176,     0,  1383,   373,
    1139,     0,   221,   222,   223,     0,   298,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   397,   243,   244,   245,   246,
     247,   248,   249,   250,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   256,   257,   258,   259,     0,     0,     0,     0,   260,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   265,   266,   267,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   269,    27,
       0,   270,   220,   176,     0,  1558,     0,     0,     0,   221,
     222,   223,     0,     0,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   397,   243,   244,   245,   246,   247,   248,   249,
     250,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   256,   257,
     258,   259,     0,     0,     0,     0,   260,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   265,   266,   267,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   269,    27,     0,   270,     0,
     608,   609,   610,   611,   612,   613,   614,   615,   616,   617,
     618,   619,   620,   721,   622,   623,   624,   625,     0,   284,
       0,     0,   626,   285,     0,     0,     0,     0,     0,   287,
     288,   289,  1205,   290,   291,   292,     0,     0,     0,   124,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   293,   398,     0,     0,
       0,     0,     0,   295,     0,     0,     0,     0,   373,     0,
       0,     0,     0,     0,     0,   298,   608,   609,   610,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   721,
     622,   623,   624,   625,     0,     0,     0,     0,   626,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1206,     0,
       0,     0,     0,     0,     0,     0,   284,     0,     0,     0,
     285,     0,     0,     0,     0,     0,   287,   288,   289,     0,
     290,   291,   292,     0,     0,     0,   124,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   293,   398,     0,     0,     0,     0,     0,
     295,   220,   176,     0,  1617,   373,     0,     0,   221,   222,
     223,     0,   298,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   397,   243,   244,   245,   246,   247,   248,   249,   250,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   256,   257,   258,
     259,     0,     0,     0,     0,   260,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   265,   266,   267,     0,     0,     0,     0,     0,     0,
       0,   220,   176,     0,   269,    27,     0,   270,   221,   222,
     223,     0,     0,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   397,   243,   244,   245,   246,   247,   248,   249,   250,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   256,   257,   258,
     259,     0,     0,     0,     0,   260,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   265,   266,   267,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   269,    27,     0,   270,   608,   609,
     610,   611,   612,   613,   614,   615,   616,   617,   618,   619,
     620,   721,   622,   623,   624,   625,     0,     0,     0,     0,
     626,     0,     0,     0,     0,   284,     0,     0,     0,   285,
    1207,     0,     0,     0,     0,   287,   288,   289,     0,   290,
     291,   292,     0,     0,     0,   124,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   293,   398,     0,     0,     0,     0,     0,   295,
       0,     0,     0,     0,   373,     0,     0,     0,     0,     0,
       0,   298,   608,   609,   610,   611,   612,   613,   614,   615,
     616,   617,   618,   619,   620,   721,   622,   623,   624,   625,
       0,     0,     0,     0,   626,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1212,   284,     0,     0,     0,   285,
       0,     0,     0,     0,     0,   287,   288,   289,     0,   290,
     291,   292,     0,     0,     0,   124,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   293,   398,     0,     0,     0,     0,     0,   295,
     220,   176,     0,     0,   373,  1672,     0,   221,   222,   223,
       0,   298,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     397,   243,   244,   245,   246,   247,   248,   249,   250,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   256,   257,   258,   259,
       0,     0,     0,     0,   260,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     265,   266,   267,     0,     0,     0,     0,     0,     0,     0,
     220,   176,     0,   269,    27,     0,   270,   221,   222,   223,
       0,     0,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     397,   243,   244,   245,   246,   247,   248,   249,   250,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   256,   257,   258,   259,
       0,     0,     0,     0,   260,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     265,   266,   267,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   269,    27,     0,   270,   608,   609,   610,
     611,   612,   613,   614,   615,   616,   617,   618,   619,   620,
     721,   622,   623,   624,   625,     0,     0,     0,     0,   626,
       0,     0,     0,     0,   284,     0,     0,     0,   285,  1213,
       0,     0,     0,     0,   287,   288,   289,     0,   290,   291,
     292,     0,     0,     0,   124,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   293,   398,     0,     0,     0,     0,     0,   295,     0,
       0,     0,     0,   373,  2011,     0,     0,     0,     0,     0,
     298,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   721,   622,   623,   624,   625,     0,
       0,     0,     0,   626,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1215,   284,     0,     0,     0,   285,     0,
       0,     0,     0,     0,   287,   288,   289,     0,   290,   291,
     292,     0,     0,     0,   124,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   293,   398,     0,     0,     0,     0,     0,   295,     0,
       0,     0,     0,   373,   220,   176,     0,  2071,     0,     0,
     298,   221,   222,   223,     0,     0,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   397,   243,   244,   245,   246,   247,
     248,   249,   250,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   176,   403,     0,     0,     0,
     256,   257,   258,   259,     0,     0,     0,     0,   260,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   265,   266,   267,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   269,    27,     0,
     270,   404,   405,   406,   407,   408,   409,   410,   411,   412,
       0,     0,     0,     0,   413,   414,   415,   416,     0,     0,
       0,     0,   417,   418,   419,   420,     0,     0,     0,     0,
       0,   421,     0,   422,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   423,
       0,     0,   424,     0,     0,     0,   182,     0,     0,   183,
       0,     0,   184,     0,   185,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    48,     0,   608,   609,   610,
     611,   612,   613,   614,   615,   616,   617,   618,   619,   620,
     721,   622,   623,   624,   625,     0,   453,     7,     8,   626,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1333,
       0,     0,     0,     0,     0,     0,     0,     0,   284,     0,
       0,     0,   285,     0,     0,     0,     0,     0,   287,   288,
     289,     0,   290,   291,   292,     0,     0,     0,   124,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   293,   398,     0,     0,     7,
       8,     0,   295,     0,     0,     0,     0,   373,     0,   425,
     426,   427,     0,     0,   298,     0,     0,     0,     0,     0,
       0,   428,     0,     0,     0,   429,     0,   430,   124,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,     0,     0,     0,    45,    46,    47,    48,     0,
       0,     0,     0,    50,     0,     0,     0,     0,     0,     0,
       0,  1846,   796,    58,     0,     0,    61,   797,     0,   798,
     799,     0,   800,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      82,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,     0,     7,     8,    45,    46,    47,
      48,     0,     0,     0,     0,    50,     0,     0,   100,   101,
     102,     0,     0,     0,   796,    58,     0,     0,    61,   797,
       0,   798,   799,     0,   800,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    82,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     7,     8,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     100,   101,   102,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1020,     0,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
       0,     0,     0,    45,    46,    47,    48,     0,     0,     0,
       0,    50,     0,     0,     0,     0,     0,     0,     0,     0,
     796,    58,     0,     0,    61,   797,     0,   798,   799,     0,
     800,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1022,    82,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,     0,     7,     8,    45,    46,    47,    48,     0,
       0,     0,     0,    50,     0,     0,   100,   101,   102,     0,
       0,     0,   796,    58,     0,     0,    61,   797,     0,   798,
     799,     0,   800,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      82,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     7,     8,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   100,   101,
     102,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1023,     0,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,     0,     0,
       0,    45,    46,    47,    48,     0,     0,     0,     0,    50,
       0,     0,     0,     0,     0,     0,     0,     0,   796,    58,
       0,     0,    61,   797,     0,   798,   799,     0,   800,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1077,    82,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
       0,     7,     8,    45,    46,    47,    48,     0,     0,     0,
       0,    50,     0,     0,   100,   101,   102,     0,     0,     0,
     796,    58,     0,     0,    61,   797,     0,   798,   799,     0,
     800,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    82,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     7,     8,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   100,   101,   102,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1079,     0,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,     0,     0,     0,    45,
      46,    47,    48,     0,     0,     0,     0,    50,     0,     0,
       0,     0,     0,     0,     0,     0,   796,    58,     0,     0,
      61,   797,     0,   798,   799,     0,   800,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1289,    82,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,     0,     7,
       8,    45,    46,    47,    48,     0,     0,     0,     0,    50,
       0,     0,   100,   101,   102,     0,     0,     0,   796,    58,
       0,     0,    61,   797,     0,   798,   799,     0,   800,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    82,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     7,     8,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   100,   101,   102,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1291,
       0,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,     0,     0,     0,    45,    46,    47,
      48,     0,     0,     0,     0,    50,     0,     0,     0,     0,
       0,     0,     0,     0,   796,    58,     0,     0,    61,   797,
       0,   798,   799,     0,   800,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1292,    82,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,     0,     7,     8,    45,
      46,    47,    48,     0,     0,     0,     0,    50,     0,     0,
     100,   101,   102,     0,     0,     0,   796,    58,     0,     0,
      61,   797,     0,   798,   799,     0,   800,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    82,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     7,
       8,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   100,   101,   102,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1311,     0,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,     0,     0,     0,    45,    46,    47,    48,     0,
       0,     0,     0,    50,     0,     0,     0,     0,     0,     0,
       0,     0,   796,    58,     0,     0,    61,   797,     0,   798,
     799,     0,   800,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1322,
      82,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,     0,     7,     8,    45,    46,    47,
      48,     0,     0,     0,     0,    50,     0,     0,   100,   101,
     102,     0,     0,     0,   796,    58,     0,     0,    61,   797,
       0,   798,   799,     0,   800,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    82,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     7,     8,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     100,   101,   102,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1341,     0,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
       0,     0,     0,    45,    46,    47,    48,     0,     0,     0,
       0,    50,     0,     0,     0,     0,     0,     0,     0,     0,
     796,    58,     0,     0,    61,   797,     0,   798,   799,     0,
     800,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1378,    82,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,     0,     7,     8,    45,    46,    47,    48,     0,
       0,     0,     0,    50,     0,     0,   100,   101,   102,     0,
       0,     0,   796,    58,     0,     0,    61,   797,     0,   798,
     799,     0,   800,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      82,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   721,   622,   623,   624,   625,     0,
       0,     0,     0,   626,     0,     0,     0,     0,   100,   101,
     102,     0,     0,  1359,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1550,     0,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,     0,     0,
       0,    45,    46,    47,    48,     0,     0,     0,     0,    50,
       0,     0,     0,     0,     0,     0,     0,     0,   796,    58,
       0,     0,    61,   797,     0,   798,   799,     0,   800,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2194,    82,     0,     0,     0,
      -4,     1,     0,     0,    -4,     0,     0,     0,     0,     0,
       0,     0,     0,    -4,    -4,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   100,   101,   102,     0,   608,   609,
     610,   611,   612,   613,   614,   615,   616,   617,   618,   619,
     620,   721,   622,   623,   624,   625,     0,    -4,    -4,    -4,
     626,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1442,     0,     0,     0,     0,     0,     0,     0,    -4,    -4,
      -4,     0,     0,     0,     0,    -4,    -4,     0,     0,     0,
       0,    -4,     0,     0,     0,     0,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,     0,    -4,    -4,     0,    -4,     0,     0,
       0,  2238,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,     0,
      -4,    -4,    -4,    -4,    -4,     0,     0,    -4,     0,    -4,
       0,    -4,    -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,     0,
      -4,    -4,    -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,
       0,     0,    -4,    -4,    -4,     0,     0,     0,    -4,     0,
       0,     0,     0,    -4,    -4,    -4,    -4,     0,     0,    -4,
       0,    -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,     6,     0,
       0,     0,     0,    -4,    -4,    -4,    -4,     7,     8,     0,
       0,     0,     0,     0,     0,    -4,     0,    -4,    -4,     0,
       0,     0,   608,   609,   610,   611,   612,   613,   614,   615,
     616,   617,   618,   619,   620,   721,   622,   623,   624,   625,
       0,     9,    10,    11,   626,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1447,     0,     0,     0,     0,     0,
       0,     0,    12,    13,    14,     0,     0,     0,     0,    15,
      16,     0,     0,     0,     0,    17,     0,     0,     0,     0,
      18,    19,    20,    21,    22,    23,    24,     0,    25,    26,
       0,    27,     0,     0,     0,     0,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,     0,     0,    44,    45,    46,    47,    48,     0,
       0,    49,     0,    50,     0,    51,    52,     0,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,     0,     0,    67,    68,    69,     0,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,     0,     0,     0,    95,    96,    97,     0,
       0,     0,    98,     0,     0,     0,     0,    99,   100,   101,
     102,   176,   403,   103,     0,   104,     0,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,     0,     0,     0,     0,     0,     0,   119,   120,   121,
     122,     0,     0,     0,     0,     0,     0,     0,     0,   123,
       0,   124,   125,     0,     0,     0,     0,   404,   405,   406,
     407,   408,   409,   410,   411,   412,     0,     0,     0,     0,
     413,   414,   415,   416,     0,   434,   403,     0,   417,   418,
     419,   420,     0,     0,     0,     0,     0,   421,     0,   422,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   423,     0,     0,   424,     0,
       0,     0,   182,     0,     0,   183,     0,     0,   184,     0,
     185,   404,   405,   406,   407,   408,   409,   410,   411,   412,
       0,    48,     0,     0,   413,   414,   415,   416,   403,     0,
       0,     0,   417,   418,   419,   420,     0,     0,     0,     0,
       0,   421,   453,   422,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     7,     8,   423,
       0,     0,   424,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   404,   405,   406,   407,   408,   409,   410,
     411,   412,     0,     0,     0,     0,   413,   414,   415,   416,
       0,     0,     0,     0,   417,   418,   419,   420,     0,     0,
       0,     0,     0,   421,     0,   422,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   425,   426,   427,     0,     0,
       0,   423,     0,     0,   424,     0,     0,   428,     0,     0,
       0,   429,     0,   430,   124,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,     0,     0,     0,    45,    46,    47,    48,     7,
       8,     0,     0,    50,     0,     0,     0,     0,     0,   425,
     426,   427,   796,    58,     0,     0,    61,   797,     0,   798,
     799,   428,   800,     0,     0,   429,  1085,   430,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      82,     0,     0,     0,  1086,   608,   609,   610,   611,   612,
     613,   614,   615,   616,   617,   618,   619,   620,   721,   622,
     623,   624,   625,     0,     0,     0,     0,   626,   100,   101,
     102,   425,   426,   427,     0,     0,     0,  1552,     0,     0,
       0,     0,     0,   428,     0,     0,     0,   429,     0,   430,
       0,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,     0,     0,     0,    45,    46,    47,
      48,     0,     0,     0,     0,    50,     0,     0,     0,     0,
       0,     0,     0,     0,   796,    58,     0,     0,    61,   797,
       0,   798,   799,     0,   800,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    82,   608,   609,   610,   611,   612,   613,   614,
     615,   616,   617,   618,   619,   620,   721,   622,   623,   624,
     625,     0,     0,     0,     0,   626,     0,     0,     0,     0,
     100,   101,   102,     0,     0,  1553,   608,   609,   610,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   721,
     622,   623,   624,   625,     0,     0,     0,     0,   626,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1593,   608,
     609,   610,   611,   612,   613,   614,   615,   616,   617,   618,
     619,   620,   721,   622,   623,   624,   625,     0,     0,     0,
       0,   626,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1725,   608,   609,   610,   611,   612,   613,   614,   615,
     616,   617,   618,   619,   620,   721,   622,   623,   624,   625,
       0,     0,     0,     0,   626,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1726,   608,   609,   610,   611,   612,
     613,   614,   615,   616,   617,   618,   619,   620,   721,   622,
     623,   624,   625,     0,     0,     0,     0,   626,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1727,   608,   609,
     610,   611,   612,   613,   614,   615,   616,   617,   618,   619,
     620,   721,   622,   623,   624,   625,     0,     0,     0,     0,
     626,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1875,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   721,   622,   623,   624,   625,     0,
       0,     0,     0,   626,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1997,   608,   609,   610,   611,   612,   613,
     614,   615,   616,   617,   618,   619,   620,   721,   622,   623,
     624,   625,     0,     0,     0,     0,   626,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1998,   608,   609,   610,
     611,   612,   613,   614,   615,   616,   617,   618,   619,   620,
     721,   622,   623,   624,   625,     0,     0,     0,     0,   626,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2032,
     608,   609,   610,   611,   612,   613,   614,   615,   616,   617,
     618,   619,   620,   721,   622,   623,   624,   625,     0,     0,
       0,     0,   626,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2105,   608,   609,   610,   611,   612,   613,   614,
     615,   616,   617,   618,   619,   620,   721,   622,   623,   624,
     625,     0,     0,     0,     0,   626,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2120,   608,   609,   610,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   721,
     622,   623,   624,   625,     0,     0,     0,     0,   626,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2122,   608,
     609,   610,   611,   612,   613,   614,   615,   616,   617,   618,
     619,   620,   721,   622,   623,   624,   625,     0,     0,     0,
       0,   626,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2160,   608,   609,   610,   611,   612,   613,   614,   615,
     616,   617,   618,   619,   620,   721,   622,   623,   624,   625,
       0,     0,     0,     0,   626,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2161,   608,   609,   610,   611,   612,
     613,   614,   615,   616,   617,   618,   619,   620,   721,   622,
     623,   624,   625,     0,     0,     0,     0,   626,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2175,   608,   609,
     610,   611,   612,   613,   614,   615,   616,   617,   618,   619,
     620,   721,   622,   623,   624,   625,     0,     0,     0,     0,
     626,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2206,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   721,   622,   623,   624,   625,     0,
       0,     0,     0,   626,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2227,   608,   609,   610,   611,   612,   613,
     614,   615,   616,   617,   618,   619,   620,   721,   622,   623,
     624,   625,     0,     0,     0,     0,   626,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2232,   608,   609,   610,
     611,   612,   613,   614,   615,   616,   617,   618,   619,   620,
     721,   622,   623,   624,   625,     0,     0,     0,     0,   626,
       0,     0,     0,     0,     0,  1120,   608,   609,   610,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   721,
     622,   623,   624,   625,     0,     0,     0,     0,   626,     0,
       0,     0,     0,     0,  1179,   608,   609,   610,   611,   612,
     613,   614,   615,   616,   617,   618,   619,   620,   721,   622,
     623,   624,   625,     0,     0,     0,     0,   626,     0,     0,
       0,     0,     0,  1228,   608,   609,   610,   611,   612,   613,
     614,   615,   616,   617,   618,   619,   620,   721,   622,   623,
     624,   625,     0,     0,     0,     0,   626,     0,     0,     0,
       0,     0,  1229,   608,   609,   610,   611,   612,   613,   614,
     615,   616,   617,   618,   619,   620,   721,   622,   623,   624,
     625,     0,     0,     0,     0,   626,     0,     0,     0,     0,
       0,  1281,   608,   609,   610,   611,   612,   613,   614,   615,
     616,   617,   618,   619,   620,   721,   622,   623,   624,   625,
       0,     0,     0,     0,   626,     0,     0,     0,     0,     0,
    1320,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   721,   622,   623,   624,   625,     0,
       0,     0,     0,   626,     0,     0,     0,     0,     0,  1328,
     608,   609,   610,   611,   612,   613,   614,   615,   616,   617,
     618,   619,   620,   721,   622,   623,   624,   625,     0,     0,
       0,     0,   626,     0,     0,     0,     0,     0,  1389,   608,
     609,   610,   611,   612,   613,   614,   615,   616,   617,   618,
     619,   620,   721,   622,   623,   624,   625,     0,     0,     0,
       0,   626,     0,     0,     0,     0,     0,  1409,   608,   609,
     610,   611,   612,   613,   614,   615,   616,   617,   618,   619,
     620,   721,   622,   623,   624,   625,     0,     0,     0,     0,
     626,     0,     0,     0,     0,     0,  1445,   608,   609,   610,
     611,   612,   613,   614,   615,   616,   617,   618,   619,   620,
     721,   622,   623,   624,   625,     0,     0,     0,     0,   626,
       0,     0,     0,     0,     0,  1497,   608,   609,   610,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   721,
     622,   623,   624,   625,     0,     0,     0,     0,   626,     0,
       0,     0,     0,     0,  1498,   608,   609,   610,   611,   612,
     613,   614,   615,   616,   617,   618,   619,   620,   721,   622,
     623,   624,   625,     0,     0,     0,     0,   626,     0,     0,
       0,     0,     0,  1499,   608,   609,   610,   611,   612,   613,
     614,   615,   616,   617,   618,   619,   620,   721,   622,   623,
     624,   625,     0,     0,     0,     0,   626,     0,     0,     0,
       0,     0,  1502,   608,   609,   610,   611,   612,   613,   614,
     615,   616,   617,   618,   619,   620,   721,   622,   623,   624,
     625,     0,     0,     0,     0,   626,     0,     0,     0,     0,
       0,  1503,   608,   609,   610,   611,   612,   613,   614,   615,
     616,   617,   618,   619,   620,   721,   622,   623,   624,   625,
       0,     0,     0,     0,   626,     0,     0,     0,     0,     0,
    1504,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   721,   622,   623,   624,   625,     0,
       0,     0,     0,   626,     0,     0,     0,     0,     0,  1506,
     608,   609,   610,   611,   612,   613,   614,   615,   616,   617,
     618,   619,   620,   721,   622,   623,   624,   625,     0,     0,
       0,     0,   626,     0,     0,     0,     0,     0,  1509,   608,
     609,   610,   611,   612,   613,   614,   615,   616,   617,   618,
     619,   620,   721,   622,   623,   624,   625,     0,     0,     0,
       0,   626,     0,     0,     0,     0,     0,  1554,   608,   609,
     610,   611,   612,   613,   614,   615,   616,   617,   618,   619,
     620,   721,   622,   623,   624,   625,     0,     0,     0,     0,
     626,     0,     0,     0,     0,     0,  1623,   608,   609,   610,
     611,   612,   613,   614,   615,   616,   617,   618,   619,   620,
     721,   622,   623,   624,   625,     0,     0,     0,     0,   626,
       0,     0,     0,     0,     0,  1736,   608,   609,   610,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   721,
     622,   623,   624,   625,     0,     0,     0,     0,   626,     0,
       0,     0,     0,     0,  1933,   608,   609,   610,   611,   612,
     613,   614,   615,   616,   617,   618,   619,   620,   721,   622,
     623,   624,   625,     0,     0,     0,     0,   626,     0,     0,
       0,     0,     0,  1944,   608,   609,   610,   611,   612,   613,
     614,   615,   616,   617,   618,   619,   620,   721,   622,   623,
     624,   625,     0,     0,     0,     0,   626,     0,     0,     0,
       0,     0,  1977,   608,   609,   610,   611,   612,   613,   614,
     615,   616,   617,   618,   619,   620,   721,   622,   623,   624,
     625,     0,     0,     0,     0,   626,     0,     0,     0,     0,
       0,  2012,   608,   609,   610,   611,   612,   613,   614,   615,
     616,   617,   618,   619,   620,   721,   622,   623,   624,   625,
       0,     0,     0,     0,   626,     0,     0,     0,     0,     0,
    2057,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   721,   622,   623,   624,   625,     0,
       0,     0,     0,   626,     0,     0,     0,     0,     0,  2066,
     608,   609,   610,   611,   612,   613,   614,   615,   616,   617,
     618,   619,   620,   721,   622,   623,   624,   625,     0,     0,
       0,     0,   626,     0,     0,     0,     0,     0,  2067,   608,
     609,   610,   611,   612,   613,   614,   615,   616,   617,   618,
     619,   620,   721,   622,   623,   624,   625,     0,     0,     0,
       0,   626,     0,     0,     0,     0,     0,  2082,   608,   609,
     610,   611,   612,   613,   614,   615,   616,   617,   618,   619,
     620,   721,   622,   623,   624,   625,     0,     0,     0,     0,
     626,     0,     0,     0,     0,     0,  2106,   608,   609,   610,
     611,   612,   613,   614,   615,   616,   617,   618,   619,   620,
     721,   622,   623,   624,   625,     0,     0,     0,     0,   626,
       0,     0,     0,     0,     0,  2121,   608,   609,   610,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   721,
     622,   623,   624,   625,     0,     0,     0,     0,   626,     0,
       0,     0,     0,     0,  2145,   608,   609,   610,   611,   612,
     613,   614,   615,   616,   617,   618,   619,   620,   721,   622,
     623,   624,   625,     0,     0,     0,     0,   626,     0,     0,
       0,     0,     0,  2148,   608,   609,   610,   611,   612,   613,
     614,   615,   616,   617,   618,   619,   620,   721,   622,   623,
     624,   625,     0,     0,     0,     0,   626,     0,     0,     0,
       0,     0,  2149,   608,   609,   610,   611,   612,   613,   614,
     615,   616,   617,   618,   619,   620,   721,   622,   623,   624,
     625,     0,     0,     0,     0,   626,     0,     0,     0,     0,
       0,  2174,   608,   609,   610,   611,   612,   613,   614,   615,
     616,   617,   618,   619,   620,   721,   622,   623,   624,   625,
       0,     0,     0,     0,   626,     0,     0,     0,     0,     0,
    2178,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   721,   622,   623,   624,   625,     0,
       0,     0,     0,   626,     0,     0,     0,     0,     0,  2211,
     608,   609,   610,   611,   612,   613,   614,   615,   616,   617,
     618,   619,   620,   721,   622,   623,   624,   625,     0,     0,
       0,     0,   626,     0,     0,     0,     0,     0,  2212,   608,
     609,   610,   611,   612,   613,   614,   615,   616,   617,   618,
     619,   620,   721,   622,   623,   624,   625,     0,     0,     0,
       0,   626,     0,     0,     0,     0,     0,  2220,   608,   609,
     610,   611,   612,   613,   614,   615,   616,   617,   618,   619,
     620,   721,   622,   623,   624,   625,     0,     0,     0,     0,
     626,     0,     0,     0,     0,     0,  2245,   608,   609,   610,
     611,   612,   613,   614,   615,   616,   617,   618,   619,   620,
     721,   622,   623,   624,   625,     0,     0,     0,     0,   626,
       0,     0,     0,     0,     0,  2270,   608,   609,   610,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   721,
     622,   623,   624,   625,     0,     0,     0,     0,   626,     0,
       0,     0,     0,     0,  2271,   608,   609,   610,   611,   612,
     613,   614,   615,   616,   617,   618,   619,   620,   721,   622,
     623,   624,   625,     0,     0,     0,     0,   626,     0,     0,
       0,     0,   758,   608,   609,   610,   611,   612,   613,   614,
     615,   616,   617,   618,   619,   620,   721,   622,   623,   624,
     625,     0,     0,     0,     0,   626,     0,     0,     0,     0,
     987,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   721,   622,   623,   624,   625,     0,
       0,     0,     0,   626,     0,     0,     0,     0,  2050,   608,
     609,   610,   611,   612,   613,   614,   615,   616,   617,   618,
     619,   620,   721,   622,   623,   624,   625,     0,     0,     0,
       0,   626,     0,     0,     0,  1051,   608,   609,   610,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   721,
     622,   623,   624,   625,     0,     0,     0,     0,   626,     0,
       0,     0,  1096,   608,   609,   610,   611,   612,   613,   614,
     615,   616,   617,   618,   619,   620,   721,   622,   623,   624,
     625,     0,     0,     0,     0,   626,     0,     0,     0,  1260,
     608,   609,   610,   611,   612,   613,   614,   615,   616,   617,
     618,   619,   620,   721,   622,   623,   624,   625,     0,     0,
       0,     0,   626,     0,     0,     0,  1321,   608,   609,   610,
     611,   612,   613,   614,   615,   616,   617,   618,   619,   620,
     721,   622,   623,   624,   625,     0,     0,     0,     0,   626,
       0,     0,     0,  1323,   608,   609,   610,   611,   612,   613,
     614,   615,   616,   617,   618,   619,   620,   721,   622,   623,
     624,   625,     0,     0,     0,     0,   626,     0,     0,     0,
    1331,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   721,   622,   623,   624,   625,     0,
       0,     0,     0,   626,     0,     0,     0,  1332,   608,   609,
     610,   611,   612,   613,   614,   615,   616,   617,   618,   619,
     620,   721,   622,   623,   624,   625,     0,     0,     0,     0,
     626,     0,     0,     0,  1424,   608,   609,   610,   611,   612,
     613,   614,   615,   616,   617,   618,   619,   620,   721,   622,
     623,   624,   625,     0,     0,     0,     0,   626,     0,     0,
       0,  1438,   608,   609,   610,   611,   612,   613,   614,   615,
     616,   617,   618,   619,   620,   721,   622,   623,   624,   625,
       0,     0,     0,     0,   626,     0,     0,     0,  1652,   608,
     609,   610,   611,   612,   613,   614,   615,   616,   617,   618,
     619,   620,   721,   622,   623,   624,   625,     0,     0,     0,
       0,   626,     0,     0,     0,  1752,   608,   609,   610,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   721,
     622,   623,   624,   625,     0,     0,     0,     0,   626,     0,
       0,     0,  1798,   608,   609,   610,   611,   612,   613,   614,
     615,   616,   617,   618,   619,   620,   721,   622,   623,   624,
     625,     0,     0,     0,     0,   626,     0,     0,     0,  1989,
     608,   609,   610,   611,   612,   613,   614,   615,   616,   617,
     618,   619,   620,   721,   622,   623,   624,   625,     0,     0,
       0,     0,   626,     0,     0,     0,  2040,   608,   609,   610,
     611,   612,   613,   614,   615,   616,   617,   618,   619,   620,
     721,   622,   623,   624,   625,     0,     0,     0,     0,   626,
       0,     0,     0,  2058,   608,   609,   610,   611,   612,   613,
     614,   615,   616,   617,   618,   619,   620,   721,   622,   623,
     624,   625,     0,     0,     0,     0,   626,     0,   837,   608,
     609,   610,   611,   612,   613,   614,   615,   616,   617,   618,
     619,   620,   721,   622,   623,   624,   625,     0,     0,     0,
       0,   626,     0,   838,   608,   609,   610,   611,   612,   613,
     614,   615,   616,   617,   618,   619,   620,   721,   622,   623,
     624,   625,     0,     0,     0,     0,   626,     0,   839,   608,
     609,   610,   611,   612,   613,   614,   615,   616,   617,   618,
     619,   620,   721,   622,   623,   624,   625,     0,     0,     0,
       0,   626,     0,   841,   608,   609,   610,   611,   612,   613,
     614,   615,   616,   617,   618,   619,   620,   721,   622,   623,
     624,   625,     0,     0,     0,     0,   626,     0,   842,   608,
     609,   610,   611,   612,   613,   614,   615,   616,   617,   618,
     619,   620,   721,   622,   623,   624,   625,     0,     0,     0,
       0,   626,     0,   843,   608,   609,   610,   611,   612,   613,
     614,   615,   616,   617,   618,   619,   620,   721,   622,   623,
     624,   625,     0,     0,     0,     0,   626,     0,   845,   608,
     609,   610,   611,   612,   613,   614,   615,   616,   617,   618,
     619,   620,   721,   622,   623,   624,   625,     0,     0,     0,
       0,   626,     0,   846,   608,   609,   610,   611,   612,   613,
     614,   615,   616,   617,   618,   619,   620,   721,   622,   623,
     624,   625,     0,     0,     0,     0,   626,     0,   847,   608,
     609,   610,   611,   612,   613,   614,   615,   616,   617,   618,
     619,   620,   721,   622,   623,   624,   625,     0,     0,     0,
       0,   626,     0,   848,   608,   609,   610,   611,   612,   613,
     614,   615,   616,   617,   618,   619,   620,   721,   622,   623,
     624,   625,     0,     0,     0,     0,   626,     0,   849,   608,
     609,   610,   611,   612,   613,   614,   615,   616,   617,   618,
     619,   620,   721,   622,   623,   624,   625,     0,     0,     0,
       0,   626,     0,   850,   608,   609,   610,   611,   612,   613,
     614,   615,   616,   617,   618,   619,   620,   721,   622,   623,
     624,   625,     0,     0,     0,     0,   626,     0,   851,   608,
     609,   610,   611,   612,   613,   614,   615,   616,   617,   618,
     619,   620,   721,   622,   623,   624,   625,     0,     0,     0,
       0,   626,     0,   854,   608,   609,   610,   611,   612,   613,
     614,   615,   616,   617,   618,   619,   620,   721,   622,   623,
     624,   625,     0,     0,     0,     0,   626,     0,   855,   608,
     609,   610,   611,   612,   613,   614,   615,   616,   617,   618,
     619,   620,   721,   622,   623,   624,   625,     0,     0,     0,
       0,   626,     0,   856,   608,   609,   610,   611,   612,   613,
     614,   615,   616,   617,   618,   619,   620,   721,   622,   623,
     624,   625,     0,     0,     0,     0,   626,     0,   934,   608,
     609,   610,   611,   612,   613,   614,   615,   616,   617,   618,
     619,   620,   721,   622,   623,   624,   625,     0,     0,     0,
       0,   626,     0,   968,   608,   609,   610,   611,   612,   613,
     614,   615,   616,   617,   618,   619,   620,   721,   622,   623,
     624,   625,     0,     0,     0,     0,   626,     0,  1009,   608,
     609,   610,   611,   612,   613,   614,   615,   616,   617,   618,
     619,   620,   721,   622,   623,   624,   625,     0,     0,     0,
       0,   626,     0,  1028,   608,   609,   610,   611,   612,   613,
     614,   615,   616,   617,   618,   619,   620,   721,   622,   623,
     624,   625,     0,     0,     0,     0,   626,     0,  1036,   608,
     609,   610,   611,   612,   613,   614,   615,   616,   617,   618,
     619,   620,   721,   622,   623,   624,   625,     0,     0,     0,
       0,   626,     0,  1038,   608,   609,   610,   611,   612,   613,
     614,   615,   616,   617,   618,   619,   620,   721,   622,   623,
     624,   625,     0,     0,     0,     0,   626,     0,  1039,   608,
     609,   610,   611,   612,   613,   614,   615,   616,   617,   618,
     619,   620,   721,   622,   623,   624,   625,     0,     0,     0,
       0,   626,     0,  1045,   608,   609,   610,   611,   612,   613,
     614,   615,   616,   617,   618,   619,   620,   721,   622,   623,
     624,   625,     0,     0,     0,     0,   626,     0,  1046,   608,
     609,   610,   611,   612,   613,   614,   615,   616,   617,   618,
     619,   620,   721,   622,   623,   624,   625,     0,     0,     0,
       0,   626,     0,  1084,   608,   609,   610,   611,   612,   613,
     614,   615,   616,   617,   618,   619,   620,   721,   622,   623,
     624,   625,     0,     0,     0,     0,   626,     0,  1095,   608,
     609,   610,   611,   612,   613,   614,   615,   616,   617,   618,
     619,   620,   721,   622,   623,   624,   625,     0,     0,     0,
       0,   626,     0,  1157,   608,   609,   610,   611,   612,   613,
     614,   615,   616,   617,   618,   619,   620,   721,   622,   623,
     624,   625,     0,     0,     0,     0,   626,     0,  1161,   608,
     609,   610,   611,   612,   613,   614,   615,   616,   617,   618,
     619,   620,   721,   622,   623,   624,   625,     0,     0,     0,
       0,   626,     0,  1174,   608,   609,   610,   611,   612,   613,
     614,   615,   616,   617,   618,   619,   620,   721,   622,   623,
     624,   625,     0,     0,     0,     0,   626,     0,  1259,   608,
     609,   610,   611,   612,   613,   614,   615,   616,   617,   618,
     619,   620,   721,   622,   623,   624,   625,     0,     0,     0,
       0,   626,     0,  1269,   608,   609,   610,   611,   612,   613,
     614,   615,   616,   617,   618,   619,   620,   721,   622,   623,
     624,   625,     0,     0,     0,     0,   626,     0,  1270,   608,
     609,   610,   611,   612,   613,   614,   615,   616,   617,   618,
     619,   620,   721,   622,   623,   624,   625,     0,     0,     0,
       0,   626,     0,  1271,   608,   609,   610,   611,   612,   613,
     614,   615,   616,   617,   618,   619,   620,   721,   622,   623,
     624,   625,     0,     0,     0,     0,   626,     0,  1280,   608,
     609,   610,   611,   612,   613,   614,   615,   616,   617,   618,
     619,   620,   721,   622,   623,   624,   625,     0,     0,     0,
       0,   626,     0,  1282,   608,   609,   610,   611,   612,   613,
     614,   615,   616,   617,   618,   619,   620,   721,   622,   623,
     624,   625,     0,     0,     0,     0,   626,     0,  1283,   608,
     609,   610,   611,   612,   613,   614,   615,   616,   617,   618,
     619,   620,   721,   622,   623,   624,   625,     0,     0,     0,
       0,   626,     0,  1319,   608,   609,   610,   611,   612,   613,
     614,   615,   616,   617,   618,   619,   620,   721,   622,   623,
     624,   625,     0,     0,     0,     0,   626,     0,  1334,   608,
     609,   610,   611,   612,   613,   614,   615,   616,   617,   618,
     619,   620,   721,   622,   623,   624,   625,     0,     0,     0,
       0,   626,     0,  1336,   608,   609,   610,   611,   612,   613,
     614,   615,   616,   617,   618,   619,   620,   721,   622,   623,
     624,   625,     0,     0,     0,     0,   626,     0,  1377,   608,
     609,   610,   611,   612,   613,   614,   615,   616,   617,   618,
     619,   620,   721,   622,   623,   624,   625,     0,     0,     0,
       0,   626,     0,  1423,   608,   609,   610,   611,   612,   613,
     614,   615,   616,   617,   618,   619,   620,   721,   622,   623,
     624,   625,     0,     0,     0,     0,   626,     0,  1437,   608,
     609,   610,   611,   612,   613,   614,   615,   616,   617,   618,
     619,   620,   721,   622,   623,   624,   625,     0,     0,     0,
       0,   626,     0,  1653,   608,   609,   610,   611,   612,   613,
     614,   615,   616,   617,   618,   619,   620,   721,   622,   623,
     624,   625,     0,     0,     0,     0,   626,     0,  1692,   608,
     609,   610,   611,   612,   613,   614,   615,   616,   617,   618,
     619,   620,   721,   622,   623,   624,   625,     0,     0,     0,
       0,   626,     0,  1739,   608,   609,   610,   611,   612,   613,
     614,   615,   616,   617,   618,   619,   620,   721,   622,   623,
     624,   625,     0,     0,     0,     0,   626,     0,  1751,   608,
     609,   610,   611,   612,   613,   614,   615,   616,   617,   618,
     619,   620,   721,   622,   623,   624,   625,     0,     0,     0,
       0,   626,     0,  1861,   608,   609,   610,   611,   612,   613,
     614,   615,   616,   617,   618,   619,   620,   721,   622,   623,
     624,   625,     0,     0,     0,     0,   626,     0,  1863,   608,
     609,   610,   611,   612,   613,   614,   615,   616,   617,   618,
     619,   620,   721,   622,   623,   624,   625,     0,     0,     0,
       0,   626,     0,  1867,   608,   609,   610,   611,   612,   613,
     614,   615,   616,   617,   618,   619,   620,   721,   622,   623,
     624,   625,     0,     0,     0,     0,   626,     0,  1874,   608,
     609,   610,   611,   612,   613,   614,   615,   616,   617,   618,
     619,   620,   721,   622,   623,   624,   625,     0,     0,     0,
       0,   626,     0,  1934,   608,   609,   610,   611,   612,   613,
     614,   615,   616,   617,   618,   619,   620,   721,   622,   623,
     624,   625,     0,     0,     0,     0,   626,     0,  1943,   608,
     609,   610,   611,   612,   613,   614,   615,   616,   617,   618,
     619,   620,   721,   622,   623,   624,   625,     0,     0,     0,
       0,   626,     0,  1960,   608,   609,   610,   611,   612,   613,
     614,   615,   616,   617,   618,   619,   620,   721,   622,   623,
     624,   625,     0,     0,     0,     0,   626,     0,  2039,   608,
     609,   610,   611,   612,   613,   614,   615,   616,   617,   618,
     619,   620,   721,   622,   623,   624,   625,     0,     0,     0,
       0,   626,     0,  2103,   608,   609,   610,   611,   612,   613,
     614,   615,   616,   617,   618,   619,   620,   721,   622,   623,
     624,   625,     0,     0,     0,     0,   626,     0,  2104,   608,
     609,   610,   611,   612,   613,   614,   615,   616,   617,   618,
     619,   620,   721,   622,   623,   624,   625,     0,     0,     0,
       0,   626,     0,  2117,   608,   609,   610,   611,   612,   613,
     614,   615,   616,   617,   618,   619,   620,   721,   622,   623,
     624,   625,     0,     0,     0,     0,   626,     0,  2226,   608,
     609,   610,   611,   612,   613,   614,   615,   616,   617,   618,
     619,   620,   721,   622,   623,   624,   625,     0,     0,     0,
       0,   626,     0,  2253,   608,   609,   610,   611,   612,   613,
     614,   615,   616,   617,   618,   619,   620,   721,   622,   623,
     624,   625,     0,     0,     0,     0,   626
};

static const yytype_int16 yycheck[] =
{
       3,   334,  1308,     3,   665,   666,    71,    72,     5,    74,
    1513,     4,    98,   164,   150,  1312,  1829,     4,  1831,     4,
     779,    65,     4,     4,    27,     5,   785,     6,     5,    27,
       4,     7,     5,     4,     6,   114,   111,   116,     6,     6,
       6,     6,     6,     6,     6,     4,     6,     4,  2015,   111,
       4,     4,  1818,   108,    57,  2047,   111,   112,   113,   149,
       7,     9,   111,     6,   168,   169,    68,   105,   463,   124,
     170,   150,   154,   155,     6,     9,     4,   159,     6,     6,
     254,   255,   111,    86,     9,   266,   124,   268,   149,   138,
      93,   272,   270,     4,   275,    98,   274,     9,     9,   199,
     103,   275,   181,   105,    97,   267,   167,  2099,   187,   138,
       0,   114,   202,   275,     6,   215,   216,  1883,   179,   180,
     181,     6,   208,     6,   185,   186,   149,   272,   254,   255,
     275,   217,   256,   257,   258,   259,   260,   149,     4,   194,
     267,   265,   254,   255,   167,   272,     7,   150,   149,   275,
       9,   151,   155,   156,   157,   167,   179,   180,   181,   271,
      26,   164,   185,   186,     9,    14,   167,   179,   180,   181,
     269,    37,    38,   185,   186,   267,   275,   105,   179,   180,
     181,   254,   255,   275,   185,   186,   254,   255,   269,     4,
     111,   266,   105,   266,   275,   108,     7,   270,   111,   266,
     203,     7,  2169,   175,   266,   208,   266,   275,   187,   212,
     271,   124,   263,   264,   217,   218,   219,   210,   262,   263,
     264,   272,   263,   264,   254,   255,   266,   187,   254,   255,
       7,   270,   318,   319,   320,   630,   271,  2229,     8,   283,
     275,  1744,   346,   214,   237,   275,   254,   255,   271,   275,
     237,   266,   237,   268,   358,   270,   237,     6,   266,   271,
     364,   365,   270,   237,  1570,   351,   352,   353,     6,     7,
       7,  2263,   337,   270,   339,     7,   279,   270,   237,   267,
     345,   346,   267,   270,   269,   371,   268,   275,   270,   270,
     270,   294,   274,   270,   297,   298,   272,   270,   266,   273,
     298,   270,   270,   270,   270,   270,   270,   270,   270,   266,
     313,   314,   266,   266,   317,   318,   319,   320,   266,   266,
     268,   268,   254,   255,   272,   328,   237,   254,   255,   332,
     725,   334,   266,   437,   268,   439,  1095,  1096,   263,   264,
       6,   266,   446,   268,   269,   348,   349,   272,   351,   352,
     353,     6,   263,   264,   266,   266,   268,   268,     6,   270,
     272,   272,   254,   255,   249,   250,   249,   250,   371,   108,
     266,   374,   111,   452,   189,   190,   191,   192,   239,   240,
     241,   242,   266,     6,   268,   124,   201,  2200,   203,   204,
     205,   206,   207,     6,   254,   255,   211,   212,   793,   214,
     254,   255,   263,   264,   263,   264,   111,   266,   113,   268,
     270,   272,   267,   272,   269,   810,   270,   568,   263,   264,
     275,   266,   266,   268,   268,   820,     4,   272,   239,   240,
     241,   242,     8,   239,   240,   241,   242,     6,   266,   442,
     268,   444,   272,   267,   274,   448,   449,   275,    26,     6,
       4,   275,   263,   264,   254,   255,   271,   263,   264,    37,
      38,   464,   239,   240,   241,   242,   259,   260,   471,   573,
     254,   255,   265,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   275,   267,   108,   497,   265,   111,     4,   113,   585,
     275,   271,   239,   240,   241,   242,     4,   239,   240,   241,
     242,   254,   255,   592,   266,  1176,   128,   267,   270,    26,
     523,   254,   255,   268,     4,   275,   263,   264,    26,   271,
      37,    38,   275,   275,  2037,   108,   114,   115,   111,    37,
      38,   936,   275,   267,   266,   548,    26,   254,   255,   268,
     654,   275,   656,   657,   557,   558,   266,    37,    38,   562,
     270,   564,   565,   566,   567,   568,     6,   267,   275,   673,
     254,   255,   575,   254,   255,   275,   267,   267,   729,   269,
     684,   584,   585,   586,   275,   588,   589,   590,   591,   270,
     593,   275,   595,   591,   266,   593,   149,     4,   663,   664,
     154,   155,   156,   157,   669,   159,   160,   114,   115,   713,
     267,   111,   269,   270,   167,   169,   114,   115,   621,    26,
     174,   199,   200,   266,   627,   268,   179,   180,   181,   267,
      37,    38,   185,   186,   114,   115,   105,   275,   267,   108,
     269,   270,   111,   779,   113,   108,   649,   650,   111,   267,
     113,   269,  1313,  1314,   758,   124,   267,   275,   269,   108,
     266,   124,   111,   742,   275,   665,   666,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,     6,   267,   690,   269,   265,
     693,   694,   199,   200,   275,   271,   267,   700,   269,   263,
     264,   271,  1097,   266,   275,   275,   270,   114,   115,   254,
     255,   256,   257,   258,   259,   260,   154,   155,   271,   722,
     265,   159,   266,   266,   727,   728,   729,   730,   731,   732,
     733,   734,   735,   266,   737,   738,   739,   740,   741,   266,
     743,   744,   745,   746,   747,   266,   266,   750,   746,   263,
     264,   266,   266,   268,   268,   799,   270,   836,   263,   264,
     271,   266,   271,   268,   275,   768,   275,     8,   263,   264,
     271,   266,   271,   268,   275,   271,   275,   266,   271,   275,
    1539,   784,   275,     4,   266,     6,   270,   790,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   806,   807,   266,   271,   265,   270,   812,
     275,   814,   271,   113,   817,   818,   275,   271,   271,   271,
     266,   275,   275,   275,   827,   266,   829,   266,   270,   965,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   266,   923,   271,   108,   265,  1243,   275,
    1245,   271,   271,   111,   271,   275,   275,   860,   275,   862,
     271,   271,   271,  1258,   275,   275,   275,   271,   271,  1628,
      57,   275,   275,   271,   271,   266,   271,   275,   275,  1638,
     275,   266,   271,   111,   271,   150,   275,   991,   275,   270,
     155,   156,   157,  1288,   270,   898,   271,   271,  2195,   978,
     275,   275,   271,   271,   271,   908,   275,   275,   275,   271,
     108,   271,   270,   275,  1050,   275,  2222,   271,   108,   271,
     923,   275,     3,   275,   271,   111,   271,   271,   275,   994,
     275,   275,   111,   271,   270,   938,  1001,   275,   203,   270,
    1005,   271,  2239,  2249,     4,   275,     8,     4,    29,  1344,
       4,   954,  1347,  1348,   219,     4,   266,   271,   271,  1095,
    1096,   275,   275,   966,   271,   271,   271,   271,   275,   275,
     275,   275,   975,   266,   271,   271,  1112,  1372,   275,   275,
       6,   271,   271,    64,   987,   275,   275,   271,   266,     6,
       6,   275,   268,   266,   268,   270,     6,   274,   270,     6,
    1395,     9,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
    1099,   274,   266,   266,   265,   270,   267,  1422,   269,   266,
     266,   218,   266,   266,   266,   270,   202,   202,   119,   202,
     270,  1436,   111,   138,   266,   202,   266,   266,  1443,   266,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,  1399,   270,   270,   150,
     265,   270,   266,   266,   155,   156,   157,   266,   266,     4,
       6,   202,     6,   164,     6,   270,   270,  1090,   270,  1154,
     268,     7,   279,   270,   270,  1098,   270,   270,   270,   268,
     268,   268,     6,  1106,     6,   266,   266,   266,   270,     6,
     266,   266,   266,   266,  1775,  1776,  1119,   266,   268,     6,
       6,  1124,   203,  1259,  1260,   270,     8,     6,     8,   266,
     317,   270,     7,     6,   270,   270,     6,   270,   219,   271,
     100,   328,     7,     6,   275,   332,   275,     6,   267,   272,
     270,   265,  1155,  1156,   270,  1158,  1159,  1160,   270,  1162,
    1163,  1164,  1165,  1166,  1167,  1168,   270,  1170,  1171,  1172,
     270,   270,   270,   270,   270,    68,  1176,   442,   270,     8,
     261,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,     7,
     281,   282,     7,   265,   267,   267,     6,   266,     7,   270,
       6,   199,     7,     6,  1217,  1218,  1219,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,     6,   271,   270,   267,   265,
     271,   271,   269,     6,   272,   270,     7,  1250,     6,   268,
     270,   266,     6,     6,     6,     6,   270,     6,   267,     7,
       7,   448,   449,  1266,  1267,  1268,   268,     7,     7,     7,
       7,     7,     7,     7,     7,     7,     7,   464,     7,     7,
       7,     7,     6,   267,   269,   275,   275,  1423,  1424,   275,
     271,   270,   275,   267,     7,   271,     7,   562,  1631,   564,
     272,   566,   567,   270,   270,     4,     6,   272,   271,   271,
     149,   270,  1315,  1313,  1314,   270,     7,     6,   270,     7,
       7,     7,   272,   588,   589,   272,   267,   267,     9,   275,
     275,   275,  1335,   267,  1337,  1338,   269,   274,   202,     7,
     170,   271,   270,     6,     6,     6,    50,  1350,    50,   272,
    1429,   266,  1355,   270,   266,   266,  1359,   270,   272,   266,
       7,   442,   272,     7,     7,  1368,   275,  1370,   202,  1448,
    1373,  1450,   453,   267,     7,     7,     7,     6,   565,   267,
     275,     7,     7,  1386,     7,     7,     7,     4,     6,   270,
     266,   105,  2053,   123,   475,     6,  1399,   584,   270,   586,
       6,     6,   111,     7,     7,     6,     6,     4,     7,   490,
     491,     7,   273,   275,   267,   275,     6,   271,   270,   270,
     270,  1424,     6,     6,   268,     7,  1429,     6,  1431,  1508,
       6,     6,   270,   266,   266,     6,   271,     6,     6,     6,
    1835,   272,     6,   269,     6,     6,   142,  1450,   275,     6,
       6,     6,     6,     6,     6,     6,     6,     6,     6,     6,
    1463,     6,     6,   728,  1467,   730,   731,   732,   733,   734,
     735,     5,   737,   738,   739,   740,   267,   271,   743,   744,
     745,   562,   202,   564,   129,   566,   567,   568,  1639,  1640,
     129,   129,  1628,   267,     6,     6,     4,     6,   270,     6,
     270,     7,     7,   270,  1569,   270,   270,   588,   589,   268,
    1843,     6,  1616,     6,   271,   271,  1620,     6,   198,     6,
     270,     6,     6,   267,   270,   270,     6,     4,     7,   272,
    1533,  1534,  1535,  1612,   275,     6,     6,     6,  1541,  1542,
    1543,     6,     6,   266,     7,     6,     6,     6,   266,   266,
     275,   270,   817,   275,   275,   271,   149,  1560,     6,     5,
     270,     6,   270,   109,   829,   270,   267,   270,   111,   275,
       6,     6,  1575,   270,     6,   149,   149,   275,     6,     6,
     275,   768,   267,   275,  1587,     6,  1589,     6,     6,     6,
     671,   275,   270,   270,     6,     6,     6,     6,  1677,     6,
     270,     7,     6,   270,   270,   270,   687,     5,   267,     6,
     691,   692,   153,   270,  1750,     6,   270,     6,   270,     6,
     271,   271,     7,     6,   270,     6,     6,   197,  1631,     6,
    1695,   267,     7,     6,   271,     6,  1639,  1640,   272,     6,
       6,   271,  1645,   271,     6,     6,   727,   728,   729,   730,
     731,   732,   733,   734,   735,   270,   737,   738,   739,   740,
       6,  1664,   743,   744,   745,     6,     6,     6,   200,   271,
       6,     6,   753,   267,  1677,   756,   271,   266,   270,  1682,
     271,   762,   270,   270,   270,     6,   267,     6,     6,     6,
     270,   149,  1771,   271,     6,  1846,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,     6,     6,     6,   798,   265,   800,
       6,     6,     6,     6,   212,     6,     6,     6,   270,   267,
     270,   270,  1811,  1435,   271,   271,   817,   270,  2202,  1818,
    1819,   270,  1500,  2016,  1690,  1974,  1462,  1758,   829,     3,
       3,   938,   494,  2086,   582,  1108,     3,     3,  1837,  1762,
    2049,  1609,     3,  1640,  1767,  1768,  1429,  1836,   642,   817,
    1818,    -1,    -1,    -1,    -1,  1775,  1776,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   975,  1792,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1803,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1813,    -1,    -1,  1816,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   313,   314,    -1,    -1,  1832,
      -1,    -1,    -1,  1836,    -1,    -1,    -1,    -1,    -1,    -1,
    1843,    -1,  1845,  1846,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1124,
     348,   349,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
    1883,    -1,    -1,    -1,   265,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1976,    -1,    -1,
      -1,    -1,    -1,  1090,    -1,    -1,    -1,    -1,    -1,   990,
      -1,   992,   993,    -1,  1917,  1918,    -1,    -1,    -1,  1106,
      -1,    -1,    -1,    -1,    -1,  1006,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1018,    -1,  1942,
      -1,     6,  2021,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1218,  1219,    -1,   444,    -1,  2062,  1962,
      -1,  1042,    -1,    -1,    -1,    -1,    -1,    -1,  1155,  1156,
      -1,  1158,  1159,  1160,    -1,  1162,  1163,  1164,  1165,  1166,
    1167,  1168,    -1,  1170,  1171,  1172,    -1,    -1,    -1,    -1,
      -1,     6,    -1,    -1,    -1,    -1,    -1,  2000,    -1,    -1,
    1081,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2017,    -1,    -1,    -1,    -1,  2022,
      -1,    -1,  2025,  2026,    -1,    -1,    -1,    -1,    -1,    -1,
    1217,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1124,  2047,    -1,    -1,  2050,    -1,    -1,
    2154,    -1,    -1,  2053,    -1,    -1,    -1,    -1,  2061,    -1,
      -1,    -1,    -1,  1250,     7,     8,  2131,    -1,  2071,    -1,
    2135,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1266,
      -1,    -1,    -1,  2086,    -1,    -1,    -1,    -1,    -1,    -1,
    1355,  2170,  2196,    -1,  1359,    -1,  2099,    -1,    -1,    -1,
      -1,    -1,    -1,  1368,    -1,  1370,    -1,   595,  1373,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2182,    -1,    -1,
      -1,  2186,    -1,    -1,    -1,    -1,    -1,    -1,  1315,  2132,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1218,  1219,     6,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1335,    -1,
    1337,  1338,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1424,
      -1,   649,   650,    -1,    -1,    -1,    -1,    -1,    -1,  2234,
    2235,    -1,    -1,    -1,    -1,    -1,    -1,  2180,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,     6,    -1,    -1,  1386,
     265,    -1,   690,    -1,    -1,   693,   694,    -1,    -1,  1290,
      -1,    -1,   700,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2229,    -1,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,    -1,    -1,    -1,  2252,
     265,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2263,    -1,   750,  1450,  2267,  2268,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1355,    -1,  1463,  2280,  1359,    -1,
    1467,    -1,    -1,    -1,    -1,    -1,    -1,  1368,    -1,  1370,
      -1,    -1,  1373,    -1,    -1,    -1,   784,    -1,    -1,  1380,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   806,    -1,
      -1,    -1,   265,    -1,   812,    -1,   814,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1424,    -1,    -1,  1533,  1534,  1535,    -1,
      -1,    -1,    -1,    -1,  1541,  1542,  1543,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1560,    -1,    -1,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,  1664,
    1587,    -1,  1589,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     898,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     908,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,    -1,    -1,    -1,    -1,   265,    -1,    -1,  1645,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   954,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   966,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
    1677,     6,    -1,    -1,    -1,    10,    11,    12,    -1,   987,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    59,    60,    61,    62,  1813,    -1,
      -1,  1816,    67,    -1,    -1,    -1,    -1,    -1,  1639,  1640,
       4,     5,    -1,    -1,    -1,    -1,    -1,    -1,    83,    84,
      85,    -1,    -1,    -1,    -1,  1762,    -1,    -1,    -1,    -1,
      -1,    96,    97,  1664,    99,    -1,    -1,   149,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    -1,  1803,    -1,    -1,    63,
      64,    65,    66,    -1,    -1,    -1,    -1,    71,    72,    73,
      74,  1119,    -1,    -1,    -1,    -1,    80,    -1,    82,    -1,
      -1,    -1,    -1,    -1,    -1,  1832,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    98,    -1,    -1,   101,  1845,    -1,
      -1,   105,    -1,    -1,   108,    -1,    -1,   111,    -1,   113,
      -1,    -1,    -1,    -1,    -1,    -1,     6,    -1,    -1,    -1,
     124,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,    -1,
      -1,   145,   217,   265,    -1,    -1,   221,    -1,    -1,     6,
      -1,    -1,   227,   228,   229,    -1,   231,   232,   233,    -1,
      -1,    -1,   237,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1813,     7,    -1,  1816,    -1,    -1,    -1,   254,
     255,    -1,    -1,    -1,    -1,    -1,   261,    -1,  1829,    -1,
    1831,   266,    -1,    -1,    -1,  1942,    -1,    -1,   273,    -1,
      -1,    -1,    -1,    -1,    -1,  1846,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   218,   219,   220,    -1,    -1,  1267,
    1268,    -1,    -1,    -1,    -1,    -1,   230,    -1,    -1,    -1,
     234,    -1,   236,   237,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1883,    -1,    -1,    -1,    -1,    -1,    -1,   110,
      -1,    -1,    -1,  2000,    -1,    -1,    -1,    -1,    -1,   263,
     264,    -1,   123,    -1,    -1,    -1,   270,    -1,   272,    -1,
    2017,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   150,
      -1,    -1,    -1,   154,    -1,    -1,    -1,    -1,   159,    -1,
    2047,    -1,  1350,    -1,    -1,   166,    -1,    -1,   169,    -1,
      -1,    -1,    -1,    -1,  2061,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     6,   188,   189,   190,
      -1,   192,   193,   194,    -1,   196,   197,   198,   199,   200,
     201,   202,    -1,   204,   205,   206,   207,    -1,    -1,    -1,
      -1,   212,  2099,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,    -1,    -1,    -1,    -1,   265,    -1,    -1,    -1,    -1,
      -1,  1429,    -1,  1431,    -1,  2132,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,  2252,    -1,    -1,
      -1,   265,   293,   294,   295,   296,   297,    -1,    -1,    -1,
      -1,    -1,  2267,  2268,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   312,   313,   314,    -1,  2280,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   330,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   340,
     341,    -1,  2229,    -1,    -1,   346,    -1,   348,   349,   350,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2144,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   373,   374,    -1,    -1,  2263,    -1,    -1,    -1,
      -1,    -1,    -1,   384,    -1,   386,   387,  1575,   389,    -1,
      -1,    -1,   393,   394,   395,    -1,    -1,   398,    -1,    -1,
      -1,   402,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2200,
      -1,    -1,    -1,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,    -1,  2223,   444,   445,   265,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     461,   462,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2252,    -1,    -1,    -1,   476,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2267,  2268,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   499,  2280,
      -1,    -1,    -1,   504,    -1,    -1,    -1,   508,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   522,   523,    -1,    -1,    -1,   527,    -1,    -1,    -1,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     541,   542,   543,   544,   545,   546,   547,   548,   549,   550,
     551,   552,   553,   554,   555,   556,   557,   558,    -1,   560,
     561,    -1,   563,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   574,    -1,    -1,   577,   578,    -1,  1767,
    1768,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   590,
      -1,    -1,    -1,    -1,   595,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1792,    -1,   607,   608,   609,   610,
     611,   612,   613,   614,   615,   616,   617,   618,   619,   620,
     621,   622,   623,   624,   625,   626,     6,   628,   629,    -1,
      -1,    -1,    -1,    -1,    -1,   636,   637,   638,    -1,    -1,
      -1,    -1,    -1,   644,   645,   646,   647,    -1,   649,   650,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   668,   669,   670,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   680,
     681,    -1,   683,    -1,    -1,   686,    -1,    -1,    -1,   690,
       6,    -1,   693,   694,   695,    -1,    -1,    -1,   699,   700,
     701,   702,   703,    -1,    -1,   706,    -1,   708,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   718,    -1,    -1,
     721,    -1,   723,   724,    -1,    -1,    -1,    -1,    -1,  1917,
    1918,    -1,    -1,    -1,    -1,   736,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   750,
      -1,    -1,    -1,    -1,    -1,    -1,   757,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   765,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1962,    -1,     6,    -1,    -1,    -1,
      -1,    -1,    -1,   784,    -1,   786,    -1,    -1,    -1,    -1,
     791,   792,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   806,    -1,   808,   809,     6,
      -1,   812,    -1,   814,   815,    -1,    -1,    -1,   819,    -1,
     821,    -1,    -1,   824,    -1,    -1,    -1,    -1,    -1,   830,
      -1,    -1,    -1,   834,    -1,    -1,    -1,  2025,  2026,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   853,    -1,    -1,    -1,    -1,   858,    -1,   860,
      -1,   862,  2050,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,    -1,    -1,  2071,    -1,   265,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   898,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   908,   909,   910,
     911,    -1,    -1,    -1,    -1,    -1,    -1,   918,   919,   920,
      -1,   922,   923,    -1,    -1,   926,    -1,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,
      -1,    -1,    -1,   954,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   966,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   974,    -1,    -1,    -1,   978,    -1,    -1,
      -1,    -1,    -1,   984,    -1,    -1,   987,    -1,    -1,    -1,
      -1,    -1,  2180,    -1,   995,   996,    -1,    -1,    -1,    -1,
    1001,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1010,
      -1,    -1,  1013,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,    -1,    -1,    -1,    -1,   265,    -1,    -1,    -1,    -1,
    1041,    -1,  1043,  1044,    -1,    -1,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,    -1,  1066,    -1,    -1,   265,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     4,     5,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1086,    -1,    -1,    -1,    -1,
      -1,    -1,  1093,    -1,    -1,    -1,    -1,    -1,    -1,  1100,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1113,  1114,    -1,    -1,    -1,    -1,  1119,    -1,
      -1,    -1,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    -1,    -1,    -1,   212,    63,    64,    65,    66,    -1,
      -1,  1142,    -1,    71,    72,    73,    74,    -1,    -1,    -1,
      -1,  1152,    80,    -1,    82,    -1,    -1,    -1,    -1,     6,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      98,    -1,    -1,   101,    -1,    -1,    -1,   105,    -1,    -1,
     108,    -1,    -1,   111,    -1,   113,    -1,    -1,    -1,    -1,
      -1,    -1,  1193,    -1,    -1,    -1,   124,    -1,    -1,    -1,
      -1,    -1,  1203,  1204,  1205,  1206,  1207,    -1,    -1,    -1,
      -1,  1212,  1213,    -1,  1215,    -1,   294,   145,    -1,   297,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1233,    -1,    -1,   313,   314,  1238,  1239,    -1,
      -1,    -1,    -1,    -1,     6,  1246,  1247,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1255,  1256,    -1,    -1,    -1,    -1,
    1261,  1262,    -1,    -1,    -1,    -1,  1267,  1268,    -1,    -1,
     348,   349,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     218,   219,   220,    -1,    -1,    -1,   374,    -1,    -1,    -1,
      -1,  1302,   230,    -1,    -1,    -1,   234,    -1,   236,   237,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1325,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1333,    -1,    -1,    -1,    -1,    -1,    -1,   267,
      -1,   269,   270,    -1,  1345,  1346,    -1,    -1,    -1,  1350,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1358,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   444,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1382,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1393,    -1,    -1,  1396,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,     6,    -1,    -1,    -1,   265,    -1,
      -1,    -1,    -1,    -1,  1425,    -1,    -1,  1428,  1429,  1430,
    1431,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1439,    -1,
      -1,  1442,    -1,  1444,    -1,   523,  1447,  1448,     6,    -1,
    1451,  1452,  1453,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     548,    -1,    -1,    -1,    -1,  1476,    -1,    -1,    -1,   557,
     558,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,    -1,
      -1,    -1,    -1,   265,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   590,    -1,    -1,    -1,    -1,   595,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,    -1,    -1,    -1,  1540,
     265,    -1,    -1,   621,    -1,    -1,    -1,    -1,    -1,    -1,
    1551,  1552,  1553,    -1,    -1,    -1,    -1,    -1,    -1,  1560,
      -1,  1562,    -1,    -1,    -1,    -1,    -1,    -1,  1569,    -1,
      -1,   649,   650,    -1,  1575,    -1,    -1,    -1,    -1,    -1,
      -1,  1582,  1583,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1593,  1594,  1595,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1604,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   690,  1614,    -1,   693,   694,    -1,    -1,    -1,
      -1,    -1,   700,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1635,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1643,  1644,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,    -1,
      -1,    -1,   750,   265,  1675,    -1,    -1,    -1,    -1,    -1,
      -1,  1682,    -1,    -1,    -1,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,    -1,    -1,    -1,   784,   265,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1725,  1726,  1727,     6,   806,    -1,
      -1,    -1,    -1,    -1,   812,    -1,   814,    -1,    -1,    -1,
      -1,  1742,    -1,    -1,    -1,    -1,  1747,  1748,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1760,
      -1,    -1,    -1,     6,    -1,    -1,  1767,  1768,  1769,    -1,
    1771,    -1,    -1,    -1,    -1,    -1,  1777,  1778,    -1,    -1,
      -1,    -1,   860,    -1,   862,    -1,    -1,    -1,    -1,    -1,
      -1,  1792,    -1,  1794,  1795,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1807,  1808,    -1,    -1,
    1811,    -1,    -1,  1814,    -1,    -1,    -1,  1818,    -1,    -1,
     898,    -1,    -1,    -1,    -1,    -1,    -1,  1828,    -1,    -1,
     908,    -1,    -1,   466,     6,    -1,    -1,  1838,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   923,    -1,    -1,    -1,    -1,
      -1,  1852,    -1,    -1,    -1,    -1,  1857,  1858,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1872,    -1,    -1,  1875,  1876,   954,    -1,  1879,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   966,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1900,
      -1,    -1,    -1,    -1,    -1,  1906,  1907,  1908,    -1,   987,
      -1,    -1,    -1,    -1,    -1,    -1,  1917,  1918,    -1,    -1,
      -1,    -1,    -1,  1924,  1925,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1936,    -1,    -1,    -1,    -1,
      -1,    -1,   575,    -1,  1945,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1957,  1958,    -1,    -1,
    1961,  1962,    -1,    -1,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,    -1,    -1,    -1,    -1,   265,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1997,  1998,    -1,   632,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,    -1,  2020,
      -1,    -1,   265,    -1,  2025,  2026,  2027,    -1,    -1,    -1,
      -1,  2032,    13,    14,    -1,  2036,    -1,    -1,    -1,    -1,
      -1,  1119,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2050,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2068,    -1,    -1,
    2071,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,    -1,
      -1,    -1,    -1,   265,    -1,  2096,    -1,    -1,    -1,    -1,
      -1,  2102,    -1,    -1,  2105,    -1,    -1,    -1,    28,    -1,
      30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2120,
      -1,  2122,    -1,    -1,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,     8,    -1,  2140,
     121,   122,   123,   124,    -1,    -1,    -1,    -1,   129,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,   139,  2160,
    2161,   142,   143,    -1,   145,   146,     8,   148,    -1,    -1,
      -1,    -1,    -1,    -1,  2175,    -1,    -1,    -1,    -1,  2180,
      -1,    -1,    -1,    -1,    -1,   166,    -1,    -1,    -1,  1267,
    1268,    -1,  2193,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2202,    -1,    -1,    -1,  2206,     8,    -1,    -1,    -1,
      -1,    -1,    -1,   194,   195,   196,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2227,    -1,    -1,    -1,
     150,  2232,    -1,    -1,   867,   868,   869,   870,   871,   872,
     873,   874,   875,   876,   877,   878,    -1,   880,   881,   882,
     883,    -1,   885,   886,   887,   888,  2257,  2258,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   901,    -1,
     903,    -1,  1350,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   914,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     271,    -1,    -1,    -1,    -1,   928,   929,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   937,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,    -1,   258,   259,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   269,
     270,  1429,    -1,  1431,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   285,   286,    -1,    -1,    -1,
      -1,    -1,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
      -1,    -1,    -1,    -1,   265,    -1,    -1,    -1,    -1,    -1,
      -1,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,  1052,
    1053,  1054,    -1,   265,    -1,  1058,  1059,    -1,    -1,  1062,
    1063,  1064,  1065,    -1,  1067,    -1,    -1,    -1,    -1,  1072,
      -1,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,    -1,
      -1,    -1,    -1,   265,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   397,    -1,    -1,
      -1,    -1,    -1,    -1,   404,   405,   406,    -1,    -1,    -1,
     410,   411,   412,   413,   414,   415,   416,  1575,   418,    -1,
      -1,    -1,    -1,   423,   424,    -1,    -1,   427,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,  1151,    -1,
    1153,    -1,    10,    11,    12,    -1,    -1,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    -1,
      -1,    -1,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    -1,    -1,    71,    72,    73,    74,    -1,    -1,    77,
      78,    79,    80,    -1,    82,    83,    84,    85,    -1,    -1,
      88,    -1,    -1,    -1,  1682,    -1,    -1,    -1,    96,    97,
      98,    99,    -1,   101,    -1,    -1,    -1,   105,    -1,    -1,
     108,    -1,    -1,   111,    -1,   113,    -1,    -1,    -1,    -1,
      -1,  1264,   120,    -1,    -1,    -1,   124,   125,   126,    -1,
      -1,   129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     138,    -1,   140,   141,    -1,   143,    -1,   145,    -1,    -1,
     148,    -1,     8,    -1,    -1,    -1,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,    -1,    -1,
      -1,   169,    -1,   603,    -1,   173,   174,    -1,    -1,  1767,
    1768,    -1,    -1,    -1,    13,    14,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   199,    -1,    -1,  1792,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   217,
     218,   219,   220,   221,   222,    -1,    -1,    -1,    -1,   227,
     228,   229,   230,   231,   232,   233,   234,    -1,   236,   237,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   254,   255,    -1,    -1,
      -1,    -1,  1405,   261,    -1,    -1,    -1,    -1,   266,    -1,
      -1,    -1,   270,    -1,    -1,   273,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,    -1,
      -1,    -1,   121,   122,   123,   124,    -1,    -1,    -1,    -1,
     129,    -1,    -1,    -1,    -1,    -1,  1449,    -1,    -1,   138,
     139,    -1,    -1,   142,   143,    -1,   145,   146,    -1,   148,
      -1,    -1,    -1,    13,    14,    -1,    -1,    -1,    -1,  1917,
    1918,    -1,    -1,    -1,    -1,    -1,    -1,   166,    -1,    -1,
    1483,  1484,  1485,  1486,  1487,  1488,  1489,    -1,    -1,    -1,
      -1,  1494,  1495,    -1,    -1,    -1,    -1,    -1,  1501,    -1,
      -1,    -1,    -1,    -1,    -1,   194,   195,   196,  1511,    -1,
      -1,    -1,  1515,    -1,  1962,  1518,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1529,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,
      -1,    -1,    -1,    -1,    -1,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,    -1,    -1,
      -1,   121,   122,   123,   124,    -1,    -1,  2025,  2026,   129,
      -1,    -1,   271,    -1,    -1,    -1,    -1,    -1,   138,   139,
      -1,    -1,   142,   143,    -1,   145,   146,  1600,   148,  1602,
      -1,    -1,  2050,  1606,    -1,  1608,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   166,    -1,    -1,    -1,
      -1,    -1,    -1,  2071,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1639,    -1,    -1,    -1,
      -1,    -1,   932,    -1,   194,   195,   196,    -1,    -1,    -1,
      -1,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,     3,
       4,     5,    -1,   265,    -1,   965,    10,    11,    12,   271,
      -1,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   271,    -1,    -1,    -1,    59,    60,    61,    62,    -1,
      -1,    -1,  2180,    67,    68,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    77,    78,    79,  1749,    -1,    -1,    83,
      84,    85,    -1,    -1,    88,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    96,    97,    -1,    99,    -1,    -1,    -1,    -1,
      -1,   105,    -1,    -1,   108,    -1,    -1,   111,    -1,   113,
      -1,    -1,    -1,    -1,    -1,    -1,   120,    -1,    -1,    -1,
     124,   125,   126,    -1,    -1,   129,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   138,    -1,   140,   141,    -1,   143,
      -1,   145,    -1,    -1,   148,    -1,    -1,    -1,    -1,    -1,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,    -1,    -1,    -1,   169,    -1,    -1,    -1,   173,
     174,    -1,    -1,    -1,    -1,  1848,    -1,    -1,  1851,    -1,
      -1,    -1,    -1,    -1,    -1,  1145,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   199,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   217,    -1,    -1,    -1,   221,   222,    -1,
      -1,    -1,    -1,   227,   228,   229,    -1,   231,   232,   233,
    1903,  1904,    -1,   237,    -1,    -1,    -1,  1910,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     254,   255,    -1,    -1,    -1,    -1,    -1,   261,    -1,    -1,
      -1,    -1,   266,    -1,    -1,    -1,   270,    -1,    -1,   273,
      -1,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,    -1,
      -1,  1251,    -1,   265,  1967,  1968,    -1,    -1,    -1,   271,
       3,     4,     5,   275,    -1,     8,    -1,    10,    11,    12,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    -1,  2018,    -1,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    -1,    -1,    71,    72,
      73,    74,    -1,    -1,    77,    78,    79,    80,    -1,    82,
      83,    84,    85,    -1,    -1,    88,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    96,    97,    98,    99,    -1,   101,    -1,
      -1,    -1,   105,    -1,    -1,   108,    -1,    -1,   111,    -1,
     113,    -1,    -1,    -1,    -1,    -1,    -1,   120,    -1,    -1,
      -1,   124,   125,   126,    -1,    -1,   129,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   138,    -1,   140,   141,    -1,
     143,    -1,   145,    -1,    -1,   148,  1406,  1407,    -1,    -1,
      -1,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,    -1,    -1,    -1,   169,    -1,    -1,    -1,
     173,   174,    -1,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,    -1,    -1,    -1,    -1,   265,   199,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     8,    -1,    -1,   217,   218,   219,   220,   221,   222,
      -1,    -1,    -1,    -1,   227,   228,   229,   230,   231,   232,
     233,   234,    -1,   236,   237,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   254,   255,  1513,    -1,    -1,    -1,    -1,   261,    -1,
      -1,    -1,  1522,   266,    -1,    -1,    -1,    -1,   271,    -1,
     273,    -1,    -1,  2246,     3,     4,     5,    -1,    -1,     8,
      -1,    10,    11,    12,    -1,    -1,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    -1,    -1,
      -1,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      -1,    -1,    71,    72,    73,    74,    -1,    -1,    77,    78,
      79,    80,    -1,    82,    83,    84,    85,    -1,    -1,    88,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    96,    97,    98,
      99,    -1,   101,    -1,    -1,    -1,   105,    -1,    -1,   108,
      -1,    -1,   111,    -1,   113,    -1,    -1,    -1,    -1,    -1,
      -1,   120,    -1,    -1,    -1,   124,   125,   126,    -1,    -1,
     129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,
      -1,   140,   141,    -1,   143,    -1,   145,    -1,    -1,   148,
      -1,  1681,    -1,    -1,    -1,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,    -1,    -1,    -1,
     169,    -1,    -1,    -1,   173,   174,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,    -1,
     199,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   217,   218,
     219,   220,   221,   222,    -1,    -1,    -1,    -1,   227,   228,
     229,   230,   231,   232,   233,   234,    -1,   236,   237,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   254,   255,    -1,    -1,    -1,
      -1,    -1,   261,     3,     4,     5,    -1,   266,    -1,    -1,
      10,    11,    12,    -1,   273,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    -1,    -1,    -1,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    -1,
      -1,    71,    72,    73,    74,    -1,    -1,    77,    78,    79,
      80,    -1,    82,    83,    84,    85,    -1,    -1,    88,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    96,    97,    98,    99,
      -1,   101,    -1,    -1,    -1,   105,    -1,    -1,   108,    -1,
      -1,   111,    -1,   113,    -1,    -1,    -1,    -1,    -1,    -1,
     120,    -1,    -1,    -1,   124,   125,   126,    -1,    -1,   129,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,    -1,
     140,   141,    -1,   143,    -1,   145,    -1,    -1,   148,    -1,
      -1,    -1,    -1,    -1,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,    -1,    -1,    -1,   169,
      -1,    -1,    -1,   173,   174,    -1,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,   199,
     267,    -1,   269,    -1,    -1,    -1,    -1,    -1,   275,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   217,   218,   219,
     220,   221,   222,    -1,    -1,    -1,    -1,   227,   228,   229,
     230,   231,   232,   233,   234,    -1,   236,   237,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   254,   255,    -1,    -1,    -1,    -1,
      -1,   261,    -1,    -1,    -1,    -1,   266,     3,     4,     5,
     270,     7,    -1,   273,    10,    11,    12,    -1,    -1,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    -1,    -1,    -1,    71,    72,    73,    74,    -1,
      -1,    -1,    -1,    -1,    80,    -1,    82,    83,    84,    85,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      96,    97,    98,    99,    -1,   101,    -1,    -1,    -1,   105,
       4,     5,   108,    -1,    -1,   111,    -1,   113,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   124,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,    -1,    -1,   145,
      -1,   265,    -1,   267,    -1,   269,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    -1,    -1,    -1,    -1,    63,
      64,    65,    66,    -1,    -1,    -1,    -1,    71,    72,    73,
      74,    -1,    -1,    -1,    -1,    -1,    80,    -1,    82,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    98,    -1,    -1,   101,    -1,    -1,
      -1,    -1,    -1,    -1,   210,    -1,    -1,    -1,    -1,    -1,
      -1,   217,   218,   219,   220,   221,    -1,    -1,    -1,    -1,
      -1,   227,   228,   229,   230,   231,   232,   233,   234,    -1,
     236,   237,    -1,   239,   240,   241,   242,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   254,   255,
      -1,    -1,    -1,    -1,    -1,   261,    -1,   263,   264,    -1,
     266,    -1,   268,     3,     4,    -1,   272,   273,     8,    -1,
      10,    11,    12,    -1,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   218,   219,   220,    -1,    -1,    59,
      60,    61,    62,    -1,    -1,    -1,   230,    67,    68,    -1,
     234,    -1,   236,   237,    -1,    -1,    -1,    77,    78,    79,
      -1,    -1,    -1,    83,    84,    85,    -1,    -1,    88,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    96,    97,    -1,    99,
      -1,    -1,    -1,    -1,    -1,   105,    -1,    -1,   108,    -1,
      -1,   111,    -1,   113,    -1,    -1,    -1,    -1,    -1,    -1,
     120,    -1,    -1,    -1,   124,   125,   126,    -1,    -1,   129,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,    -1,
     140,   141,    -1,   143,    -1,   145,    -1,    -1,   148,    -1,
      -1,    -1,    -1,    -1,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,    -1,    -1,    -1,   169,
      -1,    -1,    -1,   173,   174,    -1,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,   199,
     267,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   275,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   217,    -1,    -1,
      -1,   221,   222,    -1,    -1,    -1,    -1,   227,   228,   229,
      -1,   231,   232,   233,    -1,    -1,    -1,   237,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   254,   255,    -1,    -1,    -1,    -1,
      -1,   261,    -1,    -1,    -1,    -1,   266,     3,     4,     5,
      -1,   271,    -1,   273,    10,    11,    12,    -1,    -1,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    59,    60,    61,    62,    -1,    -1,    -1,
      -1,    67,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    77,    78,    79,    -1,    -1,    -1,    83,    84,    85,
      -1,    -1,    88,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      96,    97,    -1,    99,    -1,    -1,    -1,    -1,    -1,   105,
      -1,    -1,   108,    -1,    -1,   111,    -1,   113,    -1,    -1,
      -1,    -1,    -1,    -1,   120,    -1,    -1,    -1,   124,   125,
     126,    -1,    -1,   129,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   138,    -1,   140,   141,    -1,   143,    -1,   145,
      -1,    -1,   148,    -1,    -1,    -1,    -1,    -1,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
      -1,    -1,    -1,   169,    -1,    -1,    -1,   173,   174,    -1,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,    -1,    -1,
      -1,    -1,   265,   199,   267,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   275,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   217,    -1,    -1,    -1,   221,   222,    -1,    -1,    -1,
      -1,   227,   228,   229,    -1,   231,   232,   233,    -1,    -1,
      -1,   237,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   254,   255,
      -1,    -1,    -1,    -1,    -1,   261,    -1,    -1,    -1,    -1,
     266,     3,     4,    -1,   270,    -1,    -1,   273,    10,    11,
      12,    -1,    -1,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,    60,    61,
      62,    -1,    -1,    -1,    -1,    67,    68,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    77,    78,    79,    -1,    -1,
      -1,    83,    84,    85,    -1,    -1,    88,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    96,    97,    -1,    99,    -1,    -1,
      -1,    -1,    -1,   105,    -1,    -1,   108,    -1,    -1,   111,
      -1,   113,    -1,    -1,    -1,    -1,    -1,    -1,   120,    -1,
      -1,    -1,   124,   125,   126,    -1,    -1,   129,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   138,    -1,   140,   141,
      -1,   143,    -1,   145,    -1,    -1,   148,    -1,    -1,    -1,
      -1,    -1,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,    -1,    -1,    -1,   169,    -1,    -1,
      -1,   173,   174,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,    -1,    -1,    -1,    -1,   265,    -1,   199,    -1,    -1,
      -1,   271,    -1,    -1,    -1,   275,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   217,    -1,    -1,    -1,   221,
     222,    -1,    -1,    -1,    -1,   227,   228,   229,    -1,   231,
     232,   233,    -1,    -1,    -1,   237,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   254,   255,    -1,    -1,    -1,    -1,    -1,   261,
      -1,    -1,    -1,    -1,   266,     3,     4,    -1,   270,    -1,
      -1,   273,    10,    11,    12,    -1,    -1,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    59,    60,    61,    62,    -1,    -1,    -1,    -1,    67,
      68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,
      78,    79,    -1,    -1,    -1,    83,    84,    85,    -1,    -1,
      88,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    96,    97,
      -1,    99,    -1,    -1,    -1,    -1,    -1,   105,    -1,    -1,
     108,    -1,    -1,   111,    -1,   113,    -1,    -1,    -1,    -1,
      -1,    -1,   120,    -1,    -1,    -1,   124,   125,   126,    -1,
      -1,   129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     138,    -1,   140,   141,    -1,   143,    -1,   145,    -1,    -1,
     148,    -1,    -1,    -1,    -1,    -1,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,    -1,    -1,
      -1,   169,    -1,    -1,    -1,   173,   174,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,
      -1,   199,    -1,    -1,    -1,   271,    -1,    -1,    -1,   275,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   217,
      -1,    -1,    -1,   221,   222,    -1,    -1,    -1,    -1,   227,
     228,   229,    -1,   231,   232,   233,    -1,    -1,    -1,   237,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   254,   255,    -1,    -1,
      -1,    -1,    -1,   261,    -1,    -1,    -1,    -1,   266,     3,
       4,    -1,   270,    -1,    -1,   273,    10,    11,    12,    -1,
      -1,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    59,    60,    61,    62,    -1,
      -1,    -1,    -1,    67,    68,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    77,    78,    79,    -1,    -1,    -1,    83,
      84,    85,    -1,    -1,    88,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    96,    97,    -1,    99,    -1,    -1,    -1,    -1,
      -1,   105,    -1,    -1,   108,    -1,    -1,   111,    -1,   113,
      -1,    -1,    -1,    -1,    -1,    -1,   120,    -1,    -1,    -1,
     124,   125,   126,    -1,    -1,   129,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   138,    -1,   140,   141,    -1,   143,
      -1,   145,    -1,    -1,   148,    -1,    -1,    -1,    -1,    -1,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,    -1,    -1,    -1,   169,    -1,    -1,    -1,   173,
     174,    -1,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
      -1,    -1,    -1,    -1,   265,   199,   267,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   275,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   217,    -1,    -1,    -1,   221,   222,    -1,
      -1,    -1,    -1,   227,   228,   229,    -1,   231,   232,   233,
      -1,    -1,    -1,   237,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     254,   255,    -1,    -1,    -1,    -1,    -1,   261,    -1,    -1,
      -1,    -1,   266,     3,     4,    -1,   270,    -1,    -1,   273,
      10,    11,    12,    -1,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,
      60,    61,    62,    -1,    -1,    -1,    -1,    67,    68,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,    78,    79,
      -1,    -1,    -1,    83,    84,    85,    -1,    -1,    88,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    96,    97,    -1,    99,
      -1,    -1,    -1,    -1,    -1,   105,    -1,    -1,   108,    -1,
      -1,   111,    -1,   113,    -1,    -1,    -1,    -1,    -1,    -1,
     120,    -1,    -1,    -1,   124,   125,   126,    -1,    -1,   129,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,    -1,
     140,   141,    -1,   143,    -1,   145,    -1,    -1,   148,    -1,
      -1,    -1,    -1,    -1,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,    -1,    -1,    -1,   169,
      -1,    -1,    -1,   173,   174,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,    -1,    -1,    -1,    -1,   265,    -1,   199,
      -1,    -1,    -1,   271,    -1,    -1,    -1,   275,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   217,    -1,    -1,
      -1,   221,   222,    -1,    -1,    -1,    -1,   227,   228,   229,
      -1,   231,   232,   233,    -1,    -1,    -1,   237,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   254,   255,    -1,    -1,    -1,    -1,
      -1,   261,    -1,    -1,    -1,    -1,   266,     3,     4,    -1,
      -1,   271,    -1,   273,    10,    11,    12,    -1,    -1,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    59,    60,    61,    62,    -1,    -1,    -1,
      -1,    67,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    77,    78,    79,    -1,    -1,    -1,    83,    84,    85,
      -1,    -1,    88,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      96,    97,    -1,    99,    -1,    -1,    -1,    -1,    -1,   105,
      -1,    -1,   108,    -1,    -1,   111,    -1,   113,    -1,    -1,
      -1,    -1,    -1,    -1,   120,    -1,    -1,    -1,   124,   125,
     126,    -1,    -1,   129,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   138,    -1,   140,   141,    -1,   143,    -1,   145,
      -1,    -1,   148,    -1,    -1,    -1,    -1,    -1,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
      -1,    -1,    -1,   169,    -1,    -1,    -1,   173,   174,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,    -1,    -1,    -1,
      -1,   265,    -1,   199,    -1,    -1,    -1,   271,    -1,    -1,
      -1,   275,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   217,    -1,    -1,    -1,   221,   222,    -1,    -1,    -1,
      -1,   227,   228,   229,    -1,   231,   232,   233,    -1,    -1,
      -1,   237,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   254,   255,
      -1,    -1,    -1,    -1,    -1,   261,    -1,    -1,    -1,    -1,
     266,     3,     4,    -1,   270,    -1,    -1,   273,    10,    11,
      12,    -1,    -1,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,    60,    61,
      62,    -1,    -1,    -1,    -1,    67,    68,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    77,    78,    79,    -1,    -1,
      -1,    83,    84,    85,    -1,    -1,    88,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    96,    97,    -1,    99,    -1,    -1,
      -1,    -1,    -1,   105,    -1,    -1,   108,    -1,    -1,   111,
      -1,   113,    -1,    -1,    -1,    -1,    -1,    -1,   120,    -1,
      -1,    -1,   124,   125,   126,    -1,    -1,   129,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   138,    -1,   140,   141,
      -1,   143,    -1,   145,    -1,    -1,   148,    -1,    -1,    -1,
      -1,    -1,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,    -1,    -1,    -1,   169,    -1,    -1,
      -1,   173,   174,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,    -1,    -1,    -1,    -1,   265,    -1,   199,    -1,    -1,
      -1,   271,    -1,    -1,    -1,   275,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   217,    -1,    -1,    -1,   221,
     222,    -1,    -1,    -1,    -1,   227,   228,   229,    -1,   231,
     232,   233,    -1,    -1,    -1,   237,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   254,   255,    -1,    -1,    -1,    -1,    -1,   261,
      -1,    -1,    -1,    -1,   266,     3,     4,    -1,   270,    -1,
      -1,   273,    10,    11,    12,    -1,    -1,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    59,    60,    61,    62,    -1,    -1,    -1,    -1,    67,
      68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,
      78,    79,    -1,    -1,    -1,    83,    84,    85,    -1,    -1,
      88,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    96,    97,
      -1,    99,    -1,    -1,    -1,    -1,    -1,   105,    -1,    -1,
     108,    -1,    -1,   111,    -1,   113,    -1,    -1,    -1,    -1,
      -1,    -1,   120,    -1,    -1,    -1,   124,   125,   126,    -1,
      -1,   129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     138,    -1,   140,   141,    -1,   143,    -1,   145,    -1,    -1,
     148,    -1,    -1,    -1,    -1,    -1,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,    -1,    -1,
      -1,   169,    -1,    -1,    -1,   173,   174,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,
      -1,   199,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   275,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   217,
      -1,    -1,    -1,   221,   222,    -1,    -1,    -1,    -1,   227,
     228,   229,    -1,   231,   232,   233,    -1,    -1,    -1,   237,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   254,   255,    -1,    -1,
      -1,    -1,    -1,   261,    -1,    -1,    -1,    -1,   266,     3,
       4,    -1,   270,    -1,     8,   273,    10,    11,    12,    -1,
      -1,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    59,    60,    61,    62,    -1,
      -1,    -1,    -1,    67,    68,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    77,    78,    79,    -1,    -1,    -1,    83,
      84,    85,    -1,    -1,    88,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    96,    97,    -1,    99,    -1,    -1,    -1,    -1,
      -1,   105,    -1,    -1,   108,    -1,    -1,   111,    -1,   113,
      -1,    -1,    -1,    -1,    -1,    -1,   120,    -1,    -1,    -1,
     124,   125,   126,    -1,    -1,   129,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   138,    -1,   140,   141,    -1,   143,
      -1,   145,    -1,    -1,   148,    -1,    -1,    -1,    -1,    -1,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,    -1,    -1,    -1,   169,    -1,    -1,    -1,   173,
     174,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,    -1,
      -1,    -1,    -1,   265,    -1,   199,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   275,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   217,    -1,    -1,    -1,   221,   222,    -1,
      -1,    -1,    -1,   227,   228,   229,    -1,   231,   232,   233,
      -1,    -1,    -1,   237,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     254,   255,    -1,    -1,    -1,    -1,    -1,   261,     3,     4,
      -1,    -1,   266,    -1,    -1,    10,    11,    12,    -1,   273,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    59,    60,    61,    62,    -1,    -1,
      -1,    -1,    67,    68,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    77,    78,    79,    -1,    -1,    -1,    83,    84,
      85,    -1,    -1,    88,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    96,    97,    -1,    99,    -1,    -1,    -1,    -1,    -1,
     105,    -1,    -1,   108,    -1,    -1,   111,    -1,   113,    -1,
      -1,    -1,    -1,    -1,    -1,   120,    -1,    -1,    -1,   124,
     125,   126,    -1,    -1,   129,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   138,    -1,   140,   141,    -1,   143,    -1,
     145,    -1,    -1,   148,    -1,    -1,    -1,    -1,    -1,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,    -1,    -1,    -1,   169,    -1,    -1,    -1,   173,   174,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,    -1,    -1,
      -1,    -1,   265,    -1,   199,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   275,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   217,    -1,    -1,    -1,   221,   222,    -1,    -1,
      -1,    -1,   227,   228,   229,    -1,   231,   232,   233,    -1,
      -1,    -1,   237,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   254,
     255,    -1,    -1,    -1,    -1,    -1,   261,    -1,    -1,    -1,
      -1,   266,     3,     4,    -1,    -1,   271,    -1,   273,    10,
      11,    12,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,    60,
      61,    62,    -1,    -1,    -1,    -1,    67,    68,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    77,    78,    79,    -1,
      -1,    -1,    83,    84,    85,    -1,    -1,    88,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    96,    97,    -1,    99,    -1,
      -1,    -1,    -1,    -1,   105,    -1,    -1,   108,    -1,    -1,
     111,    -1,   113,    -1,    -1,    -1,    -1,    -1,    -1,   120,
      -1,    -1,    -1,   124,   125,   126,    -1,    -1,   129,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,    -1,   140,
     141,    -1,   143,    -1,   145,    -1,    -1,   148,    -1,    -1,
      -1,    -1,    -1,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,    -1,    -1,    -1,   169,    -1,
      -1,    -1,   173,   174,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,    -1,    -1,    -1,    -1,   265,    -1,   199,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   275,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   217,    -1,    -1,    -1,
     221,   222,    -1,    -1,    -1,    -1,   227,   228,   229,    -1,
     231,   232,   233,    -1,    -1,    -1,   237,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   254,   255,    -1,    -1,    -1,    -1,    -1,
     261,     3,     4,     5,    -1,   266,    -1,    -1,    10,    11,
      12,    -1,   273,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    -1,    -1,    -1,    71,
      72,    73,    74,    -1,    -1,    -1,    -1,    -1,    80,    -1,
      82,    83,    84,    85,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    96,    97,    98,    99,    -1,   101,
       3,     4,     5,    -1,    -1,    -1,    -1,    10,    11,    12,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    -1,    -1,    -1,    71,    72,
      73,    74,    -1,    -1,    -1,    -1,    -1,    80,    -1,    82,
      83,    84,    85,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    96,    97,    98,    99,    -1,   101,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   217,   218,   219,   220,   221,
      -1,    -1,    -1,    -1,    -1,   227,   228,   229,   230,   231,
     232,   233,   234,    -1,   236,   237,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   254,   255,    -1,    -1,    -1,    -1,    -1,   261,
      -1,    -1,    -1,    -1,   266,    -1,    -1,    -1,   270,    -1,
      -1,   273,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
      -1,    -1,    -1,    -1,   265,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   275,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   217,   218,   219,   220,   221,    -1,
      -1,    -1,    -1,    -1,   227,   228,   229,   230,   231,   232,
     233,   234,    -1,   236,   237,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   254,   255,    -1,    -1,    -1,    -1,    -1,   261,    -1,
      -1,    -1,    -1,   266,     3,     4,     5,   270,    -1,    -1,
     273,    10,    11,    12,    -1,    -1,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    -1,
      -1,    -1,    71,    72,    73,    74,    -1,    -1,    -1,    -1,
      -1,    80,    -1,    82,    83,    84,    85,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    96,    97,    98,
      99,    -1,   101,     3,     4,     5,    -1,    -1,    -1,    -1,
      10,    11,    12,    -1,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    -1,    -1,
      -1,    71,    72,    73,    74,    -1,    -1,    -1,    -1,    -1,
      80,    -1,    82,    83,    84,    85,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    96,    97,    98,    99,
      -1,   101,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   217,   218,
     219,   220,   221,    -1,    -1,    -1,    -1,    -1,   227,   228,
     229,   230,   231,   232,   233,   234,    -1,   236,   237,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   254,   255,    -1,    -1,    -1,
      -1,    -1,   261,    -1,    -1,    -1,    -1,   266,    -1,    -1,
      -1,   270,    -1,    -1,   273,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,    -1,    -1,    -1,    -1,   265,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   275,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   217,   218,   219,
     220,   221,    -1,    -1,    -1,    -1,    -1,   227,   228,   229,
     230,   231,   232,   233,   234,    -1,   236,   237,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   254,   255,    -1,    -1,    -1,    -1,
      -1,   261,     3,     4,    -1,    -1,   266,    -1,    -1,    10,
      11,    12,    -1,   273,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,    60,
      61,    62,    -1,    -1,    -1,    -1,    67,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    83,    84,    85,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,    -1,    96,    97,    -1,    99,    10,
      11,    12,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,    60,
      61,    62,    -1,    -1,    -1,    -1,    67,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    83,    84,    85,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    96,    97,    -1,    99,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,    -1,    -1,    -1,
      -1,   265,    -1,    -1,    -1,    -1,   217,    -1,    -1,    -1,
     221,   275,    -1,    -1,    -1,    -1,   227,   228,   229,    -1,
     231,   232,   233,    -1,    -1,    -1,   237,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   254,   255,    -1,    -1,    -1,    -1,    -1,
     261,    -1,    -1,    -1,    -1,   266,    -1,    -1,    -1,   270,
      -1,    -1,   273,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,    -1,    -1,    -1,    -1,   265,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   275,   217,    -1,    -1,    -1,
     221,    -1,    -1,    -1,    -1,    -1,   227,   228,   229,    -1,
     231,   232,   233,    -1,    -1,    -1,   237,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   254,   255,    -1,    -1,    -1,    -1,    -1,
     261,    -1,    -1,    -1,    -1,   266,     3,     4,    -1,   270,
      -1,     8,   273,    10,    11,    12,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    59,    60,    61,    62,    -1,    -1,    -1,    -1,
      67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    83,    84,    85,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,    -1,    96,
      97,    -1,    99,    10,    11,    12,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    59,    60,    61,    62,    -1,    -1,    -1,    -1,
      67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    83,    84,    85,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    96,
      97,    -1,    99,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,    -1,    -1,    -1,    -1,   265,    -1,    -1,    -1,    -1,
     217,    -1,    -1,    -1,   221,   275,    -1,    -1,    -1,    -1,
     227,   228,   229,    -1,   231,   232,   233,    -1,    -1,    -1,
     237,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   254,   255,    -1,
      -1,    -1,    -1,    -1,   261,    -1,    -1,    -1,    -1,   266,
      -1,    -1,    -1,    -1,    -1,    -1,   273,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   275,
     217,    -1,    -1,    -1,   221,    -1,    -1,    -1,    -1,    -1,
     227,   228,   229,    -1,   231,   232,   233,    -1,    -1,    -1,
     237,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   254,   255,    -1,
      -1,    -1,    -1,    -1,   261,     3,     4,    -1,     6,   266,
     267,    -1,    10,    11,    12,    -1,   273,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    59,    60,    61,    62,    -1,    -1,    -1,    -1,    67,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    83,    84,    85,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    96,    97,
      -1,    99,     3,     4,    -1,     6,    -1,    -1,    -1,    10,
      11,    12,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,    60,
      61,    62,    -1,    -1,    -1,    -1,    67,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    83,    84,    85,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    96,    97,    -1,    99,    -1,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,    -1,   217,
      -1,    -1,   265,   221,    -1,    -1,    -1,    -1,    -1,   227,
     228,   229,   275,   231,   232,   233,    -1,    -1,    -1,   237,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   254,   255,    -1,    -1,
      -1,    -1,    -1,   261,    -1,    -1,    -1,    -1,   266,    -1,
      -1,    -1,    -1,    -1,    -1,   273,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   275,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   217,    -1,    -1,    -1,
     221,    -1,    -1,    -1,    -1,    -1,   227,   228,   229,    -1,
     231,   232,   233,    -1,    -1,    -1,   237,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   254,   255,    -1,    -1,    -1,    -1,    -1,
     261,     3,     4,    -1,     6,   266,    -1,    -1,    10,    11,
      12,    -1,   273,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,    60,    61,
      62,    -1,    -1,    -1,    -1,    67,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    83,    84,    85,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     3,     4,    -1,    96,    97,    -1,    99,    10,    11,
      12,    -1,    -1,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,    60,    61,
      62,    -1,    -1,    -1,    -1,    67,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    83,    84,    85,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    96,    97,    -1,    99,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,    -1,    -1,    -1,    -1,
     265,    -1,    -1,    -1,    -1,   217,    -1,    -1,    -1,   221,
     275,    -1,    -1,    -1,    -1,   227,   228,   229,    -1,   231,
     232,   233,    -1,    -1,    -1,   237,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   254,   255,    -1,    -1,    -1,    -1,    -1,   261,
      -1,    -1,    -1,    -1,   266,    -1,    -1,    -1,    -1,    -1,
      -1,   273,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
      -1,    -1,    -1,    -1,   265,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   275,   217,    -1,    -1,    -1,   221,
      -1,    -1,    -1,    -1,    -1,   227,   228,   229,    -1,   231,
     232,   233,    -1,    -1,    -1,   237,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   254,   255,    -1,    -1,    -1,    -1,    -1,   261,
       3,     4,    -1,    -1,   266,   267,    -1,    10,    11,    12,
      -1,   273,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    59,    60,    61,    62,
      -1,    -1,    -1,    -1,    67,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      83,    84,    85,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,    -1,    96,    97,    -1,    99,    10,    11,    12,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    59,    60,    61,    62,
      -1,    -1,    -1,    -1,    67,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      83,    84,    85,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    96,    97,    -1,    99,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,
      -1,    -1,    -1,    -1,   217,    -1,    -1,    -1,   221,   275,
      -1,    -1,    -1,    -1,   227,   228,   229,    -1,   231,   232,
     233,    -1,    -1,    -1,   237,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   254,   255,    -1,    -1,    -1,    -1,    -1,   261,    -1,
      -1,    -1,    -1,   266,   267,    -1,    -1,    -1,    -1,    -1,
     273,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,    -1,
      -1,    -1,    -1,   265,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   275,   217,    -1,    -1,    -1,   221,    -1,
      -1,    -1,    -1,    -1,   227,   228,   229,    -1,   231,   232,
     233,    -1,    -1,    -1,   237,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   254,   255,    -1,    -1,    -1,    -1,    -1,   261,    -1,
      -1,    -1,    -1,   266,     3,     4,    -1,   270,    -1,    -1,
     273,    10,    11,    12,    -1,    -1,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     4,     5,    -1,    -1,    -1,
      59,    60,    61,    62,    -1,    -1,    -1,    -1,    67,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    83,    84,    85,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    96,    97,    -1,
      99,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      -1,    -1,    -1,    -1,    63,    64,    65,    66,    -1,    -1,
      -1,    -1,    71,    72,    73,    74,    -1,    -1,    -1,    -1,
      -1,    80,    -1,    82,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    98,
      -1,    -1,   101,    -1,    -1,    -1,   105,    -1,    -1,   108,
      -1,    -1,   111,    -1,   113,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   124,    -1,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,    -1,   145,    13,    14,   265,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   275,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   217,    -1,
      -1,    -1,   221,    -1,    -1,    -1,    -1,    -1,   227,   228,
     229,    -1,   231,   232,   233,    -1,    -1,    -1,   237,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   254,   255,    -1,    -1,    13,
      14,    -1,   261,    -1,    -1,    -1,    -1,   266,    -1,   218,
     219,   220,    -1,    -1,   273,    -1,    -1,    -1,    -1,    -1,
      -1,   230,    -1,    -1,    -1,   234,    -1,   236,   237,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,    -1,    -1,    -1,   121,   122,   123,   124,    -1,
      -1,    -1,    -1,   129,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   270,   138,   139,    -1,    -1,   142,   143,    -1,   145,
     146,    -1,   148,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     166,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,    -1,    13,    14,   121,   122,   123,
     124,    -1,    -1,    -1,    -1,   129,    -1,    -1,   194,   195,
     196,    -1,    -1,    -1,   138,   139,    -1,    -1,   142,   143,
      -1,   145,   146,    -1,   148,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   166,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    13,    14,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     194,   195,   196,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   271,    -1,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
      -1,    -1,    -1,   121,   122,   123,   124,    -1,    -1,    -1,
      -1,   129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     138,   139,    -1,    -1,   142,   143,    -1,   145,   146,    -1,
     148,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   271,   166,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,    -1,    13,    14,   121,   122,   123,   124,    -1,
      -1,    -1,    -1,   129,    -1,    -1,   194,   195,   196,    -1,
      -1,    -1,   138,   139,    -1,    -1,   142,   143,    -1,   145,
     146,    -1,   148,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     166,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    13,    14,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   194,   195,
     196,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   271,    -1,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,    -1,    -1,
      -1,   121,   122,   123,   124,    -1,    -1,    -1,    -1,   129,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,   139,
      -1,    -1,   142,   143,    -1,   145,   146,    -1,   148,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   271,   166,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
      -1,    13,    14,   121,   122,   123,   124,    -1,    -1,    -1,
      -1,   129,    -1,    -1,   194,   195,   196,    -1,    -1,    -1,
     138,   139,    -1,    -1,   142,   143,    -1,   145,   146,    -1,
     148,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   166,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    13,    14,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   194,   195,   196,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   271,    -1,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,    -1,    -1,    -1,   121,
     122,   123,   124,    -1,    -1,    -1,    -1,   129,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   138,   139,    -1,    -1,
     142,   143,    -1,   145,   146,    -1,   148,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   271,   166,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,    -1,    13,
      14,   121,   122,   123,   124,    -1,    -1,    -1,    -1,   129,
      -1,    -1,   194,   195,   196,    -1,    -1,    -1,   138,   139,
      -1,    -1,   142,   143,    -1,   145,   146,    -1,   148,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   166,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   194,   195,   196,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   271,
      -1,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,    -1,    -1,    -1,   121,   122,   123,
     124,    -1,    -1,    -1,    -1,   129,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   138,   139,    -1,    -1,   142,   143,
      -1,   145,   146,    -1,   148,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   271,   166,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,    -1,    13,    14,   121,
     122,   123,   124,    -1,    -1,    -1,    -1,   129,    -1,    -1,
     194,   195,   196,    -1,    -1,    -1,   138,   139,    -1,    -1,
     142,   143,    -1,   145,   146,    -1,   148,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   166,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    13,
      14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   194,   195,   196,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   271,    -1,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,    -1,    -1,    -1,   121,   122,   123,   124,    -1,
      -1,    -1,    -1,   129,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   138,   139,    -1,    -1,   142,   143,    -1,   145,
     146,    -1,   148,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   271,
     166,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,    -1,    13,    14,   121,   122,   123,
     124,    -1,    -1,    -1,    -1,   129,    -1,    -1,   194,   195,
     196,    -1,    -1,    -1,   138,   139,    -1,    -1,   142,   143,
      -1,   145,   146,    -1,   148,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   166,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    13,    14,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     194,   195,   196,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   271,    -1,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
      -1,    -1,    -1,   121,   122,   123,   124,    -1,    -1,    -1,
      -1,   129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     138,   139,    -1,    -1,   142,   143,    -1,   145,   146,    -1,
     148,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   271,   166,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,    -1,    13,    14,   121,   122,   123,   124,    -1,
      -1,    -1,    -1,   129,    -1,    -1,   194,   195,   196,    -1,
      -1,    -1,   138,   139,    -1,    -1,   142,   143,    -1,   145,
     146,    -1,   148,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     166,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,    -1,
      -1,    -1,    -1,   265,    -1,    -1,    -1,    -1,   194,   195,
     196,    -1,    -1,   275,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   271,    -1,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,    -1,    -1,
      -1,   121,   122,   123,   124,    -1,    -1,    -1,    -1,   129,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,   139,
      -1,    -1,   142,   143,    -1,   145,   146,    -1,   148,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   271,   166,    -1,    -1,    -1,
       0,     1,    -1,    -1,     4,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    13,    14,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   194,   195,   196,    -1,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,    -1,    47,    48,    49,
     265,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     275,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    68,    69,
      70,    -1,    -1,    -1,    -1,    75,    76,    -1,    -1,    -1,
      -1,    81,    -1,    -1,    -1,    -1,    86,    87,    88,    89,
      90,    91,    92,    -1,    94,    95,    -1,    97,    -1,    -1,
      -1,   271,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,    -1,    -1,
     120,   121,   122,   123,   124,    -1,    -1,   127,    -1,   129,
      -1,   131,   132,    -1,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,    -1,    -1,
     150,   151,   152,    -1,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,    -1,
      -1,    -1,   182,   183,   184,    -1,    -1,    -1,   188,    -1,
      -1,    -1,    -1,   193,   194,   195,   196,    -1,    -1,   199,
      -1,   201,    -1,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,    -1,     4,    -1,
      -1,    -1,    -1,   223,   224,   225,   226,    13,    14,    -1,
      -1,    -1,    -1,    -1,    -1,   235,    -1,   237,   238,    -1,
      -1,    -1,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
      -1,    47,    48,    49,   265,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   275,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    68,    69,    70,    -1,    -1,    -1,    -1,    75,
      76,    -1,    -1,    -1,    -1,    81,    -1,    -1,    -1,    -1,
      86,    87,    88,    89,    90,    91,    92,    -1,    94,    95,
      -1,    97,    -1,    -1,    -1,    -1,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,    -1,    -1,   120,   121,   122,   123,   124,    -1,
      -1,   127,    -1,   129,    -1,   131,   132,    -1,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,    -1,    -1,   150,   151,   152,    -1,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,    -1,    -1,    -1,   182,   183,   184,    -1,
      -1,    -1,   188,    -1,    -1,    -1,    -1,   193,   194,   195,
     196,     4,     5,   199,    -1,   201,    -1,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,    -1,    -1,    -1,    -1,    -1,    -1,   223,   224,   225,
     226,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   235,
      -1,   237,   238,    -1,    -1,    -1,    -1,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    -1,    -1,    -1,    -1,
      63,    64,    65,    66,    -1,     4,     5,    -1,    71,    72,
      73,    74,    -1,    -1,    -1,    -1,    -1,    80,    -1,    82,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    98,    -1,    -1,   101,    -1,
      -1,    -1,   105,    -1,    -1,   108,    -1,    -1,   111,    -1,
     113,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      -1,   124,    -1,    -1,    63,    64,    65,    66,     5,    -1,
      -1,    -1,    71,    72,    73,    74,    -1,    -1,    -1,    -1,
      -1,    80,   145,    82,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    13,    14,    98,
      -1,    -1,   101,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    -1,    -1,    -1,    -1,    63,    64,    65,    66,
      -1,    -1,    -1,    -1,    71,    72,    73,    74,    -1,    -1,
      -1,    -1,    -1,    80,    -1,    82,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   218,   219,   220,    -1,    -1,
      -1,    98,    -1,    -1,   101,    -1,    -1,   230,    -1,    -1,
      -1,   234,    -1,   236,   237,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,    -1,    -1,    -1,   121,   122,   123,   124,    13,
      14,    -1,    -1,   129,    -1,    -1,    -1,    -1,    -1,   218,
     219,   220,   138,   139,    -1,    -1,   142,   143,    -1,   145,
     146,   230,   148,    -1,    -1,   234,   152,   236,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     166,    -1,    -1,    -1,   170,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,    -1,    -1,    -1,    -1,   265,   194,   195,
     196,   218,   219,   220,    -1,    -1,    -1,   275,    -1,    -1,
      -1,    -1,    -1,   230,    -1,    -1,    -1,   234,    -1,   236,
      -1,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,    -1,    -1,    -1,   121,   122,   123,
     124,    -1,    -1,    -1,    -1,   129,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   138,   139,    -1,    -1,   142,   143,
      -1,   145,   146,    -1,   148,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   166,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,    -1,    -1,    -1,    -1,   265,    -1,    -1,    -1,    -1,
     194,   195,   196,    -1,    -1,   275,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   275,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,    -1,    -1,    -1,
      -1,   265,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   275,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
      -1,    -1,    -1,    -1,   265,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   275,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,    -1,    -1,    -1,    -1,   265,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   275,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,    -1,    -1,    -1,    -1,
     265,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     275,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,    -1,
      -1,    -1,    -1,   265,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   275,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,    -1,    -1,    -1,    -1,   265,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   275,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   275,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,    -1,    -1,
      -1,    -1,   265,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   275,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,    -1,    -1,    -1,    -1,   265,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   275,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   275,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,    -1,    -1,    -1,
      -1,   265,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   275,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
      -1,    -1,    -1,    -1,   265,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   275,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,    -1,    -1,    -1,    -1,   265,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   275,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,    -1,    -1,    -1,    -1,
     265,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     275,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,    -1,
      -1,    -1,    -1,   265,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   275,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,    -1,    -1,    -1,    -1,   265,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   275,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,
      -1,    -1,    -1,    -1,    -1,   271,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,    -1,
      -1,    -1,    -1,    -1,   271,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,    -1,    -1,    -1,    -1,   265,    -1,    -1,
      -1,    -1,    -1,   271,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,    -1,    -1,    -1,    -1,   265,    -1,    -1,    -1,
      -1,    -1,   271,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,    -1,    -1,    -1,    -1,   265,    -1,    -1,    -1,    -1,
      -1,   271,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
      -1,    -1,    -1,    -1,   265,    -1,    -1,    -1,    -1,    -1,
     271,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,    -1,
      -1,    -1,    -1,   265,    -1,    -1,    -1,    -1,    -1,   271,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,    -1,    -1,
      -1,    -1,   265,    -1,    -1,    -1,    -1,    -1,   271,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,    -1,    -1,    -1,
      -1,   265,    -1,    -1,    -1,    -1,    -1,   271,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,    -1,    -1,    -1,    -1,
     265,    -1,    -1,    -1,    -1,    -1,   271,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,
      -1,    -1,    -1,    -1,    -1,   271,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,    -1,
      -1,    -1,    -1,    -1,   271,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,    -1,    -1,    -1,    -1,   265,    -1,    -1,
      -1,    -1,    -1,   271,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,    -1,    -1,    -1,    -1,   265,    -1,    -1,    -1,
      -1,    -1,   271,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,    -1,    -1,    -1,    -1,   265,    -1,    -1,    -1,    -1,
      -1,   271,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
      -1,    -1,    -1,    -1,   265,    -1,    -1,    -1,    -1,    -1,
     271,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,    -1,
      -1,    -1,    -1,   265,    -1,    -1,    -1,    -1,    -1,   271,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,    -1,    -1,
      -1,    -1,   265,    -1,    -1,    -1,    -1,    -1,   271,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,    -1,    -1,    -1,
      -1,   265,    -1,    -1,    -1,    -1,    -1,   271,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,    -1,    -1,    -1,    -1,
     265,    -1,    -1,    -1,    -1,    -1,   271,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,
      -1,    -1,    -1,    -1,    -1,   271,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,    -1,
      -1,    -1,    -1,    -1,   271,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,    -1,    -1,    -1,    -1,   265,    -1,    -1,
      -1,    -1,    -1,   271,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,    -1,    -1,    -1,    -1,   265,    -1,    -1,    -1,
      -1,    -1,   271,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,    -1,    -1,    -1,    -1,   265,    -1,    -1,    -1,    -1,
      -1,   271,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
      -1,    -1,    -1,    -1,   265,    -1,    -1,    -1,    -1,    -1,
     271,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,    -1,
      -1,    -1,    -1,   265,    -1,    -1,    -1,    -1,    -1,   271,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,    -1,    -1,
      -1,    -1,   265,    -1,    -1,    -1,    -1,    -1,   271,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,    -1,    -1,    -1,
      -1,   265,    -1,    -1,    -1,    -1,    -1,   271,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,    -1,    -1,    -1,    -1,
     265,    -1,    -1,    -1,    -1,    -1,   271,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,
      -1,    -1,    -1,    -1,    -1,   271,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,    -1,
      -1,    -1,    -1,    -1,   271,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,    -1,    -1,    -1,    -1,   265,    -1,    -1,
      -1,    -1,    -1,   271,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,    -1,    -1,    -1,    -1,   265,    -1,    -1,    -1,
      -1,    -1,   271,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,    -1,    -1,    -1,    -1,   265,    -1,    -1,    -1,    -1,
      -1,   271,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
      -1,    -1,    -1,    -1,   265,    -1,    -1,    -1,    -1,    -1,
     271,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,    -1,
      -1,    -1,    -1,   265,    -1,    -1,    -1,    -1,    -1,   271,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,    -1,    -1,
      -1,    -1,   265,    -1,    -1,    -1,    -1,    -1,   271,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,    -1,    -1,    -1,
      -1,   265,    -1,    -1,    -1,    -1,    -1,   271,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,    -1,    -1,    -1,    -1,
     265,    -1,    -1,    -1,    -1,    -1,   271,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,
      -1,    -1,    -1,    -1,    -1,   271,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,    -1,
      -1,    -1,    -1,    -1,   271,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,    -1,    -1,    -1,    -1,   265,    -1,    -1,
      -1,    -1,   270,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,    -1,    -1,    -1,    -1,   265,    -1,    -1,    -1,    -1,
     270,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,    -1,
      -1,    -1,    -1,   265,    -1,    -1,    -1,    -1,   270,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,    -1,    -1,    -1,
      -1,   265,    -1,    -1,    -1,   269,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,    -1,
      -1,    -1,   269,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,    -1,    -1,    -1,    -1,   265,    -1,    -1,    -1,   269,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,    -1,    -1,
      -1,    -1,   265,    -1,    -1,    -1,   269,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,
      -1,    -1,    -1,   269,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,    -1,    -1,    -1,    -1,   265,    -1,    -1,    -1,
     269,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,    -1,
      -1,    -1,    -1,   265,    -1,    -1,    -1,   269,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,    -1,    -1,    -1,    -1,
     265,    -1,    -1,    -1,   269,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,    -1,    -1,    -1,    -1,   265,    -1,    -1,
      -1,   269,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
      -1,    -1,    -1,    -1,   265,    -1,    -1,    -1,   269,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,    -1,    -1,    -1,
      -1,   265,    -1,    -1,    -1,   269,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,    -1,
      -1,    -1,   269,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,    -1,    -1,    -1,    -1,   265,    -1,    -1,    -1,   269,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,    -1,    -1,
      -1,    -1,   265,    -1,    -1,    -1,   269,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,
      -1,    -1,    -1,   269,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,    -1,    -1,    -1,    -1,   265,    -1,   267,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,    -1,    -1,    -1,
      -1,   265,    -1,   267,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,    -1,    -1,    -1,    -1,   265,    -1,   267,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,    -1,    -1,    -1,
      -1,   265,    -1,   267,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,    -1,    -1,    -1,    -1,   265,    -1,   267,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,    -1,    -1,    -1,
      -1,   265,    -1,   267,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,    -1,    -1,    -1,    -1,   265,    -1,   267,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,    -1,    -1,    -1,
      -1,   265,    -1,   267,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,    -1,    -1,    -1,    -1,   265,    -1,   267,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,    -1,    -1,    -1,
      -1,   265,    -1,   267,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,    -1,    -1,    -1,    -1,   265,    -1,   267,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,    -1,    -1,    -1,
      -1,   265,    -1,   267,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,    -1,    -1,    -1,    -1,   265,    -1,   267,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,    -1,    -1,    -1,
      -1,   265,    -1,   267,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,    -1,    -1,    -1,    -1,   265,    -1,   267,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,    -1,    -1,    -1,
      -1,   265,    -1,   267,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,    -1,    -1,    -1,    -1,   265,    -1,   267,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,    -1,    -1,    -1,
      -1,   265,    -1,   267,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,    -1,    -1,    -1,    -1,   265,    -1,   267,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,    -1,    -1,    -1,
      -1,   265,    -1,   267,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,    -1,    -1,    -1,    -1,   265,    -1,   267,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,    -1,    -1,    -1,
      -1,   265,    -1,   267,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,    -1,    -1,    -1,    -1,   265,    -1,   267,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,    -1,    -1,    -1,
      -1,   265,    -1,   267,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,    -1,    -1,    -1,    -1,   265,    -1,   267,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,    -1,    -1,    -1,
      -1,   265,    -1,   267,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,    -1,    -1,    -1,    -1,   265,    -1,   267,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,    -1,    -1,    -1,
      -1,   265,    -1,   267,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,    -1,    -1,    -1,    -1,   265,    -1,   267,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,    -1,    -1,    -1,
      -1,   265,    -1,   267,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,    -1,    -1,    -1,    -1,   265,    -1,   267,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,    -1,    -1,    -1,
      -1,   265,    -1,   267,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,    -1,    -1,    -1,    -1,   265,    -1,   267,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,    -1,    -1,    -1,
      -1,   265,    -1,   267,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,    -1,    -1,    -1,    -1,   265,    -1,   267,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,    -1,    -1,    -1,
      -1,   265,    -1,   267,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,    -1,    -1,    -1,    -1,   265,    -1,   267,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,    -1,    -1,    -1,
      -1,   265,    -1,   267,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,    -1,    -1,    -1,    -1,   265,    -1,   267,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,    -1,    -1,    -1,
      -1,   265,    -1,   267,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,    -1,    -1,    -1,    -1,   265,    -1,   267,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,    -1,    -1,    -1,
      -1,   265,    -1,   267,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,    -1,    -1,    -1,    -1,   265,    -1,   267,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,    -1,    -1,    -1,
      -1,   265,    -1,   267,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,    -1,    -1,    -1,    -1,   265,    -1,   267,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,    -1,    -1,    -1,
      -1,   265,    -1,   267,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,    -1,    -1,    -1,    -1,   265,    -1,   267,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,    -1,    -1,    -1,
      -1,   265,    -1,   267,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,    -1,    -1,    -1,    -1,   265,    -1,   267,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,    -1,    -1,    -1,
      -1,   265,    -1,   267,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,    -1,    -1,    -1,    -1,   265,    -1,   267,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,    -1,    -1,    -1,
      -1,   265,    -1,   267,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,    -1,    -1,    -1,    -1,   265,    -1,   267,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,    -1,    -1,    -1,
      -1,   265,    -1,   267,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,    -1,    -1,    -1,    -1,   265,    -1,   267,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,    -1,    -1,    -1,
      -1,   265,    -1,   267,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,    -1,    -1,    -1,    -1,   265,    -1,   267,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,    -1,    -1,    -1,
      -1,   265,    -1,   267,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,    -1,    -1,    -1,    -1,   265,    -1,   267,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,    -1,    -1,    -1,
      -1,   265,    -1,   267,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,    -1,    -1,    -1,    -1,   265
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,   277,   278,     6,     0,     4,    13,    14,    47,
      48,    49,    68,    69,    70,    75,    76,    81,    86,    87,
      88,    89,    90,    91,    92,    94,    95,    97,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   120,   121,   122,   123,   124,   127,
     129,   131,   132,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   150,   151,   152,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   182,   183,   184,   188,   193,
     194,   195,   196,   199,   201,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   223,
     224,   225,   226,   235,   237,   238,   279,   281,   282,   303,
     322,   324,   328,   331,   332,   333,   334,   335,   336,   337,
     338,   345,   347,   348,   354,   355,   356,   357,   363,   389,
     390,   270,   274,    14,   111,   266,   266,   266,     6,   270,
       6,     6,     6,     6,   266,     6,   270,     6,   270,   270,
       6,     6,     6,     6,   268,   268,     4,   365,   390,   266,
     268,   300,   105,   108,   111,   113,   324,   300,   266,   266,
     266,     4,   266,   266,   266,     4,   266,   266,   266,   266,
     266,   266,   266,   266,   266,   266,   266,   270,   128,   111,
       6,     6,   270,   105,   108,   111,   124,   327,   113,   266,
       3,    10,    11,    12,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    59,    60,    61,    62,
      67,    68,    77,    78,    79,    83,    84,    85,    88,    96,
      99,   105,   108,   111,   113,   124,   125,   126,   129,   138,
     143,   145,   148,   199,   217,   221,   222,   227,   228,   229,
     231,   232,   233,   254,   255,   261,   266,   270,   273,   324,
     325,   328,   338,   345,   347,   358,   359,   363,   365,   371,
     374,   390,   266,   270,   270,   111,   111,   138,   108,   111,
     113,   324,   108,   111,   112,   113,   124,   194,   325,   108,
     111,   266,   108,   170,   199,   215,   216,   270,   254,   255,
     266,   270,   368,   369,   368,   270,   270,   368,   270,   270,
     266,   111,   113,   111,   108,     4,    97,   210,   270,   390,
       4,     6,   105,     6,   270,   270,   108,   111,   108,   111,
     124,   326,     5,   266,   270,   371,   373,   111,     4,     4,
       4,   373,     4,   111,   266,   111,   266,   266,     4,   270,
     377,   390,     4,   266,   266,   266,     6,    33,   255,   358,
     390,     6,   268,     5,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    63,    64,    65,    66,    71,    72,    73,
      74,    80,    82,    98,   101,   218,   219,   220,   230,   234,
     236,   381,   390,   266,     4,   381,     5,   270,     5,   270,
     324,   358,   268,     6,   270,   266,   270,     6,   266,   270,
       6,   274,     7,   145,   210,   239,   240,   241,   242,   263,
     264,   266,   268,   272,   298,   299,   300,   324,   358,   380,
     381,   390,     4,   328,   329,   330,   270,     6,   358,   380,
     381,   390,   380,   380,   358,   380,   387,   388,   390,   358,
     330,   330,   358,   305,   309,   266,   367,     9,   381,   266,
     381,   358,   358,   358,   266,   358,   358,   358,   266,   358,
     358,   358,   358,   358,   358,   358,   380,   358,   358,   358,
     358,   373,   266,   255,   358,   374,   375,   270,   373,   371,
     380,   300,   300,   300,   300,   300,   300,   300,   300,   300,
     300,   300,   300,   300,   300,   300,   300,   300,   300,   300,
     300,   300,   300,   300,   300,   300,   300,   266,   268,   300,
     300,   300,   300,   300,   300,   266,   300,   300,   266,   324,
     325,   325,   325,   270,   300,   300,     5,   270,   270,   111,
     108,   111,    68,   105,   138,   324,   324,   325,   266,   300,
     300,   266,   266,   266,   358,   270,   358,   374,   358,   358,
     271,   375,   365,   390,   202,     5,   270,     8,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   265,     9,   266,   268,
     272,   299,   300,   358,   375,   375,   266,   266,   266,   371,
     373,   373,   373,   323,   266,   270,   266,   266,   371,   270,
     270,   358,     4,   371,   270,   377,   270,   270,   368,   368,
     368,   358,   358,   254,   255,   270,   270,   368,   254,   255,
     266,   330,   368,   270,   375,   375,   358,   373,   373,   373,
     266,   270,     4,   268,   270,     6,   268,   330,     6,     6,
     270,   330,   330,   270,   270,   270,   373,   358,     8,     7,
     270,   268,   268,   268,     6,     6,   266,   358,   266,   358,
     358,   272,   358,   270,   202,   358,   358,   358,   300,   358,
       6,   256,     9,   266,   268,   272,   358,   300,   300,   300,
     266,   266,   266,   300,   300,   300,   300,   300,   300,   300,
     300,   300,   300,   266,   266,   300,   266,   268,     6,     6,
     270,     6,     8,   330,     6,     8,   330,   266,   270,   380,
     375,   358,   330,   371,   371,   270,   381,   324,     7,   358,
     358,     4,    26,    37,    38,   114,   115,   199,   200,   302,
     371,     6,   267,   269,   270,   301,   270,     6,   270,     6,
       9,   266,   268,   272,   390,   271,   138,   143,   145,   146,
     148,   322,   324,   358,     6,   267,   275,     9,   266,   268,
     272,   267,   275,   267,   275,   275,   267,   275,     9,   266,
     272,   275,   271,   271,   275,   269,   275,   304,   269,   304,
     100,   366,   364,   390,   275,   358,   275,   267,   267,   267,
     358,   267,   267,   267,   358,   267,   267,   267,   267,   267,
     267,   267,   267,   275,   267,   267,   267,   271,     7,   358,
     256,   271,   275,   358,     6,     6,   267,   358,   358,   358,
     358,   358,   358,   358,   358,   358,   358,   358,   358,   358,
     358,   358,   358,   358,   358,   374,   358,   358,   358,   358,
     358,   358,   358,   358,   358,   374,   374,   390,   270,   358,
     358,   380,   358,   380,   371,   380,   380,   387,   270,   270,
     270,   270,   358,   301,   390,     8,   358,   358,   270,   270,
     270,   326,   270,   270,   373,   371,   270,   380,   380,   374,
     365,   381,   365,   375,   267,   271,   272,   300,    68,     8,
     358,   358,   358,   358,   358,   358,   358,   358,   358,   358,
     358,   358,   358,   358,   270,   358,   374,   358,   358,   358,
     358,   358,   390,   358,   358,   302,   270,   301,   267,   271,
     271,   358,   358,   358,     7,     7,   351,   351,   266,   358,
     358,   358,   358,     6,   175,   375,   375,   270,   267,     6,
     330,   270,   330,   330,   275,   275,   275,   368,   368,   329,
     329,   275,   358,   271,   342,   275,   330,   271,   271,   267,
       7,   352,     6,     7,   358,   358,     6,   358,   330,   358,
     271,   375,   271,   271,   375,   375,   358,     6,   267,   271,
     358,   375,   358,   358,   358,   358,   267,   358,   267,   267,
     199,   275,   330,   270,     8,   267,   267,   358,   358,   390,
     302,   269,   387,   380,   387,   380,   380,   380,   380,   380,
     380,   358,   380,   380,   380,   380,   273,   383,   390,   381,
     380,   380,   380,   365,   390,   375,   271,   271,   271,   271,
     358,   330,   269,   271,   267,   152,   170,   346,   267,   271,
     275,   358,     6,   270,   371,   267,   269,   272,     7,     7,
     298,   299,     6,   375,     7,   242,   298,   358,   283,   390,
     358,   358,   302,   268,   266,   138,   324,   325,   324,   270,
     271,     6,   249,   250,   280,   375,   390,   358,   358,   302,
       6,   375,     6,   375,   358,     6,   380,   388,   390,   267,
     302,   358,   270,   358,     6,   390,     6,   380,   358,   267,
     268,   358,   275,   381,     7,     7,     7,   267,     7,     7,
       7,   267,     7,     7,     7,     7,     7,     7,     7,   358,
       7,     7,     7,   358,   267,     6,   270,   358,   374,   271,
       6,   301,   301,   301,   301,   301,   301,   301,   301,   301,
     301,   301,   301,   275,   301,   301,   301,   301,   301,   301,
     301,   301,   301,   275,   275,   275,   275,   275,   267,   269,
     269,   375,   275,   275,   301,   275,   301,   275,   275,   275,
     267,   375,   358,   358,   358,   360,   301,   271,   271,   271,
     358,   358,   358,   270,   358,   376,   381,   358,   275,   275,
     301,   301,   267,   272,   267,   272,   275,   300,   361,   271,
       7,   302,   301,   371,   271,     8,     8,   375,   272,   267,
     269,   266,   268,   299,   300,   375,     7,   270,   270,   267,
     267,   267,   358,   371,     4,   350,     6,   318,   358,   381,
     267,   271,   267,   267,   358,   271,   271,   375,   272,   271,
     330,   271,   271,   368,   358,   358,   271,   271,   358,   368,
     149,   149,   167,   179,   180,   181,   185,   186,   343,   344,
     368,   271,   339,   270,   270,     7,   358,     6,   358,   267,
     271,   269,   271,   269,   271,   270,   271,   271,   271,     6,
     271,   269,   269,   275,   267,     7,   267,     7,     7,   272,
     358,   271,   358,   358,   272,   266,   268,     7,   272,   301,
     275,   301,   301,   267,   267,   275,   301,   301,   275,   275,
     301,   301,   301,   301,   358,   301,     9,   382,   275,   267,
     275,   301,   272,   275,   362,   269,   271,   267,   271,   274,
     202,     7,   170,     6,   358,   271,   270,     6,   371,   271,
     358,     6,     7,   298,   299,   272,   298,   299,   302,   270,
     378,   390,   381,   358,     6,   271,    50,    50,   371,   271,
       4,   189,   190,   191,   192,   271,   286,   290,   293,   295,
     296,   337,   272,   267,   269,   266,   358,   358,   266,   270,
     266,   270,     8,   375,   380,   267,   272,   267,   269,   266,
     267,   267,   275,   272,   266,   271,   358,   275,     7,   300,
       4,    26,    37,    38,   312,   313,   314,   301,   358,   301,
     368,   371,   371,     7,   371,   371,   371,     7,   371,   371,
     371,   371,   371,   371,   371,   267,   275,   371,   371,   371,
       6,     7,   329,   358,   358,   358,   358,   358,   358,   271,
     358,   358,   358,   371,   380,   380,   271,   271,   271,   271,
     275,   311,   271,   271,   271,   358,   271,   271,   275,   271,
     358,   358,   302,   302,   358,   358,   267,   371,   300,   358,
     358,   271,   302,   299,   272,   299,   358,   358,   301,   271,
     371,   375,   375,     7,     7,     7,   149,   349,     6,   267,
     275,     7,     7,     7,     6,     7,     7,   271,     4,   302,
     271,   275,   275,   275,   271,   271,   123,     4,     6,   358,
     270,     6,   266,     6,   187,     6,   187,   271,   344,   275,
     343,   329,   329,   371,     6,   270,   105,     6,     6,     6,
     358,   111,     7,     7,     6,     6,   358,     7,   371,     7,
     371,   371,     4,   275,     8,     8,   267,   302,   302,   302,
     375,   380,   358,   380,   273,   275,   315,   380,   380,   302,
     380,   267,   275,     6,   270,   324,   270,     6,   358,     6,
     270,   371,   271,   271,   358,     6,   199,   200,   302,   358,
       6,     7,   377,   379,     6,   268,     6,     6,   301,   300,
     300,     6,   287,   266,   266,   270,   297,     6,   302,   272,
     380,   358,   269,   267,   358,     8,   375,   376,   358,   375,
     271,   271,     6,     6,   280,   302,   272,   358,     6,     6,
     358,   302,   267,     6,   271,   275,   358,   270,   358,   381,
     301,    50,   270,   371,   381,   384,   358,   358,   358,   269,
     275,     6,   267,     6,     6,   142,   320,   320,   371,     6,
       6,     6,   371,   149,   202,   319,     6,     6,     6,     6,
       6,     6,   358,     6,     6,     6,     5,   271,   301,   301,
     301,   301,   301,   301,   301,   275,   275,   275,   267,   301,
     301,   313,   301,   129,   129,   129,   271,   202,   381,   267,
     301,   267,   300,   361,   301,     6,   301,   266,   268,   300,
     302,   267,   269,   301,     6,   271,   271,   371,   371,   371,
       4,     6,   298,   358,   371,   371,   371,   270,   270,     7,
       6,     7,   358,   358,   358,   270,   270,   270,   268,     6,
     358,   371,   358,     6,     6,   358,   368,   271,   271,   271,
       6,   375,   270,   271,   275,   270,   358,   358,   269,   371,
       6,   371,     6,   198,   358,   358,   358,   266,   268,     6,
       6,     7,   301,   275,   275,   301,   275,   358,     4,   214,
     316,   317,   301,   267,   301,   362,   381,   358,   270,   330,
       6,   330,   275,     6,     6,   272,     7,     7,   298,   299,
       6,   377,   271,   275,   358,   298,   270,   301,   385,   386,
     387,   385,   266,   358,   358,   370,   371,   270,   266,     4,
       6,   267,     6,   267,   271,   271,   271,   267,   271,     6,
       6,   380,   266,     4,   267,   275,   266,   358,   271,   275,
     371,   381,     7,   300,   310,   358,   374,   314,     6,   368,
       6,     6,     6,   149,   321,   105,   124,   109,     6,   267,
     275,     5,     6,   358,   358,   358,   270,   270,   270,   111,
     358,   267,   361,   358,   358,   301,   299,   270,   270,     6,
     319,     6,   358,   371,   149,   149,     4,     6,   375,   375,
     358,   358,   381,   271,   267,   271,   275,   329,   329,   358,
     358,   271,   275,   267,   271,   275,   271,   375,   358,   358,
       6,     6,     6,     6,     6,   371,   271,   275,     8,   271,
     267,   255,   270,   358,   372,   381,   380,   358,   380,   358,
     381,   384,   386,   381,   275,   267,   275,   271,   358,   346,
     346,   371,   302,   378,   381,   358,     6,     6,   377,   269,
     371,   387,     6,   301,   301,   284,   358,   275,   275,   271,
     275,   285,   358,   358,     6,     6,     6,     6,     6,   358,
     358,   267,   271,     6,   358,   306,   308,   270,   386,   271,
     275,     7,     7,   153,     6,   270,   270,   270,   358,     5,
     301,   301,   275,   358,   358,   358,   270,   301,   267,   267,
     269,   375,   375,     6,     6,   358,   358,   270,   271,   271,
     270,     6,     6,   270,   358,   271,   271,   271,   269,     6,
     371,     7,   270,   358,     6,   271,   271,   271,   197,   358,
     358,   270,   271,   375,     6,     6,     6,   267,   301,   301,
     317,   381,   271,   271,   271,   271,     7,     6,     6,     6,
     272,     6,   271,     6,     6,   267,   275,   358,   358,   270,
     371,   271,   275,   267,   267,   275,   271,   311,   315,   371,
     301,   358,   381,   390,   375,   375,   358,   267,     6,   358,
     275,   271,   275,   358,   361,   271,   271,     6,     6,   370,
     154,   155,   159,   353,   154,   155,   353,   375,   329,   271,
     275,     6,   271,   371,   330,   271,     6,   358,   271,   271,
     375,   271,   267,     6,   270,     6,   377,   200,   288,   358,
     275,   275,   370,     6,   358,   358,     6,   271,   271,   307,
       7,   266,   271,   271,   271,   275,   358,   358,   271,   267,
     270,   271,   270,   368,   371,     6,   270,   368,     6,   271,
     271,   358,     6,   149,   271,   340,   270,     6,   271,     6,
     330,     6,   270,   358,   358,   271,   275,   311,   381,   267,
     358,   271,   271,   375,     6,   368,     6,   368,     6,     6,
     271,   358,   343,   330,   346,   285,   267,   275,     6,   270,
     358,   271,   275,   271,   275,   275,     6,   271,   271,   341,
     271,   271,   291,   358,   370,   271,   358,   368,   368,   343,
       6,     6,   270,   267,   271,     6,   301,   275,   275,   271,
     289,   380,   294,   270,   358,   358,   271,   275,   270,   370,
     271,   271,     6,   380,   292,   380,   271,     6,     6,   271,
     275,     6,     6,   380
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
#line 288 "Gmsh.y"
    { yyerrok; return 1; ;}
    break;

  case 6:
#line 299 "Gmsh.y"
    { return 1; ;}
    break;

  case 7:
#line 300 "Gmsh.y"
    { return 1; ;}
    break;

  case 8:
#line 301 "Gmsh.y"
    { return 1; ;}
    break;

  case 9:
#line 303 "Gmsh.y"
    {
      // synchronize with GModel before switching kernel
      if(GModel::current()->getGEOInternals()->getChanged())
        GModel::current()->getGEOInternals()->synchronize(GModel::current());
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      GModel::current()->synchronizeDiscreteCADInternals();
      gmsh_yyfactory = (yyvsp[(3) - (5)].c);
      if(gmsh_yyfactory == "OpenCASCADE"){
        if(!GModel::current()->getOCCInternals())
          GModel::current()->createOCCInternals();
        for(int dim = -2; dim <= 3; dim++)
          GModel::current()->getOCCInternals()->setMaxTag
            (dim, std::max(GModel::current()->getOCCInternals()->getMaxTag(dim),
                           GModel::current()->getGEOInternals()->getMaxTag(dim)));
      }
      else if(gmsh_yyfactory == "Discrete"){
        if(!GModel::current()->getDiscreteCADInternals())
          GModel::current()->createDiscreteCADInternals();
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
#line 336 "Gmsh.y"
    { return 1; ;}
    break;

  case 11:
#line 337 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 12:
#line 338 "Gmsh.y"
    { return 1; ;}
    break;

  case 13:
#line 339 "Gmsh.y"
    { return 1; ;}
    break;

  case 14:
#line 340 "Gmsh.y"
    { return 1; ;}
    break;

  case 15:
#line 341 "Gmsh.y"
    { return 1; ;}
    break;

  case 16:
#line 342 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 17:
#line 343 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 18:
#line 344 "Gmsh.y"
    { return 1; ;}
    break;

  case 19:
#line 345 "Gmsh.y"
    { return 1; ;}
    break;

  case 20:
#line 346 "Gmsh.y"
    { return 1; ;}
    break;

  case 21:
#line 347 "Gmsh.y"
    { return 1; ;}
    break;

  case 22:
#line 348 "Gmsh.y"
    { return 1; ;}
    break;

  case 23:
#line 349 "Gmsh.y"
    { return 1; ;}
    break;

  case 24:
#line 350 "Gmsh.y"
    { return 1; ;}
    break;

  case 25:
#line 355 "Gmsh.y"
    {
      (yyval.c) = (char*)"w";
    ;}
    break;

  case 26:
#line 359 "Gmsh.y"
    {
      (yyval.c) = (char*)"a";
    ;}
    break;

  case 27:
#line 366 "Gmsh.y"
    {
      Msg::Direct("%s", (yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 28:
#line 371 "Gmsh.y"
    {
      Msg::Warning("%s", (yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 29:
#line 376 "Gmsh.y"
    {
      Msg::Error("%s", (yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 30:
#line 381 "Gmsh.y"
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
#line 395 "Gmsh.y"
    {
      std::string tmpstring;
      int i = printListOfDouble((yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].l), tmpstring);
      if(i < 0)
	yymsg(0, "Too few arguments in Printf");
      else if(i > 0)
	yymsg(0, "%d extra argument%s in Printf", i, (i > 1) ? "s" : "");
      else
	Msg::Direct("%s", tmpstring.c_str());
      Free((yyvsp[(3) - (7)].c));
      List_Delete((yyvsp[(5) - (7)].l));
    ;}
    break;

  case 32:
#line 408 "Gmsh.y"
    {
      std::string tmpstring;
      int i = printListOfDouble((yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].l), tmpstring);
      if(i < 0)
	yymsg(1, "Too few arguments in Error");
      else if(i > 0)
	yymsg(1, "%d extra argument%s in Error", i, (i > 1) ? "s" : "");
      else
	Msg::Warning("%s", tmpstring.c_str());
      Free((yyvsp[(3) - (7)].c));
      List_Delete((yyvsp[(5) - (7)].l));
    ;}
    break;

  case 33:
#line 421 "Gmsh.y"
    {
      std::string tmpstring;
      int i = printListOfDouble((yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].l), tmpstring);
      if(i < 0)
	yymsg(0, "Too few arguments in Error");
      else if(i > 0)
	yymsg(0, "%d extra argument%s in Error", i, (i > 1) ? "s" : "");
      else
	Msg::Error("%s", tmpstring.c_str());
      Free((yyvsp[(3) - (7)].c));
      List_Delete((yyvsp[(5) - (7)].l));
    ;}
    break;

  case 34:
#line 434 "Gmsh.y"
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

  case 35:
#line 462 "Gmsh.y"
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

  case 36:
#line 476 "Gmsh.y"
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

  case 37:
#line 489 "Gmsh.y"
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

  case 38:
#line 502 "Gmsh.y"
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

  case 39:
#line 520 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData = new PViewDataList();
#endif
    ;}
    break;

  case 46:
#line 535 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(1) - (1)].d)); ;}
    break;

  case 47:
#line 537 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(3) - (3)].d)); ;}
    break;

  case 48:
#line 542 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(1) - (1)].d)); ;}
    break;

  case 49:
#line 544 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(3) - (3)].d)); ;}
    break;

  case 50:
#line 549 "Gmsh.y"
    {
#if defined(HAVE_POST)
      // the list of the element type named by the 2 first letters (e.g. ST
      // for scalar triangles), of order 2 if followed by 2 (e.g. ST2)
      ViewValueList = 0;
      for(int i = 0; i < 24; i++){
        const PViewDataList::listKind &k = PViewDataList::listKinds[i];
        if(!strncmp((yyvsp[(1) - (1)].c), k.name, 2)){
          ViewValueList = ViewData->incrementList(k.numComp, k.type);
          if(strlen((yyvsp[(1) - (1)].c)) > 2 && k.type != TYPE_PNT) ViewData->setOrder2(k.type);
          break;
        }
      }
      if(!ViewValueList) yymsg(0, "Unknown element type '%s'", (yyvsp[(1) - (1)].c));
#endif
      ViewCoord.clear();
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 51:
#line 568 "Gmsh.y"
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
#line 582 "Gmsh.y"
    {
      ViewStrings.push_back((yyvsp[(1) - (1)].c));
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 54:
#line 587 "Gmsh.y"
    {
      ViewStrings.push_back((yyvsp[(3) - (3)].c));
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 55:
#line 595 "Gmsh.y"
    {
      ViewStrings.clear();
    ;}
    break;

  case 56:
#line 599 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->addString2D((yyvsp[(3) - (13)].d), (yyvsp[(5) - (13)].d), (yyvsp[(7) - (13)].d), ViewStrings);
#endif
    ;}
    break;

  case 57:
#line 608 "Gmsh.y"
    {
      ViewStrings.push_back((yyvsp[(1) - (1)].c));
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 58:
#line 613 "Gmsh.y"
    {
      ViewStrings.push_back((yyvsp[(3) - (3)].c));
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 59:
#line 621 "Gmsh.y"
    {
      ViewStrings.clear();
    ;}
    break;

  case 60:
#line 625 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->addString3D((yyvsp[(3) - (15)].d), (yyvsp[(5) - (15)].d), (yyvsp[(7) - (15)].d), (yyvsp[(9) - (15)].d), ViewStrings);
#endif
    ;}
    break;

  case 61:
#line 635 "Gmsh.y"
    {
#if defined(HAVE_POST)
      int type =
	ViewData->getNumLines() ? TYPE_LIN :
	ViewData->getNumTriangles() ? TYPE_TRI :
	ViewData->getNumQuadrangles() ? TYPE_QUA :
	ViewData->getNumTetrahedra() ? TYPE_TET :
	ViewData->getNumPyramids() ? TYPE_PYR :
	ViewData->getNumPrisms() ? TYPE_PRI :
      	ViewData->getNumHexahedra() ? TYPE_HEX :
	0;
      ViewData->setInterpolationMatrices(type, ListOfListOfDouble2Matrix((yyvsp[(3) - (8)].l)),
                                         ListOfListOfDouble2Matrix((yyvsp[(6) - (8)].l)));
#endif
    ;}
    break;

  case 62:
#line 654 "Gmsh.y"
    {
#if defined(HAVE_POST)
      int type =
	ViewData->getNumLines() ? TYPE_LIN :
	ViewData->getNumTriangles() ? TYPE_TRI :
	ViewData->getNumQuadrangles() ? TYPE_QUA :
	ViewData->getNumTetrahedra() ? TYPE_TET :
      	ViewData->getNumHexahedra() ? TYPE_HEX :
	0;
      ViewData->setInterpolationMatrices(type, ListOfListOfDouble2Matrix((yyvsp[(3) - (14)].l)),
                                         ListOfListOfDouble2Matrix((yyvsp[(6) - (14)].l)),
                                         ListOfListOfDouble2Matrix((yyvsp[(9) - (14)].l)),
                                         ListOfListOfDouble2Matrix((yyvsp[(12) - (14)].l)));
#endif
    ;}
    break;

  case 63:
#line 673 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewTime.clear();
      ViewValueList = &ViewTime;
#endif
    ;}
    break;

  case 64:
#line 680 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(auto t : ViewTime) ViewData->addTime(t);
#endif
    ;}
    break;

  case 65:
#line 690 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 66:
#line 691 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 67:
#line 692 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 68:
#line 693 "Gmsh.y"
    { (yyval.i) = 3; ;}
    break;

  case 69:
#line 694 "Gmsh.y"
    { (yyval.i) = 4; ;}
    break;

  case 70:
#line 698 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 71:
#line 699 "Gmsh.y"
    { (yyval.i) = -1; ;}
    break;

  case 72:
#line 705 "Gmsh.y"
    { (yyval.c) = (char*)"("; ;}
    break;

  case 73:
#line 705 "Gmsh.y"
    { (yyval.c) = (char*)"["; ;}
    break;

  case 74:
#line 707 "Gmsh.y"
    { (yyval.c) = (char*)")"; ;}
    break;

  case 75:
#line 707 "Gmsh.y"
    { (yyval.c) = (char*)"]"; ;}
    break;

  case 76:
#line 712 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 77:
#line 713 "Gmsh.y"
    { (yyval.c) = (char *)Malloc(4 * sizeof(char)); strcpy((yyval.c), "Min"); ;}
    break;

  case 78:
#line 714 "Gmsh.y"
    { (yyval.c) = (char *)Malloc(4 * sizeof(char)); strcpy((yyval.c), "Max"); ;}
    break;

  case 79:
#line 715 "Gmsh.y"
    { (yyval.c) = (char *)Malloc(5 * sizeof(char)); strcpy((yyval.c), "Step"); ;}
    break;

  case 80:
#line 716 "Gmsh.y"
    { (yyval.c) = (char *)Malloc(4 * sizeof(char)); strcpy((yyval.c), "Box"); ;}
    break;

  case 81:
#line 717 "Gmsh.y"
    { (yyval.c) = (char *)Malloc(9 * sizeof(char)); strcpy((yyval.c), "Cylinder"); ;}
    break;

  case 85:
#line 727 "Gmsh.y"
    {
      Msg::SetOnelabNumber((yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].d));
      Free((yyvsp[(3) - (7)].c));
    ;}
    break;

  case 86:
#line 732 "Gmsh.y"
    {
      Msg::SetOnelabString((yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].c));
      Free((yyvsp[(3) - (7)].c));
      Free((yyvsp[(5) - (7)].c));
    ;}
    break;

  case 87:
#line 738 "Gmsh.y"
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

  case 88:
#line 799 "Gmsh.y"
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

  case 90:
#line 842 "Gmsh.y"
    {
      assignVariables((yyvsp[(1) - (9)].c), (yyvsp[(4) - (9)].l), (yyvsp[(7) - (9)].i), (yyvsp[(8) - (9)].l));
      Free((yyvsp[(1) - (9)].c));
      List_Delete((yyvsp[(4) - (9)].l));
      List_Delete((yyvsp[(8) - (9)].l));
    ;}
    break;

  case 91:
#line 852 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    ;}
    break;

  case 92:
#line 857 "Gmsh.y"
    {
      incrementVariable((yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].i));
      Free((yyvsp[(1) - (6)].c));
    ;}
    break;

  case 93:
#line 865 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    ;}
    break;

  case 94:
#line 870 "Gmsh.y"
    {
      incrementVariable((yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].i));
      Free((yyvsp[(1) - (6)].c));
    ;}
    break;

  case 95:
#line 878 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[(1) - (4)].c)] = std::vector<std::string>(1, (yyvsp[(3) - (4)].c));
      Free((yyvsp[(1) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 96:
#line 887 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[(1) - (8)].c)] = std::vector<std::string>();
      Free((yyvsp[(1) - (8)].c));
    ;}
    break;

  case 97:
#line 892 "Gmsh.y"
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
#line 904 "Gmsh.y"
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
#line 921 "Gmsh.y"
    {
      std::string tmp((yyvsp[(5) - (6)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (6)].c), 0, (yyvsp[(3) - (6)].c), tmp);
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 100:
#line 927 "Gmsh.y"
    {
      std::string tmp((yyvsp[(8) - (9)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (9)].c), (int)(yyvsp[(3) - (9)].d), (yyvsp[(6) - (9)].c), tmp);
      Free((yyvsp[(1) - (9)].c)); Free((yyvsp[(6) - (9)].c)); Free((yyvsp[(8) - (9)].c));
    ;}
    break;

  case 101:
#line 936 "Gmsh.y"
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
#line 954 "Gmsh.y"
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
#line 972 "Gmsh.y"
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
#line 981 "Gmsh.y"
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
#line 993 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (8)].c), 0, (yyvsp[(5) - (8)].c), (yyvsp[(7) - (8)].u));
      Free((yyvsp[(1) - (8)].c)); Free((yyvsp[(5) - (8)].c));
    ;}
    break;

  case 106:
#line 998 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (11)].c), (int)(yyvsp[(3) - (11)].d), (yyvsp[(8) - (11)].c), (yyvsp[(10) - (11)].u));
      Free((yyvsp[(1) - (11)].c)); Free((yyvsp[(8) - (11)].c));
    ;}
    break;

  case 107:
#line 1006 "Gmsh.y"
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
#line 1026 "Gmsh.y"
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
#line 1049 "Gmsh.y"
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

  case 110:
#line 1069 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      if(!GModel::current()->getFields()->newField((int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c)))
	yymsg(0, "Cannot create field %i of type '%s'", (int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c));
#endif
      Free((yyvsp[(6) - (7)].c));
    ;}
    break;

  case 111:
#line 1077 "Gmsh.y"
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

  case 112:
#line 1094 "Gmsh.y"
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

  case 113:
#line 1112 "Gmsh.y"
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

  case 114:
#line 1150 "Gmsh.y"
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
#line 1171 "Gmsh.y"
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
#line 1183 "Gmsh.y"
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
#line 1201 "Gmsh.y"
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
#line 1210 "Gmsh.y"
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
#line 1219 "Gmsh.y"
    { init_options(); ;}
    break;

  case 123:
#line 1221 "Gmsh.y"
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
#line 1239 "Gmsh.y"
    { init_options(); ;}
    break;

  case 125:
#line 1241 "Gmsh.y"
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
#line 1257 "Gmsh.y"
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
#line 1266 "Gmsh.y"
    { init_options(); ;}
    break;

  case 128:
#line 1268 "Gmsh.y"
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
#line 1282 "Gmsh.y"
    {
      std::string name((yyvsp[(3) - (3)].c));
      Msg::UndefineOnelabParameter(name);
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 131:
#line 1290 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(doubleXstring));
      doubleXstring v = {(yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].c)};
      List_Add((yyval.l), &v);
    ;}
    break;

  case 132:
#line 1296 "Gmsh.y"
    {
      doubleXstring v = {(yyvsp[(3) - (5)].d), (yyvsp[(5) - (5)].c)};
      List_Add((yyval.l), &v);
    ;}
    break;

  case 133:
#line 1301 "Gmsh.y"
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
#line 1344 "Gmsh.y"
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

  case 141:
#line 1356 "Gmsh.y"
    {
      floatOptions["Min"].push_back((yyvsp[(2) - (2)].d));
    ;}
    break;

  case 142:
#line 1360 "Gmsh.y"
    {
      floatOptions["Max"].push_back((yyvsp[(2) - (2)].d));
    ;}
    break;

  case 143:
#line 1364 "Gmsh.y"
    {
      floatOptions["Step"].push_back((yyvsp[(2) - (2)].d));
    ;}
    break;

  case 144:
#line 1368 "Gmsh.y"
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

  case 145:
#line 1381 "Gmsh.y"
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

  case 146:
#line 1395 "Gmsh.y"
    {
      std::string key((yyvsp[(1) - (2)].c));
      std::string val((yyvsp[(2) - (2)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(1) - (2)].c));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 147:
#line 1403 "Gmsh.y"
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

  case 152:
#line 1428 "Gmsh.y"
    {
      std::string key((yyvsp[(1) - (2)].c));
      double val = (yyvsp[(2) - (2)].d);
      floatOptions[key].push_back(val);
      Free((yyvsp[(1) - (2)].c));
    ;}
    break;

  case 153:
#line 1436 "Gmsh.y"
    {
      std::string key((yyvsp[(1) - (2)].c));
      std::string val((yyvsp[(2) - (2)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(1) - (2)].c));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 154:
#line 1445 "Gmsh.y"
    {
      std::string key("Macro");
      std::string val((yyvsp[(2) - (2)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 155:
#line 1453 "Gmsh.y"
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
#line 1467 "Gmsh.y"
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
#line 1485 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    ;}
    break;

  case 158:
#line 1489 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->getPhysicalNumber(dim_entity, std::string((yyvsp[(1) - (1)].c)));

      if ((yyval.i) < 0) {
        int t = GModel::current()->getGEOInternals()->getMaxPhysicalTag();
        GModel::current()->getGEOInternals()->setMaxPhysicalTag(t + 1);
        (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (1)].c)), dim_entity, t + 1);
      }
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 159:
#line 1500 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (3)].c)), dim_entity, (yyvsp[(3) - (3)].d));
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 160:
#line 1508 "Gmsh.y"
    {
      (yyval.l) = 0;
    ;}
    break;

  case 161:
#line 1512 "Gmsh.y"
    {
      (yyval.l) = List_Create(1, 1, sizeof(double));
      double p = (yyvsp[(4) - (5)].d);
      List_Add((yyval.l), &p);
    ;}
    break;

  case 162:
#line 1518 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
    ;}
    break;

  case 163:
#line 1522 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      double flag = -1;
      List_Add((yyval.l), &flag);
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++)
        List_Add((yyval.l), List_Pointer((yyvsp[(4) - (5)].l), i));
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 164:
#line 1533 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = 0.;
    ;}
    break;

  case 165:
#line 1537 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 166:
#line 1543 "Gmsh.y"
    {
      (yyval.d) = 0;
    ;}
    break;

  case 167:
#line 1547 "Gmsh.y"
    {
      (yyval.d) = 1;
    ;}
    break;

  case 168:
#line 1553 "Gmsh.y"
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

  case 169:
#line 1576 "Gmsh.y"
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

  case 170:
#line 1592 "Gmsh.y"
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

  case 171:
#line 1608 "Gmsh.y"
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

  case 172:
#line 1625 "Gmsh.y"
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

  case 173:
#line 1642 "Gmsh.y"
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

  case 174:
#line 1679 "Gmsh.y"
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

  case 175:
#line 1723 "Gmsh.y"
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

  case 176:
#line 1739 "Gmsh.y"
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

  case 177:
#line 1756 "Gmsh.y"
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

  case 178:
#line 1787 "Gmsh.y"
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

  case 179:
#line 1803 "Gmsh.y"
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

  case 180:
#line 1820 "Gmsh.y"
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

  case 181:
#line 1836 "Gmsh.y"
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

  case 182:
#line 1886 "Gmsh.y"
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

  case 183:
#line 1904 "Gmsh.y"
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

  case 184:
#line 1925 "Gmsh.y"
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

  case 185:
#line 1946 "Gmsh.y"
    {
      myGmshSurface = 0;
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 186:
#line 1952 "Gmsh.y"
    {
      myGmshSurface = gmshSurface::getSurface((int)(yyvsp[(3) - (4)].d));
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 187:
#line 1958 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (10)].d);
      myGmshSurface = gmshParametricSurface::NewParametricSurface(num, (yyvsp[(7) - (10)].c), (yyvsp[(8) - (10)].c), (yyvsp[(9) - (10)].c));
      (yyval.s).Type = 0;
      (yyval.s).Num = num;
    ;}
    break;

  case 188:
#line 1965 "Gmsh.y"
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
#if defined(HAVE_DISCRETECAD)
        else if(gmsh_yyfactory == "Discrete" &&
                GModel::current()->getDiscreteCADInternals()){
          if(param.size() == 4)
            r = GModel::current()->getDiscreteCADInternals()->addSphere
              (num, param[0], param[1], param[2], param[3], -1.);
          else
            yymsg(0, "Sphere requires 4 parameters with the Discrete geometry kernel");
        }
#endif
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

  case 189:
#line 2006 "Gmsh.y"
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

  case 190:
#line 2021 "Gmsh.y"
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
#if defined(HAVE_DISCRETECAD)
      else if(gmsh_yyfactory == "Discrete" &&
              GModel::current()->getDiscreteCADInternals()){
        if(param.size() == 6)
          r = GModel::current()->getDiscreteCADInternals()->addBox
            (num, param[0], param[1], param[2], param[3], param[4], param[5]);
        else
          yymsg(0, "Box requires 6 parameters with the Discrete geometry kernel");
      }
#endif
      else{
        yymsg(0, "Box only available with OpenCASCADE geometry kernel");
      }
      if(!r) yymsg(0, "Could not add block");
      List_Delete((yyvsp[(6) - (7)].l));
      (yyval.s).Type = MSH_VOLUME;
      (yyval.s).Num = num;
    ;}
    break;

  case 191:
#line 2053 "Gmsh.y"
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
#if defined(HAVE_DISCRETECAD)
      else if(gmsh_yyfactory == "Discrete" &&
              GModel::current()->getDiscreteCADInternals()){
        if(param.size() == 5)
          r = GModel::current()->getDiscreteCADInternals()->addTorus
            (num, param[0], param[1], param[2], param[3], param[4],
             std::vector<double>(), -1.);
        else
          yymsg(0, "Torus requires 5 parameters with the Discrete geometry kernel");
      }
#endif
      else{
        yymsg(0, "Torus only available with OpenCASCADE geometry kernel");
      }
      if(!r) yymsg(0, "Could not add torus");
      List_Delete((yyvsp[(6) - (7)].l));
      (yyval.s).Type = MSH_VOLUME;
      (yyval.s).Num = num;
    ;}
    break;

  case 192:
#line 2087 "Gmsh.y"
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
#if defined(HAVE_DISCRETECAD)
      else if(gmsh_yyfactory == "Discrete" &&
              GModel::current()->getDiscreteCADInternals()){
        if(param.size() == 5)
          r = GModel::current()->getDiscreteCADInternals()->addRectangle
            (num, param[0], param[1], param[2], param[3], param[4]);
        else
          yymsg(0, "Rectangle requires 5 parameters with the Discrete geometry kernel");
      }
#endif
      else{
        yymsg(0, "Rectangle only available with OpenCASCADE geometry kernel");
      }
      if(!r) yymsg(0, "Could not add rectangle");
      List_Delete((yyvsp[(6) - (7)].l));
      (yyval.s).Type = MSH_SURF_PLAN;
      (yyval.s).Num = num;
    ;}
    break;

  case 193:
#line 2120 "Gmsh.y"
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
#if defined(HAVE_DISCRETECAD)
      else if(gmsh_yyfactory == "Discrete" &&
              GModel::current()->getDiscreteCADInternals()){
        if(param.size() == 4 || param.size() == 5)
          r = GModel::current()->getDiscreteCADInternals()->addDisk
            (num, param[0], param[1], param[2], param[3],
             param.size() == 5 ? param[4] : param[3], std::vector<double>(),
             std::vector<double>(), -1.);
        else
          yymsg(0, "Disk requires 4 or 5 parameters with the Discrete geometry kernel");
      }
#endif
      else{
        yymsg(0, "Disk only available with OpenCASCADE geometry kernel");
      }
      if(!r) yymsg(0, "Could not add disk");
      List_Delete((yyvsp[(6) - (7)].l));
      (yyval.s).Type = MSH_SURF_PLAN;
      (yyval.s).Num = num;
    ;}
    break;

  case 194:
#line 2155 "Gmsh.y"
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
#if defined(HAVE_DISCRETECAD)
      else if(gmsh_yyfactory == "Discrete" &&
              GModel::current()->getDiscreteCADInternals()){
        if(param.size() == 7)
          r = GModel::current()->getDiscreteCADInternals()->addCylinder
            (num, param[0], param[1], param[2], param[3], param[4], param[5],
             param[6], -1.);
        else
          yymsg(0, "Cylinder requires 7 parameters with the Discrete geometry kernel");
      }
#endif
      else{
        yymsg(0, "Cylinder only available with OpenCASCADE geometry kernel");
      }
      if(!r) yymsg(0, "Could not add cylinder");
      List_Delete((yyvsp[(6) - (7)].l));
      (yyval.s).Type = MSH_VOLUME;
      (yyval.s).Num = num;
    ;}
    break;

  case 195:
#line 2190 "Gmsh.y"
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
#if defined(HAVE_DISCRETECAD)
      else if(gmsh_yyfactory == "Discrete" &&
              GModel::current()->getDiscreteCADInternals()){
        if(param.size() == 8)
          r = GModel::current()->getDiscreteCADInternals()->addCone
            (num, param[0], param[1], param[2], param[3], param[4], param[5],
             param[6], param[7], -1.);
        else
          yymsg(0, "Cone requires 8 parameters with the Discrete geometry kernel");
      }
#endif
      else{
        yymsg(0, "Cone only available with OpenCASCADE geometry kernel");
      }
      if(!r) yymsg(0, "Could not add cone");
      List_Delete((yyvsp[(6) - (7)].l));
      (yyval.s).Type = MSH_VOLUME;
      (yyval.s).Num = num;
    ;}
    break;

  case 196:
#line 2225 "Gmsh.y"
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

  case 197:
#line 2249 "Gmsh.y"
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

  case 198:
#line 2275 "Gmsh.y"
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

  case 199:
#line 2292 "Gmsh.y"
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

  case 200:
#line 2308 "Gmsh.y"
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

  case 201:
#line 2326 "Gmsh.y"
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

  case 202:
#line 2344 "Gmsh.y"
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

  case 203:
#line 2357 "Gmsh.y"
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

  case 204:
#line 2369 "Gmsh.y"
    {
      dim_entity = (yyvsp[(2) - (2)].i);
    ;}
    break;

  case 205:
#line 2373 "Gmsh.y"
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

  case 206:
#line 2399 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 207:
#line 2401 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 208:
#line 2403 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 209:
#line 2405 "Gmsh.y"
    { (yyval.i) = 3; ;}
    break;

  case 210:
#line 2407 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(3) - (4)].d);
      if((yyval.i) < 0 || (yyval.i) > 3) yymsg(0, "GeoEntity dim out of range [0,3]");
    ;}
    break;

  case 211:
#line 2415 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 212:
#line 2417 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 213:
#line 2419 "Gmsh.y"
    { (yyval.i) = 3; ;}
    break;

  case 214:
#line 2421 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(3) - (4)].d);
      if((yyval.i)<1 || (yyval.i)>3) yymsg(0, "GeoEntity dim out of range [1,3]");
    ;}
    break;

  case 215:
#line 2429 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 216:
#line 2431 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 217:
#line 2433 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(3) - (4)].d);
      if((yyval.i)<1 || (yyval.i)>2) yymsg(0, "GeoEntity dim out of range [1,2]");
    ;}
    break;

  case 218:
#line 2441 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 219:
#line 2443 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 220:
#line 2445 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 221:
#line 2447 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(3) - (4)].d);
      if((yyval.i) < 0 || (yyval.i) > 2) yymsg(0, "GeoEntity dim out of range [0,2]");
    ;}
    break;

  case 222:
#line 2457 "Gmsh.y"
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

  case 223:
#line 2473 "Gmsh.y"
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

  case 224:
#line 2489 "Gmsh.y"
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

  case 225:
#line 2505 "Gmsh.y"
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

  case 226:
#line 2521 "Gmsh.y"
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

  case 227:
#line 2537 "Gmsh.y"
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

  case 228:
#line 2554 "Gmsh.y"
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

  case 229:
#line 2580 "Gmsh.y"
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
        GModel::current()->synchronizeDiscreteCADInternals();
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

  case 230:
#line 2623 "Gmsh.y"
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

  case 231:
#line 2644 "Gmsh.y"
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

  case 232:
#line 2665 "Gmsh.y"
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

  case 233:
#line 2690 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 234:
#line 2691 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 235:
#line 2696 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    ;}
    break;

  case 236:
#line 2700 "Gmsh.y"
    {
      List_Add((yyval.l), &(yyvsp[(2) - (2)].s));
    ;}
    break;

  case 237:
#line 2704 "Gmsh.y"
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

  case 238:
#line 2721 "Gmsh.y"
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

  case 239:
#line 2741 "Gmsh.y"
    {
      List_T *tmp = List_Create(10, 10, sizeof(double));
      getElementaryTagsForPhysicalNames((yyvsp[(3) - (7)].i), (yyvsp[(5) - (7)].l), tmp);
      for(int i = 0; i < List_Nbr(tmp); i++){
	double d;
	List_Read(tmp, i, &d);
 	Shape s;
	s.Num = (int)d;
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
#line 2761 "Gmsh.y"
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
#line 2781 "Gmsh.y"
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
#line 2800 "Gmsh.y"
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
#line 2827 "Gmsh.y"
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

  case 244:
#line 2852 "Gmsh.y"
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

  case 245:
#line 2877 "Gmsh.y"
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

  case 246:
#line 2889 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      GModel::current()->getFields()->deleteField((int)(yyvsp[(4) - (6)].d));
#endif
    ;}
    break;

  case 247:
#line 2895 "Gmsh.y"
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

  case 248:
#line 2910 "Gmsh.y"
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

  case 249:
#line 2941 "Gmsh.y"
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

  case 250:
#line 2953 "Gmsh.y"
    {
      gmsh_yynamespaces.clear();
    ;}
    break;

  case 251:
#line 2962 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), dimTags);
      setColor(dimTags, (yyvsp[(2) - (5)].u), false);
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 252:
#line 2969 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(5) - (6)].l), dimTags);
      setColor(dimTags, (yyvsp[(3) - (6)].u), true);
      List_Delete((yyvsp[(5) - (6)].l));
    ;}
    break;

  case 253:
#line 2981 "Gmsh.y"
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

  case 254:
#line 3001 "Gmsh.y"
    {
      setVisibility(-1, 1, false);
    ;}
    break;

  case 255:
#line 3005 "Gmsh.y"
    {
      setVisibility(-1, 1, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 256:
#line 3010 "Gmsh.y"
    {
      setVisibility(-1, 0, false);
    ;}
    break;

  case 257:
#line 3014 "Gmsh.y"
    {
      setVisibility(-1, 0, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 258:
#line 3019 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(3) - (4)].l), dimTags);
      setVisibility(dimTags, 1, false);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 259:
#line 3026 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), dimTags);
      setVisibility(dimTags, 1, true);
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 260:
#line 3033 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(3) - (4)].l), dimTags);
      setVisibility(dimTags, 0, false);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 261:
#line 3040 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), dimTags);
      setVisibility(dimTags, 0, true);
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 262:
#line 3052 "Gmsh.y"
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
        GModel::current()->synchronizeDiscreteCADInternals();
        if(GModel::current()->getGEOInternals()->getChanged())
          GModel::current()->getGEOInternals()->synchronize(GModel::current());
        std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(2) - (3)].c));
	CreateOutputFile(tmp, CTX::instance()->print.fileFormat);
      }
      else if(!strcmp((yyvsp[(1) - (3)].c), "Save")){
        if(GModel::current()->getOCCInternals() &&
           GModel::current()->getOCCInternals()->getChanged())
          GModel::current()->getOCCInternals()->synchronize(GModel::current());
        GModel::current()->synchronizeDiscreteCADInternals();
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
        GModel::current()->synchronizeDiscreteCADInternals();
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

  case 263:
#line 3128 "Gmsh.y"
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

  case 264:
#line 3146 "Gmsh.y"
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

  case 265:
#line 3171 "Gmsh.y"
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

  case 266:
#line 3186 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(1) - (3)].c), "Sleep")) {
	SleepInSeconds((yyvsp[(2) - (3)].d));
      }
      else if(!strcmp((yyvsp[(1) - (3)].c), "Remesh")) {
	yymsg(0, "Surface remeshing must be reinterfaced");
      }
      else if(!strcmp((yyvsp[(1) - (3)].c), "Mesh")) {
        // part of the operation reading the script, which may hold the lock
        if(GModel::current()->getOCCInternals() &&
           GModel::current()->getOCCInternals()->getChanged())
          GModel::current()->getOCCInternals()->synchronize(GModel::current());
        GModel::current()->synchronizeDiscreteCADInternals();
        if(GModel::current()->getGEOInternals()->getChanged())
          GModel::current()->getGEOInternals()->synchronize(GModel::current());
	GModel::current()->mesh((int)(yyvsp[(2) - (3)].d), true);
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
      else if(!strcmp((yyvsp[(1) - (3)].c), "CreateOverlaps")) {
        GModel::current()->createOverlaps((yyvsp[(2) - (3)].d));
      }
      else if(!strcmp((yyvsp[(1) - (3)].c), "SetCurrentWindow")) {
#if defined(HAVE_FLTK)
        if(FlGui::available()) FlGui::instance()->setCurrentOpenglWindow((int)(yyvsp[(2) - (3)].d));
#endif
      }
      else if(!strcmp((yyvsp[(1) - (3)].c), "SplitCurrentWindowHorizontal")) {
#if defined(HAVE_FLTK)
        if(FlGui::available()) FlGui::instance()->splitCurrentOpenglWindow('h', (yyvsp[(2) - (3)].d));
#endif
      }
      else if(!strcmp((yyvsp[(1) - (3)].c), "SplitCurrentWindowVertical")) {
#if defined(HAVE_FLTK)
        if(FlGui::available()) FlGui::instance()->splitCurrentOpenglWindow('v', (yyvsp[(2) - (3)].d));
#endif
      }
      else {
	yymsg(0, "Unknown command '%s'", (yyvsp[(1) - (3)].c));
      }
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 267:
#line 3237 "Gmsh.y"
    {
#if defined(HAVE_FLTK)
      if(FlGui::available()) FlGui::instance()->splitCurrentOpenglWindow('u');
#endif
    ;}
    break;

  case 268:
#line 3243 "Gmsh.y"
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

  case 269:
#line 3255 "Gmsh.y"
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

  case 270:
#line 3287 "Gmsh.y"
    {
      Msg::Exit(0, false); // will return 0 only if no meshing error occurred
    ;}
    break;

  case 271:
#line 3291 "Gmsh.y"
    {
      Msg::Exit((int)(yyvsp[(2) - (3)].d), true); // will always return the specified value
    ;}
    break;

  case 272:
#line 3295 "Gmsh.y"
    {
      gmsh_yyerrorstate = 999; // this will be checked when yyparse returns
      YYABORT;
    ;}
    break;

  case 273:
#line 3300 "Gmsh.y"
    {
      // force sync
      if(GModel::current()->getOCCInternals())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      GModel::current()->synchronizeDiscreteCADInternals();
      GModel::current()->getGEOInternals()->synchronize(GModel::current());
    ;}
    break;

  case 274:
#line 3308 "Gmsh.y"
    {
      new GModel();
      GModel::current(GModel::list.size() - 1);
    ;}
    break;

  case 275:
#line 3313 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 0;
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      GModel::current()->synchronizeDiscreteCADInternals();
      if(GModel::current()->getGEOInternals()->getChanged())
        GModel::current()->getGEOInternals()->synchronize(GModel::current());
      SetBoundingBox();
    ;}
    break;

  case 276:
#line 3324 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 1;
      SetBoundingBox((yyvsp[(3) - (15)].d), (yyvsp[(5) - (15)].d), (yyvsp[(7) - (15)].d), (yyvsp[(9) - (15)].d), (yyvsp[(11) - (15)].d), (yyvsp[(13) - (15)].d));
    ;}
    break;

  case 277:
#line 3329 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
      drawContext::global()->draw(false); // not rate limited
#endif
    ;}
    break;

  case 278:
#line 3335 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
     CTX::instance()->meshChanged();
     for(std::size_t index = 0; index < PView::list.size(); index++)
       PView::list[index]->setChanged(true);
#endif
    ;}
    break;

  case 279:
#line 3343 "Gmsh.y"
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

  case 280:
#line 3354 "Gmsh.y"
    {
      GModel::current()->makeDiscreteRegionsSimplyConnected();
      GModel::current()->makeDiscreteFacesSimplyConnected();
      GModel::current()->createTopologyFromMesh();
      // Warning: this clears GEO_Internals!
      GModel::current()->exportDiscreteGEOInternals();
    ;}
    break;

  case 281:
#line 3362 "Gmsh.y"
    {
      GModel::current()->classifySurfaces((yyvsp[(3) - (9)].d), (yyvsp[(5) - (9)].d), (yyvsp[(7) - (9)].d), M_PI);
    ;}
    break;

  case 282:
#line 3366 "Gmsh.y"
    {
      GModel::current()->classifySurfaces((yyvsp[(3) - (11)].d), (yyvsp[(5) - (11)].d), (yyvsp[(7) - (11)].d), (yyvsp[(9) - (11)].d));
    ;}
    break;

  case 283:
#line 3370 "Gmsh.y"
    {
      GModel::current()->createGeometryOfDiscreteEntities();
    ;}
    break;

  case 284:
#line 3374 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(3) - (4)].l), dimTags);
      GModel::current()->createGeometryOfDiscreteEntities(dimTags);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 285:
#line 3381 "Gmsh.y"
    {
      GModel::current()->renumberMeshVertices();
    ;}
    break;

  case 286:
#line 3385 "Gmsh.y"
    {
      GModel::current()->renumberMeshElements();
    ;}
    break;

  case 287:
#line 3389 "Gmsh.y"
    {
      GModel::current()->createMEdges();
    ;}
    break;

  case 288:
#line 3393 "Gmsh.y"
    {
      GModel::current()->createMFaces();
    ;}
    break;

  case 289:
#line 3397 "Gmsh.y"
    {
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      GModel::current()->synchronizeDiscreteCADInternals();
      if(GModel::current()->getGEOInternals()->getChanged())
        GModel::current()->getGEOInternals()->synchronize(GModel::current());
      GModel::current()->refineMesh(CTX::instance()->mesh.secondOrderLinear,
                                    CTX::instance()->mesh.algoSubdivide == 1,
                                    CTX::instance()->mesh.algoSubdivide == 2,
                                    CTX::instance()->mesh.algoSubdivide == 3);
    ;}
    break;

  case 290:
#line 3410 "Gmsh.y"
    {
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      GModel::current()->synchronizeDiscreteCADInternals();
      if(GModel::current()->getGEOInternals()->getChanged())
        GModel::current()->getGEOInternals()->synchronize(GModel::current());
      GModel::current()->recombineMesh();
    ;}
    break;

  case 291:
#line 3420 "Gmsh.y"
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

  case 292:
#line 3440 "Gmsh.y"
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

  case 293:
#line 3466 "Gmsh.y"
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

  case 294:
#line 3482 "Gmsh.y"
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

  case 295:
#line 3499 "Gmsh.y"
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

  case 296:
#line 3516 "Gmsh.y"
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

  case 297:
#line 3538 "Gmsh.y"
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

  case 298:
#line 3560 "Gmsh.y"
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

  case 299:
#line 3595 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip(nullptr, "Return");
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 300:
#line 3603 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip(nullptr, "Return");
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 301:
#line 3611 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    ;}
    break;

  case 302:
#line 3617 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function '%s'", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 303:
#line 3624 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function '%s'", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 304:
#line 3631 "Gmsh.y"
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

  case 305:
#line 3651 "Gmsh.y"
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

  case 306:
#line 3677 "Gmsh.y"
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

  case 307:
#line 3689 "Gmsh.y"
    {
      ImbricatedTest--;
      if(ImbricatedTest < 0)
        yymsg(1, "Orphan EndIf");
    ;}
    break;

  case 308:
#line 3700 "Gmsh.y"
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

  case 309:
#line 3718 "Gmsh.y"
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

  case 310:
#line 3736 "Gmsh.y"
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

  case 311:
#line 3754 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 312:
#line 3760 "Gmsh.y"
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

  case 313:
#line 3778 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 314:
#line 3784 "Gmsh.y"
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

  case 315:
#line 3804 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 316:
#line 3810 "Gmsh.y"
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

  case 317:
#line 3828 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 318:
#line 3834 "Gmsh.y"
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

  case 319:
#line 3851 "Gmsh.y"
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

  case 320:
#line 3867 "Gmsh.y"
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

  case 321:
#line 3884 "Gmsh.y"
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

  case 322:
#line 3902 "Gmsh.y"
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
#if defined(HAVE_DISCRETECAD)
      else if(gmsh_yyfactory == "Discrete" &&
              GModel::current()->getDiscreteCADInternals()){
        std::vector<int> regions, edges;
        ListOfDouble2Vector((yyvsp[(3) - (10)].l), regions); ListOfDouble2Vector((yyvsp[(6) - (10)].l), edges);
        std::vector<double> radii;
        ListOfDouble2Vector((yyvsp[(9) - (10)].l), radii);
        std::vector<std::pair<int, int> > outDimTags;
        r = GModel::current()->getDiscreteCADInternals()->fillet
          (regions, edges, radii, outDimTags, true);
        VectorOfPairs2ListOfShapes(outDimTags, (yyval.l));
      }
#endif
      else{
        yymsg(0, "Fillet only available with OpenCASCADE and Discrete geometry "
              "kernels");
      }
      if(!r) yymsg(0, "Could not fillet shapes");
      List_Delete((yyvsp[(3) - (10)].l));
      List_Delete((yyvsp[(6) - (10)].l));
      List_Delete((yyvsp[(9) - (10)].l));
    ;}
    break;

  case 323:
#line 3939 "Gmsh.y"
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

  case 324:
#line 3966 "Gmsh.y"
    {
    ;}
    break;

  case 325:
#line 3969 "Gmsh.y"
    {
    ;}
    break;

  case 326:
#line 3975 "Gmsh.y"
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
#line 3987 "Gmsh.y"
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
#line 4007 "Gmsh.y"
    {
      extr.mesh.ScaleLast = true;
    ;}
    break;

  case 329:
#line 4011 "Gmsh.y"
    {
      extr.mesh.Recombine = true;
    ;}
    break;

  case 330:
#line 4015 "Gmsh.y"
    {
      extr.mesh.Recombine = (yyvsp[(2) - (3)].d) ? true : false;
    ;}
    break;

  case 331:
#line 4019 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1;
    ;}
    break;

  case 332:
#line 4023 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1_RECOMB;
    ;}
    break;

  case 333:
#line 4027 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1;
    ;}
    break;

  case 334:
#line 4031 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1_RECOMB;
    ;}
    break;

  case 335:
#line 4035 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(6) - (9)].l), tags);
      int num = (int)(yyvsp[(3) - (9)].d);
      GModel::current()->getGEOInternals()->addDiscreteSurface(num);
      extr.mesh.Holes[num].first = (yyvsp[(8) - (9)].d);
      extr.mesh.Holes[num].second = tags;
      List_Delete((yyvsp[(6) - (9)].l));
    ;}
    break;

  case 336:
#line 4044 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (6)].c), "Index"))
        extr.mesh.BoundaryLayerIndex = (yyvsp[(4) - (6)].d);
      else if(!strcmp((yyvsp[(2) - (6)].c), "View"))
        extr.mesh.ViewIndex = (yyvsp[(4) - (6)].d);
      Free((yyvsp[(2) - (6)].c));
    ;}
    break;

  case 337:
#line 4056 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Union; ;}
    break;

  case 338:
#line 4057 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Intersection; ;}
    break;

  case 339:
#line 4058 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Difference; ;}
    break;

  case 340:
#line 4059 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Section; ;}
    break;

  case 341:
#line 4060 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Fragments; ;}
    break;

  case 342:
#line 4064 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 343:
#line 4065 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 344:
#line 4066 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 345:
#line 4067 "Gmsh.y"
    { (yyval.i) = (yyvsp[(2) - (3)].d) ? 1 : 0; ;}
    break;

  case 346:
#line 4068 "Gmsh.y"
    { (yyval.i) = (yyvsp[(3) - (4)].d) ? 2 : 0; ;}
    break;

  case 347:
#line 4073 "Gmsh.y"
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
#if defined(HAVE_DISCRETECAD)
      else if(gmsh_yyfactory == "Discrete" &&
              GModel::current()->getDiscreteCADInternals()){
        std::vector<std::pair<int, int > > object, tool, out;
        std::vector<std::vector<std::pair<int, int > > > outMap;
        ListOfShapes2VectorOfPairs((yyvsp[(3) - (9)].l), object);
        ListOfShapes2VectorOfPairs((yyvsp[(7) - (9)].l), tool);
        if((yyvsp[(1) - (9)].i) > OCC_Internals::Difference)
          yymsg(0, "Only BooleanUnion, BooleanIntersection and BooleanDifference "
                "available with the Discrete geometry kernel");
        else
          r = GModel::current()->getDiscreteCADInternals()->booleanOperation
            ((yyvsp[(1) - (9)].i), object, tool, out, outMap, -1, (yyvsp[(4) - (9)].i), (yyvsp[(8) - (9)].i));
        VectorOfPairs2ListOfShapes(out, (yyval.l));
      }
#endif
      else{
        yymsg(0, "Boolean operators only available with OpenCASCADE geometry kernel");
      }
      if(!r) yymsg(0, "Could not apply boolean operator");
      List_Delete((yyvsp[(3) - (9)].l));
      List_Delete((yyvsp[(7) - (9)].l));
    ;}
    break;

  case 348:
#line 4112 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        std::vector<std::pair<int, int> > out;
        std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
        GModel::current()->getOCCInternals()->importShapes(tmp, true, out);
        VectorOfPairs2ListOfShapes(out, (yyval.l));
      }
#if defined(HAVE_DISCRETECAD)
      else if(gmsh_yyfactory == "Discrete" &&
              GModel::current()->getDiscreteCADInternals()){
        std::vector<std::pair<int, int> > out;
        std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
        r = GModel::current()->getDiscreteCADInternals()->importTriangulations
          (tmp, out);
        VectorOfPairs2ListOfShapes(out, (yyval.l));
      }
#endif
      else{
        yymsg(0, "ShapeFromFile only available with OpenCASCADE and Discrete "
              "geometry kernels");
      }
      if(!r) yymsg(0, "Could import shape");
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 349:
#line 4139 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      DiscreteClassify((yyvsp[(3) - (7)].l), (yyvsp[(6) - (7)].d), M_PI, (yyval.l));
      List_Delete((yyvsp[(3) - (7)].l));
    ;}
    break;

  case 350:
#line 4145 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      DiscreteClassify((yyvsp[(3) - (9)].l), (yyvsp[(6) - (9)].d), (yyvsp[(8) - (9)].d), (yyval.l));
      List_Delete((yyvsp[(3) - (9)].l));
    ;}
    break;

  case 351:
#line 4151 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      DiscreteRecognize((yyvsp[(3) - (7)].l), (yyvsp[(6) - (7)].d), -1., (yyval.l));
      List_Delete((yyvsp[(3) - (7)].l));
    ;}
    break;

  case 352:
#line 4157 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      DiscreteRecognize((yyvsp[(3) - (9)].l), (yyvsp[(6) - (9)].d), (yyvsp[(8) - (9)].d), (yyval.l));
      List_Delete((yyvsp[(3) - (9)].l));
    ;}
    break;

  case 353:
#line 4163 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      DiscreteShapeFromFile((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d), M_PI, -1., (yyval.l));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 354:
#line 4169 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      DiscreteShapeFromFile((yyvsp[(3) - (8)].c), (yyvsp[(5) - (8)].d), (yyvsp[(7) - (8)].d), -1., (yyval.l));
      Free((yyvsp[(3) - (8)].c));
    ;}
    break;

  case 355:
#line 4175 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      DiscreteShapeFromFile((yyvsp[(3) - (10)].c), (yyvsp[(5) - (10)].d), (yyvsp[(7) - (10)].d), (yyvsp[(9) - (10)].d), (yyval.l));
      Free((yyvsp[(3) - (10)].c));
    ;}
    break;

  case 356:
#line 4185 "Gmsh.y"
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
#if defined(HAVE_DISCRETECAD)
      else if(gmsh_yyfactory == "Discrete" &&
              GModel::current()->getDiscreteCADInternals()){
        std::vector<std::pair<int, int> > object, tool, out;
        std::vector<std::vector<std::pair<int, int > > > outMap;
        ListOfShapes2VectorOfPairs((yyvsp[(7) - (14)].l), object);
        ListOfShapes2VectorOfPairs((yyvsp[(11) - (14)].l), tool);
        if((yyvsp[(1) - (14)].i) > OCC_Internals::Difference)
          yymsg(0, "Only BooleanUnion, BooleanIntersection and BooleanDifference "
                "available with the Discrete geometry kernel");
        else
          r = GModel::current()->getDiscreteCADInternals()->booleanOperation
            ((yyvsp[(1) - (14)].i), object, tool, out, outMap, (int)(yyvsp[(3) - (14)].d), (yyvsp[(8) - (14)].i), (yyvsp[(12) - (14)].i));
      }
#endif
      if(!r) yymsg(0, "Could not apply boolean operator");
      List_Delete((yyvsp[(7) - (14)].l));
      List_Delete((yyvsp[(11) - (14)].l));
    ;}
    break;

  case 357:
#line 4221 "Gmsh.y"
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    ;}
    break;

  case 358:
#line 4225 "Gmsh.y"
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

  case 359:
#line 4252 "Gmsh.y"
    {
      (yyval.i) = -1; // left
    ;}
    break;

  case 360:
#line 4256 "Gmsh.y"
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

  case 361:
#line 4272 "Gmsh.y"
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   ;}
    break;

  case 362:
#line 4276 "Gmsh.y"
    {
     (yyval.l) = (yyvsp[(2) - (2)].l);
   ;}
    break;

  case 363:
#line 4281 "Gmsh.y"
    {
      (yyval.i) = 45;
    ;}
    break;

  case 364:
#line 4285 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(2) - (2)].d);
    ;}
    break;

  case 365:
#line 4291 "Gmsh.y"
    {
      (yyval.l) = List_Create(1, 1, sizeof(double));
    ;}
    break;

  case 366:
#line 4295 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
    ;}
    break;

  case 367:
#line 4302 "Gmsh.y"
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

  case 368:
#line 4325 "Gmsh.y"
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

  case 369:
#line 4344 "Gmsh.y"
    {
      // transfinite constraints are stored in GEO internals in addition to
      // GModel, as they can be copied around during GEO operations
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      GModel::current()->synchronizeDiscreteCADInternals();
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

  case 370:
#line 4386 "Gmsh.y"
    {
      // transfinite constraints are stored in GEO internals in addition to
      // GModel, as they can be copied around during GEO operations
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      GModel::current()->synchronizeDiscreteCADInternals();
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

  case 371:
#line 4432 "Gmsh.y"
    {
      // transfinite constraints are stored in GEO internals in addition to
      // GModel, as they can be copied around during GEO operations
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      GModel::current()->synchronizeDiscreteCADInternals();
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

  case 372:
#line 4473 "Gmsh.y"
    {
      // transfinite constraints are stored in GEO internals in addition to
      // GModel, as they can be copied around during GEO operations
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      GModel::current()->synchronizeDiscreteCADInternals();
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

  case 373:
#line 4499 "Gmsh.y"
    {
      int dim = (int)(yyvsp[(2) - (8)].i);
      int tag = (int)(yyvsp[(4) - (8)].d);
      int new_tag = (int)(yyvsp[(6) - (8)].d);
      GModel::current()->changeEntityTag(dim, tag, new_tag);
    ;}
    break;

  case 374:
#line 4506 "Gmsh.y"
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

  case 375:
#line 4517 "Gmsh.y"
    {
      // mesh algorithm constraints are stored in GEO internals in addition to
      // GModel, as they can be copied around during GEO operations
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      GModel::current()->synchronizeDiscreteCADInternals();
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

  case 376:
#line 4535 "Gmsh.y"
    {
      // mesh size from boundary onstraints are stored in GEO internals in
      // addition to GModel, as they can be copied around during GEO operations
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      GModel::current()->synchronizeDiscreteCADInternals();
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

  case 377:
#line 4553 "Gmsh.y"
    {
      // recombine constraints are stored in GEO internals in addition to
      // GModel, as they can be copied around during GEO operations
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      GModel::current()->synchronizeDiscreteCADInternals();
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

  case 378:
#line 4584 "Gmsh.y"
    {
      // recombine constraints are stored in GEO internals in addition to
      // GModel, as they can be copied around during GEO operations
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      GModel::current()->synchronizeDiscreteCADInternals();
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

  case 379:
#line 4611 "Gmsh.y"
    {
      // smoothing constraints are stored in GEO internals in addition to
      // GModel, as they can be copied around during GEO operations
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      GModel::current()->synchronizeDiscreteCADInternals();
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

  case 380:
#line 4639 "Gmsh.y"
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

  case 381:
#line 4671 "Gmsh.y"
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

  case 382:
#line 4699 "Gmsh.y"
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

  case 383:
#line 4725 "Gmsh.y"
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

  case 384:
#line 4751 "Gmsh.y"
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

  case 385:
#line 4777 "Gmsh.y"
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

  case 386:
#line 4803 "Gmsh.y"
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

  case 387:
#line 4824 "Gmsh.y"
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

  case 388:
#line 4836 "Gmsh.y"
    {
      // reverse mesh constraints are stored in GEO internals in addition to
      // GModel, as they can be copied around during GEO operations
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      GModel::current()->synchronizeDiscreteCADInternals();
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

  case 389:
#line 4885 "Gmsh.y"
    {
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      GModel::current()->synchronizeDiscreteCADInternals();
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

  case 390:
#line 4940 "Gmsh.y"
    {
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      GModel::current()->synchronizeDiscreteCADInternals();
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

  case 391:
#line 4956 "Gmsh.y"
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

  case 392:
#line 4968 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (4)].l), tags);
      GModel::current()->getGEOInternals()->setCompoundMesh((yyvsp[(2) - (4)].i), tags);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 393:
#line 4974 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (6)].l), tags);
      tags.push_back(- (int) (yyvsp[(5) - (6)].d));
      GModel::current()->getGEOInternals()->setCompoundMesh((yyvsp[(2) - (6)].i), tags);
      List_Delete((yyvsp[(3) - (6)].l));
    ;}
    break;

  case 394:
#line 4986 "Gmsh.y"
    {
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals())
        GModel::current()->getOCCInternals()->removeAllDuplicates();
      else
        GModel::current()->getGEOInternals()->removeAllDuplicates();
    ;}
    break;

  case 395:
#line 4993 "Gmsh.y"
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

  case 396:
#line 5008 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(4) - (6)].l), tags);
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals())
        GModel::current()->getOCCInternals()->mergeVertices(tags);
      else
        GModel::current()->getGEOInternals()->mergeVertices(tags);
      List_Delete((yyvsp[(4) - (6)].l));
    ;}
    break;

  case 397:
#line 5017 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > in, out;
      ListOfShapes2VectorOfPairs((yyvsp[(3) - (4)].l), in);
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()) {
        GModel::current()->getOCCInternals()->healShapes
          (in, out, CTX::instance()->geom.tolerance,
           CTX::instance()->geom.occFixDegenerated,
           CTX::instance()->geom.occFixSmallEdges,
           CTX::instance()->geom.occFixSmallFaces,
           CTX::instance()->geom.occSewFaces,
           CTX::instance()->geom.occMakeSolids);
      }
#if defined(HAVE_DISCRETECAD)
      else if(gmsh_yyfactory == "Discrete" &&
              GModel::current()->getDiscreteCADInternals()) {
        std::vector<int> surfaces;
        for(auto &p : in) {
          if(p.first == 2) surfaces.push_back(p.second);
          else yymsg(0, "HealShapes only heals surfaces with the Discrete "
                     "geometry kernel");
        }
        if(!GModel::current()->getDiscreteCADInternals()->heal(surfaces))
          yymsg(0, "Could not heal shapes");
      }
#endif
      else {
        yymsg(0, "HealShapes only available with OpenCASCADE and Discrete "
              "geometry kernels");
      }
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 398:
#line 5049 "Gmsh.y"
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
#if defined(HAVE_DISCRETECAD)
      else if(gmsh_yyfactory == "Discrete" &&
              GModel::current()->getDiscreteCADInternals()) {
        if(!GModel::current()->getDiscreteCADInternals()->heal
           (std::vector<int>()))
          yymsg(0, "Could not heal shapes");
      }
#endif
      else {
        yymsg(0, "HealShapes only available with OpenCASCADE geometry kernel");
      }
    ;}
    break;

  case 399:
#line 5077 "Gmsh.y"
    { (yyval.c) = (char*)"Homology"; ;}
    break;

  case 400:
#line 5078 "Gmsh.y"
    { (yyval.c) = (char*)"Cohomology"; ;}
    break;

  case 401:
#line 5079 "Gmsh.y"
    { (yyval.c) = (char*)"Betti"; ;}
    break;

  case 402:
#line 5084 "Gmsh.y"
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest((yyvsp[(1) - (2)].c), domain, subdomain, dim);
    ;}
    break;

  case 403:
#line 5090 "Gmsh.y"
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
#line 5102 "Gmsh.y"
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
#line 5120 "Gmsh.y"
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
#line 5147 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d);           ;}
    break;

  case 407:
#line 5148 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (3)].d);           ;}
    break;

  case 408:
#line 5149 "Gmsh.y"
    { (yyval.d) = -(yyvsp[(2) - (2)].d);          ;}
    break;

  case 409:
#line 5150 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);           ;}
    break;

  case 410:
#line 5151 "Gmsh.y"
    { (yyval.d) = !(yyvsp[(2) - (2)].d);          ;}
    break;

  case 411:
#line 5152 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) - (yyvsp[(3) - (3)].d);      ;}
    break;

  case 412:
#line 5153 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) + (yyvsp[(3) - (3)].d);      ;}
    break;

  case 413:
#line 5154 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) * (yyvsp[(3) - (3)].d);      ;}
    break;

  case 414:
#line 5156 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (3)].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));
      else
	(yyval.d) = (yyvsp[(1) - (3)].d) / (yyvsp[(3) - (3)].d);
    ;}
    break;

  case 415:
#line 5162 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) | (int)(yyvsp[(3) - (3)].d); ;}
    break;

  case 416:
#line 5163 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) & (int)(yyvsp[(3) - (3)].d); ;}
    break;

  case 417:
#line 5164 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) % (int)(yyvsp[(3) - (3)].d); ;}
    break;

  case 418:
#line 5165 "Gmsh.y"
    { (yyval.d) = pow((yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));  ;}
    break;

  case 419:
#line 5166 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d);      ;}
    break;

  case 420:
#line 5167 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) > (yyvsp[(3) - (3)].d);      ;}
    break;

  case 421:
#line 5168 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) <= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 422:
#line 5169 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) >= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 423:
#line 5170 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) == (yyvsp[(3) - (3)].d);     ;}
    break;

  case 424:
#line 5171 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) != (yyvsp[(3) - (3)].d);     ;}
    break;

  case 425:
#line 5172 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) && (yyvsp[(3) - (3)].d);     ;}
    break;

  case 426:
#line 5173 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) || (yyvsp[(3) - (3)].d);     ;}
    break;

  case 427:
#line 5174 "Gmsh.y"
    { (yyval.d) = ((int)(yyvsp[(1) - (3)].d) >> (int)(yyvsp[(3) - (3)].d)); ;}
    break;

  case 428:
#line 5175 "Gmsh.y"
    { (yyval.d) = ((int)(yyvsp[(1) - (3)].d) << (int)(yyvsp[(3) - (3)].d)); ;}
    break;

  case 429:
#line 5176 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (5)].d) ? (yyvsp[(3) - (5)].d) : (yyvsp[(5) - (5)].d); ;}
    break;

  case 430:
#line 5177 "Gmsh.y"
    { (yyval.d) = ((yyvsp[(3) - (4)].d) < 0) ? 0 : 1; ;}
    break;

  case 431:
#line 5178 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 432:
#line 5179 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 433:
#line 5180 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 434:
#line 5181 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 435:
#line 5182 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 436:
#line 5183 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 437:
#line 5184 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 438:
#line 5185 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 439:
#line 5186 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 440:
#line 5187 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 441:
#line 5188 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 442:
#line 5189 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 443:
#line 5190 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 444:
#line 5191 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 445:
#line 5192 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 446:
#line 5193 "Gmsh.y"
    { (yyval.d) = std::abs((yyvsp[(3) - (4)].d)); ;}
    break;

  case 447:
#line 5194 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 448:
#line 5195 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 449:
#line 5196 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d) + 0.5); ;}
    break;

  case 450:
#line 5197 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 451:
#line 5198 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 452:
#line 5199 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 453:
#line 5200 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 454:
#line 5201 "Gmsh.y"
    { (yyval.d) = std::max((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 455:
#line 5202 "Gmsh.y"
    { (yyval.d) = std::min((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 456:
#line 5211 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 457:
#line 5212 "Gmsh.y"
    { (yyval.d) = 3.141592653589793; ;}
    break;

  case 458:
#line 5213 "Gmsh.y"
    { (yyval.d) = (double)ImbricatedTest; ;}
    break;

  case 459:
#line 5214 "Gmsh.y"
    { (yyval.d) = Msg::GetCommRank(); ;}
    break;

  case 460:
#line 5215 "Gmsh.y"
    { (yyval.d) = Msg::GetCommSize(); ;}
    break;

  case 461:
#line 5216 "Gmsh.y"
    { (yyval.d) = GetGmshMajorVersion(); ;}
    break;

  case 462:
#line 5217 "Gmsh.y"
    { (yyval.d) = GetGmshMinorVersion(); ;}
    break;

  case 463:
#line 5218 "Gmsh.y"
    { (yyval.d) = GetGmshPatchVersion(); ;}
    break;

  case 464:
#line 5219 "Gmsh.y"
    { (yyval.d) = Cpu(); ;}
    break;

  case 465:
#line 5220 "Gmsh.y"
    { (yyval.d) = GetMemoryUsage()/1024./1024.; ;}
    break;

  case 466:
#line 5221 "Gmsh.y"
    { (yyval.d) = TotalRam(); ;}
    break;

  case 467:
#line 5226 "Gmsh.y"
    { init_options(); ;}
    break;

  case 468:
#line 5228 "Gmsh.y"
    {
      std::vector<double> val(1, (yyvsp[(3) - (6)].d));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.d) = val[0];
    ;}
    break;

  case 469:
#line 5234 "Gmsh.y"
    {
      (yyval.d) = (yyvsp[(1) - (1)].d);
    ;}
    break;

  case 470:
#line 5238 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 471:
#line 5243 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 472:
#line 5248 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(1) - (1)].c2).char1, (yyvsp[(1) - (1)].c2).char2);
    ;}
    break;

  case 473:
#line 5253 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float(nullptr, (yyvsp[(1) - (4)].c), 2, (int)(yyvsp[(3) - (4)].d));
    ;}
    break;

  case 474:
#line 5258 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float(nullptr, (yyvsp[(1) - (4)].c), 2, (int)(yyvsp[(3) - (4)].d));
    ;}
    break;

  case 475:
#line 5262 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(3) - (4)].c2).char1, (yyvsp[(3) - (4)].c2).char2, 1, 0, 0., 1);
    ;}
    break;

  case 476:
#line 5266 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(3) - (6)].c2).char1, (yyvsp[(3) - (6)].c2).char2, (yyvsp[(5) - (6)].c), 0, 0., 1);
    ;}
    break;

  case 477:
#line 5270 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(3) - (5)].c2).char1, (yyvsp[(3) - (5)].c2).char2, 1, 0, (yyvsp[(4) - (5)].d), 2);
    ;}
    break;

  case 478:
#line 5274 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(3) - (7)].c2).char1, (yyvsp[(3) - (7)].c2).char2, (yyvsp[(5) - (7)].c), 0, (yyvsp[(6) - (7)].d), 2);
    ;}
    break;

  case 479:
#line 5278 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(3) - (8)].c2).char1, (yyvsp[(3) - (8)].c2).char2, 2, (int)(yyvsp[(5) - (8)].d), (yyvsp[(7) - (8)].d), 2);
    ;}
    break;

  case 480:
#line 5282 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(3) - (10)].c2).char1, (yyvsp[(3) - (10)].c2).char2, (yyvsp[(5) - (10)].c), (int)(yyvsp[(7) - (10)].d), (yyvsp[(9) - (10)].d), 2);
    ;}
    break;

  case 481:
#line 5286 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.d) = !StatFile(tmp);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 482:
#line 5292 "Gmsh.y"
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

  case 483:
#line 5307 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float_getDim((yyvsp[(2) - (6)].c2).char1, (yyvsp[(2) - (6)].c2).char2, (yyvsp[(4) - (6)].c));
    ;}
    break;

  case 484:
#line 5311 "Gmsh.y"
    {
      std::string struct_namespace((yyvsp[(3) - (4)].c));
      (yyval.d) = (double)gmsh_yynamespaces[struct_namespace].size();
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 485:
#line 5317 "Gmsh.y"
    {
      std::string struct_namespace(std::string(""));
      (yyval.d) = (double)gmsh_yynamespaces[struct_namespace].size();
    ;}
    break;

  case 486:
#line 5322 "Gmsh.y"
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

  case 487:
#line 5341 "Gmsh.y"
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

  case 488:
#line 5361 "Gmsh.y"
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

  case 489:
#line 5382 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(nullptr, (yyvsp[(1) - (3)].c), (yyvsp[(3) - (3)].c));
    ;}
    break;

  case 490:
#line 5386 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c), (yyvsp[(5) - (5)].c));
    ;}
    break;

  case 491:
#line 5390 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(nullptr, (yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].c), (int)(yyvsp[(5) - (6)].d));
    ;}
    break;

  case 492:
#line 5394 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(1) - (8)].c), (yyvsp[(3) - (8)].c), (yyvsp[(5) - (8)].c), (int)(yyvsp[(7) - (8)].d));
    ;}
    break;

  case 493:
#line 5398 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(nullptr, (yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].c), (int)(yyvsp[(5) - (6)].d));
    ;}
    break;

  case 494:
#line 5402 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(1) - (8)].c), (yyvsp[(3) - (8)].c), (yyvsp[(5) - (8)].c), (int)(yyvsp[(7) - (8)].d));
    ;}
    break;

  case 495:
#line 5406 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), (yyval.d));
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 496:
#line 5411 "Gmsh.y"
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

  case 497:
#line 5421 "Gmsh.y"
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

  case 498:
#line 5431 "Gmsh.y"
    {
      (yyval.d) = Msg::GetValue((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 499:
#line 5436 "Gmsh.y"
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

  case 500:
#line 5447 "Gmsh.y"
    {
      std::string s((yyvsp[(3) - (6)].c)), substr((yyvsp[(5) - (6)].c));
      if(s.find(substr) != std::string::npos)
        (yyval.d) = 1.;
      else
        (yyval.d) = 0.;
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 501:
#line 5456 "Gmsh.y"
    {
      (yyval.d) = strlen((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 502:
#line 5461 "Gmsh.y"
    {
      (yyval.d) = strcmp((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 503:
#line 5466 "Gmsh.y"
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

  case 504:
#line 5493 "Gmsh.y"
    { (yyval.d) = 0.; ;}
    break;

  case 505:
#line 5495 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);;}
    break;

  case 506:
#line 5500 "Gmsh.y"
    { (yyval.c) = nullptr; ;}
    break;

  case 507:
#line 5502 "Gmsh.y"
    { (yyval.c) = (yyvsp[(2) - (2)].c);;}
    break;

  case 508:
#line 5507 "Gmsh.y"
    {
      std::string struct_namespace((yyvsp[(2) - (3)].c2).char1? (yyvsp[(2) - (3)].c2).char1 : std::string("")),
        struct_name((yyvsp[(2) - (3)].c2).char2);
      init_options
        (gmsh_yynamespaces.getMember_ValMax(struct_namespace, struct_name));
    ;}
    break;

  case 509:
#line 5514 "Gmsh.y"
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

  case 510:
#line 5530 "Gmsh.y"
    { (yyval.c2).char1 = nullptr; (yyval.c2).char2 = (yyvsp[(1) - (1)].c); ;}
    break;

  case 511:
#line 5532 "Gmsh.y"
    { (yyval.c2).char1 = (yyvsp[(1) - (3)].c); (yyval.c2).char2 = (yyvsp[(3) - (3)].c); ;}
    break;

  case 512:
#line 5537 "Gmsh.y"
    { (yyval.i) = 99; ;}
    break;

  case 513:
#line 5539 "Gmsh.y"
    { (yyval.i) = (int)(yyvsp[(2) - (2)].d); ;}
    break;

  case 514:
#line 5544 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 515:
#line 5546 "Gmsh.y"
    { (yyval.i) = (yyvsp[(2) - (3)].i); ;}
    break;

  case 516:
#line 5551 "Gmsh.y"
    {
      memcpy((yyval.v), (yyvsp[(1) - (1)].v), 5 * sizeof(double));
    ;}
    break;

  case 517:
#line 5555 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 518:
#line 5559 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 519:
#line 5563 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] - (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 520:
#line 5567 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] + (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 521:
#line 5574 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (11)].d);  (yyval.v)[1] = (yyvsp[(4) - (11)].d);  (yyval.v)[2] = (yyvsp[(6) - (11)].d);  (yyval.v)[3] = (yyvsp[(8) - (11)].d); (yyval.v)[4] = (yyvsp[(10) - (11)].d);
    ;}
    break;

  case 522:
#line 5578 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (9)].d);  (yyval.v)[1] = (yyvsp[(4) - (9)].d);  (yyval.v)[2] = (yyvsp[(6) - (9)].d);  (yyval.v)[3] = (yyvsp[(8) - (9)].d); (yyval.v)[4] = 1.0;
    ;}
    break;

  case 523:
#line 5582 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 524:
#line 5586 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 525:
#line 5593 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].l)));
    ;}
    break;

  case 526:
#line 5598 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].l)));
    ;}
    break;

  case 527:
#line 5605 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 528:
#line 5610 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 529:
#line 5614 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
    ;}
    break;

  case 530:
#line 5618 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 531:
#line 5622 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 532:
#line 5630 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (5)].d);
      }
    ;}
    break;

  case 533:
#line 5641 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
    ;}
    break;

  case 534:
#line 5645 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 535:
#line 5649 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 536:
#line 5660 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 537:
#line 5664 "Gmsh.y"
    {
      (yyval.l) = 0;
    ;}
    break;

  case 538:
#line 5668 "Gmsh.y"
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

  case 539:
#line 5682 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 540:
#line 5690 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (3)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (3)].d);
      }
    ;}
    break;

  case 541:
#line 5698 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      for(double d = (yyvsp[(1) - (3)].d); ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d <= (yyvsp[(3) - (3)].d)) : (d >= (yyvsp[(3) - (3)].d));
          ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d += 1.) : (d -= 1.))
	List_Add((yyval.l), &d);
    ;}
    break;

  case 542:
#line 5705 "Gmsh.y"
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

  case 543:
#line 5715 "Gmsh.y"
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

  case 544:
#line 5738 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags(0, (yyval.l));
    ;}
    break;

  case 545:
#line 5743 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags(0, (yyval.l));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 546:
#line 5749 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags((yyvsp[(1) - (4)].i), (yyval.l));
    ;}
    break;

  case 547:
#line 5754 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags((yyvsp[(1) - (2)].i), (yyval.l));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 548:
#line 5760 "Gmsh.y"
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

  case 549:
#line 5771 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getElementaryTagsForPhysicalNames((yyvsp[(2) - (5)].i), (yyvsp[(4) - (5)].l), (yyval.l));
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 550:
#line 5777 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getParentTags((yyvsp[(2) - (3)].i), (yyvsp[(3) - (3)].l), (yyval.l));
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 551:
#line 5783 "Gmsh.y"
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

  case 552:
#line 5797 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getBoundingBox((yyvsp[(2) - (5)].i), (yyvsp[(4) - (5)].l), (yyval.l));
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 553:
#line 5803 "Gmsh.y"
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

  case 554:
#line 5815 "Gmsh.y"
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

  case 555:
#line 5829 "Gmsh.y"
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

  case 556:
#line 5842 "Gmsh.y"
    {
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      GModel::current()->synchronizeDiscreteCADInternals();
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

  case 557:
#line 5873 "Gmsh.y"
    {
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      GModel::current()->synchronizeDiscreteCADInternals();
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

  case 558:
#line 5897 "Gmsh.y"
    {
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      GModel::current()->synchronizeDiscreteCADInternals();
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

  case 559:
#line 5918 "Gmsh.y"
    {
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      GModel::current()->synchronizeDiscreteCADInternals();
      if(GModel::current()->getGEOInternals()->getChanged())
        GModel::current()->getGEOInternals()->synchronize(GModel::current());
      (yyval.l) = List_Create(9, 1, sizeof(double));
      int tag = (int)(yyvsp[(4) - (9)].d);
      GEdge *ge = GModel::current()->getEdgeByTag(tag);
      if(ge) {
        double c = ge->curvature((yyvsp[(8) - (9)].d));
        List_Add((yyval.l), &c);
      }
      else {
        yymsg(0, "Curve %d does not exist", tag);
      }
    ;}
    break;

  case 560:
#line 5938 "Gmsh.y"
    {
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      GModel::current()->synchronizeDiscreteCADInternals();
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

  case 561:
#line 5959 "Gmsh.y"
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

  case 562:
#line 5976 "Gmsh.y"
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

  case 563:
#line 5986 "Gmsh.y"
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

  case 564:
#line 5996 "Gmsh.y"
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
#line 6006 "Gmsh.y"
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

  case 566:
#line 6018 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfFloat(nullptr, (yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c));
    ;}
    break;

  case 567:
#line 6022 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfFloat((yyvsp[(1) - (7)].c), (yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].c));
    ;}
    break;

  case 568:
#line 6027 "Gmsh.y"
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

  case 569:
#line 6039 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 570:
#line 6043 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 571:
#line 6047 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (6)].l);
    ;}
    break;

  case 572:
#line 6051 "Gmsh.y"
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

  case 573:
#line 6069 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = (yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1);
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 574:
#line 6077 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = pow(10,(yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1));
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 575:
#line 6085 "Gmsh.y"
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

  case 576:
#line 6114 "Gmsh.y"
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

  case 577:
#line 6124 "Gmsh.y"
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

  case 578:
#line 6140 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
        double *d = (double*)List_Pointer((yyvsp[(3) - (4)].l), i);
        *d = std::abs(*d);
      }
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 579:
#line 6151 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 580:
#line 6156 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 581:
#line 6160 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].d)));
    ;}
    break;

  case 582:
#line 6164 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (3)].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 583:
#line 6176 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(char*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].c)));
    ;}
    break;

  case 584:
#line 6181 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].c)));
    ;}
    break;

  case 585:
#line 6188 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (9)].d), (int)(yyvsp[(4) - (9)].d), (int)(yyvsp[(6) - (9)].d), (int)(yyvsp[(8) - (9)].d));
    ;}
    break;

  case 586:
#line 6192 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (7)].d), (int)(yyvsp[(4) - (7)].d), (int)(yyvsp[(6) - (7)].d), 255);
    ;}
    break;

  case 587:
#line 6204 "Gmsh.y"
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
#line 6221 "Gmsh.y"
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(5) - (5)].c), val);
      (yyval.u) = val;
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(5) - (5)].c));
    ;}
    break;

  case 589:
#line 6231 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 590:
#line 6235 "Gmsh.y"
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
#line 6250 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].u)));
    ;}
    break;

  case 592:
#line 6255 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].u)));
    ;}
    break;

  case 593:
#line 6262 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 594:
#line 6266 "Gmsh.y"
    {
      // No need to extend to Struct_FullName (a Tag is not a String)
      (yyval.c) = treat_Struct_FullName_String(nullptr, (yyvsp[(1) - (1)].c));
    ;}
    break;

  case 595:
#line 6271 "Gmsh.y"
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
#line 6285 "Gmsh.y"
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
#line 6299 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String(nullptr, (yyvsp[(1) - (3)].c), (yyvsp[(3) - (3)].c));
    ;}
    break;

  case 598:
#line 6303 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c), (yyvsp[(5) - (5)].c));
    ;}
    break;

  case 599:
#line 6307 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String(nullptr, (yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].c), (int)(yyvsp[(5) - (6)].d));
    ;}
    break;

  case 600:
#line 6311 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(1) - (8)].c), (yyvsp[(3) - (8)].c), (yyvsp[(5) - (8)].c), (int)(yyvsp[(7) - (8)].d));
    ;}
    break;

  case 601:
#line 6315 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 602:
#line 6323 "Gmsh.y"
    {
      std::string name = GModel::current()->getElementaryName((yyvsp[(1) - (4)].i), (int)(yyvsp[(3) - (4)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 603:
#line 6329 "Gmsh.y"
    {
      std::string name = GModel::current()->getPhysicalName((yyvsp[(2) - (5)].i), (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 604:
#line 6338 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 605:
#line 6342 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 606:
#line 6346 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    ;}
    break;

  case 607:
#line 6354 "Gmsh.y"
    {
      std::string exe = Msg::GetExecutableName();
      (yyval.c) = (char *)Malloc(exe.size() + 1);
      strcpy((yyval.c), exe.c_str());
    ;}
    break;

  case 608:
#line 6360 "Gmsh.y"
    {
      std::string action = Msg::GetOnelabAction();
      (yyval.c) = (char *)Malloc(action.size() + 1);
      strcpy((yyval.c), action.c_str());
    ;}
    break;

  case 609:
#line 6366 "Gmsh.y"
    {
      (yyval.c) = strsave((char*)"Gmsh");
    ;}
    break;

  case 610:
#line 6370 "Gmsh.y"
    {
      std::string env = GetEnvironmentVar((yyvsp[(3) - (4)].c));
      (yyval.c) = (char *)Malloc((env.size() + 1) * sizeof(char));
      strcpy((yyval.c), env.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 611:
#line 6377 "Gmsh.y"
    {
      std::string s = Msg::GetString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 612:
#line 6385 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (4)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 613:
#line 6392 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 614:
#line 6401 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_String(nullptr, (yyvsp[(3) - (5)].c2).char2, 1, 0, (yyvsp[(4) - (5)].c), 2);
    ;}
    break;

  case 615:
#line 6405 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(3) - (7)].c2).char1, (yyvsp[(3) - (7)].c2).char2, (yyvsp[(5) - (7)].c), 0, (yyvsp[(6) - (7)].c), 2);
    ;}
    break;

  case 616:
#line 6409 "Gmsh.y"
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
#line 6424 "Gmsh.y"
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
#line 6438 "Gmsh.y"
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
#line 6452 "Gmsh.y"
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
#line 6464 "Gmsh.y"
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
#line 6480 "Gmsh.y"
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
#line 6489 "Gmsh.y"
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
#line 6498 "Gmsh.y"
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
#line 6508 "Gmsh.y"
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
#line 6519 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (8)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (8)].d), (int)(yyvsp[(7) - (8)].d));
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (8)].c));
    ;}
    break;

  case 626:
#line 6527 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (6)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (6)].d), std::string::npos);
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 627:
#line 6535 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 628:
#line 6539 "Gmsh.y"
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
#line 6557 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 630:
#line 6564 "Gmsh.y"
    {
      std::string tmp = SplitFileName(GetAbsolutePath(gmsh_yyname))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
    ;}
    break;

  case 631:
#line 6570 "Gmsh.y"
    {
      std::string tmp = GetFileNameWithoutPath(gmsh_yyname);
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
    ;}
    break;

  case 632:
#line 6576 "Gmsh.y"
    {
      std::string tmp = SplitFileName((yyvsp[(3) - (4)].c))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 633:
#line 6583 "Gmsh.y"
    {
      std::string tmp = GetAbsolutePath((yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 634:
#line 6590 "Gmsh.y"
    { init_options(); ;}
    break;

  case 635:
#line 6592 "Gmsh.y"
    {
      std::string val((yyvsp[(3) - (6)].c));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.c) = (char*)Malloc((val.size() + 1) * sizeof(char));
      strcpy((yyval.c), val.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 636:
#line 6600 "Gmsh.y"
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
#line 6624 "Gmsh.y"
    { struct_namespace = std::string(""); (yyval.d) = (yyvsp[(2) - (2)].d); ;}
    break;

  case 638:
#line 6626 "Gmsh.y"
    { struct_namespace = (yyvsp[(1) - (4)].c); Free((yyvsp[(1) - (4)].c)); (yyval.d) = (yyvsp[(4) - (4)].d); ;}
    break;

  case 639:
#line 6632 "Gmsh.y"
    { (yyval.l) = (yyvsp[(3) - (4)].l); ;}
    break;

  case 640:
#line 6637 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 641:
#line 6639 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 642:
#line 6644 "Gmsh.y"
    { (yyval.l) = (yyvsp[(2) - (3)].l); ;}
    break;

  case 643:
#line 6649 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].c)));
    ;}
    break;

  case 644:
#line 6654 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 645:
#line 6656 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].c)));
    ;}
    break;

  case 646:
#line 6660 "Gmsh.y"
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
#line 6672 "Gmsh.y"
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
#line 6686 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfString(nullptr, (yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c));
    ;}
    break;

  case 649:
#line 6690 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfString((yyvsp[(1) - (7)].c), (yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].c));
    ;}
    break;

  case 650:
#line 6697 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr) + 1) * sizeof(char));
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 651:
#line 6705 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr) + 1) * sizeof(char)) ;
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)) ; strcat((yyval.c), tmpstr) ;
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 652:
#line 6713 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(7) - (8)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(3) - (8)].c))+strlen(tmpstr) + 1) * sizeof(char));
      strcpy((yyval.c), (yyvsp[(3) - (8)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(3) - (8)].c));
    ;}
    break;

  case 653:
#line 6724 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 654:
#line 6726 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 655:
#line 6729 "Gmsh.y"
    { (yyval.c) = (yyvsp[(3) - (4)].c); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 15234 "Gmsh.tab.cpp"
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


#line 6732 "Gmsh.y"


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

// the triangulations of a mesh file imported in the discrete CAD modeler, and
// their topology (surfaces split where the normals turn by more than angle,
// curves where they turn by more than curveAngle, analytic surfaces
// recognized within tolerance)
void DiscreteShapeFromFile(const char *fileName, double angle,
                           double curveAngle, double tolerance,
                           List_T *shapes)
{
#if defined(HAVE_DISCRETECAD)
  if(gmsh_yyfactory == "Discrete" &&
     GModel::current()->getDiscreteCADInternals()){
    std::vector<std::pair<int, int> > out;
    std::string tmp = FixRelativePath(gmsh_yyname, fileName);
    if(!GModel::current()->getDiscreteCADInternals()->importShapes
       (tmp, angle, curveAngle, tolerance, out))
      yymsg(0, "Could not import shape");
    VectorOfPairs2ListOfShapes(out, shapes);
    return;
  }
#endif
  yymsg(0, "ShapeFromFile with angles only available with Discrete geometry "
        "kernel");
}

// the raw surfaces of the discrete CAD modeler (all of them if the list is
// empty) replaced by their topology: surfaces split where the normals turn by
// more than angle, curves where they turn by more than curveAngle
void DiscreteClassify(List_T *list, double angle, double curveAngle,
                      List_T *shapes)
{
#if defined(HAVE_DISCRETECAD)
  if(gmsh_yyfactory == "Discrete" &&
     GModel::current()->getDiscreteCADInternals()){
    std::vector<std::pair<int, int> > in, out;
    ListOfShapes2VectorOfPairs(list, in);
    std::vector<int> surfaces;
    for(auto &p : in) {
      if(p.first == 2) surfaces.push_back(p.second);
      else yymsg(0, "ClassifySurfaces only classifies surfaces");
    }
    if(!GModel::current()->getDiscreteCADInternals()->classify
       (surfaces, angle, curveAngle, out))
      yymsg(0, "Could not classify surfaces");
    VectorOfPairs2ListOfShapes(out, shapes);
    return;
  }
#endif
  yymsg(0, "ClassifySurfaces of shapes only available with Discrete geometry "
        "kernel");
}

// the analytic surfaces of shapes of the discrete CAD modeler (the normals of
// their triangles within angle of those of the surfaces, their nodes within
// tolerance)
void DiscreteRecognize(List_T *list, double angle, double tolerance,
                       List_T *shapes)
{
#if defined(HAVE_DISCRETECAD)
  if(gmsh_yyfactory == "Discrete" &&
     GModel::current()->getDiscreteCADInternals()){
    std::vector<std::pair<int, int> > in, out;
    ListOfShapes2VectorOfPairs(list, in);
    if(!GModel::current()->getDiscreteCADInternals()->recognize
       (in, angle, tolerance, out))
      yymsg(0, "Could not recognize shapes");
    VectorOfPairs2ListOfShapes(out, shapes);
    return;
  }
#endif
  yymsg(0, "RecognizeShapes only available with Discrete geometry kernel");
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
  GModel::current()->synchronizeDiscreteCADInternals();
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
  GModel::current()->synchronizeDiscreteCADInternals();
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
  GModel::current()->synchronizeDiscreteCADInternals();
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
  GModel::current()->synchronizeDiscreteCADInternals();
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
  GModel::current()->synchronizeDiscreteCADInternals();
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
  GModel::current()->synchronizeDiscreteCADInternals();
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
  GModel::current()->synchronizeDiscreteCADInternals();
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
  GModel::current()->synchronizeDiscreteCADInternals();
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

void getElementaryTagsForPhysicalNames(int dim, List_T *in, List_T *out)
{
  if(GModel::current()->getOCCInternals() &&
     GModel::current()->getOCCInternals()->getChanged())
    GModel::current()->getOCCInternals()->synchronize(GModel::current());
  GModel::current()->synchronizeDiscreteCADInternals();
  if(GModel::current()->getGEOInternals()->getChanged())
    GModel::current()->getGEOInternals()->synchronize(GModel::current());

  List_T *tags = List_Create(10, 10, sizeof(double));
  for(int i = 0; i < List_Nbr(in); i++){
    char *name;
    List_Read(in, i, &name);
    double num = GModel::current()->getPhysicalNumber(dim, name);
    if(num < 0)
      yymsg(0, "Unknown physical group '%s' of dimension %d", name, dim);
    else
      List_Add(tags, &num);
    Free(name);
  }
  getElementaryTagsForPhysicalGroups(dim, tags, out);
  List_Delete(tags);
}

void getElementaryTagsInBoundingBox(int dim, double x1, double y1, double z1,
                                    double x2, double y2, double z2, List_T *out)
{
  if(GModel::current()->getOCCInternals() &&
     GModel::current()->getOCCInternals()->getChanged())
    GModel::current()->getOCCInternals()->synchronize(GModel::current());
  GModel::current()->synchronizeDiscreteCADInternals();
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
  GModel::current()->synchronizeDiscreteCADInternals();
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
  GModel::current()->synchronizeDiscreteCADInternals();
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
  GModel::current()->synchronizeDiscreteCADInternals();
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
  GModel::current()->synchronizeDiscreteCADInternals();
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
  GModel::current()->synchronizeDiscreteCADInternals();
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

