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
     tLevelset = 414,
     tAffine = 415,
     tClosest = 416,
     tBooleanUnion = 417,
     tBooleanIntersection = 418,
     tBooleanDifference = 419,
     tBooleanSection = 420,
     tBooleanFragments = 421,
     tThickSolid = 422,
     tRecombine = 423,
     tSmoother = 424,
     tSplit = 425,
     tDelete = 426,
     tCoherence = 427,
     tHealShapes = 428,
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
#define tLevelset 414
#define tAffine 415
#define tClosest 416
#define tBooleanUnion 417
#define tBooleanIntersection 418
#define tBooleanDifference 419
#define tBooleanSection 420
#define tBooleanFragments 421
#define tThickSolid 422
#define tRecombine 423
#define tSmoother 424
#define tSplit 425
#define tDelete 426
#define tCoherence 427
#define tHealShapes 428
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
#line 789 "Gmsh.tab.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 802 "Gmsh.tab.cpp"

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
#define YYLAST   19079

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  276
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  115
/* YYNRULES -- Number of rules.  */
#define YYNRULES  657
/* YYNRULES -- Number of states.  */
#define YYNSTATES  2367

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
    1656,  1659,  1662,  1665,  1682,  1688,  1697,  1709,  1716,  1725,
    1734,  1745,  1747,  1750,  1753,  1755,  1759,  1763,  1768,  1773,
    1775,  1777,  1783,  1795,  1809,  1810,  1818,  1819,  1833,  1834,
    1850,  1851,  1858,  1868,  1871,  1875,  1886,  1900,  1902,  1905,
    1911,  1919,  1922,  1925,  1929,  1932,  1936,  1939,  1943,  1953,
    1960,  1962,  1964,  1966,  1968,  1970,  1971,  1974,  1978,  1982,
    1987,  1997,  2002,  2017,  2018,  2022,  2023,  2025,  2026,  2029,
    2030,  2033,  2034,  2037,  2043,  2050,  2058,  2065,  2071,  2075,
    2084,  2091,  2100,  2109,  2115,  2120,  2127,  2139,  2151,  2170,
    2189,  2202,  2215,  2228,  2239,  2244,  2249,  2254,  2259,  2264,
    2271,  2274,  2278,  2285,  2288,  2290,  2292,  2294,  2297,  2303,
    2311,  2322,  2324,  2328,  2331,  2334,  2337,  2341,  2345,  2349,
    2353,  2357,  2361,  2365,  2369,  2373,  2377,  2381,  2385,  2389,
    2393,  2397,  2401,  2405,  2409,  2415,  2420,  2425,  2430,  2435,
    2440,  2445,  2450,  2455,  2460,  2465,  2470,  2477,  2482,  2487,
    2492,  2497,  2502,  2507,  2512,  2517,  2524,  2531,  2538,  2543,
    2550,  2557,  2559,  2561,  2563,  2565,  2567,  2569,  2571,  2573,
    2575,  2577,  2579,  2580,  2587,  2589,  2594,  2601,  2603,  2608,
    2613,  2618,  2625,  2631,  2639,  2648,  2659,  2664,  2669,  2676,
    2681,  2685,  2688,  2694,  2700,  2704,  2710,  2717,  2726,  2733,
    2742,  2749,  2754,  2762,  2769,  2776,  2783,  2788,  2795,  2800,
    2801,  2804,  2805,  2808,  2809,  2817,  2819,  2823,  2825,  2828,
    2829,  2833,  2835,  2838,  2841,  2845,  2849,  2861,  2871,  2879,
    2887,  2889,  2893,  2895,  2897,  2900,  2904,  2909,  2915,  2918,
    2922,  2927,  2929,  2933,  2935,  2938,  2942,  2946,  2952,  2957,
    2962,  2965,  2970,  2973,  2977,  2981,  2986,  2992,  2998,  3004,
    3010,  3017,  3029,  3041,  3051,  3062,  3068,  3070,  3072,  3074,
    3078,  3084,  3092,  3097,  3102,  3107,  3114,  3121,  3130,  3139,
    3144,  3159,  3164,  3169,  3171,  3173,  3177,  3181,  3191,  3199,
    3201,  3207,  3211,  3218,  3220,  3224,  3226,  3228,  3233,  3238,
    3242,  3248,  3255,  3264,  3271,  3276,  3282,  3284,  3289,  3291,
    3293,  3295,  3297,  3302,  3309,  3314,  3321,  3327,  3335,  3340,
    3345,  3350,  3359,  3364,  3369,  3374,  3379,  3388,  3397,  3404,
    3409,  3416,  3421,  3423,  3425,  3430,  3435,  3436,  3443,  3448,
    3451,  3456,  3461,  3463,  3465,  3469,  3471,  3473,  3477,  3481,
    3485,  3491,  3499,  3505,  3511,  3520,  3522,  3524
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     277,     0,    -1,   278,    -1,     1,     6,    -1,    -1,   278,
     279,    -1,   281,    -1,   282,    -1,   303,    -1,   137,   266,
     380,   267,     6,    -1,   322,    -1,   328,    -1,   332,    -1,
     333,    -1,   334,    -1,   335,    -1,   339,    -1,   348,    -1,
     349,    -1,   355,    -1,   356,    -1,   338,    -1,   337,    -1,
     336,    -1,   331,    -1,   358,    -1,   249,    -1,   250,    -1,
      47,   266,   380,   267,     6,    -1,    49,   266,   380,   267,
       6,    -1,    48,   266,   380,   267,     6,    -1,    47,   266,
     380,   267,   280,   380,     6,    -1,    47,   266,   380,   275,
     376,   267,     6,    -1,    49,   266,   380,   275,   376,   267,
       6,    -1,    48,   266,   380,   275,   376,   267,     6,    -1,
      47,   266,   380,   275,   376,   267,   280,   380,     6,    -1,
     390,   380,   270,   283,   271,     6,    -1,   182,     4,   268,
     359,   269,     6,    -1,   183,     4,   268,   359,   269,     6,
      -1,   184,     4,   268,   359,   275,   359,   269,     6,    -1,
      -1,   283,   286,    -1,   283,   290,    -1,   283,   293,    -1,
     283,   295,    -1,   283,   296,    -1,   283,   338,    -1,   359,
      -1,   284,   275,   359,    -1,   359,    -1,   285,   275,   359,
      -1,    -1,    -1,     4,   287,   266,   284,   267,   288,   270,
     285,   271,     6,    -1,   380,    -1,   289,   275,   380,    -1,
      -1,   189,   266,   359,   275,   359,   275,   359,   267,   291,
     270,   289,   271,     6,    -1,   380,    -1,   292,   275,   380,
      -1,    -1,   190,   266,   359,   275,   359,   275,   359,   275,
     359,   267,   294,   270,   292,   271,     6,    -1,   191,   270,
     371,   271,   270,   371,   271,     6,    -1,   191,   270,   371,
     271,   270,   371,   271,   270,   371,   271,   270,   371,   271,
       6,    -1,    -1,   192,   297,   270,   285,   271,     6,    -1,
       7,    -1,   242,    -1,   241,    -1,   240,    -1,   239,    -1,
     264,    -1,   263,    -1,   266,    -1,   268,    -1,   267,    -1,
     269,    -1,     4,    -1,    37,    -1,    38,    -1,    26,    -1,
     114,    -1,   115,    -1,    94,   268,   305,   269,     6,    -1,
      95,   268,   309,   269,     6,    -1,   364,     6,    -1,   102,
     300,   381,   275,   359,   301,     6,    -1,   104,   300,   381,
     275,   381,   301,     6,    -1,   390,   298,   372,     6,    -1,
     390,   299,     6,    -1,   390,   300,   301,   298,   372,     6,
      -1,   390,   300,   270,   376,   271,   301,   298,   372,     6,
      -1,   390,   268,   359,   269,   298,   359,     6,    -1,   390,
     268,   359,   269,   299,     6,    -1,   390,   266,   359,   267,
     298,   359,     6,    -1,   390,   266,   359,   267,   299,     6,
      -1,   390,     7,   381,     6,    -1,   390,   300,   301,     7,
      50,   300,   301,     6,    -1,   390,   300,   301,     7,    50,
     300,   385,   301,     6,    -1,   390,   300,   301,   242,    50,
     300,   385,   301,     6,    -1,   390,   272,   302,     7,   381,
       6,    -1,   390,   268,   359,   269,   272,   302,     7,   381,
       6,    -1,   390,   272,   302,   298,   359,     6,    -1,   390,
     268,   359,   269,   272,   302,   298,   359,     6,    -1,   390,
     272,   302,   299,     6,    -1,   390,   268,   359,   269,   272,
     302,   299,     6,    -1,   390,   272,   199,   272,   302,     7,
     377,     6,    -1,   390,   268,   359,   269,   272,   199,   272,
     302,     7,   377,     6,    -1,   390,   272,   200,     7,   378,
       6,    -1,   390,   268,   359,   269,   272,   200,     7,   378,
       6,    -1,   390,   210,     7,   372,     6,    -1,   210,   268,
     359,   269,     7,   302,     6,    -1,   210,   268,   359,   269,
     272,   302,     7,   359,     6,    -1,   210,   268,   359,   269,
     272,   302,     7,   381,     6,    -1,   210,   268,   359,   269,
     272,   302,     7,   373,     6,    -1,   210,   268,   359,   269,
     272,   302,     6,    -1,   150,   266,     4,   267,   272,   302,
       7,   359,     6,    -1,   150,   266,     4,   267,   272,   302,
       7,   381,     6,    -1,    -1,   275,    -1,    -1,   305,   304,
     390,    -1,   305,   304,   390,     7,   359,    -1,    -1,   305,
     304,   390,     7,   270,   372,   306,   311,   271,    -1,    -1,
     305,   304,   390,   300,   301,     7,   270,   372,   307,   311,
     271,    -1,   305,   304,   390,     7,   381,    -1,    -1,   305,
     304,   390,     7,   270,   381,   308,   315,   271,    -1,    -1,
     309,   304,   380,    -1,   359,     7,   381,    -1,   310,   275,
     359,     7,   381,    -1,   375,     7,   390,   266,   267,    -1,
      -1,   275,   313,    -1,    -1,   313,    -1,   314,    -1,   313,
     275,   314,    -1,     4,   372,    -1,    37,   359,    -1,    38,
     359,    -1,    26,   359,    -1,     4,    -1,     4,   270,   310,
     271,    -1,     4,   381,    -1,     4,   384,    -1,    -1,   275,
     316,    -1,   317,    -1,   316,   275,   317,    -1,     4,   359,
      -1,     4,   381,    -1,   214,   381,    -1,     4,   386,    -1,
       4,   384,    -1,   359,    -1,   381,    -1,   381,   275,   359,
      -1,    -1,   202,   109,   270,   359,   271,    -1,   149,   105,
     270,   376,   271,    -1,   149,   124,   270,   376,   271,    -1,
      -1,   142,   369,    -1,    -1,   149,   153,    -1,   105,   266,
     359,   267,     7,   369,     6,    -1,   108,   266,   359,   267,
       7,   372,     6,    -1,   112,   266,   359,   267,     7,   372,
       6,    -1,   146,   112,   266,   359,   267,     7,   372,   149,
     359,     6,    -1,   146,   194,   266,   359,   267,     7,   372,
     149,   359,     6,    -1,   106,   266,   359,   267,     7,   372,
     320,     6,    -1,   107,   266,   359,   267,     7,   372,   320,
       6,    -1,   194,   266,   359,   267,     7,   372,     6,    -1,
     195,   266,   359,   267,     7,   372,     6,    -1,   196,   266,
     359,   267,     7,   372,   198,   372,   197,   359,     6,    -1,
     123,   266,   359,   267,     7,   372,     6,    -1,   108,     4,
     266,   359,   267,     7,   372,     6,    -1,   142,   111,   266,
     359,   267,     7,   372,     6,    -1,   111,   266,   359,   267,
       7,   372,   319,     6,    -1,   143,   111,   266,   359,   267,
       7,   372,   319,     6,    -1,   194,   111,   266,   359,   267,
       7,   372,     6,    -1,   195,   111,   266,   359,   267,     7,
     372,     6,    -1,    13,    14,     6,    -1,    14,   111,   359,
       6,    -1,   129,   111,   266,   359,   267,     7,     5,     5,
       5,     6,    -1,   109,   266,   359,   267,     7,   372,     6,
      -1,   110,   266,   359,   267,     7,   372,     6,    -1,   114,
     266,   359,   267,     7,   372,     6,    -1,   117,   266,   359,
     267,     7,   372,     6,    -1,   121,   266,   359,   267,     7,
     372,     6,    -1,   122,   266,   359,   267,     7,   372,     6,
      -1,   115,   266,   359,   267,     7,   372,     6,    -1,   116,
     266,   359,   267,     7,   372,     6,    -1,   139,   266,   359,
     267,     7,   372,     6,    -1,   167,   266,   359,   267,     7,
     372,     6,    -1,   111,     4,   266,   359,   267,     7,   372,
     321,     6,    -1,   113,   266,   359,   267,     7,   372,     6,
      -1,   138,   266,   359,   267,     7,   372,     6,    -1,   143,
     138,   266,   359,   267,     7,   372,     6,    -1,   146,   325,
     266,   359,   267,     7,   372,     6,    -1,   146,   325,   266,
     359,   267,     7,   372,     4,   270,   371,   271,     6,    -1,
      -1,   145,   324,   323,   266,   318,   267,   298,   372,     6,
      -1,   105,    -1,   108,    -1,   111,    -1,   113,    -1,   124,
     270,   359,   271,    -1,   108,    -1,   111,    -1,   113,    -1,
     124,   270,   359,   271,    -1,   108,    -1,   111,    -1,   124,
     270,   359,   271,    -1,   105,    -1,   108,    -1,   111,    -1,
     124,   270,   359,   271,    -1,   155,   369,   270,   329,   271,
      -1,   154,   270,   369,   275,   369,   275,   359,   271,   270,
     329,   271,    -1,   156,   369,   270,   329,   271,    -1,   157,
     270,   369,   275,   359,   271,   270,   329,   271,    -1,   157,
     270,   369,   275,   369,   271,   270,   329,   271,    -1,   160,
     270,   376,   271,   270,   329,   271,    -1,   161,   270,   376,
     271,   270,   329,   271,    -1,     4,   270,   329,   271,    -1,
     174,   108,   270,   376,   271,   111,   270,   359,   271,    -1,
     170,   108,   270,   359,   271,   105,   270,   376,   271,     6,
      -1,   170,   108,   266,   359,   267,   270,   376,   271,     6,
      -1,   330,    -1,   328,    -1,    -1,   330,   322,    -1,   330,
     324,   270,   376,   271,     6,    -1,   330,   145,   324,   270,
     376,   271,     6,    -1,   330,   148,   324,   270,   376,   271,
       6,    -1,   330,   324,   270,     8,   271,     6,    -1,   330,
     145,   324,   270,     8,   271,     6,    -1,   159,   142,   266,
     359,   267,     7,   372,     6,    -1,   159,   105,   266,   359,
     267,     7,   270,   371,   271,     6,    -1,   159,   142,   266,
     359,   267,     7,   270,   369,   275,   369,   275,   376,   271,
       6,    -1,   159,   142,   266,   359,   267,     7,   270,   369,
     275,   369,   275,   369,   275,   376,   271,     6,    -1,   159,
     109,   266,   359,   267,     7,   270,   369,   275,   376,   271,
       6,    -1,   159,   115,   266,   359,   267,     7,   270,   369,
     275,   369,   275,   376,   271,     6,    -1,   159,   116,   266,
     359,   267,     7,   270,   369,   275,   369,   275,   376,   271,
       6,    -1,   159,   118,   266,   359,   267,     7,   270,   369,
     275,   369,   275,   376,   271,     6,    -1,   159,   119,   266,
     359,   267,     7,   270,   369,   275,   369,   275,   376,   271,
       6,    -1,   159,     4,   266,   359,   267,     7,   372,     6,
      -1,   159,     4,   266,   359,   267,     7,     5,     6,    -1,
     159,     4,   270,   359,   271,     6,    -1,   171,   270,   330,
     271,    -1,   152,   171,   270,   330,   271,    -1,   171,     4,
     270,   330,   271,    -1,   171,   210,   268,   359,   269,     6,
      -1,   171,     4,   268,   359,   269,     6,    -1,   171,   390,
       6,    -1,   171,     4,     4,     6,    -1,   171,    97,     6,
      -1,   199,   377,   270,   330,   271,    -1,   152,   199,   377,
     270,   330,   271,    -1,   235,   359,   270,   330,   271,    -1,
     215,   270,     8,   271,    -1,   215,     5,     6,    -1,   216,
     270,     8,   271,    -1,   216,     5,     6,    -1,   215,   270,
     330,   271,    -1,   152,   215,   270,   330,   271,    -1,   216,
     270,   330,   271,    -1,   152,   216,   270,   330,   271,    -1,
     390,   381,     6,    -1,    81,   266,   387,   267,     6,    -1,
     390,   390,   268,   359,   269,   380,     6,    -1,   390,   390,
     390,   268,   359,   269,     6,    -1,   390,   359,     6,    -1,
     238,     6,    -1,   150,   266,     4,   267,   272,     4,     6,
      -1,   193,     4,     6,    -1,   208,     6,    -1,   208,   359,
       6,    -1,   209,     6,    -1,    75,     6,    -1,    76,     6,
      -1,    68,     6,    -1,    68,   270,   359,   275,   359,   275,
     359,   275,   359,   275,   359,   275,   359,   271,     6,    -1,
      69,     6,    -1,    70,     6,    -1,    86,   270,   359,   275,
     359,   271,     6,    -1,    86,     6,    -1,    88,   270,   359,
     275,   359,   275,   359,   271,     6,    -1,    88,   270,   359,
     275,   359,   275,   359,   275,   359,   271,     6,    -1,    87,
       6,    -1,    87,   270,   330,   271,    -1,    89,     6,    -1,
      90,     6,    -1,    91,     6,    -1,    92,     6,    -1,   131,
       6,    -1,   132,     6,    -1,   133,   270,   376,   271,   270,
     376,   271,   270,   371,   271,   270,   359,   275,   359,   271,
       6,    -1,   134,   270,   376,   271,     6,    -1,   134,   270,
     376,   271,   270,   329,   271,     6,    -1,   213,   266,   270,
     376,   271,   275,   381,   275,   381,   267,     6,    -1,   201,
     266,   359,     8,   359,   267,    -1,   201,   266,   359,     8,
     359,     8,   359,   267,    -1,   201,     4,   202,   270,   359,
       8,   359,   271,    -1,   201,     4,   202,   270,   359,     8,
     359,     8,   359,   271,    -1,   203,    -1,   214,     4,    -1,
     214,   381,    -1,   211,    -1,   212,   390,     6,    -1,   212,
     381,     6,    -1,   204,   266,   359,   267,    -1,   205,   266,
     359,   267,    -1,   206,    -1,   207,    -1,   158,   369,   270,
     330,   271,    -1,   158,   270,   369,   275,   369,   275,   359,
     271,   270,   330,   271,    -1,   158,   270,   369,   275,   369,
     275,   369,   275,   359,   271,   270,   330,   271,    -1,    -1,
     158,   369,   270,   330,   340,   344,   271,    -1,    -1,   158,
     270,   369,   275,   369,   275,   359,   271,   270,   330,   341,
     344,   271,    -1,    -1,   158,   270,   369,   275,   369,   275,
     369,   275,   359,   271,   270,   330,   342,   344,   271,    -1,
      -1,   158,   270,   330,   343,   344,   271,    -1,   158,   270,
     330,   271,   149,   123,   270,   359,   271,    -1,   138,   372,
      -1,   143,   138,   372,    -1,   140,   270,   376,   271,   270,
     376,   271,   270,   376,   271,    -1,   141,   270,   376,   271,
     270,   376,   271,   270,   376,   271,   270,   376,   271,    -1,
     345,    -1,   344,   345,    -1,   179,   270,   359,   271,     6,
      -1,   179,   270,   372,   275,   372,   271,     6,    -1,   180,
       6,    -1,   168,     6,    -1,   168,   359,     6,    -1,   185,
       6,    -1,   185,   187,     6,    -1,   186,     6,    -1,   186,
     187,     6,    -1,   181,   266,   359,   267,     7,   372,   149,
     359,     6,    -1,   149,     4,   268,   359,   269,     6,    -1,
     162,    -1,   163,    -1,   164,    -1,   165,    -1,   166,    -1,
      -1,   171,     6,    -1,   152,   171,     6,    -1,   171,   359,
       6,    -1,   152,   171,   359,     6,    -1,   346,   270,   330,
     347,   271,   270,   330,   347,   271,    -1,   120,   266,   380,
     267,    -1,   346,   266,   359,   267,     7,   270,   330,   347,
     271,   270,   330,   347,   271,     6,    -1,    -1,   149,     4,
     359,    -1,    -1,     4,    -1,    -1,     7,   372,    -1,    -1,
       7,   359,    -1,    -1,   160,   372,    -1,   177,   374,     7,
     359,     6,    -1,   127,   128,   374,     7,   359,     6,    -1,
     144,   108,   374,     7,   359,   350,     6,    -1,   144,   111,
     374,   352,   351,     6,    -1,   144,   113,   374,   352,     6,
      -1,   188,   374,     6,    -1,   103,   324,   266,   359,   275,
     359,   267,     6,    -1,   223,   324,   266,   359,   267,     6,
      -1,   175,   111,   270,   376,   271,     7,   359,     6,    -1,
     178,   111,   270,   376,   271,     7,   359,     6,    -1,   168,
     111,   374,   353,     6,    -1,   168,   113,   374,     6,    -1,
     169,   111,   374,     7,   359,     6,    -1,   147,   108,   270,
     376,   271,     7,   270,   376,   271,   354,     6,    -1,   147,
     111,   270,   376,   271,     7,   270,   376,   271,   354,     6,
      -1,   147,   108,   270,   376,   271,     7,   270,   376,   271,
     154,   270,   369,   275,   369,   275,   359,   271,     6,    -1,
     147,   111,   270,   376,   271,     7,   270,   376,   271,   154,
     270,   369,   275,   369,   275,   359,   271,     6,    -1,   147,
     108,   270,   376,   271,     7,   270,   376,   271,   155,   369,
       6,    -1,   147,   111,   270,   376,   271,     7,   270,   376,
     271,   155,   369,     6,    -1,   147,   111,   359,   270,   376,
     271,     7,   359,   270,   376,   271,     6,    -1,   324,   270,
     376,   271,   202,   324,   270,   359,   271,     6,    -1,   176,
     326,   374,     6,    -1,   135,   327,   374,     6,    -1,   136,
     113,   372,     6,    -1,   151,   108,   372,     6,    -1,   146,
     325,   372,     6,    -1,   146,   325,   372,   175,   359,     6,
      -1,   172,     6,    -1,   172,     4,     6,    -1,   172,   105,
     270,   376,   271,     6,    -1,   173,     6,    -1,   224,    -1,
     225,    -1,   226,    -1,   357,     6,    -1,   357,   270,   372,
     271,     6,    -1,   357,   270,   372,   275,   372,   271,     6,
      -1,   357,   266,   372,   267,   270,   372,   275,   372,   271,
       6,    -1,   360,    -1,   266,   359,   267,    -1,   255,   359,
      -1,   254,   359,    -1,   261,   359,    -1,   359,   255,   359,
      -1,   359,   254,   359,    -1,   359,   256,   359,    -1,   359,
     257,   359,    -1,   359,   259,   359,    -1,   359,   260,   359,
      -1,   359,   258,   359,    -1,   359,   265,   359,    -1,   359,
     248,   359,    -1,   359,   249,   359,    -1,   359,   253,   359,
      -1,   359,   252,   359,    -1,   359,   247,   359,    -1,   359,
     246,   359,    -1,   359,   245,   359,    -1,   359,   244,   359,
      -1,   359,   250,   359,    -1,   359,   251,   359,    -1,   359,
     243,   359,     8,   359,    -1,    26,   300,   359,   301,    -1,
      16,   300,   359,   301,    -1,    17,   300,   359,   301,    -1,
      18,   300,   359,   301,    -1,    19,   300,   359,   301,    -1,
      20,   300,   359,   301,    -1,    21,   300,   359,   301,    -1,
      22,   300,   359,   301,    -1,    23,   300,   359,   301,    -1,
      24,   300,   359,   301,    -1,    27,   300,   359,   301,    -1,
      28,   300,   359,   275,   359,   301,    -1,    29,   300,   359,
     301,    -1,    30,   300,   359,   301,    -1,    31,   300,   359,
     301,    -1,    32,   300,   359,   301,    -1,    33,   300,   359,
     301,    -1,    34,   300,   359,   301,    -1,    35,   300,   359,
     301,    -1,    36,   300,   359,   301,    -1,    39,   300,   359,
     275,   359,   301,    -1,    40,   300,   359,   275,   359,   301,
      -1,    41,   300,   359,   275,   359,   301,    -1,    25,   300,
     359,   301,    -1,    38,   300,   359,   275,   359,   301,    -1,
      37,   300,   359,   275,   359,   301,    -1,     3,    -1,    10,
      -1,    15,    -1,    11,    -1,    12,    -1,   231,    -1,   232,
      -1,   233,    -1,    83,    -1,    84,    -1,    85,    -1,    -1,
      96,   300,   359,   361,   311,   301,    -1,   364,    -1,   221,
     300,   380,   301,    -1,   221,   300,   380,   275,   359,   301,
      -1,   366,    -1,   390,   268,   359,   269,    -1,   390,   266,
     359,   267,    -1,   227,   266,   366,   267,    -1,   227,   266,
     366,   272,   302,   267,    -1,   229,   266,   366,   362,   267,
      -1,   229,   266,   366,   272,   302,   362,   267,    -1,   229,
     266,   366,   300,   359,   301,   362,   267,    -1,   229,   266,
     366,   272,   302,   300,   359,   301,   362,   267,    -1,   228,
     266,   381,   267,    -1,   273,   390,   300,   301,    -1,   273,
     366,   272,   302,   300,   301,    -1,    99,   300,   390,   301,
      -1,    99,   300,   301,    -1,   390,   299,    -1,   390,   268,
     359,   269,   299,    -1,   390,   266,   359,   267,   299,    -1,
     390,   272,   302,    -1,   390,     9,   390,   272,   302,    -1,
     390,   272,   302,   266,   359,   267,    -1,   390,     9,   390,
     272,   302,   266,   359,   267,    -1,   390,   272,   302,   268,
     359,   269,    -1,   390,     9,   390,   272,   302,   268,   359,
     269,    -1,   390,   268,   359,   269,   272,   302,    -1,   390,
     272,   302,   299,    -1,   390,   268,   359,   269,   272,   302,
     299,    -1,   217,   266,   380,   275,   359,   267,    -1,    60,
     266,   372,   275,   372,   267,    -1,    61,   300,   380,   275,
     380,   301,    -1,    59,   300,   380,   301,    -1,    62,   300,
     380,   275,   380,   301,    -1,    67,   266,   387,   267,    -1,
      -1,   275,   359,    -1,    -1,   275,   380,    -1,    -1,    97,
     366,   368,   365,   268,   312,   269,    -1,   390,    -1,   390,
       9,   390,    -1,   100,    -1,   100,   359,    -1,    -1,   266,
     367,   267,    -1,   370,    -1,   255,   369,    -1,   254,   369,
      -1,   369,   255,   369,    -1,   369,   254,   369,    -1,   270,
     359,   275,   359,   275,   359,   275,   359,   275,   359,   271,
      -1,   270,   359,   275,   359,   275,   359,   275,   359,   271,
      -1,   270,   359,   275,   359,   275,   359,   271,    -1,   266,
     359,   275,   359,   275,   359,   267,    -1,   372,    -1,   371,
     275,   372,    -1,   359,    -1,   375,    -1,   270,   271,    -1,
     270,   376,   271,    -1,   255,   270,   376,   271,    -1,   359,
     256,   270,   376,   271,    -1,   270,   271,    -1,   270,   376,
     271,    -1,   255,   270,   376,   271,    -1,   372,    -1,   270,
       8,   271,    -1,     5,    -1,   255,   375,    -1,   359,   256,
     375,    -1,   359,     8,   359,    -1,   359,     8,   359,     8,
     359,    -1,   105,   270,   359,   271,    -1,   105,   270,     8,
     271,    -1,   105,     5,    -1,   325,   270,     8,   271,    -1,
     325,     5,    -1,   145,   324,   374,    -1,   148,   324,   372,
      -1,   324,   202,    68,   372,    -1,    68,   324,   270,   376,
     271,    -1,    77,   325,   270,   359,   271,    -1,    78,   325,
     270,   359,   271,    -1,    79,   325,   270,   359,   271,    -1,
     129,    68,   326,   270,   359,   271,    -1,   125,   111,   270,
     359,   271,   129,   270,   359,   275,   359,   271,    -1,   126,
     111,   270,   359,   271,   129,   270,   359,   275,   359,   271,
      -1,   126,   108,   270,   359,   271,   129,   270,   359,   271,
      -1,   129,   105,   270,   359,   271,   202,   111,   270,   359,
     271,    -1,   199,   325,   270,   359,   271,    -1,   328,    -1,
     339,    -1,   348,    -1,   390,   300,   301,    -1,   390,   272,
     302,   300,   301,    -1,   390,     9,   390,   272,   302,   300,
     301,    -1,    42,   268,   390,   269,    -1,    42,   268,   375,
     269,    -1,    42,   266,   375,   267,    -1,    42,   300,   270,
     376,   271,   301,    -1,   390,   300,   270,   376,   271,   301,
      -1,    43,   300,   359,   275,   359,   275,   359,   301,    -1,
      44,   300,   359,   275,   359,   275,   359,   301,    -1,    45,
     300,   380,   301,    -1,    46,   300,   359,   275,   359,   275,
     359,   275,   359,   275,   359,   275,   359,   301,    -1,   222,
     300,   375,   301,    -1,    33,   300,   375,   301,    -1,   359,
      -1,   375,    -1,   376,   275,   359,    -1,   376,   275,   375,
      -1,   270,   359,   275,   359,   275,   359,   275,   359,   271,
      -1,   270,   359,   275,   359,   275,   359,   271,    -1,   390,
      -1,     4,   272,   199,   272,     4,    -1,   270,   379,   271,
      -1,   390,   268,   359,   269,   272,   200,    -1,   377,    -1,
     379,   275,   377,    -1,   381,    -1,   390,    -1,   390,   268,
     359,   269,    -1,   390,   266,   359,   267,    -1,   390,   272,
     302,    -1,   390,     9,   390,   272,   302,    -1,   390,   272,
     302,   266,   359,   267,    -1,   390,     9,   390,   272,   302,
     266,   359,   267,    -1,   390,   268,   359,   269,   272,     4,
      -1,   324,   270,   359,   271,    -1,   145,   324,   270,   359,
     271,    -1,     5,    -1,   236,   268,   390,   269,    -1,    71,
      -1,   234,    -1,    80,    -1,    82,    -1,   219,   266,   380,
     267,    -1,   218,   266,   380,   275,   380,   267,    -1,   220,
     300,   380,   301,    -1,   220,   300,   380,   275,   380,   301,
      -1,   230,   266,   366,   363,   267,    -1,   230,   266,   366,
     272,   302,   363,   267,    -1,    52,   300,   387,   301,    -1,
      53,   266,   380,   267,    -1,    54,   266,   380,   267,    -1,
      55,   266,   380,   275,   380,   275,   380,   267,    -1,    50,
     300,   387,   301,    -1,    64,   300,   380,   301,    -1,    65,
     300,   380,   301,    -1,    66,   300,   380,   301,    -1,    63,
     300,   359,   275,   380,   275,   380,   301,    -1,    58,   300,
     380,   275,   359,   275,   359,   301,    -1,    58,   300,   380,
     275,   359,   301,    -1,    51,   300,   380,   301,    -1,    51,
     300,   380,   275,   376,   301,    -1,    72,   300,   380,   301,
      -1,    73,    -1,    74,    -1,    57,   300,   380,   301,    -1,
      56,   300,   380,   301,    -1,    -1,   101,   300,   381,   382,
     315,   301,    -1,    98,   300,   383,   301,    -1,   273,   359,
      -1,   390,     9,   273,   359,    -1,    50,   300,   386,   301,
      -1,   387,    -1,   386,    -1,   270,   387,   271,    -1,   380,
      -1,   388,    -1,   387,   275,   380,    -1,   387,   275,   388,
      -1,   390,   266,   267,    -1,   390,   272,   302,   266,   267,
      -1,   390,     9,   390,   272,   302,   266,   267,    -1,     4,
     274,   270,   359,   271,    -1,   389,   274,   270,   359,   271,
      -1,   237,   268,   380,   269,   274,   270,   359,   271,    -1,
       4,    -1,   389,    -1,   237,   268,   380,   269,    -1
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
    3734,  3738,  3750,  3759,  3818,  3838,  3864,  3880,  3897,  3914,
    3936,  3958,  3993,  4001,  4009,  4015,  4022,  4029,  4049,  4075,
    4087,  4098,  4116,  4134,  4153,  4152,  4177,  4176,  4203,  4202,
    4227,  4226,  4249,  4265,  4282,  4299,  4322,  4350,  4353,  4359,
    4371,  4391,  4395,  4399,  4403,  4407,  4411,  4415,  4419,  4428,
    4441,  4442,  4443,  4444,  4445,  4449,  4450,  4451,  4452,  4453,
    4456,  4480,  4499,  4522,  4525,  4553,  4556,  4573,  4576,  4582,
    4585,  4592,  4595,  4602,  4625,  4644,  4685,  4730,  4770,  4795,
    4802,  4813,  4830,  4847,  4877,  4903,  4929,  4961,  4989,  5015,
    5041,  5067,  5093,  5115,  5127,  5175,  5229,  5244,  5256,  5262,
    5274,  5281,  5296,  5305,  5326,  5327,  5328,  5332,  5338,  5350,
    5368,  5396,  5397,  5398,  5399,  5400,  5401,  5402,  5403,  5404,
    5411,  5412,  5413,  5414,  5415,  5416,  5417,  5418,  5419,  5420,
    5421,  5422,  5423,  5424,  5425,  5426,  5427,  5428,  5429,  5430,
    5431,  5432,  5433,  5434,  5435,  5436,  5437,  5438,  5439,  5440,
    5441,  5442,  5443,  5444,  5445,  5446,  5447,  5448,  5449,  5450,
    5451,  5460,  5461,  5462,  5463,  5464,  5465,  5466,  5467,  5468,
    5469,  5470,  5475,  5474,  5482,  5486,  5491,  5496,  5500,  5505,
    5510,  5514,  5518,  5522,  5526,  5530,  5534,  5540,  5555,  5559,
    5565,  5570,  5589,  5609,  5630,  5634,  5638,  5642,  5646,  5650,
    5654,  5659,  5669,  5679,  5684,  5695,  5704,  5709,  5714,  5742,
    5743,  5749,  5750,  5756,  5755,  5778,  5780,  5785,  5787,  5793,
    5794,  5799,  5803,  5807,  5811,  5815,  5822,  5826,  5830,  5834,
    5841,  5846,  5853,  5858,  5862,  5866,  5870,  5878,  5889,  5893,
    5897,  5908,  5912,  5916,  5930,  5938,  5946,  5953,  5963,  5986,
    5991,  5997,  6002,  6008,  6019,  6025,  6039,  6045,  6057,  6071,
    6084,  6114,  6137,  6157,  6176,  6196,  6213,  6223,  6233,  6243,
    6255,  6259,  6264,  6276,  6280,  6284,  6288,  6306,  6314,  6322,
    6351,  6361,  6377,  6388,  6393,  6397,  6401,  6413,  6417,  6429,
    6446,  6456,  6460,  6475,  6480,  6487,  6491,  6496,  6510,  6524,
    6528,  6532,  6536,  6540,  6548,  6554,  6563,  6567,  6571,  6579,
    6585,  6591,  6595,  6602,  6610,  6617,  6626,  6630,  6634,  6649,
    6663,  6677,  6689,  6705,  6714,  6723,  6733,  6744,  6752,  6760,
    6764,  6782,  6789,  6795,  6801,  6808,  6816,  6815,  6825,  6849,
    6851,  6857,  6862,  6864,  6869,  6874,  6879,  6881,  6885,  6897,
    6911,  6915,  6922,  6930,  6938,  6949,  6951,  6954
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
  "tTranslate", "tSymmetry", "tDilate", "tExtrude", "tLevelset", "tAffine",
  "tClosest", "tBooleanUnion", "tBooleanIntersection",
  "tBooleanDifference", "tBooleanSection", "tBooleanFragments",
  "tThickSolid", "tRecombine", "tSmoother", "tSplit", "tDelete",
  "tCoherence", "tHealShapes", "tIntersect", "tMeshAlgorithm",
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
     279,   279,   279,   279,   279,   279,   280,   280,   281,   281,
     281,   281,   281,   281,   281,   281,   282,   282,   282,   282,
     283,   283,   283,   283,   283,   283,   283,   284,   284,   285,
     285,   287,   288,   286,   289,   289,   291,   290,   292,   292,
     294,   293,   295,   295,   297,   296,   298,   298,   298,   298,
     298,   299,   299,   300,   300,   301,   301,   302,   302,   302,
     302,   302,   302,   303,   303,   303,   303,   303,   303,   303,
     303,   303,   303,   303,   303,   303,   303,   303,   303,   303,
     303,   303,   303,   303,   303,   303,   303,   303,   303,   303,
     303,   303,   303,   303,   303,   303,   303,   303,   304,   304,
     305,   305,   305,   306,   305,   307,   305,   305,   308,   305,
     309,   309,   310,   310,   310,   311,   311,   312,   312,   313,
     313,   314,   314,   314,   314,   314,   314,   314,   314,   315,
     315,   316,   316,   317,   317,   317,   317,   317,   318,   318,
     318,   319,   319,   319,   319,   320,   320,   321,   321,   322,
     322,   322,   322,   322,   322,   322,   322,   322,   322,   322,
     322,   322,   322,   322,   322,   322,   322,   322,   322,   322,
     322,   322,   322,   322,   322,   322,   322,   322,   322,   322,
     322,   322,   322,   322,   322,   323,   322,   324,   324,   324,
     324,   324,   325,   325,   325,   325,   326,   326,   326,   327,
     327,   327,   327,   328,   328,   328,   328,   328,   328,   328,
     328,   328,   328,   328,   329,   329,   330,   330,   330,   330,
     330,   330,   330,   331,   331,   331,   331,   331,   331,   331,
     331,   331,   331,   331,   331,   332,   332,   332,   332,   332,
     332,   332,   332,   333,   333,   334,   335,   335,   335,   335,
     335,   335,   335,   335,   336,   336,   336,   336,   336,   336,
     336,   336,   336,   336,   336,   336,   336,   336,   336,   336,
     336,   336,   336,   336,   336,   336,   336,   336,   336,   336,
     336,   336,   336,   336,   336,   336,   337,   338,   338,   338,
     338,   338,   338,   338,   338,   338,   338,   338,   338,   338,
     338,   339,   339,   339,   340,   339,   341,   339,   342,   339,
     343,   339,   339,   339,   339,   339,   339,   344,   344,   345,
     345,   345,   345,   345,   345,   345,   345,   345,   345,   345,
     346,   346,   346,   346,   346,   347,   347,   347,   347,   347,
     348,   348,   349,   350,   350,   351,   351,   352,   352,   353,
     353,   354,   354,   355,   355,   355,   355,   355,   355,   355,
     355,   355,   355,   355,   355,   355,   355,   355,   355,   355,
     355,   355,   355,   355,   355,   355,   355,   355,   355,   355,
     356,   356,   356,   356,   357,   357,   357,   358,   358,   358,
     358,   359,   359,   359,   359,   359,   359,   359,   359,   359,
     359,   359,   359,   359,   359,   359,   359,   359,   359,   359,
     359,   359,   359,   359,   359,   359,   359,   359,   359,   359,
     359,   359,   359,   359,   359,   359,   359,   359,   359,   359,
     359,   359,   359,   359,   359,   359,   359,   359,   359,   359,
     359,   360,   360,   360,   360,   360,   360,   360,   360,   360,
     360,   360,   361,   360,   360,   360,   360,   360,   360,   360,
     360,   360,   360,   360,   360,   360,   360,   360,   360,   360,
     360,   360,   360,   360,   360,   360,   360,   360,   360,   360,
     360,   360,   360,   360,   360,   360,   360,   360,   360,   362,
     362,   363,   363,   365,   364,   366,   366,   367,   367,   368,
     368,   369,   369,   369,   369,   369,   370,   370,   370,   370,
     371,   371,   372,   372,   372,   372,   372,   372,   373,   373,
     373,   374,   374,   374,   375,   375,   375,   375,   375,   375,
     375,   375,   375,   375,   375,   375,   375,   375,   375,   375,
     375,   375,   375,   375,   375,   375,   375,   375,   375,   375,
     375,   375,   375,   375,   375,   375,   375,   375,   375,   375,
     375,   375,   375,   376,   376,   376,   376,   377,   377,   377,
     377,   378,   378,   379,   379,   380,   380,   380,   380,   380,
     380,   380,   380,   380,   380,   380,   381,   381,   381,   381,
     381,   381,   381,   381,   381,   381,   381,   381,   381,   381,
     381,   381,   381,   381,   381,   381,   381,   381,   381,   381,
     381,   381,   381,   381,   381,   381,   382,   381,   381,   383,
     383,   384,   385,   385,   386,   387,   387,   387,   387,   388,
     388,   388,   389,   389,   389,   390,   390,   390
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
       2,     2,     2,    16,     5,     8,    11,     6,     8,     8,
      10,     1,     2,     2,     1,     3,     3,     4,     4,     1,
       1,     5,    11,    13,     0,     7,     0,    13,     0,    15,
       0,     6,     9,     2,     3,    10,    13,     1,     2,     5,
       7,     2,     2,     3,     2,     3,     2,     3,     9,     6,
       1,     1,     1,     1,     1,     0,     2,     3,     3,     4,
       9,     4,    14,     0,     3,     0,     1,     0,     2,     0,
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
       2,     4,     2,     3,     3,     4,     5,     5,     5,     5,
       6,    11,    11,     9,    10,     5,     1,     1,     1,     3,
       5,     7,     4,     4,     4,     6,     6,     8,     8,     4,
      14,     4,     4,     1,     1,     3,     3,     9,     7,     1,
       5,     3,     6,     1,     3,     1,     1,     4,     4,     3,
       5,     6,     8,     6,     4,     5,     1,     4,     1,     1,
       1,     1,     4,     6,     4,     6,     5,     7,     4,     4,
       4,     8,     4,     4,     4,     4,     8,     8,     6,     4,
       6,     4,     1,     1,     4,     4,     0,     6,     4,     2,
       4,     4,     1,     1,     3,     1,     1,     3,     3,     3,
       5,     7,     5,     5,     8,     1,     1,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     2,     3,     1,   655,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   207,     0,     0,   208,     0,     0,   209,     0,   210,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   350,
     351,   352,   353,   354,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   311,     0,     0,   319,
     320,     0,     0,     0,   314,     0,     0,     0,     0,     0,
       0,   404,   405,   406,     0,     0,     0,     5,     6,     7,
       8,    10,     0,    11,    24,    12,    13,    14,    15,    23,
      22,    21,    16,     0,    17,    18,    19,    20,     0,    25,
       0,   656,     0,   236,     0,     0,     0,     0,     0,     0,
     287,     0,   289,   290,   285,   286,     0,   292,     0,   295,
     236,     0,   297,   298,   299,   300,   120,   130,   655,   519,
     515,    73,    74,     0,   207,   208,   209,   210,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   301,   302,     0,     0,   219,   220,   221,     0,
       0,     0,     0,   461,   462,   464,   465,   463,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   469,   470,
     471,     0,     0,   207,   212,   213,   214,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   466,   467,   468,     0,     0,     0,     0,     0,
       0,     0,     0,   566,   567,     0,   568,   532,   411,   474,
     477,   333,   533,   515,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   205,   212,   213,     0,   214,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   521,     0,     0,   236,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   655,     0,     0,   236,     0,
       0,   400,     0,   403,     0,     0,   216,   217,     0,     0,
     543,     0,     0,   541,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   655,     0,     0,   589,
       0,     0,     0,     0,   282,     0,     0,     0,   515,   284,
       0,   606,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   608,     0,   632,   633,   610,
     611,     0,     0,     0,     0,     0,     0,   609,     0,     0,
       0,     0,   312,   313,     0,   236,     0,   236,     0,     0,
       0,   279,     0,     0,   236,   407,     0,     0,    85,     0,
      66,     0,     0,    70,    69,    68,    67,    72,    71,    73,
      74,     0,     0,     0,     0,     0,     0,     0,   595,   515,
       0,   235,     0,   234,     0,   186,     0,     0,   595,   596,
       0,     0,     0,   645,     0,   646,   596,     0,     0,     0,
     118,   118,     0,   513,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   583,   584,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    73,    74,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   550,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   414,     0,   413,   544,   415,     0,   534,     0,     0,
     515,     0,   552,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    73,    74,     0,   491,     0,
       0,     0,     0,     0,     0,     0,   334,     0,   367,   367,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   236,     0,   236,   236,     0,   523,   522,     0,     0,
       0,     0,   236,   236,     0,     0,     0,     0,   330,     0,
     236,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   369,     0,     0,     0,     0,     0,     0,
     236,   262,     0,     0,   260,   401,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   378,   281,
       0,     0,     0,     0,     0,     0,     0,   236,     0,     0,
       0,     0,     0,   413,   283,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   316,   315,     0,   267,     0,     0,   269,     0,
       0,     0,   236,     0,     0,     0,   355,     0,     0,     0,
       0,     0,     0,     0,     0,    77,    80,    78,    79,    81,
      82,     0,     0,     0,     0,    89,    75,    76,     0,     0,
       0,   278,    40,   274,     0,     0,     0,     0,     0,   230,
       0,     0,     0,     0,     0,   237,     0,     0,   187,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   296,     0,     0,   119,
       0,     0,     0,   517,     0,     0,   516,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   361,     0,     0,     0,   211,
       0,     0,     0,     0,     0,     0,     0,   395,   396,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     515,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   472,   490,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   553,   554,     0,     0,
       0,     0,     0,     0,   509,     0,   412,   535,     0,     0,
       0,     0,   546,     0,   431,   430,   429,   428,   424,   425,
     432,   433,   427,   426,   417,   416,     0,   418,   545,   419,
     422,   420,   421,   423,   516,     0,     0,   494,     0,   569,
       0,     0,     0,     0,     0,     0,     0,     0,   365,     0,
       0,     0,     0,     0,     0,   398,     0,     0,     0,     0,
       0,   397,     0,   236,     0,     0,     0,     0,     0,   525,
     524,     0,     0,     0,     0,     0,     0,     0,   324,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   384,     0,     0,     0,   261,     0,     0,
       0,   255,     0,     0,     0,     0,   394,   412,   542,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   317,   318,     0,   418,   516,   494,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   636,     0,
       0,     0,   511,     0,     0,   266,   270,   268,   272,     0,
       0,   657,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    96,     0,     0,   412,     0,     0,     0,    66,     0,
       0,    88,     0,    66,    67,     0,     0,     0,   516,     0,
       0,   494,     0,     0,     0,   205,     0,     0,     0,   652,
      28,    26,    27,     0,     0,     0,     0,     0,   599,    30,
       0,    29,     0,     0,   275,   647,   648,     0,   649,   599,
       0,     0,    83,   121,    84,   131,   518,   520,   137,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   585,   586,   304,   236,   222,     9,   436,
     437,   438,   439,   440,   441,   442,   443,   444,   458,   435,
     445,     0,   447,   448,   449,   450,   451,   582,   452,   453,
     454,     0,     0,     0,     0,     0,   574,   573,   572,     0,
       0,     0,   579,     0,   506,     0,     0,     0,   508,     0,
       0,     0,     0,   135,   489,   549,   548,   215,     0,     0,
       0,     0,     0,     0,     0,     0,   475,   581,   480,     0,
     486,     0,     0,     0,     0,   536,     0,     0,   487,   555,
     551,     0,     0,     0,     0,   479,   478,    73,    74,   501,
       0,     0,     0,     0,     0,     0,     0,   412,   363,   368,
     366,     0,   377,     0,   158,   159,     0,   215,     0,   412,
       0,     0,     0,     0,     0,   256,     0,   271,   273,     0,
       0,     0,   223,   225,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   337,     0,   321,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   236,   236,
       0,   370,   383,     0,     0,     0,     0,   257,     0,     0,
       0,     0,   218,   373,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   263,     0,     0,     0,     0,
       0,     0,     0,   622,     0,   629,   618,   619,   620,     0,
     635,   634,     0,     0,   623,   624,   625,   631,   639,   638,
       0,   149,     0,   612,     0,   614,     0,     0,     0,   607,
       0,     0,   265,     0,     0,     0,     0,   356,     0,     0,
       0,   408,     0,   653,     0,   110,    66,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   104,     0,
       0,     0,     0,   604,    51,     0,     0,     0,    64,     0,
      41,    42,    43,    44,    45,    46,     0,   479,   478,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   598,   597,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   145,     0,     0,     0,     0,   138,   139,
       0,     0,     0,     0,   165,   165,     0,     0,     0,     0,
       0,   161,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   374,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   556,   557,
     558,   559,     0,     0,     0,     0,     0,     0,     0,   565,
       0,     0,     0,   509,   510,     0,   482,     0,     0,   547,
     434,   537,   495,   493,     0,   492,     0,     0,   570,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   376,     0,
       0,     0,     0,     0,   399,     0,     0,     0,    77,     0,
     264,     0,     0,     0,     0,     0,     0,     0,   342,     0,
       0,   341,     0,   344,     0,   346,     0,   331,   338,     0,
       0,     0,   254,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   385,     0,     0,   259,   258,   402,     0,
       0,     0,    37,    38,     0,     0,     0,     0,     0,     0,
     590,     0,     0,     0,   307,   495,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   511,   512,   616,
       0,   380,     0,     0,   236,   357,     0,   358,   236,     0,
       0,   605,     0,    95,     0,     0,     0,     0,    93,     0,
     593,     0,   108,     0,   100,   102,     0,     0,     0,    90,
       0,     0,     0,     0,     0,    36,   495,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    31,
      32,     0,   600,     0,     0,    34,    33,     0,   600,   650,
     291,     0,     0,   122,   127,     0,     0,     0,   141,   147,
     148,   144,   142,   143,   514,     0,    86,     0,    87,   169,
       0,     0,     0,     0,   170,   189,   190,   167,     0,     0,
       0,   171,   200,   191,   195,   196,   192,   193,   194,   179,
       0,     0,     0,   446,   460,   459,   455,   456,   457,   575,
       0,     0,     0,   504,   505,   507,   136,   473,     0,     0,
       0,   560,     0,   503,   476,   481,     0,     0,   509,   201,
     488,    73,    74,     0,   500,   496,   498,   576,   197,     0,
       0,     0,   161,     0,     0,   375,     0,   160,     0,     0,
       0,     0,     0,     0,   280,     0,     0,     0,     0,   236,
     236,     0,     0,   343,   532,     0,     0,   345,   347,     0,
       0,   325,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   228,   229,   198,     0,     0,     0,     0,     0,
       0,     0,   176,     0,   177,     0,     0,     0,     0,     0,
       0,   111,   115,     0,   630,     0,     0,   628,     0,   640,
       0,     0,   150,   151,   637,   613,   615,     0,     0,     0,
       0,   355,   359,   355,     0,   409,    94,     0,     0,    66,
       0,     0,    92,     0,   591,     0,     0,     0,     0,     0,
       0,   643,   642,     0,     0,     0,     0,     0,   530,     0,
       0,    77,   276,   496,   277,     0,     0,     0,     0,     0,
     241,   238,     0,     0,   603,   601,     0,     0,     0,     0,
     123,   128,     0,     0,     0,   583,   584,   140,   379,   166,
     174,   175,   180,     0,     0,     0,     0,     0,   182,     0,
       0,   305,     0,     0,     0,     0,     0,     0,     0,     0,
     483,     0,     0,     0,   571,   502,     0,     0,   181,     0,
     202,   364,     0,     0,     0,     0,   203,     0,     0,     0,
       0,     0,     0,   529,   528,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   253,   252,     0,     0,     0,
       0,     0,     0,     0,     0,   243,     0,     0,     0,   381,
     382,    39,   184,   185,     0,   588,     0,     0,   309,   308,
       0,     0,     0,     0,     0,     0,     0,     0,   153,   154,
     157,   156,   155,     0,   617,     0,   654,     0,     0,     0,
       0,     0,     0,     0,     0,   105,   106,   594,     0,     0,
       0,    97,     0,     0,     0,    47,     0,     0,     0,     0,
       0,    49,     0,   242,   239,   240,    35,     0,     0,   651,
     293,     0,   135,   149,     0,     0,   146,     0,     0,     0,
     168,   199,     0,     0,     0,     0,     0,   577,   578,     0,
       0,     0,     0,     0,   509,   484,   497,   499,     0,     0,
     183,   206,     0,     0,     0,   371,   371,     0,   116,   117,
     236,     0,   226,   227,   332,     0,   339,     0,     0,   236,
       0,     0,     0,     0,     0,     0,     0,     0,   233,     0,
     231,     0,     0,     0,     0,   538,     0,   112,   114,   113,
     621,   627,   626,   152,     0,     0,     0,   360,     0,     0,
     109,   101,   103,     0,    91,   644,    98,    99,    52,     0,
       0,     0,     0,   531,     0,     0,   497,   602,     0,     0,
       0,     0,   125,   641,     0,   132,     0,     0,     0,     0,
     188,     0,     0,     0,   563,     0,     0,     0,   335,     0,
     172,   173,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   527,     0,   349,     0,     0,   326,     0,   244,
       0,     0,     0,     0,     0,     0,   232,     0,   587,   310,
       0,   539,     0,   393,   236,   410,     0,   592,     0,    48,
       0,     0,     0,    65,    50,     0,   294,   124,   129,   135,
       0,     0,   163,   164,   162,     0,     0,     0,     0,   564,
     485,     0,     0,     0,     0,   372,   386,     0,     0,   387,
       0,   224,     0,   340,     0,   322,     0,   236,     0,     0,
       0,     0,     0,     0,   178,   540,   306,   355,   107,     0,
       0,     0,     0,     0,     0,   133,   134,     0,     0,   561,
     562,     0,   204,     0,   390,     0,   391,   392,   526,     0,
       0,   328,   247,     0,     0,     0,     0,     0,     0,     0,
       0,    56,     0,    62,     0,     0,   126,     0,     0,   336,
       0,     0,   348,   327,   323,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   248,   249,   250,   251,     0,   245,   362,
      53,     0,    60,     0,   288,     0,   580,     0,     0,   329,
       0,     0,    54,     0,     0,   303,     0,     0,   246,     0,
       0,     0,     0,     0,     0,    57,    55,     0,    58,     0,
     388,   389,     0,     0,    63,    61,    59
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,   127,  1143,   128,   129,  1127,  2034,  2040,
    1440,  1670,  2208,  2341,  1441,  2314,  2357,  1442,  2343,  1443,
    1444,  1674,   472,   638,   639,  1216,  1774,   130,   840,   500,
    2052,  2219,  2053,   501,  1914,  1523,  1477,  1478,  1479,  1634,
    1852,  1853,  1293,  1730,  1721,  1924,   815,   650,   301,   302,
     379,   220,   303,   482,   483,   134,   135,   136,   137,   138,
     139,   140,   141,   304,  1328,  2246,  2305,  1016,  1324,  1325,
     305,  1106,   306,   145,  1557,  1291,   988,  1032,  2176,   146,
     147,   148,   149,   307,   308,  1243,  1264,  1398,   309,   845,
     310,   844,   503,   667,   345,  1887,   383,  2003,   384,   312,
     608,   398,  1424,  1661,   493,   488,  1391,  1086,  1710,  1880,
    1881,  1071,   495,   151,   408
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -2025
static const yytype_int16 yypact[] =
{
   14126,    67,    50, 14340, -2025, -2025,  -155,    24,   -48,  -174,
    -138,  -121,    11,   144,   167,   177,   199,  -104,    25,    28,
     -60,   238,   248,   268,   278,   -31,    86,    23,  -188,   697,
    -188,    77,   137,   166,    73,   173,   185,    75,   254,   269,
     275,   282,   288,   308,   368,   386,   392,   397,   225,   582,
     557,   747,   763,   413,   477,    61,   701,   530,  7326,   565,
     570,   597,   774,   -69,   497,   697,   -13,    27,   644,   809,
    -109,   652,   -39,   -39,   653,   436,    71,   655,   661, -2025,
   -2025, -2025, -2025, -2025,   670,   219,   823,   869,    29,    54,
     939,   877,   842,   156,  6259,   865,   983,   991,   999,  6259,
    1000,   -82,   -74,   745,    15,    83, -2025,   764,   766, -2025,
   -2025, 11464,  1011,   797, -2025, 14597,   800, 14660,    36,    38,
     697, -2025, -2025, -2025, 13140,   820,  1062, -2025, -2025, -2025,
   -2025, -2025,   819, -2025, -2025, -2025, -2025, -2025, -2025, -2025,
   -2025, -2025, -2025,   240, -2025, -2025, -2025, -2025,    59, -2025,
    1085,   844,  5974,   490,   858,  1123, 13140, 14533, 14533, 14533,
   -2025, 13140, -2025, -2025, -2025, -2025, 14533, -2025, 13140, -2025,
   -2025, 13140, -2025, -2025, -2025, -2025, -2025, -2025,   902,   900,
    1121, -2025, -2025, 14722, -2025, -2025, -2025, -2025,   924, 14722,
   13140, 13140, 13140,   927, 13140, 13140, 13140,   928, 13140, 13140,
   13140, 13140, 13140, 13140, 13140, 14533, 13140, 13140, 13140, 13140,
    6259,   929, -2025, -2025, 10484, 10484, -2025, -2025, -2025,   926,
    6259,  7590, 14533, -2025, -2025, -2025, -2025, -2025,  -188,  -188,
    -188,  -188,  -188,  -188,  -188,  -188,  -188,  -188,  -188,  -188,
    -188,  -188,  -188,  -188,  -188,  -188,  -188,  -188,  -188,  -188,
    -188,  -188,  -188,  -188,   330,  -188,  -188,  -188,  -188,  -188,
     931,  -188,  -188,   932,   697,   253,   253,   253, -2025, -2025,
   -2025,  -188,  -188,    40,  1006,  1007,  1008,   941,  1105,   367,
      -1,  7590,  1079,   697,   697,   253,   958,  -188,  -188,   959,
     960,   961, -2025, -2025, -2025, 13140,  7854, 13140, 13140,  8118,
      23,  1026,    41, -2025, -2025,   965, -2025,  6470, -2025, -2025,
   -2025, -2025, -2025,    99, 13140, 10484, 10484,   970,   971,  8382,
    6259,  6259,  6259, -2025, -2025, -2025,   972, -2025,   969,   974,
    8646,   973, 11554,  1237,  7590,   975,    15,   976,   978,   -39,
     -39,   -39, 13140, 13140,    17, -2025,   134,   -39, 11818,   258,
     272,   985,   987,   989,   990,   992,   993,   995, 10484, 10484,
   13140,  6259,  6259,  6259,   391,    18,  1236,   981, -2025,  1238,
    1258, -2025,   996, -2025,   998,  1001, -2025, -2025,  1002,  6259,
   -2025, 13140,  6534, -2025,  1262,  1004,   997,  1009,  1010,  1264,
    1269,  1016, 13140,  1017, 13140, 13140,   349, 13140,  1014, -2025,
    1074, 13140, 13140, 13140, -2025,  -188, 13140,   791,   128, -2025,
   13140, -2025,  -188,  -188,  -188,  1019,  1020,  1021,  -188,  -188,
    -188,  -188,  -188,  -188,  -188, -2025,  -188, -2025, -2025, -2025,
   -2025,  -188,  -188,  1022,  1023,  -188,  1024, -2025,  1025,  1285,
    1286,  1047, -2025, -2025,  1289,  1288,  1312,  1311,  1054, 16623,
   14533, -2025, 10484, 13140, -2025, -2025,  7590,  7590, -2025,  1052,
   14722,   697,  1316, -2025, -2025, -2025, -2025, -2025, -2025, 13140,
   13140,   470,  7590,  1318,   429,  1057,   827,  1058,  1323,    72,
    1060, -2025,  1061, 14743, 13140, -2025,  1056,   -71, -2025,    85,
     108,   131,  8842, -2025,   135, -2025,   133,  9106,  4468,  9365,
     105,   230,  1231, -2025,    23,  1059, 13140,  1063, 17139, 17164,
   17189, 13140, 17214, 17239, 17264, 13140, 17289, 17314, 17339, 17364,
   17389, 17414, 17439,  1066, 17464, 17489, 17514, 15376,  1328, 13140,
   10484,  6730, -2025,   122,   460, 13140,  1330,  1334,  1075, 13140,
   13140, 13140, 13140, 13140, 13140, 13140, 13140, 13140, 13140, 13140,
   13140, 13140, 13140, 13140, 13140, 13140, 10484, 13140, 13140, 13140,
   13140, 13140, 13140, 13140, 13140, 10484, 10484,  1076, 13140, 13140,
   14533, 13140, 14533,  7590, 14533, 14533, 14533,  1077,  1078,  1080,
    1081, 13140,    57, -2025, 11908, 13140,  1082,  1083,  1084,   156,
    1087,  7590,  6259,  7590,  1092, 14533, 14533, 10484,    23, 14722,
      23,  1090, 10484,  1090, -2025,  1090, 17539, -2025,   491,  1091,
      84,  1281, -2025,  1358, 13140, 13140, 13140, 13140, 13140, 13140,
   13140, 13140, 13140, 13140, 13140, 13140, 13140, 13140,  8910, 13140,
   13140, 13140, 13140, 13140,    23, 13140, 13140,   110, -2025,   692,
   17564,   532,   538, 13140, 13140, 13140, -2025,  1363,  1365,  1365,
    1107, 13140, 13140, 13140, 13140,    51, 10484, 10484, 16651,  1108,
    1368, -2025,  1111, -2025, -2025,  -145, -2025, -2025,  9624,  9888,
     -39,   -39,   490,   490,  -134, 11818, 11818, 13140, 11519,   -87,
   -2025, 13140, 13140, 13140, 13140, 13140, 13140, 13140, 13140, 13140,
     540,   555, 17589,  1370,  1372,  1375, 13140, 13140,  1378, 13140,
   -2025, -2025, 13140, 11873, -2025, -2025, 10484, 10484, 10484, 13140,
    1381, 17614,  1119, 13140, 10484, 13140, 13140, 13140, -2025, -2025,
   13140, 17639, 13140, 17664, 17689,  1193, 10152, -2025,  1125,  6994,
   17714, 17739, 13140,  1090, -2025, 13140,    23, 13140, 13140,   110,
   16734, 14533, 14533, 14533, 14533, 14533, 14533, 14533, 14533, 14533,
   13140, 14533, 14533, 14533, 14533,    16, 14722, 14533, 14533, 14533,
      23,    23, -2025, -2025, 10484, -2025,  1122, 13276, -2025,  1126,
   13339, 13140, -2025,  1127,   561, 17764,  4848,  1131,   567, 13140,
    1393,  1130,  7590, 17789, 16761, -2025, -2025, -2025, -2025, -2025,
   -2025,  1129,  1395,   196,  1397, -2025, -2025, -2025, 10484,   222,
   13140, -2025, -2025, -2025,    23, 13140, 13140,   110,  1136, -2025,
    1139,   -64,   697,   -13,   697, -2025,  1138, 15405, -2025,    20,
   10484,    23, 13140, 13140,   110,  1400, 10484,  1403, 10484, 13140,
    1404, 14533,    23, 12167,   110, 13140, -2025, 13140,  1405, -2025,
      23,  1408, 14533, 13140,  1148,  1150, -2025, 13140, 10416, 14722,
    1409,  1410,  1418, 17814,  1419,  1420,  1439, 17839,  1441,  1444,
    1446,  1447,  1448,  1449,  1450, -2025,  1451,  1452,  1453, -2025,
   13140, 17864, 10484,  1191, 10484,    58, 15434, -2025, -2025,  1456,
   16707, 16707, 16707, 16707, 16707, 16707, 16707, 16707, 16707, 16707,
   16707, 16707, 10774, 16707, 16707, 16707, 16707,   647,   463, 16707,
   16707, 16707, 11137, 11495, 11849, 12122, 12198,  6730,  1196,  1195,
     118, 10484, 12478, 12738,   463, 12998,   463,  1190,  1192,  1194,
     218, 10484, 13140, 13140, 13140, 18814, -2025,   463,  1197, 15463,
   15492, 13140, 13140, 13140,  1201, 13140, -2025, -2025, 13140,  1198,
     -10,   463,  -213,  1199,   358,   638,  1467, -2025,   110,   463,
    7590,  1204,  7258,  7522,  1184,   534,   845,   845,   713,   713,
     713,   713,   713,   713,   622,   622, 10484,   257, -2025,   257,
     257,  1090,  1090,  1090,  1205, 17889, 16788,   510, 10484, -2025,
    1469,  1208,  1209, 17914, 17939, 17964, 13140,  7590,  1476,  1475,
   11205, 17989, 15521, 18014, 18039, -2025, 13140,   640,   649, 10484,
    1210, -2025, 13403, -2025, 13466, 13530,   -39, 13140, 13140, -2025,
   -2025,  1213,  1214, 11818,  5856,  1337,   -63,   -39, 13593, 18064,
   15550, 18089, 18114, 18139, 18164, 18189, 18214, 18239,  1218,  1219,
    1483, 13140,  1485, -2025, 13140, 18264, 15579, -2025, 16815, 13657,
   16842, -2025,   668,   675,   677, 15608, -2025, -2025, -2025,  1382,
     680, 16869, 16896, 13074, 18289,  1487, 18314,  1488,  1489,  1220,
   13140, 13720, 13140, 13140, -2025, -2025, 16707,   257,  1225,   620,
      49,   406,   407,   406,  1232,  1233,  1223,   463,   463,  1226,
   13901,   463,   463,   463,   463, 13140,   463,  1493, -2025,  1228,
    1240,   496,   544,  1250,   683, -2025, -2025, -2025, -2025, 18339,
   13784,  1235,  1303,  1522,  1360, 12264,  1263,  1265,  1527,  7590,
   15637, -2025, 13140,  1531,   202,   106,   110,    31, 14722, 13140,
    1532, -2025,   708,  1490,  1491,  7590, 15666,    44,  1271, 18364,
   16923,   674, 13140, 13140,  1278,  1276,  1282,  1277,  9174, -2025,
   -2025, -2025, -2025, 14533,   316,  1283, 18389, 16950,  1287, -2025,
     422, -2025,   433, 14125, -2025, -2025, -2025,  1284, -2025,  1291,
   15695, 14668, -2025,     7, -2025, -2025, 18814, -2025,   120, 16707,
   13140,   463,   -39,  7590,  7590,  1542,  7590,  7590,  7590,  1547,
    7590,  7590,  7590,  7590,  7590,  7590,  7590,  7590,  7590,  7590,
    2137,  1554, 10484,  6730, -2025, -2025,   490, -2025, -2025, -2025,
   -2025, -2025, -2025, -2025, -2025, -2025, -2025, -2025, -2025, -2025,
   -2025, 13140, -2025, -2025, -2025, -2025, -2025, -2025, -2025, -2025,
   -2025, 13140, 13140, 13140, 13140, 13140, -2025, -2025, -2025,   711,
   13140, 13140, -2025, 13140, -2025,  7590, 14533, 14533, -2025,   717,
   15724, 15753, 15782,  1290, -2025, -2025, -2025,  1361, 15811, 15840,
   15869, 13140, 15898, 15927, 13140, 13140, -2025, -2025, -2025,   110,
   -2025,   110, 13140, 13140,  1295, -2025,  7590,  -188, -2025, -2025,
   -2025, 13140, 13140,   719,   110,   317,  -120, 13140, 13140, -2025,
     463,   722,  7590, 10484, 10484,  1557,  1559,  1560,  3221, -2025,
   -2025,  1562, -2025,  1302, 18814,  1296,  1563, -2025,  1565,  1566,
    2405,  1567,  1568,   727,   127, -2025, 13847, -2025, -2025,   -84,
   14716, 14749, -2025, -2025, 15956,   232,  1455,  1572, 12523,  1309,
    1574,  1319,    43,    45,   -97, -2025,   -76, -2025,   -63,  1575,
    1578,  1579,  1580,  1582,  1583,  1585,  1586,  1587,   490,   490,
    7590, 18814, -2025,  2496,  1325,  1492,  1592, -2025,  1593,  1596,
    1494,  1597, -2025, -2025,  1599,  1601,  1602, 13140,  1603,  7590,
    1606,  7590,  7590,  1605, 14782, -2025,  7786,   469,   110, 13140,
   13140,   110,   110, -2025, 10484, -2025, -2025, -2025, -2025, 14533,
   -2025, -2025, 13140, 14533, -2025, -2025, -2025, -2025, 18814, -2025,
    1342,  1341, 14533, -2025, 14533, -2025,   110, 14533,  1336, -2025,
    1343,  1611, -2025,  1349,   697,  1350, 12620, -2025,  2568,  1351,
    7590, -2025,  1352, -2025, 15985, -2025, -2025, 13140,  1616,   488,
   13140,  1637,  1638,    15,  1640,  1376,  1644,  2619, -2025,   463,
    -188,  -188,  1645, -2025, -2025,  1388,  1389,  1387, -2025,  1652,
   -2025, -2025, -2025, -2025, -2025, -2025,   110,  -131,  1149, 13140,
   16977, 18414, 13140,  9433, 13140, 10484,  1390,   730,  1653,   123,
     110, -2025,  1394, 13140,  1654,  1656, 13140,   110, 12783,  1661,
   13140, 10743,   463,  5439, 13140, 13140, 13140,  1402,  1398, -2025,
    1663, 18439,  1666,   154,  1533,  1533,  7590,  1668,  1670,  1671,
    7590,  -105,  1672,  1673,  1674,  1675,  1676,  1677,  1678,  1679,
    1680, -2025,  1682,   735,  1421, 16707, 16707, 16707, 16707, 16707,
   16707,   463, 14815, 14848, 14881,  1422,   463,   463, -2025, -2025,
   -2025, -2025,   120,   463,  1561,  1564,  1569, 16014,  1495, -2025,
   18464, 16707,  1424,   293, 18814, 16707, -2025,  1688,   463, 18814,
   18814, -2025,   509, -2025,   110, -2025, 18489, 17004, -2025,   463,
    1689,   738,   741,  7590,  7590,  7590,  1692,  1694, -2025,   231,
   13140,  7590,  7590,  7590, -2025,  1431,  1432,  1696,  1699,  1700,
   -2025, 13140, 13140, 13140,  1436,  1438,  1440,  1443, -2025,  2983,
    7590, -2025, 13140, -2025,  1703, -2025,  1706, -2025, -2025, 11818,
     351,  6798, -2025,  1445,  1463,  1464,  1466,  1468,  1470,  9692,
    1442,  1471,  1708, -2025, 10484,  1473, -2025, -2025, -2025,  1474,
   13140, 13140, -2025, -2025, 17031,  7590,  1712,  7590,  1716,  1539,
   -2025, 13140, 13140, 13140, -2025,   575,  1733,   753,   537,  1472,
    5375,  1477, 13140,    32,   463,  1478,   463,  1479, -2025, -2025,
   14722, -2025, 13140,  1480, -2025, -2025,  3327, -2025, -2025,  1481,
    1735, -2025,  3457, -2025,  1496,  1741,   216,  3656, -2025,    15,
   -2025,   743, -2025, 13140, -2025, -2025,   231,  2210,  4765, -2025,
    1498, 13140, 13140,  7590,  1497, -2025,   182,   578,  1743, 18514,
    1745,  1467, 18539,  1482,   748, 18564,   749,  1749,  1751, -2025,
   -2025, 14533,  1499,  1762, 18589, -2025, -2025, 14914,  1503, -2025,
   -2025,  6195,  5703, 18814, -2025,  1763,  -188,  8118, -2025, -2025,
   -2025, 18814, 18814, 18814, -2025,   120, -2025,  1766, -2025, -2025,
     -39,  1769,  1770,  1771, -2025, -2025, -2025,  1630,   -52,  1681,
    1774, -2025, -2025, -2025, -2025, -2025, -2025, -2025, -2025, -2025,
    1776,  1512,  1778, -2025, -2025, -2025, -2025, -2025, -2025, -2025,
   13140, 13140, 13140, -2025, -2025, -2025,  1398, -2025,  1515,  1516,
    1521, -2025,  1684, -2025, -2025, -2025, 13140,  1525,  1518, -2025,
   -2025, 13140, 13140,   463,   317, -2025, -2025, -2025, -2025,  1528,
    1529,  1791,  -105,  1794, 13140, -2025,  7590, 18814,  1655,  1657,
     864, 10484, 10484, 13140, -2025, 11205, 16043, 18614,  8050,   490,
     490, 13140, 13140, -2025,   169,  1530, 18639, -2025, -2025, 16072,
     -61, -2025,  1797,  1801,  7590,   -39,   -39,   -39,   -39,   -39,
    7062,  1804, -2025, -2025, -2025,   751, 10484, 13140,  3821,  4549,
    1806,  1807, -2025,  1808, -2025,  7590,  8314,   601, 18664, 13140,
   13140, -2025, -2025, 10842, -2025, 14533, 13140, -2025, 14533, 18814,
   11106, 14722,  1540, -2025, -2025, -2025, -2025,  1549,  1543, 16101,
   13140,  4848, -2025,  4848,  7590, -2025, -2025,   110,    31, 14722,
   13140,  1813, -2025,  1818, -2025,    15, 17058,  7590, 14533,  1820,
     463, -2025,  1552,   463, 13140, 14947, 14980,   754, -2025, 13140,
   13140,  1558, -2025,  1570, -2025,  1560,  1823,  1825,  1566,  1827,
   -2025, -2025,  1828, 13140, -2025, -2025, 13140, 12880,  1829, 13140,
   -2025, -2025,  1571,  4765,   756,  1641,  1830, -2025, -2025,   621,
   -2025, -2025, -2025,  1683,  1832,  1573,  1576,  1577, -2025,  1834,
    7590, -2025, 16707, 16707, 15013, 13140, 13140, 13140,  1581, 16707,
   -2025,  1588, 18689, 17085, -2025, -2025, 10484, 10484, -2025,  1838,
   -2025, 18814,  1842, 13140, 13140,  1584, -2025,   783,   784, 16679,
    4649,  1843,  1589, -2025, -2025, 13140,  1591,  1595, 16130, 17112,
    1844,  7590,  1845,  1590, 13140, -2025, -2025,   786,   213,   227,
     229,   236,   243,  9956,   289, -2025,  1847,   789, 16159, -2025,
   -2025, -2025, -2025, -2025,  1659, -2025, 13140, 13140, -2025, -2025,
   13043, 10220,  4672,  1851,  1852,  1600, 16707,   463, 18814, -2025,
   -2025, -2025, -2025,    32, -2025, 14722, -2025, 16188,  1607,  1608,
    1609,  1856,  1858,  1862,  4837, -2025, -2025, -2025,  1598,  1865,
     792, -2025,  1867,  1870,   434, 18814, 13140, 13140,  1612,  7590,
     836, 18814, 18714, -2025, -2025, -2025, -2025, 18739, 15046, -2025,
   -2025, 16217,  1290,  1341,  7590,   463, -2025, 13140, 14722,    23,
   -2025, -2025, 10484, 10484, 13140,  1871,   837, -2025, -2025, 13140,
   15079, 16246, 15112, 13140,  1518, -2025, -2025, -2025,   838,   846,
   -2025, -2025,  4865,  5092,  7590,    46,   457, 10484, -2025, -2025,
     490,  8578, -2025, -2025, -2025,  1875, -2025,  1632,  7590, -2025,
   16275,  1901, 10484,   -39,   -39,   -39,   -39,   -39, -2025,  1902,
   -2025, 13140, 16304, 16333, 10484, -2025,   848, -2025, -2025, -2025,
   -2025, -2025, -2025, -2025,  1642,  1905,  1643, -2025,  1908,    15,
   -2025, -2025, -2025,  1715, -2025, -2025, -2025, -2025, -2025, 13140,
   15145, 15178,  7590, -2025,  1910, 13140,  1647, -2025, 13140,  1912,
    1648,  1649, -2025, -2025,  5889, -2025,  1658,   849,   856, 16362,
   -2025,  1651, 15211, 13140, -2025, 13140, 16391,  1662, -2025,  1660,
   -2025, -2025,   866,  1664,   -39,  7590,  1916,  1665,   -39,  1917,
     867,  1667, -2025, 13140, -2025,  1919,  1777, 13911,  1669, -2025,
     868,   301,   303,   311,   352,   365, -2025,  5132, -2025, -2025,
     873, -2025,  1922, -2025, -2025, -2025,  1925, -2025,  1685, 18814,
   13140, 13140,   874, -2025, 18814, 15244, -2025, -2025, -2025,  1290,
   14722,  1687, -2025, -2025, -2025, 13140, 13140, 16420, 16449, -2025,
   -2025, 10484,  1926,   -39,   176, -2025, -2025,   -39,   191, -2025,
    1927, -2025, 16478, -2025, 13140, -2025,   -63, -2025,  1930, 10484,
   10484, 10484, 10484,  9956, -2025, -2025, -2025,  4848, -2025, 13140,
   18764, 15277,    64, 13140,  1686, -2025, -2025, 15310, 15343, -2025,
   -2025,   875, -2025,   374, -2025,   381, -2025, -2025, -2025,  5635,
     366, 13974, -2025,   876,   881,   884,   886,   384,   887,  1690,
     889, -2025, 13140, -2025,  7590, 16507, -2025, 13140, 13140, -2025,
     -39,   -39, -2025, -2025, -2025,   -63,  1931,  1934,  1935,  1936,
   10484,  1939,  1940,  1941,  1693, 18789,   892,  1942, 16536, 16707,
     387,   411,   499, -2025, -2025, -2025, -2025,   894, -2025, -2025,
   -2025, 14533, -2025,  1695, -2025,  1943, -2025, 13140, 13140, -2025,
    1944,   897, -2025,  1697,  7590, -2025, 16565, 16594, -2025,  1945,
   14533, 14533,   916,  1946,  1950, -2025, -2025,   917, -2025,  1952,
   -2025, -2025,  1954, 14533, -2025, -2025, -2025
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -2025, -2025, -2025, -2025,   503, -2025, -2025, -2025, -2025,  -295,
   -2025, -2025, -2025, -2025, -2025, -2025, -2025, -2025, -2025, -2025,
   -2025, -2025,  -792,  -150,  5006,  3224,  -439, -2025,  1484, -2025,
   -2025, -2025, -2025, -2025, -2025, -2024, -2025,   447,   255,   -81,
   -2025,   -42, -2025,   192,   492, -2025,  1970, -2025,   769,   -45,
    1386, -2025,    22,  -667,  -140, -2025, -2025, -2025, -2025, -2025,
   -2025, -2025,   851,  1973, -2025, -2025, -2025, -2025, -1316, -1314,
    1976, -1850,  1978, -2025, -2025, -2025,  1333, -2025,  -103, -2025,
   -2025, -2025, -2025,  2377, -2025, -2025, -1525,   347,  1983, -2025,
     -23, -2025, -2025,   -57, -2025, -1805,   543, -2025,   -59,  2965,
    3064,  -333,   119, -2025,  2049,   -49, -2025, -2025,   138,   321,
   -1811,  -143,  1159, -2025,    -3
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -604
static const yytype_int16 yytable[] =
{
     152,  1119,   473,   662,   179,  1011,  1012,  1125,  1767,  1977,
    1588,  2018,  1590,  2019,  1471,   344,   346,   160,   349,   396,
     178,   330,   698,   494,   180,   133,  1140,   178,  2150,   391,
     498,   167,   793,   365,   169,   178,  1850,   393,   155,  2011,
     389,   444,   318,   446,  1728,   583,   612,   318,  1434,  1583,
       5,  1585,  1317,  1925,  1258,   313,  1371,   995,   370,  1259,
     371,   178,   335,   156,  1195,   455,   439,   589,   443,   319,
    2293,  1318,  1926,     4,  1134,   350,   178,   193,   181,   197,
     182,   804,  1319,  1320,  1321,   369,  1317,   400,  1322,  1323,
     336,   313,   157,   504,   821,   324,   313,  1729,   325,   326,
     327,   399,  2055,   478,   590,  1318,   337,   338,   634,   670,
     671,   328,   440,  1416,   785,   153,  1319,  1320,  1321,   154,
     670,   671,  1322,  1323,  1473,  2066,   366,   634,   158,  1690,
    1006,  1568,   467,   468,   505,   331,   786,   736,   332,  -598,
     507,  1013,   832,   467,   468,   159,  1474,   787,   788,   479,
     162,   528,  1544,   786,   489,   489,   489,  1475,  1476,   372,
    1719,   536,   166,   496,   787,   788,   216,   670,   671,   217,
     670,   671,   218,   163,  1587,   481,   351,   614,   670,   671,
     352,   329,  2274,   164,   392,   219,   353,   354,  1017,   355,
     356,  1571,   394,   670,   671,  2264,   819,  2276,   977,  1589,
    2173,  2174,   489,  1118,   820,   165,  2175,   313,   678,  1416,
     171,   313,   313,   357,  1974,   340,   341,   313,   313,   489,
     578,   579,   580,  1869,   789,   790,   996,   342,   703,  1123,
    1584,   343,  1586,  1435,  1436,  1437,  1438,   176,  1416,   367,
     594,   789,   790,  1941,   172,   105,  1851,   106,   107,   108,
     109,   110,   125,   125,   173,   114,   115,   796,   117,   797,
     125,   647,   648,   649,   376,  1255,   125,   377,   125,  1141,
    1142,   670,   671,   181,   174,   182,  1588,   609,   313,  2172,
     378,   161,   665,   666,   175,   397,   699,   672,   700,  1085,
     674,   679,   154,   313,   125,   168,   313,   610,   170,   368,
    1069,  1423,   693,   694,   695,   767,   445,   770,   447,   125,
     584,   613,   313,   313,   776,  1439,   313,   313,   313,   313,
     710,  1372,  1417,  1420,   796,   456,   797,   313,  1196,   457,
     361,   313,   362,   399,  2294,   467,   468,  2212,   805,   194,
     806,   198,  -596,   190,   807,   463,   464,   465,   466,   401,
     181,   822,   182,   823,   177,   313,   313,   824,   313,   313,
     313,   324,   467,   468,   325,   635,   327,   636,  1131,   467,
     468,   637,  1141,  1142,   838,   825,   313,   328,  1419,   313,
     839,   467,   468,   826,   635,  1148,   636,  1228,   670,   671,
     637,   467,   468,   873,   737,  1159,   738,   874,   827,   833,
     739,   823,   830,   191,   673,   834,   828,  2289,   670,   671,
     831,   780,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   625,   626,   627,   628,   629,   630,   631,   632,
     670,   671,   192,   920,   633,   463,   464,   465,   466,   195,
    1970,   463,   464,   465,   466,   670,   671,   489,  1890,   313,
    1840,   196,  -600,   313,   313,   463,   464,   465,   466,   467,
     468,   463,   464,   465,  1124,   467,   468,   670,   671,   313,
     463,   464,   465,   466,   785,   587,   808,  1623,   588,   467,
     468,   670,   671,   670,   671,  1238,   670,   671,  2102,  2316,
     670,   671,   785,   831,   480,   209,   786,   670,   671,   841,
    1317,   846,  2103,  1575,  2104,   839,   453,   787,   788,  1267,
     454,  2105,   670,   671,   786,  1317,   631,   632,  2106,  1318,
     199,  1002,   633,  1004,  1005,   787,   788,   313,   680,  1504,
    1319,  1320,  1321,   936,  1318,   200,  1322,  1323,   681,  2352,
    1018,   201,   682,   670,   671,  1319,  1320,  1321,   202,  2167,
     943,  1322,  1323,   313,   203,   670,   671,   670,   671,   181,
    1039,   182,   313,   910,  2107,   670,   671,   489,  1262,   489,
     313,   489,   489,   496,   204,   942,  2249,   944,  2250,   927,
     467,   468,  1891,  1459,   789,   790,  2251,  1061,   313,   313,
     313,   874,   489,   489,   313,   180,   565,   180,   566,   313,
    1073,   311,   789,   790,   786,   320,   670,   671,   321,  1997,
     322,  2177,  2178,  1009,  1010,   787,   788,  2175,   666,   670,
     671,   725,  1811,   154,   181,   313,   182,  2252,   670,   671,
    1261,   974,  1100,  1262,   205,   670,   671,  2303,   670,   671,
    2253,   670,   671,  1120,    71,    72,    73,    74,  1317,  2300,
      77,    78,   206,   313,   313,   614,  2301,   696,   207,  2310,
      87,   697,  2337,   208,    91,   670,   671,  1318,   211,   791,
     792,  1600,  1601,   796,   796,   797,   797,  1422,  1319,  1320,
    1321,   831,  1374,   214,  1322,  1323,  2338,  1654,  1655,  1464,
     340,   341,   789,   790,   481,   481,   796,   874,   797,   798,
    1465,  2138,   342,   313,   313,   313,   348,  1088,   874,  2139,
     210,   313,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   625,   626,   627,   735,   629,   630,   631,   632,
     796,   875,   797,  1068,   633,   874,  1624,  1092,   496,   489,
     496,   489,   489,   489,   489,   489,   489,   215,   489,   489,
     489,   489,  1087,   212,   489,   489,   489,   180,  1093,  1842,
    1843,   313,   947,   796,   537,   797,   874,  1786,  1136,   213,
    2339,  1394,   132,   467,   468,  1771,  1277,  1772,  1278,   313,
     618,   619,   620,   621,   622,   623,   624,   625,   626,   627,
     735,   629,   630,   631,   632,   313,   222,   734,   188,   633,
    1171,  1128,   184,   981,   796,   185,   797,   874,   186,   982,
     187,  1028,   874,   874,   221,   874,  1396,   313,  1145,  1397,
    1532,    48,  1533,   313,   311,   313,  1029,  1279,   496,  1157,
     874,   314,  1102,   801,   323,  1542,   874,  1163,  1108,   489,
     315,  1839,  1109,  1840,   615,   616,   617,   618,   619,   620,
     621,   622,   623,   624,   625,   626,   627,   735,   629,   630,
     631,   632,   646,  1306,  1870,  1569,   633,   316,  1955,   313,
    1956,   313,  1998,   655,  1877,   670,   671,   660,   735,   629,
     630,   631,   632,   467,   468,   317,  1369,   633,  1370,   448,
     615,   616,   617,   618,   619,   620,   621,   622,   623,   624,
     625,   626,   627,   872,   629,   630,   631,   632,   313,  1265,
     333,  1301,   633,   874,   796,   874,   797,   334,   313,  1279,
    1302,   475,   339,   347,   874,   358,   475,   475,   475,  1625,
    2280,   359,  1626,  1627,   363,   475,   360,   467,   468,  1349,
    1449,  1295,  1370,   874,  -599,   373,  1350,   313,  1351,  1309,
     874,  1354,   874,   375,  1400,   874,  1315,  1637,   874,   796,
    1326,   797,   978,   313,  1418,  1421,  1588,   626,   627,   735,
     629,   630,   631,   632,   475,   313,   385,   364,   633,  1429,
    1656,  1279,  1511,   874,   313,   374,   874,   386,  1518,  2322,
    1541,   475,   874,  1549,   874,   387,   313,   874,  1567,   777,
     778,  1688,   874,   388,   390,   874,  1741,  1676,  1588,  1779,
     874,   395,  1780,   874,  1874,   794,   874,   409,  1875,  1897,
    1899,  1692,  1986,   874,   874,  2038,   874,  2056,  1698,  2039,
     402,  2057,   403,   577,   615,   616,   617,   618,   619,   620,
     621,   622,   623,   624,   625,   626,   627,   735,   629,   630,
     631,   632,   592,   593,  2085,  2086,   633,  2101,   874,   874,
    2109,  2039,   818,  2135,   874,   410,   441,   831,   451,  1426,
     615,   616,   617,   618,   619,   620,   621,   622,   623,   624,
     625,   626,   627,   735,   629,   630,   631,   632,   450,   452,
    1660,   458,   633,   620,   621,   622,   623,   624,   625,   626,
     627,   735,   629,   630,   631,   632,   313,  2144,  2161,  2168,
     633,  2145,  2039,   874,  1425,  1483,   917,  2169,   459,  2201,
    2222,   874,   313,   874,   874,  1543,  1545,  2223,   484,   485,
     504,   874,  1966,  1967,   646,   313,   937,  2232,  2240,  2248,
     489,  2039,   874,   874,  2255,  2262,  2299,  2306,   874,  2039,
     874,   874,  2307,   178,   411,  2308,   874,  2309,  2311,   874,
    2313,   874,   874,  2333,  2145,  2340,   502,  2039,  2349,   874,
     313,   313,  2350,   313,   313,   313,   154,   313,   313,   313,
     313,   313,   313,   313,   313,   313,   313,  2359,  2362,   313,
     506,  2039,  2363,   511,   515,   529,   535,   573,   576,   412,
     413,   414,   415,   416,   417,   418,   419,   420,  -208,  -209,
    -210,   585,   421,   422,   423,   424,   586,   591,   481,   475,
     425,   426,   427,   428,   595,   598,   599,   600,   611,   429,
     781,   430,   313,   489,   489,   454,   643,   644,   651,   652,
     653,   659,   701,   656,   704,   661,   663,   431,   664,   702,
     432,   683,   816,   684,   184,   685,   686,   185,   687,   688,
     186,   689,   187,   313,   705,   715,   706,   816,   707,   713,
     718,   708,   709,    48,   714,   719,   728,   716,   717,   313,
     313,   313,   720,   722,   727,   744,   745,   746,   757,   758,
     760,   762,   763,   761,   461,   765,   766,  1543,  1545,   615,
     616,   617,   618,   619,   620,   621,   622,   623,   624,   625,
     626,   627,   735,   629,   630,   631,   632,   764,   768,   769,
     771,   633,   779,   782,   795,  1113,  1873,   800,   802,   803,
     153,   843,   809,   865,   847,   870,   877,   313,   849,   475,
     878,   475,   879,   475,   475,   475,   911,   921,   922,   950,
     923,   924,   931,   932,   933,   633,   313,   935,   313,   313,
     481,   481,   938,   948,   475,   475,   951,   433,   434,   435,
     986,   313,   987,   990,  1001,  1000,   489,  1031,  1033,   436,
     489,  1003,  1034,   437,  1037,   438,   125,  1046,  1353,   489,
    1048,   489,  1059,  1095,   489,  1062,  1101,  1097,  1107,  1111,
    1112,  1116,  1117,  1121,  1132,  1133,  1149,   313,  1138,  1151,
    1154,  1162,   467,   468,  1164,  1167,  1172,  1173,  1168,  -597,
     399,  1677,  1704,  2181,  1709,  1174,  1176,  1177,  2021,   617,
     618,   619,   620,   621,   622,   623,   624,   625,   626,   627,
     735,   629,   630,   631,   632,   489,  1178,   816,  1180,   633,
     313,  1181,   313,  1182,  1183,  1184,  1185,  1186,  1187,  1188,
    1189,  1192,  1198,  1226,  1227,  1235,  1260,  1236,  1245,  1237,
     313,  1251,   816,  1254,  1266,  1270,  1282,  1274,  1283,  1284,
    1290,  1292,  1304,   313,  1312,  1313,  1316,   313,  1338,  1339,
    1340,  1342,  1363,  1269,  1359,  1361,  1362,  1368,  1379,  1377,
    1378,  1382,  1390,  1392,  1861,  1404,  1871,  1393,  1863,  1403,
     475,   475,   475,   475,   475,   475,   475,   475,   475,  1399,
     475,   475,   475,   475,  1882,  1882,   475,   475,   475,  1405,
    1289,  1406,  1810,  1411,  1409,  1410,   816,  1415,  1428,   816,
    1430,  1431,  2027,  1446,  1452,   816,  1453,  1455,  1454,  1486,
     313,   313,   313,  1463,  1490,  1460,  1467,  1468,   313,   313,
     313,  1502,  1536,  -211,  1553,  1522,  1554,  1555,  1558,  1559,
    1561,  1560,  1562,  1563,  1565,  1566,  1577,   313,  1576,  1580,
    1581,  1135,  1591,  1137,  1592,  1582,  1593,  1594,   313,  1595,
    1596,  1858,  1597,  1598,  1599,  1604,   313,  1605,  1606,  1607,
     475,   313,  1608,  1639,  1610,  1609,  1611,  1612,  1613,  1620,
    1615,   475,   313,  1617,   313,  1632,  1633,  1641,  1640,  1642,
    1644,  1648,  1653,  1650,  1945,   615,   616,   617,   618,   619,
     620,   621,   622,   623,   624,   625,   626,   627,   735,   629,
     630,   631,   632,  1658,  1663,  1659,  1662,   633,  2058,   614,
    1664,  1669,  1412,  1911,  1671,  1672,   399,  1673,  1675,  1689,
    1695,  1687,  1696,  1919,   496,   496,  1693,  1700,  1432,  1716,
     313,  1714,  1718,  1715,  1724,  1720,  1725,  1726,  1731,  1732,
    1733,  1734,  1735,  1736,  1737,  1738,  1739,  1740,   489,  1753,
    1758,  1765,  1742,  1759,  1769,  1778,  1784,  1762,  1760,   313,
    1785,  1791,  1792,  1793,   313,  1794,  1799,  1795,  1800,  1807,
    1801,  1802,  1808,  1822,  1824,  1814,  1484,  1485,  1832,  1487,
    1488,  1489,  1834,  1491,  1492,  1493,  1494,  1495,  1496,  1497,
    1498,  1499,  1500,  1815,  1816,  2030,  1817,  1835,  1818,  1841,
    1819,  1865,  1823,  1826,  1827,  1855,  1961,  1845,  1868,  1892,
    1860,  1894,  1848,  1896,  1397,  1900,  1864,  1901,  1978,  1979,
    1980,  1981,  1982,  1984,  1884,  1903,  1904,  1889,  1867,  1907,
    1912,   816,  1918,   816,   816,  1920,  1921,  1922,  1515,  1923,
    1928,  1929,  1930,   313,  1931,  1935,  1936,   816,   313,   313,
    1927,  1937,  1940,  1262,  2004,  1938,  2206,  1948,  1946,  1947,
    1950,  2009,  2012,  1975,  1953,  1971,  1954,  1976,   816,  1537,
    1985,   313,  1991,  1992,  1993,  2013,  2014,   313,  2015,  2025,
    2023,   481,   481,   313,  2026,  1550,  2031,   831,  -603,  2043,
     816,  2044,   313,  2045,  2046,  2050,  2060,  2059,  2061,  2065,
    -601,  2054,   489,  2062,  2080,   489,  2063,  2064,  2081,  2089,
    2096,  2073,  2098,  2108,  2084,  2075,  2111,  2118,  2119,  2090,
    2099,   313,  2092,  2129,  2130,  1425,  2093,  2120,  2131,   816,
    2133,  2134,   399,  2136,   313,   496,  2137,  2160,  2126,  2127,
    2128,  2184,  2142,  1602,   615,   616,   617,   618,   619,   620,
     621,   622,   623,   624,   625,   626,   627,   872,   629,   630,
     631,   632,  1616,  2185,  1618,  1619,   633,  2189,  2196,  2202,
     496,  2203,   475,  2204,  2205,  2207,  2213,  -602,  2216,  2217,
    2218,  2225,  2236,  2239,  2221,  2243,  2244,   313,  2256,  2230,
    2231,  2258,  2272,  2277,  2233,  2237,  2282,  2323,  2241,  2247,
    2324,  2325,  2326,   313,   313,  2328,  2329,  2330,  2334,  2345,
    2348,  2355,  2360,  1649,  2266,  2259,  2361,  2296,  2364,  2187,
    2365,  2312,  1691,  2331,  2290,  2344,  2124,  2351,   313,  1756,
    1917,  2123,  2151,   131,  1949,   934,   142,  1722,  1445,   143,
     313,   144,   989,  2179,  1857,   842,   150,  2022,  2010,  1883,
    1156,     0,     0,     0,     0,     0,     0,     0,   313,     0,
       0,     0,     0,     0,     0,   475,   475,     0,     0,  2155,
       0,     0,     0,     0,     0,     0,  1708,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1723,
       0,     0,     0,  1727,     0,     0,   313,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2191,  2192,  2193,  2194,
    2195,   313,     0,     0,     0,     0,  2156,     0,     0,   313,
     313,     0,     0,     0,  2257,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   816,     0,     0,     0,     0,
       0,   313,     0,     0,   313,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   313,  1781,  1782,  1783,   313,
       0,     0,     0,     0,  1788,  1789,  1790,  2281,     0,     0,
       0,   313,   481,     0,     0,     0,     0,  2234,     0,     0,
       0,  2238,     0,  1805,     0,     0,   399,     0,     0,     0,
       0,     0,     0,     0,  1813,     0,     0,     0,     0,   313,
       0,     0,  1821,  1501,     0,     0,     0,     0,   475,     0,
       0,     0,   475,     0,     0,     0,     0,     0,  1831,     0,
    1833,   475,     0,   475,     0,     0,   475,     0,     0,     0,
       0,  2265,   313,  1643,     0,     0,  2273,     0,     0,     0,
    2275,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2287,     0,     0,     0,
       0,   477,     0,     0,     0,     0,   487,   490,   491,     0,
       0,     0,     0,     0,   178,   411,  1888,   475,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   313,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2320,  2321,  1910,   313,   313,   313,   313,
     313,     0,     0,     0,   523,     0,     0,     0,     0,     0,
     412,   413,   414,   415,   416,   417,   418,   419,   420,     0,
       0,   538,     0,   421,   422,   423,   424,     0,     0,     0,
       0,   425,   426,   427,   428,     0,     0,     0,     0,     0,
     429,   313,   430,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   313,   431,     0,
       0,   432,     0,     0,     0,   184,     0,     0,   185,     0,
       0,   186,     0,   187,     0,     0,     0,     0,   489,  1952,
       0,     0,     0,     0,    48,     0,     0,     0,     0,     0,
       0,   313,     0,     0,     0,     0,     0,   489,   489,     0,
       0,     0,     0,     0,     0,   461,     0,  1888,     0,     0,
     489,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1994,     0,
     615,   616,   617,   618,   619,   620,   621,   622,   623,   624,
     625,   626,   627,   735,   629,   630,   631,   632,     0,     0,
       0,     0,   633,     0,     0,     0,     0,  2020,     0,     0,
       0,  1564,     0,     0,     0,     0,     0,     0,     0,     0,
    2029,     0,     0,     0,     0,     0,     0,     0,   433,   434,
     435,     0,     0,     0,     0,     0,   475,   475,     0,     0,
     436,     0,     0,     0,   437,     0,   438,   125,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     475,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1888,     0,     0,     0,   796,     0,   797,
    1878,     0,     0,     0,     0,     0,     0,     0,   407,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   773,
       0,   449,  1603,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2097,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   476,
       0,     0,     0,   486,     0,     0,     0,     0,   492,     0,
       0,     0,     0,     0,     0,   497,     0,     0,   499,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   508,   509,   510,
       0,   512,   513,   514,  1647,   516,   517,   518,   519,   520,
     521,   522,  2143,   524,   525,   526,   527,     0,     0,     0,
       0,   531,   531,     0,     0,     0,     0,  2152,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   475,     0,     0,   475,     0,   914,
       0,   916,     0,   918,   919,  1665,     0,  1888,     0,     0,
     816,     0,   816,     0,     0,     0,     0,     0,     0,     0,
       0,  2186,     0,     0,   939,   940,     0,   475,   615,   616,
     617,   618,   619,   620,   621,   622,   623,   624,   625,   626,
     627,   735,   629,   630,   631,   632,     0,     0,     0,     0,
     633,     0,   601,   603,   605,   606,   531,     0,     0,     0,
       0,     0,   475,     0,     0,  1888,     0,     0,     0,     0,
       0,   640,   531,   531,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   658,
       0,     0,     0,     0,     0,     0,     0,     0,  2235,   668,
     669,     0,     0,     0,     0,   669,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   531,   531,   692,     0,   615,
     616,   617,   618,   619,   620,   621,   622,   623,   624,   625,
     626,   627,   735,   629,   630,   631,   632,     0,   711,   531,
       0,   633,     0,     0,     0,     0,     0,     0,     0,   721,
       0,   723,   724,     0,   726,     0,     0,     0,   729,   730,
     731,     0,     0,   733,     0,     0,     0,   740,     0,     0,
       0,  1072,     0,  1074,  1075,  1076,  1077,  1078,  1079,     0,
    1081,  1082,  1083,  1084,     0,     0,  1089,  1090,  1091,     0,
       0,   615,   616,   617,   618,   619,   620,   621,   622,   623,
     624,   625,   626,   627,   735,   629,   630,   631,   632,   531,
     775,     0,     0,   633,     0,     0,     0,  1888,     0,     0,
       0,     0,     0,     0,     0,     0,   783,   784,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   817,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   625,   626,   627,   735,   629,   630,   631,   632,
    1155,     0,     0,   848,   633,     0,     0,  1888,   853,     0,
       0,  1165,   857,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   871,   603,     0,     0,
       0,     0,   876,     0,     0,     0,   880,   881,   882,   883,
     884,   885,   886,   887,   888,   889,   890,   891,   892,   893,
     894,   895,   896,   897,   899,   900,   901,   902,   903,   904,
     905,   906,   907,   907,     0,   912,   913,     0,   915,     0,
       0,     0,     0,     0,     0,     0,   816,     0,   925,     0,
       0,   929,   930,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   907,     0,     0,     0,     0,   531,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1803,
       0,   952,   953,   954,   955,   956,   957,   958,   959,   960,
     961,   962,   963,   964,   965,   967,   969,   970,   971,   972,
     973,     0,   975,   976,     0,     0,     0,     0,     0,     0,
     983,   984,   985,     0,     0,     0,   816,     0,   991,   992,
     993,   994,     0,   531,   531,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     816,     0,   601,   733,  1014,     0,     0,     0,  1019,  1020,
    1021,  1022,  1023,  1024,  1025,  1026,  1027,     0,     0,     0,
       0,     0,     0,  1035,  1036,     0,  1038,     0,     0,  1040,
       0,     0,     0,   531,   531,   531,  1045,     0,     0,     0,
    1049,   531,  1051,  1052,  1053,     0,     0,  1054,     0,  1056,
     475,     0,     0,     0,     0,     0,     0,     0,     0,  1066,
       0,     0,  1067,     0,   975,   976,     0,     0,     0,   475,
     475,     0,     0,     0,     0,     0,     0,  1080,     0,     0,
       0,     0,   475,     0,     0,     0,     0,     0,     0,     0,
       0,   531,     0,     0,     0,     0,     0,     0,  1099,     0,
       0,     0,     0,     0,     0,     0,  1110,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   531,     0,  1126,     0,   532,
     532,     0,  1129,  1130,     0,     0,     0,     0,     0,     0,
       0,     0,  1458,     0,     0,     0,     0,   531,     0,  1146,
    1147,     0,     0,   531,     0,   531,  1153,     0,     0,     0,
    1146,     0,  1160,     0,  1161,     0,     0,     0,     0,     0,
    1166,     0,     0,     0,  1169,     0,   615,   616,   617,   618,
     619,   620,   621,   622,   623,   624,   625,   626,   627,   735,
     629,   630,   631,   632,     0,     0,     0,  1190,   633,   967,
       0,  1193,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   604,     0,     0,   532,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   533,   534,
     532,   532,     0,     0,     0,  1516,  1517,     0,   531,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   531,  1240,
    1241,  1242,     0,     0,     0,     0,     0,     0,  1248,  1249,
    1250,     0,  1252,     0,     0,  1253,     0,     0,     0,     0,
       0,     0,     0,   532,   532,     0,     0,     0,     0,     0,
       0,     0,     0,  1862,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   531,     0,     0,     0,   532,     0,     0,
       0,     0,     0,     0,     0,   531,     0,     0,     0,     0,
       0,     0,     0,  1288,     0,     0,     0,  1294,     0,     0,
    1556,     0,     0,  1300,     0,     0,   531,     0,     0,   641,
     642,     0,     0,     0,  1310,  1311,     0,     0,     0,     0,
    1314,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1341,     0,
       0,  1343,     0,     0,     0,     0,     0,   532,     0,     0,
       0,     0,   690,   691,     0,     0,     0,     0,  1629,     0,
       0,     0,  1631,     0,     0,     0,     0,  1364,     0,  1366,
    1367,  1635,     0,  1636,     0,     0,  1638,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1388,  1866,   615,   616,   617,   618,   619,   620,
     621,   622,   623,   624,   625,   626,   627,   735,   629,   630,
     631,   632,  1408,     0,     0,     0,   633,     0,     0,  1414,
       0,     0,     0,     0,     0,   604,  1427,  1678,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1450,
    1451,     0,     0,     0,     0,   531,   774,     0,     0,     0,
       0,   898,     0,     0,     0,     0,     0,     0,     0,     0,
     908,   909,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1481,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   941,     0,     0,     0,     0,   532,     0,   531,
     615,   616,   617,   618,   619,   620,   621,   622,   623,   624,
     625,   626,   627,   735,   629,   630,   631,   632,  1505,     0,
       0,     0,   633,   968,     0,     0,     0,     0,  1506,  1507,
    1508,  1509,  1510,     0,     0,     0,     0,  1512,  1513,     0,
    1514,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   532,   532,     0,     0,     0,     0,     0,  1527,     0,
       0,  1530,  1531,     0,     0,     0,     0,     0,     0,  1534,
    1535,     0,     0,     0,     0,     0,     0,     0,  1539,  1540,
       0,     0,     0,     0,  1546,  1547,     0,     0,     0,     0,
     531,   531,  1872,     0,     0,     0,   945,     0,     0,     0,
       0,   532,   532,   532,     0,     0,     0,     0,     0,   532,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1579,     0,     0,   799,     0,
     615,   616,   617,   618,   619,   620,   621,   622,   623,   624,
     625,   626,   627,   735,   629,   630,   631,   632,     0,     0,
     997,   998,   633,     0,     0,     0,     0,     0,     0,   532,
       0,     0,     0,     0,  1614,     0,     0,     0,     0,     0,
    1902,     0,     0,     0,     0,     0,  1546,  1547,     0,     0,
       0,   531,     0,     0,     0,     0,     0,     0,     0,  1630,
       0,     0,     0,   532,     0,     0,     0,     0,     0,     0,
    1042,  1043,  1044,     0,     0,     0,     0,     0,  1050,     0,
       0,     0,     0,  1646,     0,   532,     0,     0,     0,     0,
       0,   532,     0,   532,  1652,     0,     0,  1657,     0,     0,
       0,     0,     0,     0,     0,     0,   926,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1679,  1989,  1094,  1682,
     531,  1685,   531,     0,     0,     0,     0,   968,     0,  1194,
    1694,     0,     0,  1697,     0,  1694,     0,  1701,  1703,     0,
       0,  1711,  1712,  1713,     0,     0,     0,     0,     0,     0,
       0,     0,  1122,   979,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   532,     0,     0,     0,
       0,     0,     0,     0,  1144,     0,   532,     0,     0,     0,
    1150,     0,  1152,     0,  2005,     0,     0,  2007,     0,   615,
     616,   617,   618,   619,   620,   621,   622,   623,   624,   625,
     626,   627,   735,   629,   630,   631,   632,     0,     0,     0,
       0,   633,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   532,     0,     0,     0,     0,     0,  1787,     0,     0,
       0,     0,     0,   532,     0,     0,     0,     0,  1796,  1797,
    1798,     0,     0,     0,     0,     0,     0,  1804,     0,  1806,
       0,     0,     0,     0,   532,     0,  1809,     0,     0,     0,
       0,     0,     0,     0,     0,  1229,     0,     0,     0,     0,
       0,   531,     0,     0,     0,  1239,     0,  1828,  1829,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1836,  1837,
    1838,     0,     0,     0,     0,     0,     0,     0,     0,  1849,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1859,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1273,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1876,     0,  1281,     0,     0,     0,     0,     0,  1885,  1886,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1303,   615,   616,   617,   618,   619,   620,
     621,   622,   623,   624,   625,   626,   627,   735,   629,   630,
     631,   632,     0,     0,  1915,     0,   633,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   532,  1199,  1200,  1201,  1202,  1203,  1204,
    1205,  1206,  1207,  1208,  1209,  1210,     0,  1212,  1213,  1214,
    1215,     0,  1217,  1218,  1219,  1220,     0,  1932,  1933,  1934,
       0,     0,     0,     0,     0,     0,     0,     0,  1232,     0,
    1234,     0,     0,  1939,     0,     0,     0,     0,  1942,  1943,
       0,  1244,     0,     0,     0,     0,     0,   532,     0,     0,
       0,  1951,     0,     0,  1256,  1257,     0,     0,   531,   531,
    1959,     0,  1960,  1268,     0,     0,     0,     0,  1968,  1969,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   531,     0,     0,
       0,     0,  1457,   531,  1988,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1942,  1943,     0,     0,
    2002,     0,     0,  2006,     0,     0,     0,  2008,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2017,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2024,   532,   532,
       0,     0,     0,     0,     0,     0,  1503,     0,     0,     0,
       0,  2035,     0,     0,     0,     0,  2041,  2042,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2047,     0,     0,  2048,  2047,     0,  2051,     0,     0,     0,
       0,     0,     0,     0,     0,  1373,  1375,  1376,     0,     0,
       0,  1380,  1381,     0,     0,  1384,  1385,  1386,  1387,     0,
    1389,     0,  2070,  2071,  2072,  1395,     0,     0,     0,     0,
       0,     0,     0,   531,   531,     0,     0,     0,     0,     0,
    2082,  2083,     0,     0,     0,     0,     0,     0,     0,   532,
       0,     0,  2091,     0,     0,     0,     0,  1551,  1552,     0,
       0,  2100,     0,     0,     0,     0,     0,     0,     0,     0,
     603,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2112,  2113,     0,     0,   733,   531,     0,
    2342,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1480,     0,  1482,     0,     0,     0,  2356,
    2358,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2366,  2140,  2141,     0,     0,     0,   532,     0,
     532,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2154,     0,     0,     0,  1628,   531,
     531,  2159,     0,     0,     0,     0,  2162,     0,     0,     0,
    2166,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   531,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   531,
       0,     7,     8,     0,     0,     0,     0,     0,  2197,     0,
       0,   531,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1548,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2209,  1684,     0,  1686,
       0,     0,  2214,     0,     0,  2215,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2227,     0,  2228,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1990,     0,     0,     0,     0,
    2242,     0,     0,     0,     0,     0,     0,     0,     0,   532,
       0,     0,     0,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,     0,  2260,  2261,    45,
      46,    47,    48,     0,     0,     0,     0,    50,     0,     0,
       0,     0,  2267,  2268,     0,     0,   810,    59,   531,     0,
      62,   811,     0,   812,   813,     0,   814,     0,     0,     0,
       0,  2279,     0,     0,     0,     0,   531,   531,   531,   531,
     531,     0,     0,     0,     0,    84,  2041,     0,     0,     0,
    2295,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1666,     0,  2088,     0,     0,     0,     0,
       0,     0,   101,   102,   103,     0,     0,     0,  1825,  2315,
       0,     0,  1916,     0,  2318,  2319,     0,     0,  2117,     0,
       0,     0,     0,     0,     0,     0,     0,   531,     0,     0,
       0,     0,     0,     0,     0,     0,  1705,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2346,  2347,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1743,
    1744,  1745,  1746,  1747,  1748,  1749,     0,     0,     0,   836,
    1754,  1755,     0,     0,     0,     0,     0,  1757,     0,     0,
       0,     0,     0,     0,     0,  1764,   532,   532,     0,  1768,
       0,     0,  1770,     0,     0,     0,     0,     0,     0,   178,
     411,     0,     0,  1777,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   532,     0,     0,     0,     0,
       0,   532,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   625,   626,   627,   735,   629,   630,   631,   632,
       0,     0,     0,     0,   633,   412,   413,   414,   415,   416,
     417,   418,   419,   420,     0,     0,     0,     0,   421,   422,
     423,   424,     0,     0,     0,     0,   425,   426,   427,   428,
       0,     0,     0,  2132,     0,   429,     0,   430,     0,     0,
       0,     0,  1844,     0,  1847,  1957,  1958,     0,  1854,     0,
    1856,     7,     8,   431,     0,     0,   432,     0,     0,     0,
     184,  2170,     0,   185,     0,     0,   186,     0,   187,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    48,
    1987,  1879,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   625,   626,   627,   735,   629,   630,   631,   632,
     461,   532,   532,     0,   633,   615,   616,   617,   618,   619,
     620,   621,   622,   623,   624,   625,   626,   627,   735,   629,
     630,   631,   632,     0,     0,     0,     0,   633,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   604,     0,
       0,     0,     0,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,   532,     0,     0,    45,
      46,    47,    48,     0,     0,     0,     0,    50,     0,     0,
       0,     0,     0,   433,   434,   435,   810,    59,     0,     0,
      62,   811,     0,   812,   813,   436,   814,  1944,     0,   437,
    1104,   438,   125,     0,     0,     0,     0,     0,     0,     0,
    2078,  2079,     0,     0,     0,    84,     0,     0,     0,  1105,
       0,     0,     0,     0,     0,     0,     0,   532,   532,     0,
       0,     0,     0,     0,   183,  1878,   189,     0,     0,     0,
       0,     0,   101,   102,   103,     0,     0,     0,     0,     0,
       0,     0,   532,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2116,     0,   532,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   532,
     615,   616,   617,   618,   619,   620,   621,   622,   623,   624,
     625,   626,   627,   735,   629,   630,   631,   632,  2171,     0,
       0,     0,   633,     0,  2032,     0,     0,  2033,   615,   616,
     617,   618,   619,   620,   621,   622,   623,   624,   625,   626,
     627,   735,   629,   630,   631,   632,  2157,  2158,     0,     0,
     633,     0,     0,     0,     0,     0,     0,     0,  2254,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2180,     0,     0,     0,     0,  2067,  2068,   474,     0,
       0,     0,     0,  2074,     0,     0,  2190,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2200,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   532,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   532,   532,   532,   532,   532,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2121,  2122,     0,     0,   539,   540,   541,   542,   543,   544,
     545,   546,   547,   548,   549,   550,   551,   552,   553,   554,
     555,   556,   557,   558,   559,   560,   561,   562,   563,   564,
     567,   568,   569,   570,   571,   572,     0,   574,   575,     0,
       0,     0,     0,     0,     0,   532,     0,   581,   582,  2153,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   596,   597,  2271,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2283,  2284,  2285,  2286,  2288,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   615,   616,   617,   618,   619,
     620,   621,   622,   623,   624,   625,   626,   627,   735,   629,
     630,   631,   632,     0,     0,     0,     0,   633,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2327,   615,   616,   617,   618,   619,
     620,   621,   622,   623,   624,   625,   626,   627,   735,   629,
     630,   631,   632,     0,     0,     0,     0,   633,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   732,     0,     0,     0,     0,     0,     0,   741,   742,
     743,     0,     0,     0,   747,   748,   749,   750,   751,   752,
     753,     0,   754,     0,     0,     0,     0,   755,   756,     0,
       0,   759,   223,     6,   411,     0,     0,     0,     0,   224,
     225,   226,     0,     0,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,     0,     0,     0,  1706,
     413,   414,   415,   416,   417,   418,   419,   420,   259,   260,
     261,   262,   421,   422,   423,   424,   263,   264,     0,     0,
     425,   426,   427,   428,     0,     0,   265,   266,   267,   429,
       0,   430,   268,   269,   270,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   271,    27,   431,   272,     0,
     432,     0,     0,  2336,   273,     0,     0,   274,     0,     0,
     275,     0,   276,     0,     0,     0,     0,     0,     0,    44,
       0,     0,     0,   277,   278,   279,     0,     0,   280,     0,
       0,     0,     0,     0,     0,     0,     0,   281,     0,    60,
      61,     0,   282,     0,   283,     0,     0,   284,     0,     0,
       0,     0,     0,    71,    72,    73,    74,    75,     0,    77,
      78,    79,    80,    81,    82,    83,     0,     0,     0,    87,
       0,     0,     0,    91,     0,     0,   949,     0,   615,   616,
     617,   618,   619,   620,   621,   622,   623,   624,   625,   626,
     627,   735,   629,   630,   631,   632,     0,     0,   285,     0,
     633,  2302,   796,     0,   797,     0,     0,     0,     0,     0,
    1846,     0,     0,     0,     0,     0,   286,   433,   434,   435,
     287,   288,     0,     0,     0,     0,   289,   290,   291,   436,
     292,   293,   294,   437,     0,   438,   125,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   295,   296,     0,     0,     0,     0,     0,
     297,     0,     0,     0,     0,   381,   223,     6,   411,  1707,
       0,     0,   300,   224,   225,   226,     0,     0,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
       0,     0,     0,   412,   413,   414,   415,   416,   417,   418,
     419,   420,   259,   260,   261,   262,   421,   422,   423,   424,
     263,   264,     0,     0,   425,   426,   427,   428,     0,     0,
     265,   266,   267,   429,     0,   430,   268,   269,   270,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   271,
      27,   431,   272,     0,   432,     0,     0,     0,   273,     0,
       0,   274,     0,     0,   275,     0,   276,     0,     0,     0,
       0,     0,     0,    44,     0,     0,     0,   277,   278,   279,
       0,     0,   280,     0,     0,     0,     0,     0,     0,     0,
       0,   281,     0,    60,    61,     0,   282,     0,   283,     0,
       0,   284,     0,     0,     0,     0,     0,    71,    72,    73,
      74,    75,     0,    77,    78,    79,    80,    81,    82,    83,
       0,     0,     0,    87,     0,     0,     0,    91,   615,   616,
     617,   618,   619,   620,   621,   622,   623,   624,   625,   626,
     627,   735,   629,   630,   631,   632,  2220,     0,     0,     0,
     633,     0,   285,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     286,   433,   434,   435,   287,   288,     0,     0,     0,     0,
     289,   290,   291,   436,   292,   293,   294,   437,     0,   438,
     125,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1263,     0,     0,     0,     0,     0,     0,   295,   296,     0,
       0,     0,     0,     0,   297,     0,     0,     0,     0,   381,
       0,     0,     0,   299,     0,     0,   300,   223,   178,   411,
       0,   460,     0,  1280,   224,   225,   226,     0,     0,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   405,   246,   247,
     248,   249,   250,   251,   252,   253,     0,     0,     0,     0,
       0,     0,     0,     0,   412,   413,   414,   415,   416,   417,
     418,   419,   420,   259,   260,   261,   262,   421,   422,   423,
     424,   263,     0,     0,     0,   425,   426,   427,   428,     0,
       0,     0,     0,     0,   429,     0,   430,   268,   269,   270,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     271,    27,   431,   272,     0,   432,     0,     0,     0,   184,
       0,     0,   185,     0,     0,   186,     0,   187,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    48,   615,
     616,   617,   618,   619,   620,   621,   622,   623,   624,   625,
     626,   627,   735,   629,   630,   631,   632,     0,     0,   461,
       0,   633,     0,  1047,     0,     0,     0,     0,     0,     0,
       0,  1007,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   625,   626,   627,   735,   629,   630,   631,   632,
       0,     0,     0,     0,   633,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1472,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   462,     0,     0,     0,     0,     0,
       0,   286,   433,   434,   435,   287,     0,     0,     0,     0,
       0,   289,   290,   291,   436,   292,   293,   294,   437,     0,
     438,   125,     0,   463,   464,   465,   466,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   295,   406,
       0,     0,     0,     0,     0,   297,     0,   467,   468,     0,
     469,     0,   470,     0,     0,     0,   471,   300,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   223,     6,   380,     0,     0,     0,     0,   224,
     225,   226,     0,  1538,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   259,   260,
     261,   262,     0,     0,     0,     0,   263,   264,     0,     0,
       0,     0,     0,     0,     0,     0,   265,   266,   267,     0,
       0,     0,   268,   269,   270,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   271,    27,     0,   272,     0,
       0,     0,     0,     0,   273,     0,     0,   274,     0,     0,
     275,     0,   276,     0,     0,     0,     0,     0,     0,    44,
       0,     0,     0,   277,   278,   279,     0,     0,   280,     0,
       0,     0,     0,     0,     0,     0,     0,   281,     0,    60,
      61,     0,   282,     0,   283,     0,     0,   284,     0,     0,
       0,     0,     0,    71,    72,    73,    74,    75,     0,    77,
      78,    79,    80,    81,    82,    83,     0,     0,     0,    87,
       0,     0,     0,    91,     0,     0,  1667,  1668,   615,   616,
     617,   618,   619,   620,   621,   622,   623,   624,   625,   626,
     627,   735,   629,   630,   631,   632,     0,     0,   285,     0,
     633,     0,     0,     0,     0,     0,  1908,     0,     0,     0,
    1909,     0,     0,     0,     0,     0,   286,     0,   614,     0,
     287,   288,     0,     0,     0,     0,   289,   290,   291,     0,
     292,   293,   294,     0,     0,     0,   125,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   295,   296,     0,     0,     0,     0,     0,
     297,     0,     0,     0,     0,   381,     0,     0,     0,   382,
       0,     0,   300,     0,     0,     0,     0,   223,     6,  1766,
       0,     0,   712,     0,   224,   225,   226,     0,  1773,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   259,   260,   261,   262,     0,     0,     0,
       0,   263,   264,     0,     0,     0,     0,     0,     0,     0,
       0,   265,   266,   267,     0,     0,     0,   268,   269,   270,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     271,    27,     0,   272,     0,     0,     0,     0,     0,   273,
       0,     0,   274,     0,     0,   275,     0,   276,     0,     0,
       0,     0,     0,     0,    44,     0,     0,     0,   277,   278,
     279,     0,     0,   280,     0,     0,     0,     0,     0,     0,
       0,     0,   281,     0,    60,    61,     0,   282,     0,   283,
       0,     0,   284,     0,     0,     0,     0,     0,    71,    72,
      73,    74,    75,     0,    77,    78,    79,    80,    81,    82,
      83,     0,     0,     0,    87,     0,     0,     0,    91,     0,
       0,     0,  1913,   615,   616,   617,   618,   619,   620,   621,
     622,   623,   624,   625,   626,   627,   628,   629,   630,   631,
     632,     0,     0,   285,     0,   633,     0,     0,   614,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   286,     0,     0,     0,   287,   288,     0,     0,     0,
       0,   289,   290,   291,     0,   292,   293,   294,     0,     0,
       0,   125,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   295,   530,
       0,     0,     0,     0,     0,   297,     0,     0,     0,     0,
     381,   223,     6,  1812,     0,   607,     0,   300,   224,   225,
     226,     0,     0,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   259,   260,   261,
     262,     0,     0,     0,     0,   263,   264,     0,     0,     0,
       0,     0,     0,     0,     0,   265,   266,   267,     0,     0,
       0,   268,   269,   270,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   271,    27,     0,   272,     0,     0,
       0,     0,     0,   273,     0,     0,   274,     0,     0,   275,
       0,   276,     0,     0,     0,     0,     0,     0,    44,     0,
       0,     0,   277,   278,   279,     0,     0,   280,     0,     0,
       0,     0,     0,     0,     0,     0,   281,     0,    60,    61,
       0,   282,     0,   283,     0,     0,   284,     0,     0,     0,
       0,     0,    71,    72,    73,    74,    75,     0,    77,    78,
      79,    80,    81,    82,    83,     0,     0,     0,    87,     0,
       0,     0,    91,   615,   616,   617,   618,   619,   620,   621,
     622,   623,   624,   625,   626,   627,   872,   629,   630,   631,
     632,     0,     0,     0,     0,   633,     0,   285,     0,     0,
       0,     0,  1063,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   286,     0,     0,     0,   287,
     288,     0,     0,     0,     0,   289,   290,   291,     0,   292,
     293,   294,     0,     0,     0,   125,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   295,   296,     0,     0,     0,     0,     0,   297,
       0,     0,     0,     0,   381,   223,     6,     0,   299,     0,
       0,   300,   224,   225,   226,     0,     0,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   259,   260,   261,   262,     0,     0,     0,     0,   263,
     264,     0,     0,     0,     0,     0,     0,     0,     0,   265,
     266,   267,     0,     0,     0,   268,   269,   270,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   271,    27,
       0,   272,     0,     0,     0,     0,     0,   273,     0,     0,
     274,     0,     0,   275,     0,   276,     0,     0,     0,     0,
       0,     0,    44,     0,     0,     0,   277,   278,   279,     0,
       0,   280,     0,     0,     0,     0,     0,     0,     0,     0,
     281,     0,    60,    61,     0,   282,     0,   283,     0,     0,
     284,     0,     0,     0,     0,     0,    71,    72,    73,    74,
      75,     0,    77,    78,    79,    80,    81,    82,    83,     0,
       0,     0,    87,     0,     0,     0,    91,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   624,   625,   626,   627,
     735,   629,   630,   631,   632,     0,     0,     0,     0,   633,
       0,   285,     0,     0,     0,     0,  1271,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   286,
       0,     0,     0,   287,   288,     0,     0,     0,     0,   289,
     290,   291,     0,   292,   293,   294,     0,     0,     0,   125,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   675,  1983,     0,     0,
       0,     0,     0,   297,     0,     0,     0,     0,   677,   223,
       6,     0,   343,   607,     0,   300,   224,   225,   226,     0,
       0,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   259,   260,   261,   262,     0,
       0,     0,     0,   263,   264,     0,     0,     0,     0,     0,
       0,     0,     0,   265,   266,   267,     0,     0,     0,   268,
     269,   270,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   271,    27,     0,   272,     0,     0,     0,     0,
       0,   273,     0,     0,   274,     0,     0,   275,     0,   276,
       0,     0,     0,     0,     0,     0,    44,     0,     0,     0,
     277,   278,   279,     0,     0,   280,     0,     0,     0,     0,
       0,     0,     0,     0,   281,     0,    60,    61,     0,   282,
       0,   283,     0,     0,   284,     0,     0,     0,     0,     0,
      71,    72,    73,    74,    75,     0,    77,    78,    79,    80,
      81,    82,    83,     0,     0,     0,    87,     0,     0,     0,
      91,   615,   616,   617,   618,   619,   620,   621,   622,   623,
     624,   625,   626,   627,   735,   629,   630,   631,   632,     0,
       0,     0,     0,   633,     0,   285,     0,     0,     0,     0,
    1272,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   286,     0,     0,     0,   287,   288,     0,
       0,     0,     0,   289,   290,   291,     0,   292,   293,   294,
       0,     0,     0,   125,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     295,   296,     0,     0,     0,     0,     0,   297,     0,     0,
       0,     0,   298,   223,     6,     0,   299,     0,     0,   300,
     224,   225,   226,     0,     0,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   259,
     260,   261,   262,     0,     0,     0,     0,   263,   264,     0,
       0,     0,     0,     0,     0,     0,     0,   265,   266,   267,
       0,     0,     0,   268,   269,   270,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   271,    27,     0,   272,
       0,     0,     0,     0,     0,   273,     0,     0,   274,     0,
       0,   275,     0,   276,     0,     0,     0,     0,     0,     0,
      44,     0,     0,     0,   277,   278,   279,     0,     0,   280,
       0,     0,     0,     0,     0,     0,     0,     0,   281,     0,
      60,    61,     0,   282,     0,   283,     0,     0,   284,     0,
       0,     0,     0,     0,    71,    72,    73,    74,    75,     0,
      77,    78,    79,    80,    81,    82,    83,     0,     0,     0,
      87,     0,     0,     0,    91,   615,   616,   617,   618,   619,
     620,   621,   622,   623,   624,   625,   626,   627,   735,   629,
     630,   631,   632,     0,     0,     0,     0,   633,     0,   285,
       0,     0,     0,     0,  1622,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   286,     0,     0,
       0,   287,   288,     0,     0,     0,     0,   289,   290,   291,
       0,   292,   293,   294,     0,     0,     0,   125,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   295,   296,     0,     0,     0,     0,
       0,   297,     0,     0,     0,     0,   381,   223,     6,     0,
     299,     0,     0,   300,   224,   225,   226,     0,     0,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   259,   260,   261,   262,     0,     0,     0,
       0,   263,   264,     0,     0,     0,     0,     0,     0,     0,
       0,   265,   266,   267,     0,     0,     0,   268,   269,   270,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     271,    27,     0,   272,     0,     0,     0,     0,     0,   273,
       0,     0,   274,     0,     0,   275,     0,   276,     0,     0,
       0,     0,     0,     0,    44,     0,     0,     0,   277,   278,
     279,     0,     0,   280,     0,     0,     0,     0,     0,     0,
       0,     0,   281,     0,    60,    61,     0,   282,     0,   283,
       0,     0,   284,     0,     0,     0,     0,     0,    71,    72,
      73,    74,    75,     0,    77,    78,    79,    80,    81,    82,
      83,     0,     0,     0,    87,     0,     0,     0,    91,   615,
     616,   617,   618,   619,   620,   621,   622,   623,   624,   625,
     626,   627,   735,   629,   630,   631,   632,     0,     0,     0,
       0,   633,     0,   285,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   286,     0,     0,     0,   287,   288,     0,     0,     0,
       0,   289,   290,   291,     0,   292,   293,   294,     0,     0,
       0,   125,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   295,   530,
       0,     0,     0,     0,     0,   297,     0,     0,     0,     0,
     381,   223,     6,     0,   602,     0,     0,   300,   224,   225,
     226,     0,     0,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   259,   260,   261,
     262,     0,     0,     0,     0,   263,   264,     0,     0,     0,
       0,     0,     0,     0,     0,   265,   266,   267,     0,     0,
       0,   268,   269,   270,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   271,    27,     0,   272,     0,     0,
       0,     0,     0,   273,     0,     0,   274,     0,     0,   275,
       0,   276,     0,     0,     0,     0,     0,     0,    44,     0,
       0,     0,   277,   278,   279,     0,     0,   280,     0,     0,
       0,     0,     0,     0,     0,     0,   281,     0,    60,    61,
       0,   282,     0,   283,     0,     0,   284,     0,     0,     0,
       0,     0,    71,    72,    73,    74,    75,     0,    77,    78,
      79,    80,    81,    82,    83,     0,     0,     0,    87,     0,
       0,     0,    91,   615,   616,   617,   618,   619,   620,   621,
     622,   623,   624,   625,   626,   627,   735,   629,   630,   631,
     632,     0,     0,     0,     0,   633,     0,   285,     0,     0,
       0,  1964,     0,     0,     0,  1965,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   286,     0,     0,     0,   287,
     288,     0,     0,     0,     0,   289,   290,   291,     0,   292,
     293,   294,     0,     0,     0,   125,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   295,   530,     0,     0,     0,     0,     0,   297,
       0,     0,     0,     0,   381,   223,     6,     0,     0,   607,
       0,   300,   224,   225,   226,     0,     0,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   259,   260,   261,   262,     0,     0,     0,     0,   263,
     264,     0,     0,     0,     0,     0,     0,     0,     0,   265,
     266,   267,     0,     0,     0,   268,   269,   270,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   271,    27,
       0,   272,     0,     0,     0,     0,     0,   273,     0,     0,
     274,     0,     0,   275,     0,   276,     0,     0,     0,     0,
       0,     0,    44,     0,     0,     0,   277,   278,   279,     0,
       0,   280,     0,     0,     0,     0,     0,     0,     0,     0,
     281,     0,    60,    61,     0,   282,     0,   283,     0,     0,
     284,     0,     0,     0,     0,     0,    71,    72,    73,    74,
      75,     0,    77,    78,    79,    80,    81,    82,    83,     0,
       0,     0,    87,     0,     0,     0,    91,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   624,   625,   626,   627,
     735,   629,   630,   631,   632,     0,     0,     0,     0,   633,
       0,   285,     0,     0,     0,  1995,     0,     0,     0,  1996,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   286,
       0,     0,     0,   287,   288,     0,     0,     0,     0,   289,
     290,   291,     0,   292,   293,   294,     0,     0,     0,   125,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   295,   296,     0,     0,
       0,     0,     0,   297,     0,     0,     0,     0,   645,   223,
       6,     0,   299,     0,     0,   300,   224,   225,   226,     0,
       0,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   259,   260,   261,   262,     0,
       0,     0,     0,   263,   264,     0,     0,     0,     0,     0,
       0,     0,     0,   265,   266,   267,     0,     0,     0,   268,
     269,   270,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   271,    27,     0,   272,     0,     0,     0,     0,
       0,   273,     0,     0,   274,     0,     0,   275,     0,   276,
       0,     0,     0,     0,     0,     0,    44,     0,     0,     0,
     277,   278,   279,     0,     0,   280,     0,     0,     0,     0,
       0,     0,     0,     0,   281,     0,    60,    61,     0,   282,
       0,   283,     0,     0,   284,     0,     0,     0,     0,     0,
      71,    72,    73,    74,    75,     0,    77,    78,    79,    80,
      81,    82,    83,     0,     0,     0,    87,     0,     0,     0,
      91,   615,   616,   617,   618,   619,   620,   621,   622,   623,
     624,   625,   626,   627,   735,   629,   630,   631,   632,     0,
       0,     0,     0,   633,     0,   285,     0,     0,     0,  2182,
       0,     0,     0,  2183,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   286,     0,     0,     0,   287,   288,     0,
       0,     0,     0,   289,   290,   291,     0,   292,   293,   294,
       0,     0,     0,   125,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     295,   296,     0,     0,     0,     0,     0,   297,     0,     0,
       0,     0,   654,   223,     6,     0,   299,     0,     0,   300,
     224,   225,   226,     0,     0,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   259,
     260,   261,   262,     0,     0,     0,     0,   263,   264,     0,
       0,     0,     0,     0,     0,     0,     0,   265,   266,   267,
       0,     0,     0,   268,   269,   270,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   271,    27,     0,   272,
       0,     0,     0,     0,     0,   273,     0,     0,   274,     0,
       0,   275,     0,   276,     0,     0,     0,     0,     0,     0,
      44,     0,     0,     0,   277,   278,   279,     0,     0,   280,
       0,     0,     0,     0,     0,     0,     0,     0,   281,     0,
      60,    61,     0,   282,     0,   283,     0,     0,   284,     0,
       0,     0,     0,     0,    71,    72,    73,    74,    75,     0,
      77,    78,    79,    80,    81,    82,    83,     0,     0,     0,
      87,     0,     0,     0,    91,   615,   616,   617,   618,   619,
     620,   621,   622,   623,   624,   625,   626,   627,   735,   629,
     630,   631,   632,     0,     0,     0,     0,   633,     0,   285,
       0,     0,     0,     0,     0,     0,     0,   829,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   286,     0,     0,
       0,   287,   288,     0,     0,     0,     0,   289,   290,   291,
       0,   292,   293,   294,     0,     0,     0,   125,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   295,   530,     0,     0,     0,     0,
       0,   297,     0,     0,     0,     0,   381,   223,     6,     0,
     966,     0,  1456,   300,   224,   225,   226,     0,     0,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   259,   260,   261,   262,     0,     0,     0,
       0,   263,   264,     0,     0,     0,     0,     0,     0,     0,
       0,   265,   266,   267,     0,     0,     0,   268,   269,   270,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     271,    27,     0,   272,     0,     0,     0,     0,     0,   273,
       0,     0,   274,     0,     0,   275,     0,   276,     0,     0,
       0,     0,     0,     0,    44,     0,     0,     0,   277,   278,
     279,     0,     0,   280,     0,     0,     0,     0,     0,     0,
       0,     0,   281,     0,    60,    61,     0,   282,     0,   283,
       0,     0,   284,     0,     0,     0,     0,     0,    71,    72,
      73,    74,    75,     0,    77,    78,    79,    80,    81,    82,
      83,     0,     0,     0,    87,     0,     0,     0,    91,   615,
     616,   617,   618,   619,   620,   621,   622,   623,   624,   625,
     626,   627,   735,   629,   630,   631,   632,     0,     0,     0,
       0,   633,     0,   285,     0,     0,     0,     0,     0,     0,
       0,   835,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   286,     0,     0,     0,   287,   288,     0,     0,     0,
       0,   289,   290,   291,     0,   292,   293,   294,     0,     0,
       0,   125,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   295,   530,
       0,     0,     0,     0,     0,   297,   223,     6,     0,     0,
     381,  1683,     0,   224,   225,   226,     0,   300,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   259,   260,   261,   262,     0,     0,     0,     0,
     263,   264,     0,     0,     0,     0,     0,     0,     0,     0,
     265,   266,   267,     0,     0,     0,   268,   269,   270,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   271,
      27,     0,   272,     0,     0,     0,     0,     0,   273,     0,
       0,   274,     0,     0,   275,     0,   276,     0,     0,     0,
       0,     0,     0,    44,     0,     0,     0,   277,   278,   279,
       0,     0,   280,     0,     0,     0,     0,     0,     0,     0,
       0,   281,     0,    60,    61,     0,   282,     0,   283,     0,
       0,   284,     0,     0,     0,     0,     0,    71,    72,    73,
      74,    75,     0,    77,    78,    79,    80,    81,    82,    83,
       0,     0,     0,    87,     0,     0,     0,    91,   615,   616,
     617,   618,   619,   620,   621,   622,   623,   624,   625,   626,
     627,   735,   629,   630,   631,   632,     0,     0,     0,     0,
     633,     0,   285,     0,     0,     0,     0,     0,     0,     0,
     837,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     286,     0,     0,     0,   287,   288,     0,     0,     0,     0,
     289,   290,   291,     0,   292,   293,   294,     0,     0,     0,
     125,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   295,   530,     0,
       0,     0,     0,     0,   297,   223,     6,     0,     0,   381,
       0,     0,   224,   225,   226,     0,   300,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   259,   260,   261,   262,     0,     0,     0,     0,   263,
     264,     0,     0,     0,     0,     0,     0,     0,     0,   265,
     266,   267,     0,     0,     0,   268,   269,   270,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   271,    27,
       0,   272,     0,     0,     0,     0,     0,   273,     0,     0,
     274,     0,     0,   275,     0,   276,     0,     0,     0,     0,
       0,     0,    44,     0,     0,     0,   277,   278,   279,     0,
       0,   280,     0,     0,     0,     0,     0,     0,     0,     0,
     281,     0,    60,    61,     0,   282,     0,   283,     0,     0,
     284,     0,     0,     0,     0,     0,    71,    72,    73,    74,
      75,     0,    77,    78,    79,    80,    81,    82,    83,     0,
       0,     0,    87,     0,     0,     0,    91,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   624,   625,   626,   627,
     735,   629,   630,   631,   632,     0,     0,     0,     0,   633,
       0,   285,     0,     0,     0,     0,     0,     0,     0,  1007,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   286,
       0,     0,     0,   287,   288,     0,     0,     0,     0,   289,
     290,   291,     0,   292,   293,   294,     0,     0,     0,   125,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   295,   296,     0,     0,
       0,     0,     0,   297,     0,     0,     0,     0,   381,   223,
       6,     0,  1820,     0,     0,   300,   224,   225,   226,     0,
       0,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   259,   260,   261,   262,     0,
       0,     0,     0,   263,   264,     0,     0,     0,     0,     0,
       0,     0,     0,   265,   266,   267,     0,     0,     0,   268,
     269,   270,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   271,    27,     0,   272,     0,     0,     0,     0,
       0,   273,     0,     0,   274,     0,     0,   275,     0,   276,
       0,     0,     0,     0,     0,     0,    44,     0,     0,     0,
     277,   278,   279,     0,     0,   280,     0,     0,     0,     0,
       0,     0,     0,     0,   281,     0,    60,    61,     0,   282,
       0,   283,     0,     0,   284,     0,     0,     0,     0,     0,
      71,    72,    73,    74,    75,     0,    77,    78,    79,    80,
      81,    82,    83,     0,     0,     0,    87,     0,     0,     0,
      91,   615,   616,   617,   618,   619,   620,   621,   622,   623,
     624,   625,   626,   627,   735,   629,   630,   631,   632,     0,
       0,     0,     0,   633,     0,   285,     0,     0,     0,     0,
       0,     0,     0,  1008,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   286,     0,     0,     0,   287,   288,     0,
       0,     0,     0,   289,   290,   291,     0,   292,   293,   294,
       0,     0,     0,   125,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     675,  1983,     0,     0,     0,     0,     0,   297,     0,     0,
       0,     0,   677,   223,     6,     0,   343,     0,     0,   300,
     224,   225,   226,     0,     0,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   259,
     260,   261,   262,     0,     0,     0,     0,   263,   264,     0,
       0,     0,     0,     0,     0,     0,     0,   265,   266,   267,
       0,     0,     0,   268,   269,   270,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   271,    27,     0,   272,
       0,     0,     0,     0,     0,   273,     0,     0,   274,     0,
       0,   275,     0,   276,     0,     0,     0,     0,     0,     0,
      44,     0,     0,     0,   277,   278,   279,     0,     0,   280,
       0,     0,     0,     0,     0,     0,     0,     0,   281,     0,
      60,    61,     0,   282,     0,   283,     0,     0,   284,     0,
       0,     0,     0,     0,    71,    72,    73,    74,    75,     0,
      77,    78,    79,    80,    81,    82,    83,     0,     0,     0,
      87,     0,     0,     0,    91,   615,   616,   617,   618,   619,
     620,   621,   622,   623,   624,   625,   626,   627,   735,   629,
     630,   631,   632,     0,     0,     0,     0,   633,     0,   285,
       0,     0,     0,     0,     0,     0,     0,  1060,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   286,     0,     0,
       0,   287,   288,     0,     0,     0,     0,   289,   290,   291,
       0,   292,   293,   294,     0,     0,     0,   125,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   295,   530,     0,     0,     0,     0,
       0,   297,     0,     0,     0,     0,   381,   223,     6,     0,
       0,  2115,     0,   300,   224,   225,   226,     0,     0,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   259,   260,   261,   262,     0,     0,     0,
       0,   263,   264,     0,     0,     0,     0,     0,     0,     0,
       0,   265,   266,   267,     0,     0,     0,   268,   269,   270,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     271,    27,     0,   272,     0,     0,     0,     0,     0,   273,
       0,     0,   274,     0,     0,   275,     0,   276,     0,     0,
       0,     0,     0,     0,    44,     0,     0,     0,   277,   278,
     279,     0,     0,   280,     0,     0,     0,     0,     0,     0,
       0,     0,   281,     0,    60,    61,     0,   282,     0,   283,
       0,     0,   284,     0,     0,     0,     0,     0,    71,    72,
      73,    74,    75,     0,    77,    78,    79,    80,    81,    82,
      83,     0,     0,     0,    87,     0,     0,     0,    91,   615,
     616,   617,   618,   619,   620,   621,   622,   623,   624,   625,
     626,   627,   735,   629,   630,   631,   632,     0,     0,     0,
       0,   633,     0,   285,     0,     0,     0,     0,     0,     0,
       0,  1170,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   286,     0,     0,     0,   287,   288,     0,     0,     0,
       0,   289,   290,   291,     0,   292,   293,   294,     0,     0,
       0,   125,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   295,   530,
       0,     0,     0,     0,     0,   297,   223,   178,   411,     0,
     381,     0,     0,   224,   225,   226,     0,   300,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   405,   246,   247,   248,
     249,   250,   251,   252,   253,     0,     0,     0,     0,     0,
       0,     0,     0,   412,   413,   414,   415,   416,   417,   418,
     419,   420,   259,   260,   261,   262,   421,   422,   423,   424,
     263,     0,     0,     0,   425,   426,   427,   428,     0,     0,
       0,     0,     0,   429,     0,   430,   268,   269,   270,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   271,
      27,   431,   272,     0,   432,   223,   178,   411,     0,     0,
       0,     0,   224,   225,   226,     0,     0,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   405,   246,   247,   248,   249,
     250,   251,   252,   253,     0,     0,     0,     0,     0,     0,
       0,     0,   412,   413,   414,   415,   416,   417,   418,   419,
     420,   259,   260,   261,   262,   421,   422,   423,   424,   263,
       0,     0,     0,   425,   426,   427,   428,     0,     0,     0,
       0,     0,   429,     0,   430,   268,   269,   270,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   271,    27,
     431,   272,     0,   432,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     286,   433,   434,   435,   287,     0,     0,     0,     0,     0,
     289,   290,   291,   436,   292,   293,   294,   437,     0,   438,
     125,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   295,   406,     0,
       0,     0,     0,     0,   297,     0,     0,     0,     0,   381,
       0,     0,     0,  1702,     0,     0,   300,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   624,   625,   626,   627,
     735,   629,   630,   631,   632,     0,     0,     0,     0,   633,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1211,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   286,
     433,   434,   435,   287,     0,     0,     0,     0,     0,   289,
     290,   291,   436,   292,   293,   294,   437,     0,   438,   125,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   295,  2000,     0,     0,
       0,     0,     0,   297,     0,     0,     0,     0,   381,   223,
     178,   411,  2001,     0,     0,   300,   224,   225,   226,     0,
       0,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   405,
     246,   247,   248,   249,   250,   251,   252,   253,     0,     0,
       0,     0,     0,     0,     0,     0,  1706,   413,   414,   415,
     416,   417,   418,   419,   420,   259,   260,   261,   262,   421,
     422,   423,   424,   263,     0,     0,     0,   425,   426,   427,
     428,     0,     0,     0,     0,     0,   429,     0,   430,   268,
     269,   270,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   271,    27,   431,   272,     0,   432,   223,   178,
     411,     0,     0,     0,     0,   224,   225,   226,     0,     0,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   405,   246,
     247,   248,   249,   250,   251,   252,   253,     0,     0,     0,
       0,     0,     0,     0,     0,   412,   413,   414,   415,   416,
     417,   418,   419,   420,   259,   260,   261,   262,   421,   422,
     423,   424,   263,     0,     0,     0,   425,   426,   427,   428,
       0,     0,     0,     0,     0,   429,     0,   430,   268,   269,
     270,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   271,    27,   431,   272,     0,   432,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   286,   433,   434,   435,   287,     0,     0,
       0,     0,     0,   289,   290,   291,   436,   292,   293,   294,
     437,     0,   438,   125,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     295,   406,     0,     0,     0,     0,     0,   297,     0,     0,
       0,     0,   381,     0,     0,     0,  1878,     0,     0,   300,
     615,   616,   617,   618,   619,   620,   621,   622,   623,   624,
     625,   626,   627,   735,   629,   630,   631,   632,     0,     0,
       0,     0,   633,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1221,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   286,   433,   434,   435,   287,     0,     0,     0,
       0,     0,   289,   290,   291,   436,   292,   293,   294,   437,
       0,   438,   125,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   295,
     406,     0,     0,     0,     0,     0,   297,   223,   178,     0,
     404,   381,     0,     0,   224,   225,   226,     0,   300,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   405,   246,   247,
     248,   249,   250,   251,   252,   253,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   259,   260,   261,   262,     0,     0,     0,
       0,   263,     7,     8,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   268,   269,   270,
       0,     0,     0,     0,     0,     0,     0,   223,   178,     0,
     271,    27,     0,   272,   224,   225,   226,     0,     0,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   405,   246,   247,
     248,   249,   250,   251,   252,   253,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   259,   260,   261,   262,     0,     0,     0,
       0,   263,     0,     0,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,   268,   269,   270,
      45,    46,    47,    48,     0,     0,     0,     0,    50,     0,
     271,    27,     0,   272,     0,     0,     0,   810,    59,     0,
       0,    62,   811,     0,   812,   813,     0,   814,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   286,     0,     0,     0,   287,    84,     0,     0,     0,
       0,   289,   290,   291,     0,   292,   293,   294,     0,     0,
       0,   125,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   101,   102,   103,     0,     0,   295,   406,
       0,     0,     0,     0,     0,   297,     0,     0,     0,     0,
     381,     0,     0,     0,     0,     0,     0,   300,   615,   616,
     617,   618,   619,   620,   621,   622,   623,   624,   625,   626,
     627,   735,   629,   630,   631,   632,     0,     0,     0,     0,
     633,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1222,   286,     0,     0,     0,   287,     0,     0,     0,     0,
       0,   289,   290,   291,     0,   292,   293,   294,     0,     0,
    1015,   125,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   295,   406,
       0,     0,     0,     0,     0,   297,     0,     0,     0,     0,
     381,   223,   178,     0,   657,     0,     0,   300,   224,   225,
     226,     0,     0,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   405,   246,   247,   248,   249,   250,   251,   252,   253,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   259,   260,   261,
     262,     0,     0,     0,     0,   263,     7,     8,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   268,   269,   270,     0,     0,     0,     0,     0,     0,
       0,   223,   178,     0,   271,    27,   928,   272,   224,   225,
     226,     0,     0,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   405,   246,   247,   248,   249,   250,   251,   252,   253,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   259,   260,   261,
     262,     0,     0,     0,     0,   263,     0,     0,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,   268,   269,   270,    45,    46,    47,    48,     0,     0,
       0,     0,    50,     0,   271,    27,     0,   272,     0,     0,
       0,   810,    59,     0,     0,    62,   811,     0,   812,   813,
       0,   814,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   286,     0,     0,     0,   287,
      84,     0,     0,     0,     0,   289,   290,   291,     0,   292,
     293,   294,     0,     0,     0,   125,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   101,   102,   103,
       0,     0,   675,   676,     0,     0,     0,     0,     0,   297,
       0,     0,     0,     0,   677,     0,     0,     0,   343,     0,
       0,   300,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   625,   626,   627,   735,   629,   630,   631,   632,
       0,     0,     0,     0,   633,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1223,   286,     0,     0,     0,   287,
       0,     0,     0,     0,     0,   289,   290,   291,     0,   292,
     293,   294,     0,     0,  1041,   125,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   295,   406,     0,     0,     0,     0,     0,   297,
     223,   178,     0,     0,   381,     0,     0,   224,   225,   226,
       0,   300,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     405,   246,   247,   248,   249,   250,   251,   252,   253,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   259,   260,   261,   262,
       0,     0,     0,     0,   263,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     268,   269,   270,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   271,    27,     0,   272,   223,   178,     0,
    1407,     0,     0,     0,   224,   225,   226,     0,     0,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   405,   246,   247,
     248,   249,   250,   251,   252,   253,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   259,   260,   261,   262,     0,     0,     0,
       0,   263,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   268,   269,   270,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     271,    27,     0,   272,     0,   615,   616,   617,   618,   619,
     620,   621,   622,   623,   624,   625,   626,   627,   735,   629,
     630,   631,   632,     0,   286,     0,     0,   633,   287,     0,
       0,     0,     0,     0,   289,   290,   291,  1224,   292,   293,
     294,     0,     0,     0,   125,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   295,   406,     0,     0,     0,     0,     0,   297,     0,
       0,     0,     0,   381,  1158,     0,     0,     0,     0,     0,
     300,   615,   616,   617,   618,   619,   620,   621,   622,   623,
     624,   625,   626,   627,   735,   629,   630,   631,   632,     0,
       0,     0,     0,   633,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1225,     0,     0,     0,     0,     0,     0,
       0,   286,     0,     0,     0,   287,     0,     0,     0,     0,
       0,   289,   290,   291,     0,   292,   293,   294,     0,     0,
       0,   125,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   295,   406,
       0,     0,     0,     0,     0,   297,   223,   178,     0,  1578,
     381,     0,     0,   224,   225,   226,     0,   300,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   405,   246,   247,   248,
     249,   250,   251,   252,   253,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   259,   260,   261,   262,     0,     0,     0,     0,
     263,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   268,   269,   270,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   271,
      27,     0,   272,   223,   178,     0,  1645,     0,     0,     0,
     224,   225,   226,     0,     0,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   405,   246,   247,   248,   249,   250,   251,
     252,   253,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   259,
     260,   261,   262,     0,     0,     0,     0,   263,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   268,   269,   270,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   271,    27,     0,   272,
       0,   615,   616,   617,   618,   619,   620,   621,   622,   623,
     624,   625,   626,   627,   735,   629,   630,   631,   632,     0,
     286,     0,     0,   633,   287,     0,     0,     0,     0,     0,
     289,   290,   291,  1230,   292,   293,   294,     0,     0,     0,
     125,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   295,   406,     0,
       0,     0,     0,     0,   297,     0,   223,   178,     0,   381,
       0,     0,     0,   224,   225,   226,   300,     0,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   405,   246,   247,   248,
     249,   250,   251,   252,   253,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   286,     0,     0,
       0,   287,   259,   260,   261,   262,     0,   289,   290,   291,
     263,   292,   293,   294,     0,     0,     0,   125,     0,     0,
       0,     0,     0,     0,     0,     0,   268,   269,   270,     0,
       0,     0,     0,     0,   295,   406,     0,     0,     0,   271,
      27,   297,   272,   223,   178,     0,   381,     0,     0,     0,
     224,   225,   226,   300,     0,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   405,   246,   247,   248,   249,   250,   251,
     252,   253,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   259,
     260,   261,   262,     0,     0,     0,     0,   263,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   268,   269,   270,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   271,    27,     0,   272,
       0,   615,   616,   617,   618,   619,   620,   621,   622,   623,
     624,   625,   626,   627,   735,   629,   630,   631,   632,     0,
     286,     0,     0,   633,   287,     0,     0,     0,     0,     0,
     289,   290,   291,  1231,   292,   293,   294,     0,     0,     0,
     125,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   295,   406,     0,
       0,     0,     0,     0,   297,     0,   223,   178,     0,   381,
    1699,     0,     0,   224,   225,   226,   300,     0,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   405,   246,   247,   248,
     249,   250,   251,   252,   253,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   286,     0,     0,
       0,   287,   259,   260,   261,   262,     0,   289,   290,   291,
     263,   292,   293,   294,     0,     0,     0,   125,     0,     0,
       0,     0,     0,     0,     0,     0,   268,   269,   270,     0,
       0,     0,     0,     0,   295,   406,     0,     0,     0,   271,
      27,   297,   272,   223,   178,     0,   381,  2049,     0,     0,
     224,   225,   226,   300,     0,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   405,   246,   247,   248,   249,   250,   251,
     252,   253,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   259,
     260,   261,   262,     0,     0,     0,     0,   263,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   268,   269,   270,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   271,    27,     0,   272,
       0,   615,   616,   617,   618,   619,   620,   621,   622,   623,
     624,   625,   626,   627,   735,   629,   630,   631,   632,     0,
     286,     0,     0,   633,   287,     0,     0,     0,     0,     0,
     289,   290,   291,  1233,   292,   293,   294,     0,     0,     0,
     125,     0,     0,     0,     0,     0,     0,     0,     0,     7,
       8,     0,     0,     0,     0,     0,     0,   295,   406,     0,
       0,     0,     0,     0,   297,     0,     0,     0,     0,   381,
       0,     0,     0,  2114,     0,     0,   300,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   624,   625,   626,   627,
     735,   629,   630,   631,   632,     0,     0,     0,     0,   633,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1357,
       0,     0,     7,     8,     0,     0,     0,   286,     0,     0,
       0,   287,     0,     0,     0,     0,     0,   289,   290,   291,
       0,   292,   293,   294,     0,     0,     0,   125,     0,     0,
       0,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,   295,   406,     0,    45,    46,    47,
      48,   297,     0,     0,     0,    50,   381,     0,     0,     0,
       0,     0,     0,   300,   810,    59,     7,     8,    62,   811,
       0,   812,   813,     0,   814,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    84,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,     0,     0,     0,
      45,    46,    47,    48,     0,     0,     0,     0,    50,     0,
     101,   102,   103,     0,     0,     0,     0,   810,    59,     7,
       8,    62,   811,     0,   812,   813,     0,   814,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    84,     0,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,     0,     0,     0,    45,    46,    47,    48,     0,     0,
       0,     0,    50,   101,   102,   103,     0,     0,     0,     0,
       0,   810,    59,     7,     8,    62,   811,  1096,   812,   813,
       0,   814,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      84,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,     0,     0,     0,    45,    46,    47,
      48,     0,     0,     0,     0,    50,     0,   101,   102,   103,
       0,     0,     0,     0,   810,    59,     7,     8,    62,   811,
    1098,   812,   813,     0,   814,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    84,     0,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,     0,     0,
       0,    45,    46,    47,    48,     0,     0,     0,     0,    50,
     101,   102,   103,     0,     0,     0,     0,     0,   810,    59,
       7,     8,    62,   811,  1305,   812,   813,     0,   814,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    84,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,     0,     0,     0,    45,    46,    47,    48,     0,     0,
       0,     0,    50,     0,   101,   102,   103,     0,     0,     0,
       0,   810,    59,     7,     8,    62,   811,  1307,   812,   813,
       0,   814,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      84,     0,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,     0,     0,     0,    45,    46,
      47,    48,     0,     0,     0,     0,    50,   101,   102,   103,
       0,     0,     0,     0,     0,   810,    59,     7,     8,    62,
     811,  1308,   812,   813,     0,   814,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    84,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,     0,     0,
       0,    45,    46,    47,    48,     0,     0,     0,     0,    50,
       0,   101,   102,   103,     0,     0,     0,     0,   810,    59,
       7,     8,    62,   811,  1327,   812,   813,     0,   814,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    84,     0,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,     0,     0,     0,    45,    46,    47,    48,     0,
       0,     0,     0,    50,   101,   102,   103,     0,     0,     0,
       0,     0,   810,    59,     7,     8,    62,   811,  1347,   812,
     813,     0,   814,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    84,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,     0,     0,     0,    45,    46,
      47,    48,     0,     0,     0,     0,    50,     0,   101,   102,
     103,     0,     0,     0,     0,   810,    59,     7,     8,    62,
     811,  1365,   812,   813,     0,   814,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    84,     0,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,     0,
       0,     0,    45,    46,    47,    48,     0,     0,     0,     0,
      50,   101,   102,   103,     0,     0,     0,     0,     0,   810,
      59,     0,     0,    62,   811,  1402,   812,   813,     0,   814,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    84,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,     0,     0,     0,    45,    46,    47,    48,     0,
       0,     0,     0,    50,     0,   101,   102,   103,     0,     0,
       0,     0,   810,    59,     0,     0,    62,   811,  1570,   812,
     813,     0,   814,     0,     0,     0,    -4,     1,     0,     0,
      -4,     0,     0,     0,     0,     0,     0,     0,     0,    -4,
      -4,    84,     0,     0,   615,   616,   617,   618,   619,   620,
     621,   622,   623,   624,   625,   626,   627,   735,   629,   630,
     631,   632,     0,     0,     0,     0,   633,     0,   101,   102,
     103,     0,     0,    -4,    -4,    -4,  1383,     0,     0,     0,
       0,     0,  2245,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    -4,    -4,    -4,     0,     0,     0,
       0,    -4,    -4,     0,     0,     0,     0,    -4,     0,     0,
       0,     0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,
      -4,    -4,     0,    -4,     0,     0,     0,     0,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,     0,  2304,    -4,    -4,    -4,    -4,
      -4,     0,     0,    -4,     0,    -4,     0,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,     0,     0,    -4,    -4,    -4,     0,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,     0,     0,     0,    -4,    -4,
      -4,     0,     0,     0,    -4,     0,     0,     0,     0,    -4,
      -4,    -4,    -4,     0,     0,    -4,     0,    -4,     0,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,     0,     6,     0,     0,     0,     0,    -4,
      -4,    -4,    -4,     7,     8,     0,     0,     0,     0,     0,
       0,    -4,     0,    -4,    -4,     0,     0,     0,   615,   616,
     617,   618,   619,   620,   621,   622,   623,   624,   625,   626,
     627,   735,   629,   630,   631,   632,     0,     9,    10,    11,
     633,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1466,     0,     0,     0,     0,     0,     0,     0,    12,    13,
      14,     0,     0,     0,     0,    15,    16,     0,     0,     0,
       0,    17,     0,     0,     0,     0,    18,    19,    20,    21,
      22,    23,    24,     0,    25,    26,     0,    27,     0,     0,
       0,     0,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,     0,     0,
      44,    45,    46,    47,    48,     0,     0,    49,     0,    50,
       0,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,     0,     0,
      68,    69,    70,     0,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,     0,
       0,     0,    96,    97,    98,     0,     0,     0,    99,     0,
       0,     0,     0,   100,   101,   102,   103,   178,   411,   104,
       0,   105,     0,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,     0,     0,     0,
       0,     0,     0,   120,   121,   122,   123,     0,     0,     0,
       0,     0,     0,     0,     0,   124,     0,   125,   126,     0,
       0,     0,     0,   412,   413,   414,   415,   416,   417,   418,
     419,   420,     0,     0,     0,     0,   421,   422,   423,   424,
       0,   178,   411,     0,   425,   426,   427,   428,     0,     0,
       0,     0,     0,   429,     0,   430,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   431,     0,     0,   432,     0,     0,     0,   184,     0,
       0,   185,     0,     0,   186,     0,   187,   412,   413,   414,
     415,   416,   417,   418,   419,   420,     0,    48,     0,     0,
     421,   422,   423,   424,   442,   411,     0,     0,   425,   426,
     427,   428,     0,     0,     0,     0,     0,   429,   461,   430,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   431,     0,     0,   432,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     412,   413,   414,   415,   416,   417,   418,   419,   420,     0,
       0,     0,     0,   421,   422,   423,   424,   411,     0,     0,
       0,   425,   426,   427,   428,     0,     0,     0,     0,     0,
     429,     0,   430,     0,     0,     0,     0,     0,     0,     0,
       0,   433,   434,   435,     0,     0,     7,     8,   431,     0,
       0,   432,     0,   436,     0,     0,     0,   437,     0,   438,
     125,     0,   412,   413,   414,   415,   416,   417,   418,   419,
     420,     0,     0,     0,     0,   421,   422,   423,   424,     0,
       0,     0,     0,   425,   426,   427,   428,     0,     0,     0,
       0,     0,   429,     0,   430,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   433,   434,   435,     0,     0,
     431,     0,     0,   432,     0,     0,     0,   436,     0,     0,
       0,   437,     0,   438,   125,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,     0,     0,     0,    45,    46,    47,    48,     0,     0,
       0,     0,    50,     0,     0,     0,     0,     0,   433,   434,
     435,   810,    59,     0,     0,    62,   811,     0,   812,   813,
     436,   814,     0,     0,   437,     0,   438,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      84,   615,   616,   617,   618,   619,   620,   621,   622,   623,
     624,   625,   626,   627,   735,   629,   630,   631,   632,     0,
       0,     0,     0,   633,     0,     0,     0,   101,   102,   103,
     433,   434,   435,  1470,     0,     0,     0,     0,     0,     0,
       0,     0,   436,     0,     0,     0,   437,     0,   438,   615,
     616,   617,   618,   619,   620,   621,   622,   623,   624,   625,
     626,   627,   735,   629,   630,   631,   632,     0,     0,     0,
       0,   633,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1572,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   625,   626,   627,   735,   629,   630,   631,   632,
       0,     0,     0,     0,   633,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1573,   615,   616,   617,   618,   619,
     620,   621,   622,   623,   624,   625,   626,   627,   735,   629,
     630,   631,   632,     0,     0,     0,     0,   633,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1621,   615,   616,
     617,   618,   619,   620,   621,   622,   623,   624,   625,   626,
     627,   735,   629,   630,   631,   632,     0,     0,     0,     0,
     633,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1750,   615,   616,   617,   618,   619,   620,   621,   622,   623,
     624,   625,   626,   627,   735,   629,   630,   631,   632,     0,
       0,     0,     0,   633,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1751,   615,   616,   617,   618,   619,   620,
     621,   622,   623,   624,   625,   626,   627,   735,   629,   630,
     631,   632,     0,     0,     0,     0,   633,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1752,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   624,   625,   626,   627,
     735,   629,   630,   631,   632,     0,     0,     0,     0,   633,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1906,
     615,   616,   617,   618,   619,   620,   621,   622,   623,   624,
     625,   626,   627,   735,   629,   630,   631,   632,     0,     0,
       0,     0,   633,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2036,   615,   616,   617,   618,   619,   620,   621,
     622,   623,   624,   625,   626,   627,   735,   629,   630,   631,
     632,     0,     0,     0,     0,   633,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2037,   615,   616,   617,   618,
     619,   620,   621,   622,   623,   624,   625,   626,   627,   735,
     629,   630,   631,   632,     0,     0,     0,     0,   633,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2069,   615,
     616,   617,   618,   619,   620,   621,   622,   623,   624,   625,
     626,   627,   735,   629,   630,   631,   632,     0,     0,     0,
       0,   633,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2148,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   625,   626,   627,   735,   629,   630,   631,   632,
       0,     0,     0,     0,   633,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2163,   615,   616,   617,   618,   619,
     620,   621,   622,   623,   624,   625,   626,   627,   735,   629,
     630,   631,   632,     0,     0,     0,     0,   633,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2165,   615,   616,
     617,   618,   619,   620,   621,   622,   623,   624,   625,   626,
     627,   735,   629,   630,   631,   632,     0,     0,     0,     0,
     633,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2210,   615,   616,   617,   618,   619,   620,   621,   622,   623,
     624,   625,   626,   627,   735,   629,   630,   631,   632,     0,
       0,     0,     0,   633,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2211,   615,   616,   617,   618,   619,   620,
     621,   622,   623,   624,   625,   626,   627,   735,   629,   630,
     631,   632,     0,     0,     0,     0,   633,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2226,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   624,   625,   626,   627,
     735,   629,   630,   631,   632,     0,     0,     0,     0,   633,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2263,
     615,   616,   617,   618,   619,   620,   621,   622,   623,   624,
     625,   626,   627,   735,   629,   630,   631,   632,     0,     0,
       0,     0,   633,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2292,   615,   616,   617,   618,   619,   620,   621,
     622,   623,   624,   625,   626,   627,   735,   629,   630,   631,
     632,     0,     0,     0,     0,   633,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2297,   615,   616,   617,   618,
     619,   620,   621,   622,   623,   624,   625,   626,   627,   735,
     629,   630,   631,   632,     0,     0,     0,     0,   633,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2298,   615,
     616,   617,   618,   619,   620,   621,   622,   623,   624,   625,
     626,   627,   735,   629,   630,   631,   632,     0,     0,     0,
       0,   633,     0,     0,     0,     0,     0,   869,   615,   616,
     617,   618,   619,   620,   621,   622,   623,   624,   625,   626,
     627,   735,   629,   630,   631,   632,     0,     0,     0,     0,
     633,     0,     0,     0,     0,     0,  1139,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   624,   625,   626,   627,
     735,   629,   630,   631,   632,     0,     0,     0,     0,   633,
       0,     0,     0,     0,     0,  1197,   615,   616,   617,   618,
     619,   620,   621,   622,   623,   624,   625,   626,   627,   735,
     629,   630,   631,   632,     0,     0,     0,     0,   633,     0,
       0,     0,     0,     0,  1246,   615,   616,   617,   618,   619,
     620,   621,   622,   623,   624,   625,   626,   627,   735,   629,
     630,   631,   632,     0,     0,     0,     0,   633,     0,     0,
       0,     0,     0,  1247,   615,   616,   617,   618,   619,   620,
     621,   622,   623,   624,   625,   626,   627,   735,   629,   630,
     631,   632,     0,     0,     0,     0,   633,     0,     0,     0,
       0,     0,  1297,   615,   616,   617,   618,   619,   620,   621,
     622,   623,   624,   625,   626,   627,   735,   629,   630,   631,
     632,     0,     0,     0,     0,   633,     0,     0,     0,     0,
       0,  1330,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   625,   626,   627,   735,   629,   630,   631,   632,
       0,     0,     0,     0,   633,     0,     0,     0,     0,     0,
    1345,   615,   616,   617,   618,   619,   620,   621,   622,   623,
     624,   625,   626,   627,   735,   629,   630,   631,   632,     0,
       0,     0,     0,   633,     0,     0,     0,     0,     0,  1352,
     615,   616,   617,   618,   619,   620,   621,   622,   623,   624,
     625,   626,   627,   735,   629,   630,   631,   632,     0,     0,
       0,     0,   633,     0,     0,     0,     0,     0,  1413,   615,
     616,   617,   618,   619,   620,   621,   622,   623,   624,   625,
     626,   627,   735,   629,   630,   631,   632,     0,     0,     0,
       0,   633,     0,     0,     0,     0,     0,  1433,   615,   616,
     617,   618,   619,   620,   621,   622,   623,   624,   625,   626,
     627,   735,   629,   630,   631,   632,     0,     0,     0,     0,
     633,     0,     0,     0,     0,     0,  1469,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   624,   625,   626,   627,
     735,   629,   630,   631,   632,     0,     0,     0,     0,   633,
       0,     0,     0,     0,     0,  1519,   615,   616,   617,   618,
     619,   620,   621,   622,   623,   624,   625,   626,   627,   735,
     629,   630,   631,   632,     0,     0,     0,     0,   633,     0,
       0,     0,     0,     0,  1520,   615,   616,   617,   618,   619,
     620,   621,   622,   623,   624,   625,   626,   627,   735,   629,
     630,   631,   632,     0,     0,     0,     0,   633,     0,     0,
       0,     0,     0,  1521,   615,   616,   617,   618,   619,   620,
     621,   622,   623,   624,   625,   626,   627,   735,   629,   630,
     631,   632,     0,     0,     0,     0,   633,     0,     0,     0,
       0,     0,  1524,   615,   616,   617,   618,   619,   620,   621,
     622,   623,   624,   625,   626,   627,   735,   629,   630,   631,
     632,     0,     0,     0,     0,   633,     0,     0,     0,     0,
       0,  1525,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   625,   626,   627,   735,   629,   630,   631,   632,
       0,     0,     0,     0,   633,     0,     0,     0,     0,     0,
    1526,   615,   616,   617,   618,   619,   620,   621,   622,   623,
     624,   625,   626,   627,   735,   629,   630,   631,   632,     0,
       0,     0,     0,   633,     0,     0,     0,     0,     0,  1528,
     615,   616,   617,   618,   619,   620,   621,   622,   623,   624,
     625,   626,   627,   735,   629,   630,   631,   632,     0,     0,
       0,     0,   633,     0,     0,     0,     0,     0,  1529,   615,
     616,   617,   618,   619,   620,   621,   622,   623,   624,   625,
     626,   627,   735,   629,   630,   631,   632,     0,     0,     0,
       0,   633,     0,     0,     0,     0,     0,  1574,   615,   616,
     617,   618,   619,   620,   621,   622,   623,   624,   625,   626,
     627,   735,   629,   630,   631,   632,     0,     0,     0,     0,
     633,     0,     0,     0,     0,     0,  1651,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   624,   625,   626,   627,
     735,   629,   630,   631,   632,     0,     0,     0,     0,   633,
       0,     0,     0,     0,     0,  1761,   615,   616,   617,   618,
     619,   620,   621,   622,   623,   624,   625,   626,   627,   735,
     629,   630,   631,   632,     0,     0,     0,     0,   633,     0,
       0,     0,     0,     0,  1962,   615,   616,   617,   618,   619,
     620,   621,   622,   623,   624,   625,   626,   627,   735,   629,
     630,   631,   632,     0,     0,     0,     0,   633,     0,     0,
       0,     0,     0,  1973,   615,   616,   617,   618,   619,   620,
     621,   622,   623,   624,   625,   626,   627,   735,   629,   630,
     631,   632,     0,     0,     0,     0,   633,     0,     0,     0,
       0,     0,  2016,   615,   616,   617,   618,   619,   620,   621,
     622,   623,   624,   625,   626,   627,   735,   629,   630,   631,
     632,     0,     0,     0,     0,   633,     0,     0,     0,     0,
       0,  2094,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   625,   626,   627,   735,   629,   630,   631,   632,
       0,     0,     0,     0,   633,     0,     0,     0,     0,     0,
    2110,   615,   616,   617,   618,   619,   620,   621,   622,   623,
     624,   625,   626,   627,   735,   629,   630,   631,   632,     0,
       0,     0,     0,   633,     0,     0,     0,     0,     0,  2125,
     615,   616,   617,   618,   619,   620,   621,   622,   623,   624,
     625,   626,   627,   735,   629,   630,   631,   632,     0,     0,
       0,     0,   633,     0,     0,     0,     0,     0,  2149,   615,
     616,   617,   618,   619,   620,   621,   622,   623,   624,   625,
     626,   627,   735,   629,   630,   631,   632,     0,     0,     0,
       0,   633,     0,     0,     0,     0,     0,  2164,   615,   616,
     617,   618,   619,   620,   621,   622,   623,   624,   625,   626,
     627,   735,   629,   630,   631,   632,     0,     0,     0,     0,
     633,     0,     0,     0,     0,     0,  2188,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   624,   625,   626,   627,
     735,   629,   630,   631,   632,     0,     0,     0,     0,   633,
       0,     0,     0,     0,     0,  2198,   615,   616,   617,   618,
     619,   620,   621,   622,   623,   624,   625,   626,   627,   735,
     629,   630,   631,   632,     0,     0,     0,     0,   633,     0,
       0,     0,     0,     0,  2199,   615,   616,   617,   618,   619,
     620,   621,   622,   623,   624,   625,   626,   627,   735,   629,
     630,   631,   632,     0,     0,     0,     0,   633,     0,     0,
       0,     0,     0,  2224,   615,   616,   617,   618,   619,   620,
     621,   622,   623,   624,   625,   626,   627,   735,   629,   630,
     631,   632,     0,     0,     0,     0,   633,     0,     0,     0,
       0,     0,  2229,   615,   616,   617,   618,   619,   620,   621,
     622,   623,   624,   625,   626,   627,   735,   629,   630,   631,
     632,     0,     0,     0,     0,   633,     0,     0,     0,     0,
       0,  2269,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   625,   626,   627,   735,   629,   630,   631,   632,
       0,     0,     0,     0,   633,     0,     0,     0,     0,     0,
    2270,   615,   616,   617,   618,   619,   620,   621,   622,   623,
     624,   625,   626,   627,   735,   629,   630,   631,   632,     0,
       0,     0,     0,   633,     0,     0,     0,     0,     0,  2278,
     615,   616,   617,   618,   619,   620,   621,   622,   623,   624,
     625,   626,   627,   735,   629,   630,   631,   632,     0,     0,
       0,     0,   633,     0,     0,     0,     0,     0,  2317,   615,
     616,   617,   618,   619,   620,   621,   622,   623,   624,   625,
     626,   627,   735,   629,   630,   631,   632,     0,     0,     0,
       0,   633,     0,     0,     0,     0,     0,  2335,   615,   616,
     617,   618,   619,   620,   621,   622,   623,   624,   625,   626,
     627,   735,   629,   630,   631,   632,     0,     0,     0,     0,
     633,     0,     0,     0,     0,     0,  2353,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   624,   625,   626,   627,
     735,   629,   630,   631,   632,     0,     0,     0,     0,   633,
       0,     0,     0,     0,     0,  2354,   615,   616,   617,   618,
     619,   620,   621,   622,   623,   624,   625,   626,   627,   735,
     629,   630,   631,   632,     0,     0,     0,     0,   633,     0,
       0,     0,     0,   772,   615,   616,   617,   618,   619,   620,
     621,   622,   623,   624,   625,   626,   627,   735,   629,   630,
     631,   632,     0,     0,     0,     0,   633,     0,     0,     0,
       0,   999,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   625,   626,   627,   735,   629,   630,   631,   632,
       0,     0,     0,     0,   633,     0,     0,     0,     0,  2087,
     615,   616,   617,   618,   619,   620,   621,   622,   623,   624,
     625,   626,   627,   735,   629,   630,   631,   632,     0,     0,
       0,     0,   633,     0,   796,     0,   797,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   624,   625,   626,   627,
     735,   629,   630,   631,   632,     0,     0,     0,     0,   633,
       0,     0,     0,  1070,   615,   616,   617,   618,   619,   620,
     621,   622,   623,   624,   625,   626,   627,   735,   629,   630,
     631,   632,     0,     0,     0,     0,   633,     0,     0,     0,
    1115,   615,   616,   617,   618,   619,   620,   621,   622,   623,
     624,   625,   626,   627,   735,   629,   630,   631,   632,     0,
       0,     0,     0,   633,     0,     0,     0,  1276,   615,   616,
     617,   618,   619,   620,   621,   622,   623,   624,   625,   626,
     627,   735,   629,   630,   631,   632,     0,     0,     0,     0,
     633,     0,     0,     0,  1346,   615,   616,   617,   618,   619,
     620,   621,   622,   623,   624,   625,   626,   627,   735,   629,
     630,   631,   632,     0,     0,     0,     0,   633,     0,     0,
       0,  1348,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   625,   626,   627,   735,   629,   630,   631,   632,
       0,     0,     0,     0,   633,     0,     0,     0,  1355,   615,
     616,   617,   618,   619,   620,   621,   622,   623,   624,   625,
     626,   627,   735,   629,   630,   631,   632,     0,     0,     0,
       0,   633,     0,     0,     0,  1356,   615,   616,   617,   618,
     619,   620,   621,   622,   623,   624,   625,   626,   627,   735,
     629,   630,   631,   632,     0,     0,     0,     0,   633,     0,
       0,     0,  1448,   615,   616,   617,   618,   619,   620,   621,
     622,   623,   624,   625,   626,   627,   735,   629,   630,   631,
     632,     0,     0,     0,     0,   633,     0,     0,     0,  1462,
     615,   616,   617,   618,   619,   620,   621,   622,   623,   624,
     625,   626,   627,   735,   629,   630,   631,   632,     0,     0,
       0,     0,   633,     0,     0,     0,  1680,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   624,   625,   626,   627,
     735,   629,   630,   631,   632,     0,     0,     0,     0,   633,
       0,     0,     0,  1776,   615,   616,   617,   618,   619,   620,
     621,   622,   623,   624,   625,   626,   627,   735,   629,   630,
     631,   632,     0,     0,     0,     0,   633,     0,     0,     0,
    1830,   615,   616,   617,   618,   619,   620,   621,   622,   623,
     624,   625,   626,   627,   735,   629,   630,   631,   632,     0,
       0,     0,     0,   633,     0,     0,     0,  2028,   615,   616,
     617,   618,   619,   620,   621,   622,   623,   624,   625,   626,
     627,   735,   629,   630,   631,   632,     0,     0,     0,     0,
     633,     0,     0,     0,  2077,   615,   616,   617,   618,   619,
     620,   621,   622,   623,   624,   625,   626,   627,   735,   629,
     630,   631,   632,     0,     0,     0,     0,   633,     0,     0,
       0,  2095,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   625,   626,   627,   735,   629,   630,   631,   632,
       0,     0,     0,     0,   633,     0,   850,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   624,   625,   626,   627,
     735,   629,   630,   631,   632,     0,     0,     0,     0,   633,
       0,   851,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   625,   626,   627,   735,   629,   630,   631,   632,
       0,     0,     0,     0,   633,     0,   852,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   624,   625,   626,   627,
     735,   629,   630,   631,   632,     0,     0,     0,     0,   633,
       0,   854,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   625,   626,   627,   735,   629,   630,   631,   632,
       0,     0,     0,     0,   633,     0,   855,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   624,   625,   626,   627,
     735,   629,   630,   631,   632,     0,     0,     0,     0,   633,
       0,   856,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   625,   626,   627,   735,   629,   630,   631,   632,
       0,     0,     0,     0,   633,     0,   858,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   624,   625,   626,   627,
     735,   629,   630,   631,   632,     0,     0,     0,     0,   633,
       0,   859,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   625,   626,   627,   735,   629,   630,   631,   632,
       0,     0,     0,     0,   633,     0,   860,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   624,   625,   626,   627,
     735,   629,   630,   631,   632,     0,     0,     0,     0,   633,
       0,   861,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   625,   626,   627,   735,   629,   630,   631,   632,
       0,     0,     0,     0,   633,     0,   862,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   624,   625,   626,   627,
     735,   629,   630,   631,   632,     0,     0,     0,     0,   633,
       0,   863,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   625,   626,   627,   735,   629,   630,   631,   632,
       0,     0,     0,     0,   633,     0,   864,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   624,   625,   626,   627,
     735,   629,   630,   631,   632,     0,     0,     0,     0,   633,
       0,   866,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   625,   626,   627,   735,   629,   630,   631,   632,
       0,     0,     0,     0,   633,     0,   867,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   624,   625,   626,   627,
     735,   629,   630,   631,   632,     0,     0,     0,     0,   633,
       0,   868,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   625,   626,   627,   735,   629,   630,   631,   632,
       0,     0,     0,     0,   633,     0,   946,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   624,   625,   626,   627,
     735,   629,   630,   631,   632,     0,     0,     0,     0,   633,
       0,   980,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   625,   626,   627,   735,   629,   630,   631,   632,
       0,     0,     0,     0,   633,     0,  1030,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   624,   625,   626,   627,
     735,   629,   630,   631,   632,     0,     0,     0,     0,   633,
       0,  1047,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   625,   626,   627,   735,   629,   630,   631,   632,
       0,     0,     0,     0,   633,     0,  1055,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   624,   625,   626,   627,
     735,   629,   630,   631,   632,     0,     0,     0,     0,   633,
       0,  1057,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   625,   626,   627,   735,   629,   630,   631,   632,
       0,     0,     0,     0,   633,     0,  1058,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   624,   625,   626,   627,
     735,   629,   630,   631,   632,     0,     0,     0,     0,   633,
       0,  1064,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   625,   626,   627,   735,   629,   630,   631,   632,
       0,     0,     0,     0,   633,     0,  1065,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   624,   625,   626,   627,
     735,   629,   630,   631,   632,     0,     0,     0,     0,   633,
       0,  1103,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   625,   626,   627,   735,   629,   630,   631,   632,
       0,     0,     0,     0,   633,     0,  1114,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   624,   625,   626,   627,
     735,   629,   630,   631,   632,     0,     0,     0,     0,   633,
       0,  1175,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   625,   626,   627,   735,   629,   630,   631,   632,
       0,     0,     0,     0,   633,     0,  1179,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   624,   625,   626,   627,
     735,   629,   630,   631,   632,     0,     0,     0,     0,   633,
       0,  1191,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   625,   626,   627,   735,   629,   630,   631,   632,
       0,     0,     0,     0,   633,     0,  1275,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   624,   625,   626,   627,
     735,   629,   630,   631,   632,     0,     0,     0,     0,   633,
       0,  1285,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   625,   626,   627,   735,   629,   630,   631,   632,
       0,     0,     0,     0,   633,     0,  1286,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   624,   625,   626,   627,
     735,   629,   630,   631,   632,     0,     0,     0,     0,   633,
       0,  1287,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   625,   626,   627,   735,   629,   630,   631,   632,
       0,     0,     0,     0,   633,     0,  1296,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   624,   625,   626,   627,
     735,   629,   630,   631,   632,     0,     0,     0,     0,   633,
       0,  1298,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   625,   626,   627,   735,   629,   630,   631,   632,
       0,     0,     0,     0,   633,     0,  1299,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   624,   625,   626,   627,
     735,   629,   630,   631,   632,     0,     0,     0,     0,   633,
       0,  1329,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   625,   626,   627,   735,   629,   630,   631,   632,
       0,     0,     0,     0,   633,     0,  1331,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   624,   625,   626,   627,
     735,   629,   630,   631,   632,     0,     0,     0,     0,   633,
       0,  1332,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   625,   626,   627,   735,   629,   630,   631,   632,
       0,     0,     0,     0,   633,     0,  1333,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   624,   625,   626,   627,
     735,   629,   630,   631,   632,     0,     0,     0,     0,   633,
       0,  1334,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   625,   626,   627,   735,   629,   630,   631,   632,
       0,     0,     0,     0,   633,     0,  1335,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   624,   625,   626,   627,
     735,   629,   630,   631,   632,     0,     0,     0,     0,   633,
       0,  1336,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   625,   626,   627,   735,   629,   630,   631,   632,
       0,     0,     0,     0,   633,     0,  1337,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   624,   625,   626,   627,
     735,   629,   630,   631,   632,     0,     0,     0,     0,   633,
       0,  1344,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   625,   626,   627,   735,   629,   630,   631,   632,
       0,     0,     0,     0,   633,     0,  1358,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   624,   625,   626,   627,
     735,   629,   630,   631,   632,     0,     0,     0,     0,   633,
       0,  1360,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   625,   626,   627,   735,   629,   630,   631,   632,
       0,     0,     0,     0,   633,     0,  1401,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   624,   625,   626,   627,
     735,   629,   630,   631,   632,     0,     0,     0,     0,   633,
       0,  1447,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   625,   626,   627,   735,   629,   630,   631,   632,
       0,     0,     0,     0,   633,     0,  1461,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   624,   625,   626,   627,
     735,   629,   630,   631,   632,     0,     0,     0,     0,   633,
       0,  1681,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   625,   626,   627,   735,   629,   630,   631,   632,
       0,     0,     0,     0,   633,     0,  1717,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   624,   625,   626,   627,
     735,   629,   630,   631,   632,     0,     0,     0,     0,   633,
       0,  1763,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   625,   626,   627,   735,   629,   630,   631,   632,
       0,     0,     0,     0,   633,     0,  1775,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   624,   625,   626,   627,
     735,   629,   630,   631,   632,     0,     0,     0,     0,   633,
       0,  1893,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   625,   626,   627,   735,   629,   630,   631,   632,
       0,     0,     0,     0,   633,     0,  1895,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   624,   625,   626,   627,
     735,   629,   630,   631,   632,     0,     0,     0,     0,   633,
       0,  1898,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   625,   626,   627,   735,   629,   630,   631,   632,
       0,     0,     0,     0,   633,     0,  1905,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   624,   625,   626,   627,
     735,   629,   630,   631,   632,     0,     0,     0,     0,   633,
       0,  1963,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   625,   626,   627,   735,   629,   630,   631,   632,
       0,     0,     0,     0,   633,     0,  1972,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   624,   625,   626,   627,
     735,   629,   630,   631,   632,     0,     0,     0,     0,   633,
       0,  1999,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   625,   626,   627,   735,   629,   630,   631,   632,
       0,     0,     0,     0,   633,     0,  2076,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   624,   625,   626,   627,
     735,   629,   630,   631,   632,     0,     0,     0,     0,   633,
       0,  2146,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   625,   626,   627,   735,   629,   630,   631,   632,
       0,     0,     0,     0,   633,     0,  2147,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   624,   625,   626,   627,
     735,   629,   630,   631,   632,     0,     0,     0,     0,   633,
       0,  2291,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   625,   626,   627,   735,   629,   630,   631,   632,
       0,     0,     0,     0,   633,     0,  2332,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   624,   625,   626,   627,
     735,   629,   630,   631,   632,     0,     0,     0,     0,   633
};

static const yytype_int16 yycheck[] =
{
       3,   793,   152,   336,    27,   672,   673,   799,  1533,  1814,
    1324,  1861,  1328,  1863,     7,    72,    73,     6,    75,     4,
       4,    66,     4,   166,    27,     3,     6,     4,  2052,   111,
     170,     6,   471,     4,     6,     4,     4,   111,    14,  1850,
      99,     5,   111,     5,   149,     5,     5,   111,     4,     6,
       0,     6,   149,   105,   267,    58,     7,     6,     4,   272,
       6,     4,   171,   111,     6,     6,   115,    68,   117,   138,
       6,   168,   124,     6,   138,     4,     4,     4,   266,     4,
     268,     9,   179,   180,   181,    88,   149,     4,   185,   186,
     199,    94,   266,     9,     9,   108,    99,   202,   111,   112,
     113,   104,  1913,   152,   105,   168,   215,   216,     9,   254,
     255,   124,   115,     7,     4,   270,   179,   180,   181,   274,
     254,   255,   185,   186,     4,  1930,    97,     9,   266,     6,
     275,     4,   263,   264,   183,   108,    26,     9,   111,   270,
     189,   275,     9,   263,   264,   266,    26,    37,    38,   152,
       6,   210,   272,    26,   157,   158,   159,    37,    38,   105,
       6,   220,   266,   166,    37,    38,   105,   254,   255,   108,
     254,   255,   111,     6,   271,   153,   105,     8,   254,   255,
     109,   194,     6,     6,   266,   124,   115,   116,   275,   118,
     119,   275,   266,   254,   255,  2219,   267,     6,   637,   275,
     154,   155,   205,     7,   275,     6,   160,   210,   348,     7,
     270,   214,   215,   142,   275,   254,   255,   220,   221,   222,
     265,   266,   267,     7,   114,   115,   175,   266,   368,     7,
     187,   270,   187,   189,   190,   191,   192,   268,     7,   210,
     285,   114,   115,  1768,     6,   201,   214,   203,   204,   205,
     206,   207,   237,   237,     6,   211,   212,   267,   214,   269,
     237,   320,   321,   322,   108,   275,   237,   111,   237,   249,
     250,   254,   255,   266,     6,   268,  1590,   300,   281,  2084,
     124,   270,   339,   340,     6,   270,   268,   270,   270,   273,
     347,   348,   274,   296,   237,   270,   299,   300,   270,   270,
     739,   270,   361,   362,   363,   445,   270,   447,   270,   237,
     270,   270,   315,   316,   454,   271,   319,   320,   321,   322,
     379,   272,  1114,  1115,   267,   266,   269,   330,   270,   270,
     111,   334,   113,   336,   270,   263,   264,  2142,   266,   266,
     268,   266,   270,   266,   272,   239,   240,   241,   242,   266,
     266,   266,   268,   268,   268,   358,   359,   272,   361,   362,
     363,   108,   263,   264,   111,   266,   113,   268,   807,   263,
     264,   272,   249,   250,   269,   267,   379,   124,   272,   382,
     275,   263,   264,   275,   266,   824,   268,   269,   254,   255,
     272,   263,   264,   271,   266,   834,   268,   275,   267,   266,
     272,   268,   267,   266,   270,   272,   275,  2257,   254,   255,
     275,   460,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     254,   255,   266,   576,   265,   239,   240,   241,   242,   266,
     271,   239,   240,   241,   242,   254,   255,   450,   266,   452,
     268,   266,   270,   456,   457,   239,   240,   241,   242,   263,
     264,   239,   240,   241,   242,   263,   264,   254,   255,   472,
     239,   240,   241,   242,     4,   108,   479,     8,   111,   263,
     264,   254,   255,   254,   255,   267,   254,   255,   275,  2294,
     254,   255,     4,   275,     4,   270,    26,   254,   255,   269,
     149,   504,   275,   271,   275,   275,   266,    37,    38,   948,
     270,   275,   254,   255,    26,   149,   259,   260,   275,   168,
     266,   661,   265,   663,   664,    37,    38,   530,   270,  1196,
     179,   180,   181,   592,   168,   266,   185,   186,   266,  2344,
     680,   266,   270,   254,   255,   179,   180,   181,   266,  2074,
     599,   185,   186,   556,   266,   254,   255,   254,   255,   266,
     700,   268,   565,   566,   275,   254,   255,   570,   275,   572,
     573,   574,   575,   576,   266,   598,   275,   600,   275,   582,
     263,   264,     4,   267,   114,   115,   275,   727,   591,   592,
     593,   275,   595,   596,   597,   598,   266,   600,   268,   602,
     743,    58,   114,   115,    26,   108,   254,   255,   111,     8,
     113,   154,   155,   670,   671,    37,    38,   160,   675,   254,
     255,   272,   271,   274,   266,   628,   268,   275,   254,   255,
     272,   634,   772,   275,   266,   254,   255,   271,   254,   255,
     275,   254,   255,   793,   154,   155,   156,   157,   149,   275,
     160,   161,   266,   656,   657,     8,   275,   266,   266,   275,
     170,   270,   275,   266,   174,   254,   255,   168,   111,   199,
     200,  1338,  1339,   267,   267,   269,   269,  1116,   179,   180,
     181,   275,   275,   270,   185,   186,   275,   199,   200,   267,
     254,   255,   114,   115,   672,   673,   267,   275,   269,   270,
     267,   267,   266,   706,   707,   708,   270,   756,   275,   275,
     128,   714,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     267,   271,   269,   736,   265,   275,   267,   760,   741,   742,
     743,   744,   745,   746,   747,   748,   749,   270,   751,   752,
     753,   754,   755,     6,   757,   758,   759,   760,   761,     6,
       7,   764,   271,   267,   221,   269,   275,  1559,   813,     6,
     271,   275,     3,   263,   264,   266,   266,   268,   268,   782,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   798,   266,     6,    29,   265,
     849,   804,   105,   271,   267,   108,   269,   275,   111,   271,
     113,   271,   275,   275,   113,   275,   272,   820,   821,   275,
    1259,   124,  1261,   826,   281,   828,   271,   977,   831,   832,
     275,   266,   271,     6,    65,  1274,   275,   840,   271,   842,
     270,   266,   275,   268,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   319,  1003,  1656,  1304,   265,   270,     4,   872,
       6,   874,   271,   330,  1666,   254,   255,   334,   256,   257,
     258,   259,   260,   263,   264,   111,   266,   265,   268,   120,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   911,   271,
     266,   271,   265,   275,   267,   275,   269,   108,   921,  1069,
     271,   152,   270,   270,   275,   270,   157,   158,   159,  1368,
    2246,   270,  1371,  1372,   111,   166,   266,   263,   264,   271,
     266,   990,   268,   275,   270,     6,   271,   950,   271,  1006,
     275,   271,   275,   111,   271,   275,  1013,  1396,   275,   267,
    1017,   269,   270,   966,  1114,  1115,  2280,   254,   255,   256,
     257,   258,   259,   260,   205,   978,   111,   108,   265,   271,
    1419,  1131,   271,   275,   987,   108,   275,     4,   271,  2305,
     271,   222,   275,   271,   275,     4,   999,   275,   271,   456,
     457,   271,   275,     4,     4,   275,   271,  1446,  2322,   271,
     275,   266,   271,   275,   271,   472,   275,     6,   275,   271,
     271,  1460,   271,   275,   275,   271,   275,   271,  1467,   275,
     266,   275,   266,   264,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   283,   284,   271,   271,   265,   271,   275,   275,
     271,   275,     6,   271,   275,   268,   266,   275,     6,  1118,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   268,   270,
    1423,     6,   265,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,  1109,   271,   271,   271,
     265,   275,   275,   275,  1117,  1172,   573,   271,   274,   271,
     271,   275,  1125,   275,   275,  1275,  1276,   271,   270,     6,
       9,   275,  1799,  1800,   591,  1138,   593,   271,   271,   271,
    1143,   275,   275,   275,   271,   271,   271,   271,   275,   275,
     275,   275,   271,     4,     5,   271,   275,   271,   271,   275,
     271,   275,   275,   271,   275,   271,   266,   275,   271,   275,
    1173,  1174,   275,  1176,  1177,  1178,   274,  1180,  1181,  1182,
    1183,  1184,  1185,  1186,  1187,  1188,  1189,   271,   271,  1192,
     266,   275,   275,   266,   266,   266,   270,   266,   266,    50,
      51,    52,    53,    54,    55,    56,    57,    58,   202,   202,
     202,   270,    63,    64,    65,    66,   111,   138,  1196,   450,
      71,    72,    73,    74,   266,   266,   266,   266,   202,    80,
     461,    82,  1235,  1236,  1237,   270,   266,   266,   266,   270,
     266,     4,     6,   270,     6,   270,   270,    98,   270,   268,
     101,   266,   483,   266,   105,   266,   266,   108,   266,   266,
     111,   266,   113,  1266,     6,   268,   270,   498,   270,     7,
       6,   270,   270,   124,   270,     6,   202,   268,   268,  1282,
    1283,  1284,   266,   266,   270,   266,   266,   266,   266,   266,
     266,     6,     6,   268,   145,     6,     8,  1447,  1448,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   270,     6,     8,
     266,   265,   270,     7,     6,   782,  1659,   270,   270,     6,
     270,   100,   271,   267,   275,     7,     6,  1340,   275,   570,
       6,   572,   267,   574,   575,   576,   270,   270,   270,    68,
     270,   270,   270,   270,   270,   265,  1359,   270,  1361,  1362,
    1338,  1339,   270,   272,   595,   596,     8,   218,   219,   220,
       7,  1374,     7,   266,     6,   267,  1379,     7,     6,   230,
    1383,   270,     7,   234,     6,   236,   237,     6,     6,  1392,
     271,  1394,   199,   271,  1397,   270,   269,   271,   267,     6,
     270,   272,     7,     6,   268,   266,     6,  1410,   270,     6,
       6,     6,   263,   264,     6,   267,     7,     7,   268,   270,
    1423,   272,  1471,  2090,  1473,     7,     7,     7,  1867,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,  1448,     7,   678,     7,   265,
    1453,     7,  1455,     7,     7,     7,     7,     7,     7,     7,
       7,   270,     6,   267,   269,   275,   267,   275,   271,   275,
    1473,   270,   703,   275,     7,   271,     7,   272,   270,   270,
       4,     6,   272,  1486,   271,   271,   149,  1490,   270,   270,
       7,     6,   272,   950,     7,     7,     7,   272,   275,   267,
     267,   275,     9,   275,  1644,   202,  1656,   267,  1648,   274,
     741,   742,   743,   744,   745,   746,   747,   748,   749,   269,
     751,   752,   753,   754,  1667,  1668,   757,   758,   759,     7,
     987,   171,  1589,     6,   271,   270,   767,     6,     6,   770,
      50,    50,  1875,   272,   266,   776,   270,   270,   266,     7,
    1553,  1554,  1555,   266,     7,   272,   272,   266,  1561,  1562,
    1563,     7,   267,   202,     7,   275,     7,     7,     6,   267,
       7,   275,     7,     7,     7,     7,     4,  1580,   123,   270,
       6,   812,     7,   814,     6,   266,     7,     7,  1591,     7,
       7,  1640,     7,     7,     7,   270,  1599,   105,     6,     6,
     831,  1604,     6,   267,     7,   111,     7,     6,     6,     4,
       7,   842,  1615,     7,  1617,   273,   275,     6,   275,   270,
     270,   270,     6,   271,  1774,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,     6,   268,     7,     6,   265,     7,     8,
       6,     6,  1109,  1702,   266,   266,  1659,   270,     6,     6,
       6,   271,     6,  1720,  1667,  1668,   272,     6,  1125,     6,
    1673,   269,     6,   275,     6,   142,     6,     6,     6,     6,
       6,     6,     6,     6,     6,     6,     6,     5,  1691,   267,
     129,   267,   271,   129,     6,     6,     4,   202,   129,  1702,
       6,   270,   270,     7,  1707,     6,   270,     7,   270,     6,
     270,   268,     6,   271,     6,   270,  1173,  1174,     6,  1176,
    1177,  1178,     6,  1180,  1181,  1182,  1183,  1184,  1185,  1186,
    1187,  1188,  1189,   270,   270,  1878,   270,   198,   270,     6,
     270,     6,   271,   270,   270,   267,  1795,   275,     7,     6,
     270,     6,   275,   271,   275,     6,   275,     6,  1815,  1816,
    1817,  1818,  1819,  1820,   266,   266,     4,   270,   272,   266,
       7,  1002,     6,  1004,  1005,     6,     6,     6,  1235,   149,
       6,     5,   270,  1786,     6,   270,   270,  1018,  1791,  1792,
     109,   270,   267,   275,  1843,   111,  2129,     6,   270,   270,
       6,  1850,  1851,     6,   149,   275,   149,     6,  1039,  1266,
       6,  1814,     6,     6,     6,   275,   267,  1820,   275,     6,
    1869,  1799,  1800,  1826,     6,  1282,     6,   275,   270,     6,
    1061,     6,  1835,     6,     6,     6,   153,     7,     6,     5,
     270,   270,  1845,   270,     6,  1848,   270,   270,     6,     6,
       6,   270,     7,     6,   270,   267,   197,     6,     6,   270,
     270,  1864,   271,     7,     6,  1868,   271,   267,     6,  1100,
     272,     6,  1875,     6,  1877,  1878,     6,     6,   271,   271,
     271,     6,   270,  1340,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,  1359,   271,  1361,  1362,   265,     6,     6,   267,
    1913,     6,  1143,   270,     6,   200,     6,   270,     6,   271,
     271,   270,     6,     6,   266,     6,   149,  1930,     6,   267,
     270,     6,     6,     6,   270,   270,     6,     6,   271,   270,
       6,     6,     6,  1946,  1947,     6,     6,     6,     6,     6,
       6,     6,     6,  1410,   267,   270,     6,   271,     6,  2099,
       6,   271,  1459,   270,  2259,   270,  2015,   270,  1971,  1522,
    1715,  2013,  2053,     3,  1782,   589,     3,  1485,  1127,     3,
    1983,     3,   649,  2086,  1637,   501,     3,  1868,  1850,  1668,
     831,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2001,    -1,
      -1,    -1,    -1,    -1,    -1,  1236,  1237,    -1,    -1,  2058,
      -1,    -1,    -1,    -1,    -1,    -1,  1473,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1486,
      -1,    -1,    -1,  1490,    -1,    -1,  2039,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2103,  2104,  2105,  2106,
    2107,  2054,    -1,    -1,    -1,    -1,  2059,    -1,    -1,  2062,
    2063,    -1,    -1,    -1,  2204,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1306,    -1,    -1,    -1,    -1,
      -1,  2084,    -1,    -1,  2087,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2098,  1553,  1554,  1555,  2102,
      -1,    -1,    -1,    -1,  1561,  1562,  1563,  2247,    -1,    -1,
      -1,  2114,  2090,    -1,    -1,    -1,    -1,  2174,    -1,    -1,
      -1,  2178,    -1,  1580,    -1,    -1,  2129,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1591,    -1,    -1,    -1,    -1,  2142,
      -1,    -1,  1599,     6,    -1,    -1,    -1,    -1,  1379,    -1,
      -1,    -1,  1383,    -1,    -1,    -1,    -1,    -1,  1615,    -1,
    1617,  1392,    -1,  1394,    -1,    -1,  1397,    -1,    -1,    -1,
      -1,  2220,  2175,  1404,    -1,    -1,  2233,    -1,    -1,    -1,
    2237,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2253,    -1,    -1,    -1,
      -1,   152,    -1,    -1,    -1,    -1,   157,   158,   159,    -1,
      -1,    -1,    -1,    -1,     4,     5,  1673,  1448,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2231,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2300,  2301,  1702,  2249,  2250,  2251,  2252,
    2253,    -1,    -1,    -1,   205,    -1,    -1,    -1,    -1,    -1,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    -1,
      -1,   222,    -1,    63,    64,    65,    66,    -1,    -1,    -1,
      -1,    71,    72,    73,    74,    -1,    -1,    -1,    -1,    -1,
      80,  2294,    82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2310,    98,    -1,
      -1,   101,    -1,    -1,    -1,   105,    -1,    -1,   108,    -1,
      -1,   111,    -1,   113,    -1,    -1,    -1,    -1,  2331,  1786,
      -1,    -1,    -1,    -1,   124,    -1,    -1,    -1,    -1,    -1,
      -1,  2344,    -1,    -1,    -1,    -1,    -1,  2350,  2351,    -1,
      -1,    -1,    -1,    -1,    -1,   145,    -1,  1814,    -1,    -1,
    2363,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1835,    -1,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,    -1,    -1,
      -1,    -1,   265,    -1,    -1,    -1,    -1,  1864,    -1,    -1,
      -1,     6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1877,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   218,   219,
     220,    -1,    -1,    -1,    -1,    -1,  1667,  1668,    -1,    -1,
     230,    -1,    -1,    -1,   234,    -1,   236,   237,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1691,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1930,    -1,    -1,    -1,   267,    -1,   269,
     270,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   450,
      -1,   124,     6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1971,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   152,
      -1,    -1,    -1,   156,    -1,    -1,    -1,    -1,   161,    -1,
      -1,    -1,    -1,    -1,    -1,   168,    -1,    -1,   171,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   190,   191,   192,
      -1,   194,   195,   196,     6,   198,   199,   200,   201,   202,
     203,   204,  2039,   206,   207,   208,   209,    -1,    -1,    -1,
      -1,   214,   215,    -1,    -1,    -1,    -1,  2054,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1845,    -1,    -1,  1848,    -1,   570,
      -1,   572,    -1,   574,   575,     6,    -1,  2084,    -1,    -1,
    1861,    -1,  1863,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2098,    -1,    -1,   595,   596,    -1,  1878,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,    -1,    -1,    -1,    -1,
     265,    -1,   295,   296,   297,   298,   299,    -1,    -1,    -1,
      -1,    -1,  1913,    -1,    -1,  2142,    -1,    -1,    -1,    -1,
      -1,   314,   315,   316,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   332,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2175,   342,
     343,    -1,    -1,    -1,    -1,   348,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   358,   359,   360,    -1,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,    -1,   381,   382,
      -1,   265,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   392,
      -1,   394,   395,    -1,   397,    -1,    -1,    -1,   401,   402,
     403,    -1,    -1,   406,    -1,    -1,    -1,   410,    -1,    -1,
      -1,   742,    -1,   744,   745,   746,   747,   748,   749,    -1,
     751,   752,   753,   754,    -1,    -1,   757,   758,   759,    -1,
      -1,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   452,
     453,    -1,    -1,   265,    -1,    -1,    -1,  2294,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   469,   470,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   484,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     831,    -1,    -1,   506,   265,    -1,    -1,  2344,   511,    -1,
      -1,   842,   515,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   529,   530,    -1,    -1,
      -1,    -1,   535,    -1,    -1,    -1,   539,   540,   541,   542,
     543,   544,   545,   546,   547,   548,   549,   550,   551,   552,
     553,   554,   555,   556,   557,   558,   559,   560,   561,   562,
     563,   564,   565,   566,    -1,   568,   569,    -1,   571,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2187,    -1,   581,    -1,
      -1,   584,   585,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   597,    -1,    -1,    -1,    -1,   602,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     6,
      -1,   614,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   625,   626,   627,   628,   629,   630,   631,   632,
     633,    -1,   635,   636,    -1,    -1,    -1,    -1,    -1,    -1,
     643,   644,   645,    -1,    -1,    -1,  2257,    -1,   651,   652,
     653,   654,    -1,   656,   657,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2281,    -1,   675,   676,   677,    -1,    -1,    -1,   681,   682,
     683,   684,   685,   686,   687,   688,   689,    -1,    -1,    -1,
      -1,    -1,    -1,   696,   697,    -1,   699,    -1,    -1,   702,
      -1,    -1,    -1,   706,   707,   708,   709,    -1,    -1,    -1,
     713,   714,   715,   716,   717,    -1,    -1,   720,    -1,   722,
    2331,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   732,
      -1,    -1,   735,    -1,   737,   738,    -1,    -1,    -1,  2350,
    2351,    -1,    -1,    -1,    -1,    -1,    -1,   750,    -1,    -1,
      -1,    -1,  2363,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   764,    -1,    -1,    -1,    -1,    -1,    -1,   771,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   779,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   798,    -1,   800,    -1,   214,
     215,    -1,   805,   806,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1143,    -1,    -1,    -1,    -1,   820,    -1,   822,
     823,    -1,    -1,   826,    -1,   828,   829,    -1,    -1,    -1,
     833,    -1,   835,    -1,   837,    -1,    -1,    -1,    -1,    -1,
     843,    -1,    -1,    -1,   847,    -1,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,    -1,    -1,    -1,   870,   265,   872,
      -1,   874,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   296,    -1,    -1,   299,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   214,   215,
     315,   316,    -1,    -1,    -1,  1236,  1237,    -1,   911,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   921,   922,
     923,   924,    -1,    -1,    -1,    -1,    -1,    -1,   931,   932,
     933,    -1,   935,    -1,    -1,   938,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   358,   359,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     6,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   966,    -1,    -1,    -1,   382,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   978,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   986,    -1,    -1,    -1,   990,    -1,    -1,
     149,    -1,    -1,   996,    -1,    -1,   999,    -1,    -1,   315,
     316,    -1,    -1,    -1,  1007,  1008,    -1,    -1,    -1,    -1,
    1013,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1031,    -1,
      -1,  1034,    -1,    -1,    -1,    -1,    -1,   452,    -1,    -1,
      -1,    -1,   358,   359,    -1,    -1,    -1,    -1,  1379,    -1,
      -1,    -1,  1383,    -1,    -1,    -1,    -1,  1060,    -1,  1062,
    1063,  1392,    -1,  1394,    -1,    -1,  1397,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1085,     6,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,  1105,    -1,    -1,    -1,   265,    -1,    -1,  1112,
      -1,    -1,    -1,    -1,    -1,   530,  1119,  1448,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1132,
    1133,    -1,    -1,    -1,    -1,  1138,   452,    -1,    -1,    -1,
      -1,   556,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     565,   566,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1170,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   597,    -1,    -1,    -1,    -1,   602,    -1,  1192,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,  1211,    -1,
      -1,    -1,   265,   628,    -1,    -1,    -1,    -1,  1221,  1222,
    1223,  1224,  1225,    -1,    -1,    -1,    -1,  1230,  1231,    -1,
    1233,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   656,   657,    -1,    -1,    -1,    -1,    -1,  1251,    -1,
      -1,  1254,  1255,    -1,    -1,    -1,    -1,    -1,    -1,  1262,
    1263,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1271,  1272,
      -1,    -1,    -1,    -1,  1277,  1278,    -1,    -1,    -1,    -1,
    1283,  1284,     6,    -1,    -1,    -1,   602,    -1,    -1,    -1,
      -1,   706,   707,   708,    -1,    -1,    -1,    -1,    -1,   714,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1318,    -1,    -1,   474,    -1,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,    -1,    -1,
     656,   657,   265,    -1,    -1,    -1,    -1,    -1,    -1,   764,
      -1,    -1,    -1,    -1,  1357,    -1,    -1,    -1,    -1,    -1,
    1691,    -1,    -1,    -1,    -1,    -1,  1369,  1370,    -1,    -1,
      -1,  1374,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1382,
      -1,    -1,    -1,   798,    -1,    -1,    -1,    -1,    -1,    -1,
     706,   707,   708,    -1,    -1,    -1,    -1,    -1,   714,    -1,
      -1,    -1,    -1,  1406,    -1,   820,    -1,    -1,    -1,    -1,
      -1,   826,    -1,   828,  1417,    -1,    -1,  1420,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   582,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1449,     6,   764,  1452,
    1453,  1454,  1455,    -1,    -1,    -1,    -1,   872,    -1,   874,
    1463,    -1,    -1,  1466,    -1,  1468,    -1,  1470,  1471,    -1,
      -1,  1474,  1475,  1476,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   798,   639,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   911,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   820,    -1,   921,    -1,    -1,    -1,
     826,    -1,   828,    -1,  1845,    -1,    -1,  1848,    -1,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,    -1,    -1,    -1,
      -1,   265,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   966,    -1,    -1,    -1,    -1,    -1,  1560,    -1,    -1,
      -1,    -1,    -1,   978,    -1,    -1,    -1,    -1,  1571,  1572,
    1573,    -1,    -1,    -1,    -1,    -1,    -1,  1580,    -1,  1582,
      -1,    -1,    -1,    -1,   999,    -1,  1589,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   911,    -1,    -1,    -1,    -1,
      -1,  1604,    -1,    -1,    -1,   921,    -1,  1610,  1611,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1621,  1622,
    1623,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1632,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1642,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     966,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1663,    -1,   978,    -1,    -1,    -1,    -1,    -1,  1671,  1672,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   999,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,    -1,    -1,  1707,    -1,   265,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1138,   880,   881,   882,   883,   884,   885,
     886,   887,   888,   889,   890,   891,    -1,   893,   894,   895,
     896,    -1,   898,   899,   900,   901,    -1,  1750,  1751,  1752,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   914,    -1,
     916,    -1,    -1,  1766,    -1,    -1,    -1,    -1,  1771,  1772,
      -1,   927,    -1,    -1,    -1,    -1,    -1,  1192,    -1,    -1,
      -1,  1784,    -1,    -1,   940,   941,    -1,    -1,  1791,  1792,
    1793,    -1,  1795,   949,    -1,    -1,    -1,    -1,  1801,  1802,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1820,    -1,    -1,
      -1,    -1,  1138,  1826,  1827,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1839,  1840,    -1,    -1,
    1843,    -1,    -1,  1846,    -1,    -1,    -1,  1850,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1860,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1870,  1283,  1284,
      -1,    -1,    -1,    -1,    -1,    -1,  1192,    -1,    -1,    -1,
      -1,  1884,    -1,    -1,    -1,    -1,  1889,  1890,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1903,    -1,    -1,  1906,  1907,    -1,  1909,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1071,  1072,  1073,    -1,    -1,
      -1,  1077,  1078,    -1,    -1,  1081,  1082,  1083,  1084,    -1,
    1086,    -1,  1935,  1936,  1937,  1091,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1946,  1947,    -1,    -1,    -1,    -1,    -1,
    1953,  1954,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1374,
      -1,    -1,  1965,    -1,    -1,    -1,    -1,  1283,  1284,    -1,
      -1,  1974,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1983,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1996,  1997,    -1,    -1,  2000,  2001,    -1,
    2331,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1169,    -1,  1171,    -1,    -1,    -1,  2350,
    2351,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2363,  2036,  2037,    -1,    -1,    -1,  1453,    -1,
    1455,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2057,    -1,    -1,    -1,  1374,  2062,
    2063,  2064,    -1,    -1,    -1,    -1,  2069,    -1,    -1,    -1,
    2073,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2087,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2102,
      -1,    13,    14,    -1,    -1,    -1,    -1,    -1,  2111,    -1,
      -1,  2114,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1280,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2139,  1453,    -1,  1455,
      -1,    -1,  2145,    -1,    -1,  2148,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2163,    -1,  2165,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     6,    -1,    -1,    -1,    -1,
    2183,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1604,
      -1,    -1,    -1,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,    -1,  2210,  2211,   121,
     122,   123,   124,    -1,    -1,    -1,    -1,   129,    -1,    -1,
      -1,    -1,  2225,  2226,    -1,    -1,   138,   139,  2231,    -1,
     142,   143,    -1,   145,   146,    -1,   148,    -1,    -1,    -1,
      -1,  2244,    -1,    -1,    -1,    -1,  2249,  2250,  2251,  2252,
    2253,    -1,    -1,    -1,    -1,   167,  2259,    -1,    -1,    -1,
    2263,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1429,    -1,     6,    -1,    -1,    -1,    -1,
      -1,    -1,   194,   195,   196,    -1,    -1,    -1,  1604,  2292,
      -1,    -1,  1707,    -1,  2297,  2298,    -1,    -1,     6,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2310,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1472,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2337,  2338,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1505,
    1506,  1507,  1508,  1509,  1510,  1511,    -1,    -1,    -1,   271,
    1516,  1517,    -1,    -1,    -1,    -1,    -1,  1523,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1531,  1791,  1792,    -1,  1535,
      -1,    -1,  1538,    -1,    -1,    -1,    -1,    -1,    -1,     4,
       5,    -1,    -1,  1549,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1820,    -1,    -1,    -1,    -1,
      -1,  1826,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
      -1,    -1,    -1,    -1,   265,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    -1,    -1,    -1,    -1,    63,    64,
      65,    66,    -1,    -1,    -1,    -1,    71,    72,    73,    74,
      -1,    -1,    -1,     6,    -1,    80,    -1,    82,    -1,    -1,
      -1,    -1,  1628,    -1,  1630,  1791,  1792,    -1,  1634,    -1,
    1636,    13,    14,    98,    -1,    -1,   101,    -1,    -1,    -1,
     105,     6,    -1,   108,    -1,    -1,   111,    -1,   113,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   124,
    1826,  1667,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     145,  1946,  1947,    -1,   265,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,    -1,    -1,    -1,    -1,   265,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1983,    -1,
      -1,    -1,    -1,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,  2001,    -1,    -1,   121,
     122,   123,   124,    -1,    -1,    -1,    -1,   129,    -1,    -1,
      -1,    -1,    -1,   218,   219,   220,   138,   139,    -1,    -1,
     142,   143,    -1,   145,   146,   230,   148,  1773,    -1,   234,
     152,   236,   237,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1946,  1947,    -1,    -1,    -1,   167,    -1,    -1,    -1,   171,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2062,  2063,    -1,
      -1,    -1,    -1,    -1,    28,   270,    30,    -1,    -1,    -1,
      -1,    -1,   194,   195,   196,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2087,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2001,    -1,  2102,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2114,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,     6,    -1,
      -1,    -1,   265,    -1,  1880,    -1,    -1,  1883,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,  2062,  2063,    -1,    -1,
     265,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     6,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2087,    -1,    -1,    -1,    -1,  1932,  1933,   152,    -1,
      -1,    -1,    -1,  1939,    -1,    -1,  2102,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2114,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2231,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2249,  2250,  2251,  2252,  2253,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2006,  2007,    -1,    -1,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,    -1,   261,   262,    -1,
      -1,    -1,    -1,    -1,    -1,  2310,    -1,   271,   272,  2055,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   287,   288,  2231,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2249,  2250,  2251,  2252,  2253,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,    -1,    -1,    -1,    -1,   265,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2310,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,    -1,    -1,    -1,    -1,   265,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   405,    -1,    -1,    -1,    -1,    -1,    -1,   412,   413,
     414,    -1,    -1,    -1,   418,   419,   420,   421,   422,   423,
     424,    -1,   426,    -1,    -1,    -1,    -1,   431,   432,    -1,
      -1,   435,     3,     4,     5,    -1,    -1,    -1,    -1,    10,
      11,    12,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    -1,    -1,    -1,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    -1,    -1,
      71,    72,    73,    74,    -1,    -1,    77,    78,    79,    80,
      -1,    82,    83,    84,    85,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    96,    97,    98,    99,    -1,
     101,    -1,    -1,  2319,   105,    -1,    -1,   108,    -1,    -1,
     111,    -1,   113,    -1,    -1,    -1,    -1,    -1,    -1,   120,
      -1,    -1,    -1,   124,   125,   126,    -1,    -1,   129,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,    -1,   140,
     141,    -1,   143,    -1,   145,    -1,    -1,   148,    -1,    -1,
      -1,    -1,    -1,   154,   155,   156,   157,   158,    -1,   160,
     161,   162,   163,   164,   165,   166,    -1,    -1,    -1,   170,
      -1,    -1,    -1,   174,    -1,    -1,   610,    -1,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,    -1,    -1,   199,    -1,
     265,     6,   267,    -1,   269,    -1,    -1,    -1,    -1,    -1,
     275,    -1,    -1,    -1,    -1,    -1,   217,   218,   219,   220,
     221,   222,    -1,    -1,    -1,    -1,   227,   228,   229,   230,
     231,   232,   233,   234,    -1,   236,   237,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   254,   255,    -1,    -1,    -1,    -1,    -1,
     261,    -1,    -1,    -1,    -1,   266,     3,     4,     5,   270,
      -1,    -1,   273,    10,    11,    12,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      -1,    -1,    -1,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    -1,    -1,    71,    72,    73,    74,    -1,    -1,
      77,    78,    79,    80,    -1,    82,    83,    84,    85,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    96,
      97,    98,    99,    -1,   101,    -1,    -1,    -1,   105,    -1,
      -1,   108,    -1,    -1,   111,    -1,   113,    -1,    -1,    -1,
      -1,    -1,    -1,   120,    -1,    -1,    -1,   124,   125,   126,
      -1,    -1,   129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   138,    -1,   140,   141,    -1,   143,    -1,   145,    -1,
      -1,   148,    -1,    -1,    -1,    -1,    -1,   154,   155,   156,
     157,   158,    -1,   160,   161,   162,   163,   164,   165,   166,
      -1,    -1,    -1,   170,    -1,    -1,    -1,   174,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,     7,    -1,    -1,    -1,
     265,    -1,   199,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     217,   218,   219,   220,   221,   222,    -1,    -1,    -1,    -1,
     227,   228,   229,   230,   231,   232,   233,   234,    -1,   236,
     237,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     944,    -1,    -1,    -1,    -1,    -1,    -1,   254,   255,    -1,
      -1,    -1,    -1,    -1,   261,    -1,    -1,    -1,    -1,   266,
      -1,    -1,    -1,   270,    -1,    -1,   273,     3,     4,     5,
      -1,     7,    -1,   977,    10,    11,    12,    -1,    -1,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    -1,    -1,    -1,    71,    72,    73,    74,    -1,
      -1,    -1,    -1,    -1,    80,    -1,    82,    83,    84,    85,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      96,    97,    98,    99,    -1,   101,    -1,    -1,    -1,   105,
      -1,    -1,   108,    -1,    -1,   111,    -1,   113,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   124,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,    -1,    -1,   145,
      -1,   265,    -1,   267,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   275,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
      -1,    -1,    -1,    -1,   265,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1163,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   210,    -1,    -1,    -1,    -1,    -1,
      -1,   217,   218,   219,   220,   221,    -1,    -1,    -1,    -1,
      -1,   227,   228,   229,   230,   231,   232,   233,   234,    -1,
     236,   237,    -1,   239,   240,   241,   242,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   254,   255,
      -1,    -1,    -1,    -1,    -1,   261,    -1,   263,   264,    -1,
     266,    -1,   268,    -1,    -1,    -1,   272,   273,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,    -1,    -1,    -1,    -1,    10,
      11,    12,    -1,  1267,    15,    16,    17,    18,    19,    20,
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
      -1,    -1,    -1,   154,   155,   156,   157,   158,    -1,   160,
     161,   162,   163,   164,   165,   166,    -1,    -1,    -1,   170,
      -1,    -1,    -1,   174,    -1,    -1,  1430,  1431,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,    -1,    -1,   199,    -1,
     265,    -1,    -1,    -1,    -1,    -1,   271,    -1,    -1,    -1,
     275,    -1,    -1,    -1,    -1,    -1,   217,    -1,     8,    -1,
     221,   222,    -1,    -1,    -1,    -1,   227,   228,   229,    -1,
     231,   232,   233,    -1,    -1,    -1,   237,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   254,   255,    -1,    -1,    -1,    -1,    -1,
     261,    -1,    -1,    -1,    -1,   266,    -1,    -1,    -1,   270,
      -1,    -1,   273,    -1,    -1,    -1,    -1,     3,     4,  1533,
      -1,    -1,     8,    -1,    10,    11,    12,    -1,  1542,    15,
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
     156,   157,   158,    -1,   160,   161,   162,   163,   164,   165,
     166,    -1,    -1,    -1,   170,    -1,    -1,    -1,   174,    -1,
      -1,    -1,  1706,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,    -1,    -1,   199,    -1,   265,    -1,    -1,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   217,    -1,    -1,    -1,   221,   222,    -1,    -1,    -1,
      -1,   227,   228,   229,    -1,   231,   232,   233,    -1,    -1,
      -1,   237,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   254,   255,
      -1,    -1,    -1,    -1,    -1,   261,    -1,    -1,    -1,    -1,
     266,     3,     4,     5,    -1,   271,    -1,   273,    10,    11,
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
      -1,    -1,   154,   155,   156,   157,   158,    -1,   160,   161,
     162,   163,   164,   165,   166,    -1,    -1,    -1,   170,    -1,
      -1,    -1,   174,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,    -1,    -1,    -1,    -1,   265,    -1,   199,    -1,    -1,
      -1,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    96,    97,
      -1,    99,    -1,    -1,    -1,    -1,    -1,   105,    -1,    -1,
     108,    -1,    -1,   111,    -1,   113,    -1,    -1,    -1,    -1,
      -1,    -1,   120,    -1,    -1,    -1,   124,   125,   126,    -1,
      -1,   129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     138,    -1,   140,   141,    -1,   143,    -1,   145,    -1,    -1,
     148,    -1,    -1,    -1,    -1,    -1,   154,   155,   156,   157,
     158,    -1,   160,   161,   162,   163,   164,   165,   166,    -1,
      -1,    -1,   170,    -1,    -1,    -1,   174,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,
      -1,   199,    -1,    -1,    -1,    -1,     8,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   217,
      -1,    -1,    -1,   221,   222,    -1,    -1,    -1,    -1,   227,
     228,   229,    -1,   231,   232,   233,    -1,    -1,    -1,   237,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   254,   255,    -1,    -1,
      -1,    -1,    -1,   261,    -1,    -1,    -1,    -1,   266,     3,
       4,    -1,   270,   271,    -1,   273,    10,    11,    12,    -1,
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
     154,   155,   156,   157,   158,    -1,   160,   161,   162,   163,
     164,   165,   166,    -1,    -1,    -1,   170,    -1,    -1,    -1,
     174,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,    -1,
      -1,    -1,    -1,   265,    -1,   199,    -1,    -1,    -1,    -1,
       8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
      -1,    -1,    -1,    83,    84,    85,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    96,    97,    -1,    99,
      -1,    -1,    -1,    -1,    -1,   105,    -1,    -1,   108,    -1,
      -1,   111,    -1,   113,    -1,    -1,    -1,    -1,    -1,    -1,
     120,    -1,    -1,    -1,   124,   125,   126,    -1,    -1,   129,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,    -1,
     140,   141,    -1,   143,    -1,   145,    -1,    -1,   148,    -1,
      -1,    -1,    -1,    -1,   154,   155,   156,   157,   158,    -1,
     160,   161,   162,   163,   164,   165,   166,    -1,    -1,    -1,
     170,    -1,    -1,    -1,   174,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,    -1,    -1,    -1,    -1,   265,    -1,   199,
      -1,    -1,    -1,    -1,     8,    -1,    -1,    -1,    -1,    -1,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      96,    97,    -1,    99,    -1,    -1,    -1,    -1,    -1,   105,
      -1,    -1,   108,    -1,    -1,   111,    -1,   113,    -1,    -1,
      -1,    -1,    -1,    -1,   120,    -1,    -1,    -1,   124,   125,
     126,    -1,    -1,   129,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   138,    -1,   140,   141,    -1,   143,    -1,   145,
      -1,    -1,   148,    -1,    -1,    -1,    -1,    -1,   154,   155,
     156,   157,   158,    -1,   160,   161,   162,   163,   164,   165,
     166,    -1,    -1,    -1,   170,    -1,    -1,    -1,   174,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,    -1,    -1,    -1,
      -1,   265,    -1,   199,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
      -1,    83,    84,    85,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    96,    97,    -1,    99,    -1,    -1,
      -1,    -1,    -1,   105,    -1,    -1,   108,    -1,    -1,   111,
      -1,   113,    -1,    -1,    -1,    -1,    -1,    -1,   120,    -1,
      -1,    -1,   124,   125,   126,    -1,    -1,   129,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   138,    -1,   140,   141,
      -1,   143,    -1,   145,    -1,    -1,   148,    -1,    -1,    -1,
      -1,    -1,   154,   155,   156,   157,   158,    -1,   160,   161,
     162,   163,   164,   165,   166,    -1,    -1,    -1,   170,    -1,
      -1,    -1,   174,   243,   244,   245,   246,   247,   248,   249,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    96,    97,
      -1,    99,    -1,    -1,    -1,    -1,    -1,   105,    -1,    -1,
     108,    -1,    -1,   111,    -1,   113,    -1,    -1,    -1,    -1,
      -1,    -1,   120,    -1,    -1,    -1,   124,   125,   126,    -1,
      -1,   129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     138,    -1,   140,   141,    -1,   143,    -1,   145,    -1,    -1,
     148,    -1,    -1,    -1,    -1,    -1,   154,   155,   156,   157,
     158,    -1,   160,   161,   162,   163,   164,   165,   166,    -1,
      -1,    -1,   170,    -1,    -1,    -1,   174,   243,   244,   245,
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
      84,    85,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    96,    97,    -1,    99,    -1,    -1,    -1,    -1,
      -1,   105,    -1,    -1,   108,    -1,    -1,   111,    -1,   113,
      -1,    -1,    -1,    -1,    -1,    -1,   120,    -1,    -1,    -1,
     124,   125,   126,    -1,    -1,   129,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   138,    -1,   140,   141,    -1,   143,
      -1,   145,    -1,    -1,   148,    -1,    -1,    -1,    -1,    -1,
     154,   155,   156,   157,   158,    -1,   160,   161,   162,   163,
     164,   165,   166,    -1,    -1,    -1,   170,    -1,    -1,    -1,
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
      -1,    -1,    -1,    83,    84,    85,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    96,    97,    -1,    99,
      -1,    -1,    -1,    -1,    -1,   105,    -1,    -1,   108,    -1,
      -1,   111,    -1,   113,    -1,    -1,    -1,    -1,    -1,    -1,
     120,    -1,    -1,    -1,   124,   125,   126,    -1,    -1,   129,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,    -1,
     140,   141,    -1,   143,    -1,   145,    -1,    -1,   148,    -1,
      -1,    -1,    -1,    -1,   154,   155,   156,   157,   158,    -1,
     160,   161,   162,   163,   164,   165,   166,    -1,    -1,    -1,
     170,    -1,    -1,    -1,   174,   243,   244,   245,   246,   247,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      96,    97,    -1,    99,    -1,    -1,    -1,    -1,    -1,   105,
      -1,    -1,   108,    -1,    -1,   111,    -1,   113,    -1,    -1,
      -1,    -1,    -1,    -1,   120,    -1,    -1,    -1,   124,   125,
     126,    -1,    -1,   129,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   138,    -1,   140,   141,    -1,   143,    -1,   145,
      -1,    -1,   148,    -1,    -1,    -1,    -1,    -1,   154,   155,
     156,   157,   158,    -1,   160,   161,   162,   163,   164,   165,
     166,    -1,    -1,    -1,   170,    -1,    -1,    -1,   174,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,    -1,    -1,    -1,
      -1,   265,    -1,   199,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   275,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   217,    -1,    -1,    -1,   221,   222,    -1,    -1,    -1,
      -1,   227,   228,   229,    -1,   231,   232,   233,    -1,    -1,
      -1,   237,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   254,   255,
      -1,    -1,    -1,    -1,    -1,   261,     3,     4,    -1,    -1,
     266,     8,    -1,    10,    11,    12,    -1,   273,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    59,    60,    61,    62,    -1,    -1,    -1,    -1,
      67,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      77,    78,    79,    -1,    -1,    -1,    83,    84,    85,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    96,
      97,    -1,    99,    -1,    -1,    -1,    -1,    -1,   105,    -1,
      -1,   108,    -1,    -1,   111,    -1,   113,    -1,    -1,    -1,
      -1,    -1,    -1,   120,    -1,    -1,    -1,   124,   125,   126,
      -1,    -1,   129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   138,    -1,   140,   141,    -1,   143,    -1,   145,    -1,
      -1,   148,    -1,    -1,    -1,    -1,    -1,   154,   155,   156,
     157,   158,    -1,   160,   161,   162,   163,   164,   165,   166,
      -1,    -1,    -1,   170,    -1,    -1,    -1,   174,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,    -1,    -1,    -1,    -1,
     265,    -1,   199,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     275,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     217,    -1,    -1,    -1,   221,   222,    -1,    -1,    -1,    -1,
     227,   228,   229,    -1,   231,   232,   233,    -1,    -1,    -1,
     237,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   254,   255,    -1,
      -1,    -1,    -1,    -1,   261,     3,     4,    -1,    -1,   266,
      -1,    -1,    10,    11,    12,    -1,   273,    15,    16,    17,
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
     158,    -1,   160,   161,   162,   163,   164,   165,   166,    -1,
      -1,    -1,   170,    -1,    -1,    -1,   174,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,
      -1,   199,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   275,
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
      84,    85,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    96,    97,    -1,    99,    -1,    -1,    -1,    -1,
      -1,   105,    -1,    -1,   108,    -1,    -1,   111,    -1,   113,
      -1,    -1,    -1,    -1,    -1,    -1,   120,    -1,    -1,    -1,
     124,   125,   126,    -1,    -1,   129,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   138,    -1,   140,   141,    -1,   143,
      -1,   145,    -1,    -1,   148,    -1,    -1,    -1,    -1,    -1,
     154,   155,   156,   157,   158,    -1,   160,   161,   162,   163,
     164,   165,   166,    -1,    -1,    -1,   170,    -1,    -1,    -1,
     174,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,    -1,
      -1,    -1,    -1,   265,    -1,   199,    -1,    -1,    -1,    -1,
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
      -1,    -1,    -1,    83,    84,    85,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    96,    97,    -1,    99,
      -1,    -1,    -1,    -1,    -1,   105,    -1,    -1,   108,    -1,
      -1,   111,    -1,   113,    -1,    -1,    -1,    -1,    -1,    -1,
     120,    -1,    -1,    -1,   124,   125,   126,    -1,    -1,   129,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,    -1,
     140,   141,    -1,   143,    -1,   145,    -1,    -1,   148,    -1,
      -1,    -1,    -1,    -1,   154,   155,   156,   157,   158,    -1,
     160,   161,   162,   163,   164,   165,   166,    -1,    -1,    -1,
     170,    -1,    -1,    -1,   174,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,    -1,    -1,    -1,    -1,   265,    -1,   199,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   275,    -1,    -1,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      96,    97,    -1,    99,    -1,    -1,    -1,    -1,    -1,   105,
      -1,    -1,   108,    -1,    -1,   111,    -1,   113,    -1,    -1,
      -1,    -1,    -1,    -1,   120,    -1,    -1,    -1,   124,   125,
     126,    -1,    -1,   129,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   138,    -1,   140,   141,    -1,   143,    -1,   145,
      -1,    -1,   148,    -1,    -1,    -1,    -1,    -1,   154,   155,
     156,   157,   158,    -1,   160,   161,   162,   163,   164,   165,
     166,    -1,    -1,    -1,   170,    -1,    -1,    -1,   174,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,    -1,    -1,    -1,
      -1,   265,    -1,   199,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   275,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   217,    -1,    -1,    -1,   221,   222,    -1,    -1,    -1,
      -1,   227,   228,   229,    -1,   231,   232,   233,    -1,    -1,
      -1,   237,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   254,   255,
      -1,    -1,    -1,    -1,    -1,   261,     3,     4,     5,    -1,
     266,    -1,    -1,    10,    11,    12,    -1,   273,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    -1,    -1,    -1,    71,    72,    73,    74,    -1,    -1,
      -1,    -1,    -1,    80,    -1,    82,    83,    84,    85,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    96,
      97,    98,    99,    -1,   101,     3,     4,     5,    -1,    -1,
      -1,    -1,    10,    11,    12,    -1,    -1,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      -1,    -1,    -1,    71,    72,    73,    74,    -1,    -1,    -1,
      -1,    -1,    80,    -1,    82,    83,    84,    85,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    96,    97,
      98,    99,    -1,   101,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     217,   218,   219,   220,   221,    -1,    -1,    -1,    -1,    -1,
     227,   228,   229,   230,   231,   232,   233,   234,    -1,   236,
     237,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   254,   255,    -1,
      -1,    -1,    -1,    -1,   261,    -1,    -1,    -1,    -1,   266,
      -1,    -1,    -1,   270,    -1,    -1,   273,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   275,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   217,
     218,   219,   220,   221,    -1,    -1,    -1,    -1,    -1,   227,
     228,   229,   230,   231,   232,   233,   234,    -1,   236,   237,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   254,   255,    -1,    -1,
      -1,    -1,    -1,   261,    -1,    -1,    -1,    -1,   266,     3,
       4,     5,   270,    -1,    -1,   273,    10,    11,    12,    -1,
      -1,    15,    16,    17,    18,    19,    20,    21,    22,    23,
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
     255,    -1,    -1,    -1,    -1,    -1,   261,     3,     4,    -1,
       6,   266,    -1,    -1,    10,    11,    12,    -1,   273,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    59,    60,    61,    62,    -1,    -1,    -1,
      -1,    67,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    83,    84,    85,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,    -1,
      96,    97,    -1,    99,    10,    11,    12,    -1,    -1,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    59,    60,    61,    62,    -1,    -1,    -1,
      -1,    67,    -1,    -1,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,    83,    84,    85,
     121,   122,   123,   124,    -1,    -1,    -1,    -1,   129,    -1,
      96,    97,    -1,    99,    -1,    -1,    -1,   138,   139,    -1,
      -1,   142,   143,    -1,   145,   146,    -1,   148,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   217,    -1,    -1,    -1,   221,   167,    -1,    -1,    -1,
      -1,   227,   228,   229,    -1,   231,   232,   233,    -1,    -1,
      -1,   237,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   194,   195,   196,    -1,    -1,   254,   255,
      -1,    -1,    -1,    -1,    -1,   261,    -1,    -1,    -1,    -1,
     266,    -1,    -1,    -1,    -1,    -1,    -1,   273,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,    -1,    -1,    -1,    -1,
     265,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     275,   217,    -1,    -1,    -1,   221,    -1,    -1,    -1,    -1,
      -1,   227,   228,   229,    -1,   231,   232,   233,    -1,    -1,
     271,   237,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   254,   255,
      -1,    -1,    -1,    -1,    -1,   261,    -1,    -1,    -1,    -1,
     266,     3,     4,    -1,   270,    -1,    -1,   273,    10,    11,
      12,    -1,    -1,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,    60,    61,
      62,    -1,    -1,    -1,    -1,    67,    13,    14,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    83,    84,    85,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     3,     4,    -1,    96,    97,     8,    99,    10,    11,
      12,    -1,    -1,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,    60,    61,
      62,    -1,    -1,    -1,    -1,    67,    -1,    -1,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,    83,    84,    85,   121,   122,   123,   124,    -1,    -1,
      -1,    -1,   129,    -1,    96,    97,    -1,    99,    -1,    -1,
      -1,   138,   139,    -1,    -1,   142,   143,    -1,   145,   146,
      -1,   148,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   217,    -1,    -1,    -1,   221,
     167,    -1,    -1,    -1,    -1,   227,   228,   229,    -1,   231,
     232,   233,    -1,    -1,    -1,   237,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   194,   195,   196,
      -1,    -1,   254,   255,    -1,    -1,    -1,    -1,    -1,   261,
      -1,    -1,    -1,    -1,   266,    -1,    -1,    -1,   270,    -1,
      -1,   273,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
      -1,    -1,    -1,    -1,   265,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   275,   217,    -1,    -1,    -1,   221,
      -1,    -1,    -1,    -1,    -1,   227,   228,   229,    -1,   231,
     232,   233,    -1,    -1,   271,   237,    -1,    -1,    -1,    -1,
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
      -1,    -1,    -1,    96,    97,    -1,    99,     3,     4,    -1,
       6,    -1,    -1,    -1,    10,    11,    12,    -1,    -1,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    59,    60,    61,    62,    -1,    -1,    -1,
      -1,    67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    83,    84,    85,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      96,    97,    -1,    99,    -1,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,    -1,   217,    -1,    -1,   265,   221,    -1,
      -1,    -1,    -1,    -1,   227,   228,   229,   275,   231,   232,
     233,    -1,    -1,    -1,   237,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   254,   255,    -1,    -1,    -1,    -1,    -1,   261,    -1,
      -1,    -1,    -1,   266,   267,    -1,    -1,    -1,    -1,    -1,
     273,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,    -1,
      -1,    -1,    -1,   265,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   275,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   217,    -1,    -1,    -1,   221,    -1,    -1,    -1,    -1,
      -1,   227,   228,   229,    -1,   231,   232,   233,    -1,    -1,
      -1,   237,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   254,   255,
      -1,    -1,    -1,    -1,    -1,   261,     3,     4,    -1,     6,
     266,    -1,    -1,    10,    11,    12,    -1,   273,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    59,    60,    61,    62,    -1,    -1,    -1,    -1,
      67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    83,    84,    85,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    96,
      97,    -1,    99,     3,     4,    -1,     6,    -1,    -1,    -1,
      10,    11,    12,    -1,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,
      60,    61,    62,    -1,    -1,    -1,    -1,    67,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    83,    84,    85,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    96,    97,    -1,    99,
      -1,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,    -1,
     217,    -1,    -1,   265,   221,    -1,    -1,    -1,    -1,    -1,
     227,   228,   229,   275,   231,   232,   233,    -1,    -1,    -1,
     237,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   254,   255,    -1,
      -1,    -1,    -1,    -1,   261,    -1,     3,     4,    -1,   266,
      -1,    -1,    -1,    10,    11,    12,   273,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   217,    -1,    -1,
      -1,   221,    59,    60,    61,    62,    -1,   227,   228,   229,
      67,   231,   232,   233,    -1,    -1,    -1,   237,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    83,    84,    85,    -1,
      -1,    -1,    -1,    -1,   254,   255,    -1,    -1,    -1,    96,
      97,   261,    99,     3,     4,    -1,   266,    -1,    -1,    -1,
      10,    11,    12,   273,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,
      60,    61,    62,    -1,    -1,    -1,    -1,    67,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    83,    84,    85,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    96,    97,    -1,    99,
      -1,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,    -1,
     217,    -1,    -1,   265,   221,    -1,    -1,    -1,    -1,    -1,
     227,   228,   229,   275,   231,   232,   233,    -1,    -1,    -1,
     237,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   254,   255,    -1,
      -1,    -1,    -1,    -1,   261,    -1,     3,     4,    -1,   266,
     267,    -1,    -1,    10,    11,    12,   273,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   217,    -1,    -1,
      -1,   221,    59,    60,    61,    62,    -1,   227,   228,   229,
      67,   231,   232,   233,    -1,    -1,    -1,   237,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    83,    84,    85,    -1,
      -1,    -1,    -1,    -1,   254,   255,    -1,    -1,    -1,    96,
      97,   261,    99,     3,     4,    -1,   266,   267,    -1,    -1,
      10,    11,    12,   273,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,
      60,    61,    62,    -1,    -1,    -1,    -1,    67,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    83,    84,    85,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    96,    97,    -1,    99,
      -1,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,    -1,
     217,    -1,    -1,   265,   221,    -1,    -1,    -1,    -1,    -1,
     227,   228,   229,   275,   231,   232,   233,    -1,    -1,    -1,
     237,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    13,
      14,    -1,    -1,    -1,    -1,    -1,    -1,   254,   255,    -1,
      -1,    -1,    -1,    -1,   261,    -1,    -1,    -1,    -1,   266,
      -1,    -1,    -1,   270,    -1,    -1,   273,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   275,
      -1,    -1,    13,    14,    -1,    -1,    -1,   217,    -1,    -1,
      -1,   221,    -1,    -1,    -1,    -1,    -1,   227,   228,   229,
      -1,   231,   232,   233,    -1,    -1,    -1,   237,    -1,    -1,
      -1,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   254,   255,    -1,   121,   122,   123,
     124,   261,    -1,    -1,    -1,   129,   266,    -1,    -1,    -1,
      -1,    -1,    -1,   273,   138,   139,    13,    14,   142,   143,
      -1,   145,   146,    -1,   148,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   167,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,    -1,    -1,    -1,
     121,   122,   123,   124,    -1,    -1,    -1,    -1,   129,    -1,
     194,   195,   196,    -1,    -1,    -1,    -1,   138,   139,    13,
      14,   142,   143,    -1,   145,   146,    -1,   148,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   167,    -1,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,    -1,    -1,    -1,   121,   122,   123,   124,    -1,    -1,
      -1,    -1,   129,   194,   195,   196,    -1,    -1,    -1,    -1,
      -1,   138,   139,    13,    14,   142,   143,   271,   145,   146,
      -1,   148,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     167,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,    -1,    -1,    -1,   121,   122,   123,
     124,    -1,    -1,    -1,    -1,   129,    -1,   194,   195,   196,
      -1,    -1,    -1,    -1,   138,   139,    13,    14,   142,   143,
     271,   145,   146,    -1,   148,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   167,    -1,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,    -1,    -1,
      -1,   121,   122,   123,   124,    -1,    -1,    -1,    -1,   129,
     194,   195,   196,    -1,    -1,    -1,    -1,    -1,   138,   139,
      13,    14,   142,   143,   271,   145,   146,    -1,   148,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   167,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,    -1,    -1,    -1,   121,   122,   123,   124,    -1,    -1,
      -1,    -1,   129,    -1,   194,   195,   196,    -1,    -1,    -1,
      -1,   138,   139,    13,    14,   142,   143,   271,   145,   146,
      -1,   148,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     167,    -1,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,    -1,    -1,    -1,   121,   122,
     123,   124,    -1,    -1,    -1,    -1,   129,   194,   195,   196,
      -1,    -1,    -1,    -1,    -1,   138,   139,    13,    14,   142,
     143,   271,   145,   146,    -1,   148,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   167,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,    -1,    -1,
      -1,   121,   122,   123,   124,    -1,    -1,    -1,    -1,   129,
      -1,   194,   195,   196,    -1,    -1,    -1,    -1,   138,   139,
      13,    14,   142,   143,   271,   145,   146,    -1,   148,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   167,    -1,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,    -1,    -1,    -1,   121,   122,   123,   124,    -1,
      -1,    -1,    -1,   129,   194,   195,   196,    -1,    -1,    -1,
      -1,    -1,   138,   139,    13,    14,   142,   143,   271,   145,
     146,    -1,   148,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   167,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,    -1,    -1,    -1,   121,   122,
     123,   124,    -1,    -1,    -1,    -1,   129,    -1,   194,   195,
     196,    -1,    -1,    -1,    -1,   138,   139,    13,    14,   142,
     143,   271,   145,   146,    -1,   148,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   167,    -1,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,    -1,
      -1,    -1,   121,   122,   123,   124,    -1,    -1,    -1,    -1,
     129,   194,   195,   196,    -1,    -1,    -1,    -1,    -1,   138,
     139,    -1,    -1,   142,   143,   271,   145,   146,    -1,   148,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   167,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,    -1,    -1,    -1,   121,   122,   123,   124,    -1,
      -1,    -1,    -1,   129,    -1,   194,   195,   196,    -1,    -1,
      -1,    -1,   138,   139,    -1,    -1,   142,   143,   271,   145,
     146,    -1,   148,    -1,    -1,    -1,     0,     1,    -1,    -1,
       4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    13,
      14,   167,    -1,    -1,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,    -1,    -1,    -1,    -1,   265,    -1,   194,   195,
     196,    -1,    -1,    47,    48,    49,   275,    -1,    -1,    -1,
      -1,    -1,   271,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    68,    69,    70,    -1,    -1,    -1,
      -1,    75,    76,    -1,    -1,    -1,    -1,    81,    -1,    -1,
      -1,    -1,    86,    87,    88,    89,    90,    91,    92,    -1,
      94,    95,    -1,    97,    -1,    -1,    -1,    -1,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,    -1,   271,   120,   121,   122,   123,
     124,    -1,    -1,   127,    -1,   129,    -1,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,    -1,    -1,   150,   151,   152,    -1,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,    -1,    -1,    -1,   182,   183,
     184,    -1,    -1,    -1,   188,    -1,    -1,    -1,    -1,   193,
     194,   195,   196,    -1,    -1,   199,    -1,   201,    -1,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,    -1,     4,    -1,    -1,    -1,    -1,   223,
     224,   225,   226,    13,    14,    -1,    -1,    -1,    -1,    -1,
      -1,   235,    -1,   237,   238,    -1,    -1,    -1,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,    -1,    47,    48,    49,
     265,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     275,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    68,    69,
      70,    -1,    -1,    -1,    -1,    75,    76,    -1,    -1,    -1,
      -1,    81,    -1,    -1,    -1,    -1,    86,    87,    88,    89,
      90,    91,    92,    -1,    94,    95,    -1,    97,    -1,    -1,
      -1,    -1,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,    -1,    -1,
     120,   121,   122,   123,   124,    -1,    -1,   127,    -1,   129,
      -1,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,    -1,    -1,
     150,   151,   152,    -1,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,    -1,
      -1,    -1,   182,   183,   184,    -1,    -1,    -1,   188,    -1,
      -1,    -1,    -1,   193,   194,   195,   196,     4,     5,   199,
      -1,   201,    -1,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,    -1,    -1,    -1,
      -1,    -1,    -1,   223,   224,   225,   226,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   235,    -1,   237,   238,    -1,
      -1,    -1,    -1,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    -1,    -1,    -1,    -1,    63,    64,    65,    66,
      -1,     4,     5,    -1,    71,    72,    73,    74,    -1,    -1,
      -1,    -1,    -1,    80,    -1,    82,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    98,    -1,    -1,   101,    -1,    -1,    -1,   105,    -1,
      -1,   108,    -1,    -1,   111,    -1,   113,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    -1,   124,    -1,    -1,
      63,    64,    65,    66,     4,     5,    -1,    -1,    71,    72,
      73,    74,    -1,    -1,    -1,    -1,    -1,    80,   145,    82,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    98,    -1,    -1,   101,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    -1,
      -1,    -1,    -1,    63,    64,    65,    66,     5,    -1,    -1,
      -1,    71,    72,    73,    74,    -1,    -1,    -1,    -1,    -1,
      80,    -1,    82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   218,   219,   220,    -1,    -1,    13,    14,    98,    -1,
      -1,   101,    -1,   230,    -1,    -1,    -1,   234,    -1,   236,
     237,    -1,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    -1,    -1,    -1,    -1,    63,    64,    65,    66,    -1,
      -1,    -1,    -1,    71,    72,    73,    74,    -1,    -1,    -1,
      -1,    -1,    80,    -1,    82,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   218,   219,   220,    -1,    -1,
      98,    -1,    -1,   101,    -1,    -1,    -1,   230,    -1,    -1,
      -1,   234,    -1,   236,   237,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,    -1,    -1,    -1,   121,   122,   123,   124,    -1,    -1,
      -1,    -1,   129,    -1,    -1,    -1,    -1,    -1,   218,   219,
     220,   138,   139,    -1,    -1,   142,   143,    -1,   145,   146,
     230,   148,    -1,    -1,   234,    -1,   236,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     167,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,    -1,
      -1,    -1,    -1,   265,    -1,    -1,    -1,   194,   195,   196,
     218,   219,   220,   275,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   230,    -1,    -1,    -1,   234,    -1,   236,   243,
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
      -1,    -1,    -1,   270,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,    -1,    -1,    -1,    -1,   265,    -1,    -1,    -1,
      -1,   270,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
      -1,    -1,    -1,    -1,   265,    -1,    -1,    -1,    -1,   270,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,    -1,    -1,
      -1,    -1,   265,    -1,   267,    -1,   269,   243,   244,   245,
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
      -1,    -1,    -1,   265,    -1,    -1,    -1,   269,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,    -1,    -1,    -1,    -1,
     265,    -1,    -1,    -1,   269,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,    -1,    -1,    -1,    -1,   265,    -1,    -1,
      -1,   269,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
      -1,    -1,    -1,    -1,   265,    -1,   267,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,
      -1,   267,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
      -1,    -1,    -1,    -1,   265,    -1,   267,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,
      -1,   267,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
      -1,    -1,    -1,    -1,   265,    -1,   267,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,
      -1,   267,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
      -1,    -1,    -1,    -1,   265,    -1,   267,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,
      -1,   267,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
      -1,    -1,    -1,    -1,   265,    -1,   267,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,
      -1,   267,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
      -1,    -1,    -1,    -1,   265,    -1,   267,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,
      -1,   267,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
      -1,    -1,    -1,    -1,   265,    -1,   267,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,
      -1,   267,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
      -1,    -1,    -1,    -1,   265,    -1,   267,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,
      -1,   267,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
      -1,    -1,    -1,    -1,   265,    -1,   267,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,
      -1,   267,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
      -1,    -1,    -1,    -1,   265,    -1,   267,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,
      -1,   267,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
      -1,    -1,    -1,    -1,   265,    -1,   267,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,
      -1,   267,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
      -1,    -1,    -1,    -1,   265,    -1,   267,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,
      -1,   267,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
      -1,    -1,    -1,    -1,   265,    -1,   267,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,
      -1,   267,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
      -1,    -1,    -1,    -1,   265,    -1,   267,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,
      -1,   267,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
      -1,    -1,    -1,    -1,   265,    -1,   267,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,
      -1,   267,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
      -1,    -1,    -1,    -1,   265,    -1,   267,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,
      -1,   267,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
      -1,    -1,    -1,    -1,   265,    -1,   267,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,
      -1,   267,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
      -1,    -1,    -1,    -1,   265,    -1,   267,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,
      -1,   267,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
      -1,    -1,    -1,    -1,   265,    -1,   267,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,
      -1,   267,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
      -1,    -1,    -1,    -1,   265,    -1,   267,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,
      -1,   267,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
      -1,    -1,    -1,    -1,   265,    -1,   267,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,
      -1,   267,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
      -1,    -1,    -1,    -1,   265,    -1,   267,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,
      -1,   267,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
      -1,    -1,    -1,    -1,   265,    -1,   267,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,
      -1,   267,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
      -1,    -1,    -1,    -1,   265,    -1,   267,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,
      -1,   267,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
      -1,    -1,    -1,    -1,   265,    -1,   267,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,
      -1,   267,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
      -1,    -1,    -1,    -1,   265,    -1,   267,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,
      -1,   267,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
      -1,    -1,    -1,    -1,   265,    -1,   267,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,
      -1,   267,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
      -1,    -1,    -1,    -1,   265,    -1,   267,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,
      -1,   267,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
      -1,    -1,    -1,    -1,   265,    -1,   267,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,
      -1,   267,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
      -1,    -1,    -1,    -1,   265,    -1,   267,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,
      -1,   267,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
      -1,    -1,    -1,    -1,   265,    -1,   267,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,
      -1,   267,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
      -1,    -1,    -1,    -1,   265,    -1,   267,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,
      -1,   267,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
      -1,    -1,    -1,    -1,   265,    -1,   267,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,
      -1,   267,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
      -1,    -1,    -1,    -1,   265,    -1,   267,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,    -1,    -1,    -1,    -1,   265
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
     129,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   150,   151,
     152,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   182,   183,   184,   188,
     193,   194,   195,   196,   199,   201,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     223,   224,   225,   226,   235,   237,   238,   279,   281,   282,
     303,   322,   324,   328,   331,   332,   333,   334,   335,   336,
     337,   338,   339,   346,   348,   349,   355,   356,   357,   358,
     364,   389,   390,   270,   274,    14,   111,   266,   266,   266,
       6,   270,     6,     6,     6,     6,   266,     6,   270,     6,
     270,   270,     6,     6,     6,     6,   268,   268,     4,   366,
     390,   266,   268,   300,   105,   108,   111,   113,   324,   300,
     266,   266,   266,     4,   266,   266,   266,     4,   266,   266,
     266,   266,   266,   266,   266,   266,   266,   266,   266,   270,
     128,   111,     6,     6,   270,   270,   105,   108,   111,   124,
     327,   113,   266,     3,    10,    11,    12,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    59,
      60,    61,    62,    67,    68,    77,    78,    79,    83,    84,
      85,    96,    99,   105,   108,   111,   113,   124,   125,   126,
     129,   138,   143,   145,   148,   199,   217,   221,   222,   227,
     228,   229,   231,   232,   233,   254,   255,   261,   266,   270,
     273,   324,   325,   328,   339,   346,   348,   359,   360,   364,
     366,   372,   375,   390,   266,   270,   270,   111,   111,   138,
     108,   111,   113,   324,   108,   111,   112,   113,   124,   194,
     325,   108,   111,   266,   108,   171,   199,   215,   216,   270,
     254,   255,   266,   270,   369,   370,   369,   270,   270,   369,
       4,   105,   109,   115,   116,   118,   119,   142,   270,   270,
     266,   111,   113,   111,   108,     4,    97,   210,   270,   390,
       4,     6,   105,     6,   108,   111,   108,   111,   124,   326,
       5,   266,   270,   372,   374,   111,     4,     4,     4,   374,
       4,   111,   266,   111,   266,   266,     4,   270,   377,   390,
       4,   266,   266,   266,     6,    33,   255,   359,   390,     6,
     268,     5,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    63,    64,    65,    66,    71,    72,    73,    74,    80,
      82,    98,   101,   218,   219,   220,   230,   234,   236,   381,
     390,   266,     4,   381,     5,   270,     5,   270,   324,   359,
     268,     6,   270,   266,   270,     6,   266,   270,     6,   274,
       7,   145,   210,   239,   240,   241,   242,   263,   264,   266,
     268,   272,   298,   299,   300,   324,   359,   380,   381,   390,
       4,   328,   329,   330,   270,     6,   359,   380,   381,   390,
     380,   380,   359,   380,   387,   388,   390,   359,   330,   359,
     305,   309,   266,   368,     9,   381,   266,   381,   359,   359,
     359,   266,   359,   359,   359,   266,   359,   359,   359,   359,
     359,   359,   359,   380,   359,   359,   359,   359,   374,   266,
     255,   359,   375,   376,   376,   270,   374,   372,   380,   300,
     300,   300,   300,   300,   300,   300,   300,   300,   300,   300,
     300,   300,   300,   300,   300,   300,   300,   300,   300,   300,
     300,   300,   300,   300,   300,   266,   268,   300,   300,   300,
     300,   300,   300,   266,   300,   300,   266,   324,   325,   325,
     325,   300,   300,     5,   270,   270,   111,   108,   111,    68,
     105,   138,   324,   324,   325,   266,   300,   300,   266,   266,
     266,   359,   270,   359,   375,   359,   359,   271,   376,   366,
     390,   202,     5,   270,     8,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   265,     9,   266,   268,   272,   299,   300,
     359,   376,   376,   266,   266,   266,   372,   374,   374,   374,
     323,   266,   270,   266,   266,   372,   270,   270,   359,     4,
     372,   270,   377,   270,   270,   369,   369,   369,   359,   359,
     254,   255,   270,   270,   369,   254,   255,   266,   330,   369,
     270,   266,   270,   266,   266,   266,   266,   266,   266,   266,
     376,   376,   359,   374,   374,   374,   266,   270,     4,   268,
     270,     6,   268,   330,     6,     6,   270,   270,   270,   270,
     374,   359,     8,     7,   270,   268,   268,   268,     6,     6,
     266,   359,   266,   359,   359,   272,   359,   270,   202,   359,
     359,   359,   300,   359,     6,   256,     9,   266,   268,   272,
     359,   300,   300,   300,   266,   266,   266,   300,   300,   300,
     300,   300,   300,   300,   300,   300,   300,   266,   266,   300,
     266,   268,     6,     6,   270,     6,     8,   330,     6,     8,
     330,   266,   270,   380,   376,   359,   330,   372,   372,   270,
     381,   324,     7,   359,   359,     4,    26,    37,    38,   114,
     115,   199,   200,   302,   372,     6,   267,   269,   270,   301,
     270,     6,   270,     6,     9,   266,   268,   272,   390,   271,
     138,   143,   145,   146,   148,   322,   324,   359,     6,   267,
     275,     9,   266,   268,   272,   267,   275,   267,   275,   275,
     267,   275,     9,   266,   272,   275,   271,   275,   269,   275,
     304,   269,   304,   100,   367,   365,   390,   275,   359,   275,
     267,   267,   267,   359,   267,   267,   267,   359,   267,   267,
     267,   267,   267,   267,   267,   267,   267,   267,   267,   271,
       7,   359,   256,   271,   275,   271,   359,     6,     6,   267,
     359,   359,   359,   359,   359,   359,   359,   359,   359,   359,
     359,   359,   359,   359,   359,   359,   359,   359,   375,   359,
     359,   359,   359,   359,   359,   359,   359,   359,   375,   375,
     390,   270,   359,   359,   380,   359,   380,   372,   380,   380,
     387,   270,   270,   270,   270,   359,   301,   390,     8,   359,
     359,   270,   270,   270,   326,   270,   374,   372,   270,   380,
     380,   375,   366,   381,   366,   376,   267,   271,   272,   300,
      68,     8,   359,   359,   359,   359,   359,   359,   359,   359,
     359,   359,   359,   359,   359,   359,   270,   359,   375,   359,
     359,   359,   359,   359,   390,   359,   359,   302,   270,   301,
     267,   271,   271,   359,   359,   359,     7,     7,   352,   352,
     266,   359,   359,   359,   359,     6,   175,   376,   376,   270,
     267,     6,   330,   270,   330,   330,   275,   275,   275,   369,
     369,   329,   329,   275,   359,   271,   343,   275,   330,   359,
     359,   359,   359,   359,   359,   359,   359,   359,   271,   271,
     267,     7,   353,     6,     7,   359,   359,     6,   359,   330,
     359,   271,   376,   376,   376,   359,     6,   267,   271,   359,
     376,   359,   359,   359,   359,   267,   359,   267,   267,   199,
     275,   330,   270,     8,   267,   267,   359,   359,   390,   302,
     269,   387,   380,   387,   380,   380,   380,   380,   380,   380,
     359,   380,   380,   380,   380,   273,   383,   390,   381,   380,
     380,   380,   366,   390,   376,   271,   271,   271,   271,   359,
     330,   269,   271,   267,   152,   171,   347,   267,   271,   275,
     359,     6,   270,   372,   267,   269,   272,     7,     7,   298,
     299,     6,   376,     7,   242,   298,   359,   283,   390,   359,
     359,   302,   268,   266,   138,   324,   325,   324,   270,   271,
       6,   249,   250,   280,   376,   390,   359,   359,   302,     6,
     376,     6,   376,   359,     6,   380,   388,   390,   267,   302,
     359,   359,     6,   390,     6,   380,   359,   267,   268,   359,
     275,   381,     7,     7,     7,   267,     7,     7,     7,   267,
       7,     7,     7,     7,     7,     7,     7,     7,     7,     7,
     359,   267,   270,   359,   375,     6,   270,   271,     6,   301,
     301,   301,   301,   301,   301,   301,   301,   301,   301,   301,
     301,   275,   301,   301,   301,   301,   301,   301,   301,   301,
     301,   275,   275,   275,   275,   275,   267,   269,   269,   376,
     275,   275,   301,   275,   301,   275,   275,   275,   267,   376,
     359,   359,   359,   361,   301,   271,   271,   271,   359,   359,
     359,   270,   359,   359,   275,   275,   301,   301,   267,   272,
     267,   272,   275,   300,   362,   271,     7,   302,   301,   372,
     271,     8,     8,   376,   272,   267,   269,   266,   268,   299,
     300,   376,     7,   270,   270,   267,   267,   267,   359,   372,
       4,   351,     6,   318,   359,   381,   267,   271,   267,   267,
     359,   271,   271,   376,   272,   271,   330,   271,   271,   369,
     359,   359,   271,   271,   359,   369,   149,   149,   168,   179,
     180,   181,   185,   186,   344,   345,   369,   271,   340,   267,
     271,   267,   267,   267,   267,   267,   267,   267,   270,   270,
       7,   359,     6,   359,   267,   271,   269,   271,   269,   271,
     271,   271,   271,     6,   271,   269,   269,   275,   267,     7,
     267,     7,     7,   272,   359,   271,   359,   359,   272,   266,
     268,     7,   272,   301,   275,   301,   301,   267,   267,   275,
     301,   301,   275,   275,   301,   301,   301,   301,   359,   301,
       9,   382,   275,   267,   275,   301,   272,   275,   363,   269,
     271,   267,   271,   274,   202,     7,   171,     6,   359,   271,
     270,     6,   372,   271,   359,     6,     7,   298,   299,   272,
     298,   299,   302,   270,   378,   390,   381,   359,     6,   271,
      50,    50,   372,   271,     4,   189,   190,   191,   192,   271,
     286,   290,   293,   295,   296,   338,   272,   267,   269,   266,
     359,   359,   266,   270,   266,   270,     8,   376,   380,   267,
     272,   267,   269,   266,   267,   267,   275,   272,   266,   271,
     275,     7,   300,     4,    26,    37,    38,   312,   313,   314,
     301,   359,   301,   369,   372,   372,     7,   372,   372,   372,
       7,   372,   372,   372,   372,   372,   372,   372,   372,   372,
     372,     6,     7,   376,   329,   359,   359,   359,   359,   359,
     359,   271,   359,   359,   359,   372,   380,   380,   271,   271,
     271,   271,   275,   311,   271,   271,   271,   359,   271,   271,
     359,   359,   302,   302,   359,   359,   267,   372,   300,   359,
     359,   271,   302,   299,   272,   299,   359,   359,   301,   271,
     372,   376,   376,     7,     7,     7,   149,   350,     6,   267,
     275,     7,     7,     7,     6,     7,     7,   271,     4,   302,
     271,   275,   275,   275,   271,   271,   123,     4,     6,   359,
     270,     6,   266,     6,   187,     6,   187,   271,   345,   275,
     344,     7,     6,     7,     7,     7,     7,     7,     7,     7,
     329,   329,   372,     6,   270,   105,     6,     6,     6,   111,
       7,     7,     6,     6,   359,     7,   372,     7,   372,   372,
       4,   275,     8,     8,   267,   302,   302,   302,   376,   380,
     359,   380,   273,   275,   315,   380,   380,   302,   380,   267,
     275,     6,   270,   324,   270,     6,   359,     6,   270,   372,
     271,   271,   359,     6,   199,   200,   302,   359,     6,     7,
     377,   379,     6,   268,     6,     6,   301,   300,   300,     6,
     287,   266,   266,   270,   297,     6,   302,   272,   380,   359,
     269,   267,   359,     8,   376,   359,   376,   271,   271,     6,
       6,   280,   302,   272,   359,     6,     6,   359,   302,   267,
       6,   359,   270,   359,   381,   301,    50,   270,   372,   381,
     384,   359,   359,   359,   269,   275,     6,   267,     6,     6,
     142,   320,   320,   372,     6,     6,     6,   372,   149,   202,
     319,     6,     6,     6,     6,     6,     6,     6,     6,     6,
       5,   271,   271,   301,   301,   301,   301,   301,   301,   301,
     275,   275,   275,   267,   301,   301,   313,   301,   129,   129,
     129,   271,   202,   267,   301,   267,   300,   362,   301,     6,
     301,   266,   268,   300,   302,   267,   269,   301,     6,   271,
     271,   372,   372,   372,     4,     6,   298,   359,   372,   372,
     372,   270,   270,     7,     6,     7,   359,   359,   359,   270,
     270,   270,   268,     6,   359,   372,   359,     6,     6,   359,
     369,   271,     5,   372,   270,   270,   270,   270,   270,   270,
     270,   372,   271,   271,     6,   376,   270,   270,   359,   359,
     269,   372,     6,   372,     6,   198,   359,   359,   359,   266,
     268,     6,     6,     7,   301,   275,   275,   301,   275,   359,
       4,   214,   316,   317,   301,   267,   301,   363,   381,   359,
     270,   330,     6,   330,   275,     6,     6,   272,     7,     7,
     298,   299,     6,   377,   271,   275,   359,   298,   270,   301,
     385,   386,   387,   385,   266,   359,   359,   371,   372,   270,
     266,     4,     6,   267,     6,   267,   271,   271,   267,   271,
       6,     6,   380,   266,     4,   267,   275,   266,   271,   275,
     372,   381,     7,   300,   310,   359,   375,   314,     6,   369,
       6,     6,     6,   149,   321,   105,   124,   109,     6,     5,
     270,     6,   359,   359,   359,   270,   270,   270,   111,   359,
     267,   362,   359,   359,   301,   299,   270,   270,     6,   319,
       6,   359,   372,   149,   149,     4,     6,   376,   376,   359,
     359,   381,   271,   267,   271,   275,   329,   329,   359,   359,
     271,   275,   267,   271,   275,     6,     6,   371,   369,   369,
     369,   369,   369,   255,   369,     6,   271,   376,   359,     6,
       6,     6,     6,     6,   372,   271,   275,     8,   271,   267,
     255,   270,   359,   373,   381,   380,   359,   380,   359,   381,
     384,   386,   381,   275,   267,   275,   271,   359,   347,   347,
     372,   302,   378,   381,   359,     6,     6,   377,   269,   372,
     387,     6,   301,   301,   284,   359,   275,   275,   271,   275,
     285,   359,   359,     6,     6,     6,     6,   359,   359,   267,
       6,   359,   306,   308,   270,   386,   271,   275,     7,     7,
     153,     6,   270,   270,   270,     5,   371,   301,   301,   275,
     359,   359,   359,   270,   301,   267,   267,   269,   376,   376,
       6,     6,   359,   359,   270,   271,   271,   270,     6,     6,
     270,   359,   271,   271,   271,   269,     6,   372,     7,   270,
     359,   271,   275,   275,   275,   275,   275,   275,     6,   271,
     271,   197,   359,   359,   270,   271,   376,     6,     6,     6,
     267,   301,   301,   317,   381,   271,   271,   271,   271,     7,
       6,     6,     6,   272,     6,   271,     6,     6,   267,   275,
     359,   359,   270,   372,   271,   275,   267,   267,   275,   271,
     311,   315,   372,   301,   359,   381,   390,   376,   376,   359,
       6,   271,   359,   275,   271,   275,   359,   362,   271,   271,
       6,     6,   371,   154,   155,   160,   354,   154,   155,   354,
     376,   329,   271,   275,     6,   271,   372,   330,   271,     6,
     376,   369,   369,   369,   369,   369,     6,   359,   271,   271,
     376,   271,   267,     6,   270,     6,   377,   200,   288,   359,
     275,   275,   371,     6,   359,   359,     6,   271,   271,   307,
       7,   266,   271,   271,   271,   270,   275,   359,   359,   271,
     267,   270,   271,   270,   369,   372,     6,   270,   369,     6,
     271,   271,   359,     6,   149,   271,   341,   270,   271,   275,
     275,   275,   275,   275,     6,   271,     6,   330,     6,   270,
     359,   359,   271,   275,   311,   381,   267,   359,   359,   271,
     271,   376,     6,   369,     6,   369,     6,     6,   271,   359,
     344,   330,     6,   376,   376,   376,   376,   369,   376,   347,
     285,   267,   275,     6,   270,   359,   271,   275,   275,   271,
     275,   275,     6,   271,   271,   342,   271,   271,   271,   271,
     275,   271,   271,   271,   291,   359,   371,   271,   359,   359,
     369,   369,   344,     6,     6,     6,     6,   376,     6,     6,
       6,   270,   267,   271,     6,   271,   301,   275,   275,   271,
     271,   289,   380,   294,   270,     6,   359,   359,     6,   271,
     275,   270,   371,   271,   271,     6,   380,   292,   380,   271,
       6,     6,   271,   275,     6,     6,   380
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
      GModel::current()->createMEdges();
    ;}
    break;

  case 300:
#line 3735 "Gmsh.y"
    {
      GModel::current()->createMFaces();
    ;}
    break;

  case 301:
#line 3739 "Gmsh.y"
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

  case 302:
#line 3751 "Gmsh.y"
    {
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      if(GModel::current()->getGEOInternals()->getChanged())
        GModel::current()->getGEOInternals()->synchronize(GModel::current());
      GModel::current()->recombineMesh();
    ;}
    break;

  case 303:
#line 3761 "Gmsh.y"
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

  case 304:
#line 3819 "Gmsh.y"
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

  case 305:
#line 3839 "Gmsh.y"
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

  case 306:
#line 3865 "Gmsh.y"
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

  case 307:
#line 3881 "Gmsh.y"
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

  case 308:
#line 3898 "Gmsh.y"
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

  case 309:
#line 3915 "Gmsh.y"
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

  case 310:
#line 3937 "Gmsh.y"
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

  case 311:
#line 3959 "Gmsh.y"
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

  case 312:
#line 3994 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip(nullptr, "Return");
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 313:
#line 4002 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip(nullptr, "Return");
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 314:
#line 4010 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    ;}
    break;

  case 315:
#line 4016 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function '%s'", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 316:
#line 4023 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function '%s'", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 317:
#line 4030 "Gmsh.y"
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

  case 318:
#line 4050 "Gmsh.y"
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

  case 319:
#line 4076 "Gmsh.y"
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

  case 320:
#line 4088 "Gmsh.y"
    {
      ImbricatedTest--;
      if(ImbricatedTest < 0)
        yymsg(1, "Orphan EndIf");
    ;}
    break;

  case 321:
#line 4099 "Gmsh.y"
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

  case 322:
#line 4117 "Gmsh.y"
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

  case 323:
#line 4135 "Gmsh.y"
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

  case 324:
#line 4153 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 325:
#line 4159 "Gmsh.y"
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

  case 326:
#line 4177 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 327:
#line 4183 "Gmsh.y"
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

  case 328:
#line 4203 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 329:
#line 4209 "Gmsh.y"
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

  case 330:
#line 4227 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 331:
#line 4233 "Gmsh.y"
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

  case 332:
#line 4250 "Gmsh.y"
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

  case 333:
#line 4266 "Gmsh.y"
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

  case 334:
#line 4283 "Gmsh.y"
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

  case 335:
#line 4301 "Gmsh.y"
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

  case 336:
#line 4324 "Gmsh.y"
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

  case 337:
#line 4351 "Gmsh.y"
    {
    ;}
    break;

  case 338:
#line 4354 "Gmsh.y"
    {
    ;}
    break;

  case 339:
#line 4360 "Gmsh.y"
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

  case 340:
#line 4372 "Gmsh.y"
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

  case 341:
#line 4392 "Gmsh.y"
    {
      extr.mesh.ScaleLast = true;
    ;}
    break;

  case 342:
#line 4396 "Gmsh.y"
    {
      extr.mesh.Recombine = true;
    ;}
    break;

  case 343:
#line 4400 "Gmsh.y"
    {
      extr.mesh.Recombine = (yyvsp[(2) - (3)].d) ? true : false;
    ;}
    break;

  case 344:
#line 4404 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1;
    ;}
    break;

  case 345:
#line 4408 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1_RECOMB;
    ;}
    break;

  case 346:
#line 4412 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1;
    ;}
    break;

  case 347:
#line 4416 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1_RECOMB;
    ;}
    break;

  case 348:
#line 4420 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(6) - (9)].l), tags);
      int num = (int)(yyvsp[(3) - (9)].d);
      GModel::current()->getGEOInternals()->addDiscreteSurface(num);
      extr.mesh.Holes[num].first = (yyvsp[(8) - (9)].d);
      extr.mesh.Holes[num].second = tags;
      List_Delete((yyvsp[(6) - (9)].l));
    ;}
    break;

  case 349:
#line 4429 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (6)].c), "Index"))
        extr.mesh.BoundaryLayerIndex = (yyvsp[(4) - (6)].d);
      else if(!strcmp((yyvsp[(2) - (6)].c), "View"))
        extr.mesh.ViewIndex = (yyvsp[(4) - (6)].d);
      Free((yyvsp[(2) - (6)].c));
    ;}
    break;

  case 350:
#line 4441 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Union; ;}
    break;

  case 351:
#line 4442 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Intersection; ;}
    break;

  case 352:
#line 4443 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Difference; ;}
    break;

  case 353:
#line 4444 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Section; ;}
    break;

  case 354:
#line 4445 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Fragments; ;}
    break;

  case 355:
#line 4449 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 356:
#line 4450 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 357:
#line 4451 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 358:
#line 4452 "Gmsh.y"
    { (yyval.i) = (yyvsp[(2) - (3)].d) ? 1 : 0; ;}
    break;

  case 359:
#line 4453 "Gmsh.y"
    { (yyval.i) = (yyvsp[(3) - (4)].d) ? 2 : 0; ;}
    break;

  case 360:
#line 4458 "Gmsh.y"
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

  case 361:
#line 4481 "Gmsh.y"
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

  case 362:
#line 4501 "Gmsh.y"
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

  case 363:
#line 4522 "Gmsh.y"
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    ;}
    break;

  case 364:
#line 4526 "Gmsh.y"
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

  case 365:
#line 4553 "Gmsh.y"
    {
      (yyval.i) = -1; // left
    ;}
    break;

  case 366:
#line 4557 "Gmsh.y"
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

  case 367:
#line 4573 "Gmsh.y"
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   ;}
    break;

  case 368:
#line 4577 "Gmsh.y"
    {
     (yyval.l) = (yyvsp[(2) - (2)].l);
   ;}
    break;

  case 369:
#line 4582 "Gmsh.y"
    {
      (yyval.i) = 45;
    ;}
    break;

  case 370:
#line 4586 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(2) - (2)].d);
    ;}
    break;

  case 371:
#line 4592 "Gmsh.y"
    {
      (yyval.l) = List_Create(1, 1, sizeof(double));
    ;}
    break;

  case 372:
#line 4596 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
    ;}
    break;

  case 373:
#line 4603 "Gmsh.y"
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

  case 374:
#line 4626 "Gmsh.y"
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

  case 375:
#line 4645 "Gmsh.y"
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

  case 376:
#line 4686 "Gmsh.y"
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

  case 377:
#line 4731 "Gmsh.y"
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

  case 378:
#line 4771 "Gmsh.y"
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

  case 379:
#line 4796 "Gmsh.y"
    {
      int dim = (int)(yyvsp[(2) - (8)].i);
      int tag = (int)(yyvsp[(4) - (8)].d);
      int new_tag = (int)(yyvsp[(6) - (8)].d);
      GModel::current()->changeEntityTag(dim, tag, new_tag);
    ;}
    break;

  case 380:
#line 4803 "Gmsh.y"
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

  case 381:
#line 4814 "Gmsh.y"
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

  case 382:
#line 4831 "Gmsh.y"
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

  case 383:
#line 4848 "Gmsh.y"
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

  case 384:
#line 4878 "Gmsh.y"
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

  case 385:
#line 4904 "Gmsh.y"
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

  case 386:
#line 4931 "Gmsh.y"
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

  case 387:
#line 4963 "Gmsh.y"
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

  case 388:
#line 4991 "Gmsh.y"
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

  case 389:
#line 5017 "Gmsh.y"
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

  case 390:
#line 5043 "Gmsh.y"
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

  case 391:
#line 5069 "Gmsh.y"
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

  case 392:
#line 5095 "Gmsh.y"
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

  case 393:
#line 5116 "Gmsh.y"
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

  case 394:
#line 5128 "Gmsh.y"
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

  case 395:
#line 5176 "Gmsh.y"
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

  case 396:
#line 5230 "Gmsh.y"
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

  case 397:
#line 5245 "Gmsh.y"
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

  case 398:
#line 5257 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (4)].l), tags);
      GModel::current()->getGEOInternals()->setCompoundMesh((yyvsp[(2) - (4)].i), tags);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 399:
#line 5263 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (6)].l), tags);
      tags.push_back(- (int) (yyvsp[(5) - (6)].d));
      GModel::current()->getGEOInternals()->setCompoundMesh((yyvsp[(2) - (6)].i), tags);
      List_Delete((yyvsp[(3) - (6)].l));
    ;}
    break;

  case 400:
#line 5275 "Gmsh.y"
    {
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals())
        GModel::current()->getOCCInternals()->removeAllDuplicates();
      else
        GModel::current()->getGEOInternals()->removeAllDuplicates();
    ;}
    break;

  case 401:
#line 5282 "Gmsh.y"
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

  case 402:
#line 5297 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(4) - (6)].l), tags);
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals())
        GModel::current()->getOCCInternals()->mergeVertices(tags);
      else
        GModel::current()->getGEOInternals()->mergeVertices(tags);
      List_Delete((yyvsp[(4) - (6)].l));
    ;}
    break;

  case 403:
#line 5306 "Gmsh.y"
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

  case 404:
#line 5326 "Gmsh.y"
    { (yyval.c) = (char*)"Homology"; ;}
    break;

  case 405:
#line 5327 "Gmsh.y"
    { (yyval.c) = (char*)"Cohomology"; ;}
    break;

  case 406:
#line 5328 "Gmsh.y"
    { (yyval.c) = (char*)"Betti"; ;}
    break;

  case 407:
#line 5333 "Gmsh.y"
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest((yyvsp[(1) - (2)].c), domain, subdomain, dim);
    ;}
    break;

  case 408:
#line 5339 "Gmsh.y"
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

  case 409:
#line 5351 "Gmsh.y"
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

  case 410:
#line 5369 "Gmsh.y"
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

  case 411:
#line 5396 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d);           ;}
    break;

  case 412:
#line 5397 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (3)].d);           ;}
    break;

  case 413:
#line 5398 "Gmsh.y"
    { (yyval.d) = -(yyvsp[(2) - (2)].d);          ;}
    break;

  case 414:
#line 5399 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);           ;}
    break;

  case 415:
#line 5400 "Gmsh.y"
    { (yyval.d) = !(yyvsp[(2) - (2)].d);          ;}
    break;

  case 416:
#line 5401 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) - (yyvsp[(3) - (3)].d);      ;}
    break;

  case 417:
#line 5402 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) + (yyvsp[(3) - (3)].d);      ;}
    break;

  case 418:
#line 5403 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) * (yyvsp[(3) - (3)].d);      ;}
    break;

  case 419:
#line 5405 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (3)].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));
      else
	(yyval.d) = (yyvsp[(1) - (3)].d) / (yyvsp[(3) - (3)].d);
    ;}
    break;

  case 420:
#line 5411 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) | (int)(yyvsp[(3) - (3)].d); ;}
    break;

  case 421:
#line 5412 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) & (int)(yyvsp[(3) - (3)].d); ;}
    break;

  case 422:
#line 5413 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) % (int)(yyvsp[(3) - (3)].d); ;}
    break;

  case 423:
#line 5414 "Gmsh.y"
    { (yyval.d) = pow((yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));  ;}
    break;

  case 424:
#line 5415 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d);      ;}
    break;

  case 425:
#line 5416 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) > (yyvsp[(3) - (3)].d);      ;}
    break;

  case 426:
#line 5417 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) <= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 427:
#line 5418 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) >= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 428:
#line 5419 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) == (yyvsp[(3) - (3)].d);     ;}
    break;

  case 429:
#line 5420 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) != (yyvsp[(3) - (3)].d);     ;}
    break;

  case 430:
#line 5421 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) && (yyvsp[(3) - (3)].d);     ;}
    break;

  case 431:
#line 5422 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) || (yyvsp[(3) - (3)].d);     ;}
    break;

  case 432:
#line 5423 "Gmsh.y"
    { (yyval.d) = ((int)(yyvsp[(1) - (3)].d) >> (int)(yyvsp[(3) - (3)].d)); ;}
    break;

  case 433:
#line 5424 "Gmsh.y"
    { (yyval.d) = ((int)(yyvsp[(1) - (3)].d) << (int)(yyvsp[(3) - (3)].d)); ;}
    break;

  case 434:
#line 5425 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (5)].d) ? (yyvsp[(3) - (5)].d) : (yyvsp[(5) - (5)].d); ;}
    break;

  case 435:
#line 5426 "Gmsh.y"
    { (yyval.d) = ((yyvsp[(3) - (4)].d) < 0) ? 0 : 1; ;}
    break;

  case 436:
#line 5427 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 437:
#line 5428 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 438:
#line 5429 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 439:
#line 5430 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 440:
#line 5431 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 441:
#line 5432 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 442:
#line 5433 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 443:
#line 5434 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 444:
#line 5435 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 445:
#line 5436 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 446:
#line 5437 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 447:
#line 5438 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 448:
#line 5439 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 449:
#line 5440 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 450:
#line 5441 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 451:
#line 5442 "Gmsh.y"
    { (yyval.d) = std::abs((yyvsp[(3) - (4)].d)); ;}
    break;

  case 452:
#line 5443 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 453:
#line 5444 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 454:
#line 5445 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d) + 0.5); ;}
    break;

  case 455:
#line 5446 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 456:
#line 5447 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 457:
#line 5448 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 458:
#line 5449 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 459:
#line 5450 "Gmsh.y"
    { (yyval.d) = std::max((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 460:
#line 5451 "Gmsh.y"
    { (yyval.d) = std::min((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 461:
#line 5460 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 462:
#line 5461 "Gmsh.y"
    { (yyval.d) = 3.141592653589793; ;}
    break;

  case 463:
#line 5462 "Gmsh.y"
    { (yyval.d) = (double)ImbricatedTest; ;}
    break;

  case 464:
#line 5463 "Gmsh.y"
    { (yyval.d) = Msg::GetCommRank(); ;}
    break;

  case 465:
#line 5464 "Gmsh.y"
    { (yyval.d) = Msg::GetCommSize(); ;}
    break;

  case 466:
#line 5465 "Gmsh.y"
    { (yyval.d) = GetGmshMajorVersion(); ;}
    break;

  case 467:
#line 5466 "Gmsh.y"
    { (yyval.d) = GetGmshMinorVersion(); ;}
    break;

  case 468:
#line 5467 "Gmsh.y"
    { (yyval.d) = GetGmshPatchVersion(); ;}
    break;

  case 469:
#line 5468 "Gmsh.y"
    { (yyval.d) = Cpu(); ;}
    break;

  case 470:
#line 5469 "Gmsh.y"
    { (yyval.d) = GetMemoryUsage()/1024./1024.; ;}
    break;

  case 471:
#line 5470 "Gmsh.y"
    { (yyval.d) = TotalRam(); ;}
    break;

  case 472:
#line 5475 "Gmsh.y"
    { init_options(); ;}
    break;

  case 473:
#line 5477 "Gmsh.y"
    {
      std::vector<double> val(1, (yyvsp[(3) - (6)].d));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.d) = val[0];
    ;}
    break;

  case 474:
#line 5483 "Gmsh.y"
    {
      (yyval.d) = (yyvsp[(1) - (1)].d);
    ;}
    break;

  case 475:
#line 5487 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 476:
#line 5492 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 477:
#line 5497 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(1) - (1)].c2).char1, (yyvsp[(1) - (1)].c2).char2);
    ;}
    break;

  case 478:
#line 5502 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float(nullptr, (yyvsp[(1) - (4)].c), 2, (int)(yyvsp[(3) - (4)].d));
    ;}
    break;

  case 479:
#line 5507 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float(nullptr, (yyvsp[(1) - (4)].c), 2, (int)(yyvsp[(3) - (4)].d));
    ;}
    break;

  case 480:
#line 5511 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(3) - (4)].c2).char1, (yyvsp[(3) - (4)].c2).char2, 1, 0, 0., 1);
    ;}
    break;

  case 481:
#line 5515 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(3) - (6)].c2).char1, (yyvsp[(3) - (6)].c2).char2, (yyvsp[(5) - (6)].c), 0, 0., 1);
    ;}
    break;

  case 482:
#line 5519 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(3) - (5)].c2).char1, (yyvsp[(3) - (5)].c2).char2, 1, 0, (yyvsp[(4) - (5)].d), 2);
    ;}
    break;

  case 483:
#line 5523 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(3) - (7)].c2).char1, (yyvsp[(3) - (7)].c2).char2, (yyvsp[(5) - (7)].c), 0, (yyvsp[(6) - (7)].d), 2);
    ;}
    break;

  case 484:
#line 5527 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(3) - (8)].c2).char1, (yyvsp[(3) - (8)].c2).char2, 2, (int)(yyvsp[(5) - (8)].d), (yyvsp[(7) - (8)].d), 2);
    ;}
    break;

  case 485:
#line 5531 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(3) - (10)].c2).char1, (yyvsp[(3) - (10)].c2).char2, (yyvsp[(5) - (10)].c), (int)(yyvsp[(7) - (10)].d), (yyvsp[(9) - (10)].d), 2);
    ;}
    break;

  case 486:
#line 5535 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.d) = !StatFile(tmp);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 487:
#line 5541 "Gmsh.y"
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

  case 488:
#line 5556 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float_getDim((yyvsp[(2) - (6)].c2).char1, (yyvsp[(2) - (6)].c2).char2, (yyvsp[(4) - (6)].c));
    ;}
    break;

  case 489:
#line 5560 "Gmsh.y"
    {
      std::string struct_namespace((yyvsp[(3) - (4)].c));
      (yyval.d) = (double)gmsh_yynamespaces[struct_namespace].size();
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 490:
#line 5566 "Gmsh.y"
    {
      std::string struct_namespace(std::string(""));
      (yyval.d) = (double)gmsh_yynamespaces[struct_namespace].size();
    ;}
    break;

  case 491:
#line 5571 "Gmsh.y"
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

  case 492:
#line 5590 "Gmsh.y"
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
#line 5610 "Gmsh.y"
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

  case 494:
#line 5631 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(nullptr, (yyvsp[(1) - (3)].c), (yyvsp[(3) - (3)].c));
    ;}
    break;

  case 495:
#line 5635 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c), (yyvsp[(5) - (5)].c));
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
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(nullptr, (yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].c), (int)(yyvsp[(5) - (6)].d));
    ;}
    break;

  case 499:
#line 5651 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(1) - (8)].c), (yyvsp[(3) - (8)].c), (yyvsp[(5) - (8)].c), (int)(yyvsp[(7) - (8)].d));
    ;}
    break;

  case 500:
#line 5655 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), (yyval.d));
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 501:
#line 5660 "Gmsh.y"
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

  case 502:
#line 5670 "Gmsh.y"
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

  case 503:
#line 5680 "Gmsh.y"
    {
      (yyval.d) = Msg::GetValue((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 504:
#line 5685 "Gmsh.y"
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

  case 505:
#line 5696 "Gmsh.y"
    {
      std::string s((yyvsp[(3) - (6)].c)), substr((yyvsp[(5) - (6)].c));
      if(s.find(substr) != std::string::npos)
        (yyval.d) = 1.;
      else
        (yyval.d) = 0.;
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 506:
#line 5705 "Gmsh.y"
    {
      (yyval.d) = strlen((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 507:
#line 5710 "Gmsh.y"
    {
      (yyval.d) = strcmp((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 508:
#line 5715 "Gmsh.y"
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

  case 509:
#line 5742 "Gmsh.y"
    { (yyval.d) = 0.; ;}
    break;

  case 510:
#line 5744 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);;}
    break;

  case 511:
#line 5749 "Gmsh.y"
    { (yyval.c) = nullptr; ;}
    break;

  case 512:
#line 5751 "Gmsh.y"
    { (yyval.c) = (yyvsp[(2) - (2)].c);;}
    break;

  case 513:
#line 5756 "Gmsh.y"
    {
      std::string struct_namespace((yyvsp[(2) - (3)].c2).char1? (yyvsp[(2) - (3)].c2).char1 : std::string("")),
        struct_name((yyvsp[(2) - (3)].c2).char2);
      init_options
        (gmsh_yynamespaces.getMember_ValMax(struct_namespace, struct_name));
    ;}
    break;

  case 514:
#line 5763 "Gmsh.y"
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

  case 515:
#line 5779 "Gmsh.y"
    { (yyval.c2).char1 = nullptr; (yyval.c2).char2 = (yyvsp[(1) - (1)].c); ;}
    break;

  case 516:
#line 5781 "Gmsh.y"
    { (yyval.c2).char1 = (yyvsp[(1) - (3)].c); (yyval.c2).char2 = (yyvsp[(3) - (3)].c); ;}
    break;

  case 517:
#line 5786 "Gmsh.y"
    { (yyval.i) = 99; ;}
    break;

  case 518:
#line 5788 "Gmsh.y"
    { (yyval.i) = (int)(yyvsp[(2) - (2)].d); ;}
    break;

  case 519:
#line 5793 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 520:
#line 5795 "Gmsh.y"
    { (yyval.i) = (yyvsp[(2) - (3)].i); ;}
    break;

  case 521:
#line 5800 "Gmsh.y"
    {
      memcpy((yyval.v), (yyvsp[(1) - (1)].v), 5 * sizeof(double));
    ;}
    break;

  case 522:
#line 5804 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 523:
#line 5808 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 524:
#line 5812 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] - (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 525:
#line 5816 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] + (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 526:
#line 5823 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (11)].d);  (yyval.v)[1] = (yyvsp[(4) - (11)].d);  (yyval.v)[2] = (yyvsp[(6) - (11)].d);  (yyval.v)[3] = (yyvsp[(8) - (11)].d); (yyval.v)[4] = (yyvsp[(10) - (11)].d);
    ;}
    break;

  case 527:
#line 5827 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (9)].d);  (yyval.v)[1] = (yyvsp[(4) - (9)].d);  (yyval.v)[2] = (yyvsp[(6) - (9)].d);  (yyval.v)[3] = (yyvsp[(8) - (9)].d); (yyval.v)[4] = 1.0;
    ;}
    break;

  case 528:
#line 5831 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 529:
#line 5835 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 530:
#line 5842 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].l)));
    ;}
    break;

  case 531:
#line 5847 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].l)));
    ;}
    break;

  case 532:
#line 5854 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 533:
#line 5859 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 534:
#line 5863 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
    ;}
    break;

  case 535:
#line 5867 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 536:
#line 5871 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 537:
#line 5879 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (5)].d);
      }
    ;}
    break;

  case 538:
#line 5890 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
    ;}
    break;

  case 539:
#line 5894 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 540:
#line 5898 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 541:
#line 5909 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 542:
#line 5913 "Gmsh.y"
    {
      (yyval.l) = 0;
    ;}
    break;

  case 543:
#line 5917 "Gmsh.y"
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

  case 544:
#line 5931 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 545:
#line 5939 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (3)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (3)].d);
      }
    ;}
    break;

  case 546:
#line 5947 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      for(double d = (yyvsp[(1) - (3)].d); ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d <= (yyvsp[(3) - (3)].d)) : (d >= (yyvsp[(3) - (3)].d));
          ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d += 1.) : (d -= 1.))
	List_Add((yyval.l), &d);
    ;}
    break;

  case 547:
#line 5954 "Gmsh.y"
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

  case 548:
#line 5964 "Gmsh.y"
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

  case 549:
#line 5987 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags(0, (yyval.l));
    ;}
    break;

  case 550:
#line 5992 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags(0, (yyval.l));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 551:
#line 5998 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags((yyvsp[(1) - (4)].i), (yyval.l));
    ;}
    break;

  case 552:
#line 6003 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags((yyvsp[(1) - (2)].i), (yyval.l));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 553:
#line 6009 "Gmsh.y"
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

  case 554:
#line 6020 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getParentTags((yyvsp[(2) - (3)].i), (yyvsp[(3) - (3)].l), (yyval.l));
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 555:
#line 6026 "Gmsh.y"
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
#line 6040 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getBoundingBox((yyvsp[(2) - (5)].i), (yyvsp[(4) - (5)].l), (yyval.l));
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 557:
#line 6046 "Gmsh.y"
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
#line 6058 "Gmsh.y"
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
#line 6072 "Gmsh.y"
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
#line 6085 "Gmsh.y"
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

  case 561:
#line 6115 "Gmsh.y"
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

  case 562:
#line 6138 "Gmsh.y"
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

  case 563:
#line 6158 "Gmsh.y"
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

  case 564:
#line 6177 "Gmsh.y"
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

  case 565:
#line 6197 "Gmsh.y"
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
#line 6214 "Gmsh.y"
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
#line 6224 "Gmsh.y"
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
#line 6234 "Gmsh.y"
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
#line 6244 "Gmsh.y"
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
#line 6256 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfFloat(nullptr, (yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c));
    ;}
    break;

  case 571:
#line 6260 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfFloat((yyvsp[(1) - (7)].c), (yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].c));
    ;}
    break;

  case 572:
#line 6265 "Gmsh.y"
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
#line 6277 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 574:
#line 6281 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 575:
#line 6285 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (6)].l);
    ;}
    break;

  case 576:
#line 6289 "Gmsh.y"
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
#line 6307 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = (yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1);
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 578:
#line 6315 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = pow(10,(yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1));
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 579:
#line 6323 "Gmsh.y"
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
#line 6352 "Gmsh.y"
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
#line 6362 "Gmsh.y"
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
#line 6378 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
        double *d = (double*)List_Pointer((yyvsp[(3) - (4)].l), i);
        *d = std::abs(*d);
      }
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 583:
#line 6389 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 584:
#line 6394 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 585:
#line 6398 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].d)));
    ;}
    break;

  case 586:
#line 6402 "Gmsh.y"
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
#line 6414 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (9)].d), (int)(yyvsp[(4) - (9)].d), (int)(yyvsp[(6) - (9)].d), (int)(yyvsp[(8) - (9)].d));
    ;}
    break;

  case 588:
#line 6418 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (7)].d), (int)(yyvsp[(4) - (7)].d), (int)(yyvsp[(6) - (7)].d), 255);
    ;}
    break;

  case 589:
#line 6430 "Gmsh.y"
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

  case 590:
#line 6447 "Gmsh.y"
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(5) - (5)].c), val);
      (yyval.u) = val;
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(5) - (5)].c));
    ;}
    break;

  case 591:
#line 6457 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 592:
#line 6461 "Gmsh.y"
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

  case 593:
#line 6476 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].u)));
    ;}
    break;

  case 594:
#line 6481 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].u)));
    ;}
    break;

  case 595:
#line 6488 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 596:
#line 6492 "Gmsh.y"
    {
      // No need to extend to Struct_FullName (a Tag is not a String)
      (yyval.c) = treat_Struct_FullName_String(nullptr, (yyvsp[(1) - (1)].c));
    ;}
    break;

  case 597:
#line 6497 "Gmsh.y"
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

  case 598:
#line 6511 "Gmsh.y"
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

  case 599:
#line 6525 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String(nullptr, (yyvsp[(1) - (3)].c), (yyvsp[(3) - (3)].c));
    ;}
    break;

  case 600:
#line 6529 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c), (yyvsp[(5) - (5)].c));
    ;}
    break;

  case 601:
#line 6533 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String(nullptr, (yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].c), (int)(yyvsp[(5) - (6)].d));
    ;}
    break;

  case 602:
#line 6537 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(1) - (8)].c), (yyvsp[(3) - (8)].c), (yyvsp[(5) - (8)].c), (int)(yyvsp[(7) - (8)].d));
    ;}
    break;

  case 603:
#line 6541 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 604:
#line 6549 "Gmsh.y"
    {
      std::string name = GModel::current()->getElementaryName((yyvsp[(1) - (4)].i), (int)(yyvsp[(3) - (4)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 605:
#line 6555 "Gmsh.y"
    {
      std::string name = GModel::current()->getPhysicalName((yyvsp[(2) - (5)].i), (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 606:
#line 6564 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 607:
#line 6568 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 608:
#line 6572 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    ;}
    break;

  case 609:
#line 6580 "Gmsh.y"
    {
      std::string exe = Msg::GetExecutableName();
      (yyval.c) = (char *)Malloc(exe.size() + 1);
      strcpy((yyval.c), exe.c_str());
    ;}
    break;

  case 610:
#line 6586 "Gmsh.y"
    {
      std::string action = Msg::GetOnelabAction();
      (yyval.c) = (char *)Malloc(action.size() + 1);
      strcpy((yyval.c), action.c_str());
    ;}
    break;

  case 611:
#line 6592 "Gmsh.y"
    {
      (yyval.c) = strsave((char*)"Gmsh");
    ;}
    break;

  case 612:
#line 6596 "Gmsh.y"
    {
      std::string env = GetEnvironmentVar((yyvsp[(3) - (4)].c));
      (yyval.c) = (char *)Malloc((env.size() + 1) * sizeof(char));
      strcpy((yyval.c), env.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 613:
#line 6603 "Gmsh.y"
    {
      std::string s = Msg::GetString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 614:
#line 6611 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (4)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 615:
#line 6618 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 616:
#line 6627 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_String(nullptr, (yyvsp[(3) - (5)].c2).char2, 1, 0, (yyvsp[(4) - (5)].c), 2);
    ;}
    break;

  case 617:
#line 6631 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(3) - (7)].c2).char1, (yyvsp[(3) - (7)].c2).char2, (yyvsp[(5) - (7)].c), 0, (yyvsp[(6) - (7)].c), 2);
    ;}
    break;

  case 618:
#line 6635 "Gmsh.y"
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

  case 619:
#line 6650 "Gmsh.y"
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

  case 620:
#line 6664 "Gmsh.y"
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

  case 621:
#line 6678 "Gmsh.y"
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

  case 622:
#line 6690 "Gmsh.y"
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

  case 623:
#line 6706 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = toupper((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 624:
#line 6715 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = tolower((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 625:
#line 6724 "Gmsh.y"
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

  case 626:
#line 6734 "Gmsh.y"
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

  case 627:
#line 6745 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (8)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (8)].d), (int)(yyvsp[(7) - (8)].d));
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (8)].c));
    ;}
    break;

  case 628:
#line 6753 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (6)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (6)].d), std::string::npos);
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 629:
#line 6761 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 630:
#line 6765 "Gmsh.y"
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

  case 631:
#line 6783 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 632:
#line 6790 "Gmsh.y"
    {
      std::string tmp = SplitFileName(GetAbsolutePath(gmsh_yyname))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
    ;}
    break;

  case 633:
#line 6796 "Gmsh.y"
    {
      std::string tmp = GetFileNameWithoutPath(gmsh_yyname);
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
    ;}
    break;

  case 634:
#line 6802 "Gmsh.y"
    {
      std::string tmp = SplitFileName((yyvsp[(3) - (4)].c))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 635:
#line 6809 "Gmsh.y"
    {
      std::string tmp = GetAbsolutePath((yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 636:
#line 6816 "Gmsh.y"
    { init_options(); ;}
    break;

  case 637:
#line 6818 "Gmsh.y"
    {
      std::string val((yyvsp[(3) - (6)].c));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.c) = (char*)Malloc((val.size() + 1) * sizeof(char));
      strcpy((yyval.c), val.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 638:
#line 6826 "Gmsh.y"
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

  case 639:
#line 6850 "Gmsh.y"
    { struct_namespace = std::string(""); (yyval.d) = (yyvsp[(2) - (2)].d); ;}
    break;

  case 640:
#line 6852 "Gmsh.y"
    { struct_namespace = (yyvsp[(1) - (4)].c); Free((yyvsp[(1) - (4)].c)); (yyval.d) = (yyvsp[(4) - (4)].d); ;}
    break;

  case 641:
#line 6858 "Gmsh.y"
    { (yyval.l) = (yyvsp[(3) - (4)].l); ;}
    break;

  case 642:
#line 6863 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 643:
#line 6865 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 644:
#line 6870 "Gmsh.y"
    { (yyval.l) = (yyvsp[(2) - (3)].l); ;}
    break;

  case 645:
#line 6875 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].c)));
    ;}
    break;

  case 646:
#line 6880 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 647:
#line 6882 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].c)));
    ;}
    break;

  case 648:
#line 6886 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	char* c;
	List_Read((yyvsp[(3) - (3)].l), i, &c);
	List_Add((yyval.l), &c);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 649:
#line 6898 "Gmsh.y"
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

  case 650:
#line 6912 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfString(nullptr, (yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c));
    ;}
    break;

  case 651:
#line 6916 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfString((yyvsp[(1) - (7)].c), (yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].c));
    ;}
    break;

  case 652:
#line 6923 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr) + 1) * sizeof(char));
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 653:
#line 6931 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr) + 1) * sizeof(char)) ;
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)) ; strcat((yyval.c), tmpstr) ;
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 654:
#line 6939 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(7) - (8)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(3) - (8)].c))+strlen(tmpstr) + 1) * sizeof(char));
      strcpy((yyval.c), (yyvsp[(3) - (8)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(3) - (8)].c));
    ;}
    break;

  case 655:
#line 6950 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 656:
#line 6952 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 657:
#line 6955 "Gmsh.y"
    { (yyval.c) = (yyvsp[(3) - (4)].c); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 15525 "Gmsh.tab.cpp"
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


#line 6958 "Gmsh.y"


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

