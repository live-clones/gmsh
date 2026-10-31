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
     tIntersect = 428,
     tMeshAlgorithm = 429,
     tReverseMesh = 430,
     tMeshSize = 431,
     tMeshSizeFromBoundary = 432,
     tLayers = 433,
     tScaleLast = 434,
     tHole = 435,
     tAlias = 436,
     tAliasWithOptions = 437,
     tCopyOptions = 438,
     tQuadTriAddVerts = 439,
     tQuadTriNoNewVerts = 440,
     tRecombLaterals = 441,
     tTransfQuadTri = 442,
     tText2D = 443,
     tText3D = 444,
     tInterpolationScheme = 445,
     tTime = 446,
     tCombine = 447,
     tBSpline = 448,
     tBezier = 449,
     tNurbs = 450,
     tNurbsOrder = 451,
     tNurbsKnots = 452,
     tColor = 453,
     tColorTable = 454,
     tFor = 455,
     tIn = 456,
     tEndFor = 457,
     tIf = 458,
     tElseIf = 459,
     tElse = 460,
     tEndIf = 461,
     tExit = 462,
     tAbort = 463,
     tField = 464,
     tReturn = 465,
     tCall = 466,
     tSlide = 467,
     tMacro = 468,
     tShow = 469,
     tHide = 470,
     tGetValue = 471,
     tGetStringValue = 472,
     tGetEnv = 473,
     tGetString = 474,
     tGetNumber = 475,
     tUnique = 476,
     tSetMaxTag = 477,
     tHomology = 478,
     tCohomology = 479,
     tBetti = 480,
     tExists = 481,
     tFileExists = 482,
     tGetForced = 483,
     tGetForcedStr = 484,
     tGMSH_MAJOR_VERSION = 485,
     tGMSH_MINOR_VERSION = 486,
     tGMSH_PATCH_VERSION = 487,
     tGmshExecutableName = 488,
     tSetPartition = 489,
     tNameToString = 490,
     tStringToName = 491,
     tUnsplitWindow = 492,
     tAFFECTDIVIDE = 493,
     tAFFECTTIMES = 494,
     tAFFECTMINUS = 495,
     tAFFECTPLUS = 496,
     tOR = 497,
     tAND = 498,
     tNOTEQUAL = 499,
     tEQUAL = 500,
     tGREATERGREATER = 501,
     tLESSLESS = 502,
     tGREATEROREQUAL = 503,
     tLESSOREQUAL = 504,
     UNARYPREC = 505,
     tMINUSMINUS = 506,
     tPLUSPLUS = 507
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
#define tIntersect 428
#define tMeshAlgorithm 429
#define tReverseMesh 430
#define tMeshSize 431
#define tMeshSizeFromBoundary 432
#define tLayers 433
#define tScaleLast 434
#define tHole 435
#define tAlias 436
#define tAliasWithOptions 437
#define tCopyOptions 438
#define tQuadTriAddVerts 439
#define tQuadTriNoNewVerts 440
#define tRecombLaterals 441
#define tTransfQuadTri 442
#define tText2D 443
#define tText3D 444
#define tInterpolationScheme 445
#define tTime 446
#define tCombine 447
#define tBSpline 448
#define tBezier 449
#define tNurbs 450
#define tNurbsOrder 451
#define tNurbsKnots 452
#define tColor 453
#define tColorTable 454
#define tFor 455
#define tIn 456
#define tEndFor 457
#define tIf 458
#define tElseIf 459
#define tElse 460
#define tEndIf 461
#define tExit 462
#define tAbort 463
#define tField 464
#define tReturn 465
#define tCall 466
#define tSlide 467
#define tMacro 468
#define tShow 469
#define tHide 470
#define tGetValue 471
#define tGetStringValue 472
#define tGetEnv 473
#define tGetString 474
#define tGetNumber 475
#define tUnique 476
#define tSetMaxTag 477
#define tHomology 478
#define tCohomology 479
#define tBetti 480
#define tExists 481
#define tFileExists 482
#define tGetForced 483
#define tGetForcedStr 484
#define tGMSH_MAJOR_VERSION 485
#define tGMSH_MINOR_VERSION 486
#define tGMSH_PATCH_VERSION 487
#define tGmshExecutableName 488
#define tSetPartition 489
#define tNameToString 490
#define tStringToName 491
#define tUnsplitWindow 492
#define tAFFECTDIVIDE 493
#define tAFFECTTIMES 494
#define tAFFECTMINUS 495
#define tAFFECTPLUS 496
#define tOR 497
#define tAND 498
#define tNOTEQUAL 499
#define tEQUAL 500
#define tGREATERGREATER 501
#define tLESSLESS 502
#define tGREATEROREQUAL 503
#define tLESSOREQUAL 504
#define UNARYPREC 505
#define tMINUSMINUS 506
#define tPLUSPLUS 507




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
#line 176 "Gmsh.y"
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
#line 794 "Gmsh.tab.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 807 "Gmsh.tab.cpp"

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
#define YYLAST   18278

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  275
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  115
/* YYNRULES -- Number of rules.  */
#define YYNRULES  650
/* YYNRULES -- Number of states.  */
#define YYNSTATES  2261

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   507

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint16 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   260,     2,   272,     2,   257,   259,     2,
     265,   266,   255,   253,   274,   254,   271,   256,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     247,     2,   248,   242,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   267,     2,   268,   264,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   269,   258,   270,   273,     2,     2,     2,
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
     235,   236,   237,   238,   239,   240,   241,   243,   244,   245,
     246,   249,   250,   251,   252,   261,   262,   263
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
    1848,  1857,  1868,  1883,  1884,  1888,  1889,  1891,  1892,  1895,
    1896,  1899,  1900,  1903,  1909,  1916,  1924,  1931,  1937,  1941,
    1950,  1957,  1966,  1975,  1981,  1986,  1993,  2005,  2017,  2036,
    2055,  2068,  2081,  2094,  2105,  2110,  2115,  2120,  2125,  2130,
    2137,  2140,  2144,  2151,  2154,  2156,  2158,  2160,  2163,  2169,
    2177,  2188,  2190,  2194,  2197,  2200,  2203,  2207,  2211,  2215,
    2219,  2223,  2227,  2231,  2235,  2239,  2243,  2247,  2251,  2255,
    2259,  2263,  2267,  2271,  2275,  2281,  2286,  2291,  2296,  2301,
    2306,  2311,  2316,  2321,  2326,  2331,  2336,  2343,  2348,  2353,
    2358,  2363,  2368,  2373,  2378,  2383,  2390,  2397,  2404,  2409,
    2416,  2423,  2425,  2427,  2429,  2431,  2433,  2435,  2437,  2439,
    2441,  2443,  2445,  2446,  2453,  2455,  2460,  2467,  2469,  2474,
    2479,  2484,  2491,  2497,  2505,  2514,  2525,  2530,  2535,  2542,
    2547,  2551,  2554,  2560,  2566,  2570,  2576,  2583,  2592,  2599,
    2608,  2615,  2620,  2628,  2635,  2642,  2649,  2654,  2661,  2666,
    2667,  2670,  2671,  2674,  2675,  2683,  2685,  2689,  2691,  2694,
    2695,  2699,  2701,  2704,  2707,  2711,  2715,  2727,  2737,  2745,
    2753,  2755,  2759,  2761,  2763,  2766,  2770,  2775,  2781,  2784,
    2788,  2793,  2795,  2799,  2801,  2804,  2808,  2812,  2818,  2823,
    2828,  2831,  2836,  2839,  2843,  2849,  2853,  2858,  2864,  2870,
    2876,  2882,  2889,  2901,  2913,  2923,  2934,  2940,  2942,  2944,
    2946,  2950,  2956,  2964,  2969,  2974,  2979,  2986,  2993,  3002,
    3011,  3016,  3031,  3036,  3041,  3043,  3045,  3049,  3053,  3055,
    3059,  3069,  3077,  3079,  3085,  3089,  3096,  3098,  3102,  3104,
    3106,  3111,  3116,  3120,  3126,  3133,  3142,  3149,  3154,  3160,
    3162,  3167,  3169,  3171,  3173,  3175,  3180,  3187,  3192,  3199,
    3205,  3213,  3218,  3223,  3228,  3237,  3242,  3247,  3252,  3257,
    3266,  3275,  3282,  3287,  3294,  3299,  3301,  3303,  3308,  3313,
    3314,  3321,  3326,  3329,  3334,  3339,  3341,  3343,  3347,  3349,
    3351,  3355,  3359,  3363,  3369,  3377,  3383,  3389,  3398,  3400,
    3402
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     276,     0,    -1,   277,    -1,     1,     6,    -1,    -1,   277,
     278,    -1,   280,    -1,   281,    -1,   302,    -1,   137,   265,
     379,   266,     6,    -1,   321,    -1,   327,    -1,   330,    -1,
     331,    -1,   332,    -1,   333,    -1,   337,    -1,   346,    -1,
     347,    -1,   353,    -1,   354,    -1,   336,    -1,   335,    -1,
     334,    -1,   356,    -1,   248,    -1,   249,    -1,    47,   265,
     379,   266,     6,    -1,    49,   265,   379,   266,     6,    -1,
      48,   265,   379,   266,     6,    -1,    47,   265,   379,   266,
     279,   379,     6,    -1,    47,   265,   379,   274,   374,   266,
       6,    -1,    49,   265,   379,   274,   374,   266,     6,    -1,
      48,   265,   379,   274,   374,   266,     6,    -1,    47,   265,
     379,   274,   374,   266,   279,   379,     6,    -1,   389,   379,
     269,   282,   270,     6,    -1,   181,     4,   267,   357,   268,
       6,    -1,   182,     4,   267,   357,   268,     6,    -1,   183,
       4,   267,   357,   274,   357,   268,     6,    -1,    -1,   282,
     285,    -1,   282,   289,    -1,   282,   292,    -1,   282,   294,
      -1,   282,   295,    -1,   282,   336,    -1,   357,    -1,   283,
     274,   357,    -1,   357,    -1,   284,   274,   357,    -1,    -1,
      -1,     4,   286,   265,   283,   266,   287,   269,   284,   270,
       6,    -1,   379,    -1,   288,   274,   379,    -1,    -1,   188,
     265,   357,   274,   357,   274,   357,   266,   290,   269,   288,
     270,     6,    -1,   379,    -1,   291,   274,   379,    -1,    -1,
     189,   265,   357,   274,   357,   274,   357,   274,   357,   266,
     293,   269,   291,   270,     6,    -1,   190,   269,   369,   270,
     269,   369,   270,     6,    -1,   190,   269,   369,   270,   269,
     369,   270,   269,   369,   270,   269,   369,   270,     6,    -1,
      -1,   191,   296,   269,   284,   270,     6,    -1,     7,    -1,
     241,    -1,   240,    -1,   239,    -1,   238,    -1,   263,    -1,
     262,    -1,   265,    -1,   267,    -1,   266,    -1,   268,    -1,
       4,    -1,    37,    -1,    38,    -1,    26,    -1,   114,    -1,
     115,    -1,    94,   267,   304,   268,     6,    -1,    95,   267,
     308,   268,     6,    -1,   362,     6,    -1,   102,   299,   380,
     274,   357,   300,     6,    -1,   104,   299,   380,   274,   380,
     300,     6,    -1,   389,   297,   370,     6,    -1,   389,   298,
       6,    -1,   389,   299,   300,   297,   370,     6,    -1,   389,
     299,   269,   374,   270,   300,   297,   370,     6,    -1,   389,
     267,   357,   268,   297,   357,     6,    -1,   389,   267,   357,
     268,   298,     6,    -1,   389,   265,   357,   266,   297,   357,
       6,    -1,   389,   265,   357,   266,   298,     6,    -1,   389,
       7,   380,     6,    -1,   389,   299,   300,     7,    50,   299,
     300,     6,    -1,   389,   299,   300,     7,    50,   299,   384,
     300,     6,    -1,   389,   299,   300,   241,    50,   299,   384,
     300,     6,    -1,   389,   271,   301,     7,   380,     6,    -1,
     389,   267,   357,   268,   271,   301,     7,   380,     6,    -1,
     389,   271,   301,   297,   357,     6,    -1,   389,   267,   357,
     268,   271,   301,   297,   357,     6,    -1,   389,   271,   301,
     298,     6,    -1,   389,   267,   357,   268,   271,   301,   298,
       6,    -1,   389,   271,   198,   271,   301,     7,   376,     6,
      -1,   389,   267,   357,   268,   271,   198,   271,   301,     7,
     376,     6,    -1,   389,   271,   199,     7,   377,     6,    -1,
     389,   267,   357,   268,   271,   199,     7,   377,     6,    -1,
     389,   209,     7,   370,     6,    -1,   209,   267,   357,   268,
       7,   301,     6,    -1,   209,   267,   357,   268,   271,   301,
       7,   357,     6,    -1,   209,   267,   357,   268,   271,   301,
       7,   380,     6,    -1,   209,   267,   357,   268,   271,   301,
       7,   371,     6,    -1,   209,   267,   357,   268,   271,   301,
       6,    -1,   150,   265,     4,   266,   271,   301,     7,   357,
       6,    -1,   150,   265,     4,   266,   271,   301,     7,   380,
       6,    -1,    -1,   274,    -1,    -1,   304,   303,   389,    -1,
     304,   303,   389,     7,   357,    -1,    -1,   304,   303,   389,
       7,   269,   370,   305,   310,   270,    -1,    -1,   304,   303,
     389,   299,   300,     7,   269,   370,   306,   310,   270,    -1,
     304,   303,   389,     7,   380,    -1,    -1,   304,   303,   389,
       7,   269,   380,   307,   314,   270,    -1,    -1,   308,   303,
     379,    -1,   357,     7,   380,    -1,   309,   274,   357,     7,
     380,    -1,   373,     7,   389,   265,   266,    -1,    -1,   274,
     312,    -1,    -1,   312,    -1,   313,    -1,   312,   274,   313,
      -1,     4,   370,    -1,    37,   357,    -1,    38,   357,    -1,
      26,   357,    -1,     4,    -1,     4,   269,   309,   270,    -1,
       4,   380,    -1,     4,   383,    -1,    -1,   274,   315,    -1,
     316,    -1,   315,   274,   316,    -1,     4,   357,    -1,     4,
     380,    -1,   213,   380,    -1,     4,   385,    -1,     4,   383,
      -1,   357,    -1,   380,    -1,   380,   274,   357,    -1,    -1,
     201,   109,   269,   357,   270,    -1,   149,   105,   269,   374,
     270,    -1,   149,   124,   269,   374,   270,    -1,    -1,   142,
     367,    -1,    -1,   149,   153,    -1,   105,   265,   357,   266,
       7,   367,     6,    -1,   108,   265,   357,   266,     7,   370,
       6,    -1,   112,   265,   357,   266,     7,   370,     6,    -1,
     146,   112,   265,   357,   266,     7,   370,   149,   357,     6,
      -1,   146,   193,   265,   357,   266,     7,   370,   149,   357,
       6,    -1,   106,   265,   357,   266,     7,   370,   319,     6,
      -1,   107,   265,   357,   266,     7,   370,   319,     6,    -1,
     193,   265,   357,   266,     7,   370,     6,    -1,   194,   265,
     357,   266,     7,   370,     6,    -1,   195,   265,   357,   266,
       7,   370,   197,   370,   196,   357,     6,    -1,   123,   265,
     357,   266,     7,   370,     6,    -1,   108,     4,   265,   357,
     266,     7,   370,     6,    -1,   142,   111,   265,   357,   266,
       7,   370,     6,    -1,   111,   265,   357,   266,     7,   370,
     318,     6,    -1,   143,   111,   265,   357,   266,     7,   370,
     318,     6,    -1,   193,   111,   265,   357,   266,     7,   370,
       6,    -1,   194,   111,   265,   357,   266,     7,   370,     6,
      -1,    13,    14,     6,    -1,    14,   111,   357,     6,    -1,
     129,   111,   265,   357,   266,     7,     5,     5,     5,     6,
      -1,   109,   265,   357,   266,     7,   370,     6,    -1,   110,
     265,   357,   266,     7,   370,     6,    -1,   114,   265,   357,
     266,     7,   370,     6,    -1,   117,   265,   357,   266,     7,
     370,     6,    -1,   121,   265,   357,   266,     7,   370,     6,
      -1,   122,   265,   357,   266,     7,   370,     6,    -1,   115,
     265,   357,   266,     7,   370,     6,    -1,   116,   265,   357,
     266,     7,   370,     6,    -1,   139,   265,   357,   266,     7,
     370,     6,    -1,   166,   265,   357,   266,     7,   370,     6,
      -1,   111,     4,   265,   357,   266,     7,   370,   320,     6,
      -1,   113,   265,   357,   266,     7,   370,     6,    -1,   138,
     265,   357,   266,     7,   370,     6,    -1,   143,   138,   265,
     357,   266,     7,   370,     6,    -1,   146,   324,   265,   357,
     266,     7,   370,     6,    -1,   146,   324,   265,   357,   266,
       7,   370,     4,   269,   369,   270,     6,    -1,    -1,   145,
     323,   322,   265,   317,   266,   297,   370,     6,    -1,   105,
      -1,   108,    -1,   111,    -1,   113,    -1,   124,   269,   357,
     270,    -1,   108,    -1,   111,    -1,   113,    -1,   124,   269,
     357,   270,    -1,   108,    -1,   111,    -1,   124,   269,   357,
     270,    -1,   105,    -1,   108,    -1,   111,    -1,   124,   269,
     357,   270,    -1,   155,   367,   269,   328,   270,    -1,   154,
     269,   367,   274,   367,   274,   357,   270,   269,   328,   270,
      -1,   156,   367,   269,   328,   270,    -1,   157,   269,   367,
     274,   357,   270,   269,   328,   270,    -1,   157,   269,   367,
     274,   367,   270,   269,   328,   270,    -1,   159,   269,   374,
     270,   269,   328,   270,    -1,   160,   269,   374,   270,   269,
     328,   270,    -1,     4,   269,   328,   270,    -1,   173,   108,
     269,   374,   270,   111,   269,   357,   270,    -1,   169,   108,
     269,   357,   270,   105,   269,   374,   270,     6,    -1,   169,
     108,   265,   357,   266,   269,   374,   270,     6,    -1,   329,
      -1,   327,    -1,    -1,   329,   321,    -1,   329,   323,   269,
     374,   270,     6,    -1,   329,   145,   323,   269,   374,   270,
       6,    -1,   329,   145,   323,   269,   375,   270,     6,    -1,
     329,   148,   323,   269,   374,   270,     6,    -1,   329,   323,
     269,     8,   270,     6,    -1,   329,   145,   323,   269,     8,
     270,     6,    -1,   170,   269,   329,   270,    -1,   152,   170,
     269,   329,   270,    -1,   170,     4,   269,   329,   270,    -1,
     170,   209,   267,   357,   268,     6,    -1,   170,     4,   267,
     357,   268,     6,    -1,   170,   389,     6,    -1,   170,     4,
       4,     6,    -1,   170,    97,     6,    -1,   198,   376,   269,
     329,   270,    -1,   152,   198,   376,   269,   329,   270,    -1,
     234,   357,   269,   329,   270,    -1,   214,   269,     8,   270,
      -1,   214,     5,     6,    -1,   215,   269,     8,   270,    -1,
     215,     5,     6,    -1,   214,   269,   329,   270,    -1,   152,
     214,   269,   329,   270,    -1,   215,   269,   329,   270,    -1,
     152,   215,   269,   329,   270,    -1,   389,   380,     6,    -1,
      81,   265,   386,   266,     6,    -1,   389,   389,   267,   357,
     268,   379,     6,    -1,   389,   389,   389,   267,   357,   268,
       6,    -1,   389,   357,     6,    -1,   237,     6,    -1,   150,
     265,     4,   266,   271,     4,     6,    -1,   192,     4,     6,
      -1,   207,     6,    -1,   207,   357,     6,    -1,   208,     6,
      -1,    75,     6,    -1,    76,     6,    -1,    68,     6,    -1,
      68,   269,   357,   274,   357,   274,   357,   274,   357,   274,
     357,   274,   357,   270,     6,    -1,    69,     6,    -1,    70,
       6,    -1,    86,   269,   357,   274,   357,   270,     6,    -1,
      86,     6,    -1,    88,   269,   357,   274,   357,   274,   357,
     270,     6,    -1,    88,   269,   357,   274,   357,   274,   357,
     274,   357,   270,     6,    -1,    87,     6,    -1,    87,   269,
     329,   270,    -1,    89,     6,    -1,    90,     6,    -1,    91,
       6,    -1,    92,     6,    -1,   131,     6,    -1,   132,     6,
      -1,   134,   269,   374,   270,     6,    -1,   134,   269,   374,
     270,   269,   328,   270,     6,    -1,   212,   265,   269,   374,
     270,   274,   380,   274,   380,   266,     6,    -1,   200,   265,
     357,     8,   357,   266,    -1,   200,   265,   357,     8,   357,
       8,   357,   266,    -1,   200,     4,   201,   269,   357,     8,
     357,   270,    -1,   200,     4,   201,   269,   357,     8,   357,
       8,   357,   270,    -1,   202,    -1,   213,     4,    -1,   213,
     380,    -1,   210,    -1,   211,   389,     6,    -1,   211,   380,
       6,    -1,   203,   265,   357,   266,    -1,   204,   265,   357,
     266,    -1,   205,    -1,   206,    -1,   158,   367,   269,   329,
     270,    -1,   158,   269,   367,   274,   367,   274,   357,   270,
     269,   329,   270,    -1,   158,   269,   367,   274,   367,   274,
     367,   274,   357,   270,   269,   329,   270,    -1,    -1,   158,
     367,   269,   329,   338,   342,   270,    -1,    -1,   158,   269,
     367,   274,   367,   274,   357,   270,   269,   329,   339,   342,
     270,    -1,    -1,   158,   269,   367,   274,   367,   274,   367,
     274,   357,   270,   269,   329,   340,   342,   270,    -1,    -1,
     158,   269,   329,   341,   342,   270,    -1,   158,   269,   329,
     270,   149,   123,   269,   357,   270,    -1,   138,   370,    -1,
     143,   138,   370,    -1,   140,   269,   374,   270,   269,   374,
     270,   269,   374,   270,    -1,   141,   269,   374,   270,   269,
     374,   270,   269,   374,   270,   269,   374,   270,    -1,   343,
      -1,   342,   343,    -1,   178,   269,   357,   270,     6,    -1,
     178,   269,   370,   274,   370,   270,     6,    -1,   179,     6,
      -1,   167,     6,    -1,   167,   357,     6,    -1,   184,     6,
      -1,   184,   186,     6,    -1,   185,     6,    -1,   185,   186,
       6,    -1,   180,   265,   357,   266,     7,   370,   149,   357,
       6,    -1,   149,     4,   267,   357,   268,     6,    -1,   161,
      -1,   162,    -1,   163,    -1,   164,    -1,   165,    -1,    -1,
     170,     6,    -1,   152,   170,     6,    -1,   170,   357,     6,
      -1,   152,   170,   357,     6,    -1,   344,   269,   329,   345,
     270,   269,   329,   345,   270,    -1,   120,   265,   379,   266,
      -1,   120,   265,   379,   274,   357,   266,    -1,   120,   265,
     379,   274,   357,   274,   357,   266,    -1,   120,   265,   379,
     274,   357,   274,   357,   274,   357,   266,    -1,   344,   265,
     357,   266,     7,   269,   329,   345,   270,   269,   329,   345,
     270,     6,    -1,    -1,   149,     4,   357,    -1,    -1,     4,
      -1,    -1,     7,   370,    -1,    -1,     7,   357,    -1,    -1,
     159,   370,    -1,   176,   372,     7,   357,     6,    -1,   127,
     128,   372,     7,   357,     6,    -1,   144,   108,   372,     7,
     357,   348,     6,    -1,   144,   111,   372,   350,   349,     6,
      -1,   144,   113,   372,   350,     6,    -1,   187,   372,     6,
      -1,   103,   323,   265,   357,   274,   357,   266,     6,    -1,
     222,   323,   265,   357,   266,     6,    -1,   174,   111,   269,
     374,   270,     7,   357,     6,    -1,   177,   111,   269,   374,
     270,     7,   357,     6,    -1,   167,   111,   372,   351,     6,
      -1,   167,   113,   372,     6,    -1,   168,   111,   372,     7,
     357,     6,    -1,   147,   108,   269,   374,   270,     7,   269,
     374,   270,   352,     6,    -1,   147,   111,   269,   374,   270,
       7,   269,   374,   270,   352,     6,    -1,   147,   108,   269,
     374,   270,     7,   269,   374,   270,   154,   269,   367,   274,
     367,   274,   357,   270,     6,    -1,   147,   111,   269,   374,
     270,     7,   269,   374,   270,   154,   269,   367,   274,   367,
     274,   357,   270,     6,    -1,   147,   108,   269,   374,   270,
       7,   269,   374,   270,   155,   367,     6,    -1,   147,   111,
     269,   374,   270,     7,   269,   374,   270,   155,   367,     6,
      -1,   147,   111,   357,   269,   374,   270,     7,   357,   269,
     374,   270,     6,    -1,   323,   269,   374,   270,   201,   323,
     269,   357,   270,     6,    -1,   175,   325,   372,     6,    -1,
     135,   326,   372,     6,    -1,   136,   113,   370,     6,    -1,
     151,   108,   370,     6,    -1,   146,   324,   370,     6,    -1,
     146,   324,   370,   174,   357,     6,    -1,   171,     6,    -1,
     171,     4,     6,    -1,   171,   105,   269,   374,   270,     6,
      -1,   172,     6,    -1,   223,    -1,   224,    -1,   225,    -1,
     355,     6,    -1,   355,   269,   370,   270,     6,    -1,   355,
     269,   370,   274,   370,   270,     6,    -1,   355,   265,   370,
     266,   269,   370,   274,   370,   270,     6,    -1,   358,    -1,
     265,   357,   266,    -1,   254,   357,    -1,   253,   357,    -1,
     260,   357,    -1,   357,   254,   357,    -1,   357,   253,   357,
      -1,   357,   255,   357,    -1,   357,   256,   357,    -1,   357,
     258,   357,    -1,   357,   259,   357,    -1,   357,   257,   357,
      -1,   357,   264,   357,    -1,   357,   247,   357,    -1,   357,
     248,   357,    -1,   357,   252,   357,    -1,   357,   251,   357,
      -1,   357,   246,   357,    -1,   357,   245,   357,    -1,   357,
     244,   357,    -1,   357,   243,   357,    -1,   357,   249,   357,
      -1,   357,   250,   357,    -1,   357,   242,   357,     8,   357,
      -1,    26,   299,   357,   300,    -1,    16,   299,   357,   300,
      -1,    17,   299,   357,   300,    -1,    18,   299,   357,   300,
      -1,    19,   299,   357,   300,    -1,    20,   299,   357,   300,
      -1,    21,   299,   357,   300,    -1,    22,   299,   357,   300,
      -1,    23,   299,   357,   300,    -1,    24,   299,   357,   300,
      -1,    27,   299,   357,   300,    -1,    28,   299,   357,   274,
     357,   300,    -1,    29,   299,   357,   300,    -1,    30,   299,
     357,   300,    -1,    31,   299,   357,   300,    -1,    32,   299,
     357,   300,    -1,    33,   299,   357,   300,    -1,    34,   299,
     357,   300,    -1,    35,   299,   357,   300,    -1,    36,   299,
     357,   300,    -1,    39,   299,   357,   274,   357,   300,    -1,
      40,   299,   357,   274,   357,   300,    -1,    41,   299,   357,
     274,   357,   300,    -1,    25,   299,   357,   300,    -1,    38,
     299,   357,   274,   357,   300,    -1,    37,   299,   357,   274,
     357,   300,    -1,     3,    -1,    10,    -1,    15,    -1,    11,
      -1,    12,    -1,   230,    -1,   231,    -1,   232,    -1,    83,
      -1,    84,    -1,    85,    -1,    -1,    96,   299,   357,   359,
     310,   300,    -1,   362,    -1,   220,   299,   379,   300,    -1,
     220,   299,   379,   274,   357,   300,    -1,   364,    -1,   389,
     267,   357,   268,    -1,   389,   265,   357,   266,    -1,   226,
     265,   364,   266,    -1,   226,   265,   364,   271,   301,   266,
      -1,   228,   265,   364,   360,   266,    -1,   228,   265,   364,
     271,   301,   360,   266,    -1,   228,   265,   364,   299,   357,
     300,   360,   266,    -1,   228,   265,   364,   271,   301,   299,
     357,   300,   360,   266,    -1,   227,   265,   380,   266,    -1,
     272,   389,   299,   300,    -1,   272,   364,   271,   301,   299,
     300,    -1,    99,   299,   389,   300,    -1,    99,   299,   300,
      -1,   389,   298,    -1,   389,   267,   357,   268,   298,    -1,
     389,   265,   357,   266,   298,    -1,   389,   271,   301,    -1,
     389,     9,   389,   271,   301,    -1,   389,   271,   301,   265,
     357,   266,    -1,   389,     9,   389,   271,   301,   265,   357,
     266,    -1,   389,   271,   301,   267,   357,   268,    -1,   389,
       9,   389,   271,   301,   267,   357,   268,    -1,   389,   267,
     357,   268,   271,   301,    -1,   389,   271,   301,   298,    -1,
     389,   267,   357,   268,   271,   301,   298,    -1,   216,   265,
     379,   274,   357,   266,    -1,    60,   265,   370,   274,   370,
     266,    -1,    61,   299,   379,   274,   379,   300,    -1,    59,
     299,   379,   300,    -1,    62,   299,   379,   274,   379,   300,
      -1,    67,   265,   386,   266,    -1,    -1,   274,   357,    -1,
      -1,   274,   379,    -1,    -1,    97,   364,   366,   363,   267,
     311,   268,    -1,   389,    -1,   389,     9,   389,    -1,   100,
      -1,   100,   357,    -1,    -1,   265,   365,   266,    -1,   368,
      -1,   254,   367,    -1,   253,   367,    -1,   367,   254,   367,
      -1,   367,   253,   367,    -1,   269,   357,   274,   357,   274,
     357,   274,   357,   274,   357,   270,    -1,   269,   357,   274,
     357,   274,   357,   274,   357,   270,    -1,   269,   357,   274,
     357,   274,   357,   270,    -1,   265,   357,   274,   357,   274,
     357,   266,    -1,   370,    -1,   369,   274,   370,    -1,   357,
      -1,   373,    -1,   269,   270,    -1,   269,   374,   270,    -1,
     254,   269,   374,   270,    -1,   357,   255,   269,   374,   270,
      -1,   269,   270,    -1,   269,   374,   270,    -1,   254,   269,
     374,   270,    -1,   370,    -1,   269,     8,   270,    -1,     5,
      -1,   254,   373,    -1,   357,   255,   373,    -1,   357,     8,
     357,    -1,   357,     8,   357,     8,   357,    -1,   105,   269,
     357,   270,    -1,   105,   269,     8,   270,    -1,   105,     5,
      -1,   324,   269,     8,   270,    -1,   324,     5,    -1,   145,
     323,   372,    -1,   145,   323,   269,   375,   270,    -1,   148,
     323,   370,    -1,   323,   201,    68,   370,    -1,    68,   323,
     269,   374,   270,    -1,    77,   324,   269,   357,   270,    -1,
      78,   324,   269,   357,   270,    -1,    79,   324,   269,   357,
     270,    -1,   129,    68,   325,   269,   357,   270,    -1,   125,
     111,   269,   357,   270,   129,   269,   357,   274,   357,   270,
      -1,   126,   111,   269,   357,   270,   129,   269,   357,   274,
     357,   270,    -1,   126,   108,   269,   357,   270,   129,   269,
     357,   270,    -1,   129,   105,   269,   357,   270,   201,   111,
     269,   357,   270,    -1,   198,   324,   269,   357,   270,    -1,
     327,    -1,   337,    -1,   346,    -1,   389,   299,   300,    -1,
     389,   271,   301,   299,   300,    -1,   389,     9,   389,   271,
     301,   299,   300,    -1,    42,   267,   389,   268,    -1,    42,
     267,   373,   268,    -1,    42,   265,   373,   266,    -1,    42,
     299,   269,   374,   270,   300,    -1,   389,   299,   269,   374,
     270,   300,    -1,    43,   299,   357,   274,   357,   274,   357,
     300,    -1,    44,   299,   357,   274,   357,   274,   357,   300,
      -1,    45,   299,   379,   300,    -1,    46,   299,   357,   274,
     357,   274,   357,   274,   357,   274,   357,   274,   357,   300,
      -1,   221,   299,   373,   300,    -1,    33,   299,   373,   300,
      -1,   357,    -1,   373,    -1,   374,   274,   357,    -1,   374,
     274,   373,    -1,   380,    -1,   375,   274,   380,    -1,   269,
     357,   274,   357,   274,   357,   274,   357,   270,    -1,   269,
     357,   274,   357,   274,   357,   270,    -1,   389,    -1,     4,
     271,   198,   271,     4,    -1,   269,   378,   270,    -1,   389,
     267,   357,   268,   271,   199,    -1,   376,    -1,   378,   274,
     376,    -1,   380,    -1,   389,    -1,   389,   267,   357,   268,
      -1,   389,   265,   357,   266,    -1,   389,   271,   301,    -1,
     389,     9,   389,   271,   301,    -1,   389,   271,   301,   265,
     357,   266,    -1,   389,     9,   389,   271,   301,   265,   357,
     266,    -1,   389,   267,   357,   268,   271,     4,    -1,   323,
     269,   357,   270,    -1,   145,   323,   269,   357,   270,    -1,
       5,    -1,   235,   267,   389,   268,    -1,    71,    -1,   233,
      -1,    80,    -1,    82,    -1,   218,   265,   379,   266,    -1,
     217,   265,   379,   274,   379,   266,    -1,   219,   299,   379,
     300,    -1,   219,   299,   379,   274,   379,   300,    -1,   229,
     265,   364,   361,   266,    -1,   229,   265,   364,   271,   301,
     361,   266,    -1,    52,   299,   386,   300,    -1,    53,   265,
     379,   266,    -1,    54,   265,   379,   266,    -1,    55,   265,
     379,   274,   379,   274,   379,   266,    -1,    50,   299,   386,
     300,    -1,    64,   299,   379,   300,    -1,    65,   299,   379,
     300,    -1,    66,   299,   379,   300,    -1,    63,   299,   357,
     274,   379,   274,   379,   300,    -1,    58,   299,   379,   274,
     357,   274,   357,   300,    -1,    58,   299,   379,   274,   357,
     300,    -1,    51,   299,   379,   300,    -1,    51,   299,   379,
     274,   374,   300,    -1,    72,   299,   379,   300,    -1,    73,
      -1,    74,    -1,    57,   299,   379,   300,    -1,    56,   299,
     379,   300,    -1,    -1,   101,   299,   380,   381,   314,   300,
      -1,    98,   299,   382,   300,    -1,   272,   357,    -1,   389,
       9,   272,   357,    -1,    50,   299,   385,   300,    -1,   386,
      -1,   385,    -1,   269,   386,   270,    -1,   379,    -1,   387,
      -1,   386,   274,   379,    -1,   386,   274,   387,    -1,   389,
     265,   266,    -1,   389,   271,   301,   265,   266,    -1,   389,
       9,   389,   271,   301,   265,   266,    -1,     4,   273,   269,
     357,   270,    -1,   388,   273,   269,   357,   270,    -1,   236,
     267,   379,   268,   273,   269,   357,   270,    -1,     4,    -1,
     388,    -1,   236,   267,   379,   268,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   283,   283,   284,   289,   291,   295,   296,   297,   298,
     332,   333,   334,   335,   336,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   350,   354,   361,   366,   371,
     376,   390,   403,   416,   429,   457,   471,   484,   497,   516,
     521,   522,   523,   524,   525,   526,   530,   532,   537,   539,
     545,   564,   544,   577,   582,   591,   590,   603,   608,   617,
     616,   629,   646,   669,   668,   686,   687,   688,   689,   690,
     694,   695,   701,   701,   703,   703,   708,   709,   710,   711,
     712,   713,   719,   720,   721,   722,   727,   733,   794,   809,
     837,   847,   852,   860,   865,   873,   882,   887,   899,   916,
     922,   931,   949,   967,   976,   988,   993,  1001,  1021,  1044,
    1064,  1072,  1089,  1107,  1145,  1166,  1178,  1192,  1192,  1194,
    1196,  1205,  1215,  1214,  1235,  1234,  1252,  1262,  1261,  1275,
    1277,  1285,  1291,  1296,  1323,  1325,  1328,  1330,  1334,  1335,
    1339,  1351,  1355,  1359,  1363,  1376,  1390,  1398,  1411,  1413,
    1417,  1418,  1423,  1431,  1440,  1448,  1462,  1480,  1484,  1495,
    1504,  1507,  1513,  1517,  1529,  1532,  1539,  1542,  1548,  1571,
    1587,  1603,  1620,  1637,  1674,  1718,  1734,  1750,  1782,  1798,
    1815,  1831,  1881,  1899,  1920,  1941,  1947,  1953,  1960,  2001,
    2016,  2048,  2082,  2115,  2150,  2185,  2220,  2244,  2270,  2287,
    2303,  2321,  2339,  2351,  2365,  2364,  2394,  2396,  2398,  2400,
    2402,  2410,  2412,  2414,  2416,  2424,  2426,  2428,  2436,  2438,
    2440,  2442,  2452,  2468,  2484,  2500,  2516,  2532,  2549,  2575,
    2618,  2639,  2660,  2686,  2687,  2692,  2695,  2699,  2716,  2736,
    2756,  2776,  2795,  2822,  2847,  2872,  2884,  2890,  2905,  2936,
    2948,  2957,  2964,  2976,  2996,  3000,  3005,  3009,  3014,  3021,
    3028,  3035,  3047,  3123,  3141,  3166,  3181,  3234,  3240,  3252,
    3284,  3288,  3292,  3297,  3305,  3310,  3321,  3326,  3332,  3340,
    3351,  3359,  3363,  3367,  3371,  3378,  3382,  3386,  3390,  3394,
    3407,  3417,  3437,  3463,  3479,  3496,  3513,  3535,  3557,  3592,
    3600,  3608,  3614,  3621,  3628,  3648,  3674,  3686,  3697,  3715,
    3733,  3752,  3751,  3776,  3775,  3802,  3801,  3826,  3825,  3848,
    3864,  3881,  3898,  3921,  3949,  3952,  3958,  3970,  3990,  3994,
    3998,  4002,  4006,  4010,  4014,  4018,  4027,  4040,  4041,  4042,
    4043,  4044,  4048,  4049,  4050,  4051,  4052,  4055,  4095,  4111,
    4117,  4123,  4132,  4170,  4173,  4201,  4204,  4221,  4224,  4230,
    4233,  4240,  4243,  4250,  4273,  4292,  4334,  4380,  4421,  4447,
    4454,  4465,  4483,  4501,  4532,  4559,  4586,  4618,  4646,  4672,
    4698,  4724,  4750,  4772,  4784,  4833,  4888,  4904,  4916,  4922,
    4934,  4941,  4956,  4965,  4986,  4987,  4988,  4992,  4998,  5010,
    5028,  5056,  5057,  5058,  5059,  5060,  5061,  5062,  5063,  5064,
    5071,  5072,  5073,  5074,  5075,  5076,  5077,  5078,  5079,  5080,
    5081,  5082,  5083,  5084,  5085,  5086,  5087,  5088,  5089,  5090,
    5091,  5092,  5093,  5094,  5095,  5096,  5097,  5098,  5099,  5100,
    5101,  5102,  5103,  5104,  5105,  5106,  5107,  5108,  5109,  5110,
    5111,  5120,  5121,  5122,  5123,  5124,  5125,  5126,  5127,  5128,
    5129,  5130,  5135,  5134,  5142,  5146,  5151,  5156,  5160,  5165,
    5170,  5174,  5178,  5182,  5186,  5190,  5194,  5200,  5215,  5219,
    5225,  5230,  5249,  5269,  5290,  5294,  5298,  5302,  5306,  5310,
    5314,  5319,  5329,  5339,  5344,  5355,  5364,  5369,  5374,  5402,
    5403,  5409,  5410,  5416,  5415,  5438,  5440,  5445,  5447,  5453,
    5454,  5459,  5463,  5467,  5471,  5475,  5482,  5486,  5490,  5494,
    5501,  5506,  5513,  5518,  5522,  5526,  5530,  5538,  5549,  5553,
    5557,  5568,  5572,  5576,  5590,  5598,  5606,  5613,  5623,  5646,
    5651,  5657,  5662,  5668,  5679,  5685,  5691,  5705,  5711,  5723,
    5737,  5750,  5781,  5805,  5826,  5846,  5867,  5884,  5894,  5904,
    5914,  5926,  5930,  5935,  5947,  5951,  5955,  5959,  5977,  5985,
    5993,  6022,  6032,  6048,  6059,  6064,  6068,  6072,  6084,  6089,
    6096,  6100,  6112,  6129,  6139,  6143,  6158,  6163,  6170,  6174,
    6179,  6193,  6207,  6211,  6215,  6219,  6223,  6231,  6237,  6246,
    6250,  6254,  6262,  6268,  6274,  6278,  6285,  6293,  6300,  6309,
    6313,  6317,  6332,  6346,  6360,  6372,  6388,  6397,  6406,  6416,
    6427,  6435,  6443,  6447,  6465,  6472,  6478,  6484,  6491,  6499,
    6498,  6508,  6532,  6534,  6540,  6545,  6547,  6552,  6557,  6562,
    6564,  6568,  6580,  6594,  6598,  6605,  6613,  6621,  6632,  6634,
    6637
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
  "tIntersect", "tMeshAlgorithm", "tReverseMesh", "tMeshSize",
  "tMeshSizeFromBoundary", "tLayers", "tScaleLast", "tHole", "tAlias",
  "tAliasWithOptions", "tCopyOptions", "tQuadTriAddVerts",
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
     495,   496,    63,   497,   498,   499,   500,    60,    62,   501,
     502,   503,   504,    43,    45,    42,    47,    37,   124,    38,
      33,   505,   506,   507,    94,    40,    41,    91,    93,   123,
     125,    46,    35,   126,    44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   275,   276,   276,   277,   277,   278,   278,   278,   278,
     278,   278,   278,   278,   278,   278,   278,   278,   278,   278,
     278,   278,   278,   278,   278,   279,   279,   280,   280,   280,
     280,   280,   280,   280,   280,   281,   281,   281,   281,   282,
     282,   282,   282,   282,   282,   282,   283,   283,   284,   284,
     286,   287,   285,   288,   288,   290,   289,   291,   291,   293,
     292,   294,   294,   296,   295,   297,   297,   297,   297,   297,
     298,   298,   299,   299,   300,   300,   301,   301,   301,   301,
     301,   301,   302,   302,   302,   302,   302,   302,   302,   302,
     302,   302,   302,   302,   302,   302,   302,   302,   302,   302,
     302,   302,   302,   302,   302,   302,   302,   302,   302,   302,
     302,   302,   302,   302,   302,   302,   302,   303,   303,   304,
     304,   304,   305,   304,   306,   304,   304,   307,   304,   308,
     308,   309,   309,   309,   310,   310,   311,   311,   312,   312,
     313,   313,   313,   313,   313,   313,   313,   313,   314,   314,
     315,   315,   316,   316,   316,   316,   316,   317,   317,   317,
     318,   318,   318,   318,   319,   319,   320,   320,   321,   321,
     321,   321,   321,   321,   321,   321,   321,   321,   321,   321,
     321,   321,   321,   321,   321,   321,   321,   321,   321,   321,
     321,   321,   321,   321,   321,   321,   321,   321,   321,   321,
     321,   321,   321,   321,   322,   321,   323,   323,   323,   323,
     323,   324,   324,   324,   324,   325,   325,   325,   326,   326,
     326,   326,   327,   327,   327,   327,   327,   327,   327,   327,
     327,   327,   327,   328,   328,   329,   329,   329,   329,   329,
     329,   329,   329,   330,   330,   330,   330,   330,   330,   330,
     330,   331,   331,   332,   333,   333,   333,   333,   333,   333,
     333,   333,   334,   334,   334,   334,   334,   334,   334,   334,
     334,   334,   334,   334,   334,   334,   334,   334,   334,   334,
     334,   334,   334,   334,   334,   334,   334,   334,   334,   334,
     334,   334,   334,   335,   336,   336,   336,   336,   336,   336,
     336,   336,   336,   336,   336,   336,   336,   336,   337,   337,
     337,   338,   337,   339,   337,   340,   337,   341,   337,   337,
     337,   337,   337,   337,   342,   342,   343,   343,   343,   343,
     343,   343,   343,   343,   343,   343,   343,   344,   344,   344,
     344,   344,   345,   345,   345,   345,   345,   346,   346,   346,
     346,   346,   347,   348,   348,   349,   349,   350,   350,   351,
     351,   352,   352,   353,   353,   353,   353,   353,   353,   353,
     353,   353,   353,   353,   353,   353,   353,   353,   353,   353,
     353,   353,   353,   353,   353,   353,   353,   353,   353,   353,
     354,   354,   354,   354,   355,   355,   355,   356,   356,   356,
     356,   357,   357,   357,   357,   357,   357,   357,   357,   357,
     357,   357,   357,   357,   357,   357,   357,   357,   357,   357,
     357,   357,   357,   357,   357,   357,   357,   357,   357,   357,
     357,   357,   357,   357,   357,   357,   357,   357,   357,   357,
     357,   357,   357,   357,   357,   357,   357,   357,   357,   357,
     357,   358,   358,   358,   358,   358,   358,   358,   358,   358,
     358,   358,   359,   358,   358,   358,   358,   358,   358,   358,
     358,   358,   358,   358,   358,   358,   358,   358,   358,   358,
     358,   358,   358,   358,   358,   358,   358,   358,   358,   358,
     358,   358,   358,   358,   358,   358,   358,   358,   358,   360,
     360,   361,   361,   363,   362,   364,   364,   365,   365,   366,
     366,   367,   367,   367,   367,   367,   368,   368,   368,   368,
     369,   369,   370,   370,   370,   370,   370,   370,   371,   371,
     371,   372,   372,   372,   373,   373,   373,   373,   373,   373,
     373,   373,   373,   373,   373,   373,   373,   373,   373,   373,
     373,   373,   373,   373,   373,   373,   373,   373,   373,   373,
     373,   373,   373,   373,   373,   373,   373,   373,   373,   373,
     373,   373,   373,   373,   374,   374,   374,   374,   375,   375,
     376,   376,   376,   376,   377,   377,   378,   378,   379,   379,
     379,   379,   379,   379,   379,   379,   379,   379,   379,   380,
     380,   380,   380,   380,   380,   380,   380,   380,   380,   380,
     380,   380,   380,   380,   380,   380,   380,   380,   380,   380,
     380,   380,   380,   380,   380,   380,   380,   380,   380,   381,
     380,   380,   382,   382,   383,   384,   384,   385,   386,   386,
     386,   386,   387,   387,   387,   388,   388,   388,   389,   389,
     389
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
       1,     1,     0,     2,     3,     3,     4,     9,     4,     6,
       8,    10,    14,     0,     3,     0,     1,     0,     2,     0,
       2,     0,     2,     5,     6,     7,     6,     5,     3,     8,
       6,     8,     8,     5,     4,     6,    11,    11,    18,    18,
      12,    12,    12,    10,     4,     4,     4,     4,     4,     6,
       2,     3,     6,     2,     1,     1,     1,     2,     5,     7,
      10,     1,     3,     2,     2,     2,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     5,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     6,     4,     4,     4,
       4,     4,     4,     4,     4,     6,     6,     6,     4,     6,
       6,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     6,     1,     4,     6,     1,     4,     4,
       4,     6,     5,     7,     8,    10,     4,     4,     6,     4,
       3,     2,     5,     5,     3,     5,     6,     8,     6,     8,
       6,     4,     7,     6,     6,     6,     4,     6,     4,     0,
       2,     0,     2,     0,     7,     1,     3,     1,     2,     0,
       3,     1,     2,     2,     3,     3,    11,     9,     7,     7,
       1,     3,     1,     1,     2,     3,     4,     5,     2,     3,
       4,     1,     3,     1,     2,     3,     3,     5,     4,     4,
       2,     4,     2,     3,     5,     3,     4,     5,     5,     5,
       5,     6,    11,    11,     9,    10,     5,     1,     1,     1,
       3,     5,     7,     4,     4,     4,     6,     6,     8,     8,
       4,    14,     4,     4,     1,     1,     3,     3,     1,     3,
       9,     7,     1,     5,     3,     6,     1,     3,     1,     1,
       4,     4,     3,     5,     6,     8,     6,     4,     5,     1,
       4,     1,     1,     1,     1,     4,     6,     4,     6,     5,
       7,     4,     4,     4,     8,     4,     4,     4,     4,     8,
       8,     6,     4,     6,     4,     1,     1,     4,     4,     0,
       6,     4,     2,     4,     4,     1,     1,     3,     1,     1,
       3,     3,     3,     5,     7,     5,     5,     8,     1,     1,
       4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     2,     3,     1,   648,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   206,     0,     0,   207,     0,     0,   208,     0,   209,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   337,   338,   339,
     340,   341,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   298,     0,     0,   306,   307,     0,
       0,     0,   301,     0,     0,     0,     0,     0,     0,   394,
     395,   396,     0,     0,     0,     5,     6,     7,     8,    10,
       0,    11,    12,    13,    14,    15,    23,    22,    21,    16,
       0,    17,    18,    19,    20,     0,    24,     0,   649,     0,
     235,     0,     0,     0,     0,     0,     0,   275,     0,   277,
     278,   273,   274,     0,   280,     0,   283,   235,     0,   285,
     286,   287,   288,   119,   129,   648,   509,   505,    72,    73,
       0,   206,   207,   208,   209,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   289,
     290,     0,   218,   219,   220,     0,     0,     0,     0,   451,
     452,   454,   455,   453,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   459,   460,   461,     0,     0,   206,
     211,   212,   213,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   456,   457,
     458,     0,     0,     0,     0,     0,     0,     0,     0,   557,
     558,     0,   559,   522,   401,   464,   467,   320,   523,   505,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   204,
     211,   212,     0,   213,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   511,     0,     0,   235,     0,     0,     0,     0,     0,
       0,     0,     0,   648,     0,     0,   235,     0,     0,   390,
       0,   393,     0,     0,   215,   216,     0,     0,   533,     0,
       0,   531,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   648,     0,     0,   582,     0,     0,
       0,     0,   270,     0,     0,     0,   505,   272,     0,   599,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   601,     0,   625,   626,   603,   604,     0,
       0,     0,     0,     0,     0,   602,     0,     0,     0,     0,
     299,   300,     0,   235,     0,   235,     0,     0,     0,   267,
       0,     0,   235,   397,     0,     0,    84,     0,    65,     0,
       0,    69,    68,    67,    66,    71,    70,    72,    73,     0,
       0,     0,     0,     0,     0,     0,   588,   505,     0,   234,
       0,   233,     0,   185,     0,     0,   588,   589,     0,     0,
       0,   638,     0,   639,   589,     0,     0,     0,   117,   117,
       0,   503,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   574,
     575,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    72,    73,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     540,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   404,     0,
     403,   534,   405,     0,   524,     0,     0,   505,     0,   542,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    72,    73,     0,   481,     0,     0,     0,     0,
       0,     0,     0,   321,     0,   357,   357,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   235,     0,
     235,   235,     0,   513,   512,     0,     0,     0,     0,   235,
     235,     0,     0,     0,     0,   317,     0,   235,     0,     0,
       0,   359,     0,     0,     0,     0,     0,     0,   235,   250,
       0,     0,   248,   391,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   368,   269,     0,     0,
       0,     0,     0,     0,     0,   235,     0,     0,     0,     0,
       0,   403,   271,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     303,   302,     0,   255,     0,     0,   257,     0,     0,     0,
     235,     0,     0,     0,   342,     0,     0,     0,     0,     0,
       0,     0,     0,    76,    79,    77,    78,    80,    81,     0,
       0,     0,     0,    88,    74,    75,     0,     0,     0,   266,
      39,   262,     0,     0,     0,     0,     0,   229,     0,     0,
       0,     0,     0,   236,     0,     0,   186,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   284,     0,     0,   118,     0,     0,
       0,   507,     0,     0,   506,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   348,     0,     0,     0,     0,   210,     0,
       0,     0,     0,     0,     0,   385,   386,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   505,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   462,   480,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   543,   545,     0,     0,     0,
       0,     0,     0,   499,     0,   402,   525,     0,     0,     0,
       0,   536,     0,   421,   420,   419,   418,   414,   415,   422,
     423,   417,   416,   407,   406,     0,   408,   535,   409,   412,
     410,   411,   413,   506,     0,     0,   484,     0,   560,     0,
       0,     0,     0,     0,     0,     0,     0,   355,     0,     0,
       0,     0,     0,     0,   388,     0,     0,     0,     0,     0,
     387,     0,   235,     0,     0,     0,     0,     0,   515,   514,
       0,     0,     0,     0,     0,     0,     0,   311,     0,     0,
       0,     0,     0,   374,     0,     0,     0,   249,     0,     0,
       0,   243,     0,     0,     0,     0,   384,   402,   532,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   304,   305,     0,   408,   506,   484,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   629,     0,
       0,     0,   501,     0,     0,   254,   258,   256,   260,     0,
       0,   650,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    95,     0,     0,   402,     0,     0,     0,    65,     0,
       0,    87,     0,    65,    66,     0,     0,     0,   506,     0,
       0,   484,     0,     0,     0,   204,     0,     0,     0,   645,
      27,    25,    26,     0,     0,     0,     0,     0,   592,    29,
       0,    28,     0,     0,   263,   640,   641,     0,   642,   592,
       0,     0,    82,   120,    83,   130,   508,   510,   136,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   291,   235,   576,   577,   221,     9,   426,
     427,   428,   429,   430,   431,   432,   433,   434,   448,   425,
     435,     0,   437,   438,   439,   440,   441,   573,   442,   443,
     444,     0,     0,     0,     0,     0,   565,   564,   563,     0,
       0,     0,   570,     0,   496,     0,     0,     0,   498,     0,
       0,     0,     0,   134,   479,   539,   538,   214,     0,     0,
       0,     0,     0,     0,   578,     0,     0,     0,   465,   572,
     470,     0,   476,     0,     0,     0,     0,   526,     0,     0,
     477,   546,   541,     0,     0,     0,     0,   469,   468,    72,
      73,   491,     0,     0,     0,     0,     0,     0,     0,   402,
     353,   358,   356,     0,   367,     0,   157,   158,     0,   214,
       0,   402,     0,     0,     0,     0,     0,   244,     0,   259,
     261,     0,     0,     0,   222,   224,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   324,     0,   308,
       0,   235,   235,     0,   360,   373,     0,     0,     0,     0,
     245,     0,     0,     0,     0,   217,   363,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   251,     0,
       0,     0,     0,     0,     0,     0,   615,     0,   622,   611,
     612,   613,     0,   628,   627,     0,     0,   616,   617,   618,
     624,   632,   631,     0,   148,     0,   605,     0,   607,     0,
       0,     0,   600,     0,     0,   253,     0,     0,     0,     0,
     343,     0,     0,     0,   398,     0,   646,     0,   109,    65,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   103,     0,     0,     0,     0,   597,    50,     0,     0,
       0,    63,     0,    40,    41,    42,    43,    44,    45,     0,
     469,   468,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   591,   590,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   144,     0,     0,     0,
       0,   137,   138,     0,     0,     0,     0,   164,   164,     0,
       0,     0,     0,     0,   160,     0,     0,     0,     0,     0,
       0,   349,     0,     0,     0,     0,   364,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   547,   548,   549,   550,     0,     0,     0,     0,
       0,     0,     0,   544,     0,   556,     0,     0,     0,   499,
     500,     0,   472,     0,     0,   537,   424,   527,   485,   483,
       0,   482,     0,     0,   561,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   366,     0,     0,     0,     0,     0,
     389,     0,     0,     0,    76,     0,   252,     0,     0,     0,
       0,     0,     0,     0,   329,     0,     0,   328,     0,   331,
       0,   333,     0,   318,   325,     0,     0,     0,     0,     0,
     375,     0,     0,   247,   246,   392,     0,     0,     0,    36,
      37,     0,     0,     0,     0,     0,     0,   583,     0,     0,
       0,   294,   485,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   501,   502,   609,     0,   370,     0,
       0,   235,   344,     0,   345,   235,     0,     0,   598,     0,
      94,     0,     0,     0,     0,    92,     0,   586,     0,   107,
       0,    99,   101,     0,     0,     0,    89,     0,     0,     0,
       0,     0,    35,   485,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    30,    31,     0,
     593,     0,     0,    33,    32,     0,   593,   643,   279,     0,
       0,   121,   126,     0,     0,     0,   140,   146,   147,   143,
     141,   142,   504,     0,    85,     0,    86,   168,     0,     0,
       0,     0,   169,   188,   189,   166,     0,     0,     0,   170,
     199,   190,   194,   195,   191,     0,   192,   193,   178,     0,
       0,   436,   450,   449,   445,   446,   447,   566,     0,     0,
       0,   494,   495,   497,   135,   463,     0,     0,     0,   551,
       0,   579,   493,   466,   471,     0,     0,   499,   200,   478,
      72,    73,     0,   490,   486,   488,   567,   196,     0,     0,
       0,   160,     0,     0,   365,     0,   159,     0,     0,     0,
       0,     0,     0,   268,     0,     0,     0,     0,   235,   235,
       0,     0,   330,   522,     0,     0,   332,   334,     0,     0,
     312,   227,   228,   197,     0,     0,     0,     0,     0,     0,
       0,   175,     0,   176,     0,     0,     0,     0,     0,     0,
     110,   114,     0,   623,     0,     0,   621,     0,   633,     0,
       0,   149,   150,   630,   606,   608,     0,     0,     0,     0,
     342,   346,   342,     0,   399,    93,     0,     0,    65,     0,
       0,    91,     0,   584,     0,     0,     0,     0,     0,     0,
     636,   635,     0,     0,     0,     0,     0,   520,     0,     0,
      76,   264,   486,   265,     0,     0,     0,     0,     0,     0,
     241,   237,     0,     0,   596,   594,     0,     0,     0,     0,
     122,   127,     0,     0,     0,   574,   575,   139,   369,   165,
     173,   174,   179,     0,     0,     0,     0,     0,   181,   350,
       0,     0,   292,     0,     0,     0,     0,     0,     0,     0,
       0,   473,     0,     0,     0,   562,   492,     0,     0,   180,
       0,   201,   354,     0,     0,     0,     0,   202,     0,     0,
       0,     0,     0,     0,   519,   518,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   371,
     372,    38,   183,   184,     0,   581,     0,     0,   296,   295,
       0,     0,     0,     0,     0,     0,     0,     0,   152,   153,
     156,   155,   154,     0,   610,     0,   647,     0,     0,     0,
       0,     0,     0,     0,     0,   104,   105,   587,     0,     0,
       0,    96,     0,     0,     0,    46,     0,     0,     0,     0,
       0,    48,     0,   242,   238,   239,   240,    34,     0,     0,
     644,   281,     0,   134,   148,     0,     0,   145,     0,     0,
       0,   167,   198,     0,     0,     0,     0,     0,   568,   569,
       0,     0,     0,     0,     0,   499,   474,   487,   489,     0,
       0,   182,   205,     0,     0,     0,   361,   361,     0,   115,
     116,   235,     0,   225,   226,   319,     0,   326,     0,     0,
     235,     0,   232,     0,   230,     0,     0,     0,     0,   528,
       0,   111,   113,   112,   614,   620,   619,   151,     0,     0,
       0,   347,     0,     0,   108,   100,   102,     0,    90,   637,
      97,    98,    51,     0,     0,     0,     0,   521,     0,     0,
     487,   595,     0,     0,     0,     0,   124,   634,     0,   131,
       0,     0,     0,     0,   351,   187,     0,     0,   554,     0,
       0,     0,   322,     0,   171,   172,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   517,     0,   336,     0,
       0,   313,     0,   231,     0,   580,   297,     0,   529,     0,
     383,   235,   400,     0,   585,     0,    47,     0,     0,     0,
      64,    49,     0,   282,   123,   128,   134,     0,     0,   162,
     163,   161,     0,     0,     0,   555,   475,     0,     0,     0,
       0,   362,   376,     0,     0,   377,     0,   223,     0,   327,
       0,   309,     0,   235,   177,   530,   293,   342,   106,     0,
       0,     0,     0,     0,     0,   132,   133,     0,   552,   553,
       0,   203,     0,   380,     0,   381,   382,   516,     0,     0,
     315,     0,     0,    55,     0,    61,     0,     0,   125,     0,
     323,     0,     0,   335,   314,   310,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   352,    52,     0,
      59,     0,   276,   571,     0,     0,   316,     0,    53,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    56,
      54,     0,    57,     0,   378,   379,     0,     0,    62,    60,
      58
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,   125,  1113,   126,   127,  1097,  1974,  1980,
    1403,  1627,  2135,  2237,  1404,  2219,  2251,  1405,  2239,  1406,
    1407,  1631,   460,   625,   626,  1186,  1733,   128,   818,   488,
    1993,  2146,  1994,   489,  1864,  1487,  1440,  1441,  1442,  1591,
    1801,  1802,  1265,  1688,  1679,  1874,   793,   637,   297,   298,
     367,   216,   299,   470,   471,   132,   133,   134,   135,   136,
     137,   138,   300,  1300,  2172,  2216,   995,  1296,  1297,   301,
    1076,   302,   142,  1523,  1263,   967,  1002,  2110,   143,   144,
     145,   146,   303,   304,  1213,  1236,  1361,   305,   823,   306,
     822,   491,   653,   341,  1836,   371,  1943,   372,   308,   595,
    1223,   386,  1387,  1618,   481,   476,  1354,  1056,  1668,  1829,
    1830,  1041,   483,   148,   396
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1955
static const yytype_int16 yypact[] =
{
   13396,    38,   101, 13609, -1955, -1955,  -146,    41,   -15,  -154,
    -145,  -115,    35,   241,   339,   427,   432,   -71,    53,    55,
     -50,   439,   462,   497,   517,    -6,   272,    32,   191,   493,
     191,   226,   276,   313,    45,   338,   374,    70,   400,   415,
     429,   445,   460,   466,   491,   505,   510,   528,    14,   455,
     482,   698,   709,   475,    13,   649,   537,  7230,   546,   531,
     547,   702,   -45,   267,   493,   -48,   293,   554,   729,  -117,
     593,   -82,   -82,   611,   354,   652,   668, -1955, -1955, -1955,
   -1955, -1955,   642,   379,   804,   830,    12,    52,   933,   837,
     836,    74,  5033,   856,   962,   964,   965,  5033,   967,   -88,
     -76,   707,    16,    73, -1955,   730,   731, -1955, -1955, 10569,
     968,   727, -1955, 13865,   732, 13928,    25,    28,   493, -1955,
   -1955, -1955, 12240,   736,   993, -1955, -1955, -1955, -1955, -1955,
     737, -1955, -1955, -1955, -1955, -1955, -1955, -1955, -1955, -1955,
     -74, -1955, -1955, -1955, -1955,    22, -1955,   995,   735,  5311,
      68,   743,   999, 12240, 13801, 13801, 13801, -1955, 12240, -1955,
   -1955, -1955, -1955, 13801, -1955, 12240, -1955, -1955, 12240, -1955,
   -1955, -1955, -1955, -1955, -1955,   740,   749,  1006, -1955, -1955,
    7367, -1955, -1955, -1955, -1955,   751,  7367, 12240, 12240, 12240,
     752, 12240, 12240, 12240,   755, 12240, 12240, 12240, 12240, 12240,
   12240, 12240, 13801, 12240, 12240, 12240, 12240,  5033,   757, -1955,
   -1955,  9592, -1955, -1955, -1955,   754,  5033,  7493, 13801, -1955,
   -1955, -1955, -1955, -1955,   191,   191,   191,   191,   191,   191,
     191,   191,   191,   191,   191,   191,   191,   191,   191,   191,
     191,   191,   191,   191,   191,   191,   191,   191,   191,   191,
     435,   191,   191,   191,   191,   191,   759,   191,   191,   760,
     493,   118,   118,   118, -1955, -1955, -1955,   191,   191,    37,
     825,   826,   827,   762,   918,   542,   -18,  7493,   894,   493,
     493,   118,   768,   191,   191,   769,   770,   771, -1955, -1955,
   -1955, 12240,  7756, 12240, 12240,  8019,    32,   838,    42, -1955,
   -1955,   787, -1955,  5652, -1955, -1955, -1955, -1955, -1955,   188,
   12240,  9592,  9592,   772,   773,  8282,  5033,  5033,  5033, -1955,
   -1955, -1955,   793, -1955,   792,   797,  8545,   794, 10659,  1060,
    7493,   798,    16,   800,   801,   -82,   -82,   -82, 12240, 12240,
     213, -1955,   377,   -82, 10922,   383,  9592,  9592, 12240,  5033,
    5033,  5033,   210,    15,  1059,   799, -1955,  1065,  1066, -1955,
     806, -1955,   808,   809, -1955, -1955,   811,  5033, -1955, 12240,
    6704, -1955,  1074,   813,   818,   819,   820,  1083,  1085,   828,
   12240,   829, 12240, 12240,   472, 12240,   833, -1955,   895, 12240,
   12240, 12240, -1955,   191, 12240,  1923,   198, -1955, 12240, -1955,
     191,   191,   191,   832,   834,   839,   191,   191,   191,   191,
     191,   191,   191, -1955,   191, -1955, -1955, -1955, -1955,   191,
     191,   841,   842,   191,   843, -1955,   831,  1089,  1103,   844,
   -1955, -1955,  1108,  1109,  1110,  1124,   853, 15998, 13801, -1955,
    9592, 12240, -1955, -1955,  7493,  7493, -1955,   868,  7367,   493,
    1131, -1955, -1955, -1955, -1955, -1955, -1955, 12240, 12240,   450,
    7493,  1133,  -103,   873,  2150,   877,  1148,    36,   889, -1955,
     890, 14059, 12240, -1955,  2177,  -158, -1955,    69,    65,   173,
    9524, -1955,   196, -1955,    94,  9881,  1592, 10243,   -36,   212,
    1061, -1955,    32,   885, 12240,   888, 16514, 16539, 16564, 12240,
   16589, 16614, 16639, 12240, 16664, 16689, 16714, 16739, 16764, 16789,
   16814,   227, 16839, 16864, 16889, 14809,  1156, 12240,  9592,  5848,
   -1955,   246, 12240,  1158,  1159,   900, 12240, 12240, 12240, 12240,
   12240, 12240, 12240, 12240, 12240, 12240, 12240, 12240, 12240, 12240,
   12240, 12240, 12240,  9592, 12240, 12240, 12240, 12240, 12240, 12240,
   12240, 12240,  9592,  9592,   898, 12240, 12240, 13801, 12240, 13801,
    7493, 13801, 13801, 13801,   902,   903,   904,   905, 12240,    34,
   -1955, 11012, 12240,   906,   907,   908,    74,   909,  7493,  6967,
    7493,   910, 13801, 13801,  9592,    32,  7367,    32,   916,  9592,
     916, -1955,   916, 16914, -1955,   318,   911,    93,  1101, -1955,
    1173, 12240, 12240, 12240, 12240, 12240, 12240, 12240, 12240, 12240,
   12240, 12240, 12240, 12240, 12240,  8808, 12240, 12240, 12240, 12240,
   12240,    32, 12240, 12240,    47, -1955,   303, 16939,   358,   387,
   12240, 12240, 12240, -1955,  1176,  1177,  1177,   920, 12240, 12240,
   12240, 12240,    26,  9592,  9592, 16026,   921,  1180, -1955,   924,
   -1955, -1955,  -186, -1955, -1955, 10600, 10953,   -82,   -82,    68,
      68,   -95, 10922, 10922, 12240, 10624,   -78, -1955,   467,   485,
   16964,  1182,  1184,  1187, 12240, 12240,  1189, 12240, -1955, -1955,
   12240, 10977, -1955, -1955,  9592,  9592,  9592, 12240,  1190, 16989,
     929, 12240,  9592, 12240, 12240, 12240, -1955, -1955, 12240, 17014,
   12240, 17039, 17064,  1002, 11225, -1955,   932,  6110, 17089, 17114,
   12240,   916, -1955, 12240,    32, 12240, 12240,    47, 16109, 13801,
   13801, 13801, 13801, 13801, 13801, 13801, 13801, 13801, 12240, 13801,
   13801, 13801, 13801,    18,  7367, 13801, 13801, 13801,    32,    32,
   -1955, -1955,  9592, -1955,   935, 12316, -1955,   936, 12421, 12240,
   -1955,   939,   498, 17139, 13947,   942,   504, 12240,  1203,   941,
    7493, 17164, 16136, -1955, -1955, -1955, -1955, -1955, -1955,   940,
    1205,   233,  1208, -1955, -1955, -1955,  9592,    19, 12240, -1955,
   -1955, -1955,    32, 12240, 12240,    47,   948, -1955,   953,   -32,
     493,   -48,   493, -1955,   950, 14838, -1955,   158,  9592,    32,
   12240, 12240,    47,  1214,  9592,  1215,  9592, 12240,  1216, 13801,
      32, 11270,    47, 12240, -1955, 12240,  1217, -1955,    32,  1218,
   13801, 12240,   959,   960, -1955, 12240, 11301,  7367,  1219,  1221,
    1222, 17189,  1223,  1224,  1225, 17214,  1226,  1227,  1229,  1230,
    1231,  1233,  1234, -1955, 12240,  1235,  1236,  1237, -1955, 12240,
   17239,  9592,    63,  9592, 14867, -1955, -1955,  1239, 16082, 16082,
   16082, 16082, 16082, 16082, 16082, 16082, 16082, 16082, 16082, 16082,
   11580, 16082, 16082, 16082, 16082,   734,   495, 16082, 16082, 16082,
   11839, 12098, 13076, 13182, 13395,  5848,   980,   979,   181,  9592,
   13879, 13984,   495, 14017,   495,   974,   975,   976,   244,  9592,
   12240, 12240, 12240, 18014, -1955,   495,   984, 14896, 14925, 12240,
   12240, 12240,   986, 12240,  5585, -1955, -1955, 12240,   982,   328,
     495,  -191,   991,   296,   507,  1251, -1955,    47,   495,  7493,
     989,  6373,  6636,   577,   796,   872,   872,   533,   533,   533,
     533,   533,   533,   494,   494,  9592,   352, -1955,   352,   352,
     916,   916,   916,   990, 17264, 16163,   412,  9592, -1955,  1253,
     994,   996, 17289, 17314, 17339, 12240,  7493,  1258,  1261, 10311,
   17364, 14954, 17389, 17414, -1955, 12240,   524,   535,  9592,   997,
   -1955, 12483, -1955, 12588, 12650,   -82, 12240, 12240, -1955, -1955,
    1000,  1001, 10922,  7689,  1115,   -11,   -82, 12755,  1003,  1004,
    1262, 12240,  1270, -1955, 12240, 17439, 14983, -1955, 16190, 12817,
   16217, -1955,   538,   544,   569, 15012, -1955, -1955, -1955,  2381,
     570, 16244, 16271, 14050, 17464,  1271, 17489,  1272,  1274,  1011,
   12240, 12922, 12240, 12240, -1955, -1955, 16082,   352,  1012,   430,
      50,   331,   388,   331,  1018,  1019,  1014,   495,   495,  1016,
   14083,   495,   495,   495,   495, 12240,   495,  1268, -1955,  1017,
    1020,   392,  -135,  1024,   572, -1955, -1955, -1955, -1955, 17514,
   12984,  1021,  1094,  1289,  1127, 11367,  1028,  1030,  1295,  7493,
   15041, -1955, 12240,  1296,   259,    79,    47,    17,  7367, 12240,
    1297, -1955,   575,  1257,  1259,  7493, 15070,   166,  1037, 17539,
   16298,   502, 12240, 12240,  1045,  1042,  1047,  1046,  9071, -1955,
   -1955, -1955, -1955, 13801,   251,  1043, 17564, 16325,  1051, -1955,
     268, -1955,   278, 14116, -1955, -1955, -1955,  1049, -1955,  1058,
   15099, 14149, -1955,    84, -1955, -1955, 18014, -1955,    96, 16082,
   12240,   495,   -82,  7493,  7493,  1317,  7493,  7493,  7493,  1318,
    7493,  7493,  7493,  7493,  7493,  7493,  7493,  7952,  7493,  7493,
    7493,  2441,  1320, -1955,    68,  5848, -1955, -1955, -1955, -1955,
   -1955, -1955, -1955, -1955, -1955, -1955, -1955, -1955, -1955, -1955,
   -1955, 12240, -1955, -1955, -1955, -1955, -1955, -1955, -1955, -1955,
   -1955, 12240, 12240, 12240, 12240, 12240, -1955, -1955, -1955,   581,
   12240, 12240, -1955, 12240, -1955,  7493, 13801, 13801, -1955,   582,
   15128, 15157, 15186,  1054, -1955, -1955, -1955,  1128, 15215, 15244,
   15273, 12240, 15302,   583, -1955, 15331, 12240, 12240, -1955, -1955,
   -1955,    47, -1955,    47, 12240, 12240,  1064, -1955,  7493,   191,
   -1955, -1955, -1955, 12240, 12240,   589,    47,   409,  -131, 12240,
   12240, -1955,   495,   591,  7493,  9592,  9592,  1325,  1328,  1329,
    4236, -1955, -1955,  1331, -1955,  1072, 18014,  1068,  1333, -1955,
    1337,  1338,  2599,  1339,  1340,   597,    88, -1955, 13089, -1955,
   -1955,   -73, 14182, 14215, -1955, -1955, 15360,   224,  1228,  1344,
   11625,  1081,  1347,  1090,    23,    31,   -37, -1955,   -19, -1955,
     -11,    68,    68,  7493, 18014, -1955,  2635,  1087,  1254,  1352,
   -1955,  1354,  1355,  1252,  1357, -1955, -1955,  1358,  1356,  1360,
   12240,  1361,  7493,  1364,  7493,  7493,  1368, 14248, -1955,  6899,
    1209,    47, 12240, 12240,    47,    47, -1955,  9592, -1955, -1955,
   -1955, -1955, 13801, -1955, -1955, 12240, 13801, -1955, -1955, -1955,
   -1955, 18014, -1955,  1102,  1104, 13801, -1955, 13801, -1955,    47,
   13801,  1111, -1955,  1105,  1369, -1955,  1107,   493,  1112, 11722,
   -1955,  2794,  1113,  7493, -1955,  1114, -1955, 15389, -1955, -1955,
   12240,  1374,   500, 12240,  1379,  1380,    16,  1382,  1119,  1383,
    3231, -1955,   495,   191,   191,  1384, -1955, -1955,  1126,  1129,
    1123, -1955,  1387, -1955, -1955, -1955, -1955, -1955, -1955,    47,
     -13,  3675, 12240, 16352, 17589, 12240,  5915, 12240,  9592,  1125,
     599,  1390,   182,    47, -1955,  1130, 12240,  1391,  1392, 12240,
      47, 11884,  1394, 12240,  9850,   495,  6178, 12240, 12240, 12240,
    1134,  1132, -1955,  1397, 17614,  1398,    99,  1263,  1263,  7493,
    1401,  1403,  1404,  7493,   -97,  1405,  1413,  1414,  1415,  1416,
    1417, -1955, 12240,  1418,  1419,  1420, -1955,  1423,  1160, 16082,
   16082, 16082, 16082, 16082, 16082,   495, 14281, 14314, 14347,  1163,
     495,   495, -1955, -1955, -1955, -1955,    96,   495,  1302,  1303,
    1305, 15418,  1238, -1955,  7367, -1955, 17639, 16082,  1169,   -81,
   18014, 16082, -1955,  1430,   495, 18014, 18014, -1955,   436, -1955,
      47, -1955, 17664, 16379, -1955,   495,  1434,   600,   602,  7493,
    7493,  7493,  1437,  1436, -1955,    24, 12240,  7493,  7493,  7493,
   -1955,  1174,  1175,  1438,  1441,  1442, -1955, 12240, 12240, 12240,
    1179,  1200,  1201,  1207, -1955,  3379,  7493, -1955, 12240, -1955,
    1470, -1955,  1473, -1955, -1955, 10922,   442,  1211,  1212,  1477,
   -1955,  9592,  1220, -1955, -1955, -1955,  1232, 12240, 12240, -1955,
   -1955, 16406,  7493,  1478,  7493,  1479,  1291, -1955, 12240, 12240,
   12240, -1955,   515,  1480,   681,   402,  1240,  7426,  1241, 12240,
      30,   495,  1242,   495,  1245, -1955, -1955,  7367, -1955, 12240,
    1243, -1955, -1955,  3409, -1955, -1955,  1247,  1484, -1955,  3758,
   -1955,  1256,  1485,   273,  3815, -1955,    16, -1955,   605, -1955,
   12240, -1955, -1955,    24,  2498,  4177, -1955,  1244, 12240, 12240,
    7493,  1260, -1955,   -49,    91,  1487, 17689,  1488,  1251, 17714,
    1264,   608,   613, 17739,   615,  1489,  1492, -1955, -1955, 13801,
    1246,  1495, 17764, -1955, -1955, 14380,  1266, -1955, -1955,  8214,
    6441, 18014, -1955,  1496,   191,  8019, -1955, -1955, -1955, 18014,
   18014, 18014, -1955,    96, -1955,  1498, -1955, -1955,   -82,  1499,
    1500,  1501, -1955, -1955, -1955,  1342,   -34,  1393,  1504, -1955,
   -1955, -1955, -1955, -1955, -1955,  8478, -1955, -1955, -1955,  1517,
    1522, -1955, -1955, -1955, -1955, -1955, -1955, -1955, 12240, 12240,
   12240, -1955, -1955, -1955,  1132, -1955,  1269,  1273,  1275, -1955,
    1412, -1955, -1955, -1955, -1955, 12240,  1267,  1265, -1955, -1955,
   12240, 12240,   495,   409, -1955, -1955, -1955, -1955,  1276,  1277,
    1526,   -97,  1529, 12240, -1955,  7493, 18014,  1388,  1399,   779,
    9592,  9592, 12240, -1955, 10311, 15447, 17789,  8740,    68,    68,
   12240, 12240, -1955,   141,  1278, 17814, -1955, -1955, 15476,   231,
   -1955, -1955, -1955, -1955,   618,  9592, 12240,  3855,  4317,  1534,
    1535, -1955,  1541, -1955,  7493,  9003,   170, 17839, 12240, 12240,
   -1955, -1955,  9949, -1955, 13801, 12240, -1955, 13801, 18014, 10212,
    7367,  1279, -1955, -1955, -1955, -1955,  1283,  1280, 15505, 12240,
   13947, -1955, 13947,  7493, -1955, -1955,    47,    17,  7367, 12240,
    1544, -1955,  1545, -1955,    16, 16433,  7493, 13801,  1549,   495,
   -1955,  1282,   495, 12240, 14413, 14446,   620, -1955, 12240, 12240,
    1288, -1955,  1290, -1955,  1329,  1554,  1555,  1556,  1338,  1557,
   -1955, -1955,  1558, 12240, -1955, -1955, 12240, 11981,  1559, 12240,
   -1955, -1955,  1298,  4177,   621,  5517,  1561, -1955, -1955,   645,
   -1955, -1955, -1955,  1435,  1560,  1301,  1304,  1314, -1955, -1955,
   12240,  1567, -1955, 16082, 16082, 14479, 12240, 12240, 12240,  1326,
   16082, -1955,  1323, 17864, 16460, -1955, -1955,  9592,  9592, -1955,
    1588, -1955, 18014,  1590, 12240, 12240,  1330, -1955,   623,   630,
   16054,  4354,  1595,  1335, -1955, -1955, 12240,  1332,  1341, 15534,
   16487,  1601,  7493,  1591,  1343, 12240,  1602,   631, 15563, -1955,
   -1955, -1955, -1955, -1955,  1421, -1955, 12240, 12240, -1955, -1955,
   12143,  9329,  4423,  1608,  1609,  1350, 16082,   495, 18014, -1955,
   -1955, -1955, -1955,    30, -1955,  7367, -1955, 15592,  1348,  1349,
    1359,  1613,  1618,  1619,  4493, -1955, -1955, -1955,  1362,  1620,
     636, -1955,  1622,  1624,   281, 18014, 12240, 12240,  1363,  7493,
     638, 18014, 17889, -1955, -1955, -1955, -1955, -1955, 17914, 14512,
   -1955, -1955, 15621,  1054,  1104,  7493,   495, -1955, 12240,  7367,
      32, -1955, -1955,  9592,  9592, 12240, 17939,  1625, -1955, -1955,
   12240, 14545, 15650, 14578, 12240,  1265, -1955, -1955, -1955,   639,
     646, -1955, -1955,  4677,  4700,  7493,   470,   479,  9592, -1955,
   -1955,    68,  9261, -1955, -1955, -1955,  1628, -1955,  1365,  7493,
   -1955, 15679, -1955,  1630, -1955, 12240, 15708, 15737,  9592, -1955,
     648, -1955, -1955, -1955, -1955, -1955, -1955, -1955,  1371,  1632,
    1370, -1955,  1634,    16, -1955, -1955, -1955,  1443, -1955, -1955,
   -1955, -1955, -1955, 12240, 14611, 14644,  7493, -1955,  1635, 12240,
    1375, -1955, 12240,  1637,  1378,  1381, -1955, -1955,  5625, -1955,
    1385,   653,   659, 15766, -1955, -1955, 14677, 12240, -1955, 12240,
   15795,  1386, -1955,  1389, -1955, -1955,   660,  1396,   -82,  7493,
    1643,  1400,   -82,  1647,   661,  1402, -1955, 12240, -1955,  1648,
    1506, 13151,  1407, -1955,  4723, -1955, -1955,   662, -1955,  1650,
   -1955, -1955, -1955,  1653, -1955,  1408, 18014, 12240, 12240,   670,
   -1955, 18014, 14710, -1955, -1955, -1955,  1054,  7367,  1395, -1955,
   -1955, -1955, 12240, 15824, 15853, -1955, -1955,  9592,  1654,   -82,
     109, -1955, -1955,   -82,   149, -1955,  1657, -1955, 15882, -1955,
   12240, -1955,   -11, -1955, -1955, -1955, -1955, 13947, -1955, 12240,
   17964, 14743,    64, 12240,  1409, -1955, -1955, 14776, -1955, -1955,
     676, -1955,   255, -1955,   274, -1955, -1955, -1955,  5242,   506,
   13256,  1410,   682, -1955, 12240, -1955,  7493, 15911, -1955, 12240,
   -1955,   -82,   -82, -1955, -1955, -1955,   -11,  1660,  1661,  1422,
   17989,   683,  1662, 16082,   277,   279,   529, -1955, -1955, 13801,
   -1955,  1424, -1955, -1955, 12240, 12240, -1955,   685, -1955,  1425,
    7493, 15940, 15969,  1664, 13801, 13801,   688,  1665,  1672, -1955,
   -1955,   690, -1955,  1675, -1955, -1955,  1677, 13801, -1955, -1955,
   -1955
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1955, -1955, -1955, -1955,   262, -1955, -1955, -1955, -1955,  -494,
   -1955, -1955, -1955, -1955, -1955, -1955, -1955, -1955, -1955, -1955,
   -1955, -1955,  -759,  -136,  2107,  3968,  -143, -1955,  1197, -1955,
   -1955, -1955, -1955, -1955, -1955, -1954, -1955,   202,    39,  -305,
   -1955,  -263, -1955,   -46,   248, -1955,  1689, -1955,   855,   -51,
    1135, -1955,     4,  -658,  -105, -1955, -1955, -1955, -1955, -1955,
   -1955,   625,  1707, -1955, -1955, -1955, -1955, -1291, -1285,  1714,
   -1795,  1715, -1955, -1955, -1955,  1084, -1955,  -304, -1955, -1955,
   -1955, -1955,  2616, -1955, -1955, -1491,   130,  1723, -1955,     0,
   -1955, -1955,   -68, -1955, -1593,   753, -1955,   -72,  3242,    62,
     311,  -327,   -89, -1955,  1726,   -67, -1955, -1955,   -70,   114,
   -1756,  -153,   934, -1955,    -3
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -597
static const yytype_int16 yytable[] =
{
     149,   990,   991,   340,   342,   649,   345,   131,  1726,  1556,
     482,  1554,  1089,   461,   326,  1958,   353,  1959,  1095,   676,
     384,   175,   175,   379,   177,   377,  1093,   176,   443,  1549,
     432,  1379,   974,   434,  1799,   381,   175,  1551,   175,  2084,
     175,   157,   570,  1951,     4,   782,   427,   599,   431,   190,
     576,   763,  1686,   331,   309,   152,   358,  1334,   359,   164,
     320,   166,   486,   321,   322,   323,   314,   657,   658,  1163,
    2205,  1875,   468,   764,   194,  1230,   324,   388,   799,   314,
    1231,   332,   466,   357,   765,   766,  1379,   577,   985,   309,
    1876,  1434,  1534,   315,   309,  1840,   153,   333,   334,   387,
    1436,     5,   492,   810,  1687,  1677,  1104,  1996,   797,   354,
     428,   154,  1289,   493,   764,  2193,   798,   764,   212,   495,
     155,   213,  1437,   150,   214,   765,   766,   151,   765,   766,
    1290,   455,   456,  1438,  1439,   516,  1359,   215,  1289,  1360,
    1510,  1291,  1292,  1293,   523,   325,   467,  1294,  1295,   601,
     156,   477,   477,   477,   469,  2195,  1290,   360,   657,   658,
     484,   767,   768,   774,  1110,   775,   776,  1291,  1292,  1293,
    1397,   336,   337,  1294,  1295,   657,   658,   380,  1937,   992,
     657,   658,   364,   338,   178,   365,   179,   339,  1648,   382,
     621,   441,  2184,  1234,   163,   442,   996,   621,   366,   477,
     975,  1537,   767,   768,   309,   767,   768,   714,   309,  1550,
     565,   566,   567,   309,   309,   477,  1839,  1552,  1789,   168,
    -593,   355,    70,    71,    72,    73,   320,    75,    76,   321,
     581,   323,   816,  1553,   657,   658,  1892,    85,   817,   665,
    1088,    89,   324,  1800,   634,   635,   636,   159,   123,   455,
     456,   681,   123,   123,   123,  1555,  -591,   451,   452,   453,
    1094,   173,   451,   452,   453,   454,  1379,   652,   123,   654,
     123,  1554,   123,   521,   309,   661,   666,   671,   672,   673,
    1818,   356,   677,   206,   678,   385,  1386,   444,   151,   309,
    1055,   445,   309,   597,   433,   688,   596,   435,   455,   456,
     774,   783,   775,   784,   158,  -589,   571,   785,   309,   309,
     191,   600,   309,   309,   309,   309,   771,   451,   452,   453,
     454,  1335,   165,   309,   167,  1380,  1383,   309,   745,   387,
     748,   803,  1164,  2206,   800,   195,   801,   754,   389,   804,
     802,   455,   456,   309,   309,   160,   309,   309,   309,   178,
    1382,   179,   657,   658,  1398,  1399,  1400,  1401,   178,   811,
     179,   801,   657,   658,   309,   812,   103,   309,   104,   105,
     106,   107,   108,   628,   629,   316,   112,   113,   317,   115,
     318,   758,  2201,   602,   603,   604,   605,   606,   607,   608,
     609,   610,   611,   612,   613,   614,   615,   616,   617,   618,
     619,   327,   657,   658,   328,   620,  1111,  1112,   668,   669,
     898,  1921,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   614,   713,   616,   617,   618,   619,
    1111,  1112,  2106,   161,   620,   477,  1402,   309,   162,   805,
    1938,   309,   309,   455,   456,   169,   622,   806,   623,  1198,
     455,   456,   624,   622,   763,   623,   178,   309,   179,   624,
     455,   456,   808,   715,   786,   716,   657,   658,   170,   717,
     809,   451,   452,   453,   454,   674,   764,   657,   658,   675,
     819,   956,   659,  2139,   657,   658,   817,   765,   766,   824,
     349,   187,   350,   843,  1541,   455,   456,   451,   452,   453,
     454,   844,   752,   171,   763,  1925,  1468,   915,   657,   658,
    1208,   451,   452,   453,   454,   309,   852,  1422,   809,   922,
     853,   455,   456,   172,  2101,   853,   764,   657,   658,  2211,
     657,   658,   657,   658,  1427,   455,   456,   765,   766,   174,
     309,   188,   853,   981,  1428,   983,   984,  2072,  2212,   309,
     888,  2234,   853,  2235,   477,  2073,   477,   309,   477,   477,
     484,   178,   997,   179,   767,   768,   905,  1233,  1043,   774,
    1234,   775,   957,  1009,  1039,   309,   309,   309,   189,   477,
     477,   309,   177,   207,   177,   921,   309,   923,   926,   988,
     989,  1289,   853,   208,   774,   654,   775,   774,   181,   775,
    1031,   182,  1227,   192,   183,   809,   184,   336,   337,  1290,
     618,   619,   309,  2221,   767,   768,   620,    48,   953,   338,
    1291,  1292,  1293,   344,  2107,  2108,  1294,  1295,   960,  2109,
     657,   658,   853,  2111,  2112,  1090,   657,   658,  2109,   193,
     309,   309,  1101,  1557,  1558,  1070,   660,  2246,   769,   770,
     574,   924,   667,   575,   774,  1289,   775,   961,   774,  1118,
     775,   853,  1337,   469,   469,   196,  1357,  1058,   774,  1129,
     775,   455,   456,  1290,   455,   456,   853,  1249,  1289,  1250,
     197,   309,   309,   309,  1291,  1292,  1293,  1791,  1792,   309,
    1294,  1295,   455,   456,   198,  1332,  1290,  1333,  1611,  1612,
     552,  1730,   553,  1731,   209,   976,   977,  1291,  1292,  1293,
     199,  1038,  1770,  1294,  1295,   210,   484,   477,   484,   477,
     477,   477,   477,   477,   477,   200,   477,   477,   477,   477,
    1057,   201,   477,   477,   477,   177,  1063,   998,  1062,   309,
    1106,   853,   601,   703,   211,   151,  1012,  1013,  1014,   713,
     616,   617,   618,   619,  1020,   999,   202,   309,   620,   853,
    1141,   774,   217,   775,   455,   456,  1745,  1412,  1072,  1333,
     203,  -592,   853,   309,  1078,   204,  2214,  1237,  1079,  1098,
    1788,   853,  1789,  1906,  1239,  1907,   613,   614,   713,   616,
     617,   618,   619,   205,  1273,   309,  1115,   620,   853,  2236,
     311,   309,   218,   309,  1064,  1274,   484,  1127,  1312,   853,
     307,   310,   853,   313,  1313,  1133,   312,   477,   853,   329,
    1251,   604,   605,   606,   607,   608,   609,   610,   611,   612,
     613,   614,   713,   616,   617,   618,   619,   330,  1092,  1314,
    1317,   620,  1363,   853,   853,  1392,   853,  1224,   309,   853,
     309,  1475,  1482,  1493,  1819,   853,   853,  1494,   130,  1507,
    1114,  1515,   335,   853,  1826,   853,  1120,  1533,  1122,  1646,
    1738,   853,  1739,   853,   853,  1823,   853,  1278,  1846,  1824,
     343,  2199,   853,  1847,   185,  1849,   309,  1494,  1926,   853,
    1978,  1997,   853,  2026,  1979,  1998,   309,   853,   657,   658,
    2027,  2043,  1267,  1251,   853,   853,  2069,   348,  2078,  2102,
     809,   309,  2079,   853,  1554,   351,  2103,  1281,  2128,   319,
     853,   346,   853,  2149,  1287,  2226,   309,   853,  1298,  2150,
    2158,  2166,  2175,   853,  1979,   853,   853,   347,   352,   361,
    2182,  1554,   309,  1385,  1979,   362,  2210,   363,  1381,  1384,
     853,  1199,  2218,  2231,   309,  2243,  2079,  1979,  2253,  2244,
    2256,  1209,  1979,   309,  2257,  1251,   374,   373,   375,   376,
     524,   378,   383,   436,   397,   309,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   612,   613,   614,   851,
     616,   617,   618,   619,   398,   390,   391,   429,   620,   439,
     774,   446,   775,   438,   463,   473,   440,  1245,   447,   463,
     463,   463,   472,   151,   490,   492,   494,   499,   463,  1253,
     503,  1389,   517,   522,   560,   563,  -207,  -208,  -209,   573,
     307,   572,   578,   582,   585,   586,   587,   630,   631,   598,
    1275,   605,   606,   607,   608,   609,   610,   611,   612,   613,
     614,   713,   616,   617,   618,   619,   442,   463,   638,  1617,
     620,   639,   640,   643,   646,   679,   680,   648,   633,   650,
     651,   682,   683,   463,  1446,   684,   309,   685,   686,   642,
     687,   691,   692,   647,  1388,   693,   694,   695,  1498,   696,
    1499,   697,   309,   698,   700,   740,   706,   722,   739,   723,
    1917,  1918,   705,  1508,   724,   309,   735,   736,   738,   741,
     477,  1509,  1511,   742,   743,   564,   746,   744,   749,   607,
     608,   609,   610,   611,   612,   613,   614,   713,   616,   617,
     618,   619,   747,  1535,   579,   580,   620,   757,   760,   773,
     309,   309,   778,   309,   309,   309,   780,   309,   309,   309,
     309,   309,   309,   309,   781,   309,   309,   309,   150,   825,
     787,   821,   827,   849,   855,   856,   857,   889,   469,   929,
    1420,   899,   900,   901,   902,   909,   910,   911,   913,   917,
     620,   930,   927,   965,   966,   969,   980,   979,  1582,  1001,
    1003,  1583,  1584,   982,  1004,  1007,  1016,   755,   756,  1018,
    1029,  1032,   309,   477,   477,  1065,  1067,  1071,  1077,  1081,
    1082,  1086,  1087,   772,  1091,  1102,  1594,  1580,  1103,  1108,
    1119,  1121,  1124,  1132,  1134,  1137,  1142,  1138,  1143,  1144,
    1146,  1147,  1148,  1150,  1151,   309,  1152,  1153,  1154,  1613,
    1155,  1156,  1158,  1159,  1160,  1168,  1196,  1197,  1205,  1206,
    1207,   309,   309,   309,  1215,  1221,  1226,  1232,  1238,  1242,
    1254,  1246,  1262,  1255,  1288,  1256,  1633,  1264,  1276,  1303,
    1284,  1285,  1301,  1302,  1509,  1511,  1305,  1353,  1322,  1324,
    1650,  1325,  1326,  1331,  1340,  1341,  1356,  1656,  1342,  1822,
    1345,  1355,  1362,   463,  1366,  1367,  1368,  1369,  1372,  1373,
     309,  1374,  1378,  1391,   759,   469,   469,  1393,  1409,  1394,
    1415,  1416,  1417,   895,  1423,  1418,  1426,  1517,  1518,   309,
    1430,   309,   309,  1431,  1449,  1453,   794,  1467,  1486,  -210,
    1502,   633,  1519,   916,   309,  1520,  1521,  1524,  1525,   477,
    1527,   794,  1526,   477,  1528,  1529,  1531,  1532,  1543,  1224,
    1546,  1542,   477,  1547,   477,  1548,  1561,   477,  1563,  1562,
    1564,  1565,  1569,  1566,  1567,  1568,  1570,  1662,  1572,  1667,
     309,  1574,  1577,  2115,  1589,  1598,  1599,  1596,  1590,  1597,
    1610,  1601,  1605,   387,  1607,  1615,  1620,  1616,  1619,  1621,
    1626,  1628,  1630,  1632,  1629,  1645,  1647,  1653,  1654,  1585,
    1658,  1651,  1672,  1674,  1676,  1678,  1673,  1682,   477,  1683,
    1684,  1689,   463,   309,   463,   309,   463,   463,   463,  1690,
    1691,  1692,  1693,  1694,  1696,  1697,  1698,  1721,  1699,  1711,
    1700,  1716,  1717,   309,  1718,  1724,  1728,   463,   463,  1720,
    1737,  1743,  1744,  1750,  1751,  1752,   309,  1753,  1758,  1754,
     309,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   612,   613,   614,   713,   616,   617,   618,   619,  1759,
    1760,  1831,  1831,   620,  1761,  1581,  1766,  1820,  1641,  1767,
    1644,  1771,  1772,  1773,  1781,  1783,  1790,  1769,  1784,  1775,
    1814,  1873,  1817,  1841,  1843,  1850,  1810,  1967,  1851,  1854,
    1812,  1776,  1877,  1862,  1868,  1870,  1871,  1872,  1804,  1833,
    1878,  1853,  1809,  1083,  1794,  1797,   309,   309,   309,  1360,
     794,  1813,  1881,  1889,   309,   309,   309,  1816,  1882,  1838,
    1807,  1857,  1899,  1891,  1845,  1901,   794,  1904,  1886,  1234,
    1931,  1932,  1887,   309,  1888,  1897,  1898,  1933,  1905,  1954,
    1965,  1966,  1922,  1953,  1955,  1971,   809,  -596,   309,  -594,
    1983,  1984,  1985,  1986,  1987,  1991,  2002,  1995,  2000,   309,
    2003,   309,  2007,  2004,   463,   463,   463,   463,   463,   463,
     463,   463,   463,  2005,   463,   463,   463,   463,  2001,  2016,
     463,   463,   463,  1861,  2021,  2014,  2022,  1896,  2039,  2025,
     794,  2030,  2033,   794,  2031,     7,     8,  2037,  2042,   794,
    1869,  2034,  2040,   387,  2052,  2053,  2054,  2045,  2060,  2061,
    2063,   484,   484,  1774,  2064,  2065,  2068,   309,  2070,  2062,
    2071,  2095,  2076,  2067,  2118,  2119,  2123,  2129,  2130,  2131,
    2132,  2140,  2134,  2143,  -595,  1105,   477,  1107,  2144,  2162,
    2148,  2145,  2156,  2165,  2169,  2170,  2176,   309,  2157,  2178,
    2191,  2186,   309,  2196,   463,  2159,  2227,  2228,  2232,  2163,
    2249,  2254,  2167,  1961,  1970,   463,  2173,  2179,  2255,  2208,
    2217,  2258,  1241,  2259,  1649,  2202,   820,  1912,  1714,  2085,
    2057,  2229,   129,  2240,  2245,  1900,  1680,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
     139,   912,  1867,    45,    46,    47,    48,   140,   141,  1261,
     968,    50,  1408,  2113,  1806,  1944,   147,  1642,  1962,  1950,
     788,    58,  1949,  1952,    61,   789,  2133,   790,   791,  1832,
     792,     0,   309,  1126,     0,     0,     0,   309,   309,     0,
       0,  1963,     0,     0,     0,     0,     0,     0,    82,     0,
       0,     0,   469,   469,     0,     0,     0,     0,     0,     0,
       0,     0,   309,     0,     0,     0,     0,     0,     0,     0,
       0,   309,     0,     0,     0,    99,   100,   101,     0,     0,
       0,   477,     0,     0,   477,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     309,     0,  1908,  1909,  1388,     0,     0,     0,     0,     0,
       0,   387,     0,   309,   484,     0,     0,     0,     0,     0,
       0,     0,  1375,     0,     0,     0,   794,  1927,   794,   794,
       0,     0,     0,     0,     0,     0,     0,     0,  1395,     0,
       0,     0,   794,     0,     0,     0,     0,     0,     0,     0,
     484,     0,   814,     0,   794,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   465,     0,     0,     0,     0,
     475,   478,   479,     0,     0,     0,   794,     0,  2058,     0,
       0,     0,     0,     0,   309,   309,  1447,  1448,     0,  1450,
    1451,  1452,     0,  1454,  1455,  1456,  1457,  1458,  1459,  1460,
       0,  1463,  1464,  1465,     0,     0,     0,     0,     0,   309,
       0,     0,     0,     0,     0,   794,     0,     0,   511,   712,
       0,     0,  2089,     0,     0,  2121,     0,     0,   309,     0,
       0,     0,     0,     0,   525,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1479,  2019,
    2020,     0,     0,     0,     0,     0,     0,     0,   463,     0,
       0,     0,     0,     0,     0,     0,   309,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1503,   309,     0,     0,     0,     0,  2090,     0,     0,
     309,   309,     0,  2050,     0,     0,     0,  1516,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   309,     0,     0,   309,  2177,     0,     0,     0,
       0,     0,     0,     0,     0,   469,   309,     0,     0,     0,
    2160,     0,     0,     0,  2164,   309,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1559,     0,     0,     0,
     387,   463,   463,     0,     0,  2091,  2092,     0,  2200,     0,
       0,     0,     0,   309,     0,  1573,     0,  1575,  1576,     0,
    2185,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2114,  2192,     0,     0,     0,  2194,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   309,     0,     0,     0,
    2127,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1606,     0,     0,     0,
       0,     0,     0,   794,     0,   180,     0,   186,     0,     0,
       0,     0,     0,  2224,  2225,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   309,     0,   779,     0,     0,     0,
       0,     0,     0,     0,   751,   602,   603,   604,   605,   606,
     607,   608,   609,   610,   611,   612,   613,   614,   713,   616,
     617,   618,   619,   796,     0,     0,     0,   620,     0,  1666,
       0,     0,     0,     0,     0,     0,     0,   463,     0,     0,
       0,   463,  1681,   309,     0,     0,  1685,     0,     0,     0,
     463,     0,   463,     0,     0,   463,     0,     0,     0,  2190,
       0,     0,  1600,     0,     0,     0,   477,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   309,     0,     0,
       0,   477,   477,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   477,     0,   462,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   463,     0,     0,     0,
       0,     0,  1740,  1741,  1742,     0,     0,     0,     0,     0,
    1747,  1748,  1749,   892,     0,   894,     0,   896,   897,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1764,
       0,     0,     0,     0,     0,     0,     0,     0,   918,   919,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1780,     0,  1782,     0,     0,
       0,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   547,   548,   549,   550,   551,   554,   555,   556,
     557,   558,   559,     0,   561,   562,     0,     0,     0,     0,
       0,     0,     0,     0,   568,   569,     0,     0,     0,     0,
       0,     0,     0,  1837,     0,     0,     0,  1316,     0,     0,
     583,   584,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   614,   713,   616,   617,   618,   619,
       0,     0,     0,  1860,   620,     0,     0,     0,     0,   602,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   612,
     613,   614,   713,   616,   617,   618,   619,     0,     0,     0,
       0,   620,     0,     0,     0,     0,  1042,  1466,  1044,  1045,
    1046,  1047,  1048,  1049,     0,  1051,  1052,  1053,  1054,     0,
       0,  1059,  1060,  1061,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   463,
     463,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1903,     0,
     710,     0,   175,   399,   463,     0,     0,   719,   720,   721,
       0,     0,     0,   725,   726,   727,   728,   729,   730,   731,
       0,   732,     0,     0,     0,     0,   733,   734,     0,     0,
     737,     0,     0,     0,     0,  1125,     0,  1934,     0,     0,
       0,     0,     0,     0,     0,     0,  1135,     0,   400,   401,
     402,   403,   404,   405,   406,   407,   408,     0,     0,     0,
       0,   409,   410,   411,   412,     0,  1960,     0,     0,   413,
     414,   415,   416,     0,     0,     0,     0,     0,   417,  1969,
     418,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   419,     0,     0,   420,
       0,     0,     0,   181,     0,  1530,   182,     0,     0,   183,
       0,   184,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    48,   602,   603,   604,   605,   606,   607,   608,
     609,   610,   611,   612,   613,   614,   713,   616,   617,   618,
     619,  1560,     0,   449,     0,   620,     0,     0,     0,   463,
       0,     0,   463,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   794,     0,   794,     0,     0,
       0,     0,     0,     0,     0,  2038,     0,     0,     0,     0,
       0,     0,   463,   602,   603,   604,   605,   606,   607,   608,
     609,   610,   611,   612,   613,   614,   713,   616,   617,   618,
     619,     0,     0,     0,   928,   620,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   421,   422,   423,   463,     0,
       0,     0,     0,     0,     0,   395,     0,   424,     0,     0,
       0,   425,  2077,   426,   123,     0,     0,     0,   437,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2086,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   774,   464,   775,  1827,     0,   474,
       0,     0,     0,     0,   480,     0,     0,     0,  1837,     0,
       0,   485,     0,     0,   487,     0,     0,     0,     0,     0,
       0,     0,  2120,     0,     0,     0,     0,     0,     0,     0,
    1604,     0,     0,   496,   497,   498,     0,   500,   501,   502,
       0,   504,   505,   506,   507,   508,   509,   510,     0,   512,
     513,   514,   515,     0,     0,     0,     0,   519,     0,  1837,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1421,
       0,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   612,   613,   614,   713,   616,   617,   618,   619,     0,
       0,     0,  2161,   620,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   614,
     713,   616,   617,   618,   619,     0,     0,     0,     0,   620,
       0,     0,     0,     0,     0,     0,     0,   588,   590,   592,
     593,   519,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   627,   519,   519,     0,
       0,     0,  1480,  1481,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   645,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   655,   656,     0,     0,     0,  1837,
     656,     0,   519,   519,   670,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   794,     0,     0,     0,
       0,     0,     0,     0,     0,   689,   519,     0,     0,     0,
       0,     0,     0,  1837,     0,     0,   699,     0,   701,   702,
       0,   704,     0,     0,     0,   707,   708,   709,     0,     0,
     711,     0,     0,     0,   718,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1235,     0,   794,     0,     0,     0,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   612,   613,   614,   713,
     616,   617,   618,   619,     0,   794,   519,   753,   620,     0,
       0,     0,     0,  1252,     0,     0,     0,     0,  1586,     0,
       0,     0,  1588,   761,   762,     0,     0,     0,     0,     0,
       0,  1592,     0,  1593,   463,     0,  1595,     0,   795,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   463,
     463,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     826,     0,   463,     0,     0,   831,     0,     0,     0,   835,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   850,   590,     0,     0,  1635,   854,     0,
       0,     0,   858,   859,   860,   861,   862,   863,   864,   865,
     866,   867,   868,   869,   870,   871,   872,   873,   874,   875,
     877,   878,   879,   880,   881,   882,   883,   884,   885,   885,
       0,   890,   891,     0,   893,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   903,     0,     0,   907,   908,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     885,     0,     0,     0,     0,   519,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   931,   932,   933,
     934,   935,   936,   937,   938,   939,   940,   941,   942,   943,
     944,   946,   948,   949,   950,   951,   952,  1622,   954,   955,
    1435,     0,     0,     0,     0,     0,   962,   963,   964,     0,
       0,     0,     0,     0,   970,   971,   972,   973,     0,   519,
     519,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   588,   711,
     993,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1005,  1006,     0,  1008,     0,     0,  1010,     0,     0,     0,
     519,   519,   519,  1015,     0,     0,     0,  1019,   519,  1021,
    1022,  1023,     0,     0,  1024,     0,  1026,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1036,     0,     0,  1037,
       0,   954,   955,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1050,     0,  1504,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   519,     0,
       0,     0,     0,     0,     0,  1069,     0,     0,     0,     0,
       0,     0,     0,  1080,     0,  1852,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1762,     0,     0,     0,     0,
       0,     0,   519,     0,  1096,     0,     0,     0,     0,  1099,
    1100,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   519,  1811,  1116,  1117,     0,     0,
     519,     0,   519,  1123,     0,     0,     0,  1116,     0,  1130,
       0,  1131,     0,     0,     0,     0,     0,  1136,     0,     0,
       0,  1139,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   520,     0,     0,     0,     0,     0,     0,
    1157,     0,     0,     0,     0,  1161,     0,   946,     0,  1165,
       0,     0,     0,   602,   603,   604,   605,   606,   607,   608,
     609,   610,   611,   612,   613,   614,   713,   616,   617,   618,
     619,     0,     0,     0,     0,   620,     0,     0,     0,     0,
    1624,  1625,     0,     0,     0,   519,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   519,  1210,  1211,  1212,     0,
    1945,     0,     0,  1947,     0,  1218,  1219,  1220,     0,  1222,
     519,     0,     0,  1225,   591,     0,     0,   520,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   520,   520,     0,     0,     0,     0,     0,
       0,   519,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   519,     0,     0,     0,     0,     0,     0,
       0,  1260,     0,     0,     0,  1266,     0,     0,   520,   520,
       0,  1272,     0,     0,   519,     0,     0,     0,     0,     0,
       0,     0,  1282,  1283,     0,     0,  1725,     0,  1286,     0,
       0,     0,   520,     0,     0,  1732,     0,  1304,     0,     0,
    1306,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   612,   613,   614,   713,   616,   617,   618,   619,     0,
       0,     0,     0,   620,     0,     0,  1327,     0,  1329,  1330,
       0,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   612,   613,   614,   713,   616,   617,   618,   619,     0,
       0,  1351,     0,   620,     0,     0,     0,     0,     0,   175,
     399,     0,   520,     0,     0,     0,     0,     0,     0,     0,
       0,  1371,     0,     0,     0,     0,     0,     0,  1377,     0,
       0,     0,     0,     0,     0,  1390,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1413,  1414,
       0,     0,     0,     0,   519,   400,   401,   402,   403,   404,
     405,   406,   407,   408,     0,     0,     0,     0,   409,   410,
     411,   412,     0,     0,     0,     0,   413,   414,   415,   416,
       0,     0,     0,     0,     0,   417,  1444,   418,     0,     0,
     591,     0,     0,     0,  1815,     0,     0,     0,     0,     0,
       0,  1863,     0,   419,     0,     0,   420,     0,     0,     0,
     181,     0,     0,   182,     0,   876,   183,     0,   184,     0,
       0,     0,     0,     0,   886,   887,     0,  1469,     0,    48,
       0,     0,     0,     0,     0,     0,     0,  1470,  1471,  1472,
    1473,  1474,     0,     0,     0,     0,  1476,  1477,     0,  1478,
     449,  1821,     0,     0,     0,     0,   920,     0,     0,     0,
       0,   520,     0,     0,     0,     0,     0,  1491,     0,     0,
       0,     0,  1496,  1497,     0,     0,     0,     0,     0,     0,
    1500,  1501,     0,     0,     0,     0,     0,   947,     0,  1505,
    1506,  1929,     0,     0,     0,  1512,  1513,     0,     0,     0,
       0,   519,   519,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   520,   520,     0,     0,     0,
       0,     0,   421,   422,   423,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   424,     0,  1545,     0,   425,     0,
     426,   123,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   520,   520,   520,     0,
       0,     0,     0,     0,   520,     0,  1571,   455,   456,     0,
       0,     0,     0,     0,  -590,     0,  1634,     0,  1512,  1513,
       0,     0,     0,   519,     0,  2238,     0,     0,     0,     0,
       0,  1587,     0,     0,     0,     0,     0,     0,     0,     0,
    2250,  2252,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2260,   520,  1603,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1609,     0,     0,  1614,
     602,   603,   604,   605,   606,   607,   608,   609,   610,   611,
     612,   613,   614,   713,   616,   617,   618,   619,   520,     0,
       0,     0,   620,     0,     0,     0,     0,     0,  1636,     0,
       0,  1639,   519,  1643,   519,     0,     0,     0,     0,     0,
     520,     0,  1652,     0,     0,  1655,   520,  1652,   520,  1659,
    1661,     0,     0,  1669,  1670,  1671,     0,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   614,
     713,   616,   617,   618,   619,     0,     0,     0,  1695,   620,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   947,     0,  1166,     0,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   614,
     713,   616,   617,   618,   619,     0,     0,     0,     0,   620,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   520,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   520,  1746,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1755,  1756,  1757,   520,     0,     0,     0,
       0,     0,  1763,     0,  1765,     0,     0,     0,     0,     0,
       0,  1768,     0,     0,     0,     0,     0,   519,     0,     0,
       0,   175,   399,  1777,  1778,     0,     0,   520,     0,     0,
       0,     0,     0,     0,  1785,  1786,  1787,     0,     0,   520,
       0,     0,     0,     0,     0,  1798,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1808,     0,     0,     0,     0,
     520,     0,     0,     0,     0,     0,     0,   400,   401,   402,
     403,   404,   405,   406,   407,   408,  1825,     0,     0,     0,
     409,   410,   411,   412,  1834,  1835,     0,     0,   413,   414,
     415,   416,     0,     0,     0,     0,     0,   417,     0,   418,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   419,     0,     0,   420,     0,
       0,  1865,   181,     0,     0,   182,     0,     0,   183,     0,
     184,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    48,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   449,  1930,  1883,  1884,  1885,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1890,     0,     0,     0,     0,  1893,  1894,     0,     0,
     520,     0,     0,     0,     0,     0,     0,     0,     0,  1902,
    2029,     0,     0,     0,     0,     0,   519,   519,  1910,     0,
    1911,     0,     0,     0,     0,     0,  1919,  1920,     0,     0,
       0,     0,     0,     0,     0,  1522,     0,     0,     0,     0,
       0,   519,  1928,     0,   421,   422,   423,     0,     0,     0,
       0,     0,     0,     0,  1893,  1894,   424,     0,  1942,     0,
     425,  1946,   426,   123,     0,  1948,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1957,     0,     0,     0,  2051,
     777,     0,     0,     0,     0,  1964,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1827,     0,     0,  1975,
       0,     0,     0,     0,  1981,  1982,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1988,
       0,     0,  1989,  1988,     0,  1992,     0,     0,   602,   603,
     604,   605,   606,   607,   608,   609,   610,   611,   612,   613,
     614,   713,   616,   617,   618,   619,  2006,   520,   520,  2066,
     620,     0,  2011,  2012,  2013,     0,     0,     0,     0,     0,
       0,     0,     0,   519,   519,     0,     0,     0,     0,     0,
    2023,  2024,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2032,     0,     0,     0,     0,   904,     0,     0,
       0,  2041,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2046,  2047,     0,     0,   711,   519,     0,   602,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   612,
     613,   614,   713,   616,   617,   618,   619,     0,     0,   520,
       0,   620,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2074,  2075,   958,     0,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   612,   613,   614,   713,
     616,   617,   618,   619,  2088,     0,     0,     0,   620,   519,
     519,  2093,     0,     0,     0,     0,  2096,     0,     0,     0,
    2100,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   519,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   520,     0,
     520,  2124,     0,     0,   519,   602,   603,   604,   605,   606,
     607,   608,   609,   610,   611,   612,   613,   614,   713,   616,
     617,   618,   619,  2104,     0,     0,     0,   620,     0,  2136,
       0,     0,     0,     0,     0,  2141,     0,     0,  2142,     0,
       0,     0,     0,     0,     0,     0,  2105,     0,     0,     0,
       0,     0,     0,  2153,     0,  2154,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2174,
       0,     0,     0,  2168,     0,   602,   603,   604,   605,   606,
     607,   608,   609,   610,   611,   612,   613,   614,   713,   616,
     617,   618,   619,  2180,  2181,     0,     0,   620,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2187,     0,
       0,     0,     0,   519,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2198,     0,     0,     0,
       0,     0,     0,     0,     0,  1981,     0,     0,     0,  2207,
       0,     0,     0,   520,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2220,     0,     0,     0,     0,  2223,  1169,  1170,  1171,  1172,
    1173,  1174,  1175,  1176,  1177,  1178,  1179,  1180,     0,  1182,
    1183,  1184,  1185,     0,  1187,  1188,  1189,  1190,     0,     0,
    2241,  2242,     0,     0,     0,     0,     0,     0,     0,     0,
    1202,     0,  1204,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1214,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1228,  1229,     0,
       0,     0,     0,     0,     0,     0,  1240,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1866,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   602,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   612,
     613,   614,   713,   616,   617,   618,   619,     0,     0,     0,
       0,   620,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   614,   713,   616,   617,   618,   619,
       0,     0,     0,     0,   620,   602,   603,   604,   605,   606,
     607,   608,   609,   610,   611,   612,   613,   614,   713,   616,
     617,   618,   619,     0,     0,     0,     0,   620,     0,     0,
       0,     0,   520,   520,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1336,
    1338,  1339,     0,     0,     0,  1343,  1344,   520,     0,  1347,
    1348,  1349,  1350,     0,  1352,     0,     0,     0,     0,  1358,
       0,     0,     0,     0,     0,     0,   219,     6,   368,     0,
       0,     0,     0,   220,   221,   222,     0,     0,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   255,   256,   257,   258,     0,     0,     0,     0,
     259,   260,     0,     0,     0,     0,     0,  1443,     0,  1445,
     261,   262,   263,     0,     0,     0,   264,   265,   266,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   267,
      27,     0,   268,     0,     0,     0,     0,     0,   269,   520,
     520,   270,     0,     0,   271,     0,   272,     0,     0,     0,
       0,     0,     0,    44,     0,     0,     0,   273,   274,   275,
       0,     0,   276,     0,     0,     0,     0,     0,     0,     0,
       0,   277,     0,    59,    60,     0,   278,     0,   279,     0,
       0,   280,     0,   520,     0,     0,     0,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,     0,
       0,     0,    85,     0,     0,     0,    89,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1514,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   281,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   520,   520,     0,  2213,   282,
       0,     0,     0,   283,   284,     0,     0,     0,     0,   285,
     286,   287,     0,   288,   289,   290,     0,     0,     0,   123,
     520,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   291,   292,     0,     0,
     520,     0,     0,   293,     0,     0,     0,     0,   369,     0,
       0,     0,   370,     0,     0,   296,     0,     0,     0,     0,
       0,     0,     0,     0,   219,   175,   399,     0,   448,     0,
       0,   220,   221,   222,     0,     0,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   393,   242,   243,   244,   245,   246,
     247,   248,   249,     0,     0,     0,     0,     0,     0,     0,
    1623,   400,   401,   402,   403,   404,   405,   406,   407,   408,
     255,   256,   257,   258,   409,   410,   411,   412,   259,     0,
       0,     0,   413,   414,   415,   416,     0,     0,     0,     0,
       0,   417,     0,   418,   264,   265,   266,     0,     0,   520,
       0,     0,     0,  1663,     0,     0,     0,   267,    27,   419,
     268,     0,   420,     0,     0,     0,   181,     0,     0,   182,
       0,     0,   183,     0,   184,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    48,     0,  1701,  1702,  1703,
    1704,  1705,  1706,  1707,     0,     0,     0,     0,  1712,  1713,
       0,     0,     0,     0,     0,  1715,   449,     0,     0,     0,
       0,     0,     0,     0,     0,  1723,     0,     0,     0,  1727,
       0,     0,  1729,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1736,   602,   603,   604,   605,   606,   607,
     608,   609,   610,   611,   612,   613,   614,   713,   616,   617,
     618,   619,     0,     0,     0,     0,   620,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     450,     0,     0,     0,  1999,   601,     0,   282,   421,   422,
     423,   283,     0,     0,     0,     0,     0,   285,   286,   287,
     424,   288,   289,   290,   425,     0,   426,   123,     0,   451,
     452,   453,   454,  1793,     0,  1796,     0,     0,     0,  1803,
       0,  1805,     0,     0,   291,   394,     0,     0,     0,     0,
       0,   293,     0,   455,   456,     0,   457,     0,   458,     0,
       0,     0,   459,   296,     0,     0,     0,     0,   219,     6,
     399,     0,  1828,   690,     0,   220,   221,   222,     0,     0,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,  2147,     0,     0,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   255,   256,   257,   258,   409,   410,
     411,   412,   259,   260,     0,     0,   413,   414,   415,   416,
     601,     0,   261,   262,   263,   417,     0,   418,   264,   265,
     266,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   267,    27,   419,   268,     0,   420,     0,     0,     0,
     269,     0,     0,   270,     0,     0,   271,     0,   272,     0,
    1895,     0,     0,     0,     0,    44,     0,     0,     0,   273,
     274,   275,     0,     0,   276,     0,     0,     0,     0,     0,
       0,     0,     0,   277,     0,    59,    60,     0,   278,     0,
     279,     0,     0,   280,     0,     0,     0,     0,     0,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,     0,     0,     0,    85,     0,     0,     0,    89,   602,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   612,
     613,   614,   851,   616,   617,   618,   619,     0,     0,     0,
       0,   620,     0,   281,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1972,     0,     0,
    1973,   282,   421,   422,   423,   283,   284,     0,     0,     0,
       0,   285,   286,   287,   424,   288,   289,   290,   425,     0,
     426,   123,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   291,   518,
       0,     0,     0,     0,     0,   293,     0,     0,     0,     0,
     369,  2008,  2009,     0,     0,   594,   601,   296,  2015,     0,
       0,     0,     0,     0,     0,     0,     0,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   614,
     713,   616,   617,   618,   619,     0,     0,     0,     0,   620,
       0,     0,     0,     0,   602,   603,   604,   605,   606,   607,
     608,   609,   610,   611,   612,   613,   614,   615,   616,   617,
     618,   619,     0,     0,  2055,  2056,   620,     0,   219,     6,
     399,     0,     0,  1640,     0,   220,   221,   222,     0,     0,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,     0,     0,  2087,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   255,   256,   257,   258,   409,   410,
     411,   412,   259,   260,     0,     0,   413,   414,   415,   416,
       0,     0,   261,   262,   263,   417,     0,   418,   264,   265,
     266,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   267,    27,   419,   268,     0,   420,     0,     0,     0,
     269,     0,     0,   270,     0,     0,   271,     0,   272,     0,
       0,     0,     0,     0,     0,    44,     0,     0,     0,   273,
     274,   275,     0,     0,   276,     0,     0,     0,     0,     0,
       0,     0,     0,   277,     0,    59,    60,     0,   278,     0,
     279,     0,     0,   280,     0,     0,     0,     0,     0,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,     0,     0,     0,    85,     0,     0,     0,    89,     0,
     602,   603,   604,   605,   606,   607,   608,   609,   610,   611,
     612,   613,   614,   851,   616,   617,   618,   619,     0,     0,
       0,     0,   620,   281,     0,     0,     0,     0,  1033,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   282,   421,   422,   423,   283,   284,     0,     0,     0,
       0,   285,   286,   287,   424,   288,   289,   290,   425,     0,
     426,   123,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   291,   518,
       0,     0,     0,     0,     0,   293,     0,     0,     0,     0,
     369,   219,     6,   399,     0,     0,     0,   296,   220,   221,
     222,  2233,     0,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,     0,     0,     0,  1664,   401,
     402,   403,   404,   405,   406,   407,   408,   255,   256,   257,
     258,   409,   410,   411,   412,   259,   260,     0,     0,   413,
     414,   415,   416,     0,     0,   261,   262,   263,   417,     0,
     418,   264,   265,   266,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   267,    27,   419,   268,     0,   420,
       0,     0,     0,   269,     0,     0,   270,     0,     0,   271,
       0,   272,     0,     0,     0,     0,     0,     0,    44,     0,
       0,     0,   273,   274,   275,     0,     0,   276,     0,     0,
       0,     0,     0,     0,     0,     0,   277,     0,    59,    60,
       0,   278,     0,   279,     0,     0,   280,     0,     0,     0,
       0,     0,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,     0,     0,     0,    85,     0,     0,
       0,    89,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   614,   713,   616,   617,   618,   619,
       0,     0,     0,     0,   620,     0,   281,     0,     0,     0,
       0,  1243,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   282,   421,   422,   423,   283,   284,
       0,     0,     0,     0,   285,   286,   287,   424,   288,   289,
     290,   425,     0,   426,   123,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   291,   292,     0,     0,     0,     0,     0,   293,     0,
       0,     0,     0,   369,   219,     6,   399,  1665,     0,     0,
     296,   220,   221,   222,     0,     0,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,     0,     0,
       0,   400,   401,   402,   403,   404,   405,   406,   407,   408,
     255,   256,   257,   258,   409,   410,   411,   412,   259,   260,
       0,     0,   413,   414,   415,   416,     0,     0,   261,   262,
     263,   417,     0,   418,   264,   265,   266,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   267,    27,   419,
     268,     0,   420,     0,     0,     0,   269,     0,     0,   270,
       0,     0,   271,     0,   272,     0,     0,     0,     0,     0,
       0,    44,     0,     0,     0,   273,   274,   275,     0,     0,
     276,     0,     0,     0,     0,     0,     0,     0,     0,   277,
       0,    59,    60,     0,   278,     0,   279,     0,     0,   280,
       0,     0,     0,     0,     0,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,     0,     0,     0,
      85,     0,     0,     0,    89,   602,   603,   604,   605,   606,
     607,   608,   609,   610,   611,   612,   613,   614,   713,   616,
     617,   618,   619,     0,     0,     0,     0,   620,     0,   281,
       0,     0,     0,     0,  1244,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   282,   421,   422,
     423,   283,   284,     0,     0,     0,     0,   285,   286,   287,
     424,   288,   289,   290,   425,     0,   426,   123,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   291,   292,     0,     0,     0,     0,
       0,   293,     0,     0,     0,     0,   369,   219,     6,     0,
     295,     0,   690,   296,   220,   221,   222,     0,     0,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   255,   256,   257,   258,     0,     0,     0,
       0,   259,   260,     0,     0,     0,     0,     0,     0,     0,
       0,   261,   262,   263,     0,     0,     0,   264,   265,   266,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     267,    27,     0,   268,     0,     0,     0,     0,     0,   269,
       0,     0,   270,     0,     0,   271,     0,   272,     0,     0,
       0,     0,     0,     0,    44,     0,     0,     0,   273,   274,
     275,     0,     0,   276,     0,     0,     0,     0,     0,     0,
       0,     0,   277,     0,    59,    60,     0,   278,     0,   279,
       0,     0,   280,     0,     0,     0,     0,     0,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
       0,     0,     0,    85,     0,     0,     0,    89,   602,   603,
     604,   605,   606,   607,   608,   609,   610,   611,   612,   613,
     614,   713,   616,   617,   618,   619,     0,     0,     0,     0,
     620,     0,   281,     0,     0,     0,     0,  1579,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     282,     0,     0,     0,   283,   284,     0,     0,     0,     0,
     285,   286,   287,     0,   288,   289,   290,     0,     0,     0,
     123,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   291,   518,     0,
       0,     0,     0,     0,   293,     0,     0,     0,     0,   369,
     219,     6,   368,     0,   594,     0,   296,   220,   221,   222,
       0,     0,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   255,   256,   257,   258,
       0,     0,     0,     0,   259,   260,     0,     0,     0,     0,
       0,     0,     0,     0,   261,   262,   263,     0,     0,     0,
     264,   265,   266,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   267,    27,     0,   268,     0,     0,     0,
       0,     0,   269,     0,     0,   270,     0,     0,   271,     0,
     272,     0,     0,     0,     0,     0,     0,    44,     0,     0,
       0,   273,   274,   275,     0,     0,   276,     0,     0,     0,
       0,     0,     0,     0,     0,   277,     0,    59,    60,     0,
     278,     0,   279,     0,     0,   280,     0,     0,     0,     0,
       0,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,     0,     0,     0,    85,     0,     0,     0,
      89,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   612,   613,   614,   713,   616,   617,   618,   619,     0,
       0,     0,     0,   620,     0,   281,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   282,     0,     0,     0,   283,   284,     0,
       0,     0,     0,   285,   286,   287,     0,   288,   289,   290,
       0,     0,     0,   123,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     291,   292,     0,     0,     0,     0,     0,   293,     0,     0,
       0,     0,   369,   219,     6,     0,   914,     0,     0,   296,
     220,   221,   222,     0,     0,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   255,
     256,   257,   258,     0,     0,     0,     0,   259,   260,     0,
       0,     0,     0,     0,     0,     0,     0,   261,   262,   263,
       0,     0,     0,   264,   265,   266,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   267,    27,     0,   268,
       0,     0,     0,     0,     0,   269,     0,     0,   270,     0,
       0,   271,     0,   272,     0,     0,     0,     0,     0,     0,
      44,     0,     0,     0,   273,   274,   275,     0,     0,   276,
       0,     0,     0,     0,     0,     0,     0,     0,   277,     0,
      59,    60,   399,   278,     0,   279,     0,     0,   280,     0,
       0,     0,     0,     0,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,     0,     0,     0,    85,
       0,     0,     0,    89,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   400,   401,   402,
     403,   404,   405,   406,   407,   408,     0,     0,   281,     0,
     409,   410,   411,   412,     0,     0,     0,     0,   413,   414,
     415,   416,     0,     0,     0,     0,   282,   417,     0,   418,
     283,   284,     0,     0,     0,     0,   285,   286,   287,     0,
     288,   289,   290,     0,     0,   419,   123,     0,   420,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   291,   292,     0,     0,     0,     0,     0,
     293,     0,     0,     0,     0,   294,   219,     6,     0,   295,
       0,     0,   296,   220,   221,   222,     0,     0,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   255,   256,   257,   258,     0,     0,     0,     0,
     259,   260,     0,     0,     0,     0,     0,     0,     0,     0,
     261,   262,   263,     0,     0,     0,   264,   265,   266,     0,
       0,     0,     0,     0,   421,   422,   423,     0,     0,   267,
      27,     0,   268,     0,     0,     0,   424,     0,   269,     0,
     425,   270,   426,     0,   271,     0,   272,     0,     0,     0,
       0,     0,     0,    44,     0,     0,     0,   273,   274,   275,
       0,     0,   276,     0,     0,     0,     0,     0,     0,     0,
       0,   277,     0,    59,    60,     0,   278,     0,   279,     0,
       0,   280,     0,     0,     0,     0,     0,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,     0,
       0,     0,    85,     0,     0,     0,    89,     0,   602,   603,
     604,   605,   606,   607,   608,   609,   610,   611,   612,   613,
     614,   713,   616,   617,   618,   619,     0,     0,     0,     0,
     620,   281,   774,     0,   775,     0,     0,     0,     0,     0,
    1795,     0,     0,     0,     0,     0,     0,     0,     0,   282,
       0,     0,     0,   283,   284,     0,     0,     0,     0,   285,
     286,   287,     0,   288,   289,   290,     0,     0,     0,   123,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   291,   292,     0,     0,
       0,     0,     0,   293,     0,     0,     0,     0,   369,   219,
       6,     0,   295,     0,     0,   296,   220,   221,   222,     0,
       0,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   255,   256,   257,   258,     0,
       0,     0,     0,   259,   260,     0,     0,     0,     0,     0,
       0,     0,     0,   261,   262,   263,     0,     0,     0,   264,
     265,   266,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   267,    27,     0,   268,     0,     0,     0,     0,
       0,   269,     0,     0,   270,     0,     0,   271,     0,   272,
       0,     0,     0,     0,     0,     0,    44,     0,     0,     0,
     273,   274,   275,     0,     0,   276,     0,     0,     0,     0,
       0,     0,     0,     0,   277,     0,    59,    60,     0,   278,
       0,   279,     0,     0,   280,     0,     0,     0,     0,     0,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,     0,     0,     0,    85,     0,     0,     0,    89,
       0,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   612,   613,   614,   713,   616,   617,   618,   619,     0,
       0,     0,     0,   620,   281,  1017,     0,     0,     0,     0,
       0,     0,     0,   986,     0,     0,     0,     0,     0,     0,
       0,     0,   282,     0,     0,     0,   283,   284,     0,     0,
       0,     0,   285,   286,   287,     0,   288,   289,   290,     0,
       0,     0,   123,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   291,
     518,     0,     0,     0,     0,     0,   293,     0,     0,     0,
       0,   369,   219,     6,     0,   589,     0,     0,   296,   220,
     221,   222,     0,     0,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   255,   256,
     257,   258,     0,     0,     0,     0,   259,   260,     0,     0,
       0,     0,     0,     0,     0,     0,   261,   262,   263,     0,
       0,     0,   264,   265,   266,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   267,    27,     0,   268,     0,
       0,     0,     0,     0,   269,     0,     0,   270,     0,     0,
     271,     0,   272,     0,     0,     0,     0,     0,     0,    44,
       0,     0,     0,   273,   274,   275,     0,     0,   276,     0,
       0,     0,     0,     0,     0,     0,     0,   277,     0,    59,
      60,     0,   278,     0,   279,     0,     0,   280,     0,     0,
       0,     0,     0,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,     0,     0,     0,    85,     0,
       0,     0,    89,     0,   602,   603,   604,   605,   606,   607,
     608,   609,   610,   611,   612,   613,   614,   713,   616,   617,
     618,   619,     0,     0,     0,     0,   620,   281,  1461,     0,
       0,     0,     0,     0,     0,     0,  1462,     0,     0,     0,
       0,     0,     0,     0,     0,   282,     0,     0,     0,   283,
     284,     0,     0,     0,     0,   285,   286,   287,     0,   288,
     289,   290,     0,     0,     0,   123,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   291,   518,     0,     0,     0,     0,     0,   293,
       0,     0,     0,     0,   369,   219,     6,     0,     0,   594,
       0,   296,   220,   221,   222,     0,     0,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   255,   256,   257,   258,     0,     0,     0,     0,   259,
     260,     0,     0,     0,     0,     0,     0,     0,     0,   261,
     262,   263,     0,     0,     0,   264,   265,   266,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   267,    27,
       0,   268,     0,     0,     0,     0,     0,   269,     0,     0,
     270,     0,     0,   271,     0,   272,     0,     0,     0,     0,
       0,     0,    44,     0,     0,     0,   273,   274,   275,     0,
       0,   276,     0,     0,     0,     0,     0,     0,     0,     0,
     277,     0,    59,    60,     0,   278,     0,   279,     0,     0,
     280,     0,     0,     0,     0,     0,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,     0,     0,
       0,    85,     0,     0,     0,    89,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   612,   613,   614,   713,
     616,   617,   618,   619,     0,     0,     0,     0,   620,     0,
     281,     0,     0,     0,  1858,     0,     0,     0,  1859,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   282,     0,
       0,     0,   283,   284,     0,     0,     0,     0,   285,   286,
     287,     0,   288,   289,   290,     0,     0,     0,   123,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   291,   292,     0,     0,     0,
       0,     0,   293,     0,     0,     0,     0,   632,   219,     6,
       0,   295,     0,     0,   296,   220,   221,   222,     0,     0,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   255,   256,   257,   258,     0,     0,
       0,     0,   259,   260,     0,     0,     0,     0,     0,     0,
       0,     0,   261,   262,   263,     0,     0,     0,   264,   265,
     266,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   267,    27,     0,   268,     0,     0,     0,     0,     0,
     269,     0,     0,   270,     0,     0,   271,     0,   272,     0,
       0,     0,     0,     0,     0,    44,     0,     0,     0,   273,
     274,   275,     0,     0,   276,     0,     0,     0,     0,     0,
       0,     0,     0,   277,     0,    59,    60,     0,   278,     0,
     279,     0,     0,   280,     0,     0,     0,     0,     0,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,     0,     0,     0,    85,     0,     0,     0,    89,     0,
     602,   603,   604,   605,   606,   607,   608,   609,   610,   611,
     612,   613,   614,   713,   616,   617,   618,   619,     0,     0,
       0,     0,   620,   281,  1879,     0,     0,     0,     0,     0,
       0,     0,  1880,     0,     0,     0,     0,     0,     0,     0,
       0,   282,     0,     0,     0,   283,   284,     0,     0,     0,
       0,   285,   286,   287,     0,   288,   289,   290,     0,     0,
       0,   123,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   291,   292,
       0,     0,     0,     0,     0,   293,     0,     0,     0,     0,
     641,   219,     6,     0,   295,     0,     0,   296,   220,   221,
     222,     0,     0,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   255,   256,   257,
     258,     0,     0,     0,     0,   259,   260,     0,     0,     0,
       0,     0,     0,     0,     0,   261,   262,   263,     0,     0,
       0,   264,   265,   266,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   267,    27,     0,   268,     0,     0,
       0,     0,     0,   269,     0,     0,   270,     0,     0,   271,
       0,   272,     0,     0,     0,     0,     0,     0,    44,     0,
       0,     0,   273,   274,   275,     0,     0,   276,     0,     0,
       0,     0,     0,     0,     0,     0,   277,     0,    59,    60,
       0,   278,     0,   279,     0,     0,   280,     0,     0,     0,
       0,     0,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,     0,     0,     0,    85,     0,     0,
       0,    89,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   614,   713,   616,   617,   618,   619,
       0,     0,     0,     0,   620,     0,   281,     0,     0,     0,
    1915,     0,     0,     0,  1916,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   282,     0,     0,     0,   283,   284,
       0,     0,     0,     0,   285,   286,   287,     0,   288,   289,
     290,     0,     0,     0,   123,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   291,   518,     0,     0,     0,     0,     0,   293,     0,
       0,     0,     0,   369,   219,     6,     0,   945,     0,  1419,
     296,   220,   221,   222,     0,     0,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     255,   256,   257,   258,     0,     0,     0,     0,   259,   260,
       0,     0,     0,     0,     0,     0,     0,     0,   261,   262,
     263,     0,     0,     0,   264,   265,   266,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   267,    27,     0,
     268,     0,     0,     0,     0,     0,   269,     0,     0,   270,
       0,     0,   271,     0,   272,     0,     0,     0,     0,     0,
       0,    44,     0,     0,     0,   273,   274,   275,     0,     0,
     276,     0,     0,     0,     0,     0,     0,     0,     0,   277,
       0,    59,    60,     0,   278,     0,   279,     0,     0,   280,
       0,     0,     0,     0,     0,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,     0,     0,     0,
      85,     0,     0,     0,    89,   602,   603,   604,   605,   606,
     607,   608,   609,   610,   611,   612,   613,   614,   713,   616,
     617,   618,   619,     0,     0,     0,     0,   620,     0,   281,
       0,     0,     0,  1935,     0,     0,     0,  1936,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   282,     0,     0,
       0,   283,   284,     0,     0,     0,     0,   285,   286,   287,
       0,   288,   289,   290,     0,     0,     0,   123,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   291,   518,     0,     0,     0,     0,
       0,   293,   219,     6,     0,     0,   369,     0,     0,   220,
     221,   222,     0,   296,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   255,   256,
     257,   258,     0,     0,     0,     0,   259,   260,     0,     0,
       0,     0,     0,     0,     0,     0,   261,   262,   263,     0,
       0,     0,   264,   265,   266,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   267,    27,     0,   268,     0,
       0,     0,     0,     0,   269,     0,     0,   270,     0,     0,
     271,     0,   272,     0,     0,     0,     0,     0,     0,    44,
       0,     0,     0,   273,   274,   275,     0,     0,   276,     0,
       0,     0,     0,     0,     0,     0,     0,   277,     0,    59,
      60,     0,   278,     0,   279,     0,     0,   280,     0,     0,
       0,     0,     0,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,     0,     0,     0,    85,     0,
       0,     0,    89,   602,   603,   604,   605,   606,   607,   608,
     609,   610,   611,   612,   613,   614,   713,   616,   617,   618,
     619,     0,     0,     0,     0,   620,     0,   281,     0,     0,
       0,  2116,     0,     0,     0,  2117,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   282,     0,     0,     0,   283,
     284,     0,     0,     0,     0,   285,   286,   287,     0,   288,
     289,   290,     0,     0,     0,   123,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   291,   518,     0,     0,     0,     0,     0,   293,
       0,     0,     0,     0,   369,   219,     6,     0,     0,  2049,
       0,   296,   220,   221,   222,     0,     0,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   255,   256,   257,   258,     0,     0,     0,     0,   259,
     260,     0,     0,     0,     0,     0,     0,     0,     0,   261,
     262,   263,     0,     0,     0,   264,   265,   266,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   267,    27,
       0,   268,     0,     0,     0,     0,     0,   269,     0,     0,
     270,     0,     0,   271,     0,   272,     0,     0,     0,     0,
       0,     0,    44,     0,     0,     0,   273,   274,   275,     0,
       0,   276,     0,     0,     0,     0,     0,     0,     0,     0,
     277,     0,    59,    60,     0,   278,     0,   279,     0,     0,
     280,     0,     0,     0,     0,     0,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,     0,     0,
       0,    85,     0,     0,     0,    89,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   612,   613,   614,   713,
     616,   617,   618,   619,     0,     0,     0,     0,   620,     0,
     281,     0,     0,     0,     0,     0,     0,     0,   807,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   282,     0,
       0,     0,   283,   284,     0,     0,     0,     0,   285,   286,
     287,     0,   288,   289,   290,     0,     0,     0,   123,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   291,   518,     0,     0,     0,
       0,     0,   293,   219,   175,   399,     0,   369,     0,     0,
     220,   221,   222,     0,   296,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   393,   242,   243,   244,   245,   246,   247,
     248,   249,     0,     0,     0,     0,     0,     0,     0,     0,
     400,   401,   402,   403,   404,   405,   406,   407,   408,   255,
     256,   257,   258,   409,   410,   411,   412,   259,     0,     0,
       0,   413,   414,   415,   416,     0,     0,     0,     0,     0,
     417,     0,   418,   264,   265,   266,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   267,    27,   419,   268,
       0,   420,   219,   175,   399,     0,     0,     0,     0,   220,
     221,   222,     0,     0,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   393,   242,   243,   244,   245,   246,   247,   248,
     249,     0,     0,     0,     0,     0,     0,     0,     0,   400,
     401,   402,   403,   404,   405,   406,   407,   408,   255,   256,
     257,   258,   409,   410,   411,   412,   259,     0,     0,     0,
     413,   414,   415,   416,     0,     0,     0,     0,     0,   417,
       0,   418,   264,   265,   266,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   267,    27,   419,   268,     0,
     420,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   282,   421,   422,   423,
     283,     0,     0,     0,     0,     0,   285,   286,   287,   424,
     288,   289,   290,   425,     0,   426,   123,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   291,   394,     0,     0,     0,     0,     0,
     293,     0,     0,     0,     0,   369,     0,     0,     0,  1660,
       0,     0,   296,   602,   603,   604,   605,   606,   607,   608,
     609,   610,   611,   612,   613,   614,   713,   616,   617,   618,
     619,     0,     0,     0,     0,   620,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   813,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   282,   421,   422,   423,   283,
       0,     0,     0,     0,     0,   285,   286,   287,   424,   288,
     289,   290,   425,     0,   426,   123,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   291,  1940,     0,     0,     0,     0,     0,   293,
       0,     0,     0,     0,   369,   219,   175,   399,  1941,     0,
       0,   296,   220,   221,   222,     0,     0,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   393,   242,   243,   244,   245,
     246,   247,   248,   249,     0,     0,     0,     0,     0,     0,
       0,     0,  1664,   401,   402,   403,   404,   405,   406,   407,
     408,   255,   256,   257,   258,   409,   410,   411,   412,   259,
       0,     0,     0,   413,   414,   415,   416,     0,     0,     0,
       0,     0,   417,     0,   418,   264,   265,   266,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   267,    27,
     419,   268,     0,   420,   219,   175,   399,     0,     0,     0,
       0,   220,   221,   222,     0,     0,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   393,   242,   243,   244,   245,   246,
     247,   248,   249,     0,     0,     0,     0,     0,     0,     0,
       0,   400,   401,   402,   403,   404,   405,   406,   407,   408,
     255,   256,   257,   258,   409,   410,   411,   412,   259,     0,
       0,     0,   413,   414,   415,   416,     0,     0,     0,     0,
       0,   417,     0,   418,   264,   265,   266,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   267,    27,   419,
     268,     0,   420,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   282,   421,
     422,   423,   283,     0,     0,     0,     0,     0,   285,   286,
     287,   424,   288,   289,   290,   425,     0,   426,   123,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   291,   394,     0,     0,     0,
       0,     0,   293,     0,     0,     0,     0,   369,     0,     0,
       0,  1827,     0,     0,   296,   602,   603,   604,   605,   606,
     607,   608,   609,   610,   611,   612,   613,   614,   713,   616,
     617,   618,   619,     0,     0,     0,     0,   620,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   815,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   282,   421,   422,
     423,   283,     0,     0,     0,     0,     0,   285,   286,   287,
     424,   288,   289,   290,   425,     0,   426,   123,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   291,   394,     0,     0,     0,     0,
       0,   293,   219,   175,     0,   392,   369,     0,     0,   220,
     221,   222,     0,   296,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   393,   242,   243,   244,   245,   246,   247,   248,
     249,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   255,   256,
     257,   258,     0,     0,     0,     0,   259,     7,     8,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   264,   265,   266,     0,     0,     0,     0,     0,
       0,     0,   219,   175,     0,   267,    27,     0,   268,   220,
     221,   222,     0,     0,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   393,   242,   243,   244,   245,   246,   247,   248,
     249,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   255,   256,
     257,   258,     0,     0,     0,     0,   259,     0,     0,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,   264,   265,   266,    45,    46,    47,    48,     0,
       0,     0,     0,    50,     0,   267,    27,     0,   268,     0,
       0,     0,   788,    58,     0,     0,    61,   789,     0,   790,
     791,     0,   792,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   282,     0,     0,     0,   283,
      82,     0,     0,     0,     0,   285,   286,   287,     0,   288,
     289,   290,     0,     0,     0,   123,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    99,   100,   101,
       0,     0,   291,   394,     0,     0,     0,     0,     0,   293,
       0,     0,     0,     0,   369,     0,     0,     0,     0,     0,
       0,   296,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   614,   713,   616,   617,   618,   619,
       0,     0,     0,     0,   620,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   986,   282,     0,     0,     0,   283,
       0,     0,     0,     0,     0,   285,   286,   287,     0,   288,
     289,   290,     0,     0,   994,   123,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   291,   394,     0,     0,     0,     0,     0,   293,
       0,     0,     0,     0,   369,   219,   175,     0,   644,     0,
       0,   296,   220,   221,   222,     0,     0,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   393,   242,   243,   244,   245,
     246,   247,   248,   249,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   255,   256,   257,   258,     0,     0,     0,     0,   259,
       7,     8,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   264,   265,   266,     0,     0,
       0,     0,     0,     0,     0,   219,   175,     0,   267,    27,
     906,   268,   220,   221,   222,     0,     0,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   393,   242,   243,   244,   245,
     246,   247,   248,   249,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   255,   256,   257,   258,     0,     0,     0,     0,   259,
       0,     0,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,   264,   265,   266,    45,    46,
      47,    48,     0,     0,     0,     0,    50,     0,   267,    27,
       0,   268,     0,     0,     0,   788,    58,     0,     0,    61,
     789,     0,   790,   791,     0,   792,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   282,     0,
       0,     0,   283,    82,     0,     0,     0,     0,   285,   286,
     287,     0,   288,   289,   290,     0,     0,     0,   123,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      99,   100,   101,     0,     0,   662,   663,     0,     0,     0,
       0,     0,   293,     0,     0,     0,     0,   664,     0,     0,
       0,   339,     0,     0,   296,   602,   603,   604,   605,   606,
     607,   608,   609,   610,   611,   612,   613,   614,   713,   616,
     617,   618,   619,     0,     0,     0,     0,   620,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   987,   282,     0,
       0,     0,   283,     0,     0,     0,     0,     0,   285,   286,
     287,     0,   288,   289,   290,     0,     0,  1011,   123,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   291,   394,     0,     0,     0,
       0,     0,   293,   219,   175,     0,     0,   369,     0,     0,
     220,   221,   222,     0,   296,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   393,   242,   243,   244,   245,   246,   247,
     248,   249,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   255,
     256,   257,   258,     0,     0,     0,     0,   259,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   264,   265,   266,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   267,    27,     0,   268,
     219,   175,     0,  1370,     0,     0,     0,   220,   221,   222,
       0,     0,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     393,   242,   243,   244,   245,   246,   247,   248,   249,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   255,   256,   257,   258,
       0,     0,     0,     0,   259,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     264,   265,   266,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   267,    27,     0,   268,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   614,
     713,   616,   617,   618,   619,     0,   282,     0,     0,   620,
     283,     0,     0,     0,     0,     0,   285,   286,   287,  1030,
     288,   289,   290,     0,     0,     0,   123,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   291,   394,     0,     0,     0,     0,     0,
     293,     0,     0,     0,     0,   369,  1128,     0,     0,     0,
       0,     0,   296,   602,   603,   604,   605,   606,   607,   608,
     609,   610,   611,   612,   613,   614,   713,   616,   617,   618,
     619,     0,     0,     0,     0,   620,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1140,     0,     0,     0,     0,
       0,     0,     0,   282,     0,     0,     0,   283,     0,     0,
       0,     0,     0,   285,   286,   287,     0,   288,   289,   290,
       0,     0,     0,   123,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     291,   394,     0,     0,     0,     0,     0,   293,   219,   175,
       0,  1544,   369,     0,     0,   220,   221,   222,     0,   296,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   393,   242,
     243,   244,   245,   246,   247,   248,   249,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   255,   256,   257,   258,     0,     0,
       0,     0,   259,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   264,   265,
     266,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   267,    27,     0,   268,   219,   175,     0,  1602,     0,
       0,     0,   220,   221,   222,     0,     0,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   393,   242,   243,   244,   245,
     246,   247,   248,   249,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   255,   256,   257,   258,     0,     0,     0,     0,   259,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   264,   265,   266,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   267,    27,
       0,   268,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   614,   713,   616,   617,   618,   619,
       0,   282,     0,     0,   620,   283,     0,     0,     0,     0,
       0,   285,   286,   287,  1181,   288,   289,   290,     0,     0,
       0,   123,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   291,   394,
       0,     0,     0,     0,     0,   293,     0,   219,   175,     0,
     369,     0,     0,     0,   220,   221,   222,   296,     0,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   393,   242,   243,
     244,   245,   246,   247,   248,   249,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   282,     0,
       0,     0,   283,   255,   256,   257,   258,     0,   285,   286,
     287,   259,   288,   289,   290,     0,     0,     0,   123,     0,
       0,     0,     0,     0,     0,     0,     0,   264,   265,   266,
       0,     0,     0,     0,     0,   291,   394,     0,     0,     0,
     267,    27,   293,   268,   219,   175,     0,   369,     0,     0,
       0,   220,   221,   222,   296,     0,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   393,   242,   243,   244,   245,   246,
     247,   248,   249,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     255,   256,   257,   258,     0,     0,     0,     0,   259,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   264,   265,   266,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   267,    27,     0,
     268,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   612,   613,   614,   713,   616,   617,   618,   619,     0,
     282,     0,     0,   620,   283,     0,     0,     0,     0,     0,
     285,   286,   287,  1191,   288,   289,   290,     0,     0,     0,
     123,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   291,   394,     0,
       0,     0,     0,     0,   293,     0,   219,   175,     0,   369,
    1657,     0,     0,   220,   221,   222,   296,     0,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   393,   242,   243,   244,
     245,   246,   247,   248,   249,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   282,     0,     0,
       0,   283,   255,   256,   257,   258,     0,   285,   286,   287,
     259,   288,   289,   290,     0,     0,     0,   123,     0,     0,
       0,     0,     0,     0,     0,     0,   264,   265,   266,     0,
       0,     0,     0,     0,   291,   394,     0,     0,     0,   267,
      27,   293,   268,   219,   175,     0,   369,  1990,     0,     0,
     220,   221,   222,   296,     0,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   393,   242,   243,   244,   245,   246,   247,
     248,   249,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   255,
     256,   257,   258,     0,     0,     0,     0,   259,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   264,   265,   266,     0,     0,     0,     7,
       8,     0,     0,     0,     0,     0,   267,    27,     0,   268,
     602,   603,   604,   605,   606,   607,   608,   609,   610,   611,
     612,   613,   614,   713,   616,   617,   618,   619,     0,   282,
       0,     0,   620,   283,     0,     0,     0,     0,     0,   285,
     286,   287,  1192,   288,   289,   290,     0,     0,     0,   123,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   291,   394,     0,     0,
       0,     0,     0,   293,     0,     0,     0,     0,   369,     0,
       0,     0,  2048,     0,     0,   296,     0,     0,     0,     0,
       0,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,     7,     8,     0,    45,    46,    47,
      48,     0,     0,     0,     0,    50,     0,     0,     0,     0,
       0,     0,     0,     0,   788,    58,   282,     0,    61,   789,
     283,   790,   791,     0,   792,     0,   285,   286,   287,     0,
     288,   289,   290,     0,     0,     0,   123,     0,     0,     0,
       0,     0,    82,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   291,   394,     0,     7,     8,     0,     0,
     293,     0,     0,     0,     0,   369,     0,     0,     0,    99,
     100,   101,   296,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,     0,
       0,     0,    45,    46,    47,    48,     0,     0,     0,     0,
      50,     0,     0,     0,     0,     0,     0,     0,     0,   788,
      58,     0,     0,    61,   789,     0,   790,   791,     0,   792,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1066,    82,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,     7,     8,     0,    45,    46,    47,    48,     0,     0,
       0,     0,    50,     0,    99,   100,   101,     0,     0,     0,
       0,   788,    58,     0,     0,    61,   789,     0,   790,   791,
       0,   792,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    82,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     7,     8,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    99,   100,   101,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1068,     0,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,     0,     0,     0,    45,
      46,    47,    48,     0,     0,     0,     0,    50,     0,     0,
       0,     0,     0,     0,     0,     0,   788,    58,     0,     0,
      61,   789,     0,   790,   791,     0,   792,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1277,    82,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,     7,     8,
       0,    45,    46,    47,    48,     0,     0,     0,     0,    50,
       0,    99,   100,   101,     0,     0,     0,     0,   788,    58,
       0,     0,    61,   789,     0,   790,   791,     0,   792,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    82,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       7,     8,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    99,   100,   101,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1279,     0,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,     0,     0,     0,    45,    46,    47,    48,
       0,     0,     0,     0,    50,     0,     0,     0,     0,     0,
       0,     0,     0,   788,    58,     0,     0,    61,   789,     0,
     790,   791,     0,   792,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1280,    82,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,     7,     8,     0,    45,    46,
      47,    48,     0,     0,     0,     0,    50,     0,    99,   100,
     101,     0,     0,     0,     0,   788,    58,     0,     0,    61,
     789,     0,   790,   791,     0,   792,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    82,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     7,     8,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      99,   100,   101,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1299,     0,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
       0,     0,     0,    45,    46,    47,    48,     0,     0,     0,
       0,    50,     0,     0,     0,     0,     0,     0,     0,     0,
     788,    58,     0,     0,    61,   789,     0,   790,   791,     0,
     792,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1310,    82,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,     7,     8,     0,    45,    46,    47,    48,     0,
       0,     0,     0,    50,     0,    99,   100,   101,     0,     0,
       0,     0,   788,    58,     0,     0,    61,   789,     0,   790,
     791,     0,   792,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      82,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     7,     8,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    99,   100,   101,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1328,     0,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,     0,     0,     0,
      45,    46,    47,    48,     0,     0,     0,     0,    50,     0,
       0,     0,     0,     0,     0,     0,     0,   788,    58,     0,
       0,    61,   789,     0,   790,   791,     0,   792,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1365,    82,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,     7,
       8,     0,    45,    46,    47,    48,     0,     0,     0,     0,
      50,     0,    99,   100,   101,     0,     0,     0,     0,   788,
      58,     0,     0,    61,   789,     0,   790,   791,     0,   792,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    82,   602,   603,
     604,   605,   606,   607,   608,   609,   610,   611,   612,   613,
     614,   713,   616,   617,   618,   619,     0,     0,     0,     0,
     620,     0,     0,     0,    99,   100,   101,     0,     0,     0,
    1193,     0,     0,     0,     0,     0,     0,     0,     0,  1536,
       0,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,     0,     0,     0,    45,    46,    47,
      48,     0,     0,     0,     0,    50,     0,     0,     0,     0,
       0,     0,     0,     0,   788,    58,    -4,     1,    61,   789,
      -4,   790,   791,     0,   792,     0,     0,     0,     0,    -4,
      -4,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2171,    82,     0,   602,   603,   604,   605,   606,   607,
     608,   609,   610,   611,   612,   613,   614,   713,   616,   617,
     618,   619,     0,    -4,    -4,    -4,   620,     0,     0,    99,
     100,   101,     0,     0,     0,     0,  1194,     0,     0,     0,
       0,     0,     0,     0,    -4,    -4,    -4,     0,     0,     0,
       0,    -4,    -4,     0,     0,     0,     0,    -4,     0,     0,
       0,     0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,
      -4,    -4,     0,    -4,     0,     0,     0,     0,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,     0,     0,    -4,    -4,    -4,    -4,
      -4,     0,     0,    -4,     0,    -4,  2215,    -4,    -4,     0,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,     0,     0,    -4,    -4,    -4,     0,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,     0,     0,     0,    -4,    -4,    -4,
       0,     0,     0,    -4,     0,     0,     0,     0,    -4,    -4,
      -4,    -4,     0,     0,    -4,     0,    -4,     0,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,     0,     6,     0,     0,     0,     0,    -4,    -4,
      -4,    -4,     7,     8,     0,     0,     0,     0,     0,     0,
      -4,     0,    -4,    -4,     0,     0,     0,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   614,
     713,   616,   617,   618,   619,     0,     9,    10,    11,   620,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1195,
       0,     0,     0,     0,     0,     0,     0,    12,    13,    14,
       0,     0,     0,     0,    15,    16,     0,     0,     0,     0,
      17,     0,     0,     0,     0,    18,    19,    20,    21,    22,
      23,    24,     0,    25,    26,     0,    27,     0,     0,     0,
       0,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,     0,     0,    44,
      45,    46,    47,    48,     0,     0,    49,     0,    50,     0,
      51,    52,     0,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,     0,     0,    67,
      68,    69,     0,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,     0,     0,     0,
      94,    95,    96,     0,     0,     0,    97,     0,     0,     0,
       0,    98,    99,   100,   101,   175,   399,   102,     0,   103,
       0,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,     0,     0,     0,     0,     0,
       0,   118,   119,   120,   121,     0,     0,     0,     0,     0,
       0,     0,     0,   122,     0,   123,   124,     0,     0,     0,
       0,   400,   401,   402,   403,   404,   405,   406,   407,   408,
       0,     0,     0,     0,   409,   410,   411,   412,     0,   175,
     399,     0,   413,   414,   415,   416,     0,     0,     0,     0,
       0,   417,     0,   418,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   419,
       0,     0,   420,     0,     0,     0,   181,     0,     0,   182,
       0,     0,   183,     0,   184,   400,   401,   402,   403,   404,
     405,   406,   407,   408,     0,    48,     0,     0,   409,   410,
     411,   412,   430,   399,     0,     0,   413,   414,   415,   416,
       0,     0,     0,     0,     0,   417,   449,   418,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       7,     8,     0,   419,     0,     0,   420,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   400,   401,
     402,   403,   404,   405,   406,   407,   408,     0,     0,     0,
       0,   409,   410,   411,   412,     0,     0,     0,     0,   413,
     414,   415,   416,     0,     0,     0,     0,     0,   417,     0,
     418,     0,     0,     0,     0,     0,     0,     0,   421,   422,
     423,     0,     0,     0,     0,     0,   419,     0,     0,   420,
     424,     0,     0,     0,   425,     0,   426,   123,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,     0,     0,     0,    45,    46,
      47,    48,     7,     8,     0,     0,    50,     0,     0,     0,
       0,     0,   421,   422,   423,   788,    58,     0,     0,    61,
     789,     0,   790,   791,   424,   792,     0,     0,   425,  1074,
     426,   123,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    82,     0,     0,     0,  1075,     0,     0,
       0,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   612,   613,   614,   713,   616,   617,   618,   619,     0,
      99,   100,   101,   620,     0,   421,   422,   423,     0,     0,
       0,     0,     0,  1200,     0,     0,     0,   424,     0,     0,
       0,   425,     0,   426,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,     0,     0,     0,
      45,    46,    47,    48,     0,     0,     0,     0,    50,     0,
       0,     0,     0,     0,     0,     0,     0,   788,    58,     0,
       0,    61,   789,     0,   790,   791,     0,   792,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    82,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   612,   613,   614,   713,
     616,   617,   618,   619,     0,     0,     0,     0,   620,     0,
       0,     0,    99,   100,   101,     0,     0,     0,  1201,   602,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   612,
     613,   614,   713,   616,   617,   618,   619,     0,     0,     0,
       0,   620,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1203,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   614,   713,   616,   617,   618,   619,
       0,     0,     0,     0,   620,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1320,   602,   603,   604,   605,   606,
     607,   608,   609,   610,   611,   612,   613,   614,   713,   616,
     617,   618,   619,     0,     0,     0,     0,   620,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1346,   602,   603,
     604,   605,   606,   607,   608,   609,   610,   611,   612,   613,
     614,   713,   616,   617,   618,   619,     0,     0,     0,     0,
     620,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1429,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   612,   613,   614,   713,   616,   617,   618,   619,     0,
       0,     0,     0,   620,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1433,   602,   603,   604,   605,   606,   607,
     608,   609,   610,   611,   612,   613,   614,   713,   616,   617,
     618,   619,     0,     0,     0,     0,   620,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1538,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   614,
     713,   616,   617,   618,   619,     0,     0,     0,     0,   620,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1539,
     602,   603,   604,   605,   606,   607,   608,   609,   610,   611,
     612,   613,   614,   713,   616,   617,   618,   619,     0,     0,
       0,     0,   620,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1578,   602,   603,   604,   605,   606,   607,   608,
     609,   610,   611,   612,   613,   614,   713,   616,   617,   618,
     619,     0,     0,     0,     0,   620,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1708,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   612,   613,   614,   713,
     616,   617,   618,   619,     0,     0,     0,     0,   620,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1709,   602,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   612,
     613,   614,   713,   616,   617,   618,   619,     0,     0,     0,
       0,   620,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1710,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   614,   713,   616,   617,   618,   619,
       0,     0,     0,     0,   620,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1856,   602,   603,   604,   605,   606,
     607,   608,   609,   610,   611,   612,   613,   614,   713,   616,
     617,   618,   619,     0,     0,     0,     0,   620,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1976,   602,   603,
     604,   605,   606,   607,   608,   609,   610,   611,   612,   613,
     614,   713,   616,   617,   618,   619,     0,     0,     0,     0,
     620,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1977,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   612,   613,   614,   713,   616,   617,   618,   619,     0,
       0,     0,     0,   620,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2010,   602,   603,   604,   605,   606,   607,
     608,   609,   610,   611,   612,   613,   614,   713,   616,   617,
     618,   619,     0,     0,     0,     0,   620,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2082,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   614,
     713,   616,   617,   618,   619,     0,     0,     0,     0,   620,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2097,
     602,   603,   604,   605,   606,   607,   608,   609,   610,   611,
     612,   613,   614,   713,   616,   617,   618,   619,     0,     0,
       0,     0,   620,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2099,   602,   603,   604,   605,   606,   607,   608,
     609,   610,   611,   612,   613,   614,   713,   616,   617,   618,
     619,     0,     0,     0,     0,   620,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2137,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   612,   613,   614,   713,
     616,   617,   618,   619,     0,     0,     0,     0,   620,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2138,   602,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   612,
     613,   614,   713,   616,   617,   618,   619,     0,     0,     0,
       0,   620,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2152,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   614,   713,   616,   617,   618,   619,
       0,     0,     0,     0,   620,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2183,   602,   603,   604,   605,   606,
     607,   608,   609,   610,   611,   612,   613,   614,   713,   616,
     617,   618,   619,     0,     0,     0,     0,   620,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2204,   602,   603,
     604,   605,   606,   607,   608,   609,   610,   611,   612,   613,
     614,   713,   616,   617,   618,   619,     0,     0,     0,     0,
     620,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2209,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   612,   613,   614,   713,   616,   617,   618,   619,     0,
       0,     0,     0,   620,     0,     0,     0,     0,     0,   848,
     602,   603,   604,   605,   606,   607,   608,   609,   610,   611,
     612,   613,   614,   713,   616,   617,   618,   619,     0,     0,
       0,     0,   620,     0,     0,     0,     0,     0,  1109,   602,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   612,
     613,   614,   713,   616,   617,   618,   619,     0,     0,     0,
       0,   620,     0,     0,     0,     0,     0,  1167,   602,   603,
     604,   605,   606,   607,   608,   609,   610,   611,   612,   613,
     614,   713,   616,   617,   618,   619,     0,     0,     0,     0,
     620,     0,     0,     0,     0,     0,  1216,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   614,
     713,   616,   617,   618,   619,     0,     0,     0,     0,   620,
       0,     0,     0,     0,     0,  1217,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   612,   613,   614,   713,
     616,   617,   618,   619,     0,     0,     0,     0,   620,     0,
       0,     0,     0,     0,  1269,   602,   603,   604,   605,   606,
     607,   608,   609,   610,   611,   612,   613,   614,   713,   616,
     617,   618,   619,     0,     0,     0,     0,   620,     0,     0,
       0,     0,     0,  1308,   602,   603,   604,   605,   606,   607,
     608,   609,   610,   611,   612,   613,   614,   713,   616,   617,
     618,   619,     0,     0,     0,     0,   620,     0,     0,     0,
       0,     0,  1315,   602,   603,   604,   605,   606,   607,   608,
     609,   610,   611,   612,   613,   614,   713,   616,   617,   618,
     619,     0,     0,     0,     0,   620,     0,     0,     0,     0,
       0,  1376,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   614,   713,   616,   617,   618,   619,
       0,     0,     0,     0,   620,     0,     0,     0,     0,     0,
    1396,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   612,   613,   614,   713,   616,   617,   618,   619,     0,
       0,     0,     0,   620,     0,     0,     0,     0,     0,  1432,
     602,   603,   604,   605,   606,   607,   608,   609,   610,   611,
     612,   613,   614,   713,   616,   617,   618,   619,     0,     0,
       0,     0,   620,     0,     0,     0,     0,     0,  1483,   602,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   612,
     613,   614,   713,   616,   617,   618,   619,     0,     0,     0,
       0,   620,     0,     0,     0,     0,     0,  1484,   602,   603,
     604,   605,   606,   607,   608,   609,   610,   611,   612,   613,
     614,   713,   616,   617,   618,   619,     0,     0,     0,     0,
     620,     0,     0,     0,     0,     0,  1485,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   614,
     713,   616,   617,   618,   619,     0,     0,     0,     0,   620,
       0,     0,     0,     0,     0,  1488,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   612,   613,   614,   713,
     616,   617,   618,   619,     0,     0,     0,     0,   620,     0,
       0,     0,     0,     0,  1489,   602,   603,   604,   605,   606,
     607,   608,   609,   610,   611,   612,   613,   614,   713,   616,
     617,   618,   619,     0,     0,     0,     0,   620,     0,     0,
       0,     0,     0,  1490,   602,   603,   604,   605,   606,   607,
     608,   609,   610,   611,   612,   613,   614,   713,   616,   617,
     618,   619,     0,     0,     0,     0,   620,     0,     0,     0,
       0,     0,  1492,   602,   603,   604,   605,   606,   607,   608,
     609,   610,   611,   612,   613,   614,   713,   616,   617,   618,
     619,     0,     0,     0,     0,   620,     0,     0,     0,     0,
       0,  1495,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   614,   713,   616,   617,   618,   619,
       0,     0,     0,     0,   620,     0,     0,     0,     0,     0,
    1540,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   612,   613,   614,   713,   616,   617,   618,   619,     0,
       0,     0,     0,   620,     0,     0,     0,     0,     0,  1608,
     602,   603,   604,   605,   606,   607,   608,   609,   610,   611,
     612,   613,   614,   713,   616,   617,   618,   619,     0,     0,
       0,     0,   620,     0,     0,     0,     0,     0,  1719,   602,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   612,
     613,   614,   713,   616,   617,   618,   619,     0,     0,     0,
       0,   620,     0,     0,     0,     0,     0,  1913,   602,   603,
     604,   605,   606,   607,   608,   609,   610,   611,   612,   613,
     614,   713,   616,   617,   618,   619,     0,     0,     0,     0,
     620,     0,     0,     0,     0,     0,  1924,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   614,
     713,   616,   617,   618,   619,     0,     0,     0,     0,   620,
       0,     0,     0,     0,     0,  1956,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   612,   613,   614,   713,
     616,   617,   618,   619,     0,     0,     0,     0,   620,     0,
       0,     0,     0,     0,  2035,   602,   603,   604,   605,   606,
     607,   608,   609,   610,   611,   612,   613,   614,   713,   616,
     617,   618,   619,     0,     0,     0,     0,   620,     0,     0,
       0,     0,     0,  2044,   602,   603,   604,   605,   606,   607,
     608,   609,   610,   611,   612,   613,   614,   713,   616,   617,
     618,   619,     0,     0,     0,     0,   620,     0,     0,     0,
       0,     0,  2059,   602,   603,   604,   605,   606,   607,   608,
     609,   610,   611,   612,   613,   614,   713,   616,   617,   618,
     619,     0,     0,     0,     0,   620,     0,     0,     0,     0,
       0,  2083,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   614,   713,   616,   617,   618,   619,
       0,     0,     0,     0,   620,     0,     0,     0,     0,     0,
    2098,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   612,   613,   614,   713,   616,   617,   618,   619,     0,
       0,     0,     0,   620,     0,     0,     0,     0,     0,  2122,
     602,   603,   604,   605,   606,   607,   608,   609,   610,   611,
     612,   613,   614,   713,   616,   617,   618,   619,     0,     0,
       0,     0,   620,     0,     0,     0,     0,     0,  2125,   602,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   612,
     613,   614,   713,   616,   617,   618,   619,     0,     0,     0,
       0,   620,     0,     0,     0,     0,     0,  2126,   602,   603,
     604,   605,   606,   607,   608,   609,   610,   611,   612,   613,
     614,   713,   616,   617,   618,   619,     0,     0,     0,     0,
     620,     0,     0,     0,     0,     0,  2151,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   614,
     713,   616,   617,   618,   619,     0,     0,     0,     0,   620,
       0,     0,     0,     0,     0,  2155,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   612,   613,   614,   713,
     616,   617,   618,   619,     0,     0,     0,     0,   620,     0,
       0,     0,     0,     0,  2188,   602,   603,   604,   605,   606,
     607,   608,   609,   610,   611,   612,   613,   614,   713,   616,
     617,   618,   619,     0,     0,     0,     0,   620,     0,     0,
       0,     0,     0,  2189,   602,   603,   604,   605,   606,   607,
     608,   609,   610,   611,   612,   613,   614,   713,   616,   617,
     618,   619,     0,     0,     0,     0,   620,     0,     0,     0,
       0,     0,  2197,   602,   603,   604,   605,   606,   607,   608,
     609,   610,   611,   612,   613,   614,   713,   616,   617,   618,
     619,     0,     0,     0,     0,   620,     0,     0,     0,     0,
       0,  2222,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   614,   713,   616,   617,   618,   619,
       0,     0,     0,     0,   620,     0,     0,     0,     0,     0,
    2247,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   612,   613,   614,   713,   616,   617,   618,   619,     0,
       0,     0,     0,   620,     0,     0,     0,     0,     0,  2248,
     602,   603,   604,   605,   606,   607,   608,   609,   610,   611,
     612,   613,   614,   713,   616,   617,   618,   619,     0,     0,
       0,     0,   620,     0,     0,     0,     0,   750,   602,   603,
     604,   605,   606,   607,   608,   609,   610,   611,   612,   613,
     614,   713,   616,   617,   618,   619,     0,     0,     0,     0,
     620,     0,     0,     0,     0,   978,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   612,   613,   614,   713,
     616,   617,   618,   619,     0,     0,     0,     0,   620,     0,
       0,     0,     0,  2028,   602,   603,   604,   605,   606,   607,
     608,   609,   610,   611,   612,   613,   614,   713,   616,   617,
     618,   619,     0,     0,     0,     0,   620,     0,   774,     0,
     775,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   612,   613,   614,   713,   616,   617,   618,   619,     0,
       0,     0,     0,   620,     0,     0,     0,  1040,   602,   603,
     604,   605,   606,   607,   608,   609,   610,   611,   612,   613,
     614,   713,   616,   617,   618,   619,     0,     0,     0,     0,
     620,     0,     0,     0,  1085,   602,   603,   604,   605,   606,
     607,   608,   609,   610,   611,   612,   613,   614,   713,   616,
     617,   618,   619,     0,     0,     0,     0,   620,     0,     0,
       0,  1248,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   614,   713,   616,   617,   618,   619,
       0,     0,     0,     0,   620,     0,     0,     0,  1309,   602,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   612,
     613,   614,   713,   616,   617,   618,   619,     0,     0,     0,
       0,   620,     0,     0,     0,  1311,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   612,   613,   614,   713,
     616,   617,   618,   619,     0,     0,     0,     0,   620,     0,
       0,     0,  1318,   602,   603,   604,   605,   606,   607,   608,
     609,   610,   611,   612,   613,   614,   713,   616,   617,   618,
     619,     0,     0,     0,     0,   620,     0,     0,     0,  1319,
     602,   603,   604,   605,   606,   607,   608,   609,   610,   611,
     612,   613,   614,   713,   616,   617,   618,   619,     0,     0,
       0,     0,   620,     0,     0,     0,  1411,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   614,
     713,   616,   617,   618,   619,     0,     0,     0,     0,   620,
       0,     0,     0,  1425,   602,   603,   604,   605,   606,   607,
     608,   609,   610,   611,   612,   613,   614,   713,   616,   617,
     618,   619,     0,     0,     0,     0,   620,     0,     0,     0,
    1637,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   612,   613,   614,   713,   616,   617,   618,   619,     0,
       0,     0,     0,   620,     0,     0,     0,  1735,   602,   603,
     604,   605,   606,   607,   608,   609,   610,   611,   612,   613,
     614,   713,   616,   617,   618,   619,     0,     0,     0,     0,
     620,     0,     0,     0,  1779,   602,   603,   604,   605,   606,
     607,   608,   609,   610,   611,   612,   613,   614,   713,   616,
     617,   618,   619,     0,     0,     0,     0,   620,     0,     0,
       0,  1968,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   614,   713,   616,   617,   618,   619,
       0,     0,     0,     0,   620,     0,     0,     0,  2018,   602,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   612,
     613,   614,   713,   616,   617,   618,   619,     0,     0,     0,
       0,   620,     0,     0,     0,  2036,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   612,   613,   614,   713,
     616,   617,   618,   619,     0,     0,     0,     0,   620,     0,
     828,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   612,   613,   614,   713,   616,   617,   618,   619,     0,
       0,     0,     0,   620,     0,   829,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   612,   613,   614,   713,
     616,   617,   618,   619,     0,     0,     0,     0,   620,     0,
     830,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   612,   613,   614,   713,   616,   617,   618,   619,     0,
       0,     0,     0,   620,     0,   832,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   612,   613,   614,   713,
     616,   617,   618,   619,     0,     0,     0,     0,   620,     0,
     833,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   612,   613,   614,   713,   616,   617,   618,   619,     0,
       0,     0,     0,   620,     0,   834,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   612,   613,   614,   713,
     616,   617,   618,   619,     0,     0,     0,     0,   620,     0,
     836,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   612,   613,   614,   713,   616,   617,   618,   619,     0,
       0,     0,     0,   620,     0,   837,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   612,   613,   614,   713,
     616,   617,   618,   619,     0,     0,     0,     0,   620,     0,
     838,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   612,   613,   614,   713,   616,   617,   618,   619,     0,
       0,     0,     0,   620,     0,   839,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   612,   613,   614,   713,
     616,   617,   618,   619,     0,     0,     0,     0,   620,     0,
     840,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   612,   613,   614,   713,   616,   617,   618,   619,     0,
       0,     0,     0,   620,     0,   841,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   612,   613,   614,   713,
     616,   617,   618,   619,     0,     0,     0,     0,   620,     0,
     842,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   612,   613,   614,   713,   616,   617,   618,   619,     0,
       0,     0,     0,   620,     0,   845,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   612,   613,   614,   713,
     616,   617,   618,   619,     0,     0,     0,     0,   620,     0,
     846,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   612,   613,   614,   713,   616,   617,   618,   619,     0,
       0,     0,     0,   620,     0,   847,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   612,   613,   614,   713,
     616,   617,   618,   619,     0,     0,     0,     0,   620,     0,
     925,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   612,   613,   614,   713,   616,   617,   618,   619,     0,
       0,     0,     0,   620,     0,   959,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   612,   613,   614,   713,
     616,   617,   618,   619,     0,     0,     0,     0,   620,     0,
    1000,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   612,   613,   614,   713,   616,   617,   618,   619,     0,
       0,     0,     0,   620,     0,  1017,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   612,   613,   614,   713,
     616,   617,   618,   619,     0,     0,     0,     0,   620,     0,
    1025,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   612,   613,   614,   713,   616,   617,   618,   619,     0,
       0,     0,     0,   620,     0,  1027,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   612,   613,   614,   713,
     616,   617,   618,   619,     0,     0,     0,     0,   620,     0,
    1028,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   612,   613,   614,   713,   616,   617,   618,   619,     0,
       0,     0,     0,   620,     0,  1034,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   612,   613,   614,   713,
     616,   617,   618,   619,     0,     0,     0,     0,   620,     0,
    1035,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   612,   613,   614,   713,   616,   617,   618,   619,     0,
       0,     0,     0,   620,     0,  1073,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   612,   613,   614,   713,
     616,   617,   618,   619,     0,     0,     0,     0,   620,     0,
    1084,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   612,   613,   614,   713,   616,   617,   618,   619,     0,
       0,     0,     0,   620,     0,  1145,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   612,   613,   614,   713,
     616,   617,   618,   619,     0,     0,     0,     0,   620,     0,
    1149,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   612,   613,   614,   713,   616,   617,   618,   619,     0,
       0,     0,     0,   620,     0,  1162,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   612,   613,   614,   713,
     616,   617,   618,   619,     0,     0,     0,     0,   620,     0,
    1247,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   612,   613,   614,   713,   616,   617,   618,   619,     0,
       0,     0,     0,   620,     0,  1257,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   612,   613,   614,   713,
     616,   617,   618,   619,     0,     0,     0,     0,   620,     0,
    1258,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   612,   613,   614,   713,   616,   617,   618,   619,     0,
       0,     0,     0,   620,     0,  1259,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   612,   613,   614,   713,
     616,   617,   618,   619,     0,     0,     0,     0,   620,     0,
    1268,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   612,   613,   614,   713,   616,   617,   618,   619,     0,
       0,     0,     0,   620,     0,  1270,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   612,   613,   614,   713,
     616,   617,   618,   619,     0,     0,     0,     0,   620,     0,
    1271,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   612,   613,   614,   713,   616,   617,   618,   619,     0,
       0,     0,     0,   620,     0,  1307,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   612,   613,   614,   713,
     616,   617,   618,   619,     0,     0,     0,     0,   620,     0,
    1321,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   612,   613,   614,   713,   616,   617,   618,   619,     0,
       0,     0,     0,   620,     0,  1323,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   612,   613,   614,   713,
     616,   617,   618,   619,     0,     0,     0,     0,   620,     0,
    1364,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   612,   613,   614,   713,   616,   617,   618,   619,     0,
       0,     0,     0,   620,     0,  1410,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   612,   613,   614,   713,
     616,   617,   618,   619,     0,     0,     0,     0,   620,     0,
    1424,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   612,   613,   614,   713,   616,   617,   618,   619,     0,
       0,     0,     0,   620,     0,  1638,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   612,   613,   614,   713,
     616,   617,   618,   619,     0,     0,     0,     0,   620,     0,
    1675,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   612,   613,   614,   713,   616,   617,   618,   619,     0,
       0,     0,     0,   620,     0,  1722,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   612,   613,   614,   713,
     616,   617,   618,   619,     0,     0,     0,     0,   620,     0,
    1734,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   612,   613,   614,   713,   616,   617,   618,   619,     0,
       0,     0,     0,   620,     0,  1842,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   612,   613,   614,   713,
     616,   617,   618,   619,     0,     0,     0,     0,   620,     0,
    1844,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   612,   613,   614,   713,   616,   617,   618,   619,     0,
       0,     0,     0,   620,     0,  1848,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   612,   613,   614,   713,
     616,   617,   618,   619,     0,     0,     0,     0,   620,     0,
    1855,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   612,   613,   614,   713,   616,   617,   618,   619,     0,
       0,     0,     0,   620,     0,  1914,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   612,   613,   614,   713,
     616,   617,   618,   619,     0,     0,     0,     0,   620,     0,
    1923,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   612,   613,   614,   713,   616,   617,   618,   619,     0,
       0,     0,     0,   620,     0,  1939,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   612,   613,   614,   713,
     616,   617,   618,   619,     0,     0,     0,     0,   620,     0,
    2017,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   612,   613,   614,   713,   616,   617,   618,   619,     0,
       0,     0,     0,   620,     0,  2080,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   612,   613,   614,   713,
     616,   617,   618,   619,     0,     0,     0,     0,   620,     0,
    2081,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   612,   613,   614,   713,   616,   617,   618,   619,     0,
       0,     0,     0,   620,     0,  2094,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   612,   613,   614,   713,
     616,   617,   618,   619,     0,     0,     0,     0,   620,     0,
    2203,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   612,   613,   614,   713,   616,   617,   618,   619,     0,
       0,     0,     0,   620,     0,  2230,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   612,   613,   614,   713,
     616,   617,   618,   619,     0,     0,     0,     0,   620
};

static const yytype_int16 yycheck[] =
{
       3,   659,   660,    71,    72,   332,    74,     3,  1499,  1300,
     163,  1296,   771,   149,    65,  1810,     4,  1812,   777,     4,
       4,     4,     4,   111,    27,    97,     7,    27,     6,     6,
       5,     7,     6,     5,     4,   111,     4,     6,     4,  1993,
       4,     6,     5,  1799,     6,     9,   113,     5,   115,     4,
      68,     4,   149,   170,    57,    14,     4,     7,     6,     6,
     108,     6,   167,   111,   112,   113,   111,   253,   254,     6,
       6,   105,     4,    26,     4,   266,   124,     4,     9,   111,
     271,   198,   149,    86,    37,    38,     7,   105,   274,    92,
     124,     7,     4,   138,    97,     4,   111,   214,   215,   102,
       4,     0,     9,     9,   201,     6,   138,  1863,   266,    97,
     113,   265,   149,   180,    26,     6,   274,    26,   105,   186,
     265,   108,    26,   269,   111,    37,    38,   273,    37,    38,
     167,   262,   263,    37,    38,   207,   271,   124,   149,   274,
     271,   178,   179,   180,   216,   193,   149,   184,   185,     8,
     265,   154,   155,   156,   150,     6,   167,   105,   253,   254,
     163,   114,   115,   266,     6,   268,   269,   178,   179,   180,
       4,   253,   254,   184,   185,   253,   254,   265,     8,   274,
     253,   254,   108,   265,   265,   111,   267,   269,     6,   265,
       9,   265,  2146,   274,   265,   269,   274,     9,   124,   202,
     174,   274,   114,   115,   207,   114,   115,     9,   211,   186,
     261,   262,   263,   216,   217,   218,   265,   186,   267,   269,
     269,   209,   154,   155,   156,   157,   108,   159,   160,   111,
     281,   113,   268,   270,   253,   254,  1727,   169,   274,   344,
       7,   173,   124,   213,   316,   317,   318,     6,   236,   262,
     263,   356,   236,   236,   236,   274,   269,   238,   239,   240,
     241,   267,   238,   239,   240,   241,     7,   335,   236,   337,
     236,  1556,   236,   211,   277,   343,   344,   349,   350,   351,
       7,   269,   267,   269,   269,   269,   269,   265,   273,   292,
     272,   269,   295,   296,   269,   367,   296,   269,   262,   263,
     266,   265,   268,   267,   269,   269,   269,   271,   311,   312,
     265,   269,   315,   316,   317,   318,   459,   238,   239,   240,
     241,   271,   269,   326,   269,  1084,  1085,   330,   433,   332,
     435,   266,   269,   269,   265,   265,   267,   442,   265,   274,
     271,   262,   263,   346,   347,     6,   349,   350,   351,   265,
     271,   267,   253,   254,   188,   189,   190,   191,   265,   265,
     267,   267,   253,   254,   367,   271,   200,   370,   202,   203,
     204,   205,   206,   311,   312,   108,   210,   211,   111,   213,
     113,   448,  2177,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   108,   253,   254,   111,   264,   248,   249,   346,   347,
     563,   270,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     248,   249,  2025,     6,   264,   438,   270,   440,     6,   266,
     270,   444,   445,   262,   263,     6,   265,   274,   267,   268,
     262,   263,   271,   265,     4,   267,   265,   460,   267,   271,
     262,   263,   266,   265,   467,   267,   253,   254,     6,   271,
     274,   238,   239,   240,   241,   265,    26,   253,   254,   269,
     268,   624,   269,  2076,   253,   254,   274,    37,    38,   492,
     111,   265,   113,   266,   270,   262,   263,   238,   239,   240,
     241,   274,   440,     6,     4,   274,  1164,   579,   253,   254,
     266,   238,   239,   240,   241,   518,   270,   266,   274,   586,
     274,   262,   263,     6,  2015,   274,    26,   253,   254,   274,
     253,   254,   253,   254,   266,   262,   263,    37,    38,   267,
     543,   265,   274,   648,   266,   650,   651,   266,   274,   552,
     553,   274,   274,   274,   557,   274,   559,   560,   561,   562,
     563,   265,   667,   267,   114,   115,   569,   271,   721,   266,
     274,   268,   269,   678,   717,   578,   579,   580,   265,   582,
     583,   584,   585,   128,   587,   585,   589,   587,   270,   657,
     658,   149,   274,   111,   266,   663,   268,   266,   105,   268,
     705,   108,   274,   265,   111,   274,   113,   253,   254,   167,
     258,   259,   615,  2206,   114,   115,   264,   124,   621,   265,
     178,   179,   180,   269,   154,   155,   184,   185,   270,   159,
     253,   254,   274,   154,   155,   771,   253,   254,   159,   265,
     643,   644,   785,  1301,  1302,   750,   269,  2240,   198,   199,
     108,   589,   269,   111,   266,   149,   268,   270,   266,   802,
     268,   274,   274,   659,   660,   265,   274,   734,   266,   812,
     268,   262,   263,   167,   262,   263,   274,   265,   149,   267,
     265,   684,   685,   686,   178,   179,   180,     6,     7,   692,
     184,   185,   262,   263,   265,   265,   167,   267,   198,   199,
     265,   265,   267,   267,     6,   643,   644,   178,   179,   180,
     265,   714,   270,   184,   185,     6,   719,   720,   721,   722,
     723,   724,   725,   726,   727,   265,   729,   730,   731,   732,
     733,   265,   735,   736,   737,   738,   739,   270,   738,   742,
     791,   274,     8,   271,   269,   273,   684,   685,   686,   255,
     256,   257,   258,   259,   692,   270,   265,   760,   264,   274,
     827,   266,   113,   268,   262,   263,  1525,   265,   270,   267,
     265,   269,   274,   776,   270,   265,   270,   270,   274,   782,
     265,   274,   267,     4,   927,     6,   253,   254,   255,   256,
     257,   258,   259,   265,   270,   798,   799,   264,   274,   270,
     269,   804,   265,   806,   742,   270,   809,   810,   270,   274,
      57,   265,   274,   111,   270,   818,   269,   820,   274,   265,
     956,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   108,   776,   270,
     270,   264,   270,   274,   274,   270,   274,   914,   851,   274,
     853,   270,   270,   270,  1613,   274,   274,   274,     3,   270,
     798,   270,   269,   274,  1623,   274,   804,   270,   806,   270,
     270,   274,   270,   274,   274,   270,   274,   982,   270,   274,
     269,  2172,   274,   270,    29,   270,   889,   274,   270,   274,
     270,   270,   274,   270,   274,   274,   899,   274,   253,   254,
     270,   270,   969,  1039,   274,   274,   270,   265,   270,   270,
     274,   914,   274,   274,  2199,   111,   270,   985,   270,    64,
     274,   269,   274,   270,   992,  2216,   929,   274,   996,   270,
     270,   270,   270,   274,   274,   274,   274,   269,   108,     6,
     270,  2226,   945,  1086,   274,   108,   270,   111,  1084,  1085,
     274,   889,   270,   270,   957,   270,   274,   274,   270,   274,
     270,   899,   274,   966,   274,  1101,     4,   111,     4,     4,
     217,     4,   265,   118,     6,   978,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   267,   265,   265,   265,   264,     6,
     266,     6,   268,   267,   149,     6,   269,   945,   273,   154,
     155,   156,   269,   273,   265,     9,   265,   265,   163,   957,
     265,  1088,   265,   269,   265,   265,   201,   201,   201,   111,
     277,   269,   138,   265,   265,   265,   265,   265,   265,   201,
     978,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   269,   202,   265,  1386,
     264,   269,   265,   269,     4,     6,   267,   269,   315,   269,
     269,     6,     6,   218,  1142,   269,  1079,   269,   269,   326,
     269,     7,   269,   330,  1087,   267,   267,   267,  1231,     6,
    1233,     6,  1095,   265,   265,     6,   201,   265,   267,   265,
    1758,  1759,   269,  1246,   265,  1108,   265,   265,   265,     6,
    1113,  1247,  1248,   269,     6,   260,     6,     8,   265,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,     8,  1276,   279,   280,   264,   269,     7,     6,
    1143,  1144,   269,  1146,  1147,  1148,   269,  1150,  1151,  1152,
    1153,  1154,  1155,  1156,     6,  1158,  1159,  1160,   269,   274,
     270,   100,   274,     7,     6,     6,   266,   269,  1164,    68,
    1108,   269,   269,   269,   269,   269,   269,   269,   269,   269,
     264,     8,   271,     7,     7,   265,     6,   266,  1331,     7,
       6,  1334,  1335,   269,     7,     6,     6,   444,   445,   270,
     198,   269,  1205,  1206,  1207,   270,   270,   268,   266,     6,
     269,   271,     7,   460,     6,   267,  1359,     8,   265,   269,
       6,     6,     6,     6,     6,   266,     7,   267,     7,     7,
       7,     7,     7,     7,     7,  1238,     7,     7,     7,  1382,
       7,     7,     7,     7,     7,     6,   266,   268,   274,   274,
     274,  1254,  1255,  1256,   270,   269,   274,   266,     7,   270,
       7,   271,     4,   269,   149,   269,  1409,     6,   271,     7,
     270,   270,   269,   269,  1410,  1411,     6,     9,     7,     7,
    1423,     7,   271,   271,   266,   266,   266,  1430,   274,  1616,
     274,   274,   268,   438,   273,   201,     7,   170,   270,   269,
    1303,     6,     6,     6,   449,  1301,  1302,    50,   271,    50,
     265,   269,   265,   560,   271,   269,   265,  1255,  1256,  1322,
     271,  1324,  1325,   265,     7,     7,   471,     7,   274,   201,
     266,   578,     7,   580,  1337,     7,     7,     6,   266,  1342,
       7,   486,   274,  1346,     7,     7,     7,     7,     4,  1416,
     269,   123,  1355,     6,  1357,   265,   269,  1360,     6,   105,
       6,     6,     6,   111,     7,     7,     6,  1434,     7,  1436,
    1373,     7,     4,  2031,   272,     6,   269,   266,   274,   274,
       6,   269,   269,  1386,   270,     6,   267,     7,     6,     6,
       6,   265,   269,     6,   265,   270,     6,     6,     6,  1337,
       6,   271,   268,     6,     6,   142,   274,     6,  1411,     6,
       6,     6,   557,  1416,   559,  1418,   561,   562,   563,     6,
       6,     6,     6,     6,     6,     6,     6,  1494,     5,   266,
     270,   129,   129,  1436,   129,   266,     6,   582,   583,   201,
       6,     4,     6,   269,   269,     7,  1449,     6,   269,     7,
    1453,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   269,
     269,  1624,  1625,   264,   267,   266,     6,  1613,  1416,     6,
    1418,   270,   270,     6,     6,     6,     6,  1555,   197,   269,
       6,   149,     7,     6,     6,     6,  1601,  1824,     6,     4,
    1605,   269,   109,     7,     6,     6,     6,     6,   266,   265,
       6,   265,   269,   760,   274,   274,  1519,  1520,  1521,   274,
     665,   274,     5,   111,  1527,  1528,  1529,   271,     6,   269,
    1597,   265,     6,   266,   270,     6,   681,   149,   269,   274,
       6,     6,   269,  1546,   269,   269,   269,     6,   149,   266,
       6,     6,   274,   274,   274,     6,   274,   269,  1561,   269,
       6,     6,     6,     6,     6,     6,     6,   269,     7,  1572,
     269,  1574,     5,   269,   719,   720,   721,   722,   723,   724,
     725,   726,   727,   269,   729,   730,   731,   732,   153,   266,
     735,   736,   737,  1660,     6,   269,     6,  1733,     7,   269,
     745,     6,   270,   748,   269,    13,    14,     6,     6,   754,
    1678,   270,   269,  1616,     6,     6,   266,   196,   270,   270,
       7,  1624,  1625,  1561,     6,     6,     6,  1630,     6,   270,
       6,     6,   269,   271,     6,   270,     6,   266,     6,   269,
       6,     6,   199,     6,   269,   790,  1649,   792,   270,     6,
     265,   270,   266,     6,     6,   149,     6,  1660,   269,     6,
       6,   266,  1665,     6,   809,   269,     6,     6,     6,   269,
       6,     6,   270,  1816,  1827,   820,   269,   269,     6,   270,
     270,     6,   929,     6,  1422,  2179,   489,  1754,  1486,  1994,
    1953,   269,     3,   269,   269,  1741,  1448,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
       3,   576,  1673,   121,   122,   123,   124,     3,     3,   966,
     636,   129,  1097,  2027,  1594,  1792,     3,  1416,  1817,  1799,
     138,   139,  1799,  1800,   142,   143,  2063,   145,   146,  1625,
     148,    -1,  1745,   809,    -1,    -1,    -1,  1750,  1751,    -1,
      -1,  1818,    -1,    -1,    -1,    -1,    -1,    -1,   166,    -1,
      -1,    -1,  1758,  1759,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1775,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1784,    -1,    -1,    -1,   193,   194,   195,    -1,    -1,
      -1,  1794,    -1,    -1,  1797,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1813,    -1,  1750,  1751,  1817,    -1,    -1,    -1,    -1,    -1,
      -1,  1824,    -1,  1826,  1827,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1079,    -1,    -1,    -1,   981,  1775,   983,   984,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1095,    -1,
      -1,    -1,   997,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1863,    -1,   270,    -1,  1009,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   149,    -1,    -1,    -1,    -1,
     154,   155,   156,    -1,    -1,    -1,  1031,    -1,  1955,    -1,
      -1,    -1,    -1,    -1,  1897,  1898,  1143,  1144,    -1,  1146,
    1147,  1148,    -1,  1150,  1151,  1152,  1153,  1154,  1155,  1156,
      -1,  1158,  1159,  1160,    -1,    -1,    -1,    -1,    -1,  1922,
      -1,    -1,    -1,    -1,    -1,  1070,    -1,    -1,   202,     6,
      -1,    -1,  1999,    -1,    -1,  2040,    -1,    -1,  1941,    -1,
      -1,    -1,    -1,    -1,   218,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1205,  1897,
    1898,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1113,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1979,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1238,  1995,    -1,    -1,    -1,    -1,  2000,    -1,    -1,
    2003,  2004,    -1,  1941,    -1,    -1,    -1,  1254,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2025,    -1,    -1,  2028,  2131,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2031,  2039,    -1,    -1,    -1,
    2108,    -1,    -1,    -1,  2112,  2048,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1303,    -1,    -1,    -1,
    2063,  1206,  1207,    -1,    -1,  2003,  2004,    -1,  2173,    -1,
      -1,    -1,    -1,  2076,    -1,  1322,    -1,  1324,  1325,    -1,
    2147,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2028,  2159,    -1,    -1,    -1,  2163,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2109,    -1,    -1,    -1,
    2048,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1373,    -1,    -1,    -1,
      -1,    -1,    -1,  1278,    -1,    28,    -1,    30,    -1,    -1,
      -1,    -1,    -1,  2211,  2212,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2157,    -1,     6,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   438,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,     6,    -1,    -1,    -1,   264,    -1,  1436,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1342,    -1,    -1,
      -1,  1346,  1449,  2206,    -1,    -1,  1453,    -1,    -1,    -1,
    1355,    -1,  1357,    -1,    -1,  1360,    -1,    -1,    -1,  2157,
      -1,    -1,  1367,    -1,    -1,    -1,  2229,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2240,    -1,    -1,
      -1,  2244,  2245,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2257,    -1,   149,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1411,    -1,    -1,    -1,
      -1,    -1,  1519,  1520,  1521,    -1,    -1,    -1,    -1,    -1,
    1527,  1528,  1529,   557,    -1,   559,    -1,   561,   562,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1546,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   582,   583,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1572,    -1,  1574,    -1,    -1,
      -1,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,    -1,   257,   258,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   267,   268,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1630,    -1,    -1,    -1,     6,    -1,    -1,
     283,   284,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
      -1,    -1,    -1,  1660,   264,    -1,    -1,    -1,    -1,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,    -1,    -1,    -1,
      -1,   264,    -1,    -1,    -1,    -1,   720,     6,   722,   723,
     724,   725,   726,   727,    -1,   729,   730,   731,   732,    -1,
      -1,   735,   736,   737,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1624,
    1625,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1745,    -1,
     393,    -1,     4,     5,  1649,    -1,    -1,   400,   401,   402,
      -1,    -1,    -1,   406,   407,   408,   409,   410,   411,   412,
      -1,   414,    -1,    -1,    -1,    -1,   419,   420,    -1,    -1,
     423,    -1,    -1,    -1,    -1,   809,    -1,  1784,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   820,    -1,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    -1,    -1,    -1,
      -1,    63,    64,    65,    66,    -1,  1813,    -1,    -1,    71,
      72,    73,    74,    -1,    -1,    -1,    -1,    -1,    80,  1826,
      82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    98,    -1,    -1,   101,
      -1,    -1,    -1,   105,    -1,     6,   108,    -1,    -1,   111,
      -1,   113,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   124,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,     6,    -1,   145,    -1,   264,    -1,    -1,    -1,  1794,
      -1,    -1,  1797,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1810,    -1,  1812,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1922,    -1,    -1,    -1,    -1,
      -1,    -1,  1827,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,    -1,    -1,    -1,   597,   264,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   217,   218,   219,  1863,    -1,
      -1,    -1,    -1,    -1,    -1,   109,    -1,   229,    -1,    -1,
      -1,   233,  1979,   235,   236,    -1,    -1,    -1,   122,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1995,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   266,   149,   268,   269,    -1,   153,
      -1,    -1,    -1,    -1,   158,    -1,    -1,    -1,  2025,    -1,
      -1,   165,    -1,    -1,   168,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2039,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       6,    -1,    -1,   187,   188,   189,    -1,   191,   192,   193,
      -1,   195,   196,   197,   198,   199,   200,   201,    -1,   203,
     204,   205,   206,    -1,    -1,    -1,    -1,   211,    -1,  2076,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1113,
      -1,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,    -1,
      -1,    -1,  2109,   264,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,    -1,    -1,    -1,    -1,   264,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   291,   292,   293,
     294,   295,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   310,   311,   312,    -1,
      -1,    -1,  1206,  1207,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   328,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   338,   339,    -1,    -1,    -1,  2206,
     344,    -1,   346,   347,   348,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2121,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   369,   370,    -1,    -1,    -1,
      -1,    -1,    -1,  2240,    -1,    -1,   380,    -1,   382,   383,
      -1,   385,    -1,    -1,    -1,   389,   390,   391,    -1,    -1,
     394,    -1,    -1,    -1,   398,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     923,    -1,  2177,    -1,    -1,    -1,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,    -1,  2200,   440,   441,   264,    -1,
      -1,    -1,    -1,   956,    -1,    -1,    -1,    -1,  1342,    -1,
      -1,    -1,  1346,   457,   458,    -1,    -1,    -1,    -1,    -1,
      -1,  1355,    -1,  1357,  2229,    -1,  1360,    -1,   472,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2244,
    2245,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     494,    -1,  2257,    -1,    -1,   499,    -1,    -1,    -1,   503,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   517,   518,    -1,    -1,  1411,   522,    -1,
      -1,    -1,   526,   527,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   537,   538,   539,   540,   541,   542,   543,
     544,   545,   546,   547,   548,   549,   550,   551,   552,   553,
      -1,   555,   556,    -1,   558,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   568,    -1,    -1,   571,   572,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     584,    -1,    -1,    -1,    -1,   589,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   601,   602,   603,
     604,   605,   606,   607,   608,   609,   610,   611,   612,   613,
     614,   615,   616,   617,   618,   619,   620,     6,   622,   623,
    1133,    -1,    -1,    -1,    -1,    -1,   630,   631,   632,    -1,
      -1,    -1,    -1,    -1,   638,   639,   640,   641,    -1,   643,
     644,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   662,   663,
     664,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     674,   675,    -1,   677,    -1,    -1,   680,    -1,    -1,    -1,
     684,   685,   686,   687,    -1,    -1,    -1,   691,   692,   693,
     694,   695,    -1,    -1,   698,    -1,   700,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   710,    -1,    -1,   713,
      -1,   715,   716,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   728,    -1,  1239,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   742,    -1,
      -1,    -1,    -1,    -1,    -1,   749,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   757,    -1,  1649,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     6,    -1,    -1,    -1,    -1,
      -1,    -1,   776,    -1,   778,    -1,    -1,    -1,    -1,   783,
     784,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   798,     6,   800,   801,    -1,    -1,
     804,    -1,   806,   807,    -1,    -1,    -1,   811,    -1,   813,
      -1,   815,    -1,    -1,    -1,    -1,    -1,   821,    -1,    -1,
      -1,   825,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   211,    -1,    -1,    -1,    -1,    -1,    -1,
     844,    -1,    -1,    -1,    -1,   849,    -1,   851,    -1,   853,
      -1,    -1,    -1,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,    -1,    -1,    -1,    -1,   264,    -1,    -1,    -1,    -1,
    1393,  1394,    -1,    -1,    -1,   889,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   899,   900,   901,   902,    -1,
    1794,    -1,    -1,  1797,    -1,   909,   910,   911,    -1,   913,
     914,    -1,    -1,   917,   292,    -1,    -1,   295,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   311,   312,    -1,    -1,    -1,    -1,    -1,
      -1,   945,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   957,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   965,    -1,    -1,    -1,   969,    -1,    -1,   346,   347,
      -1,   975,    -1,    -1,   978,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   986,   987,    -1,    -1,  1499,    -1,   992,    -1,
      -1,    -1,   370,    -1,    -1,  1508,    -1,  1001,    -1,    -1,
    1004,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,    -1,
      -1,    -1,    -1,   264,    -1,    -1,  1030,    -1,  1032,  1033,
      -1,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,    -1,
      -1,  1055,    -1,   264,    -1,    -1,    -1,    -1,    -1,     4,
       5,    -1,   440,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1075,    -1,    -1,    -1,    -1,    -1,    -1,  1082,    -1,
      -1,    -1,    -1,    -1,    -1,  1089,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1102,  1103,
      -1,    -1,    -1,    -1,  1108,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    -1,    -1,    -1,    -1,    63,    64,
      65,    66,    -1,    -1,    -1,    -1,    71,    72,    73,    74,
      -1,    -1,    -1,    -1,    -1,    80,  1140,    82,    -1,    -1,
     518,    -1,    -1,    -1,     6,    -1,    -1,    -1,    -1,    -1,
      -1,  1664,    -1,    98,    -1,    -1,   101,    -1,    -1,    -1,
     105,    -1,    -1,   108,    -1,   543,   111,    -1,   113,    -1,
      -1,    -1,    -1,    -1,   552,   553,    -1,  1181,    -1,   124,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1191,  1192,  1193,
    1194,  1195,    -1,    -1,    -1,    -1,  1200,  1201,    -1,  1203,
     145,     6,    -1,    -1,    -1,    -1,   584,    -1,    -1,    -1,
      -1,   589,    -1,    -1,    -1,    -1,    -1,  1221,    -1,    -1,
      -1,    -1,  1226,  1227,    -1,    -1,    -1,    -1,    -1,    -1,
    1234,  1235,    -1,    -1,    -1,    -1,    -1,   615,    -1,  1243,
    1244,     6,    -1,    -1,    -1,  1249,  1250,    -1,    -1,    -1,
      -1,  1255,  1256,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   643,   644,    -1,    -1,    -1,
      -1,    -1,   217,   218,   219,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   229,    -1,  1290,    -1,   233,    -1,
     235,   236,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   684,   685,   686,    -1,
      -1,    -1,    -1,    -1,   692,    -1,  1320,   262,   263,    -1,
      -1,    -1,    -1,    -1,   269,    -1,   271,    -1,  1332,  1333,
      -1,    -1,    -1,  1337,    -1,  2229,    -1,    -1,    -1,    -1,
      -1,  1345,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2244,  2245,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2257,   742,  1369,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1380,    -1,    -1,  1383,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   776,    -1,
      -1,    -1,   264,    -1,    -1,    -1,    -1,    -1,  1412,    -1,
      -1,  1415,  1416,  1417,  1418,    -1,    -1,    -1,    -1,    -1,
     798,    -1,  1426,    -1,    -1,  1429,   804,  1431,   806,  1433,
    1434,    -1,    -1,  1437,  1438,  1439,    -1,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,    -1,    -1,    -1,  1462,   264,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   851,    -1,   853,    -1,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,    -1,    -1,    -1,    -1,   264,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   889,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   899,  1526,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1537,  1538,  1539,   914,    -1,    -1,    -1,
      -1,    -1,  1546,    -1,  1548,    -1,    -1,    -1,    -1,    -1,
      -1,  1555,    -1,    -1,    -1,    -1,    -1,  1561,    -1,    -1,
      -1,     4,     5,  1567,  1568,    -1,    -1,   945,    -1,    -1,
      -1,    -1,    -1,    -1,  1578,  1579,  1580,    -1,    -1,   957,
      -1,    -1,    -1,    -1,    -1,  1589,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1599,    -1,    -1,    -1,    -1,
     978,    -1,    -1,    -1,    -1,    -1,    -1,    50,    51,    52,
      53,    54,    55,    56,    57,    58,  1620,    -1,    -1,    -1,
      63,    64,    65,    66,  1628,  1629,    -1,    -1,    71,    72,
      73,    74,    -1,    -1,    -1,    -1,    -1,    80,    -1,    82,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    98,    -1,    -1,   101,    -1,
      -1,  1665,   105,    -1,    -1,   108,    -1,    -1,   111,    -1,
     113,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   124,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   145,     6,  1708,  1709,  1710,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1725,    -1,    -1,    -1,    -1,  1730,  1731,    -1,    -1,
    1108,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1743,
       6,    -1,    -1,    -1,    -1,    -1,  1750,  1751,  1752,    -1,
    1754,    -1,    -1,    -1,    -1,    -1,  1760,  1761,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   149,    -1,    -1,    -1,    -1,
      -1,  1775,  1776,    -1,   217,   218,   219,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1788,  1789,   229,    -1,  1792,    -1,
     233,  1795,   235,   236,    -1,  1799,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1809,    -1,    -1,    -1,     6,
     462,    -1,    -1,    -1,    -1,  1819,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   269,    -1,    -1,  1833,
      -1,    -1,    -1,    -1,  1838,  1839,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1853,
      -1,    -1,  1856,  1857,    -1,  1859,    -1,    -1,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,  1880,  1255,  1256,     6,
     264,    -1,  1886,  1887,  1888,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1897,  1898,    -1,    -1,    -1,    -1,    -1,
    1904,  1905,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1916,    -1,    -1,    -1,    -1,   569,    -1,    -1,
      -1,  1925,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1936,  1937,    -1,    -1,  1940,  1941,    -1,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,    -1,    -1,  1337,
      -1,   264,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1976,  1977,   626,    -1,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,  1998,    -1,    -1,    -1,   264,  2003,
    2004,  2005,    -1,    -1,    -1,    -1,  2010,    -1,    -1,    -1,
    2014,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2028,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1416,    -1,
    1418,  2045,    -1,    -1,  2048,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,     6,    -1,    -1,    -1,   264,    -1,  2073,
      -1,    -1,    -1,    -1,    -1,  2079,    -1,    -1,  2082,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     6,    -1,    -1,    -1,
      -1,    -1,    -1,  2097,    -1,  2099,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     6,
      -1,    -1,    -1,  2117,    -1,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,  2137,  2138,    -1,    -1,   264,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2152,    -1,
      -1,    -1,    -1,  2157,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2170,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2179,    -1,    -1,    -1,  2183,
      -1,    -1,    -1,  1561,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2204,    -1,    -1,    -1,    -1,  2209,   858,   859,   860,   861,
     862,   863,   864,   865,   866,   867,   868,   869,    -1,   871,
     872,   873,   874,    -1,   876,   877,   878,   879,    -1,    -1,
    2234,  2235,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     892,    -1,   894,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   905,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   919,   920,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   928,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1665,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,    -1,    -1,    -1,
      -1,   264,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
      -1,    -1,    -1,    -1,   264,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,    -1,    -1,    -1,    -1,   264,    -1,    -1,
      -1,    -1,  1750,  1751,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1041,
    1042,  1043,    -1,    -1,    -1,  1047,  1048,  1775,    -1,  1051,
    1052,  1053,  1054,    -1,  1056,    -1,    -1,    -1,    -1,  1061,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,    -1,
      -1,    -1,    -1,    10,    11,    12,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    59,    60,    61,    62,    -1,    -1,    -1,    -1,
      67,    68,    -1,    -1,    -1,    -1,    -1,  1139,    -1,  1141,
      77,    78,    79,    -1,    -1,    -1,    83,    84,    85,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    96,
      97,    -1,    99,    -1,    -1,    -1,    -1,    -1,   105,  1897,
    1898,   108,    -1,    -1,   111,    -1,   113,    -1,    -1,    -1,
      -1,    -1,    -1,   120,    -1,    -1,    -1,   124,   125,   126,
      -1,    -1,   129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   138,    -1,   140,   141,    -1,   143,    -1,   145,    -1,
      -1,   148,    -1,  1941,    -1,    -1,    -1,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,    -1,
      -1,    -1,   169,    -1,    -1,    -1,   173,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1252,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   198,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2003,  2004,    -1,     6,   216,
      -1,    -1,    -1,   220,   221,    -1,    -1,    -1,    -1,   226,
     227,   228,    -1,   230,   231,   232,    -1,    -1,    -1,   236,
    2028,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   253,   254,    -1,    -1,
    2048,    -1,    -1,   260,    -1,    -1,    -1,    -1,   265,    -1,
      -1,    -1,   269,    -1,    -1,   272,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,    -1,     7,    -1,
      -1,    10,    11,    12,    -1,    -1,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1392,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    -1,
      -1,    -1,    71,    72,    73,    74,    -1,    -1,    -1,    -1,
      -1,    80,    -1,    82,    83,    84,    85,    -1,    -1,  2157,
      -1,    -1,    -1,  1435,    -1,    -1,    -1,    96,    97,    98,
      99,    -1,   101,    -1,    -1,    -1,   105,    -1,    -1,   108,
      -1,    -1,   111,    -1,   113,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   124,    -1,  1469,  1470,  1471,
    1472,  1473,  1474,  1475,    -1,    -1,    -1,    -1,  1480,  1481,
      -1,    -1,    -1,    -1,    -1,  1487,   145,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1497,    -1,    -1,    -1,  1501,
      -1,    -1,  1504,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1515,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,    -1,    -1,    -1,    -1,   264,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     209,    -1,    -1,    -1,     7,     8,    -1,   216,   217,   218,
     219,   220,    -1,    -1,    -1,    -1,    -1,   226,   227,   228,
     229,   230,   231,   232,   233,    -1,   235,   236,    -1,   238,
     239,   240,   241,  1585,    -1,  1587,    -1,    -1,    -1,  1591,
      -1,  1593,    -1,    -1,   253,   254,    -1,    -1,    -1,    -1,
      -1,   260,    -1,   262,   263,    -1,   265,    -1,   267,    -1,
      -1,    -1,   271,   272,    -1,    -1,    -1,    -1,     3,     4,
       5,    -1,  1624,     8,    -1,    10,    11,    12,    -1,    -1,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,     7,    -1,    -1,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    -1,    -1,    71,    72,    73,    74,
       8,    -1,    77,    78,    79,    80,    -1,    82,    83,    84,
      85,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    96,    97,    98,    99,    -1,   101,    -1,    -1,    -1,
     105,    -1,    -1,   108,    -1,    -1,   111,    -1,   113,    -1,
    1732,    -1,    -1,    -1,    -1,   120,    -1,    -1,    -1,   124,
     125,   126,    -1,    -1,   129,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   138,    -1,   140,   141,    -1,   143,    -1,
     145,    -1,    -1,   148,    -1,    -1,    -1,    -1,    -1,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,    -1,    -1,    -1,   169,    -1,    -1,    -1,   173,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,    -1,    -1,    -1,
      -1,   264,    -1,   198,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1829,    -1,    -1,
    1832,   216,   217,   218,   219,   220,   221,    -1,    -1,    -1,
      -1,   226,   227,   228,   229,   230,   231,   232,   233,    -1,
     235,   236,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   253,   254,
      -1,    -1,    -1,    -1,    -1,   260,    -1,    -1,    -1,    -1,
     265,  1883,  1884,    -1,    -1,   270,     8,   272,  1890,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,    -1,    -1,    -1,    -1,   264,
      -1,    -1,    -1,    -1,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,    -1,    -1,  1946,  1947,   264,    -1,     3,     4,
       5,    -1,    -1,     8,    -1,    10,    11,    12,    -1,    -1,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    -1,    -1,  1996,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    -1,    -1,    71,    72,    73,    74,
      -1,    -1,    77,    78,    79,    80,    -1,    82,    83,    84,
      85,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    96,    97,    98,    99,    -1,   101,    -1,    -1,    -1,
     105,    -1,    -1,   108,    -1,    -1,   111,    -1,   113,    -1,
      -1,    -1,    -1,    -1,    -1,   120,    -1,    -1,    -1,   124,
     125,   126,    -1,    -1,   129,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   138,    -1,   140,   141,    -1,   143,    -1,
     145,    -1,    -1,   148,    -1,    -1,    -1,    -1,    -1,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,    -1,    -1,    -1,   169,    -1,    -1,    -1,   173,    -1,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,    -1,    -1,
      -1,    -1,   264,   198,    -1,    -1,    -1,    -1,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   216,   217,   218,   219,   220,   221,    -1,    -1,    -1,
      -1,   226,   227,   228,   229,   230,   231,   232,   233,    -1,
     235,   236,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   253,   254,
      -1,    -1,    -1,    -1,    -1,   260,    -1,    -1,    -1,    -1,
     265,     3,     4,     5,    -1,    -1,    -1,   272,    10,    11,
      12,  2223,    -1,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    -1,    -1,    -1,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    -1,    -1,    71,
      72,    73,    74,    -1,    -1,    77,    78,    79,    80,    -1,
      82,    83,    84,    85,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    96,    97,    98,    99,    -1,   101,
      -1,    -1,    -1,   105,    -1,    -1,   108,    -1,    -1,   111,
      -1,   113,    -1,    -1,    -1,    -1,    -1,    -1,   120,    -1,
      -1,    -1,   124,   125,   126,    -1,    -1,   129,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   138,    -1,   140,   141,
      -1,   143,    -1,   145,    -1,    -1,   148,    -1,    -1,    -1,
      -1,    -1,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,    -1,    -1,    -1,   169,    -1,    -1,
      -1,   173,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
      -1,    -1,    -1,    -1,   264,    -1,   198,    -1,    -1,    -1,
      -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   216,   217,   218,   219,   220,   221,
      -1,    -1,    -1,    -1,   226,   227,   228,   229,   230,   231,
     232,   233,    -1,   235,   236,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   253,   254,    -1,    -1,    -1,    -1,    -1,   260,    -1,
      -1,    -1,    -1,   265,     3,     4,     5,   269,    -1,    -1,
     272,    10,    11,    12,    -1,    -1,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    -1,    -1,
      -1,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      -1,    -1,    71,    72,    73,    74,    -1,    -1,    77,    78,
      79,    80,    -1,    82,    83,    84,    85,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    96,    97,    98,
      99,    -1,   101,    -1,    -1,    -1,   105,    -1,    -1,   108,
      -1,    -1,   111,    -1,   113,    -1,    -1,    -1,    -1,    -1,
      -1,   120,    -1,    -1,    -1,   124,   125,   126,    -1,    -1,
     129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,
      -1,   140,   141,    -1,   143,    -1,   145,    -1,    -1,   148,
      -1,    -1,    -1,    -1,    -1,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,    -1,    -1,    -1,
     169,    -1,    -1,    -1,   173,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,    -1,    -1,    -1,    -1,   264,    -1,   198,
      -1,    -1,    -1,    -1,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   216,   217,   218,
     219,   220,   221,    -1,    -1,    -1,    -1,   226,   227,   228,
     229,   230,   231,   232,   233,    -1,   235,   236,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   253,   254,    -1,    -1,    -1,    -1,
      -1,   260,    -1,    -1,    -1,    -1,   265,     3,     4,    -1,
     269,    -1,     8,   272,    10,    11,    12,    -1,    -1,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    59,    60,    61,    62,    -1,    -1,    -1,
      -1,    67,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    77,    78,    79,    -1,    -1,    -1,    83,    84,    85,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      96,    97,    -1,    99,    -1,    -1,    -1,    -1,    -1,   105,
      -1,    -1,   108,    -1,    -1,   111,    -1,   113,    -1,    -1,
      -1,    -1,    -1,    -1,   120,    -1,    -1,    -1,   124,   125,
     126,    -1,    -1,   129,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   138,    -1,   140,   141,    -1,   143,    -1,   145,
      -1,    -1,   148,    -1,    -1,    -1,    -1,    -1,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
      -1,    -1,    -1,   169,    -1,    -1,    -1,   173,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,    -1,    -1,    -1,    -1,
     264,    -1,   198,    -1,    -1,    -1,    -1,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     216,    -1,    -1,    -1,   220,   221,    -1,    -1,    -1,    -1,
     226,   227,   228,    -1,   230,   231,   232,    -1,    -1,    -1,
     236,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   253,   254,    -1,
      -1,    -1,    -1,    -1,   260,    -1,    -1,    -1,    -1,   265,
       3,     4,     5,    -1,   270,    -1,   272,    10,    11,    12,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    59,    60,    61,    62,
      -1,    -1,    -1,    -1,    67,    68,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    77,    78,    79,    -1,    -1,    -1,
      83,    84,    85,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    96,    97,    -1,    99,    -1,    -1,    -1,
      -1,    -1,   105,    -1,    -1,   108,    -1,    -1,   111,    -1,
     113,    -1,    -1,    -1,    -1,    -1,    -1,   120,    -1,    -1,
      -1,   124,   125,   126,    -1,    -1,   129,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   138,    -1,   140,   141,    -1,
     143,    -1,   145,    -1,    -1,   148,    -1,    -1,    -1,    -1,
      -1,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,    -1,    -1,    -1,   169,    -1,    -1,    -1,
     173,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,    -1,
      -1,    -1,    -1,   264,    -1,   198,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   216,    -1,    -1,    -1,   220,   221,    -1,
      -1,    -1,    -1,   226,   227,   228,    -1,   230,   231,   232,
      -1,    -1,    -1,   236,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     253,   254,    -1,    -1,    -1,    -1,    -1,   260,    -1,    -1,
      -1,    -1,   265,     3,     4,    -1,   269,    -1,    -1,   272,
      10,    11,    12,    -1,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,
      60,    61,    62,    -1,    -1,    -1,    -1,    67,    68,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,    78,    79,
      -1,    -1,    -1,    83,    84,    85,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    96,    97,    -1,    99,
      -1,    -1,    -1,    -1,    -1,   105,    -1,    -1,   108,    -1,
      -1,   111,    -1,   113,    -1,    -1,    -1,    -1,    -1,    -1,
     120,    -1,    -1,    -1,   124,   125,   126,    -1,    -1,   129,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,    -1,
     140,   141,     5,   143,    -1,   145,    -1,    -1,   148,    -1,
      -1,    -1,    -1,    -1,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,    -1,    -1,    -1,   169,
      -1,    -1,    -1,   173,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    -1,    -1,   198,    -1,
      63,    64,    65,    66,    -1,    -1,    -1,    -1,    71,    72,
      73,    74,    -1,    -1,    -1,    -1,   216,    80,    -1,    82,
     220,   221,    -1,    -1,    -1,    -1,   226,   227,   228,    -1,
     230,   231,   232,    -1,    -1,    98,   236,    -1,   101,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   253,   254,    -1,    -1,    -1,    -1,    -1,
     260,    -1,    -1,    -1,    -1,   265,     3,     4,    -1,   269,
      -1,    -1,   272,    10,    11,    12,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    59,    60,    61,    62,    -1,    -1,    -1,    -1,
      67,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      77,    78,    79,    -1,    -1,    -1,    83,    84,    85,    -1,
      -1,    -1,    -1,    -1,   217,   218,   219,    -1,    -1,    96,
      97,    -1,    99,    -1,    -1,    -1,   229,    -1,   105,    -1,
     233,   108,   235,    -1,   111,    -1,   113,    -1,    -1,    -1,
      -1,    -1,    -1,   120,    -1,    -1,    -1,   124,   125,   126,
      -1,    -1,   129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   138,    -1,   140,   141,    -1,   143,    -1,   145,    -1,
      -1,   148,    -1,    -1,    -1,    -1,    -1,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,    -1,
      -1,    -1,   169,    -1,    -1,    -1,   173,    -1,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,    -1,    -1,    -1,    -1,
     264,   198,   266,    -1,   268,    -1,    -1,    -1,    -1,    -1,
     274,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   216,
      -1,    -1,    -1,   220,   221,    -1,    -1,    -1,    -1,   226,
     227,   228,    -1,   230,   231,   232,    -1,    -1,    -1,   236,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   253,   254,    -1,    -1,
      -1,    -1,    -1,   260,    -1,    -1,    -1,    -1,   265,     3,
       4,    -1,   269,    -1,    -1,   272,    10,    11,    12,    -1,
      -1,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    59,    60,    61,    62,    -1,
      -1,    -1,    -1,    67,    68,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    77,    78,    79,    -1,    -1,    -1,    83,
      84,    85,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    96,    97,    -1,    99,    -1,    -1,    -1,    -1,
      -1,   105,    -1,    -1,   108,    -1,    -1,   111,    -1,   113,
      -1,    -1,    -1,    -1,    -1,    -1,   120,    -1,    -1,    -1,
     124,   125,   126,    -1,    -1,   129,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   138,    -1,   140,   141,    -1,   143,
      -1,   145,    -1,    -1,   148,    -1,    -1,    -1,    -1,    -1,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,    -1,    -1,    -1,   169,    -1,    -1,    -1,   173,
      -1,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,    -1,
      -1,    -1,    -1,   264,   198,   266,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   274,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   216,    -1,    -1,    -1,   220,   221,    -1,    -1,
      -1,    -1,   226,   227,   228,    -1,   230,   231,   232,    -1,
      -1,    -1,   236,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   253,
     254,    -1,    -1,    -1,    -1,    -1,   260,    -1,    -1,    -1,
      -1,   265,     3,     4,    -1,   269,    -1,    -1,   272,    10,
      11,    12,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,    60,
      61,    62,    -1,    -1,    -1,    -1,    67,    68,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    77,    78,    79,    -1,
      -1,    -1,    83,    84,    85,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    96,    97,    -1,    99,    -1,
      -1,    -1,    -1,    -1,   105,    -1,    -1,   108,    -1,    -1,
     111,    -1,   113,    -1,    -1,    -1,    -1,    -1,    -1,   120,
      -1,    -1,    -1,   124,   125,   126,    -1,    -1,   129,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,    -1,   140,
     141,    -1,   143,    -1,   145,    -1,    -1,   148,    -1,    -1,
      -1,    -1,    -1,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,    -1,    -1,    -1,   169,    -1,
      -1,    -1,   173,    -1,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,    -1,    -1,    -1,    -1,   264,   198,   266,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   274,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   216,    -1,    -1,    -1,   220,
     221,    -1,    -1,    -1,    -1,   226,   227,   228,    -1,   230,
     231,   232,    -1,    -1,    -1,   236,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   253,   254,    -1,    -1,    -1,    -1,    -1,   260,
      -1,    -1,    -1,    -1,   265,     3,     4,    -1,    -1,   270,
      -1,   272,    10,    11,    12,    -1,    -1,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    59,    60,    61,    62,    -1,    -1,    -1,    -1,    67,
      68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,
      78,    79,    -1,    -1,    -1,    83,    84,    85,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    96,    97,
      -1,    99,    -1,    -1,    -1,    -1,    -1,   105,    -1,    -1,
     108,    -1,    -1,   111,    -1,   113,    -1,    -1,    -1,    -1,
      -1,    -1,   120,    -1,    -1,    -1,   124,   125,   126,    -1,
      -1,   129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     138,    -1,   140,   141,    -1,   143,    -1,   145,    -1,    -1,
     148,    -1,    -1,    -1,    -1,    -1,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,    -1,    -1,
      -1,   169,    -1,    -1,    -1,   173,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,    -1,    -1,    -1,    -1,   264,    -1,
     198,    -1,    -1,    -1,   270,    -1,    -1,    -1,   274,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   216,    -1,
      -1,    -1,   220,   221,    -1,    -1,    -1,    -1,   226,   227,
     228,    -1,   230,   231,   232,    -1,    -1,    -1,   236,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   253,   254,    -1,    -1,    -1,
      -1,    -1,   260,    -1,    -1,    -1,    -1,   265,     3,     4,
      -1,   269,    -1,    -1,   272,    10,    11,    12,    -1,    -1,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    59,    60,    61,    62,    -1,    -1,
      -1,    -1,    67,    68,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    77,    78,    79,    -1,    -1,    -1,    83,    84,
      85,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    96,    97,    -1,    99,    -1,    -1,    -1,    -1,    -1,
     105,    -1,    -1,   108,    -1,    -1,   111,    -1,   113,    -1,
      -1,    -1,    -1,    -1,    -1,   120,    -1,    -1,    -1,   124,
     125,   126,    -1,    -1,   129,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   138,    -1,   140,   141,    -1,   143,    -1,
     145,    -1,    -1,   148,    -1,    -1,    -1,    -1,    -1,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,    -1,    -1,    -1,   169,    -1,    -1,    -1,   173,    -1,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,    -1,    -1,
      -1,    -1,   264,   198,   266,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   274,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   216,    -1,    -1,    -1,   220,   221,    -1,    -1,    -1,
      -1,   226,   227,   228,    -1,   230,   231,   232,    -1,    -1,
      -1,   236,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   253,   254,
      -1,    -1,    -1,    -1,    -1,   260,    -1,    -1,    -1,    -1,
     265,     3,     4,    -1,   269,    -1,    -1,   272,    10,    11,
      12,    -1,    -1,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,    60,    61,
      62,    -1,    -1,    -1,    -1,    67,    68,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    77,    78,    79,    -1,    -1,
      -1,    83,    84,    85,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    96,    97,    -1,    99,    -1,    -1,
      -1,    -1,    -1,   105,    -1,    -1,   108,    -1,    -1,   111,
      -1,   113,    -1,    -1,    -1,    -1,    -1,    -1,   120,    -1,
      -1,    -1,   124,   125,   126,    -1,    -1,   129,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   138,    -1,   140,   141,
      -1,   143,    -1,   145,    -1,    -1,   148,    -1,    -1,    -1,
      -1,    -1,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,    -1,    -1,    -1,   169,    -1,    -1,
      -1,   173,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
      -1,    -1,    -1,    -1,   264,    -1,   198,    -1,    -1,    -1,
     270,    -1,    -1,    -1,   274,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   216,    -1,    -1,    -1,   220,   221,
      -1,    -1,    -1,    -1,   226,   227,   228,    -1,   230,   231,
     232,    -1,    -1,    -1,   236,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   253,   254,    -1,    -1,    -1,    -1,    -1,   260,    -1,
      -1,    -1,    -1,   265,     3,     4,    -1,   269,    -1,     8,
     272,    10,    11,    12,    -1,    -1,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      59,    60,    61,    62,    -1,    -1,    -1,    -1,    67,    68,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,    78,
      79,    -1,    -1,    -1,    83,    84,    85,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    96,    97,    -1,
      99,    -1,    -1,    -1,    -1,    -1,   105,    -1,    -1,   108,
      -1,    -1,   111,    -1,   113,    -1,    -1,    -1,    -1,    -1,
      -1,   120,    -1,    -1,    -1,   124,   125,   126,    -1,    -1,
     129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,
      -1,   140,   141,    -1,   143,    -1,   145,    -1,    -1,   148,
      -1,    -1,    -1,    -1,    -1,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,    -1,    -1,    -1,
     169,    -1,    -1,    -1,   173,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,    -1,    -1,    -1,    -1,   264,    -1,   198,
      -1,    -1,    -1,   270,    -1,    -1,    -1,   274,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   216,    -1,    -1,
      -1,   220,   221,    -1,    -1,    -1,    -1,   226,   227,   228,
      -1,   230,   231,   232,    -1,    -1,    -1,   236,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   253,   254,    -1,    -1,    -1,    -1,
      -1,   260,     3,     4,    -1,    -1,   265,    -1,    -1,    10,
      11,    12,    -1,   272,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,    60,
      61,    62,    -1,    -1,    -1,    -1,    67,    68,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    77,    78,    79,    -1,
      -1,    -1,    83,    84,    85,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    96,    97,    -1,    99,    -1,
      -1,    -1,    -1,    -1,   105,    -1,    -1,   108,    -1,    -1,
     111,    -1,   113,    -1,    -1,    -1,    -1,    -1,    -1,   120,
      -1,    -1,    -1,   124,   125,   126,    -1,    -1,   129,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,    -1,   140,
     141,    -1,   143,    -1,   145,    -1,    -1,   148,    -1,    -1,
      -1,    -1,    -1,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,    -1,    -1,    -1,   169,    -1,
      -1,    -1,   173,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,    -1,    -1,    -1,    -1,   264,    -1,   198,    -1,    -1,
      -1,   270,    -1,    -1,    -1,   274,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   216,    -1,    -1,    -1,   220,
     221,    -1,    -1,    -1,    -1,   226,   227,   228,    -1,   230,
     231,   232,    -1,    -1,    -1,   236,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   253,   254,    -1,    -1,    -1,    -1,    -1,   260,
      -1,    -1,    -1,    -1,   265,     3,     4,    -1,    -1,   270,
      -1,   272,    10,    11,    12,    -1,    -1,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    59,    60,    61,    62,    -1,    -1,    -1,    -1,    67,
      68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,
      78,    79,    -1,    -1,    -1,    83,    84,    85,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    96,    97,
      -1,    99,    -1,    -1,    -1,    -1,    -1,   105,    -1,    -1,
     108,    -1,    -1,   111,    -1,   113,    -1,    -1,    -1,    -1,
      -1,    -1,   120,    -1,    -1,    -1,   124,   125,   126,    -1,
      -1,   129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     138,    -1,   140,   141,    -1,   143,    -1,   145,    -1,    -1,
     148,    -1,    -1,    -1,    -1,    -1,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,    -1,    -1,
      -1,   169,    -1,    -1,    -1,   173,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,    -1,    -1,    -1,    -1,   264,    -1,
     198,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   274,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   216,    -1,
      -1,    -1,   220,   221,    -1,    -1,    -1,    -1,   226,   227,
     228,    -1,   230,   231,   232,    -1,    -1,    -1,   236,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   253,   254,    -1,    -1,    -1,
      -1,    -1,   260,     3,     4,     5,    -1,   265,    -1,    -1,
      10,    11,    12,    -1,   272,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    -1,    -1,
      -1,    71,    72,    73,    74,    -1,    -1,    -1,    -1,    -1,
      80,    -1,    82,    83,    84,    85,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    96,    97,    98,    99,
      -1,   101,     3,     4,     5,    -1,    -1,    -1,    -1,    10,
      11,    12,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    -1,    -1,    -1,
      71,    72,    73,    74,    -1,    -1,    -1,    -1,    -1,    80,
      -1,    82,    83,    84,    85,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    96,    97,    98,    99,    -1,
     101,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   216,   217,   218,   219,
     220,    -1,    -1,    -1,    -1,    -1,   226,   227,   228,   229,
     230,   231,   232,   233,    -1,   235,   236,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   253,   254,    -1,    -1,    -1,    -1,    -1,
     260,    -1,    -1,    -1,    -1,   265,    -1,    -1,    -1,   269,
      -1,    -1,   272,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,    -1,    -1,    -1,    -1,   264,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   274,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   216,   217,   218,   219,   220,
      -1,    -1,    -1,    -1,    -1,   226,   227,   228,   229,   230,
     231,   232,   233,    -1,   235,   236,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   253,   254,    -1,    -1,    -1,    -1,    -1,   260,
      -1,    -1,    -1,    -1,   265,     3,     4,     5,   269,    -1,
      -1,   272,    10,    11,    12,    -1,    -1,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      -1,    -1,    -1,    71,    72,    73,    74,    -1,    -1,    -1,
      -1,    -1,    80,    -1,    82,    83,    84,    85,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    96,    97,
      98,    99,    -1,   101,     3,     4,     5,    -1,    -1,    -1,
      -1,    10,    11,    12,    -1,    -1,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    -1,
      -1,    -1,    71,    72,    73,    74,    -1,    -1,    -1,    -1,
      -1,    80,    -1,    82,    83,    84,    85,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    96,    97,    98,
      99,    -1,   101,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   216,   217,
     218,   219,   220,    -1,    -1,    -1,    -1,    -1,   226,   227,
     228,   229,   230,   231,   232,   233,    -1,   235,   236,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   253,   254,    -1,    -1,    -1,
      -1,    -1,   260,    -1,    -1,    -1,    -1,   265,    -1,    -1,
      -1,   269,    -1,    -1,   272,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,    -1,    -1,    -1,    -1,   264,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   274,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   216,   217,   218,
     219,   220,    -1,    -1,    -1,    -1,    -1,   226,   227,   228,
     229,   230,   231,   232,   233,    -1,   235,   236,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   253,   254,    -1,    -1,    -1,    -1,
      -1,   260,     3,     4,    -1,     6,   265,    -1,    -1,    10,
      11,    12,    -1,   272,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,    60,
      61,    62,    -1,    -1,    -1,    -1,    67,    13,    14,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    83,    84,    85,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,    -1,    96,    97,    -1,    99,    10,
      11,    12,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,    60,
      61,    62,    -1,    -1,    -1,    -1,    67,    -1,    -1,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,    83,    84,    85,   121,   122,   123,   124,    -1,
      -1,    -1,    -1,   129,    -1,    96,    97,    -1,    99,    -1,
      -1,    -1,   138,   139,    -1,    -1,   142,   143,    -1,   145,
     146,    -1,   148,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   216,    -1,    -1,    -1,   220,
     166,    -1,    -1,    -1,    -1,   226,   227,   228,    -1,   230,
     231,   232,    -1,    -1,    -1,   236,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   193,   194,   195,
      -1,    -1,   253,   254,    -1,    -1,    -1,    -1,    -1,   260,
      -1,    -1,    -1,    -1,   265,    -1,    -1,    -1,    -1,    -1,
      -1,   272,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
      -1,    -1,    -1,    -1,   264,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   274,   216,    -1,    -1,    -1,   220,
      -1,    -1,    -1,    -1,    -1,   226,   227,   228,    -1,   230,
     231,   232,    -1,    -1,   270,   236,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   253,   254,    -1,    -1,    -1,    -1,    -1,   260,
      -1,    -1,    -1,    -1,   265,     3,     4,    -1,   269,    -1,
      -1,   272,    10,    11,    12,    -1,    -1,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    59,    60,    61,    62,    -1,    -1,    -1,    -1,    67,
      13,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    83,    84,    85,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,    -1,    96,    97,
       8,    99,    10,    11,    12,    -1,    -1,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    59,    60,    61,    62,    -1,    -1,    -1,    -1,    67,
      -1,    -1,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,    83,    84,    85,   121,   122,
     123,   124,    -1,    -1,    -1,    -1,   129,    -1,    96,    97,
      -1,    99,    -1,    -1,    -1,   138,   139,    -1,    -1,   142,
     143,    -1,   145,   146,    -1,   148,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   216,    -1,
      -1,    -1,   220,   166,    -1,    -1,    -1,    -1,   226,   227,
     228,    -1,   230,   231,   232,    -1,    -1,    -1,   236,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     193,   194,   195,    -1,    -1,   253,   254,    -1,    -1,    -1,
      -1,    -1,   260,    -1,    -1,    -1,    -1,   265,    -1,    -1,
      -1,   269,    -1,    -1,   272,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,    -1,    -1,    -1,    -1,   264,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   274,   216,    -1,
      -1,    -1,   220,    -1,    -1,    -1,    -1,    -1,   226,   227,
     228,    -1,   230,   231,   232,    -1,    -1,   270,   236,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   253,   254,    -1,    -1,    -1,
      -1,    -1,   260,     3,     4,    -1,    -1,   265,    -1,    -1,
      10,    11,    12,    -1,   272,    15,    16,    17,    18,    19,
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
      -1,    -1,    -1,    96,    97,    -1,    99,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,    -1,   216,    -1,    -1,   264,
     220,    -1,    -1,    -1,    -1,    -1,   226,   227,   228,   274,
     230,   231,   232,    -1,    -1,    -1,   236,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   253,   254,    -1,    -1,    -1,    -1,    -1,
     260,    -1,    -1,    -1,    -1,   265,   266,    -1,    -1,    -1,
      -1,    -1,   272,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,    -1,    -1,    -1,    -1,   264,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   274,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   216,    -1,    -1,    -1,   220,    -1,    -1,
      -1,    -1,    -1,   226,   227,   228,    -1,   230,   231,   232,
      -1,    -1,    -1,   236,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     253,   254,    -1,    -1,    -1,    -1,    -1,   260,     3,     4,
      -1,     6,   265,    -1,    -1,    10,    11,    12,    -1,   272,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    59,    60,    61,    62,    -1,    -1,
      -1,    -1,    67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    83,    84,
      85,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    96,    97,    -1,    99,     3,     4,    -1,     6,    -1,
      -1,    -1,    10,    11,    12,    -1,    -1,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    59,    60,    61,    62,    -1,    -1,    -1,    -1,    67,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    83,    84,    85,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    96,    97,
      -1,    99,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
      -1,   216,    -1,    -1,   264,   220,    -1,    -1,    -1,    -1,
      -1,   226,   227,   228,   274,   230,   231,   232,    -1,    -1,
      -1,   236,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   253,   254,
      -1,    -1,    -1,    -1,    -1,   260,    -1,     3,     4,    -1,
     265,    -1,    -1,    -1,    10,    11,    12,   272,    -1,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   216,    -1,
      -1,    -1,   220,    59,    60,    61,    62,    -1,   226,   227,
     228,    67,   230,   231,   232,    -1,    -1,    -1,   236,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    83,    84,    85,
      -1,    -1,    -1,    -1,    -1,   253,   254,    -1,    -1,    -1,
      96,    97,   260,    99,     3,     4,    -1,   265,    -1,    -1,
      -1,    10,    11,    12,   272,    -1,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      59,    60,    61,    62,    -1,    -1,    -1,    -1,    67,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    83,    84,    85,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    96,    97,    -1,
      99,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,    -1,
     216,    -1,    -1,   264,   220,    -1,    -1,    -1,    -1,    -1,
     226,   227,   228,   274,   230,   231,   232,    -1,    -1,    -1,
     236,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   253,   254,    -1,
      -1,    -1,    -1,    -1,   260,    -1,     3,     4,    -1,   265,
     266,    -1,    -1,    10,    11,    12,   272,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   216,    -1,    -1,
      -1,   220,    59,    60,    61,    62,    -1,   226,   227,   228,
      67,   230,   231,   232,    -1,    -1,    -1,   236,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    83,    84,    85,    -1,
      -1,    -1,    -1,    -1,   253,   254,    -1,    -1,    -1,    96,
      97,   260,    99,     3,     4,    -1,   265,   266,    -1,    -1,
      10,    11,    12,   272,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,
      60,    61,    62,    -1,    -1,    -1,    -1,    67,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    83,    84,    85,    -1,    -1,    -1,    13,
      14,    -1,    -1,    -1,    -1,    -1,    96,    97,    -1,    99,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,    -1,   216,
      -1,    -1,   264,   220,    -1,    -1,    -1,    -1,    -1,   226,
     227,   228,   274,   230,   231,   232,    -1,    -1,    -1,   236,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   253,   254,    -1,    -1,
      -1,    -1,    -1,   260,    -1,    -1,    -1,    -1,   265,    -1,
      -1,    -1,   269,    -1,    -1,   272,    -1,    -1,    -1,    -1,
      -1,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,    13,    14,    -1,   121,   122,   123,
     124,    -1,    -1,    -1,    -1,   129,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   138,   139,   216,    -1,   142,   143,
     220,   145,   146,    -1,   148,    -1,   226,   227,   228,    -1,
     230,   231,   232,    -1,    -1,    -1,   236,    -1,    -1,    -1,
      -1,    -1,   166,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   253,   254,    -1,    13,    14,    -1,    -1,
     260,    -1,    -1,    -1,    -1,   265,    -1,    -1,    -1,   193,
     194,   195,   272,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,    -1,
      -1,    -1,   121,   122,   123,   124,    -1,    -1,    -1,    -1,
     129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,
     139,    -1,    -1,   142,   143,    -1,   145,   146,    -1,   148,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   270,   166,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,    13,    14,    -1,   121,   122,   123,   124,    -1,    -1,
      -1,    -1,   129,    -1,   193,   194,   195,    -1,    -1,    -1,
      -1,   138,   139,    -1,    -1,   142,   143,    -1,   145,   146,
      -1,   148,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   166,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    13,    14,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   193,   194,   195,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   270,    -1,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,    -1,    -1,    -1,   121,
     122,   123,   124,    -1,    -1,    -1,    -1,   129,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   138,   139,    -1,    -1,
     142,   143,    -1,   145,   146,    -1,   148,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   270,   166,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,    13,    14,
      -1,   121,   122,   123,   124,    -1,    -1,    -1,    -1,   129,
      -1,   193,   194,   195,    -1,    -1,    -1,    -1,   138,   139,
      -1,    -1,   142,   143,    -1,   145,   146,    -1,   148,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   166,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      13,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   193,   194,   195,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   270,    -1,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,    -1,    -1,    -1,   121,   122,   123,   124,
      -1,    -1,    -1,    -1,   129,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   138,   139,    -1,    -1,   142,   143,    -1,
     145,   146,    -1,   148,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     270,   166,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,    13,    14,    -1,   121,   122,
     123,   124,    -1,    -1,    -1,    -1,   129,    -1,   193,   194,
     195,    -1,    -1,    -1,    -1,   138,   139,    -1,    -1,   142,
     143,    -1,   145,   146,    -1,   148,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   166,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    13,    14,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     193,   194,   195,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   270,    -1,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
      -1,    -1,    -1,   121,   122,   123,   124,    -1,    -1,    -1,
      -1,   129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     138,   139,    -1,    -1,   142,   143,    -1,   145,   146,    -1,
     148,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   270,   166,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,    13,    14,    -1,   121,   122,   123,   124,    -1,
      -1,    -1,    -1,   129,    -1,   193,   194,   195,    -1,    -1,
      -1,    -1,   138,   139,    -1,    -1,   142,   143,    -1,   145,
     146,    -1,   148,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     166,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    13,    14,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   193,   194,   195,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   270,    -1,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,    -1,    -1,    -1,
     121,   122,   123,   124,    -1,    -1,    -1,    -1,   129,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,   139,    -1,
      -1,   142,   143,    -1,   145,   146,    -1,   148,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   270,   166,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,    13,
      14,    -1,   121,   122,   123,   124,    -1,    -1,    -1,    -1,
     129,    -1,   193,   194,   195,    -1,    -1,    -1,    -1,   138,
     139,    -1,    -1,   142,   143,    -1,   145,   146,    -1,   148,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   166,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,    -1,    -1,    -1,    -1,
     264,    -1,    -1,    -1,   193,   194,   195,    -1,    -1,    -1,
     274,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   270,
      -1,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,    -1,    -1,    -1,   121,   122,   123,
     124,    -1,    -1,    -1,    -1,   129,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   138,   139,     0,     1,   142,   143,
       4,   145,   146,    -1,   148,    -1,    -1,    -1,    -1,    13,
      14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   270,   166,    -1,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,    -1,    47,    48,    49,   264,    -1,    -1,   193,
     194,   195,    -1,    -1,    -1,    -1,   274,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    68,    69,    70,    -1,    -1,    -1,
      -1,    75,    76,    -1,    -1,    -1,    -1,    81,    -1,    -1,
      -1,    -1,    86,    87,    88,    89,    90,    91,    92,    -1,
      94,    95,    -1,    97,    -1,    -1,    -1,    -1,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,    -1,    -1,   120,   121,   122,   123,
     124,    -1,    -1,   127,    -1,   129,   270,   131,   132,    -1,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,    -1,    -1,   150,   151,   152,    -1,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,    -1,    -1,    -1,   181,   182,   183,
      -1,    -1,    -1,   187,    -1,    -1,    -1,    -1,   192,   193,
     194,   195,    -1,    -1,   198,    -1,   200,    -1,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,    -1,     4,    -1,    -1,    -1,    -1,   222,   223,
     224,   225,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,
     234,    -1,   236,   237,    -1,    -1,    -1,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,    -1,    47,    48,    49,   264,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   274,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    68,    69,    70,
      -1,    -1,    -1,    -1,    75,    76,    -1,    -1,    -1,    -1,
      81,    -1,    -1,    -1,    -1,    86,    87,    88,    89,    90,
      91,    92,    -1,    94,    95,    -1,    97,    -1,    -1,    -1,
      -1,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,    -1,    -1,   120,
     121,   122,   123,   124,    -1,    -1,   127,    -1,   129,    -1,
     131,   132,    -1,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,    -1,    -1,   150,
     151,   152,    -1,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,    -1,    -1,    -1,
     181,   182,   183,    -1,    -1,    -1,   187,    -1,    -1,    -1,
      -1,   192,   193,   194,   195,     4,     5,   198,    -1,   200,
      -1,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,    -1,    -1,    -1,    -1,    -1,
      -1,   222,   223,   224,   225,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   234,    -1,   236,   237,    -1,    -1,    -1,
      -1,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      -1,    -1,    -1,    -1,    63,    64,    65,    66,    -1,     4,
       5,    -1,    71,    72,    73,    74,    -1,    -1,    -1,    -1,
      -1,    80,    -1,    82,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    98,
      -1,    -1,   101,    -1,    -1,    -1,   105,    -1,    -1,   108,
      -1,    -1,   111,    -1,   113,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    -1,   124,    -1,    -1,    63,    64,
      65,    66,     4,     5,    -1,    -1,    71,    72,    73,    74,
      -1,    -1,    -1,    -1,    -1,    80,   145,    82,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      13,    14,    -1,    98,    -1,    -1,   101,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    -1,    -1,    -1,
      -1,    63,    64,    65,    66,    -1,    -1,    -1,    -1,    71,
      72,    73,    74,    -1,    -1,    -1,    -1,    -1,    80,    -1,
      82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   217,   218,
     219,    -1,    -1,    -1,    -1,    -1,    98,    -1,    -1,   101,
     229,    -1,    -1,    -1,   233,    -1,   235,   236,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,    -1,    -1,    -1,   121,   122,
     123,   124,    13,    14,    -1,    -1,   129,    -1,    -1,    -1,
      -1,    -1,   217,   218,   219,   138,   139,    -1,    -1,   142,
     143,    -1,   145,   146,   229,   148,    -1,    -1,   233,   152,
     235,   236,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   166,    -1,    -1,    -1,   170,    -1,    -1,
      -1,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,    -1,
     193,   194,   195,   264,    -1,   217,   218,   219,    -1,    -1,
      -1,    -1,    -1,   274,    -1,    -1,    -1,   229,    -1,    -1,
      -1,   233,    -1,   235,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,    -1,    -1,    -1,
     121,   122,   123,   124,    -1,    -1,    -1,    -1,   129,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,   139,    -1,
      -1,   142,   143,    -1,   145,   146,    -1,   148,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   166,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,    -1,    -1,    -1,    -1,   264,    -1,
      -1,    -1,   193,   194,   195,    -1,    -1,    -1,   274,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,    -1,    -1,    -1,
      -1,   264,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   274,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
      -1,    -1,    -1,    -1,   264,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   274,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,    -1,    -1,    -1,    -1,   264,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   274,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,    -1,    -1,    -1,    -1,
     264,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     274,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,    -1,
      -1,    -1,    -1,   264,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   274,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,    -1,    -1,    -1,    -1,   264,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   274,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,    -1,    -1,    -1,    -1,   264,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   274,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,    -1,    -1,
      -1,    -1,   264,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   274,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,    -1,    -1,    -1,    -1,   264,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   274,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,    -1,    -1,    -1,    -1,   264,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   274,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,    -1,    -1,    -1,
      -1,   264,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   274,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
      -1,    -1,    -1,    -1,   264,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   274,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,    -1,    -1,    -1,    -1,   264,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   274,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,    -1,    -1,    -1,    -1,
     264,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     274,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,    -1,
      -1,    -1,    -1,   264,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   274,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,    -1,    -1,    -1,    -1,   264,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   274,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,    -1,    -1,    -1,    -1,   264,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   274,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,    -1,    -1,
      -1,    -1,   264,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   274,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,    -1,    -1,    -1,    -1,   264,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   274,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,    -1,    -1,    -1,    -1,   264,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   274,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,    -1,    -1,    -1,
      -1,   264,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   274,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
      -1,    -1,    -1,    -1,   264,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   274,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,    -1,    -1,    -1,    -1,   264,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   274,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,    -1,    -1,    -1,    -1,
     264,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     274,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,    -1,
      -1,    -1,    -1,   264,    -1,    -1,    -1,    -1,    -1,   270,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,    -1,    -1,
      -1,    -1,   264,    -1,    -1,    -1,    -1,    -1,   270,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,    -1,    -1,    -1,
      -1,   264,    -1,    -1,    -1,    -1,    -1,   270,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,    -1,    -1,    -1,    -1,
     264,    -1,    -1,    -1,    -1,    -1,   270,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,    -1,    -1,    -1,    -1,   264,
      -1,    -1,    -1,    -1,    -1,   270,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,    -1,    -1,    -1,    -1,   264,    -1,
      -1,    -1,    -1,    -1,   270,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,    -1,    -1,    -1,    -1,   264,    -1,    -1,
      -1,    -1,    -1,   270,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,    -1,    -1,    -1,    -1,   264,    -1,    -1,    -1,
      -1,    -1,   270,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,    -1,    -1,    -1,    -1,   264,    -1,    -1,    -1,    -1,
      -1,   270,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
      -1,    -1,    -1,    -1,   264,    -1,    -1,    -1,    -1,    -1,
     270,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,    -1,
      -1,    -1,    -1,   264,    -1,    -1,    -1,    -1,    -1,   270,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,    -1,    -1,
      -1,    -1,   264,    -1,    -1,    -1,    -1,    -1,   270,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,    -1,    -1,    -1,
      -1,   264,    -1,    -1,    -1,    -1,    -1,   270,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,    -1,    -1,    -1,    -1,
     264,    -1,    -1,    -1,    -1,    -1,   270,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,    -1,    -1,    -1,    -1,   264,
      -1,    -1,    -1,    -1,    -1,   270,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,    -1,    -1,    -1,    -1,   264,    -1,
      -1,    -1,    -1,    -1,   270,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,    -1,    -1,    -1,    -1,   264,    -1,    -1,
      -1,    -1,    -1,   270,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,    -1,    -1,    -1,    -1,   264,    -1,    -1,    -1,
      -1,    -1,   270,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,    -1,    -1,    -1,    -1,   264,    -1,    -1,    -1,    -1,
      -1,   270,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
      -1,    -1,    -1,    -1,   264,    -1,    -1,    -1,    -1,    -1,
     270,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,    -1,
      -1,    -1,    -1,   264,    -1,    -1,    -1,    -1,    -1,   270,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,    -1,    -1,
      -1,    -1,   264,    -1,    -1,    -1,    -1,    -1,   270,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,    -1,    -1,    -1,
      -1,   264,    -1,    -1,    -1,    -1,    -1,   270,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,    -1,    -1,    -1,    -1,
     264,    -1,    -1,    -1,    -1,    -1,   270,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,    -1,    -1,    -1,    -1,   264,
      -1,    -1,    -1,    -1,    -1,   270,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,    -1,    -1,    -1,    -1,   264,    -1,
      -1,    -1,    -1,    -1,   270,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,    -1,    -1,    -1,    -1,   264,    -1,    -1,
      -1,    -1,    -1,   270,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,    -1,    -1,    -1,    -1,   264,    -1,    -1,    -1,
      -1,    -1,   270,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,    -1,    -1,    -1,    -1,   264,    -1,    -1,    -1,    -1,
      -1,   270,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
      -1,    -1,    -1,    -1,   264,    -1,    -1,    -1,    -1,    -1,
     270,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,    -1,
      -1,    -1,    -1,   264,    -1,    -1,    -1,    -1,    -1,   270,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,    -1,    -1,
      -1,    -1,   264,    -1,    -1,    -1,    -1,    -1,   270,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,    -1,    -1,    -1,
      -1,   264,    -1,    -1,    -1,    -1,    -1,   270,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,    -1,    -1,    -1,    -1,
     264,    -1,    -1,    -1,    -1,    -1,   270,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,    -1,    -1,    -1,    -1,   264,
      -1,    -1,    -1,    -1,    -1,   270,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,    -1,    -1,    -1,    -1,   264,    -1,
      -1,    -1,    -1,    -1,   270,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,    -1,    -1,    -1,    -1,   264,    -1,    -1,
      -1,    -1,    -1,   270,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,    -1,    -1,    -1,    -1,   264,    -1,    -1,    -1,
      -1,    -1,   270,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,    -1,    -1,    -1,    -1,   264,    -1,    -1,    -1,    -1,
      -1,   270,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
      -1,    -1,    -1,    -1,   264,    -1,    -1,    -1,    -1,    -1,
     270,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,    -1,
      -1,    -1,    -1,   264,    -1,    -1,    -1,    -1,    -1,   270,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,    -1,    -1,
      -1,    -1,   264,    -1,    -1,    -1,    -1,   269,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,    -1,    -1,    -1,    -1,
     264,    -1,    -1,    -1,    -1,   269,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,    -1,    -1,    -1,    -1,   264,    -1,
      -1,    -1,    -1,   269,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,    -1,    -1,    -1,    -1,   264,    -1,   266,    -1,
     268,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,    -1,
      -1,    -1,    -1,   264,    -1,    -1,    -1,   268,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,    -1,    -1,    -1,    -1,
     264,    -1,    -1,    -1,   268,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,    -1,    -1,    -1,    -1,   264,    -1,    -1,
      -1,   268,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
      -1,    -1,    -1,    -1,   264,    -1,    -1,    -1,   268,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,    -1,    -1,    -1,
      -1,   264,    -1,    -1,    -1,   268,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,    -1,    -1,    -1,    -1,   264,    -1,
      -1,    -1,   268,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,    -1,    -1,    -1,    -1,   264,    -1,    -1,    -1,   268,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,    -1,    -1,
      -1,    -1,   264,    -1,    -1,    -1,   268,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,    -1,    -1,    -1,    -1,   264,
      -1,    -1,    -1,   268,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,    -1,    -1,    -1,    -1,   264,    -1,    -1,    -1,
     268,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,    -1,
      -1,    -1,    -1,   264,    -1,    -1,    -1,   268,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,    -1,    -1,    -1,    -1,
     264,    -1,    -1,    -1,   268,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,    -1,    -1,    -1,    -1,   264,    -1,    -1,
      -1,   268,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
      -1,    -1,    -1,    -1,   264,    -1,    -1,    -1,   268,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,    -1,    -1,    -1,
      -1,   264,    -1,    -1,    -1,   268,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,    -1,    -1,    -1,    -1,   264,    -1,
     266,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,    -1,
      -1,    -1,    -1,   264,    -1,   266,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,    -1,    -1,    -1,    -1,   264,    -1,
     266,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,    -1,
      -1,    -1,    -1,   264,    -1,   266,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,    -1,    -1,    -1,    -1,   264,    -1,
     266,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,    -1,
      -1,    -1,    -1,   264,    -1,   266,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,    -1,    -1,    -1,    -1,   264,    -1,
     266,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,    -1,
      -1,    -1,    -1,   264,    -1,   266,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,    -1,    -1,    -1,    -1,   264,    -1,
     266,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,    -1,
      -1,    -1,    -1,   264,    -1,   266,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,    -1,    -1,    -1,    -1,   264,    -1,
     266,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,    -1,
      -1,    -1,    -1,   264,    -1,   266,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,    -1,    -1,    -1,    -1,   264,    -1,
     266,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,    -1,
      -1,    -1,    -1,   264,    -1,   266,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,    -1,    -1,    -1,    -1,   264,    -1,
     266,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,    -1,
      -1,    -1,    -1,   264,    -1,   266,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,    -1,    -1,    -1,    -1,   264,    -1,
     266,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,    -1,
      -1,    -1,    -1,   264,    -1,   266,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,    -1,    -1,    -1,    -1,   264,    -1,
     266,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,    -1,
      -1,    -1,    -1,   264,    -1,   266,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,    -1,    -1,    -1,    -1,   264,    -1,
     266,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,    -1,
      -1,    -1,    -1,   264,    -1,   266,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,    -1,    -1,    -1,    -1,   264,    -1,
     266,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,    -1,
      -1,    -1,    -1,   264,    -1,   266,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,    -1,    -1,    -1,    -1,   264,    -1,
     266,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,    -1,
      -1,    -1,    -1,   264,    -1,   266,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,    -1,    -1,    -1,    -1,   264,    -1,
     266,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,    -1,
      -1,    -1,    -1,   264,    -1,   266,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,    -1,    -1,    -1,    -1,   264,    -1,
     266,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,    -1,
      -1,    -1,    -1,   264,    -1,   266,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,    -1,    -1,    -1,    -1,   264,    -1,
     266,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,    -1,
      -1,    -1,    -1,   264,    -1,   266,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,    -1,    -1,    -1,    -1,   264,    -1,
     266,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,    -1,
      -1,    -1,    -1,   264,    -1,   266,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,    -1,    -1,    -1,    -1,   264,    -1,
     266,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,    -1,
      -1,    -1,    -1,   264,    -1,   266,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,    -1,    -1,    -1,    -1,   264,    -1,
     266,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,    -1,
      -1,    -1,    -1,   264,    -1,   266,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,    -1,    -1,    -1,    -1,   264,    -1,
     266,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,    -1,
      -1,    -1,    -1,   264,    -1,   266,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,    -1,    -1,    -1,    -1,   264,    -1,
     266,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,    -1,
      -1,    -1,    -1,   264,    -1,   266,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,    -1,    -1,    -1,    -1,   264,    -1,
     266,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,    -1,
      -1,    -1,    -1,   264,    -1,   266,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,    -1,    -1,    -1,    -1,   264,    -1,
     266,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,    -1,
      -1,    -1,    -1,   264,    -1,   266,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,    -1,    -1,    -1,    -1,   264,    -1,
     266,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,    -1,
      -1,    -1,    -1,   264,    -1,   266,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,    -1,    -1,    -1,    -1,   264,    -1,
     266,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,    -1,
      -1,    -1,    -1,   264,    -1,   266,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,    -1,    -1,    -1,    -1,   264,    -1,
     266,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,    -1,
      -1,    -1,    -1,   264,    -1,   266,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,    -1,    -1,    -1,    -1,   264,    -1,
     266,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,    -1,
      -1,    -1,    -1,   264,    -1,   266,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,    -1,    -1,    -1,    -1,   264,    -1,
     266,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,    -1,
      -1,    -1,    -1,   264,    -1,   266,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,    -1,    -1,    -1,    -1,   264,    -1,
     266,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,    -1,
      -1,    -1,    -1,   264,    -1,   266,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,    -1,    -1,    -1,    -1,   264,    -1,
     266,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,    -1,
      -1,    -1,    -1,   264,    -1,   266,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,    -1,    -1,    -1,    -1,   264
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,   276,   277,     6,     0,     4,    13,    14,    47,
      48,    49,    68,    69,    70,    75,    76,    81,    86,    87,
      88,    89,    90,    91,    92,    94,    95,    97,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   120,   121,   122,   123,   124,   127,
     129,   131,   132,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   150,   151,   152,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   181,   182,   183,   187,   192,   193,
     194,   195,   198,   200,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   222,   223,
     224,   225,   234,   236,   237,   278,   280,   281,   302,   321,
     323,   327,   330,   331,   332,   333,   334,   335,   336,   337,
     344,   346,   347,   353,   354,   355,   356,   362,   388,   389,
     269,   273,    14,   111,   265,   265,   265,     6,   269,     6,
       6,     6,     6,   265,     6,   269,     6,   269,   269,     6,
       6,     6,     6,   267,   267,     4,   364,   389,   265,   267,
     299,   105,   108,   111,   113,   323,   299,   265,   265,   265,
       4,   265,   265,   265,     4,   265,   265,   265,   265,   265,
     265,   265,   265,   265,   265,   265,   269,   128,   111,     6,
       6,   269,   105,   108,   111,   124,   326,   113,   265,     3,
      10,    11,    12,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    59,    60,    61,    62,    67,
      68,    77,    78,    79,    83,    84,    85,    96,    99,   105,
     108,   111,   113,   124,   125,   126,   129,   138,   143,   145,
     148,   198,   216,   220,   221,   226,   227,   228,   230,   231,
     232,   253,   254,   260,   265,   269,   272,   323,   324,   327,
     337,   344,   346,   357,   358,   362,   364,   370,   373,   389,
     265,   269,   269,   111,   111,   138,   108,   111,   113,   323,
     108,   111,   112,   113,   124,   193,   324,   108,   111,   265,
     108,   170,   198,   214,   215,   269,   253,   254,   265,   269,
     367,   368,   367,   269,   269,   367,   269,   269,   265,   111,
     113,   111,   108,     4,    97,   209,   269,   389,     4,     6,
     105,     6,   108,   111,   108,   111,   124,   325,     5,   265,
     269,   370,   372,   111,     4,     4,     4,   372,     4,   111,
     265,   111,   265,   265,     4,   269,   376,   389,     4,   265,
     265,   265,     6,    33,   254,   357,   389,     6,   267,     5,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    63,
      64,    65,    66,    71,    72,    73,    74,    80,    82,    98,
     101,   217,   218,   219,   229,   233,   235,   380,   389,   265,
       4,   380,     5,   269,     5,   269,   323,   357,   267,     6,
     269,   265,   269,     6,   265,   269,     6,   273,     7,   145,
     209,   238,   239,   240,   241,   262,   263,   265,   267,   271,
     297,   298,   299,   323,   357,   379,   380,   389,     4,   327,
     328,   329,   269,     6,   357,   379,   380,   389,   379,   379,
     357,   379,   386,   387,   389,   357,   329,   357,   304,   308,
     265,   366,     9,   380,   265,   380,   357,   357,   357,   265,
     357,   357,   357,   265,   357,   357,   357,   357,   357,   357,
     357,   379,   357,   357,   357,   357,   372,   265,   254,   357,
     373,   374,   269,   372,   370,   379,   299,   299,   299,   299,
     299,   299,   299,   299,   299,   299,   299,   299,   299,   299,
     299,   299,   299,   299,   299,   299,   299,   299,   299,   299,
     299,   299,   265,   267,   299,   299,   299,   299,   299,   299,
     265,   299,   299,   265,   323,   324,   324,   324,   299,   299,
       5,   269,   269,   111,   108,   111,    68,   105,   138,   323,
     323,   324,   265,   299,   299,   265,   265,   265,   357,   269,
     357,   373,   357,   357,   270,   374,   364,   389,   201,     5,
     269,     8,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     264,     9,   265,   267,   271,   298,   299,   357,   374,   374,
     265,   265,   265,   370,   372,   372,   372,   322,   265,   269,
     265,   265,   370,   269,   269,   357,     4,   370,   269,   376,
     269,   269,   367,   367,   367,   357,   357,   253,   254,   269,
     269,   367,   253,   254,   265,   329,   367,   269,   374,   374,
     357,   372,   372,   372,   265,   269,     4,   267,   269,     6,
     267,   329,     6,     6,   269,   269,   269,   269,   372,   357,
       8,     7,   269,   267,   267,   267,     6,     6,   265,   357,
     265,   357,   357,   271,   357,   269,   201,   357,   357,   357,
     299,   357,     6,   255,     9,   265,   267,   271,   357,   299,
     299,   299,   265,   265,   265,   299,   299,   299,   299,   299,
     299,   299,   299,   299,   299,   265,   265,   299,   265,   267,
       6,     6,   269,     6,     8,   329,     6,     8,   329,   265,
     269,   379,   374,   357,   329,   370,   370,   269,   380,   323,
       7,   357,   357,     4,    26,    37,    38,   114,   115,   198,
     199,   301,   370,     6,   266,   268,   269,   300,   269,     6,
     269,     6,     9,   265,   267,   271,   389,   270,   138,   143,
     145,   146,   148,   321,   323,   357,     6,   266,   274,     9,
     265,   267,   271,   266,   274,   266,   274,   274,   266,   274,
       9,   265,   271,   274,   270,   274,   268,   274,   303,   268,
     303,   100,   365,   363,   389,   274,   357,   274,   266,   266,
     266,   357,   266,   266,   266,   357,   266,   266,   266,   266,
     266,   266,   266,   266,   274,   266,   266,   266,   270,     7,
     357,   255,   270,   274,   357,     6,     6,   266,   357,   357,
     357,   357,   357,   357,   357,   357,   357,   357,   357,   357,
     357,   357,   357,   357,   357,   357,   373,   357,   357,   357,
     357,   357,   357,   357,   357,   357,   373,   373,   389,   269,
     357,   357,   379,   357,   379,   370,   379,   379,   386,   269,
     269,   269,   269,   357,   300,   389,     8,   357,   357,   269,
     269,   269,   325,   269,   269,   372,   370,   269,   379,   379,
     373,   364,   380,   364,   374,   266,   270,   271,   299,    68,
       8,   357,   357,   357,   357,   357,   357,   357,   357,   357,
     357,   357,   357,   357,   357,   269,   357,   373,   357,   357,
     357,   357,   357,   389,   357,   357,   301,   269,   300,   266,
     270,   270,   357,   357,   357,     7,     7,   350,   350,   265,
     357,   357,   357,   357,     6,   174,   374,   374,   269,   266,
       6,   329,   269,   329,   329,   274,   274,   274,   367,   367,
     328,   328,   274,   357,   270,   341,   274,   329,   270,   270,
     266,     7,   351,     6,     7,   357,   357,     6,   357,   329,
     357,   270,   374,   374,   374,   357,     6,   266,   270,   357,
     374,   357,   357,   357,   357,   266,   357,   266,   266,   198,
     274,   329,   269,     8,   266,   266,   357,   357,   389,   301,
     268,   386,   379,   386,   379,   379,   379,   379,   379,   379,
     357,   379,   379,   379,   379,   272,   382,   389,   380,   379,
     379,   379,   364,   389,   374,   270,   270,   270,   270,   357,
     329,   268,   270,   266,   152,   170,   345,   266,   270,   274,
     357,     6,   269,   370,   266,   268,   271,     7,     7,   297,
     298,     6,   374,     7,   241,   297,   357,   282,   389,   357,
     357,   301,   267,   265,   138,   323,   324,   323,   269,   270,
       6,   248,   249,   279,   374,   389,   357,   357,   301,     6,
     374,     6,   374,   357,     6,   379,   387,   389,   266,   301,
     357,   357,     6,   389,     6,   379,   357,   266,   267,   357,
     274,   380,     7,     7,     7,   266,     7,     7,     7,   266,
       7,     7,     7,     7,     7,     7,     7,   357,     7,     7,
       7,   357,   266,     6,   269,   357,   373,   270,     6,   300,
     300,   300,   300,   300,   300,   300,   300,   300,   300,   300,
     300,   274,   300,   300,   300,   300,   300,   300,   300,   300,
     300,   274,   274,   274,   274,   274,   266,   268,   268,   374,
     274,   274,   300,   274,   300,   274,   274,   274,   266,   374,
     357,   357,   357,   359,   300,   270,   270,   270,   357,   357,
     357,   269,   357,   375,   380,   357,   274,   274,   300,   300,
     266,   271,   266,   271,   274,   299,   360,   270,     7,   301,
     300,   370,   270,     8,     8,   374,   271,   266,   268,   265,
     267,   298,   299,   374,     7,   269,   269,   266,   266,   266,
     357,   370,     4,   349,     6,   317,   357,   380,   266,   270,
     266,   266,   357,   270,   270,   374,   271,   270,   329,   270,
     270,   367,   357,   357,   270,   270,   357,   367,   149,   149,
     167,   178,   179,   180,   184,   185,   342,   343,   367,   270,
     338,   269,   269,     7,   357,     6,   357,   266,   270,   268,
     270,   268,   270,   270,   270,   270,     6,   270,   268,   268,
     274,   266,     7,   266,     7,     7,   271,   357,   270,   357,
     357,   271,   265,   267,     7,   271,   300,   274,   300,   300,
     266,   266,   274,   300,   300,   274,   274,   300,   300,   300,
     300,   357,   300,     9,   381,   274,   266,   274,   300,   271,
     274,   361,   268,   270,   266,   270,   273,   201,     7,   170,
       6,   357,   270,   269,     6,   370,   270,   357,     6,     7,
     297,   298,   271,   297,   298,   301,   269,   377,   389,   380,
     357,     6,   270,    50,    50,   370,   270,     4,   188,   189,
     190,   191,   270,   285,   289,   292,   294,   295,   336,   271,
     266,   268,   265,   357,   357,   265,   269,   265,   269,     8,
     374,   379,   266,   271,   266,   268,   265,   266,   266,   274,
     271,   265,   270,   274,     7,   299,     4,    26,    37,    38,
     311,   312,   313,   300,   357,   300,   367,   370,   370,     7,
     370,   370,   370,     7,   370,   370,   370,   370,   370,   370,
     370,   266,   274,   370,   370,   370,     6,     7,   328,   357,
     357,   357,   357,   357,   357,   270,   357,   357,   357,   370,
     379,   379,   270,   270,   270,   270,   274,   310,   270,   270,
     270,   357,   270,   270,   274,   270,   357,   357,   301,   301,
     357,   357,   266,   370,   299,   357,   357,   270,   301,   298,
     271,   298,   357,   357,   300,   270,   370,   374,   374,     7,
       7,     7,   149,   348,     6,   266,   274,     7,     7,     7,
       6,     7,     7,   270,     4,   301,   270,   274,   274,   274,
     270,   270,   123,     4,     6,   357,   269,     6,   265,     6,
     186,     6,   186,   270,   343,   274,   342,   328,   328,   370,
       6,   269,   105,     6,     6,     6,   111,     7,     7,     6,
       6,   357,     7,   370,     7,   370,   370,     4,   274,     8,
       8,   266,   301,   301,   301,   374,   379,   357,   379,   272,
     274,   314,   379,   379,   301,   379,   266,   274,     6,   269,
     323,   269,     6,   357,     6,   269,   370,   270,   270,   357,
       6,   198,   199,   301,   357,     6,     7,   376,   378,     6,
     267,     6,     6,   300,   299,   299,     6,   286,   265,   265,
     269,   296,     6,   301,   271,   379,   357,   268,   266,   357,
       8,   374,   375,   357,   374,   270,   270,     6,     6,   279,
     301,   271,   357,     6,     6,   357,   301,   266,     6,   357,
     269,   357,   380,   300,    50,   269,   370,   380,   383,   357,
     357,   357,   268,   274,     6,   266,     6,     6,   142,   319,
     319,   370,     6,     6,     6,   370,   149,   201,   318,     6,
       6,     6,     6,     6,     6,   357,     6,     6,     6,     5,
     270,   300,   300,   300,   300,   300,   300,   300,   274,   274,
     274,   266,   300,   300,   312,   300,   129,   129,   129,   270,
     201,   380,   266,   300,   266,   299,   360,   300,     6,   300,
     265,   267,   299,   301,   266,   268,   300,     6,   270,   270,
     370,   370,   370,     4,     6,   297,   357,   370,   370,   370,
     269,   269,     7,     6,     7,   357,   357,   357,   269,   269,
     269,   267,     6,   357,   370,   357,     6,     6,   357,   367,
     270,   270,   270,     6,   374,   269,   269,   357,   357,   268,
     370,     6,   370,     6,   197,   357,   357,   357,   265,   267,
       6,     6,     7,   300,   274,   274,   300,   274,   357,     4,
     213,   315,   316,   300,   266,   300,   361,   380,   357,   269,
     329,     6,   329,   274,     6,     6,   271,     7,     7,   297,
     298,     6,   376,   270,   274,   357,   297,   269,   300,   384,
     385,   386,   384,   265,   357,   357,   369,   370,   269,   265,
       4,     6,   266,     6,   266,   270,   270,   270,   266,   270,
       6,     6,   379,   265,     4,   266,   274,   265,   270,   274,
     370,   380,     7,   299,   309,   357,   373,   313,     6,   367,
       6,     6,     6,   149,   320,   105,   124,   109,     6,   266,
     274,     5,     6,   357,   357,   357,   269,   269,   269,   111,
     357,   266,   360,   357,   357,   300,   298,   269,   269,     6,
     318,     6,   357,   370,   149,   149,     4,     6,   374,   374,
     357,   357,   380,   270,   266,   270,   274,   328,   328,   357,
     357,   270,   274,   266,   270,   274,   270,   374,   357,     6,
       6,     6,     6,     6,   370,   270,   274,     8,   270,   266,
     254,   269,   357,   371,   380,   379,   357,   379,   357,   380,
     383,   385,   380,   274,   266,   274,   270,   357,   345,   345,
     370,   301,   377,   380,   357,     6,     6,   376,   268,   370,
     386,     6,   300,   300,   283,   357,   274,   274,   270,   274,
     284,   357,   357,     6,     6,     6,     6,     6,   357,   357,
     266,     6,   357,   305,   307,   269,   385,   270,   274,     7,
       7,   153,     6,   269,   269,   269,   357,     5,   300,   300,
     274,   357,   357,   357,   269,   300,   266,   266,   268,   374,
     374,     6,     6,   357,   357,   269,   270,   270,   269,     6,
       6,   269,   357,   270,   270,   270,   268,     6,   370,     7,
     269,   357,     6,   270,   270,   196,   357,   357,   269,   270,
     374,     6,     6,     6,   266,   300,   300,   316,   380,   270,
     270,   270,   270,     7,     6,     6,     6,   271,     6,   270,
       6,     6,   266,   274,   357,   357,   269,   370,   270,   274,
     266,   266,   274,   270,   310,   314,   370,   300,   357,   380,
     389,   374,   374,   357,   266,     6,   357,   274,   270,   274,
     357,   360,   270,   270,     6,     6,   369,   154,   155,   159,
     352,   154,   155,   352,   374,   328,   270,   274,     6,   270,
     370,   329,   270,     6,   357,   270,   270,   374,   270,   266,
       6,   269,     6,   376,   199,   287,   357,   274,   274,   369,
       6,   357,   357,     6,   270,   270,   306,     7,   265,   270,
     270,   270,   274,   357,   357,   270,   266,   269,   270,   269,
     367,   370,     6,   269,   367,     6,   270,   270,   357,     6,
     149,   270,   339,   269,     6,   270,     6,   329,     6,   269,
     357,   357,   270,   274,   310,   380,   266,   357,   270,   270,
     374,     6,   367,     6,   367,     6,     6,   270,   357,   342,
     329,   345,   284,   266,   274,     6,   269,   357,   270,   274,
     270,   274,   274,     6,   270,   270,   340,   270,   270,   290,
     357,   369,   270,   357,   367,   367,   342,     6,     6,   269,
     266,   270,     6,   300,   274,   274,   270,   288,   379,   293,
     269,   357,   357,   270,   274,   269,   369,   270,   270,     6,
     379,   291,   379,   270,     6,     6,   270,   274,     6,     6,
     379
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
#line 284 "Gmsh.y"
    { yyerrok; return 1; ;}
    break;

  case 6:
#line 295 "Gmsh.y"
    { return 1; ;}
    break;

  case 7:
#line 296 "Gmsh.y"
    { return 1; ;}
    break;

  case 8:
#line 297 "Gmsh.y"
    { return 1; ;}
    break;

  case 9:
#line 299 "Gmsh.y"
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
#line 332 "Gmsh.y"
    { return 1; ;}
    break;

  case 11:
#line 333 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 12:
#line 334 "Gmsh.y"
    { return 1; ;}
    break;

  case 13:
#line 335 "Gmsh.y"
    { return 1; ;}
    break;

  case 14:
#line 336 "Gmsh.y"
    { return 1; ;}
    break;

  case 15:
#line 337 "Gmsh.y"
    { return 1; ;}
    break;

  case 16:
#line 338 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 17:
#line 339 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 18:
#line 340 "Gmsh.y"
    { return 1; ;}
    break;

  case 19:
#line 341 "Gmsh.y"
    { return 1; ;}
    break;

  case 20:
#line 342 "Gmsh.y"
    { return 1; ;}
    break;

  case 21:
#line 343 "Gmsh.y"
    { return 1; ;}
    break;

  case 22:
#line 344 "Gmsh.y"
    { return 1; ;}
    break;

  case 23:
#line 345 "Gmsh.y"
    { return 1; ;}
    break;

  case 24:
#line 346 "Gmsh.y"
    { return 1; ;}
    break;

  case 25:
#line 351 "Gmsh.y"
    {
      (yyval.c) = (char*)"w";
    ;}
    break;

  case 26:
#line 355 "Gmsh.y"
    {
      (yyval.c) = (char*)"a";
    ;}
    break;

  case 27:
#line 362 "Gmsh.y"
    {
      Msg::Direct((yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 28:
#line 367 "Gmsh.y"
    {
      Msg::Warning((yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 29:
#line 372 "Gmsh.y"
    {
      Msg::Error((yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 30:
#line 377 "Gmsh.y"
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
#line 391 "Gmsh.y"
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

  case 32:
#line 404 "Gmsh.y"
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

  case 33:
#line 417 "Gmsh.y"
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

  case 34:
#line 430 "Gmsh.y"
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
#line 458 "Gmsh.y"
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
#line 472 "Gmsh.y"
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
#line 485 "Gmsh.y"
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
#line 498 "Gmsh.y"
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
#line 516 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData = new PViewDataList();
#endif
    ;}
    break;

  case 46:
#line 531 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(1) - (1)].d)); ;}
    break;

  case 47:
#line 533 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(3) - (3)].d)); ;}
    break;

  case 48:
#line 538 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(1) - (1)].d)); ;}
    break;

  case 49:
#line 540 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(3) - (3)].d)); ;}
    break;

  case 50:
#line 545 "Gmsh.y"
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
#line 564 "Gmsh.y"
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
#line 578 "Gmsh.y"
    {
      ViewStrings.push_back((yyvsp[(1) - (1)].c));
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 54:
#line 583 "Gmsh.y"
    {
      ViewStrings.push_back((yyvsp[(3) - (3)].c));
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 55:
#line 591 "Gmsh.y"
    {
      ViewStrings.clear();
    ;}
    break;

  case 56:
#line 595 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->addString2D((yyvsp[(3) - (13)].d), (yyvsp[(5) - (13)].d), (yyvsp[(7) - (13)].d), ViewStrings);
#endif
    ;}
    break;

  case 57:
#line 604 "Gmsh.y"
    {
      ViewStrings.push_back((yyvsp[(1) - (1)].c));
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 58:
#line 609 "Gmsh.y"
    {
      ViewStrings.push_back((yyvsp[(3) - (3)].c));
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 59:
#line 617 "Gmsh.y"
    {
      ViewStrings.clear();
    ;}
    break;

  case 60:
#line 621 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->addString3D((yyvsp[(3) - (15)].d), (yyvsp[(5) - (15)].d), (yyvsp[(7) - (15)].d), (yyvsp[(9) - (15)].d), ViewStrings);
#endif
    ;}
    break;

  case 61:
#line 631 "Gmsh.y"
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
#line 650 "Gmsh.y"
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
#line 669 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewTime.clear();
      ViewValueList = &ViewTime;
#endif
    ;}
    break;

  case 64:
#line 676 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(auto t : ViewTime) ViewData->addTime(t);
#endif
    ;}
    break;

  case 65:
#line 686 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 66:
#line 687 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 67:
#line 688 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 68:
#line 689 "Gmsh.y"
    { (yyval.i) = 3; ;}
    break;

  case 69:
#line 690 "Gmsh.y"
    { (yyval.i) = 4; ;}
    break;

  case 70:
#line 694 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 71:
#line 695 "Gmsh.y"
    { (yyval.i) = -1; ;}
    break;

  case 72:
#line 701 "Gmsh.y"
    { (yyval.c) = (char*)"("; ;}
    break;

  case 73:
#line 701 "Gmsh.y"
    { (yyval.c) = (char*)"["; ;}
    break;

  case 74:
#line 703 "Gmsh.y"
    { (yyval.c) = (char*)")"; ;}
    break;

  case 75:
#line 703 "Gmsh.y"
    { (yyval.c) = (char*)"]"; ;}
    break;

  case 76:
#line 708 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 77:
#line 709 "Gmsh.y"
    { (yyval.c) = (char *)Malloc(4 * sizeof(char)); strcpy((yyval.c), "Min"); ;}
    break;

  case 78:
#line 710 "Gmsh.y"
    { (yyval.c) = (char *)Malloc(4 * sizeof(char)); strcpy((yyval.c), "Max"); ;}
    break;

  case 79:
#line 711 "Gmsh.y"
    { (yyval.c) = (char *)Malloc(5 * sizeof(char)); strcpy((yyval.c), "Step"); ;}
    break;

  case 80:
#line 712 "Gmsh.y"
    { (yyval.c) = (char *)Malloc(4 * sizeof(char)); strcpy((yyval.c), "Box"); ;}
    break;

  case 81:
#line 713 "Gmsh.y"
    { (yyval.c) = (char *)Malloc(9 * sizeof(char)); strcpy((yyval.c), "Cylinder"); ;}
    break;

  case 85:
#line 723 "Gmsh.y"
    {
      Msg::SetOnelabNumber((yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].d));
      Free((yyvsp[(3) - (7)].c));
    ;}
    break;

  case 86:
#line 728 "Gmsh.y"
    {
      Msg::SetOnelabString((yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].c));
      Free((yyvsp[(3) - (7)].c));
      Free((yyvsp[(5) - (7)].c));
    ;}
    break;

  case 87:
#line 734 "Gmsh.y"
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
#line 795 "Gmsh.y"
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
#line 810 "Gmsh.y"
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
#line 838 "Gmsh.y"
    {
      assignVariables((yyvsp[(1) - (9)].c), (yyvsp[(4) - (9)].l), (yyvsp[(7) - (9)].i), (yyvsp[(8) - (9)].l));
      Free((yyvsp[(1) - (9)].c));
      List_Delete((yyvsp[(4) - (9)].l));
      List_Delete((yyvsp[(8) - (9)].l));
    ;}
    break;

  case 91:
#line 848 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    ;}
    break;

  case 92:
#line 853 "Gmsh.y"
    {
      incrementVariable((yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].i));
      Free((yyvsp[(1) - (6)].c));
    ;}
    break;

  case 93:
#line 861 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    ;}
    break;

  case 94:
#line 866 "Gmsh.y"
    {
      incrementVariable((yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].i));
      Free((yyvsp[(1) - (6)].c));
    ;}
    break;

  case 95:
#line 874 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[(1) - (4)].c)] = std::vector<std::string>(1, (yyvsp[(3) - (4)].c));
      Free((yyvsp[(1) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 96:
#line 883 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[(1) - (8)].c)] = std::vector<std::string>();
      Free((yyvsp[(1) - (8)].c));
    ;}
    break;

  case 97:
#line 888 "Gmsh.y"
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
#line 900 "Gmsh.y"
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
#line 917 "Gmsh.y"
    {
      std::string tmp((yyvsp[(5) - (6)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (6)].c), 0, (yyvsp[(3) - (6)].c), tmp);
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 100:
#line 923 "Gmsh.y"
    {
      std::string tmp((yyvsp[(8) - (9)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (9)].c), (int)(yyvsp[(3) - (9)].d), (yyvsp[(6) - (9)].c), tmp);
      Free((yyvsp[(1) - (9)].c)); Free((yyvsp[(6) - (9)].c)); Free((yyvsp[(8) - (9)].c));
    ;}
    break;

  case 101:
#line 932 "Gmsh.y"
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
#line 950 "Gmsh.y"
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
#line 968 "Gmsh.y"
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
#line 977 "Gmsh.y"
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
#line 989 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (8)].c), 0, (yyvsp[(5) - (8)].c), (yyvsp[(7) - (8)].u));
      Free((yyvsp[(1) - (8)].c)); Free((yyvsp[(5) - (8)].c));
    ;}
    break;

  case 106:
#line 994 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (11)].c), (int)(yyvsp[(3) - (11)].d), (yyvsp[(8) - (11)].c), (yyvsp[(10) - (11)].u));
      Free((yyvsp[(1) - (11)].c)); Free((yyvsp[(8) - (11)].c));
    ;}
    break;

  case 107:
#line 1002 "Gmsh.y"
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
#line 1022 "Gmsh.y"
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
#line 1045 "Gmsh.y"
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
#line 1065 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      if(!GModel::current()->getFields()->newField((int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c)))
	yymsg(0, "Cannot create field %i of type '%s'", (int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c));
#endif
      Free((yyvsp[(6) - (7)].c));
    ;}
    break;

  case 111:
#line 1073 "Gmsh.y"
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
#line 1090 "Gmsh.y"
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
#line 1108 "Gmsh.y"
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
#line 1146 "Gmsh.y"
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
#line 1167 "Gmsh.y"
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
#line 1179 "Gmsh.y"
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
#line 1197 "Gmsh.y"
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
#line 1206 "Gmsh.y"
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
#line 1215 "Gmsh.y"
    { init_options(); ;}
    break;

  case 123:
#line 1217 "Gmsh.y"
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
#line 1235 "Gmsh.y"
    { init_options(); ;}
    break;

  case 125:
#line 1237 "Gmsh.y"
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
#line 1253 "Gmsh.y"
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
#line 1262 "Gmsh.y"
    { init_options(); ;}
    break;

  case 128:
#line 1264 "Gmsh.y"
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
#line 1278 "Gmsh.y"
    {
      std::string name((yyvsp[(3) - (3)].c));
      Msg::UndefineOnelabParameter(name);
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 131:
#line 1286 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(doubleXstring));
      doubleXstring v = {(yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].c)};
      List_Add((yyval.l), &v);
    ;}
    break;

  case 132:
#line 1292 "Gmsh.y"
    {
      doubleXstring v = {(yyvsp[(3) - (5)].d), (yyvsp[(5) - (5)].c)};
      List_Add((yyval.l), &v);
    ;}
    break;

  case 133:
#line 1297 "Gmsh.y"
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
#line 1340 "Gmsh.y"
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
#line 1352 "Gmsh.y"
    {
      floatOptions["Min"].push_back((yyvsp[(2) - (2)].d));
    ;}
    break;

  case 142:
#line 1356 "Gmsh.y"
    {
      floatOptions["Max"].push_back((yyvsp[(2) - (2)].d));
    ;}
    break;

  case 143:
#line 1360 "Gmsh.y"
    {
      floatOptions["Step"].push_back((yyvsp[(2) - (2)].d));
    ;}
    break;

  case 144:
#line 1364 "Gmsh.y"
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
#line 1377 "Gmsh.y"
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
#line 1391 "Gmsh.y"
    {
      std::string key((yyvsp[(1) - (2)].c));
      std::string val((yyvsp[(2) - (2)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(1) - (2)].c));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 147:
#line 1399 "Gmsh.y"
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
#line 1424 "Gmsh.y"
    {
      std::string key((yyvsp[(1) - (2)].c));
      double val = (yyvsp[(2) - (2)].d);
      floatOptions[key].push_back(val);
      Free((yyvsp[(1) - (2)].c));
    ;}
    break;

  case 153:
#line 1432 "Gmsh.y"
    {
      std::string key((yyvsp[(1) - (2)].c));
      std::string val((yyvsp[(2) - (2)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(1) - (2)].c));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 154:
#line 1441 "Gmsh.y"
    {
      std::string key("Macro");
      std::string val((yyvsp[(2) - (2)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 155:
#line 1449 "Gmsh.y"
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
#line 1463 "Gmsh.y"
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
#line 1481 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    ;}
    break;

  case 158:
#line 1485 "Gmsh.y"
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
#line 1496 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (3)].c)), dim_entity, (yyvsp[(3) - (3)].d));
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 160:
#line 1504 "Gmsh.y"
    {
      (yyval.l) = 0;
    ;}
    break;

  case 161:
#line 1508 "Gmsh.y"
    {
      (yyval.l) = List_Create(1, 1, sizeof(double));
      double p = (yyvsp[(4) - (5)].d);
      List_Add((yyval.l), &p);
    ;}
    break;

  case 162:
#line 1514 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
    ;}
    break;

  case 163:
#line 1518 "Gmsh.y"
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
#line 1529 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = 0.;
    ;}
    break;

  case 165:
#line 1533 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 166:
#line 1539 "Gmsh.y"
    {
      (yyval.d) = 0;
    ;}
    break;

  case 167:
#line 1543 "Gmsh.y"
    {
      (yyval.d) = 1;
    ;}
    break;

  case 168:
#line 1549 "Gmsh.y"
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
#line 1572 "Gmsh.y"
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
#line 1588 "Gmsh.y"
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
#line 1604 "Gmsh.y"
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
#line 1621 "Gmsh.y"
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
#line 1638 "Gmsh.y"
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
#line 1675 "Gmsh.y"
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
#line 1719 "Gmsh.y"
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
#line 1735 "Gmsh.y"
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
#line 1752 "Gmsh.y"
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
#line 1783 "Gmsh.y"
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
#line 1799 "Gmsh.y"
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
#line 1816 "Gmsh.y"
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
#line 1832 "Gmsh.y"
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
#line 1882 "Gmsh.y"
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
#line 1900 "Gmsh.y"
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
#line 1921 "Gmsh.y"
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
#line 1942 "Gmsh.y"
    {
      myGmshSurface = 0;
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 186:
#line 1948 "Gmsh.y"
    {
      myGmshSurface = gmshSurface::getSurface((int)(yyvsp[(3) - (4)].d));
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 187:
#line 1954 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (10)].d);
      myGmshSurface = gmshParametricSurface::NewParametricSurface(num, (yyvsp[(7) - (10)].c), (yyvsp[(8) - (10)].c), (yyvsp[(9) - (10)].c));
      (yyval.s).Type = 0;
      (yyval.s).Num = num;
    ;}
    break;

  case 188:
#line 1961 "Gmsh.y"
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
#line 2002 "Gmsh.y"
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
#line 2017 "Gmsh.y"
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
#line 2049 "Gmsh.y"
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
#line 2083 "Gmsh.y"
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
#line 2116 "Gmsh.y"
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
#line 2151 "Gmsh.y"
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
#line 2186 "Gmsh.y"
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
#line 2221 "Gmsh.y"
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
#line 2245 "Gmsh.y"
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
#line 2271 "Gmsh.y"
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
#line 2288 "Gmsh.y"
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
#line 2304 "Gmsh.y"
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
#line 2322 "Gmsh.y"
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
#line 2340 "Gmsh.y"
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
#line 2353 "Gmsh.y"
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
#line 2365 "Gmsh.y"
    {
      dim_entity = (yyvsp[(2) - (2)].i);
    ;}
    break;

  case 205:
#line 2369 "Gmsh.y"
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
#line 2395 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 207:
#line 2397 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 208:
#line 2399 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 209:
#line 2401 "Gmsh.y"
    { (yyval.i) = 3; ;}
    break;

  case 210:
#line 2403 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(3) - (4)].d);
      if((yyval.i) < 0 || (yyval.i) > 3) yymsg(0, "GeoEntity dim out of range [0,3]");
    ;}
    break;

  case 211:
#line 2411 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 212:
#line 2413 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 213:
#line 2415 "Gmsh.y"
    { (yyval.i) = 3; ;}
    break;

  case 214:
#line 2417 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(3) - (4)].d);
      if((yyval.i)<1 || (yyval.i)>3) yymsg(0, "GeoEntity dim out of range [1,3]");
    ;}
    break;

  case 215:
#line 2425 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 216:
#line 2427 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 217:
#line 2429 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(3) - (4)].d);
      if((yyval.i)<1 || (yyval.i)>2) yymsg(0, "GeoEntity dim out of range [1,2]");
    ;}
    break;

  case 218:
#line 2437 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 219:
#line 2439 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 220:
#line 2441 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 221:
#line 2443 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(3) - (4)].d);
      if((yyval.i) < 0 || (yyval.i) > 2) yymsg(0, "GeoEntity dim out of range [0,2]");
    ;}
    break;

  case 222:
#line 2453 "Gmsh.y"
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
#line 2469 "Gmsh.y"
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
#line 2485 "Gmsh.y"
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
#line 2501 "Gmsh.y"
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
#line 2517 "Gmsh.y"
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
#line 2533 "Gmsh.y"
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
#line 2550 "Gmsh.y"
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
#line 2576 "Gmsh.y"
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
#line 2619 "Gmsh.y"
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
#line 2640 "Gmsh.y"
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
#line 2661 "Gmsh.y"
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
#line 2686 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 234:
#line 2687 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 235:
#line 2692 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    ;}
    break;

  case 236:
#line 2696 "Gmsh.y"
    {
      List_Add((yyval.l), &(yyvsp[(2) - (2)].s));
    ;}
    break;

  case 237:
#line 2700 "Gmsh.y"
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
#line 2717 "Gmsh.y"
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
#line 2737 "Gmsh.y"
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
#line 2757 "Gmsh.y"
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
#line 2777 "Gmsh.y"
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
#line 2796 "Gmsh.y"
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
#line 2823 "Gmsh.y"
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
#line 2848 "Gmsh.y"
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
#line 2873 "Gmsh.y"
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
#line 2885 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      GModel::current()->getFields()->deleteField((int)(yyvsp[(4) - (6)].d));
#endif
    ;}
    break;

  case 247:
#line 2891 "Gmsh.y"
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
#line 2906 "Gmsh.y"
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
#line 2937 "Gmsh.y"
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
#line 2949 "Gmsh.y"
    {
      gmsh_yynamespaces.clear();
    ;}
    break;

  case 251:
#line 2958 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), dimTags);
      setColor(dimTags, (yyvsp[(2) - (5)].u), false);
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 252:
#line 2965 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(5) - (6)].l), dimTags);
      setColor(dimTags, (yyvsp[(3) - (6)].u), true);
      List_Delete((yyvsp[(5) - (6)].l));
    ;}
    break;

  case 253:
#line 2977 "Gmsh.y"
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
#line 2997 "Gmsh.y"
    {
      setVisibility(-1, 1, false);
    ;}
    break;

  case 255:
#line 3001 "Gmsh.y"
    {
      setVisibility(-1, 1, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 256:
#line 3006 "Gmsh.y"
    {
      setVisibility(-1, 0, false);
    ;}
    break;

  case 257:
#line 3010 "Gmsh.y"
    {
      setVisibility(-1, 0, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 258:
#line 3015 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(3) - (4)].l), dimTags);
      setVisibility(dimTags, 1, false);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 259:
#line 3022 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), dimTags);
      setVisibility(dimTags, 1, true);
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 260:
#line 3029 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(3) - (4)].l), dimTags);
      setVisibility(dimTags, 0, false);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 261:
#line 3036 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), dimTags);
      setVisibility(dimTags, 0, true);
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 262:
#line 3048 "Gmsh.y"
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
#line 3124 "Gmsh.y"
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
#line 3142 "Gmsh.y"
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
#line 3167 "Gmsh.y"
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
#line 3182 "Gmsh.y"
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
        GModel::current()->synchronizeDiscreteCADInternals();
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
      else if(!strcmp((yyvsp[(1) - (3)].c), "CreateOverlaps")) {
        GModel::current()->createOverlaps((yyvsp[(2) - (3)].d));
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

  case 267:
#line 3235 "Gmsh.y"
    {
#if defined(HAVE_FLTK)
      FlGui::instance()->splitCurrentOpenglWindow('u');
#endif
    ;}
    break;

  case 268:
#line 3241 "Gmsh.y"
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
#line 3253 "Gmsh.y"
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
#line 3285 "Gmsh.y"
    {
      Msg::Exit(0, false); // will return 0 only if no meshing error occurred
    ;}
    break;

  case 271:
#line 3289 "Gmsh.y"
    {
      Msg::Exit((int)(yyvsp[(2) - (3)].d), true); // will always return the specified value
    ;}
    break;

  case 272:
#line 3293 "Gmsh.y"
    {
      gmsh_yyerrorstate = 999; // this will be checked when yyparse returns
      YYABORT;
    ;}
    break;

  case 273:
#line 3298 "Gmsh.y"
    {
      // force sync
      if(GModel::current()->getOCCInternals())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      GModel::current()->synchronizeDiscreteCADInternals();
      GModel::current()->getGEOInternals()->synchronize(GModel::current());
    ;}
    break;

  case 274:
#line 3306 "Gmsh.y"
    {
      new GModel();
      GModel::current(GModel::list.size() - 1);
    ;}
    break;

  case 275:
#line 3311 "Gmsh.y"
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
#line 3322 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 1;
      SetBoundingBox((yyvsp[(3) - (15)].d), (yyvsp[(5) - (15)].d), (yyvsp[(7) - (15)].d), (yyvsp[(9) - (15)].d), (yyvsp[(11) - (15)].d), (yyvsp[(13) - (15)].d));
    ;}
    break;

  case 277:
#line 3327 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
      drawContext::global()->draw(false); // not rate limited
#endif
    ;}
    break;

  case 278:
#line 3333 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
     CTX::instance()->meshChanged();
     for(std::size_t index = 0; index < PView::list.size(); index++)
       PView::list[index]->setChanged(true);
#endif
    ;}
    break;

  case 279:
#line 3341 "Gmsh.y"
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
#line 3352 "Gmsh.y"
    {
      GModel::current()->makeDiscreteRegionsSimplyConnected();
      GModel::current()->makeDiscreteFacesSimplyConnected();
      GModel::current()->createTopologyFromMesh();
      // Warning: this clears GEO_Internals!
      GModel::current()->exportDiscreteGEOInternals();
    ;}
    break;

  case 281:
#line 3360 "Gmsh.y"
    {
      GModel::current()->classifySurfaces((yyvsp[(3) - (9)].d), (yyvsp[(5) - (9)].d), (yyvsp[(7) - (9)].d), M_PI);
    ;}
    break;

  case 282:
#line 3364 "Gmsh.y"
    {
      GModel::current()->classifySurfaces((yyvsp[(3) - (11)].d), (yyvsp[(5) - (11)].d), (yyvsp[(7) - (11)].d), (yyvsp[(9) - (11)].d));
    ;}
    break;

  case 283:
#line 3368 "Gmsh.y"
    {
      GModel::current()->createGeometryOfDiscreteEntities();
    ;}
    break;

  case 284:
#line 3372 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(3) - (4)].l), dimTags);
      GModel::current()->createGeometryOfDiscreteEntities(dimTags);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 285:
#line 3379 "Gmsh.y"
    {
      GModel::current()->renumberMeshVertices();
    ;}
    break;

  case 286:
#line 3383 "Gmsh.y"
    {
      GModel::current()->renumberMeshElements();
    ;}
    break;

  case 287:
#line 3387 "Gmsh.y"
    {
      GModel::current()->createMEdges();
    ;}
    break;

  case 288:
#line 3391 "Gmsh.y"
    {
      GModel::current()->createMFaces();
    ;}
    break;

  case 289:
#line 3395 "Gmsh.y"
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
#line 3408 "Gmsh.y"
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
#line 3418 "Gmsh.y"
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
#line 3438 "Gmsh.y"
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
#line 3464 "Gmsh.y"
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
#line 3480 "Gmsh.y"
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
#line 3497 "Gmsh.y"
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
#line 3514 "Gmsh.y"
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
#line 3536 "Gmsh.y"
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
#line 3558 "Gmsh.y"
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
#line 3593 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip(nullptr, "Return");
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 300:
#line 3601 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip(nullptr, "Return");
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 301:
#line 3609 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    ;}
    break;

  case 302:
#line 3615 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function '%s'", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 303:
#line 3622 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function '%s'", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 304:
#line 3629 "Gmsh.y"
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
#line 3649 "Gmsh.y"
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
#line 3675 "Gmsh.y"
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
#line 3687 "Gmsh.y"
    {
      ImbricatedTest--;
      if(ImbricatedTest < 0)
        yymsg(1, "Orphan EndIf");
    ;}
    break;

  case 308:
#line 3698 "Gmsh.y"
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
#line 3716 "Gmsh.y"
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
#line 3734 "Gmsh.y"
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
#line 3752 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 312:
#line 3758 "Gmsh.y"
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
#line 3776 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 314:
#line 3782 "Gmsh.y"
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
#line 3802 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 316:
#line 3808 "Gmsh.y"
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
#line 3826 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 318:
#line 3832 "Gmsh.y"
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
#line 3849 "Gmsh.y"
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
#line 3865 "Gmsh.y"
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
#line 3882 "Gmsh.y"
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
#line 3900 "Gmsh.y"
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

  case 323:
#line 3923 "Gmsh.y"
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
#line 3950 "Gmsh.y"
    {
    ;}
    break;

  case 325:
#line 3953 "Gmsh.y"
    {
    ;}
    break;

  case 326:
#line 3959 "Gmsh.y"
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
#line 3971 "Gmsh.y"
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
#line 3991 "Gmsh.y"
    {
      extr.mesh.ScaleLast = true;
    ;}
    break;

  case 329:
#line 3995 "Gmsh.y"
    {
      extr.mesh.Recombine = true;
    ;}
    break;

  case 330:
#line 3999 "Gmsh.y"
    {
      extr.mesh.Recombine = (yyvsp[(2) - (3)].d) ? true : false;
    ;}
    break;

  case 331:
#line 4003 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1;
    ;}
    break;

  case 332:
#line 4007 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1_RECOMB;
    ;}
    break;

  case 333:
#line 4011 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1;
    ;}
    break;

  case 334:
#line 4015 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1_RECOMB;
    ;}
    break;

  case 335:
#line 4019 "Gmsh.y"
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
#line 4028 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (6)].c), "Index"))
        extr.mesh.BoundaryLayerIndex = (yyvsp[(4) - (6)].d);
      else if(!strcmp((yyvsp[(2) - (6)].c), "View"))
        extr.mesh.ViewIndex = (yyvsp[(4) - (6)].d);
      Free((yyvsp[(2) - (6)].c));
    ;}
    break;

  case 337:
#line 4040 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Union; ;}
    break;

  case 338:
#line 4041 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Intersection; ;}
    break;

  case 339:
#line 4042 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Difference; ;}
    break;

  case 340:
#line 4043 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Section; ;}
    break;

  case 341:
#line 4044 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Fragments; ;}
    break;

  case 342:
#line 4048 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 343:
#line 4049 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 344:
#line 4050 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 345:
#line 4051 "Gmsh.y"
    { (yyval.i) = (yyvsp[(2) - (3)].d) ? 1 : 0; ;}
    break;

  case 346:
#line 4052 "Gmsh.y"
    { (yyval.i) = (yyvsp[(3) - (4)].d) ? 2 : 0; ;}
    break;

  case 347:
#line 4057 "Gmsh.y"
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
#line 4096 "Gmsh.y"
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

  case 349:
#line 4112 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      DiscreteShapeFromFile((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d), M_PI, -1., (yyval.l));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 350:
#line 4118 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      DiscreteShapeFromFile((yyvsp[(3) - (8)].c), (yyvsp[(5) - (8)].d), (yyvsp[(7) - (8)].d), -1., (yyval.l));
      Free((yyvsp[(3) - (8)].c));
    ;}
    break;

  case 351:
#line 4124 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      DiscreteShapeFromFile((yyvsp[(3) - (10)].c), (yyvsp[(5) - (10)].d), (yyvsp[(7) - (10)].d), (yyvsp[(9) - (10)].d), (yyval.l));
      Free((yyvsp[(3) - (10)].c));
    ;}
    break;

  case 352:
#line 4134 "Gmsh.y"
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

  case 353:
#line 4170 "Gmsh.y"
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    ;}
    break;

  case 354:
#line 4174 "Gmsh.y"
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

  case 355:
#line 4201 "Gmsh.y"
    {
      (yyval.i) = -1; // left
    ;}
    break;

  case 356:
#line 4205 "Gmsh.y"
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
#line 4221 "Gmsh.y"
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   ;}
    break;

  case 358:
#line 4225 "Gmsh.y"
    {
     (yyval.l) = (yyvsp[(2) - (2)].l);
   ;}
    break;

  case 359:
#line 4230 "Gmsh.y"
    {
      (yyval.i) = 45;
    ;}
    break;

  case 360:
#line 4234 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(2) - (2)].d);
    ;}
    break;

  case 361:
#line 4240 "Gmsh.y"
    {
      (yyval.l) = List_Create(1, 1, sizeof(double));
    ;}
    break;

  case 362:
#line 4244 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
    ;}
    break;

  case 363:
#line 4251 "Gmsh.y"
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

  case 364:
#line 4274 "Gmsh.y"
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

  case 365:
#line 4293 "Gmsh.y"
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

  case 366:
#line 4335 "Gmsh.y"
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

  case 367:
#line 4381 "Gmsh.y"
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

  case 368:
#line 4422 "Gmsh.y"
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

  case 369:
#line 4448 "Gmsh.y"
    {
      int dim = (int)(yyvsp[(2) - (8)].i);
      int tag = (int)(yyvsp[(4) - (8)].d);
      int new_tag = (int)(yyvsp[(6) - (8)].d);
      GModel::current()->changeEntityTag(dim, tag, new_tag);
    ;}
    break;

  case 370:
#line 4455 "Gmsh.y"
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

  case 371:
#line 4466 "Gmsh.y"
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

  case 372:
#line 4484 "Gmsh.y"
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

  case 373:
#line 4502 "Gmsh.y"
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

  case 374:
#line 4533 "Gmsh.y"
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

  case 375:
#line 4560 "Gmsh.y"
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

  case 376:
#line 4588 "Gmsh.y"
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

  case 377:
#line 4620 "Gmsh.y"
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

  case 378:
#line 4648 "Gmsh.y"
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

  case 379:
#line 4674 "Gmsh.y"
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

  case 380:
#line 4700 "Gmsh.y"
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

  case 381:
#line 4726 "Gmsh.y"
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

  case 382:
#line 4752 "Gmsh.y"
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

  case 383:
#line 4773 "Gmsh.y"
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

  case 384:
#line 4785 "Gmsh.y"
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

  case 385:
#line 4834 "Gmsh.y"
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

  case 386:
#line 4889 "Gmsh.y"
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

  case 387:
#line 4905 "Gmsh.y"
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

  case 388:
#line 4917 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (4)].l), tags);
      GModel::current()->getGEOInternals()->setCompoundMesh((yyvsp[(2) - (4)].i), tags);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 389:
#line 4923 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (6)].l), tags);
      tags.push_back(- (int) (yyvsp[(5) - (6)].d));
      GModel::current()->getGEOInternals()->setCompoundMesh((yyvsp[(2) - (6)].i), tags);
      List_Delete((yyvsp[(3) - (6)].l));
    ;}
    break;

  case 390:
#line 4935 "Gmsh.y"
    {
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals())
        GModel::current()->getOCCInternals()->removeAllDuplicates();
      else
        GModel::current()->getGEOInternals()->removeAllDuplicates();
    ;}
    break;

  case 391:
#line 4942 "Gmsh.y"
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

  case 392:
#line 4957 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(4) - (6)].l), tags);
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals())
        GModel::current()->getOCCInternals()->mergeVertices(tags);
      else
        GModel::current()->getGEOInternals()->mergeVertices(tags);
      List_Delete((yyvsp[(4) - (6)].l));
    ;}
    break;

  case 393:
#line 4966 "Gmsh.y"
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

  case 394:
#line 4986 "Gmsh.y"
    { (yyval.c) = (char*)"Homology"; ;}
    break;

  case 395:
#line 4987 "Gmsh.y"
    { (yyval.c) = (char*)"Cohomology"; ;}
    break;

  case 396:
#line 4988 "Gmsh.y"
    { (yyval.c) = (char*)"Betti"; ;}
    break;

  case 397:
#line 4993 "Gmsh.y"
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest((yyvsp[(1) - (2)].c), domain, subdomain, dim);
    ;}
    break;

  case 398:
#line 4999 "Gmsh.y"
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
#line 5011 "Gmsh.y"
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
#line 5029 "Gmsh.y"
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
#line 5056 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d);           ;}
    break;

  case 402:
#line 5057 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (3)].d);           ;}
    break;

  case 403:
#line 5058 "Gmsh.y"
    { (yyval.d) = -(yyvsp[(2) - (2)].d);          ;}
    break;

  case 404:
#line 5059 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);           ;}
    break;

  case 405:
#line 5060 "Gmsh.y"
    { (yyval.d) = !(yyvsp[(2) - (2)].d);          ;}
    break;

  case 406:
#line 5061 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) - (yyvsp[(3) - (3)].d);      ;}
    break;

  case 407:
#line 5062 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) + (yyvsp[(3) - (3)].d);      ;}
    break;

  case 408:
#line 5063 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) * (yyvsp[(3) - (3)].d);      ;}
    break;

  case 409:
#line 5065 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (3)].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));
      else
	(yyval.d) = (yyvsp[(1) - (3)].d) / (yyvsp[(3) - (3)].d);
    ;}
    break;

  case 410:
#line 5071 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) | (int)(yyvsp[(3) - (3)].d); ;}
    break;

  case 411:
#line 5072 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) & (int)(yyvsp[(3) - (3)].d); ;}
    break;

  case 412:
#line 5073 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) % (int)(yyvsp[(3) - (3)].d); ;}
    break;

  case 413:
#line 5074 "Gmsh.y"
    { (yyval.d) = pow((yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));  ;}
    break;

  case 414:
#line 5075 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d);      ;}
    break;

  case 415:
#line 5076 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) > (yyvsp[(3) - (3)].d);      ;}
    break;

  case 416:
#line 5077 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) <= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 417:
#line 5078 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) >= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 418:
#line 5079 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) == (yyvsp[(3) - (3)].d);     ;}
    break;

  case 419:
#line 5080 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) != (yyvsp[(3) - (3)].d);     ;}
    break;

  case 420:
#line 5081 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) && (yyvsp[(3) - (3)].d);     ;}
    break;

  case 421:
#line 5082 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) || (yyvsp[(3) - (3)].d);     ;}
    break;

  case 422:
#line 5083 "Gmsh.y"
    { (yyval.d) = ((int)(yyvsp[(1) - (3)].d) >> (int)(yyvsp[(3) - (3)].d)); ;}
    break;

  case 423:
#line 5084 "Gmsh.y"
    { (yyval.d) = ((int)(yyvsp[(1) - (3)].d) << (int)(yyvsp[(3) - (3)].d)); ;}
    break;

  case 424:
#line 5085 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (5)].d) ? (yyvsp[(3) - (5)].d) : (yyvsp[(5) - (5)].d); ;}
    break;

  case 425:
#line 5086 "Gmsh.y"
    { (yyval.d) = ((yyvsp[(3) - (4)].d) < 0) ? 0 : 1; ;}
    break;

  case 426:
#line 5087 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 427:
#line 5088 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 428:
#line 5089 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 429:
#line 5090 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 430:
#line 5091 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 431:
#line 5092 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 432:
#line 5093 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 433:
#line 5094 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 434:
#line 5095 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 435:
#line 5096 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 436:
#line 5097 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 437:
#line 5098 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 438:
#line 5099 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 439:
#line 5100 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 440:
#line 5101 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 441:
#line 5102 "Gmsh.y"
    { (yyval.d) = std::abs((yyvsp[(3) - (4)].d)); ;}
    break;

  case 442:
#line 5103 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 443:
#line 5104 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 444:
#line 5105 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d) + 0.5); ;}
    break;

  case 445:
#line 5106 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 446:
#line 5107 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 447:
#line 5108 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 448:
#line 5109 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 449:
#line 5110 "Gmsh.y"
    { (yyval.d) = std::max((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 450:
#line 5111 "Gmsh.y"
    { (yyval.d) = std::min((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 451:
#line 5120 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 452:
#line 5121 "Gmsh.y"
    { (yyval.d) = 3.141592653589793; ;}
    break;

  case 453:
#line 5122 "Gmsh.y"
    { (yyval.d) = (double)ImbricatedTest; ;}
    break;

  case 454:
#line 5123 "Gmsh.y"
    { (yyval.d) = Msg::GetCommRank(); ;}
    break;

  case 455:
#line 5124 "Gmsh.y"
    { (yyval.d) = Msg::GetCommSize(); ;}
    break;

  case 456:
#line 5125 "Gmsh.y"
    { (yyval.d) = GetGmshMajorVersion(); ;}
    break;

  case 457:
#line 5126 "Gmsh.y"
    { (yyval.d) = GetGmshMinorVersion(); ;}
    break;

  case 458:
#line 5127 "Gmsh.y"
    { (yyval.d) = GetGmshPatchVersion(); ;}
    break;

  case 459:
#line 5128 "Gmsh.y"
    { (yyval.d) = Cpu(); ;}
    break;

  case 460:
#line 5129 "Gmsh.y"
    { (yyval.d) = GetMemoryUsage()/1024./1024.; ;}
    break;

  case 461:
#line 5130 "Gmsh.y"
    { (yyval.d) = TotalRam(); ;}
    break;

  case 462:
#line 5135 "Gmsh.y"
    { init_options(); ;}
    break;

  case 463:
#line 5137 "Gmsh.y"
    {
      std::vector<double> val(1, (yyvsp[(3) - (6)].d));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.d) = val[0];
    ;}
    break;

  case 464:
#line 5143 "Gmsh.y"
    {
      (yyval.d) = (yyvsp[(1) - (1)].d);
    ;}
    break;

  case 465:
#line 5147 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 466:
#line 5152 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 467:
#line 5157 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(1) - (1)].c2).char1, (yyvsp[(1) - (1)].c2).char2);
    ;}
    break;

  case 468:
#line 5162 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float(nullptr, (yyvsp[(1) - (4)].c), 2, (int)(yyvsp[(3) - (4)].d));
    ;}
    break;

  case 469:
#line 5167 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float(nullptr, (yyvsp[(1) - (4)].c), 2, (int)(yyvsp[(3) - (4)].d));
    ;}
    break;

  case 470:
#line 5171 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(3) - (4)].c2).char1, (yyvsp[(3) - (4)].c2).char2, 1, 0, 0., 1);
    ;}
    break;

  case 471:
#line 5175 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(3) - (6)].c2).char1, (yyvsp[(3) - (6)].c2).char2, (yyvsp[(5) - (6)].c), 0, 0., 1);
    ;}
    break;

  case 472:
#line 5179 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(3) - (5)].c2).char1, (yyvsp[(3) - (5)].c2).char2, 1, 0, (yyvsp[(4) - (5)].d), 2);
    ;}
    break;

  case 473:
#line 5183 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(3) - (7)].c2).char1, (yyvsp[(3) - (7)].c2).char2, (yyvsp[(5) - (7)].c), 0, (yyvsp[(6) - (7)].d), 2);
    ;}
    break;

  case 474:
#line 5187 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(3) - (8)].c2).char1, (yyvsp[(3) - (8)].c2).char2, 2, (int)(yyvsp[(5) - (8)].d), (yyvsp[(7) - (8)].d), 2);
    ;}
    break;

  case 475:
#line 5191 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(3) - (10)].c2).char1, (yyvsp[(3) - (10)].c2).char2, (yyvsp[(5) - (10)].c), (int)(yyvsp[(7) - (10)].d), (yyvsp[(9) - (10)].d), 2);
    ;}
    break;

  case 476:
#line 5195 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.d) = !StatFile(tmp);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 477:
#line 5201 "Gmsh.y"
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

  case 478:
#line 5216 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float_getDim((yyvsp[(2) - (6)].c2).char1, (yyvsp[(2) - (6)].c2).char2, (yyvsp[(4) - (6)].c));
    ;}
    break;

  case 479:
#line 5220 "Gmsh.y"
    {
      std::string struct_namespace((yyvsp[(3) - (4)].c));
      (yyval.d) = (double)gmsh_yynamespaces[struct_namespace].size();
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 480:
#line 5226 "Gmsh.y"
    {
      std::string struct_namespace(std::string(""));
      (yyval.d) = (double)gmsh_yynamespaces[struct_namespace].size();
    ;}
    break;

  case 481:
#line 5231 "Gmsh.y"
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

  case 482:
#line 5250 "Gmsh.y"
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

  case 483:
#line 5270 "Gmsh.y"
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

  case 484:
#line 5291 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(nullptr, (yyvsp[(1) - (3)].c), (yyvsp[(3) - (3)].c));
    ;}
    break;

  case 485:
#line 5295 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c), (yyvsp[(5) - (5)].c));
    ;}
    break;

  case 486:
#line 5299 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(nullptr, (yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].c), (int)(yyvsp[(5) - (6)].d));
    ;}
    break;

  case 487:
#line 5303 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(1) - (8)].c), (yyvsp[(3) - (8)].c), (yyvsp[(5) - (8)].c), (int)(yyvsp[(7) - (8)].d));
    ;}
    break;

  case 488:
#line 5307 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(nullptr, (yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].c), (int)(yyvsp[(5) - (6)].d));
    ;}
    break;

  case 489:
#line 5311 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(1) - (8)].c), (yyvsp[(3) - (8)].c), (yyvsp[(5) - (8)].c), (int)(yyvsp[(7) - (8)].d));
    ;}
    break;

  case 490:
#line 5315 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), (yyval.d));
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 491:
#line 5320 "Gmsh.y"
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

  case 492:
#line 5330 "Gmsh.y"
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

  case 493:
#line 5340 "Gmsh.y"
    {
      (yyval.d) = Msg::GetValue((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 494:
#line 5345 "Gmsh.y"
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

  case 495:
#line 5356 "Gmsh.y"
    {
      std::string s((yyvsp[(3) - (6)].c)), substr((yyvsp[(5) - (6)].c));
      if(s.find(substr) != std::string::npos)
        (yyval.d) = 1.;
      else
        (yyval.d) = 0.;
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 496:
#line 5365 "Gmsh.y"
    {
      (yyval.d) = strlen((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 497:
#line 5370 "Gmsh.y"
    {
      (yyval.d) = strcmp((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 498:
#line 5375 "Gmsh.y"
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

  case 499:
#line 5402 "Gmsh.y"
    { (yyval.d) = 0.; ;}
    break;

  case 500:
#line 5404 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);;}
    break;

  case 501:
#line 5409 "Gmsh.y"
    { (yyval.c) = nullptr; ;}
    break;

  case 502:
#line 5411 "Gmsh.y"
    { (yyval.c) = (yyvsp[(2) - (2)].c);;}
    break;

  case 503:
#line 5416 "Gmsh.y"
    {
      std::string struct_namespace((yyvsp[(2) - (3)].c2).char1? (yyvsp[(2) - (3)].c2).char1 : std::string("")),
        struct_name((yyvsp[(2) - (3)].c2).char2);
      init_options
        (gmsh_yynamespaces.getMember_ValMax(struct_namespace, struct_name));
    ;}
    break;

  case 504:
#line 5423 "Gmsh.y"
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

  case 505:
#line 5439 "Gmsh.y"
    { (yyval.c2).char1 = nullptr; (yyval.c2).char2 = (yyvsp[(1) - (1)].c); ;}
    break;

  case 506:
#line 5441 "Gmsh.y"
    { (yyval.c2).char1 = (yyvsp[(1) - (3)].c); (yyval.c2).char2 = (yyvsp[(3) - (3)].c); ;}
    break;

  case 507:
#line 5446 "Gmsh.y"
    { (yyval.i) = 99; ;}
    break;

  case 508:
#line 5448 "Gmsh.y"
    { (yyval.i) = (int)(yyvsp[(2) - (2)].d); ;}
    break;

  case 509:
#line 5453 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 510:
#line 5455 "Gmsh.y"
    { (yyval.i) = (yyvsp[(2) - (3)].i); ;}
    break;

  case 511:
#line 5460 "Gmsh.y"
    {
      memcpy((yyval.v), (yyvsp[(1) - (1)].v), 5 * sizeof(double));
    ;}
    break;

  case 512:
#line 5464 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 513:
#line 5468 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 514:
#line 5472 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] - (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 515:
#line 5476 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] + (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 516:
#line 5483 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (11)].d);  (yyval.v)[1] = (yyvsp[(4) - (11)].d);  (yyval.v)[2] = (yyvsp[(6) - (11)].d);  (yyval.v)[3] = (yyvsp[(8) - (11)].d); (yyval.v)[4] = (yyvsp[(10) - (11)].d);
    ;}
    break;

  case 517:
#line 5487 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (9)].d);  (yyval.v)[1] = (yyvsp[(4) - (9)].d);  (yyval.v)[2] = (yyvsp[(6) - (9)].d);  (yyval.v)[3] = (yyvsp[(8) - (9)].d); (yyval.v)[4] = 1.0;
    ;}
    break;

  case 518:
#line 5491 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 519:
#line 5495 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 520:
#line 5502 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].l)));
    ;}
    break;

  case 521:
#line 5507 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].l)));
    ;}
    break;

  case 522:
#line 5514 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 523:
#line 5519 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 524:
#line 5523 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
    ;}
    break;

  case 525:
#line 5527 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 526:
#line 5531 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 527:
#line 5539 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (5)].d);
      }
    ;}
    break;

  case 528:
#line 5550 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
    ;}
    break;

  case 529:
#line 5554 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 530:
#line 5558 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 531:
#line 5569 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 532:
#line 5573 "Gmsh.y"
    {
      (yyval.l) = 0;
    ;}
    break;

  case 533:
#line 5577 "Gmsh.y"
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

  case 534:
#line 5591 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 535:
#line 5599 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (3)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (3)].d);
      }
    ;}
    break;

  case 536:
#line 5607 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      for(double d = (yyvsp[(1) - (3)].d); ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d <= (yyvsp[(3) - (3)].d)) : (d >= (yyvsp[(3) - (3)].d));
          ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d += 1.) : (d -= 1.))
	List_Add((yyval.l), &d);
    ;}
    break;

  case 537:
#line 5614 "Gmsh.y"
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

  case 538:
#line 5624 "Gmsh.y"
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

  case 539:
#line 5647 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags(0, (yyval.l));
    ;}
    break;

  case 540:
#line 5652 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags(0, (yyval.l));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 541:
#line 5658 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags((yyvsp[(1) - (4)].i), (yyval.l));
    ;}
    break;

  case 542:
#line 5663 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags((yyvsp[(1) - (2)].i), (yyval.l));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 543:
#line 5669 "Gmsh.y"
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

  case 544:
#line 5680 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getElementaryTagsForPhysicalNames((yyvsp[(2) - (5)].i), (yyvsp[(4) - (5)].l), (yyval.l));
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 545:
#line 5686 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getParentTags((yyvsp[(2) - (3)].i), (yyvsp[(3) - (3)].l), (yyval.l));
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 546:
#line 5692 "Gmsh.y"
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

  case 547:
#line 5706 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getBoundingBox((yyvsp[(2) - (5)].i), (yyvsp[(4) - (5)].l), (yyval.l));
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 548:
#line 5712 "Gmsh.y"
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

  case 549:
#line 5724 "Gmsh.y"
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

  case 550:
#line 5738 "Gmsh.y"
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

  case 551:
#line 5751 "Gmsh.y"
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

  case 552:
#line 5782 "Gmsh.y"
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

  case 553:
#line 5806 "Gmsh.y"
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

  case 554:
#line 5827 "Gmsh.y"
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

  case 555:
#line 5847 "Gmsh.y"
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

  case 556:
#line 5868 "Gmsh.y"
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

  case 557:
#line 5885 "Gmsh.y"
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

  case 558:
#line 5895 "Gmsh.y"
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

  case 559:
#line 5905 "Gmsh.y"
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

  case 560:
#line 5915 "Gmsh.y"
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

  case 561:
#line 5927 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfFloat(nullptr, (yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c));
    ;}
    break;

  case 562:
#line 5931 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfFloat((yyvsp[(1) - (7)].c), (yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].c));
    ;}
    break;

  case 563:
#line 5936 "Gmsh.y"
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

  case 564:
#line 5948 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 565:
#line 5952 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 566:
#line 5956 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (6)].l);
    ;}
    break;

  case 567:
#line 5960 "Gmsh.y"
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

  case 568:
#line 5978 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = (yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1);
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 569:
#line 5986 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = pow(10,(yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1));
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 570:
#line 5994 "Gmsh.y"
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

  case 571:
#line 6023 "Gmsh.y"
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

  case 572:
#line 6033 "Gmsh.y"
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

  case 573:
#line 6049 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
        double *d = (double*)List_Pointer((yyvsp[(3) - (4)].l), i);
        *d = std::abs(*d);
      }
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 574:
#line 6060 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 575:
#line 6065 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 576:
#line 6069 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].d)));
    ;}
    break;

  case 577:
#line 6073 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (3)].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 578:
#line 6085 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(char*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].c)));
    ;}
    break;

  case 579:
#line 6090 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].c)));
    ;}
    break;

  case 580:
#line 6097 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (9)].d), (int)(yyvsp[(4) - (9)].d), (int)(yyvsp[(6) - (9)].d), (int)(yyvsp[(8) - (9)].d));
    ;}
    break;

  case 581:
#line 6101 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (7)].d), (int)(yyvsp[(4) - (7)].d), (int)(yyvsp[(6) - (7)].d), 255);
    ;}
    break;

  case 582:
#line 6113 "Gmsh.y"
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

  case 583:
#line 6130 "Gmsh.y"
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(5) - (5)].c), val);
      (yyval.u) = val;
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(5) - (5)].c));
    ;}
    break;

  case 584:
#line 6140 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 585:
#line 6144 "Gmsh.y"
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

  case 586:
#line 6159 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].u)));
    ;}
    break;

  case 587:
#line 6164 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].u)));
    ;}
    break;

  case 588:
#line 6171 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 589:
#line 6175 "Gmsh.y"
    {
      // No need to extend to Struct_FullName (a Tag is not a String)
      (yyval.c) = treat_Struct_FullName_String(nullptr, (yyvsp[(1) - (1)].c));
    ;}
    break;

  case 590:
#line 6180 "Gmsh.y"
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

  case 591:
#line 6194 "Gmsh.y"
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

  case 592:
#line 6208 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String(nullptr, (yyvsp[(1) - (3)].c), (yyvsp[(3) - (3)].c));
    ;}
    break;

  case 593:
#line 6212 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c), (yyvsp[(5) - (5)].c));
    ;}
    break;

  case 594:
#line 6216 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String(nullptr, (yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].c), (int)(yyvsp[(5) - (6)].d));
    ;}
    break;

  case 595:
#line 6220 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(1) - (8)].c), (yyvsp[(3) - (8)].c), (yyvsp[(5) - (8)].c), (int)(yyvsp[(7) - (8)].d));
    ;}
    break;

  case 596:
#line 6224 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 597:
#line 6232 "Gmsh.y"
    {
      std::string name = GModel::current()->getElementaryName((yyvsp[(1) - (4)].i), (int)(yyvsp[(3) - (4)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 598:
#line 6238 "Gmsh.y"
    {
      std::string name = GModel::current()->getPhysicalName((yyvsp[(2) - (5)].i), (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 599:
#line 6247 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 600:
#line 6251 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 601:
#line 6255 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    ;}
    break;

  case 602:
#line 6263 "Gmsh.y"
    {
      std::string exe = Msg::GetExecutableName();
      (yyval.c) = (char *)Malloc(exe.size() + 1);
      strcpy((yyval.c), exe.c_str());
    ;}
    break;

  case 603:
#line 6269 "Gmsh.y"
    {
      std::string action = Msg::GetOnelabAction();
      (yyval.c) = (char *)Malloc(action.size() + 1);
      strcpy((yyval.c), action.c_str());
    ;}
    break;

  case 604:
#line 6275 "Gmsh.y"
    {
      (yyval.c) = strsave((char*)"Gmsh");
    ;}
    break;

  case 605:
#line 6279 "Gmsh.y"
    {
      std::string env = GetEnvironmentVar((yyvsp[(3) - (4)].c));
      (yyval.c) = (char *)Malloc((env.size() + 1) * sizeof(char));
      strcpy((yyval.c), env.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 606:
#line 6286 "Gmsh.y"
    {
      std::string s = Msg::GetString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 607:
#line 6294 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (4)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 608:
#line 6301 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 609:
#line 6310 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_String(nullptr, (yyvsp[(3) - (5)].c2).char2, 1, 0, (yyvsp[(4) - (5)].c), 2);
    ;}
    break;

  case 610:
#line 6314 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(3) - (7)].c2).char1, (yyvsp[(3) - (7)].c2).char2, (yyvsp[(5) - (7)].c), 0, (yyvsp[(6) - (7)].c), 2);
    ;}
    break;

  case 611:
#line 6318 "Gmsh.y"
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

  case 612:
#line 6333 "Gmsh.y"
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

  case 613:
#line 6347 "Gmsh.y"
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

  case 614:
#line 6361 "Gmsh.y"
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

  case 615:
#line 6373 "Gmsh.y"
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

  case 616:
#line 6389 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = toupper((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 617:
#line 6398 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = tolower((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 618:
#line 6407 "Gmsh.y"
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

  case 619:
#line 6417 "Gmsh.y"
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

  case 620:
#line 6428 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (8)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (8)].d), (int)(yyvsp[(7) - (8)].d));
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (8)].c));
    ;}
    break;

  case 621:
#line 6436 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (6)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (6)].d), std::string::npos);
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 622:
#line 6444 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 623:
#line 6448 "Gmsh.y"
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

  case 624:
#line 6466 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 625:
#line 6473 "Gmsh.y"
    {
      std::string tmp = SplitFileName(GetAbsolutePath(gmsh_yyname))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
    ;}
    break;

  case 626:
#line 6479 "Gmsh.y"
    {
      std::string tmp = GetFileNameWithoutPath(gmsh_yyname);
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
    ;}
    break;

  case 627:
#line 6485 "Gmsh.y"
    {
      std::string tmp = SplitFileName((yyvsp[(3) - (4)].c))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 628:
#line 6492 "Gmsh.y"
    {
      std::string tmp = GetAbsolutePath((yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 629:
#line 6499 "Gmsh.y"
    { init_options(); ;}
    break;

  case 630:
#line 6501 "Gmsh.y"
    {
      std::string val((yyvsp[(3) - (6)].c));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.c) = (char*)Malloc((val.size() + 1) * sizeof(char));
      strcpy((yyval.c), val.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 631:
#line 6509 "Gmsh.y"
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

  case 632:
#line 6533 "Gmsh.y"
    { struct_namespace = std::string(""); (yyval.d) = (yyvsp[(2) - (2)].d); ;}
    break;

  case 633:
#line 6535 "Gmsh.y"
    { struct_namespace = (yyvsp[(1) - (4)].c); Free((yyvsp[(1) - (4)].c)); (yyval.d) = (yyvsp[(4) - (4)].d); ;}
    break;

  case 634:
#line 6541 "Gmsh.y"
    { (yyval.l) = (yyvsp[(3) - (4)].l); ;}
    break;

  case 635:
#line 6546 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 636:
#line 6548 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 637:
#line 6553 "Gmsh.y"
    { (yyval.l) = (yyvsp[(2) - (3)].l); ;}
    break;

  case 638:
#line 6558 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].c)));
    ;}
    break;

  case 639:
#line 6563 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 640:
#line 6565 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].c)));
    ;}
    break;

  case 641:
#line 6569 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	char* c;
	List_Read((yyvsp[(3) - (3)].l), i, &c);
	List_Add((yyval.l), &c);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 642:
#line 6581 "Gmsh.y"
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

  case 643:
#line 6595 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfString(nullptr, (yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c));
    ;}
    break;

  case 644:
#line 6599 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfString((yyvsp[(1) - (7)].c), (yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].c));
    ;}
    break;

  case 645:
#line 6606 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr) + 1) * sizeof(char));
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 646:
#line 6614 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr) + 1) * sizeof(char)) ;
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)) ; strcat((yyval.c), tmpstr) ;
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 647:
#line 6622 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(7) - (8)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(3) - (8)].c))+strlen(tmpstr) + 1) * sizeof(char));
      strcpy((yyval.c), (yyvsp[(3) - (8)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(3) - (8)].c));
    ;}
    break;

  case 648:
#line 6633 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 649:
#line 6635 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 650:
#line 6638 "Gmsh.y"
    { (yyval.c) = (yyvsp[(3) - (4)].c); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 14986 "Gmsh.tab.cpp"
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


#line 6641 "Gmsh.y"


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

