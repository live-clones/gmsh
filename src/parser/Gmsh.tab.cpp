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
#line 168 "Gmsh.y"
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
#line 786 "Gmsh.tab.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 799 "Gmsh.tab.cpp"

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
#define YYLAST   17504

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  275
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  114
/* YYNRULES -- Number of rules.  */
#define YYNRULES  643
/* YYNRULES -- Number of states.  */
#define YYNSTATES  2243

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
    1250,  1257,  1265,  1270,  1276,  1282,  1289,  1296,  1300,  1305,
    1309,  1315,  1322,  1328,  1333,  1337,  1342,  1346,  1351,  1357,
    1362,  1368,  1372,  1378,  1386,  1394,  1398,  1401,  1409,  1413,
    1416,  1420,  1423,  1426,  1429,  1432,  1448,  1451,  1454,  1462,
    1465,  1475,  1487,  1490,  1495,  1498,  1501,  1504,  1507,  1510,
    1513,  1519,  1528,  1540,  1547,  1556,  1565,  1576,  1578,  1581,
    1584,  1586,  1590,  1594,  1599,  1604,  1606,  1608,  1614,  1626,
    1640,  1641,  1649,  1650,  1664,  1665,  1681,  1682,  1689,  1699,
    1702,  1706,  1717,  1731,  1733,  1736,  1742,  1750,  1753,  1756,
    1760,  1763,  1767,  1770,  1774,  1784,  1791,  1793,  1795,  1797,
    1799,  1801,  1802,  1805,  1809,  1813,  1818,  1828,  1833,  1848,
    1849,  1853,  1854,  1856,  1857,  1860,  1861,  1864,  1865,  1868,
    1874,  1881,  1889,  1896,  1902,  1906,  1915,  1922,  1931,  1940,
    1946,  1951,  1958,  1970,  1982,  2001,  2020,  2033,  2046,  2059,
    2070,  2075,  2080,  2085,  2090,  2095,  2102,  2105,  2109,  2116,
    2119,  2121,  2123,  2125,  2128,  2134,  2142,  2153,  2155,  2159,
    2162,  2165,  2168,  2172,  2176,  2180,  2184,  2188,  2192,  2196,
    2200,  2204,  2208,  2212,  2216,  2220,  2224,  2228,  2232,  2236,
    2240,  2246,  2251,  2256,  2261,  2266,  2271,  2276,  2281,  2286,
    2291,  2296,  2301,  2308,  2313,  2318,  2323,  2328,  2333,  2338,
    2343,  2348,  2355,  2362,  2369,  2374,  2381,  2388,  2390,  2392,
    2394,  2396,  2398,  2400,  2402,  2404,  2406,  2408,  2410,  2411,
    2418,  2420,  2425,  2432,  2434,  2439,  2444,  2449,  2456,  2462,
    2470,  2479,  2490,  2495,  2500,  2507,  2512,  2516,  2519,  2525,
    2531,  2535,  2541,  2548,  2557,  2564,  2573,  2580,  2585,  2593,
    2600,  2607,  2614,  2619,  2626,  2631,  2632,  2635,  2636,  2639,
    2640,  2648,  2650,  2654,  2656,  2659,  2660,  2664,  2666,  2669,
    2672,  2676,  2680,  2692,  2702,  2710,  2718,  2720,  2724,  2726,
    2728,  2731,  2735,  2740,  2746,  2749,  2753,  2758,  2760,  2764,
    2766,  2769,  2773,  2777,  2783,  2788,  2793,  2796,  2801,  2804,
    2808,  2812,  2817,  2823,  2829,  2835,  2841,  2848,  2860,  2872,
    2882,  2893,  2899,  2901,  2903,  2905,  2909,  2915,  2923,  2928,
    2933,  2938,  2945,  2952,  2961,  2970,  2975,  2990,  2995,  3000,
    3002,  3004,  3008,  3012,  3022,  3030,  3032,  3038,  3042,  3049,
    3051,  3055,  3057,  3059,  3064,  3069,  3073,  3079,  3086,  3095,
    3102,  3107,  3113,  3115,  3120,  3122,  3124,  3126,  3128,  3133,
    3140,  3145,  3152,  3158,  3166,  3171,  3176,  3181,  3190,  3195,
    3200,  3205,  3210,  3219,  3228,  3235,  3240,  3247,  3252,  3254,
    3256,  3261,  3266,  3267,  3274,  3279,  3282,  3287,  3292,  3294,
    3296,  3300,  3302,  3304,  3308,  3312,  3316,  3322,  3330,  3336,
    3342,  3351,  3353,  3355
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     276,     0,    -1,   277,    -1,     1,     6,    -1,    -1,   277,
     278,    -1,   280,    -1,   281,    -1,   302,    -1,   137,   265,
     378,   266,     6,    -1,   321,    -1,   327,    -1,   330,    -1,
     331,    -1,   332,    -1,   333,    -1,   337,    -1,   346,    -1,
     347,    -1,   353,    -1,   354,    -1,   336,    -1,   335,    -1,
     334,    -1,   356,    -1,   248,    -1,   249,    -1,    47,   265,
     378,   266,     6,    -1,    49,   265,   378,   266,     6,    -1,
      48,   265,   378,   266,     6,    -1,    47,   265,   378,   266,
     279,   378,     6,    -1,    47,   265,   378,   274,   374,   266,
       6,    -1,    49,   265,   378,   274,   374,   266,     6,    -1,
      48,   265,   378,   274,   374,   266,     6,    -1,    47,   265,
     378,   274,   374,   266,   279,   378,     6,    -1,   388,   378,
     269,   282,   270,     6,    -1,   181,     4,   267,   357,   268,
       6,    -1,   182,     4,   267,   357,   268,     6,    -1,   183,
       4,   267,   357,   274,   357,   268,     6,    -1,    -1,   282,
     285,    -1,   282,   289,    -1,   282,   292,    -1,   282,   294,
      -1,   282,   295,    -1,   282,   336,    -1,   357,    -1,   283,
     274,   357,    -1,   357,    -1,   284,   274,   357,    -1,    -1,
      -1,     4,   286,   265,   283,   266,   287,   269,   284,   270,
       6,    -1,   378,    -1,   288,   274,   378,    -1,    -1,   188,
     265,   357,   274,   357,   274,   357,   266,   290,   269,   288,
     270,     6,    -1,   378,    -1,   291,   274,   378,    -1,    -1,
     189,   265,   357,   274,   357,   274,   357,   274,   357,   266,
     293,   269,   291,   270,     6,    -1,   190,   269,   369,   270,
     269,   369,   270,     6,    -1,   190,   269,   369,   270,   269,
     369,   270,   269,   369,   270,   269,   369,   270,     6,    -1,
      -1,   191,   296,   269,   284,   270,     6,    -1,     7,    -1,
     241,    -1,   240,    -1,   239,    -1,   238,    -1,   263,    -1,
     262,    -1,   265,    -1,   267,    -1,   266,    -1,   268,    -1,
       4,    -1,    37,    -1,    38,    -1,    26,    -1,   114,    -1,
     115,    -1,    94,   267,   304,   268,     6,    -1,    95,   267,
     308,   268,     6,    -1,   362,     6,    -1,   102,   299,   379,
     274,   357,   300,     6,    -1,   104,   299,   379,   274,   379,
     300,     6,    -1,   388,   297,   370,     6,    -1,   388,   298,
       6,    -1,   388,   299,   300,   297,   370,     6,    -1,   388,
     299,   269,   374,   270,   300,   297,   370,     6,    -1,   388,
     267,   357,   268,   297,   357,     6,    -1,   388,   267,   357,
     268,   298,     6,    -1,   388,   265,   357,   266,   297,   357,
       6,    -1,   388,   265,   357,   266,   298,     6,    -1,   388,
       7,   379,     6,    -1,   388,   299,   300,     7,    50,   299,
     300,     6,    -1,   388,   299,   300,     7,    50,   299,   383,
     300,     6,    -1,   388,   299,   300,   241,    50,   299,   383,
     300,     6,    -1,   388,   271,   301,     7,   379,     6,    -1,
     388,   267,   357,   268,   271,   301,     7,   379,     6,    -1,
     388,   271,   301,   297,   357,     6,    -1,   388,   267,   357,
     268,   271,   301,   297,   357,     6,    -1,   388,   271,   301,
     298,     6,    -1,   388,   267,   357,   268,   271,   301,   298,
       6,    -1,   388,   271,   198,   271,   301,     7,   375,     6,
      -1,   388,   267,   357,   268,   271,   198,   271,   301,     7,
     375,     6,    -1,   388,   271,   199,     7,   376,     6,    -1,
     388,   267,   357,   268,   271,   199,     7,   376,     6,    -1,
     388,   209,     7,   370,     6,    -1,   209,   267,   357,   268,
       7,   301,     6,    -1,   209,   267,   357,   268,   271,   301,
       7,   357,     6,    -1,   209,   267,   357,   268,   271,   301,
       7,   379,     6,    -1,   209,   267,   357,   268,   271,   301,
       7,   371,     6,    -1,   209,   267,   357,   268,   271,   301,
       6,    -1,   150,   265,     4,   266,   271,   301,     7,   357,
       6,    -1,   150,   265,     4,   266,   271,   301,     7,   379,
       6,    -1,    -1,   274,    -1,    -1,   304,   303,   388,    -1,
     304,   303,   388,     7,   357,    -1,    -1,   304,   303,   388,
       7,   269,   370,   305,   310,   270,    -1,    -1,   304,   303,
     388,   299,   300,     7,   269,   370,   306,   310,   270,    -1,
     304,   303,   388,     7,   379,    -1,    -1,   304,   303,   388,
       7,   269,   379,   307,   314,   270,    -1,    -1,   308,   303,
     378,    -1,   357,     7,   379,    -1,   309,   274,   357,     7,
     379,    -1,   373,     7,   388,   265,   266,    -1,    -1,   274,
     312,    -1,    -1,   312,    -1,   313,    -1,   312,   274,   313,
      -1,     4,   370,    -1,    37,   357,    -1,    38,   357,    -1,
      26,   357,    -1,     4,    -1,     4,   269,   309,   270,    -1,
       4,   379,    -1,     4,   382,    -1,    -1,   274,   315,    -1,
     316,    -1,   315,   274,   316,    -1,     4,   357,    -1,     4,
     379,    -1,   213,   379,    -1,     4,   384,    -1,     4,   382,
      -1,   357,    -1,   379,    -1,   379,   274,   357,    -1,    -1,
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
       6,    -1,   329,   148,   323,   269,   374,   270,     6,    -1,
     329,   323,   269,     8,   270,     6,    -1,   329,   145,   323,
     269,     8,   270,     6,    -1,   170,   269,   329,   270,    -1,
     152,   170,   269,   329,   270,    -1,   170,     4,   269,   329,
     270,    -1,   170,   209,   267,   357,   268,     6,    -1,   170,
       4,   267,   357,   268,     6,    -1,   170,   388,     6,    -1,
     170,     4,     4,     6,    -1,   170,    97,     6,    -1,   198,
     375,   269,   329,   270,    -1,   152,   198,   375,   269,   329,
     270,    -1,   234,   357,   269,   329,   270,    -1,   214,   269,
       8,   270,    -1,   214,     5,     6,    -1,   215,   269,     8,
     270,    -1,   215,     5,     6,    -1,   214,   269,   329,   270,
      -1,   152,   214,   269,   329,   270,    -1,   215,   269,   329,
     270,    -1,   152,   215,   269,   329,   270,    -1,   388,   379,
       6,    -1,    81,   265,   385,   266,     6,    -1,   388,   388,
     267,   357,   268,   378,     6,    -1,   388,   388,   388,   267,
     357,   268,     6,    -1,   388,   357,     6,    -1,   237,     6,
      -1,   150,   265,     4,   266,   271,     4,     6,    -1,   192,
       4,     6,    -1,   207,     6,    -1,   207,   357,     6,    -1,
     208,     6,    -1,    75,     6,    -1,    76,     6,    -1,    68,
       6,    -1,    68,   269,   357,   274,   357,   274,   357,   274,
     357,   274,   357,   274,   357,   270,     6,    -1,    69,     6,
      -1,    70,     6,    -1,    86,   269,   357,   274,   357,   270,
       6,    -1,    86,     6,    -1,    88,   269,   357,   274,   357,
     274,   357,   270,     6,    -1,    88,   269,   357,   274,   357,
     274,   357,   274,   357,   270,     6,    -1,    87,     6,    -1,
      87,   269,   329,   270,    -1,    89,     6,    -1,    90,     6,
      -1,    91,     6,    -1,    92,     6,    -1,   131,     6,    -1,
     132,     6,    -1,   134,   269,   374,   270,     6,    -1,   134,
     269,   374,   270,   269,   328,   270,     6,    -1,   212,   265,
     269,   374,   270,   274,   379,   274,   379,   266,     6,    -1,
     200,   265,   357,     8,   357,   266,    -1,   200,   265,   357,
       8,   357,     8,   357,   266,    -1,   200,     4,   201,   269,
     357,     8,   357,   270,    -1,   200,     4,   201,   269,   357,
       8,   357,     8,   357,   270,    -1,   202,    -1,   213,     4,
      -1,   213,   379,    -1,   210,    -1,   211,   388,     6,    -1,
     211,   379,     6,    -1,   203,   265,   357,   266,    -1,   204,
     265,   357,   266,    -1,   205,    -1,   206,    -1,   158,   367,
     269,   329,   270,    -1,   158,   269,   367,   274,   367,   274,
     357,   270,   269,   329,   270,    -1,   158,   269,   367,   274,
     367,   274,   367,   274,   357,   270,   269,   329,   270,    -1,
      -1,   158,   367,   269,   329,   338,   342,   270,    -1,    -1,
     158,   269,   367,   274,   367,   274,   357,   270,   269,   329,
     339,   342,   270,    -1,    -1,   158,   269,   367,   274,   367,
     274,   367,   274,   357,   270,   269,   329,   340,   342,   270,
      -1,    -1,   158,   269,   329,   341,   342,   270,    -1,   158,
     269,   329,   270,   149,   123,   269,   357,   270,    -1,   138,
     370,    -1,   143,   138,   370,    -1,   140,   269,   374,   270,
     269,   374,   270,   269,   374,   270,    -1,   141,   269,   374,
     270,   269,   374,   270,   269,   374,   270,   269,   374,   270,
      -1,   343,    -1,   342,   343,    -1,   178,   269,   357,   270,
       6,    -1,   178,   269,   370,   274,   370,   270,     6,    -1,
     179,     6,    -1,   167,     6,    -1,   167,   357,     6,    -1,
     184,     6,    -1,   184,   186,     6,    -1,   185,     6,    -1,
     185,   186,     6,    -1,   180,   265,   357,   266,     7,   370,
     149,   357,     6,    -1,   149,     4,   267,   357,   268,     6,
      -1,   161,    -1,   162,    -1,   163,    -1,   164,    -1,   165,
      -1,    -1,   170,     6,    -1,   152,   170,     6,    -1,   170,
     357,     6,    -1,   152,   170,   357,     6,    -1,   344,   269,
     329,   345,   270,   269,   329,   345,   270,    -1,   120,   265,
     378,   266,    -1,   344,   265,   357,   266,     7,   269,   329,
     345,   270,   269,   329,   345,   270,     6,    -1,    -1,   149,
       4,   357,    -1,    -1,     4,    -1,    -1,     7,   370,    -1,
      -1,     7,   357,    -1,    -1,   159,   370,    -1,   176,   372,
       7,   357,     6,    -1,   127,   128,   372,     7,   357,     6,
      -1,   144,   108,   372,     7,   357,   348,     6,    -1,   144,
     111,   372,   350,   349,     6,    -1,   144,   113,   372,   350,
       6,    -1,   187,   372,     6,    -1,   103,   323,   265,   357,
     274,   357,   266,     6,    -1,   222,   323,   265,   357,   266,
       6,    -1,   174,   111,   269,   374,   270,     7,   357,     6,
      -1,   177,   111,   269,   374,   270,     7,   357,     6,    -1,
     167,   111,   372,   351,     6,    -1,   167,   113,   372,     6,
      -1,   168,   111,   372,     7,   357,     6,    -1,   147,   108,
     269,   374,   270,     7,   269,   374,   270,   352,     6,    -1,
     147,   111,   269,   374,   270,     7,   269,   374,   270,   352,
       6,    -1,   147,   108,   269,   374,   270,     7,   269,   374,
     270,   154,   269,   367,   274,   367,   274,   357,   270,     6,
      -1,   147,   111,   269,   374,   270,     7,   269,   374,   270,
     154,   269,   367,   274,   367,   274,   357,   270,     6,    -1,
     147,   108,   269,   374,   270,     7,   269,   374,   270,   155,
     367,     6,    -1,   147,   111,   269,   374,   270,     7,   269,
     374,   270,   155,   367,     6,    -1,   147,   111,   357,   269,
     374,   270,     7,   357,   269,   374,   270,     6,    -1,   323,
     269,   374,   270,   201,   323,   269,   357,   270,     6,    -1,
     175,   325,   372,     6,    -1,   135,   326,   372,     6,    -1,
     136,   113,   370,     6,    -1,   151,   108,   370,     6,    -1,
     146,   324,   370,     6,    -1,   146,   324,   370,   174,   357,
       6,    -1,   171,     6,    -1,   171,     4,     6,    -1,   171,
     105,   269,   374,   270,     6,    -1,   172,     6,    -1,   223,
      -1,   224,    -1,   225,    -1,   355,     6,    -1,   355,   269,
     370,   270,     6,    -1,   355,   269,   370,   274,   370,   270,
       6,    -1,   355,   265,   370,   266,   269,   370,   274,   370,
     270,     6,    -1,   358,    -1,   265,   357,   266,    -1,   254,
     357,    -1,   253,   357,    -1,   260,   357,    -1,   357,   254,
     357,    -1,   357,   253,   357,    -1,   357,   255,   357,    -1,
     357,   256,   357,    -1,   357,   258,   357,    -1,   357,   259,
     357,    -1,   357,   257,   357,    -1,   357,   264,   357,    -1,
     357,   247,   357,    -1,   357,   248,   357,    -1,   357,   252,
     357,    -1,   357,   251,   357,    -1,   357,   246,   357,    -1,
     357,   245,   357,    -1,   357,   244,   357,    -1,   357,   243,
     357,    -1,   357,   249,   357,    -1,   357,   250,   357,    -1,
     357,   242,   357,     8,   357,    -1,    26,   299,   357,   300,
      -1,    16,   299,   357,   300,    -1,    17,   299,   357,   300,
      -1,    18,   299,   357,   300,    -1,    19,   299,   357,   300,
      -1,    20,   299,   357,   300,    -1,    21,   299,   357,   300,
      -1,    22,   299,   357,   300,    -1,    23,   299,   357,   300,
      -1,    24,   299,   357,   300,    -1,    27,   299,   357,   300,
      -1,    28,   299,   357,   274,   357,   300,    -1,    29,   299,
     357,   300,    -1,    30,   299,   357,   300,    -1,    31,   299,
     357,   300,    -1,    32,   299,   357,   300,    -1,    33,   299,
     357,   300,    -1,    34,   299,   357,   300,    -1,    35,   299,
     357,   300,    -1,    36,   299,   357,   300,    -1,    39,   299,
     357,   274,   357,   300,    -1,    40,   299,   357,   274,   357,
     300,    -1,    41,   299,   357,   274,   357,   300,    -1,    25,
     299,   357,   300,    -1,    38,   299,   357,   274,   357,   300,
      -1,    37,   299,   357,   274,   357,   300,    -1,     3,    -1,
      10,    -1,    15,    -1,    11,    -1,    12,    -1,   230,    -1,
     231,    -1,   232,    -1,    83,    -1,    84,    -1,    85,    -1,
      -1,    96,   299,   357,   359,   310,   300,    -1,   362,    -1,
     220,   299,   378,   300,    -1,   220,   299,   378,   274,   357,
     300,    -1,   364,    -1,   388,   267,   357,   268,    -1,   388,
     265,   357,   266,    -1,   226,   265,   364,   266,    -1,   226,
     265,   364,   271,   301,   266,    -1,   228,   265,   364,   360,
     266,    -1,   228,   265,   364,   271,   301,   360,   266,    -1,
     228,   265,   364,   299,   357,   300,   360,   266,    -1,   228,
     265,   364,   271,   301,   299,   357,   300,   360,   266,    -1,
     227,   265,   379,   266,    -1,   272,   388,   299,   300,    -1,
     272,   364,   271,   301,   299,   300,    -1,    99,   299,   388,
     300,    -1,    99,   299,   300,    -1,   388,   298,    -1,   388,
     267,   357,   268,   298,    -1,   388,   265,   357,   266,   298,
      -1,   388,   271,   301,    -1,   388,     9,   388,   271,   301,
      -1,   388,   271,   301,   265,   357,   266,    -1,   388,     9,
     388,   271,   301,   265,   357,   266,    -1,   388,   271,   301,
     267,   357,   268,    -1,   388,     9,   388,   271,   301,   267,
     357,   268,    -1,   388,   267,   357,   268,   271,   301,    -1,
     388,   271,   301,   298,    -1,   388,   267,   357,   268,   271,
     301,   298,    -1,   216,   265,   378,   274,   357,   266,    -1,
      60,   265,   370,   274,   370,   266,    -1,    61,   299,   378,
     274,   378,   300,    -1,    59,   299,   378,   300,    -1,    62,
     299,   378,   274,   378,   300,    -1,    67,   265,   385,   266,
      -1,    -1,   274,   357,    -1,    -1,   274,   378,    -1,    -1,
      97,   364,   366,   363,   267,   311,   268,    -1,   388,    -1,
     388,     9,   388,    -1,   100,    -1,   100,   357,    -1,    -1,
     265,   365,   266,    -1,   368,    -1,   254,   367,    -1,   253,
     367,    -1,   367,   254,   367,    -1,   367,   253,   367,    -1,
     269,   357,   274,   357,   274,   357,   274,   357,   274,   357,
     270,    -1,   269,   357,   274,   357,   274,   357,   274,   357,
     270,    -1,   269,   357,   274,   357,   274,   357,   270,    -1,
     265,   357,   274,   357,   274,   357,   266,    -1,   370,    -1,
     369,   274,   370,    -1,   357,    -1,   373,    -1,   269,   270,
      -1,   269,   374,   270,    -1,   254,   269,   374,   270,    -1,
     357,   255,   269,   374,   270,    -1,   269,   270,    -1,   269,
     374,   270,    -1,   254,   269,   374,   270,    -1,   370,    -1,
     269,     8,   270,    -1,     5,    -1,   254,   373,    -1,   357,
     255,   373,    -1,   357,     8,   357,    -1,   357,     8,   357,
       8,   357,    -1,   105,   269,   357,   270,    -1,   105,   269,
       8,   270,    -1,   105,     5,    -1,   324,   269,     8,   270,
      -1,   324,     5,    -1,   145,   323,   372,    -1,   148,   323,
     370,    -1,   323,   201,    68,   370,    -1,    68,   323,   269,
     374,   270,    -1,    77,   324,   269,   357,   270,    -1,    78,
     324,   269,   357,   270,    -1,    79,   324,   269,   357,   270,
      -1,   129,    68,   325,   269,   357,   270,    -1,   125,   111,
     269,   357,   270,   129,   269,   357,   274,   357,   270,    -1,
     126,   111,   269,   357,   270,   129,   269,   357,   274,   357,
     270,    -1,   126,   108,   269,   357,   270,   129,   269,   357,
     270,    -1,   129,   105,   269,   357,   270,   201,   111,   269,
     357,   270,    -1,   198,   324,   269,   357,   270,    -1,   327,
      -1,   337,    -1,   346,    -1,   388,   299,   300,    -1,   388,
     271,   301,   299,   300,    -1,   388,     9,   388,   271,   301,
     299,   300,    -1,    42,   267,   388,   268,    -1,    42,   267,
     373,   268,    -1,    42,   265,   373,   266,    -1,    42,   299,
     269,   374,   270,   300,    -1,   388,   299,   269,   374,   270,
     300,    -1,    43,   299,   357,   274,   357,   274,   357,   300,
      -1,    44,   299,   357,   274,   357,   274,   357,   300,    -1,
      45,   299,   378,   300,    -1,    46,   299,   357,   274,   357,
     274,   357,   274,   357,   274,   357,   274,   357,   300,    -1,
     221,   299,   373,   300,    -1,    33,   299,   373,   300,    -1,
     357,    -1,   373,    -1,   374,   274,   357,    -1,   374,   274,
     373,    -1,   269,   357,   274,   357,   274,   357,   274,   357,
     270,    -1,   269,   357,   274,   357,   274,   357,   270,    -1,
     388,    -1,     4,   271,   198,   271,     4,    -1,   269,   377,
     270,    -1,   388,   267,   357,   268,   271,   199,    -1,   375,
      -1,   377,   274,   375,    -1,   379,    -1,   388,    -1,   388,
     267,   357,   268,    -1,   388,   265,   357,   266,    -1,   388,
     271,   301,    -1,   388,     9,   388,   271,   301,    -1,   388,
     271,   301,   265,   357,   266,    -1,   388,     9,   388,   271,
     301,   265,   357,   266,    -1,   388,   267,   357,   268,   271,
       4,    -1,   323,   269,   357,   270,    -1,   145,   323,   269,
     357,   270,    -1,     5,    -1,   235,   267,   388,   268,    -1,
      71,    -1,   233,    -1,    80,    -1,    82,    -1,   218,   265,
     378,   266,    -1,   217,   265,   378,   274,   378,   266,    -1,
     219,   299,   378,   300,    -1,   219,   299,   378,   274,   378,
     300,    -1,   229,   265,   364,   361,   266,    -1,   229,   265,
     364,   271,   301,   361,   266,    -1,    52,   299,   385,   300,
      -1,    53,   265,   378,   266,    -1,    54,   265,   378,   266,
      -1,    55,   265,   378,   274,   378,   274,   378,   266,    -1,
      50,   299,   385,   300,    -1,    64,   299,   378,   300,    -1,
      65,   299,   378,   300,    -1,    66,   299,   378,   300,    -1,
      63,   299,   357,   274,   378,   274,   378,   300,    -1,    58,
     299,   378,   274,   357,   274,   357,   300,    -1,    58,   299,
     378,   274,   357,   300,    -1,    51,   299,   378,   300,    -1,
      51,   299,   378,   274,   374,   300,    -1,    72,   299,   378,
     300,    -1,    73,    -1,    74,    -1,    57,   299,   378,   300,
      -1,    56,   299,   378,   300,    -1,    -1,   101,   299,   379,
     380,   314,   300,    -1,    98,   299,   381,   300,    -1,   272,
     357,    -1,   388,     9,   272,   357,    -1,    50,   299,   384,
     300,    -1,   385,    -1,   384,    -1,   269,   385,   270,    -1,
     378,    -1,   386,    -1,   385,   274,   378,    -1,   385,   274,
     386,    -1,   388,   265,   266,    -1,   388,   271,   301,   265,
     266,    -1,   388,     9,   388,   271,   301,   265,   266,    -1,
       4,   273,   269,   357,   270,    -1,   387,   273,   269,   357,
     270,    -1,   236,   267,   378,   268,   273,   269,   357,   270,
      -1,     4,    -1,   387,    -1,   236,   267,   378,   268,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   274,   274,   275,   280,   282,   286,   287,   288,   289,
     318,   319,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,   331,   332,   336,   340,   347,   352,   357,
     362,   376,   389,   402,   415,   443,   457,   470,   483,   502,
     507,   508,   509,   510,   511,   512,   516,   518,   523,   525,
     531,   635,   530,   653,   660,   671,   670,   688,   695,   706,
     705,   722,   739,   762,   761,   775,   776,   777,   778,   779,
     783,   784,   790,   790,   792,   792,   797,   798,   799,   800,
     801,   802,   808,   809,   810,   811,   816,   822,   883,   898,
     926,   936,   941,   949,   954,   962,   971,   976,   988,  1005,
    1011,  1020,  1038,  1056,  1065,  1077,  1082,  1090,  1110,  1133,
    1153,  1161,  1178,  1196,  1234,  1255,  1267,  1281,  1281,  1283,
    1285,  1294,  1304,  1303,  1324,  1323,  1341,  1351,  1350,  1364,
    1366,  1374,  1380,  1385,  1412,  1414,  1417,  1419,  1423,  1424,
    1428,  1440,  1444,  1448,  1452,  1465,  1479,  1487,  1500,  1502,
    1506,  1507,  1512,  1520,  1529,  1537,  1551,  1569,  1573,  1580,
    1589,  1592,  1598,  1602,  1614,  1617,  1624,  1627,  1633,  1656,
    1672,  1688,  1705,  1722,  1759,  1803,  1819,  1835,  1867,  1883,
    1900,  1916,  1966,  1984,  2005,  2026,  2032,  2038,  2045,  2076,
    2091,  2113,  2136,  2159,  2182,  2206,  2230,  2254,  2280,  2297,
    2313,  2331,  2349,  2361,  2375,  2374,  2404,  2406,  2408,  2410,
    2412,  2420,  2422,  2424,  2426,  2434,  2436,  2438,  2446,  2448,
    2450,  2452,  2462,  2478,  2494,  2510,  2526,  2542,  2559,  2585,
    2627,  2648,  2669,  2695,  2696,  2701,  2704,  2708,  2725,  2745,
    2765,  2784,  2811,  2836,  2861,  2873,  2879,  2894,  2925,  2937,
    2946,  2953,  2965,  2985,  2989,  2994,  2998,  3003,  3010,  3017,
    3024,  3036,  3109,  3127,  3152,  3167,  3219,  3225,  3237,  3269,
    3273,  3277,  3282,  3289,  3294,  3304,  3309,  3315,  3323,  3334,
    3342,  3346,  3350,  3354,  3361,  3365,  3369,  3373,  3377,  3389,
    3398,  3418,  3444,  3460,  3477,  3494,  3516,  3538,  3573,  3581,
    3589,  3595,  3602,  3609,  3629,  3655,  3667,  3678,  3696,  3714,
    3733,  3732,  3757,  3756,  3783,  3782,  3807,  3806,  3829,  3845,
    3862,  3879,  3902,  3930,  3933,  3939,  3951,  3971,  3975,  3979,
    3983,  3987,  3991,  3995,  3999,  4008,  4021,  4022,  4023,  4024,
    4025,  4029,  4030,  4031,  4032,  4033,  4036,  4060,  4079,  4102,
    4105,  4133,  4136,  4153,  4156,  4162,  4165,  4172,  4175,  4182,
    4205,  4224,  4265,  4310,  4350,  4375,  4382,  4393,  4410,  4427,
    4457,  4483,  4509,  4541,  4569,  4595,  4621,  4647,  4673,  4695,
    4707,  4755,  4809,  4824,  4836,  4842,  4854,  4861,  4876,  4885,
    4906,  4907,  4908,  4912,  4918,  4930,  4948,  4976,  4977,  4978,
    4979,  4980,  4981,  4982,  4983,  4984,  4991,  4992,  4993,  4994,
    4995,  4996,  4997,  4998,  4999,  5000,  5001,  5002,  5003,  5004,
    5005,  5006,  5007,  5008,  5009,  5010,  5011,  5012,  5013,  5014,
    5015,  5016,  5017,  5018,  5019,  5020,  5021,  5022,  5023,  5024,
    5025,  5026,  5027,  5028,  5029,  5030,  5031,  5040,  5041,  5042,
    5043,  5044,  5045,  5046,  5047,  5048,  5049,  5050,  5055,  5054,
    5062,  5066,  5071,  5076,  5080,  5085,  5090,  5094,  5098,  5102,
    5106,  5110,  5114,  5120,  5135,  5139,  5145,  5150,  5169,  5189,
    5210,  5214,  5218,  5222,  5226,  5230,  5234,  5239,  5249,  5259,
    5264,  5275,  5284,  5289,  5294,  5322,  5323,  5329,  5330,  5336,
    5335,  5358,  5360,  5365,  5367,  5373,  5374,  5379,  5383,  5387,
    5391,  5395,  5402,  5406,  5410,  5414,  5421,  5426,  5433,  5438,
    5442,  5446,  5450,  5458,  5469,  5473,  5477,  5488,  5492,  5496,
    5510,  5518,  5526,  5533,  5543,  5566,  5571,  5577,  5582,  5588,
    5599,  5605,  5619,  5625,  5637,  5651,  5664,  5694,  5717,  5737,
    5756,  5776,  5793,  5803,  5813,  5823,  5835,  5839,  5844,  5856,
    5860,  5864,  5868,  5886,  5894,  5902,  5931,  5941,  5957,  5968,
    5973,  5977,  5981,  5993,  5997,  6009,  6026,  6036,  6040,  6055,
    6060,  6067,  6071,  6076,  6090,  6104,  6108,  6112,  6116,  6120,
    6128,  6134,  6143,  6147,  6151,  6159,  6165,  6171,  6175,  6182,
    6190,  6197,  6206,  6210,  6214,  6229,  6243,  6257,  6269,  6285,
    6294,  6303,  6313,  6324,  6332,  6340,  6344,  6362,  6369,  6375,
    6381,  6388,  6396,  6395,  6405,  6429,  6431,  6437,  6442,  6444,
    6449,  6454,  6459,  6461,  6465,  6477,  6491,  6495,  6502,  6510,
    6518,  6529,  6531,  6534
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
     329,   329,   330,   330,   330,   330,   330,   330,   330,   330,
     331,   331,   332,   333,   333,   333,   333,   333,   333,   333,
     333,   334,   334,   334,   334,   334,   334,   334,   334,   334,
     334,   334,   334,   334,   334,   334,   334,   334,   334,   334,
     334,   334,   334,   334,   334,   334,   334,   334,   334,   334,
     334,   334,   335,   336,   336,   336,   336,   336,   336,   336,
     336,   336,   336,   336,   336,   336,   336,   337,   337,   337,
     338,   337,   339,   337,   340,   337,   341,   337,   337,   337,
     337,   337,   337,   342,   342,   343,   343,   343,   343,   343,
     343,   343,   343,   343,   343,   343,   344,   344,   344,   344,
     344,   345,   345,   345,   345,   345,   346,   346,   347,   348,
     348,   349,   349,   350,   350,   351,   351,   352,   352,   353,
     353,   353,   353,   353,   353,   353,   353,   353,   353,   353,
     353,   353,   353,   353,   353,   353,   353,   353,   353,   353,
     353,   353,   353,   353,   353,   353,   354,   354,   354,   354,
     355,   355,   355,   356,   356,   356,   356,   357,   357,   357,
     357,   357,   357,   357,   357,   357,   357,   357,   357,   357,
     357,   357,   357,   357,   357,   357,   357,   357,   357,   357,
     357,   357,   357,   357,   357,   357,   357,   357,   357,   357,
     357,   357,   357,   357,   357,   357,   357,   357,   357,   357,
     357,   357,   357,   357,   357,   357,   357,   358,   358,   358,
     358,   358,   358,   358,   358,   358,   358,   358,   359,   358,
     358,   358,   358,   358,   358,   358,   358,   358,   358,   358,
     358,   358,   358,   358,   358,   358,   358,   358,   358,   358,
     358,   358,   358,   358,   358,   358,   358,   358,   358,   358,
     358,   358,   358,   358,   358,   360,   360,   361,   361,   363,
     362,   364,   364,   365,   365,   366,   366,   367,   367,   367,
     367,   367,   368,   368,   368,   368,   369,   369,   370,   370,
     370,   370,   370,   370,   371,   371,   371,   372,   372,   372,
     373,   373,   373,   373,   373,   373,   373,   373,   373,   373,
     373,   373,   373,   373,   373,   373,   373,   373,   373,   373,
     373,   373,   373,   373,   373,   373,   373,   373,   373,   373,
     373,   373,   373,   373,   373,   373,   373,   373,   373,   374,
     374,   374,   374,   375,   375,   375,   375,   376,   376,   377,
     377,   378,   378,   378,   378,   378,   378,   378,   378,   378,
     378,   378,   379,   379,   379,   379,   379,   379,   379,   379,
     379,   379,   379,   379,   379,   379,   379,   379,   379,   379,
     379,   379,   379,   379,   379,   379,   379,   379,   379,   379,
     379,   379,   380,   379,   379,   381,   381,   382,   383,   383,
     384,   385,   385,   385,   385,   386,   386,   386,   387,   387,
     387,   388,   388,   388
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
       6,     7,     4,     5,     5,     6,     6,     3,     4,     3,
       5,     6,     5,     4,     3,     4,     3,     4,     5,     4,
       5,     3,     5,     7,     7,     3,     2,     7,     3,     2,
       3,     2,     2,     2,     2,    15,     2,     2,     7,     2,
       9,    11,     2,     4,     2,     2,     2,     2,     2,     2,
       5,     8,    11,     6,     8,     8,    10,     1,     2,     2,
       1,     3,     3,     4,     4,     1,     1,     5,    11,    13,
       0,     7,     0,    13,     0,    15,     0,     6,     9,     2,
       3,    10,    13,     1,     2,     5,     7,     2,     2,     3,
       2,     3,     2,     3,     9,     6,     1,     1,     1,     1,
       1,     0,     2,     3,     3,     4,     9,     4,    14,     0,
       3,     0,     1,     0,     2,     0,     2,     0,     2,     5,
       6,     7,     6,     5,     3,     8,     6,     8,     8,     5,
       4,     6,    11,    11,    18,    18,    12,    12,    12,    10,
       4,     4,     4,     4,     4,     6,     2,     3,     6,     2,
       1,     1,     1,     2,     5,     7,    10,     1,     3,     2,
       2,     2,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       5,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     6,     4,     4,     4,     4,     4,     4,     4,
       4,     6,     6,     6,     4,     6,     6,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     6,
       1,     4,     6,     1,     4,     4,     4,     6,     5,     7,
       8,    10,     4,     4,     6,     4,     3,     2,     5,     5,
       3,     5,     6,     8,     6,     8,     6,     4,     7,     6,
       6,     6,     4,     6,     4,     0,     2,     0,     2,     0,
       7,     1,     3,     1,     2,     0,     3,     1,     2,     2,
       3,     3,    11,     9,     7,     7,     1,     3,     1,     1,
       2,     3,     4,     5,     2,     3,     4,     1,     3,     1,
       2,     3,     3,     5,     4,     4,     2,     4,     2,     3,
       3,     4,     5,     5,     5,     5,     6,    11,    11,     9,
      10,     5,     1,     1,     1,     3,     5,     7,     4,     4,
       4,     6,     6,     8,     8,     4,    14,     4,     4,     1,
       1,     3,     3,     9,     7,     1,     5,     3,     6,     1,
       3,     1,     1,     4,     4,     3,     5,     6,     8,     6,
       4,     5,     1,     4,     1,     1,     1,     1,     4,     6,
       4,     6,     5,     7,     4,     4,     4,     8,     4,     4,
       4,     4,     8,     8,     6,     4,     6,     4,     1,     1,
       4,     4,     0,     6,     4,     2,     4,     4,     1,     1,
       3,     1,     1,     3,     3,     3,     5,     7,     5,     5,
       8,     1,     1,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     2,     3,     1,   641,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   206,     0,     0,   207,     0,     0,   208,     0,   209,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   336,   337,   338,
     339,   340,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   297,     0,     0,   305,   306,     0,
       0,     0,   300,     0,     0,     0,     0,     0,     0,   390,
     391,   392,     0,     0,     0,     5,     6,     7,     8,    10,
       0,    11,    12,    13,    14,    15,    23,    22,    21,    16,
       0,    17,    18,    19,    20,     0,    24,     0,   642,     0,
     235,     0,     0,     0,     0,     0,     0,   274,     0,   276,
     277,   272,   273,     0,   279,     0,   282,   235,     0,   284,
     285,   286,   287,   119,   129,   641,   505,   501,    72,    73,
       0,   206,   207,   208,   209,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   288,
     289,     0,   218,   219,   220,     0,     0,     0,     0,   447,
     448,   450,   451,   449,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   455,   456,   457,     0,     0,   206,
     211,   212,   213,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   452,   453,
     454,     0,     0,     0,     0,     0,     0,     0,     0,   552,
     553,     0,   554,   518,   397,   460,   463,   319,   519,   501,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   204,
     211,   212,     0,   213,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   507,     0,     0,   235,     0,     0,     0,     0,     0,
       0,     0,     0,   641,     0,     0,   235,     0,     0,   386,
       0,   389,     0,     0,   215,   216,     0,     0,   529,     0,
       0,   527,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   641,     0,     0,   575,     0,     0,
       0,     0,   269,     0,     0,     0,   501,   271,     0,   592,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   594,     0,   618,   619,   596,   597,     0,
       0,     0,     0,     0,     0,   595,     0,     0,     0,     0,
     298,   299,     0,   235,     0,   235,     0,     0,     0,   266,
       0,     0,   235,   393,     0,     0,    84,     0,    65,     0,
       0,    69,    68,    67,    66,    71,    70,    72,    73,     0,
       0,     0,     0,     0,     0,     0,   581,   501,     0,   234,
       0,   233,     0,   185,     0,     0,   581,   582,     0,     0,
       0,   631,     0,   632,   582,     0,     0,     0,   117,   117,
       0,   499,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   569,
     570,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    72,    73,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     536,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   400,     0,
     399,   530,   401,     0,   520,     0,     0,   501,     0,   538,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    72,    73,     0,   477,     0,     0,     0,     0,
       0,     0,     0,   320,     0,   353,   353,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   235,     0,
     235,   235,     0,   509,   508,     0,     0,     0,     0,   235,
     235,     0,     0,     0,     0,   316,     0,   235,     0,     0,
       0,   355,     0,     0,     0,     0,     0,     0,   235,   249,
       0,     0,   247,   387,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   364,   268,     0,     0,
       0,     0,     0,     0,     0,   235,     0,     0,     0,     0,
       0,   399,   270,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     302,   301,     0,   254,     0,     0,   256,     0,     0,     0,
     235,     0,     0,     0,   341,     0,     0,     0,     0,     0,
       0,     0,     0,    76,    79,    77,    78,    80,    81,     0,
       0,     0,     0,    88,    74,    75,     0,     0,     0,   265,
      39,   261,     0,     0,     0,     0,     0,   229,     0,     0,
       0,     0,     0,   236,     0,     0,   186,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   283,     0,     0,   118,     0,     0,
       0,   503,     0,     0,   502,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   347,     0,     0,     0,   210,     0,     0,
       0,     0,     0,     0,   381,   382,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   501,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   458,   476,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   539,   540,     0,     0,     0,     0,     0,
       0,   495,     0,   398,   521,     0,     0,     0,     0,   532,
       0,   417,   416,   415,   414,   410,   411,   418,   419,   413,
     412,   403,   402,     0,   404,   531,   405,   408,   406,   407,
     409,   502,     0,     0,   480,     0,   555,     0,     0,     0,
       0,     0,     0,     0,     0,   351,     0,     0,     0,     0,
       0,     0,   384,     0,     0,     0,     0,     0,   383,     0,
     235,     0,     0,     0,     0,     0,   511,   510,     0,     0,
       0,     0,     0,     0,     0,   310,     0,     0,     0,     0,
       0,   370,     0,     0,     0,   248,     0,     0,     0,   242,
       0,     0,     0,     0,   380,   398,   528,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   303,   304,     0,   404,   502,   480,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   622,     0,     0,     0,
     497,     0,     0,   253,   257,   255,   259,     0,     0,   643,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    95,
       0,     0,   398,     0,     0,     0,    65,     0,     0,    87,
       0,    65,    66,     0,     0,     0,   502,     0,     0,   480,
       0,     0,     0,   204,     0,     0,     0,   638,    27,    25,
      26,     0,     0,     0,     0,     0,   585,    29,     0,    28,
       0,     0,   262,   633,   634,     0,   635,   585,     0,     0,
      82,   120,    83,   130,   504,   506,   136,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     290,   235,   571,   572,   221,     9,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   444,   421,   431,     0,   433,
     434,   435,   436,   437,   568,   438,   439,   440,     0,     0,
       0,     0,     0,   560,   559,   558,     0,     0,     0,   565,
       0,   492,     0,     0,     0,   494,     0,     0,     0,     0,
     134,   475,   535,   534,   214,     0,     0,     0,     0,     0,
       0,     0,     0,   461,   567,   466,     0,   472,     0,     0,
       0,     0,   522,     0,     0,   473,   541,   537,     0,     0,
       0,     0,   465,   464,    72,    73,   487,     0,     0,     0,
       0,     0,     0,     0,   398,   349,   354,   352,     0,   363,
       0,   157,   158,     0,   214,     0,   398,     0,     0,     0,
       0,     0,   243,     0,   258,   260,     0,     0,     0,   222,
     224,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   323,     0,   307,     0,   235,   235,     0,   356,
     369,     0,     0,     0,     0,   244,     0,     0,     0,     0,
     217,   359,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   250,     0,     0,     0,     0,     0,     0,
       0,   608,     0,   615,   604,   605,   606,     0,   621,   620,
       0,     0,   609,   610,   611,   617,   625,   624,     0,   148,
       0,   598,     0,   600,     0,     0,     0,   593,     0,     0,
     252,     0,     0,     0,     0,   342,     0,     0,     0,   394,
       0,   639,     0,   109,    65,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   103,     0,     0,     0,
       0,   590,    50,     0,     0,     0,    63,     0,    40,    41,
      42,    43,    44,    45,     0,   465,   464,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   584,
     583,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   144,     0,     0,     0,     0,   137,   138,     0,     0,
       0,     0,   164,   164,     0,     0,     0,     0,     0,   160,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   360,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   542,   543,   544,   545,     0,
       0,     0,     0,     0,     0,     0,   551,     0,     0,     0,
     495,   496,     0,   468,     0,     0,   533,   420,   523,   481,
     479,     0,   478,     0,     0,   556,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   362,     0,     0,     0,     0,
       0,   385,     0,     0,     0,    76,     0,   251,     0,     0,
       0,     0,     0,     0,     0,   328,     0,     0,   327,     0,
     330,     0,   332,     0,   317,   324,     0,     0,     0,     0,
       0,   371,     0,     0,   246,   245,   388,     0,     0,     0,
      36,    37,     0,     0,     0,     0,     0,     0,   576,     0,
       0,     0,   293,   481,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   497,   498,   602,     0,   366,
       0,     0,   235,   343,     0,   344,   235,     0,     0,   591,
       0,    94,     0,     0,     0,     0,    92,     0,   579,     0,
     107,     0,    99,   101,     0,     0,     0,    89,     0,     0,
       0,     0,     0,    35,   481,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    30,    31,     0,
     586,     0,     0,    33,    32,     0,   586,   636,   278,     0,
       0,   121,   126,     0,     0,     0,   140,   146,   147,   143,
     141,   142,   500,     0,    85,     0,    86,   168,     0,     0,
       0,     0,   169,   188,   189,   166,     0,     0,     0,   170,
     199,   190,   194,   195,   191,   192,   193,   178,     0,     0,
     432,   446,   445,   441,   442,   443,   561,     0,     0,     0,
     490,   491,   493,   135,   459,     0,     0,     0,   546,     0,
     489,   462,   467,     0,     0,   495,   200,   474,    72,    73,
       0,   486,   482,   484,   562,   196,     0,     0,     0,   160,
       0,     0,   361,     0,   159,     0,     0,     0,     0,     0,
       0,   267,     0,     0,     0,     0,   235,   235,     0,     0,
     329,   518,     0,     0,   331,   333,     0,     0,   311,   227,
     228,   197,     0,     0,     0,     0,     0,     0,     0,   175,
       0,   176,     0,     0,     0,     0,     0,     0,   110,   114,
       0,   616,     0,     0,   614,     0,   626,     0,     0,   149,
     150,   623,   599,   601,     0,     0,     0,     0,   341,   345,
     341,     0,   395,    93,     0,     0,    65,     0,     0,    91,
       0,   577,     0,     0,     0,     0,     0,     0,   629,   628,
       0,     0,     0,     0,     0,   516,     0,     0,    76,   263,
     482,   264,     0,     0,     0,     0,     0,   240,   237,     0,
       0,   589,   587,     0,     0,     0,     0,   122,   127,     0,
       0,     0,   569,   570,   139,   365,   165,   173,   174,   179,
       0,     0,     0,     0,     0,   181,     0,   291,     0,     0,
       0,     0,     0,     0,     0,     0,   469,     0,     0,     0,
     557,   488,     0,     0,   180,     0,   201,   350,     0,     0,
       0,     0,   202,     0,     0,     0,     0,     0,     0,   515,
     514,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   367,   368,    38,   183,   184,     0,
     574,     0,     0,   295,   294,     0,     0,     0,     0,     0,
       0,     0,     0,   152,   153,   156,   155,   154,     0,   603,
       0,   640,     0,     0,     0,     0,     0,     0,     0,     0,
     104,   105,   580,     0,     0,     0,    96,     0,     0,     0,
      46,     0,     0,     0,     0,     0,    48,     0,   241,   238,
     239,    34,     0,     0,   637,   280,     0,   134,   148,     0,
       0,   145,     0,     0,     0,   167,   198,     0,     0,     0,
       0,   563,   564,     0,     0,     0,     0,     0,   495,   470,
     483,   485,     0,     0,   182,   205,     0,     0,     0,   357,
     357,     0,   115,   116,   235,     0,   225,   226,   318,     0,
     325,     0,     0,   235,     0,   232,     0,   230,     0,     0,
       0,     0,   524,     0,   111,   113,   112,   607,   613,   612,
     151,     0,     0,     0,   346,     0,     0,   108,   100,   102,
       0,    90,   630,    97,    98,    51,     0,     0,     0,     0,
     517,     0,     0,   483,   588,     0,     0,     0,     0,   124,
     627,     0,   131,     0,     0,     0,     0,   187,     0,     0,
     549,     0,     0,     0,   321,     0,   171,   172,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   513,     0,
     335,     0,     0,   312,     0,   231,     0,   573,   296,     0,
     525,     0,   379,   235,   396,     0,   578,     0,    47,     0,
       0,     0,    64,    49,     0,   281,   123,   128,   134,     0,
       0,   162,   163,   161,     0,     0,     0,   550,   471,     0,
       0,     0,     0,   358,   372,     0,     0,   373,     0,   223,
       0,   326,     0,   308,     0,   235,   177,   526,   292,   341,
     106,     0,     0,     0,     0,     0,     0,   132,   133,     0,
     547,   548,     0,   203,     0,   376,     0,   377,   378,   512,
       0,     0,   314,     0,     0,    55,     0,    61,     0,     0,
     125,     0,   322,     0,     0,   334,   313,   309,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   348,
      52,     0,    59,     0,   275,   566,     0,     0,   315,     0,
      53,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    56,    54,     0,    57,     0,   374,   375,     0,     0,
      62,    60,    58
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,   125,  1111,   126,   127,  1095,  1959,  1965,
    1398,  1618,  2117,  2219,  1399,  2201,  2233,  1400,  2221,  1401,
    1402,  1622,   460,   625,   626,  1183,  1721,   128,   818,   488,
    1977,  2128,  1978,   489,  1851,  1480,  1435,  1436,  1437,  1582,
    1789,  1790,  1260,  1678,  1669,  1861,   793,   637,   297,   298,
     367,   216,   299,   470,   471,   132,   133,   134,   135,   136,
     137,   138,   300,  1295,  2154,  2198,   993,  1291,  1292,   301,
    1074,   302,   142,  1514,  1258,   965,  1000,  2092,   143,   144,
     145,   146,   303,   304,  1210,  1231,  1356,   305,   823,   306,
     822,   491,   653,   341,  1824,   371,  1928,   372,   308,   595,
     386,  1382,  1609,   481,   476,  1349,  1054,  1658,  1817,  1818,
    1039,   483,   148,   396
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1940
static const yytype_int16 yypact[] =
{
   12738,    60,   149, 12951, -1940, -1940,   158,   148,    82,   -86,
     -46,    71,     9,   256,   335,   374,   385,   137,    37,    38,
     152,   409,   456,   469,   479,   233,   302,    58,    92,   400,
      92,   272,   309,   328,    52,   372,   421,    56,   473,   478,
     486,   489,   507,   527,   529,   534,   537,   540,   462,   552,
     707,   817,   820,   579,   411,   751,   600,  6500,   606,   584,
     612,   779,   -66,   285,   400,     4,   342,   644,   811,  -123,
     662,   -58,   -58,   663,   226,   688,   702, -1940, -1940, -1940,
   -1940, -1940,   684,   401,   863,   868,   109,    36,   985,   891,
     889,   325,  5974,   893,  1001,  1002,  1003,  5974,  1008,   -93,
     -90,   746,    19,    69, -1940,   748,   749, -1940, -1940,  4502,
    1010,   752, -1940, 13207,   753, 13270,    11,    12,   400, -1940,
   -1940, -1940, 11415,   754,  1016, -1940, -1940, -1940, -1940, -1940,
     755, -1940, -1940, -1940, -1940, -1940, -1940, -1940, -1940, -1940,
     207, -1940, -1940, -1940, -1940,     7, -1940,  1017,   761,  5709,
     631,   766,  1030, 11415, 13143, 13143, 13143, -1940, 11415, -1940,
   -1940, -1940, -1940, 13143, -1940, 11415, -1940, -1940, 11415, -1940,
   -1940, -1940, -1940, -1940, -1940,   764,   777,  1035, -1940, -1940,
    7426, -1940, -1940, -1940, -1940,   780,  7426, 11415, 11415, 11415,
     786, 11415, 11415, 11415,   787, 11415, 11415, 11415, 11415, 11415,
   11415, 11415, 13143, 11415, 11415, 11415, 11415,  5974,   788, -1940,
   -1940,  9120, -1940, -1940, -1940,   785,  5974,  6763, 13143, -1940,
   -1940, -1940, -1940, -1940,    92,    92,    92,    92,    92,    92,
      92,    92,    92,    92,    92,    92,    92,    92,    92,    92,
      92,    92,    92,    92,    92,    92,    92,    92,    92,    92,
     288,    92,    92,    92,    92,    92,   793,    92,    92,   794,
     400,   503,   503,   503, -1940, -1940, -1940,    92,    92,    29,
     859,   860,   861,   795,   952,   415,   -17,  6763,   927,   400,
     400,   503,   801,    92,    92,   802,   804,   806, -1940, -1940,
   -1940, 11415,  7026, 11415, 11415,  7289,    58,   874,    31, -1940,
   -1940,   808, -1940,  5651, -1940, -1940, -1940, -1940, -1940,   167,
   11415,  9120,  9120,   813,   814,  7552,  5974,  5974,  5974, -1940,
   -1940, -1940,   816, -1940,   818,   824,  7815,   825,  4777,  1081,
    6763,   826,    19,   827,   828,   -58,   -58,   -58, 11415, 11415,
     292, -1940,   314,   -58, 10097,   336,  9120,  9120, 11415,  5974,
    5974,  5974,   348,    18,  1092,   833, -1940,  1095,  1096, -1940,
     835, -1940,   836,   837, -1940, -1940,   838,  5974, -1940, 11415,
    6237, -1940,  1102,   841,   844,   845,   846,  1109,  1110,   852,
   11415,   856, 11415, 11415,   382, 11415,   853, -1940,   922, 11415,
   11415, 11415, -1940,    92, 11415,   449,   196, -1940, 11415, -1940,
      92,    92,    92,   864,   866,   867,    92,    92,    92,    92,
      92,    92,    92, -1940,    92, -1940, -1940, -1940, -1940,    92,
      92,   870,   871,    92,   872, -1940,   857,  1119,  1120,   875,
   -1940, -1940,  1122,  1132,  1149,  1148,   892, 15249, 13143, -1940,
    9120, 11415, -1940, -1940,  6763,  6763, -1940,   890,  7426,   400,
    1151, -1940, -1940, -1940, -1940, -1940, -1940, 11415, 11415,   737,
    6763,  1154,   419,   911,  1688,   912,  1176,    89,   914, -1940,
     915, 13401, 11415, -1940,  1995,  -209, -1940,    61,  -142,  -127,
    8531, -1940,  -108, -1940,    68,  8789, 10152,  9052,  -184,  -101,
    1086, -1940,    58,   913, 11415,   917, 15765, 15790, 15815, 11415,
   15840, 15865, 15890, 11415, 15915, 15940, 15965, 15990, 16015, 16040,
   16065,   923, 16090, 16115, 16140,  4664,  1181, 11415,  9120,  5906,
   -1940,   475, 11415,  1189,  1190,   931, 11415, 11415, 11415, 11415,
   11415, 11415, 11415, 11415, 11415, 11415, 11415, 11415, 11415, 11415,
   11415, 11415, 11415,  9120, 11415, 11415, 11415, 11415, 11415, 11415,
   11415, 11415,  9120,  9120,   929, 11415, 11415, 13143, 11415, 13143,
    6763, 13143, 13143, 13143,   933,   934,   936,   937, 11415,    74,
   -1940, 10187, 11415,   938,   940,   962,   325,   963,  6763,  5974,
    6763,   968, 13143, 13143,  9120,    58,  7426,    58,   976,  9120,
     976, -1940,   976, 16165, -1940,   491,   971,    88,  1171, -1940,
    1237, 11415, 11415, 11415, 11415, 11415, 11415, 11415, 11415, 11415,
   11415, 11415, 11415, 11415, 11415,  8078, 11415, 11415, 11415, 11415,
   11415,    58, 11415, 11415,    70, -1940,   501, 16190,   506,   523,
   11415, 11415, 11415, -1940,  1260,  1261,  1261,  1004, 11415, 11415,
   11415, 11415,    13,  9120,  9120, 15277,  1009,  1264, -1940,  1005,
   -1940, -1940,  -134, -1940, -1940,  9409,  9771,   -58,   -58,   631,
     631,  -120, 10097, 10097, 11415, 11491,  -111, -1940,   550,   551,
   16215,  1270,  1272,  1276, 11415, 11415,  1274, 11415, -1940, -1940,
   11415, 11596, -1940, -1940,  9120,  9120,  9120, 11415,  1278, 16240,
    1015, 11415,  9120, 11415, 11415, 11415, -1940, -1940, 11415, 16265,
   11415, 16290, 16315,  1088, 10128, -1940,  1018,  6169, 16340, 16365,
   11415,   976, -1940, 11415,    58, 11415, 11415,    70, 15360, 13143,
   13143, 13143, 13143, 13143, 13143, 13143, 13143, 13143, 11415, 13143,
   13143, 13143, 13143,    27,  7426, 13143, 13143, 13143,    58,    58,
   -1940, -1940,  9120, -1940,  1019, 11658, -1940,  1020, 11763, 11415,
   -1940,  1011,   569, 16390, 13289,  1022,   571, 11415,  1285,  1024,
    6763, 16415, 15387, -1940, -1940, -1940, -1940, -1940, -1940,  1023,
    1291,   289,  1293, -1940, -1940, -1940,  9120,   205, 11415, -1940,
   -1940, -1940,    58, 11415, 11415,    70,  1033, -1940,  1036,   -56,
     400,     4,   400, -1940,  1037,  5592, -1940,   155,  9120,    58,
   11415, 11415,    70,  1296,  9120,  1298,  9120, 11415,  1299, 13143,
      58, 10445,    70, 11415, -1940, 11415,  1301, -1940,    58,  1302,
   13143, 11415,  1043,  1044, -1940, 11415, 10400,  7426,  1303,  1305,
    1306, 16440,  1308,  1311,  1312, 16465,  1313,  1314,  1315,  1316,
    1317,  1319,  1320, -1940,  1321,  1323,  1324, -1940, 11415, 16490,
    9120,    42,  9120, 14118, -1940, -1940,  1326, 15333, 15333, 15333,
   15333, 15333, 15333, 15333, 15333, 15333, 15333, 15333, 15333, 10476,
   15333, 15333, 15333, 15333,   970,   496, 15333, 15333, 15333, 10755,
   11014, 11273, 12418, 12524,  5906,  1067,  1068,   114,  9120, 12737,
   13221,   496, 13326,   496,  1061,  1063,  1065,   -64,  9120, 11415,
   11415, 11415, 17240, -1940,   496,  1071, 14147, 14176, 11415, 11415,
   11415,  1073, 11415, -1940, -1940, 11415,  1069,  -163,   496,  -144,
    1079,   365,   576,  1341, -1940,    70,   496,  6763,  1080,  6432,
    6695,  1433,  1660,  1273,  1273,   555,   555,   555,   555,   555,
     555,   351,   351,  9120,   284, -1940,   284,   284,   976,   976,
     976,  1082, 16515, 15414,   366,  9120, -1940,  1344,  1085,  1087,
   16540, 16565, 16590, 11415,  6763,  1351,  1352,  9839, 16615, 14205,
   16640, 16665, -1940, 11415,   586,   588,  9120,  1090, -1940, 11825,
   -1940, 11930, 11992,   -58, 11415, 11415, -1940, -1940,  1089,  1093,
   10097,  5054,  1208,   649,   -58, 12097,  1097,  1098,  1355, 11415,
    1358, -1940, 11415, 16690, 14234, -1940, 15441, 12159, 15468, -1940,
     593,   596,   602, 14263, -1940, -1940, -1940,  2160,   603, 15495,
   15522, 13359, 16715,  1361, 16740,  1362,  1363,  1100, 11415, 12264,
   11415, 11415, -1940, -1940, 15333,   284,  1101,   447,    34,   203,
     236,   203,  1107,  1108,  1103,   496,   496,  1105, 13392,   496,
     496,   496,   496, 11415,   496,  1366, -1940,  1106,  1115,   297,
     466,  1114,   604, -1940, -1940, -1940, -1940, 16765, 12326,  1111,
    1175,  1376,  1216, 10542,  1121,  1123,  1383,  6763, 14292, -1940,
   11415,  1384,   359,   185,    70,    35,  7426, 11415,  1387, -1940,
     605,  1345,  1346,  6763, 14321,   184,  1126, 16790, 15549,   575,
   11415, 11415,  1129,  1130,  1133,  1131,  8341, -1940, -1940, -1940,
   -1940, 13143,   -57,  1134, 16815, 15576,  1137, -1940,   146, -1940,
     270, 13425, -1940, -1940, -1940,  1135, -1940,  1139, 14350, 13458,
   -1940,    30, -1940, -1940, 17240, -1940,   100, 15333, 11415,   496,
     -58,  6763,  6763,  1400,  6763,  6763,  6763,  1402,  6763,  6763,
    6763,  6763,  6763,  6763,  6763,  6763,  6763,  6763,  2187,  1405,
   -1940,   631,  5906, -1940, -1940, -1940, -1940, -1940, -1940, -1940,
   -1940, -1940, -1940, -1940, -1940, -1940, -1940, -1940, 11415, -1940,
   -1940, -1940, -1940, -1940, -1940, -1940, -1940, -1940, 11415, 11415,
   11415, 11415, 11415, -1940, -1940, -1940,   610, 11415, 11415, -1940,
   11415, -1940,  6763, 13143, 13143, -1940,   617, 14379, 14408, 14437,
    1140, -1940, -1940, -1940,  1217, 14466, 14495, 14524, 11415, 14553,
   14582, 11415, 11415, -1940, -1940, -1940,    70, -1940,    70, 11415,
   11415,  1153, -1940,  6763,    92, -1940, -1940, -1940, 11415, 11415,
     619,    70,   357,  -107, 11415, 11415, -1940,   496,   626,  6763,
    9120,  9120,  1413,  1414,  1415,  3211, -1940, -1940,  1417, -1940,
    1158, 17240,  1152,  1418, -1940,  1420,  1422,  2296,  1423,  1424,
     627,   480, -1940, 12431, -1940, -1940,  -109, 13491, 13524, -1940,
   -1940, 14611,   -76,  1309,  1429, 10800,  1166,  1434,  1174,     5,
      14,   -99, -1940,   -84, -1940,   649,   631,   631,  6763, 17240,
   -1940,  2362,  1173,  1338,  1438, -1940,  1440,  1441,  1337,  1444,
   -1940, -1940,  1448,  1462,  1463, 11415,  1464,  6763,  1465,  6763,
    6763,  1469, 13557, -1940,  6958,  1007,    70, 11415, 11415,    70,
      70, -1940,  9120, -1940, -1940, -1940, -1940, 13143, -1940, -1940,
   11415, 13143, -1940, -1940, -1940, -1940, 17240, -1940,  1202,  1201,
   13143, -1940, 13143, -1940,    70, 13143,  1210, -1940,  1203,  1472,
   -1940,  1213,   400,  1214, 10897, -1940,  2864,  1215,  6763, -1940,
    1209, -1940, 14640, -1940, -1940, 11415,  1479,   740, 11415,  1480,
    1481,    19,  1484,  1220,  1485,  3057, -1940,   496,    92,    92,
    1486, -1940, -1940,  1228,  1229,  1226, -1940,  1490, -1940, -1940,
   -1940, -1940, -1940, -1940,    70,   389,  2089, 11415, 15603, 16840,
   11415,  8599, 11415,  9120,  1227,   629,  1493,   168,    70, -1940,
    1230, 11415,  1494,  1496, 11415,    70, 11059,  1498, 11415,  9378,
     496,  5119, 11415, 11415, 11415,  1238,  1231, -1940,  1505, 16865,
    1506,    96,  1371,  1371,  6763,  1508,  1512,  1530,  6763,  -114,
    1532,  1533,  1534,  1536,  1537,  1538,  1539,  1540,  1541, -1940,
    1543,  1280, 15333, 15333, 15333, 15333, 15333, 15333,   496, 13590,
   13623, 13656,  1286,   496,   496, -1940, -1940, -1940, -1940,   100,
     496,  1425,  1426,  1427, 14669,  1350, -1940, 16890, 15333,  1287,
    -198, 17240, 15333, -1940,  1552,   496, 17240, 17240, -1940,   481,
   -1940,    70, -1940, 16915, 15630, -1940,   496,  1553,   632,   634,
    6763,  6763,  6763,  1557,  1558, -1940,   258, 11415,  6763,  6763,
    6763, -1940,  1294,  1297,  1560,  1562,  1563, -1940, 11415, 11415,
   11415,  1300,  1318,  1325,  1304, -1940,  3244,  6763, -1940, 11415,
   -1940,  1566, -1940,  1576, -1940, -1940, 10097,   -49,  1322,  1328,
    1582, -1940,  9120,  1327, -1940, -1940, -1940,  1331, 11415, 11415,
   -1940, -1940, 15657,  6763,  1587,  6763,  1589,  1404, -1940, 11415,
   11415, 11415, -1940,   516,  1597,   581,   380,  1333,  4360,  1335,
   11415,     3,   496,  1339,   496,  1336, -1940, -1940,  7426, -1940,
   11415,  1342, -1940, -1940,  3575, -1940, -1940,  1340,  1609, -1940,
    3608, -1940,  1348,  1610,   363,  3800, -1940,    19, -1940,   640,
   -1940, 11415, -1940, -1940,   258,   975,  3173, -1940,  1356, 11415,
   11415,  6763,  1347, -1940,   -47,   721,  1614, 16940,  1616,  1341,
   16965,  1353,   641, 16990,   642,  1618,  1620, -1940, -1940, 13143,
    1364,  1626, 17015, -1940, -1940, 13689,  1367, -1940, -1940,  7484,
    5437, 17240, -1940,  1624,    92,  7289, -1940, -1940, -1940, 17240,
   17240, 17240, -1940,   100, -1940,  1627, -1940, -1940,   -58,  1628,
    1629,  1631, -1940, -1940, -1940,  1489,   -53,  1531,  1633, -1940,
   -1940, -1940, -1940, -1940, -1940, -1940, -1940, -1940,  1636,  1637,
   -1940, -1940, -1940, -1940, -1940, -1940, -1940, 11415, 11415, 11415,
   -1940, -1940, -1940,  1231, -1940,  1373,  1379,  1380, -1940,  1545,
   -1940, -1940, -1940, 11415,  1385,  1386, -1940, -1940, 11415, 11415,
     496,   357, -1940, -1940, -1940, -1940,  1381,  1389,  1639,  -114,
    1648, 11415, -1940,  6763, 17240,  1510,  1513,   778,  9120,  9120,
   11415, -1940,  9839, 14698, 17040,  7747,   631,   631, 11415, 11415,
   -1940,   420,  1390, 17065, -1940, -1940, 14727,   -73, -1940, -1940,
   -1940, -1940,   647,  9120, 11415,  3910,  3985,  1655,  1659, -1940,
    1661, -1940,  6763,  8010,   920, 17090, 11415, 11415, -1940, -1940,
    9477, -1940, 13143, 11415, -1940, 13143, 17240,  9740,  7426,  1394,
   -1940, -1940, -1940, -1940,  1403,  1396, 14756, 11415, 13289, -1940,
   13289,  6763, -1940, -1940,    70,    35,  7426, 11415,  1665, -1940,
    1666, -1940,    19, 15684,  6763, 13143,  1667,   496, -1940,  1401,
     496, 11415, 13722, 13755,   652, -1940, 11415, 11415,  1430, -1940,
    1431, -1940,  1415,  1687,  1690,  1422,  1692, -1940, -1940,  1695,
   11415, -1940, -1940, 11415, 11156,  1698, 11415, -1940, -1940,  1436,
    3173,   653,  5369,  1699, -1940, -1940,   578, -1940, -1940, -1940,
    1554,  1702,  1442,  1443,  1445, -1940,  1704, -1940, 15333, 15333,
   13788, 11415, 11415, 11415,  1447, 15333, -1940,  1451, 17115, 15711,
   -1940, -1940,  9120,  9120, -1940,  1707, -1940, 17240,  1712, 11415,
   11415,  1450, -1940,   659,   660, 15305,  4207,  1714,  1453, -1940,
   -1940, 11415,  1454,  1455, 14785, 15738,  1717,  6763,  1703,  1457,
   11415,  1721,   671, 14814, -1940, -1940, -1940, -1940, -1940,  1535,
   -1940, 11415, 11415, -1940, -1940, 11318,  8857,  4240,  1722,  1723,
    1466, 15333,   496, 17240, -1940, -1940, -1940, -1940,     3, -1940,
    7426, -1940, 14843,  1467,  1468,  1470,  1726,  1728,  1735,  4416,
   -1940, -1940, -1940,  1471,  1737,   672, -1940,  1738,  1739,   304,
   17240, 11415, 11415,  1482,  6763,   673, 17240, 17140, -1940, -1940,
   -1940, -1940, 17165, 13821, -1940, -1940, 14872,  1140,  1201,  6763,
     496, -1940, 11415,  7426,    58, -1940, -1940,  9120,  9120, 11415,
    1742, -1940, -1940, 11415, 13854, 14901, 13887, 11415,  1386, -1940,
   -1940, -1940,   674,   680, -1940, -1940,  4695,  4813,  6763,   502,
     601,  9120, -1940, -1940,   631,  8273, -1940, -1940, -1940,  1743,
   -1940,  1483,  6763, -1940, 14930, -1940,  1744, -1940, 11415, 14959,
   14988,  9120, -1940,   681, -1940, -1940, -1940, -1940, -1940, -1940,
   -1940,  1488,  1749,  1492, -1940,  1751,    19, -1940, -1940, -1940,
    1559, -1940, -1940, -1940, -1940, -1940, 11415, 13920, 13953,  6763,
   -1940,  1753, 11415,  1495, -1940, 11415,  1756,  1497,  1500, -1940,
   -1940,  5622, -1940,  1501,   686,   692, 15017, -1940, 13986, 11415,
   -1940, 11415, 15046,  1499, -1940,  1502, -1940, -1940,   693,  1503,
     -58,  6763,  1757,  1504,   -58,  1762,   694,  1507, -1940, 11415,
   -1940,  1768,  1632, 12493,  1509, -1940,  4849, -1940, -1940,   695,
   -1940,  1769, -1940, -1940, -1940,  1770, -1940,  1511, 17240, 11415,
   11415,   712, -1940, 17240, 14019, -1940, -1940, -1940,  1140,  7426,
    1517, -1940, -1940, -1940, 11415, 15075, 15104, -1940, -1940,  9120,
    1778,   -58,   108, -1940, -1940,   -58,   115, -1940,  1779, -1940,
   15133, -1940, 11415, -1940,   649, -1940, -1940, -1940, -1940, 13289,
   -1940, 11415, 17190, 14052,    47, 11415,  1516, -1940, -1940, 14085,
   -1940, -1940,   713, -1940,   -71, -1940,   186, -1940, -1940, -1940,
    5160,   303, 12598,  1518,   714, -1940, 11415, -1940,  6763, 15162,
   -1940, 11415, -1940,   -58,   -58, -1940, -1940, -1940,   649,  1781,
    1783,  1521, 17215,   715,  1785, 15333,   212,   220,   354, -1940,
   -1940, 13143, -1940,  1523, -1940, -1940, 11415, 11415, -1940,   720,
   -1940,  1524,  6763, 15191, 15220,  1788, 13143, 13143,   723,  1789,
    1790, -1940, -1940,   728, -1940,  1791, -1940, -1940,  1793, 13143,
   -1940, -1940, -1940
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1940, -1940, -1940, -1940,   383, -1940, -1940, -1940, -1940,  -360,
   -1940, -1940, -1940, -1940, -1940, -1940, -1940, -1940, -1940, -1940,
   -1940, -1940,  -745,  -124,    -1,  3506,  -334, -1940,  1332, -1940,
   -1940, -1940, -1940, -1940, -1940, -1939, -1940,   324,   141,  -173,
   -1940,  -132, -1940,    78,   367, -1940,  1805, -1940,   854,    -2,
    1239, -1940,     0,  -654,  -158, -1940, -1940, -1940, -1940, -1940,
   -1940,   718,  1811, -1940, -1940, -1940, -1940, -1293, -1283,  1813,
   -1788,  1814, -1940, -1940, -1940,  1186, -1940,  -187, -1940, -1940,
   -1940, -1940,  2189, -1940, -1940, -1457,   239,  1822, -1940,   -23,
   -1940, -1940,   -13, -1940, -1902,   308, -1940,   -48,  2894,  2709,
    -331,    24, -1940,  1866,   -85, -1940, -1940,    43,   215, -1741,
    -149,  1025, -1940,    -3
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -590
static const yytype_int16 yytable[] =
{
     149,   649,  1547,   131,   176,   988,   989,  1787,  1545,   486,
    1943,  1540,  1944,   443,   482,   157,   432,   434,   379,   972,
    1542,   381,   676,   384,   177,   461,  1087,   180,   427,   186,
     431,   175,  1093,  1714,   570,  1676,   599,  1429,  2067,   175,
     358,  1329,   359,   164,   166,   314,  1936,   331,  1160,   377,
    1284,   576,  1862,  2187,   309,   314,   190,   797,   340,   342,
     194,   345,   175,   326,   466,   798,     4,   178,  1285,   179,
     799,  1863,   315,   388,   763,   332,  1229,   810,   175,  1286,
    1287,  1288,  1102,   357,   816,  1289,  1290,  1677,   577,   309,
     817,   333,   334,   175,   309,   493,   764,   492,   782,   387,
    1284,   495,  1667,   774,  1431,   775,  2088,   765,   766,  1980,
     428,  1222,   320,   353,  2175,   321,   322,   323,  1285,   657,
     658,  2177,  1225,   621,   803,   771,  1432,  1226,   324,  1286,
    1287,  1288,   804,   657,   658,  1289,  1290,  1433,  1434,   805,
     983,   360,   657,   658,   657,   658,   467,   806,   462,     5,
     469,   477,   477,   477,   990,   455,   456,  2121,   808,   516,
     484,  1108,   152,   994,  1501,  1528,   809,   819,   523,   657,
     658,  1544,   380,   817,  1638,   382,   621,   657,   658,   154,
     657,   658,   657,   658,   767,   768,   665,   973,  1392,  2166,
    1546,  1541,  1374,   153,  1532,   336,   337,   325,   681,   477,
    1543,  1910,  1205,  2193,   309,   714,   354,   338,   309,  1417,
     809,   339,  1091,   309,   309,   477,  1788,   852,  1827,   155,
    1777,  1758,  -586,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   541,   542,
     543,   544,   545,   546,   547,   548,   549,   550,   551,   554,
     555,   556,   557,   558,   559,   123,   561,   562,  1877,   565,
     566,   567,   159,   123,  1545,  1374,   568,   569,   634,   635,
     636,   123,   444,   596,   309,   745,   445,   748,   158,   581,
     433,   435,   583,   584,   754,   677,  2203,   678,   385,   309,
     954,   151,   309,   597,   123,   178,  1086,   179,   571,  1053,
     600,   671,   672,   673,  1381,  1330,   165,   167,   309,   309,
     123,  1161,   309,   309,   309,   309,  2188,   191,   355,   688,
    2228,   195,   652,   309,   654,   123,   800,   309,   801,   387,
     661,   666,   802,   811,   389,   801,   156,  1375,  1378,   812,
     774,   160,   775,   309,   309,   123,   309,   309,   309,   657,
     658,   455,   456,   178,   783,   179,   784,   178,  -582,   179,
     785,   657,   658,   758,   309,   307,  1374,   309,   657,   658,
    1806,  2183,  1393,  1394,  1395,  1396,   455,   456,   356,   622,
     161,   623,  1195,  1037,   103,   624,   104,   105,   106,   107,
     108,   162,   710,   316,   112,   113,   317,   115,   318,   719,
     720,   721,   163,  1109,  1110,   725,   726,   727,   728,   729,
     730,   731,  1422,   732,   897,   169,  1109,  1110,   733,   734,
     852,   168,   737,   451,   452,   453,   454,   150,   601,   455,
     456,   151,   622,   364,   623,   477,   365,   309,   624,   657,
     658,   309,   309,   451,   452,   453,  1092,   455,   456,   366,
     327,  1099,  1284,   328,  1397,   712,  1377,   309,   455,   456,
    2194,   715,   170,   716,   786,   657,   658,   717,  1116,   774,
    1285,   775,   441,   657,   658,   171,   442,   809,  1127,   336,
     337,  1286,  1287,  1288,  1525,   172,  2216,  1289,  1290,   824,
     979,   338,   981,   982,  2217,   344,   451,   452,   453,   454,
     173,   920,   774,  1284,   775,   181,   764,  1461,   182,   995,
    1332,   183,   349,   184,   350,   309,   212,   765,   766,   213,
    1007,  1285,   214,   574,    48,   524,   575,   451,   452,   453,
     454,   913,  1286,  1287,  1288,   215,  1423,   187,  1289,  1290,
     309,  2083,   618,   619,   852,   657,   658,  1029,   620,   309,
     887,   455,   456,   552,   477,   553,   477,   309,   477,   477,
     484,   659,   919,   774,   921,   775,   904,   657,   658,   174,
    2055,  1352,  1041,  2196,   188,   309,   309,   309,  2056,   477,
     477,   309,   177,   660,   177,   307,   309,  1779,  1780,   657,
     658,  1234,  1068,   189,   767,   768,   926,   451,   452,   453,
     454,   451,   452,   453,   454,   667,   713,   616,   617,   618,
     619,   320,   309,   674,   321,   620,   323,   675,   951,   455,
     456,   455,   456,   633,  2218,   455,   456,   324,   455,   456,
     178,  1244,   179,  1245,   642,   468,  1228,   192,   647,  1229,
     309,   309,  1548,  1549,   986,   987,   774,  1088,   775,  1056,
     654,   455,   456,   703,   852,   151,  2089,  2090,  -584,   469,
     469,  2091,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   614,   615,   616,   617,   618,   619,
     207,   309,   309,   309,   620,   774,   193,   775,   776,   309,
    1906,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   612,   613,   614,   713,   616,   617,   618,   619,   455,
     456,  1036,  1327,   620,  1328,  1060,   484,   477,   484,   477,
     477,   477,   477,   477,   477,  1828,   477,   477,   477,   477,
    1055,   206,   477,   477,   477,   177,  1061,  1354,   196,   309,
    1355,   763,  1139,   197,   763,   851,  1718,   764,  1719,   852,
    1380,   198,   755,   756,   199,  2093,  2094,   309,   765,   766,
    2091,   924,   774,   764,   775,   852,   764,   774,   772,   775,
     955,  1733,   200,   309,   765,   766,   958,   765,   766,  1096,
     852,  1776,  1891,  1777,  1892,    70,    71,    72,    73,  1104,
      75,    76,   201,   959,   202,   309,  1113,   852,  1284,   203,
      85,   309,   204,   309,    89,   205,   484,  1125,   613,   614,
     713,   616,   617,   618,   619,  1131,  1285,   477,   208,   620,
     996,   997,  1273,   209,   852,   852,   210,  1286,  1287,  1288,
    1246,   657,   658,  1289,  1290,   767,   768,   455,   456,  1070,
    1407,  1076,  1328,   852,  -585,  1077,  1232,   309,   211,   309,
     852,   767,   768,   311,   767,   768,  1268,   130,  1269,  1807,
     852,  2181,   852,  1307,   217,   218,  1308,   852,   894,  1814,
     852,   310,  1309,  1312,  1358,  1387,   852,   852,   852,   852,
    1468,   312,  1262,   185,   852,   309,   633,  1475,   914,  1498,
     313,   852,  1489,   852,  1490,   309,  1506,  1524,  1545,  1636,
     852,   852,  1726,   852,  1727,  2208,   852,  1499,   852,   329,
    1811,  1834,  1836,  1246,  1812,   852,   852,  1911,   319,   330,
    1230,   852,  1963,  1981,   309,  1545,  1964,  1982,  1922,  2009,
    2010,   335,   343,   852,   852,   769,   770,  1526,  1602,  1603,
     309,  2026,  2052,  2061,  2084,   852,   809,  2062,   852,   348,
    2085,  2110,   309,  1247,   852,   852,  2131,   346,  1376,  1379,
     852,   309,  2132,  2140,  2148,  2157,   852,  1964,   852,   852,
    1276,   347,   436,   309,   351,  1246,   352,  1282,   601,   175,
     399,  1293,  2164,  2192,  2200,  2213,  1964,   852,  2062,  1964,
    2225,   361,  1573,  2235,  2226,  1574,  1575,  1964,  2238,   362,
     363,  1384,  2239,   463,   373,   374,   375,   376,   463,   463,
     463,   383,   378,   390,   391,  1571,   397,   463,   429,   398,
    1585,   438,   439,   446,   440,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   447,   472,   473,   151,   409,   410,
     411,   412,   490,  1604,   492,   494,   413,   414,   415,   416,
    1608,   499,   503,   517,   522,   417,   463,   418,   560,   563,
    -207,  -208,  -209,   573,   572,   578,   582,   585,  1081,   586,
    1624,   587,   463,   419,   309,   598,   420,   442,   630,   631,
     181,   638,  1383,   182,  1640,   646,   183,   639,   184,   640,
     309,  1646,  1902,  1903,   643,   648,   650,   651,   679,    48,
     680,   682,   683,   309,   684,   685,   686,   687,   477,   691,
     692,   693,   694,   695,   564,   696,   697,   698,  1500,  1502,
     449,   700,   705,   706,   739,   740,   741,  1441,   743,   722,
    1430,   723,   724,   579,   580,   735,   736,   738,   309,   309,
     744,   309,   309,   309,   742,   309,   309,   309,   309,   309,
     309,   309,   309,   309,   309,   746,   747,   749,   760,   757,
     773,   469,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   614,   713,   616,   617,   618,   619,
     778,   780,   781,   150,   620,   787,   821,   825,   848,   843,
    1923,   827,   421,   422,   423,   854,   855,   856,   888,   309,
     477,   477,   898,   899,   424,   900,   901,   908,   425,   909,
     426,   123,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   614,   850,   616,   617,   618,   619,
     309,   910,   912,  1495,   620,  1236,   774,   915,   775,   927,
     620,   774,   925,   775,  1815,   928,   309,   309,   309,   602,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   612,
     613,   614,   713,   616,   617,   618,   619,   963,   964,   967,
     978,   620,  1256,  1572,   980,   977,  1810,   999,  1001,  1069,
    1005,  1500,  1502,  1002,  1014,  1016,  1027,  1030,  1075,  1063,
    1065,  1079,   463,  1080,  1084,   309,   469,   469,  1085,  1089,
    1100,  1101,  1117,   759,  1119,  1122,  1106,  1130,  1132,  1135,
    1140,  1136,  1141,  1142,   309,  1144,   309,   309,  1145,  1146,
    1148,  1149,  1150,  1151,  1152,   794,  1153,  1154,  1155,   309,
    1156,  1157,  1165,  1193,   477,  1202,  1194,  1203,   477,  1204,
     794,  1212,  1218,  1221,  1652,  1227,  1657,   477,  1233,   477,
    1237,  1249,   477,  1241,  1250,  1257,  1251,  1283,  1259,  1279,
    2097,  1271,  1298,  1280,  1300,   309,  1296,  1297,  1317,  1319,
    1320,  1321,  1326,  1335,  1336,  1348,  1362,  1337,   387,  1340,
    1350,  1351,  1357,  1363,  1361,  1370,  1364,  1615,  1616,  1369,
    1373,  1367,  1368,  1386,  1410,  1388,  1389,  1404,  1412,  1411,
    1413,  1390,  1421,   477,  1426,  1418,  1425,  1444,   309,  1448,
     309,   463,  1460,   463,  1479,   463,   463,   463,  -210,  1493,
    1510,  1511,  1512,  1515,  1516,  1518,  1517,  1519,   309,  1520,
    1522,  1523,  1533,  1534,  1798,  1537,   463,   463,  1800,  1539,
    1538,   309,  1552,  1553,  1554,   309,  1555,  1556,  1557,  1442,
    1443,  1558,  1445,  1446,  1447,  1559,  1449,  1450,  1451,  1452,
    1453,  1454,  1455,  1456,  1457,  1458,  1819,  1819,  1560,  1561,
    1946,  1563,  1565,  1568,  1580,  1581,  1587,  1588,  1589,  1598,
    1808,  1952,  1590,  1592,  1596,  1601,  1606,  1611,  1607,  1713,
    1610,  1612,  1617,  1619,  1620,  1621,  1623,  1635,  1720,  1637,
    1643,  1641,  1644,  1795,  1648,  1663,  1662,   309,   309,   309,
    1472,  1664,  1666,  1668,  1672,   309,   309,   309,  1673,   794,
     607,   608,   609,   610,   611,   612,   613,   614,   713,   616,
     617,   618,   619,  1757,   309,   794,  1674,   620,  1679,  1680,
    1681,  1494,  1682,  1683,  1684,  1685,  1686,  1687,  1688,   309,
    1689,  1709,  1700,  1712,  1705,  1706,  1707,  1507,  1716,  1725,
     309,  1731,   309,  1738,  1732,  1848,  1739,  1740,  1741,  1746,
    1742,  1749,  1754,   463,   463,   463,   463,   463,   463,   463,
     463,   463,  1755,   463,   463,   463,   463,  1747,  1761,   463,
     463,   463,  1759,  1769,  1748,  1771,  1763,  1881,  1760,   794,
    1764,  1772,   794,  1778,   387,  1792,  1550,  1782,   794,  1785,
    1355,  1797,   484,   484,  1801,  1802,  1826,  1805,   309,  1804,
    1829,  1821,  1831,  1833,  1837,  1564,  1838,  1566,  1567,  1840,
    1841,  1849,  1844,  1855,  1857,  1858,   477,  1859,  1860,  1865,
    1864,  1866,  1871,  1867,  1103,  1884,  1105,   309,  1872,  1873,
    1882,  1876,   309,  1850,  1886,  1856,  1874,  1897,  1883,  1889,
    1229,  1916,  1890,   463,  1907,  1917,  1955,  1918,  1938,  1939,
    1940,  1950,  1951,  1956,   463,   809,  1597,   604,   605,   606,
     607,   608,   609,   610,   611,   612,   613,   614,   713,   616,
     617,   618,   619,  1968,   779,  1929,  1969,   620,  1970,  -589,
    -587,  1971,  1934,  1937,  1975,  1979,  1984,  1985,  1986,  1990,
    2022,  1987,  1988,  2004,  1989,  2115,  1997,  1999,  2005,  2008,
    2013,  1948,  2014,  2020,  2016,  2017,  2023,  2025,  2035,  2036,
     309,  2028,  2037,  2046,  2047,   309,   309,  2043,  2044,  1656,
    2045,  2048,  2050,  2051,  2053,  2054,   469,   469,  2077,  2100,
    2105,  2059,  1671,  2101,  2111,  2112,  1675,  2114,  2116,  2122,
     309,  2113,  2125,  2144,  -588,  2138,  2130,  2126,  2147,   309,
    2127,  2139,  2141,  2145,  2151,  2158,  2160,  2149,  2155,   477,
    2161,  2152,   477,  2168,  2173,  2178,  2190,  2209,  2199,  2210,
    2211,  2214,  2222,  2227,  2231,  2236,  2237,  2240,   309,  2241,
    1639,  2184,  1383,  1703,  1854,  2068,  2040,  1885,   129,   387,
    1670,   309,   484,  1403,   139,   911,   140,   141,  1728,  1729,
    1730,   820,   966,  2095,  1794,   147,  1735,  1736,  1737,  1947,
    1935,  1820,     0,   794,  1124,   794,   794,     0,     0,     0,
       0,     0,     0,     0,     0,  1752,     0,   484,     0,   794,
       0,     0,     0,     0,     0,  2041,     0,     0,     0,     0,
       0,   794,     0,     0,     0,  2103,     0,     0,     0,     0,
       0,  1768,     0,  1770,     0,     0,     0,     0,     0,   309,
     309,     0,     0,   794,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2072,     0,
       0,     0,     0,     0,   309,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   614,   713,   616,   617,   618,   619,
       0,     0,   794,   309,   620,     0,     0,     0,     0,  1825,
     602,   603,   604,   605,   606,   607,   608,   609,   610,   611,
     612,   613,   614,   713,   616,   617,   618,   619,     0,     0,
       0,     0,   620,     0,     0,  2159,     0,     0,  1847,     0,
       0,   309,     0,     0,     0,   463,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   309,     0,     0,     0,
       0,  2073,     0,     0,   309,   309,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2182,     0,     0,
       0,   796,     0,     0,     0,   309,     0,     0,   309,     0,
       0,     0,     0,     0,   469,   465,     0,     0,     0,   309,
     475,   478,   479,     0,     0,     0,     0,     0,   309,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1888,     0,   387,  2167,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   309,   463,   463,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   511,     0,
       0,     0,     0,     0,     0,     0,     0,  2142,     0,     0,
    1919,  2146,     0,     0,   525,     0,     0,     0,   309,     0,
       0,     0,     0,   175,   399,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1945,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1954,     0,     0,     0,     0,   794,  2174,     0,
       0,     0,  2176,     0,     0,     0,   309,     0,     0,   400,
     401,   402,   403,   404,   405,   406,   407,   408,     0,     0,
       0,     0,   409,   410,   411,   412,     0,     0,     0,     0,
     413,   414,   415,   416,     0,     0,  1311,     0,     0,   417,
       0,   418,     0,     0,     0,     0,     0,     0,     0,     0,
    2206,  2207,     0,     0,     0,   309,     0,   419,     0,     0,
     420,   463,     0,  1459,   181,   463,     0,   182,     0,     0,
     183,     0,   184,     0,   463,     0,   463,     0,   477,   463,
       0,     0,     0,    48,     0,  2021,  1591,     0,     0,   309,
       0,     0,     0,   477,   477,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   449,     0,   477,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   614,
     713,   616,   617,   618,   619,     0,     0,     0,     0,   620,
     463,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2060,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2069,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   395,     0,
       0,     0,  1521,     0,   751,     0,   421,   422,   423,     0,
       0,   437,     0,     0,     0,     0,  1825,     0,   424,     0,
       0,     0,   425,     0,   426,   123,     0,     0,     0,     0,
    2102,     0,     0,     0,     0,     0,     0,     0,   464,     0,
       0,     0,   474,     0,     0,     0,     0,   480,     0,     0,
       0,   455,   456,     0,   485,     0,     0,   487,  -583,     0,
    1625,     0,     0,     0,     0,     0,     0,  1825,  1551,     0,
       0,     0,     0,     0,     0,     0,   496,   497,   498,     0,
     500,   501,   502,     0,   504,   505,   506,   507,   508,   509,
     510,     0,   512,   513,   514,   515,     0,     0,     0,  2143,
     519,     0,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   614,   713,   616,   617,   618,   619,
       0,     0,     0,   891,   620,   893,     0,   895,   896,   602,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   612,
     613,   614,   713,   616,   617,   618,   619,     0,   916,   917,
       0,   620,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   463,
     463,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     588,   590,   592,   593,   519,     0,     0,     0,     0,     0,
       0,     0,     0,   463,     0,     0,  1825,     0,     0,   627,
     519,   519,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   645,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   655,   656,     0,
    1825,     0,     0,   656,     0,   519,   519,   670,   602,   603,
     604,   605,   606,   607,   608,   609,   610,   611,   612,   613,
     614,   713,   616,   617,   618,   619,     0,     0,   689,   519,
     620,     0,     0,     0,     0,     0,     0,     0,     0,   699,
       0,   701,   702,     0,   704,     0,     0,     0,   707,   708,
     709,     0,     0,   711,     0,     0,  1040,   718,  1042,  1043,
    1044,  1045,  1046,  1047,     0,  1049,  1050,  1051,  1052,     0,
       0,  1057,  1058,  1059,   602,   603,   604,   605,   606,   607,
     608,   609,   610,   611,   612,   613,   614,   713,   616,   617,
     618,   619,     0,     0,     0,     0,   620,     0,     0,   519,
     753,     0,     0,     0,     0,     0,   463,     0,     0,   463,
       0,     0,     0,     0,     0,     0,   761,   762,     0,     0,
       0,     0,   794,     0,   794,     0,     0,     0,     0,     0,
       0,   795,     0,     0,     0,     0,     0,     0,     0,   463,
       0,     0,     0,     0,     0,  1123,     0,     0,     0,     0,
       0,     0,     0,   826,     0,     0,  1133,     0,   831,     0,
       0,     0,   835,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   463,     0,   849,   590,     0,     0,
       0,   853,     0,     0,     0,   857,   858,   859,   860,   861,
     862,   863,   864,   865,   866,   867,   868,   869,   870,   871,
     872,   873,   874,   876,   877,   878,   879,   880,   881,   882,
     883,   884,   884,     0,   889,   890,     0,   892,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   902,     0,     0,
     906,   907,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   884,     0,     0,     0,     0,   519,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     929,   930,   931,   932,   933,   934,   935,   936,   937,   938,
     939,   940,   941,   942,   944,   946,   947,   948,   949,   950,
       0,   952,   953,     0,     0,     0,     0,     0,     0,   960,
     961,   962,     0,     0,     0,     0,     0,   968,   969,   970,
     971,     0,   519,   519,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   588,   711,   991,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1003,  1004,     0,  1006,     0,     0,  1008,
    1595,     0,     0,   519,   519,   519,  1013,     0,     0,     0,
    1017,   519,  1019,  1020,  1021,     0,     0,  1022,     0,  1024,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1034,
       0,     0,  1035,     0,   952,   953,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1048,     0,     0,
     521,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   519,     0,     0,     0,     0,     0,     0,  1067,     0,
       0,     0,     0,     0,     0,     0,  1078,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   794,     0,     0,
       0,     0,     0,     0,     0,   519,     0,  1094,     0,     0,
       0,     0,  1097,  1098,     0,     0,     0,  1416,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   519,     0,  1114,
    1115,     0,     0,   519,     0,   519,  1121,     0,     0,     0,
    1114,     0,  1128,     0,  1129,     0,     0,     0,     0,     0,
    1134,     0,     0,   794,  1137,     0,     0,     0,     0,     0,
     628,   629,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   794,  1158,     0,   944,
       0,  1162,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   668,   669,     0,     0,     0,
       0,     0,     0,  1613,     0,   463,     0,     0,     0,  1473,
    1474,     0,     0,     0,     0,     0,     0,   519,     0,     0,
     463,   463,     0,     0,     0,     0,     0,   519,  1207,  1208,
    1209,     0,     0,   463,     0,     0,     0,  1215,  1216,  1217,
       0,  1219,     0,     0,  1220,   520,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   612,   613,   614,   713,
     616,   617,   618,   619,     0,     0,     0,     0,   620,     0,
       0,     0,   519,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   519,     0,     0,     0,     0,   752,
       0,     0,  1255,     0,     0,     0,  1261,     0,     0,     0,
       0,     0,  1267,     0,     0,   519,     0,     0,     0,     0,
       0,     0,     0,  1277,  1278,     0,     0,   175,   399,  1281,
       0,     0,     0,     0,     0,     0,   591,     0,  1299,   520,
       0,  1301,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1577,     0,   520,   520,  1579,     0,     0,
       0,     0,     0,     0,     0,     0,  1583,  1322,  1584,  1324,
    1325,  1586,     0,   400,   401,   402,   403,   404,   405,   406,
     407,   408,     0,     0,     0,     0,   409,   410,   411,   412,
     520,   520,  1346,     0,   413,   414,   415,   416,     0,     0,
    1750,     0,     0,   417,     0,   418,     0,     0,     0,     0,
       0,     0,  1366,     0,   520,     0,     0,     0,     0,  1372,
       0,   419,  1626,     0,   420,     0,  1385,     0,   181,     0,
       0,   182,     0,     0,   183,     0,   184,     0,     0,  1408,
    1409,     0,     0,     0,     0,   519,     0,    48,   922,   602,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   612,
     613,   614,   713,   616,   617,   618,   619,     0,   449,     0,
       0,   620,     0,     0,     0,     0,     0,  1439,     0,     0,
       0,     0,     0,     0,   520,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   974,   975,     0,     0,     0,     0,     0,     0,
    1513,     0,     0,     0,     0,     0,     0,  1462,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1463,  1464,  1465,
    1466,  1467,     0,     0,     0,     0,  1469,  1470,     0,  1471,
     421,   422,   423,  1010,  1011,  1012,     0,     0,     0,     0,
       0,  1018,   424,     0,     0,     0,   425,  1484,   426,   123,
    1487,  1488,   591,     0,     0,     0,     0,     0,  1491,  1492,
       0,     0,     0,     0,     0,     0,     0,  1496,  1497,     0,
       0,     0,     0,  1503,  1504,     0,     0,   875,     0,   519,
     519,     0,  1815,     0,     0,     0,   885,   886,     0,     0,
       0,  1062,     0,   602,   603,   604,   605,   606,   607,   608,
     609,   610,   611,   612,   613,   614,   713,   616,   617,   618,
     619,     0,     0,     0,  1536,   620,     0,     0,   918,     0,
       0,     0,     0,   520,     0,  1090,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   612,   613,   614,   713,
     616,   617,   618,   619,  1562,  1839,     0,  1112,   620,   945,
       0,     0,     0,  1118,     0,  1120,  1503,  1504,     0,     0,
       0,   519,     0,     0,     0,     0,     0,     0,     0,  1578,
       0,     0,     0,     0,     0,     0,     0,   520,   520,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1594,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1600,     0,     0,  1605,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   520,   520,
     520,  1799,     0,     0,     0,     0,   520,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1627,  1196,     0,  1630,
     519,  1633,   519,     0,     0,     0,     0,  1206,     0,     0,
    1642,     0,     0,  1645,  1803,  1642,     0,  1649,  1651,     0,
       0,  1659,  1660,  1661,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   520,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1930,     0,
       0,  1932,  1240,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1248,     0,     0,     0,     0,     0,
     520,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1270,     0,     0,     0,     0,
       0,     0,   520,     0,     0,     0,     0,     0,   520,     0,
     520,     0,     0,     0,     0,     0,  1734,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1743,  1744,  1745,
       0,     0,     0,     0,     0,     0,  1751,     0,  1753,     0,
       0,     0,     0,     0,     0,  1756,     0,     0,     0,     0,
       0,   519,     0,     0,   945,     0,  1163,  1765,  1766,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1773,  1774,
    1775,     0,     0,     0,     0,     0,     0,     0,     0,  1786,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1796,
       0,     0,   520,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   520,     0,     0,     0,     0,     0,     0,     0,
    1813,     0,     0,     0,     0,     0,  1809,     0,  1822,  1823,
       0,     0,     0,     0,     0,  1415,     0,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   614,
     713,   616,   617,   618,   619,     0,     0,   520,     0,   620,
       0,     0,     0,     0,  1852,     0,     0,     0,     0,   520,
     602,   603,   604,   605,   606,   607,   608,   609,   610,   611,
     612,   613,   614,   713,   616,   617,   618,   619,     0,     0,
     520,     0,   620,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1868,  1869,  1870,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1875,     0,     0,     0,     0,  1878,  1879,     0,
       0,     0,     0,     0,     0,     0,  1914,     0,     0,     0,
    1887,     0,     0,     0,     0,     0,     0,   519,   519,  1895,
       0,  1896,     0,     0,     0,     0,     0,  1904,  1905,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   519,  1913,     0,     0,     0,     0,     0,  1508,
    1509,     0,     0,     0,     0,  1878,  1879,     0,   777,  1927,
       0,     0,  1931,     0,     0,     0,  1933,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1942,     0,     0,     0,
       0,  1915,     0,     0,     0,     0,  1949,     0,     0,     0,
     520,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1960,     0,     0,     0,     0,  1966,  1967,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1972,
       0,     0,  1973,  1972,     0,  1976,     0,     0,     0,     0,
       0,  1576,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   614,   713,   616,   617,   618,   619,
    1994,  1995,  1996,     0,   620,     0,     0,     0,     0,     0,
       0,   519,   519,     0,     0,   903,     0,  2220,  2006,  2007,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2015,     0,  2232,  2234,     0,     0,     0,     0,     0,  2024,
       0,     0,     0,     0,     0,  2242,     0,     0,     0,     0,
    2029,  2030,     0,     0,   711,   519,     0,     0,     0,     0,
    1632,     0,  1634,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   956,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   520,   520,     0,     0,     0,     0,
    2057,  2058,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   614,   713,   616,   617,   618,   619,
       0,  2071,     0,     0,   620,     0,   519,   519,  2076,     0,
       0,     0,  2078,     0,     0,     0,  2082,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     519,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2012,     0,     0,     0,  2106,     0,     0,
     519,     0,     0,     0,     0,     0,   520,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   614,
     713,   616,   617,   618,   619,  2118,  2034,     0,     0,   620,
       0,  2123,     0,     0,  2124,     0,     0,     0,     0,     0,
       0,  1762,     0,     0,     0,     0,     0,     0,  2135,     0,
    2136,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2150,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   520,     0,   520,  2162,  2163,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2169,     0,     0,     0,     0,   519,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2180,     0,     0,     0,     0,     0,     0,     0,     0,
    1966,     0,     0,     0,  2189,     0,     0,     0,     0,     0,
       0,     0,     0,  1166,  1167,  1168,  1169,  1170,  1171,  1172,
    1173,  1174,  1175,  1176,  1177,  2202,  1179,  1180,  1181,  1182,
    2205,  1184,  1185,  1186,  1187,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1199,     0,  1201,
       0,     0,     0,     0,     0,  2223,  2224,     0,     0,     0,
    1211,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2049,  1223,  1224,     0,     0,     0,     0,     0,
       0,     0,  1235,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   520,  1893,  1894,   602,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   612,
     613,   614,   713,   616,   617,   618,   619,     0,     0,     0,
       0,   620,  1912,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   614,   713,   616,   617,   618,   619,
       0,     0,     0,     0,   620,   219,   175,     0,   392,     0,
       0,     0,   220,   221,   222,     0,     0,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   393,   242,   243,   244,   245,
     246,   247,   248,   249,     0,  1331,  1333,  1334,     0,  1853,
       0,  1338,  1339,     0,     0,  1342,  1343,  1344,  1345,     0,
    1347,   255,   256,   257,   258,  1353,     0,     0,     0,   259,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   264,   265,   266,     0,     0,
       0,  2002,  2003,     0,     0,     0,     0,     0,   267,    27,
       0,   268,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   614,   713,   616,   617,   618,   619,
       0,     0,     0,     0,   620,     0,   774,     0,   775,     0,
       0,     0,   520,   520,  1783,  2033,     0,     0,     0,     0,
       0,     0,     0,  1438,     0,  1440,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   520,   602,   603,
     604,   605,   606,   607,   608,   609,   610,   611,   612,   613,
     614,   713,   616,   617,   618,   619,     0,     0,     0,     0,
     620,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2074,  2075,     0,     0,
       0,  2086,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   282,     0,
    2096,     0,   283,     0,     0,     0,     0,     0,   285,   286,
     287,     0,   288,   289,   290,     0,     0,     0,   123,     0,
    2109,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1505,     0,   291,   394,     0,     0,     0,
       0,     0,   293,     0,     0,     0,     0,   369,     0,     0,
       0,     0,     0,     0,   296,     0,   520,   520,     0,     0,
     219,   175,     0,     0,     0,     0,     0,   220,   221,   222,
       0,     0,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     393,   242,   243,   244,   245,   246,   247,   248,   249,  2087,
     520,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   255,   256,   257,   258,
       0,     0,     0,     0,   259,     0,     0,     0,  2172,     0,
       0,     0,     0,     0,     0,  2156,     0,     0,     0,     0,
     264,   265,   266,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   267,    27,     0,   268,     0,     0,     0,
       0,   520,   520,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1614,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   520,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   612,   613,   614,   713,
     616,   617,   618,   619,     0,   520,     0,     0,   620,     0,
       0,     0,     0,     0,   847,     0,  1653,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   614,
     713,   616,   617,   618,   619,     0,     0,     0,     0,   620,
       0,     0,     0,     0,     0,     0,     0,     0,  1690,  1691,
    1692,  1693,  1694,  1695,  1696,     0,     0,     0,     0,  1701,
    1702,     0,     0,     0,     0,     0,  1704,     0,     0,     0,
       0,     0,     0,   282,  1711,     0,     0,   283,  1715,     0,
       0,  1717,     0,   285,   286,   287,     0,   288,   289,   290,
       0,     0,  1724,   123,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     291,   394,     0,   520,     0,     0,     0,   293,     0,     0,
       0,     0,   369,     0,     0,     0,   644,     0,     0,   296,
       0,     0,     0,     0,     0,   602,   603,   604,   605,   606,
     607,   608,   609,   610,   611,   612,   613,   614,   713,   616,
     617,   618,   619,     0,     0,     0,     0,   620,     0,     0,
       0,     0,  1781,     0,  1784,     0,     0,     0,  1791,     0,
    1793,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   612,   613,   614,   713,   616,   617,   618,   619,     0,
       0,     0,     0,   620,     0,     0,     0,     0,     0,     0,
       0,  1816,   219,     6,   399,     0,     0,     0,     0,   220,
     221,   222,     0,     0,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,  2195,     0,     0,  1654,
     401,   402,   403,   404,   405,   406,   407,   408,   255,   256,
     257,   258,   409,   410,   411,   412,   259,   260,     0,     0,
     413,   414,   415,   416,     0,     0,   261,   262,   263,   417,
       0,   418,   264,   265,   266,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   267,    27,   419,   268,     0,
     420,     0,     0,     0,   269,     0,  1880,   270,     0,     0,
     271,     0,   272,     0,     0,     0,     0,     0,     0,    44,
       0,     0,     0,   273,   274,   275,     0,     0,   276,     0,
       0,     0,     0,     0,     0,     0,     0,   277,     0,    59,
      60,     0,   278,     0,   279,     0,     0,   280,     0,     0,
       0,     0,     0,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,     0,     0,     0,    85,     0,
       0,     0,    89,     0,     0,     0,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   612,   613,   614,   713,
     616,   617,   618,   619,     0,     0,     0,   281,   620,     0,
    1015,     0,     0,  1957,     0,     0,  1958,     0,   984,     0,
       0,     0,     0,     0,     0,   282,   421,   422,   423,   283,
     284,     0,     0,     0,     0,   285,   286,   287,   424,   288,
     289,   290,   425,     0,   426,   123,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   291,   292,  1991,  1992,  1983,   601,     0,   293,
       0,  1998,     0,     0,   369,     0,     0,     0,  1655,     0,
       0,   296,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   614,   713,   616,   617,   618,   619,
       0,     0,     0,     0,   620,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2038,  2039,     0,
     219,     6,   399,     0,     0,     0,     0,   220,   221,   222,
       0,     0,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,     0,     0,  2070,   400,   401,   402,
     403,   404,   405,   406,   407,   408,   255,   256,   257,   258,
     409,   410,   411,   412,   259,   260,     0,     0,   413,   414,
     415,   416,     0,     0,   261,   262,   263,   417,     0,   418,
     264,   265,   266,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   267,    27,   419,   268,     0,   420,     0,
       0,     0,   269,     0,     0,   270,     0,     0,   271,     0,
     272,     0,     0,     0,     0,     0,     0,    44,     0,     0,
       0,   273,   274,   275,     0,     0,   276,     0,     0,     0,
       0,     0,     0,     0,     0,   277,     0,    59,    60,     0,
     278,     0,   279,     0,     0,   280,     0,     0,     0,     0,
       0,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,     0,     0,     0,    85,     0,     0,     0,
      89,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   612,   613,   614,   850,   616,   617,   618,   619,  2129,
       0,     0,     0,   620,     0,   281,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   282,   421,   422,   423,   283,   284,   601,
       0,     0,     0,   285,   286,   287,   424,   288,   289,   290,
     425,     0,   426,   123,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     291,   292,     0,     0,     0,     0,     0,   293,     0,     0,
       0,     0,   369,     0,     0,     0,   295,     0,     0,   296,
       0,  2215,   219,   175,   399,     0,   448,     0,     0,   220,
     221,   222,     0,     0,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   393,   242,   243,   244,   245,   246,   247,   248,
     249,     0,     0,     0,     0,     0,     0,     0,     0,   400,
     401,   402,   403,   404,   405,   406,   407,   408,   255,   256,
     257,   258,   409,   410,   411,   412,   259,     0,     0,     0,
     413,   414,   415,   416,     0,     0,     0,     0,     0,   417,
       0,   418,   264,   265,   266,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   267,    27,   419,   268,     0,
     420,     0,     0,     0,   181,     0,     0,   182,     0,     0,
     183,     0,   184,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    48,   602,   603,   604,   605,   606,   607,
     608,   609,   610,   611,   612,   613,   614,   713,   616,   617,
     618,   619,     0,     0,   449,     0,   620,     0,     0,     0,
       0,     0,  1107,     0,   602,   603,   604,   605,   606,   607,
     608,   609,   610,   611,   612,   613,   614,   713,   616,   617,
     618,   619,     0,     0,     0,     0,   620,     0,     0,     0,
       0,     0,     0,   602,   603,   604,   605,   606,   607,   608,
     609,   610,   611,   612,   613,   614,   615,   616,   617,   618,
     619,     0,     0,     0,   601,   620,     0,     0,   450,     0,
       0,     0,     0,     0,     0,   282,   421,   422,   423,   283,
       0,     0,     0,     0,     0,   285,   286,   287,   424,   288,
     289,   290,   425,     0,   426,   123,     0,   451,   452,   453,
     454,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   291,   394,     0,     0,     0,     0,     0,   293,
       0,   455,   456,     0,   457,     0,   458,   219,     6,   368,
     459,   296,     0,     0,   220,   221,   222,     0,     0,   223,
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
     614,   850,   616,   617,   618,   619,     0,     0,     0,     0,
     620,     0,   281,     0,     0,     0,     0,  1031,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     282,     0,     0,     0,   283,   284,     0,     0,     0,     0,
     285,   286,   287,     0,   288,   289,   290,     0,     0,     0,
     123,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   291,   292,     0,
       0,     0,     0,     0,   293,     0,     0,     0,     0,   369,
     219,     6,     0,   370,     0,   690,   296,   220,   221,   222,
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
    1238,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   282,     0,     0,     0,   283,   284,     0,
       0,     0,     0,   285,   286,   287,     0,   288,   289,   290,
       0,     0,     0,   123,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     291,   518,     0,     0,     0,     0,     0,   293,     0,     0,
       0,     0,   369,   219,     6,     0,     0,   594,     0,   296,
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
      59,    60,     0,   278,     0,   279,     0,     0,   280,     0,
       0,     0,     0,     0,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,     0,     0,     0,    85,
       0,     0,     0,    89,   602,   603,   604,   605,   606,   607,
     608,   609,   610,   611,   612,   613,   614,   713,   616,   617,
     618,   619,     0,     0,     0,     0,   620,     0,   281,     0,
       0,     0,     0,  1239,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   282,     0,     0,     0,
     283,   284,     0,     0,     0,     0,   285,   286,   287,     0,
     288,   289,   290,     0,     0,     0,   123,     0,     0,     0,
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
       0,     0,     0,     0,     0,     0,     0,     0,     0,   267,
      27,     0,   268,     0,     0,     0,     0,     0,   269,     0,
       0,   270,     0,     0,   271,     0,   272,     0,     0,     0,
       0,     0,     0,    44,     0,     0,     0,   273,   274,   275,
       0,     0,   276,     0,     0,     0,     0,     0,     0,     0,
       0,   277,     0,    59,    60,     0,   278,     0,   279,     0,
       0,   280,     0,     0,     0,     0,     0,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,     0,
       0,     0,    85,     0,     0,     0,    89,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   614,
     713,   616,   617,   618,   619,     0,     0,     0,     0,   620,
       0,   281,     0,     0,     0,     0,  1570,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   282,
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
     602,   603,   604,   605,   606,   607,   608,   609,   610,   611,
     612,   613,   614,   713,   616,   617,   618,   619,     0,     0,
       0,     0,   620,     0,   281,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
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
      60,   399,   278,     0,   279,     0,     0,   280,     0,     0,
       0,     0,     0,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,     0,     0,     0,    85,     0,
       0,     0,    89,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   400,   401,   402,   403,
     404,   405,   406,   407,   408,     0,     0,   281,     0,   409,
     410,   411,   412,     0,     0,     0,     0,   413,   414,   415,
     416,     0,     0,     0,     0,   282,   417,     0,   418,   283,
     284,     0,     0,     0,     0,   285,   286,   287,     0,   288,
     289,   290,     0,     0,   419,   123,     0,   420,     0,     0,
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
       0,     0,     0,   421,   422,   423,     0,     0,   267,    27,
       0,   268,     0,     0,     0,   424,     0,   269,     0,   425,
     270,   426,     0,   271,     0,   272,     0,     0,     0,     0,
       0,     0,    44,     0,     0,     0,   273,   274,   275,     0,
       0,   276,     0,     0,     0,     0,     0,     0,     0,     0,
     277,     0,    59,    60,     0,   278,     0,   279,     0,     0,
     280,     0,     0,     0,     0,     0,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,     0,     0,
       0,    85,     0,     0,     0,    89,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   612,   613,   614,   713,
     616,   617,   618,   619,     0,     0,     0,     0,   620,     0,
     281,     0,     0,     0,  1845,     0,     0,     0,  1846,     0,
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
      81,     0,     0,     0,    85,     0,     0,     0,    89,   602,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   612,
     613,   614,   713,   616,   617,   618,   619,     0,     0,     0,
       0,   620,     0,   281,     0,     0,     0,  1900,     0,     0,
       0,  1901,     0,     0,     0,     0,     0,     0,     0,     0,
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
    1920,     0,     0,     0,  1921,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   282,     0,     0,     0,   283,   284,
       0,     0,     0,     0,   285,   286,   287,     0,   288,   289,
     290,     0,     0,     0,   123,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   291,   518,     0,     0,     0,     0,     0,   293,     0,
       0,     0,     0,   369,   219,     6,     0,   943,     0,  1414,
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
       0,     0,     0,  2098,     0,     0,     0,  2099,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   282,     0,     0,
       0,   283,   284,     0,     0,     0,     0,   285,   286,   287,
       0,   288,   289,   290,     0,     0,     0,   123,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   291,   518,     0,     0,     0,     0,
       0,   293,   219,     6,     0,     0,   369,  1631,     0,   220,
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
       0,     0,     0,     0,     0,   807,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   282,     0,     0,     0,   283,
     284,     0,     0,     0,     0,   285,   286,   287,     0,   288,
     289,   290,     0,     0,     0,   123,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   291,   518,     0,     0,     0,     0,     0,   293,
     219,     6,     0,     0,   369,     0,     0,   220,   221,   222,
       0,   296,   223,   224,   225,   226,   227,   228,   229,   230,
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
       0,     0,     0,   813,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   282,     0,     0,     0,   283,   284,     0,
       0,     0,     0,   285,   286,   287,     0,   288,   289,   290,
       0,     0,     0,   123,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     291,   518,     0,     0,     0,     0,     0,   293,     0,     0,
       0,     0,   369,   219,     6,     0,     0,  2032,     0,   296,
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
      59,    60,     0,   278,     0,   279,     0,     0,   280,     0,
       0,     0,     0,     0,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,     0,     0,     0,    85,
       0,     0,     0,    89,   602,   603,   604,   605,   606,   607,
     608,   609,   610,   611,   612,   613,   614,   713,   616,   617,
     618,   619,     0,     0,     0,     0,   620,     0,   281,     0,
       0,     0,     0,     0,     0,     0,   815,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   282,     0,     0,     0,
     283,   284,     0,     0,     0,     0,   285,   286,   287,     0,
     288,   289,   290,     0,     0,     0,   123,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   291,   518,     0,     0,     0,     0,     0,
     293,   219,   175,   399,     0,   369,     0,     0,   220,   221,
     222,     0,   296,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   393,   242,   243,   244,   245,   246,   247,   248,   249,
       0,     0,     0,     0,     0,     0,     0,     0,   400,   401,
     402,   403,   404,   405,   406,   407,   408,   255,   256,   257,
     258,   409,   410,   411,   412,   259,     0,     0,     0,   413,
     414,   415,   416,     0,     0,     0,     0,     0,   417,     0,
     418,   264,   265,   266,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   267,    27,   419,   268,     0,   420,
     219,   175,   399,     0,     0,     0,     0,   220,   221,   222,
       0,     0,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     393,   242,   243,   244,   245,   246,   247,   248,   249,     0,
       0,     0,     0,     0,     0,     0,     0,   400,   401,   402,
     403,   404,   405,   406,   407,   408,   255,   256,   257,   258,
     409,   410,   411,   412,   259,     0,     0,     0,   413,   414,
     415,   416,     0,     0,     0,     0,     0,   417,     0,   418,
     264,   265,   266,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   267,    27,   419,   268,     0,   420,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   282,   421,   422,   423,   283,     0,
       0,     0,     0,     0,   285,   286,   287,   424,   288,   289,
     290,   425,     0,   426,   123,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   291,   394,     0,     0,     0,     0,     0,   293,     0,
       0,     0,     0,   369,     0,     0,     0,  1650,     0,     0,
     296,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   612,   613,   614,   713,   616,   617,   618,   619,     0,
       0,     0,     0,   620,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   984,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   282,   421,   422,   423,   283,     0,     0,
       0,     0,     0,   285,   286,   287,   424,   288,   289,   290,
     425,     0,   426,   123,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     291,  1925,     0,     0,     0,     0,     0,   293,     0,     0,
       0,     0,   369,   219,   175,   399,  1926,     0,     0,   296,
     220,   221,   222,     0,     0,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   393,   242,   243,   244,   245,   246,   247,
     248,   249,     0,     0,     0,     0,     0,     0,     0,     0,
    1654,   401,   402,   403,   404,   405,   406,   407,   408,   255,
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
     293,     0,     0,     0,     0,   369,     0,     0,     0,  1815,
       0,     0,   296,   602,   603,   604,   605,   606,   607,   608,
     609,   610,   611,   612,   613,   614,   713,   616,   617,   618,
     619,     0,     0,     0,     0,   620,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   985,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   282,   421,   422,   423,   283,
       0,     0,     0,     0,     0,   285,   286,   287,   424,   288,
     289,   290,   425,     0,   426,   123,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   291,   394,     0,     0,     0,     0,     0,   293,
     219,   175,     0,     0,   369,     0,     0,   220,   221,   222,
       0,   296,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     393,   242,   243,   244,   245,   246,   247,   248,   249,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   255,   256,   257,   258,
       0,     0,     0,     0,   259,     7,     8,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     264,   265,   266,     0,     0,     0,     0,     0,     0,     0,
     219,   175,     0,   267,    27,   905,   268,   220,   221,   222,
       0,     0,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     393,   242,   243,   244,   245,   246,   247,   248,   249,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   255,   256,   257,   258,
       0,     0,     0,     0,   259,     0,     0,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
     264,   265,   266,    45,    46,    47,    48,     0,     0,     0,
       0,    50,     0,   267,    27,     0,   268,     0,     0,     0,
     788,    58,     0,     0,    61,   789,     0,   790,   791,     0,
     792,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   282,     0,     0,     0,   283,    82,     0,
       0,     0,     0,   285,   286,   287,     0,   288,   289,   290,
       0,     0,     0,   123,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    99,   100,   101,     0,     0,
     662,   663,     0,     0,     0,     0,     0,   293,     0,     0,
       0,     0,   664,     0,     0,     0,   339,     0,     0,   296,
     602,   603,   604,   605,   606,   607,   608,   609,   610,   611,
     612,   613,   614,   713,   616,   617,   618,   619,     0,     0,
       0,     0,   620,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1028,   282,     0,     0,     0,   283,     0,     0,
       0,     0,     0,   285,   286,   287,     0,   288,   289,   290,
       0,     0,   814,   123,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     291,   394,     0,     0,     0,     0,     0,   293,   219,   175,
       0,     0,   369,     0,     0,   220,   221,   222,     0,   296,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   393,   242,
     243,   244,   245,   246,   247,   248,   249,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   255,   256,   257,   258,     0,     0,
       0,     0,   259,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   264,   265,
     266,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   267,    27,     0,   268,   219,   175,     0,  1365,     0,
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
       0,   285,   286,   287,  1138,   288,   289,   290,     0,     0,
       0,   123,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   291,   394,
       0,     0,     0,     0,     0,   293,     0,     0,     0,     0,
     369,  1126,     0,     0,     0,     0,     0,   296,   602,   603,
     604,   605,   606,   607,   608,   609,   610,   611,   612,   613,
     614,   713,   616,   617,   618,   619,     0,     0,     0,     0,
     620,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1178,     0,     0,     0,     0,     0,     0,     0,   282,     0,
       0,     0,   283,     0,     0,     0,     0,     0,   285,   286,
     287,     0,   288,   289,   290,     0,     0,     0,   123,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   291,   394,     0,     0,     0,
       0,     0,   293,   219,   175,     0,  1535,   369,     0,     0,
     220,   221,   222,     0,   296,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   393,   242,   243,   244,   245,   246,   247,
     248,   249,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   255,
     256,   257,   258,     0,     0,     0,     0,   259,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   264,   265,   266,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   267,    27,     0,   268,
     219,   175,     0,  1593,     0,     0,     0,   220,   221,   222,
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
     283,     0,     0,     0,     0,     0,   285,   286,   287,  1188,
     288,   289,   290,     0,     0,     0,   123,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   291,   394,     0,     0,     0,     0,     0,
     293,     0,   219,   175,     0,   369,     0,     0,     0,   220,
     221,   222,   296,     0,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   393,   242,   243,   244,   245,   246,   247,   248,
     249,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   282,     0,     0,     0,   283,   255,   256,
     257,   258,     0,   285,   286,   287,   259,   288,   289,   290,
       0,     0,     0,   123,     0,     0,     0,     0,     0,     0,
       0,     0,   264,   265,   266,     0,     0,     0,     0,     0,
     291,   394,     0,     0,     0,   267,    27,   293,   268,   219,
     175,     0,   369,     0,     0,     0,   220,   221,   222,   296,
       0,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   393,
     242,   243,   244,   245,   246,   247,   248,   249,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   255,   256,   257,   258,     0,
       0,     0,     0,   259,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   264,
     265,   266,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   267,    27,     0,   268,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   612,   613,   614,   713,
     616,   617,   618,   619,     0,   282,     0,     0,   620,   283,
       0,     0,     0,     0,     0,   285,   286,   287,  1189,   288,
     289,   290,     0,     0,     0,   123,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   291,   394,     0,     0,     0,     0,     0,   293,
       0,   219,   175,     0,   369,  1647,     0,     0,   220,   221,
     222,   296,     0,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   393,   242,   243,   244,   245,   246,   247,   248,   249,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   282,     0,     0,     0,   283,   255,   256,   257,
     258,     0,   285,   286,   287,   259,   288,   289,   290,     0,
       0,     0,   123,     0,     0,     0,     0,     0,     0,     0,
       0,   264,   265,   266,     0,     0,     0,     0,     0,   291,
     394,     0,     0,     0,   267,    27,   293,   268,   219,   175,
       0,   369,  1974,     0,     0,   220,   221,   222,   296,     0,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   393,   242,
     243,   244,   245,   246,   247,   248,   249,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   255,   256,   257,   258,     0,     0,
       0,     0,   259,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   264,   265,
     266,     0,     0,     0,     7,     8,     0,     0,     0,     0,
       0,   267,    27,     0,   268,   602,   603,   604,   605,   606,
     607,   608,   609,   610,   611,   612,   613,   614,   713,   616,
     617,   618,   619,     0,   282,     0,     0,   620,   283,     0,
       0,     0,     0,     0,   285,   286,   287,  1190,   288,   289,
     290,     0,     0,     0,   123,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   291,   394,     0,     0,     0,     0,     0,   293,     0,
       0,     0,     0,   369,     0,     0,     0,  2031,     0,     0,
     296,     0,     0,     0,     0,     0,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,     7,
       8,     0,    45,    46,    47,    48,     0,     0,     0,     0,
      50,     0,     0,     0,     0,     0,     0,     0,     0,   788,
      58,   282,     0,    61,   789,   283,   790,   791,     0,   792,
       0,   285,   286,   287,     0,   288,   289,   290,     0,     0,
       0,   123,     0,     0,     0,     0,     0,    82,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   291,   394,
       0,     7,     8,     0,     0,   293,     0,     0,     0,     0,
     369,     0,     0,     0,    99,   100,   101,   296,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,     0,     0,     0,    45,    46,    47,
      48,     0,     0,     0,     0,    50,     0,     0,     0,     0,
       0,     0,     0,     0,   788,    58,     0,     0,    61,   789,
       0,   790,   791,     0,   792,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   992,    82,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,     7,     8,     0,    45,
      46,    47,    48,     0,     0,     0,     0,    50,     0,    99,
     100,   101,     0,     0,     0,     0,   788,    58,     0,     0,
      61,   789,     0,   790,   791,     0,   792,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    82,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     7,     8,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    99,   100,   101,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1009,     0,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,     0,     0,     0,    45,    46,    47,    48,     0,     0,
       0,     0,    50,     0,     0,     0,     0,     0,     0,     0,
       0,   788,    58,     0,     0,    61,   789,     0,   790,   791,
       0,   792,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1064,    82,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,     7,     8,     0,    45,    46,    47,    48,
       0,     0,     0,     0,    50,     0,    99,   100,   101,     0,
       0,     0,     0,   788,    58,     0,     0,    61,   789,     0,
     790,   791,     0,   792,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    82,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     7,     8,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    99,   100,
     101,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1066,     0,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,     0,     0,
       0,    45,    46,    47,    48,     0,     0,     0,     0,    50,
       0,     0,     0,     0,     0,     0,     0,     0,   788,    58,
       0,     0,    61,   789,     0,   790,   791,     0,   792,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1272,    82,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
       7,     8,     0,    45,    46,    47,    48,     0,     0,     0,
       0,    50,     0,    99,   100,   101,     0,     0,     0,     0,
     788,    58,     0,     0,    61,   789,     0,   790,   791,     0,
     792,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    82,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     7,     8,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    99,   100,   101,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1274,     0,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,     0,     0,     0,    45,    46,
      47,    48,     0,     0,     0,     0,    50,     0,     0,     0,
       0,     0,     0,     0,     0,   788,    58,     0,     0,    61,
     789,     0,   790,   791,     0,   792,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1275,    82,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,     7,     8,     0,
      45,    46,    47,    48,     0,     0,     0,     0,    50,     0,
      99,   100,   101,     0,     0,     0,     0,   788,    58,     0,
       0,    61,   789,     0,   790,   791,     0,   792,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    82,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     7,
       8,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    99,   100,   101,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1294,     0,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,     0,     0,     0,    45,    46,    47,    48,     0,
       0,     0,     0,    50,     0,     0,     0,     0,     0,     0,
       0,     0,   788,    58,     0,     0,    61,   789,     0,   790,
     791,     0,   792,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1305,
      82,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,     7,     8,     0,    45,    46,    47,
      48,     0,     0,     0,     0,    50,     0,    99,   100,   101,
       0,     0,     0,     0,   788,    58,     0,     0,    61,   789,
       0,   790,   791,     0,   792,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    82,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     7,     8,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    99,
     100,   101,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1323,     0,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,     0,
       0,     0,    45,    46,    47,    48,     0,     0,     0,     0,
      50,     0,     0,     0,     0,     0,     0,     0,     0,   788,
      58,     0,     0,    61,   789,     0,   790,   791,     0,   792,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1360,    82,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,     7,     8,     0,    45,    46,    47,    48,     0,     0,
       0,     0,    50,     0,    99,   100,   101,     0,     0,     0,
       0,   788,    58,     0,     0,    61,   789,     0,   790,   791,
       0,   792,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    82,
     602,   603,   604,   605,   606,   607,   608,   609,   610,   611,
     612,   613,   614,   713,   616,   617,   618,   619,     0,     0,
       0,     0,   620,     0,     0,     0,    99,   100,   101,     0,
       0,     0,  1191,     0,     0,     0,     0,     0,     0,     0,
       0,  1527,     0,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,     0,     0,     0,    45,
      46,    47,    48,     0,     0,     0,     0,    50,     0,     0,
       0,     0,     0,     0,     0,     0,   788,    58,    -4,     1,
      61,   789,    -4,   790,   791,     0,   792,     0,     0,     0,
       0,    -4,    -4,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2153,    82,     0,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   612,   613,   614,   713,
     616,   617,   618,   619,     0,    -4,    -4,    -4,   620,     0,
       0,    99,   100,   101,     0,     0,     0,     0,  1192,     0,
       0,     0,     0,     0,     0,     0,    -4,    -4,    -4,     0,
       0,     0,     0,    -4,    -4,     0,     0,     0,     0,    -4,
       0,     0,     0,     0,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,     0,    -4,    -4,     0,    -4,     0,     0,     0,     0,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,     0,     0,    -4,    -4,
      -4,    -4,    -4,     0,     0,    -4,     0,    -4,  2197,    -4,
      -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,     0,     0,    -4,    -4,
      -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,     0,     0,     0,    -4,
      -4,    -4,     0,     0,     0,    -4,     0,     0,     0,     0,
      -4,    -4,    -4,    -4,     0,     0,    -4,     0,    -4,     0,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,     0,     6,     0,     0,     0,     0,
      -4,    -4,    -4,    -4,     7,     8,     0,     0,     0,     0,
       0,     0,    -4,     0,    -4,    -4,     0,     0,     0,   602,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   612,
     613,   614,   713,   616,   617,   618,   619,     0,     9,    10,
      11,   620,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1197,     0,     0,     0,     0,     0,     0,     0,    12,
      13,    14,     0,     0,     0,     0,    15,    16,     0,     0,
       0,     0,    17,     0,     0,     0,     0,    18,    19,    20,
      21,    22,    23,    24,     0,    25,    26,     0,    27,     0,
       0,     0,     0,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,     0,
       0,    44,    45,    46,    47,    48,     0,     0,    49,     0,
      50,     0,    51,    52,     0,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,     0,
       0,    67,    68,    69,     0,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,     0,
       0,     0,    94,    95,    96,     0,     0,     0,    97,     0,
       0,     0,     0,    98,    99,   100,   101,   175,   399,   102,
       0,   103,     0,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,     0,     0,     0,
       0,     0,     0,   118,   119,   120,   121,     0,     0,     0,
       0,     0,     0,     0,     0,   122,     0,   123,   124,     0,
       0,     0,     0,   400,   401,   402,   403,   404,   405,   406,
     407,   408,     0,     0,     0,     0,   409,   410,   411,   412,
       0,   175,   399,     0,   413,   414,   415,   416,     0,     0,
       0,     0,     0,   417,     0,   418,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   419,     0,     0,   420,     0,     0,     0,   181,     0,
       0,   182,     0,     0,   183,     0,   184,   400,   401,   402,
     403,   404,   405,   406,   407,   408,     0,    48,     0,     0,
     409,   410,   411,   412,   430,   399,     0,     0,   413,   414,
     415,   416,     0,     0,     0,     0,     0,   417,   449,   418,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     7,     8,     0,   419,     0,     0,   420,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     400,   401,   402,   403,   404,   405,   406,   407,   408,     0,
       0,     0,     0,   409,   410,   411,   412,     0,     0,     0,
       0,   413,   414,   415,   416,     0,     0,     0,     0,     0,
     417,     0,   418,     0,     0,     0,     0,     0,     0,     0,
     421,   422,   423,     0,     0,     0,     0,     0,   419,     0,
       0,   420,   424,     0,     0,     0,   425,     0,   426,   123,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,     0,     0,     0,
      45,    46,    47,    48,     7,     8,     0,     0,    50,     0,
       0,     0,     0,     0,   421,   422,   423,   788,    58,     0,
       0,    61,   789,     0,   790,   791,   424,   792,     0,     0,
     425,  1072,   426,   123,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    82,     0,     0,     0,  1073,
       0,     0,     0,   602,   603,   604,   605,   606,   607,   608,
     609,   610,   611,   612,   613,   614,   713,   616,   617,   618,
     619,     0,    99,   100,   101,   620,     0,   421,   422,   423,
       0,     0,     0,     0,     0,  1198,     0,     0,     0,   424,
       0,     0,     0,   425,     0,   426,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,     0,
       0,     0,    45,    46,    47,    48,     0,     0,     0,     0,
      50,     0,     0,     0,     0,     0,     0,     0,     0,   788,
      58,     0,     0,    61,   789,     0,   790,   791,     0,   792,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    82,   602,   603,
     604,   605,   606,   607,   608,   609,   610,   611,   612,   613,
     614,   713,   616,   617,   618,   619,     0,     0,     0,     0,
     620,     0,     0,     0,    99,   100,   101,     0,     0,     0,
    1200,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   612,   613,   614,   713,   616,   617,   618,   619,     0,
       0,     0,     0,   620,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1315,   602,   603,   604,   605,   606,   607,
     608,   609,   610,   611,   612,   613,   614,   713,   616,   617,
     618,   619,     0,     0,     0,     0,   620,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1341,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   614,
     713,   616,   617,   618,   619,     0,     0,     0,     0,   620,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1424,
     602,   603,   604,   605,   606,   607,   608,   609,   610,   611,
     612,   613,   614,   713,   616,   617,   618,   619,     0,     0,
       0,     0,   620,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1428,   602,   603,   604,   605,   606,   607,   608,
     609,   610,   611,   612,   613,   614,   713,   616,   617,   618,
     619,     0,     0,     0,     0,   620,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1529,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   612,   613,   614,   713,
     616,   617,   618,   619,     0,     0,     0,     0,   620,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1530,   602,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   612,
     613,   614,   713,   616,   617,   618,   619,     0,     0,     0,
       0,   620,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1569,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   614,   713,   616,   617,   618,   619,
       0,     0,     0,     0,   620,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1697,   602,   603,   604,   605,   606,
     607,   608,   609,   610,   611,   612,   613,   614,   713,   616,
     617,   618,   619,     0,     0,     0,     0,   620,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1698,   602,   603,
     604,   605,   606,   607,   608,   609,   610,   611,   612,   613,
     614,   713,   616,   617,   618,   619,     0,     0,     0,     0,
     620,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1699,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   612,   613,   614,   713,   616,   617,   618,   619,     0,
       0,     0,     0,   620,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1843,   602,   603,   604,   605,   606,   607,
     608,   609,   610,   611,   612,   613,   614,   713,   616,   617,
     618,   619,     0,     0,     0,     0,   620,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1961,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   614,
     713,   616,   617,   618,   619,     0,     0,     0,     0,   620,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1962,
     602,   603,   604,   605,   606,   607,   608,   609,   610,   611,
     612,   613,   614,   713,   616,   617,   618,   619,     0,     0,
       0,     0,   620,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1993,   602,   603,   604,   605,   606,   607,   608,
     609,   610,   611,   612,   613,   614,   713,   616,   617,   618,
     619,     0,     0,     0,     0,   620,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2065,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   612,   613,   614,   713,
     616,   617,   618,   619,     0,     0,     0,     0,   620,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2079,   602,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   612,
     613,   614,   713,   616,   617,   618,   619,     0,     0,     0,
       0,   620,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2081,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   614,   713,   616,   617,   618,   619,
       0,     0,     0,     0,   620,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2119,   602,   603,   604,   605,   606,
     607,   608,   609,   610,   611,   612,   613,   614,   713,   616,
     617,   618,   619,     0,     0,     0,     0,   620,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2120,   602,   603,
     604,   605,   606,   607,   608,   609,   610,   611,   612,   613,
     614,   713,   616,   617,   618,   619,     0,     0,     0,     0,
     620,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2134,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   612,   613,   614,   713,   616,   617,   618,   619,     0,
       0,     0,     0,   620,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2165,   602,   603,   604,   605,   606,   607,
     608,   609,   610,   611,   612,   613,   614,   713,   616,   617,
     618,   619,     0,     0,     0,     0,   620,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2186,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   614,
     713,   616,   617,   618,   619,     0,     0,     0,     0,   620,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2191,
     602,   603,   604,   605,   606,   607,   608,   609,   610,   611,
     612,   613,   614,   713,   616,   617,   618,   619,     0,     0,
       0,     0,   620,     0,     0,     0,     0,     0,  1164,   602,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   612,
     613,   614,   713,   616,   617,   618,   619,     0,     0,     0,
       0,   620,     0,     0,     0,     0,     0,  1213,   602,   603,
     604,   605,   606,   607,   608,   609,   610,   611,   612,   613,
     614,   713,   616,   617,   618,   619,     0,     0,     0,     0,
     620,     0,     0,     0,     0,     0,  1214,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   614,
     713,   616,   617,   618,   619,     0,     0,     0,     0,   620,
       0,     0,     0,     0,     0,  1264,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   612,   613,   614,   713,
     616,   617,   618,   619,     0,     0,     0,     0,   620,     0,
       0,     0,     0,     0,  1303,   602,   603,   604,   605,   606,
     607,   608,   609,   610,   611,   612,   613,   614,   713,   616,
     617,   618,   619,     0,     0,     0,     0,   620,     0,     0,
       0,     0,     0,  1310,   602,   603,   604,   605,   606,   607,
     608,   609,   610,   611,   612,   613,   614,   713,   616,   617,
     618,   619,     0,     0,     0,     0,   620,     0,     0,     0,
       0,     0,  1371,   602,   603,   604,   605,   606,   607,   608,
     609,   610,   611,   612,   613,   614,   713,   616,   617,   618,
     619,     0,     0,     0,     0,   620,     0,     0,     0,     0,
       0,  1391,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   614,   713,   616,   617,   618,   619,
       0,     0,     0,     0,   620,     0,     0,     0,     0,     0,
    1427,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   612,   613,   614,   713,   616,   617,   618,   619,     0,
       0,     0,     0,   620,     0,     0,     0,     0,     0,  1476,
     602,   603,   604,   605,   606,   607,   608,   609,   610,   611,
     612,   613,   614,   713,   616,   617,   618,   619,     0,     0,
       0,     0,   620,     0,     0,     0,     0,     0,  1477,   602,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   612,
     613,   614,   713,   616,   617,   618,   619,     0,     0,     0,
       0,   620,     0,     0,     0,     0,     0,  1478,   602,   603,
     604,   605,   606,   607,   608,   609,   610,   611,   612,   613,
     614,   713,   616,   617,   618,   619,     0,     0,     0,     0,
     620,     0,     0,     0,     0,     0,  1481,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   614,
     713,   616,   617,   618,   619,     0,     0,     0,     0,   620,
       0,     0,     0,     0,     0,  1482,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   612,   613,   614,   713,
     616,   617,   618,   619,     0,     0,     0,     0,   620,     0,
       0,     0,     0,     0,  1483,   602,   603,   604,   605,   606,
     607,   608,   609,   610,   611,   612,   613,   614,   713,   616,
     617,   618,   619,     0,     0,     0,     0,   620,     0,     0,
       0,     0,     0,  1485,   602,   603,   604,   605,   606,   607,
     608,   609,   610,   611,   612,   613,   614,   713,   616,   617,
     618,   619,     0,     0,     0,     0,   620,     0,     0,     0,
       0,     0,  1486,   602,   603,   604,   605,   606,   607,   608,
     609,   610,   611,   612,   613,   614,   713,   616,   617,   618,
     619,     0,     0,     0,     0,   620,     0,     0,     0,     0,
       0,  1531,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   614,   713,   616,   617,   618,   619,
       0,     0,     0,     0,   620,     0,     0,     0,     0,     0,
    1599,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   612,   613,   614,   713,   616,   617,   618,   619,     0,
       0,     0,     0,   620,     0,     0,     0,     0,     0,  1708,
     602,   603,   604,   605,   606,   607,   608,   609,   610,   611,
     612,   613,   614,   713,   616,   617,   618,   619,     0,     0,
       0,     0,   620,     0,     0,     0,     0,     0,  1898,   602,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   612,
     613,   614,   713,   616,   617,   618,   619,     0,     0,     0,
       0,   620,     0,     0,     0,     0,     0,  1909,   602,   603,
     604,   605,   606,   607,   608,   609,   610,   611,   612,   613,
     614,   713,   616,   617,   618,   619,     0,     0,     0,     0,
     620,     0,     0,     0,     0,     0,  1941,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   614,
     713,   616,   617,   618,   619,     0,     0,     0,     0,   620,
       0,     0,     0,     0,     0,  2018,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   612,   613,   614,   713,
     616,   617,   618,   619,     0,     0,     0,     0,   620,     0,
       0,     0,     0,     0,  2027,   602,   603,   604,   605,   606,
     607,   608,   609,   610,   611,   612,   613,   614,   713,   616,
     617,   618,   619,     0,     0,     0,     0,   620,     0,     0,
       0,     0,     0,  2042,   602,   603,   604,   605,   606,   607,
     608,   609,   610,   611,   612,   613,   614,   713,   616,   617,
     618,   619,     0,     0,     0,     0,   620,     0,     0,     0,
       0,     0,  2066,   602,   603,   604,   605,   606,   607,   608,
     609,   610,   611,   612,   613,   614,   713,   616,   617,   618,
     619,     0,     0,     0,     0,   620,     0,     0,     0,     0,
       0,  2080,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   614,   713,   616,   617,   618,   619,
       0,     0,     0,     0,   620,     0,     0,     0,     0,     0,
    2104,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   612,   613,   614,   713,   616,   617,   618,   619,     0,
       0,     0,     0,   620,     0,     0,     0,     0,     0,  2107,
     602,   603,   604,   605,   606,   607,   608,   609,   610,   611,
     612,   613,   614,   713,   616,   617,   618,   619,     0,     0,
       0,     0,   620,     0,     0,     0,     0,     0,  2108,   602,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   612,
     613,   614,   713,   616,   617,   618,   619,     0,     0,     0,
       0,   620,     0,     0,     0,     0,     0,  2133,   602,   603,
     604,   605,   606,   607,   608,   609,   610,   611,   612,   613,
     614,   713,   616,   617,   618,   619,     0,     0,     0,     0,
     620,     0,     0,     0,     0,     0,  2137,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   614,
     713,   616,   617,   618,   619,     0,     0,     0,     0,   620,
       0,     0,     0,     0,     0,  2170,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   612,   613,   614,   713,
     616,   617,   618,   619,     0,     0,     0,     0,   620,     0,
       0,     0,     0,     0,  2171,   602,   603,   604,   605,   606,
     607,   608,   609,   610,   611,   612,   613,   614,   713,   616,
     617,   618,   619,     0,     0,     0,     0,   620,     0,     0,
       0,     0,     0,  2179,   602,   603,   604,   605,   606,   607,
     608,   609,   610,   611,   612,   613,   614,   713,   616,   617,
     618,   619,     0,     0,     0,     0,   620,     0,     0,     0,
       0,     0,  2204,   602,   603,   604,   605,   606,   607,   608,
     609,   610,   611,   612,   613,   614,   713,   616,   617,   618,
     619,     0,     0,     0,     0,   620,     0,     0,     0,     0,
       0,  2229,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   614,   713,   616,   617,   618,   619,
       0,     0,     0,     0,   620,     0,     0,     0,     0,     0,
    2230,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   612,   613,   614,   713,   616,   617,   618,   619,     0,
       0,     0,     0,   620,     0,     0,     0,     0,   750,   602,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   612,
     613,   614,   713,   616,   617,   618,   619,     0,     0,     0,
       0,   620,     0,     0,     0,     0,   976,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   614,
     713,   616,   617,   618,   619,     0,     0,     0,     0,   620,
       0,     0,     0,     0,  2011,   602,   603,   604,   605,   606,
     607,   608,   609,   610,   611,   612,   613,   614,   713,   616,
     617,   618,   619,     0,     0,     0,     0,   620,     0,   774,
       0,   775,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   614,   713,   616,   617,   618,   619,
       0,     0,     0,     0,   620,     0,     0,     0,  1038,   602,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   612,
     613,   614,   713,   616,   617,   618,   619,     0,     0,     0,
       0,   620,     0,     0,     0,  1083,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   612,   613,   614,   713,
     616,   617,   618,   619,     0,     0,     0,     0,   620,     0,
       0,     0,  1243,   602,   603,   604,   605,   606,   607,   608,
     609,   610,   611,   612,   613,   614,   713,   616,   617,   618,
     619,     0,     0,     0,     0,   620,     0,     0,     0,  1304,
     602,   603,   604,   605,   606,   607,   608,   609,   610,   611,
     612,   613,   614,   713,   616,   617,   618,   619,     0,     0,
       0,     0,   620,     0,     0,     0,  1306,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   614,
     713,   616,   617,   618,   619,     0,     0,     0,     0,   620,
       0,     0,     0,  1313,   602,   603,   604,   605,   606,   607,
     608,   609,   610,   611,   612,   613,   614,   713,   616,   617,
     618,   619,     0,     0,     0,     0,   620,     0,     0,     0,
    1314,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   612,   613,   614,   713,   616,   617,   618,   619,     0,
       0,     0,     0,   620,     0,     0,     0,  1406,   602,   603,
     604,   605,   606,   607,   608,   609,   610,   611,   612,   613,
     614,   713,   616,   617,   618,   619,     0,     0,     0,     0,
     620,     0,     0,     0,  1420,   602,   603,   604,   605,   606,
     607,   608,   609,   610,   611,   612,   613,   614,   713,   616,
     617,   618,   619,     0,     0,     0,     0,   620,     0,     0,
       0,  1628,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   614,   713,   616,   617,   618,   619,
       0,     0,     0,     0,   620,     0,     0,     0,  1723,   602,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   612,
     613,   614,   713,   616,   617,   618,   619,     0,     0,     0,
       0,   620,     0,     0,     0,  1767,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   612,   613,   614,   713,
     616,   617,   618,   619,     0,     0,     0,     0,   620,     0,
       0,     0,  1953,   602,   603,   604,   605,   606,   607,   608,
     609,   610,   611,   612,   613,   614,   713,   616,   617,   618,
     619,     0,     0,     0,     0,   620,     0,     0,     0,  2001,
     602,   603,   604,   605,   606,   607,   608,   609,   610,   611,
     612,   613,   614,   713,   616,   617,   618,   619,     0,     0,
       0,     0,   620,     0,     0,     0,  2019,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   614,
     713,   616,   617,   618,   619,     0,     0,     0,     0,   620,
       0,   828,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   614,   713,   616,   617,   618,   619,
       0,     0,     0,     0,   620,     0,   829,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   614,
     713,   616,   617,   618,   619,     0,     0,     0,     0,   620,
       0,   830,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   614,   713,   616,   617,   618,   619,
       0,     0,     0,     0,   620,     0,   832,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   614,
     713,   616,   617,   618,   619,     0,     0,     0,     0,   620,
       0,   833,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   614,   713,   616,   617,   618,   619,
       0,     0,     0,     0,   620,     0,   834,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   614,
     713,   616,   617,   618,   619,     0,     0,     0,     0,   620,
       0,   836,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   614,   713,   616,   617,   618,   619,
       0,     0,     0,     0,   620,     0,   837,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   614,
     713,   616,   617,   618,   619,     0,     0,     0,     0,   620,
       0,   838,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   614,   713,   616,   617,   618,   619,
       0,     0,     0,     0,   620,     0,   839,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   614,
     713,   616,   617,   618,   619,     0,     0,     0,     0,   620,
       0,   840,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   614,   713,   616,   617,   618,   619,
       0,     0,     0,     0,   620,     0,   841,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   614,
     713,   616,   617,   618,   619,     0,     0,     0,     0,   620,
       0,   842,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   614,   713,   616,   617,   618,   619,
       0,     0,     0,     0,   620,     0,   844,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   614,
     713,   616,   617,   618,   619,     0,     0,     0,     0,   620,
       0,   845,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   614,   713,   616,   617,   618,   619,
       0,     0,     0,     0,   620,     0,   846,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   614,
     713,   616,   617,   618,   619,     0,     0,     0,     0,   620,
       0,   923,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   614,   713,   616,   617,   618,   619,
       0,     0,     0,     0,   620,     0,   957,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   614,
     713,   616,   617,   618,   619,     0,     0,     0,     0,   620,
       0,   998,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   614,   713,   616,   617,   618,   619,
       0,     0,     0,     0,   620,     0,  1015,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   614,
     713,   616,   617,   618,   619,     0,     0,     0,     0,   620,
       0,  1023,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   614,   713,   616,   617,   618,   619,
       0,     0,     0,     0,   620,     0,  1025,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   614,
     713,   616,   617,   618,   619,     0,     0,     0,     0,   620,
       0,  1026,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   614,   713,   616,   617,   618,   619,
       0,     0,     0,     0,   620,     0,  1032,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   614,
     713,   616,   617,   618,   619,     0,     0,     0,     0,   620,
       0,  1033,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   614,   713,   616,   617,   618,   619,
       0,     0,     0,     0,   620,     0,  1071,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   614,
     713,   616,   617,   618,   619,     0,     0,     0,     0,   620,
       0,  1082,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   614,   713,   616,   617,   618,   619,
       0,     0,     0,     0,   620,     0,  1143,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   614,
     713,   616,   617,   618,   619,     0,     0,     0,     0,   620,
       0,  1147,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   614,   713,   616,   617,   618,   619,
       0,     0,     0,     0,   620,     0,  1159,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   614,
     713,   616,   617,   618,   619,     0,     0,     0,     0,   620,
       0,  1242,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   614,   713,   616,   617,   618,   619,
       0,     0,     0,     0,   620,     0,  1252,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   614,
     713,   616,   617,   618,   619,     0,     0,     0,     0,   620,
       0,  1253,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   614,   713,   616,   617,   618,   619,
       0,     0,     0,     0,   620,     0,  1254,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   614,
     713,   616,   617,   618,   619,     0,     0,     0,     0,   620,
       0,  1263,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   614,   713,   616,   617,   618,   619,
       0,     0,     0,     0,   620,     0,  1265,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   614,
     713,   616,   617,   618,   619,     0,     0,     0,     0,   620,
       0,  1266,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   614,   713,   616,   617,   618,   619,
       0,     0,     0,     0,   620,     0,  1302,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   614,
     713,   616,   617,   618,   619,     0,     0,     0,     0,   620,
       0,  1316,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   614,   713,   616,   617,   618,   619,
       0,     0,     0,     0,   620,     0,  1318,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   614,
     713,   616,   617,   618,   619,     0,     0,     0,     0,   620,
       0,  1359,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   614,   713,   616,   617,   618,   619,
       0,     0,     0,     0,   620,     0,  1405,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   614,
     713,   616,   617,   618,   619,     0,     0,     0,     0,   620,
       0,  1419,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   614,   713,   616,   617,   618,   619,
       0,     0,     0,     0,   620,     0,  1629,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   614,
     713,   616,   617,   618,   619,     0,     0,     0,     0,   620,
       0,  1665,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   614,   713,   616,   617,   618,   619,
       0,     0,     0,     0,   620,     0,  1710,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   614,
     713,   616,   617,   618,   619,     0,     0,     0,     0,   620,
       0,  1722,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   614,   713,   616,   617,   618,   619,
       0,     0,     0,     0,   620,     0,  1830,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   614,
     713,   616,   617,   618,   619,     0,     0,     0,     0,   620,
       0,  1832,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   614,   713,   616,   617,   618,   619,
       0,     0,     0,     0,   620,     0,  1835,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   614,
     713,   616,   617,   618,   619,     0,     0,     0,     0,   620,
       0,  1842,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   614,   713,   616,   617,   618,   619,
       0,     0,     0,     0,   620,     0,  1899,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   614,
     713,   616,   617,   618,   619,     0,     0,     0,     0,   620,
       0,  1908,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   614,   713,   616,   617,   618,   619,
       0,     0,     0,     0,   620,     0,  1924,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   614,
     713,   616,   617,   618,   619,     0,     0,     0,     0,   620,
       0,  2000,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   614,   713,   616,   617,   618,   619,
       0,     0,     0,     0,   620,     0,  2063,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   614,
     713,   616,   617,   618,   619,     0,     0,     0,     0,   620,
       0,  2064,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   614,   713,   616,   617,   618,   619,
       0,     0,     0,     0,   620,     0,  2185,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   614,
     713,   616,   617,   618,   619,     0,     0,     0,     0,   620,
       0,  2212,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   614,   713,   616,   617,   618,   619,
       0,     0,     0,     0,   620
};

static const yytype_int16 yycheck[] =
{
       3,   332,  1295,     3,    27,   659,   660,     4,  1291,   167,
    1798,     6,  1800,     6,   163,     6,     5,     5,   111,     6,
       6,   111,     4,     4,    27,   149,   771,    28,   113,    30,
     115,     4,   777,  1490,     5,   149,     5,     7,  1977,     4,
       4,     7,     6,     6,     6,   111,  1787,   170,     6,    97,
     149,    68,   105,     6,    57,   111,     4,   266,    71,    72,
       4,    74,     4,    65,   149,   274,     6,   265,   167,   267,
       9,   124,   138,     4,     4,   198,   274,     9,     4,   178,
     179,   180,   138,    86,   268,   184,   185,   201,   105,    92,
     274,   214,   215,     4,    97,   180,    26,     9,     9,   102,
     149,   186,     6,   266,     4,   268,  2008,    37,    38,  1850,
     113,   274,   108,     4,     6,   111,   112,   113,   167,   253,
     254,     6,   266,     9,   266,   459,    26,   271,   124,   178,
     179,   180,   274,   253,   254,   184,   185,    37,    38,   266,
     274,   105,   253,   254,   253,   254,   149,   274,   149,     0,
     150,   154,   155,   156,   274,   262,   263,  2059,   266,   207,
     163,     6,    14,   274,   271,   274,   274,   268,   216,   253,
     254,   270,   265,   274,     6,   265,     9,   253,   254,   265,
     253,   254,   253,   254,   114,   115,   344,   174,     4,  2128,
     274,   186,     7,   111,   270,   253,   254,   193,   356,   202,
     186,   274,   266,   274,   207,     9,    97,   265,   211,   266,
     274,   269,     7,   216,   217,   218,   213,   274,   265,   265,
     267,   270,   269,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   236,   257,   258,  1715,   261,
     262,   263,     6,   236,  1547,     7,   267,   268,   316,   317,
     318,   236,   265,   296,   277,   433,   269,   435,   269,   281,
     269,   269,   283,   284,   442,   267,  2188,   269,   269,   292,
     624,   273,   295,   296,   236,   265,     7,   267,   269,   272,
     269,   349,   350,   351,   269,   271,   269,   269,   311,   312,
     236,   269,   315,   316,   317,   318,   269,   265,   209,   367,
    2222,   265,   335,   326,   337,   236,   265,   330,   267,   332,
     343,   344,   271,   265,   265,   267,   265,  1082,  1083,   271,
     266,     6,   268,   346,   347,   236,   349,   350,   351,   253,
     254,   262,   263,   265,   265,   267,   267,   265,   269,   267,
     271,   253,   254,   448,   367,    57,     7,   370,   253,   254,
       7,  2159,   188,   189,   190,   191,   262,   263,   269,   265,
       6,   267,   268,   717,   200,   271,   202,   203,   204,   205,
     206,     6,   393,   108,   210,   211,   111,   213,   113,   400,
     401,   402,   265,   248,   249,   406,   407,   408,   409,   410,
     411,   412,   266,   414,   563,     6,   248,   249,   419,   420,
     274,   269,   423,   238,   239,   240,   241,   269,     8,   262,
     263,   273,   265,   108,   267,   438,   111,   440,   271,   253,
     254,   444,   445,   238,   239,   240,   241,   262,   263,   124,
     108,   785,   149,   111,   270,     6,   271,   460,   262,   263,
     274,   265,     6,   267,   467,   253,   254,   271,   802,   266,
     167,   268,   265,   253,   254,     6,   269,   274,   812,   253,
     254,   178,   179,   180,     4,     6,   274,   184,   185,   492,
     648,   265,   650,   651,   274,   269,   238,   239,   240,   241,
     267,   586,   266,   149,   268,   105,    26,  1161,   108,   667,
     274,   111,   111,   113,   113,   518,   105,    37,    38,   108,
     678,   167,   111,   108,   124,   217,   111,   238,   239,   240,
     241,   579,   178,   179,   180,   124,   266,   265,   184,   185,
     543,  1998,   258,   259,   274,   253,   254,   705,   264,   552,
     553,   262,   263,   265,   557,   267,   559,   560,   561,   562,
     563,   269,   585,   266,   587,   268,   569,   253,   254,   267,
     266,   274,   721,   270,   265,   578,   579,   580,   274,   582,
     583,   584,   585,   269,   587,   277,   589,     6,     7,   253,
     254,   925,   750,   265,   114,   115,   597,   238,   239,   240,
     241,   238,   239,   240,   241,   269,   255,   256,   257,   258,
     259,   108,   615,   265,   111,   264,   113,   269,   621,   262,
     263,   262,   263,   315,   270,   262,   263,   124,   262,   263,
     265,   265,   267,   267,   326,     4,   271,   265,   330,   274,
     643,   644,  1296,  1297,   657,   658,   266,   771,   268,   734,
     663,   262,   263,   271,   274,   273,   154,   155,   269,   659,
     660,   159,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     128,   684,   685,   686,   264,   266,   265,   268,   269,   692,
     270,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   262,
     263,   714,   265,   264,   267,   738,   719,   720,   721,   722,
     723,   724,   725,   726,   727,     4,   729,   730,   731,   732,
     733,   269,   735,   736,   737,   738,   739,   271,   265,   742,
     274,     4,   827,   265,     4,   270,   265,    26,   267,   274,
    1084,   265,   444,   445,   265,   154,   155,   760,    37,    38,
     159,   270,   266,    26,   268,   274,    26,   266,   460,   268,
     269,  1516,   265,   776,    37,    38,   270,    37,    38,   782,
     274,   265,     4,   267,     6,   154,   155,   156,   157,   791,
     159,   160,   265,   270,   265,   798,   799,   274,   149,   265,
     169,   804,   265,   806,   173,   265,   809,   810,   253,   254,
     255,   256,   257,   258,   259,   818,   167,   820,   111,   264,
     270,   270,   980,     6,   274,   274,     6,   178,   179,   180,
     954,   253,   254,   184,   185,   114,   115,   262,   263,   270,
     265,   270,   267,   274,   269,   274,   270,   850,   269,   852,
     274,   114,   115,   269,   114,   115,   270,     3,   270,  1604,
     274,  2154,   274,   270,   113,   265,   270,   274,   560,  1614,
     274,   265,   270,   270,   270,   270,   274,   274,   274,   274,
     270,   269,   967,    29,   274,   888,   578,   270,   580,   270,
     111,   274,  1226,   274,  1228,   898,   270,   270,  2181,   270,
     274,   274,   270,   274,   270,  2198,   274,  1241,   274,   265,
     270,   270,   270,  1037,   274,   274,   274,   270,    64,   108,
     921,   274,   270,   270,   927,  2208,   274,   274,     8,   270,
     270,   269,   269,   274,   274,   198,   199,  1271,   198,   199,
     943,   270,   270,   270,   270,   274,   274,   274,   274,   265,
     270,   270,   955,   954,   274,   274,   270,   269,  1082,  1083,
     274,   964,   270,   270,   270,   270,   274,   274,   274,   274,
     983,   269,   118,   976,   111,  1099,   108,   990,     8,     4,
       5,   994,   270,   270,   270,   270,   274,   274,   274,   274,
     270,     6,  1326,   270,   274,  1329,  1330,   274,   270,   108,
     111,  1086,   274,   149,   111,     4,     4,     4,   154,   155,
     156,   265,     4,   265,   265,     8,     6,   163,   265,   267,
    1354,   267,     6,     6,   269,    50,    51,    52,    53,    54,
      55,    56,    57,    58,   273,   269,     6,   273,    63,    64,
      65,    66,   265,  1377,     9,   265,    71,    72,    73,    74,
    1381,   265,   265,   265,   269,    80,   202,    82,   265,   265,
     201,   201,   201,   111,   269,   138,   265,   265,   760,   265,
    1404,   265,   218,    98,  1077,   201,   101,   269,   265,   265,
     105,   265,  1085,   108,  1418,     4,   111,   269,   113,   265,
    1093,  1425,  1746,  1747,   269,   269,   269,   269,     6,   124,
     267,     6,     6,  1106,   269,   269,   269,   269,  1111,     7,
     269,   267,   267,   267,   260,     6,     6,   265,  1242,  1243,
     145,   265,   269,   201,   267,     6,     6,  1140,     6,   265,
    1131,   265,   265,   279,   280,   265,   265,   265,  1141,  1142,
       8,  1144,  1145,  1146,   269,  1148,  1149,  1150,  1151,  1152,
    1153,  1154,  1155,  1156,  1157,     6,     8,   265,     7,   269,
       6,  1161,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     269,   269,     6,   269,   264,   270,   100,   274,     7,   266,
     270,   274,   217,   218,   219,     6,     6,   266,   269,  1202,
    1203,  1204,   269,   269,   229,   269,   269,   269,   233,   269,
     235,   236,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
    1233,   269,   269,  1234,   264,   927,   266,   269,   268,    68,
     264,   266,   271,   268,   269,     8,  1249,  1250,  1251,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,     7,     7,   265,
       6,   264,   964,   266,   269,   266,  1607,     7,     6,   268,
       6,  1405,  1406,     7,     6,   270,   198,   269,   266,   270,
     270,     6,   438,   269,   271,  1298,  1296,  1297,     7,     6,
     267,   265,     6,   449,     6,     6,   269,     6,     6,   266,
       7,   267,     7,     7,  1317,     7,  1319,  1320,     7,     7,
       7,     7,     7,     7,     7,   471,     7,     7,     7,  1332,
       7,     7,     6,   266,  1337,   274,   268,   274,  1341,   274,
     486,   270,   269,   274,  1429,   266,  1431,  1350,     7,  1352,
     270,     7,  1355,   271,   269,     4,   269,   149,     6,   270,
    2014,   271,     7,   270,     6,  1368,   269,   269,     7,     7,
       7,   271,   271,   266,   266,     9,   201,   274,  1381,   274,
     274,   266,   268,     7,   273,  1077,   170,  1388,  1389,     6,
       6,   270,   269,     6,   265,    50,    50,   271,   265,   269,
     269,  1093,   265,  1406,   265,   271,   271,     7,  1411,     7,
    1413,   557,     7,   559,   274,   561,   562,   563,   201,   266,
       7,     7,     7,     6,   266,     7,   274,     7,  1431,     7,
       7,     7,   123,     4,  1592,   269,   582,   583,  1596,   265,
       6,  1444,   269,   105,     6,  1448,     6,     6,   111,  1141,
    1142,     7,  1144,  1145,  1146,     7,  1148,  1149,  1150,  1151,
    1152,  1153,  1154,  1155,  1156,  1157,  1615,  1616,     6,     6,
    1804,     7,     7,     4,   272,   274,   266,   274,     6,   270,
    1604,  1812,   269,   269,   269,     6,     6,   267,     7,  1490,
       6,     6,     6,   265,   265,   269,     6,   270,  1499,     6,
       6,   271,     6,  1588,     6,   274,   268,  1510,  1511,  1512,
    1202,     6,     6,   142,     6,  1518,  1519,  1520,     6,   665,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,  1546,  1537,   681,     6,   264,     6,     6,
       6,  1233,     6,     6,     6,     6,     6,     6,     5,  1552,
     270,   201,   266,   266,   129,   129,   129,  1249,     6,     6,
    1563,     4,  1565,   269,     6,  1650,   269,     7,     6,   269,
       7,   267,     6,   719,   720,   721,   722,   723,   724,   725,
     726,   727,     6,   729,   730,   731,   732,   269,     6,   735,
     736,   737,   270,     6,   269,     6,   269,  1721,   270,   745,
     269,   197,   748,     6,  1607,   266,  1298,   274,   754,   274,
     274,   269,  1615,  1616,   274,     6,   269,     7,  1621,   271,
       6,   265,     6,   270,     6,  1317,     6,  1319,  1320,   265,
       4,     7,   265,     6,     6,     6,  1639,     6,   149,     6,
     109,     5,   269,     6,   790,     6,   792,  1650,   269,   269,
     269,   266,  1655,  1654,     6,  1668,   111,  1742,   269,   149,
     274,     6,   149,   809,   274,     6,  1815,     6,   274,   266,
     274,     6,     6,     6,   820,   274,  1368,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,     6,     6,  1780,     6,   264,     6,   269,
     269,     6,  1787,  1788,     6,   269,     7,   153,     6,     5,
       7,   269,   269,     6,   269,  2046,   269,   266,     6,   269,
       6,  1806,   269,     6,   270,   270,   269,     6,     6,     6,
    1733,   196,   266,     7,     6,  1738,  1739,   270,   270,  1431,
     270,     6,   271,     6,     6,     6,  1746,  1747,     6,     6,
       6,   269,  1444,   270,   266,     6,  1448,     6,   199,     6,
    1763,   269,     6,     6,   269,   266,   265,   270,     6,  1772,
     270,   269,   269,   269,     6,     6,     6,   270,   269,  1782,
     269,   149,  1785,   266,     6,     6,   270,     6,   270,     6,
     269,     6,   269,   269,     6,     6,     6,     6,  1801,     6,
    1417,  2161,  1805,  1479,  1663,  1978,  1938,  1729,     3,  1812,
    1443,  1814,  1815,  1095,     3,   576,     3,     3,  1510,  1511,
    1512,   489,   636,  2010,  1585,     3,  1518,  1519,  1520,  1805,
    1787,  1616,    -1,   979,   809,   981,   982,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1537,    -1,  1850,    -1,   995,
      -1,    -1,    -1,    -1,    -1,  1940,    -1,    -1,    -1,    -1,
      -1,  1007,    -1,    -1,    -1,  2023,    -1,    -1,    -1,    -1,
      -1,  1563,    -1,  1565,    -1,    -1,    -1,    -1,    -1,  1882,
    1883,    -1,    -1,  1029,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1983,    -1,
      -1,    -1,    -1,    -1,  1907,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
      -1,    -1,  1068,  1926,   264,    -1,    -1,    -1,    -1,  1621,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,    -1,    -1,
      -1,    -1,   264,    -1,    -1,  2113,    -1,    -1,  1650,    -1,
      -1,  1964,    -1,    -1,    -1,  1111,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1979,    -1,    -1,    -1,
      -1,  1984,    -1,    -1,  1987,  1988,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2155,    -1,    -1,
      -1,     6,    -1,    -1,    -1,  2008,    -1,    -1,  2011,    -1,
      -1,    -1,    -1,    -1,  2014,   149,    -1,    -1,    -1,  2022,
     154,   155,   156,    -1,    -1,    -1,    -1,    -1,  2031,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1733,    -1,  2046,  2129,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2059,  1203,  1204,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   202,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2090,    -1,    -1,
    1772,  2094,    -1,    -1,   218,    -1,    -1,    -1,  2091,    -1,
      -1,    -1,    -1,     4,     5,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1801,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1814,    -1,    -1,    -1,    -1,  1273,  2141,    -1,
      -1,    -1,  2145,    -1,    -1,    -1,  2139,    -1,    -1,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    -1,    -1,
      -1,    -1,    63,    64,    65,    66,    -1,    -1,    -1,    -1,
      71,    72,    73,    74,    -1,    -1,     6,    -1,    -1,    80,
      -1,    82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2193,  2194,    -1,    -1,    -1,  2188,    -1,    98,    -1,    -1,
     101,  1337,    -1,     6,   105,  1341,    -1,   108,    -1,    -1,
     111,    -1,   113,    -1,  1350,    -1,  1352,    -1,  2211,  1355,
      -1,    -1,    -1,   124,    -1,  1907,  1362,    -1,    -1,  2222,
      -1,    -1,    -1,  2226,  2227,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   145,    -1,  2239,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,    -1,    -1,    -1,    -1,   264,
    1406,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1964,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1979,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   109,    -1,
      -1,    -1,     6,    -1,   438,    -1,   217,   218,   219,    -1,
      -1,   122,    -1,    -1,    -1,    -1,  2008,    -1,   229,    -1,
      -1,    -1,   233,    -1,   235,   236,    -1,    -1,    -1,    -1,
    2022,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   149,    -1,
      -1,    -1,   153,    -1,    -1,    -1,    -1,   158,    -1,    -1,
      -1,   262,   263,    -1,   165,    -1,    -1,   168,   269,    -1,
     271,    -1,    -1,    -1,    -1,    -1,    -1,  2059,     6,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   187,   188,   189,    -1,
     191,   192,   193,    -1,   195,   196,   197,   198,   199,   200,
     201,    -1,   203,   204,   205,   206,    -1,    -1,    -1,  2091,
     211,    -1,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
      -1,    -1,    -1,   557,   264,   559,    -1,   561,   562,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,    -1,   582,   583,
      -1,   264,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1615,
    1616,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     291,   292,   293,   294,   295,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1639,    -1,    -1,  2188,    -1,    -1,   310,
     311,   312,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   328,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   338,   339,    -1,
    2222,    -1,    -1,   344,    -1,   346,   347,   348,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,    -1,    -1,   369,   370,
     264,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   380,
      -1,   382,   383,    -1,   385,    -1,    -1,    -1,   389,   390,
     391,    -1,    -1,   394,    -1,    -1,   720,   398,   722,   723,
     724,   725,   726,   727,    -1,   729,   730,   731,   732,    -1,
      -1,   735,   736,   737,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,    -1,    -1,    -1,    -1,   264,    -1,    -1,   440,
     441,    -1,    -1,    -1,    -1,    -1,  1782,    -1,    -1,  1785,
      -1,    -1,    -1,    -1,    -1,    -1,   457,   458,    -1,    -1,
      -1,    -1,  1798,    -1,  1800,    -1,    -1,    -1,    -1,    -1,
      -1,   472,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1815,
      -1,    -1,    -1,    -1,    -1,   809,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   494,    -1,    -1,   820,    -1,   499,    -1,
      -1,    -1,   503,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1850,    -1,   517,   518,    -1,    -1,
      -1,   522,    -1,    -1,    -1,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     541,   542,   543,   544,   545,   546,   547,   548,   549,   550,
     551,   552,   553,    -1,   555,   556,    -1,   558,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   568,    -1,    -1,
     571,   572,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   584,    -1,    -1,    -1,    -1,   589,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   612,   613,   614,   615,   616,   617,   618,   619,   620,
      -1,   622,   623,    -1,    -1,    -1,    -1,    -1,    -1,   630,
     631,   632,    -1,    -1,    -1,    -1,    -1,   638,   639,   640,
     641,    -1,   643,   644,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   662,   663,   664,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   674,   675,    -1,   677,    -1,    -1,   680,
       6,    -1,    -1,   684,   685,   686,   687,    -1,    -1,    -1,
     691,   692,   693,   694,   695,    -1,    -1,   698,    -1,   700,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   710,
      -1,    -1,   713,    -1,   715,   716,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   728,    -1,    -1,
     211,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   742,    -1,    -1,    -1,    -1,    -1,    -1,   749,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   757,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2103,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   776,    -1,   778,    -1,    -1,
      -1,    -1,   783,   784,    -1,    -1,    -1,  1111,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   798,    -1,   800,
     801,    -1,    -1,   804,    -1,   806,   807,    -1,    -1,    -1,
     811,    -1,   813,    -1,   815,    -1,    -1,    -1,    -1,    -1,
     821,    -1,    -1,  2159,   825,    -1,    -1,    -1,    -1,    -1,
     311,   312,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2182,   848,    -1,   850,
      -1,   852,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   346,   347,    -1,    -1,    -1,
      -1,    -1,    -1,     6,    -1,  2211,    -1,    -1,    -1,  1203,
    1204,    -1,    -1,    -1,    -1,    -1,    -1,   888,    -1,    -1,
    2226,  2227,    -1,    -1,    -1,    -1,    -1,   898,   899,   900,
     901,    -1,    -1,  2239,    -1,    -1,    -1,   908,   909,   910,
      -1,   912,    -1,    -1,   915,   211,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,    -1,    -1,    -1,    -1,   264,    -1,
      -1,    -1,   943,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   955,    -1,    -1,    -1,    -1,   440,
      -1,    -1,   963,    -1,    -1,    -1,   967,    -1,    -1,    -1,
      -1,    -1,   973,    -1,    -1,   976,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   984,   985,    -1,    -1,     4,     5,   990,
      -1,    -1,    -1,    -1,    -1,    -1,   292,    -1,   999,   295,
      -1,  1002,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1337,    -1,   311,   312,  1341,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1350,  1028,  1352,  1030,
    1031,  1355,    -1,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    -1,    -1,    -1,    -1,    63,    64,    65,    66,
     346,   347,  1053,    -1,    71,    72,    73,    74,    -1,    -1,
       6,    -1,    -1,    80,    -1,    82,    -1,    -1,    -1,    -1,
      -1,    -1,  1073,    -1,   370,    -1,    -1,    -1,    -1,  1080,
      -1,    98,  1406,    -1,   101,    -1,  1087,    -1,   105,    -1,
      -1,   108,    -1,    -1,   111,    -1,   113,    -1,    -1,  1100,
    1101,    -1,    -1,    -1,    -1,  1106,    -1,   124,   589,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,    -1,   145,    -1,
      -1,   264,    -1,    -1,    -1,    -1,    -1,  1138,    -1,    -1,
      -1,    -1,    -1,    -1,   440,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   643,   644,    -1,    -1,    -1,    -1,    -1,    -1,
     149,    -1,    -1,    -1,    -1,    -1,    -1,  1178,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1188,  1189,  1190,
    1191,  1192,    -1,    -1,    -1,    -1,  1197,  1198,    -1,  1200,
     217,   218,   219,   684,   685,   686,    -1,    -1,    -1,    -1,
      -1,   692,   229,    -1,    -1,    -1,   233,  1218,   235,   236,
    1221,  1222,   518,    -1,    -1,    -1,    -1,    -1,  1229,  1230,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1238,  1239,    -1,
      -1,    -1,    -1,  1244,  1245,    -1,    -1,   543,    -1,  1250,
    1251,    -1,   269,    -1,    -1,    -1,   552,   553,    -1,    -1,
      -1,   742,    -1,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,    -1,    -1,    -1,  1285,   264,    -1,    -1,   584,    -1,
      -1,    -1,    -1,   589,    -1,   776,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,  1315,  1639,    -1,   798,   264,   615,
      -1,    -1,    -1,   804,    -1,   806,  1327,  1328,    -1,    -1,
      -1,  1332,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1340,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   643,   644,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1364,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1375,    -1,    -1,  1378,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   684,   685,
     686,     6,    -1,    -1,    -1,    -1,   692,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1407,   888,    -1,  1410,
    1411,  1412,  1413,    -1,    -1,    -1,    -1,   898,    -1,    -1,
    1421,    -1,    -1,  1424,     6,  1426,    -1,  1428,  1429,    -1,
      -1,  1432,  1433,  1434,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   742,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1782,    -1,
      -1,  1785,   943,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   955,    -1,    -1,    -1,    -1,    -1,
     776,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   976,    -1,    -1,    -1,    -1,
      -1,    -1,   798,    -1,    -1,    -1,    -1,    -1,   804,    -1,
     806,    -1,    -1,    -1,    -1,    -1,  1517,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1528,  1529,  1530,
      -1,    -1,    -1,    -1,    -1,    -1,  1537,    -1,  1539,    -1,
      -1,    -1,    -1,    -1,    -1,  1546,    -1,    -1,    -1,    -1,
      -1,  1552,    -1,    -1,   850,    -1,   852,  1558,  1559,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1569,  1570,
    1571,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1580,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1590,
      -1,    -1,   888,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   898,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1611,    -1,    -1,    -1,    -1,    -1,     6,    -1,  1619,  1620,
      -1,    -1,    -1,    -1,    -1,  1106,    -1,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,    -1,    -1,   943,    -1,   264,
      -1,    -1,    -1,    -1,  1655,    -1,    -1,    -1,    -1,   955,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,    -1,    -1,
     976,    -1,   264,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1697,  1698,  1699,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1713,    -1,    -1,    -1,    -1,  1718,  1719,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     6,    -1,    -1,    -1,
    1731,    -1,    -1,    -1,    -1,    -1,    -1,  1738,  1739,  1740,
      -1,  1742,    -1,    -1,    -1,    -1,    -1,  1748,  1749,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1763,  1764,    -1,    -1,    -1,    -1,    -1,  1250,
    1251,    -1,    -1,    -1,    -1,  1776,  1777,    -1,   462,  1780,
      -1,    -1,  1783,    -1,    -1,    -1,  1787,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1797,    -1,    -1,    -1,
      -1,     6,    -1,    -1,    -1,    -1,  1807,    -1,    -1,    -1,
    1106,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1821,    -1,    -1,    -1,    -1,  1826,  1827,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1840,
      -1,    -1,  1843,  1844,    -1,  1846,    -1,    -1,    -1,    -1,
      -1,  1332,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
    1871,  1872,  1873,    -1,   264,    -1,    -1,    -1,    -1,    -1,
      -1,  1882,  1883,    -1,    -1,   569,    -1,  2211,  1889,  1890,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1901,    -1,  2226,  2227,    -1,    -1,    -1,    -1,    -1,  1910,
      -1,    -1,    -1,    -1,    -1,  2239,    -1,    -1,    -1,    -1,
    1921,  1922,    -1,    -1,  1925,  1926,    -1,    -1,    -1,    -1,
    1411,    -1,  1413,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   626,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1250,  1251,    -1,    -1,    -1,    -1,
    1961,  1962,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
      -1,  1982,    -1,    -1,   264,    -1,  1987,  1988,  1989,    -1,
      -1,    -1,  1993,    -1,    -1,    -1,  1997,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2011,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     6,    -1,    -1,    -1,  2028,    -1,    -1,
    2031,    -1,    -1,    -1,    -1,    -1,  1332,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,  2056,     6,    -1,    -1,   264,
      -1,  2062,    -1,    -1,  2065,    -1,    -1,    -1,    -1,    -1,
      -1,  1552,    -1,    -1,    -1,    -1,    -1,    -1,  2079,    -1,
    2081,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2099,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1411,    -1,  1413,  2119,  2120,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2134,    -1,    -1,    -1,    -1,  2139,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2152,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2161,    -1,    -1,    -1,  2165,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   857,   858,   859,   860,   861,   862,   863,
     864,   865,   866,   867,   868,  2186,   870,   871,   872,   873,
    2191,   875,   876,   877,   878,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   891,    -1,   893,
      -1,    -1,    -1,    -1,    -1,  2216,  2217,    -1,    -1,    -1,
     904,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     6,   917,   918,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   926,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1552,  1738,  1739,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,    -1,    -1,    -1,
      -1,   264,  1763,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
      -1,    -1,    -1,    -1,   264,     3,     4,    -1,     6,    -1,
      -1,    -1,    10,    11,    12,    -1,    -1,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    -1,  1039,  1040,  1041,    -1,  1655,
      -1,  1045,  1046,    -1,    -1,  1049,  1050,  1051,  1052,    -1,
    1054,    59,    60,    61,    62,  1059,    -1,    -1,    -1,    67,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    83,    84,    85,    -1,    -1,
      -1,  1882,  1883,    -1,    -1,    -1,    -1,    -1,    96,    97,
      -1,    99,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
      -1,    -1,    -1,    -1,   264,    -1,   266,    -1,   268,    -1,
      -1,    -1,  1738,  1739,   274,  1926,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1137,    -1,  1139,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1763,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,    -1,    -1,    -1,    -1,
     264,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1987,  1988,    -1,    -1,
      -1,     6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   216,    -1,
    2011,    -1,   220,    -1,    -1,    -1,    -1,    -1,   226,   227,
     228,    -1,   230,   231,   232,    -1,    -1,    -1,   236,    -1,
    2031,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1247,    -1,   253,   254,    -1,    -1,    -1,
      -1,    -1,   260,    -1,    -1,    -1,    -1,   265,    -1,    -1,
      -1,    -1,    -1,    -1,   272,    -1,  1882,  1883,    -1,    -1,
       3,     4,    -1,    -1,    -1,    -1,    -1,    10,    11,    12,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,     6,
    1926,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    59,    60,    61,    62,
      -1,    -1,    -1,    -1,    67,    -1,    -1,    -1,  2139,    -1,
      -1,    -1,    -1,    -1,    -1,     6,    -1,    -1,    -1,    -1,
      83,    84,    85,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    96,    97,    -1,    99,    -1,    -1,    -1,
      -1,  1987,  1988,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1387,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2011,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,    -1,  2031,    -1,    -1,   264,    -1,
      -1,    -1,    -1,    -1,   270,    -1,  1430,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,    -1,    -1,    -1,    -1,   264,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1462,  1463,
    1464,  1465,  1466,  1467,  1468,    -1,    -1,    -1,    -1,  1473,
    1474,    -1,    -1,    -1,    -1,    -1,  1480,    -1,    -1,    -1,
      -1,    -1,    -1,   216,  1488,    -1,    -1,   220,  1492,    -1,
      -1,  1495,    -1,   226,   227,   228,    -1,   230,   231,   232,
      -1,    -1,  1506,   236,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     253,   254,    -1,  2139,    -1,    -1,    -1,   260,    -1,    -1,
      -1,    -1,   265,    -1,    -1,    -1,   269,    -1,    -1,   272,
      -1,    -1,    -1,    -1,    -1,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,    -1,    -1,    -1,    -1,   264,    -1,    -1,
      -1,    -1,  1576,    -1,  1578,    -1,    -1,    -1,  1582,    -1,
    1584,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,    -1,
      -1,    -1,    -1,   264,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1615,     3,     4,     5,    -1,    -1,    -1,    -1,    10,
      11,    12,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,     6,    -1,    -1,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    -1,    -1,
      71,    72,    73,    74,    -1,    -1,    77,    78,    79,    80,
      -1,    82,    83,    84,    85,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    96,    97,    98,    99,    -1,
     101,    -1,    -1,    -1,   105,    -1,  1720,   108,    -1,    -1,
     111,    -1,   113,    -1,    -1,    -1,    -1,    -1,    -1,   120,
      -1,    -1,    -1,   124,   125,   126,    -1,    -1,   129,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,    -1,   140,
     141,    -1,   143,    -1,   145,    -1,    -1,   148,    -1,    -1,
      -1,    -1,    -1,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,    -1,    -1,    -1,   169,    -1,
      -1,    -1,   173,    -1,    -1,    -1,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,    -1,    -1,    -1,   198,   264,    -1,
     266,    -1,    -1,  1817,    -1,    -1,  1820,    -1,   274,    -1,
      -1,    -1,    -1,    -1,    -1,   216,   217,   218,   219,   220,
     221,    -1,    -1,    -1,    -1,   226,   227,   228,   229,   230,
     231,   232,   233,    -1,   235,   236,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   253,   254,  1868,  1869,     7,     8,    -1,   260,
      -1,  1875,    -1,    -1,   265,    -1,    -1,    -1,   269,    -1,
      -1,   272,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
      -1,    -1,    -1,    -1,   264,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1931,  1932,    -1,
       3,     4,     5,    -1,    -1,    -1,    -1,    10,    11,    12,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    -1,    -1,  1980,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    -1,    -1,    71,    72,
      73,    74,    -1,    -1,    77,    78,    79,    80,    -1,    82,
      83,    84,    85,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    96,    97,    98,    99,    -1,   101,    -1,
      -1,    -1,   105,    -1,    -1,   108,    -1,    -1,   111,    -1,
     113,    -1,    -1,    -1,    -1,    -1,    -1,   120,    -1,    -1,
      -1,   124,   125,   126,    -1,    -1,   129,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   138,    -1,   140,   141,    -1,
     143,    -1,   145,    -1,    -1,   148,    -1,    -1,    -1,    -1,
      -1,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,    -1,    -1,    -1,   169,    -1,    -1,    -1,
     173,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,     7,
      -1,    -1,    -1,   264,    -1,   198,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   216,   217,   218,   219,   220,   221,     8,
      -1,    -1,    -1,   226,   227,   228,   229,   230,   231,   232,
     233,    -1,   235,   236,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     253,   254,    -1,    -1,    -1,    -1,    -1,   260,    -1,    -1,
      -1,    -1,   265,    -1,    -1,    -1,   269,    -1,    -1,   272,
      -1,  2205,     3,     4,     5,    -1,     7,    -1,    -1,    10,
      11,    12,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    -1,    -1,    -1,
      71,    72,    73,    74,    -1,    -1,    -1,    -1,    -1,    80,
      -1,    82,    83,    84,    85,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    96,    97,    98,    99,    -1,
     101,    -1,    -1,    -1,   105,    -1,    -1,   108,    -1,    -1,
     111,    -1,   113,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   124,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,    -1,    -1,   145,    -1,   264,    -1,    -1,    -1,
      -1,    -1,   270,    -1,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,    -1,    -1,    -1,    -1,   264,    -1,    -1,    -1,
      -1,    -1,    -1,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,    -1,    -1,    -1,     8,   264,    -1,    -1,   209,    -1,
      -1,    -1,    -1,    -1,    -1,   216,   217,   218,   219,   220,
      -1,    -1,    -1,    -1,    -1,   226,   227,   228,   229,   230,
     231,   232,   233,    -1,   235,   236,    -1,   238,   239,   240,
     241,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   253,   254,    -1,    -1,    -1,    -1,    -1,   260,
      -1,   262,   263,    -1,   265,    -1,   267,     3,     4,     5,
     271,   272,    -1,    -1,    10,    11,    12,    -1,    -1,    15,
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
       3,     4,    -1,   269,    -1,     8,   272,    10,    11,    12,
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
       8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   216,    -1,    -1,    -1,   220,   221,    -1,
      -1,    -1,    -1,   226,   227,   228,    -1,   230,   231,   232,
      -1,    -1,    -1,   236,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     253,   254,    -1,    -1,    -1,    -1,    -1,   260,    -1,    -1,
      -1,    -1,   265,     3,     4,    -1,    -1,   270,    -1,   272,
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
      -1,    -1,    -1,    -1,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,    -1,    -1,    -1,   169,
      -1,    -1,    -1,   173,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,    -1,    -1,    -1,    -1,   264,    -1,   198,    -1,
      -1,    -1,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   216,    -1,    -1,    -1,
     220,   221,    -1,    -1,    -1,    -1,   226,   227,   228,    -1,
     230,   231,   232,    -1,    -1,    -1,   236,    -1,    -1,    -1,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    96,
      97,    -1,    99,    -1,    -1,    -1,    -1,    -1,   105,    -1,
      -1,   108,    -1,    -1,   111,    -1,   113,    -1,    -1,    -1,
      -1,    -1,    -1,   120,    -1,    -1,    -1,   124,   125,   126,
      -1,    -1,   129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   138,    -1,   140,   141,    -1,   143,    -1,   145,    -1,
      -1,   148,    -1,    -1,    -1,    -1,    -1,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,    -1,
      -1,    -1,   169,    -1,    -1,    -1,   173,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,    -1,    -1,    -1,    -1,   264,
      -1,   198,    -1,    -1,    -1,    -1,     8,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   216,
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
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,    -1,    -1,
      -1,    -1,   264,    -1,   198,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
     141,     5,   143,    -1,   145,    -1,    -1,   148,    -1,    -1,
      -1,    -1,    -1,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,    -1,    -1,    -1,   169,    -1,
      -1,    -1,   173,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    -1,    -1,   198,    -1,    63,
      64,    65,    66,    -1,    -1,    -1,    -1,    71,    72,    73,
      74,    -1,    -1,    -1,    -1,   216,    80,    -1,    82,   220,
     221,    -1,    -1,    -1,    -1,   226,   227,   228,    -1,   230,
     231,   232,    -1,    -1,    98,   236,    -1,   101,    -1,    -1,
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
      -1,    -1,    -1,   217,   218,   219,    -1,    -1,    96,    97,
      -1,    99,    -1,    -1,    -1,   229,    -1,   105,    -1,   233,
     108,   235,    -1,   111,    -1,   113,    -1,    -1,    -1,    -1,
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
     165,    -1,    -1,    -1,   169,    -1,    -1,    -1,   173,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,    -1,    -1,    -1,
      -1,   264,    -1,   198,    -1,    -1,    -1,   270,    -1,    -1,
      -1,   274,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
      -1,   260,     3,     4,    -1,    -1,   265,     8,    -1,    10,
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
      -1,    -1,    -1,    -1,    -1,   274,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   216,    -1,    -1,    -1,   220,
     221,    -1,    -1,    -1,    -1,   226,   227,   228,    -1,   230,
     231,   232,    -1,    -1,    -1,   236,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   253,   254,    -1,    -1,    -1,    -1,    -1,   260,
       3,     4,    -1,    -1,   265,    -1,    -1,    10,    11,    12,
      -1,   272,    15,    16,    17,    18,    19,    20,    21,    22,
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
      -1,    -1,    -1,   274,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   216,    -1,    -1,    -1,   220,   221,    -1,
      -1,    -1,    -1,   226,   227,   228,    -1,   230,   231,   232,
      -1,    -1,    -1,   236,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     253,   254,    -1,    -1,    -1,    -1,    -1,   260,    -1,    -1,
      -1,    -1,   265,     3,     4,    -1,    -1,   270,    -1,   272,
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
      -1,    -1,    -1,    -1,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,    -1,    -1,    -1,   169,
      -1,    -1,    -1,   173,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,    -1,    -1,    -1,    -1,   264,    -1,   198,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   274,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   216,    -1,    -1,    -1,
     220,   221,    -1,    -1,    -1,    -1,   226,   227,   228,    -1,
     230,   231,   232,    -1,    -1,    -1,   236,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   253,   254,    -1,    -1,    -1,    -1,    -1,
     260,     3,     4,     5,    -1,   265,    -1,    -1,    10,    11,
      12,    -1,   272,    15,    16,    17,    18,    19,    20,    21,
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
      -1,    -1,    -1,    -1,   216,   217,   218,   219,   220,    -1,
      -1,    -1,    -1,    -1,   226,   227,   228,   229,   230,   231,
     232,   233,    -1,   235,   236,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   253,   254,    -1,    -1,    -1,    -1,    -1,   260,    -1,
      -1,    -1,    -1,   265,    -1,    -1,    -1,   269,    -1,    -1,
     272,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,    -1,
      -1,    -1,    -1,   264,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   274,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   216,   217,   218,   219,   220,    -1,    -1,
      -1,    -1,    -1,   226,   227,   228,   229,   230,   231,   232,
     233,    -1,   235,   236,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     253,   254,    -1,    -1,    -1,    -1,    -1,   260,    -1,    -1,
      -1,    -1,   265,     3,     4,     5,   269,    -1,    -1,   272,
      10,    11,    12,    -1,    -1,    15,    16,    17,    18,    19,
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
       3,     4,    -1,    -1,   265,    -1,    -1,    10,    11,    12,
      -1,   272,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    59,    60,    61,    62,
      -1,    -1,    -1,    -1,    67,    13,    14,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      83,    84,    85,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,    -1,    96,    97,     8,    99,    10,    11,    12,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    59,    60,    61,    62,
      -1,    -1,    -1,    -1,    67,    -1,    -1,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
      83,    84,    85,   121,   122,   123,   124,    -1,    -1,    -1,
      -1,   129,    -1,    96,    97,    -1,    99,    -1,    -1,    -1,
     138,   139,    -1,    -1,   142,   143,    -1,   145,   146,    -1,
     148,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   216,    -1,    -1,    -1,   220,   166,    -1,
      -1,    -1,    -1,   226,   227,   228,    -1,   230,   231,   232,
      -1,    -1,    -1,   236,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   193,   194,   195,    -1,    -1,
     253,   254,    -1,    -1,    -1,    -1,    -1,   260,    -1,    -1,
      -1,    -1,   265,    -1,    -1,    -1,   269,    -1,    -1,   272,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,    -1,    -1,
      -1,    -1,   264,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   274,   216,    -1,    -1,    -1,   220,    -1,    -1,
      -1,    -1,    -1,   226,   227,   228,    -1,   230,   231,   232,
      -1,    -1,   270,   236,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     253,   254,    -1,    -1,    -1,    -1,    -1,   260,     3,     4,
      -1,    -1,   265,    -1,    -1,    10,    11,    12,    -1,   272,
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
      -1,    -1,    -1,    -1,    -1,   260,    -1,    -1,    -1,    -1,
     265,   266,    -1,    -1,    -1,    -1,    -1,   272,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,    -1,    -1,    -1,    -1,
     264,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     274,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   216,    -1,
      -1,    -1,   220,    -1,    -1,    -1,    -1,    -1,   226,   227,
     228,    -1,   230,   231,   232,    -1,    -1,    -1,   236,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   253,   254,    -1,    -1,    -1,
      -1,    -1,   260,     3,     4,    -1,     6,   265,    -1,    -1,
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
     260,    -1,     3,     4,    -1,   265,    -1,    -1,    -1,    10,
      11,    12,   272,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   216,    -1,    -1,    -1,   220,    59,    60,
      61,    62,    -1,   226,   227,   228,    67,   230,   231,   232,
      -1,    -1,    -1,   236,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    83,    84,    85,    -1,    -1,    -1,    -1,    -1,
     253,   254,    -1,    -1,    -1,    96,    97,   260,    99,     3,
       4,    -1,   265,    -1,    -1,    -1,    10,    11,    12,   272,
      -1,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    59,    60,    61,    62,    -1,
      -1,    -1,    -1,    67,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    83,
      84,    85,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    96,    97,    -1,    99,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,    -1,   216,    -1,    -1,   264,   220,
      -1,    -1,    -1,    -1,    -1,   226,   227,   228,   274,   230,
     231,   232,    -1,    -1,    -1,   236,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   253,   254,    -1,    -1,    -1,    -1,    -1,   260,
      -1,     3,     4,    -1,   265,   266,    -1,    -1,    10,    11,
      12,   272,    -1,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   216,    -1,    -1,    -1,   220,    59,    60,    61,
      62,    -1,   226,   227,   228,    67,   230,   231,   232,    -1,
      -1,    -1,   236,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    83,    84,    85,    -1,    -1,    -1,    -1,    -1,   253,
     254,    -1,    -1,    -1,    96,    97,   260,    99,     3,     4,
      -1,   265,   266,    -1,    -1,    10,    11,    12,   272,    -1,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    59,    60,    61,    62,    -1,    -1,
      -1,    -1,    67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    83,    84,
      85,    -1,    -1,    -1,    13,    14,    -1,    -1,    -1,    -1,
      -1,    96,    97,    -1,    99,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,    -1,   216,    -1,    -1,   264,   220,    -1,
      -1,    -1,    -1,    -1,   226,   227,   228,   274,   230,   231,
     232,    -1,    -1,    -1,   236,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   253,   254,    -1,    -1,    -1,    -1,    -1,   260,    -1,
      -1,    -1,    -1,   265,    -1,    -1,    -1,   269,    -1,    -1,
     272,    -1,    -1,    -1,    -1,    -1,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,    13,
      14,    -1,   121,   122,   123,   124,    -1,    -1,    -1,    -1,
     129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,
     139,   216,    -1,   142,   143,   220,   145,   146,    -1,   148,
      -1,   226,   227,   228,    -1,   230,   231,   232,    -1,    -1,
      -1,   236,    -1,    -1,    -1,    -1,    -1,   166,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   253,   254,
      -1,    13,    14,    -1,    -1,   260,    -1,    -1,    -1,    -1,
     265,    -1,    -1,    -1,   193,   194,   195,   272,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,    -1,    -1,    -1,   121,   122,   123,
     124,    -1,    -1,    -1,    -1,   129,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   138,   139,    -1,    -1,   142,   143,
      -1,   145,   146,    -1,   148,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   270,   166,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,    13,    14,    -1,   121,
     122,   123,   124,    -1,    -1,    -1,    -1,   129,    -1,   193,
     194,   195,    -1,    -1,    -1,    -1,   138,   139,    -1,    -1,
     142,   143,    -1,   145,   146,    -1,   148,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   166,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    13,    14,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   193,   194,   195,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   270,    -1,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,    -1,    -1,    -1,   121,   122,   123,   124,    -1,    -1,
      -1,    -1,   129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   138,   139,    -1,    -1,   142,   143,    -1,   145,   146,
      -1,   148,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   270,   166,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,    13,    14,    -1,   121,   122,   123,   124,
      -1,    -1,    -1,    -1,   129,    -1,   193,   194,   195,    -1,
      -1,    -1,    -1,   138,   139,    -1,    -1,   142,   143,    -1,
     145,   146,    -1,   148,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   166,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    13,    14,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   193,   194,
     195,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   270,    -1,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,    -1,    -1,
      -1,   121,   122,   123,   124,    -1,    -1,    -1,    -1,   129,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,   139,
      -1,    -1,   142,   143,    -1,   145,   146,    -1,   148,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   270,   166,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
      13,    14,    -1,   121,   122,   123,   124,    -1,    -1,    -1,
      -1,   129,    -1,   193,   194,   195,    -1,    -1,    -1,    -1,
     138,   139,    -1,    -1,   142,   143,    -1,   145,   146,    -1,
     148,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   166,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   193,   194,   195,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     270,    -1,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,    -1,    -1,    -1,   121,   122,
     123,   124,    -1,    -1,    -1,    -1,   129,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   138,   139,    -1,    -1,   142,
     143,    -1,   145,   146,    -1,   148,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   270,   166,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,    13,    14,    -1,
     121,   122,   123,   124,    -1,    -1,    -1,    -1,   129,    -1,
     193,   194,   195,    -1,    -1,    -1,    -1,   138,   139,    -1,
      -1,   142,   143,    -1,   145,   146,    -1,   148,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   166,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    13,
      14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   193,   194,   195,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   270,    -1,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,    -1,    -1,    -1,   121,   122,   123,   124,    -1,
      -1,    -1,    -1,   129,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   138,   139,    -1,    -1,   142,   143,    -1,   145,
     146,    -1,   148,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   270,
     166,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,    13,    14,    -1,   121,   122,   123,
     124,    -1,    -1,    -1,    -1,   129,    -1,   193,   194,   195,
      -1,    -1,    -1,    -1,   138,   139,    -1,    -1,   142,   143,
      -1,   145,   146,    -1,   148,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   166,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    13,    14,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   193,
     194,   195,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   270,    -1,   105,   106,   107,   108,
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
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,    -1,    -1,
      -1,    -1,   264,    -1,    -1,    -1,   193,   194,   195,    -1,
      -1,    -1,   274,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   270,    -1,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,    -1,    -1,    -1,   121,
     122,   123,   124,    -1,    -1,    -1,    -1,   129,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   138,   139,     0,     1,
     142,   143,     4,   145,   146,    -1,   148,    -1,    -1,    -1,
      -1,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   270,   166,    -1,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,    -1,    47,    48,    49,   264,    -1,
      -1,   193,   194,   195,    -1,    -1,    -1,    -1,   274,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    68,    69,    70,    -1,
      -1,    -1,    -1,    75,    76,    -1,    -1,    -1,    -1,    81,
      -1,    -1,    -1,    -1,    86,    87,    88,    89,    90,    91,
      92,    -1,    94,    95,    -1,    97,    -1,    -1,    -1,    -1,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,    -1,    -1,   120,   121,
     122,   123,   124,    -1,    -1,   127,    -1,   129,   270,   131,
     132,    -1,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,    -1,    -1,   150,   151,
     152,    -1,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,    -1,    -1,    -1,   181,
     182,   183,    -1,    -1,    -1,   187,    -1,    -1,    -1,    -1,
     192,   193,   194,   195,    -1,    -1,   198,    -1,   200,    -1,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,    -1,     4,    -1,    -1,    -1,    -1,
     222,   223,   224,   225,    13,    14,    -1,    -1,    -1,    -1,
      -1,    -1,   234,    -1,   236,   237,    -1,    -1,    -1,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,    -1,    47,    48,
      49,   264,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   274,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    68,
      69,    70,    -1,    -1,    -1,    -1,    75,    76,    -1,    -1,
      -1,    -1,    81,    -1,    -1,    -1,    -1,    86,    87,    88,
      89,    90,    91,    92,    -1,    94,    95,    -1,    97,    -1,
      -1,    -1,    -1,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,    -1,
      -1,   120,   121,   122,   123,   124,    -1,    -1,   127,    -1,
     129,    -1,   131,   132,    -1,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,    -1,
      -1,   150,   151,   152,    -1,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,    -1,
      -1,    -1,   181,   182,   183,    -1,    -1,    -1,   187,    -1,
      -1,    -1,    -1,   192,   193,   194,   195,     4,     5,   198,
      -1,   200,    -1,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,    -1,    -1,    -1,
      -1,    -1,    -1,   222,   223,   224,   225,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   234,    -1,   236,   237,    -1,
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
      -1,    -1,    13,    14,    -1,    98,    -1,    -1,   101,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    -1,
      -1,    -1,    -1,    63,    64,    65,    66,    -1,    -1,    -1,
      -1,    71,    72,    73,    74,    -1,    -1,    -1,    -1,    -1,
      80,    -1,    82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     217,   218,   219,    -1,    -1,    -1,    -1,    -1,    98,    -1,
      -1,   101,   229,    -1,    -1,    -1,   233,    -1,   235,   236,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,    -1,    -1,    -1,
     121,   122,   123,   124,    13,    14,    -1,    -1,   129,    -1,
      -1,    -1,    -1,    -1,   217,   218,   219,   138,   139,    -1,
      -1,   142,   143,    -1,   145,   146,   229,   148,    -1,    -1,
     233,   152,   235,   236,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   166,    -1,    -1,    -1,   170,
      -1,    -1,    -1,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,    -1,   193,   194,   195,   264,    -1,   217,   218,   219,
      -1,    -1,    -1,    -1,    -1,   274,    -1,    -1,    -1,   229,
      -1,    -1,    -1,   233,    -1,   235,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,    -1,
      -1,    -1,   121,   122,   123,   124,    -1,    -1,    -1,    -1,
     129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,
     139,    -1,    -1,   142,   143,    -1,   145,   146,    -1,   148,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   166,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,    -1,    -1,    -1,    -1,
     264,    -1,    -1,    -1,   193,   194,   195,    -1,    -1,    -1,
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
      -1,    -1,    -1,   264,    -1,    -1,    -1,    -1,   269,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,    -1,    -1,    -1,
      -1,   264,    -1,    -1,    -1,    -1,   269,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,    -1,    -1,    -1,    -1,   264,
      -1,    -1,    -1,    -1,   269,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,    -1,    -1,    -1,    -1,   264,    -1,   266,
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
      -1,    -1,   268,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,    -1,    -1,    -1,    -1,   264,    -1,    -1,    -1,   268,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,    -1,    -1,
      -1,    -1,   264,    -1,    -1,    -1,   268,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,    -1,    -1,    -1,    -1,   264,
      -1,   266,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
      -1,    -1,    -1,    -1,   264,    -1,   266,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,    -1,    -1,    -1,    -1,   264,
      -1,   266,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
      -1,    -1,    -1,    -1,   264,    -1,   266,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,    -1,    -1,    -1,    -1,   264,
      -1,   266,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
      -1,    -1,    -1,    -1,   264,    -1,   266,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,    -1,    -1,    -1,    -1,   264,
      -1,   266,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
      -1,    -1,    -1,    -1,   264,    -1,   266,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,    -1,    -1,    -1,    -1,   264,
      -1,   266,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
      -1,    -1,    -1,    -1,   264,    -1,   266,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,    -1,    -1,    -1,    -1,   264,
      -1,   266,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
      -1,    -1,    -1,    -1,   264,    -1,   266,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,    -1,    -1,    -1,    -1,   264,
      -1,   266,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
      -1,    -1,    -1,    -1,   264,    -1,   266,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,    -1,    -1,    -1,    -1,   264,
      -1,   266,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
      -1,    -1,    -1,    -1,   264,    -1,   266,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,    -1,    -1,    -1,    -1,   264,
      -1,   266,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
      -1,    -1,    -1,    -1,   264,    -1,   266,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,    -1,    -1,    -1,    -1,   264,
      -1,   266,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
      -1,    -1,    -1,    -1,   264,    -1,   266,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,    -1,    -1,    -1,    -1,   264,
      -1,   266,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
      -1,    -1,    -1,    -1,   264,    -1,   266,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,    -1,    -1,    -1,    -1,   264,
      -1,   266,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
      -1,    -1,    -1,    -1,   264,    -1,   266,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,    -1,    -1,    -1,    -1,   264,
      -1,   266,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
      -1,    -1,    -1,    -1,   264,    -1,   266,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,    -1,    -1,    -1,    -1,   264,
      -1,   266,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
      -1,    -1,    -1,    -1,   264,    -1,   266,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,    -1,    -1,    -1,    -1,   264,
      -1,   266,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
      -1,    -1,    -1,    -1,   264,    -1,   266,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,    -1,    -1,    -1,    -1,   264,
      -1,   266,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
      -1,    -1,    -1,    -1,   264,    -1,   266,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,    -1,    -1,    -1,    -1,   264,
      -1,   266,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
      -1,    -1,    -1,    -1,   264,    -1,   266,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,    -1,    -1,    -1,    -1,   264,
      -1,   266,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
      -1,    -1,    -1,    -1,   264,    -1,   266,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,    -1,    -1,    -1,    -1,   264,
      -1,   266,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
      -1,    -1,    -1,    -1,   264,    -1,   266,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,    -1,    -1,    -1,    -1,   264,
      -1,   266,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
      -1,    -1,    -1,    -1,   264,    -1,   266,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,    -1,    -1,    -1,    -1,   264,
      -1,   266,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
      -1,    -1,    -1,    -1,   264,    -1,   266,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,    -1,    -1,    -1,    -1,   264,
      -1,   266,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
      -1,    -1,    -1,    -1,   264,    -1,   266,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,    -1,    -1,    -1,    -1,   264,
      -1,   266,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
      -1,    -1,    -1,    -1,   264,    -1,   266,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,    -1,    -1,    -1,    -1,   264,
      -1,   266,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
      -1,    -1,    -1,    -1,   264,    -1,   266,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,    -1,    -1,    -1,    -1,   264,
      -1,   266,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
      -1,    -1,    -1,    -1,   264,    -1,   266,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,    -1,    -1,    -1,    -1,   264,
      -1,   266,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
      -1,    -1,    -1,    -1,   264,    -1,   266,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,    -1,    -1,    -1,    -1,   264,
      -1,   266,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
      -1,    -1,    -1,    -1,   264,    -1,   266,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,    -1,    -1,    -1,    -1,   264,
      -1,   266,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
      -1,    -1,    -1,    -1,   264,    -1,   266,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,    -1,    -1,    -1,    -1,   264,
      -1,   266,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
      -1,    -1,    -1,    -1,   264,    -1,   266,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,    -1,    -1,    -1,    -1,   264,
      -1,   266,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
      -1,    -1,    -1,    -1,   264
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
     344,   346,   347,   353,   354,   355,   356,   362,   387,   388,
     269,   273,    14,   111,   265,   265,   265,     6,   269,     6,
       6,     6,     6,   265,     6,   269,     6,   269,   269,     6,
       6,     6,     6,   267,   267,     4,   364,   388,   265,   267,
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
     337,   344,   346,   357,   358,   362,   364,   370,   373,   388,
     265,   269,   269,   111,   111,   138,   108,   111,   113,   323,
     108,   111,   112,   113,   124,   193,   324,   108,   111,   265,
     108,   170,   198,   214,   215,   269,   253,   254,   265,   269,
     367,   368,   367,   269,   269,   367,   269,   269,   265,   111,
     113,   111,   108,     4,    97,   209,   269,   388,     4,     6,
     105,     6,   108,   111,   108,   111,   124,   325,     5,   265,
     269,   370,   372,   111,     4,     4,     4,   372,     4,   111,
     265,   111,   265,   265,     4,   269,   375,   388,     4,   265,
     265,   265,     6,    33,   254,   357,   388,     6,   267,     5,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    63,
      64,    65,    66,    71,    72,    73,    74,    80,    82,    98,
     101,   217,   218,   219,   229,   233,   235,   379,   388,   265,
       4,   379,     5,   269,     5,   269,   323,   357,   267,     6,
     269,   265,   269,     6,   265,   269,     6,   273,     7,   145,
     209,   238,   239,   240,   241,   262,   263,   265,   267,   271,
     297,   298,   299,   323,   357,   378,   379,   388,     4,   327,
     328,   329,   269,     6,   357,   378,   379,   388,   378,   378,
     357,   378,   385,   386,   388,   357,   329,   357,   304,   308,
     265,   366,     9,   379,   265,   379,   357,   357,   357,   265,
     357,   357,   357,   265,   357,   357,   357,   357,   357,   357,
     357,   378,   357,   357,   357,   357,   372,   265,   254,   357,
     373,   374,   269,   372,   370,   378,   299,   299,   299,   299,
     299,   299,   299,   299,   299,   299,   299,   299,   299,   299,
     299,   299,   299,   299,   299,   299,   299,   299,   299,   299,
     299,   299,   265,   267,   299,   299,   299,   299,   299,   299,
     265,   299,   299,   265,   323,   324,   324,   324,   299,   299,
       5,   269,   269,   111,   108,   111,    68,   105,   138,   323,
     323,   324,   265,   299,   299,   265,   265,   265,   357,   269,
     357,   373,   357,   357,   270,   374,   364,   388,   201,     5,
     269,     8,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     264,     9,   265,   267,   271,   298,   299,   357,   374,   374,
     265,   265,   265,   370,   372,   372,   372,   322,   265,   269,
     265,   265,   370,   269,   269,   357,     4,   370,   269,   375,
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
     269,   378,   374,   357,   329,   370,   370,   269,   379,   323,
       7,   357,   357,     4,    26,    37,    38,   114,   115,   198,
     199,   301,   370,     6,   266,   268,   269,   300,   269,     6,
     269,     6,     9,   265,   267,   271,   388,   270,   138,   143,
     145,   146,   148,   321,   323,   357,     6,   266,   274,     9,
     265,   267,   271,   266,   274,   266,   274,   274,   266,   274,
       9,   265,   271,   274,   270,   274,   268,   274,   303,   268,
     303,   100,   365,   363,   388,   274,   357,   274,   266,   266,
     266,   357,   266,   266,   266,   357,   266,   266,   266,   266,
     266,   266,   266,   266,   266,   266,   266,   270,     7,   357,
     255,   270,   274,   357,     6,     6,   266,   357,   357,   357,
     357,   357,   357,   357,   357,   357,   357,   357,   357,   357,
     357,   357,   357,   357,   357,   373,   357,   357,   357,   357,
     357,   357,   357,   357,   357,   373,   373,   388,   269,   357,
     357,   378,   357,   378,   370,   378,   378,   385,   269,   269,
     269,   269,   357,   300,   388,     8,   357,   357,   269,   269,
     269,   325,   269,   372,   370,   269,   378,   378,   373,   364,
     379,   364,   374,   266,   270,   271,   299,    68,     8,   357,
     357,   357,   357,   357,   357,   357,   357,   357,   357,   357,
     357,   357,   357,   269,   357,   373,   357,   357,   357,   357,
     357,   388,   357,   357,   301,   269,   300,   266,   270,   270,
     357,   357,   357,     7,     7,   350,   350,   265,   357,   357,
     357,   357,     6,   174,   374,   374,   269,   266,     6,   329,
     269,   329,   329,   274,   274,   274,   367,   367,   328,   328,
     274,   357,   270,   341,   274,   329,   270,   270,   266,     7,
     351,     6,     7,   357,   357,     6,   357,   329,   357,   270,
     374,   374,   374,   357,     6,   266,   270,   357,   374,   357,
     357,   357,   357,   266,   357,   266,   266,   198,   274,   329,
     269,     8,   266,   266,   357,   357,   388,   301,   268,   385,
     378,   385,   378,   378,   378,   378,   378,   378,   357,   378,
     378,   378,   378,   272,   381,   388,   379,   378,   378,   378,
     364,   388,   374,   270,   270,   270,   270,   357,   329,   268,
     270,   266,   152,   170,   345,   266,   270,   274,   357,     6,
     269,   370,   266,   268,   271,     7,     7,   297,   298,     6,
     374,     7,   241,   297,   357,   282,   388,   357,   357,   301,
     267,   265,   138,   323,   324,   323,   269,   270,     6,   248,
     249,   279,   374,   388,   357,   357,   301,     6,   374,     6,
     374,   357,     6,   378,   386,   388,   266,   301,   357,   357,
       6,   388,     6,   378,   357,   266,   267,   357,   274,   379,
       7,     7,     7,   266,     7,     7,     7,   266,     7,     7,
       7,     7,     7,     7,     7,     7,     7,     7,   357,   266,
       6,   269,   357,   373,   270,     6,   300,   300,   300,   300,
     300,   300,   300,   300,   300,   300,   300,   300,   274,   300,
     300,   300,   300,   300,   300,   300,   300,   300,   274,   274,
     274,   274,   274,   266,   268,   268,   374,   274,   274,   300,
     274,   300,   274,   274,   274,   266,   374,   357,   357,   357,
     359,   300,   270,   270,   270,   357,   357,   357,   269,   357,
     357,   274,   274,   300,   300,   266,   271,   266,   271,   274,
     299,   360,   270,     7,   301,   300,   370,   270,     8,     8,
     374,   271,   266,   268,   265,   267,   298,   299,   374,     7,
     269,   269,   266,   266,   266,   357,   370,     4,   349,     6,
     317,   357,   379,   266,   270,   266,   266,   357,   270,   270,
     374,   271,   270,   329,   270,   270,   367,   357,   357,   270,
     270,   357,   367,   149,   149,   167,   178,   179,   180,   184,
     185,   342,   343,   367,   270,   338,   269,   269,     7,   357,
       6,   357,   266,   270,   268,   270,   268,   270,   270,   270,
     270,     6,   270,   268,   268,   274,   266,     7,   266,     7,
       7,   271,   357,   270,   357,   357,   271,   265,   267,     7,
     271,   300,   274,   300,   300,   266,   266,   274,   300,   300,
     274,   274,   300,   300,   300,   300,   357,   300,     9,   380,
     274,   266,   274,   300,   271,   274,   361,   268,   270,   266,
     270,   273,   201,     7,   170,     6,   357,   270,   269,     6,
     370,   270,   357,     6,     7,   297,   298,   271,   297,   298,
     301,   269,   376,   388,   379,   357,     6,   270,    50,    50,
     370,   270,     4,   188,   189,   190,   191,   270,   285,   289,
     292,   294,   295,   336,   271,   266,   268,   265,   357,   357,
     265,   269,   265,   269,     8,   374,   378,   266,   271,   266,
     268,   265,   266,   266,   274,   271,   265,   270,   274,     7,
     299,     4,    26,    37,    38,   311,   312,   313,   300,   357,
     300,   367,   370,   370,     7,   370,   370,   370,     7,   370,
     370,   370,   370,   370,   370,   370,   370,   370,   370,     6,
       7,   328,   357,   357,   357,   357,   357,   357,   270,   357,
     357,   357,   370,   378,   378,   270,   270,   270,   270,   274,
     310,   270,   270,   270,   357,   270,   270,   357,   357,   301,
     301,   357,   357,   266,   370,   299,   357,   357,   270,   301,
     298,   271,   298,   357,   357,   300,   270,   370,   374,   374,
       7,     7,     7,   149,   348,     6,   266,   274,     7,     7,
       7,     6,     7,     7,   270,     4,   301,   270,   274,   274,
     274,   270,   270,   123,     4,     6,   357,   269,     6,   265,
       6,   186,     6,   186,   270,   343,   274,   342,   328,   328,
     370,     6,   269,   105,     6,     6,     6,   111,     7,     7,
       6,     6,   357,     7,   370,     7,   370,   370,     4,   274,
       8,     8,   266,   301,   301,   301,   374,   378,   357,   378,
     272,   274,   314,   378,   378,   301,   378,   266,   274,     6,
     269,   323,   269,     6,   357,     6,   269,   370,   270,   270,
     357,     6,   198,   199,   301,   357,     6,     7,   375,   377,
       6,   267,     6,     6,   300,   299,   299,     6,   286,   265,
     265,   269,   296,     6,   301,   271,   378,   357,   268,   266,
     357,     8,   374,   357,   374,   270,   270,     6,     6,   279,
     301,   271,   357,     6,     6,   357,   301,   266,     6,   357,
     269,   357,   379,   300,    50,   269,   370,   379,   382,   357,
     357,   357,   268,   274,     6,   266,     6,     6,   142,   319,
     319,   370,     6,     6,     6,   370,   149,   201,   318,     6,
       6,     6,     6,     6,     6,     6,     6,     6,     5,   270,
     300,   300,   300,   300,   300,   300,   300,   274,   274,   274,
     266,   300,   300,   312,   300,   129,   129,   129,   270,   201,
     266,   300,   266,   299,   360,   300,     6,   300,   265,   267,
     299,   301,   266,   268,   300,     6,   270,   270,   370,   370,
     370,     4,     6,   297,   357,   370,   370,   370,   269,   269,
       7,     6,     7,   357,   357,   357,   269,   269,   269,   267,
       6,   357,   370,   357,     6,     6,   357,   367,   270,   270,
     270,     6,   374,   269,   269,   357,   357,   268,   370,     6,
     370,     6,   197,   357,   357,   357,   265,   267,     6,     6,
       7,   300,   274,   274,   300,   274,   357,     4,   213,   315,
     316,   300,   266,   300,   361,   379,   357,   269,   329,     6,
     329,   274,     6,     6,   271,     7,     7,   297,   298,     6,
     375,   270,   274,   357,   297,   269,   300,   383,   384,   385,
     383,   265,   357,   357,   369,   370,   269,   265,     4,     6,
     266,     6,   266,   270,   270,   266,   270,     6,     6,   378,
     265,     4,   266,   274,   265,   270,   274,   370,   379,     7,
     299,   309,   357,   373,   313,     6,   367,     6,     6,     6,
     149,   320,   105,   124,   109,     6,     5,     6,   357,   357,
     357,   269,   269,   269,   111,   357,   266,   360,   357,   357,
     300,   298,   269,   269,     6,   318,     6,   357,   370,   149,
     149,     4,     6,   374,   374,   357,   357,   379,   270,   266,
     270,   274,   328,   328,   357,   357,   270,   274,   266,   270,
     274,   270,   374,   357,     6,     6,     6,     6,     6,   370,
     270,   274,     8,   270,   266,   254,   269,   357,   371,   379,
     378,   357,   378,   357,   379,   382,   384,   379,   274,   266,
     274,   270,   357,   345,   345,   370,   301,   376,   379,   357,
       6,     6,   375,   268,   370,   385,     6,   300,   300,   283,
     357,   274,   274,   270,   274,   284,   357,   357,     6,     6,
       6,     6,   357,   357,   266,     6,   357,   305,   307,   269,
     384,   270,   274,     7,     7,   153,     6,   269,   269,   269,
       5,   300,   300,   274,   357,   357,   357,   269,   300,   266,
     266,   268,   374,   374,     6,     6,   357,   357,   269,   270,
     270,   269,     6,     6,   269,   357,   270,   270,   270,   268,
       6,   370,     7,   269,   357,     6,   270,   270,   196,   357,
     357,   269,   270,   374,     6,     6,     6,   266,   300,   300,
     316,   379,   270,   270,   270,   270,     7,     6,     6,     6,
     271,     6,   270,     6,     6,   266,   274,   357,   357,   269,
     370,   270,   274,   266,   266,   274,   270,   310,   314,   370,
     300,   357,   379,   388,   374,   374,   357,     6,   357,   274,
     270,   274,   357,   360,   270,   270,     6,     6,   369,   154,
     155,   159,   352,   154,   155,   352,   374,   328,   270,   274,
       6,   270,   370,   329,   270,     6,   357,   270,   270,   374,
     270,   266,     6,   269,     6,   375,   199,   287,   357,   274,
     274,   369,     6,   357,   357,     6,   270,   270,   306,     7,
     265,   270,   270,   270,   274,   357,   357,   270,   266,   269,
     270,   269,   367,   370,     6,   269,   367,     6,   270,   270,
     357,     6,   149,   270,   339,   269,     6,   270,     6,   329,
       6,   269,   357,   357,   270,   274,   310,   379,   266,   357,
     270,   270,   374,     6,   367,     6,   367,     6,     6,   270,
     357,   342,   329,   345,   284,   266,   274,     6,   269,   357,
     270,   274,   270,   274,   274,     6,   270,   270,   340,   270,
     270,   290,   357,   369,   270,   357,   367,   367,   342,     6,
       6,   269,   266,   270,     6,   300,   274,   274,   270,   288,
     378,   293,   269,   357,   357,   270,   274,   269,   369,   270,
     270,     6,   378,   291,   378,   270,     6,     6,   270,   274,
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
#line 275 "Gmsh.y"
    { yyerrok; return 1; ;}
    break;

  case 6:
#line 286 "Gmsh.y"
    { return 1; ;}
    break;

  case 7:
#line 287 "Gmsh.y"
    { return 1; ;}
    break;

  case 8:
#line 288 "Gmsh.y"
    { return 1; ;}
    break;

  case 9:
#line 290 "Gmsh.y"
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
#line 318 "Gmsh.y"
    { return 1; ;}
    break;

  case 11:
#line 319 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 12:
#line 320 "Gmsh.y"
    { return 1; ;}
    break;

  case 13:
#line 321 "Gmsh.y"
    { return 1; ;}
    break;

  case 14:
#line 322 "Gmsh.y"
    { return 1; ;}
    break;

  case 15:
#line 323 "Gmsh.y"
    { return 1; ;}
    break;

  case 16:
#line 324 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 17:
#line 325 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 18:
#line 326 "Gmsh.y"
    { return 1; ;}
    break;

  case 19:
#line 327 "Gmsh.y"
    { return 1; ;}
    break;

  case 20:
#line 328 "Gmsh.y"
    { return 1; ;}
    break;

  case 21:
#line 329 "Gmsh.y"
    { return 1; ;}
    break;

  case 22:
#line 330 "Gmsh.y"
    { return 1; ;}
    break;

  case 23:
#line 331 "Gmsh.y"
    { return 1; ;}
    break;

  case 24:
#line 332 "Gmsh.y"
    { return 1; ;}
    break;

  case 25:
#line 337 "Gmsh.y"
    {
      (yyval.c) = (char*)"w";
    ;}
    break;

  case 26:
#line 341 "Gmsh.y"
    {
      (yyval.c) = (char*)"a";
    ;}
    break;

  case 27:
#line 348 "Gmsh.y"
    {
      Msg::Direct((yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 28:
#line 353 "Gmsh.y"
    {
      Msg::Warning((yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 29:
#line 358 "Gmsh.y"
    {
      Msg::Error((yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 30:
#line 363 "Gmsh.y"
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
#line 377 "Gmsh.y"
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
#line 390 "Gmsh.y"
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
#line 403 "Gmsh.y"
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
#line 416 "Gmsh.y"
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
#line 444 "Gmsh.y"
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
#line 458 "Gmsh.y"
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
#line 471 "Gmsh.y"
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
#line 484 "Gmsh.y"
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
#line 502 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData = new PViewDataList();
#endif
    ;}
    break;

  case 46:
#line 517 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(1) - (1)].d)); ;}
    break;

  case 47:
#line 519 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(3) - (3)].d)); ;}
    break;

  case 48:
#line 524 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(1) - (1)].d)); ;}
    break;

  case 49:
#line 526 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(3) - (3)].d)); ;}
    break;

  case 50:
#line 531 "Gmsh.y"
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

  case 51:
#line 635 "Gmsh.y"
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

  case 52:
#line 645 "Gmsh.y"
    {
#if defined(HAVE_POST)
      if(ViewValueList) (*ViewNumList)++;
#endif
    ;}
    break;

  case 53:
#line 654 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[(1) - (1)].c)[i]);
#endif
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 54:
#line 661 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[(3) - (3)].c)[i]);
#endif
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 55:
#line 671 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->T2D.push_back((yyvsp[(3) - (8)].d));
      ViewData->T2D.push_back((yyvsp[(5) - (8)].d));
      ViewData->T2D.push_back((yyvsp[(7) - (8)].d));
      ViewData->T2D.push_back(ViewData->T2C.size());
#endif
    ;}
    break;

  case 56:
#line 680 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->NbT2++;
#endif
    ;}
    break;

  case 57:
#line 689 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[(1) - (1)].c)[i]);
#endif
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 58:
#line 696 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[(3) - (3)].c)[i]);
#endif
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 59:
#line 706 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->T3D.push_back((yyvsp[(3) - (10)].d)); ViewData->T3D.push_back((yyvsp[(5) - (10)].d));
      ViewData->T3D.push_back((yyvsp[(7) - (10)].d)); ViewData->T3D.push_back((yyvsp[(9) - (10)].d));
      ViewData->T3D.push_back(ViewData->T3C.size());
#endif
    ;}
    break;

  case 60:
#line 714 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->NbT3++;
#endif
    ;}
    break;

  case 61:
#line 724 "Gmsh.y"
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

  case 62:
#line 743 "Gmsh.y"
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

  case 63:
#line 762 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewValueList = &ViewData->Time;
#endif
    ;}
    break;

  case 64:
#line 768 "Gmsh.y"
    {
    ;}
    break;

  case 65:
#line 775 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 66:
#line 776 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 67:
#line 777 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 68:
#line 778 "Gmsh.y"
    { (yyval.i) = 3; ;}
    break;

  case 69:
#line 779 "Gmsh.y"
    { (yyval.i) = 4; ;}
    break;

  case 70:
#line 783 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 71:
#line 784 "Gmsh.y"
    { (yyval.i) = -1; ;}
    break;

  case 72:
#line 790 "Gmsh.y"
    { (yyval.c) = (char*)"("; ;}
    break;

  case 73:
#line 790 "Gmsh.y"
    { (yyval.c) = (char*)"["; ;}
    break;

  case 74:
#line 792 "Gmsh.y"
    { (yyval.c) = (char*)")"; ;}
    break;

  case 75:
#line 792 "Gmsh.y"
    { (yyval.c) = (char*)"]"; ;}
    break;

  case 76:
#line 797 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 77:
#line 798 "Gmsh.y"
    { (yyval.c) = (char *)Malloc(4 * sizeof(char)); strcpy((yyval.c), "Min"); ;}
    break;

  case 78:
#line 799 "Gmsh.y"
    { (yyval.c) = (char *)Malloc(4 * sizeof(char)); strcpy((yyval.c), "Max"); ;}
    break;

  case 79:
#line 800 "Gmsh.y"
    { (yyval.c) = (char *)Malloc(5 * sizeof(char)); strcpy((yyval.c), "Step"); ;}
    break;

  case 80:
#line 801 "Gmsh.y"
    { (yyval.c) = (char *)Malloc(4 * sizeof(char)); strcpy((yyval.c), "Box"); ;}
    break;

  case 81:
#line 802 "Gmsh.y"
    { (yyval.c) = (char *)Malloc(9 * sizeof(char)); strcpy((yyval.c), "Cylinder"); ;}
    break;

  case 85:
#line 812 "Gmsh.y"
    {
      Msg::SetOnelabNumber((yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].d));
      Free((yyvsp[(3) - (7)].c));
    ;}
    break;

  case 86:
#line 817 "Gmsh.y"
    {
      Msg::SetOnelabString((yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].c));
      Free((yyvsp[(3) - (7)].c));
      Free((yyvsp[(5) - (7)].c));
    ;}
    break;

  case 87:
#line 823 "Gmsh.y"
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
#line 884 "Gmsh.y"
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
#line 899 "Gmsh.y"
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
#line 927 "Gmsh.y"
    {
      assignVariables((yyvsp[(1) - (9)].c), (yyvsp[(4) - (9)].l), (yyvsp[(7) - (9)].i), (yyvsp[(8) - (9)].l));
      Free((yyvsp[(1) - (9)].c));
      List_Delete((yyvsp[(4) - (9)].l));
      List_Delete((yyvsp[(8) - (9)].l));
    ;}
    break;

  case 91:
#line 937 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    ;}
    break;

  case 92:
#line 942 "Gmsh.y"
    {
      incrementVariable((yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].i));
      Free((yyvsp[(1) - (6)].c));
    ;}
    break;

  case 93:
#line 950 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    ;}
    break;

  case 94:
#line 955 "Gmsh.y"
    {
      incrementVariable((yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].i));
      Free((yyvsp[(1) - (6)].c));
    ;}
    break;

  case 95:
#line 963 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[(1) - (4)].c)] = std::vector<std::string>(1, (yyvsp[(3) - (4)].c));
      Free((yyvsp[(1) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 96:
#line 972 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[(1) - (8)].c)] = std::vector<std::string>();
      Free((yyvsp[(1) - (8)].c));
    ;}
    break;

  case 97:
#line 977 "Gmsh.y"
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
#line 989 "Gmsh.y"
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
#line 1006 "Gmsh.y"
    {
      std::string tmp((yyvsp[(5) - (6)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (6)].c), 0, (yyvsp[(3) - (6)].c), tmp);
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 100:
#line 1012 "Gmsh.y"
    {
      std::string tmp((yyvsp[(8) - (9)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (9)].c), (int)(yyvsp[(3) - (9)].d), (yyvsp[(6) - (9)].c), tmp);
      Free((yyvsp[(1) - (9)].c)); Free((yyvsp[(6) - (9)].c)); Free((yyvsp[(8) - (9)].c));
    ;}
    break;

  case 101:
#line 1021 "Gmsh.y"
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
#line 1039 "Gmsh.y"
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
#line 1057 "Gmsh.y"
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
#line 1066 "Gmsh.y"
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
#line 1078 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (8)].c), 0, (yyvsp[(5) - (8)].c), (yyvsp[(7) - (8)].u));
      Free((yyvsp[(1) - (8)].c)); Free((yyvsp[(5) - (8)].c));
    ;}
    break;

  case 106:
#line 1083 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (11)].c), (int)(yyvsp[(3) - (11)].d), (yyvsp[(8) - (11)].c), (yyvsp[(10) - (11)].u));
      Free((yyvsp[(1) - (11)].c)); Free((yyvsp[(8) - (11)].c));
    ;}
    break;

  case 107:
#line 1091 "Gmsh.y"
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
#line 1111 "Gmsh.y"
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
#line 1134 "Gmsh.y"
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
#line 1154 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      if(!GModel::current()->getFields()->newField((int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c)))
	yymsg(0, "Cannot create field %i of type '%s'", (int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c));
#endif
      Free((yyvsp[(6) - (7)].c));
    ;}
    break;

  case 111:
#line 1162 "Gmsh.y"
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
#line 1179 "Gmsh.y"
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
#line 1197 "Gmsh.y"
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
#line 1235 "Gmsh.y"
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
#line 1256 "Gmsh.y"
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
#line 1268 "Gmsh.y"
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
#line 1286 "Gmsh.y"
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
#line 1295 "Gmsh.y"
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
#line 1304 "Gmsh.y"
    { init_options(); ;}
    break;

  case 123:
#line 1306 "Gmsh.y"
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
#line 1324 "Gmsh.y"
    { init_options(); ;}
    break;

  case 125:
#line 1326 "Gmsh.y"
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
#line 1342 "Gmsh.y"
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
#line 1351 "Gmsh.y"
    { init_options(); ;}
    break;

  case 128:
#line 1353 "Gmsh.y"
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
#line 1367 "Gmsh.y"
    {
      std::string name((yyvsp[(3) - (3)].c));
      Msg::UndefineOnelabParameter(name);
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 131:
#line 1375 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(doubleXstring));
      doubleXstring v = {(yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].c)};
      List_Add((yyval.l), &v);
    ;}
    break;

  case 132:
#line 1381 "Gmsh.y"
    {
      doubleXstring v = {(yyvsp[(3) - (5)].d), (yyvsp[(5) - (5)].c)};
      List_Add((yyval.l), &v);
    ;}
    break;

  case 133:
#line 1386 "Gmsh.y"
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
#line 1429 "Gmsh.y"
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
#line 1441 "Gmsh.y"
    {
      floatOptions["Min"].push_back((yyvsp[(2) - (2)].d));
    ;}
    break;

  case 142:
#line 1445 "Gmsh.y"
    {
      floatOptions["Max"].push_back((yyvsp[(2) - (2)].d));
    ;}
    break;

  case 143:
#line 1449 "Gmsh.y"
    {
      floatOptions["Step"].push_back((yyvsp[(2) - (2)].d));
    ;}
    break;

  case 144:
#line 1453 "Gmsh.y"
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
#line 1466 "Gmsh.y"
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
#line 1480 "Gmsh.y"
    {
      std::string key((yyvsp[(1) - (2)].c));
      std::string val((yyvsp[(2) - (2)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(1) - (2)].c));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 147:
#line 1488 "Gmsh.y"
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
#line 1513 "Gmsh.y"
    {
      std::string key((yyvsp[(1) - (2)].c));
      double val = (yyvsp[(2) - (2)].d);
      floatOptions[key].push_back(val);
      Free((yyvsp[(1) - (2)].c));
    ;}
    break;

  case 153:
#line 1521 "Gmsh.y"
    {
      std::string key((yyvsp[(1) - (2)].c));
      std::string val((yyvsp[(2) - (2)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(1) - (2)].c));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 154:
#line 1530 "Gmsh.y"
    {
      std::string key("Macro");
      std::string val((yyvsp[(2) - (2)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 155:
#line 1538 "Gmsh.y"
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
#line 1552 "Gmsh.y"
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
#line 1570 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    ;}
    break;

  case 158:
#line 1574 "Gmsh.y"
    {
      int t = GModel::current()->getGEOInternals()->getMaxPhysicalTag();
      GModel::current()->getGEOInternals()->setMaxPhysicalTag(t + 1);
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (1)].c)), dim_entity, t + 1);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 159:
#line 1581 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (3)].c)), dim_entity, (yyvsp[(3) - (3)].d));
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 160:
#line 1589 "Gmsh.y"
    {
      (yyval.l) = 0;
    ;}
    break;

  case 161:
#line 1593 "Gmsh.y"
    {
      (yyval.l) = List_Create(1, 1, sizeof(double));
      double p = (yyvsp[(4) - (5)].d);
      List_Add((yyval.l), &p);
    ;}
    break;

  case 162:
#line 1599 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
    ;}
    break;

  case 163:
#line 1603 "Gmsh.y"
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
#line 1614 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = 0.;
    ;}
    break;

  case 165:
#line 1618 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 166:
#line 1624 "Gmsh.y"
    {
      (yyval.d) = 0;
    ;}
    break;

  case 167:
#line 1628 "Gmsh.y"
    {
      (yyval.d) = 1;
    ;}
    break;

  case 168:
#line 1634 "Gmsh.y"
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
#line 1657 "Gmsh.y"
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
#line 1673 "Gmsh.y"
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
#line 1689 "Gmsh.y"
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
#line 1706 "Gmsh.y"
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
#line 1723 "Gmsh.y"
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
#line 1760 "Gmsh.y"
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
#line 1804 "Gmsh.y"
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
#line 1820 "Gmsh.y"
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
#line 1837 "Gmsh.y"
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
#line 1868 "Gmsh.y"
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
#line 1884 "Gmsh.y"
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
#line 1901 "Gmsh.y"
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
#line 1917 "Gmsh.y"
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
#line 1967 "Gmsh.y"
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
#line 1985 "Gmsh.y"
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
#line 2006 "Gmsh.y"
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
#line 2027 "Gmsh.y"
    {
      myGmshSurface = 0;
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 186:
#line 2033 "Gmsh.y"
    {
      myGmshSurface = gmshSurface::getSurface((int)(yyvsp[(3) - (4)].d));
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 187:
#line 2039 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (10)].d);
      myGmshSurface = gmshParametricSurface::NewParametricSurface(num, (yyvsp[(7) - (10)].c), (yyvsp[(8) - (10)].c), (yyvsp[(9) - (10)].c));
      (yyval.s).Type = 0;
      (yyval.s).Num = num;
    ;}
    break;

  case 188:
#line 2046 "Gmsh.y"
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

  case 189:
#line 2077 "Gmsh.y"
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
#line 2092 "Gmsh.y"
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

  case 191:
#line 2114 "Gmsh.y"
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

  case 192:
#line 2137 "Gmsh.y"
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

  case 193:
#line 2160 "Gmsh.y"
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

  case 194:
#line 2183 "Gmsh.y"
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

  case 195:
#line 2207 "Gmsh.y"
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

  case 196:
#line 2231 "Gmsh.y"
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
#line 2255 "Gmsh.y"
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
#line 2281 "Gmsh.y"
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
#line 2298 "Gmsh.y"
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
#line 2314 "Gmsh.y"
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
#line 2332 "Gmsh.y"
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
#line 2350 "Gmsh.y"
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
#line 2363 "Gmsh.y"
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
#line 2375 "Gmsh.y"
    {
      dim_entity = (yyvsp[(2) - (2)].i);
    ;}
    break;

  case 205:
#line 2379 "Gmsh.y"
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
#line 2405 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 207:
#line 2407 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 208:
#line 2409 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 209:
#line 2411 "Gmsh.y"
    { (yyval.i) = 3; ;}
    break;

  case 210:
#line 2413 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(3) - (4)].d);
      if((yyval.i) < 0 || (yyval.i) > 3) yymsg(0, "GeoEntity dim out of range [0,3]");
    ;}
    break;

  case 211:
#line 2421 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 212:
#line 2423 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 213:
#line 2425 "Gmsh.y"
    { (yyval.i) = 3; ;}
    break;

  case 214:
#line 2427 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(3) - (4)].d);
      if((yyval.i)<1 || (yyval.i)>3) yymsg(0, "GeoEntity dim out of range [1,3]");
    ;}
    break;

  case 215:
#line 2435 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 216:
#line 2437 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 217:
#line 2439 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(3) - (4)].d);
      if((yyval.i)<1 || (yyval.i)>2) yymsg(0, "GeoEntity dim out of range [1,2]");
    ;}
    break;

  case 218:
#line 2447 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 219:
#line 2449 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 220:
#line 2451 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 221:
#line 2453 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(3) - (4)].d);
      if((yyval.i) < 0 || (yyval.i) > 2) yymsg(0, "GeoEntity dim out of range [0,2]");
    ;}
    break;

  case 222:
#line 2463 "Gmsh.y"
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
#line 2479 "Gmsh.y"
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
#line 2495 "Gmsh.y"
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
#line 2511 "Gmsh.y"
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
#line 2527 "Gmsh.y"
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
#line 2543 "Gmsh.y"
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
#line 2560 "Gmsh.y"
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
#line 2586 "Gmsh.y"
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

  case 230:
#line 2628 "Gmsh.y"
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
#line 2649 "Gmsh.y"
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
#line 2670 "Gmsh.y"
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
#line 2695 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 234:
#line 2696 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 235:
#line 2701 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    ;}
    break;

  case 236:
#line 2705 "Gmsh.y"
    {
      List_Add((yyval.l), &(yyvsp[(2) - (2)].s));
    ;}
    break;

  case 237:
#line 2709 "Gmsh.y"
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
#line 2726 "Gmsh.y"
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
#line 2746 "Gmsh.y"
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

  case 240:
#line 2766 "Gmsh.y"
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

  case 241:
#line 2785 "Gmsh.y"
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

  case 242:
#line 2812 "Gmsh.y"
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

  case 243:
#line 2837 "Gmsh.y"
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

  case 244:
#line 2862 "Gmsh.y"
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

  case 245:
#line 2874 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      GModel::current()->getFields()->deleteField((int)(yyvsp[(4) - (6)].d));
#endif
    ;}
    break;

  case 246:
#line 2880 "Gmsh.y"
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

  case 247:
#line 2895 "Gmsh.y"
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

  case 248:
#line 2926 "Gmsh.y"
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

  case 249:
#line 2938 "Gmsh.y"
    {
      gmsh_yynamespaces.clear();
    ;}
    break;

  case 250:
#line 2947 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), dimTags);
      setColor(dimTags, (yyvsp[(2) - (5)].u), false);
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 251:
#line 2954 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(5) - (6)].l), dimTags);
      setColor(dimTags, (yyvsp[(3) - (6)].u), true);
      List_Delete((yyvsp[(5) - (6)].l));
    ;}
    break;

  case 252:
#line 2966 "Gmsh.y"
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

  case 253:
#line 2986 "Gmsh.y"
    {
      setVisibility(-1, 1, false);
    ;}
    break;

  case 254:
#line 2990 "Gmsh.y"
    {
      setVisibility(-1, 1, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 255:
#line 2995 "Gmsh.y"
    {
      setVisibility(-1, 0, false);
    ;}
    break;

  case 256:
#line 2999 "Gmsh.y"
    {
      setVisibility(-1, 0, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 257:
#line 3004 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(3) - (4)].l), dimTags);
      setVisibility(dimTags, 1, false);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 258:
#line 3011 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), dimTags);
      setVisibility(dimTags, 1, true);
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 259:
#line 3018 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(3) - (4)].l), dimTags);
      setVisibility(dimTags, 0, false);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 260:
#line 3025 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), dimTags);
      setVisibility(dimTags, 0, true);
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 261:
#line 3037 "Gmsh.y"
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

  case 262:
#line 3110 "Gmsh.y"
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

  case 263:
#line 3128 "Gmsh.y"
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

  case 264:
#line 3153 "Gmsh.y"
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

  case 265:
#line 3168 "Gmsh.y"
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

  case 266:
#line 3220 "Gmsh.y"
    {
#if defined(HAVE_FLTK)
      FlGui::instance()->splitCurrentOpenglWindow('u');
#endif
    ;}
    break;

  case 267:
#line 3226 "Gmsh.y"
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

  case 268:
#line 3238 "Gmsh.y"
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

  case 269:
#line 3270 "Gmsh.y"
    {
      Msg::Exit(0, false); // will return 0 only if no meshing error occurred
    ;}
    break;

  case 270:
#line 3274 "Gmsh.y"
    {
      Msg::Exit((int)(yyvsp[(2) - (3)].d), true); // will always return the specified value
    ;}
    break;

  case 271:
#line 3278 "Gmsh.y"
    {
      gmsh_yyerrorstate = 999; // this will be checked when yyparse returns
      YYABORT;
    ;}
    break;

  case 272:
#line 3283 "Gmsh.y"
    {
      // force sync
      if(GModel::current()->getOCCInternals())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      GModel::current()->getGEOInternals()->synchronize(GModel::current());
    ;}
    break;

  case 273:
#line 3290 "Gmsh.y"
    {
      new GModel();
      GModel::current(GModel::list.size() - 1);
    ;}
    break;

  case 274:
#line 3295 "Gmsh.y"
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

  case 275:
#line 3305 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 1;
      SetBoundingBox((yyvsp[(3) - (15)].d), (yyvsp[(5) - (15)].d), (yyvsp[(7) - (15)].d), (yyvsp[(9) - (15)].d), (yyvsp[(11) - (15)].d), (yyvsp[(13) - (15)].d));
    ;}
    break;

  case 276:
#line 3310 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
      drawContext::global()->draw(false); // not rate limited
#endif
    ;}
    break;

  case 277:
#line 3316 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
     CTX::instance()->mesh.changed = ENT_ALL;
     for(std::size_t index = 0; index < PView::list.size(); index++)
       PView::list[index]->setChanged(true);
#endif
    ;}
    break;

  case 278:
#line 3324 "Gmsh.y"
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

  case 279:
#line 3335 "Gmsh.y"
    {
      GModel::current()->makeDiscreteRegionsSimplyConnected();
      GModel::current()->makeDiscreteFacesSimplyConnected();
      GModel::current()->createTopologyFromMesh();
      // Warning: this clears GEO_Internals!
      GModel::current()->exportDiscreteGEOInternals();
    ;}
    break;

  case 280:
#line 3343 "Gmsh.y"
    {
      GModel::current()->classifySurfaces((yyvsp[(3) - (9)].d), (yyvsp[(5) - (9)].d), (yyvsp[(7) - (9)].d), M_PI);
    ;}
    break;

  case 281:
#line 3347 "Gmsh.y"
    {
      GModel::current()->classifySurfaces((yyvsp[(3) - (11)].d), (yyvsp[(5) - (11)].d), (yyvsp[(7) - (11)].d), (yyvsp[(9) - (11)].d));
    ;}
    break;

  case 282:
#line 3351 "Gmsh.y"
    {
      GModel::current()->createGeometryOfDiscreteEntities();
    ;}
    break;

  case 283:
#line 3355 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(3) - (4)].l), dimTags);
      GModel::current()->createGeometryOfDiscreteEntities(dimTags);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 284:
#line 3362 "Gmsh.y"
    {
      GModel::current()->renumberMeshVertices();
    ;}
    break;

  case 285:
#line 3366 "Gmsh.y"
    {
      GModel::current()->renumberMeshElements();
    ;}
    break;

  case 286:
#line 3370 "Gmsh.y"
    {
      GModel::current()->createMEdges();
    ;}
    break;

  case 287:
#line 3374 "Gmsh.y"
    {
      GModel::current()->createMFaces();
    ;}
    break;

  case 288:
#line 3378 "Gmsh.y"
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

  case 289:
#line 3390 "Gmsh.y"
    {
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      if(GModel::current()->getGEOInternals()->getChanged())
        GModel::current()->getGEOInternals()->synchronize(GModel::current());
      GModel::current()->recombineMesh();
    ;}
    break;

  case 290:
#line 3399 "Gmsh.y"
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

  case 291:
#line 3419 "Gmsh.y"
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

  case 292:
#line 3445 "Gmsh.y"
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
#line 3461 "Gmsh.y"
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
#line 3478 "Gmsh.y"
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
#line 3495 "Gmsh.y"
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
#line 3517 "Gmsh.y"
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
#line 3539 "Gmsh.y"
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
#line 3574 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip(nullptr, "Return");
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 299:
#line 3582 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip(nullptr, "Return");
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 300:
#line 3590 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    ;}
    break;

  case 301:
#line 3596 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function '%s'", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 302:
#line 3603 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function '%s'", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 303:
#line 3610 "Gmsh.y"
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
#line 3630 "Gmsh.y"
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

  case 305:
#line 3656 "Gmsh.y"
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
#line 3668 "Gmsh.y"
    {
      ImbricatedTest--;
      if(ImbricatedTest < 0)
        yymsg(1, "Orphan EndIf");
    ;}
    break;

  case 307:
#line 3679 "Gmsh.y"
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
#line 3697 "Gmsh.y"
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
#line 3715 "Gmsh.y"
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
#line 3733 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 311:
#line 3739 "Gmsh.y"
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
#line 3757 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 313:
#line 3763 "Gmsh.y"
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
#line 3783 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 315:
#line 3789 "Gmsh.y"
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
#line 3807 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 317:
#line 3813 "Gmsh.y"
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
#line 3830 "Gmsh.y"
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
#line 3846 "Gmsh.y"
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
#line 3863 "Gmsh.y"
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
#line 3881 "Gmsh.y"
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
#line 3904 "Gmsh.y"
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
#line 3931 "Gmsh.y"
    {
    ;}
    break;

  case 324:
#line 3934 "Gmsh.y"
    {
    ;}
    break;

  case 325:
#line 3940 "Gmsh.y"
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
#line 3952 "Gmsh.y"
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
#line 3972 "Gmsh.y"
    {
      extr.mesh.ScaleLast = true;
    ;}
    break;

  case 328:
#line 3976 "Gmsh.y"
    {
      extr.mesh.Recombine = true;
    ;}
    break;

  case 329:
#line 3980 "Gmsh.y"
    {
      extr.mesh.Recombine = (yyvsp[(2) - (3)].d) ? true : false;
    ;}
    break;

  case 330:
#line 3984 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1;
    ;}
    break;

  case 331:
#line 3988 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1_RECOMB;
    ;}
    break;

  case 332:
#line 3992 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1;
    ;}
    break;

  case 333:
#line 3996 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1_RECOMB;
    ;}
    break;

  case 334:
#line 4000 "Gmsh.y"
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
#line 4009 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (6)].c), "Index"))
        extr.mesh.BoundaryLayerIndex = (yyvsp[(4) - (6)].d);
      else if(!strcmp((yyvsp[(2) - (6)].c), "View"))
        extr.mesh.ViewIndex = (yyvsp[(4) - (6)].d);
      Free((yyvsp[(2) - (6)].c));
    ;}
    break;

  case 336:
#line 4021 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Union; ;}
    break;

  case 337:
#line 4022 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Intersection; ;}
    break;

  case 338:
#line 4023 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Difference; ;}
    break;

  case 339:
#line 4024 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Section; ;}
    break;

  case 340:
#line 4025 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Fragments; ;}
    break;

  case 341:
#line 4029 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 342:
#line 4030 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 343:
#line 4031 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 344:
#line 4032 "Gmsh.y"
    { (yyval.i) = (yyvsp[(2) - (3)].d) ? 1 : 0; ;}
    break;

  case 345:
#line 4033 "Gmsh.y"
    { (yyval.i) = (yyvsp[(3) - (4)].d) ? 2 : 0; ;}
    break;

  case 346:
#line 4038 "Gmsh.y"
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
#line 4061 "Gmsh.y"
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
#line 4081 "Gmsh.y"
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
#line 4102 "Gmsh.y"
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    ;}
    break;

  case 350:
#line 4106 "Gmsh.y"
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

  case 351:
#line 4133 "Gmsh.y"
    {
      (yyval.i) = -1; // left
    ;}
    break;

  case 352:
#line 4137 "Gmsh.y"
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
#line 4153 "Gmsh.y"
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   ;}
    break;

  case 354:
#line 4157 "Gmsh.y"
    {
     (yyval.l) = (yyvsp[(2) - (2)].l);
   ;}
    break;

  case 355:
#line 4162 "Gmsh.y"
    {
      (yyval.i) = 45;
    ;}
    break;

  case 356:
#line 4166 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(2) - (2)].d);
    ;}
    break;

  case 357:
#line 4172 "Gmsh.y"
    {
      (yyval.l) = List_Create(1, 1, sizeof(double));
    ;}
    break;

  case 358:
#line 4176 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
    ;}
    break;

  case 359:
#line 4183 "Gmsh.y"
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

  case 360:
#line 4206 "Gmsh.y"
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

  case 361:
#line 4225 "Gmsh.y"
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

  case 362:
#line 4266 "Gmsh.y"
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

  case 363:
#line 4311 "Gmsh.y"
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

  case 364:
#line 4351 "Gmsh.y"
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

  case 365:
#line 4376 "Gmsh.y"
    {
      int dim = (int)(yyvsp[(2) - (8)].i);
      int tag = (int)(yyvsp[(4) - (8)].d);
      int new_tag = (int)(yyvsp[(6) - (8)].d);
      GModel::current()->changeEntityTag(dim, tag, new_tag);
    ;}
    break;

  case 366:
#line 4383 "Gmsh.y"
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

  case 367:
#line 4394 "Gmsh.y"
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

  case 368:
#line 4411 "Gmsh.y"
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

  case 369:
#line 4428 "Gmsh.y"
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

  case 370:
#line 4458 "Gmsh.y"
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

  case 371:
#line 4484 "Gmsh.y"
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

  case 372:
#line 4511 "Gmsh.y"
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

  case 373:
#line 4543 "Gmsh.y"
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

  case 374:
#line 4571 "Gmsh.y"
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

  case 375:
#line 4597 "Gmsh.y"
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

  case 376:
#line 4623 "Gmsh.y"
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

  case 377:
#line 4649 "Gmsh.y"
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

  case 378:
#line 4675 "Gmsh.y"
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

  case 379:
#line 4696 "Gmsh.y"
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

  case 380:
#line 4708 "Gmsh.y"
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

  case 381:
#line 4756 "Gmsh.y"
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

  case 382:
#line 4810 "Gmsh.y"
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

  case 383:
#line 4825 "Gmsh.y"
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

  case 384:
#line 4837 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (4)].l), tags);
      GModel::current()->getGEOInternals()->setCompoundMesh((yyvsp[(2) - (4)].i), tags);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 385:
#line 4843 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (6)].l), tags);
      tags.push_back(- (int) (yyvsp[(5) - (6)].d));
      GModel::current()->getGEOInternals()->setCompoundMesh((yyvsp[(2) - (6)].i), tags);
      List_Delete((yyvsp[(3) - (6)].l));
    ;}
    break;

  case 386:
#line 4855 "Gmsh.y"
    {
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals())
        GModel::current()->getOCCInternals()->removeAllDuplicates();
      else
        GModel::current()->getGEOInternals()->removeAllDuplicates();
    ;}
    break;

  case 387:
#line 4862 "Gmsh.y"
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

  case 388:
#line 4877 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(4) - (6)].l), tags);
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals())
        GModel::current()->getOCCInternals()->mergeVertices(tags);
      else
        GModel::current()->getGEOInternals()->mergeVertices(tags);
      List_Delete((yyvsp[(4) - (6)].l));
    ;}
    break;

  case 389:
#line 4886 "Gmsh.y"
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

  case 390:
#line 4906 "Gmsh.y"
    { (yyval.c) = (char*)"Homology"; ;}
    break;

  case 391:
#line 4907 "Gmsh.y"
    { (yyval.c) = (char*)"Cohomology"; ;}
    break;

  case 392:
#line 4908 "Gmsh.y"
    { (yyval.c) = (char*)"Betti"; ;}
    break;

  case 393:
#line 4913 "Gmsh.y"
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest((yyvsp[(1) - (2)].c), domain, subdomain, dim);
    ;}
    break;

  case 394:
#line 4919 "Gmsh.y"
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
#line 4931 "Gmsh.y"
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
#line 4949 "Gmsh.y"
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
#line 4976 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d);           ;}
    break;

  case 398:
#line 4977 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (3)].d);           ;}
    break;

  case 399:
#line 4978 "Gmsh.y"
    { (yyval.d) = -(yyvsp[(2) - (2)].d);          ;}
    break;

  case 400:
#line 4979 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);           ;}
    break;

  case 401:
#line 4980 "Gmsh.y"
    { (yyval.d) = !(yyvsp[(2) - (2)].d);          ;}
    break;

  case 402:
#line 4981 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) - (yyvsp[(3) - (3)].d);      ;}
    break;

  case 403:
#line 4982 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) + (yyvsp[(3) - (3)].d);      ;}
    break;

  case 404:
#line 4983 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) * (yyvsp[(3) - (3)].d);      ;}
    break;

  case 405:
#line 4985 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (3)].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));
      else
	(yyval.d) = (yyvsp[(1) - (3)].d) / (yyvsp[(3) - (3)].d);
    ;}
    break;

  case 406:
#line 4991 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) | (int)(yyvsp[(3) - (3)].d); ;}
    break;

  case 407:
#line 4992 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) & (int)(yyvsp[(3) - (3)].d); ;}
    break;

  case 408:
#line 4993 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) % (int)(yyvsp[(3) - (3)].d); ;}
    break;

  case 409:
#line 4994 "Gmsh.y"
    { (yyval.d) = pow((yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));  ;}
    break;

  case 410:
#line 4995 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d);      ;}
    break;

  case 411:
#line 4996 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) > (yyvsp[(3) - (3)].d);      ;}
    break;

  case 412:
#line 4997 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) <= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 413:
#line 4998 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) >= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 414:
#line 4999 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) == (yyvsp[(3) - (3)].d);     ;}
    break;

  case 415:
#line 5000 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) != (yyvsp[(3) - (3)].d);     ;}
    break;

  case 416:
#line 5001 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) && (yyvsp[(3) - (3)].d);     ;}
    break;

  case 417:
#line 5002 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) || (yyvsp[(3) - (3)].d);     ;}
    break;

  case 418:
#line 5003 "Gmsh.y"
    { (yyval.d) = ((int)(yyvsp[(1) - (3)].d) >> (int)(yyvsp[(3) - (3)].d)); ;}
    break;

  case 419:
#line 5004 "Gmsh.y"
    { (yyval.d) = ((int)(yyvsp[(1) - (3)].d) << (int)(yyvsp[(3) - (3)].d)); ;}
    break;

  case 420:
#line 5005 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (5)].d) ? (yyvsp[(3) - (5)].d) : (yyvsp[(5) - (5)].d); ;}
    break;

  case 421:
#line 5006 "Gmsh.y"
    { (yyval.d) = ((yyvsp[(3) - (4)].d) < 0) ? 0 : 1; ;}
    break;

  case 422:
#line 5007 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 423:
#line 5008 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 424:
#line 5009 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 425:
#line 5010 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 426:
#line 5011 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 427:
#line 5012 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 428:
#line 5013 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 429:
#line 5014 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 430:
#line 5015 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 431:
#line 5016 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 432:
#line 5017 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 433:
#line 5018 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 434:
#line 5019 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 435:
#line 5020 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 436:
#line 5021 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 437:
#line 5022 "Gmsh.y"
    { (yyval.d) = std::abs((yyvsp[(3) - (4)].d)); ;}
    break;

  case 438:
#line 5023 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 439:
#line 5024 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 440:
#line 5025 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d) + 0.5); ;}
    break;

  case 441:
#line 5026 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 442:
#line 5027 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 443:
#line 5028 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 444:
#line 5029 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 445:
#line 5030 "Gmsh.y"
    { (yyval.d) = std::max((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 446:
#line 5031 "Gmsh.y"
    { (yyval.d) = std::min((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 447:
#line 5040 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 448:
#line 5041 "Gmsh.y"
    { (yyval.d) = 3.141592653589793; ;}
    break;

  case 449:
#line 5042 "Gmsh.y"
    { (yyval.d) = (double)ImbricatedTest; ;}
    break;

  case 450:
#line 5043 "Gmsh.y"
    { (yyval.d) = Msg::GetCommRank(); ;}
    break;

  case 451:
#line 5044 "Gmsh.y"
    { (yyval.d) = Msg::GetCommSize(); ;}
    break;

  case 452:
#line 5045 "Gmsh.y"
    { (yyval.d) = GetGmshMajorVersion(); ;}
    break;

  case 453:
#line 5046 "Gmsh.y"
    { (yyval.d) = GetGmshMinorVersion(); ;}
    break;

  case 454:
#line 5047 "Gmsh.y"
    { (yyval.d) = GetGmshPatchVersion(); ;}
    break;

  case 455:
#line 5048 "Gmsh.y"
    { (yyval.d) = Cpu(); ;}
    break;

  case 456:
#line 5049 "Gmsh.y"
    { (yyval.d) = GetMemoryUsage()/1024./1024.; ;}
    break;

  case 457:
#line 5050 "Gmsh.y"
    { (yyval.d) = TotalRam(); ;}
    break;

  case 458:
#line 5055 "Gmsh.y"
    { init_options(); ;}
    break;

  case 459:
#line 5057 "Gmsh.y"
    {
      std::vector<double> val(1, (yyvsp[(3) - (6)].d));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.d) = val[0];
    ;}
    break;

  case 460:
#line 5063 "Gmsh.y"
    {
      (yyval.d) = (yyvsp[(1) - (1)].d);
    ;}
    break;

  case 461:
#line 5067 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 462:
#line 5072 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 463:
#line 5077 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(1) - (1)].c2).char1, (yyvsp[(1) - (1)].c2).char2);
    ;}
    break;

  case 464:
#line 5082 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float(nullptr, (yyvsp[(1) - (4)].c), 2, (int)(yyvsp[(3) - (4)].d));
    ;}
    break;

  case 465:
#line 5087 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float(nullptr, (yyvsp[(1) - (4)].c), 2, (int)(yyvsp[(3) - (4)].d));
    ;}
    break;

  case 466:
#line 5091 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(3) - (4)].c2).char1, (yyvsp[(3) - (4)].c2).char2, 1, 0, 0., 1);
    ;}
    break;

  case 467:
#line 5095 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(3) - (6)].c2).char1, (yyvsp[(3) - (6)].c2).char2, (yyvsp[(5) - (6)].c), 0, 0., 1);
    ;}
    break;

  case 468:
#line 5099 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(3) - (5)].c2).char1, (yyvsp[(3) - (5)].c2).char2, 1, 0, (yyvsp[(4) - (5)].d), 2);
    ;}
    break;

  case 469:
#line 5103 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(3) - (7)].c2).char1, (yyvsp[(3) - (7)].c2).char2, (yyvsp[(5) - (7)].c), 0, (yyvsp[(6) - (7)].d), 2);
    ;}
    break;

  case 470:
#line 5107 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(3) - (8)].c2).char1, (yyvsp[(3) - (8)].c2).char2, 2, (int)(yyvsp[(5) - (8)].d), (yyvsp[(7) - (8)].d), 2);
    ;}
    break;

  case 471:
#line 5111 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(3) - (10)].c2).char1, (yyvsp[(3) - (10)].c2).char2, (yyvsp[(5) - (10)].c), (int)(yyvsp[(7) - (10)].d), (yyvsp[(9) - (10)].d), 2);
    ;}
    break;

  case 472:
#line 5115 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.d) = !StatFile(tmp);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 473:
#line 5121 "Gmsh.y"
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

  case 474:
#line 5136 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float_getDim((yyvsp[(2) - (6)].c2).char1, (yyvsp[(2) - (6)].c2).char2, (yyvsp[(4) - (6)].c));
    ;}
    break;

  case 475:
#line 5140 "Gmsh.y"
    {
      std::string struct_namespace((yyvsp[(3) - (4)].c));
      (yyval.d) = (double)gmsh_yynamespaces[struct_namespace].size();
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 476:
#line 5146 "Gmsh.y"
    {
      std::string struct_namespace(std::string(""));
      (yyval.d) = (double)gmsh_yynamespaces[struct_namespace].size();
    ;}
    break;

  case 477:
#line 5151 "Gmsh.y"
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

  case 478:
#line 5170 "Gmsh.y"
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
#line 5190 "Gmsh.y"
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

  case 480:
#line 5211 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(nullptr, (yyvsp[(1) - (3)].c), (yyvsp[(3) - (3)].c));
    ;}
    break;

  case 481:
#line 5215 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c), (yyvsp[(5) - (5)].c));
    ;}
    break;

  case 482:
#line 5219 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(nullptr, (yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].c), (int)(yyvsp[(5) - (6)].d));
    ;}
    break;

  case 483:
#line 5223 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(1) - (8)].c), (yyvsp[(3) - (8)].c), (yyvsp[(5) - (8)].c), (int)(yyvsp[(7) - (8)].d));
    ;}
    break;

  case 484:
#line 5227 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(nullptr, (yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].c), (int)(yyvsp[(5) - (6)].d));
    ;}
    break;

  case 485:
#line 5231 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(1) - (8)].c), (yyvsp[(3) - (8)].c), (yyvsp[(5) - (8)].c), (int)(yyvsp[(7) - (8)].d));
    ;}
    break;

  case 486:
#line 5235 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), (yyval.d));
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 487:
#line 5240 "Gmsh.y"
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

  case 488:
#line 5250 "Gmsh.y"
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

  case 489:
#line 5260 "Gmsh.y"
    {
      (yyval.d) = Msg::GetValue((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 490:
#line 5265 "Gmsh.y"
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

  case 491:
#line 5276 "Gmsh.y"
    {
      std::string s((yyvsp[(3) - (6)].c)), substr((yyvsp[(5) - (6)].c));
      if(s.find(substr) != std::string::npos)
        (yyval.d) = 1.;
      else
        (yyval.d) = 0.;
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 492:
#line 5285 "Gmsh.y"
    {
      (yyval.d) = strlen((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 493:
#line 5290 "Gmsh.y"
    {
      (yyval.d) = strcmp((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 494:
#line 5295 "Gmsh.y"
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

  case 495:
#line 5322 "Gmsh.y"
    { (yyval.d) = 0.; ;}
    break;

  case 496:
#line 5324 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);;}
    break;

  case 497:
#line 5329 "Gmsh.y"
    { (yyval.c) = nullptr; ;}
    break;

  case 498:
#line 5331 "Gmsh.y"
    { (yyval.c) = (yyvsp[(2) - (2)].c);;}
    break;

  case 499:
#line 5336 "Gmsh.y"
    {
      std::string struct_namespace((yyvsp[(2) - (3)].c2).char1? (yyvsp[(2) - (3)].c2).char1 : std::string("")),
        struct_name((yyvsp[(2) - (3)].c2).char2);
      init_options
        (gmsh_yynamespaces.getMember_ValMax(struct_namespace, struct_name));
    ;}
    break;

  case 500:
#line 5343 "Gmsh.y"
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

  case 501:
#line 5359 "Gmsh.y"
    { (yyval.c2).char1 = nullptr; (yyval.c2).char2 = (yyvsp[(1) - (1)].c); ;}
    break;

  case 502:
#line 5361 "Gmsh.y"
    { (yyval.c2).char1 = (yyvsp[(1) - (3)].c); (yyval.c2).char2 = (yyvsp[(3) - (3)].c); ;}
    break;

  case 503:
#line 5366 "Gmsh.y"
    { (yyval.i) = 99; ;}
    break;

  case 504:
#line 5368 "Gmsh.y"
    { (yyval.i) = (int)(yyvsp[(2) - (2)].d); ;}
    break;

  case 505:
#line 5373 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 506:
#line 5375 "Gmsh.y"
    { (yyval.i) = (yyvsp[(2) - (3)].i); ;}
    break;

  case 507:
#line 5380 "Gmsh.y"
    {
      memcpy((yyval.v), (yyvsp[(1) - (1)].v), 5 * sizeof(double));
    ;}
    break;

  case 508:
#line 5384 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 509:
#line 5388 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 510:
#line 5392 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] - (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 511:
#line 5396 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] + (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 512:
#line 5403 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (11)].d);  (yyval.v)[1] = (yyvsp[(4) - (11)].d);  (yyval.v)[2] = (yyvsp[(6) - (11)].d);  (yyval.v)[3] = (yyvsp[(8) - (11)].d); (yyval.v)[4] = (yyvsp[(10) - (11)].d);
    ;}
    break;

  case 513:
#line 5407 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (9)].d);  (yyval.v)[1] = (yyvsp[(4) - (9)].d);  (yyval.v)[2] = (yyvsp[(6) - (9)].d);  (yyval.v)[3] = (yyvsp[(8) - (9)].d); (yyval.v)[4] = 1.0;
    ;}
    break;

  case 514:
#line 5411 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 515:
#line 5415 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 516:
#line 5422 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].l)));
    ;}
    break;

  case 517:
#line 5427 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].l)));
    ;}
    break;

  case 518:
#line 5434 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 519:
#line 5439 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 520:
#line 5443 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
    ;}
    break;

  case 521:
#line 5447 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 522:
#line 5451 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 523:
#line 5459 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (5)].d);
      }
    ;}
    break;

  case 524:
#line 5470 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
    ;}
    break;

  case 525:
#line 5474 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 526:
#line 5478 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 527:
#line 5489 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 528:
#line 5493 "Gmsh.y"
    {
      (yyval.l) = 0;
    ;}
    break;

  case 529:
#line 5497 "Gmsh.y"
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

  case 530:
#line 5511 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 531:
#line 5519 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (3)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (3)].d);
      }
    ;}
    break;

  case 532:
#line 5527 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      for(double d = (yyvsp[(1) - (3)].d); ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d <= (yyvsp[(3) - (3)].d)) : (d >= (yyvsp[(3) - (3)].d));
          ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d += 1.) : (d -= 1.))
	List_Add((yyval.l), &d);
    ;}
    break;

  case 533:
#line 5534 "Gmsh.y"
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

  case 534:
#line 5544 "Gmsh.y"
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

  case 535:
#line 5567 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags(0, (yyval.l));
    ;}
    break;

  case 536:
#line 5572 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags(0, (yyval.l));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 537:
#line 5578 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags((yyvsp[(1) - (4)].i), (yyval.l));
    ;}
    break;

  case 538:
#line 5583 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags((yyvsp[(1) - (2)].i), (yyval.l));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 539:
#line 5589 "Gmsh.y"
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

  case 540:
#line 5600 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getParentTags((yyvsp[(2) - (3)].i), (yyvsp[(3) - (3)].l), (yyval.l));
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 541:
#line 5606 "Gmsh.y"
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

  case 542:
#line 5620 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getBoundingBox((yyvsp[(2) - (5)].i), (yyvsp[(4) - (5)].l), (yyval.l));
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 543:
#line 5626 "Gmsh.y"
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

  case 544:
#line 5638 "Gmsh.y"
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

  case 545:
#line 5652 "Gmsh.y"
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

  case 546:
#line 5665 "Gmsh.y"
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

  case 547:
#line 5695 "Gmsh.y"
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

  case 548:
#line 5718 "Gmsh.y"
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

  case 549:
#line 5738 "Gmsh.y"
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

  case 550:
#line 5757 "Gmsh.y"
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

  case 551:
#line 5777 "Gmsh.y"
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

  case 552:
#line 5794 "Gmsh.y"
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

  case 553:
#line 5804 "Gmsh.y"
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

  case 554:
#line 5814 "Gmsh.y"
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

  case 555:
#line 5824 "Gmsh.y"
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

  case 556:
#line 5836 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfFloat(nullptr, (yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c));
    ;}
    break;

  case 557:
#line 5840 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfFloat((yyvsp[(1) - (7)].c), (yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].c));
    ;}
    break;

  case 558:
#line 5845 "Gmsh.y"
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

  case 559:
#line 5857 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 560:
#line 5861 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 561:
#line 5865 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (6)].l);
    ;}
    break;

  case 562:
#line 5869 "Gmsh.y"
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

  case 563:
#line 5887 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = (yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1);
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 564:
#line 5895 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = pow(10,(yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1));
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 565:
#line 5903 "Gmsh.y"
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

  case 566:
#line 5932 "Gmsh.y"
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

  case 567:
#line 5942 "Gmsh.y"
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

  case 568:
#line 5958 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
        double *d = (double*)List_Pointer((yyvsp[(3) - (4)].l), i);
        *d = std::abs(*d);
      }
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 569:
#line 5969 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 570:
#line 5974 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 571:
#line 5978 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].d)));
    ;}
    break;

  case 572:
#line 5982 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (3)].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 573:
#line 5994 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (9)].d), (int)(yyvsp[(4) - (9)].d), (int)(yyvsp[(6) - (9)].d), (int)(yyvsp[(8) - (9)].d));
    ;}
    break;

  case 574:
#line 5998 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (7)].d), (int)(yyvsp[(4) - (7)].d), (int)(yyvsp[(6) - (7)].d), 255);
    ;}
    break;

  case 575:
#line 6010 "Gmsh.y"
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

  case 576:
#line 6027 "Gmsh.y"
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(5) - (5)].c), val);
      (yyval.u) = val;
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(5) - (5)].c));
    ;}
    break;

  case 577:
#line 6037 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 578:
#line 6041 "Gmsh.y"
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

  case 579:
#line 6056 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].u)));
    ;}
    break;

  case 580:
#line 6061 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].u)));
    ;}
    break;

  case 581:
#line 6068 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 582:
#line 6072 "Gmsh.y"
    {
      // No need to extend to Struct_FullName (a Tag is not a String)
      (yyval.c) = treat_Struct_FullName_String(nullptr, (yyvsp[(1) - (1)].c));
    ;}
    break;

  case 583:
#line 6077 "Gmsh.y"
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

  case 584:
#line 6091 "Gmsh.y"
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

  case 585:
#line 6105 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String(nullptr, (yyvsp[(1) - (3)].c), (yyvsp[(3) - (3)].c));
    ;}
    break;

  case 586:
#line 6109 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c), (yyvsp[(5) - (5)].c));
    ;}
    break;

  case 587:
#line 6113 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String(nullptr, (yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].c), (int)(yyvsp[(5) - (6)].d));
    ;}
    break;

  case 588:
#line 6117 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(1) - (8)].c), (yyvsp[(3) - (8)].c), (yyvsp[(5) - (8)].c), (int)(yyvsp[(7) - (8)].d));
    ;}
    break;

  case 589:
#line 6121 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 590:
#line 6129 "Gmsh.y"
    {
      std::string name = GModel::current()->getElementaryName((yyvsp[(1) - (4)].i), (int)(yyvsp[(3) - (4)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 591:
#line 6135 "Gmsh.y"
    {
      std::string name = GModel::current()->getPhysicalName((yyvsp[(2) - (5)].i), (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 592:
#line 6144 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 593:
#line 6148 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 594:
#line 6152 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    ;}
    break;

  case 595:
#line 6160 "Gmsh.y"
    {
      std::string exe = Msg::GetExecutableName();
      (yyval.c) = (char *)Malloc(exe.size() + 1);
      strcpy((yyval.c), exe.c_str());
    ;}
    break;

  case 596:
#line 6166 "Gmsh.y"
    {
      std::string action = Msg::GetOnelabAction();
      (yyval.c) = (char *)Malloc(action.size() + 1);
      strcpy((yyval.c), action.c_str());
    ;}
    break;

  case 597:
#line 6172 "Gmsh.y"
    {
      (yyval.c) = strsave((char*)"Gmsh");
    ;}
    break;

  case 598:
#line 6176 "Gmsh.y"
    {
      std::string env = GetEnvironmentVar((yyvsp[(3) - (4)].c));
      (yyval.c) = (char *)Malloc((env.size() + 1) * sizeof(char));
      strcpy((yyval.c), env.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 599:
#line 6183 "Gmsh.y"
    {
      std::string s = Msg::GetString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 600:
#line 6191 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (4)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 601:
#line 6198 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 602:
#line 6207 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_String(nullptr, (yyvsp[(3) - (5)].c2).char2, 1, 0, (yyvsp[(4) - (5)].c), 2);
    ;}
    break;

  case 603:
#line 6211 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(3) - (7)].c2).char1, (yyvsp[(3) - (7)].c2).char2, (yyvsp[(5) - (7)].c), 0, (yyvsp[(6) - (7)].c), 2);
    ;}
    break;

  case 604:
#line 6215 "Gmsh.y"
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

  case 605:
#line 6230 "Gmsh.y"
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

  case 606:
#line 6244 "Gmsh.y"
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

  case 607:
#line 6258 "Gmsh.y"
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

  case 608:
#line 6270 "Gmsh.y"
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

  case 609:
#line 6286 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = toupper((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 610:
#line 6295 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = tolower((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 611:
#line 6304 "Gmsh.y"
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

  case 612:
#line 6314 "Gmsh.y"
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

  case 613:
#line 6325 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (8)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (8)].d), (int)(yyvsp[(7) - (8)].d));
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (8)].c));
    ;}
    break;

  case 614:
#line 6333 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (6)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (6)].d), std::string::npos);
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 615:
#line 6341 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 616:
#line 6345 "Gmsh.y"
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

  case 617:
#line 6363 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 618:
#line 6370 "Gmsh.y"
    {
      std::string tmp = SplitFileName(GetAbsolutePath(gmsh_yyname))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
    ;}
    break;

  case 619:
#line 6376 "Gmsh.y"
    {
      std::string tmp = GetFileNameWithoutPath(gmsh_yyname);
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
    ;}
    break;

  case 620:
#line 6382 "Gmsh.y"
    {
      std::string tmp = SplitFileName((yyvsp[(3) - (4)].c))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 621:
#line 6389 "Gmsh.y"
    {
      std::string tmp = GetAbsolutePath((yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 622:
#line 6396 "Gmsh.y"
    { init_options(); ;}
    break;

  case 623:
#line 6398 "Gmsh.y"
    {
      std::string val((yyvsp[(3) - (6)].c));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.c) = (char*)Malloc((val.size() + 1) * sizeof(char));
      strcpy((yyval.c), val.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 624:
#line 6406 "Gmsh.y"
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

  case 625:
#line 6430 "Gmsh.y"
    { struct_namespace = std::string(""); (yyval.d) = (yyvsp[(2) - (2)].d); ;}
    break;

  case 626:
#line 6432 "Gmsh.y"
    { struct_namespace = (yyvsp[(1) - (4)].c); Free((yyvsp[(1) - (4)].c)); (yyval.d) = (yyvsp[(4) - (4)].d); ;}
    break;

  case 627:
#line 6438 "Gmsh.y"
    { (yyval.l) = (yyvsp[(3) - (4)].l); ;}
    break;

  case 628:
#line 6443 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 629:
#line 6445 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 630:
#line 6450 "Gmsh.y"
    { (yyval.l) = (yyvsp[(2) - (3)].l); ;}
    break;

  case 631:
#line 6455 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].c)));
    ;}
    break;

  case 632:
#line 6460 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 633:
#line 6462 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].c)));
    ;}
    break;

  case 634:
#line 6466 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	char* c;
	List_Read((yyvsp[(3) - (3)].l), i, &c);
	List_Add((yyval.l), &c);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 635:
#line 6478 "Gmsh.y"
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

  case 636:
#line 6492 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfString(nullptr, (yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c));
    ;}
    break;

  case 637:
#line 6496 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfString((yyvsp[(1) - (7)].c), (yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].c));
    ;}
    break;

  case 638:
#line 6503 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr) + 1) * sizeof(char));
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 639:
#line 6511 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr) + 1) * sizeof(char)) ;
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)) ; strcat((yyval.c), tmpstr) ;
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 640:
#line 6519 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(7) - (8)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(3) - (8)].c))+strlen(tmpstr) + 1) * sizeof(char));
      strcpy((yyval.c), (yyvsp[(3) - (8)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(3) - (8)].c));
    ;}
    break;

  case 641:
#line 6530 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 642:
#line 6532 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 643:
#line 6535 "Gmsh.y"
    { (yyval.c) = (yyvsp[(3) - (4)].c); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 14701 "Gmsh.tab.cpp"
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


#line 6538 "Gmsh.y"


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

