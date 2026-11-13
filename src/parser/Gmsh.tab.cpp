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
#define YYLAST   18603

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  276
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  115
/* YYNRULES -- Number of rules.  */
#define YYNRULES  659
/* YYNRULES -- Number of states.  */
#define YYNSTATES  2289

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
      24,    26,    28,    31,    33,    36,    38,    40,    42,    44,
      47,    49,    52,    54,    56,    58,    60,    62,    64,    66,
      68,    70,    76,    82,    88,    96,   104,   112,   120,   130,
     137,   144,   151,   160,   161,   164,   167,   170,   173,   176,
     179,   181,   185,   187,   191,   192,   193,   204,   206,   210,
     211,   225,   227,   231,   232,   248,   257,   272,   273,   280,
     282,   284,   286,   288,   290,   292,   294,   296,   298,   300,
     302,   304,   306,   308,   310,   312,   314,   320,   326,   329,
     337,   345,   350,   354,   361,   371,   379,   386,   394,   401,
     406,   415,   425,   435,   442,   452,   459,   469,   475,   484,
     493,   505,   512,   522,   528,   536,   546,   556,   566,   574,
     584,   594,   595,   597,   598,   602,   608,   609,   619,   620,
     632,   638,   639,   649,   650,   654,   658,   664,   670,   671,
     674,   675,   677,   679,   683,   686,   689,   692,   695,   697,
     702,   705,   708,   709,   712,   714,   718,   721,   724,   727,
     730,   733,   735,   737,   741,   742,   748,   754,   760,   761,
     764,   765,   768,   776,   784,   792,   803,   814,   823,   832,
     840,   848,   860,   868,   877,   886,   895,   905,   914,   923,
     927,   932,   943,   951,   959,   967,   975,   983,   991,   999,
    1007,  1015,  1023,  1033,  1041,  1049,  1058,  1067,  1080,  1081,
    1091,  1093,  1095,  1097,  1099,  1104,  1106,  1108,  1110,  1115,
    1117,  1119,  1124,  1126,  1128,  1130,  1135,  1141,  1153,  1159,
    1169,  1179,  1187,  1195,  1200,  1210,  1221,  1231,  1233,  1235,
    1236,  1239,  1246,  1254,  1262,  1270,  1277,  1285,  1290,  1296,
    1302,  1309,  1316,  1320,  1325,  1329,  1335,  1342,  1348,  1353,
    1357,  1362,  1366,  1371,  1377,  1382,  1388,  1392,  1398,  1406,
    1414,  1418,  1421,  1429,  1433,  1436,  1440,  1443,  1446,  1449,
    1452,  1468,  1471,  1474,  1482,  1485,  1495,  1507,  1510,  1515,
    1518,  1521,  1524,  1527,  1530,  1533,  1539,  1548,  1560,  1567,
    1576,  1585,  1596,  1598,  1601,  1604,  1606,  1610,  1614,  1619,
    1624,  1626,  1628,  1634,  1646,  1660,  1661,  1669,  1670,  1684,
    1685,  1701,  1702,  1709,  1719,  1722,  1726,  1737,  1751,  1753,
    1756,  1762,  1770,  1773,  1776,  1780,  1783,  1787,  1790,  1794,
    1804,  1811,  1813,  1815,  1817,  1819,  1821,  1822,  1825,  1829,
    1833,  1838,  1848,  1853,  1861,  1871,  1879,  1889,  1896,  1905,
    1916,  1931,  1932,  1936,  1937,  1939,  1940,  1943,  1944,  1947,
    1948,  1951,  1957,  1964,  1972,  1979,  1985,  1989,  1998,  2005,
    2014,  2023,  2029,  2034,  2041,  2053,  2065,  2084,  2103,  2116,
    2129,  2142,  2153,  2158,  2163,  2168,  2173,  2178,  2185,  2188,
    2192,  2199,  2205,  2208,  2210,  2212,  2214,  2217,  2223,  2231,
    2242,  2244,  2248,  2251,  2254,  2257,  2261,  2265,  2269,  2273,
    2277,  2281,  2285,  2289,  2293,  2297,  2301,  2305,  2309,  2313,
    2317,  2321,  2325,  2329,  2335,  2340,  2345,  2350,  2355,  2360,
    2365,  2370,  2375,  2380,  2385,  2390,  2397,  2402,  2407,  2412,
    2417,  2422,  2427,  2432,  2437,  2444,  2451,  2458,  2463,  2470,
    2477,  2479,  2481,  2483,  2485,  2487,  2489,  2491,  2493,  2495,
    2497,  2499,  2500,  2507,  2509,  2514,  2521,  2523,  2528,  2533,
    2538,  2545,  2551,  2559,  2568,  2579,  2584,  2589,  2596,  2601,
    2605,  2608,  2614,  2620,  2624,  2630,  2637,  2646,  2653,  2662,
    2669,  2674,  2682,  2689,  2696,  2703,  2708,  2715,  2720,  2721,
    2724,  2725,  2728,  2729,  2737,  2739,  2743,  2745,  2748,  2749,
    2753,  2755,  2758,  2761,  2765,  2769,  2781,  2791,  2799,  2807,
    2809,  2813,  2815,  2817,  2820,  2824,  2829,  2835,  2838,  2842,
    2847,  2849,  2853,  2855,  2858,  2862,  2866,  2872,  2877,  2882,
    2885,  2890,  2893,  2897,  2903,  2907,  2912,  2918,  2924,  2930,
    2936,  2943,  2955,  2967,  2977,  2988,  2994,  2996,  2998,  3000,
    3004,  3010,  3018,  3023,  3028,  3033,  3040,  3047,  3056,  3065,
    3070,  3085,  3090,  3095,  3097,  3099,  3103,  3107,  3109,  3113,
    3123,  3131,  3133,  3139,  3143,  3150,  3152,  3156,  3158,  3160,
    3165,  3170,  3174,  3180,  3187,  3196,  3203,  3208,  3214,  3216,
    3221,  3223,  3225,  3227,  3229,  3234,  3241,  3246,  3253,  3259,
    3267,  3272,  3277,  3282,  3291,  3296,  3301,  3306,  3311,  3320,
    3329,  3336,  3341,  3348,  3353,  3355,  3357,  3362,  3367,  3368,
    3375,  3380,  3383,  3388,  3393,  3395,  3397,  3401,  3403,  3405,
    3409,  3413,  3417,  3423,  3431,  3437,  3443,  3452,  3454,  3456
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     277,     0,    -1,   278,    -1,     1,     6,    -1,    -1,   278,
     279,    -1,   281,    -1,   282,    -1,   303,    -1,   137,   266,
     380,   267,     6,    -1,   322,    -1,   328,    -1,   328,     6,
      -1,   331,    -1,   331,     6,    -1,   332,    -1,   333,    -1,
     334,    -1,   338,    -1,   338,     6,    -1,   347,    -1,   347,
       6,    -1,   348,    -1,   354,    -1,   355,    -1,   337,    -1,
     336,    -1,   335,    -1,   357,    -1,   249,    -1,   250,    -1,
      47,   266,   380,   267,     6,    -1,    49,   266,   380,   267,
       6,    -1,    48,   266,   380,   267,     6,    -1,    47,   266,
     380,   267,   280,   380,     6,    -1,    47,   266,   380,   275,
     375,   267,     6,    -1,    49,   266,   380,   275,   375,   267,
       6,    -1,    48,   266,   380,   275,   375,   267,     6,    -1,
      47,   266,   380,   275,   375,   267,   280,   380,     6,    -1,
     390,   380,   270,   283,   271,     6,    -1,   182,     4,   268,
     358,   269,     6,    -1,   183,     4,   268,   358,   269,     6,
      -1,   184,     4,   268,   358,   275,   358,   269,     6,    -1,
      -1,   283,   286,    -1,   283,   290,    -1,   283,   293,    -1,
     283,   295,    -1,   283,   296,    -1,   283,   337,    -1,   358,
      -1,   284,   275,   358,    -1,   358,    -1,   285,   275,   358,
      -1,    -1,    -1,     4,   287,   266,   284,   267,   288,   270,
     285,   271,     6,    -1,   380,    -1,   289,   275,   380,    -1,
      -1,   189,   266,   358,   275,   358,   275,   358,   267,   291,
     270,   289,   271,     6,    -1,   380,    -1,   292,   275,   380,
      -1,    -1,   190,   266,   358,   275,   358,   275,   358,   275,
     358,   267,   294,   270,   292,   271,     6,    -1,   191,   270,
     370,   271,   270,   370,   271,     6,    -1,   191,   270,   370,
     271,   270,   370,   271,   270,   370,   271,   270,   370,   271,
       6,    -1,    -1,   192,   297,   270,   285,   271,     6,    -1,
       7,    -1,   242,    -1,   241,    -1,   240,    -1,   239,    -1,
     264,    -1,   263,    -1,   266,    -1,   268,    -1,   267,    -1,
     269,    -1,     4,    -1,    37,    -1,    38,    -1,    26,    -1,
     114,    -1,   115,    -1,    94,   268,   305,   269,     6,    -1,
      95,   268,   309,   269,     6,    -1,   363,     6,    -1,   102,
     300,   381,   275,   358,   301,     6,    -1,   104,   300,   381,
     275,   381,   301,     6,    -1,   390,   298,   371,     6,    -1,
     390,   299,     6,    -1,   390,   300,   301,   298,   371,     6,
      -1,   390,   300,   270,   375,   271,   301,   298,   371,     6,
      -1,   390,   268,   358,   269,   298,   358,     6,    -1,   390,
     268,   358,   269,   299,     6,    -1,   390,   266,   358,   267,
     298,   358,     6,    -1,   390,   266,   358,   267,   299,     6,
      -1,   390,     7,   381,     6,    -1,   390,   300,   301,     7,
      50,   300,   301,     6,    -1,   390,   300,   301,     7,    50,
     300,   385,   301,     6,    -1,   390,   300,   301,   242,    50,
     300,   385,   301,     6,    -1,   390,   272,   302,     7,   381,
       6,    -1,   390,   268,   358,   269,   272,   302,     7,   381,
       6,    -1,   390,   272,   302,   298,   358,     6,    -1,   390,
     268,   358,   269,   272,   302,   298,   358,     6,    -1,   390,
     272,   302,   299,     6,    -1,   390,   268,   358,   269,   272,
     302,   299,     6,    -1,   390,   272,   199,   272,   302,     7,
     377,     6,    -1,   390,   268,   358,   269,   272,   199,   272,
     302,     7,   377,     6,    -1,   390,   272,   200,     7,   378,
       6,    -1,   390,   268,   358,   269,   272,   200,     7,   378,
       6,    -1,   390,   210,     7,   371,     6,    -1,   210,   268,
     358,   269,     7,   302,     6,    -1,   210,   268,   358,   269,
     272,   302,     7,   358,     6,    -1,   210,   268,   358,   269,
     272,   302,     7,   381,     6,    -1,   210,   268,   358,   269,
     272,   302,     7,   372,     6,    -1,   210,   268,   358,   269,
     272,   302,     6,    -1,   150,   266,     4,   267,   272,   302,
       7,   358,     6,    -1,   150,   266,     4,   267,   272,   302,
       7,   381,     6,    -1,    -1,   275,    -1,    -1,   305,   304,
     390,    -1,   305,   304,   390,     7,   358,    -1,    -1,   305,
     304,   390,     7,   270,   371,   306,   311,   271,    -1,    -1,
     305,   304,   390,   300,   301,     7,   270,   371,   307,   311,
     271,    -1,   305,   304,   390,     7,   381,    -1,    -1,   305,
     304,   390,     7,   270,   381,   308,   315,   271,    -1,    -1,
     309,   304,   380,    -1,   358,     7,   381,    -1,   310,   275,
     358,     7,   381,    -1,   374,     7,   390,   266,   267,    -1,
      -1,   275,   313,    -1,    -1,   313,    -1,   314,    -1,   313,
     275,   314,    -1,     4,   371,    -1,    37,   358,    -1,    38,
     358,    -1,    26,   358,    -1,     4,    -1,     4,   270,   310,
     271,    -1,     4,   381,    -1,     4,   384,    -1,    -1,   275,
     316,    -1,   317,    -1,   316,   275,   317,    -1,     4,   358,
      -1,     4,   381,    -1,   214,   381,    -1,     4,   386,    -1,
       4,   384,    -1,   358,    -1,   381,    -1,   381,   275,   358,
      -1,    -1,   202,   109,   270,   358,   271,    -1,   149,   105,
     270,   375,   271,    -1,   149,   124,   270,   375,   271,    -1,
      -1,   142,   368,    -1,    -1,   149,   153,    -1,   105,   266,
     358,   267,     7,   368,     6,    -1,   108,   266,   358,   267,
       7,   371,     6,    -1,   112,   266,   358,   267,     7,   371,
       6,    -1,   146,   112,   266,   358,   267,     7,   371,   149,
     358,     6,    -1,   146,   194,   266,   358,   267,     7,   371,
     149,   358,     6,    -1,   106,   266,   358,   267,     7,   371,
     320,     6,    -1,   107,   266,   358,   267,     7,   371,   320,
       6,    -1,   194,   266,   358,   267,     7,   371,     6,    -1,
     195,   266,   358,   267,     7,   371,     6,    -1,   196,   266,
     358,   267,     7,   371,   198,   371,   197,   358,     6,    -1,
     123,   266,   358,   267,     7,   371,     6,    -1,   108,     4,
     266,   358,   267,     7,   371,     6,    -1,   142,   111,   266,
     358,   267,     7,   371,     6,    -1,   111,   266,   358,   267,
       7,   371,   319,     6,    -1,   143,   111,   266,   358,   267,
       7,   371,   319,     6,    -1,   194,   111,   266,   358,   267,
       7,   371,     6,    -1,   195,   111,   266,   358,   267,     7,
     371,     6,    -1,    13,    14,     6,    -1,    14,   111,   358,
       6,    -1,   129,   111,   266,   358,   267,     7,     5,     5,
       5,     6,    -1,   109,   266,   358,   267,     7,   371,     6,
      -1,   110,   266,   358,   267,     7,   371,     6,    -1,   114,
     266,   358,   267,     7,   371,     6,    -1,   117,   266,   358,
     267,     7,   371,     6,    -1,   121,   266,   358,   267,     7,
     371,     6,    -1,   122,   266,   358,   267,     7,   371,     6,
      -1,   115,   266,   358,   267,     7,   371,     6,    -1,   116,
     266,   358,   267,     7,   371,     6,    -1,   139,   266,   358,
     267,     7,   371,     6,    -1,   166,   266,   358,   267,     7,
     371,     6,    -1,   111,     4,   266,   358,   267,     7,   371,
     321,     6,    -1,   113,   266,   358,   267,     7,   371,     6,
      -1,   138,   266,   358,   267,     7,   371,     6,    -1,   143,
     138,   266,   358,   267,     7,   371,     6,    -1,   146,   325,
     266,   358,   267,     7,   371,     6,    -1,   146,   325,   266,
     358,   267,     7,   371,     4,   270,   370,   271,     6,    -1,
      -1,   145,   324,   323,   266,   318,   267,   298,   371,     6,
      -1,   105,    -1,   108,    -1,   111,    -1,   113,    -1,   124,
     270,   358,   271,    -1,   108,    -1,   111,    -1,   113,    -1,
     124,   270,   358,   271,    -1,   108,    -1,   111,    -1,   124,
     270,   358,   271,    -1,   105,    -1,   108,    -1,   111,    -1,
     124,   270,   358,   271,    -1,   155,   368,   270,   329,   271,
      -1,   154,   270,   368,   275,   368,   275,   358,   271,   270,
     329,   271,    -1,   156,   368,   270,   329,   271,    -1,   157,
     270,   368,   275,   358,   271,   270,   329,   271,    -1,   157,
     270,   368,   275,   368,   271,   270,   329,   271,    -1,   159,
     270,   375,   271,   270,   329,   271,    -1,   160,   270,   375,
     271,   270,   329,   271,    -1,     4,   270,   329,   271,    -1,
     174,   108,   270,   375,   271,   111,   270,   358,   271,    -1,
     169,   108,   270,   358,   271,   105,   270,   375,   271,     6,
      -1,   169,   108,   266,   358,   267,   270,   375,   271,     6,
      -1,   330,    -1,   328,    -1,    -1,   330,   322,    -1,   330,
     324,   270,   375,   271,     6,    -1,   330,   145,   324,   270,
     375,   271,     6,    -1,   330,   145,   324,   270,   376,   271,
       6,    -1,   330,   148,   324,   270,   375,   271,     6,    -1,
     330,   324,   270,     8,   271,     6,    -1,   330,   145,   324,
     270,     8,   271,     6,    -1,   170,   270,   330,   271,    -1,
     152,   170,   270,   330,   271,    -1,   170,     4,   270,   330,
     271,    -1,   170,   210,   268,   358,   269,     6,    -1,   170,
       4,   268,   358,   269,     6,    -1,   170,   390,     6,    -1,
     170,     4,     4,     6,    -1,   170,    97,     6,    -1,   199,
     377,   270,   330,   271,    -1,   152,   199,   377,   270,   330,
     271,    -1,   235,   358,   270,   330,   271,    -1,   215,   270,
       8,   271,    -1,   215,     5,     6,    -1,   216,   270,     8,
     271,    -1,   216,     5,     6,    -1,   215,   270,   330,   271,
      -1,   152,   215,   270,   330,   271,    -1,   216,   270,   330,
     271,    -1,   152,   216,   270,   330,   271,    -1,   390,   381,
       6,    -1,    81,   266,   387,   267,     6,    -1,   390,   390,
     268,   358,   269,   380,     6,    -1,   390,   390,   390,   268,
     358,   269,     6,    -1,   390,   358,     6,    -1,   238,     6,
      -1,   150,   266,     4,   267,   272,     4,     6,    -1,   193,
       4,     6,    -1,   208,     6,    -1,   208,   358,     6,    -1,
     209,     6,    -1,    75,     6,    -1,    76,     6,    -1,    68,
       6,    -1,    68,   270,   358,   275,   358,   275,   358,   275,
     358,   275,   358,   275,   358,   271,     6,    -1,    69,     6,
      -1,    70,     6,    -1,    86,   270,   358,   275,   358,   271,
       6,    -1,    86,     6,    -1,    88,   270,   358,   275,   358,
     275,   358,   271,     6,    -1,    88,   270,   358,   275,   358,
     275,   358,   275,   358,   271,     6,    -1,    87,     6,    -1,
      87,   270,   330,   271,    -1,    89,     6,    -1,    90,     6,
      -1,    91,     6,    -1,    92,     6,    -1,   131,     6,    -1,
     132,     6,    -1,   134,   270,   375,   271,     6,    -1,   134,
     270,   375,   271,   270,   329,   271,     6,    -1,   213,   266,
     270,   375,   271,   275,   381,   275,   381,   267,     6,    -1,
     201,   266,   358,     8,   358,   267,    -1,   201,   266,   358,
       8,   358,     8,   358,   267,    -1,   201,     4,   202,   270,
     358,     8,   358,   271,    -1,   201,     4,   202,   270,   358,
       8,   358,     8,   358,   271,    -1,   203,    -1,   214,     4,
      -1,   214,   381,    -1,   211,    -1,   212,   390,     6,    -1,
     212,   381,     6,    -1,   204,   266,   358,   267,    -1,   205,
     266,   358,   267,    -1,   206,    -1,   207,    -1,   158,   368,
     270,   330,   271,    -1,   158,   270,   368,   275,   368,   275,
     358,   271,   270,   330,   271,    -1,   158,   270,   368,   275,
     368,   275,   368,   275,   358,   271,   270,   330,   271,    -1,
      -1,   158,   368,   270,   330,   339,   343,   271,    -1,    -1,
     158,   270,   368,   275,   368,   275,   358,   271,   270,   330,
     340,   343,   271,    -1,    -1,   158,   270,   368,   275,   368,
     275,   368,   275,   358,   271,   270,   330,   341,   343,   271,
      -1,    -1,   158,   270,   330,   342,   343,   271,    -1,   158,
     270,   330,   271,   149,   123,   270,   358,   271,    -1,   138,
     371,    -1,   143,   138,   371,    -1,   140,   270,   375,   271,
     270,   375,   271,   270,   375,   271,    -1,   141,   270,   375,
     271,   270,   375,   271,   270,   375,   271,   270,   375,   271,
      -1,   344,    -1,   343,   344,    -1,   179,   270,   358,   271,
       6,    -1,   179,   270,   371,   275,   371,   271,     6,    -1,
     180,     6,    -1,   167,     6,    -1,   167,   358,     6,    -1,
     185,     6,    -1,   185,   187,     6,    -1,   186,     6,    -1,
     186,   187,     6,    -1,   181,   266,   358,   267,     7,   371,
     149,   358,     6,    -1,   149,     4,   268,   358,   269,     6,
      -1,   161,    -1,   162,    -1,   163,    -1,   164,    -1,   165,
      -1,    -1,   170,     6,    -1,   152,   170,     6,    -1,   170,
     358,     6,    -1,   152,   170,   358,     6,    -1,   345,   270,
     330,   346,   271,   270,   330,   346,   271,    -1,   120,   266,
     380,   267,    -1,    88,   270,   330,   271,   270,   358,   271,
      -1,    88,   270,   330,   271,   270,   358,   275,   358,   271,
      -1,   173,   270,   330,   271,   270,   358,   271,    -1,   173,
     270,   330,   271,   270,   358,   275,   358,   271,    -1,   120,
     266,   380,   275,   358,   267,    -1,   120,   266,   380,   275,
     358,   275,   358,   267,    -1,   120,   266,   380,   275,   358,
     275,   358,   275,   358,   267,    -1,   345,   266,   358,   267,
       7,   270,   330,   346,   271,   270,   330,   346,   271,     6,
      -1,    -1,   149,     4,   358,    -1,    -1,     4,    -1,    -1,
       7,   371,    -1,    -1,     7,   358,    -1,    -1,   159,   371,
      -1,   177,   373,     7,   358,     6,    -1,   127,   128,   373,
       7,   358,     6,    -1,   144,   108,   373,     7,   358,   349,
       6,    -1,   144,   111,   373,   351,   350,     6,    -1,   144,
     113,   373,   351,     6,    -1,   188,   373,     6,    -1,   103,
     324,   266,   358,   275,   358,   267,     6,    -1,   223,   324,
     266,   358,   267,     6,    -1,   175,   111,   270,   375,   271,
       7,   358,     6,    -1,   178,   111,   270,   375,   271,     7,
     358,     6,    -1,   167,   111,   373,   352,     6,    -1,   167,
     113,   373,     6,    -1,   168,   111,   373,     7,   358,     6,
      -1,   147,   108,   270,   375,   271,     7,   270,   375,   271,
     353,     6,    -1,   147,   111,   270,   375,   271,     7,   270,
     375,   271,   353,     6,    -1,   147,   108,   270,   375,   271,
       7,   270,   375,   271,   154,   270,   368,   275,   368,   275,
     358,   271,     6,    -1,   147,   111,   270,   375,   271,     7,
     270,   375,   271,   154,   270,   368,   275,   368,   275,   358,
     271,     6,    -1,   147,   108,   270,   375,   271,     7,   270,
     375,   271,   155,   368,     6,    -1,   147,   111,   270,   375,
     271,     7,   270,   375,   271,   155,   368,     6,    -1,   147,
     111,   358,   270,   375,   271,     7,   358,   270,   375,   271,
       6,    -1,   324,   270,   375,   271,   202,   324,   270,   358,
     271,     6,    -1,   176,   326,   373,     6,    -1,   135,   327,
     373,     6,    -1,   136,   113,   371,     6,    -1,   151,   108,
     371,     6,    -1,   146,   325,   371,     6,    -1,   146,   325,
     371,   175,   358,     6,    -1,   171,     6,    -1,   171,     4,
       6,    -1,   171,   105,   270,   375,   271,     6,    -1,   172,
     270,   330,   271,     6,    -1,   172,     6,    -1,   224,    -1,
     225,    -1,   226,    -1,   356,     6,    -1,   356,   270,   371,
     271,     6,    -1,   356,   270,   371,   275,   371,   271,     6,
      -1,   356,   266,   371,   267,   270,   371,   275,   371,   271,
       6,    -1,   359,    -1,   266,   358,   267,    -1,   255,   358,
      -1,   254,   358,    -1,   261,   358,    -1,   358,   255,   358,
      -1,   358,   254,   358,    -1,   358,   256,   358,    -1,   358,
     257,   358,    -1,   358,   259,   358,    -1,   358,   260,   358,
      -1,   358,   258,   358,    -1,   358,   265,   358,    -1,   358,
     248,   358,    -1,   358,   249,   358,    -1,   358,   253,   358,
      -1,   358,   252,   358,    -1,   358,   247,   358,    -1,   358,
     246,   358,    -1,   358,   245,   358,    -1,   358,   244,   358,
      -1,   358,   250,   358,    -1,   358,   251,   358,    -1,   358,
     243,   358,     8,   358,    -1,    26,   300,   358,   301,    -1,
      16,   300,   358,   301,    -1,    17,   300,   358,   301,    -1,
      18,   300,   358,   301,    -1,    19,   300,   358,   301,    -1,
      20,   300,   358,   301,    -1,    21,   300,   358,   301,    -1,
      22,   300,   358,   301,    -1,    23,   300,   358,   301,    -1,
      24,   300,   358,   301,    -1,    27,   300,   358,   301,    -1,
      28,   300,   358,   275,   358,   301,    -1,    29,   300,   358,
     301,    -1,    30,   300,   358,   301,    -1,    31,   300,   358,
     301,    -1,    32,   300,   358,   301,    -1,    33,   300,   358,
     301,    -1,    34,   300,   358,   301,    -1,    35,   300,   358,
     301,    -1,    36,   300,   358,   301,    -1,    39,   300,   358,
     275,   358,   301,    -1,    40,   300,   358,   275,   358,   301,
      -1,    41,   300,   358,   275,   358,   301,    -1,    25,   300,
     358,   301,    -1,    38,   300,   358,   275,   358,   301,    -1,
      37,   300,   358,   275,   358,   301,    -1,     3,    -1,    10,
      -1,    15,    -1,    11,    -1,    12,    -1,   231,    -1,   232,
      -1,   233,    -1,    83,    -1,    84,    -1,    85,    -1,    -1,
      96,   300,   358,   360,   311,   301,    -1,   363,    -1,   221,
     300,   380,   301,    -1,   221,   300,   380,   275,   358,   301,
      -1,   365,    -1,   390,   268,   358,   269,    -1,   390,   266,
     358,   267,    -1,   227,   266,   365,   267,    -1,   227,   266,
     365,   272,   302,   267,    -1,   229,   266,   365,   361,   267,
      -1,   229,   266,   365,   272,   302,   361,   267,    -1,   229,
     266,   365,   300,   358,   301,   361,   267,    -1,   229,   266,
     365,   272,   302,   300,   358,   301,   361,   267,    -1,   228,
     266,   381,   267,    -1,   273,   390,   300,   301,    -1,   273,
     365,   272,   302,   300,   301,    -1,    99,   300,   390,   301,
      -1,    99,   300,   301,    -1,   390,   299,    -1,   390,   268,
     358,   269,   299,    -1,   390,   266,   358,   267,   299,    -1,
     390,   272,   302,    -1,   390,     9,   390,   272,   302,    -1,
     390,   272,   302,   266,   358,   267,    -1,   390,     9,   390,
     272,   302,   266,   358,   267,    -1,   390,   272,   302,   268,
     358,   269,    -1,   390,     9,   390,   272,   302,   268,   358,
     269,    -1,   390,   268,   358,   269,   272,   302,    -1,   390,
     272,   302,   299,    -1,   390,   268,   358,   269,   272,   302,
     299,    -1,   217,   266,   380,   275,   358,   267,    -1,    60,
     266,   371,   275,   371,   267,    -1,    61,   300,   380,   275,
     380,   301,    -1,    59,   300,   380,   301,    -1,    62,   300,
     380,   275,   380,   301,    -1,    67,   266,   387,   267,    -1,
      -1,   275,   358,    -1,    -1,   275,   380,    -1,    -1,    97,
     365,   367,   364,   268,   312,   269,    -1,   390,    -1,   390,
       9,   390,    -1,   100,    -1,   100,   358,    -1,    -1,   266,
     366,   267,    -1,   369,    -1,   255,   368,    -1,   254,   368,
      -1,   368,   255,   368,    -1,   368,   254,   368,    -1,   270,
     358,   275,   358,   275,   358,   275,   358,   275,   358,   271,
      -1,   270,   358,   275,   358,   275,   358,   275,   358,   271,
      -1,   270,   358,   275,   358,   275,   358,   271,    -1,   266,
     358,   275,   358,   275,   358,   267,    -1,   371,    -1,   370,
     275,   371,    -1,   358,    -1,   374,    -1,   270,   271,    -1,
     270,   375,   271,    -1,   255,   270,   375,   271,    -1,   358,
     256,   270,   375,   271,    -1,   270,   271,    -1,   270,   375,
     271,    -1,   255,   270,   375,   271,    -1,   371,    -1,   270,
       8,   271,    -1,     5,    -1,   255,   374,    -1,   358,   256,
     374,    -1,   358,     8,   358,    -1,   358,     8,   358,     8,
     358,    -1,   105,   270,   358,   271,    -1,   105,   270,     8,
     271,    -1,   105,     5,    -1,   325,   270,     8,   271,    -1,
     325,     5,    -1,   145,   324,   373,    -1,   145,   324,   270,
     376,   271,    -1,   148,   324,   371,    -1,   324,   202,    68,
     371,    -1,    68,   324,   270,   375,   271,    -1,    77,   325,
     270,   358,   271,    -1,    78,   325,   270,   358,   271,    -1,
      79,   325,   270,   358,   271,    -1,   129,    68,   326,   270,
     358,   271,    -1,   125,   111,   270,   358,   271,   129,   270,
     358,   275,   358,   271,    -1,   126,   111,   270,   358,   271,
     129,   270,   358,   275,   358,   271,    -1,   126,   108,   270,
     358,   271,   129,   270,   358,   271,    -1,   129,   105,   270,
     358,   271,   202,   111,   270,   358,   271,    -1,   199,   325,
     270,   358,   271,    -1,   328,    -1,   338,    -1,   347,    -1,
     390,   300,   301,    -1,   390,   272,   302,   300,   301,    -1,
     390,     9,   390,   272,   302,   300,   301,    -1,    42,   268,
     390,   269,    -1,    42,   268,   374,   269,    -1,    42,   266,
     374,   267,    -1,    42,   300,   270,   375,   271,   301,    -1,
     390,   300,   270,   375,   271,   301,    -1,    43,   300,   358,
     275,   358,   275,   358,   301,    -1,    44,   300,   358,   275,
     358,   275,   358,   301,    -1,    45,   300,   380,   301,    -1,
      46,   300,   358,   275,   358,   275,   358,   275,   358,   275,
     358,   275,   358,   301,    -1,   222,   300,   374,   301,    -1,
      33,   300,   374,   301,    -1,   358,    -1,   374,    -1,   375,
     275,   358,    -1,   375,   275,   374,    -1,   381,    -1,   376,
     275,   381,    -1,   270,   358,   275,   358,   275,   358,   275,
     358,   271,    -1,   270,   358,   275,   358,   275,   358,   271,
      -1,   390,    -1,     4,   272,   199,   272,     4,    -1,   270,
     379,   271,    -1,   390,   268,   358,   269,   272,   200,    -1,
     377,    -1,   379,   275,   377,    -1,   381,    -1,   390,    -1,
     390,   268,   358,   269,    -1,   390,   266,   358,   267,    -1,
     390,   272,   302,    -1,   390,     9,   390,   272,   302,    -1,
     390,   272,   302,   266,   358,   267,    -1,   390,     9,   390,
     272,   302,   266,   358,   267,    -1,   390,   268,   358,   269,
     272,     4,    -1,   324,   270,   358,   271,    -1,   145,   324,
     270,   358,   271,    -1,     5,    -1,   236,   268,   390,   269,
      -1,    71,    -1,   234,    -1,    80,    -1,    82,    -1,   219,
     266,   380,   267,    -1,   218,   266,   380,   275,   380,   267,
      -1,   220,   300,   380,   301,    -1,   220,   300,   380,   275,
     380,   301,    -1,   230,   266,   365,   362,   267,    -1,   230,
     266,   365,   272,   302,   362,   267,    -1,    52,   300,   387,
     301,    -1,    53,   266,   380,   267,    -1,    54,   266,   380,
     267,    -1,    55,   266,   380,   275,   380,   275,   380,   267,
      -1,    50,   300,   387,   301,    -1,    64,   300,   380,   301,
      -1,    65,   300,   380,   301,    -1,    66,   300,   380,   301,
      -1,    63,   300,   358,   275,   380,   275,   380,   301,    -1,
      58,   300,   380,   275,   358,   275,   358,   301,    -1,    58,
     300,   380,   275,   358,   301,    -1,    51,   300,   380,   301,
      -1,    51,   300,   380,   275,   375,   301,    -1,    72,   300,
     380,   301,    -1,    73,    -1,    74,    -1,    57,   300,   380,
     301,    -1,    56,   300,   380,   301,    -1,    -1,   101,   300,
     381,   382,   315,   301,    -1,    98,   300,   383,   301,    -1,
     273,   358,    -1,   390,     9,   273,   358,    -1,    50,   300,
     386,   301,    -1,   387,    -1,   386,    -1,   270,   387,   271,
      -1,   380,    -1,   388,    -1,   387,   275,   380,    -1,   387,
     275,   388,    -1,   390,   266,   267,    -1,   390,   272,   302,
     266,   267,    -1,   390,     9,   390,   272,   302,   266,   267,
      -1,     4,   274,   270,   358,   271,    -1,   389,   274,   270,
     358,   271,    -1,   237,   268,   380,   269,   274,   270,   358,
     271,    -1,     4,    -1,   389,    -1,   237,   268,   380,   269,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   287,   287,   288,   293,   295,   299,   300,   301,   302,
     336,   340,   341,   342,   343,   344,   345,   346,   347,   348,
     349,   350,   351,   352,   353,   354,   355,   356,   357,   361,
     365,   372,   377,   382,   387,   401,   414,   427,   440,   468,
     482,   495,   508,   527,   532,   533,   534,   535,   536,   537,
     541,   543,   548,   550,   556,   575,   555,   588,   593,   602,
     601,   614,   619,   628,   627,   640,   657,   680,   679,   697,
     698,   699,   700,   701,   705,   706,   712,   712,   714,   714,
     719,   720,   721,   722,   723,   724,   730,   731,   732,   733,
     738,   744,   805,   820,   848,   858,   863,   871,   876,   884,
     893,   898,   910,   927,   933,   942,   960,   978,   987,   999,
    1004,  1012,  1032,  1055,  1075,  1083,  1100,  1118,  1156,  1177,
    1189,  1203,  1203,  1205,  1207,  1216,  1226,  1225,  1246,  1245,
    1263,  1273,  1272,  1286,  1288,  1296,  1302,  1307,  1334,  1336,
    1339,  1341,  1345,  1346,  1350,  1362,  1366,  1370,  1374,  1387,
    1401,  1409,  1422,  1424,  1428,  1429,  1434,  1442,  1451,  1459,
    1473,  1491,  1495,  1506,  1515,  1518,  1524,  1528,  1540,  1543,
    1550,  1553,  1559,  1582,  1598,  1614,  1631,  1648,  1685,  1729,
    1745,  1761,  1793,  1809,  1826,  1842,  1892,  1910,  1931,  1952,
    1958,  1964,  1971,  2012,  2027,  2059,  2093,  2126,  2161,  2196,
    2231,  2255,  2281,  2298,  2314,  2332,  2350,  2362,  2376,  2375,
    2405,  2407,  2409,  2411,  2413,  2421,  2423,  2425,  2427,  2435,
    2437,  2439,  2447,  2449,  2451,  2453,  2463,  2479,  2495,  2511,
    2527,  2543,  2560,  2586,  2629,  2650,  2671,  2697,  2698,  2703,
    2706,  2710,  2727,  2747,  2767,  2787,  2806,  2833,  2858,  2883,
    2895,  2901,  2916,  2947,  2959,  2968,  2975,  2987,  3007,  3011,
    3016,  3020,  3025,  3032,  3039,  3046,  3058,  3134,  3152,  3177,
    3192,  3243,  3249,  3261,  3293,  3297,  3301,  3306,  3314,  3319,
    3330,  3335,  3341,  3349,  3360,  3368,  3372,  3376,  3380,  3387,
    3391,  3395,  3399,  3403,  3416,  3426,  3446,  3472,  3488,  3505,
    3522,  3544,  3566,  3601,  3609,  3617,  3623,  3630,  3637,  3657,
    3683,  3695,  3706,  3724,  3742,  3761,  3760,  3785,  3784,  3811,
    3810,  3835,  3834,  3857,  3873,  3890,  3907,  3944,  3972,  3975,
    3981,  3993,  4013,  4017,  4021,  4025,  4029,  4033,  4037,  4041,
    4050,  4063,  4064,  4065,  4066,  4067,  4071,  4072,  4073,  4074,
    4075,  4078,  4118,  4145,  4151,  4157,  4163,  4169,  4175,  4181,
    4190,  4228,  4231,  4259,  4262,  4279,  4282,  4288,  4291,  4298,
    4301,  4308,  4331,  4350,  4392,  4438,  4479,  4505,  4512,  4523,
    4541,  4559,  4590,  4617,  4644,  4676,  4704,  4730,  4756,  4782,
    4808,  4830,  4842,  4891,  4946,  4962,  4974,  4980,  4992,  4999,
    5014,  5023,  5055,  5084,  5085,  5086,  5090,  5096,  5108,  5126,
    5154,  5155,  5156,  5157,  5158,  5159,  5160,  5161,  5162,  5169,
    5170,  5171,  5172,  5173,  5174,  5175,  5176,  5177,  5178,  5179,
    5180,  5181,  5182,  5183,  5184,  5185,  5186,  5187,  5188,  5189,
    5190,  5191,  5192,  5193,  5194,  5195,  5196,  5197,  5198,  5199,
    5200,  5201,  5202,  5203,  5204,  5205,  5206,  5207,  5208,  5209,
    5218,  5219,  5220,  5221,  5222,  5223,  5224,  5225,  5226,  5227,
    5228,  5233,  5232,  5240,  5244,  5249,  5254,  5258,  5263,  5268,
    5272,  5276,  5280,  5284,  5288,  5292,  5298,  5313,  5317,  5323,
    5328,  5347,  5367,  5388,  5392,  5396,  5400,  5404,  5408,  5412,
    5417,  5427,  5437,  5442,  5453,  5462,  5467,  5472,  5500,  5501,
    5507,  5508,  5514,  5513,  5536,  5538,  5543,  5545,  5551,  5552,
    5557,  5561,  5565,  5569,  5573,  5580,  5584,  5588,  5592,  5599,
    5604,  5611,  5616,  5620,  5624,  5628,  5636,  5647,  5651,  5655,
    5666,  5670,  5674,  5688,  5696,  5704,  5711,  5721,  5744,  5749,
    5755,  5760,  5766,  5777,  5783,  5789,  5803,  5809,  5821,  5835,
    5848,  5879,  5903,  5924,  5944,  5965,  5982,  5992,  6002,  6012,
    6024,  6028,  6033,  6045,  6049,  6053,  6057,  6075,  6083,  6091,
    6120,  6130,  6146,  6157,  6162,  6166,  6170,  6182,  6187,  6194,
    6198,  6210,  6227,  6237,  6241,  6256,  6261,  6268,  6272,  6277,
    6291,  6305,  6309,  6313,  6317,  6321,  6329,  6335,  6344,  6348,
    6352,  6360,  6366,  6372,  6376,  6383,  6391,  6398,  6407,  6411,
    6415,  6430,  6444,  6458,  6470,  6486,  6495,  6504,  6514,  6525,
    6533,  6541,  6545,  6563,  6570,  6576,  6582,  6589,  6597,  6596,
    6606,  6630,  6632,  6638,  6643,  6645,  6650,  6655,  6660,  6662,
    6666,  6678,  6692,  6696,  6703,  6711,  6719,  6730,  6732,  6735
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
     279,   279,   279,   279,   279,   279,   279,   279,   279,   280,
     280,   281,   281,   281,   281,   281,   281,   281,   281,   282,
     282,   282,   282,   283,   283,   283,   283,   283,   283,   283,
     284,   284,   285,   285,   287,   288,   286,   289,   289,   291,
     290,   292,   292,   294,   293,   295,   295,   297,   296,   298,
     298,   298,   298,   298,   299,   299,   300,   300,   301,   301,
     302,   302,   302,   302,   302,   302,   303,   303,   303,   303,
     303,   303,   303,   303,   303,   303,   303,   303,   303,   303,
     303,   303,   303,   303,   303,   303,   303,   303,   303,   303,
     303,   303,   303,   303,   303,   303,   303,   303,   303,   303,
     303,   304,   304,   305,   305,   305,   306,   305,   307,   305,
     305,   308,   305,   309,   309,   310,   310,   310,   311,   311,
     312,   312,   313,   313,   314,   314,   314,   314,   314,   314,
     314,   314,   315,   315,   316,   316,   317,   317,   317,   317,
     317,   318,   318,   318,   319,   319,   319,   319,   320,   320,
     321,   321,   322,   322,   322,   322,   322,   322,   322,   322,
     322,   322,   322,   322,   322,   322,   322,   322,   322,   322,
     322,   322,   322,   322,   322,   322,   322,   322,   322,   322,
     322,   322,   322,   322,   322,   322,   322,   322,   323,   322,
     324,   324,   324,   324,   324,   325,   325,   325,   325,   326,
     326,   326,   327,   327,   327,   327,   328,   328,   328,   328,
     328,   328,   328,   328,   328,   328,   328,   329,   329,   330,
     330,   330,   330,   330,   330,   330,   330,   331,   331,   331,
     331,   331,   331,   331,   331,   332,   332,   333,   334,   334,
     334,   334,   334,   334,   334,   334,   335,   335,   335,   335,
     335,   335,   335,   335,   335,   335,   335,   335,   335,   335,
     335,   335,   335,   335,   335,   335,   335,   335,   335,   335,
     335,   335,   335,   335,   335,   335,   335,   336,   337,   337,
     337,   337,   337,   337,   337,   337,   337,   337,   337,   337,
     337,   337,   338,   338,   338,   339,   338,   340,   338,   341,
     338,   342,   338,   338,   338,   338,   338,   338,   343,   343,
     344,   344,   344,   344,   344,   344,   344,   344,   344,   344,
     344,   345,   345,   345,   345,   345,   346,   346,   346,   346,
     346,   347,   347,   347,   347,   347,   347,   347,   347,   347,
     348,   349,   349,   350,   350,   351,   351,   352,   352,   353,
     353,   354,   354,   354,   354,   354,   354,   354,   354,   354,
     354,   354,   354,   354,   354,   354,   354,   354,   354,   354,
     354,   354,   354,   354,   354,   354,   354,   354,   355,   355,
     355,   355,   355,   356,   356,   356,   357,   357,   357,   357,
     358,   358,   358,   358,   358,   358,   358,   358,   358,   358,
     358,   358,   358,   358,   358,   358,   358,   358,   358,   358,
     358,   358,   358,   358,   358,   358,   358,   358,   358,   358,
     358,   358,   358,   358,   358,   358,   358,   358,   358,   358,
     358,   358,   358,   358,   358,   358,   358,   358,   358,   358,
     359,   359,   359,   359,   359,   359,   359,   359,   359,   359,
     359,   360,   359,   359,   359,   359,   359,   359,   359,   359,
     359,   359,   359,   359,   359,   359,   359,   359,   359,   359,
     359,   359,   359,   359,   359,   359,   359,   359,   359,   359,
     359,   359,   359,   359,   359,   359,   359,   359,   361,   361,
     362,   362,   364,   363,   365,   365,   366,   366,   367,   367,
     368,   368,   368,   368,   368,   369,   369,   369,   369,   370,
     370,   371,   371,   371,   371,   371,   371,   372,   372,   372,
     373,   373,   373,   374,   374,   374,   374,   374,   374,   374,
     374,   374,   374,   374,   374,   374,   374,   374,   374,   374,
     374,   374,   374,   374,   374,   374,   374,   374,   374,   374,
     374,   374,   374,   374,   374,   374,   374,   374,   374,   374,
     374,   374,   374,   375,   375,   375,   375,   376,   376,   377,
     377,   377,   377,   378,   378,   379,   379,   380,   380,   380,
     380,   380,   380,   380,   380,   380,   380,   380,   381,   381,
     381,   381,   381,   381,   381,   381,   381,   381,   381,   381,
     381,   381,   381,   381,   381,   381,   381,   381,   381,   381,
     381,   381,   381,   381,   381,   381,   381,   381,   382,   381,
     381,   383,   383,   384,   385,   385,   386,   387,   387,   387,
     387,   388,   388,   388,   389,   389,   389,   390,   390,   390
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     2,     1,     1,     1,     5,
       1,     1,     2,     1,     2,     1,     1,     1,     1,     2,
       1,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     5,     5,     5,     7,     7,     7,     7,     9,     6,
       6,     6,     8,     0,     2,     2,     2,     2,     2,     2,
       1,     3,     1,     3,     0,     0,    10,     1,     3,     0,
      13,     1,     3,     0,    15,     8,    14,     0,     6,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     5,     5,     2,     7,
       7,     4,     3,     6,     9,     7,     6,     7,     6,     4,
       8,     9,     9,     6,     9,     6,     9,     5,     8,     8,
      11,     6,     9,     5,     7,     9,     9,     9,     7,     9,
       9,     0,     1,     0,     3,     5,     0,     9,     0,    11,
       5,     0,     9,     0,     3,     3,     5,     5,     0,     2,
       0,     1,     1,     3,     2,     2,     2,     2,     1,     4,
       2,     2,     0,     2,     1,     3,     2,     2,     2,     2,
       2,     1,     1,     3,     0,     5,     5,     5,     0,     2,
       0,     2,     7,     7,     7,    10,    10,     8,     8,     7,
       7,    11,     7,     8,     8,     8,     9,     8,     8,     3,
       4,    10,     7,     7,     7,     7,     7,     7,     7,     7,
       7,     7,     9,     7,     7,     8,     8,    12,     0,     9,
       1,     1,     1,     1,     4,     1,     1,     1,     4,     1,
       1,     4,     1,     1,     1,     4,     5,    11,     5,     9,
       9,     7,     7,     4,     9,    10,     9,     1,     1,     0,
       2,     6,     7,     7,     7,     6,     7,     4,     5,     5,
       6,     6,     3,     4,     3,     5,     6,     5,     4,     3,
       4,     3,     4,     5,     4,     5,     3,     5,     7,     7,
       3,     2,     7,     3,     2,     3,     2,     2,     2,     2,
      15,     2,     2,     7,     2,     9,    11,     2,     4,     2,
       2,     2,     2,     2,     2,     5,     8,    11,     6,     8,
       8,    10,     1,     2,     2,     1,     3,     3,     4,     4,
       1,     1,     5,    11,    13,     0,     7,     0,    13,     0,
      15,     0,     6,     9,     2,     3,    10,    13,     1,     2,
       5,     7,     2,     2,     3,     2,     3,     2,     3,     9,
       6,     1,     1,     1,     1,     1,     0,     2,     3,     3,
       4,     9,     4,     7,     9,     7,     9,     6,     8,    10,
      14,     0,     3,     0,     1,     0,     2,     0,     2,     0,
       2,     5,     6,     7,     6,     5,     3,     8,     6,     8,
       8,     5,     4,     6,    11,    11,    18,    18,    12,    12,
      12,    10,     4,     4,     4,     4,     4,     6,     2,     3,
       6,     5,     2,     1,     1,     1,     2,     5,     7,    10,
       1,     3,     2,     2,     2,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     5,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     6,     4,     4,     4,     4,
       4,     4,     4,     4,     6,     6,     6,     4,     6,     6,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     6,     1,     4,     6,     1,     4,     4,     4,
       6,     5,     7,     8,    10,     4,     4,     6,     4,     3,
       2,     5,     5,     3,     5,     6,     8,     6,     8,     6,
       4,     7,     6,     6,     6,     4,     6,     4,     0,     2,
       0,     2,     0,     7,     1,     3,     1,     2,     0,     3,
       1,     2,     2,     3,     3,    11,     9,     7,     7,     1,
       3,     1,     1,     2,     3,     4,     5,     2,     3,     4,
       1,     3,     1,     2,     3,     3,     5,     4,     4,     2,
       4,     2,     3,     5,     3,     4,     5,     5,     5,     5,
       6,    11,    11,     9,    10,     5,     1,     1,     1,     3,
       5,     7,     4,     4,     4,     6,     6,     8,     8,     4,
      14,     4,     4,     1,     1,     3,     3,     1,     3,     9,
       7,     1,     5,     3,     6,     1,     3,     1,     1,     4,
       4,     3,     5,     6,     8,     6,     4,     5,     1,     4,
       1,     1,     1,     1,     4,     6,     4,     6,     5,     7,
       4,     4,     4,     8,     4,     4,     4,     4,     8,     8,
       6,     4,     6,     4,     1,     1,     4,     4,     0,     6,
       4,     2,     4,     4,     1,     1,     3,     1,     1,     3,
       3,     3,     5,     7,     5,     5,     8,     1,     1,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     2,     3,     1,   657,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   210,     0,     0,   211,     0,     0,   212,     0,   213,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   341,   342,   343,
     344,   345,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   302,     0,     0,   310,   311,
       0,     0,     0,   305,     0,     0,     0,     0,     0,     0,
     403,   404,   405,     0,     0,     0,     5,     6,     7,     8,
      10,     0,    11,    13,    15,    16,    17,    27,    26,    25,
      18,     0,    20,    22,    23,    24,     0,    28,     0,   658,
       0,   239,     0,     0,     0,     0,     0,     0,   279,     0,
     281,   282,   277,   278,     0,   284,     0,   287,   239,   239,
     289,   290,   291,   292,   123,   133,   657,   518,   514,    76,
      77,     0,   210,   211,   212,   213,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     293,   294,     0,   222,   223,   224,     0,     0,     0,     0,
     460,   461,   463,   464,   462,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   468,   469,   470,     0,     0,
       0,   210,   215,   216,   217,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     465,   466,   467,     0,     0,     0,     0,     0,     0,     0,
       0,   566,   567,     0,   568,   531,   410,   473,   476,   324,
     532,   514,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   208,   215,   216,     0,   217,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   520,     0,     0,   239,     0,     0,     0,
       0,     0,     0,     0,     0,   657,     0,     0,   239,     0,
       0,   398,     0,   402,   239,   239,     0,     0,   219,   220,
       0,     0,   542,     0,     0,   540,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   657,     0,
       0,   591,     0,     0,     0,     0,   274,     0,     0,     0,
     514,   276,     0,   608,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   610,     0,   634,
     635,   612,   613,     0,     0,     0,     0,     0,     0,   611,
       0,     0,     0,     0,   303,   304,     0,   239,     0,   239,
       0,     0,     0,   271,     0,    12,    14,    19,     0,   239,
      21,   406,     0,     0,    88,     0,    69,     0,     0,    73,
      72,    71,    70,    75,    74,    76,    77,     0,     0,     0,
       0,     0,     0,     0,   597,   514,     0,   238,     0,   237,
       0,   189,     0,     0,   597,   598,     0,     0,     0,   647,
       0,   648,   598,     0,     0,     0,     0,   121,   121,     0,
     512,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   583,   584,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    76,    77,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   239,     0,     0,
     549,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   413,     0,
     412,   543,   414,     0,   533,     0,     0,   514,     0,   551,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    76,    77,     0,   490,     0,     0,     0,     0,
       0,     0,     0,   325,     0,   365,   365,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   239,     0,
     239,   239,     0,   522,   521,     0,     0,     0,     0,   239,
     239,     0,     0,     0,     0,   321,     0,   239,     0,     0,
       0,   367,     0,     0,     0,     0,     0,     0,   239,   254,
       0,     0,   252,   399,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   376,   273,
       0,     0,     0,     0,     0,     0,     0,   239,     0,     0,
       0,     0,     0,   412,   275,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   307,   306,     0,   259,     0,     0,   261,     0,
       0,     0,   239,     0,     0,     0,   346,     0,     0,     0,
       0,     0,     0,     0,     0,    80,    83,    81,    82,    84,
      85,     0,     0,     0,     0,    92,    78,    79,     0,     0,
       0,   270,    43,   266,     0,     0,     0,     0,     0,   233,
       0,     0,     0,     0,     0,   240,     0,     0,   190,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   288,     0,     0,     0,
     122,     0,     0,     0,   516,     0,     0,   515,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   352,     0,     0,     0,
       0,   214,     0,     0,     0,     0,     0,     0,   393,   394,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   514,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   471,   489,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   552,   554,
       0,     0,     0,     0,     0,     0,   508,     0,   411,   534,
       0,     0,     0,     0,   545,     0,   430,   429,   428,   427,
     423,   424,   431,   432,   426,   425,   416,   415,     0,   417,
     544,   418,   421,   419,   420,   422,   515,     0,     0,   493,
       0,   569,     0,     0,     0,     0,     0,     0,     0,     0,
     363,     0,     0,     0,     0,     0,     0,   396,     0,     0,
       0,     0,     0,   395,     0,   239,     0,     0,     0,     0,
       0,   524,   523,     0,     0,     0,     0,     0,     0,     0,
     315,     0,     0,     0,     0,     0,   382,     0,     0,     0,
     253,     0,     0,     0,   247,     0,     0,     0,     0,     0,
       0,   392,   411,   541,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   308,
     309,     0,   417,   515,   493,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   638,     0,     0,     0,   510,     0,     0,
     258,   262,   260,   264,     0,     0,   659,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    99,     0,     0,   411,
       0,     0,     0,    69,     0,     0,    91,     0,    69,    70,
       0,     0,     0,   515,     0,     0,   493,     0,     0,     0,
     208,     0,     0,     0,   654,    31,    29,    30,     0,     0,
       0,     0,     0,   601,    33,     0,    32,     0,     0,   267,
     649,   650,     0,   651,   601,     0,     0,     0,    86,   124,
      87,   134,   517,   519,   140,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   295,
     239,   585,   586,   225,     9,   435,   436,   437,   438,   439,
     440,   441,   442,   443,   457,   434,   444,     0,   446,   447,
     448,   449,   450,   582,   451,   452,   453,     0,     0,     0,
       0,     0,   574,   573,   572,     0,     0,     0,   579,     0,
     505,     0,     0,     0,   507,     0,     0,     0,     0,   138,
     488,   548,   547,   218,     0,     0,     0,     0,     0,     0,
     587,     0,     0,     0,   474,   581,   479,     0,   485,     0,
       0,     0,     0,   535,     0,     0,   486,   555,   550,     0,
       0,     0,     0,   478,   477,    76,    77,   500,     0,     0,
       0,     0,     0,     0,     0,   411,   361,   366,   364,     0,
     375,     0,   161,   162,     0,   218,     0,   411,     0,     0,
       0,     0,     0,   248,     0,   263,   265,     0,     0,     0,
     226,   228,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   328,     0,   312,     0,   239,   239,     0,
     368,   381,     0,     0,     0,     0,   249,     0,     0,   401,
       0,     0,     0,   221,   371,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   255,     0,     0,     0,
       0,     0,     0,     0,   624,     0,   631,   620,   621,   622,
       0,   637,   636,     0,     0,   625,   626,   627,   633,   641,
     640,     0,   152,     0,   614,     0,   616,     0,     0,     0,
     609,     0,     0,   257,     0,     0,     0,     0,   347,     0,
       0,     0,   407,     0,   655,     0,   113,    69,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   107,
       0,     0,     0,     0,   606,    54,     0,     0,     0,    67,
       0,    44,    45,    46,    47,    48,    49,     0,   478,   477,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   600,   599,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   148,     0,     0,     0,     0,
     141,   142,     0,     0,     0,     0,   168,   168,     0,     0,
       0,     0,     0,   164,     0,     0,     0,     0,     0,     0,
     357,     0,     0,     0,     0,   372,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   556,   557,   558,   559,     0,     0,     0,     0,     0,
       0,     0,   553,     0,   565,     0,     0,     0,   508,   509,
       0,   481,     0,     0,   546,   433,   536,   494,   492,     0,
     491,     0,     0,   570,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   374,     0,     0,     0,     0,     0,   397,
       0,     0,     0,    80,     0,   256,     0,     0,     0,     0,
       0,     0,     0,   333,     0,     0,   332,     0,   335,     0,
     337,     0,   322,   329,     0,     0,     0,     0,     0,   383,
       0,     0,   251,   250,   400,     0,     0,     0,     0,    40,
      41,     0,     0,     0,     0,     0,     0,   592,     0,     0,
       0,   298,   494,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   510,   511,   618,     0,   378,     0,
       0,   239,   348,     0,   349,   239,     0,     0,   607,     0,
      98,     0,     0,     0,     0,    96,     0,   595,     0,   111,
       0,   103,   105,     0,     0,     0,    93,     0,     0,     0,
       0,     0,    39,   494,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    34,    35,     0,
     602,     0,     0,    37,    36,     0,   602,   652,   283,   353,
       0,     0,     0,   125,   130,     0,     0,     0,   144,   150,
     151,   147,   145,   146,   513,     0,    89,     0,    90,   172,
       0,     0,     0,     0,   173,   192,   193,   170,     0,     0,
       0,   174,   203,   194,   198,   199,   195,     0,   196,   197,
     182,     0,     0,   445,   459,   458,   454,   455,   456,   575,
       0,     0,     0,   503,   504,   506,   139,   472,     0,     0,
       0,   560,     0,   588,   502,   475,   480,     0,     0,   508,
     204,   487,    76,    77,     0,   499,   495,   497,   576,   200,
       0,     0,     0,   164,     0,     0,   373,     0,   163,     0,
       0,     0,     0,     0,     0,   272,     0,     0,     0,     0,
     239,   239,     0,     0,   334,   531,     0,     0,   336,   338,
       0,     0,   316,   231,   232,   201,     0,     0,   355,     0,
       0,     0,     0,     0,     0,   179,     0,   180,     0,     0,
       0,     0,     0,     0,   114,   118,     0,   632,     0,     0,
     630,     0,   642,     0,     0,   153,   154,   639,   615,   617,
       0,     0,     0,     0,   346,   350,   346,     0,   408,    97,
       0,     0,    69,     0,     0,    95,     0,   593,     0,     0,
       0,     0,     0,     0,   645,   644,     0,     0,     0,     0,
       0,   529,     0,     0,    80,   268,   495,   269,     0,     0,
       0,     0,     0,     0,   245,   241,     0,     0,   605,   603,
       0,     0,     0,     0,     0,   126,   131,     0,     0,     0,
     583,   584,   143,   377,   169,   177,   178,   183,     0,     0,
       0,     0,     0,   185,   358,     0,     0,   296,     0,     0,
       0,     0,     0,     0,     0,     0,   482,     0,     0,     0,
     571,   501,     0,     0,   184,     0,   205,   362,     0,     0,
       0,     0,   206,     0,     0,     0,     0,     0,     0,   528,
     527,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   379,   380,    42,   187,   188,
       0,   590,     0,     0,   300,   299,     0,     0,     0,     0,
       0,     0,     0,     0,   156,   157,   160,   159,   158,     0,
     619,     0,   656,     0,     0,     0,     0,     0,     0,     0,
       0,   108,   109,   596,     0,     0,     0,   100,     0,     0,
       0,    50,     0,     0,     0,     0,     0,    52,     0,   246,
     242,   243,   244,    38,     0,     0,   653,   354,   285,     0,
     138,   152,     0,     0,   149,     0,     0,     0,   171,   202,
       0,     0,     0,     0,     0,   577,   578,     0,     0,     0,
       0,     0,   508,   483,   496,   498,     0,     0,   186,   209,
       0,     0,     0,   369,   369,     0,   119,   120,   239,     0,
     229,   230,   323,     0,   330,     0,     0,   239,     0,   236,
       0,   356,   234,     0,     0,     0,     0,   537,     0,   115,
     117,   116,   623,   629,   628,   155,     0,     0,     0,   351,
       0,     0,   112,   104,   106,     0,    94,   646,   101,   102,
      55,     0,     0,     0,     0,   530,     0,     0,   496,   604,
       0,     0,     0,     0,   128,   643,     0,   135,     0,     0,
       0,     0,   359,   191,     0,     0,   563,     0,     0,     0,
     326,     0,   175,   176,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   526,     0,   340,     0,     0,   317,
       0,   235,     0,   589,   301,     0,   538,     0,   391,   239,
     409,     0,   594,     0,    51,     0,     0,     0,    68,    53,
       0,   286,   127,   132,   138,     0,     0,   166,   167,   165,
       0,     0,     0,   564,   484,     0,     0,     0,     0,   370,
     384,     0,     0,   385,     0,   227,     0,   331,     0,   313,
       0,   239,   181,   539,   297,   346,   110,     0,     0,     0,
       0,     0,     0,   136,   137,     0,   561,   562,     0,   207,
       0,   388,     0,   389,   390,   525,     0,     0,   319,     0,
       0,    59,     0,    65,     0,     0,   129,     0,   327,     0,
       0,   339,   318,   314,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   360,    56,     0,    63,     0,
     280,   580,     0,     0,   320,     0,    57,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    60,    58,     0,
      61,     0,   386,   387,     0,     0,    66,    64,    62
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,   126,  1128,   127,   128,  1112,  2000,  2006,
    1421,  1647,  2163,  2265,  1422,  2247,  2279,  1423,  2267,  1424,
    1425,  1651,   468,   635,   636,  1202,  1755,   129,   831,   497,
    2020,  2174,  2021,   498,  1889,  1506,  1459,  1460,  1461,  1611,
    1825,  1826,  1281,  1710,  1701,  1899,   805,   647,   299,   300,
     371,   217,   301,   478,   479,   133,   134,   135,   136,   137,
     138,   139,   302,  1316,  2200,  2244,  1008,  1312,  1313,   303,
    1091,   304,   143,  1542,  1279,   980,  1015,  2138,   144,   145,
     146,   147,   305,   306,  1229,  1252,  1379,   307,   836,   308,
     835,   500,   663,   343,  1860,   375,  1969,   376,   310,   605,
    1239,   390,  1405,  1638,   489,   484,  1372,  1071,  1690,  1853,
    1854,  1056,   491,   149,   400
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1983
static const yytype_int16 yypact[] =
{
   13858,    45,   138, 14072, -1983, -1983,   223,   148,   -53,   -92,
     -56,   -49,     9,   143,   224,   263,   279,    52,    43,    49,
      18,   341,   347,   367,   370,   157,   186,    21,  -182,   427,
    -182,   153,   221,   257,    42,   265,   291,    74,   298,   317,
     327,   358,   359,   364,   381,   382,   394,   402,   252,   442,
     473,   631,   655,   405,   371,   584,   423,  7336,   437,   414,
     436,   632,   -73,   585,   427,   362,    15,   459,   629,  -127,
     516,     7,     7,   517,   282,   522,   540, -1983, -1983, -1983,
   -1983, -1983,   534,   129,   714,   721,     8,    53,    50,   544,
     736,   794,    58,  5195,   802,   910,   911,   916,  5195,   918,
     -80,   -63,   669,    22,    76, -1983,   671,   685, -1983, -1983,
    5555,   921,   691, -1983, 14329,   692, 14392,    29,    34,   427,
   -1983, -1983, -1983, 12449,   704,   974, -1983, -1983, -1983, -1983,
   -1983,   720,  1003,  1005, -1983, -1983, -1983, -1983, -1983, -1983,
    1006,   343,  1013, -1983, -1983, -1983,    71, -1983,  1027,   762,
    5657,    24,   764,  1031, 12449, 14265, 14265, 14265, -1983, 12449,
   -1983, -1983, -1983, -1983, 14265, -1983, 12449, -1983, -1983, 12449,
   -1983, -1983, -1983, -1983, -1983, -1983,   766,   772,  1032, -1983,
   -1983,  3058, -1983, -1983, -1983, -1983,   778,  3058, 12449, 12449,
   12449,   779, 12449, 12449, 12449,   780, 12449, 12449, 12449, 12449,
   12449, 12449, 12449, 14265, 12449, 12449, 12449, 12449,  5195,   781,
   -1983, -1983,  9707, -1983, -1983, -1983,   782,  5195,  7600, 14265,
   -1983, -1983, -1983, -1983, -1983,  -182,  -182,  -182,  -182,  -182,
    -182,  -182,  -182,  -182,  -182,  -182,  -182,  -182,  -182,  -182,
    -182,  -182,  -182,  -182,  -182,  -182,  -182,  -182,  -182,  -182,
    -182,   201,  -182,  -182,  -182,  -182,  -182,   783,  -182,  -182,
     784,   427,   507,   507,   507, -1983, -1983, -1983,   803,  -182,
    -182,    36,   846,   849,   870,   808,   968,    93,    -7,  7600,
     942,   427,   427,   507,   815,  -182,  -182,   816,   817,   819,
   -1983, -1983, -1983, 12449,  7864, 12449, 12449,  8128,    21,   884,
      39, -1983, -1983,   818, -1983,  3868, -1983, -1983, -1983, -1983,
   -1983,    88, 12449,  9707,  9707,   821,   823,  8392,  5195,  5195,
    5195, -1983, -1983, -1983,   824, -1983,   822,   828,  8656,   825,
   10687,  1092,  7600,   827,    22,   830,   831,     7,     7,     7,
   12449, 12449,   -78, -1983,    89,     7, 10777,   307,  9707,  9707,
   12449,  5195,  5195,  5195,   444,    19,  1096,   835, -1983,  1098,
    1099, -1983,   836, -1983, -1983, -1983,   838,   839, -1983, -1983,
     840,  5195, -1983, 12449,  2471, -1983,  1091,   841,   844,   845,
     847,  1108,  1110,   851, 12449,   852, 12449, 12449,   418, 12449,
     854, -1983,   917, 12449, 12449, 12449, -1983,  -182, 12449,   623,
     116, -1983, 12449, -1983,  -182,  -182,  -182,   855,   856,   864,
    -182,  -182,  -182,  -182,  -182,  -182,  -182, -1983,  -182, -1983,
   -1983, -1983, -1983,  -182,  -182,   865,   866,  -182,   867, -1983,
     868,  1128,  1129,   885, -1983, -1983,  1131,  1130,  1134,  1146,
     896, 16322, 14265, -1983,  9707, -1983, -1983, -1983, 12449, -1983,
   -1983, -1983,  7600,  7600, -1983,   900,  3058,   427,  1167, -1983,
   -1983, -1983, -1983, -1983, -1983, 12449, 12449,    56,  7600,  1169,
     457,   906,  1455,   907,  1172,    60,   909, -1983,   912, 14524,
   12449, -1983,  1606,  -199, -1983,    95,  -168,  -154,  8852, -1983,
    -103, -1983,   115,  9116,  3876,  4971,  9375,   -22,    -9,  1080,
   -1983,    21,   915, 12449,   925, 16838, 16863, 16888, 12449, 16913,
   16938, 16963, 12449, 16988, 17013, 17038, 17063, 17088, 17113, 17138,
     -10, 17163, 17188, 17213, 15075,  1188, 12449,  9707,  4697, -1983,
     478, 12449,  1197,  1198,   938, 12449, 12449, 12449, 12449, 12449,
   12449, 12449, 12449, 12449, 12449, 12449, 12449, 12449, 12449, 12449,
   12449, 12449,  9707, 12449, 12449, 12449, 12449, 12449, 12449, 12449,
   12449,  9707,  9707,   936, 12449, 12449, 14265, 12449, 14265,  7600,
   14265, 14265, 14265,   937,   939,   940,   941, -1983, 12449,    38,
   -1983, 11041, 12449,   943,   945,   946,    58,   947,  7600,  7072,
    7600,   969, 14265, 14265,  9707,    21,  3058,    21,   975,  9707,
     975, -1983,   975, 17238, -1983,   487,   970,   147,  1140, -1983,
    1204, 12449, 12449, 12449, 12449, 12449, 12449, 12449, 12449, 12449,
   12449, 12449, 12449, 12449, 12449,  8920, 12449, 12449, 12449, 12449,
   12449,    21, 12449, 12449,    92, -1983,   498, 17263,   489,   530,
   12449, 12449, 12449, -1983,  1234,  1237,  1237,   980, 12449, 12449,
   12449, 12449,    27,  9707,  9707, 16350,   981,  1241, -1983,   979,
   -1983, -1983,  -188, -1983, -1983,  9639,  9997,     7,     7,    24,
      24,  -163, 10777, 10777, 12449, 12414,  -135, -1983,   531,   541,
   17288,  1243,  1246,  1247, 12449, 12449,  1249, 12449, -1983, -1983,
   12449, 12478, -1983, -1983,  9707, 12618, 12680,  9707,  9707, 12449,
    1250, 17313,   982, 12449,  9707, 12449, 12449, 12449, -1983, -1983,
   12449, 17338, 12449, 17363, 17388,  1058, 10360, -1983,   988,  5290,
   17413, 17438, 12449,   975, -1983, 12449,    21, 12449, 12449,    92,
   16433, 14265, 14265, 14265, 14265, 14265, 14265, 14265, 14265, 14265,
   12449, 14265, 14265, 14265, 14265,    17,  3058, 14265, 14265, 14265,
      21,    21, -1983, -1983,  9707, -1983,   989, 12786, -1983,   990,
   12848, 12449, -1983,   993,   546, 17463, 14412,   992,   549, 12449,
    1258,   995,  7600, 17488, 16460, -1983, -1983, -1983, -1983, -1983,
   -1983,   994,  1263,   182,  1266, -1983, -1983, -1983,  9707,   218,
   12449, -1983, -1983, -1983,    21, 12449, 12449,    92,  1008, -1983,
    1007,   -32,   427,   362,   427, -1983,  1004, 15104, -1983,   162,
    9707,    21, 12449, 12449,    92,  1271,  9707,  1272,  9707, 12449,
    1273, 14265,    21, 11131,    92, 12449, -1983,  1010, 12449,  1275,
   -1983,    21,  1276, 14265, 12449,  1017,  1018, -1983, 12449, 10634,
    3058,  1278,  1280,  1281, 17513,  1282,  1283,  1286, 17538,  1287,
    1288,  1289,  1290,  1291,  1292,  1293, -1983, 12449,  1295,  1297,
    1298, -1983, 12449, 17563,  9707,    57,  9707, 15133, -1983, -1983,
    1300, 16406, 16406, 16406, 16406, 16406, 16406, 16406, 16406, 16406,
   16406, 16406, 16406, 10718, 16406, 16406, 16406, 16406,   748,   542,
   16406, 16406, 16406, 10988, 11072, 11345, 11421, 11693,  4697,  1040,
    1039,   106,  9707, 11777, 12042,   542, 12126,   542,  1034,  1035,
    1036,   151,  9707, 12449, 12449, 12449, 18338, -1983,   542,  1041,
   15162, 15191, 12449, 12449, 12449,  1044, 12449,  5973, -1983, -1983,
   12449,  1042,   278,   542,   332,  1048,   377,   551,  1311, -1983,
      92,   542,  7600,  1049,  5590,  5691,   809,   524,   893,   893,
     539,   539,   539,   539,   539,   539,   398,   398,  9707,  -100,
   -1983,  -100,  -100,   975,   975,   975,  1047, 17588, 16487,   228,
    9707, -1983,  1314,  1052,  1053, 17613, 17638, 17663, 12449,  7600,
    1321,  1320, 10428, 17688, 15220, 17713, 17738, -1983, 12449,   552,
     560,  9707,  1055, -1983, 12954, -1983, 13016, 13122,     7, 12449,
   12449, -1983, -1983,  1059,  1060, 10777,  6477,  1180,   -35,     7,
   13184,  1062,  1065,  1329, 12449,  1332, -1983, 12449, 17763, 15249,
   -1983, 16514, 13290, 16541, -1983,   563,  1335,  1072,   565,   566,
   15278, -1983, -1983, -1983,  1786,   568, 16568, 16595, 12404, 17788,
    1336, 17813,  1337,  1338,  1074, 12449, 13352, 12449, 12449, -1983,
   -1983, 16406,  -100,  1075,   491,    40,   352,   369,   352,  1081,
    1082,  1076,   542,   542,  1078, 13665,   542,   542,   542,   542,
   12449,   542,  1341, -1983,  1079,  1093,   412,    -4,  1087,   571,
   -1983, -1983, -1983, -1983, 17838, 13458,  1084,  1157,  1356,  1194,
   11390,  1094,  1097,  1360,  7600, 15307, -1983, 12449,  1362,   188,
      94,    92,    26,  3058, 12449,  1363, -1983,   576,  1323,  1328,
    7600, 15336,    32,  1107, 17863, 16622,   452, 12449, 12449,  1105,
    1112,  1114,  1113,  9184, -1983, -1983, -1983, -1983, 14265,   168,
    1115, 17888, 16649,  1118, -1983,   213, -1983,   266, 13857, -1983,
   -1983, -1983,  1117, -1983,  1119, 15365, 12449, 14340, -1983,    96,
   -1983, -1983, 18338, -1983,   159, 16406, 12449,   542,     7,  7600,
    7600,  1379,  7600,  7600,  7600,  1383,  7600,  7600,  7600,  7600,
    7600,  7600,  7600,  6741,  7600,  7600,  7600,  2406,  1384, -1983,
      24,  4697, -1983, -1983, -1983, -1983, -1983, -1983, -1983, -1983,
   -1983, -1983, -1983, -1983, -1983, -1983, -1983, 12449, -1983, -1983,
   -1983, -1983, -1983, -1983, -1983, -1983, -1983, 12449, 12449, 12449,
   12449, 12449, -1983, -1983, -1983,   578, 12449, 12449, -1983, 12449,
   -1983,  7600, 14265, 14265, -1983,   579, 15394, 15423, 15452,  1120,
   -1983, -1983, -1983,  1190, 15481, 15510, 15539, 12449, 15568,   581,
   -1983, 15597, 12449, 12449, -1983, -1983, -1983,    92, -1983,    92,
   12449, 12449,  1126, -1983,  7600,  -182, -1983, -1983, -1983, 12449,
   12449,   587,    92,  -190,  -136, 12449, 12449, -1983,   542,   589,
    7600,  9707,  9707,  1387,  1389,  1390,  6018, -1983, -1983,  1392,
   -1983,  1133, 18338,  1132,  1397, -1983,  1398,  1401,  2531,  1402,
    1403,   614,   105, -1983, 13520, -1983, -1983,  -120, 14448, 14481,
   -1983, -1983, 15626,  -138,  1294,  1407, 11487,  1142,  1410,  1147,
      44,    47,   304, -1983,   -67, -1983,   -35,    24,    24,  7600,
   18338, -1983,  2671,  1148,  1315,  1413, -1983,  1415,  1416, -1983,
   12449,  1312,  1417, -1983, -1983,  1418,  1421,  1422, 12449,  1423,
    7600,  1425,  7600,  7600,  1431, 14514, -1983,  5906,   978,    92,
   12449, 12449,    92,    92, -1983,  9707, -1983, -1983, -1983, -1983,
   14265, -1983, -1983, 12449, 14265, -1983, -1983, -1983, -1983, 18338,
   -1983,  1156,  1161, 14265, -1983, 14265, -1983,    92, 14265,  1173,
   -1983,  1164,  1435, -1983,  1174,   427,  1175, 11746, -1983,  2703,
    1176,  7600, -1983,  1171, -1983, 15655, -1983, -1983, 12449,  1437,
     440, 12449,  1441,  1443,    22,  1445,  1185,  1448,  2727, -1983,
     542,  -182,  -182,  1449, -1983, -1983,  1191,  1192,  1186, -1983,
    1453, -1983, -1983, -1983, -1983, -1983, -1983,    92,   318,  2136,
   12449, 16676, 17913, 12449,  6285, 12449,  9707,  1189,   620,  1456,
     167,    92, -1983,  1195, 12449,  1457,  1460, 12449,    92, 11836,
    1462,  7004, 12449,  9966,   542,  6544, 12449, 12449, 12449,  1201,
    1196, -1983,  1466, 17938,  1467,    46,  1333,  1333,  7600,  1468,
    1470,  1471,  7600,  -117,  1472,  1473,  1474,  1475,  1478,  1479,
   -1983, 12449,  1481,  1483,  1487, -1983,  1489,  1224, 16406, 16406,
   16406, 16406, 16406, 16406,   542, 14547, 14580, 14613,  1230,   542,
     542, -1983, -1983, -1983, -1983,   159,   542,  1369,  1370,  1371,
   15684,  1299, -1983,  3058, -1983, 17963, 16406,  1235,   408, 18338,
   16406, -1983,  1497,   542, 18338, 18338, -1983,   453, -1983,    92,
   -1983, 17988, 16703, -1983,   542,  1498,   625,   626,  7600,  7600,
    7600,  1501,  1500, -1983,   222, 12449,  7600,  7600,  7600, -1983,
    1238,  1240,  1504,  1508,  1509, -1983, 12449, 12449, 12449,  1248,
    1251,  1252,  1239, -1983,  3228,  7600, -1983, 12449, -1983,  1511,
   -1983,  1513, -1983, -1983, 10777,   393,  1253,  1254,  1514, -1983,
    9707,  1256, -1983, -1983, -1983,  7268,  1257, 12449, 12449, -1983,
   -1983, 16730,  7600,  1517,  7600,  1522,  1331, -1983, 12449, 12449,
   12449, -1983,   591,  1524,   184,   413,  1259,  6218,  1264, 12449,
      12,   542,  1265,   542,  1267, -1983, -1983,  3058, -1983, 12449,
    1261, -1983, -1983,  3297, -1983, -1983,  1274,  1534, -1983,  3326,
   -1983,  1269,  1539,   192,  3390, -1983,    22, -1983,   627, -1983,
   12449, -1983, -1983,   222,  4171,  4313, -1983,  1284, 12449, 12449,
    7600,  1277, -1983,   172,   597,  1542, 18013,  1545,  1311, 18038,
    1285,   633,   635, 18063,   636,  1546,  1547, -1983, -1983, 14265,
    1301,  1550, 18088, -1983, -1983, 14646,  1302, -1983, -1983, -1983,
   12449,  7532,  6808, 18338, -1983,  1548,  -182,  8128, -1983, -1983,
   -1983, 18338, 18338, 18338, -1983,   159, -1983,  1551, -1983, -1983,
       7,  1552,  1553,  1554, -1983, -1983, -1983,  1412,   -43,  1454,
    1558, -1983, -1983, -1983, -1983, -1983, -1983,  7797, -1983, -1983,
   -1983,  1561,  1563, -1983, -1983, -1983, -1983, -1983, -1983, -1983,
   12449, 12449, 12449, -1983, -1983, -1983,  1196, -1983,  1303,  1304,
    1305, -1983,  1459, -1983, -1983, -1983, -1983, 12449,  1309,  1296,
   -1983, -1983, 12449, 12449,   542,  -190, -1983, -1983, -1983, -1983,
    1310,  1313,  1566,  -117,  1573, 12449, -1983,  7600, 18338,  1432,
    1433,   880,  9707,  9707, 12449, -1983, 10428, 15713, 18113,  8060,
      24,    24, 12449, 12449, -1983,   149,  1317, 18138, -1983, -1983,
   15742,   -27, -1983, -1983, -1983, -1983,   641,  9707, -1983, 12449,
   12449,  3530,  3583,  1579,  1581, -1983,  1582, -1983,  7600,  8324,
     256, 18163, 12449, 12449, -1983, -1983, 10065, -1983, 14265, 12449,
   -1983, 14265, 18338, 10329,  3058,  1318, -1983, -1983, -1983, -1983,
    1327,  1322, 15771, 12449, 14412, -1983, 14412,  7600, -1983, -1983,
      92,    26,  3058, 12449,  1584, -1983,  1590, -1983,    22, 16757,
    7600, 14265,  1592,   542, -1983,  1324,   542, 12449, 14679, 14712,
     650, -1983, 12449, 12449,  1330, -1983,  1334, -1983,  1390,  1595,
    1596,  1599,  1401,  1600, -1983, -1983,  1601, 12449, -1983, -1983,
   12449, 12095, 15800,  1602, 12449, -1983, -1983,  1339,  4313,   659,
    5132,  1603, -1983, -1983,   289, -1983, -1983, -1983,  1461,  1607,
    1347,  1349,  1350, -1983, -1983, 12449,  1616, -1983, 16406, 16406,
   14745, 12449, 12449, 12449,  1352, 16406, -1983,  1357, 18188, 16784,
   -1983, -1983,  9707,  9707, -1983,  1617, -1983, 18338,  1619, 12449,
   12449,  1358, -1983,   661,   667, 16378,  3615,  1620,  1359, -1983,
   -1983, 12449,  1361,  1365, 15829, 16811,  1621,  7600,  1623,  1364,
   12449,  1625,   672, 15858, 15887, -1983, -1983, -1983, -1983, -1983,
    1440, -1983, 12449, 12449, -1983, -1983, 12185,  9443,  3949,  1632,
    1633,  1373, 16406,   542, 18338, -1983, -1983, -1983, -1983,    12,
   -1983,  3058, -1983, 15916,  1372,  1374,  1375,  1637,  1642,  1643,
    4078, -1983, -1983, -1983,  1378,  1654,   677, -1983,  1659,  1664,
     395, 18338, 12449, 12449,  1404,  7600,   679, 18338, 18213, -1983,
   -1983, -1983, -1983, -1983, 18238, 14778, -1983, -1983, -1983, 15945,
    1120,  1161,  7600,   542, -1983, 12449,  3058,    21, -1983, -1983,
    9707,  9707, 12449, 18263,  1665, -1983, -1983, 12449, 14811, 15974,
   14844, 12449,  1296, -1983, -1983, -1983,   682,   689, -1983, -1983,
    4345,  4428,  7600,   545,   554,  9707, -1983, -1983,    24,  8588,
   -1983, -1983, -1983,  1669, -1983,  1405,  7600, -1983, 16003, -1983,
    1672, -1983, -1983, 12449, 16032, 16061,  9707, -1983,   690, -1983,
   -1983, -1983, -1983, -1983, -1983, -1983,  1414,  1676,  1420, -1983,
    1677,    22, -1983, -1983, -1983,  1485, -1983, -1983, -1983, -1983,
   -1983, 12449, 14877, 14910,  7600, -1983,  1681, 12449,  1424, -1983,
   12449,  1685,  1446,  1447, -1983, -1983,  3485, -1983,  1426,   695,
     698, 16090, -1983, -1983, 14943, 12449, -1983, 12449, 16119,  1428,
   -1983,  1451, -1983, -1983,   700,  1458,     7,  7600,  1687,  1463,
       7,  1690,   703,  1452, -1983, 12449, -1983,  1710,  1570, 13626,
    1464, -1983,  4463, -1983, -1983,   706, -1983,  1719, -1983, -1983,
   -1983,  1720, -1983,  1465, 18338, 12449, 12449,   712, -1983, 18338,
   14976, -1983, -1983, -1983,  1120,  3058,  1469, -1983, -1983, -1983,
   12449, 16148, 16177, -1983, -1983,  9707,  1721,     7,   131, -1983,
   -1983,     7,   135, -1983,  1723, -1983, 16206, -1983, 12449, -1983,
     -35, -1983, -1983, -1983, -1983, 14412, -1983, 12449, 18288, 15009,
      69, 12449,  1476, -1983, -1983, 15042, -1983, -1983,   739, -1983,
     193, -1983,   264, -1983, -1983, -1983,  4723,   431, 13688,  1477,
     751, -1983, 12449, -1983,  7600, 16235, -1983, 12449, -1983,     7,
       7, -1983, -1983, -1983,   -35,  1724,  1725,  1480, 18313,   752,
    1726, 16406,   271,   275,   492, -1983, -1983, 14265, -1983,  1482,
   -1983, -1983, 12449, 12449, -1983,   754, -1983,  1484,  7600, 16264,
   16293,  1732, 14265, 14265,   757,  1733,  1734, -1983, -1983,   760,
   -1983,  1740, -1983, -1983,  1743, 14265, -1983, -1983, -1983
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1983, -1983, -1983, -1983,   311, -1983, -1983, -1983, -1983,  -452,
   -1983, -1983, -1983, -1983, -1983, -1983, -1983, -1983, -1983, -1983,
   -1983, -1983,  -778,  -137,  4767,  3998,  -459, -1983,  1262, -1983,
   -1983, -1983, -1983, -1983, -1983, -1980, -1983,   251,    62,  -262,
   -1983,  -218, -1983,    -1,   299, -1983,  1762, -1983,   920,   -51,
    1181, -1983,    16,  -652,   268, -1983, -1983, -1983, -1983, -1983,
   -1983,   660,  1768, -1983, -1983, -1983, -1983, -1313, -1308,  1770,
   -1814,  1771, -1983, -1983, -1983,  1135, -1983,  -279, -1983, -1983,
   -1983, -1983,  2701, -1983, -1983, -1508,   163,  1773, -1983,     0,
   -1983, -1983,   -65, -1983, -1982,   996, -1983,   -69,  3068,  1089,
     344,  -333,   -62, -1983,   450,   -79, -1983, -1983,   -41,   139,
   -1778,  -162,   959, -1983,    -3
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -606
static const yytype_int16 yytable[] =
{
     150,   659,   490,  1575,  1573,  1104,   342,   344,   783,   347,
    1748,  1110,   355,   469,   328,   158,  1823,  1003,  1004,   132,
    1984,   176,  1985,   686,   178,   176,   388,   177,   476,   381,
     176,   383,  1708,   987,   436,   431,  1415,   435,   316,   438,
    2112,   580,   176,   333,   609,  1977,   191,  1352,   385,   165,
    1568,     4,  1699,  1570,   311,   167,   363,   360,   154,   361,
     775,   586,  1900,  1179,   176,   317,   667,   668,   809,   794,
    2134,   474,   334,   463,   464,  2233,   810,   451,   195,   316,
     392,  1901,   776,   359,   179,  1709,   180,   998,   335,   336,
     311,   667,   668,   777,   778,   311,   775,   631,   587,   815,
     391,  1397,   502,  1453,   811,   356,  1119,   816,   504,  1553,
    2023,   432,  1005,   817,  1305,   631,   667,   668,   776,   667,
     668,   818,  2167,   329,   822,   726,   330,   463,   464,   777,
     778,   776,  1306,  1560,   667,   668,  1529,  2221,     5,   525,
    1009,  2223,   777,   778,  1307,  1308,  1309,   475,   532,   160,
    1310,  1311,   485,   485,   485,  1556,   501,   611,   362,   628,
     629,   492,   153,  1455,   820,   630,   368,   477,  1125,   369,
     779,   780,   821,  1668,   155,   969,   667,   668,    70,    71,
      72,    73,   370,    75,    76,  1456,   384,   667,   668,  1103,
    1815,  1816,   669,    85,  2212,  1397,  1457,  1458,    90,  1842,
     485,   584,   988,   386,   585,   311,   779,   780,  1574,   311,
     156,   574,   575,   576,   311,   311,   485,   157,   357,   779,
     780,  1416,  1417,  1418,  1419,  1108,  1824,   667,   668,  1397,
     161,  1569,   591,   104,  1571,   105,   106,   107,   108,   109,
     351,  1917,   352,   113,   114,   124,   116,   829,  1950,   644,
     645,   646,  2249,   830,   124,   781,   782,   856,   124,   124,
     832,   338,   339,   124,  1963,   857,   830,  1573,  1377,   162,
    1054,  1378,   662,   340,   664,   124,   311,   341,   358,   159,
     671,   676,   681,   682,   683,   163,  2274,   687,   169,   688,
    1070,   311,   389,   152,   311,   607,  1404,   124,   606,   437,
     667,   668,   700,  1420,   439,   786,   581,   787,   192,   610,
     311,   311,  1353,   166,   311,   311,   311,   311,   164,   168,
     364,  1398,  1401,   463,   464,   311,   795,  1180,   796,   311,
    -598,   391,   797,   459,   460,   461,   462,   452,  1116,  2234,
     196,   453,   393,   667,   668,   311,   311,   170,   311,   311,
     311,   463,   464,   171,   632,  1133,   633,   463,   464,   670,
     634,   812,   179,   813,   180,  1144,  1400,   814,   311,   463,
     464,   311,   632,   172,   633,  1214,   173,   770,   634,   463,
     464,   823,   727,   813,   728,   667,   668,   824,   729,   667,
     668,  2229,   612,   613,   614,   615,   616,   617,   618,   619,
     620,   621,   622,   623,   624,   625,   626,   627,   628,   629,
     911,  1126,  1127,   179,   630,   180,  1126,  1127,  1224,   188,
    1946,   459,   460,   461,   462,   174,   821,   459,   460,   461,
     462,   459,   460,   461,   462,  1440,   494,   495,  1863,   485,
    1813,   311,  -602,   866,   775,   463,   464,   667,   668,   311,
     311,   463,   464,  1305,   175,   463,   464,   459,   460,   461,
    1109,   459,   460,   461,   462,   311,   776,   561,  2239,   562,
     322,  1306,   798,   323,   324,   325,   213,   777,   778,   214,
    1445,  1255,   215,  1307,  1308,  1309,   326,   189,   866,  1310,
    1311,   463,   464,   151,  1265,   216,  1266,   152,   837,   612,
     613,   614,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   725,   626,   627,   628,   629,   935,   667,   668,
     928,   630,   207,   190,   311,   667,   668,  1964,  1487,   667,
     668,   193,   182,  1446,  2129,   183,   338,   339,   184,  2240,
     185,   866,  1305,   667,   668,   786,  2262,   787,   340,   311,
    2263,    48,   346,  1243,   779,   780,   327,   194,   311,   901,
    1306,   667,   668,   485,   197,   485,   311,   485,   485,   492,
     208,  1058,  1307,  1308,  1309,  1572,   918,   677,  1310,  1311,
    1305,   463,   464,   198,   209,   311,   311,   311,  -600,   485,
     485,   311,   178,   199,   178,   934,   311,   936,  1306,  1246,
     473,  1864,  1001,  1002,  1247,   483,   486,   487,   664,   448,
    1307,  1308,  1309,   449,   675,   322,  1310,  1311,   323,   786,
     325,   787,   311,   776,   200,   201,   691,   821,   966,   724,
     202,   326,   695,   696,   777,   778,   786,   210,   787,  1631,
    1632,  1305,  1403,   179,  1355,   180,  1105,   203,   204,  1249,
     311,   311,  1250,   520,   725,   626,   627,   628,   629,  1306,
     205,   211,  2100,   630,  1792,  1576,  1577,  1073,   206,   534,
    2101,  1307,  1308,  1309,   179,   212,   180,  1310,  1311,   786,
     786,   787,   787,  1250,   313,   477,   477,  1375,   866,   219,
     715,   311,   152,   318,   311,   311,   319,   218,   320,  2135,
    2136,   311,  2242,   312,  2137,   757,   314,   760,  2139,  2140,
     684,   779,   780,  2137,   685,   463,   464,   766,  1430,  1752,
    1351,  1753,  -601,  1053,   786,   331,   787,   788,   492,   485,
     492,   485,   485,   485,   485,   485,   485,   332,   485,   485,
     485,   485,  1072,   315,   485,   485,   485,   178,  1078,   865,
    1077,   311,  1121,   866,   463,   464,   611,  1350,   939,  1351,
     973,  1157,   866,  2264,   866,   786,  1767,   787,   970,   311,
     615,   616,   617,   618,   619,   620,   621,   622,   623,   624,
     725,   626,   627,   628,   629,   311,   337,   345,  1517,   630,
    1518,  1113,   348,   623,   624,   725,   626,   627,   628,   629,
     350,   974,  1011,  1527,   630,   866,   866,   311,  1130,   786,
     349,   787,  1012,   311,   365,   311,   866,  1087,   492,  1142,
    1093,   866,  1253,  1289,  1094,   353,   866,   866,  1149,   354,
     485,  1290,  1267,  1554,  1328,   866,  1331,  1332,   866,  1335,
     866,   866,  1381,   866,   366,   495,   866,  1410,  1240,  1494,
    1501,   866,  1512,   866,   866,  1843,  1513,  1812,  1526,  1813,
    1534,   311,   866,   311,   866,  1850,   612,   613,   614,   615,
     616,   617,   618,   619,   620,   621,   622,   623,   624,   725,
     626,   627,   628,   629,  1931,  1552,  1932,  2227,   630,   866,
    1602,  1666,   763,  1603,  1604,   866,  1760,  1761,  1847,   311,
     866,   866,  1848,  1283,  1870,   367,  1871,  1873,   866,   311,
    1513,   866,  1951,   377,   378,   379,   866,  1267,  1614,  1573,
     380,  2004,   382,   131,   311,  2005,   994,   401,   996,   997,
    2024,  2254,  2053,  1297,  2025,   387,   866,   394,  2054,   311,
    1303,  1633,   866,  2070,  1314,  1010,  1573,   866,  2097,   186,
    2106,   395,   821,  2130,  2107,   311,  1022,   866,   433,   402,
    2131,  2156,  1399,  1402,   866,   866,  2177,   311,  1653,  2178,
     866,  2186,   442,   866,  2194,  2005,   311,  2203,   866,  1267,
     443,   866,  1670,  2210,   321,  1046,  1600,  2005,   311,  1676,
     444,   612,   613,   614,   615,   616,   617,   618,   619,   620,
     621,   622,   623,   624,   864,   626,   627,   628,   629,   445,
    2238,   446,   447,   630,   866,   786,   905,   787,   907,   450,
     909,   910,  2246,  2259,  1407,  2271,  2107,  2005,  2281,  2272,
    1085,  2284,  2005,   454,   480,  2285,   455,   481,   499,   440,
     152,   501,   931,   932,   503,   508,   512,   526,  -211,   569,
     572,  -212,   531,   309,   614,   615,   616,   617,   618,   619,
     620,   621,   622,   623,   624,   725,   626,   627,   628,   629,
     471,  1637,  -213,   577,   630,   471,   471,   471,   582,   583,
     588,   592,   595,   596,   471,   597,   608,   640,   449,   641,
     648,   311,   649,  1465,   650,   653,   656,   658,   703,  1406,
     660,   661,   689,   690,   692,   693,   694,   311,   697,   698,
     699,   704,   705,   706,   708,   707,   709,   710,   712,   718,
     311,   734,   735,   471,   717,   485,  1528,  1530,  1942,  1943,
     736,   747,   748,   750,   752,   753,   751,   755,   756,   471,
     758,   617,   618,   619,   620,   621,   622,   623,   624,   725,
     626,   627,   628,   629,   759,   754,   311,   311,   630,   311,
     311,   311,   761,   311,   311,   311,   311,   311,   311,   311,
     769,   311,   311,   311,   772,   785,   790,   792,   793,   151,
     834,   573,  1057,   799,  1059,  1060,  1061,  1062,  1063,  1064,
     838,  1066,  1067,  1068,  1069,   862,   477,  1074,  1075,  1076,
     840,   589,   590,   868,   869,   870,   902,   912,   942,   913,
     914,   915,   943,   922,   533,   923,   924,   926,   311,   485,
     485,   612,   613,   614,   615,   616,   617,   618,   619,   620,
     621,   622,   623,   624,   725,   626,   627,   628,   629,   930,
     630,   978,   940,   630,   979,  1601,   982,   993,   992,   995,
    1014,   311,  1016,  1033,  1017,  1020,  1031,  1044,  1047,  1092,
    1080,  1082,  1086,  1294,  1096,  1097,  1101,   311,   311,   311,
    1102,  1140,  1106,  1118,  1123,   309,  1117,  1134,  1136,  1139,
    1146,  1148,  1150,  1151,  1153,  1158,  1154,  1159,  1160,  1162,
    1163,  1528,  1530,  1164,  1166,  1167,  1168,  1169,  1170,  1171,
    1172,   530,  1174,  1846,  1175,  1176,  1184,  1212,  1213,  1221,
    1222,  1223,  1231,   643,  1237,  1248,   311,  1242,  1254,  1262,
    1258,  1270,  1271,  1272,   652,  1278,  1280,  1292,   657,  1304,
    1300,  1301,  1317,   477,   477,  1318,  1319,   311,  1321,   311,
     311,  1329,  1330,  1340,  1342,  1343,  1344,  1349,  1358,  1359,
    1371,  1360,   311,  1363,  1373,  1240,  1380,   485,  1384,  1385,
    1374,   485,   471,  1386,  1387,  1390,  1392,  1391,  1396,  1409,
     485,  1433,   485,  1411,  1684,   485,  1689,   771,  1412,  1427,
    1435,  1987,  1434,  1436,  1444,  1449,  1468,  1441,   311,  1448,
    1472,  1486,  -214,  1521,  1538,  1505,  1539,  1540,  1543,   806,
    1544,   391,   638,   639,  1546,  1547,  2143,  1545,  1548,  1550,
    1551,  1562,  1565,  1567,   806,   806,  1566,  1561,  1580,  1582,
    1581,  1583,  1584,  1586,  1587,  1588,   485,  1589,  1590,  1609,
    1592,   311,  1594,   311,  1743,  1597,  1610,   678,   679,  1617,
    1616,  1618,  1627,  1630,  1619,  1621,  1625,  1635,   767,   768,
    1636,  1639,   311,  1640,  1641,  1646,  1650,  1648,  1649,  1652,
    1665,   791,  1667,  1673,   784,   311,  1674,  1671,  1678,   311,
    1694,  1695,  1696,  1698,  1704,  1700,  1705,  1706,  1711,  1712,
    1713,  1714,  1855,  1855,  1715,  1716,   471,  1718,   471,  1719,
     471,   471,   471,  1720,  1721,  1722,  1844,  1733,  1738,  1739,
    1740,  1742,  1746,  1750,  1759,  1765,  1766,  1783,  1772,  1791,
    1773,  1774,   471,   471,  1775,  1993,  1776,  1788,  1780,  1789,
    1795,  1781,  1782,  1805,  1793,  1794,  1797,  1800,  1807,  1808,
    1814,  1833,  1828,   764,  1818,   311,   311,   311,  1831,  1821,
    1838,  1840,  1378,   311,   311,   311,  1841,  1862,  1865,  1837,
    1857,  1867,  1874,  1875,  1878,  1887,  1869,  1893,  1895,  1896,
    1897,  1898,   311,  1902,  1903,   908,  1906,  1877,  1881,  1907,
    1914,  1250,  1924,  1911,  1912,  1913,  1916,   311,  1439,  1926,
    1922,  1929,  1930,  1923,   643,  1957,   929,  1958,  1959,   311,
    1991,   311,  1947,  1979,  1980,   806,  1992,  1981,  1997,   821,
    -605,  2009,  2010,  1886,  -603,  2011,  2012,  2013,  2018,  2022,
    2027,   806,   808,  2029,  2028,   806,   806,  2030,  1921,  2031,
    2032,  2034,  2041,  2048,  2043,  2049,  2057,  2064,  2052,  2058,
    2066,  2069,  2060,   391,  2067,  1894,  2061,  2073,  2080,  2081,
    2082,   492,   492,  2088,  2091,  2089,  2090,   311,  2092,  2093,
    2095,   471,   471,   471,   471,   471,   471,   471,   471,   471,
    2096,   471,   471,   471,   471,  2098,   485,   471,   471,   471,
    2099,  2123,  1499,  1500,  2104,  2146,  2147,   806,  2151,   311,
     806,  2157,  2158,  2160,   311,  2162,   806,  2168,   937,  1996,
    2159,  2171,  2176,  2190,  -604,  2184,  2193,  1937,   612,   613,
     614,   615,   616,   617,   618,   619,   620,   621,   622,   623,
     624,   725,   626,   627,   628,   629,  2197,  2172,  2173,  2198,
     630,  2185,  1120,  2195,  1122,  2204,  2206,  2219,  2187,  2224,
    2255,  2256,  2260,  2191,  2201,  2207,  2214,  1970,  2277,  2282,
    2283,   471,   989,   990,  1975,  1978,  2286,  2236,  2245,  2287,
    2257,  1669,  2268,   471,  2273,  2230,  1736,  1892,  2161,  2113,
     833,  2085,  1925,  1989,   311,   130,  1702,   925,  1098,   311,
     311,   140,  1426,   141,   142,  2141,   148,  1830,  1662,  1988,
    1141,   981,  1976,  1025,  1856,     0,  1028,  1029,     0,     0,
       0,     0,  1334,  1035,   311,     0,   477,   477,     0,     0,
       0,     0,     0,     0,     0,   311,     0,     0,     0,     0,
    1606,     0,     0,     0,  1608,   485,     0,     0,   485,     0,
       0,     0,     0,  1612,     0,  1613,     0,     0,  1615,     0,
       0,     0,     0,     0,   311,     0,     0,     0,  1406,     0,
       0,     0,     0,  1079,     0,   391,     0,   311,   492,   612,
     613,   614,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   725,   626,   627,   628,   629,     0,     0,     0,
       0,   630,     0,     0,     0,     0,     0,  1107,     0,  1655,
       0,     0,     0,     0,     0,   492,     0,     0,     0,  1834,
       0,     0,     0,  1836,     0,     0,     0,     0,     0,  1129,
       0,     0,  2086,     0,     0,  1135,     0,  1137,     0,     0,
       0,     0,     0,     0,   806,     0,   806,   806,     0,   311,
     311,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     806,     0,     0,     0,     0,     0,     0,     0,  1257,     0,
       0,     0,   806,     0,   311,     0,     0,  2117,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   311,     0,   806,     0,     0,     0,
       0,     0,     0,     0,     0,  1277,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1215,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1225,   311,     0,     0,   806,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   311,
       0,     0,     0,     0,  2118,     0,     0,   311,   311,   612,
     613,   614,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   725,   626,   627,   628,   629,  1261,   471,   311,
       0,   630,   311,     0,     0,     0,     0,     0,     0,  1269,
       0,     0,     0,   311,     0,     0,     0,     0,     0,     0,
       0,  2188,     0,   311,   477,  2192,     0,     0,     0,     0,
    1291,     0,     0,     0,     0,     0,     0,     0,   391,     0,
    1393,     0,     0,     0,     0,     0,  2213,     0,     0,     0,
       0,   311,     0,     0,     0,     0,  1413,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1876,
       0,     0,  2220,     0,     0,     0,  2222,     0,     0,     0,
       0,     0,     0,     0,   311,     0,     0,     0,     0,     0,
     176,   403,   471,   471,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1466,  1467,     0,  1469,  1470,
    1471,     0,  1473,  1474,  1475,  1476,  1477,  1478,  1479,     0,
    1482,  1483,  1484,     0,  2252,  2253,     0,     0,     0,     0,
       0,     0,   311,     0,     0,     0,   404,   405,   406,   407,
     408,   409,   410,   411,   412,     0,     0,     0,     0,   413,
     414,   415,   416,     0,     0,     0,     0,   417,   418,   419,
     420,     0,  1438,     0,   806,     0,   421,  1498,   422,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   311,     0,     0,   423,     0,     0,   424,     0,     0,
       0,   182,     0,     0,   183,     0,     0,   184,     0,   185,
    1522,     0,     0,     0,   485,     0,     0,     0,     0,     0,
      48,     0,     0,     0,     0,   311,  1535,     0,  1971,   485,
     485,  1973,     0,     0,     0,     0,     0,     0,     0,     0,
     471,   457,   485,     0,   471,     0,     0,     0,     0,     0,
       0,     0,     0,   471,     0,   471,     0,     0,   471,     0,
       0,     0,     0,     0,     0,  1620,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1578,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2149,  1593,     0,  1595,  1596,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   471,
       0,     0,     0,     0,   425,   426,   427,     0,     0,     0,
    1536,  1537,     0,     0,     0,     0,   428,     0,     0,     0,
     429,     0,   430,   124,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1626,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   463,
     464,     0,     0,     0,     0,     0,  -599,     0,  1654,     0,
       0,     0,  1485,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2205,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1605,     0,     0,     0,     0,     0,
       0,  1688,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1703,     0,     0,     0,  1707,  2228,
       0,     0,     0,     0,   220,     6,     0,     0,     0,   702,
       0,   221,   222,   223,     0,     0,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,     0,     0,
       0,     0,     0,  1661,     0,  1664,     0,     0,     0,     0,
     256,   257,   258,   259,  1762,  1763,  1764,  1549,   260,   261,
       0,     0,  1769,  1770,  1771,     0,     0,     0,   262,   263,
     264,     0,     0,     0,   265,   266,   267,     0,     0,   268,
       0,  1786,     0,     0,   471,   471,     0,   269,    27,     0,
     270,     0,     0,     0,     0,     0,   271,     0,     0,   272,
       0,     0,   273,     0,   274,     0,     0,     0,  1804,   471,
    1806,    44,     0,     0,     0,   275,   276,   277,     0,     0,
     278,     0,     0,     0,     0,     0,     0,     0,     0,   279,
       0,    59,    60,     0,   280,     0,   281,     0,     0,   282,
       0,     0,     0,     0,     0,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,     0,     0,     0,
      85,     0,     0,     0,    89,    90,  1861,     0,     0,   612,
     613,   614,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   725,   626,   627,   628,   629,     0,     0,  1796,
     283,   630,     0,     0,     0,     0,     0,  1579,  1885,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   284,     0,
       0,     0,   285,   286,     0,     0,     0,     0,   287,   288,
     289,     0,   290,   291,   292,     0,     0,  2266,   124,  1624,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2278,  2280,     0,   293,   527,     0,     0,     0,
       0,     0,   295,  1642,     0,  2288,     0,   373,   471,     0,
       0,   471,   604,     0,   298,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   806,     0,   806,     0,     0,     0,
       0,     0,     0,  1928,     0,     0,     0,     0,     0,     0,
       0,   471,     0,     0,   612,   613,   614,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   624,   725,   626,   627,
     628,   629,     0,     0,     0,     0,   630,     0,     0,     0,
       0,     0,     0,     0,  1960,     0,     0,     0,   471,     0,
       0,   399,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   441,     0,     0,     0,     0,     0,
       0,     0,     0,  1986,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1995,     0,     0,     0,
       0,   472,     0,     0,     0,   482,     0,     0,     0,     0,
     488,  1933,  1934,     0,     0,     0,     0,   493,     0,     0,
     496,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1952,     0,     0,   505,
     506,   507,     0,   509,   510,   511,     0,   513,   514,   515,
     516,   517,   518,   519,     0,   521,   522,   523,   524,     0,
       0,     0,     0,   528,   612,   613,   614,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   624,   725,   626,   627,
     628,   629,     0,     0,     0,     0,   630,     0,     0,     0,
       0,     0,     0,  2065,     0,     0,   612,   613,   614,   615,
     616,   617,   618,   619,   620,   621,   622,   623,   624,   725,
     626,   627,   628,   629,     0,     0,     0,     0,   630,     0,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   621,
     622,   623,   624,   725,   626,   627,   628,   629,     0,     0,
       0,     0,   630,     0,   598,   600,   602,   603,   528,     0,
       0,  2105,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2046,  2047,   637,   528,   528,     0,     0,  2114,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   655,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   665,   666,     0,     0,     0,     0,   666,  1861,   528,
     528,   680,     0,     0,     0,     0,  2078,     0,     0,     0,
       0,     0,  2148,   403,     0,     0,     0,     0,     0,   806,
       0,     0,     0,     0,   701,   528,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   711,     0,   713,   714,     0,
     716,     0,     0,     0,   719,   720,   721,     0,     0,   723,
    1861,     0,     0,   730,     0,     0,     0,     0,   404,   405,
     406,   407,   408,   409,   410,   411,   412,     0,     0,  2119,
    2120,   413,   414,   415,   416,   806,     0,     0,     0,   417,
     418,   419,   420,  2189,     0,     0,     0,     0,   421,     0,
     422,     0,     0,     0,  2142,   528,     0,     0,   806,   765,
       0,     0,     0,     0,     0,     0,   423,     0,     0,   424,
       0,     0,     0,     0,     0,  2155,   773,   774,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   471,     0,     0,
       0,   807,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   471,   471,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   839,   471,     0,     0,     0,   844,
       0,     0,     0,   848,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   863,   600,     0,
    1861,     0,   867,     0,  1784,     0,   871,   872,   873,   874,
     875,   876,   877,   878,   879,   880,   881,   882,   883,   884,
     885,   886,   887,   888,   890,   891,   892,   893,   894,   895,
     896,   897,   898,   898,  1861,   903,   904,     0,   906,     0,
       0,     0,     0,     0,  2218,     0,   425,   426,   427,   916,
     529,     0,   920,   921,     0,     0,     0,     0,   428,     0,
       0,     0,   429,     0,   430,   898,     0,     0,     0,     0,
     528,     0,     0,  1835,     0,     0,     0,     0,     0,     0,
       0,     0,   944,   945,   946,   947,   948,   949,   950,   951,
     952,   953,   954,   955,   956,   957,   959,   961,   962,   963,
     964,   965,  1839,   967,   968,     0,     0,     0,     0,     0,
       0,   975,   976,   977,     0,     0,     0,     0,     0,   983,
     984,   985,   986,     0,   528,   528,     0,     0,     0,     0,
       0,     0,   601,     0,     0,   529,     0,     0,     0,     0,
       0,     0,     0,   598,   723,  1006,     0,     0,     0,     0,
       0,   529,   529,     0,     0,  1018,  1019,     0,  1021,     0,
       0,  1023,     0,     0,     0,   528,  1845,     0,   528,   528,
    1030,     0,     0,     0,  1034,   528,  1036,  1037,  1038,     0,
       0,  1039,     0,  1041,     0,     0,   529,   529,     0,     0,
       0,     0,     0,  1051,     0,     0,  1052,     0,   967,   968,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1065,   529,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   528,     0,     0,     0,     0,
       0,     0,  1084,     0,     0,     0,     0,     0,     0,     0,
    1095,   612,   613,   614,   615,   616,   617,   618,   619,   620,
     621,   622,   623,   624,   725,   626,   627,   628,   629,   528,
       0,  1111,  2175,   630,     0,     0,  1114,  1115,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   528,   529,  1131,  1132,     0,     0,   528,     0,   528,
    1138,     0,     0,     0,  1131,     0,  1145,     0,     0,  1147,
       0,     0,     0,     0,     0,  1152,  1955,     0,     0,  1155,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   621,
     622,   623,   624,   725,   626,   627,   628,   629,  1173,     0,
       0,     0,   630,  1177,     0,   959,     0,  1181,     0,   612,
     613,   614,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   725,   626,   627,   628,   629,     0,     0,  1956,
       0,   630,     0,     0,     0,   601,     0,     0,     0,     0,
       0,     0,     0,   528,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   528,  1226,  1227,  1228,     0,     0,     0,
     889,  2056,     0,  1234,  1235,  1236,     0,  1238,   528,   899,
     900,  1241,     0,   612,   613,   614,   615,   616,   617,   618,
     619,   620,   621,   622,   623,   624,   725,   626,   627,   628,
     629,     0,     0,     0,     0,   630,     0,     0,     0,   528,
       0,     0,   933,     0,     0,     0,     0,   529,     0,     0,
       0,   528,     0,     0,     0,     0,     0,     0,     0,  1276,
       0,     0,     0,  1282,     0,     0,     0,     0,     0,  1288,
       0,     0,   528,   960,     0,     0,     0,     0,     0,     0,
    1298,  1299,     0,     0,     0,     0,  1302,     0,     0,     0,
       0,     0,     0,     0,     0,  1320,     0,     0,  1322,     0,
       0,   529,   529,     0,     0,     0,     0,     0,   612,   613,
     614,   615,   616,   617,   618,   619,   620,   621,   622,   623,
     624,   725,   626,   627,   628,   629,  1345,     0,  1347,  1348,
     630,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   529,     0,     0,   529,   529,     0,     0,     0,
       0,  1369,   529,   612,   613,   614,   615,   616,   617,   618,
     619,   620,   621,   622,   623,   624,   725,   626,   627,   628,
     629,  1389,     0,     0,     0,   630,     0,     0,  1395,     0,
       0,     0,     0,     0,     0,  1408,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1431,  1432,
       0,     0,   529,     0,   528,     0,   612,   613,   614,   615,
     616,   617,   618,   619,   620,   621,   622,   623,   624,   725,
     626,   627,   628,   629,     0,     0,     0,  1451,   630,     0,
       0,     0,     0,     0,     0,     0,   529,  1463,   612,   613,
     614,   615,   616,   617,   618,   619,   620,   621,   622,   623,
     624,   725,   626,   627,   628,   629,   611,     0,   529,     0,
     630,     0,     0,     0,   529,     0,   529,     0,     0,     7,
       8,     0,     0,     0,     0,     0,     0,     0,  1488,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1489,  1490,
    1491,  1492,  1493,     0,     0,     0,     0,  1495,  1496,     0,
    1497,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   960,     0,  1182,     0,     0,     0,  1510,     0,
       0,     0,     0,  1515,  1516,     0,     0,     0,     0,     0,
       0,  1519,  1520,     0,     0,  2079,     0,     0,     0,     0,
    1524,  1525,     0,     0,     0,     0,  1531,  1532,     0,     0,
     529,     0,   528,   528,     0,     0,     0,     0,     0,     0,
     529,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,     0,   529,     0,    45,    46,    47,
      48,     0,     0,     0,     0,    50,     0,  1564,     0,     0,
       0,     0,     0,     0,   800,    58,     0,     0,    61,   801,
       0,   802,   803,     0,   804,     0,   529,     0,     0,     0,
       0,  1585,     0,     0,     0,     0,     0,     0,   529,  1591,
       0,     0,    82,     0,     0,     0,     0,     0,     0,     0,
       0,  1531,  1532,     0,     0,     0,   528,     0,     0,   529,
       0,     0,     0,     0,  1607,     0,     0,     0,     0,     0,
     100,   101,   102,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2094,     0,     0,     0,  1623,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1629,
       0,     0,  1634,     0,     0,     0,     0,     0,     0,     0,
       0,   612,   613,   614,   615,   616,   617,   618,   619,   620,
     621,   622,   623,   624,   625,   626,   627,   628,   629,     0,
       0,  1656,     0,   630,  1659,   528,  1663,   528,     0,     0,
       0,     0,     0,     0,     0,  1672,     0,   826,  1675,     0,
    1672,     0,     0,  1681,  1683,     0,     0,  1691,  1692,  1693,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   176,   403,     0,     0,     0,
       0,     0,  1717,     0,     0,     0,     0,     0,     0,     0,
       0,   529,   612,   613,   614,   615,   616,   617,   618,   619,
     620,   621,   622,   623,   624,   725,   626,   627,   628,   629,
       0,     0,     0,     0,   630,     0,     0,     0,     0,     0,
       0,   404,   405,   406,   407,   408,   409,   410,   411,   412,
       0,     0,     0,     0,   413,   414,   415,   416,     0,     0,
       0,     0,   417,   418,   419,   420,  1768,     0,     0,     0,
       0,   421,     0,   422,     0,     0,     0,  1777,  1778,  1779,
       0,     0,     0,     0,     0,     0,  1785,     0,  1787,   423,
       0,     0,   424,     0,     0,  1790,   182,     0,     0,   183,
       0,   528,   184,     0,   185,     0,     0,     0,  1801,  1802,
       0,     0,     0,     0,     0,    48,     0,     0,     0,  1809,
    1810,  1811,     0,     0,     0,     0,     0,     0,     0,     0,
    1822,     0,     0,     0,     0,     0,   457,   176,   403,     0,
    1832,   612,   613,   614,   615,   616,   617,   618,   619,   620,
     621,   622,   623,   624,   725,   626,   627,   628,   629,   529,
     529,  1849,     0,   630,     0,     0,     0,     0,     0,  1858,
    1859,  2132,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   404,   405,   406,   407,   408,   409,   410,
     411,   412,     0,     0,     0,     0,   413,   414,   415,   416,
       0,  1882,     0,     0,   417,   418,   419,   420,  1890,   425,
     426,   427,     0,   421,     0,   422,     0,     0,     0,     0,
       0,   428,     0,     0,     0,   429,     0,   430,   124,     0,
       0,   423,     0,     0,   424,     0,     0,     0,   182,     0,
       0,   183,     0,   529,   184,     0,   185,     0,     0,     0,
       0,  1908,  1909,  1910,  2133,     0,     0,    48,   786,     0,
     787,  1851,     0,     0,     0,     0,     0,     0,  1915,     0,
       0,     0,     0,  1918,  1919,     0,     0,     0,   457,     0,
       0,     0,     0,     0,     0,     0,  1927,     0,   789,  2202,
       0,     0,     0,   528,   528,  1935,     0,  1936,     0,     0,
       0,     0,     0,  1944,  1945,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   528,     0,
    1953,  1954,   529,     0,   529,     0,     0,     0,     0,     0,
       0,     0,     0,  1918,  1919,     0,     0,  1968,     0,     0,
    1972,     0,     0,     0,  1974,     0,     0,     0,     0,     0,
       0,   425,   426,   427,  1983,     0,     0,     0,     0,     0,
       0,     0,     0,   428,  1990,     0,     0,   429,     0,   430,
     124,     0,     0,     0,     0,     0,     0,     0,  2001,     0,
       0,     0,     0,  2007,  2008,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   917,  2014,     0,
       0,  2015,  2014,  1851,     0,  2019,     0,     0,   612,   613,
     614,   615,   616,   617,   618,   619,   620,   621,   622,   623,
     624,   725,   626,   627,   628,   629,  2033,     0,     0,     0,
     630,     0,  2038,  2039,  2040,     0,     0,     0,     0,     0,
       0,     0,     0,   528,   528,     0,     0,     0,     0,     0,
    2050,  2051,     0,     0,   971,     0,     0,     0,     0,     0,
       0,     0,  2059,     0,     0,     0,     0,     0,   529,     0,
       0,  2068,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2074,  2075,     0,     0,   723,   528,     0,
       0,   612,   613,   614,   615,   616,   617,   618,   619,   620,
     621,   622,   623,   624,   725,   626,   627,   628,   629,     0,
       0,     0,     0,   630,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2102,  2103,   611,   612,   613,   614,   615,
     616,   617,   618,   619,   620,   621,   622,   623,   624,   725,
     626,   627,   628,   629,     0,     0,  2116,     0,   630,  2241,
       0,   528,   528,  2121,     0,     0,     0,     0,  2124,     0,
       0,     0,  2128,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1891,   528,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2152,     0,     0,   528,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   181,     0,   187,     0,     0,
       0,     0,  2164,     0,     0,     0,     0,     0,  2169,     0,
       0,  2170,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2181,     0,  2182,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     529,   529,     0,     0,     0,     0,  2196,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   529,  2208,  2209,     0,  1185,
    1186,  1187,  1188,  1189,  1190,  1191,  1192,  1193,  1194,  1195,
    1196,  2215,  1198,  1199,  1200,  1201,   528,  1203,  1204,  1205,
    1206,     0,     0,     0,     0,     0,     0,     0,     0,  2226,
       0,     0,     0,  1218,     0,  1220,     0,     0,  2007,     0,
       0,     0,  2235,     0,     0,     0,  1230,   470,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1244,  1245,     0,  2248,     0,     0,     0,     0,  2251,  1256,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   621,
     622,   623,   624,   864,   626,   627,   628,   629,     0,     0,
       0,     0,   630,  2269,  2270,     0,   612,   613,   614,   615,
     616,   617,   618,   619,   620,   621,   622,   623,   624,   725,
     626,   627,   628,   629,     7,     8,     0,     0,   630,     0,
     529,   529,   535,   536,   537,   538,   539,   540,   541,   542,
     543,   544,   545,   546,   547,   548,   549,   550,   551,   552,
     553,   554,   555,   556,   557,   558,   559,   560,   563,   564,
     565,   566,   567,   568,     0,   570,   571,     0,     0,     0,
       0,     0,     0,     0,     0,   529,   578,   579,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   593,   594,  1354,  1356,  1357,     0,     0,     0,
    1361,  1362,     0,     0,  1365,  1366,  1367,  1368,     0,  1370,
       0,     0,     0,     0,  1376,     0,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,     0,
       0,     0,    45,    46,    47,    48,     0,     0,   529,   529,
      50,     0,     0,     0,     0,     0,     0,     0,     0,   800,
      58,     0,     0,    61,   801,     0,   802,   803,     0,   804,
       0,     0,     0,   529,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    82,     0,  2026,
     611,     0,     0,     0,   529,     0,     0,     0,     0,     0,
       0,     0,     0,  1462,     0,  1464,     0,     0,     0,     0,
       0,     0,     0,     0,   722,   100,   101,   102,     0,     0,
       0,   731,   732,   733,     0,     0,     0,   737,   738,   739,
     740,   741,   742,   743,     0,   744,     0,     0,     0,     0,
     745,   746,     0,     0,   749,     0,     0,     0,   220,     6,
     372,     0,     0,     0,     0,   221,   222,   223,     0,     0,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   827,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   529,   256,   257,   258,   259,     0,     0,
       0,     0,   260,   261,     0,     0,  1533,     0,     0,     0,
       0,     0,   262,   263,   264,     0,     0,     0,   265,   266,
     267,     0,     0,   268,     0,     0,     0,     0,     0,     0,
       0,   269,    27,     0,   270,     0,     0,     0,  1048,     0,
     271,     0,     0,   272,     0,     0,   273,     0,   274,     0,
       0,     0,     0,     0,     0,    44,     0,     0,     0,   275,
     276,   277,     0,     0,   278,     0,     0,     0,     0,     0,
       0,     0,     0,   279,     0,    59,    60,     0,   280,     0,
     281,     0,     0,   282,     0,     0,     0,     0,     0,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,     0,     0,     0,    85,     0,     0,     0,    89,    90,
       0,     0,     0,     0,   941,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   621,   622,   623,   624,   864,   626,
     627,   628,   629,     0,   283,     0,     0,   630,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1643,     0,
       0,     0,   284,     0,     0,     0,   285,   286,     0,     0,
       0,     0,   287,   288,   289,     0,   290,   291,   292,     0,
       0,     0,   124,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   293,
     294,     0,  1685,     0,     0,     0,   295,     0,     0,     0,
       0,   373,     0,     0,     0,   374,     0,     0,   298,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1723,  1724,  1725,  1726,
    1727,  1728,  1729,     0,     0,     0,     0,  1734,  1735,     0,
       0,     0,     0,     0,  1737,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1745,     0,     0,     0,  1749,     0,
       0,  1751,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1758,   612,   613,   614,   615,   616,   617,   618,
     619,   620,   621,   622,   623,   624,   725,   626,   627,   628,
     629,     0,     0,     0,     0,   630,     0,     0,   220,   176,
       0,   396,     0,     0,     0,   221,   222,   223,     0,     0,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   397,   243,
     244,   245,   246,   247,   248,   249,   250,     0,  1259,     0,
       0,     0,     0,  1817,     0,  1820,     0,     0,     0,  1827,
       0,  1829,     0,     0,   256,   257,   258,   259,     0,     0,
       0,     0,   260,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   265,   266,
     267,     0,  1852,     0,     0,     0,     0,     0,     0,     0,
       0,   269,    27,     0,   270,     0,     0,     0,     0,     0,
     220,   176,   403,     0,   456,     0,     0,   221,   222,   223,
       0,     0,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     397,   243,   244,   245,   246,   247,   248,   249,   250,  1260,
       0,     0,     0,  1251,     0,     0,     0,   404,   405,   406,
     407,   408,   409,   410,   411,   412,   256,   257,   258,   259,
     413,   414,   415,   416,   260,     0,     0,     0,   417,   418,
     419,   420,     0,     0,     0,     0,  1268,   421,     0,   422,
     265,   266,   267,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1920,   269,    27,   423,   270,     0,   424,     0,
       0,     0,   182,     0,     0,   183,     0,     0,   184,     0,
     185,     0,   284,     0,     0,     0,   285,     0,     0,     0,
       0,    48,   287,   288,   289,     0,   290,   291,   292,     0,
       0,     0,   124,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   457,     0,     0,     0,     0,     0,     0,   293,
     398,     0,     0,     0,     0,     0,   295,     0,     0,     0,
       0,   373,     0,     0,     0,     0,     0,     0,   298,     0,
       0,     0,     0,   612,   613,   614,   615,   616,   617,   618,
     619,   620,   621,   622,   623,   624,   725,   626,   627,   628,
     629,  1998,     0,     0,  1999,   630,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   458,     0,     0,
       0,     0,     0,     0,   284,   425,   426,   427,   285,     0,
       0,     0,     0,     0,   287,   288,   289,   428,   290,   291,
     292,   429,     0,   430,   124,     0,   459,   460,   461,   462,
       0,     0,     0,     0,     0,     0,  2035,  2036,     0,     0,
       0,   293,   398,  2042,  1599,     0,  1454,     0,   295,     0,
     463,   464,     0,   465,     0,   466,     0,     0,     0,   467,
     298,     0,     0,     0,   612,   613,   614,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   624,   725,   626,   627,
     628,   629,     0,     0,     0,     0,   630,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2083,  2084,     0,     0,     0,     0,   220,     6,   403,     0,
       0,   702,     0,   221,   222,   223,     0,     0,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
       0,  2115,  1523,   404,   405,   406,   407,   408,   409,   410,
     411,   412,   256,   257,   258,   259,   413,   414,   415,   416,
     260,   261,     0,     0,   417,   418,   419,   420,     0,     0,
     262,   263,   264,   421,     0,   422,   265,   266,   267,     0,
       0,   268,     0,     0,     0,     0,     0,     0,     0,   269,
      27,   423,   270,     0,   424,     0,     0,     0,   271,     0,
       0,   272,     0,     0,   273,     0,   274,     0,     0,     0,
       0,     0,     0,    44,     0,     0,     0,   275,   276,   277,
       0,     0,   278,     0,     0,     0,     0,     0,     0,     0,
       0,   279,     0,    59,    60,     0,   280,     0,   281,     0,
       0,   282,     0,     0,     0,     0,     0,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,     0,
       0,     0,    85,     0,     0,     0,    89,    90,     0,   612,
     613,   614,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   725,   626,   627,   628,   629,  1541,     0,     0,
       0,   630,   283,     0,     0,     0,     0,     0,  1644,  1645,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     284,   425,   426,   427,   285,   286,     0,     0,     0,     0,
     287,   288,   289,   428,   290,   291,   292,   429,     0,   430,
     124,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   293,   527,     0,
       0,     0,     0,     0,   295,     0,     0,     0,     0,   373,
       0,     0,     0,     0,   604,     0,   298,     0,     0,  2261,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   612,   613,   614,   615,   616,   617,   618,   619,   620,
     621,   622,   623,   624,   725,   626,   627,   628,   629,     0,
       0,     0,     0,   630,     0,  1747,     0,     0,   220,     6,
     403,     0,     0,  1660,  1754,   221,   222,   223,     0,     0,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,     0,     0,     0,   404,   405,   406,   407,   408,
     409,   410,   411,   412,   256,   257,   258,   259,   413,   414,
     415,   416,   260,   261,     0,     0,   417,   418,   419,   420,
       0,     0,   262,   263,   264,   421,     0,   422,   265,   266,
     267,     0,     0,   268,     0,     0,     0,     0,     0,     0,
       0,   269,    27,   423,   270,     0,   424,     0,     0,     0,
     271,     0,     0,   272,     0,     0,   273,     0,   274,     0,
       0,     0,     0,     0,     0,    44,     0,     0,     0,   275,
     276,   277,     0,     0,   278,     0,     0,     0,     0,     0,
       0,     0,     0,   279,     0,    59,    60,     0,   280,     0,
     281,     0,     0,   282,     0,     0,     0,     0,     0,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,     0,     0,  1888,    85,     0,     0,     0,    89,    90,
       0,   612,   613,   614,   615,   616,   617,   618,   619,   620,
     621,   622,   623,   624,   725,   626,   627,   628,   629,     0,
       0,     0,     0,   630,   283,   786,     0,   787,     0,     0,
       0,     0,     0,  1819,     0,     0,     0,     0,     0,     0,
       0,     0,   284,   425,   426,   427,   285,   286,     0,     0,
       0,     0,   287,   288,   289,   428,   290,   291,   292,   429,
       0,   430,   124,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   293,
     527,     0,     0,     0,     0,     0,   295,   220,     6,   403,
       0,   373,     0,     0,   221,   222,   223,     0,   298,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,     0,     0,     0,  1686,   405,   406,   407,   408,   409,
     410,   411,   412,   256,   257,   258,   259,   413,   414,   415,
     416,   260,   261,     0,     0,   417,   418,   419,   420,     0,
       0,   262,   263,   264,   421,     0,   422,   265,   266,   267,
       0,     0,   268,     0,     0,     0,     0,     0,     0,     0,
     269,    27,   423,   270,     0,   424,     0,     0,     0,   271,
       0,     0,   272,     0,     0,   273,     0,   274,     0,     0,
       0,     0,     0,     0,    44,     0,     0,     0,   275,   276,
     277,     0,     0,   278,     0,     0,     0,     0,     0,     0,
       0,     0,   279,     0,    59,    60,     0,   280,     0,   281,
       0,     0,   282,     0,     0,     0,     0,     0,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
       0,     0,     0,    85,     0,     0,     0,    89,    90,     0,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   621,
     622,   623,   624,   725,   626,   627,   628,   629,     0,     0,
       0,     0,   630,   283,  1032,     0,     0,     0,     0,     0,
       0,     0,   999,     0,     0,     0,     0,     0,     0,     0,
       0,   284,   425,   426,   427,   285,   286,     0,     0,     0,
       0,   287,   288,   289,   428,   290,   291,   292,   429,     0,
     430,   124,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   293,   294,
       0,     0,     0,     0,     0,   295,     0,     0,     0,     0,
     373,   220,     6,   403,  1687,     0,     0,   298,   221,   222,
     223,     0,     0,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,     0,     0,     0,   404,   405,
     406,   407,   408,   409,   410,   411,   412,   256,   257,   258,
     259,   413,   414,   415,   416,   260,   261,     0,     0,   417,
     418,   419,   420,     0,     0,   262,   263,   264,   421,     0,
     422,   265,   266,   267,     0,     0,   268,     0,     0,     0,
       0,     0,     0,     0,   269,    27,   423,   270,     0,   424,
       0,     0,     0,   271,     0,     0,   272,     0,     0,   273,
       0,   274,     0,     0,     0,     0,     0,     0,    44,     0,
       0,     0,   275,   276,   277,     0,     0,   278,     0,     0,
       0,     0,     0,     0,     0,     0,   279,     0,    59,    60,
       0,   280,     0,   281,     0,     0,   282,     0,     0,     0,
       0,     0,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,     0,     0,     0,    85,     0,     0,
       0,    89,    90,     0,   612,   613,   614,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   624,   725,   626,   627,
     628,   629,     0,     0,     0,     0,   630,   283,  1480,     0,
       0,     0,     0,     0,     0,     0,  1481,     0,     0,     0,
       0,     0,     0,     0,     0,   284,   425,   426,   427,   285,
     286,     0,     0,     0,     0,   287,   288,   289,   428,   290,
     291,   292,   429,     0,   430,   124,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   293,   294,     0,     0,     0,     0,     0,   295,
       0,     0,     0,     0,   373,   220,     6,   372,   297,     0,
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
       0,    85,     0,     0,     0,    89,    90,   612,   613,   614,
     615,   616,   617,   618,   619,   620,   621,   622,   623,   624,
     725,   626,   627,   628,   629,     0,     0,     0,     0,   630,
       0,   283,     0,     0,     0,  1679,     0,     0,     0,  1680,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   284,
       0,     0,     0,   285,   286,     0,     0,     0,     0,   287,
     288,   289,     0,   290,   291,   292,     0,     0,     0,   124,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   293,   294,     0,     0,
       0,     0,     0,   295,     0,     0,     0,     0,   373,   220,
       6,     0,   927,     0,     0,   298,   221,   222,   223,     0,
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
      90,   612,   613,   614,   615,   616,   617,   618,   619,   620,
     621,   622,   623,   624,   725,   626,   627,   628,   629,     0,
       0,     0,     0,   630,     0,   283,     0,     0,     0,  1798,
       0,     0,     0,  1799,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   284,     0,     0,     0,   285,   286,     0,
       0,     0,     0,   287,   288,   289,     0,   290,   291,   292,
       0,     0,     0,   124,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     293,   294,     0,     0,     0,     0,     0,   295,     0,     0,
       0,     0,   296,   220,     6,     0,   297,     0,     0,   298,
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
       0,     0,     0,    89,    90,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   621,   622,   623,   624,   725,   626,
     627,   628,   629,     0,     0,     0,     0,   630,     0,   283,
       0,     0,     0,  1883,     0,     0,     0,  1884,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   284,     0,     0,
       0,   285,   286,     0,     0,     0,     0,   287,   288,   289,
       0,   290,   291,   292,     0,     0,     0,   124,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   293,   294,     0,     0,     0,     0,
       0,   295,     0,     0,     0,     0,   373,   220,     6,     0,
     297,     0,     0,   298,   221,   222,   223,     0,     0,   224,
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
     612,   613,   614,   615,   616,   617,   618,   619,   620,   621,
     622,   623,   624,   725,   626,   627,   628,   629,     0,     0,
       0,     0,   630,   283,  1904,     0,     0,     0,     0,     0,
       0,     0,  1905,     0,     0,     0,     0,     0,     0,     0,
       0,   284,     0,     0,     0,   285,   286,     0,     0,     0,
       0,   287,   288,   289,     0,   290,   291,   292,     0,     0,
       0,   124,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   293,   527,
       0,     0,     0,     0,     0,   295,     0,     0,     0,     0,
     373,   220,     6,     0,   599,     0,     0,   298,   221,   222,
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
       0,    89,    90,   612,   613,   614,   615,   616,   617,   618,
     619,   620,   621,   622,   623,   624,   725,   626,   627,   628,
     629,     0,     0,     0,     0,   630,     0,   283,     0,     0,
       0,  1940,     0,     0,     0,  1941,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   284,     0,     0,     0,   285,
     286,     0,     0,     0,     0,   287,   288,   289,     0,   290,
     291,   292,     0,     0,     0,   124,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   293,   527,     0,     0,     0,     0,     0,   295,
       0,     0,     0,     0,   373,   220,     6,     0,     0,   604,
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
       0,    85,     0,     0,     0,    89,    90,   612,   613,   614,
     615,   616,   617,   618,   619,   620,   621,   622,   623,   624,
     725,   626,   627,   628,   629,     0,     0,     0,     0,   630,
       0,   283,     0,     0,     0,  1961,     0,     0,     0,  1962,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   284,
       0,     0,     0,   285,   286,     0,     0,     0,     0,   287,
     288,   289,     0,   290,   291,   292,     0,     0,     0,   124,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   293,   294,     0,     0,
       0,     0,     0,   295,     0,     0,     0,     0,   642,   220,
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
      90,   612,   613,   614,   615,   616,   617,   618,   619,   620,
     621,   622,   623,   624,   725,   626,   627,   628,   629,     0,
       0,     0,     0,   630,     0,   283,     0,     0,     0,  2144,
       0,     0,     0,  2145,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   284,     0,     0,     0,   285,   286,     0,
       0,     0,     0,   287,   288,   289,     0,   290,   291,   292,
       0,     0,     0,   124,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     293,   294,     0,     0,     0,     0,     0,   295,     0,     0,
       0,     0,   651,   220,     6,     0,   297,     0,     0,   298,
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
       0,     0,     0,    89,    90,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   621,   622,   623,   624,   725,   626,
     627,   628,   629,     0,     0,     0,     0,   630,     0,   283,
       0,     0,     0,     0,     0,     0,     0,   819,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   284,     0,     0,
       0,   285,   286,     0,     0,     0,     0,   287,   288,   289,
       0,   290,   291,   292,     0,     0,     0,   124,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   293,   527,     0,     0,     0,     0,
       0,   295,     0,     0,     0,     0,   373,   220,     6,     0,
     958,     0,  1437,   298,   221,   222,   223,     0,     0,   224,
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
       0,     0,     0,    85,     0,     0,     0,    89,    90,   612,
     613,   614,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   725,   626,   627,   628,   629,     0,     0,     0,
       0,   630,     0,   283,     0,     0,     0,     0,     0,     0,
       0,   825,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   284,     0,     0,     0,   285,   286,     0,     0,     0,
       0,   287,   288,   289,     0,   290,   291,   292,     0,     0,
       0,   124,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   293,   527,
       0,     0,     0,     0,     0,   295,   220,     6,     0,     0,
     373,     0,     0,   221,   222,   223,     0,   298,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   256,   257,   258,   259,     0,     0,     0,     0,
     260,   261,     0,     0,     0,     0,     0,     0,     0,     0,
     262,   263,   264,     0,     0,     0,   265,   266,   267,     0,
       0,   268,     0,     0,     0,     0,     0,     0,     0,   269,
      27,     0,   270,     0,     0,     0,     0,     0,   271,     0,
       0,   272,     0,     0,   273,     0,   274,     0,     0,     0,
       0,     0,     0,    44,     0,     0,     0,   275,   276,   277,
       0,     0,   278,     0,     0,     0,     0,     0,     0,     0,
       0,   279,     0,    59,    60,     0,   280,     0,   281,     0,
       0,   282,     0,     0,     0,     0,     0,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,     0,
       0,     0,    85,     0,     0,     0,    89,    90,   612,   613,
     614,   615,   616,   617,   618,   619,   620,   621,   622,   623,
     624,   725,   626,   627,   628,   629,     0,     0,     0,     0,
     630,     0,   283,     0,     0,     0,     0,     0,     0,     0,
     828,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     284,     0,     0,     0,   285,   286,     0,     0,     0,     0,
     287,   288,   289,     0,   290,   291,   292,     0,     0,     0,
     124,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   293,   527,     0,
       0,     0,     0,     0,   295,     0,     0,     0,     0,   373,
     220,     6,     0,     0,  2077,     0,   298,   221,   222,   223,
       0,     0,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   256,   257,   258,   259,
       0,     0,     0,     0,   260,   261,     0,     0,     0,     0,
       0,     0,     0,     0,   262,   263,   264,     0,     0,     0,
     265,   266,   267,     0,     0,   268,     0,     0,     0,     0,
       0,     0,     0,   269,    27,     0,   270,     0,     0,     0,
       0,     0,   271,     0,     0,   272,     0,     0,   273,     0,
     274,     0,     0,     0,     0,     0,     0,    44,     0,     0,
       0,   275,   276,   277,     0,     0,   278,     0,     0,     0,
       0,     0,     0,     0,     0,   279,     0,    59,    60,     0,
     280,     0,   281,     0,     0,   282,     0,     0,     0,     0,
       0,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,     0,     0,     0,    85,     0,     0,     0,
      89,    90,   612,   613,   614,   615,   616,   617,   618,   619,
     620,   621,   622,   623,   624,   725,   626,   627,   628,   629,
       0,     0,     0,     0,   630,     0,   283,     0,     0,     0,
       0,     0,     0,     0,   999,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   284,     0,     0,     0,   285,   286,
       0,     0,     0,     0,   287,   288,   289,     0,   290,   291,
     292,     0,     0,     0,   124,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   293,   527,     0,     0,     0,     0,     0,   295,   220,
     176,   403,     0,   373,     0,     0,   221,   222,   223,     0,
     298,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   397,
     243,   244,   245,   246,   247,   248,   249,   250,     0,     0,
       0,     0,     0,     0,     0,     0,   404,   405,   406,   407,
     408,   409,   410,   411,   412,   256,   257,   258,   259,   413,
     414,   415,   416,   260,     0,     0,     0,   417,   418,   419,
     420,     0,     0,     0,     0,     0,   421,     0,   422,   265,
     266,   267,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   269,    27,   423,   270,     0,   424,   220,   176,
     403,     0,     0,     0,     0,   221,   222,   223,     0,     0,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   397,   243,
     244,   245,   246,   247,   248,   249,   250,     0,     0,     0,
       0,     0,     0,     0,     0,   404,   405,   406,   407,   408,
     409,   410,   411,   412,   256,   257,   258,   259,   413,   414,
     415,   416,   260,     0,     0,     0,   417,   418,   419,   420,
       0,     0,     0,     0,     0,   421,     0,   422,   265,   266,
     267,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   269,    27,   423,   270,     0,   424,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   284,   425,   426,   427,   285,     0,     0,
       0,     0,     0,   287,   288,   289,   428,   290,   291,   292,
     429,     0,   430,   124,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     293,   398,     0,     0,     0,     0,     0,   295,     0,     0,
       0,     0,   373,     0,     0,     0,  1682,     0,     0,   298,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   621,
     622,   623,   624,   725,   626,   627,   628,   629,     0,     0,
       0,     0,   630,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1000,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   284,   425,   426,   427,   285,     0,     0,     0,
       0,     0,   287,   288,   289,   428,   290,   291,   292,   429,
       0,   430,   124,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   293,
    1966,     0,     0,     0,     0,     0,   295,     0,     0,     0,
       0,   373,   220,   176,   403,  1967,     0,     0,   298,   221,
     222,   223,     0,     0,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   397,   243,   244,   245,   246,   247,   248,   249,
     250,     0,     0,     0,     0,     0,     0,     0,     0,  1686,
     405,   406,   407,   408,   409,   410,   411,   412,   256,   257,
     258,   259,   413,   414,   415,   416,   260,     0,     0,     0,
     417,   418,   419,   420,     0,     0,     0,     0,     0,   421,
       0,   422,   265,   266,   267,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   269,    27,   423,   270,     0,
     424,   220,   176,   403,     0,     0,     0,     0,   221,   222,
     223,     0,     0,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   397,   243,   244,   245,   246,   247,   248,   249,   250,
       0,     0,     0,     0,     0,     0,     0,     0,   404,   405,
     406,   407,   408,   409,   410,   411,   412,   256,   257,   258,
     259,   413,   414,   415,   416,   260,     0,     0,     0,   417,
     418,   419,   420,     0,     0,     0,     0,     0,   421,     0,
     422,   265,   266,   267,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   269,    27,   423,   270,     0,   424,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   284,   425,   426,   427,
     285,     0,     0,     0,     0,     0,   287,   288,   289,   428,
     290,   291,   292,   429,     0,   430,   124,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   293,   398,     0,     0,     0,     0,     0,
     295,     0,     0,     0,     0,   373,     0,     0,     0,  1851,
       0,     0,   298,   612,   613,   614,   615,   616,   617,   618,
     619,   620,   621,   622,   623,   624,   725,   626,   627,   628,
     629,     0,     0,     0,     0,   630,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1045,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   284,   425,   426,   427,   285,
       0,     0,     0,     0,     0,   287,   288,   289,   428,   290,
     291,   292,   429,     0,   430,   124,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   293,   398,     0,     0,     0,     0,     0,   295,
     220,   176,     0,     0,   373,     0,     0,   221,   222,   223,
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
       0,     0,     0,   269,    27,     0,   270,   612,   613,   614,
     615,   616,   617,   618,   619,   620,   621,   622,   623,   624,
     725,   626,   627,   628,   629,     0,     0,     0,     0,   630,
       0,     0,     0,     0,   284,     0,     0,     0,   285,  1156,
       0,     0,     0,     0,   287,   288,   289,     0,   290,   291,
     292,     0,     0,     0,   124,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   293,   398,     0,     0,     0,     0,     0,   295,     0,
       0,     0,     0,   373,     0,     0,     0,   654,     0,     0,
     298,   612,   613,   614,   615,   616,   617,   618,   619,   620,
     621,   622,   623,   624,   725,   626,   627,   628,   629,     0,
       0,     0,     0,   630,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1197,   284,     0,     0,     0,   285,     0,
       0,     0,     0,     0,   287,   288,   289,     0,   290,   291,
     292,     0,     0,     0,   124,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   672,   673,     0,     0,     0,     0,     0,   295,     0,
       0,     0,     0,   674,   220,   176,     0,   341,     0,   919,
     298,   221,   222,   223,     0,     0,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   397,   243,   244,   245,   246,   247,
     248,   249,   250,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     256,   257,   258,   259,     0,     0,     0,     0,   260,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   265,   266,   267,     0,     0,     0,
       0,     0,     0,     0,   220,   176,     0,   269,    27,     0,
     270,   221,   222,   223,     0,     0,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   397,   243,   244,   245,   246,   247,
     248,   249,   250,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     256,   257,   258,   259,     0,     0,     0,     0,   260,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   265,   266,   267,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   269,    27,     0,
     270,   612,   613,   614,   615,   616,   617,   618,   619,   620,
     621,   622,   623,   624,   725,   626,   627,   628,   629,     0,
       0,     0,     0,   630,     0,     0,     0,     0,   284,     0,
       0,     0,   285,  1207,     0,     0,     0,     0,   287,   288,
     289,     0,   290,   291,   292,     0,     0,     0,   124,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   293,   398,     0,     0,     0,
       0,     0,   295,     0,     0,     0,     0,   373,     0,     0,
       0,     0,     0,     0,   298,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   621,   622,   623,   624,   725,   626,
     627,   628,   629,     0,     0,     0,     0,   630,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1208,   284,     0,
       0,     0,   285,     0,     0,     0,     0,     0,   287,   288,
     289,     0,   290,   291,   292,     0,     0,     0,   124,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   293,   398,     0,     0,     0,
       0,     0,   295,   220,   176,     0,  1388,   373,  1143,     0,
     221,   222,   223,     0,   298,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   397,   243,   244,   245,   246,   247,   248,
     249,   250,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   256,
     257,   258,   259,     0,     0,     0,     0,   260,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   265,   266,   267,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   269,    27,     0,   270,
     220,   176,     0,  1563,     0,     0,     0,   221,   222,   223,
       0,     0,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     397,   243,   244,   245,   246,   247,   248,   249,   250,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   256,   257,   258,   259,
       0,     0,     0,     0,   260,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     265,   266,   267,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   269,    27,     0,   270,     0,   612,   613,
     614,   615,   616,   617,   618,   619,   620,   621,   622,   623,
     624,   725,   626,   627,   628,   629,     0,   284,     0,     0,
     630,   285,     0,     0,     0,     0,     0,   287,   288,   289,
    1209,   290,   291,   292,     0,     0,     0,   124,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   293,   398,     0,     0,     0,     0,
       0,   295,     0,     0,     0,     0,   373,     0,     0,     0,
       0,     0,     0,   298,   612,   613,   614,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   624,   725,   626,   627,
     628,   629,     0,     0,     0,     0,   630,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1210,     0,     0,     0,
       0,     0,     0,     0,   284,     0,     0,     0,   285,     0,
       0,     0,     0,     0,   287,   288,   289,     0,   290,   291,
     292,     0,     0,     0,   124,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   293,   398,     0,     0,     0,     0,     0,   295,   220,
     176,     0,  1622,   373,     0,     0,   221,   222,   223,     0,
     298,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   397,
     243,   244,   245,   246,   247,   248,   249,   250,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   256,   257,   258,   259,     0,
       0,     0,     0,   260,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   265,
     266,   267,     0,     0,     0,     0,     0,     0,     0,   220,
     176,     0,   269,    27,     0,   270,   221,   222,   223,     0,
       0,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   397,
     243,   244,   245,   246,   247,   248,   249,   250,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   256,   257,   258,   259,     0,
       0,     0,     0,   260,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   265,
     266,   267,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   269,    27,     0,   270,   612,   613,   614,   615,
     616,   617,   618,   619,   620,   621,   622,   623,   624,   725,
     626,   627,   628,   629,     0,     0,     0,     0,   630,     0,
       0,     0,     0,   284,     0,     0,     0,   285,  1211,     0,
       0,     0,     0,   287,   288,   289,     0,   290,   291,   292,
       0,     0,     0,   124,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     293,   398,     0,     0,     0,     0,     0,   295,     0,     0,
       0,     0,   373,     0,     0,     0,     0,     0,     0,   298,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   621,
     622,   623,   624,   725,   626,   627,   628,   629,     0,     0,
       0,     0,   630,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1216,   284,     0,     0,     0,   285,     0,     0,
       0,     0,     0,   287,   288,   289,     0,   290,   291,   292,
       0,     0,     0,   124,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     293,   398,     0,     0,     0,     0,     0,   295,   220,   176,
       0,     0,   373,  1677,     0,   221,   222,   223,     0,   298,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   397,   243,
     244,   245,   246,   247,   248,   249,   250,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   256,   257,   258,   259,     0,     0,
       0,     0,   260,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   265,   266,
     267,     0,     0,     0,     0,     0,     0,     0,   220,   176,
       0,   269,    27,     0,   270,   221,   222,   223,     0,     0,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   397,   243,
     244,   245,   246,   247,   248,   249,   250,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   256,   257,   258,   259,     0,     0,
       0,     0,   260,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   265,   266,
     267,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   269,    27,     0,   270,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   621,   622,   623,   624,   725,   626,
     627,   628,   629,     0,     0,     0,     0,   630,     0,     0,
       0,     0,   284,     0,     0,     0,   285,  1217,     0,     0,
       0,     0,   287,   288,   289,     0,   290,   291,   292,     0,
       0,     0,   124,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   293,
     398,     0,     0,     0,     0,     0,   295,     0,     0,     0,
       0,   373,  2016,     0,     0,     0,     0,     0,   298,   612,
     613,   614,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   725,   626,   627,   628,   629,     0,     0,     0,
       0,   630,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1219,   284,     0,     0,     0,   285,     0,     0,     0,
       0,     0,   287,   288,   289,     0,   290,   291,   292,     0,
       0,     0,   124,     0,     0,     0,     0,     7,     8,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   293,
     398,     0,     0,     0,     0,     0,   295,     0,     0,     0,
       0,   373,   220,   176,     0,  2076,     0,     0,   298,   221,
     222,   223,     0,     0,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   397,   243,   244,   245,   246,   247,   248,   249,
     250,     7,     8,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   256,   257,
     258,   259,     0,     0,     0,     0,   260,     0,     0,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,   265,   266,   267,    45,    46,    47,    48,     0,
       0,     0,     0,    50,     0,   269,    27,     0,   270,     0,
       0,     0,   800,    58,     0,     0,    61,   801,     0,   802,
     803,     0,   804,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      82,     0,     0,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,     0,     0,     0,    45,
      46,    47,    48,     0,     0,     0,     0,    50,   100,   101,
     102,     0,     0,     0,     0,     0,   800,    58,     0,     0,
      61,   801,     0,   802,   803,     0,   804,     0,     0,     0,
       0,     7,     8,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    82,     0,     0,   612,   613,   614,
     615,   616,   617,   618,   619,   620,   621,   622,   623,   624,
     725,   626,   627,   628,   629,     0,   284,     0,     0,   630,
     285,     0,   100,   101,   102,     0,   287,   288,   289,  1338,
     290,   291,   292,     0,     0,  1007,   124,     0,     0,     0,
       0,     0,     0,     7,     8,     0,     0,     0,     0,     0,
       0,     0,     0,   293,   398,     0,     0,     0,     0,     0,
     295,     0,     0,     0,     0,   373,     0,     0,     0,     0,
       0,     0,   298,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,     0,     0,     0,    45,
      46,    47,    48,     0,     0,     0,     0,    50,     0,  1024,
       0,     0,     0,     0,     0,     0,   800,    58,     0,     0,
      61,   801,     0,   802,   803,     0,   804,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    82,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,     0,     7,
       8,    45,    46,    47,    48,     0,     0,     0,     0,    50,
       0,     0,   100,   101,   102,     0,     0,     0,   800,    58,
       0,     0,    61,   801,     0,   802,   803,     0,   804,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    82,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     7,     8,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   100,   101,   102,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1026,
       0,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,     0,     0,     0,    45,    46,    47,
      48,     0,     0,     0,     0,    50,     0,     0,     0,     0,
       0,     0,     0,     0,   800,    58,     0,     0,    61,   801,
       0,   802,   803,     0,   804,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1027,    82,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,     0,     7,     8,    45,
      46,    47,    48,     0,     0,     0,     0,    50,     0,     0,
     100,   101,   102,     0,     0,     0,   800,    58,     0,     0,
      61,   801,     0,   802,   803,     0,   804,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    82,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     7,
       8,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   100,   101,   102,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1081,     0,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,     0,     0,     0,    45,    46,    47,    48,     0,
       0,     0,     0,    50,     0,     0,     0,     0,     0,     0,
       0,     0,   800,    58,     0,     0,    61,   801,     0,   802,
     803,     0,   804,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1083,
      82,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,     0,     7,     8,    45,    46,    47,
      48,     0,     0,     0,     0,    50,     0,     0,   100,   101,
     102,     0,     0,     0,   800,    58,     0,     0,    61,   801,
       0,   802,   803,     0,   804,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    82,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     7,     8,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     100,   101,   102,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1293,     0,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
       0,     0,     0,    45,    46,    47,    48,     0,     0,     0,
       0,    50,     0,     0,     0,     0,     0,     0,     0,     0,
     800,    58,     0,     0,    61,   801,     0,   802,   803,     0,
     804,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1295,    82,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,     0,     7,     8,    45,    46,    47,    48,     0,
       0,     0,     0,    50,     0,     0,   100,   101,   102,     0,
       0,     0,   800,    58,     0,     0,    61,   801,     0,   802,
     803,     0,   804,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      82,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     7,     8,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   100,   101,
     102,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1296,     0,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,     0,     0,
       0,    45,    46,    47,    48,     0,     0,     0,     0,    50,
       0,     0,     0,     0,     0,     0,     0,     0,   800,    58,
       0,     0,    61,   801,     0,   802,   803,     0,   804,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1315,    82,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
       0,     7,     8,    45,    46,    47,    48,     0,     0,     0,
       0,    50,     0,     0,   100,   101,   102,     0,     0,     0,
     800,    58,     0,     0,    61,   801,     0,   802,   803,     0,
     804,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    82,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     7,     8,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   100,   101,   102,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1326,     0,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,     0,     0,     0,    45,
      46,    47,    48,     0,     0,     0,     0,    50,     0,     0,
       0,     0,     0,     0,     0,     0,   800,    58,     0,     0,
      61,   801,     0,   802,   803,     0,   804,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1346,    82,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,     0,     7,
       8,    45,    46,    47,    48,     0,     0,     0,     0,    50,
       0,     0,   100,   101,   102,     0,     0,     0,   800,    58,
       0,     0,    61,   801,     0,   802,   803,     0,   804,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    82,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     7,     8,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   100,   101,   102,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1383,
       0,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,     0,     0,     0,    45,    46,    47,
      48,     0,     0,     0,     0,    50,     0,     0,     0,     0,
       0,     0,     0,     0,   800,    58,     0,     0,    61,   801,
       0,   802,   803,     0,   804,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1555,    82,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,     0,     0,     0,    45,
      46,    47,    48,     0,     0,     0,     0,    50,     0,     0,
     100,   101,   102,     0,     0,     0,   800,    58,     0,     0,
      61,   801,     0,   802,   803,     0,   804,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    82,     0,     0,     0,    -4,     1,
       0,     0,    -4,     0,     0,     0,     0,     0,     0,     0,
       0,    -4,    -4,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   100,   101,   102,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2199,     0,     0,
       0,     0,     0,     0,     0,    -4,    -4,    -4,   612,   613,
     614,   615,   616,   617,   618,   619,   620,   621,   622,   623,
     624,   725,   626,   627,   628,   629,    -4,    -4,    -4,     0,
     630,     0,     0,    -4,    -4,     0,     0,     0,     0,    -4,
    1364,     0,     0,     0,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,     0,    -4,    -4,     0,    -4,     0,     0,     0,  2243,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,     0,     0,    -4,    -4,
      -4,    -4,    -4,     0,     0,    -4,     0,    -4,     0,    -4,
      -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,     0,     0,    -4,    -4,
      -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,     0,     0,
      -4,    -4,    -4,     0,     0,     0,    -4,     0,     0,     0,
       0,    -4,    -4,    -4,    -4,     0,     0,    -4,     0,    -4,
       0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,     0,     6,     0,     0,     0,
       0,    -4,    -4,    -4,    -4,     7,     8,     0,     0,     0,
       0,     0,     0,    -4,     0,    -4,    -4,     0,     0,     0,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   621,
     622,   623,   624,   725,   626,   627,   628,   629,     0,     9,
      10,    11,   630,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1447,     0,     0,     0,     0,     0,     0,     0,
      12,    13,    14,     0,     0,     0,     0,    15,    16,     0,
       0,     0,     0,    17,     0,     0,     0,     0,    18,    19,
      20,    21,    22,    23,    24,     0,    25,    26,     0,    27,
       0,     0,     0,     0,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
       0,     0,    44,    45,    46,    47,    48,     0,     0,    49,
       0,    50,     0,    51,    52,     0,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
       0,     0,    67,    68,    69,     0,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,     0,     0,     0,    95,    96,    97,     0,     0,     0,
      98,     0,     0,     0,     0,    99,   100,   101,   102,   176,
     403,   103,     0,   104,     0,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,     0,
       0,     0,     0,     0,     0,   119,   120,   121,   122,     0,
       0,     0,     0,     0,     0,     0,     0,   123,     0,   124,
     125,     0,     0,     0,     0,   404,   405,   406,   407,   408,
     409,   410,   411,   412,     0,     0,     0,     0,   413,   414,
     415,   416,     0,   176,   403,     0,   417,   418,   419,   420,
       0,     0,     0,     0,     0,   421,     0,   422,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   423,     0,     0,   424,     0,     0,     0,
     182,     0,     0,   183,     0,     0,   184,     0,   185,   404,
     405,   406,   407,   408,   409,   410,   411,   412,     0,    48,
       0,     0,   413,   414,   415,   416,   434,   403,     0,     0,
     417,   418,   419,   420,     0,     0,     0,     0,     0,   421,
     457,   422,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     7,     8,   423,     0,     0,
     424,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   404,   405,   406,   407,   408,   409,   410,   411,
     412,     0,     0,     0,     0,   413,   414,   415,   416,     0,
       0,     0,     0,   417,   418,   419,   420,     0,     0,     0,
       0,     0,   421,     0,   422,     0,     0,     0,     0,     0,
       0,     0,     0,   425,   426,   427,     0,     0,     0,     0,
     423,     0,     0,   424,     0,   428,     0,     0,     0,   429,
       0,   430,   124,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
       0,     0,     0,    45,    46,    47,    48,     7,     8,     0,
       0,    50,     0,     0,     0,     0,     0,   425,   426,   427,
     800,    58,     0,     0,    61,   801,     0,   802,   803,   428,
     804,     0,     0,   429,  1089,   430,   124,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    82,     0,
       0,     0,  1090,   612,   613,   614,   615,   616,   617,   618,
     619,   620,   621,   622,   623,   624,   725,   626,   627,   628,
     629,     0,     0,     0,     0,   630,   100,   101,   102,     0,
     425,   426,   427,     0,     0,  1452,     0,     0,     0,     0,
       0,     0,   428,     0,     0,     0,   429,     0,   430,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,     0,     0,     0,    45,    46,    47,    48,     0,
       0,     0,     0,    50,     0,     0,     0,     0,     0,     0,
       0,     0,   800,    58,     0,     0,    61,   801,     0,   802,
     803,     0,   804,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      82,   612,   613,   614,   615,   616,   617,   618,   619,   620,
     621,   622,   623,   624,   725,   626,   627,   628,   629,     0,
       0,     0,     0,   630,     0,     0,     0,     0,   100,   101,
     102,     0,     0,  1557,   612,   613,   614,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   624,   725,   626,   627,
     628,   629,     0,     0,     0,     0,   630,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1558,   612,   613,   614,
     615,   616,   617,   618,   619,   620,   621,   622,   623,   624,
     725,   626,   627,   628,   629,     0,     0,     0,     0,   630,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1598,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   621,
     622,   623,   624,   725,   626,   627,   628,   629,     0,     0,
       0,     0,   630,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1730,   612,   613,   614,   615,   616,   617,   618,
     619,   620,   621,   622,   623,   624,   725,   626,   627,   628,
     629,     0,     0,     0,     0,   630,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1731,   612,   613,   614,   615,
     616,   617,   618,   619,   620,   621,   622,   623,   624,   725,
     626,   627,   628,   629,     0,     0,     0,     0,   630,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1732,   612,
     613,   614,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   725,   626,   627,   628,   629,     0,     0,     0,
       0,   630,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1880,   612,   613,   614,   615,   616,   617,   618,   619,
     620,   621,   622,   623,   624,   725,   626,   627,   628,   629,
       0,     0,     0,     0,   630,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2002,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   621,   622,   623,   624,   725,   626,
     627,   628,   629,     0,     0,     0,     0,   630,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2003,   612,   613,
     614,   615,   616,   617,   618,   619,   620,   621,   622,   623,
     624,   725,   626,   627,   628,   629,     0,     0,     0,     0,
     630,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2037,   612,   613,   614,   615,   616,   617,   618,   619,   620,
     621,   622,   623,   624,   725,   626,   627,   628,   629,     0,
       0,     0,     0,   630,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2110,   612,   613,   614,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   624,   725,   626,   627,
     628,   629,     0,     0,     0,     0,   630,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2125,   612,   613,   614,
     615,   616,   617,   618,   619,   620,   621,   622,   623,   624,
     725,   626,   627,   628,   629,     0,     0,     0,     0,   630,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2127,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   621,
     622,   623,   624,   725,   626,   627,   628,   629,     0,     0,
       0,     0,   630,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2165,   612,   613,   614,   615,   616,   617,   618,
     619,   620,   621,   622,   623,   624,   725,   626,   627,   628,
     629,     0,     0,     0,     0,   630,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2166,   612,   613,   614,   615,
     616,   617,   618,   619,   620,   621,   622,   623,   624,   725,
     626,   627,   628,   629,     0,     0,     0,     0,   630,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2180,   612,
     613,   614,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   725,   626,   627,   628,   629,     0,     0,     0,
       0,   630,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2211,   612,   613,   614,   615,   616,   617,   618,   619,
     620,   621,   622,   623,   624,   725,   626,   627,   628,   629,
       0,     0,     0,     0,   630,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2232,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   621,   622,   623,   624,   725,   626,
     627,   628,   629,     0,     0,     0,     0,   630,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2237,   612,   613,
     614,   615,   616,   617,   618,   619,   620,   621,   622,   623,
     624,   725,   626,   627,   628,   629,     0,     0,     0,     0,
     630,     0,     0,     0,     0,     0,   861,   612,   613,   614,
     615,   616,   617,   618,   619,   620,   621,   622,   623,   624,
     725,   626,   627,   628,   629,     0,     0,     0,     0,   630,
       0,     0,     0,     0,     0,  1124,   612,   613,   614,   615,
     616,   617,   618,   619,   620,   621,   622,   623,   624,   725,
     626,   627,   628,   629,     0,     0,     0,     0,   630,     0,
       0,     0,     0,     0,  1183,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   621,   622,   623,   624,   725,   626,
     627,   628,   629,     0,     0,     0,     0,   630,     0,     0,
       0,     0,     0,  1232,   612,   613,   614,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   624,   725,   626,   627,
     628,   629,     0,     0,     0,     0,   630,     0,     0,     0,
       0,     0,  1233,   612,   613,   614,   615,   616,   617,   618,
     619,   620,   621,   622,   623,   624,   725,   626,   627,   628,
     629,     0,     0,     0,     0,   630,     0,     0,     0,     0,
       0,  1285,   612,   613,   614,   615,   616,   617,   618,   619,
     620,   621,   622,   623,   624,   725,   626,   627,   628,   629,
       0,     0,     0,     0,   630,     0,     0,     0,     0,     0,
    1324,   612,   613,   614,   615,   616,   617,   618,   619,   620,
     621,   622,   623,   624,   725,   626,   627,   628,   629,     0,
       0,     0,     0,   630,     0,     0,     0,     0,     0,  1333,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   621,
     622,   623,   624,   725,   626,   627,   628,   629,     0,     0,
       0,     0,   630,     0,     0,     0,     0,     0,  1394,   612,
     613,   614,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   725,   626,   627,   628,   629,     0,     0,     0,
       0,   630,     0,     0,     0,     0,     0,  1414,   612,   613,
     614,   615,   616,   617,   618,   619,   620,   621,   622,   623,
     624,   725,   626,   627,   628,   629,     0,     0,     0,     0,
     630,     0,     0,     0,     0,     0,  1450,   612,   613,   614,
     615,   616,   617,   618,   619,   620,   621,   622,   623,   624,
     725,   626,   627,   628,   629,     0,     0,     0,     0,   630,
       0,     0,     0,     0,     0,  1502,   612,   613,   614,   615,
     616,   617,   618,   619,   620,   621,   622,   623,   624,   725,
     626,   627,   628,   629,     0,     0,     0,     0,   630,     0,
       0,     0,     0,     0,  1503,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   621,   622,   623,   624,   725,   626,
     627,   628,   629,     0,     0,     0,     0,   630,     0,     0,
       0,     0,     0,  1504,   612,   613,   614,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   624,   725,   626,   627,
     628,   629,     0,     0,     0,     0,   630,     0,     0,     0,
       0,     0,  1507,   612,   613,   614,   615,   616,   617,   618,
     619,   620,   621,   622,   623,   624,   725,   626,   627,   628,
     629,     0,     0,     0,     0,   630,     0,     0,     0,     0,
       0,  1508,   612,   613,   614,   615,   616,   617,   618,   619,
     620,   621,   622,   623,   624,   725,   626,   627,   628,   629,
       0,     0,     0,     0,   630,     0,     0,     0,     0,     0,
    1509,   612,   613,   614,   615,   616,   617,   618,   619,   620,
     621,   622,   623,   624,   725,   626,   627,   628,   629,     0,
       0,     0,     0,   630,     0,     0,     0,     0,     0,  1511,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   621,
     622,   623,   624,   725,   626,   627,   628,   629,     0,     0,
       0,     0,   630,     0,     0,     0,     0,     0,  1514,   612,
     613,   614,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   725,   626,   627,   628,   629,     0,     0,     0,
       0,   630,     0,     0,     0,     0,     0,  1559,   612,   613,
     614,   615,   616,   617,   618,   619,   620,   621,   622,   623,
     624,   725,   626,   627,   628,   629,     0,     0,     0,     0,
     630,     0,     0,     0,     0,     0,  1628,   612,   613,   614,
     615,   616,   617,   618,   619,   620,   621,   622,   623,   624,
     725,   626,   627,   628,   629,     0,     0,     0,     0,   630,
       0,     0,     0,     0,     0,  1741,   612,   613,   614,   615,
     616,   617,   618,   619,   620,   621,   622,   623,   624,   725,
     626,   627,   628,   629,     0,     0,     0,     0,   630,     0,
       0,     0,     0,     0,  1938,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   621,   622,   623,   624,   725,   626,
     627,   628,   629,     0,     0,     0,     0,   630,     0,     0,
       0,     0,     0,  1949,   612,   613,   614,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   624,   725,   626,   627,
     628,   629,     0,     0,     0,     0,   630,     0,     0,     0,
       0,     0,  1982,   612,   613,   614,   615,   616,   617,   618,
     619,   620,   621,   622,   623,   624,   725,   626,   627,   628,
     629,     0,     0,     0,     0,   630,     0,     0,     0,     0,
       0,  2017,   612,   613,   614,   615,   616,   617,   618,   619,
     620,   621,   622,   623,   624,   725,   626,   627,   628,   629,
       0,     0,     0,     0,   630,     0,     0,     0,     0,     0,
    2062,   612,   613,   614,   615,   616,   617,   618,   619,   620,
     621,   622,   623,   624,   725,   626,   627,   628,   629,     0,
       0,     0,     0,   630,     0,     0,     0,     0,     0,  2071,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   621,
     622,   623,   624,   725,   626,   627,   628,   629,     0,     0,
       0,     0,   630,     0,     0,     0,     0,     0,  2072,   612,
     613,   614,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   725,   626,   627,   628,   629,     0,     0,     0,
       0,   630,     0,     0,     0,     0,     0,  2087,   612,   613,
     614,   615,   616,   617,   618,   619,   620,   621,   622,   623,
     624,   725,   626,   627,   628,   629,     0,     0,     0,     0,
     630,     0,     0,     0,     0,     0,  2111,   612,   613,   614,
     615,   616,   617,   618,   619,   620,   621,   622,   623,   624,
     725,   626,   627,   628,   629,     0,     0,     0,     0,   630,
       0,     0,     0,     0,     0,  2126,   612,   613,   614,   615,
     616,   617,   618,   619,   620,   621,   622,   623,   624,   725,
     626,   627,   628,   629,     0,     0,     0,     0,   630,     0,
       0,     0,     0,     0,  2150,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   621,   622,   623,   624,   725,   626,
     627,   628,   629,     0,     0,     0,     0,   630,     0,     0,
       0,     0,     0,  2153,   612,   613,   614,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   624,   725,   626,   627,
     628,   629,     0,     0,     0,     0,   630,     0,     0,     0,
       0,     0,  2154,   612,   613,   614,   615,   616,   617,   618,
     619,   620,   621,   622,   623,   624,   725,   626,   627,   628,
     629,     0,     0,     0,     0,   630,     0,     0,     0,     0,
       0,  2179,   612,   613,   614,   615,   616,   617,   618,   619,
     620,   621,   622,   623,   624,   725,   626,   627,   628,   629,
       0,     0,     0,     0,   630,     0,     0,     0,     0,     0,
    2183,   612,   613,   614,   615,   616,   617,   618,   619,   620,
     621,   622,   623,   624,   725,   626,   627,   628,   629,     0,
       0,     0,     0,   630,     0,     0,     0,     0,     0,  2216,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   621,
     622,   623,   624,   725,   626,   627,   628,   629,     0,     0,
       0,     0,   630,     0,     0,     0,     0,     0,  2217,   612,
     613,   614,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   725,   626,   627,   628,   629,     0,     0,     0,
       0,   630,     0,     0,     0,     0,     0,  2225,   612,   613,
     614,   615,   616,   617,   618,   619,   620,   621,   622,   623,
     624,   725,   626,   627,   628,   629,     0,     0,     0,     0,
     630,     0,     0,     0,     0,     0,  2250,   612,   613,   614,
     615,   616,   617,   618,   619,   620,   621,   622,   623,   624,
     725,   626,   627,   628,   629,     0,     0,     0,     0,   630,
       0,     0,     0,     0,     0,  2275,   612,   613,   614,   615,
     616,   617,   618,   619,   620,   621,   622,   623,   624,   725,
     626,   627,   628,   629,     0,     0,     0,     0,   630,     0,
       0,     0,     0,     0,  2276,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   621,   622,   623,   624,   725,   626,
     627,   628,   629,     0,     0,     0,     0,   630,     0,     0,
       0,     0,   762,   612,   613,   614,   615,   616,   617,   618,
     619,   620,   621,   622,   623,   624,   725,   626,   627,   628,
     629,     0,     0,     0,     0,   630,     0,     0,     0,     0,
     991,   612,   613,   614,   615,   616,   617,   618,   619,   620,
     621,   622,   623,   624,   725,   626,   627,   628,   629,     0,
       0,     0,     0,   630,     0,     0,     0,     0,  2055,   612,
     613,   614,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   725,   626,   627,   628,   629,     0,     0,     0,
       0,   630,     0,   786,     0,   787,   612,   613,   614,   615,
     616,   617,   618,   619,   620,   621,   622,   623,   624,   725,
     626,   627,   628,   629,     0,     0,     0,     0,   630,     0,
       0,     0,  1055,   612,   613,   614,   615,   616,   617,   618,
     619,   620,   621,   622,   623,   624,   725,   626,   627,   628,
     629,     0,     0,     0,     0,   630,     0,     0,     0,  1100,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   621,
     622,   623,   624,   725,   626,   627,   628,   629,     0,     0,
       0,     0,   630,     0,     0,     0,  1264,   612,   613,   614,
     615,   616,   617,   618,   619,   620,   621,   622,   623,   624,
     725,   626,   627,   628,   629,     0,     0,     0,     0,   630,
       0,     0,     0,  1325,   612,   613,   614,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   624,   725,   626,   627,
     628,   629,     0,     0,     0,     0,   630,     0,     0,     0,
    1327,   612,   613,   614,   615,   616,   617,   618,   619,   620,
     621,   622,   623,   624,   725,   626,   627,   628,   629,     0,
       0,     0,     0,   630,     0,     0,     0,  1336,   612,   613,
     614,   615,   616,   617,   618,   619,   620,   621,   622,   623,
     624,   725,   626,   627,   628,   629,     0,     0,     0,     0,
     630,     0,     0,     0,  1337,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   621,   622,   623,   624,   725,   626,
     627,   628,   629,     0,     0,     0,     0,   630,     0,     0,
       0,  1429,   612,   613,   614,   615,   616,   617,   618,   619,
     620,   621,   622,   623,   624,   725,   626,   627,   628,   629,
       0,     0,     0,     0,   630,     0,     0,     0,  1443,   612,
     613,   614,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   725,   626,   627,   628,   629,     0,     0,     0,
       0,   630,     0,     0,     0,  1657,   612,   613,   614,   615,
     616,   617,   618,   619,   620,   621,   622,   623,   624,   725,
     626,   627,   628,   629,     0,     0,     0,     0,   630,     0,
       0,     0,  1757,   612,   613,   614,   615,   616,   617,   618,
     619,   620,   621,   622,   623,   624,   725,   626,   627,   628,
     629,     0,     0,     0,     0,   630,     0,     0,     0,  1803,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   621,
     622,   623,   624,   725,   626,   627,   628,   629,     0,     0,
       0,     0,   630,     0,     0,     0,  1994,   612,   613,   614,
     615,   616,   617,   618,   619,   620,   621,   622,   623,   624,
     725,   626,   627,   628,   629,     0,     0,     0,     0,   630,
       0,     0,     0,  2045,   612,   613,   614,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   624,   725,   626,   627,
     628,   629,     0,     0,     0,     0,   630,     0,     0,     0,
    2063,   612,   613,   614,   615,   616,   617,   618,   619,   620,
     621,   622,   623,   624,   725,   626,   627,   628,   629,     0,
       0,     0,     0,   630,     0,   841,   612,   613,   614,   615,
     616,   617,   618,   619,   620,   621,   622,   623,   624,   725,
     626,   627,   628,   629,     0,     0,     0,     0,   630,     0,
     842,   612,   613,   614,   615,   616,   617,   618,   619,   620,
     621,   622,   623,   624,   725,   626,   627,   628,   629,     0,
       0,     0,     0,   630,     0,   843,   612,   613,   614,   615,
     616,   617,   618,   619,   620,   621,   622,   623,   624,   725,
     626,   627,   628,   629,     0,     0,     0,     0,   630,     0,
     845,   612,   613,   614,   615,   616,   617,   618,   619,   620,
     621,   622,   623,   624,   725,   626,   627,   628,   629,     0,
       0,     0,     0,   630,     0,   846,   612,   613,   614,   615,
     616,   617,   618,   619,   620,   621,   622,   623,   624,   725,
     626,   627,   628,   629,     0,     0,     0,     0,   630,     0,
     847,   612,   613,   614,   615,   616,   617,   618,   619,   620,
     621,   622,   623,   624,   725,   626,   627,   628,   629,     0,
       0,     0,     0,   630,     0,   849,   612,   613,   614,   615,
     616,   617,   618,   619,   620,   621,   622,   623,   624,   725,
     626,   627,   628,   629,     0,     0,     0,     0,   630,     0,
     850,   612,   613,   614,   615,   616,   617,   618,   619,   620,
     621,   622,   623,   624,   725,   626,   627,   628,   629,     0,
       0,     0,     0,   630,     0,   851,   612,   613,   614,   615,
     616,   617,   618,   619,   620,   621,   622,   623,   624,   725,
     626,   627,   628,   629,     0,     0,     0,     0,   630,     0,
     852,   612,   613,   614,   615,   616,   617,   618,   619,   620,
     621,   622,   623,   624,   725,   626,   627,   628,   629,     0,
       0,     0,     0,   630,     0,   853,   612,   613,   614,   615,
     616,   617,   618,   619,   620,   621,   622,   623,   624,   725,
     626,   627,   628,   629,     0,     0,     0,     0,   630,     0,
     854,   612,   613,   614,   615,   616,   617,   618,   619,   620,
     621,   622,   623,   624,   725,   626,   627,   628,   629,     0,
       0,     0,     0,   630,     0,   855,   612,   613,   614,   615,
     616,   617,   618,   619,   620,   621,   622,   623,   624,   725,
     626,   627,   628,   629,     0,     0,     0,     0,   630,     0,
     858,   612,   613,   614,   615,   616,   617,   618,   619,   620,
     621,   622,   623,   624,   725,   626,   627,   628,   629,     0,
       0,     0,     0,   630,     0,   859,   612,   613,   614,   615,
     616,   617,   618,   619,   620,   621,   622,   623,   624,   725,
     626,   627,   628,   629,     0,     0,     0,     0,   630,     0,
     860,   612,   613,   614,   615,   616,   617,   618,   619,   620,
     621,   622,   623,   624,   725,   626,   627,   628,   629,     0,
       0,     0,     0,   630,     0,   938,   612,   613,   614,   615,
     616,   617,   618,   619,   620,   621,   622,   623,   624,   725,
     626,   627,   628,   629,     0,     0,     0,     0,   630,     0,
     972,   612,   613,   614,   615,   616,   617,   618,   619,   620,
     621,   622,   623,   624,   725,   626,   627,   628,   629,     0,
       0,     0,     0,   630,     0,  1013,   612,   613,   614,   615,
     616,   617,   618,   619,   620,   621,   622,   623,   624,   725,
     626,   627,   628,   629,     0,     0,     0,     0,   630,     0,
    1032,   612,   613,   614,   615,   616,   617,   618,   619,   620,
     621,   622,   623,   624,   725,   626,   627,   628,   629,     0,
       0,     0,     0,   630,     0,  1040,   612,   613,   614,   615,
     616,   617,   618,   619,   620,   621,   622,   623,   624,   725,
     626,   627,   628,   629,     0,     0,     0,     0,   630,     0,
    1042,   612,   613,   614,   615,   616,   617,   618,   619,   620,
     621,   622,   623,   624,   725,   626,   627,   628,   629,     0,
       0,     0,     0,   630,     0,  1043,   612,   613,   614,   615,
     616,   617,   618,   619,   620,   621,   622,   623,   624,   725,
     626,   627,   628,   629,     0,     0,     0,     0,   630,     0,
    1049,   612,   613,   614,   615,   616,   617,   618,   619,   620,
     621,   622,   623,   624,   725,   626,   627,   628,   629,     0,
       0,     0,     0,   630,     0,  1050,   612,   613,   614,   615,
     616,   617,   618,   619,   620,   621,   622,   623,   624,   725,
     626,   627,   628,   629,     0,     0,     0,     0,   630,     0,
    1088,   612,   613,   614,   615,   616,   617,   618,   619,   620,
     621,   622,   623,   624,   725,   626,   627,   628,   629,     0,
       0,     0,     0,   630,     0,  1099,   612,   613,   614,   615,
     616,   617,   618,   619,   620,   621,   622,   623,   624,   725,
     626,   627,   628,   629,     0,     0,     0,     0,   630,     0,
    1161,   612,   613,   614,   615,   616,   617,   618,   619,   620,
     621,   622,   623,   624,   725,   626,   627,   628,   629,     0,
       0,     0,     0,   630,     0,  1165,   612,   613,   614,   615,
     616,   617,   618,   619,   620,   621,   622,   623,   624,   725,
     626,   627,   628,   629,     0,     0,     0,     0,   630,     0,
    1178,   612,   613,   614,   615,   616,   617,   618,   619,   620,
     621,   622,   623,   624,   725,   626,   627,   628,   629,     0,
       0,     0,     0,   630,     0,  1263,   612,   613,   614,   615,
     616,   617,   618,   619,   620,   621,   622,   623,   624,   725,
     626,   627,   628,   629,     0,     0,     0,     0,   630,     0,
    1273,   612,   613,   614,   615,   616,   617,   618,   619,   620,
     621,   622,   623,   624,   725,   626,   627,   628,   629,     0,
       0,     0,     0,   630,     0,  1274,   612,   613,   614,   615,
     616,   617,   618,   619,   620,   621,   622,   623,   624,   725,
     626,   627,   628,   629,     0,     0,     0,     0,   630,     0,
    1275,   612,   613,   614,   615,   616,   617,   618,   619,   620,
     621,   622,   623,   624,   725,   626,   627,   628,   629,     0,
       0,     0,     0,   630,     0,  1284,   612,   613,   614,   615,
     616,   617,   618,   619,   620,   621,   622,   623,   624,   725,
     626,   627,   628,   629,     0,     0,     0,     0,   630,     0,
    1286,   612,   613,   614,   615,   616,   617,   618,   619,   620,
     621,   622,   623,   624,   725,   626,   627,   628,   629,     0,
       0,     0,     0,   630,     0,  1287,   612,   613,   614,   615,
     616,   617,   618,   619,   620,   621,   622,   623,   624,   725,
     626,   627,   628,   629,     0,     0,     0,     0,   630,     0,
    1323,   612,   613,   614,   615,   616,   617,   618,   619,   620,
     621,   622,   623,   624,   725,   626,   627,   628,   629,     0,
       0,     0,     0,   630,     0,  1339,   612,   613,   614,   615,
     616,   617,   618,   619,   620,   621,   622,   623,   624,   725,
     626,   627,   628,   629,     0,     0,     0,     0,   630,     0,
    1341,   612,   613,   614,   615,   616,   617,   618,   619,   620,
     621,   622,   623,   624,   725,   626,   627,   628,   629,     0,
       0,     0,     0,   630,     0,  1382,   612,   613,   614,   615,
     616,   617,   618,   619,   620,   621,   622,   623,   624,   725,
     626,   627,   628,   629,     0,     0,     0,     0,   630,     0,
    1428,   612,   613,   614,   615,   616,   617,   618,   619,   620,
     621,   622,   623,   624,   725,   626,   627,   628,   629,     0,
       0,     0,     0,   630,     0,  1442,   612,   613,   614,   615,
     616,   617,   618,   619,   620,   621,   622,   623,   624,   725,
     626,   627,   628,   629,     0,     0,     0,     0,   630,     0,
    1658,   612,   613,   614,   615,   616,   617,   618,   619,   620,
     621,   622,   623,   624,   725,   626,   627,   628,   629,     0,
       0,     0,     0,   630,     0,  1697,   612,   613,   614,   615,
     616,   617,   618,   619,   620,   621,   622,   623,   624,   725,
     626,   627,   628,   629,     0,     0,     0,     0,   630,     0,
    1744,   612,   613,   614,   615,   616,   617,   618,   619,   620,
     621,   622,   623,   624,   725,   626,   627,   628,   629,     0,
       0,     0,     0,   630,     0,  1756,   612,   613,   614,   615,
     616,   617,   618,   619,   620,   621,   622,   623,   624,   725,
     626,   627,   628,   629,     0,     0,     0,     0,   630,     0,
    1866,   612,   613,   614,   615,   616,   617,   618,   619,   620,
     621,   622,   623,   624,   725,   626,   627,   628,   629,     0,
       0,     0,     0,   630,     0,  1868,   612,   613,   614,   615,
     616,   617,   618,   619,   620,   621,   622,   623,   624,   725,
     626,   627,   628,   629,     0,     0,     0,     0,   630,     0,
    1872,   612,   613,   614,   615,   616,   617,   618,   619,   620,
     621,   622,   623,   624,   725,   626,   627,   628,   629,     0,
       0,     0,     0,   630,     0,  1879,   612,   613,   614,   615,
     616,   617,   618,   619,   620,   621,   622,   623,   624,   725,
     626,   627,   628,   629,     0,     0,     0,     0,   630,     0,
    1939,   612,   613,   614,   615,   616,   617,   618,   619,   620,
     621,   622,   623,   624,   725,   626,   627,   628,   629,     0,
       0,     0,     0,   630,     0,  1948,   612,   613,   614,   615,
     616,   617,   618,   619,   620,   621,   622,   623,   624,   725,
     626,   627,   628,   629,     0,     0,     0,     0,   630,     0,
    1965,   612,   613,   614,   615,   616,   617,   618,   619,   620,
     621,   622,   623,   624,   725,   626,   627,   628,   629,     0,
       0,     0,     0,   630,     0,  2044,   612,   613,   614,   615,
     616,   617,   618,   619,   620,   621,   622,   623,   624,   725,
     626,   627,   628,   629,     0,     0,     0,     0,   630,     0,
    2108,   612,   613,   614,   615,   616,   617,   618,   619,   620,
     621,   622,   623,   624,   725,   626,   627,   628,   629,     0,
       0,     0,     0,   630,     0,  2109,   612,   613,   614,   615,
     616,   617,   618,   619,   620,   621,   622,   623,   624,   725,
     626,   627,   628,   629,     0,     0,     0,     0,   630,     0,
    2122,   612,   613,   614,   615,   616,   617,   618,   619,   620,
     621,   622,   623,   624,   725,   626,   627,   628,   629,     0,
       0,     0,     0,   630,     0,  2231,   612,   613,   614,   615,
     616,   617,   618,   619,   620,   621,   622,   623,   624,   725,
     626,   627,   628,   629,     0,     0,     0,     0,   630,     0,
    2258,   612,   613,   614,   615,   616,   617,   618,   619,   620,
     621,   622,   623,   624,   725,   626,   627,   628,   629,     0,
       0,     0,     0,   630
};

static const yytype_int16 yycheck[] =
{
       3,   334,   164,  1316,  1312,   783,    71,    72,   467,    74,
    1518,   789,     4,   150,    65,     6,     4,   669,   670,     3,
    1834,     4,  1836,     4,    27,     4,     4,    27,     4,    98,
       4,   111,   149,     6,     5,   114,     4,   116,   111,     5,
    2020,     5,     4,   170,     5,  1823,     4,     7,   111,     6,
       6,     6,     6,     6,    57,     6,     6,     4,   111,     6,
       4,    68,   105,     6,     4,   138,   254,   255,   267,     9,
    2052,   150,   199,   263,   264,     6,   275,     6,     4,   111,
       4,   124,    26,    86,   266,   202,   268,   275,   215,   216,
      93,   254,   255,    37,    38,    98,     4,     9,   105,   267,
     103,     7,   181,     7,     9,    97,   138,   275,   187,     4,
    1888,   114,   275,   267,   149,     9,   254,   255,    26,   254,
     255,   275,  2104,   108,     9,     9,   111,   263,   264,    37,
      38,    26,   167,   271,   254,   255,   272,     6,     0,   208,
     275,     6,    37,    38,   179,   180,   181,   150,   217,     6,
     185,   186,   155,   156,   157,   275,     9,     8,   105,   259,
     260,   164,    14,     4,   267,   265,   108,   151,     6,   111,
     114,   115,   275,     6,   266,   634,   254,   255,   154,   155,
     156,   157,   124,   159,   160,    26,   266,   254,   255,     7,
       6,     7,   270,   169,  2174,     7,    37,    38,   174,     7,
     203,   108,   175,   266,   111,   208,   114,   115,   275,   212,
     266,   262,   263,   264,   217,   218,   219,   266,   210,   114,
     115,   189,   190,   191,   192,     7,   214,   254,   255,     7,
       6,   187,   283,   201,   187,   203,   204,   205,   206,   207,
     111,  1749,   113,   211,   212,   237,   214,   269,   275,   318,
     319,   320,  2234,   275,   237,   199,   200,   267,   237,   237,
     269,   254,   255,   237,     8,   275,   275,  1575,   272,     6,
     729,   275,   337,   266,   339,   237,   279,   270,   270,   270,
     345,   346,   351,   352,   353,     6,  2268,   268,   270,   270,
     273,   294,   270,   274,   297,   298,   270,   237,   298,   270,
     254,   255,   371,   271,   270,   267,   270,   269,   266,   270,
     313,   314,   272,   270,   317,   318,   319,   320,   266,   270,
     270,  1099,  1100,   263,   264,   328,   266,   270,   268,   332,
     270,   334,   272,   239,   240,   241,   242,   266,   797,   270,
     266,   270,   266,   254,   255,   348,   349,     6,   351,   352,
     353,   263,   264,     6,   266,   814,   268,   263,   264,   270,
     272,   266,   266,   268,   268,   824,   272,   272,   371,   263,
     264,   374,   266,     6,   268,   269,     6,   456,   272,   263,
     264,   266,   266,   268,   268,   254,   255,   272,   272,   254,
     255,  2205,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     572,   249,   250,   266,   265,   268,   249,   250,   267,   266,
     271,   239,   240,   241,   242,   268,   275,   239,   240,   241,
     242,   239,   240,   241,   242,   267,   168,   169,   266,   442,
     268,   444,   270,   275,     4,   263,   264,   254,   255,   452,
     453,   263,   264,   149,   268,   263,   264,   239,   240,   241,
     242,   239,   240,   241,   242,   468,    26,   266,   275,   268,
     108,   167,   475,   111,   112,   113,   105,    37,    38,   108,
     267,   940,   111,   179,   180,   181,   124,   266,   275,   185,
     186,   263,   264,   270,   266,   124,   268,   274,   501,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   596,   254,   255,
     589,   265,   270,   266,   527,   254,   255,   271,  1180,   254,
     255,   266,   105,   267,  2042,   108,   254,   255,   111,   275,
     113,   275,   149,   254,   255,   267,   275,   269,   266,   552,
     275,   124,   270,   275,   114,   115,   194,   266,   561,   562,
     167,   254,   255,   566,   266,   568,   569,   570,   571,   572,
     128,   733,   179,   180,   181,   271,   579,   270,   185,   186,
     149,   263,   264,   266,   111,   588,   589,   590,   270,   592,
     593,   594,   595,   266,   597,   595,   599,   597,   167,   267,
     150,     4,   667,   668,   272,   155,   156,   157,   673,   266,
     179,   180,   181,   270,   346,   108,   185,   186,   111,   267,
     113,   269,   625,    26,   266,   266,   358,   275,   631,     6,
     266,   124,   364,   365,    37,    38,   267,     6,   269,   199,
     200,   149,  1101,   266,   275,   268,   783,   266,   266,   272,
     653,   654,   275,   203,   256,   257,   258,   259,   260,   167,
     266,     6,   267,   265,   271,  1317,  1318,   746,   266,   219,
     275,   179,   180,   181,   266,   270,   268,   185,   186,   267,
     267,   269,   269,   275,   270,   669,   670,   275,   275,   266,
     272,   694,   274,   108,   697,   698,   111,   113,   113,   154,
     155,   704,   271,   266,   159,   437,   270,   439,   154,   155,
     266,   114,   115,   159,   270,   263,   264,   449,   266,   266,
     268,   268,   270,   726,   267,   266,   269,   270,   731,   732,
     733,   734,   735,   736,   737,   738,   739,   108,   741,   742,
     743,   744,   745,   111,   747,   748,   749,   750,   751,   271,
     750,   754,   803,   275,   263,   264,     8,   266,   271,   268,
     271,   840,   275,   271,   275,   267,  1544,   269,   270,   772,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   788,   270,   270,  1247,   265,
    1249,   794,   270,   254,   255,   256,   257,   258,   259,   260,
     266,   271,   271,  1262,   265,   275,   275,   810,   811,   267,
     270,   269,   271,   816,   270,   818,   275,   271,   821,   822,
     271,   275,   271,   271,   275,   111,   275,   275,   831,   108,
     833,   271,   969,  1292,   271,   275,   271,   271,   275,   271,
     275,   275,   271,   275,   108,   577,   275,   271,   927,   271,
     271,   275,   271,   275,   275,  1633,   275,   266,   271,   268,
     271,   864,   275,   866,   275,  1643,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,     4,   271,     6,  2200,   265,   275,
    1349,   271,   442,  1352,  1353,   275,   271,   271,   271,   902,
     275,   275,   275,   982,   271,   111,   271,   271,   275,   912,
     275,   275,   271,   111,     4,     4,   275,  1054,  1377,  2227,
       4,   271,     4,     3,   927,   275,   658,     6,   660,   661,
     271,  2244,   271,   998,   275,   266,   275,   266,   271,   942,
    1005,  1400,   275,   271,  1009,   677,  2254,   275,   271,    29,
     271,   266,   275,   271,   275,   958,   688,   275,   266,   268,
     271,   271,  1099,  1100,   275,   275,   271,   970,  1427,   271,
     275,   271,   268,   275,   271,   275,   979,   271,   275,  1116,
       6,   275,  1441,   271,    64,   717,     8,   275,   991,  1448,
     270,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,     6,
     271,     6,     6,   265,   275,   267,   566,   269,   568,     6,
     570,   571,   271,   271,  1103,   271,   275,   275,   271,   275,
     762,   271,   275,     6,   270,   275,   274,     6,   266,   119,
     274,     9,   592,   593,   266,   266,   266,   266,   202,   266,
     266,   202,   270,    57,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     150,  1404,   202,   270,   265,   155,   156,   157,   270,   111,
     138,   266,   266,   266,   164,   266,   202,   266,   270,   266,
     266,  1094,   270,  1158,   266,   270,     4,   270,     7,  1102,
     270,   270,     6,   268,     6,     6,   270,  1110,   270,   270,
     270,   270,   268,   268,     6,   268,     6,   266,   266,   202,
    1123,   266,   266,   203,   270,  1128,  1263,  1264,  1780,  1781,
     266,   266,   266,   266,     6,     6,   268,     6,     8,   219,
       6,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,     8,   270,  1159,  1160,   265,  1162,
    1163,  1164,   266,  1166,  1167,  1168,  1169,  1170,  1171,  1172,
     270,  1174,  1175,  1176,     7,     6,   270,   270,     6,   270,
     100,   261,   732,   271,   734,   735,   736,   737,   738,   739,
     275,   741,   742,   743,   744,     7,  1180,   747,   748,   749,
     275,   281,   282,     6,     6,   267,   270,   270,    68,   270,
     270,   270,     8,   270,   218,   270,   270,   270,  1221,  1222,
    1223,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   270,
     265,     7,   272,   265,     7,   267,   266,     6,   267,   270,
       7,  1254,     6,   271,     7,     6,     6,   199,   270,   267,
     271,   271,   269,   995,     6,   270,   272,  1270,  1271,  1272,
       7,   821,     6,   266,   270,   279,   268,     6,     6,     6,
     270,     6,     6,   833,   267,     7,   268,     7,     7,     7,
       7,  1428,  1429,     7,     7,     7,     7,     7,     7,     7,
       7,   212,     7,  1636,     7,     7,     6,   267,   269,   275,
     275,   275,   271,   317,   270,   267,  1319,   275,     7,   272,
     271,     7,   270,   270,   328,     4,     6,   272,   332,   149,
     271,   271,   270,  1317,  1318,   270,     7,  1340,     6,  1342,
    1343,     6,   270,     7,     7,     7,   272,   272,   267,   267,
       9,   275,  1355,   275,   275,  1434,   269,  1360,   274,   202,
     267,  1364,   442,     7,   170,   271,     6,   270,     6,     6,
    1373,   266,  1375,    50,  1453,  1378,  1455,   457,    50,   272,
     266,  1840,   270,   270,   266,   266,     7,   272,  1391,   272,
       7,     7,   202,   267,     7,   275,     7,     7,     6,   479,
     267,  1404,   313,   314,     7,     7,  2058,   275,     7,     7,
       7,     4,   270,   266,   494,   495,     6,   123,   270,     6,
     105,     6,     6,   111,     7,     7,  1429,     6,     6,   273,
       7,  1434,     7,  1436,  1513,     4,   275,   348,   349,   275,
     267,     6,   271,     6,   270,   270,   270,     6,   452,   453,
       7,     6,  1455,   268,     6,     6,   270,   266,   266,     6,
     271,     6,     6,     6,   468,  1468,     6,   272,     6,  1472,
     269,   275,     6,     6,     6,   142,     6,     6,     6,     6,
       6,     6,  1644,  1645,     6,     6,   566,     6,   568,     6,
     570,   571,   572,     6,     5,   271,  1633,   267,   129,   129,
     129,   202,   267,     6,     6,     4,     6,   268,   270,  1574,
     270,     7,   592,   593,     6,  1848,     7,     6,   270,     6,
       6,   270,   270,     6,   271,   271,   270,   270,     6,   198,
       6,   270,   267,   444,   275,  1538,  1539,  1540,  1617,   275,
       6,   272,   275,  1546,  1547,  1548,     7,   270,     6,   275,
     266,     6,     6,     6,     4,     7,   271,     6,     6,     6,
       6,   149,  1565,   109,     6,   569,     5,   266,   266,     6,
     111,   275,     6,   270,   270,   270,   267,  1580,  1128,     6,
     270,   149,   149,   270,   588,     6,   590,     6,     6,  1592,
       6,  1594,   275,   275,   267,   675,     6,   275,     6,   275,
     270,     6,     6,  1682,   270,     6,     6,     6,     6,   270,
       7,   691,     6,     6,   153,   695,   696,   270,  1755,   270,
     270,     5,   270,     6,   267,     6,     6,     6,   270,   270,
       7,     6,   271,  1636,   270,  1700,   271,   197,     6,     6,
     267,  1644,  1645,   271,     7,   271,   271,  1650,     6,     6,
     272,   731,   732,   733,   734,   735,   736,   737,   738,   739,
       6,   741,   742,   743,   744,     6,  1669,   747,   748,   749,
       6,     6,  1222,  1223,   270,     6,   271,   757,     6,  1682,
     760,   267,     6,     6,  1687,   200,   766,     6,   599,  1851,
     270,     6,   266,     6,   270,   267,     6,  1776,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,     6,   271,   271,   149,
     265,   270,   802,   271,   804,     6,     6,     6,   270,     6,
       6,     6,     6,   270,   270,   270,   267,  1816,     6,     6,
       6,   821,   653,   654,  1823,  1824,     6,   271,   271,     6,
     270,  1440,   270,   833,   270,  2207,  1505,  1695,  2091,  2021,
     498,  1979,  1763,  1842,  1767,     3,  1467,   586,   772,  1772,
    1773,     3,  1112,     3,     3,  2054,     3,  1614,  1434,  1841,
     821,   646,  1823,   694,  1645,    -1,   697,   698,    -1,    -1,
      -1,    -1,     6,   704,  1797,    -1,  1780,  1781,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1808,    -1,    -1,    -1,    -1,
    1360,    -1,    -1,    -1,  1364,  1818,    -1,    -1,  1821,    -1,
      -1,    -1,    -1,  1373,    -1,  1375,    -1,    -1,  1378,    -1,
      -1,    -1,    -1,    -1,  1837,    -1,    -1,    -1,  1841,    -1,
      -1,    -1,    -1,   754,    -1,  1848,    -1,  1850,  1851,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,    -1,    -1,    -1,
      -1,   265,    -1,    -1,    -1,    -1,    -1,   788,    -1,  1429,
      -1,    -1,    -1,    -1,    -1,  1888,    -1,    -1,    -1,  1621,
      -1,    -1,    -1,  1625,    -1,    -1,    -1,    -1,    -1,   810,
      -1,    -1,  1981,    -1,    -1,   816,    -1,   818,    -1,    -1,
      -1,    -1,    -1,    -1,   994,    -1,   996,   997,    -1,  1922,
    1923,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1010,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   942,    -1,
      -1,    -1,  1022,    -1,  1947,    -1,    -1,  2026,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1967,    -1,  1046,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   979,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   902,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   912,  2005,    -1,    -1,  1085,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2022,
      -1,    -1,    -1,    -1,  2027,    -1,    -1,  2030,  2031,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   958,  1128,  2052,
      -1,   265,  2055,    -1,    -1,    -1,    -1,    -1,    -1,   970,
      -1,    -1,    -1,  2066,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2136,    -1,  2076,  2058,  2140,    -1,    -1,    -1,    -1,
     991,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2091,    -1,
    1094,    -1,    -1,    -1,    -1,    -1,  2175,    -1,    -1,    -1,
      -1,  2104,    -1,    -1,    -1,    -1,  1110,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1669,
      -1,    -1,  2187,    -1,    -1,    -1,  2191,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2137,    -1,    -1,    -1,    -1,    -1,
       4,     5,  1222,  1223,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1159,  1160,    -1,  1162,  1163,
    1164,    -1,  1166,  1167,  1168,  1169,  1170,  1171,  1172,    -1,
    1174,  1175,  1176,    -1,  2239,  2240,    -1,    -1,    -1,    -1,
      -1,    -1,  2185,    -1,    -1,    -1,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    -1,    -1,    -1,    -1,    63,
      64,    65,    66,    -1,    -1,    -1,    -1,    71,    72,    73,
      74,    -1,  1123,    -1,  1294,    -1,    80,  1221,    82,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2234,    -1,    -1,    98,    -1,    -1,   101,    -1,    -1,
      -1,   105,    -1,    -1,   108,    -1,    -1,   111,    -1,   113,
    1254,    -1,    -1,    -1,  2257,    -1,    -1,    -1,    -1,    -1,
     124,    -1,    -1,    -1,    -1,  2268,  1270,    -1,  1818,  2272,
    2273,  1821,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1360,   145,  2285,    -1,  1364,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1373,    -1,  1375,    -1,    -1,  1378,    -1,
      -1,    -1,    -1,    -1,    -1,  1385,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1319,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2067,  1340,    -1,  1342,  1343,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1429,
      -1,    -1,    -1,    -1,   218,   219,   220,    -1,    -1,    -1,
    1271,  1272,    -1,    -1,    -1,    -1,   230,    -1,    -1,    -1,
     234,    -1,   236,   237,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1391,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   263,
     264,    -1,    -1,    -1,    -1,    -1,   270,    -1,   272,    -1,
      -1,    -1,     6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2159,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1355,    -1,    -1,    -1,    -1,    -1,
      -1,  1455,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1468,    -1,    -1,    -1,  1472,  2201,
      -1,    -1,    -1,    -1,     3,     4,    -1,    -1,    -1,     8,
      -1,    10,    11,    12,    -1,    -1,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    -1,    -1,
      -1,    -1,    -1,  1434,    -1,  1436,    -1,    -1,    -1,    -1,
      59,    60,    61,    62,  1538,  1539,  1540,     6,    67,    68,
      -1,    -1,  1546,  1547,  1548,    -1,    -1,    -1,    77,    78,
      79,    -1,    -1,    -1,    83,    84,    85,    -1,    -1,    88,
      -1,  1565,    -1,    -1,  1644,  1645,    -1,    96,    97,    -1,
      99,    -1,    -1,    -1,    -1,    -1,   105,    -1,    -1,   108,
      -1,    -1,   111,    -1,   113,    -1,    -1,    -1,  1592,  1669,
    1594,   120,    -1,    -1,    -1,   124,   125,   126,    -1,    -1,
     129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,
      -1,   140,   141,    -1,   143,    -1,   145,    -1,    -1,   148,
      -1,    -1,    -1,    -1,    -1,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,    -1,    -1,    -1,
     169,    -1,    -1,    -1,   173,   174,  1650,    -1,    -1,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,    -1,    -1,  1580,
     199,   265,    -1,    -1,    -1,    -1,    -1,     6,  1682,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   217,    -1,
      -1,    -1,   221,   222,    -1,    -1,    -1,    -1,   227,   228,
     229,    -1,   231,   232,   233,    -1,    -1,  2257,   237,     6,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2272,  2273,    -1,   254,   255,    -1,    -1,    -1,
      -1,    -1,   261,     6,    -1,  2285,    -1,   266,  1818,    -1,
      -1,  1821,   271,    -1,   273,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1834,    -1,  1836,    -1,    -1,    -1,
      -1,    -1,    -1,  1767,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1851,    -1,    -1,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,    -1,    -1,    -1,    -1,   265,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1808,    -1,    -1,    -1,  1888,    -1,
      -1,   110,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   123,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1837,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1850,    -1,    -1,    -1,
      -1,   150,    -1,    -1,    -1,   154,    -1,    -1,    -1,    -1,
     159,  1772,  1773,    -1,    -1,    -1,    -1,   166,    -1,    -1,
     169,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1797,    -1,    -1,   188,
     189,   190,    -1,   192,   193,   194,    -1,   196,   197,   198,
     199,   200,   201,   202,    -1,   204,   205,   206,   207,    -1,
      -1,    -1,    -1,   212,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,    -1,    -1,    -1,    -1,   265,    -1,    -1,    -1,
      -1,    -1,    -1,  1947,    -1,    -1,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,    -1,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,    -1,    -1,
      -1,    -1,   265,    -1,   293,   294,   295,   296,   297,    -1,
      -1,  2005,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1922,  1923,   312,   313,   314,    -1,    -1,  2022,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   330,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   340,   341,    -1,    -1,    -1,    -1,   346,  2052,   348,
     349,   350,    -1,    -1,    -1,    -1,  1967,    -1,    -1,    -1,
      -1,    -1,  2066,     5,    -1,    -1,    -1,    -1,    -1,  2149,
      -1,    -1,    -1,    -1,   373,   374,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   384,    -1,   386,   387,    -1,
     389,    -1,    -1,    -1,   393,   394,   395,    -1,    -1,   398,
    2104,    -1,    -1,   402,    -1,    -1,    -1,    -1,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    -1,    -1,  2030,
    2031,    63,    64,    65,    66,  2205,    -1,    -1,    -1,    71,
      72,    73,    74,  2137,    -1,    -1,    -1,    -1,    80,    -1,
      82,    -1,    -1,    -1,  2055,   444,    -1,    -1,  2228,   448,
      -1,    -1,    -1,    -1,    -1,    -1,    98,    -1,    -1,   101,
      -1,    -1,    -1,    -1,    -1,  2076,   465,   466,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2257,    -1,    -1,
      -1,   480,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2272,  2273,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   503,  2285,    -1,    -1,    -1,   508,
      -1,    -1,    -1,   512,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   526,   527,    -1,
    2234,    -1,   531,    -1,     6,    -1,   535,   536,   537,   538,
     539,   540,   541,   542,   543,   544,   545,   546,   547,   548,
     549,   550,   551,   552,   553,   554,   555,   556,   557,   558,
     559,   560,   561,   562,  2268,   564,   565,    -1,   567,    -1,
      -1,    -1,    -1,    -1,  2185,    -1,   218,   219,   220,   578,
     212,    -1,   581,   582,    -1,    -1,    -1,    -1,   230,    -1,
      -1,    -1,   234,    -1,   236,   594,    -1,    -1,    -1,    -1,
     599,    -1,    -1,     6,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   611,   612,   613,   614,   615,   616,   617,   618,
     619,   620,   621,   622,   623,   624,   625,   626,   627,   628,
     629,   630,     6,   632,   633,    -1,    -1,    -1,    -1,    -1,
      -1,   640,   641,   642,    -1,    -1,    -1,    -1,    -1,   648,
     649,   650,   651,    -1,   653,   654,    -1,    -1,    -1,    -1,
      -1,    -1,   294,    -1,    -1,   297,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   672,   673,   674,    -1,    -1,    -1,    -1,
      -1,   313,   314,    -1,    -1,   684,   685,    -1,   687,    -1,
      -1,   690,    -1,    -1,    -1,   694,     6,    -1,   697,   698,
     699,    -1,    -1,    -1,   703,   704,   705,   706,   707,    -1,
      -1,   710,    -1,   712,    -1,    -1,   348,   349,    -1,    -1,
      -1,    -1,    -1,   722,    -1,    -1,   725,    -1,   727,   728,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   740,   374,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   754,    -1,    -1,    -1,    -1,
      -1,    -1,   761,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     769,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   788,
      -1,   790,     7,   265,    -1,    -1,   795,   796,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   810,   444,   812,   813,    -1,    -1,   816,    -1,   818,
     819,    -1,    -1,    -1,   823,    -1,   825,    -1,    -1,   828,
      -1,    -1,    -1,    -1,    -1,   834,     6,    -1,    -1,   838,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   857,    -1,
      -1,    -1,   265,   862,    -1,   864,    -1,   866,    -1,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,    -1,    -1,     6,
      -1,   265,    -1,    -1,    -1,   527,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   902,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   912,   913,   914,   915,    -1,    -1,    -1,
     552,     6,    -1,   922,   923,   924,    -1,   926,   927,   561,
     562,   930,    -1,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,    -1,    -1,    -1,    -1,   265,    -1,    -1,    -1,   958,
      -1,    -1,   594,    -1,    -1,    -1,    -1,   599,    -1,    -1,
      -1,   970,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   978,
      -1,    -1,    -1,   982,    -1,    -1,    -1,    -1,    -1,   988,
      -1,    -1,   991,   625,    -1,    -1,    -1,    -1,    -1,    -1,
     999,  1000,    -1,    -1,    -1,    -1,  1005,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1014,    -1,    -1,  1017,    -1,
      -1,   653,   654,    -1,    -1,    -1,    -1,    -1,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,  1045,    -1,  1047,  1048,
     265,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   694,    -1,    -1,   697,   698,    -1,    -1,    -1,
      -1,  1070,   704,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,  1090,    -1,    -1,    -1,   265,    -1,    -1,  1097,    -1,
      -1,    -1,    -1,    -1,    -1,  1104,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1117,  1118,
      -1,    -1,   754,    -1,  1123,    -1,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,    -1,    -1,    -1,  1146,   265,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   788,  1156,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,     8,    -1,   810,    -1,
     265,    -1,    -1,    -1,   816,    -1,   818,    -1,    -1,    13,
      14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1197,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1207,  1208,
    1209,  1210,  1211,    -1,    -1,    -1,    -1,  1216,  1217,    -1,
    1219,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   864,    -1,   866,    -1,    -1,    -1,  1237,    -1,
      -1,    -1,    -1,  1242,  1243,    -1,    -1,    -1,    -1,    -1,
      -1,  1250,  1251,    -1,    -1,     6,    -1,    -1,    -1,    -1,
    1259,  1260,    -1,    -1,    -1,    -1,  1265,  1266,    -1,    -1,
     902,    -1,  1271,  1272,    -1,    -1,    -1,    -1,    -1,    -1,
     912,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,    -1,   927,    -1,   121,   122,   123,
     124,    -1,    -1,    -1,    -1,   129,    -1,  1306,    -1,    -1,
      -1,    -1,    -1,    -1,   138,   139,    -1,    -1,   142,   143,
      -1,   145,   146,    -1,   148,    -1,   958,    -1,    -1,    -1,
      -1,  1330,    -1,    -1,    -1,    -1,    -1,    -1,   970,  1338,
      -1,    -1,   166,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1350,  1351,    -1,    -1,    -1,  1355,    -1,    -1,   991,
      -1,    -1,    -1,    -1,  1363,    -1,    -1,    -1,    -1,    -1,
     194,   195,   196,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     6,    -1,    -1,    -1,  1387,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1398,
      -1,    -1,  1401,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,    -1,
      -1,  1430,    -1,   265,  1433,  1434,  1435,  1436,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1444,    -1,   271,  1447,    -1,
    1449,    -1,    -1,  1452,  1453,    -1,    -1,  1456,  1457,  1458,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     4,     5,    -1,    -1,    -1,
      -1,    -1,  1481,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1123,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
      -1,    -1,    -1,    -1,   265,    -1,    -1,    -1,    -1,    -1,
      -1,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      -1,    -1,    -1,    -1,    63,    64,    65,    66,    -1,    -1,
      -1,    -1,    71,    72,    73,    74,  1545,    -1,    -1,    -1,
      -1,    80,    -1,    82,    -1,    -1,    -1,  1556,  1557,  1558,
      -1,    -1,    -1,    -1,    -1,    -1,  1565,    -1,  1567,    98,
      -1,    -1,   101,    -1,    -1,  1574,   105,    -1,    -1,   108,
      -1,  1580,   111,    -1,   113,    -1,    -1,    -1,  1587,  1588,
      -1,    -1,    -1,    -1,    -1,   124,    -1,    -1,    -1,  1598,
    1599,  1600,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1609,    -1,    -1,    -1,    -1,    -1,   145,     4,     5,    -1,
    1619,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,  1271,
    1272,  1640,    -1,   265,    -1,    -1,    -1,    -1,    -1,  1648,
    1649,     6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    -1,    -1,    -1,    -1,    63,    64,    65,    66,
      -1,  1680,    -1,    -1,    71,    72,    73,    74,  1687,   218,
     219,   220,    -1,    80,    -1,    82,    -1,    -1,    -1,    -1,
      -1,   230,    -1,    -1,    -1,   234,    -1,   236,   237,    -1,
      -1,    98,    -1,    -1,   101,    -1,    -1,    -1,   105,    -1,
      -1,   108,    -1,  1355,   111,    -1,   113,    -1,    -1,    -1,
      -1,  1730,  1731,  1732,     6,    -1,    -1,   124,   267,    -1,
     269,   270,    -1,    -1,    -1,    -1,    -1,    -1,  1747,    -1,
      -1,    -1,    -1,  1752,  1753,    -1,    -1,    -1,   145,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1765,    -1,   470,     6,
      -1,    -1,    -1,  1772,  1773,  1774,    -1,  1776,    -1,    -1,
      -1,    -1,    -1,  1782,  1783,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1797,    -1,
    1799,  1800,  1434,    -1,  1436,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1812,  1813,    -1,    -1,  1816,    -1,    -1,
    1819,    -1,    -1,    -1,  1823,    -1,    -1,    -1,    -1,    -1,
      -1,   218,   219,   220,  1833,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   230,  1843,    -1,    -1,   234,    -1,   236,
     237,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1857,    -1,
      -1,    -1,    -1,  1862,  1863,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   579,  1877,    -1,
      -1,  1880,  1881,   270,    -1,  1884,    -1,    -1,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,  1905,    -1,    -1,    -1,
     265,    -1,  1911,  1912,  1913,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1922,  1923,    -1,    -1,    -1,    -1,    -1,
    1929,  1930,    -1,    -1,   636,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1941,    -1,    -1,    -1,    -1,    -1,  1580,    -1,
      -1,  1950,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1962,  1963,    -1,    -1,  1966,  1967,    -1,
      -1,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,    -1,
      -1,    -1,    -1,   265,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2002,  2003,     8,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,    -1,    -1,  2025,    -1,   265,     6,
      -1,  2030,  2031,  2032,    -1,    -1,    -1,    -1,  2037,    -1,
      -1,    -1,  2041,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1687,  2055,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2073,    -1,    -1,  2076,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    28,    -1,    30,    -1,    -1,
      -1,    -1,  2101,    -1,    -1,    -1,    -1,    -1,  2107,    -1,
      -1,  2110,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2125,    -1,  2127,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1772,  1773,    -1,    -1,    -1,    -1,  2145,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1797,  2165,  2166,    -1,   871,
     872,   873,   874,   875,   876,   877,   878,   879,   880,   881,
     882,  2180,   884,   885,   886,   887,  2185,   889,   890,   891,
     892,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2198,
      -1,    -1,    -1,   905,    -1,   907,    -1,    -1,  2207,    -1,
      -1,    -1,  2211,    -1,    -1,    -1,   918,   150,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     932,   933,    -1,  2232,    -1,    -1,    -1,    -1,  2237,   941,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,    -1,    -1,
      -1,    -1,   265,  2262,  2263,    -1,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,    13,    14,    -1,    -1,   265,    -1,
    1922,  1923,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,    -1,   258,   259,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1967,   269,   270,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   285,   286,  1056,  1057,  1058,    -1,    -1,    -1,
    1062,  1063,    -1,    -1,  1066,  1067,  1068,  1069,    -1,  1071,
      -1,    -1,    -1,    -1,  1076,    -1,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,    -1,
      -1,    -1,   121,   122,   123,   124,    -1,    -1,  2030,  2031,
     129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,
     139,    -1,    -1,   142,   143,    -1,   145,   146,    -1,   148,
      -1,    -1,    -1,  2055,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   166,    -1,     7,
       8,    -1,    -1,    -1,  2076,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1155,    -1,  1157,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   397,   194,   195,   196,    -1,    -1,
      -1,   404,   405,   406,    -1,    -1,    -1,   410,   411,   412,
     413,   414,   415,   416,    -1,   418,    -1,    -1,    -1,    -1,
     423,   424,    -1,    -1,   427,    -1,    -1,    -1,     3,     4,
       5,    -1,    -1,    -1,    -1,    10,    11,    12,    -1,    -1,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,   271,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2185,    59,    60,    61,    62,    -1,    -1,
      -1,    -1,    67,    68,    -1,    -1,  1268,    -1,    -1,    -1,
      -1,    -1,    77,    78,    79,    -1,    -1,    -1,    83,    84,
      85,    -1,    -1,    88,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    96,    97,    -1,    99,    -1,    -1,    -1,     8,    -1,
     105,    -1,    -1,   108,    -1,    -1,   111,    -1,   113,    -1,
      -1,    -1,    -1,    -1,    -1,   120,    -1,    -1,    -1,   124,
     125,   126,    -1,    -1,   129,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   138,    -1,   140,   141,    -1,   143,    -1,
     145,    -1,    -1,   148,    -1,    -1,    -1,    -1,    -1,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,    -1,    -1,    -1,   169,    -1,    -1,    -1,   173,   174,
      -1,    -1,    -1,    -1,   607,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,    -1,   199,    -1,    -1,   265,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1410,    -1,
      -1,    -1,   217,    -1,    -1,    -1,   221,   222,    -1,    -1,
      -1,    -1,   227,   228,   229,    -1,   231,   232,   233,    -1,
      -1,    -1,   237,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   254,
     255,    -1,  1454,    -1,    -1,    -1,   261,    -1,    -1,    -1,
      -1,   266,    -1,    -1,    -1,   270,    -1,    -1,   273,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1488,  1489,  1490,  1491,
    1492,  1493,  1494,    -1,    -1,    -1,    -1,  1499,  1500,    -1,
      -1,    -1,    -1,    -1,  1506,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1516,    -1,    -1,    -1,  1520,    -1,
      -1,  1523,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1534,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,    -1,    -1,    -1,    -1,   265,    -1,    -1,     3,     4,
      -1,     6,    -1,    -1,    -1,    10,    11,    12,    -1,    -1,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    -1,     8,    -1,
      -1,    -1,    -1,  1605,    -1,  1607,    -1,    -1,    -1,  1611,
      -1,  1613,    -1,    -1,    59,    60,    61,    62,    -1,    -1,
      -1,    -1,    67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    83,    84,
      85,    -1,  1644,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    96,    97,    -1,    99,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,    -1,     7,    -1,    -1,    10,    11,    12,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,     8,
      -1,    -1,    -1,   936,    -1,    -1,    -1,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    -1,    -1,    -1,    71,    72,
      73,    74,    -1,    -1,    -1,    -1,   969,    80,    -1,    82,
      83,    84,    85,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1754,    96,    97,    98,    99,    -1,   101,    -1,
      -1,    -1,   105,    -1,    -1,   108,    -1,    -1,   111,    -1,
     113,    -1,   217,    -1,    -1,    -1,   221,    -1,    -1,    -1,
      -1,   124,   227,   228,   229,    -1,   231,   232,   233,    -1,
      -1,    -1,   237,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   145,    -1,    -1,    -1,    -1,    -1,    -1,   254,
     255,    -1,    -1,    -1,    -1,    -1,   261,    -1,    -1,    -1,
      -1,   266,    -1,    -1,    -1,    -1,    -1,    -1,   273,    -1,
      -1,    -1,    -1,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,  1853,    -1,    -1,  1856,   265,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   210,    -1,    -1,
      -1,    -1,    -1,    -1,   217,   218,   219,   220,   221,    -1,
      -1,    -1,    -1,    -1,   227,   228,   229,   230,   231,   232,
     233,   234,    -1,   236,   237,    -1,   239,   240,   241,   242,
      -1,    -1,    -1,    -1,    -1,    -1,  1908,  1909,    -1,    -1,
      -1,   254,   255,  1915,     8,    -1,  1149,    -1,   261,    -1,
     263,   264,    -1,   266,    -1,   268,    -1,    -1,    -1,   272,
     273,    -1,    -1,    -1,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,    -1,    -1,    -1,    -1,   265,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1972,  1973,    -1,    -1,    -1,    -1,     3,     4,     5,    -1,
      -1,     8,    -1,    10,    11,    12,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      -1,  2023,  1255,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    -1,    -1,    71,    72,    73,    74,    -1,    -1,
      77,    78,    79,    80,    -1,    82,    83,    84,    85,    -1,
      -1,    88,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    96,
      97,    98,    99,    -1,   101,    -1,    -1,    -1,   105,    -1,
      -1,   108,    -1,    -1,   111,    -1,   113,    -1,    -1,    -1,
      -1,    -1,    -1,   120,    -1,    -1,    -1,   124,   125,   126,
      -1,    -1,   129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   138,    -1,   140,   141,    -1,   143,    -1,   145,    -1,
      -1,   148,    -1,    -1,    -1,    -1,    -1,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,    -1,
      -1,    -1,   169,    -1,    -1,    -1,   173,   174,    -1,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   149,    -1,    -1,
      -1,   265,   199,    -1,    -1,    -1,    -1,    -1,  1411,  1412,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     217,   218,   219,   220,   221,   222,    -1,    -1,    -1,    -1,
     227,   228,   229,   230,   231,   232,   233,   234,    -1,   236,
     237,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   254,   255,    -1,
      -1,    -1,    -1,    -1,   261,    -1,    -1,    -1,    -1,   266,
      -1,    -1,    -1,    -1,   271,    -1,   273,    -1,    -1,  2251,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,    -1,
      -1,    -1,    -1,   265,    -1,  1518,    -1,    -1,     3,     4,
       5,    -1,    -1,     8,  1527,    10,    11,    12,    -1,    -1,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    -1,    -1,    -1,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    -1,    -1,    71,    72,    73,    74,
      -1,    -1,    77,    78,    79,    80,    -1,    82,    83,    84,
      85,    -1,    -1,    88,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    96,    97,    98,    99,    -1,   101,    -1,    -1,    -1,
     105,    -1,    -1,   108,    -1,    -1,   111,    -1,   113,    -1,
      -1,    -1,    -1,    -1,    -1,   120,    -1,    -1,    -1,   124,
     125,   126,    -1,    -1,   129,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   138,    -1,   140,   141,    -1,   143,    -1,
     145,    -1,    -1,   148,    -1,    -1,    -1,    -1,    -1,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,    -1,    -1,  1686,   169,    -1,    -1,    -1,   173,   174,
      -1,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,    -1,
      -1,    -1,    -1,   265,   199,   267,    -1,   269,    -1,    -1,
      -1,    -1,    -1,   275,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   217,   218,   219,   220,   221,   222,    -1,    -1,
      -1,    -1,   227,   228,   229,   230,   231,   232,   233,   234,
      -1,   236,   237,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   254,
     255,    -1,    -1,    -1,    -1,    -1,   261,     3,     4,     5,
      -1,   266,    -1,    -1,    10,    11,    12,    -1,   273,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    -1,    -1,    -1,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    -1,    -1,    71,    72,    73,    74,    -1,
      -1,    77,    78,    79,    80,    -1,    82,    83,    84,    85,
      -1,    -1,    88,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      96,    97,    98,    99,    -1,   101,    -1,    -1,    -1,   105,
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
      -1,   217,   218,   219,   220,   221,   222,    -1,    -1,    -1,
      -1,   227,   228,   229,   230,   231,   232,   233,   234,    -1,
     236,   237,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   254,   255,
      -1,    -1,    -1,    -1,    -1,   261,    -1,    -1,    -1,    -1,
     266,     3,     4,     5,   270,    -1,    -1,   273,    10,    11,
      12,    -1,    -1,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    -1,    -1,    -1,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    -1,    -1,    71,
      72,    73,    74,    -1,    -1,    77,    78,    79,    80,    -1,
      82,    83,    84,    85,    -1,    -1,    88,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    96,    97,    98,    99,    -1,   101,
      -1,    -1,    -1,   105,    -1,    -1,   108,    -1,    -1,   111,
      -1,   113,    -1,    -1,    -1,    -1,    -1,    -1,   120,    -1,
      -1,    -1,   124,   125,   126,    -1,    -1,   129,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   138,    -1,   140,   141,
      -1,   143,    -1,   145,    -1,    -1,   148,    -1,    -1,    -1,
      -1,    -1,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,    -1,    -1,    -1,   169,    -1,    -1,
      -1,   173,   174,    -1,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,    -1,    -1,    -1,    -1,   265,   199,   267,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   275,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   217,   218,   219,   220,   221,
     222,    -1,    -1,    -1,    -1,   227,   228,   229,   230,   231,
     232,   233,   234,    -1,   236,   237,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   254,   255,    -1,    -1,    -1,    -1,    -1,   261,
      -1,    -1,    -1,    -1,   266,     3,     4,     5,   270,    -1,
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
     174,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,    -1,
      -1,    -1,    -1,   265,    -1,   199,    -1,    -1,    -1,   271,
      -1,    -1,    -1,   275,    -1,    -1,    -1,    -1,    -1,    -1,
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
     270,    -1,    -1,   273,    10,    11,    12,    -1,    -1,    15,
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
      -1,    -1,    -1,    -1,   266,     3,     4,    -1,    -1,   271,
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
     174,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,    -1,
      -1,    -1,    -1,   265,    -1,   199,    -1,    -1,    -1,   271,
      -1,    -1,    -1,   275,    -1,    -1,    -1,    -1,    -1,    -1,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   275,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   217,    -1,    -1,
      -1,   221,   222,    -1,    -1,    -1,    -1,   227,   228,   229,
      -1,   231,   232,   233,    -1,    -1,    -1,   237,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   254,   255,    -1,    -1,    -1,    -1,
      -1,   261,    -1,    -1,    -1,    -1,   266,     3,     4,    -1,
     270,    -1,     8,   273,    10,    11,    12,    -1,    -1,    15,
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
      -1,   265,    -1,   199,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   275,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   217,    -1,    -1,    -1,   221,   222,    -1,    -1,    -1,
      -1,   227,   228,   229,    -1,   231,   232,   233,    -1,    -1,
      -1,   237,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   254,   255,
      -1,    -1,    -1,    -1,    -1,   261,     3,     4,    -1,    -1,
     266,    -1,    -1,    10,    11,    12,    -1,   273,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    59,    60,    61,    62,    -1,    -1,    -1,    -1,
      67,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      77,    78,    79,    -1,    -1,    -1,    83,    84,    85,    -1,
      -1,    88,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    96,
      97,    -1,    99,    -1,    -1,    -1,    -1,    -1,   105,    -1,
      -1,   108,    -1,    -1,   111,    -1,   113,    -1,    -1,    -1,
      -1,    -1,    -1,   120,    -1,    -1,    -1,   124,   125,   126,
      -1,    -1,   129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   138,    -1,   140,   141,    -1,   143,    -1,   145,    -1,
      -1,   148,    -1,    -1,    -1,    -1,    -1,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,    -1,
      -1,    -1,   169,    -1,    -1,    -1,   173,   174,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,    -1,    -1,    -1,    -1,
     265,    -1,   199,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     275,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     217,    -1,    -1,    -1,   221,   222,    -1,    -1,    -1,    -1,
     227,   228,   229,    -1,   231,   232,   233,    -1,    -1,    -1,
     237,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   254,   255,    -1,
      -1,    -1,    -1,    -1,   261,    -1,    -1,    -1,    -1,   266,
       3,     4,    -1,    -1,   271,    -1,   273,    10,    11,    12,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    59,    60,    61,    62,
      -1,    -1,    -1,    -1,    67,    68,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    77,    78,    79,    -1,    -1,    -1,
      83,    84,    85,    -1,    -1,    88,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    96,    97,    -1,    99,    -1,    -1,    -1,
      -1,    -1,   105,    -1,    -1,   108,    -1,    -1,   111,    -1,
     113,    -1,    -1,    -1,    -1,    -1,    -1,   120,    -1,    -1,
      -1,   124,   125,   126,    -1,    -1,   129,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   138,    -1,   140,   141,    -1,
     143,    -1,   145,    -1,    -1,   148,    -1,    -1,    -1,    -1,
      -1,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,    -1,    -1,    -1,   169,    -1,    -1,    -1,
     173,   174,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
      -1,    -1,    -1,    -1,   265,    -1,   199,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   275,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   217,    -1,    -1,    -1,   221,   222,
      -1,    -1,    -1,    -1,   227,   228,   229,    -1,   231,   232,
     233,    -1,    -1,    -1,   237,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   254,   255,    -1,    -1,    -1,    -1,    -1,   261,     3,
       4,     5,    -1,   266,    -1,    -1,    10,    11,    12,    -1,
     273,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    -1,    -1,    -1,    71,    72,    73,
      74,    -1,    -1,    -1,    -1,    -1,    80,    -1,    82,    83,
      84,    85,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    96,    97,    98,    99,    -1,   101,     3,     4,
       5,    -1,    -1,    -1,    -1,    10,    11,    12,    -1,    -1,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    -1,    -1,    -1,    71,    72,    73,    74,
      -1,    -1,    -1,    -1,    -1,    80,    -1,    82,    83,    84,
      85,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    96,    97,    98,    99,    -1,   101,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   217,   218,   219,   220,   221,    -1,    -1,
      -1,    -1,    -1,   227,   228,   229,   230,   231,   232,   233,
     234,    -1,   236,   237,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     254,   255,    -1,    -1,    -1,    -1,    -1,   261,    -1,    -1,
      -1,    -1,   266,    -1,    -1,    -1,   270,    -1,    -1,   273,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,    -1,    -1,
      -1,    -1,   265,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   275,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   217,   218,   219,   220,   221,    -1,    -1,    -1,
      -1,    -1,   227,   228,   229,   230,   231,   232,   233,   234,
      -1,   236,   237,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   254,
     255,    -1,    -1,    -1,    -1,    -1,   261,    -1,    -1,    -1,
      -1,   266,     3,     4,     5,   270,    -1,    -1,   273,    10,
      11,    12,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    -1,    -1,    -1,
      71,    72,    73,    74,    -1,    -1,    -1,    -1,    -1,    80,
      -1,    82,    83,    84,    85,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    96,    97,    98,    99,    -1,
     101,     3,     4,     5,    -1,    -1,    -1,    -1,    10,    11,
      12,    -1,    -1,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    -1,    -1,    -1,    71,
      72,    73,    74,    -1,    -1,    -1,    -1,    -1,    80,    -1,
      82,    83,    84,    85,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    96,    97,    98,    99,    -1,   101,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   217,   218,   219,   220,
     221,    -1,    -1,    -1,    -1,    -1,   227,   228,   229,   230,
     231,   232,   233,   234,    -1,   236,   237,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   254,   255,    -1,    -1,    -1,    -1,    -1,
     261,    -1,    -1,    -1,    -1,   266,    -1,    -1,    -1,   270,
      -1,    -1,   273,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,    -1,    -1,    -1,    -1,   265,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   275,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   217,   218,   219,   220,   221,
      -1,    -1,    -1,    -1,    -1,   227,   228,   229,   230,   231,
     232,   233,   234,    -1,   236,   237,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   254,   255,    -1,    -1,    -1,    -1,    -1,   261,
       3,     4,    -1,    -1,   266,    -1,    -1,    10,    11,    12,
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
      -1,    -1,    -1,   266,    -1,    -1,    -1,   270,    -1,    -1,
     273,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,    -1,
      -1,    -1,    -1,   265,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   275,   217,    -1,    -1,    -1,   221,    -1,
      -1,    -1,    -1,    -1,   227,   228,   229,    -1,   231,   232,
     233,    -1,    -1,    -1,   237,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   254,   255,    -1,    -1,    -1,    -1,    -1,   261,    -1,
      -1,    -1,    -1,   266,     3,     4,    -1,   270,    -1,     8,
     273,    10,    11,    12,    -1,    -1,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      59,    60,    61,    62,    -1,    -1,    -1,    -1,    67,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    83,    84,    85,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,    -1,    96,    97,    -1,
      99,    10,    11,    12,    -1,    -1,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      59,    60,    61,    62,    -1,    -1,    -1,    -1,    67,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    83,    84,    85,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    96,    97,    -1,
      99,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,    -1,
      -1,    -1,    -1,   265,    -1,    -1,    -1,    -1,   217,    -1,
      -1,    -1,   221,   275,    -1,    -1,    -1,    -1,   227,   228,
     229,    -1,   231,   232,   233,    -1,    -1,    -1,   237,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   254,   255,    -1,    -1,    -1,
      -1,    -1,   261,    -1,    -1,    -1,    -1,   266,    -1,    -1,
      -1,    -1,    -1,    -1,   273,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,    -1,    -1,    -1,    -1,   265,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   275,   217,    -1,
      -1,    -1,   221,    -1,    -1,    -1,    -1,    -1,   227,   228,
     229,    -1,   231,   232,   233,    -1,    -1,    -1,   237,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   254,   255,    -1,    -1,    -1,
      -1,    -1,   261,     3,     4,    -1,     6,   266,   267,    -1,
      10,    11,    12,    -1,   273,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,
      60,    61,    62,    -1,    -1,    -1,    -1,    67,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    83,    84,    85,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    96,    97,    -1,    99,
       3,     4,    -1,     6,    -1,    -1,    -1,    10,    11,    12,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    59,    60,    61,    62,
      -1,    -1,    -1,    -1,    67,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      83,    84,    85,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    96,    97,    -1,    99,    -1,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,    -1,   217,    -1,    -1,
     265,   221,    -1,    -1,    -1,    -1,    -1,   227,   228,   229,
     275,   231,   232,   233,    -1,    -1,    -1,   237,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   254,   255,    -1,    -1,    -1,    -1,
      -1,   261,    -1,    -1,    -1,    -1,   266,    -1,    -1,    -1,
      -1,    -1,    -1,   273,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,    -1,    -1,    -1,    -1,   265,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   275,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   217,    -1,    -1,    -1,   221,    -1,
      -1,    -1,    -1,    -1,   227,   228,   229,    -1,   231,   232,
     233,    -1,    -1,    -1,   237,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   254,   255,    -1,    -1,    -1,    -1,    -1,   261,     3,
       4,    -1,     6,   266,    -1,    -1,    10,    11,    12,    -1,
     273,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    59,    60,    61,    62,    -1,
      -1,    -1,    -1,    67,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    83,
      84,    85,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,    -1,    96,    97,    -1,    99,    10,    11,    12,    -1,
      -1,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    59,    60,    61,    62,    -1,
      -1,    -1,    -1,    67,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    83,
      84,    85,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    96,    97,    -1,    99,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,    -1,
      -1,    -1,    -1,   217,    -1,    -1,    -1,   221,   275,    -1,
      -1,    -1,    -1,   227,   228,   229,    -1,   231,   232,   233,
      -1,    -1,    -1,   237,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     254,   255,    -1,    -1,    -1,    -1,    -1,   261,    -1,    -1,
      -1,    -1,   266,    -1,    -1,    -1,    -1,    -1,    -1,   273,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,    -1,    -1,
      -1,    -1,   265,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   275,   217,    -1,    -1,    -1,   221,    -1,    -1,
      -1,    -1,    -1,   227,   228,   229,    -1,   231,   232,   233,
      -1,    -1,    -1,   237,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     254,   255,    -1,    -1,    -1,    -1,    -1,   261,     3,     4,
      -1,    -1,   266,   267,    -1,    10,    11,    12,    -1,   273,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    59,    60,    61,    62,    -1,    -1,
      -1,    -1,    67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    83,    84,
      85,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
      -1,    96,    97,    -1,    99,    10,    11,    12,    -1,    -1,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    59,    60,    61,    62,    -1,    -1,
      -1,    -1,    67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    83,    84,
      85,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    96,    97,    -1,    99,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,    -1,    -1,    -1,    -1,   265,    -1,    -1,
      -1,    -1,   217,    -1,    -1,    -1,   221,   275,    -1,    -1,
      -1,    -1,   227,   228,   229,    -1,   231,   232,   233,    -1,
      -1,    -1,   237,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   254,
     255,    -1,    -1,    -1,    -1,    -1,   261,    -1,    -1,    -1,
      -1,   266,   267,    -1,    -1,    -1,    -1,    -1,   273,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,    -1,    -1,    -1,
      -1,   265,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   275,   217,    -1,    -1,    -1,   221,    -1,    -1,    -1,
      -1,    -1,   227,   228,   229,    -1,   231,   232,   233,    -1,
      -1,    -1,   237,    -1,    -1,    -1,    -1,    13,    14,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   254,
     255,    -1,    -1,    -1,    -1,    -1,   261,    -1,    -1,    -1,
      -1,   266,     3,     4,    -1,   270,    -1,    -1,   273,    10,
      11,    12,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,    60,
      61,    62,    -1,    -1,    -1,    -1,    67,    -1,    -1,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,    83,    84,    85,   121,   122,   123,   124,    -1,
      -1,    -1,    -1,   129,    -1,    96,    97,    -1,    99,    -1,
      -1,    -1,   138,   139,    -1,    -1,   142,   143,    -1,   145,
     146,    -1,   148,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     166,    -1,    -1,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,    -1,    -1,    -1,   121,
     122,   123,   124,    -1,    -1,    -1,    -1,   129,   194,   195,
     196,    -1,    -1,    -1,    -1,    -1,   138,   139,    -1,    -1,
     142,   143,    -1,   145,   146,    -1,   148,    -1,    -1,    -1,
      -1,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   166,    -1,    -1,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,    -1,   217,    -1,    -1,   265,
     221,    -1,   194,   195,   196,    -1,   227,   228,   229,   275,
     231,   232,   233,    -1,    -1,   271,   237,    -1,    -1,    -1,
      -1,    -1,    -1,    13,    14,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   254,   255,    -1,    -1,    -1,    -1,    -1,
     261,    -1,    -1,    -1,    -1,   266,    -1,    -1,    -1,    -1,
      -1,    -1,   273,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,    -1,    -1,    -1,   121,
     122,   123,   124,    -1,    -1,    -1,    -1,   129,    -1,   271,
      -1,    -1,    -1,    -1,    -1,    -1,   138,   139,    -1,    -1,
     142,   143,    -1,   145,   146,    -1,   148,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   166,   105,   106,   107,   108,   109,
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
     112,   113,   114,   115,   116,   117,    -1,    -1,    -1,   121,
     122,   123,   124,    -1,    -1,    -1,    -1,   129,    -1,    -1,
     194,   195,   196,    -1,    -1,    -1,   138,   139,    -1,    -1,
     142,   143,    -1,   145,   146,    -1,   148,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   166,    -1,    -1,    -1,     0,     1,
      -1,    -1,     4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   194,   195,   196,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   271,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    47,    48,    49,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,    68,    69,    70,    -1,
     265,    -1,    -1,    75,    76,    -1,    -1,    -1,    -1,    81,
     275,    -1,    -1,    -1,    86,    87,    88,    89,    90,    91,
      92,    -1,    94,    95,    -1,    97,    -1,    -1,    -1,   271,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,    -1,    -1,   120,   121,
     122,   123,   124,    -1,    -1,   127,    -1,   129,    -1,   131,
     132,    -1,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,    -1,    -1,   150,   151,
     152,    -1,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,    -1,    -1,    -1,
     182,   183,   184,    -1,    -1,    -1,   188,    -1,    -1,    -1,
      -1,   193,   194,   195,   196,    -1,    -1,   199,    -1,   201,
      -1,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,    -1,     4,    -1,    -1,    -1,
      -1,   223,   224,   225,   226,    13,    14,    -1,    -1,    -1,
      -1,    -1,    -1,   235,    -1,   237,   238,    -1,    -1,    -1,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,    -1,    47,
      48,    49,   265,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   275,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      68,    69,    70,    -1,    -1,    -1,    -1,    75,    76,    -1,
      -1,    -1,    -1,    81,    -1,    -1,    -1,    -1,    86,    87,
      88,    89,    90,    91,    92,    -1,    94,    95,    -1,    97,
      -1,    -1,    -1,    -1,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
      -1,    -1,   120,   121,   122,   123,   124,    -1,    -1,   127,
      -1,   129,    -1,   131,   132,    -1,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
      -1,    -1,   150,   151,   152,    -1,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,    -1,    -1,    -1,   182,   183,   184,    -1,    -1,    -1,
     188,    -1,    -1,    -1,    -1,   193,   194,   195,   196,     4,
       5,   199,    -1,   201,    -1,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,    -1,
      -1,    -1,    -1,    -1,    -1,   223,   224,   225,   226,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   235,    -1,   237,
     238,    -1,    -1,    -1,    -1,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    -1,    -1,    -1,    -1,    63,    64,
      65,    66,    -1,     4,     5,    -1,    71,    72,    73,    74,
      -1,    -1,    -1,    -1,    -1,    80,    -1,    82,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    98,    -1,    -1,   101,    -1,    -1,    -1,
     105,    -1,    -1,   108,    -1,    -1,   111,    -1,   113,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    -1,   124,
      -1,    -1,    63,    64,    65,    66,     4,     5,    -1,    -1,
      71,    72,    73,    74,    -1,    -1,    -1,    -1,    -1,    80,
     145,    82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    13,    14,    98,    -1,    -1,
     101,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    -1,    -1,    -1,    -1,    63,    64,    65,    66,    -1,
      -1,    -1,    -1,    71,    72,    73,    74,    -1,    -1,    -1,
      -1,    -1,    80,    -1,    82,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   218,   219,   220,    -1,    -1,    -1,    -1,
      98,    -1,    -1,   101,    -1,   230,    -1,    -1,    -1,   234,
      -1,   236,   237,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
      -1,    -1,    -1,   121,   122,   123,   124,    13,    14,    -1,
      -1,   129,    -1,    -1,    -1,    -1,    -1,   218,   219,   220,
     138,   139,    -1,    -1,   142,   143,    -1,   145,   146,   230,
     148,    -1,    -1,   234,   152,   236,   237,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   166,    -1,
      -1,    -1,   170,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,    -1,    -1,    -1,    -1,   265,   194,   195,   196,    -1,
     218,   219,   220,    -1,    -1,   275,    -1,    -1,    -1,    -1,
      -1,    -1,   230,    -1,    -1,    -1,   234,    -1,   236,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,    -1,    -1,    -1,   121,   122,   123,   124,    -1,
      -1,    -1,    -1,   129,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   138,   139,    -1,    -1,   142,   143,    -1,   145,
     146,    -1,   148,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     166,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,    -1,
      -1,    -1,    -1,   265,    -1,    -1,    -1,    -1,   194,   195,
     196,    -1,    -1,   275,   243,   244,   245,   246,   247,   248,
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
      -1,   265,    -1,   267,    -1,   269,   243,   244,   245,   246,
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
     259,   260,    -1,    -1,    -1,    -1,   265,    -1,    -1,    -1,
     269,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,    -1,
      -1,    -1,    -1,   265,    -1,   267,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,    -1,
     267,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,    -1,
      -1,    -1,    -1,   265,    -1,   267,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,    -1,
     267,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,    -1,
      -1,    -1,    -1,   265,    -1,   267,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,    -1,
     267,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,    -1,
      -1,    -1,    -1,   265,    -1,   267,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,    -1,
     267,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,    -1,
      -1,    -1,    -1,   265,    -1,   267,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,    -1,
     267,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,    -1,
      -1,    -1,    -1,   265,    -1,   267,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,    -1,
     267,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,    -1,
      -1,    -1,    -1,   265,    -1,   267,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,    -1,
     267,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,    -1,
      -1,    -1,    -1,   265,    -1,   267,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,    -1,
     267,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,    -1,
      -1,    -1,    -1,   265,    -1,   267,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,    -1,
     267,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,    -1,
      -1,    -1,    -1,   265,    -1,   267,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,    -1,
     267,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,    -1,
      -1,    -1,    -1,   265,    -1,   267,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,    -1,
     267,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,    -1,
      -1,    -1,    -1,   265,    -1,   267,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,    -1,
     267,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,    -1,
      -1,    -1,    -1,   265,    -1,   267,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,    -1,
     267,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,    -1,
      -1,    -1,    -1,   265,    -1,   267,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,    -1,
     267,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,    -1,
      -1,    -1,    -1,   265,    -1,   267,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,    -1,
     267,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,    -1,
      -1,    -1,    -1,   265,    -1,   267,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,    -1,
     267,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,    -1,
      -1,    -1,    -1,   265,    -1,   267,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,    -1,
     267,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,    -1,
      -1,    -1,    -1,   265,    -1,   267,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,    -1,
     267,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,    -1,
      -1,    -1,    -1,   265,    -1,   267,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,    -1,
     267,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,    -1,
      -1,    -1,    -1,   265,    -1,   267,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,    -1,
     267,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,    -1,
      -1,    -1,    -1,   265,    -1,   267,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,    -1,
     267,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,    -1,
      -1,    -1,    -1,   265,    -1,   267,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,    -1,
     267,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,    -1,
      -1,    -1,    -1,   265,    -1,   267,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,    -1,
     267,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,    -1,
      -1,    -1,    -1,   265,    -1,   267,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,    -1,
     267,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,    -1,
      -1,    -1,    -1,   265,    -1,   267,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,    -1,
     267,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,    -1,
      -1,    -1,    -1,   265,    -1,   267,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,    -1,
     267,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,    -1,
      -1,    -1,    -1,   265,    -1,   267,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,    -1,
     267,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,    -1,
      -1,    -1,    -1,   265,    -1,   267,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,    -1,
     267,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,    -1,
      -1,    -1,    -1,   265,    -1,   267,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,    -1,
     267,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,    -1,
      -1,    -1,    -1,   265,    -1,   267,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,    -1,
     267,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,    -1,
      -1,    -1,    -1,   265
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
     324,   358,   268,     6,   270,     6,     6,     6,   266,   270,
       6,     6,   266,   270,     6,   274,     7,   145,   210,   239,
     240,   241,   242,   263,   264,   266,   268,   272,   298,   299,
     300,   324,   358,   380,   381,   390,     4,   328,   329,   330,
     270,     6,   358,   380,   381,   390,   380,   380,   358,   380,
     387,   388,   390,   358,   330,   330,   358,   305,   309,   266,
     367,     9,   381,   266,   381,   358,   358,   358,   266,   358,
     358,   358,   266,   358,   358,   358,   358,   358,   358,   358,
     380,   358,   358,   358,   358,   373,   266,   255,   358,   374,
     375,   270,   373,   371,   380,   300,   300,   300,   300,   300,
     300,   300,   300,   300,   300,   300,   300,   300,   300,   300,
     300,   300,   300,   300,   300,   300,   300,   300,   300,   300,
     300,   266,   268,   300,   300,   300,   300,   300,   300,   266,
     300,   300,   266,   324,   325,   325,   325,   270,   300,   300,
       5,   270,   270,   111,   108,   111,    68,   105,   138,   324,
     324,   325,   266,   300,   300,   266,   266,   266,   358,   270,
     358,   374,   358,   358,   271,   375,   365,   390,   202,     5,
     270,     8,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     265,     9,   266,   268,   272,   299,   300,   358,   375,   375,
     266,   266,   266,   371,   373,   373,   373,   323,   266,   270,
     266,   266,   371,   270,   270,   358,     4,   371,   270,   377,
     270,   270,   368,   368,   368,   358,   358,   254,   255,   270,
     270,   368,   254,   255,   266,   330,   368,   270,   375,   375,
     358,   373,   373,   373,   266,   270,     4,   268,   270,     6,
     268,   330,     6,     6,   270,   330,   330,   270,   270,   270,
     373,   358,     8,     7,   270,   268,   268,   268,     6,     6,
     266,   358,   266,   358,   358,   272,   358,   270,   202,   358,
     358,   358,   300,   358,     6,   256,     9,   266,   268,   272,
     358,   300,   300,   300,   266,   266,   266,   300,   300,   300,
     300,   300,   300,   300,   300,   300,   300,   266,   266,   300,
     266,   268,     6,     6,   270,     6,     8,   330,     6,     8,
     330,   266,   270,   380,   375,   358,   330,   371,   371,   270,
     381,   324,     7,   358,   358,     4,    26,    37,    38,   114,
     115,   199,   200,   302,   371,     6,   267,   269,   270,   301,
     270,     6,   270,     6,     9,   266,   268,   272,   390,   271,
     138,   143,   145,   146,   148,   322,   324,   358,     6,   267,
     275,     9,   266,   268,   272,   267,   275,   267,   275,   275,
     267,   275,     9,   266,   272,   275,   271,   271,   275,   269,
     275,   304,   269,   304,   100,   366,   364,   390,   275,   358,
     275,   267,   267,   267,   358,   267,   267,   267,   358,   267,
     267,   267,   267,   267,   267,   267,   267,   275,   267,   267,
     267,   271,     7,   358,   256,   271,   275,   358,     6,     6,
     267,   358,   358,   358,   358,   358,   358,   358,   358,   358,
     358,   358,   358,   358,   358,   358,   358,   358,   358,   374,
     358,   358,   358,   358,   358,   358,   358,   358,   358,   374,
     374,   390,   270,   358,   358,   380,   358,   380,   371,   380,
     380,   387,   270,   270,   270,   270,   358,   301,   390,     8,
     358,   358,   270,   270,   270,   326,   270,   270,   373,   371,
     270,   380,   380,   374,   365,   381,   365,   375,   267,   271,
     272,   300,    68,     8,   358,   358,   358,   358,   358,   358,
     358,   358,   358,   358,   358,   358,   358,   358,   270,   358,
     374,   358,   358,   358,   358,   358,   390,   358,   358,   302,
     270,   301,   267,   271,   271,   358,   358,   358,     7,     7,
     351,   351,   266,   358,   358,   358,   358,     6,   175,   375,
     375,   270,   267,     6,   330,   270,   330,   330,   275,   275,
     275,   368,   368,   329,   329,   275,   358,   271,   342,   275,
     330,   271,   271,   267,     7,   352,     6,     7,   358,   358,
       6,   358,   330,   358,   271,   375,   271,   271,   375,   375,
     358,     6,   267,   271,   358,   375,   358,   358,   358,   358,
     267,   358,   267,   267,   199,   275,   330,   270,     8,   267,
     267,   358,   358,   390,   302,   269,   387,   380,   387,   380,
     380,   380,   380,   380,   380,   358,   380,   380,   380,   380,
     273,   383,   390,   381,   380,   380,   380,   365,   390,   375,
     271,   271,   271,   271,   358,   330,   269,   271,   267,   152,
     170,   346,   267,   271,   275,   358,     6,   270,   371,   267,
     269,   272,     7,     7,   298,   299,     6,   375,     7,   242,
     298,   358,   283,   390,   358,   358,   302,   268,   266,   138,
     324,   325,   324,   270,   271,     6,   249,   250,   280,   375,
     390,   358,   358,   302,     6,   375,     6,   375,   358,     6,
     380,   388,   390,   267,   302,   358,   270,   358,     6,   390,
       6,   380,   358,   267,   268,   358,   275,   381,     7,     7,
       7,   267,     7,     7,     7,   267,     7,     7,     7,     7,
       7,     7,     7,   358,     7,     7,     7,   358,   267,     6,
     270,   358,   374,   271,     6,   301,   301,   301,   301,   301,
     301,   301,   301,   301,   301,   301,   301,   275,   301,   301,
     301,   301,   301,   301,   301,   301,   301,   275,   275,   275,
     275,   275,   267,   269,   269,   375,   275,   275,   301,   275,
     301,   275,   275,   275,   267,   375,   358,   358,   358,   360,
     301,   271,   271,   271,   358,   358,   358,   270,   358,   376,
     381,   358,   275,   275,   301,   301,   267,   272,   267,   272,
     275,   300,   361,   271,     7,   302,   301,   371,   271,     8,
       8,   375,   272,   267,   269,   266,   268,   299,   300,   375,
       7,   270,   270,   267,   267,   267,   358,   371,     4,   350,
       6,   318,   358,   381,   267,   271,   267,   267,   358,   271,
     271,   375,   272,   271,   330,   271,   271,   368,   358,   358,
     271,   271,   358,   368,   149,   149,   167,   179,   180,   181,
     185,   186,   343,   344,   368,   271,   339,   270,   270,     7,
     358,     6,   358,   267,   271,   269,   271,   269,   271,     6,
     270,   271,   271,   271,     6,   271,   269,   269,   275,   267,
       7,   267,     7,     7,   272,   358,   271,   358,   358,   272,
     266,   268,     7,   272,   301,   275,   301,   301,   267,   267,
     275,   301,   301,   275,   275,   301,   301,   301,   301,   358,
     301,     9,   382,   275,   267,   275,   301,   272,   275,   362,
     269,   271,   267,   271,   274,   202,     7,   170,     6,   358,
     271,   270,     6,   371,   271,   358,     6,     7,   298,   299,
     272,   298,   299,   302,   270,   378,   390,   381,   358,     6,
     271,    50,    50,   371,   271,     4,   189,   190,   191,   192,
     271,   286,   290,   293,   295,   296,   337,   272,   267,   269,
     266,   358,   358,   266,   270,   266,   270,     8,   375,   380,
     267,   272,   267,   269,   266,   267,   267,   275,   272,   266,
     271,   358,   275,     7,   300,     4,    26,    37,    38,   312,
     313,   314,   301,   358,   301,   368,   371,   371,     7,   371,
     371,   371,     7,   371,   371,   371,   371,   371,   371,   371,
     267,   275,   371,   371,   371,     6,     7,   329,   358,   358,
     358,   358,   358,   358,   271,   358,   358,   358,   371,   380,
     380,   271,   271,   271,   271,   275,   311,   271,   271,   271,
     358,   271,   271,   275,   271,   358,   358,   302,   302,   358,
     358,   267,   371,   300,   358,   358,   271,   302,   299,   272,
     299,   358,   358,   301,   271,   371,   375,   375,     7,     7,
       7,   149,   349,     6,   267,   275,     7,     7,     7,     6,
       7,     7,   271,     4,   302,   271,   275,   275,   275,   271,
     271,   123,     4,     6,   358,   270,     6,   266,     6,   187,
       6,   187,   271,   344,   275,   343,   329,   329,   371,     6,
     270,   105,     6,     6,     6,   358,   111,     7,     7,     6,
       6,   358,     7,   371,     7,   371,   371,     4,   275,     8,
       8,   267,   302,   302,   302,   375,   380,   358,   380,   273,
     275,   315,   380,   380,   302,   380,   267,   275,     6,   270,
     324,   270,     6,   358,     6,   270,   371,   271,   271,   358,
       6,   199,   200,   302,   358,     6,     7,   377,   379,     6,
     268,     6,     6,   301,   300,   300,     6,   287,   266,   266,
     270,   297,     6,   302,   272,   380,   358,   269,   267,   358,
       8,   375,   376,   358,   375,   271,   271,     6,     6,   280,
     302,   272,   358,     6,     6,   358,   302,   267,     6,   271,
     275,   358,   270,   358,   381,   301,    50,   270,   371,   381,
     384,   358,   358,   358,   269,   275,     6,   267,     6,     6,
     142,   320,   320,   371,     6,     6,     6,   371,   149,   202,
     319,     6,     6,     6,     6,     6,     6,   358,     6,     6,
       6,     5,   271,   301,   301,   301,   301,   301,   301,   301,
     275,   275,   275,   267,   301,   301,   313,   301,   129,   129,
     129,   271,   202,   381,   267,   301,   267,   300,   361,   301,
       6,   301,   266,   268,   300,   302,   267,   269,   301,     6,
     271,   271,   371,   371,   371,     4,     6,   298,   358,   371,
     371,   371,   270,   270,     7,     6,     7,   358,   358,   358,
     270,   270,   270,   268,     6,   358,   371,   358,     6,     6,
     358,   368,   271,   271,   271,     6,   375,   270,   271,   275,
     270,   358,   358,   269,   371,     6,   371,     6,   198,   358,
     358,   358,   266,   268,     6,     6,     7,   301,   275,   275,
     301,   275,   358,     4,   214,   316,   317,   301,   267,   301,
     362,   381,   358,   270,   330,     6,   330,   275,     6,     6,
     272,     7,     7,   298,   299,     6,   377,   271,   275,   358,
     298,   270,   301,   385,   386,   387,   385,   266,   358,   358,
     370,   371,   270,   266,     4,     6,   267,     6,   267,   271,
     271,   271,   267,   271,     6,     6,   380,   266,     4,   267,
     275,   266,   358,   271,   275,   371,   381,     7,   300,   310,
     358,   374,   314,     6,   368,     6,     6,     6,   149,   321,
     105,   124,   109,     6,   267,   275,     5,     6,   358,   358,
     358,   270,   270,   270,   111,   358,   267,   361,   358,   358,
     301,   299,   270,   270,     6,   319,     6,   358,   371,   149,
     149,     4,     6,   375,   375,   358,   358,   381,   271,   267,
     271,   275,   329,   329,   358,   358,   271,   275,   267,   271,
     275,   271,   375,   358,   358,     6,     6,     6,     6,     6,
     371,   271,   275,     8,   271,   267,   255,   270,   358,   372,
     381,   380,   358,   380,   358,   381,   384,   386,   381,   275,
     267,   275,   271,   358,   346,   346,   371,   302,   378,   381,
     358,     6,     6,   377,   269,   371,   387,     6,   301,   301,
     284,   358,   275,   275,   271,   275,   285,   358,   358,     6,
       6,     6,     6,     6,   358,   358,   267,   271,     6,   358,
     306,   308,   270,   386,   271,   275,     7,     7,   153,     6,
     270,   270,   270,   358,     5,   301,   301,   275,   358,   358,
     358,   270,   301,   267,   267,   269,   375,   375,     6,     6,
     358,   358,   270,   271,   271,   270,     6,     6,   270,   358,
     271,   271,   271,   269,     6,   371,     7,   270,   358,     6,
     271,   271,   271,   197,   358,   358,   270,   271,   375,     6,
       6,     6,   267,   301,   301,   317,   381,   271,   271,   271,
     271,     7,     6,     6,     6,   272,     6,   271,     6,     6,
     267,   275,   358,   358,   270,   371,   271,   275,   267,   267,
     275,   271,   311,   315,   371,   301,   358,   381,   390,   375,
     375,   358,   267,     6,   358,   275,   271,   275,   358,   361,
     271,   271,     6,     6,   370,   154,   155,   159,   353,   154,
     155,   353,   375,   329,   271,   275,     6,   271,   371,   330,
     271,     6,   358,   271,   271,   375,   271,   267,     6,   270,
       6,   377,   200,   288,   358,   275,   275,   370,     6,   358,
     358,     6,   271,   271,   307,     7,   266,   271,   271,   271,
     275,   358,   358,   271,   267,   270,   271,   270,   368,   371,
       6,   270,   368,     6,   271,   271,   358,     6,   149,   271,
     340,   270,     6,   271,     6,   330,     6,   270,   358,   358,
     271,   275,   311,   381,   267,   358,   271,   271,   375,     6,
     368,     6,   368,     6,     6,   271,   358,   343,   330,   346,
     285,   267,   275,     6,   270,   358,   271,   275,   271,   275,
     275,     6,   271,   271,   341,   271,   271,   291,   358,   370,
     271,   358,   368,   368,   343,     6,     6,   270,   267,   271,
       6,   301,   275,   275,   271,   289,   380,   294,   270,   358,
     358,   271,   275,   270,   370,   271,   271,     6,   380,   292,
     380,   271,     6,     6,   271,   275,     6,     6,   380
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
#line 340 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); ;}
    break;

  case 12:
#line 341 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (2)].l)); return 1; ;}
    break;

  case 13:
#line 342 "Gmsh.y"
    { ;}
    break;

  case 14:
#line 343 "Gmsh.y"
    { return 1; ;}
    break;

  case 15:
#line 344 "Gmsh.y"
    { return 1; ;}
    break;

  case 16:
#line 345 "Gmsh.y"
    { return 1; ;}
    break;

  case 17:
#line 346 "Gmsh.y"
    { return 1; ;}
    break;

  case 18:
#line 347 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); ;}
    break;

  case 19:
#line 348 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (2)].l)); return 1; ;}
    break;

  case 20:
#line 349 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); ;}
    break;

  case 21:
#line 350 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (2)].l)); return 1; ;}
    break;

  case 22:
#line 351 "Gmsh.y"
    { return 1; ;}
    break;

  case 23:
#line 352 "Gmsh.y"
    { return 1; ;}
    break;

  case 24:
#line 353 "Gmsh.y"
    { return 1; ;}
    break;

  case 25:
#line 354 "Gmsh.y"
    { return 1; ;}
    break;

  case 26:
#line 355 "Gmsh.y"
    { return 1; ;}
    break;

  case 27:
#line 356 "Gmsh.y"
    { return 1; ;}
    break;

  case 28:
#line 357 "Gmsh.y"
    { return 1; ;}
    break;

  case 29:
#line 362 "Gmsh.y"
    {
      (yyval.c) = (char*)"w";
    ;}
    break;

  case 30:
#line 366 "Gmsh.y"
    {
      (yyval.c) = (char*)"a";
    ;}
    break;

  case 31:
#line 373 "Gmsh.y"
    {
      Msg::Direct("%s", (yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 32:
#line 378 "Gmsh.y"
    {
      Msg::Warning("%s", (yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 33:
#line 383 "Gmsh.y"
    {
      Msg::Error("%s", (yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 34:
#line 388 "Gmsh.y"
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

  case 35:
#line 402 "Gmsh.y"
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

  case 36:
#line 415 "Gmsh.y"
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

  case 37:
#line 428 "Gmsh.y"
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

  case 38:
#line 441 "Gmsh.y"
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

  case 39:
#line 469 "Gmsh.y"
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

  case 40:
#line 483 "Gmsh.y"
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

  case 41:
#line 496 "Gmsh.y"
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

  case 42:
#line 509 "Gmsh.y"
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

  case 43:
#line 527 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData = new PViewDataList();
#endif
    ;}
    break;

  case 50:
#line 542 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(1) - (1)].d)); ;}
    break;

  case 51:
#line 544 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(3) - (3)].d)); ;}
    break;

  case 52:
#line 549 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(1) - (1)].d)); ;}
    break;

  case 53:
#line 551 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(3) - (3)].d)); ;}
    break;

  case 54:
#line 556 "Gmsh.y"
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

  case 55:
#line 575 "Gmsh.y"
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

  case 57:
#line 589 "Gmsh.y"
    {
      ViewStrings.push_back((yyvsp[(1) - (1)].c));
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 58:
#line 594 "Gmsh.y"
    {
      ViewStrings.push_back((yyvsp[(3) - (3)].c));
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 59:
#line 602 "Gmsh.y"
    {
      ViewStrings.clear();
    ;}
    break;

  case 60:
#line 606 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->addString2D((yyvsp[(3) - (13)].d), (yyvsp[(5) - (13)].d), (yyvsp[(7) - (13)].d), ViewStrings);
#endif
    ;}
    break;

  case 61:
#line 615 "Gmsh.y"
    {
      ViewStrings.push_back((yyvsp[(1) - (1)].c));
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 62:
#line 620 "Gmsh.y"
    {
      ViewStrings.push_back((yyvsp[(3) - (3)].c));
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 63:
#line 628 "Gmsh.y"
    {
      ViewStrings.clear();
    ;}
    break;

  case 64:
#line 632 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->addString3D((yyvsp[(3) - (15)].d), (yyvsp[(5) - (15)].d), (yyvsp[(7) - (15)].d), (yyvsp[(9) - (15)].d), ViewStrings);
#endif
    ;}
    break;

  case 65:
#line 642 "Gmsh.y"
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

  case 66:
#line 661 "Gmsh.y"
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

  case 67:
#line 680 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewTime.clear();
      ViewValueList = &ViewTime;
#endif
    ;}
    break;

  case 68:
#line 687 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(auto t : ViewTime) ViewData->addTime(t);
#endif
    ;}
    break;

  case 69:
#line 697 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 70:
#line 698 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 71:
#line 699 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 72:
#line 700 "Gmsh.y"
    { (yyval.i) = 3; ;}
    break;

  case 73:
#line 701 "Gmsh.y"
    { (yyval.i) = 4; ;}
    break;

  case 74:
#line 705 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 75:
#line 706 "Gmsh.y"
    { (yyval.i) = -1; ;}
    break;

  case 76:
#line 712 "Gmsh.y"
    { (yyval.c) = (char*)"("; ;}
    break;

  case 77:
#line 712 "Gmsh.y"
    { (yyval.c) = (char*)"["; ;}
    break;

  case 78:
#line 714 "Gmsh.y"
    { (yyval.c) = (char*)")"; ;}
    break;

  case 79:
#line 714 "Gmsh.y"
    { (yyval.c) = (char*)"]"; ;}
    break;

  case 80:
#line 719 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 81:
#line 720 "Gmsh.y"
    { (yyval.c) = (char *)Malloc(4 * sizeof(char)); strcpy((yyval.c), "Min"); ;}
    break;

  case 82:
#line 721 "Gmsh.y"
    { (yyval.c) = (char *)Malloc(4 * sizeof(char)); strcpy((yyval.c), "Max"); ;}
    break;

  case 83:
#line 722 "Gmsh.y"
    { (yyval.c) = (char *)Malloc(5 * sizeof(char)); strcpy((yyval.c), "Step"); ;}
    break;

  case 84:
#line 723 "Gmsh.y"
    { (yyval.c) = (char *)Malloc(4 * sizeof(char)); strcpy((yyval.c), "Box"); ;}
    break;

  case 85:
#line 724 "Gmsh.y"
    { (yyval.c) = (char *)Malloc(9 * sizeof(char)); strcpy((yyval.c), "Cylinder"); ;}
    break;

  case 89:
#line 734 "Gmsh.y"
    {
      Msg::SetOnelabNumber((yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].d));
      Free((yyvsp[(3) - (7)].c));
    ;}
    break;

  case 90:
#line 739 "Gmsh.y"
    {
      Msg::SetOnelabString((yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].c));
      Free((yyvsp[(3) - (7)].c));
      Free((yyvsp[(5) - (7)].c));
    ;}
    break;

  case 91:
#line 745 "Gmsh.y"
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

  case 92:
#line 806 "Gmsh.y"
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

  case 93:
#line 821 "Gmsh.y"
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

  case 94:
#line 849 "Gmsh.y"
    {
      assignVariables((yyvsp[(1) - (9)].c), (yyvsp[(4) - (9)].l), (yyvsp[(7) - (9)].i), (yyvsp[(8) - (9)].l));
      Free((yyvsp[(1) - (9)].c));
      List_Delete((yyvsp[(4) - (9)].l));
      List_Delete((yyvsp[(8) - (9)].l));
    ;}
    break;

  case 95:
#line 859 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    ;}
    break;

  case 96:
#line 864 "Gmsh.y"
    {
      incrementVariable((yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].i));
      Free((yyvsp[(1) - (6)].c));
    ;}
    break;

  case 97:
#line 872 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    ;}
    break;

  case 98:
#line 877 "Gmsh.y"
    {
      incrementVariable((yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].i));
      Free((yyvsp[(1) - (6)].c));
    ;}
    break;

  case 99:
#line 885 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[(1) - (4)].c)] = std::vector<std::string>(1, (yyvsp[(3) - (4)].c));
      Free((yyvsp[(1) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 100:
#line 894 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[(1) - (8)].c)] = std::vector<std::string>();
      Free((yyvsp[(1) - (8)].c));
    ;}
    break;

  case 101:
#line 899 "Gmsh.y"
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

  case 102:
#line 911 "Gmsh.y"
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

  case 103:
#line 928 "Gmsh.y"
    {
      std::string tmp((yyvsp[(5) - (6)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (6)].c), 0, (yyvsp[(3) - (6)].c), tmp);
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 104:
#line 934 "Gmsh.y"
    {
      std::string tmp((yyvsp[(8) - (9)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (9)].c), (int)(yyvsp[(3) - (9)].d), (yyvsp[(6) - (9)].c), tmp);
      Free((yyvsp[(1) - (9)].c)); Free((yyvsp[(6) - (9)].c)); Free((yyvsp[(8) - (9)].c));
    ;}
    break;

  case 105:
#line 943 "Gmsh.y"
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

  case 106:
#line 961 "Gmsh.y"
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

  case 107:
#line 979 "Gmsh.y"
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(3) - (5)].c), d)){
	d += (yyvsp[(4) - (5)].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (5)].c), 0, (yyvsp[(3) - (5)].c), d);
      }
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 108:
#line 988 "Gmsh.y"
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[(1) - (8)].c), (int)(yyvsp[(3) - (8)].d), (yyvsp[(6) - (8)].c), d)){
	d += (yyvsp[(7) - (8)].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (8)].c), (int)(yyvsp[(3) - (8)].d), (yyvsp[(6) - (8)].c), d);
      }
      Free((yyvsp[(1) - (8)].c)); Free((yyvsp[(6) - (8)].c));
    ;}
    break;

  case 109:
#line 1000 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (8)].c), 0, (yyvsp[(5) - (8)].c), (yyvsp[(7) - (8)].u));
      Free((yyvsp[(1) - (8)].c)); Free((yyvsp[(5) - (8)].c));
    ;}
    break;

  case 110:
#line 1005 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (11)].c), (int)(yyvsp[(3) - (11)].d), (yyvsp[(8) - (11)].c), (yyvsp[(10) - (11)].u));
      Free((yyvsp[(1) - (11)].c)); Free((yyvsp[(8) - (11)].c));
    ;}
    break;

  case 111:
#line 1013 "Gmsh.y"
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

  case 112:
#line 1033 "Gmsh.y"
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

  case 113:
#line 1056 "Gmsh.y"
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

  case 114:
#line 1076 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      if(!GModel::current()->getFields()->newField((int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c)))
	yymsg(0, "Cannot create field %i of type '%s'", (int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c));
#endif
      Free((yyvsp[(6) - (7)].c));
    ;}
    break;

  case 115:
#line 1084 "Gmsh.y"
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

  case 116:
#line 1101 "Gmsh.y"
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

  case 117:
#line 1119 "Gmsh.y"
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

  case 118:
#line 1157 "Gmsh.y"
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

  case 119:
#line 1178 "Gmsh.y"
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

  case 120:
#line 1190 "Gmsh.y"
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

  case 124:
#line 1208 "Gmsh.y"
    {
      std::string key((yyvsp[(3) - (3)].c));
      std::vector<double> val(1, 0.);
      if(!gmsh_yysymbols.count(key)){
        gmsh_yysymbols[key].value = val;
      }
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 125:
#line 1217 "Gmsh.y"
    {
      std::string key((yyvsp[(3) - (5)].c));
      std::vector<double> val(1, (yyvsp[(5) - (5)].d));
      if(!gmsh_yysymbols.count(key)){
        gmsh_yysymbols[key].value = val;
      }
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 126:
#line 1226 "Gmsh.y"
    { init_options(); ;}
    break;

  case 127:
#line 1228 "Gmsh.y"
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

  case 128:
#line 1246 "Gmsh.y"
    { init_options(); ;}
    break;

  case 129:
#line 1248 "Gmsh.y"
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

  case 130:
#line 1264 "Gmsh.y"
    {
      std::string key((yyvsp[(3) - (5)].c)), val((yyvsp[(5) - (5)].c));
      if(!gmsh_yystringsymbols.count(key)){
        gmsh_yystringsymbols[key] = std::vector<std::string>(1, val);
      }
      Free((yyvsp[(3) - (5)].c));
      Free((yyvsp[(5) - (5)].c));
    ;}
    break;

  case 131:
#line 1273 "Gmsh.y"
    { init_options(); ;}
    break;

  case 132:
#line 1275 "Gmsh.y"
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

  case 134:
#line 1289 "Gmsh.y"
    {
      std::string name((yyvsp[(3) - (3)].c));
      Msg::UndefineOnelabParameter(name);
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 135:
#line 1297 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(doubleXstring));
      doubleXstring v = {(yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].c)};
      List_Add((yyval.l), &v);
    ;}
    break;

  case 136:
#line 1303 "Gmsh.y"
    {
      doubleXstring v = {(yyvsp[(3) - (5)].d), (yyvsp[(5) - (5)].c)};
      List_Add((yyval.l), &v);
    ;}
    break;

  case 137:
#line 1308 "Gmsh.y"
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

  case 144:
#line 1351 "Gmsh.y"
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

  case 145:
#line 1363 "Gmsh.y"
    {
      floatOptions["Min"].push_back((yyvsp[(2) - (2)].d));
    ;}
    break;

  case 146:
#line 1367 "Gmsh.y"
    {
      floatOptions["Max"].push_back((yyvsp[(2) - (2)].d));
    ;}
    break;

  case 147:
#line 1371 "Gmsh.y"
    {
      floatOptions["Step"].push_back((yyvsp[(2) - (2)].d));
    ;}
    break;

  case 148:
#line 1375 "Gmsh.y"
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

  case 149:
#line 1388 "Gmsh.y"
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

  case 150:
#line 1402 "Gmsh.y"
    {
      std::string key((yyvsp[(1) - (2)].c));
      std::string val((yyvsp[(2) - (2)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(1) - (2)].c));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 151:
#line 1410 "Gmsh.y"
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

  case 156:
#line 1435 "Gmsh.y"
    {
      std::string key((yyvsp[(1) - (2)].c));
      double val = (yyvsp[(2) - (2)].d);
      floatOptions[key].push_back(val);
      Free((yyvsp[(1) - (2)].c));
    ;}
    break;

  case 157:
#line 1443 "Gmsh.y"
    {
      std::string key((yyvsp[(1) - (2)].c));
      std::string val((yyvsp[(2) - (2)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(1) - (2)].c));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 158:
#line 1452 "Gmsh.y"
    {
      std::string key("Macro");
      std::string val((yyvsp[(2) - (2)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 159:
#line 1460 "Gmsh.y"
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

  case 160:
#line 1474 "Gmsh.y"
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

  case 161:
#line 1492 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    ;}
    break;

  case 162:
#line 1496 "Gmsh.y"
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

  case 163:
#line 1507 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (3)].c)), dim_entity, (yyvsp[(3) - (3)].d));
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 164:
#line 1515 "Gmsh.y"
    {
      (yyval.l) = 0;
    ;}
    break;

  case 165:
#line 1519 "Gmsh.y"
    {
      (yyval.l) = List_Create(1, 1, sizeof(double));
      double p = (yyvsp[(4) - (5)].d);
      List_Add((yyval.l), &p);
    ;}
    break;

  case 166:
#line 1525 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
    ;}
    break;

  case 167:
#line 1529 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      double flag = -1;
      List_Add((yyval.l), &flag);
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++)
        List_Add((yyval.l), List_Pointer((yyvsp[(4) - (5)].l), i));
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 168:
#line 1540 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = 0.;
    ;}
    break;

  case 169:
#line 1544 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 170:
#line 1550 "Gmsh.y"
    {
      (yyval.d) = 0;
    ;}
    break;

  case 171:
#line 1554 "Gmsh.y"
    {
      (yyval.d) = 1;
    ;}
    break;

  case 172:
#line 1560 "Gmsh.y"
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

  case 173:
#line 1583 "Gmsh.y"
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

  case 174:
#line 1599 "Gmsh.y"
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

  case 175:
#line 1615 "Gmsh.y"
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

  case 176:
#line 1632 "Gmsh.y"
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

  case 177:
#line 1649 "Gmsh.y"
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

  case 178:
#line 1686 "Gmsh.y"
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

  case 179:
#line 1730 "Gmsh.y"
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

  case 180:
#line 1746 "Gmsh.y"
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

  case 181:
#line 1763 "Gmsh.y"
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

  case 182:
#line 1794 "Gmsh.y"
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

  case 183:
#line 1810 "Gmsh.y"
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

  case 184:
#line 1827 "Gmsh.y"
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

  case 185:
#line 1843 "Gmsh.y"
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

  case 186:
#line 1893 "Gmsh.y"
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

  case 187:
#line 1911 "Gmsh.y"
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

  case 188:
#line 1932 "Gmsh.y"
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

  case 189:
#line 1953 "Gmsh.y"
    {
      myGmshSurface = 0;
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 190:
#line 1959 "Gmsh.y"
    {
      myGmshSurface = gmshSurface::getSurface((int)(yyvsp[(3) - (4)].d));
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 191:
#line 1965 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (10)].d);
      myGmshSurface = gmshParametricSurface::NewParametricSurface(num, (yyvsp[(7) - (10)].c), (yyvsp[(8) - (10)].c), (yyvsp[(9) - (10)].c));
      (yyval.s).Type = 0;
      (yyval.s).Num = num;
    ;}
    break;

  case 192:
#line 1972 "Gmsh.y"
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

  case 193:
#line 2013 "Gmsh.y"
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

  case 194:
#line 2028 "Gmsh.y"
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

  case 195:
#line 2060 "Gmsh.y"
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

  case 196:
#line 2094 "Gmsh.y"
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

  case 197:
#line 2127 "Gmsh.y"
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

  case 198:
#line 2162 "Gmsh.y"
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

  case 199:
#line 2197 "Gmsh.y"
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

  case 200:
#line 2232 "Gmsh.y"
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

  case 201:
#line 2256 "Gmsh.y"
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

  case 202:
#line 2282 "Gmsh.y"
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

  case 203:
#line 2299 "Gmsh.y"
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

  case 204:
#line 2315 "Gmsh.y"
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

  case 205:
#line 2333 "Gmsh.y"
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

  case 206:
#line 2351 "Gmsh.y"
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

  case 207:
#line 2364 "Gmsh.y"
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

  case 208:
#line 2376 "Gmsh.y"
    {
      dim_entity = (yyvsp[(2) - (2)].i);
    ;}
    break;

  case 209:
#line 2380 "Gmsh.y"
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

  case 210:
#line 2406 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 211:
#line 2408 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 212:
#line 2410 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 213:
#line 2412 "Gmsh.y"
    { (yyval.i) = 3; ;}
    break;

  case 214:
#line 2414 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(3) - (4)].d);
      if((yyval.i) < 0 || (yyval.i) > 3) yymsg(0, "GeoEntity dim out of range [0,3]");
    ;}
    break;

  case 215:
#line 2422 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 216:
#line 2424 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 217:
#line 2426 "Gmsh.y"
    { (yyval.i) = 3; ;}
    break;

  case 218:
#line 2428 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(3) - (4)].d);
      if((yyval.i)<1 || (yyval.i)>3) yymsg(0, "GeoEntity dim out of range [1,3]");
    ;}
    break;

  case 219:
#line 2436 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 220:
#line 2438 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 221:
#line 2440 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(3) - (4)].d);
      if((yyval.i)<1 || (yyval.i)>2) yymsg(0, "GeoEntity dim out of range [1,2]");
    ;}
    break;

  case 222:
#line 2448 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 223:
#line 2450 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 224:
#line 2452 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 225:
#line 2454 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(3) - (4)].d);
      if((yyval.i) < 0 || (yyval.i) > 2) yymsg(0, "GeoEntity dim out of range [0,2]");
    ;}
    break;

  case 226:
#line 2464 "Gmsh.y"
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

  case 227:
#line 2480 "Gmsh.y"
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

  case 228:
#line 2496 "Gmsh.y"
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

  case 229:
#line 2512 "Gmsh.y"
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

  case 230:
#line 2528 "Gmsh.y"
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

  case 231:
#line 2544 "Gmsh.y"
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

  case 232:
#line 2561 "Gmsh.y"
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

  case 233:
#line 2587 "Gmsh.y"
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

  case 234:
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

  case 235:
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

  case 236:
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

  case 237:
#line 2697 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 238:
#line 2698 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 239:
#line 2703 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    ;}
    break;

  case 240:
#line 2707 "Gmsh.y"
    {
      List_Add((yyval.l), &(yyvsp[(2) - (2)].s));
    ;}
    break;

  case 241:
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

  case 242:
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

  case 243:
#line 2748 "Gmsh.y"
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

  case 244:
#line 2768 "Gmsh.y"
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

  case 245:
#line 2788 "Gmsh.y"
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

  case 246:
#line 2807 "Gmsh.y"
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

  case 247:
#line 2834 "Gmsh.y"
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

  case 248:
#line 2859 "Gmsh.y"
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

  case 249:
#line 2884 "Gmsh.y"
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

  case 250:
#line 2896 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      GModel::current()->getFields()->deleteField((int)(yyvsp[(4) - (6)].d));
#endif
    ;}
    break;

  case 251:
#line 2902 "Gmsh.y"
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

  case 252:
#line 2917 "Gmsh.y"
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

  case 253:
#line 2948 "Gmsh.y"
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

  case 254:
#line 2960 "Gmsh.y"
    {
      gmsh_yynamespaces.clear();
    ;}
    break;

  case 255:
#line 2969 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), dimTags);
      setColor(dimTags, (yyvsp[(2) - (5)].u), false);
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 256:
#line 2976 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(5) - (6)].l), dimTags);
      setColor(dimTags, (yyvsp[(3) - (6)].u), true);
      List_Delete((yyvsp[(5) - (6)].l));
    ;}
    break;

  case 257:
#line 2988 "Gmsh.y"
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

  case 258:
#line 3008 "Gmsh.y"
    {
      setVisibility(-1, 1, false);
    ;}
    break;

  case 259:
#line 3012 "Gmsh.y"
    {
      setVisibility(-1, 1, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 260:
#line 3017 "Gmsh.y"
    {
      setVisibility(-1, 0, false);
    ;}
    break;

  case 261:
#line 3021 "Gmsh.y"
    {
      setVisibility(-1, 0, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 262:
#line 3026 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(3) - (4)].l), dimTags);
      setVisibility(dimTags, 1, false);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 263:
#line 3033 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), dimTags);
      setVisibility(dimTags, 1, true);
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 264:
#line 3040 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(3) - (4)].l), dimTags);
      setVisibility(dimTags, 0, false);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 265:
#line 3047 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), dimTags);
      setVisibility(dimTags, 0, true);
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 266:
#line 3059 "Gmsh.y"
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

  case 267:
#line 3135 "Gmsh.y"
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

  case 268:
#line 3153 "Gmsh.y"
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

  case 269:
#line 3178 "Gmsh.y"
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

  case 270:
#line 3193 "Gmsh.y"
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

  case 271:
#line 3244 "Gmsh.y"
    {
#if defined(HAVE_FLTK)
      if(FlGui::available()) FlGui::instance()->splitCurrentOpenglWindow('u');
#endif
    ;}
    break;

  case 272:
#line 3250 "Gmsh.y"
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

  case 273:
#line 3262 "Gmsh.y"
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

  case 274:
#line 3294 "Gmsh.y"
    {
      Msg::Exit(0, false); // will return 0 only if no meshing error occurred
    ;}
    break;

  case 275:
#line 3298 "Gmsh.y"
    {
      Msg::Exit((int)(yyvsp[(2) - (3)].d), true); // will always return the specified value
    ;}
    break;

  case 276:
#line 3302 "Gmsh.y"
    {
      gmsh_yyerrorstate = 999; // this will be checked when yyparse returns
      YYABORT;
    ;}
    break;

  case 277:
#line 3307 "Gmsh.y"
    {
      // force sync
      if(GModel::current()->getOCCInternals())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      GModel::current()->synchronizeDiscreteCADInternals();
      GModel::current()->getGEOInternals()->synchronize(GModel::current());
    ;}
    break;

  case 278:
#line 3315 "Gmsh.y"
    {
      new GModel();
      GModel::current(GModel::list.size() - 1);
    ;}
    break;

  case 279:
#line 3320 "Gmsh.y"
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

  case 280:
#line 3331 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 1;
      SetBoundingBox((yyvsp[(3) - (15)].d), (yyvsp[(5) - (15)].d), (yyvsp[(7) - (15)].d), (yyvsp[(9) - (15)].d), (yyvsp[(11) - (15)].d), (yyvsp[(13) - (15)].d));
    ;}
    break;

  case 281:
#line 3336 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
      drawContext::global()->draw(false); // not rate limited
#endif
    ;}
    break;

  case 282:
#line 3342 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
     CTX::instance()->meshChanged();
     for(std::size_t index = 0; index < PView::list.size(); index++)
       PView::list[index]->setChanged(true);
#endif
    ;}
    break;

  case 283:
#line 3350 "Gmsh.y"
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

  case 284:
#line 3361 "Gmsh.y"
    {
      GModel::current()->makeDiscreteRegionsSimplyConnected();
      GModel::current()->makeDiscreteFacesSimplyConnected();
      GModel::current()->createTopologyFromMesh();
      // Warning: this clears GEO_Internals!
      GModel::current()->exportDiscreteGEOInternals();
    ;}
    break;

  case 285:
#line 3369 "Gmsh.y"
    {
      GModel::current()->classifySurfaces((yyvsp[(3) - (9)].d), (yyvsp[(5) - (9)].d), (yyvsp[(7) - (9)].d), M_PI);
    ;}
    break;

  case 286:
#line 3373 "Gmsh.y"
    {
      GModel::current()->classifySurfaces((yyvsp[(3) - (11)].d), (yyvsp[(5) - (11)].d), (yyvsp[(7) - (11)].d), (yyvsp[(9) - (11)].d));
    ;}
    break;

  case 287:
#line 3377 "Gmsh.y"
    {
      GModel::current()->createGeometryOfDiscreteEntities();
    ;}
    break;

  case 288:
#line 3381 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(3) - (4)].l), dimTags);
      GModel::current()->createGeometryOfDiscreteEntities(dimTags);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 289:
#line 3388 "Gmsh.y"
    {
      GModel::current()->renumberMeshVertices();
    ;}
    break;

  case 290:
#line 3392 "Gmsh.y"
    {
      GModel::current()->renumberMeshElements();
    ;}
    break;

  case 291:
#line 3396 "Gmsh.y"
    {
      GModel::current()->createMEdges();
    ;}
    break;

  case 292:
#line 3400 "Gmsh.y"
    {
      GModel::current()->createMFaces();
    ;}
    break;

  case 293:
#line 3404 "Gmsh.y"
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

  case 294:
#line 3417 "Gmsh.y"
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

  case 295:
#line 3427 "Gmsh.y"
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

  case 296:
#line 3447 "Gmsh.y"
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

  case 297:
#line 3473 "Gmsh.y"
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

  case 298:
#line 3489 "Gmsh.y"
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

  case 299:
#line 3506 "Gmsh.y"
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

  case 300:
#line 3523 "Gmsh.y"
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

  case 301:
#line 3545 "Gmsh.y"
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

  case 302:
#line 3567 "Gmsh.y"
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

  case 303:
#line 3602 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip(nullptr, "Return");
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 304:
#line 3610 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip(nullptr, "Return");
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 305:
#line 3618 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    ;}
    break;

  case 306:
#line 3624 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function '%s'", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 307:
#line 3631 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function '%s'", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 308:
#line 3638 "Gmsh.y"
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

  case 309:
#line 3658 "Gmsh.y"
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

  case 310:
#line 3684 "Gmsh.y"
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

  case 311:
#line 3696 "Gmsh.y"
    {
      ImbricatedTest--;
      if(ImbricatedTest < 0)
        yymsg(1, "Orphan EndIf");
    ;}
    break;

  case 312:
#line 3707 "Gmsh.y"
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

  case 313:
#line 3725 "Gmsh.y"
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

  case 314:
#line 3743 "Gmsh.y"
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

  case 315:
#line 3761 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 316:
#line 3767 "Gmsh.y"
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

  case 317:
#line 3785 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 318:
#line 3791 "Gmsh.y"
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

  case 319:
#line 3811 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 320:
#line 3817 "Gmsh.y"
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

  case 321:
#line 3835 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 322:
#line 3841 "Gmsh.y"
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

  case 323:
#line 3858 "Gmsh.y"
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

  case 324:
#line 3874 "Gmsh.y"
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

  case 325:
#line 3891 "Gmsh.y"
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

  case 326:
#line 3909 "Gmsh.y"
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

  case 327:
#line 3946 "Gmsh.y"
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

  case 328:
#line 3973 "Gmsh.y"
    {
    ;}
    break;

  case 329:
#line 3976 "Gmsh.y"
    {
    ;}
    break;

  case 330:
#line 3982 "Gmsh.y"
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

  case 331:
#line 3994 "Gmsh.y"
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

  case 332:
#line 4014 "Gmsh.y"
    {
      extr.mesh.ScaleLast = true;
    ;}
    break;

  case 333:
#line 4018 "Gmsh.y"
    {
      extr.mesh.Recombine = true;
    ;}
    break;

  case 334:
#line 4022 "Gmsh.y"
    {
      extr.mesh.Recombine = (yyvsp[(2) - (3)].d) ? true : false;
    ;}
    break;

  case 335:
#line 4026 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1;
    ;}
    break;

  case 336:
#line 4030 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1_RECOMB;
    ;}
    break;

  case 337:
#line 4034 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1;
    ;}
    break;

  case 338:
#line 4038 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1_RECOMB;
    ;}
    break;

  case 339:
#line 4042 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(6) - (9)].l), tags);
      int num = (int)(yyvsp[(3) - (9)].d);
      GModel::current()->getGEOInternals()->addDiscreteSurface(num);
      extr.mesh.Holes[num].first = (yyvsp[(8) - (9)].d);
      extr.mesh.Holes[num].second = tags;
      List_Delete((yyvsp[(6) - (9)].l));
    ;}
    break;

  case 340:
#line 4051 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (6)].c), "Index"))
        extr.mesh.BoundaryLayerIndex = (yyvsp[(4) - (6)].d);
      else if(!strcmp((yyvsp[(2) - (6)].c), "View"))
        extr.mesh.ViewIndex = (yyvsp[(4) - (6)].d);
      Free((yyvsp[(2) - (6)].c));
    ;}
    break;

  case 341:
#line 4063 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Union; ;}
    break;

  case 342:
#line 4064 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Intersection; ;}
    break;

  case 343:
#line 4065 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Difference; ;}
    break;

  case 344:
#line 4066 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Section; ;}
    break;

  case 345:
#line 4067 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Fragments; ;}
    break;

  case 346:
#line 4071 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 347:
#line 4072 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 348:
#line 4073 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 349:
#line 4074 "Gmsh.y"
    { (yyval.i) = (yyvsp[(2) - (3)].d) ? 1 : 0; ;}
    break;

  case 350:
#line 4075 "Gmsh.y"
    { (yyval.i) = (yyvsp[(3) - (4)].d) ? 2 : 0; ;}
    break;

  case 351:
#line 4080 "Gmsh.y"
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

  case 352:
#line 4119 "Gmsh.y"
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

  case 353:
#line 4146 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      DiscreteClassify((yyvsp[(3) - (7)].l), (yyvsp[(6) - (7)].d), M_PI, (yyval.l));
      List_Delete((yyvsp[(3) - (7)].l));
    ;}
    break;

  case 354:
#line 4152 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      DiscreteClassify((yyvsp[(3) - (9)].l), (yyvsp[(6) - (9)].d), (yyvsp[(8) - (9)].d), (yyval.l));
      List_Delete((yyvsp[(3) - (9)].l));
    ;}
    break;

  case 355:
#line 4158 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      DiscreteRecognize((yyvsp[(3) - (7)].l), (yyvsp[(6) - (7)].d), -1., (yyval.l));
      List_Delete((yyvsp[(3) - (7)].l));
    ;}
    break;

  case 356:
#line 4164 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      DiscreteRecognize((yyvsp[(3) - (9)].l), (yyvsp[(6) - (9)].d), (yyvsp[(8) - (9)].d), (yyval.l));
      List_Delete((yyvsp[(3) - (9)].l));
    ;}
    break;

  case 357:
#line 4170 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      DiscreteShapeFromFile((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d), M_PI, -1., (yyval.l));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 358:
#line 4176 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      DiscreteShapeFromFile((yyvsp[(3) - (8)].c), (yyvsp[(5) - (8)].d), (yyvsp[(7) - (8)].d), -1., (yyval.l));
      Free((yyvsp[(3) - (8)].c));
    ;}
    break;

  case 359:
#line 4182 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      DiscreteShapeFromFile((yyvsp[(3) - (10)].c), (yyvsp[(5) - (10)].d), (yyvsp[(7) - (10)].d), (yyvsp[(9) - (10)].d), (yyval.l));
      Free((yyvsp[(3) - (10)].c));
    ;}
    break;

  case 360:
#line 4192 "Gmsh.y"
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

  case 361:
#line 4228 "Gmsh.y"
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    ;}
    break;

  case 362:
#line 4232 "Gmsh.y"
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
#line 4259 "Gmsh.y"
    {
      (yyval.i) = -1; // left
    ;}
    break;

  case 364:
#line 4263 "Gmsh.y"
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
#line 4279 "Gmsh.y"
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   ;}
    break;

  case 366:
#line 4283 "Gmsh.y"
    {
     (yyval.l) = (yyvsp[(2) - (2)].l);
   ;}
    break;

  case 367:
#line 4288 "Gmsh.y"
    {
      (yyval.i) = 45;
    ;}
    break;

  case 368:
#line 4292 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(2) - (2)].d);
    ;}
    break;

  case 369:
#line 4298 "Gmsh.y"
    {
      (yyval.l) = List_Create(1, 1, sizeof(double));
    ;}
    break;

  case 370:
#line 4302 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
    ;}
    break;

  case 371:
#line 4309 "Gmsh.y"
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
#line 4332 "Gmsh.y"
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
#line 4351 "Gmsh.y"
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

  case 374:
#line 4393 "Gmsh.y"
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

  case 375:
#line 4439 "Gmsh.y"
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

  case 376:
#line 4480 "Gmsh.y"
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

  case 377:
#line 4506 "Gmsh.y"
    {
      int dim = (int)(yyvsp[(2) - (8)].i);
      int tag = (int)(yyvsp[(4) - (8)].d);
      int new_tag = (int)(yyvsp[(6) - (8)].d);
      GModel::current()->changeEntityTag(dim, tag, new_tag);
    ;}
    break;

  case 378:
#line 4513 "Gmsh.y"
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
#line 4524 "Gmsh.y"
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

  case 380:
#line 4542 "Gmsh.y"
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

  case 381:
#line 4560 "Gmsh.y"
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

  case 382:
#line 4591 "Gmsh.y"
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

  case 383:
#line 4618 "Gmsh.y"
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

  case 384:
#line 4646 "Gmsh.y"
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
#line 4678 "Gmsh.y"
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
#line 4706 "Gmsh.y"
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
#line 4732 "Gmsh.y"
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
#line 4758 "Gmsh.y"
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
#line 4784 "Gmsh.y"
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
#line 4810 "Gmsh.y"
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
#line 4831 "Gmsh.y"
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
#line 4843 "Gmsh.y"
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

  case 393:
#line 4892 "Gmsh.y"
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

  case 394:
#line 4947 "Gmsh.y"
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

  case 395:
#line 4963 "Gmsh.y"
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
#line 4975 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (4)].l), tags);
      GModel::current()->getGEOInternals()->setCompoundMesh((yyvsp[(2) - (4)].i), tags);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 397:
#line 4981 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (6)].l), tags);
      tags.push_back(- (int) (yyvsp[(5) - (6)].d));
      GModel::current()->getGEOInternals()->setCompoundMesh((yyvsp[(2) - (6)].i), tags);
      List_Delete((yyvsp[(3) - (6)].l));
    ;}
    break;

  case 398:
#line 4993 "Gmsh.y"
    {
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals())
        GModel::current()->getOCCInternals()->removeAllDuplicates();
      else
        GModel::current()->getGEOInternals()->removeAllDuplicates();
    ;}
    break;

  case 399:
#line 5000 "Gmsh.y"
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
#line 5015 "Gmsh.y"
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
#line 5024 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > in, out;
      ListOfShapes2VectorOfPairs((yyvsp[(3) - (5)].l), in);
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
      List_Delete((yyvsp[(3) - (5)].l));
    ;}
    break;

  case 402:
#line 5056 "Gmsh.y"
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

  case 403:
#line 5084 "Gmsh.y"
    { (yyval.c) = (char*)"Homology"; ;}
    break;

  case 404:
#line 5085 "Gmsh.y"
    { (yyval.c) = (char*)"Cohomology"; ;}
    break;

  case 405:
#line 5086 "Gmsh.y"
    { (yyval.c) = (char*)"Betti"; ;}
    break;

  case 406:
#line 5091 "Gmsh.y"
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest((yyvsp[(1) - (2)].c), domain, subdomain, dim);
    ;}
    break;

  case 407:
#line 5097 "Gmsh.y"
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

  case 408:
#line 5109 "Gmsh.y"
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

  case 409:
#line 5127 "Gmsh.y"
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

  case 410:
#line 5154 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d);           ;}
    break;

  case 411:
#line 5155 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (3)].d);           ;}
    break;

  case 412:
#line 5156 "Gmsh.y"
    { (yyval.d) = -(yyvsp[(2) - (2)].d);          ;}
    break;

  case 413:
#line 5157 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);           ;}
    break;

  case 414:
#line 5158 "Gmsh.y"
    { (yyval.d) = !(yyvsp[(2) - (2)].d);          ;}
    break;

  case 415:
#line 5159 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) - (yyvsp[(3) - (3)].d);      ;}
    break;

  case 416:
#line 5160 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) + (yyvsp[(3) - (3)].d);      ;}
    break;

  case 417:
#line 5161 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) * (yyvsp[(3) - (3)].d);      ;}
    break;

  case 418:
#line 5163 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (3)].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));
      else
	(yyval.d) = (yyvsp[(1) - (3)].d) / (yyvsp[(3) - (3)].d);
    ;}
    break;

  case 419:
#line 5169 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) | (int)(yyvsp[(3) - (3)].d); ;}
    break;

  case 420:
#line 5170 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) & (int)(yyvsp[(3) - (3)].d); ;}
    break;

  case 421:
#line 5171 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) % (int)(yyvsp[(3) - (3)].d); ;}
    break;

  case 422:
#line 5172 "Gmsh.y"
    { (yyval.d) = pow((yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));  ;}
    break;

  case 423:
#line 5173 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d);      ;}
    break;

  case 424:
#line 5174 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) > (yyvsp[(3) - (3)].d);      ;}
    break;

  case 425:
#line 5175 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) <= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 426:
#line 5176 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) >= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 427:
#line 5177 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) == (yyvsp[(3) - (3)].d);     ;}
    break;

  case 428:
#line 5178 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) != (yyvsp[(3) - (3)].d);     ;}
    break;

  case 429:
#line 5179 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) && (yyvsp[(3) - (3)].d);     ;}
    break;

  case 430:
#line 5180 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) || (yyvsp[(3) - (3)].d);     ;}
    break;

  case 431:
#line 5181 "Gmsh.y"
    { (yyval.d) = ((int)(yyvsp[(1) - (3)].d) >> (int)(yyvsp[(3) - (3)].d)); ;}
    break;

  case 432:
#line 5182 "Gmsh.y"
    { (yyval.d) = ((int)(yyvsp[(1) - (3)].d) << (int)(yyvsp[(3) - (3)].d)); ;}
    break;

  case 433:
#line 5183 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (5)].d) ? (yyvsp[(3) - (5)].d) : (yyvsp[(5) - (5)].d); ;}
    break;

  case 434:
#line 5184 "Gmsh.y"
    { (yyval.d) = ((yyvsp[(3) - (4)].d) < 0) ? 0 : 1; ;}
    break;

  case 435:
#line 5185 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 436:
#line 5186 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 437:
#line 5187 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 438:
#line 5188 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 439:
#line 5189 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 440:
#line 5190 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 441:
#line 5191 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 442:
#line 5192 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 443:
#line 5193 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 444:
#line 5194 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 445:
#line 5195 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 446:
#line 5196 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 447:
#line 5197 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 448:
#line 5198 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 449:
#line 5199 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 450:
#line 5200 "Gmsh.y"
    { (yyval.d) = std::abs((yyvsp[(3) - (4)].d)); ;}
    break;

  case 451:
#line 5201 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 452:
#line 5202 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 453:
#line 5203 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d) + 0.5); ;}
    break;

  case 454:
#line 5204 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 455:
#line 5205 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 456:
#line 5206 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 457:
#line 5207 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 458:
#line 5208 "Gmsh.y"
    { (yyval.d) = std::max((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 459:
#line 5209 "Gmsh.y"
    { (yyval.d) = std::min((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 460:
#line 5218 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 461:
#line 5219 "Gmsh.y"
    { (yyval.d) = 3.141592653589793; ;}
    break;

  case 462:
#line 5220 "Gmsh.y"
    { (yyval.d) = (double)ImbricatedTest; ;}
    break;

  case 463:
#line 5221 "Gmsh.y"
    { (yyval.d) = Msg::GetCommRank(); ;}
    break;

  case 464:
#line 5222 "Gmsh.y"
    { (yyval.d) = Msg::GetCommSize(); ;}
    break;

  case 465:
#line 5223 "Gmsh.y"
    { (yyval.d) = GetGmshMajorVersion(); ;}
    break;

  case 466:
#line 5224 "Gmsh.y"
    { (yyval.d) = GetGmshMinorVersion(); ;}
    break;

  case 467:
#line 5225 "Gmsh.y"
    { (yyval.d) = GetGmshPatchVersion(); ;}
    break;

  case 468:
#line 5226 "Gmsh.y"
    { (yyval.d) = Cpu(); ;}
    break;

  case 469:
#line 5227 "Gmsh.y"
    { (yyval.d) = GetMemoryUsage()/1024./1024.; ;}
    break;

  case 470:
#line 5228 "Gmsh.y"
    { (yyval.d) = TotalRam(); ;}
    break;

  case 471:
#line 5233 "Gmsh.y"
    { init_options(); ;}
    break;

  case 472:
#line 5235 "Gmsh.y"
    {
      std::vector<double> val(1, (yyvsp[(3) - (6)].d));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.d) = val[0];
    ;}
    break;

  case 473:
#line 5241 "Gmsh.y"
    {
      (yyval.d) = (yyvsp[(1) - (1)].d);
    ;}
    break;

  case 474:
#line 5245 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 475:
#line 5250 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 476:
#line 5255 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(1) - (1)].c2).char1, (yyvsp[(1) - (1)].c2).char2);
    ;}
    break;

  case 477:
#line 5260 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float(nullptr, (yyvsp[(1) - (4)].c), 2, (int)(yyvsp[(3) - (4)].d));
    ;}
    break;

  case 478:
#line 5265 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float(nullptr, (yyvsp[(1) - (4)].c), 2, (int)(yyvsp[(3) - (4)].d));
    ;}
    break;

  case 479:
#line 5269 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(3) - (4)].c2).char1, (yyvsp[(3) - (4)].c2).char2, 1, 0, 0., 1);
    ;}
    break;

  case 480:
#line 5273 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(3) - (6)].c2).char1, (yyvsp[(3) - (6)].c2).char2, (yyvsp[(5) - (6)].c), 0, 0., 1);
    ;}
    break;

  case 481:
#line 5277 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(3) - (5)].c2).char1, (yyvsp[(3) - (5)].c2).char2, 1, 0, (yyvsp[(4) - (5)].d), 2);
    ;}
    break;

  case 482:
#line 5281 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(3) - (7)].c2).char1, (yyvsp[(3) - (7)].c2).char2, (yyvsp[(5) - (7)].c), 0, (yyvsp[(6) - (7)].d), 2);
    ;}
    break;

  case 483:
#line 5285 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(3) - (8)].c2).char1, (yyvsp[(3) - (8)].c2).char2, 2, (int)(yyvsp[(5) - (8)].d), (yyvsp[(7) - (8)].d), 2);
    ;}
    break;

  case 484:
#line 5289 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(3) - (10)].c2).char1, (yyvsp[(3) - (10)].c2).char2, (yyvsp[(5) - (10)].c), (int)(yyvsp[(7) - (10)].d), (yyvsp[(9) - (10)].d), 2);
    ;}
    break;

  case 485:
#line 5293 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.d) = !StatFile(tmp);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 486:
#line 5299 "Gmsh.y"
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

  case 487:
#line 5314 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float_getDim((yyvsp[(2) - (6)].c2).char1, (yyvsp[(2) - (6)].c2).char2, (yyvsp[(4) - (6)].c));
    ;}
    break;

  case 488:
#line 5318 "Gmsh.y"
    {
      std::string struct_namespace((yyvsp[(3) - (4)].c));
      (yyval.d) = (double)gmsh_yynamespaces[struct_namespace].size();
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 489:
#line 5324 "Gmsh.y"
    {
      std::string struct_namespace(std::string(""));
      (yyval.d) = (double)gmsh_yynamespaces[struct_namespace].size();
    ;}
    break;

  case 490:
#line 5329 "Gmsh.y"
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

  case 491:
#line 5348 "Gmsh.y"
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
#line 5368 "Gmsh.y"
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

  case 493:
#line 5389 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(nullptr, (yyvsp[(1) - (3)].c), (yyvsp[(3) - (3)].c));
    ;}
    break;

  case 494:
#line 5393 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c), (yyvsp[(5) - (5)].c));
    ;}
    break;

  case 495:
#line 5397 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(nullptr, (yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].c), (int)(yyvsp[(5) - (6)].d));
    ;}
    break;

  case 496:
#line 5401 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(1) - (8)].c), (yyvsp[(3) - (8)].c), (yyvsp[(5) - (8)].c), (int)(yyvsp[(7) - (8)].d));
    ;}
    break;

  case 497:
#line 5405 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(nullptr, (yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].c), (int)(yyvsp[(5) - (6)].d));
    ;}
    break;

  case 498:
#line 5409 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(1) - (8)].c), (yyvsp[(3) - (8)].c), (yyvsp[(5) - (8)].c), (int)(yyvsp[(7) - (8)].d));
    ;}
    break;

  case 499:
#line 5413 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), (yyval.d));
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 500:
#line 5418 "Gmsh.y"
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

  case 501:
#line 5428 "Gmsh.y"
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

  case 502:
#line 5438 "Gmsh.y"
    {
      (yyval.d) = Msg::GetValue((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 503:
#line 5443 "Gmsh.y"
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

  case 504:
#line 5454 "Gmsh.y"
    {
      std::string s((yyvsp[(3) - (6)].c)), substr((yyvsp[(5) - (6)].c));
      if(s.find(substr) != std::string::npos)
        (yyval.d) = 1.;
      else
        (yyval.d) = 0.;
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 505:
#line 5463 "Gmsh.y"
    {
      (yyval.d) = strlen((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 506:
#line 5468 "Gmsh.y"
    {
      (yyval.d) = strcmp((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 507:
#line 5473 "Gmsh.y"
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

  case 508:
#line 5500 "Gmsh.y"
    { (yyval.d) = 0.; ;}
    break;

  case 509:
#line 5502 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);;}
    break;

  case 510:
#line 5507 "Gmsh.y"
    { (yyval.c) = nullptr; ;}
    break;

  case 511:
#line 5509 "Gmsh.y"
    { (yyval.c) = (yyvsp[(2) - (2)].c);;}
    break;

  case 512:
#line 5514 "Gmsh.y"
    {
      std::string struct_namespace((yyvsp[(2) - (3)].c2).char1? (yyvsp[(2) - (3)].c2).char1 : std::string("")),
        struct_name((yyvsp[(2) - (3)].c2).char2);
      init_options
        (gmsh_yynamespaces.getMember_ValMax(struct_namespace, struct_name));
    ;}
    break;

  case 513:
#line 5521 "Gmsh.y"
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

  case 514:
#line 5537 "Gmsh.y"
    { (yyval.c2).char1 = nullptr; (yyval.c2).char2 = (yyvsp[(1) - (1)].c); ;}
    break;

  case 515:
#line 5539 "Gmsh.y"
    { (yyval.c2).char1 = (yyvsp[(1) - (3)].c); (yyval.c2).char2 = (yyvsp[(3) - (3)].c); ;}
    break;

  case 516:
#line 5544 "Gmsh.y"
    { (yyval.i) = 99; ;}
    break;

  case 517:
#line 5546 "Gmsh.y"
    { (yyval.i) = (int)(yyvsp[(2) - (2)].d); ;}
    break;

  case 518:
#line 5551 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 519:
#line 5553 "Gmsh.y"
    { (yyval.i) = (yyvsp[(2) - (3)].i); ;}
    break;

  case 520:
#line 5558 "Gmsh.y"
    {
      memcpy((yyval.v), (yyvsp[(1) - (1)].v), 5 * sizeof(double));
    ;}
    break;

  case 521:
#line 5562 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 522:
#line 5566 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 523:
#line 5570 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] - (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 524:
#line 5574 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] + (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 525:
#line 5581 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (11)].d);  (yyval.v)[1] = (yyvsp[(4) - (11)].d);  (yyval.v)[2] = (yyvsp[(6) - (11)].d);  (yyval.v)[3] = (yyvsp[(8) - (11)].d); (yyval.v)[4] = (yyvsp[(10) - (11)].d);
    ;}
    break;

  case 526:
#line 5585 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (9)].d);  (yyval.v)[1] = (yyvsp[(4) - (9)].d);  (yyval.v)[2] = (yyvsp[(6) - (9)].d);  (yyval.v)[3] = (yyvsp[(8) - (9)].d); (yyval.v)[4] = 1.0;
    ;}
    break;

  case 527:
#line 5589 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 528:
#line 5593 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 529:
#line 5600 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].l)));
    ;}
    break;

  case 530:
#line 5605 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].l)));
    ;}
    break;

  case 531:
#line 5612 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 532:
#line 5617 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 533:
#line 5621 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
    ;}
    break;

  case 534:
#line 5625 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 535:
#line 5629 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 536:
#line 5637 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (5)].d);
      }
    ;}
    break;

  case 537:
#line 5648 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
    ;}
    break;

  case 538:
#line 5652 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 539:
#line 5656 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 540:
#line 5667 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 541:
#line 5671 "Gmsh.y"
    {
      (yyval.l) = 0;
    ;}
    break;

  case 542:
#line 5675 "Gmsh.y"
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

  case 543:
#line 5689 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 544:
#line 5697 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (3)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (3)].d);
      }
    ;}
    break;

  case 545:
#line 5705 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      for(double d = (yyvsp[(1) - (3)].d); ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d <= (yyvsp[(3) - (3)].d)) : (d >= (yyvsp[(3) - (3)].d));
          ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d += 1.) : (d -= 1.))
	List_Add((yyval.l), &d);
    ;}
    break;

  case 546:
#line 5712 "Gmsh.y"
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

  case 547:
#line 5722 "Gmsh.y"
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

  case 548:
#line 5745 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags(0, (yyval.l));
    ;}
    break;

  case 549:
#line 5750 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags(0, (yyval.l));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 550:
#line 5756 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags((yyvsp[(1) - (4)].i), (yyval.l));
    ;}
    break;

  case 551:
#line 5761 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags((yyvsp[(1) - (2)].i), (yyval.l));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 552:
#line 5767 "Gmsh.y"
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

  case 553:
#line 5778 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getElementaryTagsForPhysicalNames((yyvsp[(2) - (5)].i), (yyvsp[(4) - (5)].l), (yyval.l));
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 554:
#line 5784 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getParentTags((yyvsp[(2) - (3)].i), (yyvsp[(3) - (3)].l), (yyval.l));
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 555:
#line 5790 "Gmsh.y"
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

  case 556:
#line 5804 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getBoundingBox((yyvsp[(2) - (5)].i), (yyvsp[(4) - (5)].l), (yyval.l));
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 557:
#line 5810 "Gmsh.y"
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

  case 558:
#line 5822 "Gmsh.y"
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

  case 559:
#line 5836 "Gmsh.y"
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

  case 560:
#line 5849 "Gmsh.y"
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

  case 561:
#line 5880 "Gmsh.y"
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

  case 562:
#line 5904 "Gmsh.y"
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

  case 563:
#line 5925 "Gmsh.y"
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

  case 564:
#line 5945 "Gmsh.y"
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

  case 565:
#line 5966 "Gmsh.y"
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

  case 566:
#line 5983 "Gmsh.y"
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
#line 5993 "Gmsh.y"
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

  case 568:
#line 6003 "Gmsh.y"
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

  case 569:
#line 6013 "Gmsh.y"
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

  case 570:
#line 6025 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfFloat(nullptr, (yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c));
    ;}
    break;

  case 571:
#line 6029 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfFloat((yyvsp[(1) - (7)].c), (yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].c));
    ;}
    break;

  case 572:
#line 6034 "Gmsh.y"
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

  case 573:
#line 6046 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 574:
#line 6050 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 575:
#line 6054 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (6)].l);
    ;}
    break;

  case 576:
#line 6058 "Gmsh.y"
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

  case 577:
#line 6076 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = (yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1);
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 578:
#line 6084 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = pow(10,(yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1));
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 579:
#line 6092 "Gmsh.y"
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

  case 580:
#line 6121 "Gmsh.y"
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

  case 581:
#line 6131 "Gmsh.y"
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

  case 582:
#line 6147 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
        double *d = (double*)List_Pointer((yyvsp[(3) - (4)].l), i);
        *d = std::abs(*d);
      }
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 583:
#line 6158 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 584:
#line 6163 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 585:
#line 6167 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].d)));
    ;}
    break;

  case 586:
#line 6171 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (3)].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 587:
#line 6183 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(char*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].c)));
    ;}
    break;

  case 588:
#line 6188 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].c)));
    ;}
    break;

  case 589:
#line 6195 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (9)].d), (int)(yyvsp[(4) - (9)].d), (int)(yyvsp[(6) - (9)].d), (int)(yyvsp[(8) - (9)].d));
    ;}
    break;

  case 590:
#line 6199 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (7)].d), (int)(yyvsp[(4) - (7)].d), (int)(yyvsp[(6) - (7)].d), 255);
    ;}
    break;

  case 591:
#line 6211 "Gmsh.y"
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

  case 592:
#line 6228 "Gmsh.y"
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(5) - (5)].c), val);
      (yyval.u) = val;
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(5) - (5)].c));
    ;}
    break;

  case 593:
#line 6238 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 594:
#line 6242 "Gmsh.y"
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

  case 595:
#line 6257 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].u)));
    ;}
    break;

  case 596:
#line 6262 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].u)));
    ;}
    break;

  case 597:
#line 6269 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 598:
#line 6273 "Gmsh.y"
    {
      // No need to extend to Struct_FullName (a Tag is not a String)
      (yyval.c) = treat_Struct_FullName_String(nullptr, (yyvsp[(1) - (1)].c));
    ;}
    break;

  case 599:
#line 6278 "Gmsh.y"
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

  case 600:
#line 6292 "Gmsh.y"
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

  case 601:
#line 6306 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String(nullptr, (yyvsp[(1) - (3)].c), (yyvsp[(3) - (3)].c));
    ;}
    break;

  case 602:
#line 6310 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c), (yyvsp[(5) - (5)].c));
    ;}
    break;

  case 603:
#line 6314 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String(nullptr, (yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].c), (int)(yyvsp[(5) - (6)].d));
    ;}
    break;

  case 604:
#line 6318 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(1) - (8)].c), (yyvsp[(3) - (8)].c), (yyvsp[(5) - (8)].c), (int)(yyvsp[(7) - (8)].d));
    ;}
    break;

  case 605:
#line 6322 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 606:
#line 6330 "Gmsh.y"
    {
      std::string name = GModel::current()->getElementaryName((yyvsp[(1) - (4)].i), (int)(yyvsp[(3) - (4)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 607:
#line 6336 "Gmsh.y"
    {
      std::string name = GModel::current()->getPhysicalName((yyvsp[(2) - (5)].i), (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 608:
#line 6345 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 609:
#line 6349 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 610:
#line 6353 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    ;}
    break;

  case 611:
#line 6361 "Gmsh.y"
    {
      std::string exe = Msg::GetExecutableName();
      (yyval.c) = (char *)Malloc(exe.size() + 1);
      strcpy((yyval.c), exe.c_str());
    ;}
    break;

  case 612:
#line 6367 "Gmsh.y"
    {
      std::string action = Msg::GetOnelabAction();
      (yyval.c) = (char *)Malloc(action.size() + 1);
      strcpy((yyval.c), action.c_str());
    ;}
    break;

  case 613:
#line 6373 "Gmsh.y"
    {
      (yyval.c) = strsave((char*)"Gmsh");
    ;}
    break;

  case 614:
#line 6377 "Gmsh.y"
    {
      std::string env = GetEnvironmentVar((yyvsp[(3) - (4)].c));
      (yyval.c) = (char *)Malloc((env.size() + 1) * sizeof(char));
      strcpy((yyval.c), env.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 615:
#line 6384 "Gmsh.y"
    {
      std::string s = Msg::GetString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 616:
#line 6392 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (4)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 617:
#line 6399 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 618:
#line 6408 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_String(nullptr, (yyvsp[(3) - (5)].c2).char2, 1, 0, (yyvsp[(4) - (5)].c), 2);
    ;}
    break;

  case 619:
#line 6412 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(3) - (7)].c2).char1, (yyvsp[(3) - (7)].c2).char2, (yyvsp[(5) - (7)].c), 0, (yyvsp[(6) - (7)].c), 2);
    ;}
    break;

  case 620:
#line 6416 "Gmsh.y"
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

  case 621:
#line 6431 "Gmsh.y"
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

  case 622:
#line 6445 "Gmsh.y"
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

  case 623:
#line 6459 "Gmsh.y"
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

  case 624:
#line 6471 "Gmsh.y"
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

  case 625:
#line 6487 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = toupper((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 626:
#line 6496 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = tolower((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 627:
#line 6505 "Gmsh.y"
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

  case 628:
#line 6515 "Gmsh.y"
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

  case 629:
#line 6526 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (8)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (8)].d), (int)(yyvsp[(7) - (8)].d));
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (8)].c));
    ;}
    break;

  case 630:
#line 6534 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (6)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (6)].d), std::string::npos);
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 631:
#line 6542 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 632:
#line 6546 "Gmsh.y"
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

  case 633:
#line 6564 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 634:
#line 6571 "Gmsh.y"
    {
      std::string tmp = SplitFileName(GetAbsolutePath(gmsh_yyname))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
    ;}
    break;

  case 635:
#line 6577 "Gmsh.y"
    {
      std::string tmp = GetFileNameWithoutPath(gmsh_yyname);
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
    ;}
    break;

  case 636:
#line 6583 "Gmsh.y"
    {
      std::string tmp = SplitFileName((yyvsp[(3) - (4)].c))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 637:
#line 6590 "Gmsh.y"
    {
      std::string tmp = GetAbsolutePath((yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 638:
#line 6597 "Gmsh.y"
    { init_options(); ;}
    break;

  case 639:
#line 6599 "Gmsh.y"
    {
      std::string val((yyvsp[(3) - (6)].c));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.c) = (char*)Malloc((val.size() + 1) * sizeof(char));
      strcpy((yyval.c), val.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 640:
#line 6607 "Gmsh.y"
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

  case 641:
#line 6631 "Gmsh.y"
    { struct_namespace = std::string(""); (yyval.d) = (yyvsp[(2) - (2)].d); ;}
    break;

  case 642:
#line 6633 "Gmsh.y"
    { struct_namespace = (yyvsp[(1) - (4)].c); Free((yyvsp[(1) - (4)].c)); (yyval.d) = (yyvsp[(4) - (4)].d); ;}
    break;

  case 643:
#line 6639 "Gmsh.y"
    { (yyval.l) = (yyvsp[(3) - (4)].l); ;}
    break;

  case 644:
#line 6644 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 645:
#line 6646 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 646:
#line 6651 "Gmsh.y"
    { (yyval.l) = (yyvsp[(2) - (3)].l); ;}
    break;

  case 647:
#line 6656 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].c)));
    ;}
    break;

  case 648:
#line 6661 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 649:
#line 6663 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].c)));
    ;}
    break;

  case 650:
#line 6667 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	char* c;
	List_Read((yyvsp[(3) - (3)].l), i, &c);
	List_Add((yyval.l), &c);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 651:
#line 6679 "Gmsh.y"
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

  case 652:
#line 6693 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfString(nullptr, (yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c));
    ;}
    break;

  case 653:
#line 6697 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfString((yyvsp[(1) - (7)].c), (yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].c));
    ;}
    break;

  case 654:
#line 6704 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr) + 1) * sizeof(char));
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 655:
#line 6712 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr) + 1) * sizeof(char)) ;
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)) ; strcat((yyval.c), tmpstr) ;
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 656:
#line 6720 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(7) - (8)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(3) - (8)].c))+strlen(tmpstr) + 1) * sizeof(char));
      strcpy((yyval.c), (yyvsp[(3) - (8)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(3) - (8)].c));
    ;}
    break;

  case 657:
#line 6731 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 658:
#line 6733 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 659:
#line 6736 "Gmsh.y"
    { (yyval.c) = (yyvsp[(3) - (4)].c); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 15192 "Gmsh.tab.cpp"
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


#line 6739 "Gmsh.y"


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

